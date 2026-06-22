#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

#include <directional/fields/CrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace py = pybind11;

PYBIND11_MODULE(_directional, module) {
  module.doc() =
      "Python bindings for Directional cross-field extraction and remeshing.";

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
