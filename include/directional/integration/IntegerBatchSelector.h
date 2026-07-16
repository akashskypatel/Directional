// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGER_BATCH_SELECTOR_H
#define DIRECTIONAL_INTEGRATION_INTEGER_BATCH_SELECTOR_H

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>

namespace directional {

enum class IntegerBatchStrategy {
  ResidualOnly,
  CouplingAware
};

struct IntegerBatchOptions {
  IntegerBatchStrategy strategy = IntegerBatchStrategy::ResidualOnly;
  int maximumBatchSize = 8;
  double residualMultiplier = 1.5;
  double residualWindow = 0.025;
  double absoluteResidualCeiling = 0.10;
  double couplingThreshold = 0.10;
  double influenceOverlapThreshold = 0.35;
  double strongInfluenceThreshold = 0.05;
  bool useInfluenceOverlap = true;
};

struct IntegerBatchCandidate {
  int index = -1;
  double value = 0.0;
  double roundedValue = 0.0;
  double residual = std::numeric_limits<double>::infinity();
};

struct IntegerBatchSelectionResult {
  std::vector<IntegerBatchCandidate> selected;
  double sortSeconds = 0.0;
  double couplingAnalysisSeconds = 0.0;
};

[[nodiscard]] constexpr const char *
integer_batch_strategy_name(IntegerBatchStrategy strategy) noexcept {
  switch (strategy) {
  case IntegerBatchStrategy::ResidualOnly:
    return "ResidualOnly";
  case IntegerBatchStrategy::CouplingAware:
    return "CouplingAware";
  }
  return "Unknown";
}

namespace detail {

class IntegerBatchSelector {
public:
  [[nodiscard]] static IntegerBatchSelectionResult
  select(std::vector<IntegerBatchCandidate> candidates,
         const Eigen::SparseMatrix<double> &quadraticEnergy,
         const IntegerBatchOptions &options) {
    using Clock = std::chrono::high_resolution_clock;
    IntegerBatchSelectionResult result;
    if (options.maximumBatchSize <= 0) {
      return result;
    }

    const auto sortStart = Clock::now();
    std::sort(candidates.begin(), candidates.end(),
              [](const IntegerBatchCandidate &lhs,
                 const IntegerBatchCandidate &rhs) {
                if (lhs.residual != rhs.residual) {
                  return lhs.residual < rhs.residual;
                }
                return lhs.index < rhs.index;
              });
    result.sortSeconds = elapsed_seconds(sortStart);

    if (candidates.empty()) {
      return result;
    }

    const double bestResidual = candidates.front().residual;
    const double relativeLimit = options.residualMultiplier > 0.0
                                     ? options.residualMultiplier * bestResidual
                                     : std::numeric_limits<double>::infinity();
    const double windowLimit = bestResidual + options.residualWindow;
    const double residualLimit =
        std::min(options.absoluteResidualCeiling,
                 std::max(relativeLimit, windowLimit));

    const auto couplingStart = Clock::now();
    for (const IntegerBatchCandidate &candidate : candidates) {
      if (result.selected.size() >=
          static_cast<std::size_t>(options.maximumBatchSize)) {
        break;
      }

      if (!std::isfinite(candidate.residual)) {
        continue;
      }

      if (!result.selected.empty() && candidate.residual > residualLimit) {
        break;
      }

      bool conflicts = false;
      if (options.strategy == IntegerBatchStrategy::CouplingAware) {
        for (const IntegerBatchCandidate &selected : result.selected) {
          if (has_conflict(candidate.index, selected.index, quadraticEnergy,
                           options)) {
            conflicts = true;
            break;
          }
        }
      }

      if (!conflicts) {
        result.selected.push_back(candidate);
      }
    }
    result.couplingAnalysisSeconds = elapsed_seconds(couplingStart);

    if (result.selected.empty()) {
      result.selected.push_back(candidates.front());
    }
    return result;
  }

private:
  template <typename StartTime>
  [[nodiscard]] static double elapsed_seconds(const StartTime &start) {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::high_resolution_clock::now() - start)
               .count() /
           1.0e6;
  }

  [[nodiscard]] static bool
  has_conflict(const int first, const int second,
               const Eigen::SparseMatrix<double> &quadraticEnergy,
               const IntegerBatchOptions &options) {
    if (first == second) {
      return true;
    }
    if (first < 0 || second < 0 || first >= quadraticEnergy.cols() ||
        second >= quadraticEnergy.cols()) {
      return true;
    }

    if (normalized_coupling(first, second, quadraticEnergy) >
        options.couplingThreshold) {
      return true;
    }

    return options.useInfluenceOverlap &&
           influence_overlap(first, second, quadraticEnergy, options) >
               options.influenceOverlapThreshold;
  }

  [[nodiscard]] static double
  normalized_coupling(const int first, const int second,
                      const Eigen::SparseMatrix<double> &quadraticEnergy) {
    constexpr double epsilon = 1.0e-12;
    const double firstDiagonal =
        std::max(epsilon, std::abs(quadraticEnergy.coeff(first, first)));
    const double secondDiagonal =
        std::max(epsilon, std::abs(quadraticEnergy.coeff(second, second)));
    const double direct = std::abs(quadraticEnergy.coeff(first, second));
    return direct / std::sqrt(firstDiagonal * secondDiagonal);
  }

  [[nodiscard]] static double
  influence_overlap(const int first, const int second,
                    const Eigen::SparseMatrix<double> &quadraticEnergy,
                    const IntegerBatchOptions &options) {
    const std::vector<int> firstInfluence =
        strong_influence_rows(first, quadraticEnergy, options);
    const std::vector<int> secondInfluence =
        strong_influence_rows(second, quadraticEnergy, options);
    if (firstInfluence.empty() || secondInfluence.empty()) {
      return 0.0;
    }

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t intersection = 0;
    while (i < firstInfluence.size() && j < secondInfluence.size()) {
      if (firstInfluence[i] == secondInfluence[j]) {
        ++intersection;
        ++i;
        ++j;
      } else if (firstInfluence[i] < secondInfluence[j]) {
        ++i;
      } else {
        ++j;
      }
    }

    const std::size_t denominator =
        std::min(firstInfluence.size(), secondInfluence.size());
    return denominator == 0
               ? 0.0
               : static_cast<double>(intersection) /
                     static_cast<double>(denominator);
  }

  [[nodiscard]] static std::vector<int>
  strong_influence_rows(const int column,
                        const Eigen::SparseMatrix<double> &quadraticEnergy,
                        const IntegerBatchOptions &options) {
    std::vector<int> rows;
    constexpr double epsilon = 1.0e-12;
    const double diagonal =
        std::max(epsilon, std::abs(quadraticEnergy.coeff(column, column)));
    for (Eigen::SparseMatrix<double>::InnerIterator entry(quadraticEnergy,
                                                          column);
         entry; ++entry) {
      const double rowDiagonal =
          std::max(epsilon,
                   std::abs(quadraticEnergy.coeff(entry.row(), entry.row())));
      const double normalized =
          std::abs(entry.value()) / std::sqrt(diagonal * rowDiagonal);
      if (normalized >= options.strongInfluenceThreshold) {
        rows.push_back(static_cast<int>(entry.row()));
      }
    }
    std::sort(rows.begin(), rows.end());
    rows.erase(std::unique(rows.begin(), rows.end()), rows.end());
    return rows;
  }
};

} // namespace detail

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGER_BATCH_SELECTOR_H
