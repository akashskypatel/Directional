# M6-CP1-TB2 Artifact-Only Test + Benchmark Plan

**Turn:** `M6-CP1-TB2-EXEC`
**Type:** Test + Benchmark, immutable artifact only
**Candidate artifact/source:** `10834642074 / 724316a5b3f49e33dc8e649989bb413b3dc6b7c9`
**Candidate ZIP SHA-256:** `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`
**Predecessor:** `M6-CP1-CB2`
**Mandatory semantic successor:** `M6-CP1-TB2-REV`

## Goal

Falsify or confirm the one-variable CB2 recovery without rebuilding or changing any semantic input. Re-run the exact CP1 prepublication surface that TB1 used: six frozen focused identities followed by accepted selector449, each in a fresh exact-filter process.

## Immutable preflight

1. Download artifact `10834642074` exactly once and verify outer SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`.
2. Extract with ordinary archive tooling that preserves archived executable mode bits. **Do not use Python `zipfile.extractall`, `chmod`, or any permission/content repair.** Missing executable mode is orchestration failure.
3. Verify root `SHA256SUMS` **28/28**, manifest SHA-256 `a0fffc173149d1917ed6ab6a7dbb3c70335dee0b0e4ecb6ce652438d02037c9e`, and packaged source archive SHA-256 `eaf577ccdc534c2e9e48b8b8fed31079849b268c4a6c1b47b0f253ff3ad6034b`.
4. Require `metadata/source-commit.txt == 724316a5b3f49e33dc8e649989bb413b3dc6b7c9`, five empty source-status receipts, GMP/GMPXX linkage evidence, and `runtimeExecution=false` in `metadata/command-boundary.txt`.
5. From the packaged source, verify selector449 is exactly **449 LF rows** at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 SHA-256 is `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
6. Resolve every planned identity to a packaged executable before runtime. The six focused identities all live in `directional_surface_cell_producer_tests`; selector449 routing remains authoritative for its 449 rows.
7. Record a complete pre-execution byte/mode census of the package, packaged source, and execution view for immutable postflight comparison.

Any failed preflight is orchestration failure. Do not repair, rebuild, regenerate, relink, or substitute another package.

## Frozen focused vector — execute first

Run these six identities in this exact order, each as one fresh process with an exact GoogleTest filter:

1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
2. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
3. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
4. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

For every process require exactly one selected test and **zero skips**. A zero/multi-selected process, crash, harness parse failure, missing executable, or package mutation is orchestration failure, not semantic RED/PASS.

TB1's three focused PASSes receive no carry-forward credit because they executed under the now-corrected undefined iterator range. TB2 is the first clean runtime evidence for all six focused identities.

## Accepted selector449 gate

After the six focused processes, execute every row of `.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt` in exact file order as **449 additional fresh exact-filter processes**. Use the frozen routing receipt to select the packaged executable for each row. Require exactly one selected test and zero skips per process.

Total planned runtime is therefore exactly **455 fresh processes = 6 focused + 449 selector**.

Do not run benchmarks in TB2; benchmark process count is **0**. Do not add discovery/list/help/version invocations of packaged Directional binaries. Do not configure, compile, relink, regenerate, patch, mutate source/tests/fixtures/selectors/routing/package bytes, or manufacture replacement inputs.

## Timeout and rerun rules

The complete 455-process acceptance gate must run uninterrupted to organic process results. Do not impose a workflow/job timeout for the purpose of cutting the required suite short, and do not partition/retry/stitch continuations merely to evade elapsed runtime.

A mechanically valid semantic RED is preserved exactly and **not rerun**. Retry only a diagnosed orchestration/infrastructure failure whose semantic result is invalid, and record the invalid attempt separately.

## Pre-registered semantic classification

`M6-CP1-TB1-EXEC-CAND-01 / CROSS_TEMPORARY_ITERATOR_RANGE` is recovered only when **both** conditions hold:

1. no one of the 455 processes reports `OccurrenceInvalidCornerAuthority`; and
2. accepted selector449 is **449/449 PASS**.

Expected recovery-green shape is focused **6/6 PASS** + selector **449/449 PASS = 455/455 PASS**.

Classification rules are binding:

- any remaining `OccurrenceInvalidCornerAuthority` is **failed recovery**; preserve its first sub-predicate/locus and send it to Review;
- a focused RED whose **first failure differs** from `OccurrenceInvalidCornerAuthority` is a **new candidate**, not failed recovery of CAND-01;
- this distinction is especially important for `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`, which never ran cleanly in TB1 and may expose a latent independent edge-storage-order defect;
- no TB result authorizes repair, test/selector weakening, candidate promotion, CP1 closure, or G4/debt credit before Review.

## Evidence to preserve

Preserve at minimum:

- workflow run/job IDs and exact package/source identity;
- package/preflight verification receipts and extraction-mode evidence;
- one row per planned process with ordinal, phase, filter, executable, selected/passed/failed/skipped counts, exit code, elapsed time, and raw-log SHA-256;
- complete focused and selector PASS/RED ledgers;
- first failure text/locus for every RED;
- aggregate 6/449/455 totals and benchmark count 0;
- exact immutable postflight byte/mode censuses and comparison;
- a self-excluding recursive result manifest plus dedicated diagnostic log artifact.

## Stop and successor

After one mechanically valid 455-process result, stop. Do not repair or rerun a semantic result inside TB2.

Exact successor is mandatory runtime-free **`M6-CP1-TB2-REV`**, whether TB2 is recovery-green or semantic RED/new-candidate. Review must independently re-open candidate/result/log evidence, adjudicate recovery/new-candidate status, update stable accounting only if justified, and decide whether CP1 advances.
