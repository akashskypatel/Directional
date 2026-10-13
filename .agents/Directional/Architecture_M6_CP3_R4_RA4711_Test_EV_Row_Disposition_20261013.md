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
