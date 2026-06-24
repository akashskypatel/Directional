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
  pipelineOptions.verbose = options.verbose;
  pipelineOptions.progress = std::move(progress);

  const pipeline::RemeshResult remesh =
      pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, pipelineOptions);
  if (!remesh.success) {
    throw std::runtime_error(
        "Remeshing failed while assembling the output mesh.");
  }

  const cli::QuadMeshData quad = cli::quadrangulate_remeshed_mesh(
      remesh.vertices, remesh.degrees, remesh.faces);
  return {quad.vertices, quad.faces};
}

} // namespace directional::gui
