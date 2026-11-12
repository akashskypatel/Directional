# RA-234 — Size grading decision, D10 (step 64E.12)

Turn `M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION`, Review agent only, runtime-free. Input: [TB115](Architecture_M6_CP3_TB115_P13_A4_Production_Size_Census_Full_Gate_Execution_Report_20261112.md) (945/945, scoped MATCH; census Cylinder PASS, BunnyRandom and Vase registered RED; twelve full-gate and seven census `production` lines). RA-233 §3 and §6.

## 1. What TB115 showed

| Case | Production run | Gate | Size, interior p5/p50/p95 |
|---|---|---|---|
| Plane, MultiFaceSeam, CloseSheets, Cylinder | produced; the uniform or annulus producer | accepted | identical to their TB114 per-arc lines |
| BunnyRandom | fails at `field-transport-atlas/SingularityPortClassCountMismatch` (vertex 49) | — | — |
| **Vase** | `phaseFront=NotApplicable`, `a3=0/0/0/0/0`; completion fails with `AggregateCompletionValidationFailure` | `accepted=0 strict=0` | **0.0035/0.045/0.198**, 134,598 of 135,290 interior edges below 0.5 |

Vase's other measures:
- angle 6.5°/180.8°;
- scaled Jacobian −1/−0.013;
- non-convex 16,808;
- boundary valence mismatch 248/420;
- singularity valence mismatch 1/1;
- warpage 81.8°/166.2°;
- aspect 60.7/286.6.

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **Vase's RED is not O41.** Vase never reaches an authoritative region producer: the phase front is not applicable and A3 covers nothing. Its quads come from the legacy trace path. They are about 20× smaller than target, which is the trace density RA-212 measured (noise-seeded relief critical points, O31), and they are geometrically invalid (negative Jacobian, non-convex, valence). Interior size grading in a single-patch region plays no part | TB115 Vase lines |
| F2 | **O41 blocks only the chain switch, and no accepted output needs the switch.** Every accepted gate fixture passes on the per-arc production path (TB115). The switch's purpose is A3 authority over chains on curved discs, and that only pays off once A4 builds those discs (65C) | TB112–TB115 |

## 3. Decision (D10, answered by the user on 2026-11-12: **defer the switch**)

1. **Production stays per-arc.** `SurfaceCellOptions::chainRimSchedules` stays off. CB131's staging and the CB132–CB134 receipts stay in place as measuring infrastructure; they are inert with the option off.
2. **O41 is folded into 65C** (`M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION`). A4's region construction must handle a target that varies inside a region beyond the size band: interior size transitions, which is option A in substance. Activation of the switch becomes a 65C exit condition, re-measured by the existing `switch-*` receipts.
3. **Options B and C are not taken.** The D7 count contract and the gate's thresholds are unchanged.
4. **Next work goes to the blockers of real outputs.**
   - **BunnyRandom** (P13-e) blocks at the field transport atlas. Its Review `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` has been queued as runnable in parallel since RA-214 and is now the canonical next turn.
   - **Vase** needs authoritative disc producers. The documented sequence 65A → 65B → 65C → 65D leads there and follows P13-e.
   - O31/O32 remain the owners of Vase's legacy-path density.

## 4. Nothing frozen for the implementation agent

This turn changes no source and freezes no patch. **The implementation agent has no runnable turn** until the P13-e Review freezes its CB/TB.

## 5. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64E.12 **COMPLETE** | `M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION` (this record; D10 = defer) | Review |
| **next** | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → its CB → TB | **Review agent only**, then implementation |
| then | 65A `M6-CP3-DEFN-P13-A3-BOUNDARY-SPAN-CARRIER-BINDING` → 65B `M6-CP3-DEFN-P13-A2B-RECIPROCAL-TRACE-INTERVALS` → 65C `M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION` (now including O41 and switch activation) → 65D | Review, then implementation |
| parallel | O31 `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES`, O32e (Vase legacy density) | Review |

**Gaps, stated.**
- Deferral keeps per-arc counts, which pass the accepted fixtures by over-coarsening boundaries (RA-233 F3).
- The census still runs each fixture twice (CB131 receipts), which costs runtime but changes no verdict.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No manifest frozen; TB115's is TB114's; selector497/CP3 unpromoted |
| Decisive claims re-derived | The TB115 Vase lines (phase front not applicable, A3 zero coverage, size and geometry failures) and the per-arc pass of every accepted fixture were read by me |
| User decision | D10 answered: defer the switch (2026-11-12) |
| Runtime-free checks | None needed; no patch or manifest frozen |
| Obligations carried | P13-e (next); 65A–65D with O41 and activation folded into 65C; O31; O32b–e; O33; D6 user decision pending; O34 (narrowed); O30b |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB115 945/945, membership 1,026 |
| Turn boundary | No product or test source changed in the repository |
