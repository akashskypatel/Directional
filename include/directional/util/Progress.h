// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_UTIL_PROGRESS_H
#define DIRECTIONAL_UTIL_PROGRESS_H

#include <cstddef>
#include <functional>
#include <string_view>

namespace directional {

/** Callback invoked when a library operation advances to a new task. */
using ProgressCallback =
    std::function<void(std::size_t current, std::size_t total,
                       std::string_view task)>;

/** Reports progress when a callback is installed. */
inline void report_progress(const ProgressCallback &callback,
                            const std::size_t current,
                            const std::size_t total,
                            const std::string_view task) {
  if (callback) {
    callback(current, total, task);
  }
}

} // namespace directional

#endif // DIRECTIONAL_UTIL_PROGRESS_H
