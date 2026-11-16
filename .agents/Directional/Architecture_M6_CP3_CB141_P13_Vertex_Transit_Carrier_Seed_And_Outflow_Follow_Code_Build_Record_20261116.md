# CB141 — vertex transit carrier seed and field outflow follow (Code + Build, 2026-11-16 UTC)

**Canonical turn:** `M6-CP3-CB141-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW`.
**Authority:** [RA-241](Architecture_M6_CP3_DEFN_P13_Edge_Transit_Seed_Conformance_Outcome_Review_20261116.md) §3. The user selected D12 = A: follow the field.

## Scope and source

- Applied only the frozen three-file diff `Architecture_M6_CP3_CB141_P13_Vertex_Transit_Carrier_Seed_And_Outflow_Follow_Exact.diff`, SHA-256 `cc937c0674b1deb6fd0bbf2fb561d1ad1fa1a1a26df58af6939103f08242b5`, with 482 additions and 24 deletions.
- Source snapshot `af289f341baeef4fb1dcc8c337b85f832b8f0bd2`: [run 43840674855](https://github.com/akashskypatel/Directional/actions/runs/43840674855), artifact `14213305499`, ZIP SHA-256 `4c9c5411003db4373c59c89a68c6ef5f64858a0539b4a552ac57771a410713e7`; 5,558/5,558 source checksums passed.
- Transport patch SHA-256 `2b665a4055d91efa9872bb8446304fff0dae12e40f708a3af82ac04f989c4971`; the authorized Drive apply [run 43841446114](https://github.com/akashskypatel/Directional/actions/runs/43841446114) succeeded. Source commit: `2dedeb097a7d652fd50979c9edbf7acc11222a9c`. The staged Drive file was permanently deleted after the successful apply. The exact patch remains in ChatGPT Library work preservation.
- `EdgeTransit` uses the incoming carrier ray to seed the vertex owner election. If the elected face has no field outflow, the trace follows the field by a valid radial Cross, or slides along a mutual outgoing radial by the existing edge-port departure rule. Other cases keep their existing fail-closed behavior.
- Added two regression tests in `tests/FieldAlignedCurveNetworkTests.cpp`: `EdgeTransitArrivalSeedsElectionOnCarrierRay` and `OwnerWithoutOutflowFollowsFieldAcrossRadialEdge`. They were compiled but **not executed** in this turn.

## Compile evidence

- Exact code source `2dedeb097a7d652fd50979c9edbf7acc11222a9c` compiled in [run 43841809892](https://github.com/akashskypatel/Directional/actions/runs/43841809892), result **SUCCESS**. The durable request was `m6-cp3-cb141-compile-20261116-v1`, event SHA `ac07b60ddbf773d8f102cbbdf0c97070b6049af5`.
- Immutable package artifact `14213982150`, outer ZIP SHA-256 `ea09976a5b961bf5a384e9eaf3ea2c1498a7dbab0a67858c218513d34565f497`. All **28/28** packaged file checksums passed. Source archive and empty final source status are included.
- The eight compiled targets are `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.
- Release build: tests and benchmarks were enabled for compilation; command boundary reports `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`. The package records `DIRECTIONAL_ENABLE_GMP=ON`, both GMP and GMPXX link libraries, and successful preflight and build exit codes of zero. This turn ran **no tests, benchmarks, census, or compiled Directional binaries**.

## Disposition and next turn

- CB141 source is committed and the eight required targets compile. These results **do not** prove that the two tests pass, that the production trace succeeds, or that the predicted BunnyRandom terminal changes.
- Next **separate** turn: `M6-CP3-TB122-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-FULL-GATE-EXEC` (artifact-only Test + Benchmark). Use RA-241 §4's frozen manifest `a56ad00c…` (949 cases, membership 1,030), deferred 81, and three-case census; do not rebuild in TB122.
- O44 stays open until P13-e.21 Review. O42/O43 remain open. Carry D11=A, D12=A, D10 deferred, D6 pending; accepted CP2 491/491, stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81; CP3 and selector497 unpromoted; `chainRimSchedules=false`.
