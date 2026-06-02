#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

#include <directional/pipeline.h>

namespace py = pybind11;

PYBIND11_MODULE(_directional, m) {
  m.doc() = "Python bindings for the headless Directional quad-meshing pipeline";

  py::class_<directional::pipeline::RemeshOptions>(m, "RemeshOptions")
      .def(py::init<>())
      .def_readwrite("length_ratio", &directional::pipeline::RemeshOptions::lengthRatio)
      .def_readwrite("integral_seamless", &directional::pipeline::RemeshOptions::integralSeamless)
      .def_readwrite("round_seams", &directional::pipeline::RemeshOptions::roundSeams)
      .def_readwrite("feature_align", &directional::pipeline::RemeshOptions::featureAlign)
      .def_readwrite("verbose", &directional::pipeline::RemeshOptions::verbose)
      .def_readwrite("normalize_directions", &directional::pipeline::RemeshOptions::normalizeDirections);

  py::class_<directional::pipeline::RemeshResult>(m, "RemeshResult")
      .def(py::init<>())
      .def_readwrite("success", &directional::pipeline::RemeshResult::success)
      .def_readwrite("vertices", &directional::pipeline::RemeshResult::vertices)
      .def_readwrite("degrees", &directional::pipeline::RemeshResult::degrees)
      .def_readwrite("faces", &directional::pipeline::RemeshResult::faces)
      .def_readwrite("cut_vertices", &directional::pipeline::RemeshResult::cutVertices)
      .def_readwrite("cut_faces", &directional::pipeline::RemeshResult::cutFaces)
      .def_readwrite("cut_functions", &directional::pipeline::RemeshResult::cutFunctions)
      .def_readwrite("cut_corner_functions", &directional::pipeline::RemeshResult::cutCornerFunctions);

  m.def(
      "remesh_from_raw_cross_field",
      &directional::pipeline::remesh_from_raw_cross_field,
      py::arg("vertices"),
      py::arg("faces"),
      py::arg("raw_cross_field"),
      py::arg("options") = directional::pipeline::RemeshOptions{},
      "Generate a polygonal aligned mesh from a 4-RoSy raw cross field with shape (#F, 12).");

  m.def(
      "remesh_from_cross_field",
      py::overload_cast<const Eigen::MatrixXd&, const Eigen::MatrixXi&, const Eigen::MatrixXd&,
                        const Eigen::MatrixXd&, const directional::pipeline::RemeshOptions&>(
          &directional::pipeline::remesh_from_cross_field),
      py::arg("vertices"),
      py::arg("faces"),
      py::arg("primary_directions"),
      py::arg("secondary_directions"),
      py::arg("options") = directional::pipeline::RemeshOptions{},
      "Generate a polygonal aligned mesh from primary and secondary per-face tangent directions.");

  m.def(
      "remesh_from_cross_field",
      py::overload_cast<const Eigen::MatrixXd&, const Eigen::MatrixXi&, const Eigen::MatrixXd&,
                        const directional::pipeline::RemeshOptions&>(
          &directional::pipeline::remesh_from_cross_field),
      py::arg("vertices"),
      py::arg("faces"),
      py::arg("primary_directions"),
      py::arg("options") = directional::pipeline::RemeshOptions{},
      "Generate a polygonal aligned mesh from a single per-face tangent direction; the orthogonal direction is derived automatically.");
}
