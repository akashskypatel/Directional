# M6-CP3-CB1-ENTRY-R4 — Three Phase10 row-order A2/A3 test-source migrations

Canonical turn remains `M6-CP3-CB1-ENTRY-R4` IN_PROGRESS; successor UNKNOWN. This is Code + Build source and compile evidence only, not a test result.

## Source authority and correction

Verified source snapshot `fba678ee4cf9e5308ccd9bf34531ed94ce1dae3e` from workflow `38104508456`: provider outer ZIP SHA-256 `4cddab7ee92aa25c3d0e357b0388a25a365955c83429f524cbb8572c117606f0`, source manifest 6053/6053 entries. In that source, three CP2-accepted/R3-RED frozen selector identities were still calling `build_surface_cell_network` with no independent A3 atlas: ordinal 245 `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`, ordinal 255 `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`, and ordinal 257 `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`. Their historical R3 first cause was grouped `A4_NOT_PRODUCED_UNTYPED`; a null source A3 pointer cannot be credited as the production A4 authority.

The one-file test patch reuses the already-existing `build_phase10_with_source_atlas` helper, which constructs `SourceTopologyRegions` from each original mesh/labels and `FieldTransportAtlas::make(mesh, sourceAuthority, hardFeatureEdges, crossField)` from that original mesh and field. It adds only a forward declaration so earlier tests can call it, preserving each original face-row permutation, target size, chart field, component/sheet labels, original assertions, identities, production code, factory strictness, and frozen selector list. Locally `git diff --check` and `git apply --cached --check` passed. Complete patch SHA-256 `616a160461c760dd72b7da18279b0ba05b78d0e15f840ad0fa2b2f6c17bba415`, copy stored in `/Directional/Evidence/`. Drive apply workflow `38104841732` verified patch hash, only `tests/SurfaceCellsPhase10Tests.cpp` changed, applied semantic commit `2626a053424cc8ff53c31c13fe5559494835b1af`, and staged Drive file was permanently retired.

## Source-exact GMP/GMPXX compilation

Mandatory workflow `38104929249`, job `114368349287`, exact source `2626a053424cc8ff53c31c13fe5559494835b1af`: eight approved targets compiled, preflight/build exit 0/0; `DIRECTIONAL_ENABLE_GMP=ON` and both `gmpxx`/`gmp` in generated link command; `exactArithmeticBackend=GMP`, clean source, self-manifest 28/28, `runtimeExecution=false`. Result artifact `11689775162` ZIP SHA256 `841dfae0769f52f71578cc2b75fc8607329304a699c9154a88fa94ffb1771dcd`, diagnostic artifact `11688649940` ZIP SHA256 `9a15450a17cb68d98cd6ee65fa9fd69cc74f2616a605fca7da5117314a529d12`. No Directional executable (test, benchmark, `--list`, `ctest`, CLI) was run.

## Incomplete obligations / prohibitions

These three corrections are only **compile-GREEN recovery candidates**: no frozen selector PASS, first runtime rejection, or R4 acceptance is claimed. R4 still owes 39 carried endpoint cases, 34 Phase10 positives, seven DCEL fixture negatives, 88 formerly accepted CP2 failures, real multi-carrier/odd-tau source witnesses, and independent design adjudication of second-simple-nonhard-path feasibility in a cut two-manifold vertex star. Frozen CP2 491/491 PASS is last accepted; R3 403/497, 94 RED, events/categories/recurrences 66/17/49 and debt 1 unchanged. No Test + Benchmark successor authorized.
