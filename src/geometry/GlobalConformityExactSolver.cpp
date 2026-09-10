// Exact M4 A3 Bi-MDF refinement adapted from the construction disclosed by
// Heistermann, Warnett and Bommes, ACM TOG 42(4), 2023, §§3.6-3.9.
// LEMON is used only for the inner exact weighted-perfect-matching primitive.

#include "GlobalConformityExactSolver.h"
#include "GlobalConformityExactWeight.h"

#include <algorithm>
#include <cstddef>
#include <optional>
#include <queue>
#include <utility>
#include <vector>

#include <lemon/list_graph.h>
#include <lemon/matching.h>

namespace directional::geometry::global_conformity_detail {
namespace {
constexpr int kRefinementM = 2;

EInt exact_from_size(std::size_t value) {
  EInt out(0), two(2);
  for (int bit = static_cast<int>(sizeof(std::size_t) * 8U) - 1; bit >= 0; --bit) {
    out *= two;
    if (((value >> static_cast<unsigned>(bit)) & std::size_t{1}) != 0U) out += EInt(1);
  }
  return out;
}
EInt exact_power(EInt base, std::size_t exponent) {
  EInt result(1);
  while (exponent != 0U) {
    if ((exponent & 1U) != 0U) result *= base;
    exponent >>= 1U;
    if (exponent != 0U) base *= base;
  }
  return result;
}
constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;
void hash_byte(std::uint64_t &hash, std::uint8_t value) { hash ^= value; hash *= kFnvPrime; }
void hash_u64(std::uint64_t &hash, std::uint64_t value) {
  for (unsigned shift=0; shift<64U; shift+=8U) hash_byte(hash, static_cast<std::uint8_t>((value>>shift)&0xffU));
}
void hash_eint(std::uint64_t &hash, const EInt &value) {
  const auto text=value.to_string(); hash_u64(hash,text.size()); for(unsigned char c:text) hash_byte(hash,c);
}
std::uint64_t terminal_problem_digest(std::size_t rows,const std::vector<EInt>&counts,const std::vector<ConformityWpmEdgeWitness>&edges){
  std::uint64_t hash=kFnvOffset; hash_u64(hash,static_cast<std::uint64_t>(kRefinementM)); hash_u64(hash,rows);
  hash_u64(hash,counts.size()); for(const auto&v:counts) hash_eint(hash,v);
  hash_u64(hash,edges.size()); for(const auto&e:edges){hash_u64(hash,e.first);hash_u64(hash,e.second);hash_eint(hash,e.weight);}
  return hash;
}

EInt exact_min(const EInt&a,const EInt&b){return a<b?a:b;}
EInt exact_max(const EInt&a,const EInt&b){return a>b?a:b;}
bool is_even(const EInt&v){return v%EInt(2)==EInt(0);}

struct InternalEdge {
  std::size_t semanticIndex=0U;
  std::vector<SolverIncidenceEnd> ends;
  EInt preferred,lower,upper,lexWeight;
  bool semantic=true;
};

std::vector<EInt> row_balance(std::size_t rows,const std::vector<InternalEdge>&edges,const std::vector<EInt>&flow){
  std::vector<EInt> balance(rows,EInt(0));
  if(flow.size()!=edges.size()) return {};
  for(std::size_t i=0;i<edges.size();++i) for(const auto&e:edges[i].ends) balance[e.row]+=EInt(e.sign)*flow[i];
  return balance;
}
bool exact_feasible(std::size_t rows,const std::vector<InternalEdge>&edges,const std::vector<EInt>&flow){
  if(flow.size()!=edges.size())return false;
  for(std::size_t i=0;i<edges.size();++i)if(flow[i]<edges[i].lower||flow[i]>edges[i].upper)return false;
  auto b=row_balance(rows,edges,flow); if(b.size()!=rows)return false;
  return std::all_of(b.begin(),b.end(),[](const EInt&v){return v==EInt(0);});
}
EInt edge_cost(const InternalEdge&e,const EInt&x,const EInt&L){return e.semantic?L*(x-e.preferred).abs()+e.lexWeight*x:EInt(0);}

std::vector<InternalEdge> eliminate_outer_edges(std::size_t&rows,const std::vector<SolverSpan>&spans,const EInt&U){
  std::vector<InternalEdge> out; out.reserve(spans.size()+1U);
  bool outer=false; const std::size_t boundary=rows;
  for(const auto&s:spans){
    InternalEdge e{s.semanticIndex,s.ends,s.preferred,s.lower,s.upper,s.lexWeight,s.semantic};
    if(e.ends.size()==1U){outer=true;e.ends.push_back({boundary,+1});}
    out.push_back(std::move(e));
  }
  if(outer){
    ++rows;
    out.push_back({spans.size(),{{boundary,-1},{boundary,-1}},EInt(0),EInt(0),exact_from_size(spans.size())*U,EInt(0),false});
  }
  return out;
}

std::vector<EInt> parity_adjust_guess(std::size_t rows,const std::vector<InternalEdge>&edges,const EInt&L,bool&ok,std::optional<ExactScheduleInfeasibility>&infeasibility){
  std::vector<EInt> guess(edges.size(),EInt(0));
  for(std::size_t i=0;i<edges.size();++i) guess[i]=edges[i].semantic?exact_max(edges[i].lower,exact_min(edges[i].preferred,edges[i].upper)):EInt(0);
  auto balance=row_balance(rows,edges,guess); if(balance.size()!=rows){ok=false;return{};}
  std::vector<bool> odd(rows,false); for(std::size_t r=0;r<rows;++r)odd[r]=!is_even(balance[r]);
  std::vector<std::vector<std::pair<std::size_t,std::size_t>>> adj(rows);
  for(std::size_t ei=0;ei<edges.size();++ei){
    if(edges[ei].ends.size()!=2U||edges[ei].ends[0].row==edges[ei].ends[1].row||edges[ei].lower==edges[ei].upper)continue;
    auto a=edges[ei].ends[0].row,b=edges[ei].ends[1].row; adj[a].push_back({b,ei});adj[b].push_back({a,ei});
  }
  for(auto&v:adj)std::sort(v.begin(),v.end());
  std::vector<bool> visited(rows,false); std::vector<std::size_t> parent(rows,rows),parentEdge(rows,edges.size());
  for(std::size_t root=0;root<rows;++root){
    if(visited[root])continue; std::vector<std::size_t> order,stack{root};visited[root]=true;
    while(!stack.empty()){auto u=stack.back();stack.pop_back();order.push_back(u);for(auto it=adj[u].rbegin();it!=adj[u].rend();++it)if(!visited[it->first]){visited[it->first]=true;parent[it->first]=u;parentEdge[it->first]=it->second;stack.push_back(it->first);}}
    for(std::size_t oi=order.size();oi-->1U;){
      auto node=order[oi];if(!odd[node])continue;auto ei=parentEdge[node];
      if(ei>=edges.size()){ok=false;infeasibility=ExactScheduleInfeasibility{ExactScheduleInfeasibilityKind::ParityCut,order};return{};}
      const auto&e=edges[ei];bool down=guess[ei]>e.lower,up=guess[ei]<e.upper;
      if(!down&&!up){ok=false;infeasibility=ExactScheduleInfeasibility{ExactScheduleInfeasibilityKind::ParityCut,order};return{};}
      bool useDown=down;if(down&&up){EInt dc=edge_cost(e,guess[ei]-EInt(1),L)-edge_cost(e,guess[ei],L);EInt uc=edge_cost(e,guess[ei]+EInt(1),L)-edge_cost(e,guess[ei],L);useDown=dc<=uc;}
      guess[ei]+=useDown?EInt(-1):EInt(1);odd[node]=!odd[node];odd[parent[node]]=!odd[parent[node]];
    }
    if(odd[root]){std::sort(order.begin(),order.end());ok=false;infeasibility=ExactScheduleInfeasibility{ExactScheduleInfeasibilityKind::ParityCut,order};return{};}
  }
  ok=true;return guess;
}

struct FlowArc{std::size_t first=0U,second=0U;EInt capacity;};
struct ResidualArc{std::size_t to=0U,reverse=0U;EInt capacity;std::optional<std::size_t> original;bool forward=true;};
struct FlowResult{bool success=false;bool demandMismatch=false;std::vector<EInt> flow;EInt requiredFlow,achievedFlow,cutCapacity;std::vector<std::size_t> reachableNodes;};
FlowResult solve_directed_feasibility(std::size_t nodeCount,const std::vector<FlowArc>&arcs,const std::vector<EInt>&demand){
  FlowResult result;result.flow.assign(arcs.size(),EInt(0));if(demand.size()!=nodeCount)return result;
  const std::size_t source=nodeCount,sink=nodeCount+1U;std::vector<std::vector<ResidualArc>> g(nodeCount+2U);std::vector<FlowArc> original;
  auto add=[&](std::size_t u,std::size_t v,const EInt&cap,std::optional<std::size_t>orig,bool forward){if(cap<EInt(0))return false;auto ui=g[u].size(),vi=g[v].size();g[u].push_back({v,vi,cap,orig,forward});g[v].push_back({u,ui,EInt(0),orig,!forward});original.push_back({u,v,cap});return true;};
  for(std::size_t i=0;i<arcs.size();++i){if(arcs[i].first==arcs[i].second)continue;if(!add(arcs[i].first,arcs[i].second,arcs[i].capacity,i,true))return result;}
  EInt need(0),supply(0);for(std::size_t n=0;n<nodeCount;++n){if(demand[n]>EInt(0)){add(n,sink,demand[n],{},true);need+=demand[n];}else if(demand[n]<EInt(0)){add(source,n,-demand[n],{},true);supply+=-demand[n];}}
  result.requiredFlow=need;
  if(need!=supply){result.demandMismatch=true;result.achievedFlow=supply;return result;}
  EInt total(0);
  while(total<need){
    std::vector<std::size_t> pn(g.size(),g.size()),pa(g.size());std::queue<std::size_t>q;pn[source]=source;q.push(source);
    while(!q.empty()&&pn[sink]==g.size()){auto u=q.front();q.pop();for(std::size_t ai=0;ai<g[u].size();++ai){const auto&e=g[u][ai];if(e.capacity<=EInt(0)||pn[e.to]!=g.size())continue;pn[e.to]=u;pa[e.to]=ai;q.push(e.to);if(e.to==sink)break;}}
    if(pn[sink]==g.size()){
      std::vector<bool> reachable(g.size(),false);std::queue<std::size_t>rq;reachable[source]=true;rq.push(source);
      while(!rq.empty()){auto u=rq.front();rq.pop();for(const auto&e:g[u])if(e.capacity>EInt(0)&&!reachable[e.to]){reachable[e.to]=true;rq.push(e.to);}}
      for(std::size_t n=0;n<reachable.size();++n)if(reachable[n])result.reachableNodes.push_back(n);
      EInt cut(0);for(const auto&e:original)if(reachable[e.first]&&!reachable[e.second])cut+=e.capacity;
      result.achievedFlow=total;result.cutCapacity=cut;return result;
    }
    EInt delta=need-total;for(auto v=sink;v!=source;v=pn[v])delta=exact_min(delta,g[pn[v]][pa[v]].capacity);if(delta<=EInt(0))return result;
    for(auto v=sink;v!=source;v=pn[v]){auto&e=g[pn[v]][pa[v]];auto&r=g[v][e.reverse];e.capacity-=delta;r.capacity+=delta;if(e.original){result.flow[*e.original]+=e.forward?delta:-delta;}}
    total+=delta;
  }
  if(std::any_of(result.flow.begin(),result.flow.end(),[](const EInt&v){return v<EInt(0);} ))return FlowResult{};result.success=true;result.achievedFlow=total;result.cutCapacity=total;return result;
}

struct BiResidual{std::size_t edge=0U;std::vector<SolverIncidenceEnd>ends;EInt capacity;bool positive=true;};
struct FeasibleStartResult{bool success=false;std::vector<EInt> counts;std::size_t nodes=0U,arcs=0U;std::optional<ExactScheduleInfeasibility> infeasibility;};
FeasibleStartResult double_cover_feasible_start(std::size_t rows,const std::vector<InternalEdge>&edges,const std::vector<EInt>&guess){
  FeasibleStartResult out;auto imbalance=row_balance(rows,edges,guess); if(imbalance.size()!=rows)return out;std::vector<EInt>demand(rows,EInt(0));
  for(std::size_t r=0;r<rows;++r){demand[r]=-imbalance[r];if(!is_even(demand[r])){out.infeasibility=ExactScheduleInfeasibility{ExactScheduleInfeasibilityKind::ParityCut,{r}};return out;}}
  std::vector<BiResidual> residual;for(std::size_t i=0;i<edges.size();++i){EInt f=edges[i].upper-guess[i],b=guess[i]-edges[i].lower;if(f>EInt(0))residual.push_back({i,edges[i].ends,f,true});if(b>EInt(0)){auto rev=edges[i].ends;for(auto&e:rev)e.sign=-e.sign;residual.push_back({i,std::move(rev),b,false});}}
  out.nodes=rows*2U;std::vector<EInt>dd(out.nodes,EInt(0));for(std::size_t r=0;r<rows;++r){dd[2*r]=demand[r]/EInt(2);dd[2*r+1]=-demand[r]/EInt(2);}std::vector<FlowArc>arcs;struct C{std::size_t a,b;};std::vector<C>copies;copies.reserve(residual.size());
  auto plus=[](std::size_t r){return 2*r;};auto minus=[](std::size_t r){return 2*r+1;};
  for(const auto&e:residual){if(e.ends.size()!=2U)return out;auto a=e.ends[0],b=e.ends[1];std::size_t s0=a.sign<0?plus(a.row):minus(a.row),d0=b.sign>0?plus(b.row):minus(b.row),s1=b.sign<0?plus(b.row):minus(b.row),d1=a.sign>0?plus(a.row):minus(a.row);EInt h=e.capacity/EInt(2),other=e.capacity-h;auto ia=arcs.size();arcs.push_back({s0,d0,h});auto ib=arcs.size();arcs.push_back({s1,d1,other});copies.push_back({ia,ib});}
  out.arcs=arcs.size();auto solved=solve_directed_feasibility(out.nodes,arcs,dd);if(!solved.success){ExactScheduleInfeasibility witness;witness.kind=solved.demandMismatch?ExactScheduleInfeasibilityKind::BalanceCut:ExactScheduleInfeasibilityKind::PositivityCut;witness.doubleCoverNodeCount=out.nodes;witness.reachableDoubleCoverNodes=solved.reachableNodes;witness.requiredFlow=solved.requiredFlow;witness.achievedFlow=solved.achievedFlow;witness.cutCapacity=solved.cutCapacity;out.infeasibility=std::move(witness);return out;}
  auto result=guess;for(std::size_t i=0;i<residual.size();++i){EInt amount=solved.flow[copies[i].a]+solved.flow[copies[i].b];result[residual[i].edge]+=residual[i].positive?amount:-amount;}
  if(!exact_feasible(rows,edges,result))return out;out.success=true;out.counts=std::move(result);return out;
}

struct RefinementEdge{std::size_t original=0U;std::vector<SolverIncidenceEnd>ends;int capacity=1;EInt cost;bool positive=true;};
struct BEdge{std::size_t first=0U,second=0U;int capacity=0;EInt weight;std::optional<std::size_t> residual;};
struct RefinementResult{bool success=false;std::vector<EInt>candidate;EInt costChange;std::size_t biEdges=0U,bNodes=0U,bEdges=0U,wNodes=0U,wEdges=0U;ConformityTerminalRefinementWitness witness;};
RefinementResult solve_refinement(std::size_t rows,const std::vector<InternalEdge>&edges,const std::vector<EInt>&current,const EInt&L){
  RefinementResult out;std::vector<RefinementEdge>residual;residual.reserve(edges.size()*4U);
  for(std::size_t ei=0;ei<edges.size();++ei){EInt prev=edge_cost(edges[ei],current[ei],L);for(int step=1;step<=kRefinementM;++step){EInt next=current[ei]+EInt(step);if(next>edges[ei].upper)break;EInt cost=edge_cost(edges[ei],next,L);residual.push_back({ei,edges[ei].ends,1,cost-prev,true});prev=cost;}prev=edge_cost(edges[ei],current[ei],L);for(int step=1;step<=kRefinementM;++step){EInt next=current[ei]-EInt(step);if(next<edges[ei].lower)break;auto rev=edges[ei].ends;for(auto&e:rev)e.sign=-e.sign;EInt cost=edge_cost(edges[ei],next,L);residual.push_back({ei,std::move(rev),1,cost-prev,false});prev=cost;}}
  out.biEdges=residual.size();std::vector<int>heads(rows,0),tails(rows,0);for(const auto&e:residual)for(const auto&end:e.ends)(end.sign>0?heads[end.row]:tails[end.row])+=e.capacity;std::vector<int>through(rows);for(std::size_t r=0;r<rows;++r)through[r]=std::min(kRefinementM,std::min(heads[r],tails[r]));
  out.bNodes=rows*2U;std::vector<int>degree(out.bNodes,0);auto in=[](std::size_t r){return 2*r;};auto outn=[](std::size_t r){return 2*r+1;};std::vector<BEdge>bedges;
  for(std::size_t r=0;r<rows;++r){degree[in(r)]=through[r];degree[outn(r)]=through[r];if(through[r]>0)bedges.push_back({in(r),outn(r),through[r],EInt(0),{}});}
  for(std::size_t ri=0;ri<residual.size();++ri){if(residual[ri].ends.size()!=2U)return out;auto map=[&](const SolverIncidenceEnd&e){return e.sign>0?in(e.row):outn(e.row);};bedges.push_back({map(residual[ri].ends[0]),map(residual[ri].ends[1]),1,-residual[ri].cost,ri});}
  out.bEdges=bedges.size();std::vector<std::size_t>first(out.bNodes);std::size_t wcount=0;for(std::size_t n=0;n<out.bNodes;++n){first[n]=wcount;wcount+=static_cast<std::size_t>(degree[n]);}
  struct WEdge{std::size_t a,b;EInt weight;std::optional<std::size_t>bedge;};std::vector<WEdge>wedges;
  for(std::size_t bi=0;bi<bedges.size();++bi){const auto&e=bedges[bi];int du=degree[e.first],dv=degree[e.second];if(du==0||dv==0||e.capacity<=0)continue;
    if(e.capacity>=std::min(du,dv)){for(int i=0;i<du;++i)for(int j=0;j<dv;++j){auto u=first[e.first]+static_cast<std::size_t>(i),v=first[e.second]+static_cast<std::size_t>(j);if(u!=v)wedges.push_back({u,v,e.weight,bi});}}
    else{for(int c=0;c<e.capacity;++c){auto left=wcount++,right=wcount++;wedges.push_back({left,right,EInt(0),{}});for(int i=0;i<du;++i)wedges.push_back({first[e.first]+static_cast<std::size_t>(i),left,e.weight,bi});for(int j=0;j<dv;++j)wedges.push_back({first[e.second]+static_cast<std::size_t>(j),right,EInt(0),{}});}}
  }
  out.wNodes=wcount;out.wEdges=wedges.size();if((wcount&1U)!=0U)return out;
  out.witness.refinementM=kRefinementM;out.witness.terminalCounts=current;out.witness.biMcfEdgeCount=out.biEdges;out.witness.bMatchingNodeCount=out.bNodes;out.witness.bMatchingEdgeCount=out.bEdges;out.witness.wpmNodeCount=wcount;
  for(const auto&e:wedges)out.witness.wpmEdges.push_back({e.a,e.b,e.weight,false});
  if(wcount==0U){out.success=true;out.candidate=current;out.costChange=EInt(0);out.witness.matchingPrimalWeight=EInt(0);out.witness.matchingDualValue=EInt(0);out.witness.semanticCostChange=EInt(0);out.witness.terminalProblemDigest=terminal_problem_digest(rows,current,out.witness.wpmEdges);return out;}
  lemon::ListGraph graph;std::vector<lemon::ListGraph::Node>nodes;nodes.reserve(wcount);for(std::size_t i=0;i<wcount;++i)nodes.push_back(graph.addNode());lemon::ListGraph::EdgeMap<ExactWeight>weights(graph);lemon::ListGraph::EdgeMap<std::size_t>desc(graph,wedges.size());
  for(std::size_t wi=0;wi<wedges.size();++wi){auto e=graph.addEdge(nodes[wedges[wi].a],nodes[wedges[wi].b]);weights[e]=ExactWeight(wedges[wi].weight);desc[e]=wi;}
  using Matching=lemon::MaxWeightedPerfectMatching<lemon::ListGraph,lemon::ListGraph::EdgeMap<ExactWeight>>;Matching matching(graph,weights);if(!matching.run())return out;
  std::vector<int>bflow(bedges.size(),0);EInt primal(0);for(lemon::ListGraph::EdgeIt e(graph);e!=lemon::INVALID;++e)if(matching.matching(e)){auto wi=desc[e];if(wi<wedges.size()){out.witness.wpmEdges[wi].matched=true;primal+=wedges[wi].weight;if(wedges[wi].bedge)++bflow[*wedges[wi].bedge];}}
  out.witness.matchingPrimalWeight=primal;out.witness.matchingDualScale=Matching::dualScale;out.witness.matchingDualValue=matching.dualValue().exact();
  out.witness.nodeDualValues.reserve(wcount);for(const auto&node:nodes)out.witness.nodeDualValues.push_back(matching.nodeValue(node).exact());
  for(int bi=0;bi<matching.blossomNum();++bi){ConformityWpmBlossomWitness blossom;blossom.dualValue=matching.blossomValue(bi).exact();for(typename Matching::BlossomIt it(matching,bi);it!=lemon::INVALID;++it){lemon::ListGraph::Node node=it;blossom.nodes.push_back(static_cast<std::size_t>(graph.id(node)));}std::sort(blossom.nodes.begin(),blossom.nodes.end());out.witness.blossoms.push_back(std::move(blossom));}
  std::vector<int>rflow(residual.size(),0);for(std::size_t bi=0;bi<bedges.size();++bi){if(bflow[bi]<0||bflow[bi]>bedges[bi].capacity)return out;if(bedges[bi].residual)rflow[*bedges[bi].residual]+=bflow[bi];}
  out.candidate=current;out.costChange=EInt(0);for(std::size_t ri=0;ri<residual.size();++ri){int amount=rflow[ri];if(amount==0)continue;out.costChange+=residual[ri].cost*EInt(amount);out.candidate[residual[ri].original]+=residual[ri].positive?EInt(amount):EInt(-amount);}
  if(!exact_feasible(rows,edges,out.candidate))return out;out.witness.semanticCostChange=out.costChange;out.witness.terminalProblemDigest=terminal_problem_digest(rows,current,out.witness.wpmEdges);out.success=true;return out;
}

std::size_t max_bits(const std::vector<EInt>&values){std::size_t bits=0;for(const auto&v:values)bits=std::max(bits,v.magnitude_bits());return bits;}
}

ConformityObjectiveValue evaluate_objective(const std::vector<SolverSpan>&spans,const std::vector<EInt>&counts,const EInt&L){ConformityObjectiveValue out;out.primaryDeviation=EInt(0);out.scalarValue=EInt(0);for(const auto&s:spans){if(!s.semantic||s.semanticIndex>=counts.size())continue;const auto&x=counts[s.semanticIndex];out.primaryDeviation+=(x-s.preferred).abs();out.scalarValue+=L*(x-s.preferred).abs()+s.lexWeight*x;out.canonicalCounts.push_back(x);}return out;}

ExactScheduleSolveResult solve_exact_schedule(std::size_t semanticRows,std::vector<SolverSpan>spans){
  ExactScheduleSolveResult out;const std::size_t E=spans.size(),V=semanticRows;if(E==0U||V==0U){out.failure="empty exact schedule component";return out;}EInt D(0);std::vector<EInt>preferred;preferred.reserve(E);for(const auto&s:spans){if(s.preferred<EInt(1)){out.failure="non-positive exact preferred count";return out;}D+=s.preferred;preferred.push_back(s.preferred);}EInt e=exact_from_size(E);out.h=e*exact_power(EInt(2),V);out.u=EInt(2)*D+e*out.h;out.q=out.u+EInt(1);out.l=exact_power(out.q,E);for(std::size_t i=0;i<E;++i){spans[i].lower=EInt(1);spans[i].upper=out.u;spans[i].lexWeight=exact_power(out.q,E-i-1U);}std::size_t solverRows=semanticRows;auto edges=eliminate_outer_edges(solverRows,spans,out.u);
  bool parity=false;auto guess=parity_adjust_guess(solverRows,edges,out.l,parity,out.infeasibility);if(!parity){out.failure="T-join parity adjustment failed";return out;}auto initializer=double_cover_feasible_start(solverRows,edges,guess);if(!initializer.success){out.infeasibility=initializer.infeasibility;out.failure="exact asymmetric double-cover feasible start failed";return out;}auto current=std::move(initializer.counts);std::size_t dcNodes=initializer.nodes,dcArcs=initializer.arcs;
  out.ledger.semanticRowCount=semanticRows;out.ledger.semanticSpanCount=E;out.ledger.initializerNodeCount=dcNodes;out.ledger.initializerArcCount=dcArcs;out.ledger.initializerExactFeasibilityValidated=exact_feasible(solverRows,edges,current);if(!out.ledger.initializerExactFeasibilityValidated){out.failure="initializer independent exact feasibility check failed";return out;}out.ledger.refinementM=kRefinementM;out.ledger.hBitWidth=out.h.magnitude_bits();out.ledger.uBitWidth=out.u.magnitude_bits();out.ledger.qBitWidth=out.q.magnitude_bits();out.ledger.lBitWidth=out.l.magnitude_bits();out.ledger.maximumTargetBitWidth=max_bits(preferred);out.ledger.maximumCapacityBitWidth=out.u.magnitude_bits();std::vector<EInt>semantic(E,EInt(0));for(std::size_t i=0;i<E;++i)semantic[i]=current[i];auto objective=[&]{return evaluate_objective(spans,semantic,out.l);};
  // DEFN-R1 R9.2 theorem reconciliation: Cor. 3.7 establishes finite
  // convergence for fixed M; Thm. 3.8 establishes that a non-improving
  // refinement is globally optimal for M >= 2; Cor. 3.9 therefore yields the
  // exact refinement algorithm. The production value is frozen to M=2.
  while(true){auto before=objective();auto r=solve_refinement(solverRows,edges,current,out.l);if(!r.success){out.failure="exact weighted-perfect-matching refinement failed";return out;}out.ledger.peakMatchingNodeCount=std::max(out.ledger.peakMatchingNodeCount,r.wNodes);out.ledger.peakMatchingEdgeCount=std::max(out.ledger.peakMatchingEdgeCount,r.wEdges);if(r.costChange>=EInt(0)){out.ledger.terminalRefinementCostChange=r.costChange;out.ledger.terminalExactNonImprovementValidated=true;out.terminalWitness=std::move(r.witness);break;}current=std::move(r.candidate);for(std::size_t i=0;i<E;++i)semantic[i]=current[i];auto after=objective();if(!(after.scalarValue<before.scalarValue)){out.failure="refinement did not strictly decrease exact objective";return out;}out.ledger.refinements.push_back({before,after,r.biEdges,r.bNodes,r.bEdges,r.wNodes,r.wEdges});++out.ledger.refinementCount;}
  out.counts=semantic;out.objective=objective();out.ledger.maximumCountBitWidth=max_bits(out.counts);std::vector<EInt>costs;for(std::size_t i=0;i<E;++i)costs.push_back(out.l*(out.counts[i]-spans[i].preferred).abs()+spans[i].lexWeight*out.counts[i]);out.ledger.maximumCostBitWidth=max_bits(costs);out.success=true;return out;
}
} // namespace directional::geometry::global_conformity_detail
