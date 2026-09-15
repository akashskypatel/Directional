# M4-CP-SCALE-TB3-EXEC Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / SEMANTIC RED / REVIEW REQUIRED
**Execution role:** TB-EXEC only; no promotion or semantic root-cause adjudication.
**Mandatory successor:** `M4-CP-SCALE-TB3-REV`.

## 1. Immutable authority

- Candidate artifact: `10375799491` (`m4-cp-scale-cb3-package-result-34915185539`).
- Candidate semantic source: `ba6e204d9daef39bfc6c168b659fc1b94f2b5b9b`.
- Provider artifact ZIP SHA-256: `60e84d9b630a8a59574b330e83f80120000973f91a011272a743ce6bdbac5379`.
- Packaged source archive SHA-256: `4ec9c7888621fbb0b51cff7173a8ef678c6351a5f3a88988fc0d1b590aee1e2d`.
- Package manifest SHA-256: `2f52b377f0a26bd1d474ed64e41a2fd5096b5ad102c4ff802691dd1969246cfb`, 28 entries.
- Selector423: 423 LF rows, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.
- First422 prefix SHA-256: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`.
- Owner census: **30 authority-kernel / 277 producer / 75 completion / 41 validation**.

Accepted runtime authority is unchanged pending Review: package `10360085644` / source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**.

## 2. Execution authority

Authoritative workflow run/job: `34917763195 / 104219037828`, event/source SHA `e4d489842b7ee438c9d8fd4c9b38047939fb4ed5`.

Published evidence:

- result artifact `10376198415`, SHA-256 `1dff929087652a6bc6928d378e43d638b93fd6ec0fae83e64ae7d5a2e69bbb86`;
- diagnostic log artifact `10376118600`, SHA-256 `226d4dd8a54fa3f99b44e4231c4ee8b8177047e1c071b7983b5c3ba4cc8671e8`;
- nested evidence ZIP SHA-256 `cbbf645a8572d07a1b91caabcc1dbead771eddc06254dcc093ced8271bfd72a2`.

The workflow caller schema validation and frozen execution-boundary check passed. The only repository differences admitted between orchestration base `de7c573955578fb8ec599233870e83cda0e910dd` and runtime SHA were the temporary TB3 caller and its trigger marker.

## 3. Artifact-only boundary

The frozen payload reports:

```text
configureExecution=false
compileExecution=false
relinkExecution=false
repairExecution=false
generatedDiscovery=false
mutationExecution=false
benchmarkExecution=false
```

No rebuild, relink, repair, generated discovery, source/test/fixture mutation, benchmark, or selector mutation occurred. Runtime did execute (`runtimeStarted=true`).

## 4. Focused S2 result — RED

Focused identity:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

Mechanical process result:

- selected exactly **1** test;
- exit code **1**;
- **0 OK / 0 skipped / RED**;
- no timeout, crash, or selection mismatch.

The focused process stopped in the fixture's pre-comparator authority checks. The raw log records four failed assertions before the Filter/ExactFallback comparison can receive credit:

1. expected `centerCycleLift == 0.0`, observed **1**;
2. expected `matchingCycleQuarterTurn == 0`, observed **2**;
3. expected `centerIsSuppliedSingularity == false`, observed **true**;
4. expected `atlasBuild == true`, observed **false**, with typed `CycleTransportMismatch`.

These are the mechanical TB3 observations only. Whether they reproduce an existing root, expose a distinct test-authority defect, or imply another disposition is reserved to `M4-CP-SCALE-TB3-REV`.

## 5. Fail-fast selector remainder and OBS-01

Per the frozen plan, the focused RED stopped further semantic runtime. Selector423 therefore executed **0/423** rows. The payload nevertheless preserved the complete preinitialized remainder:

```text
total=423
pass=0
red=0
skip=0
timeout=0
selectionMismatch=0
unexecuted=423
authorityKernel=30
producer=277
completion=75
validation=41
```

`failure_path_remainder_preserved=true` and `immutable_postflight=verified`. This is the required runtime proof that `M4-CP-SCALE-TB2-REV-OBS-01`'s fail-fast remainder/census control survives a focused failure.

## 6. Immutable postflight

The frozen evidence reports:

```text
package_census_equal=true
source_census_equal=true
execution_view_census_equal=true
package_manifest_verified=true
selector_rows=423
selector_sha256=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343
first422_sha256=bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc
```

The package SHA-256 verification also remained exact before and after runtime. Mechanical exit is **32**, the frozen payload's focused-RED outcome.

## 7. TB-EXEC disposition

- Candidate `10375799491` is **not promoted**.
- Selector423 receives **no new runtime credit** from TB3 because it did not execute.
- Accepted runtime authority remains package `10360085644` / selector423 **423/423** from TB1 Review.
- Stable regression accounting remains **49 / 14 / 35**, debt **5**, pending Review.
- `M4-CP-SCALE-TB2-REV-OBS-01` is mechanically discharged by the preserved 423-row UNEXECUTED remainder and verified immutable postflight.
- `M4-CP-SCALE-TB3-EXEC-CAND-01` is opened as a **non-stable review candidate** recording only the focused pre-comparator RED surface; root-cause classification is Review-owned.

Exact next: **`M4-CP-SCALE-TB3-REV`**. No retry, corrective CB, or candidate promotion is authorized before that Review.
