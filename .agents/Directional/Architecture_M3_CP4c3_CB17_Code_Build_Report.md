# M3-CP4c-3-CB17 Code + Build Report

**Status:** COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE.
**Turn boundary:** Code + Build only. No Directional runtime test, selector identity, benchmark, generated discovery, CLI/help/version command, fuzzer, or custom runtime input executed.

## Objective and exact authority

CB17 discharges **BN0-BN9** from `Architecture_M3_CP4c3_TB14_Independent_Review_Record.md` §9. It does not correct edge-locus ranking semantics. It makes every failure exit of `edge_locus_secondary_rank` typed and preserves enough bounded production evidence for TB15 to identify which previously collapsed branch owns the current ordinal-366 frontier.

The diagnostic implementation landed first at `5dcaa8be0c9677454f8d5144987eb599f544c0b9`. The first authoritative compile then exposed one compile-only declaration defect: `SurfaceCutGraph.h` referenced `EdgeTraceSecondaryRankFailureReason` before its definition was visible. The only correction was an opaque enum forward declaration. Final semantic/compile/package source is **`1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`**.

Preserved recovery patches:

- primary CB17 patch SHA-256 **`8908784862273f94905ecc179f1aa26df749d973ea021b3342359d2aa265b806`**;
- compile-fix forward-declaration patch SHA-256 **`e2f9dc3ac6e18ee05e25d4695dfc6223a285fdcdfdbb9180ae2592f25d78828b`**.

The primary patch's Drive application succeeded but the service-account identity lacked owner trash authority; owner-side cleanup later found the exact File ID no longer addressable. No unconsumed repository patch payload remains.

## BN0 / BN6 — frozen accepted boundary and selector 381

Selector **380** remains byte-identical at SHA-256 **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`**, 380 lines / 380 unique identities. The diagnostic falsification justified one append-only identity, so CB17 publishes selector **381** at SHA-256 **`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`**, 381 lines / 381 unique identities. Selector 380 is the exact 380-line prefix of 381.

The appended identity is:

`GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible`

Accepted semantic authority remains **365/365**. No selector identity was executed in CB17.

## BN1 — typed edge-locus failure reasons

`edge_locus_secondary_rank` now reports `EdgeTraceSecondaryRankFailureReason`, with one stable reason for each former untyped `nullopt` branch:

- `TraceRayFaceUnavailable`;
- `SourceFaceRecordUnavailable`;
- `ContactEdgeUnavailable`;
- `OppositeCarrierNotInFace`;
- `CoincidentLocalEdgeIndex`;
- `SourceVertexFallbackUnbound`.

The helper's successful return values and rank formulas are unchanged.

## BN2 / BN3 / BN4 — retained incidence and production projection

The error surface retains the bounded incidence required by the review: arc, trace, orientation, segment interval, incoming/outgoing carriers, resolved contact index, candidate other carrier, trace source vertex, and the three source-face corners. The typed reason is projected through `SurfaceCutGraphError`, `GlobalTopologyPlanError`, and `RemeshPipeline` to the production renderer.

The same failure projection carries a bounded edge-locus ray census. Each published ray records kind, primary rank, secondary rank when available, arc, trace, orientation and face. The census carries total-ray count and an explicit truncation flag.

## BN5 / BN8 — compiled witnesses and non-semantic audit

`GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible` compiles six independently constructed failure cases, one for each typed reason, and projects each through the production diagnostic surface. It also compares the successful edge-locus rank with and without diagnostics and requires the exact same rank, proving the observer path does not manufacture a different successful value.

The change does not alter a control-flow decision, accepted rank value, rotation ordering or topology decision. This is compile-time evidence only; TB15 must execute it before any semantic conclusion is accepted.

## BN7 — prohibition audit

CB17 does **not** change rank formulas, fallback order, `sideRank`, `key.primary`, collision detection, `build_node_loci`, contact-node construction, cut ownership/admissibility, source identity, enumeration order, tolerances, accepted boundaries, fixtures, finalize/contact fall-through, the 371/372 coupling, sphere/saturation/ordinal-370/folded-cone behavior, or the CB12/CB14/CB15/CB16 corrections. No product correction and no vertex-30 discriminator is introduced.

## Compile evidence — GREEN

The first corrected-permission compile run **`33696980384`** reached compilation at diagnostic source `5dcaa8be0c9677454f8d5144987eb599f544c0b9` and failed only because `SurfaceCutGraph.h` lacked the opaque forward declaration for `EdgeTraceSecondaryRankFailureReason`. No Directional binary ran. The surgical declaration-only correction produced final source `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`.

Authoritative compile workflow run/job **`33697315308 / 100468915978`** compiled and linked exactly the eight required targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

- exact compile source: **`1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`**;
- result artifact **`9872340053`**, Actions digest **`3a814357edf9b1f2424f4047b6c84b1e37ed54dc1751ab6a1fa3b125af206274`**;
- log artifact **`9872340412`**, Actions digest **`fcda1a3fbd206e6b9ce159dea3516a18b405897d842528268a28ad0827023b39`**;
- configure/preflight/build exit codes are zero; recursive manifest verifies; final source status is empty;
- all six packaged test/benchmark executables retain executable mode;
- link evidence contains GMPXX and GMP and records `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

## Immutable package 85

Package workflow run/job **`33697837275 / 100470530585`** consumed compile artifact `9872340053` directly. It performed no replacement compile and executed no Directional binary. It reverified exact source identity, compile-artifact digest, compile manifest, GMP evidence, clean source status, selectors 373-381 and every append-only prefix relation, 27 package-relative fixtures, executable modes, and package manifests before and after deterministic extraction.

- package artifact **`9872426500`**, Actions digest **`6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`**;
- package log artifact **`9872426826`**, Actions digest **`33ee68f4217af33ce8c37049820c3a7f41bae55c29c97972025887f616d99b20`**;
- inner deterministic `package85.tar.gz` SHA-256 **`98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`**;
- packaged source archive SHA-256 **`cb078005cef48d97401ddfb843a4276f92c53086b0827a915b01344dc665c4a9`**;
- selector 381 SHA-256 `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`; frozen selector 380 unchanged;
- `fixture_count=27`; six packaged `directional_*` executables remain executable;
- `runtimeExecution=false`, `packageRepair=false`, exact arithmetic backend GMP.

Authoritative semantic M3 package count advances **81 -> 82**. This is build/package evidence only, not semantic acceptance.

## BN9 — frozen TB15 discriminators

CB17 publishes these six mandatory next-turn discriminators without executing them:

1. selector ordinals **1-365 remain 365/365**;
2. ordinal **366 remains RED** at `EdgeTraceSecondaryRankInvalid` with the same source edge `25-31`, source face `(25,30,31)`, attempt 0 / zero cut edges; **any movement falsifies BN7**;
3. the failure line names the exact `EdgeTraceSecondaryRankFailureReason` branch that fired;
4. the line retains arc, trace, orientation, segment interval, incoming carrier and outgoing carrier, together with the bounded retained incidence fields;
5. the bounded edge-locus ray census is present with its truncation marker;
6. **the v47 conjunction remains owed**: selector 380 is expected to remain RED until the responsible edge-locus owner is corrected, so `M3-CP4c3-TB11-CAND-01` and `M3-CP4c3-TB12-REV-CAND-01` do not close in CB17.

**No vertex-30 discriminator is published.**

The executable artifact-only procedure and stop rules are frozen in `Architecture_M3_CP4c3_TB15_Artifact_Only_Test_Benchmark_Plan.md`.

## Exit

CB17 is **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE**. CP4c-3 remains **OPEN**; accepted authority remains **365/365**; stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic package count is **82**. Exact next is artifact-only **`M3-CP4c-3-TB15`** on immutable package 85. No TB15 runtime work is part of CB17.
