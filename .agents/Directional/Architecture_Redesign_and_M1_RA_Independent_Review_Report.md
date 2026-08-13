# Architecture Redesign and M1 R-A — Retained Independent Review Decisions

## Purpose

This document retains only independent-review decisions that still constrain current implementation work. Superseded chronological review narratives, resolved line-number commentary, and package-specific readiness instructions were pruned with explicit user authorization after R-A artifact-only retry 3. Historical implementation/build/runtime evidence remains in `CHANGELOG.md`, the current R-A T+B report, and the regression tracker/audit.

## Current review status

Overall R-A remains **open**. The latest immutable runtime evidence is retry 3 against exact source `555109796188b318c788ef5777f622705ee0aa94`: **92 unique selected / 86 passed / 6 failed / 0 orchestration failures**. This runtime result supersedes all earlier review-time statements that the candidate was merely “ready for retry.” M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

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
