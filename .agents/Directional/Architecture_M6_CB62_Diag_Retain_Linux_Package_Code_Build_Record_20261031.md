# CB62 — DIAG-RETAIN Linux eight-target package (2026-10-31)

- **Turn:** `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE`; compile/package only, no source patch.
- **Semantic source:** CB61 `e1fd0e4b7560c4fa5bde96853b978d336c522e8f`; GitHub comparison to the frozen package source `e7c27b0a5f53788569109c85a028e3be44035aaf` confirms zero changes in `src/`, `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt`, `cmake/`.
- **Immutable source snapshot:** run `41181147222`, artifact `13035036695`, outer ZIP SHA-256 `f58920b1d9a0712736cda3c1585f4b77a616ffe469be9a1ae7a5baa29707dc51`; 6,037/6,037 packaged files verified, source tar SHA-256 `5d6a7dc01ca183486d772322be39f67693bb8bfc4575d370883bad1d746efc57`.
- **Linux compile:** [run 41181199445](https://github.com/akashskypatel/Directional/actions/runs/41181199445), job `124478834838`; `agent-operation-dispatcher.yml` → `agent-compile-reusable.yml`, Ubuntu 24.04, Release/static, GMP/GMPXX, eight approved targets.
- **Package:** artifact `13034987618`, outer ZIP SHA-256 `81c66418420b64c466e4b6c89d79129ef8ba4adbe6981469624d781644d91de5`, root SHA256SUMS SHA-256 `48d4bf626737980e2deb4f37c4b1bfee47a1644a06a034186198be70454d4870` (28 entries), source archive SHA-256 `88653f43f67cd413c38b63cbebed376dca78405de2c0c22dc21d4a0143a72fce`; all verified.
- **Boundary:** `runtimeExecution=false`, compile-only; no native tests, benchmarks, CLI or GUI execution. No source/test/benchmark/selector mutation. Stable 66/17/49, debt 1, CP2 491/491 last accepted; no acceptance promotion.
- **Next:** `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC`, immutable CB62 package, TB58 manifest 863 rows (`31c1360a...`), deferred ledger v4 82 rows (`36241caa...`), membership 945; pre-registered 863/863 PASS on Linux, then TB61-REV.
