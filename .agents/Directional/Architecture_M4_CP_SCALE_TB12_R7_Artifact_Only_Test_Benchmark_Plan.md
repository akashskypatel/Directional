# M4-CP-SCALE-TB12-R7-EXEC — Artifact-Only Test + Benchmark Plan

**Turn:** `M4-CP-SCALE-TB12-R7-EXEC`
**Type:** immutable artifact-only Test + Benchmark
**Predecessor:** `M4-CP-SCALE-CB20`
**Candidate:** artifact `10532133889`, semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Benchmark execution:** **0**

## 1. Scope

R7 is the fresh semantic retry after CB20 corrected only the R6 shell-orchestration defect. R7 must consume the unchanged CB18 candidate and the corrected frozen harness without rebuild, repair, source/test/fixture/selector mutation, harness regeneration, or package substitution.

R7 executes exactly the frozen 436-row gate:

```text
Gate A0 5 -> Gate A 4 -> S5 1 -> selector426 426 only if all ten focused rows are green
benchmark 0
exact immutable postflight required
```

No selector427 publication or package promotion occurs in EXEC.

## 2. Corrected control-plane authority

CB20 published and SchemaStore-validated the exact R7 caller:

- publication commit `df3a476bcdb1851ec033f96cad2357b764d327d8`;
- Git blob `a9705992bf85bfe8cc0caca7e8b6a94e099d89d5`;
- 4,870 bytes;
- SHA-256 `d2f8fe25701023bdad4843cfa6f608f2fed44980006bd73db699915728288279`;
- validation run/job `35323555381 / 105531346862`;
- validation artifact `10537559842`, SHA-256 `7393e133591f77b481f55a19f350c5adcaa959715740deec354dfb5f9c79fb87`, `valid=true`.

CB20 cleanup retires the temporary active caller. R7 must reinstall exactly those published bytes before creating its marker. After reinstallation require exactly:

```yaml
permissions:
  actions: read
  contents: write
  id-token: write
  issues: write
  pull-requests: write
```

The caller must retain durable schema validation and observer jobs, label `m4-cp-scale-tb12-r7-exec`, `commit_run_file=false`, and exact trigger path `.agents/connector-triggers/m4-cp-scale-tb12-r7-exec-20260918.txt` on the working branch. Caller installation and marker creation are separate commits. Caller installation must not execute runtime.

## 3. Corrected frozen harness

Use only Drive file `1Q1h9-W7AKuS1VP-IXJ__v4nqvmiNpNGV`, **18,479 bytes**, SHA-256 `04f3e8dd49b5521f5850d4bfc2eea4b8f04b4c4f4ef839974b55cd3b1c7e7cdf`.

CB20 proved that these bytes differ from the original 18,459-byte R5/R6 harness only by replacing the one same-command `local stem=... dir=...$stem work=...$stem` declaration with sequential nounset-safe declarations. `bash -n` and a non-Directional `set -u` micro-proof pass. Do not edit, regenerate, relabel internally, or repair the corrected harness in R7.

The corrected harness intentionally retains the historical internal `TURN_ID='M4-CP-SCALE-TB12-R5-EXEC'` and result-directory naming because CB20 was allowed to alter only the nounset declaration. The outer R7 caller supplies R7 workflow/artifact naming.

## 4. Immutable candidate preflight

Before any generated Directional runtime require candidate artifact `10532133889` to reproduce:

- artifact name `m4-cp-scale-cb18-result-35307991751`;
- provider ZIP SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- package manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`, **28/28** entries;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP` and GMP/GMPXX link evidence;
- six packaged executables mode `0755`, two static libraries mode `0644`;
- clean packaged source-status receipts.

From packaged source require:

- selector426: 426 LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- first425 prefix SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- no selector427;
- genus-two OBJ SHA-256 `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
- genus-two rawfield SHA-256 `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
- genus-two metadata SHA-256 `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

Any package/harness/hash/mode preflight mismatch is orchestration failure with zero semantic ledger, not semantic RED.

## 5. Complete ledger

Before the first test process materialize all **436** expected rows as `UNEXECUTED`:

- Gate A0: 5;
- Gate A: 4;
- S5: 1;
- selector426: 426.

Every identity executes in a fresh process with exact `--gtest_filter` and `GTEST_FAIL_IF_NO_TEST_SELECTED=1`. Require exactly one selected process, zero skips, and non-crash process execution for semantic classification. Selection mismatch, skipped-only, crash, or harness/process failure is orchestration failure.

## 6. Gate A0 — CB18 ownership seam and preserved predecessor behavior

Run in order:

1. `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle`
2. `FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts`
3. `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle`
4. `FieldTransportAtlas.PublishesCheckedSingularityPortAttachments`
5. `FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings`

Acceptance is **5/5 PASS**. Any valid semantic RED stops immediately with later rows `UNEXECUTED`.

## 7. Gate A — frozen cycle-order authority

Only after Gate A0 is 5/5, run:

1. `FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents`
2. `FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence`
3. `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper`
4. `FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow`

Acceptance is **4/4 PASS**. Any valid semantic RED stops before S5/selector426.

## 8. Gate B — S5 production witness

Only after focused predecessors are 9/9 PASS, run exactly once:

`M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`

Require one selected/executed process, zero skip and exit success under existing assertions. Preserve stdout/stderr hashes and any S5 receipt. A valid RED is semantic evidence and stops before selector426.

Interpretation remains frozen: a PASS is focused evidence only and grants no selector credit; a RED at the same seam falsifies CB18; a RED at a new later seam means the boundary advanced and requires Review/root-cause classification before any corrective turn. If R7 exposes a **third distinct product root cause** on this same S5 path, Review must route to a definition turn rather than another bounded product CB.

## 9. Gate C — accepted predecessor selector

Only if all ten focused rows are green, execute selector426 **426/426**, one frozen identity per fresh process. Require:

- 426 selected identities;
- 426 executed once;
- 426 PASS;
- 0 RED / 0 skip / 0 selection mismatch / 0 crash;
- owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**.

A selector RED stops. Do not retry or benchmark.

## 10. Postflight and result routing

Benchmark execution is **0**. After the organic stop point repeat exact package/source/execution-view censuses and require equality with preflight, including manifest/source archive/selector/first425/genus-two hashes and modes.

- **All gates green:** record candidate mechanically green; exact next `M4-CP-SCALE-TB12-R7-REV`. Do not publish selector427 or promote package authority in EXEC.
- **Semantic RED:** preserve fail-fast ledger and deepest error; exact next `M4-CP-SCALE-TB12-R7-REV`. No corrective CB before Review.
- **Orchestration/integrity failure:** no semantic acceptance/rejection; preserve invalid-attempt provenance and route to the smallest orchestration-correction CB.

Accepted authority remains package `10473134357` / selector426 until a valid semantic runtime plus mandatory Review changes it.

## 11. Required evidence

Retain at least:

- R7 marker/event SHA and observer-confirmed run ID;
- exact workload job ID;
- active caller blob/hash and corrected harness Drive ID/hash;
- result/log artifact IDs and provider SHA-256 values;
- package/source identity and 28/28 manifest receipt;
- preflight/postflight byte/mode/hash censuses;
- complete 436-row ledger;
- one record per executed process with binary/filter/counts/exit/stdout/stderr hashes;
- focused S5 receipt/deepest error when applicable;
- selector owner census if Gate C executes;
- explicit `benchmarkExecuted=0`, configure/compile/relink/mutation/repair flags false.
