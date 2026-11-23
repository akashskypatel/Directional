# TB-REV-172 — adversarial continuation (2026-11-23 UTC)

## Situation

**Reject TB172. Preserve the review turn and its accepted boundaries.** The independent review correctly rejected the 987/994 full gate and withheld all production fixes. It stated one inference too strongly: the row652 receipt is not a complete source-edge *visit* signature. It examines only the **first exact piece** of each visit. Therefore, the data disprove the different-edge hypothesis only for those printed opening pieces. The complete H-strip versus co-traced H-lens decision is still open.

## Background

- Same canonical turn: `M6-CP3-TB-REV-172-P13-ALONG-EDGE-VISIT-REGION-RECEIPT-FULL-GATE`. The source branch was reopened after the earlier closeout for adversarial verification. This is not the CB-194 turn.
- Independent review: [TB-REV-172](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md). Immutable package source `587b8ba7b1a52409d2fd95cff99dbb9d1da8f881`, TB171 artifact `14799346720`, TB172 artifact `14805479282`, frozen manifest SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`.
- New source snapshot: exact commit `5954c8bf111f62b8307552c4162a60546fcd3dec`, workflow `45164278703`, artifact `14812912831`, outer SHA-256 `94d693708fba1124ff6837d3bf3cca45425ccd3edc36b80fe4b14bf3ae682492`. Its archive hash and all **5,796/5,796** member hashes passed. No compiled binary executed in this Review.

## Assessment — source and artifact falsification

**A1 — The 58 receipt rows are first-piece signatures, not complete visits.** In `tests/FieldAlignedCurveNetworkTests.cpp`, `append_along_edge_visit_receipt` sets `opening = arc.sourcePath[piece]`, uses only `opening.first` and `opening.second` to infer `edge`, then increments `piece` by `arc.sourcePieceCounts[visit.visit]`. It prints neither the count nor the trailing piece. `src/geometry/EmbeddedGraphTopology.cpp::source_piece_binding_failure` expressly accepts counts **1 or 2** and admits a trailing edge piece. `src/geometry/ArcFaceVisits.h::arc_face_visits` also classifies the **opening piece**, and says the trailing edge piece contributes no face cut. These contracts explain the classifier's reported one-sided orbit, but **do not establish whole-visit geometric coincidence** between two trace arcs.

**A2 — Exact edge IDs match for all four reported opening sequences.** Independent parsing of the raw TB172 `652.log` and `656.log` found 58 indexed visits in each, identical receipt rows, no truncation, 38 side-orbit-0 visits and 20 side-orbit-2 visits. Each pair has the same five **reported opening-edge IDs** in reverse order: orbit1 traces 0/3; orbit3 traces 2/8; orbit4 traces 4/11; orbit5 traces 7/9. At each corresponding position, the visited face equals the other record's opposite face. This is reliable face/edge topology evidence, but not a certificate of equal rational edge intervals. Moreover, opposite-face symmetry is expected once the same edge and opposite incident face are selected. It is not independent evidence of path equality.

**A3 — Carrier ambiguity is unmeasured.** The receipt loops over source-face edges and assigns `edge = candidate` whenever the exact support contains both opening endpoints. It does not count candidates, require one unique edge, or record positive segment length. A degenerate opening at a source vertex can satisfy more than one edge candidate. No evidence proves this occurs in row652; the missing uniqueness and nondegeneracy checks prevent a general proof. Source-sheet and full piece lineage are also absent.

**A4 — The rejection remains independently falsifiable.** Raw baseline/candidate ledgers each show seven RED rows (`445,652,653,656,658,660,786`), 987/994 PASS. N1–N3 permit duration, newlines and complete-record order; the five extra +87 assertion-line changes in rows `445,653,658,660,786` are not permitted. The source change inserted the receipt before other assertions, so those shifts are explainable. Explanation does not convert them into allowed differences. CP2 candidate remains 490/491 against accepted 491/491, and TB169's accepted 993/993 remains the baseline.

**A5 — No direct repair is justified.** Same-edge opening labels alone do not establish a zero-area region. They also do not license crediting all opposite incident faces or dropping a source-face-less draft. `GlobalTopologyPlan.cpp` rejects an empty elected region, but neither the first-piece receipt nor reversed source-edge IDs prove region viability or a valid region-contract exception.

## Decision and exactly one successor

Uphold the first review's **gate rejection** and correct its stronger phrase “H-strip refuted” to **“different opening-edge labels not observed; full carrier geometry undecided.”** Carry the same bounded successor:

`M6-CP3-CB-194-P13-CO-CARRIER-INTERVAL-IDENTITY-RECEIPT`

- Diagnostic-only, test-receipt-only, compile-only. Use the existing exact `sourcePath` and `sourcePieceCounts`. For each paired visit, print count 1/2, **every** piece's carrier type, exact endpoints/edge parameters, source sheet/component, direction, positive-length status, uniqueness of the edge association, and trace/arc/visit/piece identity.
- Do not infer a matching pair from edge ID alone. Form the pair from independently identified orbit/trace lineage. Show at least one negative interval witness when one exists. If exact parameters or sheet cannot be recovered from the source contract, say *unavailable* and STOP instead of inventing them.
- Preserve the 994-row manifest and its accepted 491-row prefix. Avoid new unrelated assertion source-location shifts when placing diagnostic code, but do **not** normalize or hide the five existing unauthorized shifts.
- Compile with GMP/GMPXX on the authorized GitHub workflow. No test, benchmark or compiled executable may run in the CB. The next TB and Review are separate.
- **Stop rules:** no production cut ownership/region election or topology change; no source grid recovery, selector edits, test-assertion edits, new transcript normalization, or unconditional opposite-face crediting. A disagreement between any paired exact subintervals, directions, or component/sheet bindings falsifies co-tracing. Agreement of all recorded pieces is only a candidate, **not** proof that removing the resulting graph orbit preserves the region contract.

Accepted scope and debt remain: TB169 993/993, CP2 491/491; stable events/categories/recurrences **67/17/50**, witness debt **1**, deferred **81**. CP3/497/D0/H4, production sphere and row979 remain held. No new stable event.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Frozen 994-row SHA-256 `704dcf6c…09c6`; accepted 491-row prefix `483f1101…038` remains current. No selector edit. |
| Decisive claims independently re-derived | 58 visit records in row652 and row656, 4 reversed opening-edge sequences, source first-piece rule and two-piece binding, seven RED, five nonallowed line shifts. |
| Non-vacuity checked | One differing piece/parameter, ambiguous edge candidate, or sheet mismatch would disprove full co-tracing. Existing acceptance failures are real. |
| Prior obligations discharged/carried | B4 opening-edge evidence retained; whole-visit co-trace, area and region-contract validation carried to CB-194. B5 receipt present. W1–W5, A2a/K5, row979 and CB190 held. |
| Stable accounting | 67 / 17 / 50; debt1; deferred81; TB169 accepted 993/993, CP2 491/491. |
| New candidates/obligations recorded | A1–A5 clarify first-piece limitation and uniqueness; existing mechanical candidate only. Tracker and independent review corrected. |
| ORIENTATION currency line | Adversarial TB-REV-172, 2026-11-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Recorded opening-only qualification in current checkpoint, witness, priority and recurrence. No promotion. |
| CHANGELOG | Amended the existing TB-REV-172 entry; no duplicate turn. |
| ROADMAP | n/a: no checkpoint advanced. |
| Selector manifest | n/a: no selector changed or accepted. |
| LESSONS | Existing RA-220 and RA-235 cited; no new general rule required. |
| Consolidation under CLEAN_UP_POLICY | n/a: both current review records remain live; no superseded historical per-turn report. |
| Successor frozen | CB-194 exact all-piece interval receipt and falsifiers above. No next-turn implementation in this Review. |
| Turn boundary held | Source/document inspection and evidence comparison only; no product, test, fixture, selector or build mutation; no binary executed. |
| review_check.py boundary | Exact source snapshot omits Git history. Product/test/selector unchanged by changed-path audit, but Git ancestry and durable rewrite-baseline checks cannot PASS without original history; no false full-PASS claim. |
| `STATUS` lifecycle maintained | Same review turn resumed. Final `STATUS` direct-write only after remote documentation application and cleanup. |
| Pushed to origin, branch in sync | Verified through GitHub branch authority after patch application and cleanup. The working branch remains open and draft on PR #8. Local `git status -sb` is unavailable in the source snapshot, which has no Git history. |
