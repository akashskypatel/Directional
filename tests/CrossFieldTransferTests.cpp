#include <directional/fields/CrossFieldTransfer.h>

#include <gtest/gtest.h>

namespace {

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                          const Eigen::RowVector3d &b) {
  return Eigen::RowVector3d(a.y() * b.z() - a.z() * b.y(),
                            a.z() * b.x() - a.x() * b.z(),
                            a.x() * b.y() - a.y() * b.x());
}

directional::TriMesh make_planar_mesh(const Eigen::MatrixXi &faces) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

Eigen::MatrixXd constant_planar_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.block(face, 0, 1, 3) << 1.0, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, 1.0, 0.0;
    raw.block(face, 6, 1, 3) << -1.0, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -1.0, 0.0;
  }
  return raw;
}

TEST(CrossFieldTransferPhase07,
     FieldTransferPreservesConstantPlanarCrossField) {
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2, 0, 2, 3;
  Eigen::MatrixXi targetFaces(2, 3);
  targetFaces << 0, 1, 3, 1, 2, 3;
  const directional::TriMesh source = make_planar_mesh(sourceFaces);
  const directional::TriMesh target = make_planar_mesh(targetFaces);

  const Eigen::MatrixXd transferred =
      directional::fields::CrossFieldTransfer::transfer_raw_field_nearest_face(
          source, constant_planar_raw_field(source.F.rows()), target, true);

  ASSERT_EQ(transferred.rows(), target.F.rows());
  for (int face = 0; face < transferred.rows(); ++face) {
    const Eigen::RowVector3d primary = transferred.block(face, 0, 1, 3);
    const Eigen::RowVector3d secondary = transferred.block(face, 3, 1, 3);
    EXPECT_NEAR(primary.dot(Eigen::RowVector3d(1, 0, 0)), 1.0, 1.0e-12);
    EXPECT_NEAR(secondary.dot(Eigen::RowVector3d(0, 1, 0)), 1.0,
                1.0e-12);
  }
}

TEST(CrossFieldTransferPhase07,
     FieldTransferPreservesCylinderAxialCircumferentialFieldModuloRosySymmetry) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;
  directional::TriMesh source;
  source.set_mesh(vertices, faces);
  directional::TriMesh target;
  target.set_mesh(vertices, faces);

  Eigen::MatrixXd raw(2, 12);
  for (int face = 0; face < 2; ++face) {
    raw.block(face, 0, 1, 3) << 0.0, 0.0, 1.0;
    const Eigen::RowVector3d normal = source.faceNormals.row(face);
    raw.block(face, 3, 1, 3) = cross3(normal, Eigen::RowVector3d(0, 0, 1));
    raw.block(face, 3, 1, 3).normalize();
    raw.block(face, 6, 1, 3) = -raw.block(face, 0, 1, 3);
    raw.block(face, 9, 1, 3) = -raw.block(face, 3, 1, 3);
  }

  const Eigen::MatrixXd transferred =
      directional::fields::CrossFieldTransfer::transfer_raw_field_nearest_face(
          source, raw, target, true);

  for (int face = 0; face < transferred.rows(); ++face) {
    const Eigen::RowVector3d primary = transferred.block(face, 0, 1, 3);
    const double axialAlignment =
        std::abs(primary.dot(Eigen::RowVector3d(0, 0, 1)));
    EXPECT_NEAR(axialAlignment, 1.0, 1.0e-12);
  }
}

TEST(CrossFieldTransferPhase07,
     FieldTransferProducesFiniteNormalizedRawField) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  const directional::TriMesh mesh = make_planar_mesh(faces);

  const Eigen::MatrixXd transferred =
      directional::fields::CrossFieldTransfer::transfer_raw_field_nearest_face(
          mesh, constant_planar_raw_field(mesh.F.rows()), mesh, true);

  EXPECT_TRUE(transferred.array().isFinite().all());
  for (int face = 0; face < transferred.rows(); ++face) {
    for (int direction = 0; direction < 4; ++direction) {
      const Eigen::RowVector3d axis =
          transferred.block(face, 3 * direction, 1, 3);
      EXPECT_NEAR(axis.norm(), 1.0, 1.0e-12);
    }
  }
}

} // namespace
