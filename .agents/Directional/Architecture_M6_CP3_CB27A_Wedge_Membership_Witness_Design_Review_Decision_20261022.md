# RA-135 — CB27A design block resolved: isolate wedge membership by withdrawing a real binding from the multi-binding endpoint (2026-10-22)

**Turn:** `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-DESIGN-REV`. **Input:** CB27A `BLOCKED` (`45d9da85a`); CB27-REV (`Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`).

**Verdict:** the block is real only under CB27-REV's two self-imposed constraints:
- mutate the **first** endpoint;
- mutate the **span binding**.

Neither is required by the predicate under test. A discriminating, source-derived witness exists. **CB27A resumes** (test-only, TQ only) with the construction below. CB27-REV's other findings stand: three negatives discriminating, same-side not constructible from D7.

## RA-135.1 Why CB27A could not succeed as specified

- `CornerWedgeFaceBinding` is `{face, sheet, chart}` with full equality (`RemeshPipeline.h:769–775`). `certified_seam_wedge_side` (RP:3855–3875) accepts a span binding only if all three of these hold:
  - its face is a certificate side face;
  - its sheet is that side's sheet;
  - the *whole triple* is in the occurrence's `cornerWedgeBindings`.
- **The D7 witness's first wedge has a single binding.** TB25's `cp3entry:3/5` sites show `wedge=0/0,2/1+3/1` with certificate `0/0->3/1`. The first span's binding `0/0` is the first wedge's only member. So:
  - a binding with the same face and sheet outside the first wedge must be synthetic (a fabricated chart);
  - removing `0/0` empties the wedge, so A7 rejects earlier at `cross-sheet:wedge` (RP:7496–7500).

  Both routes are invalid, so the STOP was correct for the first endpoint.

## RA-135.2 The construction — withdraw, don't substitute

**The membership clause is symmetric.** Both endpoints pass through `certified_seam_wedge_side`. The **second** endpoint's wedge `{2/1, 3/1}` has two bindings on sheet 1, and its span binds the certificate's second face `3/1`.

**Tamper:** in `records.occurrences`, remove exactly the second span's `interiorBinding` (`3/1`, with its real chart) from the second occurrence's `cornerWedgeBindings`. Change nothing else: no span, relation, certificate, sheet list, transition or placement.

**Why only membership changes:**
- **Republishing passes.** `publish_records_for_validation` (RP:3708–3830) checks only cell, corner, occurrence and relation-endpoint structure, never wedge bindings.
- **A7's per-member checks still pass:**
  - support, point and component (RP:7423–7490) read `point`/`support`, not bindings;
  - the bound-sheet set `{1}` still equals `cornerWedgeSheets` `{1}` (RP:7496–7500);
  - a single-sheet wedge is connected (RP:7505–7535);
  - `charts` only feeds the emitted vertex (RP:7491, 7686).
- **In `certified_seam_direction`:**
  - the shared-node triple is unchanged, so the face clauses stay exempt;
  - collinear edge, region and distinct sheets are unchanged;
  - first side = First, membership intact;
  - second binding face `3` = `secondFace`, sheet `1` = `secondSheet`, so it classifies as Second, opposite to the first;
  - **only** `std::find(... cornerWedgeBindings ...)` fails → `nullopt`.
- **B4 is unaffected.** The relation evidence still holds the certificate transition. So with the membership clause deleted, the direction is `Forward`, B4 passes, and A7 **accepts**. That is the counterfactual CB27-REV requires, and it holds without touching production code.

**Expected results:**
- **A6** on the tampered A5: `InvalidIsolationEvidence` (RP:5893–5898). No earlier A6 check reads wedge bindings (RP:5740–5890).
- **A7** with the original A6 product: `UncertifiedCrossSheetBinding`, site `cross-sheet:seam-direction`, with locus occurrence `relation.id.first` (A7's `fail(…, edge.first, …)` at the certified branch).

## RA-135.3 Binding in-test preconditions (the counterfactual, made checkable)

Before the tamper:
- **(P1)** The chosen endpoint's span binding is in its wedge.
- **(P2)** The wedge has at least two bindings, and another binding has the same sheet.

After the tamper:
- **(P3)** The binding is absent from that wedge, and the wedge's sheet set equals `cornerWedgeSheets` and is unchanged.
- **(P4)** `support`, `placement.selectedFace` and `placement.lattice.latticeCoordinate` are equal across both endpoints.
- **(P5)** Classified by face and sheet only, with a test-local function that does not check membership, the endpoint sides are opposite (First/Second).
- **(P6)** The relation evidence contains `{certificate.region(), certificate.seam(), sheets}` in either orientation.

Endpoint choice and locus:
- **Endpoint choice is deterministic:** the first endpoint if P1–P2 hold for it, otherwise the second. If neither qualifies, STOP and record the endpoint wedge contents.
- **Locus:** A7's failure `occurrence` equals `relation.id.first`, so the rejection belongs to the tested relation and not to another relation of the tampered occurrence.

The helper `check_d7_certified_seam_negative` may gain an **optional** expected-locus argument (default: unchecked), so the other three negatives stay byte-identical in behaviour.

## RA-135.4 Scope of the resumed CB27A

- **Replace** `CertifiedSeamRejectsSpanBindingOutsideEndpointWedge` (TQ:4266–4286) with `CertifiedSeamRejectsSpanBindingWithdrawnFromEndpointWedge`, implementing RA-135.2–135.3. The old test rejects at membership and would also reject at same-side, so it does not discriminate either predicate.
- **Preserve:** the unrelated-seam, no-certificate and lattice negatives; the D3/D7 positives; the same-side comment, updated to cite RA-135.1.
- **Limits:** TQ only, no production or other-file change. Compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Code_Build_Record_20261022.md` (at most 30 lines).

**STOP and return to Review if:**
- neither endpoint satisfies P1–P2;
- any precondition fails at compile-time reasoning;
- a production change would be needed;
- an assertion would have to be weakened.

## RA-135.5 Sequence and accounting

- **Sequence:** design review (this) → **CB27A (resumed)** → CB27A-REV → CB28 (RA-134.5 diagnostic messages) → CB28-REV → TB29 → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
  - TB29 runs CB27/CB27A's four negatives, D3/D7, the three A7 guards, the 21 silent rows and the four wrong-code rows.
  - `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Binding identity (header 769–775); side and membership logic (RP:3855–3934); republish validation scope (RP:3708–3830); A7 per-member gates and `charts` use (RP:7423–7535, 7686); A6 pre-direction checks (RP:5740–5898); D7 wedge contents (TB25 sites); helper signature (TQ:4065–4141) |
| Non-vacuity | A one-binding difference between the accepted positive and the rejected tamper; P1–P6 make the only failing clause checkable in-test |
| Obligations | CB27-REV's fourth-oracle obligation now has a valid witness design; RA-134.5 CB28 still queued |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
