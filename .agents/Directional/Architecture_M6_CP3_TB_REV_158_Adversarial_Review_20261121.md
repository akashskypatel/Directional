# TB-REV-158 — adversarial review continuation (2026-11-21 UTC)

**Turn:** `M6-CP3-TB-REV-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE`, continued after handover to the review agent. This record does not create a separate turn.
**Boundary:** runtime-free. Only `git apply --check`, `-fsyntax-only` and reads of immutable artifacts were run. No product, test or selector source is changed by this record.

## Situation

The TB158 gate verdict stands. Independently checked in this continuation:
- CB-174's three postimage hashes match HEAD, the frozen diff reverse-applies cleanly, and nothing under `src`, `include` or `tests` has changed since package source `5190b0e7…`.
- Gate artifact `14725784889` (ZIP SHA-256 `b50d32d0…54e5`, 976 logs) and census artifact `14727495926` (`5b3012ca…b8bc`, 3 logs) were re-downloaded and their hashes match.
- The normalized 975-row comparison was not repeated. It rests on the TB-REV-158 independent review.

The successor frozen by TB-REV-158, `M6-CP3-CB-175-P13-LATER-SLIDE-CONTACT-STOP-SWITCH`, is **withdrawn**. It was prose, not an exact diff. It handed Review work to a compile-only turn. It also inherited three unmeasured preconditions, one of them a numbering dependence in the evidence that TB-REV-157 W4 (my record) used to justify "Later-only".

## Findings

**T1 — the successor was prose, and bundled four stages into one compile-only turn.**
- It combined a new predicate, wiring at two producer sites, a producer-reaching test (V3b), and per-row V/E/F predictions that the implementation agent had to make "before compiling".
- Predictions are Review work. Exact Euler deltas cannot be derived without the receipts the switch depends on. The text's fallback, "stop for a separate definition", is not a Code + Build exit.
- The implementation agent receives exact diffs only. This continuation freezes them.

**T2 — the pending-pair receipt sees one role only, so the Later-only evidence is incomplete.**
- `reportEntryCoincidence` visits each pending pair once, with the lower trace index as "moving" (`SurfaceCellTracing.cpp:4549`).
- `first_field_aligned_carrier_contact` is role-asymmetric. The accepted test at `tests/FieldAlignedCurveNetworkTests.cpp:21557–21562` shows both outcomes.
- When the higher-index trace enters the lower-index trace's slide, the result is `movingInSlide=1 wallInSlide=0`. No `slideContactArrival` is printed for it. A switch at that call site would stop an entering trace only when its index is lower.
- TB158 census evidence: BunnyRandom prints `slideCoincidence moving=87:0 wall=142:2 … movingInSlide=1 wallInSlide=0 faces=different` three times, with no arrival ordering in any receipt. It also prints `movingInSlide=1 wallInSlide=1` three times.
- **Correction:** TB-REV-157 W4 said every measured slide contact is `later`. That held over one role only.
- The gate (564 lines in 24 rows) shows only `movingInSlide=0 wallInSlide=1 faces=same`.

**T3 — strict interiority is unmeasured, and the frozen rule could not be shared.**
- `field_aligned_arrival_at_slide_parameter` accepts slide ends, so the 579 `later` lines do not show that the entry is inside the wall's slide.
- A Later stop at a slide start would publish a record that the CB-174 consumer rejects with `InvalidCutGraphBinding`. That configuration belongs to slide-start subdivision (R1).
- TB-REV-157 obligation 1 said to "reuse `carrier_contact_slide_position`'s fraction rule". That function is in the cut-graph module, layered above the tracer, so a copy would let producer and consumer drift. The rule now becomes one pure tracer function that both call.

**T4 — the stop-record precondition is unmeasured.**
- `field_aligned_carrier_stop_contact` (`:4089`) builds the stop only when the moving trace's last committed segment leaves through the contact carrier without a slide exit. Otherwise `field_aligned_publish_contact` returns `InvalidNetworkEventBinding`.
- No receipt measures this. Switching first would risk turning a dropped contact into a hard error on gate rows.

**T5 — a pending wall's struck index can dangle (carried).**
- For a pending wall the record names the wall's pending segment index.
- If that wall later stops before entering at a carrier locus, the segment is never committed and the binding fails.
- The switch Review must check every `wallCommitted=0` stop line for this.

## Frozen successors (exact, stacked, compile only)

| Turn | Diff | SHA-256 | Bytes | numstat |
|---|---|---|---|---|
| `M6-CP3-CB-175-P13-SLIDE-ENTRY-STOP-PREDICATE` | [CB-175 diff](Architecture_M6_CP3_CB175_P13_Slide_Entry_Stop_Predicate_Exact.diff) | `9e75cff8cd50a8a4e1f084b69445f982331617b3b3b7e5843dafc0a2cb480a4c` | 15,384 | h +41/−0; tracer cpp +49/−0; EGT cpp +6/−10; tests +151/−0 |
| `M6-CP3-CB-176-P13-SLIDE-ENTRY-ARRIVAL-RECEIPT` | [CB-176 diff](Architecture_M6_CP3_CB176_P13_Slide_Entry_Arrival_Receipt_Exact.diff) (applies on CB-175) | `079161b74780a14e7baa7508a84cc3c27892c7c166c6c9c31bf887ceeb9e5878` | 5,428 | tracer cpp +53/−28 |

File hashes (preimage → after CB-175 → after CB-176):

| File | Preimage (HEAD) | After CB-175 | After CB-176 |
|---|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `bab90bdcd0f566a89b06fa464a9cd5fdc5e005fbfb153926dda26c0d37778fbc` | `9cfc50dc7878618b42c8bae235732b5c420874d85b5ff7d227a3d447e0a32338` | unchanged |
| `src/geometry/SurfaceCellTracing.cpp` | `69b448ea4c4869ff4e327c36fb0ae045fd7a24852a9b550392509d4d12ec6c66` | `5d5c5b56d4547b297b37c09ebd7a2a225433a8a5290d5cc0ceba9a30f3f0d764` | `11ff2fd6fa4b0b6217a3bed42595d1218145d663216999645023c975b8666b7d` |
| `src/geometry/EmbeddedGraphTopology.cpp` | `2bb4b7464fa60af7ed0b62018967ad84db125f224e489115c0b5cc7ea53206c8` | `62750f966d4a2c8c842eb11296a2b9dfae5bf71109aab850cf9d7efa879482cd` | unchanged |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `e840b2aa64458f2d56c7dc39db3297c50f83e58b94da01c071dbd0e238083217` | `0bb3dd65925e8aacc5aab2f97db9774870a60ee438626d365a986052b24280cb` | unchanged |

Syntax check (Homebrew clang `-fsyntax-only -include iterator`): both diffs apply in order (`git apply --check`). With GMP defines, all three translation units give 0 errors on HEAD, after CB-175 and after CB-176. The warning sets are unchanged (3/3/9).

**CB-175 behavior (no production caller):**
- `field_aligned_slide_interior_fraction` is the single strict-interior rule. `carrier_contact_slide_position` now calls it, with identical results; row 976 covers this.
- `field_aligned_slide_entry_contact` classifies an entry crossing onto a wall slide: locus, interior flag, and moving arrival under the active priority.
- `field_aligned_slide_entry_stops_moving_trace` is true only when the entry is interior and the moving arrival is `Later`.
- New test row 977, `FieldAlignedCarrierOccupancy.SlideEntryStopsOnlyALaterEntryStrictlyInsideTheWallSlide`, covers:
  - Later, Earlier and Inconclusive entries, and both priorities;
  - both slide ends;
  - an entry outside the slide;
  - the swapped role;
  - that a producer stop binds in the consumer at the shared fraction (1/3) while a slide-start record does not.

**CB-176 behavior (receipt only):**
- `slideContactArrival` now calls the predicate in **both roles** for every slide coincidence.
- It appends ` movingCommitted=[01] interior=[01] stop=[01] stopRecord=[01-]`. `stopRecord` reports whether `field_aligned_carrier_stop_contact` would build the stop for a pending moving end; it is `-` for a committed one.
- Scheduling is unchanged.

## TB-EXEC-159 STOP criteria

Manifest: [977 rows](gates/Architecture_M6_TB159_P13_Slide_Entry_Stop_Predicate_Full_Gate_Case_Manifest.tsv), SHA-256 `993c663f5e916b4ab5a8d812ebfd658384cbec0b8356cd11e84ea76b0107d63b`. Rows 1–976 are byte-equal to TB158, and row 977 is the new test. STOP unless all of the following hold:

1. 977/977 PASS and CP2 491/491. No new `InvalidCutGraphBinding` or `InvalidNetworkEventBinding` in any log.
2. Every record other than `FieldAlignedCurveNetwork.slideContactArrival` matches TB158 `14725784889` under N1–N3.
3. Per log, the TB158 `slideContactArrival` records map one-to-one, as a multiset, to TB159 records equal to them plus the suffix regex ` movingCommitted=[01] interior=[01] stop=[01] stopRecord=[01-]$`.
4. Every extra TB159 `slideContactArrival` record `moving=X wall=Y` has a `slideCoincidence moving=Y wall=X` record in the same log (the swapped role).
5. Census 3/3 against TB158 `14727495926` under N1–N4, with rules 2–4.
6. The report publishes a receipt table for each row and census case: counts by role, `wallCommitted`, `movingCommitted`, `movingArrival`, `interior`, `stop` and `stopRecord`, plus every distinct line.

Falsifiable predictions:
- Every forward line has `movingCommitted=0`.
- BunnyRandom gains the swapped line `moving=142:2 wall=87:0` three times.
- The gate gains no swapped line, because no gate row prints `movingInSlide=1`.
- No prediction is made for `interior`, `stop` or `stopRecord`. They are what TB159 measures.

## Obligations for TB-REV-159 (freeze CB-177 exactly)

`M6-CP3-CB-177-P13-LATER-SLIDE-CONTACT-STOP-SWITCH` must:
1. At both loops, and in both roles at the pending pair loop, queue the existing Contact event with `carrierLocus` when `field_aligned_slide_entry_stops_moving_trace` holds. Set `firstTrace` to the entering trace and the key to the later arrival. Do not build a terminal contact.
2. Fail closed through the existing `InvalidNetworkEventBinding` wherever TB159 shows `stop=1 stopRecord=0`, or resolve that before switching.
3. Check T5 on every `wallCommitted=0 stop=1` line.
4. Carry the V3b reaching test on the sphere (composition `(0,2)`, primaries 0 and 2, entering ray at `2·side+1`; a same-direction mutation gives `RotationTraceRaysAlongSharedEdge`; the test fails without the event).
5. Carry per-row predictions derived from the TB159 receipt table: row 686 χ 6→2 with V/E/F deltas, and BunnyRandom.

The committed-wall swapped role (a committed entry under a pending slide) and two-slide contacts (`1/1`) are measured by CB-176 and stay out of CB-177 unless TB159 shows them changing a gate row.

## Turn sequence

| Step | Turn |
|---|---|
| NEXT | `M6-CP3-CB-175-P13-SLIDE-ENTRY-STOP-PREDICATE` (exact diff, compile only) |
| then | `M6-CP3-CB-176-P13-SLIDE-ENTRY-ARRIVAL-RECEIPT` (exact diff stacked on CB-175, compile only) |
| then | `M6-CP3-TB-EXEC-159-P13-SLIDE-ENTRY-STOP-PREDICATE-FULL-GATE` (977 rows, receipt-only allowance) |
| then | `M6-CP3-TB-REV-159-P13-SLIDE-ENTRY-STOP-PREDICATE-FULL-GATE` (freeze CB-177 exactly from the receipts) |
| later | CB-177 stop switch → TB-EXEC/REV-160 → slide-start subdivision (R1) → slide-plan conformity (RA-275 S4a) → O48 |
| withdrawn | `M6-CP3-CB-175-P13-LATER-SLIDE-CONTACT-STOP-SWITCH` (prose, T1–T4) |

## Lessons

- Before freezing a switch at a loop that visits each pair once, check whether the classifier it calls is role-symmetric. If it is not, receipt both roles first.
- A precondition the publisher checks (stop-record constructibility) belongs in the switch's receipt before the switch.
- Share a predicate across layers by moving it to the lower layer. Do not tell the producer to "reuse" a consumer function it cannot call.
