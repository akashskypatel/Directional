#include <directional/integration/IntegerTransitionBasis.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <limits>
#include <numeric>
#include <stdexcept>

#include <Eigen/SVD>

namespace directional::detail {

class IntegerTransitionBasisImpl {
public:
  [[nodiscard]] static IntegerTransitionBasisResult analyze_relation_matrix(
      const Eigen::SparseMatrix<int> &relations,
      const IntegerTransitionBasisOptions &options = {}) {
    using Clock = std::chrono::high_resolution_clock;
    const auto start = Clock::now();

    IntegerTransitionBasisResult result;
    result.rawTransitionCount = static_cast<std::size_t>(relations.cols());
    result.rawIntegerVariableCount = static_cast<std::size_t>(relations.cols());
    result.reducedIntegerVariableCount =
        static_cast<std::size_t>(relations.cols());
    result.fullFromIndependent =
        identity_mapping(static_cast<int>(relations.cols()));
    result.numericalRank = numerical_rank(relations);

    std::vector<int> dependentToIndependent(static_cast<std::size_t>(
                                                relations.cols()),
                                            -1);
    std::vector<bool> referencedAsIndependent(
        static_cast<std::size_t>(relations.cols()), false);
    std::vector<std::vector<std::pair<int, int>>> dependencyRows(
        static_cast<std::size_t>(relations.cols()));

    for (Eigen::Index row = 0; row < relations.rows(); ++row) {
      std::vector<std::pair<int, int>> entries;
      collect_row_entries(relations, row, entries);
      if (entries.size() < 2) {
        continue;
      }

      int dependentColumn = -1;
      int dependentCoefficient = 0;
      for (auto entry = entries.rbegin(); entry != entries.rend(); ++entry) {
        const auto &[column, coefficient] = *entry;
        if (std::abs(coefficient) == 1 &&
            dependentToIndependent[static_cast<std::size_t>(column)] == -1 &&
            !referencedAsIndependent[static_cast<std::size_t>(column)]) {
          dependentColumn = column;
          dependentCoefficient = coefficient;
          break;
        }
      }
      if (dependentColumn < 0) {
        continue;
      }

      std::vector<std::pair<int, int>> reconstruction;
      bool referencesDependentColumn = false;
      for (const auto &[column, coefficient] : entries) {
        if (column == dependentColumn) {
          continue;
        }
        if (dependentToIndependent[static_cast<std::size_t>(column)] != -1) {
          referencesDependentColumn = true;
          break;
        }
        reconstruction.emplace_back(
            column, -coefficient * dependentCoefficient);
      }
      if (referencesDependentColumn || reconstruction.empty()) {
        continue;
      }

      dependentToIndependent[static_cast<std::size_t>(dependentColumn)] = 1;
      dependencyRows[static_cast<std::size_t>(dependentColumn)] =
          std::move(reconstruction);
      for (const auto &[column, coefficient] :
           dependencyRows[static_cast<std::size_t>(dependentColumn)]) {
        (void)coefficient;
        referencedAsIndependent[static_cast<std::size_t>(column)] = true;
      }
    }

    result.redundantIntegerVariableCount =
        static_cast<std::size_t>(std::count_if(
            dependentToIndependent.begin(), dependentToIndependent.end(),
            [](const int value) { return value != -1; }));
    result.reducedIntegerVariableCount =
        result.rawIntegerVariableCount - result.redundantIntegerVariableCount;
    result.reductionRatio =
        result.rawIntegerVariableCount == 0
            ? 0.0
            : static_cast<double>(result.redundantIntegerVariableCount) /
                  static_cast<double>(result.rawIntegerVariableCount);
    result.exactReductionAvailable = result.redundantIntegerVariableCount > 0;
    result.reductionEnabled =
        options.reduceIntegerTransitionBasis && result.exactReductionAvailable;

    if (result.exactReductionAvailable) {
      result.fullFromIndependent =
          build_mapping(dependentToIndependent, dependencyRows);
      if (!verify_mapping(relations, result.fullFromIndependent)) {
        result.fullFromIndependent =
            identity_mapping(static_cast<int>(relations.cols()));
        result.reducedIntegerVariableCount = result.rawIntegerVariableCount;
        result.redundantIntegerVariableCount = 0;
        result.reductionRatio = 0.0;
        result.exactReductionAvailable = false;
        result.reductionEnabled = false;
      }
    }

    result.analysisSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                              start)
            .count() /
        1.0e6;
    return result;
  }

  [[nodiscard]] static IntegerTransitionBasisResult
  analyze_expanded_integer_relations(
      const Eigen::SparseMatrix<int> &constraintMatrix,
      const Eigen::SparseMatrix<int> &linRed,
      const Eigen::SparseMatrix<int> &singularSpan,
      const Eigen::SparseMatrix<int> &integerSpan,
      const Eigen::VectorXi &integerVars, const int reducedFunctionCount,
      const IntegerTransitionBasisOptions &options = {}) {
    const Eigen::SparseMatrix<int> exactSystem =
        constraintMatrix * linRed * singularSpan * integerSpan;
    const int expandedCount = integerVars.size() * reducedFunctionCount;
    Eigen::SparseMatrix<int> relations(0, expandedCount);
    if (expandedCount == 0) {
      return analyze_relation_matrix(relations, options);
    }

    std::vector<int> expandedColumns(static_cast<std::size_t>(expandedCount));
    for (int variable = 0; variable < integerVars.size(); ++variable) {
      for (int component = 0; component < reducedFunctionCount; ++component) {
        expandedColumns[static_cast<std::size_t>(
            variable * reducedFunctionCount + component)] =
            reducedFunctionCount * integerVars(variable) + component;
      }
    }

    std::vector<int> inverseColumn(static_cast<std::size_t>(exactSystem.cols()),
                                   -1);
    for (int local = 0; local < expandedCount; ++local) {
      const int global = expandedColumns[static_cast<std::size_t>(local)];
      if (global >= 0 && global < exactSystem.cols()) {
        inverseColumn[static_cast<std::size_t>(global)] = local;
      }
    }

    std::vector<std::vector<std::pair<int, int>>> relationRows;
    for (Eigen::Index row = 0; row < exactSystem.rows(); ++row) {
      std::vector<std::pair<int, int>> rowEntries;
      bool hasNonIntegerColumn = false;
      for (Eigen::Index col = 0; col < exactSystem.outerSize(); ++col) {
        for (Eigen::SparseMatrix<int>::InnerIterator entry(exactSystem, col);
             entry; ++entry) {
          if (entry.row() != row || entry.value() == 0) {
            continue;
          }
          const int mapped =
              entry.col() >= 0 &&
                      entry.col() <
                          static_cast<Eigen::Index>(inverseColumn.size())
                  ? inverseColumn[static_cast<std::size_t>(entry.col())]
                  : -1;
          if (mapped < 0) {
            hasNonIntegerColumn = true;
            break;
          }
          rowEntries.emplace_back(mapped, entry.value());
        }
        if (hasNonIntegerColumn) {
          break;
        }
      }
      if (!hasNonIntegerColumn && !rowEntries.empty()) {
        relationRows.push_back(std::move(rowEntries));
      }
    }

    std::vector<Eigen::Triplet<int>> triplets;
    for (std::size_t row = 0; row < relationRows.size(); ++row) {
      for (const auto &[column, value] : relationRows[row]) {
        triplets.emplace_back(static_cast<int>(row), column, value);
      }
    }
    relations.resize(static_cast<int>(relationRows.size()), expandedCount);
    relations.setFromTriplets(triplets.begin(), triplets.end());
    return analyze_relation_matrix(relations, options);
  }

private:
  static void collect_row_entries(const Eigen::SparseMatrix<int> &matrix,
                                  const Eigen::Index row,
                                  std::vector<std::pair<int, int>> &entries) {
    for (Eigen::Index col = 0; col < matrix.outerSize(); ++col) {
      for (Eigen::SparseMatrix<int>::InnerIterator entry(matrix, col); entry;
           ++entry) {
        if (entry.row() == row && entry.value() != 0) {
          entries.emplace_back(static_cast<int>(entry.col()), entry.value());
        }
      }
    }
  }

  [[nodiscard]] static double
  numerical_rank(const Eigen::SparseMatrix<int> &relations) {
    if (relations.rows() == 0 || relations.cols() == 0) {
      return 0.0;
    }
    Eigen::MatrixXd dense(relations.rows(), relations.cols());
    dense.setZero();
    for (Eigen::Index col = 0; col < relations.outerSize(); ++col) {
      for (Eigen::SparseMatrix<int>::InnerIterator entry(relations, col); entry;
           ++entry) {
        dense(entry.row(), entry.col()) = static_cast<double>(entry.value());
      }
    }
    const Eigen::JacobiSVD<Eigen::MatrixXd> svd(dense);
    const double tolerance =
        std::max(relations.rows(), relations.cols()) *
        std::numeric_limits<double>::epsilon() *
        (svd.singularValues().size() > 0 ? svd.singularValues()(0) : 0.0);
    return static_cast<double>((svd.singularValues().array() > tolerance).count());
  }

  [[nodiscard]] static Eigen::SparseMatrix<int>
  identity_mapping(const int size) {
    std::vector<Eigen::Triplet<int>> triplets;
    triplets.reserve(static_cast<std::size_t>(std::max(0, size)));
    for (int index = 0; index < size; ++index) {
      triplets.emplace_back(index, index, 1);
    }
    Eigen::SparseMatrix<int> identity(size, size);
    identity.setFromTriplets(triplets.begin(), triplets.end());
    return identity;
  }

  [[nodiscard]] static Eigen::SparseMatrix<int> build_mapping(
      const std::vector<int> &dependentMarkers,
      const std::vector<std::vector<std::pair<int, int>>> &dependencyRows) {
    std::vector<int> independentColumn(dependentMarkers.size(), -1);
    int independentCount = 0;
    for (std::size_t column = 0; column < dependentMarkers.size(); ++column) {
      if (dependentMarkers[column] == -1) {
        independentColumn[column] = independentCount++;
      }
    }

    std::vector<Eigen::Triplet<int>> triplets;
    for (std::size_t column = 0; column < dependentMarkers.size(); ++column) {
      if (dependentMarkers[column] == -1) {
        triplets.emplace_back(static_cast<int>(column),
                              independentColumn[column], 1);
      } else {
        for (const auto &[sourceColumn, coefficient] :
             dependencyRows[column]) {
          triplets.emplace_back(static_cast<int>(column),
                                independentColumn[static_cast<std::size_t>(
                                    sourceColumn)],
                                coefficient);
        }
      }
    }

    Eigen::SparseMatrix<int> mapping(static_cast<int>(dependentMarkers.size()),
                                     independentCount);
    mapping.setFromTriplets(triplets.begin(), triplets.end());
    return mapping;
  }

  [[nodiscard]] static bool
  verify_mapping(const Eigen::SparseMatrix<int> &relations,
                 const Eigen::SparseMatrix<int> &mapping) {
    const Eigen::SparseMatrix<int> residual = relations * mapping;
    for (Eigen::Index col = 0; col < residual.outerSize(); ++col) {
      for (Eigen::SparseMatrix<int>::InnerIterator entry(residual, col); entry;
           ++entry) {
        if (entry.value() != 0) {
          return false;
        }
      }
    }
    return true;
  }
};

IntegerTransitionBasisResult IntegerTransitionBasis::analyze_relation_matrix(
    const Eigen::SparseMatrix<int> &relations,
    const IntegerTransitionBasisOptions &options) {
  return IntegerTransitionBasisImpl::analyze_relation_matrix(relations, options);
}

IntegerTransitionBasisResult
IntegerTransitionBasis::analyze_expanded_integer_relations(
    const Eigen::SparseMatrix<int> &constraintMatrix,
    const Eigen::SparseMatrix<int> &linRed,
    const Eigen::SparseMatrix<int> &singularSpan,
    const Eigen::SparseMatrix<int> &integerSpan,
    const Eigen::VectorXi &integerVars, const int reducedFunctionCount,
    const IntegerTransitionBasisOptions &options) {
  return IntegerTransitionBasisImpl::analyze_expanded_integer_relations(
      constraintMatrix, linRed, singularSpan, integerSpan, integerVars,
      reducedFunctionCount, options);
}

} // namespace directional::detail
