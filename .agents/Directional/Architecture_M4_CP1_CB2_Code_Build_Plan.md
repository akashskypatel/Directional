# M4-CP1-CB2 Code + Build Plan — Exact Global Conformity Schedule

**Status:** FROZEN BY `M4-CP1-CB1-REV` / EXACT NEXT = `M4-CP1-CB2`
**Turn type:** canonical Code + Build
**Runtime:** PROHIBITED
**Date:** 2026-09-09/10 UTC

## 1. Objective and assumptions

Implement the first M4 A3 schedule-authority slice after the CB1 solver-contract stop. The semantic problem is the
amended exact L1 Integral Bi-MCF contract in `Architecture_M4_DEFN_Frozen_Definitions.md` §7 and
`Architecture_M4_CP1_CB1_Independent_Review_Record.md`.

Assumptions fixed by review rather than left for CB2 to infer:

- CP1 inputs are deterministic constructed components whose positive feasibility is part of the focused fixture
  precondition; CP1 does not yet expose the production infeasible-subset alternative;
- one semantic variable exists per full A2b boundary arc; support pieces never own independent counts;
- exact count/ordinal/capacity/cost arithmetic uses repository arbitrary-precision `EInt`, with authoritative builds
  selecting GMP/GMPXX;
- the solver primitive is Gabow 1983 arbitrary-capacity minimum-cost biflow over the review's exact L1 deviation
  transformation and mixed-radix tie encoding;
- no loop or storage may scale linearly with the **numeric value** of a count, target, capacity bound `U`, or cost radix;
- scalable independent optimality certification is CP2 work. CP1 still proves solver behavior against a separate tiny
  exact test oracle and independently validates every structural/feasibility/objective/encoding property frozen below.

If source inspection disproves any of these assumptions, stop and return to review rather than silently choosing a new
solver or broadening the graph class.

## 2. Entering authority

- M3 remains CLOSED / ACCEPTED;
- reviewed runtime authority remains package113/source `6dae3f6959551f6dcdd81f153aedb5f38411a96b`, TB48
  `34409262512 / 102659650326`;
- accepted M4 predecessor remains selector365, LF SHA-256
  `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- selector409 remains final-M3 audit evidence only;
- M4 semantics are `Architecture_M4_DEFN_Frozen_Definitions.md` as amended by `M4-CP1-CB1-REV`;
- CB1 made no product/test/build/selector semantic mutation and produced no package;
- stable accounting remains **47 / 14 / 33**, debt **5**, packages **113**.

## 3. Surgical owner set

CB2 may change only the smallest set needed to add the standalone known-feasible A3 product, solver, structural
validator, focused tests, selector and build registration. Expected semantic owners are:

- `include/directional/authority/AuthorityIds.h` only for new strong A3 IDs that cannot live cleanly in the product
  header;
- one new public `GlobalConformityPlan` header/value surface under `include/directional/geometry/`;
- new implementation files under `src/geometry/` for the product, exact binary64 primitive, solver and independently
  reviewable validator;
- `CMakeLists.txt` for new library sources;
- one focused CP1 test source under `tests/` and the minimum `cmake/DirectionalTests.cmake` registration needed to
  compile it in an approved packaged target;
- one append-only `Architecture_M4_CP1_Required_Green_Selector_<N>.txt`, created only after exact test names are final;
- Code + Build report plus frozen `M4-CP1-TB1` plan after compile success;
- temporary workflow caller/markers required by ChatGPT Web orchestration, retired before closeout.

Do **not** refactor unrelated exact arithmetic, existing M3 producers/tests, reusable workflows or historical selectors.
Match existing style and keep solver-only representation private.

CB2 must not change `SurfaceCellTracing.cpp` regional `gridU/gridV` selection or post-hoc hard-rail pairing,
`RemeshPipeline.cpp` production A4 consumption semantics, CP2 infeasibility/certificate production, CP-COND/CP-SCALE,
or M5/M6 relation/embedding behavior. If header integration appears to require a production cutover, stop and re-plan.

## 4. Required implementation

### CB2.1 — semantic IDs and exact value surface

Implement/reuse:

- `ConformitySpanId` bound 1:1 to canonical full A2b `NetworkArcId` semantics;
- `ConformityBoundaryIncidenceId` preserving region-boundary occurrence multiplicity;
- `ConformityBreakpointId {ConformitySpanId, EInt exactOrdinal}` — never `SemanticId<size_t>`;
- exact positive schedule counts as `EInt`;
- compact breakpoint lookup/generation using `{span, ordinal}` and the frozen exact support-piece formula.

A large count must be representable and digestible without constructing `x_s+1` IDs. Any machine-size conversion is
allowed only after an explicit later consumer fit check and cannot influence A3 semantics.

### CB2.2 — backend-independent binary64 exactification and full-span binding

Implement the frozen bit decomposition for finite binary64 coordinates/targets. Do not call `ENumber(double,tol)` or
rely on backend-specific floating conversion for semantic values. Signed zero canonicalizes to exact zero; target metric
entries must be finite and strictly positive.

Build exactly one span per full A2b boundary arc and retain its ordered exact A2a/A2a' support-piece path. Preserve every
boundary occurrence, including same-region two-end and repeated occurrences. Reject malformed, disconnected or
non-canonically degenerate paths using the frozen typed error vocabulary. Do not split one span into per-source-simplex
schedule variables.

### CB2.3 — exact L1 normalization and finite capacity proof values

For canonical semantic incidence matrix `A`, preferred exact counts `d`, row count `V` and span count `E`, compute with
arbitrary precision:

- `D = sum d_s`;
- `H = E * 2^V`;
- `U = 2D + E*H`.

These are proof/capacity values, never iteration ranges. Construct deviation variables

`x_s = d_s + p_s - n_s`

with exact demand `b=-A d`, capacities `p_s <= U-d_s` and `n_s <= d_s-1`, original/reversed bi-directed incidence
respectively. Zero-capacity deviation edges may be omitted. An aggregated zero semantic column bypasses the solver and
returns its unique objective minimum `x_s=d_s`.

Keep code comments adjacent to the bound derivation and cite the review's extreme-ray/minor/Hadamard proof. Tests must
include a small exhaustive check that the finite cap preserves the optimum on several graph shapes; production code may
not enumerate to the cap.

### CB2.4 — exact lexicographic implementation encoding

Keep semantic objective

`J=(C,x_1,...,x_E)`, `C=sum |x-d|`.

For canonical span order compute exact

- `Q=U+1`;
- `L=Q^E`;
- `q_i=Q^(E-i)`;
- `cost(p_i)=L+q_i`;
- `cost(n_i)=L-q_i`.

Use repeated exact multiplication/exponentiation by squaring or an `O(E)` descending-power construction; no loop may
iterate `L`, `Q`, `U` or any count value times. The product must publish/recompute semantic `J`, not the scalar encoding.
The independent validator recomputes the bound/radix identities separately from candidate values.

No heuristic weight, floating cost, finite machine scalar, or arbitrary big-M is permitted.

### CB2.5 — arbitrary-capacity Integral Bi-MCF solver

Implement one deterministic private solver corresponding to Gabow 1983's minimum-cost biflow problem with arbitrary
integral capacities. Required graph semantics:

- arbitrary exact integer node demands;
- head/tail incidence at either end;
- parallel edges and same-node `+/-2` loops;
- finite exact lower/upper capacities after normalization;
- exact integer costs and exact reduced-cost/comparison decisions;
- deterministic canonical tie behavior supplied by CB2.4, not container traversal order.

For one-ended outer edges, apply the standard deterministic dummy-node reduction from Heistermann/Warnett/Bommes
§3.2.1. Add one solver-only dummy node, second `+1` incidence for every outer edge, required parity demand `0|1`, and a
zero-cost tail-tail self-loop capped by the review's conservative `(2E+1) * U` bound. The dummy representation never enters
semantic digests or A3 IDs.

Do not call generic ILP/IQP/branch-and-bound. Do not use libSatsuma's `int`/`double` implementation as semantic
backend. Reusing a small graph-container utility is acceptable only if it does not own numeric semantics or solver
choice.

If the implementation cannot be traced to the selected arbitrary-capacity min-cost biflow algorithm, stop rather than
substituting a different method.

### CB2.6 — WorkLedger

Publish deterministic evidence, not an invented universal countdown:

- semantic `V,E`, solver `V',E'`;
- algorithm tag `Gabow1983ArbitraryCapacityMinCostBiflow`;
- theorem class `O(E'^2 log V' log Cmax)`;
- `H/U/Cmax` bit widths, target/capacity/cost bit widths and maximum observed exact-integer width;
- capacity-scaling/algorithm-phase counts and augment/blossom or equivalent primitive counters exposed by the actual
  implementation;
- peak residual/solver edge count;
- retry/reset count, fixed at zero.

Every implementation loop still needs a local finite bound from graph/container cardinality or encoded bit width. A
violated implementation bound is `WorkBoundExceeded`; do not retry with another solver, truncate, or approximate.
No solver loop or graph expansion may be linear in the numeric capacity/count magnitude.

### CB2.7 — immutable feasible `GlobalConformityPlan`

Publish one standalone immutable product for known-feasible constructed components containing only semantic authority:

- exact source/network/cut-graph/A2b/target bindings;
- canonical spans and ordered support pieces;
- boundary incidences with region/family/sign/orientation and preserved multiplicity;
- one positive exact count per full span;
- compact breakpoint generator contract;
- semantic objective `J` and WorkLedger evidence needed by CP1;
- deterministic semantic digest over compact authority only.

Do not publish the solver dummy node, deviation edges, mixed-radix scalar cost, container ordinals or residual graph as
semantic identity. CP1 does not publish final `GlobalConformityCertificate` or `ConformityInfeasibleSubset`.

### CB2.8 — independent structural validator

Keep validator code separately reviewable from producer private helpers. It may share public value types and primitive
exact arithmetic only. It independently reconstructs/checks:

- all source/network/cut-graph/topology/target bindings and binary64 exactification;
- one full span per A2b boundary arc and support-piece continuity/order;
- incidence multiplicity/family/sign/orientation including same-region ends;
- exact positive counts and compact breakpoint arithmetic, including reverse ordinal `j -> x_s-j`;
- every balance and explicit even boundary parity;
- exact `R_s`, `d_s`, `C(x)` and semantic lex-vector serialization;
- `D/H/U/Q/L/q_i`, transformed capacity/cost identities and WorkLedger dimension/bit-width claims;
- semantic digest.

It must reject tampered schedule/objective/bound/encoding/WorkLedger fields. It does **not** implement a second generic
production optimizer in CP1; CP2 owns scalable optimality-certificate verification.

### CB2.9 — focused compiled test authority

Author deterministic CP1 gating identities covering at least:

1. one full span crossing multiple exact support pieces still owns one positive count;
2. reverse incidences consume the same compact breakpoint IDs under exact ordinal reversal;
3. same-region/two-end and repeated-boundary occurrences preserve multiplicity;
4. every count is positive and region/family unsigned boundary multiplicity is explicitly even;
5. very large exact count/ordinal/bound/radix values remain compact and never narrow to `size_t`;
6. binary64 normal/subnormal/signed-zero exactification and typed non-finite/non-positive target rejection;
7. L1 deviation transformation and `p/n` non-overlap equivalence on small exact cases;
8. the `H/U` cap proof is exercised on tiny exhaustive signed-incidence graphs, including `+/-2` loops, parallel and
   zero columns, without any production range scan;
9. symmetric/equal-primary-cost schedules choose the semantic lexicographic winner and exact mixed-radix encoding agrees;
10. an outer-edge case normalizes through the dummy node and returns the same semantic solution/digest;
11. path reversal plus source/container/region permutation preserves semantic schedule/digest;
12. missing/duplicate incidence, support discontinuity/order, count/balance/parity/binding, objective, bound/radix and
    WorkLedger tamper are rejected independently;
13. production solver result equals a **separate tiny exact optimum oracle** on multiple known-feasible graph classes.

The tiny oracle may exhaustively enumerate only under a hard compile-time fixture cap such as `E<=6`, `x_s<=8`; it
must live in test code, must not share producer solver helpers, and must fail if asked to exceed that bound. Do not author
a production exact-torus A3 identity yet; CP3 owns production reachability/cutover.

### CB2.10 — append-only first M4 selector

After all new exact test names are final:

- create one new selector whose first 365 LF rows are byte-for-byte selector365;
- append only new CP1 gating identities;
- record total count, full LF SHA-256 and proof that the first 365 rows hash to the accepted predecessor;
- do not copy final-M3 audit-only rows 366–409 unless a later review independently selects one as M4 work.

CB2 compiles this selector's owner targets but executes no identity.

## 5. Compile/build contract

All compile activity uses `.github/workflows/agent-compile-reusable.yml`; do not run local builds. Mandatory
`.agents/Directional/GMP_COMPILE_POLICY.md` applies unchanged. The authoritative compile must:

- configure `DIRECTIONAL_ENABLE_GMP=ON`;
- prove both `gmpxx` and `gmp` on authoritative generated link commands;
- compile/link the new product/solver/validator and every target owning appended CP1 selector identities;
- preserve the durable reusable ccache namespace/schema without caller-defined epochs/keys;
- package a clean source snapshot, self-verifying manifest, compile logs and `exactArithmeticBackend=GMP`;
- report `runtimeExecution=false`.

No generated Directional binary may run: no GoogleTest filter/discovery, `ctest`, benchmark, CLI, help/list/version or
custom input. Compile failure may be corrected only within the declared owner set and only when it does not reveal a new
algorithm/definition contradiction.

## 6. Required source audit before freezing package authority

Before declaring CB2 complete, statically verify:

- no generic ILP/Gurobi/branch-and-bound path is reachable from the CP1 solver;
- no `double` or machine-integer conversion participates in balance, capacity, cost, objective, tie-break or ordinal
  decisions;
- no loop/allocation is bounded by numeric `x`, `d`, `U`, `H`, `Q` or `L` rather than graph size/bit width;
- solver-only dummy/deviation/radix representation is absent from semantic IDs/digest;
- validator shares no producer semantic derivation or solver helper;
- CP2 certificate/infeasibility and CP3 A4 cutover are absent;
- selector365 bytes are unchanged and exact prefix proof is recorded.

Any failure blocks packaging/advancement until corrected or reviewed.

## 7. Falsifiable Code + Build prediction

If CB2 follows this plan, exactly one new A3 known-feasible schedule authority family plus its focused compiled test
surface appears; all approved targets compile/link with GMP/GMPXX; the first M4 selector is append-only from 365;
existing M3 semantic files/selectors remain unchanged; no Directional runtime occurs; and package evidence reports
`runtimeExecution=false`.

The algorithm-specific prediction is independently falsifiable from source: the final count vector must be obtained
through exact finite-capacity Integral Bi-MCF using the reviewed L1 transformation and exact mixed-radix tie encoding,
with no magnitude-linear search or heuristic fallback.

## 8. Stop conditions

Stop before semantic substitution and return to independent review if any of these occurs:

- Gabow's selected arbitrary-capacity min-cost biflow algorithm cannot represent the exact normalized demand/loop/
  parallel-edge instance without changing semantics;
- a concrete counterexample invalidates the `H/U` optimum cap or mixed-radix lexicographic proof;
- exact arithmetic requires a machine-width narrowing for a semantic decision;
- the only practical implementation path requires generic ILP/branch-and-bound, numeric-range expansion or floating
  reduced costs;
- CP1 cannot be implemented without pulling CP2 certificate/infeasibility or CP3 production-cutover semantics forward.

Do not weaken a test or redefine a witness to bypass a stop.

## 9. Success criteria and exact successor

CB2 is complete only when the static source audit is clean, the mandatory GMP/GMPXX compile/package is green, exact
source/run/job/artifact identities and digests are recorded, and `runtimeExecution=false` is proved.

Then freeze **`M4-CP1-TB1`**, artifact-only Test + Benchmark, against that exact immutable package. TB1 executes the
full CP1 selector one identity per fresh process and re-proves the accepted 365 prefix. No runtime belongs to CB2.
