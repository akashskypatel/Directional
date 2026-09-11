# M4-CP3-DEFN-R1 Review / Definition Record

**Status:** COMPLETE / BASELINE A3 INCIDENCE CONTRACT REVISED / RUNTIME-FREE / EXACT NEXT `M4-CP3-CB2`
**Date:** 2026-09-11 UTC
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Review source authority:** source-snapshot event `7e90e48b0e267d312fd5c92f900c248042e4bdd9`, run `34547115117`, artifact `10179427792`, outer SHA-256 `22455a3803749481b8f59496640eac621b107afbb96f05c5026bb4fe5925088d`

This is the runtime-free definition/review turn required by the halted `M4-CP3-CB1` derivation guard. No Directional binary, test, benchmark, discovery command, compile, package repair, production/test semantic mutation, or selector execution was performed.

## 1. Question re-opened

CB1 stopped because accepted A2a'/A2b source authority could not uniquely derive `ConformityFamily U|V` and `ConformitySign +/-` for production `GlobalTopologyArcKind::Cut` arcs. DEFN-R1 independently re-opened the upstream product shapes, the current A3 frozen definition, downstream A4 completion semantics, and the accepted CP1/CP2 proof surface rather than assuming the CB1 diagnosis was complete.

The required decision was whether to:

- A — give artificial cuts distinct/family-free conformity incidence semantics;
- B — strengthen A2a'/A2b so cellularizing cuts carry field-frame certificates;
- C — derive an exact combinatorial frame from already accepted source authority.

## 2. Independent source re-derivation

The CB1 stop was correct, but its stated scope was too narrow.

### 2.1 Artificial cuts are unframed

Production A2b contains real `GlobalTopologyArcKind::Cut` arcs generated from `SurfaceCutGraph` source edges. The cut graph publishes exact source-edge, support and topology authority, but not a global U/V family or sign. The accepted torus contains 28 such cut edges, so the gap is production-reachable.

### 2.2 Mandatory arcs are also not universally framed

`FieldAlignedMandatoryEdge` contains rail/source-edge/kind/endpoints/component/topology-region provenance but no globally comparable field branch, U/V family or sign. `SurfaceCellRail` likewise has curve/component/source support but no universal frame certificate. `GlobalTopologyArcKind::Mandatory` forwards that provenance; it does not add family/sign.

Therefore a cut-only patch would have left the same authority gap on arbitrary hard-feature/source-boundary mandatory arcs.

### 2.3 Trace-local branch data does not repair the general gap

Trace construction may carry exact per-face branch information, but raw `FieldBranch` values are face-gauge-local. Cross-face integer comparison is not a semantic global U/V identity. A production binder that inferred family/sign from those integers, nearest-arm geometry, or a tolerance would violate the frozen exact-identity rules.

### 2.4 Existing A4 does not require universal global U/V/sign for topological completion

The current `PureQuadCompletion` surface accepts generic disc boundaries with even total boundary edge count in its bounded combinatorial path; rectangular and 3-6-side/singularity rules are stronger local cases. `PatchQuadrangulator` likewise has a generic even-boundary fallback. Thus the prior frozen statement that every A4 region is a convex integer rectangle is stronger than the current accepted local-completion contract.

The architectural invariant that **is** common to all pure-quad disc completions is even boundary-edge parity. Stronger field/shape/geometry constructibility remains local A4 authority and may produce a typed nonconstructible/degraded outcome; it cannot renegotiate shared boundary points.

## 3. Alternative adjudication

### 3.1 Alternative A — ACCEPTED, expanded

Baseline A3 conformity is redefined as exact shared subdivision plus region all-quad parity. Every A2b arc kind (`Mandatory`, `Trace`, `Cut`) is a canonical full-span scheduling variable with exact support and incidence orientation. Family/sign are not production-baseline inputs.

This uses only already accepted A2b authority and preserves the single-writer rule: A3 chooses one exact count and one compact exact-ordinal breakpoint sequence per shared span; A4 only consumes it.

### 3.2 Alternative B — REJECTED

Requiring all artificial cuts to become field-certified would reopen M3 A2a'/A2b semantics and contradict the accepted cellularization rule that may use otherwise admissible source edges, including trace-crossed edges. It still would not provide a frame for all mandatory source-boundary/hard-feature arcs. This is a larger change without solving the whole authority problem.

### 3.3 Alternative C — REJECTED

A deterministic ordinal or combinatorial label is not a source-derived coordinate frame. No accepted product/theorem establishes gauge/relabel invariance for such a label. Raw cross-face `FieldBranch`, boundary ordinal, geometric nearest-arm and tolerance rules are all rejected.

## 4. Frozen baseline A3 semantics

The normative contract is now `Architecture_M4_DEFN_Frozen_Definitions.md` §17. In compact form:

1. one `ConformitySpanId` per full A2b arc, all arc kinds;
2. one or two boundary incidences per span, with region and orientation; multiplicity is semantic;
3. no production-baseline family/sign field;
4. one exact positive arbitrary-precision count `x_s >= 1` per span;
5. exact compact breakpoint identity `{span, exactOrdinal}` and exact support-piece location unchanged;
6. preferred exact target count `d_s` and objective `J=(Σ|x-d|, canonical count vector)` unchanged;
7. each region requires `Σ boundary-incidence x_span ≡ 0 (mod 2)`;
8. A4 may not alter A3 counts/breakpoints; stronger local constructibility is A4-owned.

## 5. Exact scheduler reduction

Let preferred parity be `q_s=d_s mod 2`, and let `y_s` indicate a parity flip. For a fixed parity the nearest positive count is unique: `d_s` without a flip, otherwise `d_s-1` when `d_s>1` or `2` when `d_s=1`. Every flip costs exactly one primary deviation.

The parity equations therefore reduce to a minimum-cardinality `T`-join on the region-incidence graph:

- two-region spans are graph edges;
- same-region double incidences are self-loops and have zero GF(2) effect;
- source-boundary terminals connect to a component-local virtual exterior vertex;
- demanded vertices are the independently reconstructed residual parities under preferred counts.

Closed components necessarily have even demand cardinality. Boundary components choose the exterior demand as the XOR of region demands. A solution always exists; all counts equal to two are a constructive positive witness. Hence baseline A3 has **no ordinary mathematical infeasibility outcome**.

Primary optimization is exact minimum T-join cardinality. The lexicographically least count vector is obtained by canonical prefix refinement: for each span, try the parity giving the smaller local count and retain it only if an exact constrained T-join solve proves the global minimum flip count remains attainable. This preserves the primary optimum while selecting exactly the frozen lexicographic tie.

## 6. Certificate and independent verification

The product/certificate must bind source/network/cut/topology/metric digests, full support paths and incidence multiplicity/orientation, preferred parities, residual/T construction, minimum flip count, selected flip set, canonical lex-prefix decisions, final counts/parity, compact breakpoint generators and final semantic digest.

The validator reconstructs the region-incidence graph directly from A2b boundary walks and independently recomputes the minimum-cardinality T-join and each constrained lex-prefix optimum. Fixed-small tests additionally enumerate parity assignments to verify the production optimizer without sharing its algorithm.

Because `x_s=2` is always a witness for valid bindings, prior CP2 `ConformityInfeasibleSubset` / `BalanceCut | PositivityCut | ParityCut` semantics are historical framed-mode evidence, not baseline production outcomes. Malformed binding/support/metric/work-bound failures remain typed construction errors.

## 7. CP1/CP2 impact

The review distinguishes historical fact from current production sufficiency.

- Package117 / selector382 **382/382** remains accepted historical runtime evidence for the framed CP1/CP2 contract. Package115/selector373 remains its accepted predecessor history. Their artifacts/results are not invalidated or rewritten.
- Stable regression accounting remains **47 events / 14 categories / 33 recurrences** and produced-witness debt remains **5**. No runtime event occurred in this DEFN turn.
- The **production-baseline semantic proof obligations are superseded/re-opened for re-proof inside CP3**. Family/sign balance, fixed-`M=2` Bi-MDF optimization, typed ordinary infeasibility and their CP2 certificate are not sufficient proof of the family-free parity baseline.
- Existing selector382 identities must not be silently weakened. If compatibility code is required to keep them executable, it must be explicitly non-production and structurally unreachable from the production A3 binder.
- Package117 remains latest accepted M4 runtime authority until new parity runtime evidence is accepted.

This does **not** reopen M3. A2a'/A2b topology/cut authority is the evidence that forced the corrected A3 contract and remains accepted.

## 8. Design correction at A4

`DESIGN.md` is amended so A3 no longer promises every region a convex integer rectangle. Baseline A3 promises immutable exact shared subdivisions and even disc-boundary parity. A4 owns rectangular/small-side/singularity/general-even-boundary construction and may return a typed nonconstructible/degraded result without editing shared breakpoints. Field/geometry quality remains independently verified downstream.

## 9. Regression/root-cause classification

`M4-CP3-DEFN-R1-CAND-01` is classified **RESOLVED BY DEFN-R1 / DEFINITION-AUTHORITY OVERREACH / NON-STABLE**. Root cause: the frozen framed A3 contract required family/sign data that accepted upstream products do not universally own; CB1 exposed the gap on Cut arcs and DEFN-R1 independently extended the finding to Mandatory arcs. No stable event/category/recurrence count changes.

## 10. Successor and evidence cadence

Exact next is runtime-free **`M4-CP3-CB2`**. It implements and compiles the parity scheduler/certificate/validator plus new regression identities, but deliberately does **not** production-wire A3 into A4 in the same turn. An immutable artifact-only TB must first prove the new semantic core. Only a later CP3 Code + Build may perform the producer cutover and remove local `gridU/gridV` / floating `support_key` shared-boundary authority.

This separation keeps the definition correction independently testable and avoids mixing a scheduler semantic rewrite with the production cutover that motivated it.

## 11. Consolidation disposition

This review supersedes the current-review role of the CP2 R1 review and consumes the halted CP3 CB1 plan/guard. Durable CP2 runtime facts remain in the retained R1 runtime report, closure record, tracker, changelog and `M4_Consolidated_Record.md`. The following documents are folded after their facts are preserved:

- `Architecture_M4_CP2_TB2_R1_Review_Record.md` — 190 lines;
- `Architecture_M4_CP3_CB1_Code_Build_Plan.md` — 141 lines;
- `Architecture_M4_CP3_CB1_Derivation_Guard_Record.md` — 60 lines.

Full prior text remains recoverable from Git history. No selector, closure record, durable policy, normative definition, or unresolved runtime report is folded.

---

## 10. Independent verification addendum (reviewing agent)

Runtime-free. The amendment is **upheld**: the CB1 stop was genuine, the widened scope is correct,
and the parity reduction is mathematically sound. One unstated fact is recorded as frozen §17.11
because without it the next Code + Build turn can reasonably halt on the same guard again.

### V1 — the reduction is correct, checked step by step

Each step of §17.6 was re-derived rather than accepted:

- **Flip cost is exactly 1.** `y_s=1` gives `x_s = d_s - 1` when `d_s > 1` and `x_s = 2` when
  `d_s = 1`; both are one unit from `d_s`, and the `d_s = 1` case correctly avoids `x_s = 0`, which
  the positivity rule forbids.
- **Self-loops have zero parity effect.** A same-region two-incidence span contributes `2·x_s ≡ 0
  (mod 2)` whatever `x_s` is, so it can never repair a residual — and since flipping still costs 1,
  it is never flipped at primary optimum. §17.6's closing claim follows from the procedure rather
  than standing beside it.
- **Even residual is the handshake argument.** Every non-loop span contributes to exactly two
  region parities, so on a closed component the residual-demand set has even cardinality and a
  T-join exists. The virtual exterior vertex, kept local to its connected incidence component, is
  what makes one-ended source-boundary spans behave the same way.
- **Minimum-cardinality T-join is the right object**, and it is exactly solvable in polynomial time
  through shortest paths plus minimum-weight perfect matching. The accepted exact matching surface
  built for CP1/CP2 therefore remains the correct primitive under integer cardinality weights; this
  amendment redirects that investment rather than stranding it.
- **The lexicographic tie-break is the standard constrained-optimum construction.** Fixing a prefix
  and keeping a choice iff the constrained optimum is still `K*` maintains the stated invariant, and
  the "smaller resulting `x_s`" branch is right in both directions — flip when `d_s > 1` (giving
  `d_s - 1 < d_s`), no flip when `d_s = 1` (since flipping would give `2 > 1`).

§17.7's contract also answers the defect class that dominated CP1/CP2: the validator rebuilds the
incidence graph and recomputes the T-join and each lex-prefix optimum independently of the producer,
per-decision receipts are published rather than only the final answer, and tamper coverage is
required per field family rather than per broad noun.

### V2 — the amendment does **not** put CP3's exit out of reach (recorded as §17.11)

This is the gap. §17.3 removes `ConformityFamily` / `ConformitySign` from the production baseline,
while CP3's frozen exit requires the exact-torus `InvalidHardRailPairing` blocker to be removed
**through A3 authority** — and that blocker's predicate literally tests
`first.family != second.family || first.advanceSign == second.advanceSign`
(`src/geometry/SurfaceCellTracing.cpp:15532-15533`). Read side by side and with nothing connecting
them, those two statements look like a contradiction, and §17 never addresses the torus gate except
to defer it.

They are not in contradiction, and the reason is checkable:

1. `SurfaceFrontEdge::family` and `::advanceSign` are plain `int`s
   (`include/directional/geometry/SurfaceCellTracing.h:1269-1270`) — A4-local phase-front values
   derived from A4's own field frame. They are not the A3 `ConformityFamily` / `ConformitySign`
   enums under another name.
2. `ConformityFamily` appears **zero times** in `src/geometry/SurfaceCellTracing.cpp`. The phase-front
   layer has never consumed A3's family type, so removing it from the A3 baseline cannot change that
   predicate. The same `family`/`advanceSign` idiom recurs at lines 11642-11643, 13291-13292 and
   14741-14742, confirming it is A4's own pervasive local structure.
3. The conjuncts of the pairing predicate that **are** A3-owned are exactly the ones exact shared
   subdivision fixes: `support_key(first.from) != support_key(second.to)` and its mirror
   (`:15527-15528`), `first.route != second.route.reversed()` (`:15529`), and the grouping key
   (`:15503-15505`) whose collisions decide `pair.size() == 2`. An immutable shared subdivision makes
   both sides of a shared boundary carry *identical exact breakpoints*, which is precisely what turns
   that agreement from floating-point coincidence into a guarantee — and is why §17.10 pairs the
   cutover with retiring floating `support_key` shared-boundary authority.

So the blocker's A3-owned half is addressed by the baseline contract and its A4-owned half was never
A3's to supply. CP3's exit stays reachable. Recorded as frozen §17.11 so the next CB does not
re-derive this under a halt.

### V3 — CP2's closure is narrowed, not invalidated

§17.5 makes `ConformityInfeasibleSubset` and the `BalanceCut | PositivityCut | ParityCut` outcomes
unreachable in the production baseline, since `x_s = 2` everywhere is always a positive witness. The
CP2 exit conjunct I upheld one turn ago — a genuinely infeasible constructed component yielding a
verified subset-scoped fact — therefore certifies a surface production will no longer reach. §17.9
states this honestly: package117/selector382 remains accepted historical runtime evidence and the
latest accepted M4 runtime authority, while the *production-sufficiency* part of those obligations is
superseded. That is the correct accounting; the closure was valid for the contract in force when it
was made, and nothing in it is withdrawn. The framed surface must be kept as an explicitly separate
layer (§17.3) so accepted selector382 identities stay executable and green.

No stable regression arises from a definition turn: accounting remains **47 / 14 / 33**, debt **5**.
