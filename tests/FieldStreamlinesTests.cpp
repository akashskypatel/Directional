#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/visualization/FieldStreamlines.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>

namespace {

struct Fixture {
  directional::TriMesh mesh;
  Eigen::MatrixXd raw;
};

const Fixture &sphere() {
  static const Fixture fixture = [] {
    Fixture loaded;
    const auto stem = directional::tests::benchmark_fixture_path(
        "milestone-g/sphere_prescribed");
    if (!directional::readOBJ(stem.string() + ".obj", loaded.mesh)) {
      throw std::runtime_error("Failed to read sphere_prescribed.obj");
    }
    std::ifstream stream(stem.string() + ".rawfield");
    int degree = 0;
    int faces = 0;
    if (!(stream >> degree >> faces) || degree != 4 ||
        faces != loaded.mesh.F.rows()) {
      throw std::runtime_error("Invalid sphere_prescribed.rawfield");
    }
    loaded.raw.resize(faces, 12);
    for (int face = 0; face < faces; ++face) {
      for (int column = 0; column < 12; ++column) {
        stream >> loaded.raw(face, column);
      }
    }
    return loaded;
  }();
  return fixture;
}

double average_edge_length(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) {
  std::set<std::pair<int, int>> edges;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = F(face, corner);
      const int b = F(face, (corner + 1) % 3);
      edges.insert({std::min(a, b), std::max(a, b)});
    }
  }
  double sum = 0.0;
  for (const auto &[a, b] : edges) sum += (V.row(a) - V.row(b)).norm();
  return sum / static_cast<double>(edges.size());
}

// Whether `point` lies in triangle `face` (within `tolerance` of its plane
// and inside its edges).
bool in_face(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
             const Eigen::Index face, const Eigen::RowVector3d &point,
             const double tolerance) {
  const Eigen::RowVector3d a = V.row(F(face, 0));
  const Eigen::RowVector3d b = V.row(F(face, 1));
  const Eigen::RowVector3d c = V.row(F(face, 2));
  const Eigen::RowVector3d normal = (b - a).cross(c - a);
  const double area2 = normal.norm();
  if (std::abs((point - a).dot(normal / area2)) > tolerance) return false;
  const double wa = (c - b).cross(point - b).dot(normal) / (area2 * area2);
  const double wb = (a - c).cross(point - c).dot(normal) / (area2 * area2);
  const double wc = 1.0 - wa - wb;
  const double slack = 1e-6;
  return wa >= -slack && wb >= -slack && wc >= -slack;
}

} // namespace

TEST(FieldStreamlines, SegmentsFollowTheFieldFromSpacedSeeds) {
  const Fixture &fixture = sphere();
  directional::visualization::FieldStreamlineOptions options;
  options.seedSpacing = 2.0;
  options.steps = 40;
  options.stepLength = 0.5;
  options.surfaceOffset = 0.0;
  const auto lines = directional::visualization::trace_field_streamlines(
      fixture.mesh.V, fixture.mesh.F, fixture.raw, options);

  const double edge = average_edge_length(fixture.mesh.V, fixture.mesh.F);
  EXPECT_NEAR(edge, lines.averageEdgeLength, 1e-12 * edge);
  ASSERT_GT(lines.seedFaces.size(), 1);
  EXPECT_EQ(static_cast<std::size_t>(2 * lines.seedFaces.size()), lines.lineCount);
  ASSERT_GT(lines.edges.rows(), 0);
  ASSERT_TRUE(lines.points.allFinite());

  // Seeds are distinct faces whose barycenters are at least the spacing apart.
  std::set<int> seedSet;
  for (Eigen::Index i = 0; i < lines.seedFaces.size(); ++i) {
    EXPECT_TRUE(seedSet.insert(lines.seedFaces(i)).second);
    for (Eigen::Index j = 0; j < i; ++j) {
      const auto center = [&](const int face) {
        return Eigen::RowVector3d((fixture.mesh.V.row(fixture.mesh.F(face, 0)) +
                                   fixture.mesh.V.row(fixture.mesh.F(face, 1)) +
                                   fixture.mesh.V.row(fixture.mesh.F(face, 2))) /
                                  3.0);
      };
      EXPECT_GE((center(lines.seedFaces(i)) - center(lines.seedFaces(j))).norm(),
                options.seedSpacing * edge * (1.0 - 1e-12));
    }
  }

  // Independent oracle: each segment lies in a face and runs along one of
  // that face's four input directions; ids are consistent; each streamline
  // (two half-lines) is at most 2 * steps * stepLength edge lengths long.
  std::map<int, double> lineLength;
  Eigen::Index aligned = 0;
  for (Eigen::Index segment = 0; segment < lines.edges.rows(); ++segment) {
    const Eigen::RowVector3d start = lines.points.row(lines.edges(segment, 0));
    const Eigen::RowVector3d end = lines.points.row(lines.edges(segment, 1));
    const int line = lines.edgeLine(segment);
    ASSERT_GE(line, 0);
    ASSERT_LT(static_cast<std::size_t>(line), lines.lineCount);
    EXPECT_EQ(line % 2, lines.edgeFamily(segment));
    lineLength[line] += (end - start).norm();
    if ((end - start).norm() < 1e-6 * edge) continue;
    const Eigen::RowVector3d direction = (end - start).normalized();
    bool followsField = false;
    for (Eigen::Index face = 0; face < fixture.mesh.F.rows() && !followsField;
         ++face) {
      if (!in_face(fixture.mesh.V, fixture.mesh.F, face, start, 1e-9 * edge) ||
          !in_face(fixture.mesh.V, fixture.mesh.F, face, end, 1e-9 * edge)) {
        continue;
      }
      for (int d = 0; d < 4; ++d) {
        const Eigen::RowVector3d field =
            fixture.raw.block<1, 3>(face, 3 * d).normalized();
        if (field.dot(direction) > 0.999) followsField = true;
      }
    }
    EXPECT_TRUE(followsField) << "segment " << segment;
    ++aligned;
  }
  EXPECT_GT(aligned, lines.edges.rows() / 2);
  for (const auto &[line, length] : lineLength) {
    EXPECT_LE(length, 2.0 * options.steps * options.stepLength * edge * (1.0 + 1e-9))
        << "line " << line;
  }
  // Each streamline's segments chain into one path: its two half-lines meet
  // at the seed, so at most two endpoints (the far ends) are unshared.
  std::map<int, std::map<std::array<double, 3>, int>> endpointDegree;
  for (Eigen::Index segment = 0; segment < lines.edges.rows(); ++segment) {
    for (int end = 0; end < 2; ++end) {
      const Eigen::RowVector3d point = lines.points.row(lines.edges(segment, end));
      ++endpointDegree[lines.edgeLine(segment)][{point.x(), point.y(), point.z()}];
    }
  }
  for (const auto &[line, degrees] : endpointDegree) {
    const auto loose = std::count_if(degrees.begin(), degrees.end(),
                                     [](const auto &entry) { return entry.second % 2 != 0; });
    EXPECT_LE(loose, 2) << "line " << line;
  }
  RecordProperty("seeds", static_cast<int>(lines.seedFaces.size()));
  RecordProperty("segments", static_cast<int>(lines.edges.rows()));
}

TEST(FieldStreamlines, IsDeterministicAndLiftsAlongTheNormal) {
  const Fixture &fixture = sphere();
  directional::visualization::FieldStreamlineOptions options;
  options.steps = 20;
  options.surfaceOffset = 0.0;
  const auto flat = directional::visualization::trace_field_streamlines(
      fixture.mesh.V, fixture.mesh.F, fixture.raw, options);
  const auto again = directional::visualization::trace_field_streamlines(
      fixture.mesh.V, fixture.mesh.F, fixture.raw, options);
  ASSERT_EQ(flat.points.rows(), again.points.rows());
  EXPECT_TRUE(flat.points == again.points);
  EXPECT_TRUE(flat.seedFaces == again.seedFaces);

  options.surfaceOffset = 0.1;
  const auto lifted = directional::visualization::trace_field_streamlines(
      fixture.mesh.V, fixture.mesh.F, fixture.raw, options);
  ASSERT_EQ(flat.points.rows(), lifted.points.rows());
  for (Eigen::Index row = 0; row < flat.points.rows(); ++row) {
    EXPECT_NEAR((lifted.points.row(row) - flat.points.row(row)).norm(),
                0.1 * flat.averageEdgeLength, 1e-9 * flat.averageEdgeLength);
  }

  options.seedSpacing = 0.0;
  const auto everyFace = directional::visualization::trace_field_streamlines(
      fixture.mesh.V, fixture.mesh.F, fixture.raw, options);
  EXPECT_EQ(fixture.mesh.F.rows(), everyFace.seedFaces.size());
}

TEST(FieldStreamlines, RejectsInvalidInput) {
  const Fixture &fixture = sphere();
  directional::visualization::FieldStreamlineOptions options;
  EXPECT_THROW(directional::visualization::trace_field_streamlines(
                   fixture.mesh.V, fixture.mesh.F, fixture.raw.leftCols(6),
                   options),
               std::invalid_argument);
  options.steps = 0;
  EXPECT_THROW(directional::visualization::trace_field_streamlines(
                   fixture.mesh.V, fixture.mesh.F, fixture.raw, options),
               std::invalid_argument);
  options.steps = 10;
  options.stepLength = 0.0;
  EXPECT_THROW(directional::visualization::trace_field_streamlines(
                   fixture.mesh.V, fixture.mesh.F, fixture.raw, options),
               std::invalid_argument);
}
