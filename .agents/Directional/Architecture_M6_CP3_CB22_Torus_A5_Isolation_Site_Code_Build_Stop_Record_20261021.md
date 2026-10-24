# CB22 — compile stop (2026-10-21)

- Turn: `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE`, Code + Build, RA-117.5.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft/open.
- Exact verified snapshot base: `49c982195327d86cb5a1ef64e934bd95507147de` (snapshot run `39563091173`, artifact `12328577632`, 5,725/5,725 file hashes).
- Submitted semantic source: `384961bb4ac292e99bf41681117bf8d1d4e9d520` ([commit](https://github.com/akashskypatel/Directional/commit/384961bb4ac292e99bf41681117bf8d1d4e9d520)).
- Exactly three source files changed: `include/directional/pipeline/RemeshPipeline.h`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellTransitionQuotientTests.cpp`. Fixture atlas line and diagnostic-only isolation-site additions; 122 inserted lines total. No other tests or A5 decision change intended.
- Patch SHA-256 `9d3ddfbf49269fe5da3e92970b4b010f947ab8a46aead853faee2caf630bb4bd`, diff-body `fc897f7c2ab2440b9429b066c5b4259b4a26685d8e821cc069fdbccf5500fe2a`; `git diff --check` and `git apply --check` passed against frozen snapshot.
- Drive apply run `39563834213` succeeded; result artifact `12328133775`; staged Google Drive file was permanently deleted by owner-authorized connector after successful push.
- **Compile RED:** run [39564087707](https://github.com/akashskypatel/Directional/actions/runs/39564087707), exact source `384961bb4ac292e99bf41681117bf8d1d4e9d520`. Schema/parse jobs passed; `compile / compile` failed; diagnostic log artifact `12329047110`; no successful compile package.
- Compiler: `src/pipeline/RemeshPipeline.cpp:5274–5275`, `directional::authority::OccurrenceId` has **no member `index`**; both `relationId.first.index()` and `relationId.second.index()` are invalid. `directional_pipeline` compilation failed, Ninja stopped, `compile_status=1`.
- No runtime, tests or benchmarks were executed. GMP compile environment was enabled; eight-target completion and link verification were **not attained**. No correctness or acceptance promotion.
- **Stop per RA-117.5:** no in-turn fix or compile retry for a deterministic C++ source defect. Independent Review must determine the type-correct occurrence identity formatter, verify diagnostic-only no-decision-change scope, and authorize a corrective Code + Build turn. CB22 not complete.
- Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB21 candidate 449/497; `RP-01` open, `RP-02` UNREACHED.
