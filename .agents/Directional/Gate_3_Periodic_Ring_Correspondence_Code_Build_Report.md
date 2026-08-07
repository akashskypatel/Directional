# Gate 3 Periodic Ring Correspondence — Code + Build Report

## Turn decision

The bounded **Code + Build** turn is complete. The G3 adjacent-ring correspondence defect now has a compile-valid production implementation and focused regression source. **No runtime correctness claim is made in this turn.** Exact artifact-only execution is required next.

## Design declaration

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at completion/output-validation
Missing design contract: adjacent canonical annulus rings can admit multiple source-topologically valid bijections through a triangulated strip; the authoritative periodic chart must resolve that correspondence from reciprocal cross-field family/transport authority, not lexicographic source-vertex ordering
Smallest general implementation change: replace valid.front() ring-pair selection with a field-family-consistent reciprocal ring correspondence that preserves the existing annulus topology, cut, holonomy and source-strip breakpoints; accept exactly one field-consistent bijection and fail closed on zero or multiple authoritative candidates
Observable material-progress condition: the exact cylinder keeps periodic Produced authority but its inter-ring sides follow the axial field family rather than diagonal strip edges, eliminating the 37.967-degree field-P95 defect and allowing normal/warpage quality to move under their existing thresholds while plane, seam and close sheets remain unchanged regressions
Explicitly deferred work: G4 singularities/topology-distinct completion, torus/general genus, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production remediation, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization hardening
```

## Runtime authority entering the turn

Artifact `9004509871`, source `2783ea718ffb15f8fb3868795173472ab8636c1c`, remains the latest executed G3 authority:

- focused/retained contracts: **13/13**;
- plane/seam/close sheets: direct strict-valid deterministic `Produced` outputs;
- cylinder: periodic `Produced`, `r=0`, `t=(32,0)`, route 32, cut 4, 2,237 traces, 320 direct quads, 352 provenance vertices, deterministic 3/3, no fallback/recovery;
- cylinder final output withheld at `completion/output-validation:AggregateCompletionValidationFailure`;
- exact failed scalar thresholds: normal P95 `16.6272734366°`, field P95 `37.9670987281°`, warpage P95 `30.6213792811°`.

The structural defect entering this turn was the lexicographic selection of one of two topology-compatible adjacent-ring bijections. The selected diagonal/sheared source edge deviated from the intended axial cross-field family by `37.9670987281°`, exactly matching field P95.

## Production implementation

### Final source authority

- final source/test commit: `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- initial production/test implementation commit: `18f2c880f1714d8c41c9e11dadd53169756629fe`;
- initial implementation patch SHA-256: `49cd71bc5aafc33ccdfd5e5104e5a23c7452e72074aac3c7775794f55737d6de`;
- compile-only test correction patch SHA-256: `8c96fa983990ab6c3f3ace5b24b8af59678aa7d6a0b7ed4f57b06f1397d1cd56`;
- final blobs:
  - `include/directional/geometry/SurfaceCellTracing.h` → `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
  - `src/geometry/SurfaceCellTracing.cpp` → `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`;
  - `tests/SurfaceCellsPhase10Tests.cpp` → `c4671ef674228d74b96e80499abbb6846bcdf3e3`.

### Ring-correspondence authority

`build_periodic_annulus_phase_front_for_faces()` no longer sorts topology-compatible ring candidates and consumes `valid.front()` as implicit ownership.

The bounded implementation now:

1. retains the existing source-topology-compatible ring-pair candidate enumeration;
2. builds the same source-edge incidence, matching-index and explicit-transition lookup authority used by tracing/periodic transport;
3. propagates one candidate's 4-RoSy branch state through the candidate strip's face-dual graph using `resolve_branch_transition()`;
4. requires reciprocal forward/reverse branch transport on every consumed strip transition;
5. evaluates candidate inter-ring edges against one transported field family and the circumferential ring edges against its orthogonal family;
6. minimizes transported cross-field alignment energy only among topology-compatible, reciprocally transported candidates;
7. rejects effectively equal best candidates instead of tie-breaking by source vertex ID or enumeration order;
8. rejects a strip with no field-authoritative candidate instead of recovering the old lexicographic behavior;
9. preserves the previously proven source-strip breakpoint/subdivision construction, annulus cut, periodic holonomy, artificial-cut ownership, quotient identity, provenance, and one accepted cell → one output quad.

Two typed periodic failure reasons were added:

- `InvalidPeriodicRingCorrespondence`;
- `AmbiguousPeriodicRingCorrespondence`.

No validator, materializer repair, fallback, recovery, fixture identity, expected output count, Euclidean seam weld, or post-hoc cell split/merge logic was added.

## Regression source added

The producer-test source now includes:

- `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`: exact committed cylinder/field must consume exact-source-vertex V-family edges aligned with the authoritative axial field family rather than a diagonal strip edge;
- `SurfaceCellsPhase10.PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`: a synthetic 4-RoSy field constructed as the tangent bisector of the two topology-compatible rising source edges makes both ring correspondences field-equivalent; production must return typed `Rejected/AmbiguousPeriodicRingCorrespondence` with no generic seeds/traces/proposals.

Existing periodic topology, canonical row-order, source-strip breakpoint, artificial-cut pairing, malformed-holonomy and exact-cylinder producer-boundary contracts remain compiled.

## First bounded compile attempt

The first bounded build intentionally executed no project-generated binary. It established that production source compiled, then failed while compiling the newly added test source.

- run/job: `31213727511` / `92982293325`;
- source produced by the workflow: `18f2c880f1714d8c41c9e11dadd53169756629fe`;
- failure log artifact: `9007820580`;
- failure log SHA-256: `ee5d9d3ae3f69c88983652495013a2742fa4c4e1bf8c0a90a65bc392d1a0cbec`;
- failure occurred at producer-test compilation around build action 93/111;
- exact cause: Eigen expression-template return-type mismatch in two new test lambdas plus `.cross()` applied to dynamically sized row-expression temporaries;
- no build artifact was emitted;
- no generated Directional test/benchmark/runtime executable was executed.

The correction was limited to the new regression source: explicit `Eigen::RowVector3d` lambda return types, concrete three-component edge temporaries before `cross()`, and concrete zero row vectors. Production behavior was unchanged.

A cleanup push of the first trigger briefly matched the first bounded workflow's original path filter and produced a stale expected failure. It is not source/build authority and did not execute project runtime. The retry workflow used a new exact marker path and the corrected base blobs.

## Successful compile-only authority

- successful workflow run/job: `31214404170` / `92984429773`;
- build artifact: `9008118764` (`g3-periodic-ring-correspondence-code-build`);
- build artifact SHA-256: `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- detailed log artifact: `9008117677` (`g3-periodic-ring-correspondence-code-build-logs`);
- detailed log SHA-256: `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- recursive artifact checksums: **44/44 passed**;
- compile/link actions: **111/111**;
- approved targets: **7/7**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- toolchain: GNU C++ `13.3.0`, CMake `3.31.6`, Ninja `1.13.2`;
- configuration: Release, static, GTest discovery `PRE_TEST`, GMP enabled, optional PARDISO/cuDSS/SuiteSparse disabled;
- artifact metadata records `runtimeExecution=false`;
- detailed activity log records `build_exit=0` and `package_exit=0`.

The outer artifact/log SHA-256 values downloaded locally match the GitHub artifact digests. The 44-file recursive checksum manifest was verified after extraction into a fresh directory. No packaged project binary was executed during verification.

## Runtime statement

Compilation establishes source validity only. **The exact cylinder has not been executed with source `c5d2c90f...`; G3 remains runtime-open.** The latest executed cylinder result remains the three-threshold failure from artifact `9004509871` until the next artifact-only Test + Benchmark turn.

## Next turn

Execute `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9008118764` without rebuilding or editing source/tests/fixtures/validators/build logic.
