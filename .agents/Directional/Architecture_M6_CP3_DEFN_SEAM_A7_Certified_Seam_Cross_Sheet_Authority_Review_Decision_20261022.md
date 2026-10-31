# RA-130 — DEFN-SEAM-A7 review: accepted with binding amendments; CB26 authorized (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV`.

**Verdict:** the contract `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` is **accepted with amendments**.
- **Accepted:** its consumer census of the source, its proof that `relationCertified` can hold, its core rule (certified seams replace only `occurrenceCertified`), and its diagnostic.
- **Missed:** the frozen test that already pins A7's behaviour on this relation.
- **Defects:** the rule duplicates a predicate, binds spans in an order nobody checks, and accepts any connecting transition where the certificate's own is required.
- Amendments B1–B6 are binding on CB26 and TB27. CB26 is authorized: RP plus one diagnostic line in the TQ helper, compile only.

## RA-130.1 Verified

- **§1 census:** A6, A7 per-member, A7 forest edges and A8 verification are the only places that decide cross-sheet admissibility. The emitted-geometry union (RP:7641) does not decide anything.
- **§2 `relationCertified` can hold.** Span transitions are unioned into each side's `isolationEvidence` (RP:4444–4448), which A5 copies into `first/secondSideIsolationEvidence` (RP:5213–5219, swapped with canonical order at RP:5226–5234). A6 requires the forward and reverse transitions in the endpoint spans (RP:5856–5867).
- **§3.1, §3.2, §3.4:** the scope is correct, Periodic relations and OrdinaryFront relations without a certificate are unchanged, and `occurrenceCertified` is replaced only for certified seams. This agrees with RA-34.1: one Forward/Reverse match used throughout, and A7 checks its own conditions.
- **§4:** the site suffix is correct. `geometry_embedding_failure_name` exists for the helper (header line 1419).

## RA-130.2 B1 — the frozen D7 witness is the governing oracle (missed by the audit)

- **What the test requires.** `cp3entry:5` (`M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`, TQ:3977–4056) implements RA-33.4/RA-34's D7 falsifier:
  - **positive:** A7 must produce geometry for the untampered certified seam relation with disjoint endpoint sheets (TQ:4021–4025);
  - **tamper:** clearing `firstSideIsolationEvidence`, `secondSideIsolationEvidence` and `equivalence.isolationTransitions`, while keeping the spans and certificate, must make A7 reject with code `UncertifiedCrossSheetBinding` and site **exactly `cross-sheet`** (TQ:4027–4055).
- **What this means.** The current A7 code contradicts an architecture-level witness, not just a new contract. §1 dismissed tests as "not admission sites", and RA-129 also missed this.
- **Binding:**
  - in the certified-seam branch, failure of the relation-evidence check keeps site `cross-sheet`;
  - TB27 reports the D7 tamper outcome as a falsifier, alongside the D3 tamper.
- **Correction to §6:** the D3 tamper in `cp3entry:3` rotates the second endpoint's face gauge by a quarter turn. It does not tamper a certificate.

## RA-130.3 B2 — bind spans to the relation's canonical endpoints

- **Why.** A7's forest-edge loop takes `first`/`second` from `edge.first`/`edge.second` (RP:7548–7549). A7 never checks that order against `relation.id` (RP:7191–7204). A6 happens to publish canonical order (RP:5999), but A7 should not depend on that.
- **Binding:** call `certified_seam_direction` with the occurrences `relation.id.first`/`relation.id.second` and `relation.evidence.firstEndpointSpan`/`secondEndpointSpan`.

## RA-130.4 B3 — delete §3.3's explicit pair and binding equality

- **Why.** `certified_seam_direction` returns `Forward` only when `certified_seam_wedge_side` has already required, for each span, all of the following:
  - the certificate's face on that side;
  - the matching certified sheet;
  - membership of the binding in that occurrence's `cornerWedgeBindings` (RP:3855–3875);

  and symmetrically for `Reverse`. So the explicit check in §3.3 is exactly implied by the function.
- **Binding:** do not write that check. A second copy is the drift hazard RA-127.3 already had to repair once.

## RA-130.5 B4 — the A7 evidence check must use the certificate's own transition

- **Why.** In the certified branch, the DEFN keeps `relationCertified` as "any transition connecting the endpoint sheet sets". That would let a transition on an unrelated seam that happens to join the same sheets certify the crossing. RA-32/RA-34 forbid this: certificate- and relation-owned seam evidence selects the path, not global sheet labels.
- **Binding:** in the certified branch, the relation evidence (the three lists) must contain the transition `{certificate.region(), certificate.seam(), side-1 sheet, side-2 sheet}`, in either orientation, with the sheets ordered as the direction selects. On producer data this is satisfied: A6 requires that very transition in the endpoint spans, with `collinearEdge` equal to `certificate.seam()`, and the spans feed the side evidence.

## RA-130.6 B5 — make every cross-sheet rejection identifiable

- **Why.** Six A7 checks share one code, and the plain `cross-sheet` site would cover three different causes. TB27 has to tell them apart. No test asserts the new labels; TQ asserts only `cross-sheet` (D7), `cross-sheet:hard-rail` and `cross-sheet:wedge`.
- **Binding sites:**

| Case | Site |
|---|---|
| Certified branch, no direction | `cross-sheet:seam-direction` |
| Certified branch, evidence check (B4) fails | `cross-sheet` (pinned by D7) |
| OrdinaryFront without a certificate, existing rule fails | `cross-sheet:no-certificate` |
| Periodic, existing rule fails | `cross-sheet:periodic` |

## RA-130.7 B6 — Periodic is a latent defect, recorded but out of scope

- RA-129.3's impossibility proof does not depend on the relation kind. A Periodic edge with disjoint endpoint sheets also always fails `occurrenceCertified`.
- No witness exists yet. B5's `cross-sheet:periodic` will show one if it occurs, and then it routes to Review. No Periodic change is authorized.

## RA-130.8 Successor `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` (Code + Build, compile only)

1. **RP, A7 forest-edge branch (RP:7543–7603).** For an OrdinaryFront edge with disjoint sheets and a typed `isolationSeamTransportCertificate`:
   - compute the direction per B2;
   - if none, reject with site `cross-sheet:seam-direction`;
   - otherwise run the B4 evidence check, and reject with site `cross-sheet` if it fails;
   - `occurrenceCertified` is not evaluated in this branch.
   - All other cases keep today's predicate, with the B5 labels.
2. **RP, failure mapping (RP:9276–9280):** append `":" + site` to `result.failure` for `UncertifiedCrossSheetBinding` when the site is not empty.
3. **TQ, D3 helper (TQ:2811):** record `"A7:" + geometry_embedding_failure_name(code) + ":" + site`. No other TQ edit.
4. **Limits:** no change to A5, A6, per-member A7 checks, A8, headers, selectors or workflows. No B3 duplicate. Lines at most 100 columns.
5. **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Code_Build_Record_20261022.md` (at most 30 lines).

**STOP** on a compile error, on any need to edit outside the four places above, or if B4 cannot be stated from data A7 already has.

## RA-130.9 TB27 plan (issued at CB26-REV) and sequence

- **TB27 selections:** the 18 TB26 selections plus three A7 site guards:
  - `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition` (TQ:10000);
  - `M6CP2.A7WedgeTransitionWrongRegionRejects` (TQ:11196);
  - `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects` (TQ:11256).
- **Falsifiers:**
  - any of the eight still rejects with `cross-sheet:seam-direction`;
  - the D7 tamper passes or changes site;
  - the D3 tamper passes;
  - any control or guard turns RED;
  - a `cross-sheet:periodic` site appears (route under B6).
- **Not falsifiers:** a new first failure is measured, not assumed green.
- **Sequence:** DEFN-SEAM-A7-REV (this) → **CB26** → CB26-REV → TB27 → TB27-REV → CB27 (negative tests, TQ only: RA-127.4b plus A7 unrelated-seam evidence and no-direction) → CB27-REV → TB28 (new tests plus a selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` waits for a witness, and the Periodic follow-up (B6) waits for one too. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Side-evidence dataflow (RP:4444–4448, 5213–5234); forest-edge order (RP:5999, 7191–7204); wedge-side implication (RP:3855–3875); D7 test body (TQ:3977–4056); site assertions in TQ; RA-34.1 |
| Non-vacuity | D7 positive and tamper plus D3 tamper are named falsifiers; three site guards added |
| Obligations | RA-129.4 discharged; RA-127.4 (iii) and D7 carried to TB27; RA-127.4b and A7 negatives carried to CB27; B6 registered |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
