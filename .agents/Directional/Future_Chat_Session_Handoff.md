# Future Chat Session Handoff

**DURABLE — resume authority for the active working branch.**

## Current authority

`M4-CP4-TB1-R1-EXEC` is **COMPLETE / ORCHESTRATION INVALID AFTER PARTIAL RUNTIME / NO ACCEPTANCE CREDIT**. Artifact-only run/job `35415494665 / 105823258305` consumed candidate artifact `10575545321` from exact event SHA `a4764ce76ed93e79da29d7179f82a12d62261fc8`. Result/log artifacts are `10574789745 / 10575004615`, provider SHA-256 `1b45423f593540c0218680d8b978c13b560efdf90ba3473cb45332668d8d3dc0 / 77e97dc5da2f1e3dcd178b7b2ee16c3c9d5a1a21f0f5d84d876947cd6d33ce37`.

Candidate preflight was exact: package SHA-256 `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00`, compiled source `ad54c12774e10480fd3cef8138cacb8d5dec1529`, source archive `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed`, full 28-entry manifest, five clean source-status receipts, GMPXX+GMP, selector427 **427 LF rows** / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, owner partition **30 / 281 / 75 / 41**, all owner executables mode `0755`. Frozen controls also matched exactly: harness 19,871 bytes / SHA `4b956829e4b656ccc71f00c781028fcb08452cad995cbcdfaaacde314954d29f`; caller 4,974 bytes / SHA `617e9e3634cccffd7a68ab2c30e82fb5bc48026823232ada59eae81e89a9790f`.

Runtime launched two focus processes: row 1 `ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` PASS; row 2 `ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` one-selected RED with `Invalid rawfield fixture header`. The harness then exited `1` because `run_one` re-enabled `set -e` internally before returning nonzero for the semantic RED. Mandatory rows 3–6, selector427 and immutable postflight did not run. Boundary records `runtime_started=true`, `postflight_complete=false`, `semantic_non_green=true`, `focus_executed=1`, selector `0/427`; the mismatch between two raw focus logs and `focus_executed=1` is part of the control-flow evidence.

The row-2 RED is diagnostic-only, not accepted semantic evidence. Static source shows its helper expects a `rows columns` rawfield header while the committed torus fixture begins `4 144`; Review must not adjudicate that observation until a corrected run completes the frozen control/postflight contract. Stable accounting remains **49 / 14 / 35**, debt **5**. Accepted current M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Candidate `10575545321` remains unpromoted.

## Exact next turn

**`M4-CP4-CB3`** — runtime-free control-only correction under `Architecture_M4_CP4_CB3_Code_Build_Plan.md`.

1. Read root `STATUS` and publish the CB3 entry beacon first; re-read mandatory Code + Build/cadence/workflow/cleanup policies and choose `READ_MODE=snapshot`.
2. Re-open this handoff, TODO, frozen CP4 definitions, `Architecture_M4_CP4_TB1_R1_Artifact_Only_Test_Benchmark_Report.md`, CB3 plan, tracker/ROADMAP/ORIENTATION, selector427 and relevant LESSONS.
3. Preserve artifact `10575545321`, product/test/fixture/selector/benchmark/CMake bytes and compiled source `ad54c12774e10480fd3cef8138cacb8d5dec1529` exactly. No recompile/repackage is authorized because R1 re-proved package integrity before runtime.
4. Correct only `M4-CP4-TB1-R1-ORCH-01`: `run_one` must capture generated-process status without changing the caller's `errexit` state. Semantic nonzero must return to the outer loop so focused accounting, remaining rows and immutable postflight can proceed according to the frozen contract.
5. Do not change the row-2 test/helper/fixture based on the orchestration-invalid observation. No generated Directional runtime executes in CB3.
6. Freeze corrected R2 harness/caller exact bytes/hashes; schema-validate the caller. Exact successor on green control freeze is **`M4-CP4-TB1-R2-EXEC`** on unchanged artifact `10575545321`.
7. Preserve cleanup evidence, remove temporary callers first, run manifest cleanup, and publish COMPLETE `STATUS` as the final repository mutation.

### Carried obligations and owners

- three `G4-B002` produced-witness debts — **M4-CP4 gating**; no runtime+Review credit yet.
- `M4-CP3-TB1-R1-REV-OBS-01` — **M4-CP4 exit conjunct**; produced same-region multiplicity-2 runtime+Review pending.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **pre-CP4 prerequisite**; zero-transport helper precondition runtime+Review pending.
- `M4-CP-SCALE-TB1-REV-OBS-01` — **M8-CP2**, representative/stress calibration only.
- `M4-CP-SCALE-DEFN-OBS-01` — **M8-CP2 only if observationally equivalent**; disagreement reopens A2a/M3.
- `M4-CP3-CB4-REV-OBS-02` — first legitimate future row399/path/`sourceFaces` binder touch.
- historical row408 provenance remains a truth constraint.
- two `G4-B003` debts remain **M5-owned**.
