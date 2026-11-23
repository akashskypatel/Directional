# TB-REV-172 — second adversarial continuation: shared-edge root cause (2026-11-23 UTC)

Continues turn `M6-CP3-TB-REV-172-P13-ALONG-EDGE-VISIT-REGION-RECEIPT-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md) and the [first adversarial continuation](Architecture_M6_CP3_TB_REV_172_Adversarial_Review_20261123.md).

This turn was runtime-free. It used:
- source reading;
- an SHA-checked read of TB172 artifact `14805479282` (ZIP `e9ddc7fd…3edbc`, Haiku extraction, `raw/652.log:118`);
- `git apply --check` and `clang++ -fsyntax-only`.

## Verdict

- **Upheld:** the TB172 rejection: 987/994, with the same seven mechanical controls RED.
- **Withdrawn:** CB-194 `…-CO-CARRIER-INTERVAL-IDENTITY-RECEIPT`, in both its independent and its first-adversarial form. Its only possible outcome is already decided by printed data (C1), so running it would print an answer that is already known (RA-235, the TB-REV-170 A1 pattern).
- **Root cause moved upstream, to A2a.** The lenses are exactly co-traced zero-area digons. DESIGN already assigns this case to the network producer (C3), and that producer violates DESIGN. Region election, the region reader and CB-192 are correct to reject it.
- **Replaced by:** an exact CB-194 **shared-edge oracle**. It is a pure authority-layer helper with tests, unwired, and works whichever way D13 is decided (C5). It is followed by TB-EXEC-173 on a 996-row manifest.
- **Open user decision: D13.** It was asked in this turn and not answered, so it is *pending*, not deferred (RA-240). It must be re-asked at the start of TB-REV-173.

## Findings

**C1 — Exact co-tracing is decided by elimination.** There are four premises, all printed or code-enforced:
1. **Arcs 0–13 have `trace=none` and orbits 0|0.** Each trace arc 14–25 is one whole trace (12 arcs for 12 traces). So the face walk of lens orbit o ∈ {1, 3, 4, 5} contains only the reverse darts of its two trace arcs. Each lens is a **digon**, and its two traces share both end nodes.
2. **Consecutive visits share exactly one vertex** (checked for all 8 traces over the 58 receipt rows):
   - orbit 1: 10→11→17→23→29→35;
   - orbit 3: 10→79→77→75→73→47;
   - orbit 4: 35→95→94→93→92→71;
   - orbit 5: 47→46→53→59→65→71.

   So every middle visit enters and leaves at the two ends of its printed edge.
3. **`exact_source_path_is_canonical`** (`ExactSourcePath.h:159`) rejects zero-length pieces and requires continuity. A second (trailing) piece in a visit therefore starts on the printed edge and ends at the exit vertex, so it stays on that edge.
4. **The end visits run from the shared end node** (for trace 0, `traceOrigin=10` is printed) to the first transition vertex, along the printed edge.

So each pair covers exactly the same edge intervals in opposite directions. The lenses have zero area.

The first continuation's A1 (trailing pieces) and A3 (ambiguous edge) are excluded by premises 2 and 3. Two distinct points determine at most one closed edge.

**C2 — The independent review's "H-strip refuted" was right; its "intervals undecided" was not.** The first continuation weakened a correct conclusion and enlarged a receipt that could not change it.

**C3 — The owner is A2a, not the region contract.**
- DESIGN requires:
  - "terminate each trace on first contact with an existing trace" (§4.6:163, and :439–443);
  - "every required singularity port is owned exactly once" (:449–450);
  - "the count of traces per grazing edge is an observation the stage must publish" (§4.5:158).
- The canonical producer breaks all three:
  - It seeds one trace per port with no arrival check (`SurfaceCellTracing.cpp:4302–4306`).
  - It skips every contact except `ProperCrossing`, so `CollinearOverlap` and `EndpointTouch` are dropped (`:4640–4700`, `:4740–4780`).
  - It records only the *origin* port in the `SingularityTermination` incidence, so the arrival port is lost (`:2279–2341`).
  - It publishes no per-grazing-edge count.
- So the "region-contract decision" framing (TB-REV-171 B4, TB-REV-172 independent) is withdrawn. Do not skip sourceless drafts, credit opposite faces or merge arcs in the embedded graph: each of these hides an A2a breach downstream.

**C4 — The earlier green was wrong output, and the tests could not see it.**
- TB169's mechanical plan had 6 regions, 4 of them zero-area lenses that owned real faces through the false chords CB-192 removed.
- The mechanical tests (`FieldAlignedCurveNetworkTests.cpp` 10529–10696) check region count ≥ 2, orbit ↔ region agreement and anchor uniqueness. None of them requires every region to own a source face.
- After the A2a repair the plan should have 2 regions (orbits 0 and 2). The repair CB must add the "every region owns ≥ 1 source face" assertion.

**C5 — CB-194 (exact).**
- It adds `exact_source_piece_edge_interval` and `exact_source_paths_shared_edges` to `ExactSourcePath.h`. These return the source edges that two exact paths both run along for positive length, in either direction, carrier-independently (a face piece along an edge counts the same as an edge piece).
- Two tests:
  - a co-traced chain built from mixed carriers, plus a partial overlap;
  - negative controls: touching at a point, a crossing chord, and an interval read from a corner-to-edge face piece.
- It is the falsifier for every D13 option. It is also the measure DESIGN §4.5 requires. It stays unwired here.

**C6 — My TB-EXEC-172 rule 2 was defective.** It allowed only the appended receipt fields and forgot the existing lesson (RA-247) to allow diff-proven assertion-line moves. The five +87 shifts are exactly the CB-193 insertion at line 8077, which precedes all five sites. They are comparator noise, not behaviour. The verdict is unchanged, because the seven REDs are real. From TB-EXEC-173 on, rules allow line moves proven by the diff.

**C7 — Mandatory edges are not involved.** A mandatory arc along a lens chain would split the digon and give arcs 0–13 lens orbits. They are all 0|0.

## D13 — user decision (pending)

What should happen when a trace arrives at a singularity along one of that vertex's own port directions?
- **A — arrival owns the port (recommended).** One trace per saddle connection. This is canonical and independent of order. It needs the arrival port recorded.
- **B — head-on mutual stop.** Not canonical: the meeting point depends on tracing progress.
- **C — merge downstream.** Hides the A2a breach.
- **D — drop empty regions.** Leaves zero-area faces in the graph.

## TB-EXEC-173 rules (frozen)

1. The manifest is `gates/Architecture_M6_TB173_P13_Shared_Edge_Oracle_Full_Gate_Case_Manifest.tsv`:
   - SHA-256 `b54de0b28dc646b465daae0d40dd7874f550567fb904647c7dff36a4f2e2ff6e`, 996 rows;
   - TB171's 994 rows plus rows 995 and 996;
   - prefix `483f1101…038` unchanged;
   - membership 1077.
2. Required result: 989 PASS. Rows 995 and 996 PASS. The same 7 RED (445, 652, 653, 656, 658, 660, 786).
3. Every other row must equal TB172 `14805479282` under N1–N3, plus assertion-line moves that the CB-194 diff proves. The tests are appended at the end of the file, so no moves are expected. Any other difference: STOP and return to Review.
4. No census and no repair.

## Turn sequence

1. **CB-194:** the exact oracle, compile only.
2. **TB-EXEC-173:** the rules above.
3. **TB-REV-173:** re-ask D13 first. Then freeze the A2a repair as two CBs (RA-249).
   - **CB-195**, helpers: the arrival-port record and the "no two traces share an edge" premise on the mechanical network, using the CB-194 oracle.
   - **CB-196**, wiring: apply D13 in the canonical producer, and add the regions-own-faces assertion (C4).
   - Each CB is followed by its TB.
4. Row 979, then Branch A, then CB-190, as before.

## Lessons

- Before a receipt prints intervals, check whether the face walk (digon), shared-vertex transitions and the canonical-path rules already decide them.
- When a consumer rejects a degenerate configuration, look first for the producer whose contract the configuration breaks, before calling it a consumer-contract decision.
