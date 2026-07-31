#include <directional/validation/MeshValidator.h>

namespace directional::validation {

std::pair<int, int> canonical_edge(const int a, const int b) {
  return a <= b ? std::pair<int, int>{a, b} : std::pair<int, int>{b, a};
}

} // namespace directional::validation

namespace directional::validation {

std::string_view
mesh_validation_failure_name(const MeshValidationFailureCode code) {
  switch (code) {
  case MeshValidationFailureCode::None:
    return "None";
  case MeshValidationFailureCode::MissingVertex:
    return "MissingVertex";
  case MeshValidationFailureCode::OneSidedInteriorEdge:
    return "OneSidedInteriorEdge";
  case MeshValidationFailureCode::ThreeSidedInteriorEdge:
    return "ThreeSidedInteriorEdge";
  case MeshValidationFailureCode::WrongBoundaryEdge:
    return "WrongBoundaryEdge";
  case MeshValidationFailureCode::GeometricVertexOnUnsplitEdge:
    return "GeometricVertexOnUnsplitEdge";
  case MeshValidationFailureCode::DuplicateFace:
    return "DuplicateFace";
  case MeshValidationFailureCode::BowTieVertex:
    return "BowTieVertex";
  case MeshValidationFailureCode::FlippedFace:
    return "FlippedFace";
  case MeshValidationFailureCode::ZeroAreaFace:
    return "ZeroAreaFace";
  case MeshValidationFailureCode::SelfIntersectingFace:
    return "SelfIntersectingFace";
  case MeshValidationFailureCode::ComponentMerge:
    return "ComponentMerge";
  case MeshValidationFailureCode::ChangedBoundaryLoop:
    return "ChangedBoundaryLoop";
  case MeshValidationFailureCode::MissingProvenance:
    return "MissingProvenance";
  case MeshValidationFailureCode::MissingBoundaryAuthority:
    return "MissingBoundaryAuthority";
  case MeshValidationFailureCode::MissingSourceAuthority:
    return "MissingSourceAuthority";
  case MeshValidationFailureCode::InvalidProvenance:
    return "InvalidProvenance";
  case MeshValidationFailureCode::SourceComponentMismatch:
    return "SourceComponentMismatch";
  case MeshValidationFailureCode::SourceSheetMismatch:
    return "SourceSheetMismatch";
  case MeshValidationFailureCode::SourcePositionMismatch:
    return "SourcePositionMismatch";
  case MeshValidationFailureCode::LocalSheetMismatch:
    return "LocalSheetMismatch";
  case MeshValidationFailureCode::ChangedEulerCharacteristic:
    return "ChangedEulerCharacteristic";
  case MeshValidationFailureCode::MissingFeatureRail:
    return "MissingFeatureRail";
  }
  return "Unknown";
}

} // namespace directional::validation
