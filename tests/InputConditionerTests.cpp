#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <optional>
#include <set>
#include <vector>
#include <variant>

#include <gmpxx.h>

#include <directional/geometry/BoundedMeshPreconditioner.h>
#include <directional/pipeline/InputConditioner.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

using directional::geometry::Produced;
using directional::geometry::Rejected;
using directional::pipeline::ConditionedSourceProduct;
using directional::pipeline::ConditioningFailure;
using directional::pipeline::ConditioningFailureCode;
using directional::pipeline::ConditioningPolicy;
using directional::pipeline::ConditioningResult;
using directional::pipeline::RawConditioningFeatureEdge;
using directional::pipeline::RawSurfaceCellInput;

Eigen::RowVectorXd canonical_cross_row() {
  Eigen::RowVectorXd row(12);
  row << 1.0, 0.0, 0.0,
         0.0, 1.0, 0.0,
        -1.0, 0.0, 0.0,
         0.0,-1.0, 0.0;
  return row;
}

Eigen::RowVectorXd cross_row_for_angle(const double angle) {
  const double cosine = std::cos(angle);
  const double sine = std::sin(angle);
  Eigen::RowVectorXd row(12);
  row << cosine, sine, 0.0,
        -sine, cosine, 0.0,
        -cosine, -sine, 0.0,
         sine, -cosine, 0.0;
  return row;
}

RawSurfaceCellInput make_square_input() {
  RawSurfaceCellInput raw;
  raw.vertices.resize(4, 3);
  raw.vertices << 0.0, 0.0, 0.0,
                  1.0, 0.0, 0.0,
                  1.0, 1.0, 0.0,
                  0.0, 1.0, 0.0;
  raw.faces.resize(2, 3);
  raw.faces << 0, 1, 2,
               0, 2, 3;
  raw.rawCrossField.resize(2, 12);
  raw.rawCrossField.row(0) = canonical_cross_row();
  raw.rawCrossField.row(1) = canonical_cross_row();
  raw.hardFeatures = {{0, 1}, {1, 2}};
  return raw;
}

ConditioningPolicy witness_quantization_policy() {
  ConditioningPolicy policy;
  policy.id = "cp-cond-witness-dyadic-e2-v1";
  policy.quantizeGeometry = true;
  policy.quantizeField = true;
  policy.latticeExponent = 2;
  policy.maxAbsLatticeInteger = 1ULL << 20U;
  return policy;
}

const ConditionedSourceProduct &require_produced(const ConditioningResult &result) {
  const auto *produced = std::get_if<Produced<ConditionedSourceProduct>>(&result);
  EXPECT_NE(produced, nullptr);
  static const ConditionedSourceProduct empty;
  return produced == nullptr ? empty : produced->product;
}

const ConditioningFailure &require_rejected(const ConditioningResult &result) {
  const auto *rejected = std::get_if<Rejected<ConditioningFailure>>(&result);
  EXPECT_NE(rejected, nullptr);
  static const ConditioningFailure empty;
  return rejected == nullptr ? empty : rejected->failure;
}

std::size_t independent_max_valence(const Eigen::MatrixXi &faces,
                                    const int vertexCount) {
  std::vector<std::set<int>> neighbors(static_cast<std::size_t>(vertexCount));
  for (Eigen::Index f = 0; f < faces.rows(); ++f) {
    for (int c = 0; c < 3; ++c) {
      const int v = faces(f, c);
      neighbors[static_cast<std::size_t>(v)].insert(faces(f, (c + 1) % 3));
      neighbors[static_cast<std::size_t>(v)].insert(faces(f, (c + 2) % 3));
    }
  }
  std::size_t maximum = 0;
  for (const auto &oneRing : neighbors) maximum = std::max(maximum, oneRing.size());
  return maximum;
}

RawSurfaceCellInput make_seven_valence_fan() {
  RawSurfaceCellInput raw;
  raw.vertices.resize(8, 3);
  raw.vertices.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.141592653589793238462643383279502884;
  for (int i = 0; i < 7; ++i) {
    const double angle = 2.0 * pi * static_cast<double>(i) / 7.0;
    raw.vertices.row(i + 1) << std::cos(angle), std::sin(angle), 0.0;
  }
  raw.faces.resize(7, 3);
  raw.rawCrossField.resize(7, 12);
  for (int i = 0; i < 7; ++i) {
    raw.faces.row(i) << 0, i + 1, (i + 1) % 7 + 1;
    raw.rawCrossField.row(i) = canonical_cross_row();
  }
  return raw;
}

struct NegativeIndexRawWitness {
  RawSurfaceCellInput raw;
};

NegativeIndexRawWitness make_negative_index_witness() {
  NegativeIndexRawWitness witness;
  witness.raw.vertices.resize(6, 3);
  witness.raw.vertices.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.141592653589793238462643383279502884;
  for (int i = 0; i < 5; ++i) {
    const double angle = 2.0 * pi * static_cast<double>(i) / 5.0;
    witness.raw.vertices.row(i + 1) << std::cos(angle), std::sin(angle), 0.0;
  }
  witness.raw.faces.resize(5, 3);
  witness.raw.rawCrossField.resize(5, 12);
  for (int face = 0; face < 5; ++face) {
    witness.raw.faces.row(face) << 0, face + 1, (face + 1) % 5 + 1;
    const double angle = 2.0 * pi * static_cast<double>(face) / 5.0;
    const Eigen::RowVector3d x(std::cos(angle), std::sin(angle), 0.0);
    const Eigen::RowVector3d y(-std::sin(angle), std::cos(angle), 0.0);
    witness.raw.rawCrossField.block<1, 3>(face, 0) = x;
    witness.raw.rawCrossField.block<1, 3>(face, 3) = y;
    witness.raw.rawCrossField.block<1, 3>(face, 6) = -x;
    witness.raw.rawCrossField.block<1, 3>(face, 9) = -y;
  }
  return witness;
}

RawSurfaceCellInput make_boundary_truncation_witness() {
  RawSurfaceCellInput raw;
  raw.vertices.resize(6, 3);
  raw.vertices.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.141592653589793238462643383279502884;
  for (int i = 0; i < 5; ++i) {
    const double angle = 2.0 * pi * static_cast<double>(i) / 5.0;
    raw.vertices.row(i + 1) << std::cos(angle), std::sin(angle), 0.0;
  }
  raw.faces.resize(5, 3);
  raw.rawCrossField.resize(5, 12);
  for (int face = 0; face < 5; ++face) {
    raw.faces.row(face) << 0, face + 1, (face + 1) % 5 + 1;
    const double angle =
        2.0 * pi * static_cast<double>(face) / 5.0 + pi / 5.0;
    raw.rawCrossField.row(face) = cross_row_for_angle(angle);
  }
  return raw;
}

struct ExactVec3 {
  mpq_class x;
  mpq_class y;
  mpq_class z;
};

mpz_class exact_u64(const std::uint64_t value) {
  mpz_class result;
  mpz_import(result.get_mpz_t(), 1, 1, sizeof(value), 0, 0, &value);
  return result;
}

std::optional<mpq_class> exact_binary64(const double value) {
  const std::uint64_t bits = std::bit_cast<std::uint64_t>(value);
  const std::uint64_t exponentBits = (bits >> 52U) & 0x7ffU;
  const std::uint64_t fractionBits = bits & ((std::uint64_t{1} << 52U) - 1U);
  if (exponentBits == 0x7ffU) return std::nullopt;
  if (exponentBits == 0U && fractionBits == 0U) return mpq_class(0);

  const std::uint64_t mantissa = exponentBits == 0U
      ? fractionBits
      : ((std::uint64_t{1} << 52U) | fractionBits);
  const int exponent = exponentBits == 0U
      ? 1 - 1023 - 52
      : static_cast<int>(exponentBits) - 1023 - 52;
  mpz_class numerator = exact_u64(mantissa);
  if ((bits >> 63U) != 0U) numerator = -numerator;
  if (exponent >= 0) {
    mpz_mul_2exp(numerator.get_mpz_t(), numerator.get_mpz_t(),
                 static_cast<mp_bitcnt_t>(exponent));
    return mpq_class(numerator);
  }
  mpz_class denominator(1);
  mpz_mul_2exp(denominator.get_mpz_t(), denominator.get_mpz_t(),
               static_cast<mp_bitcnt_t>(-exponent));
  mpq_class result(numerator, denominator);
  result.canonicalize();
  return result;
}

std::optional<ExactVec3> exact_vec3(const Eigen::MatrixXd &values,
                                    const Eigen::Index row,
                                    const Eigen::Index column) {
  const auto x = exact_binary64(values(row, column));
  const auto y = exact_binary64(values(row, column + 1));
  const auto z = exact_binary64(values(row, column + 2));
  if (!x || !y || !z) return std::nullopt;
  return ExactVec3{*x, *y, *z};
}

ExactVec3 operator-(const ExactVec3 &a, const ExactVec3 &b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

ExactVec3 operator-(const ExactVec3 &v) {
  return {-v.x, -v.y, -v.z};
}

bool operator==(const ExactVec3 &a, const ExactVec3 &b) {
  return a.x == b.x && a.y == b.y && a.z == b.z;
}

mpq_class exact_dot(const ExactVec3 &a, const ExactVec3 &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

ExactVec3 exact_cross(const ExactVec3 &a, const ExactVec3 &b) {
  return {a.y * b.z - a.z * b.y,
          a.z * b.x - a.x * b.z,
          a.x * b.y - a.y * b.x};
}

bool exact_zero(const ExactVec3 &v) {
  return v.x == 0 && v.y == 0 && v.z == 0;
}

std::optional<std::vector<int>> independent_closed_face_fan(
    const Eigen::MatrixXi &faces, const int vertexCount) {
  std::optional<std::vector<int>> uniqueFan;
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    struct Incident { int face; int next; int previous; };
    std::vector<Incident> incident;
    for (Eigen::Index face = 0; face < faces.rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(face, corner) != vertex) continue;
        incident.push_back({static_cast<int>(face),
                            faces(face, (corner + 1) % 3),
                            faces(face, (corner + 2) % 3)});
        break;
      }
    }
    if (incident.size() < 3U) continue;

    const auto startIt = std::min_element(
        incident.begin(), incident.end(),
        [](const Incident &a, const Incident &b) { return a.face < b.face; });
    std::vector<int> cycle;
    cycle.reserve(incident.size());
    int currentFace = startIt->face;
    for (std::size_t step = 0; step < incident.size(); ++step) {
      const auto current = std::find_if(
          incident.begin(), incident.end(),
          [&](const Incident &entry) { return entry.face == currentFace; });
      if (current == incident.end()) { cycle.clear(); break; }
      cycle.push_back(current->face);
      const auto successor = std::find_if(
          incident.begin(), incident.end(),
          [&](const Incident &entry) { return entry.next == current->previous; });
      if (successor == incident.end()) { cycle.clear(); break; }
      currentFace = successor->face;
      if (step + 1U < incident.size() &&
          std::find(cycle.begin(), cycle.end(), currentFace) != cycle.end()) {
        cycle.clear();
        break;
      }
    }
    if (cycle.size() != incident.size() || currentFace != startIt->face) continue;
    if (uniqueFan.has_value()) return std::nullopt;
    uniqueFan = std::move(cycle);
  }
  return uniqueFan;
}

struct IndependentNegativeIndexOracle {
  int cycleNumerator = 0;
  std::vector<int> quarterTurnTransport;
};

std::optional<IndependentNegativeIndexOracle> independent_negative_index_oracle(
    const RawSurfaceCellInput &raw) {
  if (raw.vertices.cols() != 3 || raw.faces.cols() != 3 ||
      raw.rawCrossField.rows() != raw.faces.rows() ||
      raw.rawCrossField.cols() != 12) {
    return std::nullopt;
  }
  const auto cycle = independent_closed_face_fan(
      raw.faces, static_cast<int>(raw.vertices.rows()));
  if (!cycle || cycle->empty()) return std::nullopt;

  std::vector<std::array<ExactVec3, 4>> branches(
      static_cast<std::size_t>(raw.faces.rows()));
  std::optional<ExactVec3> referenceNormal;

  for (Eigen::Index face = 0; face < raw.faces.rows(); ++face) {
    std::array<ExactVec3, 3> vertices;
    for (int corner = 0; corner < 3; ++corner) {
      const int sourceVertex = raw.faces(face, corner);
      if (sourceVertex < 0 || sourceVertex >= raw.vertices.rows()) return std::nullopt;
      const auto point = exact_vec3(raw.vertices, sourceVertex, 0);
      if (!point) return std::nullopt;
      vertices[static_cast<std::size_t>(corner)] = *point;
    }
    const ExactVec3 normal = exact_cross(vertices[1] - vertices[0],
                                          vertices[2] - vertices[0]);
    if (exact_zero(normal)) return std::nullopt;
    if (!referenceNormal) {
      referenceNormal = normal;
    } else if (!exact_zero(exact_cross(*referenceNormal, normal)) ||
               exact_dot(*referenceNormal, normal) <= 0) {
      return std::nullopt;
    }
    auto &faceBranches = branches[static_cast<std::size_t>(face)];
    for (int branch = 0; branch < 4; ++branch) {
      const auto exact = exact_vec3(raw.rawCrossField, face, branch * 3);
      if (!exact || exact_zero(*exact) || exact_dot(*exact, normal) != 0) {
        return std::nullopt;
      }
      faceBranches[static_cast<std::size_t>(branch)] = *exact;
    }
    if (!(faceBranches[2] == -faceBranches[0]) ||
        !(faceBranches[3] == -faceBranches[1]) ||
        exact_dot(faceBranches[0], faceBranches[1]) != 0 ||
        exact_dot(faceBranches[0], faceBranches[0]) !=
            exact_dot(faceBranches[1], faceBranches[1]) ||
        exact_dot(exact_cross(faceBranches[0], faceBranches[1]), normal) <= 0) {
      return std::nullopt;
    }
  }

  IndependentNegativeIndexOracle oracle;
  oracle.quarterTurnTransport.reserve(cycle->size());
  int residue = 0;
  for (std::size_t index = 0; index < cycle->size(); ++index) {
    const int fromFace = (*cycle)[index];
    const int toFace = (*cycle)[(index + 1U) % cycle->size()];
    const auto &from = branches[static_cast<std::size_t>(fromFace)];
    const auto &to = branches[static_cast<std::size_t>(toFace)];
    int commonOffset = -1;
    for (int branch = 0; branch < 4; ++branch) {
      int bestTarget = -1;
      mpq_class bestScore;
      bool uniqueBest = true;
      for (int target = 0; target < 4; ++target) {
        const mpq_class score = exact_dot(
            from[static_cast<std::size_t>(branch)],
            to[static_cast<std::size_t>(target)]);
        if (bestTarget < 0 || score > bestScore) {
          bestTarget = target;
          bestScore = score;
          uniqueBest = true;
        } else if (score == bestScore) {
          uniqueBest = false;
        }
      }
      if (!uniqueBest) return std::nullopt;
      const int offset = (bestTarget - branch + 4) % 4;
      if (commonOffset < 0) commonOffset = offset;
      if (offset != commonOffset) return std::nullopt;
    }
    oracle.quarterTurnTransport.push_back(commonOffset);
    residue = (residue + commonOffset) % 4;
  }
  oracle.cycleNumerator = residue > 2 ? residue - 4 : residue;
  return oracle;
}

std::optional<int> independent_cycle_center(
    const Eigen::MatrixXi &faces, const std::vector<int> &cycle) {
  if (cycle.empty()) return std::nullopt;
  std::vector<int> common;
  common.reserve(3);
  const int firstFace = cycle.front();
  if (firstFace < 0 || firstFace >= faces.rows()) return std::nullopt;
  for (int corner = 0; corner < 3; ++corner) {
    const int candidate = faces(firstFace, corner);
    bool presentEverywhere = true;
    for (const int face : cycle) {
      if (face < 0 || face >= faces.rows()) return std::nullopt;
      bool present = false;
      for (int c = 0; c < 3; ++c) present |= faces(face, c) == candidate;
      if (!present) {
        presentEverywhere = false;
        break;
      }
    }
    if (presentEverywhere) common.push_back(candidate);
  }
  if (common.size() != 1U) return std::nullopt;
  return common.front();
}

int independent_edge_incidence(const Eigen::MatrixXi &faces, int a, int b) {
  if (b < a) std::swap(a, b);
  int incidence = 0;
  for (Eigen::Index face = 0; face < faces.rows(); ++face) {
    for (int edge = 0; edge < 3; ++edge) {
      int x = faces(face, edge);
      int y = faces(face, (edge + 1) % 3);
      if (y < x) std::swap(x, y);
      if (x == a && y == b) ++incidence;
    }
  }
  return incidence;
}

struct IndependentBoundaryTruncationOracle {
  int singularityVertex = -1;
  int cycleNumerator = 0;
  int sourceFace = -1;
  int fieldBranch = -1;
  std::array<int, 2> boundaryEdge{-1, -1};
  mpq_class rayParameter;
  mpq_class boundaryParameter;

  bool operator==(const IndependentBoundaryTruncationOracle &other) const {
    return singularityVertex == other.singularityVertex &&
           cycleNumerator == other.cycleNumerator &&
           sourceFace == other.sourceFace &&
           fieldBranch == other.fieldBranch &&
           boundaryEdge == other.boundaryEdge &&
           rayParameter == other.rayParameter &&
           boundaryParameter == other.boundaryParameter;
  }
};

std::optional<IndependentBoundaryTruncationOracle>
independent_boundary_truncation_oracle(const RawSurfaceCellInput &raw) {
  const auto indexOracle = independent_negative_index_oracle(raw);
  if (!indexOracle || indexOracle->cycleNumerator == 0) return std::nullopt;

  const auto cycle = independent_closed_face_fan(
      raw.faces, static_cast<int>(raw.vertices.rows()));
  if (!cycle || cycle->empty()) return std::nullopt;
  const auto center = independent_cycle_center(raw.faces, *cycle);
  if (!center) return std::nullopt;
  const auto centerPoint = exact_vec3(raw.vertices, *center, 0);
  if (!centerPoint) return std::nullopt;

  for (const int face : *cycle) {
    int centerCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (raw.faces(face, corner) == *center) {
        centerCorner = corner;
        break;
      }
    }
    if (centerCorner < 0) return std::nullopt;

    const int rawA = raw.faces(face, (centerCorner + 1) % 3);
    const int rawB = raw.faces(face, (centerCorner + 2) % 3);
    if (independent_edge_incidence(raw.faces, rawA, rawB) != 1) continue;
    const auto a = exact_vec3(raw.vertices, rawA, 0);
    const auto b = exact_vec3(raw.vertices, rawB, 0);
    if (!a || !b) return std::nullopt;
    const ExactVec3 edge = *b - *a;
    const ExactVec3 fromCenter = *a - *centerPoint;
    const ExactVec3 normal = exact_cross(fromCenter, *b - *centerPoint);
    if (exact_zero(normal)) return std::nullopt;

    for (int branch = 0; branch < 4; ++branch) {
      const auto direction = exact_vec3(raw.rawCrossField, face, branch * 3);
      if (!direction || exact_zero(*direction) ||
          exact_dot(*direction, normal) != 0) {
        return std::nullopt;
      }
      const mpq_class denominator =
          exact_dot(exact_cross(*direction, edge), normal);
      if (denominator == 0) continue;
      const mpq_class rayParameter =
          exact_dot(exact_cross(fromCenter, edge), normal) / denominator;
      mpq_class boundaryParameter =
          exact_dot(exact_cross(fromCenter, *direction), normal) / denominator;
      if (rayParameter <= 0 || boundaryParameter <= 0 ||
          boundaryParameter >= 1) {
        continue;
      }

      std::array<int, 2> boundaryEdge{rawA, rawB};
      if (boundaryEdge[1] < boundaryEdge[0]) {
        std::swap(boundaryEdge[0], boundaryEdge[1]);
        boundaryParameter = 1 - boundaryParameter;
      }
      return IndependentBoundaryTruncationOracle{
          *center, indexOracle->cycleNumerator, face, branch, boundaryEdge,
          rayParameter, boundaryParameter};
    }
  }
  return std::nullopt;
}

std::optional<RawSurfaceCellInput> reconstruct_raw_view_from_certificate(
    const ConditionedSourceProduct &product) {
  const auto &certificate = product.certificate;
  RawSurfaceCellInput reconstructed;
  reconstructed.vertices.resize(
      static_cast<Eigen::Index>(certificate.vertices.size()), 3);
  std::vector<int> conditionedToRaw(
      static_cast<std::size_t>(product.vertices.rows()), -1);
  for (const auto &entry : certificate.vertices) {
    if (entry.rawVertex < 0 || entry.rawVertex >= reconstructed.vertices.rows() ||
        entry.conditionedVertex < 0 ||
        entry.conditionedVertex >= product.vertices.rows()) {
      return std::nullopt;
    }
    int &rawOwner =
        conditionedToRaw[static_cast<std::size_t>(entry.conditionedVertex)];
    if (rawOwner >= 0) return std::nullopt;
    rawOwner = entry.rawVertex;
    reconstructed.vertices.row(entry.rawVertex) =
        product.vertices.row(entry.conditionedVertex);
  }
  if (std::find(conditionedToRaw.begin(), conditionedToRaw.end(), -1) !=
      conditionedToRaw.end()) {
    return std::nullopt;
  }

  reconstructed.faces.resize(
      static_cast<Eigen::Index>(certificate.faces.size()), 3);
  for (const auto &entry : certificate.faces) {
    if (entry.rawFace < 0 || entry.rawFace >= reconstructed.faces.rows() ||
        entry.conditionedFace < 0 || entry.conditionedFace >= product.faces.rows()) {
      return std::nullopt;
    }
    for (int corner = 0; corner < 3; ++corner) {
      const int conditionedVertex = product.faces(entry.conditionedFace, corner);
      if (conditionedVertex < 0 ||
          conditionedVertex >= static_cast<int>(conditionedToRaw.size())) {
        return std::nullopt;
      }
      reconstructed.faces(entry.rawFace, corner) =
          conditionedToRaw[static_cast<std::size_t>(conditionedVertex)];
    }
  }

  reconstructed.rawCrossField.resize(
      static_cast<Eigen::Index>(certificate.fields.size()), 12);
  for (const auto &entry : certificate.fields) {
    if (entry.rawFace < 0 ||
        entry.rawFace >= reconstructed.rawCrossField.rows() ||
        entry.conditionedFace < 0 ||
        entry.conditionedFace >= product.rawCrossField.rows()) {
      return std::nullopt;
    }
    std::array<bool, 4> rawBranchSeen{false, false, false, false};
    for (int conditionedBranch = 0; conditionedBranch < 4;
         ++conditionedBranch) {
      const int rawBranch =
          entry.branchPermutation[static_cast<std::size_t>(conditionedBranch)];
      if (rawBranch < 0 || rawBranch >= 4 ||
          rawBranchSeen[static_cast<std::size_t>(rawBranch)]) {
        return std::nullopt;
      }
      rawBranchSeen[static_cast<std::size_t>(rawBranch)] = true;
      reconstructed.rawCrossField.block<1, 3>(entry.rawFace, rawBranch * 3) =
          product.rawCrossField.block<1, 3>(entry.conditionedFace,
                                            conditionedBranch * 3);
    }
  }

  reconstructed.hardFeatures.resize(certificate.features.size());
  for (const auto &entry : certificate.features) {
    if (entry.rawFeature < 0 ||
        entry.rawFeature >= static_cast<int>(reconstructed.hardFeatures.size())) {
      return std::nullopt;
    }
    const int conditionedA = entry.conditionedEdge.vertex0;
    const int conditionedB = entry.conditionedEdge.vertex1;
    if (conditionedA < 0 || conditionedB < 0 ||
        conditionedA >= static_cast<int>(conditionedToRaw.size()) ||
        conditionedB >= static_cast<int>(conditionedToRaw.size())) {
      return std::nullopt;
    }
    reconstructed.hardFeatures[static_cast<std::size_t>(entry.rawFeature)] = {
        conditionedToRaw[static_cast<std::size_t>(conditionedA)],
        conditionedToRaw[static_cast<std::size_t>(conditionedB)]};
  }
  return reconstructed;
}

} // namespace

TEST(InputConditionerCPCondCB1, IdentityProducedSeparatesRawAndSemanticDigests) {
  const RawSurfaceCellInput raw = make_square_input();
  const ConditioningPolicy policy = ConditioningPolicy::production_identity();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);

  EXPECT_TRUE(product.vertices.isApprox(raw.vertices, 0.0));
  EXPECT_TRUE((product.faces.array() == raw.faces.array()).all());
  EXPECT_TRUE(product.rawCrossField.isApprox(raw.rawCrossField, 0.0));
  EXPECT_TRUE(product.certificate.operations.empty());
  EXPECT_EQ(product.rawInputDigest, product.certificate.rawInputDigest);
  EXPECT_NE(product.rawInputDigest, product.conditionedSemanticDigest);
  EXPECT_FALSE(directional::pipeline::validate_conditioned_source_product(raw, policy, product).has_value());
}

TEST(InputConditionerCPCondCB1, ExactDyadicQuantizationRecordsNonEmptyOperation) {
  RawSurfaceCellInput raw = make_square_input();
  raw.vertices(1, 0) = 1.125;  // exact binary64 midpoint; ties-to-even at e=2 -> 1.0
  ConditioningPolicy policy = witness_quantization_policy();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);

  EXPECT_DOUBLE_EQ(product.vertices(1, 0), 1.0);
  ASSERT_FALSE(product.certificate.operations.empty());
  EXPECT_EQ(product.certificate.operations.front().locus, "vertex:1:0");
  EXPECT_FALSE(directional::pipeline::validate_conditioned_source_product(raw, policy, product).has_value());
}

TEST(InputConditionerCPCondCB1, ExactEqualityMergeUsesMinimumRawOwner) {
  RawSurfaceCellInput raw;
  raw.vertices.resize(5, 3);
  raw.vertices << 0.0, 0.0, 0.0,
                  1.0, 0.0, 0.0,
                  1.0, 1.0, 0.0,
                  0.125, 0.0, 0.0,
                  0.0, 1.0, 0.0;
  raw.faces.resize(2, 3);
  raw.faces << 0, 1, 2,
               3, 2, 4;
  raw.rawCrossField.resize(2, 12);
  raw.rawCrossField.row(0) = canonical_cross_row();
  raw.rawCrossField.row(1) = canonical_cross_row();

  ConditioningPolicy policy = witness_quantization_policy();
  policy.id = "cp-cond-witness-safe-merge-v1";
  policy.mergeExactDuplicates = true;
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);

  ASSERT_EQ(product.certificate.vertices.size(), 5U);
  EXPECT_EQ(product.certificate.vertices[0].conditionedVertex,
            product.certificate.vertices[3].conditionedVertex);
  const auto merge = std::find_if(product.certificate.operations.begin(),
                                  product.certificate.operations.end(),
      [](const auto &op) { return op.kind == directional::pipeline::ConditioningOperationKind::ExactVertexMerge; });
  ASSERT_NE(merge, product.certificate.operations.end());
  ASSERT_FALSE(merge->rawOwners.empty());
  EXPECT_EQ(*std::min_element(merge->rawOwners.begin(), merge->rawOwners.end()), 0);
  EXPECT_EQ(merge->locus, "vertex-owner:0");
}

TEST(InputConditionerCPCondCB1, UnsafeDisconnectedExactMergeIsTypedRefusal) {
  RawSurfaceCellInput raw;
  raw.vertices.resize(6, 3);
  raw.vertices << 0.0, 0.0, 0.0,
                  1.0, 0.0, 0.0,
                  0.0, 1.0, 0.0,
                  0.125, 0.0, 0.0,
                  2.0, 0.0, 0.0,
                  2.0, 1.0, 0.0;
  raw.faces.resize(2, 3);
  raw.faces << 0, 1, 2,
               3, 4, 5;
  raw.rawCrossField.resize(2, 12);
  raw.rawCrossField.row(0) = canonical_cross_row();
  raw.rawCrossField.row(1) = canonical_cross_row();
  ConditioningPolicy policy = witness_quantization_policy();
  policy.id = "cp-cond-witness-unsafe-merge-v1";
  policy.mergeExactDuplicates = true;

  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditioningFailure &failure = require_rejected(result);
  EXPECT_EQ(failure.code, ConditioningFailureCode::FeatureCorrespondenceConflict);
  EXPECT_FALSE(directional::pipeline::validate_conditioning_failure(raw, policy, failure).has_value());
}

TEST(InputConditionerCPCondCB1, ExactRationalSliverPredicateRefusesWithoutRepair) {
  RawSurfaceCellInput raw;
  raw.vertices.resize(3, 3);
  raw.vertices << 0.0, 0.0, 0.0,
                  1.0, 0.0, 0.0,
                  0.0, 0.0625, 0.0;
  raw.faces.resize(1, 3);
  raw.faces << 0, 1, 2;
  raw.rawCrossField.resize(1, 12);
  raw.rawCrossField.row(0) = canonical_cross_row();
  ConditioningPolicy policy;
  policy.id = "cp-cond-witness-exact-sliver-v1";
  policy.refuseSlivers = true;
  policy.sliverRatioNumerator = 1;
  policy.sliverRatioDenominator = 100;

  // Exact independently-derived ratio is 256/66049 < 1/100.
  static_assert(256LL * 100LL < 66049LL);
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditioningFailure &failure = require_rejected(result);
  EXPECT_EQ(failure.code, ConditioningFailureCode::SliverPolicyExceeded);
  EXPECT_FALSE(directional::pipeline::validate_conditioning_failure(raw, policy, failure).has_value());
}

TEST(InputConditionerCPCondCB1, HighValenceRawPreconditionIsIndependentAndProduced) {
  const RawSurfaceCellInput raw = make_seven_valence_fan();
  ASSERT_EQ(independent_max_valence(raw.faces, raw.vertices.rows()), 7U);
  const ConditioningPolicy policy = ConditioningPolicy::production_identity();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);
  EXPECT_TRUE((product.faces.array() == raw.faces.array()).all());
}

TEST(InputConditionerCPCondCB1, NegativeIndexRawPreconditionIsIndependentAndPreserved) {
  const NegativeIndexRawWitness witness = make_negative_index_witness();
  const auto rawOracle = independent_negative_index_oracle(witness.raw);
  ASSERT_TRUE(rawOracle.has_value());
  EXPECT_EQ(rawOracle->cycleNumerator, -1);
  ASSERT_FALSE(rawOracle->quarterTurnTransport.empty());

  RawSurfaceCellInput mutated = witness.raw;
  std::uint64_t mutatedBits = std::bit_cast<std::uint64_t>(mutated.rawCrossField(0, 0));
  mutatedBits ^= 1U;
  mutated.rawCrossField(0, 0) = std::bit_cast<double>(mutatedBits);
  EXPECT_FALSE(independent_negative_index_oracle(mutated).has_value());

  const ConditioningPolicy policy = ConditioningPolicy::production_identity();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(witness.raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);
  EXPECT_TRUE((product.faces.array() == witness.raw.faces.array()).all());
  EXPECT_TRUE(product.rawCrossField.isApprox(witness.raw.rawCrossField, 0.0));

  const RawSurfaceCellInput conditioned{
      product.vertices, product.faces, product.rawCrossField, product.hardFeatures};
  const auto conditionedOracle = independent_negative_index_oracle(conditioned);
  ASSERT_TRUE(conditionedOracle.has_value());
  EXPECT_EQ(conditionedOracle->cycleNumerator, rawOracle->cycleNumerator);
  EXPECT_EQ(conditionedOracle->quarterTurnTransport, rawOracle->quarterTurnTransport);
}

TEST(InputConditionerCPCondCB1, ContradictoryExactZ4PairingIsTypedRefusal) {
  RawSurfaceCellInput raw = make_square_input();
  raw.rawCrossField(0, 6) = -0.5;  // branch 2 is no longer exactly opposite branch 0
  ConditioningPolicy policy;
  policy.id = "cp-cond-witness-z4-refusal-v1";
  policy.canonicalizeFieldBranches = true;

  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditioningFailure &failure = require_rejected(result);
  EXPECT_EQ(failure.code, ConditioningFailureCode::FieldTransportInadmissible);
  EXPECT_FALSE(directional::pipeline::validate_conditioning_failure(raw, policy, failure).has_value());
}

TEST(InputConditionerCPCondCB5,
     BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved) {
  const RawSurfaceCellInput raw = make_boundary_truncation_witness();
  const auto rawOracle = independent_boundary_truncation_oracle(raw);
  ASSERT_TRUE(rawOracle.has_value());
  EXPECT_EQ(rawOracle->singularityVertex, 0);
  EXPECT_EQ(rawOracle->cycleNumerator, -1);
  EXPECT_EQ(rawOracle->sourceFace, 0);
  EXPECT_EQ(rawOracle->fieldBranch, 0);
  EXPECT_EQ(rawOracle->boundaryEdge, (std::array<int, 2>{1, 2}));
  EXPECT_EQ(independent_edge_incidence(
                raw.faces, rawOracle->boundaryEdge[0], rawOracle->boundaryEdge[1]),
            1);

  RawSurfaceCellInput mutated = raw;
  constexpr double pi = 3.141592653589793238462643383279502884;
  mutated.rawCrossField.row(0) = cross_row_for_angle(2.0 * pi / 9.0);
  const auto mutatedOracle = independent_boundary_truncation_oracle(mutated);
  ASSERT_TRUE(mutatedOracle.has_value());
  EXPECT_EQ(mutatedOracle->singularityVertex, rawOracle->singularityVertex);
  EXPECT_EQ(mutatedOracle->cycleNumerator, rawOracle->cycleNumerator);
  EXPECT_EQ(mutatedOracle->sourceFace, rawOracle->sourceFace);
  EXPECT_EQ(mutatedOracle->boundaryEdge, rawOracle->boundaryEdge);
  EXPECT_NE(mutatedOracle->boundaryParameter, rawOracle->boundaryParameter);
  EXPECT_FALSE(*mutatedOracle == *rawOracle);

  const ConditioningPolicy policy = ConditioningPolicy::production_identity();
  const ConditioningResult result =
      directional::pipeline::condition_surface_cell_input(raw, policy);
  const auto *produced = std::get_if<Produced<ConditionedSourceProduct>>(&result);
  ASSERT_NE(produced, nullptr);
  const ConditionedSourceProduct &product = produced->product;
  EXPECT_FALSE(directional::pipeline::validate_conditioned_source_product(
                   raw, policy, product)
                   .has_value());

  const auto reconstructed = reconstruct_raw_view_from_certificate(product);
  ASSERT_TRUE(reconstructed.has_value());
  const auto conditionedOracle =
      independent_boundary_truncation_oracle(*reconstructed);
  ASSERT_TRUE(conditionedOracle.has_value());
  EXPECT_TRUE(*conditionedOracle == *rawOracle);
}

TEST(InputConditionerCPCondCB1, CertificateTamperMatrixRejectsEveryAuthorityClass) {
  RawSurfaceCellInput raw = make_square_input();
  raw.vertices(1, 0) = 1.125;
  ConditioningPolicy policy = witness_quantization_policy();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditionedSourceProduct &base = require_produced(result);
  ASSERT_FALSE(base.certificate.operations.empty());

  auto expect_tamper_rejected = [&](auto mutate) {
    ConditionedSourceProduct tampered = base;
    mutate(tampered);
    EXPECT_TRUE(directional::pipeline::validate_conditioned_source_product(raw, policy, tampered).has_value());
  };
  expect_tamper_rejected([](auto &p) { p.certificate.vertices[0].conditionedVertex = 1; });
  expect_tamper_rejected([](auto &p) { p.certificate.faces[0].conditionedFace = 1; });
  expect_tamper_rejected([](auto &p) { p.certificate.fields[0].branchPermutation = {1, 2, 3, 0}; });
  expect_tamper_rejected([](auto &p) { p.certificate.features[0].conditionedEdge.vertex0 = 3; });
  expect_tamper_rejected([](auto &p) { p.certificate.operations[0].locus = "tampered"; });
  expect_tamper_rejected([](auto &p) { ++p.conditionedSemanticDigest; });
}

TEST(InputConditionerCPCondCB1, IdempotenceHoldsForCleanAndNonEmptyOperationProducts) {
  const ConditioningPolicy identity = ConditioningPolicy::production_identity();
  const RawSurfaceCellInput cleanRaw = make_square_input();
  const ConditioningResult cleanResult =
      directional::pipeline::condition_surface_cell_input(cleanRaw, identity);
  const ConditionedSourceProduct &clean = require_produced(cleanResult);
  RawSurfaceCellInput cleanSecond{clean.vertices, clean.faces, clean.rawCrossField, clean.hardFeatures};
  const ConditioningResult cleanAgainResult =
      directional::pipeline::condition_surface_cell_input(cleanSecond, identity);
  const ConditionedSourceProduct &cleanAgain = require_produced(cleanAgainResult);
  EXPECT_EQ(cleanAgain.conditionedSemanticDigest, clean.conditionedSemanticDigest);
  EXPECT_TRUE(cleanAgain.certificate.operations.empty());

  RawSurfaceCellInput changedRaw = make_square_input();
  changedRaw.vertices(1, 0) = 1.125;
  const ConditioningPolicy quantizedPolicy = witness_quantization_policy();
  const ConditioningResult changedResult =
      directional::pipeline::condition_surface_cell_input(changedRaw, quantizedPolicy);
  const ConditionedSourceProduct &changed = require_produced(changedResult);
  ASSERT_FALSE(changed.certificate.operations.empty());
  RawSurfaceCellInput changedSecond{changed.vertices, changed.faces, changed.rawCrossField, changed.hardFeatures};
  const ConditioningResult changedAgainResult =
      directional::pipeline::condition_surface_cell_input(changedSecond, quantizedPolicy);
  const ConditionedSourceProduct &changedAgain = require_produced(changedAgainResult);
  EXPECT_EQ(changedAgain.conditionedSemanticDigest, changed.conditionedSemanticDigest);
  EXPECT_TRUE(changedAgain.certificate.operations.empty());
}

TEST(InputConditionerCPCondCB1, ExactSameLatticeCellPerturbationsShareSemanticDigest) {
  RawSurfaceCellInput first = make_square_input();
  RawSurfaceCellInput second = make_square_input();
  first.vertices(1, 0) = 1.0625;
  second.vertices(1, 0) = 1.09375;
  // At e=2 both exact binary rationals are strictly inside the lattice cell
  // whose nearest lattice point is 1.0; neither is a tie.
  ASSERT_LT(first.vertices(1, 0), 1.125);
  ASSERT_LT(second.vertices(1, 0), 1.125);
  ASSERT_GT(first.vertices(1, 0), 0.875);
  ASSERT_GT(second.vertices(1, 0), 0.875);
  const ConditioningPolicy policy = witness_quantization_policy();
  const ConditioningResult firstResult =
      directional::pipeline::condition_surface_cell_input(first, policy);
  const ConditioningResult secondResult =
      directional::pipeline::condition_surface_cell_input(second, policy);
  const ConditionedSourceProduct &a = require_produced(firstResult);
  const ConditionedSourceProduct &b = require_produced(secondResult);
  EXPECT_NE(a.rawInputDigest, b.rawInputDigest);
  EXPECT_EQ(a.conditionedSemanticDigest, b.conditionedSemanticDigest);
  EXPECT_TRUE(a.vertices.isApprox(b.vertices, 0.0));
}

TEST(InputConditionerCPCondCB1, LegacyPreconditionerCannotSubstituteForCertificate) {
  const RawSurfaceCellInput raw = make_square_input();
  directional::geometry::BoundedMeshPreconditionerOptions legacyOptions;
  legacyOptions.enabled = true;
  const auto legacy = directional::geometry::BoundedMeshPreconditioner::precondition(
      raw.vertices, raw.faces, legacyOptions);

  ConditionedSourceProduct fabricated;
  fabricated.vertices = legacy.vertices;
  fabricated.faces = legacy.faces;
  fabricated.rawCrossField = raw.rawCrossField;
  fabricated.policyId = ConditioningPolicy::production_identity().id;
  EXPECT_TRUE(directional::pipeline::validate_conditioned_source_product(
      raw, ConditioningPolicy::production_identity(), fabricated).has_value());
}

TEST(InputConditionerCPCondCB1, TolerantRawFieldFinalizationCannotReplaceExactCertificate) {
  RawSurfaceCellInput raw = make_square_input();
  raw.rawCrossField.block<1, 3>(0, 0) << 0x1p-500, 0.0, 0.0;
  const ConditioningPolicy policy = ConditioningPolicy::production_identity();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);
  EXPECT_FALSE(directional::pipeline::validate_conditioned_source_product(raw, policy, product).has_value());

  ConditionedSourceProduct noCertificate = product;
  noCertificate.certificate = {};
  EXPECT_TRUE(directional::pipeline::validate_conditioned_source_product(raw, policy, noCertificate).has_value());
}

TEST(InputConditionerCPCondCB1, SurfaceCellsRawEntryRejectsAtConditionerBeforeA0) {
  RawSurfaceCellInput raw = make_square_input();
  raw.rawCrossField.block<1, 3>(0, 0).setZero();
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy = directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      raw.vertices, raw.faces, raw.rawCrossField, options);
  ASSERT_TRUE(result.is_rejected());
  ASSERT_NE(result.rejection(), nullptr);
  EXPECT_EQ(result.rejection()->surfaceCellFailure,
            directional::pipeline::SurfaceCellFailureCode::InputConditioningRejected);
  EXPECT_EQ(result.rejection()->stage, "input-conditioning/FieldShapeInvalid");
}
