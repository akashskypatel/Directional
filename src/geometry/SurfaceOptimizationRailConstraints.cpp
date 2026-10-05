#include <directional/geometry/SurfaceOptimizationRailConstraints.h>

namespace directional::geometry::surface_optimization_rail_detail {

namespace {

std::optional<surface_optimizer_detail::SourceProjectionScope> source_face_scope(
    const SurfaceOptimizationConstraints &constraints, const int face) {
  if (constraints.sourceAuthority == nullptr || face < 0 ||
      face >= constraints.sourceFaces.rows() ||
      !constraints.sourceAuthority->matches_source_faces(
          constraints.sourceFaces,
          static_cast<std::size_t>(constraints.sourceVertices.rows()))) {
    return std::nullopt;
  }
  const auto row = authority::SourceFaceId::from_index(
      face, constraints.sourceAuthority->face_count());
  if (!row) return std::nullopt;
  const auto component =
      constraints.sourceAuthority->component_for_row(row.value());
  const auto sheet =
      constraints.sourceAuthority->sheet_for_row(row.value());
  return surface_optimizer_detail::SourceProjectionScope{component, sheet};
}

} // namespace

bool source_face_contains_vertex(
    const Eigen::MatrixXi &faces, authority::SourceFaceId face,
    authority::SourceVertexId vertex) {
  if (faces.cols() != 3 ||
      (face).index() >=
          static_cast<std::size_t>(faces.rows())) {
    return false;
  }
  const auto matches = [&](const int corner) {
    return static_cast<std::int64_t>(faces(
               static_cast<Eigen::Index>(
                   (face).index()),
               corner)) ==
           static_cast<std::int64_t>(
               (vertex).index());
  };
  return matches(0) || matches(1) || matches(2);
}

} // namespace directional::geometry::surface_optimization_rail_detail

namespace directional::geometry::surface_optimization_rail_detail {

bool provenance_supports_interval_sheet(
    const SurfacePoint &provenance,
    const SurfaceFeatureCurveInterval &interval,
    const SurfaceOptimizationConstraints &constraints) {
  using authority::SourceFaceId;
  using authority::SourceVertexId;
  if (!provenance.valid() || provenance.face < 0 ||
      provenance.face >= constraints.sourceFaces.rows() ||
      interval.sourceFace < 0 ||
      interval.sourceFace >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      constraints.sourceVertices.rows() <= 0 ||
      !provenance.barycentric.allFinite()) {
    return false;
  }
  const auto provenanceScope = source_face_scope(constraints, provenance.face);
  const auto intervalScope = source_face_scope(constraints, interval.sourceFace);
  if (!provenanceScope.has_value() || !intervalScope.has_value() ||
      provenanceScope->component != intervalScope->component) {
    return false;
  }
  if (provenanceScope->sheet == intervalScope->sheet) {
    return true;
  }

  const std::size_t sourceFaceExtent =
      static_cast<std::size_t>(constraints.sourceFaces.rows());
  const auto provenanceFaceResult = directional::authority::SourceFaceId::from_index(
      provenance.face, sourceFaceExtent);
  const auto intervalFaceResult = directional::authority::SourceFaceId::from_index(
      interval.sourceFace, sourceFaceExtent);
  if (!provenanceFaceResult || !intervalFaceResult) {
    return false;
  }
  const SourceFaceId provenanceFace = provenanceFaceResult.value();
  const SourceFaceId intervalFace = intervalFaceResult.value();

  // A point on a source edge or vertex legitimately belongs to every
  // incident local sheet. Its stored provenance face is only one valid chart.
  // Accept a rail interval from another sheet only when both charts share the
  // exact source entity supporting the point; interior points remain confined
  // to their authoritative sheet.
  std::vector<SourceVertexId> supportVertices;
  for (int corner = 0; corner < 3; ++corner) {
    if (provenance.barycentric(corner) > 1.0e-8) {
      const int sourceVertexIndex = constraints.sourceFaces(
          static_cast<Eigen::Index>(
              (provenanceFace).index()),
          corner);
      if (sourceVertexIndex < 0) {
        return false;
      }
      const auto sourceVertexResult = directional::authority::SourceVertexId::from_index(
          sourceVertexIndex, static_cast<std::size_t>(constraints.sourceVertices.rows()));
      if (!sourceVertexResult) {
        return false;
      }
      supportVertices.push_back(sourceVertexResult.value());
    }
  }
  if (supportVertices.empty() || supportVertices.size() >= 3U) {
    return false;
  }
  for (const SourceVertexId sourceVertex : supportVertices) {
    if (!source_face_contains_vertex(constraints.sourceFaces, intervalFace,
                                     sourceVertex)) {
      return false;
    }
  }

  return true;
}

} // namespace directional::geometry::surface_optimization_rail_detail

namespace directional::geometry {

void fill_surface_optimization_rail_constraints(
    const std::vector<SurfaceCellRail> &rails,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints) {
  constraints.featureCurveIntervals.clear();
  constraints.featureVertices.clear();
  constraints.orderedFeatureVertices.clear();
  constraints.authoritativeBoundaryEdges.clear();
  constraints.authoritativeBoundaryLoop.clear();
  constraints.authoritativeBoundaryLoops.clear();
  constraints.authoritativeFeatureRails.clear();
  constraints.requiredFeatureRailCount = 0;
  constraints.missingFeatureRailIds.clear();
  constraints.featureRailAuthorityProvided = true;
  int nextIntervalId = 0;
  for (const SurfaceCellRail &rail : rails) {
    const int curveId = rail.curveId;
    for (int sampleIndex = 0;
         sampleIndex + 1 < static_cast<int>(rail.samples.size());
         sampleIndex += 2) {
      const SurfaceCellRailSample &start =
          rail.samples[static_cast<std::size_t>(sampleIndex)];
      const SurfaceCellRailSample &end =
          rail.samples[static_cast<std::size_t>(sampleIndex + 1)];
      SurfaceFeatureCurveInterval interval;
      interval.curveId = curveId;
      interval.intervalId = nextIntervalId++;
      interval.railId = rail.id;
      interval.order = sampleIndex / 2;
      interval.sourceFace = start.sourceFace;
      interval.parameterStart = start.railParameter;
      interval.parameterEnd = end.railParameter;
      interval.curveClosed = rail.closed;
      interval.start = start.position;
      interval.end = end.position;
      constraints.featureCurveIntervals.push_back(interval);
    }
    if (rail.kind == SurfaceCellRailKind::HardFeature) {
      ++constraints.requiredFeatureRailCount;
    }
  }

  constraints.featureCurveIds =
      Eigen::VectorXi::Constant(outputVertices.rows(), -1);
  constraints.featureRailIds.assign(
      static_cast<std::size_t>(outputVertices.rows()), std::nullopt);
  constraints.featureIntervalIds =
      Eigen::VectorXi::Constant(outputVertices.rows(), -1);
  constraints.featureParameters = Eigen::VectorXd::Zero(outputVertices.rows());
  if (outputVertices.rows() == 0 || constraints.featureCurveIntervals.empty()) {
    return;
  }

  const Eigen::RowVector3d minimum = outputVertices.colwise().minCoeff();
  const Eigen::RowVector3d maximum = outputVertices.colwise().maxCoeff();
  const double tolerance = 1.0e-9 * std::max(1.0, (maximum - minimum).norm());
  const double toleranceSquared = tolerance * tolerance;
  struct FeatureAssignment {
    int vertex = -1;
    int curveId = -1;
    SurfaceFeatureSequenceKey sequence;
    int order = -1;
    double parameter = 0.0;
    double localParameter = 0.0;
  };
  const auto sequence_key = [](const SurfaceFeatureCurveInterval &interval) {
    return SurfaceFeatureSequenceKey{
        interval.railId, interval.railId.has_value() ? -1 : interval.curveId};
  };
  std::vector<FeatureAssignment> assignments;
  // Authority membership is many-to-many at feature junctions. The optimizer
  // still chooses one primary curve coordinate per vertex, but validation
  // must retain the same endpoint in every incident hard rail.
  std::vector<FeatureAssignment> authorityAssignments;
  for (int vertex = 0; vertex < outputVertices.rows(); ++vertex) {
    const SurfacePoint provenance =
        vertex < static_cast<int>(outputProvenance.size())
            ? outputProvenance[static_cast<std::size_t>(vertex)]
            : SurfacePoint{};
    double bestDistance = std::numeric_limits<double>::infinity();
    const SurfaceFeatureCurveInterval *best = nullptr;
    double bestLocalParameter = 0.0;
    bool bestMatchesSourceFace = false;
    struct IncidentInterval {
      const SurfaceFeatureCurveInterval *interval = nullptr;
      double localParameter = 0.0;
    };
    std::vector<IncidentInterval> incidentIntervals;
    for (const SurfaceFeatureCurveInterval &interval :
         constraints.featureCurveIntervals) {
      if (!surface_optimization_rail_detail::
              provenance_supports_interval_sheet(provenance, interval,
                                                  constraints)) {
        continue;
      }
      double localParameter = 0.0;
      const Eigen::RowVector3d projected =
          surface_optimizer_detail::project_to_interval(
              outputVertices.row(vertex), interval.start, interval.end,
              &localParameter);
      const double distance =
          (outputVertices.row(vertex) - projected).squaredNorm();
      if (distance <= toleranceSquared) {
        incidentIntervals.push_back({&interval, localParameter});
      }
      const bool matchesSourceFace =
          provenance.face >= 0 && interval.sourceFace == provenance.face;
      if (distance + 1.0e-24 < bestDistance ||
          (std::abs(distance - bestDistance) <= 1.0e-24 &&
           matchesSourceFace && !bestMatchesSourceFace)) {
        bestDistance = distance;
        best = &interval;
        bestLocalParameter = localParameter;
        bestMatchesSourceFace = matchesSourceFace;
      }
    }
    if (best == nullptr || bestDistance > toleranceSquared) {
      continue;
    }
    for (const IncidentInterval &incident : incidentIntervals) {
      const SurfaceFeatureCurveInterval &interval = *incident.interval;
      authorityAssignments.push_back(
          {vertex, interval.curveId, sequence_key(interval), interval.order,
           interval.parameterStart +
               incident.localParameter *
                   (interval.parameterEnd - interval.parameterStart),
           incident.localParameter});
    }
    constraints.featureVertices.push_back(vertex);
    constraints.featureCurveIds(vertex) = best->curveId;
    constraints.featureRailIds[static_cast<std::size_t>(vertex)] = best->railId;
    constraints.featureIntervalIds(vertex) = best->intervalId;
    constraints.featureParameters(vertex) =
        best->parameterStart +
        bestLocalParameter * (best->parameterEnd - best->parameterStart);
    assignments.push_back(
        {vertex, best->curveId, sequence_key(*best), best->order,
         constraints.featureParameters(vertex), bestLocalParameter});
    bool fixed = false;
    for (std::size_t first = 0; first < incidentIntervals.size() && !fixed;
         ++first) {
      for (std::size_t second = first + 1;
           second < incidentIntervals.size(); ++second) {
        const SurfaceFeatureCurveInterval &a =
            *incidentIntervals[first].interval;
        const SurfaceFeatureCurveInterval &b =
            *incidentIntervals[second].interval;
        if (a.curveId != b.curveId || a.railId != b.railId) {
          fixed = true;
          break;
        }
        const Eigen::RowVector3d ta =
            surface_optimizer_detail::normalized_or_zero(a.end - a.start);
        const Eigen::RowVector3d tb =
            surface_optimizer_detail::normalized_or_zero(b.end - b.start);
        if (ta.squaredNorm() == 0.0 || tb.squaredNorm() == 0.0 ||
            std::abs(ta.dot(tb)) < 0.999) {
          fixed = true;
          break;
        }
      }
    }
    if (!fixed && incidentIntervals.size() == 1U) {
      const IncidentInterval &incident = incidentIntervals.front();
      fixed = !incident.interval->curveClosed &&
              (incident.localParameter <= 1.0e-12 ||
               incident.localParameter >= 1.0 - 1.0e-12);
    }
    if (fixed &&
        std::find(constraints.fixedVertices.begin(),
                  constraints.fixedVertices.end(), vertex) ==
            constraints.fixedVertices.end()) {
      constraints.fixedVertices.push_back(vertex);
    }
  }
  std::stable_sort(assignments.begin(), assignments.end(),
                   [](const FeatureAssignment &a, const FeatureAssignment &b) {
                     if (a.sequence != b.sequence) {
                       return a.sequence < b.sequence;
                     }
                     if (a.curveId != b.curveId) {
                       return a.curveId < b.curveId;
                     }
                     if (a.order != b.order) {
                       return a.order < b.order;
                     }
                     if (a.localParameter != b.localParameter) {
                       return a.localParameter < b.localParameter;
                     }
                     if (a.parameter != b.parameter) {
                       return a.parameter < b.parameter;
                     }
                     return a.vertex < b.vertex;
                   });
  std::stable_sort(authorityAssignments.begin(),
                   authorityAssignments.end(),
                   [](const FeatureAssignment &a,
                      const FeatureAssignment &b) {
                     if (a.sequence != b.sequence) {
                       return a.sequence < b.sequence;
                     }
                     if (a.order != b.order) {
                       return a.order < b.order;
                     }
                     if (a.localParameter != b.localParameter) {
                       return a.localParameter < b.localParameter;
                     }
                     if (a.parameter != b.parameter) {
                       return a.parameter < b.parameter;
                     }
                     return a.vertex < b.vertex;
                   });
  for (const FeatureAssignment &assignment : assignments) {
    constraints.orderedFeatureVertices.push_back(assignment.vertex);
  }

  for (const SurfaceCellRail &rail : rails) {
    std::vector<int> sequence;
    for (const FeatureAssignment &assignment : authorityAssignments) {
      if (assignment.sequence !=
          SurfaceFeatureSequenceKey{rail.id, -1}) {
        continue;
      }
      if (sequence.empty() || sequence.back() != assignment.vertex) {
        sequence.push_back(assignment.vertex);
      }
    }

    if (rail.kind == SurfaceCellRailKind::Boundary) {
      if (rail.closed && sequence.size() >= 2U &&
          sequence.front() == sequence.back()) {
        sequence.pop_back();
      }
      if (rail.closed && sequence.size() >= 3U) {
        constraints.authoritativeBoundaryLoops.push_back(sequence);
        if (constraints.authoritativeBoundaryLoop.empty()) {
          constraints.authoritativeBoundaryLoop = sequence;
        }
        for (std::size_t index = 0; index < sequence.size(); ++index) {
          constraints.authoritativeBoundaryEdges.insert(
              {std::min(sequence[index],
                        sequence[(index + 1U) % sequence.size()]),
               std::max(sequence[index],
                        sequence[(index + 1U) % sequence.size()])});
        }
      } else {
        for (std::size_t index = 0; index + 1U < sequence.size(); ++index) {
          constraints.authoritativeBoundaryEdges.insert(
              {std::min(sequence[index], sequence[index + 1U]),
               std::max(sequence[index], sequence[index + 1U])});
        }
      }
    } else if (rail.kind == SurfaceCellRailKind::HardFeature &&
               sequence.size() >= 2U) {
      if (rail.closed && sequence.front() != sequence.back()) {
        sequence.push_back(sequence.front());
      }
      constraints.authoritativeFeatureRails.push_back(std::move(sequence));
    } else if (rail.kind == SurfaceCellRailKind::HardFeature) {
      constraints.missingFeatureRailIds.push_back(rail.id);
    }
  }
}

} // namespace directional::geometry
