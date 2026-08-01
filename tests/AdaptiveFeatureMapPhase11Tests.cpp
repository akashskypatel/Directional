#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/AdaptiveFeatureMapVisualizer.h>

#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::AdaptiveFeatureClass;
using directional::geometry::AdaptiveFeatureCurve;
using directional::geometry::AdaptiveFeatureMap;
using directional::geometry::AdaptiveFeatureMapBuilder;
using directional::geometry::AdaptiveFeatureMapOptions;

std::pair<int, int> edge(const int a, const int b) {
  return AdaptiveFeatureMap::canonical_edge(a, b);
}

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshFixture make_hinge_strip(const double angleDegrees) {
  const double angle = angleDegrees * 3.14159265358979323846 / 180.0;
  MeshFixture mesh;
  mesh.vertices.resize(11, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 2.0, 0.0, 0.0, 3.0,
      0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 2.0,
      1.0, 0.0, 3.0, 1.0, 0.0, 4.0, 1.0, 0.0, 2.5, std::cos(angle),
      std::sin(angle);
  mesh.faces.resize(9, 3);
  mesh.faces << 0, 1, 6, 0, 6, 5, 1, 2, 7, 1, 7, 6, 2, 3, 8, 2, 8, 7,
      3, 4, 9, 3, 9, 8, 2, 3, 10;
  return mesh;
}

MeshFixture make_two_close_tetrahedra_with_tagged_edge() {
  MeshFixture mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.8, 0.0, 0.5,
      0.25, 0.75, 0.0, 0.0, 0.001, 1.0, 0.0, 0.001, 0.5, 0.8, 0.001,
      0.5, 0.25, 0.751;
  mesh.faces.resize(8, 3);
  mesh.faces << 0, 1, 2, 0, 3, 1, 1, 3, 2, 2, 3, 0, 4, 6, 5, 4, 5, 7,
      5, 6, 7, 6, 4, 7;
  return mesh;
}

MeshFixture make_offset_tetrahedron(const double zOffset) {
  MeshFixture mesh;
  mesh.vertices.resize(4, 3);
  mesh.vertices << 0.0, 0.0, zOffset, 1.0, 0.0, zOffset, 0.5, 0.8,
      zOffset, 0.5, 0.25, zOffset + 0.75;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 3, 1, 1, 3, 2, 2, 3, 0;
  return mesh;
}

MeshFixture make_square_ring() {
  MeshFixture mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << -1.0, -1.0, 0.0, 1.0, -1.0, 0.0, 1.0, 1.0, 0.0,
      -1.0, 1.0, 0.0, -0.4, -0.4, 0.0, 0.4, -0.4, 0.0, 0.4, 0.4,
      0.0, -0.4, 0.4, 0.0;
  mesh.faces.resize(8, 3);
  mesh.faces << 0, 1, 5, 0, 5, 4, 1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6,
      3, 0, 4, 3, 4, 7;
  return mesh;
}

MeshFixture make_scrambled_square_ring() {
  MeshFixture mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << -1.0, -1.0, 0.0, 0.4, -0.4, 0.0, 1.0, 1.0, 0.0,
      0.4, 0.4, 0.0, -1.0, 1.0, 0.0, -0.4, 0.4, 0.0, 1.0, -1.0,
      0.0, -0.4, -0.4, 0.0;
  mesh.faces.resize(8, 3);
  mesh.faces << 0, 6, 1, 0, 1, 7, 6, 2, 3, 6, 3, 1, 2, 4, 5, 2, 5, 3,
      4, 0, 7, 4, 7, 5;
  return mesh;
}

MeshFixture make_cube_surface() {
  MeshFixture mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0,
      -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
      1.0, -1.0, 1.0, 1.0;
  mesh.faces.resize(12, 3);
  mesh.faces << 0, 2, 1, 0, 3, 2, 4, 5, 6, 4, 6, 7, 0, 1, 5, 0, 5, 4,
      1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7;
  return mesh;
}

MeshFixture make_noisy_flat_grid(const int subdivisions,
                                 const double amplitude) {
  const int n = std::max(1, subdivisions);
  MeshFixture mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices(vertex, 0) = static_cast<double>(x);
      mesh.vertices(vertex, 1) = static_cast<double>(y);
      mesh.vertices(vertex, 2) =
          amplitude * std::sin(0.37 * static_cast<double>(x + 3 * y));
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

MeshFixture make_irregular_organic_fan() {
  constexpr int samples = 24;
  MeshFixture mesh;
  mesh.vertices.resize(samples + 1, 3);
  mesh.vertices.row(0).setZero();
  for (int sample = 0; sample < samples; ++sample) {
    const double angle =
        2.0 * 3.14159265358979323846 * static_cast<double>(sample) /
        static_cast<double>(samples);
    const double height =
        0.3 * (std::sin(3.0 * angle) +
               0.45 * std::sin(7.0 * angle + 0.2));
    mesh.vertices.row(sample + 1)
        << std::cos(angle), std::sin(angle), height;
  }
  mesh.faces.resize(samples, 3);
  for (int sample = 0; sample < samples; ++sample) {
    mesh.faces.row(sample)
        << 0, sample + 1, ((sample + 1) % samples) + 1;
  }
  return mesh;
}

MeshFixture make_open_crease_strip(const int segments,
                                   const double angleDegrees) {
  const int n = std::max(1, segments);
  const double angle = angleDegrees * 3.14159265358979323846 / 180.0;
  MeshFixture mesh;
  mesh.vertices.resize(3 * (n + 1), 3);
  for (int x = 0; x <= n; ++x) {
    mesh.vertices.row(x) << static_cast<double>(x), 0.0, 0.0;
    mesh.vertices.row((n + 1) + x) << static_cast<double>(x), 1.0, 0.0;
    mesh.vertices.row(2 * (n + 1) + x)
        << static_cast<double>(x), -std::cos(angle), std::sin(angle);
  }
  mesh.faces.resize(4 * n, 3);
  int face = 0;
  for (int x = 0; x < n; ++x) {
    const int c0 = x;
    const int c1 = x + 1;
    const int l0 = (n + 1) + x;
    const int l1 = (n + 1) + x + 1;
    const int r0 = 2 * (n + 1) + x;
    const int r1 = 2 * (n + 1) + x + 1;
    mesh.faces.row(face++) << c0, c1, l1;
    mesh.faces.row(face++) << c0, l1, l0;
    mesh.faces.row(face++) << c1, c0, r1;
    mesh.faces.row(face++) << c0, r0, r1;
  }
  return mesh;
}

MeshFixture make_beveled_strip(const int segments) {
  const int n = std::max(1, segments);
  const double bevel = 3.14159265358979323846 / 4.0;
  MeshFixture mesh;
  mesh.vertices.resize(4 * (n + 1), 3);
  for (int x = 0; x <= n; ++x) {
    mesh.vertices.row(x) << static_cast<double>(x), -1.0, 0.0;
    mesh.vertices.row((n + 1) + x) << static_cast<double>(x), 0.0, 0.0;
    mesh.vertices.row(2 * (n + 1) + x)
        << static_cast<double>(x), std::cos(bevel), std::sin(bevel);
    mesh.vertices.row(3 * (n + 1) + x)
        << static_cast<double>(x), std::cos(bevel) + 1.0, std::sin(bevel);
  }
  mesh.faces.resize(6 * n, 3);
  int face = 0;
  for (int x = 0; x < n; ++x) {
    for (int strip = 0; strip < 3; ++strip) {
      const int row0 = strip * (n + 1);
      const int row1 = (strip + 1) * (n + 1);
      const int a = row0 + x;
      const int b = row0 + x + 1;
      const int c = row1 + x;
      const int d = row1 + x + 1;
      mesh.faces.row(face++) << a, b, d;
      mesh.faces.row(face++) << a, d, c;
    }
  }
  return mesh;
}

MeshFixture make_scrambled_bent_crease() {
  MeshFixture mesh;
  mesh.vertices.resize(12, 3);
  mesh.vertices.row(4) << 0.0, 0.0, 0.0;
  mesh.vertices.row(0) << 1.0, 0.0, 0.0;
  mesh.vertices.row(7) << 2.0, 0.0, 0.0;
  mesh.vertices.row(2) << 2.0, 1.0, 0.0;
  mesh.vertices.row(5) << 0.0, 0.7, 0.0;
  mesh.vertices.row(1) << 1.0, 0.7, 0.0;
  mesh.vertices.row(8) << 2.0, 0.7, 0.0;
  mesh.vertices.row(3) << 2.7, 1.0, 0.0;
  mesh.vertices.row(6) << 0.0, -0.7, 0.35;
  mesh.vertices.row(9) << 1.0, -0.7, 0.35;
  mesh.vertices.row(10) << 2.0, -0.7, 0.35;
  mesh.vertices.row(11) << 1.3, 1.0, 0.35;
  mesh.faces.resize(12, 3);
  const int center[4] = {4, 0, 7, 2};
  const int left[4] = {5, 1, 8, 3};
  const int right[4] = {6, 9, 10, 11};
  int face = 0;
  for (int i = 0; i < 3; ++i) {
    mesh.faces.row(face++) << center[i], center[i + 1], left[i + 1];
    mesh.faces.row(face++) << center[i], left[i + 1], left[i];
    mesh.faces.row(face++) << center[i + 1], center[i], right[i + 1];
    mesh.faces.row(face++) << center[i], right[i], right[i + 1];
  }
  return mesh;
}

Eigen::MatrixXd rotate_and_scale(const Eigen::MatrixXd &vertices) {
  Eigen::MatrixXd transformed = vertices;
  const double angle = 0.37;
  Eigen::Matrix3d rotation;
  rotation << std::cos(angle), -std::sin(angle), 0.0, std::sin(angle),
      std::cos(angle), 0.0, 0.0, 0.0, 1.0;
  for (int row = 0; row < transformed.rows(); ++row) {
    transformed.row(row) = (3.5 * rotation * vertices.row(row).transpose())
                               .transpose();
  }
  return transformed;
}

MeshFixture combine_meshes(const MeshFixture &first, const MeshFixture &second,
                           const Eigen::RowVector3d &offset) {
  MeshFixture combined;
  combined.vertices.resize(first.vertices.rows() + second.vertices.rows(), 3);
  combined.vertices.topRows(first.vertices.rows()) = first.vertices;
  combined.vertices.bottomRows(second.vertices.rows()) = second.vertices;
  for (int row = first.vertices.rows(); row < combined.vertices.rows(); ++row) {
    combined.vertices.row(row) += offset;
  }
  combined.faces.resize(first.faces.rows() + second.faces.rows(), 3);
  combined.faces.topRows(first.faces.rows()) = first.faces;
  combined.faces.bottomRows(second.faces.rows()) =
      second.faces.array() + first.vertices.rows();
  return combined;
}

std::pair<double, double>
hard_feature_precision_recall(const AdaptiveFeatureMap &map,
                              const std::set<std::pair<int, int>> &labels);

double hard_feature_f1(const AdaptiveFeatureMap &map,
                       const std::set<std::pair<int, int>> &labels) {
  const auto [precision, recall] = hard_feature_precision_recall(map, labels);
  return precision + recall == 0.0
             ? 0.0
             : 2.0 * precision * recall / (precision + recall);
}

std::pair<double, double>
hard_feature_precision_recall(const AdaptiveFeatureMap &map,
                              const std::set<std::pair<int, int>> &labels) {
  int truePositive = 0;
  int falsePositive = 0;
  int falseNegative = 0;
  for (const auto &featureEdge : map.edges) {
    const bool predicted =
        featureEdge.edgeClass == AdaptiveFeatureClass::Hard;
    const bool labeled = labels.count(featureEdge.vertices) != 0;
    if (predicted && labeled) {
      ++truePositive;
    } else if (predicted) {
      ++falsePositive;
    } else if (labeled) {
      ++falseNegative;
    }
  }
  const double precision = truePositive + falsePositive == 0
                               ? 0.0
                               : static_cast<double>(truePositive) /
                                     (truePositive + falsePositive);
  const double recall = truePositive + falseNegative == 0
                            ? 0.0
                            : static_cast<double>(truePositive) /
                                  (truePositive + falseNegative);
  return {precision, recall};
}

std::set<std::pair<int, int>> cube_sharp_labels() {
  return {edge(0, 1), edge(1, 2), edge(2, 3), edge(0, 3),
          edge(4, 5), edge(5, 6), edge(6, 7), edge(4, 7),
          edge(0, 4), edge(1, 5), edge(2, 6), edge(3, 7)};
}

std::set<std::pair<int, int>> open_crease_labels(const int segments) {
  std::set<std::pair<int, int>> labels;
  for (int x = 0; x < segments; ++x) {
    labels.insert(edge(x, x + 1));
  }
  return labels;
}

std::set<std::pair<int, int>> bevel_labels(const int segments) {
  const int row1 = segments + 1;
  const int row2 = 2 * (segments + 1);
  std::set<std::pair<int, int>> labels;
  for (int x = 0; x < segments; ++x) {
    labels.insert(edge(row1 + x, row1 + x + 1));
    labels.insert(edge(row2 + x, row2 + x + 1));
  }
  return labels;
}

double hard_feature_recall(const AdaptiveFeatureMap &map,
                           const std::set<std::pair<int, int>> &labels) {
  int detected = 0;
  for (const auto &label : labels) {
    if (map.edge_class(label) == AdaptiveFeatureClass::Hard) {
      ++detected;
    }
  }
  return labels.empty() ? 1.0
                        : static_cast<double>(detected) /
                              static_cast<double>(labels.size());
}

double continuity_recall(const AdaptiveFeatureMap &map,
                         const std::set<std::pair<int, int>> &labels) {
  std::map<int, int> countsByCurve;
  for (const auto &label : labels) {
    const int index = map.find_edge(label);
    if (index < 0) {
      continue;
    }
    const int curve = map.edges[static_cast<std::size_t>(index)].curve;
    if (curve >= 0) {
      ++countsByCurve[curve];
    }
  }
  int best = 0;
  for (const auto &[curve, count] : countsByCurve) {
    (void)curve;
    best = std::max(best, count);
  }
  return labels.empty() ? 1.0
                        : static_cast<double>(best) /
                              static_cast<double>(labels.size());
}

TEST(AdaptiveFeatureMapPhase11, AnalyticHingeStrengthIncreasesWithAngle) {
  const MeshFixture low = make_hinge_strip(12.0);
  const MeshFixture high = make_hinge_strip(70.0);

  const auto lowMap =
      AdaptiveFeatureMapBuilder::build(low.vertices, low.faces);
  const auto highMap =
      AdaptiveFeatureMapBuilder::build(high.vertices, high.faces);

  EXPECT_LT(lowMap.strength(edge(2, 3)), 0.55);
  EXPECT_GT(highMap.strength(edge(2, 3)), 0.80);
  EXPECT_EQ(highMap.edge_class(edge(2, 3)), AdaptiveFeatureClass::Hard);
}

TEST(AdaptiveFeatureMapPhase11, UserHardAndSoftOverridesAreApplied) {
  const MeshFixture mesh = make_hinge_strip(5.0);
  AdaptiveFeatureMapOptions options;
  options.userHardEdges.insert(edge(2, 3));
  options.userSoftEdges.insert(edge(3, 8));

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                    options);

  EXPECT_EQ(map.edge_class(edge(2, 3)), AdaptiveFeatureClass::Hard);
  EXPECT_DOUBLE_EQ(map.strength(edge(2, 3)), 1.0);
  EXPECT_EQ(map.edge_class(edge(3, 8)), AdaptiveFeatureClass::Soft);
  EXPECT_GE(map.strength(edge(3, 8)), options.growStrength);
}

TEST(AdaptiveFeatureMapPhase11, LabeledHardFeaturePrecisionRecallGate) {
  const MeshFixture mesh = make_hinge_strip(70.0);
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  const std::set<std::pair<int, int>> labels{edge(2, 3)};
  const auto [precision, recall] = hard_feature_precision_recall(map, labels);

  EXPECT_GE(precision, 0.95);
  EXPECT_GE(recall, 0.95);
  EXPECT_GE(hard_feature_f1(map, labels), 0.95);
}

TEST(AdaptiveFeatureMapPhase11, PerComponentCadOrganicMixtureIsIndependent) {
  const MeshFixture cad = make_hinge_strip(70.0);
  const MeshFixture organic = make_hinge_strip(12.0);
  const MeshFixture mixed =
      combine_meshes(cad, organic, Eigen::RowVector3d(10.0, 0.0, 0.0));

  const auto map = AdaptiveFeatureMapBuilder::build(mixed.vertices,
                                                    mixed.faces);

  EXPECT_EQ(map.edge_class(edge(2, 3)), AdaptiveFeatureClass::Hard);
  EXPECT_EQ(map.edge_class(edge(13, 14)), AdaptiveFeatureClass::Smooth);
  ASSERT_GE(map.componentStats.size(), 2U);
  EXPECT_NE(map.componentStats[0].cadLike, map.componentStats[1].cadLike);
}

TEST(AdaptiveFeatureMapPhase11, CubeFeaturesMeetLabeledPrecisionRecallGate) {
  const MeshFixture mesh = make_cube_surface();
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);
  const auto labels = cube_sharp_labels();

  const auto [precision, recall] = hard_feature_precision_recall(map, labels);
  EXPECT_GE(precision, 0.95);
  EXPECT_GE(recall, 0.95);
  EXPECT_GE(hard_feature_f1(map, labels), 0.95);
}

TEST(AdaptiveFeatureMapPhase11, BevelRailsMeetRetessellatedF1Gate) {
  constexpr int segments = 8;
  const MeshFixture mesh = make_beveled_strip(segments);
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  EXPECT_GE(hard_feature_f1(map, bevel_labels(segments)), 0.90);
}

TEST(AdaptiveFeatureMapPhase11, NoisySphereLikePatchDoesNotCreateHardNoise) {
  const MeshFixture mesh = make_noisy_flat_grid(5, 0.015);
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  std::size_t hardInteriorEdges = 0;
  for (const auto &featureEdge : map.edges) {
    if (featureEdge.edgeClass == AdaptiveFeatureClass::Hard &&
        featureEdge.incidentFaces.size() == 2) {
      ++hardInteriorEdges;
    }
  }
  EXPECT_EQ(hardInteriorEdges, 0U);
}

TEST(AdaptiveFeatureMapPhase11,
     BroadOrganicDihedralTailDoesNotImplyCadComponent) {
  const MeshFixture mesh = make_irregular_organic_fan();
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  ASSERT_EQ(map.componentStats.size(), 1U);
  const auto &stats = map.componentStats.front();
  EXPECT_GT(stats.p98Degrees, 60.0);
  EXPECT_GT(stats.p50Degrees, 10.0);
  EXPECT_LT(stats.p75Degrees, 70.0);
  EXPECT_FALSE(stats.cadLike);
}

TEST(AdaptiveFeatureMapPhase11,
     IsolatedOrganicSpikesRemainSoftSizingAndFieldCues) {
  const MeshFixture mesh = make_irregular_organic_fan();
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  int hardInteriorEdges = 0;
  int strongSoftInteriorEdges = 0;
  for (const auto &featureEdge : map.edges) {
    if (featureEdge.incidentFaces.size() != 2) {
      continue;
    }
    hardInteriorEdges +=
        featureEdge.edgeClass == AdaptiveFeatureClass::Hard ? 1 : 0;
    strongSoftInteriorEdges +=
        featureEdge.edgeClass == AdaptiveFeatureClass::Soft &&
                featureEdge.strength >= 0.80
            ? 1
            : 0;
  }
  EXPECT_EQ(hardInteriorEdges, 0);
  EXPECT_GT(strongSoftInteriorEdges, 0);
}

TEST(AdaptiveFeatureMapPhase11, CoherentOrganicRailRemainsHard) {
  constexpr int segments = 8;
  const MeshFixture mesh = make_open_crease_strip(segments, 70.0);
  AdaptiveFeatureMapOptions options;
  options.cadMedianCeilingDegrees = -1.0;
  options.cadUpperQuartileFloorDegrees = 181.0;

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                    options);

  ASSERT_EQ(map.componentStats.size(), 1U);
  EXPECT_FALSE(map.componentStats.front().cadLike);
  EXPECT_GE(hard_feature_recall(map, open_crease_labels(segments)), 0.95);
}

TEST(AdaptiveFeatureMapPhase11, UserHardOrganicSpikeIsNeverDemoted) {
  const MeshFixture mesh = make_irregular_organic_fan();
  AdaptiveFeatureMapOptions options;
  options.userHardEdges.insert(edge(0, 1));

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                    options);

  EXPECT_FALSE(map.componentStats.front().cadLike);
  EXPECT_EQ(map.edge_class(edge(0, 1)), AdaptiveFeatureClass::Hard);
  EXPECT_DOUBLE_EQ(map.strength(edge(0, 1)), 1.0);
}

TEST(AdaptiveFeatureMapPhase11, OpenCreaseContinuityRecallGate) {
  constexpr int segments = 8;
  const MeshFixture mesh = make_open_crease_strip(segments, 70.0);
  const auto labels = open_crease_labels(segments);

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  EXPECT_GE(hard_feature_recall(map, labels), 0.95);
  EXPECT_GE(continuity_recall(map, labels), 0.98);
}

TEST(AdaptiveFeatureMapPhase11, RetessellatedFeatureF1Gate) {
  constexpr int segments = 10;
  const MeshFixture mesh = make_open_crease_strip(segments, 70.0);

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  EXPECT_GE(hard_feature_f1(map, open_crease_labels(segments)), 0.90);
}

TEST(AdaptiveFeatureMapPhase11, BoundaryAndNonManifoldAreClassified) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0,
      0.0, 0.0, 0.0, 1.0;
  Eigen::MatrixXi faces(3, 3);
  faces << 0, 1, 2, 1, 0, 3, 0, 1, 4;

  const auto map = AdaptiveFeatureMapBuilder::build(vertices, faces);

  EXPECT_TRUE(map.hasNonManifold);
  EXPECT_EQ(map.edge_class(edge(0, 1)), AdaptiveFeatureClass::NonManifold);
  EXPECT_EQ(map.edge_class(edge(1, 2)), AdaptiveFeatureClass::Boundary);
}

TEST(AdaptiveFeatureMapPhase11, ClosedBoundaryRingIsExtractedAsClosedCurve) {
  const MeshFixture mesh = make_square_ring();

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  bool foundInnerClosedLoop = false;
  for (const auto &curve : map.curves) {
    std::set<int> vertices(curve.vertices.begin(), curve.vertices.end());
    if (curve.closed && vertices == std::set<int>{4, 5, 6, 7}) {
      foundInnerClosedLoop = true;
    }
  }
  EXPECT_TRUE(foundInnerClosedLoop);
}

TEST(AdaptiveFeatureMapPhase11, StrengthIsRotationAndScaleInvariant) {
  const MeshFixture mesh = make_hinge_strip(70.0);
  const Eigen::MatrixXd transformed = rotate_and_scale(mesh.vertices);

  const auto original = AdaptiveFeatureMapBuilder::build(mesh.vertices,
                                                         mesh.faces);
  const auto moved = AdaptiveFeatureMapBuilder::build(transformed, mesh.faces);

  ASSERT_EQ(original.edges.size(), moved.edges.size());
  for (const auto &featureEdge : original.edges) {
    EXPECT_NEAR(featureEdge.strength, moved.strength(featureEdge.vertices),
                1.0e-10);
  }
}

TEST(AdaptiveFeatureMapPhase11, DensityDoesNotLeakAcrossDisconnectedCloseSheet) {
  const MeshFixture mesh = make_two_close_tetrahedra_with_tagged_edge();
  AdaptiveFeatureMapOptions options;
  options.userHardEdges.insert(edge(0, 1));
  options.cadAbsoluteLowDegrees = 179.0;
  options.cadAbsoluteHighDegrees = 180.0;
  options.organicAbsoluteLowDegrees = 179.0;
  options.organicAbsoluteHighDegrees = 180.0;
  options.densityRadius = 2.0;

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                    options);

  EXPECT_GT(map.vertexDensity(0), 0.0);
  EXPECT_GT(map.vertexDensity(1), 0.0);
  EXPECT_EQ(map.vertexDensity(4), 0.0);
  EXPECT_EQ(map.vertexDensity(5), 0.0);
  EXPECT_EQ(map.vertexDensity(6), 0.0);
  EXPECT_EQ(map.vertexDensity(7), 0.0);
}

TEST(AdaptiveFeatureMapPhase11, DefaultDensityMatchesIsolatedCloseComponent) {
  const MeshFixture combined = make_two_close_tetrahedra_with_tagged_edge();
  const MeshFixture isolated = make_offset_tetrahedron(0.001);

  const auto combinedMap =
      AdaptiveFeatureMapBuilder::build(combined.vertices, combined.faces);
  const auto isolatedMap =
      AdaptiveFeatureMapBuilder::build(isolated.vertices, isolated.faces);

  for (int vertex = 0; vertex < isolated.vertices.rows(); ++vertex) {
    EXPECT_NEAR(combinedMap.vertexDensity(4 + vertex),
                isolatedMap.vertexDensity(vertex), 1.0e-12);
  }
}

TEST(AdaptiveFeatureMapPhase11, DeterministicSamplingDoesNotDependOnInputOrder) {
  MeshFixture mesh = make_hinge_strip(70.0);
  AdaptiveFeatureMapOptions options;
  options.exactQuantileEdgeLimit = 1;
  options.sampledQuantileEdgeCount = 3;

  const auto first = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                      options);
  Eigen::MatrixXi reordered(mesh.faces.rows(), 3);
  for (int row = 0; row < mesh.faces.rows(); ++row) {
    reordered.row(row) = mesh.faces.row(mesh.faces.rows() - row - 1);
  }
  const auto second = AdaptiveFeatureMapBuilder::build(mesh.vertices, reordered,
                                                       options);

  EXPECT_DOUBLE_EQ(first.strength(edge(2, 3)), second.strength(edge(2, 3)));
  EXPECT_EQ(first.edge_class(edge(2, 3)), second.edge_class(edge(2, 3)));
}

TEST(AdaptiveFeatureMapPhase11, OverlayExposesStrengthClassCurveAndDensity) {
  const MeshFixture mesh = make_square_ring();
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  const auto overlay =
      directional::geometry::make_adaptive_feature_map_overlay(map);

  ASSERT_EQ(overlay.edgeStrength.rows(), static_cast<int>(map.edges.size()));
  ASSERT_EQ(overlay.edgeClass.rows(), static_cast<int>(map.edges.size()));
  ASSERT_EQ(overlay.edgeCurveId.rows(), static_cast<int>(map.edges.size()));
  ASSERT_EQ(overlay.vertexDensity.rows(), mesh.vertices.rows());
  EXPECT_GE(overlay.edgeStrength.maxCoeff(), 1.0);
  EXPECT_GE(overlay.edgeClass.maxCoeff(),
            static_cast<int>(AdaptiveFeatureClass::Boundary));
}

TEST(AdaptiveFeatureMapPhase11, CanonicalEdgeIndexBacksRepeatedLookup) {
  const MeshFixture mesh = make_open_crease_strip(12, 70.0);
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  ASSERT_EQ(map.edgeIndex.size(), map.edges.size());
  for (int repeat = 0; repeat < 1000; ++repeat) {
    EXPECT_GE(map.find_edge(edge(3, 4)), 0);
    EXPECT_GT(map.strength(edge(3, 4)), 0.0);
    EXPECT_NE(map.edge_class(edge(3, 4)), AdaptiveFeatureClass::Smooth);
  }
}

TEST(AdaptiveFeatureMapPhase11, FeatureCurveOrderDoesNotSortVertexIds) {
  const MeshFixture mesh = make_scrambled_square_ring();
  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces);

  const AdaptiveFeatureCurve *best = nullptr;
  for (const auto &curve : map.curves) {
    if (curve.closed && curve.edges.size() == 4) {
      best = &curve;
      break;
    }
  }
  ASSERT_NE(best, nullptr);
  ASSERT_GE(best->vertices.size(), 4U);
  std::vector<int> sorted = best->vertices;
  if (!sorted.empty() && sorted.front() == sorted.back()) {
    sorted.pop_back();
  }
  std::sort(sorted.begin(), sorted.end());
  std::vector<int> ordered = best->vertices;
  if (!ordered.empty() && ordered.front() == ordered.back()) {
    ordered.pop_back();
  }
  EXPECT_NE(ordered, sorted);
  for (std::size_t i = 0; i + 1 < best->vertices.size(); ++i) {
    EXPECT_GE(map.find_edge(edge(best->vertices[i], best->vertices[i + 1])), 0);
  }
}

TEST(AdaptiveFeatureMapPhase11, TangentIncompatibleHysteresisSplitsCurve) {
  const MeshFixture mesh = make_scrambled_bent_crease();
  AdaptiveFeatureMapOptions options;
  options.userHardEdges = {edge(4, 0), edge(0, 7), edge(7, 2)};
  options.tangentContinuationDegrees = 20.0;

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                    options);

  EXPECT_GT(map.tangentRejectedEdges, 0U);
  int curveWithAllCenterEdges = 0;
  for (const auto &curve : map.curves) {
    std::set<std::pair<int, int>> curveEdges;
    for (const int edgeIndex : curve.edges) {
      curveEdges.insert(map.edges[static_cast<std::size_t>(edgeIndex)].vertices);
    }
    if (curveEdges.count(edge(4, 0)) && curveEdges.count(edge(0, 7)) &&
        curveEdges.count(edge(7, 2))) {
      ++curveWithAllCenterEdges;
    }
  }
  EXPECT_EQ(curveWithAllCenterEdges, 0);
}

TEST(AdaptiveFeatureMapPhase11, SmoothRidgeValleyConfidenceIsRecorded) {
  const MeshFixture mesh = make_hinge_strip(40.0);
  AdaptiveFeatureMapOptions options;
  options.hardSeedStrength = 0.99;
  options.growStrength = 0.20;

  const auto map = AdaptiveFeatureMapBuilder::build(mesh.vertices, mesh.faces,
                                                    options);
  const int ridge = map.find_edge(edge(2, 3));
  ASSERT_GE(ridge, 0);
  EXPECT_GT(map.edges[static_cast<std::size_t>(ridge)].ridgeValleyConfidence,
            0.0);
  EXPECT_NE(map.edge_class(edge(2, 3)), AdaptiveFeatureClass::Smooth);
}

} // namespace
