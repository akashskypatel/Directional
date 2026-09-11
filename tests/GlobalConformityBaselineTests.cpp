#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
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
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              0.0, 1.0, 0.0,
              0.25, 0.25, 0.0;
  Eigen::MatrixXi faces(3, 3);
  faces << 0, 1, 3,
           1, 2, 3,
           2, 0, 3;
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
  std::size_t assignmentsExamined = 0U;
  std::size_t parityFeasibleAssignments = 0U;
  std::vector<std::vector<int>> regionSpanMultiplicities;
};

ExhaustiveParityAnswer exhaustive_terminal_parity_oracle(
    const GlobalTopologyPlan &topology,
    const std::vector<ConformitySpanId> &spans,
    const std::vector<int> &preferred) {
  if (spans.size() != preferred.size()) {
    throw std::runtime_error("exhaustive parity oracle span/count size mismatch");
  }

  std::map<ConformitySpanId, std::size_t> spanIndex;
  for (std::size_t index = 0U; index < spans.size(); ++index) {
    if (!spanIndex.emplace(spans[index], index).second) {
      throw std::runtime_error("exhaustive parity oracle duplicate span");
    }
  }

  ExhaustiveParityAnswer best;
  best.regionSpanMultiplicities.assign(
      topology.regions().size(), std::vector<int>(spans.size(), 0));
  for (std::size_t region = 0U; region < topology.regions().size(); ++region) {
    for (const auto &incidence : topology.regions()[region].boundary) {
      const auto span = ConformitySpanId::from_network_arc(incidence.arc);
      const auto found = spanIndex.find(span);
      if (found == spanIndex.end()) {
        throw std::runtime_error("exhaustive parity oracle missing boundary span");
      }
      ++best.regionSpanMultiplicities[region][found->second];
    }
  }

  bool haveBest = false;
  const std::size_t combinations = std::size_t{1} << preferred.size();
  for (std::size_t mask = 0U; mask < combinations; ++mask) {
    ++best.assignmentsExamined;
    int flipCount = 0;
    std::vector<int> counts;
    for (std::size_t span = 0U; span < preferred.size(); ++span) {
      const bool flip = ((mask >> span) & 1U) != 0U;
      flipCount += flip ? 1 : 0;
      const int count = !flip ? preferred[span]
                              : (preferred[span] > 1 ? preferred[span] - 1 : 2);
      counts.push_back(count);
    }

    bool parityFeasible = true;
    for (const auto &multiplicities : best.regionSpanMultiplicities) {
      int parity = 0;
      for (std::size_t span = 0U; span < counts.size(); ++span) {
        parity ^= (multiplicities[span] * counts[span]) & 1;
      }
      if (parity != 0) {
        parityFeasible = false;
        break;
      }
    }
    if (!parityFeasible) continue;
    ++best.parityFeasibleAssignments;

    if (!haveBest || flipCount < best.flips ||
        (flipCount == best.flips && counts < best.counts)) {
      best.flips = flipCount;
      best.counts = counts;
      haveBest = true;
    }
  }
  if (!haveBest) throw std::runtime_error("exhaustive parity oracle found no witness");
  return best;
}

void write_int_vector(std::ostream &out, const std::vector<int> &values) {
  out << '[';
  for (std::size_t index = 0U; index < values.size(); ++index) {
    if (index != 0U) out << ',';
    out << values[index];
  }
  out << ']';
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
  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=386 components="
            << built.value().certificate().components.size()
            << " hasExterior=" << component.hasExterior
            << " exteriorDemandOdd=" << component.exteriorDemandOdd
            << " terminalSpans=" << component.terminalSpans.size() << '\n';
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
  const auto counts = exact_counts(built.value());
  EXPECT_EQ((std::vector<int>{1, 1, 2}), counts);
  EXPECT_EQ(EInt(1), built.value().certificate().minimumFlipCount);
  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=388 counts=";
  write_int_vector(std::cout, counts);
  std::cout << " minimumFlipCount="
            << built.value().certificate().minimumFlipCount.to_string()
            << " lexReceipts=" << built.value().certificate().lexReceipts.size()
            << '\n';
}

TEST(GlobalConformityBaseline,
     ParityFlipMapsOneToTwoAndLargerToPredecessor) {
  const auto triangle = make_topology_fixture(make_triangle_mesh());
  const auto oneInput = make_baseline_input(triangle, 1.0);
  const auto oneBuilt = directional::geometry::build_global_conformity_baseline(
      triangle.topology, oneInput);
  ASSERT_TRUE(oneBuilt);
  ASSERT_FALSE(oneBuilt.value().certificate().selectedFlips.empty());
  const auto *oneEntry = oneBuilt.value().find_schedule(
      oneBuilt.value().certificate().selectedFlips.front());
  ASSERT_NE(nullptr, oneEntry);
  EXPECT_EQ(EInt(1), oneEntry->preferredCount);
  EXPECT_EQ(EInt(2), oneEntry->count);

  const auto square = make_topology_fixture(make_square_mesh());
  const auto largerInput = make_baseline_input(square, 0.5, 1U);
  ASSERT_FALSE(largerInput.spans.empty());
  const auto largerBuilt = directional::geometry::build_global_conformity_baseline(
      square.topology, largerInput);
  ASSERT_TRUE(largerBuilt);
  const auto *largerEntry =
      largerBuilt.value().find_schedule(largerInput.spans.front().id);
  ASSERT_NE(nullptr, largerEntry);
  EXPECT_EQ(EInt(2), largerEntry->preferredCount);
  EXPECT_EQ(EInt(1), largerEntry->count);

  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=389 onePreferred="
            << oneEntry->preferredCount.to_string()
            << " oneFinal=" << oneEntry->count.to_string()
            << " largerPreferred=" << largerEntry->preferredCount.to_string()
            << " largerFinal=" << largerEntry->count.to_string() << '\n';
}

TEST(GlobalConformityBaseline,
     IndependentTinyExhaustiveOracleMatchesParityOptimumAndLexTie) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto input = make_baseline_input(fixture, 1.0);
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(built);
  std::vector<ConformitySpanId> spans;
  std::vector<int> preferred;
  for (const auto &entry : built.value().schedule()) {
    spans.push_back(entry.span);
    preferred.push_back(std::stoi(entry.preferredCount.to_string()));
  }
  const auto oracle =
      exhaustive_terminal_parity_oracle(fixture.topology, spans, preferred);
  const std::size_t expectedAssignments = std::size_t{1} << preferred.size();
  EXPECT_EQ(expectedAssignments, oracle.assignmentsExamined);
  EXPECT_GT(oracle.parityFeasibleAssignments, 0U);
  EXPECT_EQ(oracle.flips,
            std::stoi(built.value().certificate().minimumFlipCount.to_string()));
  const auto counts = exact_counts(built.value());
  EXPECT_EQ(oracle.counts, counts);

  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=390 spanCount="
            << preferred.size()
            << " assignmentsExamined=" << oracle.assignmentsExamined
            << " parityFeasibleAssignments=" << oracle.parityFeasibleAssignments
            << " winningFlips=" << oracle.flips << " winningCounts=";
  write_int_vector(std::cout, oracle.counts);
  std::cout << " regionSpanMultiplicities=";
  for (std::size_t region = 0U;
       region < oracle.regionSpanMultiplicities.size(); ++region) {
    if (region != 0U) std::cout << ';';
    write_int_vector(std::cout, oracle.regionSpanMultiplicities[region]);
  }
  std::cout << '\n';
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

  std::size_t tamperRows = 0U;

  auto support = baseline;
  support.schedule.front().supportPieces.front().first =
      support.schedule.front().supportPieces.front().second;
  const auto supportError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, support);
  ++tamperRows;
  EXPECT_TRUE(supportError);

  auto incidence = baseline;
  incidence.incidences.front().orientation =
      incidence.incidences.front().orientation ==
              directional::authority::Orientation::Forward
          ? directional::authority::Orientation::Reverse
          : directional::authority::Orientation::Forward;
  const auto incidenceError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, incidence);
  ++tamperRows;
  EXPECT_TRUE(incidenceError);

  auto residual = baseline;
  residual.certificate.regions.front().preferredResidualOdd =
      !residual.certificate.regions.front().preferredResidualOdd;
  const auto residualError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, residual);
  ++tamperRows;
  EXPECT_TRUE(residualError);

  auto demand = baseline;
  ASSERT_FALSE(demand.certificate.demandedVertices.empty());
  demand.certificate.demandedVertices.pop_back();
  const auto demandError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, demand);
  ++tamperRows;
  EXPECT_TRUE(demandError);

  auto flips = baseline;
  ASSERT_FALSE(flips.certificate.selectedFlips.empty());
  flips.certificate.selectedFlips.clear();
  const auto flipsError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, flips);
  ++tamperRows;
  EXPECT_TRUE(flipsError);

  auto optimum = baseline;
  optimum.certificate.minimumFlipCount += EInt(1);
  const auto optimumError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, optimum);
  ++tamperRows;
  EXPECT_TRUE(optimumError);

  auto lex = baseline;
  lex.certificate.lexReceipts.front().selectedFlip =
      !lex.certificate.lexReceipts.front().selectedFlip;
  const auto lexError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, lex);
  ++tamperRows;
  EXPECT_TRUE(lexError);

  auto count = baseline;
  count.schedule.front().count += EInt(1);
  const auto countError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, count);
  ++tamperRows;
  EXPECT_TRUE(countError);

  auto digest = baseline;
  digest.semanticDigest ^= 1U;
  const auto digestError =
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, digest);
  ++tamperRows;
  EXPECT_TRUE(digestError);

  EXPECT_EQ(9U, tamperRows);
  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=391 tamperRows="
            << tamperRows << '\n';
}

TEST(GlobalConformityBaseline,
     CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  auto input = make_baseline_input(fixture, 0.25, 1U, true);
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
  ASSERT_EQ(EInt(4), entry.preferredCount);
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
  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=392 preferredCount="
            << entry.preferredCount.to_string()
            << " entryCount=" << entry.count.to_string()
            << " forwardOrdinal=" << forward->id.exactOrdinal.to_string()
            << " reverseOrdinal=" << reverse->id.exactOrdinal.to_string()
            << " forwardDenominator=" << forward->localDenominator.to_string()
            << " reverseDenominator=" << reverse->localDenominator.to_string()
            << '\n';
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
  std::size_t topologyBoundaryIncidenceCount = 0U;
  for (const auto &region : fixture.topology.regions()) {
    topologyBoundaryIncidenceCount += region.boundary.size();
  }
  EXPECT_EQ(topologyBoundaryIncidenceCount, built.value().incidences().size());
  std::cout << "M4_CP3_BASELINE_RECEIPT ordinal=394 topologyBoundaryIncidences="
            << topologyBoundaryIncidenceCount
            << " baselineIncidences=" << built.value().incidences().size()
            << '\n';
}
