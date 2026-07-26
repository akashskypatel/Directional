#include <algorithm>
#include <cmath>
#include <filesystem>
#include <numbers>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/fields/CrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"

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
  return options;
}

std::string signature(const directional::pipeline::RemeshResult &result) {
  return result.diagnostics.requestedBackend + "/" +
         result.diagnostics.executedBackend + "/" +
         result.diagnostics.terminalFailureCode + "/" +
         std::to_string(result.vertices.rows()) + "/" +
         std::to_string(result.faces.rows()) + "/" +
         std::to_string(result.degrees.sum());
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

  const std::vector<directional::geometry::SurfaceCellRail> rails =
      directional::pipeline::build_authoritative_surface_cell_rails(meshWhole, map);

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
  first[0].railId = 4;
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
  EXPECT_EQ(SurfaceCellFallbackPolicy::ReturnQuadDominant,
            directional::pipeline::parse_surface_cell_fallback_policy(
                "return-quad-dominant"));
  EXPECT_THROW((void)directional::pipeline::parse_remesh_backend("unknown"),
               std::runtime_error);
}

TEST(SurfaceCellPipelinePhase20, InvalidRawFieldDimsReturnPreciseFailureCode) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd badRaw(mesh.faces.rows(), 9);
  badRaw.setZero();
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, badRaw, surface_options());

  EXPECT_FALSE(result.success);
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

  field.matchingComputed = true;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingSingularities", result.diagnostics.terminalFailureCode);

  field.singularitiesComputed = true;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingConfidence", result.diagnostics.terminalFailureCode);

  field.confidence = Eigen::VectorXd::Ones(mesh.faces.rows());
  field.confidenceComputed = true;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("UncoveredFaces", result.diagnostics.terminalFailureCode);

  field.uncoveredFaces.resize(0);
  field.uncoveredFacePolicyApplied = true;
  directional::TriMesh meshWhole;
  meshWhole.set_mesh(mesh.vertices, mesh.faces);
  field = directional::pipeline::finalize_surface_cell_raw_cross_field(
      meshWhole, field.rawField);
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_TRUE(result.success);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_TRUE(result.surfaceCellContext.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasMatching);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasSingularities);
  EXPECT_TRUE(result.surfaceCellContext.crossField.confidenceComputed);
  EXPECT_TRUE(result.surfaceCellContext.crossField.uncoveredFacePolicyApplied);
  EXPECT_EQ(field.matching.size(),
            result.surfaceCellContext.crossField.matching.size());
  EXPECT_EQ(field.rawField.rows(),
            result.surfaceCellContext.crossField.rawField.rows());
  EXPECT_NE(nullptr, find_context_product(result.surfaceCellContext,
                                          "cross-field"));
  EXPECT_STREQ("CompletedSurfaceCells", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  if (result.diagnostics.surfaceCellRemeshOccurred) {
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
              result.diagnostics.surfaceCellOutputOrigin);
  }
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

  ASSERT_TRUE(rawResult.surfaceCellContext.hasCrossField);
  ASSERT_TRUE(finalizedResult.surfaceCellContext.hasCrossField);
  EXPECT_TRUE(rawResult.surfaceCellContext.crossField.matchingComputed);
  EXPECT_TRUE(rawResult.surfaceCellContext.crossField.singularitiesComputed);
  EXPECT_TRUE(rawResult.surfaceCellContext.crossField.confidenceComputed);
  EXPECT_TRUE(rawResult.surfaceCellContext.crossField.uncoveredFacePolicyApplied);
  EXPECT_EQ(finalized.matching.size(),
            rawResult.surfaceCellContext.crossField.matching.size());
  EXPECT_EQ(finalized.effort.size(),
            rawResult.surfaceCellContext.crossField.effort.size());
  EXPECT_EQ(finalized.singularCycles.size(),
            rawResult.surfaceCellContext.crossField.singularCycles.size());
  EXPECT_EQ(finalized.singularIndices.size(),
            rawResult.surfaceCellContext.crossField.singularIndices.size());
  EXPECT_EQ(0, rawResult.surfaceCellContext.crossField.uncoveredFaces.size());
  EXPECT_EQ(rawResult.surfaceCellContext.crossField.matching.size(),
            finalizedResult.surfaceCellContext.crossField.matching.size());
  EXPECT_EQ(rawResult.surfaceCellContext.crossField.singularitiesComputed,
            finalizedResult.surfaceCellContext.crossField.singularitiesComputed);
}

TEST(SurfaceCellPipelinePhase20, UncoveredRawFieldFacesFailBeforeTracing) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  raw.row(0).setZero();

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_FALSE(result.success);
  EXPECT_EQ("UncoveredFaces", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_TRUE(result.surfaceCellContext.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossField.confidenceComputed);
  EXPECT_TRUE(result.surfaceCellContext.crossField.uncoveredFacePolicyApplied);
  ASSERT_EQ(1, result.surfaceCellContext.crossField.uncoveredFaces.size());
  EXPECT_EQ(0, result.surfaceCellContext.crossField.uncoveredFaces(0));
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
  EXPECT_FALSE(result.success);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);

  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.success) << "relief=" << result.diagnostics.surfaceCellReliefPatchCount << " trace=" << result.diagnostics.surfaceCellTraceSegmentCount << " arrangement=" << result.diagnostics.surfaceCellArrangementCellCount << " simplified=" << result.diagnostics.surfaceCellSimplifiedCellCount << " completed=" << result.diagnostics.surfaceCellCompletedQuadCount << " opt=" << result.diagnostics.surfaceCellOptimizationIterationCount << " terminal=" << result.diagnostics.terminalFailureCode << ":" << result.diagnostics.terminalFailureStage;
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellReturnedQuadDominantFallback);
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

  EXPECT_TRUE(result.success);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_TRUE(result.surfaceCellContext.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasMatching);
  EXPECT_EQ(result.crossFieldMatching.size(),
            result.surfaceCellContext.crossField.matching.size());
  EXPECT_EQ(raw.rows(),
            result.surfaceCellContext.crossField.rawField.rows());
  EXPECT_NE(nullptr, find_context_product(result.surfaceCellContext,
                                          "cross-field"));
  EXPECT_STREQ("CompletedSurfaceCells", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  if (result.diagnostics.surfaceCellRemeshOccurred) {
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
              result.diagnostics.surfaceCellOutputOrigin);
  }
  EXPECT_EQ(static_cast<std::size_t>(mesh.vertices.rows()),
            result.diagnostics.surfaceCellMetricSampleCount);
  EXPECT_NE(static_cast<std::size_t>(mesh.faces.rows()),
            result.diagnostics.surfaceCellFeatureCount);
  EXPECT_TRUE(result.diagnostics.surfaceCellReliefCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellTraceCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellArrangementCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellSimplifiedCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellCompletedQuadCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellOptimizationIterationCountAvailable);
  EXPECT_GT(result.diagnostics.surfaceCellReliefPatchCount, 0U);
  EXPECT_GT(result.diagnostics.surfaceCellTraceSegmentCount, 0U);
  EXPECT_EQ(2U, result.diagnostics.surfaceCellCompletedQuadCount);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  EXPECT_TRUE(context.hasSourceMesh);
  EXPECT_TRUE(context.hasCrossField);
  EXPECT_TRUE(context.hasFeatureMap);
  EXPECT_TRUE(context.hasAuthoritativeRails);
  EXPECT_TRUE(context.hasMetricField);
  EXPECT_TRUE(context.hasReliefResult);
  EXPECT_TRUE(context.hasTraceNetwork);
  EXPECT_TRUE(context.hasFlowRepNetwork);
  EXPECT_TRUE(context.hasEmbeddedArrangementArcs);
  EXPECT_TRUE(context.hasArrangement);
  EXPECT_TRUE(context.hasSimplifiedComplex);
  EXPECT_TRUE(context.hasCompletedPatches);
  EXPECT_TRUE(context.hasOptimizationResult);
  EXPECT_TRUE(context.hasValidationResult);
  EXPECT_TRUE(context.validationResult.authoritativeBoundaryUsed);
  EXPECT_TRUE(context.validationResult.authoritativeFeatureRailsUsed);
  EXPECT_EQ(mesh.faces.rows(), context.sourceMesh.F.rows());
  EXPECT_EQ(result.diagnostics.surfaceCellFeatureCount,
            context.featureMap.edges.size());
  EXPECT_EQ(result.diagnostics.surfaceCellTraceSegmentCount > 0,
            !context.traceNetwork.traces.empty());
  EXPECT_EQ(result.diagnostics.surfaceCellCompletedQuadCount,
            context.completedPatches.size());
  for (const std::string &productName : {"source", "cross-field",
                                        "feature", "rails", "metric", "relief",
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
  EXPECT_EQ(2U, lastStage.objectCount);
  EXPECT_FALSE(lastStage.consumedByNextStage);
}


TEST(SurfaceCellPipelinePhase20, LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.featureMap.userHardEdges.insert({0, 2});
  options.surfaceCells.injectFailureAfterStage = 6;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.success);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("arrangement", result.diagnostics.terminalFailureStage);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  ASSERT_TRUE(context.hasAuthoritativeRails);
  ASSERT_FALSE(context.authoritativeRails.empty());
  const directional::pipeline::SurfaceCellContextProductDebug *railsProduct =
      find_context_product(context, "rails");
  ASSERT_NE(nullptr, railsProduct);
  EXPECT_TRUE(railsProduct->available);
  EXPECT_EQ(context.authoritativeRails.size(), railsProduct->elementCount);
  ASSERT_TRUE(context.hasTraceNetwork);
  EXPECT_EQ(context.authoritativeRails.size(),
            context.traceNetwork.authoritativeRails.size());

  bool hasBoundaryRail = false;
  bool hasHardRail = false;
  std::set<int> railIds;
  for (const directional::geometry::SurfaceCellRail &rail :
       context.authoritativeRails) {
    railIds.insert(rail.id);
    hasBoundaryRail = hasBoundaryRail ||
        rail.kind == directional::geometry::SurfaceCellRailKind::Boundary;
    hasHardRail = hasHardRail ||
        rail.kind == directional::geometry::SurfaceCellRailKind::HardFeature;
    EXPECT_GE(rail.curveId, 0);
    EXPECT_GE(rail.component, 0);
    EXPECT_GE(rail.samples.size(), 2U);
    for (const directional::geometry::SurfaceCellRailSample &sample :
         rail.samples) {
      EXPECT_GE(sample.sourceFace, 0);
      EXPECT_GE(sample.sourceEdge, 0);
      EXPECT_NEAR(1.0, sample.barycentric.sum(), 1.0e-12);
    }
  }
  EXPECT_TRUE(hasBoundaryRail);
  EXPECT_TRUE(hasHardRail);

  bool sawRailSeed = false;
  for (const directional::geometry::SurfaceTraceSeed &seed :
       context.traceNetwork.seeds) {
    if ((seed.provenance == directional::geometry::SurfaceSeedProvenance::Boundary ||
         seed.provenance == directional::geometry::SurfaceSeedProvenance::Feature) &&
        railIds.count(seed.sourceId) != 0) {
      sawRailSeed = true;
    }
  }
  EXPECT_TRUE(sawRailSeed);

  bool sawHardFlowRepRail = false;
  bool sawBoundaryFlowRepRail = false;
  for (const directional::geometry::FlowRepArc &arc : context.flowRepArcs) {
    if (arc.railId >= 0) {
      EXPECT_TRUE(arc.mandatoryRail);
      EXPECT_GE(arc.curveId, 0);
      EXPECT_LE(arc.railT0, arc.railT1);
      sawHardFlowRepRail = sawHardFlowRepRail || arc.hardFeatureRail;
      sawBoundaryFlowRepRail = sawBoundaryFlowRepRail || arc.boundaryRail;
    }
  }
  EXPECT_TRUE(sawHardFlowRepRail);
  EXPECT_TRUE(sawBoundaryFlowRepRail);

  bool sawArrangementRail = false;
  for (const directional::geometry::SurfaceArrangementArc &arc :
       context.embeddedArrangementArcs) {
    if (arc.railId >= 0) {
      sawArrangementRail = true;
      EXPECT_GE(arc.curveId, 0);
      EXPECT_TRUE(arc.hardFeature);
    }
  }
  EXPECT_TRUE(sawArrangementRail);
  bool sawHalfedgeRail = false;
  for (const directional::geometry::SurfaceArrangementHalfedge &halfedge :
       context.arrangement.halfedges) {
    if (halfedge.railId >= 0) {
      sawHalfedgeRail = true;
      EXPECT_GE(halfedge.curveId, 0);
      EXPECT_GE(halfedge.railT0, 0.0);
      EXPECT_LE(halfedge.railT0, 1.0);
      EXPECT_GE(halfedge.railT1, 0.0);
      EXPECT_LE(halfedge.railT1, 1.0);
    }
  }
  EXPECT_TRUE(sawHalfedgeRail);

  const directional::SurfaceCellStageLineage *tracing =
      find_stage_lineage(result.diagnostics, "tracing");
  ASSERT_NE(nullptr, tracing);
  EXPECT_TRUE(tracing->consumedByNextStage);
  EXPECT_EQ(directional::pipeline::hash_trace_network(context.traceNetwork),
            tracing->outputObject.structuralHash);
}
TEST(SurfaceCellPipelinePhase20, TryLegacyPreservesInjectedSurfaceCellFailureWhenLegacyFails) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 9;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::TryLegacy;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.surfaceCellFallbackCause);
  EXPECT_STREQ("None", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
}


TEST(SurfaceCellPipelinePhase20, TryLegacyReportsExecutedBackendWhenLegacySucceeds) {
  const SyntheticMesh mesh = make_planar_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 9;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::TryLegacy;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("LegacyInteger", result.diagnostics.executedBackend);
  EXPECT_EQ("NotProductionReady",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("completion",
            result.diagnostics.originalSurfaceCellFailureStage);
  EXPECT_EQ("NotProductionReady", result.diagnostics.surfaceCellFallbackCause);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_STREQ("LegacyFallback", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_NE("InjectedStageFailure", result.diagnostics.terminalFailureCode);
}

TEST(SurfaceCellPipelinePhase20, CylinderFixtureFailsHonestlyAtCompletion) {
  const SyntheticMesh mesh = make_open_cylinder();
  const Eigen::MatrixXd raw = cylinder_raw_field(mesh);

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_FALSE(result.success);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_STREQ("None", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_EQ("NotProductionReady", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("completion", result.diagnostics.terminalFailureStage);
  EXPECT_EQ(0U, result.diagnostics.surfaceCellCompletedQuadCount);
}
TEST(SurfaceCellPipelinePhase20, MultiFaceStripFailsClosedAtCrossFieldValidation) {
  const SyntheticMesh mesh = make_two_square_strip();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_FALSE(result.success);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_STREQ("None", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  EXPECT_EQ("MissingSingularities", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("cross-field-validation", result.diagnostics.terminalFailureStage);
  EXPECT_EQ(0U, result.diagnostics.surfaceCellCompletedQuadCount);
  EXPECT_TRUE(result.diagnostics.surfaceCellStageLineage.empty());
}

TEST(SurfaceCellPipelinePhase20, CloseSheetsDoNotLeakSourceProvenance) {
  const SyntheticMesh mesh = make_close_parallel_sheets();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_TRUE(result.surfaceCellContext.hasCrossField);
  EXPECT_TRUE(result.surfaceCellContext.crossFieldHasMatching);
  EXPECT_EQ(result.crossFieldMatching.size(),
            result.surfaceCellContext.crossField.matching.size());
  EXPECT_EQ(raw.rows(),
            result.surfaceCellContext.crossField.rawField.rows());
  EXPECT_NE(nullptr, find_context_product(result.surfaceCellContext,
                                          "cross-field"));
  EXPECT_STREQ("CompletedSurfaceCells", surface_cell_output_origin_name(result.diagnostics.surfaceCellOutputOrigin));
  if (result.diagnostics.surfaceCellRemeshOccurred) {
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
              result.diagnostics.surfaceCellOutputOrigin);
  }
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_EQ(2U, result.diagnostics.surfaceCellCompletedQuadCount);
}


TEST(SurfaceCellPipelinePhase20, ValidationRejectionCannotReportCompletedSurfaceCells) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.targetSize.baseSize = 0.01;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_FALSE(result.success);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("NotProductionReady", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("validation", result.diagnostics.terminalFailureStage);
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

    EXPECT_FALSE(result.success) << stage;
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

  directional::pipeline::RemeshOptions sequential = surface_options();
  sequential.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;
  const directional::pipeline::RemeshResult sequentialResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, sequential);

  directional::pipeline::RemeshOptions parallel = sequential;
  parallel.parallelizeComponents = true;
  parallel.maxComponentThreads = 2;
  const directional::pipeline::RemeshResult parallelResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, parallel);

  EXPECT_TRUE(sequentialResult.success);
  EXPECT_TRUE(parallelResult.success);
  EXPECT_EQ(signature(sequentialResult), signature(parallelResult));
  EXPECT_EQ(2U, parallelResult.diagnostics.componentCount);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            sequentialResult.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            parallelResult.diagnostics.surfaceCellOutputOrigin);
  EXPECT_TRUE(parallelResult.diagnostics.surfaceCellRemeshOccurred);
  const directional::SurfaceCellStageLineage *arrangement =
      find_stage_lineage(parallelResult.diagnostics, "arrangement");
  ASSERT_NE(nullptr, arrangement);
  EXPECT_EQ("embedded-network", arrangement->inputObject.type);
  EXPECT_NE(0U, arrangement->inputObject.structuralHash);
  EXPECT_GE(parallelResult.diagnostics.surfaceCellStageLineage.size(),
            sequentialResult.diagnostics.surfaceCellStageLineage.size());
  EXPECT_GE(parallelResult.diagnostics.surfaceCellCompletedQuadCount, 2U);
  expect_lineage_identities_are_valid(parallelResult.diagnostics);
}

TEST(SurfaceCellPipelinePhase20, SurfaceCellFallbackIsDeterministic) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;

  const std::string expected = signature(
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options));
  for (int run = 0; run < 10; ++run) {
    EXPECT_EQ(expected, signature(
                            directional::pipeline::remesh_from_raw_cross_field(
                                mesh.vertices, mesh.faces, raw, options)));
  }
}

TEST(SurfaceCellPipelinePhase20, BenchmarkManifestDispatchesBackends) {
  const std::filesystem::path manifestPath =
      std::filesystem::path(DIRECTIONAL_TEST_SOURCE_DIR) /
      "benchmarks/fixtures/manifest.example.json";
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
