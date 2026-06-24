#include "RemeshOutput.h"

#include "CrossFieldOutput.h"
#include "MatrixIO.h"

#include <algorithm>
#include <cctype>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace directional::cli {
namespace {

std::filesystem::path sidecar(const std::filesystem::path &prefix,
                              const char *suffix) {
  return std::filesystem::path(prefix.string() + suffix);
}

std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

QuadMeshData quadrangulate_remeshed_mesh_impl(
    const Eigen::MatrixXd &vertices,
    const Eigen::VectorXi &degrees,
    const Eigen::MatrixXi &faces) {
  if (vertices.cols() != 3) {
    throw std::runtime_error(
        "Remeshing output vertices must have shape (#V, 3).");
  }
  if (degrees.size() != faces.rows()) {
    throw std::runtime_error(
        "Remeshing output requires one polygon degree per face row.");
  }

  std::vector<Eigen::RowVector3d> outputVertices;
  outputVertices.reserve(
      static_cast<std::size_t>(vertices.rows() + faces.rows()));

  for (Eigen::Index vertex = 0; vertex < vertices.rows(); ++vertex) {
    outputVertices.push_back(vertices.row(vertex));
  }

  std::vector<Eigen::RowVector4i> outputFaces;
  std::map<std::pair<int, int>, int> edgeMidpoints;

  for (Eigen::Index face = 0; face < faces.rows(); ++face) {
    const int degree = degrees(face);
    if (degree < 3 || degree > faces.cols()) {
      throw std::runtime_error("Invalid polygon degree in remeshing output.");
    }

    Eigen::RowVector3d center = Eigen::RowVector3d::Zero();
    std::vector<int> polygon(static_cast<std::size_t>(degree));

    for (int corner = 0; corner < degree; ++corner) {
      const int index = faces(face, corner);
      if (index < 0 || index >= vertices.rows()) {
        throw std::runtime_error("Invalid vertex index in remeshing output.");
      }

      if (std::find(polygon.begin(), polygon.begin() + corner, index) !=
          polygon.begin() + corner) {
        throw std::runtime_error("Degenerate polygon in remeshing output.");
      }

      polygon[static_cast<std::size_t>(corner)] = index;
      center += vertices.row(index);
    }

    center /= static_cast<double>(degree);
    const int centerIndex = static_cast<int>(outputVertices.size());
    outputVertices.push_back(center);

    std::vector<int> midpointIndices(static_cast<std::size_t>(degree));

    for (int corner = 0; corner < degree; ++corner) {
      const int first = polygon[static_cast<std::size_t>(corner)];
      const int second =
          polygon[static_cast<std::size_t>((corner + 1) % degree)];
      const std::pair<int, int> edge{
          std::min(first, second),
          std::max(first, second),
      };

      const auto existing = edgeMidpoints.find(edge);
      if (existing != edgeMidpoints.end()) {
        midpointIndices[static_cast<std::size_t>(corner)] = existing->second;
        continue;
      }

      const int midpointIndex = static_cast<int>(outputVertices.size());
      outputVertices.push_back(
          0.5 * (vertices.row(first) + vertices.row(second)));
      edgeMidpoints.emplace(edge, midpointIndex);
      midpointIndices[static_cast<std::size_t>(corner)] = midpointIndex;
    }

    for (int corner = 0; corner < degree; ++corner) {
      const int previous = (corner + degree - 1) % degree;
      Eigen::RowVector4i quad;
      quad << polygon[static_cast<std::size_t>(corner)],
          midpointIndices[static_cast<std::size_t>(corner)], centerIndex,
          midpointIndices[static_cast<std::size_t>(previous)];
      outputFaces.push_back(quad);
    }
  }

  if (outputFaces.empty()) {
    throw std::runtime_error("Remeshing output contains no polygons.");
  }

  QuadMeshData result;
  result.vertices.resize(static_cast<Eigen::Index>(outputVertices.size()), 3);
  result.faces.resize(static_cast<Eigen::Index>(outputFaces.size()), 4);

  for (Eigen::Index vertex = 0; vertex < result.vertices.rows(); ++vertex) {
    result.vertices.row(vertex) =
        outputVertices[static_cast<std::size_t>(vertex)];
  }
  for (Eigen::Index face = 0; face < result.faces.rows(); ++face) {
    result.faces.row(face) = outputFaces[static_cast<std::size_t>(face)];
  }

  return result;
}

} // namespace

QuadMeshData quadrangulate_remeshed_mesh(
    const Eigen::MatrixXd &vertices,
    const Eigen::VectorXi &degrees,
    const Eigen::MatrixXi &faces) {
  return quadrangulate_remeshed_mesh_impl(vertices, degrees, faces);
}

void write_remeshed_mesh(const std::filesystem::path &path,
                          const Eigen::MatrixXd &vertices,
                          const Eigen::VectorXi &degrees,
                          const Eigen::MatrixXi &faces) {
  const std::string extension = lowercase(path.extension().string());
  if (extension != ".obj" && extension != ".off") {
    throw std::runtime_error(
        "Native remeshing output must use the .obj or .off extension.");
  }

  const QuadMeshData quadMesh =
      quadrangulate_remeshed_mesh(vertices, degrees, faces);
  const Eigen::VectorXi quadDegrees =
      Eigen::VectorXi::Constant(quadMesh.faces.rows(), 4);

  if (extension == ".off") {
    write_polygonal_off(
        path,
        quadMesh.vertices,
        quadDegrees,
        quadMesh.faces);
    return;
  }

  write_polygonal_obj(
      path,
      quadMesh.vertices,
      quadDegrees,
      quadMesh.faces);
}

void write_remesh_diagnostics(
    const std::filesystem::path &prefix,
    const std::string &meshExtension,
    const Eigen::VectorXi &degrees,
    const Eigen::MatrixXd &cutVertices,
    const Eigen::MatrixXi &cutFaces,
    const Eigen::MatrixXd &cutFunctions,
    const Eigen::MatrixXd &cutCornerFunctions,
    const Eigen::MatrixXd &rawCrossField,
    const Eigen::VectorXi &crossFieldMatching,
    const Eigen::VectorXd &crossFieldEffort,
    const Eigen::VectorXi &crossFieldSingularCycles,
    const Eigen::VectorXi &crossFieldSingularIndices) {
  write_dmat(sidecar(prefix, ".degrees.dmat"), degrees);

  const std::string extension = lowercase(meshExtension);
  if (extension == ".obj") {
    write_triangle_obj(sidecar(prefix, ".cut.obj"), cutVertices, cutFaces);
  } else if (extension == ".off") {
    write_triangle_off(sidecar(prefix, ".cut.off"), cutVertices, cutFaces);
  } else {
    throw std::runtime_error(
        "Diagnostic mesh output requires .obj or .off remesh output.");
  }

  write_dmat(sidecar(prefix, ".cut_functions.dmat"), cutFunctions);
  write_dmat(
      sidecar(prefix, ".cut_corner_functions.dmat"),
      cutCornerFunctions);
  write_raw_field(sidecar(prefix, ".cross_field.txt"), 4, rawCrossField);
  write_dmat(sidecar(prefix, ".matching.dmat"), crossFieldMatching);
  write_dmat(sidecar(prefix, ".effort.dmat"), crossFieldEffort);
  write_dmat(
      sidecar(prefix, ".singular_cycles.dmat"),
      crossFieldSingularCycles);
  write_dmat(
      sidecar(prefix, ".singular_indices.dmat"),
      crossFieldSingularIndices);
}

} // namespace directional::cli
