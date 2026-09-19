# M4-CP4-TB1-R1-EXEC — artifact-only Test + Benchmark report

**Turn:** `M4-CP4-TB1-R1-EXEC`
**Result:** COMPLETE / ORCHESTRATION INVALID AFTER PARTIAL RUNTIME / NO ACCEPTANCE CREDIT
**Candidate artifact:** `10575545321`
**Exact compiled source:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`
**Run / execute job:** `35415494665 / 105823258305`
**Event SHA:** `a4764ce76ed93e79da29d7179f82a12d62261fc8`

## 1. Immutable preflight

The frozen R1 controls were recovered byte-for-byte and the run independently re-recorded their exact identities before runtime:

- harness: **19,871 bytes**, SHA-256 `4b956829e4b656ccc71f00c781028fcb08452cad995cbcdfaaacde314954d29f`;
- caller: **4,974 bytes**, SHA-256 `617e9e3634cccffd7a68ab2c30e82fb5bc48026823232ada59eae81e89a9790f`.

The immutable candidate passed package preflight: provider/package ZIP SHA-256 `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00`, exact source `ad54c12774e10480fd3cef8138cacb8d5dec1529`, packaged-source SHA-256 `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed`, complete 28-entry package manifest, clean five source-status receipts, GMPXX+GMP, selector427 **427 LF rows** / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, owner partition **30 / 281 / 75 / 41**, and all four owner executables present with mode `0755`.

No configure, compile, relink, generated discovery/list/help/version, package/mode repair, benchmark, source/test/fixture/selector mutation or custom input ran.

## 2. Runtime evidence actually obtained

The run started generated Directional runtime and launched exactly two fresh focused processes before the harness exited:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` — **PASS**, exit `0`, selected `1`, passed `1`, skipped `0`, raw-log SHA-256 `2723c9c6d57c55f309c4889d95dd9c2a13cb2cb1c39d3ef6ed0ec5d54576665b`.
2. `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` — observed **RED**, exit `1`, selected `1`, skipped `0`, raw-log SHA-256 `e54d425ff3abe6beb32980da9aa0da22f0c2f5e2c55aab3f533cad2ab2df14b6`. The process throws `Invalid rawfield fixture header` for `milestone-g/torus.rawfield` before reaching the candidate-extraction assertions.

Focused rows 3–6 and all selector427 rows are explicitly **UNEXECUTED**. Benchmark count is `0`.

Result/log artifacts are `10574789745 / 10575004615`, provider SHA-256 `1b45423f593540c0218680d8b978c13b560efdf90ba3473cb45332668d8d3dc0 / 77e97dc5da2f1e3dcd178b7b2ee16c3c9d5a1a21f0f5d84d876947cd6d33ce37`. The result's recursive `SHA256SUMS` verifies.

## 3. Root cause — `M4-CP4-TB1-R1-ORCH-01`

The frozen harness does not preserve the caller's `errexit` state. The outer focused loop deliberately executes `run_one` under `set +e` so semantic RED can be recorded and the remaining focused rows can still run. Inside `run_one`, however, the generated test launch is followed by an unconditional `set -e`. On a RED, the function's final `[[ "$status" == PASS ]]` therefore returns `1` while `errexit` is active and terminates the whole harness before the outer loop can capture `one_rc`, increment the focused counter, continue rows 3–6, run selector427, or perform mandatory immutable postflight.

The boundary file exposes the contradiction directly: two raw focus logs exist and ledger row 2 is RED, but `focus_executed=1`, `harness_exit=1`, `postflight_complete=false`, `semantic_non_green=true`, and `orchestration_failure=false`. The harness classified the semantic row but failed its own frozen control flow.

Because runtime began but immutable postflight never executed and the planned six-focused/427-selector surface was not completed according to the frozen rules, this attempt is **orchestration-invalid** and grants no semantic acceptance, no package promotion, no debt discharge and no selector credit.

## 4. Row-2 observation disposition

The row-2 process is retained as diagnostic evidence only. Static source explains the immediate exception: `read_rawfield_fixture(...)` in `SurfaceComplexSimplificationPhase17Tests.cpp` interprets the first two integers as `rows columns` and requires `rows == mesh.F.rows()` and `columns == 12`, while the committed torus raw-field fixture begins with the project format header `4 144` (degree / face count). That is a likely test-authority/fixture-format mismatch, but this orchestration-invalid run is not the place to adjudicate or repair it.

`M4-CP4-CB3` must correct only the harness control-flow defect. It must not change the row-2 test, fixture, product, selector or candidate package. A fresh corrected artifact-only retry must re-observe the complete focused surface and mandatory postflight; only then may Review adjudicate any semantic RED.

## 5. Regression accounting and authority

`M4-CP4-TB1-R1-ORCH-01` is a **non-stable orchestration candidate**. No accepted-green authority was lost and the row-2 observation is not accepted semantic evidence. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

Accepted current M4 runtime authority therefore remains package `10565723112` / exact source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Candidate artifact `10575545321` remains unpromoted.

## 6. Successor

Exact successor: **`M4-CP4-CB3`**, a runtime-free control-only correction under `Architecture_M4_CP4_CB3_Code_Build_Plan.md`. It preserves candidate artifact `10575545321` and every semantic byte, corrects only the harness `errexit`/semantic-return interaction, freezes corrected retry controls, and routes next to a fresh `M4-CP4-TB1-R2-EXEC`.


## 7. Closeout transport and cleanup provenance

Durable closeout used the standard Google Drive patch transport. The first apply run/job `35415819923 / 105824184409` schema-validated and verified the exact staged patch, then failed before commit because the patch envelope encoded `intended_paths` with commas while the durable reusable parses that field with semicolons. No repository patch commit was pushed and `runtimeExecution=false`. Its result/log artifacts are `10575139947 / 10576015347`, provider SHA-256 `5e326e578468dce33aee87596d7bbb8ff06a9f89d49ae720161ce5b5b1e1821f / d61ba982b2b546a20f605af62c3c4f80dda60813d1da155f34fcad8d47e3540c`.

The diagnosed retry changed only the envelope delimiter. The diff body remained SHA-256 `491be26c231203df5241a06bec5b10497b79993901edd4e85722051ea72a8414`; corrected full patch SHA-256 was `3c851164abc0a8bb6b703c25b9e9e3badad0be3d62488b283d515e1779114830`. Retry run/job `35415936328 / 105824505720` verified and applied it successfully, pushing durable documentation commit `973fe78a69f036a8f1c3c83f45ba62c66cdfc2ed`. Retry result/log artifacts are `10575319847 / 10575339724`, provider SHA-256 `0412c462c1ab8342befbaf44eb8cb063427f09f7bcffac54cdabf57a3bca320a / 35f3cf213e6a858a141a1b34c957dd60ed3f1bff193a5e64f7cca7ac1f9dd216`. Both the corrected staged file and the superseded failed-attempt staged file were permanently retired through the owner-authorized Drive control plane after the successful push.

Temporary workflow callers were deleted first. Mandatory batch cleanup then ran as `35416024325 / 105824750757` from event SHA `22ea0e1b1697637f5db88eae2a4203a8488846b8` and pushed cleanup commit `7af83ed46a2d1d9ee87b731f0377b5247909f91c`. Cleanup result/log artifacts are `10576445187 / 10576395280`, provider SHA-256 `9a495e566c9887dc6dd27711b5908cffad985a1a96750108b0e5bdd24b321502 / 8fc633e9fad0693e9befaa91030d27eb25baf3856829839ae232fc1dafb7046a`. Cleanup removed the source-snapshot marker, runtime marker, frozen retry harness, closeout-apply marker, and cleanup manifest; validated that only the seven durable workflows remained; deleted five PR conversation comments and zero inline review comments before observer publication; and recorded `runtimeExecution=false`.
