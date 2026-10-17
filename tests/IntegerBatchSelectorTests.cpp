#include <vector>

#include <gtest/gtest.h>

#include <directional/integration/IntegerBatchSelector.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

Eigen::SparseMatrix<double>
make_energy(const int size,
            const std::vector<Eigen::Triplet<double>> &extraTriplets = {}) {
  std::vector<Eigen::Triplet<double>> triplets;
  for (int i = 0; i < size; ++i) {
    triplets.emplace_back(i, i, 1.0);
  }
  triplets.insert(triplets.end(), extraTriplets.begin(), extraTriplets.end());
  Eigen::SparseMatrix<double> energy(size, size);
  energy.setFromTriplets(triplets.begin(), triplets.end());
  energy.makeCompressed();
  return energy;
}

directional::IntegerBatchCandidate candidate(const int index,
                                             const double residual) {
  return directional::IntegerBatchCandidate{index, residual, 0.0, residual};
}

directional::IntegerBatchOptions coupling_options() {
  directional::IntegerBatchOptions options;
  options.strategy = directional::IntegerBatchStrategy::CouplingAware;
  options.maximumBatchSize = 4;
  options.absoluteResidualCeiling = 0.5;
  options.residualWindow = 0.5;
  options.couplingThreshold = 0.25;
  options.useInfluenceOverlap = false;
  return options;
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

directional::pipeline::RemeshResult run_batching_integration(
    const directional::IntegerBatchStrategy strategy) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.integrationSolveStrategy =
      directional::IntegrationSolveStrategy::DirectOnly;
  options.integerBatching.strategy = strategy;
  return directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, make_axis_raw_field(mesh.faces.rows()),
      options);
}

} // namespace

TEST(IntegerBatchSelectorPhase02,
     CouplingAwareSelectorSeparatesStronglyCoupledCandidates) {
  const Eigen::SparseMatrix<double> energy =
      make_energy(3, {{0, 1, 0.8}, {1, 0, 0.8}});
  std::vector<directional::IntegerBatchCandidate> candidates{
      candidate(0, 0.01), candidate(1, 0.02), candidate(2, 0.03)};

  const directional::IntegerBatchSelectionResult result =
      directional::detail::IntegerBatchSelector::select(candidates, energy,
                                                        coupling_options());

  ASSERT_GE(result.selected.size(), 2);
  EXPECT_EQ(result.selected[0].index, 0);
  EXPECT_EQ(result.selected[1].index, 2);
}

TEST(IntegerBatchSelectorPhase02,
     CouplingAwareSelectorBatchesIndependentCandidates) {
  const Eigen::SparseMatrix<double> energy = make_energy(4);
  std::vector<directional::IntegerBatchCandidate> candidates{
      candidate(0, 0.01), candidate(2, 0.02), candidate(3, 0.03)};

  const directional::IntegerBatchSelectionResult result =
      directional::detail::IntegerBatchSelector::select(candidates, energy,
                                                        coupling_options());

  ASSERT_EQ(result.selected.size(), 3);
  EXPECT_EQ(result.selected[0].index, 0);
  EXPECT_EQ(result.selected[1].index, 2);
  EXPECT_EQ(result.selected[2].index, 3);
}

TEST(IntegerBatchSelectorPhase02, BestCandidateIsAlwaysSelected) {
  directional::IntegerBatchOptions options = coupling_options();
  options.maximumBatchSize = 1;
  options.absoluteResidualCeiling = 0.0;
  const Eigen::SparseMatrix<double> energy = make_energy(2);
  std::vector<directional::IntegerBatchCandidate> candidates{
      candidate(1, 0.25), candidate(0, 0.10)};

  const directional::IntegerBatchSelectionResult result =
      directional::detail::IntegerBatchSelector::select(candidates, energy,
                                                        options);

  ASSERT_EQ(result.selected.size(), 1);
  EXPECT_EQ(result.selected[0].index, 0);
}

TEST(IntegerBatchSelectorPhase02, SelectorRespectsMaximumBatchSize) {
  directional::IntegerBatchOptions options = coupling_options();
  options.maximumBatchSize = 2;
  const Eigen::SparseMatrix<double> energy = make_energy(4);
  std::vector<directional::IntegerBatchCandidate> candidates{
      candidate(0, 0.01), candidate(1, 0.02), candidate(2, 0.03)};

  const directional::IntegerBatchSelectionResult result =
      directional::detail::IntegerBatchSelector::select(candidates, energy,
                                                        options);

  EXPECT_EQ(result.selected.size(), 2);
}

TEST(IntegerBatchSelectorPhase02, SelectorIsDeterministicForEqualResiduals) {
  const Eigen::SparseMatrix<double> energy = make_energy(4);
  std::vector<directional::IntegerBatchCandidate> candidates{
      candidate(3, 0.01), candidate(1, 0.01), candidate(2, 0.01)};

  const directional::IntegerBatchSelectionResult result =
      directional::detail::IntegerBatchSelector::select(candidates, energy,
                                                        coupling_options());

  ASSERT_EQ(result.selected.size(), 3);
  EXPECT_EQ(result.selected[0].index, 1);
  EXPECT_EQ(result.selected[1].index, 2);
  EXPECT_EQ(result.selected[2].index, 3);
}

TEST(IntegerBatchSelectorPhase02,
     CouplingAwareBatchingPreservesIntegrationQuality) {
  const directional::pipeline::RemeshResult residual =
      run_batching_integration(directional::IntegerBatchStrategy::ResidualOnly);
  const directional::pipeline::RemeshResult coupling =
      run_batching_integration(directional::IntegerBatchStrategy::CouplingAware);

  ASSERT_TRUE(residual.is_produced());
  ASSERT_TRUE(coupling.is_produced());
  EXPECT_LE(coupling.diagnostics.integration.finalConstraintResidualNorm,
            residual.diagnostics.integration.finalConstraintResidualNorm +
                1.0e-8);
  EXPECT_NEAR(coupling.diagnostics.integration.maximumUnresolvedIntegerResidual,
              residual.diagnostics.integration.maximumUnresolvedIntegerResidual,
              1.0e-8);
}

TEST(IntegerBatchSelectorPhase02,
     CouplingAwareBatchingDoesNotIncreaseSolverFailureCount) {
  const directional::pipeline::RemeshResult residual =
      run_batching_integration(directional::IntegerBatchStrategy::ResidualOnly);
  const directional::pipeline::RemeshResult coupling =
      run_batching_integration(directional::IntegerBatchStrategy::CouplingAware);

  ASSERT_TRUE(residual.is_produced());
  ASSERT_TRUE(coupling.is_produced());
  EXPECT_LE(coupling.diagnostics.integration.factorizationFailures,
            residual.diagnostics.integration.factorizationFailures);
  EXPECT_LE(coupling.diagnostics.integration.solveFailures,
            residual.diagnostics.integration.solveFailures);
}

TEST(IntegerBatchSelectorPhase02,
     CouplingAwareBatchingMaintainsRemeshTopologySignature) {
  const directional::pipeline::RemeshResult residual =
      run_batching_integration(directional::IntegerBatchStrategy::ResidualOnly);
  const directional::pipeline::RemeshResult coupling =
      run_batching_integration(directional::IntegerBatchStrategy::CouplingAware);

  ASSERT_TRUE(residual.is_produced());
  ASSERT_TRUE(coupling.is_produced());
  EXPECT_EQ(coupling.product().faces.rows(), residual.product().faces.rows());
  EXPECT_EQ(coupling.product().degrees.size(), residual.product().degrees.size());
  for (int face = 0; face < coupling.product().degrees.size(); ++face) {
    EXPECT_EQ(coupling.product().degrees(face), residual.product().degrees(face));
  }
}
