#include "MeshIO.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace directional::cli {
namespace {

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

} // namespace

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

} // namespace directional::cli
