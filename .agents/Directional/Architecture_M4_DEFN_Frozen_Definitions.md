# M4-DEFN Frozen Definitions — Global Conformity

**Status:** FROZEN / M4 BASELINE A3 SEMANTICS AMENDED BY `M4-CP3-DEFN-R1` / EXACT NEXT = `M4-CP3-CB2` / RUNTIME-FREE
**Date:** 2026-09-09; solver amendment 2026-09-10; production-baseline incidence amendment 2026-09-11
**Definition authority:** §§1-16 retain the historical M4-DEFN/M4-DEFN-R1 framed schedule contract and evidence lineage. **§17 is the current production-baseline authority** and supersedes conflicting family/sign, balance, infeasibility, solver, checkpoint-exit, and successor clauses for production A3. Historical CP1/CP2 evidence is not rewritten.

This document freezes the M4 contract. It does not implement it and creates no runtime evidence.

## 1. Entering authority and M3 reconciliation

M4 enters from the accepted M3 boundary, not from the final audit selector:

- reviewed semantic package: package113, semantic source `6dae3f6959551f6dcdd81f153aedb5f38411a96b`;
- final M3 audit runtime: `34409262512 / 102659650326`, selector409, **405 PASS / 4 RED / 0 SKIP**;
- accepted required-green predecessor: selector **365**, LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- carried final-audit REDs: `[368,369,374,398]`, each under its pre-existing separate owner;
- ownership: **300 established / 0 unavailable / 0 conflicting**;
- stable regression accounting: **47 events / 14 categories / 33 recurrences**;
- produced-witness debt: **5** total, of which three `G4-B002` contracts are M4-owned and two `G4-B003` contracts are M5-owned;
- accepted package count: **113**.

Selector409 remains a retained audit surface. It is not the prefix from which M4 selectors may be constructed.

### 1.1 Correction to the independent TB48 review amendment

The appended §12.2 of `Architecture_M3_CP4c3_TB48_Independent_Review_Record.md` says
`M3-CP4c-0-TB-R9` was never executed and tries to derive CP4c-0 closure from later cumulative inclusion. That historical
premise is false.

Primary and retained evidence agree that **TB-R9 did execute and directly closed CP4c-0**:

- workflow run `33079817998`, named `M3 CP4c0 TB-R9 Whole-Gate Reproof`, completed successfully;
- workload job `98543736213`;
- source `7bbc0480d9ab5954329b940992ef41a9223102ed`;
- selector346 SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- result artifact `9649625534`, SHA-256 `6cd4e3c21dc46fd7e0d6df2209ee5a382531d768f50ae52d190302e05bec02af`;
- log artifact `9649626115`, SHA-256 `3ba381cd12ec1188bd9ae36020d35bdaa458271ea2c7b1163aac31a9a474d7f9`;
- **346/346 PASS**, including Q8 criteria **1, 4 and 5**, with immutable pre/postflight green and no timeout,
  exception or orchestration failure.

`CHANGELOG.md`, `Regression_Root_Cause_Tracker.md` and `M3_CP4c_Consolidated_Record.md` all retain the same direct gate
result. Later 353/355/365 prefix inclusion is consistent corroboration, but it is **not** the closure basis and no
conditional M3 re-opening check remains for M4. M3 stays CLOSED / ACCEPTED.

This correction is definition-time historical reconciliation only. It changes no runtime result, stable regression
count, selector, package, product semantics or M3 acceptance state.

## 2. One M4 checkpoint chain

The two previously overlapping roadmap decompositions are frozen into this single **development/acceptance order**:

1. **`M4-CP1` — Global schedule authority.** Introduce the immutable `GlobalConformityPlan`, canonical conformity
   spans/incidences, one shared subdivision count per span, exact breakpoint identity, deterministic minimum-deviation
   schedule, and an independent validator for feasible plans. One A3 writer only.
2. **`M4-CP2` — Certification and typed infeasibility.** Add complete positivity/optimality certificates and
   subset-scoped infeasibility certificates/outcomes. Mathematical infeasibility is data, not a run-wide producer
   error and not permission for local repair.
3. **`M4-CP3` — Producer cutover.** Regional producers consume the verified schedule and lose authority to choose,
   insert, remove, quantize, re-pair or reorder shared breakpoints. Remove the post-hoc hard-rail-pairing authority;
   recover `G4-B002` on the produced exact torus.
4. **`M4-CP-COND` — Input conditioning coverage.** Implement Amendment 20's conditioning stage **architecturally
   before A0**, with raw-to-conditioned correspondence and typed inadmissibility. Development occurs after the A3
   semantic core so conditioning cannot become an unstated prerequisite for defining the schedule. It may change the
   A0 input product, but it may not redefine A3 schedule semantics.
5. **`M4-CP-SCALE` — Scale and boundedness.** Establish S1 expression-swell evidence, S2 certified-filter
   equivalence, S3 exact limit-cycle termination reporting, S4 incremental-Betti early rejection and S5 genus>=2
   coverage. Scale mechanisms may accelerate exact decisions but may not become alternate semantic authorities.
6. **`M4-CP4` — Cumulative M4 exit.** Re-prove the full accepted predecessor plus every M4 required identity,
   discharge all three M4-owned `G4-B002` produced-witness debts, retain work/bit-width evidence, and prove no
   post-hoc local pairing authority remains.

`M4-CP4` is an exit/cumulative-proof checkpoint, not a second schedule writer.

### 2.1 Architectural order versus development order

`M4-CP-COND` is developed fourth but its final product is inserted before A0. This is deliberate. CP1–CP3 are defined
and proved on already-admissible accepted M3 inputs; CP-COND later supplies the conditioned immutable source that A0
consumes. The A3 contract below binds only to A0/A2b/metric authority and therefore does not depend on the particular
conditioning algorithm. Before M4 exits, the production stage order is:

`Conditioning -> A0 -> A1 -> A2a -> A2a' -> A2b -> A3 GlobalConformityPlan -> A4 regional construction`.

## 3. A3 product and single-writer boundary

### 3.1 Product family

M4 freezes these semantic roles; exact C++ spellings may follow repository style but may not change their meaning:

- `GlobalConformityPlan` — immutable A3 scheduled-product authority and **only** shared-breakpoint/subdivision writer;
- `ConformitySpanId` — semantic identity for one canonical A2b boundary arc between topology nodes; it is one
  scheduling variable even when its exact source path crosses several source simplices;
- `ConformitySupportPiece` — one ordered exact source-attached linear piece of a span's bound A2a/A2a' path; support
  pieces locate breakpoints but do **not** own independent subdivision counts;
- `ConformityBoundaryIncidenceId` — semantic identity for one occurrence of a span in one canonical region boundary
  walk, preserving multiplicity even when both incidences belong to the same `NetworkRegionId`;
- `ConformityBreakpointId` — strong pair-valued identity `{ConformitySpanId, exactOrdinal}` where `exactOrdinal` uses
  the semantic arbitrary-precision integer type; it is **not** a `SemanticId<size_t>` alias;
- `ConformitySourcePoint` — exact source point (`SourceVertexId`, edge + exact unit parameter, or source face + exact
  barycentric triple) used for path-piece endpoints;
- `ConformityIncidence` — one boundary occurrence with region/family/sign/orientation authority;
- `ConformityScheduleEntry` — one exact positive subdivision count plus a compact deterministic breakpoint-generator
  rule; A3 never stores an O(`x_s`) breakpoint vector;
- `GlobalConformityCertificate` — CP2-carried binding, primal-feasibility, positivity/parity and optimality evidence for
  scheduled components;
- `ConformityInfeasibleSubset` — CP2-carried canonical subset-scoped infeasibility fact plus independently checkable
  witness;
- `GlobalConformityPlanError` — malformed/binding/contract failure only, never ordinary mathematical infeasibility.

The **final CP2+ A3 outcome** partitions the normalized incidence graph into connected constraint components. Every
region/family boundary incidence is covered exactly once by a scheduled component or an infeasible-subset fact; one
region may participate in more than one component. No input region or boundary incidence disappears. A3 does not assign
D0-D4 disposition; later disposition authority consumes these facts.

**CP1 staging is intentionally narrower:** CP1 implements and validates only constructed inputs whose normalized
constraint components are known to be feasible. It does not expose a production A3 entry point that maps ordinary
infeasibility to `GlobalConformityPlanError`, and it does not carry a provisional CP2 certificate. CP2 adds the
certificate and infeasible alternative **without changing CP1 schedule semantics**.

### 3.2 Exact bindings

Every plan publishes and the independent oracle re-derives:

- `sourceDigest == GlobalTopologyPlan::source_digest()`;
- `networkDigest` bound to the accepted `FieldAlignedCurveNetwork`;
- `cutGraphDigest == GlobalTopologyPlan::cut_graph_digest()`;
- `topologyPlanDigest == GlobalTopologyPlan::semantic_digest()`;
- a deterministic `targetMetricDigest` over the exact dyadic interpretation of the source-vertex target-size field;
- a semantic plan digest over canonical bindings, full spans/support paths, boundary incidences, exact counts, compact
  breakpoint-generator contracts, certificates and infeasible-subset facts.

A zero/mismatched digest is a typed binding error. Diagnostics, vector row numbers, hash-container order, thread order,
floating positions and output emission order are never identity.

### 3.3 Stage ownership

Only A3 may construct schedule entries. A4 receives a `const GlobalConformityPlan&` (or an immutable product handle)
and may only resolve IDs and validate bindings. It may not:

- derive another count from `targetSize`;
- insert a shared breakpoint because a local chart wants one;
- delete/coalesce/reorder a planned shared breakpoint;
- group chart edges by floating support or tolerance;
- run the existing `support_key(...1e-9/1e12...)` post-hoc hard-rail pairing as semantic authority;
- rewrite a plan after one region has already committed output.

The current `SurfaceCellTracing.cpp` local `targetSize.mean() -> gridU/gridV` selection and post-production
`HardRailPairKey` grouping are the migration targets. They are retained until the owning cutover checkpoint, then lose
semantic authority rather than being made a fallback.

## 4. Canonical conformity spans and breakpoint identity

### 4.1 Span construction

A2b `GlobalTopologyPlan` is the source of boundary topology, while its bound A2a `FieldAlignedCurveNetwork` and A2a'
`SurfaceCutGraph` provide exact path detail for trace/contact/cut segments. A3 consumes the bound A0-A2b products; it
does not infer exact points from `GlobalTopologyArc::sourceFaces` alone.

One **canonical conformity span is one canonical A2b boundary arc between topology nodes**. `ConformitySpanId` is
therefore semantically equivalent to the bound `NetworkArcId` (a distinct strong namespace is permitted for type
safety), not to a source-face/source-segment ordinal. An A2b arc that crosses ten source triangles still owns exactly
one schedule variable and may receive `x_s = 1`; input-triangle count is never a lower bound on output subdivision.

Each span publishes a canonical ordered `ConformitySupportPiece` path reconstructed from the bound exact A2a/A2a'
authority. Each nondegenerate piece publishes exact source-point endpoints and carrier provenance. Pieces are ordered by
the arc's semantic trace/cut order, never source-face row or container order. Empty paths, disconnected piece chains,
nonmatching consecutive endpoints, or zero-length pieces that cannot be canonically removed without changing a fixed
feature/node locus are malformed `DegenerateConformityPath` input.

Every occurrence of a span in a region's canonical oriented boundary walk becomes a
`ConformityBoundaryIncidenceId = (NetworkRegionId, canonicalBoundaryOccurrenceOrdinal)`. The occurrence carries family
`U|V`, sign `+|-`, and forward/reverse orientation derived from field/topology authority. Multiplicity is preserved:
two incidences of one shared span need not name distinct regions, and repeated occurrences are never collapsed merely
because their `NetworkRegionId` matches. A non-boundary/shared span has two incidence **ends**; a source-boundary
terminal has one. More than two ends or contradictory bound owners is malformed input. In the induced bi-directed
network, a self-incidence is a loop with two signed ends; after row aggregation it may contribute `0` or `+-2`, so the
implementation must not discard incidence-level multiplicity to force a simple matrix shape.

### 4.2 Compact path parameter and breakpoint definition

Let a span `s` have `m_s >= 1` ordered support pieces. The canonical exact path coordinate assigns piece `q` the equal
interval `[q/m_s, (q+1)/m_s]`. This coordinate is **source-authoritative but not physical arclength**; its purpose is to
map one global schedule to exact points on the already-bound A2 path without an algebraic-length/tolerance dependency.
The path segmentation is part of the bound A2 semantic input. Reversal maps `t -> 1-t`.

For every span `s`, A3 owns one exact positive integer subdivision count

`x_s in Z, x_s >= 1`.

The semantic count type must not truncate at machine-word range. Authoritative builds use the repository exact-integer
surface backed by GMP/GMPXX. `std::size_t` or another machine type is permitted only after an independently verified
fit/output-budget check in the later consumer and never becomes semantic source.

The breakpoint sequence is **implicit**:

`B_s = { (s,j) | j in Z, 0 <= j <= x_s }`.

`ConformityBreakpointId(s,j)` stores the exact ordinal `j`; `ConformityScheduleEntry` stores `x_s` and the generator
contract, not `x_s+1` IDs. For `0 < j < x_s`, map `t=j/x_s` to support piece
`q=floor(m_s*j/x_s)` and local exact parameter `u=(m_s*j-q*x_s)/x_s`; the two endpoints map directly to the first/last
path endpoints. The opposite incidence consumes exact ordinal `x_s-j`. Thus both sides reference the same semantic
breakpoints without geometric matching.

A3 semantic digest hashes the span/path authority, exact count and generator rule, never an enumerated O(`x_s`) list.
CP1/CP2 validation may enumerate **small test counts only** as a test convenience. Production enumeration is A4
output-sensitive work after an explicit fit/budget check; inability to materialize a huge exact count does not permit
A4 to rewrite the A3 schedule.

## 5. Exact target objective

Target size chooses among globally feasible plans; it never grants a regional producer independent breakpoint
authority. The authoritative target metric remains the source-vertex
`AdaptiveTargetSizeResult::targetSize` vector, bound to the A0 vertex count.

### 5.1 Backend-independent binary64 ingress

Every finite source coordinate and target-size `double` is converted to an exact dyadic by **bit decomposition**, not
by the tolerance-based `ENumber(double,tol)` constructor and not by backend-dependent implicit conversion. For binary64
sign `s`, biased exponent `e`, and 52-bit fraction `F`:

- `e == 0`: exact value is `(-1)^s * F * 2^-1074`;
- `0 < e < 2047`: exact value is `(-1)^s * (2^52 + F) * 2^(e-1075)`;
- `e == 2047`: reject as non-finite.

Canonicalize the resulting exact numerator/power-of-two denominator. Source-coordinate signed zero normalizes to exact
zero. Target metric entries must additionally be strictly positive. This conversion is shared only as a primitive;
producer and independent validator each derive semantic target data from the exact bits.

### 5.2 Exact full-span preference proxy

M4 deliberately avoids both per-source-simplex positivity and an unbounded exact sum-of-square-roots arclength
decision. For span `s` with `m_s` support pieces, piece displacement `Delta_q`, and exact positive target value `h_q`
interpolated at that piece's exact midpoint, define the exact rational target-normalized path energy

`R_s = m_s * sum_q ( ||Delta_q||^2 / h_q^2 )`.

`R_s` is the squared RMS target-normalized speed of the canonical equal-piece path parameter. It is exact because
source coordinates, source-point barycentrics and target values are exact rationals; it is invariant under path
reversal and semantic row/container permutation. It is **not claimed to be physical arclength** and may change if the
bound A2 path segmentation/re-triangulation itself changes. Such a change is a new bound semantic input; it still can
never produce different schedules on the two sides of one span. A span with zero exact path energy is
`DegenerateConformityPath`, not a zero-count schedule.

A3 derives preferred `d_s >= 1` as the nearest integer to `sqrt(R_s)` without an inexact square root: compare the exact
rational `R_s` with half-integer squared thresholds `(k+1/2)^2`. Exact half-way ties choose the smaller integer.

Let spans be in canonical order `s_1..s_E`. The semantic objective is the lexicographic integer vector

`J(x) = ( C(x), x_(s_1), x_(s_2), ..., x_(s_E) )`, where `C(x)=sum_s |x_s-d_s|`.

Thus primary minimum deviation is authoritative and the unique tie result is the lexicographically least count vector.
All spans have unit primary weight in M4. Later quality work may replace this proxy only through a new definition/review;
A4 cannot smuggle geometric weights or local target decisions into validity.

**Target-size invariance means:** once a `GlobalConformityPlan` is fixed, changing any A4-local target-size input cannot
change the breakpoint sequence it consumes. Changing the bound A3 target metric is a new input and may legitimately
produce a different globally consistent plan/digest.

## 6. Constraint and parity system

Constraints are formed over **boundary incidences**, not deduplicated region IDs. For each
`(NetworkRegionId r, family f in {U,V})`, a feasible schedule satisfies

`sum_{i in boundaryIncidences(r,f)} sigma_i * x_span(i) = 0`, with `sigma_i in {-1,+1}`.

A shared span has two signed incidence ends in the bi-directed network even when both ends attach to the same row/region.
A source-boundary terminal has one end. The implementation keeps that incidence graph as authority; matrix aggregation
may yield loop coefficients outside `{-1,0,+1}` and is only a derived representation.

**Parity is mandatory from CP1 onward, not an optional later constraint.** For each region/family define the unsigned
boundary multiplicity

`B_(r,f) = sum_{i in boundaryIncidences(r,f)} x_span(i)`.

The signed balance equation partitions those incidences into equal positive/negative sums, therefore
`B_(r,f) = 2 * sum_{sigma_i=+1} x_span(i)` and is even. Consequently each region's total scheduled boundary edge count
is even, the required all-quad disc parity condition. The solver enforces parity structurally by satisfying the exact
balance system; the independent validator must **also check the evenness explicitly** so a broken family/sign
derivation cannot hide behind producer/oracle agreement. A CP2 infeasibility witness may label an obstruction
`ParityCut` when its modulo-two projection is the shortest independent explanation, but parity is not a separate
heuristic repair variable.

The lower bound is eliminated by `y_s=x_s-1 >= 0`; the induced exact imbalance is part of the normalized problem.
**No active 2:1 adaptivity constraint is frozen for baseline M4** because the current bound A0-A2b/target input has no
separate authoritative enable/constraint product. A future active 2:1 contract requires a definition/review and cannot
appear because a local mesher prefers it.

Malformed side decomposition, contradictory incidence, unbound arc, degenerate path or invalid metric fails before the
solver. Ordinary exact infeasibility does not become a fatal construction error.

## 7. Exact finite-convergence solver contract — amended by `M4-DEFN-R1`

The semantic scheduling problem and objective are unchanged, but the production solver assurance is amended. M4 still
forbids generic ILP/branch-and-bound, inexact optimization, machine-width semantic narrowing, numeric-range enumeration,
and heuristic scalarization. It no longer claims a polynomial bound for the **outer exact optimizer**. The selected
implementation authority is the exact fixed-`M=2` Bi-MDF iterative-refinement algorithm disclosed by Heistermann,
Warnett and Bommes, *Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization*, ACM TOG 42(4), 2023,
DOI `10.1145/3592437`, §§3.6–3.9.

The previous Gabow 1983 primitive and `O(E'^2 log V' log Cmax)` WorkLedger theorem tag are **retired**. Independent
`M4-CP1-CB2-REV` established that the cited Gabow paper states the arbitrary-capacity minimum-cost biflow result while
deferring the construction, so that implementation identity could not be traced without invention or substitution.
`Architecture_M4_DEFN_R1_Definition_Record.md` records the route adjudication and assurance change.

### 7.1 Input-derived finite optimum cap — unchanged semantic proof

For a feasible CP1 component with `V` region/family rows and `E` span columns, every incidence column has at most two
ends and Euclidean norm at most `2`, including same-row `+/-2` loops. The rational cone `{x>=0 | A x=0}` has primitive
extreme-ray generators whose entries are signed minors of minimally dependent column sets. By Hadamard's inequality,
those minors have magnitude at most `2^V`. Because a strictly positive feasible vector is a nonnegative combination of
extreme rays, choosing one positive primitive ray per coordinate and summing them yields a positive integer circulation
with every coordinate at most

`H = E * 2^V`.

Let `D = sum_s d_s`. That feasible circulation has primary deviation at most `D + E*H`; hence every primary optimum
obeys

`1 <= x_s <= U`, where `U = 2D + E*H = 2D + E^2*2^V`.

`U` is a **proof/domain bound, never an iteration range**. Its encoded bit width is polynomial in input width. No graph
expansion, allocation, or loop may be linear in the numeric value of `H`, `U`, `D`, `d_s`, or an exact count.

### 7.2 Exact lexicographic objective encoding — semantic order unchanged

The semantic objective remains

`J(x) = (C(x), x_(s_1), ..., x_(s_E))`, `C(x)=sum|x_s-d_s|`,

for canonical span order `s_1..s_E`. Set `Q=U+1`, `L=Q^E`, and `q_i=Q^(E-i)`. Since every count is a base-`Q`
digit in `1..U`, `S(x)=sum_i q_i*x_i` orders count vectors exactly lexicographically and its entire variation is less
than `L`. Thus

`F(x)=L*C(x)+S(x)`

has exactly the same ordering as `J(x)`. For the production Bi-MDF representation, use the exact separable convex
integer edge cost

`c_i(x) = L*|x-d_i| + q_i*x`, for `1 <= x <= U`.

The previous `x=d+p-n` linearization remains a valid proof of the L1 deviation identity and finite-cap/radix
construction, but it is no longer the required production solver representation. `J` remains semantic authority;
`F` and `c_i` are private solver representations. Powers/weights are built with exact arithmetic without
numeric-range enumeration.

### 7.3 Selected exact algorithm — Heistermann/Warnett/Bommes fixed-`M=2` refinement

The production algorithm follows the disclosed 2023 construction:

1. obtain a feasible integer starting flow using the paper's double-cover/T-join approximation pipeline, adapted to
   exact M4 arithmetic and independently validate it before refinement;
2. around current feasible flow `f`, construct the zero-demand bounded Bi-MCF refinement problem of §3.7;
3. fix maximum node throughflow **`M=2`**;
4. reduce Bi-MCF to capacitated weighted perfect b-matching using the disclosed node-splitting construction;
5. reduce weighted perfect b-matching to weighted perfect matching using the disclosed construction;
6. solve the matching problem with exact arbitrary-precision weights/comparisons and translate the result back through
   every reduction;
7. commit only an exact strict objective improvement; terminate on exact non-improvement.

Corollary 3.7 proves finite convergence for fixed `M`; Theorem 3.8 proves that a non-improving iteration with `M>=2`
is globally optimal; Corollary 3.9 concludes that the refinement algorithm finds an optimum for any Bi-MDF problem.
These identities are the solver theorem authority. There is no floating epsilon terminal and no inherited Gabow bound.

The admissible M4 incidence class remains genuinely bidirected: same-row two-end spans may carry one `+2` or `-2`
coefficient and are not dropped. The ordinary-MCF route is therefore not frozen. A direct one-shot capacitated
b-matching route is also not frozen because the simple reduction disclosed in Heistermann et al. §3.7 is specialized to
the zero-demand refinement subproblem, while the previous one-shot `p/n` Bi-MCF carries nonzero demand `-A d`.

The standing user authorization permits adding a solver library for the weighted-perfect-matching primitive. Any such
primitive must preserve exact arbitrary-precision comparisons. Upstream `libSatsuma` is implementation/reference
material only: its `int` flow, `double` target/cost, `int64_t` matching weights and floating refinement terminal are not
M4 semantic authority and must not be inherited as-is.

### 7.4 WorkLedger and assurance class — amended

The outer optimization assurance class is now **exact finite convergence**, not polynomial runtime. `WorkLedger` records
at minimum:

- semantic `V,E`, algorithm identity `HeistermannWarnettBommes2023ExactBiMDFRefinementM2`, and theorem class
  `FiniteExactConvergence(Corollary3.7+Theorem3.8+Corollary3.9,M=2)`;
- exact `H/U/Q/L` bit widths, target/count/capacity/cost bit widths, and maximum observed exact-integer width;
- feasible-initialization graph dimensions and independent exact feasibility receipt;
- `refinementM=2`, exact `refinementCount`, and exact objective before/after every committed refinement;
- each refinement's Bi-MCF/WPbM/WPM graph dimensions, peak matching vertices/edges, and matching primitive identity;
- retry/reset count, fixed at zero.

Every implementation loop still has a finite bound derived from graph/container cardinality or encoded bit width. A
violated local bound is `WorkBoundExceeded`, never permission to truncate, approximate, retry, or switch solvers. No
solver work may depend linearly on exact numeric magnitude. CP-SCALE may report measured refinement/resource scaling
but must not relabel it polynomial.

## 8. Certificates and typed outcomes

### 8.1 Scheduled-component certificate — CP2 addition

CP1 has no carried final certificate; its separately implemented validator independently recomputes and checks feasible
plans and the fixed-small test oracle independently checks optimum/tie behavior. **Because `M4-DEFN-R1` withdraws the
outer polynomial-runtime claim, CP2's scalable independent optimality certificate is a mandatory semantic barrier
before CP3 cutover.**

For each scheduled component the CP2 certificate contains at minimum:

- binding/normalized-problem digest;
- exact compact `x_s`, preferred `d_s`, objective `J*` and mandatory region/family parity results;
- every region-family balance and positivity result;
- exact terminal `M=2` refinement-problem identity plus a producer-native WPM/refinement witness sufficient to
  reconstruct the zero-improvement claim;
- independently checkable mapping from that terminal matching/refinement witness back to the semantic Bi-MDF schedule;
- exact theorem-hypothesis evidence needed to apply Heistermann/Warnett/Bommes Theorem 3.8;
- WorkLedger bounds and observed maxima.

The independent CP2 verifier must recompute exact `J`, validate the terminal `M=2` refinement instance and verify that
no negative-cost admissible refinement exists. A solver-emitted `no improvement` flag alone is not a certificate. The
certificate proves semantic optimality; it does **not** claim a polynomial bound on outer refinement count. It hashes
compact schedule/generator data and never expands O(`x_s`) breakpoint vectors.

### 8.2 Subset-scoped infeasibility — CP2 addition

CP1 is exercised only on independently constructed feasible components and does not publish a temporary fatal
infeasibility outcome. CP2 adds the production alternative. Ordinary inability to satisfy the exact positive
balance/parity system is **not** `GlobalConformityPlanError`; CP2 publishes `ConformityInfeasibleSubset` with:

- canonical connected constraint-component ID;
- sorted affected `NetworkRegionId`s, boundary-incidence IDs and `ConformitySpanId`s;
- reason `BalanceCut | PositivityCut | ParityCut`;
- an algorithm-native residual/cut/deficit witness reconstructible exactly by the independent oracle;
- source/topology/metric/problem digests;
- no A4 replacement schedule.

The subset need not be cardinality-minimal; it must be a deterministic valid obstruction witness. `ParityCut` denotes an
independently checkable modulo-two projection of the same frozen balance system, not a new heuristic constraint. Future
M7 disposition may map this fact to D3. M4 itself does not.

### 8.3 Fatal construction errors

The fatal A3 error vocabulary is frozen to these semantic classes (exact enum names may follow repository style):

- `InvalidSourceBinding`;
- `InvalidTopologyPlanBinding`;
- `InvalidTargetMetricBinding`;
- `DuplicateConformitySpan`;
- `MissingSpanSourceSupport`;
- `DegenerateConformityPath`;
- `InvalidSharedSpanIncidence`;
- `InvalidRegionSideDecomposition`;
- `ConflictingRailOwner`;
- `CertificateConstructionMismatch`;
- `WorkBoundExceeded`.

There is no `UnsupportedEnabledAdaptivityConstraint` in baseline M4 because no active 2:1 enable contract exists. Every
error carries the earliest available semantic locus: span, boundary incidence, arc, rail, region, source edge/face or
metric entry. No fatal code means "solver found no feasible schedule"; that semantic alternative begins in CP2.

## 9. Independent oracle contract

`validate_global_conformity_plan(...)` (exact name may follow repository style) accepts only the bound A0/A2a/A2a'/A2b
products, source-vertex target field, and a read-only candidate view. It may not call the producer's canonicalization, solver, certificate-construction or
private cached schedule helpers.

It independently:

1. rebuilds full A2b conformity spans, ordered exact support pieces and boundary-occurrence multiplicity;
2. bit-decomposes source/target binary64 inputs and re-derives exact `R_s` and each `d_s`;
3. checks source/topology/metric/semantic bindings;
4. checks one compact exact count per span, `x_s>=1`, breakpoint-ID generator arithmetic and reverse-orientation
   agreement without materializing O(`x_s`) data;
5. checks every incidence-preserving region/family balance **and explicit even boundary parity**;
6. re-evaluates `C(x)`, semantic lex-vector serialization, the `D/H/U/Q/L/q_i` bound/radix identities, transformed
   capacity/cost consistency and WorkLedger dimension/bit-width claims;
7. in CP1, performs **no second generic production solve**; focused CP1 test authority compares the producer solver to
   an independently implemented fixed-small exact oracle. From CP2 onward, the production oracle verifies the carried
   algorithm-native optimality witness and lexicographic canonical-minimizer proof;
8. from CP2 onward, verifies every infeasible-subset obstruction from source-derived normalized constraints;
9. from CP2 onward, proves every normalized boundary incidence is covered exactly once by a scheduled component or
   infeasible subset and every input region/family is fully accounted for.

The oracle may share public value types and exact arithmetic primitives. It may not share semantic derivation helpers
whose defect would make producer and oracle agree for the same reason.

### 9.1 Required tamper matrix

The cumulative M4 gate must contain independently falsifying identities for at least:

- missing span;
- duplicate span;
- non-positive count and huge exact count whose ID/generator remains compact;
- altered count that breaks a region-family balance or explicit region parity;
- A4-side inserted/deleted/reordered shared breakpoint;
- reversed incidence without exact-ordinal `j -> x_s-j`;
- collapsed/duplicated boundary occurrence, including a same-region two-end case;
- wrong `HardRailId`, support-piece order or source support;
- wrong source/topology/target digest or backend-dependent/tolerance-based binary64 exactification;
- altered objective/dual potential/residual witness;
- duplicate or omitted region incidence;
- omitted infeasible subset member/cut witness;
- semantic equality under source row/container permutation where topology is unchanged;
- fixed-plan A4 target-size perturbation leaves consumed shared breakpoints unchanged;
- global A3 target-size change either changes the bound plan digest consistently or deterministically leaves it equal;
  no per-side divergence is permitted.

## 10. Witness and reachability matrix

No required-green identity is appended until its stated precondition is independently constructed/reachable.

| Witness/obligation | Current provenance/reachability | M4 checkpoint | Gate status rule |
|---|---|---|---|
| canonical shared full-span fixture | direct deterministic fixture can span multiple source pieces and may include same-region two-end incidence; no production claim | CP1 | gating once CB authors/compiles it and oracle derives incidence multiplicity independently |
| positive/parity/compact-breakpoint schedule + tamper matrix | same CP1 direct product fixture, including huge exact count without enumeration | CP1 | gating |
| exact-torus `G4-B002` | ~~already reaches regional phase-front aggregation and fails at the current post-hoc `InvalidHardRailPairing` seam~~ **CORRECTED 2026-09-12 — this claim cited no evidence and is contradicted by observation.** TB3 (run `34671972132`) observed `NotApplicable` with no hard-rail authority; TB5 (run `34680334158`), with the intended 18-edge authority proved at runtime, observed the curved bounded-disk producer return `NotApplicable` at its Euler applicability test (`chi_whole=0` vs required `1`) **before** any boundary phase is constructed — so the torus does not reach hard-rail pairing at all. The semantic obligation is unchanged: CP3 still owes a production torus witness that carries shared hard-rail authority and completes without `InvalidHardRailPairing`; it may not be reported as reproducing a historically observed failure. | CP3 | gating once A3 is production-wired; failure before A3 is evidence, not a weakened gate |
| A4-local target perturbation | direct scheduled fixture, later production torus | CP3 | gating |
| three `G4-B002` produced-witness re-proofs | debt named in M1 closure; require produced closed/periodic authority, not direct drafts | CP4 | gating; all three must pass before M4 closes |
| sliver/anisotropic raw input | coverage gap; raw input necessarily reaches the pre-A0 conditioner entry once CP-COND exists | CP-COND | gating after fixture/correspondence precondition is authored and independently verified |
| high-valence raw input | same | CP-COND | gating after precondition verification |
| negative-index singularity raw input | same | CP-COND | gating after field admissibility/inadmissibility expectation is derived, not hand asserted |
| boundary-truncated separatrix raw input | same | CP-COND | gating after precondition verification |
| deliberately inadmissible field | same | CP-COND | gating typed refusal/certificate; never “repair until accepted” |
| conditioning correspondence + idempotence + S6 perturbation | no current accepted production witness | CP-COND | gating after CB construction; perturbation metrics may be report-only until threshold frozen |
| S1 bit-width/expression swell | current meshes <=152 vertices/300 faces, so production envelope is uncalibrated | CP-SCALE | **non-gating measurement** first; a later review may freeze a numeric gate, never M4-DEFN guesswork |
| S2 certified-filter equivalence | exact fallback can provide oracle | CP-SCALE | gating: filtered and exact decisions must agree |
| S3 limit-cycle typed termination | prescribed-sphere history proves a real exact limit-cycle surface | CP-SCALE | gating typed outcome when the dedicated fixture reaches the detector |
| S4 incremental-Betti early rejection | construction owed | CP-SCALE | gating only after independently proved precondition/reachability |
| S5 genus>=2 | construction/reachability owed; genus1 torus is insufficient | CP-SCALE/CP4 | gating only after a genus>=2 fixture reaches A3; until then it is an explicit blocker, not guaranteed-red selector debt |

Representative Bunny/Vase quality/resource acceptance remains later milestone authority and is not silently pulled into
M4.

## 11. Debt and `G4-B004` adjudication

### 11.1 `G4-B002` — M4-owned, unchanged count three

M4-CP4 cannot close until all three inherited contracts are re-proven on pipeline-produced authority:

1. `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on a produced closed complex;
2. `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` through the torus pipeline;
3. `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority rather than `direct_periodic_owner_product()`.

The main exact-torus `InvalidHardRailPairing` product blocker must be removed by CP3 without post-hoc pairing. The three
debts are discharged only at the cumulative CP4 exit. Total produced-witness debt remains **5** until actual runtime
acceptance; M4-DEFN does not decrement it.

### 11.2 `G4-B004` — not M4 work

`G4-B004` is split explicitly and **adds no M4 gate identity/debt**:

- **M5 owns the focused positive multi-isolation quotient relation/certificate witness.** It must prove the relation
  producer emits positive multi-isolation authority with explicit owners/certificate, matching `REORIENTATION_PLAN.md`
  §9.
- **M6 owns representative occurrence/embedding/verifier consumption.** It must prove the M5-produced authority is
  materialized/consumed exactly once and independently verified on the representative product path.

This resolves the former “M5/M6” ambiguity without importing relation/embedding semantics into A3.

## 12. Selector and gate contract

M4 selector lineage is append-only from the exact 365-line accepted predecessor.

1. Every M4 selector begins with selector365 byte-for-byte/LF-hash preserved.
2. New identities are appended only after their test source is authored and compile evidence exists in the owning CB.
3. Direct deterministic CP1/CP2 contract/oracle/tamper identities with fully constructed preconditions are **gating**.
4. CP3 exact-torus and consumption invariance identities are **gating** once the pipeline reaches A3.
5. CP-COND semantic admissibility/correspondence identities are **gating** once their raw preconditions are independently
   verified.
6. CP-SCALE exact-decision/termination/early-rejection/genus identities are gating only when their preconditions are
   proved; uncalibrated S1 numeric measurements are explicitly **non-gating diagnostic** rows and contribute zero gate
   credit.
7. CP4 appends the three produced-witness debt identities as gating and re-runs the full cumulative accepted prefix.
8. The four M3 audit RED rows 368/369/374/398 are not copied into M4's accepted prefix merely because selector409
   exists; their independent owners remain visible in the tracker/audit record.

Every selector publication must record line count, LF SHA-256 and predecessor-prefix SHA. A prose obligation that has
no selector identity is not gate-enforced and must be labeled as such.

## 13. Checkpoint-specific exit conditions

- **CP1 closes** when one immutable feasible schedule has a single writer, each full A2b span uses one exact positive
  count and one compact exact-ordinal breakpoint generator, region/family balance plus explicit all-quad boundary parity
  are proved, multi-piece/same-region incidence authority is preserved, binary64 exactification is backend-independent,
  deterministic permutation/reversal invariance is proved, the amended exact fixed-`M=2` Bi-MDF refinement/cap/radix
  solver contract is compiled, the independent structural oracle rejects binding/feasibility/objective/encoding tamper,
  and fixed-small test oracles independently reproduce optimum/tie results on the frozen CP1 graph classes.
- **CP2 closes** when positivity and **scalable production optimality** are independently certified from carried
  algorithm-native evidence and a genuinely infeasible constructed component yields a verified subset-scoped fact
  without ad-hoc schedule substitution or run-wide A3 failure.
- **CP3 closes** when A4 consumes the plan, no local target/grid/post-hoc support-pairing path can change shared
  boundaries, the exact-torus `InvalidHardRailPairing` blocker is removed through A3 authority, and fixed-plan
  target-size perturbation cannot change consumed breakpoints.
- **CP-COND closes** when the pre-A0 conditioner produces immutable conditioned source + certified raw correspondence,
  typed inadmissibility and the named coverage witnesses, without changing A3 semantics.
- **CP-SCALE closes** when certified filters are semantically equivalent to exact fallback, limit-cycle/Betti outcomes
  are typed and bounded, S1 measurements are published, and a genus>=2 witness reaches the required stage or the
  checkpoint remains open with that precondition explicit.
- **CP4 closes M4** only on a cumulative green required selector, all three `G4-B002` debts runtime-reproved on produced
  authority, exact-torus production path green past the retired post-hoc pairing seam, and work/bit-width evidence
  satisfies the frozen bounds then in force.

## 14. Exact implementation seam frozen for the first CB

Current source at the latest amended head establishes a surgical seam:

- `src/pipeline/RemeshPipeline.cpp` constructs `GlobalTopologyPlan` and then calls `build_surface_cell_network(...)`;
- `src/geometry/SurfaceCellTracing.cpp` still chooses region `gridU/gridV` from local/mean target size and later groups
  hard-rail chart copies using tolerance/quantized floating `support_key` values before assigning `oppositeEdge`;
- `GlobalTopologyPlan` already publishes source/network/cut-graph/semantic digests and exact A2b arc/region identities;
- `authority::ExactUnitParameter` and `SourceSupport` already provide the exact support vocabulary needed by A3.

Therefore M4 does not require a new topology authority. CP1 introduces a new A3 product from existing accepted A2b
inputs. CP3, not CP1, removes the legacy consumer-side authority.

## 15. Definition falsifiers

Any later plan or implementation must stop/review if it would require one of these changes:

- making geometry/tolerance/quantized barycentrics semantic breakpoint identity;
- splitting one A2b boundary arc into independently positive per-source-simplex schedule variables;
- enumerating O(`x_s`) semantic breakpoint storage or narrowing exact ordinals to `size_t`;
- exactifying binary64 semantics through tolerance/backend-dependent double constructors;
- treating mandatory region parity as optional or a downstream A4 repair;
- letting two regional producers own separate counts for one shared span;
- using a generic ILP/branch-and-bound solver, inexact feasibility/reduced-cost comparison, or heuristic/unproved
  scalarization; the exact theorem-derived mixed-radix encoding of §7.2 is the sole permitted scalar solver encoding;
- restoring the retired Gabow solver identity/bound, inheriting upstream libSatsuma/Blossom-V machine-width scalar
  semantics, or terminating exact refinement through a floating tolerance;
- changing fixed refinement `M=2`, hiding a numeric-magnitude loop behind a solver adapter, or claiming the amended
  outer refinement process has a polynomial runtime bound without a new definition/review and source-backed theorem;
- activating an unfrozen 2:1 adaptivity constraint without a new authoritative input contract/review;
- repairing an infeasible component locally instead of publishing its typed obstruction;
- assigning D0–D4 inside A3;
- making CP-COND algorithm details a precondition for A3 semantics;
- moving uncalibrated S1 measurements into a hard numeric gate without review;
- importing `G4-B004` relation/embedding work into M4;
- using selector409 as the accepted M4 predecessor;
- re-opening M3 based on the refuted “TB-R9 never ran” premise.

## 16. Exact successor

**`M4-CP1-CB3` — canonical Code + Build / runtime-free.** Its frozen plan is
`Architecture_M4_CP1_CB3_Code_Build_Plan.md`, issued by `M4-DEFN-R1` after independently reviewed CB1/CB2
traceability stops. No M4 runtime or benchmark is authorized before that Code + Build turn produces a
GMP/GMPXX-linked immutable package and the next artifact-only Test + Benchmark plan.

## 17. `M4-CP3-DEFN-R1` amendment — baseline conformity is exact shared subdivision plus region parity

This amendment was forced by the `M4-CP3-CB1` pre-mutation derivation guard and an independent source re-derivation. It is normative for production A3. Earlier family/sign Bi-MDF material in §§3.1, 6-9, 13, 15 and 16 remains historical authority for the already accepted framed CP1/CP2 proof surface only where it does not conflict with this section.

### 17.1 Why the framed incidence contract cannot be the production baseline

A2b publishes three production arc kinds: `Mandatory`, `Trace`, and `Cut`. Exact source/support/topology identity exists for all three, but accepted upstream products do **not** publish a universal global coordinate-frame label for every arc:

- artificial `Cut` arcs are selected from `SurfaceCutGraph` source edges to cellularize the complement; the accepted cut product carries exact edge/support/topology authority but no `ConformityFamily U|V` or `ConformitySign +/-`;
- `FieldAlignedMandatoryEdge` and `SurfaceCellRail` likewise carry source/rail/topology provenance but no globally comparable family/sign authority for arbitrary hard-feature or source-boundary arcs;
- trace material may carry face-local branch information, but a raw `FieldBranch` integer is face-gauge-local and is not a globally comparable family identity across arbitrary region boundaries.

Therefore a production binder cannot derive `{family, sign}` for every A2b boundary occurrence without inventing a convention, comparing raw cross-face branch integers, or reintroducing geometric/tolerance matching. All three are prohibited. The accepted torus has 28 artificial cut edges, so the missing authority is production-reachable.

### 17.2 Adjudication of the CB1 alternatives

**Alternative A is selected and expanded:** baseline A3 uses family/sign-free boundary incidences. Artificial cuts and mandatory barriers are ordinary exact shared-boundary seams. A3 owns shared subdivision identity and the all-quad parity invariant; stronger local chart/field constructibility remains an A4 responsibility.

**Alternative B is rejected:** requiring every artificial cellularizing cut to be field-certified would reopen accepted A2a'/A2b semantics and contradict the accepted ability to cellularize with otherwise admissible source edges, including trace-crossed source edges. It would still not manufacture an upstream family/sign certificate for arbitrary mandatory source-boundary or hard-feature arcs.

**Alternative C is rejected:** a deterministic ordinal, raw branch number, or combinatorial labeling rule can create repeatable labels but cannot make them semantic coordinate families. No accepted source product or theorem makes such labels gauge/relabel invariant. Determinism is not authority.

### 17.3 Production A3 product and incidence authority

Production baseline roles are now:

- `ConformitySpanId`: one canonical full A2b arc, regardless of arc kind, with one global subdivision variable;
- exact ordered support pieces: unchanged and still the only source-location authority for breakpoints;
- `ConformityBoundaryIncidenceId`: one occurrence of a span in one region boundary walk, preserving multiplicity and incidence orientation;
- **baseline `ConformityIncidence`: region + span + orientation only. `ConformityFamily` and `ConformitySign` are not production-baseline semantic inputs.**

A valid manifold A2b binding gives every span one or two incidence ends. A same-region two-end span preserves both occurrences. A source-boundary terminal has one region incidence. Any other incidence multiplicity is a malformed binding error.

If the accepted framed CP1/CP2 implementation surface must remain temporarily to keep already accepted selector identities executable, it must be an explicitly separate legacy/framed API or test surface. It may not be selected by production, may not be implicitly activated by populated optional fields, and may not be converted into baseline A3 authority without a future definition that introduces a real upstream frame certificate.

### 17.4 Counts, breakpoints, and exact target preference are unchanged

For canonical spans `s_1..s_E`, production A3 still owns exactly one arbitrary-precision integer count

`x_s >= 1`

and compact breakpoint identities `{ConformitySpanId, exactOrdinal}`. The exact support-piece breakpoint generator, source/metric/topology digest bindings, binary64 exactification rule, and full-span preferred count `d_s >= 1` from §5 remain authoritative.

The semantic objective remains

`J(x) = ( sum_s |x_s-d_s|, x_(s_1), ..., x_(s_E) )`.

No A4-local target, grid, chart, tolerance, floating support key, or geometric nearest-arm rule may change `x_s` or the resulting shared breakpoint sequence.

### 17.5 Baseline feasibility constraint: region all-quad parity

For every A2b region `r`, using **boundary-incidence multiplicity**, production A3 requires

`sum_{i in boundaryIncidences(r)} x_span(i) ≡ 0 (mod 2)`.

There is no baseline `(region,family)` signed-balance row because family/sign are not universally source-derived. Same-region double incidences contribute twice and therefore cancel modulo two while remaining present in the semantic boundary walk.

This is the exact topological boundary-parity condition required by an all-quad disc complex. It is deliberately narrower than local rectangular/parametric constructibility. A4 must independently classify/construct the region under its field, feature, singularity and geometry obligations; it may return the existing typed nonconstructible/degraded outcome, but it may not repair or renegotiate A3 shared counts.

Baseline parity scheduling is **always mathematically feasible for a well-formed binding**: `x_s = 2` for every span is a positive witness. Consequently `ConformityInfeasibleSubset` and `BalanceCut | PositivityCut | ParityCut` are not production-baseline A3 outcomes. They remain historical framed-CP2 evidence only. Production baseline A3 has scheduled output or a malformed/binding/metric/work-bound construction error; a future stronger cross-span validity constraint requires a new definition before it can reintroduce mathematical infeasibility.

### 17.6 Exact minimum-deviation parity scheduler

Let `q_s = d_s mod 2`. Let `y_s = 1` when the selected parity of `x_s` differs from `q_s`, otherwise `0`. For fixed parity, the unique positive count minimizing `|x_s-d_s|` and then `x_s` is:

- `x_s = d_s` when `y_s = 0`;
- `x_s = d_s - 1` when `y_s = 1` and `d_s > 1`;
- `x_s = 2` when `y_s = 1` and `d_s = 1`.

Every flip therefore contributes exactly one unit to the primary objective. Region parity becomes a GF(2) incidence problem on a graph whose vertices are A2b regions:

- a two-region span is one graph edge;
- a same-region two-incidence span is a self-loop with zero parity effect;
- a one-ended source-boundary span connects its region to a **virtual exterior vertex local to that connected incidence component**.

Compute each region's residual parity under preferred parities `q_s`. On a closed component, residual-demand cardinality is even because every non-loop span contributes to two region rows. On a component with terminals, set the component-local exterior demand to the XOR of region residuals. Then a flip set is feasible exactly when it is a `T`-join for those demanded vertices.

The primary optimum is therefore a **minimum-cardinality T-join**. Production implementation must solve it exactly through an exact graph/matching formulation; no ILP/branch-and-bound, floating cost, tolerance, numeric-magnitude enumeration, or heuristic repair is permitted. Existing exact weighted-perfect-matching infrastructure may be reused only with integer graph-cardinality weights and exact comparisons.

After the minimum flip count `K*` is known, enforce the semantic lexicographic tie-break without huge invented scalar weights. Scan spans in canonical order. For span `s`, first try the parity choice that gives the smaller resulting `x_s` (`flip` when `d_s>1`, `no flip` when `d_s=1`), subject to all previously fixed choices, and recompute the exact minimum achievable T-join cardinality. Keep that choice iff the optimum remains `K*`; otherwise force the other choice. The invariant is that the fixed prefix always extends to at least one primary-optimal solution. This yields exactly the lexicographically least count vector under `J`.

Same-region self-loops never need to flip at primary optimum and therefore retain `x_s=d_s`.

### 17.7 Certificate, validator, and independent-oracle contract

The baseline plan/certificate carries enough exact information to verify, without trusting producer-normalized rows:

1. source/network/cut/topology/metric bindings and full span/support/incidence coverage;
2. preferred counts/parities and independently reconstructed region residuals;
3. component/exterior construction and exact demanded-vertex set `T`;
4. selected flip set and `minimumFlipCount = K*`;
5. every canonical lex-prefix decision and its constrained optimum receipt;
6. final positive counts, per-region even boundary sums, compact breakpoint generators, and semantic plan digest.

The independent validator rebuilds the incidence graph from A2b boundary walks, recomputes the minimum-cardinality T-join and each lex-prefix optimum independently of the producer's normalized rows, then checks the final schedule/objective and exact breakpoint generator. Fixed-small tests additionally exhaust parity assignments to reproduce `K*` and the lexicographic optimum without the production matching implementation.

Tamper coverage must separately falsify binding/support, incidence multiplicity/orientation, residual/T construction, flip set, optimum count, lex-prefix receipts, final counts/parity, breakpoint generation and semantic digest.

### 17.8 A4 contract correction

A3 does **not** promise that every region boundary is a convex integer rectangle. It promises an exact immutable shared subdivision and an even boundary-edge count for each disc region. A4 owns the stronger local construction question. Existing `PureQuadCompletion` already distinguishes rectangular/small-side/singularity cases from generic even-boundary combinatorial completion and typed nonconstructibility. A4 may choose among its authorized local constructions but must consume A3 breakpoints unchanged.

Field alignment and geometric quality remain required by their own downstream contracts and verification/disposition. They cannot be back-filled into A3 by fabricating family/sign identity for arbitrary topological seams.

### 17.9 CP1/CP2 evidence and checkpoint impact

Package117 / selector382 **382/382** remains accepted historical runtime evidence for the old fully framed CP1/CP2 problem; package115/selector373 remains its predecessor. Their measured results, closure records, stable regression accounting, and artifacts are not rewritten.

However, the **production-sufficiency** part of those proof obligations is superseded by this amendment. The family/sign balance solver, fixed-`M=2` Bi-MDF production optimization, typed mathematical infeasibility and their CP2 certificates cannot be cited as proof of the new baseline production A3 semantics. CP3 must re-prove the parity scheduler, certificate/validator, compact-breakpoint invariants and production reachability before cutover. This is a semantic re-proof inside CP3; it does not reopen accepted M3 A2a'/A2b authority and does not create a runtime regression event.

Until replacement runtime evidence is accepted, package117/selector382 remains the latest accepted M4 runtime authority. Existing accepted selector identities must not be silently weakened or rewritten; compatibility needed to keep them executable must remain explicitly non-production.

### 17.10 Revised CP3 sequence and successor

`M4-CP3` now proceeds in two evidence-separated stages before the final producer cutover:

1. **`M4-CP3-CB2`** implements the family/sign-free baseline parity A3 scheduler/certificate/validator and compiles new regression identities while preserving existing accepted selector identities as historical compatibility coverage. It does **not** production-wire A3 into A4 yet.
2. An artifact-only TB turn runtime-proves the new parity semantics and independent oracle/certificate surface.
3. Only after that runtime acceptance may a later CP3 Code + Build turn perform the production A3->A4 cutover, retire local target/grid and floating `support_key` shared-boundary authority, and attack the exact-torus `InvalidHardRailPairing` gate.

**Exact next: `M4-CP3-CB2` under `Architecture_M4_CP3_CB2_Code_Build_Plan.md`.** No Directional runtime belongs in that Code + Build turn.

**Historical-sequence note:** the CB2 -> artifact-only TB -> corrective CB3/TB1-R1 semantic-proof stages have since completed and package119/selector394 is accepted. Current production-cutover sequencing is further amended by §17.12; `M4-CP3-CB4-R1` is the current successor.

### 17.11 The removed A3 family/sign is not the A4 hard-rail family/sign

Recorded because §17.3 and the CP3 exit otherwise read as contradictory. CP3 must remove the exact-torus
`InvalidHardRailPairing` blocker **through A3 authority**, yet that predicate tests
`first.family != second.family || first.advanceSign == second.advanceSign`
(`src/geometry/SurfaceCellTracing.cpp:15532-15533`). No CB turn may treat this as a definition conflict.

`SurfaceFrontEdge::family` and `::advanceSign` are plain `int`s
(`include/directional/geometry/SurfaceCellTracing.h:1269-1270`), A4-local phase-front values derived from A4's
own field frame; `ConformityFamily` appears **zero times** in `src/geometry/SurfaceCellTracing.cpp`. The
phase-front layer never consumed the A3 family type, so §17.3 cannot affect those conjuncts. The same idiom
recurs at `:11642-11643`, `:13291-13292` and `:14741-14742`.

The A3-owned conjuncts are the shared-boundary agreements: `support_key` equality across the pair
(`:15527-15528`), route reversal (`:15529`), and the grouping key (`:15503-15505`) that decides
`pair.size() == 2`. An immutable exact shared subdivision gives both sides identical exact breakpoints, turning
that agreement into a guarantee instead of a floating coincidence — which is why §17.10 pairs the cutover with
retiring floating `support_key` shared-boundary authority. A4 keeps deriving its own `family`/`advanceSign`
locally and A3 never supplies them.

### 17.12 A2b must publish each full arc's exact ordered source path

`M4-CP3-CB4` proved that the reconstruction wording in §4.1 is not sufficient for the accepted public product surface.
A2b construction privately knows exact split loci for artificial cuts and mandatory barriers, but the accepted
`GlobalTopologyArc` product does not publish those loci. After a source edge is split, the parent source-edge key and
synthetic endpoint node IDs therefore do not identify which exact subinterval belongs to each A2b arc. A3 may not fill
that publication gap from synthetic-node allocation order, floating geometry, tolerance, source-face overlap, or another
invented convention.

This subsection supersedes the production reconstruction implication of §4.1 and sharpens §§17.1/17.3:

1. **A2b is the publication owner.** Every accepted `GlobalTopologyArc`, for `Mandatory`, `Trace`, and `Cut`, publishes
   one non-empty canonical ordered exact source path in `firstNode -> secondNode` orientation. A2b is the first accepted
   stage that combines A2a trace/terminal authority with A2a′ cut authority into the actual embedded-graph arc
   decomposition.
2. **One upstream-neutral exact representation is canonical.** A path point is exactly one source vertex, one source
   edge plus exact rational parameter, or one source face plus exact barycentric coordinates associated with canonical
   face-topology vertex order. A support piece binds two exact points to one `SourceSupport` carrier. The existing A3
   `ConformitySourcePoint` / `ConformitySupportPiece` surface must reuse or alias that representation rather than create a
   second independently canonicalized encoding.
3. **Exact canonical path invariants.** Pieces are nondegenerate, carrier-contained and exactly contiguous. Exact edge
   endpoints canonicalize to source vertices; interior edge points remain edge points; true face-interior points remain
   face points. The first/last path point is the exact locus of the arc's first/second node. Reverse incidence reverses
   piece order/endpoints and never creates a second semantic path.
4. **Mandatory arcs.** Each arc publishes the exact source-edge interval it owns. If A2b splits a mandatory edge at an
   A2a terminal, the two arcs publish the two exact endpoint-to-terminal intervals; neither may claim the whole parent
   edge.
5. **Cut arcs.** Each arc publishes the exact interval between the adjacent exact cut-node parameters already used by
   A2b construction. Distinct split arcs on one selected cut edge therefore publish distinct exact subintervals.
6. **Trace arcs.** Each arc publishes the exact ordered support chain for its segment range from accepted A2a exact
   entry/exit/contact/terminal authority. A missing or contradictory exact endpoint is an A2b construction/binding
   failure, not permission for geometric reconstruction.
7. **Validation and digest.** A2b candidate validation reconstructs expected support from source + accepted A2a/A2a′
   authority and compares it exactly; the candidate cannot authenticate its own support. A2b semantic hashing includes
   the published path.
8. **A3 is a copier, not a path reconstructor.** Production creates exactly one `ConformitySpanInput` per canonical A2b
   arc, with the same ordered exact support path. `GlobalTopologyArc::sourceFaces`, the parent cut edge, synthetic-node
   numbering and floating geometry are not alternate path authorities.

This is an additive A2b publication/certificate strengthening. It does not change selected cuts, arc IDs/order/topology,
rotation system, region walks, disc certificates, or accepted package119 parity-scheduler semantics. Historical M3 runtime
evidence remains authority for those unchanged semantics but does **not** prove the newly published support field. The
new publication and production A3 binder require artifact-only runtime proof before A4 may consume them.
