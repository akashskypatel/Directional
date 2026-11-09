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
## Same-turn verification and evidence route (2026-11-09 UTC)

- **Exact source review:** snapshot `18102b6249068f440dcb2150dfb2e014a9aa225c`, workflow 42551485386, artifact 13645093415; nested tar plus **6,283/6,283** individual file hashes verified. No product/test/selector/source mutation or project runtime in Review.
- **Source-derived D5 quotient proof:** [D5 incidence proof gates](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Incidence_Proof_Gates_20261109.md) preserves the original A2b arc-to-schedule binding, join/admissibility criteria, D7/D7b exact support identities, original region occurrence expansion, parity proof and test tamper matrix. Per-arc positivity under DESIGN §7.4 remains normative; no scheduler/consumer rewrite is approved.
- **Immutable runtime evidence checked:** TB92 census artifact 13643067924, ZIP digest `7bd174072c806555c4fd98251b3cfc29e2ac674b737b6becd5ab5ceb72a3dd76`, 9/9 inner checksums. Vase's registered completion RED, original stage digests and A3 coverage were observed, but per-original-arc incidence, support carriers and exact breakpoint-to-child mappings were **not** serialized. The 145/3/164 count summary cannot independently establish any admissible maximal chain.
- **Smallest observable evidence route:** [D5 evidence recovery](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Evidence_Recovery_20261109.md) identifies existing retained A2b/A3 product snapshots accessible at the Vase acceptance test return seam, even following a completion-stage rejection. **Governance correction:** RA-214 §1.3/§2 explicitly forbids a diagnostic-only CB; the earlier test-only exporter proposal is **withdrawn**. The next candidate is a retained production Mandatory-chain topology view plus an independently checked verifier, to be observed in its separate artifact-only TB. See the corrected evidence-recovery review; this product slice is not frozen or executed.
- **Remaining Review work:** freeze the exact retained chain-topology product/validator CB and TB with falsifiers; measure the actual Vase join partition before switching A3 counts or A4 consumers; make the required normative amendment and complete the policy §5 review closeout only when evidence supports it. The source snapshot has no `.git`, so a history-dependent `review_check.py boundary` pass cannot be established from it; no such pass is claimed. Prior execution statements have not been independently reproduced in this turn.

**No D5 final plan, successor implementation authorization, direct Vase compression, D6 decision, or CP3 promotion is claimed.**
