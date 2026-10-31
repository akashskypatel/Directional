# RA-127 — DEFN-SEAM review: accepted with two binding amendments; CB25 authorized (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV`.

**Verdict:** the contract `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` is **accepted with amendments**.
- Its scope, its non-weakening table, the decision to leave A6/D3 unchanged and the deferral of nonzero-turn seams are correct.
- Its shared-node predicate is too weak, and its enforcer table misses a second copy of the clauses.
- Amendments A1–A4 are binding on CB25. CB25 is authorized: RP only, compile only.

## RA-127.1 Verified

- RP is byte-identical to the CB24 source `dae267a82`, so every anchor in the contract holds at HEAD.
- **§1** keeps every clause except the two face equalities, only for shared-node pairs. Direction still comes from `certified_seam_wedge_side` (wedge membership and certified sheet, RP:3855–3875), with opposite sides. Certificate uniqueness stays in `seam_transport_certificate` (RP:4695).
- **§2** is right that A6's source is untouched. Its gauge-face check (RP:5869–5870), the D3 check (RP:5887–5905) and the second evaluation of `certified_seam_direction` (RP:5878) all still apply.
  - **Correction:** "A6 byte-semantically unchanged" overstates it. Through the shared function, A6 stops rejecting shared-node pairs as `InvalidIsolationEvidence` (RP:5881–5885), and D3 then becomes their binding guard. That is the intended effect, but the contract must say so.
- **§3:** the non-weakening table covers every independent rejecting clause.
- **§4:** treating the next first failure as a measured outcome is correct.

## RA-127.2 A1 — "equal support and equal selectedFace" does not identify a node

- **The problem.** `SourceEdgeSupport` holds only `edge` (`SourceSupport.h:23–26`), and a face-interior support only its face. For edge- or face-supported corners, two different points on the same edge or face with the same selected face satisfy the contract's `sharedNode`. That contradicts its own requirement that a shared node be a canonical identity, not geometry.
- **The fix.** The predicate must also require equal `placement.lattice.latticeCoordinate`, which is exact integers.
- **No effect on producer data.** In all three producers, node indices do not wrap (`v * columns + u`; SCT:13317, 15071, 17585). Each cell corner takes its coordinate from the same (u+du, v+dv) offsets as its node id (SCT:13424–13427 uniform, 15119–15121 annulus, 17752–17756 curved). So two cells sharing a node always agree on its coordinate.
- **No new authority.** A6 already rejects any OrdinaryFront pair whose lattice coordinates, scale or phase differ (RP:5748–5766). So A5 only stops admitting pairs that A6 would reject anyway.
- **Binding definition:** `sharedNode` ⇔ equal `support`, equal `placement.selectedFace`, and equal `placement.lattice.latticeCoordinate`.
- **Reading TB26.** After CB25, a `first-face`/`second-face` label on a site whose `support` and `sel` tokens are equal can only mean the lattice coordinates differ. That falsifies the producer argument above; route it to Review.

## RA-127.3 A2 — the rejection-site classifier must mirror the amended rule

- **The problem.** The relation rejection site (RP:5303–5333) re-implements the face clauses on its own (`first-face`, `second-face`). Only its pass count calls `certified_seam_direction` (RP:5293).
- **The consequence.** If only the function changes, a shared-node pair rejected for another reason (same side, span outside the wedge) is mislabelled `first-face`. That breaks the mirror of `certified_seam_direction` accepted at RA-118.2, and future harvests would be misread.
- **The fix.** CB25 applies the same shared-node exemption to the classifier, in the same commit. This is diagnostic only.
- **Correction to §2:** at RP:5293, the pass count reflects the new predicate; the per-certificate clause labels follow it only once A2 is in.

## RA-127.4 A3 — the decisive positive witnesses must be named

- `cp3entry:3` and `cp3entry:5` are the frozen D3 identities, `OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition` and `ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition` (TQ:3613, TQ:3977).
- Once A5 admits their shared-node seam relation, they are the **first exercise of A6's seam branch on producer-built relations**. `cp3entry:3` includes the D3 tamper: rotating the second endpoint's face gauge by a quarter turn must reject as `RelationCertificateConflict` (TQ:3652–3677).
- **TB26** must report, for these two rows:
  - whether the search helper now finds a certified reciprocal cross-sheet relation;
  - whether A6 admits the untampered relation, which needs stripped turn = identity = F;
  - whether it rejects the tampered one.

  A tamper that passes falsifies the contract (F2).

## RA-127.4b A4 — test coverage of the new branch is owed

- The amended predicate needs direct negative tests before the RP-01 Review can accept the change:
  - a shared node with the span outside its wedge;
  - a shared node with both spans on the same side;
  - edge-supported corners on the same edge and face but with different lattice coordinates (the A1 case).
- These are test-only and belong in their own CB (CB26) after TB26. CB25 stays a source-only change.

## RA-127.5 Successor `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (Code + Build, compile only)

**Base:** HEAD (RP identical to `dae267a82`). Edit RP only:

1. In `certified_seam_direction` (RP:3880–3911), compute `sharedNode` per A1. When it holds, skip the two face-equality clauses (RP:3891–3892). Every other clause and the side logic are unchanged.
2. In the rejection-site classifier (RP:5303–5333), apply the same `sharedNode` exemption to the `first-face` and `second-face` labels (A2). Keep the existing site text format.
3. Share one helper between (1) and (2), so the rule exists once.
4. Write no other change, especially none to A6, A2, the header, TQ or other files. Lines at most 100 columns.
5. Compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Code_Build_Record_20261022.md` (at most 30 lines).

**STOP** on a compile error or any need to edit outside RP, or if the classifier cannot use the shared helper.

## RA-127.6 Sequence and accounting

- **Sequence:** DEFN-SEAM-REV (this) → **CB25** → CB25-REV → TB26 (12 A5-ISO rows with the A3 reporting, guard `selector:447`, TB25 controls) → TB26-REV → CB26 (A4 negative tests, TQ only) → CB26-REV → TB27 (new tests plus a selector-497 census) → TB27-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` waits for a nonzero-turn witness; `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | RP anchors at HEAD; orientation mapping and uniqueness (RP:3880–3911, 4686–4702); support-identity types; producer node indexing and coordinates; classifier duplication; A6 lattice-equality check and direction-failure code; D3 identities and tamper |
| Non-vacuity | A3 names the first runtime exercise of A6's seam branch and its tamper falsifier |
| Obligations | RA-126.4 discharged; A1–A4 binding on CB25/TB26/CB26 |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
