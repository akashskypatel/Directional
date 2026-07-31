#include <directional/core/Library.h>
#include <directional/fields/CrossField.h>
#include <directional/io/WriteRawField.h>
#include <directional/numerics/ExactGeometry.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/util/Progress.h>

#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>

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

TEST(CompiledLibrary, LinksPipelineImplementation) {
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            directional::pipeline::parse_remesh_backend("surface-cells"));
  EXPECT_EQ("LegacyInteger",
            directional::pipeline::remesh_backend_name(
                directional::pipeline::RemeshBackend::LegacyInteger));
}

TEST(CompiledLibrary, LinksIoImplementation) {
  directional::CartesianField field;
  field.N = 2;
  field.extField.resize(1, 6);
  field.extField << 1.0, 0.0, 0.0, -1.0, 0.0, 0.0;

  const std::filesystem::path path =
      std::filesystem::current_path() / "directional_compiled_api.rawfield";
  std::error_code error;
  std::filesystem::remove(path, error);

  ASSERT_TRUE(directional::write_raw_field(path.string(), field, true));

  std::ifstream input(path);
  int degree = 0;
  int rows = 0;
  input >> degree >> rows;
  EXPECT_EQ(2, degree);
  EXPECT_EQ(1, rows);

  input.close();
  EXPECT_TRUE(std::filesystem::remove(path, error));
}

TEST(CompiledLibrary, LinksUtilityImplementation) {
  std::size_t current = 0;
  std::size_t total = 0;
  std::string task;
  directional::report_progress(
      [&](const std::size_t value, const std::size_t maximum,
          const std::string_view name) {
        current = value;
        total = maximum;
        task = name;
      },
      3, 7, "compiled utility");

  EXPECT_EQ(3U, current);
  EXPECT_EQ(7U, total);
  EXPECT_EQ("compiled utility", task);
}

TEST(CompiledLibrary, LinksExactGeometryImplementation) {
  const directional::Line2 horizontal(
      directional::EVector2{ENumber(0), ENumber(0)},
      directional::EVector2{ENumber(1), ENumber(0)});
  const directional::Line2 vertical(
      directional::EVector2{ENumber(2), ENumber(-1)},
      directional::EVector2{ENumber(0), ENumber(1)});
  ENumber horizontalParameter;
  ENumber verticalParameter;

  ASSERT_EQ(1, directional::line_line_intersection(
                   horizontal, vertical, horizontalParameter,
                   verticalParameter));
  EXPECT_NEAR(2.0, static_cast<double>(horizontalParameter.to_double()),
              1.0e-12);
  EXPECT_NEAR(1.0, static_cast<double>(verticalParameter.to_double()),
              1.0e-12);
}
