# M1j Phase-Front Edge Source-Scope Consumer — Artifact-Only Test + Benchmark Report

**Turn type:** Test + Benchmark only  
**Status:** **IMMUTABLE ACCEPTED**  
**Review policy:** `never`  
**Implementation accepted:** `d5f681173600dc32dc7617de6105d9e584e593be`  
**Source parent:** `391271e253557b5c6b267befb3f2f33330c090c9`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate  
**Date:** 2026-08-10 UTC

## 1. Acceptance decision

M1j is immutable accepted. The exact packaged implementation preserves checked edge-owned source-component and isolation-sheet authority through the production path without changing entering accepted product behavior or reconstructing edge authority from consumer-side integer coincidences.

Selected seam:

`SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`

The accepted implementation keeps `SurfaceFrontEdge::sourceTopologyRegion` raw and outside M1j. No source, test, benchmark, validator, fixture, CMake, package, or manifest content was edited during this Test + Benchmark turn; no configure, compile, relink, regeneration, package repair/substitution, or runtime fixture symlink was used.

## 2. Immutable input authority

| Evidence | Value |
|---|---|
| Build run/job | `31422691741 / 93566993166` |
| Result artifact | `9076217893` — `m1j-edge-source-scope-code-build-result-final` |
| Result ZIP SHA-256 | `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c` |
| Log artifact | `9076218338` — `m1j-edge-source-scope-code-build-logs-authoritative` |
| Log ZIP SHA-256 | `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9` |
| Recursive manifest | **67/67**, SHA-256 `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59` |
| Package cardinality | **68** regular files including manifest; 7 executables; 2 static libraries; 27 fixtures |
| Producer SHA-256 | `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40` |

Preflight from arbitrary extraction verified safe archive paths, the exact build-authority metadata, all 67 manifest entries, cardinalities, zero package symlinks, absence of `bin/test-data`, exact producer hash, and exact packaged source blobs. The package naturally resolved sibling `../test-data`; no fixture-path substitute was created.

The earlier artifact `9075863759` remains compile provenance only and was not used for semantic runtime because its manifest preceded a final log copy.

## 3. Native discovery authority

Exact packaged GoogleTest discovery:

| Target | Discovered |
|---|---:|
| producer | **214** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

All counts equal the declared acceptance authority.

## 4. M1j focused acceptance

Each M1j contract ran in its own fresh process and selected exactly one test:

1. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.PlanarEdgesPublishCheckedDefaultComponentAndSheet`
2. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.ExplicitSourceLabelsRemainDistinctTypedEdgeDomains`
3. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.MultipleObservedSheetsDoNotInventRepresentativeEdgeSheet`
4. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.MalformedOrMismatchedEdgeScopeFailsClosed`
5. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.FaceRowPermutationPreservesTypedEdgeSourceScope`
6. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.TypedEdgeToLegacyPipelineBoundaryPreservesCompatibility`

Result: **6/6**.

This establishes the intended semantic invariants: component and isolation-sheet domains remain distinct typed authority; multi-sheet edges preserve the complete sheet set without inventing a single-sheet representative; malformed/mismatched authority fails closed; face-row permutation does not change semantic scope; and still-raw pipeline boundaries preserve compatibility through explicit conversion.

## 5. Entering architecture/test preservation

All retained focused suites passed individually:

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

## 6. Required-green producer segment

From producer discovery **214**, exactly 15 separately classified tests were excluded: four direct products, eight historical/deferred reds, strict-validator timing, BunnyRandom, and Vase.

The aggregate GoogleTest filter used exactly one positive/negative separator and selected exactly **199** tests.

Result: **199/199**, rc=0. Remote evidence wall time was **21.95 s**, peak RSS **22,648 KiB**. No failure was retried or relabeled.

## 7. Direct representative products

Each product ran individually from an arbitrary working directory with no fixture symlink and passed its independent product oracle:

| Product | Result | Wall | Peak RSS |
|---|---|---:|---:|
| Plane | pass | 1.34 s | 10,544 KiB |
| MultiFaceSeam | pass | 2.09 s | 10,700 KiB |
| CloseSheets | pass | 16.85 s | 13,152 KiB |
| Cylinder | pass | 8.91 s | 14,376 KiB |

The product path therefore remains independently oracle-clean after the edge source-scope migration.

## 8. Historical/deferred red preservation

All eight entering red cases retained their existing class:

1. `MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red.
2. `FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`.
3. `TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`.
4. `MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`.
5. `SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`.
6. `MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`.
7. `QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red.
8. `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

There is no historical failure-class drift. Nonzero periodic whole-cycle rotation remains `PeriodicHolonomyMismatch`; `G4-B003` remains unresolved. Persistence of these known reds is not a new regression.

## 9. Strict-validator timing characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` ran in 10 fresh processes with no retry-based greening. Result: **0/10 pass, 10/10 fail**.

Remote validation / threshold pairs:

1. `0.000170038 / 0.00011822215`
2. `0.000170960 / 0.00011941385`
3. `0.000200105 / 0.00011667725`
4. `0.000174326 / 0.00011936225`
5. `0.000169537 / 0.00011807185`
6. `0.000167614 / 0.00011866545`
7. `0.000210063 / 0.00011445205`
8. `0.000170640 / 0.00011652195`
9. `0.000172412 / 0.00012144015`
10. `0.000173985 / 0.00012350255`

This remains the existing deferred sub-millisecond ratio/microbenchmark defect. M1j does not change its classification and no threshold/retry workaround is authorized.

## 10. Remote artifact-only evidence

A temporary no-build validation workflow downloaded and verified the exact declared package directly from GitHub Actions, then repeated the semantic gates and postflight without checking out or modifying source.

Validation run/job: `31425748772 / 93576908519`.

- evidence artifact `9077128237`, SHA-256 `f61559e32b1d3cd8f1fa4f50867291c310aabec7b2a30d5415777b86b8af5b96`;
- dedicated logs artifact `9077129029`, SHA-256 `b600209fe10737bdbc6e3a07651c8b91fe036f94286b8a3f2e847320784441fd`.

This remote execution reproduced discovery 214/77/14/29, M1j **6/6**, M1i-M1b preservation, counterexamples **3/3 + 3/3**, required-green **199/199**, validation/M1a/T1 **77/77 / 14/14 / 29/29**, four direct products green, all eight entering red classes unchanged, and strict timing **0/10**.

## 11. Bunny and Vase bounded comparison

Heavy artifact-only run: `31425364955`. Each job downloaded artifact `9076217893` directly, verified the exact ZIP/manifest/cardinality/producer authority before runtime, used no configure/build/relink/regeneration/repair/symlink, and repeated exact postflight afterward.

### BunnyRandom

Job `93575663004`:

- exact BunnyRandom case;
- rc=1 after **1:11.58**, peak RSS **341,764 KiB**;
- independent oracle rejects first with empty/non-quad/component/Euler/output-origin/terminal-failure findings;
- product assertion remains unchanged:
  `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

Artifacts:

- evidence `9076993439`, SHA-256 `9a7fa508ed2b8d6f2d9c235895f7777536a92cc8e55da827f32b553a20ddb3e7`;
- logs `9076993713`, SHA-256 `cfbe4fcf32c844cfc0fc1d6ec31071294c4f8c5c7c03865ab668cc9f71a10a3e`.

### Vase

Job `93575662894`:

- exact Vase case reached `[ RUN ]`;
- bounded at **60.00 s**, rc=124, peak RSS **70,968 KiB**;
- safety-only evidence; no correctness or nontermination conclusion is drawn.

Artifacts:

- evidence `9076989920`, SHA-256 `5d0274626e722a976ca50a0be63d984a5aa68983788b14ce509b2778b50daa64`;
- logs `9076990491`, SHA-256 `1f387fd97632fe4f3d9ce437cc7ae9ce56148b2571a7536b6789ae960f85087d`.

## 12. Exact postflight

Local and remote postflight both preserved:

- result ZIP SHA-256 `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c`;
- log ZIP SHA-256 `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`;
- manifest SHA-256 `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`;
- **67/67** package content checksums;
- 68 regular files, 7 executables, 2 libraries, 27 fixtures;
- producer SHA-256 `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`;
- zero package symlinks and `fixtureSymlink=false`.

No package mutation occurred.

## 13. Regression and product-gate disposition

M1j creates no stable product regression event or recurrence. Historical PR-wide totals remain:

- **34 regression events**;
- **14 categories**;
- **20 recurrences**.

`PR8-R034 / G4-R007` remains active. G4 remains unchanged. M1j accepts an architecture migration slice only; it does not claim production completion, repair nonzero periodic holonomy, Bunny/Vase production success, or the strict-validator microbenchmark.

Architecture authority is now **M1a through M1j immutable accepted**.

## 14. Mandatory next turn

Review is skipped (`never`), so the next Code + Build plan is authoritative:

`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`

M1k is bounded to the explicitly deferred edge topology-region consumer:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`

Only edge-owned topology-region identity is migrated to checked `TopologyRegionId`; cell/region/periodic/bounded-disk/certificate topology-region schemas and topology-region construction/numbering remain out of scope. The following turn is **Code + Build only** and must execute no generated Directional binary, test discovery/listing, tests, benchmarks, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.
