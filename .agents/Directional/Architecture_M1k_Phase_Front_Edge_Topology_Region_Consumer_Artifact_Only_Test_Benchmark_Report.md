# M1k Phase-Front Edge Topology-Region Consumer — Artifact-Only Test + Benchmark Report

**Turn type:** Test + Benchmark only  
**Status:** **IMMUTABLE ACCEPTED**  
**Review policy:** `never`  
**Implementation accepted:** `b9181364926cea840e9cb50da21fe721f33fd874`  
**Source parent:** `38d6fc4c4042c5a0d200abf4e5594dcf325b8383`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate  
**Date:** 2026-08-10 UTC

## 1. Acceptance decision

M1k is immutable accepted. The exact packaged implementation preserves checked edge-owned `TopologyRegionId` authority through the production path, keeps it distinct from component/sheet/chart integer domains, fails closed when edge region authority is missing or inconsistent, and preserves all entering accepted behavior.

Selected seam:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`

No production source, test logic, benchmark logic, validator, fixture, CMake, or immutable package content was edited during this Test + Benchmark turn. No configure, compile, relink, regeneration, package repair/substitution, or fixture symlink was used.

## 2. Immutable input authority

| Evidence | Value |
|---|---|
| Implementation | `b9181364926cea840e9cb50da21fe721f33fd874` |
| Build run/job | `31430898273 / 93593780187` |
| Result artifact | `9079318682` — `m1k-edge-topology-region-code-build-result-final` |
| Result ZIP SHA-256 | `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d` |
| Build-log artifact | `9079319269` — `m1k-edge-topology-region-code-build-logs-authoritative` |
| Build-log ZIP SHA-256 | `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381` |
| Recursive manifest | **68/68**, SHA-256 `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c` |
| Package | **69** regular files including manifest; 7 executables; 2 static libraries; 27 fixtures |
| Producer SHA-256 | `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1` |

Preflight from a fresh extraction verified safe archive paths, zero package symlinks, absence of `bin/test-data`, 21 milestone-G fixture files, exact build-authority metadata, exact source blob identities, all 68 recursive checksums, and all command-boundary flags false.

A first local extraction through Python `zipfile.extractall` did not preserve executable mode bits and produced rc=126. This was diagnosed before semantic execution and discarded as an extraction-method artifact. Fresh CLI `unzip` extraction preserved packaged executable modes naturally; no `chmod`, copied binary, symlink, or other package repair was used.

## 3. Authoritative remote execution evidence

Authoritative artifact-only validation run/job:

`31433794426 / 93603203081`

Artifacts:

- evidence `9080245848` — SHA-256 `986ba903c8727eb1f8049982e1ed38063d4458fa5e12aa53be835838e2910dda`;
- detailed logs `9080246452` — SHA-256 `6d44b14d239ce2b7bf2209d7ebb36d1cbcd49706a3e0c3d2a3279aecd75cf758`.

Both are retained for 14 days. The workflow downloaded the exact declared M1k build artifacts from GitHub Actions and executed them without configuring, compiling, relinking, regenerating, modifying, repairing, or substituting package content.

The immediately preceding remote run `31433441840 / 93602058525` completed the semantic execution step successfully but the workflow was red because its evidence-upload path pointed at `/tmp` while the validator used `$RUNNER_TEMP`. The dedicated logs artifact `9080118797` was retained. The corrected retry changed only execution-plane evidence retention, reran the same immutable package, and is the authoritative retained evidence above. This is infrastructure/orchestration provenance, not product evidence of a regression.

## 4. Native discovery authority

Exact packaged GoogleTest discovery:

| Target | Discovered |
|---|---:|
| producer | **220** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

All counts equal the declared acceptance authority.

## 5. M1k focused acceptance

Every M1k contract ran individually in a fresh process and selected exactly one test:

1. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.PlanarEdgesPublishCheckedTopologyRegionZero`
2. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.DistinctTopologyRegionsRemainDistinctFromIsolationSheets`
3. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.MissingOrInvalidEdgeTopologyRegionFailsClosed`
4. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.FaceRowPermutationPreservesTypedEdgeTopologyRegion`
5. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.CrossRegionOppositesRetainDistinctTypedRegionIdentity`
6. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.TypedEdgeTopologyRegionToLegacyPipelineBoundaryPreservesCompatibility`

Result: **6/6**.

This establishes that edge topology-region identity is checked semantic authority derived from region ownership, remains distinct from isolation-sheet identity despite numeric coincidence, is permutation-stable, remains distinct across legitimate cross-region relations, fails closed when missing/stale, and crosses still-raw pipeline boundaries only through explicit compatibility conversion.

## 6. Entering architecture/test preservation

All retained focused suites passed individually:

- M1j **6/6**;
- M1i **6/6**;
- M1h **6/6**;
- M1g **6/6**;
- M1f **6/6**;
- M1e **6/6**;
- M1d **6/6**;
- M1c **6/6**;
- M1b **6/6** from the validation executable.

Counterexample preservation:

- M1d route witnesses **3/3**;
- M1c transition counterexamples **3/3**.

Independent targets:

- validation **77/77**;
- M1a **14/14**;
- T1 independent oracle **29/29**.

## 7. Required-green producer segment

Producer discovery was exactly **220**. Exactly 15 separately classified tests were excluded: four direct products, eight historical/deferred reds, strict-validator timing, BunnyRandom, and Vase.

Required-green result: **205/205**, rc=0.

- wall time: **22.52 s**;
- peak RSS: **22,808 KiB**.

No failure was retried or relabeled to obtain this result.

## 8. Direct representative products

Each direct product ran individually from the exact package with no fixture symlink or runtime repair and passed its independent product oracle:

| Product | Result | Wall | Peak RSS |
|---|---|---:|---:|
| Plane | pass | 1.37 s | 10,844 KiB |
| MultiFaceSeam | pass | 2.16 s | 10,744 KiB |
| CloseSheets | pass | 17.35 s | 12,948 KiB |
| Cylinder | pass | 9.51 s | 14,228 KiB |

During an earlier local aggregate harness, the first Cylinder invocation reached `[ RUN ]` but did not complete before that aggregate harness's outer timeout. Immediate bounded execution of the same exact extracted binary passed in 6.65 s, the first remote semantic run passed in 9.07 s, and the authoritative retained remote run passed in 9.51 s. The isolated local stall therefore did not reproduce in three subsequent fresh exact-artifact executions and is classified as a local execution-plane/harness anomaly, not a stable product regression. No retry was used to replace a red semantic assertion; all authoritative direct-product evidence comes from fresh process executions.

## 9. Historical/deferred red preservation

All eight entering red cases retained their established class:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red.
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`.
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`.
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`.
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`.
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`.
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red.
8. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

No historical failure-class drift occurred. Nonzero periodic whole-cycle rotation remains outside M1k and `G4-B003` remains unresolved.

## 10. Strict-validator timing characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` ran in **10 independent fresh processes**.

Result: **10/10 pass** in the authoritative run. Every process completed within the timer's `0:00.00` display resolution with peak RSS between approximately 8.2 and 8.9 MiB.

Successful GoogleTest executions do not print the internal validation/reference timing operands, so fresh operand pairs are unavailable for these green samples. Entering M1j was **0/10**, while earlier accepted turns have also shown mixed results. The gate therefore remains classified as the existing nondeterministic sub-millisecond ratio/microbenchmark defect; this 10/10 sample does **not** establish that the timing test is repaired, and no threshold/retry workaround is authorized.

## 11. Bunny and Vase bounded comparison

### BunnyRandom

Exact parameterized test:

`UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom`

Result:

- rc=1;
- wall **57.81 s**;
- peak RSS **342,500 KiB**;
- independent oracle rejects first with empty/non-quad/component/Euler/output-origin/terminal-failure findings;
- product failure then remains exactly:
  `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

This matches entering M1j product disposition.

### Vase

Exact parameterized test:

`UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`

The test reached `[ RUN ]` and was bounded at **60.00 s**, rc=124, peak RSS **71,416 KiB**. This is safety-only evidence; no correctness or nontermination conclusion is inferred from the timeout.

## 12. Exact postflight

Authoritative postflight preserved:

- result ZIP SHA-256 `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d`;
- build-log ZIP SHA-256 `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381`;
- manifest SHA-256 `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c`;
- **68/68** content checksums;
- 69 regular files, 7 executables, 2 libraries, 27 fixtures;
- producer SHA-256 `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1`;
- zero package symlinks and `fixtureSymlink=false`.

No package mutation occurred.

## 13. Regression and product-gate disposition

M1k creates no stable product regression event or recurrence. Historical PR-wide totals remain:

- **34 regression events**;
- **14 categories**;
- **20 recurrences**.

The Python extraction-mode issue, one non-reproducing local Cylinder stall, and the first remote evidence-upload path failure are execution-plane/infrastructure observations, not previously accepted product behavior losses.

`PR8-R034 / G4-R007` remains active. G4 remains unchanged. M1k accepts one authority-migration slice only; it does not claim production completion, nonzero periodic holonomy support, Bunny/Vase production success, or repair of the strict-validator microbenchmark.

Architecture authority is now **M1a through M1k immutable accepted**.

## 14. Accepted-source inspection and next bounded consumer

Only after M1k acceptance, the exact accepted source was inspected to select the next bounded consumer.

`SurfaceFrontEdge::sourceTopologyRegion` is now typed, but `SurfacePhaseFrontCell::sourceTopologyRegion` remains a raw `int`. In `normalize_scope`, the authoritative `SurfaceTopologyRegion::id` is copied into the raw cell field, then separately converted to `TopologyRegionId` for edges. The materializer consequently converts typed edge authority back to legacy form to compare it with raw cell authority, and multiple raw cell consumers still use the same integer as map key, connectivity input, occurrence compatibility value, and structural-hash input.

The next smallest M1 consumer is therefore **M1l Phase-Front Cell Topology-Region Consumer**:

`SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`

M1l migrates only cell-owned topology-region identity to checked `TopologyRegionId`, makes cell/edge region agreement a typed semantic comparison, and keeps region discovery/numbering, `SurfaceTopologyRegion::id`, `sourceTopologyRegionByFace`, certificate/periodic/bounded-disk schemas, occurrence compatibility storage, M2-M6, and G4 behavior out of scope.

## 15. Mandatory next turn

Review is skipped (`never`), so the authoritative next turn is:

**M1l Phase-Front Cell Topology-Region Consumer — Code + Build only**

Plan:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`

The following Code + Build turn must not execute generated Directional binaries, GoogleTest discovery/list commands, tests, benchmarks, `ctest`, CLI/GUI/help/version commands, fuzzers, or custom inputs.
