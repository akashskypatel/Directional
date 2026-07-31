#include <directional/fields/CompareCrossFields.h>

namespace directional::fields::compare_detail {

void validate_mesh(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) {
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

void validate_field(const Eigen::MatrixXd &field,
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

Eigen::RowVector3d normalized_row(const Eigen::RowVector3d &value,
                                         const char *context) {
  const double norm = value.norm();
  if (!std::isfinite(norm) || norm <= 1e-30) {
    throw std::runtime_error(std::string("Cannot normalize near-zero vector in ") +
                             context + ".");
  }
  return value / norm;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

void compute_face_geometry(const Eigen::MatrixXd &V,
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

std::complex<double> normalized_complex(std::complex<double> value) {
  const double magnitude = std::abs(value);
  if (!std::isfinite(magnitude) || magnitude <= 1e-30) {
    return {1.0, 0.0};
  }
  return value / magnitude;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

std::complex<double> direction_q4(const Eigen::RowVector3d &direction,
                                         const Eigen::RowVector3d &basisX,
                                         const Eigen::RowVector3d &basisY) {
  const Eigen::RowVector3d unit = normalized_row(direction, "field direction");
  const std::complex<double> z(unit.dot(basisX), unit.dot(basisY));
  const std::complex<double> q = normalized_complex(z);
  return q * q * q * q;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

Eigen::VectorXcd field_q4(const Eigen::MatrixXd &field,
                                 const Eigen::MatrixXd &basisX,
                                 const Eigen::MatrixXd &basisY) {
  Eigen::VectorXcd q4(field.rows());
  for (Eigen::Index face = 0; face < field.rows(); ++face) {
    q4(face) = direction_q4(field.block(face, 0, 1, 3), basisX.row(face),
                            basisY.row(face));
  }
  return q4;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

Eigen::MatrixXd raw_cross_field(const Eigen::MatrixXd &field) {
  if (field.cols() == 12) {
    return field;
  }
  Eigen::MatrixXd raw(field.rows(), 12);
  raw.leftCols<3>() = field.leftCols<3>();
  raw.middleCols<3>(3) = field.middleCols<3>(3);
  raw.middleCols<3>(6) = -field.leftCols<3>();
  raw.middleCols<3>(9) = -field.middleCols<3>(3);
  return raw;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

double percentile_sorted(const std::vector<double> &sorted,
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

ScalarDistributionStats scalar_stats(const Eigen::VectorXd &values,
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

ScalarDistributionStats scalar_stats(const std::vector<double> &values) {
  if (values.empty()) {
    return {};
  }
  Eigen::VectorXd eigenValues(values.size());
  Eigen::VectorXd weights = Eigen::VectorXd::Ones(values.size());
  for (Eigen::Index i = 0; i < eigenValues.size(); ++i) {
    eigenValues(i) = values[static_cast<std::size_t>(i)];
  }
  return scalar_stats(eigenValues, weights);
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

ScalarDistributionStats masked_scalar_stats(
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

ShapeOperatorAlignmentStats shape_operator_stats(
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

double average_edge_length(const Eigen::MatrixXd &V,
                                  const Eigen::MatrixXi &F) {
  double total = 0.0;
  Eigen::Index count = 0;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      total += (V.row(F(face, corner)) -
                V.row(F(face, (corner + 1) % 3)))
                   .norm();
      ++count;
    }
  }
  return count > 0 ? total / static_cast<double>(count) : 1.0;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

Eigen::VectorXd vertex_area_weights(const Eigen::MatrixXi &F,
                                           const Eigen::VectorXd &faceAreas,
                                           const Eigen::Index vertexCount) {
  Eigen::VectorXd weights = Eigen::VectorXd::Zero(vertexCount);
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const double contribution = faceAreas(face) / 3.0;
    for (int corner = 0; corner < 3; ++corner) {
      weights(F(face, corner)) += contribution;
    }
  }
  return weights;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

CrossFieldTopologyStats
topology_stats(const PCFaceTangentBundle &tangentBundle,
               const Eigen::Index vertexCount,
               const Eigen::MatrixXd &field) {
  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, crossFieldDegree);
  rawField.set_extrinsic_field(raw_cross_field(field));
  principal_matching(rawField);

  CrossFieldTopologyStats stats;
  stats.singularVertices = rawField.singLocalCycles;
  stats.singularNumerators = rawField.singIndices;
  stats.vertexNumerators = Eigen::VectorXi::Zero(vertexCount);
  for (Eigen::Index i = 0; i < stats.singularVertices.size(); ++i) {
    const int vertex = stats.singularVertices(i);
    if (vertex < 0 || vertex >= vertexCount) {
      continue;
    }
    const int numerator = stats.singularNumerators(i);
    stats.vertexNumerators(vertex) += numerator;
    if (numerator > 0) {
      ++stats.positiveCount;
    } else if (numerator < 0) {
      ++stats.negativeCount;
    }
    stats.totalAbsoluteIndex +=
        std::abs(static_cast<double>(numerator)) /
        static_cast<double>(crossFieldDegree);
  }
  return stats;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

CrossFieldTopologyComparison topology_comparison(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::VectorXd &faceAreas, const Eigen::MatrixXd &firstField,
    const Eigen::MatrixXd &secondField) {
  CrossFieldTopologyComparison result;
  TriMesh mesh;
  mesh.set_mesh(V, F);
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(mesh);
  result.first = topology_stats(tangentBundle, V.rows(), firstField);
  result.second = topology_stats(tangentBundle, V.rows(), secondField);

  const Eigen::VectorXd vertexWeights =
      vertex_area_weights(F, faceAreas, V.rows());
  double mismatchedArea = 0.0;
  for (Eigen::Index vertex = 0; vertex < V.rows(); ++vertex) {
    const int first = result.first.vertexNumerators(vertex);
    const int second = result.second.vertexNumerators(vertex);
    if (first == second) {
      if (first != 0) {
        ++result.matchingSingularityCount;
      }
      continue;
    }

    ++result.mismatchedVertexCount;
    mismatchedArea += vertexWeights(vertex);
    result.l1IndexDifference +=
        std::abs(static_cast<double>(first - second)) /
        static_cast<double>(crossFieldDegree);
    if (first != 0 && second == 0) {
      ++result.firstOnlyCount;
    } else if (first == 0 && second != 0) {
      ++result.secondOnlyCount;
    } else {
      ++result.differingIndexCount;
    }
  }
  const double totalArea = vertexWeights.sum();
  result.mismatchedVertexAreaFraction =
      totalArea > 0.0 ? mismatchedArea / totalArea : 0.0;

  const double edgeLength = std::max(average_edge_length(V, F), 1e-30);
  const auto directed_distances =
      [&](const CrossFieldTopologyStats &source,
          const CrossFieldTopologyStats &target,
          Eigen::Index &unmatched) -> ScalarDistributionStats {
    std::vector<double> distances;
    for (Eigen::Index sourceIndex = 0;
         sourceIndex < source.singularVertices.size(); ++sourceIndex) {
      const int sourceVertex = source.singularVertices(sourceIndex);
      const int numerator = source.singularNumerators(sourceIndex);
      double minimum = std::numeric_limits<double>::infinity();
      for (Eigen::Index targetIndex = 0;
           targetIndex < target.singularVertices.size(); ++targetIndex) {
        if (target.singularNumerators(targetIndex) != numerator) {
          continue;
        }
        const int targetVertex = target.singularVertices(targetIndex);
        minimum = std::min(
            minimum,
            (V.row(sourceVertex) - V.row(targetVertex)).norm() / edgeLength);
      }
      if (std::isfinite(minimum)) {
        distances.push_back(minimum);
      } else {
        ++unmatched;
      }
    }
    return scalar_stats(distances);
  };

  result.firstToSecondDistanceEdgeLengths = directed_distances(
      result.first, result.second, result.firstWithoutSameIndexReference);
  result.secondToFirstDistanceEdgeLengths = directed_distances(
      result.second, result.first, result.secondWithoutSameIndexReference);
  result.available = true;
  return result;
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

std::vector<InteriorEdge> interior_edges(const Eigen::MatrixXi &F) {
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

CrossFieldSmoothnessStats smoothness_stats(
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

HighErrorComponents high_error_components(
    const Eigen::MatrixXi &F, const Eigen::VectorXd &areas,
    const Eigen::MatrixXd &centers,
    const Eigen::VectorXd &deviationDegrees, const double thresholdDegrees) {
  HighErrorComponents result;
  result.thresholdDegrees = thresholdDegrees;
  result.faceComponentIds = Eigen::VectorXi::Constant(F.rows(), -1);
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

    HighErrorComponents::Component component;
    component.id = static_cast<int>(result.components.size());
    component.firstFace = seed;
    seen[seed] = 1;
    queue.push(seed);
    double componentArea = 0.0;
    double weightedDeviation = 0.0;
    Eigen::RowVector3d weightedCentroid = Eigen::RowVector3d::Zero();

    while (!queue.empty()) {
      const Eigen::Index face = queue.front();
      queue.pop();
      result.faceComponentIds(face) = component.id;
      ++component.faceCount;
      componentArea += areas(face);
      weightedDeviation += areas(face) * deviationDegrees(face);
      weightedCentroid += areas(face) * centers.row(face);
      component.maximumDegrees =
          std::max(component.maximumDegrees, deviationDegrees(face));
      for (const Eigen::Index neighbor : neighbors[face]) {
        if (mask[neighbor] && !seen[neighbor]) {
          seen[neighbor] = 1;
          queue.push(neighbor);
        }
      }
    }

    component.areaFraction =
        totalArea > 0.0 ? componentArea / totalArea : 0.0;
    if (componentArea > 0.0) {
      component.areaWeightedMeanDegrees =
          weightedDeviation / componentArea;
      component.areaWeightedCentroid = weightedCentroid / componentArea;
    }
    componentSizes.push_back(static_cast<int>(component.faceCount));
    result.components.push_back(component);
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

std::array<unsigned char, 3> heatmap_color(double value,
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

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

void write_json_string(std::ostream &stream, const std::string &value) {
  stream << '"';
  for (const unsigned char character : value) {
    switch (character) {
    case '"':
      stream << "\\\"";
      break;
    case '\\':
      stream << "\\\\";
      break;
    case '\b':
      stream << "\\b";
      break;
    case '\f':
      stream << "\\f";
      break;
    case '\n':
      stream << "\\n";
      break;
    case '\r':
      stream << "\\r";
      break;
    case '\t':
      stream << "\\t";
      break;
    default:
      if (character < 0x20) {
        stream << "\\u" << std::hex << std::setw(4) << std::setfill('0')
               << static_cast<int>(character) << std::dec << std::setfill(' ');
      } else {
        stream << static_cast<char>(character);
      }
      break;
    }
  }
  stream << '"';
}

} // namespace directional::fields::compare_detail

namespace directional::fields::compare_detail {

std::string utc_timestamp() {
  const std::time_t time = std::chrono::system_clock::to_time_t(
      std::chrono::system_clock::now());
  std::tm utc{};
#if defined(_WIN32)
  gmtime_s(&utc, &time);
#else
  gmtime_r(&time, &utc);
#endif
  std::ostringstream stream;
  stream << std::put_time(&utc, "%Y-%m-%dT%H:%M:%SZ");
  return stream.str();
}

} // namespace directional::fields::compare_detail

namespace directional::fields {

CrossFieldComparisonResult compare_cross_fields(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::MatrixXd &firstField, const Eigen::MatrixXd &secondField,
    const CrossFieldComparisonOptions &options) {
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

  result.faceSignedDeviationDegrees.resize(F.rows());
  result.faceDeviationDegrees.resize(F.rows());
  result.faceQ4SquaredChordalError.resize(F.rows());
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const std::complex<double> relative =
        secondQ4(face) * std::conj(phaseCorrection * firstQ4(face));
    const double signedAngle =
        std::arg(relative) * 180.0 / (4.0 * compare_detail::pi);
    result.faceSignedDeviationDegrees(face) = signedAngle;
    result.faceDeviationDegrees(face) = std::abs(signedAngle);
    result.faceQ4SquaredChordalError(face) =
        std::norm(secondQ4(face) - phaseCorrection * firstQ4(face));
  }

  result.faceDeviationStats =
      compare_detail::scalar_stats(result.faceDeviationDegrees,
                                   result.faceAreas);
  result.q4SquaredChordalErrorStats =
      compare_detail::scalar_stats(result.faceQ4SquaredChordalError,
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
      F, result.faceAreas, result.faceCenters, result.faceDeviationDegrees,
      options.highErrorThresholdDegrees);
  try {
    result.topology = compare_detail::topology_comparison(
        V, F, result.faceAreas, firstField, secondField);
  } catch (const std::exception &error) {
    result.topology.available = false;
    result.topology.error = error.what();
  }
  return result;
}

} // namespace directional::fields

namespace directional::fields {

void write_cross_field_comparison_csv(
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
            "cross_field_difference_degrees,signed_difference_degrees,"
            "q4_squared_chordal_error,high_error,high_error_component";
  if (result.hasShapeOperatorAlignment) {
    stream << ",candidate_shape_operator_alignment_degrees,"
              "reference_shape_operator_alignment_degrees,"
              "candidate_shape_operator_energy,"
              "reference_shape_operator_energy,"
              "shape_operator_confidence";
  }
  stream << '\n';
  for (Eigen::Index face = 0; face < result.faceDeviationDegrees.size(); ++face) {
    stream << face << ',' << result.faceCenters(face, 0) << ','
           << result.faceCenters(face, 1) << ',' << result.faceCenters(face, 2)
           << ',' << result.faceAreas(face) << ','
           << result.faceDeviationDegrees(face) << ','
           << result.faceSignedDeviationDegrees(face) << ','
           << result.faceQ4SquaredChordalError(face) << ','
           << (result.faceDeviationDegrees(face) >
                       result.highErrorComponents.thresholdDegrees
                   ? 1
                   : 0)
           << ',' << result.highErrorComponents.faceComponentIds(face);
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

} // namespace directional::fields

namespace directional::fields {

void write_cross_field_comparison_ply(
    const std::filesystem::path &path, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const CrossFieldComparisonResult &result,
    const double maximumDegrees) {
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

} // namespace directional::fields

namespace directional::fields {

void write_cross_field_comparison_json(
    const std::filesystem::path &path, const CrossFieldComparisonResult &result,
    const CrossFieldComparisonReportMetadata &metadata) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open comparison JSON: " + path.string());
  }
  stream << std::setprecision(std::numeric_limits<double>::digits10 + 1);

  const auto write_stats = [&stream](const ScalarDistributionStats &stats,
                                     const int indent) {
    const std::string pad(static_cast<std::size_t>(indent), ' ');
    const std::string child(static_cast<std::size_t>(indent + 2), ' ');
    stream << "{\n"
           << child << "\"minimum\": " << stats.minimum << ",\n"
           << child << "\"maximum\": " << stats.maximum << ",\n"
           << child << "\"mean\": " << stats.mean << ",\n"
           << child << "\"median\": " << stats.median << ",\n"
           << child << "\"p75\": " << stats.p75 << ",\n"
           << child << "\"p90\": " << stats.p90 << ",\n"
           << child << "\"p95\": " << stats.p95 << ",\n"
           << child << "\"p99\": " << stats.p99 << ",\n"
           << child << "\"rms\": " << stats.rms << ",\n"
           << child << "\"weighted_mean\": " << stats.weightedMean
           << ",\n"
           << child << "\"weighted_rms\": " << stats.weightedRms
           << "\n"
           << pad << "}";
  };

  const auto write_string_field = [&stream](const char *name,
                                             const std::string &value,
                                             const int indent,
                                             const bool comma = true) {
    stream << std::string(static_cast<std::size_t>(indent), ' ') << '"' << name
           << "\": ";
    compare_detail::write_json_string(stream, value);
    if (comma) {
      stream << ',';
    }
    stream << '\n';
  };

  const auto write_parameter_maps = [&stream, &metadata]() {
    stream << "      \"parameters\": {\n";
    bool first = true;
    auto separator = [&]() {
      if (!first) {
        stream << ",\n";
      }
      first = false;
    };
    for (const auto &[name, value] : metadata.candidateStringParameters) {
      separator();
      stream << "        ";
      compare_detail::write_json_string(stream, name);
      stream << ": ";
      compare_detail::write_json_string(stream, value);
    }
    for (const auto &[name, value] : metadata.candidateNumericParameters) {
      separator();
      stream << "        ";
      compare_detail::write_json_string(stream, name);
      stream << ": " << value;
    }
    for (const auto &[name, value] : metadata.candidateBooleanParameters) {
      separator();
      stream << "        ";
      compare_detail::write_json_string(stream, name);
      stream << ": " << (value ? "true" : "false");
    }
    if (!first) {
      stream << '\n';
    }
    stream << "      }\n";
  };

  stream << "{\n";
  write_string_field("schema", "directional.field-comparison", 2);
  stream << "  \"schema_version\": 1,\n";
  write_string_field("created_utc", compare_detail::utc_timestamp(), 2);
  stream << "  \"units\": {\"angle\": \"degrees\", "
            "\"length\": \"mesh_units\", "
            "\"area\": \"mesh_units_squared\"},\n";
  stream << "  \"weighting\": {"
            "\"face_error\": \"face_area\", "
            "\"smoothness\": \"dual_harmonic_edge_weight\", "
            "\"singularity_distance\": \"uniform\"},\n";
  stream << "  \"mesh\": {\n";
  write_string_field("path", metadata.meshPath, 4);
  stream << "    \"vertex_count\": " << metadata.vertexCount << ",\n"
         << "    \"face_count\": " << result.faceDeviationDegrees.size()
         << "\n  },\n";

  stream << "  \"candidate\": {\n";
  write_string_field("label", metadata.candidateLabel, 4);
  write_string_field("path", metadata.candidatePath, 4);
  write_parameter_maps();
  stream << "  },\n";
  stream << "  \"reference\": {\n";
  write_string_field("label", metadata.referenceLabel, 4);
  write_string_field("path", metadata.referencePath, 4);
  write_string_field("format", metadata.referenceFormat, 4, false);
  stream << "  },\n";

  stream << "  \"comparison\": {\n";
  stream << "    \"options\": {\"remove_global_phase\": "
         << (metadata.removeGlobalPhase ? "true" : "false")
         << ", \"shape_operator_alignment\": "
         << (metadata.shapeOperatorAlignment ? "true" : "false") << "},\n";
  stream << "    \"global_phase_degrees\": " << result.globalPhaseDegrees
         << ",\n";
  stream << "    \"primary_objective\": {\n"
         << "      \"name\": \"area_weighted_q4_squared_chordal_error\",\n"
         << "      \"value\": "
         << result.q4SquaredChordalErrorStats.weightedMean << ",\n"
         << "      \"lower_is_better\": true\n"
         << "    },\n";
  stream << "    \"angular_error_degrees\": ";
  write_stats(result.faceDeviationStats, 4);
  stream << ",\n    \"q4_squared_chordal_error\": ";
  write_stats(result.q4SquaredChordalErrorStats, 4);
  stream << ",\n";

  stream << "    \"within_thresholds\": [\n";
  for (std::size_t i = 0; i < result.withinDegreeThresholds.size(); ++i) {
    stream << "      {\"degrees\": " << result.withinDegreeThresholds[i]
           << ", \"face_fraction\": " << result.withinDegreeFractions[i]
           << ", \"area_fraction\": "
           << result.withinDegreeAreaFractions[i] << "}";
    if (i + 1 != result.withinDegreeThresholds.size()) {
      stream << ',';
    }
    stream << '\n';
  }
  stream << "    ],\n";

  const std::array<double, 9> histogramEdges{{0.0, 2.5, 5.0, 10.0, 15.0,
                                               20.0, 30.0, 40.0, 45.0}};
  stream << "    \"angular_error_histogram\": [\n";
  for (std::size_t bin = 0; bin + 1 < histogramEdges.size(); ++bin) {
    Eigen::Index count = 0;
    double area = 0.0;
    for (Eigen::Index face = 0; face < result.faceDeviationDegrees.size();
         ++face) {
      const double value = result.faceDeviationDegrees(face);
      const bool inside = value >= histogramEdges[bin] &&
                          (bin + 2 == histogramEdges.size()
                               ? value <= histogramEdges[bin + 1]
                               : value < histogramEdges[bin + 1]);
      if (inside) {
        ++count;
        area += result.faceAreas(face);
      }
    }
    stream << "      {\"minimum_degrees\": " << histogramEdges[bin]
           << ", \"maximum_degrees\": " << histogramEdges[bin + 1]
           << ", \"face_count\": " << count
           << ", \"face_fraction\": "
           << (result.faceDeviationDegrees.size() > 0
                   ? static_cast<double>(count) /
                         static_cast<double>(result.faceDeviationDegrees.size())
                   : 0.0)
           << ", \"area_fraction\": "
           << (result.faceAreas.sum() > 0.0 ? area / result.faceAreas.sum()
                                            : 0.0)
           << "}";
    if (bin + 2 != histogramEdges.size()) {
      stream << ',';
    }
    stream << '\n';
  }
  stream << "    ],\n";

  stream << "    \"smoothness\": {\n";
  stream << "      \"candidate_angle_degrees\": ";
  write_stats(result.firstSmoothness.angleDegrees, 6);
  stream << ",\n      \"candidate_weighted_chordal_energy\": "
         << result.firstSmoothness.weightedChordalEnergy << ",\n";
  stream << "      \"reference_angle_degrees\": ";
  write_stats(result.secondSmoothness.angleDegrees, 6);
  stream << ",\n      \"reference_weighted_chordal_energy\": "
         << result.secondSmoothness.weightedChordalEnergy << ",\n"
         << "      \"weighted_chordal_energy_delta\": "
         << result.firstSmoothness.weightedChordalEnergy -
                result.secondSmoothness.weightedChordalEnergy
         << "\n    },\n";

  const auto &topology = result.topology;
  stream << "    \"topology\": {\n"
         << "      \"available\": "
         << (topology.available ? "true" : "false");
  if (!topology.available) {
    stream << ",\n      \"error\": ";
    compare_detail::write_json_string(stream, topology.error);
    stream << "\n    },\n";
  } else {
    stream << ",\n"
           << "      \"candidate_singularity_count\": "
           << topology.first.singularVertices.size() << ",\n"
           << "      \"candidate_positive_count\": "
           << topology.first.positiveCount << ",\n"
           << "      \"candidate_negative_count\": "
           << topology.first.negativeCount << ",\n"
           << "      \"candidate_total_absolute_index\": "
           << topology.first.totalAbsoluteIndex << ",\n"
           << "      \"reference_singularity_count\": "
           << topology.second.singularVertices.size() << ",\n"
           << "      \"reference_positive_count\": "
           << topology.second.positiveCount << ",\n"
           << "      \"reference_negative_count\": "
           << topology.second.negativeCount << ",\n"
           << "      \"reference_total_absolute_index\": "
           << topology.second.totalAbsoluteIndex << ",\n"
           << "      \"matching_vertex_and_index_count\": "
           << topology.matchingSingularityCount << ",\n"
           << "      \"candidate_only_count\": " << topology.firstOnlyCount
           << ",\n"
           << "      \"reference_only_count\": " << topology.secondOnlyCount
           << ",\n"
           << "      \"different_index_count\": "
           << topology.differingIndexCount << ",\n"
           << "      \"mismatched_vertex_count\": "
           << topology.mismatchedVertexCount << ",\n"
           << "      \"mismatched_vertex_area_fraction\": "
           << topology.mismatchedVertexAreaFraction << ",\n"
           << "      \"l1_index_difference\": "
           << topology.l1IndexDifference << ",\n"
           << "      \"candidate_without_same_index_reference\": "
           << topology.firstWithoutSameIndexReference << ",\n"
           << "      \"reference_without_same_index_candidate\": "
           << topology.secondWithoutSameIndexReference << ",\n";
    stream << "      \"candidate_to_reference_distance_edge_lengths\": ";
    write_stats(topology.firstToSecondDistanceEdgeLengths, 6);
    stream << ",\n      \"reference_to_candidate_distance_edge_lengths\": ";
    write_stats(topology.secondToFirstDistanceEdgeLengths, 6);
    stream << "\n    },\n";
  }

  if (result.hasShapeOperatorAlignment) {
    stream << "    \"shape_operator_alignment\": {\n";
    stream << "      \"candidate_valid_face_count\": "
           << result.firstShapeOperatorStats.validFaceCount << ",\n";
    stream << "      \"candidate_valid_area_fraction\": "
           << result.firstShapeOperatorStats.validAreaFraction << ",\n";
    stream << "      \"candidate_weighted_mean_energy\": "
           << result.firstShapeOperatorStats.weightedMeanEnergy << ",\n";
    stream << "      \"candidate_angle_degrees\": ";
    write_stats(result.firstShapeOperatorStats.angleDegrees, 6);
    stream << ",\n      \"reference_valid_face_count\": "
           << result.secondShapeOperatorStats.validFaceCount << ",\n";
    stream << "      \"reference_valid_area_fraction\": "
           << result.secondShapeOperatorStats.validAreaFraction << ",\n";
    stream << "      \"reference_weighted_mean_energy\": "
           << result.secondShapeOperatorStats.weightedMeanEnergy << ",\n";
    stream << "      \"reference_angle_degrees\": ";
    write_stats(result.secondShapeOperatorStats.angleDegrees, 6);
    stream << "\n    },\n";
  }

  stream << "    \"high_error\": {\n"
         << "      \"threshold_degrees\": "
         << result.highErrorComponents.thresholdDegrees << ",\n"
         << "      \"face_count\": " << result.highErrorComponents.faceCount
         << ",\n"
         << "      \"area_fraction\": "
         << result.highErrorComponents.areaFraction << ",\n"
         << "      \"component_count\": "
         << result.highErrorComponents.componentCount << ",\n"
         << "      \"components\": [\n";
  for (std::size_t i = 0; i < result.highErrorComponents.components.size();
       ++i) {
    const auto &component = result.highErrorComponents.components[i];
    stream << "        {\"id\": " << component.id
           << ", \"first_face\": " << component.firstFace
           << ", \"face_count\": " << component.faceCount
           << ", \"area_fraction\": " << component.areaFraction
           << ", \"area_weighted_mean_degrees\": "
           << component.areaWeightedMeanDegrees
           << ", \"maximum_degrees\": " << component.maximumDegrees
           << ", \"centroid\": [" << component.areaWeightedCentroid(0)
           << ", " << component.areaWeightedCentroid(1) << ", "
           << component.areaWeightedCentroid(2) << "]}";
    if (i + 1 != result.highErrorComponents.components.size()) {
      stream << ',';
    }
    stream << '\n';
  }
  stream << "      ]\n    }\n";
  stream << "  },\n";

  stream << "  \"artifacts\": {\n";
  write_string_field("faces_csv", metadata.faceCsvPath, 4);
  write_string_field("heatmap_ply", metadata.heatmapPath, 4, false);
  stream << "  }\n}\n";
}

} // namespace directional::fields

namespace directional::fields {

CrossFieldComparisonReportPaths write_cross_field_comparison_report(
    const std::filesystem::path &requestedPath, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const CrossFieldComparisonResult &result,
    const CrossFieldComparisonReportMetadata &metadata,
    const double maximumDegrees) {
  CrossFieldComparisonReportPaths paths;
  paths.json = requestedPath;
  if (paths.json.extension() != ".json") {
    paths.json = std::filesystem::path(paths.json.string() + ".fieldcmp.json");
  }
  std::filesystem::path artifactBase = paths.json;
  artifactBase.replace_extension();
  paths.facesCsv =
      std::filesystem::path(artifactBase.string() + ".faces.csv");
  paths.heatmapPly =
      std::filesystem::path(artifactBase.string() + ".heatmap.ply");

  write_cross_field_comparison_csv(paths.facesCsv, result);
  write_cross_field_comparison_ply(paths.heatmapPly, V, F, result,
                                   maximumDegrees);

  CrossFieldComparisonReportMetadata reportMetadata = metadata;
  reportMetadata.vertexCount = V.rows();
  reportMetadata.faceCsvPath = paths.facesCsv.filename().string();
  reportMetadata.heatmapPath = paths.heatmapPly.filename().string();
  write_cross_field_comparison_json(paths.json, result, reportMetadata);
  return paths;
}

} // namespace directional::fields

namespace directional::fields {

std::string summarize_cross_field_comparison(
    const CrossFieldComparisonResult &result) {
  std::ostringstream stream;
  stream << std::setprecision(6);
  const auto &s = result.faceDeviationStats;
  stream << "Field difference: median " << s.median << " deg, mean "
         << s.mean << " deg, area-weighted mean " << s.weightedMean
         << " deg, area-weighted RMS " << s.weightedRms << " deg, p95 "
         << s.p95 << " deg, p99 " << s.p99 << " deg.\n";
  stream << "Primary q4 chordal objective: "
         << result.q4SquaredChordalErrorStats.weightedMean << ".\n";
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
  if (result.topology.available) {
    stream << "Singularities: first "
           << result.topology.first.singularVertices.size() << ", second "
           << result.topology.second.singularVertices.size() << "; "
           << result.topology.mismatchedVertexCount
           << " vertex/index mismatches.\n";
  } else {
    stream << "Singularity diagnostics unavailable: " << result.topology.error
           << ".\n";
  }
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
