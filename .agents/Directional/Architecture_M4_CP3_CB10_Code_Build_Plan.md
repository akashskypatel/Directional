# M4-CP3-CB10 Code + Build Plan — migrate accepted hard-rail unit fixture to A2b/A3 authority

**Turn:** `M4-CP3-CB10`
**Type:** Code + Build only; runtime-free
**Owner:** `M4-CP3-TB7-REV-CAND-01`
**Scope:** test authority only
**Accepted runtime authority entering:** corrected R4 package `10289601000`, selector403 **403/403**
**Candidate entering:** CB9 package `10305678151`, rejected/unpromoted after TB7 ordinal211 RED.

## 1. Problem frozen by Review

CB5 intentionally made exact A3 `SurfaceSharedBoundaryInterval` identity mandatory for production hard-rail pairing. The accepted `hard_rail_fixture()` in `tests/SurfaceCellTransitionQuotientTests.cpp` was not migrated: it still calls `build_surface_cell_network()` with manually supplied hard edges/rail but without `GlobalTopologyPlan` or `GlobalConformityBaselinePlan`.

As a result, ordinal211 fails during fixture production with `InvalidHardRailPairing` before reaching its intended reciprocal-`oppositeEdge` tamper oracle. Product behavior is correct under the frozen A3→A4 single-writer contract; the fixture precondition is stale.

## 2. Mandatory pre-mutation guards

All guards are static/source-derived. If any fails, **STOP before mutation or compile and return to Review**.

### G1 — accepted identity and unchanged test bytes

Prove:

1. accepted R4 selector403 ran 403/403 PASS and contains ordinal211;
2. `tests/SurfaceCellTransitionQuotientTests.cpp` is byte-identical across accepted R4, CB5 and CB9/current source (`4372a939...982f25` at Review);
3. selector403/408 identity-list bytes remain unchanged.

### G2 — exact precondition drift

Prove from current source that:

1. `make_hard_rail_fixture()` supplies hard feature edges/authoritative rail but no accepted A2b/A3 plan pointers;
2. `SurfaceSharedBoundaryInterval` is populated only under accepted-conformity authority;
3. global `HardRail` aggregation rejects a hard-rail edge that lacks `sharedBoundaryInterval`;
4. ordinal211 fails before its intended draft tamper when the setup network is not Produced.

### G3 — product contract is intentionally strict

Re-read the frozen M4 definition and prove that production A4 must consume immutable A3 shared subdivision, may not restore floating `support_key`, and may not locally invent or re-solve shared breakpoints. Any proposed product relaxation is a STOP.

### G4 — replacement fixture path is authority-complete

Before editing, identify one existing production-authority construction path that publishes all of:

- retained trace network;
- `SourceTopologyRegions`;
- `FieldTransportAtlas` / field-network authority needed by the production route;
- `GlobalTopologyPlan`;
- `GlobalConformityBaselinePlan`;
- authoritative hard rail(s) for the same 3×3 fixture support.

Preferred minimal route: use the already exercised `remesh_from_raw_cross_field(..., SurfaceCells)` intermediate-product path, with the same 3×3 mesh and user hard edges `(1,4)` and `(4,7)`, fallback disabled, source-grid recovery disabled, and intermediate geometry retained. If this route cannot statically preserve the intended fixture semantics without a second unrelated change, STOP.

## 3. Authorized semantic change

Change only `tests/SurfaceCellTransitionQuotientTests.cpp` as required to migrate the shared `make_hard_rail_fixture()` setup onto accepted production authority.

Preferred implementation:

1. retain the same 3×3 planar mesh and two intended user hard edges `(1,4)` / `(4,7)`;
2. construct those hard edges through the production SurfaceCells pipeline so A2b/A3 products are created by their owning stages;
3. require retained intermediate `traceNetwork` and accepted topology/conformity products before exposing the fixture;
4. use the resulting produced trace network as the shared fixture consumed by the existing quotient/typed-transport tests;
5. delete only manual rail-construction code made unused by that migration.

The six existing downstream identities and their assertions remain unchanged:

- 211 `AmbiguousHardRailCounterpartIsRejected`;
- 217 `ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- 219 `MissingHardRailCounterpartIsRejected`;
- 227 `DuplicateSemanticRouteTopologyFailsClosed`;
- 230 `RouteTopologyTransitionMismatchFailsClosed`;
- 231 `ValidHardRailRouteUsesTypedIdentity`.

## 4. Explicitly prohibited

CB10 must not:

- change production code under `src/` or `include/`;
- restore `support_key` hard-rail pairing or add a no-plan fallback;
- weaken `InvalidHardRailPairing` / `InvalidSharedBoundaryInterval` rejection;
- change A2b or A3 writers, schedule semantics, occurrence identity, or CB8 cut-open authority;
- change CB9's bounded-disc applicability correction;
- change rows404-408 or ordinal138 fixtures/assertions;
- rename, delete, reorder or weaken any accepted selector403 identity;
- change selector403/408 identity-list bytes;
- run Directional tests, benchmarks or generated binaries in this turn.

## 5. Compile/package contract

Use the mandatory reusable compile workflow with GMP/GMPXX. Compile/package exactly the eight unique targets used by the current CP3 cumulative gate:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Required build evidence:

- all eight targets compile/link GREEN;
- GMP and GMPXX are both proven on authoritative link commands;
- source status is empty before/after/final;
- package root manifest is complete and verified;
- source archive identifies the exact semantic source;
- `runtimeExecution=false`.

No runtime acceptance is claimed by compilation.

## 6. Future TB8 gate to freeze in CB10 closeout

CB10 must emit the artifact-only `M4-CP3-TB8` plan. At minimum TB8 must execute, fail-fast and with immutable pre/postflight:

1. the six shared-fixture identities 211/217/219/227/230/231 in focused A and focused B;
2. ordinal138 A/B;
3. row408 A/B;
4. rows404-407 A/B;
5. selector403 cumulative **403/403**;
6. selector408 cumulative **408/408**.

Only TB8 Review may promote the CB10 package or close `M4-CP3-TB7-REV-CAND-01`.

## 7. Success criteria

CB10 is complete only if:

- G1-G4 all pass before mutation;
- diff is test-authority-only and minimal;
- all six identity bodies/names are unchanged;
- selector identity-list hashes are unchanged;
- mandatory eight-target GMP package is compile-green and runtime-free;
- a complete TB8 artifact-only plan is committed;
- no temporary workflow/trigger/Drive staging state remains after closeout.

## Amendment — TB8 execution mode (TB7-REV §11 V3, reviewing agent)

The successor artifact-only turn must execute accepted **selector403 to completion, without fail-fast**, and publish
the complete set of accepted ordinals that go RED under the candidate.

Rationale: fail-fast is what has turned this into a one-defect-per-cycle loop. TB3-TB5 each stopped at row408 before
cumulative selector403 could reach ordinal211, and TB6 stopped earlier still at ordinal138 — five TB cycles, one
blocker each, one full Code + Build plus execution round trip each. The six-consumer census bounds the
`hard_rail_fixture()` vector but not the risk class, which is *accepted identities whose preconditions depend on
applicability or disposition behaviour the A3→A4 cutover changed*.

Fail-fast may be retained for candidate rows 404-408, where clean first-failure attribution is still worth more than
completeness. It is specifically the accepted prefix where completeness is now worth more than early exit.

