# M6-CP3-TB1-ENTRY-R2-EXEC — Immutable artifact-only gate execution record

**Live state (2026-10-08T11:00Z): dispatched; runtime result pending.** This is one bounded Test + Benchmark execution turn, not a permission to implement, repair, retry, recompile, or promote. Source and compiled package are frozen. The mandatory independent successor is `M6-CP3-TB1-ENTRY-R2-REV` only after mechanically complete execution evidence.

## Exact immutable inputs and dispatch

- Semantic source commit `80fc1688f13e5ed52699177a845f25cc4dbda38b`.
- Compile workflow `37762724429`; immutable compiled artifact `11542824274`, name `m6-cp3-cb1-r2-ra36-v3-compile-result-37762724429`; provider/download ZIP SHA-256 `8aa756b1085a75109648b4da7f07a2ffebcdf975ea04981ec88b2d2e61c89114`.
- Root `SHA256SUMS` SHA-256 `1fe5d60440fc1ec2f874fbbad3ecb9da260d25839e786cf384e73adb1aa4cd57`; **28/28** referenced artifact files (29 ZIP members including root manifest).
- Embedded source tar SHA-256 `2c4a3c8eb9616482a86263a77a2ce07185be4492c685ad090b98f10b55c91e74`; content includes pinned selector/routing authorities.
- Executor `d07689344ef448f963c28c95d7f4a8dfe11375a2`, preexisting `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh`, Git blob `007bf988f88b2dfa55aeec8c8efbca7f13fefb88`, SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`; no harness changes.
- Dispatcher push/trigger commit `7d219b15519bc7eb003286677c0c122650cf48ab`, request path `.agents/Directional/agent-dispatch-request.json`, `request_id=m6-cp3-tb1-entry-r2-exec-artifact11542824274-1`, `mailbox_key=m6-cp3-tb1-entry-r2-exec`, `operation=test_benchmark`, `turn_id=M6-CP3-TB1-ENTRY-R2-EXEC`, result prefix `m6-cp3-tb1-entry-r2-exec`, retention 14 days.
- Expected authoritative completion record `.workflow-mailbox/m6-cp3-tb1-entry-r2-exec/latest.json`; verify it names the exact trigger, source, run, and artifact before closeout.

## Frozen gate — execution-authority proof

- `focused30`: 30 exact-filter processes, frozen hash `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`.
- `focused12`: 12 exact-filter processes, hash `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`.
- `selector449`: 449 exact-filter processes, hash `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing TSV hash `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
- `CP3-entry`: six canonical identities declared by the immutable harness: PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority; HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge; OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition; A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds; ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition; HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels.
- Each must select exactly one GoogleTest case, with no skips or benchmark invocation. Frozen cumulative count is **497 = 30 + 12 + 449 + 6**.
- Harness performs provider ZIP digest check, downloaded digest, full package manifest, source tar digest, frozen selector/routing checks, byte/mode census pre/postflight for package/source/execution-view, 497 one-process exact filters, independent per-process raw log/resource and checksummed ledger, immutable postflight, and result SHA256SUMS.
- Offline/static preflight rechecked outer ZIP hash, manifest hash/count, all four selector/routing hashes from the embedded source archive, and the original harness Git blob+SHA-256; no tests, builds, executable discovery, or runtime were executed locally.

## Decision boundary

**Execution alone is not acceptance.** A complete 497-process run with any RED requires independent `M6-CP3-TB1-ENTRY-R2-REV` adjudication, not a TB implementation or silent retry. Any missing organic D1/D2/D3/D4/D5 positive, RA-36 multi-edge produced route, reciprocal/sign/face-permutation invariant or authority proof is to be reported as unproven. Review receives full raw logs, red ledger, immutable package checks and exact source. No CB2/CP3 exit. Stable **63/17/46**, produced-witness debt **1**.

## Runtime evidence — terminal, independently verified (2026-10-08T11:04Z)

**Disposition: mechanically complete, SEMANTIC RED (444 PASS / 53 RED). R2 candidate UNPROMOTED pending mandatory independent Review.** Workflow completion is not semantic acceptance; do not release CB2/CP3 exit.

- Dispatcher workflow run **`37767144537`**, [GitHub Actions](https://github.com/akashskypatel/Directional/actions/runs/37767144537); runtime job **`113277596566`** result `success` (mechanical), compile, drive_apply and noop jobs all skipped; mailbox published success at `2026-10-08T11:04:12Z`.
- Mailbox `.workflow-mailbox/m6-cp3-tb1-entry-r2-exec/latest.json`: `event_sha=7d219b15519bc7eb003286677c0c122650cf48ab`, `source_sha=80fc1688f13e5ed52699177a845f25cc4dbda38b`, `run_id=37767144537`, `result=success`.
- **Result artifact ID `11545716507`**, `m6-cp3-tb1-entry-r2-exec-result-37767144537`, [GitHub download](https://github.com/akashskypatel/Directional/actions/runs/37767144537/artifacts/11545716507), expires `2026-10-22T11:03:52Z`; provider/download outer ZIP SHA-256 **`d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`**.
- Full extracted result `SHA256SUMS` verifies **1019/1019** content files (1,020 ZIP entries including checksum manifest). Independently replayed `csv.DictReader` integrity: **497/497** ledger rows, each ordinal unique/in order, **497/497 exact-one selection**, **0 skips**, all per-row raw SHA-256 digests match, **53 RED rows exactly matched red-ledger.tsv**, PASS entries carry exit=0 and one `[ OK ]`. No rerun, retry, discovery, fixture mutation, compile, linking, configuration, or package repair.
- `execution-boundary.txt`: `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, totals `30+12+449+6=497`, `benchmark_execution=false`, other mutation/retry flags false, `script_exit=0`. `candidate-artifact-authority.txt` verifies compiled artifact ID `11542824274` and provider+download digest `8aa756b1085a75109648b4da7f07a2ffebcdf975ea04981ec88b2d2e61c89114`.
- `immutability.txt`: source/package/execution-view byte+mode censuses all equal before/after, four selector/routing digests unchanged, candidate root manifest `28/28` after. Independently compared all three census before/after files byte-for-byte.

### Exact phase accounting

| Group | Processes | PASS | RED | RED ordinals |
|---|---:|---:|---:|---|
| focused30 | 30 | 15 | 15 | 3,6,12,14,15,17,18,20,22,23,24,25,26,27,28 |
| focused12 | 12 | 10 | 2 | 5,6 |
| selector449 | 449 | 419 | 30 | 115,116,117,122,130,132,134,137,139,140,141,142,143,150,176,201,211,217,219,227,230,231,404,405,406,407,444,446,447,448 |
| CP3entry | 6 | **0** | **6** | 1,2,3,4,5,6 |
| **total** | **497** | **444** | **53** | all in `red-ledger.tsv` |

### Evidence-localized observations for mandatory Review (NOT independent adjudication)

The following buckets are an **exclusive rough grouping by raw first failure signature**, not proven root-cause classification. Parent-child cascading and accepted→RED repricing are owned by Review:

1. **25 REDs** have explicit `InvalidHardRailRouteCertificate` in the raw process log, including formerly green focused30/focused12 tests, selector cases and D2/D6 CP3 identities. Representative `raw/focused30/ordinal-003.log`, `raw/selector/ordinal-217.log`, `raw/cp3entry/ordinal-002.log`, `raw/cp3entry/ordinal-006.log`. Internal-midline rectangle producer fails before many asserted A5/A6/A7 behaviors are reached. Determine whether A4 RA-36 certificate construction or a legitimately unrepresentable route is responsible; do not relax typed fail-closed rules without Review.
2. **12 REDs** in `SurfaceCellsPhase10Tests.cpp` have an initial `SurfaceCellProducerDisposition::Produced` vs actual rejected disposition (4-byte 01 vs 02), usually shared rectangle phaseFront family; sampled `raw/selector/ordinal-116.log` and `ordinal-139.log`. Some other selector logs explicitly include the HardRail code and are counted in bucket 1. Treat these as observed downstream products, not twelve independently established root causes.
3. **5 REDs** explicitly report *“No tracer-produced reciprocal periodic torus witness with an exact source/A3 generator and odd selected-face gauge delta.”* See focused30 ordinals 6,20; selector ordinals 446,447; CP3entry ordinal 1. Does not establish that a legitimate odd witness exists or that product is wrong; pre-registered nonvacuity gate is RED.
4. **2 REDs** fail D3/D7 bounded real-tracer seam-collinear OrdinaryFront search: `raw/cp3entry/ordinal-003.log`, `005.log`; case 3 explicitly says *“bounded axis-aligned real-tracer family produced no fully certified reciprocal cross-sheet OrdinaryFront.”*
5. **1 RED** fails the D5 actual A5 route-bearing ordinary carrier baseline before tamper: `raw/cp3entry/ordinal-004.log`, `baseline == nullptr`.
6. **8 remaining REDs** include torus A5/A6/arrangement absent (focused30 25–28, selector 444/448), and two RE-package downstream terminal-code mismatches (selector 176,201): expected `InjectedStageFailure` but got `NotProductionReady`. These require trace-back through the earliest typed producer failure in Review, without treating dependent assertions as new independent defects.

All six CP3entry witnesses are **RED**, thus odd τ, route composition, reciprocal/face-permutation and real seam-collinear positives are not mechanically validated by this candidate. A true multi-edge HardRail route producer witness is **not** demonstrated by this run; do not cite RA-36 multi-edge coverage. Do not relabel, synthesize, adjust the frozen selector/fixture/routing, relax equality checks, retry, or silently change the eight-target artifact.

### Next mandatory turn and stable ledger

**Exact next turn after terminal STATUS closure: `M6-CP3-TB1-ENTRY-R2-REV`.** That turn must independently verify the artifact/report and classify all 53 RED as product/fixture/test-authority regression, identify true first causes versus cascades, and decide whether R2 is rejected/unpromoted and what bounded Definition/Code+Build recovery is permitted. This execution record does **not** independently accept/reject a stable event or reprice the stable ledger. Reviewed CP2 491/491 remains the last accepted source baseline; prior R1 482/497 is rejected. Stable counts **63 events / 17 categories / 46 recurrences**, debt **1**, subject only to independent Review.

