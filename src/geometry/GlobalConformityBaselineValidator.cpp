#include <directional/geometry/GlobalConformityBaseline.h>

#include "GlobalConformityBaselineSupport.h"
#include "GlobalConformityParityGraph.h"

#include <algorithm>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace directional::geometry {
namespace {

using global_conformity_baseline_detail::MinimumTJoinWorkEvidence;
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

void observe_bits(std::size_t &maximum, const EInt &value) {
  maximum = std::max(maximum, value.magnitude_bits());
}

void finalize_exact_widths(BaselineConformityExactWidthReceipt &widths) {
  widths.overallMaximumBits = std::max(
      {widths.preferredCountBits, widths.scheduledCountBits,
       widths.minimumFlipCountBits, widths.lexMinimumCountBits,
       widths.regionBoundaryCountBits, widths.matchingDistanceBits,
       widths.breakpointOrdinalBits, widths.breakpointNumeratorBits,
       widths.breakpointDenominatorBits});
}

void independently_observe_compact_breakpoint_widths(
    BaselineConformityExactWidthReceipt &widths,
    const std::vector<ConformityScheduleEntry> &schedule) {
  const EInt zero(0);
  const EInt one(1);
  for (const auto &entry : schedule) {
    observe_bits(widths.breakpointOrdinalBits, zero);
    observe_bits(widths.breakpointOrdinalBits, entry.count);
    observe_bits(widths.breakpointNumeratorBits, zero);
    observe_bits(widths.breakpointNumeratorBits, one);
    observe_bits(widths.breakpointDenominatorBits, one);
    if (entry.count <= one || entry.supportPieces.empty()) continue;

    const EInt pieceCount =
        global_conformity_baseline_detail::exact_from_size(
            entry.supportPieces.size());
    for (const EInt ordinal : {one, entry.count - one}) {
      const EInt scaled = pieceCount * ordinal;
      const EInt quotient = scaled / entry.count;
      const EInt numerator = scaled - quotient * entry.count;
      observe_bits(widths.breakpointOrdinalBits, ordinal);
      observe_bits(widths.breakpointNumeratorBits, numerator);
      observe_bits(widths.breakpointDenominatorBits, entry.count);
    }
  }
}

std::optional<MinimumTJoinWorkEvidence> independently_derive_t_join_work(
    const ParityGraphProblem &problem, const ParityFixedChoices &fixed) {
  if (problem.vertexCount == 0U || problem.demand.size() != problem.vertexCount) {
    return std::nullopt;
  }
  std::size_t spanCount = 0U;
  for (const auto &edge : problem.edges) {
    if (edge.firstVertex >= problem.vertexCount ||
        edge.secondVertex >= problem.vertexCount) {
      return std::nullopt;
    }
    spanCount = std::max(spanCount, edge.spanIndex + 1U);
  }
  if (fixed.size() != spanCount) return std::nullopt;

  std::vector<bool> remainingDemand = problem.demand;
  std::vector<std::vector<std::size_t>> adjacency(problem.vertexCount);
  for (const auto &edge : problem.edges) {
    const auto choice = fixed[edge.spanIndex];
    if (choice < -1 || choice > 1) return std::nullopt;
    if (choice == 1) {
      if (edge.firstVertex != edge.secondVertex) {
        remainingDemand[edge.firstVertex] = !remainingDemand[edge.firstVertex];
        remainingDemand[edge.secondVertex] = !remainingDemand[edge.secondVertex];
      }
      continue;
    }
    if (choice == 0 || edge.firstVertex == edge.secondVertex) continue;
    adjacency[edge.firstVertex].push_back(edge.secondVertex);
    adjacency[edge.secondVertex].push_back(edge.firstVertex);
  }

  std::vector<std::size_t> terminals;
  for (std::size_t vertex = 0U; vertex < problem.vertexCount; ++vertex) {
    if (remainingDemand[vertex]) terminals.push_back(vertex);
  }
  if ((terminals.size() & 1U) != 0U) return std::nullopt;

  MinimumTJoinWorkEvidence evidence;
  evidence.terminalCount = terminals.size();
  evidence.matchingNodeCount = terminals.size();
  evidence.matchingExecuted = !terminals.empty();
  if (terminals.empty()) return evidence;

  constexpr std::size_t kUnreached = std::numeric_limits<std::size_t>::max();
  for (std::size_t sourceOrdinal = 0U; sourceOrdinal < terminals.size();
       ++sourceOrdinal) {
    std::vector<std::size_t> distance(problem.vertexCount, kUnreached);
    std::queue<std::size_t> queue;
    distance[terminals[sourceOrdinal]] = 0U;
    queue.push(terminals[sourceOrdinal]);
    while (!queue.empty()) {
      const auto current = queue.front();
      queue.pop();
      for (const auto next : adjacency[current]) {
        if (distance[next] != kUnreached) continue;
        distance[next] = distance[current] + 1U;
        queue.push(next);
      }
    }
    for (std::size_t targetOrdinal = sourceOrdinal + 1U;
         targetOrdinal < terminals.size(); ++targetOrdinal) {
      const auto d = distance[terminals[targetOrdinal]];
      if (d == kUnreached) continue;
      if (d >= problem.vertexCount) return std::nullopt;
      ++evidence.matchingEdgeCount;
      const EInt exactDistance =
          global_conformity_baseline_detail::exact_from_size(d);
      evidence.maximumMatchingDistanceBitWidth =
          std::max(evidence.maximumMatchingDistanceBitWidth,
                   exactDistance.magnitude_bits());
    }
  }
  return evidence;
}

bool same_work_evidence(const MinimumTJoinWorkEvidence &first,
                        const MinimumTJoinWorkEvidence &second) {
  return first.terminalCount == second.terminalCount &&
         first.matchingNodeCount == second.matchingNodeCount &&
         first.matchingEdgeCount == second.matchingEdgeCount &&
         first.matchingExecuted == second.matchingExecuted &&
         first.maximumMatchingDistanceBitWidth ==
             second.maximumMatchingDistanceBitWidth;
}

std::size_t maximum_matching_edge_count(std::size_t terminalCount) {
  if (terminalCount < 2U) return 0U;
  return terminalCount % 2U == 0U
             ? (terminalCount / 2U) * (terminalCount - 1U)
             : terminalCount * ((terminalCount - 1U) / 2U);
}

bool receipt_matches(
    const BaselineConformityTJoinWorkReceipt &receipt,
    BaselineConformityWorkPhase phase, BaselineConformityTJoinPurpose purpose,
    std::optional<ConformitySpanId> span, std::size_t fixedPrefixLength,
    const MinimumTJoinWorkEvidence &evidence) {
  return receipt.phase == phase && receipt.purpose == purpose &&
         receipt.span == span &&
         receipt.fixedPrefixLength == fixedPrefixLength &&
         receipt.terminalCount == evidence.terminalCount &&
         receipt.matchingNodeCount == evidence.matchingNodeCount &&
         receipt.matchingEdgeCount == evidence.matchingEdgeCount &&
         receipt.matchingExecuted == evidence.matchingExecuted &&
         receipt.maximumMatchingDistanceBitWidth ==
             evidence.maximumMatchingDistanceBitWidth &&
         receipt.matchingEdgeCount <=
             maximum_matching_edge_count(receipt.terminalCount);
}

void hash_work_receipt(std::uint64_t &hash,
                       const BaselineConformityWorkReceipt &work) {
  hash_u64(hash, work.spanCount);
  hash_u64(hash, work.parityVertexCount);
  hash_u64(hash, work.parityEdgeCount);
  hash_u64(hash, work.producerTJoinInvocationCount);
  hash_u64(hash, work.validatorTJoinInvocationCount);
  hash_u64(hash, work.aggregateTJoinInvocationCount);
  hash_u64(hash, static_cast<std::uint64_t>(work.tJoinInvocations.size()));
  for (const auto &receipt : work.tJoinInvocations) {
    hash_u64(hash, static_cast<std::uint64_t>(receipt.phase));
    hash_u64(hash, static_cast<std::uint64_t>(receipt.purpose));
    hash_u64(hash, receipt.span.has_value());
    if (receipt.span) hash_id(hash, receipt.span->network_arc());
    hash_u64(hash, receipt.fixedPrefixLength);
    hash_u64(hash, receipt.terminalCount);
    hash_u64(hash, receipt.matchingNodeCount);
    hash_u64(hash, receipt.matchingEdgeCount);
    hash_u64(hash, receipt.matchingExecuted);
    hash_u64(hash, receipt.maximumMatchingDistanceBitWidth);
  }
  hash_u64(hash, work.retryResetCount);
  hash_u64(hash, work.producerInitialOptimumPending);
  hash_u64(hash, work.producerRemainingCanonicalSpanDecisions);
  hash_u64(hash, work.validatorInitialOptimumPending);
  hash_u64(hash, work.validatorRemainingCanonicalSpanDecisions);
}

void hash_exact_widths(std::uint64_t &hash,
                       const BaselineConformityExactWidthReceipt &widths) {
  hash_u64(hash, widths.preferredCountBits);
  hash_u64(hash, widths.scheduledCountBits);
  hash_u64(hash, widths.minimumFlipCountBits);
  hash_u64(hash, widths.lexMinimumCountBits);
  hash_u64(hash, widths.regionBoundaryCountBits);
  hash_u64(hash, widths.matchingDistanceBits);
  hash_u64(hash, widths.breakpointOrdinalBits);
  hash_u64(hash, widths.breakpointNumeratorBits);
  hash_u64(hash, widths.breakpointDenominatorBits);
  hash_u64(hash, widths.overallMaximumBits);
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
  hash_work_receipt(hash, certificate.work);
  hash_exact_widths(hash, certificate.exactWidths);
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

  const std::size_t spanCount = problem->spans.size();
  if (spanCount > (std::numeric_limits<std::size_t>::max() - 1U) / 2U) {
    return validation_error("baseline work invocation count overflow");
  }
  const std::size_t invocationsPerPhase = 1U + 2U * spanCount;
  if (invocationsPerPhase >
      std::numeric_limits<std::size_t>::max() / 2U) {
    return validation_error("baseline aggregate work invocation count overflow");
  }
  const std::size_t aggregateInvocations = 2U * invocationsPerPhase;
  const auto &work = certificate.work;
  if (work.spanCount != spanCount ||
      work.parityVertexCount != problem->graph.vertexCount ||
      work.parityEdgeCount != problem->graph.edges.size() ||
      work.producerTJoinInvocationCount != invocationsPerPhase ||
      work.validatorTJoinInvocationCount != invocationsPerPhase ||
      work.aggregateTJoinInvocationCount != aggregateInvocations ||
      work.tJoinInvocations.size() != aggregateInvocations ||
      work.retryResetCount != 0U || work.producerInitialOptimumPending ||
      work.producerRemainingCanonicalSpanDecisions != 0U ||
      work.validatorInitialOptimumPending ||
      work.validatorRemainingCanonicalSpanDecisions != 0U) {
    return validation_error("baseline production work receipt cardinality/progress mismatch");
  }

  BaselineConformityExactWidthReceipt independentWidths;
  for (const auto &preferred : problem->preferred) {
    observe_bits(independentWidths.preferredCountBits, preferred);
  }
  for (const auto &entry : candidate.schedule) {
    observe_bits(independentWidths.scheduledCountBits, entry.count);
  }
  independently_observe_compact_breakpoint_widths(independentWidths,
                                                   candidate.schedule);

  ParityFixedChoices fixed(problem->spans.size(), -1);
  const auto independentInitial =
      independently_derive_t_join_work(problem->graph, fixed);
  if (!independentInitial ||
      !receipt_matches(work.tJoinInvocations[0U],
                       BaselineConformityWorkPhase::Producer,
                       BaselineConformityTJoinPurpose::InitialOptimum,
                       std::nullopt, 0U, *independentInitial) ||
      !receipt_matches(work.tJoinInvocations[invocationsPerPhase],
                       BaselineConformityWorkPhase::Validator,
                       BaselineConformityTJoinPurpose::InitialOptimum,
                       std::nullopt, 0U, *independentInitial)) {
    return validation_error("baseline initial T-join work receipt mismatch");
  }
  MinimumTJoinWorkEvidence actualInitial;
  const auto minimum =
      global_conformity_baseline_detail::minimum_t_join_cardinality(
          problem->graph, fixed, &actualInitial);
  if (!same_work_evidence(actualInitial, *independentInitial)) {
    return validation_error("baseline validator initial T-join dimensions disagree with independent reconstruction");
  }
  independentWidths.matchingDistanceBits =
      std::max(independentWidths.matchingDistanceBits,
               independentInitial->maximumMatchingDistanceBitWidth);
  if (!minimum || certificate.minimumFlipCount != *minimum) {
    return validation_error("baseline minimum T-join cardinality mismatch");
  }
  observe_bits(independentWidths.minimumFlipCountBits, *minimum);

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
    const auto independentTrial =
        independently_derive_t_join_work(problem->graph, fixed);
    const std::size_t trialIndex = 1U + 2U * span;
    if (!independentTrial ||
        !receipt_matches(work.tJoinInvocations[trialIndex],
                         BaselineConformityWorkPhase::Producer,
                         BaselineConformityTJoinPurpose::TrialPrefix,
                         problem->spans[span].id, span + 1U,
                         *independentTrial) ||
        !receipt_matches(work.tJoinInvocations[invocationsPerPhase + trialIndex],
                         BaselineConformityWorkPhase::Validator,
                         BaselineConformityTJoinPurpose::TrialPrefix,
                         problem->spans[span].id, span + 1U,
                         *independentTrial)) {
      return validation_error("baseline trial T-join work receipt mismatch");
    }
    MinimumTJoinWorkEvidence actualTrial;
    const auto trial =
        global_conformity_baseline_detail::minimum_t_join_cardinality(
            problem->graph, fixed, &actualTrial);
    if (!same_work_evidence(actualTrial, *independentTrial)) {
      return validation_error("baseline validator trial T-join dimensions disagree with independent reconstruction");
    }
    independentWidths.matchingDistanceBits =
        std::max(independentWidths.matchingDistanceBits,
                 independentTrial->maximumMatchingDistanceBitWidth);
    if (trial) observe_bits(independentWidths.lexMinimumCountBits, *trial);

    const bool keepTrial = trial && *trial == *minimum;
    if (!keepTrial) fixed[span] = desiredFlip ? 0 : 1;
    const auto independentSelected =
        independently_derive_t_join_work(problem->graph, fixed);
    const std::size_t selectedIndex = trialIndex + 1U;
    if (!independentSelected ||
        !receipt_matches(work.tJoinInvocations[selectedIndex],
                         BaselineConformityWorkPhase::Producer,
                         BaselineConformityTJoinPurpose::SelectedPrefix,
                         problem->spans[span].id, span + 1U,
                         *independentSelected) ||
        !receipt_matches(work.tJoinInvocations[invocationsPerPhase + selectedIndex],
                         BaselineConformityWorkPhase::Validator,
                         BaselineConformityTJoinPurpose::SelectedPrefix,
                         problem->spans[span].id, span + 1U,
                         *independentSelected)) {
      return validation_error("baseline selected T-join work receipt mismatch");
    }
    MinimumTJoinWorkEvidence actualSelected;
    const auto selectedMinimum =
        global_conformity_baseline_detail::minimum_t_join_cardinality(
            problem->graph, fixed, &actualSelected);
    if (!same_work_evidence(actualSelected, *independentSelected)) {
      return validation_error("baseline validator selected T-join dimensions disagree with independent reconstruction");
    }
    independentWidths.matchingDistanceBits =
        std::max(independentWidths.matchingDistanceBits,
                 independentSelected->maximumMatchingDistanceBitWidth);
    if (!selectedMinimum || *selectedMinimum != *minimum) {
      return validation_error("baseline lex-prefix replay lost primary optimum");
    }
    observe_bits(independentWidths.lexMinimumCountBits, *selectedMinimum);
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
    observe_bits(independentWidths.regionBoundaryCountBits, boundary);
    if (boundary % EInt(2) != EInt(0)) {
      return validation_error("baseline region boundary parity is odd");
    }
  }
  if (certificate.regions != regionReceipts) {
    return validation_error("baseline independent region parity receipt mismatch");
  }

  finalize_exact_widths(independentWidths);
  if (certificate.exactWidths != independentWidths) {
    return validation_error("baseline exact magnitude-width receipt mismatch");
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
