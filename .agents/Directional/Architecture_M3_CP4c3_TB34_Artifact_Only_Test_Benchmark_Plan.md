# M3-CP4c-3-TB34 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M3-CP4c-3-TB34`
- Execution split: **`TB34-EXEC` -> independent `TB34-REV`**
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `7711b9c2c20d284823911aa4ca067bd33244f4e6`
- Build run/job: `34061111130 / 101561719362`
- Immutable artifact: `9997560649` / `m3-cp4c3-cb39-result-34061111130`
- Provider/download ZIP SHA-256: `9a71fe17b789c94f70580116b822b3949dabecda7bf1d736afef10a1e6a9c3d2`
- Packaged source archive SHA-256: `c0005445a764dda63a2fa2c6c30e512f26aabe84f944f23cde078046b4bf0fc7`
- Selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt`
- Selector count/SHA-256: **409** / `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`
- Artifact-only harness: `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`
- Packaged harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`
- Accepted prefix: **1–365**
- Benchmark execution: **N/A / prohibited in TB34**

## Objective

Execute selector 409 against the immutable CB39 package without rebuilding, repairing, or mutating it. TB34 must determine whether the narrow boundary-walk correction behaves exactly as frozen by TB33-REV.

The runtime questions are:

1. **409 hard negative:** does `GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` PASS, proving two node-disjoint loops remain rejected as `ArcChainBroken`?
2. **366/367 diagnosis:** do the frontier rows clear `RegionBoundaryNotSingleWalk`, or if they remain there, which typed reason fired?
3. **Monotonicity:** do 366/367 stay at the same or a later legitimate stage, never an earlier stage?
4. **Protected greens:** do 390/393/404/406/407/408 remain PASS with their contracts unchanged?
5. **Carried surfaces:** do 368/369/370/374/398 remain semantically credible, with any change preserved rather than re-scoped inside EXEC?
6. **Retired guards and ownership:** do both retired codes remain absent and certified ownership remain 300 established / 0 unavailable / 0 conflicting whenever publication reaches that stage?
7. **Accepted prefix and provenance:** do identities 1–365 remain 365/365 PASS, all 409 rows select exactly one test, and all package/source/execution-view bytes and modes remain unchanged?

No aggregate PASS/RED total is pre-assumed beyond the accepted prefix and the explicit protected-green/409 requirements. TB34-EXEC preserves raw facts only. Semantic/root-cause adjudication belongs to independent TB34-REV.

## Immutable preflight and execution mechanism

TB34-EXEC must use the packaged CB39 harness directly in `--execute` mode. Do not author a replacement harness or generate test discovery. The workflow supplies:

```text
TURN_ID=M3-CP4c-3-TB34-EXEC
ARTIFACT_ID=9997560649
EXPECTED_ARTIFACT_NAME=m3-cp4c3-cb39-result-34061111130
EXPECTED_PROVIDER_DIGEST=sha256:9a71fe17b789c94f70580116b822b3949dabecda7bf1d736afef10a1e6a9c3d2
EXPECTED_ZIP_SHA256=9a71fe17b789c94f70580116b822b3949dabecda7bf1d736afef10a1e6a9c3d2
EXPECTED_SOURCE_SHA=7711b9c2c20d284823911aa4ca067bd33244f4e6
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt
EXPECTED_SELECTOR_COUNT=409
EXPECTED_SELECTOR_SHA256=eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e
ACCEPTED_PREFIX_COUNT=365
```

`GITHUB_REPOSITORY`, the executing `GITHUB_RUN_ID`, and `GH_TOKEN` come from the TB34 workflow environment. Execute exactly:

```sh
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

### Preflight requirements

Fail closed before any Directional runtime unless all of these hold:

- artifact ID/name/provider digest and independently downloaded ZIP SHA match the frozen values;
- root `SHA256SUMS` verifies completely;
- `metadata/source-commit.txt` equals the evidence source;
- compile preflight/build exits are zero;
- command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `preflightCompile=true`;
- GMP evidence includes `DIRECTIONAL_ENABLE_GMP=ON`, `gmpxx`, and `gmp`;
- packaged test executables exist with archived executable mode bits intact;
- packaged selector count/hash are exact and selector 408 is the exact first 408 lines;
- static source mapping gives exactly one owning binary per selector identity without generated discovery;
- package, packaged-source, and disposable execution-view byte+mode censuses are captured before runtime.

Do not use Python `zipfile.extractall` for executable payloads. Do not `chmod`, repair, repack, configure, compile, relink, regenerate discovery, mutate source/tests/fixtures/selectors, or substitute a new artifact.

## TB34-EXEC ordered runtime contract

### 1. Execute all 409 identities exactly once

The packaged harness executes each selector identity in ordinal order, one fresh process and fresh working directory per row, with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, static owner resolution, `/usr/bin/time -v`, and the existing 180-second focused per-identity timeout.

A semantic RED never stops later rows and is never retried. Zero/multiple selected tests, timeout, incomplete ledger, or immutability mismatch is orchestration failure, not semantic evidence. Do not wrap the complete 409-row execution in a shorter repository/job watchdog.

### 2. Hard semantic checks

Retain complete raw logs and failure-detail files for at least:

`366,367,368,369,370,374,390,393,398,404,406,407,408,409`

Required outcomes:

- **409: PASS.** Any RED means the CB39 correction weakened the real chain guard and is a hard falsifier.
- **390,393,404,406,407,408: PASS.** They were explicitly outside CB39 ownership and must remain green.
- **Retired-code silence:** zero raw logs may contain `TraceArcDoesNotSeparateItsSides` or `UncutFaceComponentOrbitSeedNotUnique`.
- **366/367 monotonicity:** neither may move to a stage earlier than the TB33 `RegionBoundaryNotSingleWalk` frontier. PASS or a later legitimate stage is admissible raw evidence.
- If 366/367 still fail `RegionBoundaryNotSingleWalk` with `regionBoundaryWalkReason=ArcChainBroken`, preserve it as the frozen falsifier: the TB33 diagnosis was wrong and the defect is upstream in boundary assembly.
- If 366/367 clear that rejection and later fail while publishing `regionBoundaryWalkReason=ClosedBeforeEnd`, preserve the later failure plus that non-rejecting evidence; this supports the CB39 diagnosis but does not itself close the checkpoint.
- **368/369/370/374/398:** preserve every change exactly. CB39 did not own these rows; unexpected PASS/failure-surface changes are review evidence, not permission to alter the gate inside EXEC.
- Whenever certified ownership publishes, require **300 established / 0 unavailable / 0 conflicting**.

### 3. Boundary-walk reason evidence

For every focused RED with boundary-walk data, transcribe/check:

- `regionBoundaryWalkReason` exactly (`ArcChainBroken`, `ClosedBeforeEnd`, or `WalkNotClosed`);
- existing `regionFrontierFailureStage` and complete plan/certifier correspondence when present;
- rejection code and arc identity;
- absence/presence of legacy `uncutFaceComponent*` fields under the already-approved stage contract.

`ClosedBeforeEnd` is evidence only. A result that rejects solely because `ClosedBeforeEnd` was observed falsifies CU4/CU5.

### 4. Failure-detail provenance

Retain the established TB33 provenance contract unchanged:

- historical `ledger.tsv` columns remain unchanged;
- `failure-detail-digests.tsv` has exactly 409 data rows plus header;
- every PASS detail is exactly `PASS\n` and every RED detail hash matches retained bytes;
- the table SHA verifies;
- each RED detail contains the complete GoogleTest failure block or explicit `PROCESS_FAILURE` fallback;
- `baseline-authority.txt` names `M3-CP4c-3-TB34-EXEC run=<executing GITHUB_RUN_ID>` and the exact artifact/source/selector identities.

**Hard report requirement:** TB34-EXEC must transcribe the retained failing assertion/exception detail for every RED ordinal in the focused index above. Missing focused transcription makes EXEC incomplete.

### 5. Accepted-prefix and postflight integrity

Require:

- identities 1–365 = **365/365 PASS**;
- all 409 rows present, ordinal sequence exact, `selected=1`, zero timeouts;
- selector 409 bytes unchanged and 408 exact prefix preserved;
- no source/test/fixture/selector/build mutation;
- no configure, compile, relink, repair, generated discovery, or benchmark execution;
- package/source/execution-view byte+mode censuses exactly equal pre/post.

## Required EXEC evidence

Preserve and upload the complete harness result directory plus persistent workflow log, including artifact/environment/selector authority, root checksum validation, static identity map, all 409 raw logs and failure details, ledger and failure-detail digests, resource logs/summary, semantic summary, executing-run baseline authority, pre/post censuses, immutability result, and execution-boundary record.

The EXEC report records raw evidence only and must not change product/test/fixture/selector/build logic or stable regression accounting.

## Benchmark plan

**No benchmark execution.** `directional_benchmarks` is integrity-censused only. Performance/quality gates are outside TB34's frozen semantic scope.

## Stop and rerun rules

- Any preflight, artifact authority, executable mode, selection-count, timeout, digest, completeness, or immutability defect => **ORCHESTRATION FAILURE**, no semantic verdict; do not repair immutable bytes.
- Semantic RED => preserve and continue remaining selector rows; **no semantic retry**.
- Accepted-prefix RED, protected-green RED, 409 RED, retired-code emission, or 366/367 earlier-stage movement => preserve as a hard semantic falsifier; do not change scope inside EXEC.
- Do not rebuild inside TB34. Any implementation/test/harness correction routes only after independent review.

## Closeout and independent-review boundary

TB34-EXEC must update the required Test + Benchmark evidence surfaces and regression/root-cause tracker before its turn can close. Once raw evidence, required transcriptions, handoff/TODO, and temporary-state cleanup are complete, the exact next boundary is **`M3-CP4c-3-TB34-REV`**.

`TB34-REV` is explicitly outsourced to an independent agent. The implementation/orchestration loop must **stop completely** at that boundary. No successor CB, new runtime, or acceptance claim may be authorized before independent review.
