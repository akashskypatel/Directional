# M3-CP4c-2-CB2-DIAG-R2 Code + Build Report

- Phase: `M3-CP4c-2-CB2-DIAG-R2`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Authorizing review: `Architecture_M3_CP4c2_TB_X2_R3_Independent_Review_Record.md`, measures **Z10-Z19**
- Built evidence commit: `5ad711e5d4ced95f38e103b993139a6307ba2cee`
- Runtime execution in this turn: **none**

## Objective and assumptions

R3 review localized the torus diagnostic failure to a test-side reconstruction path and identified a second diagnostic gating defect: D1 rebuilt pipeline authority instead of consuming published products, flattened typed construction errors, and aborted the witness loop on the first failing witness. The authorized correction was therefore test/diagnostic source only. Production source, `SurfaceCutGraph`, selectors, accepted gates, fixtures, and validators remained frozen.

The smallest sufficient change was confined to `tests/FieldAlignedCurveNetworkTests.cpp`. No `src/`, `include/`, fixture-data, selector, build-configuration, or production semantic change was justified or made.

## Implemented — Z10-Z19

- **Z10 / frozen authority:** accepted CP4c-1 runtime authority remains 355/355. All six frozen selector hashes are unchanged. The final build uses GMP/GMPXX and records `runtimeExecution=false`.
- **Z11 / consume published products:** loaded production witnesses now call `remesh_from_raw_cross_field(...)` once and consume `surfaceCellContext.productSnapshots` for authoritative rails, source topology, field-transport atlas, and field-aligned network. The former `cp4c_build_rail_authority(...)` reconstruction helper was removed. A relaxed `build_cp4c_pipeline_products_fixture(...)` tolerates absent cut graph/global plan, while the existing strict `build_cp4c_production_fixture(...)` retains its original stronger precondition and was not weakened.
- **Z11 / constructed witness separation:** the synthetic two-ring remains a constructed `AtlasDerived` witness and builds its own source authority, atlas, rails, and network. Every D1 record now publishes `witnessConstruction=pipelineProducts|constructed`.
- **Z12 / publication fields:** pipeline witnesses publish `pipelineAtlasAvailable`, `pipelineNetworkAvailable`, `pipelineCutGraphAvailable`, `pipelinePlanAvailable`, `terminalFailureCode`, and `terminalFailureStage` on both success and failure records.
- **Z13 / no witness suppression:** D1 no longer calls `ASSERT_*` inside the witness loop. Each witness independently emits exactly one success or failure record, failures accumulate, and one `ASSERT_TRUE(allWitnessesValid)` occurs only after the loop.
- **Z14 / typed construction failures:** constructed atlas failures retain `FieldAtlasBuildError` and serialize through `append_atlas_error(...)` plus `append_cp4c_atlas_failure_diagnosis(...)`; network failures retain the typed network error, serialize it, and publish `networkErrorLocus`. Bare stage-only failure strings are no longer the sole evidence.
- **Z15 / no fourth idiom:** three witness roles remain, explicitly commented in source: (1) reachability observer replay, (2) pipeline-product fixture consumer, and (3) D1 network-only fixture that delegates loaded witnesses to the pipeline-product consumer and constructs only the synthetic two-ring. No fourth construction path was added.
- **Z16 / surviving R1 authority preserved:** `sourceEdgeBarrier`, `oracleSelfConsistent`, explicit no-default rail authority, no encoded expected answers, and two-ring re-derivation remain intact.
- **Z17 / successor ordering support:** D1 can now publish every witness unconditionally before the successor evaluates the torus control and all-witness self-consistency. D2 remains a separate identity and is not executed in Code + Build.
- **Z18 / accounting discipline:** no runtime candidate is closed by compile evidence. Stable regression accounting remains **42 / 14 / 28**, produced-witness debt **5**, and the final immutable package advances M3 package accounting to **61**.
- **Z19 / prohibited work:** no selector runtime, cumulative gate, D1/D2 runtime, product CB3, mechanical/C2, CP4c-3, source-cut refinement, validator weakening, or production change occurred.

## Files changed

Semantic/test evidence commit:

- `tests/FieldAlignedCurveNetworkTests.cpp`

No other production/test/build source belongs to `5ad711e5d4ced95f38e103b993139a6307ba2cee`.

## Source application and compile evidence

The exact semantic/test patch was preserved against base `7dd5d1a012e39ee3483dd81685461c0c2e817b29` with SHA-256
`6b7726da5bbad3345045ea46b60abe24565b967b6572626f22eb1a19a02c1c50` and applied transactionally. The resulting semantic/test commit is `5ad711e5d4ced95f38e103b993139a6307ba2cee`.

A changed-owner precompile run `33226421754` passed. The final authoritative full package compile is:

- exact semantic/test source: `5ad711e5d4ced95f38e103b993139a6307ba2cee`;
- compile workflow run/job: `33226609913 / 99031482464` — **PASS**;
- immutable result/package artifact: `9707091209` / `sha256:e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63`;
- compile diagnostic log artifact: `9707091377` / `sha256:0188b2926df2d77b5885a6560ba358f325d709d3b57f326b3a2abf5473bfe3b2`;
- packaged source archive SHA-256: `9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11`;
- targets, all compiled/linked successfully:
  - `directional_core`
  - `directional_pipeline`
  - `directional_surface_cell_authority_kernel_tests`
  - `directional_surface_cell_producer_tests`
  - `directional_surface_cell_completion_tests`
  - `directional_surface_cell_validation_tests`
  - `directional_compiled_api_tests`
  - `directional_benchmarks`;
- configure/build exit codes: `0 / 0`;
- exact arithmetic: `DIRECTIONAL_ENABLE_GMP=ON`; link evidence contains both `libgmpxx.so` and `libgmp.so`;
- package `SHA256SUMS`: verified;
- all packaged source-status snapshots: empty;
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`;
- generated Directional binaries/tests/benchmarks executed: **none**.

The workflow trigger/control commits after the semantic commit are orchestration-only. Package metadata records `5ad711e5d4ced95f38e103b993139a6307ba2cee` as the compiled source authority.

## Static retention finding — runtime must adjudicate it

Static inspection found a material risk in the assumption behind Z11/Z12: production assigns `productSnapshots.sourceTopologyRegions`, `fieldTransportAtlas`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, and `globalTopologyPlan` together only **after both `SurfaceCutGraph::make(...)` and `GlobalTopologyPlan::make(...)` have succeeded**. Earlier returns preserve authoritative rails but do not copy the already-constructed atlas/network into those snapshot optionals.

The torus is already known to terminate at `SurfaceCutGraph`. Therefore the R4 torus may legitimately publish `pipelineAtlasAvailable=false` / `pipelineNetworkAvailable=false` even though production successfully constructed those products earlier in the same pipeline execution. This is a static source finding, **not runtime evidence and not a product correction authorization**.

The successor must obey Z12 exactly: if the torus pipeline snapshots do not expose atlas/network, preserve all three D1 per-witness records, stop before D2, and route the result to `TB-X2-R4-REV`. Do not infer 48/48 failure, a Y5 branch, or a production fix from snapshot-retention absence in EXEC.

## Candidate state after compile

- `M3-CP4c2-TB-X2-R3-CAND-01`: localized/resolved as to cause by R3 review; the Z11 code correction is compiled, but its runtime closure condition is still pending R4.
- `M3-CP4c2-TB-X2-R3-CAND-02`: Z13 code correction is compiled; runtime closure requires proof that one witness failure no longer suppresses the others.
- `M3-CP4c2-TB-X2-R2-CAND-01` and `...CAND-02`: remain active pending corrected D1 publications.
- `M3-CP4c2-TB-X2-CAND-04`: remains active/unlocalized because D2 has never executed on an authorized package.
- `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

## Mandatory successor plan

- Plan: `Architecture_M3_CP4c2_TB_X2_R4_Artifact_Only_Test_Benchmark_Plan.md`
- Evidence source/package: `5ad711e5d4ced95f38e103b993139a6307ba2cee` / `9707091209`
- Exact next subturn: `M3-CP4c-2-TB-X2-R4-EXEC`
- Following subturn: `M3-CP4c-2-TB-X2-R4-REV`
- No runtime is part of this Code + Build closeout.
