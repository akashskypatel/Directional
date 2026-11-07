# M6-CP3-CB1-ENTRY-R4 — R3 A4 route-rejection identity-to-source inventory

**Boundary:** Same unfinished Code + Build turn. This is a static recovery inventory, not a current runtime test, a new acceptance selector, or a claim that any historical case now passes. RA-51's two retired unreachable negatives remain retired; all source-side fail-closed guards remain in place.

## Frozen authority and exact inspected source

- Frozen historical observation: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv`; use **`CP2_ACCEPTED_RECOMPUTED`**, not the provisional CP2 column of the older `R3_Red_Classification.tsv`. Of 94 R3 RED entries, filter exactly `observed_first_failure_class=A4_ROUTE_CERTIFICATE_REJECTION` (39 entries).
- Current source: branch `agent/surface_cell_quad/p5-recover-bridge-healing`, exact snapshot/event SHA `d2381fc3118c953b44d7d8756b291fc1919f6b3c`; [snapshot workflow 38474829579](https://github.com/akashskypatel/Directional/actions/runs/38474829579), source artifact `11853417605`, outer ZIP SHA256 `9f9bfb6ecc38e6f9831e1535f60ed97629ae10e09abce30b6e30a9b825073c6f`, inner `source.tar.gz` SHA256 `cf87bb7d13e099c839241b2004612535c3b33447029235d95cf9c0800ad72066`; `SHA256SUMS` checked **5756/5756**, metadata says `runtimeExecution=false`.
- Enumerate current C++ `TEST`/`TEST_F`/`TEST_P` identities across `tests/**/*.cpp`; match each frozen identity exactly once and record its current start line and any of nine explicitly recognized *direct lexical* fixture calls. A missing direct call means **indirect/delegated**, not no producer path. For the historical predicate hint, parse only the frozen `first_diagnostic` text. No current binary, test/benchmark, or discovery command was invoked.
- Machine-readable 39-row mapping: `Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv` alongside this document; each row's status is `STATIC ONLY — current result unknown`.

## Results that the evidence supports

| Historical/static measure | Exact count |
|---|---:|
| Frozen R3 RED identities in overlay | 94 |
| Historical `A4_ROUTE_CERTIFICATE_REJECTION` identities | **39** |
| Unique current-source `TEST` identities found | **39/39** |
| Historical first diagnostic explicitly contains `predicate=endpoint-0` | **38** |
| Historical route-rejection classification without that literal | **1** |
| Independently recomputed `CP2_ACCEPTED_RECOMPUTED=true` within these 39 | **37** |
| Same column false (new CP3 identities) | **2** |
| Current `tests/SurfaceCellTransitionQuotientTests.cpp` entries | **19** |
| Current `tests/SurfaceCellsPhase10Tests.cpp` entries | **18** |
| Current `tests/SurfaceCellREPackageTests.cpp` entries | **2** |
| Entries with no direct recognized fixture-helper call inside the test body | **23** |

The lone historically route-classified case without a literal `endpoint-0` is frozen ordinal **150**, `SurfaceCellAuthorityContractCutover.RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent`: its recorded R3 text reports downstream `produced[0]/produced[1]` false and empty region counts rather than a recorded endpoint predicate. Do **not** assign the same root cause merely because its review class is `A4_ROUTE_CERTIFICATE_REJECTION`.

The two cases with independent recomputed CP2 acceptance **false** are frozen CP3 ordinals **2** (`M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`) and **6** (`M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`). They are part of the 39 R3 historical failures, but not part of the **37** accepted-CP2 regressions represented by this particular subset. They must not inflate the 88 accepted CP2 losses.

## Source-exact producer and next-verdict boundary

The current `build_surface_cell_network` in `src/geometry/SurfaceCellTracing.cpp` builds A3-bound hard-feature carrier transitions, consumes a producer-owned `hardRailTerminalContacts` map, and calls `endpoint_certificate` before `publish_phase_front_result`. Its route-local first rejection still distinguishes source-corner contact, A2b terminal star, rail-carrier orientation and A3 path. Its current predicate set was modified repeatedly after the frozen R3 run (RA-49/50/51); **frozen R3 first predicates are historical observations, not current failures**. The present test fixture and code can be statically located, but compile-only evidence cannot decide which historical case now passes.

The previous focused Phase10 static census (`Architecture_M6_CP3_R4_Phase10_R3_RED_Source_Atlas_Static_Census_20261011.md`) correctly isolates 18 indirect route-certificate cases inside its 52 Phase10 RED cases. This inventory is **not** a reclassification of those 52; it extends identity mapping to **all 39 frozen R3 route-certificate cases** across three translation units and separates the two CP3 non-CP2-accepted cases and one downstream-only diagnostic. It does **not** identify a verified new production defect or authorize a source repair by conjecture.

**Actionable next boundary:** In the separately authorized immutable artifact-only test turn, compare each of these 39 exact identities with its current organic result, preserve first rejected predicate and producer-source provenance, investigate the 38 formerly `endpoint-0` cases without assuming they still share one defect, and account for the 37 prior CP2 accepted cases separately from the two new CP3 entries. For the one downstream-only case, obtain a genuine first-predicate result before grouping. The complete frozen selector (497 identities), CP2 491/491, R3 403/497, 94 RED, 88 accepted losses, ledger 66/17/49 and debt 1 remain unchanged. No TB497, successor turn, runtime acceptance, or R4 completion is authorized by this inventory.
