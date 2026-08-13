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
