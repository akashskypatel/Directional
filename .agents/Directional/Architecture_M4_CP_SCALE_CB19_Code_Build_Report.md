# M4-CP-SCALE-CB19 — Orchestration-Correction Code + Build Report

**Turn:** `M4-CP-SCALE-CB19`
**Type:** Code + Build / control-plane-only orchestration correction
**Status:** **COMPLETE / CONTROL PLANE GREEN / ZERO DIRECTIONAL RUNTIME / NO REBUILD**
**Reused candidate:** artifact `10532133889`, semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Frozen harness:** Drive `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`
**Exact next:** `M4-CP-SCALE-TB12-R6-EXEC`

## 1. Scope and result

CB19 changes only the execution control plane required to recover from R5's startup failure. It does not edit production source, tests, fixtures, selector files, CMake/build semantics, the CB18 package, or the frozen 436-row runtime harness. It performs no configure, compile, relink, repackage, generated test/discovery/benchmark invocation, or other Directional runtime.

The corrected fresh R6 caller was published at `.github/workflows/m4-cp-scale-tb12-r6-exec.yml` only after exact pre-publication validation, while its execution marker `.agents/connector-triggers/m4-cp-scale-tb12-r6-exec-20260918.txt` remained absent. Mandatory turn cleanup permits only the durable workflow set, so CB19 retires that temporary R6 caller again before cleanup. Its exact validated bytes remain frozen by publication commit `efeb4da300cc559a02d92e0d7c10d140f3bef352`, Git blob `c31306fce7c7dbf96bb2b80859f285062460b26d`, and SHA-256 `6a673c9a8a8cd146dfc56f28d746ec928b6de34781eaa51a58231017645063eb`. R6 must reinstall those exact bytes, without editing or regenerating them, before creating the marker.

Accepted runtime authority is unchanged at package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owner census **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. CB18 candidate `10532133889` remains unpromoted; S5/A3 remain uncredited; no selector427 exists.

## 2. Start-of-turn read-mode recovery

The canonical entry `STATUS` beacon for CB19 was direct-written first as required. The session then began several repository policy/handoff reads before explicitly declaring `READ_MODE`, violating the start-of-turn ordering rule in `TOOL_USE_CONSERVATION_POLICY.md` / `Mandatory_Start_Checklist.md`. The miss was detected before any semantic/control-plane authoring beyond the `STATUS` bootstrap. Piecemeal inspection stopped and the turn recovered to mandatory `READ_MODE=snapshot`.

Recovery snapshot run/job `35314272574 / 105502517858` captured event/source SHA `cad01d27a12ffc7af6748255061071e011119e25`. Snapshot artifact `10534104381` has provider SHA-256 `a312219304c2e040fba0ae1763da76d55a1657361564aa69bdfb6085006e0b21`; its nested source archive hashes to `c758696e42f24cfe63d147973e85880defda9a952f30f44618a51d4dad949b28` and its 5,283-file manifest verified locally. The process miss changed no product/test/build semantics and is retained here so it is not silently erased.

## 3. Frozen package and harness authority

CB19 reuses, without mutation:

- candidate artifact `10532133889`, provider SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- package manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`, 28/28 entries;
- selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` and first425 SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- retained genus-two OBJ/rawfield/metadata hashes from CB18;
- exact R5/R6 semantic harness bytes from Drive file `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`.

The Drive harness was fetched through the owner-authorized control plane and independently hashed locally: 18,459 bytes, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`, exactly matching the frozen CB19 plan. Its internal `TURN_ID='M4-CP-SCALE-TB12-R5-EXEC'` and result-path naming are intentionally retained because R6 must execute these exact bytes rather than regenerate or relabel the semantic harness.

The post-closeout duplicate run `35312751970 / 105497993610` remains invalid-attempt provenance only. CB19 does not use its row-1 RED to change semantics or to bypass the required fresh R6 execution.

## 4. Permission-ceiling correction

Current reusable authority was rechecked before authoring the successor caller:

- `.github/workflows/agent-run-observer-reusable.yml` — blob `04b65c5db671ddcae15aa7d2832f3cdc1d4372fc`; its `branch-file` nested job requests `contents: write` even when `commit_run_file=false` skips it at runtime;
- `.github/workflows/agent-workflow-schema-validator-reusable.yml` — blob `397d1d38d43daa0cff076528a854ba35b154a996`; validation needs `contents: read`.

The fresh R6 caller therefore carries the exact frozen top-level union:

```yaml
permissions:
  actions: read
  contents: write
  id-token: write
  issues: write
  pull-requests: write
```

`id-token: write` is required by the Google Workload Identity authentication used only to download the frozen harness. The caller retains the existing observer, schema-validator, exact-Drive-download, hash-check, artifact-only harness execution and evidence-upload topology. The R5 startup defect — `contents: read` below the reusable observer's static ceiling — is removed without widening product semantics.

## 5. Exact caller freezing and schema validation

The R6 caller was first authored outside `.github/workflows/**` at `.agents/Directional/turn-payloads/m4-cp-scale-tb12-r6-exec.yml`. Its harness digest was materialized from an `@@SHA256:R5_HARNESS@@` placeholder with `.agents/Directional/tools/write_orchestration_payload.py`; the rendered caller is 4,870 bytes, SHA-256 `6a673c9a8a8cd146dfc56f28d746ec928b6de34781eaa51a58231017645063eb`, Git blob `c31306fce7c7dbf96bb2b80859f285062460b26d`.

Schema validation used temporary validation workflow run `35315434185`, event SHA `94d6a873ca0d0ae07f01e1062522e7c837d11cf6`:

- validation-workflow self-check job `105505944638`: success;
- exact R6 draft validation job `105505987470`: success;
- R6 draft SchemaStore result artifact `10535275417`, SHA-256 `ec90baa515ecbfe92bf53e8c6dce73578d06ac4c455fec3babfbcb144d0418c6`;
- retained report names `.agents/Directional/turn-payloads/m4-cp-scale-tb12-r6-exec.yml`, checked-out/event SHA `94d6a873...`, `validation_outcome=success`, `valid=true`.

After validation, the exact same bytes were published at `.github/workflows/m4-cp-scale-tb12-r6-exec.yml` by commit `efeb4da300cc559a02d92e0d7c10d140f3bef352`. Re-fetch showed the draft and published caller share the identical Git blob `c31306fce7c7dbf96bb2b80859f285062460b26d` and 4,870-character content. The R6 marker was separately checked and remained absent. Temporary validation workflow authority was retired in commit `3887fcc8f967f7cb2f2a0a3e66f5b22a70dab9e6`; the temporary R6 caller is likewise retired before mandatory turn cleanup. This does not discard its validation authority: R6 reinstalls the exact content-addressed bytes from commit/blob above, verifies the same SHA-256 and permission union, and only then creates the marker.

## 6. Build/runtime boundary

CB19 is a Code + Build turn only by cadence role; its authorized correction requires no compilation. Accordingly:

- `configureExecuted=false`;
- `compileExecuted=false`;
- `relinkExecuted=false`;
- `repackageExecuted=false`;
- `generatedDirectionalRuntime=false`;
- `testExecution=false`;
- `benchmarkExecution=false`;
- `discoveryExecution=false`;
- candidate package mutation/repair is false.

The mandatory GMP policy remains satisfied by the reused CB18 package's already-recorded GMP/GMPXX build evidence; CB19 creates no new compile evidence and claims none.

## 7. Disposition

CB19 closes only the R5 orchestration defect. It does not adjudicate the product, the invalid duplicate row-1 observation, S5, A3, or selector publication. Exact next is fresh artifact-only `M4-CP-SCALE-TB12-R6-EXEC` under `Architecture_M4_CP_SCALE_TB12_R6_Artifact_Only_Test_Benchmark_Plan.md`.

The successor must first reinstall the exact prevalidated R6 caller bytes from commit `efeb4da300cc559a02d92e0d7c10d140f3bef352` / blob `c31306fce7c7dbf96bb2b80859f285062460b26d`, verify SHA-256 `6a673c9a8a8cd146dfc56f28d746ec928b6de34781eaa51a58231017645063eb` and the frozen permission union, then create the R6 marker in a separate commit, observe the resulting run, and execute the exact frozen 436-row semantic plan. A valid semantic RED routes to `M4-CP-SCALE-TB12-R6-REV`; an orchestration/integrity failure routes to the smallest orchestration-correction CB; an all-green result also routes to R6 Review before any selector427/publication decision.
