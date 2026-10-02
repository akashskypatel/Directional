# M6-CP1-TB7-A6 — Artifact-Only Test + Benchmark Plan (frozen 460-process recovery gate)

**Turn:** `M6-CP1-TB7-A6-EXEC`
**Type:** artifact-only runtime gate; no configure, compile, relink, repair or source mutation
**Predecessor:** `M6-CP1-CB7-A6` (COMPLETE; `Architecture_M6_CP1_CB7_A6_Code_Build_Report.md`)
**Mandatory successor:** `M6-CP1-TB7-A6-REV`

## 1. Candidate — consume immutably

- Result artifact `11257522199`, provider digest `sha256:bbb18e89f41b959aa82e285c20b543ac9fea9f65fad6a07b0e6cfb1d989f10fd`; compile run/job `37078118843 / 111072482082`; log artifact `11257522202`, digest `sha256:a25f02b42ed950336eda2924c3345c10facf451260395af471838b087a37bef6`.
- Semantic source: `40842caa88f8d7a08a38c91273ace77ebd7c0676`. Packaged source archive SHA-256: `2c8981c6da6e9e72b4977f2879a687e2ba1c6c042591bd82720936f69888d27f`.
- Root `SHA256SUMS` must verify **28/28** before and after runtime. Receipts, GMP/GMPXX evidence and `runtimeExecution=false` must be present exactly as packaged.
- Selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; routing owner census `32 / 301 / 75 / 41`.

Do not repair permissions, package bytes, manifests, fixtures, or source. Missing executable mode or missing packaged evidence is orchestration failure, not permission to mutate the candidate.

## 2. Mandatory execution view before runtime

TB6's first attempt proved that package binaries cannot be run from an arbitrary extraction directory without the packaged fixture layout. Before starting process 1:

1. extract the candidate with an archive tool that preserves executable mode bits;
2. extract the packaged source archive separately and verify its declared SHA-256;
3. create a **separate execution view** without altering either immutable extraction;
4. stage/copy the packaged-source `benchmarks/fixtures` directory into the execution view at the adjacent path expected by the binaries: `test-data/benchmarks/fixtures`;
5. record byte/mode censuses for the candidate extraction, packaged-source extraction and execution view;
6. verify the execution-view fixture bytes derive only from the packaged source.

This setup is orchestration, not a fixture repair. Once process 1 begins, there is no retry or alternate execution-view construction after a mechanically valid RED.

## 3. Frozen process order — 11 focused, then selector449

All 11 focused identities route to `directional_surface_cell_producer_tests`. Execute each as one fresh process with one exact `--gtest_filter`, exact-one selection and zero skips.

| # | identity | recovery role |
|---:|---|---|
| 1 | `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell` | retained A5 control |
| 2 | `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity` | retained A5 permutation control |
| 3 | `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints` | retained malformed-endpoint control |
| 4 | `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct` | retained coincidence control |
| 5 | `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` | retained multi-isolation control |
| 6 | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RA-13 nonzero-Z4 produced witness |
| 7 | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | retained seam authority control |
| 8 | `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant` | retained A6 class identity |
| 9 | `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord` | retained exact-once ledger |
| 10 | `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption` | strengthened certificate-to-A5 tamper falsifier |
| 11 | `M6CP1.CycleClosingRelationTransportConflictRejected` | unchanged strict-cycle negative |

Then execute all 449 selector449 identities in exact selector file order, routed through routing449. Total: **460 fresh exact-filter processes**. Benchmark count is 0. There is no discovery-based enumeration, watchdog, partitioned continuation, or retry after runtime starts.

## 4. Recovery-green shape — conjunctive

All conditions are required:

- focused **11/11 PASS** and selector449 **449/449 PASS**, i.e. **460/460**;
- exact-one selection and zero skips/crashes/selection mismatches for all 460;
- selector139 and selector142 PASS by correctly rejecting with legacy `InvalidHardRailTransport`;
- selector140 PASS;
- selector232 and torus rows444/446/448/449 PASS;
- focused6 PASS under RA-13 placement-gauge transport and the strict cycle rule;
- focused10 PASS including the new tamper-away-from-A5 `RelationCertificateConflict` branch;
- focused11 PASS unchanged;
- no accepted produced row, especially focused6 and selector446, emits `QuotientHolonomyConflict`;
- no raw log contains `OccurrenceInvalidCornerAuthority`;
- candidate package, packaged source, selector and routing hashes are unchanged;
- pre/post candidate/source/execution-view byte and mode censuses are identical; root package manifest remains 28/28.

## 5. RED handling — no repair and no same-turn rerun

Any mechanically valid RED is preserved and advances to mandatory `M6-CP1-TB7-A6-REV`. EXEC does not repair, weaken, reclassify, recompile, alter fixtures, or rerun a mechanically valid semantic failure.

- If focused6 or selector446 fails with `QuotientHolonomyConflict`, preserve the full RA-13 residual suffix and exact relation/cycle identity. Review owns diagnosis; EXEC must not introduce or resurrect a residual-holonomy fallback.
- If selector139/142 fails to restore accepted `InvalidHardRailTransport`, preserve the exact typed A5 failure/missing-failure evidence.
- Any certificate authority failure must retain the exact A5/A6 relation identity and typed error.
- An orchestration failure before semantic runtime receives no semantic credit and must be distinguished from a mechanically valid RED.

## 6. Evidence to record

The EXEC report records:

- candidate/result/log artifact IDs and provider digests;
- candidate root-manifest count and packaged-source archive hash;
- execution-view construction receipt and pre/post byte/mode censuses;
- execution-ledger hash and red-ledger contents;
- focused/selector totals and exact-one/skip/crash mismatch counts;
- explicit outcomes for focused6/10/11 and selectors139/140/142/232/444/446/448/449;
- grep/census result for `QuotientHolonomyConflict` and `OccurrenceInvalidCornerAuthority`;
- differential against authoritative TB6: which of its 460 identities changed state;
- immutable postflight proof.

EXEC grants no candidate promotion, CP1 closure, stable-event/accounting change, debt credit, R4/A7 authorization, or `G4-B002` disposition. Those remain Review-owned.
