# RA-124 — DEFN-ISO-A census review: the seam contract does not fit the shared-node producers (2026-10-21)

**Turn:** `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV`.

**Verdict:** the census is **accepted with amendments**.
- Q1 (the `src` enforcer inventory) and Q5 (reach) are accepted.
- Q2 and Q4 are **amended**: Q2 reported statically decidable facts as undecidable and omitted a producer; Q4 misattributed a rule.
- This Review's own finding (RA-124.3) **supersedes RA-123.6–123.7**. The certified-seam contract is written for independently represented sides, but all three producers publish shared nodes in one continuous region frame. **DEFN-ISO-B as framed is withdrawn.**
- The successor is CB24, a diagnostic for one discriminating measurement. No code is authorized.

## RA-124.1 Verified

- `src` and `include` are identical to `e859175333`.
- Q1: the literal reads match the census exactly: `placement.selectedFace` RP:3891–3892, 4678, 4683, 5051–5052, 5312, 5315, 5347, 5350, 5841–5842; `placement.lattice` RP:4990–4993, 5056–5057, 5149–5153, 5721–5722; `cornerWedgeBindings` RP:3869–3871, 5363, 5538–5539, 7311, 7371, 7447, 8190. `include/` holds only the declaration (RemeshPipeline.h:778).
- Q5: the census states correctly that the new suffix was measured on 3 of the 10 rows.
- Credit: the census declined to design a rule and named the probes it would need.

## RA-124.2 Corrections to the census

1. **§1 "Selection is per occurrence, not per side" is wrong.** The face is selected per node and only published per occurrence (RA-123.3; RA-124.3 P1).
2. **§1 annulus anchor.** SCT:14502 is the candidate table; the published gauge write is SCT:14596–14615.
3. **§2 omits a producer.** The annulus producer never writes `branchRotation`: only SCT:13419 and SCT:17757 write it (verified by search). Annulus corners therefore keep the default 0 (SurfaceCellTracing.h:1278), while the gauge table holds per-face values.
4. **§2 "residual offsets not statically proven".** The residual can be derived statically for each producer (P3 below). Only *which* producer built region 0 is a runtime fact.
5. **§2 answers the wrong question.** It answers the `(1,0)→97/2` question at A5 (the face clause), but the question asked about A6's turn check.
6. **§4 misattributes the rule.**
   - `point_on_periodic_chart` is shared by the annulus (SCT:15076) and curved (SCT:17636) producers, not used by the curved one alone.
   - The key comparison lists 3 of vertex 61's 6 faces, omitting 118 `[49,59,61]`, 119 `[59,61,71]` and 142 `[0,61,71]`. Face 121's key `[0,1,61]` is still the least, so the conclusion stands.
   - Missed inference: the uniform producer's minimum-row rule would pick 97 (RA-72.6), so the observed 121 is evidence against the uniform producer for region 0.

## RA-124.3 Finding — the certified-seam contract cannot pass on produced data (static proof)

- **P1 Shared node.**
  - An OrdinaryFront endpoint pair is (the first cell's side start, the second cell's side end) on their shared front edge (RP:4943–4947).
  - Every producer copies one node point into both corners: uniform SCT:13404–13405, annulus SCT:15115–15116, curved SCT:17741–17742.
  - A2 takes `selectedFace` from that point (RP:4448–4458).
  - So both occurrences of an OrdinaryFront relation inside one producer grid carry **the same** `selectedFace`.
- **P2 The A5 seam branch is dead code.**
  - Forward and Reverse each need one span on the certificate's first face and the other on its second face (RP:3855–3875, 3896–3910).
  - The face clauses (RP:3891–3892) require each span's face to equal its own occurrence's `selectedFace`.
  - With equal `selectedFace`s, that demands the first and second faces be equal. That is impossible, because the sheets must differ (RP:3893) and each face row has one sheet.
  - Hence `certified_seam_direction` always returns no direction for a shared-node relation, and RP:5249 rejects **every** certified collinear-seam OrdinaryFront any producer emits. A5-ISO is an instance of this, not a special case.
- **P3 The A6 stripped turn is degenerate.** A6 computes regional = gauge(selectedFace)⁻¹ ∘ branchRotation (RP:5859–5868). By producer:
  - uniform: branch = gauge (SCT:13419–13420, 13579), so regional is always 0;
  - curved: branch = gauge + `chartUBranch`, a single value per region (SCT:16831, 17757–17759, 18037), so regional is always `chartUBranch`;
  - annulus: branch is never written, so regional = −gauge(face).

  For shared nodes, all three give a stripped turn of identity. For any two occurrences of one uniform or curved region, it is identity whatever faces are chosen.
- **Consequence for frozen RA-30a.3 (D3).** D3 requires "face-gauge-stripped branch difference == certificate quarter-turn". It is satisfiable only when the certified turn is identity, or under annulus by a gauge coincidence that reads no lattice data.
- **Corollary 1.** For shared nodes, A6's non-seam OrdinaryFront equalities (chart, branch, coordinate, phase) compare one node's lattice with itself: they are tautological.
- **Corollary 2.** The positive D3 witnesses `cp3entry:3` and `cp3entry:5` are RED with "produced no fully certified reciprocal cross-sheet OrdinaryFront" (TB21 inventory), which P2 predicts. They are filed as "adjacent-sheet helper" fixture debt; this finding contests that filing.
- **No produced seam relation has ever passed A5 and A6 together.**

## RA-124.4 Realignment

- **RA-123.6 amended.** The A2 per-node representative contributes, but the defect is the seam contract: the A5 face clauses plus frozen D3, set against shared-node producers. A per-occurrence representative would satisfy P2, but P3 would then decide the outcome. RA-72.5 applies: relocation is not repair.
- **Two contract families remain:**
  - **(i) Amend D3 for the continuous frame.**
    - Coordinate-identity transport.
    - A stripped difference of identity.
    - The certified turn checked against the gauge jump `g(second face) − g(first face)`, which is chart evidence (RA-2).
    - A5 side authority from wedge bindings, which `certified_seam_wedge_side` already checks, rather than node-face equality.
  - **(ii) Producers publish per-side representatives** with sheet-relative gauges, leaving D3 unchanged.
- **The deciding fact.** Family (i) is admissible only if the published gauge jump at the seam equals the certificate turn. If it does not, the producer gauge table owns the defect. A frozen definition is not amended on a guess (LESSONS §5).

## RA-124.5 Successor `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE` (Code + Build, compile only)

- **RP:** inside the relation-collinear-seam block, after the `spanOnlyN` loop and before `error.isolationSite = std::move(site);`, append in this order:
  1. `;branch=<a>,<b>`: each canonical occurrence's `placement.lattice.branchRotation`;
  2. `;gaugeSel=<a>,<b>`: `sourceFaceBranchRotations()[row(selectedFace)]`, or `none`;
  3. `;gaugeSpan=<a>,<b>`: the same at each canonical span's `interiorBinding.face`, or `none`;
  4. `;turnN=<f>,<r>`: for each matching certificate in `certN` order, `forward().value()`,`reverse().value()`.
- **TQ:** in the A5 branch of `m6cp3_produced_seam_fixture` (TQ:2756–2762), record `a5_rejection_message(a5Construction)` (TQ:960) instead of the bare error name.
- **Invariants:**
  - no decision, return, error-code or assertion change;
  - existing site text is appended to only;
  - every other file is byte-identical;
  - no line over 100 columns.
- **Build and record:** compile the eight targets with GMP/GMPXX and `runtimeExecution=false`. Write `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Code_Build_Record_20261021.md` (at most 30 lines).
- **STOP** on any compile error or any need to edit outside those two hunks.

## RA-124.6 TB25 frame (to be frozen at CB24-REV)

**Rows (11):**
- A5 rows: `focused30:20` (W/P), `selector:444` (T/P), `focused30:28` (T/D);
- D3 witnesses: `cp3entry:3`, `cp3entry:5`, with full assertion messages;
- guard: `selector:447`;
- controls: `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`.

**Routing, pre-registered; read both occurrences:**
- **Producer signature:** `branch − gaugeSel` is 0 for both (uniform); equal to some c ≠ 0 for both (curved); or `branch` is 0 while a gauge is non-zero (annulus).
- **P3:** the stripped turn computed from these values is identity.
- **Gauge jump.** Let d = `gaugeSpan(second) − gaugeSpan(first)` mod 4 and F = `turn0` forward:
  - F = 0 → D3 is satisfiable, and family (i) reduces to A5 side authority;
  - F ≠ 0 and d = F → family (i) is admissible, and D3 must be amended;
  - d ≠ F → the producer gauge table owns the defect.
- **`cp3entry:3/5`:** if any candidate records `relation-collinear-seam`, they join the seam family; otherwise they stay fixture debt at the recorded stage.

## RA-124.7 Sequence and accounting

- **Sequence:** CB24 → CB24-REV → TB25 → TB25-REV → DEFN-SEAM (the seam contract for the shared-node model, per TB25's routing) → DEFN-SEAM-REV → corrective CB → CB-REV → TB → TB-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | The census inventory, re-run; P1–P3 from the cited RP/SCT lines; the `branchRotation` writer search; vertex 61's face keys |
| Non-vacuity | P2 and P3 are proofs over every producer; TB25 measures the one runtime fact (d against F) |
| Obligations | RA-123.7 discharged; RA-123.6 amended; DEFN-ISO-B withdrawn; RA-30a.3 (D3) challenged, not amended |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index, LESSONS |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
