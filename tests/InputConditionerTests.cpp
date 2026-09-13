#include <gtest/gtest.h>

#include <algorithm>
#include <bit>
#include <cmath>
#include <set>
#include <vector>
#include <variant>

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
  int exactDiscreteNumerator = 0;
};

NegativeIndexRawWitness make_negative_index_witness() {
  // Five planar sectors with a 72-degree CCW representative advance. For a
  // 4-RoSy field, independently reduce each +72-degree step by one +90-degree
  // branch relabel, leaving -18 degrees per sector. Five sectors therefore
  // accumulate exactly -90 degrees = numerator -1. The binary64 branch values
  // are merely the raw carrier; the expected discrete numerator is derived
  // from the authored 5 * (72 - 90) degree combinatorics, not production output.
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
  constexpr int sectors = 5;
  constexpr int representativeStepDegrees = 72;
  constexpr int quarterTurnDegrees = 90;
  constexpr int residualDegrees =
      sectors * (representativeStepDegrees - quarterTurnDegrees);
  static_assert(residualDegrees == -90);
  witness.exactDiscreteNumerator = residualDegrees / quarterTurnDegrees;
  return witness;
}

bool exact_boundary_truncation_precondition_is_proved_without_a2a() {
  // CP-COND can prove an open source boundary and preserve its raw carriers,
  // but this CB1 fixture intentionally does not claim that the later A2a trace
  // reaches that boundary. That reachability remains a named blocked gate.
  return false;
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
  ASSERT_EQ(witness.exactDiscreteNumerator, -1);
  const ConditioningPolicy policy = ConditioningPolicy::production_identity();
  const ConditioningResult result = directional::pipeline::condition_surface_cell_input(witness.raw, policy);
  const ConditionedSourceProduct &product = require_produced(result);
  EXPECT_TRUE((product.faces.array() == witness.raw.faces.array()).all());
  EXPECT_TRUE(product.rawCrossField.isApprox(witness.raw.rawCrossField, 0.0));
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

TEST(InputConditionerCPCondCB1, BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker) {
  const RawSurfaceCellInput raw = make_square_input();
  ASSERT_EQ(raw.faces.rows(), 2);
  EXPECT_FALSE(exact_boundary_truncation_precondition_is_proved_without_a2a());
  GTEST_SKIP() << "CP-COND proves boundary/correspondence only; A2a separatrix reachability remains unproved and non-selector.";
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
