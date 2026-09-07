# M3-CP4c-3-TB35 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M3-CP4c-3-TB35`
- Execution split: **`TB35-EXEC` -> independent `TB35-REV`**
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `23a753a83f0eda0447172ce96bcd3180bf95ae8a`
- Build run/job: `34080675952 / 101615243724`
- Immutable artifact: `10003613409` / `m3-cp4c3-cb40-result-34080675952`
- Provider/download ZIP SHA-256: `bb5ee6afc1601d8d339d4fbdba32596e7b9a72b747f1510e4221b54d0776b94f`
- Packaged source archive SHA-256: `56dc4a0ba09797bb08374abc15d4eaf472d19bcd8bcfa5d2ca3db361182257b4`
- Selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt`
- Selector count/SHA-256: **409** / `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`
- Selector 408 prefix SHA-256: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`
- Artifact-only harness: `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`
- Packaged harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`
- Accepted prefix: **1–365**
- Benchmark execution: **N/A / prohibited in TB35**

## Objective

Execute selector 409 against the immutable CB40 package without rebuilding, relinking, repairing, regenerating discovery, or mutating package/source/test/fixture/selector bytes. TB35 must determine whether CV2/CV3 restored the accepted boundary contract and whether the real 366/367 frontier is exposed consistently.

The runtime questions are:

1. **312 hard recovery gate:** does `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks` PASS again, restoring accepted 1–365 to **365/365**?
2. **409 hard fixture/oracle gate:** does `GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` reach the re-aimed shared-node multi-walk and PASS with `RegionBoundaryNotSingleWalk` / `ClosedBeforeEnd`?
3. **366/367 discriminator:** after the restored earlier rejection, do they return to `RegionBoundaryNotSingleWalk` with `ClosedBeforeEnd`, or report `ArcChainBroken` instead?
4. **Protected greens:** do 390/393/404/406/407/408 remain PASS?
5. **Carried surfaces:** do 368/369/370/374/398 remain credible without any scope weakening inside EXEC?
6. **Retired guards and ownership:** do both retired codes remain absent and ownership remain 300 established / 0 unavailable / 0 conflicting whenever published?
7. **Provenance:** do all 409 identities execute exactly once from immutable artifact `10003613409`, with exact selector bytes and unchanged pre/post censuses?

TB35-EXEC preserves raw facts only. Candidate/root-cause promotion belongs to independent TB35-REV.

## Immutable preflight

Use the packaged CB40 harness directly in `--execute` mode. Supply:

```text
TURN_ID=M3-CP4c-3-TB35-EXEC
ARTIFACT_ID=10003613409
EXPECTED_ARTIFACT_NAME=m3-cp4c3-cb40-result-34080675952
EXPECTED_PROVIDER_DIGEST=sha256:bb5ee6afc1601d8d339d4fbdba32596e7b9a72b747f1510e4221b54d0776b94f
EXPECTED_ZIP_SHA256=bb5ee6afc1601d8d339d4fbdba32596e7b9a72b747f1510e4221b54d0776b94f
EXPECTED_SOURCE_SHA=23a753a83f0eda0447172ce96bcd3180bf95ae8a
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt
EXPECTED_SELECTOR_COUNT=409
EXPECTED_SELECTOR_SHA256=eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e
ACCEPTED_PREFIX_COUNT=365
```

Execute exactly:

```sh
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

Fail closed before Directional runtime unless all of these hold:

- artifact ID/name/provider digest and independently downloaded ZIP SHA match;
- root `SHA256SUMS` verifies **28/28**;
- `metadata/source-commit.txt` is the evidence source;
- preflight/build exits are zero and all eight compiled targets are present;
- command boundary says `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- GMP evidence contains `DIRECTIONAL_ENABLE_GMP=ON`, `gmpxx`, and `gmp`;
- selector count/hash are exact, and selector 408 is the exact frozen prefix;
- packaged harness SHA-256 is exact;
- static source mapping resolves exactly one owning binary per selector identity without generated discovery;
- package, packaged-source, and disposable execution-view byte+mode censuses are captured before runtime.

Do not chmod/repair/repack/configure/compile/relink/regenerate discovery/mutate immutable bytes or substitute another artifact.

## TB35-EXEC ordered runtime contract

### 1. Execute all 409 identities exactly once

Run each selector identity in ordinal order using the existing packaged harness: one fresh process and working directory per row, `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, static owner resolution, `/usr/bin/time -v`, and the established 180-second focused per-identity timeout.

Semantic RED does not stop later rows and is not retried. Zero/multiple selection, timeout, incomplete ledger, preflight failure, or immutability failure is **orchestration failure**, not semantic evidence.

### 2. Hard recovery and protection gates

Retain complete raw logs/failure details for at least:

`312,366,367,368,369,370,374,390,393,398,404,406,407,408,409`

Required outcomes:

- **312: PASS.** Any RED means CV2 is incomplete. Preserve evidence and stop semantic promotion; do not edit the witness.
- **Accepted prefix 1–365: 365/365 PASS.** Any accepted RED is a hard regression.
- **409: PASS and reach its semantic oracle.** It must exercise the re-aimed shared-node multi-walk and require `RegionBoundaryNotSingleWalk` with `regionBoundaryWalkReason=ClosedBeforeEnd`. Fixture-construction/precondition failure is a hard CV3 falsifier, not a semantic PASS.
- **390/393/404/406/407/408: PASS.** Nothing they own was authorized to change.
- **Retired-code silence:** no raw log may emit `TraceArcDoesNotSeparateItsSides` or `UncutFaceComponentOrbitSeedNotUnique`.
- Whenever ownership publishes, require **300 established / 0 unavailable / 0 conflicting**.

### 3. 366/367 frontier discriminator

For both ordinals preserve rejection code, typed boundary reason, frontier stage, region/arc locus, and complete failure detail.

Interpret raw outcomes only as evidence for TB35-REV:

- `RegionBoundaryNotSingleWalk` + `ClosedBeforeEnd` => TB34's pinch reading is runtime-supported and the next frontier remains `M3-CP4c3-TB34-REV-CAND-03` (non-disc plan region).
- `ArcChainBroken` => the pinch interpretation is wrong; preserve as review-owned falsifier.
- An earlier stage than the TB34 boundary/certification frontier => hard monotonicity regression.
- PASS or a different later failure => preserve without re-scoping; independent review owns interpretation.

**Do not attempt to make 366/367 green in EXEC.** Their product defect is diagnosed, not patched.

### 4. Carried RED surfaces

For 368/369/370/374/398 preserve every change exactly. No expectation or gate may be weakened during EXEC. In particular ordinal 398 remains outside CB40 ownership.

### 5. Evidence integrity

Preserve the existing harness evidence contract:

- 409 ledger data rows, exact ordinal order, `selected=1`, zero timeout;
- failure-detail digest table covers all 409 rows;
- each PASS detail is exactly `PASS\n`; each RED digest matches retained bytes;
- focused RED details include the complete GoogleTest failure block or `PROCESS_FAILURE` fallback;
- `baseline-authority.txt` identifies the executing TB35 run and exact artifact/source/selector authority;
- package/source/execution-view byte+mode censuses are identical pre/post;
- no configure, compile, relink, benchmark, generated discovery, repair, package rewrite, or source/test/fixture/selector mutation occurs.

## Required EXEC report

The raw EXEC report must record:

- run/job IDs and terminal workflow state;
- exact artifact/source/selector/harness identities and verified digests;
- 409 aggregate, accepted-prefix aggregate, RED ordinal list, timeout/selection counts;
- verbatim or complete retained detail for every focused RED listed above;
- explicit 312 and 409 gate outcomes;
- 366/367 discriminator evidence;
- protected-green, retired-code, and ownership outcomes;
- ledger/failure-detail hashes and postflight immutability results;
- statement that no semantic/root-cause promotion was performed in EXEC.

## Benchmark plan

**No benchmark execution.** `directional_benchmarks` is package-integrity-censused only. Performance/quality work is outside TB35's frozen semantic scope.

## Stop and rerun rules

- Preflight/authority/digest/mode/selection/timeout/completeness/immutability defect => **ORCHESTRATION FAILURE**; do not repair immutable bytes.
- Semantic RED => retain and continue remaining rows; **no semantic retry**.
- 312 RED, accepted-prefix RED, 409 fixture/oracle failure, protected-green RED, retired-code emission, or 366/367 earlier-stage movement => preserve as hard falsifier; no scope change inside EXEC.
- Do not rebuild inside TB35.
- After mechanically valid EXEC evidence is durably preserved, **stop completely at independent `M3-CP4c-3-TB35-REV`**. No CB/DEFN/runtime continuation is authorized before that independent review.
