# M6-CP3-CB1-ENTRY-R4 — raw source-edge index bounds regression

**Canonical turn:** M6-CP3-CB1-ENTRY-R4 (still open; no successor work).
**Mode:** Code + Build only; runtime-free.

- Exact verified source snapshot: workflow `38218473160`, source `9e723070b5e677cb045e1e3f6502a14e12fbb0a9`, manifest 6411/6411.
- Surgical amendment: existing `FieldAlignedCurveNetwork.RejectsMissingDuplicateOrForeignMandatoryEdges` additionally rejects a raw source-edge index equal to `mesh.EV.rows()` while preserving authentic typed endpoint values and the expected `InvalidRailGeometry` error. No production source, frozen selector, test identity, or runtime oracle changed.
- Source patch: `Directional__M6-CP3-CB1-ENTRY-R4__base-9e723070b5e6__work-preservation.patch`, SHA-256 `9d1429ffa014923a93a8349e4699922c507d365d08177ba4d86aa93c46a9704f`, diff-body SHA-256 `da1e853cb9babce3b136a58699ae17d8f46fba2e47d05bb167180550a24bcff5`; exact local diff, reverse-apply and staged-apply checks passed.
- Drive application: dispatcher run `38219398469`, success; verified result ZIP artifact `11732917742`, SHA-256 `879b30723bb09afbf8f9cf97c19656a7d7b7a7f09cd4fea3a19f82edbf5f0bb3`, semantic source `e6797440ff7ac5f312d9c4b2f3ab0c64383f4b63`. Temporary Drive file permanently deleted by owner; snapshot trigger retired.
- Mandatory eight-target GMP/GMPXX compile **GREEN**, exact source `e6797440ff7ac5f312d9c4b2f3ab0c64383f4b63`: dispatcher event `8083189b1ea1c7254ad1448e41ea4b7434b92f44`, workflow `38219523638`, compile job `114712231901`, artifact `11732669850`, outer ZIP SHA-256 `5516e84ea8c05ce5e0c7e429891bc71041533bea1c7736ca9c515ebbd5884b84`; package 28/28 SHA256SUMS checks, preflight/build exit 0/0, all eight named targets, actual generated link uses `libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`. Diagnostic artifact `11733254732` SHA-256 `d4ca1e0ba7ed0405af524b365dafe04a500411a3c92fa736a756f991f7ec24ef`.
- No generated Directional executable, test, benchmark, discovery, frozen TB497, or runtime oracle was executed. The new assertion has no PASS credit before separately authorized Test + Benchmark.
- Continue the same R4 turn. Do not start TB497. Overfull-A3 independent Review, RA-43.4, original 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 / six CP3, and real odd-tau/multi-carrier obligations remain open.
