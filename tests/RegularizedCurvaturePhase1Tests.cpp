#include <gtest/gtest.h>

#include <cmath>
#include <numbers>

#include <directional/core/TriMesh.h>
#include <directional/fields/RegularizedCurvatureCrossField.h>
#include <directional/geometry/FaceCurvature.h>

namespace {

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshFixture make_plane() {
  MeshFixture mesh;
  mesh.vertices.resize(4, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3;
  return mesh;
}

MeshFixture make_folded_plate() {
  MeshFixture mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      1.0, 0.0, 1.0,
      0.0, 0.0, 1.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2,
      0, 2, 3,
      1, 0, 5,
      1, 5, 4;
  return mesh;
}

MeshFixture make_open_cylinder(const int segments = 24,
                               const int rings = 5,
                               const double radius = 2.0,
                               const double height = 2.0) {
  MeshFixture mesh;
  mesh.vertices.resize(segments * rings, 3);
  for (int ring = 0; ring < rings; ++ring) {
    const double z = -0.5 * height +
                     height * static_cast<double>(ring) /
                         static_cast<double>(rings - 1);
    for (int segment = 0; segment < segments; ++segment) {
      const double angle = 2.0 * std::numbers::pi *
                           static_cast<double>(segment) /
                           static_cast<double>(segments);
      mesh.vertices.row(ring * segments + segment) <<
          radius * std::cos(angle), radius * std::sin(angle), z;
    }
  }

  mesh.faces.resize((rings - 1) * segments * 2, 3);
  int face = 0;
  for (int ring = 0; ring < rings - 1; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const int next = (segment + 1) % segments;
      const int a = ring * segments + segment;
      const int b = ring * segments + next;
      const int c = (ring + 1) * segments + segment;
      const int d = (ring + 1) * segments + next;
      mesh.faces.row(face++) << a, b, d;
      mesh.faces.row(face++) << a, d, c;
    }
  }
  return mesh;
}

} // namespace

TEST(TriMeshPhase1, BoundaryAdjacencyIsInitialized) {
  const MeshFixture input = make_plane();
  directional::TriMesh mesh;
  mesh.set_mesh(input.vertices, input.faces);

  EXPECT_EQ(mesh.isBoundaryVertex.size(), mesh.V.rows());
  EXPECT_EQ(mesh.isBoundaryEdge.size(), mesh.EV.rows());
  EXPECT_TRUE((mesh.TT.array() >= -1).all());
  EXPECT_GT((mesh.TT.array() == -1).count(), 0);
}

TEST(FaceCurvaturePhase1, PlaneHasZeroCurvatureAndConfidence) {
  const MeshFixture input = make_plane();
  directional::TriMesh mesh;
  mesh.set_mesh(input.vertices, input.faces);

  directional::FaceCurvatureOptions options;
  options.smoothingIterations = 0;
  const directional::FaceCurvatureResult result =
      directional::estimate_face_curvature(
          mesh.V, mesh.F, mesh.FBx, mesh.FBy, mesh.faceNormals,
          mesh.faceAreas, mesh.TT, mesh.vertexNormals, options);

  EXPECT_EQ(result.valid.sum(), mesh.F.rows());
  EXPECT_LT(result.principalCurvatures.cwiseAbs().maxCoeff(), 1e-10);
  EXPECT_LT(result.confidence.maxCoeff(), 1e-10);
}

TEST(FaceCurvaturePhase1, CylinderRecoversPrincipalCurvatures) {
  const MeshFixture input = make_open_cylinder();
  directional::TriMesh mesh;
  mesh.set_mesh(input.vertices, input.faces);

  Eigen::MatrixXd analyticNormals(mesh.V.rows(), 3);
  for (int vertex = 0; vertex < mesh.V.rows(); ++vertex) {
    Eigen::Vector3d normal(mesh.V(vertex, 0), mesh.V(vertex, 1), 0.0);
    analyticNormals.row(vertex) = normal.normalized();
  }

  directional::FaceCurvatureOptions options;
  options.smoothingIterations = 1;
  const directional::FaceCurvatureResult result =
      directional::estimate_face_curvature(
          mesh.V, mesh.F, mesh.FBx, mesh.FBy, mesh.faceNormals,
          mesh.faceAreas, mesh.TT, analyticNormals, options);

  ASSERT_EQ(result.valid.sum(), mesh.F.rows());
  const double meanSmall =
      result.principalCurvatures.col(0).cwiseAbs().mean();
  const double meanLarge =
      result.principalCurvatures.col(1).cwiseAbs().mean();
  EXPECT_LT(meanSmall, 0.05);
  EXPECT_NEAR(meanLarge, 0.5, 0.06);
  EXPECT_GT(result.confidence.mean(), 0.5);
}

TEST(FaceCurvaturePhase1, FeatureAwareNormalsRejectFalseCreaseCurvature) {
  const MeshFixture input = make_folded_plate();
  directional::TriMesh mesh;
  mesh.set_mesh(input.vertices, input.faces);

  directional::FaceCurvatureOptions featureAware;
  featureAware.smoothingIterations = 0;
  featureAware.sharpFeatureAngleDegrees = 60.0;
  featureAware.useFeatureAwareCornerNormals = true;
  const directional::FaceCurvatureResult split =
      directional::estimate_face_curvature(
          mesh.V, mesh.F, mesh.FBx, mesh.FBy, mesh.faceNormals,
          mesh.faceAreas, mesh.TT, mesh.vertexNormals, featureAware);

  directional::FaceCurvatureOptions blended = featureAware;
  blended.useFeatureAwareCornerNormals = false;
  const directional::FaceCurvatureResult unsplit =
      directional::estimate_face_curvature(
          mesh.V, mesh.F, mesh.FBx, mesh.FBy, mesh.faceNormals,
          mesh.faceAreas, mesh.TT, mesh.vertexNormals, blended);

  ASSERT_EQ(split.valid.sum(), mesh.F.rows());
  ASSERT_EQ(unsplit.valid.sum(), mesh.F.rows());
  EXPECT_LT(split.principalCurvatures.cwiseAbs().maxCoeff(), 1e-10);
  EXPECT_GT(unsplit.principalCurvatures.cwiseAbs().maxCoeff(), 0.1);
}

TEST(FaceCurvaturePhase1, NormalTransportPreservesIsotropicTensor) {
  const Eigen::Vector3d sourceNormal(0.0, 0.0, 1.0);
  const Eigen::Vector3d targetNormal =
      Eigen::Vector3d(0.3, -0.4, 0.866025403784).normalized();
  const Eigen::Matrix3d rotation =
      directional::transport_rotation_between_normals(sourceNormal,
                                                       targetNormal);

  Eigen::Vector3d sourceX(1.0, 0.0, 0.0);
  Eigen::Vector3d sourceY(0.0, 1.0, 0.0);
  const Eigen::Vector3d targetX = rotation * sourceX;
  const Eigen::Vector3d targetY = rotation * sourceY;
  Eigen::Matrix<double, 3, 2> sourceBasis;
  sourceBasis << sourceX, sourceY;
  Eigen::Matrix<double, 3, 2> targetBasis;
  targetBasis << targetX, targetY;

  const Eigen::Matrix2d sourceTensor = 2.0 * Eigen::Matrix2d::Identity();
  const Eigen::Matrix3d ambient =
      sourceBasis * sourceTensor * sourceBasis.transpose();
  const Eigen::Matrix3d transported = rotation * ambient * rotation.transpose();
  const Eigen::Matrix2d restricted =
      targetBasis.transpose() * transported * targetBasis;

  EXPECT_TRUE(restricted.isApprox(sourceTensor, 1e-12));
}

TEST(RegularizedCurvatureFieldPhase1, ProducesAlignedCylinderField) {
  const MeshFixture input = make_open_cylinder();
  directional::fields::RegularizedCurvatureCrossFieldOptions options;
  options.proxy.smoothnessWeight = 1e-3;
  options.minimumConfidence = 1e-4;
  options.curvature.smoothingIterations = 1;

  const auto result =
      directional::fields::extract_regularized_curvature_cross_field(
          input.vertices, input.faces, options);

  EXPECT_EQ(result.field.rawField.rows(), input.faces.rows());
  EXPECT_EQ(result.field.rawField.cols(), 12);
  EXPECT_GT(result.constrainedFaces.size(), 0);
  EXPECT_TRUE(result.field.rawField.array().isFinite().all());
  EXPECT_TRUE(std::isfinite(result.smoothnessEnergy));
  EXPECT_TRUE(std::isfinite(result.alignmentEnergy));
}

TEST(RegularizedCurvatureFieldPhase1, SharpEdgesProvideFieldConstraints) {
  const MeshFixture input = make_folded_plate();
  directional::fields::RegularizedCurvatureCrossFieldOptions options;
  options.proxy.smoothnessWeight = 0.0;
  options.curvatureAlignmentWeight = 0.0;
  options.boundaryAlignmentWeight = 0.0;
  options.sharpFeatureAlignmentWeight = 1.0;
  options.curvature.sharpFeatureAngleDegrees = 60.0;
  options.computeMatching = false;

  const auto result =
      directional::fields::extract_regularized_curvature_cross_field(
          input.vertices, input.faces, options);

  ASSERT_EQ(result.constrainedFaces.size(), 2);
  ASSERT_EQ(result.constraintTypes.size(), 2);
  for (int index = 0; index < result.constraintTypes.size(); ++index) {
    EXPECT_EQ(
        result.constraintTypes(index),
        static_cast<int>(directional::fields::
                             RegularizedCrossFieldConstraintType::SharpFeature));
  }
  EXPECT_TRUE(result.field.rawField.array().isFinite().all());
  EXPECT_GT(result.sharpFeatureAlignmentEnergy, 0.0);
}
