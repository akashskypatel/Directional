#include "FilePicker.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <system_error>
#include <utility>

#include <imgui.h>

namespace directional::gui {
namespace {

std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

template <std::size_t Size>
void copy_to_buffer(const std::string &value, std::array<char, Size> &buffer) {
  const std::size_t count = std::min(value.size(), buffer.size() - 1);
  std::memcpy(buffer.data(), value.data(), count);
  buffer[count] = '\0';
}

std::vector<std::filesystem::path> filesystem_roots() {
  std::vector<std::filesystem::path> roots;
#ifdef _WIN32
  for (char letter = 'A'; letter <= 'Z'; ++letter) {
    const std::filesystem::path root(std::string(1, letter) + ":\\");
    std::error_code error;
    if (std::filesystem::exists(root, error) && !error) {
      roots.push_back(root);
    }
  }
#else
  roots.emplace_back("/");
#endif
  return roots;
}

} // namespace

void FilePicker::open(std::string title,
                      const std::filesystem::path &initialPath,
                      std::vector<std::string> extensions) {
  popupId_ = std::move(title) + "##directional_file_picker";
  extensions_.clear();
  extensions_.reserve(extensions.size());
  for (std::string extension : extensions) {
    extension = lowercase(std::move(extension));
    if (!extension.empty() && extension.front() != '.') {
      extension.insert(extension.begin(), '.');
    }
    extensions_.push_back(std::move(extension));
  }

  std::error_code error;
  std::filesystem::path initialDirectory;
  if (!initialPath.empty() &&
      std::filesystem::is_directory(initialPath, error) && !error) {
    initialDirectory = initialPath;
  } else if (!initialPath.empty()) {
    initialDirectory = initialPath.parent_path();
  }
  if (initialDirectory.empty() ||
      !std::filesystem::is_directory(initialDirectory, error) || error) {
    error.clear();
    initialDirectory = std::filesystem::current_path(error);
  }
  if (error || initialDirectory.empty()) {
    initialDirectory = ".";
  }

  roots_ = filesystem_roots();
  currentDirectory_.clear();
  selectionBuffer_.fill('\0');
  error_.clear();
  navigate_to(initialDirectory);

  error.clear();
  if (!initialPath.empty() &&
      std::filesystem::is_regular_file(initialPath, error) && !error &&
      matches_filter(initialPath)) {
    std::filesystem::path selected =
        std::filesystem::weakly_canonical(initialPath, error);
    if (error) {
      error.clear();
      selected = std::filesystem::absolute(initialPath, error);
    }
    select_path(error ? initialPath : selected);
  }

  openRequested_ = true;
  active_ = true;
}

bool FilePicker::active() const noexcept {
  return active_ || openRequested_;
}

void FilePicker::navigate_to(const std::filesystem::path &directory) {
  std::filesystem::path requested = directory;
  if (requested.is_relative() && !currentDirectory_.empty()) {
    requested = currentDirectory_ / requested;
  }

  std::error_code error;
  std::filesystem::path normalized =
      std::filesystem::weakly_canonical(requested, error);
  if (error) {
    error.clear();
    normalized = std::filesystem::absolute(requested, error);
  }
  if (error || normalized.empty() ||
      !std::filesystem::is_directory(normalized, error) || error) {
    error_ = "Cannot open directory: " + requested.string();
    return;
  }

  currentDirectory_ = std::move(normalized);
  copy_to_buffer(currentDirectory_.string(), directoryBuffer_);
  selectionBuffer_.fill('\0');
  error_.clear();
  refresh_entries();
}

void FilePicker::refresh_entries() {
  entries_.clear();

  std::error_code error;
  std::filesystem::directory_iterator iterator(
      currentDirectory_,
      std::filesystem::directory_options::skip_permission_denied, error);
  const std::filesystem::directory_iterator end;
  if (error) {
    error_ = "Cannot read directory: " + currentDirectory_.string();
    return;
  }

  while (iterator != end) {
    const std::filesystem::directory_entry &entry = *iterator;
    std::error_code typeError;
    const bool isDirectory = entry.is_directory(typeError);
    if (!typeError && (isDirectory || matches_filter(entry.path()))) {
      entries_.push_back({entry.path(), isDirectory});
    }

    iterator.increment(error);
    if (error) {
      error_ = "Stopped reading directory after a filesystem error.";
      break;
    }
  }

  std::sort(entries_.begin(), entries_.end(),
            [](const Entry &left, const Entry &right) {
              if (left.directory != right.directory) {
                return left.directory > right.directory;
              }
              return lowercase(left.path.filename().string()) <
                     lowercase(right.path.filename().string());
            });
}

void FilePicker::select_path(const std::filesystem::path &path) {
  copy_to_buffer(path.string(), selectionBuffer_);
  error_.clear();
}

bool FilePicker::matches_filter(const std::filesystem::path &path) const {
  if (extensions_.empty()) {
    return true;
  }
  const std::string extension = lowercase(path.extension().string());
  return std::find(extensions_.begin(), extensions_.end(), extension) !=
         extensions_.end();
}

std::optional<std::filesystem::path> FilePicker::confirm_selection() {
  std::filesystem::path selected(selectionBuffer_.data());
  if (selected.empty()) {
    error_ = "Select a file first.";
    return std::nullopt;
  }
  if (selected.is_relative()) {
    selected = currentDirectory_ / selected;
  }

  std::error_code error;
  if (std::filesystem::is_directory(selected, error) && !error) {
    navigate_to(selected);
    return std::nullopt;
  }
  if (error || !std::filesystem::is_regular_file(selected, error) || error) {
    error_ = "Selected path is not a readable file.";
    return std::nullopt;
  }
  if (!matches_filter(selected)) {
    error_ = "Selected file does not match the active extension filter.";
    return std::nullopt;
  }

  return selected;
}

std::optional<std::filesystem::path> FilePicker::draw() {
  if (openRequested_) {
    ImGui::OpenPopup(popupId_.c_str());
    openRequested_ = false;
  }
  if (!active_) {
    return std::nullopt;
  }

  std::optional<std::filesystem::path> result;
  bool keepOpen = true;
  ImGui::SetNextWindowSize(ImVec2(760.0F, 520.0F), ImGuiCond_Appearing);
  if (ImGui::BeginPopupModal(popupId_.c_str(), &keepOpen,
                             ImGuiWindowFlags_NoCollapse)) {
    if (!roots_.empty()) {
      const std::string currentRoot = currentDirectory_.root_path().string();
      if (ImGui::BeginCombo("Root", currentRoot.c_str())) {
        for (const std::filesystem::path &root : roots_) {
          const std::string label = root.string();
          const bool selected = root == currentDirectory_.root_path();
          if (ImGui::Selectable(label.c_str(), selected)) {
            navigate_to(root);
          }
          if (selected) {
            ImGui::SetItemDefaultFocus();
          }
        }
        ImGui::EndCombo();
      }
    }

    const std::filesystem::path parent = currentDirectory_.parent_path();
    ImGui::BeginDisabled(parent.empty() || parent == currentDirectory_);
    if (ImGui::Button("Up")) {
      navigate_to(parent);
    }
    ImGui::EndDisabled();
    ImGui::SameLine();
    if (ImGui::Button("Refresh")) {
      refresh_entries();
    }
    ImGui::SameLine();
    ImGui::SetNextItemWidth(-55.0F);
    ImGui::InputText("##directory", directoryBuffer_.data(),
                     directoryBuffer_.size());
    ImGui::SameLine();
    if (ImGui::Button("Go")) {
      navigate_to(std::filesystem::path(directoryBuffer_.data()));
    }

    std::string filterLabel = "Files";
    if (!extensions_.empty()) {
      filterLabel += ": ";
      for (std::size_t index = 0; index < extensions_.size(); ++index) {
        if (index != 0) {
          filterLabel += ", ";
        }
        filterLabel += "*" + extensions_[index];
      }
    }
    ImGui::TextUnformatted(filterLabel.c_str());
    ImGui::Separator();

    const float footerHeight =
        ImGui::GetFrameHeightWithSpacing() * 3.0F +
        ImGui::GetStyle().ItemSpacing.y;
    std::optional<std::filesystem::path> pendingNavigation;
    if (ImGui::BeginChild("##file_entries", ImVec2(0.0F, -footerHeight),
                          true)) {
      for (const Entry &entry : entries_) {
        const std::string filename = entry.path.filename().string();
        const std::string label =
            (entry.directory ? "[Directory] " : "[File] ") + filename;
        const bool selected =
            selectionBuffer_[0] != '\0' &&
            std::filesystem::path(selectionBuffer_.data()) == entry.path;
        if (ImGui::Selectable(label.c_str(), selected,
                              ImGuiSelectableFlags_AllowDoubleClick)) {
          select_path(entry.path);
          if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
            if (entry.directory) {
              pendingNavigation = entry.path;
            } else {
              result = entry.path;
              active_ = false;
              ImGui::CloseCurrentPopup();
            }
          }
        }
      }
    }
    ImGui::EndChild();
    if (pendingNavigation.has_value()) {
      navigate_to(*pendingNavigation);
    }

    ImGui::TextUnformatted("Selected file");
    ImGui::SetNextItemWidth(-1.0F);
    ImGui::InputText("##selected_file", selectionBuffer_.data(),
                     selectionBuffer_.size());

    if (!error_.empty()) {
      ImGui::TextColored(ImVec4(1.0F, 0.35F, 0.35F, 1.0F), "%s",
                         error_.c_str());
    } else {
      ImGui::Spacing();
    }

    if (ImGui::Button("Open")) {
      result = confirm_selection();
      if (result.has_value()) {
        active_ = false;
        ImGui::CloseCurrentPopup();
      }
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel")) {
      active_ = false;
      ImGui::CloseCurrentPopup();
    }

    ImGui::EndPopup();
  }

  if (!keepOpen || !ImGui::IsPopupOpen(popupId_.c_str())) {
    active_ = false;
  }
  return result;
}

} // namespace directional::gui
