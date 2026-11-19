# TB143 entry-coincidence receipt — independent full-gate review

## Situation

**REVIEWED — strict prior-log MATCH rejected; two isolated output-layout exceptions remain.** The immutable TB143 gate executed 960/960 rows (959 PASS, known row 858 RED); the three-case census executed 3/3 (Cylinder PASS, BunnyRandom and Vase expected RED). Independently compared 959 prior gate logs and three prior census logs to TB142: **957/959 gate plus 3/3 census equals 960/962 strict matches** under frozen N1–N7. Rows **169** and **477** do not satisfy N3, so neither 959/959 nor 962/962 may be claimed. No new stable regression or product acceptance follows.

## Background — exact evidence

Immutable source `b77a81ff5250aabbf6dd58cf4e9e6c208d4a973f`, package `14488684741`. TB143 gate artifact `14490999571` SHA-256 `ffa03f7e359eeed8e76ad3f4f7a1624bed5f69d44c97a50b860939a8a044b11d`; TB143 census `14492518198` SHA-256 `4089fc0de5bf38620f98e077b80a0b00706c17240869ff564ff36eb9b8b7cfa1`. TB142 gate `14482831297` SHA-256 `a4352cf815bd8796bf4e2fa7e61ef900c29a034a23fa520e611872bbd385bc51`; TB142 census `14482339143` SHA-256 `4f245848bd9005b28fcf75d6cc66cc9a02fba9cc2fdc5ded9977f1d49b65ad64`. Independently checked all four ZIP SHA-256 and **3,874/3,874** indexed internal hashes. Source snapshot run `44448914197`, exact snapshot SHA `7b308f1ea02ce604ac5858e7ea8335f86e98920f`, artifact `14494611487` ZIP SHA-256 `e768689129523ebe0c7883a1d313fb96d3a794913198c6347e5ebf80834e6cf7`, 5,594/5,594 source file hashes verified.

Accepted selector prefix: 30 SHA-256 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, 12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, 449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; concatenated 491 selectors SHA-256 `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`, 491/491 PASS. Gate membership 960+81 deferred = 1,041. No selector promotion.

## Assessment — independently derived decision

1. **N3 does not authorize repairing line layout.** In each of rows 169 and 477, two otherwise complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records are concatenated into one raw line (approximately 930 characters vs two lines of 465 each), plus one additional blank line. Baseline and current contain the same four complete record *values* in each row, but frozen N3 permits only sorting contiguous **complete lines**, not splitting joined lines or discarding an extra blank line. All other 957 prior gate logs and three census logs match under N1–N7. Thus classify **diagnostic-output layout candidate; strict evidence mismatch, not accepted MATCH**. `src/geometry/GlobalTopologyPlan.cpp` emits the record via `std::cerr << out.str() << '\n'`; concurrency-driven output interleaving is plausible, not independently established. Do not alter normalization retrospectively.
2. **Receipts are real and narrow.** Gate has 240 new `entryCoincidence` lines over 20 sphere-path fixture rows: 120 lines for pair `4:7/6:7` at `(0,2)`, 120 for `15:7/19:7` at `(25,27)`, all with exact parameter `574181338608147/4503599627370496`. The census adds six BunnyRandom lines, three each for `15:21/43:15` on `(72,243)` at `191903898244039/562949953421312` and `15:22/43:16` on `(72,273)` at `1755811011335563/2251799813685248`. No Cylinder/Vase receipt. They are repetitions across producer invocations, not 246 independent fixture identities.
3. **Sphere witness reached.** The 66 sphere `duplicateCutCrossing edge=(0,2)` diagnostic occurrences span 19 rows. Every one of those **19 rows** contains the exact carrier `(0,2)` entry receipt with pair `4:7/6:7` and matching parameter. This proves the **row-level witness contract** only: some rows have more crossing diagnostic instances than matching receipt lines. Row 693 has a receipt without a crossing diagnostic, permitted by the frozen rule. Receipt presence does not repair C5/O47 or prove graph publication.
4. **Existing output invariant.** All 1,266 raw `slideProposal` lines and all 1,266 raw `committedSlide` lines match TB142 byte-for-byte and in order (1,200 gate and 66 census of each kind). Prior ledger identity, selector, binary, verdict, exit and first failure match. Row 858 remains RED at `tests/SurfaceCellTracingDisplayTests.cpp:155`; row648 PASS does not establish its unreached assertion. Cylinder remains PASS/288; BunnyRandom still RED at trace82, Vase RED in completion. All three census logs match. No newly produced successful surface-cell graph is established.
5. **Independent non-vacuity:** deleting the entry receipt would eliminate the positive row-level sphere witness; changing its carrier, exact rational or trace pair would falsify that check. The comparator detects even presentation-level changes in complete diagnostics; it **did** reject rows 169/477. The raw slide-line byte comparisons detect any mutation of retained slide evidence. The two presentation differences are not proof of a new stable product regression, because no accepted-green case was lost. Do not claim the underlying interleaving cause proven.
6. **Carry obligations.** RA-264 EC2/EC3 remains prospectively scoped and requires a new freeze after strict gate evidence is restored or a separately authorized prospective comparison contract is defined; no retrospective waiver. C5/O47, O48, O49 and H4 remain; no graph publication, no CP3/D0 acceptance. Stable accounting remains **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**, accepted CP2 prefix **491/491**, selector497 unpromoted.

## Recommendation — exactly one bounded next turn

Freeze **`M6-CP3-CB168B-P13-REGION-SUPPORT-DIAGNOSTIC-FRAMING`**, Code + Build **only**, not EC2. The diagnostic producer must emit each complete `region_support_projection` line as one indivisible record (or otherwise serialize output safely) without modifying the content, order semantics, geometry, test outcome, selector, raw slide or entry receipts, other producers, or accepted definitions. Use the smallest shared output point causing this defect; do not add broad diagnostic normalization. Before edits, reproduce the two joined-record shapes in raw TB143 row169/477 logs; identify the exact emitting call and other relevant output sites; compare frozen N3 and verify no source-mutation scope leak. Compile only the authorized GMP/GMPXX targets; `runtimeExecution=false`. Independently verify exact source, eight-target build, compile warnings and package hashes. **Falsifier for its subsequent artifact-only Test + Benchmark:** all 962 prior logs must compare under the *unchanged* N1–N7; 491/491 accepted prefix, row858 failure site, 19/19 sphere receipt witness, N5/N6 raw slides and BunnyRandom first failure must be preserved. Any semantic event change, deleted diagnostic, altered record payload, or unmatched log is STOP, not permission to edit a normalizer. This corrective turn does not run here; EC2/EC3 remain held.

## Procedure and scope disclosure

This session read several source documents directly before selecting the mandatory `READ_MODE=snapshot`. That breached `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` pre-read ordering. It stopped those reads, obtained and verified an exact source snapshot, then performed the evidence comparison locally. No resulting runtime evidence was fabricated, and no Code + Build or Test + Benchmark was run. A source-archive snapshot does not retain Git ancestry, so the history-based `review_check.py boundary` cannot establish a true remote ancestor relation; any local result from a synthetic Git baseline is not a remote push verification.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/491 PASS; 30/12/449 source SHA-256 and concatenated `452360f7…e5300b` above |
| Decisive claims independently re-derived | Four result ZIP digests, 3,874 file hashes, 960/962 normalized log matches, two exact raw-layout mismatches, gate and census receipts, prior failure sites |
| Non-vacuity checked | Positive receipt required in 19 sphere rows; exact fields/parameter; strict comparator rejected two unpermitted changes; N5/N6 byte comparisons |
| Prior obligations discharged/carried | TB143 receipt census reviewed; carry strict rows169/477, C5/O47/O48/O49/H4, row858 and row648 premise; EC2/EC3 held |
| Stable accounting | 66/17/49; debt 1; 81 deferred; accepted CP2 491/491, selector497 not promoted |
| New candidates/obligations recorded | Presentation-layout candidate with falsifier and owner `M6-CP3-CB168B-P13-REGION-SUPPORT-DIAGNOSTIC-FRAMING`; regression tracker updated |
| ORIENTATION currency line | Updated to TB143-REV, 2026-11-19 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §4 witness, §7 priority and §8 known no-retroactive-normalization pattern updated |
| CHANGELOG | TB143 independent review entry added |
| ROADMAP | n/a: M6-CP3 remains open; no milestone status changed |
| Selector manifest | n/a: no selector or accepted prefix changed |
| LESSONS | Existing exact-source, frozen-comparison and non-vacuity patterns applied; no new general rule |
| Consolidation under CLEAN_UP_POLICY | n/a: current TB143 execution and review are both live authority; no already-superseded document removed in this scope |
| Successor frozen | `M6-CP3-CB168B-P13-REGION-SUPPORT-DIAGNOSTIC-FRAMING`; bounded corrective specification and falsifiers in Recommendation above |
| Turn boundary held | Review-only analysis; no build/runtime or source/test/selector/fixture mutation |
| review_check.py boundary | Executed on synthetic source-only Git baseline: FAIL (all untracked product paths appear newly created); not accepted as remote boundary proof. Intended patch path audit contains only six documentation files |
| `STATUS` lifecycle maintained | Bootstrap on current turn; final beacon written only after durable closeout or remains IN_PROGRESS when transport incomplete |
| Pushed to origin, branch in sync | GitHub Actions patch application and final PR-head read serve as remote confirmation; status remains unconfirmed until those return success |
