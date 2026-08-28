# M3-CP4c-2-CB2-DIAG-R1 Code + Build Report

- Phase: `M3-CP4c-2-CB2-DIAG-R1`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Authorizing review: `Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Record.md`, measures **Z0-Z9**
- Built evidence commit: `c552a5a4a318063cde2564c40773ec7edaf064f6`
- Runtime execution in this turn: **none**

## Objective and assumptions

The independent R2 review established two test-authority defects in D1 and authorized a bounded diagnostic-only correction: (1) the torus control was built from atlas-derived rails rather than production-authoritative feature-map rails, and (2) D1 mixed network-graph `V/E` with source-edge-barrier `F`, making its prescribed-sphere Euler publication self-contradictory. The review settled the normative diagnostic complex as the **source-mesh barrier complex** and prohibited product, selector, `SurfaceCutGraph`, fixture-result, or acceptance changes.

The smallest sufficient correction was therefore confined to `tests/FieldAlignedCurveNetworkTests.cpp`. No production semantic change was justified or made.

## Implemented — Z0-Z9

- **Z0 / frozen production and selectors:** no `src/`, `include/`, `SurfaceCutGraph`, build-configuration, fixture-data, or selector changes. Accepted 355/prefixes 316/346/353 and frozen 357/358 remain unchanged.
- **Z1 / production rail authority:** the prescribed sphere and torus D1 witnesses explicitly use `PipelineAuthoritative`; the two-ring explicitly uses its legitimate constructed `AtlasDerived` authority.
- **Z2 / one named Euler complex:** D1 now derives one `sourceEdgeBarrier` complex from the union of mandatory-rail source edges plus trace incoming/outgoing carrier source edges. It publishes `barrierV`, `barrierE`, `barrierF`, definitions, barrier count, and provenance.
- **Z3 / fail-closed self-consistency:** each D1 witness computes and publishes `eulerIdentityMatches` and `oracleSelfConsistent`, where self-consistency requires `(everyComponentDisc == (barrierV - barrierE + barrierF == sourceChi))`. D1 asserts this value before advancing to the next witness.
- **Z4 / explicit no-default authority:** one `Cp4cRailAuthority` route (`AtlasDerived` or `PipelineAuthoritative`) is passed explicitly through `cp4c_build_rail_authority(...)`; every D1/D2 record publishes `railAuthority=` and `mandatoryRailCount=`.
- **Z5 / no encoded expected answers:** no witness name, expected 48/48 values, sphere outcome table, or fixed branch result is encoded in the oracle. Counts derive from mesh/rails/network state.
- **Z6 / retry order:** D1 witness order is **torus -> prescribed sphere -> two-ring**, so the mandatory torus control is observed before any sphere self-consistency failure can terminate the process. D2 remains a separate identity and is only authorized after D1 passes the successor TB stop gate.
- **Z7 / two-ring re-derivation:** two-ring runs through the same barrier-complex accounting and self-consistency path rather than carrying forward the R2 result.
- **Z8 / accounting discipline:** no runtime candidate was closed in Code + Build. `M3-CP4c2-TB-X2-R2-CAND-01` and `...CAND-02` remain active pending corrected runtime; `M3-CP4c2-TB-X2-CAND-04` remains active/unlocalized pending D2. Stable totals remain 42/14/28 and produced-witness debt remains 5. The final immutable CB package advances M3 package accounting to **60**.
- **Z9 / prohibited work:** no D1/D2 runtime, selector 355/357/358 runtime, cumulative gate, CB3, mechanical/C2, CP4c-3, validation weakening, or product change occurred.

## Files changed

- `tests/FieldAlignedCurveNetworkTests.cpp`

No other semantic/test/build source file belongs to the evidence commit.

## Same-turn Z6 correction

The first compile-valid R1 revision (`0bf55f9620e9f7fedeba237a38d26ae4a819ccf5`) exposed one closeout defect by static review: the witness array still ordered sphere before torus, so a sphere Z3 failure could prevent the mandatory Z6 torus control from being published first. A surgical one-block test-only correction reordered the array to torus -> sphere -> two-ring. The correction was applied by verified Drive patch transport in run/job `33220234369 / 99012579536`; result/log artifacts `9704883058 / 9704883330`, digests `81854c89ba1c037af380a14b8db91c4d32ff6b752b1ac6491d1eb7b6811ee3db / af74e95c9e0c97045b014d57a62ba6678bcd991414d5db542fdde203e037c12a`. The staged Drive file was retired after the successful push.

The first compile is superseded as final evidence by the post-Z6 compile below. It is not runtime evidence and does not increase the canonical package accounting beyond this R1 turn's final package.

## Final authoritative compile

- Exact semantic/test source: `c552a5a4a318063cde2564c40773ec7edaf064f6`
- Compile workflow run/job: `33220315294 / 99012815358` — **PASS**
- Immutable result/package artifact: `9704935112` / `sha256:dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`
- Compile diagnostic log artifact: `9704935373` / `sha256:1fc2250c00dd57e8cbd6385bde11857bc92126dfddfdf969ba188a67709651c0`
- Packaged source archive SHA-256: `e533669daa7ac0219bc6ca6bd7d72db2901af32937848c3f37f02b772345ae02`
- Targets, all compiled/linked successfully:
  - `directional_core`
  - `directional_pipeline`
  - `directional_surface_cell_authority_kernel_tests`
  - `directional_surface_cell_producer_tests`
  - `directional_surface_cell_completion_tests`
  - `directional_surface_cell_validation_tests`
  - `directional_compiled_api_tests`
  - `directional_benchmarks`
- Configure: Release, static, `PRE_TEST`, out-of-tree; exit 0.
- Exact arithmetic: `DIRECTIONAL_ENABLE_GMP=ON`; link evidence contains both `libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`.
- Package `SHA256SUMS`: verified locally after download.
- All packaged source-status snapshots: empty.
- Command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.
- Generated Directional binaries/tests/benchmarks executed: **none**.

## Verification goals and deferred runtime

Compile success proves only that the corrected diagnostic authority is build-valid. The successor artifact-only TB must establish behavior:

1. D1 first publishes the torus control and it reproduces `V=48`, `E=48`, source `chi=0`, non-cellular from `PipelineAuthoritative` rails.
2. D1 then completes all three witnesses with `oracleSelfConsistent=true` under `complex=sourceEdgeBarrier`.
3. Only after 1-2 pass may D2 execute once for prescribed-sphere localization and Y5 evidence.
4. Any failure in 1-2 is a stop; it does not authorize D2, CB3, selector 355/357/358 runtime, or a cumulative gate.

## Known risks

- The corrected D1 has **not executed**. The torus 48/48 reproduction and all three Z3 self-consistency results remain unadjudicated.
- D2 has not executed from the corrected package, so `M3-CP4c2-TB-X2-CAND-04` remains unlocalized.
- The source-edge barrier complex is intentionally the frozen correctness model for this correction; the separate quad-quality concern that whole-carrier-edge cutting is coarser than the traces remains deferred.

## Mandatory successor plan

- Plan: `Architecture_M3_CP4c2_TB_X2_R3_Artifact_Only_Test_Benchmark_Plan.md`
- Evidence source/package: `c552a5a4a318063cde2564c40773ec7edaf064f6` / `9704935112`
- Exact next subturn: `M3-CP4c-2-TB-X2-R3-EXEC`
- Following subturn: `M3-CP4c-2-TB-X2-R3-REV`
- No runtime is part of this Code + Build closeout.
