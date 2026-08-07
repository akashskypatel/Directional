# Gate 3 Periodic Cylinder / Holonomy — Code + Build Plan

## Turn boundary

This is a **Code + Build** turn only. Source/tests may change and approved targets may be configured/compiled/linked. Execute no generated Directional binary, unit test, benchmark, `ctest` discovery, CLI, GUI, help, or list command. Use `PRE_TEST` or an equivalent compile-only-safe discovery configuration.

## Required declaration before editing

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: authoritative phase/front construction and periodic seam reconciliation on a singularity-free annulus without treating the periodic cut as an exterior boundary or falling back to generic tracing
Smallest general implementation change: extend the uniform authoritative producer with one deterministic intrinsic cut/unwrapped chart for annular source topology, record exact lattice holonomy across that cut, and stitch periodic front counterparts through source-topology/phase equivalence
Observable material-progress condition: exact production cylinder becomes authoritative Produced or reaches a new typed periodic-holonomy Rejected state with zero generic substitution, while plane, seam, and close sheets remain mandatory regressions
Explicitly deferred work: torus/non-annular topology, singularities/topology-distinct completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production/performance, scheduler timing, downstream completion/simplification failures
```

## Current authority

G0, G1, and G2 are closed. Artifact-only G2 validation established:

- plane: direct valid `Produced`, 64 quads, hash `730caeae49ec872c`
- seam: direct valid `Produced`, 64 quads, hash `5bdf34d7802e9fb0`
- close sheets: direct valid `Produced`, 200 quads, two isolated components, hash `89b052762f52a5af`
- cylinder: `NotApplicable`, 732 generic traces, zero arrangement/completion, terminal `NotProductionReady:completion`

Source authority entering this turn is the branch containing implementation source `218dd3ec3f6399dc82183390720a4ba4d3a70b42` plus subsequent documentation-only closeout commits.

## Bounded G3 architecture

The G3 producer covers only a connected, orientable, singularity-free annulus-like sheet with two source boundary loops and one periodic lattice direction. Do not implement general genus or singular topology in this turn.

### 1. Topological applicability

Determine applicability from source topology, not fixture identity or geometry counts:

- exactly one authoritative `(component, localSheet)` work item being processed
- connected orientable manifold sheet
- no cross-field singularity vertices in the active sheet
- Euler characteristic consistent with an annulus
- exactly two source boundary cycles
- current planar rectangular producer is not applicable because the sheet is intrinsically periodic/non-planar

Malformed authoritative topology is `Rejected`; unsupported topology is `NotApplicable`.

### 2. Deterministic intrinsic cut

Construct one source-topology cut connecting the two boundary cycles so the annulus becomes a disk suitable for an unwrapped phase chart.

Requirements:

- select the cut using canonical source topology and field-compatible transport, never world-space nearest projection, face-row order, fixture IDs, or arbitrary subset search
- preserve the ordered source-edge route of the cut
- duplicate chart occurrences only in the unwrapped representation; retain one authoritative source entity identity beneath both sides
- face-row permutations must select an equivalent canonical cut/holonomy except canonical renumbering

### 3. Intrinsic unwrapped phase chart

Propagate the existing reciprocal quarter-turn transport over the cut-open sheet and accumulate local lattice coordinates intrinsically.

Do not require all source vertices to be coplanar in world space. The chart is an intrinsic construction derived from transported local tangent coordinates/source-edge crossings.

Every chart point must retain:

- source face/barycentric provenance
- component/local-sheet identity
- branch rotation/family/sign
- lattice coordinate and phase
- ordered transition route
- whether it lies on either copy of the periodic cut

### 4. Explicit periodic holonomy

Compute and store the transition from one cut copy to the other as first-class periodic holonomy:

```text
quarter-turn rotation r in Z4
integer lattice translation t in Z2
ordered canonical source route
```

For the bounded cylinder producer, accept only holonomy compatible with the singularity-free annular lattice. Non-reciprocal, non-integral, branch-incompatible, missing-provenance, or ambiguous holonomy is authoritative typed `Rejected`.

Add a typed failure reason that identifies periodic-holonomy rejection without falling through to generic tracing.

### 5. Periodic front reconciliation

Do not mark the artificial cut as exterior output boundary.

- pair cut-side front edges through exact source-route and lattice-holonomy equivalence
- require reciprocal family/sign/phase compatibility
- introduce an explicit periodic merge event or equivalently explicit periodic ownership state; do not hide the merge as positional snapping
- preserve the two real cylinder boundary loops as exterior boundaries
- every periodic front edge has exactly one authoritative opposite edge after reconciliation

### 6. Direct materialization

Materialize one accepted cell to one quad while quotienting duplicated cut-chart lattice vertices by exact periodic source/holonomy identity.

Prohibited:

- Euclidean seam welding
- nearest-point seam pairing
- post-hoc cell merging
- source-grid recovery
- fixture/count/order special cases
- generic producer substitution after `Rejected`

## Compile-verified regression sources

Add only the minimum tests required to prove the new contract. Compile, do not execute, in this turn.

Required tests:

1. annulus applicability is derived from source topology and not world-space planarity
2. deterministic cut/holonomy is invariant to source-face row enumeration
3. reciprocal periodic front pairing never creates an exterior seam on the artificial cut
4. malformed/non-integral/branch-incompatible holonomy fails closed with a typed periodic reason and produces no generic seeds/traces/proposals
5. exact committed production cylinder reaches the authoritative periodic producer boundary
6. existing plane, seam, and close-sheet producer contracts remain compiled mandatory regressions

Do not weaken the current cylinder acceptance test.

## Compile gate

Configure and compile the same approved seven-target surface-cell closure unless a narrower existing target set proves all changed translation units and required tests:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

No generated project binary execution is allowed.

## Artifact requirements

Package an immutable next-turn artifact containing:

- exact source authority and changed blob IDs
- source patch(es)
- five executables and two project libraries
- required production fixtures including plane, seam, close sheets, cylinder, bunny, vase
- configuration/build logs
- command-boundary metadata proving `runtimeExecution=false`
- recursive checksums and outer SHA-256

Remove the bounded workflow/trigger/payload after artifact and log verification. The next turn must be artifact-only Test + Benchmark.

## G3 next-turn acceptance hierarchy

### G3 closure

Cylinder is direct deterministic `Produced` pure-quad `CompletedSurfaceCells` output with:

- correct periodic seam closure
- only the two genuine source boundary loops
- complete source provenance
- zero strict validation failures
- no fallback/recovery
- deterministic holonomy/structural/output hashes
- plane, seam, and close sheets retained as valid direct regressions

### Material progress, G3 still open

Cylinder is now applicable to the periodic producer and reaches a new exact typed `Rejected` holonomy/front state without generic substitution, while all passed gates remain green. The following Code + Build addresses only that general periodic rejection.

### No progress/regression

Cylinder remains on the same generic `NotApplicable` path without a new live periodic contract, periodic cut is emitted as a false boundary, seam pairing uses proximity, `Rejected` falls through to generic work, or any G0–G2 regression occurs.
