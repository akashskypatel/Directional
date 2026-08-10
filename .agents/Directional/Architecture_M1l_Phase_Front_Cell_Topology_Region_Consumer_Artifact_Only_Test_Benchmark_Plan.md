# M1l Phase-Front Cell Topology-Region Consumer — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Implementation under test:** `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Immutable input authority

Consume only the exact M1l Code + Build artifacts produced by run/job `31441661026 / 93627457924`:

| Evidence | Required identity |
|---|---|
| result artifact | `9083262395` — `m1l-cell-topology-region-code-build-result-final` |
| result ZIP SHA-256 | `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c` |
| log artifact | `9083262833` — `m1l-cell-topology-region-code-build-logs-authoritative-r3` |
| log ZIP SHA-256 | `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8` |
| implementation | `bd140cff4572412e6f4ecd70a6ce0fe85310932c` |
| semantic source base | `d5a97953416196a8fc74c8d9790a1ae7b646ca2d` |
| recursive manifest | **56/56**, `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454` |
| package regular files | **57** including `SHA256SUMS` |
| packaged executables / libraries | **7 / 2** |
| fixtures / milestone-G fixtures | **27 / 21** |
| producer SHA-256 | `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856` |

The Test + Benchmark turn must not rebuild, relink, configure, regenerate, edit source/tests/fixtures/build logic, substitute package content, repair archive contents, alter executable permissions, or create fixture symlinks. Extract the artifact naturally with CLI `unzip`; do not use `chmod` or any equivalent package repair.

## 2. Preflight integrity gate

Before runtime:

1. download exactly artifacts `9083262395 / 9083262833`;
2. verify both outer ZIP SHA-256 values exactly;
3. reject absolute paths, `..` traversal, unsafe archive members, or unexpected link members;
4. extract without mutating archive semantics;
5. verify `SHA256SUMS` digest `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454` and all **56/56** entries;
6. verify exactly **57** regular files, seven executables, two static libraries, 27 fixtures, and 21 milestone-G fixtures;
7. verify package link/symlink state directly and record it rather than assuming it;
8. verify producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`;
9. verify `metadata/build-authority.json` identifies implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`, semantic source base `d5a97953416196a8fc74c8d9790a1ae7b646ca2d`, run `31441661026`, Release/static/Ninja/PRE_TEST, and every Code + Build runtime flag false;
10. verify the packaged semantic patch/source blobs and exact focused/direct/red/deferred test-name manifests before executing anything.

Any package identity or integrity mismatch blocks semantic execution.

## 3. Native discovery authority

Using only the packaged binaries, perform native GoogleTest discovery and require exact counts:

- producer: **226**;
- validation: **77**;
- M1a authority kernel: **14**;
- T1 independent product oracle: **29**.

Zero-selected or unexpected test discovery is an orchestration failure, not a pass.

## 4. M1l focused semantic acceptance

Run each packaged `SurfaceCellPhaseFrontCellTopologyRegionAuthorityMigration` contract individually in a fresh process and require exact one-test selection and pass:

1. `PlanarCellPublishesCheckedTopologyRegionZero`
2. `DistinctCellTopologyRegionsRemainDistinctFromIsolationSheets`
3. `MissingOrInvalidCellTopologyRegionFailsClosed`
4. `FaceRowPermutationPreservesTypedCellTopologyRegion`
5. `TypedCellAndEdgeTopologyRegionAuthorityAgreeSemantically`
6. `TypedCellTopologyRegionToLegacyMaterializerBoundaryPreservesCompatibility`

Required result: **6/6**.

These contracts must prove the production-path semantics; do not reinterpret a failing witness, weaken an expectation, or substitute an adapter-only test in this artifact-only turn.

## 5. Entering architecture preservation

Run the retained focused suites individually and require all entering M1 authority to remain green:

- M1k **6/6**;
- M1j **6/6**;
- M1i **6/6**;
- M1h **6/6**;
- M1g **6/6**;
- M1f **6/6**;
- M1e **6/6**;
- M1d **6/6**;
- M1c **6/6**;
- M1b **6/6**, using the validation executable that owns those names.

Also preserve:

- M1d route counterexamples **3/3**;
- M1c transition counterexamples **3/3**.

Any regression blocks M1l acceptance.

## 6. Complete required-green producer segment

Producer discovery is expected to be **226**. Exclude exactly the same 15 separately classified cases used by entering authority:

- four direct representative products;
- eight historical/deferred reds;
- strict-validator timing;
- BunnyRandom;
- Vase.

Expected aggregate required-green selection:

`226 - 15 = 211`.

Require **211/211**. Focused M1l success alone is insufficient.

## 7. Independent preservation targets

Require exact packaged-target passes:

- validation **77/77**;
- M1a authority kernel **14/14**;
- T1 independent oracle **29/29**.

## 8. Direct representative product preservation

Run each exact direct product individually from the immutable package:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

Each must select exactly one intended case, complete through the public production path, and remain independent-oracle clean with no fallback/recovery substitution and no fixture repair/symlink.

A representative-product regression blocks M1l acceptance even if all focused contracts pass.

## 9. Historical/deferred red preservation

Run the eight packaged historical/deferred red cases individually and preserve their entering failure classes:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red;
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`;
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`;
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`;
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`;
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`;
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red;
8. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

Persistence is not a new regression. Failure-class drift must be investigated and reported; do not relabel known reds green or expected-failure to complete M1l.

## 10. Strict-validator timing characterization

Run `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` in **10 independent fresh processes**. Record all outcomes truthfully.

This remains a known nondeterministic sub-millisecond ratio/microbenchmark defect. Do not retry individual failures to manufacture a pass, weaken the threshold, or claim the defect repaired from one favorable sample.

## 11. Bunny/Vase bounded comparison

Only after all mandatory semantic/preservation/product gates above are complete:

### BunnyRandom

Run the exact packaged BunnyRandom direct-product case in a fresh process and preserve independent-oracle ordering. Entering M1k disposition is:

`NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

A changed failure class/signature must be reported rather than normalized away.

### Vase

Run the exact packaged Vase case under the established **60-second** bound. Reaching `[ RUN ]` and timing out remains safety-only evidence; it is neither correctness proof nor proof of nontermination.

Use artifact-only remote execution if needed for these heavier cases, with exact preflight and postflight around the same package.

## 12. Postflight immutability

After all runtime work, reverify:

- both original outer artifact ZIP hashes;
- recursive manifest digest and all **56/56** package checksums;
- package cardinalities, executable/library/fixture counts, and recorded link state;
- producer SHA-256;
- implementation/build authority metadata.

No runtime action may mutate packaged contents.

## 13. Acceptance and stop conditions

M1l becomes immutable accepted only if:

1. preflight identity is exact;
2. discovery is exactly `226 / 77 / 14 / 29`;
3. M1l is **6/6**;
4. all M1k–M1b focused preservation and M1d/M1c counterexamples pass;
5. required-green is **211/211**;
6. validation/M1a/T1 are **77/77 / 14/14 / 29/29**;
7. Plane/MultiFaceSeam/CloseSheets/Cylinder remain independent-oracle clean;
8. all eight historical/deferred red classes are preserved or any drift is explicitly classified;
9. strict timing is characterized honestly without workaround;
10. Bunny/Vase bounded comparison preserves or truthfully reports product disposition;
11. exact immutable postflight succeeds;
12. no source/test/build/fixture/package content is changed.

If any mandatory green or representative product gate regresses, stop at M1l, classify the failure using `Regression_Root_Cause_Tracker.md`, and do not select another M1 consumer.

A successful artifact-only turn must write the current immutable report, update durable status/changelog/TODO/handoff as required, clean superseded repository-side evidence under `CLEAN_UP_POLICY.md`, and then select the next bounded action from accepted source only after M1l is semantically accepted.
