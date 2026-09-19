# M4-CP4-TB1-EXEC — artifact-only Test + Benchmark report

**Turn:** `M4-CP4-TB1-EXEC`
**Result:** ORCHESTRATION INVALID / NO SEMANTIC RUNTIME / PACKAGE UNPROMOTED
**Candidate artifact:** `10574525792`
**Exact compiled source:** `8d6b8ccf5d49966414f8c54b02b130d8196d3af8`
**Execution run/job:** `35411656874 / 105812362078`
**Event SHA:** `807722c0518c2919a6f208e4bbe98368f100905b`

## 1. Immutable preflight evidence

The frozen TB1 caller passed SchemaStore validation before execution. The execution job froze the actual control bytes before touching the candidate package:

- harness: `.agents/Directional/turn-payloads/m4-cp4-tb1-harness.sh`, **19,860 bytes**, SHA-256 `3574953980bb3e9ec377795264a8768b1b237b03b3c9730539ae343e7e030e03`;
- caller: `.github/workflows/m4-cp4-tb1-exec.yml`, **4,908 bytes**, SHA-256 `36c0cad155eff3762bf71259fd4713d5f1de0fc0e80c631273a7bcfff9b62ce5`;
- candidate artifact `10574525792` was downloaded exactly once;
- observed provider/package ZIP SHA-256 exactly matched the frozen value `857d49282a099d7c0c11b378e99c6b2cb7ab26a44ab0797a9e74157b27dec7c0`;
- package `SHA256SUMS` verified completely before the stop;
- packaged source commit matched `8d6b8ccf5d49966414f8c54b02b130d8196d3af8`.

The primary TB result/log artifacts are:

- result artifact `10573982618`, provider SHA-256 `2e9bcb293ee8d99e6b9d90210496c6633f02ab5bd2830b6e7d668bc6ad4eba6d`;
- diagnostic log artifact `10573992605`, provider SHA-256 `c79fd3fa32fb8d002aa7f6196afd255cc3636436eba4b9a166877d3eaadfaea3`;
- workflow-schema result/log artifacts `10574563318 / 10574653220`, provider SHA-256 `e9e7fcd12b389cab11403cd4b398c3af2d69b8120a9447a79c1cac52f3716796 / 4abd36434fcba656c2f2059593ffad39c2316e82265ba0739368c0d47d32f6fa`;
- observer log artifact `10574533335`, provider SHA-256 `baf1281d313fa2554dd12a20ff6c7ff8f63782eab4dc1bb8eb95fb79b93dd532`.

The run stopped before any generated Directional process. `runtime_started=false`; focused rows executed **0/6**; selector rows executed **0/427**; benchmark count **0**. Configure, compile, relink, package repair, mode repair, generated discovery, source mutation, test mutation, fixture mutation and selector mutation counts are all **0**.

## 2. Deterministic orchestration failure

The frozen harness required a non-existent clean-source receipt named `metadata/source-status-after-package.txt`. The actual immutable package manifest contains the reusable compile workflow's clean receipt set:

- `source-status-before-configure.txt`;
- `source-status-preconfigure.txt`;
- `source-status-after-configure.txt`;
- `source-status-after-build.txt`;
- `source-status-final.txt`.

There is no `source-status-after-package.txt`. The harness therefore emitted exactly:

`ORCHESTRATION_FAILURE: missing_source-status-after-package.txt`

and exited `90` before semantic runtime. This is an orchestration-contract defect in the TB harness, not product/test evidence.

The same verified package manifest also exposes a second deterministic closure defect. Candidate artifact `10574525792` packages only these selector-owner test executables:

- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`.

It does **not** package `directional_surface_cell_validation_tests`. Selector427's frozen owner partition is **30 authority-kernel / 281 producer / 75 completion / 41 validation**. Therefore the immutable CB1 package cannot execute the required 41 validation-owned accepted-prefix rows even after correcting the receipt-name check. CB1 had deliberately compiled only five targets: core, pipeline and the three affected test-owner executables; that target set is insufficient for the full selector427 TB gate.

Both defects are package/orchestration closure issues. Neither changes the CP4 semantic implementation, selector427, accepted authority, or regression accounting.

## 3. Classification and accounting

This attempt is **ORCHESTRATION INVALID BEFORE TRUSTWORTHY SEMANTIC EVIDENCE** under the frozen TB1 plan. No semantic RED, PASS, SKIP, crash or timeout is creditable because no generated Directional process started. The candidate package is not promoted, no produced-witness debt is discharged, no CP4 focused identity receives runtime credit, and no selector publication is authorized.

Stable regression accounting remains **49 events / 14 categories / 35 recurrences** with produced-witness debt **5**. This turn adds **no stable regression**; it records one non-stable orchestration/package-closure incident with two deterministic causes: an invented harness receipt requirement and an incomplete owner-executable package for a 427-row selector reproof.

Accepted current M4 runtime authority remains package `10565723112` / exact source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

## 4. Control-plane provenance

Turn-start source authority was acquired through source-snapshot run `35411123919`, artifact `10574507468`, event/source `db53288eedaf47d6b50aec51aa5b4154f4cfe483`, provider SHA-256 `968d830a2a8b0c079d558e2fc6a55092da14a7433c21334d614bb9709264fbd6`, internal source archive SHA-256 `b4299481247b4fa4adc4c58296441099d5de5b28325a6304b70d007c6eda11e8`, `runtimeExecution=false`. A bounded set of direct connector reads occurred before that snapshot was acquired; broad inspection then stopped and snapshot authority was used. No source/product semantics were changed by that process miss.


## 5. Exact successor

Exactly one successor is authorized: runtime-free **`M4-CP4-CB2`** under `Architecture_M4_CP4_CB2_Code_Build_Plan.md`.

CB2 is orchestration/package correction only. It must keep product/test/fixture/selector semantics byte-identical, compile/package the unchanged CP4 semantic surface through mandatory `agent-compile-reusable.yml` with **all eight standard targets**, prove all four selector-owner executables are present, and freeze a corrected retry harness that checks only the reusable workflow's actual source-status receipts. No generated Directional runtime belongs in CB2.

After a fresh complete package is accepted as build authority, the only runtime successor is fresh artifact-only **`M4-CP4-TB1-R1-EXEC`**, which must rerun all **433** planned rows from scratch.
