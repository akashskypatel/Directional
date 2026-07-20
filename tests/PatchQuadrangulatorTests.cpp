#include <directional/meshing/PatchQuadrangulator.h>

#include <gtest/gtest.h>

namespace {

directional::detail::PatchRegion make_patch(std::vector<int> boundary,
                                             std::vector<int> sideCounts) {
  directional::detail::PatchRegion patch;
  patch.boundaryVertices = std::move(boundary);
  patch.sideEdgeCounts = std::move(sideCounts);
  for (std::size_t index = 0; index < patch.boundaryVertices.size(); ++index) {
    const int first = patch.boundaryVertices[index];
    const int second =
        patch.boundaryVertices[(index + 1) % patch.boundaryVertices.size()];
    patch.protectedBoundaryEdges.insert(
        directional::detail::canonical_patch_edge(first, second));
  }
  return patch;
}

void expect_valid_patch_output(const directional::detail::PatchRegion &patch,
                               const directional::detail::PatchMesh &mesh) {
  EXPECT_TRUE(
      directional::detail::PatchQuadrangulator::boundary_is_preserved(patch,
                                                                      mesh));
  EXPECT_TRUE(directional::detail::PatchQuadrangulator::output_has_no_t_junctions(
      mesh));
  EXPECT_TRUE(directional::detail::PatchQuadrangulator::output_is_pure_quad(
      mesh));
}

TEST(PatchQuadrangulatorPhase06,
     QuadrangulatesFourSidedPatchWithMatchingOppositeCounts) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5, 6, 7}, {2, 2, 2, 2});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.patchClass, directional::detail::PatchClass::FourSidedDisk);
  EXPECT_EQ(result.mesh.quads.size(), 4U);
  expect_valid_patch_output(patch, result.mesh);
}

TEST(PatchQuadrangulatorPhase06,
     RejectsFourSidedPatchWithIncompatibleCounts) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5, 6}, {2, 1, 3, 1});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  EXPECT_FALSE(result.success);
}

TEST(PatchQuadrangulatorPhase06, QuadrangulatesSimpleThreeSidedPatch) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5}, {2, 2, 2});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.patchClass,
            directional::detail::PatchClass::SimpleThreeSided);
  EXPECT_EQ(result.mesh.quads.size(), 3U);
  expect_valid_patch_output(patch, result.mesh);
}

TEST(PatchQuadrangulatorPhase06, QuadrangulatesSimpleFiveSidedPatch) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5}, {2, 1, 1, 1, 1});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.patchClass, directional::detail::PatchClass::SimpleFiveSided);
  EXPECT_EQ(result.mesh.quads.size(), 3U);
  expect_valid_patch_output(patch, result.mesh);
}

TEST(PatchQuadrangulatorPhase06, QuadrangulatesSimpleSixSidedPatch) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5}, {1, 1, 1, 1, 1, 1});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.patchClass, directional::detail::PatchClass::SimpleSixSided);
  EXPECT_EQ(result.mesh.quads.size(), 3U);
  expect_valid_patch_output(patch, result.mesh);
}

TEST(PatchQuadrangulatorPhase06, PatchBoundaryIsPreservedExactly) {
  const auto patch = make_patch({10, 11, 12, 13, 14, 15}, {2, 2, 2});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.mesh.boundaryVertices, patch.boundaryVertices);
}

TEST(PatchQuadrangulatorPhase06, PatchOutputHasNoTJunctions) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5, 6, 7}, {2, 2, 2, 2});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_TRUE(directional::detail::PatchQuadrangulator::output_has_no_t_junctions(
      result.mesh));
}

TEST(PatchQuadrangulatorPhase06, PatchOutputIsPureQuad) {
  const auto patch = make_patch({0, 1, 2, 3, 4, 5}, {2, 1, 1, 1, 1});

  const auto result =
      directional::detail::PatchQuadrangulator::quadrangulate(patch);

  ASSERT_TRUE(result.success);
  EXPECT_TRUE(directional::detail::PatchQuadrangulator::output_is_pure_quad(
      result.mesh));
}

} // namespace
