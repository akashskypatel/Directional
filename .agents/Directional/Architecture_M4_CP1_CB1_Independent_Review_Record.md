# M4-CP1-CB1-REV Independent Review — Exact Polynomial Bi-flow Contract

**Status:** REVIEW COMPLETE / CB1 STOP UPHELD / SOLVER CONTRACT AMENDED / EXACT NEXT = `M4-CP1-CB2`
**Turn:** `M4-CP1-CB1-REV` independent REVIEW + PLAN / runtime-free
**Date:** 2026-09-09/10 UTC

## 1. Verdict

The `M4-CP1-CB1` stop was correct. The frozen contract asked one bounded Code + Build turn to invent or infer a solver
that was simultaneously arbitrary-precision, exact-lexicographic, bi-directed, magnitude-independent and backed by an
implementation-specific polynomial transition budget. The named implementation (`libSatsuma`) did not satisfy that
surface, and the cited exact Bi-MDF refinement proof did not supply the frozen polynomial iteration count.

The review does **not** weaken M4 to heuristic or merely finite convergence. It instead specializes the already-frozen
M4 objective to a simpler exact problem and removes one unsupported evidence representation:

1. the semantic objective remains exactly `J(x) = (sum |x_s-d_s|, x_1, ..., x_E)`;
2. that L1 objective is transformed exactly to **Integral Bi-directed Minimum-Cost Flow (Bi-MCF)** with finite,
   input-derived capacities;
3. a proved finite optimum cap permits an exact mixed-radix implementation encoding of the lexicographic tie-break;
4. the production solver primitive is **Gabow 1983 arbitrary-capacity minimum-cost biflow**, whose published bound is
   `O(E'^2 log V' log Cmax)` for largest capacity `Cmax`;
5. `libSatsuma` remains useful as an illustrative/reference formulation, but is no longer M4's normative implementation
   authority;
6. the old requirement for a precomputed scalar `P(V,E,B)` decremented on every internal transition is withdrawn.
   The polynomial solver theorem, exact input-derived capacity/cost bit-width bounds, and auditable per-phase counters
   are the WorkLedger authority instead;
7. generic independent optimality certification remains CP2 work. CP1 independently validates structure, bindings,
   feasibility, objective reconstruction, encoding consistency and digest, while focused CP1 tests compare the solver
   to a separate tiny exact oracle. CP2 adds the scalable carried optimality witness and production verifier before
   CP3 cuts A4 over.

No implementation, compile, package, selector mutation, Directional runtime, test or benchmark occurred in this review.
Stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**, packages **113**.

## 2. Authority independently re-checked

Entering branch authority before this review's control marker was
`0edf8042b5b01d5fef423790669274e8da62ff63`. Exact source materialization used source-snapshot run `34423780205`,
snapshot job `102704615928`, event/control SHA `61e5b4394a9e91407a2b084a773c4cafaa8d6b6a`, artifact `10131877788`,
provider digest `sha256:38cc234cc3eb46e4d01536979ebb89f43df8bef9fb553ad7207aff872e64046e`, archive digest
`sha256:4ec6c493555d05580c5615c05fa4b6d636c03a9118b0830b8c635bc2f41af46a`, and 5222/5222 manifest files verified.
The snapshot records `runtimeExecution=false`.

The blocker facts were independently re-checked against upstream `cgg-bern/libSatsuma` commit
`4e96979ecb11bbfe8d9c05e8f8be1ecb992ca5fd`:

- `src/libsatsuma/Problems/BiFlowGraph.hh` declares `FlowScalar = int`;
- `src/libsatsuma/Problems/BiMDF.hh` declares `TargetScalar = double` and `CostScalar = double`;
- its `BiMCF_to_BMatching` reduction also documents that non-zero demands are not supported in that path.

Those facts make an as-is libSatsuma wrapper unsuitable for M4's semantic count/cost surface.

The research basis is:

- Heistermann, Warnett, Bommes, *Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization*, ACM TOG 42(4),
  2023, DOI `10.1145/3592437`. Its §1.2–§1.3 gives the exact positive/negative-deviation linearization of an L1
  quantization objective; §3.2 defines integral bi-flows with arbitrary node demands; §3.2.1 gives the standard
  outer-edge elimination; §3.3 defines Integral Bi-MCF; §3.5 uses the same `f=g+f+−f−` transformation for Bi-MDF.
- Gabow, *An Efficient Reduction Technique for Degree-Constrained Subgraph and Bidirected Network Flow Problems*,
  STOC 1983, DOI `10.1145/800061.808776`. For minimum-cost biflow with arbitrary integral capacities, the published
  running time is `O(E^2 log V log C)`, where `C` is the largest capacity.

The 2023 paper's iterative-refinement theorem remains valid background but is not the production complexity authority
for CP1.

## 3. Why the frozen L1 objective does not require a general convex Bi-MDF solver

Let `A` be the exact normalized signed-incidence matrix from M4 §6, with one column `A_s` per semantic span and one row
per `(NetworkRegionId, U|V)` constraint. Let `d_s >= 1` be the exact preferred integer count already frozen by §5.
The semantic feasible set is

`A x = 0`, `x_s >= 1`, `x integral`.

The primary objective is

`C(x) = sum_s |x_s-d_s|`.

For every span introduce nonnegative integer deviation variables `p_s,n_s` and write

`x_s = d_s + p_s - n_s`, with `0 <= n_s <= d_s-1`.

Then balance is exactly

`A p - A n = -A d`.

Graphically, `p_s` uses the original bi-directed incidence column `A_s`; `n_s` uses the reversed column `-A_s`.
Assign unit primary cost to both. At a primary optimum, `p_s` and `n_s` cannot both be positive: subtracting
`min(p_s,n_s)` from both leaves `x` and every balance unchanged and strictly decreases cost. Therefore

`sum_s (p_s+n_s) = sum_s |x_s-d_s| = C(x)`

at every optimum. This is an exact Integral Bi-MCF formulation, not an approximation and not a generic ILP.

This specialization is materially simpler than freezing a general separable-convex Bi-MDF implementation. It also
matches the linearization already used in the 2023 paper; M4's distinct contribution is to keep all values exact and to
prove a magnitude-independent finite capacity bound rather than expanding work proportional to a numeric deviation
range.

## 4. A finite optimum cap exists with polynomial encoded width

The original CB1 definition rejected scalarization because no safe magnitude bound had been proved. That premise can be
removed without scanning any count range.

Let the semantic incidence graph contain `V` rows and `E` span columns. Each column has at most two signed ends and
Euclidean norm at most `2` (including a `+/-2` same-row loop). Assume the CP1 component is feasible, so the cone

`K = {x >= 0 | A x = 0}`

contains a strictly positive integer vector.

### 4.1 Small positive circulation lemma

Every extreme ray of the rational cone `K` is supported on a minimally dependent set of columns. A primitive integer
ray generator can be written from signed minors of a full-rank submatrix. By Hadamard's inequality, because every
participating column has norm at most `2`, each such minor has absolute value at most `2^V`.

A strictly positive feasible vector is a nonnegative combination of extreme rays. For every coordinate `s`, at least
one contributing extreme ray is positive in coordinate `s`. Choose one primitive ray for each coordinate and sum the
chosen rays. The result is an integer circulation `x0 > 0` with

`1 <= (x0)_s <= H`, where `H = E * 2^V`.

Zero incidence columns are the trivial one-coordinate ray and satisfy the same bound. This is a proof object only; the
implementation does not enumerate extreme rays or determinants.

### 4.2 Optimum coordinate cap

Let `D = sum_s d_s`. The feasible witness above gives

`C(x0) <= D + E*H`.

Therefore any primary optimum `x*` satisfies `C(x*) <= D + E*H`, and for every coordinate

`x*_s <= d_s + C(x*) <= 2D + E*H`.

Freeze

`U = 2D + E*H = 2D + E^2 * 2^V`.

Adding `x_s <= U` cannot remove a primary optimum. Its **numeric value may be large**, but its encoded bit width is
`O(bitwidth(D) + V + log E)`. No loop, allocation or graph expansion may be linear in `U`, `H`, `D`, `d_s`, or an exact
count magnitude.

Thus the deviation edges have finite capacities

- `0 <= p_s <= U-d_s`;
- `0 <= n_s <= d_s-1`.

Both are represented by arbitrary-precision `EInt`; conversion to machine index types is forbidden.

## 5. Exact lexicographic tie-breaking without heuristic big-M

The semantic objective remains the vector `J`; scalarization is only a solver encoding.

Let canonical spans be `s_1..s_E`, set `Q=U+1`, `L=Q^E`, and

`q_i = Q^(E-i)` for `i=1..E`.

Because every `x_i` lies in `1..U`, each is a valid base-`Q` digit. Define

`S(x) = sum_i q_i x_i`.

Then numeric order of `S` is exactly lexicographic order of `(x_1,...,x_E)`, and the total possible variation of `S`
is strictly less than `L`. Consequently

`F(x) = L*C(x) + S(x)`

has exactly the same ordering as the semantic vector `J(x)`.

On the deviation graph, after dropping the constant `S(d)`, assign exact integer edge costs

- `cost(p_i) = L + q_i`;
- `cost(n_i) = L - q_i`.

Both are positive. As shown in §3, an optimum never has `p_i,n_i` simultaneously positive, so the transformed scalar
cost equals `F(x)-S(d)`. The returned minimizer is therefore exactly the unique `J`-minimum schedule.

This is **not** the forbidden arbitrary big-M pattern. `U`, `Q` and `L` are theorem-derived exact values, the proof is
part of the contract, arithmetic is arbitrary precision, and producer/validator independently recompute the encoding.
The prior blanket prohibition is narrowed to heuristic/unproved finite-weight scalarization. The semantic API never
publishes `F` in place of `J`.

The largest solver cost has bit width `O(E * log(U+1))`, polynomial in encoded input width. Constructing `Q^E` takes
`O(E)` exact multiplications; no numeric-range enumeration is involved.

## 6. Normalization to Gabow's arbitrary-capacity Integral Bi-MCF

The CP1 implementation must freeze one deterministic normalization:

1. canonical semantic row/span order is fixed before solver construction;
2. build `p_s` and `n_s` deviation edges with exact finite capacities and costs from §§4–5;
3. set exact node demand `b = -A d`;
4. omit zero-capacity deviation edges; an aggregated zero semantic column is solver-independent and its unique
   objective-minimizing value is `x_s=d_s`;
5. preserve same-row `+/-2` loops and parallel edges — they are legal bi-directed edges, not cases to deduplicate;
6. eliminate one-ended outer edges by the standard 2023 construction: add deterministic dummy node `partial`, attach
   it as the second `+1` incidence of every outer edge, give it demand `0` or `1` according to the required demand
   parity, and add one zero-cost tail-tail self-loop. Unlike the paper's abstract unbounded loop, CP1 caps this solver
   artifact by `(2E+1) * U`, a semantic-input bound that dominates the maximum compensation any feasible bounded transformed flow can require;
7. the resulting solver graph has `V' <= V+1`, `E' <= 2E+1` before omission of zero-capacity edges and a largest
   capacity `Cmax <= (2E+1) * U`.

The dummy node/loop and deviation edges are solver representation only. They never enter semantic span IDs,
`GlobalConformityPlan` digests, A4 breakpoint identity or selector ordering.

## 7. Complexity and WorkLedger adjudication

The core polynomial requirement is retained. Gabow's arbitrary-integral-capacity minimum-cost biflow bound gives

`O(E'^2 log V' log Cmax)`

combinatorial time. Since `log Cmax` is polynomial in the encoded M4 input width by §4 and exact cost values have
polynomial bit width by §5, arbitrary-precision arithmetic does not turn the algorithm into magnitude-linear work.
Exact cost addition/comparison and capacity arithmetic must stay on `EInt`/exact values; no `convert()` narrowing may
participate in a semantic decision.

What is withdrawn is the old **evidence encoding** that demanded one guessed scalar `P(V,E,B)` before implementation
and decremented `remainingCertifiedSteps` on every internal state transition. Neither Gabow 1983 nor the general
`DESIGN.md` §10.2 requires that representation, and inventing its hidden constant was exactly the CB1 blocker.

The amended `WorkLedger` records at minimum:

- semantic `V,E`, transformed `V',E'`;
- exact `H,U,Cmax` bit widths, not their machine-narrowed values;
- `targetBits`, `capacityBits`, `costBits` and maximum observed exact-integer bit width;
- algorithm identity `Gabow1983ArbitraryCapacityMinCostBiflow` and theorem class
  `O(E'^2 log V' log Cmax)`;
- implementation phase counters, including capacity-scale count (bounded by encoded capacity width), augment/blossom
  or equivalent primitive counts, peak residual edges and any implementation-local finite loop budgets;
- zero retry/reset count.

An implementation loop still needs an explicit finite bound derived from graph/container size or encoded capacity bits.
What is no longer required is pretending those heterogeneous bounds are one literature-supplied countdown. A violated
local bound remains `WorkBoundExceeded`; it is never permission to approximate, retry or switch solvers.

## 8. CP1/CP2 oracle boundary correction

The old CB1 plan asked the CP1 production validator to independently establish generic optimality and lexicographic
minimality while simultaneously declaring that the carried optimality certificate belongs to CP2. That duplicated a
full hard solver before the certification checkpoint and blurred checkpoint ownership.

Freeze the boundary as follows:

- **CP1 producer:** computes the exact known-feasible schedule with the solver above.
- **CP1 independent production validator:** independently rebuilds bindings, spans/support paths, incidence
  multiplicity, binary64 exactification, `R_s`, `d_s`, feasibility, positivity, parity, compact breakpoint arithmetic,
  `C(x)`, semantic lex-vector serialization, `U/Q/L/q_i` encoding consistency, WorkLedger dimensions/bit widths and
  semantic digest. It does **not** claim a generic independent optimality proof.
- **CP1 focused tests:** compare the production solver on fixed small feasible graphs to a separate exact exhaustive or
  closed-form oracle. Enumeration is permitted only inside that test oracle under a hard tiny bound independent of
  production inputs; it is never reused by product code.
- **CP2:** adds an algorithm-native carried optimality witness/certificate and a production independent verifier that
  proves no cheaper admissible schedule exists and that the lexicographic winner is canonical. CP2 remains before CP3,
  so no A4 producer consumes a schedule lacking scalable independent optimality certification.

This is a staging correction, not a reduction in final M4 assurance.

## 9. Rejected alternatives

- **Use libSatsuma as-is:** rejected; machine `int` flow and `double` target/cost types violate exact authority.
- **Port libSatsuma's full iterative Bi-MDF solver and accept finite convergence:** rejected; it weakens the frozen
  polynomial architecture unnecessarily when M4's L1 objective admits a linear Bi-MCF specialization.
- **Generic ILP/IQP/branch-and-bound:** remains prohibited.
- **Enumerate counts/deviations up to `U`:** prohibited. `U` is a capacity proof, not an iteration range.
- **Use a heuristic big-M:** prohibited. Only the exact mixed-radix encoding proved in §5 is authorized.
- **Narrow M4 to orientable/non-T-junction graphs:** rejected. No source proof shows that restriction is semantically
  complete, and it is unnecessary for the selected algorithm.
- **Use floating costs or machine capacities because practical meshes are small:** prohibited; representation must
  satisfy the semantic contract, not only current fixtures.

## 10. Required CB2 prediction and stop rule

`M4-CP1-CB2` must implement exactly the amended contract and stay runtime-free. Its falsifiable prediction is:

- one new immutable A3 known-feasible product and independent structural validator compile with exact GMP/GMPXX
  arithmetic;
- the solver path is the frozen arbitrary-capacity Integral Bi-MCF path, not libSatsuma-as-is, ILP or range search;
- focused tests are compiled but not executed; their source includes an independent bounded tiny optimum oracle and the
  required structural/tamper cases;
- no M3 selector byte changes; the first M4 selector is exact selector365 plus only new CP1 gating identities;
- no A4 production cutover, CP2 certificate/infeasibility production, CP-COND, CP-SCALE or M5/M6 work occurs;
- build evidence reports `runtimeExecution=false` and authoritative GMP/GMPXX linkage.

If implementing Gabow's exact arbitrary-capacity solver reveals that the cited algorithm cannot support the normalized
integer-demand/loop/parallel-edge problem as frozen, or if the proof-only cap/lex encoding is invalidated by a concrete
counterexample, **stop before substituting another algorithm** and return to independent review. Compile errors inside
the declared owner set may be corrected in the same CB as usual.

## 11. Review-turn process note

`READ_MODE=snapshot` was selected because the turn required cross-file review, but one direct one-line handoff read was
issued before the snapshot was materialized. That is a start-of-turn ordering miss under
`TOOL_USE_CONSERVATION_POLICY.md`; it changed no repository semantics or evidence. Further piecemeal source inspection
stopped, exact snapshot authority was obtained, and all substantive review was performed from that verified local
snapshot. This process miss does not change stable product regression accounting.

## 12. Exact successor

**`M4-CP1-CB2` — canonical Code + Build / runtime-free**, under
`Architecture_M4_CP1_CB2_Code_Build_Plan.md`.

No implementation, compile, package, selector execution, Directional runtime, test or benchmark belongs to this review
turn.
