# M3-CP4c-3-TB29 — Artifact-Only Test + Benchmark Plan

**Turn:** `M3-CP4c-3-TB29`
**Execution boundary:** `M3-CP4c-3-TB29-EXEC` — runtime execution only.
**Review boundary:** `M3-CP4c-3-TB29-REV` — evidence review only; no new runtime.
**Immutable evidence source:** `25ab3d55697598bde436d1ac811d71e6cf911f2e`
**Immutable package:** artifact `9979639398` (`m3-cp4c3-cb34-result-34001505322`)
**Package/provider ZIP SHA-256:** `c7e35682b9d38b8e8b7916e6030cc2bd3fd4172d0dfc49be83d09a4b0a45ecf2`
**Packaged source archive SHA-256:** `187d75cc76a4664c5fd2486b7e6b1b9bae5d7fe0a0e2a5d9be54c73a0885ff5e`
**Selector:** 408 identities, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`

## 1. Purpose

TB29 is the first semantic runtime execution of the single CM9 separating-arc correction compiled by CB34. It must
measure the immutable CB34 package, not rebuild, repair, reinterpret, or supplement it. The pre-CB34 semantic
authority remains TB28-R3: selector 407, **400 PASS / 7 RED**, accepted **1–365 = 365/365**, RED
`[366,367,368,369,370,374,398]`.

The new ordinal 408 is a census-effect witness only. It must not be interpreted as an owner oracle.

## 2. Hard prohibitions

TB29-EXEC must not:

- configure, compile, relink, rebuild, or repackage Directional;
- repair executable modes, package bytes, source bytes, fixtures, selectors, or generated content;
- run generated discovery, `--gtest_list_tests`, `ctest`, or `directional_benchmarks`;
- edit product, test, fixture, benchmark, build, selector, or harness semantics;
- weaken or rename any identity in the accepted prefix or selectors 397/401/403/405/406/407/408;
- retry a semantic RED to obtain a cleaner result;
- stop at the first semantic RED;
- use TB29-EXEC to diagnose, classify, or plan a product correction.

An orchestration failure is not semantic evidence. Preserve the first actionable failure and stop.

## 3. Immutable preflight

Before any Directional process starts, verify all of the following.

### 3.1 Package authority

Require exactly:

- artifact ID `9979639398`;
- artifact name `m3-cp4c3-cb34-result-34001505322`;
- provider/download ZIP digest
  `sha256:c7e35682b9d38b8e8b7916e6030cc2bd3fd4172d0dfc49be83d09a4b0a45ecf2`;
- root `SHA256SUMS` verification **28/28 PASS**;
- packaged source commit `25ab3d55697598bde436d1ac811d71e6cf911f2e`;
- packaged source archive SHA-256
  `187d75cc76a4664c5fd2486b7e6b1b9bae5d7fe0a0e2a5d9be54c73a0885ff5e`;
- `build-exit-code=0`, `preflight-exit-code=0`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `preflightCompile=true`, and
  `exactArithmeticBackend=GMP`;
- GMP evidence contains both `gmpxx` and `gmp`.

Extraction must preserve archived mode bits. Ordinary `unzip`/`tar` is allowed. Python `zipfile.extractall` is
prohibited for executable payloads unless archived modes are restored and verified by the format itself. **No
`chmod` or other mode repair is allowed.** A missing executable mode is an orchestration failure.

### 3.2 Runtime executable authority

Record SHA-256, Unix mode, and byte size for every packaged runtime executable:

- `directional_benchmarks` — record only, do not execute;
- `directional_compiled_api_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_validation_tests`.

### 3.3 Selector authority

Verify the frozen LF-normalized chain and exact prefixes:

- prefix 365: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- selector 397: `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`;
- selector 401: `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`;
- selector 403: `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`;
- selector 405: `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`;
- selector 406: `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`;
- selector 407: `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`;
- selector 408: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`.

Require selector 407 to be the exact first 407 identities of selector 408 and ordinal 408 to be exactly:

`SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus`

Construct the identity-to-binary map statically from immutable packaged source and `cmake/DirectionalTests.cmake`.
Require exactly one compiled owner for every identity. Do not execute a Directional binary to discover tests.

### 3.4 Execution view and mutation census

Create a disposable execution view from immutable package/source bytes only so executable-relative fixtures resolve.
Before runtime, publish byte+mode censuses for the package tree, packaged-source tree, and execution view. Record all
mutation/boundary flags false: configure, compile, relink, generated discovery, package repair, mode repair,
source/test/fixture/selector mutation, and benchmark execution.

If any preflight check fails, set `runtime_started=false`, preserve evidence, and stop as orchestration failure.

## 4. TB29-EXEC runtime contract

Execute all 408 selector identities in frozen order, **one identity per fresh process and fresh working directory**.
Route each row through the static identity map and invoke only its owning packaged test executable:

```sh
env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
  "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
```

Retain a focused per-process timeout of 180 seconds and `/usr/bin/time -v` resource evidence. A timeout is an
orchestration failure, not a semantic RED.

For every process count GoogleTest `[ RUN      ]` lines independently of the exit code:

- `selected == 1 && exit == 0` -> PASS;
- `selected == 1 && exit != 0` -> RED;
- `selected != 1` -> orchestration-invalid row; never PASS.

Execute all 408 rows once. No semantic retries.

## 5. Required EXEC evidence

Publish and hash:

- ordered `ledger.tsv` with `ordinal, identity, binary, exit, selected, result, raw_log`;
- exactly ordinals 1..408, no gaps or duplicates;
- full static identity map;
- all 408 raw logs;
- runtime executable SHA-256/mode/size census;
- per-process resource logs and summary;
- total PASS/RED and exact RED ordinal list;
- accepted-prefix result for ordinals 1–365;
- explicit rows for prior controls 366, 367, 398 and publication gates 404, 406, 407, 408;
- pre/post package, packaged-source, and execution-view byte+mode censuses;
- execution-boundary flags proving no configure/compile/relink/discovery/repair/benchmark/mutation occurred.

Postflight must prove all three censuses unchanged. EXEC records raw evidence only; it does not choose the next
product correction or promote semantic authority.

## 6. TB29-REV contract

TB29-REV consumes the immutable EXEC artifacts and performs **no new runtime**. It must:

1. verify artifact/source/selector/executable/identity-map/census integrity;
2. prove all 408 rows selected exactly one test and no timeout occurred;
3. compare ordinals 1–407 against TB28-R3, explicitly reporting any behavior delta;
4. independently report accepted-prefix 1–365 and classify any regression before considering later rows;
5. adjudicate ordinal 408 only as the frozen census-effect witness — never as a predicted owner value;
6. classify every observed RED/change in `Regression_Root_Cause_Tracker.md` without inventing a stable event;
7. decide whether the CM9 correction advances CP4c-3 or requires a bounded successor review/plan.

A green ordinal 408 alone is insufficient to close the checkpoint if accepted-prefix regressions or other gating REDs
remain. Likewise, unchanged pre-existing REDs must not be falsely attributed to CB34.

## 7. Exit routes

### Mechanically valid execution

If package integrity, exact selection, timeouts, and postflight immutability are all valid, TB29-EXEC closes by
publishing the raw 408-row evidence and routes **only** to `M3-CP4c-3-TB29-REV`.

### Orchestration failure

If immutable package integrity, identity routing, selected count, timeout, evidence upload, or census integrity
fails, preserve the first actionable evidence and stop without semantic credit. A retry may change only the
control plane and may not change product/test/fixture/selector bytes.

PR #8 remains draft and unmerged throughout TB29.
