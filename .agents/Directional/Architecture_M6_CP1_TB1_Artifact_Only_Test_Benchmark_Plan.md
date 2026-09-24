# M6-CP1-TB1 — Artifact-Only Test + Benchmark Plan

**Turn:** `M6-CP1-TB1-EXEC`
**Type:** Test + Benchmark, immutable artifact only
**Predecessor:** `M6-CP1-CB1`
**Candidate artifact/source:** `10826090221 / ee8b8ac20571df5773f5f94bf9b382161f37a893`
**Accepted predecessor:** M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`

## Goal

Mechanically test the first A5 product cutover without rebuilding, repairing, publishing a selector, or granting semantic credit. Execute the complete M6-CP1-CB1 focused prepublication vector and the unchanged accepted selector449 from the exact immutable candidate package. Review remains the sole promotion/adjudication owner.

## Immutable preflight

1. Download result artifact `10826090221` exactly once and verify its provider/outer SHA-256 `6e3c3b09d272e200f3c213aa5198ed805bff2f293f35b37a55b948176c870a9c`.
2. Extract with an archive tool that preserves packaged executable mode bits (`unzip`/`tar` as appropriate). **Do not use Python `zipfile.extractall` for executable payloads and do not `chmod` or otherwise repair the package.** A missing executable mode is orchestration failure.
3. Verify the package `SHA256SUMS` completely (expected 28/28), exact packaged source commit `ee8b8ac20571df5773f5f94bf9b382161f37a893`, clean source receipts, GMP/GMPXX evidence and `runtimeExecution=false`.
4. Verify packaged selector449 is exactly 449 LF lines with SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; verify the paired routing receipt has 449 rows and routes every selector identity to a packaged owner executable.
5. Record immutable preflight hashes of every executable, selector/routing file and packaged source archive used by the run. If any check fails, execute nothing and report orchestration failure.

No configure, CMake generation, compile, link, source mutation, fixture mutation, permission repair or package repair is permitted.

## Focused prepublication vector — six fresh exact-filter processes

Execute each identity in a fresh process from the packaged `directional_surface_cell_producer_tests` binary, requiring exit 0, exactly one selected test, zero skips and PASS:

1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
2. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
3. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
4. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

The last two are previously ungated/no-credit identities. Their execution in TB1 grants no retroactive M5 credit. If pair-swap is RED, preserve the exact failure for Review to determine whether CB1 introduced an edge-storage-order dependence; do not repair it in EXEC.

## Accepted predecessor gate — 449 fresh exact-filter processes

Execute every identity in accepted selector449 once in a fresh process using its frozen routing receipt. Require:

- **449/449 PASS**;
- exactly one selected test per process;
- zero skips, crashes, timeouts or selection mismatches;
- owner census unchanged at **32 / 301 / 75 / 41**;
- no benchmark invocation.

The focused six are not part of selector449, so the planned runtime census is **455 fresh exact-filter processes total**.

## Postflight and evidence

1. Re-hash the immutable package, executables, selector/routing files and packaged source archive and require exact preflight equality.
2. Produce a machine-readable execution ledger with one row per planned process, raw log SHA-256, selected/skipped/pass/fail counts, exit code, owner executable and identity.
3. Upload a self-verifying result artifact and separate diagnostic log artifact. The result manifest must include every required evidence file exactly once and exclude itself.
4. Record benchmark execution count **0**, build/configure/link mutation count **0**, and immutable package/source postflight.
5. Categorize every observed regression in `Regression_Root_Cause_Tracker.md` before EXEC closes. If no semantic regression is observed, record +0 and leave stable totals unchanged.

## Stop rules

- Any package/preflight/postflight mismatch: orchestration failure, zero semantic credit.
- Zero-selected or skipped exact-filter process: orchestration failure, never PASS.
- Any focused or selector RED: preserve exact evidence; do not patch/rebuild/retry inside EXEC.
- Do not publish selector450 or any successor selector in this turn.
- Do not claim A5 acceptance, CP1 closure, G4-B002/G4-B004 closure, or production readiness.

## Successor

After one complete authoritative execution, the exact successor is mandatory runtime-free `M6-CP1-TB1-REV`. Review independently re-derives package and execution evidence, adjudicates the six focused identities, and alone decides whether the A5 candidate is accepted and what bounded M6-CP1 Code + Build turn follows.
