# CB27A certified-seam wedge-membership oracle — independent Review (2026-10-22)

**Turn:** `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION-REV`. **Disposition:** ACCEPT the CB27A test-authority correction as a *static, discriminating negative oracle*, not as runtime PASS or CP3 acceptance. CB28 is authorized only in the test-only, messages-only RA-134.5 scope.

## Independent decision and falsifier

- Reviewed RA-135.1–135.5 and CB27-REV's failing prior oracle. D7's first corner has only `0/0`, whereas the second has authentic same-sheet `2/1` and `3/1`; the second endpoint's span selects `3/1`. Withdrawing exactly that producer binding retains `2/1`, its sheet set, selected face, support, lattice coordinate, unchanged A5 relation, seam certificate and transition evidence.
- TQ `CertifiedSeamRejectsSpanBindingWithdrawnFromEndpointWedge` checks **P1–P6** before asserting any rejection: source-span binding membership and same-sheet sibling, post-withdrawal sheet-set equality, shared-node support/face/lattice equality, opposite certificate sides classified without membership, and a concrete certificate-matching transition. It deterministically chooses the first eligible endpoint, otherwise second (D7).
- `publish_records_for_validation` validates structural relationships rather than wedge membership. A7 per-member gates still accept the remaining connected, same-sheet wedge. With the certified-seam membership requirement deleted *alone*, `certified_seam_direction` still classifies opposite certificate sides and finds the unchanged transition, so the source-derived tamper would be admitted. With the actual guard, A6 reports `InvalidIsolationEvidence` and A7 using the **original A6 forest** reports `UncertifiedCrossSheetBinding` at `cross-sheet:seam-direction`, with the relation-first occurrence locus. This is an independent static counterfactual, **not an executed mutation test**.
- The helper's optional locus check defaults off for the other three negatives. The first three negative fixtures and D3/D7 positive oracles remain unchanged. GitHub historical comparison `aa143c3003dc9b0a21a50951b90c56987e178a6d`→`f021e8f7b876c261b8337334596f519f4b7652a7` identifies only `tests/SurfaceCellTransitionQuotientTests.cpp` (+101/-20) as semantic change, with no production, selector, fixture or workflow edit.
- Pre-existing compile package `12452346647`, run `39838687950`, outer SHA-256 `c650a9d5463fde132dfc270356ef7538d7fe11c6ec0ef3cdde54d6f3e5602af4`: independently verified 28/28 hashes, all eight targets, GMP/GMPXX link, exact semantic source and `runtimeExecution=false`. This Review ran no compile, tests or benchmarks.

**Carry:** stable 66 events / 17 categories / 49 recurrences, one produced-witness debt; accepted CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate only; selector 497 byte-frozen; RP-01 open, RP-02 UNREACHED; Gate C suspended. No M6-CP3 promotion.

## Bounded successor — `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS`

Code + Build, **test-only diagnostics** (RA-134.5): edit only `tests/SurfaceCellTransitionQuotientTests.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. Add a test-local `SurfacePhaseFrontProductError` formatter with integer code plus `sourceAuthoritySite`, `edge`, `event`, `cell`, `region`, `periodicRelation`; append it to the helper exception text at TQ:358/2498 and SP10:6479. Append `FieldAtlasBuildError` code/location at SP10:4340; stream factory rejection into TQ assertions 3900/5942/5983, and `a5_rejection_message` at 5158. **No** assertion, expected-value, control-flow, fixture, product source, selector or workflow changes. Eight-target GMP/GMPXX compile only, no binaries; independently Review CB28 before TB29. STOP if a message change affects decisions, requires a fixture or assertion modification, or diagnostic source does not identify an authentic error.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector or runtime publication; CP2 491/491 and frozen 497 unchanged |
| Decisive claims independently re-derived | RA-135, CB27-REV and actual TQ membership/predicate path; original historical semantic compare and compile evidence |
| Non-vacuity checked | P1–P6 plus isolated membership-withdrawal counterfactual; static only, runtime untested |
| Prior obligations discharged/carried | CB27-REV fourth oracle discharged at test-authority level; RA-134.5 diagnostics carried to CB28; produced witness debt remains |
| Stable accounting | 66/17/49; debt 1; CP2 491/491; TB28 462/497 candidate |
| New candidates/obligations recorded | none; existing CB28 diagnostics obligation assigned |
| ORIENTATION currency line | CB27A-REV, 2026-10-22; CB28 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current candidate retained; §4 n/a no witness changed; §7 priority updated; §8 existing vacuous-witness pattern covers correction |
| CHANGELOG | CB27A-REV static-review entry added |
| ROADMAP | n/a: checkpoint status unchanged |
| Selector manifest | n/a: frozen 497 unchanged |
| LESSONS | existing witness-non-vacuity lesson; no novel reusable pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: one current record, no historical deletion |
| Successor frozen | `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS`; RA-134.5 scope and STOP above |
| Turn boundary held | Review only; no new product/test/selector/workflow edits or runtime execution |
| review_check.py boundary | pending authoritative real-history execution; synthetic source snapshot cannot prove history |
| `STATUS` lifecycle maintained | entry/resume beacon published; final COMPLETE only after remote publication and verification |
| Pushed to origin, branch in sync | pending verified Drive-apply remote publication; not claimed by this draft |
