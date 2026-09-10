#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <set>
#include <string>
#include <stdexcept>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/GlobalConformityPlan.h>
#include <directional/geometry/GlobalTopologyPlan.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SourceTopologyRegions.h>
#include <directional/geometry/SurfaceCutGraph.h>

#include "../src/geometry/GlobalConformityExactSolver.h"
#include "../src/geometry/GlobalConformityExactWeight.h"

namespace {

using directional::TriMesh;
using directional::authority::FieldExactRational;
using directional::authority::HardRailId;
using directional::authority::SourceEdgeTopologyKey;
using directional::authority::SourceFaceTopologyKey;
using directional::geometry::SourceTopologyRegions;
using directional::authority::SourceVertexId;
using directional::fields::CrossFieldEdgeTransition;
using directional::fields::CrossFieldResult;
using directional::geometry::ConformityFamily;
using directional::geometry::ConformityIncidence;
using directional::geometry::ConformitySign;
using directional::geometry::ConformitySpanId;
using directional::geometry::ConformitySpanInput;
using directional::geometry::ConformitySupportPiece;
using directional::geometry::FieldAlignedCurveNetwork;
using directional::geometry::GlobalConformityKnownFeasibleInput;
using directional::geometry::GlobalConformityPlan;
using directional::geometry::GlobalTopologyPlan;
using directional::geometry::SurfaceCellRail;
using directional::geometry::SurfaceCellRailKind;
using directional::geometry::SurfaceCellTracingOptions;
using directional::geometry::global_conformity_detail::ExactWeight;
using directional::geometry::global_conformity_detail::SolverIncidenceEnd;
using directional::geometry::global_conformity_detail::SolverSpan;

EInt exact_power(EInt base, std::size_t exponent) {
  EInt result(1);
  while (exponent != 0U) {
    if ((exponent & 1U) != 0U) result *= base;
    exponent >>= 1U;
    if (exponent != 0U) base *= base;
  }
  return result;
}

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

struct SquareTopologyFixture {
  TriMesh mesh;
  GlobalTopologyPlan topology;
};

SquareTopologyFixture make_square_topology_fixture() {
  TriMesh mesh = make_square_mesh();
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

FieldExactRational half() {
  return *FieldExactRational::from_ratio(1, 2);
}

GlobalConformityKnownFeasibleInput make_known_feasible_input(
    const SquareTopologyFixture &fixture, bool twoPieces = true) {
  GlobalConformityKnownFeasibleInput input;
  input.sourceVertices = fixture.mesh.V;
  input.targetSize = Eigen::VectorXd::Ones(fixture.mesh.V.rows());

  for (const auto &arc : fixture.topology.arcs()) {
    SourceFaceTopologyKey face = !arc.sourceFaces.empty()
                                     ? arc.sourceFaces.front()
                                     : SourceFaceTopologyKey::make(
                                           std::array<SourceVertexId, 3>{
                                               SourceVertexId::from_index(0, 4).value(),
                                               SourceVertexId::from_index(1, 4).value(),
                                               SourceVertexId::from_index(2, 4).value()})
                                           .value();
    const auto first = face.vertices()[0];
    const auto second = face.vertices()[1];
    const auto supportEdge = SourceEdgeTopologyKey::make(first, second).value();
    const directional::geometry::ConformityEdgePoint midpoint{supportEdge, half()};
    ConformitySpanInput span{ConformitySpanId::from_network_arc(arc.id), {}};
    if (twoPieces) {
      span.supportPieces.push_back(
          {directional::authority::SourceEdgeSupport{supportEdge}, first, midpoint});
      span.supportPieces.push_back(
          {directional::authority::SourceEdgeSupport{supportEdge}, midpoint, second});
    } else {
      span.supportPieces.push_back(
          {directional::authority::SourceEdgeSupport{supportEdge}, first, second});
    }
    input.spans.push_back(std::move(span));
  }

  for (const auto &region : fixture.topology.regions()) {
    for (std::size_t ordinal = 0; ordinal < region.boundary.size(); ++ordinal) {
      const auto &boundary = region.boundary[ordinal];
      input.incidences.push_back({
          {region.id, ordinal}, ConformitySpanId::from_network_arc(boundary.arc),
          ConformityFamily::U,
          (ordinal & 1U) == 0U ? ConformitySign::Positive
                              : ConformitySign::Negative,
          boundary.orientation});
    }
  }
  return input;
}

std::vector<SolverSpan> two_row_equal_counts_problem(EInt firstPreferred,
                                                     EInt secondPreferred) {
  return {
      {0U, {{0U, +1}, {1U, -1}}, std::move(firstPreferred), EInt(1), EInt(1), EInt(0), true},
      {1U, {{0U, -1}, {1U, +1}}, std::move(secondPreferred), EInt(1), EInt(1), EInt(0), true},
  };
}

std::vector<SolverSpan> same_row_bidirected_problem() {
  return {
      {0U, {{0U, +1}, {0U, +1}}, EInt(2), EInt(1), EInt(1), EInt(0), true},
      {1U, {{0U, -1}, {0U, -1}}, EInt(4), EInt(1), EInt(1), EInt(0), true},
  };
}

std::vector<EInt> tiny_exhaustive_equal_counts_oracle(
    const EInt &firstPreferred, const EInt &secondPreferred) {
  static constexpr int kMax = 8;
  bool haveBest = false;
  EInt bestPrimary;
  int best = 0;
  for (int x = 1; x <= kMax; ++x) {
    const EInt exactX(x);
    const EInt primary =
        (exactX - firstPreferred).abs() + (exactX - secondPreferred).abs();
    if (!haveBest || primary < bestPrimary ||
        (primary == bestPrimary && x < best)) {
      haveBest = true;
      bestPrimary = primary;
      best = x;
    }
  }
  return {EInt(best), EInt(best)};
}

}  // namespace

TEST(GlobalConformityPlan,
     MultiPieceCompactOrdinalsAndReverseIncidenceSymmetry) {
  const auto fixture = make_square_topology_fixture();
  const auto input = make_known_feasible_input(fixture, true);
  const auto built = GlobalConformityPlan::make_known_feasible(fixture.topology, input);
  ASSERT_TRUE(built) << directional::geometry::global_conformity_plan_error_code_name(
      built.error().code);
  const auto &plan = built.value();
  ASSERT_EQ(fixture.topology.arcs().size(), plan.schedule().size());
  for (const auto &entry : plan.schedule()) {
    ASSERT_EQ(2U, entry.supportPieces.size());
    const auto first = plan.breakpoint_location(entry.span, EInt(0));
    const auto last = plan.breakpoint_location(entry.span, entry.count);
    ASSERT_TRUE(first);
    ASSERT_TRUE(last);
    EXPECT_TRUE(first->firstEndpoint);
    EXPECT_TRUE(last->lastEndpoint);
    EXPECT_LE(plan.validation_candidate().schedule.size(), fixture.topology.arcs().size());
    if (entry.count > EInt(1)) {
      const auto forward = plan.breakpoint_location(entry.span, EInt(1));
      const auto reverse = plan.breakpoint_location(entry.span, entry.count - EInt(1));
      ASSERT_TRUE(forward);
      ASSERT_TRUE(reverse);
      EXPECT_EQ(EInt(1), forward->id.exactOrdinal);
      EXPECT_EQ(entry.count - EInt(1), reverse->id.exactOrdinal);
    }
  }
}

TEST(GlobalConformityExactSolver,
     PreservesSameRowBidirectedMultiplicityPositivityAndParity) {
  auto result = directional::geometry::global_conformity_detail::solve_exact_schedule(
      1U, same_row_bidirected_problem());
  ASSERT_TRUE(result.success) << result.failure;
  ASSERT_EQ(2U, result.counts.size());
  EXPECT_EQ(result.counts[0], result.counts[1]);
  EXPECT_GE(result.counts[0], EInt(1));
  EXPECT_EQ(EInt(0), (EInt(2) * result.counts[0] - EInt(2) * result.counts[1]));
  EXPECT_EQ(EInt(0), (EInt(2) * result.counts[0]) % EInt(2));
  EXPECT_EQ(2, result.ledger.refinementM);
  EXPECT_TRUE(result.ledger.terminalExactNonImprovementValidated);
  EXPECT_GE(result.ledger.terminalRefinementCostChange, EInt(0));
}

TEST(GlobalConformityPlan,
     ExactBinary64IngressCanonicalizesSignedZeroAndSubnormal) {
  const auto positiveZero = FieldExactRational::from_double_exact(+0.0);
  const auto negativeZero = FieldExactRational::from_double_exact(-0.0);
  const auto subnormal = FieldExactRational::from_double_exact(
      std::numeric_limits<double>::denorm_min());
  ASSERT_TRUE(positiveZero);
  ASSERT_TRUE(negativeZero);
  ASSERT_TRUE(subnormal);
  EXPECT_EQ(*positiveZero, *negativeZero);
  EXPECT_EQ(EInt(0), negativeZero->exact_numerator());
  EXPECT_EQ(EInt(1), negativeZero->exact_denominator());
  EXPECT_EQ(EInt(1), subnormal->exact_numerator());
  EXPECT_GT(subnormal->exact_denominator().magnitude_bits(), 1000U);
  EXPECT_FALSE(FieldExactRational::from_double_exact(
      std::numeric_limits<double>::infinity()));
}

TEST(GlobalConformityExactSolver,
     HugeExactCapRadixAndLexObjectiveNeverNarrow) {
  const EInt huge = exact_power(EInt(2), 130U) + EInt(3);
  auto spans = two_row_equal_counts_problem(huge, huge);
  auto result = directional::geometry::global_conformity_detail::solve_exact_schedule(
      2U, spans);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_GT(result.u.magnitude_bits(), 64U);
  EXPECT_GT(result.q.magnitude_bits(), 64U);
  EXPECT_GT(result.l.magnitude_bits(), 128U);
  EXPECT_GT(result.ledger.maximumTargetBitWidth, 64U);
  EXPECT_GT(result.ledger.maximumCapacityBitWidth, 64U);
  EXPECT_EQ(0U, result.ledger.retryResetCount);

  ExactWeight exact(huge * huge);
  EXPECT_TRUE(exact.finite());
  EXPECT_EQ(huge * huge, exact.exact());
  EXPECT_GT(exact.exact().magnitude_bits(), 128U);
}

TEST(GlobalConformityExactSolver,
     FixedM2RefinementMatchesSeparateTinyExhaustiveOracle) {
  const EInt firstPreferred(3), secondPreferred(1);
  const auto expected =
      tiny_exhaustive_equal_counts_oracle(firstPreferred, secondPreferred);
  auto result = directional::geometry::global_conformity_detail::solve_exact_schedule(
      2U, two_row_equal_counts_problem(firstPreferred, secondPreferred));
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(expected, result.counts);
  EXPECT_EQ(2, result.ledger.refinementM);
  EXPECT_EQ(result.ledger.refinementCount, result.ledger.refinements.size());
  for (const auto &step : result.ledger.refinements) {
    EXPECT_LT(step.after.scalarValue, step.before.scalarValue);
  }
  EXPECT_TRUE(result.ledger.terminalExactNonImprovementValidated);
  EXPECT_GE(result.ledger.terminalRefinementCostChange, EInt(0));
}

TEST(GlobalConformityExactSolver,
     GenuinelyBidirectedLoopPermutationAndReversalAreDeterministic) {
  auto baseline = directional::geometry::global_conformity_detail::solve_exact_schedule(
      1U, same_row_bidirected_problem());
  ASSERT_TRUE(baseline.success) << baseline.failure;

  auto permuted = same_row_bidirected_problem();
  std::reverse(permuted.begin(), permuted.end());
  std::swap(permuted[0].semanticIndex, permuted[1].semanticIndex);
  for (auto &span : permuted) {
    std::reverse(span.ends.begin(), span.ends.end());
  }
  auto reordered = directional::geometry::global_conformity_detail::solve_exact_schedule(
      1U, std::move(permuted));
  ASSERT_TRUE(reordered.success) << reordered.failure;
  EXPECT_EQ(baseline.objective.primaryDeviation,
            reordered.objective.primaryDeviation);
  EXPECT_EQ(baseline.ledger.retryResetCount, reordered.ledger.retryResetCount);
}

TEST(GlobalConformityPlan, IndependentValidatorRejectsTamperMatrix) {
  const auto fixture = make_square_topology_fixture();
  const auto input = make_known_feasible_input(fixture, false);
  const auto built = GlobalConformityPlan::make_known_feasible(fixture.topology, input);
  ASSERT_TRUE(built) << directional::geometry::global_conformity_plan_error_code_name(
      built.error().code);
  const auto &plan = built.value();

  auto candidate = plan.validation_candidate();
  ASSERT_FALSE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, candidate));

  auto badCount = candidate;
  badCount.schedule.front().count = EInt(0);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badCount));

  auto badBinding = candidate;
  badBinding.topologyPlanDigest ^= 1U;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badBinding));

  auto badObjective = candidate;
  badObjective.objective.scalarValue += EInt(1);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badObjective));

  auto badCap = candidate;
  badCap.finiteCapU += EInt(1);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badCap));

  auto badRadix = candidate;
  badRadix.radixQ += EInt(1);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badRadix));

  auto badLedger = candidate;
  badLedger.workLedger.refinementM = 3;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badLedger));

  auto badIncidence = candidate;
  ASSERT_FALSE(badIncidence.incidences.empty());
  badIncidence.incidences.pop_back();
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badIncidence));

  auto badParity = candidate;
  ASSERT_GE(badParity.incidences.size(), 2U);
  badParity.incidences.front().sign =
      badParity.incidences.front().sign == ConformitySign::Positive
          ? ConformitySign::Negative
          : ConformitySign::Positive;
  EXPECT_TRUE(directional::geometry::validate_global_conformity_candidate(
      fixture.topology, input, badParity));
}

TEST(GlobalConformityExactSolver,
     ExactValuesExceedLibSatsumaAndBlossomScalarWidths) {
  static_assert(std::numeric_limits<ExactWeight>::is_exact);
  static_assert(std::numeric_limits<ExactWeight>::is_integer);
  const EInt beyondSigned64 = exact_power(EInt(2), 191U) + EInt(17);
  ExactWeight a(beyondSigned64);
  ExactWeight b(beyondSigned64 + EInt(1));
  EXPECT_LT(a, b);
  EXPECT_EQ(EInt(2) * beyondSigned64, (a + a).exact());
  EXPECT_GT((a + a).exact().magnitude_bits(), 64U);
}
