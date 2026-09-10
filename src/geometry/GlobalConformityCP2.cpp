#include <directional/geometry/GlobalConformityPlan.h>

#include "GlobalConformityExactSolver.h"
#include "GlobalConformityProblem.h"

#include <algorithm>
#include <cstdint>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace directional::geometry {
namespace {
constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;
void hash_byte(std::uint64_t &hash, std::uint8_t value) { hash ^= value; hash *= kFnvPrime; }
void hash_u64(std::uint64_t &hash, std::uint64_t value) {
  for (unsigned shift=0;shift<64U;shift+=8U) hash_byte(hash,static_cast<std::uint8_t>((value>>shift)&0xffU));
}
void hash_eint(std::uint64_t &hash,const EInt &value) {
  const auto text=value.to_string();hash_u64(hash,text.size());for(unsigned char c:text)hash_byte(hash,c);
}
template<class Id> void hash_id(std::uint64_t &hash,Id id) {
  hash_u64(hash,static_cast<std::uint64_t>(Id::domain()));hash_u64(hash,id.index());
}

GlobalConformityPlanError cp2_error(GlobalConformityPlanErrorCode code,std::string detail) {
  GlobalConformityPlanError out;out.code=code;out.detail=std::move(detail);return out;
}
GlobalConformityKnownFeasibleInput as_known_feasible(const GlobalConformityInput &input) {
  return {input.sourceVertices,input.targetSize,input.spans,input.incidences};
}

std::uint64_t normalized_problem_digest(const GlobalTopologyPlan &topology,
    const global_conformity_detail::NormalizedConformityProblem &problem) {
  std::uint64_t hash=kFnvOffset;
  hash_u64(hash,topology.source_digest());hash_u64(hash,topology.network_digest());
  hash_u64(hash,topology.cut_graph_digest());hash_u64(hash,topology.semantic_digest());
  hash_u64(hash,problem.targetMetricDigest);hash_u64(hash,problem.rowCount);
  for(const auto &row:problem.rows){hash_id(hash,row.region);hash_u64(hash,static_cast<std::uint64_t>(row.family));}
  hash_u64(hash,problem.spans.size());
  for(std::size_t i=0;i<problem.spans.size();++i){hash_id(hash,problem.spans[i].id.network_arc());hash_eint(hash,problem.preferred[i]);}
  hash_u64(hash,problem.incidences.size());
  for(const auto &inc:problem.incidences){hash_id(hash,inc.id.region);hash_u64(hash,inc.id.canonicalBoundaryOccurrenceOrdinal);hash_id(hash,inc.span.network_arc());hash_u64(hash,static_cast<std::uint64_t>(inc.family));hash_u64(hash,static_cast<std::uint64_t>(static_cast<int>(inc.sign)+1));hash_u64(hash,static_cast<std::uint64_t>(static_cast<int>(inc.orientation)+1));}
  return hash;
}

struct Component {
  std::vector<std::size_t> spans;
  std::vector<std::size_t> rows;
};
std::vector<Component> connected_components(const global_conformity_detail::NormalizedConformityProblem &problem) {
  const std::size_t E=problem.spans.size();
  std::vector<std::vector<std::size_t>> rowSpans(problem.rowCount);
  for(std::size_t si=0;si<E;++si) for(const auto &end:problem.solver[si].ends) rowSpans[end.row].push_back(si);
  for(auto &v:rowSpans){std::sort(v.begin(),v.end());v.erase(std::unique(v.begin(),v.end()),v.end());}
  std::vector<bool> seenSpan(E,false),seenRow(problem.rowCount,false);std::vector<Component> out;
  for(std::size_t seed=0;seed<E;++seed){
    if(seenSpan[seed])continue;Component component;std::vector<std::size_t> spanStack{seed};seenSpan[seed]=true;
    while(!spanStack.empty()){
      const auto si=spanStack.back();spanStack.pop_back();component.spans.push_back(si);
      for(const auto &end:problem.solver[si].ends){if(!seenRow[end.row]){seenRow[end.row]=true;component.rows.push_back(end.row);for(auto other:rowSpans[end.row])if(!seenSpan[other]){seenSpan[other]=true;spanStack.push_back(other);}}}
    }
    std::sort(component.spans.begin(),component.spans.end());std::sort(component.rows.begin(),component.rows.end());out.push_back(std::move(component));
  }
  return out;
}

struct LocalComponentProblem {
  std::vector<global_conformity_detail::SolverSpan> solver;
  std::vector<std::size_t> globalSpans;
  std::vector<std::size_t> globalRows;
};
LocalComponentProblem make_local_component(const global_conformity_detail::NormalizedConformityProblem &problem,const Component &component) {
  LocalComponentProblem local;local.globalSpans=component.spans;local.globalRows=component.rows;
  std::map<std::size_t,std::size_t> rowMap;for(std::size_t i=0;i<component.rows.size();++i)rowMap.emplace(component.rows[i],i);
  for(std::size_t localIndex=0;localIndex<component.spans.size();++localIndex){
    const auto globalIndex=component.spans[localIndex];auto span=problem.solver[globalIndex];span.semanticIndex=localIndex;span.ends.clear();
    for(const auto &end:problem.solver[globalIndex].ends)span.ends.push_back({rowMap.at(end.row),end.sign});
    local.solver.push_back(std::move(span));
  }
  return local;
}

std::vector<ConformityIncidence> component_incidences(const global_conformity_detail::NormalizedConformityProblem &problem,const Component &component) {
  std::set<ConformitySpanId> ids;for(auto si:component.spans)ids.insert(problem.spans[si].id);
  std::vector<ConformityIncidence> out;for(const auto &inc:problem.incidences)if(ids.count(inc.span))out.push_back(inc);return out;
}

GlobalConformityCertificate make_certificate(const GlobalTopologyPlan &topology,
    const global_conformity_detail::NormalizedConformityProblem &problem,const Component &component,
    std::size_t ordinal,const global_conformity_detail::ExactScheduleSolveResult &solved,std::uint64_t problemDigest) {
  GlobalConformityCertificate certificate;certificate.componentOrdinal=ordinal;
  for(std::size_t li=0;li<component.spans.size();++li){const auto si=component.spans[li];certificate.spans.push_back(problem.spans[si].id);certificate.schedule.push_back({problem.spans[si].id,problem.preferred[si],solved.counts[li],problem.spans[si].supportPieces});}
  certificate.incidences=component_incidences(problem,component);for(const auto &inc:certificate.incidences)certificate.incidenceIds.push_back(inc.id);
  std::map<ConformitySpanId,EInt> counts;for(const auto &entry:certificate.schedule)counts.emplace(entry.span,entry.count);
  for(auto globalRow:component.rows){ConformityRowCertificate row{problem.rows[globalRow],EInt(0),EInt(0),false};for(const auto &inc:certificate.incidences)if(inc.id.region==row.row.region&&inc.family==row.row.family){const auto &count=counts.at(inc.span);row.signedBalance+=EInt(static_cast<int>(inc.sign))*count;row.unsignedBoundaryCount+=count;}row.parityEven=row.unsignedBoundaryCount%EInt(2)==EInt(0);certificate.rows.push_back(std::move(row));}
  certificate.objective=solved.objective;certificate.workLedger=solved.ledger;certificate.finiteCapU=solved.u;certificate.radixQ=solved.q;certificate.lexicographicScaleL=solved.l;certificate.terminalWitness=solved.terminalWitness;
  certificate.theoremEvidence.exactIntegralProblem=true;certificate.theoremEvidence.terminalZeroDemand=true;certificate.theoremEvidence.perfectMatchingOptimalityCertified=true;
  certificate.sourceDigest=topology.source_digest();certificate.networkDigest=topology.network_digest();certificate.cutGraphDigest=topology.cut_graph_digest();certificate.topologyPlanDigest=topology.semantic_digest();certificate.targetMetricDigest=problem.targetMetricDigest;certificate.normalizedProblemDigest=problemDigest;
  return certificate;
}

ConformityInfeasibilityReason public_reason(global_conformity_detail::ExactScheduleInfeasibilityKind kind) {
  switch(kind){case global_conformity_detail::ExactScheduleInfeasibilityKind::BalanceCut:return ConformityInfeasibilityReason::BalanceCut;case global_conformity_detail::ExactScheduleInfeasibilityKind::PositivityCut:return ConformityInfeasibilityReason::PositivityCut;case global_conformity_detail::ExactScheduleInfeasibilityKind::ParityCut:return ConformityInfeasibilityReason::ParityCut;}return ConformityInfeasibilityReason::BalanceCut;
}
ConformityInfeasibleSubset make_infeasible_subset(const GlobalTopologyPlan &topology,
    const global_conformity_detail::NormalizedConformityProblem &problem,const Component &component,
    std::size_t ordinal,const global_conformity_detail::ExactScheduleInfeasibility &witness,std::uint64_t problemDigest) {
  ConformityInfeasibleSubset subset;subset.componentOrdinal=ordinal;subset.reason=public_reason(witness.kind);
  for(auto si:component.spans)subset.spans.push_back(problem.spans[si].id);auto incidences=component_incidences(problem,component);for(const auto &inc:incidences)subset.incidenceIds.push_back(inc.id);
  for(auto ri:component.rows)subset.regions.push_back(problem.rows[ri].region);std::sort(subset.regions.begin(),subset.regions.end());subset.regions.erase(std::unique(subset.regions.begin(),subset.regions.end()),subset.regions.end());
  subset.witness.rowOrdinals=witness.rowOrdinals;subset.witness.doubleCoverNodeCount=witness.doubleCoverNodeCount;subset.witness.reachableDoubleCoverNodes=witness.reachableDoubleCoverNodes;subset.witness.requiredFlow=witness.requiredFlow;subset.witness.achievedFlow=witness.achievedFlow;subset.witness.cutCapacity=witness.cutCapacity;
  subset.sourceDigest=topology.source_digest();subset.networkDigest=topology.network_digest();subset.cutGraphDigest=topology.cut_graph_digest();subset.topologyPlanDigest=topology.semantic_digest();subset.targetMetricDigest=problem.targetMetricDigest;subset.normalizedProblemDigest=problemDigest;return subset;
}
}

GlobalConformityOutcomeBuildResult build_global_conformity_outcome(const GlobalTopologyPlan &topology,const GlobalConformityInput &input) {
  try {
    const auto known=as_known_feasible(input);auto normalizedResult=global_conformity_detail::normalize_global_conformity_problem(topology,known);
    if(auto *error=std::get_if<GlobalConformityPlanError>(&normalizedResult))return GlobalConformityOutcomeBuildResult(*error);
    const auto &problem=std::get<global_conformity_detail::NormalizedConformityProblem>(normalizedResult);const auto digest=normalized_problem_digest(topology,problem);
    GlobalConformityOutcome outcome;outcome.sourceDigest=topology.source_digest();outcome.networkDigest=topology.network_digest();outcome.cutGraphDigest=topology.cut_graph_digest();outcome.topologyPlanDigest=topology.semantic_digest();outcome.targetMetricDigest=problem.targetMetricDigest;outcome.normalizedProblemDigest=digest;
    const auto components=connected_components(problem);
    for(std::size_t ordinal=0;ordinal<components.size();++ordinal){const auto local=make_local_component(problem,components[ordinal]);auto solved=global_conformity_detail::solve_exact_schedule(local.globalRows.size(),local.solver);if(solved.success){outcome.scheduledComponents.push_back(make_certificate(topology,problem,components[ordinal],ordinal,solved,digest));continue;}if(solved.infeasibility){outcome.infeasibleSubsets.push_back(make_infeasible_subset(topology,problem,components[ordinal],ordinal,*solved.infeasibility,digest));continue;}return GlobalConformityOutcomeBuildResult(cp2_error(solved.failure.find("matching")!=std::string::npos?GlobalConformityPlanErrorCode::ExactMatchingFailed:GlobalConformityPlanErrorCode::ExactValidationFailed,solved.failure));}
    if(outcome.infeasibleSubsets.empty()){
      auto legacy=GlobalConformityPlan::make_known_feasible(topology,known);if(!legacy)return GlobalConformityOutcomeBuildResult(legacy.error());
      std::map<ConformitySpanId,EInt> componentCounts;for(const auto &certificate:outcome.scheduledComponents)for(const auto &entry:certificate.schedule)componentCounts.emplace(entry.span,entry.count);
      for(const auto &entry:legacy.value().schedule()){auto it=componentCounts.find(entry.span);if(it==componentCounts.end()||it->second!=entry.count)return GlobalConformityOutcomeBuildResult(cp2_error(GlobalConformityPlanErrorCode::ExactValidationFailed,"CP2 component schedule diverged from accepted CP1 feasible semantics"));}
      outcome.feasiblePlan=legacy.value();
    }
    if(const auto validation=validate_global_conformity_outcome(topology,input,outcome))return GlobalConformityOutcomeBuildResult(*validation);
    return GlobalConformityOutcomeBuildResult(std::move(outcome));
  } catch(const std::exception &e) { return GlobalConformityOutcomeBuildResult(cp2_error(GlobalConformityPlanErrorCode::ExactValidationFailed,e.what())); }
}

const char* global_conformity_infeasibility_reason_name(ConformityInfeasibilityReason reason) noexcept {
  switch(reason){case ConformityInfeasibilityReason::BalanceCut:return "BalanceCut";case ConformityInfeasibilityReason::PositivityCut:return "PositivityCut";case ConformityInfeasibilityReason::ParityCut:return "ParityCut";}return "UnknownConformityInfeasibilityReason";
}

}  // namespace directional::geometry
