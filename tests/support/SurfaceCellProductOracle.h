#pragma once

#include <string>
#include <vector>

#include <Eigen/Core>

#include <directional/pipeline/RemeshPipeline.h>

namespace directional::tests::surface_cell_oracle {

struct ConnectedComponentCount {
  int value = 0;
  friend bool operator==(const ConnectedComponentCount &,
                         const ConnectedComponentCount &) = default;
};

struct BoundaryLoopCount {
  int value = 0;
  friend bool operator==(const BoundaryLoopCount &,
                         const BoundaryLoopCount &) = default;
};

struct EulerCharacteristic {
  int value = 0;
  friend bool operator==(const EulerCharacteristic &,
                         const EulerCharacteristic &) = default;
};

struct TopologySummary {
  ConnectedComponentCount connectedComponents;
  BoundaryLoopCount boundaryLoops;
  EulerCharacteristic eulerCharacteristic;
  friend bool operator==(const TopologySummary &,
                         const TopologySummary &) = default;
};

enum class TopologyExpectationKind {
  MatchSource,
  Exact,
};

struct TopologyExpectation {
  TopologyExpectationKind kind = TopologyExpectationKind::MatchSource;
  TopologySummary exact;

  static TopologyExpectation match_source();
  static TopologyExpectation exact_topology(
      ConnectedComponentCount connectedComponents,
      BoundaryLoopCount boundaryLoops,
      EulerCharacteristic eulerCharacteristic);
};

struct ProductExpectation {
  TopologyExpectation topology = TopologyExpectation::match_source();
};

enum class OracleIssueClass {
  ExactInvariant,
  GeometryDiagnostic,
};

enum class OracleIssueCode {
  InvalidSourceSchema,
  EmptyOutput,
  InvalidOutputVertexSchema,
  NonFiniteOutputVertex,
  NonQuadOutput,
  InvalidDegreeMetadata,
  OutOfRangeOutputIndex,
  RepeatedFaceCorner,
  DuplicateFace,
  ZeroAreaFace,
  NonManifoldEdge,
  InconsistentWinding,
  BrokenBoundaryIncidence,
  ConnectedComponentMismatch,
  BoundaryLoopMismatch,
  EulerCharacteristicMismatch,
  VertexProvenanceCardinality,
  InvalidVertexProvenance,
  VertexLineageCardinality,
  DuplicateVertexLineage,
  MissingVertexLineage,
  InvalidVertexLineageSource,
  FaceLineageCardinality,
  DuplicateFaceLineage,
  MissingFaceLineage,
  InvalidFaceLineage,
  RequestedBackendMismatch,
  ExecutedBackendMismatch,
  FallbackObserved,
  RecoveryObserved,
  OutputOriginMismatch,
  TerminalFailureObserved,
};

const char *oracle_issue_code_name(OracleIssueCode code);

struct OracleIssue {
  OracleIssueCode code = OracleIssueCode::InvalidSourceSchema;
  OracleIssueClass issueClass = OracleIssueClass::ExactInvariant;
  std::string detail;
};

struct CanonicalVertexIdentity {
  std::string value;
  friend bool operator==(const CanonicalVertexIdentity &,
                         const CanonicalVertexIdentity &) = default;
  friend bool operator<(const CanonicalVertexIdentity &lhs,
                        const CanonicalVertexIdentity &rhs) {
    return lhs.value < rhs.value;
  }
};

struct CanonicalFaceIdentity {
  std::string value;
  friend bool operator==(const CanonicalFaceIdentity &,
                         const CanonicalFaceIdentity &) = default;
  friend bool operator<(const CanonicalFaceIdentity &lhs,
                        const CanonicalFaceIdentity &rhs) {
    return lhs.value < rhs.value;
  }
};

struct CanonicalProductRecord {
  TopologySummary topology;
  std::vector<CanonicalVertexIdentity> vertices;
  std::vector<CanonicalFaceIdentity> faces;
  std::string requestedBackend;
  std::string executedBackend;
  SurfaceCellOutputOrigin outputOrigin = SurfaceCellOutputOrigin::None;

  friend bool operator==(const CanonicalProductRecord &,
                         const CanonicalProductRecord &) = default;
};

struct ProductOracleReport {
  TopologySummary sourceTopology;
  TopologySummary outputTopology;
  CanonicalProductRecord canonicalRecord;
  std::vector<OracleIssue> issues;

  [[nodiscard]] bool ok() const { return issues.empty(); }
  [[nodiscard]] bool has_issue(OracleIssueCode code) const;
  [[nodiscard]] std::string describe() const;
};

ProductOracleReport inspect_surface_cell_product(
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const pipeline::RemeshResult &result,
    const ProductExpectation &expectation = ProductExpectation{});

} // namespace directional::tests::surface_cell_oracle
