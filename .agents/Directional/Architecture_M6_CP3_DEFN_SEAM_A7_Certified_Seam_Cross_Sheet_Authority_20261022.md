# DEFN-SEAM-A7 — certified cross-sheet OrdinaryFront authority (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY`.
**Boundary:** documents-only contract; no implementation, test, workflow or runtime change.
**Inspected source:** `575d10ef8e6efc6f20c24b1643b0620859a489a9` (snapshot 39737334509); `RP` = `src/pipeline/RemeshPipeline.cpp`, `TQ` = `tests/SurfaceCellTransitionQuotientTests.cpp`. RA-129.4 is the authority; RA-127 and RA-124.3 are carried without altering D3.

## 1. Post-A5 consumer census (search-first audit)

Searched `cornerWedgeSheets`, `cornerWedgeIsolation`, `isolationTransitions`, `SideIsolationEvidence`, `isolationSeamTransportCertificate`, and `certified_seam_direction` across `src/`, `include/` and `tests/`. The decisions on the A5→A9 path are below; hashing, diagnostics, declarations and test inspection are not independent admission sites.

| Consumer and source | Actual predicate on a shared-node, disjoint-sheet, certified OrdinaryFront relation | Disposition |
|---|---|---|
| A5 side evidence, RP:4290–4449, 4699–4740, 5203–5267 | Collinear directed-side spans carry `interiorBinding` plus seam transition; `isolationEvidence` is the union of span transitions; canonical endpoint spans and the unique typed A4 seam certificate are published. | **PASS for TB26 witnesses**; A5 producer prerequisite, not an A6/A7 substitute. |
| A6 OrdinaryFront, RP:5760–5912 | No rail/periodic tag, identity transport, same lattice coordinate/scale/phase, typed reciprocal side isolation, forward/reverse seam span transitions, both selected-face gauges, matching region/seam, `certified_seam_direction`, D3 stripped turn equal to certified turn. | **PASS for the six TB26 `cp3entry:3/5` searches** (RA-129.2); mutations or nonzero turns may reject. No A6 amendment authorized. |
| A6 quotient construction, RP:6035–6095 | Preserve member wedge transitions as provenance after union; selected forest carries the accepted relation, not a new sheet-admission decision. | **PASS** on those witnesses; construction otherwise subject to existing validations. |
| A7 per member, RP:7410–7541 | Same source support and point; valid component and region; wedge-binding sheet set nonempty and equal cached `cornerWedgeSheets`; multi-sheet wedges must be connected *within their own wedge* by `cornerWedgeIsolation`. | **Independent conditional gate**; cannot be waived by a seam certificate. TB26 lacks an A7-site diagnostic to prove each individual predicate on all nine RED rows. |
| A7 forest, RP:7543–7603 | HardRail needs distinct regions/gauges; OrdinaryFront/Periodic need equal regions; with shared wedge sheet, pass. Otherwise both `relationCertified` and `occurrenceCertified` must connect the endpoint sheet sets. | **REJECT for disjoint-sheet seams**: `occurrenceCertified` is impossible; it consults only each endpoint's own wedge transitions. This is the A7 structural defect (RA-129.3). |
| A7 emitted geometry, RP:7641–7642 | Stores union of member sheets as `sourceIsolationSheets` only *after* admissibility; does not independently authorize a crossing. | **Not an admission gate**. |
| A8 verifier, RP:8231–8283 | `a5:wedge-bindings` rechecks support incidence, per-face sheet assignment and flattened bindings; `a5:wedge-isolation` rechecks source seam, edge incidence and exactly the two incident sheets. | **Independent conditional gate**; checks original A5 facts, not endpoint-relation crossing. Keep unchanged. |
| Downstream A8/A9 / other `src` consumers | Search found no further use of these five isolation-evidence symbols as a cross-sheet relation admission check after the sites listed above. | **No further seam-authorization consumer found** in inspected source. |

A5's wedge walk only appends transitions between its own bindings (RP:4540–4665). A disjoint second endpoint sheet therefore cannot be connected by the first occurrence's `cornerWedgeIsolation`, nor conversely. This does **not** imply the relation itself lacks reciprocal cross-seam side evidence.

## 2. `relationCertified` is attainable — not a replacement for typed direction

RP:4290–4449 appends every collinear segment's seam transition into its directed side's `isolationEvidence`; RP:5203–5219 copies the two front sides into `firstSideIsolationEvidence` and `secondSideIsolationEvidence`, and RP:4970–4978 copies the first side into `equivalence.isolationTransitions`. A6's certified branch requires the forward transition in the first endpoint span and reverse transition in the second (RP:5840–5877). Each endpoint span belongs to the corresponding directed side (RP:4718–4740). Thus, for an unmodified A6-accepted seam relation, at least one relation evidence collection can connect the disjoint endpoint sheet sets: **`relationCertified` can be true**, unlike `occurrenceCertified`. This is a static producer/dataflow implication, **not a runtime assertion that A7 reached the particular predicate**; the A7 site suffix is needed to distinguish other gates.

## 3. Normative A7 forest-edge rule (CB26 implementation contract)

1. Preserve HardRail, SingularityPort, same-region, same-sheet, and all per-member source-support, component, point, wedge-binding and wedge-connectivity checks exactly as presently enforced. Preserve the existing crossing predicate verbatim for **Periodic** and **OrdinaryFront without** `isolationSeamTransportCertificate`.
2. Only for **OrdinaryFront**, **disjoint** `firstSheets`/`secondSheets` and a present **typed** certificate: require both canonical `firstEndpointSpan` and `secondEndpointSpan`; evaluate `certified_seam_direction(first, second, firstSpan, secondSpan, certificate)` from RP:3889–3934 **once**, without choosing a side from labels, `selectedFace`, or a re-derived orientation.
3. Reject if no direction; otherwise bind Forward to `(certificate.firstFace(), certificate.firstSheet())` for `firstSpan` and `(certificate.secondFace(), certificate.secondSheet())` for `secondSpan`, or Reverse to the opposite ordering. Require each span's `interiorBinding` to be the selected typed face/sheet pair **and** its sheet to appear in its endpoint's certified wedge bindings. Do not require the entire wedge-sheet set to be a singleton. Keep `relationCertified` as an independent transition-evidence guard; it is attainable as shown in §2.
4. The seam-certified branch **replaces only** the impossible cross-endpoint `occurrenceCertified` demand; it does not transform a plain, invalid or Periodic relation into a seam. No inferred side from bare sheet labels; no global sheet equality; no change to A5, A6, the D3 gauge equation or their frozen predicates.

## 4. Diagnostic-only change (CB26)

At RP:9276–9280, when `geometryError->code == UncertifiedCrossSheetBinding`, append `":" + geometryError->site` to `result.failure` (if nonempty), analogous to the existing `:support-point` handling. Keep code, typed site, stage and return unchanged. At TQ:2725–2814, the D3 fixture helper must record `A7:<GeometryEmbeddingFailureCode>:<site>` (or an equivalently unambiguous code/site pair) instead of `A7:rejected-certified-seam`. No assertion or evidence reduction; a change in diagnostic text alone is not success.

## 5. Non-weakening / rejection matrix

| Case | Required rejection clause (source) |
|---|---|
| Disjoint sheets, no typed seam certificate | Existing `relationCertified && occurrenceCertified` rule (RP:7574–7603); no new path. |
| Certificate's selected-side sheet/face differs from endpoint span or wedge binding | `certified_seam_direction` / `certified_seam_wedge_side` (RP:3855–3934), then explicit §3 typed pair/binding equality; **reject**. |
| Noncollinear/missing spans, wrong seam, same-side mapping or invalid certificate direction | `certified_seam_direction` (RP:3889–3934); **reject**, no fallback. |
| Periodic cross-sheet with disjoint wedges | Original A7 transition rule unchanged (RP:7543–7603). |
| Wrong topology region | A7 region equality (RP:7558–7565) plus certificate region predicate (RP:3899–3914). |
| Per-member wedge cache mismatch, unconnected wedge or invalid source support | A7 wedge/source checks (RP:7370–7541) and A8 wedge verification (RP:8231–8283); never suppressed. |
| Nonreciprocal seam side transitions, wrong selected-face gauge or D3 gauge tamper | A6 reciprocal/span/gauge/stripped-turn clauses (RP:5840–5912), producing `RelationCertificateConflict` for the D3 tamper. |

## 6. TB27 predictions and falsifiers (not executed here)

- Re-run exactly the TB26 18 selections, same code+site diagnostics. The eight rows with `UncertifiedCrossSheetBinding` (`focused30:6,20,25`; `selector:444,446,448`; `cp3entry:3,5`) **should pass the former A7 cross-sheet gate** when certified; this does **not** promise end-to-end PASS or invent the next first failure.
- `focused30:24` must expose its actual A7 error code and site; any non-cross-sheet first failure falsifies its proposed attribution to the §3 branch, not the independently proven impossibility of `occurrenceCertified` for disjoint sheets.
- The D3 helper in `cp3entry:3/5` should first produce a successful untampered A7 witness and reach the gauge tamper. A tampered certificate must be rejected at A6 as **`RelationCertificateConflict`**; a tamper that passes falsifies the D3 preservation guarantee. If untampered A7 still fails, report its exact code/site instead of asserting a tamper outcome.
- All TB26 controls (including `focused30:26–28`) must remain PASS; do not promote candidate 449/497 or modify stable 66/17/49, debt 1, or the frozen 497 selector. Any new error or later first failure is **measured**, not inferred from moving diagnostics.

**Disposition:** The requested consumer audit found no additional post-A5 seam gate requiring an A6 contract change, and `relationCertified` is statically attainable. DEFN can proceed to independent Review. CB26, TB27 and downstream turns remain unauthorized until their Reviews assign them.
