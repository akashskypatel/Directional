#include <directional/core/Library.h>
#include <directional/fields/CrossField.h>

#include <gtest/gtest.h>

TEST(CompiledLibrary, ExposesBuildInformation) {
  EXPECT_STREQ("Directional shared library core", directional_build_info());
}

TEST(CompiledLibrary, LinksCrossFieldImplementation) {
  const Eigen::RowVector3d tangent =
      directional::fields::project_tangent(Eigen::RowVector3d(2.0, 0.0, 3.0),
                                           Eigen::RowVector3d(0.0, 0.0, 1.0),
                                           true);

  EXPECT_NEAR(1.0, tangent.x(), 1.0e-12);
  EXPECT_NEAR(0.0, tangent.y(), 1.0e-12);
  EXPECT_NEAR(0.0, tangent.z(), 1.0e-12);
}
