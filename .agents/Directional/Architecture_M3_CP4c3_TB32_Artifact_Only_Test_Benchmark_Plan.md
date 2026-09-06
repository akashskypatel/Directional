# M3-CP4c-3-TB32 Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M3-CP4c-3-TB32`
- Execution split: `TB32-EXEC` -> `TB32-REV`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit: `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`
- Build run / package job: `34014992328 / 101437310546`
- Immutable result artifact: `9983643195` / `cb37-package-result-34014992328`
- Provider digest: `sha256:75fcebb299c02b3a10525d935973a8cfca5bf119e3cfc4e54b5591f3cf8f699f`
- Packaged source archive SHA-256: `cae8e29946c5e9dfea1a49070e0d8721bc17fb53dba54bb6c66188347560d3fa`
- Planned platform: GitHub-hosted Ubuntu runner, immutable artifact execution only

## Validation Objective

Validate Part VIII `DEFN-R4` after CB37 without rebuilding or mutating any packaged source/input:

1. `TraceArcDoesNotSeparateItsSides` must never be emitted by 366/367 or any other row.
2. the prior component-0 `189 faces / seedCount 1 / Unique / [0]` seed failure must not reproduce as `UncutFaceComponentOrbitSeedNotUnique` on 366/367;
3. ordinals **390, 393, 406 and 407 must return to PASS** while retaining their durable frontier-evidence assertions;
4. credibility surfaces **368, 369, 370, 374 and 398 must remain RED** because CB37 did not own them;
5. accepted identities **1-365 remain 365/365 PASS**, selector 408 remains byte-identical, and certified ownership remains 300 established / 0 unavailable / 0 conflicting when published.

No aggregate PASS count is pre-assumed for 366/367: either may PASS or advance to a later legitimate semantic guard. TB32-REV adjudicates the exact later locus.

## Preconditions

Before runtime, verify the package exactly:

- artifact ID/name and provider digest above;
- root `SHA256SUMS` all PASS;
- `metadata/source-commit.txt == 7f63b5f41a0ca72f0b984ec4ee42d11f74775719`;
- source archive SHA-256 above;
- `preflight-exit-code=0`, `build-exit-code=0`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- GMP evidence includes both `gmpxx` and `gmp` on an authoritative link line;
- all package source-status files are empty;
- preserve executable mode bits and bytes exactly.

Record SHA-256, mode and size for packaged executables. `directional_benchmarks` is integrity-censused but **never executed**.

Verify selector 408 from packaged source:

- line count: **408**;
- SHA-256: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- construct identity-to-binary ownership statically from packaged source and `cmake/DirectionalTests.cmake`;
- exactly one owning binary per identity;
- no generated discovery and no `--gtest_list_tests`.

Create a disposable execution view from immutable bytes. Publish package/source/execution-view byte+mode censuses before runtime. Any mismatch is orchestration failure, not semantic RED.

## TB32-EXEC — Ordered Runtime Plan

### 1. Complete selector-408 execution

Execute every identity 1..408 in ordinal order, one fresh process and fresh working directory per identity, using only its statically resolved packaged owner:

```sh
env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
  "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
```

Use a 180-second per-process timeout and `/usr/bin/time -v`. Independently count `[ RUN      ]` lines:

- `selected == 1 && exit == 0` -> PASS
- `selected == 1 && exit != 0` -> RED
- `selected != 1` -> orchestration invalid

Do not retry semantic REDs. A semantic RED does not stop remaining selector rows.

### 2. Frozen R4 falsification and required outcomes

Retain complete raw logs for **366, 367, 368, 369, 370, 374, 390, 393, 398, 406 and 407**.

For 366/367 extract every emitted frontier field, including:

- terminal failure/detail code and locus;
- plan component, face count, face-set digest and partition identity;
- seed count/state/orbits if present;
- certifier census identity/digest;
- `censusCorrespondence` and subset relation;
- interior-arc census projections;
- certified owner publication counts.

Hard falsifiers:

- any `TraceArcDoesNotSeparateItsSides` emission -> **DEFN-R4.3 falsified**;
- `UncutFaceComponentOrbitSeedNotUnique` reproducing the prior 189-face / seedCount 1 / `[0]` component -> **DEFN-R4.1 falsified**.

Required green identities: **390, 393, 406, 407**.

Credibility gate that must stay RED: **368, 369, 370, 374, 398**. Any change on those rows is preserved as review evidence; EXEC does not reinterpret their owner or weaken their contract.

### 3. Accepted-prefix and ownership integrity

Require:

- identities 1..365 = **365/365 PASS**;
- all 408 rows selected exactly once;
- zero timeouts;
- no source/test/fixture/selector/build mutation;
- no configure, compile, relink, repair, discovery or benchmark execution;
- selector bytes unchanged;
- certified ownership remains **300 / 0 / 0** whenever the publication reaches that stage.

### 4. Postflight integrity

Recompute package, packaged-source and execution-view byte+mode censuses and require exact pre/post equality. Record all mutation/build/benchmark flags false.

## Required EXEC Evidence

Publish and hash:

- ordered `ledger.tsv` for ordinals 1..408: `ordinal, identity, binary, exit, selected, result, raw_log`;
- complete static identity map;
- all 408 raw logs;
- executable SHA-256/mode/size census;
- per-process resource logs and summary;
- total PASS/RED and exact RED list;
- accepted 1..365 result;
- complete focused rows/logs listed above;
- all frontier/census/ownership evidence emitted by 366/367;
- pre/post package/source/execution-view censuses;
- explicit false flags for configure/compile/relink/discovery/repair/benchmark/source/test/fixture/selector mutation.

TB32-EXEC records raw evidence only. It performs no diagnosis, code/test change, rebuild, or planning correction.

## Benchmark Plan

- Applicable: **no**.
- `directional_benchmarks` is integrity-censused only.
- `/usr/bin/time -v` is process-health evidence, not a performance gate.
- Determinism: one semantic execution per selector identity; no semantic reruns.

## Unit-Test Design Check

CB37 changed four existing test assertions only. Their observable contract is frontier evidence publication/completeness, not one incidental terminal failure code. Names, ordinals, fixtures, selector membership and the substantive evidence assertions remain unchanged. TB32 therefore executes the immutable compiled tests; it does not edit or regenerate them.

## Stop and Blocker Conditions

Before semantic runtime, stop and preserve evidence as orchestration failure on any artifact/source/digest/mode mismatch, selector/hash/identity-map failure, zero/multiple owner, package/source/execution-view mutation, repair, or inability to preserve the complete ledger/raw logs.

After mechanically valid start, semantic REDs do not stop the selector. A per-process timeout is orchestration failure, never PASS/RED.

## Plan-Defined Reruns

- Semantic retries: none.
- Seed/order permutations: none.
- Nondeterminism investigation: TB32-REV only; no EXEC rerun.
- An orchestration-invalid attempt may be replaced only by an explicitly diagnosed control-plane correction with no product/test/fixture/selector/build mutation.

## TB32-REV Contract

TB32-REV consumes only the immutable TB32-EXEC evidence and performs **no runtime or implementation mutation**. It must:

1. verify package/source/selector/executable/identity-map/census integrity;
2. verify 408/408 rows selected exactly once with zero timeouts;
3. independently verify accepted 1..365;
4. adjudicate both frozen R4 falsifiers;
5. verify 390/393/406/407 are PASS or classify any failure as a blocking contradiction;
6. verify 368/369/370/374/398 remain RED and retain their existing owners unless immutable evidence independently proves otherwise;
7. classify the exact new 366/367 locus if either remains RED;
8. verify ownership publication and frontier evidence without equating the two partition component indices;
9. update regression/root-cause records only where evidence justifies a stable identity/count change;
10. freeze the next boundary. Independent review/planning is outsourced to a separate agent; the implementation loop stops at that boundary.

## Completion Criteria

TB32 is mechanically complete only when EXEC preserves all required raw evidence and REV can adjudicate every criterion without reconstructing intent from chat context.
