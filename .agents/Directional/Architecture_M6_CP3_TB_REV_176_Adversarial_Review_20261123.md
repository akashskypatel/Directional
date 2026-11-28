# TB-REV-176 — adversarial continuation (2026-11-23 UTC)

This continues turn `M6-CP3-TB-REV-176` after the [independent review](Architecture_M6_CP3_TB_REV_176_P13_Piece_Builder_And_Ordered_Retrace_Independent_Review_20261123.md).

The review was runtime-free. It used:
- source reading;
- a Haiku read-only inventory of how tests reach the mechanical fixture's traces;
- `git apply --check`;
- `clang++ -fsyntax-only` on the test translation unit.

## Verdict

- **Upheld:** the TB176 rejection, 994/1001 with the same seven RED. CB-197A and CB-197B changed no production output, as predicted.
- **Upheld:** the need for a per-fixture selection receipt before the selection switch.
- **Withdrawn:** the independent review's prose CB-198. It handed a receipt to the implementation agent as a description, not an exact diff. That is the pattern RA-261 withdrew, and it has now recurred in four reviews in a row.
- **Replaced by:** an exact test-only CB-198 diff (H1), with frozen TB-EXEC-177 rules.

## Findings

**H1 — The only place a test can read the mechanical traces is the existing failure branch. CB-198 is frozen there.**

- **Where the traces are.** Mechanical production fails at the region stage. So `cp4c_mechanical_fixture()` throws from `build_cp4c_production_fixture`. The only code that holds the produced `FieldAlignedCurveNetwork` for that fixture is that function's `RegionElectedCutComponentEmpty` branch, which already calls `append_along_edge_visit_receipt`.
- **Why not a new test.** No test applies `exact_trace_segment_pieces` to mechanical traces. The only fixture-backed caller is on the sphere. A new TEST would rerun the pipeline and need a new manifest row, and it would print nothing the branch cannot print.
- **The patch.** `Architecture_M6_CP3_CB198_P13_Mechanical_Retraced_Trace_Selection_Receipt_Exact.diff` adds `append_retraced_trace_selection_receipt` and one call after the along-edge receipt. For each trace, in port order, it concatenates `exact_trace_segment_pieces` over every segment, then:
  - **Fails closed.** It prints `retracedTraceSelection=pathUnavailable{trace,segment,read=none|empty|disjoint|noSegments}` and stops if any of these happens:
    - a segment cannot be read;
    - a segment reads empty;
    - a segment does not start where the previous one ended;
    - the trace has no segments.

    A missing path is never counted as "no retrace" (TB-REV-174 F5).
  - **Calls the switch's own helper.** It runs `exact_source_retraced_traces` on the paths, as RA-264 requires. For each pair it prints:
    - the kept and removed trace, port and origin singularity;
    - **the arrival singularity of each** (`terminalSingularity`);
    - the shared edges.
  - **Prints the evidence behind a short count (RA-231).** It lists every pair of traces that shares a source edge, up to 64 pairs, each with:
    - `retrace`;
    - an `ends` relation: reversed, same, sharedStart, sharedEnd or other;
    - the face-piece counts and piece counts.

    So if fewer than 4 pairs appear, the log already says which condition failed.

**H2 — The D13 = A premise needs a check that neither review named.** The arrival port is `Y.port` (TB-REV-174 F1) only if the kept trace X actually *arrives at* Y's origin singularity. X must end with `terminalSingularity == Y.singularity`, not with a `terminalContact` or a limit cycle.

The retrace predicate compares geometric ends. It cannot tell a singular arrival from a stop at a point that happens to sit on the singular vertex. CB-198 prints `keptArrival` and `removedArrival` next to both origins, so TB-EXEC-177 checks the premise directly.

If any pair breaks this check, CB-199 cannot record `Y.port` as X's arrival port. The Review must then go back to how arrivals are recorded before any switch.

**H3 — Two of the independent review's demands are redundant or over-scoped, and are not frozen.**
- **Already enforced.** "Require an actual positive-length opposite traversal" is enforced by the predicate itself. `exact_source_piece_edge_interval` rejects zero-length pieces, and the predicate rejects empty paths.
- **Evidence nothing reads.** "Full source-entity and directed interval witnesses" would print data that no decision reads (TB-REV-174 F1 lesson). The frozen fields are the ones that decide the outcome: edges, ends, face pieces and arrivals.

**H4 — The receipt cannot change outcomes, and needs no CMake or manifest change.**
- It only appends text to an exception that is already thrown, so it cannot change any row's outcome.
- No new test, so the TB176 manifest is reused unchanged.
- Syntax check of the test translation unit: 0 errors and 9 warnings, the same as before.
- The receipt is O(T²) in the trace count and runs only on the failure path.

## TB-EXEC-177 rules (frozen)

1. **Code:** apply CB-198 on top of CB-197B source `8d2dd3d4…`. Compile only in the CB.
2. **Manifest:** the unchanged TB176 manifest, `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`, 1001 rows, membership 1082.
3. **Required result:** 994 PASS, with the same 7 RED rows (445/652/653/656/658/660/786).
4. **Comparison:** compare against TB176 `14861444963` under N1–N3. The only allowed difference is in rows whose TB176 log contains `;alongEdgeVisitsTruncated=`. Directly after each `;alongEdgeVisitsTruncated=<true|false>`, one inserted text may appear. It must start with `;retracedTraceSelection=` and end with `;sharedEdgeTracePairsTruncated=<true|false>`, or end with `}` after `pathUnavailable{…}`. Any other difference means STOP.
5. **Record:** the full row-652 receipt text, verbatim, in the TB report.
6. **Prediction (recorded, not forced):** row 652 reports:
   - `available` with `retracedTraceCount=4`;
   - in every pair, `keptArrival = removedSingularity` and `removedArrival = keptSingularity`;
   - singularities drawn from {10, 35, 47, 71}.

## Turn sequence

1. CB-198: compile only.
2. TB-EXEC-177.
3. TB-REV-177 reads the receipt.
   - If the prediction holds, freeze CB-199A: a pure, unwired helper that remaps references, plus a unit test. It remaps `struckTrace` and the event incidences from the removed trace to the kept one, and records `Y.port` as owned by the kept trace's arrival.
   - If the receipt shows `pathUnavailable` or a broken arrival, the Review addresses the producer first.
4. CB-199B: the switch inside `canonical_field_aligned_candidate`. It selects with `exact_source_retraced_traces`, applies CB-199A and fails closed on a missing path. Then a TB.
5. CB-200, then a TB: the readers that assume one trace per port (`EmbeddedGraphTopology.cpp` 1793, `GlobalTopologyPlan.cpp` 410/2117, the origin events), plus the every-region-owns-a-face assertion. Expected: the seven controls go green, and row 652 has 2 regions.
6. Row 979, Branch A, CB-190.

Still open: CollinearOverlap/EndpointTouch (TB-REV-173 E5). Naming debt: the `embedded_graph_topology_detail` namespace.

## Lessons

- Before freezing a receipt for a failing fixture, find where the test already holds the failing product. A failure-branch receipt reuses that product, without a new run or a new row.
- An ownership rule derived from geometric ends needs the recorded arrival kind as well as the end point.
