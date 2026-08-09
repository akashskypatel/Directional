from pathlib import Path

source = Path("src/geometry/SurfaceCellTracing.cpp")
text = source.read_text()

include_old = """#include <directional/geometry/SurfaceCellTracing.h>\n\n#include <Eigen/SparseCholesky>\n"""
include_new = """#include <directional/geometry/SurfaceCellTracing.h>\n\n#include <directional/authority/GridAutomorphism.h>\n#include <directional/authority/LegacyAuthorityAdapters.h>\n\n#include <Eigen/SparseCholesky>\n"""
if text.count(include_old) != 1:
    raise SystemExit(f"tracing include anchor mismatch: {text.count(include_old)}")
text = text.replace(include_old, include_new, 1)

old_authoritative = """  const int sourceBranch = branch_from_family_sign(sourceFamily, sourceSign);\n  bool authoritativeMatching = false;\n  if (edgeTransitions != nullptr) {\n    const auto found = transitionLookup.byEdge.find(edgeKey);\n    if (found == transitionLookup.byEdge.end() ||\n        !transition_faces_match(found->second, sourceFace, targetFace) ||\n        edge_key(found->second.sourceVertex0,\n                 found->second.sourceVertex1) != edgeKey) {\n      return result;\n    }\n    result.matching = found->second.matching;\n    if (found->second.secondFace == sourceFace) {\n      result.matching = -result.matching;\n    }\n    result.effort = found->second.effort;\n    authoritativeMatching = true;\n  } else {\n"""
new_authoritative = """  const int sourceBranch = branch_from_family_sign(sourceFamily, sourceSign);\n  bool authoritativeMatching = false;\n  std::optional<authority::QuarterTurn> authoritativeTransitionTransport;\n  if (edgeTransitions != nullptr) {\n    const auto found = transitionLookup.byEdge.find(edgeKey);\n    if (found == transitionLookup.byEdge.end()) {\n      return result;\n    }\n\n    const std::size_t sourceFaceExtent =\n        static_cast<std::size_t>(faces.rows());\n    const std::size_t sourceVertexExtent =\n        static_cast<std::size_t>(vertices.rows());\n    const auto sourceFaceResult = authority::LegacyAuthorityAdapters::source_face(\n        sourceFace, sourceFaceExtent);\n    const auto targetFaceResult = authority::LegacyAuthorityAdapters::source_face(\n        targetFace, sourceFaceExtent);\n    const auto firstFaceResult = authority::LegacyAuthorityAdapters::source_face(\n        found->second.firstFace, sourceFaceExtent);\n    const auto secondFaceResult = authority::LegacyAuthorityAdapters::source_face(\n        found->second.secondFace, sourceFaceExtent);\n    if (!sourceFaceResult || !targetFaceResult || !firstFaceResult ||\n        !secondFaceResult) {\n      return result;\n    }\n\n    const authority::SourceFaceId typedSourceFace = sourceFaceResult.value();\n    const authority::SourceFaceId typedTargetFace = targetFaceResult.value();\n    const authority::SourceFaceId typedFirstFace = firstFaceResult.value();\n    const authority::SourceFaceId typedSecondFace = secondFaceResult.value();\n    const bool forwardTraversal = typedFirstFace == typedSourceFace &&\n                                  typedSecondFace == typedTargetFace;\n    const bool reverseTraversal = typedFirstFace == typedTargetFace &&\n                                  typedSecondFace == typedSourceFace;\n    if (!forwardTraversal && !reverseTraversal) {\n      return result;\n    }\n\n    const auto firstVertexResult =\n        authority::LegacyAuthorityAdapters::source_vertex(\n            found->second.sourceVertex0, sourceVertexExtent);\n    const auto secondVertexResult =\n        authority::LegacyAuthorityAdapters::source_vertex(\n            found->second.sourceVertex1, sourceVertexExtent);\n    if (!firstVertexResult || !secondVertexResult) {\n      return result;\n    }\n    const auto sourceEdgeResult = authority::SourceEdgeTopologyKey::make(\n        firstVertexResult.value(), secondVertexResult.value());\n    if (!sourceEdgeResult) {\n      return result;\n    }\n    const authority::SourceEdgeTopologyKey sourceEdge = sourceEdgeResult.value();\n    const std::uint64_t transitionEdgeKey = edge_key(\n        static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(\n            sourceEdge.first())),\n        static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(\n            sourceEdge.second())));\n    if (transitionEdgeKey != edgeKey) {\n      return result;\n    }\n\n    authority::QuarterTurn transport =\n        authority::QuarterTurn::from_integer(found->second.matching);\n    if (reverseTraversal) {\n      transport = transport.inverse();\n    }\n    authoritativeTransitionTransport = transport;\n\n    result.matching = found->second.matching;\n    if (reverseTraversal) {\n      result.matching = -result.matching;\n    }\n    result.effort = found->second.effort;\n    authoritativeMatching = true;\n  } else {\n"""
if text.count(old_authoritative) != 1:
    raise SystemExit(
        f"authoritative transition anchor mismatch: {text.count(old_authoritative)}"
    )
text = text.replace(old_authoritative, new_authoritative, 1)

old_target = """  int targetBranch = sourceBranch;\n  if (authoritativeMatching) {\n    targetBranch = normalized_branch(sourceBranch + result.matching);\n  } else {\n"""
new_target = """  int targetBranch = sourceBranch;\n  if (authoritativeTransitionTransport.has_value()) {\n    targetBranch = normalized_branch(\n        sourceBranch +\n        static_cast<int>(authoritativeTransitionTransport->value()));\n  } else if (authoritativeMatching) {\n    targetBranch = normalized_branch(sourceBranch + result.matching);\n  } else {\n"""
if text.count(old_target) != 1:
    raise SystemExit(f"target-branch anchor mismatch: {text.count(old_target)}")
text = text.replace(old_target, new_target, 1)
source.write_text(text)

tests = Path("tests/SurfaceCellsPhase10Tests.cpp")
test_text = tests.read_text()
test_include_old = """#include <directional/meshing/PatchQuadrangulator.h>\n#include <directional/pipeline/RemeshPipeline.h>\n"""
test_include_new = """#include <directional/meshing/PatchQuadrangulator.h>\n#include <directional/geometry/SurfaceCellTracing.h>\n#include <directional/pipeline/RemeshPipeline.h>\n"""
if test_text.count(test_include_old) != 1:
    raise SystemExit(f"test include anchor mismatch: {test_text.count(test_include_old)}")
test_text = test_text.replace(test_include_old, test_include_new, 1)

marker = "\nTEST(SurfaceCellsPhase10, MeshValidatorDetectsMissingVertex) {"
if test_text.count(marker) != 1:
    raise SystemExit(f"test insertion marker mismatch: {test_text.count(marker)}")
block = r'''

struct FieldTransitionFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  std::map<std::uint64_t, std::array<int, 2>> edgeFaces;
  std::map<std::uint64_t, int> edgeMatchingIndices;
  directional::geometry::surface_cell_tracing_detail::EdgeTransitionLookup
      transitionLookup;
  std::uint64_t edgeKey = 0;
  std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
};

FieldTransitionFixture make_field_transition_fixture(const int matching = 1) {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  FieldTransitionFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      1.0, 1.0, 0.0,
                      0.0, 1.0, 0.0;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3;
  fixture.faceAxisX.resize(2, 3);
  fixture.faceAxisX << 1.0, 0.0, 0.0,
                       1.0, 0.0, 0.0;
  fixture.faceAxisY.resize(2, 3);
  fixture.faceAxisY << 0.0, 1.0, 0.0,
                       0.0, 1.0, 0.0;
  fixture.edgeFaces = detail::edge_faces(fixture.faces);
  fixture.edgeMatchingIndices = detail::edge_matching_indices(fixture.edgeFaces);
  fixture.edgeKey = detail::edge_key(0, 2);

  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceEdge = fixture.edgeMatchingIndices.at(fixture.edgeKey);
  transition.sourceVertex0 = 0;
  transition.sourceVertex1 = 2;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = matching;
  transition.effort = 0.25;
  fixture.transitions.push_back(transition);
  fixture.transitionLookup = detail::edge_transition_lookup(fixture.transitions);
  return fixture;
}

directional::geometry::surface_cell_tracing_detail::BranchTransitionResult
resolve_field_transition(
    const FieldTransitionFixture &fixture, const int sourceFace,
    const int targetFace, const int sourceFamily, const int sourceSign,
    const Eigen::RowVector3d &sourceDirection,
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr,
    const bool useAuthoritativeTransitions = true) {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  return detail::resolve_branch_transition(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.edgeFaces, fixture.edgeMatchingIndices, fixture.transitionLookup,
      fixture.edgeKey, sourceFace, targetFace, sourceFamily, sourceSign,
      sourceDirection, edgeMatching, edgeEffort,
      useAuthoritativeTransitions ? &fixture.transitions : nullptr);
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     ForwardQuarterTurnUsesTypedModuloTransport) {
  const FieldTransitionFixture fixture = make_field_transition_fixture(1);

  const auto result = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(1, result.matching);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(Eigen::RowVector3d(0.0, 1.0, 0.0),
                                        1.0e-12));
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     ReverseTraversalUsesExactQuarterTurnInverse) {
  const FieldTransitionFixture fixture = make_field_transition_fixture(1);

  const auto result = resolve_field_transition(
      fixture, 1, 0, 1, 1, Eigen::RowVector3d(0.0, 1.0, 0.0));

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(-1, result.matching);
  EXPECT_EQ(0, result.family);
  EXPECT_EQ(1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(Eigen::RowVector3d(1.0, 0.0, 0.0),
                                        1.0e-12));
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     EquivalentQuarterTurnsNormalizeSemantically) {
  const FieldTransitionFixture plusOne = make_field_transition_fixture(1);
  const FieldTransitionFixture plusFive = make_field_transition_fixture(5);

  const auto one = resolve_field_transition(
      plusOne, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));
  const auto five = resolve_field_transition(
      plusFive, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));

  ASSERT_TRUE(one.valid);
  ASSERT_TRUE(five.valid);
  EXPECT_EQ(1, one.matching);
  EXPECT_EQ(5, five.matching);
  EXPECT_EQ(one.family, five.family);
  EXPECT_EQ(one.sign, five.sign);
  EXPECT_TRUE(one.direction.isApprox(five.direction, 1.0e-12));
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     ReversedSourceEdgeEndpointsPreserveSemanticIdentity) {
  FieldTransitionFixture fixture = make_field_transition_fixture(1);
  fixture.transitions.front().sourceVertex0 = 2;
  fixture.transitions.front().sourceVertex1 = 0;
  fixture.transitionLookup =
      directional::geometry::surface_cell_tracing_detail::edge_transition_lookup(
          fixture.transitions);

  const auto result = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(1, result.matching);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(1, result.sign);
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     MalformedAuthoritativeFaceOrEdgeFailsClosed) {
  FieldTransitionFixture fixture = make_field_transition_fixture(1);
  const int matchingIndex = fixture.edgeMatchingIndices.at(fixture.edgeKey);
  Eigen::VectorXi fallbackMatching =
      Eigen::VectorXi::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  Eigen::VectorXd fallbackEffort =
      Eigen::VectorXd::Constant(static_cast<int>(fixture.edgeMatchingIndices.size()),
                                0.75);
  fallbackMatching[matchingIndex] = 3;

  auto malformedFace = fixture.transitions.front();
  malformedFace.firstFace = fixture.faces.rows();
  fixture.transitions = {malformedFace};
  fixture.transitionLookup.byEdge.clear();
  fixture.transitionLookup.byEdge.emplace(fixture.edgeKey, malformedFace);
  const auto faceResult = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0),
      &fallbackMatching, &fallbackEffort, true);
  EXPECT_FALSE(faceResult.valid);

  auto malformedEdge = malformedFace;
  malformedEdge.firstFace = 0;
  malformedEdge.sourceVertex1 = fixture.vertices.rows();
  fixture.transitions = {malformedEdge};
  fixture.transitionLookup.byEdge.clear();
  fixture.transitionLookup.byEdge.emplace(fixture.edgeKey, malformedEdge);
  const auto edgeResult = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0),
      &fallbackMatching, &fallbackEffort, true);
  EXPECT_FALSE(edgeResult.valid);
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent) {
  const FieldTransitionFixture fixture = make_field_transition_fixture(1);
  const int matchingIndex = fixture.edgeMatchingIndices.at(fixture.edgeKey);
  Eigen::VectorXi fallbackMatching =
      Eigen::VectorXi::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  Eigen::VectorXd fallbackEffort =
      Eigen::VectorXd::Constant(static_cast<int>(fixture.edgeMatchingIndices.size()),
                                0.75);
  fallbackMatching[matchingIndex] = 3;

  const auto result = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0),
      &fallbackMatching, &fallbackEffort, false);

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(3, result.matching);
  EXPECT_DOUBLE_EQ(0.75, result.effort);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(-1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(Eigen::RowVector3d(0.0, -1.0, 0.0),
                                        1.0e-12));
}
'''
test_text = test_text.replace(marker, block + marker, 1)
tests.write_text(test_text)
