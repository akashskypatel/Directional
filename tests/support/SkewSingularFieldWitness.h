#pragma once

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <numbers>

#include <Eigen/Geometry>
#include <Eigen/Sparse>

#include <directional/authority/AuthorityIds.h>
#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/PCFaceTangentBundle.h>

namespace directional::test_support {

inline authority::SourceEdgeTopologyKey edge_key(const TriMesh &mesh,
                                                  const int edge) {
  return authority::SourceEdgeTopologyKey::from_indices(
             mesh.EV(edge, 0), mesh.EV(edge, 1),
             static_cast<std::size_t>(mesh.V.rows()))
      .value();
}

inline std::array<Eigen::RowVector3d, 4> independent_face_branches(
    const fields::CrossFieldResult &field, const int face) {
  const Eigen::RowVector3d first =
      field.primaryDirections.row(face).normalized();
  const Eigen::RowVector3d second =
      field.secondaryDirections.row(face).normalized();
  return {first, second, -first, -second};
}

struct IndependentEdgeMeasurement {
  int matching = 0;
  double effort = 0.0;
};

inline double independent_signed_angle(const Eigen::Vector3d &from,
                                       const Eigen::Vector3d &to,
                                       const Eigen::Vector3d &normal) {
  const Eigen::Vector3d a = from.normalized();
  const Eigen::Vector3d b = to.normalized();
  return std::atan2(normal.dot(a.cross(b)),
                    std::clamp(a.dot(b), -1.0, 1.0));
}

inline IndependentEdgeMeasurement independent_edge_measurement(
    const TriMesh &mesh, const fields::CrossFieldResult &field,
    const int sourceFace, const int targetFace,
    const authority::SourceEdgeTopologyKey &edge) {
  const auto sourceBranches = independent_face_branches(field, sourceFace);
  const auto targetBranches = independent_face_branches(field, targetFace);
  const Eigen::Vector3d sourceA =
      (mesh.V.row(mesh.F(sourceFace, 1)) -
       mesh.V.row(mesh.F(sourceFace, 0)))
          .transpose();
  const Eigen::Vector3d sourceB =
      (mesh.V.row(mesh.F(sourceFace, 2)) -
       mesh.V.row(mesh.F(sourceFace, 0)))
          .transpose();
  const Eigen::Vector3d targetA =
      (mesh.V.row(mesh.F(targetFace, 1)) -
       mesh.V.row(mesh.F(targetFace, 0)))
          .transpose();
  const Eigen::Vector3d targetB =
      (mesh.V.row(mesh.F(targetFace, 2)) -
       mesh.V.row(mesh.F(targetFace, 0)))
          .transpose();
  const Eigen::Vector3d sourceNormal = sourceA.cross(sourceB).normalized();
  const Eigen::Vector3d targetNormal = targetA.cross(targetB).normalized();
  Eigen::Vector3d axis =
      (mesh.V.row(static_cast<int>(edge.second().index())) -
       mesh.V.row(static_cast<int>(edge.first().index())))
          .transpose();
  axis.normalize();
  const double connectionAngle = std::atan2(
      axis.dot(sourceNormal.cross(targetNormal)),
      sourceNormal.dot(targetNormal));
  const Eigen::AngleAxisd connection(connectionAngle, axis);

  std::array<Eigen::Vector3d, 4> transported;
  for (int branch = 0; branch < 4; ++branch) {
    transported[static_cast<std::size_t>(branch)] =
        connection * sourceBranches[static_cast<std::size_t>(branch)].transpose();
  }

  int principalBranch = 0;
  double smallestRotation = std::numeric_limits<double>::infinity();
  for (int branch = 0; branch < 4; ++branch) {
    const double rotation = independent_signed_angle(
        transported[0], targetBranches[static_cast<std::size_t>(branch)].transpose(),
        targetNormal);
    if (std::abs(rotation) < std::abs(smallestRotation)) {
      smallestRotation = rotation;
      principalBranch = branch;
    }
  }

  double freeRotation = 0.0;
  for (int branch = 0; branch < 4; ++branch) {
    freeRotation += independent_signed_angle(
        transported[static_cast<std::size_t>(branch)],
        targetBranches[static_cast<std::size_t>(branch)].transpose(),
        targetNormal);
  }
  const double effort = std::atan2(std::sin(freeRotation),
                                   std::cos(freeRotation));

  double selectedRotation = 0.0;
  for (int branch = 0; branch < 4; ++branch) {
    selectedRotation += independent_signed_angle(
        transported[static_cast<std::size_t>(branch)],
        targetBranches[static_cast<std::size_t>(
            (branch + principalBranch) % 4)]
            .transpose(),
        targetNormal);
  }
  const int matching = static_cast<int>(
      principalBranch -
      std::llround((selectedRotation - effort) /
                   (2.0 * std::numbers::pi)));
  return IndependentEdgeMeasurement{matching, effort};
}

inline TriMesh make_skew_four_triangle_fan() {
  Eigen::MatrixXd vertices(5, 3);
  vertices << -1.4, -0.8, 0.0,
               1.3, -0.6, 0.0,
               1.1,  1.5, 0.0,
              -1.2,  1.0, 0.0,
               0.1,  0.15, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4,
           1, 2, 4,
           2, 3, 4,
           3, 0, 4;
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

inline void make_skew_index_one_singularity_field(
    const TriMesh &mesh, fields::CrossFieldResult &field) {
  Eigen::MatrixXd primaryDirections(mesh.F.rows(), 3);
  Eigen::MatrixXd secondaryDirections(mesh.F.rows(), 3);

  // Author only the non-degenerate per-face cross directions. The accepted
  // field producer is the sole authority for matching, effort, and singularity
  // derivation; the fixture independently verifies the resulting center cycle.
  constexpr double baseAngle = 0.862;
  constexpr double faceStep = 0.3;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const double angle = baseAngle + faceStep * static_cast<double>(face);
    const Eigen::RowVector3d primary(std::cos(angle), std::sin(angle), 0.0);
    const Eigen::RowVector3d secondary(-std::sin(angle), std::cos(angle), 0.0);
    primaryDirections.row(face) = primary;
    secondaryDirections.row(face) = secondary;

    ASSERT_TRUE(primary.allFinite());
    ASSERT_TRUE(secondary.allFinite());
    ASSERT_NEAR(1.0, primary.norm(), 1.0e-12);
    ASSERT_NEAR(1.0, secondary.norm(), 1.0e-12);
    ASSERT_NEAR(0.0, primary.dot(secondary), 1.0e-12);
    for (int localEdge = 0; localEdge < 3; ++localEdge) {
      Eigen::RowVector3d edgeDirection =
          mesh.V.row(mesh.F(face, (localEdge + 1) % 3)) -
          mesh.V.row(mesh.F(face, localEdge));
      edgeDirection.normalize();
      const double primaryCross =
          primary.x() * edgeDirection.y() - primary.y() * edgeDirection.x();
      const double secondaryCross = secondary.x() * edgeDirection.y() -
                                    secondary.y() * edgeDirection.x();
      ASSERT_GT(std::abs(primaryCross), 0.10);
      ASSERT_GT(std::abs(secondaryCross), 0.10);
    }
  }

  PCFaceTangentBundle bundle;
  bundle.init(mesh);
  CartesianField rawField;
  rawField.init(bundle, fieldTypeEnum::RAW_FIELD, fields::kCrossFieldDegree);
  ASSERT_NO_THROW(rawField.set_extrinsic_field(
      fields::make_raw_cross_field(mesh, primaryDirections, secondaryDirections)));
  ASSERT_NO_THROW(field = fields::finalize_cross_field_result(rawField, false, true));

  ASSERT_TRUE(field.matchingComputed);
  ASSERT_TRUE(field.singularitiesComputed);
  ASSERT_EQ(mesh.EV.rows(), field.matching.size());
  ASSERT_EQ(mesh.EV.rows(), field.effort.size());
  ASSERT_EQ(static_cast<std::size_t>(mesh.EV.rows()), field.edgeTransitions.size());

  int interiorTransitionCount = 0;
  int interiorMatchingSum = 0;
  const fields::CrossFieldEdgeTransition *closingTransition = nullptr;
  for (const fields::CrossFieldEdgeTransition &transition : field.edgeTransitions) {
    ASSERT_GE(transition.sourceEdge, 0);
    ASSERT_LT(transition.sourceEdge, mesh.EV.rows());
    ASSERT_EQ(mesh.EF(transition.sourceEdge, 0), transition.firstFace);
    ASSERT_EQ(mesh.EF(transition.sourceEdge, 1), transition.secondFace);
    if (transition.secondFace < 0) continue;

    ++interiorTransitionCount;
    interiorMatchingSum += transition.matching;
    const IndependentEdgeMeasurement measured = independent_edge_measurement(
        mesh, field, transition.firstFace, transition.secondFace,
        edge_key(mesh, transition.sourceEdge));
    ASSERT_EQ(measured.matching, transition.matching);
    ASSERT_NEAR(measured.effort, transition.effort, 1.0e-9);

    if (std::min(transition.firstFace, transition.secondFace) == 0 &&
        std::max(transition.firstFace, transition.secondFace) == 3) {
      closingTransition = &transition;
    }
  }
  ASSERT_EQ(4, interiorTransitionCount);
  ASSERT_NE(nullptr, closingTransition);
  ASSERT_NE(0, interiorMatchingSum);
  ASSERT_NE(0, closingTransition->matching);

  const int centerVertex = 4;
  ASSERT_EQ(0, mesh.isBoundaryVertex(centerVertex));
  const int centerCycle = bundle.local2Cycle(centerVertex);
  ASSERT_GE(centerCycle, 0);
  ASSERT_LT(centerCycle, bundle.cycles.rows());
  Eigen::SparseMatrix<double, Eigen::RowMajor> cycles = bundle.cycles;
  double orientedEffort = 0.0;
  for (Eigen::SparseMatrix<double, Eigen::RowMajor>::InnerIterator it(
           cycles, centerCycle);
       it; ++it) {
    if (std::abs(it.value()) < 1.0e-12) continue;
    ASSERT_GE(it.col(), 0);
    ASSERT_LT(it.col(), bundle.innerAdjacencies.size());
    const int sourceEdge = bundle.innerAdjacencies(it.col());
    orientedEffort += it.value() * field.effort(sourceEdge);
  }
  const double exactIndex =
      (orientedEffort +
       static_cast<double>(fields::kCrossFieldDegree) *
           bundle.cycleCurvatures(centerCycle)) /
      (2.0 * std::numbers::pi);
  ASSERT_NEAR(2.0 * std::numbers::pi, orientedEffort, 1.0e-9);
  ASSERT_NEAR(1.0, exactIndex, 1.0e-9);

  ASSERT_EQ(field.singularCycles.size(), field.singularIndices.size());
  Eigen::Index interiorSingularityRow = -1;
  int interiorSingularityCount = 0;
  for (Eigen::Index row = 0; row < field.singularCycles.size(); ++row) {
    const int vertex = field.singularCycles(row);
    ASSERT_GE(vertex, 0);
    ASSERT_LT(vertex, mesh.V.rows());
    if (mesh.isBoundaryVertex(vertex) != 0) continue;
    interiorSingularityRow = row;
    ++interiorSingularityCount;
  }
  ASSERT_EQ(1, interiorSingularityCount);
  ASSERT_GE(interiorSingularityRow, 0);
  ASSERT_EQ(centerVertex, field.singularCycles(interiorSingularityRow));
  ASSERT_NEAR(exactIndex,
              static_cast<double>(field.singularIndices(interiorSingularityRow)),
              1.0e-9);
}

} // namespace directional::test_support
