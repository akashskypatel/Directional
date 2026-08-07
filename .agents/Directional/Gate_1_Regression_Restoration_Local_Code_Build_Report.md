# Gate 1 Regression Restoration — Local Code + Build Report

## Turn declaration

```text
Active design gate: Gate 1 — uniform phase-front plane regression restoration
Earliest failing fixture: plane__surface_cells
Missing design contract: a coherent prescribed raw field with intentionally empty matching/transition containers must use exact reciprocal physical transport rather than be rejected as incomplete authoritative metadata
Smallest general implementation change: distinguish absent metadata from present authoritative metadata inside the planar phase-front proof while preserving strict reciprocal transition validation whenever metadata exists
Observable material-progress condition: the next artifact restores direct plane output while retaining the deterministic direct seam output
Explicitly deferred work: close sheets, periodic holonomy, bunny/vase completion, validator changes, fallback/recovery, and unrelated suite cleanup
```

## Root cause

The Gate 2 implementation passed pointers to the cross-field matching, effort, and transition containers even when prescribed-field loading left those containers empty. The planar phase-front code treated a non-null pointer as authoritative metadata and required an entry for every interior edge. The constant prescribed plane therefore failed before phase-front construction and fell through to generic traces/arrangement/completion.

The seam carries complete transition metadata, so its reciprocal quarter-turn path was valid and must remain unchanged.

## General correction

`src/geometry/SurfaceCellTracing.cpp` now:

- treats empty matching, effort, and transition containers as absent metadata within the planar phase-front proof;
- uses exact physical branch transport only when no authoritative metadata exists;
- retains strict fail-closed lookup, topology checks, and reciprocal quarter-turn validation when any authoritative transition metadata exists;
- validates forward and reverse branch transport against the per-face physical lattice frame;
- records every metadata-free crossed source edge through the canonical source-edge index;
- preserves source chart, family/sign, component, local sheet, route, winding, directed ownership, and one-cell-to-one-quad materialization;
- contains no fixture name, path, ID, dimension, count, or expected-hash branch.

## Source authority

- prior tested Gate 2 source: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- documentation parent: `1a72073db04d440758ed1ddb23e3dfbf2fe1e7bb`;
- payload checkpoint: `da707052a28688ee35c81d26d2356e3f8581b032`;
- patch SHA-256: `53c402e8d9740c057f70bfc64912fef3f3e2c4d41b57c38710875f17fc4172d8`;
- final source blob: `850971a60b75dd84a81ddd4d260998f7ec9c326a`;
- source commit: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- payload cleanup commit: `d0ffebf4ef0239563f46dbb7485144bb581e80f1`;
- source-sync run/job: `31143208487` / `92757246121`;
- source-sync evidence artifact: `8980516098`;
- evidence artifact SHA-256: `2f8561fc8b5937be6bf05a6e010379bd5241ec13a7ced26c7e20a970a07b4766`.

The synchronization verified the exact patch digest, changed-file inventory, and expected final blob before creating the source commit.

## Build authority

The preserved Gate 2 Release static `PRE_TEST` Ninja graph was incrementally rebuilt locally.

- compiler: GNU C++ 14.2.0;
- configuration: Release `-O3 -DNDEBUG`;
- approved targets: 7/7;
- incremental compile/link actions: 7/7;
- wall time: 16.51 seconds;
- peak RSS: 1,152,172 KiB;
- executables packaged: 5;
- project static libraries packaged: 2;
- fixture/input files packaged: 27;
- internal checksums: 44/44;
- artifact: `directional-g1-regression-restoration-local-build-artifact.zip`;
- artifact SHA-256: `c516af42f6aa388ef219408ef63e939490176385e976885f1ea9176ec3609e20`.

The archived source reconstructs blob `850971a60b75dd84a81ddd4d260998f7ec9c326a`.

## Turn boundary

No generated project binary, test, benchmark, discovery command, CLI, GUI, help command, or list command was executed. This Code + Build turn makes no plane or seam runtime-success claim.

## Next turn

Execute `.agents/Directional/Gate_1_Regression_Restoration_Artifact_Only_Test_Benchmark_Plan.md` from the exact artifact. Run plane first, seam second, then the remaining four mandatory fixtures and non-overlapping default suites.
