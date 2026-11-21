# CB168N — source-piece counts field Code + Build record (2026-11-20 UTC)

Turn: `M6-CP3-CB168N-P13-SOURCE-PIECE-COUNTS-FIELD`. **Compile-only PASS; no runtime tests or benchmarks executed.**

- Frozen exact diff `.agents/Directional/Architecture_M6_CP3_CB168N_P13_Source_Piece_Counts_Field_Exact.diff`, SHA-256 `eddf8000ad40251a3b8a60b3d197229f8f8b5406b2789998e9c3d96ce4e37dc2`.
- CB168M source `0d925e4e5e8324a51ebcd2728bde43015ee38ccd`; exact snapshot `5985a4cf51577e7e1b9b72765d1eb7e55680e4a9`, [run 44708183807](https://github.com/akashskypatel/Directional/actions/runs/44708183807), artifact `14616037282`: 5,639/5,639 hashes and outer ZIP digest verified.
- `git apply --check`, `git diff --check` and exact four-path diff passed; [apply run 44708907358](https://github.com/akashskypatel/Directional/actions/runs/44708907358) committed exact source `2d587a2e7ec00b7dc8d0a24df9f6902f03fec931`; no other code, fixture, selector or workflow changes.
- Exact diff changes: `6 0` GlobalTopologyPlan.h; `5 1` EmbeddedGraphTopology.cpp; `7 13` GlobalTopologyPlan.cpp; `91 0` FieldAlignedCurveNetworkTests.cpp.
- GMP/GMPXX eight-target [compile run 44711983065](https://github.com/akashskypatel/Directional/actions/runs/44711983065): **SUCCESS**, immutable package artifact `14618335833`, ZIP SHA-256 `fca8a9fcc4166e708e82933d84d4aacc02b73ef5306f3ac40154baa2d4a97bde`; 28/28 internal checksums; `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- Added `sourcePieceCounts` to graph arcs and drafts, populated one count per face chord, and validated exact segment-to-piece binding with the previously compiled helper. Mandatory/cut arcs require empty counts. No path, digest or producer-cutover behavior changed.
- Row 966 independently checks one-count production, invalid count shapes, mandatory/cut rejection and structurally valid two-piece binding rejected by authoritative replay. **Compile-valid only, not runtime verified.**
- TB150 remains the latest runtime authority: 964/964, 963/963 prior MATCH; CP2 491/491; census 3/3 MATCH. Stable 66/17/49, one witness debt, 81 deferred; no CP3/selector497/D0 promotion.
- **Authorized successor, not executed:** `M6-CP3-TB151-P13-SOURCE-PIECE-COUNTS-FULL-GATE-EXEC`. Exact manifest SHA-256 `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da`.
