#include "GlobalConformityBaselineSupport.h"

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

std::optional<std::size_t> exact_to_size_checked(const EInt &value) {
  if (value < EInt(0)) return std::nullopt;
  std::size_t out = 0U;
  const EInt two(2);
  EInt remaining = value;
  std::size_t shift = 0U;
  while (remaining != EInt(0)) {
    if (shift >= sizeof(std::size_t) * 8U) return std::nullopt;
    if (remaining % two != EInt(0)) out |= std::size_t{1} << shift;
    remaining /= two;
    ++shift;
  }
  return out;
}

std::optional<EInt> derive_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize) {
  return derive_partition_stable_preferred_count_exact(span, sourceVertices,
                                                       targetSize);
}

std::optional<EInt> derive_partition_stable_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize) {
  if (span.supportPieces.empty()) return std::nullopt;
  const auto zero = exact_integer(0);
  const auto half = exact_ratio(EInt(1), EInt(2));
  const EInt scale = exact_power(EInt(2), kPartitionStableMetricFractionalBits);
  // A run is a maximal sequence of consecutive pieces along one direction u.
  // rho is affine on each piece, so a piece d contributes exactly
  // (d.u) * (rho0 + rho1) / 2 / |u|, and the run's squared metric is rational.
  std::array<FieldExactRational, 3> direction{zero, zero, zero};
  FieldExactRational directionSquared = zero;
  FieldExactRational runMeasure = zero;
  EInt scaledTotal(0);
  const auto close_run = [&]() {
    if (directionSquared == zero) return;
    const auto squared = runMeasure * runMeasure / directionSquared;
    scaledTotal += integer_sqrt_floor(squared.exact_numerator() * scale *
                                      scale / squared.exact_denominator());
  };
  std::optional<ConformitySourcePoint> previous;
  for (const auto &piece : span.supportPieces) {
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
      close_run();
      direction = delta;
      directionSquared = deltaSquared;
      runMeasure = zero;
      along = deltaSquared;
    }
    runMeasure = runMeasure + along * (*rho0 + *rho1) * half;
    previous = piece.second;
  }
  close_run();

  EInt nearest = scaledTotal / scale;
  if (EInt(2) * (scaledTotal - nearest * scale) > scale) nearest += EInt(1);
  if (nearest < EInt(1)) nearest = EInt(1);
  return nearest;
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
