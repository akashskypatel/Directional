#include <directional/geometry/GlobalConformityPlan.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace directional::geometry {
namespace {
using authority::FieldExactRational;

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

GlobalConformityPlanError validation_error(std::string detail) {
  return {GlobalConformityPlanErrorCode::ExactValidationFailed,
          std::nullopt, std::nullopt, std::move(detail)};
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
  for (unsigned char byte : value) hash_byte(hash, byte);
}
void hash_eint(std::uint64_t &hash, const EInt &value) {
  hash_string(hash, value.to_string());
}
template <class Id>
void hash_id(std::uint64_t &hash, Id id) {
  hash_u64(hash, static_cast<std::uint64_t>(Id::domain()));
  hash_u64(hash, static_cast<std::uint64_t>(id.index()));
}
void hash_exact(std::uint64_t &hash, const FieldExactRational &value) {
  hash_eint(hash, value.exact_numerator());
  hash_eint(hash, value.exact_denominator());
}

EInt exact_from_size(std::size_t value) {
  EInt out(0);
  for (int bit = static_cast<int>(sizeof(std::size_t) * 8U) - 1;
       bit >= 0; --bit) {
    out *= EInt(2);
    if (((value >> static_cast<unsigned>(bit)) & std::size_t{1}) != 0U) {
      out += EInt(1);
    }
  }
  return out;
}

EInt exact_power(EInt base, std::size_t exponent) {
  EInt result(1);
  while (exponent != 0U) {
    if ((exponent & 1U) != 0U) result *= base;
    exponent >>= 1U;
    if (exponent != 0U) base *= base;
  }
  return result;
}

EInt integer_sqrt_floor(const EInt &value) {
  if (value <= EInt(0)) return EInt(0);
  EInt guess = exact_power(EInt(2), (value.magnitude_bits() + 1U) / 2U);
  while (true) {
    const EInt next = (guess + value / guess) / EInt(2);
    if (next >= guess) return guess;
    guess = next;
  }
}

FieldExactRational exact_integer(long long value) {
  return *FieldExactRational::from_exact_fraction(EInt(value), EInt(1));
}
FieldExactRational exact_ratio(const EInt &num, const EInt &den) {
  return *FieldExactRational::from_exact_fraction(num, den);
}

using VertexWeights = std::map<std::size_t, FieldExactRational>;

void add_weight(VertexWeights &weights, std::size_t vertex,
                const FieldExactRational &weight) {
  auto [it, inserted] = weights.emplace(vertex, weight);
  if (!inserted) it->second = it->second + weight;
}

std::optional<VertexWeights> independently_decode_point(
    const ConformitySourcePoint &point, std::size_t vertexCount) {
  const auto zero = exact_integer(0);
  const auto one = exact_integer(1);
  VertexWeights weights;

  if (const auto *vertex = std::get_if<authority::SourceVertexId>(&point)) {
    if (vertex->index() >= vertexCount) return std::nullopt;
    weights.emplace(vertex->index(), one);
    return weights;
  }
  if (const auto *edge = std::get_if<ConformityEdgePoint>(&point)) {
    if (edge->edge.first().index() >= vertexCount ||
        edge->edge.second().index() >= vertexCount ||
        edge->parameter < zero || edge->parameter > one) {
      return std::nullopt;
    }
    add_weight(weights, edge->edge.first().index(), one - edge->parameter);
    add_weight(weights, edge->edge.second().index(), edge->parameter);
    return weights;
  }

  const auto &face = std::get<ConformityFacePoint>(point);
  FieldExactRational sum = zero;
  for (std::size_t corner = 0; corner < 3U; ++corner) {
    if (face.face.vertices()[corner].index() >= vertexCount ||
        face.barycentric[corner] < zero) {
      return std::nullopt;
    }
    sum = sum + face.barycentric[corner];
    add_weight(weights, face.face.vertices()[corner].index(),
               face.barycentric[corner]);
  }
  return sum == one ? std::optional<VertexWeights>(weights) : std::nullopt;
}

bool independently_check_carrier(const authority::SourceSupport &carrier,
                                 const VertexWeights &weights) {
  std::set<std::size_t> allowed;
  if (const auto *vertex =
          std::get_if<authority::SourceVertexSupport>(&carrier)) {
    allowed.insert(vertex->vertex.index());
  } else if (const auto *edge =
                 std::get_if<authority::SourceEdgeSupport>(&carrier)) {
    allowed.insert(edge->edge.first().index());
    allowed.insert(edge->edge.second().index());
  } else {
    for (const auto vertex :
         std::get<authority::SourceFaceInteriorSupport>(carrier).face.vertices()) {
      allowed.insert(vertex.index());
    }
  }
  for (const auto &[vertex, weight] : weights) {
    if (weight != exact_integer(0) && !allowed.contains(vertex)) return false;
  }
  return true;
}

std::optional<std::array<FieldExactRational, 3>> independently_position(
    const VertexWeights &weights, const Eigen::MatrixXd &vertices) {
  std::array<FieldExactRational, 3> position{
      exact_integer(0), exact_integer(0), exact_integer(0)};
  for (const auto &[vertex, weight] : weights) {
    if (vertex >= static_cast<std::size_t>(vertices.rows())) return std::nullopt;
    for (int axis = 0; axis < 3; ++axis) {
      const auto coordinate = FieldExactRational::from_double_exact(
          vertices(static_cast<Eigen::Index>(vertex), axis));
      if (!coordinate) return std::nullopt;
      position[static_cast<std::size_t>(axis)] =
          position[static_cast<std::size_t>(axis)] + weight * *coordinate;
    }
  }
  return position;
}

std::optional<FieldExactRational> independently_target(
    const VertexWeights &weights, const Eigen::VectorXd &target) {
  FieldExactRational value = exact_integer(0);
  for (const auto &[vertex, weight] : weights) {
    if (vertex >= static_cast<std::size_t>(target.size())) return std::nullopt;
    const auto exact = FieldExactRational::from_double_exact(
        target(static_cast<Eigen::Index>(vertex)));
    if (!exact || *exact <= exact_integer(0)) return std::nullopt;
    value = value + weight * *exact;
  }
  return value;
}

std::optional<EInt> independently_preferred_count(
    const ConformitySpanInput &span, const Eigen::MatrixXd &vertices,
    const Eigen::VectorXd &target) {
  if (span.supportPieces.empty()) return std::nullopt;
  FieldExactRational energy = exact_integer(0);
  std::optional<ConformitySourcePoint> previous;

  for (const auto &piece : span.supportPieces) {
    if (previous && *previous != piece.first) return std::nullopt;
    const auto first = independently_decode_point(
        piece.first, static_cast<std::size_t>(vertices.rows()));
    const auto second = independently_decode_point(
        piece.second, static_cast<std::size_t>(vertices.rows()));
    if (!first || !second || piece.first == piece.second ||
        !independently_check_carrier(piece.carrier, *first) ||
        !independently_check_carrier(piece.carrier, *second)) {
      return std::nullopt;
    }
    const auto p0 = independently_position(*first, vertices);
    const auto p1 = independently_position(*second, vertices);
    const auto h0 = independently_target(*first, target);
    const auto h1 = independently_target(*second, target);
    if (!p0 || !p1 || !h0 || !h1) return std::nullopt;

    FieldExactRational squaredLength = exact_integer(0);
    for (std::size_t axis = 0; axis < 3U; ++axis) {
      const auto delta = (*p1)[axis] - (*p0)[axis];
      squaredLength = squaredLength + delta * delta;
    }
    if (squaredLength == exact_integer(0)) return std::nullopt;
    const auto midpointTarget = (*h0 + *h1) * exact_ratio(EInt(1), EInt(2));
    energy = energy + squaredLength / (midpointTarget * midpointTarget);
    previous = piece.second;
  }

  energy = energy * exact_ratio(exact_from_size(span.supportPieces.size()), EInt(1));
  if (energy <= exact_integer(0)) return std::nullopt;

  const EInt floor = integer_sqrt_floor(
      energy.exact_numerator() / energy.exact_denominator());
  const EInt twiceFloorPlusOne = EInt(2) * floor + EInt(1);
  const bool atOrBelowHalf =
      EInt(4) * energy.exact_numerator() <=
      twiceFloorPlusOne * twiceFloorPlusOne * energy.exact_denominator();
  EInt nearest = atOrBelowHalf ? floor : floor + EInt(1);
  if (nearest < EInt(1)) nearest = EInt(1);
  return nearest;
}

std::uint64_t independently_target_digest(const Eigen::VectorXd &target) {
  std::uint64_t hash = kFnvOffset;
  hash_u64(hash, static_cast<std::uint64_t>(target.size()));
  for (Eigen::Index row = 0; row < target.size(); ++row) {
    const auto exact = FieldExactRational::from_double_exact(target(row));
    if (!exact) return 0U;
    hash_exact(hash, *exact);
  }
  return hash;
}

void independently_hash_point(std::uint64_t &hash,
                              const ConformitySourcePoint &point) {
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
    for (const auto &weight : face.barycentric) hash_exact(hash, weight);
  }
}

void independently_hash_carrier(std::uint64_t &hash,
                                const authority::SourceSupport &carrier) {
  hash_u64(hash, static_cast<std::uint64_t>(carrier.index()));
  if (const auto *vertex =
          std::get_if<authority::SourceVertexSupport>(&carrier)) {
    hash_id(hash, vertex->vertex);
  } else if (const auto *edge =
                 std::get_if<authority::SourceEdgeSupport>(&carrier)) {
    hash_id(hash, edge->edge.first());
    hash_id(hash, edge->edge.second());
  } else {
    for (const auto vertex :
         std::get<authority::SourceFaceInteriorSupport>(carrier).face.vertices()) {
      hash_id(hash, vertex);
    }
  }
}

std::uint64_t independently_semantic_digest(
    const GlobalTopologyPlan &topology, std::uint64_t metricDigest,
    const std::vector<ConformityScheduleEntry> &schedule,
    const std::vector<ConformityIncidence> &incidences) {
  std::uint64_t hash = kFnvOffset;
  hash_u64(hash, topology.source_digest());
  hash_u64(hash, topology.network_digest());
  hash_u64(hash, topology.cut_graph_digest());
  hash_u64(hash, topology.semantic_digest());
  hash_u64(hash, metricDigest);
  hash_u64(hash, static_cast<std::uint64_t>(schedule.size()));
  for (const auto &entry : schedule) {
    hash_id(hash, entry.span.network_arc());
    hash_eint(hash, entry.count);
    hash_u64(hash, static_cast<std::uint64_t>(entry.supportPieces.size()));
    for (const auto &piece : entry.supportPieces) {
      independently_hash_carrier(hash, piece.carrier);
      independently_hash_point(hash, piece.first);
      independently_hash_point(hash, piece.second);
    }
  }
  hash_u64(hash, static_cast<std::uint64_t>(incidences.size()));
  for (const auto &incidence : incidences) {
    hash_id(hash, incidence.id.region);
    hash_u64(hash, incidence.id.canonicalBoundaryOccurrenceOrdinal);
    hash_id(hash, incidence.span.network_arc());
    hash_u64(hash, static_cast<std::uint64_t>(incidence.family));
    hash_u64(hash, static_cast<std::uint64_t>(static_cast<int>(incidence.sign) + 1));
    hash_u64(hash,
             static_cast<std::uint64_t>(static_cast<int>(incidence.orientation) + 1));
  }
  return hash;
}

std::size_t max_bits(const std::vector<EInt> &values) {
  std::size_t result = 0U;
  for (const auto &value : values) result = std::max(result, value.magnitude_bits());
  return result;
}

bool ordered_span_input_less(const ConformitySpanInput &a,
                             const ConformitySpanInput &b) {
  return a.id < b.id;
}
bool ordered_incidence_less(const ConformityIncidence &a,
                            const ConformityIncidence &b) {
  return std::tie(a.id.region, a.id.canonicalBoundaryOccurrenceOrdinal,
                  a.span, a.family, a.sign, a.orientation) <
         std::tie(b.id.region, b.id.canonicalBoundaryOccurrenceOrdinal,
                  b.span, b.family, b.sign, b.orientation);
}

}  // namespace

std::optional<GlobalConformityPlanError> validate_global_conformity_candidate(
    const GlobalTopologyPlan &topology,
    const GlobalConformityKnownFeasibleInput &input,
    const GlobalConformityPlanValidationCandidate &candidate) {
  if (input.sourceVertices.cols() != 3 || input.sourceVertices.rows() <= 0 ||
      input.targetSize.size() != input.sourceVertices.rows()) {
    return validation_error("source/target dimensions are inconsistent");
  }
  for (Eigen::Index row = 0; row < input.sourceVertices.rows(); ++row) {
    for (Eigen::Index axis = 0; axis < input.sourceVertices.cols(); ++axis) {
      if (!FieldExactRational::from_double_exact(input.sourceVertices(row, axis))) {
        return validation_error("source coordinate is not finite exact binary64");
      }
    }
    const auto target =
        FieldExactRational::from_double_exact(input.targetSize(row));
    if (!target || *target <= exact_integer(0)) {
      return validation_error("target metric is not finite and strictly positive");
    }
  }
  if (candidate.sourceDigest != topology.source_digest() ||
      candidate.networkDigest != topology.network_digest() ||
      candidate.cutGraphDigest != topology.cut_graph_digest() ||
      candidate.topologyPlanDigest != topology.semantic_digest()) {
    return validation_error("source/network/cut/topology digest binding mismatch");
  }

  const std::uint64_t metricDigest = independently_target_digest(input.targetSize);
  if (metricDigest == 0U || candidate.targetMetricDigest != metricDigest) {
    return validation_error("target metric digest mismatch");
  }

  std::vector<ConformitySpanInput> spans = input.spans;
  std::sort(spans.begin(), spans.end(), ordered_span_input_less);
  if (spans.size() != topology.arcs().size() ||
      candidate.schedule.size() != spans.size()) {
    return validation_error("schedule does not own exactly one entry per A2b arc");
  }

  std::map<ConformitySpanId, std::size_t> scheduleIndex;
  std::vector<EInt> preferred;
  std::vector<EInt> counts;
  preferred.reserve(spans.size());
  counts.reserve(spans.size());
  EInt D(0);
  for (std::size_t index = 0; index < spans.size(); ++index) {
    if (index != 0U && spans[index - 1U].id == spans[index].id) {
      return validation_error("duplicate conformity span in input");
    }
    if (!topology.find_arc(spans[index].id.network_arc())) {
      return validation_error("span does not bind to an A2b arc");
    }
    const auto derived = independently_preferred_count(
        spans[index], input.sourceVertices, input.targetSize);
    if (!derived) return validation_error("span target/support derivation failed");
    if (candidate.schedule[index].span != spans[index].id ||
        candidate.schedule[index].supportPieces != spans[index].supportPieces ||
        candidate.schedule[index].preferredCount != *derived ||
        candidate.schedule[index].count < EInt(1)) {
      return validation_error("schedule span/support/preference/positivity mismatch");
    }
    preferred.push_back(*derived);
    counts.push_back(candidate.schedule[index].count);
    D += *derived;
    scheduleIndex.emplace(spans[index].id, index);
  }

  std::vector<ConformityIncidence> incidences = input.incidences;
  std::sort(incidences.begin(), incidences.end(), ordered_incidence_less);
  if (candidate.incidences != incidences) {
    return validation_error("canonical boundary-incidence sequence mismatch");
  }

  using RowKey = std::pair<std::size_t, int>;
  std::map<RowKey, EInt> signedBalance;
  std::map<RowKey, EInt> unsignedBoundary;
  std::set<std::pair<std::size_t, std::size_t>> seenOccurrences;
  for (const auto &incidence : candidate.incidences) {
    const auto region = std::find_if(
        topology.regions().begin(), topology.regions().end(),
        [&](const auto &value) { return value.id == incidence.id.region; });
    if (region == topology.regions().end() ||
        incidence.id.canonicalBoundaryOccurrenceOrdinal >= region->boundary.size()) {
      return validation_error("incidence region/ordinal is invalid");
    }
    const auto &boundary =
        region->boundary[incidence.id.canonicalBoundaryOccurrenceOrdinal];
    if (boundary.arc != incidence.span.network_arc() ||
        boundary.orientation != incidence.orientation) {
      return validation_error("incidence does not bind to exact A2b boundary occurrence");
    }
    if (!seenOccurrences.emplace(incidence.id.region.index(),
                                 incidence.id.canonicalBoundaryOccurrenceOrdinal)
             .second) {
      return validation_error("boundary occurrence was duplicated/collapsed");
    }
    const auto scheduleIt = scheduleIndex.find(incidence.span);
    if (scheduleIt == scheduleIndex.end()) {
      return validation_error("incidence names an unscheduled span");
    }
    const RowKey key{incidence.id.region.index(), static_cast<int>(incidence.family)};
    const EInt count = counts[scheduleIt->second];
    signedBalance[key] += incidence.sign == ConformitySign::Positive ? count : -count;
    unsignedBoundary[key] += count;
  }
  std::size_t expectedOccurrences = 0U;
  for (const auto &region : topology.regions()) expectedOccurrences += region.boundary.size();
  if (seenOccurrences.size() != expectedOccurrences) {
    return validation_error("not every A2b boundary occurrence is represented exactly once");
  }
  std::map<ConformitySpanId, std::size_t> incidenceDegree;
  for (const auto &incidence : candidate.incidences) {
    ++incidenceDegree[incidence.span];
  }
  bool hasOuterBoundarySpan = false;
  for (const auto &span : spans) {
    const auto degree = incidenceDegree[span.id];
    if (degree == 0U || degree > 2U) {
      return validation_error("span incidence degree is unsupported");
    }
    hasOuterBoundarySpan = hasOuterBoundarySpan || degree == 1U;
  }
  for (const auto &[key, balance] : signedBalance) {
    if (balance != EInt(0)) return validation_error("region/family balance is nonzero");
    if (unsignedBoundary[key] % EInt(2) != EInt(0)) {
      return validation_error("region/family unsigned boundary parity is odd");
    }
  }

  const std::size_t E = spans.size();
  const std::size_t V = signedBalance.size();
  if (E == 0U || V == 0U) return validation_error("empty normalized exact problem");
  const std::size_t solverRows = V + (hasOuterBoundarySpan ? 1U : 0U);
  const EInt exactE = exact_from_size(E);
  const EInt H = exactE * exact_power(EInt(2), V);
  const EInt U = EInt(2) * D + exactE * H;
  const EInt Q = U + EInt(1);
  const EInt L = exact_power(Q, E);
  if (candidate.finiteCapU != U || candidate.radixQ != Q ||
      candidate.lexicographicScaleL != L) {
    return validation_error("U/Q/L exact bound/radix identity mismatch");
  }
  for (const auto &count : counts) {
    if (count > U) return validation_error("schedule count exceeds finite cap U");
  }

  ConformityObjectiveValue objective;
  objective.primaryDeviation = EInt(0);
  objective.scalarValue = EInt(0);
  std::vector<EInt> costs;
  costs.reserve(E);
  for (std::size_t index = 0; index < E; ++index) {
    const EInt deviation = (counts[index] - preferred[index]).abs();
    const EInt q = exact_power(Q, E - index - 1U);
    const EInt cost = L * deviation + q * counts[index];
    objective.primaryDeviation += deviation;
    objective.canonicalCounts.push_back(counts[index]);
    objective.scalarValue += cost;
    costs.push_back(cost);
  }
  if (candidate.objective.primaryDeviation != objective.primaryDeviation ||
      candidate.objective.canonicalCounts != objective.canonicalCounts ||
      candidate.objective.scalarValue != objective.scalarValue) {
    return validation_error("semantic/scalar objective reconstruction mismatch");
  }

  const auto &ledger = candidate.workLedger;
  if (ledger.algorithmIdentity !=
          "HeistermannWarnettBommes2023ExactBiMDFRefinementM2" ||
      ledger.matchingPrimitiveIdentity !=
          "LEMON-1.3.1-MaxWeightedPerfectMatching-exact-EInt-adapter" ||
      ledger.matchingPrimitiveRevision !=
          "seqan/lemon@813c63d4f1d603858d941ac6f04abbe57901996a" ||
      ledger.semanticRowCount != V || ledger.semanticSpanCount != E ||
      ledger.initializerNodeCount != solverRows * 2U ||
      ledger.initializerArcCount > (E + (hasOuterBoundarySpan ? 1U : 0U)) * 4U ||
      !ledger.initializerExactFeasibilityValidated || ledger.refinementM != 2 ||
      ledger.refinementCount != ledger.refinements.size() ||
      ledger.hBitWidth != H.magnitude_bits() ||
      ledger.uBitWidth != U.magnitude_bits() ||
      ledger.qBitWidth != Q.magnitude_bits() ||
      ledger.lBitWidth != L.magnitude_bits() ||
      ledger.maximumTargetBitWidth != max_bits(preferred) ||
      ledger.maximumCountBitWidth != max_bits(counts) ||
      ledger.maximumCapacityBitWidth != U.magnitude_bits() ||
      ledger.maximumCostBitWidth != max_bits(costs) ||
      !ledger.terminalExactNonImprovementValidated ||
      ledger.terminalRefinementCostChange < EInt(0) ||
      ledger.retryResetCount != 0U) {
    return validation_error("WorkLedger identity/dimension/exact-width claim mismatch");
  }
  for (const auto &step : ledger.refinements) {
    if (!(step.after.scalarValue < step.before.scalarValue) ||
        step.before.canonicalCounts.size() != E ||
        step.after.canonicalCounts.size() != E ||
        step.biMcfEdgeCount >
            (E + (hasOuterBoundarySpan ? 1U : 0U)) * 4U ||
        step.bMatchingNodeCount > solverRows * 2U ||
        step.wpmNodeCount > ledger.peakMatchingNodeCount ||
        step.wpmEdgeCount > ledger.peakMatchingEdgeCount) {
      return validation_error("WorkLedger refinement evidence is inconsistent");
    }
  }

  const std::uint64_t semanticDigest = independently_semantic_digest(
      topology, metricDigest, candidate.schedule, candidate.incidences);
  if (candidate.semanticDigest != semanticDigest) {
    return validation_error("semantic digest mismatch");
  }
  return std::nullopt;
}

GlobalConformityPlanBuildResult validate_global_conformity_plan(
    const GlobalTopologyPlan &topology,
    const GlobalConformityKnownFeasibleInput &input,
    const GlobalConformityPlan &plan) {
  if (const auto error =
          validate_global_conformity_candidate(topology, input,
                                               plan.validation_candidate())) {
    return GlobalConformityPlanBuildResult(*error);
  }

  // Independently probe the compact generator at endpoints and two interior
  // ordinals. This stays O(E) regardless of exact count magnitude.
  for (const auto &entry : plan.schedule()) {
    const auto first = plan.breakpoint_location(entry.span, EInt(0));
    const auto last = plan.breakpoint_location(entry.span, entry.count);
    if (!first || !last || !first->firstEndpoint || first->lastEndpoint ||
        first->localNumerator != EInt(0) || first->localDenominator != EInt(1) ||
        !last->lastEndpoint || last->firstEndpoint ||
        last->supportPieceIndex + 1U != entry.supportPieces.size() ||
        last->localNumerator != EInt(1) || last->localDenominator != EInt(1)) {
      return GlobalConformityPlanBuildResult(
          validation_error("compact breakpoint endpoint generator mismatch"));
    }
    if (entry.count > EInt(1)) {
      const EInt one(1);
      const EInt reverseOrdinal = entry.count - one;
      const auto forward = plan.breakpoint_location(entry.span, one);
      const auto reverse = plan.breakpoint_location(entry.span, reverseOrdinal);
      if (!forward || !reverse || forward->id.exactOrdinal != one ||
          reverse->id.exactOrdinal != reverseOrdinal ||
          forward->localDenominator != entry.count ||
          reverse->localDenominator != entry.count) {
        return GlobalConformityPlanBuildResult(
            validation_error("compact breakpoint/reversal ordinal mismatch"));
      }
    }
  }
  return GlobalConformityPlanBuildResult(plan);
}

}  // namespace directional::geometry
