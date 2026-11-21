# TB127 independent Review — guard and rotation-locus gate (2026-11-17 UTC)

**Turn:** `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV`. **Verdict:** frozen combined MISMATCH upheld; comparison-only discrepancy, not a new product regression. Narrow C3 closure by independent adjudication, not retroactive MATCH. C5 open. No checkpoint promotion.

## Situation and evidence authority

Re-opened the actual four result ZIPs retained in Library `/Directional/Evidence/Directional_TB127_verified_evidence.zip` (SHA-256 `e0b5c4641e812680ce5fedfa4f4d3703aa39ce9c1b0a87adc3601b3668e2f6ca`; all 14 bundle hashes pass). Verified their outer digests independently against GitHub artifact inventory (TB126) or immutable mailbox records (TB127); checked every listed result hash and raw-log binding. These are prior TB executions, not executions in this Review.

| Result artifact | SHA-256 | Internal hashes | Result |
|---|---|---:|---|
| TB126 gate `14294372593` | `c13a0f5e29ab961a6c6d7a31c2883cfaafbdc577d5727f291eb127e9cc8ea55e` | 1910/1910 | 950/951 |
| TB126 census `14294313207` | `79acdba05b737e6987a39d3908ce7bf3f9375f4c051b5c4a35566670b63eb95f` | 9/9 | 1 PASS, 2 RED |
| TB127 gate `14302887671` | `017ad5589ae533d4f428312bc59d92409906544f6cd1add1a3db0ccc80383050` | 1910/1910 | 951/951 |
| TB127 census `14302668940` | `4edf0fe64c45fac424eb0c8ef9ed4e9eaae675373e32f06724df9ea4724f3cc5` | 9/9 | 1 PASS, 2 RED |

CB146 package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, package SHA-256 `457a9d061cbfe290baa1cad0b3df29b085f81f639dd8ea7e829e38aea6458984` (previous [build verification](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_cb146_p13_rotation_terminal_locus_print_code_build_record_20261117md); not a fresh package re-download). TB127 gate run `44024527625` / job `133841749525`, census run `44024687415` / job `133845742752`; TB126 gate/census runs `44005423680`/`44005461405`. Snapshot `23fad13a2c2cddff3b53f598ea4c7b39220a047f`, run `44029528086` / job `133857893634`, artifact `14304521670`, outer SHA-256 `451fc1f5d16b06cff5258f1c5799a8ff6f009923213b0377f9f0750215af6ff4`, inner archive SHA-256 `6e31b726c2036a8aee9c4d71d175ef9c4adc98e7824a8e5f149519dd50b0144a`, 5513/5513 source hashes. GitHub compare proves the package source is an ancestor of the snapshot (24 commits, docs/control only); CB144 `7b0668d432ccb187c5a2d856494064f0bcb2fb95` to CB146 (51 commits) changes precisely two semantic paths: FieldAlignedCurveNetworkTests.cpp and SurfaceCellDesignAcceptanceTests.cpp. No product, fixture, build, or selector drift. Local Git baseline is synthetic, not remote history.

## Assessment — independent derivation

1. **Gate MATCH.** 951 planned/executed/PASS; zero skipped/missing/duplicate/abnormal, 1032 membership, 81 deferred, exit 0, postflight true. 950 inherited substantive ledger rows equal TB126. Eight logs (156/168/173/175/190/191/477/705) differ only in allowed elapsed time and concurrent M3_CP4AB_FRAGMENT_DIAG newline framing. Row 951 passes without prior exception and there are no gate inventory lines. Execution boundaries exclude configure, rebuild, relink and benchmark. The committed gate hashes to `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`; first 950 rows plus header `9a112bd18c4f37248ae8c9fc2c942f9fd19cd67ca4a5236c13f5ed76f95a0290`. Census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Prefixes 491/497 with header `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` / `0eacb53afdb677e6047af1ccdff5518e9706bcc942161b473449d182a65a6a94`. Verified names of first 491 exactly equal focused30 + focused12 + selector449, respectively SHA-256 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. No newly accepted selector.
2. **Non-vacuity and exact diff.** Independently re-hashed CB144B `20aeaf0d6e999c12d634f7c505418628add662b4484fdfa6dddaa63c3b1ed4ae` and CB146 `4f1fae63d0d3f2626f02c4f27d26a923e0a525173112556fefe50d9e5be56967`. Test postimages SHA-256 `9160790d7e9830aee73bc6ce9094e277a49d5cff84036c74ac18b396db38b67e` and `898d04c1dac0ee609497220b978653acd316c72f39356b45193729757c636477`. Reverse application check and actual reverse application to scratch copies succeed; recovered preimages `417ef255e893af1cf46a736c99b5af1d593de97bf58559a47aa30088baaf1f89` and `f8bbfd4c7f7a199633271db57ce484a7b506e5d78143661151cd4fc88b034acb`. Row 951 at FieldAlignedCurveNetworkTests.cpp:18583 checks 0/1/2 cuts, exact ordering (including two exact parameters with equal double values), positive adjacent intervals covering [0,1], node and trace ownership, equal parameters, endpoint and shared-node rejection. Trace extent 39 makes maximum trace index 38 valid; node extent remains 16 for maximum 13. A skipped cut, reversed interval, wrong owner, approximate sort or wrong typed rejection fails the assertions. It is NOT a rotation-consumer direction witness.
3. **Census MISMATCH under RA-246 §5.** Cylinder 288 quads PASS; BunnyRandom RED with zero output; Vase RED with zero accepted output (189462 segments, 26817 arrangement cells, 67750 internal quads). Each case ran exactly once. After only permitted normalizations, BunnyRandom and Vase each differ in exactly two lines, source line 432→493 and 434→495; the two first_failure ledger fields shift 432→493, and raw log hashes differ. Reverse CB146 shows identical statements: `EXPECT_TRUE(independentOracle.ok()) << independentOracle.describe();` and `ASSERT_TRUE(result.is_produced()) << failure_context(result);`. 61 lines inserted above both; no assertion changed. All other permitted-normalized lines and prior terminal prefixes match. This is a comparison-contract omission, not semantic drift. Do not rewrite the old criterion, discard those lines, or mark TB127 MATCH. Existing LESSONS §5 (RA-102.1, normalize file:line) applies; future frozen comparator must authorize exact reviewed relocations and retain assertion identity before execution. No repeat TB necessary to prove this deterministic relocation.
4. **C3 close narrowly under this Review's explicit authority.** RA-244's split guard now passes; old first-terminal rejection has disappeared. Inventory (241,251): traces 107/38 nodes 149/178; (251,278): traces 92/41 nodes 184/162; both edges have distinct exact ordered parameters. All four records and upstream receipts unchanged. New failure is after mandatory drafts at trace event placement, not a rejection on either mandatory edge. Narrow obligation (remove the one-cut cardinality rejection without losing the split guard) discharged; this does not prove middle-piece ray direction, which is later and remains an independent obligation. Strict historical MISMATCH is not changed; this Review authorizes the narrow evidence disposition separately.
5. **C5 precise site (non-stable).** Verbatim suffix at face (5,104,359): `rotationReason=TraceEventPositionInvalid trace=0 eventIndex=18 eventPositionReason=NoCarrierMatch eventPositionPass=SourceEdgeUnavailable`. `EmbeddedGraphTopology.cpp:154–172` returns zero for origin-node/no-edge, segment count for terminal/no-edge, and nullopt with NoCarrierMatch/SourceEdgeUnavailable for any other no-edge incidence. `build_arcs:702–719` converts that nullopt to TraceEventPositionInvalid; the code has not reached ray ordering, nor even carrier search. Event index 18 is the network event array index, not a segment index. Trace 0 differs from all four mandatory-cut traces; no identity join to those cuts is established. The CB144 diff changes mandatory draft ordering and later mandatory ray direction; neither changes this predicate. This establishes the pre-existing unsupported event-placement branch exposed by CB144, not proof all tracing inputs are valid or that later rotation works.
6. **Exact contact support gap, not a demonstrated event identity.** A2a `SurfaceCellTracing.cpp:4070–4213` publishes FirstContact (Interior incidence on each participating trace), then TraceIntersection or TraceSelfClosure with explicit terminating roles. `field_aligned_common_carrier` can return no edge for a real face-interior contact. `FieldAlignedTerminalContact` (SurfaceCellTracing.h:430–436) stores exact barycentric position, struck trace and struck segment index; contact-node sourceVertex at SurfaceCellTracing.cpp:3022–3025 is provenance only, not position. A2a′ `TraceCut` (EmbeddedGraphTopology.cpp:154 vicinity) stores only integral segment-boundary position; `exact_trace_segment_end:267–289` can materialize terminating contact, while `exact_trace_path:291–314` and arc construction :731–770 cannot express a cut strictly inside a struck segment. A valid face-interior contact can therefore be rejected without an edge; an arbitrary position/role assumption is unsound. The published failure does **not** identify the event kind, node, role, paired terminal, exact point or struck segment. Raw census gives no such binding for this event. Do not claim that a specific face-interior crossing is proved. Need owning-stage rule for typed events, co-terminal FirstContact, and exact interior splitting, with evidence delimiting case. DESIGN §5 and Amendments 13/14 require actual embedded graph and forbid modifying the immutable A2a output. A consumer must use exact authority, not source-face membership or node provenance as positional identity. No guessing sourceEdge, choosing nearest endpoint, ignoring FirstContact, or blanket Terminal remapping.

## Recommendation — exactly one separate definition Review

`M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` is authorized **by this adjudication**, not directly by the TB127 MATCH route. Review/definition only. Before any source change, trace the canonical network event producer and consumer and freeze the exact event-position/arc contract, with source-supported identity evidence and a minimal next code/build scope. Use existing terminal-contact records, exact path support, paired incidences and validators. Determine whether existing authority establishes event 18's kind and exact position; if not, explicitly bound one read-only targeted observation for the future CB/TB cadence, not an assumed production fix. Distinguish a non-terminal FirstContact at the terminating trace's exact endpoint from a struck trace's interior split or invalid/ambiguous input. For a valid baseline, define a discriminating face-interior contact fixture and independent exact subdivision/coverage/orientation oracle; include equal or inconsistent claims, absent authority and multi-contact ordering negative controls. Freeze exact falsifiers: missing/ambiguous node-position binding, nonpositive or discontinuous source path, wrong struck trace/segment, duplicate node at inconsistent exact points, or any change to immutable network/accepted gate. If causal authority is missing, stop before freezing a repair and name the missing observation. Separately preserve (and plan, not execute) a rotation-level middle-piece direction witness that reaches both orientations under valid inputs; no false closure from row 951. No compile, test, runtime, CB145, broad rewrite, promotion, new selector or product mutation in the definition turn. No successor is started here.

Carry C5/O42/O43 open, O44/C1 and narrow C3 closed, C4/CB145 and exact grazing parked; D11=A, D12=A, D10 deferred, D6 pending. Stable 66 events/17 categories/49 recurrences, debt1, deferred81. Accepted CP2 491/491 package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; selector497/CP3/D0 unpromoted, chainRimSchedules=false. PR 8 draft, no metadata change.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/497 and 950 manifest prefixes and component selectors in assessment 1; accepted names equal. |
| Decisive claims independently re-derived | Four ZIPs, internal/raw bindings, ledger and log comparisons, exact test preimages and source predicate. |
| Non-vacuity checked | Row951 positive/negative witnesses verified; separate middle-piece rotation obligation not discharged. |
| Prior obligations discharged/carried | C3 narrowly discharged; C5, O42/O43, middle-piece direction, C4 and exact grazing carried; O44/C1 closed. |
| Stable accounting | 66/17/49, debt1, deferred81; CP2 package 11391685901/491; no CP3 promotion. |
| New candidates/obligations recorded | Non-stable comparison omission; C5 exact rejecting predicate and unresolved binding; tracker amended. |
| ORIENTATION currency line | M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV, 2026-11-17. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated gate interpretation, witness, active priority and recurring comparison pattern. |
| CHANGELOG | Entry added. |
| ROADMAP | CP3 remains active; review state updated. |
| Selector manifest | n/a: no new or promoted selector. |
| LESSONS | Existing §5 RA-102.1 and §2 RA-246 apply; no duplicate lesson. |
| Consolidation under CLEAN_UP_POLICY | Recent prior review folded historical records into Volume D3. Retain TB126/127, CB144/144B/146 and RA-244/245/246 as exact active baseline/definition/build evidence; no additional superseded per-turn document identified in the CB146-to-snapshot comparison. |
| Successor frozen | M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME; scope and falsifiers above. |
| Turn boundary held | Runtime-free; only documentation prepared. |
| review_check.py boundary | Local product/test/fixture/build and selector checks PASS; historical rewrite baseline checks FAIL (synthetic Git). GitHub compare independently confirms 8b7299b43764a6ba3444e5bc774a2f1b65e99731 ancestor of snapshot (ahead 5888, behind 0); fetched rewrite-source headings and verified handoff 4/4, orientation 1/1, tracker 0/0. Drift audit zero errors, three expected protected-document warnings (authorized currency edits); no policy mutation. |
| STATUS lifecycle maintained | Entry IN_PROGRESS; Started 2026-11-17T06:11:17Z; no resume timestamp; final beacon only after closeout. |
| Pushed to origin, branch in sync | Connector-driven snapshot/patch workflow, no real local origin; require remote applied commit, changed-path verification and cleanup before COMPLETE. |

Process limits: snapshot pre-read ordering was violated initially; switched to verified snapshot. Timer started about one minute after request; earlier actual deadline governs. Tool-call ledger incomplete across context compaction; exact total unavailable. External turn-based skill root SKILL.md fetch returned 404; repository cadence and mandatory policy remain binding. No fresh build, runtime or full package re-download.

## Owner-requested adversarial re-review (RA-247, 2026-11-17 UTC)

The owner asked for a critical re-review of this turn. It stays runtime-free: Haiku agents re-downloaded the TB126 and TB127 artifacts and ran a read-only consumer census. My own analysis read the source only.

### 1. Upheld

- **Gate.** 951/951 PASS, with rows 1–950 identical to TB126 (see §6).
- **Census.** The MISMATCH stands, and it is not semantic. CB146 inserted 61 lines above the two assertions, so `:432`/`:434` became `:493`/`:495` in BunnyRandom and Vase. That moved four lines, and two census `first_failure` fields shifted with them.
  - The comparison defect is mine. RA-246 §5 allowed only the appended terminal text, although an existing lesson (RA-102.1, normalize `file:line`) covers exactly this. That criterion should have allowed relocations that the diff proves.
  - Refusing to amend the criterion after the fact, and not repeating the TB, is right.
- **Narrow C3 closure.** Upheld.
- **C5 site.** `trace_event_position` (`EmbeddedGraphTopology.cpp:154–172`) returns nullopt for an incidence that has no event edge and is neither the origin nor Terminal. `build_arcs` (`:702–719`) turns that into `TraceEventPositionInvalid`.

### 2. Where the TB127 Review is incomplete

**G1. The kind of event is already decided by the source; no observation is needed.**

The Review left "event kind / node / role" open and allowed a bounded read-only observation. Listing every event producer in `SurfaceCellTracing.cpp` closes it:
- `SingularityPortOrigin` and the port junction (`:3880`, `:4617–4623`) carry no edge, but the producer requires `port->node == firstPort->node` for every incidence (`:4600`). So the node is the trace's own origin node, and `trace_event_position` returns 0.
- Barrier termination (`:3926`, `:4725`), singularity termination (`:2350`), limit cycle (`:3961`) and self-closure via the last segment (`:4764`) all publish an edge.
- The only events that can have no edge together with a non-origin Interior incidence are trace–trace contacts:
  - `field_aligned_publish_contact` (`:4203–4210`), which publishes a FirstContact with both incidences Interior, then a TraceIntersection with Terminal for the trace that stops and Interior for the struck trace;
  - the finalize path (`:4680–4686`).
  
  Both take their edge from `field_aligned_common_carrier`, which returns an edge that both segments touch.

So event 18 is a trace–trace contact inside face `(5,104,359)`, involving trace 0, whose two segments share no carrier edge.
- Which incidence of trace 0 it is does not matter: every such contact fails here for both traces, because the FirstContact incidences are always Interior.
- A further observation could name the other trace, but it would not change the contract.

**G2. Fixing the position alone would only move the failure. Every consumer of a node's location assumes a vertex or an edge.**
- **Position.** `TraceCut` stores an integer segment boundary only.
- **Locus.** `NodeLocus` (`EmbeddedGraphTopology.h:70–73`) holds only `vertex` and `edge`. `build_node_loci` registers a contact node through the event's edge, and fails with `EventLocusMissingSourceEdge` (`:914`) when there is none. That is the next terminal after a position-only fix.
- **Rotation.** There is no face branch (`RotationNodeLocusUnsupported`, `:1830`).
- **Arc ranges.** Splitting the struck trace inside segment k means two arcs share segment k. Ten functions read `firstSegment`/`onePastLastSegment`/`sourceFaces`/`sourcePath` from arcs:
  - `trace_ray_face`, `vertex_trace_ray_second_point`, `edge_locus_secondary_rank` and `build_rotation_system` (EmbeddedGraphTopology);
  - `build_source_face_ownership` (SurfaceCutGraph `:508–758`);
  - `annotate_trace_segment_incidence`, `build_fragment_corner_incidence`, `build_regions` (×3), `candidate_semantic_digest` and `validate_candidate_structure` (GlobalTopologyPlan);
  - plus users of `sourcePath` only: `edge_arc_schedule`, `bound_arc_schedule`, the phase-front builders, the conformity baseline and the display.
  
  Each needs an audit for any assumption that ranges are disjoint.

A definition that covers only "event position" repeats RA-244's lesson (read every consumer of the split object first).

**G3. The common-carrier rule is a proxy, and it conflicts with Amendment 13 even where it works.**
- For a contact strictly inside a face, the event's edge is a carrier both segments touch, not where the contact lies.
- A2a′ then places the node at a segment boundary and registers it as an edge locus. That amounts to sliding the node along the struck segment onto that edge.
- The result is a valid combinatorial embedding only while at most one contact lies on that side of the struck segment. Otherwise two nodes land on the same integer position and fail closed with `TraceEventPositionNodeConflict`.
- It is still "carrier provenance used as graph authority", which DESIGN Amendment 13 forbids. I'm registering it as **O45**: a conformance debt that does not block now.
- The new face-node path must apply first only to contacts that have no common carrier, so the gate is unchanged by construction (no gate row reaches that branch). Switching every contact over later is a separate decision, staged per RA-230.

**G4. Why BunnyRandom reaches this now, and why nothing caught it.**
- Two segments in one triangle that both have an entry and an exit edge always share an edge (2 + 2 > 3). So the common carrier can be missing only when a segment has no `incomingCarrier`.
- That happens on a trace's first segment, after vertex transit (`:2720`, and via `proposal.nextIncomingCarrier` `:4523`) and after edge transit (`:2817`). The D11 and D12 work made such segments more common on BunnyRandom.
- No test in `tests/` mentions `TraceEventPositionInvalid`, `NoCarrierMatch`, `EventLocusMissingSourceEdge` or `RotationNodeLocusUnsupported`, so none of these paths has ever been reached by a test (lesson RA-243).

**G5. No user decision is needed.** Amendment 13 already requires the actual embedded graph, whose nodes include contacts inside faces. Amendment 14 already allows A2a′ to subdivide a trace in the derived arrangement while leaving the immutable network unchanged. So the face-interior node is required by the existing contract, not a new one.

### 3. Realigned definition scope (`M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME`, Review only)

The DEFN takes G1–G5 as established and must produce all of the following.

1. **Representation.** I recommend:
   - `NodeLocus` gains a face plus an exact barycentric point;
   - a trace cut is either an integer boundary or (segment k, exact point) strictly inside k, using `terminalContact.barycentric` and `struckSegmentIndex`;
   - several cuts inside one segment are ordered by an exact parameter along that segment;
   - the two arcs at an interior split share segment index k, and their exact `sourcePath` pieces end or start at the contact point.
2. **Consumer audit.** Go through all ten range consumers in G2. For each, state whether two arcs sharing segment k is correct, or what must change.
3. **Rotation rule at a face node.** Order the rays counter-clockwise using an exact orientation test in the face's own vertex order (Amendment 26: one rotation per source entity). This covers a T-contact (three rays), self-closure (three) and a symmetric double termination (two).
4. **Test reachability.** Find a way to build a minimal network with a face-interior T-contact that has no common carrier, by hand or from an existing fixture. Check that it reaches the new branch.
5. **Freeze the sequence below,** with the first CB's diff frozen exactly. The DEFN may also freeze later diffs if they are independent.
6. **Plan the rotation-level middle-piece direction witness** (RA-244 gap). If no fixture can reach both directions, name the missing fixture.

**Stop rule:** if the audit finds a consumer that cannot tolerate a shared segment index without a new DESIGN contract, stop and name the decision.

### 4. Turn sequence (each turn testable on its own)

| # | Turn | Owner | Content |
|---|---|---|---|
| 1 | `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV` (+ RA-247) | Review | COMPLETE |
| 2 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Review | NEXT. Freezes everything in §3. |
| 3 | `M6-CP3-CB147-P13-FACE-CONTACT-EXACT-HELPERS` | Code + Build | Pure exact helpers, not wired in: the contact parameter along a segment and the order of several contacts in one segment; the ray order at a face node; partial-segment exact path pieces. Unit tests use inputs that rounding cannot separate. No product dispatch changes. |
| 4 | `M6-CP3-CB148-P13-FACE-NODE-LOCUS-AND-INTERIOR-CUT` | Code + Build | Representation: face `NodeLocus` and interior `TraceCut`, with range consumers updated per the audit. Still not wired, plus an equal-product test showing that integer-cut cases produce byte-identical arcs. |
| 5 | `M6-CP3-CB149-P13-FACE-CONTACT-SWITCH` | Code + Build | Contacts with no common carrier go through the face-node path, which is also wired into locus registration and rotation. Includes the unit test from §3.4. The common-carrier proxy (O45) is untouched. |
| 6 | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | Test + Benchmark | Gate unchanged by construction; census BunnyRandom moves past C5. |
| 7 | Outcome Review | Review | Closes C5, or classifies the next terminal. |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45 conformance switch | — | — |

The DEFN may merge or split steps 3–5 if its audit shows that is safer, but every step must stay independently testable.

### 5. Carried

- Open: C5, O42, O43, O45 (new, deferred).
- Middle-piece direction witness still to do; C4/CB145 and exact grazing parked.
- Closed: narrow C3, O44, C1.
- Decisions: D11 = A, D12 = A, D10 deferred, D6 pending.
- Counts: stable 66/17/49, debt 1, deferred 81; CP2 491/491.
- CP3/selector497 unpromoted; `chainRimSchedules=false`.
- DESIGN.md unchanged (G5).

### 6. Evidence re-verified (Haiku agents)

- **Archives.** All four ZIPs match: TB127 gate `017ad558…`, TB127 census `4edf0fe6…`, TB126 gate `c13a0f5e…`, TB126 census `79acdba0…`. Checksums: gate 1,910/1,910 OK and census 9/9 OK for both TB126 and TB127.
- **Gate.** TB127 is 951 PASS, 0 RED.
  - Rows 1–950 have 0 differing ledger cells compared with TB126.
  - Eight raw logs differ (156, 168, 173, 175, 190, 191, 477, 705); none differs once newlines are removed.
  - Row 951's log contains no "exception" or "Failure".
  - Every raw log hash matches its ledger entry.
- **Census.** Cylinder is identical.
  - BunnyRandom differs in `:432`→`:493` and `:434`→`:495`, plus its terminal line, which keeps the TB126 text as an exact prefix and gains the suffix quoted above.
  - Vase differs in the same two line numbers, and its terminal line is byte-identical.
  - In the census ledger, only `first_failure` changed, in rows 2 and 3, from 432 to 493.
