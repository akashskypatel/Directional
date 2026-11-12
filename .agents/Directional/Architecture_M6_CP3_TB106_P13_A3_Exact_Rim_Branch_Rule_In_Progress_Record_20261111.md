# TB106 exact rim branch full gate — in-progress evidence

- Canonical turn: `M6-CP3-TB106-P13-A3-EXACT-RIM-BRANCH-RULE-FULL-GATE-EXEC` (64B.25). Authority RA-226 §6. No CB126 work is authorized inside this turn.
- Exact executor source snapshot: commit `99d0e2d5365ca0ea6529944786b04652f7d3fdc4`, [run 43109710948](https://github.com/akashskypatel/Directional/actions/runs/43109710948), artifact `13896240459`, ZIP SHA-256 `8af0ad574dec56288d8ad75436e5e30c759a2b4467361855b8f29c6ab4ff7cb7`. All 5,482 source-file SHA-256 entries verified.
- Immutable CB125 package: artifact `13894015691`, source `0ff93f167feb69dc290d4f220a0f8d32a906e2f7`, ZIP SHA-256 `72aca96c3a4fdfc8707e8a4b24ff678455184f4c573650535dc176f78fa58d54`. All 28 package entries verified; no compile, relink or repair.
- Frozen full gate: 943 rows, SHA-256 `938836fc3326df11ccb3d475e0c6a3a4d629d8ac6e252436dcfac47286bfb651`; membership 1,024; deferred ledger 81. Harness self-check passed.
- Full-gate request commit `062889841320852680d711836c24742fc6b0fdd1`; [run 43110402612](https://github.com/akashskypatel/Directional/actions/runs/43110402612). Validator and dispatcher parse passed; runtime in progress at 22:22 UTC, 2026-11-11.
- Three-case census request commit `bbac1effc586d8019ae73ef89f9e122f3cf15eae`; [run 43110688688](https://github.com/akashskypatel/Directional/actions/runs/43110688688). Queued at 22:22 UTC.
- TB105 baseline gate artifact `13876851723` (1,892/1,892 manifest checks passed), census artifact `13877545718` (9/9 checks passed). No TB106 test verdict is claimed yet.
- Before completion, verify 943/943, all 25 prior receipt lines byte-identical, four new `rim-branch` and four new `rim-branch-agreement` lines, `exactOnly=0` and `binary64Only=0` each, membership 1,024, and unchanged three-case production census. Inspect every RED and update the root-cause tracker. Preserve accepted CP2 491/491, stable 66/17/49, debt 1 and deferred 81 unless evidence requires change.
- Turn remains IN_PROGRESS until result evidence, tracker, handoff, TODO and CHANGELOG are committed and snapshot trigger is cleaned. Successor routing is RA-226 §6 only; no successor implementation in this turn.
