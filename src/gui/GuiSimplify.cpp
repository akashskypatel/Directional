#include "GuiBackend.h"

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

#include <directional/meshing/TriFlowSimplification.h>

namespace directional::gui {
namespace {

TriFlowSimplificationOptions to_core_options(
    const MeshSimplificationOptions &options) {
  TriFlowSimplificationOptions result;
  result.targetFaceCount = options.targetFaceCount >= 4
                               ? options.targetFaceCount
                               : -1;
  result.targetFaceRatio = options.targetFaceRatio;
  result.vertexNvf = options.vertexNvf;
  result.vertexTargets = options.vertexTargets;
  result.rootThreshold = options.rootThreshold;
  result.voxelResolution = options.voxelResolution;
  result.topologyWeight = options.topologyWeight;
  result.rootRelaxationThreshold = options.rootRelaxationThreshold;
  result.preserveBoundary = options.preserveBoundary;
  result.rejectFaceFlips = options.rejectFaceFlips;
  result.verbose = options.verbose;
  return result;
}

void validate_simplification_options(
    const MeshSimplificationOptions &options) {
  if (options.targetFaceCount != 0 && options.targetFaceCount < 4) {
    throw std::runtime_error(
        "Simplification target triangle count must be 0 or at least 4.");
  }
  if (!std::isfinite(options.targetFaceRatio) ||
      options.targetFaceRatio <= 0.0 || options.targetFaceRatio > 1.0) {
    throw std::runtime_error(
        "Simplification target face ratio must be in the range (0, 1].");
  }
  if (options.rootThreshold < 0.0 && options.rootThreshold != -1.0) {
    throw std::runtime_error(
        "Simplification root threshold must be non-negative, or -1 for auto.");
  }
  if (options.voxelResolution <= 0) {
    throw std::runtime_error(
        "Simplification voxel resolution must be positive.");
  }
  if (!std::isfinite(options.topologyWeight) ||
      options.topologyWeight < 0.0) {
    throw std::runtime_error(
        "Simplification topology weight must be non-negative.");
  }
  if (!std::isfinite(options.rootRelaxationThreshold) ||
      options.rootRelaxationThreshold < 0.0) {
    throw std::runtime_error(
        "Simplification root relaxation threshold must be non-negative.");
  }
}

} // namespace

MeshSimplificationData simplify_mesh(const MeshData &mesh,
                                     const MeshSimplificationOptions &options,
                                     ProgressCallback progress) {
  if (mesh.vertices.cols() != 3 || mesh.faces.cols() != 3) {
    throw std::runtime_error(
        "TriFlow simplification requires a triangle mesh with 3D vertices.");
  }
  validate_simplification_options(options);

  if (progress) {
    progress(0, 100, "Starting TriFlow simplification");
  }

  TriFlowSimplificationResult simplified =
      tri_flow_simplify(mesh.vertices, mesh.faces, to_core_options(options));
  if (!simplified.success) {
    throw std::runtime_error(
        "TriFlow simplification failed to produce a valid triangle mesh.");
  }

  if (progress) {
    progress(100, 100, "TriFlow simplification finished");
  }

  MeshSimplificationData result;
  result.mesh.vertices = std::move(simplified.vertices);
  result.mesh.faces = std::move(simplified.faces);
  result.rootLabels = std::move(simplified.rootLabels);
  result.rootCount = simplified.rootCount;
  result.collapsedEdges = simplified.collapsedEdges;
  return result;
}

} // namespace directional::gui
