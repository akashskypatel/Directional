#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <vector>

#include <gtest/gtest.h>

#include <Eigen/SparseLU>

#include <directional/integration/solvers/AdaptiveKktSolver.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

Eigen::SparseMatrix<double> make_kkt_system() {
  std::vector<Eigen::Triplet<double>> triplets;
  triplets.emplace_back(0, 0, 4.0);
  triplets.emplace_back(0, 1, 1.0);
  triplets.emplace_back(1, 0, 1.0);
  triplets.emplace_back(1, 1, 3.0);
  triplets.emplace_back(0, 2, 1.0);
  triplets.emplace_back(2, 0, 1.0);
  Eigen::SparseMatrix<double> matrix(3, 3);
  matrix.setFromTriplets(triplets.begin(), triplets.end());
  return matrix;
}

directional::AdaptiveIntegrationOptions strict_adaptive_options() {
  directional::AdaptiveIntegrationOptions options;
  options.maxIterations = 64;
  options.relativeResidualTolerance = 1.0e-10;
  options.absoluteResidualTolerance = 1.0e-10;
  options.constraintResidualTolerance = 1.0e-10;
  options.useWarmStart = true;
  return options;
}

struct FallbackResult {
  bool fallbackInvoked = false;
  Eigen::VectorXd solution;
};

FallbackResult solve_with_direct_fallback(
    const Eigen::SparseMatrix<double> &system, const Eigen::VectorXd &rhs,
    const directional::AdaptiveIntegrationOptions &options) {
  const Eigen::VectorXd initialGuess = Eigen::VectorXd::Zero(rhs.size());
  const directional::detail::AdaptiveKktSolveResult adaptive =
      directional::detail::AdaptiveKktSolver::solve(system, rhs, initialGuess,
                                                    1, options);
  if (adaptive.accepted) {
    return {false, adaptive.solution};
  }

  Eigen::SparseLU<Eigen::SparseMatrix<double>> direct;
  direct.compute(system);
  return {true, direct.solve(rhs)};
}

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

SyntheticMesh make_grid_mesh(const int subdivisions) {
  SyntheticMesh mesh;
  const int n = std::max(1, subdivisions);
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices(vertex, 0) = static_cast<double>(x) / n;
      mesh.vertices(vertex, 1) = static_cast<double>(y) / n;
      mesh.vertices(vertex, 2) = 0.0;
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

Eigen::MatrixXd make_axis_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.row(face) << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0,
        -1.0, 0.0;
  }
  return raw;
}

std::map<int, int>
face_degree_histogram(const directional::pipeline::RemeshResult &result) {
  std::map<int, int> histogram;
  for (int face = 0; face < result.product().degrees.size(); ++face) {
    ++histogram[result.product().degrees(face)];
  }
  return histogram;
}

struct TopologySignature {
  int connectedComponents = 0;
  int boundaryEdges = 0;
};

TopologySignature topology_signature(
    const directional::pipeline::RemeshResult &result) {
  TopologySignature signature;
  std::map<std::pair<int, int>, int> edgeUse;
  std::vector<std::vector<int>> adjacency(
      static_cast<std::size_t>(result.product().vertices.rows()));
  for (int face = 0; face < result.product().faces.rows(); ++face) {
    for (int corner = 0; corner < result.product().degrees(face); ++corner) {
      const int a = result.product().faces(face, corner);
      const int b = result.product().faces(face, (corner + 1) % result.product().degrees(face));
      const auto edge = std::minmax(a, b);
      ++edgeUse[edge];
      adjacency[static_cast<std::size_t>(a)].push_back(b);
      adjacency[static_cast<std::size_t>(b)].push_back(a);
    }
  }
  for (const auto &[edge, useCount] : edgeUse) {
    (void)edge;
    if (useCount == 1) {
      ++signature.boundaryEdges;
    }
  }

  std::vector<unsigned char> visited(
      static_cast<std::size_t>(result.product().vertices.rows()), 0);
  for (int vertex = 0; vertex < result.product().vertices.rows(); ++vertex) {
    if (visited[static_cast<std::size_t>(vertex)] ||
        adjacency[static_cast<std::size_t>(vertex)].empty()) {
      continue;
    }
    ++signature.connectedComponents;
    std::vector<int> stack{vertex};
    visited[static_cast<std::size_t>(vertex)] = 1;
    while (!stack.empty()) {
      const int current = stack.back();
      stack.pop_back();
      for (const int next : adjacency[static_cast<std::size_t>(current)]) {
        if (!visited[static_cast<std::size_t>(next)]) {
          visited[static_cast<std::size_t>(next)] = 1;
          stack.push_back(next);
        }
      }
    }
  }
  return signature;
}

} // namespace

TEST(AdaptiveIntegrationSolverPhase01,
     AdaptiveSolverMatchesDirectOnSyntheticSymmetricIndefiniteSystem) {
  const Eigen::SparseMatrix<double> system = make_kkt_system();
  Eigen::VectorXd rhs(3);
  rhs << 1.0, 2.0, 0.0;

  Eigen::SparseLU<Eigen::SparseMatrix<double>> direct;
  direct.compute(system);
  const Eigen::VectorXd directSolution = direct.solve(rhs);

  const directional::detail::AdaptiveKktSolveResult adaptive =
      directional::detail::AdaptiveKktSolver::solve(
          system, rhs, Eigen::VectorXd::Zero(3), 1,
          strict_adaptive_options());

  ASSERT_TRUE(adaptive.accepted);
  EXPECT_TRUE(adaptive.solution.allFinite());
  EXPECT_LT((adaptive.solution - directSolution).norm(), 1.0e-8);
  EXPECT_LE(adaptive.relativeResidual, 1.0e-10);
}

TEST(AdaptiveIntegrationSolverPhase01,
     AdaptiveSolverFallsBackWhenIterationBudgetIsTooSmall) {
  directional::AdaptiveIntegrationOptions options = strict_adaptive_options();
  options.maxIterations = 1;
  Eigen::VectorXd rhs(3);
  rhs << 1.0, 2.0, 0.0;

  const FallbackResult result =
      solve_with_direct_fallback(make_kkt_system(), rhs, options);

  EXPECT_TRUE(result.fallbackInvoked);
  EXPECT_TRUE(result.solution.allFinite());
  EXPECT_LT((make_kkt_system() * result.solution - rhs).norm(), 1.0e-10);
}

TEST(AdaptiveIntegrationSolverPhase01,
     WarmStartMapsShrinkingFreeVariableSetCorrectly) {
  Eigen::VectorXd previous(5);
  previous << 10.0, 20.0, 30.0, 40.0, 50.0;
  const std::vector<int> freeToFull{0, 2, 4};

  const Eigen::VectorXd warmStart =
      directional::detail::AdaptiveKktSolver::map_warm_start(
          previous, freeToFull, 5, strict_adaptive_options());

  ASSERT_EQ(warmStart.size(), 5);
  EXPECT_DOUBLE_EQ(warmStart(0), 10.0);
  EXPECT_DOUBLE_EQ(warmStart(1), 30.0);
  EXPECT_DOUBLE_EQ(warmStart(2), 50.0);
  EXPECT_DOUBLE_EQ(warmStart(3), 0.0);
  EXPECT_DOUBLE_EQ(warmStart(4), 0.0);
}

TEST(AdaptiveIntegrationSolverPhase01, AdaptiveSolverRejectsNonFiniteCandidate) {
  Eigen::VectorXd rhs(3);
  rhs << 1.0, std::numeric_limits<double>::quiet_NaN(), 0.0;

  const directional::detail::AdaptiveKktSolveResult adaptive =
      directional::detail::AdaptiveKktSolver::solve(
          make_kkt_system(), rhs, Eigen::VectorXd::Zero(3), 1,
          strict_adaptive_options());

  EXPECT_FALSE(adaptive.accepted);
}

TEST(AdaptiveIntegrationSolverPhase01,
     AdaptiveAndDirectProduceEquivalentIntegrationQuality) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  const Eigen::MatrixXd rawField = make_axis_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions directOptions;
  directOptions.lengthRatio = 0.2;
  directOptions.integralSeamless = false;
  directOptions.roundSeams = false;
  directOptions.integrationSolveStrategy =
      directional::IntegrationSolveStrategy::DirectOnly;

  directional::pipeline::RemeshOptions adaptiveOptions = directOptions;
  adaptiveOptions.integrationSolveStrategy =
      directional::IntegrationSolveStrategy::Adaptive;
  adaptiveOptions.adaptiveIntegration.maxIterations = 128;

  const directional::pipeline::RemeshResult direct =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, rawField, directOptions);
  const directional::pipeline::RemeshResult adaptive =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, rawField, adaptiveOptions);

  ASSERT_TRUE(direct.is_produced());
  ASSERT_TRUE(adaptive.is_produced());
  EXPECT_LE(adaptive.diagnostics.integration.finalConstraintResidualNorm,
            direct.diagnostics.integration.finalConstraintResidualNorm +
                1.0e-8);
  EXPECT_LE(
      adaptive.diagnostics.integration.maximumUnresolvedIntegerResidual,
      direct.diagnostics.integration.maximumUnresolvedIntegerResidual + 1.0e-8);
  EXPECT_NEAR(adaptive.diagnostics.integration.finalIntegrationEnergy,
              direct.diagnostics.integration.finalIntegrationEnergy, 1.0e-6);
}

TEST(AdaptiveIntegrationSolverPhase01,
     AdaptiveAndDirectProduceEquivalentRemeshTopologySignature) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  const Eigen::MatrixXd rawField = make_axis_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions directOptions;
  directOptions.lengthRatio = 0.2;
  directOptions.integralSeamless = false;
  directOptions.roundSeams = false;

  directional::pipeline::RemeshOptions adaptiveOptions = directOptions;
  adaptiveOptions.integrationSolveStrategy =
      directional::IntegrationSolveStrategy::Adaptive;
  adaptiveOptions.adaptiveIntegration.maxIterations = 128;

  const directional::pipeline::RemeshResult direct =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, rawField, directOptions);
  const directional::pipeline::RemeshResult adaptive =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, rawField, adaptiveOptions);

  ASSERT_TRUE(direct.is_produced());
  ASSERT_TRUE(adaptive.is_produced());
  EXPECT_EQ(face_degree_histogram(adaptive), face_degree_histogram(direct));

  const TopologySignature directTopology = topology_signature(direct);
  const TopologySignature adaptiveTopology = topology_signature(adaptive);
  EXPECT_EQ(adaptiveTopology.connectedComponents,
            directTopology.connectedComponents);
  EXPECT_EQ(adaptiveTopology.boundaryEdges, directTopology.boundaryEdges);
}
