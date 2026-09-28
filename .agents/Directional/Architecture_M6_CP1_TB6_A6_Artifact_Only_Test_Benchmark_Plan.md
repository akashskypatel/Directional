# M6-CP1-TB6-A6 — Artifact-Only Test + Benchmark Plan (frozen 460-process gate)

**Turn:** `M6-CP1-TB6-A6-EXEC`
**Type:** artifact-only runtime gate; no configure, compile, relink, repair or source mutation
**Predecessor:** `M6-CP1-CB6-A6` (COMPLETE; `Architecture_M6_CP1_CB6_A6_Code_Build_Report.md`)
**Mandatory successor:** `M6-CP1-TB6-A6-REV`
**Frozen by:** the review-agent handoff reconciliation after CB6-A6 closeout. It restates the gate already pre-registered by `Architecture_M6_CP1_CB6_A6_Quotient_Product_Extraction_Code_Build_Plan.md` §6-§7 and `Architecture_M6_DEFN_R3_Review_Record.md` §4, and fixes the focused order and routing so the gate stays comparable with TB5.

## 1. Candidate (consume immutably)

- Artifact `10896307843`, provider digest `sha256:54eb770889822ef265053494e55e25af79616f77305d1ac6900f2f8969f56b7e`. It comes from Compile R1 run/job `36212725707 / 108322509801`; log artifact `10896347611`.
- Semantic source: `a532f803bd2f0ef92342652ea3f1a9b64945ba69`. Packaged source archive: `source-a532f803….tar.gz`, SHA-256 `e48ad4a919e450ccd9809083af0c02e2260b7c040d40ee94741aa79428fc9a45`.
- Root `SHA256SUMS` must verify **28/28** before and after runtime. Receipts, GMP/GMPXX evidence and `runtimeExecution=false` must be present exactly as packaged.

## 2. Frozen process order: 11 focused, then selector449 = 460 fresh exact-filter processes

All 11 focused identities route to `directional_surface_cell_producer_tests`. `tests/SurfaceCellTransitionQuotientTests.cpp` is compiled into that target (`cmake/DirectionalTests.cmake` `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES`).

| # | identity | origin |
|---:|---|---|
| 1 | `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell` | TB5 focused 1 |
| 2 | `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity` | TB5 focused 2 |
| 3 | `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints` | TB5 focused 3 |
| 4 | `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct` | TB5 focused 4 (source mechanically migrated `lattice` → `placement.lattice`, value-identical; TB6-A6-REV confirms) |
| 5 | `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` | TB5 focused 5 |
| 6 | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | TB5 focused 6 (storage-direction falsifier for RA-1) |
| 7 | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | TB5 focused 7 |
| 8 | `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant` | new (CB6-A6 plan §6.1) |
| 9 | `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord` | new (§6.2) |
| 10 | `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption` | new (§6.3) |
| 11 | `M6CP1.CycleClosingRelationTransportConflictRejected` | new (§6.4) |

Then all 449 selector449 identities in exact file order: selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, with owner routing from routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` (owner census 32 / 301 / 75 / 41).

Each process runs one exact `--gtest_filter`, and must select exactly one test with zero skips. Benchmark count is 0. There is no watchdog, no retry after runtime starts, and no discovery-based enumeration.

## 3. Recovery-green shape (conjunctive)

- focused **11/11 PASS** and selector449 **449/449 PASS**, i.e. **460/460**;
- exact-one selection and zero skips/crashes/selection mismatches for all 460;
- pre/post package, source and execution-view byte/mode censuses identical; candidate ZIP, source archive, selector and routing hashes unchanged;
- selector row140 PASS; no raw log contains `OccurrenceInvalidCornerAuthority`;
- **holonomy falsifiers:** selector row232 (cylinder) and torus rows 444/446/448/449 PASS, and **no raw log contains `QuotientHolonomyConflict`**.

## 4. RED handling (no repair)

Any mechanically valid RED is preserved and goes to mandatory `M6-CP1-TB6-A6-REV`. TB does not rerun, repair or reclassify it.
- **A `QuotientHolonomyConflict` first failure on row232 or 444/446/448/449** is the pre-registered R3 §5.4 falsifier. Only TB6-A6-REV may adjudicate it: a true holonomy defect, or a rule too strict for legitimate residual holonomy, with the documented evidence-only fallback.
- **Any other RED:** record its first failure string. Isolation failures carry RA-12 site suffixes, and `QuotientHolonomyConflict` / `SurfaceQuotientProductErrorCode` names identify A6 sites.

## 5. Evidence to record

The EXEC report records:
- the candidate/result/log artifact IDs and digests;
- the recursive self-manifest count;
- the execution-ledger hash and red-ledger contents;
- the per-phase totals;
- the differential against TB5, i.e. which of TB5's 456 identities changed state, and the 4 new identities;
- explicit statements about rows 140, 232 and 444/446/448/449 and focused 5/6/7.

EXEC grants no promotion, CP1 closure, stable-event change or debt credit.
