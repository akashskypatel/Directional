# TB152 edge-piece face-side full-gate independent review — 2026-11-20 UTC

## Situation

**PASS at the frozen helper scope, no product promotion.** Independent inspection of both immutable result ZIP files and their member checksums re-derives the full TB152 gate. The next Code + Build owns only O49 source-face edge-only ownership wiring; the later row686 test-only real-piece oracle has a separate exact patch and must not be implemented in this Review.

## Background — exact authority

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open/unmerged.
- Compiled source `1df6a09ad386791a9befddd9658ddc4d5bb795f2`, CB168O artifact `14628449217` (`runtimeExecution=false`, GMP/GMPXX); TB152 run `44739657527`, result artifact `14630642490`, ZIP SHA-256 `5bfce8410e736c1fce63c4c6fa9b272b20ff91ceac8044bb339c814bfaa3cd04`.
- Reference TB151 artifact `14619414153`, ZIP SHA-256 `c28d6ecc128bf9994d3c5f5ba2e2c799c192176f11d8818ca08c70d65caf1dab`.
- Review source snapshot run `44745759896`, artifact `14632952390`, source SHA `ae7086ba47d1cce935694790d95616faf4c81852`. Source TAR and all 5,647 files independently hashed. The snapshot contains only the review-entry STATUS and a temporary snapshot marker beyond the retained semantic source.

## Assessment — independent results

- Both ZIP hashes match GitHub artifact digests; all **1,942/1,942** TB152 and **1,940/1,940** TB151 member checksums match.
- Manifest TB151 SHA-256 `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da` is an exact byte prefix of TB152 manifest SHA-256 `cab375d014112b6ab48fe468003b9a57b2918a717e6f56e7478f0417362c0204`, with one appended row 967; membership **967 GATED +81 DEFERRED =1048**.
- TB152 **967/967 PASS**, zero RED, skipped, abnormal, duplicate, missing, bad controls or unexpected PASS. First **491/491** remain accepted CP2. Row 967 reports one successful Google Test and process exit zero.
- First **966/966** ledger identities match TB151. **704/966** raw logs are exactly equal; the remainder match under frozen N1 (Google Test elapsed time), N2 (CRLF/LF) and N3 (complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records in a multiset, not fields or omissions). All **1,750** N3 records and **504** unmasked ordered slide-contact records match on both sides. No other line was normalized.
- `execution-boundary.json` independently reads `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `postflight=true`, `exit=0`. No census was run. The helper has only declaration, definition, and its focused test: no production caller.
- The row 967 test discriminates Forward vs Reverse, reversal, half-slide cuts and non-edge/invalid inputs. Removing the helper behavior would make the focused test fail. This is non-vacuous helper evidence, **not** O49 integration evidence.
- No new stable regression or candidate; retain **66 events / 17 categories / 49 recurrences**, one produced-witness debt, **81** deferred. CP2 **491/491** remains accepted. CP3, selector497, D0, H4, row686 and the four slide contacts remain unpromoted. Sphere row686 remains χ6 vs sourceχ2 (+4); rows669/698 still exhaust.

## Recommendation — frozen future patches and stop gates

**Successor 1 (only next turn):** `M6-CP3-CB168P-P13-EDGE-ONLY-SOURCE-FACE-OWNERSHIP` (Code + Build, compile-only). The exact proposed source patch is `Architecture_M6_CP3_CB168P_O49_Edge_Only_Source_Face_Ownership_Exact.diff` (withdrawn by [RA-275](#ra-275--adversarial-re-review-of-this-review-2026-11-20-utc); retained in Git at `e3a7bfc38`). It changes only `src/geometry/SurfaceCutGraph.cpp::build_source_face_ownership`: one edge-only piece uses `edge_piece_face_side` to select the incident face's oriented orbit; neither face becomes an interior `traceCutFaces` member; edge-side ownership is recorded, other owners skipped. Its unchanged faceThenEdge path, terminal-slit exception, certificate filters and cut barriers must remain valid. **STOP** on a missing/invalid carrier, wrong incident-face side, a new owner in another face, any accepted-row raw change beyond frozen N1–N3 or a new RED. Compile eight RA-245 GMP/GMPXX targets, `runtimeExecution=false`; no test or benchmark in CB. The separate TB must show strict prior-row MATCH, and no production census is claimed for unwired fixture conditions.

**Successor 2 (later, not started):** `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE` (Code + Build, compile-only), after CB168P and its independent TB/Review gate. Exact proposed test-only patch: `Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_Exact.diff` (withdrawn by [RA-275](#ra-275--adversarial-re-review-of-this-review-2026-11-20-utc); retained in Git at `e3a7bfc38`). Only row686 selects the new independent face+edge piece interpretation; all other callers keep the chord oracle. This derives its geometry from trace transit points rather than querying the production `exact_trace_segment_pieces` helper. **STOP** if an edge interval is not a valid source-edge subset, if terminal contacts are wrongly extended into slides, if χ changes from 6 before the stop switch without an explained source-backed cause, if any prior selected identity changes, or if the new oracle is merely a second copy of the producer. It must not claim repaired χ2 until a subsequent stop-switch TB proves it.

Both proposed patches are planning artifacts, not implemented source. Each passed `git apply --unidiff-zero --check` on the snapshot; zero-context is used only for the stored diff documents to avoid whitespace-only context lines under the repository whitespace gate. No compile or runtime proof exists for either; the next Code + Build must independently check exact preimages and compile. Do not combine the two code turns, change the production switch, add counts to a digest, or activate H4 in this Review. RA-274 S5 conformity-reader and accepted-chord test inventory remains owned by the later producer-switch review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB151 manifest `2a902d36…` is byte prefix of TB152 `cab375d0…`; 491/491 accepted remain PASS; selector497 not promoted |
| Decisive claims independently re-derived | 967 outcomes, 966 normalized log comparisons, 1,750 N3 records, 504 unmasked slide records, package checksums and boundary flags |
| Non-vacuity checked | Row967 contains positive winding/reversal/split and negative inputs; source helper has no production caller |
| Prior obligations discharged/carried | RA-274 S4.2 gate/helper evidence discharged; O49 wiring and row686 oracle frozen as distinct future changes; RA-274 S5 carried to producer-switch Review |
| Stable accounting | 66/17/49; debt1; 81 deferred; CP2 491/491; no promotion |
| New candidates/obligations recorded | No new candidate; existing O47/C5/O49/H4/row686 carried, no tracker rewrite needed |
| ORIENTATION currency line | TB152 Review 2026-11-20 updated |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 no witness change; §8 no new pattern, prior lesson cited |
| CHANGELOG | Independent review entry added |
| ROADMAP | CP3 active state and current next-turn position updated |
| Selector manifest | n/a: selector is unchanged, no acceptance or new identity in Review |
| LESSONS | Existing evidence/oracle and source ownership rules apply; no new distinct pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: no newly superseded standalone Review artifacts eligible for safe folding; existing historical index preserved |
| Successor frozen | Exactly one next turn CB168P; falsifiers in Recommendation; CB168Q remains later conditional |
| Turn boundary held | Review-only documents and future diffs; no product, test, fixture, selector, build or runtime mutation |
| review_check.py boundary | Snapshot lacks Git history; exact selector hashes and source diff boundary checked separately; the script cannot prove history without a Git worktree |
| STATUS lifecycle maintained | Entry beacon and final beacon per policy; final state written only after documentation transport verification |
| Pushed to origin, branch in sync | `drive_apply` run `44747990701` completed successfully; eight document paths committed and PR head confirmed at `e3a7bfc38c5ece75cb5ebeebdb6ff2bdbd6e7647` before final cleanup; no product source changed |

## RA-275 — adversarial re-review of this Review (2026-11-20 UTC)

**Verdict: TB152 PASS upheld; both frozen successors withdrawn and replaced by exact, tested patches.** The main CB168P defect originates in **my RA-274 S4**, which told this Review to "read `exact_trace_segment_pieces`"; this Review implemented that instruction faithfully.

### S1 — Evidence (independent, read-only)

- Both ZIP SHA-256 values and GitHub API digests match (TB152 `5bfce841…3cd04`, TB151 `c28d6ecc…1dab`). TB152 967/967 PASS; rows 1–966 have identical (row, test, verdict) to TB151; row 967 ran one test, OK.
- Row 686 `m3Cp4c2ActualGraphOracle` records are byte-identical in TB151 and TB152. The sphere record ends `producerStatus=error;producerError=CutSearchExhaustedBeforeCellularity` (V18/E30/F18, χ6 vs 2). The torus record is split across lines by an interleaved concurrent line in both artifacts, so readers must parse records by witness, not by line.
- Stale premise corrected: TB141's `duplicateCutCrossing` appears in no TB151/TB152 log. The sphere and rows 669/698 never establish the disc embedding, and `build_source_face_ownership` runs only after it (`SurfaceCutGraph.cpp:893–898`).

### S2 — Design defects in the frozen successors

1. **CB168P read the segment, not the arc.** It took `exact_trace_segment_pieces(*trace, segmentIndex)`, the whole segment, instead of the arc's own pieces (`sourcePath` split by `sourcePieceCounts`, EPO-3). An arc that starts at a cut inside a slide owns only the edge piece after the cut, while the segment is [face, edge] (row 960 `{slideCut, end}` = {1,1}). The stop switch creates exactly that arc on the sphere (`carrier_contact_slide_position` cuts the struck trace inside its slide). The frozen patch would then mark the face trace-cut by that arc with both its orbits, the O49 defect it was meant to remove, and it is a second decomposition beside the published one (RA-217).
2. **CB168P had no witness and no test.** No gate row or census fixture reaches the changed code with an edge-only segment:
   - TB141 gate slides are all faceThenEdge.
   - BunnyRandom's edge-only receipts stop at `TraceEventPositionNodeConflict` in `build_arcs`.
   - The sphere does not certify.

   The function is file-local (anonymous namespace, `SurfaceCutGraph.cpp:22–1092`). "Strict prior-row MATCH" passes whether the wiring is right or wrong, so the STOPs "wrong incident-face side / new owner in another face" could not be observed (RA-215, RA-264).
3. **CB168P published misleading records.**
   - It wrote `traceFragmentSides` for both incident faces, although neither contains a fragment. That flips `trace_crossed()` (`SurfaceCutGraph.h:100`), the predicate exempting a face from the single-orbit check in `proves_cellularity` (`SurfaceCutGraph.cpp:1116–1117`), and it enters the certificate digest (`:916`).
   - `arcExclusionReasons.erase(F)` was dead: the end-of-arc loop (`:628–634`) relabels F `Other`. The census would then report an edge-only arc as an unexplained interior incidence.
4. **CB168Q was sound in mechanism but accepted records the producer rejects.** Writing the slide interval into both incident faces keeps seams paired, which the old one-face boundary path did not. However:
   - It did not require a terminal contact to lie strictly inside the face piece, as `exact_trace_segment_pieces` does.
   - It did not require the segment to leave at the slide end.
   - It added a face piece lying along a face edge as a trace piece.
   - It read raw `parameter.value` instead of the oracle's own edge parameterization.
   - Its "χ stays 6" STOP had no derivation: V and E come from the network, and only F is geometric.
5. **Both diffs were zero-context with no preimage hashes.** A zero-context pure insertion (`@@ -565,0 …`) lands by line number with no placement check.

### S3 — Realignment (exact, runtime-free checks only)

`-fsyntax-only` (GMP defines) shows 0 errors and warnings 22/27/42 for EGT.cpp/SCG.cpp/tests, equal to HEAD. Both diffs pass `git apply --check`, stacked, on `da57cbe63`. No build or run.

| Order | Turn | Exact content |
|---|---|---|
| NEXT | `M6-CP3-CB168P-P13-O49-ARC-PIECE-EDGE-ONLY-OWNERSHIP` | Full patch details and the row-968 test are in the expansion below this table. Inert until the producer publishes edge pieces (today `exact_trace_path_between` emits face pieces only and counts are 1, `EmbeddedGraphTopology.cpp:1936`). |
| Then | `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE` (test-only, stacked) | Diff (withdrawn by [RA-276](#ra-276--adversarial-re-review-of-ra-275-2026-11-20-utc); retained in Git at `41b94c585`) SHA-256 `b30af8e7053ab8ada2920d85569701f3db44e4e8d7a1ba4661b1cc65e84c4a28`, `72 4` tests. Preimage: tests after CB168P `dc6e600c1ae666835c86447bafde8b40a9ad1fc3cc606f3193e947450472b547`. Row 686 only reads real pieces. It fails closed on the four record inconsistencies in S2.4 and uses `cp4c_oracle_edge_parameter`. Postimage tests `84c9b548d97137aff498dd69b388086e99529b2cab800d94490a65f0bdb77310`. |
| Then | `M6-CP3-TB153-P13-ARC-PIECE-OWNERSHIP-AND-ROW686-ORACLE-FULL-GATE-EXEC` | Manifest SHA-256 and STOP rules in the expansion below this table. |
| Then | `M6-CP3-TB153-P13-…-FULL-GATE-REV` | Attributes any row 686 F/χ change to the four row-963 contacts. Freezes the producer switch (paths + counts + rays + ranks; counts in the digest) after the RA-274 S5 checks and S4 below. |

**CB168P expanded:**
- Diff (withdrawn by [RA-276](#ra-276--adversarial-re-review-of-ra-275-2026-11-20-utc); retained in Git at `41b94c585`), SHA-256 `ddc146d198c1ecaa3c8b0f5ec2046a97e8b4c806b1070cf82341d53966f5757e`.
- Numstat `2 0` SurfaceCutGraph.h, `23 0` EGT.cpp, `11 0` EGT.h, `33 0` SCG.cpp, `118 0` tests.
- Preimages (= `da57cbe63`; precheck `git diff --quiet 1df6a09ad HEAD -- src include tests`): EGT.cpp `8b86e46f7baed765d43c0848012f2782babdd1ca0c105475e6f3194a5d156ac9`, EGT.h `78437758477dfdb218258a9114de14bac3fb3a0bce5c95a157e6ff70dc7676bf`, SCG.cpp `8533fa4e99c4e7f64237b90338829629d1a5939a680788ce8f46d2c16fb0a7c4`, SCG.h `b52ecf21e24afaff721e0aa0112faa14594480a7095f3917d29ed3a05d38a28b`, tests `f19009d7aa42c9b1fd5a02b2d1e8988f5a9153baff64368658e797bd26f42658`.
- Adds `trace_arc_segment_pieces(arc, segment)`, the arc's own part of a segment.
- In `build_source_face_ownership`, an arc part that is exactly one edge piece:
  - inserts that edge as a barrier;
  - gives each incident face the edge-side owner `edge_piece_face_side` assigns (Forward → forward-dart orbit);
  - leaves the face out of `traceCutFaces` and `traceFragmentSides`;
  - labels it with the new reason `EdgeOnly`.
- Row 968 `FieldAlignedCarrierOccupancy.TraceArcSegmentPiecesReadTheArcsOwnPartOfASlide` uses real producer pieces:
  - The arc from a slide cut owns `{(0,1), 5/8 → v1}` while the segment has 2 pieces.
  - Today's chord arc owns a face piece.
  - It covers five rejections.

**TB153 expanded:**
- Manifest (withdrawn by [RA-276](#ra-276--adversarial-re-review-of-ra-275-2026-11-20-utc); retained in Git at `41b94c585`) SHA-256 `d5cff5133a579da8416f9eb0cc708b74f2cae6ecdcf805c0526ee99e910912cb`: TB152 byte prefix plus row 968, so 968 + 81 = 1049.
- STOP unless all of the following hold:
  - row 968 PASS;
  - rows 1–967 except 686 MATCH TB152 under N1–N3, receipts raw;
  - row 686: the two-ring and torus records equal TB152, the sphere keeps `oracleAvailable` true with every `boundaryCyclesValid=true`, and its full record is reported;
  - census 3/3 MATCH TB151 under N1–N4;
  - CP2 491/491.
- Predicted sphere χ: 6 (network V/E unchanged). Any F/χ change is reported, not a STOP.

### S4 — Obligations carried

- **Across-face side of a faceThenEdge slide.** After the switch, a [face, edge] segment's edge piece borders the face across, which gets no side owner from it. This is unchanged today, because the carrier is already a barrier. The producer-switch Review checks per fixture whether an uncut component bordering only a published slide loses its seed.
- **O49 integration is unwitnessed by any fixture.** The evidence is helper-level (rows 967 and 968) until a plan with an edge-only part certifies.
- **RA-274 S5 checks stand**, plus: grep accepted tests and diagnostics for `notTraceCutReason` names before the switch.

## RA-276 — adversarial re-review of RA-275 (2026-11-20 UTC)

**Verdict: RA-275 upheld TB152 correctly, but its realignment was wrong in four ways, all mine.** RA-275's CB168P would have failed its own test. It wired one of at least three ownership readers. It kept O49 on the producer-switch path, where it does not belong. It froze a switch with an unmeasured precondition. TB152 PASS stands.

### S1 — Evidence (read-only)

- TB152 ZIP `5bfce841…3cd04` re-verified.
- Row 963 shows all four sphere walls (traces 0, 1, 21 and 22) slide on their **last** segment (6 of 7), with `strictlyInside=1` and `sharedEvents=0`. Three slides end at `1/1` and trace 22's at `0/1`, all vertex ends.
- The row 686 sphere record is unchanged: V18/E30/F18, χ6 vs 2, 18 components each χ1 and `boundaryCyclesValid=true`, `CutSearchExhaustedBeforeCellularity`.

### S2 — Defects in RA-275

1. **Its frozen row 968 would fail.** It asserted `exact_trace_path_between(trace, slideCut, end)` has a value. That function interpolates on `trace_segment_canonical_exit`, which returns nullopt for any segment with an edge transit (`EmbeddedGraphTopology.cpp:834–855`). The ASSERT would therefore stop the test RED. A runtime-free freeze must trace every helper its test calls; I traced only the piece helpers.
2. **The O49 inventory was incomplete.** RA-274 S3 (mine) built the reader list by grepping `sourcePath`/`sourceFaces`/`sourcePieceCounts`. It missed the readers that read trace segments directly. Ownership of a trace-touched face has at least three producers:
   - the certifier (`SurfaceCutGraph.cpp` `build_source_face_ownership`);
   - plan fragment ownership (`GlobalTopologyPlan.cpp:1259–1283`, both arc orbits per segment face, k+1 check `:1421–1428`);
   - plan corner incidence (`build_fragment_corner_incidence`, `:458–620`). This one gates: `TraceSegmentCarriersCoincide`, `SourceFaceCarriesMultipleTraceCuts`.

   RA-275 changed only the first. Once edge pieces were published, the certifier would call the face uncut with one orbit while the plan still labelled it with both.
3. **O49 does not gate the producer switch.** All three readers take segment ranges from cut positions (`EmbeddedGraphTopology.cpp:1923`) and read `trace->segments`, so publishing real pieces changes none of them. The one switch-induced O49 effect is the disc phase front admitting an all-edge-only arc (RA-274 S3). TB141 R-edge, RA-274 and RA-275 all put O49 before the switch; that ordering is withdrawn. The real driver for reading arc pieces in ownership is the **stop switch**. A slide cut puts one segment into two arcs, and the plan's corner incidence rejects a second cut in one face. The tail arc is skipped only as a non-separating terminal slit (`GlobalTopologyPlan.cpp:520`, `:1270`; `is_terminal_slit` = no `terminalBarrier` and last segment). The walls slide on their last segment, so this turns on each wall trace's `terminalBarrier`, which is unmeasured.
4. **Overstated mechanisms.**
   - S2.1 said the stop switch creates "exactly that arc" with a defective owner on the sphere. Whether ownership reads that arc depends on the terminal-slit rule above, so this was not established.
   - S2.3 blamed `proves_cellularity`; there, the `Conflicting` status already masks the problem. The real consumer of `trace_crossed()` is the plan (`GlobalTopologyPlan.cpp:1618–1627`): an unlabeled face whose certificate owner is trace-crossed fails `SourceFaceFragmentOrbitMissing`.

   The conclusion stands: never write fragment sides for uncut faces.
5. **The new reason was unaccounted for.** `EdgeOnly` would fail `region_frontier_interior_arc_census_is_valid` (`tests:5528–5535`), which accepts six names.
6. **The switch precondition was never measured.** `exact_trace_segment_pieces` and `exact_trace_piece_path_between` have no production caller and have run only on hand-built rows 960, 965 and 967. Nobody knows whether every sphere trace has real pieces whose counts bind (RA-222, RA-228). Rays come from trace records (`trace_ray_face`, `vertex_trace_ray_second_point`, `EmbeddedGraphTopology.cpp:2232–2520`), so the switch needs ray code (RA-261).

### S3 — Realignment (exact; `-fsyntax-only` 0 errors, warnings 42 = HEAD; stacked `git apply --check` on `546243920`)

| Order | Turn | Exact content |
|---|---|---|
| NEXT | `M6-CP3-CB168R-P13-SPHERE-REAL-PIECE-REACH-RECEIPT` (test-only) | Details and the receipt's output lines are in the expansion below this table. |
| Then | `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE` (test-only) | RA-275's fail-closed oracle, unchanged in content, rebased onto CB168R. [Diff](Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_On_Receipt_Exact.diff) `0c096c94c8124dbf541e96abc07b4c5810d4705dd6ffd6e7f066ecd6aa91d2e5`, `72 4` tests. Preimage tests `db2bd6f04cca09ddb61804a2ec92feb7165ab82381ecba90928bbeb1fc691cb3`. |
| Then | `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-EXEC` | [Manifest](gates/Architecture_M6_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Case_Manifest.tsv) `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116`: TB152 byte prefix plus row 968, so 968 + 81 = 1049. STOP rules in the expansion below. **No census**: product source is unchanged (RA-242), and the TB greps the diff. |
| Then | `M6-CP3-TB153-…-FULL-GATE-REV` | Uses row 968 to decide the switch shape; details in the expansion below. |

**CB168R expanded:**
- [Diff](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Exact.diff) `5aee7b0984444dd35aff935764beabd10070b5ed766b25dbe19b882f7739bfec`, `86 0` tests. Preimage tests `f19009d7aa42c9b1fd5a02b2d1e8988f5a9153baff64368658e797bd26f42658` (precheck `git diff --quiet 1df6a09ad HEAD -- src include tests`).
- New row 968 `TraceTerminationCorrection.PrescribedSphereRealTracePieceReachIsPublishedNonGating` runs the switch's own helpers on all 24 sphere traces.
- It prints:
  - `SphereRealPieceReach` with counts of face / faceThenEdge / edgeOnly / rejected segments and of path and binding failures;
  - one `SphereRealPieceSegment` line per slide or rejected segment, giving `segments=` and `terminalBarrier/Contact/Point`.
- Its only assertion is ≥ 4 slide segments, which row 963's walls guarantee.

**TB153 STOP rules (all must hold):**
- row 968 PASS, with its lines reported verbatim;
- rows 1–967 except 686 MATCH TB152 under N1–N3, receipts raw;
- row 686: the two-ring and torus records equal TB152 (compare whole records; a record can be split by an interleaved line); the sphere keeps `oracleAvailable` true and every `boundaryCyclesValid=true`;
- CP2 491/491.

The sphere record is reported, with χ6 predicted. A change is a finding, not a STOP. If CB168Q fails closed, report it together with row 968's rejected list.

**TB153-REV expanded:**
1. Attribute the row 686 sphere record.
2. Use row 968 to decide the switch's shape:
   - If rejected = path failures = binding failures = 0: freeze an unwired piece-based ray helper with a test, then the switch CB. The switch moves `build_arcs` to the piece path, rays and ranks to pieces, and counts into the digest, after the RA-274 S5 checks.
   - Otherwise: first freeze the producer-rule fix for the listed records.
3. From the four walls' `terminalBarrier`, decide whether the stop switch needs arc-piece ownership in all three readers.

**Withdrawn:**
- RA-275 CB168P (`ddc146d1…`) and its TB153 manifest (`d5cff513…`), retained in Git at `41b94c585`. Arc-piece ownership becomes a held track, scoped by row 968. If needed, it lands as one shared helper with its test, then the certifier, plan-fragment and plan-corner readers together, inert until the stop switch.
- RA-275's CB168Q file is superseded by the rebased one (same code).

### S4 — Obligations carried

RA-274 S5; RA-275 S4 (across-face side of a faceThenEdge slide); disc-phase-front admission of all-edge-only arcs at the switch; `EdgeOnly` validator names if O49 lands; the segment-reader inventory below.

**Segment-reader inventory** (Haiku read-only audit; decision readers only, excluding `SurfaceCellTracing.cpp`). Slide treatment: a = straight chord to the slide end, b = reads the slide, c = rejects a slide segment, d = carriers only.

| Reader | Slide | Consequence at the switch |
|---|---|---|
| `exact_trace_path` / `exact_trace_path_between` → `build_arcs:1938` | a, and c when clipped | The producer itself; it is what the switch replaces. |
| `vertex_trace_ray_second_point` (`EGT:2338`) → `vertex_locus_secondary_parameter` | a | Ray to the slide end: rays and ranks switch with the paths (RA-261). |
| `edge_locus_secondary_rank` (`EGT:2504`, far end `:2583`) | a | Same as above. |
| `trace_segment_canonical_exit` → `build_rotation_system:3075`, `trace_segment_contact_parameter` → `collect_face_contact_nodes:1230`, `exact_trace_interior_point` | c | Rejects contacts and cuts inside slide segments. This is the stop switch's domain and must be read before freezing it. |
| `trace_crossed_source_edges` (`SCG:243`) | b | Records the slide end as a crossing of the outgoing carrier. Unchanged. |
| `build_source_face_ownership`, `build_regions` fragments (`GTP:1259–1283`, mismatch `:1447–1452`), `build_fragment_corner_incidence` (`GTP:458–704`), `build_cut_node_bindings`, `trace_event_position` | d | Unchanged by the producer switch. The first three are the ownership readers for any arc-piece rule (S2.2–S2.3). |

The `localTraceChords` path (`trace_segment_exit_barycentric`, `GTP:255`) is a chord reader feeding diagnostics only. `carrier_contact_slide_position` has no caller yet (the stop switch).
