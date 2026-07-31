#include <directional/integration/ParametrizationQuality.h>

namespace directional::detail {

Eigen::Matrix2d triangle_source_basis(const Eigen::MatrixXd &vertices,
                                             const Eigen::Vector3i &face) {
  const Eigen::Vector3d p0 = vertices.row(face(0)).transpose();
  const Eigen::Vector3d p1 = vertices.row(face(1)).transpose();
  const Eigen::Vector3d p2 = vertices.row(face(2)).transpose();
  const Eigen::Vector3d e1 = p1 - p0;
  const Eigen::Vector3d e2 = p2 - p0;
  const double e1Norm = e1.norm();
  if (e1Norm <= 0.0) {
    return Eigen::Matrix2d::Zero();
  }

  const Eigen::Vector3d axis0 = e1 / e1Norm;
  const double x2 = e2.dot(axis0);
  const Eigen::Vector3d orthogonal = e2 - x2 * axis0;
  const double y2 = orthogonal.norm();

  Eigen::Matrix2d basis;
  basis << e1Norm, x2, 0.0, y2;
  return basis;
}

} // namespace directional::detail

namespace directional::detail {

bool faces_share_vertex(const Eigen::Vector3i &a,
                               const Eigen::Vector3i &b) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a(i) == b(j)) {
        return true;
      }
    }
  }
  return false;
}

} // namespace directional::detail

namespace directional {

ParametrizationQualityReport analyze_parametrization_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &parameterFunctions,
    const ParametrizationQualityThresholds &thresholds) {
  if (vertices.cols() < 3) {
    throw std::invalid_argument(
        "analyze_parametrization_quality(): vertices must have 3 columns");
  }
  if (faces.cols() != 3) {
    throw std::invalid_argument(
        "analyze_parametrization_quality(): faces must be triangular");
  }
  if (parameterFunctions.rows() != vertices.rows() ||
      parameterFunctions.cols() < 2) {
    throw std::invalid_argument(
        "analyze_parametrization_quality(): parameterFunctions must be #V-by-2 "
        "or wider");
  }

  ParametrizationQualityReport report;
  report.faces.resize(static_cast<std::size_t>(faces.rows()));

  double conditionSum = 0.0;
  double scaleSum = 0.0;

  for (int faceIndex = 0; faceIndex < faces.rows(); ++faceIndex) {
    const Eigen::Vector3i face = faces.row(faceIndex).transpose();
    ParametrizationFaceQuality quality;

    const Eigen::Matrix2d source =
        detail::triangle_source_basis(vertices, face);
    const double sourceDeterminant = source.determinant();

    if (std::abs(sourceDeterminant) <= thresholds.determinantEpsilon) {
      quality.nearDegenerate = true;
      quality.bad = true;
      report.faces[static_cast<std::size_t>(faceIndex)] = quality;
      ++report.nearDegenerateFaceCount;
      ++report.badFaceCount;
      continue;
    }

    Eigen::Matrix2d target;
    target.col(0) =
        (parameterFunctions.row(face(1)).head<2>() -
         parameterFunctions.row(face(0)).head<2>())
            .transpose();
    target.col(1) =
        (parameterFunctions.row(face(2)).head<2>() -
         parameterFunctions.row(face(0)).head<2>())
            .transpose();

    const Eigen::Matrix2d jacobian = target * source.inverse();
    quality.determinant = jacobian.determinant();

    const Eigen::Matrix2d normal = jacobian.transpose() * jacobian;
    const Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> eigenSolver(normal);
    const Eigen::Vector2d eigenvalues =
        eigenSolver.eigenvalues().cwiseMax(0.0);
    quality.sigmaMin = std::sqrt(eigenvalues.minCoeff());
    quality.sigmaMax = std::sqrt(eigenvalues.maxCoeff());

    if (quality.sigmaMin <= 0.0) {
      quality.conditionNumber = std::numeric_limits<double>::infinity();
      quality.scaleDistortion = std::numeric_limits<double>::infinity();
    } else {
      quality.conditionNumber = quality.sigmaMax / quality.sigmaMin;
      quality.scaleDistortion =
          std::max(quality.sigmaMax, 1.0 / quality.sigmaMin);
    }

    quality.inverted = quality.determinant <= thresholds.determinantEpsilon;
    quality.nearDegenerate =
        quality.sigmaMin < thresholds.minimumSingularValue;
    quality.highCondition =
        quality.conditionNumber > thresholds.maximumConditionNumber;
    quality.highScaleDistortion =
        quality.scaleDistortion > thresholds.maximumScaleDistortion;
    quality.bad = quality.inverted || quality.nearDegenerate ||
                  quality.highCondition || quality.highScaleDistortion;

    if (quality.inverted) {
      ++report.invertedFaceCount;
    }
    if (quality.nearDegenerate) {
      ++report.nearDegenerateFaceCount;
    }
    if (quality.highCondition) {
      ++report.highConditionFaceCount;
    }
    if (quality.highScaleDistortion) {
      ++report.highScaleDistortionFaceCount;
    }
    if (quality.bad) {
      ++report.badFaceCount;
    }

    if (std::isfinite(quality.conditionNumber)) {
      report.maximumConditionNumber =
          std::max(report.maximumConditionNumber, quality.conditionNumber);
      conditionSum += quality.conditionNumber;
    }
    if (std::isfinite(quality.scaleDistortion)) {
      report.maximumScaleDistortion =
          std::max(report.maximumScaleDistortion, quality.scaleDistortion);
      scaleSum += quality.scaleDistortion;
    }

    report.faces[static_cast<std::size_t>(faceIndex)] = quality;
  }

  if (!report.faces.empty()) {
    const double denominator = static_cast<double>(report.faces.size());
    report.meanConditionNumber = conditionSum / denominator;
    report.meanScaleDistortion = scaleSum / denominator;
  }

  return report;
}

} // namespace directional

namespace directional {

TargetedStiffeningWeights build_targeted_stiffening_weights(
    const Eigen::MatrixXi &faces, const ParametrizationQualityReport &report,
    const TargetedStiffeningOptions &options) {
  if (faces.cols() != 3) {
    throw std::invalid_argument(
        "build_targeted_stiffening_weights(): faces must be triangular");
  }
  if (static_cast<std::size_t>(faces.rows()) != report.faces.size()) {
    throw std::invalid_argument(
        "build_targeted_stiffening_weights(): report size does not match faces");
  }

  TargetedStiffeningWeights weights;
  weights.faceWeights =
      Eigen::VectorXd::Ones(static_cast<Eigen::Index>(report.faces.size()));

  for (int faceIndex = 0; faceIndex < faces.rows(); ++faceIndex) {
    if (!report.faces[static_cast<std::size_t>(faceIndex)].bad) {
      continue;
    }
    weights.badFaces.push_back(faceIndex);
    weights.faceWeights(faceIndex) =
        std::max(weights.faceWeights(faceIndex), 1.0 + options.badFaceWeight);
  }

  const double neighborWeight = 1.0 + options.badFaceWeight *
                                          std::clamp(options.neighborDecay, 0.0,
                                                     1.0);
  for (const int badFace : weights.badFaces) {
    const Eigen::Vector3i bad = faces.row(badFace).transpose();
    for (int faceIndex = 0; faceIndex < faces.rows(); ++faceIndex) {
      if (faceIndex == badFace ||
          report.faces[static_cast<std::size_t>(faceIndex)].bad) {
        continue;
      }
      if (detail::faces_share_vertex(bad, faces.row(faceIndex).transpose())) {
        weights.faceWeights(faceIndex) =
            std::max(weights.faceWeights(faceIndex), neighborWeight);
      }
    }
  }

  return weights;
}

} // namespace directional
