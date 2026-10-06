# Architecture M6 CP3 CB1 Entry Authority Code + Build Report

**Turn:** `M6-CP3-CB1-ENTRY`
**Verdict:** COMPLETE / COMPILE-PACKAGE GREEN / RUNTIME-FREE
**Successor:** `M6-CP3-TB1-ENTRY-EXEC`

## Semantic source and implementation

RA-30 + RA-30a entry authority was implemented at exact semantic source
`912760f1ffc785676f5d50717177b1cd8be69234`.

The corrected complete transport patch was SHA-256
`c164988940469d0a1a0c778be65ecf214ab126f690bf8098ccce7097524bd343`,
with diff-body SHA-256
`66539ec0b18cfc0b291315878894d1abdacbbc27c450260d4fb56466932d99ec`,
based on exact source `836d8acf3565faa010d0161614d854ece6f8d1f3`. It changed exactly six files:

- `include/directional/geometry/SurfaceCellTracing.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `src/geometry/SurfaceCellTracing.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`
- `tests/SurfaceCellsPhase10Tests.cpp`

The first Drive-apply attempt (`37455665769 / 112242600282`) failed before commit because the earlier locally retained "base" directory had been modified during implementation; `git apply --check` therefore rejected two hunks. The immutable packaged source archive remained correct. The patch was regenerated from a fresh extraction of that immutable source and independently passed exact-base `git apply --check` and `git diff --check` before retry.

Corrected Drive-apply run/job `37458022713 / 112250373902` verified the exact patch/base/body/intended-path metadata and pushed semantic commit `912760f1ffc785676f5d50717177b1cd8be69234`. Result/log artifacts are `11410891262 / 11411036253`. The workflow could not trash the staged Drive file with its service identity and reported owner cleanup required; the owner-authorized connector subsequently permanently deleted File ID `1p1ISqnbtoiTjS6cagz-usBt2u0T2khId`.

## Implemented RA-30 / RA-30a entry authority

The bounded implementation provides the five entry semantics required before direct-production acceptance:

1. **Periodic exact-A3 gauge separation.** Relation-gauge coordinate/branch semantics are validated independently from occurrence-placement face gauges; placement transport is derived by endpoint gauge conjugation and equal endpoint transports are required.
2. **HardRail branch certification.** Immutable endpoint face-gauge evidence is published and both canonical endpoint branch pairs are stripped by their face gauges before being checked against the coordinate-rigid quarter-turn. The external failure family remains `InvalidHardRailTransport` with site suffix `:branch-certificate`.
3. **OrdinaryFront isolation-seam identity.** Non-seam relations retain full identity checks. Certified isolation seams use coordinate/scale identity plus exact reciprocal sheet-transition and seam-quarter-turn evidence while quotient transport remains identity; phase remains reject-only.
4. **A5 typed chart barriers.** A4 publishes the exact typed source hard-feature set consumed by tracing; A5 consumes that product authority rather than reconstructing barriers from HardRail relation kinds. The pipeline adapter asserts equality with its source set.
5. **A7 relation-kind-aware sheet semantics.** Cross-region HardRail bindings do not compare global sheet labels; same-region OrdinaryFront/Periodic bindings require a shared sheet or exact connecting transition, while cross-region Periodic remains fail-closed for Review.

No optimizer class-wide reference, D6 permutation work, direct CP3 exit evidence, tolerance topology, positional merge, recovery/fallback, or arbitrary subset search was added in this turn.

## Frozen six entry identities

Exactly the six RA-30 entry identities were added and compiled:

1. `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`
2. `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`
3. `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`
4. `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`
5. `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`
6. `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`

They are compiled evidence only here. No generated test binary was executed by Code + Build.

The previously frozen gate authorities were not edited by the semantic commit:

- focused-30: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- focused-12: `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`

## Compile/package evidence

Mandatory compile workflow run/job: `37458495402 / 112251921276`.

Exact compiled source: `912760f1ffc785676f5d50717177b1cd8be69234`.

All eight standard targets compiled and linked successfully with GMP/GMPXX:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Compile result artifact `11411137781`, provider SHA-256
`704b1b70c9fd67aca95c78757c84433b97122fad6524f14326312131d3307234`.
Compile log artifact `11410478676`, provider SHA-256
`b78df9fd9c6474937d9af4606da8ca7d5484bf96be48b0ff1309902f22d8165c`.

The downloaded result archive re-verifies the recursive self-excluding manifest at **28/28** entries. `SHA256SUMS` hashes to `f1e0fefb72df8f8e4175cda5d0cd1f05ab8fc94b29d8250a960e6de3d6f8b153`; the packaged source archive hashes to `bf0f21a8899cc5a078a9c02761d18836be728df403b7d200226d7f39b4620e67`. Preflight/build exits are `0/0` and final source status is clean.

GMP evidence records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the authoritative link command. The command boundary records `exactArithmeticBackend=GMP`, `turnBoundary=Code+Build-only`, `runtimeExecution=false`, PRE_TEST configuration and an out-of-tree build.

No generated Directional executable, test, benchmark, discovery/list/help/version command, `ctest`, CLI, GUI, fuzzer or custom input was executed in this turn.

## Disposition

The CP3 entry implementation and compile/package gate are GREEN. This Code + Build result is not runtime acceptance and does not promote the six new identities by execution.

Exact successor is immutable artifact-only `M6-CP3-TB1-ENTRY-EXEC`: consume package/source `11411137781 / 912760f1ffc785676f5d50717177b1cd8be69234` without rebuild or repair and execute exactly **497 fresh exact-filter processes**: focused30 **30** + focused12 **12** + selector449 **449** + six CP3-entry identities **6**. Require exact-one selection, zero skips, immutable package/source/execution-view postflight and no benchmark execution. Then route to mandatory `M6-CP3-TB1-ENTRY-REV`; CB2 remains held until that Review.
