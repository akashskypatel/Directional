#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/GlobalConformityBaseline.h>
#include <directional/geometry/GlobalTopologyPlan.h>
#include <directional/geometry/SourceTopologyRegions.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfaceCutGraph.h>

#include "../src/geometry/GlobalConformityParityGraph.h"

namespace {

using directional::TriMesh;
using directional::authority::FieldExactRational;
using directional::authority::HardRailId;
using directional::authority::SourceEdgeTopologyKey;
using directional::authority::SourceVertexId;
using directional::fields::CrossFieldEdgeTransition;
using directional::fields::CrossFieldResult;
using directional::geometry::BaselineConformityIncidence;
using directional::geometry::ConformityEdgePoint;
using directional::geometry::ConformitySpanId;
using directional::geometry::ConformitySpanInput;
using directional::geometry::FieldAlignedCurveNetwork;
using directional::geometry::GlobalConformityBaselineInput;
using directional::geometry::GlobalConformityBaselinePlan;
using directional::geometry::GlobalTopologyArcKind;
using directional::geometry::GlobalTopologyPlan;
using directional::geometry::SourceTopologyRegions;
using directional::geometry::SurfaceCellRail;
using directional::geometry::SurfaceCellRailKind;
using directional::geometry::SurfaceCellTracingOptions;
using directional::geometry::global_conformity_baseline_detail::ParityFixedChoices;
using directional::geometry::global_conformity_baseline_detail::ParityGraphProblem;

TriMesh make_square_mesh() {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

TriMesh make_triangle_mesh() {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

SourceEdgeTopologyKey edge_key(const TriMesh &mesh, int edge) {
  return SourceEdgeTopologyKey::from_indices(
             mesh.EV(edge, 0), mesh.EV(edge, 1),
             static_cast<std::size_t>(mesh.V.rows()))
      .value();
}

int source_edge_index(const TriMesh &mesh,
                      const SourceEdgeTopologyKey &sourceEdge) {
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (edge_key(mesh, edge) == sourceEdge) return edge;
  }
  return -1;
}

CrossFieldResult make_zero_transport_field(const TriMesh &mesh) {
  CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.matching = Eigen::VectorXi::Zero(mesh.EV.rows());
  field.effort = Eigen::VectorXd::Zero(mesh.EV.rows());
  field.matchingComputed = true;
  field.singularitiesComputed = true;
  field.singularCycles.resize(0);
  field.singularIndices.resize(0);
  field.primaryDirections.resize(mesh.F.rows(), 3);
  field.secondaryDirections.resize(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    field.primaryDirections.row(face) = Eigen::RowVector3d::UnitX();
    field.secondaryDirections.row(face) = Eigen::RowVector3d::UnitY();
  }
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    field.edgeTransitions.push_back(CrossFieldEdgeTransition{
        edge, mesh.EV(edge, 0), mesh.EV(edge, 1), mesh.EF(edge, 0),
        mesh.EF(edge, 1), 0, 0.0});
  }
  return field;
}

std::optional<SourceTopologyRegions> make_source_authority(const TriMesh &mesh) {
  SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  return directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(mesh.F, options);
}

std::vector<SurfaceCellRail> rails_from_atlas(
    const TriMesh &mesh,
    const directional::authority::FieldTransportAtlas &atlas) {
  std::vector<SurfaceCellRail> rails;
  for (const auto &barrier : atlas.nontraversable_edges()) {
    if (barrier.kind !=
            directional::authority::FieldTransportBarrierKind::SourceBoundary &&
        barrier.kind !=
            directional::authority::FieldTransportBarrierKind::HardFeature) {
      continue;
    }
    SurfaceCellRail rail(HardRailId::from_index(
                             static_cast<std::int64_t>(rails.size()),
                             atlas.nontraversable_edges().size())
                             .value());
    rail.kind = barrier.kind ==
                        directional::authority::FieldTransportBarrierKind::HardFeature
                    ? SurfaceCellRailKind::HardFeature
                    : SurfaceCellRailKind::Boundary;
    rail.component = 777;
    rail.sourceVertices = {
        static_cast<int>(barrier.sourceEdge.first().index()),
        static_cast<int>(barrier.sourceEdge.second().index())};
    rail.sourceEdges = {source_edge_index(mesh, barrier.sourceEdge)};
    rails.push_back(std::move(rail));
  }
  return rails;
}

struct TopologyFixture {
  TriMesh mesh;
  GlobalTopologyPlan topology;
};

TopologyFixture make_topology_fixture(TriMesh mesh) {
  const auto sourceAuthority = make_source_authority(mesh);
  if (!sourceAuthority) throw std::runtime_error("source authority fixture failed");
  auto atlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_zero_transport_field(mesh));
  if (!atlas) throw std::runtime_error("field atlas fixture failed");
  const auto rails = rails_from_atlas(mesh, atlas.value());
  auto network = FieldAlignedCurveNetwork::make(
      mesh, *sourceAuthority, atlas.value(), rails);
  if (!network) throw std::runtime_error("network fixture failed");
  auto cutGraph = directional::geometry::SurfaceCutGraph::make(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      atlas.value(), network.value());
  if (!cutGraph) throw std::runtime_error("cut graph fixture failed");
  auto topology = GlobalTopologyPlan::make(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      network.value(), cutGraph.value());
  if (!topology) throw std::runtime_error("topology fixture failed");
  return {std::move(mesh), std::move(topology.value())};
}

SourceEdgeTopologyKey find_edge(const TriMesh &mesh, int first, int second) {
  return SourceEdgeTopologyKey::from_indices(
             first, second, static_cast<std::size_t>(mesh.V.rows()))
      .value();
}

ConformitySpanInput one_piece_span(ConformitySpanId span,
                                   SourceEdgeTopologyKey edge) {
  return {span,
          {{directional::authority::SourceEdgeSupport{edge}, edge.first(),
            edge.second()}}};
}

GlobalConformityBaselineInput make_baseline_input(
    const TopologyFixture &fixture, double targetSize,
    std::optional<std::size_t> diagonalSpan = std::nullopt,
    bool twoPieceFirst = false) {
  GlobalConformityBaselineInput input;
  input.sourceVertices = fixture.mesh.V;
  input.targetSize = Eigen::VectorXd::Constant(fixture.mesh.V.rows(), targetSize);

  std::vector<directional::authority::NetworkArcId> arcs;
  for (const auto &arc : fixture.topology.arcs()) arcs.push_back(arc.id);
  std::sort(arcs.begin(), arcs.end());

  const auto unit = find_edge(fixture.mesh, 0, 1);
  SourceEdgeTopologyKey diagonal = unit;
  if (fixture.mesh.V.rows() >= 3) diagonal = find_edge(fixture.mesh, 0, 2);

  for (std::size_t index = 0U; index < arcs.size(); ++index) {
    const auto id = ConformitySpanId::from_network_arc(arcs[index]);
    const auto carrier = diagonalSpan && *diagonalSpan == index ? diagonal : unit;
    auto span = one_piece_span(id, carrier);
    if (twoPieceFirst && index == 0U) {
      const auto midpoint = ConformityEdgePoint{
          carrier, *FieldExactRational::from_ratio(1, 2)};
      span.supportPieces = {
          {directional::authority::SourceEdgeSupport{carrier}, carrier.first(),
           midpoint},
          {directional::authority::SourceEdgeSupport{carrier}, midpoint,
           carrier.second()}};
    }
    input.spans.push_back(std::move(span));
  }
  return input;
}

std::vector<int> exact_counts(const GlobalConformityBaselinePlan &plan) {
  std::vector<int> out;
  for (const auto &entry : plan.schedule()) {
    out.push_back(std::stoi(entry.count.to_string()));
  }
  return out;
}

struct ExhaustiveParityAnswer {
  int flips = 0;
  std::vector<int> counts;
};

ExhaustiveParityAnswer exhaustive_terminal_parity_oracle(
    const std::vector<int> &preferred) {
  bool haveBest = false;
  ExhaustiveParityAnswer best;
  const std::size_t combinations = std::size_t{1} << preferred.size();
  for (std::size_t mask = 0U; mask < combinations; ++mask) {
    int flipCount = 0;
    int parity = 0;
    std::vector<int> counts;
    for (std::size_t span = 0U; span < preferred.size(); ++span) {
      const bool flip = ((mask >> span) & 1U) != 0U;
      flipCount += flip ? 1 : 0;
      const int count = !flip ? preferred[span]
                              : (preferred[span] > 1 ? preferred[span] - 1 : 2);
      counts.push_back(count);
      parity ^= count & 1;
    }
    if (parity != 0) continue;
    if (!haveBest || flipCount < best.flips ||
        (flipCount == best.flips && counts < best.counts)) {
      best = {flipCount, counts};
      haveBest = true;
    }
  }
  if (!haveBest) throw std::runtime_error("exhaustive parity oracle found no witness");
  return best;
}

template <class T>
concept HasCallerSuppliedIncidences = requires(T value) { value.incidences; };

} // namespace

TEST(GlobalConformityBaseline,
     MixedMandatoryTraceCutKindsUseFamilyFreeParitySemantics) {
  const std::array kinds{GlobalTopologyArcKind::Mandatory,
                         GlobalTopologyArcKind::Trace,
                         GlobalTopologyArcKind::Cut};
  ParityGraphProblem problem;
  problem.vertexCount = 2U;
  problem.demand = {true, true};
  problem.edges = {{0U, 0U, 1U}, {1U, 0U, 1U}, {2U, 0U, 1U}};
  ParityFixedChoices fixed(kinds.size(), -1);
  const auto optimum =
      directional::geometry::global_conformity_baseline_detail::
          minimum_t_join_cardinality(problem, fixed);
  ASSERT_TRUE(optimum.has_value());
  EXPECT_EQ(EInt(1), *optimum);
  EXPECT_EQ(3U, kinds.size());
}

TEST(GlobalConformityBaseline,
     RegionParityUsesBoundaryIncidenceMultiplicity) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, make_baseline_input(fixture, 1.0));
  ASSERT_TRUE(built);
  ASSERT_EQ(1U, built.value().certificate().regions.size());
  EXPECT_TRUE(built.value().certificate().regions.front().finalParityEven);
  EXPECT_EQ(built.value().incidences().size(), fixture.topology.regions().front().boundary.size());
}

TEST(GlobalConformityBaseline,
     SameRegionDoubleIncidenceIsZeroEffectSelfLoop) {
  ParityGraphProblem problem;
  problem.vertexCount = 1U;
  problem.demand = {false};
  problem.edges = {{0U, 0U, 0U}};
  ParityFixedChoices free{static_cast<std::int8_t>(-1)};
  ParityFixedChoices selected{static_cast<std::int8_t>(1)};
  const auto freeOptimum =
      directional::geometry::global_conformity_baseline_detail::
          minimum_t_join_cardinality(problem, free);
  const auto selectedOptimum =
      directional::geometry::global_conformity_baseline_detail::
          minimum_t_join_cardinality(problem, selected);
  ASSERT_TRUE(freeOptimum.has_value());
  ASSERT_TRUE(selectedOptimum.has_value());
  EXPECT_EQ(EInt(0), *freeOptimum);
  EXPECT_EQ(EInt(1), *selectedOptimum);
}

TEST(GlobalConformityBaseline,
     OneEndedTerminalUsesComponentLocalExterior) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, make_baseline_input(fixture, 1.0));
  ASSERT_TRUE(built);
  ASSERT_EQ(1U, built.value().certificate().components.size());
  const auto &component = built.value().certificate().components.front();
  EXPECT_TRUE(component.hasExterior);
  EXPECT_TRUE(component.exteriorDemandOdd);
  EXPECT_EQ(3U, component.terminalSpans.size());
}

TEST(GlobalConformityBaseline,
     MinimumCardinalityTJoinBeatsLocalGreedyChoice) {
  ParityGraphProblem problem;
  problem.vertexCount = 6U;
  problem.demand = {true, false, true, true, false, true};
  problem.edges = {{0U, 0U, 1U}, {1U, 1U, 2U}, {2U, 2U, 3U},
                   {3U, 3U, 4U}, {4U, 4U, 5U}, {5U, 0U, 5U}};
  ParityFixedChoices fixed(problem.edges.size(), -1);
  const auto optimum =
      directional::geometry::global_conformity_baseline_detail::
          minimum_t_join_cardinality(problem, fixed);
  ASSERT_TRUE(optimum.has_value());
  EXPECT_EQ(EInt(2), *optimum);

  fixed[0] = 1;
  const auto greedyFirstEdge =
      directional::geometry::global_conformity_baseline_detail::
          minimum_t_join_cardinality(problem, fixed);
  ASSERT_TRUE(greedyFirstEdge.has_value());
  EXPECT_GT(*greedyFirstEdge, *optimum);
}

TEST(GlobalConformityBaseline,
     CanonicalLexPrefixChoosesLeastCountVectorAcrossEqualTJoins) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, make_baseline_input(fixture, 1.0));
  ASSERT_TRUE(built);
  EXPECT_EQ((std::vector<int>{1, 1, 2}), exact_counts(built.value()));
  EXPECT_EQ(EInt(1), built.value().certificate().minimumFlipCount);
}

TEST(GlobalConformityBaseline,
     ParityFlipMapsOneToTwoAndLargerToPredecessor) {
  const auto triangle = make_topology_fixture(make_triangle_mesh());
  const auto oneBuilt = directional::geometry::build_global_conformity_baseline(
      triangle.topology, make_baseline_input(triangle, 1.0));
  ASSERT_TRUE(oneBuilt);
  EXPECT_EQ(2, exact_counts(oneBuilt.value()).back());

  const auto square = make_topology_fixture(make_square_mesh());
  const auto largerBuilt = directional::geometry::build_global_conformity_baseline(
      square.topology, make_baseline_input(square, 0.5, 1U));
  ASSERT_TRUE(largerBuilt);
  ASSERT_GE(largerBuilt.value().schedule().front().preferredCount, EInt(2));
  EXPECT_EQ(largerBuilt.value().schedule().front().preferredCount - EInt(1),
            largerBuilt.value().schedule().front().count);
}

TEST(GlobalConformityBaseline,
     IndependentTinyExhaustiveOracleMatchesParityOptimumAndLexTie) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto input = make_baseline_input(fixture, 1.0);
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(built);
  std::vector<int> preferred;
  for (const auto &entry : built.value().schedule()) {
    preferred.push_back(std::stoi(entry.preferredCount.to_string()));
  }
  const auto oracle = exhaustive_terminal_parity_oracle(preferred);
  EXPECT_EQ(oracle.flips,
            std::stoi(built.value().certificate().minimumFlipCount.to_string()));
  EXPECT_EQ(oracle.counts, exact_counts(built.value()));
}

TEST(GlobalConformityBaseline,
     IndependentValidatorRejectsParityCertificateTamperMatrix) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto input = make_baseline_input(fixture, 1.0);
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(built);
  const auto baseline = built.value().validation_candidate();
  EXPECT_FALSE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, baseline));

  auto support = baseline;
  support.schedule.front().supportPieces.front().first =
      support.schedule.front().supportPieces.front().second;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, support));

  auto incidence = baseline;
  incidence.incidences.front().orientation =
      incidence.incidences.front().orientation ==
              directional::authority::Orientation::Forward
          ? directional::authority::Orientation::Reverse
          : directional::authority::Orientation::Forward;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, incidence));

  auto residual = baseline;
  residual.certificate.regions.front().preferredResidualOdd =
      !residual.certificate.regions.front().preferredResidualOdd;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, residual));

  auto demand = baseline;
  ASSERT_FALSE(demand.certificate.demandedVertices.empty());
  demand.certificate.demandedVertices.pop_back();
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, demand));

  auto flips = baseline;
  ASSERT_FALSE(flips.certificate.selectedFlips.empty());
  flips.certificate.selectedFlips.clear();
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, flips));

  auto optimum = baseline;
  optimum.certificate.minimumFlipCount += EInt(1);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, optimum));

  auto lex = baseline;
  lex.certificate.lexReceipts.front().selectedFlip =
      !lex.certificate.lexReceipts.front().selectedFlip;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, lex));

  auto count = baseline;
  count.schedule.front().count += EInt(1);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, count));

  auto digest = baseline;
  digest.semanticDigest ^= 1U;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, digest));
}

TEST(GlobalConformityBaseline,
     CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  auto input = make_baseline_input(fixture, 0.5, 1U, true);
  const auto first = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(first);
  std::reverse(input.spans.begin(), input.spans.end());
  const auto permuted = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(permuted);
  EXPECT_EQ(first.value().semantic_digest(), permuted.value().semantic_digest());
  EXPECT_EQ(exact_counts(first.value()), exact_counts(permuted.value()));

  const auto &entry = first.value().schedule().front();
  ASSERT_GT(entry.count, EInt(1));
  const EInt one(1);
  const auto forward = first.value().breakpoint_location(entry.span, one);
  const auto reverse =
      first.value().breakpoint_location(entry.span, entry.count - one);
  ASSERT_TRUE(forward.has_value());
  ASSERT_TRUE(reverse.has_value());
  EXPECT_EQ(entry.count, forward->localDenominator);
  EXPECT_EQ(entry.count, reverse->localDenominator);
  EXPECT_EQ(one, forward->id.exactOrdinal);
  EXPECT_EQ(entry.count - one, reverse->id.exactOrdinal);
}

TEST(GlobalConformityBaseline,
     AllEvenConstructiveWitnessHasNoBaselineInfeasibilityOutcome) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, make_baseline_input(fixture, 0.5));
  ASSERT_TRUE(built);
  EXPECT_EQ(EInt(0), built.value().certificate().minimumFlipCount);
  EXPECT_TRUE(built.value().certificate().selectedFlips.empty());
  for (const auto &entry : built.value().schedule()) {
    EXPECT_EQ(EInt(0), entry.count % EInt(2));
  }
}

TEST(GlobalConformityBaseline,
     ProductionBaselineBinderIsStructurallySeparateFromFramedSolver) {
  static_assert(!HasCallerSuppliedIncidences<GlobalConformityBaselineInput>);
  static_assert(!std::is_same_v<BaselineConformityIncidence,
                                directional::geometry::ConformityIncidence>);
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, make_baseline_input(fixture, 1.0));
  ASSERT_TRUE(built);
  EXPECT_EQ(fixture.topology.regions().front().boundary.size(),
            built.value().incidences().size());
}
