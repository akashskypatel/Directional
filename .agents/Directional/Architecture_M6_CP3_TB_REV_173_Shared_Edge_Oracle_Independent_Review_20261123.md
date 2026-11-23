# M6-CP3-TB-REV-173-P13-SHARED-EDGE-ORACLE-FULL-GATE — independent review, 2026-11-23 UTC

## Situation
**TB173 is rejected as a production gate.** Independent review of immutable archived evidence finds 989/996 passing and seven mechanical failures. Neither direct surface-cell production nor CP3/497/D0/H4 acceptance is established. The user decision D13 remains unresolved; no follow-on producer repair is authorized.

## Background — exact immutable authority
- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft. Compiled semantic source `fae9eb71bb5806d71901cc2ccb8c925201be0c0a`, GMP/GMPXX artifact `14820355596`; TB173 did not rebuild.
- TB173 run [45180338549](https://github.com/akashskypatel/Directional/actions/runs/45180338549), result artifact `14821438542`; independently downloaded ZIP SHA-256 `22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`, all 2000/2000 packaged member checksums match.
- TB172 run [45149928894](https://github.com/akashskypatel/Directional/actions/runs/45149928894), result `14805479282`; ZIP SHA-256 `e9ddc7fd80d3e33b25b18901c783fbb21ec2eaf5c1b86438f887e93cee03edbc`, 1996/1996 verified.
- Last accepted TB169 result `14787082075`, ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`, 1994/1994 verified. TB169 **993/993 accepted**, CP2 **491/491 accepted**.
- Exact source snapshot SHA `9de745e0e8298353c2e3f0c75edbcbe1c44c6606`, snapshot run `45188361323`, artifact `14823069465`; 5803/5803 hashes and enclosed source tar verified. This includes control-only STATUS and snapshot marker after the semantic source was frozen.

## Assessment — independent recomputation
1. Recomputed from the TB173 complete result ledger: 996 selected, 989 PASS, seven RED (rows **445,652,653,656,658,660,786**), none skipped or abnormal, CP2 candidate 490/491, total membership 1077 (996 selected + 81 deferred). The same seven mechanical rows were RED in TB172 (987/994); no eighth regression.
2. Recomputed the TB173 996-row manifest SHA-256 `b54de0b28dc646b465daae0d40dd7874f550567fb904647c7dff36a4f2e2ff6e`; header plus first 491 rows SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` (**exact accepted CP2 selector**). Header plus first 994 rows SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6` (**exact TB172 manifest**). Rows 995/996 are only new cases and both PASS.
3. Compared all 994 common row identities, verdicts, diagnostics and raw complete transcripts. Raw timing differences occur in 252 logs; after **N1 elapsed-time replacement** and **N2 line-ending normalization**, all 994 logs match. No N3 reorder, asserted-source-location exception, row deletion, or changed site is needed. TB173 did not repair TB172's seven failures.
4. **Helper non-vacuity:** `ExactSourcePath.h::exact_source_paths_shared_edges` compares positive-length exact source-edge parameter overlap across full piece arrays; the result uses canonical edge identity and interval endpoints, ignores traversal direction, sorts and removes duplicates. Test `FieldAlignedCurveNetworkTests.cpp` includes mixed-carrier reversed co-tracing and partial overlap positives, plus point touch, crossing-face chord, and corner-to-edge face-piece negatives. A helper that returns empty would fail positives; a helper that accepts all shared endpoints would fail negatives. These tests are meaningful **isolated helper** evidence. Static code-reference inspection found no production `.cpp` consumer of the helper. The tests do **not** establish that A2a invokes the oracle, that two traces cannot share an edge, or that a singularity arrival consumes its port. A production/source-path end-to-end non-vacuity witness remains required.
5. **Source-owner finding:** the four mechanical lens regions (orbits 1,3,4,5) remain source-edge co-traced zero-area digons, not legitimate regions to be discarded by the region consumer. A2a seeds ports without arrival ownership checks, filters out `CollinearOverlap`/`EndpointTouch`, and records only origin ports at termination; prior adversarial C1–C4 and source confirmation locate responsibility upstream. The exact shared-edge oracle gives a falsifier, not a repair. Row652 still stops `RegionElectedCutComponentEmpty`; staged row979 is `RegionContainsInteriorSingularity`, not production acceptance.
6. **Classification:** existing accepted-green mechanical regression continues. No new stable event/category/recurrence: **67 / 17 / 50**, produced-witness debt **1**, deferred **81**. Keep the existing candidate in the regression tracker; require no new category. Never count green isolated helpers as a production pass.

## D13 — owner decision is required before source repair
**Question:** What should happen when a trace reaches a singularity along that singularity's own port direction?
- **A (recommended, not approved):** arrival owns that port; one trace per saddle connection; canonical and independent of trace order. A2a must record arrival-port identity.
- **B:** mutual head-on stopping; endpoint may depend on processing order.
- **C:** merge in downstream stages; conceals the A2a ownership violation.
- **D:** discard empty regions; retains co-traced zero-area faces.

**Decision pending.** Do not infer consent from this recommendation. Do not start CB-195, CB-196 or any repair/activation. After an explicit D13 decision, the **only proposed next Code + Build** is `M6-CP3-CB-195-P13-ARRIVAL-PORT-OWNERSHIP-PROOF`: add an exact arrival-port receipt and integrate the already tested shared-edge oracle into a mechanical producer witness without changing producer behavior. Falsifiers: any positive overlap remains accepted as valid, any distinct nonoverlapping trace is rejected, any arrival port remains unrecorded, or the recorded port depends on traversal order. STOP on missing complete exact path/port authority; no source behavior wiring or test execution during that Code + Build. Its subsequent immutable TB and independent Review are separate turns. CB-196 is conditional later wiring and must not be started as part of CB-195. If D13 does not select A, this CB-195 proposal must be re-reviewed rather than presumed approved.

## Prior obligations and limits
- TB-REV-172 C1–C7: C1–C4 rechecked/carry A2a root; C5 helper non-vacuity checked; C6 comparator allowance independently reconciled (no line moves); C7 mandatory edges excluded by the recorded orbit coverage. D13 remains pending. CB-195/196, row979, Branch A, CB-190, CP3/497/D0/H4 remain held.
- Evidence-only review: no source, tests, benchmark, selector, or fixture mutation, no binary execution/rebuild/census. Source was inspected from a verified snapshot. The synthetic local snapshot does not provide authenticated git history; it cannot independently verify `git status -sb` against origin. Remote patch-push verification is required after documentation transport.
- Procedure deviation: initial control-policy/document connector reads preceded the explicit snapshot READ_MODE gate. Subsequent static inspection used the verified snapshot. The tool-call ledger was not started at the first invocation, so a complete tool-use count is **unknown**; no exact total is claimed.

## Recommendation
Keep this review current pending an explicit D13 answer. Reject the TB173 semantic gate. Preserve the previous 993/993 accepted TB169 and 491/491 CP2 baselines, the seven mechanical REDs and the full archive evidence. Do not promote CP3 or begin successor implementation without the owner decision and a separate accepted turn boundary.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491-row `483f1101…038`; 994-row `704dcf6c…09c6`; complete 996-row `b54de0b2…ff6e` |
| Decisive claims independently re-derived | Three immutable ZIP and member hash checks; 989/996, seven RED, 994 exact common transcripts N1/N2, membership 1077 |
| Non-vacuity checked | Positive/negative helper tests distinguish missing and overbroad overlap; production call absent, not validated |
| Prior obligations discharged/carried | TB-REV-172 C1–C7 audited; D13 pending; CB-195/196, row979 and activation held |
| Stable accounting | 67 events / 17 categories / 50 recurrences, debt1; TB169 993/993, CP2 491/491 accepted, deferred81 |
| New candidates/obligations recorded | No new stable event; existing tracker regression updated with D13/A2a, new owner decision outstanding |
| ORIENTATION currency line | TB-REV-173, 2026-11-23 |
| ORIENTATION §3 / §4 / §7 / §8 | Current gate, witness, owner decision and non-vacuity carried; stale current-next claims corrected |
| CHANGELOG | TB-REV-173 review outcome recorded |
| ROADMAP | M6-CP3 still in progress, TB173 rejected, D13 decision pending |
| Selector manifest | n/a: no selector change authorized in Review; 491/994 prefixes rehashed |
| LESSONS | Existing non-vacuity and single-writer/owner authority lessons apply; no new generalized lesson |
| Consolidation under CLEAN_UP_POLICY | n/a: no obsolete reports removed; accepted and rejected immutable archives remain authoritative |
| Successor frozen | No executable successor authorized while D13 unanswered. Conditional CB-195 exact bounded scope/falsifiers in D13 section; CB-196 not started |
| Turn boundary held | No runtime, source, test, selector or fixture modifications; review documentation only |
| review_check.py boundary | NOT PASS (static checker exit 1); synthetic source snapshot lacks origin Git history; rable rewrite source: Future_Chat_Session_Handoff.md; durable rewrite source: ORIENTATION.md; durable rewrite source: Regression_Root_Cause_Tracker.md |
| `STATUS` lifecycle maintained | Current turn entered 2026-11-23T13:51:03Z; D13 review blocker pending; final beacon direct-write at end of response |
| Pushed to origin, branch in sync | PENDING_REMOTE_TRANSPORT — update only after exact pushed-document verification; synthetic snapshot is not origin history |
