# M3-CP4c-3-TB36 Artifact-Only Test + Benchmark Plan

**State:** FROZEN / EXECUTABLE NEXT PLAN
**Next turn:** `M3-CP4c-3-TB36-EXEC`
**Boundary:** Test + Benchmark / artifact-only; no configure, compile, relink, regeneration, repair, source/test/fixture/selector mutation
**Benchmarks:** prohibited for this gate; compile presence is package evidence only

## 1. Immutable authority

TB36 consumes exactly the CB41 package and nothing rebuilt from later documentation/control commits.

| Authority | Exact value |
|---|---|
| evidence source | `14aa1368523580444929bc65cab0b65449240ec2` |
| CB41 build run/job | `34150409018 / 101831355500` |
| package artifact ID | `10029250324` |
| package artifact name | `cb41-result-34150409018` |
| provider / ZIP SHA-256 | `9af49dd6dd0278225e8373b76e68f74c2ec263129f2c18ed2229135d0c6a5c55` |
| packaged source archive SHA-256 | `f090d8f66d37f2d5f9c02e67a63a5c4c0c4db596a54341a9675c1b545052a6ec` |
| selector | 409 identities |
| selector409 SHA-256 | `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` |
| selector408-prefix SHA-256 | `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` |
| artifact-only harness SHA-256 | `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3` |
| accepted prefix | ordinals 1-365 |

TB35 remains the latest semantic runtime authority until TB36 is independently reviewed/promoted: selector409, 402 PASS / 7 RED, accepted 365/365, RED `[366,367,368,369,370,374,398]`.

## 2. Objective

Execute the full selector409 exactly once from immutable package101 and determine whether CB41's Part IX change:

1. preserves every accepted identity;
2. preserves protected synthetic negative oracles 312 and 409;
3. removes only the false `ClosedBeforeEnd` rejection on genuine face-walk-orbit regions 366/367;
4. exposes the frozen CX5 multiplicity evidence if 366/367 advance to Euler;
5. leaves the separately owned 368/369/370/374/398 failures and ownership census unchanged;
6. leaves source, package, selector, fixtures, binaries, modes and execution view immutable.

No TB36 result authorizes an implementation fix inside TB36.

## 3. Required execution environment

The artifact-only workflow/harness must bind these exact values before execution:

```text
TURN_ID=M3-CP4c-3-TB36-EXEC
ARTIFACT_ID=10029250324
EXPECTED_ARTIFACT_NAME=cb41-result-34150409018
EXPECTED_PROVIDER_DIGEST=sha256:9af49dd6dd0278225e8373b76e68f74c2ec263129f2c18ed2229135d0c6a5c55
EXPECTED_ZIP_SHA256=9af49dd6dd0278225e8373b76e68f74c2ec263129f2c18ed2229135d0c6a5c55
EXPECTED_SOURCE_SHA=14aa1368523580444929bc65cab0b65449240ec2
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt
EXPECTED_SELECTOR_COUNT=409
EXPECTED_SELECTOR_SHA256=eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e
ACCEPTED_PREFIX_COUNT=365
```

After preflight, execute exactly:

```bash
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

The harness, packaged selector and packaged binaries are execution authority. Do not discover tests by running a binary with list/help flags.

## 4. Fail-closed preflight

Before the first Directional process starts, the TB workflow must prove all of the following. Any failure is orchestration failure, not semantic RED or PASS.

1. Artifact ID/name/provider digest and downloaded ZIP SHA-256 match §1.
2. Package `metadata/source-commit.txt` equals the exact evidence source.
3. Package root `SHA256SUMS` verifies **28/28 PASS** and excludes itself.
4. Package metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `preflightCompile=true`.
5. GMP evidence contains both GMPXX and GMP linkage.
6. All eight compiled targets recorded by CB41 are present; the six selected runtime executables retain packaged byte hashes and modes.
7. Selector count is exactly 409 and selector409 SHA-256 matches §1; selector408-prefix hash also matches.
8. Artifact-only harness hash matches §1.
9. Before/after package, source-view and execution-view byte+mode censuses are established so post-run mutation is detectable.
10. Every selector identity maps to exactly one intended process invocation; zero selection is orchestration failure.

No configure, compile, relink, generated discovery, fixture repair, selector rewrite, source patch, binary patch, chmod repair or package repair is permitted.

## 5. Execution contract

Run all 409 selector identities in order, one identity per fresh process, preserving raw stdout/stderr/exit code and the existing structured ledger. Do not retry a semantic RED. Do not partition/stitch the full gate to evade elapsed runtime. A timeout or zero-selected invocation is orchestration failure.

The workload must preserve the immutable package and source/execution-view censuses before and after execution.

## 6. Acceptance and falsifier matrix

### 6.1 Accepted boundary — hard gate

- ordinals **1-365: 365/365 PASS**;
- any RED in 1-365 terminates semantic acceptance and routes to independent review;
- ordinal **312 PASS** specifically proves the unchanged synthetic copied-and-mutated boundary is still rejected;
- ordinal **409 PASS** specifically proves the unchanged shared-start multi-walk negative still reaches its frozen `ClosedBeforeEnd` oracle.

### 6.2 Protected current greens — hard gate

Ordinals **390, 393, 404, 406, 407, 408** must remain PASS. 312 and 409 are also protected as above.

### 6.3 Carried failures — must not move under CB41 ownership

Ordinals **368, 369, 370, 374, 398** remain RED with their separately owned failure surfaces. A change in one of these is evidence that CB41 exceeded scope and must be reviewed; TB36 must not repair it.

### 6.4 Ownership and retired-code guards

Published source-face ownership must remain exactly **300 established / 0 unavailable / 0 conflicting**. Retired failure codes/guards previously required silent must remain absent.

## 7. Part IX discriminator — ordinals 366 and 367

366/367 are the decisive witnesses.

### Hard falsifier

If either still reports:

```text
RegionBoundaryNotSingleWalk
regionBoundaryWalkReason=ClosedBeforeEnd
```

then Part IX / CB41 is falsified. Preserve raw evidence and stop at independent review. Do not patch or retry.

### Predicted next frontier

If the failure advances to `RegionEulerCharacteristicNotOne`, this confirms **only** that the provenance correction removed the false `ClosedBeforeEnd` rejection. It does not validate or invalidate a proposed Euler correction.

For every such Euler failure, the structured evidence must contain the complete CX5 set:

- `regionBoundaryProvenance=FaceWalkOrbit`;
- `regionBoundaryOrbit`;
- `regionBoundaryArcOccurrenceCount`;
- `regionBoundaryDistinctArcCount`;
- `regionBoundaryNodeOccurrenceCount`;
- `regionBoundaryDistinctNodeCount`;
- `regionBoundaryRepeatedNodeOccurrenceCount`;
- `regionBoundaryStartRevisitBeforeEndCount`;
- `vertexCount`;
- `edgeCount`;
- `faceCount`;
- `eulerCharacteristic`.

A missing CX5 field is a CB41 evidence-contract falsifier. An earlier/different production failure is preserved verbatim for review. A PASS is also preserved verbatim and adjudicated by review; TB36 does not infer an Euler fix from it.

## 8. Required focused evidence

The final artifact must make at least these ordinals directly inspectable without reconstructing them from summaries:

`312, 366, 367, 368, 369, 370, 374, 390, 393, 398, 404, 406, 407, 408, 409`.

Also preserve:

- complete 409-row ledger;
- selected-count / timeout / process-exit accounting;
- failure-detail table;
- resource summary;
- ownership census;
- retired-code silence checks;
- pre/post package/source/execution-view byte+mode censuses;
- exact run/job, source SHA, artifact IDs/digests and command-boundary metadata.

## 9. Stop and next-state rules

- **Orchestration failure:** no semantic ledger is promoted; preserve invalid-attempt evidence and route only the control-plane correction as project policy allows.
- **Any semantic RED, including the expected carried REDs:** finish raw evidence preservation, then stop at independent evidence-only `M3-CP4c-3-TB36-REV`. No source/test/fixture/selector mutation, compile, retry or correction occurs in TB36-EXEC.
- **Unexpected all-green result:** preserve it and still stop for independent adjudication before any checkpoint closeout claim.
- **Benchmarks:** do not execute `directional_benchmarks` in TB36. Its compiled presence belongs only to CB41 package evidence.

**TB36-EXEC is the single exact next turn.**
