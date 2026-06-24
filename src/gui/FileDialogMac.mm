#include "FileDialog.h"

#import <AppKit/AppKit.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>
#import <dispatch/dispatch.h>

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <string>
#include <system_error>
#include <vector>

namespace directional::gui {
namespace {

NSString *to_ns_string(const std::string &value) {
  return [NSString stringWithUTF8String:value.c_str()];
}

NSString *path_to_ns_string(const std::filesystem::path &path) {
  const std::string native = path.native();
  return [[NSFileManager defaultManager]
      stringWithFileSystemRepresentation:native.c_str()
                                  length:native.size()];
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

std::vector<std::string>
filter_extensions(const std::vector<FileDialogFilter> &filters) {
  std::vector<std::string> extensions;
  for (const FileDialogFilter &filter : filters) {
    for (const std::string &pattern : filter.patterns) {
      const std::size_t dot = pattern.find_last_of('.');
      if (dot == std::string::npos || dot + 1 >= pattern.size()) {
        continue;
      }
      std::string extension = pattern.substr(dot + 1);
      if (extension.find_first_of("*?[]") != std::string::npos) {
        continue;
      }
      std::transform(extension.begin(), extension.end(), extension.begin(),
                     [](const unsigned char character) {
                       return static_cast<char>(std::tolower(character));
                     });
      if (std::find(extensions.begin(), extensions.end(), extension) ==
          extensions.end()) {
        extensions.push_back(std::move(extension));
      }
    }
  }
  return extensions;
}

FileDialogResult run_open_panel(const FileDialogOptions &options) {
  @autoreleasepool {
    [NSApplication sharedApplication];

    NSOpenPanel *panel = [NSOpenPanel openPanel];
    panel.canChooseFiles = YES;
    panel.canChooseDirectories = NO;
    panel.allowsMultipleSelection = NO;
    panel.resolvesAliases = YES;
    panel.treatsFilePackagesAsDirectories = NO;
    panel.allowsOtherFileTypes = NO;

    if (!options.title.empty()) {
      panel.title = to_ns_string(options.title);
    }

    const std::filesystem::path directory =
        initial_directory(options.initialPath);
    if (!directory.empty()) {
      panel.directoryURL =
          [NSURL fileURLWithPath:path_to_ns_string(directory) isDirectory:YES];
    }

    std::error_code error;
    if (!options.initialPath.empty() &&
        std::filesystem::is_regular_file(options.initialPath, error) &&
        !error) {
      panel.nameFieldStringValue =
          path_to_ns_string(options.initialPath.filename());
    }

    const std::vector<std::string> extensions =
        filter_extensions(options.filters);
    if (!extensions.empty()) {
      NSMutableArray<NSString *> *extensionNames = [NSMutableArray array];
      for (const std::string &extension : extensions) {
        [extensionNames addObject:to_ns_string(extension)];
      }

      if (@available(macOS 11.0, *)) {
        NSMutableArray<UTType *> *types = [NSMutableArray array];
        for (NSString *extension in extensionNames) {
          UTType *type = [UTType typeWithFilenameExtension:extension];
          if (type != nil) {
            [types addObject:type];
          }
        }
        if (types.count > 0) {
          panel.allowedContentTypes = types;
        }
      } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        panel.allowedFileTypes = extensionNames;
#pragma clang diagnostic pop
      }
    }

    [NSApp activateIgnoringOtherApps:YES];
    const NSModalResponse response = [panel runModal];
    if (response == NSModalResponseCancel) {
      return {FileDialogStatus::Cancelled, {}, {}};
    }
    if (response != NSModalResponseOK) {
      return {FileDialogStatus::Failed, {},
              "NSOpenPanel ended without selecting a file."};
    }

    NSURL *url = panel.URL;
    if (url == nil || !url.isFileURL ||
        url.fileSystemRepresentation == nullptr) {
      return {FileDialogStatus::Failed, {},
              "NSOpenPanel did not return a local filesystem path."};
    }

    return {FileDialogStatus::Selected,
            std::filesystem::path(url.fileSystemRepresentation), {}};
  }
}

} // namespace

FileDialogResult open_native_file_dialog(const FileDialogOptions &options) {
  if ([NSThread isMainThread]) {
    return run_open_panel(options);
  }

  __block FileDialogResult result;
  dispatch_sync(dispatch_get_main_queue(), ^{
    result = run_open_panel(options);
  });
  return result;
}

} // namespace directional::gui
