# M3-CP4c-2-CB4 Code + Build Report

## Status

**COMPLETE / BUILD GREEN / RUNTIME-FREE / NOT SEMANTICALLY ACCEPTED**

`M3-CP4c-2-CB4` implements frozen DEFN-R1 measures **AC0–AC9** for actual-embedded-graph cellularity authority. No Directional runtime, test, benchmark, CLI, discovery/list/help/version command, fuzzer, or custom runtime input executed.

Accepted runtime authority remains CP4c-1 TB-R5 **355/355** until artifact-only R6 evidence is independently reviewed.

## Exact source and implementation preservation

Semantic/test source: `cebc12082c6dbe4830095df08169797b7dab0c5c`.

Implementation WIP was preserved before remote orchestration as
`Directional__M3-CP4c-2-CB4__base-858d2c37314d__work-preservation.patch`, SHA-256
`e0621b9c9a801c0af322e5f541082f457952f415a407bc440c63e032197c4d58`, diff-body SHA-256
`76a7b0861df6a7b8a9e511e8c16f4d4b12a959e590e594ef0187c92c2a6afe84`, against frozen base
`858d2c37314d910aaabf77e9e49f03f48da43484`. `git diff --check` and exact-base `git apply --check` passed.

Those exact bytes were staged in `My Drive/Directional-CI` and applied by durable
`agent-google-drive-reusable.yml`; run/job `33246430331 / 99084587314` was GREEN with
`runtimeExecution=false` and pushed the semantic source above. Result artifact `9712982174` records the patch
identity. The workflow identity could not trash the Drive object; the owner-authorized Drive connector permanently
retired the exact staged file after successful push.

Semantic changed paths are exactly:

1. `CMakeLists.txt`
2. `include/directional/geometry/SurfaceCutGraph.h`
3. `src/geometry/EmbeddedGraphTopology.cpp`
4. `src/geometry/EmbeddedGraphTopology.h`
5. `src/geometry/GlobalTopologyPlan.cpp`
6. `src/geometry/SurfaceCutGraph.cpp`
7. `src/pipeline/RemeshPipeline.cpp`
8. `tests/FieldAlignedCurveNetworkTests.cpp`

No selector changed.

## AC0–AC9 implementation audit

- **AC0:** accepted historical authority remains 355/355; 316/346/353/355/357/358 selectors are unchanged;
  `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`; compile uses GMP/GMPXX.
- **AC1:** arc/oriented-dart/node-rotation/face-orbit construction is lifted into one shared internal owner,
  `src/geometry/EmbeddedGraphTopology.{h,cpp}`, consumed by both `GlobalTopologyPlan` and `SurfaceCutGraph`.
  A second A2a′/A2b implementation is not retained.
- **AC2:** per-component/global `SurfaceCutGraph` certification, cut selection/publication, `GlobalTopologyPlan`
  consumption, and CP4c-2 observability are converted together to the actual embedded graph. Barrier-partition
  quantities are not cellularity-certificate terms.
- **AC3:** vertices are actual embedded nodes plus cut-created nodes; edges are network arcs plus cut arcs; faces
  are dart orbits; exterior/boundary orbits are distinguished from counted faces; disconnected certification uses
  `V - E + F - (c - s) = chi`.
- **AC4:** a source edge is admissible only when non-mandatory and not crossed by an immutable trace at an exact
  rational interior edge parameter; no positional tolerance decides this.
- **AC5:** `SurfaceCutGraphError::NoAdmissibleCutForNonDiscComponent` is compiled with component-local failure
  information. No inadmissible/tolerance/partial fallback was added.
- **AC6:** no witness-name branch/table/product constant encodes two-ring `9/11/3/chi=1`; R6 must derive it.
- **AC7:** the no-admissible-cut state remains a definition-return stop, not a widening trigger.
- **AC8:** non-gating
  `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating` independently reconstructs
  actual-complex topology for comparison; retained `sourceEdgeBarrier` evidence is explicitly diagnostic-only /
  not a cellularity oracle.
- **AC9:** static review found no selector changes, no `proves_cellularity()` weakening, no proxy `10/11/2`
  substitution, no witness constants, no AA1 revert, no trace subdivision, and no cumulative/357/358 runtime.

## Required compile ordering and evidence

An initial full-package attempt (`33246515627`) succeeded but occurred before a distinct changed-owner prepackage
compile. It is retained only as ordering-invalid mechanics evidence and is **not** R6 authority.

The exact same semantic source was then re-proved in the required order.

### Changed-owner prepackage

- run/job `33250503297 / 99095246849`
- target `directional_surface_cell_producer_tests`
- result `9714212919` /
  `sha256:aba9890615280d37d292b463b6400024224f465545f4f8b2a3ef5d358f723fd0`
- log `9714213161` /
  `sha256:149a32069f0ab4af28b2110b4621757fc23cfb1767fee971fdb839b6b5adcd02`
- PASS

### Fresh authoritative eight-target package

- run/job `33250547011 / 99095357374`
- package `9714226920` /
  `sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`
- log `9714227128` /
  `sha256:95c8272db296dc0f74e4d33b389cbf51305bd042590420974111d9f63afe31da`
- packaged source archive
  `3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`
- internal `SHA256SUMS` **28/28 PASS**
- source status clean
- `runtimeExecution=false`
- `turnBoundary=Code+Build-only`
- `exactArithmeticBackend=GMP`
- `DIRECTIONAL_ENABLE_GMP=ON`
- authoritative link evidence contains both `libgmpxx` and `libgmp`
- source archive includes repository-root `.agents/` and `benchmarks/fixtures/`

All eight required targets are present: `directional_core`, `directional_pipeline`,
`directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
`directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
`directional_compiled_api_tests`, and `directional_benchmarks`.

## Boundary and accounting

CB4 performed static source/diff review, patch checks, compilation/linking, and immutable compile-package
verification only. It did not execute 355, the new oracle, D2, 357/358, a cumulative gate, benchmarks,
mechanical/C2, or CP4c-3.

No runtime regression was observed, so `Regression_Root_Cause_Tracker.md` is unchanged.

- stable accounting **43 / 14 / 29**
- active accepted regression `PR8-R043 / M3-CP4c2-R001`, `AUTHORITY_DOMAIN_CONFLATION / RP-01`
- produced-witness debt **5**
- authoritative M3 packages **63**
- `selected_r2_branch=NONE`
- `selected_gate=NONE`
- `gate_execution_authorized=false`

## Successor

Exact next is **`M3-CP4c-2-TB-X2-R6-EXEC`** on immutable package `9714226920`.
Executable plan: `Architecture_M3_CP4c2_TB_X2_R6_Artifact_Only_Test_Benchmark_Plan.md`.

R6-EXEC must preserve raw artifact-only evidence and stop at independent
`M3-CP4c-2-TB-X2-R6-REV`. It may not run 357/358, the cumulative gate, mechanical/C2, or CP4c-3.
