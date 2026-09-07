# M3-CP4c-3-TB36-EXEC — Artifact-Only Test + Benchmark Execution Report

**Turn:** `M3-CP4c-3-TB36-EXEC`
**Date:** 2026-09-07 UTC
**Scope:** Test + Benchmark EXEC, artifact-only; **benchmarks prohibited and not executed**.
**Semantic source under test:** `14aa1368523580444929bc65cab0b65449240ec2`
**Immutable package:** artifact `10029250324` / `cb41-result-34150409018`
**Selector:** 409 identities, SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`

## Verdict

TB36-EXEC is **mechanically valid and semantically RED**. The frozen package101 artifact executed selector409 exactly
once per identity through the packaged artifact-only harness. The result is **402 PASS / 7 RED**, accepted
**1–365 = 365/365 PASS**, RED `[366,367,368,369,370,374,398]`, every ledger row selected, zero selection mismatch,
zero timeout, and identical package/source/execution-view censuses before and after execution.

The important raw transition is confined to ordinals **366/367**: both advance from TB35's
`RegionBoundaryNotSingleWalk / ClosedBeforeEnd` stop to **`RegionEulerCharacteristicNotOne`** while publishing
`regionBoundaryProvenance=FaceWalkOrbit` and the complete frozen CX5 measurement set. This is the runtime outcome
predicted by Part IX. **EXEC does not independently adjudicate the Euler semantics or promote package101 to current
semantic authority.** TB35 therefore remains current valid semantic runtime authority until independent TB36-REV.

No product, test, fixture, selector, benchmark, build, package, or definition was mutated in this turn.

## Execution provenance

- caller install commit: `ae80ad65db077974aa032c64e6118dffc5666638`;
- execution-trigger commit: `8a55564c31be523a1b6e3630482267cb3a452941`;
- workflow run: `34153857590`;
- schema-validation job `101841519719`: PASS before runtime;
- observer job `101841520456`: PASS; branch-file observer disabled;
- execute job `101841532059`: PASS;
- result artifact `10030367614` / `m3-cp4c3-tb36-exec-result-34153857590`, provider digest
  `sha256:310e58bee64c59e8583e671eecaba0f8d3df1d961608162765487d2d6d295721`;
- persistent log artifact `10030367857` / `m3-cp4c3-tb36-exec-log-34153857590`, provider digest
  `sha256:d32ff72401e843a87eefec4ff750a8ca329a89c6e14aa7fd92de8804cb0c9370`.

The caller used the durable schema validator and only entered `execute` after `valid == true`. Runtime-job
permissions were `actions: read` and `contents: read`; reusable workflow permissions were not changed.

### Start-of-turn snapshot recovery

A process-order miss was detected before execution: a few project documents were read piecemeal before the
mandatory `READ_MODE` choice. Work stopped immediately, the miss was recorded, and the turn switched to
`READ_MODE=snapshot` before substantive TB36 evidence analysis. Snapshot run `34153210096` succeeded from control
SHA `3318bc5c68de75d88fb8886ee24c3d6e8341c9ae`; snapshot artifact `10030071053` has provider digest
`sha256:967f7ea3bdd35facbf6ba390ab302a4e56f4299955df245a810eb17fecdd0267`, with source archive SHA-256
`8c951fb015c9db8d44d6e10a94fd0537d43cb56d59db9a426661582dde8b543a`. Subsequent source/document analysis was
local against that snapshot. This procedural miss does not alter semantic runtime evidence.

The external `turn-based-coding-agent-skill` `TB-EXEC.md` reference could not be resolved through the available
GitHub/web paths after a bounded retry sequence; the local project TB36 plan and mandatory project policies remained
the execution authority. No repeated open-ended retry was performed.

## Immutable artifact authority

Package101 was fetched once and verified before execution:

- artifact/provider/ZIP SHA-256:
  `9af49dd6dd0278225e8373b76e68f74c2ec263129f2c18ed2229135d0c6a5c55`;
- packaged source SHA: `14aa1368523580444929bc65cab0b65449240ec2`;
- packaged source archive SHA-256:
  `f090d8f66d37f2d5f9c02e67a63a5c4c0c4db596a54341a9675c1b545052a6ec`;
- packaged harness SHA-256:
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- selector409 SHA-256:
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 prefix SHA-256:
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- package `SHA256SUMS`: 28/28 PASS;
- six approved runtime executables retained mode `0755`.

No configure, compile, relink, package repair, mode repair, generated discovery, source/test/fixture/selector mutation,
or benchmark execution occurred. Local analysis only extracted and inspected preserved artifacts; no Directional
binary was executed locally.

## Harness boundary and ledger integrity

`execution-boundary.txt` records:

- `script_exit=0`;
- `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`;
- `execution_view_verified=true`, `orchestration_failure=false`;
- `selection_integrity=true`, `timeout_count=0`;
- `benchmark_execution=false`;
- `configure_execution=false`, `compile_execution=false`, `relink_execution=false`;
- `generated_discovery=false`, `package_repair=false`, `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`.

Evidence integrity:

- `ledger.tsv`: 409 rows, SHA-256 `058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`;
- `identity-map.tsv`: 409 rows, SHA-256 `f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`;
- `resource-summary.tsv`: 409 rows, SHA-256 `4d18685c95780ec2f70cac0439a46f4c11f8a86a52863d0682f032f9c3480df0`;
- failure-detail digest table SHA-256:
  `02734fd968484aed32c0e009e09392600daac200a45ef5f712423107d7c59694`;
- package census before/after: identical;
- source census before/after: identical;
- execution-view census before/after: identical.

Maximum recorded RSS is 18,464 KiB at ordinal 147 (`0:15.95`). This is observation only; TB36 has no benchmark
or quality/resource acceptance gate.

## Semantic result

| Measure | TB36 raw EXEC |
|---|---|
| selector | 409 |
| PASS / RED | **402 / 7** |
| RED ordinals | **366, 367, 368, 369, 370, 374, 398** |
| accepted prefix 1–365 | **365 / 365 PASS** |
| selection mismatch | none |
| timeouts | 0 |
| protected 312 | PASS |
| protected 390/393/404/406/407/408/409 | all PASS |
| certified ownership at ordinal385 | **300 / 0 / 0** (`established/unavailable/conflicting`) |
| retired `TraceArcDoesNotSeparateItsSides` | absent |
| retired `UncutFaceComponentOrbitSeedNotUnique` | absent |

Ordinal398 also publishes the unchanged mechanical owner map before its carried sphere stop:
`sourceFaceCount=300;ownerMapCount=300;provesCellularity=true`; torus publishes `144/144`.

### Ordinals 366 and 367 — Part IX runtime transition reached the Euler frontier

Both failures are byte-identical at failure-detail level, SHA-256
`82548091bd6aeeb2f7d61af73326e7e33ec7d88b7774de9ea5629959981883a6`, and contain all frozen CX5 fields:

```text
detailCode=RegionEulerCharacteristicNotOne
regionBoundaryWalkReason=ClosedBeforeEnd
regionBoundaryProvenance=FaceWalkOrbit
regionBoundaryOrbit=0
regionBoundaryArcOccurrenceCount=40
regionBoundaryDistinctArcCount=22
regionBoundaryNodeOccurrenceCount=40
regionBoundaryDistinctNodeCount=22
regionBoundaryRepeatedNodeOccurrenceCount=18
regionBoundaryStartRevisitBeforeEndCount=1
vertexCount=100
edgeCount=353
faceCount=250
eulerCharacteristic=-3
```

`ClosedBeforeEnd` is therefore present as non-rejecting observation on the derived face-walk provenance, rather than
remaining the terminal `RegionBoundaryNotSingleWalk` rejection. Accepted ordinal312 and gating ordinal409 remain
PASS, so the raw evidence does not show provenance overreach onto the synthetic negative boundaries.

This raw transition **confirms only that the Part IX provenance/reason-scope implementation reached its intended
runtime branch**. The meaning/correctness of the Euler census remains the independent review's job.

### Carried RED identities

The five separately owned failures remain RED without a new ordinal or accepted-prefix loss:

| Ordinal | Raw failure | Detail SHA-256 |
|---:|---|---|
| 368 | sphere still stops at `CellularityNotEstablished / RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable` | `498cfc1b4d14febbeaa90a24bf16e026e721a36bfeac68c3c1c306e6745f043d` |
| 369 | selected trace-crossed edge still reports `saturationUsed=true` where ordinary proposal is required | `ea71bb5a47280bdf486ed1b202bc242206ddb5c96f78d9cb8808a3f7b9229bfd` |
| 370 | empty closed-surface network still returns the wrong typed code and no source-face locus | `56c588972f27c84d81d94f4de08053073913888b9f9581aff27d66075a595f7c` |
| 374 | folded-cone witness still stops because `atlasBuild` is false | `ede2ae5009a7039ba339e59647bb2d196d89a90af791c43c2d6ba5051a1a5bcc` |
| 398 | owner-map fixture still cannot obtain the prescribed-sphere cut graph | `8c186956d6774805acde93bc99f5171d21a02bff767003ff510dd2d9ca78d0ea` |

These are continuations of pre-existing separately owned failures; TB36-EXEC does not re-own or correct them.

## Regression classification before close

TB36 observed no new RED ordinal and no accepted-prefix regression. The seven RED identities map to existing open
records. In particular:

- 366/367 are the runtime observation for existing `M3-CP4c3-TB35-REV-CAND-01`; the frozen provenance correction
  no longer stops at `ClosedBeforeEnd`, and the evidence reaches the separately open Euler branch;
- the Euler branch remains `M3-CP4c3-TB34-REV-CAND-03`, measurement-complete and **pending independent review**;
- 368/369/370/374/398 remain their prior carried owners and classifications.

Because EXEC is not the independent review, it does **not** create, merge, close, or reprice a stable regression.
Stable accounting therefore remains **45 events / 14 categories / 31 recurrences**, produced-witness debt **5**, and
semantic package count **101** pending TB36-REV.

## Required stop

TB36-EXEC raw evidence is preserved. Semantic RED remains, so the exact next boundary is **independent
`M3-CP4c-3-TB36-REV`**. That turn may adjudicate the provenance correction and Euler measurement, promote or reject
package101 as semantic authority, and freeze the next measure. **No additional runtime, benchmark, compile,
source/test/fixture/selector mutation, or corrective implementation is authorized inside this EXEC turn.**
