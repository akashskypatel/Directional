# M4-DEFN Frozen Definitions — Global Conformity

**Status:** FROZEN / `M4-DEFN` COMPLETE / EXACT NEXT = `M4-CP1-CB1` / PLANNING ONLY / RUNTIME-FREE
**Date:** 2026-09-09
**Definition authority:** latest amended M3 closure state at substantive head `327794a7db3f22e8326ae48bfb78d8a8052a6a0d`, re-materialized by source-snapshot run `34416013987` at event SHA `60670e53f55355146b224e01850ba75526c727cb`.

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

## 7. Deterministic polynomial solver contract

M4 forbids generic ILP/branch-and-bound. The implementation must use the dedicated **bi-directed minimum-deviation
flow** formulation required by `DESIGN.md` §4.7, with a deterministic skew-symmetric/direct residual representation or
an equivalent dedicated formulation whose integer correspondence is proved in code comments and tests.

The solver contract is:

1. canonicalize spans, region-family rows and incidence ends by semantic IDs;
2. establish the preferred vector `d` and lower-bound-shifted exact imbalance;
3. solve the bi-directed minimum-deviation problem with the exact lexicographic objective `J(x)` from §5. Use a
   polynomial dedicated min-deviation/convex-cost-flow algorithm whose cost domain is an exact lexicographic vector of
   dimension `E+1` (primary deviation coordinate followed by one canonical count coordinate per span), or an equivalent
   symbolic ordered-cost representation proved to return the same vector optimum. Residual-cost addition/comparison is
   exact and lexicographic; **big-M scalarization is forbidden** because semantic correctness may not depend on an
   invented magnitude bound;
4. return the unique `J`-minimum exact count vector directly. No linear scan, breakpoint enumeration, or search over a
   numeric count range is permitted; polynomial work is measured in `V`, `E` and encoded exact bit width, not count
   magnitude;
5. emit compact primal counts and, from CP2 onward, algorithm-native dual/residual witnesses sufficient for independent
   verification. No solver step may enumerate semantic breakpoints.

### 7.1 WorkLedger and monotone measure

The solver is combinatorial and must publish bounded progress. Its `WorkLedger` records:

- normalized `V`, `E` and maximum encoded exact-integer bit width `B`;
- the chosen solver primitive's proved polynomial step bound `P(V,E,B)` including exact lexicographic-vector cost
  operations; the bound may depend polynomially on vector dimension `E+1` and encoded bit width but never linearly on
  the numeric magnitude of an exact count;
- `remainingCertifiedSteps`, initialized once to `P` and decremented on every solver state transition; it is never
  reset by a residual phase or cost-vector comparison;
- `remainingCanonicalSpans`, a monotone accounting projection over canonical span variables finalized by the solve; it
  may decrease in batches but never increase or reset;
- maximum observed exact-integer bit width and peak residual-arc count.

The lexicographic pair `(remainingCanonicalSpans, remainingCertifiedSteps)` decreases under the active phase's declared
ordering; a step cannot reset an exhausted budget. Hitting zero before the algorithm reaches its certified terminal
state is `WorkBoundExceeded`, an implementation/evidence failure, not permission to truncate, approximate or retry with
a local schedule. CP-SCALE must replace provisional generous evidence bounds with measured/calibrated production
bounds without changing semantic decisions.

## 8. Certificates and typed outcomes

### 8.1 Scheduled-component certificate — CP2 addition

CP1 has no carried final certificate; its separately implemented validator independently recomputes and checks feasible
plans. CP2 adds the immutable carried certificate without changing the CP1 schedule. For each scheduled component the
CP2 certificate contains at minimum:

- binding/normalized-problem digest;
- exact compact `x_s`, preferred `d_s`, objective `C*` and mandatory region/family parity results;
- every region-family balance and positivity result;
- solver-native residual/dual data sufficient to prove no improving admissible move exists;
- exact lexicographic-vector objective/dual-residual evidence sufficient for independent canonical-minimizer
  verification;
- work-ledger bounds and observed maxima.

The certificate hashes compact schedule/generator data; it never expands O(`x_s`) breakpoint vectors. A certificate is
evidence carried by the product, not trusted because the producer emitted it.

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
6. re-evaluates `C(x)` and, from CP2 onward, the carried primal/dual or residual optimality witness;
7. verifies lexicographic tie minimality from an independent solve/check path;
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
| exact-torus `G4-B002` | **already reaches regional phase-front aggregation** and fails at the current post-hoc `InvalidHardRailPairing` seam | CP3 | gating once A3 is production-wired; failure before A3 is evidence, not a weakened gate |
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
  deterministic permutation/reversal invariance is proved, and the independent oracle rejects structural/binding tamper.
- **CP2 closes** when positivity and optimality are independently certified and a genuinely infeasible constructed
  component yields a verified subset-scoped fact without ad-hoc schedule substitution or run-wide A3 failure.
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
- using a generic ILP/branch-and-bound solver or inexact feasibility/reduced-cost comparison;
- activating an unfrozen 2:1 adaptivity constraint without a new authoritative input contract/review;
- repairing an infeasible component locally instead of publishing its typed obstruction;
- assigning D0–D4 inside A3;
- making CP-COND algorithm details a precondition for A3 semantics;
- moving uncalibrated S1 measurements into a hard numeric gate without review;
- importing `G4-B004` relation/embedding work into M4;
- using selector409 as the accepted M4 predecessor;
- re-opening M3 based on the refuted “TB-R9 never ran” premise.

## 16. Exact successor

**`M4-CP1-CB1` — canonical Code + Build / runtime-free.** Its frozen plan is
`Architecture_M4_CP1_CB1_Code_Build_Plan.md`. No M4 runtime or benchmark is authorized before that Code + Build turn
produces a GMP/GMPXX-linked immutable package and the next artifact-only Test + Benchmark plan.
