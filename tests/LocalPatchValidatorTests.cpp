#include <directional/meshing/LocalPatchValidator.h>

#include <gtest/gtest.h>

namespace {

directional::detail::LocalPatchDescriptor simple_patch() {
  directional::detail::LocalPatchDescriptor patch;
  patch.regionAdjacency = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
  patch.postEditBoundaryLoops = {{0, 1, 2, 3}};
  patch.postEditFaceDegrees = {4};
  patch.expectedEulerCharacteristic = 1;
  patch.postEditEulerCharacteristic = 1;
  patch.expectedComponentCount = 1;
  patch.postEditComponentCount = 1;
  return patch;
}

TEST(LocalPatchValidatorPhase05, ValidatorAcceptsSimpleQuadLikeCollapse) {
  const auto result =
      directional::detail::LocalPatchValidator::validate(simple_patch());

  EXPECT_TRUE(result.accepted);
  EXPECT_EQ(result.reason,
            directional::detail::LocalPatchRejectionReason::None);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsRepeatedBoundaryVertex) {
  auto patch = simple_patch();
  patch.postEditBoundaryLoops = {{0, 1, 2, 1}};

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason, directional::detail::LocalPatchRejectionReason::
                               RepeatedBoundaryVertex);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsComponentSplit) {
  auto patch = simple_patch();
  patch.regionAdjacency = {{0, 1}, {2, 3}};
  patch.postEditComponentCount = 2;

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason, directional::detail::LocalPatchRejectionReason::
                               ComponentSplit);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsNewBoundaryOnClosedRegion) {
  auto patch = simple_patch();
  patch.wasClosedRegion = true;
  patch.introducesBoundary = true;

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason, directional::detail::LocalPatchRejectionReason::
                               NewBoundaryOnClosedRegion);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsProtectedSeamMutation) {
  auto patch = simple_patch();
  patch.mutatesProtectedSeam = true;

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason, directional::detail::LocalPatchRejectionReason::
                               ProtectedSeamMutation);
}

TEST(LocalPatchValidatorPhase05, ValidatorAcceptsValidBoundaryCase) {
  auto patch = simple_patch();
  patch.postEditBoundaryLoops = {{10, 11, 12}};
  patch.regionAdjacency = {{10, 11}, {11, 12}, {12, 10}};
  patch.wasClosedRegion = false;
  patch.introducesBoundary = true;

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_TRUE(result.accepted);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsDegeneratePolygonCase) {
  auto patch = simple_patch();
  patch.postEditFaceDegrees = {2};

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason, directional::detail::LocalPatchRejectionReason::
                               FaceDegreeBelowThree);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsFanningBacktrackCase) {
  auto patch = simple_patch();
  patch.postEditBoundaryLoops = {{0, 1, 2, 1, 3}};
  patch.regionAdjacency = {{0, 1}, {1, 2}, {2, 1}, {1, 3}, {3, 0}};

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason, directional::detail::LocalPatchRejectionReason::
                               RepeatedBoundaryVertex);
}

TEST(LocalPatchValidatorPhase05, ValidatorRejectsFloatingComponentCase) {
  auto patch = simple_patch();
  patch.expectedComponentCount = 1;
  patch.postEditComponentCount = 2;

  const auto result =
      directional::detail::LocalPatchValidator::validate(patch);

  EXPECT_FALSE(result.accepted);
  EXPECT_EQ(result.reason,
            directional::detail::LocalPatchRejectionReason::ComponentSplit);
}

} // namespace
