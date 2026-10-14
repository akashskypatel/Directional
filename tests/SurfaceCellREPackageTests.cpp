#include <algorithm>
#include <array>
#include <map>
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

  // A source-valid feature edge must not be silently attributed to a
  // different curve or component when its rail is published.
  auto validMap = map;
  validMap.edges[0].incidentFaces = {0};
  validMap.edges[0].component = 0;
  validMap.curves[0].component = 0;
  const auto good = directional::pipeline::build_authoritative_surface_cell_rails(
      source, validMap);
  ASSERT_TRUE(good.is_produced());
  ASSERT_EQ(1U, good.product().rails.size());
  EXPECT_EQ(0, good.product().rails[0].component);
  EXPECT_EQ(17, good.product().rails[0].curveId);

  auto wrongComponent = validMap;
  wrongComponent.edges[0].component = 1;
  const auto foreignComponent =
      directional::pipeline::build_authoritative_surface_cell_rails(
          source, wrongComponent);
  ASSERT_TRUE(foreignComponent.is_rejected());
  ASSERT_NE(foreignComponent.rejection(), nullptr);
  EXPECT_EQ(foreignComponent.rejection()->kind,
            directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge);
  EXPECT_EQ(0, foreignComponent.rejection()->failedEdgeIndex);

  auto wrongCurve = validMap;
  wrongCurve.edges[0].curve = 18;
  const auto foreignCurve =
      directional::pipeline::build_authoritative_surface_cell_rails(
          source, wrongCurve);
  ASSERT_TRUE(foreignCurve.is_rejected());
  ASSERT_NE(foreignCurve.rejection(), nullptr);
  EXPECT_EQ(foreignCurve.rejection()->kind,
            directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge);
  EXPECT_EQ(0, foreignCurve.rejection()->failedEdgeIndex);

  // Both published owners can agree with each other and still be foreign to
  // the real source component. Use two disconnected source triangles so the
  // replacement component is a real, independently supported source owner.
  directional::TriMesh twoComponentSource;
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0., 0., 0., 1., 0., 0., 0., 1., 0.,
              3., 0., 0., 4., 0., 0., 3., 1., 0.;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 3, 4, 5;
  twoComponentSource.set_mesh(vertices, faces);
  auto sourcedMap = validMap;
  const auto actual = directional::pipeline::build_authoritative_surface_cell_rails(
      twoComponentSource, sourcedMap);
  ASSERT_TRUE(actual.is_produced());
  ASSERT_EQ(1U, actual.product().rails.size());
  EXPECT_EQ(0, actual.product().rails.front().component);
  auto secondSourceOwner = sourcedMap;
  secondSourceOwner.edges[0].vertices = {3, 4};
  secondSourceOwner.edges[0].incidentFaces = {1};
  secondSourceOwner.edges[0].component = 1;
  secondSourceOwner.curves[0].vertices = {3, 4};
  secondSourceOwner.curves[0].component = 1;
  const auto second = directional::pipeline::build_authoritative_surface_cell_rails(
      twoComponentSource, secondSourceOwner);
  ASSERT_TRUE(second.is_produced());
  EXPECT_EQ(1, second.product().rails.front().component);

  // A first valid supporting face does not authenticate the complete source
  // incidence of the feature edge, even when all component labels agree.
  auto forgedIncidence = sourcedMap;
  forgedIncidence.edges[0].incidentFaces = {0, 1};
  const auto foreignIncidentFace =
      directional::pipeline::build_authoritative_surface_cell_rails(
          twoComponentSource, forgedIncidence);
  ASSERT_TRUE(foreignIncidentFace.is_rejected());
  ASSERT_NE(foreignIncidentFace.rejection(), nullptr);
  EXPECT_EQ(directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge,
            foreignIncidentFace.rejection()->kind);
  EXPECT_EQ(0, foreignIncidentFace.rejection()->failedEdgeIndex);

  // Face 1 belongs to the same connected component as face 0, but does
  // not contain source edge (0,1). Component agreement alone is insufficient.
  auto sameComponentForeignFace = validMap;
  sameComponentForeignFace.edges[0].incidentFaces = {0, 1};
  const auto foreignSameComponent =
      directional::pipeline::build_authoritative_surface_cell_rails(
          source, sameComponentForeignFace);
  ASSERT_TRUE(foreignSameComponent.is_rejected());
  ASSERT_NE(foreignSameComponent.rejection(), nullptr);
  EXPECT_EQ(directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge,
            foreignSameComponent.rejection()->kind);
  EXPECT_EQ(0, foreignSameComponent.rejection()->failedEdgeIndex);

  auto forgedSourceComponent = sourcedMap;
  forgedSourceComponent.curves[0].component = 1;
  forgedSourceComponent.edges[0].component = 1;
  const auto wrongSourceComponent =
      directional::pipeline::build_authoritative_surface_cell_rails(
          twoComponentSource, forgedSourceComponent);
  ASSERT_TRUE(wrongSourceComponent.is_rejected());
  ASSERT_NE(wrongSourceComponent.rejection(), nullptr);
  EXPECT_EQ(directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge,
            wrongSourceComponent.rejection()->kind);
  EXPECT_EQ(0, wrongSourceComponent.rejection()->failedEdgeIndex);
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
  SCOPED_TRACE(::testing::Message()
               << "originalFailure="
               << result.diagnostics.originalSurfaceCellFailureCode
               << ";originalStage="
               << result.diagnostics.originalSurfaceCellFailureStage
               << ";originalDetail="
               << result.diagnostics.originalSurfaceCellFailureDetailCode
               << ";firstProducerStage="
               << result.diagnostics.surfaceCellFirstInvalidProducerStage
               << ";firstProducerReason="
               << result.diagnostics.surfaceCellFirstInvalidProducerReason);
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

  // RA-43.1: independently confirm that A4's actually produced terminal
  // contact paths use A1's source-matched transports, not a caller-labelled
  // star or a hard-rail carrier masquerading as a non-hard path step.
  ASSERT_TRUE(context.productSnapshots.fieldTransportAtlas.has_value());
  ASSERT_TRUE(context.productSnapshots.sourceTopologyRegions.has_value());
  const auto &atlas = *context.productSnapshots.fieldTransportAtlas;
  const auto &regions = *context.productSnapshots.sourceTopologyRegions;
  const auto &certificates =
      context.productSnapshots.traceNetwork.phaseFront.product()
          .hardRailRouteCertificates();
  ASSERT_FALSE(certificates.empty());
  // Independent A1 authority, not hard-coded fixture edge IDs: every
  // published A4 hard carrier must be classified by the source atlas.
  std::set<directional::authority::SourceEdgeTopologyKey> producerHardEdges;
  for (const auto &barrier : atlas.nontraversable_edges()) {
    if (barrier.kind ==
        directional::authority::FieldTransportBarrierKind::HardFeature) {
      producerHardEdges.insert(barrier.sourceEdge);
    }
  }
  ASSERT_FALSE(producerHardEdges.empty());
  EXPECT_EQ(producerHardEdges,
            context.productSnapshots.traceNetwork.phaseFront.product()
                .hardFeatureEdges());
  const auto &carrierTransitions =
      context.productSnapshots.traceNetwork.phaseFront.product()
          .hardRailFieldTransitions();
  std::set<directional::authority::SourceEdgeTopologyKey> verifiedCarriers;
  for (const auto &carrier : carrierTransitions) {
    EXPECT_TRUE(verifiedCarriers.insert(carrier.edge).second)
        << "each A4 hard carrier must publish one directed A3 receipt";
    EXPECT_EQ(1U, producerHardEdges.count(carrier.edge));
    const auto first = regions.row_for_topology(carrier.firstFace);
    const auto second = regions.row_for_topology(carrier.secondFace);
    ASSERT_TRUE(first.has_value());
    ASSERT_TRUE(second.has_value());
    const auto a1 = atlas.transition_value(carrier.edge, *first, *second);
    ASSERT_TRUE(a1.has_value());
    EXPECT_EQ(a1->transport, carrier.firstToSecond)
        << "hard-rail A3 crossing must originate in A1, not A4";
  }
  EXPECT_EQ(producerHardEdges, verifiedCarriers);
  std::size_t authenticatedContactSteps = 0U;
  std::size_t authenticatedJunctions = 0U;
  std::size_t authenticatedJunctionSteps = 0U;
  for (const auto &certificate : certificates) {
    for (const auto &endpoint : certificate.endpoints) {
      ASSERT_TRUE(endpoint.terminalVertex.has_value());
      const auto terminal = *endpoint.terminalVertex;
      EXPECT_EQ(1U, producerHardEdges.count(endpoint.terminalCarrier.edge))
          << "A4 terminal carrier must be a genuine A1 hard edge";
      EXPECT_TRUE(endpoint.terminalCarrier.edge.first() == terminal ||
                  endpoint.terminalCarrier.edge.second() == terminal);
      for (std::size_t side = 0U; side < endpoint.contactPaths.size(); ++side) {
        const auto &path = endpoint.contactPaths[side];
        auto at = side == 0U ? endpoint.firstAttachment
                            : endpoint.secondAttachment;
        std::set<directional::authority::SourceFaceTopologyKey> seen{at};
        for (const auto &step : path) {
          EXPECT_EQ(at, step.firstFace)
              << "terminal A4 contact path must remain face-contiguous";
          EXPECT_TRUE(step.edge.first() == terminal ||
                      step.edge.second() == terminal)
              << "terminal star step must touch the certified source vertex";
          EXPECT_TRUE(seen.insert(step.secondFace).second)
              << "terminal contact path cannot revisit a source face";
          EXPECT_EQ(0U, producerHardEdges.count(step.edge))
              << "terminal source-star transport crossed an A1 hard carrier";
          const auto first = regions.row_for_topology(step.firstFace);
          const auto second = regions.row_for_topology(step.secondFace);
          ASSERT_TRUE(first.has_value());
          ASSERT_TRUE(second.has_value());
          const auto directed = atlas.transition_value(step.edge, *first, *second);
          ASSERT_TRUE(directed.has_value());
          EXPECT_EQ(step.firstToSecond, directed->transport);
          at = step.secondFace;
          ++authenticatedContactSteps;
        }
        EXPECT_EQ(at, side == 0U ? endpoint.terminalCarrier.firstFace
                                : endpoint.terminalCarrier.secondFace)
            << "A4 contact path must terminate at its certified carrier face";
      }
    }
    // The genuine two-edge midline rail must also publish an A4 junction.
    // Its two disjoint sector walks must be source-incidental, face-contiguous,
    // loop-free, and transport-authenticated against the independent A1 atlas.
    const auto routeSteps = certificate.route.oriented_steps();
    ASSERT_EQ(certificate.junctions.size() + 1U, routeSteps.size());
    auto previous = certificate.endpoints[0].terminalCarrier;
    for (std::size_t index = 0U; index < certificate.junctions.size(); ++index) {
      const auto &junction = certificate.junctions[index];
      const auto &nextEdge = routeSteps[index + 1U].topology();
      ASSERT_EQ(previous.edge, routeSteps[index].topology());
      EXPECT_NE(previous.edge, nextEdge);
      EXPECT_EQ(1U, producerHardEdges.count(nextEdge));
      EXPECT_TRUE(previous.edge.first() == junction.junction ||
                  previous.edge.second() == junction.junction);
      EXPECT_TRUE(nextEdge.first() == junction.junction ||
                  nextEdge.second() == junction.junction);
      std::array<directional::authority::SourceFaceTopologyKey, 2> at{
          previous.firstFace, previous.secondFace};
      std::array<directional::authority::QuarterTurn, 2> phi{
          directional::authority::QuarterTurn::from_integer(0),
          directional::authority::QuarterTurn::from_integer(0)};
      std::array<std::set<directional::authority::SourceFaceTopologyKey>, 2> used{
          std::set<directional::authority::SourceFaceTopologyKey>{at[0]},
          std::set<directional::authority::SourceFaceTopologyKey>{at[1]}};
      for (std::size_t side = 0U; side < 2U; ++side) {
        for (const auto &step : junction.sectorPaths[side]) {
          EXPECT_EQ(at[side], step.firstFace);
          EXPECT_TRUE(step.edge.first() == junction.junction ||
                      step.edge.second() == junction.junction);
          EXPECT_EQ(0U, producerHardEdges.count(step.edge));
          EXPECT_TRUE(used[side].insert(step.secondFace).second)
              << "the A4 junction sector cannot repeat a source face";
          const auto first = regions.row_for_topology(step.firstFace);
          const auto second = regions.row_for_topology(step.secondFace);
          ASSERT_TRUE(first.has_value());
          ASSERT_TRUE(second.has_value());
          const auto a1 = atlas.transition_value(step.edge, *first, *second);
          ASSERT_TRUE(a1.has_value());
          EXPECT_EQ(a1->transport, step.firstToSecond);
          phi[side] = compose(step.firstToSecond, phi[side]);
          at[side] = step.secondFace;
          ++authenticatedJunctionSteps;
        }
      }
      for (const auto &face : used[0])
        EXPECT_EQ(0U, used[1].count(face))
            << "the two A4 junction sectors must be disjoint";
      const auto found = std::find_if(
          carrierTransitions.begin(), carrierTransitions.end(),
          [&](const auto &item) { return item.edge == nextEdge; });
      ASSERT_NE(found, carrierTransitions.end());
      auto next = *found;
      if (next.firstFace != at[0] || next.secondFace != at[1]) {
        next = {next.edge, next.secondFace, next.firstFace,
                next.firstToSecond.inverse()};
      }
      EXPECT_EQ(at[0], next.firstFace);
      EXPECT_EQ(at[1], next.secondFace);
      EXPECT_EQ(compose(next.firstToSecond, phi[0]),
                compose(phi[1], previous.firstToSecond))
          << "the multi-carrier junction must satisfy A1's commuting square";
      previous = next;
      ++authenticatedJunctions;
    }
    EXPECT_EQ(previous, certificate.endpoints[1].terminalCarrier);
  }
  EXPECT_GT(authenticatedContactSteps, 0U)
      << "the A4 consumer must publish a real non-hard source-star step";
  EXPECT_GT(authenticatedJunctions, 0U)
      << "this fixture must reach an actual produced multi-carrier junction";
  EXPECT_GT(authenticatedJunctionSteps, 0U)
      << "the produced junction must publish a nonempty non-hard sector walk";

  // The tested rail producer must publish raw source-edge IDs for the same
  // original source topology as its independently carried vertex chain.
  directional::TriMesh sourceMesh;
  sourceMesh.set_mesh(mesh.vertices, mesh.faces);

  // RA-43.1: exercise the actual A1 vertex-transit producer at the A4
  // junction, with the source atlas's own hard-carrier barriers. A4's
  // contact-path comparison above does not establish this independent germ.
  const auto &branchTopology = atlas.branch_topology();
  using EdgeKey = directional::authority::SourceEdgeTopologyKey;
  using FaceKey = directional::authority::SourceFaceTopologyKey;
  using Barrier = directional::authority::FieldNonTraversableEdge;
  std::map<EdgeKey, const Barrier *> sourceBarriers;
  for (const auto &barrier : atlas.nontraversable_edges()) {
    ASSERT_TRUE(sourceBarriers.emplace(barrier.sourceEdge, &barrier).second);
  }
  std::size_t examinedGermPaths = 0U;
  std::size_t germOwners = 0U;
  for (const auto &certificate : certificates) {
    for (const auto &junction : certificate.junctions) {
      for (const auto &sector : junction.sectorPaths) {
        if (sector.empty()) continue;
        const FaceKey seedFace = sector.front().firstFace;
        const auto *frame = branchTopology.find_frame(seedFace);
        ASSERT_NE(frame, nullptr);
        const auto faceRow = regions.row_for_topology(seedFace);
        ASSERT_TRUE(faceRow.has_value());
        for (const auto &pairing : frame->branches) {
          auto outward = pairing.direction;
          if (!outward.is_barycentric()) continue;
          for (auto &coordinate : outward.barycentric) coordinate = -coordinate;
          if (!directional::authority::direction_in_closed_vertex_wedge(
                  sourceMesh, *faceRow, junction.junction, outward)) continue;
          const auto transit = directional::geometry::surface_cell_tracing_detail::
              resolve_field_vertex_transit(
                  sourceMesh, branchTopology, frame->sourceComponent,
                  frame->topologyRegion, seedFace, pairing.branch,
                  junction.junction,
                  directional::geometry::FieldVertexArrivalMode::FaceInterior,
                  std::nullopt, std::nullopt, &sourceBarriers);
          if (std::holds_alternative<directional::geometry::
                  surface_cell_tracing_detail::FieldVertexTransitDecision>(transit)) {
            ++germOwners;
            continue;
          }
          const auto &rejection = std::get<directional::geometry::
              FieldAlignedCurveNetworkError>(transit);
          for (const auto &state : rejection.vertexTransitStates) {
            if (state.outcome != directional::geometry::
                    FieldVertexTransitStateOutcome::Evaluated ||
                state.transportPath.empty()) continue;
            FaceKey walkFace = seedFace;
            int signedLift = 0;
            for (const EdgeKey &edge : state.transportPath) {
              EXPECT_EQ(0U, producerHardEdges.count(edge))
                  << "the direct A1 germ crossed an actual hard carrier";
              const auto adjacency = std::find_if(
                  branchTopology.transports().begin(),
                  branchTopology.transports().end(),
                  [&](const auto &item) {
                    return item.sourceEdge == edge &&
                           (item.firstFace == walkFace ||
                            item.secondFace == walkFace);
                  });
              ASSERT_NE(adjacency, branchTopology.transports().end());
              const FaceKey nextFace = adjacency->firstFace == walkFace
                                           ? adjacency->secondFace
                                           : adjacency->firstFace;
              const auto directed = branchTopology.transport(edge, walkFace,
                                                              nextFace);
              ASSERT_TRUE(directed.has_value());
              signedLift += directed->signedLift;
              walkFace = nextFace;
            }
            EXPECT_EQ(state.sourceFace, walkFace);
            EXPECT_EQ(((signedLift % 4) + 4) % 4,
                      state.composedQuarterTurn);
            EXPECT_EQ(pairing.branch.rotated(signedLift), state.branch);
            ++examinedGermPaths;
          }
        }
      }
    }
  }
  EXPECT_GT(germOwners + examinedGermPaths, 0U)
      << "the produced multi-carrier junction must exercise an authentic "
         "A1 vertex-transit germ";

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
    // Producer-issued vertex ordering must describe the same source edges
    // as each paired interval's face-local edge, not inferred sample positions.
    ASSERT_EQ(rail.samples.size(), 2U * rail.sourceEdges.size());
    ASSERT_EQ(rail.sourceVertices.size(),
              rail.sourceEdges.size() + (rail.closed ? 0U : 1U));
    ASSERT_FALSE(rail.sourceVertices.empty());
    for (std::size_t interval = 0; interval < rail.sourceEdges.size(); ++interval) {
      const auto &start = rail.samples[2U * interval];
      const auto &end = rail.samples[2U * interval + 1U];
      ASSERT_GE(start.sourceFace, 0);
      ASSERT_LT(start.sourceFace, mesh.faces.rows());
      ASSERT_GE(start.sourceEdge, 0);
      ASSERT_LT(start.sourceEdge, 3);
      EXPECT_EQ(start.sourceFace, end.sourceFace);
      EXPECT_EQ(start.sourceEdge, end.sourceEdge);
      const int first = rail.sourceVertices[interval];
      const int second = rail.sourceVertices[(interval + 1U) %
                                            rail.sourceVertices.size()];
      const int edgeFirst = mesh.faces(start.sourceFace, (start.sourceEdge + 1) % 3);
      const int edgeSecond = mesh.faces(start.sourceFace, (start.sourceEdge + 2) % 3);
      EXPECT_TRUE((first == edgeFirst && second == edgeSecond) ||
                  (first == edgeSecond && second == edgeFirst));
      const auto expected = directional::authority::SourceEdgeTopologyKey::from_indices(
          first, second, static_cast<std::size_t>(sourceMesh.V.rows()));
      ASSERT_TRUE(expected);
      EXPECT_EQ(rail.sourceEdges[interval], expected.value());
    }
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


// R4 RA-43.1/D2: the odd A3 carrier and the adjacent A1 germ must be
// published by the SAME nonconstant, producer-generated two-carrier rail.
// A standalone odd singleton cannot discharge this combined witness.
TEST(SurfaceCellPipelinePhase20,
     ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm) {
  const REPkgMesh mesh = make_rectangular_internal_hard_feature_grid();
  Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  // Preserve the real geometric face field under source face-row permutations.
  // The right source component carries the quarter-turned gauge; the source
  // midline remains the two real hard carriers (1,4) and (4,7).
  for (int row = 0; row < mesh.faces.rows(); ++row) {
    double centerX = 0.0;
    for (int corner = 0; corner < 3; ++corner)
      centerX += mesh.vertices(mesh.faces(row, corner), 0);
    if (centerX / 3.0 > 1.0) {
      raw.row(row) << 0.0, 1.0, 0.0, -1.0, 0.0, 0.0,
          0.0, -1.0, 0.0, 1.0, 0.0, 0.0;
    }
  }
  auto options = surface_options();
  options.surfaceCells.featureMap.userHardEdges.insert({1, 4});
  options.surfaceCells.featureMap.userHardEdges.insert({4, 7});
  options.surfaceCells.injectFailureAfterStage = 6;
  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  SCOPED_TRACE(::testing::Message()
               << "terminal=" << result.diagnostics.terminalFailureCode
               << ";firstProducer="
               << result.diagnostics.surfaceCellFirstInvalidProducerStage
               << ";reason="
               << result.diagnostics.surfaceCellFirstInvalidProducerReason);
  ASSERT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &snapshot = result.surfaceCellContext.productSnapshots;
  ASSERT_TRUE(snapshot.fieldTransportAtlas.has_value());
  ASSERT_TRUE(snapshot.sourceTopologyRegions.has_value());
  ASSERT_TRUE(snapshot.traceNetwork.phaseFront.is_produced());
  const auto &front = snapshot.traceNetwork.phaseFront.product();
  const auto &atlas = *snapshot.fieldTransportAtlas;
  const auto &regions = *snapshot.sourceTopologyRegions;
  const auto &topology = atlas.branch_topology();
  using Edge = directional::authority::SourceEdgeTopologyKey;
  using Turn = directional::authority::QuarterTurn;
  using Decision = directional::geometry::surface_cell_tracing_detail::
      FieldVertexTransitDecision;
  using Barrier = directional::authority::FieldNonTraversableEdge;
  const auto a = Edge::from_indices(1, 4,
                                   static_cast<std::size_t>(mesh.vertices.rows()));
  const auto b = Edge::from_indices(4, 7,
                                   static_cast<std::size_t>(mesh.vertices.rows()));
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  std::map<Edge, const Barrier *> sourceBarriers;
  for (const auto &barrier : atlas.nontraversable_edges())
    ASSERT_TRUE(sourceBarriers.emplace(barrier.sourceEdge, &barrier).second);
  ASSERT_TRUE(sourceBarriers.count(a.value()));
  ASSERT_TRUE(sourceBarriers.count(b.value()));
  EXPECT_EQ(directional::authority::FieldTransportBarrierKind::HardFeature,
            sourceBarriers.at(a.value())->kind);
  EXPECT_EQ(directional::authority::FieldTransportBarrierKind::HardFeature,
            sourceBarriers.at(b.value())->kind);

  const auto &routes = front.hardRailRouteCertificates();
  const auto route = std::find_if(routes.begin(), routes.end(),
                                  [&](const auto &cert) {
    const auto edges = cert.route.oriented_steps();
    return edges.size() == 2U &&
           ((edges[0].topology() == a.value() && edges[1].topology() == b.value()) ||
            (edges[0].topology() == b.value() && edges[1].topology() == a.value()));
  });
  ASSERT_NE(routes.end(), route)
      << "odd-tau proof needs an A4-produced TWO-carrier certificate";
  ASSERT_EQ(1U, route->junctions.size());
  const auto junction = route->junctions.front().junction;
  EXPECT_EQ(4, static_cast<int>(junction.index()));
  bool oddCarrier = false;
  // The two terminal certificates must account for BOTH independent source
  // carriers; a duplicated terminal for only one edge is not a paired proof.
  std::set<Edge> terminalCarrierEdges;
  for (const auto &endpoint : route->endpoints) {
    const auto &carrier = endpoint.terminalCarrier;
    EXPECT_TRUE(terminalCarrierEdges.insert(carrier.edge).second);
    const auto first = regions.row_for_topology(carrier.firstFace);
    const auto second = regions.row_for_topology(carrier.secondFace);
    ASSERT_TRUE(first.has_value());
    ASSERT_TRUE(second.has_value());
    const auto a1 = atlas.transition_value(carrier.edge, *first, *second);
    ASSERT_TRUE(a1.has_value());
    EXPECT_EQ(a1->transport, carrier.firstToSecond);
    oddCarrier = oddCarrier ||
        carrier.firstToSecond == Turn::from_integer(1) ||
        carrier.firstToSecond == Turn::from_integer(3);
  }
  EXPECT_EQ((std::set<Edge>{a.value(), b.value()}), terminalCarrierEdges)
      << "both produced rail carriers need distinct endpoint certificates";
  EXPECT_TRUE(oddCarrier)
      << "the real paired A4 carrier must have odd tau in its A1 gauge";

  directional::TriMesh source;
  source.set_mesh(mesh.vertices, mesh.faces);
  std::size_t evaluatedNontrivialGerms = 0U;
  std::size_t verifiedOwners = 0U;
  for (const auto &sector : route->junctions.front().sectorPaths) {
    if (sector.empty()) continue;
    const auto seedFace = sector.front().firstFace;
    const auto *frame = topology.find_frame(seedFace);
    ASSERT_NE(nullptr, frame);
    const auto row = regions.row_for_topology(seedFace);
    ASSERT_TRUE(row.has_value());
    for (const auto &pairing : frame->branches) {
      auto arrival = pairing.direction;
      if (!arrival.is_barycentric()) continue;
      for (auto &coordinate : arrival.barycentric) coordinate = -coordinate;
      if (!directional::authority::direction_in_closed_vertex_wedge(
              source, *row, junction, arrival)) continue;
      const auto transit = directional::geometry::surface_cell_tracing_detail::
          resolve_field_vertex_transit(
              source, topology, frame->sourceComponent, frame->topologyRegion,
              seedFace, pairing.branch, junction,
              directional::geometry::FieldVertexArrivalMode::FaceInterior,
              std::nullopt, std::nullopt, &sourceBarriers);
      if (const auto *decision = std::get_if<Decision>(&transit)) {
        ASSERT_TRUE(decision->vertexStarTransit.has_value());
        const auto &audit = *decision->vertexStarTransit;
        ASSERT_TRUE(audit.seed.has_value());
        EXPECT_EQ(junction, audit.seed->sourceVertex);
        EXPECT_EQ(seedFace, audit.seed->arrivalFace);
        EXPECT_EQ(pairing.branch, audit.seed->arrivalBranch);
        EXPECT_EQ(directional::geometry::FieldVertexArrivalMode::FaceInterior,
                  audit.seed->arrivalMode);
        EXPECT_EQ(directional::geometry::VertexStarTransitState::Owner,
                  audit.state);
        EXPECT_EQ(1U, audit.ownerCardinality);
        EXPECT_EQ(decision->nextFace, audit.ownerFace);
        EXPECT_EQ(decision->nextBranch, audit.ownerBranch);
        EXPECT_GT(audit.fanLength, 1U);
        ASSERT_EQ(audit.fanLength, audit.sectors.size());
        // Reconstruct the admitted fan independently from A1 source faces.
        // The owner cannot be credited if its ordered sectors cross a hard
        // carrier (or any other atlas-owned nontraversable edge).
        const auto authenticatedFanLink = [&](std::size_t from,
                                              std::size_t to) {
          const auto &firstSector = audit.sectors[from];
          const auto &secondSector = audit.sectors[to];
          EXPECT_EQ(firstSector.previousRadialVertex,
                    secondSector.nextRadialVertex);
          const auto radial = Edge::make(junction,
                                         firstSector.previousRadialVertex);
          ASSERT_TRUE(radial.has_value());
          EXPECT_FALSE(sourceBarriers.contains(radial.value()));
          EXPECT_FALSE(front.hardFeatureEdges().contains(radial.value()));
          const auto directed = topology.transport(
              radial.value(), firstSector.sourceFace, secondSector.sourceFace);
          ASSERT_TRUE(directed.has_value());
          EXPECT_EQ(firstSector.branch.rotated(directed->signedLift),
                    secondSector.branch);
        };
        for (const auto &fanSector : audit.sectors) {
          const auto *fanFrame = topology.find_frame(fanSector.sourceFace);
          ASSERT_NE(nullptr, fanFrame);
          EXPECT_EQ(frame->sourceComponent, fanFrame->sourceComponent);
          EXPECT_EQ(frame->topologyRegion, fanFrame->topologyRegion);
          const auto &corners = fanSector.sourceFace.vertices();
          EXPECT_NE(corners.end(),
                    std::find(corners.begin(), corners.end(), junction));
        }
        for (std::size_t i = 1U; i < audit.sectors.size(); ++i)
          authenticatedFanLink(i - 1U, i);
        if (audit.closedFan && !audit.sectors.empty())
          authenticatedFanLink(audit.sectors.size() - 1U, 0U);
        ++verifiedOwners;
      } else {
        const auto &error = std::get<
            directional::geometry::FieldAlignedCurveNetworkError>(transit);
        for (const auto &state : error.vertexTransitStates) {
          if (state.outcome != directional::geometry::
                   FieldVertexTransitStateOutcome::Evaluated ||
              state.transportPath.empty()) continue;
          // Independently authenticate the reported diagnostic walk against
          // A1's directed source-face adjacency. An arbitrary nonempty path
          // cannot count as the same producer-bound vertex germ.
          auto walkFace = seedFace;
          int accumulatedSignedLift = 0;
          for (const auto &edge : state.transportPath) {
            EXPECT_NE(a.value(), edge);
            EXPECT_NE(b.value(), edge);
            EXPECT_FALSE(front.hardFeatureEdges().contains(edge));
            EXPECT_TRUE(edge.first() == junction ||
                        edge.second() == junction);
            const auto adjacency = std::find_if(
                topology.transports().begin(), topology.transports().end(),
                [&](const auto &item) {
                  return item.sourceEdge == edge &&
                         (item.firstFace == walkFace ||
                          item.secondFace == walkFace);
                });
            ASSERT_NE(topology.transports().end(), adjacency);
            const auto nextFace = adjacency->firstFace == walkFace
                                      ? adjacency->secondFace
                                      : adjacency->firstFace;
            const auto directed = topology.transport(edge, walkFace, nextFace);
            ASSERT_TRUE(directed.has_value());
            accumulatedSignedLift += directed->signedLift;
            walkFace = nextFace;
          }
          EXPECT_EQ(walkFace, state.sourceFace);
          EXPECT_EQ(((accumulatedSignedLift % 4) + 4) % 4,
                    state.composedQuarterTurn);
          EXPECT_EQ(pairing.branch.rotated(accumulatedSignedLift), state.branch);
          ++evaluatedNontrivialGerms;
        }
      }
    }
  }
  // An evaluated path attached to a rejected resolver result is diagnostic
  // evidence, not an admitted vertex-star transit. A positive coupled
  // odd-tau/germ witness must have an elected source-authoritative owner.
  EXPECT_GT(verifiedOwners, 0U)
      << "the paired odd carrier has no admitted A1 vertex-star owner; "
      << "nontrivial rejected diagnostic walks=" << evaluatedNontrivialGerms;
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
  SCOPED_TRACE(::testing::Message()
               << "originalFailure="
               << result.diagnostics.originalSurfaceCellFailureCode
               << ";originalStage="
               << result.diagnostics.originalSurfaceCellFailureStage
               << ";originalDetail="
               << result.diagnostics.originalSurfaceCellFailureDetailCode
               << ";firstProducerStage="
               << result.diagnostics.surfaceCellFirstInvalidProducerStage
               << ";firstProducerReason="
               << result.diagnostics.surfaceCellFirstInvalidProducerReason);
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

// RA-47.12 source oracle: reach the field-aligned producer on the ordinary
// un-injected pipeline, not only in the stage-3 failure-injection diagnostic.
// This is compile-only until the separately authorized runtime gate.
TEST(SurfaceCellFieldAlignedNetworkAuthority,
     DefaultPipelinePublishesSourceBoundMandatoryRailKeysWithoutInjection) {
  const REPkgMesh mesh = make_rectangular_internal_hard_feature_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.featureMap.userHardEdges.insert({1, 4});
  options.surfaceCells.featureMap.userHardEdges.insert({4, 7});
  // Deliberately do not set injectFailureAfterStage.
  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  SCOPED_TRACE(::testing::Message()
               << "terminal=" << result.diagnostics.terminalFailureCode
               << ";stage=" << result.diagnostics.terminalFailureStage
               << ";firstProducer="
               << result.diagnostics.surfaceCellFirstInvalidProducerStage
               << ";reason="
               << result.diagnostics.surfaceCellFirstInvalidProducerReason);
  const auto &context = result.surfaceCellContext;
  const auto &snapshots = context.productSnapshots;
  EXPECT_TRUE(context.fieldAlignedNetworkAuthorityUsed);
  EXPECT_FALSE(context.rawSingularityProjectionUsed);
  ASSERT_TRUE(snapshots.hasAuthoritativeRails);
  ASSERT_TRUE(snapshots.fieldAlignedCurveNetwork.has_value());
  const auto &network = *snapshots.fieldAlignedCurveNetwork;
  ASSERT_FALSE(network.mandatory_edges().empty());
  ASSERT_FALSE(snapshots.authoritativeRails.empty());

  const auto first = directional::authority::SourceEdgeTopologyKey::from_indices(
      1, 4, static_cast<std::size_t>(mesh.vertices.rows()));
  const auto second = directional::authority::SourceEdgeTopologyKey::from_indices(
      4, 7, static_cast<std::size_t>(mesh.vertices.rows()));
  ASSERT_TRUE(first.has_value());
  ASSERT_TRUE(second.has_value());
  bool sawFirst = false;
  bool sawSecond = false;
  std::size_t authenticatedHardIntervals = 0;
  for (const auto &rail : snapshots.authoritativeRails) {
    if (rail.kind != directional::geometry::SurfaceCellRailKind::HardFeature)
      continue;
    ASSERT_FALSE(rail.sourceEdges.empty());
    for (const auto &edge : rail.sourceEdges) {
      const auto *mandatory = network.find_mandatory_edge(edge);
      ASSERT_NE(nullptr, mandatory)
          << "default pipeline discarded a producer-published typed rail key";
      EXPECT_EQ(rail.id, mandatory->rail);
      EXPECT_EQ(rail.kind, mandatory->kind);
      sawFirst = sawFirst || edge == first.value();
      sawSecond = sawSecond || edge == second.value();
      ++authenticatedHardIntervals;
    }
  }
  EXPECT_GT(authenticatedHardIntervals, 0U);
  EXPECT_TRUE(sawFirst);
  EXPECT_TRUE(sawSecond);
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
  rail.sourceVertices = {0, 3};
  rail.sourceEdges = {directional::authority::SourceEdgeTopologyKey::from_indices(
      0, 3, static_cast<std::size_t>(mesh.vertices.rows())).value()};
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
