# Gate 4 Closed-Genus-One Holonomy Basis — Code + Build Plan

Status: **authoritative next turn**  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Turn boundary

Do not execute any generated Directional binary, test, benchmark, ctest/discovery command, CLI/GUI command, help/list command, or custom input during this turn.

Use the current working branch. Runtime authority entering this turn is exact artifact `9014730437` from final compile source `6e754bdd64482582d39e71184805fbb053c99f86`. The first G4 multi-relation slice is runtime-proven material progress but G4 is still active.

## Required design declaration before editing

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: torus__surface_cells now retains two periodic relations and advances to 670 traces, but aggregate authoritative phase-front disposition remains NotApplicable; generic arrangement then yields zero cells and completion fails SideSubdivisionRepair:InvalidInputIncidence
Missing design contract: build_uniform_phase_front is all-or-nothing across authoritative source sheets; when any later local sheet is NotApplicable it returns a partially accumulated aggregate without Produced status, so already-valid periodic sheet cells/relations cannot participate in complete authoritative materialization and the pipeline falls into a downstream zero-cell generic arrangement path
Smallest general implementation change: make phase-front construction cover every authoritative source sheet deterministically by composing supported bounded and periodic sheet charts under one complete aggregate contract; a sheet that truly cannot be represented must produce a typed first-invalid producer reason rather than silently downgrading the whole partially authoritative aggregate to NotApplicable
Observable material-progress condition: exact torus phase-front becomes fully Produced with complete source-sheet coverage and successful exact materialization, or fails earlier at the exact unsupported sheet with a typed structural reason; it must not return partial NotApplicable followed by zero arrangement cells, while all five G4 relation semantics, all 17 G0-G3 focused contracts, and direct plane/seam/close-sheets/cylinder behavior remain unchanged
Explicitly deferred work: prescribed-sphere singularity completion until torus producer coverage is closed, G5 adaptive scale/hard-feature expansion, G6 bunny/vase production, scheduler timing, historical completion/simplification failures unrelated to the active torus producer contract, validator changes, and unrelated optimization
```

## Exact runtime evidence entering the turn

Artifact `9014730437`:

- workflow run/job `31233594490 / 93042009574`;
- ZIP SHA-256 `14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`;
- recursive checksums **46/46**;
- primary implementation `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`;
- final compile source `6e754bdd64482582d39e71184805fbb053c99f86`.

Artifact-only validation proves:

- five new G4 periodic-relation semantic tests **5/5**;
- retained G0-G3 focused contracts **17/17**;
- plane direct 64 quads / 81 V, hash `730caeae49ec872c`, deterministic 3/3;
- seam direct 64 quads / 81 V, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets direct 200 quads / 242 V / two components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder direct `Produced / CompletedSurfaceCells`, one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 V, zero validation failures, hash `32135be51d7a0a26`, deterministic 3/3, exactly two genuine exterior annulus loops, no fallback/recovery.

Exact torus is deterministic 3/3:

- `surfaceCellAuthoritativeProducerDisposition = NotApplicable`;
- periodic relation count **2**;
- compatibility projection of first relation `r=0`, `t=(24,0)`, route 24, cut 2;
- 670 trace segments;
- 113 retained strands / 113 embedded arrangement arcs;
- zero arrangement cells;
- completion failure `SideSubdivisionRepair:InvalidInputIncidence`;
- no output, fallback, legacy substitution, input return, or source-grid recovery.

Stage hashes are stable 3/3: tracing `0539b306563dbe25`, strands `618d7ed18d1f3daa`, embedded network `33d00772feecc2f7`, arrangement `1ee6b9f9fd044d71`, completion `b4efe5193b9e5c27`.

Torus feature authority is nontrivial: 48 hard feature edges in four closed feature curves. These barriers must not be deleted, demoted, or geometrically welded to force production.

Detailed evidence: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Report.md`.

## Source diagnosis

`build_uniform_phase_front()` groups faces by `(source component, source sheet)` and processes each sheet in deterministic canonical order.

For each sheet it currently:

1. tries `build_uniform_phase_front_for_faces()`;
2. if `NotApplicable`, tries `build_periodic_annulus_phase_front_for_faces()`;
3. if `Rejected`, propagates a typed failure;
4. if still `NotApplicable`, immediately returns the aggregate result;
5. otherwise appends local cells/edges/events and canonical periodic relations.

Only after all sheets finish does the aggregate set `succeeded=true` and disposition `Produced`.

Therefore an unsupported later sheet can leave already-appended cells and periodic relations in a result whose disposition is still `NotApplicable`. The pipeline correctly refuses to call authoritative materialization on that partial result. The later zero-cell generic arrangement and completion-side incidence failure are downstream symptoms; they are not the first design target.

Do not fix this by merely changing the final disposition to `Produced`. Partial coverage is invalid authority.

## Required implementation contract

### 1. Complete per-sheet coverage is explicit authority

Every source sheet considered by the aggregate producer must end in exactly one of:

- **Produced** with nonempty valid cells/edges/events and complete source-sheet coverage;
- **Rejected** with a typed first-invalid structural reason;
- a deliberately unsupported whole-input `NotApplicable` only when no authoritative phase-front work has been produced at all.

Once any sheet has produced authoritative content, a later unsupported sheet must not silently convert the aggregate into partial `NotApplicable`.

Introduce only the minimum state needed to make coverage explicit. Do not add a speculative general chart framework if the existing bounded and periodic builders can be composed directly.

### 2. Support the torus's actual mixed sheet topology

Determine, from source topology and current hard-feature/source-sheet authority, which torus local sheet remains unsupported after the first two periodic relations are retained.

Extend the appropriate existing producer so that this sheet is represented truthfully. Likely supported classes are already present:

- bounded uniform rectangular/strip charts;
- periodic annulus charts.

Do not assume every torus sheet is periodic and do not hardcode the torus's observed relation count, `(24,0)`, face IDs, feature-curve IDs, or sheet ordering.

If the remaining sheet is neither of the currently supported structural classes, add the smallest general topology-derived producer needed for that class. Do not select a chart by count/frequency, transient ID, Euclidean proximity, or fixture identity.

### 3. Preserve first-class multi-relation semantics

The current canonical periodic relation collection is runtime-proven and must remain authoritative:

- equivalent/reversed descriptions canonicalize;
- distinct authoritative sheet relations remain retained;
- conflicting transport fails closed;
- unresolved same-sheet dependent basis fails closed instead of choosing by order;
- structural hashing includes canonical route/cut topology signatures;
- diagnostics expose relation cardinality;
- exact materialization uses component/sheet-aware relation lookup.

Do not regress to one scalar relation or add a secondary mutable authority.

### 4. Aggregate validation before `Produced`

Before the aggregate becomes `Produced`, validate that:

- every source sheet in the input partition contributed complete cells;
- every emitted cell's component/sheet label matches its source trace provenance;
- no source sheet is duplicated or omitted;
- periodic relations reference only their authoritative sheet/component;
- local cell/edge/event offsets remain valid after aggregation;
- the resulting aggregate is deterministic under face-row enumeration and sheet-work enumeration.

A complete aggregate may contain both non-periodic and periodic sheet charts.

### 5. Exact materialization must cover the complete aggregate

`build_authoritative_phase_front_mesh()` must consume every produced sheet in the aggregate and every retained periodic relation applicable to that sheet.

For closed torus input:

- no genuine source boundary may be synthesized;
- artificial chart/periodic cuts may not appear as exterior output;
- no Euclidean seam welding;
- no positional merging across unrelated sheets;
- hard feature rails remain source-authoritative barriers/provenance constraints.

If complete phase-front construction succeeds but materialization exposes a new structural invariant, fail at `tracing/phase-front-materialization` with the exact typed reason. That is preferable to falling through into a zero-cell generic arrangement.

### 6. Do not repair the downstream completion symptom first

Do not modify `SideSubdivisionRepair`, completion incidence validation, parity repair, FlowRep simplification, or generic arrangement merely to make the current torus run continue.

Those stages are downstream because authoritative phase-front disposition is already `NotApplicable`. They become eligible only if a fully produced/materialized phase-front still reaches them and exact runtime evidence proves they are then the first blocker.

## Typed failure contract

Add a precise phase-front failure reason if necessary for a produced-before-unsupported aggregate, for example an unsupported/incomplete source-sheet topology reason. The exact name should match existing naming style.

Requirements:

- first-invalid stage must remain `tracing/phase-front` or `tracing/phase-front-materialization`;
- reason must identify an actual structural invariant;
- do not use `InvalidFinalCellState` as a catch-all if the unsupported sheet class is known;
- no synthetic diagnostics solely to satisfy a test.

## Required compile-only regressions

Tests are compiled only in this turn and must not execute.

Add/adjust the minimum tests needed to prove:

1. **Mixed bounded + periodic sheet aggregate** — a deterministic synthetic source with at least one bounded chart and at least one periodic chart produces one complete aggregate rather than partial `NotApplicable`.
2. **Later unsupported sheet fails explicitly** — after earlier produced sheet content exists, a later truly unsupported sheet yields a typed rejection/incomplete-coverage reason and never returns partial `NotApplicable`.
3. **Sheet-work enumeration invariance** — canonical output/coverage signatures do not depend on face-row or sheet processing order.
4. **Every source sheet covered exactly once** — no omitted or duplicated sheet in a produced aggregate.
5. **Exact committed torus producer boundary** — the real torus must either reach complete `Produced` phase-front/materialization under structural authority or expose the new typed unsupported-sheet reason; do not hardcode relation count/translation/output counts.
6. **Five G4 periodic relation semantics remain compile-covered**.
7. **All 17 G0-G3 focused contracts remain compile-covered**, especially close-sheet isolation and cylinder one-relation materialization.

Do not weaken existing tests or change fixture geometry/fields to create an easier scenario.

## Compile gate

Compile exactly the established seven approved targets in Release static / Ninja with compile-only-safe discovery behavior:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Execute no generated project binary.

Package immutable source authority, implementation patch, relevant final blobs, five executables, two project libraries, all 27 fixture/input files, configure/build/toolchain logs, compile commands, `runtimeExecution=false`, and recursive checksums. Upload a separate detailed log artifact unconditionally.

Use at most one bounded workflow/payload. After exact source/build/log/artifact authority is verified, remove/disable the bounded workflow before deleting its trigger, then remove the payload. Final `.github/workflows` state must contain only durable `agent-source-snapshot.yml`.

## Following artifact-only acceptance

The next Test + Benchmark turn must verify artifact integrity first, then execute:

- new complete-sheet-coverage semantic tests;
- all five G4 periodic-relation semantic tests;
- all **17/17** G0-G3 focused contracts;
- direct plane/seam/close-sheets/cylinder three-run regression matrix with exact G3 hashes;
- exact torus in at least three independent processes if bounded runtime completes.

### Material-progress acceptance

Preferred result:

- torus phase-front `Produced` with complete source-sheet coverage;
- authoritative phase-front materialization succeeds;
- direct strict-valid pure-quad closed torus output with no artificial exterior seams, no fallback/recovery, and deterministic structural hash.

Acceptable next-slice progress:

- torus fails **earlier and truthfully** at the exact unsupported source sheet or materialization invariant with a typed first-invalid reason, instead of partial `NotApplicable -> zero arrangement cells -> SideSubdivisionRepair:InvalidInputIncidence`;
- all already-passed relation/G0-G3 contracts remain intact.

Not progress:

- marking partial phase-front coverage `Produced`;
- removing/demoting torus hard-feature barriers;
- changing source-sheet labels solely for the fixture;
- forcing generic arrangement/completion past zero cells;
- fallback/recovery substitution;
- order/ID/count/frequency/proximity ownership heuristics.

After torus producer coverage closes, return to the prescribed singular sphere. Do not preempt this slice with historical completion/simplification failures.

## Review decision

Optional Review is skipped (`review policy: never`). This plan is authoritative for the next Code + Build turn.
