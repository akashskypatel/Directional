# RA-244: edge-terminal equivalence decision (2026-11-17 UTC)

Canonical turn `M6-CP3-DEFN-P13-EDGE-TERMINAL-EQUIVALENCE-DECISION` (Review only). It accepts TB125, classifies every inventoried cut, names the stage that owns the correction, and freezes CB144 together with the TB126 manifest. No Directional binary was built or run; the source checks were `-fsyntax-only` only.

## 1. TB125 accepted (scoped MATCH)

I re-downloaded both TB125 artifacts:

| Artifact | ZIP SHA-256 | Hash check | Result |
|---|---|---|---|
| Census `14289927334` | `2f5a4b51…f8d6` | 9/9 OK | Cylinder PASS, BunnyRandom RED, Vase RED |
| Gate `14289730737` | `c1754245…061c8` | 1,908/1,908, 0 failures | 950/950 PASS |

- **Gate:** no gate log contains a `mandatoryEdgeTerminalInventory` line.
- **BunnyRandom inventory:** both lines are printed twice, once per pipeline attempt, and the two copies are identical. The terminal is still `MandatoryEdgeTerminalOrderUnresolved` at (241,251).

The inventory lines:

| Edge | Cut | Trace | Singularity | Node | t |
|---|---|---|---|---|---|
| (241,251) | 0 | 107 | 29 | 149 | 0.29728… |
| (241,251) | 1 | 38 | 9 | 178 | 0.69548… |
| (251,278) | 0 | 92 | 26 | 184 | 0.24658… |
| (251,278) | 1 | 41 | 10 | 162 | 0.26252… |

## 2. Classification

On both offending edges, every cut is a distinct trace from a distinct singularity, ending at a distinct node. Every edge has `distinctParameters == cuts`; the exact rational comparison decides that, not the printed decimals.

So there are no duplicate cuts and no incompatible cuts on either edge: all four are distinct cuts in a strict order. The two edges share vertex 251. That fits a dense crossing of a hard rail near a vertex, not a degenerate case.

## 3. Owner and rule

- **The owner is A2a′ (`build_arcs`, the cut graph).** A2a (tracing) correctly publishes one contact node per barrier termination (`SurfaceCellTracing.cpp:3895–3937`, `:4701–4736`). The one-cut limit lives entirely in A2a′. No change to tracing or the A3/A4 mesh is needed, and no validator is relaxed.
- **Rule for strictly ordered distinct cuts** (the observed class): N cuts give N + 1 mandatory pieces in exact parameter order.
  - Every piece keeps the original `mandatoryEdge` owner.
  - Pieces run from lower to higher parameter; each interval is positive, because `exact_edge_interval_path` rejects zero length.
  - Error reports keep the trace binding.
  - The existing one-cut and no-cut paths fall out as the N = 1 and N = 0 cases, with identical drafts and identical error fields.
- **Rule for equal parameters:** still rejected with `MandatoryEdgeTerminalOrderUnresolved`, even when the two cuts share one node. No instance exists, so there is nothing to decide. This is a typed rejection at the owning stage, so no user decision is opened.
- **Other failure kinds:** a cut node at an endpoint, or one node at two parameters, is rejected as `InvalidNetworkBinding`.

**Found by reading the consumers:** `edge_ray_points_to_second_endpoint` (`EmbeddedGraphTopology.cpp:1060`) gives a mandatory piece's direction only when its destination is one of the edge's endpoint nodes. For a middle piece between two terminals it returns nothing. The rotation step would then fail with `RotationEdgeRayEndpointDirectionUnavailable`, so the split alone would only move BunnyRandom's failure.
- Because every piece runs from low to high parameter, `Forward` always points toward the second endpoint.
- The new rule `orientation == Forward` agrees with the old one wherever the old one gave an answer: with zero or one cut, every piece touches an endpoint.

The other consumers already handle any number of pieces in edge order:
- `exterior_boundary_orbits` (`:2043`);
- plan validation `MandatoryEdgeNotOnAnyRegionBoundary` (`GlobalTopologyPlan.cpp:2909`);
- `mandatory_arc_indices` (`:439`);
- `edge_arc_schedule` (`SurfaceCellTracing.cpp:13838`), which requires `first < second`; the new pieces satisfy that.

## 4. CB144 frozen

**Patch:** `Architecture_M6_CP3_CB144_P13_Edge_Terminal_Ordered_Split_Exact.diff`.
- SHA-256 `081fcb5b96aff08824a661f985c40e3ab3304f3a6b218a1d14f1740df20de122`.
- 371 lines.
- Numstat: `88 63` `src/geometry/EmbeddedGraphTopology.cpp`; `38 0` `src/geometry/EmbeddedGraphTopology.h`; `119 0` `tests/FieldAlignedCurveNetworkTests.cpp`.

**Header:**
- `MandatoryEdgePiece {firstNode, secondNode, firstParameter, secondParameter, adjacentTrace}`.
- `MandatoryEdgeSplitFailureKind {TerminalAtEndpoint, EqualParameters, SharedNode}`.
- `MandatoryEdgeSplitFailure`.
- `split_mandatory_edge_at_terminals(firstNode, secondNode, cuts)`: sorts by exact parameter, using trace id to break ties, then checks the cuts and returns N + 1 chained pieces.

**Source:**
- `build_arcs` drops the blanket rejection of two or more cuts and runs every mandatory edge through the split.
  - `EqualParameters` maps to `MandatoryEdgeTerminalOrderUnresolved`, with the same fields as before (sourceEdge, trace, secondTrace).
  - The other failure kinds map to `InvalidNetworkBinding`, with the same fields as the old one-cut path.
  - The dead `size() != 1U` check is removed.
  - The RA-243 inventory line still prints.
- The direction helper uses the low-to-high rule.

**Test `MandatoryEdgeTerminalSplit.SplitsAtOrderedDistinctCutsAndRejectsAmbiguousOnes`** (gate row 951) checks:
- the 0-, 1- and 2-cut chains;
- out-of-order input, in the (241,251) shape;
- 1/3 and 1/3 + 2⁻⁶⁰, which round to the same double but form a three-piece chain;
- equal parameters, both on different nodes and on one node;
- a cut at an endpoint;
- a node shared at two parameters.

Each chain check covers end-to-end coverage of [0,1], `first < second` for every piece, continuity of nodes and parameters, and `adjacentTrace`. It fails if the implementation compares doubles, skips sorting, accepts equal or ambiguous cuts, or orients a piece backwards.

**Verification:**
- `git apply --check` passes at HEAD `027ab8b4d`.
- The precheck `git diff --quiet 6857c66b788841f8e400151b6068b2f23be25167 HEAD -- src include tests` passes.
- `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` returns 0 on both changed files. Warnings are identical to HEAD: 22 for the source and 42 for the test.
- The other files that include the header, `GlobalTopologyPlan.cpp` and `SurfaceCutGraph.cpp`, return 0.

**Routes:**
- CB144 mismatch → `M6-CP3-PLAN-P13-EDGE-TERMINAL-OWNER-CORRECTION-STOP`.
- CB144 infrastructure failure → `M6-CP3-CB144A-P13-EDGE-TERMINAL-OWNER-CORRECTION-ORCH`.

## 5. TB126 frozen

**Gate manifest:** `gates/Architecture_M6_TB126_P13_Edge_Terminal_Ordered_Split_Full_Gate_Case_Manifest.tsv`, SHA-256 `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`. It is the TB125 manifest byte for byte, plus row 951. Self-check: `SELF_CHECK_PASS cases=951 deferred=81`; membership 1,032. **Census:** `3af1dc0d…`.

**MATCH requires all of the following:**
- 951/951 PASS, 0 skipped.
- Rows 1–950 have the same ledger fields as TB125. The raw logs may vary only by elapsed time and the known `M3_CP4AB_FRAGMENT_DIAG` interleaving.
- No gate row has a multi-cut edge, so the only behavior change is unreachable in the gate.
- No inventory line appears in the gate.
- Cylinder PASS and Vase RED, both with receipts identical to TB125.
- BunnyRandom:
  - its inventory lines are identical to TB125;
  - every receipt line before the cut graph (edge ports, `vertexOutflowFollow`) is identical to TB125;
  - its terminal is not `MandatoryEdgeTerminalOrderUnresolved`;
  - its terminal is not `InvalidNetworkBinding` or `RotationEdgeRayEndpointDirectionUnavailable` at (241,251) or (251,278).

**Prediction (record it; it does not decide MATCH):** BunnyRandom's new first terminal (stage, code, locus), or PASS with its counts.

**Routes:**
- TB126 mismatch → `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV`.
- TB126 infrastructure failure → `M6-CP3-TB126A-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-ORCH`.
- TB126 MATCH → Review-only `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME`.

## 6. Turn sequence

| # | Turn | Owner | Status |
|---|---|---|---|
| 1 | `M6-CP3-TB125-P13-EDGE-TERMINAL-EXACT-INVENTORY-EXEC` | Test + Benchmark | COMPLETE, accepted here |
| 2 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-EQUIVALENCE-DECISION` (RA-244) | Review | COMPLETE |
| 3 | `M6-CP3-CB144-P13-EDGE-TERMINAL-OWNER-CORRECTION` | Code + Build (compile only, exact diff) | NEXT |
| 4 | `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-EXEC` | Test + Benchmark (artifact only) | then |
| 5 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Review | then |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | Code + Build, then TB and Review | after 5 |

## 7. Carried and gaps

- **Carried:**
  - Open: O42, O43, C3 (C3 is a non-stable P13-e candidate until TB126).
  - Closed: O44 and C1.
  - Decisions: D11 = A, D12 = A, D10 deferred, D6 pending.
  - Counts: stable 66/17/49, debt 1, deferred 81; CP2 491/491.
  - CP3/selector497 unpromoted; `chainRimSchedules=false`.
  - DESIGN.md unchanged: no contract changes, since the split realizes the existing "N + 1 sub-intervals" requirement.
- **Gaps:**
  - Row 951 has not been run.
  - No unit test drives the direction change through the rotation step; it relies on the pieces running low to high, which row 951 checks. BunnyRandom is the first runtime case.
  - Code after the cut graph has never seen a multi-cut mandatory edge, so the next terminal may sit there.
