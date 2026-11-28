#include <directional/pipeline/InputConditioner.h>

#include <directional/authority/FieldTransportAtlas.h>

#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>

namespace directional::pipeline {
namespace {

using Rational = authority::FieldExactRational;

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void hash_bytes(std::uint64_t &hash, const void *data, const std::size_t size) {
  const auto *bytes = static_cast<const unsigned char *>(data);
  for (std::size_t i = 0; i < size; ++i) {
    hash ^= static_cast<std::uint64_t>(bytes[i]);
    hash *= kFnvPrime;
  }
}

template <typename T> void hash_scalar(std::uint64_t &hash, const T &value) {
  hash_bytes(hash, &value, sizeof(T));
}

void hash_string(std::uint64_t &hash, const std::string &value) {
  const std::uint64_t size = static_cast<std::uint64_t>(value.size());
  hash_scalar(hash, size);
  hash_bytes(hash, value.data(), value.size());
}

void hash_double(std::uint64_t &hash, const double value) {
  const std::uint64_t bits = std::bit_cast<std::uint64_t>(value);
  hash_scalar(hash, bits);
}

std::uint64_t raw_digest_impl(const RawSurfaceCellInput &raw) {
  std::uint64_t hash = kFnvOffset;
  hash_string(hash, "RawSurfaceCellInput-v1");
  hash_scalar(hash, static_cast<std::uint64_t>(raw.vertices.rows()));
  hash_scalar(hash, static_cast<std::uint64_t>(raw.vertices.cols()));
  for (Eigen::Index r = 0; r < raw.vertices.rows(); ++r) {
    for (Eigen::Index c = 0; c < raw.vertices.cols(); ++c) {
      hash_double(hash, raw.vertices(r, c));
    }
  }
  hash_scalar(hash, static_cast<std::uint64_t>(raw.faces.rows()));
  hash_scalar(hash, static_cast<std::uint64_t>(raw.faces.cols()));
  for (Eigen::Index r = 0; r < raw.faces.rows(); ++r) {
    for (Eigen::Index c = 0; c < raw.faces.cols(); ++c) {
      hash_scalar(hash, static_cast<std::int64_t>(raw.faces(r, c)));
    }
  }
  hash_scalar(hash, static_cast<std::uint64_t>(raw.rawCrossField.rows()));
  hash_scalar(hash, static_cast<std::uint64_t>(raw.rawCrossField.cols()));
  for (Eigen::Index r = 0; r < raw.rawCrossField.rows(); ++r) {
    for (Eigen::Index c = 0; c < raw.rawCrossField.cols(); ++c) {
      hash_double(hash, raw.rawCrossField(r, c));
    }
  }
  hash_scalar(hash, static_cast<std::uint64_t>(raw.hardFeatures.size()));
  for (const RawConditioningFeatureEdge &edge : raw.hardFeatures) {
    hash_scalar(hash, static_cast<std::int64_t>(edge.vertex0));
    hash_scalar(hash, static_cast<std::int64_t>(edge.vertex1));
  }
  return hash;
}

void hash_policy(std::uint64_t &hash, const ConditioningPolicy &policy) {
  hash_string(hash, policy.id);
  hash_scalar(hash, policy.quantizeGeometry);
  hash_scalar(hash, policy.quantizeField);
  hash_scalar(hash, static_cast<std::int64_t>(policy.latticeExponent));
  hash_scalar(hash, policy.maxAbsLatticeInteger);
  hash_scalar(hash, policy.mergeExactDuplicates);
  hash_scalar(hash, policy.canonicalizeFieldBranches);
  hash_scalar(hash, policy.refuseSlivers);
  hash_scalar(hash, policy.sliverRatioNumerator);
  hash_scalar(hash, policy.sliverRatioDenominator);
}

std::uint64_t semantic_digest_impl(const ConditionedSourceProduct &product,
                                   const ConditioningPolicy &policy) {
  std::uint64_t hash = kFnvOffset;
  hash_string(hash, "ConditionedSourceProduct-v1");
  hash_policy(hash, policy);
  hash_scalar(hash, static_cast<std::uint64_t>(product.vertices.rows()));
  hash_scalar(hash, static_cast<std::uint64_t>(product.vertices.cols()));
  for (Eigen::Index r = 0; r < product.vertices.rows(); ++r) {
    for (Eigen::Index c = 0; c < product.vertices.cols(); ++c) {
      hash_double(hash, product.vertices(r, c));
    }
  }
  hash_scalar(hash, static_cast<std::uint64_t>(product.faces.rows()));
  hash_scalar(hash, static_cast<std::uint64_t>(product.faces.cols()));
  for (Eigen::Index r = 0; r < product.faces.rows(); ++r) {
    for (Eigen::Index c = 0; c < product.faces.cols(); ++c) {
      hash_scalar(hash, static_cast<std::int64_t>(product.faces(r, c)));
    }
  }
  hash_scalar(hash, static_cast<std::uint64_t>(product.rawCrossField.rows()));
  hash_scalar(hash, static_cast<std::uint64_t>(product.rawCrossField.cols()));
  for (Eigen::Index r = 0; r < product.rawCrossField.rows(); ++r) {
    for (Eigen::Index c = 0; c < product.rawCrossField.cols(); ++c) {
      hash_double(hash, product.rawCrossField(r, c));
    }
  }
  hash_scalar(hash, static_cast<std::uint64_t>(product.hardFeatures.size()));
  for (const RawConditioningFeatureEdge &edge : product.hardFeatures) {
    hash_scalar(hash, static_cast<std::int64_t>(edge.vertex0));
    hash_scalar(hash, static_cast<std::int64_t>(edge.vertex1));
  }
  return hash;
}

ConditioningFailure make_failure(const RawSurfaceCellInput &raw,
                                 const ConditioningPolicy &policy,
                                 const ConditioningFailureCode code,
                                 const ConditioningFailureClass classification,
                                 std::string locus, std::string evidence) {
  ConditioningFailure failure;
  failure.code = code;
  failure.classification = classification;
  failure.locus = std::move(locus);
  failure.evidence = std::move(evidence);
  failure.policyId = policy.id;
  failure.rawInputDigest = raw_digest_impl(raw);
  return failure;
}

EInt power_of_two(const int exponent) {
  EInt result(1);
  EInt two(2);
  for (int i = 0; i < exponent; ++i) result *= two;
  return result;
}

struct QuantizedScalar {
  double value = 0.0;
  bool changed = false;
};

std::optional<QuantizedScalar> quantize_dyadic(const double input,
                                                const ConditioningPolicy &policy) {
  const auto exact = Rational::from_double_exact(input);
  if (!exact || policy.latticeExponent < 0 || policy.latticeExponent > 52) {
    return std::nullopt;
  }
  const EInt scale = power_of_two(policy.latticeExponent);
  EInt numerator = exact->exact_numerator();
  const EInt denominator = exact->exact_denominator();
  const bool negative = numerator < EInt(0);
  if (negative) numerator = -numerator;
  const EInt scaled = numerator * scale;
  EInt quotient = scaled / denominator;
  const EInt remainder = scaled % denominator;
  const EInt twiceRemainder = remainder * EInt(2);
  if (twiceRemainder > denominator ||
      (twiceRemainder == denominator && (quotient % EInt(2)) != EInt(0))) {
    quotient += EInt(1);
  }
  if (negative) quotient = -quotient;
  const EInt limit(static_cast<long long>(policy.maxAbsLatticeInteger));
  if (quotient < -limit || quotient > limit) return std::nullopt;
  const long long latticeInteger = quotient.convert();
  const double output =
      std::ldexp(static_cast<double>(latticeInteger), -policy.latticeExponent);
  if (!std::isfinite(output)) return std::nullopt;
  return QuantizedScalar{output,
                         std::bit_cast<std::uint64_t>(output) !=
                             std::bit_cast<std::uint64_t>(input)};
}

bool finite_matrix(const Eigen::MatrixXd &matrix) {
  for (Eigen::Index r = 0; r < matrix.rows(); ++r) {
    for (Eigen::Index c = 0; c < matrix.cols(); ++c) {
      if (!std::isfinite(matrix(r, c))) return false;
    }
  }
  return true;
}

bool policy_representable(const ConditioningPolicy &policy) {
  if (policy.id.empty()) return false;
  if ((policy.quantizeGeometry || policy.quantizeField) &&
      (policy.latticeExponent < 0 || policy.latticeExponent > 52 ||
       policy.maxAbsLatticeInteger == 0U ||
       policy.maxAbsLatticeInteger > ((std::uint64_t{1} << 52U) - 1U))) {
    return false;
  }
  if (policy.refuseSlivers &&
      (policy.sliverRatioNumerator < 0 || policy.sliverRatioDenominator <= 0)) {
    return false;
  }
  if (policy.mergeExactDuplicates && !policy.quantizeGeometry) return false;
  return true;
}

using ExactPoint = std::array<Rational, 3>;

std::optional<ExactPoint> exact_point(const Eigen::MatrixXd &vertices,
                                      const int vertex) {
  if (vertex < 0 || vertex >= vertices.rows() || vertices.cols() != 3) {
    return std::nullopt;
  }
  ExactPoint point;
  for (int c = 0; c < 3; ++c) {
    auto value = Rational::from_double_exact(vertices(vertex, c));
    if (!value) return std::nullopt;
    point[static_cast<std::size_t>(c)] = *value;
  }
  return point;
}

ExactPoint subtract(const ExactPoint &a, const ExactPoint &b) {
  return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

ExactPoint cross(const ExactPoint &a, const ExactPoint &b) {
  return {a[1] * b[2] - a[2] * b[1],
          a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}

Rational norm_squared(const ExactPoint &a) {
  return a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
}

struct FaceShapeFacts {
  bool degenerate = false;
  bool sliver = false;
};

std::optional<FaceShapeFacts>
face_shape_facts(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                 const int face, const ConditioningPolicy &policy) {
  if (face < 0 || face >= faces.rows()) return std::nullopt;
  auto p0 = exact_point(vertices, faces(face, 0));
  auto p1 = exact_point(vertices, faces(face, 1));
  auto p2 = exact_point(vertices, faces(face, 2));
  if (!p0 || !p1 || !p2) return std::nullopt;
  const ExactPoint e01 = subtract(*p1, *p0);
  const ExactPoint e02 = subtract(*p2, *p0);
  const ExactPoint e12 = subtract(*p2, *p1);
  const Rational crossSq = norm_squared(cross(e01, e02));
  FaceShapeFacts facts;
  facts.degenerate = crossSq.is_zero();
  if (policy.refuseSlivers && !facts.degenerate) {
    Rational longest = norm_squared(e01);
    const Rational e02Sq = norm_squared(e02);
    const Rational e12Sq = norm_squared(e12);
    if (e02Sq > longest) longest = e02Sq;
    if (e12Sq > longest) longest = e12Sq;
    const auto num = Rational::from_integer(policy.sliverRatioNumerator);
    const auto den = Rational::from_integer(policy.sliverRatioDenominator);
    facts.sliver = crossSq * den < (longest * longest) * num;
  }
  return facts;
}

std::vector<std::set<int>> vertex_neighbors(const Eigen::MatrixXi &faces,
                                            const int vertexCount) {
  std::vector<std::set<int>> neighbors(static_cast<std::size_t>(vertexCount));
  for (Eigen::Index f = 0; f < faces.rows(); ++f) {
    for (int i = 0; i < 3; ++i) {
      const int a = faces(f, i);
      const int b = faces(f, (i + 1) % 3);
      neighbors[static_cast<std::size_t>(a)].insert(b);
      neighbors[static_cast<std::size_t>(b)].insert(a);
    }
  }
  return neighbors;
}

std::vector<int> vertex_components(const std::vector<std::set<int>> &neighbors) {
  std::vector<int> component(neighbors.size(), -1);
  int next = 0;
  for (std::size_t seed = 0; seed < neighbors.size(); ++seed) {
    if (component[seed] >= 0) continue;
    std::queue<int> queue;
    queue.push(static_cast<int>(seed));
    component[seed] = next;
    while (!queue.empty()) {
      const int current = queue.front();
      queue.pop();
      for (const int neighbor : neighbors[static_cast<std::size_t>(current)]) {
        if (component[static_cast<std::size_t>(neighbor)] < 0) {
          component[static_cast<std::size_t>(neighbor)] = next;
          queue.push(neighbor);
        }
      }
    }
    ++next;
  }
  return component;
}

std::set<int> incident_feature_ids(
    const int vertex, const std::vector<RawConditioningFeatureEdge> &features) {
  std::set<int> ids;
  for (std::size_t i = 0; i < features.size(); ++i) {
    if (features[i].vertex0 == vertex || features[i].vertex1 == vertex) {
      ids.insert(static_cast<int>(i));
    }
  }
  return ids;
}

bool feature_edge_exists(const Eigen::MatrixXi &faces, int a, int b) {
  if (a > b) std::swap(a, b);
  for (Eigen::Index f = 0; f < faces.rows(); ++f) {
    for (int i = 0; i < 3; ++i) {
      int x = faces(f, i);
      int y = faces(f, (i + 1) % 3);
      if (x > y) std::swap(x, y);
      if (x == a && y == b) return true;
    }
  }
  return false;
}

bool exact_vector_is_zero(const Eigen::MatrixXd &field, const int face,
                          const int branch) {
  for (int c = 0; c < 3; ++c) {
    const auto value = Rational::from_double_exact(field(face, 3 * branch + c));
    if (!value || !value->is_zero()) return false;
  }
  return true;
}

std::optional<bool> exact_vectors_are_opposites(const Eigen::MatrixXd &field,
                                                const int face,
                                                const int first,
                                                const int second) {
  const Rational zero = Rational::from_integer(0);
  for (int c = 0; c < 3; ++c) {
    auto a = Rational::from_double_exact(field(face, 3 * first + c));
    auto b = Rational::from_double_exact(field(face, 3 * second + c));
    if (!a || !b) return std::nullopt;
    if (*a + *b != zero) return false;
  }
  return true;
}

std::tuple<Rational, Rational, Rational> exact_branch_key(
    const Eigen::MatrixXd &field, const int face, const int branch) {
  return {*Rational::from_double_exact(field(face, 3 * branch + 0)),
          *Rational::from_double_exact(field(face, 3 * branch + 1)),
          *Rational::from_double_exact(field(face, 3 * branch + 2))};
}

std::optional<std::array<int, 4>> canonical_branch_permutation(
    const Eigen::MatrixXd &field, const int face) {
  for (int branch = 0; branch < 4; ++branch) {
    if (exact_vector_is_zero(field, face, branch)) return std::nullopt;
    const auto opposite = exact_vectors_are_opposites(
        field, face, branch, (branch + 2) % 4);
    if (!opposite || !*opposite) return std::nullopt;
  }
  int start = 0;
  auto best = exact_branch_key(field, face, 0);
  for (int branch = 1; branch < 4; ++branch) {
    const auto key = exact_branch_key(field, face, branch);
    if (key == best) return std::nullopt;
    if (key < best) {
      best = key;
      start = branch;
    }
  }
  return std::array<int, 4>{start, (start + 1) % 4, (start + 2) % 4,
                            (start + 3) % 4};
}

struct BasicValidation {
  std::optional<ConditioningFailure> failure;
};

BasicValidation validate_raw_basics(const RawSurfaceCellInput &raw,
                                    const ConditioningPolicy &policy) {
  if (!policy_representable(policy)) {
    return {make_failure(raw, policy,
                         ConditioningFailureCode::ConditioningPolicyUnrepresentable,
                         ConditioningFailureClass::FatalInadmissible, "policy",
                         "frozen dyadic policy parameters are not representable")};
  }
  if (raw.vertices.cols() != 3 || raw.faces.cols() != 3 ||
      raw.rawCrossField.rows() != raw.faces.rows() ||
      raw.rawCrossField.cols() != 12) {
    return {make_failure(raw, policy, ConditioningFailureCode::FieldShapeInvalid,
                         ConditioningFailureClass::FatalInadmissible, "shape",
                         "expected Vx3, Fx3 and Fx12 raw field")};
  }
  if (!finite_matrix(raw.vertices) || !finite_matrix(raw.rawCrossField)) {
    return {make_failure(raw, policy, ConditioningFailureCode::NonFiniteInput,
                         ConditioningFailureClass::FatalInadmissible,
                         "binary64", "nonfinite source or field value")};
  }
  for (Eigen::Index f = 0; f < raw.faces.rows(); ++f) {
    const int a = raw.faces(f, 0);
    const int b = raw.faces(f, 1);
    const int c = raw.faces(f, 2);
    if (a < 0 || b < 0 || c < 0 || a >= raw.vertices.rows() ||
        b >= raw.vertices.rows() || c >= raw.vertices.rows() || a == b ||
        b == c || c == a) {
      return {make_failure(raw, policy,
                           ConditioningFailureCode::InvalidSourceConnectivity,
                           ConditioningFailureClass::FatalInadmissible,
                           "face:" + std::to_string(f),
                           "invalid or repeated source vertex index")};
    }
  }
  for (std::size_t i = 0; i < raw.hardFeatures.size(); ++i) {
    const auto &edge = raw.hardFeatures[i];
    if (edge.vertex0 < 0 || edge.vertex1 < 0 ||
        edge.vertex0 >= raw.vertices.rows() || edge.vertex1 >= raw.vertices.rows() ||
        edge.vertex0 == edge.vertex1 ||
        !feature_edge_exists(raw.faces, edge.vertex0, edge.vertex1)) {
      return {make_failure(raw, policy,
                           ConditioningFailureCode::FeatureCorrespondenceConflict,
                           ConditioningFailureClass::FatalInadmissible,
                           "feature:" + std::to_string(i),
                           "hard feature is not a valid source edge")};
    }
  }
  return {};
}

std::optional<ConditioningFailure> validate_exact_faces(
    const RawSurfaceCellInput &raw, const ConditioningPolicy &policy,
    const Eigen::MatrixXd &vertices) {
  for (Eigen::Index f = 0; f < raw.faces.rows(); ++f) {
    const auto facts = face_shape_facts(vertices, raw.faces, static_cast<int>(f), policy);
    if (!facts) {
      return make_failure(raw, policy, ConditioningFailureCode::ExactDegenerateFace,
                          ConditioningFailureClass::FatalInadmissible,
                          "face:" + std::to_string(f),
                          "exact face predicate could not be derived") ;
    }
    if (facts->degenerate) {
      return make_failure(raw, policy, ConditioningFailureCode::ExactDegenerateFace,
                          ConditioningFailureClass::FatalInadmissible,
                          "face:" + std::to_string(f),
                          "exact cross-product squared is zero");
    }
    if (facts->sliver) {
      return make_failure(raw, policy, ConditioningFailureCode::SliverPolicyExceeded,
                          ConditioningFailureClass::RegularizableDegeneracy,
                          "face:" + std::to_string(f),
                          "exact scale-invariant cross-square ratio is below policy") ;
    }
  }
  return std::nullopt;
}

std::vector<std::uint64_t> scalar_bits(const double value) {
  return {std::bit_cast<std::uint64_t>(value)};
}

} // namespace

ConditioningPolicy ConditioningPolicy::production_identity() {
  return ConditioningPolicy{};
}

std::string conditioning_failure_code_name(const ConditioningFailureCode code) {
  switch (code) {
  case ConditioningFailureCode::NonFiniteInput: return "NonFiniteInput";
  case ConditioningFailureCode::InvalidSourceConnectivity: return "InvalidSourceConnectivity";
  case ConditioningFailureCode::ExactDegenerateFace: return "ExactDegenerateFace";
  case ConditioningFailureCode::SliverPolicyExceeded: return "SliverPolicyExceeded";
  case ConditioningFailureCode::FeatureCorrespondenceConflict: return "FeatureCorrespondenceConflict";
  case ConditioningFailureCode::FieldShapeInvalid: return "FieldShapeInvalid";
  case ConditioningFailureCode::FieldTransportInadmissible: return "FieldTransportInadmissible";
  case ConditioningFailureCode::ConditioningPolicyUnrepresentable: return "ConditioningPolicyUnrepresentable";
  case ConditioningFailureCode::CertificateMismatch: return "CertificateMismatch";
  }
  return "Unknown";
}

std::uint64_t conditioning_raw_input_digest(const RawSurfaceCellInput &raw) {
  return raw_digest_impl(raw);
}

std::uint64_t conditioning_semantic_digest(
    const ConditionedSourceProduct &product, const ConditioningPolicy &policy) {
  return semantic_digest_impl(product, policy);
}

ConditioningResult condition_surface_cell_input(const RawSurfaceCellInput &raw,
                                                const ConditioningPolicy &policy) {
  if (const BasicValidation basic = validate_raw_basics(raw, policy);
      basic.failure.has_value()) {
    return geometry::Rejected<ConditioningFailure>{*basic.failure};
  }

  ConditionedSourceProduct product;
  product.vertices = raw.vertices;
  product.faces = raw.faces;
  product.rawCrossField = raw.rawCrossField;
  product.hardFeatures = raw.hardFeatures;
  product.rawInputDigest = raw_digest_impl(raw);
  product.policyId = policy.id;
  product.certificate.policyId = policy.id;
  product.certificate.rawInputDigest = product.rawInputDigest;

  if (policy.quantizeGeometry) {
    for (Eigen::Index r = 0; r < product.vertices.rows(); ++r) {
      for (Eigen::Index c = 0; c < 3; ++c) {
        const double before = product.vertices(r, c);
        const auto quantized = quantize_dyadic(before, policy);
        if (!quantized) {
          return geometry::Rejected<ConditioningFailure>{make_failure(
              raw, policy, ConditioningFailureCode::ConditioningPolicyUnrepresentable,
              ConditioningFailureClass::FatalInadmissible,
              "vertex:" + std::to_string(r) + ":" + std::to_string(c),
              "dyadic lattice integer exceeds frozen exact range")};
        }
        product.vertices(r, c) = quantized->value;
        if (quantized->changed) {
          product.certificate.operations.push_back(ConditioningOperationRecord{
              ConditioningOperationKind::DyadicQuantization,
              "vertex:" + std::to_string(r) + ":" + std::to_string(c),
              scalar_bits(before), scalar_bits(quantized->value),
              {static_cast<int>(r)}, {static_cast<int>(r)}});
        }
      }
    }
  }

  if (policy.quantizeField) {
    for (Eigen::Index r = 0; r < product.rawCrossField.rows(); ++r) {
      for (Eigen::Index c = 0; c < product.rawCrossField.cols(); ++c) {
        const double before = product.rawCrossField(r, c);
        const auto quantized = quantize_dyadic(before, policy);
        if (!quantized) {
          return geometry::Rejected<ConditioningFailure>{make_failure(
              raw, policy, ConditioningFailureCode::ConditioningPolicyUnrepresentable,
              ConditioningFailureClass::FatalInadmissible,
              "field:" + std::to_string(r) + ":" + std::to_string(c),
              "dyadic field integer exceeds frozen exact range")};
        }
        product.rawCrossField(r, c) = quantized->value;
        if (quantized->changed) {
          product.certificate.operations.push_back(ConditioningOperationRecord{
              ConditioningOperationKind::DyadicQuantization,
              "field:" + std::to_string(r) + ":" + std::to_string(c),
              scalar_bits(before), scalar_bits(quantized->value),
              {static_cast<int>(r)}, {static_cast<int>(r)}});
        }
      }
    }
  }

  if (auto faceFailure = validate_exact_faces(raw, policy, product.vertices)) {
    return geometry::Rejected<ConditioningFailure>{*faceFailure};
  }

  // C4 is deliberately discrete: exact opposite-pair authority plus a cyclic
  // Z4 shift only. It never perturbs branch values.
  std::vector<std::array<int, 4>> branchPermutations(
      static_cast<std::size_t>(product.rawCrossField.rows()),
      std::array<int, 4>{0, 1, 2, 3});
  for (Eigen::Index face = 0; face < product.rawCrossField.rows(); ++face) {
    for (int branch = 0; branch < 4; ++branch) {
      if (exact_vector_is_zero(product.rawCrossField, static_cast<int>(face), branch)) {
        return geometry::Rejected<ConditioningFailure>{make_failure(
            raw, policy, ConditioningFailureCode::FieldShapeInvalid,
            ConditioningFailureClass::FatalInadmissible,
            "field:" + std::to_string(face) + ":branch:" + std::to_string(branch),
            "raw cross-field branch is exactly zero")};
      }
    }
    if (policy.canonicalizeFieldBranches) {
      const auto permutation = canonical_branch_permutation(
          product.rawCrossField, static_cast<int>(face));
      if (!permutation) {
        return geometry::Rejected<ConditioningFailure>{make_failure(
            raw, policy, ConditioningFailureCode::FieldTransportInadmissible,
            ConditioningFailureClass::FatalInadmissible,
            "field:" + std::to_string(face),
            "exact Z4 opposite-pair authority is contradictory or non-unique")};
      }
      branchPermutations[static_cast<std::size_t>(face)] = *permutation;
      if (*permutation != std::array<int, 4>{0, 1, 2, 3}) {
        Eigen::Matrix<double, 1, 12> reordered;
        std::vector<std::uint64_t> beforeBits;
        std::vector<std::uint64_t> afterBits;
        beforeBits.reserve(12);
        afterBits.reserve(12);
        for (int c = 0; c < 12; ++c) {
          beforeBits.push_back(std::bit_cast<std::uint64_t>(product.rawCrossField(face, c)));
        }
        for (int outBranch = 0; outBranch < 4; ++outBranch) {
          const int inBranch = (*permutation)[static_cast<std::size_t>(outBranch)];
          reordered.segment<3>(3 * outBranch) =
              product.rawCrossField.block<1, 3>(face, 3 * inBranch);
        }
        product.rawCrossField.row(face) = reordered;
        for (int c = 0; c < 12; ++c) {
          afterBits.push_back(std::bit_cast<std::uint64_t>(product.rawCrossField(face, c)));
        }
        product.certificate.operations.push_back(ConditioningOperationRecord{
            ConditioningOperationKind::Z4FieldReindex,
            "field:" + std::to_string(face), std::move(beforeBits),
            std::move(afterBits), {static_cast<int>(face)},
            {static_cast<int>(face)}});
      }
    }
  }

  std::vector<int> rawToConditioned(static_cast<std::size_t>(raw.vertices.rows()));
  for (int v = 0; v < raw.vertices.rows(); ++v) rawToConditioned[static_cast<std::size_t>(v)] = v;

  if (policy.mergeExactDuplicates && product.vertices.rows() > 0) {
    using Key = std::array<std::uint64_t, 3>;
    std::map<Key, std::vector<int>> groups;
    for (int v = 0; v < product.vertices.rows(); ++v) {
      groups[{std::bit_cast<std::uint64_t>(product.vertices(v, 0)),
              std::bit_cast<std::uint64_t>(product.vertices(v, 1)),
              std::bit_cast<std::uint64_t>(product.vertices(v, 2))}]
          .push_back(v);
    }
    const auto neighbors = vertex_neighbors(raw.faces, raw.vertices.rows());
    const auto components = vertex_components(neighbors);
    std::vector<int> owner(static_cast<std::size_t>(raw.vertices.rows()));
    for (int v = 0; v < raw.vertices.rows(); ++v) owner[static_cast<std::size_t>(v)] = v;

    for (const auto &[key, vertices] : groups) {
      (void)key;
      if (vertices.size() < 2U) continue;
      const int canonical = *std::min_element(vertices.begin(), vertices.end());
      for (const int v : vertices) {
        if (components[static_cast<std::size_t>(v)] !=
            components[static_cast<std::size_t>(canonical)]) {
          return geometry::Rejected<ConditioningFailure>{make_failure(
              raw, policy, ConditioningFailureCode::FeatureCorrespondenceConflict,
              ConditioningFailureClass::FatalInadmissible,
              "merge:" + std::to_string(canonical) + ":" + std::to_string(v),
              "exact-equality merge would conflate disconnected source components")};
        }
        if (v != canonical) {
          std::vector<int> common;
          std::set_intersection(neighbors[static_cast<std::size_t>(canonical)].begin(),
                                neighbors[static_cast<std::size_t>(canonical)].end(),
                                neighbors[static_cast<std::size_t>(v)].begin(),
                                neighbors[static_cast<std::size_t>(v)].end(),
                                std::back_inserter(common));
          if (common.empty() ||
              incident_feature_ids(v, raw.hardFeatures) !=
                  incident_feature_ids(canonical, raw.hardFeatures)) {
            return geometry::Rejected<ConditioningFailure>{make_failure(
                raw, policy, ConditioningFailureCode::FeatureCorrespondenceConflict,
                ConditioningFailureClass::FatalInadmissible,
                "merge:" + std::to_string(canonical) + ":" + std::to_string(v),
                "exact-equality merge lacks common fan or feature ownership")};
          }
        }
        owner[static_cast<std::size_t>(v)] = canonical;
      }
    }

    std::vector<int> owners = owner;
    std::sort(owners.begin(), owners.end());
    owners.erase(std::unique(owners.begin(), owners.end()), owners.end());
    std::map<int, int> compact;
    for (std::size_t i = 0; i < owners.size(); ++i) compact[owners[i]] = static_cast<int>(i);
    for (int v = 0; v < raw.vertices.rows(); ++v) {
      rawToConditioned[static_cast<std::size_t>(v)] = compact.at(owner[static_cast<std::size_t>(v)]);
    }

    Eigen::MatrixXd compactVertices(static_cast<Eigen::Index>(owners.size()), 3);
    for (std::size_t i = 0; i < owners.size(); ++i) compactVertices.row(static_cast<Eigen::Index>(i)) = product.vertices.row(owners[i]);
    Eigen::MatrixXi remappedFaces = raw.faces;
    std::set<std::array<int, 3>> faceKeys;
    for (Eigen::Index f = 0; f < remappedFaces.rows(); ++f) {
      for (int c = 0; c < 3; ++c) {
        remappedFaces(f, c) = rawToConditioned[static_cast<std::size_t>(raw.faces(f, c))];
      }
      if (remappedFaces(f, 0) == remappedFaces(f, 1) ||
          remappedFaces(f, 1) == remappedFaces(f, 2) ||
          remappedFaces(f, 2) == remappedFaces(f, 0)) {
        return geometry::Rejected<ConditioningFailure>{make_failure(
            raw, policy, ConditioningFailureCode::InvalidSourceConnectivity,
            ConditioningFailureClass::FatalInadmissible,
            "face:" + std::to_string(f),
            "exact merge would collapse a source face")};
      }
      std::array<int, 3> faceKey{remappedFaces(f, 0), remappedFaces(f, 1), remappedFaces(f, 2)};
      std::sort(faceKey.begin(), faceKey.end());
      if (!faceKeys.insert(faceKey).second) {
        return geometry::Rejected<ConditioningFailure>{make_failure(
            raw, policy, ConditioningFailureCode::InvalidSourceConnectivity,
            ConditioningFailureClass::FatalInadmissible,
            "face:" + std::to_string(f),
            "exact merge would create duplicate source-face incidence")};
      }
    }

    std::vector<RawConditioningFeatureEdge> remappedFeatures;
    std::set<std::pair<int, int>> featureKeys;
    remappedFeatures.reserve(raw.hardFeatures.size());
    for (std::size_t i = 0; i < raw.hardFeatures.size(); ++i) {
      int a = rawToConditioned[static_cast<std::size_t>(raw.hardFeatures[i].vertex0)];
      int b = rawToConditioned[static_cast<std::size_t>(raw.hardFeatures[i].vertex1)];
      if (a == b) {
        return geometry::Rejected<ConditioningFailure>{make_failure(
            raw, policy, ConditioningFailureCode::FeatureCorrespondenceConflict,
            ConditioningFailureClass::FatalInadmissible,
            "feature:" + std::to_string(i),
            "exact merge would collapse a hard feature")};
      }
      const auto key = std::minmax(a, b);
      if (!featureKeys.emplace(key.first, key.second).second) {
        return geometry::Rejected<ConditioningFailure>{make_failure(
            raw, policy, ConditioningFailureCode::FeatureCorrespondenceConflict,
            ConditioningFailureClass::FatalInadmissible,
            "feature:" + std::to_string(i),
            "exact merge would multiply-own a conditioned hard feature")};
      }
      remappedFeatures.push_back({a, b});
    }

    for (const auto &[key, vertices] : groups) {
      (void)key;
      if (vertices.size() < 2U) continue;
      const int canonical = *std::min_element(vertices.begin(), vertices.end());
      product.certificate.operations.push_back(ConditioningOperationRecord{
          ConditioningOperationKind::ExactVertexMerge,
          "vertex-owner:" + std::to_string(canonical), {}, {}, vertices,
          {compact.at(canonical)}});
    }
    product.vertices = std::move(compactVertices);
    product.faces = std::move(remappedFaces);
    product.hardFeatures = std::move(remappedFeatures);
  }

  product.certificate.vertices.reserve(static_cast<std::size_t>(raw.vertices.rows()));
  for (int v = 0; v < raw.vertices.rows(); ++v) {
    product.certificate.vertices.push_back({v, rawToConditioned[static_cast<std::size_t>(v)]});
  }
  product.certificate.faces.reserve(static_cast<std::size_t>(raw.faces.rows()));
  product.certificate.fields.reserve(static_cast<std::size_t>(raw.faces.rows()));
  for (int f = 0; f < raw.faces.rows(); ++f) {
    product.certificate.faces.push_back({f, f});
    product.certificate.fields.push_back({f, f, branchPermutations[static_cast<std::size_t>(f)]});
  }
  product.certificate.features.reserve(raw.hardFeatures.size());
  for (std::size_t i = 0; i < raw.hardFeatures.size(); ++i) {
    product.certificate.features.push_back(
        {static_cast<int>(i), product.hardFeatures[i]});
  }

  product.conditionedSemanticDigest = semantic_digest_impl(product, policy);
  product.certificate.conditionedSemanticDigest = product.conditionedSemanticDigest;

  if (auto validation = validate_conditioned_source_product(raw, policy, product)) {
    return geometry::Rejected<ConditioningFailure>{*validation};
  }
  return geometry::Produced<ConditionedSourceProduct>{std::move(product)};
}

std::optional<ConditioningFailure> validate_conditioned_source_product(
    const RawSurfaceCellInput &raw, const ConditioningPolicy &policy,
    const ConditionedSourceProduct &product) {
  if (const BasicValidation basic = validate_raw_basics(raw, policy);
      basic.failure.has_value()) {
    return basic.failure;
  }
  const std::uint64_t rawDigest = raw_digest_impl(raw);
  if (product.policyId != policy.id || product.certificate.policyId != policy.id ||
      product.rawInputDigest != rawDigest || product.certificate.rawInputDigest != rawDigest) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible, "digest",
                        "raw digest or policy binding mismatch") ;
  }
  if (product.faces.rows() != raw.faces.rows() || product.faces.cols() != 3 ||
      product.rawCrossField.rows() != raw.rawCrossField.rows() ||
      product.rawCrossField.cols() != raw.rawCrossField.cols() ||
      product.certificate.vertices.size() != static_cast<std::size_t>(raw.vertices.rows()) ||
      product.certificate.faces.size() != static_cast<std::size_t>(raw.faces.rows()) ||
      product.certificate.fields.size() != static_cast<std::size_t>(raw.faces.rows()) ||
      product.certificate.features.size() != raw.hardFeatures.size()) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible, "cardinality",
                        "certificate coverage cardinality mismatch") ;
  }

  std::vector<int> rawToConditioned(static_cast<std::size_t>(raw.vertices.rows()), -1);
  for (std::size_t i = 0; i < product.certificate.vertices.size(); ++i) {
    const auto &entry = product.certificate.vertices[i];
    if (entry.rawVertex != static_cast<int>(i) || entry.conditionedVertex < 0 ||
        entry.conditionedVertex >= product.vertices.rows()) {
      return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                          ConditioningFailureClass::FatalInadmissible,
                          "vertex-correspondence", "vertex ownership is missing or noncanonical");
    }
    rawToConditioned[i] = entry.conditionedVertex;
  }

  for (std::size_t i = 0; i < product.certificate.faces.size(); ++i) {
    const auto &entry = product.certificate.faces[i];
    if (entry.rawFace != static_cast<int>(i) || entry.conditionedFace != static_cast<int>(i)) {
      return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                          ConditioningFailureClass::FatalInadmissible,
                          "face-correspondence", "face identity is not one-to-one order preserving");
    }
    for (int c = 0; c < 3; ++c) {
      if (product.faces(static_cast<Eigen::Index>(i), c) !=
          rawToConditioned[static_cast<std::size_t>(raw.faces(static_cast<Eigen::Index>(i), c))]) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "face-correspondence", "face vertex mapping differs from certificate") ;
      }
    }
  }

  // Recompute exact scalar quantization independently from certificate logs.
  Eigen::MatrixXd expectedVertices = raw.vertices;
  Eigen::MatrixXd expectedField = raw.rawCrossField;
  if (policy.quantizeGeometry) {
    for (Eigen::Index r = 0; r < expectedVertices.rows(); ++r) {
      for (Eigen::Index c = 0; c < 3; ++c) {
        auto q = quantize_dyadic(expectedVertices(r, c), policy);
        if (!q) return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                                    ConditioningFailureClass::FatalInadmissible,
                                    "quantization", "validator could not derive geometry lattice value");
        expectedVertices(r, c) = q->value;
      }
    }
  }
  if (policy.quantizeField) {
    for (Eigen::Index r = 0; r < expectedField.rows(); ++r) {
      for (Eigen::Index c = 0; c < expectedField.cols(); ++c) {
        auto q = quantize_dyadic(expectedField(r, c), policy);
        if (!q) return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                                    ConditioningFailureClass::FatalInadmissible,
                                    "quantization", "validator could not derive field lattice value");
        expectedField(r, c) = q->value;
      }
    }
  }
  if (const auto faceFailure = validate_exact_faces(raw, policy, expectedVertices)) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible,
                        "face-authority",
                        "produced certificate exists for independently refused exact face");
  }
  for (int face = 0; face < expectedField.rows(); ++face) {
    for (int branch = 0; branch < 4; ++branch) {
      if (exact_vector_is_zero(expectedField, face, branch)) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "field-authority",
                            "produced certificate exists for an exact-zero conditioned branch");
      }
    }
  }

  // Independently derive the only legal C2 ownership map. Exact equality is
  // necessary but not sufficient: disconnected components, missing common
  // fan support, feature changes, collapsed faces and duplicate incidence are
  // all refusal conditions rather than merge authority.
  std::vector<int> expectedRawToConditioned(static_cast<std::size_t>(raw.vertices.rows()));
  for (int v = 0; v < raw.vertices.rows(); ++v)
    expectedRawToConditioned[static_cast<std::size_t>(v)] = v;
  std::vector<std::vector<int>> expectedMergeGroups;
  if (policy.mergeExactDuplicates && expectedVertices.rows() > 0) {
    using Key = std::array<std::uint64_t, 3>;
    std::map<Key, std::vector<int>> groups;
    for (int v = 0; v < expectedVertices.rows(); ++v) {
      groups[{std::bit_cast<std::uint64_t>(expectedVertices(v, 0)),
              std::bit_cast<std::uint64_t>(expectedVertices(v, 1)),
              std::bit_cast<std::uint64_t>(expectedVertices(v, 2))}]
          .push_back(v);
    }
    const auto neighbors = vertex_neighbors(raw.faces, raw.vertices.rows());
    const auto components = vertex_components(neighbors);
    std::vector<int> owner(static_cast<std::size_t>(raw.vertices.rows()));
    for (int v = 0; v < raw.vertices.rows(); ++v) owner[static_cast<std::size_t>(v)] = v;
    for (const auto &[key, vertices] : groups) {
      (void)key;
      if (vertices.size() < 2U) continue;
      const int canonical = *std::min_element(vertices.begin(), vertices.end());
      for (const int v : vertices) {
        if (components[static_cast<std::size_t>(v)] !=
            components[static_cast<std::size_t>(canonical)]) {
          return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                              ConditioningFailureClass::FatalInadmissible,
                              "merge-authority",
                              "produced certificate exists for disconnected exact-equality merge");
        }
        if (v != canonical) {
          std::vector<int> common;
          std::set_intersection(neighbors[static_cast<std::size_t>(canonical)].begin(),
                                neighbors[static_cast<std::size_t>(canonical)].end(),
                                neighbors[static_cast<std::size_t>(v)].begin(),
                                neighbors[static_cast<std::size_t>(v)].end(),
                                std::back_inserter(common));
          if (common.empty() ||
              incident_feature_ids(v, raw.hardFeatures) !=
                  incident_feature_ids(canonical, raw.hardFeatures)) {
            return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                                ConditioningFailureClass::FatalInadmissible,
                                "merge-authority",
                                "produced certificate exists for unsafe fan or feature merge");
          }
        }
        owner[static_cast<std::size_t>(v)] = canonical;
      }
      expectedMergeGroups.push_back(vertices);
    }
    std::vector<int> owners = owner;
    std::sort(owners.begin(), owners.end());
    owners.erase(std::unique(owners.begin(), owners.end()), owners.end());
    std::map<int, int> compact;
    for (std::size_t i = 0; i < owners.size(); ++i) compact[owners[i]] = static_cast<int>(i);
    for (int v = 0; v < raw.vertices.rows(); ++v)
      expectedRawToConditioned[static_cast<std::size_t>(v)] =
          compact.at(owner[static_cast<std::size_t>(v)]);
    if (product.vertices.rows() != static_cast<Eigen::Index>(owners.size())) {
      return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                          ConditioningFailureClass::FatalInadmissible,
                          "merge-authority", "conditioned vertex cardinality differs from exact merge plan");
    }
    std::set<std::array<int, 3>> faceKeys;
    for (Eigen::Index f = 0; f < raw.faces.rows(); ++f) {
      std::array<int, 3> faceKey{
          expectedRawToConditioned[static_cast<std::size_t>(raw.faces(f, 0))],
          expectedRawToConditioned[static_cast<std::size_t>(raw.faces(f, 1))],
          expectedRawToConditioned[static_cast<std::size_t>(raw.faces(f, 2))]};
      if (faceKey[0] == faceKey[1] || faceKey[1] == faceKey[2] || faceKey[2] == faceKey[0]) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "merge-authority", "produced certificate exists for face-collapsing merge");
      }
      std::sort(faceKey.begin(), faceKey.end());
      if (!faceKeys.insert(faceKey).second) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "merge-authority", "produced certificate exists for duplicate-face merge");
      }
    }
    std::set<std::pair<int, int>> featureKeys;
    for (const auto &feature : raw.hardFeatures) {
      const int a = expectedRawToConditioned[static_cast<std::size_t>(feature.vertex0)];
      const int b = expectedRawToConditioned[static_cast<std::size_t>(feature.vertex1)];
      if (a == b) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "merge-authority", "produced certificate exists for feature-collapsing merge");
      }
      const auto key = std::minmax(a, b);
      if (!featureKeys.emplace(key.first, key.second).second) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "merge-authority", "produced certificate exists for multiply-owned feature merge");
      }
    }
  } else if (product.vertices.rows() != raw.vertices.rows()) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible,
                        "merge-authority", "vertex cardinality changed when C2 is disabled");
  }
  if (rawToConditioned != expectedRawToConditioned) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible,
                        "vertex-correspondence", "certified owner map differs from independently derived C2 map");
  }

  std::vector<std::array<int, 4>> expectedPermutations(
      static_cast<std::size_t>(raw.faces.rows()), std::array<int, 4>{0, 1, 2, 3});
  for (int f = 0; f < raw.faces.rows(); ++f) {
    const auto &entry = product.certificate.fields[static_cast<std::size_t>(f)];
    if (entry.rawFace != f || entry.conditionedFace != f) {
      return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                          ConditioningFailureClass::FatalInadmissible,
                          "field-correspondence", "field face identity mismatch") ;
    }
    std::array<int, 4> expectedPermutation{0, 1, 2, 3};
    if (policy.canonicalizeFieldBranches) {
      const auto permutation = canonical_branch_permutation(expectedField, f);
      if (!permutation) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "field-correspondence", "validator cannot derive unique Z4 reindex") ;
      }
      expectedPermutation = *permutation;
    }
    expectedPermutations[static_cast<std::size_t>(f)] = expectedPermutation;
    if (entry.branchPermutation != expectedPermutation) {
      return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                          ConditioningFailureClass::FatalInadmissible,
                          "field-correspondence", "recorded Z4 permutation differs from exact derivation") ;
    }
    for (int outBranch = 0; outBranch < 4; ++outBranch) {
      const int inBranch = expectedPermutation[static_cast<std::size_t>(outBranch)];
      for (int c = 0; c < 3; ++c) {
        if (std::bit_cast<std::uint64_t>(product.rawCrossField(f, 3 * outBranch + c)) !=
            std::bit_cast<std::uint64_t>(expectedField(f, 3 * inBranch + c))) {
          return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                              ConditioningFailureClass::FatalInadmissible,
                              "field-correspondence", "conditioned field bits differ from exact policy") ;
        }
      }
    }
  }

  // Every raw vertex's expected quantized coordinates must equal its certified
  // conditioned owner. This validates merges without trusting merge records.
  for (int rawVertex = 0; rawVertex < raw.vertices.rows(); ++rawVertex) {
    const int conditioned = rawToConditioned[static_cast<std::size_t>(rawVertex)];
    for (int c = 0; c < 3; ++c) {
      if (std::bit_cast<std::uint64_t>(expectedVertices(rawVertex, c)) !=
          std::bit_cast<std::uint64_t>(product.vertices(conditioned, c))) {
        return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                            ConditioningFailureClass::FatalInadmissible,
                            "vertex-correspondence", "conditioned owner bits differ from exact policy") ;
      }
    }
  }

  for (std::size_t i = 0; i < raw.hardFeatures.size(); ++i) {
    const RawConditioningFeatureEdge expected{
        rawToConditioned[static_cast<std::size_t>(raw.hardFeatures[i].vertex0)],
        rawToConditioned[static_cast<std::size_t>(raw.hardFeatures[i].vertex1)]};
    const auto &entry = product.certificate.features[i];
    if (entry.rawFeature != static_cast<int>(i) || entry.conditionedEdge != expected ||
        product.hardFeatures[i] != expected) {
      return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                          ConditioningFailureClass::FatalInadmissible,
                          "feature-correspondence", "feature owner mapping differs from certificate") ;
    }
  }

  const std::uint64_t semantic = semantic_digest_impl(product, policy);
  if (product.conditionedSemanticDigest != semantic ||
      product.certificate.conditionedSemanticDigest != semantic) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible, "digest",
                        "conditioned semantic digest mismatch") ;
  }

  // Reconstruct the exact operation log rather than trusting operation counts.
  std::vector<ConditioningOperationRecord> expectedOperations;
  if (policy.quantizeGeometry) {
    for (Eigen::Index r = 0; r < raw.vertices.rows(); ++r) {
      for (Eigen::Index c = 0; c < 3; ++c) {
        if (std::bit_cast<std::uint64_t>(raw.vertices(r, c)) ==
            std::bit_cast<std::uint64_t>(expectedVertices(r, c))) continue;
        expectedOperations.push_back(ConditioningOperationRecord{
            ConditioningOperationKind::DyadicQuantization,
            "vertex:" + std::to_string(r) + ":" + std::to_string(c),
            scalar_bits(raw.vertices(r, c)), scalar_bits(expectedVertices(r, c)),
            {static_cast<int>(r)}, {static_cast<int>(r)}});
      }
    }
  }
  if (policy.quantizeField) {
    for (Eigen::Index r = 0; r < raw.rawCrossField.rows(); ++r) {
      for (Eigen::Index c = 0; c < raw.rawCrossField.cols(); ++c) {
        if (std::bit_cast<std::uint64_t>(raw.rawCrossField(r, c)) ==
            std::bit_cast<std::uint64_t>(expectedField(r, c))) continue;
        expectedOperations.push_back(ConditioningOperationRecord{
            ConditioningOperationKind::DyadicQuantization,
            "field:" + std::to_string(r) + ":" + std::to_string(c),
            scalar_bits(raw.rawCrossField(r, c)), scalar_bits(expectedField(r, c)),
            {static_cast<int>(r)}, {static_cast<int>(r)}});
      }
    }
  }
  for (int f = 0; f < raw.faces.rows(); ++f) {
    const auto permutation = expectedPermutations[static_cast<std::size_t>(f)];
    if (permutation == std::array<int, 4>{0, 1, 2, 3}) continue;
    std::vector<std::uint64_t> beforeBits;
    std::vector<std::uint64_t> afterBits;
    beforeBits.reserve(12);
    afterBits.reserve(12);
    for (int c = 0; c < 12; ++c)
      beforeBits.push_back(std::bit_cast<std::uint64_t>(expectedField(f, c)));
    for (int outBranch = 0; outBranch < 4; ++outBranch) {
      const int inBranch = permutation[static_cast<std::size_t>(outBranch)];
      for (int c = 0; c < 3; ++c)
        afterBits.push_back(std::bit_cast<std::uint64_t>(expectedField(f, 3 * inBranch + c)));
    }
    expectedOperations.push_back(ConditioningOperationRecord{
        ConditioningOperationKind::Z4FieldReindex, "field:" + std::to_string(f),
        std::move(beforeBits), std::move(afterBits), {f}, {f}});
  }
  for (const auto &vertices : expectedMergeGroups) {
    const int canonical = *std::min_element(vertices.begin(), vertices.end());
    expectedOperations.push_back(ConditioningOperationRecord{
        ConditioningOperationKind::ExactVertexMerge,
        "vertex-owner:" + std::to_string(canonical), {}, {}, vertices,
        {expectedRawToConditioned[static_cast<std::size_t>(canonical)]}});
  }
  if (product.certificate.operations != expectedOperations) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible,
                        "operation-log", "operation log differs from exact independent derivation");
  }
  return std::nullopt;
}

std::optional<ConditioningFailure> validate_conditioning_failure(
    const RawSurfaceCellInput &raw, const ConditioningPolicy &policy,
    const ConditioningFailure &failure) {
  if (failure.policyId != policy.id || failure.rawInputDigest != raw_digest_impl(raw)) {
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible,
                        "failure-binding", "failure policy or raw digest mismatch") ;
  }
  const auto basics = validate_raw_basics(raw, policy);
  if (basics.failure.has_value()) {
    if (basics.failure->code == failure.code) return std::nullopt;
    return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                        ConditioningFailureClass::FatalInadmissible,
                        "failure-code", "typed refusal does not match independently derived basic failure") ;
  }

  // Recompute the exact operation-sensitive refusal classes without trusting
  // the producer's locus/evidence strings.
  Eigen::MatrixXd vertices = raw.vertices;
  if (policy.quantizeGeometry) {
    for (Eigen::Index r = 0; r < vertices.rows(); ++r) {
      for (Eigen::Index c = 0; c < 3; ++c) {
        const auto q = quantize_dyadic(vertices(r, c), policy);
        if (!q) {
          return failure.code == ConditioningFailureCode::ConditioningPolicyUnrepresentable
                     ? std::nullopt
                     : std::optional<ConditioningFailure>(make_failure(
                           raw, policy, ConditioningFailureCode::CertificateMismatch,
                           ConditioningFailureClass::FatalInadmissible,
                           "failure-code", "expected policy-unrepresentable refusal"));
        }
        vertices(r, c) = q->value;
      }
    }
  }
  if (const auto faceFailure = validate_exact_faces(raw, policy, vertices)) {
    if (faceFailure->code == failure.code) return std::nullopt;
  }

  Eigen::MatrixXd field = raw.rawCrossField;
  if (policy.quantizeField) {
    for (Eigen::Index r = 0; r < field.rows(); ++r) {
      for (Eigen::Index c = 0; c < field.cols(); ++c) {
        const auto q = quantize_dyadic(field(r, c), policy);
        if (!q) {
          return failure.code == ConditioningFailureCode::ConditioningPolicyUnrepresentable
                     ? std::nullopt
                     : std::optional<ConditioningFailure>(make_failure(
                           raw, policy, ConditioningFailureCode::CertificateMismatch,
                           ConditioningFailureClass::FatalInadmissible,
                           "failure-code", "expected field policy-unrepresentable refusal"));
        }
        field(r, c) = q->value;
      }
    }
  }
  for (int face = 0; face < field.rows(); ++face) {
    for (int branch = 0; branch < 4; ++branch) {
      if (exact_vector_is_zero(field, face, branch)) {
        return failure.code == ConditioningFailureCode::FieldShapeInvalid
                   ? std::nullopt
                   : std::optional<ConditioningFailure>(make_failure(
                         raw, policy, ConditioningFailureCode::CertificateMismatch,
                         ConditioningFailureClass::FatalInadmissible,
                         "failure-code", "expected exact-zero field refusal"));
      }
    }
    if (policy.canonicalizeFieldBranches &&
        !canonical_branch_permutation(field, face)) {
      return failure.code == ConditioningFailureCode::FieldTransportInadmissible
                 ? std::nullopt
                 : std::optional<ConditioningFailure>(make_failure(
                       raw, policy, ConditioningFailureCode::CertificateMismatch,
                       ConditioningFailureClass::FatalInadmissible,
                       "failure-code", "expected exact Z4 transport refusal"));
    }
  }

  if (policy.mergeExactDuplicates && vertices.rows() > 0) {
    using Key = std::array<std::uint64_t, 3>;
    std::map<Key, std::vector<int>> groups;
    for (int v = 0; v < vertices.rows(); ++v) {
      groups[{std::bit_cast<std::uint64_t>(vertices(v, 0)),
              std::bit_cast<std::uint64_t>(vertices(v, 1)),
              std::bit_cast<std::uint64_t>(vertices(v, 2))}]
          .push_back(v);
    }
    const auto neighbors = vertex_neighbors(raw.faces, raw.vertices.rows());
    const auto components = vertex_components(neighbors);
    std::vector<int> owner(static_cast<std::size_t>(raw.vertices.rows()));
    for (int v = 0; v < raw.vertices.rows(); ++v) owner[static_cast<std::size_t>(v)] = v;
    bool featureConflict = false;
    bool connectivityConflict = false;
    for (const auto &[key, group] : groups) {
      (void)key;
      if (group.size() < 2U) continue;
      const int canonical = *std::min_element(group.begin(), group.end());
      for (const int v : group) {
        if (components[static_cast<std::size_t>(v)] !=
            components[static_cast<std::size_t>(canonical)]) {
          featureConflict = true;
          break;
        }
        if (v != canonical) {
          std::vector<int> common;
          std::set_intersection(neighbors[static_cast<std::size_t>(canonical)].begin(),
                                neighbors[static_cast<std::size_t>(canonical)].end(),
                                neighbors[static_cast<std::size_t>(v)].begin(),
                                neighbors[static_cast<std::size_t>(v)].end(),
                                std::back_inserter(common));
          if (common.empty() ||
              incident_feature_ids(v, raw.hardFeatures) !=
                  incident_feature_ids(canonical, raw.hardFeatures)) {
            featureConflict = true;
            break;
          }
        }
        owner[static_cast<std::size_t>(v)] = canonical;
      }
      if (featureConflict) break;
    }
    if (!featureConflict) {
      std::vector<int> owners = owner;
      std::sort(owners.begin(), owners.end());
      owners.erase(std::unique(owners.begin(), owners.end()), owners.end());
      std::map<int, int> compact;
      for (std::size_t i = 0; i < owners.size(); ++i) compact[owners[i]] = static_cast<int>(i);
      std::set<std::array<int, 3>> faceKeys;
      for (Eigen::Index f = 0; f < raw.faces.rows(); ++f) {
        std::array<int, 3> key{
            compact.at(owner[static_cast<std::size_t>(raw.faces(f, 0))]),
            compact.at(owner[static_cast<std::size_t>(raw.faces(f, 1))]),
            compact.at(owner[static_cast<std::size_t>(raw.faces(f, 2))])};
        if (key[0] == key[1] || key[1] == key[2] || key[2] == key[0]) {
          connectivityConflict = true;
          break;
        }
        std::sort(key.begin(), key.end());
        if (!faceKeys.insert(key).second) {
          connectivityConflict = true;
          break;
        }
      }
      std::set<std::pair<int, int>> featureKeys;
      if (!connectivityConflict) {
        for (const auto &feature : raw.hardFeatures) {
          const int a = compact.at(owner[static_cast<std::size_t>(feature.vertex0)]);
          const int b = compact.at(owner[static_cast<std::size_t>(feature.vertex1)]);
          const auto key = std::minmax(a, b);
          if (a == b || !featureKeys.emplace(key.first, key.second).second) {
            featureConflict = true;
            break;
          }
        }
      }
    }
    if (featureConflict) {
      return failure.code == ConditioningFailureCode::FeatureCorrespondenceConflict
                 ? std::nullopt
                 : std::optional<ConditioningFailure>(make_failure(
                       raw, policy, ConditioningFailureCode::CertificateMismatch,
                       ConditioningFailureClass::FatalInadmissible,
                       "failure-code", "expected exact merge feature refusal"));
    }
    if (connectivityConflict) {
      return failure.code == ConditioningFailureCode::InvalidSourceConnectivity
                 ? std::nullopt
                 : std::optional<ConditioningFailure>(make_failure(
                       raw, policy, ConditioningFailureCode::CertificateMismatch,
                       ConditioningFailureClass::FatalInadmissible,
                       "failure-code", "expected exact merge connectivity refusal"));
    }
  }

  return make_failure(raw, policy, ConditioningFailureCode::CertificateMismatch,
                      ConditioningFailureClass::FatalInadmissible,
                      "failure-code", "typed refusal is not independently derivable") ;
}

} // namespace directional::pipeline
