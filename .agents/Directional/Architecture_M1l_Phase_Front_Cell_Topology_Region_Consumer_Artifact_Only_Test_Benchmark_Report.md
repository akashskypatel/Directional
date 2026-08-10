# M1l Phase-Front Cell Topology-Region Consumer — Artifact-Only Test + Benchmark Report

**Status:** immutable accepted  
**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Implementation under test:** `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Immutable input authority

This turn consumed only the exact M1l Code + Build package from run/job `31441661026 / 93627457924`:

| Evidence | Identity |
|---|---|
| result artifact | `9083262395` — `m1l-cell-topology-region-code-build-result-final` |
| result ZIP SHA-256 | `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c` |
| build-log artifact | `9083262833` — `m1l-cell-topology-region-code-build-logs-authoritative-r3` |
| build-log ZIP SHA-256 | `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8` |
| implementation | `bd140cff4572412e6f4ecd70a6ce0fe85310932c` |
| semantic source base | `d5a97953416196a8fc74c8d9790a1ae7b646ca2d` |
| recursive manifest | **56/56**, SHA-256 `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454` |
| package | 57 regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures; 21 milestone-G fixtures; 0 symlinks |
| producer SHA-256 | `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856` |

Preflight rejected archive traversal/link hazards, used natural CLI `unzip` extraction, verified both outer artifact digests, all **56/56** recursive checksums, package cardinalities, producer digest, build-authority metadata, source archive/blobs, semantic patch path closure, fixture closure, and focused/direct/red/deferred test-name manifests. No package repair, permission mutation, fixture symlink, configure, compile, relink, regeneration, source/test/build edit, or replacement artifact occurred.

## 2. Authoritative runtime execution

The authoritative immutable runtime was GitHub Actions run/job:

`31444022339 / 93634344918`

The workflow downloaded the exact Code + Build artifacts by ID and repeated the full preflight before executing packaged binaries. Runtime evidence was retained as:

| Evidence | Identity |
|---|---|
| runtime evidence artifact | `9083913766` — `m1l-cell-topology-region-artifact-only-evidence` |
| runtime evidence ZIP SHA-256 | `64ad28a3334dd3e73346a221e619873dbbc523e879cb31dda0843caa0214cccd` |
| runtime log artifact | `9083913939` — `m1l-cell-topology-region-artifact-only-logs` |
| runtime log ZIP SHA-256 | `a4f9188b19fb9d21d6f7af39b54f9409cb7c3109669d3fddb0fb62fc999ea917` |
| retention expiry | 2026-08-24 UTC |

The workflow event/control-plane commit was `0d4b6f52e37261453b83ba72cc1ad1e8517399ef`; it contains only temporary orchestration state and is not the implementation/evidence source commit.

## 3. Native discovery authority

Native packaged GoogleTest discovery was exact:

- producer: **226**;
- validation: **77**;
- M1a authority kernel: **14**;
- T1 independent oracle: **29**.

No zero-selected filter or generated discovery substitution was accepted.

## 4. M1l focused semantic acceptance

Each `SurfaceCellPhaseFrontCellTopologyRegionAuthorityMigration` contract ran alone in a fresh process and selected exactly one test:

1. `PlanarCellPublishesCheckedTopologyRegionZero` — pass;
2. `DistinctCellTopologyRegionsRemainDistinctFromIsolationSheets` — pass;
3. `MissingOrInvalidCellTopologyRegionFailsClosed` — pass;
4. `FaceRowPermutationPreservesTypedCellTopologyRegion` — pass;
5. `TypedCellAndEdgeTopologyRegionAuthorityAgreeSemantically` — pass;
6. `TypedCellTopologyRegionToLegacyMaterializerBoundaryPreservesCompatibility` — pass.

Required result: **6/6**. Actual result: **6/6**.

M1l therefore establishes checked cell-owned `TopologyRegionId` authority through the selected production seam without making raw cell region identity authoritative again.

## 5. Entering architecture preservation

All entering focused authority remained green:

- M1k **6/6**;
- M1j **6/6**;
- M1i **6/6**;
- M1h **6/6**;
- M1g **6/6**;
- M1f **6/6**;
- M1e **6/6**;
- M1d **6/6**;
- M1c **6/6**;
- M1b **6/6** in the validation executable;
- M1d route counterexamples **3/3**;
- M1c transition counterexamples **3/3**.

The complete required-green producer segment passed **211/211**.

Independent packaged targets also passed:

- validation **77/77**;
- M1a **14/14**;
- T1 **29/29**.

## 6. Representative direct-product preservation

Each direct representative product selected exactly one packaged case and completed through the production path with the independent oracle clean:

| Case | Result | Remote elapsed |
|---|---|---:|
| Plane | pass | 1.35 s |
| MultiFaceSeam | pass | 2.03 s |
| CloseSheets | pass | 16.36 s |
| Cylinder | pass | 8.82 s |

No fallback/recovery substitution, fixture repair, or fixture symlink was used.

A prior local first-process Cylinder stall during corroborating execution did not reproduce in the immediate bounded local retry or in this authoritative remote run. It remains an execution-plane/harness transient, not product evidence, and no workaround was introduced.

## 7. Historical/deferred red preservation

All eight separately classified historical/deferred reds retained their entering classes:

1. `MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red;
2. `FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`;
3. `TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`;
4. `MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`;
5. `SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`;
6. `MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`;
7. `QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red;
8. `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

Persistence of these known reds is not a new regression or recurrence.

## 8. Strict-validator characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` was executed in exactly **10 independent fresh processes**. This sample was **10/10 pass**.

The classification is unchanged: this remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect because accepted historical samples vary materially. No retry, threshold change, test edit, or workaround was used, and this favorable sample is not claimed as a repair.

## 9. Bunny/Vase bounded comparison

### BunnyRandom

The exact packaged BunnyRandom case selected one test and failed with the independent oracle before the public success assertion. The entering product signature was preserved exactly:

`NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`

Remote elapsed time was **78.06 s**, peak RSS **343,068 KiB**, exit code 1. This turn does not treat cross-runner timing differences as a performance regression.

### Vase

The exact packaged Vase case selected one test, reached `[ RUN ]`, and hit the established **60-second** bound with exit code 124. Peak RSS was **67,508 KiB**. This remains safety-only evidence and is neither correctness proof nor proof of nontermination.

## 10. Postflight immutability

After all runtime execution, the authoritative workflow reverified:

- both original Code + Build outer ZIP digests;
- recursive manifest digest and all **56/56** package checksums;
- 57 regular files, 7 executables, 2 static libraries, 27 fixtures, 21 milestone-G fixtures;
- zero package symlinks;
- producer SHA-256;
- exact build-authority metadata.

No packaged content changed during runtime.

## 11. Regression and product disposition

M1l is **immutable accepted**.

No stable product regression event or recurrence is created. Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active. G4 product behavior is unchanged, and M1l architecture acceptance does not claim G4 completion.

## 12. Next bounded architecture consumer

Accepted-source inspection selects the next bounded M1 consumer at:

`SurfaceTopologyRegion::id / build_isolation_seam_transport_certificates -> SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion -> still-raw materializer/hash compatibility consumers`.

The next turn is **M1m Isolation-Seam Certificate Topology-Region Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`.

M1m must migrate only certificate-owned topology-region identity to checked `TopologyRegionId`, preserve global topology-region construction and all other raw compatibility schemas, add six production-path compile contracts, and execute no generated Directional binary, discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.
