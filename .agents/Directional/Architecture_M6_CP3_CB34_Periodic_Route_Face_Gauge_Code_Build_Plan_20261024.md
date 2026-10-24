# CB34 plan — restore valid periodic-route face gauge (2026-10-24; amended by RA-150)

**Turn:** `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR`. **Boundary:** test-only Code + Build in `tests/SurfaceCellsPhase10Tests.cpp`; compile only, no binary/test/benchmark execution. **Authority:** [TB34-REV](Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md) classification, with the transformation **as corrected by** [RA-150](Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md) §3. Where they differ, RA-150 governs.

## Exact scope

1. **`balanced_periodic_route_field` → representation gauge** g(face1)=+1 on one `CrossFieldResult`:
   - Locate the gauge face by route topology (`expectedRoute[0].targetFace == expectedRoute[1].sourceFace`, else `throw`). Locate its three interior edges by topology.
   - **Precondition:** the original directed matching on each is 0, else `throw`.
   - **Transitions:** add g(to)−g(from), giving +1 into face 1 and −1 out of face 1 on all three edges. Keep any populated compact `matching` entry consistent. `effort` is unchanged.
   - **Frame:** relabel the gauge face's `primaryDirections`, `secondaryDirections` and `rawField` row by the quarter turn that shifts A3 `rawGauge` by +1. The expected form is `p'=−s, s'=p`, `u'_k=u_{k−1}`; confirm it with oracle (2).
2. **New test** `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.BalancedRouteFieldIsPureFaceGauge` (outside selector 497). It asserts:
   - A3 `make` succeeds on the gauge field;
   - `branch_topology().semantic_digest()`, `frames()` and `transports()` equal those of A3 from the unedited `authoritativeField`;
   - raw `transition_value` is +1 / −1 / −1 on the three directed face-1 steps;
   - the two-edge-only construction rejects with `CycleTransportMismatch`, `site=cycle-transport`, LocalVertex.
3. **Unchanged:** the seven frozen test bodies, all other helpers, `build_periodic_route_network_with_source_atlas` call arguments (source == tracing for positives), production code, selectors and workflows.

## Compile-only gate

Exact-source GitHub Actions compile of the eight standard GMP/GMPXX targets: `runtimeExecution=false`, clean source, manifest and checksum receipts. Write `Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Record_20261024.md` (≤30 lines). Successor: CB34-REV, then TB35. Do not merge CB and TB.

## Stops (return to Review; never loosen assertions)

- A face-1 edge has a nonzero original matching, or a route step is not +1 / −1 after the gauge.
- No relabel direction makes oracle (2) hold on paper. Report it; do not pick the variant that compiles.
- Any change needed to `sourceField` selection (RA-150.2 prohibition), to A3/A4 production, or to a frozen test body or selector.
- Source SHA, package or checksum discrepancy.
