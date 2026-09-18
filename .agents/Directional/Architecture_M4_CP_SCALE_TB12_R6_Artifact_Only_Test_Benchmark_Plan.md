# M4-CP-SCALE-TB12-R6-EXEC — Artifact-Only Test + Benchmark Plan

**Turn:** `M4-CP-SCALE-TB12-R6-EXEC`
**Type:** Test + Benchmark / immutable artifact only
**Consumes:** CB18 candidate artifact `10532133889`
**Semantic source:** `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Frozen harness:** Drive `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`
**Mutation/compile/relink:** forbidden

## 1. Goal

Re-execute the semantic plan that R5 never reached, now through the CB19-corrected control plane. Determine whether the CB18 separating-hard-feature singularity ownership correction is runtime-valid without changing any package byte or harness byte. First prove the direct ownership seam and preserved predecessor behavior, then re-prove the frozen CB16/CB17 ordering controls, retry the unchanged genus-two S5 production witness, and only if every focused gate is green execute selector426 in full.

R6 cannot publish selector427, patch code/tests/fixtures, repair the package, regenerate the harness, configure CMake, compile/relink, or promote the candidate by assertion.

## 2. Corrected control-plane precondition

CB19 installed `.github/workflows/m4-cp-scale-tb12-r6-exec.yml` from a pre-publication validated draft. The active caller and validated draft share Git blob `c31306fce7c7dbf96bb2b80859f285062460b26d`; caller byte SHA-256 is `6a673c9a8a8cd146dfc56f28d746ec928b6de34781eaa51a58231017645063eb`.

Before creating any execution marker, require the active caller to retain exactly:

```yaml
permissions:
  actions: read
  contents: write
  id-token: write
  issues: write
  pull-requests: write
```

The caller must still use:

- schema validator `.github/workflows/agent-workflow-schema-validator-reusable.yml`;
- observer `.github/workflows/agent-run-observer-reusable.yml`, label `m4-cp-scale-tb12-r6-exec`, `commit_run_file=false`;
- exact trigger path `.agents/connector-triggers/m4-cp-scale-tb12-r6-exec-20260918.txt` on the working branch only;
- Drive file `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC` and expected harness SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`;
- no workflow/job elapsed-time watchdog around the full semantic gate.

CB19 validation run `35315434185`, job `105505987470`, validated the exact draft against SchemaStore with `valid=true`; result artifact `10535275417` hashes to `ec90baa515ecbfe92bf53e8c6dce73578d06ac4c455fec3babfbcb144d0418c6`.

The R6 execution marker was absent at CB19 handoff. R6 itself creates it in one later commit; that marker commit is the execution trigger and its SHA must match the observer report before workload evidence is accepted.

## 3. Frozen harness rule

The semantic runner is the exact 18,459-byte R5 harness retained at the Drive ID above. R6 must download those bytes with the caller's Google Workload Identity path and verify the exact SHA-256 before execution. **Do not regenerate, patch, rename internally, or replace the harness.** Its internal `TURN_ID='M4-CP-SCALE-TB12-R5-EXEC'` and `M4-CP-SCALE-TB12-R5-EXEC-result` path are expected frozen-byte properties; the outer R6 caller names the new run/artifacts.

The later duplicate run `35312751970 / 105497993610` is invalid-attempt provenance only because it ran before CB19 and used regenerated harness bytes. Its observed row-1 RED may be recognized if reproduced, but it may not be imported as R6 semantic evidence, used to skip execution, or used to alter the R6 plan.

## 4. Immutable package authority

Before any generated Directional runtime, the frozen harness must fetch artifact `10532133889` and require:

- artifact name `m4-cp-scale-cb18-result-35307991751`;
- artifact ZIP SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- exact packaged semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- root `SHA256SUMS` **28/28**, manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP` in packaged command-boundary evidence;
- GMP/GMPXX authoritative link evidence;
- six packaged executables mode `0755`, two static libraries mode `0644`;
- all packaged source-status receipts empty/clean.

Extraction must use ordinary `unzip`/`tar` semantics that preserve archived executable mode bits. Do not repair missing modes or package bytes. A preflight mismatch is **orchestration failure / zero semantic ledger**, not a product/test RED.

From the immutable packaged source require:

- selector426 exactly 426 LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- first425 prefix SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- no selector427;
- `genus_two.obj` SHA-256 `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
- `genus_two.rawfield` SHA-256 `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
- `genus_two.fixturemeta.json` SHA-256 `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

## 5. Complete ledger initialization

Before the first test process, materialize the complete **436-row** expected ledger with every row `UNEXECUTED`:

- Gate A0 ownership/preservation: **5** rows;
- frozen Gate A cycle-order authority: **4** rows;
- S5 focus: **1** row;
- selector426: **426** rows.

Every runtime identity executes in a fresh process with an exact `--gtest_filter` and `GTEST_FAIL_IF_NO_TEST_SELECTED=1`. Exactly one selected process, zero skips and a non-crash exit are required for semantic classification. Zero-selected, multi-selected, skipped-only, crash or similar process failure is orchestration failure, not semantic evidence.

## 6. Gate A0 — CB18 ownership seam and preserved predecessor behavior

Run in order, one fresh process each:

1. `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle`
2. `FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts`
3. `FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle`
4. `FieldTransportAtlas.PublishesCheckedSingularityPortAttachments`
5. `FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings`

Acceptance is **5/5 PASS**. Any valid semantic RED stops immediately. Leave all later rows `UNEXECUTED`; do not retry or repair.

## 7. Gate A — frozen CB16/CB17 cycle-order authority

Only after Gate A0 = 5/5 PASS, run:

1. `FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents`
2. `FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence`
3. `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper`
4. `FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow`

Acceptance is **4/4 PASS**. Any valid semantic RED stops before S5 and selector426.

## 8. Gate B — unchanged S5 production retry

Only after Gates A0+A = 9/9 PASS, run exactly once:

`M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`

Acceptance requires one selected/executed process, zero skip and exit success under its existing assertions. Preserve exact stdout/stderr hashes and any S5 receipt. A valid RED is semantic evidence; preserve the deepest stage/error/locus and stop before selector426.

## 9. Gate C — full accepted predecessor selector

Only if all ten focused processes are green, execute selector426 **426/426**, one exact selector identity per fresh process using the frozen source-derived owner map. No dynamic discovery or filter alteration is allowed.

Acceptance requires:

- 426 selected identities;
- 426 executed once;
- 426 PASS;
- 0 RED / 0 skip / 0 selection mismatch / 0 crash;
- owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**.

A selector RED is semantic evidence and stops. Do not retry or benchmark.

## 10. Benchmark disposition and immutable postflight

**Benchmark execution is 0.** CB18 changed no benchmark semantics and S5 is a semantic reachability/topology obligation.

After the organic runtime stop point, repeat exact package/source/execution-view censuses and require equality with preflight, including manifest/source archive/selector/first425/genus-two hashes and modes. Any postflight mismatch is orchestration/integrity failure and invalidates semantic classification for the attempt.

## 11. Result classification and successor

### All gates green

If Gate A0 = 5/5, Gate A = 4/4, S5 = 1/1 and selector426 = 426/426 with exact postflight, record the CB18 candidate as mechanically green. Do **not** publish selector427 or promote package authority inside EXEC. Exact next is runtime-free `M4-CP-SCALE-TB12-R6-REV` for S5/A3 and any selector-publication adjudication.

### Semantic RED

Any valid semantic RED stops immediately and leaves later ledger rows `UNEXECUTED`. Accepted runtime authority remains package `10473134357` / selector426. Exact next is `M4-CP-SCALE-TB12-R6-REV`; no retry or corrective CB is permitted before Review.

### Orchestration failure

A caller/harness/Drive/package/extraction/mode/selection/integrity failure creates no semantic acceptance/rejection. Preserve invalid-attempt provenance and route to the smallest orchestration-correction Code + Build turn, reusing artifact and frozen harness unchanged where possible.

## 12. Required retained evidence

Retain at least:

- R6 marker/event SHA and observer-confirmed workflow run ID;
- exact workload job ID;
- active caller blob/hash and frozen harness Drive ID/hash;
- result and persistent-log artifact IDs/provider SHA-256 values;
- exact package/source identity and 28/28 manifest receipt;
- preflight/postflight byte/mode/hash censuses;
- complete 436-row ledger with PASS/RED/UNEXECUTED status;
- one record per executed process: binary, exact filter, selected/executed/skipped counts, exit code, stdout/stderr hash;
- focused S5 receipt/deepest error if RED;
- selector owner census if Gate C executes;
- explicit `benchmarkExecuted=0`, configure/compile/relink/mutation/repair flags false.

No repository source/test/fixture/selector/build logic may be edited in R6 EXEC.
