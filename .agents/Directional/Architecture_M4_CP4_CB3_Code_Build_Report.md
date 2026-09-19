# M4-CP4-CB3 — TB1-R1 harness control correction Code + Build report

**Turn:** `M4-CP4-CB3`
**Result:** **COMPLETE / CONTROL FREEZE GREEN / RUNTIME NOT EXECUTED**
**Predecessor:** `M4-CP4-TB1-R1-EXEC`
**Candidate package retained unchanged:** `10575545321`
**Exact compiled source retained unchanged:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`

## 1. Scope and boundary

CB3 executes the bounded control-only correction authorized by `Architecture_M4_CP4_CB3_Code_Build_Plan.md`. It changes no product, test, fixture, selector, benchmark, CMake, package or compiled-source semantic byte. Candidate artifact `10575545321` is neither rebuilt nor repackaged. No generated Directional binary, test, benchmark, discovery/list/help/version command, configure, compile or relink runs in this turn.

Accepted M4 runtime authority is unchanged at package `10565723112` / exact source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 2. Source and control authority

Runtime-free source snapshot run/job `35416266431 / 105825463926` captured event/source `99442bbca3fcaac8970049c56c8552a76213b018`. Snapshot artifact `10576620294` has provider SHA-256 `97a7c420ea59060acff7b7b1a602755cf3303736fba4fdad66ac76652c4c0a5a`; diagnostic-log artifact `10576445581` has provider SHA-256 `200261b6d950b9c2c49495767cbc8f286a437138804ddfe891937a888e0ad810`.

The R1 harness was recovered exactly from historical Git blob `8703249bf79877b70f1693e2c18e6c163fa09202` (19,871 bytes; runtime SHA-256 `4b956829e4b656ccc71f00c781028fcb08452cad995cbcdfaaacde314954d29f`). `M4-CP4-TB1-R1-ORCH-01` was the inner `run_one` sequence that toggled `set +e` and then unconditionally restored `set -e` before returning its semantic PASS predicate. A semantic nonzero therefore terminated the whole harness while the outer loop intended to remain under `set +e`.

CB3 replaces only that status-capture mechanism with shell conditional control:

```bash
if GTEST_FAIL_IF_NO_TEST_SELECTED=1 "$exe" "--gtest_filter=${identity}" > "$raw" 2>&1; then
  rc=0
else
  rc=$?
fi
```

The corrected `run_one` contains no `set +e` or `set -e`, so it does not change the caller's errexit state. All classification, ledger, focused-loop, selector-loop, immutable-postflight and no-build/no-repair rules remain otherwise unchanged.

## 3. Frozen R2 controls

Corrected R2 harness:

- repository recovery commit: `9bf694a11f0c5d3b5516f5569f9bf931a3b9321a`;
- frozen path during CB3: `.agents/Directional/turn-payloads/m4-cp4-tb1-r2-harness.sh`;
- exact size: **19,885 bytes**;
- SHA-256: `78ab110f8ad851b66fcc331ef02b3a02388f51147efcd4672f2c9bfc7fd750dd`;
- candidate artifact remains `10575545321`;
- expected compiled source remains `ad54c12774e10480fd3cef8138cacb8d5dec1529`;
- selector427 remains 427 LF rows / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- benchmark count remains zero.

R2 caller draft:

- repository recovery commit: `3e49e0fe25f37db01a263fccf6aaaa2f9f2c45c2`;
- frozen path during CB3: `.agents/Directional/turn-payloads/m4-cp4-tb1-r2-exec.draft.yml`;
- exact size: **4,974 bytes**;
- SHA-256: `e21b17f12b18b7e3a45d97dba322a063cc8a64cf911e040fb6bbe60f832e5a2d`;
- execution workflow path when installed: `.github/workflows/m4-cp4-tb1-r2-exec.yml`;
- trigger path: `.agents/connector-triggers/m4-cp4-tb1-r2-exec-20260919.txt`;
- no repository timeout is present for the full semantic gate.

These recovery commits preserve the exact frozen bytes even though turn cleanup removes their temporary working paths.

## 4. Static/control validation

Control-freeze run `35416505731` at event SHA `3138fc5f97e8a5b0c8e801b8a50d39666bd9b08e` completed green:

- `validate_r2 / validate` job `105826099635`: **SUCCESS**, SchemaStore `valid=true` for the frozen R2 caller draft;
- `validate_self / validate` job `105826099713`: **SUCCESS** for the temporary CB3 validator;
- `static_control_check` job `105826126230`: **SUCCESS**.

The static job independently verified the exact harness/caller sizes and SHA-256 values, `bash -n`, absence of inner errexit toggles from `run_one`, exactly one conditional generated-process status capture, unchanged candidate/source/selector constants, benchmark zero, correct R2 paths, no timeout, and `runtimeExecution=false`.

Authoritative result/log artifacts are `10575723230 / 10575553294`, provider SHA-256 `367a374517e5dade1425bd134648facd8a0c874bc09c1a36223073cc0a6b25be / 1fb74be42fb8887850ff84edbac6916a0c3e8dfdcc16ccb44128e0f9579a05aa`. R2 SchemaStore result/log artifacts are `10576650591 / 10576665539`, provider SHA-256 `92296d5e1851259422cef3dfd935970a6cdf225f77ea417cba9a415807ca875a / ee318162ffb65be4a079122f853ef6ef04e026a217e8ac2e6e6eec7d33c31180`.

## 5. Disposition

`M4-CP4-TB1-R1-ORCH-01` is **correction-built / static-control-proved** by CB3. Runtime re-proof remains required in R2; CB3 itself grants no semantic credit, package promotion, selector credit or debt discharge.

The R1 row-2 `Invalid rawfield fixture header` observation remains diagnostic-only and unadjudicated. CB3 does not modify `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`, `SurfaceComplexSimplificationPhase17Tests.cpp`, `torus.rawfield`, product code or selector427. Trustworthy R2 evidence plus mandatory Review owns any semantic/test/fixture disposition.

## 6. Exit

Exact successor: **`M4-CP4-TB1-R2-EXEC`**. It must consume immutable artifact `10575545321` from scratch using the frozen corrected controls, execute the complete six-focused surface unless orchestration integrity fails, then selector427 according to the frozen stop rule, and perform mandatory immutable postflight whenever runtime starts. Any trustworthy semantic result routes to mandatory runtime-free `M4-CP4-TB1-R2-REV`.


## 7. Closeout transport and cleanup provenance

Durable CB3 documentation was transported as one exact Google Drive patch based on source-snapshot authority `99442bbca3fcaac8970049c56c8552a76213b018`. The patch contained eight intended paths, diff-body SHA-256 `05906d4adc7438ec3d85d26185a3858a0f0081264e1b03fc12dfe01261f894be`, and full patch SHA-256 `8f729f359ef62824545fe388a497e2fa07375663f0cfa03a937096c186e4b1dc`. Apply run/job `35416933695 / 105827305461` SchemaStore-validated the caller, verified the exact patch/base/path envelope, and pushed durable documentation commit `6de52706cd37b35e31b9f239bd19679cff8ab9c5` with `runtimeExecution=false`. Result/log artifacts are `10575688779 / 10575838701`, provider SHA-256 `92aff44ae2be3e7f27a375a88c20e4f585641b607fdf3b1c9bc019ebd4762d76 / df3a2366fee653bad249e06745a2ce34f3018a69898141eef8adb6388ac00936`. The reusable reported owner-side Drive retirement required; the exact staged file was then permanently deleted through the owner-authorized Drive control plane.

Temporary workflow callers were deleted before the cleanup trigger. Mandatory batch cleanup run/job `35416992298 / 105827440062` consumed event SHA `ae934204ca1017f335c2b72dfcafb7f0b471064c` and pushed cleanup commit `0109a65aa1ea5486da4948d810dd1838a3a939bf`. Cleanup result/log artifacts are `10575987366 / 10576196981`, provider SHA-256 `869fccf14976c811924d4867bc0c2d5545761a2e89e5e78e796035ff44254e23 / 69291df0f69c31b5ad258ca3b308f0391f55a5f7c8df7a3c4d809e704bb54804`. Cleanup removed the CB3 source-snapshot marker, control-freeze marker, Drive-apply marker, frozen R2 working harness, both caller-draft working paths and the cleanup manifest; it validated the seven-workflow durable inventory, deleted four PR conversation comments and zero inline review comments before observer publication, and recorded no generated Directional runtime.
