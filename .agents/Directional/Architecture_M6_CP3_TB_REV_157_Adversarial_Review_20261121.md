# TB-REV-157 — adversarial review continuation (2026-11-21 UTC)

**Turn:** `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`, continued after handover to the review agent. This record does not create a separate turn.
**Boundary:** runtime-free. Only `git apply --check`, `-fsyntax-only` and reads of immutable artifacts were run. No product, test or selector source is changed by this record.

## Situation

The TB157 gate verdict stands: 975/975 PASS, rows 1–972 MATCH TB156 under N1–N3 with an empty allowance, census 3/3 under N1–N4.

This review independently re-read the TB157 artifact `14719149475`:
- ZIP SHA-256 `9609b0e0…4d11` and 1958/1958 internal checksums match.
- The ledger is 975/975 PASS, and rows 973–975 PASS.
- No log names the four guards (`RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge`, `FirstPieceNotLeavingLocusIntoFace`, `RotationEdgeRayCountInvalid`).
- There are 564 `slideContactArrival` lines, all `wallCommitted=1 movingArrival=later`: 141 for each of the four sphere contacts. The TB-REV-157 V3a/V3b split is also right. My TB-REV-156 V3 asked one unwired helper to be reached by the full rotation builder, which cannot happen until a producer publishes the node.

The frozen successor, CB-174 v3 (`684d53d6…7d238`, a `later_entry_stop_on_committed_slide` helper), is **withdrawn**. It rebuilds an existing producer function. It cannot express a configuration the receipts have already observed. Its test also demonstrates a wall split that the production consumer would reject.

## Findings

**W1 — the helper duplicates the existing carrier-stop path.**
- Lines 49–55 and 84–93 of the v3 helper repeat `field_aligned_carrier_stop_contact` (`SurfaceCellTracing.cpp:4089`) guard for guard: same last segment, same `outgoingCarrier`, same no-slide-exit check, same `sourceFace`/barycentric/`carrierLocus` construction.
- The producer already turns "this trace arrives later at a carrier locus" into a stop. A `FieldAlignedQueueEvent` with `carrierLocus` is applied by `field_aligned_publish_contact` (`:4137`, `:4169`). That function records `struckTrace` and `struckSegment`, committed or proposal, and applies `field_aligned_contact_termination_decision`.
- The stop switch therefore needs only a predicate and one queued event at the slide-contact sites. A second terminal-contact builder is not needed.

**W2 — the helper's domain excludes an observed configuration.**
- The helper indexes `wall.segments[wallSegmentIndex]`, so it accepts only a committed wall.
- The TB149 census includes BunnyRandom contact `26:1/99:0` with `wallCommitted=0`, `later`. That contact is a pending wall at the pair loop (`:4549`).
- The event path covers both cases through `secondIsProposal`.
- The sphere's four contacts (`17:8/0:6`, `20:8/1:6`, `5:8/21:6`, `8:8/22:6`, each `wallCommitted=1 later`, 564 lines in TB157) come from the committed-wall loop (`:4637–4700`).

**W3 — the binding consumer was missed, and it is the real first stage.**
- `build_cut_node_bindings` (`EmbeddedGraphTopology.cpp:441–455`) resolves every non-mutual carrier contact through the entry-only `carrier_contact_struck_position`. A stop inside a wall slide would fail there with `InvalidCutGraphBinding`.
- `CarrierContactBinding` stores no parameter. `build_arcs` (`:1865–1889`) cuts the struck trace only at `TraceCutPosition{segment, nullopt}`, a segment boundary.
- `carrier_contact_slide_position` (`:880`) has no production caller. The v3 test calls it by hand, so it demonstrates a split that production would reject.
- The arc side is ready: `TraceCutPosition::parameter`, `trace_cut_segment_range` and `exact_trace_piece_path_between` already handle slide cuts (CB168L/CB168P tests).

**W4 — the ordering policy at a slide contact is Later-only, by evidence.**
- Existing semantics: Earlier lets the moving trace continue; Later stops the moving trace; Inconclusive stops both (`SurfaceCellTracing.h:762–770`).
- Inconclusive at a slide contact cannot reuse the active-wall shortening branch (`:4180–4210`). That branch keeps the whole struck segment, so the slide past the contact would survive.
- Every measured slide contact is `later`: 564 sphere lines in TB157 and 5 BunnyRandom census lines in TB149. Earlier and Inconclusive are never observed.
- The producer switch therefore acts only on Later, at a strict slide interior. Earlier and Inconclusive keep today's behavior (dropped, still printed by the receipt), so the switch is no wider than the evidence that justifies it.

**W5 — the patch was not in the repository.**
- The v3 bytes lived only in a Drive file. The review downloaded them (SHA-256 verified), and they apply to HEAD. The syntax check agreed with HEAD: one pre-existing local `std::inserter` include error and the same 42 warnings.
- Exact successors are frozen as repository `.diff` files with preimage and postimage hashes. No external store is used.

## Frozen successor — CB-174 (consumer first)

`M6-CP3-CB-174-P13-SLIDE-CONTACT-CUT-BINDING`. Code + Build, compile only. Apply exactly [the frozen diff](Architecture_M6_CP3_CB174_P13_Slide_Contact_Cut_Binding_Exact.diff).

Diff SHA-256: `236290050270f19b56d849915cfb727a87551477d0be726ac294fd0603fe1c44` (11,629 bytes). It applies to HEAD with `git apply --check`. Under Homebrew clang 23 `-fsyntax-only`, both translation units give 0 errors, with the same warnings before and after (22 and 42).

| File | numstat | Preimage | Postimage |
|---|---|---|---|
| `src/geometry/EmbeddedGraphTopology.h` | +13/−1 | `592daad7b202ff866f9f0175b790b5d71262d9f447a4895860237d4a8d899da5` | `3a6103e2746304bec45716be3c5d4b968d66755a93e102ee623e46ac0e02d900` |
| `src/geometry/EmbeddedGraphTopology.cpp` | +37/−13 | `1ef094afe1a0917c07a67c2d95fcb53f00330e8fc240a8b40c8547110bf64de7` | `2bb4b7464fa60af7ed0b62018967ad84db125f224e489115c0b5cc7ea53206c8` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | +77/−0 | `20a11166bb1a29a3689baf2e1c6aa8bb0a230d9b94e627b9200a56e276a8824c` | `e840b2aa64458f2d56c7dc39db3297c50f83e58b94da01c071dbd0e238083217` |

TB158 manifest: [976 rows](gates/Architecture_M6_TB158_P13_Slide_Contact_Cut_Binding_Full_Gate_Case_Manifest.tsv), SHA-256 `6a37e4612a6b463eac3de4b5da4ed86f5bba52ac54bfbb1e472ca7508b7caf0f`, 146,384 bytes. Rows 1–975 are byte-equal to TB157, and row 976 is the new test in `directional_surface_cell_producer_tests`.

Behavior:
- `carrier_contact_cut_position` returns the entry position, otherwise the slide-interior position.
- `CarrierContactBinding::struckParameter` carries the slide fraction, and `build_arcs` cuts the wall at `{segment, struckParameter}`.
- A slide contact on a selected cut edge fails closed with `InvalidCutGraphBinding`. That case is unreachable while Amendment 14 withholds slide carriers. The slide-start subdivision turn (R1) owns its replacement.
- Gate effect: entry contacts resolve exactly as before, and no producer emits a contact inside a slide. TB158 therefore uses an **empty allowance**.
- Test: `FieldAlignedCarrierOccupancy.CarrierContactCutPositionTakesTheEntryElseTheSlideInterior` (manifest row 976).
- **Unwitnessed:** the wiring of the binding and arcs is reached only after the producer switch (CB-175). V3b owns that proof.

## TB-EXEC-158 STOP criteria

- STOP unless 976/976 PASS and CP2 491/491.
- Rows 1–975 must MATCH TB157 artifact `14719149475` under N1–N3 with an **empty allowance**.
- The census must match TB157 `14719268782` 3/3 under N1–N4.
- No new `InvalidCutGraphBinding` may appear in any log versus TB157.
- Any difference is a STOP for review.

## Successor obligations frozen for TB-REV-158 (not yet exact)

Producer switch CB-175 must meet all of the following:
1. One shared pure predicate, called from both the committed-wall loop (`:4659`) and the pending pair loop (`:4549`). It holds when the contact is `!movingInSlide && wallInSlide`, the contact lies in the strict interior of the wall slide (reuse `carrier_contact_slide_position`'s fraction rule), and the priority comparison of the moving arrival against `field_aligned_arrival_at_slide_parameter` is `Later`.
2. When it holds, queue the existing Contact event with `carrierLocus`. Do not build a terminal contact.
3. The receipt line `slideContactArrival` calls the same predicate (RA-264).
4. V3b reaching test on the production sphere network:
   - one node per contact with composition `(0,2)` and primaries 0 and 2, plus one into-face ray at `2·side+1`;
   - a same-direction mutation gives `RotationTraceRaysAlongSharedEdge`;
   - the test must fail if the contact event is absent.
5. Per-row predictions for the 21 receipt rows (row 686 χ 6→2, V/E/F deltas) and for BunnyRandom.

## Turn sequence

| Step | Turn |
|---|---|
| NEXT | `M6-CP3-CB-174-P13-SLIDE-CONTACT-CUT-BINDING` (exact diff, compile only) |
| then | `M6-CP3-TB-EXEC-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` (976 rows, empty allowance) |
| then | `M6-CP3-TB-REV-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` (if green: freeze CB-175 producer switch exactly, with V3b and per-row predictions) |
| later | CB-175 stop switch → TB-EXEC-159/TB-REV-159 → slide-start subdivision (R1, deletes the Amendment 14 interim restriction and the selected-cut slide fail-closed) → slide-plan conformity (RA-275 S4a) → O48 |
| withdrawn | `M6-CP3-CB-174-P13-LATER-ENTRY-SLIDE-STOP-HELPER` (v3 `684d53d6…`): W1–W3, W5 |

## Lessons

- Before freezing a stop helper, check whether the producer already has an event path that applies the stop. If it does, freeze only the predicate that feeds it.
- Before freezing a producer change, trace the record to every consumer (binding, arcs) and land the consumer first.
- A test that calls an unwired consumer by hand proves nothing about production. Grep for that consumer's production callers.
