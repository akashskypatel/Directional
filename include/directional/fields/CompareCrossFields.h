#pragma once

#ifndef DIRECTIONAL_FIELDS_COMPARE_CROSS_FIELDS_H
#define DIRECTIONAL_FIELDS_COMPARE_CROSS_FIELDS_H

#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <map>
#include <numbers>
#include <numeric>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Dense>

#include <directional/fields/ShapeOperatorAlignment.h>

/**
 * @file CompareCrossFields.h
 * @brief Face-wise and edge-wise comparison metrics for 4-RoSy cross fields.
 *
 * The comparison is intentionally representation-invariant for ordinary cross
 * fields: sign flips, branch permutations, and 90-degree rotations are compared
 * through a degree-4 complex representative in each face tangent basis.
 */

namespace directional::fields {

struct ScalarDistributionStats {
  double minimum = 0.0;
  double maximum = 0.0;
  double mean = 0.0;
  double median = 0.0;
  double p75 = 0.0;
  double p90 = 0.0;
  double p95 = 0.0;
  double p99 = 0.0;
  double rms = 0.0;
  double weightedMean = 0.0;
  double weightedRms = 0.0;
};

struct CrossFieldSmoothnessStats {
  ScalarDistributionStats angleDegrees;
  double weightedChordalEnergy = 0.0;
  Eigen::VectorXd edgeAngleDegrees;
  Eigen::VectorXd edgeWeights;
};

struct ShapeOperatorAlignmentStats {
  ScalarDistributionStats angleDegrees;
  ScalarDistributionStats normalizedEnergy;
  Eigen::Index validFaceCount = 0;
  double validAreaFraction = 0.0;
  double weightedMeanEnergy = 0.0;
};

struct HighErrorComponents {
  double thresholdDegrees = 20.0;
  Eigen::Index faceCount = 0;
  double areaFraction = 0.0;
  int componentCount = 0;
  Eigen::VectorXi componentSizes;
};

struct CrossFieldComparisonOptions {
  bool removeGlobalPhase = true;
  double highErrorThresholdDegrees = 20.0;

  /// Also evaluate each field against the regularized shape operator.
  bool computeShapeOperatorAlignment = false;

  /// Options for the optional NeurCross-style shape-operator diagnostic.
  ShapeOperatorAlignmentOptions shapeOperatorAlignment;
};

struct CrossFieldComparisonResult {
  Eigen::VectorXd faceDeviationDegrees;
  Eigen::VectorXd faceAreas;
  Eigen::MatrixXd faceCenters;
  ScalarDistributionStats faceDeviationStats;
  std::array<double, 7> withinDegreeFractions{{0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                               0.0}};
  std::array<double, 7> withinDegreeAreaFractions{{0.0, 0.0, 0.0, 0.0, 0.0,
                                                   0.0, 0.0}};
  std::array<double, 7> withinDegreeThresholds{{2.5, 5.0, 10.0, 15.0, 20.0,
                                                30.0, 40.0}};
  double globalPhaseDegrees = 0.0;
  CrossFieldSmoothnessStats firstSmoothness;
  CrossFieldSmoothnessStats secondSmoothness;
  bool hasShapeOperatorAlignment = false;
  ShapeOperatorAlignmentResult firstShapeOperatorAlignment;
  ShapeOperatorAlignmentResult secondShapeOperatorAlignment;
  ShapeOperatorAlignmentStats firstShapeOperatorStats;
  ShapeOperatorAlignmentStats secondShapeOperatorStats;
  HighErrorComponents highErrorComponents;
};

namespace compare_detail {

inline constexpr double pi = std::numbers::pi_v<double>;

inline void validate_mesh(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) {
  if (V.cols() != 3) {
    throw std::runtime_error("Mesh vertex matrix must have three columns.");
  }
  if (F.cols() != 3) {
    throw std::runtime_error("Cross-field comparison requires triangle faces.");
  }
  if (!V.array().isFinite().all()) {
    throw std::runtime_error("Mesh vertices contain non-finite values.");
  }
}

inline void validate_field(const Eigen::MatrixXd &field,
                           const Eigen::Index faceCount,
                           const std::string &name) {
  if (field.rows() != faceCount) {
    throw std::runtime_error(name + " row count does not match mesh faces.");
  }
  if (field.cols() != 6 && field.cols() != 12) {
    throw std::runtime_error(name +
                             " must contain 6 crossfield columns or 12 rawfield columns.");
  }
  if (!field.array().isFinite().all()) {
    throw std::runtime_error(name + " contains non-finite values.");
  }
}

inline Eigen::RowVector3d normalized_row(const Eigen::RowVector3d &value,
                                         const char *context) {
  const double norm = value.norm();
  if (!std::isfinite(norm) || norm <= 1e-30) {
    throw std::runtime_error(std::string("Cannot normalize near-zero vector in ") +
                             context + ".");
  }
  return value / norm;
}

inline void compute_face_geometry(const Eigen::MatrixXd &V,
                                  const Eigen::MatrixXi &F,
                                  Eigen::MatrixXd &normals,
                                  Eigen::MatrixXd &basisX,
                                  Eigen::MatrixXd &basisY,
                                  Eigen::MatrixXd &centers,
                                  Eigen::VectorXd &areas) {
  normals.resize(F.rows(), 3);
  basisX.resize(F.rows(), 3);
  basisY.resize(F.rows(), 3);
  centers.resize(F.rows(), 3);
  areas.resize(F.rows());

  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const Eigen::RowVector3d a = V.row(F(face, 0));
    const Eigen::RowVector3d b = V.row(F(face, 1));
    const Eigen::RowVector3d c = V.row(F(face, 2));
    const Eigen::RowVector3d ab = b - a;
    const Eigen::RowVector3d ac = c - a;
    const Eigen::RowVector3d n = ab.cross(ac);
    const double doubleArea = n.norm();
    if (!std::isfinite(doubleArea) || doubleArea <= 1e-30) {
      throw std::runtime_error("Degenerate triangle in mesh.");
    }
    normals.row(face) = n / doubleArea;
    basisX.row(face) = normalized_row(ab, "face basis");
    const Eigen::RowVector3d normal = normals.row(face);
    const Eigen::RowVector3d xAxis = basisX.row(face);
    basisY.row(face) = normalized_row(normal.cross(xAxis), "face basis");
    centers.row(face) = (a + b + c) / 3.0;
    areas(face) = 0.5 * doubleArea;
  }
}

inline std::complex<double> normalized_complex(std::complex<double> value) {
  const double magnitude = std::abs(value);
  if (!std::isfinite(magnitude) || magnitude <= 1e-30) {
    return {1.0, 0.0};
  }
  return value / magnitude;
}

inline std::complex<double> direction_q4(const Eigen::RowVector3d &direction,
                                         const Eigen::RowVector3d &basisX,
                                         const Eigen::RowVector3d &basisY) {
  const Eigen::RowVector3d unit = normalized_row(direction, "field direction");
  const std::complex<double> z(unit.dot(basisX), unit.dot(basisY));
  const std::complex<double> q = normalized_complex(z);
  return q * q * q * q;
}

inline Eigen::VectorXcd field_q4(const Eigen::MatrixXd &field,
                                 const Eigen::MatrixXd &basisX,
                                 const Eigen::MatrixXd &basisY) {
  Eigen::VectorXcd q4(field.rows());
  for (Eigen::Index face = 0; face < field.rows(); ++face) {
    q4(face) = direction_q4(field.block(face, 0, 1, 3), basisX.row(face),
                            basisY.row(face));
  }
  return q4;
}

inline double percentile_sorted(const std::vector<double> &sorted,
                                const double percentile) {
  if (sorted.empty()) {
    return 0.0;
  }
  const double position = (percentile / 100.0) *
                          static_cast<double>(sorted.size() - 1);
  const std::size_t lower = static_cast<std::size_t>(std::floor(position));
  const std::size_t upper = static_cast<std::size_t>(std::ceil(position));
  const double fraction = position - static_cast<double>(lower);
  return sorted[lower] * (1.0 - fraction) + sorted[upper] * fraction;
}

inline ScalarDistributionStats scalar_stats(const Eigen::VectorXd &values,
                                            const Eigen::VectorXd &weights) {
  ScalarDistributionStats stats;
  if (values.size() == 0) {
    return stats;
  }

  std::vector<double> sorted(values.data(), values.data() + values.size());
  std::sort(sorted.begin(), sorted.end());
  stats.minimum = sorted.front();
  stats.maximum = sorted.back();
  stats.median = percentile_sorted(sorted, 50.0);
  stats.p75 = percentile_sorted(sorted, 75.0);
  stats.p90 = percentile_sorted(sorted, 90.0);
  stats.p95 = percentile_sorted(sorted, 95.0);
  stats.p99 = percentile_sorted(sorted, 99.0);

  double sum = 0.0;
  double squareSum = 0.0;
  for (Eigen::Index i = 0; i < values.size(); ++i) {
    sum += values(i);
    squareSum += values(i) * values(i);
  }
  stats.mean = sum / static_cast<double>(values.size());
  stats.rms = std::sqrt(squareSum / static_cast<double>(values.size()));

  if (weights.size() == values.size() && weights.sum() > 0.0) {
    const double totalWeight = weights.sum();
    double weighted = 0.0;
    double weightedSquare = 0.0;
    for (Eigen::Index i = 0; i < values.size(); ++i) {
      weighted += weights(i) * values(i);
      weightedSquare += weights(i) * values(i) * values(i);
    }
    stats.weightedMean = weighted / totalWeight;
    stats.weightedRms = std::sqrt(weightedSquare / totalWeight);
  } else {
    stats.weightedMean = stats.mean;
    stats.weightedRms = stats.rms;
  }
  return stats;
}


inline ScalarDistributionStats masked_scalar_stats(
    const Eigen::VectorXd &values, const Eigen::VectorXd &weights,
    const Eigen::VectorXi &valid) {
  if (values.size() != valid.size()) {
    return {};
  }

  Eigen::Index count = 0;
  for (Eigen::Index i = 0; i < valid.size(); ++i) {
    if (valid(i) != 0) {
      ++count;
    }
  }
  if (count == 0) {
    return {};
  }

  Eigen::VectorXd filteredValues(count);
  Eigen::VectorXd filteredWeights(count);
  Eigen::Index output = 0;
  for (Eigen::Index i = 0; i < valid.size(); ++i) {
    if (valid(i) == 0) {
      continue;
    }
    filteredValues(output) = values(i);
    filteredWeights(output) =
        weights.size() == values.size() ? weights(i) : 1.0;
    ++output;
  }
  return scalar_stats(filteredValues, filteredWeights);
}

inline ShapeOperatorAlignmentStats shape_operator_stats(
    const ShapeOperatorAlignmentResult &alignment) {
  ShapeOperatorAlignmentStats stats;
  stats.validFaceCount = alignment.validFaceCount;
  stats.validAreaFraction = alignment.validAreaFraction;
  stats.weightedMeanEnergy = alignment.weightedMeanEnergy;
  stats.angleDegrees = masked_scalar_stats(
      alignment.angleDegrees, alignment.weights, alignment.valid);
  stats.normalizedEnergy = masked_scalar_stats(
      alignment.normalizedEnergy, alignment.weights, alignment.valid);
  return stats;
}

struct InteriorEdge {
  Eigen::Index firstFace = -1;
  Eigen::Index secondFace = -1;
  int firstVertex = -1;
  int secondVertex = -1;
};

inline std::vector<InteriorEdge> interior_edges(const Eigen::MatrixXi &F) {
  std::map<std::pair<int, int>, Eigen::Index> edgeToFace;
  std::vector<InteriorEdge> edges;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = F(face, corner);
      const int b = F(face, (corner + 1) % 3);
      const std::pair<int, int> key(std::min(a, b), std::max(a, b));
      const auto existing = edgeToFace.find(key);
      if (existing == edgeToFace.end()) {
        edgeToFace.emplace(key, face);
      } else {
        edges.push_back({existing->second, face, key.first, key.second});
        edgeToFace.erase(existing);
      }
    }
  }
  return edges;
}

inline CrossFieldSmoothnessStats smoothness_stats(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::MatrixXd &basisX, const Eigen::MatrixXd &basisY,
    const Eigen::VectorXd &areas, const Eigen::VectorXcd &q4) {
  const std::vector<InteriorEdge> edges = interior_edges(F);
  CrossFieldSmoothnessStats stats;
  stats.edgeAngleDegrees.resize(edges.size());
  stats.edgeWeights.resize(edges.size());
  double weightedChordal = 0.0;

  for (Eigen::Index edgeIndex = 0;
       edgeIndex < static_cast<Eigen::Index>(edges.size()); ++edgeIndex) {
    const InteriorEdge &edge = edges[edgeIndex];
    const Eigen::RowVector3d edgeVector =
        normalized_row(V.row(edge.secondVertex) - V.row(edge.firstVertex),
                       "shared edge");
    const std::complex<double> firstEdge(edgeVector.dot(basisX.row(edge.firstFace)),
                                         edgeVector.dot(basisY.row(edge.firstFace)));
    const std::complex<double> secondEdge(
        edgeVector.dot(basisX.row(edge.secondFace)),
        edgeVector.dot(basisY.row(edge.secondFace)));
    const std::complex<double> connection =
        normalized_complex(secondEdge) / normalized_complex(firstEdge);
    const std::complex<double> transported =
        std::pow(connection, 4) * q4(edge.firstFace);
    const std::complex<double> relative =
        q4(edge.secondFace) * std::conj(transported);
    const double angle = std::abs(std::arg(relative)) / 4.0;
    stats.edgeAngleDegrees(edgeIndex) = angle * 180.0 / compare_detail::pi;

    const double lengthSquared =
        (V.row(edge.secondVertex) - V.row(edge.firstVertex)).squaredNorm();
    const double areaSum = std::max(areas(edge.firstFace) + areas(edge.secondFace),
                                    1e-30);
    stats.edgeWeights(edgeIndex) = 3.0 * lengthSquared / areaSum;
    weightedChordal += stats.edgeWeights(edgeIndex) *
                       (2.0 - 2.0 * std::cos(4.0 * angle));
  }

  stats.angleDegrees = scalar_stats(stats.edgeAngleDegrees, stats.edgeWeights);
  const double weightSum = stats.edgeWeights.sum();
  stats.weightedChordalEnergy = weightSum > 0.0 ? weightedChordal / weightSum
                                                : 0.0;
  return stats;
}

inline HighErrorComponents high_error_components(
    const Eigen::MatrixXi &F, const Eigen::VectorXd &areas,
    const Eigen::VectorXd &deviationDegrees, const double thresholdDegrees) {
  HighErrorComponents result;
  result.thresholdDegrees = thresholdDegrees;
  if (F.rows() == 0) {
    return result;
  }

  std::vector<std::vector<Eigen::Index>> neighbors(F.rows());
  for (const InteriorEdge &edge : interior_edges(F)) {
    neighbors[edge.firstFace].push_back(edge.secondFace);
    neighbors[edge.secondFace].push_back(edge.firstFace);
  }

  std::vector<char> mask(F.rows(), 0);
  double highArea = 0.0;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    if (deviationDegrees(face) > thresholdDegrees) {
      mask[face] = 1;
      ++result.faceCount;
      highArea += areas(face);
    }
  }
  const double totalArea = areas.sum();
  result.areaFraction = totalArea > 0.0 ? highArea / totalArea : 0.0;

  std::vector<char> seen(F.rows(), 0);
  std::vector<int> componentSizes;
  std::queue<Eigen::Index> queue;
  for (Eigen::Index seed = 0; seed < F.rows(); ++seed) {
    if (!mask[seed] || seen[seed]) {
      continue;
    }
    seen[seed] = 1;
    queue.push(seed);
    int size = 0;
    while (!queue.empty()) {
      const Eigen::Index face = queue.front();
      queue.pop();
      ++size;
      for (const Eigen::Index neighbor : neighbors[face]) {
        if (mask[neighbor] && !seen[neighbor]) {
          seen[neighbor] = 1;
          queue.push(neighbor);
        }
      }
    }
    componentSizes.push_back(size);
  }
  std::sort(componentSizes.begin(), componentSizes.end(), std::greater<int>());
  result.componentCount = static_cast<int>(componentSizes.size());
  result.componentSizes.resize(componentSizes.size());
  for (Eigen::Index i = 0; i < static_cast<Eigen::Index>(componentSizes.size());
       ++i) {
    result.componentSizes(i) = componentSizes[static_cast<std::size_t>(i)];
  }
  return result;
}

inline std::array<unsigned char, 3> heatmap_color(double value,
                                                  double maximumDegrees) {
  const double t = std::clamp(value / std::max(maximumDegrees, 1e-30), 0.0, 1.0);
  if (t < 0.5) {
    const double u = t / 0.5;
    return {static_cast<unsigned char>(std::round(255.0 * u)),
            static_cast<unsigned char>(std::round(255.0 * u)),
            static_cast<unsigned char>(std::round(255.0 * (1.0 - u)))};
  }
  const double u = (t - 0.5) / 0.5;
  return {255,
          static_cast<unsigned char>(std::round(255.0 * (1.0 - u))),
          0};
}

} // namespace compare_detail

inline CrossFieldComparisonResult compare_cross_fields(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::MatrixXd &firstField, const Eigen::MatrixXd &secondField,
    const CrossFieldComparisonOptions &options = {}) {
  compare_detail::validate_mesh(V, F);
  compare_detail::validate_field(firstField, F.rows(), "First field");
  compare_detail::validate_field(secondField, F.rows(), "Second field");

  Eigen::MatrixXd normals;
  Eigen::MatrixXd basisX;
  Eigen::MatrixXd basisY;
  CrossFieldComparisonResult result;
  compare_detail::compute_face_geometry(V, F, normals, basisX, basisY,
                                        result.faceCenters, result.faceAreas);

  const Eigen::VectorXcd firstQ4 =
      compare_detail::field_q4(firstField, basisX, basisY);
  const Eigen::VectorXcd secondQ4 =
      compare_detail::field_q4(secondField, basisX, basisY);

  std::complex<double> meanRelative(0.0, 0.0);
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    meanRelative += result.faceAreas(face) *
                    secondQ4(face) * std::conj(firstQ4(face));
  }
  result.globalPhaseDegrees = std::arg(meanRelative) * 180.0 / (4.0 * compare_detail::pi);
  const std::complex<double> phaseCorrection =
      options.removeGlobalPhase
          ? std::exp(std::complex<double>(0.0,
                                          4.0 * result.globalPhaseDegrees *
                                              compare_detail::pi / 180.0))
          : std::complex<double>(1.0, 0.0);

  result.faceDeviationDegrees.resize(F.rows());
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const std::complex<double> relative =
        secondQ4(face) * std::conj(phaseCorrection * firstQ4(face));
    result.faceDeviationDegrees(face) =
        std::abs(std::arg(relative)) * 180.0 / (4.0 * compare_detail::pi);
  }

  result.faceDeviationStats =
      compare_detail::scalar_stats(result.faceDeviationDegrees,
                                   result.faceAreas);
  for (std::size_t threshold = 0; threshold < result.withinDegreeThresholds.size();
       ++threshold) {
    Eigen::Index count = 0;
    double area = 0.0;
    for (Eigen::Index face = 0; face < F.rows(); ++face) {
      if (result.faceDeviationDegrees(face) <=
          result.withinDegreeThresholds[threshold]) {
        ++count;
        area += result.faceAreas(face);
      }
    }
    result.withinDegreeFractions[threshold] =
        F.rows() > 0 ? static_cast<double>(count) / static_cast<double>(F.rows())
                     : 0.0;
    result.withinDegreeAreaFractions[threshold] =
        result.faceAreas.sum() > 0.0 ? area / result.faceAreas.sum() : 0.0;
  }

  result.firstSmoothness = compare_detail::smoothness_stats(
      V, F, basisX, basisY, result.faceAreas, firstQ4);
  result.secondSmoothness = compare_detail::smoothness_stats(
      V, F, basisX, basisY, result.faceAreas, secondQ4);

  if (options.computeShapeOperatorAlignment) {
    TriMesh mesh;
    mesh.set_mesh(V, F);
    result.firstShapeOperatorAlignment = evaluate_shape_operator_alignment(
        mesh, firstField, options.shapeOperatorAlignment);
    result.secondShapeOperatorAlignment = evaluate_shape_operator_alignment(
        mesh, secondField, options.shapeOperatorAlignment);
    result.firstShapeOperatorStats = compare_detail::shape_operator_stats(
        result.firstShapeOperatorAlignment);
    result.secondShapeOperatorStats = compare_detail::shape_operator_stats(
        result.secondShapeOperatorAlignment);
    result.hasShapeOperatorAlignment = true;
  }

  result.highErrorComponents = compare_detail::high_error_components(
      F, result.faceAreas, result.faceDeviationDegrees,
      options.highErrorThresholdDegrees);
  return result;
}

inline void write_cross_field_comparison_csv(
    const std::filesystem::path &path, const CrossFieldComparisonResult &result) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open comparison CSV: " + path.string());
  }
  stream << std::setprecision(std::numeric_limits<double>::digits10 + 1);
  stream << "face_index,centroid_x,centroid_y,centroid_z,face_area,"
            "cross_field_difference_degrees";
  if (result.hasShapeOperatorAlignment) {
    stream << ",first_shape_operator_alignment_degrees,"
              "second_shape_operator_alignment_degrees,"
              "first_shape_operator_energy,"
              "second_shape_operator_energy,"
              "shape_operator_confidence";
  }
  stream << '\n';
  for (Eigen::Index face = 0; face < result.faceDeviationDegrees.size(); ++face) {
    stream << face << ',' << result.faceCenters(face, 0) << ','
           << result.faceCenters(face, 1) << ',' << result.faceCenters(face, 2)
           << ',' << result.faceAreas(face) << ','
           << result.faceDeviationDegrees(face);
    if (result.hasShapeOperatorAlignment) {
      stream << ',' << result.firstShapeOperatorAlignment.angleDegrees(face)
             << ',' << result.secondShapeOperatorAlignment.angleDegrees(face)
             << ',' << result.firstShapeOperatorAlignment.normalizedEnergy(face)
             << ',' << result.secondShapeOperatorAlignment.normalizedEnergy(face)
             << ',' << result.firstShapeOperatorAlignment.confidence(face);
    }
    stream << '\n';
  }
}

inline void write_cross_field_comparison_ply(
    const std::filesystem::path &path, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const CrossFieldComparisonResult &result,
    const double maximumDegrees = 45.0) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open comparison PLY: " + path.string());
  }
  stream << std::setprecision(std::numeric_limits<double>::digits10 + 1);
  stream << "ply\nformat ascii 1.0\n";
  stream << "element vertex " << F.rows() * 3 << "\n";
  stream << "property float x\nproperty float y\nproperty float z\n";
  stream << "property uchar red\nproperty uchar green\nproperty uchar blue\n";
  stream << "element face " << F.rows() << "\n";
  stream << "property list uchar int vertex_indices\nend_header\n";
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const auto color = compare_detail::heatmap_color(
        result.faceDeviationDegrees(face), maximumDegrees);
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = F(face, corner);
      stream << V(vertex, 0) << ' ' << V(vertex, 1) << ' ' << V(vertex, 2)
             << ' ' << static_cast<int>(color[0]) << ' '
             << static_cast<int>(color[1]) << ' '
             << static_cast<int>(color[2]) << '\n';
    }
  }
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const Eigen::Index base = face * 3;
    stream << "3 " << base << ' ' << base + 1 << ' ' << base + 2 << '\n';
  }
}

inline void write_cross_field_comparison_json(
    const std::filesystem::path &path, const CrossFieldComparisonResult &result) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open comparison JSON: " + path.string());
  }
  stream << std::setprecision(std::numeric_limits<double>::digits10 + 1);
  const auto &s = result.faceDeviationStats;
  const auto write_stats = [&stream](const ScalarDistributionStats &stats) {
    stream << "{\n"
           << "      \"minimum\": " << stats.minimum << ",\n"
           << "      \"maximum\": " << stats.maximum << ",\n"
           << "      \"mean\": " << stats.mean << ",\n"
           << "      \"median\": " << stats.median << ",\n"
           << "      \"p75\": " << stats.p75 << ",\n"
           << "      \"p90\": " << stats.p90 << ",\n"
           << "      \"p95\": " << stats.p95 << ",\n"
           << "      \"p99\": " << stats.p99 << ",\n"
           << "      \"rms\": " << stats.rms << ",\n"
           << "      \"weighted_mean\": " << stats.weightedMean << ",\n"
           << "      \"weighted_rms\": " << stats.weightedRms << "\n"
           << "    }";
  };

  stream << "{\n";
  stream << "  \"face_count\": " << result.faceDeviationDegrees.size()
         << ",\n";
  stream << "  \"global_phase_degrees\": " << result.globalPhaseDegrees
         << ",\n";
  stream << "  \"face_deviation_degrees\": ";
  write_stats(s);
  stream << ",\n  \"within_thresholds\": [\n";
  for (std::size_t i = 0; i < result.withinDegreeThresholds.size(); ++i) {
    stream << "    {\"degrees\": " << result.withinDegreeThresholds[i]
           << ", \"face_fraction\": " << result.withinDegreeFractions[i]
           << ", \"area_fraction\": "
           << result.withinDegreeAreaFractions[i] << "}";
    if (i + 1 != result.withinDegreeThresholds.size()) {
      stream << ',';
    }
    stream << '\n';
  }
  stream << "  ],\n";
  stream << "  \"first_smoothness_degrees\": ";
  write_stats(result.firstSmoothness.angleDegrees);
  stream << ",\n  \"first_weighted_chordal_energy\": "
         << result.firstSmoothness.weightedChordalEnergy << ",\n";
  stream << "  \"second_smoothness_degrees\": ";
  write_stats(result.secondSmoothness.angleDegrees);
  stream << ",\n  \"second_weighted_chordal_energy\": "
         << result.secondSmoothness.weightedChordalEnergy << ",\n";
  if (result.hasShapeOperatorAlignment) {
    stream << "  \"shape_operator_alignment\": {\n";
    stream << "    \"first_valid_face_count\": "
           << result.firstShapeOperatorStats.validFaceCount << ",\n";
    stream << "    \"first_valid_area_fraction\": "
           << result.firstShapeOperatorStats.validAreaFraction << ",\n";
    stream << "    \"first_weighted_mean_energy\": "
           << result.firstShapeOperatorStats.weightedMeanEnergy << ",\n";
    stream << "    \"first_angle_degrees\": ";
    write_stats(result.firstShapeOperatorStats.angleDegrees);
    stream << ",\n    \"first_normalized_energy\": ";
    write_stats(result.firstShapeOperatorStats.normalizedEnergy);
    stream << ",\n    \"second_valid_face_count\": "
           << result.secondShapeOperatorStats.validFaceCount << ",\n";
    stream << "    \"second_valid_area_fraction\": "
           << result.secondShapeOperatorStats.validAreaFraction << ",\n";
    stream << "    \"second_weighted_mean_energy\": "
           << result.secondShapeOperatorStats.weightedMeanEnergy << ",\n";
    stream << "    \"second_angle_degrees\": ";
    write_stats(result.secondShapeOperatorStats.angleDegrees);
    stream << ",\n    \"second_normalized_energy\": ";
    write_stats(result.secondShapeOperatorStats.normalizedEnergy);
    stream << "\n  },\n";
  }
  stream << "  \"high_error\": {\n"
         << "    \"threshold_degrees\": "
         << result.highErrorComponents.thresholdDegrees << ",\n"
         << "    \"face_count\": " << result.highErrorComponents.faceCount
         << ",\n"
         << "    \"area_fraction\": "
         << result.highErrorComponents.areaFraction << ",\n"
         << "    \"component_count\": "
         << result.highErrorComponents.componentCount << ",\n"
         << "    \"component_sizes\": [";
  for (Eigen::Index i = 0; i < result.highErrorComponents.componentSizes.size();
       ++i) {
    if (i != 0) {
      stream << ", ";
    }
    stream << result.highErrorComponents.componentSizes(i);
  }
  stream << "]\n  }\n}\n";
}

inline std::string summarize_cross_field_comparison(
    const CrossFieldComparisonResult &result) {
  std::ostringstream stream;
  stream << std::setprecision(6);
  const auto &s = result.faceDeviationStats;
  stream << "Field difference: median " << s.median << " deg, mean "
         << s.mean << " deg, area-weighted mean " << s.weightedMean
         << " deg, p95 " << s.p95 << " deg, p99 " << s.p99 << " deg.\n";
  stream << "Global phase offset: " << result.globalPhaseDegrees << " deg.\n";
  stream << "Faces within 5/10/20 deg: " << result.withinDegreeFractions[1]
         << ", " << result.withinDegreeFractions[2] << ", "
         << result.withinDegreeFractions[4] << ".\n";
  stream << "High-error faces > "
         << result.highErrorComponents.thresholdDegrees << " deg: "
         << result.highErrorComponents.faceCount << " faces, "
         << 100.0 * result.highErrorComponents.areaFraction
         << "% area, " << result.highErrorComponents.componentCount
         << " connected components.\n";
  if (result.hasShapeOperatorAlignment) {
    stream << "Shape-operator alignment: first mean "
           << result.firstShapeOperatorStats.angleDegrees.weightedMean
           << " deg, second mean "
           << result.secondShapeOperatorStats.angleDegrees.weightedMean
           << " deg; first energy "
           << result.firstShapeOperatorStats.weightedMeanEnergy
           << ", second energy "
           << result.secondShapeOperatorStats.weightedMeanEnergy << ".\n";
  }
  return stream.str();
}

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_COMPARE_CROSS_FIELDS_H
