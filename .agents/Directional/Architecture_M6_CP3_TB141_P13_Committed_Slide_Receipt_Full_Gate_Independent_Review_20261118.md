# TB141 independent review — evidence MATCH; CB167 frozen

## Situation

`M6-CP3-TB141-P13-COMMITTED-SLIDE-RECEIPT-FULL-GATE-REV`, entered 2026-11-18T21:57:04Z. Evidence adjudication: MATCH. Scope decision: R+ and R-edge under RA-262 S3/EPO-6; no R0 or R-x. This record freezes CB167 for the next turn only, after the Review COMPLETE beacon. No compile, generated product execution, product or test source edit on the working branch, gate/selector mutation, or promotion. PR #8 remains open draft, unmerged.

## Background — immutable authority

[Execution report](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Execution_Report_20261118.md); [RA-262 S2–S4](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md#ra-262--exact-piece-ownership-contract-design-stop-resolved-2026-11-18-utc). CB166 semantic source `3b599879ac05a79fb2ddce9a930da3683051017d`, package 14468664897, ZIP SHA-256 `02382960246e34577e34780b842472213ac7fa6925d60dc886fba2f7273d7ddc` (package identity from execution preflight; not freshly downloaded here). Review snapshot `7a5a3ebe2c9aa26d19ff44de40fb3b3e2e8c05f7`, run 44406879246, job 135164532971, artifact 14475016742, ZIP SHA-256 `84201d9f5fe1d3e0ef0631dd4e1077fd0dd95571287c507896c35fc7b6dd3e44`; 5,585/5,585 snapshot hashes verified. GitHub comparison from CB166: 19 commits ahead, zero behind, 11 changed paths, only docs/evidence, STATUS and control state. No product/test/fixture/build/gate drift.

| Role | Result artifact | SHA-256 (recomputed) |
|---|---:|---|
| TB140 gate | 14458589267 | `4816ea208223cac9c48507602d491edf9542176654d580acf25a6f2b4a989d84` |
| TB140 census | 14460885073 | `1c472957c6f84ac17114f3e2c070c57331eee0e261596baeb6055869d3ee9521` |
| TB141 gate | 14473040819 | `5f53a3990d5e49ea08f1440180fb155409229c4739e7b851a4081d1a0f0a47d6` |
| TB141 census | 14473701160 | `fa4afc3b5004e485d34d073e3d26b9897ffab68716203129aa3a12a5c7e86571` |

TB141 gate run 44399195712/job 135137438653, census 44399200774/job 135145910098. Six result/log ZIPs match live terminal mailbox records. Baseline source `fb51da7142646ebed97527d976fd8b382607160a` package 14459000178. Re-opened primary logs in Library archive `Directional_TB141_verified_execution_20261118.zip`; 3,870/3,870 recursive result hashes. Exact frozen inputs: gate `390fe1bd2c2e5f6d490ed21dac52219acefd9646081d361d2d4e174dfdedbf52`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

## Assessment — independently derived

Offline compare reproduced 959/959 gate and 3/3 census matches under N1–N6, nine parser controls passed. It verifies test names, exact identity/exit/site and raw log hash, no missing/skipped/duplicate/abnormal/new RED. Gate 958 PASS, permitted RED 858 at SurfaceCellTracingDisplayTests.cpp:155 (`faceLocus.sourceFace.has_value()` false). Exit 90 and control_bad=1 are not all-green evidence; census exit 0 report-only. Row 648 did not reach sphere assertions. Membership 959 + 81 = 1040. Accepted prefix matches exact 491 names and PASS outcomes. Source selector byte hashes (LF): focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, joined `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`.

Separate raw receipt scan: 123 contiguous commit blocks, exact matching proposal/commit multisets keyed trace/face/carrier/slideEnd, no duplicate trace:segment within a block, out-of-range indices or off-carrier end. 120 sphere gate blocks x 10 and three BunnyRandom blocks x 22. Zero traversed=0 and zero R-x lines. All gate records are last-segment; census 51 edgeOnly (42 non-last, 9 last), 15 faceThenEdge (9 non-last, 6 last). Counts are repeat records, not 1,266 distinct slides. Re-derived projected TSV records exactly equal durable [counts](evidence/Architecture_M6_CP3_TB141_P13_Committed_Slide_Counts_20261118.tsv) and [traversed](evidence/Architecture_M6_CP3_TB141_P13_Committed_Slide_Traversed_20261118.tsv) as multisets, 962/962 and 1266/1266. Raw proposal bytes identical. Row959 remains non-vacuous for exact ordered segment pieces, distinct carriers, terminal clip, incomplete and invalid transit rejection. No current end-to-end positive graph control.

**Publication reach, not receipt reach.** `SurfaceCellTracing.cpp:4598–4641` logs before network and graph finalization. The 20 gate rows are 380,388,393,394,396,397,644,645,648,669,686,691,693,694,698,699,700,843,844,858. Nineteen contain `EmbeddedGraphTopology.duplicateCutCrossing` (sphere traces 4/6, edge (0,2)); `build_cut_node_bindings` at EmbeddedGraphTopology.cpp:348–400 returns InvalidCutGraphBinding before build_arcs (:2958–2970). Row693 is a trace-level grazing census (FieldAlignedCurveNetworkTests.cpp:14847); its PASS is not graph publication. Row648 explicitly skips sphere graph assertions. Rows843/844 reach polyline controls; do not conflate independent polyline projection with accepted graph publication. No verified sphere slide-containing graph publication. BunnyRandom three blocks retain 17 unique edgeOnly identities (trace:segment 24:0,24:1,37:0,51:0,78:0,87:0,93:0,99:0,101:0,109:0,115:0,117:0,128:0,142:0,144:0,148:0,157:0) and five grazing identities (15:19,20:2,43:11,43:13,113:1). Three repeated non-last grazing loci 43:11 carrier (60,290), 43:13 and 15:19 carrier (94,210). The census contains two `contactCutConflict` lines: trace82, nodes220/222, terminating traces43/15. EmbeddedGraphTopology.cpp:1480–1499 returns TraceEventPositionNodeConflict inside build_arcs before that trace's arc assembly; :2967–2991 returns the error, not EmbeddedGraphTopology. SurfaceCutGraph.cpp:1011–1022 returns before certification. This proves graph build reached and graph not published for the failed construction; earlier draft arcs are not published. Do not infer every trace passed its own arc assembly. Cylinder PASS 288, Vase AggregateCompletionValidationFailure RED, neither has slides.

**R+**: affected set is exactly the listed 20 gate rows and BunnyRandom according to retained trace:segment receipt inventory, not a permission for blanket output exclusion. TB144 must require strict comparison of 939 other gate rows and Cylinder/Vase (plus any other prior rows added before TB144), and attribute every difference to a listed actual piece. Require focused positive publication control because the existing earliest failures mask graph changes. **R-edge**: 51 retained traversed edge-only records in a fixture that reaches graph build, not proof of a published edge-only graph. S3 table mentions a published graph; EPO-6 expressly bars the interim typed rejection strategy when *any fixture reaches graph build*, and S3 concluding R-edge sentence routes any traversed edge-only slide to O49 before CB169. Apply the narrower safety envelope: O49 before the coordinated cutover; do not weaken EPO-6 based on upstream failure. CB167 and CB168 remain inert and independent. If a later Review requires a specific published-graph witness to change this sequence, resolve the authority before CB169, not by silently treating BunnyRandom as not reaching graph build. **R0 false; R-x absent.**

C5/O42/O43/O46/O47/O48, H2/H4, FC-1/FC-4 and middle-piece direction witness remain open or carried. O49 required before CB169, same traversal-side contract. H3 and O45 narrow closure retained; C3/O44/C1 closed. FC-6, terminal-cut and row858 held; CB145 parked. Before CB172 require positive overlap starting at vertex rule, tie control, delete CB160/CB166 diagnostics only at authorized wiring. D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false. Stable 66/17/49, debt 1, deferred81; CP2 package 11391685901, 491/491, selector497 frozen not promoted. No new stable event.

## Recommendation — CB167 frozen, not applied

[Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Plan_20261118.md](Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Plan_20261118.md); [Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Exact.diff](Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Exact.diff), SHA-256 `9163ad66c32f0d9d3a27f95899124b135a7a8cfa210b18d455a31eacfbee651a`. Original candidate (SHA-256 `14f2abed75fd3ca479f6021a70a5af930f01cad401e6df9003d76a51be124074`) retained in Git at `890eeecf79ed3da85666791dda7228997a854dab`; now superseded. Three paths, +222/-22. Scratch-only forward/reverse applicability, clean diff, exact preimages and postimages; static check strengthens row960 with independent typed expected points, edge-only non-last departure, retained terminal clip, and strict invalid-cut controls. Old production path caller unchanged; leaf no longer calls the old path reader and new concatenation unwired. Exact patch not executed, compiled or tested. Row960 prospective PASS; prior 959 unchanged byte-for-byte; offline manifest self-check PASS (960+81). [Frozen gate](gates/Architecture_M6_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Case_Manifest.tsv) SHA-256 `2468d8baed76322bdda79072e54c287aa421fb627a819ba278c7f7ee77e12db0`. No new selectors. RA-262 controls the later sequence. O49 before CB169; keep rank fixtures 665/666 from withdrawn candidate at CB169. No CP3/D0 promotion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Four exact hashes above; 491/491. |
| Decisive claims independently re-derived | 962/962, 123 blocks and 1266 retained records; source reach and distinct publication adjudication above. Resume snapshot `dacbbd17da42ee513ec8e71b4e7f2cb397121d87`, artifact 14476243890, 5,587/5,587 file hashes; compare prior snapshot to resume head shows only documentation/control changes. |
| Non-vacuity checked | Existing row959, raw proposal/commit checks; row960 expected values independent of canonicalizer, invalid-cut, edge-only and clipping controls statically reviewed. No runtime claim. |
| Prior obligations discharged/carried | S5 and prior obligations listed above, including O49 before CB169, 665/666 rank fixtures carried; no new discharge. |
| Stable accounting | 66/17/49; debt 1; deferred81; CP2 package11391685901 491/491, selector497 not promoted. |
| New candidates/obligations recorded | O49 route and affected set in tracker; no new stable event. |
| ORIENTATION currency line | TB141-REV 2026-11-18, independent MATCH. |
| ORIENTATION §3 / §4 / §7 / §8 | Currency, evidence, milestone and priority refreshed; other unchanged sections not affected. |
| CHANGELOG | Existing TB141 Review entry amended. |
| ROADMAP | Review complete, CB167 next, CP3 not accepted. |
| Selector manifest | n/a: no new or accepted selector; prospective gate appended separately. |
| LESSONS | n/a: no new pattern; retain lesson 170 on fixed variables. |
| Consolidation under CLEAN_UP_POLICY | TB139/TB140 execution reports folded intact into D3 with original SHA-256 and index; checkpoint provenance indexed; normative reviews retained. |
| Successor frozen | `M6-CP3-CB167-P13-TRACE-PIECE-PATH-HELPER`, exact patch and plan above; conditional artifact-only TB142 criteria. |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/benchmark/build mutation on remote branch. |
| review_check.py boundary | Ran: local product and selector checks PASS; historical baseline and three durable rewrite-source checks FAIL because source snapshot omits Git history. Remote compare verifies rewrite base `8b7299b43764a6ba3444e5bc774a2f1b65e99731` ancestor (6,459 ahead, zero behind); fetched exact rewrite blobs and checked retained durable headings. Full historical script not attested; scoped alternative below. |
| STATUS lifecycle maintained | Current TB141-REV resumed 2026-11-18T22:20:58Z, original start 21:57:04Z; final beacon only after applied documentation and cleanup verification. |
| Pushed to origin, branch in sync | Connector-controlled remote-only commit and readback of branch, not local git push/status; final confirmation in response. |

Historical ledger check ran and returned missing rewrite baseline/CHANGELOG/LESSONS history in snapshot. Connector audit of commits since prior Review `5be561aaa656a3ae806c89e8d0b5e32d76029972` found CHANGELOG append-only +5/+5/+4, LESSONS unchanged. All three durable files present with historical required headings retained. Full historical scan remains unverified; synthetic snapshot Git is not history. No policy exemption or historical PASS claimed. Initial attempt direct reads before snapshot selection and comparator output-directory collision corrected (fresh directory and verified rerun); exact cross-attempt tool ledger not recoverable. This Review does not run product code.

Documentation drift audit (`--base HEAD` against exact local snapshot): zero errors; three protected-document-change warnings for authorized handoff, ORIENTATION and ROADMAP currency edits; prior handoff size warning resolved (15,213 bytes). Durable headings retained. No DESIGN or frozen policy edits; historical review edits are only relocated execution-report links.

## RA-263 — adversarial re-review of this Review (2026-11-18 UTC)

Resumed 2026-11-18T22:49:01Z. Runtime-free: three Haiku read-only audits, direct reads, `-fsyntax-only` on CB167 and the TB142 manifest self-check. Source base CB166 `3b599879a`. **MATCH, R+/R-edge, O49 before CB169 and the CB167 freeze are upheld.** The sequence after TB142 is realigned (S3).

### S1 — what holds

1. **Evidence.** In each sphere block there are 10 terminal grazing slides: traces 0,1,9,10,11,12,13,14,21,22, segment 6 of 7, `traversed=1`. Pairs share a face and converge on vertices 8, 21, 34, 45, 49 and 0, which are approaches to singular vertices. None is published: 19 of the 20 rows stop at `duplicateCutCrossing` (edge (0,2), traces 4/6) in `build_cut_node_bindings` before `build_arcs`. BunnyRandom stops inside `build_arcs` at trace 82. The Review's split between receipt reach and publication reach is correct.
2. **CB167** (`9163ad66…`, applies cleanly to HEAD). The leaf reproduces the legacy single-segment body exactly. `exact_trace_interior_point` is a pure lift of the old lambda. The new `exact_trace_piece_path_between` is unwired, and it fails closed on a cut inside any slide segment (EPO-5). All 13 row-960 expectations were checked by hand: midpoint (1/2,1/4,1/4) in (1,2,4); clipped contact (3/8,1/8,1/2) = v4 + ½(s − v4) with s = (3/4,1/4,0); edge contact (0,½,½) = finish; vertex contact → v2; departure aliases v0. The 3-piece expectation fails under the old chord algorithm. Syntax-only: EmbeddedGraphTopology.cpp 0 errors / 22 warnings, tests 0 / 42 (= base). TB142 manifest self-check passes (960+81); its first 960 lines are identical to TB140's.

### S2 — defects

1. **RA-262 S3 R0 was defined at the wrong level (my error).** "No traversed slide" is a receipt fact; H4 needs a *published* slide. Every route should have been stated at publication. The Review applied the right reading; this records the correction.
2. **The TB144 criterion is too permissive.** "Attribute every difference to a listed piece" admits changes on rows that publish no slide graph. Because no fixture publishes a slide, the cutover may change *no* outcome. Required instead: all 962 prior rows and census outcomes strictly equal, including BunnyRandom's first failure (trace 82 `TraceEventPositionNodeConflict`). A new earlier `InvalidNetworkBinding` on traces 43/15 or an edge-only trace is a stop, not an attributed difference. Positive rows may differ only after a fixture publishes slides (S3).
3. **The required "focused positive publication control" cannot be met in the current order.** Networks cannot be hand-built: `make_from_candidate` replays the producer (`SurfaceCellTracing.cpp:5433–5450`; LESSONS RA-248). No fixture reaches slide publication. CB169 would therefore land with no positive end-to-end witness, against the Review's own requirement.
4. **Trajectory: the gate-visible blocker has no owner in the sequence.** Sphere C5/O47 blocks 19 rows, and row 858's premise RED (`faceLocus.sourceFace` empty because the failure locus is edge (0,2)). Its rule is already defined: RA-259 S3.1/S3.6, the (entry, entry) carrier contact, and RA-260 S2.3–S2.5/S2.7: the later trace ends at its previous segment's end with `carrierLocus`, the earlier trace is cut at the existing boundary `{k, ∅}`, and an edge contact node is used. It needs **no slide pieces and no H4 cutover**. The current producer drops it as an `EndpointTouch` (`:2466–2486`; guard `:4397`, `:4470`). Yet RA-262 S3 queued it inside CB171/CB172, after five gate-invisible H4 turns. Fixing O47 first also turns the sphere into the slide-publishing witness that CB169 needs (S2.3).

### S3 — realigned sequence (replaces RA-262 S3 after TB142)

| Turn | Scope | Test |
|---|---|---|
| CB167 (frozen, unchanged) | leaf + unwired piece path | TB142 (row 960) |
| EC1 | `FieldAlignedTerminalContact::carrierLocus` (inert, digest only when present) + producer receipt counting (entry, entry) equal-parameter coincidences per fixture (interior parameters only; RA-259 S3.3) | TB: counts gate-wide; every sphere row has the 4/6 locus; any other fixture is listed |
| EC2 | Graph edge contact node (RA-260 S2.5) as a pure helper + wired consumer; inert (no producer sets `carrierLocus`) | TB: strict equality |
| EC3 | Producer switch, (entry, entry) only, via `first_field_aligned_carrier_contact` restricted to `movingInSlide=false, wallInSlide=false`; slides are not considered | TB: sphere rows predicted to leave `duplicateCutCrossing`; next site measured; 858 premise change predicted |
| CB168 → [O49] → CB169 → CB170 | RA-262 S2 EPO contract unchanged; CB169's positive witness is a sphere row that publishes the terminal slides | TBs per S2.2 |
| CB171 → CB172 | slide piece positions → slide-interval contact (O48), after the vertex-overlap rule and tie control; deletes the CB160/CB166 receipts | TBs |

TB142-REV freezes EC1 as an exact diff. If EC1's census finds (entry, entry) coincidences outside the sphere, EC3 lists their predicted outcomes before freezing.

### S4 — closeout

Accepted prefix 491/491 and stable 66/17/49, debt 1, deferred 81 are unchanged. No promotion. Carried: C5/O42/O43/O46/O47/O48, H2/H4, FC-1/FC-4, O49. FC-6 and terminal-cut held; the row-858 fix is held until EC3. CB145 parked. D11=A, D12=A, D10 deferred, D6 pending. Successor unchanged: `M6-CP3-CB167-P13-TRACE-PIECE-PATH-HELPER`.
