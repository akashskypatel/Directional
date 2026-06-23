#pragma once

#include <cstddef>
#include <iosfwd>
#include <string_view>

#include <directional/util/Progress.h>

namespace directional::cli {

class ProgressDisplay {
public:
  explicit ProgressDisplay(std::ostream &stream, bool inPlace = true);
  ~ProgressDisplay();

  void update(std::size_t current, std::size_t total, std::string_view task);
  void finish();

  ProgressCallback range(std::size_t first, std::size_t last,
                         std::size_t overallTotal);

private:
  std::ostream &stream_;
  bool inPlace_ = true;
  bool active_ = false;
  std::size_t previousWidth_ = 0;
};

} // namespace directional::cli
