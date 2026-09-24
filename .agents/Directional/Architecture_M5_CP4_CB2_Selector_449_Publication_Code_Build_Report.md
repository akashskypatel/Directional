# M5-CP4-CB2 selector449 publication Code + Build report

**Turn:** `M5-CP4-CB2`
**Boundary:** exact selector/routing publication plus compile/package only; no Directional runtime
**Disposition:** **COMPLETE / EXACT PUBLICATION GREEN / EIGHT-TARGET GMP COMPILE+PACKAGE GREEN / RUNTIME-FREE**

## 1. Exact publication

The turn published only the precommitted selector449 and routing449 semantic files. No C++ source, test source, fixture, field, benchmark input, CMake ownership, accepted earlier selector, or earlier routing bytes changed.

- publication source commit: `e284fea7c101eb86650d1c87c92d0fefa66050e7`;
- selector449: `.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`;
- selector449 SHA-256: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- selector449 row count: **449**; rows1-448 are byte-identical to selector448 SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- row449: `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`;
- routing449: `.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv`;
- routing449 SHA-256: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- routing rows1-448 are byte-identical to routing448 SHA-256 `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`;
- row449 owner: `directional_surface_cell_producer_tests`;
- exact static owner census: **32 authority-kernel / 301 producer / 75 completion / 41 validation**.

The exact publication transport was checksum-pinned. Apply run `36013633517` succeeded and pushed `e284fea7c101eb86650d1c87c92d0fefa66050e7`; its workload recorded `runtimeExecution=false`.

## 2. Compile/package authority

The compile caller used `.github/workflows/agent-compile-reusable.yml` with **no `targets` override**, so all eight durable defaults were built from exact source `e284fea7c101eb86650d1c87c92d0fefa66050e7`:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Compile run/job: **`36013904054 / 107681435506`**, conclusion **success**. Result/log artifacts: **`10814505512 / 10814141518`**. The result artifact provider ZIP SHA-256 is `047c3a1d7b3d5b09fe97961442237742e3dc9fac0939ca20c1dffb86b2959aae`.

The package has a self-excluding recursive `SHA256SUMS` with **28/28 payload entries verified**. Packaged source archive `source-e284fea7c101eb86650d1c87c92d0fefa66050e7.tar.gz` SHA-256 is `92af40d8be93f77a44e0a396173c4965a801367bde1424318609b1826931f315`. All five source-status receipts are empty/clean.

## 3. Exact arithmetic and command boundary

Configuration found mandatory GMP/GMPXX under `/usr`; packaged linkage evidence names both:

- `/usr/lib/x86_64-linux-gnu/libgmpxx.so`
- `/usr/lib/x86_64-linux-gnu/libgmp.so`

`metadata/command-boundary.txt` records:

- `runtimeExecution=false`;
- `turnBoundary=Code+Build-only`;
- `exactArithmeticBackend=GMP`;
- `preflightCompile=true`;
- `semanticContracts=compiled-not-executed`.

No generated Directional binary, GTest discovery/listing, `ctest`, benchmark, CLI/help/version command, or custom runtime input was executed in this turn.

## 4. Independent post-package verification

The downloaded result artifact was verified outside the build job:

- recursive manifest: **PASS**;
- packaged source commit: `e284fea7c101eb86650d1c87c92d0fefa66050e7`;
- packaged selector449 SHA-256: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- packaged routing449 SHA-256: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- packaged selector448/routing448 hashes: `70ff0860...c75789 / c91a5e2f...11dd7c`;
- exact selector/routing prefix checks: **PASS**;
- row449 identity/owner: **PASS**;
- owner census: **32/301/75/41**;
- all six generated executables are present and executable; core/pipeline static libraries are present;
- GMP/GMPXX evidence: **PASS**;
- compile exit: **0**; preflight exit: **0**;
- runtime execution: **false**.

## 5. Process-only orchestration observations

Two failed control-plane attempts produced no semantic or runtime evidence and changed no Directional product semantics:

1. `M5-CP4-CB2-OBS-01` — the first Drive preservation patch omitted the reusable workflow's required `intended_paths` metadata. Run `36013112294` failed during download/manifest verification before apply/commit/push. The patch was corrected and re-hashed before retry.
2. `M5-CP4-CB2-OBS-02` — corrected run `36013512299` verified and locally applied the exact patch, but GitHub rejected its push with an HTTP/Internal Server Error. The exact unchanged patch was retried; `36013633517` succeeded. No Directional runtime executed in either attempt.

Both are **process-only / non-stable / +0**. Stable accounting remains **51 / 14 / 37** and project debt remains **1, M6-owned**.

## 6. Authority and successor

Selector449 is now **published**, but this Code + Build turn does not accept it as M5 runtime authority. Accepted M5 runtime authority remains selector448/package `10771899191 / cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1` until fresh artifact-only TB2 and mandatory Review.

Exact successor: **`M5-CP4-TB2-EXEC`**. It must consume artifact `10814505512` immutably, execute the published selector449 as 449 fresh exact-filter processes across the four owner executables, and then route to `M5-CP4-TB2-REV`. Only that final Review may accept conjunct8, promote the package, and close M5.

## 7. Tool-call ledger

The exact start-of-turn tool-call counter was lost across context compaction. Per conservation policy it was **not reconstructed with extra tool calls**; therefore the turn records the ledger as **partial/unknown after compaction** rather than inventing a total.
