#include "SessionLog.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <system_error>

#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <limits.h>
#include <vector>
#else
#include <limits.h>
#include <unistd.h>
#include <array>
#endif

namespace directional::gui {
namespace {

std::filesystem::path executable_path() {
#if defined(_WIN32)
  std::wstring buffer(MAX_PATH, L'\0');
  for (;;) {
    const DWORD length = GetModuleFileNameW(
        nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    if (length == 0) {
      throw std::runtime_error("Unable to resolve executable path.");
    }
    if (length < buffer.size() - 1) {
      buffer.resize(length);
      return std::filesystem::path(buffer);
    }
    buffer.resize(buffer.size() * 2);
  }
#elif defined(__APPLE__)
  uint32_t size = 0;
  _NSGetExecutablePath(nullptr, &size);
  std::vector<char> buffer(size + 1, '\0');
  if (_NSGetExecutablePath(buffer.data(), &size) != 0) {
    throw std::runtime_error("Unable to resolve executable path.");
  }
  std::error_code error;
  const std::filesystem::path canonical =
      std::filesystem::weakly_canonical(buffer.data(), error);
  return error ? std::filesystem::path(buffer.data()) : canonical;
#else
  std::array<char, PATH_MAX> buffer{};
  const ssize_t length = readlink("/proc/self/exe", buffer.data(),
                                  buffer.size() - 1);
  if (length <= 0) {
    throw std::runtime_error("Unable to resolve executable path.");
  }
  buffer[static_cast<std::size_t>(length)] = '\0';
  return std::filesystem::path(buffer.data());
#endif
}

std::tm local_time(const std::time_t value) {
  std::tm result{};
#if defined(_WIN32)
  localtime_s(&result, &value);
#else
  localtime_r(&value, &result);
#endif
  return result;
}

} // namespace

std::filesystem::path executable_directory() {
  return executable_path().parent_path();
}

std::string timestamp_for_filename() {
  const auto now = std::chrono::system_clock::now();
  const std::time_t time = std::chrono::system_clock::to_time_t(now);
  const std::tm local = local_time(time);

  std::ostringstream stream;
  stream << std::put_time(&local, "%Y%m%d-%H%M%S");
  return stream.str();
}

SessionLog::TeeBuffer::TeeBuffer(std::streambuf *target, std::ofstream *file,
                                 std::mutex *fileMutex)
    : target_(target), file_(file), fileMutex_(fileMutex) {}

void SessionLog::TeeBuffer::reset(std::streambuf *target, std::ofstream *file,
                                  std::mutex *fileMutex) {
  target_ = target;
  file_ = file;
  fileMutex_ = fileMutex;
}

int SessionLog::TeeBuffer::overflow(const int character) {
  if (character == traits_type::eof()) {
    return sync() == 0 ? traits_type::not_eof(character) : traits_type::eof();
  }

  const char value = static_cast<char>(character);
  if (target_ != nullptr) {
    target_->sputc(value);
  }
  if (file_ != nullptr && fileMutex_ != nullptr) {
    std::lock_guard lock(*fileMutex_);
    if (file_->is_open()) {
      file_->put(value);
      if (!*file_) {
        return traits_type::eof();
      }
    }
  }
  return character;
}

std::streamsize SessionLog::TeeBuffer::xsputn(const char *data,
                                              const std::streamsize count) {
  if (target_ != nullptr) {
    target_->sputn(data, count);
  }
  if (file_ != nullptr && fileMutex_ != nullptr) {
    std::lock_guard lock(*fileMutex_);
    if (file_->is_open()) {
      file_->write(data, count);
      if (!*file_) {
        return 0;
      }
    }
  }
  return count;
}

int SessionLog::TeeBuffer::sync() {
  bool ok = true;
  if (target_ != nullptr) {
    target_->pubsync();
  }
  if (file_ != nullptr && fileMutex_ != nullptr) {
    std::lock_guard lock(*fileMutex_);
    if (file_->is_open()) {
      file_->flush();
      ok = ok && static_cast<bool>(*file_);
    }
  }
  return ok ? 0 : -1;
}

SessionLog::SessionLog()
    : path_(executable_directory() /
            ("directional-ui-" + timestamp_for_filename() + ".log")),
      coutBuffer_(nullptr, &file_, &fileMutex_),
      cerrBuffer_(nullptr, &file_, &fileMutex_) {}

SessionLog::~SessionLog() {
  restore_streams();
}

void SessionLog::enable() {
  std::lock_guard lock(mutex_);
  if (enabled_) {
    return;
  }

  file_.open(path_, std::ios::out | std::ios::app);
  if (!file_) {
    throw std::runtime_error("Unable to open verbose GUI log file: " +
                             path_.string());
  }

  file_ << "[directional-ui] session started\n";
  file_.flush();

  originalCout_ = std::cout.rdbuf();
  originalCerr_ = std::cerr.rdbuf();
  coutBuffer_.reset(originalCout_, &file_, &fileMutex_);
  cerrBuffer_.reset(originalCerr_, &file_, &fileMutex_);
  std::cout.rdbuf(&coutBuffer_);
  std::cerr.rdbuf(&cerrBuffer_);
  enabled_ = true;
}

bool SessionLog::is_enabled() const {
  std::lock_guard lock(mutex_);
  return enabled_;
}

const std::filesystem::path &SessionLog::path() const {
  return path_;
}

void SessionLog::restore_streams() {
  std::lock_guard lock(mutex_);
  if (!enabled_) {
    return;
  }

  if (originalCout_ != nullptr) {
    std::cout.rdbuf(originalCout_);
  }
  if (originalCerr_ != nullptr) {
    std::cerr.rdbuf(originalCerr_);
  }

  if (file_.is_open()) {
    file_ << "[directional-ui] session finished\n";
    file_.close();
  }

  originalCout_ = nullptr;
  originalCerr_ = nullptr;
  enabled_ = false;
}

} // namespace directional::gui
