#include <directional/geometry/BoundedMeshPreconditioner.h>
#include <directional/pipeline/RemeshPipeline.h>

#include <gtest/gtest.h>

#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

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

int connected_component_count(const Eigen::MatrixXi &faces) {
  std::map<int, std::vector<int>> incidentFacesByVertex;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < faces.cols(); ++corner) {
      incidentFacesByVertex[faces(face, corner)].push_back(face);
    }
  }
  std::vector<unsigned char> visited(static_cast<std::size_t>(faces.rows()), 0);
  int components = 0;
  for (int seed = 0; seed < faces.rows(); ++seed) {
    if (visited[static_cast<std::size_t>(seed)]) {
      continue;
    }
    ++components;
    std::vector<int> stack{seed};
    visited[static_cast<std::size_t>(seed)] = 1;
    while (!stack.empty()) {
      const int face = stack.back();
      stack.pop_back();
      for (int corner = 0; corner < faces.cols(); ++corner) {
        for (const int adjacent :
             incidentFacesByVertex[faces(face, corner)]) {
          if (!visited[static_cast<std::size_t>(adjacent)]) {
            visited[static_cast<std::size_t>(adjacent)] = 1;
            stack.push_back(adjacent);
          }
        }
      }
    }
  }
  return components;
}

Eigen::MatrixXd constant_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.block(face, 0, 1, 3) << 1.0, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, 1.0, 0.0;
    raw.block(face, 6, 1, 3) << -1.0, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -1.0, 0.0;
  }
  return raw;
}

int non_quad_face_count(const directional::pipeline::RemeshResult &result) {
  int count = 0;
  for (int face = 0; face < result.product().degrees.size(); ++face) {
    if (result.product().degrees(face) != 4) {
      ++count;
    }
  }
  return count;
}

std::set<std::pair<int, int>> boundary_edges(const Eigen::MatrixXi &faces) {
  std::map<std::pair<int, int>, int> counts;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int edge = 0; edge < 3; ++edge) {
      const int a = faces(face, edge);
      const int b = faces(face, (edge + 1) % 3);
      counts[a <= b ? std::make_pair(a, b) : std::make_pair(b, a)]++;
    }
  }
  std::set<std::pair<int, int>> boundary;
  for (const auto &[edge, count] : counts) {
    if (count == 1) {
      boundary.insert(edge);
    }
  }
  return boundary;
}

TEST(BoundedMeshPreconditionerPhase07,
     PreconditionerImprovesSkinnyTriangleQuality) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.7, 1.75, 0.0,
      2.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::geometry::BoundedMeshPreconditionerOptions options;
  options.enabled = true;
  const auto result = directional::geometry::BoundedMeshPreconditioner::
      precondition(vertices, faces, options);

  EXPECT_GT(result.flipsAccepted, 0U);
  EXPECT_GT(result.after.minTriangleAngleDegrees,
            result.before.minTriangleAngleDegrees);
}

TEST(BoundedMeshPreconditionerPhase07,
     PreconditionerRespectsFaceCountBudget) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.7, 1.75, 0.0,
      2.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::geometry::BoundedMeshPreconditionerOptions options;
  options.enabled = true;
  options.minFaceRatio = 1.0;
  options.maxFaceRatio = 1.0;
  const auto result = directional::geometry::BoundedMeshPreconditioner::
      precondition(vertices, faces, options);

  EXPECT_EQ(result.inputTriangleCount, result.outputTriangleCount);
  EXPECT_EQ(result.outputTriangleCount, 2U);
}

TEST(BoundedMeshPreconditionerPhase07, PreconditionerPreservesBoundary) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.7, 1.75, 0.0,
      2.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::geometry::BoundedMeshPreconditionerOptions options;
  options.enabled = true;
  const auto result = directional::geometry::BoundedMeshPreconditioner::
      precondition(vertices, faces, options);

  EXPECT_EQ(boundary_edges(faces), boundary_edges(result.faces));
}

TEST(BoundedMeshPreconditionerPhase07,
     PreconditionerPreservesProtectedFeatureEdges) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::geometry::BoundedMeshPreconditionerOptions options;
  options.enabled = true;
  options.sharpAngleDegrees = 10.0;
  const auto result = directional::geometry::BoundedMeshPreconditioner::
      precondition(vertices, faces, options);

  EXPECT_EQ(result.flipsAccepted, 0U);
  EXPECT_EQ(result.faces, faces);
  EXPECT_GT(result.adaptiveFeatureMapSeconds, 0.0);
  EXPECT_GT(result.adaptiveFeatureHardEdgeCount, 0U);
}

TEST(BoundedMeshPreconditionerPhase07,
     PreconditioningOffReproducesLegacyPath) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.preconditionInputMesh = false;

  const auto first =
      directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                              options);
  const auto second =
      directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                              options);

  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());
  EXPECT_EQ(first.product().vertices.rows(), second.product().vertices.rows());
  EXPECT_EQ(first.product().faces.rows(), second.product().faces.rows());
  EXPECT_EQ(first.product().degrees.sum(), second.product().degrees.sum());
}

TEST(BoundedMeshPreconditionerPhase07,
     PreconditioningOnDoesNotChangeConnectedComponentCount) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.preconditionInputMesh = true;

  const auto result =
      directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                              options);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(connected_component_count(mesh.faces),
            connected_component_count(result.product().cutFaces));
}

TEST(BoundedMeshPreconditionerPhase07, UploadedFieldRemeshStillSucceeds) {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.preconditionInputMesh = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, constant_raw_field(mesh.faces.rows()),
      options);

  ASSERT_TRUE(result.is_produced());
  EXPECT_GT(result.product().vertices.rows(), 0);
  EXPECT_GT(result.product().faces.rows(), 0);
}

TEST(BoundedMeshPreconditionerPhase07,
     HistoricalArrangementComplexityCaseProducesNoWorseOutputTopology) {
  const SyntheticMesh mesh = make_grid_mesh(2);

  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.preconditionInputMesh = false;
  const auto disabled =
      directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                              options);

  options.preconditionInputMesh = true;
  const auto enabled =
      directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                              options);

  ASSERT_TRUE(disabled.is_produced());
  ASSERT_TRUE(enabled.is_produced());
  EXPECT_EQ(connected_component_count(disabled.product().cutFaces),
            connected_component_count(enabled.product().cutFaces));
  EXPECT_LE(non_quad_face_count(enabled), non_quad_face_count(disabled));
}

} // namespace
