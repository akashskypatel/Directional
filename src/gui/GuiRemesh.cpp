#include "GuiBackend.h"

#include "RemeshOutput.h"

#include <stdexcept>
#include <utility>

#include <directional/pipeline/RemeshPipeline.h>

namespace directional::gui {

QuadMeshData remesh_with_field(const MeshData &mesh, const FieldData &field,
                               const RemeshOptions &options,
                               ProgressCallback progress) {
  validate_field(field, mesh.faces.rows());
  validate_options({}, options);

  pipeline::RemeshOptions pipelineOptions;
  pipelineOptions.lengthRatio = options.lengthRatio;
  pipelineOptions.integralSeamless = options.integralSeamless;
  pipelineOptions.roundSeams = options.roundSeams;
  pipelineOptions.useTriFlowDcelSimplification =
      options.useTriFlowDcelSimplification;
  pipelineOptions.verbose = options.verbose;
  pipelineOptions.progress = std::move(progress);

  pipeline::RemeshResult remesh;
  if (field.raw.rows() == mesh.faces.rows() && field.raw.cols() == 12) {
    remesh = pipeline::remesh_from_raw_cross_field(
        mesh.vertices, mesh.faces, field.raw, pipelineOptions);
  } else {
    remesh = pipeline::remesh_from_cross_field(
        mesh.vertices, mesh.faces, field.primary, field.secondary,
        pipelineOptions);
  }
  if (!remesh.is_produced()) {
    throw std::runtime_error(
        "Remeshing failed while assembling the output mesh.");
  }

  const cli::QuadMeshData quad = cli::quadrangulate_remeshed_mesh(
      remesh.product().vertices, remesh.product().degrees, remesh.product().faces);
  return {quad.vertices, quad.faces};
}

} // namespace directional::gui
