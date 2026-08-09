# M1b First Production Consumer — Artifact-Only Test + Benchmark Report

**Status:** ACCEPTED  
**Turn type:** Test + Benchmark only  
**Implementation under test:** `0340addf21473854856266ff00cb68915ce24ef0`  
**Product behavior delta:** none observed or accepted  
**Review policy:** `never`

## 1. Immutable authority

| Evidence | Value |
|---|---|
| M1b base | `9a4131f9655567ffc60c2c513db1c73826165bb2` |
| M1b implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| Build/event commit | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| Build run/job | `31330737703 / 93288453677` |
| Result artifact | `9042940168` |
| Result ZIP SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| Log artifact | `9042940336` |
| Log ZIP SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Recursive manifest | **53/53**, `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| Producer executable SHA-256 | `dcec7671b4ee961367e552a3e93e5b052890cf27fa14e792c4fc669ff25e71e1` |

Preflight verified both outer ZIP hashes, safe archive paths, all 53 package hashes, 54 regular package files including `SHA256SUMS`, seven ELF executables, two static libraries, 27 fixtures, exact implementation/event metadata, safe source archive, the exact five-path M1b source patch, and `runtimeExecution=false` for the Code + Build authority.

The packaged M1b source patch contains only:

- `CMakeLists.txt`;
- `cmake/DirectionalTests.cmake`;
- `include/directional/geometry/SurfaceOptimizationRailConstraints.h`;
- `src/geometry/SurfaceOptimizationRailConstraints.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

## 2. Discovery authority

Native GoogleTest discovery was performed exactly once for each required executable.

| Target | Discovery result | Output SHA-256 |
|---|---:|---|
| validation | exactly **77** tests | `ecea7f49605b6df5db31dc2ef407c5dbf455efd9456d301aabfdebae4b9eea35` |
| M1a authority kernel | exact immutable **14** names/order | `ca359bf4a81d2816daa16cc5c5334f02bc9c7fc33b0a34858714e9bfcdf30991` |
| T1 product oracle | exact immutable **29** names/order | `d43cd15871859b7bd26577f0b251508ec736f93a9bd6c8c3f089a2b9cbec02df` |

The validation discovery contains exactly the six packaged M1b members and no additional member in `SurfaceOptimizationRailAuthorityMigration`:

1. `SameSheetRailAssignmentRemainsAccepted`;
2. `CrossSheetExactVertexAndEdgeIncidenceRemainAccepted`;
3. `CrossSheetInteriorProvenanceRemainsRejected`;
4. `InvalidLegacySourceFacesRemainRejected`;
5. `WrongSourceFaceWithoutTypedSupportRemainsRejected`;
6. `SourceFaceComponentAndSheetAuthorityMismatchRemainRejected`.

The focused manifest matches exactly and retains SHA-256 `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`.

## 3. M1b focused semantic acceptance

Each focused contract ran individually in a fresh process and selected exactly one real test. Result: **6/6**.

The contracts preserve the intended consumer relations rather than only mechanics:

- same-sheet rail assignment still publishes the expected feature vertex, curve ID, and rail ID;
- exact cross-sheet shared source-vertex and source-edge incidence remains accepted;
- face-interior provenance remains confined to its authoritative sheet;
- negative and out-of-range legacy source faces reject;
- a wrong source face lacking the typed support vertex rejects;
- source-face component and sheet authority-vector mismatches reject.

Packaged source inspection also confirms the compile-time `RailContainsVertexFn` assertions require `(SourceFaceId, SourceVertexId)` and reject the swapped `(SourceVertexId, SourceFaceId)` invocation.

## 4. Validation preservation

The full immutable validation executable passed **77/77** in one aggregate execution.

Required pre-M1b rail/provenance witnesses remain present and green:

- `SurfaceMeshOptimizerPhase22.ProvenanceComponentSheetAndFaceCompatibilityAreEnforced`;
- `SurfaceMeshOptimizerPhase22.RailConstraintBuilderUsesOutputVertexSequencesForBoundaryAndFeatures`;
- `SurfaceMeshOptimizerPhase22.HardRailChartAuthorityNeverMasksScalarProvenanceFailures`.

## 5. M1a and T1 preservation

M1a authority-kernel contracts ran individually in fresh processes: **14/14**.

T1 independent product-oracle contracts ran individually in fresh processes: **29/29**.

This preserves the independent authority boundary; M1b focused helper tests do not replace it.

## 6. Direct product comparison

The required green cases ran from the immutable `directional_surface_cell_producer_tests` executable in fresh local processes:

| Case | Result |
|---|---|
| Plane | pass, **1.000 s**, independent oracle clean |
| MultiFaceSeam | pass, **1.559 s**, independent oracle clean |
| CloseSheets | pass, **12.169 s**, independent oracle clean |
| Cylinder | pass, **6.525 s**, independent oracle clean |

Four preliminary invocations mistakenly targeted the standalone `directional_benchmarks` CLI with GoogleTest filters. Each exited immediately with `Unknown benchmark option`; no test was selected or executed. They are non-authoritative orchestration attempts and do not enter acceptance evidence.

## 7. Bunny/Vase GitHub Actions runtime evidence

Per explicit user authorization, Bunny and Vase may run through GitHub Actions to avoid local execution-tool timeout limits. This turn used a temporary artifact-only workflow; it downloaded **artifact `9042940168` from build run `31330737703`**, verified the GitHub artifact digest, all 53 package checksums, the implementation commit, and the producer executable SHA before runtime. It performed no configure, compile, link, source edit, fixture edit, or artifact substitution.

GitHub Actions extraction does not preserve the executable mode of downloaded artifact files. The workflow therefore restored only the producer executable's `+x` mode **after** verifying its content hash. No packaged file content changed. A runtime-only `bin/test-data -> ../test-data` locator was also created.

### Non-authoritative orchestration attempt

Run `31332304742` verified the immutable package but both Bunny and Vase stopped before generated-binary execution with return code `126` (`Permission denied`) because the artifact download had stripped executable mode. This attempt is not runtime acceptance evidence.

### Authoritative runtime run

Workflow run `31332383845`:

| Case | Job | Result |
|---|---|---|
| BunnyRandom | `93292577409` | selected one real test; returned **rc=1** after wrapper **64 s** / GoogleTest **63.865 s** |
| Vase | `93292577420` | selected one real test; bounded **rc=124** after **60 s** |

BunnyRandom retains the accepted T1 known-red signature and execution order:

1. the independent oracle rejects the returned result first with `EmptyOutput`, `NonQuadOutput`, connected-component mismatch, Euler-characteristic mismatch, output-origin mismatch, and `TerminalFailureObserved:NotProductionReady:completion`;
2. only afterward does the unchanged fatal `result.success` assertion fail with `terminal=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

Bunny is therefore not green and is not treated as an M1b regression.

Vase started the exact selected production test and did not return within the 60-second guard. This remains **runtime-safety evidence only**, not correctness and not proof of nontermination.

Retained runtime evidence:

| Evidence | Artifact | SHA-256 |
|---|---:|---|
| Bunny runtime | `9043307980` | `c2e7776a9b68ffeeecc7471a3718a2c1bc90fae4556c7d7c05084b5ae8d8fb2d` |
| Vase runtime | `9043307204` | `1726deb422a3eea238ab3895108a423f6fb6e932cabcc6b215916cc969e87105` |

The temporary workflow and trigger were removed before closeout, so they create no net repository diff.

## 8. Postflight

Postflight reverified:

- result ZIP SHA-256 `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b`;
- log ZIP SHA-256 `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614`;
- `SHA256SUMS` digest `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1`;
- all **53/53** packaged regular-file checksums;
- exactly 54 regular package files; the only local runtime addition is the non-regular fixture symlink.

## 9. Architecture and regression disposition

M1b is **accepted** as the first real production adoption of the M1 authority kernel.

- `RP-01`: accepted for the `SurfaceOptimizationRailConstraints` source-face/source-vertex consumer seam.
- `RP-05`: accepted for semantic source IDs remaining distinct from matrix/vector row representation at this seam.
- `RP-02 / TA-05`: preserved by exact M1a/T1 discovery, 14/14 + 29/29, full validation, and direct independent-oracle comparison.
- `RP-03/04/06/07/08/09`: not migrated by M1b.
- No new production regression event or recurrence is created.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** and separate; M1b does not change the known direct-torus authority.

## 10. Procedural rule for long-running direct cases

For future immutable Test + Benchmark turns, Bunny and Vase are authorized to use an **ephemeral GitHub Actions artifact-only runner** instead of the local container when this avoids execution-tool timeout limits. The runner must:

1. download the exact immutable artifact by run/artifact identity;
2. verify the GitHub artifact digest, package manifest, every packaged checksum, implementation metadata, and selected executable hash before execution;
3. never configure, compile, relink, regenerate, substitute, or edit product/test/fixture content;
4. restore executable mode only after content-hash verification if the download action strips mode bits;
5. run exact selected production tests with explicit process guards;
6. retain stdout/stderr, selection/filter, return code, elapsed time, and evidence artifact digest;
7. remove temporary workflow/trigger files before turn closeout so the net implementation/test/build diff remains zero.

## 11. Following turn

Proceed to one new bounded **Code + Build** slice only. The next plan is:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Plan.md`.

M1c migrates only the authoritative `CrossFieldEdgeTransition` consumption seam in `surface_cell_tracing_detail::resolve_branch_transition` to checked source IDs/source-edge identity and typed `QuarterTurn` transport. Public field storage and all producer/tracing policies remain compatibility boundaries; broader chart/route migration stays deferred.
