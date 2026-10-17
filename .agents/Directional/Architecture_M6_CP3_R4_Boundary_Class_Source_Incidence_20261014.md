# M6 CP3 R4 — source-boundary class incidence (2026-10-14)

Canonical turn: `M6-CP3-CB1-ENTRY-R4`, Code + Build, still in progress. PR #8 remains draft/open. No TB497, successor, runtime execution, frozen 497-selector modification or accepted-count promotion.

## Source-authoritative defect and bounded change

In `build_authoritative_surface_cell_rails` the complete `AdaptiveFeatureEdge::incidentFaces` claim was checked against exact source incidence, but a forged `AdaptiveFeatureClass::Boundary` could still be attached to a real two-face interior source edge. The `AdaptiveFeatureMapBuilder` assigns `Boundary` only to singleton source-face incidence. Preserve the existing valid hard-rail contract and add one first-producer rejection when `Boundary` has incidence count other than one. Keep the typed `InvalidFeatureEdge` error and original feature-edge index; no new ABI or error class.

The existing mandatory `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` test now includes an authentic source-boundary positive on edge (0,1), plus a forged Boundary classification of source interior edge (1,4), supported by two actual faces (0,3), expecting first-edge rejection. The previous component and exact-incident-face negatives are retained. These are **source-authored, compile-only** oracles, not runtime results.

## Exact evidence

- Verified snapshot at `6d9138b4098c7033df460981d5b43edde4616491`, workflow [38559146201](https://github.com/akashskypatel/Directional/actions/runs/38559146201), immutable archive outer SHA-256 `a99353e4d7445f025522cabb3ce990fd7dbb07839f754e06152653ebbc1fb431`, 5898/5898 source checksums.
- Two-file self-describing patch full SHA-256 `4f6da62d704821e365af63358fe9c477ec318ab6eeeab40a784fb1a6d9539aa4`, body SHA-256 `30c24b95baec75ff97eea56288e51d5fe3acbfb2e5551d7c1f6cee1190f2fac8`, forward/reverse `git apply --check` and `git diff --check` passed. Preserved in ChatGPT Library `/Directional/Evidence/Directional_R4_Source_Boundary_Incidence_20261014.patch`.
- [Drive patch apply 38560046391](https://github.com/akashskypatel/Directional/actions/runs/38560046391) succeeded, semantic commit `99399772c9f17ebbe39e1dbc0f2dfdb11009bfc0`. Result ZIP `11891408361`, SHA-256 `a4ef5eb0a8e6abc408d2fa0a12cfed52f3af6dc99fb6bfdd72d4bdc2f04bb556`, `runtimeExecution=false`. Independent GitHub compare verified exactly `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellREPackageTests.cpp`. Google Drive staging File ID `1yBG8AXKE25th2wNtMqb8fBod-RJJ1Rz3` permanently deleted successfully.
- Exact GMP/GMPXX eight-target compile submitted by dispatcher commit `2d928bc580450a87806245beb44bf2c121388a1e`, mailbox `m6-cp3-r4-boundary-incidence-compile`. **At report creation, compile evidence is pending; do not claim green.**

## Carry-forward

When compile mailbox publishes, inspect job conclusion, exact source SHA, artifact digest, full SHA256SUMS, eight linked targets, GMPXX and GMP generated link, clean source statuses, and `runtimeExecution=false`. No binaries/tests/benchmarks may run during this Code + Build turn. Independent RA-43.1/RA-43.2 source branch and filled-side Review remains required for that separate claim; do not invent trace-field coupling. RA-43.4 source consumers, RA-47.12 execution, 39 endpoints, 34 Phase10, 7 DCEL, 88 CP2, six CP3, organic D1/D2/D3/D5/A6/A7 and odd-tau multicarrier remain carried. Frozen selector and accepted ledger unchanged. Continue the **same** R4 turn.

## Compile closeout — verified 2026-10-14 12:02 UTC

The pending compile is now **GREEN** for exact semantic SHA `99399772c9f17ebbe39e1dbc0f2dfdb11009bfc0`: [dispatcher run 38560327102](https://github.com/akashskypatel/Directional/actions/runs/38560327102), compile job `115839633810`, result artifact `11891348919`, outer ZIP SHA-256 `144d53b7d3ca81907161904fb39daf6a9db78a14bafea960e392328ae3709952`. Independent manifest verification: **28/28** hashes, **8/8** approved targets, preflight/build exits **0/0**, five empty source-status reports, `exactArithmeticBackend=GMP`, both `libgmpxx.so` and `libgmp.so` in the generated linker command, exact source commit and `runtimeExecution=false`. Test + Benchmark job skipped. The regression was **compiled, not executed**; do not promote its behavior to runtime PASS.
