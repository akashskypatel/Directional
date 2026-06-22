#include "ProgressDisplay.h"

#include <algorithm>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>

namespace directional::cli {

ProgressDisplay::ProgressDisplay(std::ostream &stream, const bool inPlace)
    : stream_(stream), inPlace_(inPlace) {}

ProgressDisplay::~ProgressDisplay() { finish(); }

void ProgressDisplay::update(const std::size_t current, const std::size_t total,
                             const std::string_view task) {
  const std::size_t safeTotal = std::max<std::size_t>(total, 1);
  const std::size_t safeCurrent = std::min(current, safeTotal);
  const std::size_t percent = safeCurrent * 100 / safeTotal;

  std::ostringstream line;
  line << "[Directional] (" << std::setfill('0') << std::setw(2)
       << percent << "%) ("
       << safeCurrent << '/' << safeTotal << ") Running " << task << "...";
  std::string text = line.str();
  if (!inPlace_) {
    stream_ << text << '\n';
    stream_.flush();
    return;
  }

  if (text.size() < previousWidth_) {
    text.append(previousWidth_ - text.size(), ' ');
  }

  stream_ << '\r' << text << std::flush;
  previousWidth_ = text.size();
  active_ = true;
}

void ProgressDisplay::finish() {
  if (active_) {
    stream_ << '\n';
    stream_.flush();
    active_ = false;
    previousWidth_ = 0;
  }
}

ProgressCallback ProgressDisplay::range(const std::size_t first,
                                        const std::size_t last,
                                        const std::size_t overallTotal) {
  return [this, first, last, overallTotal](const std::size_t current,
                             const std::size_t total,
                             const std::string_view task) {
    const std::size_t span = last >= first ? last - first + 1 : 1;
    const std::size_t safeTotal = std::max<std::size_t>(total, 1);
    const std::size_t safeCurrent =
        std::min(std::max<std::size_t>(current, 1), safeTotal);
    const std::size_t mapped =
        safeTotal == 1
            ? last
            : first + (safeCurrent - 1) * (span - 1) / (safeTotal - 1);
    update(std::min(mapped, last), overallTotal, task);
  };
}

} // namespace directional::cli
