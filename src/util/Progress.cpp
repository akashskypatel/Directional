#include <directional/util/Progress.h>

namespace directional {

void report_progress(const ProgressCallback &callback,
                     const std::size_t current,
                     const std::size_t total,
                     const std::string_view task) {
  if (callback) {
    callback(current, total, task);
  }
}

} // namespace directional
