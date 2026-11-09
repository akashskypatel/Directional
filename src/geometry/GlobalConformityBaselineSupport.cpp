#include "GlobalConformityBaselineSupport.h"

#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <string>

namespace directional::geometry::global_conformity_baseline_detail {
namespace {

using authority::FieldExactRational;
using VertexWeights = std::map<std::size_t, FieldExactRational>;

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

void hash_exact(std::uint64_t &hash, const FieldExactRational &value) {
  hash_eint(hash, value.exact_numerator());
  hash_eint(hash, value.exact_denominator());
}

FieldExactRational exact_integer(long long value) {
  return *FieldExactRational::from_exact_fraction(EInt(value), EInt(1));
}

FieldExactRational exact_ratio(const EInt &numerator, const EInt &denominator) {
  return *FieldExactRational::from_exact_fraction(numerator, denominator);
}

void add_weight(VertexWeights &weights, std::size_t vertex,
                const FieldExactRational &weight) {
  const auto [it, inserted] = weights.emplace(vertex, weight);
  if (!inserted) it->second = it->second + weight;
}

std::optional<VertexWeights> point_weights(const ConformitySourcePoint &point,
                                           std::size_t vertexCount) {
  if (!authority::exact_source_point_is_canonical(point)) return std::nullopt;
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
        edge->edge.second().index() >= vertexCount || edge->parameter < zero ||
        edge->parameter > one) {
      return std::nullopt;
    }
    add_weight(weights, edge->edge.first().index(), one - edge->parameter);
    add_weight(weights, edge->edge.second().index(), edge->parameter);
    return weights;
  }
  const auto &face = std::get<ConformityFacePoint>(point);
  FieldExactRational sum = zero;
  for (std::size_t corner = 0U; corner < 3U; ++corner) {
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

bool carrier_contains(const authority::SourceSupport &carrier,
                      const VertexWeights &weights) {
  std::set<std::size_t> allowed;
  if (const auto *vertex = std::get_if<authority::SourceVertexSupport>(&carrier)) {
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

std::optional<std::array<FieldExactRational, 3>> exact_position(
    const VertexWeights &weights, const Eigen::MatrixXd &vertices) {
  std::array<FieldExactRational, 3> position{
      exact_integer(0), exact_integer(0), exact_integer(0)};
  for (const auto &[vertex, weight] : weights) {
    if (vertex >= static_cast<std::size_t>(vertices.rows())) return std::nullopt;
    for (int axis = 0; axis < 3; ++axis) {
      const auto coordinate =
          FieldExactRational::from_double_exact(vertices(
              static_cast<Eigen::Index>(vertex), axis));
      if (!coordinate) return std::nullopt;
      position[static_cast<std::size_t>(axis)] =
          position[static_cast<std::size_t>(axis)] + weight * *coordinate;
    }
  }
  return position;
}

// D7 density rho = 1/h, interpolated from exact vertex reciprocals so that it
// is affine on every source simplex (RA-216).
std::optional<FieldExactRational>
exact_reciprocal_target(const VertexWeights &weights,
                        const Eigen::VectorXd &target) {
  FieldExactRational value = exact_integer(0);
  for (const auto &[vertex, weight] : weights) {
    if (vertex >= static_cast<std::size_t>(target.size())) return std::nullopt;
    const auto exact =
        FieldExactRational::from_double_exact(target(static_cast<Eigen::Index>(vertex)));
    if (!exact || *exact <= exact_integer(0)) return std::nullopt;
    value = value + weight / *exact;
  }
  return value;
}

// Each straight run contributes the floor of its exact metric length at this
// many fractional bits; the D7 count rounds their sum once (RA-216).
constexpr std::size_t kPartitionStableMetricFractionalBits = 64U;

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

// floor(2^64 * metric) for a run's exact squared metric: its D7 count share.
EInt scaled_metric_floor(const FieldExactRational &squared, const EInt &scale) {
  return integer_sqrt_floor(squared.exact_numerator() * scale * scale /
                            squared.exact_denominator());
}

// ceil(2^64 * metric): the run's breakpoint weight, at least 1 for every
// positive-length run, so no run is erased and reversal stays exact (RA-217).
EInt scaled_metric_ceiling(const FieldExactRational &squared, const EInt &scale) {
  const EInt scaledSquare = squared.exact_numerator() * scale * scale;
  EInt ceiling = scaledSquare / squared.exact_denominator();
  if (ceiling * squared.exact_denominator() != scaledSquare) ceiling += EInt(1);
  return integer_sqrt_floor(ceiling - EInt(1)) + EInt(1);
}

} // namespace

EInt exact_from_size(std::size_t value) {
  EInt out(0);
  for (int bit = static_cast<int>(sizeof(std::size_t) * 8U) - 1; bit >= 0;
       --bit) {
    out *= EInt(2);
    if (((value >> static_cast<unsigned>(bit)) & std::size_t{1}) != 0U) {
      out += EInt(1);
    }
  }
  return out;
}

std::optional<EInt> derive_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize) {
  return derive_partition_stable_preferred_count_exact(span, sourceVertices,
                                                       targetSize);
}

std::optional<std::vector<BaselineConformityMetricRun>>
derive_partition_stable_metric_runs(const ConformitySpanInput &span,
                                    const Eigen::MatrixXd &sourceVertices,
                                    const Eigen::VectorXd &targetSize) {
  if (span.supportPieces.empty()) return std::nullopt;
  const auto zero = exact_integer(0);
  const auto half = exact_ratio(EInt(1), EInt(2));
  // A run is a maximal sequence of consecutive pieces along one direction u.
  // rho is affine on each piece, so a piece d contributes exactly
  // (d.u) * (rho0 + rho1) / 2 / |u|, and the run's squared metric is rational.
  std::vector<BaselineConformityMetricRun> runs;
  std::array<FieldExactRational, 3> direction{zero, zero, zero};
  FieldExactRational directionSquared = zero;
  FieldExactRational runMeasure = zero;
  std::vector<FieldExactRational> runAlong;
  const auto close_run = [&](std::size_t endPiece) {
    if (runAlong.empty()) return;
    BaselineConformityMetricRun run;
    run.firstPiece = endPiece - runAlong.size();
    FieldExactRational length = zero;
    for (const auto &along : runAlong) length = length + along;
    FieldExactRational start = zero;
    for (const auto &along : runAlong) {
      run.pieceStarts.push_back(start / length);
      start = start + along;
    }
    run.squaredMetric = runMeasure * runMeasure / directionSquared;
    runs.push_back(std::move(run));
    runAlong.clear();
  };
  std::optional<ConformitySourcePoint> previous;
  for (std::size_t index = 0U; index < span.supportPieces.size(); ++index) {
    const auto &piece = span.supportPieces[index];
    if (previous && *previous != piece.first) return std::nullopt;
    const auto first =
        point_weights(piece.first, static_cast<std::size_t>(sourceVertices.rows()));
    const auto second =
        point_weights(piece.second, static_cast<std::size_t>(sourceVertices.rows()));
    if (!first || !second || piece.first == piece.second ||
        !carrier_contains(piece.carrier, *first) ||
        !carrier_contains(piece.carrier, *second)) {
      return std::nullopt;
    }
    const auto p0 = exact_position(*first, sourceVertices);
    const auto p1 = exact_position(*second, sourceVertices);
    const auto rho0 = exact_reciprocal_target(*first, targetSize);
    const auto rho1 = exact_reciprocal_target(*second, targetSize);
    if (!p0 || !p1 || !rho0 || !rho1) return std::nullopt;

    std::array<FieldExactRational, 3> delta{zero, zero, zero};
    FieldExactRational deltaSquared = zero;
    FieldExactRational along = zero;
    for (std::size_t axis = 0U; axis < 3U; ++axis) {
      delta[axis] = (*p1)[axis] - (*p0)[axis];
      deltaSquared = deltaSquared + delta[axis] * delta[axis];
      along = along + delta[axis] * direction[axis];
    }
    if (deltaSquared == zero) return std::nullopt;
    // Same direction iff Cauchy-Schwarz holds with equality and d.u > 0.
    if (!(along > zero && along * along == deltaSquared * directionSquared)) {
      close_run(index);
      direction = delta;
      directionSquared = deltaSquared;
      runMeasure = zero;
      along = deltaSquared;
    }
    runMeasure = runMeasure + along * (*rho0 + *rho1) * half;
    runAlong.push_back(along);
    previous = piece.second;
  }
  close_run(span.supportPieces.size());
  return runs;
}

std::optional<EInt> derive_partition_stable_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize) {
  const auto runs =
      derive_partition_stable_metric_runs(span, sourceVertices, targetSize);
  if (!runs) return std::nullopt;
  const EInt scale = exact_power(EInt(2), kPartitionStableMetricFractionalBits);
  EInt scaledTotal(0);
  for (const auto &run : *runs) {
    scaledTotal += scaled_metric_floor(run.squaredMetric, scale);
  }

  EInt nearest = scaledTotal / scale;
  if (EInt(2) * (scaledTotal - nearest * scale) > scale) nearest += EInt(1);
  if (nearest < EInt(1)) nearest = EInt(1);
  return nearest;
}

std::optional<ConformityBreakpointLocation> derive_metric_breakpoint_location(
    ConformitySpanId span, std::size_t pieceCount,
    const std::vector<BaselineConformityMetricRun> &runs, const EInt &count,
    const EInt &ordinal) {
  const EInt zero(0);
  const EInt one(1);
  if (pieceCount == 0U || runs.empty() || count < one || ordinal < zero ||
      ordinal > count) {
    return std::nullopt;
  }
  // The runs must tile the pieces in order, each run's piece starts rising
  // strictly from 0 and staying below 1.
  const auto exactZero = exact_integer(0);
  const auto exactOne = exact_integer(1);
  std::size_t nextPiece = 0U;
  for (const auto &run : runs) {
    const auto &starts = run.pieceStarts;
    if (run.firstPiece != nextPiece || starts.empty() ||
        starts.size() > pieceCount - nextPiece || starts.front() != exactZero ||
        !(starts.back() < exactOne) || !(run.squaredMetric > exactZero) ||
        std::adjacent_find(starts.begin(), starts.end(),
                           [](const auto &a, const auto &b) { return !(a < b); }) !=
            starts.end()) {
      return std::nullopt;
    }
    nextPiece += starts.size();
  }
  if (nextPiece != pieceCount) return std::nullopt;

  const ConformityBreakpointId id{span, ordinal};
  if (ordinal == zero) {
    return ConformityBreakpointLocation{id, 0U, zero, one, true, false};
  }
  if (ordinal == count) {
    return ConformityBreakpointLocation{id, pieceCount - 1U, one, one, false, true};
  }
  if (pieceCount == 1U) {
    return ConformityBreakpointLocation{id, 0U, ordinal, count, false, false};
  }

  // Run r owns the ordinals with C_r <= ordinal * W / count < C_r + W_r, where
  // W_r is the run's weight and W, C_r are the total and prefix weights. Within
  // the run, t = (ordinal * W - count * C_r) / (count * W_r) is linear in length.
  const EInt scale = exact_power(EInt(2), kPartitionStableMetricFractionalBits);
  std::vector<EInt> weights;
  EInt total(0);
  for (const auto &run : runs) {
    weights.push_back(scaled_metric_ceiling(run.squaredMetric, scale));
    total += weights.back();
  }
  const EInt target = ordinal * total;
  EInt prefix(0);
  for (std::size_t r = 0U; r < runs.size(); ++r) {
    if (target < count * (prefix + weights[r])) {
      const auto t = exact_ratio(target - count * prefix, count * weights[r]);
      const auto &starts = runs[r].pieceStarts;
      const auto piece = static_cast<std::size_t>(
          std::upper_bound(starts.begin(), starts.end(), t) - starts.begin() - 1);
      const auto end = piece + 1U < starts.size() ? starts[piece + 1U] : exactOne;
      const auto local = (t - starts[piece]) / (end - starts[piece]);
      return ConformityBreakpointLocation{id, runs[r].firstPiece + piece,
                                          local.exact_numerator(),
                                          local.exact_denominator(), false, false};
    }
    prefix += weights[r];
  }
  return std::nullopt;
}

std::optional<std::vector<BaselineMandatoryChain>>
derive_mandatory_chain_partition(
    const std::vector<GlobalTopologyArc> &arcs,
    const std::vector<GlobalTopologyNodeRotation> &rotations,
    const std::vector<FieldAlignedMandatoryEdge> &mandatoryEdges,
    const std::set<authority::NetworkNodeId> &stopNodes) {
  using authority::NetworkArcId;
  using authority::NetworkNodeId;
  using authority::Orientation;
  std::map<authority::NetworkEdgeId, authority::HardRailId> railOfEdge;
  for (const auto &edge : mandatoryEdges) {
    if (!railOfEdge.emplace(edge.id, edge.rail).second) return std::nullopt;
  }
  std::map<NetworkArcId, const GlobalTopologyArc *> arcById;
  std::map<NetworkArcId, authority::HardRailId> railOfArc;
  for (const auto &arc : arcs) {
    if (!arcById.emplace(arc.id, &arc).second) return std::nullopt;
    if (arc.kind != GlobalTopologyArcKind::Mandatory) continue;
    if (!arc.mandatoryEdge) return std::nullopt;
    const auto rail = railOfEdge.find(*arc.mandatoryEdge);
    if (rail == railOfEdge.end()) return std::nullopt;
    railOfArc.emplace(arc.id, rail->second);
  }

  // The two arcs that continue through each pass-through node.
  std::map<NetworkNodeId, std::array<NetworkArcId, 2>> joins;
  std::set<NetworkNodeId> rotationNodes;
  std::set<GlobalTopologyOrientedArc> incidences;
  for (const auto &rotation : rotations) {
    if (!rotationNodes.insert(rotation.node).second) return std::nullopt;
    for (const auto &incidence : rotation.counterClockwise) {
      const auto found = arcById.find(incidence.arc);
      if (found == arcById.end() || !incidences.insert(incidence).second) {
        return std::nullopt;
      }
      const auto end = incidence.orientation == Orientation::Forward
                           ? found->second->firstNode
                           : found->second->secondNode;
      if (end != rotation.node) return std::nullopt;
    }
    if (stopNodes.count(rotation.node) != 0U ||
        rotation.counterClockwise.size() != 2U) {
      continue;
    }
    const auto first = rotation.counterClockwise[0].arc;
    const auto second = rotation.counterClockwise[1].arc;
    const auto firstRail = railOfArc.find(first);
    const auto secondRail = railOfArc.find(second);
    if (first != second && firstRail != railOfArc.end() &&
        secondRail != railOfArc.end() && firstRail->second == secondRail->second) {
      joins.emplace(rotation.node, std::array<NetworkArcId, 2>{first, second});
    }
  }

  // Every arc end has exactly one rotation incidence, so a join names every
  // arc that ends at its node.
  if (incidences.size() != 2U * arcById.size()) return std::nullopt;

  std::vector<BaselineMandatoryChain> chains;
  std::set<NetworkArcId> placed;
  // Each path is walked from its lower-id end arc; arcs with both ends joined
  // are path interiors or lie on a join cycle.
  for (const auto &[id, arc] : arcById) {
    const bool joinedFirst = joins.count(arc->firstNode) != 0U;
    const bool joinedSecond = joins.count(arc->secondNode) != 0U;
    if (placed.count(id) != 0U || (joinedFirst && joinedSecond)) continue;
    BaselineMandatoryChain chain;
    NetworkArcId current = id;
    NetworkNodeId entry = joinedFirst ? arc->secondNode : arc->firstNode;
    while (true) {
      if (!placed.insert(current).second) return std::nullopt;
      const auto *currentArc = arcById.at(current);
      const bool forward = currentArc->firstNode == entry;
      chain.arcs.push_back(
          {current, forward ? Orientation::Forward : Orientation::Reverse});
      const auto exit = forward ? currentArc->secondNode : currentArc->firstNode;
      const auto join = joins.find(exit);
      if (join == joins.end()) break;
      current = join->second[0] == current ? join->second[1] : join->second[0];
      entry = exit;
    }
    chains.push_back(std::move(chain));
  }
  for (const auto &[id, arc] : arcById) {
    (void)arc;
    if (placed.insert(id).second) {
      chains.push_back(BaselineMandatoryChain{{{id, Orientation::Forward}}});
    }
  }
  std::sort(chains.begin(), chains.end(), [](const auto &lhs, const auto &rhs) {
    return lhs.arcs.front().arc < rhs.arcs.front().arc;
  });
  return chains;
}

std::optional<std::vector<ConformitySupportPiece>>
derive_mandatory_chain_support(const BaselineMandatoryChain &chain,
                               const std::vector<GlobalTopologyArc> &arcs) {
  std::vector<ConformitySupportPiece> support;
  for (const auto &oriented : chain.arcs) {
    const auto arc = std::find_if(arcs.begin(), arcs.end(), [&](const auto &candidate) {
      return candidate.id == oriented.arc;
    });
    if (arc == arcs.end()) return std::nullopt;
    const auto path = authority::exact_source_path_for_orientation(
        arc->sourcePath, oriented.orientation);
    support.insert(support.end(), path.begin(), path.end());
  }
  if (!authority::exact_source_path_is_canonical(support)) return std::nullopt;
  return support;
}

std::uint64_t exact_target_metric_digest(const Eigen::VectorXd &targetSize) {
  std::uint64_t hash = kFnvOffset;
  hash_u64(hash, static_cast<std::uint64_t>(targetSize.size()));
  for (Eigen::Index index = 0; index < targetSize.size(); ++index) {
    const auto exact = FieldExactRational::from_double_exact(targetSize(index));
    if (!exact || *exact <= exact_integer(0)) return 0U;
    hash_exact(hash, *exact);
  }
  return hash;
}

} // namespace directional::geometry::global_conformity_baseline_detail
