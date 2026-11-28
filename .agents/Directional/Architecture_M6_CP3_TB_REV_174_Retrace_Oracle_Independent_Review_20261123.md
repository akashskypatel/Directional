# TB-REV-174 — independent retrace-oracle full-gate review (2026-11-23 UTC)

## Situation and decision

**Reject TB-EXEC-174 for promotion.** All 998 frozen cases executed; 991 passed and the same seven mechanical controls failed. The two isolated helper tests passed, but the helper is not connected to the production A2a trace-selection stage. The original TB169 993/993 accepted gate and CP2 491/491 selector remain the accepted authorities. D13 = A was already resolved by DESIGN in TB-REV-173; this review does not reopen it.

## Background and independent evidence

The review independently downloaded and verified TB174 immutable artifact `14833644440` (ZIP SHA-256 `f77730c1896c346b15de704c90326a5a6543816a3e8ab553d4d8a70b9e11d5a3`; 2004/2004 archive members) and TB173 `14821438542` (ZIP SHA-256 `22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`; 2000/2000). Fresh exact-source snapshot at `f386134d76e7267a4ad6570af2dc794f7aad8900`, workflow `45214775639`, artifact `14837363602`, ZIP digest `de6cf8d3cf9a8a42467591f72e8d018d5483fadb9bccee054f426ff8a7dc7f0b`, source tar SHA-256 `aae58106a73fc3ff04640bc1b238fcba5d0d6b68e37f200ad814af71f9e9c1c6`, 5810/5810 source file checksums. This snapshot includes the immutable CB-195 source and TB174 closeout; the review did not compile or execute programs.

Independent ledger and log comparison finds 996 inherited identities and verdicts unchanged: 741 raw logs byte-identical, 254 different only under N1/N2 time and line-ending normalization, and one row179 N3 complete-record order change. For N3, the 24 `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records match as a multiset exactly: 12 region0 and 12 region1; their non-diagnostic lines are identical after N1/N2 normalization. **No unexplained line difference, missing case, skipped case, or new stable event.** The 491-row accepted prefix rehash is `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; the 994-row shared-prefix rehash is `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6` (header included). Frozen TB174 manifest SHA-256 `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7` matches all 998 ledger case keys; membership is 1079.

Seven RED identities remain 445, 652, 653, 656, 658, 660 and 786. Row652 fails closed with `RegionElectedCutComponentEmpty` at RegionConstruction. Row979 reports `RegionContainsInteriorSingularity` at vertex8, as a staged diagnostic, not production acceptance. The current CP2 candidate is 490/491. Historical accounting stays 67 events / 17 categories / 50 recurrences; witness debt1, deferred81; no CP3/497/D0/H4 promotion.

## Assessment — helper non-vacuity and production boundary

`include/directional/authority/ExactSourcePath.h` defines `exact_source_paths_retrace_along_edges`; focused tests in `tests/FieldAlignedCurveNetworkTests.cpp` supply one positive reversed, differently segmented same-edge retrace and negative cases for same-direction, other-edge, detour and face-interior support. Both new frozen cases 997/998 passed. The helper has independent negative controls and can fail when retrace evidence differs; however there is **no A2a production caller**. Passing the helper tests proves only the isolated exact source-path relation, not correct singularity-port selection or lens removal. The existing four co-traced zero-area lens orbits 1/3/4/5 remain, and the seven failures persist. Do not alter validators, accepted selectors, failure classification or test assertions to obtain PASS.

## Recommendation — one bounded successor, no work in this Review

**Authorized next separate Code + Build turn:** `M6-CP3-CB-196-P13-ARRIVAL-PORT-OWNERSHIP-RECEIPT`. Add **only** a read-only, deterministic terminal-singularity **arrival-port receipt**, at the A2a producer’s existing exact arrival/candidate boundary. For each arrival at a singularity, print source entity, port identity, directed source-edge carrier and interval, arriving and existing trace identity, exact equality/overlap result, and the chosen classification. Apply the DESIGN D13=A ownership interpretation as **evidence only**; do not change trace selection, port ownership, region election, source geometry, terminal classification, or production behavior in CB-196. Compile/package exact code with GMP/GMPXX and execute no tests in that turn. The next immutable artifact-only Test + Benchmark gate is TB-EXEC-175 followed by TB-REV-175. A2a step-7 ownership repair remains **separate CB-197**, conditional on independent review of the receipt.

**Falsifiers and stop rules frozen before implementation:** the receipt must identify every retained singularity-arrival candidate without changing case population, stage outcomes, stable hashes (except explicitly added diagnostics), existing seven RED verdicts, accepted selector bytes, or fixture source. If any arrival is not supported by an exact source-entity path, if two distinct ports are conflated, if a complete loop/interval comparison cannot be made, or if a caller reaches the receipt only through isolated tests, fail closed and return to independent review. No broader source rework, helper wiring, selector expansion, production census, CB-197 step-7 repair, CP3 promotion, or runtime tests in CB-196. Test the receipt in its own TB gate with positive and negative arrival witnesses, structural invariance, and non-vacuous reader evidence.

## Review-process record

The initial review obtained multiple repository documents directly before switching to the mandatory source-snapshot read mode. This missed the policy's pre-read gate; the review corrected course and verified the exact source snapshot above. No product/runtime mutations resulted. A local independent log comparator initially under-normalized an elapsed-time suffix; its regular expression was corrected, and the complete comparison reran with the results above. Neither intermediate output is acceptance evidence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 `483f1101…2a038`, 994 `704dcf6c…e6209c6`; full hashes above |
| Decisive claims independently re-derived | 998 ledger identities; 996 inherited verdicts; 741+254+1 raw log comparison; both archive checksum manifests |
| Non-vacuity checked | Positive and negative isolated oracle controls; production caller absent, so no production acceptance |
| Prior obligations discharged/carried | D13=A discharged by DESIGN earlier; mechanical seven RED and A2a arrival ownership repair carried; row979 staged-only |
| Stable accounting | 67/17/50; debt1; deferred81; accepted TB169 993/993 and CP2 491/491; TB174 rejected 991/998 |
| New candidates/obligations recorded | No new stable regression; CB-196 diagnostic receipt and separate CB-197 repair scope |
| ORIENTATION currency line | TB-REV-174, 2026-11-23 (proposed in this review patch) |
| ORIENTATION §3 / §4 / §7 / §8 | Current gate and D13 resolution updated; historical facts retained and marked prior |
| CHANGELOG | TB-REV-174 independent decision added |
| ROADMAP | n/a — no checkpoint status advanced |
| Selector manifest | n/a — no selector accepted or altered |
| LESSONS | Existing single-writer and non-vacuity lessons apply; no new pattern |
| Consolidation under CLEAN_UP_POLICY | n/a — no obsolete standalone records deleted; no history discarded |
| Successor frozen | `M6-CP3-CB-196-P13-ARRIVAL-PORT-OWNERSHIP-RECEIPT`, with explicit falsifiers and stop rules above |
| Turn boundary held | No code, test, benchmark, selector, build or runtime mutation in review |
| review_check.py boundary | Pending separate report; cannot claim success without executable repository git history |
| `STATUS` lifecycle maintained | Entry beacon written; final beacon must follow successful publication of review work |
| Pushed to origin, branch in sync | Pending patch application and remote verification; do not assert otherwise |
