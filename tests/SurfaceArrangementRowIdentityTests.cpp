#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
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

// A directed wedge is one rotation about a source edge or vertex fan.
// A trace crossing a shared source edge or vertex must continue into the next
// face; keying the wedge by the witnessing face chart splits it and turns the
// face walk back along the trace.
directional::geometry::SurfaceArrangementArc wedge_test_arc(
    const int id, const int face, const Eigen::RowVector3d &start,
    const Eigen::RowVector3d &end) {
  directional::geometry::SurfaceArrangementArc arc;
  arc.id = id;
  arc.sourceFace = face;
  arc.startBarycentric = start;
  arc.endBarycentric = end;
  arc.family = 0;
  arc.strand = 0;
  arc.provenance = id;
  return arc;
}

void expect_trace_continues_through_shared_node(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<directional::geometry::SurfaceArrangementArc> &arcs,
    const Eigen::RowVector3d &sharedPoint) {
  const std::vector<int> components(static_cast<std::size_t>(faces.rows()), 0);
  const std::vector<int> sheets(static_cast<std::size_t>(faces.rows()), 0);
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceAuthority =
      row_identity_source_authority(faces, components, sheets);
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, arcs, options);

  ASSERT_TRUE(complex.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             complex.diagnostics.incidenceFailure);
  EXPECT_EQ(2, std::count_if(complex.cells.begin(), complex.cells.end(),
                             [](const auto &cell) { return !cell.boundaryCycle; }));
  int sharedNode = -1;
  for (const auto &node : complex.nodes) {
    Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      position += node.barycentric(corner) *
                  vertices.row(faces(node.sourceFace, corner));
    }
    if ((position - sharedPoint).norm() < 1.0e-12) {
      ASSERT_EQ(-1, sharedNode);
      sharedNode = node.id;
    }
  }
  ASSERT_GE(sharedNode, 0);
  int incoming = 0;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.to != sharedNode) {
      continue;
    }
    ++incoming;
    EXPECT_NE(halfedge.twin, halfedge.next) << "halfedge " << halfedge.id;
  }
  EXPECT_EQ(2, incoming);
}

TEST(SurfaceArrangementPhase16,
     TraceCrossingInteriorSourceEdgeSharesOneDirectedEdgeWedge) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           1, 3, 2;
  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      wedge_test_arc(0, 0, Eigen::RowVector3d(0.5, 0.0, 0.5),
                     Eigen::RowVector3d(0.0, 0.5, 0.5)),
      wedge_test_arc(1, 1, Eigen::RowVector3d(0.5, 0.0, 0.5),
                     Eigen::RowVector3d(0.5, 0.5, 0.0))};
  expect_trace_continues_through_shared_node(
      vertices, faces, arcs, Eigen::RowVector3d(0.5, 0.5, 0.0));
}

TEST(SurfaceArrangementPhase16,
     TraceThroughInteriorSourceVertexSharesOneDirectedFanWedge) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      0.5, 0.5, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4,
           1, 2, 4,
           2, 3, 4,
           3, 0, 4;
  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      wedge_test_arc(0, 3, Eigen::RowVector3d(0.5, 0.5, 0.0),
                     Eigen::RowVector3d(0.0, 0.0, 1.0)),
      wedge_test_arc(1, 1, Eigen::RowVector3d(0.0, 0.0, 1.0),
                     Eigen::RowVector3d(0.5, 0.5, 0.0))};
  expect_trace_continues_through_shared_node(
      vertices, faces, arcs, Eigen::RowVector3d(0.5, 0.5, 0.0));
}

} // namespace
