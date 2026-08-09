# T1 Direct-Oracle Execution Order — Code + Build Plan

**Status:** Code + Build completed; following immutable Test + Benchmark required  
**Turn type:** Code + Build only  
**Production behavior delta:** none  
**Review policy:** `never`  
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8

Completed Code + Build authority is recorded in:

`.agents/Directional/Test_Architecture_T1_Direct_Oracle_Execution_Order_Code_Build_Report.md`

Implementation `7c169ddf8167093c16755f2160e224994e50307c` compiled/package-verified under workflow run/job `31324710550 / 93273122696`. The following turn must consume immutable result/log artifacts `9041289209 / 9041289317` exactly. This plan remains the design/scope authority for the correction; it is no longer the active Code + Build instruction.

## 1. Objective

Close the one T1 immutable-acceptance defect exposed by artifact `9040549377`:
the direct acceptance family evaluates `ASSERT_TRUE(result.success)` before the
new independent product oracle, so any returned known-red production result
terminates the test body before independent input/output evidence is recorded.

Make the oracle execute for every **returned** `RemeshResult` before the
existing fatal product-success assertion. Preserve every existing product,
backend, fallback/recovery, origin, schema, degree, and success assertion
unchanged. Do not turn Bunny/Vase into expected-green or expected-failure tests.
Known-red product status remains explicit.

This is a test-integration correction only. It does not authorize M1 or any
production change in this Code + Build turn.

## 2. Entering evidence

Authoritative runtime report:

`.agents/Directional/T1_Independent_Test_Oracle_Foundation_Artifact_Only_Test_Benchmark_Report.md`

Artifact `9040549377` established:

- exact package preflight/postflight and `runtimeExecution=false` build boundary;
- oracle discovery **29/29** exactly matching the immutable manifest;
- all **29/29** positive/mutation/metamorphic oracle contracts pass individually;
- retained focused contracts **18/18**;
- bounded suites remain producer **154/163**, completion **154/164**,
  validation **71/71**, API **8/8**;
- plane, seam, close sheets, cylinder direct tests pass and reach the oracle;
- BunnyRandom returns `NotProductionReady:completion` after 57.225 s and stops
  at `ASSERT_TRUE(result.success)` before oracle execution;
- Vase does not return within the bounded 60 s validation guard and therefore
  cannot supply an oracle result in that process.

Normative testing policy keeps known-red direct cases discovered and explicit;
they are not counted as required-green proof until promoted by later immutable
product acceptance.

## 3. Mandatory repeated-pattern review

| Pattern | Touched? | Required invariant | Following immutable evidence |
|---|---|---|---|
| `RP-01` | no semantic-domain change | preserve accepted typed oracle domains unchanged | 29/29 mutation suite unchanged |
| `RP-02` | **yes, primary** | independent oracle observation must not be guarded by a prior production-success assertion; every returned result is inspected independently | Bunny returned failure emits oracle report before unchanged product failure; four green cases still pass; 29/29 oracle suite |
| `RP-03` | no | production disposition and oracle report remain separate observations | disposition mutation suite unchanged |
| `RP-04` | no | no new work/search/recursion; only statement ordering changes | compile inspection; following bounded runtime |
| `RP-05` | no | canonical identity implementation unchanged | metamorphic oracle test unchanged |
| `RP-06` | no | no storage change | byte-identical production and oracle support |
| `RP-07` | no | cyclic logic unchanged | oracle cyclic/reversal tests unchanged |
| `RP-08` | no | no producer/fallback behavior change | direct options/assertions byte-equivalent except oracle statement position |
| `RP-09` | no | no chart/relation authority change | retained 18 focused contracts; direct torus remains separate known-red |

No new historical regression ID is created for this correction. T1 had not
reached immutable acceptance; this is incomplete `RP-02 / TA-05` work inside
the new test architecture.

## 4. Allowed scope

Allowed source path:

- `tests/SurfaceCellDesignAcceptanceTests.cpp`.

Allowed status/report paths only for truthful closeout:

- this plan/report family;
- `TODO`;
- `MILESTONE_G_TODO.md`;
- `.agents/Directional/Future_Chat_Session_Handoff.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md` only when status text
  must reflect exact immutable evidence.

A temporary bounded compile/package workflow may be used under the established
remote Code + Build procedure and must be removed before closeout.

Prohibited:

- production source or public API changes;
- oracle support or oracle mutation logic changes;
- fixtures, benchmark manifest, benchmark quality, production validator,
  tracing, arrangement, completion, optimizer, pipeline, or CMake behavior
  changes;
- assertion deletion, weakening, expected-failure conversion, skip/disable,
  fixture special cases, or timeout-as-success;
- running generated project binaries, tests, discovery, benchmarks, `ctest`,
  CLI/help/version, or custom inputs during Code + Build.

If anything beyond statement ordering in the direct acceptance test is required,
stop and return to Review rather than expanding scope.

## 5. Required code shape

Current shape at the entering implementation:

```text
result = production_call(...)
ASSERT_TRUE(result.success)          # fatal: returned red result stops here
... existing product assertions ...
independentOracle = inspect(input, result)
EXPECT_TRUE(independentOracle.ok())
```

Required and now compiled shape:

```text
result = production_call(...)
independentOracle = inspect(input, result)
EXPECT_TRUE(independentOracle.ok())  # nonfatal independent observation
ASSERT_TRUE(result.success)          # unchanged product contract remains fatal
... every existing product assertion unchanged ...
```

The independent oracle must be evaluated exactly once per returned direct
result. Do not catch, reinterpret, suppress, or translate its issues into
production success/failure.

A process that never returns from production cannot be inspected; that remains
bounded product/runtime evidence, not a reason to synthesize an oracle result.

## 6. Code + Build acceptance

The completed Code + Build satisfied the compile/package portion of these requirements:

1. the implementation diff is confined to
   `tests/SurfaceCellDesignAcceptanceTests.cpp` plus truthful status records;
2. production sources, fixtures, oracle support/tests, CMake, validators, and
   benchmark behavior are byte-identical;
3. static diff proves every existing direct assertion remains present with the
   same predicate and expected value;
4. `inspect_surface_cell_product(...)` is evaluated immediately after the
   returned `RemeshResult` and before `ASSERT_TRUE(result.success)`;
5. all eight previously approved Release/static/Ninja targets compile/link;
6. package metadata still contains the same oracle executable, labels, and
   exact 29-name manifest;
7. `runtimeExecution=false`; no generated project executable was run;
8. immutable result artifact `9041289209` and log artifact `9041289317` were
   produced for the following Test + Benchmark turn.

Compilation is not runtime acceptance.

## 7. Required following immutable Test + Benchmark

Consume result artifact `9041289209` and log artifact `9041289317` exactly without rebuild or source edit.

1. verify package/source/dependency closure and `runtimeExecution=false`;
2. discover `directional_surface_cell_oracle_tests` exactly once and require the
   same exact 29-name manifest;
3. run all 29 oracle contracts individually and require **29/29**;
4. retain the 18 focused contracts and bounded producer/completion/validation/
   API authority;
5. run the six existing direct acceptance cases in fresh processes;
6. require plane, seam, close sheets, and cylinder to remain green and show no
   oracle issue;
7. for every direct process that returns a failed product, require independent
   oracle diagnostics to appear before the unchanged product-success failure;
8. keep Bunny/Vase known-red product status explicit; do not count them green,
   disable them, or convert them to expected failure;
9. use a bounded process guard for any nonreturning known-red case and classify
   timeout as runtime evidence only, never correctness acceptance;
10. update T1 as accepted only if there is no oracle false positive/negative,
    no missing discovery/label/source authority, no assertion weakening, and
    every returned direct result reaches the oracle.

If accepted, M1 authority-kernel Code + Build may begin. T2 remains responsible
for the complete ten-case semantic fixture matrix and declared per-case
resource budgets.
