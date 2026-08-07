# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active; output-validation correction compile-valid, runtime verification pending]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Latest executed G3 authority

Artifact `9001168379` / source `56f823273cad041a01ebb4d0772c3265ff248f4a` established material runtime progress:

- cylinder authoritative periodic disposition `Produced`;
- holonomy `r=0`, `t=(29,0)`, ordered route 32 edges, deterministic cut four edges;
- 2,163 traces, 290 direct completed quads, 319 provenance vertices;
- deterministic 3/3;
- no fallback/recovery;
- terminal `completion/output-validation:AggregateCompletionValidationFailure` with exactly two aggregate completed-checkpoint validation failures.

Plane, seam, and close sheets remain strict-valid deterministic direct successes. The benchmark does not expose the two individual validator thresholds; do not infer or relax them.

Focused/retained producer contracts were **11/12**. The only failure was an incorrect row-order expectation comparing raw DCEL edge integers; canonical ordered source-endpoint route/cut identities are equal.

## G3 output-validation Code + Build complete

Exact source/test authority:

- source commit `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- `SurfaceCellTracing.cpp` blob `9df9a9759c761293fef1278f97b82fbb0aee0600`;
- `SurfaceCellsPhase10Tests.cpp` blob `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`.

Implemented bounded correction:

1. every canonical annulus source strip is a mandatory periodic lattice breakpoint;
2. each strip gets a deterministic positive nearest-integer subdivision count from transported intrinsic strip length and local vertex target-size samples;
3. cumulative periodic coordinates preserve exact source-strip endpoints and the holonomy translation becomes the sum of strip subdivisions;
4. phase-front points/cells/boundary paths use those strip-conforming nonuniform intrinsic coordinates;
5. axial subdivision and the two genuine annulus boundaries remain unchanged;
6. no validator, materializer, fallback/recovery, post-hoc split/merge, Euclidean weld, nearest-point repair, fixture ID, or expected count logic was added;
7. row-order invariance now compares ordered canonical endpoint-key sequences through each mesh's authoritative `EV` table, never sorted sets or raw DCEL IDs;
8. a new compiled structural regression requires all genuine source-boundary vertices to remain exact phase-front boundary corners without hard-coding ring/output counts.

## Build authority

- run/job `31204848178` / `92953250176`;
- artifact `9004509871` (`g3-periodic-output-validation-code-build`);
- artifact SHA-256 `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- detailed log artifact `9004508508`, SHA-256 `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`;
- recursive checksums **44/44**;
- compile/link actions **111/111** across seven approved targets;
- five executables, two libraries, 27 fixture/input files;
- Release static / Ninja / GNU C++ 13.3.0 / CMake 3.31.6 / `PRE_TEST`;
- generated project binary/test/benchmark execution: **none**.

This is compile evidence only; G3 runtime closure remains pending.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9004509871`.

Required order:

1. verify artifact/source/patch/blob/checksum authority;
2. execute the six focused periodic/output-validation producer contracts first;
3. revalidate plane, seam, and close sheets;
4. execute exact production cylinder as active G3 acceptance;
5. require periodic `Produced`, direct pure-quad `CompletedSurfaceCells`, correct holonomy/quotient, source-strip breakpoint retention, complete provenance, **zero completed-checkpoint validation failures**, no false periodic exterior seam, and no fallback/recovery;
6. do **not** require prior translation `t=(29,0)` because source-strip-conforming subdivision intentionally permits a different deterministic integral periodic count;
7. run determinism/default suites after the active gate decision;
8. observe bunny/vase only as later-gate evidence.

If cylinder closes G3, advance to G4 topology-distinct completion and singularities. If it reaches another exact source-authoritative structural/validation failure, keep G3 active and address only that failure next.

Review policy remains `never`.

Every completed turn ends with a new top-level PR #8 comment after all other repository writes.