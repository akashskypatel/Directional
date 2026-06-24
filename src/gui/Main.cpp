#include "GuiBackend.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include <imgui.h>
#include <polyscope/point_cloud.h>
#include <polyscope/polyscope.h>
#include <polyscope/surface_mesh.h>

namespace {

constexpr const char *kInputMeshName = "Input mesh";
constexpr const char *kFieldGlyphName = "Cross field";
constexpr const char *kQuadMeshName = "Quad remesh";

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
  bool hasField = false;
  bool hasQuadMesh = false;
  directional::gui::FieldData field;
  directional::gui::QuadMeshData quadMesh;
  std::string fieldLabel;
  std::string message;
  std::string error;
};

std::filesystem::path default_sibling_path(const std::filesystem::path &input,
                                           const std::string &suffix,
                                           const std::string &extension) {
  return input.parent_path() /
         (input.stem().string() + suffix + extension);
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

Eigen::MatrixXd face_centers(const directional::gui::MeshData &mesh) {
  Eigen::MatrixXd centers(mesh.faces.rows(), 3);
  for (Eigen::Index face = 0; face < mesh.faces.rows(); ++face) {
    centers.row(face) =
        (mesh.vertices.row(mesh.faces(face, 0)) +
         mesh.vertices.row(mesh.faces(face, 1)) +
         mesh.vertices.row(mesh.faces(face, 2))) /
        3.0;
  }
  return centers;
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
  explicit DirectionalUi(
      const std::optional<std::filesystem::path> &startupMesh) {
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

  std::optional<directional::gui::MeshData> mesh_;
  std::optional<directional::gui::FieldData> field_;
  std::optional<directional::gui::QuadMeshData> quadMesh_;

  std::array<char, 1024> meshPath_{};
  std::array<char, 1024> fieldInputPath_{};
  std::array<char, 1024> fieldOutputPath_{};
  std::array<char, 1024> remeshOutputPath_{};

  int fieldMethod_ = 1;
  int fieldInputFormat_ = 0;
  int fieldOutputFormat_ = 0;
  int fieldSampleStride_ = 1;
  float glyphLengthRatio_ = 0.35F;

  directional::gui::FieldOptions fieldOptions_;
  directional::gui::RemeshOptions remeshOptions_;

  std::future<TaskResult> task_;
  std::shared_ptr<ProgressState> progress_ =
      std::make_shared<ProgressState>();
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
           task_.wait_for(std::chrono::seconds(0)) !=
               std::future_status::ready;
  }

  void set_status(std::string message) {
    status_ = std::move(message);
    error_.clear();
  }

  void set_error(std::string message) { error_ = std::move(message); }

  void clear_field_and_remesh() {
    field_.reset();
    quadMesh_.reset();
    fieldLabel_.clear();
    if (polyscope::hasPointCloud(kFieldGlyphName)) {
      polyscope::removePointCloud(kFieldGlyphName);
    }
    if (polyscope::hasSurfaceMesh(kQuadMeshName)) {
      polyscope::removeSurfaceMesh(kQuadMeshName);
    }
  }

  void load_mesh() {
    const std::filesystem::path path =
        path_from_buffer(meshPath_, "Input mesh");
    directional::gui::MeshData loaded = directional::gui::load_mesh(path);
    if (loaded.faces.cols() != 3) {
      throw std::runtime_error("The input mesh must be triangular.");
    }

    mesh_ = std::move(loaded);
    clear_field_and_remesh();
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::removeSurfaceMesh(kInputMeshName);
    }
    polyscope::registerSurfaceMesh(kInputMeshName, mesh_->vertices,
                                   mesh_->faces)
        ->setSurfaceColor({0.72F, 0.75F, 0.80F});

    fieldSampleStride_ =
        std::max(1, static_cast<int>(mesh_->faces.rows() / 5000));
    copy_path_to_buffer(default_sibling_path(path, "_field", ".rawfield"),
                        fieldOutputPath_);
    copy_path_to_buffer(default_sibling_path(path, "_quad", ".obj"),
                        remeshOutputPath_);
    set_status("Loaded " + std::to_string(mesh_->vertices.rows()) +
               " vertices and " + std::to_string(mesh_->faces.rows()) +
               " triangles.");
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
    const Eigen::MatrixXd centers = face_centers(*mesh_);
    Eigen::MatrixXd sampledCenters(sampleCount, 3);
    std::array<Eigen::MatrixXd, 4> sampledVectors{
        Eigen::MatrixXd(sampleCount, 3), Eigen::MatrixXd(sampleCount, 3),
        Eigen::MatrixXd(sampleCount, 3), Eigen::MatrixXd(sampleCount, 3)};

    Eigen::Index sample = 0;
    for (Eigen::Index face = 0; face < mesh_->faces.rows(); face += stride) {
      sampledCenters.row(sample) = centers.row(face);
      for (int branch = 0; branch < 4; ++branch) {
        sampledVectors[branch].row(sample) =
            field_->raw.block(face, 3 * branch, 1, 3);
      }
      ++sample;
    }

    const double scale =
        static_cast<double>(glyphLengthRatio_) * average_edge_length(*mesh_);
    auto *cloud =
        polyscope::registerPointCloud(kFieldGlyphName, sampledCenters);
    cloud->setPointRadius(0.0);
    for (int branch = 0; branch < 4; ++branch) {
      cloud
          ->addVectorQuantity(
              "Branch " + std::to_string(branch),
              sampledVectors[branch] * scale,
              polyscope::VectorType::AMBIENT)
          ->setEnabled(true);
    }
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

  void launch_calculate_field() {
    require_mesh();
    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldOptions options = current_field_options();
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field calculation");

    task_ = std::async(std::launch::async,
                       [mesh, options, progress]() {
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
    const directional::gui::FieldOptions fieldOptions =
        current_field_options();
    const directional::gui::RemeshOptions remeshOptions = remeshOptions_;
    const auto progress = progress_;
    progress_->update(0, 100, "Starting automatic remesh");

    task_ = std::async(
        std::launch::async,
        [mesh, fieldOptions, remeshOptions, progress]() {
          TaskResult result;
          try {
            directional::gui::AutoRemeshResult remesh =
                directional::gui::auto_remesh(
                    mesh, fieldOptions, remeshOptions,
                    [progress](const std::size_t current,
                               const std::size_t total,
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
            result.message =
                result.fieldLabel + " and generated a quad mesh.";
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
    fieldLabel_ = "Loaded field: " + path.filename().string();
    visualize_field();
    set_status(fieldLabel_ + ".");
  }

  void launch_remesh_loaded_field() {
    require_mesh();
    if (!field_.has_value()) {
      throw std::runtime_error(
          "Load an input field before remeshing with it.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *field_;
    const directional::gui::RemeshOptions options = remeshOptions_;
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field-guided remesh");

    task_ = std::async(
        std::launch::async, [mesh, field, options, progress]() {
          TaskResult result;
          try {
            result.quadMesh = directional::gui::remesh_with_field(
                mesh, field, options,
                [progress](const std::size_t current,
                           const std::size_t total,
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
        task_.wait_for(std::chrono::seconds(0)) !=
            std::future_status::ready) {
      return;
    }

    TaskResult result = task_.get();
    if (!result.error.empty()) {
      set_error(result.error);
      return;
    }
    if (result.hasField) {
      field_ = std::move(result.field);
      fieldLabel_ = std::move(result.fieldLabel);
      visualize_field();
    }
    if (result.hasQuadMesh) {
      quadMesh_ = std::move(result.quadMesh);
      visualize_quad_mesh();
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
    if (!quadMesh_.has_value()) {
      throw std::runtime_error("There is no remeshed output to save.");
    }
    const std::filesystem::path path =
        path_from_buffer(remeshOutputPath_, "Remesh output");
    directional::gui::save_quad_mesh(path, *quadMesh_);
    set_status("Wrote quad mesh to " + path.string() + ".");
  }

  void require_mesh() const {
    if (!mesh_.has_value()) {
      throw std::runtime_error("Load an input mesh first.");
    }
  }

  static directional::gui::FieldFormat selected_field_format(
      const int index) {
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

  void draw_ui() {
    process_completed_task();
    const bool isBusy = busy();

    ImGui::PushItemWidth(-1.0F);
    ImGui::TextUnformatted("Directional Quad Remesher");
    ImGui::Separator();

    if (ImGui::CollapsingHeader("1. Input mesh",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      ImGui::InputText("##mesh_path", meshPath_.data(), meshPath_.size());
      ImGui::BeginDisabled(isBusy);
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

    if (ImGui::CollapsingHeader("2. Calculate field",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      const char *methods[] = {"Smooth power field",
                               "Regularized curvature"};
      ImGui::Combo("Field method", &fieldMethod_, methods, 2);

      if (ImGui::TreeNode("Field options")) {
        ImGui::Checkbox("Normalize directions",
                        &fieldOptions_.normalizeDirections);
        if (fieldMethod_ == 1) {
          ImGui::InputDouble("Proxy fidelity",
                             &fieldOptions_.proxyFidelityWeight, 0.05, 0.5,
                             "%.6g");
          ImGui::InputDouble("Proxy smoothness",
                             &fieldOptions_.proxySmoothnessWeight, 0.001,
                             0.01, "%.6g");
          ImGui::Checkbox("Preserve boundary",
                          &fieldOptions_.preserveBoundary);
          ImGui::InputDouble("Field smoothness",
                             &fieldOptions_.fieldSmoothnessWeight, 0.1, 1.0,
                             "%.6g");
          ImGui::InputDouble("Curvature alignment",
                             &fieldOptions_.curvatureAlignmentWeight, 0.1,
                             1.0, "%.6g");
          ImGui::InputDouble("Minimum confidence",
                             &fieldOptions_.minimumConfidence, 0.001, 0.01,
                             "%.6g");
          ImGui::InputDouble("Confidence exponent",
                             &fieldOptions_.confidenceExponent, 0.1, 1.0,
                             "%.6g");
          ImGui::InputInt("Curvature smoothing iterations",
                          &fieldOptions_.curvatureSmoothingIterations);
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

      ImGui::InputInt("Field display stride", &fieldSampleStride_);
      fieldSampleStride_ = std::max(fieldSampleStride_, 1);
      ImGui::SliderFloat("Glyph length", &glyphLengthRatio_, 0.05F, 1.0F,
                         "%.2f x average edge");
      ImGui::BeginDisabled(isBusy || !field_.has_value());
      if (ImGui::Button("Refresh field display")) {
        guarded_action([this] { visualize_field(); });
      }
      ImGui::EndDisabled();
    }

    if (ImGui::CollapsingHeader("3. Remesh using input field",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      ImGui::InputText("##field_input_path", fieldInputPath_.data(),
                       fieldInputPath_.size());
      const char *formats[] = {"Auto", "RawField", "CrossField", "RoSy"};
      ImGui::Combo("Input field format", &fieldInputFormat_, formats, 4);
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

    if (ImGui::CollapsingHeader("Remesh options",
                                ImGuiTreeNodeFlags_DefaultOpen)) {
      ImGui::InputDouble("Length ratio", &remeshOptions_.lengthRatio, 0.001,
                         0.01, "%.6g");
      ImGui::Checkbox("Integral seamless",
                      &remeshOptions_.integralSeamless);
      ImGui::Checkbox("Round seams", &remeshOptions_.roundSeams);
      ImGui::Checkbox("Verbose backend logging", &remeshOptions_.verbose);
    }

    if (ImGui::CollapsingHeader("Save outputs")) {
      ImGui::TextUnformatted("Field output");
      ImGui::InputText("##field_output_path", fieldOutputPath_.data(),
                       fieldOutputPath_.size());
      const char *formats[] = {"Auto", "RawField", "CrossField", "RoSy"};
      ImGui::Combo("Output field format", &fieldOutputFormat_, formats, 4);
      ImGui::BeginDisabled(isBusy || !field_.has_value());
      if (ImGui::Button("Save field")) {
        guarded_action([this] { save_field(); });
      }
      ImGui::EndDisabled();

      ImGui::Spacing();
      ImGui::TextUnformatted("Quad mesh output (.obj or .off)");
      ImGui::InputText("##remesh_output_path", remeshOutputPath_.data(),
                       remeshOutputPath_.size());
      ImGui::BeginDisabled(isBusy || !quadMesh_.has_value());
      if (ImGui::Button("Save quad mesh")) {
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
      ImGui::ProgressBar(std::clamp(fraction, 0.0F, 1.0F),
                         ImVec2(-1.0F, 0.0F));
      ImGui::TextWrapped("%s", task.c_str());
    }

    ImGui::Separator();
    if (!error_.empty()) {
      ImGui::TextColored(ImVec4(1.0F, 0.35F, 0.35F, 1.0F), "%s",
                         error_.c_str());
    } else {
      ImGui::TextWrapped("%s", status_.c_str());
    }

    ImGui::PopItemWidth();
  }
};

} // namespace

int main(int argc, char **argv) {
  try {
    std::optional<std::filesystem::path> startupMesh;
    if (argc > 1) {
      startupMesh = std::filesystem::path(argv[1]);
    }

    DirectionalUi app(startupMesh);
    app.initialize();
    app.show();
    return 0;
  } catch (const std::exception &error) {
    std::cerr << "directional-ui: error: " << error.what() << '\n';
    return 1;
  }
}
