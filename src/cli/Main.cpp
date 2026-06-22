#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <Eigen/Core>

#include <directional/fields/CrossField.h>
#include <directional/io/WriteSingularities.h>

#ifndef DIRECTIONAL_VERSION
#define DIRECTIONAL_VERSION "0.1.0"
#endif

extern "C" const char *directional_build_info();

namespace {

struct MeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

void print_usage(std::ostream &stream) {
  stream
      << "Directional native command line interface\n\n"
      << "Usage:\n"
      << "  directional info\n"
      << "  directional cross-field <input.obj|input.off> <output.rawfield> "
         "[options]\n"
      << "  directional --version\n"
      << "  directional --help\n\n"
      << "Commands:\n"
      << "  info         Show native library build information.\n"
      << "  cross-field  Extract a smooth face-based 4-RoSy field.\n\n"
      << "cross-field options:\n"
      << "  --singularities <path>  Write field singularities to a .sings file.\n"
      << "  --no-normalize          Preserve computed direction magnitudes.\n\n";
}

std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

MeshData read_off(const std::filesystem::path &path) {
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

  MeshData mesh;
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
      throw std::runtime_error(
          "Cross-field extraction requires triangular OFF faces.");
    }
  }

  return mesh;
}

int parse_obj_index(const std::string &token, const int vertexCount) {
  const std::size_t separator = token.find('/');
  const std::string positionToken = token.substr(0, separator);
  if (positionToken.empty()) {
    throw std::runtime_error("OBJ face contains an empty vertex index.");
  }

  const int sourceIndex = std::stoi(positionToken);
  const int index = sourceIndex > 0 ? sourceIndex - 1 : vertexCount + sourceIndex;
  if (index < 0 || index >= vertexCount) {
    throw std::runtime_error("OBJ face vertex index is out of range.");
  }
  return index;
}

MeshData read_obj(const std::filesystem::path &path) {
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
        throw std::runtime_error(
            "Cross-field extraction requires triangular OBJ faces.");
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

  MeshData mesh;
  mesh.vertices.resize(static_cast<int>(vertices.size()), 3);
  mesh.faces.resize(static_cast<int>(faces.size()), 3);
  for (int vertex = 0; vertex < mesh.vertices.rows(); ++vertex) {
    mesh.vertices.row(vertex) = vertices[vertex];
  }
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    mesh.faces.row(face) = faces[face];
  }
  return mesh;
}

MeshData load_mesh(const std::filesystem::path &path) {
  const std::string extension = lowercase(path.extension().string());
  if (extension == ".obj") {
    return read_obj(path);
  }
  if (extension == ".off") {
    return read_off(path);
  }
  throw std::runtime_error("Unsupported input mesh format: " + extension +
                           ". Expected .obj or .off.");
}

void ensure_parent_directory(const std::filesystem::path &path) {
  const std::filesystem::path parent = path.parent_path();
  if (!parent.empty()) {
    std::filesystem::create_directories(parent);
  }
}

void write_raw_field(const std::filesystem::path &path,
                     const directional::fields::CrossFieldResult &result) {
  ensure_parent_directory(path);
  std::ofstream stream(path);
  stream.flags(std::ios::scientific);
  stream.precision(std::numeric_limits<double>::digits10 + 1);
  stream << result.degree << ' ' << result.rawField.rows() << '\n';
  for (int face = 0; face < result.rawField.rows(); ++face) {
    stream << result.rawField.row(face) << '\n';
  }
  stream.close();
  if (stream.fail()) {
    throw std::runtime_error("Failed to write cross field: " + path.string());
  }
}

int run_cross_field(const int argc, char **argv) {
  if (argc < 4) {
    throw std::runtime_error(
        "cross-field requires an input mesh and output .rawfield path.");
  }

  const std::filesystem::path inputPath = argv[2];
  const std::filesystem::path outputPath = argv[3];
  std::optional<std::filesystem::path> singularitiesPath;
  directional::fields::CrossFieldOptions options;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    if (option == "--no-normalize") {
      options.normalizeDirections = false;
    } else if (option == "--singularities") {
      if (++argument >= argc) {
        throw std::runtime_error("--singularities requires an output path.");
      }
      singularitiesPath = std::filesystem::path(argv[argument]);
    } else {
      throw std::runtime_error("Unknown cross-field option: " + option);
    }
  }

  const MeshData mesh = load_mesh(inputPath);
  const directional::fields::CrossFieldResult result =
      directional::fields::extract_cross_field(mesh.vertices, mesh.faces,
                                               options);

  write_raw_field(outputPath, result);

  if (singularitiesPath.has_value()) {
    ensure_parent_directory(*singularitiesPath);
    if (!directional::write_singularities(
            singularitiesPath->string(), result.degree, result.singularCycles,
            result.singularIndices)) {
      throw std::runtime_error("Failed to write singularities: " +
                               singularitiesPath->string());
    }
  }

  std::cout << "Extracted " << result.degree << "-RoSy cross field on "
            << result.rawField.rows() << " faces with "
            << result.singularIndices.size() << " singularities.\n";
  std::cout << "Wrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace

int main(int argc, char **argv) {
  try {
    if (argc <= 1) {
      print_usage(std::cout);
      return 0;
    }

    const std::string command = argv[1];
    if (command == "--help" || command == "-h" || command == "help") {
      print_usage(std::cout);
      return 0;
    }

    if (command == "--version" || command == "-V") {
      std::cout << "directional-cli " << DIRECTIONAL_VERSION << '\n';
      return 0;
    }

    if (command == "info") {
      std::cout << "directional-cli " << DIRECTIONAL_VERSION << '\n';
      std::cout << "native library: " << directional_build_info() << '\n';
      return 0;
    }

    if (command == "cross-field") {
      return run_cross_field(argc, argv);
    }

    std::cerr << "directional-cli: unknown command: " << command << '\n';
    std::cerr << "Run `directional --help` for usage.\n";
    return 2;
  } catch (const std::exception &error) {
    std::cerr << "directional-cli: error: " << error.what() << '\n';
    return 1;
  }
}
