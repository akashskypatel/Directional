// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGRATION_SOLVE_STRATEGY_H
#define DIRECTIONAL_INTEGRATION_INTEGRATION_SOLVE_STRATEGY_H

#include <directional/integration/IntegerBatchSelector.h>

namespace directional {

/** @brief Mixed-integer integration KKT solve strategy. */
enum class IntegrationSolveStrategy {
  /** Always use the selected direct sparse backend. */
  DirectOnly,
  /** Try an iterative KKT solve first and fall back to the direct backend. */
  Adaptive
};

/** @brief Controls for the adaptive iterative KKT fast path. */
struct AdaptiveIntegrationOptions {
  int maxIterations = 128;
  double relativeResidualTolerance = 1.0e-6;
  double absoluteResidualTolerance = 1.0e-8;
  double constraintResidualTolerance = 1.0e-8;
  bool useWarmStart = true;
  int maximumConsecutiveFailures = 4;
};

[[nodiscard]] constexpr const char *
integration_solve_strategy_name(IntegrationSolveStrategy strategy) noexcept {
  switch (strategy) {
  case IntegrationSolveStrategy::DirectOnly:
    return "DirectOnly";
  case IntegrationSolveStrategy::Adaptive:
    return "Adaptive";
  }
  return "Unknown";
}

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGRATION_SOLVE_STRATEGY_H
