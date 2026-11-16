# RA-241 — P13-e edge-transit seed conformance outcome: D12 = A, carrier seed and outflow follow frozen (2026-11-16 UTC)

**Turn:** `M6-CP3-DEFN-P13-EDGE-TRANSIT-SEED-CONFORMANCE-OUTCOME` (Review only, P13-e.18).

**Authority read:**
- the [TB121 report](Architecture_M6_CP3_TB121_P13_Edge_Transit_Seed_Conformance_Receipt_Full_Gate_Execution_Report_20261116.md);
- [RA-240](Architecture_M6_CP3_DEFN_P13_Vertex_Transit_Outflow_Outcome_Review_20261116.md) §§2–6 and [RA-239](Architecture_M6_CP3_DEFN_P13_Obtuse_Edge_Port_Outcome_Review_20261116.md) §3;
- DESIGN Amendments 17 and 22, and `M3_Closure_Record.md` AX1;
- at HEAD: `resolve_field_vertex_transit`, `field_aligned_next_trace_proposal`, `resolve_field_edge_port_departure`/`_slide`, and the atlas straddle rule (`FieldTransportAtlas.cpp`, RA-236–RA-238).

HEAD's `src`, `include` and `tests` are identical to the CB140 source `6a293e4641a2160cb9f447322c9aa1d1d26f3838`. No runtime was used.

## 1. TB121 accepted

TB121 is accepted as a **scoped MATCH**. Both artifacts were re-downloaded into their own directories and SHA-checked:
- gate `14208145885`: outer `6b51264d…`; 1,902/1,902 internal hashes; 947/947 PASS; no R1 and no `edgeTransitSeedConformance` line in any raw log.
- census `14208251561`: outer `f8f1fbfa…`; 9/9 internal hashes; 1 PASS, 2 RED.

Every R1/sector, `partition edgePort` and `edgePortDeparture` line in all three census rows is identical, in order, to TB120's census (`14201142306`, `4d680693…`). The BunnyRandom terminal and locus are unchanged. The single new line is exactly prediction Q1:

```text
FieldAlignedCurveNetwork.edgeTransitSeedConformance singularity=12 sourceVertex=138 trace=51 step=0 vertex=137 carrierEnd=138 modeled=1 codeOwner=3 carrierOwner=4 carrierOnRadialRay=0 codeOwnerLeaves=0 carrierOwnerLeaves=1 sectors=6
```

Q2 holds: no line for traces 24 and 99. No `modeled=0` line appears anywhere.

## 2. Findings

- **F1: the AX1 seed switch is measured neutral on every accepted row.** CB140 re-ran the exact election from the carrier ray at every `EdgeTransit` arrival on the production path. It printed nothing in all 947 gate rows, Cylinder or Vase, and no arrival was unmodelable. So the switch moves no accepted owner, and RA-230's option staging is not needed. It changes one owner in the census: BunnyRandom vertex 137, from 3 to 4, whose field leaves the vertex.
- **F2: D12 = A (user, this turn).** Asked again here (RA-234), the user chose **A, follow the field**. It amends Amendment 22's residual cases: when the elected owner has no outflow, the trace continues by the existing edge rules instead of failing. Options B and C are rejected.
- **F3: the existing rule for A's slide case is the atlas straddle rule.** At a singular vertex the atlas already handles "face i's field points past the shared radial and face i+1's points back" (RA-236). It publishes an edge-supported port only when both fields advance along the radial away from the vertex, measured exactly (RA-238), and the trace then departs by `resolve_field_edge_port_departure` and slides by `resolve_field_edge_port_slide` (D11 = A). D12 = A's slide is the same configuration at a regular vertex, so it reuses that test and those two functions (RA-237 lesson). The grazing endpoint-rate proxy is not used, because it fails on obtuse faces (RA-238).
- **F4: both changes fire only where measured.** The follow runs only on the R1 predicate (owner without outflow), which fired 0 times in 947 gate rows, Cylinder and Vase (TB120, TB121). The seed switch changed no gate owner (F1). Both changes are therefore frozen in one compile-only CB with receipts that show either one firing.

## 3. Frozen CB141: `M6-CP3-CB141-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW` (compile only)

- **Patch:** [exact diff](Architecture_M6_CP3_CB141_P13_Vertex_Transit_Carrier_Seed_And_Outflow_Follow_Exact.diff).
  - SHA-256 `cc937c0674b1deb6fd0bbf2fb561d1ad1fa1a1a1a26df58af6939103f08242b5`.
  - 655 lines, standard 3-line context.
  - Numstat:
    - `41 1` `include/directional/geometry/SurfaceCellTracing.h`;
    - `239 23` `src/geometry/SurfaceCellTracing.cpp`;
    - `202 0` `tests/FieldAlignedCurveNetworkTests.cpp`.
- **Base:** HEAD at this record's commit, or any descendant that changes only documentation. Precheck: `git diff --quiet 6a293e4641a2160cb9f447322c9aa1d1d26f3838 HEAD -- src include tests`.
- **Carrier seed (O44, AX1).** `resolve_field_vertex_transit` gains a trailing `arrivalCarrierEnd`. In `EdgeTransit` mode it replaces the negated field with the exact carrier ray (−1 on the vertex, +1 on the carrier's other end). The production slide-end call passes it. Direct callers that omit it keep the field seed, so every accepted unit test is unchanged.
- **Outflow follow (D12 = A).** `follow_field_vertex_transit_outflow` reads the audited fan after the election:
  - **OwnerLeaves:** the owner's field has no negative weight off the vertex. Nothing changes.
  - **Cross:** walk across the radial edge each field points over; the first sector whose field leaves continues.
  - **Slide:** two adjacent fields point at each other across a shared radial, and both advance along it away from the vertex (exact dot product on the source geometry). The trace stays in the sector it is in, and its next step departs along that radial through the edge-port departure and slide.
  - **Unresolved:** anything else (a field pointing into the vertex, an open fan's end, a full turn, no exact advance). The election is kept, so the next step fails closed as before.
  - Wiring: both vertex-transit sites in `field_aligned_next_trace_proposal`. A new `FieldAlignedVertexSlide` carries the slide to the next proposal, which treats it exactly like an edge-port departure.
- **Receipt.** `FieldAlignedCurveNetwork.vertexOutflowFollow … outcome=Cross|Slide|Unresolved elected=(…) continuation=(…) branch= [carrier=(…)]`, printed only when the owner has no outflow. R1 and the CB140 receipt stay; the CB140 receipt now compares the carrier-seeded owner with its own model.
- **Tests (2, unrun; the gate runs them).**
  - `ResolvedBranchCorrection.EdgeTransitArrivalSeedsElectionOnCarrierRay`: the planar four-face fan, arriving at the centre with the branch whose negated field lies on the *other* radial of the arrival face. Without the carrier the owner follows the field; with it, the owner follows the carrier, and the seed audit names the carrier end.
  - `ResolvedBranchCorrection.OwnerWithoutOutflowFollowsFieldAcrossRadialEdge`: the same fan with integer per-face primaries and zero matching, so a straight-through arrival elects the top face (2,3,4). The three cases are leaves → OwnerLeaves; cross → right face (1,2,4); slide → top face along (2,4). The barycentric weights and along-edge dot products were computed by hand for each case. Either expectation fails if its rule is removed.
- **Checks.**
  - `git apply --check` passes at HEAD.
  - `-fsyntax-only -Wall -Wextra` (Homebrew clang++, CI defines) returns 0 on the source, on the changed test file, and on `SurfaceCellREPackageTests.cpp`, another caller.
  - The warning sets of the source and the changed test file are identical to HEAD's: 43 and 42.
  - Membership becomes 1,030.
- **Routes.**
  - Mismatch: `M6-CP3-PLAN-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-STOP`.
  - Infrastructure: `M6-CP3-CB141A-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-ORCH`.

## 4. TB122: `M6-CP3-TB122-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-FULL-GATE-EXEC` (artifact only)

- **Gate.** Manifest `gates/Architecture_M6_TB122_P13_Vertex_Transit_Carrier_Seed_And_Outflow_Follow_Full_Gate_Case_Manifest.tsv`:
  - TB119/TB121's 947 rows byte for byte, plus GUARD rows 948 `ra241:edge-transit-carrier-seed` and 949 `ra241:owner-without-outflow-follow` (`directional_surface_cell_producer_tests`).
  - SHA-256 `a56ad00ce48424a8505b7a6ab71500a4c60285b3d96ceecaf7cf1a3724f5f2b1`; `SELF_CHECK_PASS cases=949 deferred=81`; expected membership 1,030.
- **Census.** The three-case manifest `3af1dc0d…`.
- **MATCH requires all of these:**
  - **Gate:** 949/949 PASS, membership 1,030, deferred 81.
  - **Receipts:** every TB121 receipt line in rows 1–947 is unchanged, and no gate row prints an R1, `edgeTransitSeedConformance` or `vertexOutflowFollow` line.
  - **Cylinder:** PASS, with unchanged receipts.
  - **Vase:** terminal line identical to TB121's.
  - **BunnyRandom:** the run completes with a verdict, and its 16 `partition edgePort` lines are unchanged.
- **Record verbatim, as measurements:**
  - BunnyRandom's verdict, terminal and locus;
  - every R1/sector, `edgeTransitSeedConformance`, `vertexOutflowFollow` and `edgePortDeparture` line, in any row or case.
- **Predictions.** A miss is a finding, not a mismatch:
  - (S1) BunnyRandom prints no R1 line at vertex 137 and no `edgeTransitSeedConformance` line.
  - (S2) If trace 99 reaches vertex 349 as in TB120: `outcome=Cross` with `elected=(5,102,349)` and `continuation=(5,306,349)`.
  - (S3) If trace 24 reaches vertex 48 as in TB120: `outcome=Slide` with `elected=(48,271,272)`, `continuation=(48,271,272)` and `carrier=(48,271)`.
  - (S4) BunnyRandom's terminal moves past `BranchContinuationDegenerateEntry` at (137,149). Where it moves is not predicted.
- **Routes.**
  - Mismatch: `M6-CP3-TB122-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-FULL-GATE-REV`.
  - Infrastructure: `M6-CP3-TB122A-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-ORCH`.
  - MATCH: Review-only `M6-CP3-DEFN-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-OUTCOME` (P13-e.21). It reads BunnyRandom's new terminal and names its owner stage.

## 5. Gaps and carry

- **The tests are unrun.** Their fixtures were derived by hand, not from a run. A wrong derivation fails row 948 or 949 and routes to REV.
- **No unit test drives a slide through `field_aligned_next_trace_proposal`.** The departure reuses the edge-port path, which rows 946–947 cover. BunnyRandom vertex 48 (S3) is the first runtime witness of the D12 slide.
- **Not changed:**
  - the diagnostic legacy path `legacy_canonical_field_aligned_traces`, which runs only for the contact census;
  - the test-only cp4c trace-cost replay in `FieldAlignedCurveNetworkTests.cpp`.
  Both keep the field seed and no follow.
- **The vertex-star audit still records the Amendment 22 election.** The follow appears only in its receipt and in the continuation.
- **D12 = A is recorded here, not in DESIGN.md.** DESIGN's Amendment 22 text is unchanged, as D11 = A's was.
- **O44:** the fix is frozen in CB141 and closes when P13-e.21 accepts TB122.
- **Carried unchanged:**
  - O42 and O43;
  - D11 = A, D10 deferred, D6 pending;
  - CP2 491/491;
  - stable 66/17/49, debt 1, deferred 81;
  - CP3/selector497 unpromoted, `chainRimSchedules=false`;
  - then 65A–65D.
- **Candidate status.** BunnyRandom's terminal stays a **non-stable P13-e candidate**. Both causes established in RA-240 now have frozen fixes.
