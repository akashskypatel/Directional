# M3 CP4c-3 CB23 — Code + Build Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-CB23`
Type: **Code + Build — DIAGNOSTIC-ONLY PRODUCT INSTRUMENTATION + TEST-ONLY 371/372 DECOUPLING**
Status: **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE / BW0–BW9 IMPLEMENTED**

Source authority: **`fa5646106ccaa23770b84a935c6d1d6007928640`**. This turn changes no product acceptance semantics and executes no Directional runtime. `M3-CP4c-3-TB20` remains the immutable runtime authority until TB21.

## 1. Frozen scope and preservation

CB23 implements only BW0–BW9 from `Architecture_M3_CP4c3_TB20_Independent_Review_Record.md` §10.

- Exact starting source: `e5a4242a25f17fb995bf9b971ce3cfcd6eb98aae`.
- Work-preservation patch was emitted before remote orchestration: `Directional__M3-CP4c-3-CB23__base-e5a4242a25f1__work-preservation.patch`.
- Applied patch SHA-256: `5b577613e69b4082e64687cec637c51f08403edaf57547b1f10feab0faaeb5d2`.
- Google Drive staging file id: `1SV4Ztot879keAr_zr6HPbUeaXBwSDYU-`; the apply workflow reported `drive_file_retirement_required=true`, so owner-side permanent retirement is a mandatory closeout action.
- Applied semantic commit: **`fa5646106ccaa23770b84a935c6d1d6007928640`**.

No code/test/selector work was re-derived after the patch application.

## 2. BW1–BW4 — embedded-graph cellularity evidence

The production failure path now retains the embedded graph's own Euler census, separately from the fragment-owner trace-arc census:

- node count `V`;
- arc count `E`;
- face-walk orbit count `F`;
- embedded-graph connected-component count;
- source-surface Euler characteristic `χ(S)`;
- residual `V − E + F − χ(S)`;
- explicit `embeddedGraphEulerCensusComplete` authority bit.

`SurfaceCutGraph` computes the failure-side census from the same embedded-graph topology surfaces used by certification. `GlobalTopologyPlan` carries the accepted cut-graph certificate's census into downstream failures. `RemeshPipeline` projects the typed fields unchanged into the production failure locus. The same census is therefore available on the mechanical failure path and comparable with the torus and prescribed-sphere production paths.

For the `UncutFaceComponentOrbitSeedNotUnique` failure, the component boundary diagnostic now also retains a bounded per-orbit attribution: each graph-face orbit id and the number of component-boundary edges that expose it, plus total count and truncation status. The existing 64-row boundary retention limit is unchanged; attribution is accumulated independently so BW3 does not increase retained boundary-row volume.

## 3. BW5–BW7 — witnesses, selector, and test-only decoupling

Three diagnostic identities were appended to a new selector named by its resulting identity count:

1. `GlobalTopologyPlan.EmbeddedGraphEulerCensusPublishesThroughMechanicalProductionFailure`
2. `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure`
3. `GlobalTopologyPlan.EmbeddedGraphEulerCensusCarriesAcrossTorusAndPrescribedSphereProductionPaths`

Selector authority:

- predecessor `Architecture_M3_CP4c3_Required_Green_Selector_385.txt`: **388 identities**, SHA-256 `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`;
- new `Architecture_M3_CP4c3_Required_Green_Selector_391.txt`: **391 identities**, SHA-256 **`f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`**;
- accepted selector 365 remains byte-identical, SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

`Required_Green_Selector_Manifest.md` and its generator record selector 391 as the current gate and selector 385 as superseded without renaming the frozen 385 file.

The CW6-authorized test-only decoupling is implemented additively through `cp4c_mechanical_atlas_fixture()`. Only the two existing atlas identities at ordinals 371 and 372 switch to that accessor. Their assertions, selector membership and ordinal ordering are unchanged; `cp4c_mechanical_fixture()` remains the all-products fixture for every other consumer.

## 4. BW8 — prohibited semantic surfaces remain untouched

No product correction is made. In particular CB23 does not relax or rewrite:

- `UncutFaceComponentOrbitSeedNotUnique` or its predicate;
- `componentBarriers`, the component partition, `seedOrbits`, `edgeOrbitEvidence`, `add_fragment_orbit`, or the `exteriorOrbits` filter;
- `is_terminal_slit`, the face walk, the rotation system, region drafts, CB21's comparison, or `proves_cellularity()`;
- `localFragmentCount` fatality status;
- fixture geometry, tolerance, float-derived decisions, accepted-boundary behavior, saturation, ordinal 370, folded-cone, vertex-30, or finalize/contact semantics.

The only additional work performed on the production path is typed evidence calculation/projection on failure paths and bounded diagnostic aggregation.

## 5. BW0 — authoritative compile/package evidence

GitHub Actions run **`33815475590`** compiled the exact semantic source `fa5646106ccaa23770b84a935c6d1d6007928640` using the mandatory reusable compile workflow.

- preflight job: **`100846561708`** — GREEN;
- package job: **`100847694307`** — GREEN;
- eight standard package targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`;
- package artifact: **`9916511617`**, GitHub artifact digest **`sha256:8378a108811740cff5fd1a0fc9db66f9e3334d7048ea9e7c7d6e8e1cbd852050`**;
- package log artifact: **`9916511915`**, digest `sha256:620381f4b9881ac0773fca206e2913ab3be52cc2b1abef9d8cbe9f62477e716e`;
- GMP package: `libgmp-dev 2:6.3.0+dfsg-2ubuntu6.1`; CMake found `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`;
- authoritative generated link command contains both `libgmpxx.so` and `libgmp.so`;
- `manifest_self_verification=pass`, `source_status_clean=pass`;
- `runtimeExecution=false`: no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input was executed.

The compile run's event SHA is control-plane commit `68db8dd9097141294295adb383dc8514c6bad078`; both compile jobs explicitly checked out semantic source `fa5646106ccaa23770b84a935c6d1d6007928640`.

## 6. Turn disposition

**CB23 is COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE.** Accepted runtime authority remains **365/365** from TB20; CP4c-3 remains **OPEN**. Stable regression accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt remains **5**, and the semantic M3 package count advances to **86**.

Exact next turn: **`M3-CP4c-3-TB21`**, artifact-only Test + Benchmark, consuming immutable package artifact `9916511617` and selector 391. TB21 must execute the full 391-identity gate one identity per fresh process and discharge the six BW9 discriminators. No Code + Build correction is authorized before that runtime evidence and its required review/definition boundary.
