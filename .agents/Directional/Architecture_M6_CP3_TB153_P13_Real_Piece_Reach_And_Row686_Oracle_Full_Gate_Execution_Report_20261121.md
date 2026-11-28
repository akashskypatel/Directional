# TB153 — real-piece reach and row 686 oracle full gate (2026-11-21 UTC)

## Situation

**PASS.** The immutable CB168Q package executed the TB153 gate: **968/968 PASS**. Rows 1–967 except row 686 (966 identities) match TB152 under frozen N1–N3. Row 968 PASSes with every sphere trace's real pieces reachable: 182 segments, 0 rejected, 0 path failures, 0 binding failures. Row 686's two-ring and torus records equal TB152; its sphere record changed and is reported as a finding. CP2 remains **491/491 PASS**. This is not a production repair or acceptance promotion.

## Background — source and executable authority

| Item | Evidence |
|---|---|
| Branch | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 open, draft) |
| Semantic source | `203150dffb9e98b707ec4dd28835dbb148835338` (CB168Q; test-only on top of CB168R `7061c8b84`) |
| Compiled immutable package | Artifact `14692425922`, ZIP SHA-256 `fccfe7103494854c1c7bbcc761fb2e3aaa0d119bc5d044ffa52bcf672307f5a0`; compile run `44866324323`, GMP/GMPXX, `runtimeExecution=false` |
| Manifest | `gates/Architecture_M6_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Case_Manifest.tsv`, SHA-256 `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116` (TB152 byte prefix plus row 968), 968 required + 81 deferred |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Dispatch | Request `m6-cp3-tb153-full-gate-20261121-v1` at commit `3a0bbed95b2c25b2d87b5d6aca492bad5bf62f47`, request SHA-256 `0e0a2916dd247ea8f131d0c2cfce646fa20acc93bb132a9f111d4241bd80a992`; mailbox key `m6-cp3-tb153-full-gate` (reported 2026-11-21T04:52:22Z) |
| Executed gate | [run 44867242174](https://github.com/akashskypatel/Directional/actions/runs/44867242174); runtime job succeeded, compile/drive_apply/noop skipped |
| Result artifact | `14692372657` (`m6-cp3-tb153-gate-result-44867242174`), ZIP SHA-256 `5e102074ae1bbfcf9c1a94a928e8d354725b484c67fa7dc53410d887a12f8147` |
| Diagnostic log artifact | `14691849432`, ZIP SHA-256 `1f22395eeba2737860ce3eb376874ec76386bfca31e09b40476ae78b6e14ed1c` |
| Frozen TB152 baseline | [run 44739657527](https://github.com/akashskypatel/Directional/actions/runs/44739657527), result `14630642490`, ZIP SHA-256 `5bfce8410e736c1fce63c4c6fa9b272b20ff91ceac8044bb339c814bfaa3cd04` |
| Authority | [RA-276 S3](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md#s3--realignment-exact--fsyntax-only-0-errors-warnings-42--head-stacked-git-apply---check-on-546243920) ("TB153 STOP rules") |

## Assessment — independent archive comparison

ZIP SHA-256s were computed locally and equal GitHub's digests. Internal `SHA256SUMS`: **1,944/1,944** valid (TB152: 1,942/1,942). All 968 raw log hashes match the ledger. `execution-boundary.json`: `planned=executed=passed=968`; `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `membership=1049`, `postflight=true`, `exit=0`, `compile=configure=relink=benchmark=false`.

| STOP rule | Observed | Holds |
|---|---|---|
| Row 968 PASS with an independent successful Google Test record, lines verbatim | ledger PASS, exit 0; `[       OK ]` and `[  PASSED  ] 1 test.` in `raw/968.log`; lines below | yes |
| Rows 1–967 except 686 MATCH TB152 under N1–N3, receipts raw | 966 compared, MATCH 966 / MISMATCH 0 / MISSING 0; no row-number differences; ledger metadata matches; 706 raw logs byte-identical before normalization; 1,742 M3 `region_support_projection` records (multiset); 492 `slideContactArrival` records unmasked and ordered, no row differing | yes |
| Row 686 two-ring and torus whole records equal TB152 | two-ring 1,796 chars equal; torus 9,267 chars equal (334 interleaved pieces reassembled) | yes |
| Row 686 sphere `oracleAvailable` true, every `boundaryCyclesValid=true` | no `oracleAvailable` text in `raw/686.log`; 18 components, all `boundaryCyclesValid=true` | yes |
| CP2 491/491 | rows 1–491 all PASS; all 968 rows PASS | yes |

Source boundary: `git diff 1df6a09ad 203150dff -- src include` is empty. The only code-bearing change is `tests/FieldAlignedCurveNetworkTests.cpp` (CB168R and CB168Q), so no census was required (RA-242).

## Row 968 — verbatim

Test `TraceTerminationCorrection.PrescribedSphereRealTracePieceReachIsPublishedNonGating`, 9,060 ms.

```
SphereRealPieceReach traces=24 segments=182 slideSegments=10 face=172 faceThenEdge=10 edgeOnly=0 rejected=0 pathFailures=0 bindingFailures=0
SphereRealPieceSegment trace=0:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=1:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=9:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=10:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=11:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=12:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=13:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=14:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=21:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
SphereRealPieceSegment trace=22:6 segments=7 kind=faceThenEdge slides=1 terminalBarrier=0 terminalContact=0 terminalPoint=1
```

There are no `SphereRealPiecePathFailure` and no `SphereRealPieceBindingFailure` lines.

**Trace mapping.** The 10 slides are traces 0, 1, 9, 10, 11, 12, 13, 14, 21 and 22, each at segment 6 of 7 (the last segment). They equal the ten `FieldAlignedCurveNetwork.committedSlide` records in row 963 (`kind=faceThenEdge`, `traversed=1`, segment 6 of 7).
- The four row 963 walls are traces 0, 1, 21 and 22 (`wall=0:6`, `1:6`, `21:6`, `22:6`). Each has `terminalBarrier=0`, `terminalContact=0`, `terminalPoint=1`. The slide is on the last segment (6 of 7) and no terminal barrier is recorded.
- The other six slides (traces 9, 10, 11, 12, 13, 14) also have `terminalBarrier=0`.
- The four moving traces (17, 20, 5 and 8, segment 8 of 9 in row 963) are not slide segments; they are among the 172 face segments.

## Row 686 comparison

- **Two-ring and torus:** whole records equal TB152.
- **`oracleAvailable` inference confirmed.** In CB168Q (diff and `tests/FieldAlignedCurveNetworkTests.cpp` at `203150dff`, lines 15049 and 15063) the fail-closed path prints `...;complex=actualEmbeddedGraph;oracleAvailable=false;...`, once for a fixture error and once when `cp4c_independent_actual_embedded_graph_oracle(..., true)` returns nullopt (any real-piece reconstruction mismatch returns `std::nullopt`). The pass path prints no `oracleAvailable` field, and `raw/686.log` contains zero occurrences. The sphere oracle therefore did not fail closed.
- **N1–N3 diff of the whole row.** Of 389 lines (same count in both), exactly one differs: the `prescribed-sphere` record (19,556 chars in TB153, 19,747 in TB152). No other line in the row differs. The change is what CB168Q intends: only segments with an edge-transit slide are read as real pieces (face piece to slide start, slide on the carrier, split of both incident faces), so witnesses without slides are unchanged.

**Sphere record, top-level fields (TB153; every one equal to TB152):** `V=18;E=30;totalOrbits=18;excludedBoundaryOrbits=0;F=18;c=1;s=1;correction=0;chi=6;sourceChi=2;cutCrossingNodes=0;cutCrossingArcs=0;traceEndpointsAttached=true;noDegreeZeroNodes=true;producerComplex=unavailable;producerStatus=error;producerError=CutSearchExhaustedBeforeCellularity`, with `witness=prescribed-sphere;complex=actualEmbeddedGraph;oracleKind=independent-face-planar-rotation-seam-orbit;surfaceCutGraphCallsInsideOracle=0`. The χ6 residual (+4 over sourceChi 2) is unchanged.

**Sphere record, components (TB153), `fragments/V/E`, all `boundaryWalks=1,chi=1,boundaryCyclesValid=true`:** [0] 46/48/93, [1] 14/32/45, [2] 32/40/71, [3] 16/21/36, [4] 46/47/92, [5] 14/32/45, [6] 46/48/93, [7] 1/3/3, [8] 16/21/36, [9] 53/50/102, [10] 1/3/3, [11] 16/21/36, [12] 9/18/26, [13] 14/31/44, [14] 32/40/71, [15] 14/33/46, [16] 1/3/3, [17] 1/3/3. The record also lists 372 `fragment[i]={face=…,local=…,orbit=…}` entries (full text in the result artifact, `raw/686.log`).

**Field diff against TB152 (finding, not a STOP):**
- Equal: all 22 top-level scalar fields above, and the component count (18).
- `fragment[]` count 376 → **372** (−4). Component totals: fragments 376 → 372, V 482 → 494 (+12), E 840 → 848 (+8).
- Components whose `V`/`E` changed (TB152 → TB153): [0] 47/92 → 48/93; [1] 30/43 → 32/45; [3] 20/35 → 21/36; [4] 45/90 → 47/92; [5] 30/43 → 32/45; [6] 47/92 → 48/93; [9] 48/100 → 50/102; [12] 17/25 → 18/26; [13] 29/42 → 31/44; [15] 31/44 → 33/46. Components [2] and [14] are unchanged. TB152's two 18-fragment components (V23/E40, at [7] and [10]) become 16-fragment components (V21/E36, at [8] and [11]) in TB153, so each loses two fragments, and the 1/3/3 components shift position accordingly.
- Fragment set: four faces carried by the walls' slide, `(6,8,9)`, `(16,20,21)`, `(32,33,34)` and `(40,45,46)`, have a TB152 fragment and no TB153 fragment. The other fragments keep their face triples. Their orbit labels move by one (orbit 7 → 8 and 10 → 11 for the slide-adjacent fans).
- This is consistent with reading the four wall slides as pieces on the carrier rather than as face chords (each of the two merged-wall components loses the two wall-face fragments). The oracle's χ stays 6, so the +4 is not removed by the oracle alone. Attribution is for the Review.

## Regression classification and recommendation

**No new stable event or candidate is supported.** All accepted and previously selected cases remain PASS, every compared earlier raw log matches, and row 968 is a new non-gating receipt. The sphere record change is an expected consequence of the test-only oracle change, not a regression. Carry the open O47/C5/O49/H4, the sphere row 686 χ6 versus source χ2 (+4), and rows 669/698 `CutSearchExhaustedBeforeCellularity`. Stable accounting stays **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. CP2 **491/491** remains accepted; CP3, selector497, D0, H4 and row 686 are not promoted.

**Verdict: PASS (every STOP rule holds).**

**Next canonical turn only:** `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-REV`, a Review turn owned by the Review agent. It must independently re-open this immutable archive and then:
1. attribute the row 686 sphere record;
2. since rejected = path failures = binding failures = 0, freeze an unwired piece-based ray helper with a test, then the switch CB (the producer-rule fix is not first);
3. decide from the four walls' `terminalBarrier=0` (slide on the last segment) whether the stop switch needs arc-piece ownership in all three readers.

Do not implement any of this in TB153.
