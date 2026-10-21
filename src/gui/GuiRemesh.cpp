#include "GuiBackend.h"

#include "RemeshOutput.h"

#include <stdexcept>
#include <string>
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

FieldNetworkData trace_field_network(const MeshData &mesh,
                                     const FieldData &field,
                                     const RemeshOptions &options,
                                     ProgressCallback progress) {
  validate_field(field, mesh.faces.rows());
  validate_options({}, options);
  if (field.raw.rows() != mesh.faces.rows() || field.raw.cols() != 12) {
    throw std::runtime_error(
        "The field-aligned network needs one 12-value raw cross per mesh "
        "face.");
  }

  pipeline::RemeshOptions pipelineOptions;
  pipelineOptions.backend = pipeline::RemeshBackend::SurfaceCells;
  pipelineOptions.surfaceCells.enabled = true;
  pipelineOptions.surfaceCells.fallbackPolicy =
      pipeline::SurfaceCellFallbackPolicy::Fail;
  pipelineOptions.surfaceCells.allowSourceGridRecovery = false;
  // Snapshots are cleared at closeout unless intermediate geometry is kept.
  pipelineOptions.surfaceCells.retainIntermediateGeometry = true;
  pipelineOptions.parallelizeComponents = false;
  pipelineOptions.lengthRatio = options.lengthRatio;
  pipelineOptions.verbose = options.verbose;
  pipelineOptions.progress = std::move(progress);

  const pipeline::RemeshResult remesh = pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, field.raw, pipelineOptions);
  const auto &network =
      remesh.surfaceCellContext.productSnapshots.fieldAlignedCurveNetwork;
  if (!network.has_value()) {
    throw std::runtime_error(
        "SurfaceCells stopped before publishing a field-aligned network (" +
        (remesh.diagnostics.terminalFailureStage.empty()
             ? std::string("no stage reported")
             : remesh.diagnostics.terminalFailureStage) +
        ").");
  }

  FieldNetworkData result;
  result.polylines =
      visualization::field_aligned_network_polylines(mesh.vertices, *network);
  result.pipelineProduced = remesh.is_produced();
  result.pipelineStage = remesh.diagnostics.terminalFailureStage;
  return result;
}

} // namespace directional::gui
