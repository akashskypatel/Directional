#pragma once

#include <Eigen/Core>

#include <array>
#include <compare>
#include <cstdint>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::pipeline {

/** Stable CP-COND policy identity plus exact integer parameters. */
struct ConditioningPolicy {
  std::string id = "cp-cond-production-identity-v1";

  // Production remains bit-preserving. Non-default witness policies may
  // exercise the frozen exact operation set.
  bool quantizeGeometry = false;
  bool quantizeField = false;
  int latticeExponent = 0;
  std::uint64_t maxAbsLatticeInteger = (std::uint64_t{1} << 52U) - 1U;
  bool mergeExactDuplicates = false;
  bool canonicalizeFieldBranches = false;
  bool refuseSlivers = false;
  std::int64_t sliverRatioNumerator = 0;
  std::int64_t sliverRatioDenominator = 1;

  [[nodiscard]] static ConditioningPolicy production_identity();
};

struct RawConditioningFeatureEdge {
  int vertex0 = -1;
  int vertex1 = -1;

  auto operator<=>(const RawConditioningFeatureEdge &) const = default;
};

struct RawSurfaceCellInput {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd rawCrossField;
  std::vector<RawConditioningFeatureEdge> hardFeatures;
};

enum class ConditioningOperationKind : std::uint8_t {
  DyadicQuantization,
  ExactVertexMerge,
  Z4FieldReindex,
};

struct ConditioningOperationRecord {
  ConditioningOperationKind kind = ConditioningOperationKind::DyadicQuantization;
  std::string locus;
  std::vector<std::uint64_t> beforeBits;
  std::vector<std::uint64_t> afterBits;
  std::vector<int> rawOwners;
  std::vector<int> conditionedOwners;

  auto operator<=>(const ConditioningOperationRecord &) const = default;
};

struct ConditioningVertexCorrespondence {
  int rawVertex = -1;
  int conditionedVertex = -1;

  auto operator<=>(const ConditioningVertexCorrespondence &) const = default;
};

struct ConditioningFaceCorrespondence {
  int rawFace = -1;
  int conditionedFace = -1;

  auto operator<=>(const ConditioningFaceCorrespondence &) const = default;
};

struct ConditioningFieldCorrespondence {
  int rawFace = -1;
  int conditionedFace = -1;
  // conditioned branch i reads raw branch branchPermutation[i].
  std::array<int, 4> branchPermutation{0, 1, 2, 3};

  auto operator<=>(const ConditioningFieldCorrespondence &) const = default;
};

struct ConditioningFeatureCorrespondence {
  int rawFeature = -1;
  RawConditioningFeatureEdge conditionedEdge;

  auto operator<=>(const ConditioningFeatureCorrespondence &) const = default;
};

struct ConditioningCertificate {
  std::string policyId;
  std::uint64_t rawInputDigest = 0;
  std::uint64_t conditionedSemanticDigest = 0;
  std::vector<ConditioningVertexCorrespondence> vertices;
  std::vector<ConditioningFaceCorrespondence> faces;
  std::vector<ConditioningFieldCorrespondence> fields;
  std::vector<ConditioningFeatureCorrespondence> features;
  std::vector<ConditioningOperationRecord> operations;
};

enum class ConditioningFailureCode : std::uint8_t {
  NonFiniteInput,
  InvalidSourceConnectivity,
  ExactDegenerateFace,
  SliverPolicyExceeded,
  FeatureCorrespondenceConflict,
  FieldShapeInvalid,
  FieldTransportInadmissible,
  ConditioningPolicyUnrepresentable,
  CertificateMismatch,
};

enum class ConditioningFailureClass : std::uint8_t {
  FatalInadmissible,
  RegularizableDegeneracy,
};

struct ConditioningFailure {
  ConditioningFailureCode code = ConditioningFailureCode::ConditioningPolicyUnrepresentable;
  ConditioningFailureClass classification = ConditioningFailureClass::FatalInadmissible;
  std::string locus;
  std::string evidence;
  std::string policyId;
  std::uint64_t rawInputDigest = 0;
};

struct ConditionedSourceProduct {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd rawCrossField;
  std::vector<RawConditioningFeatureEdge> hardFeatures;
  std::uint64_t rawInputDigest = 0;
  std::uint64_t conditionedSemanticDigest = 0;
  std::string policyId;
  ConditioningCertificate certificate;
};

using ConditioningResult =
    geometry::ProducerOutcome<ConditionedSourceProduct, ConditioningFailure>;

[[nodiscard]] std::string
conditioning_failure_code_name(ConditioningFailureCode code);

[[nodiscard]] ConditioningResult
condition_surface_cell_input(const RawSurfaceCellInput &raw,
                             const ConditioningPolicy &policy);

/** Independent certificate oracle; nullopt means the produced product validates. */
[[nodiscard]] std::optional<ConditioningFailure>
validate_conditioned_source_product(const RawSurfaceCellInput &raw,
                                    const ConditioningPolicy &policy,
                                    const ConditionedSourceProduct &product);

/** Independent typed-refusal oracle; nullopt means the refusal is derivable. */
[[nodiscard]] std::optional<ConditioningFailure>
validate_conditioning_failure(const RawSurfaceCellInput &raw,
                              const ConditioningPolicy &policy,
                              const ConditioningFailure &failure);

[[nodiscard]] std::uint64_t
conditioning_raw_input_digest(const RawSurfaceCellInput &raw);

[[nodiscard]] std::uint64_t conditioning_semantic_digest(
    const ConditionedSourceProduct &product, const ConditioningPolicy &policy);

} // namespace directional::pipeline
