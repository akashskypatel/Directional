# M3-CP4c-3-TB33 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M3-CP4c-3-TB33`
- Execution split: **`TB33-EXEC` -> independent `TB33-REV`**
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `0d03edb07388c56b592a74e2e7fc5f3edde8cea4`
- Build run/job: `34052395109 / 101538234734`
- Immutable artifact: `9994997588` / `m3-cp4c3-cb38-result-34052395109`
- Provider/download ZIP SHA-256: `059f40350b0acdc885e77523668ff6b50708fc802d910b257ba278d54444f8d8`
- Packaged source archive SHA-256: `092b3a5b81894ce15d1c767d41399fc72e65cd72f2400c0e7ff4c6970300c0e0`
- Selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_408.txt`
- Selector count/SHA-256: **408** / `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`
- Artifact-only harness: `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`
- Packaged harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`
- Accepted prefix: **1–365**
- Benchmark execution: **N/A / prohibited in TB33**

## Objective

Execute the unchanged selector 408 against the immutable CB38 package and determine whether CT3–CT6 behave as designed without rebuilding or repairing anything.

The runtime questions are:

1. **390/393/406/407:** do the retained gating witnesses now PASS under the justified cleared-stage contract?
2. **Stage integrity:** does a later region failure publish `RegionConstruction` or `RegionCertification` frontier evidence without any legacy seed-stage `uncutFaceComponent*` back-fill?
3. **Retired guards:** do `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique` remain absent from every raw log?
4. **366/367 monotonicity:** do they remain at `RegionBoundaryNotSingleWalk`, advance later, or pass — but never move to an earlier stage?
5. **Credibility controls:** do 368/369/370/374/398 retain their carried RED surfaces, since CB38 did not own them?
6. **Evidence provenance:** does the new failure-detail digest distinguish RED semantics, and does `baseline-authority.txt` identify the executing TB33 run rather than a copied predecessor run?
7. **Accepted prefix:** do identities 1–365 remain **365/365 PASS** with one selected test per row?

No aggregate total is pre-assumed beyond the accepted prefix. EXEC preserves raw evidence; semantic/root-cause adjudication belongs to independent TB33-REV.

## Immutable preflight and execution mechanism

TB33-EXEC must use the packaged CB38 harness directly. Do not author another copy by search/replace. Run it once in `--execute` mode; that mode performs the full fail-closed immutable preflight **before** starting any Directional runtime, then runs all selector rows and performs postflight.

The workflow supplies these immutable inputs:

```text
TURN_ID=M3-CP4c-3-TB33-EXEC
ARTIFACT_ID=9994997588
EXPECTED_ARTIFACT_NAME=m3-cp4c3-cb38-result-34052395109
EXPECTED_PROVIDER_DIGEST=sha256:059f40350b0acdc885e77523668ff6b50708fc802d910b257ba278d54444f8d8
EXPECTED_ZIP_SHA256=059f40350b0acdc885e77523668ff6b50708fc802d910b257ba278d54444f8d8
EXPECTED_SOURCE_SHA=0d03edb07388c56b592a74e2e7fc5f3edde8cea4
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_408.txt
EXPECTED_SELECTOR_COUNT=408
EXPECTED_SELECTOR_SHA256=2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6
ACCEPTED_PREFIX_COUNT=365
```

`GITHUB_REPOSITORY`, the **executing** `GITHUB_RUN_ID`, and `GH_TOKEN` come from the TB33 workflow environment. The command is:

```sh
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

The harness itself must be read from the extracted packaged source and its SHA-256 must equal the frozen value above before execution.

### Preflight requirements

The harness must fail closed before runtime unless all of these hold:

- GitHub artifact ID/name/provider digest and independently downloaded ZIP SHA match the frozen values;
- root `SHA256SUMS` verifies completely;
- `metadata/source-commit.txt` equals the evidence source;
- compile preflight and build exits are zero;
- command boundary contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- GMP evidence includes `DIRECTIONAL_ENABLE_GMP=ON`, `gmpxx`, and `gmp`;
- required test executables exist with preserved executable mode bits;
- packaged selector count/hash are exact;
- static source mapping gives exactly one owning binary per selector identity without generated discovery;
- package, packaged-source, and disposable execution-view byte+mode censuses are recorded before runtime.

Do not use Python `zipfile.extractall` to materialize executable payloads. Do not `chmod`, repair, repack, configure, compile, relink, regenerate discovery, mutate source/tests/fixtures/selectors, or substitute a new artifact.

## TB33-EXEC ordered runtime contract

### 1. Execute all 408 identities exactly once

The packaged harness executes each selector identity in ordinal order, one fresh process and fresh working directory per row, using only the statically resolved packaged owner. It enforces `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, counts `[ RUN      ]`, records `/usr/bin/time -v`, and uses the existing **180-second per-identity focused timeout**.

A semantic RED does **not** stop later rows and is never retried. A selection count other than one, a timeout, incomplete ledger, or pre/post immutability mismatch is orchestration failure, not semantic evidence.

The complete 408-row execution itself must not be wrapped in a repository/job watchdog intended to terminate the suite early.

### 2. Hard semantic checks

Retain complete raw logs and failure-detail files for at least the focused index:

`366,367,368,369,370,374,390,393,398,406,407`

Required outcomes:

- **390, 393, 406, 407: PASS.** If any remains RED while its stage-labelled frontier evidence is complete, the TB32-REV re-scoping is falsified and EXEC must preserve that fact unchanged for review.
- **Retired-code silence:** zero raw logs may contain `TraceArcDoesNotSeparateItsSides` or `UncutFaceComponentOrbitSeedNotUnique`. Any emission is a hard semantic falsifier.
- **366/367 monotonicity:** neither may fail at a stage earlier than `RegionBoundaryNotSingleWalk`. PASS or a later legitimate stage is admissible raw evidence; EXEC does not adjudicate it.
- **368/369/370/374/398 credibility:** preserve any change exactly. CB38 did not own these rows, so an unexpected PASS or changed failure surface is review evidence, not permission to re-scope them.
- **Certified ownership:** whenever publication reaches that stage, require **300 established / 0 unavailable / 0 conflicting**.

### 3. Stage-labelled frontier evidence

For 390/393/406/407 and any focused RED that publishes region-frontier data, transcribe/check:

- `regionFrontierFailureStage`;
- `regionFrontierComponentCount`, complete rows, `regionFrontierComponentsTruncated=false`;
- plan component/partition identity/face-set digest;
- certifier `censusCorrespondence`, component identity/digest, and subset flag;
- whether legacy `uncutFaceComponent*` seed fields are present.

Admissible CT4 branches:

- `UncutComponent`: all legacy identity-owned seed evidence remains complete and untruncated; or
- `RegionConstruction` / `RegionCertification`: complete labelled frontier correspondence evidence is present **and all legacy seed-stage `uncutFaceComponent*` fields are absent/default**.

Absence of both evidence surfaces is RED, not a cleared-stage PASS.

### 4. Failure-detail provenance — CT5/CT7

Require:

- `ledger.tsv` retains exactly the historical columns `ordinal identity binary exit selected result raw_log`;
- `failure-detail-digests.tsv` has exactly 408 data rows plus header and columns `ordinal identity result detail_sha256 detail_file`;
- every PASS detail file is exactly `PASS\n` and hashes accordingly;
- every RED detail hash matches its retained `failure-details/ordinal-NNN.txt` bytes;
- `failure-detail-digests.sha256` verifies the table;
- each RED detail contains the complete GoogleTest `: Failure` block(s), or the explicit `PROCESS_FAILURE` fallback when no assertion block exists;
- `baseline-authority.txt` contains `M3-CP4c-3-TB33-EXEC run=<executing GITHUB_RUN_ID>` and the exact artifact/source/selector identities; a predecessor run ID is orchestration-invalid provenance.

**Hard report requirement:** the TB33-EXEC closeout report must transcribe the retained failing assertion or exception detail for **every RED ordinal in the focused index above**. It may link the detail files for other REDs, but it may not omit a focused RED's text. Missing transcription makes the EXEC report incomplete and prevents advancing to review.

### 5. Accepted-prefix and postflight integrity

Require:

- identities 1–365 = **365/365 PASS**;
- all 408 rows present, ordinal sequence exact, `selected=1`, zero timeouts;
- selector bytes unchanged;
- no source/test/fixture/selector/build mutation;
- no configure, compile, relink, repair, generated discovery, or benchmark execution;
- package/source/execution-view byte+mode censuses exactly equal pre/post.

## Required EXEC evidence

Preserve and upload the complete harness result directory plus the persistent TB workflow log. At minimum it contains:

- `artifact-authority.txt`, `environment.txt`, `selector-authority.txt`;
- root `sha256sums-check.txt` and runtime executable hash/mode/size census;
- static `identity-map.tsv` + hash;
- all 408 `raw/ordinal-NNN.log` files;
- all 408 `failure-details/ordinal-NNN.txt` files;
- `ledger.tsv` + `ledger.sha256`;
- `failure-detail-digests.tsv` + its SHA-256;
- all resource logs + `resource-summary.tsv` + hash;
- `semantic-summary.txt` with exact PASS/RED list and accepted-prefix result;
- `baseline-authority.txt` with the executing run ID;
- package/source/execution-view pre/post censuses and `immutability.txt`;
- `execution-boundary.txt` showing runtime started/completed and all forbidden build/repair/mutation/benchmark flags false.

The TB33-EXEC report records raw evidence only. It must not change product/test/fixture/selector/build logic or classify stable regression accounting.

## Benchmark plan

**No benchmark execution.** `directional_benchmarks` is integrity-censused only. Performance/quality gates are outside TB33's frozen semantic scope.

## Stop and rerun rules

- Preflight failure, selector-owner ambiguity, zero/multiple selected tests, timeout, missing executable mode, incomplete result set, digest mismatch, or mutable census mismatch => **ORCHESTRATION FAILURE**, no semantic verdict. Diagnose orchestration only; do not repair immutable artifact bytes.
- Semantic RED => preserve and continue remaining selector identities; **no semantic retry**.
- Accepted-prefix RED => preserve it as a blocking semantic regression; continue raw collection unless infrastructure prevents safe completion.
- Any retired-code emission or 366/367 earlier-stage movement => preserve as a hard falsifier; do not alter scope inside EXEC.
- Do not rebuild inside TB33. Any required implementation/test/harness correction routes to a later Code + Build turn after independent review.

## Closeout and independent-review boundary

TB33-EXEC must update the required Test + Benchmark durable evidence surfaces, including `Regression_Root_Cause_Tracker.md` classification for every observed regression/candidate before the TB turn can close. Once its raw evidence, required assertion transcriptions, regression documentation, handoff/TODO, and temporary-state cleanup are complete, the exact next boundary is **`M3-CP4c-3-TB33-REV`**.

`TB33-REV` is explicitly outsourced to an independent agent. The implementation/orchestration loop must **stop completely** at that boundary. No successor CB, new runtime, or acceptance claim may be authorized before independent review.
