# RA-233 — Interior size grading, O41 owner (step 64E.9)

Turn `M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING`, Review agent only, runtime-free. Input: [TB114 evidence](Architecture_M6_CP3_TB114_P13_A4_Completed_Mesh_Size_Census_Execution_Evidence_20261112.md) (945/945, scoped MATCH; 46/46 earlier receipt lines unchanged; 8 `switch-size` and 4 `switch-spans` lines). RA-232 §6.

## 1. What TB114 showed

Size ratio = edge length / local target. Columns: quads; boundary edges p5/p50/p95; interior edges p5/p50/p95; interior edges below 0.5; target min/median/max.

| Case, schedule | Quads | Boundary | Interior | Below 0.5 | Target |
|---|---|---|---|---|---|
| Plane per-arc | 64 | 1.27/1.28/1.31 | 0.65/0.88/1.19 | 0 | 0.094/0.098/0.195 |
| Plane chained | 100 | 0.98/1.03/1.07 | 0.53/0.73/0.98 | 0 | same |
| MultiFaceSeam per-arc | 64 | 1.28/1.28/1.31 | 0.53/0.79/1.11 | 4 of 112 | 0.094/0.098/0.283 |
| **MultiFaceSeam chained** | 100 | **1.02/1.02/1.05** | **0.434**/0.667/0.98 | **36 of 180** | same |
| CloseSheets per-arc | 200 | 1.07/1.15/1.21 | 0.67/0.84/1.09 | 0 | 0.085/0.088/0.161 |
| CloseSheets chained | 242 | 0.98/1.06/1.10 | 0.60/0.78/1.00 | 0 | same |
| Cylinder, both | 288 | 0.99/1.05/1.06 | 0.64/0.98/1.17 | 0 | 0.185/0.205/0.384 |

`switch-spans`: `raised=0 lowered=0` on all four fixtures.

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **H2 is refuted.** The parity solve moved no span on any fixture | `switch-spans … moved=-` |
| F2 | **H1 holds.** Under chains every boundary sits at its own target (p50 1.02–1.06). The interior is sized from the boundary count, while the target grows inward: its median stays near the minimum and its maximum is 2–3× the minimum. On MultiFaceSeam the maximum is 3×, and 20% of interior edges fall below 0.5 | `switch-size` lines |
| F3 | **Per-arc passes by over-coarsening.** Per-arc rounds each short source edge to one cell, so boundary edges are 1.28× their target and the interior is lifted. The gate tolerates this because a fixed rail edge counts as on target up to a 4× mismatch (`kMaxImmutableRailSizeRatio = 4.0`). Even per-arc leaves 4 MultiFaceSeam interior edges below 0.5 | `SurfaceMeshOptimizer.h:564`; per-arc lines |
| F4 | **No count can serve both.** A single-patch lattice has one row and column count from side to side. When the target varies about 3× inside a region, matching the boundary leaves the interior too fine, and matching the interior leaves the boundary too coarse. Following both needs size transitions inside the region (irregular vertex pairs), which neither the bounded-disk nor the uniform producer builds | Annulus and bounded-disk lattice construction (RA-227/RA-228) |

## 3. Decision

O41's owner is **the region producer's construction (A4)**, not A3 and not the gate. Three repairs are possible, and each changes a contract the user owns. I am putting them as decision **D10** rather than choosing:

| Option | What changes | Cost and consequence |
|---|---|---|
| **A. A4 size transitions** | Bounded-disk and annulus regions gain graded constructions: transition cells with irregular vertex pairs, so the interior can coarsen | Largest; overlaps step 65C (A4 disc domain). The principled fix; activation waits for it |
| **B. Region-aware A3 count** | A span's preferred count takes the coarser of its own metric and the adjacent regions' interior target, so boundaries are coarsened on purpose, as per-arc does by accident | Changes D7: the count would no longer depend only on the span's path. The gate already tolerates it (F3). Medium |
| **C. Gate policy** | The size band is measured relative to what a single-patch lattice can reach, or the completed-mesh gate before optimization is relaxed | Quality-policy change; output cells stay undersized where the target grows |

Until D10 is answered, activation stays held and nothing is frozen that depends on the choice.

**Measured regardless of D10:** whether Vase's registered RED (`AggregateCompletionValidationFailure`, same code) is the same size failure. If it is, options A or B also address Vase. CB134 prints the gate inputs and the size split on the production (per-arc) design-acceptance runs, which include Vase.

## 4. CB134 — production size receipt (compile only, test only)

[Exact patch](Architecture_M6_CP3_CB134_P13_A4_Production_Size_Census_Exact.diff): SHA-256 `0f3eb0d8c62043013f47b5815fc280d959aec13bca4f7f79d52d2b4431ae4ab4`, 17 lines, keep 1 single-space context line. Numstat: `6 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`. Base: HEAD `a988f8cab` (CB133 source `e60f2c76c` plus documentation).

`SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput` calls the existing `print_switch_receipt` and `print_switch_size_receipt` with schedule label `production`, right after its platform digest. That covers full-gate rows 795–797 (Plane, MultiFaceSeam, CloseSheets) and the census cases Cylinder, BunnyRandom and Vase. No product source changes, and no assertion is added.

Mismatch → `M6-CP3-PLAN-P13-A4-PRODUCTION-SIZE-CENSUS-STOP`; infrastructure → `M6-CP3-CB134A-P13-A4-PRODUCTION-SIZE-CENSUS-ORCH`.

## 5. TB115 — full gate and census

`M6-CP3-TB115-P13-A4-PRODUCTION-SIZE-CENSUS-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB115_P13_A4_Production_Size_Census_Full_Gate_Case_Manifest.tsv`: TB114's byte for byte, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026, `SELF_CHECK_PASS cases=945 deferred=81`. The production census runs as before.

**MATCH needs all of:**
- 945/945.
- Census verdicts unchanged: Cylinder PASS, BunnyRandom and Vase registered RED.
- Every receipt line TB114 recorded byte-identical.
- Every new `schedule=production` line recorded verbatim.
- A `switch-run case=Vase schedule=production` line with `failure=NotProductionReady/completion` and `invalid=completion/output-validation/AggregateCompletionValidationFailure`, plus a `switch-validation case=Vase schedule=production` line with `accepted=0 strict=0`.
- BunnyRandom prints a `switch-run` line only, since it fails before completion.

Every other value is evidence. Of particular interest: which Vase measures fail, and Vase's interior size p5 and target range.

Mismatch → `M6-CP3-TB115-P13-A4-PRODUCTION-SIZE-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB115A-P13-A4-PRODUCTION-SIZE-CENSUS-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION`.

## 6. Follow-on — `M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION` (Review agent only)

It applies the user's D10 answer with TB115's Vase evidence and freezes the first CB/TB pair of the chosen option. Without an answer, it records the Vase evidence and stops at the decision.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64E.9 **COMPLETE** | `M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING` (this record) | Review |
| 64E.10 | `M6-CP3-CB134-P13-A4-PRODUCTION-SIZE-CENSUS` (§4) | implementation agent |
| 64E.11 | `M6-CP3-TB115-P13-A4-PRODUCTION-SIZE-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| — | **D10**: A, B or C (§3) | **user** |
| 64E.12 | `M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION` (§6) | **Review agent only** |
| later | Activation, after O41 | Review, then implementation |

**Gaps, stated.**
- The receipt's ratios use the gate's target but not its rail exception, and count each edge once.
- For produced runs the measured mesh is the optimized one, so the design-acceptance rows show post-optimization sizes.
- Vase's completion may fail other measures too; TB115 shows which.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB115 = TB114 manifest byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | The twelve TB114 lines, the gate's rail exception and its 4.0 tolerance, and the single-patch lattice limit were checked by me |
| Runtime-free checks | `-fsyntax-only` returns 0 on `SurfaceCellDesignAcceptanceTests.cpp` with CB134; CB134 applies at HEAD; manifest self-check passes |
| Non-vacuity | Vase's `switch-run` and `switch-validation` content is a MATCH condition; a different failure path goes to REV |
| Obligations carried | 64E.10–64E.12; **D10 (new user decision)**; O41 (owner: A4); activation; D6 user decision pending; D9c 65A; trace 65B; A4 65C; D8 65D; O34 (narrowed); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB114 945/945, membership 1,026 |
| Turn boundary | No product or test source changed in the repository |
