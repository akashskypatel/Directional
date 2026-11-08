# TB90 — partition-stable D7 scheduler count switch immutable full gate and census (2026-11-08 UTC)

**Turn:** `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-EXEC` — **COMPLETE / MATCH**, under [RA-216 §7](Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md). The separate authorized successor is `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT` (step 64.5, runtime-free Review). No successor work was performed inside TB90.

## Frozen source and executor provenance

- Exact compiled semantic source: `34967c89817a9d43a7c99eaf337032f9e9a927fb`; CB107 GMP/GMPXX eight-target compile/package [run 42520884130](https://github.com/akashskypatel/Directional/actions/runs/42520884130); immutable artifact **13633039235**, outer ZIP SHA-256 `dd39eb58c0a8419de55c789ab7b685157120e742e0cf9578d014965fac864d53`, **28/28** packaged file hashes verified, `runtimeExecution=false`. No rebuild or relink within TB90.
- Frozen executor snapshot source/event `438deafb043ef7fd4b84e0b41292e6b200d40d96`; [run 42522279246](https://github.com/akashskypatel/Directional/actions/runs/42522279246), artifact **13633787612**, ZIP SHA-256 `a7dee90d53577a647817f28ab5a5589b7c5641a4aa5133db216259b6f73dafee`, **6,271/6,271** snapshot file hashes and source tar hash verified. Executor event SHA is not the compiled semantic source.
- Frozen full-gate case manifest SHA-256 `45dfbb533ed3668f48a0146a3ce6800f57a2221368380c31c8e60a7974c64607` (**914** selected identities); 81-case deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, expected membership **995**. Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 observations). Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Durable dispatcher event commits: gate `cde3404fd01bc73400dfc75d4b52ce7433f70d1d`, census `d4014c14f60f05f79844aa89a7659dc8a88b16c4`; respective mailbox keys `m6-cp3-tb90-gate`, `m6-cp3-tb90-census` on orphan `workflow-mailbox`. Both published `success`; runtime jobs passed, no compile jobs ran.

## Immutable 914-case full gate — MATCH

- [Gate run 42522538976](https://github.com/akashskypatel/Directional/actions/runs/42522538976), result artifact **13633654777**, ZIP SHA-256 `c80e7eea466c66ea76b310c3ad6895c17cd1130af6bf177aa33d6a6c57bef731`; independently verified **1,836/1,836** `SHA256SUMS` entries.
- Execution: **914 planned / 914 executed / 914 PASS**, 0 RED, abnormal, missing, skipped, duplicates or control errors; unique membership **995**, `postflight=true`, exit 0, `compile=false`, `relink=false`, `configure=false`, `benchmark=false`.
- New GUARD 914 `GlobalConformityBaseline.D7PreferredCountIsTheSchedulerObjectiveForEverySplit` PASS. Raw receipt: `D7_PREFERRED_COUNT_RECEIPT case=scheduler-objective whole=4 uneven=4 halves=4`. The separate GUARD 911–913 receipts also pass under the existing frozen gate.

## Independent TB88/TB89 raw-baseline comparison (RA-216 §7)

- TB88 and TB89 gate/census archives were independently verified. Compare each raw `platform-digest` and `a3-coverage` record by fixture and process (four gate cases plus three census observations): **all 7/7 A3 coverage records are byte-identical** to TB88/TB89. Every `platform-digest` token through `global-topology-plan` is byte-identical.
- CloseSheets, MultiFaceSeam and Plane platform lines are entirely unchanged. Gate and census **Cylinder**: `global-conformity-baseline` `12db9fbca63979ca/211` → `c83e594cebac931e/211`, and `tracing` `e0a85269f80c1190/1728` → `90ef4638b6dda005/1728`; all downstream counts and `validationIssues=0` unchanged. This is the registered D7 rebaseline.
- **Vase**: `global-conformity-baseline` `018723ddd3522976/299` → `78953dc61cf10928/299`; every later product token/count remains unchanged. This is the registered D7 rebaseline. BunnyRandom terminates before baseline and its entire available platform line is unchanged.
- No changed baseline hash was observed without RA-216's permitted downstream treatment; all `/count` values and validation-issue counts are unchanged for the four gate fixtures and census Cylinder. The changed hashes are **not** independent proof of A3 consumption (`covered=0` for Cylinder).

## Three-case production census — expected observations unchanged

- [Census run 42522755014](https://github.com/akashskypatel/Directional/actions/runs/42522755014), result artifact **13634084133**, outer ZIP SHA-256 `de6392917ffc42c534d036be40d9720d6b89efd2d659b369b175ff28539990d6`; independently verified **9/9** internal checksums.
- Three independent executions: **Cylinder PASS**, **BunnyRandom RED** (`InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch`, `sourceVertex=49`), **Vase RED** (`NotProductionReady:completion`, `AggregateCompletionValidationFailure`; 67,750 intermediate completed quads, not produced output). These are pre-registered non-gating observations, not accepted direct production results.
- Census boundary: `planned=3`, `executed=3`, `passed=1`, `red=2`, `abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `postflight=true`, exit 0; all mutation/benchmark flags false. Typed causes were inspected in raw logs rather than inferred from the generic ledger fields (`reason-not-observed`).

## Disposition and outstanding obligations

- **COMPLETE / MATCH** under the frozen gate. This does **not** promote CP3, selector497, the deferred 81, or general direct production. Accepted CP2 remains **491/491**; stable regression **66 events / 17 categories / 49 recurrences**, debt **1**, no new stable regression or accepted-green loss. BunnyRandom P13-e and Vase completion/producer obligations remain open, not relabeled or masked.
- Next separately authorized **Review/DEFN** only: `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT` (D7b, RA-216 §8), followed only after its own authority by CB108 and TB91. Then D5, D4, D9c, A2b reciprocal trace, A4 per-disc construction, D8 and D6 pending user decision. No source/test/fixture/selector changes, builds or successor work were performed in TB90.
- Temporary snapshot marker `.agents/connector-triggers/source-snapshot/m6-cp3-tb90-20261108-2053.txt` is to be retired through the recorded turn-cleanup workflow after report publication; the durable dispatcher request slot and orphan mailbox records must be retained.
