# TB-REV-159 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-159-P13-SLIDE-ENTRY-STOP-PREDICATE-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB159_P13_Slide_Entry_Stop_Predicate_Full_Gate_Independent_Review_20261122.md). Runtime-free: source reading, the TB159 report/receipt table, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB159 PASS upheld.** CB-175/CB-176 landed exactly. Worktree hashes equal the frozen postimages: `SurfaceCellTracing.h 9cfc50dc…2338`, `.cpp 11ff2fd6…6b7d`, `EGT.cpp 62750f96…82cd`, `tests 0bb3dd65…80cb`.
- **Every TB-REV-158 prediction held:**
  - Gate: 564 forward lines, all `movingCommitted=0 interior=1 stop=1 stopRecord=1`, and no swapped line.
  - Census: 15 → 18 lines, the three new ones `moving=142:2 wall=87:0`.
- **`M6-CP3-DEFN-159A-P13-SLIDE-STOP-OWNERSHIP-AND-REACHABILITY` is WITHDRAWN** (U1). Its answerable items are settled here (U2, U5). Its unanswerable items need a measurement (U3, U4), so this Review freezes the turns that produce that measurement.

## Findings

**U1 — DEFN-159A has no reachable exit (RA-172, RA-257).**
- Item 3 needs a measured exact V3b node composition. Item 4 needs the sphere V/E/F and the BunnyRandom outcome after a switch. Both exist only after the switched producer runs.
- A definition turn cannot run anything. Its own stop clause ("explicitly revise the test expectation and stop for a further review") sends it back to Review, so Review would follow Review.
- Items 1, 2 and 5 are code-reading questions. They are answered below.

**U2 — T5 adds no new lifetime mode, and the existing check fails closed.**
- *The pending reference already exists.* Every accepted ordered pending-pair ProperCrossing already ends the later trace against the other trace's *pending* segment. `field_aligned_publish_contact` sets `struckSegment = secondPendingSegmentIndex` when `secondIsProposal` (`SurfaceCellTracing.cpp`, publish). A slide stop through the same event adds no new kind of reference.
- *Production ordering rules out a dangling record.* Production `make` always uses ArcLengthFiltered (`SurfaceCellTracing.h:616–617`, `field_aligned_production_arrival_priority`), where the event key is the arrival value.
  - The queue is rebuilt every round, and a Contact pops before a SegmentEnd at an equal key.
  - So when the stop with key `k` (the moving trace's arrival) pops, every active proposal ends at an arrival ≥ `k`.
  - Any event that would end the wall before it reaches locus `q` has a key ≤ `t_wall(q)`, which is < `k`. That event is therefore in the same queue and pops first.
  - A later shortening of an active wall on an Inconclusive contact keeps segments up to its own contact. That contact's arrival is > `t_wall(q)`, so the struck segment survives.
- *Backstop.* The consumers reject a struck index ≥ `segments.size()`: `carrier_contact_struck_position`/`carrier_contact_slide_position` (`EmbeddedGraphTopology.cpp:873, :894`) and face contacts (`:1255`). A dangling record becomes a typed binding failure, never a silent graph.
- *Residual.* Under the index-keyed diagnostic priorities (StepCount, TraceSeniority) the sweep argument does not hold. This is the same as for the accepted transverse path, and production never selects them.
- *New conservative guard.* A committed wall's last segment is not a slide wall when the wall ended on a contact, because the wall may stop before `q`. This mirrors the existing `wallTerminalContact` second-exit rule.
- The sphere walls 0/1/21/22 are unaffected: row 971 counts them as slide arc ends, and that count excludes contact-terminated last segments (`tests:17952–17955`).
- *Closed:* T5 is closed by this argument plus the backstop. Runtime witness: the TB160 zero allowance and row 978.

**U3 — the premise-test inventory was missing (RA-228, RA-252).** All 24 receipt rows run the prescribed sphere under the default ArcLengthFiltered priority (two Haiku read-only audits). An unconditional switch would contradict these exact or premise assertions:
- **Row 393:** `tests:17425–17427` (7 segments, struck index), `:17435–17437` (carrier edge literals and parameter), `:17498` (carrier ends `{4,6,15,19}`), `:17499` (2 carrier nodes).
- **Row 648:** `:14141` `ASSERT_FALSE(sphere.plan)`.
- **Row 971:**
  - `:17784` 10 slide pieces; `:17959` the expected slide-trace set.
  - `:18110`, `:18120–18122` slide ends; `:18123` `changedOrdinary==0`.
- **Row 972:** `:15170`, `:15181`, `:15182` (slide carriers never selected; Amendment 14 interim).
- **Row 858:** `SurfaceCellTracingDisplayTests:155–172` (sphere stop face, zero cells).
- **Must hold anyway:** the one-terminal-kind and one-Terminal-event properties `:17405` and `:10666–10668`.

Replacement values for these lines cannot be derived statically. Each stopped trace loses its remainder, which can release other traces.

**U4 — so the switch is staged (RA-230), and activation is frozen from measurements.**
- CB-177 wires the stop behind `stopAtLaterSlideEntry`. It defaults to false and is reachable only through the diagnostic surface `FieldAlignedCurveNetwork::diagnose_with_arrival_priority`.
- Production `make` is untouched, so rows 1–977 and the census must be byte-equal under N1–N3/N4 with a **zero** allowance.
- New row 978 asserts the four derivable stops exactly:
  - moving traces 17/20/5/8 end with 8 segments on walls 0/1/21/22 at segment 6;
  - carriers (6,8)/(16,21)/(33,34)/(45,46) at the row 963 parameters;
  - one TraceIntersection per stop on its carrier, with the moving trace Terminal and the wall Interior;
  - unstaged diagnostic digest == production digest; unstaged moving traces go on, which falsifies a no-op wiring.
- It prints a receipt for what the canonical `SurfaceCutGraph::make` makes of the staged network (V3b reaching), plus the carrier-end set and the slide count that row 393 and row 971 read.
- The deltas are measured, never asserted. The four stops sit at the earliest keys where they differ from the unswitched run, so they are derivable.

**U5 — wiring design checks.**
- The key is the moving trace's arrival, which equals `max` for Later. Later ends only the first trace (`field_aligned_contact_termination_decision`).
- `carrierLocus` makes `field_aligned_carrier_stop_contact` build the record; it was constructible in all 582 receipts.
- `sourceEdge` comes from `field_aligned_common_carrier` of the moving trace's last segment and the wall's slide. The node face is the moving trace's proposal face, as at the Site B inconclusive entry.
- Excluded: committed moving traces (they cannot stop before entering; every receipt has `movingCommitted=0`) and self-contacts.
- In the pair loop the slide-stop event replaces any ProperCrossing classification of the same pair (`continue`), as Site B does.

## Frozen artifacts

| Artifact | SHA-256 | Notes |
|---|---|---|
| `Architecture_M6_CP3_CB177_P13_Staged_Slide_Entry_Stop_Exact.diff` | `4a16ee6fed7587d00b42418f906b48d2f4ee804d473842fbb6201eb3a143bd8b` (16,264 B) | numstat h +6/−1, tracer cpp +70/−5, tests +152/−0. Preimages = CB-176 postimages (`9cfc50dc…2338`, `11ff2fd6…6b7d`, `0bb3dd65…80cb`). Postimages: h `fe567847b74e9a0fed7b31e11a9904277009e08318aa2d6e9122f8dfd96fa05f`, cpp `ec3daee222af178c740279908291407195de5669f753ebc8f75c6c6c1d3052cc`, tests `82a1ec498d7ba7fea877cfeda78aedea9457e0124c124b48c69546892ebba87c`. `git apply --check` OK; `-fsyntax-only` 0 errors, warnings equal HEAD (tracer 43, EGT 22, tests 42). |
| `gates/Architecture_M6_TB160_P13_Staged_Slide_Entry_Stop_Full_Gate_Case_Manifest.tsv` | `d7eb3c355cdc3febd35f20cb8d2178489f8cb6d2aecf1f600ef8dd2b6151ca5a` (146,763 B) | 978 rows; rows 1–977 byte-equal to TB159 `993c663f…d63b` |

## TB160 rules (STOP unless all hold)

1. 978/978 PASS; CP2 491/491.
2. Rows 1–977 raw logs equal TB159 under N1–N3, with no receipt allowance.
3. Census 3/3 equal TB159 artifact `14733451393` under N1–N4, with no allowance.
4. Row 978 passes. Its `SphereStagedSlideEntryStop` receipt line is published verbatim. Prediction: `traces=24`, `slideStops=4`. `events`, `carrierEnds`, `slideSegments` and `cutGraph` are measurements, not predictions.
5. Any failure means STATUS BLOCKED and a return to Review. Do not edit tests or the manifest.

## Turn sequence

CB-177 (staged, compile only) → TB-EXEC-160 → TB-REV-160 → CB-178 → TB-EXEC/REV-161 → R1 slide-start subdivision → RA-275 S4a → O48.
- **TB-REV-160** freezes CB-178 from the row 978 receipt: the production default, deletion of the staging parameter, exact replacements for the U3 lines, and the V3b assertion. If the cut graph fails, it freezes a consumer fix instead.

## Lessons

- Withdraw a definition turn whose remaining items need a measurement. Freeze the staged measurement instead.
- Before calling a lifetime hazard new, find the accepted path that already makes the same reference, and the consumer check that fails closed on it.
- Inventory every premise assertion on the witnessing fixture before choosing between staging and direct activation.
