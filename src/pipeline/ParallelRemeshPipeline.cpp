#include <directional/pipeline/ParallelRemeshPipeline.h>

namespace directional::pipeline {

RemeshResult parallel_remesh_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, RemeshOptions options) {
  options.parallelizeComponents = true;
  return remesh_from_raw_cross_field(vertices, faces, rawCrossField, options);
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult parallel_remesh_from_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    RemeshOptions options) {
  options.parallelizeComponents = true;
  return remesh_from_mesh(vertices, faces, options);
}

} // namespace directional::pipeline
