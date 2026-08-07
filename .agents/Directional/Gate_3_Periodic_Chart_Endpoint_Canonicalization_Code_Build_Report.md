# Gate 3 Periodic Chart Endpoint Canonicalization — Code + Build Report

## Decision

The bounded G3 endpoint-canonicalization implementation is **compile-valid** and packaged for artifact-only runtime validation. This turn makes no runtime correctness claim.

The source change addresses the exact `Rejected/InvalidPeriodicChart` cell-29 regression diagnosed from artifact `9008118764` without weakening `validate_closed_boundary_paths()` or `segments_intersect_beyond_shared_endpoint_2d()` and without restoring the obsolete diagonal/lexicographic annulus-ring correspondence.

## Design declaration

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at tracing/phase-front, Rejected/InvalidPeriodicChart, cell 29
Missing design contract: tolerance-aware periodic chart clipping must emit canonical source-simplex endpoints so segments that meet at an exact source vertex or edge remain exactly shared in source geometry; clipping tolerance may decide triangle coverage but may not create geometric tails that the strict self-intersection validator sees as overlap
Smallest general implementation change: canonicalize and renormalize periodic_chart_segment barycentric interval endpoints onto exact simplex boundaries, remove any segment that becomes zero-length after canonicalization, and preserve exact shared breakpoint identity across consecutive chart intervals without weakening validate_closed_boundary_paths or its self-intersection predicate
Observable material-progress condition: the six currently regressed nominal G3 periodic contracts return to Produced/expected behavior, the field-authoritative correspondence contract reaches and passes its axial-family assertion, exact cylinder advances beyond cell 29 without losing field-authoritative correspondence, and G0-G2 remain green
Explicitly deferred work: completed-output normal/field/warpage remediation after phase-front authority is restored, G4 singularities/topology-distinct completion, G5 adaptive transitions/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization
```

## Source authority

Final source/test commit:

- `0279946920dfca6e9ac44b7ea31b38e929d1f5fc` — `fix(surface-cells): canonicalize periodic chart endpoints`.

Base production source checkpoint:

- `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`.

Patch authority:

- SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`.

Final blobs:

- `include/directional/geometry/SurfaceCellTracing.h` — unchanged `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `src/geometry/SurfaceCellTracing.cpp` — `63e5ee427f675077f710db51ffb56d91838d3519`;
- `tests/SurfaceCellsPhase10Tests.cpp` — `bef95b04c95c9a213c634e604d004b3d7d22646e`.

Artifact source archive independently reproduces all three blob IDs and the patch SHA.

## Bounded implementation

### 1. Separate chart coverage tolerance from emitted geometry

`periodic_chart_segment()` still uses the existing `1e-10` chart-coverage tolerance to decide which source triangles own an interval. It no longer uses tolerance-expanded `-tolerance` clipping limits as emitted geometric breakpoints.

For every barycentric coordinate varying along the chart segment, the producer now also derives the exact mathematical crossing `b_i(t) = 0` and records that exact parameter as the chart breakpoint. Tolerance-expanded limits remain ownership evidence only.

This removes the cell-29 failure mode where two sides that should meet at one source vertex were emitted with microscopic source-face tails.

### 2. Canonical source-simplex barycentrics

A shared `canonicalize_periodic_chart_barycentric()` helper now:

- rejects materially out-of-simplex or non-finite barycentrics;
- snaps coordinates within the existing coverage tolerance of `0` or `1` to exact simplex values;
- converts exact-vertex endpoints to exact one-hot barycentrics;
- renormalizes remaining valid barycentrics while preserving exact zero coordinates;
- is used both for periodic chart lattice points and emitted periodic chart segment endpoints.

### 3. Remove tolerance-only segments

After canonicalization, a source-face segment whose start/end barycentrics collapse to the same point within `1e-12` is not emitted. Same-face path merging keeps the already canonical endpoint.

### 4. Preserved authority

Unchanged:

- field-authoritative reciprocal adjacent-ring correspondence;
- typed `InvalidPeriodicRingCorrespondence` / `AmbiguousPeriodicRingCorrespondence` rejection;
- topology-derived annulus applicability;
- deterministic cut and first-class holonomy design;
- source-strip breakpoints/subdivisions;
- artificial-cut ownership and exact periodic quotient;
- source provenance and one accepted cell -> one quad;
- strict boundary-path/self-intersection validator implementation and tolerances;
- fallback/recovery policy;
- G0-G2 production logic.

No fixture ID/count special case, source-ID ownership tie-break, Euclidean seam weld, arbitrary subset search, post-hoc cell repair, validator relaxation, fallback, or recovery path was added.

## Compile-only regression source

Two new focused tests were compiled but **not executed**:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints`
   - requires the exact cylinder periodic phase front to reach `Produced`;
   - requires emitted endpoint barycentrics to be finite, normalized and inside the exact simplex;
   - requires near-source-vertex endpoints to be exact one-hot barycentrics;
   - rejects tolerance-only zero-length emitted segments;
   - requires consecutive cell sides to share the same source-space breakpoint;
   - calls the unchanged strict `validate_closed_boundary_paths()` and requires `Accepted`.
2. `SurfaceCellsPhase10.PeriodicChartEndpointCanonicalizationKeepsGenuineOverlapRejected`
   - proves an exact shared endpoint alone remains allowed;
   - proves collinear overlap beyond that shared endpoint remains rejected by the unchanged predicate.

Existing field-authoritative correspondence, typed ambiguity, annulus, row-order, source-strip, artificial-cut, malformed-holonomy, exact-cylinder producer-boundary, and G1/G2 regression tests were compiled unchanged.

## Compile-only build authority

Successful bounded workflow:

- workflow run `31221873296`;
- job `93007996817`;
- conclusion `success`;
- GNU C++ 13.3.0 / CMake 3.31.6 / Ninja;
- Release static build;
- GoogleTest discovery mode `PRE_TEST`;
- approved targets **7/7**;
- compile/link actions **111/111**.

Approved targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

No generated Directional binary, test, benchmark, CLI/GUI, help/list or discovery command executed. Packaged metadata records `runtimeExecution=false`.

## Immutable artifact authority

Build artifact:

- ID `9010838200`;
- name `g3-periodic-chart-endpoint-canonicalization-code-build`;
- outer SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- expiration 2026-08-21;
- recursive checksums **44/44**;
- five executables;
- two project libraries;
- 27 fixture/input files.

Detailed log artifact:

- ID `9010837410`;
- name `g3-periodic-chart-endpoint-canonicalization-code-build-logs`;
- outer SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- final log records `build_exit=0`, `package_exit=0`, source commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, and no project runtime execution.

Exact cylinder fixture closure remains unchanged:

- `cylinder.obj` SHA-256 `59ed6d736410dbef6bc751136ba0eb1d557a43c9df63fb2a570daf85c79419ae`;
- `cylinder.rawfield` SHA-256 `6e861e06fa5d3dd6ed84c48bf7d459df701acd7f6ab241cc2adbde66d829084d`.

## Runtime status

The latest executed runtime authority remains artifact `9008118764`, where exact cylinder deterministically rejects `InvalidPeriodicChart` at cell 29. This Code + Build artifact has **not** been executed.

The following artifact-only turn decides whether endpoint canonicalization restores the six regressed G3 periodic contracts and advances exact cylinder beyond cell 29 while preserving field-authoritative correspondence and G0-G2.

If that following artifact-only validation also fails to produce material G3 progress, the mandatory two-consecutive-Code+Build no-progress rule requires the subsequent turn to be the designated design review or bounded producer replacement proof.
