# M6-CP3-CB1-ENTRY-R4 — frozen R3 RED Phase10 ingress census (static, 2026-10-11)

**Authority / boundary:** Code + Build static inspection only, never runtime acceptance. Canonical turn remains `M6-CP3-CB1-ENTRY-R4`, open; successor UNKNOWN. PR #8 remains draft. Exact inspected source snapshot `fa03f13298c1ade7b46ba6bf4ca515c9831409ed`, workflow `38128171689`, artifact `11698695005`, outer ZIP SHA-256 `7ddb4a33b46f9d8a2d8aab372ad78ca27030a9fc027b05503d8e8bfd309d1e9e`; inner source archive validated and **6,132 / 6,132** manifest entries checked. `runtimeExecution=false`.

## Method and limits

Crosswalk `Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv` frozen R3 RED identity strings to all C++ `TEST(...)` identities in `tests/SurfaceCellsPhase10Tests.cpp` at this exact snapshot; delimit by the next `TEST` macro and count literal direct call sites. This is a **static lexical census**, not a compilation, invocation, or proof of producer acceptance. The overlay is the authoritative recomputed CP2 acceptance column; do **not** substitute the provisional `CP2_ACCEPTED` column in `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`.

- Frozen R3 baseline: **94 RED**; **52** of those identities occur in this translation unit, and each of these 52 is `CP2_ACCEPTED_RECOMPUTED=true` in the independent overlay. The other **42** belong to other sources/owners and are not adjudicated here.
- R3 first-failure classes among these 52: **22** `A4_NOT_PRODUCED_UNTYPED`, **18** `A4_ROUTE_CERTIFICATE_REJECTION`, **12** `A4_INVALID_FINAL_CELL_STATE`.
- Current test-body syntax for these same 52: **21** call `build_phase10_with_source_atlas` without a direct raw builder call; **1** calls both it and a direct builder; **1** calls a direct builder only; **29** call neither directly because they use wrapper/delegated production. **Do not infer success from the direct-call census for the 29 indirect identities.**

## The two direct-builder cases: original-source A3 already provided

1. Frozen ordinal **247**, `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`: its two direct `build_surface_cell_network` invocations share `options.fieldTransportAtlas` produced from `build_source_topology_regions(mesh.F, options)` and `FieldTransportAtlas::make(mesh, ..., crossField)` **before** the selected route transition is deliberately modified. The independent A3 authority is not copied from the mutated input. Source site around `tests/SurfaceCellsPhase10Tests.cpp:4660-4742`.
2. Frozen ordinal **199**, `SurfaceCellPhaseFrontFieldChartAuthorityMigration.PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero`: the direct bounded-disk builder uses `make_curved_disk_fixture()`, which calls `bind_curved_disk_atlas()` and sets `fixture.options.fieldTransportAtlas` from the original mesh and cross-field around lines `2410-2503`. Its cylinder branch separately calls `build_phase10_with_source_atlas` around `5298`.

The 21 helper-only identities use the source-atlas helper (definition around line `5319`). A3 ingress for these 23 test bodies is now explicitly threaded; **this does not prove their original failures are cured**, especially the twelve final-cell-state errors, and does not license changing checked-factory optionality.

## The 29 indirect cases and next actionable boundary

The indirect set includes **18** `SurfaceCellAuthorityContractCutover` frozen cases (ordinals 404-407, 117, 115-116, 150, 137, 141-143, 139-140, 122, 134, 132, 130) with `A4_ROUTE_CERTIFICATE_REJECTION` in R3. They use fixed-plan hard-rail and/or pipeline fixtures, not an in-body null A3 builder. For example, `build_fixed_plan_rectangular_hard_rail_network` around `6252` already passes its fixture `sourceAuthority`, `fieldTransportAtlas`, `fieldAlignedNetwork`, `globalTopologyPlan`, `globalConformityBaselinePlan`, hard feature edges, and rails. A direct atlas-only edit to those test bodies would not touch the observed route-certificate predicate.

The remaining **11** indirect cases include original-source segment-route and periodic-route helpers. `build_segment_route_network` (around `1310-1335`) independently constructs A2/A3 from `fixture.authoritativeField`, preserving separately mutated/legacy selected tracing fields; `build_periodic_route_network_with_source_atlas` (around `4195-4220`) independently constructs source A2/A3 from a specified original `sourceField`. Inspect each original first predicate and owner before proposing more fixture changes; avoid projecting a helper's correctness onto runtime evidence.

**Bounded next work:** source-authority-proven diagnosis of the 18 route-certificate failures and the full 39 endpoint family; distinguish their 2026-10-09 R3 observations from today's changed A2b producer. Address final-cell-state defects by independent source-specific reasoning, not another blind atlas-injection pass. Multi-carrier/odd-τ and dual-path design decisions remain independently gated. No runtime, no frozen 497 selector execution, no pass restoration, no successor promotion in this census.
