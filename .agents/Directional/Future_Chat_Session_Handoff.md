# Future Chat Session Handoff

## Mandatory next turn

Run **M1b First Production Consumer — immutable Test + Benchmark** under:

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1 first production-consumer adoption**;
- M1a kernel: **immutable accepted**;
- M1b production consumer: **compile/package complete, runtime pending**;
- review policy: `never`.

Do **not** edit or rebuild in the next turn. Consume only the immutable M1b artifacts below. Another production consumer remains blocked until M1b runtime acceptance passes.

## Completed M1b Code + Build

Authoritative report:
`.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Report.md`.

Exact authority:

| Evidence | Value |
|---|---|
| M1b base | `9a4131f9655567ffc60c2c513db1c73826165bb2` |
| Initial migration commit | `f768c2f434e2f340f4d7be3192d48abff645a78e` |
| Corrected implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| Build/event commit | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| Workflow run/job | `31330737703 / 93288453677` |
| Result artifact | `9042940168` |
| Result SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| Log artifact | `9042940336` |
| Log SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Recursive manifest | **53/53**, `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| Package regular files | **54** including manifest |
| Compile closure | Release/static/Ninja **120/120**, `PRE_TEST` |
| Build wall / peak RSS | **8:07.42 / 1,836,308 KiB** |
| Runtime execution | **false** |
| Retention | through **2026-08-23 UTC** |

Package preflight already confirmed seven ELF executables, two static libraries, all 27 fixtures, exact source patch/archive/compile DB/source blobs, and static 6/14/29-name manifests. No generated Directional binary, test discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input ran in Code + Build.

## M1b exact production migration

Selected call path:

`RemeshPipeline -> fill_surface_optimization_rail_constraints -> surface_optimization_rail_detail::provenance_supports_interval_sheet`.

Ignoring temporary connector files removed after artifact capture, exactly five source/test/build paths changed:

1. `CMakeLists.txt`;
2. `cmake/DirectionalTests.cmake`;
3. `include/directional/geometry/SurfaceOptimizationRailConstraints.h`;
4. `src/geometry/SurfaceOptimizationRailConstraints.cpp`;
5. `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

Key changes:

- `src/authority/AuthorityKernel.cpp` is now owned once by `directional_core`; the authority test target no longer compiles it directly;
- `source_face_contains_vertex` consumes `SourceFaceId` and `SourceVertexId`;
- existing legacy face/sentinel/extent validation occurs before named conversion;
- source vertices extracted from source-face topology reject negative values and cross `LegacyAuthorityAdapters::source_vertex` once;
- typed IDs remain typed until explicit matrix/vector indexing;
- component/sheet logic, same-sheet fast path, `1e-8` barycentric support classification, source-incidence semantics, rail assignment, projection, optimizer policy, public structs, and product disposition are intentionally unchanged.

The source-vertex adapter uses the complete nonnegative legacy-`int` extent because the pre-M1b seam had no independent `sourceVertices.rows()` rejection. Do not silently tighten that behavior during runtime acceptance; exact source-support rebinding remains M5/AR-09.

## Static M1b authority packaged

Six new focused contracts are in `directional_surface_cell_validation_tests`:

1. `SurfaceOptimizationRailAuthorityMigration.SameSheetRailAssignmentRemainsAccepted`
2. `SurfaceOptimizationRailAuthorityMigration.CrossSheetExactVertexAndEdgeIncidenceRemainAccepted`
3. `SurfaceOptimizationRailAuthorityMigration.CrossSheetInteriorProvenanceRemainsRejected`
4. `SurfaceOptimizationRailAuthorityMigration.InvalidLegacySourceFacesRemainRejected`
5. `SurfaceOptimizationRailAuthorityMigration.WrongSourceFaceWithoutTypedSupportRemainsRejected`
6. `SurfaceOptimizationRailAuthorityMigration.SourceFaceComponentAndSheetAuthorityMismatchRemainRejected`

Focused static manifest SHA-256:
`a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`.

Compile-time assertions in the same source prove the helper's exact `(SourceFaceId, SourceVertexId)` signature and reject domain swapping.

The validation target now contains **77** static tests: accepted baseline 71 plus six M1b contracts.

Preserved immutable manifests:

- M1a authority kernel: 14 names, `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- T1 oracle: 29 names, `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

## Mandatory next-turn procedure

Preflight:

1. verify result/log ZIP hashes exactly;
2. reject unsafe archive paths;
3. verify **53/53** package checksums and exact source/dependency authority;
4. require `runtimeExecution=false` from Code + Build;
5. verify static focused/M1a/T1 manifests and the five-path M1b source diff;
6. add only a non-regular `bin/test-data -> ../test-data` locator if required.

Focused M1b acceptance:

1. list validation tests **exactly once**;
2. require **77** total native GoogleTest names and exactly the six `SurfaceOptimizationRailAuthorityMigration` members above;
3. run those six individually in fresh processes and require **6/6**;
4. run the complete validation target and require **77/77**.

Preservation:

1. list M1a authority tests once, exact 14; run **14/14** individually;
2. list T1 oracle tests once, exact 29; run **29/29** individually;
3. run Plane, MultiFaceSeam, CloseSheets, Cylinder fresh and require green/oracle-clean;
4. run BunnyRandom as explicit known-red; if it returns, require independent-oracle evidence before fatal product-success assertion;
5. run Vase with a bounded 60-second guard; timeout/nonreturn is safety evidence only;
6. mutate no packaged regular file and re-hash everything postflight.

If anything fails, report it and return to Code + Build. **No source repair in the Test + Benchmark turn.**

## Compile-attempt lessons

Three non-authoritative attempts preceded the successful build:

- run `31330513984`: temporary transport patch malformed; stopped before configure/compile;
- run `31330597243`: first migration commit `f768c2f...` configured, then failed at `[49/120]` because the reopened rail-detail namespace was not closed;
- run `31330613165`: redundant retrigger stopped before configure because the deterministic source transformation was already applied.

The correction commit `0340addf...` changes only the missing namespace close. These attempts executed no generated project binary and do not create historical production regression events. Lesson: when rewriting namespace-scoped source through connector transformations, statically verify both opening and closing ownership boundaries before triggering the expensive compile.

## Regression status

- `RP-01`: first production adoption is **compile-complete / runtime pending**;
- `RP-05`: typed semantic identity versus row representation is **compile-complete / runtime pending**;
- `RP-02 / TA-05`: preservation boundary remains accepted but must be re-executed from the M1b artifact;
- M1b has not yet lost previously accepted runtime authority, so no new production regression event/recurrence is recorded;
- historical totals remain **34 events / 14 categories / 20 recurrences**;
- `PR8-R034 / G4-R007` remains active and separate.

## Accepted comparison authority

M1a accepted artifact `9041930767`:

- authority kernel **14/14**;
- T1 oracle **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green/oracle-clean;
- Bunny known-red `NotProductionReady:completion`, oracle before fatal assertion;
- Vase bounded 60-second nonreturn/safety-only.

Production G4 authority remains artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads; `G4-R007` remains active.

## Core references

- `.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.

## Deferred blockers

- active representative torus `G4-R007`;
- shared hard-rail scheduling `G4-B002`;
- nonzero periodic Z4 production capability `G4-B003`;
- positive multi-isolation witness `G4-B004`;
- historical transition-quotient/completion failures;
- strict-validator timing;
- prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization;
- later M1 consumers, M2–M6 and T2–T6.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
