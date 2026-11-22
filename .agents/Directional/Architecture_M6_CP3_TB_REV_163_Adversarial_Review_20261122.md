# TB-REV-163 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-163-P13-STAGED-UNCUT-OWNER-CENSUS-RECEIPT-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_163_Staged_Uncut_Owner_Census_Receipt_Independent_Review_20261122.md). Runtime-free: source reading, the [TB163 raw receipt](evidence/Architecture_M6_CP3_TB163_P13_Staged_Uncut_Owner_Census_Receipt_Raw_20261122.txt), Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB163 PASS and the typed STOP against the frozen TB-REV-162 map are upheld.** The map itself was wrong: my R-a row predicted `sideOwner=0`, but the edge-side record exists and is over-full (Y1).
- **REV163-O1 is resolved by realignment, not by choosing an orbit.** The component orbit is proved unique from published data (Y3), and the defect is located at one writer (Y4). No owner switch is authorised yet. Two exact, narrow CBs land a pure nearest-chord rule and publish it per boundary half-edge without changing seeds. TB-EXEC-164 measures it, and TB-REV-164 freezes the seed switch only if every prediction holds.

## Findings

**Y1 — correction of my own TB-REV-162 decision map.**
- R-a required `sideOwner=0`, assuming no edge-side owner was recorded across the component boundary.
- In fact site C (`SurfaceCutGraph.cpp:607–621`) records one, but too many. The independent review rightly refused to read `sideOwner=1` (non-empty) as "unique".
- Lesson: before predicting a census flag, read whether the writer can over-record as well as under-record.

**Y2 — H5 is excluded as the cause for components 1 and 5.**
- The census counts every trace arc whose `sourceFaces` meet the component, whatever its trace-cut or terminal-slit classification (`:762–769`).
- Both components report `interiorArcs=0` and `vertexTransits=0`, so no trace, terminal or otherwise, touches them.
- H5 (X4) stays an independent lead for other faces. It cannot explain these 16.

**Y3 — the separation proof (REV163-O1 part b), from TB163 data alone.**
- (i) A component no trace touches lies inside one face orbit.
- (ii) Each boundary edge has `barrier=0`, and by Y2 no arc crosses it into the component. So no chord of the opposite face uses it as a carrier, and the edge lies in one region of that face.
- (iii) That region's orbit is among the opposite face's listed orbits (site B lists both sides of every chord).
- Hence the component orbit lies in the intersection over its boundary edges of the opposite faces' orbit sets:
  - component 1: {0,1,6} ∩ {0,3,6} ∩ {6,7,8} ∩ {6,7,9} = **{6}**;
  - component 5: {1,11,12} ∩ {3,11,12} ∩ {8,12,13} ∩ {9,12,13} = **{12}**.
- Every opposite face carries exactly two chords that share one middle orbit (0, 7, 11 or 13). The proved orbit is always an outer orbit, never the middle one, which matches nested chords that both cross the two non-boundary edges.
- Two admissible orbits would have meant a typed stop. They do not occur.

**Y4 — root cause: site C over-records the third-edge side for nested chords.**
- For each chord crossing a face from carrier to carrier, site C writes the chord's side facing the third edge into `directOwnersByEdgeSide[{face, third edge}]`. The side comes from the oriented `turn` rule.
- Every chord that avoids the third edge separates the apex from it, so with k≥2 chords they are nested. Only the outermost chord bounds the third edge's region; each inner chord writes the middle orbit beyond it.
- So the set is {middle, true orbit}, never a singleton, and the seed at `:736–756` never fires.
- This is an over-recording rule, a third alternative to the independent review's "missing rule versus classification" dichotomy. The oriented side (`turn`) is already source-backed and stays unchanged; what is missing is the nesting selection.

**Y5 — why the product rule is the local nearest chord, not the intersection.**
- The intersection is non-local, depends on (i), and cannot decide a component whose edges all face the same chord pair.
- The nearest-chord rule decides each edge exactly from source-attached carrier points (`FieldBoundaryPoint.parameter`, an exact rational). It returns every orbit, so the ambiguity stays typed, on a missing crossing, a tie, or disagreeing carrier orders (chords meeting inside the face).
- Y3 stays the independent oracle for its predictions.

**Y6 — scope argument for the later seed switch (CB-183).**
- The selection is always a subset of the current set, and a singleton set is returned unchanged. So the switch can only change edges that do not seed today.
- A new seed that contradicts an existing one would produce `Conflicting` and falsify the rule visibly; it is never silently accepted.
- Premise rows to recheck in TB-REV-164:
  - `UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence` (mechanical, prints owner counts);
  - `UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure`;
  - `CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`;
  - row 979, which asserts only the production cut failure, staged embedded cellularity and χ2, not the plan outcome.

**Y7 — residual risk, recorded and not fixed.** Site D (vertex entry, `:624–647`) can over-record the same way for several chords leaving one vertex (a fan). It is not exercised by components 1 and 5. A fan needs an angular order, not a carrier order. It is carried to TB-REV-164.

All TB-REV-162 X1–X6 (X2 stays withdrawn; X4 is an open lead), TB-REV-161 W6–W8 and TB-REV-160 V3–V11 obligations are carried.

## Frozen artifacts

| Artifact | SHA-256 | Notes |
|---|---|---|
| `Architecture_M6_CP3_CB181_P13_Third_Edge_Side_Owner_Helper_Exact.diff` | `624492b23b225776cb3cfaeeb6615ba91a34e523184ac6ae15529a0fec8451bc` | New pure header `src/geometry/ThirdEdgeSideOwner.h` (`carrier_apex_distance`, `ThirdEdgeChordCandidate`, `third_edge_side_owner`), unwired. Tests: three `SurfaceCutGraph.*` cases with positive and negative coverage; returning the union would fail the first test. Test preimage = CB-180 postimage `fedadbd3…ef1` → `6f0b6fbb413f3951c145d497b537ef669a7b353dadfa400efcde051cf83bed6f`; header `7a055f24fb7cdea0013b4f77692ef6c8f52fa89a276512baefae1e8b5cbefb02`. |
| `Architecture_M6_CP3_CB182_P13_Third_Edge_Side_Owner_Census_Exact.diff` | `094f663a4dd706e35f873e590861059f6c1d3ad5c05ffa8ca66dba0404ef8592` | Stacked on CB-181. It adds census-only fields `sideOwnerOrbits`, `thirdEdgeChordOrbits` and `thirdEdgeChordSideOwner` to `SurfaceCutGraphUncutComponentBoundaryEdgeCensus`. Site C collects carrier-placed chord candidates, while `add_owner` and the seeds stay unchanged. Row 979 prints one `SphereStagedUncutSideOwner` line per boundary edge. Postimages: test `f70a9f8cf4d96e0a7b9a33ba5cef0aab213d5bf70d365b5b09202e72db63383c`, `SurfaceCutGraph.cpp` `1fb1ae213dbdfd090308e7311193ee61986aab5bac7e0da1e5c34d24723cf1a5` (from `a57c2477…f1eb`), header `07ceeb176f240115e42807ac094c7bbe76f66c6afcbae356b500aa692429c927` (from `7362e5ac…68e1b4`). |
| `gates/Architecture_M6_TB164_P13_Third_Edge_Side_Owner_Census_Full_Gate_Case_Manifest.tsv` | `ed615c22e85cbdfa61bb304370ddde51aa68038b04b7139e73066f1e8dae517b` | 982 rows. Rows 1–979 are byte-equal to TB161 `e15d616c…7e8a`; rows 980–982 are the CB-181 tests. Census manifest unchanged (`3af1dc0d…e793`). |

Checks: CB-181 is 8,782 B, +160/−0; CB-182 is 6,410 B, +73/−1. Both apply in stack on `b034ccd01` (`git apply --check`), and the postimages were recomputed. `-fsyntax-only` (clang 23, GMP defines) gives 0 errors in both TUs at each state, and the warning sets are identical to HEAD. A `-Wmissing-field-initializers` warning in the first CB-182 draft was removed before freezing.

## TB164 rules (STOP unless all hold)

1. 982/982 PASS; CP2 491/491.
2. Rows 1–978 equal TB163 artifact `14750681733` under N1–N3, with a zero allowance.
3. Row 979 equals TB163 row 979 under N1–N3 after deleting only `SphereStagedUncutSideOwner` lines. All 108 TB163 `SphereStaged*` lines reappear verbatim.
4. Census runs, because product source changed: 3/3 equal TB161 census `14741883606` under N1–N4 with zero allowance (Cylinder PASS, BunnyRandom and Vase RED unchanged).
5. Publish all 16 new lines verbatim. Decisive predictions (from Y3, not from the helper):
   - component 1: `sideOrbits` = `0,6` on edges 2-5, 2-10, 5-7 and 10-15, and `6,7` on 7-13, 13-18, 15-17 and 17-18;
   - component 5: `11,12` on 27-29, 27-36, 29-31 and 36-41, and `12,13` on 31-38, 38-43, 41-42 and 42-43;
   - every line has two `chordOrbits` equal to `sideOrbits` as a set, and `nearest=6` (component 1) or `nearest=12` (component 5).
6. Any failure means STATUS BLOCKED and a return to Review. Do not edit tests, the manifest or the predictions.

## TB-REV-164 decision map

| Signature | Decision |
|---|---|
| All 16 match rule 5 | Freeze CB-183: the seed reads `third_edge_side_owner` for site-C keys. Predict components 1 and 5 `Established` {6}/{12} and staged `sourceFaceCellularity=1`. Recheck the Y6 premise rows and Y7 first. |
| Any `nearest=-` | The carrier order is undecided at that edge. Freeze a receipt of its candidates' distances; no switch. |
| Any `nearest` ≠ 6/12, or `sideOrbits` ≠ prediction | The nesting model is falsified: typed STOP and reopen X4/H5 with that edge. |

## Turn sequence

1. CB-181: pure helper and tests, compile only.
2. CB-182: census-only wiring and row 979 print, compile only.
3. TB-EXEC-164: 982 rows plus the 3-case census.
4. TB-REV-164: freezes CB-183, the seed switch.
5. CB-183.
6. TB-EXEC/REV-165: staged plan `built`, or the next measured stage.
7. CB-184: activation (V3/V4/V5/V10/V11).
8. TB-EXEC/REV-166.
9. CB-185: V3b.
10. R1, then RA-275 S4a, then O48.

## Lessons

- A presence flag cannot separate "missing" from "over-full". Publish the set itself before freezing a branch on it.
- When several chords share a triangle, an uncrossed edge sees only the nearest one. Single-chord side rules over-record once chords nest.
- A uniqueness proof can come from intersecting neighbour orbit sets around a trace-free component. Use it as the independent oracle for a local rule, not as the rule.
