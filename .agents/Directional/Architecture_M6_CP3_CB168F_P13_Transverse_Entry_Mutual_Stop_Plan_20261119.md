# CB168F, CB168G and TB146 — transverse entry contact: mutual stop at an edge point (frozen by RA-267)

## Situation

[RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc) withdraws the definition-only successor `M6-CP3-DEFN-P13-SYMMETRIC-TRANSVERSE-ENTRY-EDGE-BINDING`. The symmetric rule it asked for already exists and is accepted, and the record shape it asked about follows from the producer's existing struck-index formula. This plan freezes three turns:

- two narrow Code + Build turns, each an exact patch and compile-only;
- one Test + Benchmark that witnesses both on the sphere.

Apply the patches in order.

- **Precheck before CB168F:** `git diff --quiet d43d07dd1564be90bc1a89775b17b524d4e83039 HEAD -- src include tests`, so the product is unchanged since CB168E.
- **Before CB168G:** the CB168F result.

## Background — what is already decided

- **The symmetric rule.** `field_aligned_contact_termination_decision` (`SurfaceCellTracing.h`) maps `Inconclusive` to `{true, true}`. The producer calls this "the frozen symmetric case: both traces terminate there", in the pending/pending key comment and in the wall-shortening comment of `field_aligned_publish_contact`. EC3 reuses that rule. No seniority tie-break is involved.
- **The record.** A terminating trace names the struck trace's segment by `secondPendingSegmentIndex` or `firstPendingSegmentIndex`, taken before any commit.
  - In a one-sided stop, the struck trace later commits that segment, and CB168D's `carrier_contact_struck_position` validates its entry.
  - In a mutual stop at the entry, neither trace commits, so each index equals the other trace's segment count, which is its end.

  No new binding type is needed. The consumer only has to accept "both ends at one locus".
- **The real consumer gap the TB145 Review missed.** Cut-edge arcs are split only at `crossingByKey` points, which are trace crossings, in `build_arcs` (`orderedPoints`). A mutual stop on a selected cut edge has no crossing, so the edge would pass by the contact node unsplit. CB168F splits the edge there.

## Exact patches

| Turn | Patch | SHA-256 | Numstat |
|---|---|---|---|
| `M6-CP3-CB168F-P13-MUTUAL-CARRIER-CONTACT-CONSUMER` | [diff](Architecture_M6_CP3_CB168F_P13_Mutual_Carrier_Contact_Consumer_Exact.diff) | `1239c09d217078a753764d0bc244991b75be852bab3ea91d29062e117fb1bc1c` | `64 3 src/geometry/EmbeddedGraphTopology.cpp; 15 1 src/geometry/EmbeddedGraphTopology.h; 70 0 tests/FieldAlignedCurveNetworkTests.cpp` |
| `M6-CP3-CB168G-P13-TRANSVERSE-ENTRY-MUTUAL-STOP` (EC3) | [diff](Architecture_M6_CP3_CB168G_P13_Transverse_Entry_Mutual_Stop_Exact.diff) | `4555af7c88d96cafae2feca72a503735fbcd218629f88dfe20126fc151596aa9` | `89 6 src/geometry/SurfaceCellTracing.cpp` |

### CB168F — consumer, inert

- **Pure helper `carrier_contact_is_mutual(ending, struck)`.** It returns true when:
  - each trace's record names the other at the other's end (`struckSegmentIndex == other.segments.size()`);
  - both loci are equal and interior;
  - each record's face is its trace's last segment face;
  - that segment leaves through the locus edge without a slide.
- **`build_cut_node_bindings`.** A mutual record must have `event.sourceEdge == carrier`; otherwise it returns the existing typed `InvalidCutGraphBinding`. It is not put into `carrierContacts`, because both incidences are Terminal and keep the existing end rule. On a selected cut edge, the contact node goes into `syntheticCrossings` with key `{carrier, lower trace id, its segment count}`. It does not go into `crossingByKey`, because no trace crosses there. It needs no new node id and no extent change.
- **`build_arcs`.** The cut-edge `orderedPoints` iterate `syntheticCrossings`. That set equals `crossingByKey`'s (parameter, node) pairs, since both maps are filled together or the build fails, plus the mutual nodes. The existing strict-order check fails closed if a third trace crosses at the same parameter.
- **Inert.** No producer sets `carrierLocus` yet. Every new branch needs such a record, and the iteration change is set-equal.
- **New test `FieldAlignedCarrierOccupancy.MutualCarrierContactNamesEachTraceAtItsEndOnOneLocus`.** It checks both orders true and same-trace false. Its negative controls are:
  - struck trace continuing;
  - index before the end;
  - other parameter;
  - other face;
  - other exit edge;
  - a slide;
  - a vertex locus.

  Extents: `TraceId` indices 0 and 1 of 2.

### CB168G — EC3 producer switch

- **Predicate.** In the pending/pending loop, immediately after the EC1 receipt, all of these must hold:
  - `first_field_aligned_carrier_contact(firstProposal, secondProposal)` has a value;
  - both slide flags are false;
  - the proposals' faces differ;
  - `field_aligned_compare_priority_arrivals(priority, firstRuntime.arrival, secondRuntime.arrival, …) == Inconclusive`.

  This is the census's `inconclusive/different` pair, exactly as narrow as the record.
- **Contact enqueued.** The Contact event has `secondIsProposal`, ordering `Inconclusive`, key `min` of the two entry keys, and `carrierLocus = {carrier, parameter}`. The loop then continues, so no ProperCrossing classification runs for that pair.
- **Publish.** When `carrierLocus` is set, a terminating trace does **not** commit its proposal. Its record comes from `field_aligned_carrier_stop_contact`:
  - last segment face;
  - the locus's barycentric there;
  - the struck trace and its pre-commit index;
  - the locus.

  With no last segment, a different exit edge or a slide, it fails closed with `InvalidNetworkEventBinding` on the locus edge.
- **Event `sourceEdge`.** The existing lambda reads each terminating trace's `segments.back()`. Both last segments leave through the carrier, so `field_aligned_common_carrier` returns it, which CB168F requires.
- **Unchanged.**
  - Pending/wall entry coincidences: receipt only. A committed wall would need shortening to `k`, not `k+1`. There is no witness.
  - Conclusive transverse entries: no fixture in the census. They stay on the existing path and in the receipt.
  - Same-face entries (BunnyRandom, `later/same`): O48.

### Compile falsifiers

The Review ran `-fsyntax-only -Wall -Wextra -include iterator` (`-include iterator` works around a pre-existing missing `<iterator>` in `SourceChartTransitions.h`). Warning counts with both patches applied, all equal to HEAD, with 0 errors:

| File | Warnings |
|---|---|
| `SurfaceCellTracing.cpp` | 43 |
| `EmbeddedGraphTopology.cpp` | 22 |
| `GlobalTopologyPlan.cpp` | 24 |
| `SurfaceCutGraph.cpp` | 27 |
| `FieldAlignedCurveNetworkTests.cpp` | 42 |

`git apply --check` passes in order. Each Code + Build compiles the eight RA-245 GMP/GMPXX targets with `runtimeExecution=false`. Stop on any precheck, apply, compile or package-hash failure.

## Frozen `M6-CP3-TB146-P13-TRANSVERSE-ENTRY-MUTUAL-STOP-FULL-GATE-EXEC`

- **Inputs.**
  - Immutable CB168G package.
  - Manifest `gates/Architecture_M6_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Case_Manifest.tsv`, SHA-256 `aa9911870a7514ea5674f869e74d8681f1ad0fcc8a14f43096b8da4f5210b61f`. It is the TB144 manifest plus row 962, the new test in `directional_surface_cell_producer_tests`, 962 gated + 81 deferred.
  - Unchanged 3-row census and harness.
- **Partition.** Let **S** be the rows whose TB145 log has an `entryCoincidence` line with `faces=different`, the sphere witness rows. TB145 counted 20; list them.
- **Comparison against TB145, N1–N7 as frozen (N3 per TB131).**
  - Every gate row not in S, and all 3 census rows: exact MATCH, including raw `entryCoincidence`, `slideProposal` and `committedSlide` lines.
  - Rows in S: the `entryCoincidence` lines stay byte-equal, because the receipt is printed before the switch. Everything else is enumerated, not matched.
- **Required (STOP on failure).**
  - Row 962 PASS and row 961 PASS.
  - 491/491 accepted prefix PASS. Any outcome change in rows 1–491 stops the turn, even for a row in S.
  - Cylinder PASS/288.
  - BunnyRandom first failure unchanged (trace 82).
  - No line containing the `M3_CP4AB_FRAGMENT_DIAG` prefix twice.
- **Predictions, routed to Review (not STOP).**
  - **(0,2) cut edge.** No `EmbeddedGraphTopology.duplicateCutCrossing` on (0,2) at `574181338608147/4503599627370496` in any row of S. If one remains, the pair was met at the pending/wall site and CB168G did not fire. Report it with the trace states.
  - **Sphere first failure.** Its stage, code and typed locus, before and after, per row in S.
  - **Row 393:** still PASS (24 traces, contact termini > 0).
  - **Row 648:** asserts `ASSERT_FALSE(sphere.plan.has_value())`, so it turns RED if the sphere plan now succeeds. That is a premise test, and the Review decides it.
  - **Row 858:** report its new terminal stage and locus, and whether `:155` now passes.
  - **Rows 644, 698, 699:** report-only rows. Note any changed printed outcome.
- **Census for the next freeze (raw, per row in S).** For traces 4, 6, 15 and 19, report:
  - final segment count and terminal kind;
  - `terminalContact` (face, struck, index, locus);
  - the `TraceIntersection` event's node, `sourceEdge` and roles.
- **Successor.** `M6-CP3-TB146-P13-TRANSVERSE-ENTRY-MUTUAL-STOP-FULL-GATE-REV` adjudicates S and row 648. It then freezes the next exact turn: CB168 binding, or the next sphere blocker the census shows.
