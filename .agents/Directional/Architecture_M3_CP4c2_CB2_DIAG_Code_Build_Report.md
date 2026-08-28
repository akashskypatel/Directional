# M3-CP4c-2-CB2-DIAG Code + Build Report

- Phase: `M3-CP4c-2-CB2-DIAG`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Starting semantic/planning authority: `7d93a21706f630fce55cee4ef1cbfdac24f7bd61`
- Built evidence commit: `232ac459b13657529e064272a75c5583770a5963`
- Handoff/closeout commit: recorded by the documentation apply that contains this report
- Remote synchronization verified: yes; the immutable compile checked out `232ac459b13657529e064272a75c5583770a5963` exactly

## Implemented

- Added a **test-side independent network-complement cellularity oracle** for the prescribed sphere, torus, and two-ring witnesses. It constructs an exact per-triangle arrangement from source-mesh topology plus the published field-aligned curve network, glues complement fragments only across unblocked source-edge intervals, and reports source `V/E/F/chi`, network `V/E/F/chi`, per-component Euler characteristic, boundary-cycle validity/count, disc verdict, and the aggregate `networkOnlyCellular` verdict.
- The D1 oracle contains no call, link-time dependency, or reuse of `SurfaceCutGraph`; it reports `surfaceCutGraphCalls=0` and does not define cellularity as `cut_edges().empty()`.
- Added a **test-side producer-accounting re-derivation** for D2. It mirrors the current A2a-prime barrier/component/cut accounting only to localize the shared `CellularityNotEstablished` code to `419-initial-nondisc-no-cuts`, `437-final-nondisc`, or `474-global-certificate`, and publishes the would-be producer `V/E/F/chi` terms beside the independent oracle terms.
- Added two non-gating diagnostic identities:
  - `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable`
  - `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`
- No production implementation, fixture, selector, acceptance rule, build configuration, or frozen 357/358 candidate was changed.

## Engineering-Guideline Review

- Material assumptions surfaced: D1 must be independent of the mechanism under test; D2 is intentionally a separate re-derivation of current producer accounting and is not itself the independent cellularity oracle; no runtime result may be inferred during Code + Build.
- Simplest sufficient approach chosen: exact arrangement/complement traversal is larger than a `cut_edges().empty()` check, but the latter is explicitly invalid because it restates the product decision. The implementation stays inside the existing test translation unit and introduces no production abstraction.
- During source review, the D2 added-vertex accounting was corrected to match production exactly: only source vertices introduced by tree-cotree cut endpoints and not already represented by network nodes are counted. Counting every unrepresented source vertex would have produced a false localization comparison.
- Unrelated refactors/style drift avoided: yes. The authoritative source commit changes only `tests/FieldAlignedCurveNetworkTests.cpp` and adds 1,396 lines without deleting or modifying unrelated source.
- Every changed line traces to D1/D2 observability or their exact reporting support: yes.

## Files Changed

- `tests/FieldAlignedCurveNetworkTests.cpp`

## Domain Invariants

- `SurfaceCutGraph::proves_cellularity()` was not weakened or changed.
- D1 never calls/reuses `SurfaceCutGraph`; D2 may call it only after independently computing the oracle/re-derivation so the published product error can be compared with the predicted site.
- Accepted selector 355 and prefixes 316/346/353 remain byte-identical.
- Frozen candidate selectors remain byte-identical:
  - 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
  - 358: `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`
- `selected_gate=NONE`; no cumulative gate execution is authorized by this build.

## Generalization Review

- Why this is not fixture-specific: the oracle derives topology from typed source faces/edges, exact barycentric network geometry, and published network nodes/events/traces. The three prescribed witnesses are inputs to a general helper rather than special-cased result tables.
- Valid input classes affected: test-only observation of closed triangular source meshes with a valid `FieldAlignedCurveNetwork`; production behavior is unaffected.
- Regression risks considered: divergence between D2's re-derivation and future producer accounting is intentional evidence rather than hidden authority; D1's independence is preserved so such divergence cannot manufacture a cellularity result.

## Build

- Workflow/run/job: `.github/workflows/agent-compile-reusable.yml`, `33212932401 / 98990159075`.
- Exact source: `232ac459b13657529e064272a75c5583770a5963`.
- Targets:
  - `directional_core`
  - `directional_pipeline`
  - `directional_surface_cell_authority_kernel_tests`
  - `directional_surface_cell_producer_tests`
  - `directional_surface_cell_completion_tests`
  - `directional_surface_cell_validation_tests`
  - `directional_compiled_api_tests`
  - `directional_benchmarks`
- Result: **PASS**; preflight exit `0`, full build exit `0`, all source-status snapshots empty.
- Exact arithmetic: `DIRECTIONAL_ENABLE_GMP=ON`; package evidence links both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`; `exactArithmeticBackend=GMP`.
- Immutable compile result artifact: `9702321260` / `sha256:05237f108a65c73df81b6b125d6fcecad10ad9b5af4104ecce3c6bb9f6642035`.
- Compile diagnostic log artifact: `9702321551` / `sha256:236458a4146ebec93638065a0f55500e8bb77dbf216d1d7b942f667be4070ab3`.
- Packaged source archive SHA-256: `986db8b91d06eab4284f3a0e49c1d8c9ad2676df61fdfdd4a94e56ba34a5644f`.
- Package manifest: `sha256sum -c SHA256SUMS` verified all entries.
- Command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.
- Tests or benchmarks executed: **none**.

## Known Risks

- D1 and D2 have compiled but have not executed. Their sphere/torus/two-ring numerical publications are unknown until `TB-X2-R2`.
- The unit-mismatch/coarsening explanation for the predicted site 474 remains a falsifiable hypothesis, not a finding. `TB-X2-R2` must accept or reject it from the published terms.
- No 357/358 gate predicate is established by this turn. Branch selection remains deferred to Y5 after the artifact-only diagnostics execute and are reviewed.

## Mandatory Test + Benchmark Plan

- Plan reference: `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md`
- Evidence commit/artifact under test: `232ac459b13657529e064272a75c5583770a5963` / artifact `9702321260`.
- Focused validation: execute the two new diagnostic identities separately from the immutable package and preserve complete `m3Cp4c2Y1` / `m3Cp4c2Y2` publications.
- Related regression validation: no cumulative 355/357/358 gate run in R2; frozen selector integrity is pre/postflight only.
- Benchmarks: not applicable.
- Acceptance criteria: artifact integrity and orchestration must be green; Y1-Y4 must be fully publishable; TB review must select exactly one frozen Y5 branch or stop because evidence is incomplete/inconsistent.
- Stop conditions: any artifact/source/GMP/selector mismatch, zero-selected diagnostic, missing publication, runtime mutation/rebuild, or inconsistent localization evidence.

## Next Turn

- Type: Test + Benchmark
- Canonical turn: `M3-CP4c-2-TB-X2-R2`
- Exact next subturn: `M3-CP4c-2-TB-X2-R2-EXEC`
- Corrective `CB3` and cumulative gate execution remain prohibited until R2 review completes Y5.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `232ac459b13657529e064272a75c5583770a5963`
- Test plan linked: `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md`
- Updated in this closeout: yes.
