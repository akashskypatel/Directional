# M6-CP3-TB-REV-192 — adversarial review (2026-11-27 UTC)

## Situation

The [independent review](Architecture_M6_CP3_TB_REV_192_Singularity_Arrival_Independent_Review_20261127.md) accepted the 1010-row test gate and froze `M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL` with options A/B/C and five falsifiers. Its acceptance is **upheld**. This review uses the row858 tracing records the independent review did not read. They decide most of AP4, and they correct one of my own earlier claims.

## Evidence

- TB192 result `15195820651`, ZIP `37bd0d7c…0ce` (re-verified).
- `raw/858.log`: 79,691 B, SHA-256 `d4f1e483…09914`, 478 lines.
- Three identical 30-line groups of tracing records (the canonical candidate is derived three times):
  - 10 `slideProposal` and 10 `committedSlide` lines;
  - 2 `entryCoincidence` lines;
  - 4 `slideCoincidence` + `slideContactArrival` pairs.
- Region schedules and arrival lines are the TB192 ones.
- Trace *i* starts from port *i* (TB-REV-173 E2), and r = 0 on the sphere.
- Runtime-free: the log was downloaded by a Haiku agent into an isolated scratch directory.

## Findings

**EE1 — The exact port of every arrival is confirmed. TB-REV-192 only checked ranges.**
- Each node's three ports run to three distinct neighbours of a cube graph (8 singular nodes, 12 separatrices).
- Every claimed port's own trace stops next to the claimer's origin singularity:

  | Trace | Stops | Next to |
  |---|---|---|
  | 4, 6 | head-on, inconclusive, carrier 0-2 | n0 |
  | 15, 19 | head-on, carrier 25-27 | n4 |
  | 3, 7 | at degree-2 node 8 | n3 |
  | 16, 18 | at degree-2 node 11 | n7 |
  | 2 | on trace 13 (T17) | n4 |
  | 23 | on trace 9 (T16) | n3 |

- All 10 reported ports (4, 6, 3, 23, 7, 19, 15, 2, 16, 18) are the reverse traces of their arrivals' separatrices.
- The schedules fix the current embedding: V = 18 (singular degrees 4,5,5,3,3,5,5,4; four degree-2 both-stop nodes 8–11; six T-nodes 12–17), E = 30, F = 14.

**EE2 — No claim is reciprocal, so the direction of removal is forced.**
- None of the claimed traces {2,3,4,6,7,15,16,18,19,23} is an arrival. Each partial co-trace is one-sided.
- Option B (head-on) does not arise, and D13's exact pair rule does not apply.
- Removing the arrival X would leave X's origin port unowned, because Y never reaches X's origin. Invariant 1 therefore decides that the claimed port's trace Y is the one removed, and X's `arrivalPort` owns Y's port.
- What remains open is only how a removal restores invariant 3 for traces that stopped on Y.

**EE3 — On the sphere no kept trace stops on a removed trace, so removal needs no re-trace.**
- The 14 kept traces are the 10 arrivals plus traces 5, 8, 17 and 20.
- The logs record those four stopping on the final radial-edge slides of kept arrivals 21, 22, 0 and 1.
- So option A's fixed point is reached in one round and equals plain deletion.
- Exact static prediction for any removal rule:

  | Quantity | Prediction |
  |---|---|
  | Traces | 14 |
  | Nodes | V = 12: 8 singular, all degree 3, plus T-nodes 12–15 |
  | Arcs | E = 18 |
  | Regions | F = 8: 6 cube faces + 2 slivers |
  | Arrivals | 10, all `portTraced=0` |

- Contacts are resolved by arc-length arrival order (`field_aligned_contact_termination_decision`). A re-trace after suppression is therefore **not monotone in general**: an extended trace can cut a trace that used to arrive, and so withdraw its claim.
  - Option A would need a lost-claim failure anyway.
  - **A0** is the smallest correct rule: remove each claimed trace, and fail closed with a typed error when a kept trace stops on a removed one, when claims conflict, or when claims chain.
  - A0 is order-independent, needs no termination proof, and gives EE3's result on the sphere.

**EE4 — Correction: slivers 2 and 4 are not arrival co-traces, and AP4 cannot remove them.**
- Region 2 (nodes 1,12,5,14; sides 1,32,1,32) is the separatrix n1–n5 traced twice: traces 5 and 17, neither of which arrives.
- Region 4 (nodes 13,2,15,6) is n2–n6, traced twice by traces 8 and 20.
- Each of those traces stops at a T-node on another separatrix's final slide, one segment short of its target.
- TB-REV-191 adv. DD2 and the A2a DEFN put all four slivers (2, 4, 5, 10) down to arrival co-traces. That is wrong for regions 2 and 4. Regions 5 and 10 (and lenses 1, 6, 13) do merge under removal.
- Removing trace 5 or trace 17 would leave a port owned by a curve that ends at a T-node, not at the singularity. That alters port topology, which invariant 8 forbids.
- Both regions are valid under DESIGN (disc, four sides, equal opposite sides), but they are strips of near-zero width.
- **New open obligation O52** (near-miss doubled separatrices). It is a user question after AP4 and does not block AP4.

**EE5 — The classifier is not fit to drive behaviour as frozen.**
- It takes the first match (`if (!slot && …)`), so ambiguous rays or attachments are resolved by order.
- The radial-edge path ignores the arriving branch; only the face-interior path checks `branch.rotated(2)`.
- An unmatched arrival yields `port = nullopt` without a failure.
- It reads the published network and atlas, but D13 selection runs on the candidate inside `canonical_field_aligned_traces_and_events` (`SurfaceCellTracing.cpp:4979`).
- A removal consumer therefore needs:
  - a candidate-level classifier that requires a unique, branch-consistent match and returns a typed failure otherwise;
  - delivered as its own compile-only CB, ahead of the removal CB.

**Upheld:** gate 1010/1010 for test only, the AP1–AP3 dispositions, the falsifier list and the user-decision STOP. Refined: the decision is A0 against option A, and EE3's prediction is the oracle.

## Predicted post-removal regions (counts assume additive segment counts)

Boundary nodes use the current ids (singular 0–7, T-nodes 12–15).

| Cube face | Boundary nodes | Bounding traces | Sides |
|---|---|---|---|
| Sliver n1–n5 (now region 2, unchanged) | 1, 12, 5, 14 | 5, 17, slides of 0 and 21 | 1, 32, 1, 32 |
| Sliver n2–n6 (now region 4, unchanged) | 13, 2, 15, 6 | 8, 20, slides of 1 and 22 | 1, 32, 1, 32 |
| n0-n1-n3-n2 (regions 1+6+7) | 0, 12, 1, 3, 2, 13 | 0, 9, 11, 1 | 30, 1, 37, 35, 1, 30 |
| n0-n1-n5-n4 (regions 0+5) | 0, 12, 5, 4 | 0, 17, 13, 14 | 30, 32, 37, 35 |
| n0-n2-n6-n4 (region 3, unchanged) | 0, 13, 6, 4 | 1, 20, 12, 14 | 30, 32, 35, 35 |
| n1-n5-n7-n3 (regions 8+10) | 1, 14, 7, 3 | 5, 21, 10, 9 | 32, 30, 35, 37 |
| n2-n3-n7-n6 (region 9, unchanged) | 15, 2, 3, 7 | 8, 11, 10, 22 | 32, 35, 35, 30 |
| n4-n5-n7-n6 (regions 11+12+13) | 4, 6, 15, 7, 14, 5 | 12, 22, 21, 13 | 35, 1, 30, 30, 1, 37 |

- In four faces a sliver displaces one corner from the singular node to a T-node: 12 for n1, 13 for n2, 14 for n5, 15 for n6.
- An independent Haiku check confirmed:
  - V18/E30/F14 and the node degrees;
  - the empty intersection of the claimed traces with the arrivals;
  - every kept non-arrival's stop;
  - the sliver sides and the parity sums.
- It also confirmed that the arc-to-trace mapping, and so E = 18 and F = 8, follow only from this review's trace reconstruction, which uses the stops and the side counts. No log line prints them directly. TB-EXEC-193 measures them.

All boundaries are even. Unequal opposite sides persist (DD5, A4 unequal-side construction).

## Turn sequence

1. `M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL` — NEXT. User decision A0 or A. Freeze the §7.2 step-7 text, the CB-217 and CB-218 exact diffs, and the TB-EXEC-193 manifest from EE3.
2. CB-217: candidate-level unique arrival classification (EE5), compile only, behaviour-neutral.
3. CB-218: claimed co-trace removal with typed failures, compile only.
4. TB-EXEC-193: full gate. Row858 goes from 14 to 8 regions as predicted; all other rows must be N1–N3-equal or STOP.
5. TB-REV-193.
6. Corners DEFN (A4D5), together with the O52 decision. Then A4 unequal-side construction.

## Closeout

| Duty | Answer |
|---|---|
| Own errors corrected | TB-REV-191 adv. DD2 / A2a DEFN sliver attribution (EE4). |
| Tracker | O51 narrowed (10 of 12 doubled separatrices are removable); O52 opened. |
| Boundary | Runtime-free; no product, test, selector or gate change. |
