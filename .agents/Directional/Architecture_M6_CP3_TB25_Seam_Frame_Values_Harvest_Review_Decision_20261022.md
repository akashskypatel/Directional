# RA-126 — TB25 seam frame-values review: the identity-turn branch; DEFN-SEAM narrowed to A5 shared-node side authority (2026-10-22)

**Turn:** `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST-REV`.

**Verdict:** TB25 is **accepted** as diagnostic evidence. The pre-registered routing (RA-124.6) selects **F = 0**: the frozen D3 rule (RA-30a.3) is satisfiable for every measured seam, and the A5 face clauses are the only blocker. `cp3entry:3` and `cp3entry:5` join the A5 seam family. DEFN-SEAM is **authorized, narrowed** to A5 shared-node side authority. No code is authorized yet.

## RA-126.1 Harvest verified independently

- **Artifact:** `12384333036` (run 39682528031, head `30a1e9357`). The provider digest equals the local ZIP SHA-256 `f10ef778…cbc`; it expires 2026-10-28T21:56:02Z. **16/16** manifest entries check.
- **Logs:** each of the 11 logs has exactly one `[ RUN ]` and no skip. Rows 6–11 PASS with no site.
- **Torus rows 1–3:** one byte-identical site: the TB24 prefix plus `;branch=3,3;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0`.
- **D3 witnesses (rows 4–5):** each logs three A5 `OccurrenceMismatchedIsolationEvidence` sites at `seam=1,4`. They show `sel=0/0,0/0`, `support=vertex,vertex`, `wedge=0/0,2/1+3/1`, the clause `second-face`, `spanOnly0=forward`, and `branch=0,0;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0`.

## RA-126.2 Routing (RA-124.6, read for both occurrences)

| Family | Producer signature | Stripped turn (RP:5887–5905) | d | F | Branch |
|---|---|---|---|---|---|
| Torus A5 (10 rows, TB23) | curved: `branch − gaugeSel = 3, 3` | (3−0) − (3−0) = 0 | 0 | 0 | F = 0 |
| D3 witnesses `cp3entry:3/5` | uniform: `0, 0` | 0 | 0 | 0 | F = 0 |

**RA-124.3 P3 is confirmed at runtime.** Both families have the same structure (RA-124.3 P1–P2): one shared node, one representative face, inside one occurrence's wedge and outside the other's. The face clause that fails is `first-face` on the torus and `second-face` on the D3 grid. Span/wedge side authority alone gives `forward`, and D3 (stripped turn = F = identity) holds.

Neither gauge-table inconsistency (d ≠ F) nor a nonzero certified turn was observed. **Nonzero-turn seams remain unmeasured.** For them, P3 still predicts an A6 reject under frozen D3. That is deferred, not resolved.

## RA-126.3 Classification

- **A5-ISO:** 10 torus rows plus `cp3entry:3/5`, 12 rows with one mechanism. The owner is the **A5 certified-seam face clauses (RP:3891–3892)** acting on shared-node relations. A2's per-node representative is the data model, not a defect, for identity seams.
- **`cp3entry:3/5` now have an owner.** Their helper (`m6cp3_produced_seam_fixture`, TQ:2725) fails because of the A5 mechanism, not fixture construction.
- **RA-124.3 Corollary 2 is amended.** RA-124 said these rows were filed as adjacent-sheet fixture debt; that is wrong. The adjacent-sheet item is the curved-disk helper `make_curved_disk_with_adjacent_source_sheet` (P10:2670, RA-93.3), which stays in the fixture-debt list. `cp3entry:3/5` previously had no owning family.

## RA-126.4 Successor `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (documents only)

**Deliverable:** `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md`, at most 90 lines, anchored at HEAD. It must contain:

1. **Exact amended rule for `certified_seam_direction` (RP:3880–3911).**
   - When both canonical occurrences are **one shared node**, defined as equal `support` and equal `placement.selectedFace`, the two face-equality clauses do not apply. Direction then comes from `certified_seam_wedge_side` (RP:3855–3875), which already requires the span binding to be in the occurrence's own wedge with the certified sheet, with opposite sides.
   - Every other clause is unchanged: collinear edge, certified seam, region, distinct sheets, uniqueness.
   - Relations that are not shared-node keep the face clauses unchanged.
2. **Enforcer impact.** List every caller of the function: RP:4695 (certificate selection), the relation reject at RP:5250–5262, RP:5293 (site diagnostics) and A6 RP:5878. State that A6, its D3 check (RA-30a.3), the gauge-face check at RP:5869–5870 and the endpoint gauges are unchanged.
3. **Non-weakening table.** Cases that must still reject, each with the clause that rejects it:
   - shared node with the span outside the wedge;
   - same side;
   - equal sheets;
   - two certificates;
   - not shared-node with the face clause failing;
   - shared node with a nonzero certified turn, rejected at A6 by D3.
4. **Predictions and falsifiers for the corrective TB.**
   - The A5-ISO rows (including G4-B002) and `cp3entry:3/5` get past the A5 seam reject. Their next first failure is unknown and is a measured outcome; no green is claimed.
   - All current controls still pass.
   - The TB21-PASS 449 rows are not changed by the amendment (a selector census follows).
5. **Out of scope:**
   - nonzero-turn seams (a later `DEFN-SEAM-NZ`);
   - per-occurrence representatives in A2;
   - any A6 or D3 change;
   - any minimum-face rule (RA-79.4) or new producer certificate (RA-78.4).

**STOP** and return to Review if the rule cannot be stated without changing A6, or if a caller depends on the face clause for anything other than side authority.

## RA-126.5 Sequence and accounting

- **Sequence:** TB25-REV (this) → **DEFN-SEAM** → DEFN-SEAM-REV → CB25 (corrective, RP `certified_seam_direction` only) → CB25-REV → TB26 (12 A5-ISO rows, guard and controls) → TB26-REV → selector-497 census → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DIAG-RETAIN` (user-directed) is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **Interim GUI tooling** (diagnostics sections 6–10, streamlines, build fixes) was committed between CB24 and this Review. All RP-01 sources are byte-identical to `dae267a82`, apart from the legacy streamline tracer, which SurfaceCells does not use.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 16/16 manifest; 11 logs (one RUN, no skip); every site string; routing arithmetic for both families |
| Non-vacuity | Values observed on two producers (curved and uniform) and three fixtures; guard and controls selected and passed |
| Obligations | RA-124.6 discharged (F = 0 branch); RA-124.3 P3 confirmed; D3 nonzero-turn obligation carried to `DEFN-SEAM-NZ` |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
