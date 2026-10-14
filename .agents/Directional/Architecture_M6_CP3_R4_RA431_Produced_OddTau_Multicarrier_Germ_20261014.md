# R4 RA-43.1 / D2 — genuine nonconstant two-carrier odd-tau vertex germ (2026-10-14 UTC)

**Turn authority:** `M6-CP3-CB1-ENTRY-R4` IN_PROGRESS Code + Build, PR #8 open/draft. Do not launch TB497 or successor, edit frozen selectors, or execute runtime binaries/tests/benchmarks in this turn.

## Exact source and authored invariant

The immutable eight-target GMP package from workflow `38512103184` provided source `49c5362dd58365abdee05307b75e197bd0c071cf`, outer artifact SHA256 `5470facda992313db906817373c6ea353ba7a482161c46941d11f27801b0e7e0`, and all 28 archive checksums passed. No src/include/tests/CMake changes occurred between that semantic SHA and this attempt's opening branch head.

An existing `tests/SurfaceCellREPackageTests.cpp` source file was extended by new `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm`, deriving its real 3×3 source and right-side quarter-rotated field from the already-existing producer `make_nonconstant_hard_rail_fixture` pattern. The new oracle:
- requires A4 to publish the actual two-edge `(1,4),(4,7)` hard-rail certificate and junction source vertex `4`, not an input-only claim;
- requires one odd directed hard-carrier tau from **that same paired certificate**, with A1 `FieldTransportAtlas::transition_value` equality;
- binds both A1 typed `HardFeature` barriers and the actual source mesh/branch topology to `resolve_field_vertex_transit`;
- checks the real direct germ's nontrivial elected-owner audit, or its evaluated nonempty diagnostic walk with exclusion of both hard carriers and the A4 hard-feature edge set.

This is a new *source-authored* conditional witness, not an executed odd-tau success. The combined positive condition remains unverified until separately authorized artifact-only Test + Benchmark.

Initial source [b640d51](https://github.com/akashskypatel/Directional/commit/b640d51a9e3369449ea4cc75ca5939754443740c) compiled RED in [workflow 38514059053](https://github.com/akashskypatel/Directional/actions/runs/38514059053), job `115688853670`: ten test-source `DomainResult<SourceEdgeTopologyKey>` erroneous `*a/*b` expressions, diagnosed from immutable log artifact `11871320272`, outer SHA256 `dc792a99874c60004653784f62260cd218a18c483d4acb10841b30f2a8c84896`. Corrected **only** those ten expressions to `a.value()/b.value()` in semantic [651da42](https://github.com/akashskypatel/Directional/commit/651da423b66645a2e1fc1962d04acc047eef8070), published Git blob `9c1e333c82d4cf5a45eaaa11a6c91d36bda509c2` matching independently generated local file.

Full exact-base patch against `49c5362dd58365abdee05307b75e197bd0c071cf`: SHA256 `20534b4aaa8c0d7de13171bca10e7842908d890c0c6afb2f215fc27ac9c425f1`, diff-body SHA256 `9a2296301d5939b29a14c6854d632b64ac60e85af1a4d0ffcd11f20763dc6a72`; `git apply --check`, actual pristine apply, `git diff --check`, byte equality passed. Corrected backup preserved at ChatGPT Library `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R4__base-49c5362dd583__odd-germ-corrected.patch`. A previous original erroneous patch exists and is superseded; do not use it.

## Corrected GMP compile

Dispatcher commit [c353728](https://github.com/akashskypatel/Directional/commit/c3537284db8e2c93c56a7bea513f3499ed95d6d1) pinned corrected semantic source `651da423b66645a2e1fc1962d04acc047eef8070`, all eight approved targets and mailbox `m6-cp3-r4-nonconstant-odd-germ-fixed-compile`. **PENDING**: verify eventual immutable result/archive, all 28 hashes, GMPXX+GMP generated link, exact source, preflight/build exits, five clean source status files and `runtimeExecution=false`. Do not equate dispatcher acceptance with compile success.

## Carry-forward

Still open: actual runtime verification of this combined genuine two-carrier odd-tau A1 germ; other RA-43.1/43.4 production/consumer work, RA-47.12 executed liveness, historical 39 endpoints / 34 Phase10 / 7 DCEL / 88 accepted CP2 / six CP3 restoration, organic D1/D2/D3/D5/A6/A7, and separate authorized artifact-only TB. Existing RA-46.5/46.6 negative source oracles and RA-49/51 retirements remain unchanged; frozen 497 and historical ledger are not promoted.
