# CB168D, CB168E and TB145 — carrier-contact edge-node binding and arrival receipt (frozen by RA-266)

## Situation

[RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc) replaces the prose EC2b plan the TB144 Review froze here (git history keeps it). It freezes two narrow Code + Build turns as exact patches and one Test + Benchmark covering both. Apply in order; each is compile-only.

Precheck before CB168D: `git diff --quiet e0f085eb65ed186bf836305f2896c69c6c90c519 HEAD -- src include tests` (product unchanged since CB168C). Before CB168E: the CB168D result.

## Background — exact patches

| Turn | Patch | SHA-256 | Numstat |
|---|---|---|---|
| `M6-CP3-CB168D-P13-CARRIER-CONTACT-EDGE-NODE-BINDING` (EC2b) | [diff](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Exact.diff) | `cf726ced720530467d4d36552fa19880196473a9e5856c0d0408aacb406de8de` | `89 9 src/geometry/EmbeddedGraphTopology.cpp; 14 0 src/geometry/EmbeddedGraphTopology.h` |
| `M6-CP3-CB168E-P13-ENTRY-COINCIDENCE-ARRIVAL-RECEIPT` | [diff](Architecture_M6_CP3_CB168E_P13_Entry_Coincidence_Arrival_Receipt_Exact.diff) | `674184224a4a96dadaefce0be997b75ee03e36414af9062fc87ccd70f5b71dc0` | `34 7 src/geometry/SurfaceCellTracing.cpp` |

- **CB168D (EC2b), the consumer.** A carrier contact is a trace that ends with `terminalContact->carrierLocus`. It ends on that source edge, at the point where the struck trace enters segment k.
  - **Not a face contact.** `face_contact_nodes` skips a `TraceIntersection`/`TraceSelfClosure` whose Terminal incidence carries a locus. Before this change, `collect_face_contact_nodes` would cut the struck trace at `{k, 0}` through `trace_segment_contact_parameter`. That is a second node beside the crossing `{k, ∅}`, which yields a zero-length arc. With the change, `build_node_loci` gives the node the edge locus from `event.sourceEdge`.
  - **Validated record.** `build_cut_node_bindings` validates each record:
    - `carrier_contact_struck_position` (row 961) must return `{k, ∅}`;
    - `event.sourceEdge` must equal the locus edge;
    - one node takes one binding.
    Any failure returns the existing `InvalidCutGraphBinding`, with trace, struck trace and edge set. The result is published as `CutNodeBindings::carrierContacts`.
  - **Cut-edge merge.** When the carrier is a selected cut edge, the struck trace's crossing `(edge, struck, k)` keeps the contact's network node instead of a cut-created one. The extent counts only cut-created crossings. `syntheticCrossings` also holds the merged node, so `edge_ray` parameter lookup and node loci still find it.
  - **Non-cut edge.** No crossing exists, and the contact node alone is the cut point for both traces.
  - **Struck position.** In `build_arcs`, the struck trace's non-terminal incidence at that node takes position k from the binding, not from `trace_event_position`. The terminating trace keeps the existing rule (its end).
- **CB168E, the measurement EC3 needs.** The EC1 receipt keeps its text and gains two fields: `firstArrival=earlier|later|inconclusive faces=same|different`.
  - `firstArrival` orders the first end's arrival at the shared entry against the second's. It uses `field_aligned_compare_priority_arrivals` with the active priority, the same rule that decides contacts:
    - for a pending proposal, the arrival is `runtime.arrival`;
    - for a committed wall segment, it is `segmentStarts[k]`.
  - `faces` compares the two entered segments' source faces.
  - EC3 needs both fields: the later trace is the one that terminates, and `different` is the transverse predicate.
- **Inert by construction.** No producer sets `carrierLocus`. Every CB168D branch requires a record with a locus, and the extent change subtracts an empty set. CB168E changes only diagnostic text, which N7 deletes.
- **No new test.** A `FieldAlignedCurveNetwork` cannot be hand-built (RA-248), so `face_contact_nodes`, `build_cut_node_bindings` and `build_arcs` cannot take an injected record. Their arithmetic is the accepted helper (row 961). The wiring is first witnessed by EC3's TB on the sphere.

## Assessment — compile falsifiers

Each Code + Build compiles the eight RA-245 GMP/GMPXX targets with `runtimeExecution=false`. The Review ran `-fsyntax-only` with no errors and these warning counts, all equal to base:

| File | Warnings |
|---|---|
| `EmbeddedGraphTopology.cpp` | 22 |
| `GlobalTopologyPlan.cpp` | 24 |
| `SurfaceCutGraph.cpp` | 27 |
| `FieldAlignedCurveNetworkTests.cpp` | 42 |
| `SurfaceCellTracing.cpp` | 43 |

The two patches stack on HEAD (`git apply --check` in order). Stop on any precheck, apply, compile or package-hash failure.

## Recommendation — frozen `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-EXEC`

- **Inputs.**
  - Immutable CB168E package.
  - Unchanged TB144 manifest `gates/Architecture_M6_TB144_P13_Carrier_Contact_Struck_Position_Full_Gate_Case_Manifest.tsv`, SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949` (961 gated + 81 deferred).
  - Unchanged 3-row census and harness.
- **Comparison against TB144.**
  - All 964 records (961 gate + 3 census) must match under N1, N2, N4 and N7 as frozen, and N3 exactly as defined in the TB131 Review.
  - Raw `slideProposal`/`committedSlide` lines must be byte-identical.
  - Delete the suffix from ` firstArrival=` to the end of each `entryCoincidence` line. Per row, the remainder must equal TB144's lines as a multiset: 240 gate lines in 20 rows, 6 census lines.
  - Every receipt must end with exactly one `firstArrival=` value and one `faces=` value.
- **Required outcomes.**
  - Gate 960/961, with row 961 PASS.
  - 491/491 accepted prefix.
  - Row 858 RED at `SurfaceCellTracingDisplayTests.cpp:155`.
  - BunnyRandom first failure unchanged (trace 82).
  - Cylinder PASS/288.
  - No line containing the `M3_CP4AB_FRAGMENT_DIAG` prefix twice.
- **Census for the EC3 freeze (raw, enumerated, not adjudicated).** One table row per deduplicated pair and fixture, with:
  - first and second (`t:s`), carrier and exact parameter;
  - `firstArrival` and `faces`;
  - whether the same log has an `EmbeddedGraphTopology.duplicateCutCrossing` on that carrier at that parameter, which shows whether the carrier is a cut edge there (merge path) or not (standalone node path).

  Predictions are routed to Review, not STOP:
  - the sphere pairs `4:7/6:7` on (0,2) and `15:7/19:7` on (25,27) are `faces=different`;
  - the BunnyRandom `15/43` pairs are `faces=same`;
  - a `firstArrival=inconclusive` on a `different` pair means EC3 needs a symmetric rule.
- **Successor.** `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-REV` freezes EC3, the transverse producer switch, as an exact patch. It carries these obligations:
  - the later trace (by the receipt's ordering) does not commit the proposal that enters at the locus, and ends at its previous segment's end;
  - its `terminalContact` holds `{its last segment's face, that point, struck trace, k, carrierLocus}`;
  - the `TraceIntersection` event's `sourceEdge` equals the locus edge (CB168D rejects anything else);
  - the predicate is `first_field_aligned_carrier_contact` with both slide flags false and `faces=different`;
  - same-face merges are left to O48 (CB171/CB172).
