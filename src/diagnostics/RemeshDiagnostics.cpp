#include <directional/diagnostics/RemeshDiagnostics.h>

namespace directional {

const char *surface_cell_output_origin_name(
    const SurfaceCellOutputOrigin origin) {
  switch (origin) {
  case SurfaceCellOutputOrigin::None:
    return "None";
  case SurfaceCellOutputOrigin::CompletedSurfaceCells:
    return "CompletedSurfaceCells";
  case SurfaceCellOutputOrigin::SourceGridRecovery:
    return "SourceGridRecovery";
  case SurfaceCellOutputOrigin::LegacyFallback:
    return "LegacyFallback";
  case SurfaceCellOutputOrigin::InputMeshFallback:
    return "InputMeshFallback";
  case SurfaceCellOutputOrigin::Mixed:
    return "Mixed";
  }
  return "None";
}

} // namespace directional

namespace directional {

const char *surface_cell_consumption_kind_name(
    const SurfaceCellConsumptionKind kind) {
  switch (kind) {
  case SurfaceCellConsumptionKind::None:
    return "None";
  case SurfaceCellConsumptionKind::Full:
    return "Full";
  case SurfaceCellConsumptionKind::Partial:
    return "Partial";
  case SurfaceCellConsumptionKind::Discontinuous:
    return "Discontinuous";
  }
  return "None";
}

} // namespace directional
