# M6-CP3 R4 — Region-reference positive A3 ingress Code + Build record

**Turn:** `M6-CP3-CB1-ENTRY-R4` — remains `IN_PROGRESS`. **Successor:** `UNKNOWN`. **Type:** compile-only Code + Build; runtime executions forbidden.

## Source-exact scope

- Historical independent R3 94-row overlay: CP2-accepted/R3-RED frozen ordinals **123** and **124**, respectively `SurfaceCellAuthorityContractCutover.ConflictingCellRegionFailsBeforeMaterialization` and `SurfaceCellAuthorityContractCutover.ConflictingEdgeRegionFailsBeforeMaterialization`. Both recorded first observable `A4_NOT_PRODUCED_UNTYPED` in R3; the prior report does not alone prove the same cause remains at current source.
- Previous fix `e200af8b0e2984ae6a452df9fd8520016043cc7d` already preserved the complete checked-A4 region-reference reconstruction and added a positive A4 round trip, but the **initial** `build_surface_cell_network` fixture call of each test still passed tracing options with no source-owned A3 atlas. This independent snapshot inspection found the remaining inconsistency, not a new assertion failure.
- Source fix `d3a70402a999b34fe69cacd4905440f7d529e3ab`, `tests/SurfaceCellsPhase10Tests.cpp` only: replace each original positive producer call with the already-existing `build_phase10_with_source_atlas(mesh, crossField, targetSize, options)` helper. That helper constructs A2 `SourceTopologyRegions` from the original mesh/options and A3 `FieldTransportAtlas` from the original mesh/cross field before invoking the unchanged production builder. No selector names, expected error codes, production code, or negative-mutation semantics changed.
- The test still requires the initial positive producer and a successful unmodified checked-A4 reconstruction before testing `InvalidCellRegion` / `InvalidEdgeRegion` after exactly one region-ID alteration. A new failure in these or any other predicates is **not** silenced.
- Verified source patch SHA256 `1acbc66febaed827907ecf25bbf2b5304b42834633a08494bdc4cfad269a2f53`, body SHA256 `6ccc81d29c913ed2f92d1366f297e34fa6ede0aeb2d0edf56e5ed8fa4d420dbe82`, exact base `49a3cecb06eb42bd1f57eb4cb0cd6a7c074899a6`; Drive apply workflow [38125626216](https://github.com/akashskypatel/Directional/actions/runs/38125626216), exact semantic push `d3a70402a999b34fe69cacd4905440f7d529e3ab`, one file changed with 4 insertions/4 deletions, `runtimeExecution=false`. Backup `/Directional/Evidence/Directional_M6_CP3_R4_Region_Negatives_Source_A3_Positive_Ingress.patch`; consumed Drive staging owner-deleted.

## Compile evidence

- Exact mandatory eight-target compile **GREEN**: run `38125718129`, job `114429605388`, source `d3a70402a999b34fe69cacd4905440f7d529e3ab`, all eight required targets, GMP/GMPXX links, configure/preflight/build `0/0`, manifest `28/28`, clean source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11697351263` ZIP SHA256 `85074becb5acfb2170b406126b67d99e0cf8873252ec63adc54f71b731f27e44`, log artifact `11696729558` ZIP SHA256 `3a180fd2ddf4338104313ad423efc39b3cb42d7d405623bdb25384a5e36c17ea.
- No Directional generated binary, test, benchmark, discovery, CLI, or frozen 497-case acceptance executed. All prior CP2 accepted / R3 RED labels remain historical; this is a **candidate ingress correction**, not acceptance restoration or proof of the expected typed first rejection.

## Remaining authority / next step

R4 still owes the 39 carried endpoint effects, 34 Phase10 ingress/producer positives, seven source-valid DCEL fixture negatives, 88 CP2 accepted losses, genuine multi-carrier/odd-τ witnesses, six CP3 entry gates and independent adjudication of the dual-simple-path premise. Only separately authorized Test + Benchmark may execute the immutable frozen 497 selection. Preserve canonical turn `M6-CP3-CB1-ENTRY-R4`, status `IN_PROGRESS`, successor `UNKNOWN`; do not promote candidate GREEN compile into test PASS.
