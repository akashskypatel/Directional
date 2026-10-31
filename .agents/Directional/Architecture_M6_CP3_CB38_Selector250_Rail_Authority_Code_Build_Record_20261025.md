# M6-CP3-CB38 — selector 250 hard-rail authority (Code + Build)

- **Scope:** single test body `SurfaceCellsPhase10Tests.cpp`, `PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; no production, selector, harness, workflow or existing assertion changed.
- **Authority:** RA-156.3; test fixture owns absent combined-disk rail authority and complete provenance.
- **Exact source commit:** `41f39ba920eace2dad7b36d2b26c8073ce740239`; one file, 50 added lines, zero removed.
- **Exact hunk:** `@@ -3660,6 +3660,56 @@ TEST(SurfaceCellsPhase10, PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets)`; `index 6087021c7b011a18828684adffef8b8e80bf6b0f..e836d3bd257daae0cf50b4ef7d6fee7555566ec7`.
- **Hunk evidence:** [GitHub source](https://github.com/akashskypatel/Directional/commit/41f39ba920eace2dad7b36d2b26c8073ce740239); preserved full-index diff-body SHA-256 `1c6e8167d6352b7327cb66bb45e4cd459fcc0b9e94f5e6eab316c293f3c95c7c`.
- **Producer:** one `AdaptiveFeatureMap` closed Hard boundary ring `{0,1,2,5,8,7,6,3,0}+diskOffset`, `component=2`, exactly one combined-source incident face per edge.
- **Authority transfer:** `build_authoritative_surface_cell_rails`, exactly one closed rail; `hard_rail_source_provenance_from_rails` copies terminal contacts, closed chains and open chains; exact hard edge-key equality required.
- **Patch apply:** [run 40231983472](https://github.com/akashskypatel/Directional/actions/runs/40231983472); full patch `3e822d95ecfb5e40795ce9cea19ad7e1480ee7f8c616f608028f273b799021bb`; successful immutable result; retired both consumed Drive staging files.
- **Compile-only:** [run 40232132945](https://github.com/akashskypatel/Directional/actions/runs/40232132945), artifact `12613073521`, package SHA-256 `ca7358b7de3ff7ce5bc234f69c2b06036a7a5681f96d9a2d6c9e7cd298797ab3`.
- **Verification:** 28/28 internal SHA256SUMS, eight required targets, `DIRECTIONAL_ENABLE_GMP=ON`, gmpxx+gmp on authoritative link, preflight=0/build=0, clean final source.
- **Runtime boundary:** `runtimeExecution=false`; no generated test/benchmark binary executed; selector 250 remains runtime-unmeasured after this edit.
- **Successor:** `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY-REV`; independent static review must recheck exact hunk and package, then freeze TB40 manifest under RA-156.4. Do not run TB40 in CB38.
- **Frozen authority:** CP2 accepted 491/491; TB38 candidate 490/504; TB32 candidate 481/500; stable 66/17/49 debt1, selector497 frozen, RP-01 open.
