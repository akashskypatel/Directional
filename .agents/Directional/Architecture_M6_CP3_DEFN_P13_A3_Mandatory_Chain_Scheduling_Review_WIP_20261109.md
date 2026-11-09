# D5 Mandatory-chain scheduling — independent source-review WIP (2026-11-09 UTC)

**Canonical turn:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING`.
**Review status:** unfinished. This document preserves evidence and candidate rules, **not** an approved plan or successor Code + Build turn.

**Snapshot authority:** source SHA `8619797108487b7de8206a8a95f1560fbbf6420d`; workflow `42549408358`, artifact `13645155759`, ZIP digest `6e1e50932c6d3d28a958c2e6ed4ee44200facffe12900be48ce8104fde66192f`, **6,282/6,282** file hashes verified. Semantic CB109 compiled source `3f64cbf2c79ab580bbf97509142df1d5415c4404`. Predecessor TB92 **918/918** (membership 999), Cylinder PASS, BunnyRandom and Vase expected RED. Neither tests nor build nor runtime executed during D5 review.

## Verified architectural obstacle

- `EmbeddedGraphTopology.cpp:497–557` produces Mandatory A2b arcs from original source-edge intervals and splits at trace contacts.
- `RemeshPipeline.cpp:1005–1016` creates one A3 `ConformitySpanId::from_network_arc` for **each** A2b arc.
- `GlobalConformityBaseline.cpp:266–334` validates exact one-to-one span/arc binding; `:340–456` builds its parity graph over these original arcs.
- `SurfaceCellTracing.cpp:17449–17641` requires single-piece Mandatory support, positive per-arc counts and per-arc schedule lookup; no current A4 producer consumes a coalesced multi-arc Mandatory chain.
- `DESIGN.md §7.4` requires each full A2b arc to have a positive count. Moving positivity to a maximal-chain schedule **requires an explicit normative amendment**, coordinated producer and independent validator changes, and complete child-arc coverage; regrouping A3 spans alone would violate current authority.
- RA-216 and RA-217 already replaced earlier partition-sensitive preferred count and piece-index placement. D5 must reuse D7's exact metric runs and D7b's exact rational breakpoint placement.

## Candidate semantics requiring adjudication

A chain is an **A3 scheduling view** over unchanged A2b Mandatory arcs. Join only consecutive arcs having certified equal exact source endpoint, component/sheet, hard rail, original region/exterior incidence pair, compatible oriented region occurrence and unique nonbranching Mandatory continuation. Stop at trace contact, feature/singularity port, branch, region or rail change, barrier or ambiguity. Preserve other Trace/Cut arcs as singleton schedule units. Closed cycles require canonical rotation/reversal-invariant semantic identity, not source row or hash.

Each unit retains ordered original `NetworkArcId` children, exact support paths, orientations, original Mandatory edge lineage and all region boundary occurrences. One checked monotone chain-ordinal-to-child/source-piece map must preserve every original arc and each occurrence exactly once, with canonical half-open join ownership; physical points must reverse exactly even if local representations differ.

Use D7 preferred count and D7b ceiling-weight placement on the **concatenated exact chain**, with positive count per unit only *after* normative amendment. A child with no internal breakpoint must still have source-supported length and complete coverage; never invent zero-length edges or fake positive per-child entries. Construct parity/T-join on units only if every child has identical two incident region endpoints or region+component-local exterior. Re-expand the certificate to original region occurrences. Keep the independent exact validator, canonical lex-prefix tie-breaks and reciprocal Trace matching.

## Required independent positive and negative evidence (not yet run)

1. A real production-derived admissible multi-Mandatory-arc chain with a source-chart seam; a multi-piece **single** arc is insufficient.
2. A trace terminal that must break the chain; tampered continuation rejects.
3. Different component, sheet, rail, region, corner or branch that forbids merging despite positional coincidence.
4. Equivalent admissible support segmentation, reversal and source-row permutation produce identical physical counts/breakpoints.
5. Correct cyclic-start canonicalization or typed unsupported-cycle failure.
6. Tampered missing/duplicate/reversed/foreign original child, exact carrier, shared owner and region incidence must reject.
7. Unit count smaller than child-arc count must preserve exact original arc coverage and even region parity without T-junctions.
8. No regression or promotion of CP2 491/491, stable 66/17/49 debt1, 81 deferred, selector497/CP3 unpromoted.

## Unresolved and next same-turn action

**Q1:** Derive **actual** admissible Vase A2b joins, trace contacts, and source incidence from frozen production evidence. Reported 164 arc-level boundaries vs ~62 target is not proof that valid maximal chains reduce the schedule; prior 62/64 calculations are hypothetical, not measured A3 chain results.

**Q2:** Prove the original oriented child and region-boundary incidence is preserved through chain quotient, especially cycles and repeated forward/reversed region occurrences.

**Q3:** Freeze a minimal vertical producer+independent validator+read-only multi-child consumer, with real positive and tampered negative controls. D4 uniform/annulus, D9c, A2b, A4, D8 and D6 user decision remain separate.

**Q4:** Amend `DESIGN.md §7.4` explicitly for per-chain positivity, exact child lineage and quotient parity, only after the Review proves admissibility.

**Stop:** This WIP does not authorize a successor CB turn; no final D5 definition, normative amendment or Review closeout has been published. Follow this same canonical turn, not a guessed successor.

**Procedure disclosure:** Entry STATUS posted. Handoff/source docs were mistakenly read before choosing the mandated snapshot mode and completing policy reads; subsequent iterative inspection used the verified snapshot. The tool-call ledger was not initialized at the first invocation; exact total is unknown. A fuller local 103-line WIP review is separately preserved in the current conversation.
## Same-turn source-audit supplement (2026-11-09 UTC)

**Fresh authority:** exact snapshot SHA `18102b6249068f440dcb2150dfb2e014a9aa225c`, workflow `42551485386`, artifact `13645093415`; archive checksum and **6,283/6,283** source-file checksums verified. Static review only: no product, test, build or benchmark runtime.

**S1 — replacement is invalid without a new quotient contract.** `RemeshPipeline.cpp:1005–1016` generates one span per original A2b arc. `GlobalConformityBaseline.cpp:279–318` enforces the exact arc count and existing arc IDs; `:333–359` binds every original boundary occurrence. Supplying only aggregated chain spans fails this contract, while dummy zero-count original spans would breach DESIGN §7.4's positive-per-arc requirement. Preserve A2b as is; add a *certified scheduling quotient* and amend §7.4 explicitly before implementation.

**S2 — proof obligations for each chain.** For oriented children `(a0,…,ak)`, prove a unique nonbranching endpoint continuation without trace terminal, port, rail, region or sheet change; exact complete source-support coverage with neither gap nor overlap; original boundary occurrences (region, ordinal, orientation) preserved individually, even when repeated; all children have compatible region/exterior incident endpoints. A positive unit breakpoint sequence must cover every child monotonically, including children with no interior point. Canonical identity can ignore rotation/reversal, but the oriented child-to-unit map must retain sign and the exact `j ↔ n−j` reversal law. Never use source row order, positional proximity or hashes as equivalence authority.

**S3 — parity proof.** Unit-level T-join preserves original regional parity only if each incident region occurrence traverses the complete unit with correctly paired opposite/exterior ownership. Re-expand the independently validated certificate to original `(arc, region, occurrence, interval)` IDs. Equal boundary totals or plan digests alone cannot prove conformity or absence of T-junctions.

**S4 — Vase limitation.** Previous source-backed totals are 145 Mandatory and 3 Trace arcs, 164 outer subdivisions, Trace 10/4/9 and regions 70/94/46: `210=164+2*(10+4+9)`. They cannot identify any actual admissible pair of consecutive Mandatory arcs, true trace-contact nodes, or exact chain metric. The 142-edge OFF rim and historical hypothetical 62/64 counts are not a measured chain solve. No compression success is claimed.

**S5 — next same-turn evidence gate.** Obtain immutable read-only A2b/A3 evidence: oriented region walks; certified source-edge/terminal-node and rail bindings; each original arc's full support, metric, count, breakpoints and region/exterior occurrence ownership. Independently enumerate actual eligible maximal chains and forbidden joins, then freeze the minimal producer, exact validator and multi-child consumer with positive and tampered negative witnesses. Keep D4, D9c, reciprocal Trace, A4, D8 and D6 separate. This evidence is not present in the checked-in aggregate reports inspected; do not replace it with synthetic Vase joins.

**Review-check caveat:** `review_check.py boundary` was run on the archive; it reported clean product/test/selector working files but failed three durable ancestor checks because the source archive lacks `.git`. This is not an authenticated history-level pass. D5 remains unfinished; no CB successor is authorized.
