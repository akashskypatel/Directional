#include <directional/fields/RegularizedCurvatureCrossField.h>

namespace directional::fields::regularized_cross_field_detail {

std::size_t constraint_type_index(
    const RegularizedCrossFieldConstraintType type) {
  return static_cast<std::size_t>(static_cast<int>(type));
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

double constraint_group_weight(
    const RegularizedCurvatureCrossFieldOptions &options,
    const RegularizedCrossFieldConstraintType type) {
  switch (type) {
  case RegularizedCrossFieldConstraintType::Curvature:
    return options.curvatureAlignmentWeight;
  case RegularizedCrossFieldConstraintType::Boundary:
    return options.boundaryAlignmentWeight;
  case RegularizedCrossFieldConstraintType::SharpFeature:
    return options.sharpFeatureAlignmentWeight;
  }
  return 0.0;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

double &constraint_group_energy(
    AlignmentEnergyBreakdown &energy,
    const RegularizedCrossFieldConstraintType type) {
  switch (type) {
  case RegularizedCrossFieldConstraintType::Curvature:
    return energy.curvature;
  case RegularizedCrossFieldConstraintType::Boundary:
    return energy.boundary;
  case RegularizedCrossFieldConstraintType::SharpFeature:
    return energy.sharpFeature;
  }
  return energy.curvature;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

Eigen::Vector3d transport_proxy_direction_to_original(
    const Eigen::Vector3d &direction,
    const Eigen::Vector3d &proxyNormal,
    const Eigen::Vector3d &originalNormal) {
  Eigen::Vector3d transported =
      transport_rotation_between_normals(proxyNormal, originalNormal) *
      direction;
  transported -= transported.dot(originalNormal) * originalNormal;
  const double norm = transported.norm();
  if (!(norm > 1e-12) || !transported.array().isFinite().all()) {
    return Eigen::Vector3d::Zero();
  }
  return transported / norm;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

Eigen::Vector3d projected_edge_direction(const TriMesh &mesh,
                                                const int edge,
                                                const int face) {
  Eigen::Vector3d direction =
      (mesh.V.row(mesh.EV(edge, 1)) - mesh.V.row(mesh.EV(edge, 0)))
          .transpose();
  const Eigen::Vector3d normal = mesh.faceNormals.row(face).transpose();
  direction -= direction.dot(normal) * normal;
  const double norm = direction.norm();
  if (!(norm > 1e-12) || !direction.array().isFinite().all()) {
    return Eigen::Vector3d::Zero();
  }
  return direction / norm;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

bool is_sharp_edge(const TriMesh &mesh, const int edge,
                          const double thresholdDegrees) {
  const int firstFace = mesh.EF(edge, 0);
  const int secondFace = mesh.EF(edge, 1);
  if (firstFace < 0 || secondFace < 0) {
    return false;
  }
  const double thresholdCosine =
      std::cos(thresholdDegrees * std::numbers::pi / 180.0);
  return mesh.faceNormals.row(firstFace).dot(
             mesh.faceNormals.row(secondFace)) < thresholdCosine;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

Complex degree_four_target(const TriMesh &mesh, const int face,
                                  const Eigen::Vector3d &direction) {
  Complex intrinsic(direction.dot(mesh.FBx.row(face).transpose()),
                    direction.dot(mesh.FBy.row(face).transpose()));
  const double magnitude = std::abs(intrinsic);
  if (!(magnitude > 1e-14) || !std::isfinite(magnitude)) {
    throw std::runtime_error(
        "An alignment constraint could not be projected into its face basis.");
  }
  intrinsic /= magnitude;
  return std::pow(intrinsic, kCrossFieldDegree);
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

Eigen::VectorXcd solve_aligned_power_field(
    const TriMesh &mesh, const PCFaceTangentBundle &tangentBundle,
    const std::vector<AlignmentConstraint> &constraints,
    const RegularizedCurvatureCrossFieldOptions &options,
    double &smoothnessEnergy, AlignmentEnergyBreakdown &alignmentEnergy) {
  const int faceCount = tangentBundle.numSpaces;
  if (constraints.empty()) {
    throw std::invalid_argument(
        "solve_aligned_power_field requires at least one constraint.");
  }

  double totalSmoothMass = 0.0;
  for (int diagonal = 0; diagonal < tangentBundle.connectionMass.rows();
       ++diagonal) {
    totalSmoothMass += tangentBundle.connectionMass.coeff(diagonal, diagonal);
  }
  totalSmoothMass = std::max(totalSmoothMass, 1e-30);

  std::array<double, 3> totalConstraintMass = {0.0, 0.0, 0.0};
  for (const AlignmentConstraint &constraint : constraints) {
    if (constraint_group_weight(options, constraint.type) <= 0.0) {
      continue;
    }
    totalConstraintMass[constraint_type_index(constraint.type)] +=
        constraint.mass;
  }
  for (double &mass : totalConstraintMass) {
    mass = std::max(mass, 1e-30);
  }

  std::vector<ComplexTriplet> triplets;
  triplets.reserve(static_cast<std::size_t>(
      4 * tangentBundle.innerAdjacencies.size() + constraints.size()));
  Eigen::VectorXcd rhs = Eigen::VectorXcd::Zero(faceCount);

  int innerEdge = 0;
  for (int edge = 0; edge < tangentBundle.adjSpaces.rows(); ++edge) {
    const int firstFace = tangentBundle.adjSpaces(edge, 0);
    const int secondFace = tangentBundle.adjSpaces(edge, 1);
    if (firstFace < 0 || secondFace < 0) {
      continue;
    }

    const double edgeMass =
        tangentBundle.connectionMass.coeff(innerEdge, innerEdge);
    const double weight =
        options.fieldSmoothnessWeight * edgeMass / totalSmoothMass;
    const Complex transport =
        std::pow(tangentBundle.connection(edge), kCrossFieldDegree);

    triplets.emplace_back(firstFace, firstFace,
                          weight * std::norm(transport));
    triplets.emplace_back(secondFace, secondFace, weight);
    triplets.emplace_back(firstFace, secondFace,
                          -weight * std::conj(transport));
    triplets.emplace_back(secondFace, firstFace, -weight * transport);
    ++innerEdge;
  }

  for (const AlignmentConstraint &constraint : constraints) {
    const double groupWeight = constraint_group_weight(options, constraint.type);
    if (groupWeight <= 0.0) {
      continue;
    }
    const double normalizedMass =
        constraint.mass /
        totalConstraintMass[constraint_type_index(constraint.type)];
    const double weight =
        groupWeight * constraint.confidence * normalizedMass;
    const Complex target =
        degree_four_target(mesh, constraint.face, constraint.direction);
    triplets.emplace_back(constraint.face, constraint.face, weight);
    rhs(constraint.face) += weight * target;
  }

  ComplexSparseMatrix system(faceCount, faceCount);
  system.setFromTriplets(triplets.begin(), triplets.end());
  system.makeCompressed();

  Eigen::SimplicialLDLT<ComplexSparseMatrix> solver;
  solver.compute(system);
  if (solver.info() != Eigen::Success) {
    throw std::runtime_error(
        "Curvature-aligned power-field factorization failed.");
  }

  Eigen::VectorXcd power = solver.solve(rhs);
  if (solver.info() != Eigen::Success ||
      !power.array().isFinite().all()) {
    throw std::runtime_error("Curvature-aligned power-field solve failed.");
  }

  smoothnessEnergy = 0.0;
  innerEdge = 0;
  for (int edge = 0; edge < tangentBundle.adjSpaces.rows(); ++edge) {
    const int firstFace = tangentBundle.adjSpaces(edge, 0);
    const int secondFace = tangentBundle.adjSpaces(edge, 1);
    if (firstFace < 0 || secondFace < 0) {
      continue;
    }
    const double edgeMass =
        tangentBundle.connectionMass.coeff(innerEdge, innerEdge);
    const Complex transport =
        std::pow(tangentBundle.connection(edge), kCrossFieldDegree);
    smoothnessEnergy +=
        edgeMass * std::norm(power(secondFace) - transport * power(firstFace));
    ++innerEdge;
  }
  smoothnessEnergy *= options.fieldSmoothnessWeight / totalSmoothMass;

  alignmentEnergy = {};
  for (const AlignmentConstraint &constraint : constraints) {
    const double groupWeight = constraint_group_weight(options, constraint.type);
    if (groupWeight <= 0.0) {
      continue;
    }
    const Complex target =
        degree_four_target(mesh, constraint.face, constraint.direction);
    constraint_group_energy(alignmentEnergy, constraint.type) +=
        constraint.confidence * constraint.mass *
        std::norm(power(constraint.face) - target);
  }
  for (const auto type : {RegularizedCrossFieldConstraintType::Curvature,
                          RegularizedCrossFieldConstraintType::Boundary,
                          RegularizedCrossFieldConstraintType::SharpFeature}) {
    double &energy = constraint_group_energy(alignmentEnergy, type);
    energy *= constraint_group_weight(options, type) /
              totalConstraintMass[constraint_type_index(type)];
  }

  if (options.normalizeDirections) {
    for (int face = 0; face < power.size(); ++face) {
      const double magnitude = std::abs(power(face));
      if (!(magnitude > 1e-14) || !std::isfinite(magnitude)) {
        throw std::runtime_error(
            "Curvature-aligned power solve produced a degenerate face value.");
      }
      power(face) /= magnitude;
    }
  }
  return power;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields::regularized_cross_field_detail {

CartesianField make_raw_field(const PCFaceTangentBundle &tangentBundle,
                                     const Eigen::VectorXcd &power,
                                     const bool normalizeDirections) {
  Eigen::MatrixXcd roots(tangentBundle.numSpaces, kCrossFieldDegree);
  for (int face = 0; face < tangentBundle.numSpaces; ++face) {
    Complex root =
        std::pow(power(face), 1.0 / static_cast<double>(kCrossFieldDegree));
    if (normalizeDirections) {
      const double magnitude = std::abs(root);
      if (!(magnitude > 1e-14)) {
        throw std::runtime_error(
            "Curvature-aligned field produced a degenerate root.");
      }
      root /= magnitude;
    }
    for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
      const double angle = 2.0 * std::numbers::pi * direction /
                           static_cast<double>(kCrossFieldDegree);
      roots(face, direction) = root * std::exp(Complex(0.0, angle));
    }
  }

  Eigen::MatrixXd intrinsic(tangentBundle.numSpaces,
                            2 * kCrossFieldDegree);
  for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
    intrinsic.col(2 * direction) = roots.col(direction).real();
    intrinsic.col(2 * direction + 1) = roots.col(direction).imag();
  }

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, kCrossFieldDegree);
  rawField.set_intrinsic_field(intrinsic);
  return rawField;
}

} // namespace directional::fields::regularized_cross_field_detail

namespace directional::fields {

RegularizedCurvatureCrossFieldResult
extract_regularized_curvature_cross_field(
    const TriMesh &mesh,
    const RegularizedCurvatureCrossFieldOptions &options) {
  using namespace regularized_cross_field_detail;

  if (mesh.V.rows() == 0 || mesh.F.rows() == 0 || mesh.F.cols() != 3) {
    throw std::invalid_argument(
        "Regularized curvature cross-field extraction requires a non-empty "
        "triangular mesh.");
  }
  if (!(options.fieldSmoothnessWeight > 0.0) ||
      options.curvatureAlignmentWeight < 0.0 ||
      options.boundaryAlignmentWeight < 0.0 ||
      options.sharpFeatureAlignmentWeight < 0.0 ||
      options.confidenceExponent <= 0.0 ||
      options.minimumConfidence < 0.0 || options.minimumConfidence > 1.0) {
    throw std::invalid_argument(
        "Invalid regularized curvature cross-field weights or thresholds.");
  }

  constexpr std::size_t stageCount = 7;
  report_progress(options.progress, 1, stageCount,
                  "Optimizing feature-preserving proxy mesh");
  const RegularizedProxyMeshResult proxyResult = regularize_proxy_mesh(
      mesh.V, mesh.F, mesh.EV, mesh.isBoundaryVertex, options.proxy);

  report_progress(options.progress, 2, stageCount,
                  "Initializing proxy geometry");
  TriMesh proxyMesh;
  proxyMesh.set_mesh(proxyResult.vertices, mesh.F);

  report_progress(options.progress, 3, stageCount,
                  "Estimating feature-aware proxy curvature");
  FaceCurvatureResult curvature = estimate_face_curvature(
      proxyMesh.V, proxyMesh.F, proxyMesh.FBx, proxyMesh.FBy,
      proxyMesh.faceNormals, proxyMesh.faceAreas, proxyMesh.TT,
      proxyMesh.vertexNormals, options.curvature);

  std::vector<AlignmentConstraint> constraints;
  constraints.reserve(static_cast<std::size_t>(mesh.F.rows() +
                                                2 * mesh.EV.rows()));
  geometry::AdaptiveFeatureMapOptions featureMapOptions = options.featureMap;
  featureMapOptions.cadAbsoluteHighDegrees =
      std::min(featureMapOptions.cadAbsoluteHighDegrees,
               options.curvature.sharpFeatureAngleDegrees);
  featureMapOptions.organicAbsoluteHighDegrees =
      std::min(featureMapOptions.organicAbsoluteHighDegrees,
               options.curvature.sharpFeatureAngleDegrees);
  const geometry::AdaptiveFeatureMap featureMap =
      geometry::AdaptiveFeatureMapBuilder::build(mesh.V, mesh.F,
                                                 featureMapOptions);

  if (options.curvatureAlignmentWeight > 0.0) {
    for (int face = 0; face < mesh.F.rows(); ++face) {
      if (curvature.valid(face) == 0 ||
          curvature.confidence(face) < options.minimumConfidence) {
        continue;
      }

      const Eigen::Vector3d target = transport_proxy_direction_to_original(
          curvature.principalDirectionsMax.row(face).transpose(),
          proxyMesh.faceNormals.row(face).transpose(),
          mesh.faceNormals.row(face).transpose());
      if (target.squaredNorm() <= 1e-20) {
        continue;
      }

      const double confidence =
          std::pow(curvature.confidence(face), options.confidenceExponent);
      if (!(confidence > 0.0) || !std::isfinite(confidence)) {
        continue;
      }

      constraints.push_back({face, target, confidence,
                             std::max(mesh.faceAreas(face), 1e-30),
                             RegularizedCrossFieldConstraintType::Curvature});
    }
  }

  if (options.boundaryAlignmentWeight > 0.0) {
    for (int index = 0; index < mesh.boundEdges.size(); ++index) {
      const int edge = mesh.boundEdges(index);
      const int face = mesh.EF(edge, 0);
      if (face < 0) {
        continue;
      }
      const Eigen::Vector3d direction =
          projected_edge_direction(mesh, edge, face);
      if (direction.squaredNorm() <= 1e-20) {
        continue;
      }
      const double length =
          (mesh.V.row(mesh.EV(edge, 1)) - mesh.V.row(mesh.EV(edge, 0)))
              .norm();
      constraints.push_back({face, direction, 1.0, std::max(length, 1e-30),
                             RegularizedCrossFieldConstraintType::Boundary});
    }
  }

  if (options.sharpFeatureAlignmentWeight > 0.0) {
    for (int index = 0; index < mesh.innerEdges.size(); ++index) {
      const int edge = mesh.innerEdges(index);
      const std::pair<int, int> key =
          geometry::AdaptiveFeatureMap::canonical_edge(mesh.EV(edge, 0),
                                                       mesh.EV(edge, 1));
      const geometry::AdaptiveFeatureClass edgeClass =
          featureMap.edge_class(key);
      if (edgeClass != geometry::AdaptiveFeatureClass::Hard &&
          edgeClass != geometry::AdaptiveFeatureClass::Soft) {
        continue;
      }
      const double strength = std::max(featureMap.strength(key), 1.0e-12);
      const double length =
          (mesh.V.row(mesh.EV(edge, 1)) - mesh.V.row(mesh.EV(edge, 0)))
              .norm();
      for (int side = 0; side < 2; ++side) {
        const int face = mesh.EF(edge, side);
        const Eigen::Vector3d direction =
            projected_edge_direction(mesh, edge, face);
        if (direction.squaredNorm() <= 1e-20) {
          continue;
        }
        constraints.push_back(
            {face, direction, strength, std::max(length, 1e-30),
             RegularizedCrossFieldConstraintType::SharpFeature});
      }
    }
  }

  Eigen::VectorXi constrainedFaces(constraints.size());
  Eigen::MatrixXd constraintDirections(constraints.size(), 3);
  Eigen::VectorXd alignmentWeights(constraints.size());
  Eigen::VectorXi constraintTypes(constraints.size());
  for (std::size_t index = 0; index < constraints.size(); ++index) {
    const AlignmentConstraint &constraint = constraints[index];
    constrainedFaces(static_cast<int>(index)) = constraint.face;
    constraintDirections.row(static_cast<int>(index)) = constraint.direction;
    alignmentWeights(static_cast<int>(index)) =
        constraint_group_weight(options, constraint.type) *
        constraint.confidence;
    constraintTypes(static_cast<int>(index)) =
        static_cast<int>(constraint.type);
  }

  report_progress(options.progress, 4, stageCount,
                  "Initializing original tangent bundle");
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(mesh);

  const bool hasActiveConstraint = std::any_of(
      constraints.begin(), constraints.end(),
      [&](const AlignmentConstraint &constraint) {
        return constraint_group_weight(options, constraint.type) > 0.0;
      });

  double smoothnessEnergy = 0.0;
  AlignmentEnergyBreakdown alignmentEnergy;
  if (!hasActiveConstraint) {
    report_progress(options.progress, 5, stageCount,
                    "Solving smooth fallback cross field");
    CrossFieldOptions fallbackOptions;
    fallbackOptions.normalizeDirections = options.normalizeDirections;
    fallbackOptions.combDirections = options.combDirections;
    fallbackOptions.computeMatching = options.computeMatching;
    const CrossFieldResult fallback = extract_cross_field(mesh, fallbackOptions);

    RegularizedCurvatureCrossFieldResult result;
    result.field = fallback;
    result.proxyVertices = proxyResult.vertices;
    result.proxyDisplacement = proxyResult.displacement;
    result.proxyCurvature = std::move(curvature);
    result.constrainedFaces = std::move(constrainedFaces);
    result.constraintDirections = std::move(constraintDirections);
    result.alignmentWeights = std::move(alignmentWeights);
    result.constraintTypes = std::move(constraintTypes);
    report_progress(options.progress, 6, stageCount,
                    "No active alignment constraints found");
    report_progress(options.progress, 7, stageCount,
                    "Finalizing cross field");
    return result;
  }

  report_progress(options.progress, 5, stageCount,
                  "Solving feature-aware aligned power field");
  const Eigen::VectorXcd power = solve_aligned_power_field(
      mesh, tangentBundle, constraints, options, smoothnessEnergy,
      alignmentEnergy);

  report_progress(options.progress, 6, stageCount,
                  "Constructing raw cross directions");
  CartesianField rawField =
      regularized_cross_field_detail::make_raw_field(
          tangentBundle, power, options.normalizeDirections);

  report_progress(
      options.progress, 7, stageCount,
      options.combDirections
          ? "Combing cross-field branches"
          : (options.computeMatching ? "Computing field matching"
                                     : "Finalizing cross field"));

  RegularizedCurvatureCrossFieldResult result;
  result.field = finalize_cross_field_result(
      rawField, options.combDirections, options.computeMatching);
  result.proxyVertices = proxyResult.vertices;
  result.proxyDisplacement = proxyResult.displacement;
  result.proxyCurvature = std::move(curvature);
  result.constrainedFaces = std::move(constrainedFaces);
  result.constraintDirections = std::move(constraintDirections);
  result.alignmentWeights = std::move(alignmentWeights);
  result.constraintTypes = std::move(constraintTypes);
  result.smoothnessEnergy = smoothnessEnergy;
  result.curvatureAlignmentEnergy = alignmentEnergy.curvature;
  result.boundaryAlignmentEnergy = alignmentEnergy.boundary;
  result.sharpFeatureAlignmentEnergy = alignmentEnergy.sharpFeature;
  result.alignmentEnergy = alignmentEnergy.total();
  return result;
}

} // namespace directional::fields

namespace directional::fields {

RegularizedCurvatureCrossFieldResult
extract_regularized_curvature_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const RegularizedCurvatureCrossFieldOptions &options) {
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return extract_regularized_curvature_cross_field(mesh, options);
}

} // namespace directional::fields
