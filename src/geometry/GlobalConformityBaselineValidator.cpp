#include <directional/geometry/GlobalConformityBaseline.h>

#include "GlobalConformityBaselineSupport.h"
#include "GlobalConformityParityGraph.h"

#include <algorithm>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace directional::geometry {
namespace {

using global_conformity_baseline_detail::ParityFixedChoices;
using global_conformity_baseline_detail::ParityGraphProblem;

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

GlobalConformityPlanError validation_error(std::string detail) {
  return {GlobalConformityPlanErrorCode::ExactValidationFailed, std::nullopt,
          std::nullopt, std::move(detail)};
}

void hash_byte(std::uint64_t &hash, std::uint8_t value) {
  hash ^= value;
  hash *= kFnvPrime;
}
void hash_u64(std::uint64_t &hash, std::uint64_t value) {
  for (unsigned shift = 0; shift < 64U; shift += 8U) {
    hash_byte(hash, static_cast<std::uint8_t>((value >> shift) & 0xffU));
  }
}
void hash_string(std::uint64_t &hash, const std::string &value) {
  hash_u64(hash, static_cast<std::uint64_t>(value.size()));
  for (const unsigned char byte : value) hash_byte(hash, byte);
}
void hash_eint(std::uint64_t &hash, const EInt &value) {
  hash_string(hash, value.to_string());
}
template <class Id> void hash_id(std::uint64_t &hash, Id id) {
  hash_u64(hash, static_cast<std::uint64_t>(Id::domain()));
  hash_u64(hash, static_cast<std::uint64_t>(id.index()));
}
void hash_exact(std::uint64_t &hash,
                const authority::FieldExactRational &value) {
  hash_eint(hash, value.exact_numerator());
  hash_eint(hash, value.exact_denominator());
}
void hash_point(std::uint64_t &hash, const ConformitySourcePoint &point) {
  hash_u64(hash, static_cast<std::uint64_t>(point.index()));
  if (const auto *vertex = std::get_if<authority::SourceVertexId>(&point)) {
    hash_id(hash, *vertex);
  } else if (const auto *edge = std::get_if<ConformityEdgePoint>(&point)) {
    hash_id(hash, edge->edge.first());
    hash_id(hash, edge->edge.second());
    hash_exact(hash, edge->parameter);
  } else {
    const auto &face = std::get<ConformityFacePoint>(point);
    for (const auto vertex : face.face.vertices()) hash_id(hash, vertex);
    for (const auto &coordinate : face.barycentric) hash_exact(hash, coordinate);
  }
}
void hash_support(std::uint64_t &hash,
                  const authority::SourceSupport &support) {
  hash_u64(hash, static_cast<std::uint64_t>(support.index()));
  if (const auto *vertex =
          std::get_if<authority::SourceVertexSupport>(&support)) {
    hash_id(hash, vertex->vertex);
  } else if (const auto *edge =
                 std::get_if<authority::SourceEdgeSupport>(&support)) {
    hash_id(hash, edge->edge.first());
    hash_id(hash, edge->edge.second());
  } else {
    for (const auto vertex :
         std::get<authority::SourceFaceInteriorSupport>(support).face.vertices()) {
      hash_id(hash, vertex);
    }
  }
}
void hash_span(std::uint64_t &hash, const ConformitySpanInput &span,
               const EInt &preferred) {
  hash_id(hash, span.id.network_arc());
  hash_eint(hash, preferred);
  hash_u64(hash, static_cast<std::uint64_t>(span.supportPieces.size()));
  for (const auto &piece : span.supportPieces) {
    hash_support(hash, piece.carrier);
    hash_point(hash, piece.first);
    hash_point(hash, piece.second);
  }
}
void hash_incidence(std::uint64_t &hash,
                    const BaselineConformityIncidence &incidence) {
  hash_id(hash, incidence.id.region);
  hash_u64(hash, static_cast<std::uint64_t>(
                     incidence.id.canonicalBoundaryOccurrenceOrdinal));
  hash_id(hash, incidence.span.network_arc());
  hash_u64(hash, static_cast<std::uint64_t>(
                     static_cast<int>(incidence.orientation) + 1));
}

struct DisjointSet {
  explicit DisjointSet(std::size_t count) : parent(count) {
    std::iota(parent.begin(), parent.end(), std::size_t{0});
  }
  std::size_t find(std::size_t value) {
    if (parent[value] != value) parent[value] = find(parent[value]);
    return parent[value];
  }
  void unite(std::size_t first, std::size_t second) {
    first = find(first);
    second = find(second);
    if (first == second) return;
    if (first > second) std::swap(first, second);
    parent[second] = first;
  }
  std::vector<std::size_t> parent;
};

struct IndependentProblem {
  std::vector<ConformitySpanInput> spans;
  std::vector<EInt> preferred;
  std::vector<BaselineConformityIncidence> incidences;
  std::vector<authority::NetworkRegionId> regions;
  std::vector<std::vector<std::size_t>> spanEnds;
  std::vector<bool> residual;
  std::vector<BaselineConformityComponentReceipt> components;
  ParityGraphProblem graph;
  std::uint64_t metricDigest = 0U;
  std::uint64_t normalizedDigest = 0U;
};

std::optional<IndependentProblem> rebuild_problem(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineInput &input) {
  if (input.sourceVertices.cols() != 3 || input.sourceVertices.rows() <= 0 ||
      input.targetSize.size() != input.sourceVertices.rows()) {
    return std::nullopt;
  }
  IndependentProblem out;
  out.metricDigest =
      global_conformity_baseline_detail::exact_target_metric_digest(input.targetSize);
  if (out.metricDigest == 0U) return std::nullopt;

  out.spans = input.spans;
  std::sort(out.spans.begin(), out.spans.end(),
            [](const auto &first, const auto &second) {
              return first.id < second.id;
            });
  if (out.spans.size() != topology.arcs().size()) return std::nullopt;

  std::map<ConformitySpanId, std::size_t> spanIndex;
  for (std::size_t span = 0U; span < out.spans.size(); ++span) {
    if ((span != 0U && out.spans[span - 1U].id == out.spans[span].id) ||
        topology.find_arc(out.spans[span].id.network_arc()) == nullptr) {
      return std::nullopt;
    }
    const auto preferred =
        global_conformity_baseline_detail::derive_preferred_count_exact(
            out.spans[span], input.sourceVertices, input.targetSize);
    if (!preferred) return std::nullopt;
    out.preferred.push_back(*preferred);
    spanIndex.emplace(out.spans[span].id, span);
  }

  std::vector<const GlobalTopologyRegion *> regions;
  for (const auto &region : topology.regions()) regions.push_back(&region);
  std::sort(regions.begin(), regions.end(), [](const auto *first, const auto *second) {
    return first->id < second->id;
  });
  if (regions.empty()) return std::nullopt;
  std::map<authority::NetworkRegionId, std::size_t> regionIndex;
  for (std::size_t region = 0U; region < regions.size(); ++region) {
    out.regions.push_back(regions[region]->id);
    regionIndex.emplace(regions[region]->id, region);
  }

  out.spanEnds.resize(out.spans.size());
  for (const auto *region : regions) {
    for (std::size_t ordinal = 0U; ordinal < region->boundary.size(); ++ordinal) {
      const auto &boundary = region->boundary[ordinal];
      const auto span = ConformitySpanId::from_network_arc(boundary.arc);
      const auto found = spanIndex.find(span);
      if (found == spanIndex.end()) return std::nullopt;
      out.incidences.push_back({{region->id, ordinal}, span,
                                boundary.orientation});
      out.spanEnds[found->second].push_back(regionIndex.at(region->id));
    }
  }
  for (const auto &ends : out.spanEnds) {
    if (ends.empty() || ends.size() > 2U) return std::nullopt;
  }

  out.residual.assign(out.regions.size(), false);
  for (const auto &incidence : out.incidences) {
    const auto span = spanIndex.at(incidence.span);
    if (out.preferred[span] % EInt(2) != EInt(0)) {
      const auto region = regionIndex.at(incidence.id.region);
      out.residual[region] = !out.residual[region];
    }
  }

  DisjointSet dsu(out.regions.size());
  for (const auto &ends : out.spanEnds) {
    if (ends.size() == 2U && ends[0] != ends[1]) dsu.unite(ends[0], ends[1]);
  }
  std::map<std::size_t, std::vector<std::size_t>> grouped;
  for (std::size_t region = 0U; region < out.regions.size(); ++region) {
    grouped[dsu.find(region)].push_back(region);
  }
  std::vector<std::vector<std::size_t>> groups;
  for (auto &[root, members] : grouped) {
    (void)root;
    std::sort(members.begin(), members.end());
    groups.push_back(std::move(members));
  }
  std::sort(groups.begin(), groups.end(), [](const auto &first, const auto &second) {
    return first.front() < second.front();
  });

  std::vector<std::size_t> componentOf(out.regions.size(), 0U);
  for (std::size_t component = 0U; component < groups.size(); ++component) {
    BaselineConformityComponentReceipt receipt;
    receipt.componentOrdinal = component;
    for (const auto region : groups[component]) {
      componentOf[region] = component;
      receipt.regions.push_back(out.regions[region]);
    }
    out.components.push_back(std::move(receipt));
  }
  for (std::size_t span = 0U; span < out.spanEnds.size(); ++span) {
    if (out.spanEnds[span].size() == 1U) {
      auto &component = out.components[componentOf[out.spanEnds[span][0]]];
      component.hasExterior = true;
      component.terminalSpans.push_back(out.spans[span].id);
    }
  }

  std::vector<std::optional<std::size_t>> exterior(groups.size());
  std::size_t vertexCount = out.regions.size();
  for (std::size_t component = 0U; component < groups.size(); ++component) {
    if (!out.components[component].hasExterior) continue;
    exterior[component] = vertexCount++;
    bool demand = false;
    for (const auto region : groups[component]) demand = demand != out.residual[region];
    out.components[component].exteriorDemandOdd = demand;
  }

  out.graph.vertexCount = vertexCount;
  out.graph.demand.assign(vertexCount, false);
  for (std::size_t region = 0U; region < out.regions.size(); ++region) {
    out.graph.demand[region] = out.residual[region];
  }
  for (std::size_t component = 0U; component < groups.size(); ++component) {
    if (exterior[component]) {
      out.graph.demand[*exterior[component]] =
          out.components[component].exteriorDemandOdd;
    }
  }
  for (std::size_t span = 0U; span < out.spanEnds.size(); ++span) {
    const auto &ends = out.spanEnds[span];
    if (ends.size() == 2U) {
      out.graph.edges.push_back({span, ends[0], ends[1]});
    } else {
      const auto component = componentOf[ends[0]];
      if (!exterior[component]) return std::nullopt;
      out.graph.edges.push_back({span, ends[0], *exterior[component]});
    }
  }

  std::uint64_t hash = kFnvOffset;
  hash_string(hash, "GlobalConformityBaselineProblem-v1");
  hash_u64(hash, topology.source_digest());
  hash_u64(hash, topology.network_digest());
  hash_u64(hash, topology.cut_graph_digest());
  hash_u64(hash, topology.semantic_digest());
  hash_u64(hash, out.metricDigest);
  hash_u64(hash, static_cast<std::uint64_t>(out.spans.size()));
  for (std::size_t span = 0U; span < out.spans.size(); ++span) {
    hash_span(hash, out.spans[span], out.preferred[span]);
  }
  hash_u64(hash, static_cast<std::uint64_t>(out.incidences.size()));
  for (const auto &incidence : out.incidences) hash_incidence(hash, incidence);
  out.normalizedDigest = hash;
  return out;
}

std::uint64_t independent_semantic_digest(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineValidationCandidate &candidate) {
  const auto &certificate = candidate.certificate;
  std::uint64_t hash = kFnvOffset;
  hash_string(hash, "GlobalConformityBaselinePlan-v1");
  hash_u64(hash, topology.source_digest());
  hash_u64(hash, topology.network_digest());
  hash_u64(hash, topology.cut_graph_digest());
  hash_u64(hash, topology.semantic_digest());
  hash_u64(hash, certificate.targetMetricDigest);
  hash_u64(hash, certificate.normalizedProblemDigest);
  hash_u64(hash, static_cast<std::uint64_t>(candidate.schedule.size()));
  for (const auto &entry : candidate.schedule) {
    hash_id(hash, entry.span.network_arc());
    hash_eint(hash, entry.preferredCount);
    hash_eint(hash, entry.count);
    hash_u64(hash, static_cast<std::uint64_t>(entry.supportPieces.size()));
    for (const auto &piece : entry.supportPieces) {
      hash_support(hash, piece.carrier);
      hash_point(hash, piece.first);
      hash_point(hash, piece.second);
    }
  }
  hash_u64(hash, static_cast<std::uint64_t>(candidate.incidences.size()));
  for (const auto &incidence : candidate.incidences) hash_incidence(hash, incidence);
  hash_eint(hash, certificate.minimumFlipCount);
  hash_u64(hash, static_cast<std::uint64_t>(certificate.spanParity.size()));
  for (const auto &receipt : certificate.spanParity) {
    hash_id(hash, receipt.span.network_arc());
    hash_u64(hash, receipt.preferredOdd);
    hash_u64(hash, receipt.selectedFlip);
  }
  hash_u64(hash, static_cast<std::uint64_t>(certificate.regions.size()));
  for (const auto &receipt : certificate.regions) {
    hash_id(hash, receipt.region);
    hash_u64(hash, receipt.preferredResidualOdd);
    hash_eint(hash, receipt.finalBoundaryCount);
    hash_u64(hash, receipt.finalParityEven);
  }
  hash_u64(hash, static_cast<std::uint64_t>(certificate.components.size()));
  for (const auto &component : certificate.components) {
    hash_u64(hash, component.componentOrdinal);
    hash_u64(hash, static_cast<std::uint64_t>(component.regions.size()));
    for (const auto region : component.regions) hash_id(hash, region);
    hash_u64(hash, static_cast<std::uint64_t>(component.terminalSpans.size()));
    for (const auto span : component.terminalSpans) hash_id(hash, span.network_arc());
    hash_u64(hash, component.hasExterior);
    hash_u64(hash, component.exteriorDemandOdd);
  }
  hash_u64(hash, static_cast<std::uint64_t>(certificate.demandedVertices.size()));
  for (const auto &demand : certificate.demandedVertices) {
    hash_u64(hash, demand.region.has_value());
    if (demand.region) hash_id(hash, *demand.region);
    hash_u64(hash, demand.exteriorComponentOrdinal.has_value());
    if (demand.exteriorComponentOrdinal) {
      hash_u64(hash, *demand.exteriorComponentOrdinal);
    }
  }
  hash_u64(hash, static_cast<std::uint64_t>(certificate.selectedFlips.size()));
  for (const auto span : certificate.selectedFlips) hash_id(hash, span.network_arc());
  hash_u64(hash, static_cast<std::uint64_t>(certificate.lexReceipts.size()));
  for (const auto &receipt : certificate.lexReceipts) {
    hash_id(hash, receipt.span.network_arc());
    hash_u64(hash, receipt.smallerCountRequiresFlip);
    hash_u64(hash, receipt.trialFeasible);
    hash_u64(hash, receipt.trialMinimumFlipCount.has_value());
    if (receipt.trialMinimumFlipCount) hash_eint(hash, *receipt.trialMinimumFlipCount);
    hash_u64(hash, receipt.selectedFlip);
    hash_eint(hash, receipt.selectedMinimumFlipCount);
  }
  hash_eint(hash, certificate.objective.primaryDeviation);
  hash_u64(hash, static_cast<std::uint64_t>(
                     certificate.objective.canonicalCounts.size()));
  for (const auto &count : certificate.objective.canonicalCounts) hash_eint(hash, count);
  return hash;
}

} // namespace

std::optional<GlobalConformityPlanError>
validate_global_conformity_baseline_candidate(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineInput &input,
    const GlobalConformityBaselineValidationCandidate &candidate) {
  const auto problem = rebuild_problem(topology, input);
  if (!problem) return validation_error("baseline input reconstruction failed");
  const auto &certificate = candidate.certificate;

  if (certificate.sourceDigest != topology.source_digest() ||
      certificate.networkDigest != topology.network_digest() ||
      certificate.cutGraphDigest != topology.cut_graph_digest() ||
      certificate.topologyPlanDigest != topology.semantic_digest() ||
      certificate.targetMetricDigest != problem->metricDigest ||
      certificate.normalizedProblemDigest != problem->normalizedDigest) {
    return validation_error("baseline binding/metric/problem digest mismatch");
  }
  if (candidate.incidences != problem->incidences) {
    return validation_error("baseline incidence sequence is not exact A2b authority");
  }
  if (candidate.schedule.size() != problem->spans.size()) {
    return validation_error("baseline schedule cardinality mismatch");
  }

  std::map<ConformitySpanId, std::size_t> spanIndex;
  for (std::size_t span = 0U; span < problem->spans.size(); ++span) {
    spanIndex.emplace(problem->spans[span].id, span);
    const auto &entry = candidate.schedule[span];
    if (entry.span != problem->spans[span].id ||
        entry.preferredCount != problem->preferred[span] ||
        entry.supportPieces != problem->spans[span].supportPieces ||
        entry.count < EInt(1)) {
      return validation_error("baseline schedule span/support/preference mismatch");
    }
  }

  if (certificate.components != problem->components) {
    return validation_error("baseline component-local exterior certificate mismatch");
  }
  std::vector<BaselineConformityDemandVertex> demandedVertices;
  for (std::size_t region = 0U; region < problem->regions.size(); ++region) {
    if (problem->graph.demand[region]) {
      demandedVertices.push_back({problem->regions[region], std::nullopt});
    }
  }
  std::size_t exteriorVertex = problem->regions.size();
  for (const auto &component : problem->components) {
    if (!component.hasExterior) continue;
    if (problem->graph.demand[exteriorVertex]) {
      demandedVertices.push_back({std::nullopt, component.componentOrdinal});
    }
    ++exteriorVertex;
  }
  if (certificate.demandedVertices != demandedVertices) {
    return validation_error("baseline exact demanded-vertex set T mismatch");
  }
  if (certificate.spanParity.size() != problem->spans.size() ||
      certificate.lexReceipts.size() != problem->spans.size()) {
    return validation_error("baseline span/lex certificate cardinality mismatch");
  }

  ParityFixedChoices fixed(problem->spans.size(), -1);
  const auto minimum =
      global_conformity_baseline_detail::minimum_t_join_cardinality(
          problem->graph, fixed);
  if (!minimum || certificate.minimumFlipCount != *minimum) {
    return validation_error("baseline minimum T-join cardinality mismatch");
  }

  std::vector<bool> selected(problem->spans.size(), false);
  std::vector<ConformitySpanId> selectedFlips;
  for (std::size_t span = 0U; span < problem->spans.size(); ++span) {
    const bool preferredOdd = problem->preferred[span] % EInt(2) != EInt(0);
    const auto &parity = certificate.spanParity[span];
    if (parity.span != problem->spans[span].id ||
        parity.preferredOdd != preferredOdd) {
      return validation_error("baseline preferred parity receipt mismatch");
    }

    const bool desiredFlip = problem->preferred[span] > EInt(1);
    fixed[span] = desiredFlip ? 1 : 0;
    const auto trial =
        global_conformity_baseline_detail::minimum_t_join_cardinality(
            problem->graph, fixed);
    const bool keepTrial = trial && *trial == *minimum;
    if (!keepTrial) fixed[span] = desiredFlip ? 0 : 1;
    const auto selectedMinimum =
        global_conformity_baseline_detail::minimum_t_join_cardinality(
            problem->graph, fixed);
    if (!selectedMinimum || *selectedMinimum != *minimum) {
      return validation_error("baseline lex-prefix replay lost primary optimum");
    }
    selected[span] = fixed[span] == 1;

    const auto &receipt = certificate.lexReceipts[span];
    if (receipt.span != problem->spans[span].id ||
        receipt.smallerCountRequiresFlip != desiredFlip ||
        receipt.trialFeasible != trial.has_value() ||
        receipt.trialMinimumFlipCount != trial ||
        receipt.selectedFlip != selected[span] ||
        receipt.selectedMinimumFlipCount != *selectedMinimum ||
        parity.selectedFlip != selected[span]) {
      return validation_error("baseline canonical lex-prefix receipt mismatch");
    }
    if (selected[span]) selectedFlips.push_back(problem->spans[span].id);

    const EInt expected = !selected[span]
                              ? problem->preferred[span]
                              : (problem->preferred[span] > EInt(1)
                                     ? problem->preferred[span] - EInt(1)
                                     : EInt(2));
    if (candidate.schedule[span].count != expected) {
      return validation_error("baseline parity-to-positive-count mapping mismatch");
    }
  }
  if (certificate.selectedFlips != selectedFlips) {
    return validation_error("baseline selected flip set mismatch");
  }

  BaselineConformityObjectiveValue objective;
  std::vector<BaselineConformityRegionReceipt> regionReceipts;
  for (std::size_t span = 0U; span < problem->spans.size(); ++span) {
    const auto &count = candidate.schedule[span].count;
    objective.primaryDeviation += (count - problem->preferred[span]).abs();
    objective.canonicalCounts.push_back(count);
  }
  if (objective.primaryDeviation != *minimum ||
      objective != certificate.objective) {
    return validation_error("baseline exact L1/lex objective mismatch");
  }

  for (std::size_t region = 0U; region < problem->regions.size(); ++region) {
    EInt boundary(0);
    for (const auto &incidence : problem->incidences) {
      if (incidence.id.region != problem->regions[region]) continue;
      boundary += candidate.schedule[spanIndex.at(incidence.span)].count;
    }
    regionReceipts.push_back({problem->regions[region], problem->residual[region],
                              boundary, boundary % EInt(2) == EInt(0)});
    if (boundary % EInt(2) != EInt(0)) {
      return validation_error("baseline region boundary parity is odd");
    }
  }
  if (certificate.regions != regionReceipts) {
    return validation_error("baseline independent region parity receipt mismatch");
  }

  if (candidate.semanticDigest != independent_semantic_digest(topology, candidate)) {
    return validation_error("baseline semantic digest mismatch");
  }
  return std::nullopt;
}

GlobalConformityBaselineBuildResult validate_global_conformity_baseline(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineInput &input,
    const GlobalConformityBaselinePlan &plan) {
  if (const auto error = validate_global_conformity_baseline_candidate(
          topology, input, plan.validation_candidate())) {
    return GlobalConformityBaselineBuildResult(*error);
  }

  for (const auto &entry : plan.schedule()) {
    const auto first = plan.breakpoint_location(entry.span, EInt(0));
    const auto last = plan.breakpoint_location(entry.span, entry.count);
    if (!first || !last || !first->firstEndpoint || first->lastEndpoint ||
        first->localNumerator != EInt(0) || first->localDenominator != EInt(1) ||
        !last->lastEndpoint || last->firstEndpoint ||
        last->supportPieceIndex + 1U != entry.supportPieces.size() ||
        last->localNumerator != EInt(1) || last->localDenominator != EInt(1)) {
      return GlobalConformityBaselineBuildResult(
          validation_error("baseline compact breakpoint endpoint mismatch"));
    }
    if (entry.count > EInt(1)) {
      const EInt one(1);
      const auto forward = plan.breakpoint_location(entry.span, one);
      const auto reverse = plan.breakpoint_location(entry.span, entry.count - one);
      if (!forward || !reverse || forward->localDenominator != entry.count ||
          reverse->localDenominator != entry.count) {
        return GlobalConformityBaselineBuildResult(
            validation_error("baseline compact exact-ordinal breakpoint mismatch"));
      }
    }
  }
  return GlobalConformityBaselineBuildResult(plan);
}

} // namespace directional::geometry
