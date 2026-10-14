# R4 duplicate feature curve-owner guard — Code + Build evidence (2026-10-14)

**Canonical:** `M6-CP3-CB1-ENTRY-R4`, same incomplete Code + Build turn; no TB497, successor, runtime PASS, benchmark, frozen-selector change, or accepted-count promotion.

## Source authority and defect

Exact immutable prior source `f026512e4599eb9982c1f9afd4292ed429a82eae`, compiled in [run 38586952664](https://github.com/akashskypatel/Directional/actions/runs/38586952664), result artifact `11905148938`, SHA-256 `f4a10d548631ad44a3ec8a4a1fedb59c4f90186471f7503037e232fcc7f7ead1`. Verified package `SHA256SUMS` before inspecting source. `AdaptiveFeatureMapBuilder::trace_curve_from_seed` produces unique `curve.id = map.curves.size()` and stamps owning feature edges. `build_authoritative_surface_cell_rails` already checked repeated *edge membership* but allowed two distinct feature curves to share the same `curve.id`, publishing separate rails carrying indistinguishable `rail.curveId`. This is an externally forged input-integrity gap identified by static analysis, not an observed executed regression.

## Exact bounded implementation

- `src/pipeline/RemeshPipeline.cpp`: introduce `seenCurveIds` at the curve emission boundary; reject a nonempty curve whose `id < 0` or was previously seen, using existing `InvalidFeatureEdge` and `failedEdgeIndex=curve.edges.front()`. This does not invent IDs or renumber legitimate curves.
- `tests/SurfaceCellREPackageTests.cpp`: extend existing `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` with two source-valid separate ordered curve-member edges sharing owner ID 17. Require rejection on edge index 1, no consumable product; all preexisting positives and negatives retained.
- Exactly 2 source/test paths, +7/+19 lines, no deletes, no new test identity, no ABI or selector change. `git diff --check`, exact-base forward and reverse patch checks passed; no local build, Directional executable, tests or benchmarks ran.

Full-index patch base `f026512e4599eb9982c1f9afd4292ed429a82eae`; patch SHA-256 `eb691b1bb2899b0683d221c2204f63f7e7cdf254286c42b31e4c489ad3782dc8`; body SHA-256 `27e535deace905bbee9961198462eae6e317865d75ce5052641e17f770ee351d`.

Apply dispatcher commit `555fc76f84e9ca7de681d70dd7229371ed0154ee`. [Workflow 38593331149](https://github.com/akashskypatel/Directional/actions/runs/38593331149) successful, result artifact `11909000384`, ZIP SHA-256 `5584bc466c04a8f696ededf55b9b129fd4ec1b972815e14078c08edb95964f81`, receipt exact base/patch hashes, `runtimeExecution=false`. [Applied semantic commit 6d6d269d](https://github.com/akashskypatel/Directional/commit/6d6d269dd2df211a96de1fcd20bacb54a4e34358); independent compare shows exactly the intended two paths. Staged Drive patch ID `1sLJ_lVXgZ1xdPC0zhr9WjMAnaCTWlMof` permanently deleted by authorized owner connector.

## Remote compile boundary

Mandatory eight-target GMP/GMPXX compile request submitted at dispatcher commit `81e47991100bcf08d9b1e11e9620e4565e2c01ed`, exact semantic source `6d6d269dd2df211a96de1fcd20bacb54a4e34358`, mailbox `m6-cp3-r4-duplicate-curve-owner-compile`. **The compile receipt must be reconciled separately before claiming green.** No runtime PASS is claimed.

## Unchanged R4 obligations

RA-43.1 selected A4/A1 admitted branch and filled-side authority independent source-domain Review, RA-43.4 diagnostic opt-out disposition, RA-47.12 executed liveness, 39/34/7/88/six historical restorations, organic D1/D2/D3/D5/A6/A7 and genuinely produced odd-τ multi-carrier remain open. Preserve frozen selector 497 and accepted baseline; no successor or artifact-only TB in this Code + Build turn.

---

## Exact-source pinned GMP/GMPXX compile reconciliation

The pending compile request above completed successfully in [run 38593643840](https://github.com/akashskypatel/Directional/actions/runs/38593643840), compile job `115954831123`. Immutable result artifact `11909760571`, outer ZIP SHA-256 `b84cf6a8215c8cbf02a8b0f5a443854a18cf738d9144f7fb0b29bfabfd206fa8`; all 28/28 root SHA256SUMS validated. Exact source commit `6d6d269dd2df211a96de1fcd20bacb54a4e34358` and packaged source TAR SHA-256 `6086c1394896532e416261b56e2e09cce96bb424f114ee2ba71432de41d1cc5d`. Eight named required targets built, preflight and build exits both 0; generated C++ linker command includes `libgmpxx.so` and `libgmp.so`; clean source-status snapshots. `runtimeExecution=false`, `turnBoundary=Code+Build-only`; tests and benchmarks skipped. The packaged source contains `seenCurveIds` and the existing regression extension.

**Disposition:** narrow producer identity guard compile-GREEN, not runtime-proven. Preserve same unfinished R4 canonical turn and all independent RA-43.1/.2, RA-43.4, historic and organic artifact-only TB obligations; no successor, frozen-selector change or acceptance promotion.
