#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../src/cli/CliBackend.h"

#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <directional/fields/CrossField.h>
#include <directional/fields/RegularizedCurvatureCrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace py = pybind11;

namespace {

bool is_native_mesh_path(const std::filesystem::path &path) {
  const std::string extension = path.extension().string();
  return extension == ".obj" || extension == ".OBJ" ||
         extension == ".off" || extension == ".OFF";
}

py::object load_trimesh(const std::filesystem::path &path) {
  py::module_ trimesh = py::module_::import("trimesh");
  py::object mesh = trimesh.attr("load")(path.string(), py::arg("process") = false);
  if (py::isinstance(mesh, trimesh.attr("Scene"))) {
    mesh = mesh.attr("dump")(py::arg("concatenate") = true);
  }
  if (!py::isinstance(mesh, trimesh.attr("Trimesh"))) {
    throw std::runtime_error(path.string() +
                             " did not load as a triangle mesh through trimesh.");
  }
  return mesh;
}

void export_trimesh(const py::object &mesh, const std::filesystem::path &path) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
  mesh.attr("export")(path.string());
}

int run_python_cli(std::vector<std::string> arguments) {
  py::module_ tempfile = py::module_::import("tempfile");
  py::object temporaryDirectory = tempfile.attr("TemporaryDirectory")();
  const std::filesystem::path temporaryRoot =
      py::cast<std::string>(temporaryDirectory.attr("name"));

  std::filesystem::path requestedOutput;
  std::filesystem::path adaptedOutput;
  bool convertOutput = false;

  auto adapt_input = [&](const std::size_t index, const std::string &name) {
    if (index >= arguments.size()) {
      return;
    }
    const std::filesystem::path source = arguments[index];
    if (is_native_mesh_path(source)) {
      return;
    }
    const std::filesystem::path converted = temporaryRoot / (name + ".obj");
    export_trimesh(load_trimesh(source), converted);
    arguments[index] = converted.string();
  };

  if (!arguments.empty()) {
    const std::string &command = arguments.front();
    if (command == "cross-field") {
      adapt_input(1, "cross-field-input");
    } else if (command == "remesh") {
      adapt_input(1, "remesh-input");
      if (arguments.size() > 2) {
        requestedOutput = arguments[2];
        if (!is_native_mesh_path(requestedOutput)) {
          adaptedOutput = temporaryRoot / "remesh-output.obj";
          arguments[2] = adaptedOutput.string();
          convertOutput = true;
        }
      }
    } else if (command == "convert-field") {
      for (std::size_t i = 1; i + 1 < arguments.size(); ++i) {
        if (arguments[i] == "--mesh") {
          adapt_input(i + 1, "field-conversion-mesh");
          break;
        }
      }
    }
  }

  int status = 0;
  {
    py::scoped_ostream_redirect stdoutRedirect(
        std::cout, py::module_::import("sys").attr("stdout"));
    py::scoped_estream_redirect stderrRedirect(
        std::cerr, py::module_::import("sys").attr("stderr"));
    status = directional::cli::run_cli(arguments);
  }

  if (status == 0 && convertOutput) {
    export_trimesh(load_trimesh(adaptedOutput), requestedOutput);
  }
  temporaryDirectory.attr("cleanup")();
  return status;
}

} // namespace

PYBIND11_MODULE(_directional, module) {
  module.doc() =
      "Python bindings for Directional cross-field extraction and remeshing.";

  module.def("run_cli", &run_python_cli, py::arg("arguments"),
             "Run the shared native CLI backend. Non-OBJ/OFF mesh paths are "
             "adapted through trimesh for the Python entry point.");

  py::class_<directional::fields::CrossFieldOptions>(module,
                                                      "CrossFieldOptions")
      .def(py::init<>())
      .def_readwrite(
          "normalizeDirections",
          &directional::fields::CrossFieldOptions::normalizeDirections)
      .def_readwrite("computeMatching",
                     &directional::fields::CrossFieldOptions::computeMatching);

  py::class_<directional::fields::CrossFieldResult>(module,
                                                     "CrossFieldResult")
      .def_readonly("degree", &directional::fields::CrossFieldResult::degree)
      .def_readonly("rawField",
                    &directional::fields::CrossFieldResult::rawField)
      .def_readonly(
          "primaryDirections",
          &directional::fields::CrossFieldResult::primaryDirections)
      .def_readonly(
          "secondaryDirections",
          &directional::fields::CrossFieldResult::secondaryDirections)
      .def_readonly("matching",
                    &directional::fields::CrossFieldResult::matching)
      .def_readonly("effort", &directional::fields::CrossFieldResult::effort)
      .def_readonly(
          "singularCycles",
          &directional::fields::CrossFieldResult::singularCycles)
      .def_readonly(
          "singularIndices",
          &directional::fields::CrossFieldResult::singularIndices);

  module.def(
      "extract_cross_field",
      [](const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
         const directional::fields::CrossFieldOptions &options) {
        return directional::fields::extract_cross_field(vertices, faces,
                                                        options);
      },
      py::arg("vertices"), py::arg("faces"),
      py::arg("options") = directional::fields::CrossFieldOptions{},
      "Extract a smooth face-based 4-RoSy cross field from a triangle mesh.");

  py::class_<directional::RegularizedProxyMeshOptions>(
      module, "RegularizedProxyMeshOptions")
      .def(py::init<>())
      .def_readwrite("fidelityWeight",
                     &directional::RegularizedProxyMeshOptions::fidelityWeight)
      .def_readwrite("smoothnessWeight",
                     &directional::RegularizedProxyMeshOptions::smoothnessWeight)
      .def_readwrite("preserveBoundary",
                     &directional::RegularizedProxyMeshOptions::preserveBoundary)
      .def_readwrite(
          "clampNegativeCotangents",
          &directional::RegularizedProxyMeshOptions::clampNegativeCotangents)
      .def_readwrite("fixedVertices",
                     &directional::RegularizedProxyMeshOptions::fixedVertices);

  py::class_<directional::FaceCurvatureOptions>(module,
                                                 "FaceCurvatureOptions")
      .def(py::init<>())
      .def_readwrite("smoothingIterations",
                     &directional::FaceCurvatureOptions::smoothingIterations)
      .def_readwrite("preserveSharpFeatures",
                     &directional::FaceCurvatureOptions::preserveSharpFeatures)
      .def_readwrite(
          "sharpFeatureAngleDegrees",
          &directional::FaceCurvatureOptions::sharpFeatureAngleDegrees)
      .def_readwrite("minimumRelativeArea",
                     &directional::FaceCurvatureOptions::minimumRelativeArea)
      .def_readwrite(
          "minimumSingularValueRatio",
          &directional::FaceCurvatureOptions::minimumSingularValueRatio)
      .def_readwrite("magnitudeGateScale",
                     &directional::FaceCurvatureOptions::magnitudeGateScale)
      .def_readwrite("residualDecay",
                     &directional::FaceCurvatureOptions::residualDecay);

  py::class_<directional::FaceCurvatureResult>(module,
                                                "FaceCurvatureResult")
      .def_readonly("principalDirectionsMin",
                    &directional::FaceCurvatureResult::principalDirectionsMin)
      .def_readonly("principalDirectionsMax",
                    &directional::FaceCurvatureResult::principalDirectionsMax)
      .def_readonly("principalCurvatures",
                    &directional::FaceCurvatureResult::principalCurvatures)
      .def_readonly("fitResiduals",
                    &directional::FaceCurvatureResult::fitResiduals)
      .def_readonly("fitQuality",
                    &directional::FaceCurvatureResult::fitQuality)
      .def_readonly("confidence",
                    &directional::FaceCurvatureResult::confidence)
      .def_readonly("valid", &directional::FaceCurvatureResult::valid);

  py::class_<directional::fields::RegularizedCurvatureCrossFieldOptions>(
      module, "RegularizedCurvatureCrossFieldOptions")
      .def(py::init<>())
      .def_readwrite(
          "proxy",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::proxy)
      .def_readwrite(
          "curvature",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::curvature)
      .def_readwrite(
          "fieldSmoothnessWeight",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::
              fieldSmoothnessWeight)
      .def_readwrite(
          "curvatureAlignmentWeight",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::
              curvatureAlignmentWeight)
      .def_readwrite(
          "confidenceExponent",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::
              confidenceExponent)
      .def_readwrite(
          "minimumConfidence",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::
              minimumConfidence)
      .def_readwrite(
          "normalizeDirections",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::
              normalizeDirections)
      .def_readwrite(
          "computeMatching",
          &directional::fields::RegularizedCurvatureCrossFieldOptions::
              computeMatching);

  py::class_<directional::fields::RegularizedCurvatureCrossFieldResult>(
      module, "RegularizedCurvatureCrossFieldResult")
      .def_readonly(
          "field",
          &directional::fields::RegularizedCurvatureCrossFieldResult::field)
      .def_readonly(
          "proxyVertices",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              proxyVertices)
      .def_readonly(
          "proxyDisplacement",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              proxyDisplacement)
      .def_readonly(
          "proxyCurvature",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              proxyCurvature)
      .def_readonly(
          "constrainedFaces",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              constrainedFaces)
      .def_readonly(
          "constraintDirections",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              constraintDirections)
      .def_readonly(
          "alignmentWeights",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              alignmentWeights)
      .def_readonly(
          "smoothnessEnergy",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              smoothnessEnergy)
      .def_readonly(
          "alignmentEnergy",
          &directional::fields::RegularizedCurvatureCrossFieldResult::
              alignmentEnergy);

  module.def(
      "extract_regularized_curvature_cross_field",
      [](const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
         const directional::fields::RegularizedCurvatureCrossFieldOptions
             &options) {
        return directional::fields::extract_regularized_curvature_cross_field(
            vertices, faces, options);
      },
      py::arg("vertices"), py::arg("faces"),
      py::arg("options") =
          directional::fields::RegularizedCurvatureCrossFieldOptions{},
      "Extract a smooth 4-RoSy field aligned to curvature of a regularized "
      "same-topology proxy mesh.");

  py::class_<directional::pipeline::RemeshOptions>(module, "RemeshOptions")
      .def(py::init<>())
      .def_readwrite("lengthRatio",
                     &directional::pipeline::RemeshOptions::lengthRatio)
      .def_readwrite(
          "integralSeamless",
          &directional::pipeline::RemeshOptions::integralSeamless)
      .def_readwrite("roundSeams",
                     &directional::pipeline::RemeshOptions::roundSeams)
    //   .def_readwrite("featureAlign",
    //                  &directional::pipeline::RemeshOptions::featureAlign)
      .def_readwrite("verbose",
                     &directional::pipeline::RemeshOptions::verbose)
      .def_readwrite(
          "normalizeDirections",
          &directional::pipeline::RemeshOptions::normalizeDirections);

  py::class_<directional::pipeline::RemeshResult>(module, "RemeshResult")
      .def_readonly("success",
                    &directional::pipeline::RemeshResult::success)
      .def_readonly("vertices",
                    &directional::pipeline::RemeshResult::vertices)
      .def_readonly("degrees",
                    &directional::pipeline::RemeshResult::degrees)
      .def_readonly("faces", &directional::pipeline::RemeshResult::faces)
      .def_readonly("cutVertices",
                    &directional::pipeline::RemeshResult::cutVertices)
      .def_readonly("cutFaces",
                    &directional::pipeline::RemeshResult::cutFaces)
      .def_readonly("cutFunctions",
                    &directional::pipeline::RemeshResult::cutFunctions)
      .def_readonly(
          "cutCornerFunctions",
          &directional::pipeline::RemeshResult::cutCornerFunctions)
      .def_readonly("rawCrossField",
                    &directional::pipeline::RemeshResult::rawCrossField)
      .def_readonly(
          "crossFieldMatching",
          &directional::pipeline::RemeshResult::crossFieldMatching)
      .def_readonly(
          "crossFieldEffort",
          &directional::pipeline::RemeshResult::crossFieldEffort)
      .def_readonly(
          "crossFieldSingularCycles",
          &directional::pipeline::RemeshResult::crossFieldSingularCycles)
      .def_readonly(
          "crossFieldSingularIndices",
          &directional::pipeline::RemeshResult::crossFieldSingularIndices);

  module.def(
      "remesh_from_raw_cross_field",
      [](const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
         const Eigen::MatrixXd &rawCrossField,
         const directional::pipeline::RemeshOptions &options) {
        return directional::pipeline::remesh_from_raw_cross_field(
            vertices, faces, rawCrossField, options);
      },
      py::arg("vertices"), py::arg("faces"), py::arg("raw_cross_field"),
      py::arg("options") = directional::pipeline::RemeshOptions{});

  module.def(
      "remesh_from_cross_field",
      [](const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
         const Eigen::MatrixXd &primaryDirections,
         const Eigen::MatrixXd &secondaryDirections,
         const directional::pipeline::RemeshOptions &options) {
        return directional::pipeline::remesh_from_cross_field(
            vertices, faces, primaryDirections, secondaryDirections, options);
      },
      py::arg("vertices"), py::arg("faces"), py::arg("primary_directions"),
      py::arg("secondary_directions"),
      py::arg("options") = directional::pipeline::RemeshOptions{});

  module.def(
      "remesh_from_cross_field",
      [](const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
         const Eigen::MatrixXd &primaryDirections,
         const directional::pipeline::RemeshOptions &options) {
        return directional::pipeline::remesh_from_cross_field(
            vertices, faces, primaryDirections, options);
      },
      py::arg("vertices"), py::arg("faces"), py::arg("primary_directions"),
      py::arg("options") = directional::pipeline::RemeshOptions{});

  module.def(
      "remesh_from_mesh",
      [](const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
         const directional::pipeline::RemeshOptions &options) {
        return directional::pipeline::remesh_from_mesh(vertices, faces,
                                                       options);
      },
      py::arg("vertices"), py::arg("faces"),
      py::arg("options") = directional::pipeline::RemeshOptions{},
      "Extract a degree-4 cross field from a mesh and run remeshing.");
}
