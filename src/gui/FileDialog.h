#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace directional::gui {

/**
 * @brief A named group of filename patterns for a native open dialog.
 *
 * Patterns use shell-style syntax such as `*.obj` and `*.off`.
 */
struct FileDialogFilter {
  std::string name;
  std::vector<std::string> patterns;
};

/** @brief Parameters for opening one file with the platform-native dialog. */
struct FileDialogOptions {
  std::string title;
  std::filesystem::path initialPath;
  std::vector<FileDialogFilter> filters;
};

enum class FileDialogStatus {
  Selected,
  Cancelled,
  Unavailable,
  Failed,
};

/** @brief Result returned by the platform-native file dialog. */
struct FileDialogResult {
  FileDialogStatus status = FileDialogStatus::Unavailable;
  std::filesystem::path path;
  std::string message;

  [[nodiscard]] bool selected() const noexcept {
    return status == FileDialogStatus::Selected;
  }
};

/**
 * @brief Opens the operating system's native single-file open dialog.
 *
 * The implementation is selected at build time:
 * - Windows: IFileOpenDialog
 * - macOS: NSOpenPanel
 * - Linux: XDG Desktop Portal through GIO/GDBus
 *
 * A result of Unavailable or Failed allows the caller to use the ImGui picker
 * as a fallback. Cancellation is reported separately and must not trigger the
 * fallback dialog.
 */
FileDialogResult open_native_file_dialog(const FileDialogOptions &options);

} // namespace directional::gui
