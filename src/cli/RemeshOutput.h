#pragma once

#include <filesystem>
#include <string>

#include <Eigen/Core>

namespace directional::cli {

struct QuadMeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

/** Convert the mesher's variable-degree polygons to a pure quad mesh. */
QuadMeshData quadrangulate_remeshed_mesh(
    const Eigen::MatrixXd &vertices,
    const Eigen::VectorXi &degrees,
    const Eigen::MatrixXi &faces);

void write_remeshed_mesh(const std::filesystem::path &path,
                         const Eigen::MatrixXd &vertices,
                         const Eigen::VectorXi &degrees,
                         const Eigen::MatrixXi &faces);

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
    const Eigen::VectorXi &crossFieldSingularIndices);

} // namespace directional::cli
