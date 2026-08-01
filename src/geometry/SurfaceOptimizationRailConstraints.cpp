#include <directional/geometry/SurfaceOptimizationRailConstraints.h>

namespace directional::geometry::surface_optimization_rail_detail {

bool source_face_contains_vertex(const Eigen::MatrixXi &faces,
                                        const int face,
                                        const int vertex) {
  if (face < 0 || face >= faces.rows() || faces.cols() != 3) {
    return false;
  }
  return faces(face, 0) == vertex || faces(face, 1) == vertex ||
         faces(face, 2) == vertex;
}

} // namespace directional::geometry::surface_optimization_rail_detail

namespace directional::geometry::surface_optimization_rail_detail {

bool provenance_supports_interval_sheet(
    const SurfacePoint &provenance,
    const SurfaceFeatureCurveInterval &interval,
    const SurfaceOptimizationConstraints &constraints) {
  if (provenance.component >= 0 && interval.component >= 0 &&
      provenance.component != interval.component) {
    return false;
  }
  if (provenance.sheet < 0 || interval.sheet < 0 ||
      provenance.sheet == interval.sheet) {
    return true;
  }
  if (!provenance.valid() || provenance.face < 0 ||
      provenance.face >= constraints.sourceFaces.rows() ||
      interval.sourceFace < 0 ||
      interval.sourceFace >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      !provenance.barycentric.allFinite()) {
    return false;
  }

  // A point on a source edge or vertex legitimately belongs to every
  // incident local sheet. Its stored provenance face is only one valid chart.
  // Accept a rail interval from another sheet only when both charts share the
  // exact source entity supporting the point; interior points remain confined
  // to their authoritative sheet.
  std::vector<int> supportVertices;
  for (int corner = 0; corner < 3; ++corner) {
    if (provenance.barycentric(corner) > 1.0e-8) {
      supportVertices.push_back(
          constraints.sourceFaces(provenance.face, corner));
    }
  }
  if (supportVertices.empty() || supportVertices.size() >= 3U) {
    return false;
  }
  for (const int sourceVertex : supportVertices) {
    if (sourceVertex < 0 ||
        !source_face_contains_vertex(constraints.sourceFaces,
                                     interval.sourceFace, sourceVertex)) {
      return false;
    }
  }

  if (interval.component >= 0 &&
      constraints.sourceFaceComponent.size() ==
          static_cast<std::size_t>(constraints.sourceFaces.rows()) &&
      constraints.sourceFaceComponent[static_cast<std::size_t>(
          interval.sourceFace)] != interval.component) {
    return false;
  }
  if (interval.sheet >= 0 &&
      constraints.sourceFaceSheet.size() ==
          static_cast<std::size_t>(constraints.sourceFaces.rows()) &&
      constraints.sourceFaceSheet[static_cast<std::size_t>(
          interval.sourceFace)] != interval.sheet) {
    return false;
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
  constraints.featureIntervals.clear();
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
    const int curveId = rail.curveId >= 0 ? rail.curveId : rail.id;
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
      interval.component = rail.component;
      interval.sheet =
          start.sourceFace >= 0 &&
                  start.sourceFace <
                      static_cast<int>(constraints.sourceFaceSheet.size())
              ? constraints.sourceFaceSheet[static_cast<std::size_t>(
                    start.sourceFace)]
              : -1;
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
  constraints.featureRailIds =
      Eigen::VectorXi::Constant(outputVertices.rows(), -1);
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
    int sequenceId = -1;
    int order = -1;
    double parameter = 0.0;
    double localParameter = 0.0;
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
          {vertex, interval.curveId,
           interval.railId >= 0 ? interval.railId : interval.curveId,
           interval.order,
           interval.parameterStart +
               incident.localParameter *
                   (interval.parameterEnd - interval.parameterStart),
           incident.localParameter});
    }
    constraints.featureVertices.push_back(vertex);
    constraints.featureCurveIds(vertex) = best->curveId;
    constraints.featureRailIds(vertex) = best->railId;
    constraints.featureIntervalIds(vertex) = best->intervalId;
    constraints.featureParameters(vertex) =
        best->parameterStart +
        bestLocalParameter * (best->parameterEnd - best->parameterStart);
    assignments.push_back(
        {vertex, best->curveId,
         best->railId >= 0 ? best->railId : best->curveId, best->order,
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
                     if (a.sequenceId != b.sequenceId) {
                       return a.sequenceId < b.sequenceId;
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
                     if (a.sequenceId != b.sequenceId) {
                       return a.sequenceId < b.sequenceId;
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
      if (assignment.sequenceId != rail.id) {
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
