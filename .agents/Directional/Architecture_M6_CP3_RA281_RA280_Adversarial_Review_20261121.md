# RA-281 — adversarial review of RA-280 (2026-11-21 UTC)

## Situation — CB-172B stands; RA-280's design rationale and forward sequence corrected

**RA-280's diagnosis (D1, D2) and its frozen CB-172B diff stand unchanged; CB-172B remains the next turn.** RA-280 has three defects:
- It narrowed a frozen, total contract (DESIGN Amendment 14) without noticing.
- It rejected the contract-faithful alternative for the wrong reason.
- Its forward sequence omitted a guard that the planned stop switch will trip.

RA-281 records the narrowing as an explicit interim restriction with a removal condition, gives the real reason R2 must come first, and freezes the corrected forward order. No source, test, diff or manifest changes. The CB-172B diff still applies to HEAD (`git apply --check`).

## Evidence used

- `DESIGN.md:483–489` (Amendment 14): "The admissible cut set is therefore every source edge that is not already a graph arc. Consequently `network ∪ (source 1-skeleton)` is a cellular embedding, a sufficient cut set always exists, and step 8's 'certified source-edge cuts' is a total contract."
  - It cites `M3_CP4c_Frozen_Definitions.md` Part III §§3, 5, a file that no longer exists. The content survives in `M3_Closure_Record.md:4954ff` (§6) and `:5243–5255` (Amendment 14, superseding §6's exclusion of trace-crossed edges and §8.2's "no completeness claim").
- TB148 Review (lines 19–35): each of the four sphere contacts (the χ+4 excess) is a committed moving-trace entry strictly inside a wall's slide, on carriers (6,8), (16,21), (33,34) and (45,46). These are four of the ten slid carriers, with 0 shared events.
- TB149 Review line 110 describes the stop switch, in prose only: the moving trace "ends at its entry with `carrierLocus`, and `build_cut_node_bindings` takes the struck cut from `carrier_contact_slide_position`".
- `EmbeddedGraphTopology.cpp:880–902`: a slide-interior `TraceCutPosition` fraction must lie strictly in (0, 1). The slide start (fraction 0) has no representation.
- `SurfaceCutCandidateClass` has no consumer in `src/` beyond the classifier, the candidate hashes (`SurfaceCutGraph.cpp:916/975`) and the name table. The new class is therefore read nowhere else.

## Findings on RA-280

**F1 — R2 narrows Amendment 14; RA-280 did not say so (design, major).**
- Only the slid interval [P, v] of a carrier is already a graph arc (the trace's slide piece); the remainder [far vertex, P] is not. Amendment 14 therefore makes the remainder admissible.
- R2 withholds the whole edge, so the "sufficient cut set always exists" guarantee becomes conditional.
- The exact condition: the withheld remainders must not close a dual cycle that encloses graph material. Cells merged across them along a forest stay discs. The sphere's ten carriers meet at most two per vertex, so the sphere search does not exercise the condition. It is non-cellular in any case, because of χ+4.
- RA-280's phrase "for distinct cells the merge is still a disc" stated the condition without the contract it narrows.
- **Ruling:** keep R2 as an interim restriction, recorded in `DESIGN.md` beside Amendment 14 with its removal condition and falsifier. The cut-candidate evidence already names every withheld carrier (`TraceSlideCarrier`), so the restriction is observable and never silent.

**F2 — The real reason R1 must wait (rationale, major).**
- RA-280 rejected R1 because it needed "three new rules that no fixture witnesses". The stronger and decisive reason is safety.
- Under R1 a saturated slid carrier becomes a cut. The four moving-trace entries strictly inside the wall slides (carriers 6–8, 16–21, 33–34, 45–46) are segment entry points on that cut, so `build_cut_node_bindings` creates cut nodes there (`EmbeddedGraphTopology.cpp:465–500`).
- Those nodes lie on the wall's slide piece, which no network event splits. Omitting the covered cut sub-arcs would leave nodes in the interior of a trace arc, and no guard detects that.
- R1 is safe only after the stop switch turns each sliding-wall contact into a node. It also needs a slide-start cut position, fraction 0, which does not exist yet.
- R2 is therefore the only sound repair before the stop switch, not merely the simpler one.

**F3 — The stop switch will trip CB-171's `RayRunsAlongLocusEdge` (forward sequence, major).**
- The stop switch ends each moving trace at a carrier contact strictly inside the wall's slide. That is a node at an edge locus on the wall's carrier, and the wall is split there (`carrier_contact_slide_position`).
- At that node the wall's two pieces leave along the locus edge in opposite directions. CB-171 deliberately fails such rays closed, with `EdgeTraceSecondaryRankInvalid` / `RayRunsAlongLocusEdge`.
- The stop-switch sequence must therefore define the along-locus-edge key there:
  - The key is the edge-arc slot of the ray's direction (0 toward the second endpoint, 2 toward the first; `EmbeddedGraphTopology.cpp:3138`).
  - A coincidence with a real edge-arc half fails closed.
  - These rays must count in `edgeRayCount`, so that into-face rays take `2·side+1`. Otherwise an into-face ray with side rank 0 would take primary 0, the along-edge slot.
- RA-280's prospective list omitted this, and RA-278 withdrew the rule only "until a fixture witnesses it". The stop switch is that fixture.
- Under R2 the wall carrier is never a cut, so the TB149 prose "`build_cut_node_bindings` takes the struck cut" is unreachable. The wall is split by the network event alone, and the stop-switch freeze must drop that clause.

**F4 — Minor accuracy fixes.**
- D3's "only the prescribed sphere commits slides (23 gate rows)" is a proxy taken from printed receipts. The correct wording is: no other gate row is known to publish a committed slide. TB-EXEC-156's non-A MATCH rule is what catches a surprise.
- The fixtures of the accepted tests that pin classes (`build_cp4c_trace_crossed_cut_fixture`, rows at `tests/FieldAlignedCurveNetworkTests.cpp:3288/3833/11115`) are real-tracer skew discs. Whether they carry a slide is unmeasured. If one did, its carrier would leave `TraceInteriorCrossing`, and the STOP rule would catch the change.

**Upheld without change:** D1 (the incidence is a saturated Cut arc), D2 (no cut node at the slide start), D3 (CB-172A withdrawn), O1 (row 858's placeholder locus), the CB-172B diff with its hashes and test, and the TB-EXEC-156 STOP criteria and predictions.

## Corrected turn sequence

| Step | Turn | Scope |
|---|---|---|
| NEXT | `M6-CP3-CB-172B-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY` | Unchanged: exact diff `7d0e0f0a…95ef`, compile only. |
| then | `M6-CP3-TB-EXEC-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` | Unchanged RA-280 criteria; TB156 manifest `cbba9e76…28dc6a`. |
| then | `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` | As in RA-280. If green, also freeze the stop-switch helper CB exactly, including the F3 along-locus-edge key and without the TB149 cut-binding clause. |
| prospective | stop-switch helper CB (unwired: moving-trace stop at a wall contact plus the along-locus-edge key, with pure tests) → stop-switch CB (wires both) → its TB/Review | χ+4. The four contacts become nodes. Witnesses F3. |
| prospective | slide-start subdivision CB (R1: a fraction-0 cut position, a cut-created node at the slide start, covered cut sub-arcs omitted) → TB/Review | Deletes the Amendment 14 interim restriction. Only after the stop switch (F2). |
| prospective | slide-plan conformity (RA-275 S4a) → O48 carrier turns | O49 held. Renumber when frozen. |

## Lessons

- Before narrowing a candidate set, read the frozen contract that defines it. A sound restriction of a total contract is recorded as an amendment with its removal condition, never left implicit.
- Rank staging choices by their safety precondition. Ask what an alternative would place on records that are still unsplit, not only which rules are unwitnessed.
- When a planned switch will create the configuration a fail-closed guard rejects, put the guard's replacement inside that switch's sequence.

## Review closeout

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Amendment 14 text; carriers of the four contacts; slide-fraction bounds; class consumers; CB-172B apply-check on HEAD. |
| Prior obligations | RA-280 D1–D3 upheld; its R2 rationale replaced (F2); Amendment 14 interim restriction recorded (F1); F3 added to the stop-switch sequence; RA-275 S4a, O47/C5/O48/O49 and χ+4 carried. |
| Stable accounting | 66/17/49; debt 1; deferred 81; CP2 491/491; no promotion. |
| Turn boundary | Runtime-free; documents only (`DESIGN.md` interim note, handoff, TODO, CHANGELOG, ORIENTATION, tracker, LESSONS). |
| Successor | CB-172B unchanged. |
| `STATUS` | IN_PROGRESS first (`eec213b0e`); COMPLETE last. |
