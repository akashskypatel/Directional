#include <set>
#include <string>
#include <utility>

#include <gtest/gtest.h>

#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "TestAuthorityIds.h"

namespace {

struct REPkgMesh {
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

REPkgMesh make_rectangular_internal_hard_feature_grid() {
  // Accepted-D-era production-feasible hard-feature geometry: a 2x2 planar
  // grid whose x=1 midline splits the source into two rectangular topology
  // regions. Unlike the old two-triangle diagonal fixture, both regions are
  // inside the authoritative uniform phase-front producer's supported domain.
  constexpr int columns = 3;
  constexpr int rows = 3;
  REPkgMesh mesh;
  mesh.vertices.resize(columns * rows, 3);
  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < columns; ++x) {
      mesh.vertices.row(y * columns + x) <<
          static_cast<double>(x), static_cast<double>(y), 0.0;
    }
  }

  mesh.faces.resize(2 * (columns - 1) * (rows - 1), 3);
  int face = 0;
  for (int y = 0; y < rows - 1; ++y) {
    for (int x = 0; x < columns - 1; ++x) {
      const int lowerLeft = y * columns + x;
      const int lowerRight = lowerLeft + 1;
      const int upperLeft = lowerLeft + columns;
      const int upperRight = upperLeft + 1;
      mesh.faces.row(face++) << lowerLeft, lowerRight, upperRight;
      mesh.faces.row(face++) << lowerLeft, upperRight, upperLeft;
    }
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

directional::pipeline::RemeshOptions surface_options() {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.allowSourceGridRecovery = true;
  options.lengthRatio = 0.2;
  return options;
}

REPkgMesh make_grid(const int n) {
  REPkgMesh mesh;
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

directional::geometry::SurfaceCellRailSample rail_sample(
    const REPkgMesh &mesh, const int sourceFace, const int sourceEdge,
    const double parameter, const double railParameter,
    const Eigen::RowVector3d &barycentric, const int vertex) {
  directional::geometry::SurfaceCellRailSample sample;
  sample.sourceFace = sourceFace;
  sample.sourceEdge = sourceEdge;
  sample.parameter = parameter;
  sample.railParameter = railParameter;
  sample.barycentric = barycentric;
  sample.position = mesh.vertices.row(vertex);
  return sample;
}

TEST(SurfaceCellClosedProductContracts,
     RemeshResultPublishesExactlyOneTypedOutcome) {
  directional::pipeline::RemeshProduct output;
  output.vertices.resize(4, 3);
  output.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  output.faces.resize(1, 4);
  output.faces << 0, 1, 2, 3;
  output.degrees = Eigen::VectorXi::Constant(1, 4);

  const directional::pipeline::RemeshResult produced =
      directional::pipeline::RemeshResult::produced(
          std::move(output), directional::pipeline::RemeshProductKind::Meshed,
          true);
  ASSERT_TRUE(produced.is_produced());
  EXPECT_FALSE(produced.is_rejected());
  ASSERT_NE(produced.produced_product(), nullptr);
  EXPECT_EQ(directional::pipeline::RemeshProductKind::Meshed,
            produced.produced_product()->kind);
  EXPECT_TRUE(produced.cross_field_accepted());
  EXPECT_EQ(1, produced.product().faces.rows());

  directional::pipeline::RemeshFailure failure;
  failure.kind = directional::pipeline::RemeshFailureKind::SurfaceCellRejected;
  failure.surfaceCellFailure =
      directional::pipeline::SurfaceCellFailureCode::NotProductionReady;
  failure.stage = "contract-probe";
  failure.crossFieldAccepted = true;
  const directional::pipeline::RemeshResult rejected =
      directional::pipeline::RemeshResult::rejected(std::move(failure));
  EXPECT_TRUE(rejected.is_rejected());
  EXPECT_FALSE(rejected.is_produced());
  EXPECT_EQ(nullptr, rejected.produced_product());
  ASSERT_NE(rejected.rejection(), nullptr);
  EXPECT_EQ(directional::pipeline::RemeshFailureKind::SurfaceCellRejected,
            rejected.rejection()->kind);
  EXPECT_TRUE(rejected.cross_field_accepted());

  EXPECT_THROW(
      (void)directional::pipeline::RemeshResult::produced(
          {}, directional::pipeline::RemeshProductKind::Meshed, false),
      std::invalid_argument);
  EXPECT_THROW(
      (void)directional::pipeline::RemeshResult::rejected({}),
      std::invalid_argument);
}

TEST(SurfaceCellClosedProductContracts,
     RailBuildRejectionCarriesFailureWithoutConsumableRails) {
  const REPkgMesh mesh = make_rectangular_internal_hard_feature_grid();
  directional::TriMesh source;
  source.set_mesh(mesh.vertices, mesh.faces);

  directional::geometry::AdaptiveFeatureMap map;
  directional::geometry::AdaptiveFeatureEdge edge;
  edge.vertices = {0, 1};
  edge.incidentFaces = {-1};
  edge.edgeClass = directional::geometry::AdaptiveFeatureClass::Hard;
  edge.curve = 17;
  map.edges.push_back(edge);
  directional::geometry::AdaptiveFeatureCurve curve;
  curve.id = 17;
  curve.edges = {0};
  curve.vertices = {0, 1};
  map.curves.push_back(curve);

  const auto result =
      directional::pipeline::build_authoritative_surface_cell_rails(source, map);
  ASSERT_TRUE(result.is_rejected());
  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ(nullptr, result.produced_product());
  ASSERT_NE(result.rejection(), nullptr);
  EXPECT_EQ(directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge,
            result.rejection()->kind);
  EXPECT_EQ(0, result.rejection()->failedEdgeIndex);
}

TEST(SurfaceCellPipelinePhase20,
     AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement) {
  const REPkgMesh mesh = make_rectangular_internal_hard_feature_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.featureMap.userHardEdges.insert({1, 4});
  options.surfaceCells.featureMap.userHardEdges.insert({4, 7});
  options.surfaceCells.injectFailureAfterStage = 6;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("arrangement", result.diagnostics.terminalFailureStage);
  const directional::pipeline::SurfaceCellPipelineContext &context =
      result.surfaceCellContext;
  ASSERT_TRUE(context.productSnapshots.hasAuthoritativeRails);
  ASSERT_FALSE(context.productSnapshots.authoritativeRails.empty());
  const directional::pipeline::SurfaceCellContextProductDebug *railsProduct =
      find_context_product(context, "rails");
  ASSERT_NE(nullptr, railsProduct);
  EXPECT_TRUE(railsProduct->available);
  EXPECT_EQ(context.productSnapshots.authoritativeRails.size(), railsProduct->elementCount);
  ASSERT_TRUE(context.hasTraceNetwork);
  EXPECT_EQ(context.productSnapshots.authoritativeRails.size(),
            context.productSnapshots.traceNetwork.authoritativeRails.size());
  ASSERT_TRUE(context.productSnapshots.traceNetwork.phaseFront.is_produced());
  EXPECT_FALSE(context.productSnapshots.traceNetwork.phaseFront.product().cells().empty());

  bool hasBoundaryRail = false;
  bool hasHardRail = false;
  std::set<directional::authority::HardRailId> railIds;
  for (const directional::geometry::SurfaceCellRail &rail :
       context.productSnapshots.authoritativeRails) {
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

  bool sawHardFlowRepRail = false;
  bool sawBoundaryFlowRepRail = false;
  for (const directional::geometry::FlowRepArc &arc : context.productSnapshots.flowRepArcs) {
    if (arc.railId.has_value()) {
      EXPECT_EQ(1U, railIds.count(*arc.railId));
      EXPECT_TRUE(arc.mandatoryRail);
      EXPECT_GE(arc.curveId, 0);
      EXPECT_LE(arc.railT0, arc.railT1);
      sawHardFlowRepRail = sawHardFlowRepRail || arc.hardFeatureRail;
      sawBoundaryFlowRepRail = sawBoundaryFlowRepRail || arc.boundaryRail;
    }
  }
  EXPECT_TRUE(sawHardFlowRepRail);
  EXPECT_TRUE(sawBoundaryFlowRepRail);
  ASSERT_TRUE(context.hasFlowRepNetwork);
  EXPECT_TRUE(context.productSnapshots.flowRepNetwork.selectionSucceeded);
  EXPECT_TRUE(context.productSnapshots.flowRepNetwork.coverageEvidenceUsed);
  EXPECT_TRUE(context.productSnapshots.flowRepNetwork.cycleEvidenceUsed);
  EXPECT_EQ(context.productSnapshots.flowRepNetwork.mandatoryRails,
            context.productSnapshots.flowRepNetwork.retainedMandatoryRails);

  bool sawArrangementRail = false;
  for (const directional::geometry::SurfaceArrangementArc &arc :
       context.productSnapshots.embeddedArrangementArcs) {
    if (arc.railId.has_value()) {
      EXPECT_EQ(1U, railIds.count(*arc.railId));
      sawArrangementRail = true;
      EXPECT_GE(arc.curveId, 0);
      EXPECT_TRUE(arc.hardFeature);
    }
  }
  EXPECT_TRUE(sawArrangementRail);
  ASSERT_TRUE(context.hasArrangement);
  EXPECT_GT(context.tracingCurrentOwnedBytes, 0U);
  EXPECT_GE(context.tracingPeakOwnedBytes,
            context.tracingCurrentOwnedBytes);
  EXPECT_GT(context.flowRepCurrentOwnedBytes, 0U);
  EXPECT_GE(context.flowRepPeakOwnedBytes,
            context.flowRepCurrentOwnedBytes);
  EXPECT_GT(context.arrangementCurrentOwnedBytes, 0U);
  EXPECT_GE(context.arrangementPeakOwnedBytes,
            context.arrangementCurrentOwnedBytes);
  EXPECT_GE(context.maxSimultaneousLiveLargeStructures, 2);
  EXPECT_GT(context.tracingLogicalPayloadBytes, 0U);
  EXPECT_GE(context.tracingRetainedCapacityBytes,
            context.tracingLogicalPayloadBytes);
  EXPECT_GT(context.flowRepLogicalPayloadBytes, 0U);
  EXPECT_GE(context.flowRepRetainedCapacityBytes,
            context.flowRepLogicalPayloadBytes);
  EXPECT_GT(context.arrangementLogicalPayloadBytes, 0U);
  EXPECT_GE(context.arrangementRetainedCapacityBytes,
            context.arrangementLogicalPayloadBytes);
  EXPECT_FALSE(context.memoryOwnershipTimeline.empty());
  EXPECT_GT(context.estimatedPeakSimultaneousOwnedBytes, 0U);
  for (const directional::SurfaceCellMemoryOwnershipEvent &event :
       context.memoryOwnershipTimeline) {
    EXPECT_FALSE(event.stage.empty());
    EXPECT_TRUE(event.action == "acquire" || event.action == "release");
    EXPECT_GE(event.retainedCapacityBytes, event.logicalPayloadBytes);
    if (event.action == "acquire") {
      EXPECT_GE(event.simultaneousOwnedBytes, event.retainedCapacityBytes);
    } else {
      EXPECT_EQ(0U, event.retainedCapacityBytes);
    }
  }
  bool sawHalfedgeRail = false;
  for (const directional::geometry::SurfaceArrangementHalfedge &halfedge :
       context.productSnapshots.arrangement.halfedges) {
    if (halfedge.railId.has_value()) {
      EXPECT_EQ(1U, railIds.count(*halfedge.railId));
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
  EXPECT_EQ(directional::pipeline::hash_trace_network(context.productSnapshots.traceNetwork),
            tracing->outputObject.structuralHash);
}


TEST(SurfaceCellFieldAlignedNetworkAuthority,
     ProductionConsumesTypedSkeletonWithoutRawSingularityProjection) {
  const REPkgMesh mesh = make_rectangular_internal_hard_feature_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.featureMap.userHardEdges.insert({1, 4});
  options.surfaceCells.featureMap.userHardEdges.insert({4, 7});
  options.surfaceCells.injectFailureAfterStage = 3;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_TRUE(result.is_rejected());
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("tracing", result.diagnostics.terminalFailureStage);
  const auto &context = result.surfaceCellContext;
  EXPECT_TRUE(context.fieldAlignedNetworkAuthorityUsed);
  EXPECT_FALSE(context.rawSingularityProjectionUsed);
  ASSERT_TRUE(context.productSnapshots.fieldAlignedCurveNetwork.has_value());
  const auto &network = *context.productSnapshots.fieldAlignedCurveNetwork;
  EXPECT_NE(0U, network.semantic_digest());
  EXPECT_FALSE(network.mandatory_edges().empty());
  EXPECT_EQ(
      directional::geometry::field_aligned_curve_network_hash(network),
      network.semantic_digest());
  EXPECT_TRUE(context.hasTraceNetwork);
  const directional::pipeline::SurfaceCellContextProductDebug *product =
      find_context_product(context, "field-aligned-network");
  ASSERT_NE(nullptr, product);
  EXPECT_TRUE(product->available);
  EXPECT_EQ(network.nodes().size() + network.singularity_ports().size() +
                network.mandatory_edges().size(),
            product->elementCount);
}

TEST(SurfaceCellTracingPhase14,
     InteriorHardRailSeedsBothIncidentFaceCharts) {
  const REPkgMesh mesh = make_grid(1);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 10.0);
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 10.0;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};

  directional::geometry::SurfaceCellRail rail(
      directional::tests::test_hard_rail_id(19));
  rail.curveId = 7;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3)};
  options.authoritativeRails.push_back(rail);

  const auto seeds = directional::geometry::generate_deterministic_surface_seeds(
      mesh.vertices, mesh.faces, targetSize, options);

  ASSERT_EQ(4U, seeds.size());
  std::set<std::pair<int, int>> endpointCharts;
  for (const auto &seed : seeds) {
    EXPECT_EQ(directional::geometry::SurfaceSeedProvenance::Feature,
              seed.provenance);
    ASSERT_TRUE(seed.hardRailId.has_value());
    EXPECT_EQ(rail.id, *seed.hardRailId);
    EXPECT_EQ(-1, seed.sourceId);
    const Eigen::Index corner = [&]() {
      Eigen::Index index = 0;
      seed.point.barycentric.maxCoeff(&index);
      return index;
    }();
    ASSERT_GT(seed.point.barycentric[corner], 1.0 - 1.0e-12);
    endpointCharts.insert(
        {mesh.faces(seed.point.face, static_cast<int>(corner)),
         seed.point.face});
  }
  EXPECT_EQ((std::set<std::pair<int, int>>{{0, 0}, {0, 1}, {3, 0}, {3, 1}}),
            endpointCharts);
}

}  // namespace
