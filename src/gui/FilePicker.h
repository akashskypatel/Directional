#pragma once

#include <array>
#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace directional::gui {

/**
 * @brief Dependency-free ImGui file picker backed by std::filesystem.
 *
 * The picker is modal and supports directory navigation, Windows drive
 * selection, extension filtering, and double-click selection.
 */
class FilePicker {
public:
  /**
   * @brief Opens the picker.
   *
   * @param title Modal window title.
   * @param initialPath Existing file/directory or a path whose parent should
   *        be used as the starting directory.
   * @param extensions Allowed lowercase or uppercase extensions, with or
   *        without the leading dot. An empty list accepts every file.
   */
  void open(std::string title, const std::filesystem::path &initialPath,
            std::vector<std::string> extensions);

  /**
   * @brief Draws the modal and returns a selected file once confirmed.
   */
  std::optional<std::filesystem::path> draw();

  /** @brief Returns whether the picker is open or queued to open. */
  bool active() const noexcept;

private:
  struct Entry {
    std::filesystem::path path;
    bool directory = false;
  };

  static constexpr std::size_t kPathBufferSize = 2048;

  bool openRequested_ = false;
  bool active_ = false;
  std::string popupId_;
  std::filesystem::path currentDirectory_;
  std::vector<std::string> extensions_;
  std::vector<std::filesystem::path> roots_;
  std::vector<Entry> entries_;
  std::array<char, kPathBufferSize> directoryBuffer_{};
  std::array<char, kPathBufferSize> selectionBuffer_{};
  std::string error_;

  void navigate_to(const std::filesystem::path &directory);
  void refresh_entries();
  void select_path(const std::filesystem::path &path);
  bool matches_filter(const std::filesystem::path &path) const;
  std::optional<std::filesystem::path> confirm_selection();
};

} // namespace directional::gui
