# M6-CP3-CB1-ENTRY-R4 — unique curve-edge source ownership (2026-10-14)

Canonical R4 Code + Build remains IN_PROGRESS, PR #8 draft/open; no TB497 or successor.

## Source finding and fix

Verified snapshot `d60909ee11ce9bc7d15624558629575da5fca0ec`, workflow [38565300325](https://github.com/akashskypatel/Directional/actions/runs/38565300325), artifact 11894131597 SHA256 `c2be9dcc1a60727f4e3ae2a11e8affb460f4d90f8debc0ada1b2d892d27f792f`, 5912/5912 file hashes. `AdaptiveFeatureMapBuilder::trace_curve_from_seed` marks source edges visited, but the first rail producer did not reject repeated `curve.edges` indices. A forged curve could use one real boundary edge twice and publish repeated rail intervals.

The bounded producer guard records feature-edge curve membership and rejects a duplicate at the original feature-map index with `InvalidFeatureEdge` before producing rail intervals. Existing positive source boundary behavior remains. The existing `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` test now also forges a two-interval closed curve `{0,1,0}` using edge index zero twice, and requires that first rejection with no consumable product. This is compiled-source evidence only, not a runtime PASS.

## Patch, apply, and compile boundary

Source patch backed up in ChatGPT Library `/Directional/Evidence/Directional_M6_CP3_R4_Curve_Edge_Uniqueness_20261014.patch`. Full SHA256 `8560a4b93bd17a307f30817cd3dd9ab1df8b17008d413d27c9e853c01b363491`; diff-body SHA256 `440b517ceabce497fad932d6aa77386a8ec8c6d6031214d7bab3b0ac73c9206b`. Local whitespace and reverse applicability passed; no local compile.

Verified Drive apply run [38566340470](https://github.com/akashskypatel/Directional/actions/runs/38566340470); result artifact 11896055738 ZIP SHA256 `9dcaeeba64a14c8338da05dc48538b41fecdab73d47ca5b642b06c5b5f88d404`, exact semantic commit [1470c325](https://github.com/akashskypatel/Directional/commit/1470c3258caa6b822a02d245b9719a57ff87632c). Independent compare proves only `src/pipeline/RemeshPipeline.cpp` (+7) and `tests/SurfaceCellREPackageTests.cpp` (+17) changed. Transient Drive patch owner-deleted successfully.

Exact-source eight-target GMP/GMPXX compile requested at dispatcher commit `b08f59533607cf07dba74139eaa6f11f2a934037` with mailbox `m6-cp3-r4-unique-curve-edge-compile`, pinned to `1470c3258caa6b822a02d245b9719a57ff87632c`. **Compile GREEN on exact semantic source.** [Workflow 38566701826](https://github.com/akashskypatel/Directional/actions/runs/38566701826), compile job `115861258547`, immutable result artifact `11895806522`, ZIP SHA256 `e6f2335005bd35a288bb4800fabd0c1ba0e8da98a06e853740cafab2ac8dace5`. Independently verified 28/28 `SHA256SUMS`, eight target names, exact `metadata/source-commit.txt=1470c3258caa6b822a02d245b9719a57ff87632c`, preflight/build 0/0, five empty source-status files, generated GMPXX/GMP linker command, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, and test-benchmark job skipped. No runtime acceptance credit.

Remaining R4 work includes independent RA-43.1/RA-43.2 A4-selected/A1-admitted branch and filled-side attribution Review, further RA-43.4 source-consumer work, 39 endpoint/34 Phase10/seven DCEL/88 accepted CP2/six CP3 restorations, executed RA-47.12, and organic odd-tau/multi-carrier witnesses. Runtime tests and benchmarks were not executed here. Frozen 497 selector, accepted ledger, and prior runtime baseline unchanged.
