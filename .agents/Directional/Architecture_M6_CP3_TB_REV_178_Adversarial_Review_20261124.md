# TB-REV-178 — adversarial continuation (2026-11-24 UTC)

This continues turn `M6-CP3-TB-REV-178` after the [independent review](Architecture_M6_CP3_TB_REV_178_Retraced_Trace_Reference_Remap_Independent_Review_20261124.md).

The review was runtime-free. It used:
- source reading;
- one Haiku read-only inventory of the fixture, validator, sort, piece-reader callers, region invariant, port readers and the retrace helper;
- `git apply --check` against the live preimages;
- `clang++ -fsyntax-only` on both patched translation units.

## Verdict

- **Upheld:** the TB178 rejection, 995/1002 with the same seven RED. The comparison evidence is accepted.
- **Accepted unamended:** the exact CB-199B diff `02cc43c4…1fe5`. It compiles, and it meets every J4/J5 obligation.
- **Corrected:** the CB-200 premise. No inventoried reader fails on a port that lacks a departing trace (K5). CB-200 must be scoped from the TB179 first failure, not pre-frozen.

## Findings

**K1 — CB-199B compiles. The independent review checked only `git apply`.**
- All three preimages match the live tree, and all three postimages match the manifest.
- Test TU: 0 errors and the same 9 warnings.
- Producer TU: 0 errors.
  - The local syntax check needs `-include iterator`.
  - `SourceChartTransitions.h:529` uses `std::inserter` without `<iterator>`. The error occurs at HEAD too, so it predates the diff and does not affect the CI toolchain.
  - Without the workaround, the local check stops at that header and never reaches the patched code.

**K2 — The design meets J4 and J5.**
- **Placement.** Selection runs after the last positional subscript and the terminal-kind check (`SurfaceCellTracing.cpp:4874–4885`). It runs before `field_aligned_sort_events` (`:4930`), which re-sorts incidences by `(trace, sourcePort, role)` and then the events.
- **All or nothing.** Every pair is applied to a copied candidate, which is published only if all pairs remap.
- **Ownership.** The binding is an explicit `arrivalPort`.
  - `sourcePort` and the junction roles keep their producer meaning.
  - The guard asserts `incidence.sourcePort == trace.port` on every event.
- **Explicit comparison is necessary, so the negative control is meaningful.**
  - The validator compares fields one at a time (`:5838`).
  - Before that comparison it checks only the source and atlas digests, the ports, the mandatory edges, `arrivalPriority` and the trace count.
  - Without the new `arrivalPort !=` clause, a candidate with the binding stripped would be accepted. The guard's rejection test would then fail.
- **Region grouping is redundant but harmless.** A trace cannot leave its origin region (`:2647–2649`, `:3558–3560`), so a reciprocal pair always shares a region.
- **Rejecting a reused trace is geometrically sound.** `exact_source_retraced_traces` can pair one kept index with several later indices. However, a trace arrives at exactly one singularity, and its reverse edge path is unique. Two distinct ports cannot both retrace it except in a degenerate case. Failing closed there is correct.
- **Ports remain checked.** `singularityPorts` must still equal the canonical recomputation (`:5866`). `arrivalPriority` is an enum, so it holds no trace references.

**K3 — Fail-closed exposure is bounded but not zero.**
- Path reading now runs in A2a for every singularity-terminating trace on every fixture.
- Fixtures that reach `EmbeddedGraphTopology` already read every segment between cuts (`build_arcs` → `exact_trace_piece_path_between`, `:963`/`:1823`). A missing piece there is unlikely.
- Two parts are new: the cross-segment continuity check and the terminal-point equality check, along with fixtures that stop before the embedded graph.
- The retrace predicate rejects on mismatched endpoints first (`ExactSourcePath.h:282`), so the O(T²) pair loop is cheap.
- TB179's existing "no green-to-red loss" rule is the falsifier.

**K4 — Raw-log changes are expected and must be itemized, not normalized.** The `committedSlide` diagnostic runs after selection. A fixture that loses a trace therefore loses that trace's lines. TB179 must list them per row, as the frozen rule already requires.

**K5 — The planned CB-200 reader premise is unproven.** No production reader iterates ports and demands a departing trace:
- `GlobalTopologyPlan.cpp:503`, `:2115` and `EmbeddedGraphTopology.cpp:1649–1667` look up `trace.port` among the ports, and kept traces keep their own ports.
- The `GlobalTopologyPlan.cpp:410` line cited in earlier plans only writes a failure field.

So TB179 may move row 652 straight to region election or to the rotation system. In the rotation system, the kept trace's arrival end at Y's node is the only place a missing departure at `Y.port` can matter. CB-200 is therefore re-scoped: TB-REV-179 freezes it from the observed first failure.

**K6 — Layering debt grows; it does not block.**
- The A2a producer now includes `RetracedTraceReferences.h`, which includes `ExactTraceSegmentPieces.h`.
- It calls `embedded_graph_topology_detail::exact_trace_segment_pieces`, so an upstream stage depends on a downstream stage's detail namespace, and the name no longer describes the helper's role.
- A digest-neutral rename turn is sequenced after the mechanical controls are green, so it does not disturb the gate chain.

**Not shown yet (carried from J6):** whether any `terminalContact` strikes traces 3, 8, 9 or 11. The guard's live-reference loop will show it on row 1003.

## Turn sequence

1. CB-199B, compile only, exact as frozen.
2. TB-EXEC-179: 1003 rows under the frozen plan. Row 1003 must PASS. No green-to-red loss. Every changed raw record is itemized, including `committedSlide` lines.
3. TB-REV-179: adjudicate each change, and freeze CB-200 from row 652's actual first failure. The every-region-owns-a-face assertion is retained.
4. CB-200, then a TB. Expected: the seven controls go green, and row 652 has 2 regions.
5. A digest-neutral rename of the exact piece helpers out of `embedded_graph_topology_detail`, verified by a byte-identical gate.
6. Row 979, Branch A, CB-190.

Still open: CollinearOverlap/EndpointTouch (E5).

## Lessons

- Syntax-check every patched production TU. A pre-existing header error can stop the check before the patched code is reached, so a "clean" result can be vacuous.
- Before planning a reader change, find the reader that actually fails on the new shape. An inventory showed that the planned port-set readers never require one trace per port.
