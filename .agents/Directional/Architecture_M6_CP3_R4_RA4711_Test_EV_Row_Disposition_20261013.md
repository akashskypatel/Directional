# M6-CP3 R4 — RA-47.11 test-only EV-row lookup disposition

**Scope:** Source-only census during the ongoing `M6-CP3-CB1-ENTRY-R4` Code + Build turn, not runtime evidence. Source authority: snapshot `b119a65bc0090f6e0517518bd2b95c66597d5620`; workflow [38336620819](https://github.com/akashskypatel/Directional/actions/runs/38336620819); artifact `11785262187`; 5,547/5,547 file checksums verified.

RA-47.11 and RA-50.7 require classifying six surviving textual occurrences of `source_edge_index` in `tests/FieldAlignedCurveNetworkTests.cpp` as legitimate EV-row queries or migrating them. There is one helper definition (line 159) and **five call sites**, all test-only. The helper accepts a typed `SourceEdgeTopologyKey` and returns a row of this mesh's DCEL `EV` matrix, or -1. It does not construct or publish `SurfaceCellRail::sourceEdges`.

| Line | Consumer | Classification |
|---|---|---|
| 612 | `mesh.EF(oppositeEdge, 1)` | Tests an interior opposite edge in a singular fan; needs a DCEL edge row |
| 1007 | `EXPECT_GE(source_edge_index(...), 0)` | Tests that a rail's typed edge occurs in the actual mesh |
| 1719 | `fixture.mesh.EF(edgeIndex, 1)` | Tests interior edge incidence when choosing an isolated cut |
| 5538 | `crossField.edgeTransitions[*].sourceEdge == edge` and `mesh.EF` | Looks up the fixture's EV-indexed transition diagnostics and incidence |
| 6366 | `mesh.EF(edgeRow, ...)` | Walks a source-vertex fan via actual DCEL face adjacency |

**Disposition:** all five call sites have legitimate DCEL EV-row semantics; no stale raw `SurfaceCellRail::sourceEdges` producer or consumer is present in this helper. No test migration or deletion is warranted: removing the adapter would remove a real incidence/topology check or require an equivalent replacement. RA-47.11's residual census is **accounted for**. This audit is not evidence that any test ran, and does not discharge RA-47.12 default-path liveness.

**Change boundary:** No production, test, build, frozen ABI, or selector changes are included in this report. A separate exact-base work-preservation patch prepared locally proposes only a two-line test-helper clarification plus TODO/handoff references. That patch has not been applied to GitHub and is not compile evidence. Do not describe it as landed.

**Carried gates:** RA-43.2 is discharged by RA-50 and the proposed oriented-side producer receipt is expressly refused. RA-43.1, global RA-43.4 legacy disposition, remaining RA-46.5 first-rejection coverage, RA-47.12 executed liveness, 39/34/7/88/six, and the true multi-carrier odd-τ witness require their separately authorized evidence. No TB497, Test + Benchmark execution or successor starts here. Ledger 66/17/49, debt 1; CP2 491/491 accepted; R3 403/497 rejected.

## Exact-source compile and cleanup closeout (2026-10-13 UTC)

- The three-file exact-base patch (`tests/FieldAlignedCurveNetworkTests.cpp`, `TODO.md`, `.agents/Directional/Future_Chat_Session_Handoff.md`) was applied through Drive dispatcher run [38337296844](https://github.com/akashskypatel/Directional/actions/runs/38337296844), exact base `b119a65bc0090f6e0517518bd2b95c66597d5620`, patch SHA-256 `c3287190319ecfeb709be632978f0f4a718fa5a7f1b5c31600eed0fe6e9f13e3`, semantic commit `9c659ae0c9aa260c728d96a13c23ce237d189b06`. GitHub confirmed the exact three intended paths; `runtimeExecution=false`. Owner-side Drive staging file `1q5af71DOkh8iCrzS3FA9UtcRpr2dMWNY` was permanently deleted after apply verification.
- Mandatory exact-source eight-target GMP/GMPXX **COMPILE GREEN**: [workflow 38337450995](https://github.com/akashskypatel/Directional/actions/runs/38337450995), immutable result artifact `11785289032`, outer ZIP SHA-256 `3049a8abbd04e2a99848bdb92835dd89230d266e1e546efa2732cec5930598be`. Independently verified **28/28** internal `SHA256SUMS`, all eight required target names, preflight/build exits `0/0`, generated linker includes both `libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`, five clean source-status records and `runtimeExecution=false`. No Directional binary/test/benchmark was executed; no runtime PASS is claimed.
- Mandatory turn-cleanup workflow [38337631510](https://github.com/akashskypatel/Directional/actions/runs/38337631510) **GREEN**, event `2d1aaab5c2a0f3737f1280b30cc4017fc83a7cdb`, cleanup commit `ddf3ada9573ed7019d6e87498bb8641d2ec725fa`, result artifact `11784939896` outer SHA-256 `439028528964090871d222035f9e187c5c157537c1ecfc31ceeffc55e99a0972`, verified removal of the sole snapshot-trigger temporary path and `runtimeExecution=false`.
- **Disposition:** this RA-47.11 Code + Build census/clarification checkpoint is compile-verified only. Canonical `M6-CP3-CB1-ENTRY-R4` remains **IN_PROGRESS** and its other authoritative gates stay open. Neither TB497 nor a successor turn is authorized.
