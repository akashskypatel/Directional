# M3-CP4c-3-CB24 — Code + Build Report

## 1. Turn identity and boundary

- Turn: **`M3-CP4c-3-CB24`** — Code + Build, diagnostic-only.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Starting semantic source: `a5a15484cfbe70443f674c1fb2e3cbfdd38f601a`.
- Built evidence/source commit: **`d69729a69a40b020968ed6ef1fbc1bc788284518`**.
- Binding scope: `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` §10, **BY0–BY9**.
- Runtime boundary: **none**. No Directional test, benchmark, discovery/list/help/version command, CLI, fuzzer, or custom input was executed.

CB24 does not adjudicate the projection defect. It publishes the evidence needed for TB22 and the mandatory independent TB22 review to distinguish the two remaining owners.

## 2. Implemented change

The change is limited to diagnostics, test witnesses, and selector/manifest bookkeeping. Product topology semantics remain unchanged.

- Boundary evidence retention now preserves at least one row per distinct seed orbit and one row per distinct `noSeedReason` before filling the existing bounded row budget in deterministic order. The cap/truncation contract remains.
- Minority seed-orbit rows publish the source edge, both source faces, seed orbit, seed rule (`SingleFaceOwner` or `EdgeOrbitEvidence`), owner count/barrier classification, and the certificate face on each side.
- A typed **projection-faithfulness residual** is published for adjacent uncut source-triangle pairs assigned to different certificate faces whose shared edge is absent from `componentBarriers`, together with bounded witness rows and a truncation bit.
- The diagnostic projection is carried through the production failure path without changing the seed guard, barrier construction, component partition, face walk, rotation system, region drafts, CB21 comparison, cut-graph certificate, or `proves_cellularity()`.
- Ordinal 391's test is re-scoped so the mechanical and torus evidence are independently asserted/reported; the prescribed-sphere half is skipped-with-reason while the already-owned ordinal-368 surface prevents `sphere.cutGraph`.
- Two compiled witnesses were appended:
  - ordinal **392** — `GlobalTopologyPlan.UncutFaceComponentBoundaryEvidenceRetainsDistinctSeedAndReasonRows`;
  - ordinal **393** — `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual`.
- Selector **391** is byte-identical and an exact prefix of new selector **393**. The derived selector manifest was regenerated.

Changed implementation/test/selector paths are exactly:

- `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_393.txt`
- `.agents/Directional/Required_Green_Selector_Manifest.md`
- `.agents/Directional/tools/selector_manifest.py`
- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

## 3. Frozen invariants and generalization review

**BY8 remained binding.** CB24 does not alter `componentBarriers`, the uncut-face partition, `seedOrbits`, the seed election rule, `edgeOrbitEvidence`, `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`, the embedded-graph face walk, the rotation system, region drafts, CB21's comparison, `proves_cellularity()`, or certificate construction. `localFragmentCount` remains non-fatal. No fixture geometry, tolerance, accepted assertion, sphere/saturation/370/folded-cone/vertex-30/finalize-contact product behavior was changed, and CB21 was not reverted.

The retention rule is not fixture-index-specific: it preserves categorical distinctness before positional filling. The projection residual is defined over the general relation between source-face adjacency, certificate-face attribution, and `componentBarriers`; it does not encode the observed minority edge keys or the expected residual. The two witnesses exercise typed diagnostics through the production projection path rather than manufacturing expected output.

## 4. Selector authority

- Accepted selector 365 remains `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` and is untouched.
- Selector 391 remains **391 identities**, SHA-256 **`f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`**.
- Selector 393 contains **393 identities**, SHA-256 **`ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`**.
- Selector 391 is an exact byte prefix of selector 393; only ordinals 392 and 393 are appended.

## 5. Authoritative compile/package evidence

GitHub Actions run **`33823590494`**, compile job **`100871347582`**, compiled the exact pushed source `d69729a69a40b020968ed6ef1fbc1bc788284518` through the mandatory reusable compile workflow.

All eight required targets compiled and linked successfully:

`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Compile evidence:

- preflight `directional_core`: exit **0**;
- full compile/link: exit **0**;
- source status clean before/after configure and after build;
- Ubuntu 24.04, GCC 13.3.0, CMake 3.31.6, Ninja 1.13.2;
- `libgmp-dev=2:6.3.0+dfsg-2ubuntu6.1`;
- `DIRECTIONAL_ENABLE_GMP=ON`, GMP discovered under `/usr`, and the authoritative link command contains both `libgmpxx` and `libgmp`;
- packaged command boundary records `exactArithmeticBackend=GMP`, `turnBoundary=Code+Build-only`, and `runtimeExecution=false`;
- internal `SHA256SUMS` self-verification passed; the `OK` lines are checksum verification, not execution of packaged binaries.

Immutable compile/package artifact:

- result artifact **`9919225745`**, `m3-cp4c3-cb24-compile-result-33823590494`;
- artifact SHA-256 **`7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`**;
- packaged source archive SHA-256 **`34d938298466d4be9b73a6034d1ed21230104c6634a1dfaa82b2ab71f81fa704`**;
- diagnostic log artifact **`9919226113`**, SHA-256 **`a9efadb18ace1feb1e1df156d561573da4cdfead642d168cc88eb7c09c5b05a9`**.

This is semantic M3 package **87**. No runtime acceptance is claimed by the compile.

## 6. Known risks / unresolved semantic questions

CB24 deliberately leaves the two competing interpretations unresolved. TB22 must publish the actual BY2–BY4 evidence from the mechanical production path. In particular, the projection-faithfulness residual is an observation, not an expected constant encoded by CB24. The carried semantic reds at 366/367/368/369/370/374 remain owned by their existing records unless TB22 supplies contrary evidence.

## 7. Mandatory successor

Exact next turn: **`M3-CP4c-3-TB22`**, artifact-only, using immutable artifact `9919225745` and selector 393. Execute `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Plan.md` exactly.

After TB22 closes, the next boundary is **independent `M3-CP4c-3-TB22-REV`**. No Code + Build correction and no DEFN execution is pre-authorized by CB24.
