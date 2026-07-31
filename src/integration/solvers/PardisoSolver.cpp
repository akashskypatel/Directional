#include <directional/integration/solvers/PardisoSolver.h>

namespace directional {

[[nodiscard]] PardisoBenchmarkOptions
default_pardiso_benchmark_options() {
  PardisoBenchmarkOptions options;
  options.threadCount = 4;
  options.ordering = PardisoOrdering::MinimumDegree;

  options.scaling = PardisoOptionSwitch::LibraryDefault;
  options.matching = PardisoOptionSwitch::LibraryDefault;

  options.reuseSymbolicAnalysisForIdenticalPattern = false;
  options.iterativeRefinementSteps = 2;

  options.matrixChecker = false;
  options.printPardisoStatistics = false;
  options.printPhaseSummaryEverySolve = false;
  return options;
}

} // namespace directional
