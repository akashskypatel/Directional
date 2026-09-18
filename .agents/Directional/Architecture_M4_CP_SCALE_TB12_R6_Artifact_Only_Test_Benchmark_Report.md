# M4-CP-SCALE-TB12-R6-EXEC — Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R6-EXEC`
**Type:** immutable artifact-only Test + Benchmark
**Status:** **COMPLETE / ORCHESTRATION FAILURE / ZERO DIRECTIONAL SEMANTIC EXECUTION / NON-STABLE**
**Candidate package:** `10532133889` / semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Authoritative run/job:** `35321067552 / 105523481425`
**Exact next:** `M4-CP-SCALE-CB20` under `Architecture_M4_CP_SCALE_CB20_Orchestration_Harness_Code_Build_Plan.md`

## 1. Result

R6 did not reach Gate A0. The exact CB19-prevalidated caller was reinstalled byte-for-byte, its marker triggered the expected run, the frozen Drive harness was downloaded at its exact retained hash, and candidate-package preflight succeeded. The harness then terminated under `set -u` while preparing the first `run_row` path because `stem` was referenced in the same `local` command in which it was first assigned.

The failing statement is frozen-harness line 225:

```bash
local stem="$(printf '%03d' "$ledger_ord")-${phase}-$(printf '%03d' "$phase_ord")" dir="$RESULT/raw/$stem" work="$RUNTIME/$stem"
```

Bash expands the right-hand sides for that `local` simple command before `stem` becomes available to the later assignments. With nounset enabled, expansion of `$stem` therefore terminates the harness as `stem: unbound variable` before the first generated Directional process is launched.

This is **orchestration**, not product or test semantics. All 436 initialized semantic rows remain `UNEXECUTED`; selector426 execution is 0/426; benchmark execution is 0. Accepted runtime authority therefore remains unchanged.

## 2. Control-plane provenance

- Entry `STATUS` moved from completed CB19 to R6 at commit `46637c6774f7f08bb5479c9706b5f9039021ab67`.
- Source-snapshot run/job `35320820908 / 105522741601` completed GREEN at event SHA `a8cc5c9940dd2f988ae63cda9245c1c41a38eb46`; snapshot artifact `10536634402` has provider SHA-256 `ff58465d1cc2e9454f1f7056c1821e81afaaeef48e0a9e2e192a1ffbca3d1176` and records exact snapshot SHA `a8cc5c9940dd2f988ae63cda9245c1c41a38eb46`.
- Exact R6 caller was restored from publication commit `efeb4da300cc559a02d92e0d7c10d140f3bef352`, Git blob `c31306fce7c7dbf96bb2b80859f285062460b26d`, historical byte SHA-256 `6a673c9a8a8cd146dfc56f28d746ec928b6de34781eaa51a58231017645063eb`, in caller-install commit `58fac3afbc53d5acf51d33f41284a41787560aeb`.
- Re-fetch after installation reproduced blob `c31306fce7c7dbf96bb2b80859f285062460b26d` and 4,870 bytes. The permission union remained exactly `actions: read`, `contents: write`, `id-token: write`, `issues: write`, `pull-requests: write`.
- Execution marker commit/event SHA is `532e9b0b2b681b5936a27e5ac35c6715052190eb`. Observer output reported exactly run `35321067552` with that event SHA before evidence was accepted.
- Execute job `105523481425` reached Google authentication, downloaded the frozen harness, verified its hash, and then failed in the harness execution step.

### Start-of-turn process note

Several repository authority reads occurred before `READ_MODE=snapshot` was made explicit. The miss was detected before successor semantic/control-plane authoring; the turn then acquired and verified the exact source snapshot above and used it for subsequent broad inspection. No product/test/build semantic byte or acceptance decision was changed by the process-order miss.

## 3. Frozen harness and package preflight

The exact retained R5/R6 harness was owner-control-plane fetched from Drive file `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`: **18,459 bytes**, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`. R6 did not modify those bytes.

Before the shell defect fired, the harness verified the immutable candidate package:

- artifact `10532133889`, expected provider SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- packaged source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- root package manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`, **28/28 PASS**;
- six packaged test/benchmark executables retained mode `0755`, two static libraries retained `0644`;
- selector426 remained `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` with accepted owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**;
- retained genus-two authority remained OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, raw field `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No package repair or mode repair occurred.

## 4. Semantic ledger and failure boundary

The harness initialized the complete **436-row** ledger: Gate A0 5, Gate A 4, S5 1, selector426 426. Ledger SHA-256 is `61fd0f8c26c8c2266794efbf8de1c37617a81b2436e027c3e31c0b02d08b92df`. The initial and final ledger receipts both record this same digest, proving no row transitioned out of `UNEXECUTED`.

Observed execution boundary:

```text
orchestration_failure=true
semantic_red=false
runtime_started=true
postflight_complete=false
stop_reason=orchestration_unhandled_exit_1
benchmarkExecuted=0
configureExecuted=0
compileExecuted=0
relinkExecuted=0
generatedDiscovery=0
packageRepair=0
modeRepair=0
mutationPerformed=0
```

`runtime_started=true` means the shell harness had initialized its ledger/runtime phase; it does **not** mean a generated Directional binary ran. No `run_row` body reached the binary invocation. Therefore:

- Gate A0: **0/5 executed; 5 UNEXECUTED**;
- Gate A: **0/4 executed; 4 UNEXECUTED**;
- S5: **0/1 executed; 1 UNEXECUTED**;
- selector426: **0/426 executed; 426 UNEXECUTED**;
- benchmark: **0**;
- generated test discovery: **0**.

The unhandled shell exit also prevented the frozen exact postflight from completing. R6 therefore makes no semantic acceptance/rejection claim despite the successful preflight.

## 5. Evidence artifacts

- result artifact `10536669823`, provider SHA-256 `d27820fadb682b5aee8ff32816b0a6bfa4a824ad2266f2908376ca12ae66f518`;
- persistent workflow log artifact `10536659910`, provider SHA-256 `d2471ec1fc0dfe011ab0a4463eaa6e44a652165df65fe7b9c55dd9b908f6b168`;
- nested evidence archive SHA-256 `a4ed028a9f45022c8e6894f24b6fd2f3c0ac1f55ca13952bf9cc9ef82ee6b792`;
- evidence `SHA256SUMS` file SHA-256 `6ae5e08f618a22a62dc5d3fb67eaabc768f504ce003adb37461df1fa7181b21a`; its listed result records verify;
- package census SHA-256 `08b25da4f16092e5ed77a886da51f2346868a6d0e6f35daf687db51bf84f8866`;
- source census SHA-256 `d199eacce8b9275de2e56df005f36621aef4eb8b8e64aabbab67e61d10576f50`;
- execution-view census SHA-256 `b9fb5e93b15d6fc4a746202b191f9a9495b948bb57c4552b0c5120bed9b5be04`.

## 6. Classification and authority

`M4-CP-SCALE-TB12-R6-EXEC-CAND-01` is **OPEN / ORCHESTRATION / FROZEN-HARNESS SAME-COMMAND LOCAL-INITIALIZATION DEFECT / NON-STABLE**. It creates **+0 stable events / +0 categories / +0 recurrences**.

Accepted M4 runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owner census **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. CB18 candidate `10532133889` stays unpromoted and S5/A3 remain uncredited. The invalid duplicate R5 run remains invalid-attempt provenance only.

## 7. Exact next

Per the frozen R6 plan and cadence rule for orchestration failures, **do not Review the product and do not retry R6 directly**. Exact next is control-plane-only `M4-CP-SCALE-CB20`.

CB20 is bounded to correcting the frozen harness declaration defect without touching product/test/fixture/selector/CMake/package semantics: split the dependent `stem`, `dir`, and `work` initialization into nounset-safe sequential assignments, prove the corrected harness differs only at that statement, freeze it under a new Drive file/hash, prevalidate a fresh R7 caller, and execute **zero generated Directional runtime**. The unchanged candidate package is then retried only in successor `M4-CP-SCALE-TB12-R7-EXEC`.
