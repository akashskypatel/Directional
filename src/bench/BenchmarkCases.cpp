#include "BenchmarkCases.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <directional/fields/CrossField.h>

namespace directional::bench {
namespace {

std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

std::string read_text_file(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open benchmark manifest: " +
                             path.string());
  }
  std::ostringstream buffer;
  buffer << stream.rdbuf();
  return buffer.str();
}

std::string json_string_value(const std::string &object,
                              const std::string &key,
                              const std::string &fallback = {}) {
  const std::regex pattern("\"" + key + "\"\\s*:\\s*\"([^\"]*)\"");
  std::smatch match;
  if (std::regex_search(object, match, pattern)) {
    return match[1].str();
  }
  return fallback;
}

double json_number_value(const std::string &object, const std::string &key,
                         const double fallback) {
  const std::regex pattern("\"" + key +
                           "\"\\s*:\\s*(-?[0-9]+(?:\\.[0-9]+)?(?:[eE][+-]?[0-9]+)?)");
  std::smatch match;
  if (std::regex_search(object, match, pattern)) {
    return std::stod(match[1].str());
  }
  return fallback;
}

int json_int_value(const std::string &object, const std::string &key,
                   const int fallback) {
  return static_cast<int>(json_number_value(object, key, fallback));
}

bool json_bool_value(const std::string &object, const std::string &key,
                     const bool fallback) {
  const std::regex pattern("\"" + key + "\"\\s*:\\s*(true|false)");
  std::smatch match;
  if (std::regex_search(object, match, pattern)) {
    return match[1].str() == "true";
  }
  return fallback;
}

std::vector<std::string> manifest_case_objects(const std::string &text) {
  std::vector<std::string> objects;
  const std::size_t casesPosition = text.find("\"cases\"");
  if (casesPosition == std::string::npos) {
    return objects;
  }
  const std::size_t arrayBegin = text.find('[', casesPosition);
  if (arrayBegin == std::string::npos) {
    return objects;
  }

  int depth = 0;
  std::size_t objectBegin = std::string::npos;
  bool inString = false;
  bool escaped = false;
  for (std::size_t index = arrayBegin + 1; index < text.size(); ++index) {
    const char character = text[index];
    if (escaped) {
      escaped = false;
      continue;
    }
    if (character == '\\') {
      escaped = inString;
      continue;
    }
    if (character == '"') {
      inString = !inString;
      continue;
    }
    if (inString) {
      continue;
    }
    if (character == '{') {
      if (depth == 0) {
        objectBegin = index;
      }
      ++depth;
    } else if (character == '}') {
      --depth;
      if (depth == 0 && objectBegin != std::string::npos) {
        objects.push_back(text.substr(objectBegin, index - objectBegin + 1));
        objectBegin = std::string::npos;
      }
    } else if (character == ']' && depth == 0) {
      break;
    }
  }
  return objects;
}

BenchmarkMesh make_synthetic_grid(const int subdivisions) {
  const int n = std::max(1, subdivisions);
  BenchmarkMesh mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices(vertex, 0) = static_cast<double>(x) / n;
      mesh.vertices(vertex, 1) = static_cast<double>(y) / n;
      mesh.vertices(vertex, 2) = 0.0;
    }
  }

  mesh.faces.resize(2 * n * n, 3);
  int face = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int v00 = y * (n + 1) + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * (n + 1) + x;
      const int v11 = v01 + 1;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

BenchmarkMesh make_synthetic_component_grid(const int subdivisions,
                                            const int componentCount) {
  BenchmarkMesh base = make_synthetic_grid(subdivisions);
  const int components = std::max(1, componentCount);
  BenchmarkMesh mesh;
  mesh.vertices.resize(base.vertices.rows() * components, 3);
  mesh.faces.resize(base.faces.rows() * components, 3);
  const double spacing = 3.0;
  for (int component = 0; component < components; ++component) {
    const int vertexOffset = component * static_cast<int>(base.vertices.rows());
    const int faceOffset = component * static_cast<int>(base.faces.rows());
    for (int vertex = 0; vertex < base.vertices.rows(); ++vertex) {
      mesh.vertices.row(vertexOffset + vertex) = base.vertices.row(vertex);
      mesh.vertices(vertexOffset + vertex, 0) += spacing * component;
    }
    for (int face = 0; face < base.faces.rows(); ++face) {
      mesh.faces.row(faceOffset + face) =
          base.faces.row(face).array() + vertexOffset;
    }
  }
  return mesh;
}

Eigen::RowVector3d normalized(const Eigen::RowVector3d &value) {
  const double norm = value.norm();
  if (norm < 1.0e-12) {
    throw std::runtime_error("Benchmark field contains a near-zero vector.");
  }
  return value / norm;
}

Eigen::MatrixXd make_raw_cross_field(const Eigen::MatrixXd &primary,
                                     const Eigen::MatrixXd &secondary) {
  if (primary.rows() != secondary.rows() || primary.cols() != 3 ||
      secondary.cols() != 3) {
    throw std::runtime_error("Cross-field data must be #F-by-3 pairs.");
  }
  Eigen::MatrixXd raw(primary.rows(), 12);
  raw.block(0, 0, primary.rows(), 3) = primary;
  raw.block(0, 3, primary.rows(), 3) = secondary;
  raw.block(0, 6, primary.rows(), 3) = -primary;
  raw.block(0, 9, primary.rows(), 3) = -secondary;
  return raw;
}

BenchmarkField read_crossfield(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open benchmark field: " +
                             path.string());
  }

  std::vector<Eigen::Matrix<double, 1, 6>> rows;
  std::string line;
  while (std::getline(stream, line)) {
    const std::size_t comment = line.find('#');
    if (comment != std::string::npos) {
      line.erase(comment);
    }
    std::replace(line.begin(), line.end(), ',', ' ');
    std::istringstream input(line);
    std::vector<double> values;
    double value = 0.0;
    while (input >> value) {
      values.push_back(value);
    }
    if (values.empty()) {
      continue;
    }
    std::size_t offset = 0;
    if (values.size() >= 7 &&
        std::llround(values[0]) == static_cast<long long>(rows.size())) {
      offset = 1;
    }
    if (values.size() - offset < 6) {
      throw std::runtime_error(
          "Benchmark crossfield rows require six numeric values.");
    }
    Eigen::Matrix<double, 1, 6> row;
    for (int index = 0; index < 6; ++index) {
      row(index) = values[offset + index];
    }
    rows.push_back(row);
  }
  if (rows.empty()) {
    throw std::runtime_error("Benchmark field contains no rows: " +
                             path.string());
  }

  BenchmarkField field;
  field.available = true;
  field.degree = 4;
  Eigen::MatrixXd primary(rows.size(), 3);
  Eigen::MatrixXd secondary(rows.size(), 3);
  for (Eigen::Index row = 0; row < static_cast<Eigen::Index>(rows.size());
       ++row) {
    primary.row(row) = normalized(rows[static_cast<std::size_t>(row)].segment<3>(0));
    secondary.row(row) =
        normalized(rows[static_cast<std::size_t>(row)].segment<3>(3));
  }
  field.raw = make_raw_cross_field(primary, secondary);
  return field;
}

BenchmarkField read_rawfield(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open benchmark raw field: " +
                             path.string());
  }

  Eigen::Index count = 0;
  BenchmarkField field;
  if (!(stream >> field.degree >> count) || field.degree <= 0 || count < 0) {
    throw std::runtime_error("Invalid benchmark rawfield header.");
  }
  field.raw.resize(count, field.degree * 3);
  for (Eigen::Index row = 0; row < count; ++row) {
    for (Eigen::Index col = 0; col < field.raw.cols(); ++col) {
      if (!(stream >> field.raw(row, col))) {
        throw std::runtime_error("Invalid benchmark rawfield data.");
      }
    }
  }
  if (field.degree != 4 || field.raw.cols() != 12) {
    throw std::runtime_error(
        "Benchmark remeshing requires degree-4 raw fields.");
  }
  field.available = true;
  return field;
}

bool format_is_crossfield(const std::string &format) {
  const std::string lowered = lowercase(format);
  return lowered == "crossfield" || lowered == "cross-field" ||
         lowered == "neurcross" || lowered == "neuralcross" ||
         lowered == "vec" || lowered == "txt";
}

bool format_is_rawfield(const std::string &format) {
  const std::string lowered = lowercase(format);
  return lowered == "rawfield" || lowered == "raw-field";
}

BenchmarkMesh read_off(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open input mesh: " + path.string());
  }

  std::string magic;
  int vertexCount = 0;
  int faceCount = 0;
  int edgeCount = 0;
  if (!(stream >> magic >> vertexCount >> faceCount >> edgeCount) ||
      magic != "OFF" || vertexCount <= 0 || faceCount <= 0) {
    throw std::runtime_error("Invalid OFF header in: " + path.string());
  }

  BenchmarkMesh mesh;
  mesh.vertices.resize(vertexCount, 3);
  mesh.faces.resize(faceCount, 3);
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    if (!(stream >> mesh.vertices(vertex, 0) >> mesh.vertices(vertex, 1) >>
          mesh.vertices(vertex, 2))) {
      throw std::runtime_error("Invalid OFF vertex data in: " + path.string());
    }
  }
  for (int face = 0; face < faceCount; ++face) {
    int degree = 0;
    if (!(stream >> degree) || degree != 3 ||
        !(stream >> mesh.faces(face, 0) >> mesh.faces(face, 1) >>
          mesh.faces(face, 2))) {
      throw std::runtime_error("Benchmark meshes must be triangular OFF files.");
    }
  }
  return mesh;
}

int parse_obj_index(const std::string &token, const int vertexCount) {
  const std::size_t separator = token.find('/');
  const int sourceIndex = std::stoi(token.substr(0, separator));
  const int index = sourceIndex > 0 ? sourceIndex - 1 : vertexCount + sourceIndex;
  if (index < 0 || index >= vertexCount) {
    throw std::runtime_error("OBJ face vertex index is out of range.");
  }
  return index;
}

BenchmarkMesh read_obj(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open input mesh: " + path.string());
  }

  std::vector<Eigen::RowVector3d> vertices;
  std::vector<Eigen::RowVector3i> faces;
  std::string line;
  while (std::getline(stream, line)) {
    std::istringstream lineStream(line);
    std::string recordType;
    lineStream >> recordType;
    if (recordType == "v") {
      Eigen::RowVector3d vertex;
      if (!(lineStream >> vertex.x() >> vertex.y() >> vertex.z())) {
        throw std::runtime_error("Invalid OBJ vertex in: " + path.string());
      }
      vertices.push_back(vertex);
    } else if (recordType == "f") {
      std::string tokens[4];
      if (!(lineStream >> tokens[0] >> tokens[1] >> tokens[2]) ||
          (lineStream >> tokens[3])) {
        throw std::runtime_error("Benchmark meshes must be triangular OBJ files.");
      }
      Eigen::RowVector3i face;
      for (int corner = 0; corner < 3; ++corner) {
        face(corner) =
            parse_obj_index(tokens[corner], static_cast<int>(vertices.size()));
      }
      faces.push_back(face);
    }
  }

  if (vertices.empty() || faces.empty()) {
    throw std::runtime_error("OBJ mesh contains no vertices or faces: " +
                             path.string());
  }

  BenchmarkMesh mesh;
  mesh.vertices.resize(static_cast<int>(vertices.size()), 3);
  mesh.faces.resize(static_cast<int>(faces.size()), 3);
  for (int vertex = 0; vertex < mesh.vertices.rows(); ++vertex) {
    mesh.vertices.row(vertex) = vertices[static_cast<std::size_t>(vertex)];
  }
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    mesh.faces.row(face) = faces[static_cast<std::size_t>(face)];
  }
  return mesh;
}

} // namespace

std::vector<BenchmarkCase> default_benchmark_cases() {
  BenchmarkCase synthetic;
  synthetic.name = "synthetic_grid_2";
  synthetic.synthetic = true;
  synthetic.syntheticSubdivisions = 2;
  synthetic.lengthRatio = 0.2;
  synthetic.integralSeamless = false;
  synthetic.roundSeams = false;
  return {synthetic};
}

std::vector<BenchmarkCase>
load_benchmark_manifest(const std::filesystem::path &path) {
  const std::string text = read_text_file(path);
  const std::filesystem::path basePath = path.parent_path();
  std::vector<BenchmarkCase> cases;
  for (const std::string &object : manifest_case_objects(text)) {
    BenchmarkCase benchmarkCase;
    benchmarkCase.name = json_string_value(object, "name");
    benchmarkCase.meshPath = json_string_value(object, "mesh");
    benchmarkCase.fieldPath = json_string_value(object, "field");
    benchmarkCase.fieldFormat =
        json_string_value(object, "field_format", benchmarkCase.fieldFormat);
    benchmarkCase.generatedField =
        json_string_value(object, "generated_field",
                          benchmarkCase.generatedField);
    benchmarkCase.lengthRatio =
        json_number_value(object, "length_ratio", benchmarkCase.lengthRatio);
    benchmarkCase.integralSeamless =
        json_bool_value(object, "integral_seamless",
                        benchmarkCase.integralSeamless);
    benchmarkCase.roundSeams =
        json_bool_value(object, "round_seams", benchmarkCase.roundSeams);
    benchmarkCase.backend = pipeline::parse_remesh_backend(
        json_string_value(object, "backend",
                          pipeline::remesh_backend_name(benchmarkCase.backend)));
    benchmarkCase.surfaceCellFallback =
        pipeline::parse_surface_cell_fallback_policy(json_string_value(
            object, "surface_cell_fallback",
            pipeline::surface_cell_fallback_policy_name(
                benchmarkCase.surfaceCellFallback)));
    benchmarkCase.surfaceCellSkeletonHints =
        json_bool_value(object, "surface_cell_skeleton_hints",
                        benchmarkCase.surfaceCellSkeletonHints);
    benchmarkCase.surfaceCellPreserveDebugArtifacts =
        json_bool_value(object, "surface_cell_preserve_debug_artifacts",
                        benchmarkCase.surfaceCellPreserveDebugArtifacts);
    benchmarkCase.surfaceCellTraverseUnmarkedSharpBends = json_bool_value(
        object, "surface_cell_traverse_unmarked_sharp_bends",
        benchmarkCase.surfaceCellTraverseUnmarkedSharpBends);
    benchmarkCase.surfaceCellSheetNormalCompatibility = json_number_value(
        object, "surface_cell_sheet_normal_compatibility",
        benchmarkCase.surfaceCellSheetNormalCompatibility);
    benchmarkCase.surfaceCellCloseSheetRadiusMeanEdges = json_number_value(
        object, "surface_cell_close_sheet_radius_mean_edges",
        benchmarkCase.surfaceCellCloseSheetRadiusMeanEdges);
    benchmarkCase.surfaceCellGeodesicExclusionDepth = json_int_value(
        object, "surface_cell_geodesic_exclusion_depth",
        benchmarkCase.surfaceCellGeodesicExclusionDepth);
    benchmarkCase.synthetic =
        json_bool_value(object, "synthetic", benchmarkCase.meshPath.empty());
    benchmarkCase.syntheticSubdivisions =
        json_int_value(object, "synthetic_subdivisions",
                       benchmarkCase.syntheticSubdivisions);
    benchmarkCase.syntheticComponents =
        json_int_value(object, "synthetic_components",
                       benchmarkCase.syntheticComponents);
    if (benchmarkCase.name.empty()) {
      throw std::runtime_error("Benchmark manifest case is missing a name.");
    }
    if (!benchmarkCase.meshPath.empty() && benchmarkCase.meshPath.is_relative()) {
      benchmarkCase.meshPath = basePath / benchmarkCase.meshPath;
    }
    if (!benchmarkCase.fieldPath.empty() && benchmarkCase.fieldPath.is_relative()) {
      benchmarkCase.fieldPath = basePath / benchmarkCase.fieldPath;
    }
    cases.push_back(std::move(benchmarkCase));
  }
  if (cases.empty()) {
    throw std::runtime_error("Benchmark manifest contains no cases: " +
                             path.string());
  }
  return cases;
}

BenchmarkField load_benchmark_field(const BenchmarkCase &benchmarkCase,
                                    const Eigen::Index expectedFaces) {
  if (benchmarkCase.fieldPath.empty()) {
    return {};
  }

  BenchmarkField field;
  if (benchmarkCase.fieldFormat != "auto") {
    if (format_is_crossfield(benchmarkCase.fieldFormat)) {
      field = read_crossfield(benchmarkCase.fieldPath);
    } else if (format_is_rawfield(benchmarkCase.fieldFormat)) {
      field = read_rawfield(benchmarkCase.fieldPath);
    } else {
      throw std::runtime_error("Unsupported benchmark field format: " +
                               benchmarkCase.fieldFormat);
    }
  } else {
    const std::string extension =
        lowercase(benchmarkCase.fieldPath.extension().string());
    if (extension == ".rawfield") {
      field = read_rawfield(benchmarkCase.fieldPath);
    } else if (extension == ".vec" || extension == ".txt" ||
               extension == ".neurcross" || extension == ".ncfield") {
      field = read_crossfield(benchmarkCase.fieldPath);
    } else {
      throw std::runtime_error(
          "Cannot infer benchmark field format from extension: " + extension);
    }
  }

  if (field.raw.rows() != expectedFaces) {
    throw std::runtime_error(
        "Benchmark field row count must match the mesh face count.");
  }
  return field;
}

BenchmarkField generate_benchmark_field(const BenchmarkCase &benchmarkCase,
                                        const BenchmarkMesh &mesh) {
  if (benchmarkCase.generatedField == "smooth") {
    fields::CrossFieldOptions options;
    options.normalizeDirections = true;
    options.combDirections = true;
    options.computeMatching = true;
    const fields::CrossFieldResult extracted =
        fields::extract_cross_field(mesh.vertices, mesh.faces, options);
    if (extracted.degree != 4 ||
        extracted.rawField.rows() != mesh.faces.rows() ||
        extracted.rawField.cols() != 12 ||
        !extracted.rawField.allFinite()) {
      throw std::runtime_error(
          "Smooth benchmark cross-field extraction returned invalid data.");
    }
    BenchmarkField field;
    field.available = true;
    field.degree = extracted.degree;
    field.raw = extracted.rawField;
    return field;
  }

  if (benchmarkCase.generatedField != "face_edges" &&
      benchmarkCase.generatedField != "constant_xy") {
    return {};
  }

  BenchmarkField field;
  field.available = true;
  field.degree = 4;

  Eigen::MatrixXd primary(mesh.faces.rows(), 3);
  Eigen::MatrixXd secondary(mesh.faces.rows(), 3);
  if (benchmarkCase.generatedField == "constant_xy") {
    for (Eigen::Index face = 0; face < mesh.faces.rows(); ++face) {
      primary.row(face) << 1.0, 0.0, 0.0;
      secondary.row(face) << 0.0, 1.0, 0.0;
    }
    field.raw = make_raw_cross_field(primary, secondary);
    return field;
  }

  for (Eigen::Index face = 0; face < mesh.faces.rows(); ++face) {
    const Eigen::RowVector3d a = mesh.vertices.row(mesh.faces(face, 0));
    const Eigen::RowVector3d b = mesh.vertices.row(mesh.faces(face, 1));
    const Eigen::RowVector3d c = mesh.vertices.row(mesh.faces(face, 2));

    Eigen::RowVector3d edge = b - a;
    if (edge.squaredNorm() < 1.0e-20) {
      edge = c - a;
    }
    Eigen::RowVector3d normal = edge.cross(c - a);
    if (normal.squaredNorm() < 1.0e-20) {
      throw std::runtime_error(
          "Cannot generate benchmark field on a degenerate face.");
    }
    normal.normalize();

    Eigen::RowVector3d tangent = edge - edge.dot(normal) * normal;
    if (tangent.squaredNorm() < 1.0e-20) {
      tangent = c - a;
      tangent = tangent - tangent.dot(normal) * normal;
    }
    tangent = normalized(tangent);
    Eigen::RowVector3d bitangent = normalized(normal.cross(tangent));

    primary.row(face) = tangent;
    secondary.row(face) = bitangent;
  }

  field.raw = make_raw_cross_field(primary, secondary);
  return field;
}

BenchmarkMesh load_benchmark_mesh(const BenchmarkCase &benchmarkCase) {
  if (benchmarkCase.synthetic) {
    return make_synthetic_component_grid(benchmarkCase.syntheticSubdivisions,
                                         benchmarkCase.syntheticComponents);
  }

  const std::string extension = lowercase(benchmarkCase.meshPath.extension().string());
  if (extension == ".obj") {
    return read_obj(benchmarkCase.meshPath);
  }
  if (extension == ".off") {
    return read_off(benchmarkCase.meshPath);
  }
  throw std::runtime_error("Unsupported benchmark mesh extension: " + extension);
}

pipeline::RemeshOptions make_remesh_options(const BenchmarkCase &benchmarkCase) {
  pipeline::RemeshOptions options;
  options.lengthRatio = benchmarkCase.lengthRatio;
  options.integralSeamless = benchmarkCase.integralSeamless;
  options.roundSeams = benchmarkCase.roundSeams;
  options.backend = benchmarkCase.backend;
  options.surfaceCells.enabled =
      benchmarkCase.backend == pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.fallbackPolicy = benchmarkCase.surfaceCellFallback;
  options.surfaceCells.useSkeletonHints =
      benchmarkCase.surfaceCellSkeletonHints;
  options.surfaceCells.preserveDebugArtifacts =
      benchmarkCase.surfaceCellPreserveDebugArtifacts;
  options.surfaceCells.sourceClassifier.traverseUnmarkedSharpBends =
      benchmarkCase.surfaceCellTraverseUnmarkedSharpBends;
  options.surfaceCells.sourceClassifier.normalCompatibility =
      benchmarkCase.surfaceCellSheetNormalCompatibility;
  options.surfaceCells.sourceClassifier.closeSheetRadiusMeanEdges =
      benchmarkCase.surfaceCellCloseSheetRadiusMeanEdges;
  options.surfaceCells.sourceClassifier.geodesicExclusionDepth =
      benchmarkCase.surfaceCellGeodesicExclusionDepth;
  options.verbose = false;
  return options;
}

} // namespace directional::bench
