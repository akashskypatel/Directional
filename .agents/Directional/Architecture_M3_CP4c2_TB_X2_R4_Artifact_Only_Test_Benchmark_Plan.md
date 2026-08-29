# M3-CP4c-2-TB-X2-R4 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M3-CP4c-2-TB-X2-R4`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular Test + Benchmark: `TB-X2-R4-EXEC` -> `TB-X2-R4-REV`
- Evidence commit: `5ad711e5d4ced95f38e103b993139a6307ba2cee`
- Immutable build artifact: `9707091209` (`m3-cp4c2-cb2-diag-r2-package-result-33226609913`)
- Provider digest: `sha256:e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63`
- Compile log artifact: `9707091377` / `sha256:0188b2926df2d77b5885a6560ba358f325d709d3b57f326b3a2abf5473bfe3b2`
- Packaged source archive SHA-256: `9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11`
- Benchmark execution: **none**

This plan validates only the corrected D1/D2 diagnostic authority authorized by Z10-Z19. It does not execute selector 355, 357, or 358, does not run a cumulative gate, and does not authorize product CB3 before review.

## Immutable artifact preflight

Before executing any packaged binary, fail closed unless all of the following hold:

1. artifact ID/digest exactly match `9707091209` / `sha256:e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63`;
2. extract with ordinary `unzip`/`tar` so archived executable mode bits are preserved. Do not use Python `zipfile.extractall()` for executable payloads, do not `chmod`, and do not repair package content;
3. `sha256sum -c SHA256SUMS` succeeds;
4. `metadata/source-commit.txt` equals `5ad711e5d4ced95f38e103b993139a6307ba2cee`;
5. `metadata/preflight-exit-code.txt` and `metadata/build-exit-code.txt` are `0`;
6. every `metadata/source-status-*.txt` is empty;
7. `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
8. `metadata/gmp-evidence.txt` contains authoritative `gmpxx` and `gmp` link evidence;
9. `metadata/compiled-targets.txt` contains exactly the eight targets in the R2 Code + Build report;
10. `source/source-5ad711e5d4ced95f38e103b993139a6307ba2cee.tar.gz` hashes to `9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11` and is materialized read-only at the exact fixture-root path embedded in the binary. If that path cannot be satisfied without changing package/fixture bytes, **STOP**;
11. the packaged acceptance source recomputes frozen selector hashes unchanged:
    - first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
    - first 346: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
    - first 353: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
    - selector 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
    - selector 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
    - selector 358: `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.

Record a recursive pre-runtime byte/mode inventory and repeat it post-runtime. Any mutation is orchestration failure.

No configure, compile, relink, generated discovery, source patch, fixture mutation, or package repair is permitted.

## Static source warning that constrains interpretation

The R2 Code + Build closeout found that production currently copies `sourceTopologyRegions`, `fieldTransportAtlas`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, and `globalTopologyPlan` into `productSnapshots` only after both cut-graph and global-plan production succeed. The torus is known to terminate at `SurfaceCutGraph`, so its snapshot may report atlas/network unavailable even though those products were constructed earlier in the pipeline.

This is not runtime evidence and does not alter the test oracle. It changes only the stop interpretation: **snapshot unavailability is a Z12 review stop, not a 48/48 mismatch and not authorization to run D2 or choose Y5.**

## TB-X2-R4-EXEC — ordered runtime

### Step 1 — D1, unconditional per-witness publication first

Run exactly one fresh process:

```bash
./bin/directional_surface_cell_producer_tests \
  --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable
```

Execution requirements:

- exactly one GoogleTest identity is selected;
- capture complete stdout/stderr, exit code, timestamps, and selected-count evidence;
- preserve every `m3Cp4c2Y1` line verbatim before interpreting success/failure;
- require **exactly one record for each** `witness=torus`, `witness=prescribed-sphere`, and `witness=two-ring`, even when one construction fails;
- every record publishes `witnessConstruction=` and `constructionSucceeded=`;
- torus and prescribed sphere use `witnessConstruction=pipelineProducts`; two-ring uses `witnessConstruction=constructed`;
- a construction failure must be a typed failure record and must not suppress either remaining witness;
- for pipeline witnesses, preserve `pipelineAtlasAvailable`, `pipelineNetworkAvailable`, `pipelineCutGraphAvailable`, `pipelinePlanAvailable`, `terminalFailureCode`, and `terminalFailureStage`.

**Z12 stop gate:** if the torus reports `pipelineAtlasAvailable=false` or `pipelineNetworkAvailable=false`, or otherwise cannot publish a successful network record, Step 1 is a valid diagnostic semantic red if all three witness records were still emitted. **STOP before D2.** Do not call this a 48/48 mismatch; route the evidence to R4-REV.

Only if the torus construction succeeds:

- its record must publish `complex=sourceEdgeBarrier`, `railAuthority=pipeline-authoritative`, `surfaceCutGraphCalls=0` and derive — not encode — `barrierV=48`, `barrierE=48`, `sourceChi=0`, `networkOnlyCellular=false`;
- it must publish `oracleSelfConsistent=true`;
- if those values differ, **STOP before D2**.

Only if all three witnesses construct successfully:

- all three must use `oracleKind=independent-source-edge-barrier-complex`, `complex=sourceEdgeBarrier` and publish barrier definitions/provenance, disc/non-disc counts, `eulerIdentityMatches`, and `oracleSelfConsistent=true`;
- prescribed sphere uses `railAuthority=pipeline-authoritative`; two-ring uses `railAuthority=atlas-derived`;
- if any witness has `oracleSelfConsistent=false` or D1 otherwise exits nonzero after successful construction, **STOP before D2**.

The EXEC agent does not infer a Y5 branch. It preserves raw D1 evidence only.

### Step 2 — D2, only after D1 fully passes Z17 steps 1-3

Only if Step 1 produced all three records, torus reproduced 48/48 from authority, and all three witnesses passed self-consistency, run one separate fresh process:

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

## TB-X2-R4-REV — evidence review only

The review subturn consumes the preserved R4 execution evidence and runs **no new runtime**. Review in this order:

1. **Z13 closure evidence:** confirm D1 emitted one record for all three witnesses even if one failed. Resolve `R3-CAND-02` only if the runtime proves witness isolation.
2. **Z12 product-snapshot availability:** adjudicate the torus `pipelineAtlasAvailable` / `pipelineNetworkAvailable` publication. If either is false, stop the branch/gate review and determine whether the independent review's product-snapshot premise requires a new bounded authority decision. Do not call missing retention a 48/48 contradiction.
3. **Torus control:** only when a successful torus network record exists, adjudicate 48/48, source chi 0, non-cellular from authority.
4. **Z3 consistency:** only for successfully constructed witnesses, state each barrier V/E/F, source chi, disc verdict, and `oracleSelfConsistent` result. R2 CAND-02 closes only if all three corrected publications satisfy its existing closure condition.
5. **R2 CAND-01 / R3 CAND-01:** close runtime conditions only if the corrected product-authoritative torus actually reaches a published network and reproduces the frozen control. Otherwise preserve the distinction between fixture reconstruction and product-snapshot retention.
6. **D2 / CAND-04:** adjudicate only if D2 was authorized and ran. Do not invent an unmeasured product cause.
7. **Y5:** only after all prerequisite evidence is internally consistent, apply the already-frozen Y5 predicates from `Architecture_M3_CP4c2_TB_X2_Plan.md`. Publish exactly one frozen branch or `selected_r2_branch=NONE` with blocker. Do not invent or merge branches.
8. Keep `selected_gate=NONE` and `gate_execution_authorized=false`; R4 does not execute or accept selector 357/358.

Every observed regression/candidate disposition must be recorded in `Regression_Root_Cause_Tracker.md` before the TB turn closes.

## Explicitly prohibited in R4

- selector 355/357/358 runtime;
- full semantic or cumulative suite;
- benchmarks;
- compile/configure/relink or generated test discovery;
- source/test/fixture/build mutation;
- product/validator change or validation weakening;
- mechanical/C2, CP4c-3, or frozen product CB3 work;
- test-only injection past `SurfaceCutGraph` or synthetic Y5 evidence;
- treating absent pipeline snapshots as proof that the already-constructed production atlas/network never existed;
- unchanged retry of semantic red evidence.

## Stop/rerun rules

Stop and preserve raw evidence on any immutable-preflight/postflight mismatch, zero/multi-selected identity, missing per-witness publication, Z12 snapshot-availability stop, torus-control mismatch, Z3 self-consistency failure, D2 inconsistency, timeout/crash, or package mutation. A timeout/crash is orchestration/infrastructure failure, never semantic pass/skip.

A diagnosed infrastructure/orchestration failure may be retried only after its cause is recorded and only with the exact immutable package and unchanged semantics. Semantic red evidence is reviewed, not rerun unchanged.

## Completion criteria

`M3-CP4c-2-TB-X2-R4` is complete only when:

- immutable preflight/postflight are green;
- D1 raw evidence includes exactly one record for all three witnesses;
- Z13 witness-isolation behavior and Z12 torus snapshot availability are explicitly adjudicated;
- torus 48/48 and all-witness Z3 are adjudicated only when their construction preconditions exist;
- D2 ran only if D1 fully passed Z17 steps 1-3, and its raw evidence is preserved if run;
- candidate dispositions and stable accounting are updated from evidence;
- Y5 selects one frozen branch or records `NONE` with blocker only when prerequisites authorize that decision;
- `selected_gate=NONE`, no cumulative gate ran;
- handoff/TODO identify the exact next state without executing it in R4.
