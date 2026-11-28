# M6-CP3-TB-REV-194 — adversarial review (2026-11-28 UTC)

## Situation

The [independent review](Architecture_M6_CP3_TB_REV_194_CoTrace_Deletion_Switch_Independent_Review_20261128.md) accepted the 1013-row test gate and the O51 deletion witness and attributed both TB-EXEC-194 STOPs to wrong predictions. **Upheld.** Two of its forward obligations are mis-scoped, and the trajectory needs one correction: the binding blocker for the sphere is A4 unequal-side construction, not corners or slivers.

## Findings

**FF1 — Both STOPs were my prediction errors (owned).**

- The switch DEFN froze merged-arc counts of 37 (35 + 2). TB-REV-192 adv. had carried the caveat "counts assume additive segment counts"; the manifest dropped it. D7 counts are per-support metric roundings followed by a global minimum-cardinality parity correction (`GlobalConformityBaseline.cpp:600–671`), so they are not additive across a graph edit. The measured 35 on node pairs 1–3 and 4–5 is the validated A3 product.
- The switch DEFN froze "`M3_CP4AB_FRAGMENT_DIAG` unchanged" as fallback output. It is emitted during plan construction (`GlobalTopologyPlan.cpp:1879`), one record per plan region, so 14 → 8 regions gives 56 → 44 lines. Census 2 had marked diagnostics "inferred"; I promoted an inference to a frozen prediction.
- The "983" row count was also my arithmetic error (984).

**FF2 — The D7 re-derivation is not a precondition of the corners definition.** AA2 and the entry plan's step 1 require exact D7 inputs before any count-dependent work and allow a "bounded exact-input diagnostic plan".

- Corner identification is count-independent: DEFN-65C A4D2 item 2 defines corners as "the field turning at each walk node … from A1 transport".
- A4 consumes A3 counts as the single-writer product; `GlobalConformityBaselineValidator` reconstructs supports, preferred counts and the parity/lexicographic objective and rejects a wrong count. A4 never re-derives them.
- A diagnostic turn to export D7 inputs would be a diagnostic-only slice (RA-214 §1.3).
- Disposition: withdraw step 1 as a precondition. An independent D7 oracle (exact inputs exported and recomputed by a second implementation) stays an optional test-oracle item, off the critical path.

**FF3 — O52 is a quality item, not a validity defect.**

- DESIGN Amendment 30: "Thinness is a quality objective, not a validity criterion (§4.11), so a needle cell is completed, and its needle quads remain a quality item (O23, M7)."
- Slivers 2 and 4 (schedules `1,32,1,32`, nodes 1,8,5,10 and 9,2,11,6) are discs whose boundary turns at the singular nodes and at the T-nodes where a stopped trace meets a slide: four corners, opposite sides equal (1 = 1, 32 = 32). They are griddable as 1 × 32 strips.
- Removing them would need a trace that ends at a T-node to own a port (invariant 8).
- Disposition: O52 moves from open defect to quality item (M7/O23); the entry plan's O52 STOP is superseded.

**FF4 — The binding blocker for the sphere is DD5, not corners.** Grouping each region's arcs into corner-delimited sides (a T-node is a corner only where the boundary changes trace; it is flat where one trace continues through it):

| Region | Schedule nodes | Corners | Sides | Opposite sides equal |
|---|---|---|---|---|
| 0 | 8,0,4,5 | all four | 30,35,35,32 | no |
| 1 | 0,8,1,3,2,9 | 0,1,3,2 (8, 9 flat) | 31,35,35,31 | no |
| 2 | 1,8,5,10 | all four | 1,32,1,32 | yes |
| 3 | 0,9,6,4 | all four | 30,32,35,35 | no |
| 4 | 9,2,11,6 | all four | 1,32,1,32 | yes |
| 5 | 1,10,7,3 | all four | 32,30,35,35 | no |
| 6 | 11,2,3,7 | all four | 32,35,35,30 | no |
| 7 | 4,6,11,7,10,5 | 4,6,7,5 (11, 10 flat) | 35,31,31,35 | no |

- Every region has four corners (consistent with Σ(2 − gap) = 4 on singularity-free discs, A4D5); these are predictions for the corner slice, to be measured from A1 transport, not facts.
- Six of eight regions have unequal opposite sides, so no closed-form grid applies. A3 is parity-only (DESIGN :194/:739); A4 owns unequal-side construction (DD5). That is the step that decides whether the sphere meshes.

## Turn sequence

1. `M6-CP3-DEFN-P13-A4-DISC-CORNERS` (NEXT, runtime-free): define the corner rule from A1 field turning at walk nodes; freeze one compile-only CB publishing corner-delimited sides on the region boundary schedule, with the FF4 table as falsifiers.
2. `M6-CP3-CB-220-P13-REGION-CORNER-SIDES` (compile only) → 3. TB-EXEC-195 → 4. TB-REV-195.
5. `M6-CP3-DEFN-P13-A4-UNEQUAL-SIDE-CONSTRUCTION` (DD5) → CB/TB → Vase row → fill → 65B → 65D (O50, Amendment-19) → O41/switch.

## Closeout

| Duty | Answer |
|---|---|
| Upheld | Gate 1013/1013 test only; O51 witness; AA1, AA3, AA4. |
| Corrected | AA2 scope (FF2); entry plan steps 1–2 (FF2, FF3); O52 class (FF3). |
| Own errors | FF1 (37, fragment receipt scope, 983). |
| Boundary | Runtime-free; documentation only. |
