#include <algorithm>
#include <cmath>
#include <filesystem>
#include <vector>

#include <gtest/gtest.h>

#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"
#include "TestFixturePaths.h"

namespace {

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

SyntheticMesh make_grid_mesh(const int subdivisions) {
  const int n = std::max(1, subdivisions);
  SyntheticMesh mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices(vertex, 0) = static_cast<double>(x) / n;
      mesh.vertices(vertex, 1) = static_cast<double>(y) / n;
      mesh.vertices(vertex, 2) = 0.0;
    }
  }

  mesh.faces.resize(2 * n * n, 3);
  int face = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int v00 = y * (n + 1) + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * (n + 1) + x;
      const int v11 = v01 + 1;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

directional::pipeline::RemeshResult run_regression_remesh() {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.verbose = false;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  return directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                                  options);
}

double polygon_area(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                    const Eigen::VectorXi &degrees, const int face) {
  const int degree = degrees(face);
  if (degree < 3) {
    return 0.0;
  }
  const Eigen::RowVector3d origin = vertices.row(faces(face, 0));
  double area = 0.0;
  for (int corner = 1; corner + 1 < degree; ++corner) {
    const Eigen::RowVector3d a = vertices.row(faces(face, corner)) - origin;
    const Eigen::RowVector3d b = vertices.row(faces(face, corner + 1)) - origin;
    area += 0.5 * a.cross(b).norm();
  }
  return area;
}

TEST(RemeshRegressionPhase00, SyntheticOutputSatisfiesStructuralInvariants) {
  const directional::pipeline::RemeshResult result = run_regression_remesh();

  ASSERT_TRUE(result.is_produced());
  ASSERT_GT(result.product().vertices.rows(), 0);
  ASSERT_GT(result.product().faces.rows(), 0);
  ASSERT_EQ(result.product().degrees.size(), result.product().faces.rows());
  EXPECT_TRUE(result.product().vertices.allFinite());

  for (int face = 0; face < result.product().faces.rows(); ++face) {
    const int degree = result.product().degrees(face);
    ASSERT_GE(degree, 3);
    ASSERT_LE(degree, result.product().faces.cols());

    for (int corner = 0; corner < degree; ++corner) {
      const int vertex = result.product().faces(face, corner);
      ASSERT_GE(vertex, 0);
      ASSERT_LT(vertex, result.product().vertices.rows());

      const int nextVertex = result.product().faces(face, (corner + 1) % degree);
      EXPECT_NE(vertex, nextVertex);
    }

    EXPECT_GT(polygon_area(result.product().vertices, result.product().faces, result.product().degrees, face),
              1.0e-14);
  }
}

TEST(RemeshRegressionPhase00, RandomBunnyBenchmarkFixtureHasUsableField) {
  const std::filesystem::path manifestPath =
      directional::tests::benchmark_fixture_path(
          "repo_regressions.json");

  const std::vector<directional::bench::BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifestPath);
  const auto bunny = std::find_if(
      cases.begin(), cases.end(),
      [](const directional::bench::BenchmarkCase &candidate) {
        return candidate.name == "bunny_1k_random_medium";
      });

  ASSERT_NE(bunny, cases.end());
  EXPECT_EQ(bunny->meshPath.filename(), "bunny_1k_random.obj");
  EXPECT_EQ(bunny->generatedField, "smooth");

  const directional::bench::BenchmarkMesh mesh =
      directional::bench::load_benchmark_mesh(*bunny);
  ASSERT_GT(mesh.vertices.rows(), 0);
  ASSERT_EQ(mesh.faces.rows(), 1000);

  const directional::bench::BenchmarkField field = bunny->fieldPath.empty()
      ? directional::bench::generate_benchmark_field(*bunny, mesh)
      : directional::bench::load_benchmark_field(*bunny, mesh.faces.rows());
  ASSERT_TRUE(field.available);
  EXPECT_EQ(field.degree, 4);
  EXPECT_EQ(field.raw.rows(), mesh.faces.rows());
  EXPECT_EQ(field.raw.cols(), 12);
}

} // namespace
