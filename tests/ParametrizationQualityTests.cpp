#include <gtest/gtest.h>

#include <directional/integration/ParametrizationQuality.h>

namespace {

Eigen::MatrixXd triangle_vertices() {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  return vertices;
}

Eigen::MatrixXi single_triangle() {
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  return faces;
}

} // namespace

TEST(ParametrizationQualityPhase09, QualityMetricDetectsPositiveAreaTriangle) {
  Eigen::MatrixXd uv(3, 2);
  uv << 0.0, 0.0, 1.0, 0.0, 0.0, 1.0;

  const directional::ParametrizationQualityReport report =
      directional::analyze_parametrization_quality(triangle_vertices(),
                                                   single_triangle(), uv);

  ASSERT_EQ(report.faces.size(), 1U);
  EXPECT_GT(report.faces[0].determinant, 0.0);
  EXPECT_FALSE(report.faces[0].bad);
  EXPECT_EQ(report.badFaceCount, 0U);
  EXPECT_NEAR(report.faces[0].sigmaMin, 1.0, 1.0e-12);
  EXPECT_NEAR(report.faces[0].sigmaMax, 1.0, 1.0e-12);
}

TEST(ParametrizationQualityPhase09, QualityMetricDetectsInvertedTriangle) {
  Eigen::MatrixXd uv(3, 2);
  uv << 0.0, 0.0, 0.0, 1.0, 1.0, 0.0;

  const directional::ParametrizationQualityReport report =
      directional::analyze_parametrization_quality(triangle_vertices(),
                                                   single_triangle(), uv);

  ASSERT_EQ(report.faces.size(), 1U);
  EXPECT_LT(report.faces[0].determinant, 0.0);
  EXPECT_TRUE(report.faces[0].inverted);
  EXPECT_TRUE(report.faces[0].bad);
  EXPECT_EQ(report.invertedFaceCount, 1U);
  EXPECT_EQ(report.badFaceCount, 1U);
}

TEST(ParametrizationQualityPhase09, QualityMetricDetectsNearDegenerateTriangle) {
  Eigen::MatrixXd uv(3, 2);
  uv << 0.0, 0.0, 1.0, 0.0, 0.0, 1.0e-9;

  directional::ParametrizationQualityThresholds thresholds;
  thresholds.minimumSingularValue = 1.0e-6;

  const directional::ParametrizationQualityReport report =
      directional::analyze_parametrization_quality(
          triangle_vertices(), single_triangle(), uv, thresholds);

  ASSERT_EQ(report.faces.size(), 1U);
  EXPECT_TRUE(report.faces[0].nearDegenerate);
  EXPECT_TRUE(report.faces[0].bad);
  EXPECT_EQ(report.nearDegenerateFaceCount, 1U);
  EXPECT_EQ(report.badFaceCount, 1U);
}

TEST(ParametrizationQualityPhase09,
     TargetedWeightsAffectOnlySelectedFaceNeighborhood) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2.0, 0.0,
      0.0, 5.0, 5.0, 0.0, 6.0, 5.0, 0.0;

  Eigen::MatrixXi faces(3, 3);
  faces << 0, 1, 2, 1, 3, 2, 3, 4, 5;

  directional::ParametrizationQualityReport report;
  report.faces.resize(3);
  report.faces[0].bad = true;
  report.badFaceCount = 1;

  directional::TargetedStiffeningOptions options;
  options.badFaceWeight = 4.0;
  options.neighborDecay = 0.25;

  const directional::TargetedStiffeningWeights weights =
      directional::build_targeted_stiffening_weights(faces, report, options);

  ASSERT_EQ(weights.faceWeights.size(), 3);
  ASSERT_EQ(weights.badFaces.size(), 1U);
  EXPECT_DOUBLE_EQ(weights.faceWeights(0), 5.0);
  EXPECT_DOUBLE_EQ(weights.faceWeights(1), 2.0);
  EXPECT_DOUBLE_EQ(weights.faceWeights(2), 1.0);
}
