# M3-CP4c-3-TB31 — Artifact-Only Test + Benchmark Plan

## Validation Identity

- **Phase:** `M3-CP4c-3-TB31`
- **Execution boundary:** `M3-CP4c-3-TB31-EXEC` — runtime execution only; preserve raw evidence.
- **Review boundary:** `M3-CP4c-3-TB31-REV` — evidence review only; no new runtime.
- **Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
- **Evidence commit to validate:** `90bf8430f54c8b81fb90a6bda820cf8edebce6e9`
- **Build artifact:** `9982174864`, `m3-cp4c3-cb36-result-34010011172`
- **Artifact/provider ZIP SHA-256:** `8bbc10da2372730a4fd644250a420f0ba7e6dd73f59e93364b2b1ccacfbcf43b`
- **Packaged source archive SHA-256:** `f909864226b07a4cd89a9a51669792e8cdd63206c5b2a23d2e0b179476d78cae`
- **Compile log artifact:** `9982175106`
- **Selector:** 408 identities, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`
- **Planned platform:** GitHub-hosted Linux, immutable artifact-only runtime.

## Validation Objective

Validate CB36's single product correction: the already-frozen separating-arc terminal-slit rule is now applied at
`GlobalTopologyPlan.cpp` in addition to the previously corrected certifier site.

Primary questions:

1. do ordinals **366 and 367** cease reproducing the unchanged plan-side component
   `component=0 / faceCount=191 / seedOrbits=[0,1,3] / digest=17919102493633069558`?
2. does the corrected plan partition regain semantic correspondence with the certifier census where expected?
3. does certified source-face ownership remain **300 established / 0 unavailable / 0 conflicting**?
4. does accepted **1–365 remain 365/365 PASS** and the selector remain byte-identical?
5. does no `TraceCutFaceFragmentCountMismatch` appear?

Current semantic runtime authority is TB30: selector 408, **401 PASS / 7 RED**, accepted 365/365, RED
`[366,367,368,369,370,374,398]`.

If CB36 changes only its intended frontier and both 366/367 become PASS while carried surfaces remain unchanged,
the mechanically consistent aggregate is **403 PASS / 5 RED**, RED `[368,369,370,374,398]`. This is a
consistency expectation, **not** an acceptance assumption. Any other valid semantic outcome is retained for
TB31-REV adjudication.

## Preconditions

Before any Directional runtime, verify the immutable package exactly:

- artifact ID/name `9982174864` / `m3-cp4c3-cb36-result-34010011172`;
- provider ZIP SHA-256 `8bbc10da2372730a4fd644250a420f0ba7e6dd73f59e93364b2b1ccacfbcf43b`;
- root `SHA256SUMS` all PASS;
- packaged source commit `90bf8430f54c8b81fb90a6bda820cf8edebce6e9`;
- source archive SHA-256 `f909864226b07a4cd89a9a51669792e8cdd63206c5b2a23d2e0b179476d78cae`;
- `build-exit-code=0`, `preflight-exit-code=0`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `preflightCompile=true`,
  `exactArithmeticBackend=GMP`;
- GMP evidence includes both `gmpxx` and `gmp`;
- package source-status files are empty.

Preserve archived executable mode bits. **No chmod, repair, reconfigure, compile, relink, rebuild, repackaging, or
fixture mutation.** Missing or altered modes/bytes are orchestration failure.

Record SHA-256, mode, and size for packaged executables:

- `directional_benchmarks` — integrity only, never execute;
- `directional_compiled_api_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_validation_tests`.

Verify selector hashes/prefixes exactly:

- 365 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- 397 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`
- 401 `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`
- 403 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`
- 405 `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`
- 406 `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`
- 407 `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`
- 408 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`

Require 407 to be the exact 407-identity prefix of 408. Construct identity-to-binary mapping statically from
packaged source and `cmake/DirectionalTests.cmake`; exactly one owner per identity. **No generated discovery and no
`--gtest_list_tests`.**

Create a disposable execution view from immutable bytes. Publish byte+mode censuses for package, packaged source,
and execution view. All mutation flags begin false. If preflight fails, preserve evidence with
`runtime_started=false` and stop as orchestration failure.

## Ordered Execution Plan

### 1. Complete selector-408 validation

Execute all 408 identities in ordinal order, one identity per fresh process and fresh working directory, through
only the statically resolved packaged owner:

```sh
env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
  "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
```

Use a 180-second per-process timeout and `/usr/bin/time -v`. Independently count `[ RUN      ]` lines:

- `selected == 1 && exit == 0` -> PASS
- `selected == 1 && exit != 0` -> RED
- `selected != 1` -> orchestration invalid

No semantic retries. A semantic RED does not stop the remaining selector rows.

**Acceptance/integrity criteria:**

- 408/408 rows execute exactly once;
- **1–365 = 365/365 PASS**;
- no timeout, zero-selection, multiple-selection, source/byte/mode mutation, repair, compile, or benchmark activity;
- selector bytes and all frozen prefix hashes unchanged.

### 2. CB36 frontier evidence — ordinals 366/367

Retain complete rows and raw logs for both ordinals. Extract every available plan-side field needed to identify the
post-correction component:

- component ID and domain;
- face count;
- face-set digest;
- seed count, seed state, and seed orbits;
- fragment-orbit/count fields and any `TraceCutFaceFragmentCountMismatch`;
- `censusCorrespondence` / published subset correspondence when emitted;
- certified ownership publication counts.

Compare against TB30's exact pre-correction fingerprint:

```text
component=0
faceCount=191
seedState=Multiple
seedOrbits=[0,1,3]
faceSetDigest=17919102493633069558
```

**Falsification comes before interpretation:**

- if 366/367 still fail with that same component 0 / 191 faces / `[0,1,3]` fingerprint,
  `M3-CP4c3-TB30-REV-CAND-01` is falsified;
- if `TraceCutFaceFragmentCountMismatch` appears, the `tracePieceCount` premise is wrong; preserve the complete
  evidence and do not improvise a runtime repair. A later Code + Build correction, if authorized by TB31-REV,
  narrows to `traceTouchedEdges` insertion alone.

An advance to a different semantic failure is still meaningful evidence and must be preserved; TB31-EXEC does not
adjudicate it.

### 3. Ownership and correspondence invariants

Require the certified publication to remain:

```text
sourceFaceCount=300
established=300
unavailable=0
conflicting=0
conflictRowCount=0
```

Report whether the corrected plan component regains exact/subset semantic correspondence with the certifier census.
Do not infer ownership status from ordinal 398.

### 4. Carried RED surfaces and credibility

Retain exact status and complete raw logs for **368, 369, 370, 374, and 398**. CB36 does not own these surfaces.
Ordinal 398 remains a prescribed-sphere `CellularityNotEstablished` gate owned by
`M3-CP4c2-TB-X2-CAND-04`; it must not be re-scoped or used as an ownership-control proxy.

Any unexpected change on these carried surfaces is review input, not permission to mutate or weaken them.

### 5. Postflight integrity

Recompute package, packaged-source, and execution-view byte+mode censuses and require exact pre/post equality.
Record every compile/configure/relink/repair/discovery/benchmark/mutation flag false. Never execute
`directional_benchmarks`.

## Required EXEC Evidence

Publish and hash:

- ordered `ledger.tsv`: `ordinal, identity, binary, exit, selected, result, raw_log`;
- exactly ordinals 1..408 with no gaps/duplicates;
- complete static identity map;
- 408 raw logs;
- executable SHA-256/mode/size census;
- per-process resource logs and summary;
- total PASS/RED and exact RED list;
- accepted-prefix 1–365 result;
- complete rows/raw logs for 366,367,368,369,370,374,398;
- all plan-component fingerprint, ownership, fragment-count, and census-correspondence lines emitted by 366/367;
- pre/post package/source/execution-view censuses;
- all configure/compile/relink/discovery/repair/benchmark/mutation flags false.

TB31-EXEC records raw evidence only. It does not diagnose root cause or authorize another product correction.

## Benchmark Plan

- **Applicable:** no.
- `directional_benchmarks` is integrity-censused but not executed.
- `/usr/bin/time -v` is process-health evidence, not a performance gate.
- Determinism requirement: one execution per selector identity; no semantic reruns.

## Unit-Test Design Check

No unit-test source changes were made in CB36. TB31 executes the existing immutable selector as a product
regression suite. The focused contract is the relation between certified orbit separation and plan-side barrier
construction, with 366/367 serving as existing non-vacuous witnesses.

## Stop and Blocker Conditions

Before semantic runtime, stop and preserve evidence as orchestration failure on any artifact/source/checksum mismatch,
mode/byte mismatch, selector hash/prefix or identity-map failure, zero/multiple binary owner, package/source/execution
view mutation, repair, or inability to preserve the complete ledger/raw logs.

A per-process timeout is orchestration failure, not semantic RED or pass. After a mechanically valid start, semantic
REDs do **not** stop the gate; complete all 408 rows.

## Plan-Defined Reruns

- Semantic retries: none.
- Seeds/order permutations: none.
- Nondeterminism investigation: TB31-REV only; no EXEC rerun.
- An orchestration-invalid attempt may be replaced only by a separately authorized control-plane correction with no
  product/test/fixture/selector change.

## TB31-REV Contract

TB31-REV consumes immutable EXEC evidence and performs **no runtime**. It must:

1. verify package/source/selector/executable/identity-map/census integrity;
2. prove all 408 rows selected exactly one test and no timeout occurred;
3. compare the complete ordinal vector against TB30;
4. verify accepted 1–365 independently;
5. adjudicate `M3-CP4c3-TB30-REV-CAND-01` using the exact falsification conditions above;
6. adjudicate any changed 366/367 failure locus and the plan/certifier correspondence;
7. verify source-face ownership remains 300/0/0;
8. classify every semantic RED/change in `Regression_Root_Cause_Tracker.md`;
9. leave 398 and 368/369/370/374 with their existing owners unless immutable evidence independently proves a
   reason to change ownership;
10. freeze the next boundary. Independent review/planning remains a separate boundary and the implementation loop
    stops there when reached.

## Completion Criteria

TB31-EXEC is complete only when every planned item has a recorded result or explicit blocker, raw evidence is
preserved, and TB31-REV can evaluate every acceptance criterion without reconstructing intent from chat context.

PR #8 remains draft and unmerged.
