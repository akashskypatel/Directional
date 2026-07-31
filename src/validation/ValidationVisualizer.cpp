#include <directional/validation/ValidationVisualizer.h>

namespace directional::validation {

ValidationDebugColors make_validation_debug_colors(
    const int vertexCount, const int faceCount,
    const MeshValidationResult &validation) {
  ValidationDebugColors colors;
  colors.vertexColors = Eigen::MatrixXd::Constant(vertexCount, 3, 0.75);
  colors.faceColors = Eigen::MatrixXd::Constant(faceCount, 3, 0.75);

  for (const MeshValidationIssue &issue : validation.issues) {
    if (issue.vertex >= 0 && issue.vertex < vertexCount) {
      colors.vertexColors.row(issue.vertex) << 1.0, 0.0, 0.0;
    }
    if (issue.edgeFirst >= 0 && issue.edgeFirst < vertexCount) {
      colors.vertexColors.row(issue.edgeFirst) << 1.0, 0.55, 0.0;
    }
    if (issue.edgeSecond >= 0 && issue.edgeSecond < vertexCount) {
      colors.vertexColors.row(issue.edgeSecond) << 1.0, 0.55, 0.0;
    }
    if (issue.face >= 0 && issue.face < faceCount) {
      colors.faceColors.row(issue.face) << 0.85, 0.0, 1.0;
    }
  }
  return colors;
}

} // namespace directional::validation
