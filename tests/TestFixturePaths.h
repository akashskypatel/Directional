#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#else
#include <unistd.h>
#endif

namespace directional::tests {

inline std::filesystem::path test_executable_directory() {
#if defined(_WIN32)
  std::wstring buffer(32768, L'\0');
  const DWORD length = GetModuleFileNameW(
      nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
  if (length == 0 || length == buffer.size()) {
    return {};
  }
  buffer.resize(length);
  return std::filesystem::path(buffer).parent_path();
#elif defined(__APPLE__)
  std::uint32_t size = 0;
  _NSGetExecutablePath(nullptr, &size);
  std::vector<char> buffer(size);
  if (_NSGetExecutablePath(buffer.data(), &size) != 0) {
    return {};
  }
  return std::filesystem::weakly_canonical(buffer.data()).parent_path();
#else
  std::vector<char> buffer(4096);
  const ssize_t length =
      readlink("/proc/self/exe", buffer.data(), buffer.size());
  if (length <= 0 || static_cast<std::size_t>(length) == buffer.size()) {
    return {};
  }
  buffer.resize(static_cast<std::size_t>(length));
  return std::filesystem::path(
      std::string(buffer.begin(), buffer.end())).parent_path();
#endif
}

inline std::filesystem::path test_data_root() {
  const std::filesystem::path packaged =
      test_executable_directory() / "test-data";
  if (std::filesystem::exists(packaged / "benchmarks" / "fixtures")) {
    return packaged;
  }
  return std::filesystem::path(DIRECTIONAL_TEST_SOURCE_DIR);
}

inline std::filesystem::path benchmark_fixture_path(
    const std::string_view relativePath) {
  return test_data_root() / "benchmarks" / "fixtures" /
         std::filesystem::path(relativePath);
}

} // namespace directional::tests
