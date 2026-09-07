// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_GRID_AUTOMORPHISM_H
#define DIRECTIONAL_AUTHORITY_GRID_AUTOMORPHISM_H

#include <compare>
#include <cstdint>

namespace directional::authority {

class QuarterTurn {
public:
  constexpr QuarterTurn() noexcept = default;

  [[nodiscard]] static constexpr QuarterTurn from_integer(int value) noexcept {
    const int normalized = ((value % 4) + 4) % 4;
    return QuarterTurn(static_cast<std::uint8_t>(normalized));
  }

  [[nodiscard]] constexpr std::uint8_t value() const noexcept { return value_; }

  [[nodiscard]] constexpr QuarterTurn inverse() const noexcept {
    return from_integer(-static_cast<int>(value_));
  }

  [[nodiscard]] friend constexpr QuarterTurn
  compose(QuarterTurn left, QuarterTurn right) noexcept {
    return from_integer(static_cast<int>(left.value_) +
                        static_cast<int>(right.value_));
  }

  auto operator<=>(const QuarterTurn &) const = default;

private:
  explicit constexpr QuarterTurn(std::uint8_t value) noexcept : value_(value) {}

  std::uint8_t value_ = 0;
};

struct LatticeTranslation {
  std::int64_t x = 0;
  std::int64_t y = 0;

  auto operator<=>(const LatticeTranslation &) const = default;
};

[[nodiscard]] constexpr LatticeTranslation
rotate(QuarterTurn rotation, LatticeTranslation value) noexcept {
  switch (rotation.value()) {
  case 0:
    return value;
  case 1:
    return {-value.y, value.x};
  case 2:
    return {-value.x, -value.y};
  default:
    return {value.y, -value.x};
  }
}

[[nodiscard]] constexpr LatticeTranslation
operator+(LatticeTranslation left, LatticeTranslation right) noexcept {
  return {left.x + right.x, left.y + right.y};
}

[[nodiscard]] constexpr LatticeTranslation
operator-(LatticeTranslation value) noexcept {
  return {-value.x, -value.y};
}

[[nodiscard]] constexpr LatticeTranslation
operator-(LatticeTranslation left, LatticeTranslation right) noexcept {
  return {left.x - right.x, left.y - right.y};
}

struct GridAutomorphism {
  QuarterTurn rotation;
  LatticeTranslation shift;

  [[nodiscard]] static constexpr GridAutomorphism identity() noexcept {
    return {QuarterTurn{}, {0, 0}};
  }

  // compose(left, right) means apply right first, then left.
  [[nodiscard]] friend constexpr GridAutomorphism
  compose(const GridAutomorphism &left,
          const GridAutomorphism &right) noexcept {
    return {compose(left.rotation, right.rotation),
            rotate(left.rotation, right.shift) + left.shift};
  }

  [[nodiscard]] constexpr GridAutomorphism inverse() const noexcept {
    const QuarterTurn inverseRotation = rotation.inverse();
    return {inverseRotation, rotate(inverseRotation, -shift)};
  }

  [[nodiscard]] constexpr LatticeTranslation
  apply(LatticeTranslation value) const noexcept {
    return rotate(rotation, value) + shift;
  }

  auto operator<=>(const GridAutomorphism &) const = default;
};

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_GRID_AUTOMORPHISM_H
