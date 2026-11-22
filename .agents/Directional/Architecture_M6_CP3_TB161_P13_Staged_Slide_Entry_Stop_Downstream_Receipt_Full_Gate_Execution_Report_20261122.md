# TB161 — staged slide-entry stop downstream receipt: execution record (IN PROGRESS)

## Situation

The exact Test + Benchmark turn `M6-CP3-TB-EXEC-161-P13-STAGED-SLIDE-ENTRY-STOP-DOWNSTREAM-RECEIPT-FULL-GATE` is **IN PROGRESS**. Do not start its independent Review successor until this turn closes. Neither the 979-case gate nor the three-case production census has an accepted TB161 runtime verdict as of this record. No source, tests, fixtures, selectors, build logic, or production defaults were changed.

## Background

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open.
- Exact CB-178 semantic source: `d9d685edf372573c6b07a3be06dc75e2bbec67e7`; compiled immutable package artifact `14741239012` from [run 44990307918](https://github.com/akashskypatel/Directional/actions/runs/44990307918).
- CB-178 outer artifact ZIP SHA-256 `b7f8a16f8e8c816ccd1df571d6e98c78770da0b319543cfb131353fd71a6d190` verified; internal 28/28 SHA256SUMS verified. `runtimeExecution=false`; eight GMP/GMPXX linked targets. Source archive SHA-256 `f580f9de76e367163dde5e7b504d80fe4939ab5fc3f83c1d2954563258ccfee8`.
- Exact executor snapshot event/source `85d932564966c51120b89f6afe549ef3e3bdb8d1`, [snapshot run 44991814275](https://github.com/akashskypatel/Directional/actions/runs/44991814275), artifact `14741159451`, outer ZIP SHA-256 `ca963ec85c2536fc2129deabec37439d40c0cd7ac66768cb451e4e7fde75c3`; internal 5714/5714 hashes verified.
- Reusable harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- TB161 gate case manifest SHA-256 `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a` with 979 cases; rows 1–978 byte-identical to TB160. Census case manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, three cases. Deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 deferred. Both manifest self-checks PASS.
- Reference TB160 gate artifact `14737647064` (outer SHA-256 `9dc2bb7669be86f70f2db2acf9c2c7ad12f0b4d39d40c85ae89194b5abe0ffc3`, 1964/1964 internal hashes), census artifact `14737279153` (outer SHA-256 `94341d1128af1794f33ece3f61a7f13257fb716378ea693a1b0c54d2c368657e`, 9/9 internal hashes).
- **Census request:** `m6-cp3-tb161-census-20261122-a`, request-event SHA `6641d6d049620c053169e2ce3b3c27bd6f48f280`, [run 44992037243](https://github.com/akashskypatel/Directional/actions/runs/44992037243); runtime job observed in progress.
- **Gate request:** `m6-cp3-tb161-gate-20261122-b`, request-event SHA `f56c0e0461d40fdf71f17687cf8ed95b8a291a21`, [run 44992118487](https://github.com/akashskypatel/Directional/actions/runs/44992118487); queued behind census in serialized dispatcher.
- Original first gate request `...-a` at `b9a5e15e3989b5e4e67f0a04c7a6580d26067776` did not appear as a run; the `...-b` request is confirmed. **Do not dispatch duplicates.**
- Workflow mailboxes on **orphan** `workflow-mailbox` ref: `.workflow-mailbox/m6-cp3-tb161-production-census/latest.json` and `.workflow-mailbox/m6-cp3-tb161-full-gate/latest.json`. The source-branch mailbox is not authority.

## Assessment

Immutable package, manifests, deferred ledger, exact source snapshot, and TB160 reference artifacts were verified. Test launcher self-checks passed; no local Directional binary ran. GitHub runtime jobs must finish before claiming any TB161 gate or census outcome. The separately run read-only document audit reported zero errors and one existing `ORIENTATION.md` size warning.

When artifacts are terminal, download **each** GitHub Action's result and diagnostic artifacts, verify outer ZIP and all inner checksums, confirm `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`, compare all 978 preceding gate rows and complete raw logs with TB160 using only frozen N1–N3, and compare all three census rows/logs with TB160 using N1–N4. The exact TB161 row 979 must PASS. Publish verbatim `SphereStagedCutGraph`, `SphereStagedPlan`, 24 `SphereStagedTrace`, all `SphereStagedSlidePiece`, and `SphereStagedSlidePieces` lines. Predictions are informational, not substitute assertions.

Frozen STOP rules: [TB-REV-160 adversarial record](Architecture_M6_CP3_TB_REV_160_Adversarial_Review_20261122.md), especially V7/V8, its 'TB161 rules'. Any substantive failed gate must be accurately classified for independent Review; never weaken tests or rerun using changed package. No CP3, selector497, product default, or D0 acceptance is authorized here.

## Recommendation

**Resume this same TB-EXEC-161**, recover the confirmed runs by exact ID/mailbox, examine immutable results, compare and document them, update regression tracker as warranted, update the handoff and task index, retire only temporary control files, and write the root `STATUS` as the last repository mutation. Only a completed and independently documented Test + Benchmark turn may designate `M6-CP3-TB-REV-161-P13-STAGED-SLIDE-ENTRY-STOP-DOWNSTREAM-RECEIPT-FULL-GATE` as its successor. Do not start that Review in the same turn.
