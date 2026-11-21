# TB153 real-piece reach and row 686 oracle full-gate independent review — 2026-11-21 UTC

## Situation

**TB153 PASS is upheld and was re-derived independently; no product promotion.** A second agent wrote fresh comparison scripts, did not reuse the execution stage's comparator, and reached the same result. Row 968 shows every sphere trace's real pieces are reachable (0 rejected, 0 path failures, 0 binding failures), so the switch's precondition holds. Row 686's sphere record changed in the way the real-piece oracle predicts and is attributed below. The next Code + Build lands the unwired piece-ray helpers (CB169); the producer switch is a later Review-frozen turn.

## Background — exact authority

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open/unmerged.
- Semantic source `203150dffb9e98b707ec4dd28835dbb148835338` (CB168Q, test-only on CB168R). Compiled artifact `14692425922`, ZIP SHA-256 `fccfe7103494854c1c7bbcc761fb2e3aaa0d119bc5d044ffa52bcf672307f5a0`, `runtimeExecution=false`.
- TB153 run `44867242174`, result artifact `14692372657`, ZIP SHA-256 `5e102074ae1bbfcf9c1a94a928e8d354725b484c67fa7dc53410d887a12f8147`. Reference TB152 artifact `14630642490`, ZIP SHA-256 `5bfce8410e736c1fce63c4c6fa9b272b20ff91ceac8044bb339c814bfaa3cd04`.

## Assessment — independent results

- ZIP `5e102074…f8147` matches the GitHub digest; internal `SHA256SUMS` **1944/1944**.
- **968/968 PASS**, membership **1049** (968 + 81 deferred); compile, configure, relink and benchmark all false.
- **966/966** rows (1–967 except 686) MATCH TB152 under N1–N3; **706** raw logs byte-identical; **1,742** M3 records.
- Row 686: the two-ring and torus records are byte-equal to TB152; the only differing line is the sphere record.
- CP2 **491/491** remains accepted.

**Arrival-count reconciliation.** The re-derivation counted **528** `slideContactArrival` lines in all of TB153 against **504** in TB152. Rows 1–967 all match and row 686 differs only in its sphere record line, so the 24 extra lines are row 968's own output (it runs the sphere producer). The execution report's **492** is rows 1–967 minus row 686. Arithmetic: 528 = 504 + 24. This is a difference of denominators, not an unreproduced result.

**Row 968, verbatim:**

```
SphereRealPieceReach traces=24 segments=182 slideSegments=10 face=172 faceThenEdge=10 edgeOnly=0 rejected=0 pathFailures=0 bindingFailures=0
```

Ten `SphereRealPieceSegment` lines for traces 0, 1, 9, 10, 11, 12, 13, 14, 21 and 22, each `segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1`, at segment 6.

## S1 — slide topology (row 963 `committedSlide` lines)

Every slide is the last segment (6 of 7) and ends at a mesh vertex. The walls come in pairs: each pair converges on one vertex along the two edges of one face that meet there.

| Face | Carriers | Shared end vertex |
|---|---|---|
| (6,8,9) | traces 0 (6,8) and 9 (8,9) | 8 |
| (16,20,21) | 1 (16,21) and 11 (20,21) | 21 |
| (32,33,34) | 13 (32,34) and 21 (33,34) | 34 |
| (40,45,46) | 12 (40,45) and 22 (45,46) | 45 |

Two slides are single: trace 10 on (49,62) ending at 49, and trace 14 on (0,69) ending at 0. The four moving entries (row 963 `SphereEntryOnSlidingWall`) are `moving=17:8 wall=0:6 carrier=(6,8)`, `20:8 / 1:6 (16,21)`, `5:8 / 21:6 (33,34)` and `8:8 / 22:6 (45,46)`. All have sameFace=1, strictlyInside=1 and `movingArrival=later`.

## S2 — row 686 attribution

CB168Q's real-piece oracle reads the 10 slide segments as real pieces.

- The four wall faces (6,8,9), (16,20,21), (32,33,34) and (40,45,46) each lose one fragment (376 to 372). They are exactly the faces of the four same-face moving-entry-on-sliding-wall contacts. Under the chord, the moving trace's in-face path crossed the wall's chord, a spurious crossing. Under real pieces the moving entry touches the wall's edge piece instead.
- The loss falls in the two 18-fragment components. Orbit 7 to 8 loses (6,8,9) and (32,33,34); orbit 10 to 11 loses (16,20,21) and (40,45,46). Both become 16-fragment components, V23/E40 to V21/E36, with orbit labels renumbered.
- Ten components gain V/E at the same fragment count (V/E +1 in 0, 3, 6, 12; +2 in 1, 4, 5, 9, 13, 15). That is the slide intervals being written into both incident faces' boundaries, by CB168Q's design.
- All 18 components keep `boundaryCyclesValid=true` and chi=1.
- The sphere scalars are unchanged (V18/E30/F18, chi 6 vs 2, `CutSearchExhaustedBeforeCellularity`), because the oracle's global counts come from the producer graph. That graph still has chord arcs and still lacks the four contact nodes. The +4 attribution (RA-268/RA-269) stands. The repair still needs the producer switch and then the stop switch.

## S3 — decision: the switch's shape

Row 968 has rejected = pathFailures = bindingFailures = 0. Per RA-276 the next step is the unwired piece-ray helpers, then the switch.

Code reading found that `trace_ray_face` and `vertex_trace_ray_second_point` are not in the header, and that `vertex_trace_ray_second_point` never reads `edgeTransitEntry`. Under EPO-4 a Forward ray reads the first piece's end and a Reverse ray the last piece's start.

A drafter pushback, accepted by the Review, decided scope. With no cut edges, `build_node_loci` gives a mesh vertex a vertex locus only at singularity ports and mandatory-edge endpoints; any other vertex event gets the event's edge locus. So the sphere's slide ends at vertices 8, 21, 34, 45, 49 and 0 may be edge-locus nodes. The helpers must therefore cover both locus kinds. This is unconfirmed; the receipt's `SpherePieceRaySlideEnd` lines will settle it.

CB169 adds, unwired:

- `exact_trace_arc_ray_piece`: the oriented first or last piece of the arc's real piece path (EPO-2, one decomposition);
- `exact_source_point_barycentric`: an `ExactSourcePoint` in oriented face order;
- `vertex_piece_ray`: along-edge, or in-wedge with the exact `vertex_locus_secondary_parameter` formula;
- `edge_piece_ray`: along the locus edge with direction, or into the face with the far end.

It moves three blocks without changing behaviour, so that old and new share one implementation: the edge-parameter lambda of `edge_piece_face_side` to `exact_edge_parameter`; the terminal-contact remap to `source_face_point_barycentric`; the wedge formula to `vertex_wedge_parameter`.

It has three tests (rows 969–971): two hand-built tests with exact expected values and a sphere receipt over the real graph (`build_cut_node_bindings`, `build_arcs`, `build_node_loci` with no cut edges). Key expected values in test 969: at vertex 4 of face [3,0,4], the slide start at 1/3 along (0,3) gives 2/3, while the chord gives 0. Test 970: Reverse at the slide end, locus (3,4), gives along-locus toward the second endpoint, while the legacy rank names the incoming carrier, 2·((1+3−2) mod 3) = 4.

Patch facts: `-fsyntax-only` (clang, project include and GMP defines) gives 0 errors; warnings and text are identical to HEAD in `EmbeddedGraphTopology.cpp` (22), `GlobalTopologyPlan.cpp` (24), `SurfaceCutGraph.cpp` (27) and the tests file (42).

**Predictions** (falsifiable; TB154-REV checks them against row 971):

- every slide arc end classifies along its `outgoingCarrier`;
- `coincidentAlongEdge=0`, because each wall pair arrives on two different edges;
- at the four convergence vertices the rotation is combinatorially unchanged, because both wall rays stay at the boundary of the same wedge;
- `changedOrdinary` is reported, not asserted. The drafter found a legitimate representational difference: the old Forward reader falls through to the terminal when the next entry is a vertex given on an edge outside the face. The switch Review decides on it.

## S3b — decision: the walls' `terminalBarrier`

- All four walls have `terminalBarrier=0` on their last segment, so `is_terminal_slit` holds (`GlobalTopologyPlan.cpp:338`).
- The readers decide the skip per arc, by whether the arc's two dart sides share one orbit: `GlobalTopologyPlan.cpp:520` (corner incidence), `:1270` (fragment orbits), and `SurfaceCutGraph.cpp:450` and `:543` in the certifier.
- After the stop switch, each wall's segment 6 is split at the moving contact. The contact is strictly inside the slide and the moving trace arrives later, so the wall continues to its vertex. The split gives a real face chord (entry to contact) and an edge-only suffix (contact to vertex).
- The suffix is skipped only if it is non-separating. A separating suffix would be counted as a face chord, and the k+1 check (`GlobalTopologyPlan.cpp:1421–1428`) fails closed.
- Decision: arc-piece ownership is needed only if a suffix separates. That is measured at the stop-switch TB by checking each suffix's forward and reverse orbits. It is held until then. O49 stays held.

## S4 — realignment (exact)

| Order | Turn | Exact content |
|---|---|---|
| NEXT | `M6-CP3-CB169-P13-TRACE-PIECE-RAY-HELPERS` (Code + Build, compile only) | [Diff](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Exact.diff) SHA-256 `dd08cd28094c371a6eb63ae6b5c4161f3d94376a023e4fa71288558048966b45`, numstat EGT.cpp 173/54, EGT.h 123/0, tests 806/0. Precheck `git diff --quiet 203150dff HEAD -- src include tests`, the three preimages, and `git apply --check`. Compile the eight RA-245 targets with `runtimeExecution=false`. |
| Then | `M6-CP3-TB154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE-EXEC` | [Manifest](gates/Architecture_M6_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Case_Manifest.tsv) SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305` (TB153 byte prefix plus rows 969–971; 971 + 81 = 1052), plus a census reproducing TB151's (3 fixtures, N1–N4 vs TB151). CB169 changes product source, although only by behaviour-preserving moves, so the census is required. |
| Then | `M6-CP3-TB154-…-FULL-GATE-REV` | Checks the predictions and freezes the producer switch CB: `build_arcs` onto `exact_trace_piece_path_between` with counts; rays and ranks mapped from the piece-ray helpers (EPO-4: along-edge rays use the edge-supported comparator; no new tie-break); counts into `candidate_semantic_digest`. Before freezing it runs the RA-274 S5 checks, including grepping the accepted chord-pinning tests (tests 3611–3669, 12970–13030, 13130), which must be addressed explicitly. |

**TB154 STOP rules (all must hold):**

- rows 969–971 PASS, with row 971's `SpherePieceRayReceipt`, `SpherePieceRaySlideEnd` and `SpherePieceRay` lines reported verbatim;
- rows 1–968 MATCH TB153 under N1–N3, row 686 included;
- census 3/3 MATCH TB151 under N1–N4;
- CP2 491/491.

**Census recipe** (TB151 run `44719007530`, result artifact `14621727104`, ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`; request `m6-cp3-tb151-census-20261120-v1`): census manifest `gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` (SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; 3 OBSERVE cases: `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/{Cylinder,BunnyRandom,Vase}`); harness `tools/m6_cp3_targeted_artifact_harness.sh` (SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`). Expected: Cylinder PASS, BunnyRandom and Vase RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. N4 removes only the four process-varying `GetParam()` 16-byte address contents (two per RED test). The baseline for TB154 is TB151's census artifact above (TB152 and TB153 ran no census, because their product source was unchanged).

**Prospective after that:** switch, then TB, then stop-switch CB (with the suffix-separation receipt), then TB (row 686 chi=2, rows 669/698), then CB170, CB171, CB172 (O48).

**Held/parked unchanged:** O49, FC-6, TERMINAL-CUT-OUTCOME, row 858 DEFN; CB145 parked; D11=A, D12=A.

## S5 — lessons

1. Before scoping a ray helper to one locus kind, read how the node builder places nodes. Here `build_node_loci` gives non-port mesh vertices an edge locus.
2. Reconcile a count discrepancy arithmetically from the match result before calling it unreproduced (528 = 504 + 24 from the new row).

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB152 manifest `cab375d0…` is a byte prefix of TB153 `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116`, and TB153 of TB154 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305` (checked with `cmp` on the leading bytes, plus rows 968–971). CP2 491/491 accepted; selector497 not promoted. |
| Decisive claims independently re-derived | By a second agent with fresh scripts: ZIP and SHA256SUMS 1944/1944; 968/968 PASS and membership 1049; 966/966 MATCH under N1–N3 with 706 byte-identical and 1,742 M3 records; row 686 two-ring and torus byte-equal; 528 = 504 + 24 arrival lines; row 968 lines; S1 slide table and S2 attribution from rows 963 and 686. Patch SHA, numstat, preimages and postimages verified here (postimages in a removed scratch worktree). |
| Non-vacuity checked | Row 968 asserts at least 4 slide segments and its zero counts cover 182 real segments, so a receipt that reached nothing would fail. CB169's hand-built tests carry exact values that separate the piece ray from the chord ray (2/3 vs 0; along-locus vs incoming-carrier rank 4). The sphere receipt is non-gating, so its predictions are stated before the run. |
| Prior obligations discharged/carried | Discharged: RA-276 TB153 STOP rules and the row 968 reach decision (switch precondition holds). Carried: RA-274 S5 (accepted chord-pinning tests, conformity readers) to the TB154-REV switch freeze; RA-275 S4 across-face side of a faceThenEdge slide; disc-phase-front admission of all-edge-only arcs at the switch; `EdgeOnly` validator names if O49 lands; O49 held pending the suffix-separation measurement at the stop-switch TB. |
| Stable accounting | 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred; CP2 491/491; selector unchanged. |
| New candidates/obligations recorded | No new stable event or candidate. Tracker entry for this Review added. |
| ORIENTATION currency line | TB153 Review, 2026-11-21 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 currency and next-turn pointer updated; §4 n/a: no witness state changed; §7 priority updated; §8 n/a: the patterns went to LESSONS. |
| CHANGELOG | Independent review entry added. |
| ROADMAP | CP3 next-turn pointer updated. |
| Selector manifest | n/a: no acceptance and no identity change in a Review. The TB154 case manifest is a gate manifest, frozen for the TB. |
| LESSONS | Two entries added (S5). |
| Consolidation under CLEAN_UP_POLICY | n/a: no newly superseded standalone Review artifact eligible for safe folding. |
| Successor frozen | Exactly one: `M6-CP3-CB169-P13-TRACE-PIECE-RAY-HELPERS`. Its precheck, hashes and scope are in S4 and the handoff; the TB154 and TB154-REV turns are later frozen edges, not concurrent. |
| Turn boundary held | Runtime-free. The diff was verified in a removed scratch worktree; no product, test, selector or fixture source changed in the tree. |
| review_check.py boundary | ALL CHECKS PASSED. |
| `STATUS` lifecycle maintained | IN_PROGRESS entry beacon, then COMPLETE final beacon with successor CB169, Started at `2026-11-21T04:58:32Z`, Resumed at empty, true UTC Ended at. |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the final push (no ahead/behind). |
