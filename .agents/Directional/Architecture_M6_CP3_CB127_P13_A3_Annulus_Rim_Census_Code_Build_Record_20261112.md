# CB127 annulus rim census — code and build record

- **Turn:** `M6-CP3-CB127-P13-A3-ANNULUS-RIM-CENSUS` (64D.1). Code + Build only, no runtime.
- **Authority:** RA-227 annulus plan-consumption Review. Applied exactly the frozen [test-only diff](Architecture_M6_CP3_CB127_P13_A3_Annulus_Rim_Census_Exact.diff), SHA-256 `d796c60dd0fa83c57194f89e9e97c949888d3a0e081a11ec1e7badb320a1d7da` (110 lines; 99 insertions, zero deletions).
- **Changed source:** Only `tests/SurfaceCellDesignAcceptanceTests.cpp`. Three `annulus-rim` census lines per case describe rim edge schedules and output. No production changes.
- **Applied source:** `39e91beb507468777aa90ffd83e23c146652d3ca`. [Drive apply run 43132705006](https://github.com/akashskypatel/Directional/actions/runs/43132705006), artifact `13905109288`, ZIP SHA-256 `bef19b1d321196c5facf7f9fb5f23ab90bc2856f627799352ddaccbc8b41674e`, runtime disabled. External staged patch removed after successful push.
- **Compile:** [Run 43133009660](https://github.com/akashskypatel/Directional/actions/runs/43133009660), [artifact 13905818229](https://github.com/akashskypatel/Directional/actions/runs/43133009660/artifacts/13905818229), ZIP SHA-256 `3d9feda87b4a42ae6adc5f31a75164777a4d8ec0e9442b07304ac4a968fac15e`; 28/28 packaged checksums verified, successful build, clean exact source `39e91beb507468777aa90ffd83e23c146652d3ca`.
- **Eight compiled targets:** `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- **Exact arithmetic:** `exactArithmeticBackend=GMP`; both `libgmpxx.so` and `libgmp.so` present on generated link command.
- **Boundary:** `runtimeExecution=false`; `turnBoundary=Code+Build-only`. No tests, benchmarks, source-grid recovery, selector edit, O36 wiring or CP3 promotion.
- **Inherited state:** TB107 943/943 scoped MATCH; census 1 PASS / 2 registered RED. CP2 491/491 accepted, stable 66/17/49, debt 1, deferred 81 unchanged.
- **Next separate turn:** `M6-CP3-TB108-P13-A3-ANNULUS-RIM-CENSUS-FULL-GATE-EXEC` (artifact-only Test + Benchmark), exact 943-row manifest and RA-227 receipt conditions. Not started by CB127.
