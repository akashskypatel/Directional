# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → **G2 cross-chart / close-sheet isolation [active; compile-valid, runtime verification pending]** → G3 cylinder/periodic holonomy → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G2 Code + Build complete

The bounded G2 source-sheet extension is implemented and compile-verified.

Source authority:

- source commit `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- architecture patch SHA-256 `7b99d8a7ff227c2e4f07a1498805eb7fd34b542b772d3bd0c1bb1e455e31fa8c`;
- source blobs:
  - `SurfaceCellTracing.cpp` `c9570ecb4a9557eebaf0e30b751e2ccca90b2973`;
  - `RemeshPipeline.cpp` `55af3205fd7cdb8f21357ac69516ffa29cf8a6d3`;
  - `SurfaceCellsPhase10Tests.cpp` `7151077d7d4e0a10dad388dd008479f96fc1aae8`.

Implemented contracts:

- authoritative uniform phase/front work is partitioned by source component/local-sheet before construction;
- active-sheet geometry, incidence, boundary, transport, and frame checks do not inspect unrelated spatially close sheets;
- proven reciprocal edge and ordered source-vertex-fan transport remains sheet-local;
- independent produced sheets are concatenated only after each sheet is valid;
- an applicable sheet rejection remains authoritative `Rejected`;
- unsupported/periodic topology remains `NotApplicable` for later gates;
- direct materialization uses `(component, sheet, u, v)` lattice identity rather than spatially ambiguous `(u, v)` alone;
- boundary loops are generated per source sheet;
- disconnected-sheet isolation and face-row-order invariance tests were added and compiled.

## Build authority

The first bounded compile exposed a one-line syntax error and failed before linking. The exact syntax defect was corrected without changing the design contract, then the full approved compile scope passed.

Successful authority:

- run/job/artifact `31179899458` / `92870408341` / `8994541137`;
- artifact SHA-256 `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- detailed log artifact `8994539982`, SHA-256 `c7d67285ca6b980111a53fe017b3de5800abccb2a3146352135c0d674ca0acc8`;
- recursive checksums **45/45 passed**;
- compile/link actions **111/111**;
- approved targets **7/7**;
- five executables, two project libraries, 27 fixture/input files packaged;
- no generated project binary/test/benchmark executed.

The failed compile log is retained as artifact `8994261249` and records the corrected syntax failure.

## Latest runtime authority — unchanged

No runtime validation was executed in the current Code + Build turn. Latest artifact-tested direct state remains:

- plane: direct valid `Produced`, 64 pure quads;
- seam: direct valid `Produced`, 64 pure quads;
- close sheets: `NotApplicable`, 158 generic traces, zero arrangement/completion;
- cylinder: `NotApplicable`, 732 traces;
- bunny: `NotApplicable`, 80,862 traces;
- vase: prior bounded timeout/failure observation.

## Required next turn

Execute `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `8994541137`.

Priority order:

1. verify artifact/source/checksum authority;
2. run the two new disconnected-sheet producer contracts;
3. preserve plane and seam mandatory regressions;
4. execute exact production close sheets as G2 acceptance;
5. prove component/local-sheet isolation and no cross-sheet output identity merge;
6. run bounded determinism and non-overlapping default suites;
7. observe cylinder/bunny/vase only after the active G2 decision.

G2 closes only if close sheets becomes direct deterministic strict-valid `Produced` output without cross-sheet coupling and plane/seam remain valid. If so, the next Code + Build gate becomes G3 periodic cylinder/holonomy.

Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
