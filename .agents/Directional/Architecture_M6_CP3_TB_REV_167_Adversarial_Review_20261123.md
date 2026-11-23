# TB-REV-167 — adversarial continuation (2026-11-23 UTC)

Continues `M6-CP3-TB-REV-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md). Runtime-free: source reading, the TB166 raw receipt, Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **Upheld:**
  - TB167 acceptance: 989/989, CP2 491/491, membership 1070, rows 1–984 equal under N1–N3.
  - The S1 diagnosis. The region reader counts an edge-only arc visit (arcs 1, 3, 26, 28) as a face chord and adds its opposite-side orbit. The corner reader must read the same arc pieces. So both readers must consume one shared classification.
- **Withdrawn:** the [CB-187 Code + Build plan](Architecture_M6_CP3_CB187_P13_Exact_Face_Cut_Reader_Code_Build_Plan_20261122.md) (P2–P7):
  - It is prose and monolithic, and it rests on a patch held outside the repository.
  - Its S5 STOP fires on the sphere witness, so its strict row 990 would be RED by construction.
  - Its S5 premise and its count-equality rule contradict the accepted ceiling design.
  - It puts three diagnostics-only repairs (S4, S6, S7) on the critical path.
- **Replaced by:**
  - an exact, pure, unwired CB-187 (`arc_face_visits` adapter plus four gated tests);
  - an exact 993-row TB168 manifest;
  - frozen contracts for the region switch (CB-188) and the corner switch (CB-189), which TB-REV-168 turns into exact diffs.

## Findings

**P1 — The S1 coupling is real; parts of its remedy overreach (see P6).**
- `build_regions` (`GlobalTopologyPlan.cpp:1259–1281`) and `build_fragment_corner_incidence` (`:508–624`) both iterate whole trace segments, so an edge-only arc re-reads its segment's face.
- `build_region_certificate` cross-checks the two readers: it needs a key for every region fragment (`:2237–2256`) and an owner for every corner (`:2287–2294`).
- Unless both readers take visits from one classification of `sourcePath`/`sourcePieceCounts`, they cannot agree.

**P2 — CB-187 repeats the defect withdrawn one turn earlier (L2, RA-261).**
- It hands the implementation agent eight obligations, at least five new test groups, a new manifest and a strict row. The agent must design:
  - the S5 STOP;
  - the S6 evidence rule;
  - the S7 replay;
  - the error mapping;
  - all the tests.
- Its starting point (v5) and its orbit evidence are held in an external "ChatGPT Library". They are not in the repository, so the implementation agent cannot read them and a reviewer cannot verify them.
- An exact handoff must be a committed `.diff` with preimage hashes (RA-201, RA-275).

**P3 — The S5 STOP fires on the sphere: row 990 is RED by construction.**
- TB166 receipt, face `18-19-24`:
  - arcs 11 and 12 are both `pieces=F` on trace 9, segment 0, from `v24` to `18-19@0.848226`.
- Face `25-27-28`:
  - arcs 16 and 17 are both `pieces=F` on trace 13, segment 0, from `v25` to `27-28@0.848226`.
- Two arcs on one face piece split it at a node strictly between a corner and an open-edge point. That node is an `ExactSourceFacePoint`.
- Both arcs are pieces of a separating chord, so `TraceFaceInteriorJunctionUncertified` fires.
- TB-REV-167 noted that `exit=-` alone does not prove an interior node. That is true but beside the point: the split proves it.
- CB-187 plus TB168 would spend two turns re-deriving what the published receipt already shows (RA-225: check that a defect can occur before designing its cure).

**P4 — S5's premise is wrong: `k + 1` is a sound ceiling, and the deficit side is observational by design.**
- Take the face's interior pieces as graph edges. Then F = 1 + E − V + C0 (TB-REV-167's own formula). Every component without boundary contact holds at least one interior node, so C0 ≤ V and F ≤ E + 1.
- The existing check rejects only an excess (`found->second.size() > expected`, `:1464`). It stays exact as a ceiling even with interior nodes.
- The low side is deliberately observational (`:2613–2614`; RA-217 "ceiling, not fail-closed").
- A deficit is legitimate: a chord whose two sides are one face-walk orbit gives two fragments and one owner (`sharedOwnerChordCount`, `:1447–1454`).
- v5's equality rule (item 3) would reject those configurations. It is the only reason v5 needs the STOP.
- Withdrawn: the STOP, the equality and deficit rules, and the "derive F = 1 + E − V + C0" obligation. The ceiling stays unchanged.

**P5 — S4, S6 and S7 change diagnostics only.**
- `localTraceChords` feeds only owner evidence (`:1430–1446`).
- `edgeOrbitEvidence` feeds only failure evidence and diagnostic prints (`:1515`, `:1672`, `:1937`).
- The replay (`:1476–1511`) runs only after the excess error.
- None of them decides an outcome.
- S6's rule is geometrically right: a cut arriving at corner j leaves edge j on its left and edge (j+2) on its right. But it writes evidence only.
- All three move to a later diagnostic-conformity CB (CB-190), off the critical path.

**P6 — "Re-derive every dependent fact" overreaches.**
- `traceTouchedEdges` feeds `componentBarriers` (`:1557`), which feed the uncut-component partition and the certified-owner consistency check. That is a decision.
- Changing it alters the census on rows the switch has no reason to touch.
- S1's "one side on each incident face" would also label the face across a slide edge. That would take an uncut face out of the certified-owner component flow, which already supplies its owner.
- The switch keeps barriers segment-based. It adds an edge-only visit's side orbit to the visited face only.

**P7 — A "must PASS" disc-certified row is a probe, not a gate row.**
- No one can predict the stage after the corner reader; G5 lists stages still ahead.
- Row 979 already prints the staged plan's stage. The TB after the corner switch reads it against a decision map.

**P8 — S2 and S3 are satisfied by design.**
- Once both readers consume one visit list, they cannot disagree.
- The helper's failures are face-level, so a mapped error carries `sourceFace` and no arc. No first-arc attribution remains to guard against.

## Frozen artifacts

| Artifact | SHA-256 | Content |
|---|---|---|
| `Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Exact.diff` | `806a64feba6d58d6333c4bd14b7ab465eb85b5ec4a6091afaac3cca2e48996ac` | 16,716 B, +348/−0. New `src/geometry/ArcFaceVisits.h` (`1cee9c3f71c1f24bd6ad0411379fd5679f7a4d06f29f5641e7aaf94448747f31`), detailed in the list below. Test file `8ccfc38b…1e24` → `bc1f6270c9990c260bcbc881e448a41d34eaa544ae0717ec26f5bd88dee89754`: an include plus four `ArcFaceVisits.*` tests (cut positions and trailing slide; slide side for both windings and both directions; interior ends; four typed rejections, each reaching its own rule). |
| `gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv` | `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436` | 993 rows. Rows 1–989 are TB167 `5c084199…8c50` byte for byte. Rows 990–993 are the four new tests (`directional_surface_cell_producer_tests`, PASS). |

`ArcFaceVisits.h` contains:
- `face_boundary_position`: exact barycentric coordinates → corner, edge offset, or interior.
- `arc_face_visits`: reuses `source_piece_binding_failure`, `exact_source_point_barycentric` and `edge_piece_face_side`. Each visit is either a `FaceCutPiece` with the arc's two orbits, or an edge-only side orbit.
- Typed failures: `PieceBinding`, `UnknownFace`, `PointOffFace`, `EdgeSideUndetermined`.

Haiku checks, fresh worktrees at `2870817db`:
- The first draft failed `-fsyntax-only`: `TopologyRegionId` was unqualified in the test helper. A using-declaration fixed it, and the hashes above are for the corrected diff.
- The re-check passed:
  - preimage `8ccfc38b…1e24` matched, and the header was absent before applying;
  - `git apply --check`, `git apply` and `git diff --check` pass, and both postimage hashes match;
  - numstat 128 + 220 lines added, 0 removed.
- `-fsyntax-only` (clang, C++20, `-Wall -Wextra`, `USE_GMP_ENABLED=1`): 0 errors and 42 warnings both before and after, with identical normalized sets and none in the new hunk.
- The header compiles on its own (`-Wpedantic`) with 0 warnings from it.
- `FieldExactRational::from_ratio(-1, 3)` returns a value; `<` comes from `<=>`.
- Manifest rows 1–989 hash to TB167's value. Rows 990–993 are exactly the four new tests, with no duplicate names and no other `ArcFaceVisits` suite.
- Nothing under `src/` or `include/` includes the header.
- Nothing was built or run.

## TB168 rules (STOP unless all hold)

1. 993/993 PASS; CP2 491/491; membership 1074 (993 gating + 81 deferred).
2. Rows 1–989 equal TB167 result `14770748728` under N1–N3, with zero allowance (the adapter is unwired).
3. Rows 990–993 PASS, logs published.
4. No census: no production path changes.
5. Any failure → BLOCKED and back to Review. Report it verbatim; never edit a test.

## Frozen contracts for the stacked switch (TB-REV-168 freezes both as exact diffs; RA-216, RA-249)

**CB-188 — region reader on arc visits.**
- **R1. One shared visit collection, used by both readers.**
  - Per trace arc: keep the existing trace and dart binding checks, then call `arc_face_visits(topology.faces, arc.sourceFaces, arc.sourcePieceCounts, arc.sourcePath, forwardOrbit, reverseOrbit)`.
  - Require `arc.sourceFaces[k] == trace->segments[arc.firstSegment + k].sourceFace`.
  - Any failure → `InvalidSourceBinding`, with the arc and, when known, the face.
- **R2. Cut visits.** A cut visit is skipped exactly when `is_terminal_slit(trace, firstSegment + k)` holds and its two orbits are equal, which is the old predicate unchanged. Every other cut adds 1 to `tracePieceCount` and both orbits to `fragmentOrbits`.
- **R3. Edge-only visits** add 0 chords, and add `edgeSideOrbit` to `fragmentOrbits[face]` of the visited face only.
- **R4. Unchanged:** the excess ceiling (`:1464`), `traceTouchedEdges`, segment diagnostics, `localTraceChords`, third-edge evidence and the failure replay. CB-190 owns those.
- **TB-EXEC/REV-169 predictions:**
  - Row 979: faces `6-8-9`, `16-20-21`, `32-33-34` and `40-45-46` print `traceChordCount=4 expectedFragmentCount=5 ownerCount=5`.
  - The staged stop is unchanged (`SourceFaceCarriesMultipleTraceCuts`, `6-8-9`).
  - Every other row is unchanged under N1–N3. Any other changed row → STOP, because production builds edge-only visits and must be censused.

**CB-189 — corner reader on the same visits.**
- **C1. Helper failures.** For each face with at least one counted cut, call `partition_face_corners(cuts)`. A failure maps to one new typed code carrying `sourceFace` and the `FaceCutPartitionFailure` reason, with no arc.
- **C2. Keys.**
  - Key every side orbit of the face's counted cuts, using an empty set when it touches no corner (strips, L3).
  - Require `fragmentOrbits[face]` to be a subset of those sides, passed through from `RegionBuildSuccess`. If it is not, raise a typed error at the face.
- **C3. Branches.** Keep the trace-port binding check. Delete the one-chord and ray branches and their emissions.
- **C4.** A face with no counted cut stays unkeyed.
- **TB-EXEC/REV-170 decision map:**
  - Wherever the old reader succeeded (one chord, or one corner fan), the helper reproduces its corner sets: CB-186 tests 985–989 pin both rules. So all rows except 979 are unchanged.
  - Row 979 shows either a built staged plan or the next typed stage. Decide the next step from that stage, not before.

## Turn sequence

1. **CB-187**: exact adapter diff, compile only.
2. **TB-EXEC-168**: 993 rows, rules above.
3. **TB-REV-168**: freeze the exact CB-188 and CB-189 diffs from the contracts above, each with its own manifest.
4. **CB-188** → **TB-EXEC/REV-169**: region reader.
5. **CB-189** → **TB-EXEC/REV-170**: corner reader; staged plan built, or the next typed stage.
6. **CB-190**: S4/S6/S7 diagnostic conformity. It is off the critical path and may run after CB-188.
7. Activation (V3/V4/V5/V10/V11) → TB → V3b → R1 → O48.

## Lessons

- Before freezing a typed STOP, check the published receipt for the configuration it stops. A STOP the witness must hit is a RED by construction.
- A count that is not exact can still be a sound bound. Check which side the consumer enforces before calling the count unsafe.
- Separate the facts a switch decides from the evidence it prints. Diagnostics-only repairs do not belong on the critical path.
