# Gate 4 Source-Sheet Boundary Authority — Current Runtime Report

Date: 2026-08-08 UTC  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Current runtime authority

Exact artifact **`9019024467`** (`g4-source-sheet-boundary-code-build`) is the current runtime-proven authority until the newer polygonal boundary-phase candidate executes.

Authority:

- workflow run/job `31247546780 / 93078496378`;
- implementation `b425898fa7367406fa0c07e8f4441a37efc01315`;
- cleanup `3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`;
- ZIP SHA-256 `a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`;
- internal manifest SHA-256 `7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`;
- recursive checksums **48/48**;
- package 49 files / 27 fixtures / five executables / two project static libraries;
- artifact-only validation made no source/test/fixture/validator/benchmark/build edit or configure/compile/relink/discovery regeneration.

The packaged tests retain an Actions absolute fixture path. Validation exposed immutable fixtures through the allowed runtime-only symlink:

`/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_boundary_runtime_9019024467/test-data/benchmarks/fixtures`

## Focused authority

- non-hard source-sheet-boundary semantics **3/3**;
- combined source-sheet-boundary + curved-disk semantics **9/9**;
- sheet coverage **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**.

The source-sheet boundary correction is runtime-live: a local edge is accepted when it is a genuine source boundary, a hard-feature internal boundary, or a non-hard internal edge whose opposite source face belongs to a different authoritative component/sheet. The same physical non-hard edge remains an invalid hidden cut when both incident faces share the same authoritative component/sheet. Face-row re-enumeration remains invariant.

## Direct G0-G3 authority — deterministic 3/3

| Fixture | Direct output | Hash |
|---|---|---|
| plane | 64 quads / 81 V | `730caeae49ec872c` |
| multi-face seam | 64 quads / 81 V | `5bdf34d7802e9fb0` |
| close sheets | 200 quads / 242 V / 2 components | `89b052762f52a5af` |
| cylinder | 288 pure quads / 320 V | `32135be51d7a0a26` |

Every direct run reports `Produced / CompletedSurfaceCells`, zero strict-validation failures, no fallback attempt/use, and no source-grid recovery. Cylinder retains one periodic relation `r=0`, `t=(32,0)`, source route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells and exactly two genuine exterior 32-edge loops. The artificial periodic cut is not exterior.

## Exact torus — first runtime blocker

Three independent direct processes deterministically report:

- producer `Rejected`;
- first invalid stage `tracing/phase-front`;
- first invalid reason **`InvalidBoundedDiskBoundaryPhase`**;
- first invalid source face `-1`;
- periodic authority remains live before rejection;
- compatibility projection exposed by diagnostics: `r=0`, `t=(24,0)`, route 24, cut 2;
- traces/arrangement/simplified/completed output all zero;
- output origin `None`;
- terminal `NotProductionReady:tracing`;
- no fallback attempt/use, legacy substitution, returned-input fallback, or source-grid recovery.

Stable stage hashes across all three runs:

- feature `f15e4f3be07d3c7f`;
- metric `34cb872327c9b0c6`;
- relief `8ccb10d25b69edb9`;
- source labels `e48c84177faf6e2c`;
- tracing `e9b7fe2146bd7895`.

Artifact `9019024467` does not expose which global four-run/canonical-order boundary-phase subcheck fired. No unobserved torus run count or branch sequence is claimed. Raw source IDs, relation counts, sheet counts and boundary lengths are diagnostics only, never ownership/branching keys.

## Bounded suites

- producer **115/116**; sole failure remains `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`, the existing sub-millisecond performance threshold;
- completion/simplification **154/164**, exact same ten historical failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **337/348**.

## G4 decision

**G4 remains active.** Artifact `9019024467` established material progress by proving non-hard authoritative source-sheet boundary semantics and advancing exact torus from `InvalidBoundedDiskTopology` to the deeper global `InvalidBoundedDiskBoundaryPhase` invariant without regressing prior authority or invoking fallback/recovery.

The subsequent Code + Build is complete. Implementation `085db9ec23ffaa509b1f5a29e72968229efa103d` is packaged as exact artifact **`9021175280`** and introduces first-class ordered bounded-disk boundary runs/phase, typed turn/index closure, rectangular fast-path retention, intrinsic polygonal chart construction, structural hashing and runtime diagnostics. Its non-rectangular front-pairing path remains deliberately fail-closed until runtime proves the generalized phase/chart is consumed.

## Next authoritative turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact `9021175280`.

The new artifact must run generalized boundary-phase semantics first, retain all current focused/direct authority, then classify exact torus across independent processes. A changed reason alone is not progress: diagnostics must prove the first-class phase/chart representation was actually retained and consumed. If torus constructs a valid polygonal phase/chart and reaches `InvalidBoundedDiskFrontPairing`, that becomes the next implementation target. Prescribed sphere remains deferred until torus reaches direct strict-valid production.

Local evidence archive for this runtime authority: `directional-g4-source-sheet-boundary-artifact-only-evidence.tar.gz`, SHA-256 `27b4d62c6bde5f21475ddd31a42a10c02ffbad379931fd1b728c0506a6287030`.
