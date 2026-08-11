# M1 Single-Authority Cutover — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Validated source to consume:** `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e`  
**Entering immutable comparison authority:** M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Code + Build result artifact:** `9105462679` — `m1-single-authority-cutover-code-build-result-31501276992`  
**Code + Build result artifact digest:** `sha256:f73f6e02ff7cb3254dce46694af460d3703c7869985bcb69648eb528db9c6ad2`  
**Code + Build log artifact:** `9105463175` — `m1-single-authority-cutover-code-build-log-31501276992`  
**Review policy:** `never`  
**Product gate after M1 acceptance:** G4 topology-distinct completion and singularities

## 1. Purpose and turn boundary

Validate the exact immutable package produced by the final M1 Code + Build turn. This turn decides whether the single-authority cutover preserves the required semantic/product invariants strongly enough to close M1.

This is an **artifact-only** turn. Do not configure, compile, relink, regenerate code or discovery, patch packaged source, modify packaged fixtures/manifests, or edit implementation/test/benchmark/validator/build logic. If the package is invalid, report an infrastructure/package failure; do not rebuild it in this turn.

Runtime execution is allowed only from the immutable packaged executables and packaged inputs after preflight authority succeeds.

## 2. Immutable package authority

Expected package facts from the Code + Build report:

- implementation commit: `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e`;
- immediate source parent: `1cb115500c629610d5ad7b2d73c58029beb94a7c`;
- entering accepted M1l source: `bd140cff4572412e6f4ecd70a6ce0fe85310932c`;
- recursive manifest entries: **57**;
- recursive manifest SHA-256: `ebd5f1587feec0120260eacd127f45fcf66784f5effaf1a60703e7471f9454b4`;
- fixture file count: **27**;
- seven packaged test/benchmark executables and two static libraries;
- all Code + Build command-boundary flags false.

Treat the package metadata and checksums as the source of truth. Stop before runtime if these facts do not close exactly.

## 3. Preflight — verify before any generated-binary execution

Extract the downloaded artifact into a fresh arbitrary directory using a method that preserves its natural executable mode bits. Do not `chmod`, repair, or mutate the package.

Verify, in order:

1. downloaded artifact identity/digest matches artifact `9105462679` and the recorded outer SHA-256;
2. `SHA256SUMS` exists, has exactly 57 entries, has the recorded manifest digest, and `sha256sum -c SHA256SUMS` passes **57/57**;
3. package contains no symlink or path escape and extraction did not rewrite packaged files;
4. `metadata/build-authority.json` names exact implementation `5b1c9b...`, immediate parent `1cb115...`, entering M1l `bd140c...`, Release/Ninja/PRE_TEST, and fixture count 27;
5. `metadata/command-boundary.txt` and JSON metadata record all of these as false: runtime, gtest-list, tests, benchmarks, ctest, CLI, fuzzer, custom input;
6. `metadata/source-cutover-audit.txt` records `static_cutover_audit=clean`;
7. `metadata/cutover-test-groups.txt` contains exactly the five required semantic contract groups listed below;
8. `metadata/cutover-test-source-locations.txt` contains at least one source location for each required group;
9. the source archive, M1l-to-cutover patch, changed-path manifest, changed-source-blob manifest, fixture manifest, configure/build logs, and toolchain/submodule logs exist;
10. record recursive package hash/state for immutable postflight comparison.

A preflight failure is not a product regression and does not authorize a rebuild.

## 4. Independent test discovery

Only after preflight, discover the actual GoogleTest inventory from the packaged executables. Do not use a predeclared producer or total-test count as acceptance authority.

Record for every executable:

- executable SHA-256;
- exact `--gtest_list_tests` output;
- discovered test count;
- selected test names for each gate below.

A zero-selected filter is an orchestration failure, never a semantic pass.

The required M1 cutover groups are:

```text
SurfaceCellAuthorityKernel
SurfaceCellAuthorityContractCutover
SurfaceCellIsolationSeamCertificateAuthority
SurfaceCellTypedTransportAuthority
SurfaceCellSourceSupportAndChartAuthority
```

Use the independently discovered exact names rather than assuming a fixed count.

## 5. Focused M1 cutover gates

Run every discovered test belonging to each required cutover group by exact name before aggregate execution. Each must pass independently.

Required semantic intent:

### `SurfaceCellAuthorityKernel`

- checked lower/upper valid construction boundaries;
- negative and extent rejection with typed errors;
- compile-time ID-domain separation represented by the compiled test contract;
- canonical source-edge/source-face topology-key behavior and degeneracy rejection.

### `SurfaceCellAuthorityContractCutover`

- one complete typed face-to-topology-region product;
- cell/edge/periodic/bounded-disk consumers reference the published region without conflicting component/sheet mirrors;
- source-face row permutation preserves semantic region/certificate identity;
- missing/unassigned authority fails before publication.

### `SurfaceCellIsolationSeamCertificateAuthority`

- valid reciprocal multi-sheet certificate materializes;
- wrong owner/transition/face/sheet, duplicate key, and nonreciprocal transport fail in the intended typed categories;
- exact-once certificate consumption remains observable.

### `SurfaceCellTypedTransportAuthority`

- segment, hard-rail, source-boundary, and periodic routes preserve typed step variants;
- reversal/inversion preserves canonical route identity;
- swapped topology/transition and invented boundary-transition inputs reject;
- unsupported nonzero Z4 remains truthfully unsupported unless the existing production algorithm already supported it.

### `SurfaceCellSourceSupportAndChartAuthority`

- vertex/edge/face-interior support remain distinct typed variants;
- close sheets and separate orientation charts remain distinct;
- source-row permutation preserves semantic identity;
- ambiguous/malformed support fails typed.

Do not reinterpret representation-only differences as semantic failures when the asserted product invariant is preserved.

## 6. Entering semantic-preservation gates

After the new focused groups pass, execute the adapted entering authority/contract coverage and record exact discovered names/counts rather than importing historical totals.

At minimum include:

- all surviving M1a–M1l semantic authority groups;
- M1d route counterexamples;
- M1c transition counterexamples;
- T1 independent oracle/package foundation tests;
- source-authoritative validation executable;
- completion executable coverage required by the M1 contracts;
- compiled API coverage;
- the required-green producer set, excluding only tests explicitly classified as historical/deferred red or characterization-only by the retained project records.

Compare failures against the accepted M1l semantics, not against raw field layout, numeric ID values, source row numbering, structural hashes, or intermediate counts.

## 7. Direct product oracle gates

Run these direct `SurfaceCells` production fixtures using the packaged independent product oracle and the same direct/no-fallback semantics used by entering accepted authority:

```text
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Plane
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/MultiFaceSeam
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/CloseSheets
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder
```

Required classification:

- source attachment must remain correct;
- topology-region/sheet/chart separation must remain correct;
- transport/certificate ownership and exact-once consumption must remain correct;
- direct disposition and no-fallback behavior must remain truthful;
- determinism must remain intact.

A changed raw numbering, row order, diagnostic digest, or intermediate count is not by itself a regression.

## 8. Historical/deferred red classification

Execute and report the known historical/deferred red cases rather than hiding or excluding them from evidence:

```text
SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets
SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize
SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected
SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner
SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected
SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected
SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority
SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary
```

For each, classify current behavior as one of:

- unchanged historical product limitation;
- intentional representation change with preserved semantics;
- earlier truthful typed rejection required by the new contract;
- genuine product progress;
- required-invariant regression;
- unexplained semantic drift.

Do not force the pre-cutover result if the new source model correctly rejects a previously reconstructible but invalid state.

## 9. Strict-validator characterization

The accepted M1l record identifies the sub-millisecond strict-validator ratio gate as nondeterministic. Characterize it in fresh processes without threshold/retry workarounds.

Record individual samples, denominator/numerator timing, pass/fail distribution, and whether any observed change is plausibly attributable to the authority cutover. Do not use this microbenchmark alone to reject M1 when correctness is otherwise preserved unless a stable reproducible regression is established.

## 10. Bounded Bunny/Vase characterization

Run bounded representative characterization using the packaged fixtures and existing direct-product test configuration:

- BunnyRandom: capture disposition, terminal stage/reason, trace/arrangement/completion counts, elapsed time, peak RSS, and deterministic semantic hashes available from the packaged diagnostics;
- Vase: retain the existing bounded safety timeout policy and record whether it terminates, times out safely, or changes failure class.

These are characterization/product-progress evidence. M1 acceptance does not require G6 success, but any new required-invariant regression or unexplained semantic drift blocks acceptance.

## 11. Static source audit from the packaged source

Without rebuilding, extract the packaged source archive into a separate analysis directory and independently repeat the source-only cutover audit over the packaged source.

Require zero production/test-scope references to:

```text
LegacyAuthorityAdapters
to_legacy_index
legacy_phase_front_
transitionSourceEdge
transitionSourceEdges
transitionSourceTopology
sourceRouteEdges
sourceRouteTopology
sourceTopologyRegionByFace
struct SourceChartId
struct SurfaceCellSourceChart
NegativeLegacyValue
OutOfRangeLegacyValue
legacyValue
```

Also inspect the affected authority structs for a typed ID/value stored beside a numeric mirror of the same semantic fact. A remaining duplicate semantic authority is an M1 failure, not follow-up work.

## 12. Immutable postflight

After all runtime execution:

1. recompute every packaged checksum and require the same **57/57** result;
2. recompute the manifest digest and require `ebd5f1587feec0120260eacd127f45fcf66784f5effaf1a60703e7471f9454b4`;
3. verify no package file was added, removed, rewritten, chmod-repaired, or symlinked;
4. verify executable hashes equal preflight values;
5. preserve raw discovery, focused, aggregate, product-oracle, characterization, resource, source-audit, and postflight logs as immutable evidence.

## 13. Acceptance decision

M1 is accepted only when all of the following hold:

- immutable preflight and postflight close exactly;
- all five new semantic cutover groups pass completely;
- all entering required-green semantic authority, validation, T1, and compiled-API gates pass;
- Plane, MultiFaceSeam, CloseSheets, and Cylinder have no required-invariant regression under the independent product oracle;
- every historical/deferred red case is executed and classified, with no unclassified regression;
- no source attachment, topology-region/sheet/chart distinction, transport composition, certificate ownership/exact-once consumption, determinism, direct disposition, or no-fallback invariant regresses;
- independent packaged-source audit finds no displaced representation or duplicate semantic authority;
- Bunny/Vase and strict-validator results are truthfully characterized;
- no package mutation or rebuild occurred.

If accepted, close **M1 single-authority cutover** in `TODO.md` and `CHANGELOG.md`, retain the new immutable Test + Benchmark report, and return the primary queue directly to **G4 topology-distinct completion and singularities**. Do not open another M1 letter slice.

If rejected, produce one bounded Code + Build plan addressing only proven semantic/source-authority defects. Do not restore a deleted adapter/raw mirror merely to reproduce old representation.

## 14. Required end-of-turn records

The Test + Benchmark turn must produce:

- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Report.md` with exact run/job/artifact/log identities and discovered counts;
- an updated `TODO.md`, `CHANGELOG.md`, regression tracker when a stable regression event actually exists, and live handoff;
- exactly one authoritative next Code + Build plan. On acceptance that plan must target the highest-prerequisite active **G4** blocker supported by the runtime evidence;
- repository-side stale per-turn cleanup under `CLEAN_UP_POLICY.md` and workflow/trigger/payload cleanup under `GitHub_Workflow_Policy.md`;
- a final summarized PR #8 conversation comment as the last repository write.

PR #8 remains open, draft, and unmerged throughout this validation turn.