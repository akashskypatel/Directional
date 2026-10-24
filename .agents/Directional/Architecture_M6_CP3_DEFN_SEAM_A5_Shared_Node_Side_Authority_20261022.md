# DEFN-SEAM — A5 certified-seam shared-node side authority (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (definition only). **Review authority:** RA-126.4, RA-124.3 P1–P3; semantic source inspection: snapshot `7efc2ded291091e045b59c154dd6a00f64748fa6`. **Next:** mandatory independent `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV`; no code or runtime acceptance is authorized by this document.

## 1. Amended A5 rule (RP:3855–3911)

`certified_seam_direction(firstOccurrence, secondOccurrence, firstSpan, secondSpan, certificate)` shall use the following decision, restricted to a certified collinear-seam `OrdinaryFront` relation:

1. Define `sharedNode` **only** when the canonical occurrences have equal `support` **and** equal `placement.selectedFace`. This is an occurrence-pair property, not geometric proximity, same source sheet, or a new source-vertex certificate. The producer copies one node into both ends of the shared front edge (RA-124.3 P1).
2. For `sharedNode`, do **not** require `firstSpan.interiorBinding.face == firstOccurrence.placement.selectedFace` or `secondSpan.interiorBinding.face == secondOccurrence.placement.selectedFace` (the existing RP:3891–3892 face-equality clauses). The per-node representative is not the authoritative **side** for a seam-spanning relation.
3. For **non-`sharedNode`** pairs, retain **both** existing face-equality clauses without relaxation.
4. In both branches, keep the existing shared seam/collinear-edge equality, region agreement with the certificate, distinct certified sheets, exact wedge-binding membership and typed sheet match in `certified_seam_wedge_side`, and strict opposite-side requirement. `First→Second` means `Forward`; `Second→First` means `Reverse`; any absent, `NotOnSeam`, same-side, invalid, or ambiguous direction rejects.
5. A4 is still the only source of certificate face orientation and `forward()`/`reverse()` transforms. No sheet label, face-row minimum, per-node representative, or local branch is allowed to invent orientation. A certificate must already exist and uniquely match: no certificate or two admissible certificates rejects.

**Scope precision:** this is a removal of two *redundant/incompatible per-node face-equalities* only for a pair that is already one shared node. It is **not** permission to remove any independent gauge-face guard, relabel a sheet, alter transport, fabricate a certificate, or admit arbitrary collinear spans. The shared-node equality must be checked on canonical identities; a coincident world-space position is insufficient.

## 2. Enforcer/consumer impact and preserved downstream rules

| Source site | Impact of the proposed A5-only change |
|---|---|
| RP:4695, `seam_transport_certificate` | Uses `certified_seam_direction` to select exactly one matching certificate. Two admissible certificates still produce ambiguity/rejection; zero certificates do not silently fall back. |
| RP:5250–5262, `OrdinaryFront` A5 relation | The existing `MismatchedIsolationEvidence` rejection remains if a certified seam is present but no admissible uniquely selected direction/certificate is found. Shared-node spans on opposite certified sides may now pass this one gate. |
| RP:5293, diagnostic `certified_seam_direction` call | The `certs`/`passing` site evidence reflects the new predicate; no synthetic certificate, changed site identity, or acceptance assertion is authorized. |
| RP:5878, A6 quotient | Re-evaluates the same direction, then checks the selected certificate's `forward`/`reverse` turn against the independently gauge-stripped lattice turn. A6 and D3 remain **byte-semantically unchanged**. |

In particular, A6 RP:5869–5870 still requires `firstGauge.face == firstOccurrence.placement.selectedFace` and `secondGauge.face == secondOccurrence.placement.selectedFace`; both endpoint gauges and their provenance stay unchanged. A6 RP:5887–5905 must reject `strippedTurn != expectedTurn` as `RelationCertificateConflict` (frozen RA-30a.3/D3). The identity-turn observations in TB25 do not authorize admitting nonzero-turn seams. The `certified_seam_wedge_side` implementation is unchanged; the corrective CB may change **only** the two scoped comparisons inside `certified_seam_direction`, after Review.

## 3. Non-weakening / independent negative cases

| Case | Required reject and responsible clause |
|---|---|
| Shared node, span's binding outside that occurrence's wedge | `certified_seam_wedge_side`: exact `cornerWedgeBindings` membership fails (or `NotOnSeam` if not a certified face); direction absent. |
| Shared node, spans both on same certified side | `certified_seam_direction`: neither opposite-side orientation branch matches. |
| Certificate has equal first/second sheets | `certified_seam_direction`: distinct-sheets guard; no admission, regardless of node equality. |
| Two certificates both direction-valid for this pair | `seam_transport_certificate`: second admissible candidate invalidates uniqueness (`nullopt`); A5 rejects. |
| Non-shared-node pair with either face equality failing | Original first/second span-to-selected-face clause remains required; A5 rejects. |
| Shared node, certificate's turn nonzero while both regional lattice turns remain equal | A5 may establish side, but A6's unchanged D3 `strippedTurn != expectedTurn` rejects `RelationCertificateConflict`; **no D3 bypass**. |

Additionally unchanged: wrong seam/region, missing canonical collinear edge, wrong certified sheet, non-wedge binding, missing gauge, or inconsistent gauge/selectedFace are rejections at their respective existing predicates.

## 4. Corrective TB predictions, falsifiers, and boundary

- **Prediction P1:** all 12 reviewed A5-ISO identities — `focused30:6,20,24,25,26,27,28`; `selector:444,446,448` (including G4-B002); `cp3entry:3,5` — advance beyond their prior A5 `relation-collinear-seam` rejection. The first *subsequent* failure, if any, must be reported from runtime, not guessed to be green.
- **Falsifier F1:** any of these 12 still rejects at the same A5 face clause after the scoped change, or admits without valid opposite certified wedge sides. Report exact pair/certificate identity and revisit this contract in Review.
- **Prediction P2:** the TB25 guard (`selector:447`), the six TB25 PASS controls, and the TB21-PASS population of 449 remain unaffected. A later selector-497 census is required; no unexecuted PASS is claimed here.
- **Falsifier F2:** any previously passing control or accepted-prefix identity loses its result, any newly admitted pair violates source/sheet/uniqueness, or any A6 nonidentity discrepancy passes. Route to independent Review, not ad hoc guard weakening.
- **Unknowns:** production direct-quad success, the next first failure, and nonzero-turn seams are unmeasured. Nonzero-turn semantics belong to deferred `DEFN-SEAM-NZ` only after an actual witness.

**Prohibitions:** no changes in this DEFN turn to code, tests, fixtures, selectors, workflows, compilation, runtime, A2 representatives, A6/D3, gauges, minimum-face rules (RA-79.4), or producer-authored vertex-star certificates (RA-78.4/Gate C). Stable 66/17/49; debt 1; accepted CP2 491/491; candidate TB21 449/497 and frozen selector 497 remain unchanged.
