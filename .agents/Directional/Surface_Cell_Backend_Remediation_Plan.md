# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1, and G2 are closed. G3 periodic authority is runtime-proven on the exact production cylinder, but the latest executed artifact remains incomplete at **completed output validation**.

Exact artifact `9001168379` from source `56f823273cad041a01ebb4d0772c3265ff248f4a` produces:

- authoritative periodic `Produced`;
- holonomy `r=0`, `t=(29,0)`, ordered route 32 edges, cut four edges;
- 2,163 source-attached traces;
- zero generic arrangement cells;
- 290 direct completed quads;
- 319 provenance vertices;
- no fallback/recovery;
- deterministic 3/3.

The completed checkpoint then reports exactly two validation failures at `completion/output-validation:AggregateCompletionValidationFailure`. Final output is correctly withheld. The benchmark record does not expose the two individual failed validation fields, so they must not be guessed or relaxed.

## Proven producer foundation

Retain without redesign:

- first-class `NotApplicable / Produced / Rejected` authority;
- no generic substitution after `Rejected`;
- local lattice phase/integer coordinates;
- reciprocal ordinary-edge and ordered source-vertex transport;
- complete source route provenance;
- component/local-sheet isolation;
- topology-derived singularity-free annulus applicability;
- deterministic intrinsic source cut;
- periodic holonomy `(Z4 rotation, Z2 translation, ordered source route)`;
- explicit `PeriodicFrontMerge` ownership;
- exact periodic quotient identity;
- direct one-cell-to-one-quad materialization;
- fail-closed source-authoritative validation.

Plane, seam, and close sheets remain mandatory direct regressions and were green in the latest executed G3 artifact.

## Source-strip correction — compile-valid

Source `2783ea718ffb15f8fb3868795173472ab8636c1c` implements the bounded structural correction upstream of validation.

### Source-strip-conforming periodic lattice

The periodic producer now uses the canonical annulus ring/strip ordering already derived from topology and:

1. makes every source-ring strip boundary a mandatory intrinsic periodic lattice breakpoint;
2. computes each strip's positive deterministic subdivision count from transported intrinsic strip length and local endpoint target-size samples;
3. chooses nearest positive integer subdivisions without fixture IDs, expected totals, source-row order, or hard-coded ring/grid counts;
4. accumulates those strip subdivisions into the periodic lattice coordinate and integer holonomy translation;
5. inserts every exact strip endpoint into the cumulative periodic coordinate sequence;
6. builds authoritative chart samples, cells, source-attached boundary paths, and intrinsic cell validation directly from those nonuniform coordinates;
7. preserves the exact periodic quotient and one accepted cell → one output quad;
8. leaves axial construction and the two genuine annulus boundaries unchanged;
9. fails closed as `InvalidPeriodicChart` for non-finite/overflowing subdivision state.

No output cell split/merge, Euclidean seam weld, nearest-point repair, validator change, fallback/recovery, or fixture/count special case was added.

The prior runtime translation `29` is not a required constant. The artifact test must accept a different deterministic integral periodic translation when it follows the source-strip contract.

### Row-order regression correction

The row-order test now maps each mesh's raw route/cut source-edge IDs through that mesh's authoritative `EV` table to ordered endpoint keys `(min(v0,v1), max(v0,v1))` and compares the ordered sequences. It does not sort away route order or alter production DCEL numbering. Existing grid, rotation, translation, disposition, and periodic semantic assertions remain.

A new compiled structural regression derives the genuine source-boundary vertices from `EV/EF` and requires every one to occur as an exact phase-front corner on the two annulus boundaries, without encoding the committed cylinder ring count or expected output count.

## Compile authority

- source commit `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- `SurfaceCellTracing.cpp` blob `9df9a9759c761293fef1278f97b82fbb0aee0600`;
- `SurfaceCellsPhase10Tests.cpp` blob `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`;
- run/job `31204848178` / `92953250176`;
- build artifact `9004509871`, SHA-256 `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- detailed log artifact `9004508508`, SHA-256 `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`;
- recursive checksums **44/44**;
- compile/link actions **111/111** across seven approved targets;
- five executables, two project libraries, 27 fixture/input files;
- Release static / Ninja / GNU C++ 13.3.0 / CMake 3.31.6 / `PRE_TEST`;
- packaged `runtimeExecution=false`; no generated project binary/test/benchmark executed.

This is compile evidence only. It does not establish that the cylinder's completed validation is fixed.

## Required verification sequence

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9004509871`.

The next turn is artifact-only Test + Benchmark:

1. verify outer digest, all 44 recursive checksums, exact source/patch/blobs, fixture closure, and command-boundary metadata;
2. execute the six focused periodic/output-validation contracts first, including the corrected canonical row-order route identity and source-strip breakpoint contract;
3. revalidate plane, seam, and close sheets;
4. execute exact production cylinder as active G3 acceptance;
5. require periodic `Produced`, direct pure-quad `CompletedSurfaceCells`, exact periodic quotient, retained canonical source-strip breakpoints, complete provenance, and zero completed-checkpoint validation failures;
6. allow periodic translation/grid cardinality to differ from the old `29` when determined by the source-strip subdivisions;
7. execute bounded determinism/default suites only after the direct gate decision;
8. observe bunny/vase only as later-gate evidence.

No rebuild or source/test/fixture/validator/build edit is allowed during that turn.

## G3 acceptance

G3 closes only if artifact-only validation proves the exact cylinder remains authoritative periodic `Produced` and becomes direct deterministic strict-valid `CompletedSurfaceCells` pure-quad output with correct source-strip-conforming periodic quotient, complete provenance, zero completed-checkpoint validation failures, no fallback/recovery, and retained plane/seam/close-sheet success.

If another exact source-authoritative structural/validation failure is reached, preserve it and address only that general failure in the next Code + Build turn.

## Deferred work

Do not broaden G3 into:

- torus/general genus;
- singularities or G4 topology-distinct completion;
- adaptive 2:1 transitions;
- hard-feature expansion;
- bunny/vase production/performance;
- scheduler timing;
- historical downstream completion/simplification repair;
- broad diagnostics or validator changes unrelated to G3 structural correctness.

## Acceptance discipline

No validator weakening, fixture special cases, generic-producer substitution, fallback/recovery, positional sheet merging, Euclidean periodic seam welding, arbitrary subset search, synthetic topology correction, post-hoc cycle/cell merging, or timeout-as-correctness is allowed.