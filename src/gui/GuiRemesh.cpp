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

SurfaceCellDiagnosticsData run_surface_cell_diagnostics(
    const MeshData &mesh, const FieldData &field, const RemeshOptions &options,
    const bool stopAfterQuadTracing, ProgressCallback progress) {
  validate_field(field, mesh.faces.rows());
  validate_options({}, options);
  if (field.raw.rows() != mesh.faces.rows() || field.raw.cols() != 12) {
    throw std::runtime_error(
        "SurfaceCells diagnostics need one 12-value raw cross per mesh face.");
  }

  pipeline::RemeshOptions pipelineOptions;
  pipelineOptions.backend = pipeline::RemeshBackend::SurfaceCells;
  pipelineOptions.surfaceCells.enabled = true;
  pipelineOptions.surfaceCells.fallbackPolicy =
      pipeline::SurfaceCellFallbackPolicy::Fail;
  pipelineOptions.surfaceCells.allowSourceGridRecovery = false;
  // Snapshots are cleared at closeout unless intermediate geometry is kept.
  pipelineOptions.surfaceCells.retainIntermediateGeometry = true;
  // Stage 3 is "tracing"; the pipeline reports the stop as an injected failure.
  pipelineOptions.surfaceCells.injectFailureAfterStage =
      stopAfterQuadTracing ? 3 : -1;
  pipelineOptions.parallelizeComponents = false;
  pipelineOptions.lengthRatio = options.lengthRatio;
  pipelineOptions.verbose = options.verbose;
  pipelineOptions.progress = std::move(progress);

  const pipeline::RemeshResult remesh = pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, field.raw, pipelineOptions);
  const auto &snapshots = remesh.surfaceCellContext.productSnapshots;
  SurfaceCellDiagnosticsData result;
  if (snapshots.sourceTopologyRegions.has_value()) {
    result.regions = visualization::source_region_display(
        mesh.vertices, mesh.faces, *snapshots.sourceTopologyRegions);
  }
  if (snapshots.fieldAlignedCurveNetwork.has_value()) {
    result.network = visualization::field_aligned_network_polylines(
        mesh.vertices, *snapshots.fieldAlignedCurveNetwork);
  }
  if (snapshots.surfaceCutGraph.has_value() ||
      snapshots.globalTopologyPlan.has_value()) {
    result.cutGraph = visualization::cut_graph_display(
        mesh.vertices, mesh.faces,
        snapshots.surfaceCutGraph ? &*snapshots.surfaceCutGraph : nullptr,
        snapshots.globalTopologyPlan ? &*snapshots.globalTopologyPlan : nullptr);
  }
  const auto &context = remesh.surfaceCellContext;
  result.tracing = visualization::surface_cell_tracing_display(
      mesh.vertices, mesh.faces, remesh.diagnostics,
      context.hasTraceNetwork ? &snapshots.traceNetwork : nullptr);
  result.pipelineProduced = remesh.is_produced();
  result.stoppedOnRequest =
      remesh.diagnostics.terminalFailureCode == "InjectedStageFailure";
  result.pipelineStage = remesh.diagnostics.terminalFailureStage;
  if (!result.regions.has_value() && !result.network.has_value() &&
      !result.tracing.has_stop_location() && result.tracing.cellCount == 0U) {
    throw std::runtime_error(
        "SurfaceCells stopped before publishing any diagnostic product (" +
        (result.pipelineStage.empty() ? std::string("no stage reported")
                                      : result.pipelineStage) +
        ").");
  }
  return result;
}

TargetSizeData compute_target_size(const MeshData &mesh, const FieldData &field,
                                   const RemeshOptions &options,
                                   ProgressCallback progress) {
  validate_field(field, mesh.faces.rows());
  validate_options({}, options);
  if (field.raw.rows() != mesh.faces.rows() || field.raw.cols() != 12) {
    throw std::runtime_error(
        "The target size needs one 12-value raw cross per mesh face.");
  }

  pipeline::RemeshOptions pipelineOptions;
  pipelineOptions.backend = pipeline::RemeshBackend::SurfaceCells;
  pipelineOptions.surfaceCells.enabled = true;
  pipelineOptions.surfaceCells.fallbackPolicy =
      pipeline::SurfaceCellFallbackPolicy::Fail;
  pipelineOptions.surfaceCells.allowSourceGridRecovery = false;
  pipelineOptions.surfaceCells.retainIntermediateGeometry = true;
  // Stage 1 is "metric": feature map and target size exist, nothing later runs.
  pipelineOptions.surfaceCells.injectFailureAfterStage = 1;
  pipelineOptions.parallelizeComponents = false;
  pipelineOptions.lengthRatio = options.lengthRatio;
  pipelineOptions.verbose = options.verbose;
  pipelineOptions.progress = std::move(progress);

  const pipeline::RemeshResult remesh = pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, field.raw, pipelineOptions);
  const auto &context = remesh.surfaceCellContext;
  TargetSizeData result;
  result.pipelineStage = remesh.diagnostics.terminalFailureStage;
  if (!context.hasMetricField && !context.hasFeatureMap) {
    throw std::runtime_error(
        "SurfaceCells stopped before computing the target size (" +
        (result.pipelineStage.empty() ? std::string("no stage reported")
                                      : result.pipelineStage) +
        ").");
  }
  result.display = visualization::target_size_display(
      mesh.vertices, mesh.faces,
      context.hasMetricField ? &context.metricField : nullptr,
      context.hasFeatureMap ? &context.featureMap : nullptr);
  return result;
}

} // namespace directional::gui
