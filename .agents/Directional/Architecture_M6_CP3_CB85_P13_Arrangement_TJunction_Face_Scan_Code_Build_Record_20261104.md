# CB85 arrangement T-junction source-face scan — Code + Build (2026-11-04)

- **Turn:** `M6-CP3-CB85-P13-ARRANGEMENT-TJUNCTION-FACE-SCAN` (RA-202.4, DESIGN Amendment 34); **Code + Build only**.
- **Precheck:** no source/test/build files changed since CB83 source `2278b8b649b4262fb70a522371ed282655383af5` before application; exact 178-line frozen diff SHA-256 `5b6d35a4808393d7274d8f574fa4f68eb343946bc3b065f2c1e8992babcac2f7`.
- **Semantic commit:** [`a405b59057045b5aaa302abd9553daba3d8b2934`](https://github.com/akashskypatel/Directional/commit/a405b59057045b5aaa302abd9553daba3d8b2934); only `SurfaceArrangement.h` (+3), `SurfaceArrangement.cpp` (+25/-11), `SurfaceArrangementRowIdentityTests.cpp` (+96); result SHA-256 `3e13e5cb…`, `6fa5c6c6…`, `d3290d04…` respectively, all exact.
- **Behavior:** face-indexed geometric T-junction halfedge scan, scope once per occurrence, deterministic visit-count diagnostic. GUARD row 894 added in test source; **not executed** in this turn.
- **Linux Release/static GMP/GMPXX compile:** [run 41856637027](https://github.com/akashskypatel/Directional/actions/runs/41856637027), eight required targets, build/preflight successful; `DIRECTIONAL_ENABLE_GMP=ON`, generated GMPXX/GMP link evidence; `runtimeExecution=false`.
- **Immutable package:** artifact `13338458053`, ZIP SHA-256 `a820389f1387b05d1d0b879db00ef085768c680d0093be2b5adc5607d9ee3f55`, internal manifest checked; compile log artifact `13338517975`.
- **No runtime testing, benchmarks, or source-grid recovery.** Compile is not semantic acceptance; latest TB76 893/893 gate and Vase ABNORMAL remain unchanged. CP2 491/491, stable 66/17/49, debt 1; selector497 and CP3 remain unpromoted.
- **Next separate authorized turn:** `M6-CP3-CB86-P13-SELECTION-ENDPOINT-NET-CHANGE` (RA-202.5; exact diff `c2a0c308…`, compile-only). Do not start CB86 in this turn.
