#include "FieldConversion.h"
#include "ProgressDisplay.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <Eigen/Geometry>

namespace directional::cli {
namespace {

std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
  return value;
}

void ensure_parent(const std::filesystem::path &path) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
}

Eigen::RowVector3d normalized(const Eigen::RowVector3d &v) {
  const double norm = v.norm();
  if (norm < 1e-12) {
    throw std::runtime_error("Cannot normalize a near-zero field vector.");
  }
  return v / norm;
}

Eigen::MatrixXd face_normals(const MeshData &mesh, Eigen::Index expectedFaces) {
  if (mesh.faces.rows() != expectedFaces) {
    throw std::runtime_error("Mesh face count does not match field row count.");
  }
  Eigen::MatrixXd normals(expectedFaces, 3);
  for (Eigen::Index i = 0; i < expectedFaces; ++i) {
    const Eigen::RowVector3d a = mesh.vertices.row(mesh.faces(i, 0));
    const Eigen::RowVector3d b = mesh.vertices.row(mesh.faces(i, 1));
    const Eigen::RowVector3d c = mesh.vertices.row(mesh.faces(i, 2));
    const Eigen::RowVector3d ab = b - a;
    const Eigen::RowVector3d ac = c - a;
    normals.row(i) = normalized(ab.cross(ac));
  }
  return normals;
}

Eigen::MatrixXd make_raw(const Eigen::MatrixXd &primary,
                         const Eigen::MatrixXd &secondary, int degree) {
  if (degree != 2 && degree != 4) {
    throw std::runtime_error("Only degree 2 or 4 rawfield output is supported.");
  }
  Eigen::MatrixXd raw(primary.rows(), degree * 3);
  raw.block(0, 0, primary.rows(), 3) = primary;
  raw.block(0, 3, primary.rows(), 3) = secondary;
  if (degree == 4) {
    raw.block(0, 6, primary.rows(), 3) = -primary;
    raw.block(0, 9, primary.rows(), 3) = -secondary;
  }
  return raw;
}

FieldData read_crossfield(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) throw std::runtime_error("Failed to open field input: " + path.string());
  std::vector<Eigen::Matrix<double, 1, 6>> rows;
  std::string line;
  bool skippedHeader = false;
  while (std::getline(stream, line)) {
    const auto comment = line.find('#');
    if (comment != std::string::npos) line.erase(comment);
    std::replace(line.begin(), line.end(), ',', ' ');
    std::istringstream input(line);
    std::vector<double> values;
    double value = 0.0;
    while (input >> value) values.push_back(value);
    if (values.empty()) {
      if (!input.eof() && rows.empty() && !skippedHeader) skippedHeader = true;
      continue;
    }
    std::size_t offset = 0;
    if (values.size() >= 7 && std::llround(values[0]) == static_cast<long long>(rows.size())) {
      offset = 1;
    }
    if (values.size() - offset < 6) {
      throw std::runtime_error("Crossfield rows require at least six numeric values.");
    }
    Eigen::Matrix<double, 1, 6> row;
    for (int i = 0; i < 6; ++i) row(i) = values[offset + i];
    rows.push_back(row);
  }
  if (rows.empty()) throw std::runtime_error("Crossfield file contains no rows.");
  FieldData result;
  result.degree = 4;
  result.primary.resize(rows.size(), 3);
  result.secondary.resize(rows.size(), 3);
  for (Eigen::Index i = 0; i < static_cast<Eigen::Index>(rows.size()); ++i) {
    result.primary.row(i) = normalized(rows[i].segment<3>(0));
    result.secondary.row(i) = normalized(rows[i].segment<3>(3));
  }
  result.raw = make_raw(result.primary, result.secondary, 4);
  return result;
}

FieldData read_rawfield(const std::filesystem::path &path,
                        const MeshData *mesh) {
  std::ifstream stream(path);
  if (!stream) throw std::runtime_error("Failed to open rawfield input: " + path.string());
  Eigen::Index count = 0;
  FieldData result;
  if (!(stream >> result.degree >> count) || result.degree <= 0 || count < 0) {
    throw std::runtime_error("Invalid rawfield header.");
  }
  result.raw.resize(count, result.degree * 3);
  for (Eigen::Index r = 0; r < count; ++r) {
    for (Eigen::Index c = 0; c < result.raw.cols(); ++c) {
      if (!(stream >> result.raw(r, c))) throw std::runtime_error("Invalid rawfield data.");
    }
  }
  result.primary = result.raw.leftCols(3);
  for (Eigen::Index i = 0; i < count; ++i) result.primary.row(i) = normalized(result.primary.row(i));
  if (result.degree >= 2) {
    result.secondary = result.raw.middleCols(3, 3);
    for (Eigen::Index i = 0; i < count; ++i) result.secondary.row(i) = normalized(result.secondary.row(i));
  } else {
    if (!mesh) throw std::runtime_error("Degree-1 rawfield conversion requires --mesh.");
    const Eigen::MatrixXd normals = face_normals(*mesh, count);
    result.secondary.resize(count, 3);
    for (Eigen::Index i = 0; i < count; ++i) {
      Eigen::RowVector3d a = result.primary.row(i);
      const Eigen::RowVector3d n = normals.row(i);
      a = normalized(a - a.dot(n) * n);
      result.primary.row(i) = a;
      result.secondary.row(i) = normalized(n.cross(a));
    }
  }
  return result;
}

FieldData read_rosy(const std::filesystem::path &path,
                    const MeshData *mesh) {
  std::ifstream stream(path);
  if (!stream) throw std::runtime_error("Failed to open rosy input: " + path.string());
  Eigen::Index count = 0;
  FieldData result;
  if (!(stream >> count >> result.degree) || count < 0 || result.degree <= 0) {
    throw std::runtime_error("Invalid .rosy header.");
  }
  if (!mesh) throw std::runtime_error("Rosy conversion requires --mesh to reconstruct beta.");
  std::cerr << "WARNING: lossy conversion: rosy reconstructs beta from mesh normals; "
               "original beta/sign/order are not recoverable.\n";
  const Eigen::MatrixXd normals = face_normals(*mesh, count);
  result.primary.resize(count, 3);
  result.secondary.resize(count, 3);
  for (Eigen::Index i = 0; i < count; ++i) {
    Eigen::RowVector3d a;
    if (!(stream >> a.x() >> a.y() >> a.z())) throw std::runtime_error("Invalid .rosy data.");
    const Eigen::RowVector3d n = normals.row(i);
    a = normalized(normalized(a) - normalized(a).dot(n) * n);
    result.primary.row(i) = a;
    result.secondary.row(i) = normalized(n.cross(a));
  }
  result.raw = make_raw(result.primary, result.secondary, result.degree == 2 ? 2 : 4);
  return result;
}

} // namespace

FieldFormat parse_field_format(const std::string &value) {
  const std::string format = lowercase(value);
  if (format == "crossfield") return FieldFormat::CrossField;
  if (format == "rosy") return FieldFormat::Rosy;
  if (format == "rawfield") return FieldFormat::RawField;
  throw std::runtime_error("Unsupported field format: " + value);
}

FieldFormat infer_field_format(const std::filesystem::path &path,
                               const std::string &requested) {
  const std::string extension = lowercase(path.extension().string());
  if (extension == ".rawfiled") {
    throw std::runtime_error(
        "Unsupported field extension '.rawfiled'; use '.rawfield'.");
  }
  if (requested != "auto") return parse_field_format(requested);
  if (extension == ".rawfield") return FieldFormat::RawField;
  if (extension == ".rosy") return FieldFormat::Rosy;
  if (extension == ".vec" || extension == ".txt") return FieldFormat::CrossField;
  throw std::runtime_error("Cannot infer field format from extension: " + extension);
}

std::filesystem::path infer_field_output_path(const std::filesystem::path &inputPath,
                                              FieldFormat format) {
  auto output = inputPath;
  if (format == FieldFormat::CrossField) output.replace_extension(".vec");
  else if (format == FieldFormat::Rosy) output.replace_extension(".rosy");
  else output.replace_extension(".rawfield");
  return output;
}

FieldData read_field(const std::filesystem::path &path, FieldFormat format,
                     const MeshData *mesh) {
  if (format == FieldFormat::CrossField) return read_crossfield(path);
  if (format == FieldFormat::Rosy) return read_rosy(path, mesh);
  return read_rawfield(path, mesh);
}

void write_field(const std::filesystem::path &path, FieldFormat format,
                 const FieldData &field) {
  ensure_parent(path);
  std::ofstream stream(path);
  if (!stream) throw std::runtime_error("Failed to open field output: " + path.string());
  stream.precision(std::numeric_limits<double>::digits10 + 1);
  if (format == FieldFormat::CrossField) {
    if (field.secondary.rows() != field.primary.rows()) throw std::runtime_error("Crossfield output requires alpha and beta.");
    for (Eigen::Index i = 0; i < field.primary.rows(); ++i) {
      stream << field.primary(i,0) << ' ' << field.primary(i,1) << ' ' << field.primary(i,2) << ' '
             << field.secondary(i,0) << ' ' << field.secondary(i,1) << ' ' << field.secondary(i,2) << '\n';
    }
  } else if (format == FieldFormat::Rosy) {
    stream << field.primary.rows() << '\n' << field.degree << '\n';
    for (Eigen::Index i = 0; i < field.primary.rows(); ++i) {
      const Eigen::RowVector3d a = normalized(field.primary.row(i));
      stream << a.x() << ' ' << a.y() << ' ' << a.z() << '\n';
    }
  } else {
    const int degree = field.degree == 2 ? 2 : 4;
    Eigen::MatrixXd raw = field.raw;
    if (raw.rows() == 0 || raw.cols() != degree * 3) raw = make_raw(field.primary, field.secondary, degree);
    stream << degree << ' ' << raw.rows() << '\n';
    for (Eigen::Index i = 0; i < raw.rows(); ++i) {
      for (Eigen::Index j = 0; j < raw.cols(); ++j) {
        if (j) stream << ' ';
        stream << raw(i,j);
      }
      stream << '\n';
    }
  }
}

int run_convert_field(int argc, char **argv) {
  if (argc < 4) throw std::runtime_error("convert-field requires input and output paths.");
  const std::filesystem::path input = argv[2];
  std::filesystem::path output = argv[3];
  std::string inputFormat = "auto";
  std::string outputFormat = "auto";
  std::optional<std::filesystem::path> meshPath;
  int degree = 4;
  for (int i = 4; i < argc; ++i) {
    const std::string option = argv[i];
    if (option == "--input-format" && ++i < argc) inputFormat = argv[i];
    else if (option == "--output-format" && ++i < argc) outputFormat = argv[i];
    else if (option == "--mesh" && ++i < argc) meshPath = argv[i];
    else if (option == "--degree" && ++i < argc) degree = std::stoi(argv[i]);
    else throw std::runtime_error("Unknown convert-field option: " + option);
  }
  constexpr std::size_t progressTotal = 4;
  ProgressDisplay progress(std::cout);
  progress.update(1, progressTotal, "Inspecting field formats");
  const FieldFormat sourceFormat = infer_field_format(input, inputFormat);
  const FieldFormat targetFormat = infer_field_format(output, outputFormat);
  if (sourceFormat == targetFormat) {
    if (std::filesystem::absolute(input).lexically_normal() ==
        std::filesystem::absolute(output).lexically_normal()) {
      throw std::runtime_error(
          "Input and output paths are identical for same-format conversion.");
    }
    ensure_parent(output);
    progress.update(2, progressTotal, "Copying field data");
    std::filesystem::copy_file(
        input, output, std::filesystem::copy_options::overwrite_existing);
    progress.update(4, progressTotal, "Finalizing field conversion");
    progress.finish();
    std::cout << "Wrote " << output.string() << '\n';
    return 0;
  }
  progress.update(2, progressTotal,
                  meshPath ? "Loading mesh and field data" : "Loading field data");
  std::optional<MeshData> mesh;
  if (meshPath) mesh = load_mesh(*meshPath);
  FieldData field = read_field(input, sourceFormat, mesh ? &*mesh : nullptr);
  if (targetFormat == FieldFormat::RawField && (degree == 2 || degree == 4)) {
    field.degree = degree;
    field.raw = make_raw(field.primary, field.secondary, degree);
  }
  if (sourceFormat == FieldFormat::RawField && targetFormat != FieldFormat::RawField && field.degree > 2) {
    std::cerr << "WARNING: lossy conversion: rawfield keeps only the first two branches.\n";
  }
  if (targetFormat == FieldFormat::Rosy && field.secondary.rows() > 0) {
    std::cerr << "WARNING: lossy conversion: output .rosy keeps only alpha.\n";
  }
  progress.update(3, progressTotal, "Writing converted field");
  write_field(output, targetFormat, field);
  progress.update(4, progressTotal, "Finalizing field conversion");
  progress.finish();
  std::cout << "Wrote " << output.string() << '\n';
  return 0;
}

} // namespace directional::cli
