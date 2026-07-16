#include "BenchmarkCases.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>

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
  std::vector<BenchmarkCase> cases;
  for (const std::string &object : manifest_case_objects(text)) {
    BenchmarkCase benchmarkCase;
    benchmarkCase.name = json_string_value(object, "name");
    benchmarkCase.meshPath = json_string_value(object, "mesh");
    benchmarkCase.lengthRatio =
        json_number_value(object, "length_ratio", benchmarkCase.lengthRatio);
    benchmarkCase.integralSeamless =
        json_bool_value(object, "integral_seamless",
                        benchmarkCase.integralSeamless);
    benchmarkCase.roundSeams =
        json_bool_value(object, "round_seams", benchmarkCase.roundSeams);
    benchmarkCase.synthetic =
        json_bool_value(object, "synthetic", benchmarkCase.meshPath.empty());
    benchmarkCase.syntheticSubdivisions =
        json_int_value(object, "synthetic_subdivisions",
                       benchmarkCase.syntheticSubdivisions);
    if (benchmarkCase.name.empty()) {
      throw std::runtime_error("Benchmark manifest case is missing a name.");
    }
    cases.push_back(std::move(benchmarkCase));
  }
  if (cases.empty()) {
    throw std::runtime_error("Benchmark manifest contains no cases: " +
                             path.string());
  }
  return cases;
}

BenchmarkMesh load_benchmark_mesh(const BenchmarkCase &benchmarkCase) {
  if (benchmarkCase.synthetic) {
    return make_synthetic_grid(benchmarkCase.syntheticSubdivisions);
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
  options.verbose = false;
  return options;
}

} // namespace directional::bench
