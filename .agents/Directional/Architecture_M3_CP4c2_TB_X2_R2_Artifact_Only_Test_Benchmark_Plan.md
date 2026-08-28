# M3-CP4c-2-TB-X2-R2 Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M3-CP4c-2-TB-X2-R2`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular Test + Benchmark: `TB-X2-R2-EXEC` -> `TB-X2-R2-REVIEW`
- Evidence commit to validate: `232ac459b13657529e064272a75c5583770a5963`
- Immutable build artifact: `9702321260` (`m3-cp4c2-cb2-diag-result-33212932401`)
- Outer artifact digest: `sha256:05237f108a65c73df81b6b125d6fcecad10ad9b5af4104ecce3c6bb9f6642035`
- Compile log artifact: `9702321551` / `sha256:236458a4146ebec93638065a0f55500e8bb77dbf216d1d7b942f667be4070ab3`
- Packaged source archive SHA-256: `986db8b91d06eab4284f3a0e49c1d8c9ad2676df61fdfdd4a94e56ba34a5644f`
- Planned platform: GitHub-hosted Ubuntu runner, **artifact-only**; no configure, compile, relink, patch, fixture mutation, or generated test discovery.

## Validation Objective

Evaluate the missing Y1-Y4 evidence required by the frozen `Architecture_M3_CP4c2_TB_X2_Plan.md` before any Y5 branch choice:

1. independently determine whether the prescribed-sphere, torus, and two-ring network complements are unions of discs without using `SurfaceCutGraph`;
2. localize the prescribed-sphere `CellularityNotEstablished` result to producer site 419, 437, or 474 and publish the producer's re-derived accounting terms beside the independent oracle terms;
3. confirm or refute the whole-source-edge coarsening/unit-mismatch hypothesis from those numbers;
4. verify the torus control remains `V=48`, `E=48`, source `chi=0`, and non-cellular;
5. in REVIEW, select exactly one frozen Y5 branch or stop if the evidence is insufficient/inconsistent.

This turn does **not** prove either frozen cumulative gate, does not execute selector 357/358, and does not authorize `TB-GATE-EXEC`.

## Preconditions

Before executing any packaged binary, fail closed unless all of the following hold:

- downloaded artifact identity is `9702321260` and its provider digest is `sha256:05237f108a65c73df81b6b125d6fcecad10ad9b5af4104ecce3c6bb9f6642035`;
- `sha256sum -c SHA256SUMS` succeeds for the extracted package;
- `metadata/source-commit.txt` is exactly `232ac459b13657529e064272a75c5583770a5963`;
- `metadata/preflight-exit-code.txt` and `metadata/build-exit-code.txt` are `0`;
- every `metadata/source-status-*.txt` file is empty;
- `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- `metadata/gmp-evidence.txt` contains both `gmpxx` and `gmp` link evidence;
- `metadata/compiled-targets.txt` contains exactly the eight CB2-DIAG targets recorded by the Code + Build report;
- packaged source archive hashes to `986db8b91d06eab4284f3a0e49c1d8c9ad2676df61fdfdd4a94e56ba34a5644f` and is materialized at the exact fixture-root path expected by the packaged binary before runtime. If the compiled `DIRECTIONAL_TEST_SOURCE_DIR` cannot be satisfied without changing fixture bytes, **STOP** rather than rebuilding or patching;
- packaged `tests/SurfaceCellAcceptanceTests.cpp` recomputes the frozen selector hashes exactly:
  - first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
  - first 346: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
  - first 353: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
  - selector 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
  - selector 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
  - selector 358: `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.

Preserve a pre-runtime inventory/hash record of package files and a post-runtime inventory/hash record. Any mutation is orchestration failure.

## Ordered Execution Plan

### 1. D1 — independent network-only cellularity publication

Execute exactly one fresh process:

```bash
./bin/directional_surface_cell_producer_tests   --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable
```

Purpose:
- publish one `m3Cp4c2Y1` record each for `prescribed-sphere`, `torus`, and `two-ring`;
- establish source `V/E/F/chi`, network `V/E/F/chi`, exact network-edge parts, component topology/boundary cycles, and `networkOnlyCellular` independently of `SurfaceCutGraph`.

Execution acceptance:
- exactly one GoogleTest identity selected;
- process exits `0`;
- exactly three `m3Cp4c2Y1` witness publications appear;
- every publication contains `oracleKind=independent-network-complement-arrangement` and `surfaceCutGraphCalls=0`;
- no source/package mutation occurs.

Semantic review requirements (not EXEC assertions):
- record all three witness publications verbatim;
- the torus control must report `networkV=48`, `networkE=48`, `sourceChi=0`, and `networkOnlyCellular=false`; otherwise **STOP** because the independent oracle/control is invalid;
- do not assume the prescribed-sphere result in advance. Whatever it reports is the Y1 evidence.

Preserve stdout, stderr, process exit, selected-count evidence, timestamps, and the exact command.

### 2. D2 — prescribed-sphere failure localization and accounting publication

Only after D1 completed without orchestration failure, execute one separate fresh process:

```bash
./bin/directional_surface_cell_producer_tests   --gtest_filter=GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable
```

Purpose:
- publish the prescribed-sphere independent-oracle terms and the test-side re-derived producer terms;
- classify the product publication as site 419/437/474 (or success/non-cellularity error) and verify the published error locus is consistent with the re-derivation;
- make the leading unit-mismatch/coarsening hypothesis numerically decidable.

Execution acceptance:
- exactly one GoogleTest identity selected;
- process exits `0`;
- exactly one `m3Cp4c2Y2` publication appears;
- publication includes `producerRederivationSite`, `localizedSite`, `localizationConsistent`, `oracleV/E/F/Chi`, `producerReDerivationV/E/F/Chi`, all component counts, and the product's published error/locus class;
- `localizationConsistent=true`; otherwise **STOP / evidence conflict** rather than selecting a branch;
- no source/package mutation occurs.

Preserve the full publication verbatim; do not reduce it to only the localized site.

### 3. R2 evidence review — Y1-Y4

`TB-X2-R2-REVIEW` consumes only the preserved D1/D2 evidence. It does not execute new runtime.

Review in this order:

1. **Y1 / independent cellularity:** state the prescribed-sphere result and component proof; also state both controls.
2. **Y2 / exact producer site:** use D2's re-derivation plus the actual product error/locus. If D1 says every prescribed-sphere component is a disc and the cut set is empty, sites 419/437 are structurally unreachable; a no-locus `CellularityNotEstablished` must therefore agree with site 474. If the evidence says otherwise, stop as an oracle/re-derivation conflict.
3. **Y3 / hypothesis adjudication:** compare the independent arrangement `F` and the producer's whole-carrier-edge component `F`, together with both `V/E/chi` equations. Explicitly write **CONFIRMED** or **REFUTED** for the unit-mismatch/coarsening hypothesis and cite the numerical terms that decide it.
4. **Y4 / torus control:** require `V=48`, `E=48`, `source chi=0`, non-cellular. A control failure invalidates R2.

### 4. Y5 — select exactly one frozen corrective branch or stop

Only after Y1-Y4 are complete and internally consistent, select the corresponding branch already frozen by `Architecture_M3_CP4c2_TB_X2_Plan.md`. Do not invent a fourth branch or merge branches.

The review must publish:

- `selected_r2_branch=<frozen branch name>` **or** `selected_r2_branch=NONE` with an explicit blocker;
- the exact evidence clauses satisfying that branch predicate;
- the bounded `M3-CP4c-2-CB3` authorization implied by that branch, if any;
- `selected_gate=NONE` and `gate_execution_authorized=false` regardless of R2 branch selection. The cumulative 357/358 gate is intentionally still deferred until post-certificate R3 completes the remaining frozen decision evidence.

## Related Regression / Integration / Full Validation

Not executed in R2. This turn is deliberately a measurement/localization TB, not a cumulative acceptance run. In particular:

- do not run selector 355, 357, or 358;
- do not run the full semantic suite;
- do not run benchmarks;
- do not execute mechanical/C2, C1/C3/C6 cumulative gates, CP4c-3, or any post-certificate A2b identity not already authorized by the frozen R2 plan;
- do not configure, compile, relink, regenerate fixtures, or modify test/product code.

The next runtime expansion is determined only after R2 review selects Y5 and the resulting CB3 is separately implemented and compiled.

## Benchmark Plan

- Applicable: **no**.
- No performance claim is under evaluation in `TB-X2-R2`.

## Unit-Test Design Check

- Contract under test: D1 independently measures the topology of the published curve network's complement; D2 localizes current product accounting without changing the product.
- Scenario/boundary: prescribed sphere is the disputed traced witness; torus is the zero-trace non-cellular control; two-ring is the additional independent control required by the frozen plan.
- Why values expose broken behavior: torus has a known Euler obstruction (`48-48+F=0` cannot hold for nonempty disc complement); prescribed sphere has traces/coarsening and is the first witness that exposed the suspected accounting mismatch.
- Isolation rationale: D1 excludes `SurfaceCutGraph` by construction; D2 intentionally mirrors producer accounting only for comparison/localization and is not used to establish D1 cellularity.
- Assertion semantics: setup/orchestration failures are hard assertions; predicted topology/accounting outcomes are **published, not asserted**, so the diagnostic cannot manufacture the frozen branch by encoding the expected answer.

## Stop and Blocker Conditions

Stop immediately and preserve all evidence if:

- artifact/source/digest/GMP/target/selector preflight differs from this plan;
- fixture-root materialization cannot reproduce the compiled read-only fixture path without mutation;
- either process selects zero or more than one test identity;
- required Y1/Y2 publication count/tokens are missing;
- torus control fails its fixed values;
- D2 reports `localizationConsistent=false`;
- pre/post package inventory differs;
- runtime requires configure/compile/relink/fixture mutation;
- evidence is internally inconsistent or insufficient to choose one frozen Y5 branch.

A timeout/crash/orchestration failure is never semantic pass or skip.

## Plan-Defined Reruns

- No unchanged deterministic rerun is permitted.
- A diagnosed infrastructure/orchestration failure may be retried only after the cause is recorded and the retry preserves the exact immutable package/source and runtime semantics.
- Semantic red evidence is reviewed; it is not rerun until green.

## Completion Criteria

`M3-CP4c-2-TB-X2-R2` is complete only when:

- immutable-package preflight and postflight are green;
- D1 and D2 raw evidence are preserved completely;
- Y1-Y4 are explicitly adjudicated from those publications;
- Y5 selects exactly one frozen corrective branch or records a justified `NONE` blocker;
- `selected_gate=NONE` and cumulative gate runtime remains blocked;
- regression/root-cause documentation is updated if runtime reveals a new/stable recurrence under project policy;
- the handoff names the exact next state (`CB3` for a selected branch, or planning/review stop if none) without executing it in the R2 turn.
