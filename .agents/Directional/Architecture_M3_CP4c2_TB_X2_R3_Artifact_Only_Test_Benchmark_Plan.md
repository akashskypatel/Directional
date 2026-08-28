# M3-CP4c-2-TB-X2-R3 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M3-CP4c-2-TB-X2-R3`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular Test + Benchmark: `TB-X2-R3-EXEC` -> `TB-X2-R3-REV`
- Evidence commit: `c552a5a4a318063cde2564c40773ec7edaf064f6`
- Immutable build artifact: `9704935112` (`m3-cp4c2-cb2diag-r1-z6-compile-result-33220315294`)
- Provider digest: `sha256:dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`
- Compile log artifact: `9704935373` / `sha256:1fc2250c00dd57e8cbd6385bde11857bc92126dfddfdf969ba188a67709651c0`
- Packaged source archive SHA-256: `e533669daa7ac0219bc6ca6bd7d72db2901af32937848c3f37f02b772345ae02`
- Benchmark execution: **none**

This plan validates only the corrected D1/D2 diagnostic authority authorized by Z0-Z9. It does not execute selector 355, 357, or 358, does not run a cumulative gate, and does not authorize CB3 before review.

## Immutable artifact preflight

Before executing any packaged binary, fail closed unless all of the following hold:

1. artifact ID/digest exactly match `9704935112` / `sha256:dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`;
2. extract with ordinary `unzip`/`tar` so archived executable mode bits are preserved. **Do not use Python `zipfile.extractall()` for executable payloads, do not `chmod`, and do not repair missing permissions/content**; a missing executable bit is orchestration failure;
3. `sha256sum -c SHA256SUMS` succeeds;
4. `metadata/source-commit.txt` equals `c552a5a4a318063cde2564c40773ec7edaf064f6`;
5. `metadata/preflight-exit-code.txt` and `metadata/build-exit-code.txt` are `0`;
6. every `metadata/source-status-*.txt` is empty;
7. `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
8. `metadata/gmp-evidence.txt` contains authoritative `gmpxx` and `gmp` link evidence;
9. `metadata/compiled-targets.txt` contains exactly the eight targets in the R1 Code + Build report;
10. `source/source-c552a5a4a318063cde2564c40773ec7edaf064f6.tar.gz` hashes to `e533669daa7ac0219bc6ca6bd7d72db2901af32937848c3f37f02b772345ae02` and is materialized read-only at the exact fixture-root path embedded in the binary. If that path cannot be satisfied without changing package/fixture bytes, **STOP**;
11. the packaged acceptance source recomputes frozen selector hashes unchanged:
    - first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
    - first 346: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
    - first 353: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
    - selector 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
    - selector 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
    - selector 358: `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.

Record a recursive pre-runtime byte/mode inventory and repeat it post-runtime. Any mutation is orchestration failure.

No configure, compile, relink, generated discovery, source patch, fixture mutation, or package repair is permitted.

## TB-X2-R3-EXEC — ordered runtime

### Step 1 — D1, mandatory torus-first control and Z3 self-consistency

Run exactly one fresh process:

```bash
./bin/directional_surface_cell_producer_tests \
  --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable
```

Execution requirements:

- exactly one GoogleTest identity is selected;
- capture complete stdout/stderr, exit code, timestamps, and selected-count evidence;
- D1's first `m3Cp4c2Y1` publication must be `witness=torus` because Z6 made the order authoritative;
- the torus record must publish `complex=sourceEdgeBarrier`, `railAuthority=pipeline-authoritative`, `surfaceCutGraphCalls=0`, and derive — not encode — `barrierV=48`, `barrierE=48`, `sourceChi=0`, `networkOnlyCellular=false`;
- torus must publish `oracleSelfConsistent=true`;
- if the torus control differs in any required value, **STOP immediately**. D2 must not execute;
- if torus passes, D1 must next publish `prescribed-sphere`, then `two-ring`;
- all three publications must use `oracleKind=independent-source-edge-barrier-complex`, `complex=sourceEdgeBarrier`, publish `railAuthority`, `mandatoryRailCount`, barrier definitions/provenance, disc/non-disc counts, `eulerIdentityMatches`, and `oracleSelfConsistent=true`;
- prescribed sphere must use `railAuthority=pipeline-authoritative`; two-ring must use `railAuthority=atlas-derived`;
- if D1 exits nonzero or any witness has `oracleSelfConsistent=false`, **STOP**. Preserve the last publication/assertion and do not run D2.

The EXEC agent must not infer a Y5 branch. It preserves raw D1 evidence only.

### Step 2 — D2, only after D1 passes completely

Only if Step 1 passes all Z6/Z3 conditions, run one separate fresh process:

```bash
./bin/directional_surface_cell_producer_tests \
  --gtest_filter=GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable
```

Requirements:

- exactly one GoogleTest identity selected;
- process exits 0;
- exactly one `m3Cp4c2Y2` prescribed-sphere publication;
- publication reports `oracleComplex=sourceEdgeBarrier`, `railAuthority=pipeline-authoritative`, `oracleSelfConsistent=true`, barrier provenance, `producerRederivationSite`, `localizedSite`, product error/locus class, and `localizationConsistent=true`;
- `localizationConsistent=false`, missing publication, a non-cellularity error, or unexpected mutation is **STOP / evidence conflict**, not a branch choice.

Preserve the entire publication verbatim.

### Step 3 — immutable postflight

After the last authorized process, repeat the package byte/mode inventory and immutable metadata checks. Any difference is orchestration failure.

## TB-X2-R3-REV — evidence review only

The review subturn consumes the preserved R3 execution evidence and runs **no new runtime**. Review in this order:

1. **Z6 control:** adjudicate whether corrected product-authoritative torus reproduced 48/48, source chi 0, non-cellular.
2. **Z3 consistency:** require all three D1 witnesses to have `oracleSelfConsistent=true`; state each `barrierV/E/F`, source chi, disc verdict, and authority.
3. **CAND-01:** resolve only if the corrected torus control actually reproduced 48/48 at runtime. Otherwise keep it active and stop.
4. **CAND-02:** resolve only if all three corrected D1 publications are self-consistent under the single named barrier complex. Otherwise keep it active and stop.
5. **D2 / CAND-04:** if D2 ran, adjudicate exact localization from the D2 publication without inventing an unmeasured product cause. Keep `CAND-04` active unless evidence actually closes its condition.
6. **Y5:** only after the above evidence is internally consistent, apply the already-frozen Y5 predicates from `Architecture_M3_CP4c2_TB_X2_Plan.md`. Publish exactly one `selected_r2_branch=<frozen branch>` or `selected_r2_branch=NONE` with blocker. Do not invent or merge branches.
7. Keep `selected_gate=NONE` and `gate_execution_authorized=false`; R3 does not execute or accept selector 357/358.

Every observed regression/candidate disposition must be recorded in `Regression_Root_Cause_Tracker.md` before the TB turn closes, per project policy.

## Explicitly prohibited in R3

- selector 355/357/358 runtime;
- full semantic or cumulative suite;
- benchmarks;
- compile/configure/relink or generated test discovery;
- source/test/fixture/build mutation;
- product/validator change or validation weakening;
- mechanical/C2, CP4c-3, or frozen product CB3 work;
- test-only injection past `SurfaceCutGraph` or synthetic Y5 evidence;
- unchanged retry of semantic red evidence.

## Stop/rerun rules

Stop and preserve raw evidence on any immutable-preflight/postflight mismatch, zero/multi-selected identity, torus-control mismatch, Z3 self-consistency failure, missing publication, D2 inconsistency, timeout/crash, or package mutation. A timeout/crash is orchestration/infrastructure failure, never semantic pass/skip.

A diagnosed infrastructure/orchestration failure may be retried only after its cause is recorded and only with the exact immutable package and unchanged semantics. Semantic red evidence is reviewed, not rerun unchanged.

## Completion criteria

`M3-CP4c-2-TB-X2-R3` is complete only when:

- immutable preflight/postflight are green;
- D1 raw evidence is preserved and Z6/Z3 explicitly adjudicated;
- D2 ran only if D1 fully passed, and its raw evidence is preserved if run;
- candidate dispositions and stable accounting are updated from evidence;
- Y5 selects one frozen branch or records `NONE` with blocker;
- `selected_gate=NONE`, no cumulative gate ran;
- handoff/TODO identify the exact next state without executing it in R3.
