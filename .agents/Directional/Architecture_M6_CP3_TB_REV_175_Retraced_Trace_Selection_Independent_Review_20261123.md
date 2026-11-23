# M6-CP3-TB-REV-175 — independent immutable gate review (2026-11-23 UTC)

## Situation — adjudication

**TB-EXEC-175 is REJECTED** as a production gate, with 993 PASS and seven existing RED cases out of 1000. This Review authorizes only one next, separate Code + Build turn: `M6-CP3-CB-197A-P13-EXACT-TRACE-PIECE-BUILDER-EXTRACTION`. It does not authorize A2a selection, deleting traces, port-map changes, or CP3 promotion.

## Background — independently verified evidence

- Exact CB-196 source `f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5`; immutable GMP/GMPXX compile package `14845101702`; compile run `45225040406`, no build or runtime in this Review.
- TB175 run `45233825958`, artifact `14849271506`, ZIP SHA-256 `be7a0f783d0afb025ccee2353921a765c340766340553f2d70b4b5c32992b347`, **2008/2008** checksum entries verified independently; TB174 artifact `14833644440`, ZIP SHA-256 `f77730c1896c346b15de704c90326a5a6543816a3e8ab553d4d8a70b9e11d5a3`, **2004/2004** entries verified.
- The TB175 manifest hashes to `e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35`; the original accepted 491-case prefix hashes to `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`, and the first 998 manifest rows hash to TB174's complete `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7`.
- All 1000 executions have corresponding manifest identities; 993 PASS, RED precisely 445/652/653/656/658/660/786; no skipped, missing, abnormal or wrong-site case. Membership 1000 gated + 81 deferred. TB175's `postflight=true`; no configure, compile, relink or benchmark; execution exit 90 reports required controls failed, not an orchestration pass.
- Independently compared all first 998 TB174/TB175 ledger rows: same test IDs, names, verdicts and required fields; only per-run log hashes differ. All raw logs: **757 exactly identical**, **240 N1/N2-only permitted elapsed-time/newline normalization**, and **one row179 N3 permutation of 24 complete region-support records**, with no other normalized differences. New rows 999 and 1000 PASS.

## Assessment — causality and non-vacuity

1. New case 999 enforces two exact retained/removed pairs `(0,3)` and `(2,4)` with a crossing distractor and swapped first-retained direction. Case 1000 rejects same-direction, another edge, empty and singleton paths. Those controls distinguish a selector that keeps the wrong index or matches all opposite directions. Source inspection confirms `exact_source_retraced_traces` is **not called from production**; its two PASS results are isolated helper evidence only.
2. Seven prior mechanical cases remain RED; row652's first typed failure is `RegionElectedCutComponentEmpty`, consistent with four co-traced zero-area lens orbits 1/3/4/5. Candidate CP2 is 490/491; the **accepted** CP2 is 491/491 and TB169 993/993. No new accepted-green event is counted. Stable history remains **67 events / 17 categories / 50 recurrences**, debt1, deferred81. Row979's staged `RegionContainsInteriorSingularity` at vertex8 is not production acceptance.
3. `exact_trace_segment_pieces` currently resides in `src/geometry/EmbeddedGraphTopology.cpp:955`, below several local chart/canonicalization helpers. A2a must obtain the same exact face-plus-slide edge pieces. Replacing it with the older face-only path reader would change the meaning of a sliding trace. A safe extraction must move required dependencies without changing any emitted product or existing call semantics.
4. The retrace oracle compares *merged edge coverage*, not ordered traversal or edge-visit multiplicity. For production selection, do not infer that paths with the same covered edge set are the same simple curve until the source trace admissibility contract excludes repeated/backtracking traversals, or a focused test rejects that case. This is a **prospective proof obligation**, not a newly measured failure.
5. A per-fixture selection receipt is **required before CB-197b production selection**, because the two isolated cases do not measure the real row652 paths. Capture the exact per-trace pieces, null-path status, selected `(kept, removed)` pair IDs, and expected row652 four-pair result, with an independent count and graph-consistency check. Do not put that diagnostic or production selection into the product-neutral extraction turn. A later independent Review must decide its exact test scope and selection admission.
6. Carry TB-REV-174 F1 (arrival owns removed Y's origin port), F3 (remap every `struckTrace` and contact/event incidence), F4 (piece-accurate construction and reader coordination), F5 (missing exact paths fail closed), TB-REV-173 E5 (per-grazing-edge/CollinearOverlap/EndpointTouch evidence), CB-190 S4/S6/S7, row979 staged face and CP3/497/D0/H4 holds. None is discharged by TB175.
7. Procedure: the source read mode was chosen late, after three direct document reads; this violates the conservation-policy pre-read gate. Subsequent source analysis used a separately verified 5,818-file snapshot at `1eb0acaab499220832f4d05248756e665810966f` (run `45241602709`, artifact `14851617653`). The local `review_check.py boundary` reported product/selector checks PASS but durable rewrite ancestor checks FAIL because the extracted snapshot has no Git history. This is a tooling context limitation, **not** a verified clean-history boundary. No Directional binary executed in Review.

## Recommendation — exactly one bounded next turn

`M6-CP3-CB-197A-P13-EXACT-TRACE-PIECE-BUILDER-EXTRACTION` is **Code + Build only**. Scope: extract the existing `exact_trace_segment_pieces` behavior and the smallest required exact chart/canonicalization helpers into the source-tracing/A2a-accessible lower layer, preserve the same signature where appropriate, and update only required production include/call sites and existing focused tests. Do not add duplicate logic. Do not implement trace selection, change port ownership, remap IDs, change validation/arrangement/region behavior, select tests, or activate CP3. Compile GMP/GMPXX via the existing eight-target GitHub workflow, **runtimeExecution=false**; no tests or benchmarks execute in this CB.

**Falsifiers/STOP:** any old test call cannot refer to the same behavior, any piece sequence (including terminal-contact slide, edge-only transit and exact source face/edge support) changes, any helper depends on a higher layer, any previously accepted path silently becomes an empty/default path, any patch touches selector/fixture/validator/production selection, or a compile/error authority mismatch. Require a type-checked no-semantic-drift review of moved logic and exact source/patch hashes. A subsequent separate artifact-only TB must repeat the frozen 1000-case manifest and compare all original rows under N1–N3; **seven known RED are expected**, and any novel deviation returns to Review. No CP3 promotion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 prefix `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; 998 TB174 rows `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7`; 1000 manifest `e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35` |
| Decisive claims independently re-derived | 2008/2008 TB175, 2004/2004 TB174, 1000 statuses, 998 ledger matches, 757/240/1 raw classes |
| Non-vacuity checked | Two helper cases require exact pairs and multiple negatives; production has zero selector callers |
| Prior obligations discharged/carried | F1/F3/F4/F5, E5, CB-190 S4/S6/S7, row979, CP3/497/D0/H4 all carried; no new discharge |
| Stable accounting | 67/17/50, debt1/deferred81; accepted TB169 993/993, CP2 491/491; TB175 rejected 993/1000 |
| New candidates/obligations recorded | Future proof of simple-path/edge multiplicity and per-fixture receipt before CB-197b; tracker updated; not classified as an observed regression |
| ORIENTATION currency line | TB-REV-175 (2026-11-23 UTC) |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current CP3/accepted gate updated; §4 no witness transition; §7 current priority corrected; §8 helper non-production pattern stated |
| CHANGELOG | New TB-REV-175 entry |
| ROADMAP | n/a: no checkpoint changed |
| Selector manifest | n/a: no selector accepted or changed |
| LESSONS | Existing evidence/semantic ownership lessons apply; n/a new general pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: current review and its source reports retained for next turn; no historical closure claimed |
| Successor frozen | `M6-CP3-CB-197A-P13-EXACT-TRACE-PIECE-BUILDER-EXTRACTION` with falsifiers in this record |
| Turn boundary held | Source/tests/fixtures/selectors/builds/runtime untouched in Review |
| review_check.py boundary | Product/selector PASS; ancestry/durable rewrite FAIL in snapshot lacking `.git` (incomplete verification, not a green pass) |
| `STATUS` lifecycle maintained | Entered with `Started at: 2026-11-23T18:43:49Z`; final status to be written as last repository mutation |
| Pushed to origin, branch in sync | To be checked from remote after document application; local snapshot has no remote checkout |
