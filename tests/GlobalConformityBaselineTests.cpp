#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
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
#include <directional/pipeline/RemeshPipeline.h>

#include "../src/geometry/GlobalConformityBaselineSupport.h"
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



// Test-authority seed only: zero matching/effort is not an admissibility claim.
// Downstream semantic-success fixtures must establish atlas/topology authority
// explicitly; direct non-flat uses are construction seeds or negative subjects.
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

directional::authority::FieldTransportAtlasBuildResult
zero_transport_atlas_for_semantic_success(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority) {
  auto atlas = directional::authority::FieldTransportAtlas::make(
      mesh, sourceAuthority, {}, make_zero_transport_field(mesh));
  if (!atlas) {
    throw std::runtime_error(
        std::string("make_zero_transport_field semantic-success precondition failed: ") +
        directional::authority::field_atlas_build_error_code_name(
            atlas.error().code));
  }
  return atlas;
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
    rail.sourceEdges = {barrier.sourceEdge};
    rails.push_back(std::move(rail));
  }
  return rails;
}

struct TopologyFixture {
  TriMesh mesh;
  GlobalTopologyPlan topology;
  std::vector<directional::geometry::FieldAlignedMandatoryEdge> mandatoryEdges;
};

TopologyFixture make_topology_fixture(TriMesh mesh) {
  const auto sourceAuthority = make_source_authority(mesh);
  if (!sourceAuthority) throw std::runtime_error("source authority fixture failed");
  auto atlas =
      zero_transport_atlas_for_semantic_success(mesh, *sourceAuthority);
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
  return {std::move(mesh), std::move(topology.value()),
          network.value().mandatory_edges()};
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

TEST(M4CP4, ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const auto input = make_baseline_input(fixture, 1.0);
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(built);

  const auto baseline = built.value().validation_candidate();
  const auto &work = baseline.certificate.work;
  const std::size_t spanCount = baseline.schedule.size();
  const std::size_t perPhase = 1U + 2U * spanCount;
  ASSERT_EQ(spanCount, work.spanCount);
  EXPECT_EQ(perPhase, work.producerTJoinInvocationCount);
  EXPECT_EQ(perPhase, work.validatorTJoinInvocationCount);
  EXPECT_EQ(2U * perPhase, work.aggregateTJoinInvocationCount);
  ASSERT_EQ(work.aggregateTJoinInvocationCount, work.tJoinInvocations.size());
  EXPECT_EQ(0U, work.retryResetCount);
  EXPECT_FALSE(work.producerInitialOptimumPending);
  EXPECT_EQ(0U, work.producerRemainingCanonicalSpanDecisions);
  EXPECT_FALSE(work.validatorInitialOptimumPending);
  EXPECT_EQ(0U, work.validatorRemainingCanonicalSpanDecisions);

  for (std::size_t phase = 0U; phase < 2U; ++phase) {
    const std::size_t offset = phase * perPhase;
    const auto expectedPhase =
        phase == 0U
            ? directional::geometry::BaselineConformityWorkPhase::Producer
            : directional::geometry::BaselineConformityWorkPhase::Validator;
    EXPECT_EQ(expectedPhase, work.tJoinInvocations[offset].phase);
    EXPECT_EQ(directional::geometry::BaselineConformityTJoinPurpose::InitialOptimum,
              work.tJoinInvocations[offset].purpose);
    EXPECT_EQ(0U, work.tJoinInvocations[offset].fixedPrefixLength);
    for (std::size_t span = 0U; span < spanCount; ++span) {
      const auto &trial = work.tJoinInvocations[offset + 1U + 2U * span];
      const auto &selected = work.tJoinInvocations[offset + 2U + 2U * span];
      EXPECT_EQ(expectedPhase, trial.phase);
      EXPECT_EQ(expectedPhase, selected.phase);
      EXPECT_EQ(directional::geometry::BaselineConformityTJoinPurpose::TrialPrefix,
                trial.purpose);
      EXPECT_EQ(
          directional::geometry::BaselineConformityTJoinPurpose::SelectedPrefix,
          selected.purpose);
      EXPECT_EQ(span + 1U, trial.fixedPrefixLength);
      EXPECT_EQ(span + 1U, selected.fixedPrefixLength);
      EXPECT_LE(trial.matchingEdgeCount,
                trial.terminalCount * (trial.terminalCount -
                                       (trial.terminalCount == 0U ? 0U : 1U)) /
                    2U);
      EXPECT_LE(selected.matchingEdgeCount,
                selected.terminalCount *
                    (selected.terminalCount -
                     (selected.terminalCount == 0U ? 0U : 1U)) /
                    2U);
    }
  }
  EXPECT_EQ(baseline.certificate.exactWidths.overallMaximumBits,
            std::max({baseline.certificate.exactWidths.preferredCountBits,
                      baseline.certificate.exactWidths.scheduledCountBits,
                      baseline.certificate.exactWidths.minimumFlipCountBits,
                      baseline.certificate.exactWidths.lexMinimumCountBits,
                      baseline.certificate.exactWidths.regionBoundaryCountBits,
                      baseline.certificate.exactWidths.matchingDistanceBits,
                      baseline.certificate.exactWidths.breakpointOrdinalBits,
                      baseline.certificate.exactWidths.breakpointNumeratorBits,
                      baseline.certificate.exactWidths.breakpointDenominatorBits}));
  EXPECT_FALSE(
      directional::geometry::validate_global_conformity_baseline_candidate(
          fixture.topology, input, baseline));

  auto countTamper = baseline;
  ++countTamper.certificate.work.producerTJoinInvocationCount;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, countTamper));

  auto orderTamper = baseline;
  ASSERT_GT(perPhase, 1U);
  std::swap(orderTamper.certificate.work.tJoinInvocations[0U],
            orderTamper.certificate.work.tJoinInvocations[1U]);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, orderTamper));

  auto progressTamper = baseline;
  progressTamper.certificate.work.producerRemainingCanonicalSpanDecisions = 1U;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, progressTamper));

  auto dimensionTamper = baseline;
  ++dimensionTamper.certificate.work.tJoinInvocations.front().matchingEdgeCount;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, dimensionTamper));

  auto widthTamper = baseline;
  ++widthTamper.certificate.exactWidths.overallMaximumBits;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline_candidate(
      fixture.topology, input, widthTamper));
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
  // The halved span is one run, so breakpoints 1 and n - 1 sit a quarter in
  // from each end, stored reduced (D7b, RA-217); piece-index placement stored
  // the same points as 0:2/4 and 1:2/4.
  ASSERT_EQ(EInt(4), entry.count);
  EXPECT_EQ(0U, forward->supportPieceIndex);
  EXPECT_EQ(EInt(1), forward->localNumerator);
  EXPECT_EQ(EInt(2), forward->localDenominator);
  EXPECT_EQ(1U, reverse->supportPieceIndex);
  EXPECT_EQ(EInt(1), reverse->localNumerator);
  EXPECT_EQ(EInt(2), reverse->localDenominator);
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


TEST(GlobalConformityBaseline,
     ProductionBinderCopiesExactA2bSupportOneToOneWithoutFamilyOrSign) {
  static_assert(!HasCallerSuppliedIncidences<GlobalConformityBaselineInput>);
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  const Eigen::VectorXd target =
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.75);
  const auto input = directional::pipeline::remesh_pipeline_detail::
      make_global_conformity_baseline_input(fixture.mesh.V, target,
                                            fixture.topology);
  ASSERT_EQ(fixture.topology.arcs().size(), input.spans.size());
  for (std::size_t index = 0U; index < input.spans.size(); ++index) {
    EXPECT_EQ(ConformitySpanId::from_network_arc(
                  fixture.topology.arcs()[index].id),
              input.spans[index].id);
    EXPECT_EQ(fixture.topology.arcs()[index].sourcePath,
              input.spans[index].supportPieces);
  }
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  ASSERT_TRUE(built) << (built ? "" :
      directional::geometry::global_conformity_plan_error_code_name(
          built.error().code));
  EXPECT_EQ(fixture.topology.semantic_digest(),
            built.value().topology_plan_digest());
}

TEST(GlobalConformityBaseline,
     IndependentValidatorRejectsNonCanonicalRedundantExactPointEncoding) {
  const auto fixture = make_topology_fixture(make_triangle_mesh());
  auto input = directional::pipeline::remesh_pipeline_detail::
      make_global_conformity_baseline_input(
          fixture.mesh.V,
          Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 1.0),
          fixture.topology);
  ASSERT_FALSE(input.spans.empty());
  ASSERT_FALSE(input.spans.front().supportPieces.empty());
  auto &piece = input.spans.front().supportPieces.front();
  const auto *edge =
      std::get_if<directional::authority::SourceEdgeSupport>(&piece.carrier);
  ASSERT_NE(nullptr, edge);
  piece.first = directional::authority::ExactSourceEdgePoint{
      edge->edge, directional::authority::FieldExactRational::from_integer(0)};
  const auto built = directional::geometry::build_global_conformity_baseline(
      fixture.topology, input);
  EXPECT_FALSE(built)
      << "A3 must reject endpoint-as-edge-point instead of accepting a redundant exact encoding";
}

namespace {

using directional::geometry::ConformitySourcePoint;
using directional::geometry::global_conformity_baseline_detail::
    derive_partition_stable_preferred_count_exact;
using directional::geometry::global_conformity_baseline_detail::
    derive_preferred_count_exact;

// D7 witnesses (RA-216) use exact coordinates and targets, so each expected
// count below is the hand-computed integral of rho = 1/h along the path.
ConformitySpanInput d7_span() {
  return {ConformitySpanId::from_network_arc(
              directional::authority::NetworkArcId::from_index(0U, 1U).value()),
          {}};
}

ConformitySpanInput edge_span_cut_at(
    const SourceEdgeTopologyKey &edge,
    const std::vector<std::pair<int, int>> &cuts) {
  ConformitySpanInput span = d7_span();
  ConformitySourcePoint previous = edge.first();
  for (const auto &[numerator, denominator] : cuts) {
    const ConformitySourcePoint next = ConformityEdgePoint{
        edge, *FieldExactRational::from_ratio(numerator, denominator)};
    span.supportPieces.push_back(
        {directional::authority::SourceEdgeSupport{edge}, previous, next});
    previous = next;
  }
  span.supportPieces.push_back(
      {directional::authority::SourceEdgeSupport{edge}, previous, edge.second()});
  return span;
}

ConformitySpanInput reversed_span(ConformitySpanInput span) {
  std::reverse(span.supportPieces.begin(), span.supportPieces.end());
  for (auto &piece : span.supportPieces) std::swap(piece.first, piece.second);
  return span;
}

std::optional<EInt> d7_count(const ConformitySpanInput &span,
                             const Eigen::MatrixXd &vertices,
                             const Eigen::VectorXd &target) {
  return derive_partition_stable_preferred_count_exact(span, vertices, target);
}

std::optional<EInt> objective_count(const ConformitySpanInput &span,
                                    const Eigen::MatrixXd &vertices,
                                    const Eigen::VectorXd &target) {
  return derive_preferred_count_exact(span, vertices, target);
}

} // namespace

TEST(GlobalConformityBaseline,
     D7PreferredCountIsInvariantToSupportSplitsAndReversal) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0,
              4.0, 0.0, 0.0,
              0.0, 1.0, 0.0;
  const Eigen::VectorXd unit = Eigen::VectorXd::Constant(3, 1.0);
  const auto edge = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();

  // One straight edge of metric length 4 as 1, 2, 2, 4 and 7 pieces.
  const std::vector<std::vector<std::pair<int, int>>> splits{
      {},
      {{1, 40}},
      {{1, 8}},
      {{1, 8}, {1, 2}, {3, 4}},
      {{1, 16}, {1, 8}, {1, 4}, {1, 2}, {3, 4}, {7, 8}}};
  for (const auto &cuts : splits) {
    const auto span = edge_span_cut_at(edge, cuts);
    EXPECT_EQ(std::optional<EInt>(EInt(4)), d7_count(span, vertices, unit))
        << "pieces=" << span.supportPieces.size();
    EXPECT_EQ(std::optional<EInt>(EInt(4)),
              d7_count(reversed_span(span), vertices, unit))
        << "reversed pieces=" << span.supportPieces.size();
  }
  // The scheduler's objective is the D7 count, so the former
  // round(sqrt(m * sum(lambda^2))) values 6 and 5 are gone.
  EXPECT_EQ(std::optional<EInt>(EInt(4)),
            objective_count(edge_span_cut_at(edge, {}), vertices, unit));
  EXPECT_EQ(std::optional<EInt>(EInt(4)),
            objective_count(edge_span_cut_at(edge, {{1, 40}}), vertices, unit));
  EXPECT_EQ(std::optional<EInt>(EInt(4)),
            objective_count(edge_span_cut_at(edge, {{1, 8}}), vertices, unit));

  // A face-interior run of irrational length sqrt(1/2) at h = 1/16 has
  // metric sqrt(128) = 11.31..., whole or cut unevenly at (1/8, 1/8).
  Eigen::MatrixXd face(3, 3);
  face << 0.0, 0.0, 0.0,
          1.0, 0.0, 0.0,
          0.0, 1.0, 0.0;
  const Eigen::VectorXd fine = Eigen::VectorXd::Constant(3, 0.0625);
  const auto opposite = SourceEdgeTopologyKey::from_indices(1, 2, 3).value();
  const auto faceKey = directional::authority::SourceFaceTopologyKey::make(
                           {edge.first(), edge.second(), opposite.second()})
                           .value();
  const directional::authority::SourceSupport interior =
      directional::authority::SourceFaceInteriorSupport{faceKey};
  const ConformitySourcePoint start = edge.first();
  const ConformitySourcePoint end = ConformityEdgePoint{
      opposite, *FieldExactRational::from_ratio(1, 2)};
  const ConformitySourcePoint inside = directional::authority::ExactSourceFacePoint{
      faceKey,
      {*FieldExactRational::from_ratio(3, 4), *FieldExactRational::from_ratio(1, 8),
       *FieldExactRational::from_ratio(1, 8)}};
  ConformitySpanInput whole = d7_span();
  whole.supportPieces = {{interior, start, end}};
  ConformitySpanInput cut = d7_span();
  cut.supportPieces = {{interior, start, inside}, {interior, inside, end}};
  EXPECT_EQ(std::optional<EInt>(EInt(11)), d7_count(whole, face, fine));
  EXPECT_EQ(std::optional<EInt>(EInt(11)), d7_count(cut, face, fine));
  EXPECT_EQ(std::optional<EInt>(EInt(11)),
            d7_count(reversed_span(cut), face, fine));
  EXPECT_EQ(std::optional<EInt>(EInt(11)), objective_count(whole, face, fine));
  EXPECT_EQ(std::optional<EInt>(EInt(11)), objective_count(cut, face, fine));
  std::cout << "D7_PREFERRED_COUNT_RECEIPT case=splits straight=4 objective0.1=4"
            << " objective0.5=4 faceRun=11 objectiveFaceCut=11\n";
}

TEST(GlobalConformityBaseline,
     D7PreferredCountIntegratesInterpolatedReciprocalTargetAdditively) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0,
              4.0, 0.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::VectorXd target(3);
  target << 1.0, 0.5, 1.0;
  const auto edge = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();

  // rho runs from 1 to 2 over length 4: the integral is 4 * (1 + 2) / 2 = 6
  // wherever the edge is cut, including at the non-dyadic 1/3.
  for (const auto &cuts : std::vector<std::vector<std::pair<int, int>>>{
           {}, {{1, 2}}, {{1, 3}}, {{1, 8}, {5, 8}}}) {
    const auto span = edge_span_cut_at(edge, cuts);
    EXPECT_EQ(std::optional<EInt>(EInt(6)), d7_count(span, vertices, target))
        << "pieces=" << span.supportPieces.size();
    EXPECT_EQ(std::optional<EInt>(EInt(6)),
              d7_count(reversed_span(span), vertices, target))
        << "reversed pieces=" << span.supportPieces.size();
  }
  // The objective no longer uses midpoint h, which gave 5 whole and 6 halved.
  EXPECT_EQ(std::optional<EInt>(EInt(6)),
            objective_count(edge_span_cut_at(edge, {}), vertices, target));
  EXPECT_EQ(std::optional<EInt>(EInt(6)),
            objective_count(edge_span_cut_at(edge, {{1, 2}}), vertices, target));
  std::cout << "D7_PREFERRED_COUNT_RECEIPT case=reciprocal-density d7=6"
            << " objectiveWhole=6 objectiveHalves=6\n";
}

TEST(GlobalConformityBaseline,
     D7PreferredCountRoundsOnceKeepsDirectionChangesAndFailsClosed) {
  const auto count_on_x_axis = [](double length, double size,
                                  const std::vector<std::pair<int, int>> &cuts) {
    Eigen::MatrixXd vertices(3, 3);
    vertices << 0.0, 0.0, 0.0,
                length, 0.0, 0.0,
                0.0, 1.0, 0.0;
    const auto edge = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();
    return d7_count(edge_span_cut_at(edge, cuts), vertices,
                    Eigen::VectorXd::Constant(3, size));
  };
  // Metric 4.5 is an exact half and rounds down, whole or cut; 2^-39 more
  // rounds up, so the 64-bit run resolution decides it exactly.
  EXPECT_EQ(std::optional<EInt>(EInt(4)), count_on_x_axis(2.25, 0.5, {}));
  EXPECT_EQ(std::optional<EInt>(EInt(4)), count_on_x_axis(2.25, 0.5, {{1, 9}}));
  EXPECT_EQ(std::optional<EInt>(EInt(5)),
            count_on_x_axis(2.25 + std::ldexp(1.0, -40), 0.5, {}));
  EXPECT_EQ(std::optional<EInt>(EInt(5)),
            count_on_x_axis(2.25 + std::ldexp(1.0, -40), 0.5, {{1, 9}}));
  // A positive span shorter than half a target still gets one interval.
  EXPECT_EQ(std::optional<EInt>(EInt(1)), count_on_x_axis(0.25, 1.0, {}));

  // A bend starts a new run: lengths 1 and 4 give 5 (formerly 6).
  Eigen::MatrixXd bent(3, 3);
  bent << 0.0, 0.0, 0.0,
          1.0, 0.0, 0.0,
          1.0, 4.0, 0.0;
  const Eigen::VectorXd unit = Eigen::VectorXd::Constant(3, 1.0);
  const auto first = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();
  const auto second = SourceEdgeTopologyKey::from_indices(1, 2, 3).value();
  ConformitySpanInput corner = d7_span();
  corner.supportPieces = {
      {directional::authority::SourceEdgeSupport{first}, first.first(),
       first.second()},
      {directional::authority::SourceEdgeSupport{second}, second.first(),
       second.second()}};
  EXPECT_EQ(std::optional<EInt>(EInt(5)), d7_count(corner, bent, unit));
  EXPECT_EQ(std::optional<EInt>(EInt(5)),
            d7_count(reversed_span(corner), bent, unit));
  EXPECT_EQ(std::optional<EInt>(EInt(5)), objective_count(corner, bent, unit));

  // Turning back along the same line is a new run, not a cancellation:
  // 0 -> 3 -> 1 on a length-4 edge measures 3 + 2.
  Eigen::MatrixXd line(3, 3);
  line << 0.0, 0.0, 0.0,
          4.0, 0.0, 0.0,
          0.0, 1.0, 0.0;
  const auto edge = first;
  const directional::authority::SourceSupport onEdge =
      directional::authority::SourceEdgeSupport{edge};
  const ConformitySourcePoint threeQuarters = ConformityEdgePoint{
      edge, *FieldExactRational::from_ratio(3, 4)};
  const ConformitySourcePoint oneQuarter = ConformityEdgePoint{
      edge, *FieldExactRational::from_ratio(1, 4)};
  ConformitySpanInput foldBack = d7_span();
  foldBack.supportPieces = {{onEdge, edge.first(), threeQuarters},
                            {onEdge, threeQuarters, oneQuarter}};
  EXPECT_EQ(std::optional<EInt>(EInt(5)), d7_count(foldBack, line, unit));

  // Malformed input fails closed instead of producing a count.
  EXPECT_FALSE(d7_count(d7_span(), line, unit).has_value());
  Eigen::VectorXd zeroAtStart = unit;
  zeroAtStart(0) = 0.0;
  EXPECT_FALSE(
      d7_count(edge_span_cut_at(edge, {}), line, zeroAtStart).has_value());
  Eigen::VectorXd negativeAtEnd = unit;
  negativeAtEnd(1) = -1.0;
  EXPECT_FALSE(
      d7_count(edge_span_cut_at(edge, {{1, 2}}), line, negativeAtEnd).has_value());
  ConformitySpanInput gap = d7_span();
  gap.supportPieces = {{onEdge, edge.first(), oneQuarter},
                       {onEdge, threeQuarters, edge.second()}};
  EXPECT_FALSE(d7_count(gap, line, unit).has_value());
  ConformitySpanInput stationary = d7_span();
  stationary.supportPieces = {{onEdge, edge.first(), edge.first()}};
  EXPECT_FALSE(d7_count(stationary, line, unit).has_value());
  ConformitySpanInput foreign = d7_span();
  foreign.supportPieces = {
      {directional::authority::SourceEdgeSupport{second}, edge.first(),
       edge.second()}};
  EXPECT_FALSE(d7_count(foreign, line, unit).has_value());
  std::cout << "D7_PREFERRED_COUNT_RECEIPT case=rounding half=4 halfPlus=5"
            << " short=1 bend=5 objectiveBend=5 foldBack=5 malformed=6\n";
}

TEST(GlobalConformityBaseline,
     D7PreferredCountIsTheSchedulerObjectiveForEverySplit) {
  // One A3 span on a unit edge at h = 1/4, whole, cut at 1/8 (formerly
  // preferred 5) and halved: the built and validated plan prefers 4 each time
  // and so schedules the same counts.
  const auto fixture = make_topology_fixture(make_square_mesh());
  auto whole = make_baseline_input(fixture, 0.25, 1U);
  auto uneven = whole;
  uneven.spans.front().supportPieces =
      edge_span_cut_at(find_edge(fixture.mesh, 0, 1), {{1, 8}}).supportPieces;
  auto halves = make_baseline_input(fixture, 0.25, 1U, true);
  ASSERT_EQ(2U, uneven.spans.front().supportPieces.size());
  ASSERT_EQ(2U, halves.spans.front().supportPieces.size());
  std::vector<std::vector<int>> counts;
  for (const GlobalConformityBaselineInput *input : {&whole, &uneven, &halves}) {
    const auto built = directional::geometry::build_global_conformity_baseline(
        fixture.topology, *input);
    ASSERT_TRUE(built);
    const auto *entry = built.value().find_schedule(input->spans.front().id);
    ASSERT_NE(nullptr, entry);
    EXPECT_EQ(EInt(4), entry->preferredCount)
        << "pieces=" << input->spans.front().supportPieces.size();
    counts.push_back(exact_counts(built.value()));
  }
  EXPECT_EQ(counts[0], counts[1]);
  EXPECT_EQ(counts[0], counts[2]);
  std::cout << "D7_PREFERRED_COUNT_RECEIPT case=scheduler-objective whole=4"
            << " uneven=4 halves=4\n";
}

namespace {

using directional::geometry::BaselineConformityMetricRun;
using directional::geometry::ConformityBreakpointLocation;
using directional::geometry::global_conformity_baseline_detail::
    derive_metric_breakpoint_location;
using directional::geometry::global_conformity_baseline_detail::
    derive_partition_stable_metric_runs;
using ExactPoint = std::array<FieldExactRational, 3>;

// D7b witnesses (RA-217) pin both the location a breakpoint is stored as and
// the exact point it names; every expected value is hand-computed.
ExactPoint exact_source_point(const ConformitySourcePoint &point,
                              const Eigen::MatrixXd &vertices) {
  const auto coordinate = [&](std::size_t vertex, std::size_t axis) {
    return *FieldExactRational::from_double_exact(
        vertices(static_cast<Eigen::Index>(vertex), static_cast<Eigen::Index>(axis)));
  };
  ExactPoint out;
  if (const auto *vertex = std::get_if<SourceVertexId>(&point)) {
    for (std::size_t axis = 0U; axis < 3U; ++axis) {
      out[axis] = coordinate(vertex->index(), axis);
    }
    return out;
  }
  const auto &edge = std::get<ConformityEdgePoint>(point);
  const auto one = FieldExactRational::from_integer(1);
  for (std::size_t axis = 0U; axis < 3U; ++axis) {
    out[axis] = (one - edge.parameter) * coordinate(edge.edge.first().index(), axis) +
                edge.parameter * coordinate(edge.edge.second().index(), axis);
  }
  return out;
}

std::optional<ConformityBreakpointLocation> d7b_location(
    const ConformitySpanInput &span, const Eigen::MatrixXd &vertices,
    const Eigen::VectorXd &target, int count, int ordinal) {
  const auto runs = derive_partition_stable_metric_runs(span, vertices, target);
  if (!runs) return std::nullopt;
  return derive_metric_breakpoint_location(span.id, span.supportPieces.size(),
                                           *runs, EInt(count), EInt(ordinal));
}

std::string located(const std::optional<ConformityBreakpointLocation> &location) {
  if (!location) return "none";
  return std::to_string(location->supportPieceIndex) + ":" +
         location->localNumerator.to_string() + "/" +
         location->localDenominator.to_string() +
         (location->firstEndpoint ? " first" : "") +
         (location->lastEndpoint ? " last" : "");
}

ExactPoint d7b_point(const ConformitySpanInput &span,
                     const Eigen::MatrixXd &vertices,
                     const Eigen::VectorXd &target, int count, int ordinal) {
  const auto location = d7b_location(span, vertices, target, count, ordinal);
  if (!location) throw std::runtime_error("D7b placement failed");
  const auto &piece = span.supportPieces.at(location->supportPieceIndex);
  const auto local = *FieldExactRational::from_exact_fraction(
      location->localNumerator, location->localDenominator);
  const auto start = exact_source_point(piece.first, vertices);
  const auto end = exact_source_point(piece.second, vertices);
  ExactPoint out;
  for (std::size_t axis = 0U; axis < 3U; ++axis) {
    out[axis] = start[axis] + local * (end[axis] - start[axis]);
  }
  return out;
}

ExactPoint xy(int xNumerator, int xDenominator, int yNumerator, int yDenominator) {
  return {*FieldExactRational::from_ratio(xNumerator, xDenominator),
          *FieldExactRational::from_ratio(yNumerator, yDenominator),
          FieldExactRational::from_integer(0)};
}

} // namespace

TEST(GlobalConformityBaseline, D7bBreakpointsFollowTheRunNotThePieceIndex) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0,
              4.0, 0.0, 0.0,
              0.0, 1.0, 0.0;
  const Eigen::VectorXd unit = Eigen::VectorXd::Constant(3, 1.0);
  const auto edge = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();

  // Lengths (0.1, 3.9) at count 4 form one run, so breakpoints 1-3 sit at
  // x = 1, 2, 3 on the second piece. Piece-index placement stored 0:2/4, 1:0/4
  // and 1:2/4, that is x = 0.05, 0.1 and 2.05.
  const auto uneven = edge_span_cut_at(edge, {{1, 40}});
  EXPECT_EQ("0:0/1 first", located(d7b_location(uneven, vertices, unit, 4, 0)));
  EXPECT_EQ("1:3/13", located(d7b_location(uneven, vertices, unit, 4, 1)));
  EXPECT_EQ("1:19/39", located(d7b_location(uneven, vertices, unit, 4, 2)));
  EXPECT_EQ("1:29/39", located(d7b_location(uneven, vertices, unit, 4, 3)));
  EXPECT_EQ("1:1/1 last", located(d7b_location(uneven, vertices, unit, 4, 4)));
  // A single piece keeps the unreduced (j, n).
  EXPECT_EQ("0:2/4",
            located(d7b_location(edge_span_cut_at(edge, {}), vertices, unit, 4, 2)));

  // Every split, forwards and reversed, names the same points x = j.
  const std::vector<std::vector<std::pair<int, int>>> splits{
      {},
      {{1, 40}},
      {{1, 8}},
      {{1, 8}, {1, 2}, {3, 4}},
      {{1, 16}, {1, 8}, {1, 4}, {1, 2}, {3, 4}, {7, 8}}};
  for (const auto &cuts : splits) {
    const auto span = edge_span_cut_at(edge, cuts);
    const auto reversed = reversed_span(span);
    for (int j = 0; j <= 4; ++j) {
      EXPECT_EQ(xy(j, 1, 0, 1), d7b_point(span, vertices, unit, 4, j))
          << "pieces=" << span.supportPieces.size() << " j=" << j;
      EXPECT_EQ(xy(j, 1, 0, 1), d7b_point(reversed, vertices, unit, 4, 4 - j))
          << "reversed pieces=" << span.supportPieces.size() << " j=" << j;
    }
  }
  std::cout << "D7B_BREAKPOINT_RECEIPT case=one-run uneven=1:3/13,1:19/39,1:29/39"
            << " single=0:2/4 splits=5 reversed=5\n";
}

TEST(GlobalConformityBaseline, D7bBreakpointsShareOrdinalsAcrossRunsByMetric) {
  // Leg 1 has length 1 at rho = 1 (metric 1); leg 2 has length 2 with rho
  // rising from 1 to 2 (metric 3). At count 4 the corner is breakpoint 1 and
  // leg 2 is cut evenly in length at y = 2/3 and 4/3. Spacing by total length
  // would put breakpoint 1 at (0.75, 0) and piece-index spacing at (0.5, 0).
  Eigen::MatrixXd bent(3, 3);
  bent << 0.0, 0.0, 0.0,
          1.0, 0.0, 0.0,
          1.0, 2.0, 0.0;
  Eigen::VectorXd target(3);
  target << 1.0, 1.0, 0.5;
  const auto first = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();
  const auto second = SourceEdgeTopologyKey::from_indices(1, 2, 3).value();
  const directional::authority::SourceSupport onFirst =
      directional::authority::SourceEdgeSupport{first};
  const directional::authority::SourceSupport onSecond =
      directional::authority::SourceEdgeSupport{second};
  const ConformitySourcePoint middle =
      ConformityEdgePoint{second, *FieldExactRational::from_ratio(1, 2)};
  ConformitySpanInput corner = d7_span();
  corner.supportPieces = {{onFirst, first.first(), first.second()},
                          {onSecond, second.first(), second.second()}};
  ConformitySpanInput cornerCut = d7_span();
  cornerCut.supportPieces = {{onFirst, first.first(), first.second()},
                             {onSecond, second.first(), middle},
                             {onSecond, middle, second.second()}};
  ASSERT_EQ(std::optional<EInt>(EInt(4)), d7_count(corner, bent, target));
  ASSERT_EQ(std::optional<EInt>(EInt(4)), d7_count(cornerCut, bent, target));

  const auto runs = derive_partition_stable_metric_runs(cornerCut, bent, target);
  ASSERT_TRUE(runs.has_value());
  ASSERT_EQ(2U, runs->size());
  EXPECT_EQ(0U, (*runs)[0].firstPiece);
  EXPECT_EQ(1U, (*runs)[1].firstPiece);
  EXPECT_EQ((std::vector<FieldExactRational>{
                FieldExactRational::from_integer(0),
                *FieldExactRational::from_ratio(1, 2)}),
            (*runs)[1].pieceStarts);
  EXPECT_EQ(FieldExactRational::from_integer(1), (*runs)[0].squaredMetric);
  EXPECT_EQ(FieldExactRational::from_integer(9), (*runs)[1].squaredMetric);

  const std::vector<ExactPoint> expected{xy(0, 1, 0, 1), xy(1, 1, 0, 1),
                                         xy(1, 1, 2, 3), xy(1, 1, 4, 3),
                                         xy(1, 1, 2, 1)};
  for (const ConformitySpanInput *span : {&corner, &cornerCut}) {
    const auto reversed = reversed_span(*span);
    for (int j = 0; j <= 4; ++j) {
      EXPECT_EQ(expected[static_cast<std::size_t>(j)],
                d7b_point(*span, bent, target, 4, j))
          << "pieces=" << span->supportPieces.size() << " j=" << j;
      EXPECT_EQ(expected[static_cast<std::size_t>(j)],
                d7b_point(reversed, bent, target, 4, 4 - j))
          << "reversed pieces=" << span->supportPieces.size() << " j=" << j;
    }
  }
  // The corner belongs to the run that starts there, in either direction.
  EXPECT_EQ("1:0/1", located(d7b_location(corner, bent, target, 4, 1)));
  EXPECT_EQ("1:1/3", located(d7b_location(corner, bent, target, 4, 2)));
  EXPECT_EQ("1:2/3", located(d7b_location(cornerCut, bent, target, 4, 2)));
  EXPECT_EQ("2:1/3", located(d7b_location(cornerCut, bent, target, 4, 3)));
  EXPECT_EQ("2:0/1",
            located(d7b_location(reversed_span(cornerCut), bent, target, 4, 3)));
  std::cout << "D7B_BREAKPOINT_RECEIPT case=two-runs corner=1:0/1"
            << " leg2=1:1/3,1:2/3 cut=1:2/3,2:1/3 reversedCorner=2:0/1\n";
}

TEST(GlobalConformityBaseline,
     D7bBreakpointsGiveEveryRunWeightAndRejectBrokenProfiles) {
  Eigen::MatrixXd line(3, 3);
  line << 0.0, 0.0, 0.0,
          4.0, 0.0, 0.0,
          0.0, 1.0, 0.0;
  const Eigen::VectorXd unit = Eigen::VectorXd::Constant(3, 1.0);
  const auto edge = SourceEdgeTopologyKey::from_indices(0, 1, 3).value();

  // rho rising along one piece still spaces it evenly in length and keeps the
  // unreduced (j, n): count 6 at h = (1, 0.5).
  Eigen::VectorXd rising(3);
  rising << 1.0, 0.5, 1.0;
  const auto whole = edge_span_cut_at(edge, {});
  ASSERT_EQ(std::optional<EInt>(EInt(6)), d7_count(whole, line, rising));
  for (int j = 1; j < 6; ++j) {
    EXPECT_EQ("0:" + std::to_string(j) + "/6",
              located(d7b_location(whole, line, rising, 6, j)));
  }

  // A run of metric 2^-70 adds nothing to the count (floor at 2^-64) but still
  // weighs 1 in placement (ceiling), so no run is erased: every breakpoint
  // exists, breakpoint 1 lies 3 * 2^-66 short of y = 1, and reversal maps j to
  // n - j exactly. A zero weight would make the reversed corner ambiguous.
  const double tiny = std::ldexp(1.0, -70);
  Eigen::MatrixXd hook(3, 3);
  hook << 0.0, 0.0, 0.0,
          tiny, 0.0, 0.0,
          tiny, 4.0, 0.0;
  const auto second = SourceEdgeTopologyKey::from_indices(1, 2, 3).value();
  ConformitySpanInput hooked = d7_span();
  hooked.supportPieces = {
      {directional::authority::SourceEdgeSupport{edge}, edge.first(),
       edge.second()},
      {directional::authority::SourceEdgeSupport{second}, second.first(),
       second.second()}};
  ASSERT_EQ(std::optional<EInt>(EInt(4)), d7_count(hooked, hook, unit));
  EXPECT_EQ("1:73786976294838206461/295147905179352825856",
            located(d7b_location(hooked, hook, unit, 4, 1)));
  const auto reversedHook = reversed_span(hooked);
  for (int j = 0; j <= 4; ++j) {
    EXPECT_EQ(d7b_point(hooked, hook, unit, 4, j),
              d7b_point(reversedHook, hook, unit, 4, 4 - j))
        << "j=" << j;
  }

  // A profile that does not tile the span's pieces, or a bad ordinal or
  // count, places nothing.
  const auto halves = edge_span_cut_at(edge, {{1, 2}});
  const auto runs = derive_partition_stable_metric_runs(halves, line, unit);
  ASSERT_TRUE(runs.has_value());
  const auto place = [&](const std::vector<BaselineConformityMetricRun> &profile,
                         std::size_t pieces, int count, int ordinal) {
    return derive_metric_breakpoint_location(halves.id, pieces, profile,
                                             EInt(count), EInt(ordinal))
        .has_value();
  };
  EXPECT_TRUE(place(*runs, 2U, 4, 1));
  EXPECT_FALSE(place(*runs, 3U, 4, 1));
  EXPECT_FALSE(place(*runs, 1U, 4, 1));
  EXPECT_FALSE(place({}, 2U, 4, 1));
  EXPECT_FALSE(place(*runs, 2U, 0, 0));
  EXPECT_FALSE(place(*runs, 2U, 4, -1));
  EXPECT_FALSE(place(*runs, 2U, 4, 5));
  auto shifted = *runs;
  shifted.front().firstPiece = 1U;
  EXPECT_FALSE(place(shifted, 2U, 4, 1));
  auto late = *runs;
  late.front().pieceStarts.front() = *FieldExactRational::from_ratio(1, 4);
  EXPECT_FALSE(place(late, 2U, 4, 1));
  auto unordered = *runs;
  unordered.front().pieceStarts.back() = FieldExactRational::from_integer(0);
  EXPECT_FALSE(place(unordered, 2U, 4, 1));
  auto weightless = *runs;
  weightless.front().squaredMetric = FieldExactRational::from_integer(0);
  EXPECT_FALSE(place(weightless, 2U, 4, 1));
  EXPECT_FALSE(d7b_location(d7_span(), line, unit, 4, 1).has_value());
  std::cout << "D7B_BREAKPOINT_RECEIPT case=weights single=0:j/6"
            << " tinyRun=placed reversed=5 brokenProfiles=10\n";
}

TEST(GlobalConformityBaseline,
     D7bPlanBreakpointsAreTheMetricPlacementForEverySplit) {
  // One A3 span on the unit edge (0, 1) at h = 1/4, whole, cut at 1/8 and
  // halved: the built and validated plan stores the D7b placement of its runs,
  // so breakpoint j is at x = j/4 every time. Piece-index placement stored the
  // cut span's breakpoints as 0:2/4, 1:0/4 and 1:2/4 (x = 1/16, 1/8, 9/16).
  const auto fixture = make_topology_fixture(make_square_mesh());
  auto whole = make_baseline_input(fixture, 0.25, 1U);
  auto uneven = whole;
  uneven.spans.front().supportPieces =
      edge_span_cut_at(find_edge(fixture.mesh, 0, 1), {{1, 8}}).supportPieces;
  auto halves = make_baseline_input(fixture, 0.25, 1U, true);
  std::vector<std::string> stored;
  for (const GlobalConformityBaselineInput *input : {&whole, &uneven, &halves}) {
    const auto built = directional::geometry::build_global_conformity_baseline(
        fixture.topology, *input);
    ASSERT_TRUE(built);
    const auto &span = input->spans.front();
    const auto *entry = built.value().find_schedule(span.id);
    ASSERT_NE(nullptr, entry);
    ASSERT_EQ(EInt(4), entry->count);
    for (int j = 0; j <= 4; ++j) {
      const auto location = built.value().breakpoint_location(span.id, EInt(j));
      EXPECT_EQ(located(d7b_location(span, input->sourceVertices,
                                     input->targetSize, 4, j)),
                located(location))
          << "pieces=" << span.supportPieces.size() << " j=" << j;
      EXPECT_EQ(xy(j, 4, 0, 1),
                d7b_point(span, input->sourceVertices, input->targetSize, 4, j))
          << "pieces=" << span.supportPieces.size() << " j=" << j;
      if (j > 0 && j < 4) stored.push_back(located(location));
    }
  }
  EXPECT_EQ((std::vector<std::string>{"0:1/4", "0:2/4", "0:3/4", "1:1/7",
                                      "1:3/7", "1:5/7", "0:1/2", "1:0/1",
                                      "1:1/2"}),
            stored);
  std::cout << "D7B_BREAKPOINT_RECEIPT case=plan whole=0:1/4,0:2/4,0:3/4"
            << " uneven=1:1/7,1:3/7,1:5/7 halves=0:1/2,1:0/1,1:1/2\n";
}

namespace {

using directional::authority::NetworkArcId;
using directional::authority::NetworkNodeId;
using directional::authority::Orientation;
using directional::geometry::ConformitySupportPiece;
using directional::geometry::FieldAlignedMandatoryEdge;
using directional::geometry::GlobalTopologyArc;
using directional::geometry::GlobalTopologyNodeRotation;
using directional::geometry::GlobalTopologyOrientedArc;
using directional::geometry::global_conformity_baseline_detail::BaselineMandatoryChain;
using directional::geometry::global_conformity_baseline_detail::derive_mandatory_chain_partition;
using directional::geometry::global_conformity_baseline_detail::derive_mandatory_chain_support;
using directional::geometry::global_conformity_baseline_detail::derive_partition_stable_preferred_count_exact;

constexpr std::size_t kChainExtent = 8U;

NetworkNodeId chain_node(int index) {
  return NetworkNodeId::from_index(index, kChainExtent).value();
}

// A hand-built A2b graph: node i sits on source vertex i, and each Mandatory
// arc has its own network edge unless it shares one (a trace-terminal split).
struct ChainGraph {
  std::vector<GlobalTopologyArc> arcs;
  std::vector<FieldAlignedMandatoryEdge> edges;
};

void add_arc(ChainGraph &graph, int first, int second,
             GlobalTopologyArcKind kind = GlobalTopologyArcKind::Mandatory,
             int rail = 0, std::optional<int> sharedEdge = std::nullopt) {
  const int index = static_cast<int>(graph.arcs.size());
  GlobalTopologyArc arc{.id = NetworkArcId::from_index(index, kChainExtent).value(),
                        .kind = kind,
                        .firstNode = chain_node(first),
                        .secondNode = chain_node(second)};
  const auto edge = SourceEdgeTopologyKey::from_indices(
                        first, first == second ? (first + 1) % static_cast<int>(kChainExtent) : second,
                        kChainExtent)
                        .value();
  if (first != second) {
    arc.sourcePath = {
        {directional::authority::SourceEdgeSupport{edge},
         SourceVertexId::from_index(first, kChainExtent).value(),
         SourceVertexId::from_index(second, kChainExtent).value()}};
  }
  if (kind == GlobalTopologyArcKind::Mandatory) {
    arc.mandatoryEdge = directional::authority::NetworkEdgeId::from_index(
                            sharedEdge.value_or(index), kChainExtent)
                            .value();
    if (!sharedEdge) {
      graph.edges.emplace_back(
          *arc.mandatoryEdge, HardRailId::from_index(rail, kChainExtent).value(),
          edge, SurfaceCellRailKind::Boundary, arc.firstNode, arc.secondNode,
          directional::authority::SourceComponentId::from_index(0, 1).value(),
          std::vector<directional::authority::TopologyRegionId>{});
    }
  }
  graph.arcs.push_back(std::move(arc));
}

// A2b's convention: an arc leaves its first node forwards, its second reversed.
std::vector<GlobalTopologyNodeRotation>
rotations_of(const std::vector<GlobalTopologyArc> &arcs) {
  std::map<NetworkNodeId, std::vector<GlobalTopologyOrientedArc>> outgoing;
  for (const auto &arc : arcs) {
    outgoing[arc.firstNode].push_back({arc.id, Orientation::Forward});
    outgoing[arc.secondNode].push_back({arc.id, Orientation::Reverse});
  }
  std::vector<GlobalTopologyNodeRotation> rotations;
  for (auto &[node, incidences] : outgoing) {
    rotations.push_back({node, std::move(incidences)});
  }
  return rotations;
}

// "0F,1R|2F": chains of arc indices with their orientations.
std::string chain_shape(
    const std::optional<std::vector<BaselineMandatoryChain>> &chains) {
  if (!chains) return "none";
  std::string out;
  for (const auto &chain : *chains) {
    if (!out.empty()) out += '|';
    for (std::size_t k = 0U; k < chain.arcs.size(); ++k) {
      if (k != 0U) out += ',';
      out += std::to_string(chain.arcs[k].arc.index());
      out += chain.arcs[k].orientation == Orientation::Forward ? 'F' : 'R';
    }
  }
  return out;
}

std::string partition_shape(const ChainGraph &graph, const std::set<int> &stops) {
  std::set<NetworkNodeId> stopNodes;
  for (const int stop : stops) stopNodes.insert(chain_node(stop));
  return chain_shape(derive_mandatory_chain_partition(
      graph.arcs, rotations_of(graph.arcs), graph.edges, stopNodes));
}

} // namespace

TEST(GlobalConformityBaseline, D5ChainsJoinOnlyThroughUnprotectedSameRailNodes) {
  // Rail 0 runs 0-1-2-3-4 with arc 1 stored backwards; rail 1 continues 4-5
  // and a trace leaves 5. Node 3 is a stop, such as a feature corner.
  ChainGraph graph;
  add_arc(graph, 0, 1);
  add_arc(graph, 2, 1);
  add_arc(graph, 2, 3);
  add_arc(graph, 3, 4);
  add_arc(graph, 4, 5, GlobalTopologyArcKind::Mandatory, 1);
  add_arc(graph, 5, 6, GlobalTopologyArcKind::Trace);
  EXPECT_EQ("0F,1R,2F|3F|4F|5F", partition_shape(graph, {3}));
  EXPECT_EQ("0F,1R,2F,3F|4F|5F", partition_shape(graph, {}));
  EXPECT_EQ("0F|1F|2F|3F|4F|5F", partition_shape(graph, {1, 2, 3}));

  // Row order does not matter.
  auto permuted = graph;
  std::reverse(permuted.arcs.begin(), permuted.arcs.end());
  std::reverse(permuted.edges.begin(), permuted.edges.end());
  auto rotations = rotations_of(permuted.arcs);
  std::reverse(rotations.begin(), rotations.end());
  for (auto &rotation : rotations) {
    std::reverse(rotation.counterClockwise.begin(),
                 rotation.counterClockwise.end());
  }
  EXPECT_EQ("0F,1R,2F|3F|4F|5F",
            chain_shape(derive_mandatory_chain_partition(
                permuted.arcs, rotations, permuted.edges, {chain_node(3)})));

  // A trace terminal splits one network edge into two arcs. Their node has
  // three incidences, so the halves stay apart.
  ChainGraph split;
  add_arc(split, 0, 1);
  add_arc(split, 1, 2, GlobalTopologyArcKind::Mandatory, 0, 0);
  add_arc(split, 1, 3, GlobalTopologyArcKind::Trace);
  EXPECT_EQ("0F|1F|2F", partition_shape(split, {}));
  std::cout << "D5_CHAIN_RECEIPT case=joins stop=0F,1R,2F|3F|4F|5F"
            << " open=0F,1R,2F,3F|4F|5F permuted=same split=0F|1F|2F\n";
}

TEST(GlobalConformityBaseline, D5ChainsOpenAClosedRailOnlyAtAStop) {
  // With no stop every arc of a closed rail is joined at both ends, so the
  // cycle stays single. Stops open it into chains read from the lower-id end.
  ChainGraph loop;
  add_arc(loop, 0, 1);
  add_arc(loop, 1, 2);
  add_arc(loop, 2, 0);
  EXPECT_EQ("0F|1F|2F", partition_shape(loop, {}));
  EXPECT_EQ("0F,1F,2F", partition_shape(loop, {0}));
  EXPECT_EQ("0R,2R,1R", partition_shape(loop, {1}));
  EXPECT_EQ("0F|1F,2F", partition_shape(loop, {0, 1}));

  ChainGraph pair;
  add_arc(pair, 0, 1);
  add_arc(pair, 1, 0);
  EXPECT_EQ("0F|1F", partition_shape(pair, {}));
  EXPECT_EQ("0F,1F", partition_shape(pair, {0}));

  // A loop arc fills its node's rotation by itself and joins nothing.
  ChainGraph self;
  add_arc(self, 0, 0);
  EXPECT_EQ("0F", partition_shape(self, {}));
  std::cout << "D5_CHAIN_RECEIPT case=cycles uncut=0F|1F|2F stop0=0F,1F,2F"
            << " stop1=0R,2R,1R pair=0F,1F self=0F\n";
}

TEST(GlobalConformityBaseline, D5ChainPartitionRejectsInconsistentGraphs) {
  ChainGraph graph;
  add_arc(graph, 0, 1);
  add_arc(graph, 1, 2);
  const auto rotations = rotations_of(graph.arcs);
  const auto shape = [](const std::vector<GlobalTopologyArc> &arcs,
                        const std::vector<GlobalTopologyNodeRotation> &rotation,
                        const std::vector<FieldAlignedMandatoryEdge> &edges) {
    return chain_shape(derive_mandatory_chain_partition(arcs, rotation, edges, {}));
  };
  EXPECT_EQ("0F,1F", shape(graph.arcs, rotations, graph.edges));
  EXPECT_EQ("", shape({}, {}, {}));

  auto noEdge = graph.arcs;
  noEdge[1].mandatoryEdge.reset();
  EXPECT_EQ("none", shape(noEdge, rotations, graph.edges));
  auto unknownEdge = graph.edges;
  unknownEdge.pop_back();
  EXPECT_EQ("none", shape(graph.arcs, rotations, unknownEdge));
  auto duplicateEdge = graph.edges;
  duplicateEdge.push_back(duplicateEdge.front());
  EXPECT_EQ("none", shape(graph.arcs, rotations, duplicateEdge));
  auto duplicateArc = graph.arcs;
  duplicateArc.push_back(duplicateArc.front());
  EXPECT_EQ("none", shape(duplicateArc, rotations, graph.edges));

  // Rotations are node 0 {0F}, node 1 {0R, 1F}, node 2 {1R}.
  auto wrongEnd = rotations;
  wrongEnd.front().counterClockwise.front().orientation = Orientation::Reverse;
  EXPECT_EQ("none", shape(graph.arcs, wrongEnd, graph.edges));
  auto missing = rotations;
  missing.back().counterClockwise.clear();
  EXPECT_EQ("none", shape(graph.arcs, missing, graph.edges));
  auto repeatedNode = rotations;
  repeatedNode.push_back(repeatedNode.front());
  EXPECT_EQ("none", shape(graph.arcs, repeatedNode, graph.edges));
  auto repeatedIncidence = rotations;
  repeatedIncidence.front().counterClockwise.push_back(
      repeatedIncidence.front().counterClockwise.front());
  EXPECT_EQ("none", shape(graph.arcs, repeatedIncidence, graph.edges));
  auto foreign = rotations;
  foreign.front().counterClockwise.push_back(
      {NetworkArcId::from_index(7, kChainExtent).value(), Orientation::Forward});
  EXPECT_EQ("none", shape(graph.arcs, foreign, graph.edges));
  std::cout << "D5_CHAIN_RECEIPT case=rejections rejected=9 empty=accepted\n";
}

TEST(GlobalConformityBaseline, D5ChainSupportIsTheOrientedPathAndIsCountedOnce) {
  // Three unit arcs along x at h = 2, the middle one stored backwards. Alone
  // each has metric 1/2 and count 1; the chain has metric 3/2 and count 1.
  ChainGraph graph;
  add_arc(graph, 0, 1);
  add_arc(graph, 2, 1);
  add_arc(graph, 2, 3);
  Eigen::MatrixXd vertices = Eigen::MatrixXd::Zero(kChainExtent, 3);
  for (int x = 0; x < 4; ++x) vertices(x, 0) = x;
  const Eigen::VectorXd h = Eigen::VectorXd::Constant(kChainExtent, 2.0);
  const auto chains = derive_mandatory_chain_partition(
      graph.arcs, rotations_of(graph.arcs), graph.edges, {});
  ASSERT_EQ("0F,1R,2F", chain_shape(chains));
  const auto support = derive_mandatory_chain_support(chains->front(), graph.arcs);
  ASSERT_TRUE(support.has_value());
  std::vector<ConformitySupportPiece> expected;
  for (int x = 0; x < 3; ++x) {
    const auto edge =
        SourceEdgeTopologyKey::from_indices(x, x + 1, kChainExtent).value();
    expected.push_back({directional::authority::SourceEdgeSupport{edge},
                        edge.first(), edge.second()});
  }
  EXPECT_TRUE(expected == *support);
  const auto count = [&](std::vector<ConformitySupportPiece> pieces) {
    return derive_partition_stable_preferred_count_exact(
               ConformitySpanInput{
                   ConformitySpanId::from_network_arc(graph.arcs.front().id),
                   std::move(pieces)},
               vertices, h)
        .value_or(EInt(-1))
        .to_string();
  };
  EXPECT_EQ("1", count(*support));
  for (const auto &arc : graph.arcs) EXPECT_EQ("1", count(arc.sourcePath));

  // A gap, a broken orientation, an unknown arc or no arc is not a chain.
  const auto id = [&](int index) { return graph.arcs[index].id; };
  EXPECT_FALSE(derive_mandatory_chain_support(
                   BaselineMandatoryChain{{{id(0), Orientation::Forward},
                                           {id(2), Orientation::Forward}}},
                   graph.arcs)
                   .has_value());
  EXPECT_FALSE(derive_mandatory_chain_support(
                   BaselineMandatoryChain{{{id(0), Orientation::Reverse},
                                           {id(1), Orientation::Reverse}}},
                   graph.arcs)
                   .has_value());
  EXPECT_FALSE(derive_mandatory_chain_support(
                   BaselineMandatoryChain{
                       {{NetworkArcId::from_index(7, kChainExtent).value(),
                         Orientation::Forward}}},
                   graph.arcs)
                   .has_value());
  EXPECT_FALSE(
      derive_mandatory_chain_support(BaselineMandatoryChain{}, graph.arcs)
          .has_value());
  std::cout << "D5_CHAIN_RECEIPT case=support chainCount=1 arcCounts=1,1,1"
            << " rejected=4\n";
}

TEST(GlobalConformityBaseline, D5ChainPartitionCoversARealA2bPlanOnce) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  const auto &arcs = fixture.topology.arcs();
  const auto &rotations = fixture.topology.rotation_system();

  // The fixture gives every boundary edge its own rail, so nothing joins.
  const auto own = derive_mandatory_chain_partition(
      arcs, rotations, fixture.mandatoryEdges, {});
  ASSERT_TRUE(own.has_value());
  ASSERT_EQ(arcs.size(), own->size());
  for (const auto &chain : *own) {
    ASSERT_EQ(1U, chain.arcs.size());
    EXPECT_TRUE(chain.arcs.front().orientation == Orientation::Forward);
  }

  // On one rail, with no stop and with a stop at a Mandatory arc's first node,
  // every arc lies in exactly one continuous chain with a path support.
  auto oneRail = fixture.mandatoryEdges;
  ASSERT_FALSE(oneRail.empty());
  for (auto &edge : oneRail) edge.rail = oneRail.front().rail;
  const auto mandatory =
      std::find_if(arcs.begin(), arcs.end(), [](const auto &arc) {
        return arc.kind == GlobalTopologyArcKind::Mandatory;
      });
  ASSERT_NE(arcs.end(), mandatory);
  std::vector<std::size_t> chainCounts;
  for (const auto &stops : {std::set<NetworkNodeId>{},
                            std::set<NetworkNodeId>{mandatory->firstNode}}) {
    const auto chains =
        derive_mandatory_chain_partition(arcs, rotations, oneRail, stops);
    ASSERT_TRUE(chains.has_value());
    chainCounts.push_back(chains->size());
    std::set<NetworkArcId> seen;
    for (const auto &chain : *chains) {
      std::optional<NetworkNodeId> end;
      for (const auto &oriented : chain.arcs) {
        EXPECT_TRUE(seen.insert(oriented.arc).second);
        const auto *arc = fixture.topology.find_arc(oriented.arc);
        ASSERT_NE(nullptr, arc);
        const bool forward = oriented.orientation == Orientation::Forward;
        if (end) EXPECT_TRUE(*end == (forward ? arc->firstNode : arc->secondNode));
        end = forward ? arc->secondNode : arc->firstNode;
        if (chain.arcs.size() > 1U) {
          EXPECT_TRUE(arc->kind == GlobalTopologyArcKind::Mandatory);
        }
      }
      if (chain.arcs.size() > 1U) {
        EXPECT_TRUE(derive_mandatory_chain_support(chain, arcs).has_value());
      }
    }
    EXPECT_EQ(arcs.size(), seen.size());
  }
  std::cout << "D5_CHAIN_RECEIPT case=square arcs=" << arcs.size()
            << " ownRails=" << own->size() << " oneRail=" << chainCounts[0]
            << " oneRailStop=" << chainCounts[1] << "\n";
}

namespace {

using directional::geometry::AdaptiveFeatureCurve;
using directional::geometry::FieldAlignedCurveNetworkNode;
using directional::geometry::FieldAlignedSingularityPort;
using directional::geometry::global_conformity_baseline_detail::derive_mandatory_chain_stop_nodes;

FieldAlignedCurveNetworkNode stop_node(int node, int vertex) {
  return {chain_node(node),
          SourceVertexId::from_index(vertex, kChainExtent).value()};
}

FieldAlignedSingularityPort stop_port(int node, int vertex) {
  return {directional::authority::SingularityPortId::from_index(0, 1).value(),
          directional::authority::FieldSingularityId::from_index(0, 1).value(),
          chain_node(node),
          SourceVertexId::from_index(vertex, kChainExtent).value(),
          directional::authority::SourceComponentId::from_index(0, 1).value(),
          directional::authority::TopologyRegionId::from_index(0, 1).value(),
          1, 0};
}

// "1,4": stop node indices in order.
std::string stop_shape(const std::set<NetworkNodeId> &stops) {
  std::string out;
  for (const auto &stop : stops) {
    if (!out.empty()) out += ',';
    out += std::to_string(stop.index());
  }
  return out;
}

} // namespace

TEST(GlobalConformityBaseline,
     D5StopNodesReadPortsFeatureCurvesAndHardFeatureEdges) {
  // Node k sits on source vertex 7 - k, so a node index is never its vertex.
  std::vector<FieldAlignedCurveNetworkNode> nodes;
  for (int k = 0; k < 6; ++k) nodes.push_back(stop_node(k, 7 - k));
  const std::vector<FieldAlignedSingularityPort> ports{stop_port(4, 3)};
  // Edge 0 is a source boundary on nodes 0-1, edge 1 a hard feature on 2-3.
  ChainGraph graph;
  add_arc(graph, 0, 1);
  add_arc(graph, 2, 3);
  graph.edges[1].kind = SurfaceCellRailKind::HardFeature;
  // Vertex 2 carries node 5 and vertex 6 node 1; vertex 0 carries no node.
  AdaptiveFeatureCurve curve;
  curve.corners = {2, 0};
  curve.junctions = {6};

  EXPECT_EQ("", stop_shape(derive_mandatory_chain_stop_nodes(nodes, {}, {}, {})));
  EXPECT_EQ("4",
            stop_shape(derive_mandatory_chain_stop_nodes(nodes, ports, {}, {})));
  EXPECT_EQ("2,3", stop_shape(derive_mandatory_chain_stop_nodes(
                       nodes, {}, graph.edges, {})));
  EXPECT_EQ("1,5", stop_shape(derive_mandatory_chain_stop_nodes(nodes, {}, {},
                                                                {curve})));
  EXPECT_EQ("1,2,3,4,5", stop_shape(derive_mandatory_chain_stop_nodes(
                             nodes, ports, graph.edges, {curve})));

  // Row order does not matter.
  std::reverse(nodes.begin(), nodes.end());
  std::reverse(graph.edges.begin(), graph.edges.end());
  std::reverse(curve.corners.begin(), curve.corners.end());
  EXPECT_EQ("1,2,3,4,5", stop_shape(derive_mandatory_chain_stop_nodes(
                             nodes, ports, graph.edges, {curve})));
  std::cout << "D5_STOP_RECEIPT case=sources none= ports=4 hardFeature=2,3"
            << " curves=1,5 all=1,2,3,4,5 permuted=same\n";
}

TEST(GlobalConformityBaseline, D5StopNodesKeepHardFeatureRailsPerArc) {
  // Rail 0 is a source boundary 0-1-2-3 and rail 1 a hard feature 3-4-5.
  ChainGraph graph;
  add_arc(graph, 0, 1);
  add_arc(graph, 1, 2);
  add_arc(graph, 2, 3);
  add_arc(graph, 3, 4, GlobalTopologyArcKind::Mandatory, 1);
  add_arc(graph, 4, 5, GlobalTopologyArcKind::Mandatory, 1);
  graph.edges[3].kind = SurfaceCellRailKind::HardFeature;
  graph.edges[4].kind = SurfaceCellRailKind::HardFeature;
  std::vector<FieldAlignedCurveNetworkNode> nodes;
  for (int k = 0; k < 6; ++k) nodes.push_back(stop_node(k, k));
  const auto shape = [&](const std::vector<FieldAlignedSingularityPort> &ports,
                         const std::vector<AdaptiveFeatureCurve> &curves) {
    return chain_shape(derive_mandatory_chain_partition(
        graph.arcs, rotations_of(graph.arcs), graph.edges,
        derive_mandatory_chain_stop_nodes(nodes, ports, graph.edges, curves)));
  };

  // With no stop at all the two hard-feature arcs would join at node 4.
  EXPECT_EQ("0F,1F,2F|3F,4F", partition_shape(graph, {}));
  EXPECT_EQ("0F,1F,2F|3F|4F", shape({}, {}));
  // A feature corner on vertex 1 and a port on node 2 each cut the boundary.
  AdaptiveFeatureCurve corner;
  corner.corners = {1};
  EXPECT_EQ("0F|1F,2F|3F|4F", shape({}, {corner}));
  EXPECT_EQ("0F,1F|2F|3F|4F", shape({stop_port(2, 2)}, {}));
  std::cout << "D5_STOP_RECEIPT case=partition unstopped=0F,1F,2F|3F,4F"
            << " stage1=0F,1F,2F|3F|4F corner1=0F|1F,2F|3F|4F"
            << " port2=0F,1F|2F|3F|4F\n";
}

namespace {

using directional::geometry::BaselineConformityArcBinding;
using directional::geometry::global_conformity_baseline_detail::derive_span_arc_bindings;

// The inverse of chain_shape for one-digit arcs: "0F,1R|2F,3F".
std::vector<std::vector<GlobalTopologyOrientedArc>>
chains_of(const std::string &shape) {
  std::vector<std::vector<GlobalTopologyOrientedArc>> chains;
  if (!shape.empty()) chains.emplace_back();
  for (std::size_t k = 0U; k < shape.size(); k += 3U) {
    chains.back().push_back(
        {NetworkArcId::from_index(shape[k] - '0', kChainExtent).value(),
         shape[k + 1U] == 'F' ? Orientation::Forward : Orientation::Reverse});
    if (k + 2U < shape.size() && shape[k + 2U] == '|') chains.emplace_back();
  }
  return chains;
}

// "1=0.1R+2": arc 1 is ordinal 1 of span 0's chain, reversed, after 2 pieces.
std::string binding_shape(const ChainGraph &graph,
                          const std::vector<int> &spanArcs,
                          const std::string &chains) {
  std::vector<ConformitySpanInput> spans;
  for (const int arc : spanArcs) {
    spans.push_back({ConformitySpanId::from_network_arc(
                         NetworkArcId::from_index(arc, kChainExtent).value()),
                     {}});
  }
  const auto bindings = derive_span_arc_bindings(
      graph.arcs, rotations_of(graph.arcs), spans, chains_of(chains));
  if (!bindings) return "none";
  std::string out;
  for (const auto &[arc, binding] : *bindings) {
    if (!out.empty()) out += ',';
    out += std::to_string(arc.index());
    out += '=';
    out += std::to_string(binding.span.network_arc().index());
    out += '.';
    out += std::to_string(binding.chainOrdinal);
    out += binding.orientation == Orientation::Forward ? 'F' : 'R';
    out += '+';
    out += std::to_string(binding.firstSupportPiece);
  }
  return out;
}

// 0 -a0- 1 -a1- 2 -a2- 3 -a3- 4 -a4- 5: a1 is stored backwards, a4 is a trace,
// and a0 has two source pieces (only the number of pieces is read).
ChainGraph binding_path_graph() {
  ChainGraph graph;
  add_arc(graph, 0, 1);
  add_arc(graph, 2, 1);
  add_arc(graph, 2, 3);
  add_arc(graph, 3, 4);
  add_arc(graph, 4, 5, GlobalTopologyArcKind::Trace);
  graph.arcs[0].sourcePath.push_back(graph.arcs[0].sourcePath.front());
  return graph;
}

// The square's four Mandatory arcs as one continuous walk: the accepted
// partition on one rail with one stop.
std::vector<GlobalTopologyOrientedArc>
square_loop(const TopologyFixture &fixture) {
  auto oneRail = fixture.mandatoryEdges;
  for (auto &edge : oneRail) edge.rail = oneRail.front().rail;
  const auto chains = derive_mandatory_chain_partition(
      fixture.topology.arcs(), fixture.topology.rotation_system(), oneRail,
      {fixture.topology.arcs().front().firstNode});
  if (!chains || chains->size() != 1U) return {};
  return chains->front().arcs;
}

GlobalTopologyOrientedArc reversed(GlobalTopologyOrientedArc arc) {
  arc.orientation = directional::authority::reverse_orientation(arc.orientation);
  return arc;
}

// The per-arc input with the given chains: only a chain's first arc keeps its
// span.
GlobalConformityBaselineInput chained_input(
    const TopologyFixture &fixture,
    std::vector<std::vector<GlobalTopologyOrientedArc>> chains) {
  auto input = make_baseline_input(fixture, 1.0);
  for (const auto &chain : chains) {
    for (std::size_t k = 1U; k < chain.size(); ++k) {
      std::erase_if(input.spans, [&](const auto &span) {
        return span.id.network_arc() == chain[k].arc;
      });
    }
  }
  input.chains = std::move(chains);
  return input;
}

} // namespace

TEST(GlobalConformityBaseline, D5ArcBindingsFollowChainsAndKeepOtherSpansPerArc) {
  const auto graph = binding_path_graph();
  const std::string perArc = "0=0.0F+0,1=1.0F+0,2=2.0F+0,3=3.0F+0,4=4.0F+0";
  const std::string three = "0=0.0F+0,1=0.1R+2,2=0.2F+3,3=3.0F+0,4=4.0F+0";
  const std::string back = "0=2.2R+2,1=2.1F+1,2=2.0R+0,3=3.0F+0,4=4.0F+0";
  const std::string pairs = "0=0.0F+0,1=0.1R+2,2=2.0F+0,3=2.1F+1,4=4.0F+0";
  EXPECT_EQ(perArc, binding_shape(graph, {0, 1, 2, 3, 4}, ""));
  EXPECT_EQ(three, binding_shape(graph, {0, 3, 4}, "0F,1R,2F"));
  EXPECT_EQ(back, binding_shape(graph, {2, 3, 4}, "2R,1F,0R"));
  EXPECT_EQ(pairs, binding_shape(graph, {0, 2, 4}, "0F,1R|2F,3F"));
  // Neither the span order nor the chain order matters.
  EXPECT_EQ(pairs, binding_shape(graph, {4, 2, 0}, "2F,3F|0F,1R"));
  std::cout << "D5_BINDING_RECEIPT case=shapes perArc=" << perArc
            << " three=" << three << " back=" << back << " pairs=" << pairs
            << " permuted=same\n";
}

TEST(GlobalConformityBaseline, D5ArcBindingsRejectWhatIsNotAPartitionIntoChains) {
  auto graph = binding_path_graph();
  std::size_t rejected = 0U;
  const auto reject = [&](const std::vector<int> &spans, const std::string &chains) {
    EXPECT_EQ("none", binding_shape(graph, spans, chains)) << chains;
    ++rejected;
  };
  // A chain is two or more known Mandatory arcs, head to tail.
  reject({0, 1, 2, 3, 4}, "0F");
  reject({0, 1, 2, 3, 4}, "0F,7F");
  reject({0, 1, 2, 3}, "3F,4F");
  reject({0, 1, 3, 4}, "0F,2F");
  reject({0, 2, 3, 4}, "0F,1F");
  // Every arc has one span: its own, or the one that leads its chain.
  reject({0, 2, 3, 4}, "0F,1R|2R,1F");
  reject({0, 1, 2, 3, 4}, "0F,1R");
  reject({1, 2, 3, 4}, "0F,1R");
  reject({2, 3, 4}, "0F,1R");
  reject({0, 2, 3}, "0F,1R");
  reject({0, 2, 3, 4, 7}, "0F,1R");
  // A span given twice cannot stand in for a missing one.
  reject({0, 0, 4}, "0F,1R|2F,3F");
  reject({2, 2, 3, 4}, "0F,1R");
  reject({0, 0, 1, 2, 3, 4}, "");
  // A chain does not cross a node with a third incidence.
  add_arc(graph, 1, 6);
  reject({0, 2, 3, 4, 5}, "0F,1R");
  EXPECT_EQ("0=0.0F+0,1=1.0F+0,2=2.0F+0,3=2.1F+1,4=4.0F+0,5=5.0F+0",
            binding_shape(graph, {0, 1, 2, 4, 5}, "2F,3F"));
  EXPECT_EQ(15U, rejected);
  std::cout << "D5_BINDING_RECEIPT case=rejections rejected=" << rejected
            << " branchSibling=accepted\n";
}

TEST(GlobalConformityBaseline, D5ChainedSpansScheduleOnceAndReadTheirSideAtTheIdentifyingArc) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  const auto loop = square_loop(fixture);
  ASSERT_EQ(4U, loop.size());
  ASSERT_EQ(1U, fixture.topology.regions().size());
  const auto &walk = fixture.topology.regions().front().boundary;
  ASSERT_EQ(4U, walk.size());
  const auto walk_orientation = [&](NetworkArcId arc) {
    return std::find_if(walk.begin(), walk.end(), [&](const auto &entry) {
             return entry.arc == arc;
           })->orientation;
  };
  // The walk goes round the loop one way: with it or against it throughout.
  const bool withLoop = walk_orientation(loop[0].arc) == loop[0].orientation;
  for (const auto &arc : loop) {
    EXPECT_EQ(withLoop, walk_orientation(arc.arc) == arc.orientation);
  }
  const auto build = [&](const GlobalConformityBaselineInput &input) {
    return directional::geometry::build_global_conformity_baseline(
        fixture.topology, input);
  };
  // Each incidence sits where the walk meets its span's identifying arc.
  const auto expect_sides = [&](const GlobalConformityBaselinePlan &plan) {
    ASSERT_EQ(plan.schedule().size(), plan.incidences().size());
    for (const auto &incidence : plan.incidences()) {
      const auto ordinal = incidence.id.canonicalBoundaryOccurrenceOrdinal;
      ASSERT_LT(ordinal, walk.size());
      EXPECT_TRUE(walk[ordinal].arc == incidence.span.network_arc());
    }
  };
  const auto side = [](const GlobalConformityBaselinePlan &plan,
                       NetworkArcId arc) {
    return std::find_if(plan.incidences().begin(), plan.incidences().end(),
                        [&](const auto &incidence) {
                          return incidence.span.network_arc() == arc;
                        })
        ->orientation;
  };
  const auto span_of = [](const GlobalTopologyOrientedArc &arc) {
    return ConformitySpanId::from_network_arc(arc.arc);
  };

  // Without chains every arc is its own span, read as the walk reads it.
  const auto perArcInput = make_baseline_input(fixture, 1.0);
  const auto perArc = build(perArcInput);
  ASSERT_TRUE(perArc);
  expect_sides(perArc.value());
  EXPECT_EQ((std::vector<int>{1, 1, 1, 1}), exact_counts(perArc.value()));
  for (const auto &arc : loop) {
    const auto *binding = perArc.value().find_arc_binding(arc.arc);
    ASSERT_NE(nullptr, binding);
    EXPECT_TRUE(*binding == BaselineConformityArcBinding{span_of(arc)});
    EXPECT_TRUE(side(perArc.value(), arc.arc) == walk_orientation(arc.arc));
  }

  // Two arcs as one span: three spans of count 1 bound an odd region, so one
  // flips, as on the triangle.
  const auto pairInput = chained_input(fixture, {{loop[0], loop[1]}});
  const auto pair = build(pairInput);
  ASSERT_TRUE(pair);
  expect_sides(pair.value());
  EXPECT_EQ(nullptr, pair.value().find_schedule(span_of(loop[1])));
  EXPECT_EQ((std::vector<int>{1, 1, 2}), exact_counts(pair.value()));
  EXPECT_EQ(EInt(1), pair.value().certificate().minimumFlipCount);
  EXPECT_TRUE(pair.value().certificate().regions.front().finalParityEven);
  const std::size_t firstPieces =
      fixture.topology.find_arc(loop[0].arc)->sourcePath.size();
  EXPECT_TRUE(*pair.value().find_arc_binding(loop[0].arc) ==
              (BaselineConformityArcBinding{span_of(loop[0]), 0U,
                                            loop[0].orientation, 0U}));
  EXPECT_TRUE(*pair.value().find_arc_binding(loop[1].arc) ==
              (BaselineConformityArcBinding{span_of(loop[0]), 1U,
                                            loop[1].orientation, firstPieces}));
  EXPECT_TRUE(*pair.value().find_arc_binding(loop[2].arc) ==
              BaselineConformityArcBinding{span_of(loop[2])});
  EXPECT_EQ(withLoop, side(pair.value(), loop[0].arc) == Orientation::Forward);

  // The same two arcs led from the other end are read the other way.
  const auto backInput =
      chained_input(fixture, {{reversed(loop[1]), reversed(loop[0])}});
  const auto back = build(backInput);
  ASSERT_TRUE(back);
  expect_sides(back.value());
  EXPECT_EQ(nullptr, back.value().find_schedule(span_of(loop[0])));
  EXPECT_EQ(withLoop, side(back.value(), loop[1].arc) == Orientation::Reverse);
  EXPECT_TRUE(*back.value().find_arc_binding(loop[0].arc) ==
              (BaselineConformityArcBinding{
                  span_of(loop[1]), 1U,
                  directional::authority::reverse_orientation(loop[0].orientation),
                  fixture.topology.find_arc(loop[1].arc)->sourcePath.size()}));

  // Two chains: two spans of count 1 bound an even region, so nothing flips.
  const auto pairsInput =
      chained_input(fixture, {{loop[0], loop[1]}, {loop[2], loop[3]}});
  const auto pairs = build(pairsInput);
  ASSERT_TRUE(pairs);
  expect_sides(pairs.value());
  EXPECT_EQ((std::vector<int>{1, 1}), exact_counts(pairs.value()));
  EXPECT_EQ(EInt(0), pairs.value().certificate().minimumFlipCount);
  auto permuted = pairsInput;
  std::reverse(permuted.spans.begin(), permuted.spans.end());
  std::reverse(permuted.chains.begin(), permuted.chains.end());
  const auto permutedPairs = build(permuted);
  ASSERT_TRUE(permutedPairs);
  EXPECT_EQ(pairs.value().semantic_digest(),
            permutedPairs.value().semantic_digest());

  // The four problems are different problems, and each candidate validates
  // against its own input only.
  const std::vector<const GlobalConformityBaselineInput *> inputs{
      &perArcInput, &pairInput, &backInput, &pairsInput};
  const std::vector<const GlobalConformityBaselinePlan *> plans{
      &perArc.value(), &pair.value(), &back.value(), &pairs.value()};
  std::set<std::uint64_t> digests;
  std::size_t crossRejected = 0U;
  for (std::size_t plan = 0U; plan < plans.size(); ++plan) {
    digests.insert(plans[plan]->certificate().normalizedProblemDigest);
    const auto candidate = plans[plan]->validation_candidate();
    for (std::size_t input = 0U; input < inputs.size(); ++input) {
      const auto error =
          directional::geometry::validate_global_conformity_baseline_candidate(
              fixture.topology, *inputs[input], candidate);
      EXPECT_EQ(plan != input, error.has_value());
      if (error) ++crossRejected;
    }
  }
  EXPECT_EQ(4U, digests.size());
  EXPECT_EQ(12U, crossRejected);
  std::cout << "D5_BINDING_RECEIPT case=square perArc=1,1,1,1 pair=1,1,2"
            << " pairs=1,1 backSide=opposite digests=" << digests.size()
            << " crossRejected=" << crossRejected << "\n";
}

TEST(GlobalConformityBaseline, D5BaselineRejectsChainsThatDoNotPartitionTheArcs) {
  const auto fixture = make_topology_fixture(make_square_mesh());
  const auto loop = square_loop(fixture);
  ASSERT_EQ(4U, loop.size());
  const auto detail = [&](const GlobalConformityBaselineInput &input) {
    const auto built = directional::geometry::build_global_conformity_baseline(
        fixture.topology, input);
    if (built) return std::string("built");
    EXPECT_TRUE(built.error().code ==
                directional::geometry::GlobalConformityPlanErrorCode::
                    InvalidTopologyBinding);
    return built.error().detail;
  };
  const std::string count = "baseline schedules every full A2b arc exactly once";
  const std::string partition = "baseline chains do not partition the A2b arcs";

  // A chained arc that keeps its own span is counted twice.
  auto kept = make_baseline_input(fixture, 1.0);
  kept.chains = {{loop[0], loop[1]}};
  EXPECT_EQ(count, detail(kept));
  // Arcs that do not meet are not a chain.
  EXPECT_EQ(partition, detail(chained_input(fixture, {{loop[0], loop[2]}})));
  // Nor are two arcs taken against their direction.
  EXPECT_EQ(partition,
            detail(chained_input(fixture, {{reversed(loop[0]), reversed(loop[1])}})));
  // A chain is led by its first arc, not its second.
  auto headless = chained_input(fixture, {{loop[1], loop[0]}});
  headless.chains = {{loop[0], loop[1]}};
  EXPECT_EQ(partition, detail(headless));
  // One arc is not a chain.
  auto single = make_baseline_input(fixture, 1.0);
  single.chains = {{loop[0]}};
  EXPECT_EQ(partition, detail(single));
  std::cout << "D5_BINDING_RECEIPT case=baselineRejections count=1 partition=4\n";
}
