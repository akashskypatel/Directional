#include "FileDialog.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <shobjidl.h>

#include <iomanip>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

namespace directional::gui {
namespace {

std::wstring utf8_to_wide(const std::string &value) {
  if (value.empty()) {
    return {};
  }

  const int size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                                       value.data(),
                                       static_cast<int>(value.size()), nullptr,
                                       0);
  if (size <= 0) {
    return std::wstring(value.begin(), value.end());
  }

  std::wstring result(static_cast<std::size_t>(size), L'\0');
  MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(),
                      static_cast<int>(value.size()), result.data(), size);
  return result;
}

std::string hresult_text(const HRESULT result) {
  std::ostringstream stream;
  stream << "HRESULT 0x" << std::uppercase << std::hex << std::setw(8)
         << std::setfill('0') << static_cast<unsigned long>(result);
  return stream.str();
}

std::filesystem::path initial_directory(
    const std::filesystem::path &initialPath) {
  if (initialPath.empty()) {
    return {};
  }

  std::error_code error;
  if (std::filesystem::is_directory(initialPath, error) && !error) {
    return initialPath;
  }
  return initialPath.parent_path();
}

void configure_initial_location(IFileOpenDialog *dialog,
                                const std::filesystem::path &initialPath) {
  const std::filesystem::path directory = initial_directory(initialPath);
  if (!directory.empty()) {
    IShellItem *folder = nullptr;
    if (SUCCEEDED(SHCreateItemFromParsingName(
            directory.c_str(), nullptr, IID_PPV_ARGS(&folder)))) {
      dialog->SetFolder(folder);
      folder->Release();
    }
  }

  std::error_code error;
  if (!initialPath.empty() &&
      std::filesystem::is_regular_file(initialPath, error) && !error) {
    dialog->SetFileName(initialPath.filename().c_str());
  }
}

} // namespace

FileDialogResult open_native_file_dialog(const FileDialogOptions &options) {
  const HRESULT initializeResult =
      CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
  const bool uninitialize = SUCCEEDED(initializeResult);
  if (FAILED(initializeResult) && initializeResult != RPC_E_CHANGED_MODE) {
    return {FileDialogStatus::Failed, {},
            "Unable to initialize COM for the Windows file dialog (" +
                hresult_text(initializeResult) + ")."};
  }

  IFileOpenDialog *dialog = nullptr;
  HRESULT result = CoCreateInstance(CLSID_FileOpenDialog, nullptr,
                                    CLSCTX_INPROC_SERVER,
                                    IID_PPV_ARGS(&dialog));
  if (FAILED(result)) {
    if (uninitialize) {
      CoUninitialize();
    }
    return {FileDialogStatus::Unavailable, {},
            "Windows IFileOpenDialog is unavailable (" +
                hresult_text(result) + ")."};
  }

  FILEOPENDIALOGOPTIONS dialogOptions = 0;
  if (SUCCEEDED(dialog->GetOptions(&dialogOptions))) {
    dialog->SetOptions(dialogOptions | FOS_FORCEFILESYSTEM | FOS_FILEMUSTEXIST |
                       FOS_PATHMUSTEXIST | FOS_NOCHANGEDIR);
  }

  if (!options.title.empty()) {
    const std::wstring title = utf8_to_wide(options.title);
    dialog->SetTitle(title.c_str());
  }

  std::vector<std::wstring> names;
  std::vector<std::wstring> patterns;
  names.reserve(options.filters.size());
  patterns.reserve(options.filters.size());
  for (const FileDialogFilter &filter : options.filters) {
    names.push_back(utf8_to_wide(filter.name));

    std::string joined;
    for (const std::string &pattern : filter.patterns) {
      if (!joined.empty()) {
        joined += ';';
      }
      joined += pattern;
    }
    patterns.push_back(utf8_to_wide(joined.empty() ? "*.*" : joined));
  }

  std::vector<COMDLG_FILTERSPEC> specifications;
  specifications.reserve(options.filters.size());
  for (std::size_t index = 0; index < options.filters.size(); ++index) {
    specifications.push_back({names[index].c_str(), patterns[index].c_str()});
  }
  if (!specifications.empty()) {
    dialog->SetFileTypes(static_cast<UINT>(specifications.size()),
                         specifications.data());
    dialog->SetFileTypeIndex(1);
  }

  configure_initial_location(dialog, options.initialPath);

  HWND parent = GetActiveWindow();
  if (parent == nullptr) {
    parent = GetForegroundWindow();
  }

  result = dialog->Show(parent);
  if (result == HRESULT_FROM_WIN32(ERROR_CANCELLED)) {
    dialog->Release();
    if (uninitialize) {
      CoUninitialize();
    }
    return {FileDialogStatus::Cancelled, {}, {}};
  }
  if (FAILED(result)) {
    dialog->Release();
    if (uninitialize) {
      CoUninitialize();
    }
    return {FileDialogStatus::Failed, {},
            "Windows file dialog failed (" + hresult_text(result) + ")."};
  }

  IShellItem *item = nullptr;
  result = dialog->GetResult(&item);
  if (FAILED(result)) {
    dialog->Release();
    if (uninitialize) {
      CoUninitialize();
    }
    return {FileDialogStatus::Failed, {},
            "Windows file dialog did not return a selection (" +
                hresult_text(result) + ")."};
  }

  PWSTR selectedPath = nullptr;
  result = item->GetDisplayName(SIGDN_FILESYSPATH, &selectedPath);
  FileDialogResult dialogResult;
  if (SUCCEEDED(result) && selectedPath != nullptr) {
    dialogResult = {FileDialogStatus::Selected,
                    std::filesystem::path(selectedPath), {}};
  } else {
    dialogResult = {FileDialogStatus::Failed, {},
                    "The selected Shell item does not have a filesystem path (" +
                        hresult_text(result) + ")."};
  }

  if (selectedPath != nullptr) {
    CoTaskMemFree(selectedPath);
  }
  item->Release();
  dialog->Release();
  if (uninitialize) {
    CoUninitialize();
  }
  return dialogResult;
}

} // namespace directional::gui
