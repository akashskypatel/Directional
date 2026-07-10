#pragma once

#include <filesystem>
#include <fstream>
#include <mutex>
#include <streambuf>
#include <string>

namespace directional::gui {

class SessionLog {
public:
  SessionLog();
  ~SessionLog();

  SessionLog(const SessionLog &) = delete;
  SessionLog &operator=(const SessionLog &) = delete;

  void enable();

  [[nodiscard]] bool is_enabled() const;
  [[nodiscard]] const std::filesystem::path &path() const;

private:
  class TeeBuffer : public std::streambuf {
  public:
    TeeBuffer(std::streambuf *target, std::ofstream *file,
              std::mutex *fileMutex);
    void reset(std::streambuf *target, std::ofstream *file,
               std::mutex *fileMutex);

  protected:
    int overflow(int character) override;
    std::streamsize xsputn(const char *data, std::streamsize count) override;
    int sync() override;

  private:
    std::streambuf *target_ = nullptr;
    std::ofstream *file_ = nullptr;
    std::mutex *fileMutex_ = nullptr;
  };

  void restore_streams();

  std::filesystem::path path_;
  mutable std::mutex mutex_;
  std::mutex fileMutex_;
  std::ofstream file_;
  bool enabled_ = false;

  std::streambuf *originalCout_ = nullptr;
  std::streambuf *originalCerr_ = nullptr;
  TeeBuffer coutBuffer_;
  TeeBuffer cerrBuffer_;
};

std::filesystem::path executable_directory();
std::string timestamp_for_filename();

} // namespace directional::gui
