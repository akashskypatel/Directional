#include <directional/geometry/MeshComponents.h>
#include <directional/pipeline/ParallelRemeshPipeline.h>

#include <gtest/gtest.h>

#include <map>
#include <set>
#include <string>
#include <vector>

namespace {

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

SyntheticMesh make_two_square_components() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0, 3.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0, 3.0, 1.0,
      0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
  return mesh;
}

Eigen::MatrixXd component_tagged_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    const double tag = static_cast<double>(face + 1);
    raw.block(face, 0, 1, 3) << tag, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, tag, 0.0;
    raw.block(face, 6, 1, 3) << -tag, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -tag, 0.0;
  }
  return raw;
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
    if (visited[static_cast<std::size_t>(seed)] != 0) {
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
          if (visited[static_cast<std::size_t>(adjacent)] == 0) {
            visited[static_cast<std::size_t>(adjacent)] = 1;
            stack.push_back(adjacent);
          }
        }
      }
    }
  }
  return components;
}

std::string structural_signature(const directional::pipeline::RemeshResult &r) {
  return std::to_string(r.product().vertices.rows()) + "/" +
         std::to_string(r.product().faces.rows()) + "/" +
         std::to_string(r.product().degrees.size()) + "/" +
         std::to_string(r.product().degrees.sum());
}

directional::pipeline::RemeshOptions test_options() {
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.maxComponentThreads = 2;
  return options;
}

TEST(ComponentParallelismPhase08,
     ComponentSplitterProducesDisjointCompletePartition) {
  const SyntheticMesh mesh = make_two_square_components();
  const auto components =
      directional::geometry::face_connected_components(mesh.faces);

  ASSERT_EQ(components.size(), 2U);
  EXPECT_EQ((std::vector<int>{0, 1}), components[0]);
  EXPECT_EQ((std::vector<int>{2, 3}), components[1]);
}

TEST(ComponentParallelismPhase08, FieldRowsFollowComponentFaceMapping) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = component_tagged_raw_field(mesh.faces.rows());
  const auto components =
      directional::geometry::compact_face_components(mesh.vertices, mesh.faces,
                                                     &raw);

  ASSERT_EQ(components.size(), 2U);
  ASSERT_EQ(components[1].rawField.rows(), 2);
  EXPECT_NEAR(components[1].rawField(0, 0), 3.0, 1.0e-12);
  EXPECT_NEAR(components[1].rawField(1, 0), 4.0, 1.0e-12);
}

TEST(ComponentParallelismPhase08,
     SequentialAndParallelComponentPipelinesHaveSameStructuralSignature) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::pipeline::RemeshOptions options = test_options();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  options.parallelizeComponents = true;
  options.maxComponentThreads = 1;
  const auto componentSequential = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  options.maxComponentThreads = 2;
  const auto componentParallel = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(componentSequential.is_produced());
  ASSERT_TRUE(componentParallel.is_produced());
  EXPECT_EQ(structural_signature(componentSequential),
            structural_signature(componentParallel));
}

TEST(ComponentParallelismPhase08, ParallelMergeOffsetsFaceIndicesCorrectly) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::pipeline::RemeshOptions options = test_options();
  options.parallelizeComponents = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, constant_raw_field(mesh.faces.rows()),
      options);

  ASSERT_TRUE(result.is_produced());
  ASSERT_GT(result.product().faces.rows(), 0);
  for (int face = 0; face < result.product().degrees.size(); ++face) {
    for (int corner = 0; corner < result.product().degrees(face); ++corner) {
      EXPECT_GE(result.product().faces(face, corner), 0);
      EXPECT_LT(result.product().faces(face, corner), result.product().vertices.rows());
    }
  }
  EXPECT_EQ(result.diagnostics.componentCount, 2U);
}

TEST(ComponentParallelismPhase08, ParallelMergeIsDeterministic) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::pipeline::RemeshOptions options = test_options();
  options.parallelizeComponents = true;
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const auto first = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  const auto second = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());
  EXPECT_EQ(structural_signature(first), structural_signature(second));
}

TEST(ComponentParallelismPhase08, ParallelFailureReportsFailingComponent) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  raw.block(2, 0, 2, 12).setZero();
  directional::pipeline::RemeshOptions options = test_options();
  options.parallelizeComponents = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  EXPECT_EQ(result.diagnostics.failedComponentIndex, 1U);
  EXPECT_EQ(result.diagnostics.failedComponentMinimumOriginalFace, 2U);
  ASSERT_EQ(result.diagnostics.components.size(), 2U);
  EXPECT_FALSE(result.diagnostics.components[1].success);
}

} // namespace
