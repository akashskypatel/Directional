# TB-REV-175 — adversarial continuation (2026-11-23 UTC)

This continues turn `M6-CP3-TB-REV-175` after the [independent review](Architecture_M6_CP3_TB_REV_175_Retraced_Trace_Selection_Independent_Review_20261123.md).

The review was runtime-free. It used:
- source reading;
- a Haiku read-only dependency closure of `exact_trace_segment_pieces`;
- `git apply --check`;
- `clang++ -fsyntax-only` on the changed translation units, a self-contained header probe and an A2a include probe.

## Verdict

- **Upheld:** the TB175 rejection, 993/1000 with the same seven RED. CB-196 is unwired, so this was the predicted outcome.
- **Upheld:** the independent review's two new concerns.
  - Its item 4 is right: coverage equality is too weak (G1).
  - Its item 5 is right: a per-fixture selection receipt must come before the selection switch.
- **Withdrawn:** its prose CB-197A. It passed a refactor to the implementation agent as a description instead of an exact diff (RA-261).
- **Replaced by two exact, independent diffs:**
  - CB-197A, the extraction (G2);
  - CB-197B, the corrected retrace predicate (G1).
- One TB-EXEC-176 gate follows both.

## Findings

**G1 — The retrace predicate is too weak, and is corrected exactly.**

`exact_source_paths_retrace_along_edges` (CB-195) compares the *merged* edge coverage of the two paths. The merge condition `!(merged.back().second < stretch.first)` folds overlapping stretches together. So a path that runs back and forth along an edge has the same coverage, and the same ends, as a simple path.

Two premises make this unreachable in production today:
- traces stop at self-closure;
- traces never stop on a collinear overlap, which includes self-overlap.

The selection switch must not rely on either premise.

CB-197B replaces coverage equality with an **ordered** comparison:
- Each path becomes its sequence of maximal directed edge stretches. Consecutive pieces on one edge, continuing in one direction, form one stretch.
- `b` must equal `a` reversed, stretch by stretch, with each stretch's direction reversed.

This is exact for any input. It keeps carrier independence and piece-break independence:
- the existing positive test covers both;
- all existing negatives still fail, because the detour and other-edge cases differ in stretch count or edge.

A new test, row 1001, covers two inputs:
- a path running along (0,1) three times;
- a path turning back partway along (1,2).

The old coverage helper returns true for the first. The new helper rejects both.

**G2 — The extraction is four functions, moved verbatim.** The Haiku closure, spot-checked here, finds that `exact_trace_segment_pieces` depends only on three functions in `EmbeddedGraphTopology.cpp`:
- `exact_trace_segment_end`;
- `face_chart_segment_parameter`;
- `canonical_boundary_barycentric`, which is in an anonymous namespace.

It also needs the `FaceChartPoint` alias. It reads nothing from the embedded-graph stage.

CB-197A changes:
- It moves those definitions unchanged, adding only `[[nodiscard]] inline`, into the new `src/geometry/ExactTraceSegmentPieces.h`.
- The new header includes only `ExactSourcePath.h` and `SurfaceCellTracing.h`.
- It keeps the namespace `embedded_graph_topology_detail`, so the test calls `embedded::face_chart_segment_parameter` and `embedded::exact_trace_segment_pieces` resolve unchanged.
- `EmbeddedGraphTopology.h` includes the new header and drops the two declarations and the alias it held.

What the check showed:
- Every removed body line appears in the new header. The only removed lines without a match there are the two old declarations.
- `EmbeddedGraphTopology.cpp` still has 0 errors and 3 warnings, the same as before.
- The test translation unit still has 0 errors and 9 warnings.
- The header compiles on its own.
- I prepended an include of the header to `SurfaceCellTracing.cpp`. That adds no error beyond the existing macOS-only `std::inserter` error in `SourceChartTransitions.h:529`, which the unmodified translation unit also has. So the A2a stage can include it without a name clash.

The namespace name remains a naming debt. It can be renamed once CB-199 makes A2a its second reader.

**G3 — No CMake change is needed.** Both stages are in the same library target (`CMakeLists.txt:184`, `:206`), and the moved code is header-inline.

**G4 — The independent review's falsifier "terminal-contact slide unchanged" is satisfied by construction.** The body that handles a terminal contact on the last segment moved verbatim. TB-EXEC-176 checks it at runtime, because every row that builds an embedded graph calls the moved code.

## TB-EXEC-176 rules (frozen)

1. **Code:** apply CB-197A and CB-197B. Each applies on its own and they apply together, because they touch disjoint files.
2. **Manifest:** `gates/Architecture_M6_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Case_Manifest.tsv`.
   - SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`, 1001 rows.
   - The first 1000 rows are TB175's `e1d77fd2…3e35`.
   - Membership 1082.
3. **Required result:** 994 PASS. Rows 995–1001 PASS. The same 7 rows are RED.
4. **Comparison:** every other row must equal TB175 `14849271506` under N1–N3, plus assertion-line moves that the diffs prove. The tests are appended at the end of the file, so no moves are expected. Any other difference means STOP and return to Review.

## Turn sequence

1. CB-197A: compile only.
2. CB-197B: compile only.
3. TB-EXEC-176.
4. TB-REV-176: freeze CB-198 exactly. CB-198 is a test-only per-fixture selection receipt. It calls `exact_source_retraced_traces` on the `exact_trace_segment_pieces` paths of each mechanical fixture. For row 652 it is predicted to give 4 pairs; a missing path fails closed. Then TB-EXEC-177.
5. CB-199, then TB: selection inside `canonical_field_aligned_candidate`, with three parts:
   - remap `struckTrace` and the event incidences of each removed trace;
   - record that the kept trace's arrival owns the removed trace's port, `Y.port`;
   - fail closed on a missing path.
6. CB-200, then TB: the readers that assume one trace per port, plus the every-region-owns-a-face assertion. Expected: mechanical controls green, and row 652 has 2 regions.
7. Row 979, Branch A, CB-190.

Still open: the dropped `CollinearOverlap`/`EndpointTouch` contacts and the per-grazing-edge count (TB-REV-173 E5).

## Lessons

- An equality on merged coverage is not an equality on curves. Compare the ordered, directed stretches.
- Before scheduling an extraction, take its dependency closure. If the closure is small, freeze the diff in the Review.
