# M4-CP3-TB1 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP3-TB1-EXEC`
**Status:** **COMPLETE / MEASURED SEMANTIC RED / IMMUTABLE POSTFLIGHT GREEN / REVIEW PENDING / PACKAGE118 UNPROMOTED**
**Date:** 2026-09-11 UTC
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`

## 1. Frozen authority

This execution consumed the unchanged candidate package118 frozen by `M4-CP3-CB2`:

- semantic source: `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`;
- package118 artifact: `10182447649`, `m4-cp3-cb2-package118-result-34555543569`;
- package ZIP/provider SHA-256: `1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5`;
- package byte size: `28902972`;
- candidate selector394 SHA-256: `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- accepted selector382 prefix SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- candidate owner partition: **30 authority-kernel / 248 producer / 75 completion / 41 validation**;
- accepted predecessor owner partition: **30 / 236 / 75 / 41**.

No configure, compile, relink, package repair, permission repair, generated discovery, source/test/fixture/selector mutation, benchmark, package promotion, or production A3→A4 cutover was authorized or performed.

## 2. Orchestration provenance

Two earlier runs, `34557449252` and `34557611244`, were orchestration-only failures caused by Bash `local` declaration ordering in the temporary artifact harness. They provide no semantic credit and did not alter package118, source, tests, fixtures, selectors, or build logic. The bounded harness correction changed orchestration only; the successful run re-executed the complete frozen plan from immutable package118.

## 3. Exact execution evidence

- authoritative workflow run/job: `34557818974 / 103134172994`;
- workflow event SHA: `ec0912f759adbe6bf3c68a363e74e4ee40952962`;
- result artifact: `10183361985`, SHA-256 `9f1b15e00616d487b99edc4f6681c9097dc68ff4091a5432f95f34a5c1ea9cec`;
- diagnostic-log artifact: `10183362199`, SHA-256 `90f9b68699157351532984c176b1aa0c8943becc54a4c75acde24973346d4eda`;
- immutable package preflight: **28/28** checksums green;
- immutable package postflight: **28/28** checksums green;
- package census pre/post SHA-256: `514782b859f2536dccd402de80184a37de96c2f5d26243ab5dd9d4f050704697` / same;
- execution-view census pre/post SHA-256: `a58f07aa568a74c4432401893e3e31fdd5ac2207994a8cc3abf1c76aad3e2e18` / same;
- exact fresh test-process count: **800** = 12 focused-A + 12 focused-B + 382 predecessor + 394 cumulative;
- `artifactOnly=true`, `configureExecuted=false`, `compileExecuted=false`, `relinkExecuted=false`, `generatedDiscoveryExecuted=false`, `packageRepairExecuted=false`, `permissionRepairExecuted=false`, `sourceTestFixtureSelectorMutation=false`, `productionA3A4Cutover=false`, `packagePromotion=false`.

The harness reached normal completion of every planned process and immutable postflight. Its nonzero terminal code is the expected aggregate result of semantic RED rows, not an orchestration failure.

## 4. Focused rows 383-394 — repeated deterministically

Both focused phases executed the same twelve identities in the same order, one fresh process per identity.

- focused-A: **5 PASS / 7 RED**;
- focused-B: **5 PASS / 7 RED**;
- ordered verdict vectors: **byte-identical**;
- vector: `PASS PASS PASS RED PASS RED RED RED RED RED PASS RED`.

The seven reproducibly RED new identities are:

| Ordinal | Identity |
|---:|---|
| 386 | `GlobalConformityBaseline.OneEndedTerminalUsesComponentLocalExterior` |
| 388 | `GlobalConformityBaseline.CanonicalLexPrefixChoosesLeastCountVectorAcrossEqualTJoins` |
| 389 | `GlobalConformityBaseline.ParityFlipMapsOneToTwoAndLargerToPredecessor` |
| 390 | `GlobalConformityBaseline.IndependentTinyExhaustiveOracleMatchesParityOptimumAndLexTie` |
| 391 | `GlobalConformityBaseline.IndependentValidatorRejectsParityCertificateTamperMatrix` |
| 392 | `GlobalConformityBaseline.CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant` |
| 394 | `GlobalConformityBaseline.ProductionBaselineBinderIsStructurallySeparateFromFramedSolver` |

The first semantic failure is ordinal **386**, `GlobalConformityBaseline.OneEndedTerminalUsesComponentLocalExterior`.

TB-EXEC records these outcomes only. It does not assign root cause, corrective ownership, stable regression identity, or implementation action; those belong to `M4-CP3-TB1-REV`.

## 5. Accepted predecessor gate

The unchanged accepted prefix executed completely:

- selector382: **382 PASS / 0 RED**;
- owner totals: **30 / 236 / 75 / 41**;
- zero accepted-prefix semantic regression was measured.

Package117 / selector382 **382/382** therefore remains the latest accepted M4 runtime authority pending review. Package118 is not promoted by this execution.

## 6. Cumulative candidate gate

Selector394 executed in order, one fresh process per identity:

- cumulative selector394: **387 PASS / 7 RED**;
- accepted predecessor: **382/382 PASS**;
- CP3 appended rows: **5/12 PASS, 7/12 RED**;
- owner totals: **30 / 248 / 75 / 41**;
- the RED ordinal set is exactly **[386, 388, 389, 390, 391, 392, 394]**, matching both focused phases.

This is deterministic measured semantic RED, not a package-integrity or selection-orchestration failure.

## 7. Immutable postflight

The required package and execution-view censuses are byte-identical before and after execution. `sha256sum -c SHA256SUMS` verifies **28/28** both before and after runtime. No package source, test, fixture, selector, binary, metadata, manifest, mode, size, or content changed.

The artifact-only boundary remained intact throughout the successful run.

## 8. Authority boundary and exact successor

TB-EXEC is complete because every planned command reached an organic terminal outcome and raw evidence was preserved. The semantic result is RED, so package118 remains **candidate / unpromoted** and the production A3→A4 cutover remains forbidden.

Stable accounting remains **47 events / 14 categories / 33 recurrences** and produced-witness debt remains **5** at EXEC closeout. This is not an adjudication that the seven RED rows are non-stable; classification is deliberately deferred to the required review.

Exact next turn: **`M4-CP3-TB1-REV`**. It is runtime-free evidence review. It must consume immutable package118 plus result artifact `10183361985` and diagnostic-log artifact `10183362199`, independently re-derive the decisive process/selector/immutability facts, classify the seven semantic REDs in `Regression_Root_Cause_Tracker.md`, decide package118 disposition, and freeze any justified successor plan. No compile, rerun, package repair, implementation/test mutation, package promotion, or A3→A4 cutover precedes that review.
