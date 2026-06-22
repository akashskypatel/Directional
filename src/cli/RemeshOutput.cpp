#include "RemeshOutput.h"

#include "CrossFieldOutput.h"
#include "MatrixIO.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>

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

} // namespace

void write_remeshed_mesh(const std::filesystem::path &path,
                         const Eigen::MatrixXd &vertices,
                         const Eigen::VectorXi &degrees,
                         const Eigen::MatrixXi &faces) {
  const std::string extension = lowercase(path.extension().string());
  if (extension == ".off") {
    write_polygonal_off(path, vertices, degrees, faces);
    return;
  }
  if (extension == ".obj") {
    write_polygonal_obj(path, vertices, degrees, faces);
    return;
  }
  throw std::runtime_error(
      "Native remeshing output must use the .obj or .off extension.");
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
  write_dmat(sidecar(prefix, ".cut_corner_functions.dmat"),
             cutCornerFunctions);
  write_raw_field(sidecar(prefix, ".cross_field.txt"), 4, rawCrossField);
  write_dmat(sidecar(prefix, ".matching.dmat"), crossFieldMatching);
  write_dmat(sidecar(prefix, ".effort.dmat"), crossFieldEffort);
  write_dmat(sidecar(prefix, ".singular_cycles.dmat"),
             crossFieldSingularCycles);
  write_dmat(sidecar(prefix, ".singular_indices.dmat"),
             crossFieldSingularIndices);
}

} // namespace directional::cli
