# TB-REV-172 — along-edge visit region receipt independent review (2026-11-23 UTC)

## Situation

**REJECT TB-EXEC-172 as a full gate.** The candidate remains **987/994 PASS, seven RED**. The four disputed lens orbits use matched source-edge carriers in reverse trace order. This refutes the distinct-edge H-strip hypothesis but **does not establish exact coincident intervals or zero enclosed area**. Do not credit the opposite source face, restore false chords, or change region election on the present evidence. TB169 **993/993** and CP2 **491/491** remain the last accepted authorities. This is the existing mechanical regression, not a newly counted stable event.

## Background — independently verified immutable authorities

- Canonical Review turn `M6-CP3-TB-REV-172-P13-ALONG-EDGE-VISIT-REGION-RECEIPT-FULL-GATE`, PR #8 open/draft and unmerged. Review-only source snapshot commit `a430ef8bc2b3ae18724c72dc0bc34c1f586f8bc0`, workflow run `45157245933`, artifact `14809875191`, outer SHA-256 `b91f07f0c5090331ff92bb08ef6a880fdbca1a2095432c6c6efe90c2e2ffb79c`; exact snapshot metadata SHA checked. The snapshot is review authority, not the compiled program.
- Immutable CB-193 compiled program source `587b8ba7b1a52409d2fd95cff99dbb9d1da8f881`, GMP/GMPXX compile run `45147339047`, artifact `14805640405` (SHA-256 `58a49461e3d6cdc0480c3a2ecd8a40ac038b48595b88eb2a0f9e7015b70fe2cb`), `runtimeExecution=false`. No binaries run in this Review.
- Baseline TB171 run `45133081384`, artifact `14799346720`, independently hashed ZIP `b79b5cc26044acd357243c3c8fe7350e6a68e450171400aad6228e059e143d0c`. Candidate TB172 run `45149928894`, artifact `14805479282`, ZIP `e9ddc7fd80d3e33b25b18901c783fbb21ec2eaf5c1b86438f887e93cee03edbc`. Independently verified **1996/1996 internal SHA-256 members in each archive**.
- Exact frozen 994-row manifest: `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv`, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`; the header plus 491 accepted rows hash to `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. Selection membership 1,075 = 994 required + 81 deferred.

## Assessment — full-gate re-derivation

1. Both ledgers have 994 rows. Both give **987 PASS**, **seven RED** at **445, 652, 653, 656, 658, 660, 786**; no status flips. TB172 postflight reports no missing, abnormal, skipped, or duplicate row; 7 failed controls, exit 90. Candidate CP2 prefix remains **490/491**, so it does not restore the accepted prefix. Diagnostic record multisets each contain **1,450** records, and the normalized record comparison has no differences.
2. Independently applied N1 Google Test duration, N2 newline and N3 whole diagnostic-record ordering; the **only** allowed new data are the appended `alongEdgeVisit*` exception fields. **Five nonallowed raw/ledger identity mismatches remain** at rows **445, 653, 658, 660, 786**. They are assertion source-location shifts of +87 lines: respectively `19251→19338`, `14262→14349`, `19832→19919`, `14061→14148`, `19891→19978`. They are likely due to CB-193 test-only source insertion, but that is an explanation, **not authorization to silently normalize the records**. This strictly violates the frozen TB171→TB172 transcript equivalence gate. No independent source behavior difference is established by these numbers; approval remains withheld.
3. The exact row652 exception appends **58 indexed along-edge visits** and two count/truncation markers (**60 fields**), `alongEdgeVisitCount=58`, `alongEdgeVisitsTruncated=false`. The extra receipt is also present at failing row656. Row652's visited-side orbit counts are 38 on orbit0 and 20 on orbit2, none on 1/3/4/5. The opposite-face field is a **source triangle across the same edge**, not proof of an owned positive-area region.
4. Source review confirms the receipt (`tests/FieldAlignedCurveNetworkTests.cpp`) reconstructs source-edge visits and prints faces/edges/orbits, **not exact endpoint edge parameters**. The failed ownership check (`src/geometry/GlobalTopologyPlan.cpp`) requires a source-face-owned elected draft. Its empty-draft stop does not prove the disputed orbit is a valid positive-area region. The existing two-sided source-cut-arc credit rule is not a license to credit a zero-area co-carrier lens.

### Per-orbit edge/face classification (row652; exact receipt, not geometric area proof)

| Disputed orbit | Two bounding trace/arc records | Ordered source edges, first trace | Opposite trace | Matched face evidence | Verdict |
|---|---|---|---|---|---|
| 1 | trace0/arc14 and trace3/arc17 | 10-11, 11-17, 17-23, 23-29, 29-35 | Same five in reverse | Each visited face and its opposite face swap on corresponding edge | H-lens carrier; H-strip refuted |
| 3 | trace2/arc16 and trace8/arc22 | 10-79, 77-79, 75-77, 73-75, 47-73 | Same five in reverse | Same exact face/opposite-face swap | H-lens carrier; H-strip refuted |
| 4 | trace4/arc18 and trace11/arc25 | 35-95, 94-95, 93-94, 92-93, 71-92 | Same five in reverse | Same exact face/opposite-face swap | H-lens carrier; H-strip refuted |
| 5 | trace7/arc21 and trace9/arc23 | 46-47, 46-53, 53-59, 59-65, 65-71 | Same five in reverse | Same exact face/opposite-face swap | H-lens carrier; H-strip refuted |

**Limit:** all four pairings establish identical **source-edge IDs**, reverse order, and opposite-face symmetry. No receipt contains the exact barycentric endpoints or interval orientation required to prove **coincident subsegments**, cancellation, or positive/zero area. A same-edge carrier alone is insufficient to merge trace arcs. The next turn must not interpret edge equality as full path equality.

**Independent non-vacuity:** the same formerly accepted mechanical controls are still RED; the row994 local classifier can pass while topology-plan construction fails. Tampering with any one printed edge identity could falsify the pairwise carrier result, and the current frozen comparator detects even apparently harmless assertion-line drift. No direct sphere result, source patch, or selector acceptance follows from a diagnostic receipt.

## Obligations and prohibited shortcuts

- TB-REV-171 adversarial B4 discharged **at the source-edge-carrier level**: four H-lens cases; H-strip's different-source-edge prerequisite is false. B4 **exact overlap and region validity** remains open, owned by the next single narrow Code + Build receipt. B5 receipt is present, complete and nontruncated; it does not supply interval endpoints. TB-REV-170 W1–W5 carry the seven mechanical failures and no promotion. General A2a no-co-trace and immutable single-owner region contracts remain in force; do not conflate this with the earlier narrower K5 witness. Row979's `RegionContainsInteriorSingularity` remains **staged-only** and held. CB-190 S4/S6/S7, CP3/497/D0/H4, sphere production, V3b/Y7/M7/M8 remain held.
- Existing stable history **67 events / 17 categories / 50 recurrences**, produced witness debt **1**, deferred **81**. A diagnostic source-location change on an unaccepted package does not add a new stable event. Tracker retains the existing mechanical regression with this narrow root-cause candidate.
- The snapshot-read-mode pre-read gate was violated early by reading several repository files directly before selecting the mandatory source snapshot. Switched to the verified exact snapshot and performed all substantive source comparison there. This process error cannot be represented as policy compliance; it did not change source or test data.

## Exactly one bounded successor — not executed in this Review

**`M6-CP3-CB-194-P13-CO-CARRIER-INTERVAL-IDENTITY-RECEIPT`**, Code + Build, **diagnostic-only, compile-only**. Extend the existing test exception receipt (not the production region reader) to record for each paired lens visit **exact source-edge endpoint parameters, endpoint ordering/orientation, source-sheet identity, trace/arc/visit lineage and pairing**, without deleting current receipt fields, changing source topology, test assertions or any selector. Use existing exact values/identity types and state explicitly if the parameters are unavailable. Before changing test instrumentation, prove the current prints cannot provide these exact values. Retain the global 994-row manifest and original accepted prefix, and compile all required targets with GMP/GMPXX; **execute no compiled binaries in the CB**. The next TB and independent Review remain separate and require explicit authorization from this planned succession.

**Falsifiers:** At least one paired visit with different exact subinterval or non-opposite orientation disproves exact co-tracing, even when source-edge IDs agree. Exact equal intervals with reversed orientation across all corresponding visits support a co-traced candidate, but **still do not alone authorize region deletion or owner fabrication**. Print negative/positive interval contrast from source evidence, never constructed success. **STOP** if the only way to produce a receipt is to mutate production topology, relax source-chart or region validity checks, normalize unapproved TB transcript fields, or alter test expected outcomes. Any policy or contract decision about dropping an elected sourceless orbit requires a separate explicit decision before a corrective source CB. No unconditional opposite-face crediting and no CP3 activation.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Full manifest `704dcf6c…09c6`; header + accepted 491 rows `483f1101…038`, exact |
| Decisive claims independently re-derived | Both ZIP checksums; 1996/1996 internal hashes each; 994 ledgers; 7 RED; 5 nonallowed +87 source-location mismatches; 1450/1450 diagnostic records; 58 receipt visits; four paired carrier classifications |
| Non-vacuity checked | Seven real accepted-green controls still RED, row994 local PASS insufficient; paired carrier equality and N1–N3 drift falsifiable |
| Prior obligations discharged/carried | B4 edge-level classification discharged, exact interval/region validity carried; B5 receipt confirmed; W1–W5, K5-general/A2a, row979, CB190 and held activations retained |
| Stable accounting | 67 / 17 / 50, debt1, deferred81; accepted TB169 993/993, CP2 491/491, candidate 490/491 |
| New candidates/obligations recorded | Non-stable co-carrier interval identity candidate, tracker updated; no new stable event |
| ORIENTATION currency line | TB-REV-172 2026-11-23 UTC; accepted authority retained |
| ORIENTATION §3 / §4 / §7 / §8 | Refreshed active checkpoint, receipt witness, priority and recurrence; superseded next-turn guidance marked historical |
| CHANGELOG | TB-REV-172 independent review entry added |
| ROADMAP | n/a — CP3 and milestone status did not change; verified no advancement |
| Selector manifest | n/a — immutable 994-row manifest, no selector addition/acceptance |
| LESSONS | Existing RA-220, RA-235 and paired-witness rigor apply; no new general rule |
| Consolidation under CLEAN_UP_POLICY | n/a — no unrelated historical files modified in bounded Review |
| Successor frozen | `M6-CP3-CB-194-P13-CO-CARRIER-INTERVAL-IDENTITY-RECEIPT`; falsifiers and stop rules above |
| Turn boundary held | Runtime-free review only; no product/test/fixture/selector/build changes |
| review_check.py boundary | Exact source snapshot had no ancestor Git metadata; product/test/selector checks PASS; ancestry/rewrite-source checks FAIL (not full PASS) |
| `STATUS` lifecycle maintained | Entry written; closeout final STATUS update only after remote documentation application and cleanup |
| Pushed to origin, branch in sync | Verified by remote connector branch authority after patch application, not by synthetic snapshot-local Git status |
