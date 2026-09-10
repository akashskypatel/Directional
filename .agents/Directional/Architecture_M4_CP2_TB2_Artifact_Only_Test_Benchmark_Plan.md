# M4-CP2-TB2 Artifact-Only Test + Benchmark Plan

**Status:** AUTHORIZED AFTER CB2 COMPILE GREEN / IMMUTABLE PACKAGE117 ONLY

**Turn:** `M4-CP2-TB2-EXEC`
**Boundary:** artifact-only Test + Benchmark execution; no source/test/fixture/selector/build mutation; no compile/relink/regeneration

## 1. Frozen candidate authority

TB2 must consume exactly:

- semantic source: `534c0d41ae05b31e66711f21f4b4280b59f6483f`;
- package117 result artifact: `10172820820`, `directional-m4-cp2-cb2-package117-result-34529050994`;
- package ZIP/provider SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`;
- compile run/job: `34529050994 / 103045247639`;
- compile-log artifact: `10172821494`, SHA-256 `9ad32693bebf78fc757dec039598083df15b38defdcb0edfe5fed6060b6337f2`;
- packaged source archive SHA-256: `a366908f0f52cc7bcdff4123893acbc553201880aa86a07f9418aac2734082f4`;
- selector382 SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- accepted first373 prefix SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- first380 prefix SHA-256: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- owner partition: **30 authority-kernel / 236 producer / 75 completion / 41 validation**.

No other package, source revision or rebuilt binary may substitute for this candidate.

## 2. Immutable preflight — must pass before runtime

1. Download artifact `10172820820` once and verify the provider/download SHA-256 above.
2. Extract into a fresh execution directory; do not repair permissions or mutate package bytes.
3. Run `sha256sum -c SHA256SUMS`; require **28/28** and verify `SHA256SUMS` contains no self-entry.
4. Require `metadata/source-commit.txt` equals the exact semantic source and all packaged source-status receipts are empty.
5. Require `metadata/build-exit-code.txt=0`, `metadata/preflight-exit-code.txt=0`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and both GMPXX/GMP linkage receipts.
6. Verify the packaged source archive hash, extract it once, and verify selector382 row count/hash plus first373/first380 prefix hashes.
7. Build the identity-to-owner map from packaged source/CMake authority only. Require exactly one owner for every selector identity, zero missing/duplicate definitions, and owner counts **30/236/75/41**. Do not execute `--gtest_list_tests`, discovery binaries, generated discovery, or any package-repair command.
8. Verify all four selector-owner executables exist and their SHA-256 values equal the CB2 build report. Mode repair is prohibited; a non-executable package is orchestration failure.
9. Record preflight/package/source/execution-view censuses for immutable postflight comparison.

If any preflight condition fails, stop before semantic runtime. Classify as orchestration/package-integrity failure, not PASS/SKIP.

## 3. Fresh-process execution primitive

For one selector identity `IDENTITY` mapped to owner binary `OWNER`, launch one fresh process only:

```bash
"$PACKAGE/bin/$OWNER" --gtest_filter="$IDENTITY"
```

Capture stdout/stderr and exit code separately per identity. Require exactly one `[ RUN      ]` line for `IDENTITY`, one terminal `[       OK ]` for PASS, no other selected identity, and process exit `0`. A zero-selected invocation or selection mismatch is failure, never PASS.

Do not invoke any owner binary without an exact frozen selector identity filter.

## 4. Focused correction phase A and B

Run ordinals **374, 381, 382** in that order, one fresh process each. Then repeat the same ordered three identities in a second independent phase.

Required identities:

1. `GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle`
2. `GlobalConformityCertificate.IndependentVerifierRejectsWorkLedgerBoundHistoryAndAssuranceTamper`
3. `GlobalConformityOutcome.SemanticDigestBindsFullCP2Outcome`

Both focused phases must be **3/3 PASS**, have identical verdict vectors, zero RED/SKIP/timeout/selection mismatch, and preserve package bytes.

For ordinal 374, each passing raw log must contain exactly one success-visible source-derived receipt with all three fields:

```text
M4_CP2_ORACLE_RECEIPT coordinateCount=4; containsBidirectedCoefficientMagnitude2=true; magnitude2LoadBearing=true
```

Missing, duplicate, false or differently sourced receipt is RED even if the gtest exit code is zero.

## 5. Full selector382 gate

Execute all 382 selector identities in frozen file order, one identity per fresh process using the primitive in §3. Do not use generated test discovery.

Report separately:

- accepted predecessor rows **1-373**;
- previously measured CP2 rows **374-380**;
- correction rows **381-382**;
- each owner executable outcome.

Required semantic result:

- selector382: **382/382 PASS**;
- accepted predecessor: **373/373 PASS**;
- rows374-380: **7/7 PASS**;
- rows381-382: **2/2 PASS**;
- owner outcomes: **30/30 / 236/236 / 75/75 / 41/41**;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**.

The full semantic suite must run to organic process completion. Do not impose a repository workflow/job timeout whose purpose is to terminate or partition the required complete gate.

## 6. Postflight immutability

After runtime, recompute package, extracted-source and execution-view censuses and require exact equality with preflight. Require no configure/compile/relink, regeneration, package repair, mode repair, source/test/fixture/selector mutation or benchmark execution.

Record an explicit execution-boundary receipt covering at minimum:

- `runtime_started=true` and `runtime_completed=true` only if the complete selector run finishes;
- `preflight_completed=true`;
- `selection_integrity=true`;
- `configure_execution=false`;
- `compile_execution=false`;
- `relink_execution=false`;
- `generated_discovery=false`;
- `package_repair=false`;
- `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`;
- `benchmark_execution=false`.

## 7. Evidence package and report

Preserve raw per-process logs, focused phase ledgers, full selector ledger, identity-owner map, owner distribution, pre/post censuses, ordinal374 receipt audit, semantic summary, execution-boundary receipt and diagnostic log. The report must state exact workflow run/job IDs, source/package/artifact hashes, every count above, and whether any regression candidate was observed.

No performance claim is being made by CB2, so **do not run benchmarks** in TB2.

## 8. Stop, rerun and successor rules

- Any semantic RED, SKIP, timeout, selection mismatch, missing ordinal374 receipt, nondeterministic focused result or immutable-postflight mismatch prevents promotion.
- Do not repair source, tests, fixtures, selectors or package inside TB2.
- Do not rebuild package117.
- Do not retry deterministic semantic failures unchanged. Preserve first actionable raw evidence for TB-REV.
- An infrastructure/transient failure may be rerun only after evidence establishes the failure was non-semantic and package bytes remain authoritative.
- TB2-EXEC never promotes package117 by itself.

**Exact successor after EXEC:** `M4-CP2-TB2-REV`, which independently re-opens package/result/log evidence and decides package117 promotion and M4-CP2 closure or a corrective next turn.
