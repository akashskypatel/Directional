# TB18 independent review — evidence re-derived; history gate pending (2026-10-20)

**Turn:** `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV`. **Basis:** RA-103.5; TB18 Part A `39349041417` / `12231529583`; Part B `39349459268` / `12232299548`; CB18 source `3bd24682c5e18eece541ab4d1f38f781a2230e41` and package `12227516380`. Review is **unfinished** until a history-backed `review_check.py boundary` check and closeout; this document is not a promotion or successor authorization.

## Independent re-derivation

- Both ZIP hashes recomputed exactly: A `e08b092d9451d912ead323b7f514d97512eb3c02b4c4971333ecb0498caab459`; B `b3ba45665f900d917c96af223118c49594bd8651a488a08ab9f9f74d5e4a6e9b`. Every manifest entry validated independently, A **18/18**, B **1019/1019**; archive files reconcile with their self-excluding manifests.
- Recomputed from 497 `combined-ledger.tsv` identities, not from the TB18 report: focused30 **19 PASS/11 RED**, focused12 **12/0**, selector449 **417/32**, cp3entry **0/6**, overall **448 PASS/49 RED**. All identities unique, selected once, 0 skipped; every raw log SHA-256 matches its ledger. All 49 RED identities, raw hashes, first failure context, baseline membership, and inventory status independently matched the retained 49-row TSV. The inventory's SHA-256 recomputed as `36cc9682cab7ceac02beca2a8ee25b2231bc3f33ffa768d03e1ade3dc142b9ca`.
- Compared the complete 497 keys with TB16C's retained 72-RED TSV: **23 RED→PASS, zero PASS→RED**; no new RED. All **30** TB16C B2 identities now have **16 PASS / 14 RED** at another first observable; B1=0, B2=0, B3=0, B2+B3=0, U6=0, other=49. The one `firstPredicate` precedence case, selector405, is correctly classified other: its diagnostic reports `a3ProbeContactPublished=0`; RA-91.2 excludes vacuous B2.
- Part A independently read from `ledger.tsv` and all 14 raw logs: #1–#9 and #12–#14 PASS; #10/#11 RED with the exception `non-constant internal-midline hard-rail rectangle producer failed: PublishedProductRejected`. All four `gate` tests (#1–#4) PASS and no B2 first predicate survives in #8–#12. #14 `ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` PASS includes a positive checked-factory call and three single-field forged-tag negatives, so its witness is not vacuous. The universal statement “every consumer-certified R route is factory-admissible” remains unproved by this selected witness; #10/#11 abort earlier in their producer fixture.
- Execution-boundary receipts show immutable package/source/view/selectors, Part A 14/14 selected and B 497/497, neither a rebuild nor relink, benchmark, discovery regeneration or source/test mutation. No new stable accepted-green loss; **66 events /17 categories /49 recurrences, debt 1**, accepted M6 CP2 **491/491**, rejected R3 **403/497** and frozen CP3 selector 497 all stay unchanged. `RP-01` open; `RP-02` UNREACHED; Gate C suspended.

## Residual issues / continuation

1. **History-sensitive Review boundary unavailable in source snapshot.** Ran `python3 .agents/Directional/tools/review_check.py boundary`; exit 1 because the downloaded source snapshot has no real `.git` history: rewrite-base `8b7299b43` is absent, and three durable baseline sources cannot be read. Other results suggesting selectors “untracked” are not valid proofs. **Do not synthesize Git history or mark the review COMPLETE on that result.** Re-run the mandated check in an actual authorized checkout with committed history and record its full result; re-check durable-heading preservation, selector hashes and no product/test/fixture changes before closure. The GitHub compare of `f6e28c8e3751…d0b6de8de105` shows only documentation/control changes, but does not replace history-sensitive gate execution.
2. **Unresolved observed Part A fixture producer failures:** #10/#11 now `PublishedProductRejected`; independently localize the earliest producer owner and fixture prerequisites before any corrective source modification. No justification to change U5 semantics, suppress diagnostic rejection, or promote CP3 on two exceptions. All A falsifiers **except universal factory coverage** are not triggered; universal coverage remains undetermined rather than proven false.
3. **Conditional next unit after review completion:** RA-96.6's first fixture-debt item is selector242, `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed` (P10:3258–3310). At P10:3286 it tampers `crossField.edgeTransitions`, while P10:3295–3298 constructs `FieldTransportAtlas` from the unmodified `sourceField`; the production call then consumes that atlas. The resulting `Produced` instead of the expected `InvalidTopologyRegionTransport` is a **test-specification defect** per RA-92.3, not stable semantic loss. The successor must be explicitly reviewed and bounded: a single test-only CB that tampers the authoritative atlas-owned input (or proves why that is not supported), with a valid Produced control, target rejection and tamper non-vacuity. Carry 174 → 250 → adjacent-sheet → 191 → 442 and I/R assertion-site debts separately in RA-96.6 order. **No CB is authorized by this unfinished review.**

## Review closeout (unfinished; carry to continuation)

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector edits; historical committed-prefix verification awaits history-backed boundary |
| Decisive claims independently re-derived | ZIP/manifests, 497 ledgers/raw SHA, 49 first failures, 30 B2 identities, TB16C comparison, 14 Part A outcomes |
| Non-vacuity checked | Part A #14 has positive/negative factory assertions, but universal R-factory quantifier remains unproven |
| Prior obligations discharged/carried | RA-103.5 measured predicates discharged; universal factory scope, producer #10/#11, RA-96.6 debts carried |
| Stable accounting | 66/17/49; debt 1; CP2 491/491; CP3 not accepted; 497 frozen |
| New candidates/obligations recorded | no stable event; existing TB18 candidate still unpromoted; producer and gate items above |
| ORIENTATION currency line | 2026-10-20 WIP review; edited in accompanying patch |
| ORIENTATION §3 / §4 / §7 / §8 | §3,§7 current; §4 unchanged fixture matrix; §8 existing premature-credit/non-vacuity patterns sufficient |
| CHANGELOG | pending final independent adjudication; do not enter completed review prematurely |
| ROADMAP | CP3 unchanged; stale dated boundary replaced with current candidate status |
| Selector manifest | n/a — no selector membership or acceptance changes |
| LESSONS | existing Evidence / Witnesses / Diagnostics lessons apply; no new reusable principle |
| Consolidation under CLEAN_UP_POLICY | pending completion; no historical evidence retired or deleted |
| Successor frozen | pending history-backed gate; no successor authorized during incomplete review |
| Turn boundary held | review only; no runtime, compile, product/test/fixture/selector changes |
| review_check.py boundary | **FAIL — no .git in immutable source snapshot; mandatory real-history rerun pending** |
| STATUS lifecycle maintained | same canonical TB18-REV and original started timestamp; incomplete yield uses IN_PROGRESS |
| Pushed to origin, branch in sync | pending patch publication and GitHub branch-head verification |
