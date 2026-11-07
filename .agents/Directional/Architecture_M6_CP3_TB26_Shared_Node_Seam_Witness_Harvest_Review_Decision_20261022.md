# RA-129 — TB26 review: A5 and A6 now admit the shared-node seam; A7's cross-sheet rule is the next blocker (2026-10-22)

**Turn:** `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST-REV`.

**Verdict:**
- TB26 is **accepted** as diagnostic evidence.
- Its report's A6/D3 conclusion is **corrected**: A6 *did* admit the untampered certified seam relation; only the tamper went unreached.
- All nine RED rows now stop in **A7**, and A7's OrdinaryFront cross-sheet rule is provably unsatisfiable for the relations CB25 now admits.
- Successor: documents-only **DEFN-SEAM-A7**. No promotion; accounting unchanged.

## RA-129.1 Harvest verified independently

- **Artifact:** `12403479548` (run 39727886868). The provider digest equals the local ZIP SHA-256 `3f7df8c2…ac2d`; it expires 2026-10-29T05:26:45Z.
- **Manifests:** **21/21** entries check. The execution record shows source `c5e0b242f`, package `12399179446`, 18/18 executed, 9 PASS / 9 RED, `control_bad=0`, postflight true, and no compile, relink or benchmark.
- **Logs:** each of the 18 logs has exactly one `[ RUN ]`. The six guard and control rows PASS, and `focused30:26, 27, 28` PASS.

## RA-129.2 Where each RED row stops

| Rows | Evidence in log | Stage reached |
|---|---|---|
| `focused30:6, 20, 25`; `selector:444, 446, 448` | `UncertifiedCrossSheetBinding`; row 25 shows `firstStage=tracing/phase-front-materialization` | A7. The code exists only in `GeometryEmbeddingFailureCode` (RP:7103), and the pipeline maps A7 errors to that name (RP:9276) |
| `focused30:24` | A5 and A6 assertions pass; `a7 == nullptr` at TQ:6024 | A7; code not printed |
| `cp3entry:3, 5` | `A7:rejected-certified-seam` at all sizes 0.25, 0.5 and 1.0 | A7, after A5 and A6 (below) |

**Correction to the TB26 report.** The helper `m6cp3_produced_seam_fixture` (TQ:2725–2814) records `A7:rejected-certified-seam` only after all of the following:
- A5 produced a certified OrdinaryFront seam relation with a typed seam certificate, and its endpoints' wedge sheets do not overlap;
- A6 produced its product and selected that relation in its forest;
- A7 then rejected.

A6's seam branch (RP:5804–5905) checks the reciprocal span transitions, both gauges and D3 for every relation with a certificate. So:
- **RA-127.4 (i) and (ii) are discharged** in all six searches: A5 finds a certified reciprocal relation, and A6 admits it untampered, which requires stripped turn = expected turn.
- **(iii), the D3 gauge tamper, is still unmeasured.** The test asserts that the helper returned a fixture before it reaches the tamper, and the helper needs A7 to succeed.

## RA-129.3 Root cause: A7 cannot certify a cross-sheet OrdinaryFront relation (static proof)

A7 (`SourceAttachedGeometryProducer::produce`, RP:7120) handles OrdinaryFront and Periodic forest edges at RP:7543–7603. When the endpoints share a wedge sheet, A7 accepts. When they share none, it requires both `relationCertified` and `occurrenceCertified`.

- **`occurrenceCertified` is never true when the sheets are disjoint.** An occurrence's `cornerWedgeIsolation` holds only transitions crossed while walking its own wedge, and every transition joins two of that wedge's own bindings (RP:4555–4661; the walk starts by pushing `outgoing`). So each transition's two sheets both belong to that occurrence. When the first and second endpoints share no sheet, no transition can join them.
- **So A7 rejects every cross-sheet OrdinaryFront edge it checks.** Before CB25 none reached A7, because A5 rejected them all (RA-124.3 P2); CB25 opened A5 and the rejection moved here. This is the same structural defect: a later stage re-derives cross-sheet authority from per-occurrence data that cannot carry it, and ignores the typed A4 seam certificate that A5 selected and A6 checked with D3.
- **What is measured and what is not.** 8 of 9 rows report the A7 code, and `focused30:24` fails at A7. But A7 publishes no site label (RP:9276), and six A7 checks share this code. That the cross-sheet check fires first is a strong inference, not a measurement.

**Review ownership.** RA-127 accepted an enforcer table that listed only the callers of `certified_seam_direction`. It did not audit stages that re-derive cross-sheet admissibility on their own. That breaks LESSONS "Keep definitions and their validation mutually traceable" (every implementing consumer). The A7 consumer is attributed to this Review's miss, not to CB25, which implemented RA-127 exactly.

## RA-129.4 Successor `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` (documents only)

**Deliverable:** `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md`, at most 90 lines, anchored at HEAD. It must contain:

1. **Consumer audit, required first.** List every stage after A5 that decides whether a relation may join two different isolation sheets: A6 (RP:5804–5905), A7 (per-member wedge checks RP:7423–7541; forest edges RP:7543–7603), verification (`a5:wedge-bindings` and `a5:wedge-isolation`, RP:8240–8290), and any other site found by searching for `cornerWedgeSheets`, `cornerWedgeIsolation`, `isolationTransitions`, `SideIsolationEvidence` and `isolationSeamTransportCertificate`. For each, give its predicate on a shared-node certified seam relation, and say whether it passes, rejects, or cannot be decided statically.
2. **`relationCertified` analysis.** Say whether it can hold for these relations, using RP:5214–5233 and the side authority of front edges collinear with a seam.
3. **Amended A7 rule.** For an OrdinaryFront forest edge with disjoint endpoint sheets **and** a typed seam certificate:
   - the crossing is certified only if `certified_seam_direction` (the same function as A5 and A6, given the relation's endpoint spans and certificate) returns a direction;
   - the endpoint sheets must equal the certificate's sheets on the sides that direction selects.
   - A7 must not re-derive the side and must not use sheet labels without the certificate.
   - Relations without a certificate, and all Periodic relations, keep the existing rule.
4. **Diagnostic.**
   - For `UncertifiedCrossSheetBinding`, append A7's existing `site` to `result.failure`, as is already done for `:support-point` (RP:9276–9280). No test compares the exact string.
   - The D3 helper records the A7 code and site in place of the bare `A7:rejected-certified-seam`.
5. **Non-weakening table.** Cases that must still reject:
   - a disjoint-sheet edge with no certificate;
   - a certificate whose sheets do not match the endpoints on the selected sides;
   - the endpoint spans failing `certified_seam_direction`;
   - Periodic relations with disjoint sheets (unchanged);
   - a wrong region;
   - per-member wedge checks that fail.
6. **Predictions and falsifiers for TB27.**
   - The 8 rows that report `UncertifiedCrossSheetBinding` get past A7's cross-sheet check.
   - `focused30:24`'s A7 code becomes visible.
   - `cp3entry:3/5` reach the D3 tamper, which must reject as `RelationCertificateConflict`; a tamper that passes falsifies the contract.
   - The next first failure is measured, not assumed.
   - All controls stay PASS.

**Out of scope:** any code, compile or runtime change; changes to A5, A6 or D3; nonzero-turn seams; Periodic cross-sheet semantics; DIAG-RETAIN.

**STOP** and return to Review if the audit finds a further consumer that cannot be stated without changing A6, or if `relationCertified` cannot be decided statically.

## RA-129.5 Sequence and accounting

- **Sequence:** TB26-REV (this) → **DEFN-SEAM-A7** → DEFN-SEAM-A7-REV → CB26 (RP: A7 rule and failure-site suffix; TQ: helper record only) → CB26-REV → TB27 (the same 18 selections) → TB27-REV → CB27 (negative tests for RA-127.4b and the A7 table; TQ only) → CB27-REV → TB28 (new tests plus a selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` waits for a nonzero-turn witness; `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **`focused30:26–28` PASS** are individual witnesses only, with no family credit until the census.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 21/21 manifest; 18 logs (one RUN each); failure lines; A7 code ownership (RP:7103, 9276); helper control flow; A6 seam-branch checks; the `occurrenceCertified` proof |
| Non-vacuity | A6 seam branch exercised on producer data in six searches; D3 tamper still unmeasured and carried |
| Obligations | RA-127.4 (i)/(ii) discharged, (iii) carried to TB27; RA-127.4b carried to CB27; this Review's own audit miss recorded |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
