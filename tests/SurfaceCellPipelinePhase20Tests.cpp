#include <algorithm>
#include <cmath>
#include <filesystem>
#include <limits>
#include <numbers>
#include <set>
#include <string>
#include <vector>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#else
#include <unistd.h>
#endif

#include <gtest/gtest.h>

#include <directional/fields/CrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"
#include "TestFixturePaths.h"
#include "TestAuthorityIds.h"

namespace {

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};



const directional::SurfaceCellStageLineage *find_stage_lineage(
    const directional::RemeshDiagnostics &diagnostics,
    const std::string &stage) {
  for (const directional::SurfaceCellStageLineage &lineage :
       diagnostics.surfaceCellStageLineage) {
    if (lineage.stage == stage) {
      return &lineage;
    }
  }
  return nullptr;
}

const directional::pipeline::SurfaceCellContextProductDebug *find_context_product(
    const directional::pipeline::SurfaceCellPipelineContext &context,
    const std::string &name) {
  for (const directional::pipeline::SurfaceCellContextProductDebug &product :
       context.debugProducts) {
    if (product.name == name) {
      return &product;
    }
  }
  return nullptr;
}

void expect_lineage_identities_are_valid(
    const directional::RemeshDiagnostics &diagnostics) {
  ASSERT_FALSE(diagnostics.surfaceCellStageLineage.empty());
  for (std::size_t index = 0; index < diagnostics.surfaceCellStageLineage.size();
       ++index) {
    const directional::SurfaceCellStageLineage &lineage =
        diagnostics.surfaceCellStageLineage[index];
    EXPECT_FALSE(lineage.inputObject.type.empty()) << lineage.stage;
    EXPECT_FALSE(lineage.outputObject.type.empty()) << lineage.stage;
    EXPECT_NE(0U, lineage.inputObject.structuralHash) << lineage.stage;
    EXPECT_NE(0U, lineage.outputObject.structuralHash) << lineage.stage;
    EXPECT_NE(std::string::npos, lineage.inputObjectHash.find("hash="))
        << lineage.stage;
    EXPECT_NE(std::string::npos, lineage.outputObjectHash.find("hash="))
        << lineage.stage;
    if (index + 1U < diagnostics.surfaceCellStageLineage.size()) {
      const directional::SurfaceCellStageLineage &next =
          diagnostics.surfaceCellStageLineage[index + 1U];
      const bool continuity =
          lineage.outputObject.type == next.inputObject.type &&
          lineage.outputObject.structuralHash == next.inputObject.structuralHash;
      if (lineage.stage == "validation" && !continuity) {
        EXPECT_FALSE(lineage.consumedByNextStage) << lineage.stage;
        EXPECT_EQ(directional::SurfaceCellConsumptionKind::None,
                  lineage.consumptionKind)
            << lineage.stage;
        continue;
      }

      EXPECT_EQ(continuity, lineage.consumedByNextStage) << lineage.stage;
      if (lineage.stage == "relief" && continuity) {
        EXPECT_EQ(directional::SurfaceCellConsumptionKind::Partial,
                  lineage.consumptionKind)
            << lineage.stage;
      } else {
        EXPECT_EQ(continuity ? directional::SurfaceCellConsumptionKind::Full
                             : directional::SurfaceCellConsumptionKind::Discontinuous,
                  lineage.consumptionKind)
            << lineage.stage;
      }
    } else {
      EXPECT_FALSE(lineage.consumedByNextStage) << lineage.stage;
      EXPECT_EQ(directional::SurfaceCellConsumptionKind::None,
                lineage.consumptionKind)
          << lineage.stage;
    }
  }
}
SyntheticMesh make_two_square_components() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0, 3.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0, 3.0, 1.0,
      0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
  return mesh;
}


SyntheticMesh make_open_cylinder(const int segments = 24,
                                 const int rings = 3,
                                 const double radius = 2.0,
                                 const double height = 1.0) {
  SyntheticMesh mesh;
  mesh.vertices.resize(segments * rings, 3);
  for (int ring = 0; ring < rings; ++ring) {
    const double z = -0.5 * height +
                     height * static_cast<double>(ring) /
                         static_cast<double>(rings - 1);
    for (int segment = 0; segment < segments; ++segment) {
      const double angle = 2.0 * std::numbers::pi *
                           static_cast<double>(segment) /
                           static_cast<double>(segments);
      mesh.vertices.row(ring * segments + segment) <<
          radius * std::cos(angle), radius * std::sin(angle), z;
    }
  }

  mesh.faces.resize((rings - 1) * segments * 2, 3);
  int face = 0;
  for (int ring = 0; ring < rings - 1; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const int next = (segment + 1) % segments;
      const int a = ring * segments + segment;
      const int b = ring * segments + next;
      const int c = (ring + 1) * segments + segment;
      const int d = (ring + 1) * segments + next;
      mesh.faces.row(face++) << a, b, d;
      mesh.faces.row(face++) << a, d, c;
    }
  }
  return mesh;
}

SyntheticMesh make_two_square_strip() {
  SyntheticMesh mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 0.75, 0.0, 0.0, 1.5, 0.0, 0.0,
      0.0, 0.75, 0.0, 0.75, 0.75, 0.0, 1.5, 0.75, 0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  return mesh;
}

SyntheticMesh make_planar_grid(const int subdivisions = 2) {
  const int n = std::max(1, subdivisions);
  SyntheticMesh mesh;
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

SyntheticMesh make_close_parallel_sheets() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0, 0.0, 0.0, 0.02, 1.0, 0.0, 0.02, 1.0, 1.0,
      0.02, 0.0, 1.0, 0.02;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
  return mesh;
}

SyntheticMesh make_connected_close_opposing_sheets() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
                   1.0, 0.0, 0.0,
                   1.0, 0.0, 0.02,
                   0.0, 0.0, 0.02,
                   0.0, 1.0, 0.0,
                   1.0, 1.0, 0.0,
                   1.0, 1.0, 0.02,
                   0.0, 1.0, 0.02;
  mesh.faces.resize(6, 3);
  mesh.faces << 0, 1, 5,
                0, 5, 4,
                1, 2, 6,
                1, 6, 5,
                2, 3, 7,
                2, 7, 6;
  return mesh;
}

SyntheticMesh make_smooth_hairpin_strip() {
  const std::vector<Eigen::Vector2d> path = {
      {0.0, 0.0},  {0.5, 0.0},   {1.0, 0.0},  {1.02, 0.005},
      {1.035, 0.02}, {1.04, 0.04}, {1.035, 0.06}, {1.02, 0.075},
      {1.0, 0.08}, {0.5, 0.08},  {0.0, 0.08}};
  SyntheticMesh mesh;
  mesh.vertices.resize(static_cast<int>(2 * path.size()), 3);
  for (std::size_t index = 0; index < path.size(); ++index) {
    mesh.vertices(static_cast<int>(index), 0) = path[index].x();
    mesh.vertices(static_cast<int>(index), 1) = 0.0;
    mesh.vertices(static_cast<int>(index), 2) = path[index].y();
    mesh.vertices(static_cast<int>(index + path.size()), 0) = path[index].x();
    mesh.vertices(static_cast<int>(index + path.size()), 1) = 1.0;
    mesh.vertices(static_cast<int>(index + path.size()), 2) = path[index].y();
  }
  mesh.faces.resize(static_cast<int>(2 * (path.size() - 1)), 3);
  int face = 0;
  for (std::size_t column = 0; column + 1 < path.size(); ++column) {
    const int a = static_cast<int>(column);
    const int b = static_cast<int>(column + 1);
    const int c = static_cast<int>(column + path.size());
    const int d = static_cast<int>(column + 1 + path.size());
    mesh.faces.row(face++) << a, b, d;
    mesh.faces.row(face++) << a, d, c;
  }
  return mesh;
}
Eigen::MatrixXd constant_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.block(face, 0, 1, 3) << 1.0, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, 1.0, 0.0;
    raw.block(face, 6, 1, 3) << -1.0, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -1.0, 0.0;
  }
  return raw;
}

directional::fields::CrossFieldResult matching_swap_cross_field(
    const SyntheticMesh &mesh) {
  directional::fields::CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.rawField = constant_raw_field(mesh.faces.rows());
  field.primaryDirections.resize(mesh.faces.rows(), 3);
  field.secondaryDirections.resize(mesh.faces.rows(), 3);
  field.primaryDirections.row(0) << 1.0, 0.0, 0.0;
  field.secondaryDirections.row(0) << 0.0, 1.0, 0.0;
  field.primaryDirections.row(1) << 0.0, 1.0, 0.0;
  field.secondaryDirections.row(1) << -1.0, 0.0, 0.0;
  for (int face = 2; face < mesh.faces.rows(); ++face) {
    field.primaryDirections.row(face) << 1.0, 0.0, 0.0;
    field.secondaryDirections.row(face) << 0.0, 1.0, 0.0;
  }
  field.rawField.block(0, 0, mesh.faces.rows(), 3) = field.primaryDirections;
  field.rawField.block(0, 3, mesh.faces.rows(), 3) = field.secondaryDirections;
  field.rawField.block(0, 6, mesh.faces.rows(), 3) = -field.primaryDirections;
  field.rawField.block(0, 9, mesh.faces.rows(), 3) = -field.secondaryDirections;
  directional::TriMesh sourceMesh;
  sourceMesh.set_mesh(mesh.vertices, mesh.faces);
  field.matching = Eigen::VectorXi::Zero(sourceMesh.EF.rows());
  field.effort = Eigen::VectorXd::Zero(sourceMesh.EF.rows());
  for (int edge = 0; edge < sourceMesh.EF.rows(); ++edge) {
    directional::fields::CrossFieldEdgeTransition transition;
    transition.sourceEdge = edge;
    transition.sourceVertex0 = sourceMesh.EV(edge, 0);
    transition.sourceVertex1 = sourceMesh.EV(edge, 1);
    transition.firstFace = sourceMesh.EF(edge, 0);
    transition.secondFace = sourceMesh.EF(edge, 1);
    transition.matching = sourceMesh.EF(edge, 0) >= 0 &&
                                  sourceMesh.EF(edge, 1) >= 0
                              ? 1
                              : -1;
    transition.effort = sourceMesh.EF(edge, 0) >= 0 &&
                                sourceMesh.EF(edge, 1) >= 0
                            ? 0.25
                            : 0.0;
    field.matching(edge) = transition.matching;
    field.effort(edge) = transition.effort;
    field.edgeTransitions.push_back(transition);
  }
  field.singularCycles.resize(0);
  field.singularIndices.resize(0);
  field.confidence = Eigen::VectorXd::Ones(mesh.faces.rows());
  field.uncoveredFaces.resize(0);
  field.matchingComputed = true;
  field.singularitiesComputed = true;
  field.confidenceComputed = true;
  field.uncoveredFacePolicyApplied = true;
  return field;
}


Eigen::MatrixXd cylinder_raw_field(const SyntheticMesh &mesh) {
  Eigen::MatrixXd raw(mesh.faces.rows(), 12);
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      centroid += mesh.vertices.row(mesh.faces(face, corner)) / 3.0;
    }
    Eigen::RowVector3d circumferential{-centroid.y(), centroid.x(), 0.0};
    if (circumferential.norm() <= 1.0e-12) {
      circumferential = {1.0, 0.0, 0.0};
    } else {
      circumferential.normalize();
    }
    const Eigen::RowVector3d axial{0.0, 0.0, 1.0};
    raw.block(face, 0, 1, 3) = circumferential;
    raw.block(face, 3, 1, 3) = axial;
    raw.block(face, 6, 1, 3) = -circumferential;
    raw.block(face, 9, 1, 3) = -axial;
  }
  return raw;
}
directional::pipeline::RemeshOptions surface_options() {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  // These tests inspect authoritative stage payloads. Production callers keep
  // only scalar diagnostics unless this opt-in is explicitly enabled.
  options.surfaceCells.retainIntermediateGeometry = true;
  // Recovery is non-authoritative and default-off. Tests that intentionally
  // exercise it opt in through this legacy production-fixture helper.
  options.surfaceCells.allowSourceGridRecovery = true;
  // SurfaceCells honors the public target-length ratio when no explicit
  // adaptive base size is supplied. Keep the synthetic production fixtures
  // at the same coarse resolution used by the Milestone G matrix.
  options.lengthRatio = 0.2;
  return options;
}

std::string signature(const directional::pipeline::RemeshResult &result) {
  return result.diagnostics.requestedBackend + "/" +
         result.diagnostics.executedBackend + "/" +
         result.diagnostics.terminalFailureCode + "/" +
         std::to_string(result.product().vertices.rows()) + "/" +
         std::to_string(result.product().faces.rows()) + "/" +
         std::to_string(result.product().degrees.sum());
}

std::string patch_descriptor_summary(
    const directional::pipeline::RemeshResult &result) {
  std::string summary;
  for (const auto &descriptor : result.surfaceCellContext.patchDescriptors) {
    if (!summary.empty()) {
      summary += ",";
    }
    summary += std::to_string(descriptor.cellId) + ":" +
               std::to_string(descriptor.sides.size()) + ":" +
               std::to_string(static_cast<int>(
                   descriptor.feasibility.reason));
  }
  return summary;
}

directional::geometry::AdaptiveFeatureMap minimal_feature_map() {
  directional::geometry::AdaptiveFeatureMap map;
  directional::geometry::AdaptiveFeatureEdge edge;
  edge.vertices = {0, 1};
  edge.incidentFaces = {0, 1};
  edge.component = 0;
  edge.curve = 7;
  edge.angleRadians = 0.25;
  edge.strength = 0.75;
  edge.ridgeValleyConfidence = 0.5;
  edge.length = 1.0;
  edge.edgeClass = directional::geometry::AdaptiveFeatureClass::Soft;
  map.edges.push_back(edge);
  map.edgeIndex[{0, 1}] = 0;
  map.vertexDensity = Eigen::VectorXd::Constant(2, 1.0);
  return map;
}

directional::geometry::SurfaceCellNetwork minimal_trace_network() {
  directional::geometry::SurfaceCellNetwork network;
  directional::geometry::SurfaceTraceResult trace;
  directional::geometry::SurfaceTraceSegment segment;
  segment.face = 0;
  segment.startBarycentric = Eigen::RowVector3d(0.8, 0.1, 0.1);
  segment.endBarycentric = Eigen::RowVector3d(0.1, 0.8, 0.1);
  segment.family = 2;
  segment.sign = -1;
  segment.entryEdge = 0;
  segment.exitEdge = 1;
  segment.matching = 3;
  segment.matchingEffort = 0.125;
  trace.segments.push_back(segment);
  trace.termination = directional::geometry::TraceTerminationReason::Boundary;
  trace.length = 1.0;
  network.traces.push_back(trace);
  network.stats.attempted = 1;
  return network;
}

directional::geometry::SurfaceCellComplex minimal_surface_complex() {
  directional::geometry::SurfaceCellComplex complex;
  for (int index = 0; index < 4; ++index) {
    directional::geometry::SurfaceArrangementNode node;
    node.id = index;
    node.sourceFace = 0;
    node.barycentric = Eigen::RowVector3d(
        index == 0 ? 1.0 : 0.0, index == 1 ? 1.0 : 0.0,
        index >= 2 ? 1.0 : 0.0);
    node.sourceEdge = index % 3;
    node.sourceEdgeParameter = 0.25 * index;
    complex.nodes.push_back(node);

    directional::geometry::SurfaceArrangementHalfedge halfedge;
    halfedge.id = index;
    halfedge.next = (index + 1) % 4;
    halfedge.from = index;
    halfedge.to = (index + 1) % 4;
    halfedge.sourceArc = index;
    halfedge.family = index % 2;
    halfedge.strand = index;
    halfedge.sourceFace = 0;
    halfedge.cell = 0;
    complex.halfedges.push_back(halfedge);
  }
  directional::geometry::SurfaceArrangementCell cell;
  cell.id = 0;
  cell.sourceFace = 0;
  cell.halfedges = {0, 1, 2, 3};
  cell.sideFamilies = {0, 1, 0, 1};
  cell.sideEdgeCounts = {1, 1, 1, 1};
  cell.area = 1.0;
  cell.signedArea = 1.0;
  cell.boundaryCycle = true;
  cell.disk = true;
  cell.quadReady = true;
  cell.cellClass = directional::geometry::SurfaceArrangementCellClass::RegularQuad;
  complex.cells.push_back(cell);
  return complex;
}

directional::geometry::PureQuadMesh minimal_completion_mesh() {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2, 3};
  mesh.vertexPositions.resize(4, 3);
  mesh.vertexPositions << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
      1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  mesh.quads.push_back({0, 1, 2, 3});
  mesh.boundaryVertices = mesh.vertices;
  for (int vertex = 0; vertex < 4; ++vertex) {
    directional::geometry::SurfacePoint point;
    point.face = 0;
    point.component = 0;
    point.sheet = 0;
    point.barycentric = Eigen::RowVector3d(vertex == 0 ? 1.0 : 0.0,
                                           vertex == 1 ? 1.0 : 0.0,
                                           vertex >= 2 ? 1.0 : 0.0);
    point.position = mesh.vertexPositions.row(vertex).transpose();
    mesh.vertexProvenance.push_back(point);
  }
  return mesh;
}

} // namespace

TEST(SurfaceCellPipelinePhase20, FeatureHashChangesWhenClassificationChangesWithoutCount) {
  directional::geometry::AdaptiveFeatureMap first = minimal_feature_map();
  directional::geometry::AdaptiveFeatureMap second = first;
  second.edges[0].edgeClass = directional::geometry::AdaptiveFeatureClass::Hard;

  EXPECT_NE(directional::pipeline::hash_feature_map(first),
            directional::pipeline::hash_feature_map(second));
}

TEST(SurfaceCellPipelinePhase20, FeatureHashIsStableUnderEdgeIndexInsertionOrder) {
  directional::geometry::AdaptiveFeatureMap first = minimal_feature_map();
  first.edgeIndex[{2, 3}] = 1;
  directional::geometry::AdaptiveFeatureMap second = first;
  second.edgeIndex.clear();
  second.edgeIndex[{2, 3}] = 1;
  second.edgeIndex[{0, 1}] = 0;

  EXPECT_EQ(directional::pipeline::hash_feature_map(first),
            directional::pipeline::hash_feature_map(second));
}

TEST(SurfaceCellPipelinePhase20, TraceHashChangesWhenPointMovesWithoutSegmentCount) {
  directional::geometry::SurfaceCellNetwork first = minimal_trace_network();
  directional::geometry::SurfaceCellNetwork second = first;
  second.traces[0].segments[0].endBarycentric =
      Eigen::RowVector3d(0.2, 0.7, 0.1);

  EXPECT_NE(directional::pipeline::hash_trace_network(first),
            directional::pipeline::hash_trace_network(second));
}


TEST(SurfaceCellPipelinePhase20, FeatureRailsRetainOrderedIntervalsAcrossSourceTriangles) {
  const SyntheticMesh mesh = make_two_square_strip();
  directional::TriMesh meshWhole;
  meshWhole.set_mesh(mesh.vertices, mesh.faces);

  directional::geometry::AdaptiveFeatureMap map;
  const auto add_edge = [&](const int a, const int b,
                            const std::vector<int> &faces,
                            const int curve) {
    directional::geometry::AdaptiveFeatureEdge edge;
    edge.vertices = {a, b};
    edge.incidentFaces = faces;
    edge.component = 0;
    edge.curve = curve;
    edge.edgeClass = directional::geometry::AdaptiveFeatureClass::Hard;
    const int id = static_cast<int>(map.edges.size());
    map.edgeIndex[directional::geometry::AdaptiveFeatureMap::canonical_edge(a, b)] = id;
    map.edges.push_back(edge);
    return id;
  };

  directional::geometry::AdaptiveFeatureCurve curve;
  curve.id = 21;
  curve.component = 0;
  curve.closed = false;
  curve.vertices = {0, 1, 2, 5};
  curve.edges = {add_edge(0, 1, {0}, curve.id),
                 add_edge(1, 2, {2}, curve.id),
                 add_edge(2, 5, {2}, curve.id)};
  map.curves.push_back(curve);
  map.vertexDensity = Eigen::VectorXd::Ones(mesh.vertices.rows());

  const auto railBuild =
      directional::pipeline::build_authoritative_surface_cell_rails(meshWhole, map);
  ASSERT_TRUE(railBuild.is_produced());
  const std::vector<directional::geometry::SurfaceCellRail> &rails =
      railBuild.product().rails;

  ASSERT_EQ(1U, rails.size());
  const directional::geometry::SurfaceCellRail &rail = rails.front();
  EXPECT_EQ(directional::geometry::SurfaceCellRailKind::HardFeature, rail.kind);
  EXPECT_EQ(21, rail.curveId);
  EXPECT_EQ(std::vector<int>({0, 1, 2, 5}), rail.sourceVertices);
  ASSERT_EQ(6U, rail.samples.size());
  EXPECT_EQ(0, rail.samples[0].sourceFace);
  EXPECT_EQ(2, rail.samples[2].sourceFace);
  EXPECT_DOUBLE_EQ(0.0, rail.samples[0].railParameter);
  EXPECT_DOUBLE_EQ(1.0 / 3.0, rail.samples[1].railParameter);
  EXPECT_DOUBLE_EQ(1.0 / 3.0, rail.samples[2].railParameter);
  EXPECT_DOUBLE_EQ(2.0 / 3.0, rail.samples[3].railParameter);
  EXPECT_DOUBLE_EQ(2.0 / 3.0, rail.samples[4].railParameter);
  EXPECT_DOUBLE_EQ(1.0, rail.samples[5].railParameter);
  EXPECT_NE(rail.samples[0].sourceFace, rail.samples[2].sourceFace);
}

TEST(SurfaceCellPipelinePhase20,
     AuthoritativeRailAssemblyFailsWhenAnEdgeHasNoIncidentFace) {
  const SyntheticMesh mesh = make_two_square_strip();
  directional::TriMesh meshWhole;
  meshWhole.set_mesh(mesh.vertices, mesh.faces);
  directional::geometry::AdaptiveFeatureMap map;
  directional::geometry::AdaptiveFeatureEdge edge;
  edge.vertices = {0, 1};
  edge.incidentFaces = {-1};
  edge.edgeClass = directional::geometry::AdaptiveFeatureClass::Hard;
  edge.component = 0;
  edge.curve = 41;
  map.edges.push_back(edge);
  directional::geometry::AdaptiveFeatureCurve curve;
  curve.id = 41;
  curve.edges = {0};
  curve.vertices = {0, 1};
  curve.closed = false;
  map.curves.push_back(curve);

  const auto result =
      directional::pipeline::build_authoritative_surface_cell_rails(meshWhole, map);
  ASSERT_TRUE(result.is_rejected());
  ASSERT_NE(result.rejection(), nullptr);
  EXPECT_EQ(result.rejection()->failedEdgeIndex, 0);
  EXPECT_EQ(result.rejection()->kind,
            directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge);
}

TEST(SurfaceCellPipelinePhase20,
     TraceHashIncludesRailProvenanceAndRejectionSemantics) {
  const directional::geometry::SurfaceCellNetwork baseline =
      minimal_trace_network();
  const auto hash = [&](const auto &mutate) {
    auto candidate = baseline;
    mutate(candidate);
    return directional::pipeline::hash_trace_network(candidate);
  };

  EXPECT_NE(hash([](auto &network) {
                network.traces[0].segments[0].railSideSign = 1;
              }),
            hash([](auto &network) {
                network.traces[0].segments[0].railSideSign = -1;
              }));
  EXPECT_NE(hash([](auto &network) {
                network.traces[0].segments[0].railId = directional::tests::test_hard_rail_id(7);
              }),
            hash([](auto &network) {
                network.traces[0].segments[0].railId = directional::tests::test_hard_rail_id(8);
              }));
  EXPECT_NE(hash([](auto &network) {
                network.traces[0].segments[0].railT1 = 0.25;
              }),
            hash([](auto &network) {
                network.traces[0].segments[0].railT1 = 0.75;
              }));
  EXPECT_NE(hash([](auto &network) {
                network.stats.rejectedSourceSheet = 1;
              }),
            hash([](auto &network) {
                network.stats.rejectedFieldMetadata = 1;
              }));
}

TEST(SurfaceCellPipelinePhase20, ArrangementArcHashChangesWhenRailIdentityChangesWithoutGeometry) {
  std::vector<directional::geometry::SurfaceArrangementArc> first(1);
  first[0].id = 7;
  first[0].sourceFace = 3;
  first[0].startBarycentric = Eigen::RowVector3d(0.8, 0.1, 0.1);
  first[0].endBarycentric = Eigen::RowVector3d(0.1, 0.8, 0.1);
  first[0].family = -1;
  first[0].strand = 11;
  first[0].featureClass = 3;
  first[0].hardFeature = true;
  first[0].provenance = 5;
  first[0].railId = directional::tests::test_hard_rail_id(4);
  first[0].curveId = 21;
  first[0].sourceComponent = 2;
  first[0].railT0 = 0.25;
  first[0].railT1 = 0.5;

  std::vector<directional::geometry::SurfaceArrangementArc> second = first;
  second[0].curveId = 22;

  EXPECT_EQ(first[0].startBarycentric, second[0].startBarycentric);
  EXPECT_EQ(first[0].endBarycentric, second[0].endBarycentric);
  EXPECT_NE(directional::pipeline::hash_arrangement_arcs(first),
            directional::pipeline::hash_arrangement_arcs(second));
}
TEST(SurfaceCellPipelinePhase20, ArrangementArcHashChangesWhenGeometryChangesWithoutSparseIds) {
  std::vector<directional::geometry::SurfaceArrangementArc> first(1);
  first[0].id = 7;
  first[0].sourceFace = 3;
  first[0].startBarycentric = Eigen::RowVector3d(0.8, 0.1, 0.1);
  first[0].endBarycentric = Eigen::RowVector3d(0.1, 0.8, 0.1);
  first[0].family = 2;
  first[0].strand = 11;
  first[0].featureClass = 4;
  first[0].hardFeature = true;
  first[0].provenance = 5;

  std::vector<directional::geometry::SurfaceArrangementArc> second = first;
  second[0].endBarycentric = Eigen::RowVector3d(0.2, 0.7, 0.1);

  EXPECT_EQ(first.size(), second.size());
  EXPECT_EQ(first[0].id, second[0].id);
  EXPECT_EQ(first[0].strand, second[0].strand);
  EXPECT_NE(directional::pipeline::hash_arrangement_arcs(first),
            directional::pipeline::hash_arrangement_arcs(second));
}
TEST(SurfaceCellPipelinePhase20, EmbeddingProducerOutputHashChangesWhenRetainedArcGeometryChanges) {
  std::vector<directional::geometry::SurfaceArrangementArc> first(1);
  first[0].id = 7;
  first[0].sourceFace = 3;
  first[0].startBarycentric = Eigen::RowVector3d(0.8, 0.1, 0.1);
  first[0].endBarycentric = Eigen::RowVector3d(0.1, 0.8, 0.1);
  first[0].family = 2;
  first[0].strand = 11;
  first[0].featureClass = 4;
  first[0].hardFeature = true;
  first[0].provenance = 5;

  std::vector<directional::geometry::SurfaceArrangementArc> second = first;
  second[0].startBarycentric = Eigen::RowVector3d(0.7, 0.2, 0.1);

  const directional::SurfaceCellObjectIdentity firstOutput =
      directional::pipeline::make_surface_cell_identity(
          "embedded-network", directional::pipeline::hash_arrangement_arcs(first),
          first.size());
  const directional::SurfaceCellObjectIdentity secondOutput =
      directional::pipeline::make_surface_cell_identity(
          "embedded-network", directional::pipeline::hash_arrangement_arcs(second),
          second.size());

  EXPECT_EQ(firstOutput.type, secondOutput.type);
  EXPECT_EQ(firstOutput.elementCount, secondOutput.elementCount);
  EXPECT_NE(firstOutput.structuralHash, secondOutput.structuralHash);
}
TEST(SurfaceCellPipelinePhase20, ArrangementHashChangesWhenConnectivityChangesWithoutCounts) {
  directional::geometry::SurfaceCellComplex first = minimal_surface_complex();
  directional::geometry::SurfaceCellComplex second = first;
  second.halfedges[0].next = 2;

  EXPECT_NE(directional::pipeline::hash_surface_complex(first),
            directional::pipeline::hash_surface_complex(second));
}

TEST(SurfaceCellPipelinePhase20, SimplificationSameCountTopologyMutationIsNotNoOp) {
  directional::geometry::SurfaceCellComplex first = minimal_surface_complex();
  directional::geometry::SurfaceCellComplex second = first;
  second.cells[0].halfedges = {0, 2, 1, 3};

  const directional::SurfaceCellObjectIdentity input =
      directional::pipeline::make_surface_cell_identity(
          "arrangement", directional::pipeline::hash_surface_complex(first),
          first.cells.size());
  const directional::SurfaceCellObjectIdentity output =
      directional::pipeline::make_surface_cell_identity(
          "arrangement", directional::pipeline::hash_surface_complex(second),
          second.cells.size());

  EXPECT_EQ(input.elementCount, output.elementCount);
  EXPECT_NE(input.structuralHash, output.structuralHash);
}

TEST(SurfaceCellPipelinePhase20, CompletionHashChangesWhenProvenanceChangesWithoutCount) {
  directional::geometry::PureQuadMesh first = minimal_completion_mesh();
  directional::geometry::PureQuadMesh second = first;
  second.vertexProvenance[0].face = 3;
  second.vertexProvenance[0].barycentric = Eigen::RowVector3d(0.8, 0.1, 0.1);

  EXPECT_NE(directional::pipeline::hash_completion(first),
            directional::pipeline::hash_completion(second));
}
TEST(SurfaceCellPipelinePhase20,
     ProductionDefaultReleasesConsumedIntermediateGeometry) {
  const SyntheticMesh mesh = make_planar_grid(1);
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.retainIntermediateGeometry = false;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces,
          constant_raw_field(mesh.faces.rows()), options);

  ASSERT_TRUE(result.is_produced()) << result.diagnostics.terminalFailureCode << "/"
                              << result.diagnostics.terminalFailureStage;
  EXPECT_FALSE(result.surfaceCellContext.hasTraceNetwork);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.traceNetwork.traces.empty());
  EXPECT_FALSE(result.surfaceCellContext.hasFlowRepNetwork);
  EXPECT_FALSE(result.surfaceCellContext.hasEmbeddedArrangementArcs);
  EXPECT_FALSE(result.surfaceCellContext.hasArrangement);
  EXPECT_FALSE(result.surfaceCellContext.hasSimplifiedComplex);
  EXPECT_FALSE(result.surfaceCellContext.hasCompletionComplex);
  EXPECT_FALSE(result.surfaceCellContext.hasPatchDescriptors);
  EXPECT_TRUE(result.diagnostics.surfaceCellTraceCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellArrangementCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellSimplifiedCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellCompletedQuadCountAvailable);
}

TEST(SurfaceCellPipelinePhase20, BackendNamesAndParsersExposeStableApi) {
  using directional::pipeline::RemeshBackend;
  using directional::pipeline::SurfaceCellFallbackPolicy;

  directional::pipeline::RemeshOptions defaults;
  EXPECT_EQ(RemeshBackend::LegacyInteger, defaults.backend);
  EXPECT_EQ("LegacyInteger",
            directional::pipeline::remesh_backend_name(defaults.backend));
  EXPECT_EQ(RemeshBackend::LegacyInteger,
            directional::pipeline::parse_remesh_backend("legacy-integer"));
  EXPECT_EQ(RemeshBackend::SurfaceCells,
            directional::pipeline::parse_remesh_backend("surface_cells"));
  EXPECT_EQ(SurfaceCellFallbackPolicy::ReturnInputMesh,
            directional::pipeline::parse_surface_cell_fallback_policy(
                "return-input-mesh"));
  EXPECT_EQ("ReturnInputMesh",
            directional::pipeline::surface_cell_fallback_policy_name(
                SurfaceCellFallbackPolicy::ReturnInputMesh));
  EXPECT_THROW((void)directional::pipeline::parse_remesh_backend("unknown"),
               std::runtime_error);
}

TEST(SurfaceCellPipelinePhase20, FlowRepFailuresMapToPrecisePipelineCodes) {
  using directional::geometry::FlowRepSelectionFailureCode;
  using directional::pipeline::SurfaceCellFailureCode;
  const std::vector<std::pair<FlowRepSelectionFailureCode,
                              SurfaceCellFailureCode>> cases = {
      {FlowRepSelectionFailureCode::EmptyNetwork,
       SurfaceCellFailureCode::EmptyFlowRepNetwork},
      {FlowRepSelectionFailureCode::MissingCoverageEvidence,
       SurfaceCellFailureCode::MissingFlowRepCoverageEvidence},
      {FlowRepSelectionFailureCode::MissingCycleEvidence,
       SurfaceCellFailureCode::MissingFlowRepCycleEvidence},
      {FlowRepSelectionFailureCode::InvalidCoverageEvidence,
       SurfaceCellFailureCode::InvalidFlowRepCoverageEvidence},
      {FlowRepSelectionFailureCode::InvalidCycleEvidence,
       SurfaceCellFailureCode::InvalidFlowRepCycleEvidence},
      {FlowRepSelectionFailureCode::InvalidArcIdentity,
       SurfaceCellFailureCode::InvalidFlowRepArcIdentity},
      {FlowRepSelectionFailureCode::IncompleteArcProvenance,
       SurfaceCellFailureCode::IncompleteFlowRepProvenance},
      {FlowRepSelectionFailureCode::IncompleteCycleCoverage,
       SurfaceCellFailureCode::IncompleteFlowRepCycleCoverage},
      {FlowRepSelectionFailureCode::MandatoryRailLoss,
       SurfaceCellFailureCode::FlowRepMandatoryRailLoss},
  };
  for (const auto &[flowRepCode, pipelineCode] : cases) {
    EXPECT_EQ(pipelineCode,
              directional::pipeline::surface_cell_failure_from_flow_rep(
                  flowRepCode));
  }
}

TEST(SurfaceCellPipelinePhase20, InvalidRawFieldDimsReturnPreciseFailureCode) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd badRaw(mesh.faces.rows(), 9);
  badRaw.setZero();
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, badRaw, surface_options());

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("SurfaceCells", result.diagnostics.remeshBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.terminalFailureCode);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);
  EXPECT_EQ("cross-field-validation",
            result.diagnostics.originalSurfaceCellFailureStage);
}

TEST(SurfaceCellPipelinePhase20, InvalidRawFieldValuesFailClosedBeforeFinalization) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  raw(0, 0) = std::numeric_limits<double>::quiet_NaN();
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());
  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InvalidFieldDimensions", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);

  raw = constant_raw_field(mesh.faces.rows());
  raw.block(1, 3, 1, 3).setZero();
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, surface_options());
  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InvalidFieldDimensions", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);
}

TEST(SurfaceCellPipelinePhase20, CrossFieldResultRequiresMatchingAndSingularities) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::fields::CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.rawField = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingMatching", result.diagnostics.terminalFailureCode);

  field.matching = Eigen::VectorXi::Zero(1);
  field.effort = Eigen::VectorXd::Zero(1);
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingMatching", result.diagnostics.terminalFailureCode);

  field = matching_swap_cross_field(mesh);
  field.singularitiesComputed = false;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingSingularities", result.diagnostics.terminalFailureCode);

  field.singularitiesComputed = true;
  field.confidence.resize(0);
  field.confidenceComputed = false;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingConfidence", result.diagnostics.terminalFailureCode);

  field.confidence = Eigen::VectorXd::Ones(mesh.faces.rows());
  field.confidenceComputed = true;
  field.uncoveredFacePolicyApplied = false;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("UncoveredFaces", result.diagnostics.terminalFailureCode);

  field.uncoveredFaces.resize(0);
  field.uncoveredFacePolicyApplied = true;
  directional::TriMesh meshWhole;
  meshWhole.set_mesh(mesh.vertices, mesh.faces);
  field = directional::pipeline::finalize_surface_cell_raw_cross_field(
      meshWhole, constant_raw_field(mesh.faces.rows()));
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_TRUE(result.is_produced());
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_TRUE(result.surfaceCellContext.productSnapshots.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasMatching);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasSingularities);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.crossField.confidenceComputed);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.crossField.uncoveredFacePolicyApplied);
  EXPECT_EQ(field.matching.size(),
            result.surfaceCellContext.productSnapshots.crossField.matching.size());
  EXPECT_EQ(field.rawField.rows(),
            result.surfaceCellContext.productSnapshots.crossField.rawField.rows());
  EXPECT_NE(nullptr, find_context_product(result.surfaceCellContext,
                                          "cross-field"));
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const directional::geometry::SurfaceCellNetwork &traceNetwork =
      result.surfaceCellContext.productSnapshots.traceNetwork;
  ASSERT_EQ(mesh.faces.rows(), traceNetwork.sourceFaceComponents.size());
  ASSERT_EQ(mesh.faces.rows(), traceNetwork.sourceFaceSheets.size());
  EXPECT_EQ(0, traceNetwork.sourceFaceComponents[0]);
  EXPECT_EQ(0, traceNetwork.sourceFaceComponents[1]);
  EXPECT_EQ(1, traceNetwork.sourceFaceComponents[2]);
  EXPECT_EQ(1, traceNetwork.sourceFaceComponents[3]);
  EXPECT_EQ(traceNetwork.sourceFaceComponents, traceNetwork.sourceFaceSheets);
  for (const directional::geometry::SurfaceTraceResult &trace :
       traceNetwork.traces) {
    EXPECT_TRUE(
        directional::geometry::surface_cell_tracing_detail::
            trace_respects_source_component(
                trace, traceNetwork.sourceFaceComponents));
  }
  for (const directional::geometry::SurfaceCellProposal &proposal :
       traceNetwork.proposals) {
    directional::geometry::SurfaceTraceResult sideTrace;
    sideTrace.segments = proposal.sides;
    EXPECT_TRUE(
        directional::geometry::surface_cell_tracing_detail::
            trace_respects_source_component(
                sideTrace, traceNetwork.sourceFaceComponents));
  }
  EXPECT_STREQ("SourceGridRecovery",
               surface_cell_output_origin_name(
                   result.diagnostics.surfaceCellOutputOrigin));
  if (result.diagnostics.surfaceCellRemeshOccurred) {
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::SourceGridRecovery,
              result.diagnostics.surfaceCellOutputOrigin);
  }
}

TEST(SurfaceCellPipelinePhase20, CrossFieldResultRequiresEdgeTransitionRecords) {
  const SyntheticMesh mesh = make_planar_grid(1);
  directional::fields::CrossFieldResult field = matching_swap_cross_field(mesh);
  field.edgeTransitions.clear();

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, field, surface_options());

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("MissingMatching", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
}

TEST(SurfaceCellPipelinePhase20, RawAndFinalizedFieldInputsHaveEquivalentMetadata) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::TriMesh meshWhole;
  meshWhole.set_mesh(mesh.vertices, mesh.faces);
  const directional::fields::CrossFieldResult finalized =
      directional::pipeline::finalize_surface_cell_raw_cross_field(meshWhole, raw);

  const directional::pipeline::RemeshOptions options = surface_options();
  const directional::pipeline::RemeshResult rawResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  const directional::pipeline::RemeshResult finalizedResult =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, finalized, options);

  ASSERT_TRUE(rawResult.surfaceCellContext.productSnapshots.hasCrossField);
  ASSERT_TRUE(finalizedResult.surfaceCellContext.productSnapshots.hasCrossField);
  EXPECT_TRUE(rawResult.surfaceCellContext.productSnapshots.crossField.matchingComputed);
  EXPECT_TRUE(rawResult.surfaceCellContext.productSnapshots.crossField.singularitiesComputed);
  EXPECT_TRUE(rawResult.surfaceCellContext.productSnapshots.crossField.confidenceComputed);
  EXPECT_TRUE(rawResult.surfaceCellContext.productSnapshots.crossField.uncoveredFacePolicyApplied);
  EXPECT_EQ(finalized.matching.size(),
            rawResult.surfaceCellContext.productSnapshots.crossField.matching.size());
  EXPECT_EQ(finalized.effort.size(),
            rawResult.surfaceCellContext.productSnapshots.crossField.effort.size());
  EXPECT_EQ(finalized.singularCycles.size(),
            rawResult.surfaceCellContext.productSnapshots.crossField.singularCycles.size());
  EXPECT_EQ(finalized.singularIndices.size(),
            rawResult.surfaceCellContext.productSnapshots.crossField.singularIndices.size());
  EXPECT_EQ(0, rawResult.surfaceCellContext.productSnapshots.crossField.uncoveredFaces.size());
  EXPECT_EQ(rawResult.surfaceCellContext.productSnapshots.crossField.matching.size(),
            finalizedResult.surfaceCellContext.productSnapshots.crossField.matching.size());
  EXPECT_EQ(rawResult.surfaceCellContext.productSnapshots.crossField.singularitiesComputed,
            finalizedResult.surfaceCellContext.productSnapshots.crossField.singularitiesComputed);
}

TEST(SurfaceCellPipelinePhase20, UncoveredRawFieldFacesFailBeforeTracing) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  raw.row(0).setZero();

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InvalidFieldDimensions", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_FALSE(result.surfaceCellContext.productSnapshots.hasCrossField);
  EXPECT_EQ(nullptr, find_stage_lineage(result.diagnostics, "tracing"));
}

TEST(SurfaceCellPipelinePhase20, ExplicitFallbackPoliciesAreObservable) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 9;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  EXPECT_FALSE(result.is_produced());
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);

  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnInputMesh;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.is_produced()) << "relief=" << result.diagnostics.surfaceCellReliefPatchCount << " trace=" << result.diagnostics.surfaceCellTraceSegmentCount << " arrangement=" << result.diagnostics.surfaceCellArrangementCellCount << " simplified=" << result.diagnostics.surfaceCellSimplifiedCellCount << " completed=" << result.diagnostics.surfaceCellCompletedQuadCount << " opt=" << result.diagnostics.surfaceCellOptimizationIterationCount << " terminal=" << result.diagnostics.terminalFailureCode << ":" << result.diagnostics.terminalFailureStage;
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellReturnedInputMeshFallback);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_STREQ("InputMeshFallback", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("InputMesh", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.surfaceCellFallbackCause);
  ASSERT_GT(result.diagnostics.faceDegreeHistogram.size(), 3U);
  EXPECT_EQ(static_cast<std::size_t>(mesh.faces.rows()),
            result.diagnostics.faceDegreeHistogram[3]);
}

TEST(SurfaceCellPipelinePhase20, DebugArtifactsAreRetainedOnlyWhenRequested) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 0;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_FALSE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifacts.empty());

  options.surfaceCells.preserveDebugArtifacts = true;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  ASSERT_EQ(1U, result.diagnostics.surfaceCellDebugArtifacts.size());
  EXPECT_EQ("feature", result.diagnostics.surfaceCellDebugArtifacts[0]);

  options.surfaceCells.injectFailureAfterStage = 1;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  ASSERT_EQ(2U, result.diagnostics.surfaceCellDebugArtifacts.size());
  EXPECT_EQ("feature", result.diagnostics.surfaceCellDebugArtifacts[0]);
  EXPECT_EQ("metric", result.diagnostics.surfaceCellDebugArtifacts[1]);
}


TEST(SurfaceCellPipelinePhase20, RealStageDiagnosticsAreDerivedFromIntermediates) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_TRUE(result.is_produced());
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_TRUE(result.surfaceCellContext.productSnapshots.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasMatching);
  EXPECT_EQ(result.product().crossFieldMatching.size(),
            result.surfaceCellContext.productSnapshots.crossField.matching.size());
  EXPECT_EQ(raw.rows(),
            result.surfaceCellContext.productSnapshots.crossField.rawField.rows());
  EXPECT_NE(nullptr, find_context_product(result.surfaceCellContext,
                                          "cross-field"));
  EXPECT_STREQ("SourceGridRecovery",
               surface_cell_output_origin_name(
                   result.diagnostics.surfaceCellOutputOrigin));
  if (result.diagnostics.surfaceCellRemeshOccurred) {
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::SourceGridRecovery,
              result.diagnostics.surfaceCellOutputOrigin);
  }
  EXPECT_TRUE(result.diagnostics.overallPipelineTimeAvailable);
  EXPECT_GE(result.diagnostics.overallPipelineSeconds, 0.0);
  EXPECT_TRUE(result.diagnostics.surfaceCellFeatureCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellMetricSampleCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellProvenanceVertexCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellValidationFailureCountAvailable);
  EXPECT_EQ(static_cast<std::size_t>(mesh.vertices.rows()),
            result.diagnostics.surfaceCellMetricSampleCount);
  EXPECT_NE(static_cast<std::size_t>(mesh.faces.rows()),
            result.diagnostics.surfaceCellFeatureCount);
  EXPECT_EQ(result.product().outputVertexProvenance.size(),
            result.diagnostics.surfaceCellProvenanceVertexCount);
  EXPECT_EQ(0U, result.diagnostics.surfaceCellValidationFailures);
  EXPECT_TRUE(result.diagnostics.surfaceCellReliefCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellTraceCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellArrangementCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellSimplifiedCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellCompletedQuadCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellOptimizationIterationCountAvailable);
  EXPECT_GT(result.diagnostics.surfaceCellReliefPatchCount, 0U);
  EXPECT_GT(result.diagnostics.surfaceCellTraceSegmentCount, 0U);
  EXPECT_EQ(static_cast<std::size_t>(result.product().faces.rows()),
            result.diagnostics.surfaceCellCompletedQuadCount);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  EXPECT_TRUE(context.hasSourceMesh);
  EXPECT_TRUE(context.productSnapshots.hasCrossField);
  EXPECT_TRUE(context.hasFeatureMap);
  EXPECT_TRUE(context.productSnapshots.hasAuthoritativeRails);
  EXPECT_TRUE(context.hasMetricField);
  EXPECT_TRUE(context.hasReliefResult);
  EXPECT_TRUE(context.hasTraceNetwork);
  EXPECT_TRUE(context.hasFlowRepNetwork);
  EXPECT_TRUE(context.productSnapshots.flowRepNetwork.selectionSucceeded);
  EXPECT_TRUE(context.productSnapshots.flowRepNetwork.coverageEvidenceUsed);
  EXPECT_TRUE(context.productSnapshots.flowRepNetwork.cycleEvidenceUsed);
  EXPECT_GT(context.productSnapshots.flowRepNetwork.coverageSampleCount, 0);
  EXPECT_GT(context.productSnapshots.flowRepNetwork.cycleEvidenceCount, 0);
  EXPECT_EQ(context.productSnapshots.flowRepNetwork.mandatoryRails,
            context.productSnapshots.flowRepNetwork.retainedMandatoryRails);
  EXPECT_TRUE(context.hasEmbeddedArrangementArcs);
  EXPECT_TRUE(context.hasArrangement);
  EXPECT_TRUE(context.hasSimplifiedComplex);
  EXPECT_TRUE(context.hasCompletedPatches);
  EXPECT_TRUE(context.productSnapshots.hasOptimizationResult);
  EXPECT_TRUE(context.productSnapshots.hasValidationResult);
  EXPECT_TRUE(context.productSnapshots.validationResult.authoritativeBoundaryUsed);
  EXPECT_TRUE(context.productSnapshots.validationResult.authoritativeFeatureRailsUsed);
  EXPECT_GE(result.diagnostics.surfaceCellOptimizationSeconds, 0.0);
  EXPECT_GE(result.diagnostics.surfaceCellValidationSeconds, 0.0);
  EXPECT_LE(result.diagnostics.surfaceCellOptimizationSeconds +
                result.diagnostics.surfaceCellValidationSeconds,
            result.diagnostics.overallPipelineSeconds + 1.0e-6);
  EXPECT_EQ(context.productSnapshots.validationResult.optimizerTimeWithinGate,
            result.diagnostics.surfaceCellOptimizationSeconds <=
                0.25 * result.diagnostics.overallPipelineSeconds + 1.0e-6);
  EXPECT_EQ(mesh.faces.rows(), context.sourceMesh.F.rows());
  EXPECT_EQ(result.diagnostics.surfaceCellFeatureCount,
            context.featureMap.edges.size());
  EXPECT_EQ(result.diagnostics.surfaceCellTraceSegmentCount > 0,
            !context.productSnapshots.traceNetwork.traces.empty());
  EXPECT_EQ(result.diagnostics.surfaceCellCompletedQuadCount,
            static_cast<std::size_t>(context.completedQuads.rows()));
  for (const std::string &productName : {"source", "cross-field",
                                        "feature", "rails", "metric", "relief", "relief-consumption",
                                        "source-labels",
                                        "tracing", "strands", "embedding",
                                        "arrangement", "simplification",
                                        "completion", "optimization",
                                        "validation"}) {
    const directional::pipeline::SurfaceCellContextProductDebug *product =
        find_context_product(context, productName);
    ASSERT_NE(nullptr, product) << productName;
    EXPECT_TRUE(product->available) << productName;
    EXPECT_NE(0U, product->structuralHash) << productName;
  }
    expect_lineage_identities_are_valid(result.diagnostics);
  const directional::SurfaceCellStageLineage *simplification =
      find_stage_lineage(result.diagnostics, "simplification");
  ASSERT_NE(nullptr, simplification);
  EXPECT_TRUE(simplification->noOp);
  EXPECT_EQ(simplification->inputObject.type, simplification->outputObject.type);
  EXPECT_EQ(simplification->inputObject.structuralHash,
            simplification->outputObject.structuralHash);
  ASSERT_FALSE(result.diagnostics.surfaceCellStageLineage.empty());
  const auto &lastStage = result.diagnostics.surfaceCellStageLineage.back();
  EXPECT_EQ("validation", lastStage.stage);
  EXPECT_EQ("None", lastStage.terminalFailureCode);
  EXPECT_EQ(result.diagnostics.surfaceCellCompletedQuadCount,
            lastStage.objectCount);
  EXPECT_FALSE(lastStage.consumedByNextStage);
}



TEST(SurfaceCellPipelinePhase20, ReliefBarrierEdgesStopTracingAcrossSourceEdge) {
  SyntheticMesh mesh;
  mesh.vertices.resize(4, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
                   1.0, 0.0, 0.0,
                   1.0, 1.0, 0.0,
                   0.0, 1.0, 0.0;
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2,
                0, 2, 3;

  Eigen::MatrixXd faceAxisX(2, 3);
  faceAxisX.row(0) << -1.0, 1.0, 0.0;
  faceAxisX.row(1) << -1.0, 1.0, 0.0;
  Eigen::MatrixXd faceAxisY(2, 3);
  faceAxisY.row(0) << 1.0, 0.0, 0.0;
  faceAxisY.row(1) << 1.0, 0.0, 0.0;

  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric = Eigen::RowVector3d(0.25, 0.50, 0.25);

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 2.0;
  options.reliefBarrierEdges.insert(
      directional::pipeline::surface_cell_source_edge_key(
          0, 2, static_cast<std::size_t>(mesh.vertices.rows())));
  options.reliefBarriersEmbedded = true;

  const directional::geometry::SurfaceTraceResult trace =
      directional::geometry::trace_surface_field(
          mesh.vertices, mesh.faces, faceAxisX, faceAxisY, seed, 0, 1,
          options);

  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(directional::geometry::TraceTerminationReason::Feature,
            trace.termination);
  EXPECT_EQ(1, trace.segments.front().exitEdge);
}

TEST(SurfaceCellPipelinePhase20, LiveTracingConsumesSelectedReliefRootsRegionsAndCancellation) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.relief.persistenceThreshold =
      std::numeric_limits<double>::infinity();
  options.surfaceCells.reliefRoots.maximumNormalizedDistance = 0.35;
  options.surfaceCells.injectFailureAfterStage = 3;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("tracing", result.diagnostics.terminalFailureStage);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  ASSERT_TRUE(context.hasReliefResult);
  ASSERT_TRUE(context.hasReliefRootSelection);
  ASSERT_TRUE(context.hasReliefBarrierEdges);
  ASSERT_TRUE(context.hasTraceNetwork);
  const directional::pipeline::SurfaceCellContextProductDebug *consumption =
      find_context_product(context, "relief-consumption");
  ASSERT_NE(nullptr, consumption);
  EXPECT_TRUE(consumption->available);
  EXPECT_EQ(context.reliefRootSelection.roots.size() +
                context.reliefBarrierEdges.size(),
            consumption->elementCount);
  EXPECT_EQ(context.reliefRootSelection.roots,
            context.productSnapshots.traceNetwork.reliefRootVertices);
  EXPECT_EQ(context.reliefRootSelection.labels.size(),
            context.productSnapshots.traceNetwork.reliefRegionLabels.size());
  EXPECT_EQ(context.reliefBarrierEdges,
            context.productSnapshots.traceNetwork.reliefBarrierEdges);
  EXPECT_EQ(mesh.vertices.rows(), context.reliefRootSelection.labels.size());

  std::set<int> canceledExtrema;
  for (const directional::geometry::ReliefPersistencePair &pair :
       context.reliefResult.persistencePairs) {
    if (pair.canceled) {
      canceledExtrema.insert(pair.extremum);
    }
  }
  for (const int root : context.productSnapshots.traceNetwork.reliefRootVertices) {
    EXPECT_EQ(0U, canceledExtrema.count(root));
  }

  std::set<int> rootRegions;
  for (const int root : context.productSnapshots.traceNetwork.reliefRootVertices) {
    ASSERT_GE(root, 0);
    ASSERT_LT(root, context.productSnapshots.traceNetwork.reliefRegionLabels.size());
    const int region = context.productSnapshots.traceNetwork.reliefRegionLabels[root];
    ASSERT_GE(region, 0);
    rootRegions.insert(region);
  }
  std::set<int> seededRegions;
  for (const directional::geometry::SurfaceTraceSeed &seed :
       context.productSnapshots.traceNetwork.seeds) {
    const int vertex =
        directional::geometry::surface_cell_tracing_detail::seed_anchor_vertex(
            seed, mesh.faces, static_cast<int>(mesh.vertices.rows()));
    if (vertex >= 0 && vertex < context.productSnapshots.traceNetwork.reliefRegionLabels.size()) {
      const int region = context.productSnapshots.traceNetwork.reliefRegionLabels[vertex];
      if (region >= 0) {
        seededRegions.insert(region);
      }
    }
  }
  for (const int region : rootRegions) {
    EXPECT_NE(0U, seededRegions.count(region));
  }

  const directional::SurfaceCellStageLineage *relief =
      find_stage_lineage(result.diagnostics, "relief");
  const directional::SurfaceCellStageLineage *tracing =
      find_stage_lineage(result.diagnostics, "tracing");
  ASSERT_NE(nullptr, relief);
  ASSERT_NE(nullptr, tracing);
  EXPECT_TRUE(relief->consumedByNextStage);
  EXPECT_EQ(directional::SurfaceCellConsumptionKind::Partial,
            relief->consumptionKind);
  EXPECT_EQ(directional::pipeline::hash_trace_network(context.productSnapshots.traceNetwork),
            tracing->outputObject.structuralHash);
}

TEST(SurfaceCellPipelinePhase20, LiveTracingUsesFamilySwapMatchingAcrossSourceEdge) {
  const SyntheticMesh mesh = make_planar_grid(1);
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 3;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, matching_swap_cross_field(mesh), options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("tracing", result.diagnostics.terminalFailureStage);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  ASSERT_TRUE(context.hasTraceNetwork);
  ASSERT_TRUE(context.productSnapshots.hasCrossField);
  directional::TriMesh sourceMesh;
  sourceMesh.set_mesh(mesh.vertices, mesh.faces);
  ASSERT_EQ(sourceMesh.EF.rows(), context.productSnapshots.crossField.matching.size());
  int interiorEdge = -1;
  for (int edge = 0; edge < sourceMesh.EF.rows(); ++edge) {
    if (sourceMesh.EF(edge, 0) >= 0 && sourceMesh.EF(edge, 1) >= 0) {
      interiorEdge = edge;
      break;
    }
  }
  ASSERT_GE(interiorEdge, 0);
  EXPECT_EQ(1, context.productSnapshots.crossField.matching[interiorEdge]);

  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions tracingOptions;
  tracingOptions.maxTraceLength = 10.0;
  const directional::geometry::SurfaceTraceResult trace =
      directional::geometry::trace_surface_field(
          mesh.vertices, mesh.faces, context.productSnapshots.crossField, seed, 0, -1,
          tracingOptions);
  ASSERT_GE(trace.segments.size(), 2U);
  EXPECT_EQ(1, trace.segments[0].matching);
  EXPECT_NEAR(trace.segments[0].matchingEffort, 0.25, 1.0e-12);
  EXPECT_EQ(1, trace.segments[1].face);
  EXPECT_EQ(1, trace.segments[1].family);

  const directional::SurfaceCellStageLineage *tracing =
      find_stage_lineage(result.diagnostics, "tracing");
  ASSERT_NE(nullptr, tracing);
  EXPECT_EQ(directional::pipeline::hash_trace_network(context.productSnapshots.traceNetwork),
            tracing->outputObject.structuralHash);
}

TEST(SurfaceCellPipelinePhase20, TraceMatchingUsesSourceEdgeTransitionIdentity) {
  const SyntheticMesh mesh = make_planar_grid(2);
  directional::TriMesh sourceMesh;
  sourceMesh.set_mesh(mesh.vertices, mesh.faces);
  Eigen::VectorXi matching = Eigen::VectorXi::Zero(sourceMesh.EF.rows());
  Eigen::VectorXd effort = Eigen::VectorXd::Zero(sourceMesh.EF.rows());
  std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
  for (int edge = 0; edge < sourceMesh.EF.rows(); ++edge) {
    directional::fields::CrossFieldEdgeTransition transition;
    transition.sourceEdge = edge;
    transition.sourceVertex0 = sourceMesh.EV(edge, 0);
    transition.sourceVertex1 = sourceMesh.EV(edge, 1);
    transition.firstFace = sourceMesh.EF(edge, 0);
    transition.secondFace = sourceMesh.EF(edge, 1);
    transition.matching =
        sourceMesh.EF(edge, 0) >= 0 && sourceMesh.EF(edge, 1) >= 0
            ? edge % 4
            : -1;
    transition.effort =
        sourceMesh.EF(edge, 0) >= 0 && sourceMesh.EF(edge, 1) >= 0
            ? 0.125 * static_cast<double>(edge + 1)
            : 0.0;
    matching(edge) = transition.matching;
    effort(edge) = transition.effort;
    transitions.push_back(transition);
  }
  std::reverse(transitions.begin(), transitions.end());

  int checked = 0;
  for (int edge = 0; edge < sourceMesh.EF.rows(); ++edge) {
    const int face = sourceMesh.EF(edge, 0);
    const int neighbor = sourceMesh.EF(edge, 1);
    if (face < 0 || neighbor < 0) {
      continue;
    }
    const int a = sourceMesh.EV(edge, 0);
    const int b = sourceMesh.EV(edge, 1);
    const int exitEdge =
        directional::pipeline::surface_cell_local_edge_index(mesh.faces, face,
                                                             a, b);
    ASSERT_GE(exitEdge, 0);
    directional::geometry::SurfaceTraceSeed seed;
    seed.point.face = face;
    seed.point.barycentric =
        Eigen::RowVector3d::Constant(0.25);
    seed.point.barycentric[exitEdge] = 0.50;
    const Eigen::RowVector3d start =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces, seed.point);
    directional::geometry::SurfaceTracePoint edgeMidpoint;
    edgeMidpoint.face = face;
    edgeMidpoint.barycentric = Eigen::RowVector3d::Zero();
    edgeMidpoint.barycentric[(exitEdge + 1) % 3] = 0.5;
    edgeMidpoint.barycentric[(exitEdge + 2) % 3] = 0.5;
    const Eigen::RowVector3d end =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces, edgeMidpoint);
    const Eigen::RowVector3d forward = (end - start).normalized();
    const Eigen::RowVector3d perpendicular(-forward.y(), forward.x(), 0.0);
    Eigen::MatrixXd faceAxisX =
        Eigen::MatrixXd::Zero(mesh.faces.rows(), 3);
    Eigen::MatrixXd faceAxisY =
        Eigen::MatrixXd::Zero(mesh.faces.rows(), 3);
    faceAxisX.rowwise() = Eigen::RowVector3d(1.0, 0.0, 0.0);
    faceAxisY.rowwise() = Eigen::RowVector3d(0.0, 1.0, 0.0);
    faceAxisX.row(face) = forward;
    faceAxisY.row(face) = perpendicular;

    // Configure the destination chart so the authoritative matching branch
    // continues into the adjacent triangle. This isolates transition-record
    // lookup from unrelated degenerate continuation geometry.
    switch (((matching(edge) % 4) + 4) % 4) {
    case 0:
      faceAxisX.row(neighbor) = forward;
      faceAxisY.row(neighbor) = perpendicular;
      break;
    case 1:
      faceAxisX.row(neighbor) = perpendicular;
      faceAxisY.row(neighbor) = forward;
      break;
    case 2:
      faceAxisX.row(neighbor) = -forward;
      faceAxisY.row(neighbor) = perpendicular;
      break;
    case 3:
      faceAxisX.row(neighbor) = perpendicular;
      faceAxisY.row(neighbor) = -forward;
      break;
    }

    directional::geometry::SurfaceCellTracingOptions options;
    options.maxTraceLength = 10.0;
    const directional::geometry::SurfaceTraceResult trace =
        directional::geometry::trace_surface_field(
            mesh.vertices, mesh.faces, faceAxisX, faceAxisY, seed, 0, 1,
            options, &matching, &effort, &transitions);
    // The contract under test is the transition metadata attached to the
    // segment that crosses this source edge. A valid trace may terminate in
    // the destination triangle immediately after that crossing, so requiring
    // a second segment would test unrelated continuation geometry.
    ASSERT_FALSE(trace.segments.empty()) << edge;
    EXPECT_EQ(matching(edge), trace.segments[0].matching) << edge;
    EXPECT_NEAR(effort(edge), trace.segments[0].matchingEffort, 1.0e-12)
        << edge;
    ++checked;
  }
  EXPECT_GT(checked, 1);
}

TEST(SurfaceCellPipelinePhase20, MissingEdgeTransitionTerminatesTraceFieldMetadata) {
  const SyntheticMesh mesh = make_planar_grid(1);
  directional::fields::CrossFieldResult field = matching_swap_cross_field(mesh);
  field.edgeTransitions.clear();
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;

  const directional::geometry::SurfaceTraceResult trace =
      directional::geometry::trace_surface_field(mesh.vertices, mesh.faces,
                                                 field, seed, 0, -1, options);

  EXPECT_EQ(directional::geometry::TraceTerminationReason::FieldMetadata,
            trace.termination);
}
TEST(SurfaceCellPipelinePhase20, FailedSurfaceCellPipelineNeverRunsLegacyIntegration) {
  const SyntheticMesh mesh = make_planar_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 9;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ(nullptr, result.produced_product());
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("optimization",
            result.diagnostics.originalSurfaceCellFailureStage);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("optimization", result.diagnostics.terminalFailureStage);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackCause.empty());
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_STREQ("None", surface_cell_output_origin_name(
                             result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.setupIntegrationSeconds);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.integrationTotalSeconds);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.setupMesherSeconds);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.mesherTotalSeconds);
  EXPECT_EQ(0U, result.diagnostics.integration.integerIterations);
  EXPECT_EQ(0U, result.diagnostics.integration.directFactorizations);
  EXPECT_DOUBLE_EQ(0.0,
                   result.diagnostics.integration.numericFactorizationSeconds);
}

TEST(SurfaceCellPipelinePhase20, DisconnectedFailureDoesNotEnterLegacyBackend) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 9;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.integrationTotalSeconds);
  EXPECT_EQ(0U, result.diagnostics.integration.directFactorizations);
}

TEST(SurfaceCellPipelinePhase20, CylinderFixtureCompletesProductionOutput) {
  const SyntheticMesh mesh = make_open_cylinder();
  const Eigen::MatrixXd raw = cylinder_raw_field(mesh);

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  ASSERT_TRUE(result.is_produced()) << result.diagnostics.terminalFailureCode << "/"
                              << result.diagnostics.terminalFailureStage;
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_STREQ("SourceGridRecovery",
               surface_cell_output_origin_name(
                   result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.terminalFailureStage.empty());
  EXPECT_TRUE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
  EXPECT_EQ(static_cast<std::size_t>(2 * mesh.faces.rows()),
            result.diagnostics.surfaceCellCompletedQuadCount);
  EXPECT_EQ(2 * mesh.faces.rows(), result.product().faces.rows());
  EXPECT_GT(result.product().vertices.rows(), mesh.vertices.rows());
  EXPECT_TRUE((result.product().degrees.array() == 4).all());
}
TEST(SurfaceCellPipelinePhase20, MultiFaceStripCompletesProductionOutput) {
  const SyntheticMesh mesh = make_two_square_strip();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  // Source-grid recovery refines each 0.75 x 0.75 source cell into a 2x2
  // block. Use the resulting 0.375 edge scale rather than the coarser
  // cylinder/grid default shared by surface_options().
  options.lengthRatio = 0.45;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(result.is_produced()) << result.diagnostics.terminalFailureCode << "/"
                              << result.diagnostics.terminalFailureStage;
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_STREQ("SourceGridRecovery",
               surface_cell_output_origin_name(
                   result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.terminalFailureStage.empty());
  EXPECT_TRUE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
  EXPECT_EQ(static_cast<std::size_t>(2 * mesh.faces.rows()),
            result.diagnostics.surfaceCellCompletedQuadCount);
  EXPECT_EQ(2 * mesh.faces.rows(), result.product().faces.rows());
  EXPECT_GT(result.product().vertices.rows(), mesh.vertices.rows());
  EXPECT_TRUE((result.product().degrees.array() == 4).all());
  EXPECT_EQ(result.surfaceCellContext.productSnapshots.crossField.matching.size(),
            result.product().crossFieldMatching.size());
  EXPECT_FALSE(result.diagnostics.surfaceCellStageLineage.empty());
}

TEST(SurfaceCellPipelinePhase20, CloseSheetsDoNotLeakSourceProvenance) {
  const SyntheticMesh mesh = make_close_parallel_sheets();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_TRUE(result.is_produced());
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_TRUE(result.surfaceCellContext.productSnapshots.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasMatching);
  EXPECT_EQ(result.product().crossFieldMatching.size(),
            result.surfaceCellContext.productSnapshots.crossField.matching.size());
  EXPECT_EQ(raw.rows(),
            result.surfaceCellContext.productSnapshots.crossField.rawField.rows());
  EXPECT_NE(nullptr, find_context_product(result.surfaceCellContext,
                                          "cross-field"));
  EXPECT_STREQ("SourceGridRecovery",
               surface_cell_output_origin_name(
                   result.diagnostics.surfaceCellOutputOrigin));
  if (result.diagnostics.surfaceCellRemeshOccurred) {
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::SourceGridRecovery,
              result.diagnostics.surfaceCellOutputOrigin);
  }
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize);
  EXPECT_GT(
      result.diagnostics
          .surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio,
      1.0);
  EXPECT_LE(
      result.diagnostics
          .surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio,
      surface_options().surfaceCells.maxSourceGridRecoveryTargetRelaxation);
  EXPECT_EQ(static_cast<std::size_t>(2 * mesh.faces.rows()),
            result.diagnostics.surfaceCellCompletedQuadCount);
}

TEST(SurfaceCellPipelinePhase20, ConnectedCloseSheetsKeepDistinctLocalSheetLabels) {
  const SyntheticMesh mesh = make_connected_close_opposing_sheets();
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 3;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, matching_swap_cross_field(mesh), options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("tracing", result.diagnostics.terminalFailureStage);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  ASSERT_TRUE(context.productSnapshots.hasSourceSurfaceLabels);
  ASSERT_EQ(mesh.faces.rows(),
            context.productSnapshots.sourceSurfaceLabels.componentByFace.size());
  ASSERT_EQ(mesh.faces.rows(),
            context.productSnapshots.sourceSurfaceLabels.localSheetByFace.size());
  EXPECT_EQ(context.productSnapshots.sourceSurfaceLabels.componentByFace[0],
            context.productSnapshots.sourceSurfaceLabels.componentByFace[4]);
  EXPECT_NE(context.productSnapshots.sourceSurfaceLabels.localSheetByFace[0],
            context.productSnapshots.sourceSurfaceLabels.localSheetByFace[4]);
  ASSERT_TRUE(context.hasTraceNetwork);
  EXPECT_EQ(context.productSnapshots.sourceSurfaceLabels.componentByFace,
            context.productSnapshots.traceNetwork.sourceFaceComponents);
  EXPECT_EQ(context.productSnapshots.sourceSurfaceLabels.localSheetByFace,
            context.productSnapshots.traceNetwork.sourceFaceSheets);
  for (const directional::geometry::SurfaceTraceResult &trace :
       context.productSnapshots.traceNetwork.traces) {
    EXPECT_TRUE(
        directional::geometry::surface_cell_tracing_detail::
            trace_respects_source_component(
                trace, context.productSnapshots.traceNetwork.sourceFaceComponents));
  }
  const directional::pipeline::SurfaceCellContextProductDebug *labels =
      find_context_product(context, "source-labels");
  ASSERT_NE(nullptr, labels);
  EXPECT_TRUE(labels->available);
  EXPECT_EQ(context.productSnapshots.sourceSurfaceLabels.localSheetByFace.size(),
            labels->elementCount);
}

TEST(SurfaceCellPipelinePhase20, SmoothHairpinUsesProximityOnlyToSeparateOpposingSheets) {
  const SyntheticMesh mesh = make_smooth_hairpin_strip();
  const directional::geometry::SourceSurfaceLabels labels =
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(mesh.vertices, mesh.faces);
  const int bottomFace = 0;
  const int topFace = static_cast<int>(mesh.faces.rows()) - 2;

  ASSERT_EQ(mesh.faces.rows(), labels.componentByFace.size());
  ASSERT_EQ(mesh.faces.rows(), labels.localSheetByFace.size());
  EXPECT_EQ(labels.componentByFace[bottomFace], labels.componentByFace[topFace]);
  EXPECT_EQ(labels.localSheetByFace[0], labels.localSheetByFace[1]);
  EXPECT_NE(labels.localSheetByFace[bottomFace], labels.localSheetByFace[topFace]);
}

TEST(SurfaceCellPipelinePhase20,
     InvalidSourceClassifierPolicyFailsBeforeTracing) {
  const SyntheticMesh mesh = make_two_square_strip();
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.sourceClassifier.closeSheetRadiusMeanEdges = 0.0;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, constant_raw_field(mesh.faces.rows()),
          options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InvalidClassifierOptions",
            result.diagnostics.terminalFailureCode);
  EXPECT_EQ("source-classification",
            result.diagnostics.terminalFailureStage);
  EXPECT_FALSE(result.surfaceCellContext.hasTraceNetwork);
  EXPECT_EQ(nullptr, result.produced_product());
}


TEST(SurfaceCellPipelinePhase20, PairedBoundaryProofGateIsExplicit) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.rejectPairedSourceTriangleBoundaryOutput = true;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("NotProductionReady", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("completion", result.diagnostics.terminalFailureStage);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.outputLineageValidation
                  .solelyPairedSourceTriangleBoundaries)
      << "descriptors=" << result.surfaceCellContext.patchDescriptors.size()
      << " completed=" << result.surfaceCellContext.productSnapshots.completedPatches.size()
      << " parity="
      << result.surfaceCellContext.completionOddCellsBeforeRepair << "->"
      << result.surfaceCellContext.completionOddCellsAfterRepair
      << " sides="
      << result.surfaceCellContext.completionSideInfeasibleBeforeRepair << "->"
      << result.surfaceCellContext.completionSideInfeasibleAfterRepair
      << " patches=" << patch_descriptor_summary(result);
  EXPECT_EQ("PairedSourceTriangleBoundaryOutput",
            result.surfaceCellContext.productSnapshots.outputLineageValidation.failure);
}
TEST(SurfaceCellPipelinePhase20,
     PairedBoundaryOutputFailsClosedWhenRecoveryIsDisabled) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.allowSourceGridRecovery = false;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("NotProductionReady", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("completion", result.diagnostics.terminalFailureStage);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.outputLineageValidation
                  .solelyPairedSourceTriangleBoundaries)
      << "descriptors=" << result.surfaceCellContext.patchDescriptors.size()
      << " completed=" << result.surfaceCellContext.productSnapshots.completedPatches.size()
      << " parity="
      << result.surfaceCellContext.completionOddCellsBeforeRepair << "->"
      << result.surfaceCellContext.completionOddCellsAfterRepair
      << " sides="
      << result.surfaceCellContext.completionSideInfeasibleBeforeRepair << "->"
      << result.surfaceCellContext.completionSideInfeasibleAfterRepair
      << " patches=" << patch_descriptor_summary(result);
  EXPECT_EQ("PairedSourceTriangleBoundaryOutput",
            result.surfaceCellContext.productSnapshots.outputLineageValidation.failure);
}

TEST(SurfaceCellPipelinePhase20, ValidationRejectionCannotReportCompletedSurfaceCells) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.targetSize.baseSize = 0.01;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_FALSE(result.is_produced());
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("NotProductionReady", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("validation", result.diagnostics.terminalFailureStage);
  EXPECT_TRUE(result.diagnostics.overallPipelineTimeAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellValidationFailureCountAvailable);
  EXPECT_GT(result.diagnostics.surfaceCellValidationFailures, 0U);
  EXPECT_TRUE(result.diagnostics.surfaceCellProvenanceVertexCountAvailable);
  EXPECT_EQ(result.surfaceCellContext.productSnapshots.optimizationResult.vertexProvenance.size(),
            result.diagnostics.surfaceCellProvenanceVertexCount);
  ASSERT_FALSE(result.diagnostics.surfaceCellStageLineage.empty());
  const directional::SurfaceCellStageLineage &lastStage =
      result.diagnostics.surfaceCellStageLineage.back();
  EXPECT_EQ("validation", lastStage.stage);
  EXPECT_EQ("NotProductionReady", lastStage.terminalFailureCode);
  EXPECT_EQ("validation", lastStage.terminalFailureStage);
}
TEST(SurfaceCellPipelinePhase20, ComponentOriginAggregationTracksMixedOrigins) {
  directional::RemeshDiagnostics target;
  target.surfaceCellOutputOrigin = directional::SurfaceCellOutputOrigin::None;

  directional::RemeshDiagnostics completed;
  completed.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::CompletedSurfaceCells;
  directional::pipeline::accumulate_component_diagnostics(target, completed);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            target.surfaceCellOutputOrigin);

  directional::RemeshDiagnostics completedAgain;
  completedAgain.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::CompletedSurfaceCells;
  directional::pipeline::accumulate_component_diagnostics(target, completedAgain);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            target.surfaceCellOutputOrigin);

  directional::RemeshDiagnostics fallback;
  fallback.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::InputMeshFallback;
  directional::pipeline::accumulate_component_diagnostics(target, fallback);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::Mixed,
            target.surfaceCellOutputOrigin);
}
TEST(SurfaceCellPipelinePhase20, InjectedFailuresPreserveLastCompletedStageArtifacts) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  const std::vector<std::string> stages = {"feature", "metric", "relief",
                                           "tracing", "strands", "embedding",
                                           "arrangement", "simplification",
                                           "completion", "optimization"};

  for (int stage = 0; stage < static_cast<int>(stages.size()); ++stage) {
    directional::pipeline::RemeshOptions options = surface_options();
    options.surfaceCells.preserveDebugArtifacts = true;
    options.surfaceCells.injectFailureAfterStage = stage;
    const directional::pipeline::RemeshResult result =
        directional::pipeline::remesh_from_raw_cross_field(
            mesh.vertices, mesh.faces, raw, options);

    EXPECT_FALSE(result.is_produced()) << stage;
    EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode)
        << stage;
    EXPECT_EQ(stages[static_cast<std::size_t>(stage)],
              result.diagnostics.terminalFailureStage)
        << stage;
    ASSERT_EQ(static_cast<std::size_t>(stage + 1),
              result.diagnostics.surfaceCellDebugArtifacts.size())
        << stage;
    for (int i = 0; i <= stage; ++i) {
      EXPECT_EQ(stages[static_cast<std::size_t>(i)],
                result.diagnostics.surfaceCellDebugArtifacts[static_cast<std::size_t>(i)])
          << stage;
    }
    ASSERT_FALSE(result.diagnostics.surfaceCellStageLineage.empty()) << stage;
    const directional::SurfaceCellStageLineage &failedLineage =
        result.diagnostics.surfaceCellStageLineage.back();
    EXPECT_EQ(stages[static_cast<std::size_t>(stage)], failedLineage.stage)
        << stage;
    EXPECT_EQ("InjectedStageFailure", failedLineage.terminalFailureCode)
        << stage;
    EXPECT_EQ(stages[static_cast<std::size_t>(stage)],
              failedLineage.terminalFailureStage)
        << stage;
    if (stages[static_cast<std::size_t>(stage)] == "embedding") {
      EXPECT_EQ("embedded-network", failedLineage.outputObject.type);
      EXPECT_NE(0U, failedLineage.outputObject.structuralHash);
      EXPECT_FALSE(failedLineage.consumedByNextStage);
    }
    if (stages[static_cast<std::size_t>(stage)] == "arrangement") {
      ASSERT_GE(result.diagnostics.surfaceCellStageLineage.size(), 2U);
      const directional::SurfaceCellStageLineage &embeddingLineage =
          result.diagnostics.surfaceCellStageLineage[
              result.diagnostics.surfaceCellStageLineage.size() - 2U];
      EXPECT_EQ("embedding", embeddingLineage.stage);
      EXPECT_EQ(embeddingLineage.outputObject.type,
                failedLineage.inputObject.type);
      EXPECT_EQ(embeddingLineage.outputObject.structuralHash,
                failedLineage.inputObject.structuralHash);
      EXPECT_TRUE(embeddingLineage.consumedByNextStage);
    }
  }
}

TEST(SurfaceCellPipelinePhase20, ComponentSchedulingAppliesToSurfaceCells) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnInputMesh;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(result.is_produced())
      << result.diagnostics.terminalFailureCode << "/"
      << result.diagnostics.terminalFailureStage << " component="
      << result.diagnostics.failedComponentIndex;
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("None", result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellReturnedInputMeshFallback);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::SourceGridRecovery,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ(2U, result.diagnostics.componentCount);
  EXPECT_EQ(2U, result.diagnostics.components.size());
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasCrossField);
  ASSERT_FALSE(result.diagnostics.surfaceCellStageLineage.empty());
  for (const directional::SurfaceCellStageLineage &lineage :
       result.diagnostics.surfaceCellStageLineage) {
    EXPECT_LT(lineage.componentIndex, 2U);
  }
}

TEST(SurfaceCellPipelinePhase20,
     CrossFieldResultParallelSurfaceCellsPreservesAuthoritativeMetadata) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::TriMesh sourceMesh;
  sourceMesh.set_mesh(mesh.vertices, mesh.faces);
  directional::fields::CrossFieldResult field =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          sourceMesh, constant_raw_field(mesh.faces.rows()));
  for (int edge = 0; edge < field.effort.size(); ++edge) {
    field.effort(edge) = 0.125 * static_cast<double>(edge + 1);
    field.edgeTransitions[static_cast<std::size_t>(edge)].effort =
        field.effort(edge);
  }
  directional::pipeline::RemeshOptions options = surface_options();
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, field, options);

  ASSERT_TRUE(result.is_produced())
      << result.diagnostics.terminalFailureCode << "/"
      << result.diagnostics.terminalFailureStage << " component="
      << result.diagnostics.failedComponentIndex;
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(field.rawField, result.product().rawCrossField);
  EXPECT_EQ(field.matching, result.product().crossFieldMatching);
  EXPECT_EQ(field.effort, result.product().crossFieldEffort);
  EXPECT_EQ(field.singularCycles, result.product().crossFieldSingularCycles);
  EXPECT_EQ(field.singularIndices, result.product().crossFieldSingularIndices);
  ASSERT_TRUE(result.surfaceCellContext.productSnapshots.hasCrossField);
  EXPECT_EQ(field.matching, result.surfaceCellContext.productSnapshots.crossField.matching);
  EXPECT_EQ(field.effort, result.surfaceCellContext.productSnapshots.crossField.effort);
  EXPECT_EQ(2U, result.diagnostics.componentCount);
}


TEST(SurfaceCellPipelinePhase20, SurfaceCellFallbackIsDeterministic) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnInputMesh;

  const std::string expected = signature(
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options));
  for (int run = 0; run < 10; ++run) {
    EXPECT_EQ(expected, signature(
                            directional::pipeline::remesh_from_raw_cross_field(
                                mesh.vertices, mesh.faces, raw, options)));
  }
}

TEST(SurfaceCellPipelinePhase20,
     PackagedFixtureClosureIsExecutableRelative) {
  const std::filesystem::path fixtureRoot =
      directional::tests::test_executable_directory() /
      "test-data/benchmarks/fixtures";
  for (const char *manifest : {"manifest.example.json",
                               "milestone_g_manifest.json",
                               "repo_regressions.json"}) {
    EXPECT_TRUE(std::filesystem::is_regular_file(fixtureRoot / manifest))
        << (fixtureRoot / manifest).string();
  }
  EXPECT_TRUE(std::filesystem::is_regular_file(
      fixtureRoot / "milestone-g/bunny_1k_random.obj"));
}

TEST(SurfaceCellPipelinePhase20, BenchmarkManifestDispatchesBackends) {
  const std::filesystem::path manifestPath =
      directional::tests::test_executable_directory() /
      "test-data/benchmarks/fixtures/manifest.example.json";
  ASSERT_TRUE(std::filesystem::is_regular_file(manifestPath))
      << manifestPath.string();
  const std::vector<directional::bench::BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifestPath);

  const auto surfaceCase = std::find_if(
      cases.begin(), cases.end(),
      [](const directional::bench::BenchmarkCase &candidate) {
        return candidate.name == "fertility_surface_cells_skeleton_hints";
      });
  ASSERT_NE(cases.end(), surfaceCase);
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            surfaceCase->backend);
  EXPECT_TRUE(surfaceCase->surfaceCellSkeletonHints);

  const directional::pipeline::RemeshOptions options =
      directional::bench::make_remesh_options(*surfaceCase);
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            options.backend);
  EXPECT_TRUE(options.surfaceCells.enabled);
  EXPECT_TRUE(options.surfaceCells.useSkeletonHints);
}
