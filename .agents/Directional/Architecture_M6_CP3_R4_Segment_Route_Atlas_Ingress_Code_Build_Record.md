# R4 Code + Build — six segment-route fixtures with independently source-owned A3 (2026-10-11)

**Canonical turn:** `M6-CP3-CB1-ENTRY-R4`, IN_PROGRESS; successor UNKNOWN. **Scope:** test source and compile only. No test, benchmark, CLI, discovery, `ctest` or frozen 497-case runtime execution.

## Frozen source and root-cause scope

- Exact source snapshot workflow `38112316124`, trigger `c908029ac176f81f2eab4faf45800af1c8bf202e`, snapshot artifact `11692117408`, outer ZIP SHA256 `51bbba7696d2fa18c49b43e56602c1470461c880e53bd835b4fe2499fa18f12a`, `source.tar.gz` SHA256 `1bf33bec33b1f6ab73ab2bcc6a834e950c70917f964fb4d7a490a24c3e2bf660`, **6080/6080** `SHA256SUMS` verified, `runtimeExecution=false`.
- Frozen R3 test selector ordinals `202, 203, 204, 205, 206, 207`: `SurfaceCellSegmentRouteTransportAuthorityMigration.EquivalentSignedQuarterTurnsComposeSemantically`, `LegacyMatchingFallbackUsesSameTypedRouteComposition`, `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`, `MultiStepVertexFanComposesTypedRouteTransport`, `ReverseObservedRouteUsesExactTransportInverse`, `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`.
- Historical R3 classification: ordinals `202/203/204/206/207` `A4_NOT_PRODUCED_UNTYPED`, ordinal `205` `A4_INVALID_FINAL_CELL_STATE`. These are frozen historical first-observables, **not** evidence of current test outcomes. A missing independent A3 atlas was identified by local source inspection at `build_segment_route_network` (`tests/SurfaceCellsPhase10Tests.cpp`) as a real checked A4 ingress gap. This migration may not fix other latent failure causes, especially ordinal 205.
- The test helper's selected `CrossFieldResult` is intentionally different across six tests; compact-matching legacy input clears typed transition records, and the malformed negative deliberately corrupts source-edge metadata. Building the A3 atlas from either input would incorrectly reject atlas construction or fabricate missing data. The helper now derives source topology from original `fixture.mesh.F` and fixture options, builds independent A3 from `fixture.authoritativeField`, then supplies the unchanged chosen `crossField` to the producer. Typed source binding and original six test assertions remain mandatory.

## Verified source edit

- One file: `tests/SurfaceCellsPhase10Tests.cpp` (16 insertions; no production, workflow, selector, or original test-assertion changes).
- Exact patch `/Directional/Evidence/Directional_M6_CP3_R4_Segment_Route_A3_Atlas_Recovery.patch`; SHA256 `e67ee2a7ab2bcc4c3610355605de7b22f9b6c4594896c044a745859dea358b62`, body SHA256 `32bf4fb16c500cd8e91f8f0639cca68a9279a99ef3a01061378414fafafe48c7`; base `87f26ee4a7ad5278b88991576293721e35185cfa` (only intervening snapshot-mailbox changes versus exact source); `git apply --cached --check` and `git diff --check` passed.
- Google Drive dispatcher apply workflow `38112589873`, job `114391106574`, result artifact `11692530709` ZIP SHA256 `949e91af0bce88d809839ff73a12426fba60bfa56c48bc381d10190153097287`, log artifact `11692645515` ZIP SHA256 `dd60052070caf4b14b898bce60b883c1ab553db3d5af5cddb61b946f2fd19690`; semantic commit `4ee15ada1493e14ed49ab542025040ce6e9dd91a`, clean push and `runtimeExecution=false`. Source patch staged at Google Drive ID `1lQRvBZQNVBIjmAzVtrRSeLfoWPqES0a_`, then owner-permanently deleted after successful push/evidence.

## Mandatory exact-source GMP/GMPXX compile

- Workflow `38112672216`, job `114391347393`, exact semantic source `4ee15ada1493e14ed49ab542025040ce6e9dd91a`; eight standard targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Preflight and build exit `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, CMake GMP discovery and generated linker command with both `gmpxx` and `gmp`, `exactArithmeticBackend=GMP`, result package checksum manifest `28/28`, final source clean and `runtimeExecution=false`.
- Result artifact `11691733820` ZIP SHA256 `555573b5d42e78f1f06c69d042e8d809a1f84d0830341bbaa9334a67816854e4`; diagnostic log `11691718914` ZIP SHA256 `33351ed67361d8ca882851303fbbb04044236433a3222a4eeaa473d25821689c`.

## Constraints and continuation

Compile-only validation does **not** prove that legacy, malformed or multi-step A3 fixture semantics pass or reject at the intended predicate. Do not mark selectors restored or generate a new frozen gate. The remaining R4 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, six CP3, true multi-carrier/odd-τ and separately adjudicated dual-admissible-path obligations remain unclosed. A source-valid dual-simple-path ambiguity witness on a hard-cut connected manifold vertex link is not assumed to exist: review it independently; never invent nonmanifold authority. No Test + Benchmark is authorized by this Code + Build turn.
