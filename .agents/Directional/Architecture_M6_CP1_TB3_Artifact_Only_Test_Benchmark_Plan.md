# M6-CP1-TB3 Artifact-Only Test + Benchmark Plan

**Turn:** `M6-CP1-TB3-EXEC`
**Type:** Test + Benchmark, immutable artifact-only
**Predecessor:** `M6-CP1-CB3`
**Candidate artifact/source:** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**Mandatory successor:** `M6-CP1-TB3-REV`

## Goal

Consume the exact CB3 package immutably and test whether the two Review-owned recovery surfaces are corrected without regressing the frozen CP1 prepublication and accepted selector449 surfaces.

## Immutable preflight

1. Download the exact CB3 result artifact and verify its provider digest plus recursive package manifest before execution.
2. Verify packaged source SHA `660015f2f15359fd426e2c855aea9f4201c70216`, clean source receipts, GMP/GMPXX linkage and `runtimeExecution=false` from the build package.
3. Extract with an archive tool that preserves executable mode bits. Do not use Python `zipfile.extractall` for executable payloads, do not `chmod`, and do not repair packaged bytes.
4. Do not configure, compile, relink, regenerate discovery/code, patch source, mutate fixtures, or fetch a remotely rebuilt replacement.
5. Verify selector449 is exactly 449 LF rows with SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 is `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Execution contract

Execute exactly **455 fresh exact-filter processes** in this order:

1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
2. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
3. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
4. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`
7. all 449 selector449 identities, in selector order.

For every process require exact-one test selection and zero skips. Benchmark count is **0**. Run exact immutable postflight after execution.

## Recovery-green shape

Mechanically green is exactly:

- focused **6/6 PASS**;
- selector449 **449/449 PASS**;
- aggregate **455/455 PASS**;
- exact-one selection and zero skips for every process;
- no crashes or selection mismatches;
- no `OccurrenceInvalidCornerAuthority` anywhere;
- row140 rejects through the accepted `InvalidHardRailTransport` contract;
- focused multi-isolation publishes at least one legitimate lineage whose actual quotient members span more than one isolation sheet, with relation/equivalence evidence;
- pair-swap remains PASS;
- immutable postflight is exact.

Any mechanically valid RED is preserved as evidence and advances directly to mandatory `M6-CP1-TB3-REV`. Do not repair, rerun, tune, promote, close CP1, or change stable accounting inside TB3-EXEC.

## Regression documentation

Categorize every observed regression in `.agents/Directional/Regression_Root_Cause_Tracker.md` before TB3 closes. If evidence does not justify a stable ID/count change, record it as candidate/non-stable and explicitly preserve stable totals.
