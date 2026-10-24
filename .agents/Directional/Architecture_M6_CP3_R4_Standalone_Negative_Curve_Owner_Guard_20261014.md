# M6-CP3-CB1-ENTRY-R4 — standalone negative curve-owner correction (2026-10-14)

**Turn and boundary:** Same R4 Code + Build turn, still unfinished. No TB497, successor, generated binary tests or benchmarks, selector alteration or runtime/acceptance promotion.

## Exact source authority

Snapshot workflow [38596495573](https://github.com/akashskypatel/Directional/actions/runs/38596495573), source/event `840583d57ac0263b6d6230bf0b59e1a9b58b0622`, snapshot artifact `11909188937`, ZIP SHA-256 `d34dd48b864a7f035af75f25d640d242f8820e4ddfd1bdd6c6caff49e4501959`, all 5963/5963 source hashes passed. The last prior semantic source was `6d6d269dd2df211a96de1fcd20bacb54a4e34358`, eight-target GMP/GMPXX compiled, runtime unexecuted.

The canonical `AdaptiveFeatureEdge::curve` unassigned sentinel is exactly `-1`; actual producer-owned curves use nonnegative IDs. The standalone rail path in `build_authoritative_surface_cell_rails` rejected orphan claims `curve >= 0` but accepted `curve = -2` and published that noncanonical ID as `rail.curveId`. This is a malformed externally supplied metadata acceptance gap established by static source inspection, not an observed runtime regression.

## Change

- `src/pipeline/RemeshPipeline.cpp`: reject standalone curve-owner values below `-1`, preserving the existing orphan check, `InvalidFeatureEdge` and precise failing index. Valid `-1` unassigned owner behavior unchanged.
- `tests/SurfaceCellREPackageTests.cpp`: extend existing `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` with source-valid edge #1 claiming `-2`; require typed rejection and no consumable product. No new test identity or selector modifications.
- Two files, +15/-1 lines. Exact-base full-index patch SHA-256 `076755954cc9fcdf4ab70465ceb5d0e3006b38f46346908901d954de4ee9ea6f`; body SHA-256 `b580f5d541d0583a2486f26bcddb97ca406cdf5c57e45d4fb44ff797e9ac5830`. Local git diff, forward apply and reverse apply checks passed. No local builds.

## Remote implementation and pending package

Applied from dispatcher commit `7828b61cf2a60d5f923377724fd5cdcc3209c7b7` using [workflow 38600624930](https://github.com/akashskypatel/Directional/actions/runs/38600624930), result artifact `11913556037`, outer ZIP SHA-256 `09d84d5b2042f7b88b169fb5c538a930bf952e189f5bd2b69a79d1f01524cbed`; receipt matched exact patch/base and `runtimeExecution=false`. Semantic commit [42d7915e](https://github.com/akashskypatel/Directional/commit/42d7915e9e3ba34216a50ff48974c8e9734af91f), independent two-file compare confirmed. Temporary Drive patch `19Vt3GDcl5bD_WV5eEWAqAWOeVqTX5AMT` owner-deleted successfully.

The mandatory pinned eight-target GMP/GMPXX compile request is published at dispatcher commit `5499884d52d9fce47e7ece7e6a50a2f4a8edb750`, exact source `42d7915e9e3ba34216a50ff48974c8e9734af91f`, mailbox `m6-cp3-r4-negative-standalone-owner-compile`. **Completed and reconciled:** [compile workflow 38600920037](https://github.com/akashskypatel/Directional/actions/runs/38600920037), compile job `115979814702`, immutable package `11913234237`, ZIP SHA-256 `89d899cffebdf077c2903c88de716cf94862ae15512787410c3eafda9d339829`, source TAR SHA-256 `fd8b6ac7ce07a5d242acdaa99b26855128d379a8d7f9cfdfa904aaa7b82d98e2`, 28/28 manifest entries verified, 8/8 approved targets, preflight/build exits 0/0, generated GMPXX+GMP linker command, all source-status snapshots clean, `runtimeExecution=false`. This is compile-GREEN only; no runtime test, benchmark, acceptance or successor claim.

## Open R4 gates

Independent RA-43.1/.2 A4-selected/A1-admitted directed source-branch and filled-side attribution Review, separate RA-43.4 diagnostic opt-out disposition, RA-47.12 executed liveness, historical 39/34/7/88/six restorations, organic D1/D2/D3/D5/A6/A7 and produced odd-τ multi-carrier remain unproved at runtime. Seven R3 DCEL fixture repairs are statically present but not executed. Frozen selector497, accepted/rejected ledger, PR metadata, successor remain unchanged. Only a subsequent separately authorized artifact-only TB and independent Review can accept runtime restorations.
