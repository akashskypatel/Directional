# M4-CP3-CB9 Derivation Guard Record

**Turn:** `M4-CP3-CB9`
**Status:** G1/G2/G3 GREEN BEFORE PRODUCT MUTATION
**Inspection snapshot:** `f8005cca5d93a504dfe403370b9747170d532b35`
**Frozen semantic predecessor:** `104b8e3e3821bd6438aed140c5b75377ad34223e`
**Runtime execution:** none

## G1 — ordinal138 exact bounded-disk path — GREEN

Static proof from exact current source and frozen fixture bytes:

- `make_square_mesh()` is exactly two faces `(0,1,2)` and `(0,2,3)`.
- The fixture supplies user hard edge `{0,2}`. This is the sole shared source edge, so A1 barrier partitioning yields two one-face regions.
- Each region has `V/E/F=3/3/1`, `chi=1`, and three boundary support edges.
- `RemeshPipeline.cpp` builds and binds A2b `GlobalTopologyPlan` and A3 `GlobalConformityBaselinePlan` before tracing, assigning both pointers to `SurfaceCellTracingOptions`; the incident hard edge therefore makes `useAcceptedCutDomain=true` for each region.
- The baseline builder publishes one incidence for each oriented A2b region-boundary arc. For this one-face triangular region the accepted boundary therefore materializes exactly three total segments, each sourced by a canonical source-edge path.
- Current `SurfaceCellTracing.cpp` validates those segments and then intercepts `acceptedSegments.size() < 4U` as `Rejected/InvalidFrontBoundaryAuthority` before the common bounded-disk gate `boundaryEdgeKeys.size() < 4U || boundaryAdjacency.size() < 4U`, whose default result is `NotApplicable`.
- This exactly explains selector403 ordinal138's accepted `UnsupportedSourceSheetTopology` contract being shadowed by CB8.

No G1 premise failed.

## G2 — row408 remains a distinct cut-open torus occurrence-domain case — GREEN

Static proof from the committed `benchmarks/fixtures/milestone-g/torus.obj` and frozen row408 hard-edge bytes:

- Raw torus support is exactly `V/E/F=72/216/144`, `chi=0`, with no boundary/non-manifold source edge.
- The frozen cycles are `0-3-25-37-49-61-0` and `0-1-4-6-8-10-12-14-16-18-20-22-0`: 6 + 12 = 18 unique source edges, all present in the mesh; the cycles share only source vertex 0 and no edge.
- Cutting face-corner connectivity across those 18 edges yields the accepted occurrence domain `V/E/F=91/234/144`, `chi=1`, one 36-edge degree-2 boundary loop. Thus the reduced/cut support is a disc while the raw source remains a torus.
- The cut therefore has 18 two-sided interior barriers and necessarily preserves distinct opposite cut copies/repeated source-vertex occurrences through A4 chart construction and A3 pairing.
- Row408's accepted cut boundary is not a `<4` small-domain case: two independent generator cycles produce four cut sides and 36 boundary edge occurrences. The CB9 cardinality correction cannot disable accepted-cut occurrence handling for it.

No G2 premise failed.

## G3 — semantic disposition partition — GREEN

The following remain authority failures and must stay `Rejected/InvalidFrontBoundaryAuthority`: topology/baseline digest mismatch; missing/ambiguous region, incidence, arc, or source-path binding; invalid carrier/source-face ownership; contradictory incidence orientation, schedule, span, or boundary continuity; inconsistent/non-disc accepted topology authority; occurrence collapse; exact A3 pairing/provenance contradiction.

Only a fully validated accepted boundary whose cardinality is below the curved bounded-disk producer's minimum chart size is `NotApplicable`. Aggregate hard-feature dispatch remains fail-closed: all three producers declining still publishes `UnsupportedSourceSheetTopology` and does not authorize legacy fallback.

The minimal safe seam is therefore to remove the premature accepted-boundary `<4` rejection and let the existing accepted-cut validation finish. Valid three-segment regions then reach the later common `<4 => NotApplicable` gate, while every typed invalid-authority check remains in place. Row408 has >=4 sides and follows its existing occurrence-domain path unchanged.
