# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active; endpoint canonicalization compile-valid, artifact validation pending]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Latest executed G3 runtime authority

Artifact `9008118764`, source/test `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` remains the latest executed authority:

- focused/retained producer contracts **9/15**;
- plane/seam/close sheets remain direct strict-valid deterministic passes;
- cylinder `Rejected/InvalidPeriodicChart`, `tracing/phase-front`, cell 29, zero traces/arrangement/completion/output, deterministic 3/3;
- no fallback/recovery;
- six nominal G3 periodic contracts regress before their intended assertions.

Independent reconstruction shows the field-authoritative same-column correspondence remains correct; the discarded diagonal candidate is `37.9670987281°` from the axial field. The regression is caused by tolerance-expanded periodic-chart endpoints, not by the field-correspondence choice.

## Endpoint-canonicalization Code + Build complete

Final source authority:

- source/test commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- base production checkpoint `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- patch SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`;
- final blobs:
  - header unchanged `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
  - tracing source `63e5ee427f675077f710db51ffb56d91838d3519`;
  - Phase10 tests `bef95b04c95c9a213c634e604d004b3d7d22646e`.

Implemented bounded correction:

1. retain the existing `1e-10` tolerance only for periodic-chart triangle coverage/ownership;
2. derive emitted chart breakpoints from exact barycentric zero crossings rather than tolerance-expanded coverage bounds;
3. canonicalize finite in-tolerance barycentrics onto exact simplex values;
4. convert source-vertex endpoints to exact one-hot barycentrics and renormalize remaining valid endpoints;
5. canonicalize periodic lattice points with the same source-simplex rule;
6. omit tolerance-only segments that collapse after canonicalization;
7. keep same-face path merging on canonical endpoints;
8. leave strict closed-boundary/self-intersection validators unchanged;
9. preserve field-authoritative ring correspondence, typed ambiguity rejection, annulus cut/holonomy/quotient/source-strip authority, provenance and one accepted cell → one quad;
10. add compile-only focused endpoint/shared-breakpoint and genuine-overlap regressions.

No fixture special case, source-ID/count/order/frequency selection, validator relaxation, proximity weld, fallback/recovery or post-hoc repair was added.

## Build authority

- workflow run/job `31221873296 / 93007996817`;
- artifact `9010838200` (`g3-periodic-chart-endpoint-canonicalization-code-build`);
- artifact SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- log artifact `9010837410`, SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- recursive checksums **44/44**;
- compile/link **111/111**, seven approved targets;
- five executables, two project libraries, 27 fixture/input files;
- Release static / Ninja / `PRE_TEST`;
- `runtimeExecution=false`; no generated Directional binary executed.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9010838200`.

Required order:

1. verify exact artifact/source/patch/blob/checksum/build-boundary authority;
2. run the two new endpoint-canonicalization contracts;
3. run field-authoritative correspondence and typed ambiguity contracts;
4. run the six retained G3 periodic contracts that previously regressed;
5. run seven retained G1/G2 contracts — **17 focused/retained contracts total**;
6. revalidate plane, seam and close sheets;
7. execute exact cylinder as active G3 acceptance;
8. require at minimum advancement beyond `InvalidPeriodicChart` cell 29 while retaining field authority, no generic substitution/fallback/recovery and G0-G2;
9. close G3 only with direct deterministic strict-valid periodic `CompletedSurfaceCells`, zero validation failures and existing normal/field/warpage limits satisfied;
10. run determinism/default suites and later bunny/vase observations only after the direct gate decision.

Historical cylinder translation/grid/output counts are not acceptance constants.

## No-progress rule

The ring-correspondence artifact was the first runtime-no-progress Code + Build result since the previous material-progress turn. If artifact `9010838200` also fails to establish material G3 progress, the **next turn must be the mandated design review or bounded producer replacement proof**; another ordinary isolated Code + Build is prohibited.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
