# M4-CP-SCALE-TB4-R1-EXEC Artifact-Only Test + Benchmark Plan — regular S2 comparator reachability

**Status:** FROZEN BY `M4-CP-SCALE-CB5`
**Turn type:** Test + Benchmark execution only; immutable artifact; no rebuild or repair
**Candidate semantic source:** `905dabe390577d63ed6a9289e3f3d53aa4144936`
**Candidate result artifact:** `10378808176` (`sha256:a60fbbb7127b2fb36952cc9fef8d58cce366204ffbcbdcd7ace2de69ff7e488a`)
**Compile evidence:** run/job `34923091581 / 104235295287`; `runtimeExecution=false`
**CB5 corrected payloads:** `m4_cp_scale_tb4_r1_exec.py` / `_lib.py`, SHA-256 `a83ad830677f32aa0a882158c1e800762c65957ce5bb69645acbc511a8b37673` / `10fa3684a75968e5a14256c90f7e24fec486eb8d63553f9c6daee873ace20967`; no semantic/package rebuild.
**Invalid predecessor:** run/job `34938070127 / 104280301940`; orchestration-invalid, no semantic ledger.

## 1. Purpose and authority boundary

Re-execute the complete CB4 S2 gate from process 1 using only the same immutable packaged binaries and frozen selector423. The prior TB4-EXEC attempt is orchestration-invalid and supplies no semantic result to this retry. This turn may execute the pre-authored runtime gate and preserve evidence. It may not edit production/test/fixture/benchmark/build logic, rebuild, relink, regenerate, discover generated tests, or repair a failure. Runtime promotion and stable regression accounting remain Review-owned by the mandatory successor `M4-CP-SCALE-TB4-REV`.

Accepted runtime authority remains TB1-Review package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423** until Review says otherwise.

## 2. Immutable preflight

Before executing any packaged binary:

1. Retrieve artifact `10378808176` from compile run `34923091581`; require provider digest `sha256:a60fbbb7127b2fb36952cc9fef8d58cce366204ffbcbdcd7ace2de69ff7e488a`.
2. Extract once into a fresh execution directory. Run `sha256sum -c SHA256SUMS` there and require all **28** self-excluding manifest members to verify; `SHA256SUMS` itself must not appear in the manifest.
3. Require `metadata/source-commit.txt` to equal `905dabe390577d63ed6a9289e3f3d53aa4144936`; require all packaged source-status receipts empty and `metadata/build-exit-code.txt` plus `metadata/preflight-exit-code.txt` equal `0`.
4. Require `metadata/command-boundary.txt` to record `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`; require `metadata/gmp-evidence.txt` to show GMP and GMPXX linkage.
5. Verify the frozen selector423 authority is exactly **423 LF rows**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; verify first422 SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`. Do not regenerate or rediscover this selector.
6. Verify each selector owner binary required by the frozen manifest exists in the package. A missing binary, digest mismatch, source mismatch, nonempty source receipt, wrong selector hash/count, or failed manifest member is orchestration/evidence failure and STOP, never a semantic PASS/SKIP.

## 3. Preinitialize complete result ledger

Before focused runtime, materialize the complete selector423 ledger in frozen file order with every row set to `UNEXECUTED`. Record at minimum ordinal, exact test identity, owner executable, state, process exit code, selected-test count, and evidence/log path. This ledger must survive every early exit.

Also create an immutable preflight/postflight record containing candidate artifact ID/digest, semantic source, selector423 count/hash, first422 hash, execution-directory file census/digests, and `runtimeExecution=true` for this TB execution only. Materialize packaged source `benchmarks/fixtures` exactly at `view/test-data/benchmarks/fixtures`; before any Directional process starts, require the copied fixture subtree to match source relative paths, bytes, modes and symlink targets. Produce `package-census-before.tsv`, `source-census-before.tsv`, and `execution-view-census-before.tsv` through the same shared naming authority postflight later consumes. No source checkout/build tree may become runtime authority.

## 4. Focused S2 execution — mandatory first gate

Execute exactly one fresh process from the packaged producer-test executable with exact filter:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

Requirements:

- selected-test count must be exactly **1**; zero or multiple selected tests is orchestration failure;
- preserve stdout/stderr and process exit status;
- no retry of a deterministic RED;
- the test's own CB4 guards must naturally prove the regular folded-star preconditions before comparator semantics and its six-subject oracle must naturally exercise both `Filter` and `ExactFallback`; do not infer these receipts from compile-time source inspection during TB.

If focused S2 is not a clean 1/1 PASS, leave every selector423 row `UNEXECUTED`, execute no selector row, run immutable postflight, preserve the full ledger, and STOP for `M4-CP-SCALE-TB4-REV`.

## 5. Selector423 execution after focused PASS

Only after focused S2 passes:

1. Traverse the frozen selector423 in exact row order.
2. For each row, launch exactly one fresh process of its pre-authored owner executable with the exact single-test filter from the selector. Do not use `--gtest_list_tests`, CTest discovery, wildcard expansion, suite discovery, or a combined process.
3. Update that row exactly once from `UNEXECUTED` to its observed terminal state and record selected-test count and process exit. Each row must select exactly one test.
4. Continue through all 423 rows unless the frozen harness has an already-authorized fail-closed infrastructure stop; semantic RED is preserved as RED and is not repaired/retried in TB.
5. Execute no benchmarks. The packaged benchmark binary is evidence of compile coverage only for this checkpoint.

## 6. Immutable postflight

After focused failure or completed selector execution:

- rerun `sha256sum -c SHA256SUMS`;
- re-record source identity, selector423 count/hash, first422 hash, and the matching `package/source/execution-view-census-after.tsv` receipts;
- require package/source/selector identity to match preflight exactly except for separately stored runtime logs/ledgers outside the immutable extraction;
- preserve the focused log, complete 423-row ledger, aggregate counts, and postflight record in the TB result artifact;
- upload a separate persistent diagnostic log under `if: always()`.

Evidence-upload failure prevents a GREEN conclusion even when all runtime processes passed.

## 7. Mechanical acceptance criteria

`M4-CP-SCALE-TB4-R1-EXEC` is mechanically GREEN only if all are true:

- immutable preflight passes;
- focused S2 is exactly **1/1 PASS**;
- selector423 is exactly **423/423 PASS**, with zero RED/SKIP/timeout/crash/selection mismatch/UNEXECUTED rows;
- each row ran once in a fresh exact-filter process;
- immutable postflight matches preflight;
- result and diagnostic artifacts upload successfully.

This is a **fresh retry**: no focused or selector outcome from invalid run `34938070127` may be imported, skipped, or used to short-circuit a process. Mechanical GREEN does **not** promote the candidate. Mechanical RED/failure does not authorize a repair here. In either case exact successor is `M4-CP-SCALE-TB4-REV`.

## 8. STOP rules

STOP and preserve evidence without mutation if any of these occurs:

- artifact/source/manifest/selector authority mismatch;
- focused test selects zero/multiple identities, crashes, times out, or is RED;
- any action would require rebuild, relink, source/test/fixture/build edit, generated-test discovery, selector change, or benchmark execution;
- immutable extraction changes across execution;
- result/log evidence cannot be preserved.

Do not weaken an assertion, alter a tolerance, hand-author expected comparator output, classify/promo a candidate, or change stable accounting in TB4-R1-EXEC.

## 9. Required handoff evidence

The TB4-R1-EXEC report must name exact run/job IDs, candidate artifact/digest/source, focused result, complete selector423 counts and ledger artifact, immutable pre/postflight status, any first actionable failure, and whether every required result/log artifact was preserved. The next turn is always `M4-CP-SCALE-TB4-REV`.
