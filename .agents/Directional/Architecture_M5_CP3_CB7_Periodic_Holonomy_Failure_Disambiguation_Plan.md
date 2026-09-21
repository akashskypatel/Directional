# M5-CP3-CB7 Periodic-Holonomy Failure Disambiguation Plan

**Turn:** `M5-CP3-CB7`
**Boundary:** **Code + Build / runtime-free**
**Input:** reviewed R5 candidate source lineage; accepted runtime authority remains package `10601978228` / selector430 **430/430**
**Purpose:** distinguish the still-collapsed same-region periodic-promotion failure without changing production semantics
**If compile/package green:** exact successor `M5-CP3-TB1-R6-EXEC`

| Goal | Required change | Verification | Stop condition |
|---|---|---|---|
| G1 — expose the active periodic-promotion boundary | append typed failure reasons for generator-route unavailability, action-correspondence mismatch, and each existing `SurfacePeriodicHolonomyErrorCode`; replace only the three same-region generic `PeriodicHolonomyMismatch` emissions | static diff proves no producer decision predicate/value changed; existing enum numeric values stay unchanged; new values append after 49 | any fix requires changing route selection, face authority, action math, relation identity/factory semantics, or acceptance expectations |
| G2 — preserve every frozen authority | no fixture, selector430, frozen definition, atlas API/implementation, A3 plan, relation path/action, or debt discriminator changes | selector430/first427 byte hashes unchanged; no test/fixture/selector diff | any selected identity must be weakened, removed, renamed, or given a new semantic expectation |
| G3 — compile/package only | mandatory GMP/GMPXX compile/package all eight standard targets through `agent-compile-reusable.yml` | preflight/build 0/0, explicit GMPXX+GMP link, empty source-status receipts, 28/28 manifest, `runtimeExecution=false` | any generated Directional binary/test/benchmark/discovery process would need to run in CB7 |
| G4 — make R6 falsifiable before runtime | freeze R6 as the same 446-process artifact-only gate; six produced failures must identify the active new typed branch while mechanism/focused/selector surfaces remain unchanged | R6 plan/caller consumes only immutable CB7 candidate; exact-one, zero skips, benchmark 0, immutable postflight | diagnostics still collapse to old generic reason, or more than diagnostic labeling changed |

## 1. Authorized source scope

Only these production files may change:

1. `include/directional/geometry/SurfaceCellTracing.h`
2. `src/geometry/SurfaceCellTracing.cpp`

No test-source edit is required: the existing six produced identities already report `surface_phase_front_failure_reason_name(...)`, so a typed reason reaches R6 evidence without changing any test expectation. No `RemeshPipeline` diagnostic plumbing is required for the discriminator because the six produced rows expose the phase-front reason directly.

Append, without renumbering values 0-49, typed reasons equivalent to:

- generator route unavailable;
- periodic action correspondence mismatch;
- holonomy construction zero translation;
- holonomy construction missing generator route;
- holonomy construction missing cut route;
- holonomy construction invalid relation identity.

Names may follow existing project naming conventions, but their one-to-one meaning must be explicit in the source and `surface_phase_front_failure_reason_name(...)`.

## 2. Surgical implementation rule

At the same-region hard-rail promotion site only:

- if `generator_route_for_span(...)` returns no value, emit the generator-route-unavailable typed reason;
- if `periodic_action_for_pair(...)` returns no value, emit the action-correspondence typed reason;
- keep the existing rotation equality assertion semantically unchanged; if retained as a defensive check, route it to action-correspondence mismatch rather than inventing another category;
- if `SurfacePeriodicHolonomy::make(...)` returns `SurfacePeriodicHolonomyError`, map its existing exact error code one-to-one to the corresponding appended phase-front reason;
- do not change the returned disposition, locus fields, pairing, route, action, insertion, relation ID, or any surrounding predicate.

The old `PeriodicHolonomyMismatch` reason remains valid at all unrelated existing call sites. CB7 is diagnostic disambiguation, not a global error-taxonomy migration.

## 3. Pre-committed R6 interpretation

R6 must run the unchanged semantic gate: **9 mechanism + 1 focused atlas + 6 produced + 430 selector = 446** fresh exact-filter processes.

The next Review interprets the six produced rows as follows:

- **generator-route-unavailable:** inspect `M5-CP3-TB1-R5-REV-OBS-01`; only then may a later CB test whether transition incidence must come from exact A3 carrier `sourceEdgeFaces` rather than A4 `SurfaceTracePoint.face` values;
- **action-correspondence mismatch:** inspect branch rotation / lattice endpoint correspondence; do not touch generator-route face authority merely because it is statically suspicious;
- **zero translation:** preserve the frozen zero-translation prohibition and inspect which same-region cut copies/lattice coordinates are being paired;
- **missing route / missing cut route / invalid relation identity:** stop and reconcile the observed contradiction with the already non-empty checked route inputs and relation factory contract before any repair;
- **old generic `PeriodicHolonomyMismatch`:** diagnostic cutover failed or a different call site owns the endpoint; no semantic repair is authorized.

No R6 result can promote the candidate or discharge produced debt without its mandatory independent Review.

## 4. Build/package acceptance

CB7 must call `.github/workflows/agent-compile-reusable.yml` for exactly the standard eight targets:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

GMP policy is mandatory. No generated Directional runtime, test, benchmark, discovery/list/help/version command, CLI, fuzzer, or custom input may execute. Package evidence must retain exact source identity, command boundary, GMP/GMPXX link proof, clean source-status receipts and recursive self-excluding manifest.

## 5. Prohibitions

CB7 must not:

- change selector430 or first427;
- change any test body, fixture, benchmark or required-green expectation;
- change `generator_route_for_span` inputs or face selection;
- change atlas value/traversal semantics;
- weaken hard-feature barriers;
- change periodic action computation;
- change `SurfacePeriodicHolonomy::make`, `PeriodicRelationId`, relation insertion or zero-translation rejection;
- promote a package, discharge debt, or alter stable accounting;
- infer the active branch from static source rather than leaving R6 to falsify it.
