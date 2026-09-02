# M3-CP4c-3-CB16 Code + Build Report

**Status:** COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE.
**Turn boundary:** Code + Build only. No Directional runtime test, selector identity, benchmark, generated discovery, CLI/help/version command, fuzzer, or custom runtime input executed.

## Objective and exact authority

CB16 discharges **BL0-BL9** from `Architecture_M3_CP4c3_TB13_Independent_Review_Record.md` §9. It corrects the proved vertex-exit gap in `vertex_trace_ray_second_point` and splits the previously collapsed vertex-trace secondary-parameter failure reason without broadening topology semantics.

The product correction landed at **`a2efc8d10213c86aa9136821cd83bfcb32388f80`**. The final compile/package source is **`6808c090f2dd229a48550d758f459bfd156da4b6`**; its only semantic-source follow-up changes the new mechanical compiled witness from the observation helper to `build_cp4c_pipeline_products_fixture`, resolving a test-helper type mismatch without changing product code.

Preserved recovery patches:

- product patch SHA-256 **`78497fa7a0242350919908bb350f61ea75abe8e57fa943cb815cde3c3e6a7f07`**;
- compile-fix patch SHA-256 **`2ca9520bbd7278f641f16bdf2b22f327ec9d78350638ec5f3e61c2e9374ceb54`**, diff-body SHA-256 `8b5bff2d8dea19c8f2b0dac416c4b6a7eee40bc055acc853aed87998f46701cf`.

Both successful Drive-apply paths verified patch/base/body identity and `runtimeExecution=false`; both consumed Google Drive patch files were permanently retired after successful application.

## BL0 / BL6 — frozen accepted boundary and selector 380

Selector **379** remains byte-identical at SHA-256 **`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`**, 379 lines / 379 unique identities. Static falsification of the missing vertex-exit case justified one appended compiled witness, so CB16 publishes selector **380** at SHA-256 **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`**, 380 lines / 380 unique identities. Selector 379 is the exact 379-line prefix of 380.

The appended identity is:

`GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure`

Accepted semantic authority remains **365/365**; no selector identity was executed in CB16.

## BL1 / BL2 — exact vertex-hit second point, last in the Forward chain

`vertex_trace_ray_second_point` now has one final exact fallback after every pre-existing Forward case. When the next segment's `entryPoint.source_support()` resolves to `SourceVertexSupport`, the helper expresses that source vertex as the current face's exact unit barycentric corner through `source_vertex_barycentric`.

The fallback is deliberately **last**. Every previously representable `edgeTransitExit`, continued entry point, terminal contact, and terminal point returns before it. Chain exhaustion was already a hard error, so the new case cannot reorder a previously successful rotation. The implementation uses `FieldExactRational` only; no tolerance, float, angle, or identity tie-break participates.

For the TB13 vertex-10 case, the exact shared corner is vertex 11 of face `(8,10,11)`, yielding barycentric `(0,0,1)`, denominator 1 and within-wedge parameter 0 as proved by TB13-REV.

## BL3 — typed failure split and retained discriminator payload

The legacy origin-port validation retains `VertexTracePortOrdinalInvalid`. Failure of `vertex_locus_secondary_parameter` now emits the distinct typed reason:

`VertexTraceSecondaryParameterUnavailable`

and carries `VertexTraceSecondaryParameterFailureReason` with the bounded subconditions:

- `TraceRayFaceUnavailable`;
- `SourceFaceRecordUnavailable`;
- `LocusCornerUnavailable`;
- `SecondPointUnavailable`;
- `InvalidDenominator`.

That emitter also retains the arc, trace, orientation, `firstSegment`, and `onePastLastSegment`, in addition to source vertex/face. The typed fields are projected through the cut-graph/remesh diagnostic surface, so TB14 can distinguish the new emitter from the legacy port emitter without inference.

## BL4 / BL7 — prohibition audit

CB16 does **not** change `vertex_trace_secondary_ranks`, the projection formula, `build_vertex_fan_slots`, `trace_ray_face`, edge-locus ranking, incidence ownership, cut ownership/admissibility, exact-coincidence fail-close, or the CB12/CB14/CB15 corrections. It adds no identity-based tie-break and no tolerance/float-derived topological decision. It does not repair finalize/contact fall-through, decouple 371/372, change the prescribed sphere, saturation, ordinal 370, folded-cone witness, vertex 30, or any fixture.

## BL5 / BL8 — compiled witnesses and accepted-boundary proof

`GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure` compiles the required bounded evidence:

1. a Forward vertex exit resolves from exact corner support and ranks at the exact boundary parameter;
2. a genuinely unrepresentable second point still fails, now as `VertexTraceSecondaryParameterUnavailable / SecondPointUnavailable`;
3. the production diagnostic projection retains the typed subreason, arc, trace, orientation and segment bounds;
4. the mechanical attempt-0 producer witness reaches a complete rotation-system observation instead of the TB13 vertex-10 helper failure;
5. an existing edge-transit case retains the same exact parameter/rotation behavior, demonstrating the new fallback does not preempt an accepted path.

These are compile-time witnesses only. Their semantic outcomes are not accepted until TB14 executes them from immutable package 84.

## Compile evidence — GREEN

The first eight-target attempt (`33681718237`) compiled the product correction through `directional_core` and then exposed only a test-helper type mismatch in the new mechanical witness. No Directional binary ran. The surgical helper correction produced final source `6808c090f2dd229a48550d758f459bfd156da4b6`.

Authoritative compile workflow run/job **`33682499470 / 100422188581`** compiled and linked exactly the eight required targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

- exact compile source: **`6808c090f2dd229a48550d758f459bfd156da4b6`**;
- result artifact **`9866902345`**, Actions artifact digest **`410f18cd45f0662d480592bc2bb567bb6ab02583cf0a0dd06629b5c57a0174f9`**;
- configure/preflight/build exit codes are zero; recursive manifest verifies; final source status is empty;
- all six packaged test/benchmark executables retain executable mode;
- link evidence contains both GMPXX and GMP and records `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

## Immutable package 84

Package workflow run/job **`33683929335 / 100426817194`** consumed compile artifact `9866902345` directly. It performed no replacement compile and executed no Directional binary. It reverified exact source identity, the immutable compile-artifact digest, compile manifest, GMP evidence, clean source status, selectors 373-380 and every prefix relation, 27 package-relative fixtures, executable modes, and package manifests before and after deterministic extraction.

- package artifact **`9867334959`**, Actions artifact digest **`67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`**;
- package log artifact **`9867335519`**, Actions artifact digest **`f4b1c14c5736f4ca3e19e06533c89aa44198d180a16b4508e77350e1256b75c3`**;
- inner deterministic `package84.tar.gz` SHA-256 **`8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`**;
- packaged source archive SHA-256 **`ca898abdf3e5a4d01429048f13a2a6f09dd6bc70dabd3b866209533f9e43db95`**;
- selector 380 SHA-256 `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`; frozen selector 379 unchanged;
- `fixture_count=27`; six packaged `directional_*` executables remain executable;
- `runtimeExecution=false`, `packageRepair=false`, exact arithmetic backend GMP.

Two package-orchestration attempts were non-authoritative and runtime-free. Run `33683377705` failed on an unstable checksum of the redirected artifact ZIP bytes; run `33683624213` then verified the immutable artifact metadata but failed on a transcription error in the selector-380 checksum literal. The successful caller verifies the GitHub artifact's immutable metadata digest and the corrected selector digest. Neither failed attempt changed semantic/package authority.

Authoritative semantic M3 package count advances **80 -> 81**. This is build/package evidence only, not semantic acceptance.

## BL9 — frozen TB14 discriminators

CB16 publishes these mandatory next-turn discriminators without executing them:

1. selector ordinals **1-365 remain 365/365**;
2. ordinal **366 no longer reports** the TB13 vertex-10 rotation failure under the old ambiguous `VertexTracePortOrdinalInvalid` path;
3. any remaining rotation red is separable: `VertexTraceSecondaryParameterUnavailable` must carry its typed subreason plus arc/trace/orientation/segment bounds, while `VertexTracePortOrdinalInvalid` now denotes the legacy emitter specifically;
4. the **BK7 conjunction is re-proved**: the old v47 collision remains absent **and** the full five-ray v47 rotation is published with distinct `secondary` values for the former colliding pair;
5. `M3-CP4c3-TB11-CAND-01` and `M3-CP4c3-TB12-REV-CAND-01` close only if discriminators 1, 2 and 4 all hold; the vertex-10 CB16 candidates require runtime confirmation before closure;
6. certification may now reach the face walk, where non-disc/admissible counters can legitimately be measured for the first time.

**No vertex-30 discriminator is published.** Nothing in CB16 proves execution reaches vertex 30.

The executable procedure and stop rules are frozen in `Architecture_M3_CP4c3_TB14_Artifact_Only_Test_Benchmark_Plan.md`.

## Exit

CB16 is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE**. CP4c-3 remains **OPEN**; accepted authority remains **365/365**; stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic package count is **81**. The exact next turn is artifact-only **`M3-CP4c-3-TB14`** on immutable package 84. No TB14 runtime work is part of CB16.
