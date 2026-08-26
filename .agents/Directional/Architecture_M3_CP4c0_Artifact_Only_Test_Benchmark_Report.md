# M3-CP4c-0 Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-0-TB-R4`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: artifact-only Test + Benchmark; no configure/build/relink/repair/generated discovery/performance benchmark
- Semantic/package source: `de291a17d5e9bfb6f54918660320ecfa1d521be4`
- Runtime event/control SHA: `bb21207f288c631b1d4149b56b37e78080edade7`
- Immutable build artifact: `9591540182`
- Immutable package ZIP SHA-256: `8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`
- Embedded source archive SHA-256: `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32`
- Authoritative workflow run / Test + Benchmark job: `32928381384 / 98055727654`
- Result artifact: `9592385698`, SHA-256 `6ffe56ef5a86bf44dfd2ea4e2f44514d71b6037cc5c34067aeda571a70260643`
- Diagnostic-log artifact: `9592386266`, SHA-256 `669e51f2d0c30573c751c43a4d49b737f8a4ddeba8be2236f9782c995f6ac3cb`
- Status: **COMPLETE / VALID SEMANTIC RED — 338/338 PASS; F3 2/2 PASS; G5 PASS/non-gating; Q8 CREDITABLE / RED**

## Executive result

TB-R4 validates the entire corrected CP4c-0 prerequisite gate: the unchanged frozen selector is **338/338 PASS**, accepted predecessor **316/316 PASS**, prior CP4c-0 prefix **328/328 PASS**, both F3 supplementals are **2/2 PASS**, and the G5 always-publishing diagnostic is **PASS / non-gating**. The TB-R3 test-side candidates at ordinals 333 and 334 are runtime-closed without any production-source change.

Q8 became creditable and is **RED at criterion 2**: the prescribed sphere reaches source-topology and field-transport-atlas authority but `FieldAlignedCurveNetwork::make` does not publish a network. G5 names the A2a outcome as `BranchTransportFlowDisagreement` at shared source edge `6-8`, from source face `6-8-9` branch `3` to related face `6-8-97` branch `1`, with trace seed vertex/singularity `0/0`. This matches P4's predicted remaining Q8 red, but the concrete rejection is a **non-stable semantic candidate pending independent review**, not an automatic production-regression classification.

The workflow job itself concluded failure because a **post-semantic reporting-control bug** referenced shell variable `first_red` after runtime state had been persisted as `first_red_ordinal`. The error occurred after post-runtime manifest and byte inventories were generated and compared. The uploaded evidence preserves those inventories, the 338/F3/G5 ledgers, and Q8 state; the corresponding pre/post inventories are identical. Under the frozen rerun policy, this is not grounds for a semantic rerun because valid deterministic semantic evidence exists.

## Immutable preflight and routing

TB-R4 consumed only CB4 package `9591540182`. Before runtime it verified package ZIP SHA-256, internal manifest **27/27 PASS**, semantic source `de291a17…`, `runtimeExecution=false`, clean source-status records, embedded source archive SHA-256, and the unchanged frozen selectors:

- required selector: **338**, SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 328: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

Identity-to-binary routing was derived statically; no generated GTest discovery/listing command executed.

## Frozen 338 gate

Every required identity ran in its own fresh process and in exact frozen order. F6 continue-and-observe remained enabled.

- Required / executed / passed: **338 / 338 / 338**
- Accepted predecessor prefix: **316/316 PASS**
- Prior CP4c-0 prefix: **328/328 PASS**
- Correction tail 329–338: **10/10 PASS**
- First required red: **none**
- Orchestration errors during semantic execution: **0**

Ordinal 333 `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` is **PASS**, proving G1's DCEL-valid witness reaches and satisfies the intended exact predicate. Ordinal 334 `ResolvedBranchCorrection.ExactVertexSectorPartitionsAcceptedInteriorFans` is **PASS** under G2's transported-branch oracle with G3 local-holonomy coverage. Identity 338 also remains green.

## F3 supplemental falsifiers

The two required supplemental falsifiers ran separately after the 338 gate, each in a fresh process:

1. `ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode` — **PASS**;
2. `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus` — **PASS**.

Result: **2/2 PASS**. The second identity now proves seed provenance on a constructed failure and no longer requires the live sphere to fail.

## G5 non-gating diagnostic

`ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating` ran in its own fresh process with `credit=none;owningMeasure=G5` and passed. Its actionable semantic datum is:

```text
networkError=BranchTransportFlowDisagreement
sourceEdge=6-8
sourceFace=6-8-9
relatedSourceFace=6-8-97
branch=3
relatedBranch=1
exactValues=[-18030322293639185/4503599627370496,704682678286465/140737488355328,-4519523411527695/4503599627370496,-7261349426533623/2251799813685248,8560629902387487/2251799813685248,-162410059481733/281474976710656]
traceSeedVertex=0
traceSeedSingularity=0
```

Static localization in the immutable packaged source is `src/geometry/SurfaceCellTracing.cpp:644-671`, `validate_field_branch_transport_flow`. The validator returns `BranchTransportFlowDisagreement` when the shared carrier is present in the source pairing's `outgoingCarriers` but absent from the transported target pairing's `incomingCarriers`. It records both published branch authorities and both exact barycentric direction triples. This localization does **not** adjudicate the sphere mismatch as a production defect; independent review must determine which authority or precondition is inconsistent at this edge.

## Binding Q8

All authorization preconditions were green, so Q8 is creditable. Against the frozen criteria:

1. accepted **316/316** green, zero expectation edits — **PASS**;
2. prescribed sphere reaches A2a and publishes a 24-trace network — **RED**: A2a rejects `BranchTransportFlowDisagreement` before a network exists;
3. terminal sphere `TraceIntersection` — not reachable/creditable after criterion 2 red;
4. face `1-2-5` crossover/exit flip — frozen correction identity remains green, but cannot rescue Q8 after criterion 2 red;
5. torus/mechanical unchanged — carried unchanged, not independently rerun after binding criterion 2 red.

Q8 result: **CREDITABLE / RED — `sphere_network_not_published`**. No repair is authorized inside TB-R4.

## Artifact-only integrity and postflight control failure

The semantic runtime used **341 fresh Directional processes**: 338 required identities + 2 F3 supplementals + 1 G5 diagnostic. It executed no configure, compile, relink, repair, generated discovery, or performance benchmark command.

The result artifact preserves pre/post SHA-256 inventories for the package, materialized source, fixtures, selector, and producer executable. All corresponding inventories compare byte-for-byte equal; the post-run package manifest records **27/27 PASS**. Therefore `packageMutation`, `sourceMutation`, `testMutation`, `fixtureMutation`, `selectorMutation`, `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`, and `performanceBenchmark` are all **false**.

After those comparisons completed, the reporting shell tested `$first_red` although persisted runtime state is named `first_red_ordinal`. Under `set -u` this produced `first_red: unbound variable`. The final convenience `result.json` was not written, but result/log artifacts still uploaded and contain sufficient semantic/integrity evidence. This is recorded separately as `M3-CP4c0-TB-R4-CAND-02`; no semantic rerun is authorized.

## Regression / candidate accounting

TB-R4 resolves the three TB-R3 non-stable test/diagnostic candidates and adds two non-stable TB-R4 records:

- `M3-CP4c0-TB-R4-CAND-01` — creditable Q8 sphere A2a rejection `BranchTransportFlowDisagreement` at edge `6-8`; **semantic candidate pending independent review**;
- `M3-CP4c0-TB-R4-CAND-02` — postflight summary variable mismatch after valid semantic/integrity evidence; **resolved orchestration candidate**, no rerun.

No accepted identity regressed: accepted prefix **316/316 PASS**, and CP4c-0 has never been accepted. Stable accounting therefore remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**; M3 package count remains **43**.

## Phase status / exact next

**`M3-CP4c-0-TB-R4` is COMPLETE / VALID SEMANTIC RED.** CP4c-0 remains OPEN and unaccepted; latest accepted runtime remains CP4ab **316/316**. Exact next is independent **`M3-CP4c-0-TB-R4-REVIEW-PLAN`**, review/planning only. That review must adjudicate the concrete G5 `BranchTransportFlowDisagreement` and Q8 criterion-2 failure before any corrective CB, product/test mutation, tolerance change, fixture edit, or semantic rerun is authorized.
