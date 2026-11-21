#include <directional/geometry/SurfaceOptimizationRailConstraints.h>

#include <algorithm>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

TEST(MilestoneFP19Integration, RailsBecomeOrderedExplicitOptimizerIntervals) {
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(5));
  rail.curveId = 8;
  rail.component = 0;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;

  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.railParameter = 0.0;
  a.position << 0.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample b = a;
  b.railParameter = 1.0;
  b.position << 1.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample c = b;
  directional::geometry::SurfaceCellRailSample d = c;
  d.railParameter = 2.0;
  d.position << 1.0, 1.0, 0.0;
  rail.samples = {a, b, c, d};

  Eigen::MatrixXd outputVertices(3, 3);
  outputVertices << 0.25, 0.0, 0.0,
                    1.0, 0.0, 0.0,
                    1.0, 0.75, 0.0;
  std::vector<directional::geometry::SurfacePoint> provenance(3);
  for (auto &point : provenance) {
    point.face = 0;
    point.component = 0;
    point.sheet = 4;
    point.barycentric << 1.0, 0.0, 0.0;
  }

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceFaceSheet = {4};
  directional::geometry::fill_surface_optimization_rail_constraints(
      {rail}, outputVertices, provenance, constraints);

  ASSERT_EQ(constraints.featureCurveIntervals.size(), 2U);
  EXPECT_EQ(constraints.featureCurveIntervals[0].intervalId, 0);
  EXPECT_EQ(constraints.featureCurveIntervals[1].intervalId, 1);
  EXPECT_DOUBLE_EQ(constraints.featureCurveIntervals[0].parameterStart, 0.0);
  EXPECT_DOUBLE_EQ(constraints.featureCurveIntervals[0].parameterEnd, 1.0);
  EXPECT_DOUBLE_EQ(constraints.featureCurveIntervals[1].parameterStart, 1.0);
  EXPECT_DOUBLE_EQ(constraints.featureCurveIntervals[1].parameterEnd, 2.0);
  EXPECT_EQ(constraints.featureVertices.size(), 3U);
  EXPECT_EQ(constraints.featureCurveIds(0), 8);
  EXPECT_EQ(constraints.featureIntervalIds(0), 0);
  EXPECT_EQ(constraints.featureIntervalIds(2), 1);
  EXPECT_NEAR(constraints.featureParameters(0), 0.25, 1.0e-12);
  EXPECT_NEAR(constraints.featureParameters(2), 1.75, 1.0e-12);
  EXPECT_EQ(constraints.orderedFeatureVertices,
            (std::vector<int>{0, 1, 2}));
  EXPECT_NE(std::find(constraints.fixedVertices.begin(),
                      constraints.fixedVertices.end(), 1),
            constraints.fixedVertices.end());
}

TEST(MilestoneFP19Integration,
     CollinearRailIntervalJoinRemainsFreeToSlide) {
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(2));
  rail.curveId = 3;
  rail.component = 0;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;

  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.railParameter = 0.0;
  a.position << 0.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample b = a;
  b.railParameter = 1.0;
  b.position << 1.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample c = b;
  directional::geometry::SurfaceCellRailSample d = c;
  d.railParameter = 2.0;
  d.position << 2.0, 0.0, 0.0;
  rail.samples = {a, b, c, d};

  Eigen::MatrixXd outputVertices(1, 3);
  outputVertices << 1.0, 0.0, 0.0;
  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 0;
  point.sheet = 1;
  point.barycentric << 1.0, 0.0, 0.0;

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceFaceSheet = {1};
  directional::geometry::fill_surface_optimization_rail_constraints(
      {rail}, outputVertices, {point}, constraints);

  ASSERT_EQ(constraints.featureVertices, (std::vector<int>{0}));
  EXPECT_EQ(constraints.featureCurveIds(0), 3);
  EXPECT_EQ(constraints.featureIntervalIds(0), 0);
  EXPECT_DOUBLE_EQ(constraints.featureParameters(0), 1.0);
  EXPECT_EQ(std::find(constraints.fixedVertices.begin(),
                      constraints.fixedVertices.end(), 0),
            constraints.fixedVertices.end());
}

TEST(MilestoneFP19Integration,
     DescendingRailParametersPreserveTraversalOrder) {
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(6));
  rail.curveId = 9;
  rail.component = 0;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;

  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.railParameter = 2.0;
  a.position << 0.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample b = a;
  b.railParameter = 1.0;
  b.position << 1.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample c = b;
  directional::geometry::SurfaceCellRailSample d = c;
  d.railParameter = 0.0;
  d.position << 2.0, 0.0, 0.0;
  rail.samples = {a, b, c, d};

  Eigen::MatrixXd outputVertices(2, 3);
  outputVertices << 0.25, 0.0, 0.0,
                    1.75, 0.0, 0.0;
  std::vector<directional::geometry::SurfacePoint> provenance(2);
  for (auto &point : provenance) {
    point.face = 0;
    point.component = 0;
    point.sheet = 5;
    point.barycentric << 1.0, 0.0, 0.0;
  }

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceFaceSheet = {5};
  directional::geometry::fill_surface_optimization_rail_constraints(
      {rail}, outputVertices, provenance, constraints);

  EXPECT_EQ(constraints.orderedFeatureVertices,
            (std::vector<int>{0, 1}));
  EXPECT_NEAR(constraints.featureParameters(0), 1.75, 1.0e-12);
  EXPECT_NEAR(constraints.featureParameters(1), 0.25, 1.0e-12);

  bool ordered = false;
  directional::geometry::surface_optimizer_detail::project_vertices(
      outputVertices, constraints, nullptr, &ordered, nullptr);
  EXPECT_TRUE(ordered);
}

TEST(MilestoneFP19Integration,
     SplitRailsRetainIndependentSequenceIdentity) {
  directional::geometry::SurfaceCellRail first(directional::tests::test_hard_rail_id(10));
  first.curveId = 12;
  first.component = 0;
  first.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.railParameter = 0.0;
  a.position << 0.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample b = a;
  b.railParameter = 1.0;
  b.position << 1.0, 0.0, 0.0;
  first.samples = {a, b};

  directional::geometry::SurfaceCellRail second = first;
  second.id = directional::tests::test_hard_rail_id(11);
  directional::geometry::SurfaceCellRailSample c = a;
  c.position << 2.0, 0.0, 0.0;
  directional::geometry::SurfaceCellRailSample d = b;
  d.position << 3.0, 0.0, 0.0;
  second.samples = {c, d};

  Eigen::MatrixXd outputVertices(2, 3);
  outputVertices << 0.75, 0.0, 0.0,
                    2.25, 0.0, 0.0;
  std::vector<directional::geometry::SurfacePoint> provenance(2);
  for (auto &point : provenance) {
    point.face = 0;
    point.component = 0;
    point.sheet = 6;
    point.barycentric << 1.0, 0.0, 0.0;
  }

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceFaceSheet = {6};
  directional::geometry::fill_surface_optimization_rail_constraints(
      {first, second}, outputVertices, provenance, constraints);

  EXPECT_EQ(constraints.featureCurveIds(0), 12);
  EXPECT_EQ(constraints.featureCurveIds(1), 12);
  EXPECT_EQ(constraints.featureRailIds[0], directional::tests::test_hard_rail_id(10));
  EXPECT_EQ(constraints.featureRailIds[1], directional::tests::test_hard_rail_id(11));
  EXPECT_EQ(constraints.orderedFeatureVertices,
            (std::vector<int>{0, 1}));

  bool ordered = false;
  directional::geometry::surface_optimizer_detail::project_vertices(
      outputVertices, constraints, nullptr, &ordered, nullptr);
  EXPECT_TRUE(ordered);
}
