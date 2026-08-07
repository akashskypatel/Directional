# Gate 3 Periodic Cylinder Output Validation — Code + Build Plan

## Turn boundary

This is a **Code + Build** turn only. Production/test source may change and approved targets may be configured/compiled/linked. Execute no generated Directional binary, unit test, benchmark, `ctest` discovery, CLI, GUI, help, or list command. Use `PRE_TEST` or an equivalent compile-only-safe discovery configuration.

## Required declaration before editing

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: a Produced periodic phase-front must materialize its cut-quotiented annular cells into a source-authoritative completed quad mesh that passes the existing pre-optimization validation without shortcutting canonical source-strip structure; row-order invariance must be compared in canonical source identity rather than DCEL edge numbering
Smallest general implementation change: preserve canonical annulus source-strip breakpoints in periodic lattice/materialization, choosing deterministic per-strip subdivisions nearest the target size so output sides do not bridge source topological corners, while retaining exact periodic holonomy quotient and one accepted cell -> one quad; separately correct the row-order contract test to compare ordered canonical source-edge endpoint keys instead of raw sourceEdge IDs
Observable material-progress condition: exact cylinder remains Produced with the same valid periodic authority and reaches zero completed-checkpoint validation failures/direct CompletedSurfaceCells output, while plane, seam, and close sheets remain strict-valid deterministic regressions; the row-order test passes by canonical endpoint identity without weakening its holonomy invariants
Explicitly deferred work: torus/general genus, singularity topology and G4 completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, scheduler timing, and unrelated historical completion/simplification failures
```

## Runtime authority entering this turn

Artifact-only validation of exact source `56f823273cad041a01ebb4d0772c3265ff248f4a` using artifact `9001168379` established:

- artifact SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- recursive checksums **44/44**;
- no rebuild or source/test/fixture/validator/build edit during Test + Benchmark;
- plane: `Produced`, 64 strict-valid quads, hash `730caeae49ec872c`, deterministic 3/3;
- seam: `Produced`, 64 strict-valid quads, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets: `Produced`, 200 strict-valid quads in two isolated components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder: authoritative `Produced`, periodic holonomy `r=0`, `t=(29,0)`, route-edge count 32, cut-edge count 4, 290 completed quads, 319 provenance vertices, **two completed-checkpoint validation failures**, deterministic 3/3;
- cylinder terminal state: `completion/output-validation:AggregateCompletionValidationFailure`, no fallback/recovery;
- focused/retained producer contracts: **11/12 passed**; the only focused failure compares row-dependent raw DCEL edge IDs even though canonical endpoint routes and cuts are identical.

The exact two individual `SurfaceFinalValidationReport` threshold failures are not serialized by the benchmark record. Do not guess them and do not broaden the turn into diagnostic instrumentation unless a minimal in-memory observation is essential to the planned structural correction.

## Bounded implementation objective

Preserve the now-working periodic topology/holonomy authority and correct the earliest remaining constructive defect: direct periodic materialization must respect canonical source-strip breakpoints on curved annular topology.

### 1. Preserve the proven G3 authority

Do not replace or bypass:

- source-topology-derived annulus applicability;
- deterministic intrinsic source cut;
- first-class periodic holonomy `(Z4 rotation, Z2 lattice translation, ordered source route)`;
- exact artificial-cut pairing through periodic ownership;
- typed authoritative rejection;
- exact periodic quotient identity;
- one accepted phase-front cell → one output quad;
- terminal behavior after `Rejected`.

The cylinder must not return to generic `NotApplicable`, fallback, source-grid recovery, or proximity-based seam handling.

### 2. Make periodic lattice columns source-strip-conforming

The current periodic producer chooses a global periodic count from `round(period / target)` and can place lattice columns across source-ring corners. Replace that assumption with canonical source-strip-aware subdivision.

General requirements:

1. Use the already derived ordered canonical annulus source rings/strip structure.
2. Treat every canonical source-ring strip boundary as a mandatory intrinsic lattice breakpoint.
3. Determine a positive integer subdivision count for each source strip from its intrinsic transported length and the local target-size field.
4. Use a deterministic rule such as nearest positive integer subdivision to the target metric, with deterministic tie-breaking from canonical topology; do not use fixture IDs, expected totals, hard-coded 16/29 values, face-row numbering, or arbitrary subset search.
5. Build cumulative periodic lattice coordinates from those strip-local counts. The total periodic translation is the sum of the strip subdivisions and therefore remains an exact integer holonomy translation.
6. Ensure the duplicated cut column remains the exact periodic counterpart of the first column under that translation.
7. Preserve source-face/barycentric provenance for every generated chart point/side.
8. Ensure one materialized quad side cannot skip a mandatory canonical source-strip breakpoint.

If the active source topology cannot produce a reciprocal strip-conforming chart, fail closed with the existing or a narrowly justified typed periodic reason; do not weld or repair afterward.

### 3. Preserve axial construction and genuine boundaries

Do not introduce a second periodic direction. Keep the two genuine annulus boundary loops authoritative. Axial subdivisions may continue to follow the existing target-size construction unless direct inspection proves they violate the same source-strip contract; avoid unrelated refactoring.

### 4. Materialization contract

`build_authoritative_phase_front_mesh()` or its periodic input must receive lattice cells whose corners/sides already respect source-strip breakpoints. Materialization remains a direct projection of accepted authoritative cells, not a topology-repair stage.

Prohibited:

- splitting/merging output cells after materialization;
- Euclidean seam welding or nearest-point matching;
- post-hoc snapping across source corners;
- validator threshold relaxation;
- synthetic validation success;
- fixture/count/name special cases.

### 5. Correct the row-order regression expectation

`SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` currently compares raw `sourceRouteEdges` and `cutSourceEdges` integer IDs from two independently constructed DCELs. Those IDs depend on first halfedge encounter and legitimately change when source face rows are reversed.

Correct only this structurally invalid expectation:

1. For each mesh independently, map every route/cut source-edge ID through its authoritative EV table to a canonical endpoint key `(min(v0,v1), max(v0,v1))`.
2. Compare the **ordered endpoint-key sequences** between the original and row-reversed cases.
3. Continue to compare grid dimensions, holonomy rotation, lattice translation, route/cut cardinality, disposition, and other semantic invariants already asserted.
4. Do not sort away route order, weaken the comparison to set membership/counts, or encode the current implementation output as a golden sequence.

This is a fixture/assertion correction justified by the contract's explicit allowance for canonical renumbering; production code must not normalize DCEL IDs merely to satisfy the test.

## Minimum compile-verified regression source

Compile, do not execute, coverage that protects:

1. source-topology annulus applicability;
2. canonical endpoint-route/cut row-order invariance;
3. artificial-cut periodic pairing without an exterior seam;
4. typed malformed-holonomy rejection;
5. exact committed cylinder producer boundary and existing direct design acceptance;
6. plane, seam, and close-sheet mandatory regressions;
7. a focused structural assertion, if needed, that periodic chart columns retain every canonical source-strip breakpoint without relying on committed fixture counts.

Do not weaken the existing cylinder acceptance test. It must still require direct source-authoritative pure-quad success at runtime in the following Test + Benchmark turn.

## Compile gate

Configure and compile the approved seven-target surface-cell closure:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

Use Release static/Ninja/`PRE_TEST` or the equivalent established compile-only configuration. Execute no generated project binary.

## Artifact requirements

Package an immutable next-turn artifact containing:

- exact pushed source commit and changed blob IDs;
- source patch(es);
- five executables and two project libraries;
- required production fixtures including plane, seam, close sheets, cylinder, bunny, and vase;
- configuration/build logs and toolchain metadata;
- command-boundary metadata proving `runtimeExecution=false`;
- recursive checksums and outer SHA-256.

Every temporary compile workflow must upload a separate detailed diagnostic log artifact under `if: always()`. After artifact/log verification, remove the bounded workflow, trigger, and payload. Retain only approved durable workflows.

## Following artifact-only acceptance

The next Test + Benchmark turn must use the exact new artifact without rebuilding.

### G3 closure

Cylinder remains authoritative `Produced` and becomes direct deterministic strict-valid `CompletedSurfaceCells` pure-quad output with:

- zero completed-checkpoint validation failures;
- correct periodic holonomy and exact artificial-cut quotient;
- complete source provenance;
- no false periodic exterior seam;
- no fallback/recovery;
- deterministic structural/output hashes;
- plane, seam, and close sheets retained as passed direct regressions;
- corrected row-order contract passing by canonical endpoint-route identity.

If these conditions hold, G3 closes and the next design gate is G4 topology-distinct completion and singularities.

### G3 remains open

If the source-strip-conforming producer reaches a new exact structural/validation failure, preserve the evidence and address only that general failure in the next Code + Build turn. Do not broaden to later gates.
