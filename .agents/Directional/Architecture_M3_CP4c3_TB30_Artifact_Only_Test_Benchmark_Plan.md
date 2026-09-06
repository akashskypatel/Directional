# M3-CP4c-3-TB30 — Artifact-Only Test + Benchmark Plan

## Validation Identity

- **Phase:** `M3-CP4c-3-TB30`
- **Execution boundary:** `M3-CP4c-3-TB30-EXEC` — runtime execution only.
- **Review boundary:** `M3-CP4c-3-TB30-REV` — evidence review only; no new runtime.
- **Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
- **Evidence source:** `ab86747bdfdb94c7c383bf5d2893ced4207eb555`
- **Build artifact:** `9980764888`, `m3-cp4c3-cb35-result-34005311571`
- **Artifact/provider ZIP SHA-256:** `ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`
- **Packaged source archive SHA-256:** `64801a38ccbe9de282dbec261cad6c2b6575403ed38e93b514c893c22f03684a`
- **Compile log artifact:** `9980765148`
- **Selector:** 408 identities, LF SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`
- **Platform:** GitHub-hosted Linux, artifact-only runtime.

## Validation Objective

Validate CB35's two test-authority corrections without rebuilding or changing product behavior:

1. ordinal **390 PASS** using semantic partition correspondence instead of numeric component index;
2. ordinal **404 PASS** after removal of the out-of-contract "no owner is Established" value assertion;
3. credibility controls **366/367/398 remain RED** because CB35 changes no product source;
4. accepted **1–365 remains 365/365 PASS**.

TB29 authority is selector 408, **399 PASS / 9 RED**, accepted 365/365, RED `[366,367,368,369,370,374,390,398,404]`. If only the authorized witness corrections change, the mechanically consistent TB30 result is **401 PASS / 7 RED**, RED `[366,367,368,369,370,374,398]`. This aggregate is a consistency check, not a substitute for per-row evidence.

## Preconditions

Require before any Directional runtime:

- artifact ID/name exactly `9980764888` / `m3-cp4c3-cb35-result-34005311571`;
- provider ZIP SHA-256 `ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`;
- root `SHA256SUMS` **28/28 PASS**;
- packaged source commit `ab86747bdfdb94c7c383bf5d2893ced4207eb555`;
- source archive SHA-256 `64801a38ccbe9de282dbec261cad6c2b6575403ed38e93b514c893c22f03684a`;
- `build-exit-code=0`, `preflight-exit-code=0`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `preflightCompile=true`, `exactArithmeticBackend=GMP`;
- GMP evidence includes `gmpxx` and `gmp`;
- package source status files are empty.

Preserve archived executable mode bits. **No chmod, repair, reconfigure, compile, relink, rebuild, or repackaging.** A missing mode is orchestration failure.

Record SHA-256, mode, and size for packaged runtime executables:

- `directional_benchmarks` — record only, never execute;
- `directional_compiled_api_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_validation_tests`.

Verify selector hashes/prefixes:

- 365 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- 397 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`
- 401 `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`
- 403 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`
- 405 `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`
- 406 `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`
- 407 `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`
- 408 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`

Require 407 to be the exact 407-identity prefix of 408. Construct identity-to-binary mapping statically from packaged source and `cmake/DirectionalTests.cmake`; exactly one owner per identity. **No generated discovery or `--gtest_list_tests`.**

Create a disposable execution view from immutable bytes. Publish byte+mode censuses for package, packaged source, and execution view. All mutation flags start false. If preflight fails, `runtime_started=false`; preserve evidence and stop as orchestration failure.

## Ordered Execution Plan

### 1. Complete selector-408 validation

Execute all 408 identities in order, one identity per fresh process and fresh working directory, through only the statically resolved packaged owner:

```sh
env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
  "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
```

Use 180-second per-process timeout and `/usr/bin/time -v`. Independently count `[ RUN      ]`:

- `selected == 1 && exit == 0` -> PASS
- `selected == 1 && exit != 0` -> RED
- `selected != 1` -> orchestration invalid

No semantic retries.

**Acceptance:**

- 408/408 rows execute exactly once;
- **1–365 = 365/365 PASS**;
- **390 PASS**;
- **404 PASS**;
- **366 RED, 367 RED, 398 RED**;
- no new RED outside TB29's prior RED set;
- expected aggregate if only CO6 changes behavior: **401 PASS / 7 RED** with `[366,367,368,369,370,374,398]`.

A semantic RED does not stop the remaining rows.

### 2. Correction evidence

Retain complete rows/raw logs for 390 and 404, including binary, exit, selected, PASS/RED, 390 census-correspondence / `m3Cp4c3BW3` publication if emitted, and 404 census publication/completeness fields.

### 3. Credibility/product-unchanged controls

Retain complete raw logs for **366, 367, 398**. Any unexpected PASS is an execution-credibility problem until TB30-REV proves otherwise, not automatic product progress. Also retain exact status/logs for 368, 369, 370, and 374; CB35 did not own these surfaces.

### 4. Postflight

Recompute all three byte+mode censuses and require exact pre/post equality. Record every mutation/boundary flag false. Do not execute `directional_benchmarks`.

## Required EXEC Evidence

Publish and hash:

- ordered `ledger.tsv`: `ordinal, identity, binary, exit, selected, result, raw_log`;
- exactly ordinals 1..408, no gaps/duplicates;
- complete static identity map;
- 408 raw logs;
- executable SHA-256/mode/size census;
- per-process resource logs and summary;
- total PASS/RED and exact RED list;
- accepted-prefix 1–365 result;
- explicit rows/raw logs for 366,367,368,369,370,374,390,398,404;
- any 390/404 census/correspondence lines;
- pre/post package/source/execution-view censuses;
- all configure/compile/relink/discovery/repair/benchmark/mutation flags false.

TB30-EXEC records raw evidence only. It does not diagnose root cause or authorize a correction.

## Benchmark Plan

- **Applicable:** no.
- `directional_benchmarks` is integrity-censused but not executed.
- `/usr/bin/time -v` is process-health evidence, not a performance gate.
- Determinism: one execution per selector identity; no semantic reruns.

## Unit-Test Design Check

- **Contract:** corrected evidence authority of 390/404 plus unchanged full gate.
- **Boundary:** distinct partition domains may reuse numeric component IDs; valid owner publication may include `Established` owners.
- **Why fixture is valid:** TB29 directly exposed both invalid assumptions.
- **Isolation:** no new fixture/test in TB30; immutable CB35 binaries only.
- **Assertion semantics:** 390 uses semantic partition correspondence; 404 publication/completeness only; 398 remains total-ownership product gate.

## Stop and Blocker Conditions

Before semantic runtime, stop and preserve evidence as orchestration failure on any artifact/source/checksum mismatch, mode/byte mismatch, selector hash/prefix or identity-map failure, zero/multiple binary owner, timeout, `selected != 1`, package/source/execution-view mutation or repair, or inability to preserve the complete ledger/raw logs.

After mechanically valid start, semantic REDs do **not** stop the gate.

## Plan-Defined Reruns

- Semantic retries: none.
- Seeds/order permutations: none.
- Nondeterminism investigation: TB30-REV only; no EXEC rerun.
- An orchestration-invalid attempt may be replaced only by a separately authorized control-plane correction without product/test/fixture/selector changes.

## TB30-REV Contract

TB30-REV consumes immutable EXEC artifacts and performs **no runtime**. It must:

1. verify package/source/selector/executable/identity-map/census integrity;
2. prove all 408 rows select exactly one test and no timeout occurred;
3. compare complete ordinal vector against TB29;
4. verify accepted 1–365 independently;
5. adjudicate 390 and 404 as runtime-proved or falsified;
6. treat 366/367/398 as credibility controls;
7. classify every semantic RED/change in `Regression_Root_Cause_Tracker.md`;
8. read retained post-correction census before any second product correction is authorized.

Independent review/planning is a separate boundary. TB30-EXEC must stop after preserving the execution evidence.

## Completion Criteria

TB30-EXEC is complete only when every planned item has a result or explicit blocker, raw evidence is preserved, and TB30-REV can evaluate the contract without chat reconstruction.

PR #8 remains draft and unmerged.
