#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include <directional/integration/IntegerTransitionBasis.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

Eigen::SparseMatrix<int>
make_relations(const int rows, const int cols,
               const std::vector<Eigen::Triplet<int>> &triplets) {
  Eigen::SparseMatrix<int> matrix(rows, cols);
  matrix.setFromTriplets(triplets.begin(), triplets.end());
  matrix.makeCompressed();
  return matrix;
}

Eigen::VectorXi reconstruct(const Eigen::SparseMatrix<int> &mapping,
                            const Eigen::VectorXi &independent) {
  return mapping * independent;
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

directional::pipeline::RemeshResult run_reduction_integration(
    const bool reduceIntegerTransitionBasis) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.integerTransitionBasis.reduceIntegerTransitionBasis =
      reduceIntegerTransitionBasis;
  return directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, make_axis_raw_field(mesh.faces.rows()),
      options);
}

} // namespace

TEST(IntegerTransitionBasisPhase03, IntegerBasisIdentityWhenNoDependenciesExist) {
  const Eigen::SparseMatrix<int> relations = make_relations(0, 3, {});

  const directional::IntegerTransitionBasisResult result =
      directional::detail::IntegerTransitionBasis::analyze_relation_matrix(
          relations);

  EXPECT_EQ(result.rawIntegerVariableCount, 3);
  EXPECT_EQ(result.reducedIntegerVariableCount, 3);
  EXPECT_EQ(result.redundantIntegerVariableCount, 0);
  EXPECT_FALSE(result.exactReductionAvailable);
  ASSERT_EQ(result.fullFromIndependent.rows(), 3);
  ASSERT_EQ(result.fullFromIndependent.cols(), 3);
}

TEST(IntegerTransitionBasisPhase03,
     IntegerBasisRemovesKnownSyntheticDependency) {
  const Eigen::SparseMatrix<int> relations =
      make_relations(1, 3, {{0, 0, 1}, {0, 1, -1}, {0, 2, -1}});

  directional::IntegerTransitionBasisOptions options;
  options.reduceIntegerTransitionBasis = true;
  const directional::IntegerTransitionBasisResult result =
      directional::detail::IntegerTransitionBasis::analyze_relation_matrix(
          relations, options);

  EXPECT_TRUE(result.exactReductionAvailable);
  EXPECT_TRUE(result.reductionEnabled);
  EXPECT_EQ(result.reducedIntegerVariableCount, 2);
  EXPECT_EQ(result.redundantIntegerVariableCount, 1);

  Eigen::VectorXi independent(2);
  independent << 7, -3;
  const Eigen::VectorXi full = reconstruct(result.fullFromIndependent,
                                           independent);
  ASSERT_EQ(full.size(), 3);
  EXPECT_EQ(full(0), 7);
  EXPECT_EQ(full(1), -3);
  EXPECT_EQ(full(2), 10);
  EXPECT_EQ((relations * full).norm(), 0);
}

TEST(IntegerTransitionBasisPhase03, IntegerBasisPreservesIntegerLattice) {
  const Eigen::SparseMatrix<int> relations =
      make_relations(1, 3, {{0, 0, 1}, {0, 1, -1}, {0, 2, -1}});

  directional::IntegerTransitionBasisOptions options;
  options.reduceIntegerTransitionBasis = true;
  const directional::IntegerTransitionBasisResult result =
      directional::detail::IntegerTransitionBasis::analyze_relation_matrix(
          relations, options);

  ASSERT_EQ(result.fullFromIndependent.cols(), 2);
  for (int first = -3; first <= 3; ++first) {
    for (int second = -3; second <= 3; ++second) {
      Eigen::VectorXi independent(2);
      independent << first, second;
      const Eigen::VectorXi full =
          reconstruct(result.fullFromIndependent, independent);
      EXPECT_EQ((relations * full).norm(), 0);
    }
  }
}

TEST(IntegerTransitionBasisPhase03,
     BasisDoesNotCreateChainedDependentColumnMapping) {
  const Eigen::SparseMatrix<int> relations =
      make_relations(2, 3, {{0, 0, 1},
                            {0, 1, -1},
                            {0, 2, -1},
                            {1, 0, -1},
                            {1, 1, 1}});

  directional::IntegerTransitionBasisOptions options;
  options.reduceIntegerTransitionBasis = true;
  const directional::IntegerTransitionBasisResult result =
      directional::detail::IntegerTransitionBasis::analyze_relation_matrix(
          relations, options);

  EXPECT_EQ(result.fullFromIndependent.rows(), 3);
  EXPECT_EQ(result.fullFromIndependent.cols(), 3);
  EXPECT_FALSE(result.exactReductionAvailable);
  EXPECT_FALSE(result.reductionEnabled);
  const Eigen::SparseMatrix<int> residual =
      relations * result.fullFromIndependent;
  EXPECT_EQ(residual.nonZeros(), relations.nonZeros());
}

TEST(IntegerTransitionBasisPhase03,
     BasisRejectsUnverifiedFloatingPointDependency) {
  const Eigen::SparseMatrix<int> relations =
      make_relations(1, 2, {{0, 0, 2}, {0, 1, -3}});

  directional::IntegerTransitionBasisOptions options;
  options.reduceIntegerTransitionBasis = true;
  const directional::IntegerTransitionBasisResult result =
      directional::detail::IntegerTransitionBasis::analyze_relation_matrix(
          relations, options);

  EXPECT_FALSE(result.exactReductionAvailable);
  EXPECT_EQ(result.reducedIntegerVariableCount, 2);
  EXPECT_EQ(result.redundantIntegerVariableCount, 0);
}

TEST(IntegerTransitionBasisPhase03,
     BasisReconstructionSatisfiesOriginalConstraints) {
  const Eigen::SparseMatrix<int> relations =
      make_relations(2, 4, {{0, 0, 1}, {0, 2, -1}, {1, 1, 1}, {1, 3, -1}});

  directional::IntegerTransitionBasisOptions options;
  options.reduceIntegerTransitionBasis = true;
  const directional::IntegerTransitionBasisResult result =
      directional::detail::IntegerTransitionBasis::analyze_relation_matrix(
          relations, options);

  ASSERT_TRUE(result.exactReductionAvailable);
  ASSERT_EQ(result.fullFromIndependent.cols(), 2);
  Eigen::VectorXi independent(2);
  independent << 4, -5;
  const Eigen::VectorXi full =
      reconstruct(result.fullFromIndependent, independent);
  EXPECT_EQ((relations * full).norm(), 0);
}

TEST(IntegerTransitionBasisPhase03,
     ReductionCanBeDisabledWithoutChangingLegacyPath) {
  const directional::pipeline::RemeshResult disabled =
      run_reduction_integration(false);
  const directional::pipeline::RemeshResult enabled =
      run_reduction_integration(true);

  ASSERT_TRUE(disabled.is_produced());
  ASSERT_TRUE(enabled.is_produced());
  EXPECT_EQ(enabled.product().faces.rows(), disabled.product().faces.rows());
  EXPECT_EQ(enabled.product().degrees.size(), disabled.product().degrees.size());
  EXPECT_EQ(enabled.diagnostics.integration.reducedIntegerVariableCount,
            disabled.diagnostics.integration.reducedIntegerVariableCount);
  EXPECT_FALSE(enabled.diagnostics.integration
                   .integerTransitionReductionEnabled);
}
