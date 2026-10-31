#pragma once

#include <cstddef>
#include <stdexcept>

#include <directional/authority/AuthorityIds.h>

namespace directional::tests {

inline authority::HardRailId test_hard_rail_id(const int value) {
  const auto id = authority::HardRailId::from_index(
      value, static_cast<std::size_t>(value + 1));
  if (!id) {
    throw std::runtime_error("Invalid test hard-rail ID.");
  }
  return id.value();
}

} // namespace directional::tests
