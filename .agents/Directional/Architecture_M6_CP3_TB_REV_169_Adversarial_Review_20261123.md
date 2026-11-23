# TB-REV-169 — adversarial continuation (2026-11-23 UTC)

Continues turn `M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md). Runtime-free: reading, plus an SHA-checked read of the TB169 artifact. No product binary was built or run.

## Verdict

- **Upheld:**
  - TB169 993/993. Row 979's four faces print chords 4, expected 5, owners 5 and deficit 0, as predicted.
  - Live source = CB-188 postimage `5af71bc0…0aae`.
  - Successor CB-189, amended diff `6e391678…e3b8`, which applies to the live source unchanged.
- **Added:** a replay of row 979's per-visit receipt, which predicts that CB-189 clears the corner stage on every cut face (W2). TB-EXEC-170 gets sharper rules (W4), and the post-TB-REV-170 turns are pre-split so activation cannot become one large turn again (W5).
- **No realignment of the product trajectory.**

## Findings

**W1 — TB169 acceptance is sound.**
- The comparison covers all 993 rows under N1–N3, using complete diagnostic-record multisets. A negative control confirms it is non-vacuous.
- Only the three predicted count fields changed, on exactly four row-979 face records.
- No other row changed. So in the gate, edge-only visits occur only on row 979's four slide faces, which is the census condition R-169 set.

**W2 — CB-189 is predicted to clear the corner stage on row 979.**
- *Method:*
  - Data: artifact `14787082075` (ZIP SHA verified). The 136 `SphereStagedMultiCutVisit` lines (55 faces with more than one visit) and the 30 `fragmentOwnerArc` orbit pairs.
  - The check re-applies `partition_face_corners` (`FaceCutCornerPartition.h:139–232`) to each face, in both possible windings: closed-edge rejection, crossing, shared-point order, side-orbit consistency and corner assignment.
- *Result:* all 55 faces partition consistently, each in exactly **one** winding.
  - The accepted windings agree across shared edges, as an oriented sphere requires. Examples: `6-8-9`=[6,8,9] against `6-7-9`=[6,9,7]; `16-20-21`=[16,20,21] against `15-16-20`=[15,20,16].
  - Each face's owner count equals the number of its cut-side keys, so the C2 subset check is not expected to fire.
  - Face `6-8-9` worked by hand. Its cuts are arc 0 (0|1), arc 6 (0|6), arc 5 (6|7) and arc 12 (8|7). The corners come out as {6:{1}, 8:{0,6,7}, 9:{8}}, which is exactly the region orbits {0,1,6,7,8}.
  - The interior T-junction at node 17 (`25-27-28`: trace 2 ends on trace 13, so arcs 16/17 split there) and the split pair 11/12 in `18-19-24` also partition.
  - Faces with a single cut are consistent by construction.
- *Limits:*
  - Slide-start offsets on slide edges are not printed. A placeholder was used; no other end shares those edges.
  - The receipt prints segment-level ends (W3). Two corrections were applied to the data: nodes 9 and 10 each join two arcs in adjacent faces, so they lie on the shared edges `0-2` and `25-27`.
  - So this is a prediction, not evidence.
- *Consequence:* C1/C2 are expected to stay **unwitnessed** after TB170. Row 979 is expected to move past `build_fragment_corner_incidence`, to a certificate or plan stage, or to build.

**W3 — Receipt resolution gap (recorded, not scheduled).**
- `SphereStagedMultiCutVisit` prints the segment's entry and exit, not the arc piece's cut ends.
- A last-segment end is printed as `-` even when it lies on an edge (arcs 6, 8, 19, 23).
- A split segment (11/12, 16/17) and a face-then-edge (FE) piece share one line.
- After CB-189 the deciding input is the arc-piece cut, so a corner-stage RED in TB170 could not be read from this receipt. Only in that case should TB-REV-170 freeze a test-only receipt that prints each counted cut's `FaceCutPiece` (local positions and orbits). Otherwise do not add prints (RA-235).

**W4 — TB-EXEC-170 rules (frozen, extending TB-REV-169's).**
1. 993/993 PASS; CP2 491/491; membership 1074.
2. Rows other than 979 equal TB169 `14787082075` under N1–N3, with zero allowance. Row 652 passes without a throw.
3. Row 979's `SphereStagedPlan` line is a **measurement** (the test makes no assertion on it, `tests:17885–17900`). Receipt lines that depend on the old stop may disappear.
   - Prediction: the outcome is no longer `SourceFaceCarriesMultipleTraceCuts`, and is **not** `SourceFaceCutPartitionFailed` or `SourceFaceCutOrbitNotOwned`.
   - If either new code prints, W2 is falsified, which points to an orientation or offset convention defect in the adapter or helper. The TB does not stop; TB-REV-170 starts from W3's receipt.
4. No census, no rebuild. Any other difference → STOP and return to Review.

**W5 — Post-TB-REV-170 turn split (realignment of the activation step).**
- Branch A, staged plan built. Activation stays one exact switch, because the gate must stay green: a single-source default change (V11) plus exact premise-row replacements (393/648/858/971/972/978) taken from row 979's measured lines.
  - It must not bundle parameter deletion, V3b or R1. Each gets its own CB after the activation TB.
  - The activation TB carries the BunnyRandom census falsifier (V5).
- Branch B, the next typed stage: read the stage's existing printed locus first (RA-235). Then freeze either a test-only receipt or a narrow repair, never both.
- Either branch is frozen in TB-REV-170 as exact diffs, not prose.

**W6 — Leftovers CB-189 creates (recorded for CB-190).**
- The enum values raised only by the deleted branches stay public but become unreachable. That set includes `SourceFaceCarriesMultipleTraceCuts`, `…TraceChordAndRays`, `SourcePortFaceAlreadyCarriesTraceChord` and the `FragmentCorner*` rotation reasons.
- Keep them for ABI stability. CB-190 may mark them obsolete in their doc comments, with no behavior change.

## Turn sequence

1. **CB-189**: amended diff, compile only.
2. **TB-EXEC-170**: W4.
3. **TB-REV-170**: Branch A or B (W5), exact diffs.
4. Branch A: activation CB → TB with census → parameter deletion CB → V3b → R1 → O48. Branch B: a receipt or narrow repair, then a TB.
5. **CB-190**: S4/S6/S7 plus W6, off the critical path.

## Lessons

- Replay a pure helper on the published receipt before the switch TB. Trying both face windings separates a real inconsistency from a convention artifact: a real face accepts exactly one winding, and the accepted windings must agree across shared edges.
- A receipt that prints segment-level ends cannot witness a reader that consumes arc-piece ends. Schedule the finer print only if the coarse one is ambiguous at a RED.
