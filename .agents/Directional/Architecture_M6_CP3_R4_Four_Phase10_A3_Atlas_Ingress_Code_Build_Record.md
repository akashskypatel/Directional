# M6-CP3-CB1-ENTRY-R4 — four Phase10 source-A3 fixture ingress corrections (2026-10-11)

**Canonical:** `M6-CP3-CB1-ENTRY-R4` IN_PROGRESS; successor UNKNOWN. **Execution boundary:** Code + Build, compile only. Not a Test + Benchmark acceptance or success claim.

## Source authority and exact change

Snapshot workflow `38107135716`, source/event `c279d5886168dd6852a1a98b4c8fedb4e9212bbf`, provider ZIP SHA-256 `9780d1cbbda335774c131c84c9dce918db8c9db5d93a12933fd40727c1307072`, archive SHA-256 `196ae3373e2af701fa9dcce2b779ee92f9df77d0440832866cc1e3280ea0f62d`. All **6062/6062** source `SHA256SUMS` verified; snapshot recorded `runtimeExecution=false`.

Historical frozen R3 error classification records each of these as `A4_NOT_PRODUCED_UNTYPED`, but **the resulting runtime state of the new build is unknown**. They were still passing null A3 into the A4 path despite the source-owned atlas contract:

- selector 119 — `SurfaceCellAuthorityContractCutover.CellAndEdgeConsumersReferenceThePublishedRegion` (one A4 entry)
- selector 129 — `SurfaceCellAuthorityContractCutover.FaceRowPermutationPreservesSemanticRegionIdentity` (two A4 entries)
- selector 196 — `SurfaceCellPhaseFrontFieldChartAuthorityMigration.FaceRowPermutationPreservesTypedPlanarChartAuthority` (two A4 entries)
- selector 248 — `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam` (one A4 entry)

Only `tests/SurfaceCellsPhase10Tests.cpp` changed: six existing `build_surface_cell_network` call sites now use existing `build_phase10_with_source_atlas`, which builds `SourceTopologyRegions` from the original mesh/labels and independently calls `FieldTransportAtlas::make(mesh, sourceAuthority, hardFeatureEdges, crossField)` before entering the unchanged producer. Original meshes, source-face labels, cross fields, fixture shape, test names, assertion bodies, selector ordering, and production code are unchanged. No source authority rule has been relaxed; construction errors fail closed.

The locally preflighted binary/full-index patch has SHA-256 `2aa9a5daaf2af6240447f1a90140efc4846b051211fb272956324f1d52f6ac65`, diff body SHA-256 `157c60bcff6738b4db6e18848d20a3c53bb48a1baadaf5534cc3ba46ac68374f`, base SHA `37c5c247b518951e31aa41f3bfdab7e423a37aff`; both `git diff --check` and `git apply --cached --check` succeeded. Library recovery copy: `/Directional/Evidence/Directional_M6_CP3_R4_Four_A3_Phase10_Cutover_Regression_Recovery.patch`. Workflow `38107433774` (apply job `114375849173`) verified exact hashes, changed-path set and successful push; applied semantic commit `4467edc69f6c8b2d4530cd902d4de32681aa3671`; consumed Google Drive stage owner-deleted.

## Exact-source GMP/GMPXX compile evidence

Mandatory dispatcher compile workflow `38107520617`, job `114376101533`, exact semantic source `4467edc69f6c8b2d4530cd902d4de32681aa3671`: **SUCCESS**; all eight approved targets, preflight/build exits `0/0`, CMake `DIRECTIONAL_ENABLE_GMP=ON`, authoritative link command contains `gmpxx` and `gmp`, `exactArithmeticBackend=GMP`, final source status clean, recursive package manifest `28/28` valid, `runtimeExecution=false`. Result artifact `11689459391` outer ZIP SHA-256 `a6b1a0ab0f91694ba33d730de0a596be8d49cd1d72ef799323ee37a826646506`; diagnostic artifact `11689613812` outer ZIP SHA-256 `ac7d3802a0ee67df5391ee12af6ab1df0d0d2f1a4370612f3f5567ec81981434`.

**Not executed:** tests, benchmarks, `ctest`, generated binaries, discovery/list commands, frozen 497 selector or supplemental cases. These remain **four unverified candidate repairs**, not accepted semantic passes.

## R4 continuation and frozen gates

Last accepted CP2 baseline is 491/491. Rejected R3 candidate is 403/497 with 94 RED and 88 formerly accepted CP2 RED; the frozen 39 endpoint, 34 Phase10, seven DCEL and producer-valid odd-τ/multi-carrier obligations remain open. Historical ledger 66/17/49, debt 1 unchanged. Independent design decision is needed before requiring a source-valid second simple non-hard A2b path on a two-manifold vertex star cut by a hard carrier. No R4 completion or TB497 successor is authorized. Future actual results must use separate exact artifact-only Test + Benchmark authority and update the root-cause tracker.
