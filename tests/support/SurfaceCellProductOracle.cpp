#include "SurfaceCellProductOracle.h"

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <utility>

namespace directional::tests::surface_cell_oracle {
namespace {

struct SourceVertexDomain;
struct SourceFaceDomain;
struct OutputVertexDomain;
struct OutputFaceDomain;

template <typename Domain> struct DomainIndex {
  int value = -1;
  friend bool operator==(const DomainIndex &, const DomainIndex &) = default;
  friend bool operator<(const DomainIndex &lhs, const DomainIndex &rhs) {
    return lhs.value < rhs.value;
  }
};

using SourceVertexIndex = DomainIndex<SourceVertexDomain>;
using SourceFaceIndex = DomainIndex<SourceFaceDomain>;
using OutputVertexIndex = DomainIndex<OutputVertexDomain>;
using OutputFaceIndex = DomainIndex<OutputFaceDomain>;

template <typename VertexIndex> struct UndirectedEdge {
  VertexIndex first;
  VertexIndex second;

  static UndirectedEdge from(VertexIndex from, VertexIndex to) {
    if (to < from) {
      std::swap(from, to);
    }
    return {from, to};
  }

  friend bool operator<(const UndirectedEdge &lhs,
                        const UndirectedEdge &rhs) {
    return std::tie(lhs.first, lhs.second) <
           std::tie(rhs.first, rhs.second);
  }
};

template <typename VertexIndex, typename FaceIndex> struct DirectedEdge {
  VertexIndex from;
  VertexIndex to;
  FaceIndex face;
};

template <typename VertexIndex, typename FaceIndex> struct MeshIncidence {
  std::map<UndirectedEdge<VertexIndex>,
           std::vector<DirectedEdge<VertexIndex, FaceIndex>>>
      edges;
  std::set<VertexIndex> usedVertices;
  std::set<FaceIndex> validFaces;
  std::vector<std::vector<FaceIndex>> faceAdjacency;
  int validFaceCount = 0;
};

void add_issue(ProductOracleReport &report, const OracleIssueCode code,
               const std::string &detail,
               const OracleIssueClass issueClass =
                   OracleIssueClass::ExactInvariant) {
  report.issues.push_back({code, issueClass, detail});
}

template <typename VertexIndex, typename FaceIndex>
MeshIncidence<VertexIndex, FaceIndex>
build_incidence(const Eigen::MatrixXi &faces, const int vertexCount,
                const int arity) {
  MeshIncidence<VertexIndex, FaceIndex> incidence;
  incidence.faceAdjacency.resize(static_cast<std::size_t>(faces.rows()));
  if (faces.cols() != arity) {
    return incidence;
  }

  for (int row = 0; row < faces.rows(); ++row) {
    std::vector<VertexIndex> cycle;
    cycle.reserve(static_cast<std::size_t>(arity));
    std::set<VertexIndex> unique;
    bool valid = true;
    for (int corner = 0; corner < arity; ++corner) {
      const VertexIndex vertex{faces(row, corner)};
      if (vertex.value < 0 || vertex.value >= vertexCount ||
          !unique.insert(vertex).second) {
        valid = false;
      }
      cycle.push_back(vertex);
    }
    if (!valid) {
      continue;
    }

    const FaceIndex face{row};
    ++incidence.validFaceCount;
    incidence.validFaces.insert(face);
    for (const VertexIndex vertex : cycle) {
      incidence.usedVertices.insert(vertex);
    }
    for (int edge = 0; edge < arity; ++edge) {
      const VertexIndex from = cycle[static_cast<std::size_t>(edge)];
      const VertexIndex to =
          cycle[static_cast<std::size_t>((edge + 1) % arity)];
      incidence.edges[UndirectedEdge<VertexIndex>::from(from, to)].push_back(
          {from, to, face});
    }
  }

  for (const auto &[edge, incident] : incidence.edges) {
    (void)edge;
    for (std::size_t first = 0; first < incident.size(); ++first) {
      for (std::size_t second = first + 1; second < incident.size();
           ++second) {
        incidence.faceAdjacency[static_cast<std::size_t>(
            incident[first].face.value)]
            .push_back(incident[second].face);
        incidence.faceAdjacency[static_cast<std::size_t>(
            incident[second].face.value)]
            .push_back(incident[first].face);
      }
    }
  }
  return incidence;
}

template <typename VertexIndex, typename FaceIndex>
TopologySummary summarize_topology(
    const MeshIncidence<VertexIndex, FaceIndex> &incidence,
    const int faceRows) {
  int connectedComponents = 0;
  std::vector<bool> visited(static_cast<std::size_t>(faceRows), false);
  for (const FaceIndex seedFace : incidence.validFaces) {
    const int seed = seedFace.value;
    if (visited[static_cast<std::size_t>(seed)]) {
      continue;
    }
    ++connectedComponents;
    std::queue<FaceIndex> pending;
    pending.push(FaceIndex{seed});
    visited[static_cast<std::size_t>(seed)] = true;
    while (!pending.empty()) {
      const FaceIndex face = pending.front();
      pending.pop();
      for (const FaceIndex adjacent :
           incidence.faceAdjacency[static_cast<std::size_t>(face.value)]) {
        if (!visited[static_cast<std::size_t>(adjacent.value)]) {
          visited[static_cast<std::size_t>(adjacent.value)] = true;
          pending.push(adjacent);
        }
      }
    }
  }

  std::map<VertexIndex, std::vector<VertexIndex>> boundaryAdjacency;
  for (const auto &[edge, incident] : incidence.edges) {
    if (incident.size() == 1U) {
      boundaryAdjacency[edge.first].push_back(edge.second);
      boundaryAdjacency[edge.second].push_back(edge.first);
    }
  }
  int boundaryLoops = 0;
  std::set<VertexIndex> visitedBoundary;
  for (const auto &[seed, adjacent] : boundaryAdjacency) {
    (void)adjacent;
    if (!visitedBoundary.insert(seed).second) {
      continue;
    }
    ++boundaryLoops;
    std::queue<VertexIndex> pending;
    pending.push(seed);
    while (!pending.empty()) {
      const VertexIndex vertex = pending.front();
      pending.pop();
      for (const VertexIndex next : boundaryAdjacency[vertex]) {
        if (visitedBoundary.insert(next).second) {
          pending.push(next);
        }
      }
    }
  }

  return {
      ConnectedComponentCount{connectedComponents},
      BoundaryLoopCount{boundaryLoops},
      EulerCharacteristic{static_cast<int>(incidence.usedVertices.size()) -
                          static_cast<int>(incidence.edges.size()) +
                          incidence.validFaceCount},
  };
}

std::array<int, 4> canonical_quad(std::array<int, 4> cycle) {
  std::array<int, 4> best = cycle;
  for (int reversed = 0; reversed < 2; ++reversed) {
    for (int rotation = 0; rotation < 4; ++rotation) {
      std::array<int, 4> candidate{};
      for (int corner = 0; corner < 4; ++corner) {
        const int offset = reversed == 0 ? corner : -corner;
        candidate[static_cast<std::size_t>(corner)] =
            cycle[static_cast<std::size_t>((rotation + offset + 8) % 4)];
      }
      best = std::min(best, candidate);
    }
  }
  return best;
}

std::array<std::string, 4>
canonical_quad(std::array<std::string, 4> cycle) {
  std::array<std::string, 4> best = cycle;
  for (int reversed = 0; reversed < 2; ++reversed) {
    for (int rotation = 0; rotation < 4; ++rotation) {
      std::array<std::string, 4> candidate{};
      for (int corner = 0; corner < 4; ++corner) {
        const int offset = reversed == 0 ? corner : -corner;
        candidate[static_cast<std::size_t>(corner)] =
            cycle[static_cast<std::size_t>((rotation + offset + 8) % 4)];
      }
      best = std::min(best, candidate);
    }
  }
  return best;
}

std::string exact_scalar_token(double value) {
  if (value == 0.0) {
    value = 0.0;
  }
  const std::uint64_t bits = std::bit_cast<std::uint64_t>(value);
  std::ostringstream out;
  out << std::hex << std::setw(16) << std::setfill('0') << bits;
  return out.str();
}

std::string exact_vector_token(const Eigen::Vector3d &value) {
  return exact_scalar_token(value.x()) + "," +
         exact_scalar_token(value.y()) + "," +
         exact_scalar_token(value.z());
}

bool valid_source_face(const SourceFaceIndex face,
                       const Eigen::MatrixXi &sourceFaces,
                       const int sourceVertexCount) {
  if (face.value < 0 || face.value >= sourceFaces.rows() ||
      sourceFaces.cols() != 3) {
    return false;
  }
  for (int corner = 0; corner < 3; ++corner) {
    const SourceVertexIndex vertex{sourceFaces(face.value, corner)};
    if (vertex.value < 0 || vertex.value >= sourceVertexCount) {
      return false;
    }
  }
  return true;
}

bool finite_surface_point(const geometry::SurfacePoint &point) {
  return point.barycentric.allFinite() && point.position.allFinite();
}

bool valid_source_point(const geometry::SurfacePoint &point,
                        const Eigen::MatrixXi &sourceFaces,
                        const int sourceVertexCount) {
  return valid_source_face(SourceFaceIndex{point.face}, sourceFaces,
                           sourceVertexCount) &&
         finite_surface_point(point);
}

std::string source_point_token(const geometry::SurfacePoint &point,
                               const Eigen::MatrixXd &sourceVertices,
                               const Eigen::MatrixXi &sourceFaces) {
  if (!valid_source_point(point, sourceFaces, sourceVertices.rows())) {
    return "invalid-source-point";
  }
  Eigen::Vector3d reconstructed = Eigen::Vector3d::Zero();
  for (int corner = 0; corner < 3; ++corner) {
    const SourceVertexIndex vertex{sourceFaces(point.face, corner)};
    reconstructed += point.barycentric(corner) *
                     sourceVertices.row(vertex.value).transpose();
  }
  return exact_vector_token(reconstructed);
}

std::string join_cycle(const std::array<std::string, 4> &cycle) {
  return cycle[0] + ";" + cycle[1] + ";" + cycle[2] + ";" + cycle[3];
}

} // namespace

TopologyExpectation TopologyExpectation::match_source() {
  return {TopologyExpectationKind::MatchSource, {}};
}

TopologyExpectation TopologyExpectation::exact_topology(
    const ConnectedComponentCount connectedComponents,
    const BoundaryLoopCount boundaryLoops,
    const EulerCharacteristic eulerCharacteristic) {
  return {TopologyExpectationKind::Exact,
          {connectedComponents, boundaryLoops, eulerCharacteristic}};
}

const char *oracle_issue_code_name(const OracleIssueCode code) {
  switch (code) {
  case OracleIssueCode::InvalidSourceSchema:
    return "InvalidSourceSchema";
  case OracleIssueCode::EmptyOutput:
    return "EmptyOutput";
  case OracleIssueCode::InvalidOutputVertexSchema:
    return "InvalidOutputVertexSchema";
  case OracleIssueCode::NonFiniteOutputVertex:
    return "NonFiniteOutputVertex";
  case OracleIssueCode::NonQuadOutput:
    return "NonQuadOutput";
  case OracleIssueCode::InvalidDegreeMetadata:
    return "InvalidDegreeMetadata";
  case OracleIssueCode::OutOfRangeOutputIndex:
    return "OutOfRangeOutputIndex";
  case OracleIssueCode::RepeatedFaceCorner:
    return "RepeatedFaceCorner";
  case OracleIssueCode::DuplicateFace:
    return "DuplicateFace";
  case OracleIssueCode::ZeroAreaFace:
    return "ZeroAreaFace";
  case OracleIssueCode::NonManifoldEdge:
    return "NonManifoldEdge";
  case OracleIssueCode::InconsistentWinding:
    return "InconsistentWinding";
  case OracleIssueCode::BrokenBoundaryIncidence:
    return "BrokenBoundaryIncidence";
  case OracleIssueCode::ConnectedComponentMismatch:
    return "ConnectedComponentMismatch";
  case OracleIssueCode::BoundaryLoopMismatch:
    return "BoundaryLoopMismatch";
  case OracleIssueCode::EulerCharacteristicMismatch:
    return "EulerCharacteristicMismatch";
  case OracleIssueCode::VertexProvenanceCardinality:
    return "VertexProvenanceCardinality";
  case OracleIssueCode::InvalidVertexProvenance:
    return "InvalidVertexProvenance";
  case OracleIssueCode::VertexLineageCardinality:
    return "VertexLineageCardinality";
  case OracleIssueCode::DuplicateVertexLineage:
    return "DuplicateVertexLineage";
  case OracleIssueCode::MissingVertexLineage:
    return "MissingVertexLineage";
  case OracleIssueCode::InvalidVertexLineageSource:
    return "InvalidVertexLineageSource";
  case OracleIssueCode::FaceLineageCardinality:
    return "FaceLineageCardinality";
  case OracleIssueCode::DuplicateFaceLineage:
    return "DuplicateFaceLineage";
  case OracleIssueCode::MissingFaceLineage:
    return "MissingFaceLineage";
  case OracleIssueCode::InvalidFaceLineage:
    return "InvalidFaceLineage";
  case OracleIssueCode::RequestedBackendMismatch:
    return "RequestedBackendMismatch";
  case OracleIssueCode::ExecutedBackendMismatch:
    return "ExecutedBackendMismatch";
  case OracleIssueCode::FallbackObserved:
    return "FallbackObserved";
  case OracleIssueCode::RecoveryObserved:
    return "RecoveryObserved";
  case OracleIssueCode::OutputOriginMismatch:
    return "OutputOriginMismatch";
  case OracleIssueCode::TerminalFailureObserved:
    return "TerminalFailureObserved";
  }
  return "Unknown";
}

bool ProductOracleReport::has_issue(const OracleIssueCode code) const {
  return std::any_of(issues.begin(), issues.end(),
                     [&](const OracleIssue &issue) {
                       return issue.code == code;
                     });
}

std::string ProductOracleReport::describe() const {
  std::ostringstream out;
  for (std::size_t index = 0; index < issues.size(); ++index) {
    if (index != 0U) {
      out << " | ";
    }
    out << oracle_issue_code_name(issues[index].code) << ":"
        << issues[index].detail;
  }
  return out.str();
}

ProductOracleReport inspect_surface_cell_product(
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const pipeline::RemeshResult &result,
    const ProductExpectation &expectation) {
  ProductOracleReport report;
  const pipeline::RemeshProduct emptyProduct;
  const pipeline::RemeshProduct &product =
      result.is_produced() ? result.product() : emptyProduct;

  bool sourceSchemaValid = sourceVertices.cols() == 3 &&
                           sourceVertices.rows() > 0 &&
                           sourceVertices.allFinite() &&
                           sourceFaces.cols() == 3 && sourceFaces.rows() > 0;
  if (sourceSchemaValid) {
    for (int face = 0; face < sourceFaces.rows(); ++face) {
      if (!valid_source_face(SourceFaceIndex{face}, sourceFaces,
                             sourceVertices.rows())) {
        sourceSchemaValid = false;
        break;
      }
    }
  }
  if (!sourceSchemaValid) {
    add_issue(report, OracleIssueCode::InvalidSourceSchema,
              "source must be finite #V-by-3 vertices and valid #F-by-3 "
              "triangle indices");
  }

  const auto sourceIncidence =
      build_incidence<SourceVertexIndex, SourceFaceIndex>(
          sourceFaces, sourceVertices.rows(), 3);
  report.sourceTopology = summarize_topology(sourceIncidence,
                                             sourceFaces.rows());

  if (product.vertices.rows() <= 0 || product.faces.rows() <= 0) {
    add_issue(report, OracleIssueCode::EmptyOutput,
              "output vertices and faces must both be non-empty");
  }
  if (product.vertices.cols() != 3) {
    add_issue(report, OracleIssueCode::InvalidOutputVertexSchema,
              "output vertices must have three columns");
  } else {
    for (int vertex = 0; vertex < product.vertices.rows(); ++vertex) {
      if (!product.vertices.row(vertex).allFinite()) {
        add_issue(report, OracleIssueCode::NonFiniteOutputVertex,
                  "output vertex " + std::to_string(vertex) +
                      " is non-finite");
      }
    }
  }
  if (product.faces.cols() != 4) {
    add_issue(report, OracleIssueCode::NonQuadOutput,
              "output faces must have exactly four columns");
  }
  if (product.degrees.size() != product.faces.rows() ||
      (product.degrees.size() > 0 &&
       !(product.degrees.array() == 4).all())) {
    add_issue(report, OracleIssueCode::InvalidDegreeMetadata,
              "face degree metadata must contain one degree-four value per "
              "output face");
  }

  std::set<std::array<int, 4>> canonicalFaces;
  if (product.faces.cols() == 4) {
    for (int face = 0; face < product.faces.rows(); ++face) {
      std::array<int, 4> cycle{};
      bool indicesValid = true;
      std::set<OutputVertexIndex> unique;
      for (int corner = 0; corner < 4; ++corner) {
        const OutputVertexIndex vertex{product.faces(face, corner)};
        cycle[static_cast<std::size_t>(corner)] = vertex.value;
        if (vertex.value < 0 || vertex.value >= product.vertices.rows()) {
          indicesValid = false;
          add_issue(report, OracleIssueCode::OutOfRangeOutputIndex,
                    "face " + std::to_string(face) + " corner " +
                        std::to_string(corner));
        }
        unique.insert(vertex);
      }
      if (unique.size() != 4U) {
        add_issue(report, OracleIssueCode::RepeatedFaceCorner,
                  "face " + std::to_string(face));
      }
      if (!indicesValid || unique.size() != 4U) {
        continue;
      }

      if (!canonicalFaces.insert(canonical_quad(cycle)).second) {
        add_issue(report, OracleIssueCode::DuplicateFace,
                  "face " + std::to_string(face) +
                      " duplicates a cyclic/reversed face");
      }

      if (product.vertices.cols() == 3) {
        Eigen::Vector3d doubledArea = Eigen::Vector3d::Zero();
        double faceScaleSquared = 0.0;
        for (int corner = 0; corner < 4; ++corner) {
          const Eigen::Vector3d current =
              product.vertices.row(cycle[static_cast<std::size_t>(corner)])
                  .transpose();
          const Eigen::Vector3d next =
              product.vertices
                  .row(cycle[static_cast<std::size_t>((corner + 1) % 4)])
                  .transpose();
          doubledArea += current.cross(next);
          faceScaleSquared =
              std::max(faceScaleSquared, (next - current).squaredNorm());
        }
        const double diagnosticTolerance =
            64.0 * std::numeric_limits<double>::epsilon() *
            std::max(faceScaleSquared, std::numeric_limits<double>::min());
        if (!doubledArea.allFinite() ||
            doubledArea.norm() <= diagnosticTolerance) {
          add_issue(report, OracleIssueCode::ZeroAreaFace,
                    "face " + std::to_string(face) +
                        " is zero/near-zero under the local scale-relative "
                        "diagnostic",
                    OracleIssueClass::GeometryDiagnostic);
        }
      }
    }
  }

  const auto outputIncidence =
      build_incidence<OutputVertexIndex, OutputFaceIndex>(
          product.faces, product.vertices.rows(), 4);
  for (const auto &[edge, incident] : outputIncidence.edges) {
    if (incident.size() > 2U) {
      add_issue(report, OracleIssueCode::NonManifoldEdge,
                "edge (" + std::to_string(edge.first.value) + "," +
                    std::to_string(edge.second.value) + ") has " +
                    std::to_string(incident.size()) + " incident faces");
    } else if (incident.size() == 2U) {
      const bool opposite = incident[0].from == incident[1].to &&
                            incident[0].to == incident[1].from;
      if (!opposite) {
        add_issue(report, OracleIssueCode::InconsistentWinding,
                  "two faces traverse edge (" +
                      std::to_string(edge.first.value) + "," +
                      std::to_string(edge.second.value) +
                      ") in the same direction");
      }
    }
  }

  std::map<OutputVertexIndex, int> boundaryDegree;
  for (const auto &[edge, incident] : outputIncidence.edges) {
    if (incident.size() == 1U) {
      ++boundaryDegree[edge.first];
      ++boundaryDegree[edge.second];
    }
  }
  for (const auto &[vertex, degree] : boundaryDegree) {
    if (degree != 2) {
      add_issue(report, OracleIssueCode::BrokenBoundaryIncidence,
                "boundary vertex " + std::to_string(vertex.value) +
                    " has degree " + std::to_string(degree));
    }
  }

  report.outputTopology = summarize_topology(outputIncidence,
                                             product.faces.rows());
  const TopologySummary expectedTopology =
      expectation.topology.kind == TopologyExpectationKind::MatchSource
          ? report.sourceTopology
          : expectation.topology.exact;
  if (report.outputTopology.connectedComponents !=
      expectedTopology.connectedComponents) {
    add_issue(report, OracleIssueCode::ConnectedComponentMismatch,
              "expected " +
                  std::to_string(expectedTopology.connectedComponents.value) +
                  ", observed " +
                  std::to_string(
                      report.outputTopology.connectedComponents.value));
  }
  if (report.outputTopology.boundaryLoops != expectedTopology.boundaryLoops) {
    add_issue(report, OracleIssueCode::BoundaryLoopMismatch,
              "expected " +
                  std::to_string(expectedTopology.boundaryLoops.value) +
                  ", observed " +
                  std::to_string(report.outputTopology.boundaryLoops.value));
  }
  if (report.outputTopology.eulerCharacteristic !=
      expectedTopology.eulerCharacteristic) {
    add_issue(report, OracleIssueCode::EulerCharacteristicMismatch,
              "expected " +
                  std::to_string(
                      expectedTopology.eulerCharacteristic.value) +
                  ", observed " +
                  std::to_string(
                      report.outputTopology.eulerCharacteristic.value));
  }

  if (product.outputVertexProvenance.size() !=
      static_cast<std::size_t>(product.vertices.rows())) {
    add_issue(report, OracleIssueCode::VertexProvenanceCardinality,
              "expected one provenance record per output vertex");
  }
  for (std::size_t index = 0; index < product.outputVertexProvenance.size();
       ++index) {
    if (!valid_source_point(product.outputVertexProvenance[index], sourceFaces,
                            sourceVertices.rows())) {
      add_issue(report, OracleIssueCode::InvalidVertexProvenance,
                "provenance record " + std::to_string(index) +
                    " has invalid source support");
    }
  }

  if (product.outputVertexLineage.size() !=
      static_cast<std::size_t>(product.vertices.rows())) {
    add_issue(report, OracleIssueCode::VertexLineageCardinality,
              "expected one lineage record per output vertex");
  }
  std::vector<const geometry::PureQuadVertexLineage *> lineageByVertex(
      static_cast<std::size_t>(
          product.vertices.rows() > 0 ? product.vertices.rows() : 0),
      nullptr);
  for (const auto &lineage : product.outputVertexLineage) {
    const OutputVertexIndex outputVertex{lineage.outputVertex};
    if (outputVertex.value < 0 ||
        outputVertex.value >= product.vertices.rows()) {
      add_issue(report, OracleIssueCode::InvalidVertexLineageSource,
                "lineage has an out-of-domain output vertex");
      continue;
    }
    auto &slot = lineageByVertex[static_cast<std::size_t>(outputVertex.value)];
    if (slot != nullptr) {
      add_issue(report, OracleIssueCode::DuplicateVertexLineage,
                "output vertex " + std::to_string(outputVertex.value));
      continue;
    }
    slot = &lineage;

    bool sourceValid = false;
    if (lineage.kind == geometry::PureQuadVertexLineageKind::SourceTriangle) {
      sourceValid = valid_source_point(lineage.sourcePoint, sourceFaces,
                                       sourceVertices.rows());
    } else if (lineage.kind ==
               geometry::PureQuadVertexLineageKind::OrderedFeatureInterval) {
      sourceValid = lineage.featureInterval.valid() &&
                    valid_source_point(lineage.featureInterval.start,
                                       sourceFaces, sourceVertices.rows()) &&
                    valid_source_point(lineage.featureInterval.end,
                                       sourceFaces, sourceVertices.rows()) &&
                    std::isfinite(lineage.featureInterval.parameter);
    }
    if (!sourceValid) {
      add_issue(report, OracleIssueCode::InvalidVertexLineageSource,
                "output vertex " + std::to_string(outputVertex.value) +
                    " has invalid typed source lineage");
    }
  }
  for (std::size_t vertex = 0; vertex < lineageByVertex.size(); ++vertex) {
    if (lineageByVertex[vertex] == nullptr) {
      add_issue(report, OracleIssueCode::MissingVertexLineage,
                "output vertex " + std::to_string(vertex));
    }
  }

  if (product.outputQuadLineage.size() !=
      static_cast<std::size_t>(product.faces.rows())) {
    add_issue(report, OracleIssueCode::FaceLineageCardinality,
              "expected one lineage record per output face");
  }
  std::vector<const geometry::PureQuadFaceLineage *> lineageByFace(
      static_cast<std::size_t>(
          product.faces.rows() > 0 ? product.faces.rows() : 0),
      nullptr);
  for (const auto &lineage : product.outputQuadLineage) {
    const OutputFaceIndex outputFace{lineage.outputQuad};
    if (outputFace.value < 0 || outputFace.value >= product.faces.rows() ||
        lineage.sourcePatch < 0 || lineage.operationLocalQuad < 0) {
      add_issue(report, OracleIssueCode::InvalidFaceLineage,
                "face lineage has an invalid output/source-patch domain");
      continue;
    }
    auto &slot = lineageByFace[static_cast<std::size_t>(outputFace.value)];
    if (slot != nullptr) {
      add_issue(report, OracleIssueCode::DuplicateFaceLineage,
                "output face " + std::to_string(outputFace.value));
      continue;
    }
    slot = &lineage;
  }
  for (std::size_t face = 0; face < lineageByFace.size(); ++face) {
    if (lineageByFace[face] == nullptr) {
      add_issue(report, OracleIssueCode::MissingFaceLineage,
                "output face " + std::to_string(face));
    }
  }

  if (result.diagnostics.requestedBackend != "SurfaceCells") {
    add_issue(report, OracleIssueCode::RequestedBackendMismatch,
              "requested backend was " + result.diagnostics.requestedBackend);
  }
  if (result.diagnostics.executedBackend != "SurfaceCells") {
    add_issue(report, OracleIssueCode::ExecutedBackendMismatch,
              "executed backend was " + result.diagnostics.executedBackend);
  }
  if (result.diagnostics.surfaceCellFallbackPolicy != "Fail" ||
      result.diagnostics.surfaceCellFallbackAttempted ||
      result.diagnostics.surfaceCellUsedLegacyFallback ||
      result.diagnostics.surfaceCellReturnedInputMeshFallback) {
    add_issue(report, OracleIssueCode::FallbackObserved,
              "strict direct output observed fallback policy or execution");
  }
  if (result.diagnostics.surfaceCellSourceGridRecoveryUsed) {
    add_issue(report, OracleIssueCode::RecoveryObserved,
              "source-grid recovery was used");
  }
  if (!result.diagnostics.surfaceCellRemeshOccurred ||
      result.diagnostics.surfaceCellOutputOrigin !=
          SurfaceCellOutputOrigin::CompletedSurfaceCells) {
    add_issue(report, OracleIssueCode::OutputOriginMismatch,
              "output was not completed SurfaceCells production");
  }
  if (result.diagnostics.terminalFailureCode != "None" ||
      !result.diagnostics.terminalFailureStage.empty()) {
    add_issue(report, OracleIssueCode::TerminalFailureObserved,
              result.diagnostics.terminalFailureCode + ":" +
                  result.diagnostics.terminalFailureStage);
  }

  std::vector<CanonicalVertexIdentity> canonicalVerticesByOutput(
      static_cast<std::size_t>(
          product.vertices.rows() > 0 ? product.vertices.rows() : 0));
  for (int vertex = 0; vertex < product.vertices.rows(); ++vertex) {
    std::string identity = "position=";
    if (product.vertices.cols() == 3 &&
        product.vertices.row(vertex).allFinite()) {
      identity += exact_vector_token(product.vertices.row(vertex).transpose());
    } else {
      identity += "invalid";
    }
    identity += "|provenance=";
    if (static_cast<std::size_t>(vertex) <
        product.outputVertexProvenance.size()) {
      identity += source_point_token(
          product.outputVertexProvenance[static_cast<std::size_t>(vertex)],
          sourceVertices, sourceFaces);
    } else {
      identity += "missing";
    }
    identity += "|lineage=";
    const auto *lineage =
        lineageByVertex[static_cast<std::size_t>(vertex)];
    if (lineage == nullptr) {
      identity += "missing";
    } else if (lineage->kind ==
               geometry::PureQuadVertexLineageKind::SourceTriangle) {
      identity += "triangle:" + source_point_token(
                                      lineage->sourcePoint, sourceVertices,
                                      sourceFaces);
    } else {
      identity +=
          "feature:" + source_point_token(lineage->featureInterval.start,
                                           sourceVertices, sourceFaces) +
          "->" + source_point_token(lineage->featureInterval.end,
                                     sourceVertices, sourceFaces) +
          "@" + exact_scalar_token(lineage->featureInterval.parameter);
    }
    canonicalVerticesByOutput[static_cast<std::size_t>(vertex)].value =
        std::move(identity);
  }

  report.canonicalRecord.vertices = canonicalVerticesByOutput;
  std::sort(report.canonicalRecord.vertices.begin(),
            report.canonicalRecord.vertices.end());
  if (product.faces.cols() == 4) {
    for (int face = 0; face < product.faces.rows(); ++face) {
      std::array<std::string, 4> cycle{};
      bool valid = true;
      for (int corner = 0; corner < 4; ++corner) {
        const OutputVertexIndex vertex{product.faces(face, corner)};
        if (vertex.value < 0 || vertex.value >= product.vertices.rows()) {
          valid = false;
          break;
        }
        cycle[static_cast<std::size_t>(corner)] =
            canonicalVerticesByOutput[static_cast<std::size_t>(vertex.value)]
                .value;
      }
      report.canonicalRecord.faces.push_back(
          {valid ? join_cycle(canonical_quad(std::move(cycle)))
                 : "invalid-face"});
    }
  }
  std::sort(report.canonicalRecord.faces.begin(),
            report.canonicalRecord.faces.end());
  report.canonicalRecord.topology = report.outputTopology;
  report.canonicalRecord.requestedBackend =
      result.diagnostics.requestedBackend;
  report.canonicalRecord.executedBackend =
      result.diagnostics.executedBackend;
  report.canonicalRecord.outputOrigin =
      result.diagnostics.surfaceCellOutputOrigin;

  // The closed outcome is consulted only to obtain or withhold its semantic
  // product; production diagnostics remain outside this independent oracle.
  return report;
}

} // namespace directional::tests::surface_cell_oracle
