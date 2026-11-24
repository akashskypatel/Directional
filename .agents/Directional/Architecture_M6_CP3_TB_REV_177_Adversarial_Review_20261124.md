# TB-REV-177 — adversarial continuation (2026-11-24 UTC)

This continues turn `M6-CP3-TB-REV-177` after the [independent review](Architecture_M6_CP3_TB_REV_177_Mechanical_Retrace_Selection_Independent_Review_20261124.md).

The review was runtime-free. It used:
- source reading;
- two Haiku read-only inventories:
  - which code assumes a trace id equals its position in the trace list;
  - which events production emits and which readers consume them;
- `git apply --check`;
- `clang++ -fsyntax-only` on the test translation unit with the proposed diff applied.

## Verdict

- **Upheld:** the TB177 rejection, 994/1001 with the same seven RED. The receipt evidence is accepted.
- **Accepted:** the independent review's exact CB-199A. It compiles and matches the events production emits. One design defect is amended (J4).
- **Replaced:** the original diff, by `Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Amended_Exact.diff`.
- **Frozen:** the TB-EXEC-178 manifest. The independent review described it but never created it.

## Findings

**J1 — My TB-EXEC-177 rule was wrong, and the H4 STOP is mine.** I froze "assertion-line moves: none expected", but CB-198 inserts 108 lines at test line 8162, in the middle of the file. Every assertion after that point moves by +108. Rows 445, 653, 658, 660 and 786 moved exactly +108.

- This repeats RA-247, a lesson I had already recorded: allow assertion-line moves that the diff proves.
- The independent review adjudicated it correctly, as source-location moves rather than new failures. Keeping the historical STOP is also correct.
- Every rule frozen in this continuation states its line-move allowance explicitly.

**J2 — The receipt confirms the D13 = A premise on row 652.**
- Row 652 shows four pairs: kept/removed traces 0/3, 2/8, 7/9 and 4/11.
- Each trace has five edge pieces and no face pieces.
- The ends are reversed, and both arrival equalities hold. Singularity IDs 1, 3, 5 and 7 correspond to source vertices 10, 35, 47 and 71.
- So the kept trace really arrives at the removed trace's singularity, and the arrival can own `Y.port`.

**J3 — CB-199A compiles, and its event contract matches production.** The independent review did not compile it. Here it gives 0 errors and the same 9 warnings as before, and the postimage hashes match. It assumes the same event shapes that production emits:

| Case | What production emits | Where |
|---|---|---|
| A trace arrives at a singularity | `FirstContact` (Interior) and `SingularityTermination` (Terminal) at the terminal node, `sourceEdge = terminalPoint->edge` | `SurfaceCellTracing.cpp:2352–2363` |
| A trace starts at a port | one `SingularityPortOrigin` per node; a `SingularityPortJunction` only when two or more traces leave that node | `:3900–3911` |
| One trace stops on another | `FirstContact` with both traces Interior, plus `TraceIntersection` with only the stopping trace Terminal | `:4256–4283` |

The independent review's struck-segment finding is right. `EmbeddedGraphTopology.cpp:1729` cuts the struck trace at `carrierContact.struckSegment`, so the segment index must be remapped together with the trace.

**J4 — Design defect, amended: the proposed diff recorded port ownership by changing the meaning of two event fields.**

It made two changes:
- It set the kept trace's arrival incidences to `sourcePort := removed.port`.
- It rewrote the removed trace's junction incidence as `(kept, Terminal)`.

Both break the producer's conventions:
- In production, `incidence.sourcePort` is always the origin port of the incidence's own trace.
- A junction lists only traces that leave a node together, all with role Interior.

No reader reads `sourcePort` except the event sort (`:2847`) and the digest (`:5714`). So the ownership would be invisible to every topology reader. CB-200 would have had to learn an unwritten convention: a Terminal incidence whose port differs from its trace's port means arrival ownership.

The amended diff:
- leaves every `sourcePort` as the producer writes it;
- erases the removed trace from the junction;
- drops a junction left with fewer than two departures, which is the producer's own rule;
- keeps ownership only in the returned `{arrivalTrace, arrivalPort}` binding.

CB-199B must store that binding as an explicit product field on the kept trace, include it in the digest, and have CB-200 read it.

The test now expects the arrival incidences unchanged and the junction removed. A remap that writes the port into the events fails its event equality.

**J5 — Removing a trace leaves a gap in the trace ids. That is safe, under three conditions for CB-199B.**

Why the gap is safe:
- Every reader of the finished network finds a trace by id (`find_trace`, `EmbeddedGraphTopology.cpp:2091`).
- The validator compares against a fresh canonical recomputation (`:5828`), so it sees the same gap.
- The digest hashes the trace count and ids (`:5614`). It changes only where traces are removed, which is intended.
- The polyline output uses list position (`FieldAlignedNetworkPolylines.cpp:79–145`). It is visualization only.

What CB-199B must do:
1. **Run the selection after the tracing loop.** The positional `candidateTraces[existingTraceIndex]` subscripts at `:4824–5053` must all be finished first.
2. **Re-sort events and incidences** with the producer's comparator, because the remapped trace ids change their order.
3. **Apply every pair, or none.** If any pair fails, publish nothing.

**J6 — Not yet shown on row 652.** The receipt did not print whether any trace stops on traces 3, 8, 9 or 11. The struck-reference branch is covered only by the unit guard until CB-199B runs. If CB-199B fails closed on row 652, its error will say so.

## TB-EXEC-178 rules (frozen)

1. **Code:** the amended CB-199A on top of CB-198 source `6cdd23a1…`.
2. **Manifest:** `gates/Architecture_M6_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Case_Manifest.tsv`.
   - SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed`, 1002 rows.
   - The first 1001 rows are TB176/TB177 `0f85400f…4642`.
   - Membership 1083.
3. **Required result:** 995 PASS. Row 1002 is executed and PASSes. The same 7 rows are RED.
4. **Comparison:** compare against TB177 `14871900641` under N1–N3.
   - The new test and the include are appended at EOF, so **no** assertion-line moves are allowed.
   - The row 652/656 receipts must be byte-identical to TB177's.
   - Any other difference means STOP.

## Turn sequence

1. CB-199A, amended: compile only.
2. TB-EXEC-178.
3. TB-REV-178: freeze CB-199B. It covers:
   - an explicit `arrivalPort` field on the kept trace, with digest and equality;
   - the selection call after tracing in `canonical_field_aligned_traces_and_events`, applying every pair or none;
   - a re-sort of events with the producer comparator;
   - a fail-closed error on a missing path or a failed remap.

   Then a TB. Row 652 is predicted to move past A2a, possibly to a CB-200 reader error.
4. CB-200, then a TB: the port-set readers (`GlobalTopologyPlan.cpp:503`, `:2115`; `EmbeddedGraphTopology.cpp` 1793) read `trace.port ∪ trace.arrivalPort`, plus the every-region-owns-a-face assertion. Expected: the seven controls go green, and row 652 has 2 regions.
5. Row 979, Branch A, CB-190.

Still open: CollinearOverlap/EndpointTouch (E5).

## Lessons

- A diff that inserts lines mid-file moves every later assertion. Freeze the line-move allowance from the insertion point, never "none expected".
- Record a new ownership relation as an explicit field. Do not overload an existing field whose producer meaning differs: readers cannot see the change.
