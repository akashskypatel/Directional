# Architecture Redesign and M1 R-A — Retained Independent Review Decisions

## Purpose

This document retains only independent-review decisions that still constrain current implementation work. Superseded chronological review narratives, resolved line-number commentary, and package-specific readiness instructions were pruned with explicit user authorization after R-A artifact-only retry 3. Historical implementation/build/runtime evidence remains in `CHANGELOG.md`, the current R-A T+B report, and the regression tracker/audit.

## Current review status

Overall R-A remains **open**. The latest immutable runtime evidence is retry 3 against exact source `555109796188b318c788ef5777f622705ee0aa94`: **92 unique selected / 86 passed / 6 failed / 0 orchestration failures**. This runtime result supersedes all earlier review-time statements that the candidate was merely “ready for retry.” M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

## Independent verification of the retry-4 R-A-TB4-CB-01/CB-02 root-cause analysis

Verified against exact tested source `aa16449577c48bac72257b7b9915e2b70dad3b82` (byte-identical to the branch head on `src`, `include`, `tests`). Documentation-only turn; no generated binary, test, benchmark, discovery, `ctest`, CLI, fuzzer, or custom input executed.

**Verdict: the root-cause chain is CORRECT. Every link was independently confirmed in source, not accepted from the report. One material refinement is required to CB-02's acceptance criterion, and the same narrowing affects CB-01 measure 2.**

### Chain confirmed link by link

| Claim | Verification |
|---|---|
| Hard-feature edges are barriers in source-topology-region construction | **Confirmed.** `SurfaceCellTracing.cpp:2617-2619`: inside `build_source_topology_regions` (2539-2927), an edge present in `options.hardFeatureEdges` hits `continue` before the adjacency link is written, so the two incident faces are never joined into one region. |
| The witness therefore yields one-triangle regions | **Confirmed.** `make_disconnected_square_pair_mesh` has faces `(0,1,2),(0,2,3)` and `(4,5,6),(4,6,7)`. The marked edge is the interior diagonal in both cases, so the affected square splits into two single-triangle regions with three edges and three vertices each. |
| The bounded-disk producer declines regions with fewer than four boundary edges/vertices | **Confirmed.** `SurfaceCellTracing.cpp:8051-8053`: `if (boundaryEdgeKeys.size() < 4U \|\| boundaryAdjacency.size() < 4U) return result;` — the early return leaves the default `NotApplicable` disposition. Both conditions fail for a triangle. |
| With no phase-front product, the CB-02 `HardRail` projection cannot run | **Confirmed.** `project_materialized_hard_feature_rails_from_lineage` is guarded by `useAuthoritativePhaseFront`, which is `phaseFrontProduct != nullptr`. |
| A later generic completion rejection can overwrite earlier producer context with an empty reason | **Confirmed.** `RemeshPipeline.cpp:7904-7910`: the `else` branch assigns `surfaceCellFirstInvalidProducerStage = "completion"` and sets the reason to `completionResult.failure`, falling back to `outputLineageValidation.failure`, with **no guard preserving an already-set non-empty reason**. When both strings are empty the reason becomes `""`. This matches the observed stage `completion` with an empty first-invalid-producer reason exactly. |

The analysis is also honest about what retry 4 disproved: the outer aggregate does copy inner component diagnostics, so the remaining loss is inside the component pipeline. That is consistent with the observed outer-empty reason.

One detail the durable text under-describes: `ComponentFeatureRailTamperRejectsAtAggregationSeam` marks `{4, 6}` (the second square's diagonal) while the other three mark `{0, 2}`. The mechanism is identical, but the docs read as though a single edge is involved. Worth stating precisely so a future turn does not "fix" one component and expect all four contracts to move.

### RA-TB4-F1 — CB-02's acceptance criterion names the wrong producer

**Material. Correct before the Code + Build turn starts, or the new witness may be built against the wrong precondition.**

**Evidence**

- The phase-front producer chain at `SurfaceCellTracing.cpp:9549-9564` tries **three** producers in order per region: `build_uniform_phase_front_for_faces`, then `build_periodic_annulus_phase_front_for_faces` on `NotApplicable`, then `build_curved_bounded_disk_phase_front_for_faces` on `NotApplicable`. Only if all three decline does the region land on the `firstUnsupportedRegion` path (`:9576-9579`).
- The analysis names only the third producer and its `< 4` extent rule. For this witness the conclusion still holds — all three decline and no product is created, which the runtime evidence independently establishes — but the `< 4` rule is merely the **last** of three declines, not the binding constraint.
- For a **planar** witness the binding constraint is the **first** producer. `build_uniform_phase_front_for_faces` (from `:6024`) is gated on `build_planar_phase_frame` succeeding, and its own comment records that "Non-planar, non-rectangular, or globally non-uniform phase domains are outside this bounded producer." A hard diagonal fails there because a triangle is not rectangular — long before the bounded-disk extent rule is consulted.
- Consequence for CB-02 as written: "regions … satisfy current phase-front bounded-disk preconditions" would steer the next turn toward giving each separated region four or more boundary edges. That is **necessary but not sufficient** and points at the wrong gate. A non-rectangular planar region with five boundary edges would still be declined by the uniform producer and would still fail. Conversely, a rectangular sub-region is produced by the uniform producer and never reaches the bounded-disk rule at all.

**Corrective measures**

1. Restate CB-02's criterion as: the hard-feature-separated regions must be **produced by whichever producer in the `:9549-9564` chain applies**, and for a planar witness that is the uniform producer's planar-and-rectangular domain — not the bounded-disk extent rule.
2. Build the witness accordingly: split the square with an internal hard feature along a **mid-line of a sufficiently resolved grid** so that each separated region is itself rectangular. A diagonal can never satisfy this, at any resolution, because it yields triangles.
3. Make the new contract assert that a phase-front product was actually **produced** — for example that the producer disposition is `Produced` and `useAuthoritativePhaseFront` held — rather than inferring it from downstream success. Otherwise a future regression that silently drops back to a non-materialized path would present as a different failure.

### RA-TB4-F2 — CB-01 measure 2 inherits the same narrowing

**Minor; fix alongside RA-TB4-F1.**

CB-01 measure 2 requires a typed unsupported condition when a region is outside every producer's domain "because its bounded-disk boundary extent is below the supported minimum". Keying the typed condition on the bounded-disk extent would miss the larger class: any region all three producers decline, including non-rectangular regions with four or more boundary edges. Key it on the existing "no producer applicable" outcome — the `firstUnsupportedRegion` path at `:9576-9579` — so the typed unsupported condition covers every decline, and record which producers declined.

### Assessment

This is the strongest failure analysis produced in this sequence: it is source-grounded, correctly separates the unsupported witness from a production defect, and explicitly refuses the tempting shortcuts (boundary-only feature, callback-synthesized rails, validator weakening). The two findings above narrow the corrective criteria to the constraint that actually binds; neither disputes the diagnosis.

## Retained architectural/review decisions

### 1. Single-authority direction is accepted; closure requires runtime proof

R-A is one continuous checkpoint. Typed source/component/sheet/chart/stitch/rail authority must remain single-writer and fail-closed through producer, completion, aggregate remap, optimizer, and final source-authoritative validation. Compile/static success is necessary but never semantic closure.

Do not resolve R-A failures by:
- restoring numeric/raw semantic mirrors;
- fabricating IDs, support, rails, or authority in consumers/tests;
- bypassing canonical identity reconstruction;
- weakening source-authoritative validation or completion ownership;
- treating a later validator as tested when execution failed earlier.

### 2. Attempt-1 authority-transport diagnosis was corrected

The original attempt-1 report attributed `optimization / MissingSourceAuthority` to a null `phaseFrontProduct` guard. Independent review rejected that mechanism. The actual defect was post-move lifetime: a pointer captured into the local trace network survived the move but observed moved-from state. The retained pre-move `sourceTopologyRegions` owner was the correct authority carrier.

That correction is runtime-vindicated: later retries moved beyond `optimization / MissingSourceAuthority`. Do not re-adopt the rejected null-guard diagnosis.

### 3. Completion/stitch chart closure is accepted but must remain discriminating

The completion redesign that publishes owner-valid chart closure rather than one patch-local singleton chart is accepted. Runtime retry 3 confirms both positive compatibility and negative discrimination:
- same exact boundary identity with valid compatible typed authority can merge;
- same region/sheet with genuinely different completed support still rejects with `IncompatibleTypedStitchAuthority`;
- wrong owner sheet rejects with `InvalidTypedStitchAuthority`.

The broader chart closure therefore must not be narrowed back to patch-local singleton authority or broadened into compatibility-by-default.

### 4. Aggregate identity cache is derived, not source authority

`boundaryNodeIdentities` is a derived cache. Missing cache cardinality is not itself missing source authority and may be rebuilt from completion-owned canonical lineage. Canonical reconstruction must remain fail-closed when lineage/ownership is invalid.

Retry 3 shows the remaining F4 failure is a test-fixture accounting defect: the “same-cardinality stale cache” counterfactual did not actually create same cardinality. Do not change production cache semantics merely to force rebuild count `0`.

### 5. Component feature-option transport must be conservative and explicit

Global user hard/soft feature edges must be canonicalized and mapped into exactly one component owning the actual source edge. Requests not owned by exactly one component must be explicitly counted/typed; unassigned hard requests fail closed, while unassigned soft requests may remain advisory but cannot disappear silently.

Retry 3 runtime-confirms this transport/no-leakage/conservation contract. The remaining feature failures occur later at **component completion** and must be diagnosed there rather than reopening global-to-local remap.

### 6. Final source-authoritative oracle must receive independent remapped authority

Aggregate/final validation must consume independently remapped source topology, provenance, boundary authority, and feature rail authority. Counterfactual negatives must mutate a real semantic certificate and prove that the intended final-oracle seam was reached. A mutation that can be semantically neutral is not a valid negative.

Retry 3 demonstrates this for provenance: forcing `(1,0,0)` on an output point can be the already-valid source-corner certificate. The replacement negative must prove its mutation changes the semantic provenance before expecting rejection.

## Independent pre-runtime review of the retry-3 Code + Build remediation

Reviewed at implementation `199b06f429d8004a5b51c89f94ae33748f4ec38c`, which is byte-identical on `src`, `include`, `tests`, and the audit script to the compile-pinned source `aa16449577c48bac72257b7b9915e2b70dad3b82` and to the branch head. Compile run `31674780558` passes `source_sha: aa16449577c4…` into `agent-compile-reusable.yml`, which asserts checkout equality before archiving. The static inventory reproduces byte-for-byte from the tree at **19 paths / 60 probes / 270 matches / PASS**.

**Verdict: R-A-TB3-CB-01 through CB-04 are accepted at the Code + Build boundary. The candidate is ready for retry 4.** One documentation defect was found and corrected during this review (below); it required no source, package, or artifact change.

### Verified

- **CB-01** builds a genuine same-cardinality stale cache: the counterfactual first `assign`s `boundaryNodeIdentities` to `boundaryVertices.size()` and *then* injects valid stale-token identities, so rebuild count `0` is now a real observation rather than an artifact of a short cache. The canonical/valid/non-stale publication assertions and the separate missing-cardinality exact-count positive are both retained.
- **CB-02** replaces geometric-proximity rail projection with lineage projection and is fail-closed in the right places. Output sequences are grouped by `(railId, front-edge pair)` from `HardRail` equivalence provenance; each segment must resolve to exactly two output vertices whose edge exists in the actual output mesh; adjacency is degree-checked, and the walk verifies full traversal plus the correct open/closed sequence length. Structural malformation returns false and fails the run with `InvalidMaterializedHardFeatureAuthority` at `completion/feature-authority`. Critically, a rail that cannot be projected is **not silently dropped**: it lands in `missingFeatureRailIds` while `requiredFeatureRailCount` still counts every hard rail, and that count reaches `validatorOptions.expectedFeatureRailCount` (`SurfaceMeshOptimizer.cpp:1816-1817`), so the mismatch surfaces as `MissingFeatureRail`.
- **CB-03**'s expectation is reachable: `SourcePositionMismatch` exists (`MeshValidator.h:48`), is named (`MeshValidator.cpp:54-55`), and is emitted by the strict validator (`SourceAuthoritativeMeshValidator.cpp:1193`). The counterfactual now preserves the barycentric certificate, perturbs `SurfacePoint.position`, and `ASSERT`s the change before expecting rejection — which is exactly the "prove the mutation is not semantically neutral" requirement.
- **CB-04**: every contract named for retry 4 in the handoff and `TODO.md` exists in `tests/`; the only unresolved names are validator failure codes, not test filters.

### RA-TB3-F1 — a cited implementation commit did not exist (corrected here)

The handoff, `TODO.md`, the Code + Build plan, `REORIENTATION_PLAN.md`, and `CHANGELOG.md` all recorded the semantic implementation commit as `199b5aa85d02d8ef085161e3cdfe49f043e15ee1`. **That object does not exist** — it is absent locally and a targeted `git fetch origin <sha>` could not retrieve it. The actual implementation commit is `199b06f429d8004a5b51c89f94ae33748f4ec38c`.

The gate itself was never at risk: the compile-pinned `aa16449577c4…` is correct and source-identical to the real implementation and to the head, so the package is built from the intended code. But the handoff's start-of-turn checklist directs the retry to confirm provenance before consuming the package, and one of the two cited commits was unverifiable. All five occurrences are corrected to `199b06f4…`.

### Non-blocking notes for a later turn

- CB-03 asserts the provenance mutation changed the position by more than `1e-12`, not that it exceeds the validator's position tolerance. The applied offset is ~0.573 on a unit-scale fixture, so it will hold comfortably; the assertion nonetheless documents "changed" rather than "changed enough to be rejected".
- `project_materialized_hard_feature_rails_from_lineage` bounds-checks `lineage.outputVertex` against `lineages.size()` rather than the output vertex count. These are equal wherever the aggregate rebuild enforces one lineage per output vertex, so it is correct today, but it is the wrong bound if that invariant ever changes.

## Current bounded findings after retry 3

These are runtime findings, not new independent-review verdicts:

1. **F4 fixture accounting:** create a truly same-cardinality stale boundary cache before requiring zero cardinality rebuilds.
2. **Feature-bearing completion:** four aggregate/final-oracle feature contracts stop at `completion`; preserve the exact completion reason and determine production defect vs precisely unsupported fixture before editing.
3. **Provenance counterfactual:** replace the potentially neutral `(1,0,0)` mutation with a guaranteed semantic mismatch.

The authoritative corrective task details are in `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

## Deferred post-R-A review hygiene

- **RA-REV-23-F3:** the R-A audit should dispatch the stitch-kind structural classifier through an explicit probe field rather than probe-name text, render the classifier actually executed, and include a negative self-test.
- **RA-REV-22-F6:** validation-used flags/assertions must be made falsifiable by setting them where gates actually execute or removing assertions that are tautological after publication.

These remain post-R-A hygiene and do not replace the active runtime blockers.

## Durable review lessons

- Verify the mechanism before naming a root cause; a non-null pointer can still reference moved-from state.
- Matching extent is not ownership; source authority must match exact source-face topology.
- A negative proves only the guard it actually reaches.
- Derived caches must be reconstructible from canonical authority; cache presence is not source authority.
- Global vertex IDs must be explicitly remapped before options enter compact component meshes.
- Test fixtures must establish intended semantic preconditions naturally; “green” caused by a neutral mutation or unreachable callback is not contract evidence.
- Zero-selected test filters are orchestration failure, never pass.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**.
