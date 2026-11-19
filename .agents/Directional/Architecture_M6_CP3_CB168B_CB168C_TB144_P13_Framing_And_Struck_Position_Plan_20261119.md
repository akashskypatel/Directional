# CB168B, CB168C and TB144 — diagnostic framing and carrier-contact struck position (frozen by RA-265)

## Situation

[RA-265](Architecture_M6_CP3_TB143_P13_Entry_Coincidence_Receipt_Full_Gate_Independent_Review_20261119.md#ra-265--adversarial-re-review-of-this-review-2026-11-19-utc) reclassifies TB143 as MATCH under the frozen N3 and freezes two narrow Code + Build turns, then one Test + Benchmark covering both. Apply in order; each is compile-only. Precheck for both: `git diff --quiet b77a81ff5250aabbf6dd58cf4e9e6c208d4a973f HEAD -- src include tests` (product unchanged since CB168A) before CB168B, and the CB168B result before CB168C.

## Background — exact patches

| Turn | Patch | SHA-256 | Numstat |
|---|---|---|---|
| `M6-CP3-CB168B-P13-REGION-SUPPORT-DIAGNOSTIC-FRAMING` | [diff](Architecture_M6_CP3_CB168B_P13_Region_Support_Diagnostic_Framing_Exact.diff) | `7ec11b82448a3f2c563852a796a6eb3774e5674a625d7f38bf4db6adeaedaf12` | `28 19 src/geometry/GlobalTopologyPlan.cpp` |
| `M6-CP3-CB168C-P13-CARRIER-CONTACT-STRUCK-POSITION-HELPER` | [diff](Architecture_M6_CP3_CB168C_P13_Carrier_Contact_Struck_Position_Helper_Exact.diff) | `f8badfdf09864bb88b9ff4d2a870b8e0ba1b03f57b4513d5dfc0f9f7719ee204` | `4 0 SurfaceCellTracing.h; 21 0 EmbeddedGraphTopology.cpp; 12 0 EmbeddedGraphTopology.h; 7 0 SurfaceCellTracing.cpp; 82 0 tests/FieldAlignedCurveNetworkTests.cpp` |

- **CB168B.** All seven `M3_CP4AB_FRAGMENT_DIAG` emitters in `GlobalTopologyPlan.cpp` build the whole record, newline included, in an `ostringstream` and write it with one insertion. These emitters run on concurrent `std::async` component workers (`RemeshPipeline.cpp:17726`, `:19571`). Before the change, four wrote `out.str()` then `'\n'` as two insertions: TB143 rows 169/477 and TB131 row 179 show a joined record followed by an empty line. The other three wrote 8–10 insertions, so a record from another worker could land inside a record, which N3 cannot absorb. Record text is unchanged.
- **CB168C (EC2a, unwired).** `FieldAlignedTerminalContact::carrierLocus{}` (`{}` avoids 10 `-Wmissing-field-initializers` warnings). The digest hashes it only when present. Pure helper `embedded_graph_topology_detail::carrier_contact_struck_position(struck, record)` (RA-260 S2.4, `wallInSlide=false`): it returns `{k, ∅}`, the boundary before struck segment k, only when all of these hold:
  - `struck.id == record.struckTrace`;
  - the locus is present;
  - k is in range;
  - the locus equals segment k's entry crossing, through the accepted `field_aligned_segment_entry_occupancy`;
  - the parameter is interior.
  Otherwise it returns empty, including for a slide contact (owned by CB171/CB172) and for a vertex.
  - New test `FieldAlignedCarrierOccupancy.CarrierContactCutsTheStruckTraceAtItsEntryCrossingOnly` injects records by hand. It checks one positive case at segment 1, a second positive at segment 0, and seven negative controls: no locus, another parameter, another edge, a segment past the end, another trace, an end vertex, and a point inside a slide. It fails if the helper ignores the parameter, the edge, the trace identity, or the slide/vertex exclusions.
  - The present-locus digest branch is not unit-testable (internal function; networks cannot be hand-built). It is first witnessed at EC3.

## Assessment — compile falsifiers

Each Code + Build compiles the eight RA-245 GMP/GMPXX targets with `runtimeExecution=false`. The Review ran `-fsyntax-only` with no errors and these warning counts, all equal to base:

| File | Warnings |
|---|---|
| `GlobalTopologyPlan.cpp` | 24 |
| `SurfaceCellTracing.cpp` | 43 |
| `EmbeddedGraphTopology.cpp` | 22 |
| `FieldAlignedCurveNetworkTests.cpp` | 42 |

The two patches stack (`git apply --check` in order). Stop on any precheck, apply, compile or package-hash failure.

## Recommendation — frozen `M6-CP3-TB144-P13-FRAMING-AND-STRUCK-POSITION-FULL-GATE-EXEC`

- **Inputs.**
  - Immutable CB168C package.
  - Gate manifest [TB144](gates/Architecture_M6_TB144_P13_Carrier_Contact_Struck_Position_Full_Gate_Case_Manifest.tsv), SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949`: the TB142 manifest plus row 961, so 961 gated + 81 deferred.
  - Census, deferred list and harness unchanged.
- **Comparison against TB143.** Use N1, N2, N4, N7 as frozen, and N3 exactly as defined in the TB131 Review: `M3_CP4AB_FRAGMENT_DIAG` records compared as a multiset of complete records split at the prefix, prefix count equal to record count, non-record remainder byte-equal in order.
  - All 963 prior records (960 gate + 3 census) must match.
  - Raw `slideProposal` and `committedSlide` lines must be byte-identical.
  - Per row, the `entryCoincidence` lines must equal TB143's as a multiset.
- **Required outcomes.**
  - Row 961 PASS; gate 960/961.
  - 491/491 accepted prefix.
  - Row 858 RED at `SurfaceCellTracingDisplayTests.cpp:155`.
  - BunnyRandom first failure unchanged (trace 82).
  - Cylinder PASS/288.
- **Framing check.** No line in either run may contain the `M3_CP4AB_FRAGMENT_DIAG` prefix twice; any such line is a STOP. Absence is weak evidence because the race is rare; presence falsifies CB168B.
- **Successor.** `M6-CP3-TB144-P13-FRAMING-AND-STRUCK-POSITION-FULL-GATE-REV` freezes EC2b (RA-265 S3).
