#include <directional/geometry/GlobalConformityBaseline.h>

#include "GlobalConformityBaselineSupport.h"
#include "GlobalConformityParityGraph.h"

#include <algorithm>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace directional::geometry {
namespace {

using global_conformity_baseline_detail::ParityFixedChoices;
using global_conformity_baseline_detail::ParityGraphEdge;
using global_conformity_baseline_detail::ParityGraphProblem;

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

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

GlobalConformityPlanError make_error(GlobalConformityPlanErrorCode code,
                                     std::string detail = {}) {
  GlobalConformityPlanError error;
  error.code = code;
  error.detail = std::move(detail);
  return error;
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

struct NormalizedBaselineProblem {
  std::vector<ConformitySpanInput> spans;
  std::vector<EInt> preferred;
  std::vector<BaselineConformityIncidence> incidences;
  std::vector<authority::NetworkRegionId> regions;
  std::vector<std::vector<std::size_t>> spanRegionEnds;
  std::vector<bool> preferredResidual;
  std::vector<BaselineConformityComponentReceipt> componentReceipts;
  ParityGraphProblem graph;
  std::uint64_t targetMetricDigest = 0U;
  std::uint64_t normalizedProblemDigest = 0U;
};
using NormalizeResult =
    std::variant<NormalizedBaselineProblem, GlobalConformityPlanError>;

std::uint64_t normalized_digest(const GlobalTopologyPlan &topology,
                                const NormalizedBaselineProblem &problem) {
  std::uint64_t hash = kFnvOffset;
  hash_string(hash, "GlobalConformityBaselineProblem-v1");
  hash_u64(hash, topology.source_digest());
  hash_u64(hash, topology.network_digest());
  hash_u64(hash, topology.cut_graph_digest());
  hash_u64(hash, topology.semantic_digest());
  hash_u64(hash, problem.targetMetricDigest);
  hash_u64(hash, static_cast<std::uint64_t>(problem.spans.size()));
  for (std::size_t index = 0U; index < problem.spans.size(); ++index) {
    hash_span(hash, problem.spans[index], problem.preferred[index]);
  }
  hash_u64(hash, static_cast<std::uint64_t>(problem.incidences.size()));
  for (const auto &incidence : problem.incidences) hash_incidence(hash, incidence);
  return hash;
}

NormalizeResult normalize_baseline(const GlobalTopologyPlan &topology,
                                   const GlobalConformityBaselineInput &input) {
  if (input.sourceVertices.cols() != 3 || input.sourceVertices.rows() <= 0 ||
      input.targetSize.size() != input.sourceVertices.rows()) {
    return make_error(GlobalConformityPlanErrorCode::InvalidSourceBinding,
                      "baseline source/target dimensions are invalid");
  }

  NormalizedBaselineProblem out;
  out.targetMetricDigest =
      global_conformity_baseline_detail::exact_target_metric_digest(
          input.targetSize);
  if (out.targetMetricDigest == 0U) {
    return make_error(GlobalConformityPlanErrorCode::InvalidTargetMetric,
                      "baseline target metric must be finite and positive");
  }

  out.spans = input.spans;
  std::sort(out.spans.begin(), out.spans.end(),
            [](const auto &first, const auto &second) {
              return first.id < second.id;
            });
  if (out.spans.size() != topology.arcs().size()) {
    return make_error(GlobalConformityPlanErrorCode::InvalidTopologyBinding,
                      "baseline schedules every full A2b arc exactly once");
  }

  std::map<ConformitySpanId, std::size_t> spanIndex;
  for (std::size_t index = 0U; index < out.spans.size(); ++index) {
    if (index != 0U && out.spans[index - 1U].id == out.spans[index].id) {
      auto error = make_error(GlobalConformityPlanErrorCode::DuplicateConformitySpan);
      error.span = out.spans[index].id;
      return error;
    }
    if (topology.find_arc(out.spans[index].id.network_arc()) == nullptr) {
      auto error = make_error(GlobalConformityPlanErrorCode::InvalidTopologyBinding,
                              "baseline span does not bind an A2b arc");
      error.span = out.spans[index].id;
      return error;
    }
    const auto preferred =
        global_conformity_baseline_detail::derive_preferred_count_exact(
            out.spans[index], input.sourceVertices, input.targetSize);
    if (!preferred) {
      auto error = make_error(GlobalConformityPlanErrorCode::DegenerateConformityPath,
                              "baseline exact preferred-count derivation failed");
      error.span = out.spans[index].id;
      return error;
    }
    out.preferred.push_back(*preferred);
    spanIndex.emplace(out.spans[index].id, index);
  }

  std::vector<const GlobalTopologyRegion *> orderedRegions;
  orderedRegions.reserve(topology.regions().size());
  for (const auto &region : topology.regions()) orderedRegions.push_back(&region);
  std::sort(orderedRegions.begin(), orderedRegions.end(),
            [](const auto *first, const auto *second) {
              return first->id < second->id;
            });
  if (orderedRegions.empty()) {
    return make_error(GlobalConformityPlanErrorCode::InvalidTopologyBinding,
                      "baseline requires at least one A2b region");
  }

  std::map<authority::NetworkRegionId, std::size_t> regionIndex;
  for (std::size_t index = 0U; index < orderedRegions.size(); ++index) {
    out.regions.push_back(orderedRegions[index]->id);
    regionIndex.emplace(orderedRegions[index]->id, index);
  }

  out.spanRegionEnds.resize(out.spans.size());
  for (const auto *region : orderedRegions) {
    const auto regionIt = regionIndex.find(region->id);
    for (std::size_t ordinal = 0U; ordinal < region->boundary.size(); ++ordinal) {
      const auto &boundary = region->boundary[ordinal];
      const auto span = ConformitySpanId::from_network_arc(boundary.arc);
      const auto spanIt = spanIndex.find(span);
      if (spanIt == spanIndex.end()) {
        auto error = make_error(GlobalConformityPlanErrorCode::InvalidBoundaryIncidence,
                                "A2b boundary names an unscheduled span");
        error.incidence = ConformityBoundaryIncidenceId{region->id, ordinal};
        return error;
      }
      out.incidences.push_back({{region->id, ordinal}, span,
                                boundary.orientation});
      out.spanRegionEnds[spanIt->second].push_back(regionIt->second);
    }
  }

  for (std::size_t span = 0U; span < out.spans.size(); ++span) {
    const auto degree = out.spanRegionEnds[span].size();
    if (degree == 0U || degree > 2U) {
      auto error = make_error(GlobalConformityPlanErrorCode::UnsupportedIncidenceDegree,
                              "baseline span must have one or two boundary occurrences");
      error.span = out.spans[span].id;
      return error;
    }
  }

  out.preferredResidual.assign(out.regions.size(), false);
  for (const auto &incidence : out.incidences) {
    const auto span = spanIndex.at(incidence.span);
    if (out.preferred[span] % EInt(2) == EInt(0)) continue;
    out.preferredResidual[regionIndex.at(incidence.id.region)] =
        !out.preferredResidual[regionIndex.at(incidence.id.region)];
  }

  DisjointSet components(out.regions.size());
  for (const auto &ends : out.spanRegionEnds) {
    if (ends.size() == 2U && ends[0] != ends[1]) {
      components.unite(ends[0], ends[1]);
    }
  }
  std::map<std::size_t, std::vector<std::size_t>> grouped;
  for (std::size_t region = 0U; region < out.regions.size(); ++region) {
    grouped[components.find(region)].push_back(region);
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

  std::vector<std::size_t> componentOfRegion(out.regions.size(), 0U);
  for (std::size_t component = 0U; component < groups.size(); ++component) {
    BaselineConformityComponentReceipt receipt;
    receipt.componentOrdinal = component;
    for (const auto region : groups[component]) {
      componentOfRegion[region] = component;
      receipt.regions.push_back(out.regions[region]);
    }
    out.componentReceipts.push_back(std::move(receipt));
  }

  for (std::size_t span = 0U; span < out.spans.size(); ++span) {
    if (out.spanRegionEnds[span].size() != 1U) continue;
    auto &receipt = out.componentReceipts[
        componentOfRegion[out.spanRegionEnds[span].front()]];
    receipt.hasExterior = true;
    receipt.terminalSpans.push_back(out.spans[span].id);
  }

  std::vector<std::optional<std::size_t>> exterior(groups.size());
  std::size_t vertexCount = out.regions.size();
  for (std::size_t component = 0U; component < groups.size(); ++component) {
    auto &receipt = out.componentReceipts[component];
    if (!receipt.hasExterior) continue;
    exterior[component] = vertexCount++;
    bool demand = false;
    for (const auto region : groups[component]) {
      demand = demand != out.preferredResidual[region];
    }
    receipt.exteriorDemandOdd = demand;
  }

  out.graph.vertexCount = vertexCount;
  out.graph.demand.assign(vertexCount, false);
  for (std::size_t region = 0U; region < out.regions.size(); ++region) {
    out.graph.demand[region] = out.preferredResidual[region];
  }
  for (std::size_t component = 0U; component < groups.size(); ++component) {
    if (exterior[component]) {
      out.graph.demand[*exterior[component]] =
          out.componentReceipts[component].exteriorDemandOdd;
    }
  }

  out.graph.edges.reserve(out.spans.size());
  for (std::size_t span = 0U; span < out.spans.size(); ++span) {
    const auto &ends = out.spanRegionEnds[span];
    if (ends.size() == 2U) {
      out.graph.edges.push_back({span, ends[0], ends[1]});
    } else {
      const auto component = componentOfRegion[ends.front()];
      if (!exterior[component]) {
        return make_error(GlobalConformityPlanErrorCode::ExactValidationFailed,
                          "terminal span lacks component-local exterior");
      }
      out.graph.edges.push_back({span, ends.front(), *exterior[component]});
    }
  }

  out.normalizedProblemDigest = normalized_digest(topology, out);
  return out;
}

std::uint64_t semantic_digest(
    const GlobalTopologyPlan &topology,
    const std::vector<ConformityScheduleEntry> &schedule,
    const std::vector<BaselineConformityIncidence> &incidences,
    const GlobalConformityBaselineCertificate &certificate) {
  std::uint64_t hash = kFnvOffset;
  hash_string(hash, "GlobalConformityBaselinePlan-v1");
  hash_u64(hash, topology.source_digest());
  hash_u64(hash, topology.network_digest());
  hash_u64(hash, topology.cut_graph_digest());
  hash_u64(hash, topology.semantic_digest());
  hash_u64(hash, certificate.targetMetricDigest);
  hash_u64(hash, certificate.normalizedProblemDigest);
  hash_u64(hash, static_cast<std::uint64_t>(schedule.size()));
  for (const auto &entry : schedule) {
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
  hash_u64(hash, static_cast<std::uint64_t>(incidences.size()));
  for (const auto &incidence : incidences) hash_incidence(hash, incidence);
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

GlobalConformityBaselineBuildResult build_global_conformity_baseline(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineInput &input) {
  try {
    auto normalizedResult = normalize_baseline(topology, input);
    if (const auto *error =
            std::get_if<GlobalConformityPlanError>(&normalizedResult)) {
      return GlobalConformityBaselineBuildResult(*error);
    }
    auto problem =
        std::get<NormalizedBaselineProblem>(std::move(normalizedResult));

    ParityFixedChoices fixed(problem.spans.size(), -1);
    const auto minimum =
        global_conformity_baseline_detail::minimum_t_join_cardinality(
            problem.graph, fixed);
    if (!minimum) {
      return GlobalConformityBaselineBuildResult(make_error(
          GlobalConformityPlanErrorCode::ExactMatchingFailed,
          "well-formed baseline parity graph lacked its constructive T-join"));
    }

    GlobalConformityBaselineCertificate certificate;
    certificate.sourceDigest = topology.source_digest();
    certificate.networkDigest = topology.network_digest();
    certificate.cutGraphDigest = topology.cut_graph_digest();
    certificate.topologyPlanDigest = topology.semantic_digest();
    certificate.targetMetricDigest = problem.targetMetricDigest;
    certificate.normalizedProblemDigest = problem.normalizedProblemDigest;
    certificate.minimumFlipCount = *minimum;
    certificate.components = problem.componentReceipts;
    for (std::size_t region = 0U; region < problem.regions.size(); ++region) {
      if (problem.graph.demand[region]) {
        certificate.demandedVertices.push_back(
            {problem.regions[region], std::nullopt});
      }
    }
    std::size_t exteriorVertex = problem.regions.size();
    for (const auto &component : problem.componentReceipts) {
      if (!component.hasExterior) continue;
      if (problem.graph.demand[exteriorVertex]) {
        certificate.demandedVertices.push_back(
            {std::nullopt, component.componentOrdinal});
      }
      ++exteriorVertex;
    }

    std::vector<bool> selectedFlip(problem.spans.size(), false);
    for (std::size_t span = 0U; span < problem.spans.size(); ++span) {
      const bool smallerRequiresFlip = problem.preferred[span] > EInt(1);
      fixed[span] = smallerRequiresFlip ? 1 : 0;
      const auto trial =
          global_conformity_baseline_detail::minimum_t_join_cardinality(
              problem.graph, fixed);
      const bool keepTrial = trial && *trial == *minimum;
      if (!keepTrial) fixed[span] = smallerRequiresFlip ? 0 : 1;
      const auto selected =
          global_conformity_baseline_detail::minimum_t_join_cardinality(
              problem.graph, fixed);
      if (!selected || *selected != *minimum) {
        return GlobalConformityBaselineBuildResult(make_error(
            GlobalConformityPlanErrorCode::ExactMatchingFailed,
            "canonical baseline lex-prefix refinement lost the primary optimum"));
      }
      selectedFlip[span] = fixed[span] == 1;
      certificate.lexReceipts.push_back(
          {problem.spans[span].id, smallerRequiresFlip, trial.has_value(), trial,
           selectedFlip[span], *selected});
    }

    std::vector<ConformityScheduleEntry> schedule;
    schedule.reserve(problem.spans.size());
    certificate.spanParity.reserve(problem.spans.size());
    for (std::size_t span = 0U; span < problem.spans.size(); ++span) {
      const EInt count = !selectedFlip[span]
                             ? problem.preferred[span]
                             : (problem.preferred[span] > EInt(1)
                                    ? problem.preferred[span] - EInt(1)
                                    : EInt(2));
      schedule.push_back({problem.spans[span].id, problem.preferred[span], count,
                          problem.spans[span].supportPieces});
      certificate.spanParity.push_back(
          {problem.spans[span].id,
           problem.preferred[span] % EInt(2) != EInt(0),
           selectedFlip[span]});
      if (selectedFlip[span]) {
        certificate.selectedFlips.push_back(problem.spans[span].id);
      }
      certificate.objective.primaryDeviation +=
          (count - problem.preferred[span]).abs();
      certificate.objective.canonicalCounts.push_back(count);
    }

    std::map<ConformitySpanId, std::size_t> spanIndex;
    for (std::size_t span = 0U; span < problem.spans.size(); ++span) {
      spanIndex.emplace(problem.spans[span].id, span);
    }
    certificate.regions.reserve(problem.regions.size());
    for (std::size_t region = 0U; region < problem.regions.size(); ++region) {
      EInt boundaryCount(0);
      for (const auto &incidence : problem.incidences) {
        if (incidence.id.region != problem.regions[region]) continue;
        boundaryCount += schedule[spanIndex.at(incidence.span)].count;
      }
      certificate.regions.push_back(
          {problem.regions[region], problem.preferredResidual[region],
           boundaryCount, boundaryCount % EInt(2) == EInt(0)});
    }

    if (certificate.objective.primaryDeviation != certificate.minimumFlipCount ||
        std::any_of(certificate.regions.begin(), certificate.regions.end(),
                    [](const auto &region) { return !region.finalParityEven; })) {
      return GlobalConformityBaselineBuildResult(make_error(
          GlobalConformityPlanErrorCode::ExactValidationFailed,
          "baseline schedule violates exact parity/objective identity"));
    }

    const auto digest = semantic_digest(topology, schedule, problem.incidences,
                                        certificate);
    GlobalConformityBaselinePlan plan(std::move(schedule),
                                      std::move(problem.incidences),
                                      std::move(certificate), digest);
    const auto validated = validate_global_conformity_baseline(topology, input, plan);
    return validated ? GlobalConformityBaselineBuildResult(std::move(plan))
                     : validated;
  } catch (const std::exception &exception) {
    return GlobalConformityBaselineBuildResult(make_error(
        GlobalConformityPlanErrorCode::ExactValidationFailed, exception.what()));
  }
}

const ConformityScheduleEntry *GlobalConformityBaselinePlan::find_schedule(
    ConformitySpanId span) const noexcept {
  const auto found = std::lower_bound(
      schedule_.begin(), schedule_.end(), span,
      [](const auto &entry, const auto &value) { return entry.span < value; });
  return found != schedule_.end() && found->span == span ? &*found : nullptr;
}

std::optional<ConformityBreakpointLocation>
GlobalConformityBaselinePlan::breakpoint_location(
    ConformitySpanId span, const EInt &exactOrdinal) const {
  const auto *entry = find_schedule(span);
  if (entry == nullptr || exactOrdinal < EInt(0) || exactOrdinal > entry->count ||
      entry->supportPieces.empty()) {
    return std::nullopt;
  }
  if (exactOrdinal == EInt(0)) {
    return ConformityBreakpointLocation{{span, exactOrdinal}, 0U, EInt(0), EInt(1),
                                        true, false};
  }
  if (exactOrdinal == entry->count) {
    return ConformityBreakpointLocation{
        {span, exactOrdinal}, entry->supportPieces.size() - 1U, EInt(1), EInt(1),
        false, true};
  }
  const EInt pieceCount =
      global_conformity_baseline_detail::exact_from_size(entry->supportPieces.size());
  const EInt scaled = pieceCount * exactOrdinal;
  const EInt quotient = scaled / entry->count;
  const EInt numerator = scaled - quotient * entry->count;
  if (quotient < EInt(0) || quotient >= pieceCount) return std::nullopt;
  const auto piece =
      global_conformity_baseline_detail::exact_to_size_checked(quotient);
  if (!piece || *piece >= entry->supportPieces.size()) return std::nullopt;
  return ConformityBreakpointLocation{{span, exactOrdinal}, *piece, numerator,
                                      entry->count, false, false};
}

GlobalConformityBaselineValidationCandidate
GlobalConformityBaselinePlan::validation_candidate() const {
  return {schedule_, incidences_, certificate_, semanticDigest_};
}

} // namespace directional::geometry
