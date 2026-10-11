# R4 Code + Build — two Phase10 composite A2/A3 fixture ingress candidates (2026-10-11)

**Current canonical turn:** `M6-CP3-CB1-ENTRY-R4` IN_PROGRESS; successor UNKNOWN.

## Frozen historical evidence and bounded change

Source snapshot workflow `38114816726`, artifact `11693341686` outer ZIP SHA256 `5e5e4a3c59e080e54d74f88e41f80d8f403a4de7953584ce8398424039878093`, `source.tar.gz` SHA256 `6669a36b2362acfeb0fdd4706145e0402062c5136736aa583258e9a7d5c9f578`, verified 6089/6089 `SHA256SUMS` paths; `runtimeExecution=false`. R3 historical selector ordinals 239 and 250 had `A4_INVALID_FINAL_CELL_STATE` and are not claimed accepted.

The exact unchanged selected identities:

- `SurfaceCellsPhase10.ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`: source-adjacent isolation seam, full inverse certificate and source-sheet identity.
- `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`: combined planar, periodic and curved disk sheets, original per-sheet hard-feature boundaries.

Both previously invoked `build_surface_cell_network(mesh.V, mesh.F, crossField, targetSize, options)` with no independent source atlas. They now invoke the preexisting `build_phase10_with_source_atlas(mesh, crossField, targetSize, options)` which reconstructs source A2 topology and A3 transport before passing the original selected tracing cross field. This changes no expected output, production path, immutable test identity, selector, actual hard-feature topology or cross-field content. Historical final-cell-state defects may persist; the migrated ingress alone cannot prove semantic success.

## Verified source and build evidence

Exact source `9535719a9d0e796ec455b721a199f0d6551530ae`; Drive apply workflow `38115050210`, job `114398222197`, result artifact `11693252102` ZIP SHA256 `b9faa5d24e37e088f1313ceedf1370c054a92c16befcd0fad1bca909f96832b8`, log artifact `11693541117` ZIP SHA256 `50d58792f2f24cfd79946253aff6d92f09c736747db5a525009f85b55960e58b`. Single test source file changed (two existing fixture call sites, no test identity/selector/assertion/production edits). Original test mutations and expectations are untouched. Git patch SHA256 `f0975a04934ef595f1f701117543d608b3c097bf2da0fdfdc26c5ad9ee33fa5c`, header body hash `f43b77e63ab2070b08ddb232a769ee081ae93e7eefcfffe3a2e80fbf9140003d`, base `546637302d1890ea5928324ad7611bd03961c2ce`, backup `/Directional/Evidence/Directional_M6_CP3_R4_Phase10_Two_Composite_A3_Atlas_Recovery.patch`; consumed Drive patch owner-deleted.

Mandatory compile-only GMP/GMPXX: workflow `38115159602`, job `114398532401`, exact semantic source `9535719a9d0e796ec455b721a199f0d6551530ae`, eight targets, preflight/build exit `0/0`, generated link includes `gmpxx` and `gmp`, backend `GMP`, package checksums `28/28`, final source clean, `runtimeExecution=false`. Result artifact `11693471916` ZIP SHA256 `5777133eb4b189023450f9b1a6b2eb02355c177b5c1cf310ea142e025afd9853`, separate log artifact `11692992849` ZIP SHA256 `96557fd19e09e599106ae8556d4115a9ba1f98d3ed63912a228c13d78c9808b1`.


## Boundaries and remaining R4

Only source/static inspection and GitHub Actions compile were performed. No generated Directional tests/benchmarks, discovery, CLI, ctest or frozen 497-case suite executed. Runtime validation must occur in a separately authorized immutable Test + Benchmark turn, without weakening selectors or using the source patch as semantic acceptance. Remaining: 39 endpoint, 34 Phase10, seven DCEL fixtures, 88 CP2-accepted losses, source-valid multi-carrier odd-τ, six CP3 gates, and an independent architectural decision on dual-simple-path admissibility. Handoff remains R4; no successor is authorized.
