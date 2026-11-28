# TB128 independent Review — face-contact gate mismatch (2026-11-17 UTC)

Canonical turn `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV`. **Evidence disposition: MISMATCH upheld; no promotion.** Review only; no Directional runtime, build, product, fixture, test, selector, manifest or workflow changes. Completion of the Review itself is subject to the closeout checks at the end of this record and root STATUS. PR #8 is open and draft.

## 1. Independent evidence and authority

Reviewed the four primary ZIP result archives, not only the execution report. TB127 gate `14302887671` SHA-256 `017ad5589ae533d4f428312bc59d92409906544f6cd1add1a3db0ccc80383050` (1,910 internal hashes); census `14302668940` `4edf0fe64c45fac424eb0c8ef9ed4e9eaae675373e32f06724df9ea4724f3cc5` (9). TB128 gate `14318100443` `e208416775f474f75d79ec76697ed19d643a121d8ad086cd37b8f3a330436e5d` (1,914); census `14317054197` `cdf7dab92f0e8c2650db6e2e5ac015d7ab5f07e251b4acdd17e6ed511ee7ccf4` (9). Independently checked all hashes, row identity bindings, ledger counts, raw-log hashes, pre/postflight and permitted comparison rules. Both candidate runs executed each declared row once, with zero skip, duplicate, missing or abnormal outcomes. Gate membership 1,034 = 953 + 81 deferred; exit 90, control_bad=2. Census harness exit 0. Full record: [TB128 execution](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md).

Source snapshot SHA `84917b4f29d6e94d55e51b4698bd4c5c957e4b21`, run `44065452931`, artifact `14319637583`, ZIP SHA-256 `7fb2cf03f5ac59d424a73d376ddd9e49eb86292a7ba4ce4378a93a06f1e4eec0`; archive SHA `3539eee1522804584ef26b7b903000fd5e47b4a951ea567d7ec883d4b133bfc9`, 5,525 hashes valid. Remote compare CB149 semantic SHA `85f9c703c5de86fb2b401cf83c03499a1ce73a27` to snapshot: no product/test/fixture/build changes. CB149 package `14315237769` ZIP SHA `39ce6f17ed010d26bf3e65dace9100646fc215a3a8050bb8cae6d621dfb23926`; compile record confirms eight GNU Multiple Precision (GMP/GMPXX) targets, no execution. TB127 source `48e6f97d278b2226036f658ce9060a38b8a374b5`, package `14301616031`. Remote compare semantic sources reports only five changed code/test paths: EmbeddedGraphTopology.cpp (+456/-27), .h (+108), GlobalTopologyPlan.cpp (+6), .h (+6), FieldAlignedCurveNetworkTests.cpp (+215). The three exact frozen diffs re-hash to CB147 `5c3def45e8bdd713ca321b7cfca0f9f3a5935bdf54900afd5548efc55e5df7d1`, CB148 `b4b8248715e04996bcdc22f2146497d9957bb0923f5602dabbac3c4b44dced6e`, CB149 `ddf87b85683e1f34322418ffd5303740822602d845faf3a80ecff9d8d817963c`. Reverse-check and reverse-apply each on a disposable five-file copy in reverse order all pass. The CB149 postimage Git blob is `bf38170a053d1fa1e5bf7a0ff26f1df8f7453b1d`. This is static analysis, not a runtime rerun.

Manifest 953 data rows SHA `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; inherited first 951 plus header SHA `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`. Census 3 rows `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Projection of first 491 test names with LF is byte-identical to focused30 + focused12 + selector449, combined SHA `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b` (component SHAs `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`). CP2 accepted package `11391685901` unchanged; all first 491 PASS. Row858 does not occur in that prefix. TB125 950/950 is scoped evidence, not CP3 promotion. Do not add a stable event from an unpromoted candidate.

## 2. Gate adjudication and non-vacuity

TB127 951/951; TB128 951 PASS / 2 RED. 950/951 inherited substantive ledger records match, only row858 changes. Permitted newline framing changes at 168/173/177/195/477/705. Outside permission: 164/644/669/698/858. No broadened normalization. Gate MISMATCH independent of census MATCH.

- **164** (`SurfaceCellAuthorityContractCutover.ComponentFeatureRailTamperRejectsAtAggregationSeam`): PASS. All normalized complete lines match as a multiset; a fragment projection record moves across two others. Static source does not establish emission-order cause. The frozen contract compares order, so this remains a comparison discrepancy. Owner: projection diagnostic emission/comparison, not proved topology regression. Before any future allowance, show record keys, actual order owner and lack of consumer order dependence; do not sort all logs or erase values.
- **644/669/698**: PASS; prescribed sphere reason `TraceEventPositionInvalid` becomes `ArcTraceTerminalCutPositionMismatch`. Row644 loses reported face (0,1,2); 669/698 lose old trace/event and carrier-search fields, because the new rejection path does not populate them. This is real changed evidence, not timing or framing. C5 remains open; no claim that the new terminal is identical to BunnyRandom's trace or node.
- **858**: required guard `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported` stops at `SurfaceCellTracingDisplayTests.cpp:155`, `faceLocus.sourceFace.has_value()` false. Earlier genus-two face and half-index vertex checks executed without failure; the prescribed-sphere cut-graph face assertion failed, later checks after ASSERT not reached. `SurfaceCellTracingDisplay.cpp:181–200` projects the actual reported face/vertex; it does not synthesize one. The three other sphere rows support a migrated failure-locus premise; row858 itself prints only surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent, not the exact subreason or locus. Classify inherited required guard loss on this candidate, not a proved display product defect. Carry the obligation to independently measure row858's actual upstream locus, preserve a positive cut-graph face witness and a vertex witness, and verify display copies the real producer fields. No invented face from seed/origin, no weaker optional assertion, no claim that any A4-stage face witness substitutes for cut-graph coverage. Name-only failure-reason coverage in RA-249 missed a locus assertion.
- **952**: new guard `FaceChartExactGeometry.OrdersRaysAndContactsExactlyAroundAFaceInteriorPoint` fails fatal `sameDoubles(towardB, nearB)` at FieldAlignedCurveNetworkTests.cpp:18783, not a ray-order assertion. Earlier assertions execute without recorded failure. Six later assertions unexecuted (two near-ray orders, same-ray collision, zero-length ray, empty order, one ray). FieldTransportAtlas.h:522–524 and ENumberGMP.h:147 use GMP `get_d`, toward-zero conversion. Direct independent system GMP `mpq_get_d` check (no Directional binary) gives old B `(0,1/2,1/2)` doubles `[0x0.0p+0,0x1.0000000000000p-1,0x1.0000000000000p-1]`; near B `(0,1/2+e,1/2-e)` with `e=2^-60` gives last value `0x1.fffffffffffffp-2`. Thus the test premise is false. The implementation's exact near-ray predicate has not been falsified or proved by this run. RA-248's Python model did not model this conversion; correct its claim. Carry a separate future test-only correction, not part of the measurement turn. Exact proposed stimulus below.
- **953**: PASS, exact entry/exit, edge-transit rejection, parameter, exact cut order, segment range and partial path pieces before/after/multiple contacts, reversed/equal range rejection and reason names. A pure helper test, not proof of the wired collector, full node exclusivity, rotation, face walk or downstream ownership. The production witness rejected earlier; FC-1–FC-5 remain unaccepted.

### Exact replacement witness (review proposal, not implemented)

Use barycentric `O=(1/6,1/6,2/3)`, `A=(1/3,0,2/3)`, `B=(0,1/3,2/3)`, `N=(0,1/3+e,2/3-e)`, `D=2B-O=(-1/6,1/2,2/3)`; retain e2, midpoint e0/e1 and all previous assertions. Actual system GMP conversion B=N=`[0x0.0p+0,0x1.5555555555555p-2,0x1.5555555555555p-1]`. In oriented chart (b1,b2), cross(B-O,N-O)=-e/6=-1/6917529027641081856. A and B are opposite; D and B same direction. Independent exact rational angular comparator, anchored at first supplied index, yields the existing ten expected orders: [0,2,1], [0,1,2], [0,2,1,3], [0,3,1,2], [0,1,2], [0,2,1], null, null, [], [0]. This proves the *stimulus* meets the intended discriminator and expected orders; the Directional test remains unrun. Do not replace sameDoubles, relax exactness, alter the converter or skip collision/zero/empty/single cases. Re-run in the authoritative package after a separately authorized CB.

## 3. Census and terminal owner

Cylinder PASS 288; Vase RED zero accepted (189,462 segments, 26,817 arrangement cells, 67,750 internal quads); both normalized raw logs and substantive ledgers match TB127. BunnyRandom RED zero output, full preterminal prefix unchanged, including four mandatory-edge terminal inventory lines. Old terminal face (5,104,359), trace 0 event 18, no carrier match/source edge unavailable. New terminal verbatim: `terminal=NotProductionReady:surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent detail=CellularityNotEstablished traceSegments=0 arrangementCells=0 completedQuads=0 completion= locus history=0 vertex=3 rotationReason=ArcTraceTerminalCutPositionMismatch`. This meets the frozen census comparison; no forbidden reason. O46 ownership-stage prediction **did not occur**. No RotationEdge* on (241,251)/(251,278); middle-piece direction remains unreached, not vindicated.

Static proof (`EmbeddedGraphTopology.cpp:965–1079`, pre-switch reverse copy guard at :736): denote n=segment count. Origin cut 0; synthetic crossing cuts strictly 0<k<n; exact struck cuts strictly within a segment; terminating collected face-contact incidence inserts (n, absent parameter), setting hasTerminal; remaining incidence loop only accepts a position <=n. Duplicate node disagreements return earlier. The exact reason observed requires hasTerminal true and max key strictly smaller than (n,absent). Therefore **no collected face-contact terminal for this failing trace inserted n**; at least one remaining Terminal incidence reached the existing position resolver and selected a boundary <n. The asserted source vertex is the trace's **origin** (`trace.sourceVertex`), not the terminal point, trace ID or event index. With no sourceEdge the origin shortcut can select 0; otherwise a no-edge Terminal selects n. With sourceEdge, face-restricted carrier matches (incoming k, outgoing k+1), then widen if none; unique result is accepted regardless of terminal role. Existing code already had the same guard and resolver; CB149 changes which events are skipped and inserts interior cuts. An exposed pre-existing guard does not establish that its violating record predates the switch. Actual Terminal event/role/node, trace, exact cut and owner are not in the receipt; cannot select a repair branch or decide latent versus introduced on these logs. In particular source vertex 3 does not imply trace 0.

Canonical producer `SurfaceCellTracing.cpp:4062–4210` creates a new contact node and uses the two segment carriers to select sourceEdge; it publishes exact terminalContact separately. A common-carrier contact can select an earlier incoming position rather than the actual exact face-point end. This is a specific alternative under O45, **not a diagnosis of the actual event**. Singularity/barrier/limit-cycle events and origin shortcut remain alternatives until measured. Never force every Terminal to n, widen tolerance, synthesize a cut, reassign a role, back-fill a face, or skip a rejection. Keep FC-6 unswitched.

Additional static conformance obligation: RA-248 FC-1 requires strict face-interior locus and FC-4 exclusive face/edge/vertex locus. Collector at :740–821 checks same face/point, exact interior parameter on struck trace, and end bindings, but no explicit strict barycentric test on P (two-ending case skips parameter check). Node-locus registration uses a separate map; it skips qualifying events but does not explicitly reject coexistence with another vertex/edge record. Canonical producers and candidate equality constrain inputs, so neither is a demonstrated reachable runtime failure. Verify the producer proof and disjointness before claiming FC-1/FC-4 complete; do not change those branches during terminal measurement.

## 4. Bounded next action at Review closeout

Exactly one successor: `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT` (CB149A already names orchestration recovery). Separate Code + Build, diagnostic only. See [bounded plan](Architecture_M6_CP3_CB149B_P13_Terminal_Cut_Authority_Receipt_Plan_20261117.md). It does not start until STATUS records this Review COMPLETE. Preserves all gate bytes, all REDs and the candidate failure reasons. Holds row952 and row858 corrections to later independently reviewed turns. O42/O43/O45/O46 remain open, C5 open; narrow C3/O44/C1 remain closed. C4/CB145 parked. Preserve middle-piece direction witness, D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false, stable **66/17/49**, debt 1, deferred 81; CP2 491/491, selector497/CP3/D0 not promoted. Do not treat a successful diagnostic compile as closure.


### Historical boundary and consolidation receipt (same-turn continuation)

Reused the verified source snapshot `84917b4f29d6e94d55e51b4698bd4c5c957e4b21` and the exact previously applied 14-path patch (full SHA-256 `cbb63acf5e48611c873d7d5fe52798f131e2aa6fdacb0cf014144327322db6f5`, diff-body `bab43482f3c577a58e2535d41ac25a2097e55742ddaee3a43ee5e049c6bc0174`). Its reverse apply check passes on the local postimage. Remote comparison of applied commit `a63be5f1d5a2f4f5d05fb7306e15238271181e57` to resumption head `269d7aede2e1a88cc02afdde3ee04f82fa2ac33b`: four commits ahead, zero behind; only removal of the Review snapshot marker and root STATUS modification. The dispatcher slot and STATUS blobs match the remote receipts. No additional gate or census execution.

GitHub compare `8b7299b43764a6ba3444e5bc774a2f1b65e99731` to `269d7aede2e1a88cc02afdde3ee04f82fa2ac33b` returns ahead 5,960, behind 0, merge base exactly `8b7299b43764a6ba3444e5bc774a2f1b65e99731`. This independently establishes ancestry, not a fabricated local history. Retrieved the three whole rewrite-baseline documents by full immutable commit: handoff blob `ad73c549ab9764e9391025bca4cab0cdcd5010fc` (four durable headings), ORIENTATION `36c0683642ec035da3b4f1f2543fcea083b01b5a` (one heading), tracker `afa8d7dc1b47f92b3a0340bfab5e46fcf1285b85` (zero protected headings). Check the same exact heading regex as `review_check.py`; all five original headings remain. The structured GitHub comparison and exact baseline blobs satisfy the historical predicates that a history-free snapshot cannot calculate locally. Do not report a local checker PASS.

Historical comparison `6ef77580617731bc2d5e364b924c706ad9bb0b34` to resumption head: 72 removed Markdown files, 72/72 matched in the TB126 folded index by filename and original line count, no missing names; TB128 interim continuation separately indexed. Compare RA-249 pre-freeze `7ddaf99721af555dc184540e5232c87094ffcb66` to the resumption head: no net Markdown deletions; TB128 interim note was added and retired inside that range. Retain the definition-bearing RA-245/246/247/248/249 and the current CB149 build/package record; they contain active normative obligations or current package authority, not disposable historical duplication. Archive eight superseded execution reports verbatim in Volume D3 with explicit original byte hashes. The prior successful cleanup run `44067784967` removed this turn's snapshot marker only; 37 unrelated legacy control records remain from earlier turns, outside this Review's work.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | §1, exact first 951 manifest bytes and first 491 projected names; 491/491 PASS. |
| Decisive claims independently re-derived | §§1–3, four archives, source compare, exact diffs, source guard, GMP conversion and independent exact ray model. |
| Non-vacuity checked | §2: 952 fatal premise, six unreachable assertions; 953 helper only; 858 exact locus not measured; middle-piece direction unreached. |
| Prior obligations discharged/carried | §4: C5, O42/O43/O45/O46, C4/CB145, direction witness, decisions and accounting retained. O46 prediction not met. |
| Stable accounting | 66/17/49; debt1, deferred81; accepted CP2 artifact 11391685901, 491/491. Candidate not promoted. |
| New candidates/obligations recorded | Required guard loss, diagnostic ordering, false conversion premise, terminal owner and FC-1/FC-4 proof; tracker updated. |
| ORIENTATION currency line | Updated for this Review (2026-11-17) and the single authorized successor. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated factual state and current row; existing lessons cover observed patterns; preserve durable sections. |
| CHANGELOG | Existing Review entry amended; no duplicate entry. |
| ROADMAP | Current checkpoint stays open; next diagnostic receipt identified. |
| Selector manifest | n/a; selector and all gate identities stay byte-identical; no acceptance. |
| LESSONS | Existing rules: lossy mode-dependent conversion, upstream failure locus and reaching controls, hold variables fixed. No new general lesson. |
| Consolidation under CLEAN_UP_POLICY | Eight superseded CB/TB execution records folded without losing text, indexed with original line count, SHA-256 and source commit in [Volume D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb128-review--superseded-execution-records-2026-11-17). All 72 earlier removed documents match the TB126 index by filename and line count; TB128 continuation already indexed. Live links repaired. Retain current CB149 package record, TB128 report and Review, definition-bearing prior reviews, frozen exact diffs and selectors. |
| Successor frozen | §4 and [M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT](Architecture_M6_CP3_CB149B_P13_Terminal_Cut_Authority_Receipt_Plan_20261117.md), exactly one bounded diagnostic-only Code + Build. Falsifiers and stop rules in plan; no successor work started. |
| Turn boundary held | Runtime-free; no source/test/fixture/selector/build changes. Read-only GMP system conversion and exact Python analysis only. |
| review_check.py boundary | Exit 1: 44 PASS, four history-only checks unavailable in the verified source snapshot. The independent GitHub ancestry and exact rewrite-baseline blob checks above establish all four historical predicates; all five original protected headings remain. No checker change or synthetic ancestry claim. Final drift audit: zero errors, three authorized currency-update warnings (handoff, ORIENTATION, ROADMAP). Source, test, fixture, build, exact diff, manifest and selector paths unchanged. The Review closeout uses these independent checks, not a claimed local checker PASS. |
| STATUS lifecycle maintained | Entry `2026-11-17T10:29:25Z`; resumed `2026-11-17T10:56:06Z`; the final direct root STATUS write records completion and authorized successor after push verification. |
| Pushed to origin, branch in sync | First review patch applied and verified at `a63be5f1d5a2f4f5d05fb7306e15238271181e57`; cleanup receipt verified. Final closeout patch is subject to dispatcher hash/apply/push verification and connector branch compare before final STATUS. ChatGPT Web uses remote connector evidence instead of a local tracking branch; no local `git status -sb` sync claim. |

## RA-250 — adversarial re-review of this Review (2026-11-17 UTC)

This is a Review-only pass. I fetched origin, and Haiku agents ran read-only audits.
- No binary was built or run.
- The row 952 witness was checked with an exact Python model (`python3 -I`).
- Both new patches pass `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED`.

**Verdict.** The MISMATCH disposition stands. Four parts of this Review are wrong or incomplete (§R1–§R4). Its successor, the prose-only `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`, is **withdrawn**. It is replaced by two exact patches (CB150, CB151) and the TB129 measurement (§R6).

### R0. My own errors in RA-248/RA-249

- **Row 952 (RA-248).** The witness assumed that `to_double` rounds to nearest. GMP `get_d` truncates toward zero. So `1/2 − 2⁻⁶⁰` converts to the double just below 1/2, and the guard `sameDoubles(towardB, nearB)` was false. This Review's diagnosis is correct.
- **RA-249's "the gate cannot change" argument was incomplete.**
  - It searched for tests by reason name only. It missed row 858's locus-shape assertion (`faceLocus.sourceFace.has_value()`) and the prescribed-sphere log text in rows 644/669/698.
  - Its O46 prediction was wrong: arc construction still rejects, before any rotation or ownership stage runs.
- **The larger error is in RA-248 FC-7.** FC-7 said "contacts with a common carrier keep the proxy". I did not check that rule against the A2a′ end-cut guard. §R2 shows the rule is defective by construction.

### R1. Row 952: the replacement witness is verified independently

- **Witness.** `O=(1/6,1/6,2/3)`, `A=(1/3,0,2/3)`, `B=(0,1/3,2/3)`, `N=(0,1/3+2⁻⁶⁰,2/3−2⁻⁶⁰)` and `beyond=2B−O=(−1/6,1/2,2/3)`.
- **Same doubles under either conversion.** B and N give the same doubles under truncation (`0x1.5555555555555p-2`, `0x1.5555555555555p-1`) and under round-to-nearest. So the guard no longer depends on the conversion mode.
- **Expected orders.** A model mirroring `face_chart_counter_clockwise_ray_order` line by line yields all ten expected orders: `[0,2,1] [0,1,2] [0,2,1,3] [0,3,1,2] [0,1,2] [0,2,1] null null [] [0]`. Also `orient(O,B,N) = −1` (clockwise) and `orient(O,A,B) = 0` (A and B are opposite).
- **Earlier guards in the same test.** The two earlier same-double guards (centroid; `along(1/3)`) also hold under truncation, so no other assertion in row 952 rests on the false premise.
- **Frozen as CB150** (test-only). `Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Exact.diff`:
  - SHA-256 `63a6bd0b95099f0be05b22ca5d0adb539569e5f5afa6b2d8950a6b2ab9e905ba`;
  - 49 lines;
  - numstat `10 7 tests/FieldAlignedCurveNetworkTests.cpp`.

  No assertion was removed or weakened. Only the stimulus coordinates and the comment change.

### R2. Terminal owner: the event is undetermined, but the candidates are narrower than this Review says

**Static reduction** (`EmbeddedGraphTopology.cpp` `build_arcs`):
- Collected face-contact terminals insert the end key `(n, ∅)`.
- So `ArcTraceTerminalCutPositionMismatch` means every Terminal incidence of the failing trace resolved through `trace_event_position` to a boundary k < n.

I checked each production Terminal producer. The finalize path, at `SurfaceCellTracing.cpp:4550`, is census-only: its callers are `:5113` under `contactCensus != nullptr` and the diagnostic wrapper `:5505`.

| Producer | Event `sourceEdge` | Can it resolve to k < n? |
|---|---|---|
| `field_aligned_publish_contact` `:4062`, with a common carrier | `common.front()` of the two segments' carrier sets (`:2871`) | **Yes, always, when the chosen edge is the terminating segment's incoming carrier and not its outgoing carrier.** The face-restricted pass then matches only `(n−1, segment n−1, Incoming)`. The committed terminating segment keeps its full-crossing `outgoingCarrier` (`:3589`, `:4052`), so the end edge is not a carrier the pass can match. **This is H1.** Because `common.front()` takes the smallest key, which shared edge is chosen is arbitrary. |
| Limit cycle `:3942` | `entryPoint.edge`; the event face is the face being **re-entered** | **Yes, by construction.** The last segment lies in the predecessor face. Only an earlier visit j < n−1 in the re-entered face can match: one visit gives a unique j and so the observed reason; two visits give `AmbiguousCarrierMatch`. **This is H2.** |
| Barrier `:3894` | `terminalBarrier`, which is the last segment's outgoing carrier | No: it resolves to n. |
| Singularity `:2278` | `terminalPoint->edge` | Resolves to n when that edge is the last segment's outgoing carrier. The code does not assert this; the receipt will show it. |
| Origin shortcut (`event.node == origin`, no edge) | — | **Unreachable for a Terminal incidence.** Every Terminal event at a port node carries an edge, and face-contact nodes exclude ports. |

**What this changes in the Review:**
- This Review listed "singularity/barrier/limit-cycle events and origin shortcut" as equally open alternatives. That is inaccurate. Barrier and origin shortcut are excluded, singularity is unlikely, and H1 and H2 are both deterministic.
- **Independent of what BunnyRandom shows, H1 is a latent defect in FC-7.** The O45 proxy cannot satisfy the end-cut guard whenever the selected common carrier is the terminator's incoming edge. It also always places the struck trace's node at a segment boundary, not at the contact point.
- Whether H1 or H2 is BunnyRandom's actual cause is still unmeasured. The census locus prints only `vertex=3`, which is the trace's **origin** vertex.

### R3. Row 164: static source does establish the cause

The Review says "static source does not establish emission-order cause". That is wrong.
- Row 164 runs with `parallelizeComponents=true` and `maxComponentThreads=2` (`SurfaceCellsPhase10Tests.cpp:10271`).
- Components run through `std::async` (`RemeshPipeline.cpp:17726`). Each calls `GlobalTopologyPlan::make`, which writes `M3_CP4AB_FRAGMENT_DIAG` records to `std::clog` (`GlobalTopologyPlan.cpp:1532–1971`).
- Within one component, records are ordered by value: `std::map`/`std::set` over `SourceFaceTopologyKey`, and a sorted vector.
- So the order *between* the two components' records depends on thread scheduling. The equal-multiset observation is exactly what that predicts.

**Ruling.** Row 164 is not a product discrepancy. From TB129 on, row 164 is compared as a multiset of complete newline-free records. Any changed record value, or a torn line, is still a MISMATCH. No other row gets this allowance.

### R4. Row 858: restore the face from the real failing event, not from a guess

- The display only projects `terminalFailureLocus.sourceFace` (`SurfaceCellTracingDisplay.cpp:188`).
- The current mismatch error sets only `sourceVertex`, which is the trace's origin. It is not the place where the error occurred.
- CB151 sets the error's `sourceFace` and `sourceEdge` from the Terminal event that resolved before the end. That is the producer's own face; it is not synthesized from a seed or origin. Row 858 then has a real cut-graph face witness again.
- A Haiku audit found no decision site in `src/` that reads these fields on this error; they are only copied and printed. The display gains only the "stopping face" annotation.
- Predicted outcome: row 858 PASS.

### R5. CB151: terminal-cut-before-end receipt (diagnostic only; replaces CB149B)

`Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff`:
- SHA-256 `044529d63c2f9e82cad38fb95cad00d4fa299918c6bcd02ffb3c56cc1947b516`;
- 168 lines;
- numstat `129 0 src/geometry/EmbeddedGraphTopology.cpp`;
- it applies independently of CB150 (the two patches touch different files).

**Changes:**
1. `trace_event_position` also records `pass` and `candidates` on success. This is read only by the new branch below.
2. `build_arcs` remembers the first Terminal incidence that resolves to k < n.
3. On `ArcTraceTerminalCutPositionMismatch`, the error additionally carries that incidence's `trace`, `sourceFace`, `sourceEdge`, `traceEventIndex`, `traceEventPositionPass` and `traceEventPositionCandidates`. All are existing fields with existing printers.
4. It prints one `EmbeddedGraphTopology.terminalCutBeforeEnd` line, giving:
   - the trace, the origin `sourceVertex`, `segments=n`, the event index, the event kind, the node, the face and the edge;
   - the resolved `position`, the `pass` and each candidate;
   - the last segment's face and carriers;
   - the terminal record kind with its face and edge (contact: struck trace and segment; limit cycle: face and entry edge).

   This follows the existing `report_mandatory_edge_terminal_inventory` pattern in the same file.

**What does not change:**
- No decision changes. The reason, return path, cuts and every other error are untouched.
- Syntax checks return 0 with HEAD's warning counts (EGT 22, test 42).

**Test gap.** The branch cannot be unit-tested, because networks cannot be hand-built (RA-248 fixture limit). Rows 644/669/698/858 and BunnyRandom are its witnesses.

### R6. TB129 frozen: `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC`

**Inputs:**
- Package: CB151, i.e. CB149 + CB150 + CB151.
- Gate manifest: the TB128 manifest unchanged (`941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; 953 rows, deferred 81, membership 1,034).
- Census `3af1dc0d…`.
- Comparison authority: TB128 gate `14318100443`, census `14317054197`.

**MATCH requires all of the following:**
1. 953/953 PASS, with valid postflight. Row 952 and row 858 are now PASS.
2. Every row except 164, 644, 669, 698, 858 and 952 has the same ledger fields and raw log as TB128, under TB128's permitted normalizations.
   - Row 164 is compared as a multiset (§R3).
   - Rows 644/669/698 may differ only by:
     - exactly one added `terminalCutBeforeEnd` line per rejected network;
     - the newly populated `trace`, `traceEvent`, `errorSourceFace`, `traceEventClaimedSourceEdge` and candidate fields.
   - `originatingRotationSystemReason` stays `ArcTraceTerminalCutPositionMismatch`.
3. No other row's log contains `terminalCutBeforeEnd`.
4. Cylinder (PASS, 288 quads) and Vase census logs are identical to TB128 after the normalizations.
5. BunnyRandom:
   - every line before the terminal is identical to TB128;
   - exactly one `terminalCutBeforeEnd` line;
   - the terminal is still `ArcTraceTerminalCutPositionMismatch`, now with `face=`, `edge=`, `trace=`, `eventIndex=` and `eventPositionPass=`.

**Classify each receipt (sphere and BunnyRandom).** Record the class; the class does not decide MATCH.
- **H1:** kind is `TraceIntersection` or `TraceSelfClosure`, terminal is `contact`, the position is n−1, and the candidate is (segment n−1, Incoming) with `edge = lastIncoming`.
- **H2:** kind is `LimitCycleTermination`, terminal is `limitCycle`, and the candidate is (j < n−1, Incoming) in the limit-cycle face.
- Anything else is recorded verbatim and becomes a new owner.

**Routes:**
- Mismatch → `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV`.
- Infrastructure failure → `M6-CP3-TB129A-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-ORCH`.
- MATCH → Review `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`.

**Pre-assigned work for the outcome Review:**
- **H1:** freeze contact classification by the exact `terminalContact` binding instead of by the absence of an edge. This retires O45 for contacts.
  - It must first count common-carrier contacts on Cylinder and Vase, because the switch changes them (RA-230).
- **H2:** the limit-cycle terminal resolves at the trace end. The producer must publish the face of the last segment, or the Terminal role must bind to the last segment's outgoing carrier.

**What stays as it is:**
- FC-6 (old CB150+) is renumbered after this sequence.
- CB145 and the middle-piece direction witness stay parked.
- FC-1/FC-4 producer-proof obligations are carried.

### R7. Turn sequence

| # | Turn | Owner | Status |
|---|---|---|---|
| 1 | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV` with the RA-250 re-review | Review | COMPLETE |
| 2 | `M6-CP3-CB150-P13-FACE-CHART-WITNESS-CORRECTION` | Code + Build (compile only, exact diff) | **NEXT** |
| 3 | `M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT` | Code + Build (compile only, exact diff) | then |
| 4 | `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC` | Test + Benchmark | then |
| 5 | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME` | Review | Classifies H1/H2 and freezes the fix CBs |
| 6+ | Fix CB(s) → TB → `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6) | — | Staged per RA-230 |
| withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT` | — | Replaced by CB151 |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45, which H1 would retire | — | — |

**Routes for the two Code + Build turns:**
- CB150: mismatch → `M6-CP3-PLAN-P13-FACE-CHART-WITNESS-STOP`; infrastructure failure → `M6-CP3-CB150A-P13-FACE-CHART-WITNESS-ORCH`.
- CB151: mismatch → `M6-CP3-PLAN-P13-TERMINAL-CUT-RECEIPT-STOP`; infrastructure failure → `M6-CP3-CB151A-P13-TERMINAL-CUT-RECEIPT-ORCH`.
- Both build the eight RA-245 GMP/GMPXX targets, with `runtimeExecution=false`.

**Prechecks:**
- CB150: `git diff --quiet 85f9c703c5de86fb2b401cf83c03499a1ce73a27 HEAD -- src include tests`.
- CB151: `src include tests` equal `85f9c703c` plus exactly CB150.

**Carried unchanged:**
- Stable 66/17/49, debt 1, deferred 81; CP2 491/491.
- C5, O42, O43, O45, O46 open.
- D11 = A, D12 = A, D10 deferred, D6 pending.
- CP3/selector497 not promoted; `chainRimSchedules=false`.
