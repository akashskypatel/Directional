#include "RemeshOutput.h"

#include "CrossFieldOutput.h"
#include "MatrixIO.h"

#include <stdexcept>
#include <string>

namespace directional::cli {
namespace {

std::filesystem::path sidecar(const std::filesystem::path &prefix,
                              const char *suffix) {
  return std::filesystem::path(prefix.string() + suffix);
}

} // namespace

void write_remeshed_mesh(const std::filesystem::path &path,
                         const Eigen::MatrixXd &vertices,
                         const Eigen::VectorXi &degrees,
                         const Eigen::MatrixXi &faces) {
  if (path.extension() != ".off" && path.extension() != ".OFF") {
    throw std::runtime_error(
        "Native remeshing output must use the .off extension because the "
        "generated mesh may contain non-triangular polygons.");
  }
  write_polygonal_off(path, vertices, degrees, faces);
}

void write_remesh_diagnostics(
    const std::filesystem::path &prefix,
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
  write_triangle_off(sidecar(prefix, ".cut.off"), cutVertices, cutFaces);
  write_dmat(sidecar(prefix, ".cut_functions.dmat"), cutFunctions);
  write_dmat(sidecar(prefix, ".cut_corner_functions.dmat"),
             cutCornerFunctions);
  write_raw_field(sidecar(prefix, ".rawfield"), 4, rawCrossField);
  write_dmat(sidecar(prefix, ".matching.dmat"), crossFieldMatching);
  write_dmat(sidecar(prefix, ".effort.dmat"), crossFieldEffort);
  write_dmat(sidecar(prefix, ".singular_cycles.dmat"),
             crossFieldSingularCycles);
  write_dmat(sidecar(prefix, ".singular_indices.dmat"),
             crossFieldSingularIndices);
}

} // namespace directional::cli
