#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <directional/geometry/GlobalConformityPlan.h>
namespace directional::geometry::global_conformity_detail {
struct SolverIncidenceEnd { std::size_t row=0U; int sign=1; };
struct SolverSpan { std::size_t semanticIndex=0U; std::vector<SolverIncidenceEnd> ends; EInt preferred,lower,upper,lexWeight; bool semantic=true; };
enum class ExactScheduleInfeasibilityKind : std::uint8_t { BalanceCut=0,PositivityCut=1,ParityCut=2 };
struct ExactScheduleInfeasibility {
  ExactScheduleInfeasibilityKind kind=ExactScheduleInfeasibilityKind::BalanceCut;
  std::vector<std::size_t> rowOrdinals;
  std::size_t doubleCoverNodeCount=0U;
  std::vector<std::size_t> reachableDoubleCoverNodes;
  EInt requiredFlow,achievedFlow,cutCapacity;
};
struct ExactScheduleSolveResult {
  bool success=false;
  std::vector<EInt> counts;
  ConformityObjectiveValue objective;
  GlobalConformityWorkLedger ledger;
  ConformityTerminalRefinementWitness terminalWitness;
  std::optional<ExactScheduleInfeasibility> infeasibility;
  EInt h,u,q,l;
  std::string failure;
};
[[nodiscard]] ExactScheduleSolveResult solve_exact_schedule(std::size_t,std::vector<SolverSpan>);
[[nodiscard]] ConformityObjectiveValue evaluate_objective(const std::vector<SolverSpan>&,const std::vector<EInt>&,const EInt&);
}
