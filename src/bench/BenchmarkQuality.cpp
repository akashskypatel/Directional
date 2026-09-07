#include "BenchmarkQuality.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <limits>
#include <numeric>
#include <set>
#include <sstream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#ifdef _WIN32
#define NOMINMAX
// clang-format off: Psapi requires the Windows base declarations first.
#include <Windows.h>
#include <Psapi.h>
// clang-format on
#elif defined(__linux__)
#include <unistd.h>
#endif

#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/validation/SourceAuthoritativeMeshValidator.h>

namespace directional::bench {
namespace {

using Edge = std::pair<int, int>;
using EdgeIncidence = std::map<Edge, std::vector<int>>;

constexpr double pi = 3.141592653589793238462643383279502884;

Edge canonical_edge(const int first, const int second) {
  return first <= second ? Edge{first, second} : Edge{second, first};
}

double percentile(std::vector<double> values, const double fraction) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const double index =
      static_cast<double>(values.size() - 1U) * std::clamp(fraction, 0.0, 1.0);
  const auto lower = static_cast<std::size_t>(std::floor(index));
  const auto upper = static_cast<std::size_t>(std::ceil(index));
  if (lower == upper) {
    return values[lower];
  }
  return values[lower] +
         (values[upper] - values[lower]) * (index - static_cast<double>(lower));
}

double mesh_scale(const Eigen::MatrixXd &vertices) {
  if (vertices.rows() == 0 || vertices.cols() != 3) {
    return 1.0;
  }
  return std::max(
      1.0e-12,
      (vertices.colwise().maxCoeff() - vertices.colwise().minCoeff()).norm());
}

std::vector<int> face_vertices(const Eigen::MatrixXi &faces,
                               const Eigen::VectorXi &degrees, const int face) {
  const int degree =
      face >= 0 && face < degrees.size()
          ? std::clamp(degrees(face), 0, static_cast<int>(faces.cols()))
          : static_cast<int>(faces.cols());
  std::vector<int> vertices;
  vertices.reserve(static_cast<std::size_t>(degree));
  for (int corner = 0; corner < degree; ++corner) {
    if (faces(face, corner) >= 0) {
      vertices.push_back(faces(face, corner));
    }
  }
  return vertices;
}

Eigen::VectorXi inferred_degrees(const Eigen::MatrixXi &faces) {
  Eigen::VectorXi degrees(faces.rows());
  for (int face = 0; face < faces.rows(); ++face) {
    int degree = 0;
    for (int corner = 0; corner < faces.cols(); ++corner) {
      if (faces(face, corner) >= 0) {
        ++degree;
      }
    }
    degrees(face) = degree;
  }
  return degrees;
}

EdgeIncidence build_edge_incidence(const Eigen::MatrixXi &faces,
                                   const Eigen::VectorXi &degrees) {
  EdgeIncidence incidence;
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, degrees, face);
    for (std::size_t corner = 0; corner < polygon.size(); ++corner) {
      const int first = polygon[corner];
      const int second = polygon[(corner + 1U) % polygon.size()];
      if (first >= 0 && second >= 0 && first != second) {
        incidence[canonical_edge(first, second)].push_back(face);
      }
    }
  }
  return incidence;
}

std::vector<Edge> boundary_edges(const EdgeIncidence &incidence) {
  std::vector<Edge> boundary;
  for (const auto &[edge, faces] : incidence) {
    if (faces.size() == 1U) {
      boundary.push_back(edge);
    }
  }
  return boundary;
}

int connected_face_components(const Eigen::MatrixXi &faces,
                              const EdgeIncidence &incidence) {
  if (faces.rows() == 0) {
    return 0;
  }
  std::vector<std::vector<int>> adjacency(
      static_cast<std::size_t>(faces.rows()));
  for (const auto &[edge, incidentFaces] : incidence) {
    (void)edge;
    for (const int first : incidentFaces) {
      for (const int second : incidentFaces) {
        if (first != second) {
          adjacency[static_cast<std::size_t>(first)].push_back(second);
        }
      }
    }
  }
  std::vector<unsigned char> visited(static_cast<std::size_t>(faces.rows()), 0);
  int count = 0;
  for (int seed = 0; seed < faces.rows(); ++seed) {
    if (visited[static_cast<std::size_t>(seed)] != 0) {
      continue;
    }
    ++count;
    std::vector<int> stack{seed};
    visited[static_cast<std::size_t>(seed)] = 1;
    while (!stack.empty()) {
      const int face = stack.back();
      stack.pop_back();
      for (const int next : adjacency[static_cast<std::size_t>(face)]) {
        if (visited[static_cast<std::size_t>(next)] == 0) {
          visited[static_cast<std::size_t>(next)] = 1;
          stack.push_back(next);
        }
      }
    }
  }
  return count;
}

struct TopologySummary {
  int usedVertices = 0;
  int edges = 0;
  int faces = 0;
  int connectedComponents = 0;
  int eulerCharacteristic = 0;
  int boundaryLoopCount = 0;
  bool boundaryClosed = true;
};

TopologySummary summarize_topology(const Eigen::MatrixXi &faces,
                                   const Eigen::VectorXi &degrees) {
  TopologySummary summary;
  const EdgeIncidence incidence = build_edge_incidence(faces, degrees);
  std::set<int> usedVertices;
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, degrees, face);
    if (polygon.size() < 3U) {
      continue;
    }
    ++summary.faces;
    usedVertices.insert(polygon.begin(), polygon.end());
  }
  summary.usedVertices = static_cast<int>(usedVertices.size());
  summary.edges = static_cast<int>(incidence.size());
  summary.connectedComponents = connected_face_components(faces, incidence);
  summary.eulerCharacteristic =
      summary.usedVertices - summary.edges + summary.faces;

  std::map<int, std::vector<int>> boundaryAdjacency;
  for (const Edge edge : boundary_edges(incidence)) {
    boundaryAdjacency[edge.first].push_back(edge.second);
    boundaryAdjacency[edge.second].push_back(edge.first);
  }
  for (const auto &[vertex, neighbors] : boundaryAdjacency) {
    (void)vertex;
    if (neighbors.size() != 2U) {
      summary.boundaryClosed = false;
    }
  }
  std::set<int> visited;
  for (const auto &[seed, neighbors] : boundaryAdjacency) {
    (void)neighbors;
    if (visited.count(seed) != 0) {
      continue;
    }
    ++summary.boundaryLoopCount;
    std::vector<int> stack{seed};
    visited.insert(seed);
    while (!stack.empty()) {
      const int vertex = stack.back();
      stack.pop_back();
      for (const int next : boundaryAdjacency[vertex]) {
        if (visited.insert(next).second) {
          stack.push_back(next);
        }
      }
    }
  }
  return summary;
}

double point_segment_squared_distance(const Eigen::Vector3d &point,
                                      const Eigen::Vector3d &first,
                                      const Eigen::Vector3d &second) {
  const Eigen::Vector3d direction = second - first;
  const double denominator = direction.squaredNorm();
  const double parameter =
      denominator > 0.0
          ? std::clamp((point - first).dot(direction) / denominator, 0.0, 1.0)
          : 0.0;
  return (point - (first + parameter * direction)).squaredNorm();
}

double nearest_edge_squared_distance(const Eigen::Vector3d &point,
                                     const Eigen::MatrixXd &vertices,
                                     const std::vector<Edge> &edges) {
  double best = std::numeric_limits<double>::infinity();
  for (const Edge edge : edges) {
    if (edge.first < 0 || edge.second < 0 || edge.first >= vertices.rows() ||
        edge.second >= vertices.rows()) {
      continue;
    }
    best = std::min(
        best, point_segment_squared_distance(point, vertices.row(edge.first),
                                             vertices.row(edge.second)));
  }
  return best;
}

bool boundaries_match(const BenchmarkMesh &source,
                      const pipeline::RemeshResult &output,
                      const double tolerance) {
  const Eigen::VectorXi sourceDegrees =
      Eigen::VectorXi::Constant(source.faces.rows(), 3);
  const std::vector<Edge> sourceBoundary =
      boundary_edges(build_edge_incidence(source.faces, sourceDegrees));
  const std::vector<Edge> outputBoundary =
      boundary_edges(build_edge_incidence(output.product().faces, output.product().degrees));
  if (sourceBoundary.empty() != outputBoundary.empty()) {
    return false;
  }
  if (sourceBoundary.empty()) {
    return true;
  }
  const double toleranceSquared = tolerance * tolerance;
  for (const Edge edge : outputBoundary) {
    for (const int vertex : {edge.first, edge.second}) {
      if (nearest_edge_squared_distance(output.product().vertices.row(vertex),
                                        source.vertices,
                                        sourceBoundary) > toleranceSquared) {
        return false;
      }
    }
  }
  for (const Edge edge : sourceBoundary) {
    for (const int vertex : {edge.first, edge.second}) {
      if (nearest_edge_squared_distance(source.vertices.row(vertex),
                                        output.product().vertices,
                                        outputBoundary) > toleranceSquared) {
        return false;
      }
    }
  }
  return true;
}

int count_duplicate_faces(const Eigen::MatrixXi &faces,
                          const Eigen::VectorXi &degrees) {
  std::set<std::vector<int>> unique;
  int duplicates = 0;
  for (int face = 0; face < faces.rows(); ++face) {
    std::vector<int> polygon = face_vertices(faces, degrees, face);
    std::sort(polygon.begin(), polygon.end());
    if (!polygon.empty() && !unique.insert(std::move(polygon)).second) {
      ++duplicates;
    }
  }
  return duplicates;
}

int count_t_junctions(const Eigen::MatrixXd &vertices,
                      const EdgeIncidence &incidence, const double tolerance) {
  if (vertices.rows() == 0) {
    return 0;
  }
  std::vector<int> sortedByX(static_cast<std::size_t>(vertices.rows()));
  std::iota(sortedByX.begin(), sortedByX.end(), 0);
  std::sort(sortedByX.begin(), sortedByX.end(),
            [&](const int first, const int second) {
              return vertices(first, 0) < vertices(second, 0);
            });

  int count = 0;
  for (const auto &[edge, incidentFaces] : incidence) {
    (void)incidentFaces;
    const Eigen::Vector3d first = vertices.row(edge.first);
    const Eigen::Vector3d second = vertices.row(edge.second);
    const Eigen::Vector3d direction = second - first;
    const double lengthSquared = direction.squaredNorm();
    if (lengthSquared <= tolerance * tolerance) {
      continue;
    }
    const double minimumX = std::min(first.x(), second.x()) - tolerance;
    const double maximumX = std::max(first.x(), second.x()) + tolerance;
    const auto begin =
        std::lower_bound(sortedByX.begin(), sortedByX.end(), minimumX,
                         [&](const int vertex, const double value) {
                           return vertices(vertex, 0) < value;
                         });
    for (auto candidate = begin; candidate != sortedByX.end(); ++candidate) {
      const int vertex = *candidate;
      if (vertices(vertex, 0) > maximumX) {
        break;
      }
      if (vertex == edge.first || vertex == edge.second) {
        continue;
      }
      const Eigen::Vector3d point = vertices.row(vertex);
      const double parameter = (point - first).dot(direction) / lengthSquared;
      if (parameter <= tolerance || parameter >= 1.0 - tolerance) {
        continue;
      }
      if ((point - (first + parameter * direction)).norm() <= tolerance) {
        ++count;
      }
    }
  }
  return count;
}

int count_self_intersections(const Eigen::MatrixXd &vertices,
                             const Eigen::MatrixXi &faces,
                             const double tolerance) {
  namespace detail = validation::source_authoritative_detail;
  int selfIntersectingPolygons = 0;
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = detail::face_vertices(faces, face);
    if (polygon.size() < 4U) {
      continue;
    }
    Eigen::MatrixXd localVertices(static_cast<int>(polygon.size()), 3);
    Eigen::MatrixXi localFace(1, static_cast<int>(polygon.size()));
    for (int corner = 0; corner < static_cast<int>(polygon.size()); ++corner) {
      localVertices.row(corner) =
          vertices.row(polygon[static_cast<std::size_t>(corner)]);
      localFace(0, corner) = corner;
    }
    validation::MeshValidatorOptions options;
    options.geometricTolerance = tolerance;
    const validation::MeshValidationResult validation =
        validation::MeshValidator::validate_surface_mesh(localVertices,
                                                         localFace, options);
    if (std::any_of(validation.issues.begin(), validation.issues.end(),
                    [](const validation::MeshValidationIssue &issue) {
                      return issue.code ==
                             validation::MeshValidationFailureCode::
                                 SelfIntersectingFace;
                    })) {
      ++selfIntersectingPolygons;
    }
  }
  const std::vector<detail::TrianglePrimitive> triangles =
      detail::triangulate_faces(vertices, faces, tolerance);
  std::vector<detail::Aabb> boxes;
  boxes.reserve(triangles.size());
  for (const detail::TrianglePrimitive &triangle : triangles) {
    boxes.push_back(triangle.bounds);
  }
  const detail::AabbTree tree(boxes);
  std::set<std::pair<int, int>> intersectingFacePairs;
  for (int first = 0; first < static_cast<int>(triangles.size()); ++first) {
    tree.query(boxes[static_cast<std::size_t>(first)], [&](const int second) {
      if (second <= first ||
          triangles[static_cast<std::size_t>(first)].parentFace ==
              triangles[static_cast<std::size_t>(second)].parentFace) {
        return;
      }
      if (detail::triangles_intersect(
              vertices, triangles[static_cast<std::size_t>(first)],
              triangles[static_cast<std::size_t>(second)], tolerance)) {
        intersectingFacePairs.insert(std::minmax(
            triangles[static_cast<std::size_t>(first)].parentFace,
            triangles[static_cast<std::size_t>(second)].parentFace));
      }
    });
  }
  return selfIntersectingPolygons +
         static_cast<int>(intersectingFacePairs.size());
}

Eigen::MatrixXi triangulate_output(const pipeline::RemeshResult &output) {
  std::vector<std::array<int, 3>> triangles;
  for (int face = 0; face < output.product().faces.rows(); ++face) {
    const std::vector<int> polygon =
        face_vertices(output.product().faces, output.product().degrees, face);
    for (std::size_t index = 1; index + 1U < polygon.size(); ++index) {
      triangles.push_back({polygon[0], polygon[index], polygon[index + 1U]});
    }
  }
  Eigen::MatrixXi result(static_cast<int>(triangles.size()), 3);
  for (int row = 0; row < result.rows(); ++row) {
    for (int corner = 0; corner < 3; ++corner) {
      result(row, corner) = triangles[static_cast<std::size_t>(row)]
                                     [static_cast<std::size_t>(corner)];
    }
  }
  return result;
}

std::vector<Eigen::Vector3d> surface_samples(const Eigen::MatrixXd &vertices,
                                             const Eigen::MatrixXi &faces,
                                             const Eigen::VectorXi &degrees) {
  std::vector<Eigen::Vector3d> samples;
  samples.reserve(static_cast<std::size_t>(vertices.rows() + faces.rows()));
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    samples.push_back(vertices.row(vertex));
  }
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, degrees, face);
    if (polygon.empty()) {
      continue;
    }
    Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
    for (const int vertex : polygon) {
      centroid += vertices.row(vertex).transpose();
    }
    samples.push_back(centroid / static_cast<double>(polygon.size()));
  }
  return samples;
}

std::vector<double>
directed_surface_errors(const std::vector<Eigen::Vector3d> &samples,
                        const geometry::SurfaceProjectionBvh &target,
                        const double normalization) {
  std::vector<double> errors;
  errors.reserve(samples.size());
  for (const Eigen::Vector3d &sample : samples) {
    const geometry::SurfacePoint projected = target.project(sample);
    if (projected.valid() && std::isfinite(projected.squaredDistance)) {
      errors.push_back(std::sqrt(std::max(0.0, projected.squaredDistance)) /
                       normalization);
    }
  }
  return errors;
}

double acute_angle_degrees(const Eigen::Vector3d &first,
                           const Eigen::Vector3d &second) {
  if (first.squaredNorm() <= 0.0 || second.squaredNorm() <= 0.0) {
    return 90.0;
  }
  const double cosine = std::clamp(
      std::abs(first.normalized().dot(second.normalized())), 0.0, 1.0);
  return std::acos(cosine) * 180.0 / pi;
}

double field_alignment_error(const Eigen::Vector3d &direction,
                             const BenchmarkField &field,
                             const int sourceFace) {
  if (!field.available || field.raw.cols() < 6 || sourceFace < 0 ||
      sourceFace >= field.raw.rows()) {
    return 0.0;
  }
  const Eigen::Vector3d primary = field.raw.row(sourceFace).segment<3>(0);
  const Eigen::Vector3d secondary = field.raw.row(sourceFace).segment<3>(3);
  return std::min(acute_angle_degrees(direction, primary),
                  acute_angle_degrees(direction, secondary));
}

std::vector<Edge> output_edges(const pipeline::RemeshResult &output) {
  std::vector<Edge> edges;
  if (!output.is_produced()) {
    return edges;
  }
  const EdgeIncidence incidence =
      build_edge_incidence(output.product().faces, output.product().degrees);
  edges.reserve(incidence.size());
  for (const auto &[edge, faces] : incidence) {
    (void)faces;
    edges.push_back(edge);
  }
  return edges;
}

std::pair<double, double> feature_metrics(const BenchmarkMesh &source,
                                          const pipeline::RemeshResult &output,
                                          const double targetLength) {
  const geometry::AdaptiveFeatureMap featureMap =
      geometry::AdaptiveFeatureMapBuilder::build(source.vertices, source.faces);
  std::vector<Edge> hardEdges;
  for (const geometry::AdaptiveFeatureEdge &edge : featureMap.edges) {
    if (edge.edgeClass == geometry::AdaptiveFeatureClass::Hard) {
      hardEdges.push_back(edge.vertices);
    }
  }
  if (hardEdges.empty()) {
    return {1.0, 0.0};
  }
  const std::vector<Edge> candidateEdges = output_edges(output);
  const double distanceTolerance =
      std::max(1.0e-8 * mesh_scale(source.vertices), 0.25 * targetLength);
  int accepted = 0;
  int total = 0;
  std::vector<double> alignmentErrors;
  for (const Edge sourceEdge : hardEdges) {
    const Eigen::Vector3d sourceFirst = source.vertices.row(sourceEdge.first);
    const Eigen::Vector3d sourceSecond = source.vertices.row(sourceEdge.second);
    const Eigen::Vector3d sourceDirection = sourceSecond - sourceFirst;
    for (int sampleIndex = 0; sampleIndex < 5; ++sampleIndex) {
      const double parameter = static_cast<double>(sampleIndex) / 4.0;
      const Eigen::Vector3d sample =
          (1.0 - parameter) * sourceFirst + parameter * sourceSecond;
      ++total;
      double bestDistance = std::numeric_limits<double>::infinity();
      double bestAngle = 90.0;
      for (const Edge outputEdge : candidateEdges) {
        const Eigen::Vector3d outputFirst =
            output.product().vertices.row(outputEdge.first);
        const Eigen::Vector3d outputSecond =
            output.product().vertices.row(outputEdge.second);
        const double distance = std::sqrt(
            point_segment_squared_distance(sample, outputFirst, outputSecond));
        const double angle =
            acute_angle_degrees(sourceDirection, outputSecond - outputFirst);
        const auto candidate = std::pair<double, double>{distance, angle};
        if (candidate < std::pair<double, double>{bestDistance, bestAngle}) {
          bestDistance = distance;
          bestAngle = angle;
        }
      }
      if (bestDistance <= distanceTolerance && bestAngle <= 15.0) {
        ++accepted;
        alignmentErrors.push_back(bestAngle);
      }
    }
  }
  return {total > 0 ? static_cast<double>(accepted) / total : 1.0,
          percentile(std::move(alignmentErrors), 0.95)};
}

void compute_valence(const pipeline::RemeshResult &output,
                     BenchmarkQuality &quality) {
  const EdgeIncidence incidence =
      build_edge_incidence(output.product().faces, output.product().degrees);
  std::vector<std::set<int>> neighbors(
      static_cast<std::size_t>(output.product().vertices.rows()));
  std::set<int> boundaryVertices;
  std::map<int, std::vector<int>> boundaryNeighbors;
  for (const auto &[edge, faces] : incidence) {
    neighbors[static_cast<std::size_t>(edge.first)].insert(edge.second);
    neighbors[static_cast<std::size_t>(edge.second)].insert(edge.first);
    if (faces.size() == 1U) {
      boundaryVertices.insert(edge.first);
      boundaryVertices.insert(edge.second);
      boundaryNeighbors[edge.first].push_back(edge.second);
      boundaryNeighbors[edge.second].push_back(edge.first);
    }
  }
  for (int vertex = 0; vertex < output.product().vertices.rows(); ++vertex) {
    const int valence =
        static_cast<int>(neighbors[static_cast<std::size_t>(vertex)].size());
    ++quality.valenceHistogram[valence];
    int target = boundaryVertices.count(vertex) != 0 ? 3 : 4;
    const auto boundary = boundaryNeighbors.find(vertex);
    if (boundary != boundaryNeighbors.end() && boundary->second.size() == 2U) {
      const Eigen::Vector3d first =
          output.product().vertices.row(boundary->second[0]).transpose() -
          output.product().vertices.row(vertex).transpose();
      const Eigen::Vector3d second =
          output.product().vertices.row(boundary->second[1]).transpose() -
          output.product().vertices.row(vertex).transpose();
      if (first.squaredNorm() > 0.0 && second.squaredNorm() > 0.0) {
        const double angle =
            std::acos(std::clamp(first.normalized().dot(second.normalized()),
                                 -1.0, 1.0)) *
            180.0 / pi;
        if (angle < 135.0) {
          target = 2;
        }
      }
    }
    if (valence != target) {
      ++quality.irregularVertexCount;
    }
  }
}

void write_obj(const std::filesystem::path &path,
               const pipeline::RemeshResult &output) {
  std::filesystem::create_directories(path.parent_path());
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to write benchmark mesh artifact: " +
                             path.string());
  }
  stream << std::setprecision(17);
  for (int vertex = 0; vertex < output.product().vertices.rows(); ++vertex) {
    stream << "v " << output.product().vertices(vertex, 0) << ' '
           << output.product().vertices(vertex, 1) << ' ' << output.product().vertices(vertex, 2)
           << '\n';
  }
  for (int face = 0; face < output.product().faces.rows(); ++face) {
    stream << 'f';
    for (const int vertex : face_vertices(output.product().faces, output.product().degrees, face)) {
      stream << ' ' << (vertex + 1);
    }
    stream << '\n';
  }
}

struct Bitmap {
  int width = 0;
  int height = 0;
  std::vector<unsigned char> rgb;

  Bitmap(const int requestedWidth, const int requestedHeight)
      : width(requestedWidth), height(requestedHeight),
        rgb(static_cast<std::size_t>(width * height * 3), 255) {}

  void pixel(const int x, const int y,
             const std::array<unsigned char, 3> color) {
    if (x < 0 || y < 0 || x >= width || y >= height) {
      return;
    }
    const std::size_t offset = static_cast<std::size_t>((y * width + x) * 3);
    rgb[offset] = color[0];
    rgb[offset + 1U] = color[1];
    rgb[offset + 2U] = color[2];
  }

  void line(int x0, int y0, const int x1, const int y1,
            const std::array<unsigned char, 3> color) {
    const int dx = std::abs(x1 - x0);
    const int sx = x0 < x1 ? 1 : -1;
    const int dy = -std::abs(y1 - y0);
    const int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;
    while (true) {
      pixel(x0, y0, color);
      if (x0 == x1 && y0 == y1) {
        break;
      }
      const int doubled = 2 * error;
      if (doubled >= dy) {
        error += dy;
        x0 += sx;
      }
      if (doubled <= dx) {
        error += dx;
        y0 += sy;
      }
    }
  }
};

void write_u16(std::ostream &stream, const std::uint16_t value) {
  stream.put(static_cast<char>(value & 0xffU));
  stream.put(static_cast<char>((value >> 8U) & 0xffU));
}

void write_u32(std::ostream &stream, const std::uint32_t value) {
  for (int shift = 0; shift < 32; shift += 8) {
    stream.put(static_cast<char>((value >> shift) & 0xffU));
  }
}

void write_bmp(const std::filesystem::path &path, const Bitmap &bitmap) {
  std::filesystem::create_directories(path.parent_path());
  std::ofstream stream(path, std::ios::binary);
  if (!stream) {
    throw std::runtime_error("Failed to write benchmark review image: " +
                             path.string());
  }
  const std::uint32_t rowBytes =
      static_cast<std::uint32_t>(((bitmap.width * 3 + 3) / 4) * 4);
  const std::uint32_t pixelBytes =
      rowBytes * static_cast<std::uint32_t>(bitmap.height);
  stream.put('B');
  stream.put('M');
  write_u32(stream, 54U + pixelBytes);
  write_u16(stream, 0);
  write_u16(stream, 0);
  write_u32(stream, 54);
  write_u32(stream, 40);
  write_u32(stream, static_cast<std::uint32_t>(bitmap.width));
  write_u32(stream, static_cast<std::uint32_t>(bitmap.height));
  write_u16(stream, 1);
  write_u16(stream, 24);
  write_u32(stream, 0);
  write_u32(stream, pixelBytes);
  write_u32(stream, 2835);
  write_u32(stream, 2835);
  write_u32(stream, 0);
  write_u32(stream, 0);
  const std::vector<unsigned char> padding(
      rowBytes - static_cast<std::uint32_t>(bitmap.width * 3), 0);
  for (int y = bitmap.height - 1; y >= 0; --y) {
    for (int x = 0; x < bitmap.width; ++x) {
      const std::size_t offset =
          static_cast<std::size_t>((y * bitmap.width + x) * 3);
      stream.put(static_cast<char>(bitmap.rgb[offset + 2U]));
      stream.put(static_cast<char>(bitmap.rgb[offset + 1U]));
      stream.put(static_cast<char>(bitmap.rgb[offset]));
    }
    stream.write(reinterpret_cast<const char *>(padding.data()),
                 static_cast<std::streamsize>(padding.size()));
  }
}

Eigen::Vector2d project_view(const Eigen::Vector3d &point, const int view) {
  if (view == 0) {
    return {point.x(), point.y()};
  }
  if (view == 1) {
    return {point.x(), point.z()};
  }
  constexpr double inverseSqrt2 = 0.7071067811865475244;
  return {(point.x() - point.y()) * inverseSqrt2,
          point.z() + 0.35 * (point.x() + point.y()) * inverseSqrt2};
}

std::pair<int, int> image_point(const Eigen::Vector3d &point, const int view,
                                const Eigen::Vector2d &minimum,
                                const Eigen::Vector2d &maximum,
                                const int viewportWidth, const int height) {
  const Eigen::Vector2d extent =
      (maximum - minimum).cwiseMax(Eigen::Vector2d::Constant(1.0e-12));
  const double scale =
      0.88 * std::min(static_cast<double>(viewportWidth) / extent.x(),
                      static_cast<double>(height) / extent.y());
  const Eigen::Vector2d center = 0.5 * (minimum + maximum);
  const Eigen::Vector2d projected = project_view(point, view) - center;
  return {view * viewportWidth + viewportWidth / 2 +
              static_cast<int>(std::lround(projected.x() * scale)),
          height / 2 - static_cast<int>(std::lround(projected.y() * scale))};
}

void render_edges(Bitmap &bitmap, const Eigen::MatrixXd &vertices,
                  const std::vector<Edge> &edges, const int view,
                  const Eigen::Vector2d &minimum,
                  const Eigen::Vector2d &maximum,
                  const std::array<unsigned char, 3> color) {
  const int viewportWidth = bitmap.width / 3;
  for (const Edge edge : edges) {
    const auto first = image_point(vertices.row(edge.first), view, minimum,
                                   maximum, viewportWidth, bitmap.height);
    const auto second = image_point(vertices.row(edge.second), view, minimum,
                                    maximum, viewportWidth, bitmap.height);
    bitmap.line(first.first, first.second, second.first, second.second, color);
  }
}

void write_review_image(const std::filesystem::path &path,
                        const BenchmarkMesh &source,
                        const pipeline::RemeshResult &output,
                        const bool markFailure = false) {
  Bitmap bitmap(1500, 500);
  const Eigen::VectorXi sourceDegrees =
      Eigen::VectorXi::Constant(source.faces.rows(), 3);
  std::vector<Edge> sourceEdges;
  for (const auto &[edge, faces] :
       build_edge_incidence(source.faces, sourceDegrees)) {
    (void)faces;
    sourceEdges.push_back(edge);
  }
  const bool hasOutput = output.is_produced();
  const std::vector<Edge> remeshEdges = output_edges(output);
  for (int view = 0; view < 3; ++view) {
    Eigen::Vector2d minimum =
        Eigen::Vector2d::Constant(std::numeric_limits<double>::infinity());
    Eigen::Vector2d maximum =
        Eigen::Vector2d::Constant(-std::numeric_limits<double>::infinity());
    const auto expand = [&](const Eigen::MatrixXd &vertices) {
      for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
        const Eigen::Vector2d projected =
            project_view(vertices.row(vertex), view);
        minimum = minimum.cwiseMin(projected);
        maximum = maximum.cwiseMax(projected);
      }
    };
    expand(source.vertices);
    if (hasOutput) {
      expand(output.product().vertices);
    }
    render_edges(bitmap, source.vertices, sourceEdges, view, minimum, maximum,
                 {205, 205, 205});
    if (hasOutput) {
      render_edges(bitmap, output.product().vertices, remeshEdges, view, minimum,
                   maximum, {25, 95, 175});
    }
    if (markFailure) {
      const int viewportWidth = bitmap.width / 3;
      const int left = view * viewportWidth + viewportWidth - 42;
      constexpr int top = 18;
      constexpr int size = 24;
      bitmap.line(left, top, left + size, top + size, {190, 35, 45});
      bitmap.line(left + size, top, left, top + size, {190, 35, 45});
    }
  }
  write_bmp(path, bitmap);
}

std::string escape_json(const std::string &value) {
  std::ostringstream escaped;
  for (const char character : value) {
    switch (character) {
    case '\\':
      escaped << "\\\\";
      break;
    case '"':
      escaped << "\\\"";
      break;
    case '\n':
      escaped << "\\n";
      break;
    case '\r':
      escaped << "\\r";
      break;
    case '\t':
      escaped << "\\t";
      break;
    default:
      escaped << character;
      break;
    }
  }
  return escaped.str();
}

void mix_hash(std::uint64_t &hash, const std::uint64_t value) {
  hash ^= value;
  hash *= 1099511628211ULL;
}

} // namespace

std::uint64_t current_process_working_set_bytes() {
#ifdef _WIN32
  PROCESS_MEMORY_COUNTERS_EX counters{};
  counters.cb = sizeof(counters);
  if (GetProcessMemoryInfo(
          GetCurrentProcess(),
          reinterpret_cast<PROCESS_MEMORY_COUNTERS *>(&counters),
          static_cast<DWORD>(sizeof(counters))) != 0) {
    return static_cast<std::uint64_t>(counters.WorkingSetSize);
  }
#elif defined(__linux__)
  std::ifstream statm("/proc/self/statm");
  std::uint64_t pages = 0;
  std::uint64_t resident = 0;
  if (statm >> pages >> resident) {
    const long pageSize = sysconf(_SC_PAGESIZE);
    if (pageSize > 0) {
      return resident * static_cast<std::uint64_t>(pageSize);
    }
  }
#endif
  return 0;
}

PeakWorkingSetSampler::PeakWorkingSetSampler()
    : peak_(current_process_working_set_bytes()), worker_([this]() {
        while (!stop_.load(std::memory_order_relaxed)) {
          const std::uint64_t current = current_process_working_set_bytes();
          std::uint64_t observed = peak_.load(std::memory_order_relaxed);
          while (current > observed &&
                 !peak_.compare_exchange_weak(observed, current,
                                              std::memory_order_relaxed)) {
          }
          std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
      }) {}

PeakWorkingSetSampler::~PeakWorkingSetSampler() { (void)finish(); }

std::uint64_t PeakWorkingSetSampler::finish() {
  if (!finished_) {
    const std::uint64_t current = current_process_working_set_bytes();
    std::uint64_t observed = peak_.load(std::memory_order_relaxed);
    while (current > observed &&
           !peak_.compare_exchange_weak(observed, current,
                                        std::memory_order_relaxed)) {
    }
    stop_.store(true, std::memory_order_relaxed);
    if (worker_.joinable()) {
      worker_.join();
    }
    finished_ = true;
  }
  return peak_.load(std::memory_order_relaxed);
}

std::uint64_t
benchmark_output_structural_hash(const pipeline::RemeshResult &result) {
  std::uint64_t hash = 1469598103934665603ULL;
  const pipeline::RemeshProduct emptyProduct;
  const pipeline::RemeshProduct &product =
      result.is_produced() ? result.product() : emptyProduct;
  mix_hash(hash, static_cast<std::uint64_t>(product.vertices.rows()));
  mix_hash(hash, static_cast<std::uint64_t>(product.vertices.cols()));
  mix_hash(hash, static_cast<std::uint64_t>(product.faces.rows()));
  mix_hash(hash, static_cast<std::uint64_t>(product.faces.cols()));
  for (int row = 0; row < product.vertices.rows(); ++row) {
    for (int column = 0; column < product.vertices.cols(); ++column) {
      std::uint64_t bits = 0;
      const double value = product.vertices(row, column);
      std::memcpy(&bits, &value, sizeof(bits));
      mix_hash(hash, bits);
    }
  }
  for (int degree = 0; degree < product.degrees.size(); ++degree) {
    mix_hash(hash, static_cast<std::uint64_t>(
                       static_cast<std::uint32_t>(product.degrees(degree))));
  }
  for (int row = 0; row < product.faces.rows(); ++row) {
    for (int column = 0; column < product.faces.cols(); ++column) {
      mix_hash(hash, static_cast<std::uint64_t>(static_cast<std::uint32_t>(
                         product.faces(row, column))));
    }
  }
  return hash;
}

std::uint64_t
benchmark_output_semantic_hash(const pipeline::RemeshResult &result) {
  if (!result.is_produced()) return 0U;
  using Record = std::vector<std::int64_t>;
  if (result.product().vertices.cols() != 3 || result.product().vertices.rows() <= 0 ||
      result.product().faces.rows() <= 0 ||
      result.product().degrees.size() != result.product().faces.rows() ||
      result.product().outputVertexLineage.size() !=
          static_cast<std::size_t>(result.product().vertices.rows()) ||
      result.product().outputQuadLineage.size() !=
          static_cast<std::size_t>(result.product().faces.rows())) {
    return 0U;
  }
  const auto bits = [](const double value) {
    std::uint64_t unsignedBits = 0U;
    std::memcpy(&unsignedBits, &value, sizeof(unsignedBits));
    std::int64_t signedBits = 0;
    std::memcpy(&signedBits, &unsignedBits, sizeof(signedBits));
    return signedBits;
  };
  const auto append_record = [](Record &target, const Record &record) {
    target.push_back(static_cast<std::int64_t>(record.size()));
    target.insert(target.end(), record.begin(), record.end());
  };
  const auto append_ints = [](Record &target, std::vector<int> values) {
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    target.push_back(static_cast<std::int64_t>(values.size()));
    for (const int value : values) target.push_back(value);
  };
  const auto append_semantic_ids = [](Record &target, auto values) {
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    target.push_back(static_cast<std::int64_t>(values.size()));
    for (const auto value : values) {
      target.push_back(static_cast<std::int64_t>(value.index()));
    }
  };

  std::vector<const geometry::PureQuadVertexLineage *> lineageByVertex(
      static_cast<std::size_t>(result.product().vertices.rows()), nullptr);
  for (const auto &lineage : result.product().outputVertexLineage) {
    if (lineage.outputVertex < 0 ||
        lineage.outputVertex >= result.product().vertices.rows() ||
        lineageByVertex[static_cast<std::size_t>(lineage.outputVertex)] !=
            nullptr ||
        !lineage.valid()) {
      return 0U;
    }
    lineageByVertex[static_cast<std::size_t>(lineage.outputVertex)] = &lineage;
  }
  std::vector<const geometry::PureQuadFaceLineage *> lineageByFace(
      static_cast<std::size_t>(result.product().faces.rows()), nullptr);
  for (const auto &lineage : result.product().outputQuadLineage) {
    if (lineage.outputQuad < 0 || lineage.outputQuad >= result.product().faces.rows() ||
        lineageByFace[static_cast<std::size_t>(lineage.outputQuad)] != nullptr ||
        !lineage.valid()) {
      return 0U;
    }
    lineageByFace[static_cast<std::size_t>(lineage.outputQuad)] = &lineage;
  }

  std::vector<Record> vertexRecords(
      static_cast<std::size_t>(result.product().vertices.rows()));
  for (int vertex = 0; vertex < result.product().vertices.rows(); ++vertex) {
    const auto &lineage =
        *lineageByVertex[static_cast<std::size_t>(vertex)];
    Record &record = vertexRecords[static_cast<std::size_t>(vertex)];
    record.insert(record.end(),
                  {bits(result.product().vertices(vertex, 0)),
                   bits(result.product().vertices(vertex, 1)),
                   bits(result.product().vertices(vertex, 2)),
                   static_cast<int>(lineage.kind),
                   lineage.sourceSupport.has_value() ? 1 : 0});
    if (lineage.sourceSupport.has_value()) {
      const auto &support = lineage.sourceSupport.value();
      record.push_back(static_cast<std::int64_t>(
          authority::support_kind(support)));
      if (const auto *vertexSupport =
              std::get_if<authority::SourceVertexSupport>(&support)) {
        record.push_back(static_cast<std::int64_t>(
            vertexSupport->vertex.index()));
      } else if (const auto *edgeSupport =
                     std::get_if<authority::SourceEdgeSupport>(&support)) {
        record.push_back(static_cast<std::int64_t>(
            edgeSupport->edge.first().index()));
        record.push_back(static_cast<std::int64_t>(
            edgeSupport->edge.second().index()));
      } else if (const auto *faceSupport =
                     std::get_if<authority::SourceFaceInteriorSupport>(
                         &support)) {
        record.push_back(static_cast<std::int64_t>(
            faceSupport->face.vertices()[0].index()));
        record.push_back(static_cast<std::int64_t>(
            faceSupport->face.vertices()[1].index()));
        record.push_back(static_cast<std::int64_t>(
            faceSupport->face.vertices()[2].index()));
      }
    }
    append_semantic_ids(record, lineage.sourceTopologyRegions);
    append_semantic_ids(record, lineage.sourceIsolationSheets);
    record.push_back(lineage.quotientClass.has_value()
                         ? static_cast<std::int64_t>(
                               lineage.quotientClass->index())
                         : -1);
    append_semantic_ids(record, lineage.sourceOccurrences);

    std::vector<geometry::SourceProjectionChart> charts =
        lineage.sourceCharts;
    std::sort(charts.begin(), charts.end());
    charts.erase(std::unique(charts.begin(), charts.end()), charts.end());
    record.push_back(static_cast<std::int64_t>(charts.size()));
    for (const auto &chart : charts) {
      record.insert(record.end(),
                    {static_cast<std::int64_t>(chart.chart.index()),
                     static_cast<std::int64_t>(chart.face.vertices()[0].index()),
                     static_cast<std::int64_t>(chart.face.vertices()[1].index()),
                     static_cast<std::int64_t>(chart.face.vertices()[2].index())});
    }

    std::vector<Record> equivalenceRecords;
    for (const auto &equivalence : lineage.equivalences) {
      Record relation{
          static_cast<int>(equivalence.kind),
          static_cast<int>(equivalence.action.rotation.value()),
          equivalence.action.shift.x, equivalence.action.shift.y,
          static_cast<std::int64_t>(equivalence.route.steps().size())};
      for (const authority::TransitionStep &step : equivalence.route.steps()) {
        relation.push_back(static_cast<std::int64_t>(step.topology().first().index()));
        relation.push_back(static_cast<std::int64_t>(step.topology().second().index()));
        relation.push_back(static_cast<std::int64_t>(step.kind()));
        relation.push_back(step.interior().has_value()
                               ? static_cast<std::int64_t>(step.interior()->index())
                               : -1);
      }
      relation.push_back(
          static_cast<std::int64_t>(equivalence.isolationSeams.size()));
      for (const authority::SourceEdgeTopologyKey &topology :
           equivalence.isolationSeams) {
        relation.push_back(static_cast<std::int64_t>(topology.first().index()));
        relation.push_back(static_cast<std::int64_t>(topology.second().index()));
      }
      equivalenceRecords.push_back(std::move(relation));
    }
    std::sort(equivalenceRecords.begin(), equivalenceRecords.end());
    equivalenceRecords.erase(
        std::unique(equivalenceRecords.begin(), equivalenceRecords.end()),
        equivalenceRecords.end());
    record.push_back(static_cast<std::int64_t>(equivalenceRecords.size()));
    for (const Record &equivalence : equivalenceRecords) {
      append_record(record, equivalence);
    }

    if (lineage.kind ==
        geometry::PureQuadVertexLineageKind::OrderedFeatureInterval) {
      record.insert(record.end(),
                    {lineage.featureInterval.railId.has_value()
                         ? static_cast<std::int64_t>(
                               lineage.featureInterval.railId->index())
                         : -1,
                     lineage.featureInterval.curveId,
                     bits(lineage.featureInterval.parameter)});
    }
  }

  std::vector<int> faceParent(static_cast<std::size_t>(result.product().faces.rows()));
  std::iota(faceParent.begin(), faceParent.end(), 0);
  const auto face_root = [&](int face) {
    int root = face;
    while (faceParent[static_cast<std::size_t>(root)] != root) {
      root = faceParent[static_cast<std::size_t>(root)];
    }
    while (faceParent[static_cast<std::size_t>(face)] != face) {
      const int next = faceParent[static_cast<std::size_t>(face)];
      faceParent[static_cast<std::size_t>(face)] = root;
      face = next;
    }
    return root;
  };
  const auto join_faces = [&](const int first, const int second) {
    const int firstRoot = face_root(first);
    const int secondRoot = face_root(second);
    if (firstRoot != secondRoot) {
      faceParent[static_cast<std::size_t>(secondRoot)] = firstRoot;
    }
  };
  std::vector<std::vector<int>> facesByVertex(
      static_cast<std::size_t>(result.product().vertices.rows()));
  std::vector<std::vector<int>> faceVertices(
      static_cast<std::size_t>(result.product().faces.rows()));
  for (int face = 0; face < result.product().faces.rows(); ++face) {
    const int degree = result.product().degrees(face);
    if (degree < 3 || degree > result.product().faces.cols()) return 0U;
    for (int corner = 0; corner < degree; ++corner) {
      const int vertex = result.product().faces(face, corner);
      if (vertex < 0 || vertex >= result.product().vertices.rows()) return 0U;
      faceVertices[static_cast<std::size_t>(face)].push_back(vertex);
      facesByVertex[static_cast<std::size_t>(vertex)].push_back(face);
    }
  }
  for (const auto &incidentFaces : facesByVertex) {
    for (std::size_t index = 1; index < incidentFaces.size(); ++index) {
      join_faces(incidentFaces.front(), incidentFaces[index]);
    }
  }

  struct ComponentRecords {
    std::set<int> vertices;
    std::vector<Record> faces;
    std::vector<Record> edges;
  };
  std::map<int, ComponentRecords> components;
  std::set<std::pair<int, int>> seenEdges;
  for (int face = 0; face < result.product().faces.rows(); ++face) {
    ComponentRecords &component = components[face_root(face)];
    const auto &vertices = faceVertices[static_cast<std::size_t>(face)];
    std::vector<Record> cornerRecords;
    for (const int vertex : vertices) {
      component.vertices.insert(vertex);
      cornerRecords.push_back(vertexRecords[static_cast<std::size_t>(vertex)]);
    }
    std::vector<Record> canonicalCorners;
    for (std::size_t offset = 0; offset < cornerRecords.size(); ++offset) {
      std::vector<Record> rotated;
      for (std::size_t corner = 0; corner < cornerRecords.size(); ++corner) {
        rotated.push_back(
            cornerRecords[(offset + corner) % cornerRecords.size()]);
      }
      if (canonicalCorners.empty() || rotated < canonicalCorners) {
        canonicalCorners = std::move(rotated);
      }
    }
    Record faceRecord;
    faceRecord.push_back(static_cast<std::int64_t>(canonicalCorners.size()));
    for (const Record &corner : canonicalCorners) {
      append_record(faceRecord, corner);
    }
    const auto &lineage = *lineageByFace[static_cast<std::size_t>(face)];
    faceRecord.insert(
        faceRecord.end(),
        {static_cast<int>(lineage.operation), lineage.completionVariant,
         lineage.boundaryOnly ? 1 : 0,
         static_cast<std::int64_t>(lineage.canonicalStitchCycleHash),
         static_cast<std::int64_t>(
             lineage.canonicalAuthoritativeCycleHash)});
    component.faces.push_back(std::move(faceRecord));

    for (std::size_t corner = 0; corner < vertices.size(); ++corner) {
      const int first = vertices[corner];
      const int second = vertices[(corner + 1U) % vertices.size()];
      const auto edge = canonical_edge(first, second);
      if (seenEdges.insert(edge).second) {
        const Record &firstRecord = vertexRecords[static_cast<std::size_t>(first)];
        const Record &secondRecord =
            vertexRecords[static_cast<std::size_t>(second)];
        Record edgeRecord;
        if (secondRecord < firstRecord) {
          append_record(edgeRecord, secondRecord);
          append_record(edgeRecord, firstRecord);
        } else {
          append_record(edgeRecord, firstRecord);
          append_record(edgeRecord, secondRecord);
        }
        component.edges.push_back(std::move(edgeRecord));
      }
    }
  }

  std::vector<Record> componentRecords;
  for (auto &[root, component] : components) {
    (void)root;
    std::vector<Record> vertices;
    for (const int vertex : component.vertices) {
      vertices.push_back(vertexRecords[static_cast<std::size_t>(vertex)]);
    }
    std::sort(vertices.begin(), vertices.end());
    std::sort(component.edges.begin(), component.edges.end());
    std::sort(component.faces.begin(), component.faces.end());
    Record componentRecord;
    componentRecord.insert(
        componentRecord.end(),
        {static_cast<std::int64_t>(vertices.size()),
         static_cast<std::int64_t>(component.edges.size()),
         static_cast<std::int64_t>(component.faces.size())});
    for (const Record &vertex : vertices) append_record(componentRecord, vertex);
    for (const Record &edge : component.edges) append_record(componentRecord, edge);
    for (const Record &face : component.faces) append_record(componentRecord, face);
    componentRecords.push_back(std::move(componentRecord));
  }
  std::sort(componentRecords.begin(), componentRecords.end());
  std::uint64_t hash = 1469598103934665603ULL;
  mix_hash(hash, static_cast<std::uint64_t>(componentRecords.size()));
  for (const Record &component : componentRecords) {
    mix_hash(hash, static_cast<std::uint64_t>(component.size()));
    for (const std::int64_t value : component) {
      mix_hash(hash, static_cast<std::uint64_t>(value));
    }
  }
  return hash;
}

std::string benchmark_hash_string(const std::uint64_t hash) {
  std::ostringstream stream;
  stream << std::hex << std::setfill('0') << std::setw(16) << hash;
  return stream.str();
}

BenchmarkQuality evaluate_benchmark_quality(
    const BenchmarkCase &benchmarkCase, const BenchmarkMesh &sourceMesh,
    const BenchmarkField &field, const pipeline::RemeshResult &result,
    const std::uint64_t peakWorkingSetBytes,
    const std::filesystem::path &artifactDirectory) {
  BenchmarkQuality quality;
  quality.peakWorkingSetBytes = peakWorkingSetBytes;
  quality.outputStructuralHashValue = benchmark_output_structural_hash(result);
  quality.outputStructuralHash =
      benchmark_hash_string(quality.outputStructuralHashValue);
  quality.outputSemanticHashValue = benchmark_output_semantic_hash(result);
  quality.outputSemanticHash =
      benchmark_hash_string(quality.outputSemanticHashValue);
  if (!result.is_produced() || result.product().vertices.rows() == 0 ||
      result.product().faces.rows() == 0 ||
      result.product().degrees.size() != result.product().faces.rows()) {
    quality.error =
        "Cannot evaluate quality for an unsuccessful or empty mesh.";
    return quality;
  }

  try {
    const double scale = mesh_scale(sourceMesh.vertices);
    const double targetLength =
        std::max(1.0e-12, scale * benchmarkCase.lengthRatio);
    const double geometricTolerance = std::max(1.0e-12, scale * 1.0e-9);
    const EdgeIncidence outputIncidence =
        build_edge_incidence(result.product().faces, result.product().degrees);

    int quadFaces = 0;
    for (int face = 0; face < result.product().degrees.size(); ++face) {
      if (result.product().degrees(face) == 4) {
        ++quadFaces;
      }
    }
    quality.pureQuadRate =
        result.product().faces.rows() > 0
            ? static_cast<double>(quadFaces) / result.product().faces.rows()
            : 0.0;
    for (const auto &[edge, incidentFaces] : outputIncidence) {
      (void)edge;
      if (incidentFaces.size() > 2U) {
        ++quality.nonManifoldEdgeCount;
      }
    }
    quality.tJunctionCount =
        count_t_junctions(result.product().vertices, outputIncidence, geometricTolerance);
    quality.duplicateFaceCount =
        count_duplicate_faces(result.product().faces, result.product().degrees);
    quality.selfIntersectionCount = count_self_intersections(
        result.product().vertices, result.product().faces, geometricTolerance);

    const Eigen::VectorXi sourceDegrees =
        Eigen::VectorXi::Constant(sourceMesh.faces.rows(), 3);
    const TopologySummary sourceTopology =
        summarize_topology(sourceMesh.faces, sourceDegrees);
    const TopologySummary outputTopology =
        summarize_topology(result.product().faces, result.product().degrees);
    quality.topologyPreserved =
        sourceTopology.connectedComponents ==
            outputTopology.connectedComponents &&
        sourceTopology.eulerCharacteristic ==
            outputTopology.eulerCharacteristic &&
        sourceTopology.boundaryLoopCount == outputTopology.boundaryLoopCount &&
        outputTopology.boundaryClosed;
    quality.boundaryPreserved =
        quality.topologyPreserved &&
        boundaries_match(sourceMesh, result,
                         std::max(1.0e-8 * scale, 1.0e-5 * targetLength));

    const auto [featureRecall, featureP95] =
        feature_metrics(sourceMesh, result, targetLength);
    quality.featureRecall = featureRecall;
    quality.featureAlignmentP95Degrees = featureP95;

    const geometry::SurfaceProjectionBvh sourceProjection(sourceMesh.vertices,
                                                          sourceMesh.faces);
    std::vector<double> fieldErrors;
    std::vector<double> sizeErrors;
    for (const auto &[edge, incidentFaces] : outputIncidence) {
      (void)incidentFaces;
      const Eigen::Vector3d first = result.product().vertices.row(edge.first);
      const Eigen::Vector3d second = result.product().vertices.row(edge.second);
      const Eigen::Vector3d direction = second - first;
      const geometry::SurfacePoint sourcePoint =
          sourceProjection.project(0.5 * (first + second));
      if (sourcePoint.valid()) {
        const int a = sourceMesh.faces(sourcePoint.face, 0);
        const int b = sourceMesh.faces(sourcePoint.face, 1);
        const int c = sourceMesh.faces(sourcePoint.face, 2);
        const Eigen::Vector3d sourceA = sourceMesh.vertices.row(a).transpose();
        const Eigen::Vector3d sourceB = sourceMesh.vertices.row(b).transpose();
        const Eigen::Vector3d sourceC = sourceMesh.vertices.row(c).transpose();
        Eigen::Vector3d normal = (sourceB - sourceA).cross(sourceC - sourceA);
        Eigen::Vector3d tangent = direction;
        if (normal.squaredNorm() > 0.0) {
          normal.normalize();
          tangent -= tangent.dot(normal) * normal;
        }
        fieldErrors.push_back(
            field_alignment_error(tangent, field, sourcePoint.face));
      }
      sizeErrors.push_back(std::abs(direction.norm() / targetLength - 1.0));
    }
    quality.fieldAlignmentP95Degrees = percentile(std::move(fieldErrors), 0.95);
    quality.relativeSizeErrorP95 = percentile(std::move(sizeErrors), 0.95);

    const Eigen::MatrixXi outputTriangles = triangulate_output(result);
    const geometry::SurfaceProjectionBvh outputProjection(result.product().vertices,
                                                          outputTriangles);
    std::vector<double> approximation = directed_surface_errors(
        surface_samples(result.product().vertices, result.product().faces, result.product().degrees),
        sourceProjection, targetLength);
    std::vector<double> reverse = directed_surface_errors(
        surface_samples(sourceMesh.vertices, sourceMesh.faces, sourceDegrees),
        outputProjection, targetLength);
    approximation.insert(approximation.end(), reverse.begin(), reverse.end());
    quality.surfaceApproximationP95 =
        percentile(std::move(approximation), 0.95);

    compute_valence(result, quality);

    const std::string stem =
        benchmarkCase.name + "__" + quality.outputStructuralHash;
    const std::filesystem::path meshPath =
        std::filesystem::absolute(artifactDirectory / (stem + ".obj"));
    const std::filesystem::path reviewPath =
        std::filesystem::absolute(artifactDirectory / (stem + ".bmp"));
    write_obj(meshPath, result);
    write_review_image(reviewPath, sourceMesh, result);
    quality.outputMeshPath = meshPath.generic_string();
    quality.reviewImagePath = reviewPath.generic_string();
    quality.available = true;
  } catch (const std::exception &exception) {
    quality.error = exception.what();
  }
  return quality;
}

std::string write_benchmark_failure_review_image(
    const BenchmarkCase &benchmarkCase, const BenchmarkMesh &sourceMesh,
    const std::filesystem::path &artifactDirectory) {
  const std::filesystem::path reviewPath = std::filesystem::absolute(
      artifactDirectory / (benchmarkCase.name + "__failure.bmp"));
  write_review_image(reviewPath, sourceMesh, pipeline::RemeshResult{}, true);
  return reviewPath.generic_string();
}

void write_benchmark_quality_json(std::ostream &out,
                                  const BenchmarkQuality &quality) {
  out << "{"
      << "\"available\":" << (quality.available ? "true" : "false") << ","
      << "\"error\":\"" << escape_json(quality.error) << "\","
      << "\"pureQuadRate\":" << quality.pureQuadRate << ","
      << "\"nonManifoldEdgeCount\":" << quality.nonManifoldEdgeCount << ","
      << "\"tJunctionCount\":" << quality.tJunctionCount << ","
      << "\"duplicateFaceCount\":" << quality.duplicateFaceCount << ","
      << "\"selfIntersectionCount\":" << quality.selfIntersectionCount << ","
      << "\"topologyPreserved\":"
      << (quality.topologyPreserved ? "true" : "false") << ","
      << "\"boundaryPreserved\":"
      << (quality.boundaryPreserved ? "true" : "false") << ","
      << "\"featureRecall\":" << quality.featureRecall << ","
      << "\"featureAlignmentP95Degrees\":" << quality.featureAlignmentP95Degrees
      << ","
      << "\"fieldAlignmentP95Degrees\":" << quality.fieldAlignmentP95Degrees
      << ","
      << "\"relativeSizeErrorP95\":" << quality.relativeSizeErrorP95 << ","
      << "\"surfaceApproximationP95\":" << quality.surfaceApproximationP95
      << ","
      << "\"irregularVertexCount\":" << quality.irregularVertexCount << ","
      << "\"peakWorkingSetBytes\":" << quality.peakWorkingSetBytes << ","
      << "\"outputStructuralHash\":\""
      << escape_json(quality.outputStructuralHash) << "\","
      << "\"outputSemanticHash\":\""
      << escape_json(quality.outputSemanticHash) << "\","
      << "\"outputMeshPath\":\"" << escape_json(quality.outputMeshPath) << "\","
      << "\"reviewImagePath\":\"" << escape_json(quality.reviewImagePath)
      << "\","
      << "\"valenceHistogram\":{";
  std::size_t index = 0;
  for (const auto &[valence, count] : quality.valenceHistogram) {
    if (index++ > 0U) {
      out << ",";
    }
    out << "\"" << valence << "\":" << count;
  }
  out << "}}";
}

} // namespace directional::bench
