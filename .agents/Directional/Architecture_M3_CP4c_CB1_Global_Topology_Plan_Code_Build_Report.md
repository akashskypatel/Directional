# Architecture M3 CP4c CB1 — GlobalTopologyPlan Production Wiring Code + Build Report

**Status:** COMPLETE / BUILD GREEN / RUNTIME FORBIDDEN AND NOT EXECUTED
**Turn:** `M3-CP4c-CB1` (W0–W5 only)
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Starting commit:** `a74217ac0cd258ef7acd1c3d1cc8185b0d41767e`
**Built semantic source:** `428e0ecb6f769b501c99405ae2a90c24d5401cca`
**Execution mode:** canonical Code + Build, GitHub Actions compile plane

## Implemented

W1 wires A2b exactly once, immediately after A2a, through the production remesh entry path. The
pipeline constructs `GlobalTopologyPlan` from the whole-mesh faces and vertex count, retained source
topology authority, and the just-built field-aligned network. It publishes the result in both the
diagnostic product snapshots and per-component stage products, and records product identity/hash/count
as `arcs().size() + regions().size() + rotation_system().size()`.

The chosen W1.4 policy is **(a), fail closed**: a plan construction error returns
`NotProductionReady` at stage `global-topology-plan/<typed-error-name>`. This preserves the
single-writer authority contract: no downstream consumer can mistake a missing failed product for a
product that was never reached.

## W0 Static Preconditions — all before mutation

| Item | Result | Recorded evidence |
|---|---|---|
| W0.1 | PASS | No `GlobalTopologyPlan` occurrence in production `RemeshPipeline.cpp`. |
| W0.2 | PASS | Public four-argument `GlobalTopologyPlan::make(...)` and `global_topology_plan_hash(...)` exist. |
| W0.3 | PASS | Frozen accepted selector has 304 identities; exactly five accepted identities exercise `remesh_from_raw_cross_field` with surface cells enabled and Fail fallback (list below). |
| W0.4 | PASS | Torus and mechanical-feature `.obj` and `.rawfield` fixtures all exist. |
| W0.5 | PASS | Both named test translation units belong to `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES`. |
| W0.6 | PASS | Wiring is feasible within, and the final semantic diff is confined to, the two authorized production files. |

W0.3 exact identity list (cardinality **5**):

1. `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement`
2. `SurfaceCellFieldAlignedNetworkAuthority.ProductionConsumesTypedSkeletonWithoutRawSingularityProjection`
3. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
4. `SurfaceCellAuthorityContractCutover.PostMoveSingleComponentOptimizerUsesRetainedSourceAuthority`
5. `SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`

Selector evidence: accepted-predecessor result artifact `9531769503`; artifact ZIP SHA-256
`1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`; selector SHA-256
`c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`; 304 non-empty lines.

## Files Changed

- `include/directional/pipeline/RemeshPipeline.h`
- `src/pipeline/RemeshPipeline.cpp`

Production diff: **27 insertions, 0 deletions**, exactly those two paths; patch SHA-256
`19edea4ca699db1d175036d89a0fa8b8355e5ed6164ec65a9813759f36956028`; compressed patch SHA-256
`87798b19c143286ea3682244246c531256c27f43a8be9e01be6c4582fdb7a515`.

No `GlobalTopologyPlan.cpp` or tracing change; no fixture, selector, test, identity, error-code,
cache, or shared-plan change; no second construction.

## Engineering and Invariant Review

- Material assumption: A2b is component-local because its four inputs are the same whole-mesh/source
  authority and freshly produced A2a authority used at the established site.
- Simplest sufficient implementation: mirror the existing A2a build/fail/store/publish/record shape.
- Every production line traces to W1.1–W1.4. Unrelated refactors and style drift were avoided.
- Generalization: no fixture name or test identity appears in production code; all valid production
  inputs reaching A2a now receive the same typed A2b construction and failure contract.
- Primary risk: fail-closed A2b may newly reject an accepted production witness. DG1 is expressly
  designed to measure that risk without consuming an acceptance attempt.

## Build Evidence

### Changed-owner compile

- exact source: `428e0ecb6f769b501c99405ae2a90c24d5401cca`
- target: `directional_pipeline`
- run/job: `32770533316 / 97569642420` — **PASS**
- result artifact `9536072497`, SHA-256 `4c9545b9ccce2c80c61e644fc4fa6f21c58fc562192231cd6ecc4e617b1853d7`
- log artifact `9536073130`, SHA-256 `0c4098cca5a9a7d2455eaa48a55c3142f02285604f32f82ca9a7852b9f032881`
- source archive SHA-256 `33e546764b3b3017fbb043cfd91a4366a3ae27244861ade457743fcf10cf49ac`
- owner manifest 21/21; five source-status snapshots empty; `runtimeExecution=false`

### Authoritative six-executable/two-library package

- exact source: `428e0ecb6f769b501c99405ae2a90c24d5401cca`
- targets: `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`
- run/job: `32771584396 / 97572920008` — **PASS**
- immutable package/result artifact `9536499549`, SHA-256
  `4c64c0c3ea872dbf889c4de398ed40f9e0193fce534ee6117348e3b7a5514660`
- log artifact `9536500171`, SHA-256
  `86c4ab983bba5bcf1a57213aa73ee6f6db48b7cfbe2c89a9487194e46e905732`
- source archive SHA-256 `33e546764b3b3017fbb043cfd91a4366a3ae27244861ade457743fcf10cf49ac`
- `SHA256SUMS` **27/27 PASS**; five source-status snapshots empty; `runtimeExecution=false`

One earlier compile-only package run `32770876938 / 97570691753` completed green but named only four
test executables plus the two libraries and therefore produced 25/25, not the required 27/27. It is
retained as non-authoritative process evidence, is not an M3 package, and was not reused. The corrected
caller schema was revalidated at `32771475885 / 97572581414` before the authoritative run above.

M3 package count advances **34 → 35** for artifact `9536499549`. Stable regression accounting remains
**42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**. CP4c acceptance
remains **0/3** and diagnostics **0/2** because Code + Build executes no runtime gate.

## Checks Deliberately Not Run

No generated Directional test, benchmark, discovery/list, CLI, help/version, fuzzer, fixture, or custom
input executed. No runtime test was adapted or added. `runtimeExecution=false` for every schema,
patch, compile, and cleanup workflow used by this turn.

## Granular Loop / Recoverability

- verified marker-free start snapshot: run/job `32767813318 / 97561165354`, artifact `9535101481`,
  outer SHA-256 `ffcf5a22d8ae679fa5f320df8ab7a1d62b7747bd6ffb05d014bb2dad243d3cf3`
- work-preservation patch: `Directional__M3-CP4c-CB1__base-a74217ac0cd2__work-preservation.patch`,
  File Library id `libfile_d0a197571a408191b0fd5ee41da4dac4`; apply-check PASS
- patch schema validation: `32769911110 / 97567699931`, artifact `9535797535`
- authoritative patch application: `32770104244 / 97568342561`, result `9535873486`, log
  `9535873783`, exact emitted semantic source `428e0ecb6f769b501c99405ae2a90c24d5401cca`
- all temporary application/compile/schema callers, markers, and payloads retired workflow-first;
  the active cleanup override was obeyed (`manifest.txt` absent; cleanup workflow not invoked)

## Mandatory Successor Validation Plan

Authoritative executable plan:
`Architecture_M3_CP4c_DG1_Artifact_Only_Diagnostic_Plan.md`.

It binds DG-EXEC then mandatory DG-REV to immutable package `9536499549`, exact source
`428e0ecb6f769b501c99405ae2a90c24d5401cca`, frozen selectors, one identity per process, and
**316/316**. It consumes diagnostic **1/2**, no acceptance attempt, and permits no build, discovery,
repair, or mutation.

## Next Turn

**Exact next: `M3-CP4c-DG1-DG-EXEC`**, artifact-only diagnostic execution under the successor plan.
CB1 stops at W5: no C1–C6 identity was authored and W6 was not run.
