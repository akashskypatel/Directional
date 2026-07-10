#include "FileDialog.h"
#include "FilePicker.h"
#include "GuiBackend.h"
#include "CompareFieldsCommand.h"
#include "SessionLog.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <future>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include <Eigen/Geometry>
#include <glm/gtc/matrix_inverse.hpp>
#include <imgui.h>

#include <directional/fields/CompareCrossFields.h>

#include <polyscope/point_cloud.h>
#include <polyscope/polyscope.h>
#include <polyscope/surface_mesh.h>
#include <polyscope/view.h>

namespace {

constexpr const char *kInputMeshName = "Input mesh";
constexpr const char *kFieldGlyphName = "Cross field";
constexpr const char *kQuadMeshName = "Quad remesh";
constexpr const char *kDeviationHeatmapName = "Cross-field deviation (degrees)";

enum class FilePickerTarget { None, Mesh, Field, CompareField };

struct ProgressState {
  std::atomic<std::size_t> current{0};
  std::atomic<std::size_t> total{1};
  std::mutex mutex;
  std::string task = "Idle";

  void update(const std::size_t currentValue, const std::size_t totalValue,
              const std::string_view taskValue) {
    current.store(currentValue, std::memory_order_relaxed);
    total.store(std::max<std::size_t>(totalValue, 1),
                std::memory_order_relaxed);
    std::lock_guard lock(mutex);
    task.assign(taskValue);
  }

  std::string task_copy() {
    std::lock_guard lock(mutex);
    return task;
  }
};

struct TaskResult {
  bool hasMesh = false;
  bool hasField = false;
  bool hasQuadMesh = false;
  bool hasComparison = false;
  directional::gui::MeshData mesh;
  directional::gui::FieldData field;
  directional::gui::QuadMeshData quadMesh;
  directional::gui::FieldComparisonData comparison;
  int simplificationSourceFaceCount = 0;
  int simplificationRootCount = 0;
  int simplificationCollapsedEdges = 0;
  std::string fieldLabel;
  std::string message;
  std::string error;
};

std::filesystem::path default_sibling_path(const std::filesystem::path &input,
                                           const std::string &suffix,
                                           const std::string &extension) {
  return input.parent_path() / (input.stem().string() + suffix + extension);
}

void copy_path_to_buffer(const std::filesystem::path &path,
                         std::array<char, 1024> &buffer) {
  const std::string value = path.string();
  const std::size_t count = std::min(value.size(), buffer.size() - 1);
  std::memcpy(buffer.data(), value.data(), count);
  buffer[count] = '\0';
}

std::filesystem::path path_from_buffer(const std::array<char, 1024> &buffer,
                                       const char *label) {
  const std::filesystem::path path(buffer.data());
  if (path.empty()) {
    throw std::runtime_error(std::string(label) + " path is empty.");
  }
  return path;
}

template <typename DrawFunction>
void draw_labeled_full_width_control(const char *label,
                                     DrawFunction &&drawFunction) {
  ImGui::TextUnformatted(label);
  ImGui::SetNextItemWidth(-1.0F);
  std::forward<DrawFunction>(drawFunction)();
}

struct FaceGeometry {
  Eigen::MatrixXd centers;
  Eigen::MatrixXd normals;
};

FaceGeometry face_geometry(const directional::gui::MeshData &mesh) {
  FaceGeometry geometry{Eigen::MatrixXd(mesh.faces.rows(), 3),
                        Eigen::MatrixXd::Zero(mesh.faces.rows(), 3)};
  for (Eigen::Index face = 0; face < mesh.faces.rows(); ++face) {
    const Eigen::Vector3d first =
        mesh.vertices.row(mesh.faces(face, 0)).transpose();
    const Eigen::Vector3d second =
        mesh.vertices.row(mesh.faces(face, 1)).transpose();
    const Eigen::Vector3d third =
        mesh.vertices.row(mesh.faces(face, 2)).transpose();
    geometry.centers.row(face) = ((first + second + third) / 3.0).transpose();

    Eigen::Vector3d normal = (second - first).cross(third - first);
    const double normalLength = normal.norm();
    if (normalLength > std::numeric_limits<double>::epsilon()) {
      geometry.normals.row(face) = (normal / normalLength).transpose();
    }
  }
  return geometry;
}

bool matrix_nearly_equal(const glm::mat4 &first, const glm::mat4 &second) {
  constexpr float tolerance = 1e-6F;
  for (int column = 0; column < 4; ++column) {
    for (int row = 0; row < 4; ++row) {
      if (std::abs(first[column][row] - second[column][row]) > tolerance) {
        return false;
      }
    }
  }
  return true;
}

double average_edge_length(const directional::gui::MeshData &mesh) {
  double lengthSum = 0.0;
  std::size_t edgeCount = 0;
  for (Eigen::Index face = 0; face < mesh.faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int first = mesh.faces(face, corner);
      const int second = mesh.faces(face, (corner + 1) % 3);
      lengthSum +=
          (mesh.vertices.row(first) - mesh.vertices.row(second)).norm();
      ++edgeCount;
    }
  }
  return edgeCount == 0 ? 1.0 : lengthSum / static_cast<double>(edgeCount);
}

class DirectionalUi {
public:
  DirectionalUi(const std::optional<std::filesystem::path> &startupMesh,
                directional::gui::SessionLog &sessionLog)
      : sessionLog_(sessionLog) {
    meshPath_.fill('\0');
    fieldInputPath_.fill('\0');
    fieldOutputPath_.fill('\0');
    remeshOutputPath_.fill('\0');
    if (startupMesh.has_value()) {
      copy_path_to_buffer(*startupMesh, meshPath_);
    }
  }

  void initialize() {
    polyscope::options::autocenterStructures = true;
    polyscope::options::allowHeadlessBackends = true;
    polyscope::options::groundPlaneMode = polyscope::GroundPlaneMode::None;
    polyscope::init();
    instance_ = this;
    polyscope::state::userCallback = &DirectionalUi::callback_trampoline;

    if (meshPath_[0] != '\0') {
      guarded_action([this] { load_mesh(); });
    }
  }

  void show() { polyscope::show(); }

private:
  static inline DirectionalUi *instance_ = nullptr;

  directional::gui::SessionLog &sessionLog_;

  std::optional<directional::gui::MeshData> mesh_;
  std::optional<directional::gui::FieldData> field_;
  std::optional<directional::gui::FieldData> referenceField_;
  std::optional<directional::gui::FieldComparisonData> fieldComparison_;
  std::optional<directional::gui::QuadMeshData> quadMesh_;

  std::array<char, 1024> meshPath_{};
  std::array<char, 1024> fieldInputPath_{};
  std::array<char, 1024> compareFieldInputPath_{};
  std::array<char, 1024> fieldOutputPath_{};
  std::array<char, 1024> remeshOutputPath_{};

  directional::gui::FilePicker filePicker_;
  FilePickerTarget filePickerTarget_ = FilePickerTarget::None;

  int fieldMethod_ = 1;
  int fieldInputFormat_ = 0;
  int compareFieldInputFormat_ = 0;
  int fieldOutputFormat_ = 0;
  int fieldSampleStride_ = 1;
  float glyphLengthRatio_ = 0.35F;
  float glyphSurfaceOffsetRatio_ = 0.04F;
  Eigen::MatrixXd fieldGlyphCenters_;
  Eigen::MatrixXd fieldGlyphNormals_;
  double fieldGlyphSurfaceOffset_ = 0.0;
  std::optional<Eigen::Vector3d> lastFieldGlyphCameraPosition_;
  float comparisonHeatmapMaxDegrees_ = 45.0F;
  double comparisonHighErrorThresholdDegrees_ = 20.0;
  bool comparisonRemoveGlobalPhase_ = true;
  bool comparisonShapeOperatorAlignment_ = false;

  directional::gui::MeshSimplificationOptions simplificationOptions_;
  directional::gui::FieldOptions fieldOptions_;
  directional::gui::RemeshOptions remeshOptions_;

  std::future<TaskResult> task_;
  std::shared_ptr<ProgressState> progress_ = std::make_shared<ProgressState>();
  std::string status_ = "Load an OBJ or OFF triangle mesh.";
  std::string error_;
  std::string fieldLabel_;

  static void callback_trampoline() {
    if (instance_ != nullptr) {
      instance_->draw_ui();
    }
  }

  bool busy() const {
    return task_.valid() &&
           task_.wait_for(std::chrono::seconds(0)) != std::future_status::ready;
  }

  void set_status(std::string message) {
    status_ = std::move(message);
    error_.clear();
  }

  void set_error(std::string message) { error_ = std::move(message); }

  void enable_verbose_session_log_if_needed(const bool verbose) {
    if (!verbose) {
      return;
    }

    const bool wasEnabled = sessionLog_.is_enabled();
    sessionLog_.enable();
    if (!wasEnabled) {
      std::cout << "[directional-ui] verbose session log: "
                << sessionLog_.path().string() << '\n';
    }
  }

  void clear_field_and_remesh() {
    field_.reset();
    referenceField_.reset();
    fieldComparison_.reset();
    quadMesh_.reset();
    fieldLabel_.clear();
    fieldGlyphCenters_.resize(0, 3);
    fieldGlyphNormals_.resize(0, 3);
    fieldGlyphSurfaceOffset_ = 0.0;
    lastFieldGlyphCameraPosition_.reset();
    if (polyscope::hasPointCloud(kFieldGlyphName)) {
      polyscope::removePointCloud(kFieldGlyphName);
    }
    if (polyscope::hasSurfaceMesh(kQuadMeshName)) {
      polyscope::removeSurfaceMesh(kQuadMeshName);
    }
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::getSurfaceMesh(kInputMeshName)
          ->removeQuantity(kDeviationHeatmapName, false);
    }
  }

  void replace_input_mesh(directional::gui::MeshData loaded,
                          const bool resetCamera) {
    mesh_ = std::move(loaded);
    clear_field_and_remesh();
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::removeSurfaceMesh(kInputMeshName);
    }
    auto *inputMesh = polyscope::registerSurfaceMesh(
        kInputMeshName, mesh_->vertices, mesh_->faces);
    if (inputMesh == nullptr) {
      throw std::runtime_error("Failed to register the input mesh viewer.");
    }

    // Polyscope persists structure state by name. The previous input mesh is
    // disabled when a quad remesh is shown, so a replacement registered with
    // the same name can inherit that disabled state. Reset the inherited
    // display state before framing the newly loaded mesh.
    inputMesh->resetTransform();
    inputMesh->centerBoundingBox();
    inputMesh->setSurfaceColor({0.72F, 0.75F, 0.80F});
    inputMesh->setTransparency(1.0F);
    inputMesh->setEnabled(true);

    fieldSampleStride_ =
        std::max(1, static_cast<int>(mesh_->faces.rows() / 5000));
    if (resetCamera) {
      polyscope::view::resetCameraToHomeView();
    }
  }

  void load_mesh() {
    const std::filesystem::path path =
        path_from_buffer(meshPath_, "Input mesh");
    directional::gui::MeshData loaded = directional::gui::load_mesh(path);
    if (loaded.faces.cols() != 3) {
      throw std::runtime_error("The input mesh must be triangular.");
    }

    const Eigen::Index vertexCount = loaded.vertices.rows();
    const Eigen::Index faceCount = loaded.faces.rows();
    replace_input_mesh(std::move(loaded), true);
    copy_path_to_buffer(default_sibling_path(path, "_field", ".rawfield"),
                        fieldOutputPath_);
    copy_path_to_buffer(default_sibling_path(path, "_quad", ".obj"),
                        remeshOutputPath_);
    set_status("Loaded " + std::to_string(vertexCount) +
               " vertices and " + std::to_string(faceCount) +
               " triangles.");
  }

  void update_field_glyph_positions(const bool force = false) {
    if (fieldGlyphCenters_.rows() == 0 ||
        !polyscope::hasPointCloud(kFieldGlyphName) ||
        !polyscope::hasSurfaceMesh(kInputMeshName)) {
      return;
    }

    auto *cloud = polyscope::getPointCloud(kFieldGlyphName);
    auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
    const glm::mat4 meshTransform = inputMesh->getTransform();

    // The point cloud is registered after the mesh and would otherwise receive
    // its own auto-centering transform. Reuse the mesh transform so that face
    // centers and vectors remain in exactly the same coordinate frame.
    const bool transformChanged =
        !matrix_nearly_equal(cloud->getTransform(), meshTransform);
    if (transformChanged) {
      cloud->setTransform(meshTransform);
    }

    const glm::vec3 cameraWorld = polyscope::view::getCameraWorldPosition();
    glm::vec4 cameraObject =
        glm::inverse(meshTransform) * glm::vec4(cameraWorld, 1.0F);
    if (std::abs(cameraObject.w) > std::numeric_limits<float>::epsilon()) {
      cameraObject /= cameraObject.w;
    }
    const Eigen::Vector3d camera(cameraObject.x, cameraObject.y,
                                 cameraObject.z);

    const double positionTolerance =
        std::max(fieldGlyphSurfaceOffset_ * 1e-4, 1e-12);
    if (!force && !transformChanged &&
        lastFieldGlyphCameraPosition_.has_value() &&
        (camera - *lastFieldGlyphCameraPosition_).squaredNorm() <=
            positionTolerance * positionTolerance) {
      return;
    }

    Eigen::MatrixXd displayCenters = fieldGlyphCenters_;
    for (Eigen::Index sample = 0; sample < displayCenters.rows(); ++sample) {
      const Eigen::Vector3d normal =
          fieldGlyphNormals_.row(sample).transpose();
      if (normal.squaredNorm() == 0.0) {
        continue;
      }

      const Eigen::Vector3d center =
          fieldGlyphCenters_.row(sample).transpose();
      const double side = normal.dot(camera - center) >= 0.0 ? 1.0 : -1.0;
      displayCenters.row(sample) =
          (center + side * fieldGlyphSurfaceOffset_ * normal).transpose();
    }

    cloud->updatePointPositions(displayCenters);
    lastFieldGlyphCameraPosition_ = camera;
  }

  void visualize_field() {
    if (!mesh_.has_value() || !field_.has_value()) {
      return;
    }
    directional::gui::validate_field(*field_, mesh_->faces.rows());

    if (polyscope::hasPointCloud(kFieldGlyphName)) {
      polyscope::removePointCloud(kFieldGlyphName);
    }

    const int stride = std::max(fieldSampleStride_, 1);
    const Eigen::Index sampleCount =
        (mesh_->faces.rows() + stride - 1) / stride;
    const FaceGeometry geometry = face_geometry(*mesh_);
    Eigen::MatrixXd sampledCenters(sampleCount, 3);
    Eigen::MatrixXd sampledNormals(sampleCount, 3);
    std::array<Eigen::MatrixXd, 4> sampledVectors{
        Eigen::MatrixXd(sampleCount, 3), Eigen::MatrixXd(sampleCount, 3),
        Eigen::MatrixXd(sampleCount, 3), Eigen::MatrixXd(sampleCount, 3)};

    Eigen::Index sample = 0;
    for (Eigen::Index face = 0; face < mesh_->faces.rows(); face += stride) {
      sampledCenters.row(sample) = geometry.centers.row(face);
      sampledNormals.row(sample) = geometry.normals.row(face);
      for (int branch = 0; branch < 4; ++branch) {
        sampledVectors[branch].row(sample) =
            field_->raw.block(face, 3 * branch, 1, 3);
      }
      ++sample;
    }

    const double averageEdgeLength = average_edge_length(*mesh_);
    const double scale =
        static_cast<double>(glyphLengthRatio_) * averageEdgeLength;
    const double vectorRadius = std::max(scale * 0.025, 1e-12);
    fieldGlyphSurfaceOffset_ =
        static_cast<double>(glyphSurfaceOffsetRatio_) * averageEdgeLength;
    fieldGlyphCenters_ = sampledCenters;
    fieldGlyphNormals_ = sampledNormals;
    lastFieldGlyphCameraPosition_.reset();

    auto *cloud =
        polyscope::registerPointCloud(kFieldGlyphName, sampledCenters);
    cloud->setPointRadius(0.0);
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      cloud->setTransform(
          polyscope::getSurfaceMesh(kInputMeshName)->getTransform());
    }
    for (int branch = 0; branch < 4; ++branch) {
      cloud
          ->addVectorQuantity("Branch " + std::to_string(branch),
                              sampledVectors[branch] * scale,
                              polyscope::VectorType::AMBIENT)
          ->setVectorRadius(vectorRadius, false)
          ->setEnabled(true);
    }

    update_field_glyph_positions(true);
  }

  void visualize_quad_mesh() {
    if (!quadMesh_.has_value()) {
      return;
    }
    if (polyscope::hasSurfaceMesh(kQuadMeshName)) {
      polyscope::removeSurfaceMesh(kQuadMeshName);
    }
    auto *quad = polyscope::registerSurfaceMesh(
        kQuadMeshName, quadMesh_->vertices, quadMesh_->faces);
    quad->setSurfaceColor({0.80F, 0.64F, 0.30F});
    quad->setEdgeWidth(1.0);
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::getSurfaceMesh(kInputMeshName)->setEnabled(false);
    }
  }

  directional::gui::ProgressCallback progress_callback() const {
    const auto progress = progress_;
    return [progress](const std::size_t current, const std::size_t total,
                      const std::string_view task) {
      progress->update(current, total, task);
    };
  }

  directional::gui::FieldOptions current_field_options() const {
    directional::gui::FieldOptions options = fieldOptions_;
    options.method = fieldMethod_ == 0
                         ? directional::gui::FieldMethod::Smooth
                         : directional::gui::FieldMethod::RegularizedCurvature;
    return options;
  }

  std::string selected_field_method_label() const {
    return fieldMethod_ == 0 ? "smooth power field"
                             : "regularized-curvature field";
  }

  void launch_simplify_mesh() {
    require_mesh();
    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::MeshSimplificationOptions options =
        simplificationOptions_;
    enable_verbose_session_log_if_needed(options.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Starting TriFlow simplification");

    task_ = std::async(std::launch::async, [mesh, options, progress]() {
      TaskResult result;
      try {
        directional::gui::MeshSimplificationData simplified =
            directional::gui::simplify_mesh(
                mesh, options,
                [progress](const std::size_t current, const std::size_t total,
                           const std::string_view task) {
                  progress->update(current, total, task);
                });
        result.mesh = std::move(simplified.mesh);
        result.hasMesh = true;
        result.simplificationSourceFaceCount =
            static_cast<int>(mesh.faces.rows());
        result.simplificationRootCount = simplified.rootCount;
        result.simplificationCollapsedEdges = simplified.collapsedEdges;
        result.message =
            "Simplified input mesh from " +
            std::to_string(result.simplificationSourceFaceCount) +
            " to " + std::to_string(result.mesh.faces.rows()) +
            " triangles using " +
            std::to_string(result.simplificationCollapsedEdges) +
            " edge collapses.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "TriFlow simplification finished");
      return result;
    });
    set_status("Simplifying input mesh with TriFlow constrained QEM...");
  }

  void launch_calculate_field() {
    require_mesh();
    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldOptions options = current_field_options();
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field calculation");

    task_ = std::async(std::launch::async, [mesh, options, progress]() {
      TaskResult result;
      try {
        result.field = directional::gui::calculate_field(
            mesh, options,
            [progress](const std::size_t current, const std::size_t total,
                       const std::string_view task) {
              progress->update(current, total, task);
            });
        result.hasField = true;
        result.fieldLabel =
            options.method == directional::gui::FieldMethod::Smooth
                ? "Calculated smooth power field"
                : "Calculated regularized-curvature field";
        result.message = result.fieldLabel + ".";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field calculation finished");
      return result;
    });
    set_status("Calculating " + selected_field_method_label() + "...");
  }

  void launch_auto_remesh() {
    require_mesh();
    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldOptions fieldOptions = current_field_options();
    const directional::gui::RemeshOptions remeshOptions = remeshOptions_;
    enable_verbose_session_log_if_needed(remeshOptions.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Starting automatic remesh");

    task_ = std::async(std::launch::async, [mesh, fieldOptions, remeshOptions,
                                            progress]() {
      TaskResult result;
      try {
        directional::gui::AutoRemeshResult remesh =
            directional::gui::auto_remesh(
                mesh, fieldOptions, remeshOptions,
                [progress](const std::size_t current, const std::size_t total,
                           const std::string_view task) {
                  progress->update(current, total, task);
                });
        result.field = std::move(remesh.field);
        result.quadMesh = std::move(remesh.quadMesh);
        result.hasField = true;
        result.hasQuadMesh = true;
        result.fieldLabel =
            fieldOptions.method == directional::gui::FieldMethod::Smooth
                ? "Auto-calculated smooth power field"
                : "Auto-calculated regularized-curvature field";
        result.message = result.fieldLabel + " and generated a quad mesh.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Automatic remesh finished");
      return result;
    });
    set_status("Auto-calculating field and remeshing...");
  }

  void load_field() {
    require_mesh();
    const std::filesystem::path path =
        path_from_buffer(fieldInputPath_, "Input field");
    field_ = directional::gui::load_field(
        path, selected_field_format(fieldInputFormat_), *mesh_);
    fieldComparison_.reset();
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::getSurfaceMesh(kInputMeshName)
          ->removeQuantity(kDeviationHeatmapName, false);
    }
    fieldLabel_ = "Loaded field: " + path.filename().string();
    visualize_field();
    set_status(fieldLabel_ + ".");
  }

  void load_compare_field() {
    require_mesh();
    const std::filesystem::path path =
        path_from_buffer(compareFieldInputPath_, "Reference field");
    referenceField_ = directional::gui::load_field(
        path, selected_field_format(compareFieldInputFormat_), *mesh_);
    set_status("Loaded comparison reference field: " + path.filename().string() +
               ".");
  }

  void launch_compare_fields() {
    require_mesh();
    if (!field_.has_value()) {
      throw std::runtime_error("Calculate or load a field before comparing it.");
    }
    if (!referenceField_.has_value()) {
      throw std::runtime_error("Load a reference field before comparing.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *field_;
    const directional::gui::FieldData reference = *referenceField_;
    const double highErrorThreshold = comparisonHighErrorThresholdDegrees_;
    const bool removeGlobalPhase = comparisonRemoveGlobalPhase_;
    const bool shapeOperatorAlignment = comparisonShapeOperatorAlignment_;
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field comparison");

    task_ = std::async(std::launch::async, [mesh, field, reference,
                                            highErrorThreshold,
                                            removeGlobalPhase,
                                            shapeOperatorAlignment, progress]() {
      TaskResult result;
      try {
        result.comparison = directional::gui::compare_fields(
            mesh, field, reference, highErrorThreshold, removeGlobalPhase,
            shapeOperatorAlignment);
        result.hasComparison = true;
        result.message = "Compared current field to reference field.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field comparison finished");
      return result;
    });
    set_status("Comparing current field to reference field...");
  }

  void launch_remesh_loaded_field() {
    require_mesh();
    if (!field_.has_value()) {
      throw std::runtime_error("Load an input field before remeshing with it.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *field_;
    const directional::gui::RemeshOptions options = remeshOptions_;
    enable_verbose_session_log_if_needed(options.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field-guided remesh");

    task_ = std::async(std::launch::async, [mesh, field, options, progress]() {
      TaskResult result;
      try {
        result.quadMesh = directional::gui::remesh_with_field(
            mesh, field, options,
            [progress](const std::size_t current, const std::size_t total,
                       const std::string_view task) {
              progress->update(current, total, task);
            });
        result.hasQuadMesh = true;
        result.message = "Generated a quad mesh from the loaded field.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field-guided remesh finished");
      return result;
    });
    set_status("Remeshing with the loaded field...");
  }

  void process_completed_task() {
    if (!task_.valid() ||
        task_.wait_for(std::chrono::seconds(0)) != std::future_status::ready) {
      return;
    }

    TaskResult result = task_.get();
    if (!result.error.empty()) {
      set_error(result.error);
      return;
    }
    if (result.hasMesh) {
      replace_input_mesh(std::move(result.mesh), false);
    }
    if (result.hasField) {
      field_ = std::move(result.field);
      fieldComparison_.reset();
      if (polyscope::hasSurfaceMesh(kInputMeshName)) {
        polyscope::getSurfaceMesh(kInputMeshName)
            ->removeQuantity(kDeviationHeatmapName, false);
      }
      fieldLabel_ = std::move(result.fieldLabel);
      visualize_field();
    }
    if (result.hasQuadMesh) {
      quadMesh_ = std::move(result.quadMesh);
      visualize_quad_mesh();
    }
    if (result.hasComparison) {
      fieldComparison_ = std::move(result.comparison);
      directional::gui::show_field_deviation_heatmap(
          kInputMeshName, *fieldComparison_, comparisonHeatmapMaxDegrees_);
    }
    set_status(std::move(result.message));
  }

  void save_field() {
    if (!field_.has_value()) {
      throw std::runtime_error(
          "There is no calculated or loaded field to save.");
    }
    const std::filesystem::path path =
        path_from_buffer(fieldOutputPath_, "Field output");
    directional::gui::save_field(
        path, selected_field_format(fieldOutputFormat_), *field_);
    set_status("Wrote field to " + path.string() + ".");
  }

void save_quad_mesh() {
  const std::filesystem::path path =
      path_from_buffer(remeshOutputPath_, "Mesh output");

  if (quadMesh_.has_value()) {
    directional::gui::save_quad_mesh(path, *quadMesh_);
    set_status("Wrote quad mesh to " + path.string() + ".");
    return;
  }

  if (mesh_.has_value()) {
    directional::gui::save_mesh(path, *mesh_);
    set_status("Wrote mesh to " + path.string() + ".");
    return;
  }

  throw std::runtime_error("There is no mesh to save.");
}

  void require_mesh() const {
    if (!mesh_.has_value()) {
      throw std::runtime_error("Load an input mesh first.");
    }
  }

  static directional::gui::FieldFormat selected_field_format(const int index) {
    switch (index) {
    case 1:
      return directional::gui::FieldFormat::RawField;
    case 2:
      return directional::gui::FieldFormat::CrossField;
    case 3:
      return directional::gui::FieldFormat::Rosy;
    default:
      return directional::gui::FieldFormat::Auto;
    }
  }

  template <typename Function> void guarded_action(Function &&function) {
    try {
      function();
    } catch (const std::exception &error) {
      set_error(error.what());
    }
  }

  void apply_selected_file(const FilePickerTarget target,
                           const std::filesystem::path &path) {
    if (target == FilePickerTarget::Mesh) {
      copy_path_to_buffer(path, meshPath_);
      set_status("Selected input mesh: " + path.string() + ".");
    } else if (target == FilePickerTarget::Field) {
      copy_path_to_buffer(path, fieldInputPath_);
      set_status("Selected input field: " + path.string() + ".");
    } else if (target == FilePickerTarget::CompareField) {
      copy_path_to_buffer(path, compareFieldInputPath_);
      set_status("Selected comparison reference field: " + path.string() + ".");
    }
  }

  void open_fallback_picker(const FilePickerTarget target,
                            const std::string &title,
                            const std::filesystem::path &initialPath,
                            std::vector<std::string> extensions,
                            const std::string &nativeError) {
    filePickerTarget_ = target;
    filePicker_.open(title, initialPath, std::move(extensions));
    status_ = nativeError.empty()
                  ? "Using the built-in file picker."
                  : nativeError + " Using the built-in file picker instead.";
    error_.clear();
  }

  void open_mesh_picker() {
    const std::filesystem::path initialPath(meshPath_.data());
    const directional::gui::FileDialogResult result =
        directional::gui::open_native_file_dialog(
            {"Select input mesh",
             initialPath,
             {{"Mesh files", {"*.obj", "*.off"}}}});

    if (result.selected()) {
      apply_selected_file(FilePickerTarget::Mesh, result.path);
    } else if (result.status != directional::gui::FileDialogStatus::Cancelled) {
      open_fallback_picker(FilePickerTarget::Mesh, "Select input mesh",
                           initialPath, {".obj", ".off"}, result.message);
    }
  }

  void open_field_picker() {
    const std::filesystem::path initialPath(fieldInputPath_.data());
    const directional::gui::FileDialogResult result =
        directional::gui::open_native_file_dialog(
            {"Select input field",
             initialPath,
             {{"Directional field files",
               {"*.rawfield", "*.rosy", "*.vec", "*.txt"}}}});

    if (result.selected()) {
      apply_selected_file(FilePickerTarget::Field, result.path);
    } else if (result.status != directional::gui::FileDialogStatus::Cancelled) {
      open_fallback_picker(FilePickerTarget::Field, "Select input field",
                           initialPath, {".rawfield", ".rosy", ".vec", ".txt"},
                           result.message);
    }
  }

  void open_compare_field_picker() {
    const std::filesystem::path initialPath(compareFieldInputPath_.data());
    const directional::gui::FileDialogResult result =
        directional::gui::open_native_file_dialog(
            {"Select comparison reference field",
             initialPath,
             {{"Directional field files",
               {"*.rawfield", "*.rosy", "*.vec", "*.txt"}}}});

    if (result.selected()) {
      apply_selected_file(FilePickerTarget::CompareField, result.path);
    } else if (result.status != directional::gui::FileDialogStatus::Cancelled) {
      open_fallback_picker(FilePickerTarget::CompareField,
                           "Select comparison reference field", initialPath,
                           {".rawfield", ".rosy", ".vec", ".txt"},
                           result.message);
    }
  }

  void process_file_picker() {
    const std::optional<std::filesystem::path> selected = filePicker_.draw();
    if (selected.has_value()) {
      apply_selected_file(filePickerTarget_, *selected);
      filePickerTarget_ = FilePickerTarget::None;
    } else if (!filePicker_.active()) {
      filePickerTarget_ = FilePickerTarget::None;
    }
  }

  void draw_ui() {
    process_completed_task();
    update_field_glyph_positions();
    const bool isBusy = busy();

    ImGui::TextUnformatted("Directional Quad Remesher");
    ImGui::Separator();

    if (ImGui::CollapsingHeader("1. Input mesh",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      const float browseWidth = ImGui::CalcTextSize("Browse...").x +
                                2.0F * ImGui::GetStyle().FramePadding.x;
      ImGui::SetNextItemWidth(-browseWidth - ImGui::GetStyle().ItemSpacing.x);
      ImGui::InputText("##mesh_path", meshPath_.data(), meshPath_.size());
      ImGui::SameLine();
      ImGui::BeginDisabled(isBusy);
      if (ImGui::Button("Browse...##mesh")) {
        open_mesh_picker();
      }
      if (ImGui::Button("Load mesh")) {
        guarded_action([this] { load_mesh(); });
      }
      ImGui::EndDisabled();
      if (mesh_.has_value()) {
        ImGui::Text("Vertices: %lld",
                    static_cast<long long>(mesh_->vertices.rows()));
        ImGui::Text("Triangles: %lld",
                    static_cast<long long>(mesh_->faces.rows()));
      }
    }

    if (ImGui::CollapsingHeader("2. TriFlow simplify input",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      draw_labeled_full_width_control(
          "Target triangle count (>= 4; 0 uses target ratio)", [this] {
            ImGui::InputInt("##simplification_target_faces",
                            &simplificationOptions_.targetFaceCount);
          });
      simplificationOptions_.targetFaceCount =
          std::max(0, simplificationOptions_.targetFaceCount);

      draw_labeled_full_width_control(
          "Target face ratio (0 to 1; used when target count is 0)", [this] {
            ImGui::InputDouble("##simplification_target_ratio",
                               &simplificationOptions_.targetFaceRatio, 0.05,
                               0.10, "%.6g");
          });
      simplificationOptions_.targetFaceRatio =
          std::clamp(simplificationOptions_.targetFaceRatio, 1e-6, 1.0);

      ImGui::Checkbox(
          "Preserve boundary (avoid collapsing initial boundary into interior)",
          &simplificationOptions_.preserveBoundary);
      ImGui::Checkbox(
          "Reject face flips (skip collapses that invert adjacent normals)",
          &simplificationOptions_.rejectFaceFlips);
      ImGui::Checkbox(
          "Verbose simplification logging",
          &simplificationOptions_.verbose);
      if (sessionLog_.is_enabled()) {
        ImGui::TextWrapped("Verbose log: %s",
                           sessionLog_.path().string().c_str());
      }

      ImGui::BeginDisabled(isBusy || !mesh_.has_value());
      if (ImGui::Button("Simplify input mesh")) {
        guarded_action([this] { launch_simplify_mesh(); });
      }
      ImGui::EndDisabled();
    }

    if (ImGui::CollapsingHeader("3. Calculate field",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      const char *methods[] = {"Smooth power field", "Regularized curvature"};
      draw_labeled_full_width_control("Field method", [this, &methods] {
        ImGui::Combo("##field_method", &fieldMethod_, methods, 2);
      });

      if (ImGui::TreeNode("Field options")) {
        ImGui::Checkbox("Normalize directions",
                        &fieldOptions_.normalizeDirections);
        if (fieldMethod_ == 1) {
          draw_labeled_full_width_control(
              "Proxy fidelity weight (>= 0; typical: 0.1 to 10)", [this] {
                ImGui::InputDouble("##proxy_fidelity",
                                   &fieldOptions_.proxyFidelityWeight, 0.05,
                                   0.5, "%.6g");
              });

          draw_labeled_full_width_control(
              "Proxy smoothness weight (>= 0; typical: 0.001 to 0.1)", [this] {
                ImGui::InputDouble("##proxy_smoothness",
                                   &fieldOptions_.proxySmoothnessWeight, 0.001,
                                   0.01, "%.6g");
              });

          ImGui::Checkbox(
              "Preserve boundary (align the proxy field to boundary edges)",
              &fieldOptions_.preserveBoundary);

          draw_labeled_full_width_control(
              "Field smoothness weight (>= 0; typical: 0.1 to 10)", [this] {
                ImGui::InputDouble("##field_smoothness",
                                   &fieldOptions_.fieldSmoothnessWeight, 0.1,
                                   1.0, "%.6g");
              });

          draw_labeled_full_width_control(
              "Curvature alignment weight (>= 0; typical: 0.1 to 10)", [this] {
                ImGui::InputDouble("##curvature_alignment",
                                   &fieldOptions_.curvatureAlignmentWeight, 0.1,
                                   1.0, "%.6g");
              });

          draw_labeled_full_width_control(
              "Minimum curvature confidence (0 to 1; typical: 0.001 to 0.1)",
              [this] {
                ImGui::InputDouble("##minimum_confidence",
                                   &fieldOptions_.minimumConfidence, 0.001,
                                   0.01, "%.6g");
              });

          draw_labeled_full_width_control(
              "Confidence exponent (> 0; typical: 1 to 4)", [this] {
                ImGui::InputDouble("##confidence_exponent",
                                   &fieldOptions_.confidenceExponent, 0.1, 1.0,
                                   "%.6g");
              });

          draw_labeled_full_width_control(
              "Curvature smoothing iterations (>= 0; typical: 0 to 20)",
              [this] {
                ImGui::InputInt("##curvature_smoothing_iterations",
                                &fieldOptions_.curvatureSmoothingIterations);
              });
        }
        ImGui::TreePop();
      }

      ImGui::BeginDisabled(isBusy || !mesh_.has_value());
      if (ImGui::Button("Calculate field")) {
        guarded_action([this] { launch_calculate_field(); });
      }
      ImGui::SameLine();
      if (ImGui::Button("Auto-calculate field and remesh")) {
        guarded_action([this] { launch_auto_remesh(); });
      }
      ImGui::EndDisabled();

      draw_labeled_full_width_control(
          "Field display stride (>= 1; show one glyph every N faces)", [this] {
            ImGui::InputInt("##field_display_stride", &fieldSampleStride_);
          });
      fieldSampleStride_ = std::max(fieldSampleStride_, 1);

      draw_labeled_full_width_control(
          "Glyph length (0.05 to 1.0 x average edge length)", [this] {
            ImGui::SliderFloat("##glyph_length", &glyphLengthRatio_, 0.05F,
                               1.0F, "%.2f x average edge");
          });
      draw_labeled_full_width_control(
          "Glyph surface offset (0 to 0.2 x average edge length)", [this] {
            ImGui::SliderFloat("##glyph_surface_offset",
                               &glyphSurfaceOffsetRatio_, 0.0F, 0.2F,
                               "%.3f x average edge");
          });
      ImGui::BeginDisabled(isBusy || !field_.has_value());
      if (ImGui::Button("Refresh field display")) {
        guarded_action([this] { visualize_field(); });
      }
      ImGui::EndDisabled();
    }

    if (ImGui::CollapsingHeader("4. Remesh using input field",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      const float browseWidth = ImGui::CalcTextSize("Browse...").x +
                                2.0F * ImGui::GetStyle().FramePadding.x;
      ImGui::SetNextItemWidth(-browseWidth - ImGui::GetStyle().ItemSpacing.x);
      ImGui::InputText("##field_input_path", fieldInputPath_.data(),
                       fieldInputPath_.size());
      ImGui::SameLine();
      ImGui::BeginDisabled(isBusy);
      if (ImGui::Button("Browse...##field")) {
        open_field_picker();
      }
      ImGui::EndDisabled();
      const char *formats[] = {"Auto", "RawField", "CrossField / NeurCross", "RoSy"};
      draw_labeled_full_width_control("Input field format", [this, &formats] {
        ImGui::Combo("##input_field_format", &fieldInputFormat_, formats, 4);
      });
      ImGui::BeginDisabled(isBusy || !mesh_.has_value());
      if (ImGui::Button("Load field")) {
        guarded_action([this] { load_field(); });
      }
      ImGui::SameLine();
      if (ImGui::Button("Remesh using input field")) {
        guarded_action([this] {
          load_field();
          launch_remesh_loaded_field();
        });
      }
      ImGui::EndDisabled();
      if (!fieldLabel_.empty()) {
        ImGui::TextWrapped("%s", fieldLabel_.c_str());
      }
    }

    if (ImGui::CollapsingHeader("5. Compare fields")) {
      const float browseWidth = ImGui::CalcTextSize("Browse...").x +
                                2.0F * ImGui::GetStyle().FramePadding.x;
      ImGui::SetNextItemWidth(-browseWidth - ImGui::GetStyle().ItemSpacing.x);
      ImGui::InputText("##compare_field_input_path",
                       compareFieldInputPath_.data(),
                       compareFieldInputPath_.size());
      ImGui::SameLine();
      ImGui::BeginDisabled(isBusy);
      if (ImGui::Button("Browse...##compare_field")) {
        open_compare_field_picker();
      }
      ImGui::EndDisabled();

      const char *formats[] = {"Auto", "RawField", "CrossField / NeurCross", "RoSy"};
      draw_labeled_full_width_control("Reference field format",
                                      [this, &formats] {
                                        ImGui::Combo(
                                            "##compare_field_format",
                                            &compareFieldInputFormat_, formats,
                                            4);
                                      });

      ImGui::Checkbox("Remove best global 4-RoSy phase",
                      &comparisonRemoveGlobalPhase_);
      ImGui::Checkbox("Also score against proxy shape operator",
                      &comparisonShapeOperatorAlignment_);

      draw_labeled_full_width_control(
          "High-error threshold in degrees", [this] {
            ImGui::InputDouble("##comparison_high_error_threshold",
                               &comparisonHighErrorThresholdDegrees_, 1.0,
                               5.0, "%.6g");
          });
      comparisonHighErrorThresholdDegrees_ =
          std::max(0.0, comparisonHighErrorThresholdDegrees_);

      draw_labeled_full_width_control(
          "Heatmap maximum degrees", [this] {
            ImGui::SliderFloat("##comparison_heatmap_max",
                               &comparisonHeatmapMaxDegrees_, 1.0F, 45.0F,
                               "%.1f deg");
          });

      ImGui::BeginDisabled(isBusy || !mesh_.has_value());
      if (ImGui::Button("Load reference field")) {
        guarded_action([this] { load_compare_field(); });
      }
      ImGui::SameLine();
      ImGui::BeginDisabled(!field_.has_value() || !referenceField_.has_value());
      if (ImGui::Button("Compare current field")) {
        guarded_action([this] { launch_compare_fields(); });
      }
      ImGui::EndDisabled();
      ImGui::EndDisabled();

      if (fieldComparison_.has_value()) {
        ImGui::Text("Mean: %.3f deg, median: %.3f deg",
                    fieldComparison_->meanDegrees,
                    fieldComparison_->medianDegrees);
        ImGui::Text("Area-weighted mean: %.3f deg, p95: %.3f deg, p99: %.3f deg",
                    fieldComparison_->areaWeightedMeanDegrees,
                    fieldComparison_->p95Degrees,
                    fieldComparison_->p99Degrees);
        ImGui::Text("> %.3f deg: %lld faces, %.2f%% area, %d components",
                    comparisonHighErrorThresholdDegrees_,
                    static_cast<long long>(
                        fieldComparison_->highErrorFaceCount),
                    100.0 * fieldComparison_->highErrorAreaFraction,
                    fieldComparison_->highErrorComponentCount);
        ImGui::Text("Global phase: %.3f deg",
                    fieldComparison_->globalPhaseDegrees);
        if (fieldComparison_->hasShapeOperatorAlignment) {
          ImGui::Text("Shape alignment first: mean %.3f deg, p95 %.3f deg, energy %.6g",
                      fieldComparison_->firstShapeAlignmentMeanDegrees,
                      fieldComparison_->firstShapeAlignmentP95Degrees,
                      fieldComparison_->firstShapeAlignmentEnergy);
          ImGui::Text("Shape alignment second: mean %.3f deg, p95 %.3f deg, energy %.6g",
                      fieldComparison_->secondShapeAlignmentMeanDegrees,
                      fieldComparison_->secondShapeAlignmentP95Degrees,
                      fieldComparison_->secondShapeAlignmentEnergy);
        }
        ImGui::BeginDisabled(!mesh_.has_value());
        if (ImGui::Button("Refresh deviation heatmap")) {
          guarded_action([this] {
            directional::gui::show_field_deviation_heatmap(
                kInputMeshName, *fieldComparison_, comparisonHeatmapMaxDegrees_);
          });
        }
        ImGui::EndDisabled();
      }
    }

    if (ImGui::CollapsingHeader("Remesh options",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      draw_labeled_full_width_control(
          "Target edge-length ratio (> 0; typical: 0.005 to 0.1)", [this] {
            ImGui::InputDouble("##length_ratio", &remeshOptions_.lengthRatio,
                               0.001, 0.01, "%.6g");
          });

      ImGui::Checkbox(
          "Integral seamless (integer-compatible seamless parameterization)",
          &remeshOptions_.integralSeamless);

      ImGui::Checkbox(
          "Round seams (round seam translations to nearby integer offsets)",
          &remeshOptions_.roundSeams);

      ImGui::Checkbox(
          "Experimental TriFlow DCEL simplification",
          &remeshOptions_.useTriFlowDcelSimplification);
      if (remeshOptions_.useTriFlowDcelSimplification) {
        ImGui::TextWrapped(
            "Runs a conservative TriFlow-style QEM pass directly on the "
            "generated DCEL after the standard arrangement cleanup.");
      }

      ImGui::Checkbox(
          "Verbose (print detailed remeshing progress and diagnostics)",
          &remeshOptions_.verbose);
      if (sessionLog_.is_enabled()) {
        ImGui::TextWrapped("Verbose log: %s",
                           sessionLog_.path().string().c_str());
      }
    }

    if (ImGui::CollapsingHeader("Save outputs")) {
      ImGui::TextUnformatted("Field output");
      ImGui::SetNextItemWidth(-1.0F);
      ImGui::InputText("##field_output_path", fieldOutputPath_.data(),
                       fieldOutputPath_.size());
      const char *formats[] = {"Auto", "RawField", "CrossField / NeurCross", "RoSy"};
      draw_labeled_full_width_control("Output field format", [this, &formats] {
        ImGui::Combo("##output_field_format", &fieldOutputFormat_, formats, 4);
      });
      ImGui::BeginDisabled(isBusy || !field_.has_value());
      if (ImGui::Button("Save field")) {
        guarded_action([this] { save_field(); });
      }
      ImGui::EndDisabled();

      ImGui::Spacing();
      ImGui::TextUnformatted("Mesh output (.obj or .off)");
      ImGui::SetNextItemWidth(-1.0F);
      ImGui::InputText("##remesh_output_path", remeshOutputPath_.data(),
                      remeshOutputPath_.size());

      ImGui::BeginDisabled(isBusy ||
                          (!quadMesh_.has_value() && !mesh_.has_value()));
      if (ImGui::Button(quadMesh_.has_value() ? "Save quad mesh"
                                              : "Save current mesh")) {
        guarded_action([this] { save_quad_mesh(); });
      }
      ImGui::EndDisabled();
    }

    if (isBusy) {
      const std::size_t current =
          progress_->current.load(std::memory_order_relaxed);
      const std::size_t total = std::max<std::size_t>(
          progress_->total.load(std::memory_order_relaxed), 1);
      const float fraction =
          static_cast<float>(current) / static_cast<float>(total);
      const std::string task = progress_->task_copy();
      ImGui::Separator();
      ImGui::ProgressBar(std::clamp(fraction, 0.0F, 1.0F), ImVec2(-1.0F, 0.0F));
      ImGui::TextWrapped("%s", task.c_str());
    }

    ImGui::Separator();
    if (!error_.empty()) {
      ImGui::TextColored(ImVec4(1.0F, 0.35F, 0.35F, 1.0F), "%s",
                         error_.c_str());
    } else {
      ImGui::TextWrapped("%s", status_.c_str());
    }

    process_file_picker();
  }
};

} // namespace

int main(int argc, char **argv) {
  try {
    std::optional<std::filesystem::path> startupMesh;
    if (argc > 1) {
      startupMesh = std::filesystem::path(argv[1]);
    }

    directional::gui::SessionLog sessionLog;
    DirectionalUi app(startupMesh, sessionLog);
    app.initialize();
    app.show();
    return 0;
  } catch (const std::exception &error) {
    std::cerr << "directional-ui: error: " << error.what() << '\n';
    return 1;
  }
}
