# M4-CP-SCALE-TB1 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB1-EXEC`
**Disposition:** COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED
**Mandatory successor:** `M4-CP-SCALE-TB1-REV`
**Runtime authority after EXEC:** unchanged pending Review; accepted package `10331193451` / selector423 **423/423** remains authority.

## 1. Immutable candidate authority

TB1-EXEC consumed only the immutable CB1 compile candidate:

- candidate artifact: `10360085644` (`m4-cp-scale-cb1-result-34872546633`);
- provider/result-ZIP SHA-256: `996189b38c26f906bdd86354451571475900d98d0811f50e50a9439f26ff6ec7`;
- semantic source: `a359b981f9350139304bc5a654041dfba78609b6`;
- packaged source archive SHA-256: `b261f468cde2e54974f19931ca5101e2c6d07e273ca555c0526d9e7ce112e3d4`;
- package `SHA256SUMS`: **28/28** entries verified, manifest SHA-256 `3ac6c9e388d06ed5572613480a587952736657be88cf8dfba393d356e47028b8`;
- selector423: **423 LF rows**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- static owner census: **30 authority-kernel / 277 producer / 75 completion / 41 validation**.

No configure, compile, relink, generated discovery, package repair, source/test/fixture/selector mutation, or benchmark execution occurred.

The clean turn snapshot was captured from repository source `92648ae72307810f6fd8412c5fbca9fec30c4e83` by source-snapshot run `34880699930`. Snapshot artifact `10362778402` (`agent-source-snapshot-cp-scale-tb1-20260914-34880699930`) has provider SHA-256 `251aa0777802e4679d0dee78e5876306a0bd21901d28aec91f463361aceebec9`; its source archive SHA-256 is `7f5e16c10e90548a29a7979069635fe5a7f9802d0c7920b1d8da679653507993`, with `runtimeExecution=false`.

## 2. Focused S1 diagnostic

The authored identity executed exactly once in a fresh process:

`M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral`

Mechanical result: **1/1 PASS**.

The four required retained witness-family reports were all present exactly once:

| Witness | sampleCount | numeratorBitsMax | denominatorBitsMax | magnitudeBitsMax | baselineOutcome | deepest / failed stage |
|---|---:|---:|---:|---:|---|---|
| two-ring | 9 | 105 | 107 | 107 | success | `direct-field-aligned-network` |
| torus | 0 | 0 | 0 | 0 | success | `global-topology-plan` |
| mechanical feature | 60 | 1 | 1 | 1 | success | `global-topology-plan` |
| prescribed sphere | 186 | 429 | 429 | 429 | success | `field-aligned-network` / `surface-cut-graph` |

The prescribed-sphere reachability receipt retains the existing downstream failure surface at `surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`, originating reason `TraceEventPositionInvalid`, trace `2`, event `30`, `NoCarrierMatch / SourceEdgeUnavailable`. The torus and mechanical-feature receipts reach `global-topology-plan`. The zero-sample torus census is preserved as reportable coverage and receives no inferred threshold or gate credit.

The S1 process-ledger SHA-256 is `e3ad302d281cdefdcc4f55860264b3cd01914e8f19e8ec0e579456d1f1964d37`. The parsed four-family measurement table SHA-256 is `3befc557dbcf4fe72a74f401aea7ecbadc2dcf1771d9d8e760d4b17f9d0fbdd2`.

EXEC does **not** infer, propose, or freeze any bit-width threshold from these measurements. S1 remains diagnostic/non-gating.

## 3. Accepted selector423 execution

Every frozen selector423 identity executed in its own fresh exact-filter process against the statically resolved owner binary. Generated discovery was not used.

Mechanical result:

- selector423: **423/423 PASS**;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- crash: **0**;
- selection mismatch: **0**;
- owner census: **30 / 277 / 75 / 41**.

The selector process-ledger SHA-256 is `2e838afc0482da53456679da600a19525fbd8847d21dcad64904c3f50cd59a80`. The focused S1 identity is outside selector423 and contributes zero selector/gate credit.

## 4. Exact immutable postflight

Postflight proves exact equality across every frozen execution surface:

```text
package_census_equal=true
source_census_equal=true
execution_view_census_equal=true
package_manifest_verified=true
selector_rows=423
selector_sha256=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343
configureExecution=false
compileExecution=false
relinkExecution=false
repairExecution=false
generatedDiscovery=false
mutationExecution=false
benchmarkExecution=false
runtimeStarted=true
runtimeCompleted=true
focusedPass=true
selectorCompleted=true
selectionIntegrity=true
timeoutCount=0
crashCount=0
```

Census SHA-256 values are unchanged pre/post:

- package census: `b7e0e440c1e48fe6da46347a073cb964384cecfea16f985f6ec3aea0f9a954e1`;
- source census: `aec374f14c47e2b61b367141df78f58f39498461d6712b40bff3995a5621bafe`;
- execution-view census: `f265c6896789b55f9c42fb8dbf9545f88640ba4420ad6f94d7c97ef9fc718c29`.

## 5. Preserved evidence and publication authority

The complete non-self-referential TB1 evidence archive is:

- file: `Directional__M4-CP-SCALE-TB1-EXEC__evidence.zip`;
- SHA-256: `712bf4983695a58d1d0859e041895209c9935eb7e8f4bdc2835c01737173e3da`;
- internal evidence `SHA256SUMS` SHA-256: `844df680f067deef6eb566bb5856fedc17ba113c1d471d27ada9fb6991c3db49`.

A temporary Drive transport was used only to publish the already-complete immutable evidence into GitHub Actions artifacts. Publication retry run `34883153457`, publish job `104107197329`, completed successfully and independently downloaded the exact archive, matched its SHA-256, verified the complete internal manifest, and recorded `runtimeExecution=false`.

Published artifacts:

- result artifact `10363765929`, `m4-cp-scale-tb1-exec-result-34883153457`, provider SHA-256 `4d1a45227983bf9cef221268ee14657f1d81752b5a5c1923db6954607fdfcfe1`;
- log artifact `10364255019`, `m4-cp-scale-tb1-exec-log-34883153457`, provider SHA-256 `68552b7be50578dbdc6e5b0596e7afe03332ef9f011ab995b3556ef080e61200`.

The downloaded published result was re-opened after publication: its nested evidence archive re-hashes exactly to `712bf498...e3da`, `publication.env` records `internal_manifest_verified=true` and `runtimeExecution=false`, and every internal `SHA256SUMS` entry verifies.

The first publication caller run `34882964148` failed at workflow startup because the temporary caller's permission ceiling omitted `actions: write`, which the reusable schema-validator required for artifact upload. It created no jobs and no runtime evidence. The retry corrected only that temporary caller ceiling; reusable workflow permissions were not changed.

## 6. Regression intake and authority boundary

TB1-EXEC observed no RED, crash, skip, timeout, nondeterminism, selection-integrity failure, immutable-postflight failure, or new semantic failure surface. No new stable event/category/recurrence or regression candidate is created by EXEC.

The four S1 numeric observations are raw diagnostic evidence only. Review alone may interpret them, classify whether they justify any bounded implementation slice, or promote the CB1 candidate.

Stable accounting therefore remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. Accepted runtime authority remains package `10331193451` / selector423 **423/423** pending Review.

## 7. Exact successor

`M4-CP-SCALE-TB1-EXEC` is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**.

**Exact next turn: `M4-CP-SCALE-TB1-REV` — runtime-free Review.**

No retry, compile, rebuild, package repair, source/test/fixture/selector mutation, threshold selection, or S2-S5 implementation is authorized before that Review.
