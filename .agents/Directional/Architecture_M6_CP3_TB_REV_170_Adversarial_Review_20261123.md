# TB-REV-170 — adversarial continuation (2026-11-23 UTC)

Continues turn `M6-CP3-TB-REV-170-P13-CORNER-VISIT-READER-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_170_Corner_Visit_Reader_Independent_Review_20261123.md). Runtime-free: reading, an SHA-checked read of the TB170 and TB169 artifact logs, `git apply --check` and `clang++ -fsyntax-only`. No product binary was built or run.

## Verdict

- **Upheld:**
  - TB170 rejection: 986/993, seven mechanical controls RED, one accepted-green recurrence (67/17/50).
  - CB-189's corner reader and `partition_face_corners`. Both are correct: the rejection they raise is a true geometric contradiction.
- **Withdrawn:** the CB-191 reason receipt (`aa2ff185…792f`), never executed. The reason is already decided by the lines the RED prints (A1), so the receipt would spend a CB and a full gate to print a value with one possible outcome.
- **Replaced by:** exact repair **CB-192** at the classifier that owns the defect (A2–A4), with its own falsifier test, and **TB-EXEC-171** on a 994-row manifest.
- **Corrected in the record:** TB-REV-168 Q3 and TB-REV-169 W4 predicted that row 652 would pass under CB-189. That was wrong (A5).

## Findings

**A1 — The failure reason is already decided by the printed locus (RA-235).**
- The row-652 exception line (TB170 artifact `14793023424`, ZIP SHA verified, `raw/652.log:118`) carries the region reader's own per-face records, not only the outer label:
  - `fragmentOwnerFace[3]={sourceFace=1,4,139,…,traceChordCount=1,…,sharedOwnerChordCount=1}`
  - `sharedChord[0]={trace=1,arc=15,segment=3,forwardOrbit=0,reverseOrbit=0}`
- `traceChordCount` is CB-188's `tracePieceCount`. It is computed from the same `arcVisits` with the same terminal-slit skip as the cuts CB-189 passes to `partition_face_corners`. So the helper saw **exactly one cut, with equal side orbits**, and that cut is segment 3 of arc 15, a middle segment.
- Elimination over `FaceCutCornerPartition.h:139–232`:
  - `UnorderedSharedEndpoint` and `CrossingCuts` need two cuts.
  - `InconsistentSideOrbits` cannot fire on one cut whose orbits are equal.
  - `MalformedBoundaryPosition` cannot come from `face_boundary_position`: every offset it returns is a barycentric weight in [0, 1).
  - `NoBoundaryEndpoint` needs both ends strictly inside the face, but a middle segment's entry is a `FieldBoundaryPoint`.
  - **Only `CutAlongOneEdge` remains.**
- The geometry agrees. Arc 15 visits `8-10-151`, `6-8-147`, `4-6-143`, `1-4-139` and `0-1-102` (segments 0–4). Each consecutive pair of faces shares a single vertex (8, 6, 4, 1), so the trace walks the vertex chain 8→6→4→1. Each middle segment is a face-interior piece from one corner of its face to another, which is geometrically the edge between them: a mechanical feature line along mesh edges.
- `1-4-139` is the first failing face because `cutsByFace` is visited in key order: `0-1-102` is a terminal slit with equal orbits and is skipped.

**A2 — Root cause: the visit classifier reads the carrier type, not the geometry.**
- `exact_source_path_is_canonical` (`ExactSourcePath.h:159`) admits a `SourceFaceInteriorSupport` piece whose two ends are corners, or points, of one edge of the face. `exact_trace_path` (`EmbeddedGraphTopology.cpp:326–346`) emits every segment as a face piece.
- `partition_face_corners`' contract says "Pieces that run along an edge cut no face interior and are not passed here". `arc_face_visits` breaks that contract: it labels a visit a cut whenever the opening piece's carrier is a face. It should label a visit a cut only when the piece actually leaves the edge.
- The old segment-based corner reader tolerated such a corner-to-corner "chord". The exact reader correctly refuses it.
- So the defect is in the adapter (CB-187), not in CB-189 or the helper. Weakening the helper, or skipping `CutAlongOneEdge` in the reader, would hide the same misreading from the region reader. That reader already counts the piece as a chord: `expectedFragmentCount=2` against one owner, which is the `ownerDeficit=1` on all four middle faces of arc 15.

**A3 — Repair, CB-192, exact.**
- `arc_face_visits` reads a face piece whose two boundary positions lie on one closed edge as an along-edge visit. It cuts nothing, and its `edgeSideOrbit` comes from the new pure `along_edge_face_side`:
  - Forward when the piece runs in corner order along that edge. That is the side `FaceCutPiece` gives the forward dart, and the same side `edge_piece_face_side` gives an edge piece in the same direction.
  - `on_one_closed_edge` is reused from the helper, so the classifier and the rejection share one predicate.
- Both readers consume `arcVisits`, so one change fixes both:
  - The region reader drops the false chord: count 0, owner set unchanged.
  - The corner reader leaves the face unkeyed.
  - The certificate already treats an unkeyed face as whole (`GlobalTopologyPlan.cpp:2196–2200`), which is exactly an uncut face.
- No upstream path or tracer change. A tracer emitting `SourceEdgeSupport` would be the deeper fix, but it reaches every conformity validator and is out of proportion to the defect.
- Falsifier: new test `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides`.
  - In both windings of the shared edge and both directions, a corner-to-corner face piece has no cut and takes **the same side as the edge piece** in that direction.
  - It also covers corner-to-point and point-to-corner on one edge.
  - A corner-to-opposite-edge control still cuts.
  - The test fails on the current classifier, which returns a cut.
  - Row 652 is the integration witness.

**A4 — Every off-row change is explained by the one cause.**
- Haiku classified all 21 rows from both artifacts. Only the header face `1,4,139` carries `SourceFaceCutPartitionFailed` (rows 652, 656, 669). No other `global-topology-plan/<Code>` appears.
- The 7 RED rows lose the mechanical plan.
- The 13 other PASS rows differ only by missing `M3_CP4AB_FRAGMENT_DIAG` records, which the mechanical plan emits.
- Row 669's non-N3 change is its mechanical `pipelineFailureStage` moving from `tracing` to the same code.
- So TB-EXEC-171 can require exact TB169 equality off row 979.

**A5 — Correction of my earlier prediction.**
- TB-REV-168 Q3 checked which *deleted* old-reader codes the gate reached. It never checked where the *new* helper's rejections could fire on inputs the old reader accepted.
- TB-REV-169 W2 replayed only row 979, from a receipt that prints segment ends.
- Both missed `CutAlongOneEdge` on single-cut mechanical faces. TB170 is the evidence.
- The "row 652 passes" rule in W4 was a false prediction, not an observation.

**A6 — The independent review's CB-191 was under-determined in the wrong direction.**
- It read only the outer label ("do not infer from the outer label") and missed the per-face records on the same line.
- It deferred a piece-lineage receipt to a further turn. Doing both would have cost two CB+TB cycles before any repair.
- Its accounting (67/17/50), its rejection and its row-979 classification stand.

**A7 — Row 979: recorded, not scheduled.**
- `RegionContainsInteriorSingularity` at source vertex 8 (`RegionCertification`) is the sphere's next typed stage after the corner reader.
- CB-192 may change row 979 if any of its arcs carries along-edge face pieces. W2's replay could not see piece ends.
- TB-REV-171 reads row 979's printed locus before choosing a sphere turn (RA-235).

## TB-EXEC-171 rules (frozen)

1. Use manifest `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv`, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`. It is the TB168 993 rows plus row 994, `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides`. The first 491 rows are unchanged (`483f1101…038`).
   - Required: **994/994 PASS**; CP2 491/491; membership **1075** = 994 + 81 deferred.
2. Rows other than 979 and 994 equal TB169 `14787082075` under N1–N3, with zero allowance. That includes rows 445, 652, 653, 656, 658, 660 and 786 (PASS again) and the 300 restored diagnostic records.
   - Any difference → STOP, report the lines, return to Review. Make no edits.
   - A difference confined to faces that carry along-edge face pieces is a *measurement* for Review, not an acceptance.
3. Row 979's `SphereStagedPlan` is a measurement. Report it against TB170's `RegionContainsInteriorSingularity sourceVertex=8`.
4. No census, no rebuild, no activation.

## Turn sequence

1. **CB-192**: exact diff, compile only (GMP/GMPXX).
2. **TB-EXEC-171**: rules above.
3. **TB-REV-171**:
   - If green: read row 979's printed locus for `RegionContainsInteriorSingularity`, then freeze a receipt **or** a narrow repair (W5 Branch B), never both.
   - Branch A (activation, the census TB, parameter deletion, V3b, R1, O48) only after the staged plan builds.
4. **CB-190** (S4/S6/S7 + W6) stays off the critical path.

## Lessons

- Before switching to a stricter reader, list every rejection the new reader can raise and check each against the inputs the old reader accepted on every gate row, not only the codes being deleted.
- Read every field of a RED's exception line before freezing a receipt. A per-face record already printed can decide the reason by elimination.
- A classifier that types pieces by carrier must agree with the geometric predicate its consumer rejects on. Share the predicate.
