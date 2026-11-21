# M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE — independent Review, 2026-11-21 UTC

## Verdict and authority

**REJECT / STOP.** TB-EXEC-155 did not meet the frozen gate. The reviewed semantic source is `65ae140e49db5bd04d202390e71b50f455ff152e` (CB-171 package `14702459291`). The reviewed full-gate run `44895154802` / artifact `14704220616` and census run `44895169959` / artifact `14704657114` are immutable. The prior full gate is TB154 (baseline artifact `14696380156`); the census baseline is TB151 artifact `14621727104`. This Review executed no production test, benchmark, or build. It does not authorize a stop switch or successor work in this turn.

## Independent checks

- Reverified the downloaded ZIP SHA-256 digests: TB155 gate `e4e08a887f2d9b1ccddb174cba19e78d71df1934e603a51e7e57431a06f46358`, TB154 gate `ce172d892dbf3f52084eaf3a148ec03443bc19c06ec9e5262f89e35c89b648c0`, TB155 census `fcd296b4664ecfb905a81ff204637a51d831cd44de469b10e5ddbee4276ed68b`, TB151 census `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`. Their internal checksums match respectively `1950/1950`, `1950/1950`, `9/9`, `9/9`.
- Parsed the full-gate TSV receipts independently: exactly 971 rows, 970 PASS, 1 RED (`858`), no invalid, absent, or skipped cases; 491 accepted CP2 entries PASS. Three census identities retain one Cylinder PASS and two expected diagnostic REDs; exact result equivalence is in the separate TB155 comparison evidence.
- Compared all 971 immutable raw log pairs independently. N1 removes only GoogleTest `(integer ms)` and `(integer ms total)`; N2 normalizes CRLF; N3 sorts the exact `region_support_projection` record multiset, without altering other lines. Precisely seven changed rows: `644,645,669,686,698,858,966`. The other four permitted rows `648,963,968,971` and **all 960 cases outside allowance A** match. The first-difference annex includes complete before/after lines; its original line numbers depend on preserving the position of N3 records. This Review's multiset normalization can shift reported first-line offsets but does not change the changed-row set.
- Independently hashed the exact 971-case manifest, `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305` (145526 bytes), and the 968-case TB153 manifest, `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116` (145036 bytes). The first 968 case entries and header are byte-identical: **the accepted historical prefix has not changed**. The prior 491 accepted cases also remain PASS in both immutable ledgers.

## Cause and non-vacuity

1. **Guard is a valid safety stop, not proven to be the underlying defect.** `EmbeddedGraphTopology.cpp` compares exact primary slots at a source vertex. If an along-edge trace ray shares the slot with any second incidence, it returns `RotationTraceRaysAlongSharedEdge`, rather than using an arbitrary tie-break. Rows 644, 669 and 698 show source vertex `0`, source edge `0–69`, trace `14`. This is an actual production-path rejection and violates the TB155 express STOP. The error only names the first trace, not the conflicting incidence or whether it is a mandatory, cut, or trace arc. Consequently, the current bytes **do not prove** whether the duplicate is a correct rejection of incompatible input, a duplicate representation of one ray, or a defective cut proposal. Do not remove the guard, infer equality from position, or silently choose an ordering.
2. **Possible cause remains conditional:** `SurfaceCutGraph.cpp` assembles and retries cut candidates; its saturation branch may add trace-crossed source edges (Amendment 14), and the next exact rotation certification may see both a cut and an along-edge trace. This source path is consistent with the observed failure but the unreported conflicting incidence prevents definitive attribution. The successor must publish both incidences with exact owner/kind/edge/source-chart authority before choosing a repair.
3. **Row 858 is a genuine previously accepted test loss**, not a new geometry success. The earlier `CutSearchExhaustedBeforeCellularity` carried source-face `0–1–2`; the new earlier `CellularityNotEstablished/origin=RotationSystemInconsistent` names vertex/edge and no source-face. The accepted `SurfaceCellTracingDisplayTests.cpp:155` `sourceFace` assertion therefore fails. Do not weaken or delete the assertion to force green. Restore correct source-authoritative failure progression, or justify a separately frozen contract change with a falsifiable replacement oracle at a later authorized turn.
4. **Unresolved topology persists:** row 686 records `V=18,E=30,F=18`, Euler characteristic `6` while the sphere source has `2`, so the excess remains `+4`. Four interior sliding-wall contacts remain without a proved common graph event. No completed cut graph, source-conformity proof, or direct sphere mesh follows from this Review.
5. **RA-277-NV1 and RA-275 S4a remain limited:** row 971 prints ten along-edge slide ends, zero edge-arc coincidences, zero ordinary-ray changes and zero failures; the test explicitly asserts the count, but it observes the pre-cut network. A green pre-cut witness cannot rule out the later cut-candidate conflict. RA-275 S4a asks whether a formerly uncut face component touching only a published face-then-edge slide loses its seed. The present sphere stops before complete admissible ownership census; there is no positive witness to discharge S4a. Carry it into a later independently executed topology/seed test; do not interpret the early stop as proof that the seed is preserved.

## Classification and obligations

- **RA-279-C1 (candidate, non-stable):** failed shared-edge rotation certification for trace14/edge0–69 on rows644/669/698; exact second incidence and owning stage unknown. Owner M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE; falsifier: any proposed correction hides a real distinct incidence or changes any of the 960 protected rows. No geometry/selector release.
- **RA-279-C2 (candidate, non-stable accepted-row loss):** row858 expected source-face location absent due to earlier failure. Owner M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE; falsifier: row858 still RED or the accepted assertion is weakened/replaced without independent evidence.
- **RA-275 S4a (carried):** prove uncut-component seed preservation on face-then-edge slides after a valid cut graph exists; owner the later specifically authorized seed/stop-switch review, **not** the present correction. RA-277-NV1: source ray oracle reaches a pre-cut path, but cross-stage coverage remains open. RA-278 C1/C2/C4 changes compile and affected tests pass; C3 deliberate guard triggers an unresolved actual collision, so C3's product outcome is **not discharged**.
- Stable accounting remains **66 events / 17 categories / 49 recurrences**, one produced-witness debt, 81 deferred tests, accepted CP2 491/491; no new stable event, CP3/selector497/D0/H4 promotion, or release claim.

## Recommendation — exactly one bounded successor

M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE — Code + Build and **compile only**, governed by [Architecture_M6_CP3_CB172A_P13_Cut_Candidate_Shared_Edge_Incidence_Code_Build_Plan_20261121.md](Architecture_M6_CP3_CB172A_P13_Cut_Candidate_Shared_Edge_Incidence_Code_Build_Plan_20261121.md). It must publish complete exact collision provenance and implement only the demonstrated source-of-duplicate correction if its admissibility is established. It may not add a stop-switch, repair Euler +4, alter the selector, or modify unrelated product areas. A future immutable Test + Benchmark and independent Review must rerun the unchanged 971-case gate and census. There is **no permission** to start successor work inside this Review.

## Policy and execution qualification

This Review initially read several repository source documents directly before selecting mandatory snapshot mode; it then changed to `READ_MODE=snapshot`, acquired and verified the full source snapshot from run `44899230132` at `e628d5b9ccae67712badcfea129e9e5c3570cce9` (5,669/5,669 source file digests), and stopped piecemeal source reads. The initial selection-order error is retained as an explicit policy exception, not normalized. The local snapshot lacks the historical Git objects required to prove ancestry via `review_check.py authority`; that is a tooling limitation, not evidence of product acceptance. The closeout `review_check.py boundary` result is recorded below when available.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB153 `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116` is exact prefix of TB154/TB155 971-row manifest `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`; first 491 PASS. |
| Decisive claims independently re-derived | Four ZIP checks, manifests, 971 TSV outcomes and all 971 N1–N3 raw pairs; census comparison also checked against TB151 receipts. |
| Non-vacuity checked | Row971 is pre-cut only; full production guard actually rejects; 858 catches changed terminal locus. A complete two-incidence cut-stage negative control is missing and is required next. |
| Prior obligations discharged/carried | RA-278 C1/C2/C4 compiled and runtime observations available; C3 product blocked by collision. RA-277-NV1 incomplete cut-stage coverage. RA-275 S4a carried; four contacts and O47/C5 remain. |
| Stable accounting | 66 / 17 / 49; debt 1; deferred 81; CP2 491/491 accepted; CP3 unpromoted. |
| New candidates/obligations recorded | RA-279-C1/C2 in regression tracker; successor exact incident-pair proof; seed obligation carried. |
| ORIENTATION currency line | M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE, 2026-11-21 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 refreshed; §4 witness status unchanged (no successful new witness); §8 references existing lessons and candidate guard without adding a new generic pattern. |
| CHANGELOG | Review entry appended. |
| ROADMAP | M6-CP3 current gate RED; other milestone statuses unchanged. |
| Selector manifest | n/a: no selector added/promoted or changed. |
| LESSONS | Existing proof/non-vacuity and single-writer rules applied; no new generalizable rule. |
| Consolidation under CLEAN_UP_POLICY | n/a: current TB155 immutable report/annex remain live evidence; current Review and one successor plan are newly retained. No superseded role-specific file identified for folding in this turn. |
| Successor frozen | M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE with exact preconditions, falsifiers, no-successor-work and stop rules in `Architecture_M6_CP3_CB172A_P13_Cut_Candidate_Shared_Edge_Incidence_Code_Build_Plan_20261121.md`. |
| Turn boundary held | Static Review only; no source, test, fixture, build, selector, or runtime modification. |
| review_check.py boundary | Executed on the verified snapshot-derived local worktree: code/selector checks pass; four historical-base checks fail because the shallow snapshot omits rewrite commit `8b7299b43` and its three document preimages. These are tool-history limitations, not source mutations. |
| `STATUS` lifecycle maintained | Entry beacon published at 2026-11-21T11:27:00Z; final COMPLETE/IN_PROGRESS beacon must be the final repository action. |
| Pushed to origin, branch in sync | Pending successful Drive patch application and remote head check; the local archive is not an origin branch. |
