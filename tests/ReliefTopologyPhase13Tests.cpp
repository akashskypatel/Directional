#include <directional/geometry/ReliefTopology.h>
#include <directional/meshing/TriFlowSimplification.h>
#include <directional/meshing/TriFlowSimplificationDCEL.h>

#include <algorithm>
#include <cmath>
#include <set>
#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshFixture make_grid(const int n) {
  MeshFixture mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices.row(vertex) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  mesh.faces.resize(2 * n * n, 3);
  int face = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int v00 = y * (n + 1) + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * (n + 1) + x;
      const int v11 = v01 + 1;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

MeshFixture make_saddle_fan() {
  MeshFixture mesh;
  mesh.vertices.resize(5, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0,
      0.0, 0.0, 0.0, -1.0, 0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 1;
  return mesh;
}

MeshFixture make_dumbbell_strip() {
  MeshFixture mesh;
  mesh.vertices.resize(18, 3);
  int vertex = 0;
  for (int y = 0; y <= 2; ++y) {
    for (int x = 0; x <= 5; ++x) {
      mesh.vertices.row(vertex++) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  std::vector<Eigen::Vector3i> faces;
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 5; ++x) {
      const bool inLeftLobe = x <= 1;
      const bool inRightLobe = x >= 3;
      const bool inBridge = x == 2 && y == 0;
      if (!inLeftLobe && !inRightLobe && !inBridge) {
        continue;
      }
      const int v00 = y * 6 + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * 6 + x;
      const int v11 = v01 + 1;
      faces.push_back({v00, v10, v11});
      faces.push_back({v00, v11, v01});
    }
  }
  mesh.faces.resize(static_cast<int>(faces.size()), 3);
  for (int face = 0; face < static_cast<int>(faces.size()); ++face) {
    mesh.faces.row(face) = faces[static_cast<std::size_t>(face)];
  }
  return mesh;
}

int count_type(const std::vector<directional::geometry::ReliefCriticalPoint> &points,
               const directional::geometry::ReliefCriticalType type) {
  return static_cast<int>(std::count_if(
      points.begin(), points.end(),
      [&](const directional::geometry::ReliefCriticalPoint &point) {
        return point.type == type;
      }));
}

std::uint64_t edge_key(const int a, const int b) {
  return directional::geometry::relief_topology_detail::edge_key(a, b);
}

std::uint64_t structural_hash(const directional::TriFlowSimplificationResult &result) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  mix(result.vertices.rows());
  mix(result.faces.rows());
  for (int row = 0; row < result.faces.rows(); ++row) {
    for (int col = 0; col < result.faces.cols(); ++col) {
      mix(result.faces(row, col));
    }
  }
  for (int vertex = 0; vertex < result.rootLabels.size(); ++vertex) {
    mix(result.rootLabels[vertex]);
  }
  return hash;
}

} // namespace

TEST(ReliefTopologyPhase13, ReliefFormulaUsesDistinctNormalizedSignals) {
  directional::geometry::ReliefInput input;
  input.salience = Eigen::VectorXd::Zero(3);
  input.curvature = Eigen::VectorXd::Zero(3);
  input.density = Eigen::VectorXd::Zero(3);
  input.thickness.resize(3);
  input.thickness << 10.0, 1.0, 0.1;
  input.patchEnergy = Eigen::VectorXd::Zero(3);

  directional::geometry::ReliefOptions options;
  options.baseSize = 1.0;
  const Eigen::VectorXd relief =
      directional::geometry::compute_salience_relief(input, options);

  ASSERT_EQ(relief.size(), 3);
  EXPECT_LT(relief[0], relief[1]);
  EXPECT_LT(relief[1], relief[2]);
}

TEST(ReliefTopologyPhase13, AnalyticPlCriticalClassificationFindsSaddle) {
  const MeshFixture mesh = make_saddle_fan();
  Eigen::VectorXd relief(5);
  relief << 0.5, 0.0, 1.0, 0.0, 1.0;

  const auto points =
      directional::geometry::classify_pl_critical_points(mesh.faces, relief);

  ASSERT_EQ(points.size(), 5U);
  EXPECT_EQ(points[0].type, directional::geometry::ReliefCriticalType::Saddle);
  EXPECT_EQ(points[0].lowerComponents, 2);
  EXPECT_EQ(points[0].upperComponents, 2);
  EXPECT_EQ(count_type(points, directional::geometry::ReliefCriticalType::Minimum),
            2);
  EXPECT_EQ(count_type(points, directional::geometry::ReliefCriticalType::Maximum),
            2);
}

TEST(ReliefTopologyPhase13, PlateauUsesSymbolicOrderButLowPersistenceCanCancel) {
  const MeshFixture mesh = make_grid(1);
  const Eigen::VectorXd relief = Eigen::VectorXd::Constant(4, 1.0);
  directional::geometry::ReliefOptions options;
  options.persistenceThreshold = 0.01;

  const auto topology = directional::geometry::analyze_relief_topology(
      mesh.vertices, mesh.faces, relief, {}, options);

  int retainedExtrema = 0;
  for (const auto &point : topology.criticalPoints) {
    if (point.retained &&
        point.type != directional::geometry::ReliefCriticalType::Regular) {
      ++retainedExtrema;
    }
  }
  EXPECT_LE(retainedExtrema, 1);
}

TEST(ReliefTopologyPhase13, PersistenceThresholdCancelsLowPairsOnly) {
  const MeshFixture mesh = make_saddle_fan();
  Eigen::VectorXd relief(5);
  relief << 0.5, 0.0, 1.0, 0.0, 1.0;

  const auto pairs =
      directional::geometry::compute_relief_persistence_pairs(mesh.vertices,
                                                              mesh.faces,
                                                              relief, 0.25);
  ASSERT_FALSE(pairs.empty());
  for (std::size_t index = 1; index < pairs.size(); ++index) {
    EXPECT_LE(pairs[index - 1].persistence, pairs[index].persistence);
  }
  EXPECT_TRUE(std::none_of(pairs.begin(), pairs.end(), [](const auto &pair) {
    return pair.persistence >= 0.25 && pair.canceled;
  }));
}

TEST(ReliefTopologyPhase13, SaddleBranchesTraceToExtrema) {
  const MeshFixture mesh = make_saddle_fan();
  Eigen::VectorXd relief(5);
  relief << 0.5, 0.0, 1.0, 0.0, 1.0;
  const auto topology =
      directional::geometry::analyze_relief_topology(mesh.vertices, mesh.faces,
                                                     relief);

  ASSERT_FALSE(topology.branches.empty());
  bool hasDescending = false;
  bool hasAscending = false;
  for (const auto &branch : topology.branches) {
    EXPECT_EQ(branch.saddle, 0);
    ASSERT_FALSE(branch.vertices.empty());
    EXPECT_EQ(branch.vertices.front(), 0);
    hasDescending = hasDescending || !branch.ascending;
    hasAscending = hasAscending || branch.ascending;
    if (branch.ascending) {
      EXPECT_EQ(topology.criticalPoints[branch.extremum].type,
                directional::geometry::ReliefCriticalType::Maximum);
    } else {
      EXPECT_EQ(topology.criticalPoints[branch.extremum].type,
                directional::geometry::ReliefCriticalType::Minimum);
    }
  }
  EXPECT_TRUE(hasDescending);
  EXPECT_TRUE(hasAscending);
}

TEST(ReliefTopologyPhase13, CanceledExtremaDoNotAppearInRetainedBranches) {
  const MeshFixture mesh = make_saddle_fan();
  Eigen::VectorXd relief(5);
  relief << 0.5, 0.0, 1.0, 0.0, 1.0;
  directional::geometry::ReliefOptions options;
  options.persistenceThreshold = 0.75;

  const auto topology = directional::geometry::analyze_relief_topology(
      mesh.vertices, mesh.faces, relief, {}, options);

  std::set<int> canceledExtrema;
  for (const auto &pair : topology.persistencePairs) {
    if (pair.canceled) {
      canceledExtrema.insert(pair.extremum);
    }
  }
  ASSERT_FALSE(canceledExtrema.empty());
  for (const auto &branch : topology.branches) {
    EXPECT_EQ(canceledExtrema.count(branch.extremum), 0U);
    ASSERT_GE(branch.saddle, 0);
    ASSERT_GE(branch.extremum, 0);
    EXPECT_TRUE(topology.criticalPoints[branch.saddle].retained);
    EXPECT_TRUE(topology.criticalPoints[branch.extremum].retained);
  }
}

TEST(ReliefTopologyPhase13, WatershedLabelsEveryVertexAndHonorsBarrier) {
  const MeshFixture mesh = make_grid(1);
  const std::set<std::uint64_t> barriers{edge_key(0, 2)};
  const Eigen::VectorXi labels = directional::geometry::watershed_to_roots(
      mesh.vertices, mesh.faces, {1, 3}, barriers);

  ASSERT_EQ(labels.size(), 4);
  for (int vertex = 0; vertex < labels.size(); ++vertex) {
    EXPECT_GE(labels[vertex], 0);
  }
  EXPECT_NE(labels[0], labels[2]);
}

TEST(ReliefTopologyPhase13, RootSelectionIncludesCrossFieldSingularities) {
  const MeshFixture mesh = make_grid(2);
  Eigen::VectorXd relief = Eigen::VectorXd::Zero(mesh.vertices.rows());
  relief[0] = 0.0;
  relief[8] = 1.0;
  const auto topology =
      directional::geometry::analyze_relief_topology(mesh.vertices, mesh.faces,
                                                     relief);
  directional::geometry::ReliefRootSelectionOptions options;
  options.maximumNormalizedDistance = 100.0;
  options.singularities = {4};
  const auto roots = directional::geometry::select_relief_roots(
      mesh.vertices, mesh.faces, topology,
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0), options);

  EXPECT_NE(std::find(roots.roots.begin(), roots.roots.end(), 4),
            roots.roots.end());
  EXPECT_EQ(roots.targets.rows(), static_cast<int>(roots.roots.size()));
  EXPECT_EQ(roots.labels.size(), mesh.vertices.rows());
}

TEST(ReliefTopologyPhase13, RootSelectionPassesBarriersToEveryWatershed) {
  const MeshFixture mesh = make_grid(1);
  directional::geometry::ReliefTopologyResult topology;
  topology.criticalPoints.push_back(
      {1, directional::geometry::ReliefCriticalType::Minimum, 0, 0, 0, true});
  topology.criticalPoints.push_back(
      {3, directional::geometry::ReliefCriticalType::Minimum, 0, 0, 0, true});
  directional::geometry::ReliefRootSelectionOptions options;
  options.maximumNormalizedDistance = 100.0;
  options.hardBarrierEdges.insert(edge_key(0, 2));

  const auto roots = directional::geometry::select_relief_roots(
      mesh.vertices, mesh.faces, topology,
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0), options);

  ASSERT_EQ(roots.labels.size(), mesh.vertices.rows());
  EXPECT_NE(roots.labels[0], roots.labels[2]);
}

TEST(ReliefTopologyPhase13, TriFlowUsesExplicitRootLabelsAndBlocksCrossRootCollapse) {
  const MeshFixture mesh = make_grid(2);
  directional::TriFlowSimplificationOptions options;
  options.targetFaceRatio = 0.25;
  options.preserveBoundary = false;
  options.rejectFaceFlips = false;
  options.prescribedRootLabels.resize(mesh.vertices.rows());
  for (int vertex = 0; vertex < mesh.vertices.rows(); ++vertex) {
    options.prescribedRootLabels[vertex] = mesh.vertices(vertex, 0) < 1.0 ? 0 : 1;
  }
  options.prescribedRootTargets.resize(2, 3);
  options.prescribedRootTargets << 0.0, 1.0, 0.0, 2.0, 1.0, 0.0;

  const auto result =
      directional::tri_flow_simplify(mesh.vertices, mesh.faces, options);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.rootCount, 2);
  for (int vertex = 0; vertex < result.rootLabels.size(); ++vertex) {
    EXPECT_TRUE(result.rootLabels[vertex] == 0 || result.rootLabels[vertex] == 1);
  }
  bool hasLeft = false;
  bool hasRight = false;
  for (int vertex = 0; vertex < result.rootLabels.size(); ++vertex) {
    hasLeft = hasLeft || result.rootLabels[vertex] == 0;
    hasRight = hasRight || result.rootLabels[vertex] == 1;
  }
  EXPECT_TRUE(hasLeft);
  EXPECT_TRUE(hasRight);
}

TEST(ReliefTopologyPhase13, TriFlowProtectedEdgeKeysPreventCollapse) {
  const MeshFixture mesh = make_grid(2);

  directional::TriFlowSimplificationOptions blocked;
  blocked.targetFaceRatio = 0.25;
  blocked.preserveBoundary = false;
  blocked.rejectFaceFlips = false;
  std::set<std::uint64_t> allEdges;
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      allEdges.insert(directional::detail::edge_key(
          mesh.faces(face, corner), mesh.faces(face, (corner + 1) % 3)));
    }
  }
  blocked.protectedEdgeKeys.assign(allEdges.begin(), allEdges.end());
  const auto blockedResult =
      directional::tri_flow_simplify(mesh.vertices, mesh.faces, blocked);

  directional::TriFlowSimplificationOptions unblocked = blocked;
  unblocked.protectedEdgeKeys.clear();
  const auto unblockedResult =
      directional::tri_flow_simplify(mesh.vertices, mesh.faces, unblocked);

  EXPECT_TRUE(blockedResult.success);
  EXPECT_TRUE(unblockedResult.success);
  EXPECT_EQ(blockedResult.collapsedEdges, 0);
  EXPECT_GT(unblockedResult.collapsedEdges, blockedResult.collapsedEdges);
}

TEST(ReliefTopologyPhase13, DcelOptionsExposeExplicitPhase13Targets) {
  directional::TriFlowSimplificationDCELOptions options;
  options.prescribedRootLabels.resize(3);
  options.prescribedRootLabels << 0, 1, 1;
  options.prescribedRootTargets.resize(2, 3);
  options.prescribedRootTargets << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0;
  options.protectedEdgeKeys = {directional::detail::edge_key(0, 1)};

  EXPECT_EQ(options.prescribedRootLabels.size(), 3);
  EXPECT_EQ(options.prescribedRootTargets.rows(), 2);
  EXPECT_EQ(options.protectedEdgeKeys.front(), directional::detail::edge_key(0, 1));
}

TEST(ReliefTopologyPhase13,
     TopologyTargetedDumbbellSimplificationReducesAndIsStable) {
  const MeshFixture mesh = make_dumbbell_strip();
  directional::TriFlowSimplificationOptions options;
  options.targetFaceRatio = 0.5;
  options.preserveBoundary = false;
  options.rejectFaceFlips = false;
  options.prescribedRootLabels.resize(mesh.vertices.rows());
  for (int vertex = 0; vertex < mesh.vertices.rows(); ++vertex) {
    options.prescribedRootLabels[vertex] = mesh.vertices(vertex, 0) <= 2.5 ? 0 : 1;
  }
  options.prescribedRootTargets.resize(2, 3);
  options.prescribedRootTargets << 0.5, 1.0, 0.0, 4.5, 1.0, 0.0;

  const auto first =
      directional::tri_flow_simplify(mesh.vertices, mesh.faces, options);
  ASSERT_TRUE(first.success);
  EXPECT_LE(first.faces.rows(),
            static_cast<int>(std::ceil(0.7 * mesh.faces.rows())));
  bool hasLeft = false;
  bool hasRight = false;
  for (int vertex = 0; vertex < first.rootLabels.size(); ++vertex) {
    hasLeft = hasLeft || first.rootLabels[vertex] == 0;
    hasRight = hasRight || first.rootLabels[vertex] == 1;
  }
  EXPECT_TRUE(hasLeft);
  EXPECT_TRUE(hasRight);

  const std::uint64_t expectedHash = structural_hash(first);
  for (int run = 0; run < 9; ++run) {
    const auto repeated =
        directional::tri_flow_simplify(mesh.vertices, mesh.faces, options);
    ASSERT_TRUE(repeated.success);
    EXPECT_EQ(structural_hash(repeated), expectedHash);
  }
}
