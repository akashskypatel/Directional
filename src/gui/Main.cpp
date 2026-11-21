#include "FileDialog.h"
#include "FilePicker.h"
#include "GuiBackend.h"
#include "CompareFieldsCommand.h"
#include "SessionLog.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstdint>
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
#include <directional/visualization/FieldStreamlines.h>

#include <polyscope/curve_network.h>
#include <polyscope/point_cloud.h>
#include <polyscope/polyscope.h>
#include <polyscope/surface_mesh.h>
#include <polyscope/view.h>

namespace {

constexpr const char *kInputMeshName = "Input mesh";
constexpr const char *kCalculatedFieldGlyphName = "Calculated field";
constexpr const char *kUploadedFieldGlyphName = "Uploaded field";
constexpr const char *kQuadMeshName = "Quad remesh";
constexpr const char *kDeviationHeatmapName = "Cross-field deviation (degrees)";
constexpr const char *kNetworkTracesName = "A2a field-aligned traces";
constexpr const char *kNetworkMandatoryName = "A2a mandatory edges";
constexpr const char *kNetworkSingularitiesName = "A2a singularities";
constexpr const char *kRegionSeamsName = "A0 isolation seams";
constexpr const char *kRegionBoundariesName = "A0 region boundaries";
constexpr const char *kFaceRegionQuantity = "A0 topology region";
constexpr const char *kFaceSheetQuantity = "A0 isolation sheet";
constexpr const char *kFaceComponentQuantity = "A0 source component";
constexpr const char *kStreamlinesName = "Field streamlines";
constexpr const char *kStopFacesName = "SurfaceCells stop faces";
constexpr const char *kStopEdgesName = "SurfaceCells stop edges";
constexpr const char *kStopVerticesName = "SurfaceCells stop vertices";
constexpr const char *kTracedCellsName = "A4 traced cells";
constexpr const char *kTracedCornersName = "A4 cell corners";
constexpr const char *kOccurrenceSidesName = "A5 occurrence cell sides";
constexpr const char *kOccurrencesName = "A5 corner occurrences";
constexpr const char *kQuotientClassQuantity = "A6 quotient class";
constexpr const char *kGeometryQuadsName = "A7 source-attached geometry";
constexpr const char *kCutEdgesName = "A2a' cut edges";
constexpr const char *kGraphArcsName = "A2b graph arcs";
constexpr const char *kFaceDiscRegionQuantity = "A2b disc region";
constexpr const char *kFeatureEdgesName = "Feature edges";
constexpr const char *kSizeQuantityPrefix = "Size: ";
constexpr const char *kStreamlineLineColors = "line colors";
constexpr const char *kStreamlineFamilyColors = "direction family";

enum class FilePickerTarget { None, Mesh, Field };

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

struct ComparisonReportContext {
  directional::gui::FieldOptions candidateOptions;
  std::string meshPath;
  std::string referencePath;
  std::string candidateLabel;
  std::string referenceLabel;
  std::string referenceFormat;
  bool removeGlobalPhase = true;
  bool shapeOperatorAlignment = false;
};

struct TaskResult {
  bool hasMesh = false;
  bool hasField = false;
  bool hasQuadMesh = false;
  bool hasComparison = false;
  bool hasSurfaceCellDiagnostics = false;
  bool hasStreamlines = false;
  bool hasFieldNetwork = false;
  bool hasCutGraph = false;
  bool hasTargetSize = false;
  directional::gui::MeshData mesh;
  directional::gui::FieldData field;
  std::optional<directional::gui::FieldOptions> fieldOptions;
  directional::gui::QuadMeshData quadMesh;
  directional::gui::FieldComparisonData comparison;
  directional::gui::SurfaceCellDiagnosticsData surfaceCellDiagnostics;
  directional::visualization::FieldStreamlines streamlines;
  directional::visualization::FieldAlignedNetworkPolylines fieldNetwork;
  std::string fieldNetworkStage;
  directional::visualization::CutGraphDisplay cutGraph;
  std::string cutGraphStage;
  directional::gui::TargetSizeData targetSize;
  std::optional<ComparisonReportContext> comparisonContext;
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

// ImGui::TextColored never wraps, so a long error or field label is clipped at
// the panel edge. Wrapped text also grows the panel's content height, which
// extends its scroll range to the last line.
void text_colored_wrapped(const ImVec4 &color, const std::string &text) {
  ImGui::PushStyleColor(ImGuiCol_Text, color);
  ImGui::TextWrapped("%s", text.c_str());
  ImGui::PopStyleColor();
}

// One color per streamline from a small print-like palette; the multiplicative
// hash keeps neighbouring line ids from sharing a color.
Eigen::MatrixXd streamline_colors(const Eigen::VectorXi &edgeLine) {
  static const std::array<Eigen::RowVector3d, 6> palette{
      Eigen::RowVector3d(0.00, 0.75, 0.95), Eigen::RowVector3d(0.95, 0.10, 0.60),
      Eigen::RowVector3d(1.00, 0.88, 0.10), Eigen::RowVector3d(0.30, 0.55, 0.95),
      Eigen::RowVector3d(1.00, 0.55, 0.75), Eigen::RowVector3d(0.65, 0.45, 0.95)};
  Eigen::MatrixXd colors(edgeLine.size(), 3);
  for (Eigen::Index edge = 0; edge < edgeLine.size(); ++edge) {
    const auto hash = static_cast<std::uint32_t>(edgeLine(edge)) * 2654435761U;
    colors.row(edge) = palette[(hash >> 16U) % palette.size()];
  }
  return colors;
}

Eigen::MatrixXd family_colors(const Eigen::VectorXi &edgeFamily) {
  Eigen::MatrixXd colors(edgeFamily.size(), 3);
  for (Eigen::Index edge = 0; edge < edgeFamily.size(); ++edge) {
    colors.row(edge) = edgeFamily(edge) == 0
                           ? Eigen::RowVector3d(0.00, 0.75, 0.95)
                           : Eigen::RowVector3d(0.95, 0.10, 0.60);
  }
  return colors;
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

struct FieldGlyphState {
  Eigen::MatrixXd centers;
  Eigen::MatrixXd normals;
  double surfaceOffset = 0.0;
  std::optional<Eigen::Vector3d> lastCameraPosition;
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
    comparisonReportPath_.fill('\0');
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
  std::optional<directional::gui::FieldData> calculatedField_;
  std::optional<directional::gui::FieldOptions> calculatedFieldOptions_;
  std::optional<directional::gui::FieldData> uploadedField_;
  std::optional<directional::gui::FieldComparisonData> fieldComparison_;
  std::optional<ComparisonReportContext> comparisonContext_;
  std::optional<directional::gui::QuadMeshData> quadMesh_;
  std::optional<directional::gui::SurfaceCellDiagnosticsData>
      surfaceCellDiagnostics_;
  std::optional<directional::visualization::FieldStreamlines> streamlines_;
  std::optional<directional::visualization::FieldAlignedNetworkPolylines>
      fieldNetwork_;
  std::string fieldNetworkStage_;
  std::optional<directional::visualization::CutGraphDisplay> cutGraph_;
  std::string cutGraphStage_;
  std::optional<directional::gui::TargetSizeData> targetSize_;

  std::array<char, 1024> meshPath_{};
  std::array<char, 1024> fieldInputPath_{};
  std::array<char, 1024> fieldOutputPath_{};
  std::array<char, 1024> comparisonReportPath_{};
  std::array<char, 1024> remeshOutputPath_{};

  directional::gui::FilePicker filePicker_;
  FilePickerTarget filePickerTarget_ = FilePickerTarget::None;

  int fieldMethod_ = 1;
  int fieldInputFormat_ = 0;
  int fieldOutputFormat_ = 0;
  int fieldOutputSource_ = 0;
  int diagnosticsFieldSource_ = 0;
  bool diagnosticsStopAfterTracing_ = true;
  int streamlineFieldSource_ = 0;
  int fieldNetworkSource_ = 0;
  int cutGraphFieldSource_ = 0;
  int targetSizeFieldSource_ = 0;
  int targetSizeScalar_ = 0;
  float streamlineSeedSpacing_ = 2.0F;
  int streamlineSteps_ = 120;
  float streamlineStepLength_ = 0.5F;
  float streamlineThickness_ = 0.06F;
  int streamlineColorMode_ = 0;
  int fieldSampleStride_ = 1;
  float glyphLengthRatio_ = 0.35F;
  float glyphSurfaceOffsetRatio_ = 0.04F;
  FieldGlyphState calculatedFieldGlyph_;
  FieldGlyphState uploadedFieldGlyph_;
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
  std::string calculatedFieldLabel_;
  std::string uploadedFieldLabel_;

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
    calculatedField_.reset();
    calculatedFieldOptions_.reset();
    uploadedField_.reset();
    fieldComparison_.reset();
    comparisonContext_.reset();
    quadMesh_.reset();
    clear_surface_cell_diagnostics();
    clear_streamlines();
    clear_field_network();
    clear_cut_graph();
    clear_target_size();
    calculatedFieldLabel_.clear();
    uploadedFieldLabel_.clear();
    calculatedFieldGlyph_ = {};
    uploadedFieldGlyph_ = {};
    if (polyscope::hasPointCloud(kCalculatedFieldGlyphName)) {
      polyscope::removePointCloud(kCalculatedFieldGlyphName);
    }
    if (polyscope::hasPointCloud(kUploadedFieldGlyphName)) {
      polyscope::removePointCloud(kUploadedFieldGlyphName);
    }
    if (polyscope::hasSurfaceMesh(kQuadMeshName)) {
      polyscope::removeSurfaceMesh(kQuadMeshName);
    }
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::getSurfaceMesh(kInputMeshName)
          ->removeQuantity(kDeviationHeatmapName, false);
    }
  }

  void remove_surface_cell_layers() {
    for (const char *name : {kNetworkTracesName, kNetworkMandatoryName,
                             kRegionSeamsName, kRegionBoundariesName,
                             kStopEdgesName, kTracedCellsName,
                             kOccurrenceSidesName}) {
      if (polyscope::hasCurveNetwork(name)) {
        polyscope::removeCurveNetwork(name);
      }
    }
    for (const char *name : {kNetworkSingularitiesName, kStopVerticesName,
                             kTracedCornersName, kOccurrencesName}) {
      if (polyscope::hasPointCloud(name)) {
        polyscope::removePointCloud(name);
      }
    }
    for (const char *name : {kStopFacesName, kGeometryQuadsName}) {
      if (polyscope::hasSurfaceMesh(name)) {
        polyscope::removeSurfaceMesh(name);
      }
    }
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
      for (const char *name : {kFaceRegionQuantity, kFaceSheetQuantity,
                               kFaceComponentQuantity}) {
        inputMesh->removeQuantity(name, false);
      }
    }
  }

  void remove_field_network_layers() {
    for (const char *name : {kNetworkTracesName, kNetworkMandatoryName}) {
      if (polyscope::hasCurveNetwork(name)) {
        polyscope::removeCurveNetwork(name);
      }
    }
    if (polyscope::hasPointCloud(kNetworkSingularitiesName)) {
      polyscope::removePointCloud(kNetworkSingularitiesName);
    }
  }

  void clear_field_network() {
    fieldNetwork_.reset();
    fieldNetworkStage_.clear();
    remove_field_network_layers();
  }

  void remove_cut_graph_layers() {
    for (const char *name : {kCutEdgesName, kGraphArcsName}) {
      if (polyscope::hasCurveNetwork(name)) {
        polyscope::removeCurveNetwork(name);
      }
    }
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::getSurfaceMesh(kInputMeshName)
          ->removeQuantity(kFaceDiscRegionQuantity, false);
    }
  }

  void clear_cut_graph() {
    cutGraph_.reset();
    cutGraphStage_.clear();
    remove_cut_graph_layers();
  }

  void visualize_cut_graph(
      const directional::visualization::CutGraphDisplay &cutGraph) {
    remove_cut_graph_layers();
    if (cutGraph.hasTopologyPlan && polyscope::hasSurfaceMesh(kInputMeshName)) {
      auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
      // -1: in no region; -2: split among regions by traces.
      inputMesh
          ->addFaceScalarQuantity(kFaceDiscRegionQuantity, cutGraph.faceRegion,
                                  polyscope::DataType::CATEGORICAL)
          ->setEnabled(true);
      inputMesh->setEnabled(true);
    }
    if (cutGraph.cutEdges.rows() > 0) {
      auto *cuts = polyscope::registerCurveNetwork(
          kCutEdgesName, cutGraph.cutPoints, cutGraph.cutEdges);
      cuts->setColor({0.80F, 0.25F, 0.05F});
      cuts->setRadius(0.003F);
    }
    if (cutGraph.arcEdges.rows() > 0) {
      auto *arcs = polyscope::registerCurveNetwork(
          kGraphArcsName, cutGraph.arcPoints, cutGraph.arcEdges);
      arcs->setColor({0.15F, 0.15F, 0.15F});
      arcs->setRadius(0.002F);
      // 0 mandatory, 1 trace, 2 cut.
      arcs->addEdgeScalarQuantity("arc kind", cutGraph.arcKind,
                                  polyscope::DataType::CATEGORICAL)
          ->setEnabled(true);
      arcs->addEdgeScalarQuantity("arc", cutGraph.arcIndex,
                                  polyscope::DataType::CATEGORICAL);
    }
    sync_overlay_transforms();
  }

  void remove_target_size_layers() {
    if (polyscope::hasCurveNetwork(kFeatureEdgesName)) {
      polyscope::removeCurveNetwork(kFeatureEdgesName);
    }
    if (targetSize_.has_value() && polyscope::hasSurfaceMesh(kInputMeshName)) {
      auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
      for (const auto &field : targetSize_->display.vertexScalars) {
        inputMesh->removeQuantity(kSizeQuantityPrefix + field.name, false);
      }
    }
  }

  void clear_target_size() {
    remove_target_size_layers();
    targetSize_.reset();
    targetSizeScalar_ = 0;
  }

  void show_selected_target_scalar() {
    if (!targetSize_.has_value() || !polyscope::hasSurfaceMesh(kInputMeshName)) {
      return;
    }
    const auto &fields = targetSize_->display.vertexScalars;
    if (targetSizeScalar_ < 0 || targetSizeScalar_ >= static_cast<int>(fields.size())) {
      return;
    }
    auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
    inputMesh
        ->getQuantity(kSizeQuantityPrefix +
                      fields[static_cast<std::size_t>(targetSizeScalar_)].name)
        ->setEnabled(true);
    inputMesh->setEnabled(true);
  }

  void visualize_target_size() {
    if (!targetSize_.has_value()) {
      return;
    }
    const auto &display = targetSize_->display;
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
      for (const auto &field : display.vertexScalars) {
        inputMesh->addVertexScalarQuantity(kSizeQuantityPrefix + field.name,
                                           field.values);
      }
    }
    if (display.featureEdges.rows() > 0) {
      auto *features = polyscope::registerCurveNetwork(
          kFeatureEdgesName, display.featurePoints, display.featureEdges);
      features->setColor({0.10F, 0.10F, 0.10F});
      features->setRadius(0.0025F);
      // 1 boundary, 2 soft, 3 hard, 4 non-manifold.
      features->addEdgeScalarQuantity("class", display.featureClass,
                                      polyscope::DataType::CATEGORICAL)
          ->setEnabled(true);
      features->addEdgeScalarQuantity("strength", display.featureStrength);
      features->addEdgeScalarQuantity("angle (degrees)",
                                      display.featureAngleDegrees);
    }
    show_selected_target_scalar();
    sync_overlay_transforms();
  }

  void clear_streamlines() {
    streamlines_.reset();
    if (polyscope::hasCurveNetwork(kStreamlinesName)) {
      polyscope::removeCurveNetwork(kStreamlinesName);
    }
  }

  void clear_surface_cell_diagnostics() {
    surfaceCellDiagnostics_.reset();
    remove_surface_cell_layers();
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
    copy_path_to_buffer(
        default_sibling_path(path, "_field_comparison", ".fieldcmp.json"),
        comparisonReportPath_);
    copy_path_to_buffer(default_sibling_path(path, "_quad", ".obj"),
                        remeshOutputPath_);
    set_status("Loaded " + std::to_string(vertexCount) +
               " vertices and " + std::to_string(faceCount) +
               " triangles.");
  }

  void update_field_glyph_positions(const char *glyphName,
                                    FieldGlyphState &glyphState,
                                    const bool force = false) {
    if (glyphState.centers.rows() == 0 ||
        !polyscope::hasPointCloud(glyphName) ||
        !polyscope::hasSurfaceMesh(kInputMeshName)) {
      return;
    }

    auto *cloud = polyscope::getPointCloud(glyphName);
    auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
    const glm::mat4 meshTransform = inputMesh->getTransform();

    // Reuse the mesh transform so that face centers and vectors remain in
    // exactly the same coordinate frame as the input surface.
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
        std::max(glyphState.surfaceOffset * 1e-4, 1e-12);
    if (!force && !transformChanged &&
        glyphState.lastCameraPosition.has_value() &&
        (camera - *glyphState.lastCameraPosition).squaredNorm() <=
            positionTolerance * positionTolerance) {
      return;
    }

    Eigen::MatrixXd displayCenters = glyphState.centers;
    for (Eigen::Index sample = 0; sample < displayCenters.rows(); ++sample) {
      const Eigen::Vector3d normal =
          glyphState.normals.row(sample).transpose();
      if (normal.squaredNorm() == 0.0) {
        continue;
      }

      const Eigen::Vector3d center =
          glyphState.centers.row(sample).transpose();
      const double side = normal.dot(camera - center) >= 0.0 ? 1.0 : -1.0;
      displayCenters.row(sample) =
          (center + side * glyphState.surfaceOffset * normal).transpose();
    }

    cloud->updatePointPositions(displayCenters);
    glyphState.lastCameraPosition = camera;
  }

  void visualize_field(
      const directional::gui::FieldData &field, const char *glyphName,
      FieldGlyphState &glyphState,
      const std::array<glm::vec3, 4> &branchColors,
      const double radiusMultiplier, const double offsetMultiplier) {
    if (!mesh_.has_value()) {
      return;
    }
    directional::gui::validate_field(field, mesh_->faces.rows());

    if (polyscope::hasPointCloud(glyphName)) {
      polyscope::removePointCloud(glyphName);
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
            field.raw.block(face, 3 * branch, 1, 3);
      }
      ++sample;
    }

    const double averageEdgeLength = average_edge_length(*mesh_);
    const double scale =
        static_cast<double>(glyphLengthRatio_) * averageEdgeLength;
    const double vectorRadius =
        std::max(scale * radiusMultiplier, 1e-12);
    glyphState.surfaceOffset =
        static_cast<double>(glyphSurfaceOffsetRatio_) * averageEdgeLength *
        offsetMultiplier;
    glyphState.centers = sampledCenters;
    glyphState.normals = sampledNormals;
    glyphState.lastCameraPosition.reset();

    auto *cloud = polyscope::registerPointCloud(glyphName, sampledCenters);
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
          ->setVectorColor(branchColors[branch])
          ->setVectorRadius(vectorRadius, false)
          ->setEnabled(true);
    }

    update_field_glyph_positions(glyphName, glyphState, true);
  }

  void visualize_calculated_field() {
    if (!calculatedField_.has_value()) {
      return;
    }
    static const std::array<glm::vec3, 4> branchColors{
        {{0.10F, 0.55F, 1.00F},
         {0.00F, 0.80F, 0.80F},
         {0.35F, 0.75F, 1.00F},
         {0.45F, 0.35F, 0.95F}}};
    visualize_field(*calculatedField_, kCalculatedFieldGlyphName,
                    calculatedFieldGlyph_, branchColors, 0.030, 1.0);
  }

  void visualize_uploaded_field() {
    if (!uploadedField_.has_value()) {
      return;
    }
    static const std::array<glm::vec3, 4> branchColors{
        {{1.00F, 0.45F, 0.15F},
         {1.00F, 0.70F, 0.10F},
         {0.90F, 0.20F, 0.20F},
         {1.00F, 0.35F, 0.65F}}};
    // Use thinner, slightly more elevated glyphs so coincident calculated and
    // uploaded directions remain simultaneously visible.
    visualize_field(*uploadedField_, kUploadedFieldGlyphName,
                    uploadedFieldGlyph_, branchColors, 0.018, 1.5);
  }

  void visualize_fields() {
    if (calculatedField_.has_value()) {
      visualize_calculated_field();
    } else if (polyscope::hasPointCloud(kCalculatedFieldGlyphName)) {
      polyscope::removePointCloud(kCalculatedFieldGlyphName);
      calculatedFieldGlyph_ = {};
    }

    if (uploadedField_.has_value()) {
      visualize_uploaded_field();
    } else if (polyscope::hasPointCloud(kUploadedFieldGlyphName)) {
      polyscope::removePointCloud(kUploadedFieldGlyphName);
      uploadedFieldGlyph_ = {};
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

  void sync_overlay_transforms() {
    if (!polyscope::hasSurfaceMesh(kInputMeshName)) {
      return;
    }
    const glm::mat4 meshTransform =
        polyscope::getSurfaceMesh(kInputMeshName)->getTransform();
    const auto sync = [&meshTransform](polyscope::Structure *structure) {
      if (!matrix_nearly_equal(structure->getTransform(), meshTransform)) {
        structure->setTransform(meshTransform);
      }
    };
    for (const char *name : {kNetworkTracesName, kNetworkMandatoryName,
                             kRegionSeamsName, kRegionBoundariesName,
                             kStreamlinesName, kStopEdgesName,
                             kTracedCellsName, kCutEdgesName,
                             kGraphArcsName, kFeatureEdgesName,
                             kOccurrenceSidesName}) {
      if (polyscope::hasCurveNetwork(name)) {
        sync(polyscope::getCurveNetwork(name));
      }
    }
    for (const char *name : {kNetworkSingularitiesName, kStopVerticesName,
                             kTracedCornersName, kOccurrencesName}) {
      if (polyscope::hasPointCloud(name)) {
        sync(polyscope::getPointCloud(name));
      }
    }
    for (const char *name : {kStopFacesName, kGeometryQuadsName}) {
      if (polyscope::hasSurfaceMesh(name)) {
        sync(polyscope::getSurfaceMesh(name));
      }
    }
  }

  void visualize_quad_tracing(
      const directional::visualization::SurfaceCellTracingDisplay &tracing) {
    if (tracing.stopFaces.rows() > 0 && mesh_.has_value()) {
      // Lift each highlighted face off the surface so it does not z-fight.
      const double lift =
          0.002 * (mesh_->vertices.colwise().maxCoeff() -
                   mesh_->vertices.colwise().minCoeff())
                      .norm();
      Eigen::MatrixXd lifted = tracing.stopFaceVertices;
      for (Eigen::Index face = 0; face < tracing.stopFaces.rows(); ++face) {
        const Eigen::RowVector3d a = lifted.row(tracing.stopFaces(face, 0));
        const Eigen::RowVector3d b = lifted.row(tracing.stopFaces(face, 1));
        const Eigen::RowVector3d c = lifted.row(tracing.stopFaces(face, 2));
        const Eigen::RowVector3d normal = (b - a).cross(c - a).normalized();
        for (int corner = 0; corner < 3; ++corner) {
          lifted.row(tracing.stopFaces(face, corner)) += lift * normal;
        }
      }
      auto *faces = polyscope::registerSurfaceMesh(kStopFacesName, lifted,
                                                   tracing.stopFaces);
      faces->setSurfaceColor({1.0F, 0.50F, 0.0F});
      faces->setBackFacePolicy(polyscope::BackFacePolicy::Identical);
      // 0 stopping face, 1 related face.
      faces->addFaceScalarQuantity("role", tracing.stopFaceRole,
                                   polyscope::DataType::CATEGORICAL);
    }
    if (tracing.stopEdges.rows() > 0) {
      auto *edges = polyscope::registerCurveNetwork(
          kStopEdgesName, tracing.stopEdgePoints, tracing.stopEdges);
      edges->setColor({1.0F, 0.35F, 0.0F});
      edges->setRadius(0.004F);
    }
    if (tracing.stopVertices.rows() > 0) {
      auto *vertices =
          polyscope::registerPointCloud(kStopVerticesName, tracing.stopVertices);
      vertices->setPointColor({1.0F, 0.20F, 0.0F});
      vertices->setPointRadius(0.012F);
    }
    if (tracing.cellEdges.rows() > 0) {
      auto *cells = polyscope::registerCurveNetwork(
          kTracedCellsName, tracing.cellPoints, tracing.cellEdges);
      cells->setColor({0.05F, 0.45F, 0.20F});
      cells->setRadius(0.0012F);
    }
    if (tracing.cellCorners.rows() > 0) {
      auto *corners =
          polyscope::registerPointCloud(kTracedCornersName, tracing.cellCorners);
      corners->setPointColor({0.05F, 0.30F, 0.12F});
      corners->setPointRadius(0.0025F);
    }
  }

  void visualize_source_regions(
      const directional::visualization::SourceRegionDisplay &regions) {
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
      inputMesh->addFaceScalarQuantity(kFaceRegionQuantity, regions.faceRegion,
                                       polyscope::DataType::CATEGORICAL);
      inputMesh->addFaceScalarQuantity(kFaceComponentQuantity,
                                       regions.faceComponent,
                                       polyscope::DataType::CATEGORICAL);
      inputMesh
          ->addFaceScalarQuantity(kFaceSheetQuantity, regions.faceSheet,
                                  polyscope::DataType::CATEGORICAL)
          ->setEnabled(true);
      // A quad remesh hides the input mesh; the labels live on it.
      inputMesh->setEnabled(true);
    }
    if (regions.seamEdges.rows() > 0) {
      auto *seams = polyscope::registerCurveNetwork(
          kRegionSeamsName, regions.seamPoints, regions.seamEdges);
      seams->setColor({0.95F, 0.10F, 0.85F});
      seams->setRadius(0.003F);
      seams->addEdgeScalarQuantity("region", regions.seamRegion,
                                   polyscope::DataType::CATEGORICAL);
    }
    if (regions.boundaryEdges.rows() > 0) {
      auto *boundaries = polyscope::registerCurveNetwork(
          kRegionBoundariesName, regions.boundaryPoints, regions.boundaryEdges);
      boundaries->setColor({0.10F, 0.10F, 0.10F});
      boundaries->setRadius(0.002F);
    }
  }

  void visualize_field_network(
      const directional::visualization::FieldAlignedNetworkPolylines &network) {
    if (network.traceEdges.rows() > 0) {
      auto *traces = polyscope::registerCurveNetwork(
          kNetworkTracesName, network.tracePoints, network.traceEdges);
      traces->setColor({0.10F, 0.45F, 0.85F});
      traces->setRadius(0.0015F);
      traces->addEdgeScalarQuantity("trace", network.traceEdgeTrace,
                                    polyscope::DataType::CATEGORICAL);
      // 0 open, 1 barrier, 2 singularity, 3 contact, 4 limit cycle.
      traces->addEdgeScalarQuantity("terminal kind", network.traceEdgeTerminal,
                                    polyscope::DataType::CATEGORICAL);
    }
    if (network.mandatoryEdges.rows() > 0) {
      auto *mandatory = polyscope::registerCurveNetwork(
          kNetworkMandatoryName, network.mandatoryPoints,
          network.mandatoryEdges);
      mandatory->setColor({0.15F, 0.15F, 0.15F});
      mandatory->setRadius(0.0025F);
    }
    if (network.singularityPoints.rows() > 0) {
      auto *singularities = polyscope::registerPointCloud(
          kNetworkSingularitiesName, network.singularityPoints);
      singularities->setPointRadius(0.006F);
      singularities
          ->addScalarQuantity("index numerator", network.singularityIndex,
                              polyscope::DataType::SYMMETRIC)
          ->setEnabled(true);
    }
  }

  void visualize_materialization(
      const directional::visualization::MaterializationDiagnosticsDisplay
          &products) {
    if (products.occurrenceSides.rows() > 0) {
      auto *sides = polyscope::registerCurveNetwork(
          kOccurrenceSidesName, products.occurrencePoints,
          products.occurrenceSides);
      sides->setColor({0.85F, 0.45F, 0.10F});
      sides->setRadius(0.0012F);
    }
    if (products.occurrencePoints.rows() > 0) {
      auto *occurrences = polyscope::registerPointCloud(
          kOccurrencesName, products.occurrencePoints);
      occurrences->setPointRadius(0.003F);
      // -1 marks an occurrence that no retained A6 class lists.
      if (products.hasQuotientProduct) {
        occurrences
            ->addScalarQuantity(kQuotientClassQuantity,
                                products.occurrenceClass,
                                polyscope::DataType::CATEGORICAL)
            ->setEnabled(true);
      }
    }
    if (products.geometryQuads.rows() > 0) {
      auto *geometry = polyscope::registerSurfaceMesh(
          kGeometryQuadsName, products.geometryPoints, products.geometryQuads);
      geometry->setEdgeWidth(1.0);
      geometry->setEnabled(false);
    }
  }

  void apply_streamline_style() {
    if (!streamlines_.has_value() || !polyscope::hasCurveNetwork(kStreamlinesName)) {
      return;
    }
    auto *lines = polyscope::getCurveNetwork(kStreamlinesName);
    lines->setRadius(streamlineThickness_ *
                         static_cast<float>(streamlines_->averageEdgeLength),
                     false);
    lines
        ->getQuantity(streamlineColorMode_ == 0 ? kStreamlineLineColors
                                                : kStreamlineFamilyColors)
        ->setEnabled(true);
  }

  void visualize_streamlines() {
    if (!streamlines_.has_value()) {
      return;
    }
    if (polyscope::hasCurveNetwork(kStreamlinesName)) {
      polyscope::removeCurveNetwork(kStreamlinesName);
    }
    if (streamlines_->edges.rows() == 0) {
      return;
    }
    auto *lines = polyscope::registerCurveNetwork(
        kStreamlinesName, streamlines_->points, streamlines_->edges);
    lines->addEdgeColorQuantity(kStreamlineLineColors,
                                streamline_colors(streamlines_->edgeLine));
    lines->addEdgeColorQuantity(kStreamlineFamilyColors,
                                family_colors(streamlines_->edgeFamily));
    apply_streamline_style();
    sync_overlay_transforms();
  }

  void visualize_surface_cell_diagnostics() {
    if (!surfaceCellDiagnostics_.has_value()) {
      return;
    }
    remove_surface_cell_layers();
    if (surfaceCellDiagnostics_->regions.has_value()) {
      visualize_source_regions(*surfaceCellDiagnostics_->regions);
    }
    if (surfaceCellDiagnostics_->network.has_value()) {
      visualize_field_network(*surfaceCellDiagnostics_->network);
    }
    if (surfaceCellDiagnostics_->materialization.has_value()) {
      visualize_materialization(*surfaceCellDiagnostics_->materialization);
    }
    visualize_quad_tracing(surfaceCellDiagnostics_->tracing);
    sync_overlay_transforms();
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
        result.fieldOptions = options;
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
        result.fieldOptions = fieldOptions;
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

  void load_uploaded_field() {
    require_mesh();
    const std::filesystem::path path =
        path_from_buffer(fieldInputPath_, "Uploaded field");
    uploadedField_ = directional::gui::load_field(
        path, selected_field_format(fieldInputFormat_), *mesh_);
    fieldComparison_.reset();
    comparisonContext_.reset();
    if (polyscope::hasSurfaceMesh(kInputMeshName)) {
      polyscope::getSurfaceMesh(kInputMeshName)
          ->removeQuantity(kDeviationHeatmapName, false);
    }
    uploadedFieldLabel_ = "Uploaded field: " + path.filename().string();
    visualize_uploaded_field();
    set_status(uploadedFieldLabel_ + ".");
  }

  void launch_compare_fields() {
    require_mesh();
    if (!calculatedField_.has_value()) {
      throw std::runtime_error("Calculate a field before comparing it.");
    }
    if (!uploadedField_.has_value()) {
      throw std::runtime_error("Load an uploaded field before comparing.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *calculatedField_;
    const directional::gui::FieldData reference = *uploadedField_;
    const double highErrorThreshold = comparisonHighErrorThresholdDegrees_;
    const bool removeGlobalPhase = comparisonRemoveGlobalPhase_;
    const bool shapeOperatorAlignment = comparisonShapeOperatorAlignment_;
    ComparisonReportContext reportContext;
    reportContext.candidateOptions =
        calculatedFieldOptions_.value_or(current_field_options());
    reportContext.meshPath = std::filesystem::path(meshPath_.data()).string();
    reportContext.referencePath =
        std::filesystem::path(fieldInputPath_.data()).string();
    reportContext.candidateLabel = calculatedFieldLabel_;
    reportContext.referenceLabel = uploadedFieldLabel_;
    reportContext.referenceFormat = selected_field_format_label(fieldInputFormat_);
    reportContext.removeGlobalPhase = removeGlobalPhase;
    reportContext.shapeOperatorAlignment = shapeOperatorAlignment;
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field comparison");

    task_ = std::async(std::launch::async, [mesh, field, reference,
                                            highErrorThreshold,
                                            removeGlobalPhase,
                                            shapeOperatorAlignment,
                                            reportContext, progress]() {
      TaskResult result;
      try {
        result.comparison = directional::gui::compare_fields(
            mesh, field, reference, highErrorThreshold, removeGlobalPhase,
            shapeOperatorAlignment);
        result.hasComparison = true;
        result.comparisonContext = reportContext;
        result.message = "Compared the calculated field to the uploaded field.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field comparison finished");
      return result;
    });
    set_status("Comparing the calculated field to the uploaded field...");
  }

  void launch_remesh_loaded_field() {
    require_mesh();
    if (!uploadedField_.has_value()) {
      throw std::runtime_error("Load an uploaded field before remeshing with it.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *uploadedField_;
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
        result.message = "Generated a quad mesh from the uploaded field.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field-guided remesh finished");
      return result;
    });
    set_status("Remeshing with the uploaded field...");
  }

  void launch_surface_cell_diagnostics() {
    require_mesh();
    const std::optional<directional::gui::FieldData> &source =
        diagnosticsFieldSource_ == 0 ? calculatedField_ : uploadedField_;
    if (!source.has_value()) {
      throw std::runtime_error(
          diagnosticsFieldSource_ == 0
              ? "Calculate a field before running SurfaceCells diagnostics."
              : "Load an uploaded field before running SurfaceCells diagnostics.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *source;
    const directional::gui::RemeshOptions options = remeshOptions_;
    const bool stopAfterTracing = diagnosticsStopAfterTracing_;
    enable_verbose_session_log_if_needed(options.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Starting SurfaceCells diagnostics");

    task_ = std::async(std::launch::async, [mesh, field, options,
                                            stopAfterTracing, progress]() {
      TaskResult result;
      try {
        result.surfaceCellDiagnostics =
            directional::gui::run_surface_cell_diagnostics(
                mesh, field, options, stopAfterTracing,
                [progress](const std::size_t current, const std::size_t total,
                           const std::string_view task) {
                  progress->update(current, total, task);
                });
        result.hasSurfaceCellDiagnostics = true;
        const auto &diagnostics = result.surfaceCellDiagnostics;
        std::string message = "SurfaceCells diagnostics: ";
        if (diagnostics.regions.has_value()) {
          message += std::to_string(diagnostics.regions->regionCount) +
                     " topology regions, " +
                     std::to_string(diagnostics.regions->sheetCount) +
                     " isolation sheets, " +
                     std::to_string(diagnostics.regions->seamEdges.rows()) +
                     " seam edges; ";
        }
        if (diagnostics.network.has_value()) {
          message += std::to_string(diagnostics.network->traceCount) +
                     " field-aligned traces, " +
                     std::to_string(
                         diagnostics.network->singularityPoints.rows()) +
                     " singularities; ";
        } else {
          message += "no field-aligned network; ";
        }
        if (diagnostics.tracing.cellCount > 0U) {
          message += std::to_string(diagnostics.tracing.cellCount) +
                     " traced cells; ";
        }
        message += diagnostics.pipelineProduced
                       ? std::string("remesh produced.")
                   : diagnostics.stoppedOnRequest
                       ? std::string("stopped after quad tracing as requested.")
                       : "stopped at " + diagnostics.pipelineStage + ".";
        result.message = std::move(message);
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "SurfaceCells diagnostics finished");
      return result;
    });
    set_status("Running SurfaceCells diagnostics...");
  }

  void launch_trace_field_network() {
    require_mesh();
    const std::optional<directional::gui::FieldData> &source =
        fieldNetworkSource_ == 0 ? calculatedField_ : uploadedField_;
    if (!source.has_value()) {
      throw std::runtime_error(
          fieldNetworkSource_ == 0
              ? "Calculate a field before tracing its network."
              : "Load an uploaded field before tracing its network.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *source;
    const directional::gui::RemeshOptions options = remeshOptions_;
    enable_verbose_session_log_if_needed(options.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Starting field-aligned network trace");

    task_ = std::async(std::launch::async, [mesh, field, options, progress]() {
      TaskResult result;
      try {
        // The network (A2a) is built during the tracing stage, so the run can
        // stop right after it.
        directional::gui::SurfaceCellDiagnosticsData run =
            directional::gui::run_surface_cell_diagnostics(
                mesh, field, options, true,
                [progress](const std::size_t current, const std::size_t total,
                           const std::string_view task) {
                  progress->update(current, total, task);
                });
        if (!run.network.has_value()) {
          throw std::runtime_error(
              "SurfaceCells stopped before publishing a field-aligned network (" +
              run.pipelineStage + "). Run SurfaceCells diagnostics to see where.");
        }
        result.fieldNetwork = std::move(*run.network);
        result.fieldNetworkStage =
            run.stoppedOnRequest ? std::string() : run.pipelineStage;
        result.hasFieldNetwork = true;
        const auto &network = result.fieldNetwork;
        result.message =
            "Traced " + std::to_string(network.traceCount) +
            " field-aligned traces (" + std::to_string(network.segmentCount) +
            " face segments), " + std::to_string(network.singularityPoints.rows()) +
            " singularities and " + std::to_string(network.mandatoryEdges.rows()) +
            " mandatory edges.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field-aligned network trace finished");
      return result;
    });
    set_status("Tracing the SurfaceCells field-aligned network...");
  }

  void launch_cut_graph() {
    require_mesh();
    const std::optional<directional::gui::FieldData> &source =
        cutGraphFieldSource_ == 0 ? calculatedField_ : uploadedField_;
    if (!source.has_value()) {
      throw std::runtime_error(
          cutGraphFieldSource_ == 0
              ? "Calculate a field before computing its cut graph."
              : "Load an uploaded field before computing its cut graph.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *source;
    const directional::gui::RemeshOptions options = remeshOptions_;
    enable_verbose_session_log_if_needed(options.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Starting cut graph and disc regions");

    task_ = std::async(std::launch::async, [mesh, field, options, progress]() {
      TaskResult result;
      try {
        // Both products are built during the tracing stage.
        directional::gui::SurfaceCellDiagnosticsData run =
            directional::gui::run_surface_cell_diagnostics(
                mesh, field, options, true,
                [progress](const std::size_t current, const std::size_t total,
                           const std::string_view task) {
                  progress->update(current, total, task);
                });
        if (!run.cutGraph.has_value()) {
          throw std::runtime_error(
              "SurfaceCells stopped before publishing the cut graph (" +
              run.pipelineStage + "). Run SurfaceCells diagnostics to see where.");
        }
        result.cutGraph = std::move(*run.cutGraph);
        result.cutGraphStage =
            run.stoppedOnRequest ? std::string() : run.pipelineStage;
        result.hasCutGraph = true;
        const auto &cutGraph = result.cutGraph;
        result.message =
            "Cut graph: " + std::to_string(cutGraph.cutEdges.rows()) +
            " cut edges; " + std::to_string(cutGraph.regionCount) +
            " disc regions (" + std::to_string(cutGraph.discRegionCount) +
            " proven discs), " + std::to_string(cutGraph.arcCount) +
            " graph arcs.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Cut graph and disc regions finished");
      return result;
    });
    set_status("Computing the cut graph and disc regions...");
  }

  void launch_target_size() {
    require_mesh();
    const std::optional<directional::gui::FieldData> &source =
        targetSizeFieldSource_ == 0 ? calculatedField_ : uploadedField_;
    if (!source.has_value()) {
      throw std::runtime_error(
          targetSizeFieldSource_ == 0
              ? "Calculate a field before computing the target size."
              : "Load an uploaded field before computing the target size.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *source;
    const directional::gui::RemeshOptions options = remeshOptions_;
    enable_verbose_session_log_if_needed(options.verbose);
    const auto progress = progress_;
    progress_->update(0, 100, "Computing target size and features");

    task_ = std::async(std::launch::async, [mesh, field, options, progress]() {
      TaskResult result;
      try {
        result.targetSize = directional::gui::compute_target_size(
            mesh, field, options,
            [progress](const std::size_t current, const std::size_t total,
                       const std::string_view task) {
              progress->update(current, total, task);
            });
        result.hasTargetSize = true;
        const auto &display = result.targetSize.display;
        result.message =
            "Target size: " + std::to_string(display.vertexScalars.size()) +
            " heatmaps and " + std::to_string(display.featureEdges.rows()) +
            " feature edges.";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Target size and features finished");
      return result;
    });
    set_status("Computing the target size and feature map...");
  }

  void launch_trace_streamlines() {
    require_mesh();
    const std::optional<directional::gui::FieldData> &source =
        streamlineFieldSource_ == 0 ? calculatedField_ : uploadedField_;
    if (!source.has_value()) {
      throw std::runtime_error(
          streamlineFieldSource_ == 0
              ? "Calculate a field before tracing streamlines."
              : "Load an uploaded field before tracing streamlines.");
    }

    const directional::gui::MeshData mesh = *mesh_;
    const directional::gui::FieldData field = *source;
    directional::visualization::FieldStreamlineOptions options;
    options.seedSpacing = streamlineSeedSpacing_;
    options.steps = streamlineSteps_;
    options.stepLength = streamlineStepLength_;
    const auto progress = progress_;
    progress_->update(0, 100, "Tracing field streamlines");

    task_ = std::async(std::launch::async, [mesh, field, options, progress]() {
      TaskResult result;
      try {
        directional::gui::validate_field(field, mesh.faces.rows());
        result.streamlines = directional::visualization::trace_field_streamlines(
            mesh.vertices, mesh.faces, field.raw, options);
        result.hasStreamlines = true;
        result.message =
            "Traced " + std::to_string(result.streamlines.lineCount) +
            " streamlines from " +
            std::to_string(result.streamlines.seedFaces.size()) + " seeds (" +
            std::to_string(result.streamlines.edges.rows()) + " segments).";
      } catch (const std::exception &error) {
        result.error = error.what();
      }
      progress->update(100, 100, "Field streamlines finished");
      return result;
    });
    set_status("Tracing field streamlines...");
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
      calculatedField_ = std::move(result.field);
      calculatedFieldOptions_ = std::move(result.fieldOptions);
      fieldComparison_.reset();
      comparisonContext_.reset();
      if (polyscope::hasSurfaceMesh(kInputMeshName)) {
        polyscope::getSurfaceMesh(kInputMeshName)
            ->removeQuantity(kDeviationHeatmapName, false);
      }
      calculatedFieldLabel_ = std::move(result.fieldLabel);
      visualize_calculated_field();
    }
    if (result.hasQuadMesh) {
      quadMesh_ = std::move(result.quadMesh);
      visualize_quad_mesh();
    }
    if (result.hasFieldNetwork) {
      fieldNetwork_ = std::move(result.fieldNetwork);
      fieldNetworkStage_ = std::move(result.fieldNetworkStage);
      remove_field_network_layers();
      visualize_field_network(*fieldNetwork_);
      sync_overlay_transforms();
    }
    if (result.hasTargetSize) {
      clear_target_size();
      targetSize_ = std::move(result.targetSize);
      visualize_target_size();
    }
    if (result.hasCutGraph) {
      cutGraph_ = std::move(result.cutGraph);
      cutGraphStage_ = std::move(result.cutGraphStage);
      visualize_cut_graph(*cutGraph_);
    }
    if (result.hasStreamlines) {
      streamlines_ = std::move(result.streamlines);
      visualize_streamlines();
    }
    if (result.hasSurfaceCellDiagnostics) {
      surfaceCellDiagnostics_ = std::move(result.surfaceCellDiagnostics);
      visualize_surface_cell_diagnostics();
    }
    if (result.hasComparison) {
      fieldComparison_ = std::move(result.comparison);
      comparisonContext_ = std::move(result.comparisonContext);
      directional::gui::show_field_deviation_heatmap(
          kInputMeshName, *fieldComparison_, comparisonHeatmapMaxDegrees_);
    }
    set_status(std::move(result.message));
  }

  const directional::gui::FieldData &selected_output_field() const {
    if (fieldOutputSource_ == 1) {
      if (!uploadedField_.has_value()) {
        throw std::runtime_error("There is no uploaded field to save.");
      }
      return *uploadedField_;
    }

    if (!calculatedField_.has_value()) {
      throw std::runtime_error("There is no calculated field to save.");
    }
    return *calculatedField_;
  }

  void save_field() {
    const std::filesystem::path path =
        path_from_buffer(fieldOutputPath_, "Field output");
    directional::gui::save_field(
        path, selected_field_format(fieldOutputFormat_),
        selected_output_field());
    set_status("Wrote field to " + path.string() + ".");
  }

  void save_comparison_report() {
    require_mesh();
    if (!fieldComparison_.has_value() || !comparisonContext_.has_value()) {
      throw std::runtime_error("Run a field comparison before saving a report.");
    }

    const std::filesystem::path path =
        path_from_buffer(comparisonReportPath_, "Comparison report");
    const ComparisonReportContext &context = *comparisonContext_;
    directional::fields::CrossFieldComparisonReportMetadata metadata;
    metadata.meshPath = context.meshPath;
    metadata.referencePath = context.referencePath;
    metadata.candidateLabel = context.candidateLabel;
    metadata.referenceLabel = context.referenceLabel;
    metadata.referenceFormat = context.referenceFormat;
    metadata.removeGlobalPhase = context.removeGlobalPhase;
    metadata.shapeOperatorAlignment = context.shapeOperatorAlignment;
    metadata.candidateStringParameters["method"] =
        context.candidateOptions.method ==
                directional::gui::FieldMethod::RegularizedCurvature
            ? "regularized_curvature"
            : "smooth_power";
    metadata.candidateBooleanParameters["normalize_directions"] =
        context.candidateOptions.normalizeDirections;
    metadata.candidateBooleanParameters["preserve_boundary"] =
        context.candidateOptions.preserveBoundary;
    metadata.candidateBooleanParameters["preserve_sharp_features"] =
        context.candidateOptions.preserveSharpFeatures;
    metadata.candidateBooleanParameters["feature_aware_corner_normals"] =
        context.candidateOptions.useFeatureAwareCornerNormals;
    metadata.candidateNumericParameters["proxy_fidelity_weight"] =
        context.candidateOptions.proxyFidelityWeight;
    metadata.candidateNumericParameters["proxy_smoothness_weight"] =
        context.candidateOptions.proxySmoothnessWeight;
    metadata.candidateNumericParameters["field_smoothness_weight"] =
        context.candidateOptions.fieldSmoothnessWeight;
    metadata.candidateNumericParameters["curvature_alignment_weight"] =
        context.candidateOptions.curvatureAlignmentWeight;
    metadata.candidateNumericParameters["boundary_alignment_weight"] =
        context.candidateOptions.boundaryAlignmentWeight;
    metadata.candidateNumericParameters["sharp_feature_alignment_weight"] =
        context.candidateOptions.sharpFeatureAlignmentWeight;
    metadata.candidateNumericParameters["sharp_feature_angle_degrees"] =
        context.candidateOptions.sharpFeatureAngleDegrees;
    metadata.candidateNumericParameters["minimum_confidence"] =
        context.candidateOptions.minimumConfidence;
    metadata.candidateNumericParameters["confidence_exponent"] =
        context.candidateOptions.confidenceExponent;
    metadata.candidateNumericParameters["curvature_smoothing_iterations"] =
        static_cast<double>(
            context.candidateOptions.curvatureSmoothingIterations);

    const directional::fields::CrossFieldComparisonReportPaths paths =
        directional::fields::write_cross_field_comparison_report(
            path, mesh_->vertices, mesh_->faces,
            fieldComparison_->details, metadata,
            static_cast<double>(comparisonHeatmapMaxDegrees_));
    copy_path_to_buffer(paths.json, comparisonReportPath_);
    set_status("Wrote comparison report bundle: " + paths.json.string() +
               ".");
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

  static std::string selected_field_format_label(const int index) {
    switch (index) {
    case 1:
      return "rawfield";
    case 2:
      return "crossfield_neurcross";
    case 3:
      return "rosy";
    default:
      return "auto";
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
      set_status("Selected uploaded field: " + path.string() + ".");
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
            {"Select uploaded field",
             initialPath,
             {{"Directional field files",
               {"*.rawfield", "*.rosy", "*.vec", "*.txt"}}}});

    if (result.selected()) {
      apply_selected_file(FilePickerTarget::Field, result.path);
    } else if (result.status != directional::gui::FileDialogStatus::Cancelled) {
      open_fallback_picker(FilePickerTarget::Field, "Select uploaded field",
                           initialPath, {".rawfield", ".rosy", ".vec", ".txt"},
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
    update_field_glyph_positions(kCalculatedFieldGlyphName,
                                 calculatedFieldGlyph_);
    update_field_glyph_positions(kUploadedFieldGlyphName,
                                 uploadedFieldGlyph_);
    sync_overlay_transforms();
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
              "Preserve boundary vertices in proxy mesh",
              &fieldOptions_.preserveBoundary);
          ImGui::Checkbox(
              "Preserve sharp-feature vertices in proxy mesh",
              &fieldOptions_.preserveSharpFeatures);
          ImGui::Checkbox(
              "Use feature-aware corner normals for curvature",
              &fieldOptions_.useFeatureAwareCornerNormals);

          draw_labeled_full_width_control(
              "Sharp-feature angle (degrees; typical: 30 to 80)", [this] {
                ImGui::InputDouble("##sharp_feature_angle",
                                   &fieldOptions_.sharpFeatureAngleDegrees,
                                   1.0, 5.0, "%.6g");
              });

          draw_labeled_full_width_control(
              "Field smoothness weight (> 0; typical: 0.1 to 10)", [this] {
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
              "Boundary alignment weight (>= 0; typical: 0.1 to 10)", [this] {
                ImGui::InputDouble("##boundary_alignment",
                                   &fieldOptions_.boundaryAlignmentWeight, 0.1,
                                   1.0, "%.6g");
              });

          draw_labeled_full_width_control(
              "Sharp-feature alignment weight (>= 0; typical: 0.1 to 10)",
              [this] {
                ImGui::InputDouble(
                    "##sharp_feature_alignment",
                    &fieldOptions_.sharpFeatureAlignmentWeight, 0.1, 1.0,
                    "%.6g");
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
      ImGui::BeginDisabled(
          isBusy ||
          (!calculatedField_.has_value() && !uploadedField_.has_value()));
      if (ImGui::Button("Refresh field displays")) {
        guarded_action([this] { visualize_fields(); });
      }
      ImGui::EndDisabled();

      if (!calculatedFieldLabel_.empty()) {
        text_colored_wrapped(ImVec4(0.15F, 0.65F, 1.0F, 1.0F),
                             calculatedFieldLabel_);
      }
    }

    if (ImGui::CollapsingHeader("4. Uploaded field",
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

      const char *formats[] = {"Auto", "RawField",
                               "CrossField / NeurCross", "RoSy"};
      draw_labeled_full_width_control("Uploaded field format",
                                      [this, &formats] {
                                        ImGui::Combo("##input_field_format",
                                                     &fieldInputFormat_,
                                                     formats, 4);
                                      });

      ImGui::BeginDisabled(isBusy || !mesh_.has_value());
      if (ImGui::Button("Load uploaded field")) {
        guarded_action([this] { load_uploaded_field(); });
      }
      ImGui::SameLine();
      if (ImGui::Button("Remesh using uploaded field")) {
        guarded_action([this] {
          load_uploaded_field();
          launch_remesh_loaded_field();
        });
      }
      ImGui::EndDisabled();

      if (!uploadedFieldLabel_.empty()) {
        text_colored_wrapped(ImVec4(1.0F, 0.45F, 0.15F, 1.0F),
                             uploadedFieldLabel_);
      }
      ImGui::TextWrapped(
          "The uploaded field is shared by remeshing and field comparison.");
    }

    if (ImGui::CollapsingHeader("5. Compare fields")) {
      ImGui::TextWrapped(
          "Compare the calculated field against the uploaded field from "
          "section 4.");

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

      ImGui::BeginDisabled(
          isBusy || !mesh_.has_value() || !calculatedField_.has_value() ||
          !uploadedField_.has_value());
      if (ImGui::Button("Compare calculated to uploaded")) {
        guarded_action([this] { launch_compare_fields(); });
      }
      ImGui::EndDisabled();

      if (fieldComparison_.has_value()) {
        ImGui::Text("Mean: %.3f deg, median: %.3f deg",
                    fieldComparison_->meanDegrees,
                    fieldComparison_->medianDegrees);
        ImGui::Text("Area-weighted mean/RMS: %.3f / %.3f deg",
                    fieldComparison_->areaWeightedMeanDegrees,
                    fieldComparison_->areaWeightedRmsDegrees);
        ImGui::Text("p95: %.3f deg, p99: %.3f deg",
                    fieldComparison_->p95Degrees,
                    fieldComparison_->p99Degrees);
        ImGui::Text("Primary q4 chordal objective: %.8g",
                    fieldComparison_->q4WeightedMeanError);
        ImGui::Text("> %.3f deg: %lld faces, %.2f%% area, %d components",
                    comparisonHighErrorThresholdDegrees_,
                    static_cast<long long>(
                        fieldComparison_->highErrorFaceCount),
                    100.0 * fieldComparison_->highErrorAreaFraction,
                    fieldComparison_->highErrorComponentCount);
        ImGui::Text("Global phase: %.3f deg",
                    fieldComparison_->globalPhaseDegrees);
        if (fieldComparison_->hasTopologyDiagnostics) {
          ImGui::Text("Singularities candidate/reference: %lld / %lld",
                      static_cast<long long>(
                          fieldComparison_->candidateSingularityCount),
                      static_cast<long long>(
                          fieldComparison_->referenceSingularityCount));
          ImGui::Text(
              "Singularity vertex/index mismatches: %lld (%.2f%% area)",
              static_cast<long long>(
                  fieldComparison_->singularityMismatchVertexCount),
              100.0 *
                  fieldComparison_->singularityMismatchAreaFraction);
        } else {
          ImGui::TextUnformatted("Singularity diagnostics unavailable.");
        }
        if (fieldComparison_->hasShapeOperatorAlignment) {
          ImGui::Text("Shape alignment candidate: mean %.3f deg, p95 %.3f deg, energy %.6g",
                      fieldComparison_->firstShapeAlignmentMeanDegrees,
                      fieldComparison_->firstShapeAlignmentP95Degrees,
                      fieldComparison_->firstShapeAlignmentEnergy);
          ImGui::Text("Shape alignment reference: mean %.3f deg, p95 %.3f deg, energy %.6g",
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

      ImGui::Spacing();
      draw_labeled_full_width_control(
          "Comparison report (.fieldcmp.json)", [this] {
            ImGui::InputText("##comparison_report_path",
                             comparisonReportPath_.data(),
                             comparisonReportPath_.size());
          });
      ImGui::BeginDisabled(isBusy || !mesh_.has_value() ||
                          !fieldComparison_.has_value());
      if (ImGui::Button("Save comparison report")) {
        guarded_action([this] { save_comparison_report(); });
      }
      ImGui::EndDisabled();
      ImGui::TextWrapped(
          "Writes a versioned JSON summary plus per-face CSV and PLY heatmap "
          "sidecars for comparing parameter sweeps between runs.");
    }

    if (ImGui::CollapsingHeader("6. Field-aligned curve network")) {
      ImGui::TextWrapped(
          "Traces the SurfaceCells A2a network from the field's singularities: "
          "traces, mandatory boundary and feature edges, and singularities "
          "colored by index. It is shown even when a later SurfaceCells stage "
          "rejects.");
      const char *networkSources[] = {"Calculated field", "Uploaded field"};
      draw_labeled_full_width_control("Network field source",
                                      [this, &networkSources] {
                                        ImGui::Combo("##network_field_source",
                                                     &fieldNetworkSource_,
                                                     networkSources, 2);
                                      });
      const bool networkFieldAvailable =
          fieldNetworkSource_ == 0 ? calculatedField_.has_value()
                                   : uploadedField_.has_value();
      ImGui::BeginDisabled(isBusy || !mesh_.has_value() ||
                           !networkFieldAvailable);
      if (ImGui::Button("Trace field-aligned network")) {
        guarded_action([this] { launch_trace_field_network(); });
      }
      ImGui::EndDisabled();
      if (fieldNetwork_.has_value()) {
        ImGui::Text("Traces: %zu  Segments: %zu", fieldNetwork_->traceCount,
                    fieldNetwork_->segmentCount);
        ImGui::Text("Singularities: %d  Mandatory edges: %d",
                    static_cast<int>(fieldNetwork_->singularityPoints.rows()),
                    static_cast<int>(fieldNetwork_->mandatoryEdges.rows()));
        if (!fieldNetworkStage_.empty()) {
          ImGui::TextWrapped("SurfaceCells rejected later at: %s",
                             fieldNetworkStage_.c_str());
        }
      }
    }

    if (ImGui::CollapsingHeader("7. SurfaceCells diagnostics")) {
      ImGui::TextWrapped(
          "Runs the SurfaceCells backend and shows what it publishes, even "
          "when a later stage rejects: topology regions, isolation sheets and "
          "seams (A0), the field-aligned curve network (A2a), the traced quad "
          "cells (A4), and where the run stopped (orange).");
      const char *diagnosticsSources[] = {"Calculated field", "Uploaded field"};
      draw_labeled_full_width_control("Diagnostics field source",
                                      [this, &diagnosticsSources] {
                                        ImGui::Combo("##diagnostics_field_source",
                                                     &diagnosticsFieldSource_,
                                                     diagnosticsSources, 2);
                                      });
      const bool diagnosticsFieldAvailable =
          diagnosticsFieldSource_ == 0 ? calculatedField_.has_value()
                                       : uploadedField_.has_value();
      ImGui::Checkbox("Stop after quad tracing (faster)",
                      &diagnosticsStopAfterTracing_);
      ImGui::BeginDisabled(isBusy || !mesh_.has_value() ||
                           !diagnosticsFieldAvailable);
      if (ImGui::Button("Run SurfaceCells diagnostics")) {
        guarded_action([this] { launch_surface_cell_diagnostics(); });
      }
      ImGui::EndDisabled();
      if (surfaceCellDiagnostics_.has_value()) {
        const auto &diagnostics = *surfaceCellDiagnostics_;
        if (diagnostics.regions.has_value()) {
          ImGui::Text("Regions: %zu  Sheets: %zu  Seam edges: %d",
                      diagnostics.regions->regionCount,
                      diagnostics.regions->sheetCount,
                      static_cast<int>(diagnostics.regions->seamEdges.rows()));
        } else {
          ImGui::TextWrapped("Topology regions were not published.");
        }
        if (diagnostics.network.has_value()) {
          ImGui::Text("Traces: %zu  Segments: %zu",
                      diagnostics.network->traceCount,
                      diagnostics.network->segmentCount);
          ImGui::Text(
              "Singularities: %d  Mandatory edges: %d",
              static_cast<int>(diagnostics.network->singularityPoints.rows()),
              static_cast<int>(diagnostics.network->mandatoryEdges.rows()));
        } else {
          ImGui::TextWrapped("The field-aligned network was not published.");
        }
        const auto &tracing = diagnostics.tracing;
        if (tracing.cellCount > 0U) {
          ImGui::Text("Traced cells: %zu", tracing.cellCount);
        }
        if (diagnostics.stoppedOnRequest) {
          ImGui::TextWrapped("Stopped after quad tracing, as requested.");
        } else if (!diagnostics.pipelineProduced) {
          ImGui::TextWrapped("SurfaceCells stopped at: %s",
                             diagnostics.pipelineStage.c_str());
          if (tracing.has_stop_location()) {
            ImGui::Text("Highlighted: %d faces, %d edges, %d vertices",
                        static_cast<int>(tracing.stopFaces.rows()),
                        static_cast<int>(tracing.stopEdges.rows()),
                        static_cast<int>(tracing.stopVertices.rows()));
          } else {
            ImGui::TextWrapped("The stage reported no mesh location.");
          }
          for (const std::string &note : tracing.stopNotes) {
            // BulletText does not wrap; notes can be long stage strings.
            ImGui::Bullet();
            ImGui::SameLine();
            ImGui::TextWrapped("%s", note.c_str());
          }
        }
      }
    }

    if (ImGui::CollapsingHeader("8. Field streamlines")) {
      ImGui::TextWrapped(
          "Traces streamlines of the cross field from evenly spaced seeds. "
          "Each seed starts one line per direction family; lengths are in "
          "average edge lengths.");
      const char *streamlineSources[] = {"Calculated field", "Uploaded field"};
      draw_labeled_full_width_control("Streamline field source",
                                      [this, &streamlineSources] {
                                        ImGui::Combo("##streamline_field_source",
                                                     &streamlineFieldSource_,
                                                     streamlineSources, 2);
                                      });
      draw_labeled_full_width_control(
          "Seed spacing (0 seeds every face)", [this] {
            ImGui::SliderFloat("##streamline_spacing", &streamlineSeedSpacing_,
                               0.0F, 10.0F, "%.2f edges");
          });
      draw_labeled_full_width_control("Steps (line length = steps x step)",
                                      [this] {
                                        ImGui::InputInt("##streamline_steps",
                                                        &streamlineSteps_, 10, 100);
                                        streamlineSteps_ =
                                            std::clamp(streamlineSteps_, 1, 5000);
                                      });
      draw_labeled_full_width_control("Step length", [this] {
        ImGui::SliderFloat("##streamline_step", &streamlineStepLength_, 0.05F,
                           2.0F, "%.2f edges");
      });
      draw_labeled_full_width_control("Line thickness", [this] {
        if (ImGui::SliderFloat("##streamline_thickness", &streamlineThickness_,
                               0.005F, 0.3F, "%.3f edges")) {
          apply_streamline_style();
        }
      });
      const char *colorModes[] = {"Random per line", "Direction family"};
      draw_labeled_full_width_control("Line colors", [this, &colorModes] {
        if (ImGui::Combo("##streamline_colors", &streamlineColorMode_,
                         colorModes, 2)) {
          apply_streamline_style();
        }
      });
      const bool streamlineFieldAvailable =
          streamlineFieldSource_ == 0 ? calculatedField_.has_value()
                                      : uploadedField_.has_value();
      ImGui::BeginDisabled(isBusy || !mesh_.has_value() ||
                           !streamlineFieldAvailable);
      if (ImGui::Button("Trace streamlines")) {
        guarded_action([this] { launch_trace_streamlines(); });
      }
      ImGui::EndDisabled();
      if (streamlines_.has_value()) {
        ImGui::Text("Seeds: %d  Lines: %zu  Segments: %d",
                    static_cast<int>(streamlines_->seedFaces.size()),
                    streamlines_->lineCount,
                    static_cast<int>(streamlines_->edges.rows()));
      }
    }

    if (ImGui::CollapsingHeader("9. Cut graph and disc regions")) {
      ImGui::TextWrapped(
          "Shows how SurfaceCells cuts the surface into discs before quad "
          "tracing: the cut-graph edges (A2a'), the embedded graph arcs "
          "colored by kind, and each face's disc region (A2b).");
      const char *cutGraphSources[] = {"Calculated field", "Uploaded field"};
      draw_labeled_full_width_control("Cut graph field source",
                                      [this, &cutGraphSources] {
                                        ImGui::Combo("##cut_graph_field_source",
                                                     &cutGraphFieldSource_,
                                                     cutGraphSources, 2);
                                      });
      const bool cutGraphFieldAvailable =
          cutGraphFieldSource_ == 0 ? calculatedField_.has_value()
                                    : uploadedField_.has_value();
      ImGui::BeginDisabled(isBusy || !mesh_.has_value() || !cutGraphFieldAvailable);
      if (ImGui::Button("Show cut graph and disc regions")) {
        guarded_action([this] { launch_cut_graph(); });
      }
      ImGui::EndDisabled();
      if (cutGraph_.has_value()) {
        if (cutGraph_->hasCutGraph) {
          ImGui::Text("Cut edges: %d", static_cast<int>(cutGraph_->cutEdges.rows()));
        } else {
          ImGui::TextWrapped("The cut graph was not published.");
        }
        if (cutGraph_->hasTopologyPlan) {
          ImGui::Text("Disc regions: %zu (%zu proven discs, %zu singularity-free)",
                      cutGraph_->regionCount, cutGraph_->discRegionCount,
                      cutGraph_->regularRegionCount);
          ImGui::Text("Graph arcs: %zu  Faces split by traces: %zu",
                      cutGraph_->arcCount, cutGraph_->splitFaceCount);
          ImGui::TextWrapped(
              "Disc region colors: -1 is no region, -2 a face that traces split "
              "among regions. Arc kind: 0 mandatory, 1 trace, 2 cut.");
        } else {
          ImGui::TextWrapped("The topology plan was not published.");
        }
        if (!cutGraphStage_.empty()) {
          ImGui::TextWrapped("SurfaceCells rejected later at: %s",
                             cutGraphStage_.c_str());
        }
      }
    }

    if (ImGui::CollapsingHeader("10. Target size and feature heatmaps")) {
      ImGui::TextWrapped(
          "Shows the SurfaceCells target edge length and the inputs behind it "
          "(salience, curvature, thickness and feature density) as heatmaps, "
          "plus the detected feature edges. The run stops after the metric "
          "stage, so it is quick. Uses the target edge-length ratio from Remesh "
          "options.");
      const char *targetSizeSources[] = {"Calculated field", "Uploaded field"};
      draw_labeled_full_width_control("Target size field source",
                                      [this, &targetSizeSources] {
                                        ImGui::Combo("##target_size_field_source",
                                                     &targetSizeFieldSource_,
                                                     targetSizeSources, 2);
                                      });
      const bool targetSizeFieldAvailable =
          targetSizeFieldSource_ == 0 ? calculatedField_.has_value()
                                      : uploadedField_.has_value();
      ImGui::BeginDisabled(isBusy || !mesh_.has_value() || !targetSizeFieldAvailable);
      if (ImGui::Button("Show target size and features")) {
        guarded_action([this] { launch_target_size(); });
      }
      ImGui::EndDisabled();
      if (targetSize_.has_value()) {
        const auto &display = targetSize_->display;
        const auto &fields = display.vertexScalars;
        if (!fields.empty()) {
          draw_labeled_full_width_control("Heatmap", [this, &fields] {
            const std::string current =
                fields[static_cast<std::size_t>(targetSizeScalar_)].name;
            if (ImGui::BeginCombo("##target_size_heatmap", current.c_str())) {
              for (int i = 0; i < static_cast<int>(fields.size()); ++i) {
                const bool selected = i == targetSizeScalar_;
                if (ImGui::Selectable(fields[static_cast<std::size_t>(i)].name.c_str(),
                                      selected)) {
                  targetSizeScalar_ = i;
                  show_selected_target_scalar();
                }
              }
              ImGui::EndCombo();
            }
          });
          const auto &field = fields[static_cast<std::size_t>(targetSizeScalar_)];
          ImGui::Text("Range: %.6g to %.6g", field.values.minCoeff(),
                      field.values.maxCoeff());
          if (field.nonFiniteCount > 0) {
            ImGui::TextWrapped("%d infinite values are shown at the maximum.",
                               field.nonFiniteCount);
          }
        } else {
          ImGui::TextWrapped("No per-vertex target-size values were published.");
        }
        if (display.hasTargetSize) {
          ImGui::Text("Resolved surface error: %.6g", display.resolvedSurfaceError);
        }
        if (display.hasFeatureMap) {
          ImGui::Text("Feature edges: %d (class: 1 boundary, 2 soft, 3 hard, 4 "
                      "non-manifold)",
                      static_cast<int>(display.featureEdges.rows()));
        }
        for (const std::string &note : display.notes) {
          ImGui::Bullet();
          ImGui::SameLine();
          ImGui::TextWrapped("%s", note.c_str());
        }
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
      const char *fieldSources[] = {"Calculated field", "Uploaded field"};
      draw_labeled_full_width_control("Field output source",
                                      [this, &fieldSources] {
                                        ImGui::Combo("##field_output_source",
                                                     &fieldOutputSource_,
                                                     fieldSources, 2);
                                      });
      const char *formats[] = {"Auto", "RawField",
                               "CrossField / NeurCross", "RoSy"};
      draw_labeled_full_width_control("Output field format", [this, &formats] {
        ImGui::Combo("##output_field_format", &fieldOutputFormat_, formats, 4);
      });
      const bool selectedFieldAvailable =
          fieldOutputSource_ == 0 ? calculatedField_.has_value()
                                  : uploadedField_.has_value();
      ImGui::BeginDisabled(isBusy || !selectedFieldAvailable);
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
      text_colored_wrapped(ImVec4(1.0F, 0.35F, 0.35F, 1.0F), error_);
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
