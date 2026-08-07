# Gate 3 Periodic Ring Correspondence — Code + Build Plan

## Turn boundary

This is a **Code + Build** turn only. Production/test source may change and the approved seven targets may be configured/compiled/linked. Execute no generated Directional binary, unit test, benchmark, `ctest` discovery, CLI/GUI, help/list, or custom-mesh command.

## Required declaration before editing

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at completion/output-validation
Missing design contract: adjacent canonical annulus rings can admit multiple source-topologically valid bijections through a triangulated strip; the authoritative periodic chart must resolve that correspondence from reciprocal cross-field family/transport authority, not lexicographic source-vertex ordering
Smallest general implementation change: replace valid.front() ring-pair selection with a field-family-consistent reciprocal ring correspondence that preserves the existing annulus topology, cut, holonomy and source-strip breakpoints; accept exactly one field-consistent bijection and fail closed on zero or multiple authoritative candidates
Observable material-progress condition: the exact cylinder keeps periodic Produced authority but its inter-ring sides follow the axial field family rather than diagonal strip edges, eliminating the 37.967-degree field-P95 defect and allowing normal/warpage quality to move under their existing thresholds while plane, seam and close sheets remain unchanged regressions
Explicitly deferred work: G4 singularities/topology-distinct completion, torus/general genus, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production remediation, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization hardening
```

## Runtime authority entering this turn

Artifact `9004509871`, source `2783ea718ffb15f8fb3868795173472ab8636c1c`:

- focused/retained contracts **13/13**;
- plane/seam/close sheets direct strict-valid and deterministic;
- cylinder periodic `Produced`, `r=0`, `t=(32,0)`, route 32, cut 4;
- 2,237 traces, 320 completed quads, 352 provenance vertices;
- no fallback/recovery;
- deterministic 3/3;
- completion validation failure count **3**.

Exact failed `SurfaceFinalValidationReport` thresholds from the packaged runtime:

1. `normalP95Degrees = 16.6272734366` > 15;
2. `fieldP95Degrees = 37.9670987281` > 15;
3. `warpageP95Degrees = 30.6213792811` > 30.

All discrete strict/source-authoritative topology/provenance/boundary checks represented in the report pass.

The preceding artifact had only normal P95 and field P95 failures. Source-strip conformity dramatically improved bidirectional surface approximation but left field P95 exactly unchanged and moved warpage P95 marginally over threshold.

## Root cause to correct

`build_periodic_annulus_phase_front_for_faces()` currently:

1. derives a canonical cycle independently for each graph-distance ring;
2. enumerates all offset/direction reindexings whose inter-ring source edges and two-triangle strips are topologically compatible;
3. sorts the valid candidate vertex sequences lexicographically;
4. chooses `valid.front()`.

For the committed cylinder, every adjacent ring pair has two valid topological correspondences because each triangulated strip contains both the intended same-column axial edge and a diagonal source edge to the next circumferential column.

The lexicographic candidate is the diagonal/sheared one. Ring 0 starts at `0°`; the selected next ring starts at `22.5°`. The selected inter-ring edge is **37.9670987281°** away from the axial cross-field family, exactly matching the runtime field-P95 failure.

This is a general ambiguity in triangulated annulus chart correspondence, not a cylinder-count special case.

## Bounded implementation objective

### 1. Preserve proven periodic authority

Do not redesign or bypass:

- source-topology annulus applicability;
- deterministic true-boundary cycles and cut;
- first-class holonomy `(Z4 rotation, Z2 translation, ordered source route)`;
- typed `NotApplicable / Produced / Rejected` semantics;
- explicit artificial-cut periodic ownership;
- exact periodic quotient identity;
- canonical source-strip periodic breakpoints and per-strip subdivisions;
- one accepted phase-front cell -> one output quad;
- source component/local-sheet authority.

### 2. Replace incidental ring-candidate ordering with field authority

For each adjacent ring pair:

1. retain the current topology-compatible candidate enumeration;
2. for every candidate, derive the intended inter-ring transported family from the finalized cross field and existing reciprocal edge-transition authority;
3. require each candidate inter-ring connection to be compatible with one consistent cross-field family/sign modulo 4-RoSy transport across the complete ring;
4. require the circumferential ring direction to be the reciprocal orthogonal family under the same transported branch assignment;
5. preserve ordered source-edge provenance for the chosen correspondence;
6. accept the candidate only when this family assignment is globally reciprocal and unambiguous;
7. if zero candidates satisfy field authority, return typed periodic `Rejected`;
8. if more than one candidate remains genuinely field-equivalent, return typed periodic ambiguity rather than choosing by source vertex ID, count, order, frequency, Euclidean distance, or arbitrary tie-breaking.

The selection must not use fixture names, ring size 16, current translation 32, expected counts, source vertex numerical order as ownership authority, or nearest geometric direction in world space without cross-field transport semantics.

### 3. Preserve source-strip conformity

After the field-authoritative ring correspondence is fixed, retain the current per-source-strip periodic subdivision logic. Do not revert to one global `round(period/target)` count.

The source-strip correction is proven useful: it reduces source-to-output P95 from about `0.1045` to `0.00817` and quad-to-source P95 from about `0.0683` to `0.0313`.

### 4. Regression source

Add/adjust focused tests, compile only, to establish:

1. an annulus strip with both axial and diagonal topology-compatible inter-ring edges chooses the reciprocal field-family-consistent correspondence;
2. the same contract is invariant to face-row enumeration and incidental source-edge/DCEL numbering;
3. a deliberately field-ambiguous two-candidate ring correspondence fails closed with a typed periodic reason instead of lexicographic selection;
4. canonical source-strip boundary breakpoints remain retained;
5. artificial-cut pairing remains reciprocal and non-exterior;
6. exact cylinder still reaches authoritative periodic producer boundary;
7. plane, seam and close sheets compile as mandatory regressions.

Do not weaken any existing direct cylinder or strict validation assertion.

## Compile gate

Compile exactly the established seven-target closure with Release static/Ninja/`PRE_TEST` or equivalent compile-only-safe configuration:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Execute no generated project binary.

## Artifact requirements

Package immutable next-turn authority containing exact source commit/blobs/patch, five executables, two libraries, required fixtures, build/configure/toolchain logs, `runtimeExecution=false` command-boundary metadata, recursive checksums, and a separate always-uploaded diagnostic log artifact.

Remove the temporary workflow, trigger, and payload after source/build/log/artifact verification. Leave only approved durable workflow state.

## Following Test + Benchmark acceptance

The following artifact-only turn must first execute the focused correspondence/periodic contracts, then plane/seam/close-sheet, then exact cylinder.

G3 closes only if cylinder is direct deterministic `Produced` `CompletedSurfaceCells` pure-quad output with:

- zero strict/completed validation failures;
- field P95 <= 15 degrees;
- normal P95 <= 15 degrees;
- warpage P95 <= 30 degrees;
- correct periodic holonomy and source route;
- no false cut seam;
- complete provenance;
- no fallback/recovery;
- retained G0–G2 successes.

If the field-authoritative correspondence is consumed but a new exact quality failure remains, preserve it and address only that next general defect. Do not relax the validator.
