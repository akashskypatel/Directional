# M4-CP2-TB2-R1 Artifact-Only Test + Benchmark Plan

**Status:** **AUTHORIZED AFTER CB3 STATIC GREEN / IMMUTABLE PACKAGE117 RETRY ONLY**
**Turn:** `M4-CP2-TB2-R1-EXEC`
**Boundary:** artifact-only Test + Benchmark re-execution; no source/test/fixture/selector/build mutation; no compile/relink/regeneration; invalid TB2 process observations carry no semantic credit

## 1. Frozen candidate authority

R1 must consume exactly:

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

## 2. Invalid-attempt provenance and corrected harness authority

Preserve `M4-CP2-TB2-EXEC` run/job `34532107988 / 103055098832` and result/log artifacts `10174031432 / 10174032131` as **ORCHESTRATION-INVALID / NO SEMANTIC CREDIT** provenance. Do not combine or stitch its process results into R1.

The invalid control commit was `2c37042b380ae8cc877fcb0f2d8c146e6a5efc5e`. Its exact harness lineage is:

- invalid preflight SHA-256: `af458b58c6ba6c339c80ac64d360dfeaf190f621b13e31de50d49461274f4aaa`;
- executor SHA-256: `717a4dd6cda5ba96fb8bd6e16879c422f9b2e1ff561951801dc5658d85480019`;
- invalid caller SHA-256: `a6e2d136408162eba84fa50dc18e10200b4fae748a89fb4fed193ef36c678154`.

CB3 authorizes exactly one harness semantic change: in the preflight payload replace only `execution-view-before.tsv` with `execution-view-census-before.tsv`. Materialize expected SHA-256 literals through `tools/write_orchestration_payload.py`; do not hand-transcribe digest-bearing orchestration payloads. The exact R1 payload hashes must be:

- `m4_cp2_tb2_r1_preflight.py`: `12090d4b5e01f6c3e55de712b595dff3444b509ba58b040201a2c61f87d805c1`;
- `m4_cp2_tb2_r1_execute.py`: `717a4dd6cda5ba96fb8bd6e16879c422f9b2e1ff561951801dc5658d85480019` — byte-identical to the invalid executor;
- retry caller draft: `baf81bf788f6823d79f3b34431424a1e19e7e45b6eacb6fb788604333a08d6ab`.

The retry caller changes only scalar turn/marker/workflow/script/artifact labels from the schema-validated predecessor and preserves the same YAML schema/type tree. Publish only the exact frozen retry bytes under the normal workflow lifecycle, then use a separate marker commit. Do not change reusable workflow permissions.

## 3. Immutable preflight — must pass before runtime

1. Download artifact `10172820820` once and verify the provider/download SHA-256 above.
2. Extract into a fresh execution directory; do not repair permissions or mutate package bytes.
3. Run `sha256sum -c SHA256SUMS`; require **28/28** and verify `SHA256SUMS` contains no self-entry.
4. Require `metadata/source-commit.txt` equals the exact semantic source and all packaged source-status receipts are empty.
5. Require `metadata/build-exit-code.txt=0`, `metadata/preflight-exit-code.txt=0`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and both GMPXX/GMP linkage receipts.
6. Verify the packaged source archive hash, extract it once, and verify selector382 row count/hash plus first373/first380 prefix hashes.
7. Build the identity-to-owner map from packaged source/CMake authority only. Require exactly one owner for every selector identity, zero missing/duplicate definitions, and owner counts **30/236/75/41**. Do not execute `--gtest_list_tests`, discovery binaries, generated discovery, or any package-repair command.
8. Verify all four selector-owner executables exist and their SHA-256 values equal the CB2 build report. Mode repair is prohibited; a non-executable package is orchestration failure.
9. Record `package-census-before.tsv`, `source-census-before.tsv`, and **exactly `execution-view-census-before.tsv`**. The preflight must not create or reference the invalid `execution-view-before.tsv` basename.

If any preflight condition fails, stop before semantic runtime. Classify as orchestration/package-integrity failure, not PASS/SKIP.

## 4. Fresh-process execution primitive

For one selector identity `IDENTITY` mapped to owner binary `OWNER`, launch one fresh process only:

```bash
"$PACKAGE/bin/$OWNER" --gtest_filter="$IDENTITY"
```

Capture stdout/stderr and exit code separately per identity. Require exactly one `[ RUN      ]` line for `IDENTITY`, one terminal `[       OK ]` for PASS, no other selected identity, and process exit `0`. A zero-selected invocation or selection mismatch is failure, never PASS.

Do not invoke any owner binary without an exact frozen selector identity filter.

## 5. Focused correction phase A and B

Run ordinals **374, 381, 382** in that order, one fresh process each. Repeat the same ordered three identities in a second independent phase.

1. `GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle`
2. `GlobalConformityCertificate.IndependentVerifierRejectsWorkLedgerBoundHistoryAndAssuranceTamper`
3. `GlobalConformityOutcome.SemanticDigestBindsFullCP2Outcome`

Both focused phases must be **3/3 PASS**, have identical verdict vectors, zero RED/SKIP/timeout/selection mismatch, and preserve package bytes.

For ordinal 374, each passing raw log must contain exactly one success-visible source-derived receipt:

```text
M4_CP2_ORACLE_RECEIPT coordinateCount=4; containsBidirectedCoefficientMagnitude2=true; magnitude2LoadBearing=true
```

Missing, duplicate, false or differently sourced receipt is RED even if the gtest exit code is zero.

## 6. Full selector382 gate

Execute all 382 selector identities in frozen order, one identity per fresh process using §4. Do not use generated discovery.

Require and report separately:

- selector382: **382/382 PASS**;
- accepted predecessor rows 1-373: **373/373 PASS**;
- CP2 rows 374-380: **7/7 PASS**;
- correction rows 381-382: **2/2 PASS**;
- owner outcomes: **30/30 / 236/236 / 75/75 / 41/41**;
- RED **0**, SKIP **0**, timeout **0**, selection mismatch **0**.

The complete gate must run uninterrupted to organic process completion. No repository workflow/job timeout may terminate or partition it.

## 7. Corrected postflight immutability

After runtime, recompute:

- `package-census-after.tsv` and compare byte-for-byte with `package-census-before.tsv`;
- `source-census-after.tsv` and compare byte-for-byte with `source-census-before.tsv`;
- **`execution-view-census-after.tsv` and compare byte-for-byte with `execution-view-census-before.tsv`**.

The exact execution-view names above are the CB3 correction and are load-bearing. A missing/mismatched census is orchestration failure, not semantic PASS.

Require no configure/compile/relink, regeneration, package repair, mode repair, source/test/fixture/selector mutation or benchmark execution. Record an execution-boundary receipt with `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `selection_integrity=true`, and every prohibited mutation/execution flag false.

## 8. Evidence package and report

Preserve raw per-process logs, focused phase ledgers, full selector ledger, identity-owner map, owner distribution, pre/post censuses, ordinal374 receipt audit, semantic summary, execution-boundary receipt, workflow-boundary receipt, and diagnostic log. The report must identify the exact run/job, package/source/artifact hashes, every count above, and the invalid-attempt provenance separately.

No performance claim is under test: **do not run benchmarks**.

## 9. Stop, rerun and successor rules

- Any semantic RED, SKIP, timeout, selection mismatch, missing ordinal374 receipt, nondeterministic focused result, or immutable-postflight mismatch prevents promotion.
- Do not repair source, tests, fixtures, selectors or package inside R1.
- Do not rebuild package117.
- Do not stitch audit-only results from the invalid TB2 attempt into R1.
- Do not retry deterministic semantic failures unchanged. Preserve first actionable raw evidence for review.
- Another orchestration failure routes to a bounded orchestration-correction CB under the durable cadence; it receives no semantic credit.
- `M4-CP2-TB2-R1-EXEC` never promotes package117 by itself.

**Exact successor after a valid R1 execution:** `M4-CP2-TB2-R1-REV`, which re-opens package/result/log evidence and decides package117 promotion and M4-CP2 closure or the next corrective turn.
