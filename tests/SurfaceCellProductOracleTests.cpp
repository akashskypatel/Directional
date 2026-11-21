#include <algorithm>
#include <array>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "support/SurfaceCellProductOracle.h"

namespace {

namespace oracle = directional::tests::surface_cell_oracle;

struct IntentRecord {
  const char *intent;
  const char *precondition;
  const char *stimulus;
  const char *independentOracle;
  const char *counterexample;
  const char *evidenceIdentity;

  [[nodiscard]] std::string describe() const {
    std::ostringstream out;
    out << "intent=" << intent << "\nprecondition=" << precondition
        << "\nstimulus=" << stimulus
        << "\nindependent-oracle=" << independentOracle
        << "\ncounterexample=" << counterexample
        << "\nevidence=" << evidenceIdentity;
    return out.str();
  }
};

#define T1_INTENT(INTENT, PRECONDITION, STIMULUS, ORACLE, COUNTEREXAMPLE,       \
                  EVIDENCE)                                                    \
  const IntentRecord intentRecord{INTENT, PRECONDITION, STIMULUS, ORACLE,      \
                                  COUNTEREXAMPLE, EVIDENCE};                    \
  SCOPED_TRACE(intentRecord.describe())

struct HandAuthoredProduct {
  Eigen::MatrixXd sourceVertices;
  Eigen::MatrixXi sourceFaces;
  directional::pipeline::RemeshResult result;
  oracle::ProductExpectation expectation;
};

directional::geometry::SurfacePoint source_vertex_point(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const int sourceVertex) {
  for (int face = 0; face < sourceFaces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      if (sourceFaces(face, corner) != sourceVertex) {
        continue;
      }
      directional::geometry::SurfacePoint point;
      point.face = face;
      point.component = 0;
      point.sheet = 0;
      point.barycentric(corner) = 1.0;
      point.position = sourceVertices.row(sourceVertex).transpose();
      point.squaredDistance = 0.0;
      return point;
    }
  }
  return {};
}

void set_strict_direct_diagnostics(
    directional::pipeline::RemeshResult &result) {
  result.diagnostics.remeshBackend = "SurfaceCells";
  result.diagnostics.requestedBackend = "SurfaceCells";
  result.diagnostics.executedBackend = "SurfaceCells";
  result.diagnostics.surfaceCellFallbackPolicy = "Fail";
  result.diagnostics.surfaceCellFallbackAttempted = false;
  result.diagnostics.surfaceCellUsedLegacyFallback = false;
  result.diagnostics.surfaceCellReturnedInputMeshFallback = false;
  result.diagnostics.surfaceCellRemeshOccurred = true;
  result.diagnostics.surfaceCellSourceGridRecoveryUsed = false;
  result.diagnostics.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::CompletedSurfaceCells;
  result.diagnostics.terminalFailureCode = "None";
  result.diagnostics.terminalFailureStage.clear();
}

HandAuthoredProduct make_product(const Eigen::MatrixXd &sourceVertices,
                                 const Eigen::MatrixXi &sourceFaces,
                                 const Eigen::MatrixXi &outputFaces) {
  HandAuthoredProduct product;
  product.sourceVertices = sourceVertices;
  product.sourceFaces = sourceFaces;
  directional::pipeline::RemeshProduct output;
  output.vertices = sourceVertices;
  output.faces = outputFaces;
  output.degrees =
      Eigen::VectorXi::Constant(outputFaces.rows(), outputFaces.cols());
  product.result = directional::pipeline::RemeshResult::produced(
      std::move(output), directional::pipeline::RemeshProductKind::Meshed,
      true);
  set_strict_direct_diagnostics(product.result);

  for (int vertex = 0; vertex < sourceVertices.rows(); ++vertex) {
    const directional::geometry::SurfacePoint point =
        source_vertex_point(sourceVertices, sourceFaces, vertex);
    product.result.product().outputVertexProvenance.push_back(point);

    directional::geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = vertex;
    lineage.kind =
        directional::geometry::PureQuadVertexLineageKind::SourceTriangle;
    lineage.sourcePoint = point;
    lineage.sourcePatch = 0;
    lineage.localVertex = vertex;
    lineage.sourceComponent = 0;
    lineage.sourceSheet = 0;
    product.result.product().outputVertexLineage.push_back(std::move(lineage));
  }
  for (int face = 0; face < outputFaces.rows(); ++face) {
    directional::geometry::PureQuadFaceLineage lineage;
    lineage.outputQuad = face;
    lineage.sourcePatch = 0;
    lineage.operationLocalQuad = face;
    product.result.product().outputQuadLineage.push_back(lineage);
  }
  return product;
}

HandAuthoredProduct make_single_quad() {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0;
  Eigen::MatrixXi triangles(2, 3);
  triangles << 0, 1, 2, 0, 2, 3;
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  return make_product(vertices, triangles, quads);
}

HandAuthoredProduct make_two_quad_strip() {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0,
      1.0, 0.0, 1.0, 1.0, 0.0, 2.0, 1.0, 0.0;
  Eigen::MatrixXi triangles(4, 3);
  triangles << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  Eigen::MatrixXi quads(2, 4);
  quads << 0, 1, 4, 3, 1, 2, 5, 4;
  return make_product(vertices, triangles, quads);
}

int append_output_vertex(HandAuthoredProduct &product,
                         const Eigen::Vector3d &position) {
  const int vertex = product.result.product().vertices.rows();
  product.result.product().vertices.conservativeResize(vertex + 1, 3);
  product.result.product().vertices.row(vertex) = position.transpose();

  directional::geometry::SurfacePoint point =
      source_vertex_point(product.sourceVertices, product.sourceFaces, 0);
  product.result.product().outputVertexProvenance.push_back(point);
  directional::geometry::PureQuadVertexLineage lineage;
  lineage.outputVertex = vertex;
  lineage.kind =
      directional::geometry::PureQuadVertexLineageKind::SourceTriangle;
  lineage.sourcePoint = point;
  lineage.sourcePatch = 0;
  lineage.localVertex = vertex;
  lineage.sourceComponent = 0;
  lineage.sourceSheet = 0;
  product.result.product().outputVertexLineage.push_back(std::move(lineage));
  return vertex;
}

void append_output_face(HandAuthoredProduct &product,
                        const std::array<int, 4> &vertices) {
  const int face = product.result.product().faces.rows();
  product.result.product().faces.conservativeResize(face + 1, 4);
  for (int corner = 0; corner < 4; ++corner) {
    product.result.product().faces(face, corner) =
        vertices[static_cast<std::size_t>(corner)];
  }
  product.result.product().degrees.conservativeResize(face + 1);
  product.result.product().degrees(face) = 4;
  directional::geometry::PureQuadFaceLineage lineage;
  lineage.outputQuad = face;
  lineage.sourcePatch = 0;
  lineage.operationLocalQuad = face;
  product.result.product().outputQuadLineage.push_back(lineage);
}

oracle::ProductOracleReport inspect(const HandAuthoredProduct &product) {
  return oracle::inspect_surface_cell_product(
      product.sourceVertices, product.sourceFaces, product.result,
      product.expectation);
}

void expect_rejected(const HandAuthoredProduct &product,
                     const oracle::OracleIssueCode issue) {
  const oracle::ProductOracleReport report = inspect(product);
  EXPECT_FALSE(report.ok());
  EXPECT_TRUE(report.has_issue(issue)) << report.describe();
}

void remap_source_point(directional::geometry::SurfacePoint &point,
                        const std::vector<int> &oldFaceToNew) {
  if (point.face >= 0) {
    point.face = oldFaceToNew[static_cast<std::size_t>(point.face)];
  }
}

HandAuthoredProduct permute_rows_and_cycles(const HandAuthoredProduct &source) {
  HandAuthoredProduct permuted = source;

  const std::vector<int> newToOldSourceVertex{2, 5, 1, 4, 0, 3};
  std::vector<int> oldToNewSourceVertex(newToOldSourceVertex.size(), -1);
  for (std::size_t next = 0; next < newToOldSourceVertex.size(); ++next) {
    oldToNewSourceVertex[static_cast<std::size_t>(
        newToOldSourceVertex[next])] = static_cast<int>(next);
    permuted.sourceVertices.row(static_cast<int>(next)) =
        source.sourceVertices.row(newToOldSourceVertex[next]);
  }

  const std::vector<int> newToOldSourceFace{3, 1, 0, 2};
  std::vector<int> oldToNewSourceFace(newToOldSourceFace.size(), -1);
  for (std::size_t next = 0; next < newToOldSourceFace.size(); ++next) {
    const int old = newToOldSourceFace[next];
    oldToNewSourceFace[static_cast<std::size_t>(old)] =
        static_cast<int>(next);
    for (int corner = 0; corner < 3; ++corner) {
      permuted.sourceFaces(static_cast<int>(next), corner) =
          oldToNewSourceVertex[static_cast<std::size_t>(
              source.sourceFaces(old, corner))];
    }
  }

  const std::vector<int> newToOldOutputVertex{4, 0, 5, 1, 3, 2};
  std::vector<int> oldToNewOutputVertex(newToOldOutputVertex.size(), -1);
  permuted.result.product().outputVertexProvenance.clear();
  permuted.result.product().outputVertexLineage.clear();
  for (std::size_t next = 0; next < newToOldOutputVertex.size(); ++next) {
    const int old = newToOldOutputVertex[next];
    oldToNewOutputVertex[static_cast<std::size_t>(old)] =
        static_cast<int>(next);
    permuted.result.product().vertices.row(static_cast<int>(next)) =
        source.result.product().vertices.row(old);

    auto provenance =
        source.result.product().outputVertexProvenance[static_cast<std::size_t>(old)];
    remap_source_point(provenance, oldToNewSourceFace);
    permuted.result.product().outputVertexProvenance.push_back(provenance);

    auto lineage =
        source.result.product().outputVertexLineage[static_cast<std::size_t>(old)];
    lineage.outputVertex = static_cast<int>(next);
    remap_source_point(lineage.sourcePoint, oldToNewSourceFace);
    permuted.result.product().outputVertexLineage.push_back(std::move(lineage));
  }

  const std::vector<int> newToOldOutputFace{1, 0};
  permuted.result.product().outputQuadLineage.clear();
  for (std::size_t next = 0; next < newToOldOutputFace.size(); ++next) {
    const int old = newToOldOutputFace[next];
    const int rotation = static_cast<int>(next) + 1;
    for (int corner = 0; corner < 4; ++corner) {
      const int oldCorner = (rotation - corner + 8) % 4;
      const int oldVertex = source.result.product().faces(old, oldCorner);
      permuted.result.product().faces(static_cast<int>(next), corner) =
          oldToNewOutputVertex[static_cast<std::size_t>(oldVertex)];
    }
    auto lineage =
        source.result.product().outputQuadLineage[static_cast<std::size_t>(old)];
    lineage.outputQuad = static_cast<int>(next);
    lineage.sourcePatch += 10;
    permuted.result.product().outputQuadLineage.push_back(lineage);
  }
  return permuted;
}

TEST(SurfaceCellProductOraclePositive, AcceptsIndependentMinimalDisk) {
  T1_INTENT(
      "accept a valid strict-direct manifold pure-quad disk",
      "hand-authored two-triangle source and one-quad result have obvious "
      "disk topology and complete typed lineage",
      "inspect_surface_cell_product on public source/result records",
      "independent incidence, topology, lineage-domain, and disposition "
      "reconstruction",
      "all later mutation tests change one named public fact",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOraclePositive.AcceptsIndependentMinimalDisk");
  const oracle::ProductOracleReport report = inspect(make_single_quad());
  EXPECT_TRUE(report.ok()) << report.describe();
  EXPECT_EQ(1, report.outputTopology.connectedComponents.value);
  EXPECT_EQ(1, report.outputTopology.boundaryLoops.value);
  EXPECT_EQ(1, report.outputTopology.eulerCharacteristic.value);
}

TEST(SurfaceCellProductOracleSchema, RejectsEmptyOutput) {
  T1_INTENT(
      "reject empty output", "the hand-authored disk is valid before mutation",
      "remove all public output vertices/faces/lineage",
      "non-empty output schema predicate", "vertices=0;faces=0",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsEmptyOutput");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().vertices.resize(0, 3);
  product.result.product().faces.resize(0, 4);
  product.result.product().degrees.resize(0);
  product.result.product().outputVertexProvenance.clear();
  product.result.product().outputVertexLineage.clear();
  product.result.product().outputQuadLineage.clear();
  expect_rejected(product, oracle::OracleIssueCode::EmptyOutput);
}

TEST(SurfaceCellProductOracleSchema, RejectsInvalidVertexShape) {
  T1_INTENT(
      "reject a non-3D public vertex matrix",
      "the hand-authored disk is valid before mutation",
      "truncate the output vertex matrix to two columns",
      "public output vertex-schema predicate", "vertexColumns=2",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsInvalidVertexShape");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().vertices.conservativeResize(product.result.product().vertices.rows(), 2);
  expect_rejected(product,
                  oracle::OracleIssueCode::InvalidOutputVertexSchema);
}

TEST(SurfaceCellProductOracleSchema, RejectsInvalidSourceIndexDomain) {
  T1_INTENT(
      "reject a source triangle outside the source-vertex domain",
      "the hand-authored source has four vertices and valid triangle indices",
      "replace one source corner with index 4",
      "typed source-vertex domain validation before output comparison",
      "sourceFace0=[0,1,4];sourceVertexCount=4",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsInvalidSourceIndexDomain");
  HandAuthoredProduct product = make_single_quad();
  product.sourceFaces(0, 2) = product.sourceVertices.rows();
  expect_rejected(product, oracle::OracleIssueCode::InvalidSourceSchema);
}

TEST(SurfaceCellProductOracleSchema, RejectsNonFiniteVertex) {
  T1_INTENT(
      "reject non-finite output geometry",
      "the hand-authored disk is valid before mutation",
      "replace one coordinate with positive infinity",
      "finite public output-coordinate predicate", "vertex[0].x=+inf",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsNonFiniteVertex");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().vertices(0, 0) = std::numeric_limits<double>::infinity();
  expect_rejected(product, oracle::OracleIssueCode::NonFiniteOutputVertex);
}

TEST(SurfaceCellProductOracleSchema, RejectsOutOfRangeOutputIndex) {
  T1_INTENT(
      "reject an output corner outside the output-vertex domain",
      "the hand-authored disk is valid before mutation",
      "replace one quad corner with index 17",
      "typed output-vertex domain check", "face0=[0,1,2,17]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsOutOfRangeOutputIndex");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().faces(0, 3) = 17;
  expect_rejected(product, oracle::OracleIssueCode::OutOfRangeOutputIndex);
}

TEST(SurfaceCellProductOracleSchema, RejectsNonQuadFaceDegree) {
  T1_INTENT(
      "reject non-quad output arity",
      "the hand-authored disk is valid before mutation",
      "replace the one quad row with a triangle row",
      "exact output face-arity predicate", "faceColumns=3;degree=3",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsNonQuadFaceDegree");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().faces.resize(1, 3);
  product.result.product().faces << 0, 1, 2;
  product.result.product().degrees = Eigen::VectorXi::Constant(1, 3);
  expect_rejected(product, oracle::OracleIssueCode::NonQuadOutput);
}

TEST(SurfaceCellProductOracleSchema, RejectsDegreeMetadataMismatch) {
  T1_INTENT(
      "reject face-degree metadata that contradicts quad arity",
      "the hand-authored disk is valid before mutation",
      "change the one declared face degree from four to three",
      "one degree-four metadata value per output face", "degrees=[3]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleSchema.RejectsDegreeMetadataMismatch");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().degrees(0) = 3;
  expect_rejected(product, oracle::OracleIssueCode::InvalidDegreeMetadata);
}

TEST(SurfaceCellProductOracleFaces, RejectsRepeatedCorner) {
  T1_INTENT(
      "reject a quad with one repeated corner",
      "the hand-authored disk is valid before mutation",
      "duplicate vertex 1 in the face cycle",
      "four distinct typed output-vertex occurrences per face",
      "face0=[0,1,1,3]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleFaces.RejectsRepeatedCorner");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().faces.row(0) << 0, 1, 1, 3;
  expect_rejected(product, oracle::OracleIssueCode::RepeatedFaceCorner);
}

TEST(SurfaceCellProductOracleFaces, RejectsScaleRelativeZeroArea) {
  T1_INTENT(
      "reject a geometrically zero-area quad without using tolerance as "
      "topology identity",
      "the hand-authored disk has four distinct valid corners",
      "make the four output positions collinear",
      "local scale-relative area diagnostic, separate from exact incidence",
      "positions=(0,0),(1,0),(2,0),(3,0)",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleFaces.RejectsScaleRelativeZeroArea");
  HandAuthoredProduct product = make_single_quad();
  for (int vertex = 0; vertex < 4; ++vertex) {
    product.result.product().vertices.row(vertex) << static_cast<double>(vertex), 0.0,
        0.0;
  }
  expect_rejected(product, oracle::OracleIssueCode::ZeroAreaFace);
}

TEST(SurfaceCellProductOracleFaces, RejectsCyclicOrReversedDuplicateFace) {
  T1_INTENT(
      "reject duplicate faces independent of cyclic start and orientation",
      "the hand-authored disk is valid before mutation",
      "append the reversed face cycle starting at corner 2",
      "exact canonical cyclic/reversed output-index cycle",
      "face1=[2,1,0,3] duplicates face0=[0,1,2,3]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleFaces."
      "RejectsCyclicOrReversedDuplicateFace");
  HandAuthoredProduct product = make_single_quad();
  append_output_face(product, {2, 1, 0, 3});
  expect_rejected(product, oracle::OracleIssueCode::DuplicateFace);
}

TEST(SurfaceCellProductOracleIncidence, RejectsEdgeWithMoreThanTwoFaces) {
  T1_INTENT(
      "reject nonmanifold output edge multiplicity",
      "the hand-authored disk has one incident face on edge (0,1)",
      "append two distinct nondegenerate quads incident on edge (0,1)",
      "independently reconstructed undirected-edge incidence",
      "incidence(0,1)=3",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleIncidence."
      "RejectsEdgeWithMoreThanTwoFaces");
  HandAuthoredProduct product = make_single_quad();
  const int v4 = append_output_vertex(product, {0.0, -1.0, 0.0});
  const int v5 = append_output_vertex(product, {1.0, -1.0, 0.0});
  const int v6 = append_output_vertex(product, {1.0, 0.0, 1.0});
  const int v7 = append_output_vertex(product, {0.0, 0.0, 1.0});
  append_output_face(product, {1, 0, v4, v5});
  append_output_face(product, {0, 1, v6, v7});
  expect_rejected(product, oracle::OracleIssueCode::NonManifoldEdge);
}

TEST(SurfaceCellProductOracleIncidence, RejectsEqualSharedEdgeDirection) {
  T1_INTENT(
      "reject equal traversal of a two-face shared edge",
      "the hand-authored two-quad strip traverses its shared edge oppositely",
      "reverse the second face so both traverse edge (1,4) as 1->4",
      "independently reconstructed directed-edge incidence",
      "rightFace=[1,4,5,2]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleIncidence."
      "RejectsEqualSharedEdgeDirection");
  HandAuthoredProduct product = make_two_quad_strip();
  product.result.product().faces.row(1) << 1, 4, 5, 2;
  expect_rejected(product, oracle::OracleIssueCode::InconsistentWinding);
}

TEST(SurfaceCellProductOracleIncidence, RejectsBrokenBoundaryCycle) {
  T1_INTENT(
      "reject boundary incidence that is not a disjoint union of cycles",
      "the hand-authored disk has boundary degree two at every boundary "
      "vertex",
      "append a second quad sharing only output vertex 0",
      "independently reconstructed boundary graph degree",
      "boundaryDegree(vertex0)=4",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleIncidence.RejectsBrokenBoundaryCycle");
  HandAuthoredProduct product = make_single_quad();
  const int v4 = append_output_vertex(product, {-1.0, 0.0, 0.0});
  const int v5 = append_output_vertex(product, {-1.0, -1.0, 0.0});
  const int v6 = append_output_vertex(product, {0.0, -1.0, 0.0});
  append_output_face(product, {0, v4, v5, v6});
  expect_rejected(product, oracle::OracleIssueCode::BrokenBoundaryIncidence);
}

TEST(SurfaceCellProductOracleTopology, RejectsChangedComponentAndEulerStructure) {
  T1_INTENT(
      "reject output topology that differs from the declared source policy",
      "the hand-authored source/result are both one disk with chi=1",
      "append one disjoint nondegenerate quad",
      "independent face components, boundary loops, and V-E+F",
      "output=(components=2,boundaries=2,chi=2)",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleTopology."
      "RejectsChangedComponentAndEulerStructure");
  HandAuthoredProduct product = make_single_quad();
  const int v4 = append_output_vertex(product, {2.0, 0.0, 0.0});
  const int v5 = append_output_vertex(product, {3.0, 0.0, 0.0});
  const int v6 = append_output_vertex(product, {3.0, 1.0, 0.0});
  const int v7 = append_output_vertex(product, {2.0, 1.0, 0.0});
  append_output_face(product, {v4, v5, v6, v7});
  const oracle::ProductOracleReport report = inspect(product);
  EXPECT_TRUE(report.has_issue(
      oracle::OracleIssueCode::ConnectedComponentMismatch));
  EXPECT_TRUE(report.has_issue(oracle::OracleIssueCode::BoundaryLoopMismatch));
  EXPECT_TRUE(report.has_issue(
      oracle::OracleIssueCode::EulerCharacteristicMismatch));
}

TEST(SurfaceCellProductOracleLineage, RejectsMissingVertexProvenance) {
  T1_INTENT(
      "reject incomplete public per-vertex source provenance",
      "the hand-authored disk has one valid provenance record per vertex",
      "remove the final provenance record",
      "public provenance cardinality and source-domain reconstruction",
      "provenanceCount=3;vertexCount=4",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage."
      "RejectsMissingVertexProvenance");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputVertexProvenance.pop_back();
  expect_rejected(product,
                  oracle::OracleIssueCode::VertexProvenanceCardinality);
}

TEST(SurfaceCellProductOracleLineage, RejectsOutOfDomainVertexProvenance) {
  T1_INTENT(
      "reject public provenance outside the source-face domain",
      "the hand-authored disk provenance references one of two triangles",
      "set one provenance source face to 2",
      "typed public provenance source-face range validation",
      "provenance[0].sourceFace=2;sourceFaceCount=2",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage."
      "RejectsOutOfDomainVertexProvenance");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputVertexProvenance.front().face =
      product.sourceFaces.rows();
  expect_rejected(product, oracle::OracleIssueCode::InvalidVertexProvenance);
}

TEST(SurfaceCellProductOracleLineage, RejectsMissingVertexLineage) {
  T1_INTENT(
      "reject incomplete public per-vertex lineage",
      "the hand-authored disk has one valid lineage record per vertex",
      "remove the final vertex-lineage record",
      "typed output-vertex lineage coverage map",
      "lineageCount=3;vertexCount=4",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage.RejectsMissingVertexLineage");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputVertexLineage.pop_back();
  const oracle::ProductOracleReport report = inspect(product);
  EXPECT_TRUE(
      report.has_issue(oracle::OracleIssueCode::VertexLineageCardinality));
  EXPECT_TRUE(report.has_issue(oracle::OracleIssueCode::MissingVertexLineage));
}

TEST(SurfaceCellProductOracleLineage, RejectsDuplicateVertexLineage) {
  T1_INTENT(
      "reject duplicate authority for one output vertex",
      "the hand-authored disk maps each output vertex exactly once",
      "replace vertex 3 lineage identity with outputVertex=0",
      "typed output-vertex lineage uniqueness/coverage map",
      "lineageOutputs=[0,1,2,0]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage."
      "RejectsDuplicateVertexLineage");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputVertexLineage.back().outputVertex = 0;
  expect_rejected(product,
                  oracle::OracleIssueCode::DuplicateVertexLineage);
}

TEST(SurfaceCellProductOracleLineage, RejectsOutOfDomainSourceFace) {
  T1_INTENT(
      "reject vertex lineage outside the source-face domain",
      "the hand-authored disk lineage references one of two source triangles",
      "set one lineage source face to 2",
      "typed source-face range and triangle-index validation",
      "vertexLineage[0].sourceFace=2;sourceFaceCount=2",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage."
      "RejectsOutOfDomainSourceFace");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputVertexLineage.front().sourcePoint.face =
      product.sourceFaces.rows();
  expect_rejected(product,
                  oracle::OracleIssueCode::InvalidVertexLineageSource);
}

TEST(SurfaceCellProductOracleLineage, RejectsMissingFaceLineage) {
  T1_INTENT(
      "reject incomplete public per-face lineage",
      "the hand-authored disk has one valid face-lineage record",
      "remove the face-lineage record", "typed output-face lineage coverage",
      "faceLineageCount=0;faceCount=1",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage.RejectsMissingFaceLineage");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputQuadLineage.clear();
  const oracle::ProductOracleReport report = inspect(product);
  EXPECT_TRUE(report.has_issue(oracle::OracleIssueCode::FaceLineageCardinality));
  EXPECT_TRUE(report.has_issue(oracle::OracleIssueCode::MissingFaceLineage));
}

TEST(SurfaceCellProductOracleLineage, RejectsDuplicateFaceLineage) {
  T1_INTENT(
      "reject duplicate authority for one output face",
      "the hand-authored disk maps its face exactly once",
      "append a second lineage record with outputQuad=0",
      "typed output-face lineage uniqueness/coverage map",
      "faceLineageOutputs=[0,0]",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage.RejectsDuplicateFaceLineage");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputQuadLineage.push_back(
      product.result.product().outputQuadLineage.front());
  expect_rejected(product, oracle::OracleIssueCode::DuplicateFaceLineage);
}

TEST(SurfaceCellProductOracleLineage, RejectsInvalidFaceSourceDomain) {
  T1_INTENT(
      "reject invalid source-patch face lineage",
      "the hand-authored disk face lineage has nonnegative source domains",
      "set sourcePatch to -1",
      "typed output-face and source-patch domain checks", "sourcePatch=-1",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleLineage."
      "RejectsInvalidFaceSourceDomain");
  HandAuthoredProduct product = make_single_quad();
  product.result.product().outputQuadLineage.front().sourcePatch = -1;
  expect_rejected(product, oracle::OracleIssueCode::InvalidFaceLineage);
}

TEST(SurfaceCellProductOracleDisposition, RejectsBackendCorruption) {
  T1_INTENT(
      "reject a non-direct backend disposition",
      "the hand-authored disk declares requested/executed SurfaceCells",
      "change both public backend fields to LegacyInteger",
      "strict requested/executed public disposition predicates",
      "requested=LegacyInteger;executed=LegacyInteger",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleDisposition.RejectsBackendCorruption");
  HandAuthoredProduct product = make_single_quad();
  product.result.diagnostics.requestedBackend = "LegacyInteger";
  product.result.diagnostics.executedBackend = "LegacyInteger";
  const oracle::ProductOracleReport report = inspect(product);
  EXPECT_TRUE(
      report.has_issue(oracle::OracleIssueCode::RequestedBackendMismatch));
  EXPECT_TRUE(
      report.has_issue(oracle::OracleIssueCode::ExecutedBackendMismatch));
}

TEST(SurfaceCellProductOracleDisposition, RejectsFallbackCorruption) {
  T1_INTENT(
      "reject fallback in strict direct production",
      "the hand-authored disk declares Fail policy and no fallback",
      "set fallbackAttempted=true",
      "strict fallback-policy and execution observations",
      "surfaceCellFallbackAttempted=true",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleDisposition.RejectsFallbackCorruption");
  HandAuthoredProduct product = make_single_quad();
  product.result.diagnostics.surfaceCellFallbackAttempted = true;
  expect_rejected(product, oracle::OracleIssueCode::FallbackObserved);
}

TEST(SurfaceCellProductOracleDisposition, RejectsRecoveryCorruption) {
  T1_INTENT(
      "reject source-grid recovery in strict direct production",
      "the hand-authored disk declares recovery unused",
      "set sourceGridRecoveryUsed=true",
      "strict recovery observation",
      "surfaceCellSourceGridRecoveryUsed=true",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleDisposition.RejectsRecoveryCorruption");
  HandAuthoredProduct product = make_single_quad();
  product.result.diagnostics.surfaceCellSourceGridRecoveryUsed = true;
  expect_rejected(product, oracle::OracleIssueCode::RecoveryObserved);
}

TEST(SurfaceCellProductOracleDisposition, RejectsOutputOriginCorruption) {
  T1_INTENT(
      "reject an output not originating from completed surface cells",
      "the hand-authored disk declares CompletedSurfaceCells origin",
      "change origin to InputMeshFallback",
      "typed public output-origin predicate", "origin=InputMeshFallback",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleDisposition."
      "RejectsOutputOriginCorruption");
  HandAuthoredProduct product = make_single_quad();
  product.result.diagnostics.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::InputMeshFallback;
  expect_rejected(product, oracle::OracleIssueCode::OutputOriginMismatch);
}

TEST(SurfaceCellProductOracleDisposition, RejectsTerminalFailureCorruption) {
  T1_INTENT(
      "reject a terminal failure attached to purported direct output",
      "the hand-authored disk declares terminal code None and empty stage",
      "set terminal code/stage to InjectedStageFailure/validation",
      "public terminal disposition observation",
      "terminal=InjectedStageFailure:validation",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleDisposition."
      "RejectsTerminalFailureCorruption");
  HandAuthoredProduct product = make_single_quad();
  product.result.diagnostics.terminalFailureCode = "InjectedStageFailure";
  product.result.diagnostics.terminalFailureStage = "validation";
  expect_rejected(product, oracle::OracleIssueCode::TerminalFailureObserved);
}

TEST(SurfaceCellProductOracleCanonicalization,
     PreservesInputOutputRowCycleAndReversalSemantics) {
  T1_INTENT(
      "preserve canonical semantic facts under permitted representation "
      "changes",
      "the hand-authored two-quad strip and all typed lineage are valid",
      "permute source vertex/face rows, output vertex/face rows, and globally "
      "reverse/rotate quad cycles with complete index remapping",
      "exact coordinate/source-support identities plus canonical cyclic face "
      "multiset and reconstructed topology",
      "same semantic strip; different source/output rows and face cycles",
      "directional_surface_cell_oracle_tests :: "
      "Oracle.SurfaceCellProductOracleCanonicalization."
      "PreservesInputOutputRowCycleAndReversalSemantics");
  const HandAuthoredProduct base = make_two_quad_strip();
  const HandAuthoredProduct permuted = permute_rows_and_cycles(base);
  const oracle::ProductOracleReport baseReport = inspect(base);
  const oracle::ProductOracleReport permutedReport = inspect(permuted);
  ASSERT_TRUE(baseReport.ok()) << baseReport.describe();
  ASSERT_TRUE(permutedReport.ok()) << permutedReport.describe();
  EXPECT_TRUE(baseReport.canonicalRecord == permutedReport.canonicalRecord);
}

#undef T1_INTENT

} // namespace
