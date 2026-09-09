# M3-CP4c-3-TB48 Artifact-Only Test + Benchmark Plan

## Status

**FROZEN BY CB54 / EXACT NEXT = `M3-CP4c-3-TB48-EXEC` / IMMUTABLE PACKAGE113 ONLY**

Execution subturn: **TB-EXEC**. Raw runtime execution/evidence collection only. Interpretation, promotion, stable
repricing, corrective planning and checkpoint-closure judgment belong to independent **`M3-CP4c-3-TB48-REV`**.

No benchmark command is authorized by this checkpoint plan; “Test + Benchmark” names the canonical turn boundary.

## 1. Immutable authority

- repository: `akashskypatel/Directional`;
- semantic source: **`6dae3f6959551f6dcdd81f153aedb5f38411a96b`**;
- package113 result artifact ID: **`10125000895`**;
- artifact name: `m3-cp4c3-cb54-package113-result-34404928469`;
- required artifact SHA-256: **`e5fb50f92bbf4c4ffae5afeb203d6738490f6410b3a7e49245607e1b2e7835e9`**;
- compile run/package job: `34404928469 / 102645952921`;
- selector409 SHA-256: **`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`**;
- generic artifact-only harness SHA-256:
  **`aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`**;
- accepted gating prefix: **1–365**.

Package112/TB47 is the comparison/runtime baseline, not executable authority for TB48.

## 2. Preflight — fail closed before runtime

1. Download artifact **10125000895 exactly once** and verify the downloaded ZIP SHA-256 equals the required artifact
   digest above. A mismatch is orchestration failure; do not retry semantic runtime from altered bytes.
2. Extract with ordinary `unzip`/`tar` semantics that preserve archived executable mode bits. **Do not use Python
   `zipfile.extractall` for executable payloads and do not `chmod` or otherwise repair the immutable package.** A
   missing executable mode is orchestration failure.
3. Verify the package root `SHA256SUMS` **28/28** before executing anything.
4. Verify package metadata states:
   - `source-commit.txt = 6dae3f6959551f6dcdd81f153aedb5f38411a96b`;
   - `runtimeExecution=false` for the build;
   - `exactArithmeticBackend=GMP` and authoritative `gmpxx` + `gmp` link evidence;
   - clean source-status evidence;
   - packaged source archive SHA-256
     `321d123d09d5ef65defb76d8361e800dd787628a2b571c6b7d3fd8588f28e730`.
5. Recompute and verify selector409 and generic-harness SHA-256 values from packaged bytes.
6. Verify required executable files already carry executable mode from the archive. Do not repair mode/content.
7. Record a complete immutable pre-runtime census of package files, sizes, modes and SHA-256 values plus selector
   membership/order.
8. Prove no configure/compile/relink/regeneration/build tool is invoked in the TB workload. A zero-selected filter is
   orchestration failure, never PASS.

Any preflight failure stops TB48-EXEC with **no semantic result** and routes to control-plane correction. Do not
rebuild a replacement package inside Test + Benchmark.

## 3. Exact execution contract

Use packaged `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh` in execute mode and the packaged selector409
without changing either file.

Required semantics:

1. execute **all 409 identities exactly once in ordinal order**;
2. use one fresh process and fresh working directory per identity;
3. retain the established focused per-identity control **`timeout -k 5s 180s`**;
4. impose **no outer elapsed cutoff, no suite-level timeout, and no workflow/job timeout whose purpose is to kill the
   complete selector run**;
5. accepted ordinals **1–365** are gating; after the first RED, every remaining identity still executes report-only
   with **zero gate credit**;
6. preserve stdout/stderr, exit code, elapsed/resource data, typed failure fields and per-identity logs;
7. execute no benchmark, discovery/list/help/version, `ctest`, configure, compile, relink, fixture generation,
   permission repair or package mutation command.

## 4. Mechanical acceptance

A TB48 execution is mechanically valid only when all of the following hold:

- package/selector/harness/source hashes match preflight authority;
- root package manifest verifies before and after runtime;
- **409/409** selector identities execute exactly once with no selection mismatch;
- no process is silently skipped; timeout count is zero for semantic acceptance;
- package/source/fixture/selector bytes and executable modes are unchanged by postflight census;
- build/configure/repair/mutation flags remain false;
- accepted-prefix accounting is derived from actual process results, not synthesized;
- result and diagnostic-log artifacts are both uploaded and their IDs/digests recorded.

A timeout, selection mismatch, missing artifact, altered census or execution-permission defect is orchestration failure,
not a semantic RED/PASS.

## 5. Falsifiable CB54 semantic prediction

This is a prediction to test, **not an acceptance shortcut**:

- ordinal **370** changes from TB47 RED to **PASS** by observing existing
  `SurfaceCutGraphErrorCode::EmptyNetworkOnClosedSurface = 6` and a non-empty deterministic `sourceFace` locus;
- no other identity changes;
- aggregate becomes **405 PASS / 4 RED / 0 SKIP**;
- RED set becomes **`[368,369,374,398]`**;
- accepted prefix remains **365/365**;
- ordinal367 remains PASS;
- protected 390/393/406/407 remain PASS and non-vacuous;
- ownership remains **300 established / 0 unavailable / 0 conflicting** unless runtime evidence proves otherwise.

A different semantic vector is still valid evidence if the mechanical gate is valid. **Do not weaken a test, patch the
package, rerun a different build, or reinterpret the oracle to obtain the prediction.** Preserve the first actionable
difference for review.

## 6. Evidence to preserve

TB48-EXEC must retain at minimum:

- exact workflow run ID and execute job ID;
- result artifact ID/name/SHA-256 and diagnostic-log artifact ID/name/SHA-256;
- package artifact ID/name/SHA-256 and exact semantic source;
- selector409 and harness hashes;
- preflight/postflight immutable censuses and package-manifest verification;
- executed identity count/order, PASS/RED/SKIP totals, RED ordinals, accepted-prefix count;
- selection mismatch and timeout counts;
- ownership totals and protected-control results;
- ordinal370 raw log/typed failure evidence including error code and locus;
- every build/configure/relink/repair/mutation/benchmark flag proving the artifact-only boundary.

Every observed regression/candidate must be recorded in `Regression_Root_Cause_Tracker.md` before the canonical Test
+ Benchmark turn can close. **TB-EXEC itself records raw evidence and leaves interpretation/classification to
TB48-REV.**

## 7. Stop / rerun rules

- **Mechanical preflight/execution failure:** stop; preserve evidence; no semantic promotion/repricing; correct only
  orchestration in the proper boundary before another execution.
- **Mechanically valid semantic result, prediction met or falsified:** stop after evidence packaging. Do not rerun to
  seek a different vector.
- **No source/test/fixture/selector/build-logic edit and no replacement compile is permitted in TB48-EXEC.**
- Exact next after a mechanically valid TB48-EXEC is independent **`M3-CP4c-3-TB48-REV`**.
- Independent review decides package113 promotion, ordinal370 closure, regression accounting and whether formal
  CP4c-3 closure follows from the already-met AU0–AU9 mechanical criterion.
