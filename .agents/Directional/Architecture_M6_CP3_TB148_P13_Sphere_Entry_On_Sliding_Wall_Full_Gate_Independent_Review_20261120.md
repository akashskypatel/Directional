# TB148 independent Review — exact sliding-wall contact ownership (2026-11-20 UTC)

## Situation

**Independent gate MATCH; sphere cut graph still fails.** This is an evidence-only Review of `M6-CP3-TB148-P13-SPHERE-ENTRY-ON-SLIDING-WALL-FULL-GATE-EXEC`. The four committed entry-on-sliding-wall contacts are exact, distinct source-edge interior positions and have no shared event. This upholds the narrow RA-269 contact-publication prediction, **not** its proposed causal/topology repair. No code, test, selector, production fixture or runtime execution changed in this Review.

## Background — independently opened evidence

- TB148 run `44668273156`; original artifact `14598534659`; outer ZIP SHA-256 `dac729fa05bb68c53c908476b4c32dfebe21f5f21d82743bcff58e31c7294c4e`. TB147 baseline artifact `14590664543`, ZIP SHA-256 `4fe8ddd8ab64669940fad176499cd77a739c798df7a931111fcd6ad5218ed372`. Both archives and their SHA256SUMS were independently rechecked.
- CB168J source artifact `14598581632`, ZIP SHA-256 `7d958a45613b560c59e58790b2aa4721403fdbf6dc2afe36e524c2911dfaabdd`, semantic compile source `d78404724a7f0bfb0c9c73769e6a68b9f2addd81`; source snapshot metadata verified `673615807739900fb12a981cf3770803e5df8f75` and inner archive hash. A later exact repository inspection snapshot `9181c85dfe0a23e6c733b470aa289b299af219c3`, run `44673210360`, artifact `14601125710`, ZIP SHA-256 `21f95e4a66513e4e21968282b0b6fa696e0e5509a43a8d806500b027792713e1`, 5623 source files, was also verified.
- Original required-gate manifest 963 selected, SHA-256 `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c`; deferred 81 unchanged (file SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`).

## Assessment — independent gate verification

1. Recomputed TB148 SHA256SUMS: **1934/1934** indexed files valid, **963/963** raw per-row log digests valid, manifest 963 selected identities unique with **963 PASS**, zero RED/missing/skipped/duplicate, **491/491** first accepted-prefix outcomes PASS. TB147: **1932/1932** indexed, **962/962** per-row logs valid, **962 PASS**.
2. Independently matched TB148's previous 962 row identities, binary/test names and verdicts against TB147. All **962/962** raw log records match with **only frozen N1–N3** normalization (Google Test duration and line ending; unchanged complete M3 diagnostic records compared by full-line multiset). 1738 complete M3 records were counted; rows164/172 reorder these intact records. No new normalization, selector update or accepted-prefix promotion. The check confirms 491 outcome/membership continuity; it does **not** claim a new independent hash of the historical CP2 491-row source selector.
3. The new row963 test is **non-gating as to contact truth**: source asserts 24 committed traces and trace identifier order; it prints `committed`, exact carrier entry/slide parameters, `strictlyInside`, helper agreement, and `sharedEvents` without asserting those facts. Its PASS is therefore not independent ownership proof. The Review inspected the entire four printed records and the source expressions independently, and used the exact source-edge paths to distinguish the narrow observation from final topology.

### Four complete source-edge interior contact observations

| Moving trace:segment | Wall trace:segment | Carrier edge | Exact parameter | Slide interval | Shared event count |
|---|---|---|---|---|---:|
| 17:8 | 0:6 | (6,8) | 4038890029339747/4503599627370496 | 707873584687237/2251799813685248 to 1 | 0 |
| 20:8 | 1:6 | (16,21) | 4038890029339747/4503599627370496 | 707873584687237/2251799813685248 to 1 | 0 |
| 5:8 | 21:6 | (33,34) | 1009722507334937/1125899906842624 | 707873584687237/2251799813685248 to 1 | 0 |
| 8:8 | 22:6 | (45,46) | 464709598030749/4503599627370496 | 1543926228998011/2251799813685248 to 0 | 0 |

Each has `committed=1`, `movingEntryOnCarrier=1`, `previousExitCarrier=1`, `previousSlides=0`, `wallOutgoingIsCarrier=1`, `sameFace=1`, `strictlyInside=1`, `contactAgrees=1`. All four source-edge topology keys differ. These are not four duplications of one chart alias. `sharedEvents=0` is a complete pairwise event-list inspection performed by the test, not proof that the rest of the graph is free of vertex meetings.

### Root-cause boundary and new implementation constraint

- In `SurfaceCellTracing.cpp` near 4430, `reportEntryCoincidence` logs a contact if either end slides and returns without publishing. Both pending/pending and committed/pending loops retain only `ProperCrossing` from the face-chord classifier; `field_aligned_segment_exit_point` uses the early transit entry, not the later slide exit. The existing exact slide-arrival calculator around 5849 is not wired into this classification.
- `EmbeddedGraphTopology.cpp` near 878–948 and 1798 constructs real face+edge pieces and consumes the sliding source path. It does not synthesize a shared cut event at the four measured loci. The row686 independent graph oracle instead represents the wall's sliding piece as a face chord (`FieldAlignedCurveNetworkTests.cpp` near 8421/8567); its current Euler result is therefore a chord-based observer, not an independent traversal of the edge-slide network. This oracle must change only with the separately controlled H4 cutover at CB169, never by silently changing its acceptance criterion now.
- **New precision constraint:** `carrier_contact_struck_position` in `EmbeddedGraphTopology.cpp` near 821–840 currently matches only an exact entry. Its existing `TraceCutPosition` with an optional scalar parameter is evaluated by `exact_trace_interior_point` near 956–973 on a **face chord**, even when the committed segment has an edge slide. Merely filling that parameter with the wall's source-edge parameter would create a false face point, and could violate path support. An inert exact struck-in-slide **contact discriminator** is supported; changing graph cut-position semantics or publishing a cut node is **not yet justified** by this receipt alone. Require a separately frozen piece-aware representation before any live switch.
- Row686 remains `V=18 E=30 F=18 c=1 chi=6 sourceChi=2`, excess **+4**, `cutCrossingNodes=0`, `cutCrossingArcs=0`; all measured face components are discs. Rows669 and 698 still end with `CutSearchExhaustedBeforeCellularity`. Four unowned slide contacts equal four units of excess numerically but no independent topology rewrite has shown that registering them yields `chi=2`. The earlier two mutually published carrier ends remain distinct and valid; do not count them as new slide contacts.

**Falsifiers:** The slide hypothesis fails as a complete correction if a piece-aware authoritative graph with these exactly four contacts still gives `chi!=2`, requires another vertex meeting, has invalid arc incidence, or yields different counts. The four-pair ownership claim fails if any authentic shared event on the same source edge/parameter is found (none in the immutable row963 evidence). The proposed consumer fails if it uses a chord parameter to represent an edge slide, accepts slide endpoints as interiors, mixes opposite/source sheets, or changes product behavior while labeled inert.

## Recommendation — exactly one bounded next turn

Freeze `M6-CP3-CB168K-P13-EXACT-SLIDE-INTERIOR-CONTACT-CONSUMER` — **Code + Build, compile-only**, as defined in [Architecture_M6_CP3_CB168K_P13_Exact_Slide_Interior_Contact_Consumer_Plan_20261120.md](Architecture_M6_CP3_CB168K_P13_Exact_Slide_Interior_Contact_Consumer_Plan_20261120.md). It may introduce only a source-edge-exact *inert* contact discriminator for a struck trace sliding through a carrier interior, with independent positive/negative test data and no production call-site switch. It must not shoehorn a slide point into `TraceCutPosition`'s face-chord scalar, and it must not build or publish a graph event. Compile the eight mandatory GMP/GMPXX targets with `runtimeExecution=false`; no binaries in Code + Build. A separate later Review must freeze a path-piece-aware position representation and producer switch in **both** loops, with the existing slide-arrival ordering. A subsequent immutable TB must falsify the claimed repair, including independently correct edge-slide graph Euler `chi=2`, rows669/698 passing, previous gate/prefix continuity, and full path/ownership validation. Do not start any of those turns here.

Preserve C5/O47, O48/O49, H4, FC-6, terminal-cut/row858 holds, `chainRimSchedules=false`, stable **66/17/49**, produced-witness debt **1**, deferred **81**, CP2 accepted **491/491**; CP3 497 identities, D0 and selector497 remain **unpromoted**. TB148 had **no** new three-case census; only TB147 supports the earlier Cylinder PASS/BunnyRandom and Vase expected RED.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB148/TB147 manifest first-491 identities and outcomes compared; 491/491 PASS, 962/962 prior row equality. Historical CP2 selector source bytes not independently re-hashed; the Review does not claim that stronger check. |
| Decisive claims independently re-derived | Both ZIPs, 1934/1934 and 1932/1932 inner hashes, 963/963 and 962/962 raw digests, 962/962 N1–N3 comparison, four exact receipts and row686 Euler arithmetic. |
| Non-vacuity checked | Row963 only asserts trace count/identifiers, not contact condition; four full printed exact observations separately examined and their source flow audited. Causal topology still unproved. |
| Prior obligations discharged/carried | RA-269 exact unowned slide-contact prediction upheld narrowly; C5/O47, O48/O49, H4, FC-6, row858, D6/D10, debt1 and deferred81 carried. No semantic repair. |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt1; deferred81; CP2 accepted 491/491; CP3/selector497/D0 not promoted. |
| New candidates/obligations recorded | Exact-slide-path position contract added to O47/C5 in tracker; no new stable event. The face-chord parameter is prohibited as a substitute. |
| ORIENTATION currency line | Updated to TB148 independent Review, 2026-11-20. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated exact gate, four witnesses, open producer/consumer obligation and recurring position-type mismatch; stale TB147 denial superseded in place. |
| CHANGELOG | Added one TB148 Review entry. |
| ROADMAP | M6-CP3 remains in progress, with current evidence line updated; M7 not entered. |
| Selector manifest | n/a: Review changes no selector or accepted membership. |
| LESSONS | Existing **Semantic ownership, identity, and dataflow** and **Witnesses, tests, and independent oracles** cited; no new generalized rule required. |
| Consolidation under CLEAN_UP_POLICY | Current TB147 review/RA-269, CB168J compile, TB148 execution and new Review remain live evidence dependencies. No safe fold of current authority; no deletions. Historical supersession still indexed. |
| Successor frozen | Exactly `M6-CP3-CB168K-P13-EXACT-SLIDE-INTERIOR-CONTACT-CONSUMER` with bounded stop conditions in linked plan. No successor work executed. |
| Turn boundary held | Runtime-free independent evidence inspection; no product/test/fixture/selector/build source changes. |
| review_check.py boundary | To be run against the local verified snapshot; no git-history authority in an archive, so ancestry checks cannot be claimed. |
| `STATUS` lifecycle maintained | Entry beacon published for TB148 Review; final direct STATUS write will be the last repository mutation. |
| Pushed to origin, branch in sync | Documentation apply/push is verified separately by dispatcher result; local snapshot lacks authoritative upstream tracking and cannot provide a meaningful `git status -sb` branch-sync attestation. |

**Tool-use/read-mode process disclosure:** initial direct GitHub document reads preceded the mandatory snapshot-mode selection. That breached the conservation pre-read gate; the agent stopped piecemeal source retrieval, obtained a verified exact snapshot for further source analysis, and did not use this process miss as permission to change acceptance or selector evidence. The call ledger before compaction was not retained as a fully exact namespace count; do not substitute invented totals.

## RA-270 — adversarial re-review of this Review (2026-11-20 UTC)

### S1 — What holds

- Gate arithmetic (963/963, 491/491, 962/962 MATCH TB147) and the four row 963 receipts are upheld. RA-269's prediction held field for field: `committed=1 … strictlyInside=1 contactAgrees=1 sharedEvents=0` on four distinct carriers.
- The constraint that a slide point must not be encoded in `TraceCutPosition::parameter` is correct, with one accuracy fix. Doing so would not "create a false face point": it fails closed. `exact_trace_interior_point` (`EmbeddedGraphTopology.cpp:955`) needs `trace_segment_canonical_exit`, which returns nullopt for any sliding segment (`:803`). `exact_trace_piece_path_between` (`:1018–1020`) also rejects clipping a sliding segment. The conclusion stands: no cut position on an edge-slide piece exists today.
- Keeping the row 686 oracle unchanged until H4 is correct.

### S2 — Design defects of this Review

1. **The deciding measurement is missing: which trace is later at the contact.** The repair's shape depends on it, and nobody has measured it.
   - **If the moving trace is later**, it stops at its entry point. Its record is the existing carrier-stop shape (CB168G `field_aligned_carrier_stop_contact`: last segment face, leaving through the locus edge). Only the *struck* side is new: a cut position inside the wall's slide.
   - **If the wall is later**, the wall should have stopped mid-slide when its slide was pending. But `first_field_aligned_carrier_contact` never compares a slide with another trace's committed *exit* point, so that contact was never even detected. The repair would need a new detection plus an end-inside-slide record, and `exact_trace_segment_pieces` (`:907–921`) currently accepts a terminal contact only on the face piece.
   - **If inconclusive** against a retired wall, the existing rule fails closed (`ContactInconclusiveAgainstRetiredWall`).

   Freezing a consumer before this is known repeats the RA-266 lesson (give the switch its deciding measurement). Corroborating evidence: two of the four records have moving index > wall index (17/0, 20/1). The pending/pending loop always reports the lower index first, and would have printed the pair with `movingInSlide=1`. So all four come from the committed-wall loop, and the receipt can say so (`wallCommitted`).
2. **The frozen successor is again a prose plan, and dead code if built.** `CB168K-…-EXACT-SLIDE-INTERIOR-CONTACT-CONSUMER` asks the implementation agent to design a helper. That helper restates `first_field_aligned_carrier_contact` (which already returns carrier, parameter and `wallInSlide`) plus a strict-bounds check. It explicitly defers the representation that is actually missing (a piece-aware cut position, arc split and node locus) to a later Review. It is not an exact diff, it has no reader, and it can't move χ. **Withdrawn.**
3. **The row 686 oracle becomes a precondition, not a bystander.** After a stop-at-entry switch, the moving trace ends at a point on the wall's *edge slide*. The oracle cuts the wall's segment as the chord entry→slide end, which does not pass through that point. So the endpoint would not lie on any oracle fragment boundary, and row 686 would misread. The oracle's slide reading (an H4 consumer) must therefore switch **before** the TB that reads χ on the repaired graph, not at CB169. Recorded.

### S3 — Frozen successors

- **`M6-CP3-CB168K-P13-SLIDE-CONTACT-ARRIVAL-RECEIPT`** (Code + Build, compile only; diagnostic only).
  - [Exact diff](Architecture_M6_CP3_CB168K_P13_Slide_Contact_Arrival_Receipt_Exact.diff), SHA-256 `fc70c9aa07ea31f4121ac297f7bc24fca3f82ffadec6ef6880b82f8d99ecb4a4`, numstat `28 0 src/geometry/SurfaceCellTracing.cpp`, preimage `ecbf1470e3c04ab31e8bb244dd6b7a34652d40931502254c16aec447889322f5`.
  - Inside the existing slide branch of `reportEntryCoincidence`, after the `slideCoincidence` line and only for `!movingInSlide && wallInSlide`, it prints one line: `FieldAlignedCurveNetwork.slideContactArrival moving= wall= wallCommitted= movingArrival=earlier|later|inconclusive|unavailable`.
  - The wall's arrival comes from the accepted `field_aligned_arrival_at_slide_parameter` on the wall's start arrival. It is compared by `field_aligned_compare_priority_arrivals(priority, moving, wall, movingIndex, wallIndex)`, the same call and order the wall loop uses for crossings.
  - It is deduplicated with the slide line. Scheduling is unchanged.
  - Precheck: `git diff --quiet d78404724a7f0bfb0c9c73769e6a68b9f2addd81 HEAD -- src include tests`; `git apply --check`. `-fsyntax-only -Wall -Wextra -include iterator`: 43 warnings, equal to HEAD, 0 errors. Eight RA-245 targets, `runtimeExecution=false`.
- **`M6-CP3-TB149-P13-SLIDE-CONTACT-ARRIVAL-FULL-GATE-EXEC`.**
  - Inputs: immutable CB168K package; unchanged TB148 manifest `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c` (963+81); unchanged 3-row census manifest `3af1dc0d…e793` and harness.
  - STOP on failure: delete every line starting `FieldAlignedCurveNetwork.slideContactArrival`; then rows 1–963 MATCH TB148 under the frozen rules (N1–N3), with 491/491. Run the census only after the gate passes: 3/3 MATCH TB147 after the same deletion.
  - To Review, verbatim and deduplicated per row: every `slideContactArrival` line from the 20 sphere rows and the 3 census rows, with counts.
  - **Prediction (not STOP):** the four sphere pairs print `wallCommitted=1 movingArrival=later`.
- **`M6-CP3-TB149-…-REV` decision table.**
  - All four `later`: freeze, as separate exact CBs,
    - (a) a piece-aware cut position on a slide's edge piece, with path, arc split and node locus, inert, with an injected test;
    - (b) the row 686 oracle reading slides as real face+edge pieces, test-only, with expected χ unchanged at 6 before the switch;
    - (c) the wall-loop producer stop (the moving trace ends at its entry with `carrierLocus`; struck = wall segment inside the slide);
    - (d) a TB with falsifiers: row 686 χ = 2, rows 669/698 past exhaustion, and four Terminal/Interior events on four nodes.
  - Any `earlier`: a slide-vs-committed-exit detection receipt first.
  - `inconclusive`/`unavailable`: design stop in the Review.

### S4 — Sequence

CB168K → TB149 → TB149-REV → (all later: slide-piece cut position CB → oracle slide-piece CB → wall-loop stop switch CB → TB; else the detection receipt) → CB168 binding → [O49] → CB169 H4 remainder → CB170 → CB171 → CB172 (O48). Held: FC-6, TERMINAL-CUT-OUTCOME, row 858 DEFN. Parked: CB145. D11=A, D12=A.

### S5 — Closeout

Runtime-free: `-fsyntax-only` on CB168K. Code read: the contact loops, the slide-arrival helper, and the cut-position/path functions in `EmbeddedGraphTopology.cpp`. No product, test, selector or manifest bytes changed. The withdrawn consumer plan is marked as withdrawn. Accounting unchanged: 66/17/49, debt1, deferred81, CP2 491/491, selector497 not promoted.
