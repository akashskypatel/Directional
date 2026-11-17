# RA-243: edge-terminal inventory Review (2026-11-17 UTC)

Canonical turn `M6-CP3-DEFN-P13-EDGE-TERMINAL-INVENTORY` (Review only). It does two things: accepts TB124, and freezes CB143 together with the TB125 manifest. No Directional binary was built or run. The source checks were `-fsyntax-only` only.

## 1. TB124 accepted (scoped MATCH)

I re-downloaded the result artifact `14283755675`. Its ZIP SHA-256 is `016b9528c330d60a3202d8594d0d6f37b6c0eb76415cab2f0c93ecc965d30d42`, which matches the report, and the TB122 baseline artifact `14216937463` was downloaded alongside it.

- **SHA256SUMS:** 1,906/1,906 entries are OK, with 0 failures.
- **Ledger:** 949 rows, all PASS.
- **Ledger diff against TB122:** I compared every field except elapsed time and log hash. Exactly 5 fields differ, all in row 949: verdict, exit, passed, first_failure and typed_reason. That is the TB122 RED turning into a PASS. Rows 1–948 are unchanged.
- **Raw logs:** with elapsed times normalized, 944/948 inherited logs are byte-identical. Rows 164, 176, 190 and 195 differ only in the order and line joining of `M3_CP4AB_FRAGMENT_DIAG` records. In each of the four, the multiset of records (split at each marker) is equal.

**Cause of the four reordered logs.** The cause is now identified; the TB124 report had left it open.
- These records are written to `std::cerr` (`GlobalTopologyPlan.cpp:1883–1991`) as two separate insertions, `out.str()` and then `'\n'`.
- The affected rows run `RemeshPipeline`, which processes components in parallel with `std::async` (`RemeshPipeline.cpp:17726`). Row 195, for example, is `SecondComponentAuthorityFailurePublishesNoSemanticAggregateContext`.
- When two workers write at the same time, their records can interleave or join on one line. TB122 shows the same effect: row 190 has a joined line there, and row 195 has one in TB124.

This is concurrent diagnostic output, not product nondeterminism, because the values are identical. It is not a stable event. I did not open a fix item: the order of diagnostic prints is not a contract, and these rows' verdicts never depend on it.

**What closes:**
- C1, the cross-face oracle, closes.
- The scoped D12 follow contract is accepted at helper level (row 949 on CI) and by the TB122 BunnyRandom receipts (Slide at vertex 48, Cross at vertex 349).
- O44 was already closed by RA-242.

## 2. Findings on the next blocker (C3)

- **F1. The rejection has never been tested.** No test, fixture or gate row reaches `MandatoryEdgeTerminalOrderUnresolved`. Searching `src include tests` finds only the code that raises it (`EmbeddedGraphTopology.cpp:483–491`) and the code that prints its name (`GlobalTopologyPlan.cpp:3175`). BunnyRandom is the only producer that reaches it.
- **F2. The validator hides every offending edge after the first.** `build_arcs` returns on the first edge with two or more cuts, in `SourceEdgeTopologyKey` map order. The census shows (241,251) only because it sorts first among the offending edges, so the number of such edges on BunnyRandom is unknown (lesson RA-210).
- **F3. The cut data already exists in `build_arcs`.** For each cut it has the trace, the node and an exact `ExactUnitParameter`, the same rational used by the exactly-one split at `:494–558`. No new producer data is needed, only the order and equality of what is already there.
- **F4. Use exact comparisons only.** Rounded parameters cannot be used to decide whether two cuts coincide: two cuts a rounding unit apart would look equal. Equality and order must use `FieldExactRational`; the printed `t` value is for reading only (lesson RA-226).
- **F5. The arc builder is fine as it stands.** The existing `cuts->second.size() != 1U` branch at `:518` cannot be reached once the rejection runs first. CB144 changes both together, so CB143 leaves both untouched.

## 3. CB143 frozen: exact inventory, no behavior change

**Patch:** `Architecture_M6_CP3_CB143_P13_Edge_Terminal_Exact_Inventory_Exact.diff`.
- SHA-256 `c0439b1f303827d2f9584373bf7a8515df771649ff9ab4c04ab9b1d1cc29205b`.
- 223 lines.
- Numstat: `75 8` `src/geometry/EmbeddedGraphTopology.cpp`; `27 0` `src/geometry/EmbeddedGraphTopology.h`; `63 0` `tests/FieldAlignedCurveNetworkTests.cpp`.

**Header changes:**
- `MandatoryEdgeTerminalCut {trace, node, parameter}` replaces the private `TerminalBarrierCut` struct inside `build_arcs`. Its fields are the same.
- `MandatoryEdgeTerminalInventory {sourceEdge, cuts, orderClass, distinctParameters, equalParametersShareNode}`.
- `inventory_mandatory_edge_terminals(cutsByEdge)` returns one inventory for each edge with two or more cuts:
  - cuts sorted by exact parameter, with trace id breaking ties;
  - `orderClass` numbers the distinct parameters along the edge, so equal parameters share a class;
  - `equalParametersShareNode` is false when two equal-parameter cuts bind different nodes.

**Source changes:**
- `build_arcs` prints one `SurfaceCutGraph.mandatoryEdgeTerminalInventory` line per inventoried edge to `std::clog`, before the existing rejection loop. The fields are `edge=(a,b) cuts= distinctParameters= equalParametersShareNode=`, followed by one `cutN=[trace= singularity= node= class= t=]` per cut.
- The rejection loop, its error fields and the arc builder are unchanged.

**Test `MandatoryEdgeTerminalInventory.OrdersCutsExactlyAndClassesEqualParameters`** (gate row 950, `directional_surface_cell_producer_tests`) uses four hand-built edges:
- one cut: not inventoried;
- three cuts at 3/4, 1/4, 3/4: order 7, 2, 5 (trace-id tie-break), classes {0,1,1}, distinct 2, nodes shared;
- two cuts at 1/2 with different nodes: classes {0,0}, `equalParametersShareNode=false`;
- 1/3 and 1/3 + 2⁻⁶⁰: the test asserts that both round to the same double, then requires two distinct classes in exact order.

The test fails if the implementation compares parameters as doubles, sorts by trace before parameter, includes single-cut edges or ignores node identity.

**Verification:**
- `git apply --check` passes at HEAD `3e30af990`.
- The precheck `git diff --quiet 57b28b737fd92b083d24d882152dea186211f735 HEAD -- src include tests` passes.
- `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` returns 0 on the patched `EmbeddedGraphTopology.cpp` (22 warnings, the same set as HEAD) and on `FieldAlignedCurveNetworkTests.cpp` (42 warnings, the same set as HEAD).
- The other files that include the header, `GlobalTopologyPlan.cpp` and `SurfaceCutGraph.cpp`, return 0 with no errors.
- The test has not been run.

**Routes:**
- CB143 mismatch → `M6-CP3-PLAN-P13-EDGE-TERMINAL-EXACT-INVENTORY-STOP`.
- CB143 infrastructure failure → `M6-CP3-CB143A-P13-EDGE-TERMINAL-EXACT-INVENTORY-ORCH`.

## 4. TB125 frozen

**Package:** the CB143 package. **Gate manifest:** `gates/Architecture_M6_TB125_P13_Edge_Terminal_Exact_Inventory_Full_Gate_Case_Manifest.tsv`, SHA-256 `9a112bd18c4f37248ae8c9fc2c942f9fd19cd67ca4a5236c13f5ed76f95a0290`. It is the TB122/TB124 manifest byte for byte, plus row 950. Self-check: `SELF_CHECK_PASS cases=950 deferred=81`; membership 1,031. **Census:** `gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` (`3af1dc0d…`, 3 rows).

**MATCH requires all of the following:**
- 950/950 PASS, 0 skipped.
- Rows 1–949 have the same ledger fields as TB124. The raw logs may vary only by elapsed time and the known `M3_CP4AB_FRAGMENT_DIAG` interleaving.
- No `mandatoryEdgeTerminalInventory` line appears in the gate (prediction P1).
- Cylinder PASS and Vase RED, both with unchanged terminals, receipts identical to TB122, and no inventory line (P2).
- BunnyRandom keeps its terminal: `MandatoryEdgeTerminalOrderUnresolved`, edge (241,251). Every receipt line from TB122 is unchanged, and at least one inventory line appears, including (241,251) (P3).

**Predictions (record them; they do not decide MATCH):**
- P4: the number of inventoried edges on BunnyRandom.
- P5: whether any edge has `distinctParameters < cuts`.

  If every class is distinct, CB144 is the N+1 sub-arc split. If any parameters are equal, the equivalence Review must decide what that means before CB144.

**Routes:**
- TB125 mismatch → `M6-CP3-TB125-P13-EDGE-TERMINAL-EXACT-INVENTORY-REV`.
- TB125 infrastructure failure → `M6-CP3-TB125A-P13-EDGE-TERMINAL-EXACT-INVENTORY-ORCH`.
- TB125 MATCH → Review-only `M6-CP3-DEFN-P13-EDGE-TERMINAL-EQUIVALENCE-DECISION`.

## 5. Turn sequence

| # | Turn | Owner | Status |
|---|---|---|---|
| 1 | `M6-CP3-TB124-P13-CORRECTED-FULL-GATE-EXEC` | Test + Benchmark | COMPLETE, accepted here |
| 2 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-INVENTORY` (RA-243) | Review | COMPLETE |
| 3 | `M6-CP3-CB143-P13-EDGE-TERMINAL-EXACT-INVENTORY` | Code + Build (compile only, exact diff) | NEXT |
| 4 | `M6-CP3-TB125-P13-EDGE-TERMINAL-EXACT-INVENTORY-EXEC` | Test + Benchmark (artifact only) | then |
| 5 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-EQUIVALENCE-DECISION` | Review (freezes CB144) | then |
| 6 | `M6-CP3-CB144-P13-EDGE-TERMINAL-OWNER-CORRECTION` | Code + Build | then |
| 7 | `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-EXEC` | Test + Benchmark | then |
| 8 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Review | then |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | Code + Build, then TB and Review | after 8 |

## 6. Carried and gaps

- **Carried:**
  - Open: O42, O43, C3 (C3 is a non-stable P13-e candidate).
  - Closed: O44 and C1.
  - Decisions: D11 = A, D12 = A, D10 deferred, D6 pending.
  - Counts: stable 66/17/49, debt 1, deferred 81; CP2 491/491.
  - CP3/selector497 unpromoted; `chainRimSchedules=false`.
  - DESIGN.md unchanged.
- **Gaps:**
  - Row 950 has not been run.
  - The inventory printer is exercised only by the census.
  - CB143 does not show where the cuts come from (trace geometry).
  - Equal-parameter cuts that bind different nodes stay rejected. CB143 does not decide them.
