#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <memory>
#include <stdexcept>
#include <vector>

#include <gtest/gtest.h>

namespace directional::geometry::surface_arrangement_detail {
SurfaceCellCanonicalIdentity diagnostic_source_entity_identity(
    const ResolvedSourceEntity &entity);
}

namespace {

const directional::geometry::SourceTopologyRegions *
row_identity_source_authority(const Eigen::MatrixXi &faces,
                              const std::vector<int> &components,
                              const std::vector<int> &sheets) {
  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.sourceFaceComponents = components;
  tracing.sourceFaceSheets = sheets;
  auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, tracing);
  if (!authority.has_value()) {
    throw std::runtime_error(
        "Failed to construct typed row-identity source authority.");
  }
  static std::vector<
      std::unique_ptr<directional::geometry::SourceTopologyRegions>>
      arena;
  arena.push_back(
      std::make_unique<directional::geometry::SourceTopologyRegions>(
          std::move(*authority)));
  return arena.back().get();
}

TEST(SurfaceArrangementPhase16,
     FaceInteriorSupportAndChartIdentityAreRowIndependentAndDiscriminating) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 1};
  const auto *firstAuthority =
      row_identity_source_authority(faces, components, sheets);
  const directional::geometry::SourceChartTransitionGraph firstGraph(
      faces, *firstAuthority, directional::geometry::empty_hard_feature_edges());
  ASSERT_TRUE(firstGraph.available());

  directional::geometry::SurfacePoint firstPoint;
  firstPoint.face = 0;
  firstPoint.component = 0;
  firstPoint.sheet = 0;
  firstPoint.barycentric << 0.2, 0.3, 0.5;
  const auto firstEntityResult = firstGraph.resolve_entity(firstPoint);
  ASSERT_TRUE(firstEntityResult.has_value());
  const auto &firstEntity = firstEntityResult.value();
  ASSERT_TRUE(firstEntity.valid());
  EXPECT_EQ(directional::geometry::SourceEntityKind::FaceInterior,
            firstEntity.kind());
  const auto firstChart = firstGraph.chart(0);
  const auto distinctChart = firstGraph.chart(1);
  ASSERT_TRUE(firstChart.has_value());
  ASSERT_TRUE(distinctChart.has_value());
  EXPECT_NE(firstChart.value(), distinctChart.value());

  const auto firstIdentity =
      directional::geometry::surface_arrangement_detail::
          diagnostic_source_entity_identity(firstEntity);
  ASSERT_TRUE(firstIdentity.valid);

  Eigen::MatrixXi reorderedFaces = faces;
  reorderedFaces.row(0).swap(reorderedFaces.row(1));
  const std::vector<int> reorderedComponents = {0, 0};
  const std::vector<int> reorderedSheets = {1, 0};
  const auto *reorderedAuthority = row_identity_source_authority(
      reorderedFaces, reorderedComponents, reorderedSheets);
  const directional::geometry::SourceChartTransitionGraph reorderedGraph(
      reorderedFaces, *reorderedAuthority,
      directional::geometry::empty_hard_feature_edges());
  ASSERT_TRUE(reorderedGraph.available());

  directional::geometry::SurfacePoint reorderedPoint = firstPoint;
  reorderedPoint.face = 1;
  const auto reorderedEntityResult =
      reorderedGraph.resolve_entity(reorderedPoint);
  ASSERT_TRUE(reorderedEntityResult.has_value());
  const auto &reorderedEntity = reorderedEntityResult.value();
  ASSERT_TRUE(reorderedEntity.valid());
  const auto reorderedChart = reorderedGraph.chart(1);
  ASSERT_TRUE(reorderedChart.has_value());

  EXPECT_EQ(firstChart.value(), reorderedChart.value());
  EXPECT_EQ(firstEntity.support, reorderedEntity.support);
  const auto reorderedIdentity =
      directional::geometry::surface_arrangement_detail::
          diagnostic_source_entity_identity(reorderedEntity);
  ASSERT_TRUE(reorderedIdentity.valid);
  EXPECT_EQ(firstIdentity, reorderedIdentity);

  directional::geometry::SurfacePoint distinctPoint = firstPoint;
  distinctPoint.face = 1;
  distinctPoint.sheet = 1;
  const auto distinctEntityResult = firstGraph.resolve_entity(distinctPoint);
  ASSERT_TRUE(distinctEntityResult.has_value());
  const auto &distinctEntity = distinctEntityResult.value();
  ASSERT_TRUE(distinctEntity.valid());
  EXPECT_EQ(directional::geometry::SourceEntityKind::FaceInterior,
            distinctEntity.kind());
  const auto distinctIdentity =
      directional::geometry::surface_arrangement_detail::
          diagnostic_source_entity_identity(distinctEntity);
  ASSERT_TRUE(distinctIdentity.valid);
  EXPECT_NE(firstEntity.support, distinctEntity.support);
  EXPECT_NE(firstIdentity, distinctIdentity);
}

} // namespace
