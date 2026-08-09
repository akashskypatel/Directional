# Gate 4 Torus Hard-Rail Face-Chart Authority — Code + Build Report

Status: **completed**
Turn type: **Code + Build only**
Active design gate: **G4 topology-distinct completion and singularities**
Date: **2026-08-09 UTC**
Review policy: `never`

## Outcome

The exact quotient-retained face-chart authority projection compiled successfully in the required Release/static/Ninja configuration. Exactly the seven approved targets compiled. The implementation changes only the six allowlisted optimizer, validator, pipeline, and focused-test files.

No generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI command, help/version command, or custom input was executed. `runtimeExecution=false`; this report makes no runtime correctness or benchmark claim.

## Source authority

| Authority | Value |
|---|---|
| Entering branch head | `62fc5e6fd2fb0a28817b8a67974389ac3cc466e7` |
| Implementation | `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Workflow commit | `5ed67bceec1f14ccdc1d9014f2daa20b5af53557` |
| Build/event commit | `872ae0eebb90ad31738169687f7b8c1895708076` |
| Workflow cleanup commit | `5f26d42e596b1258106cf3e2f149e7542fbdc645` |
| Trigger cleanup commit | `15cbac9224b0e424e02a37f769ee2712ad450976` |
| Optimizer header blob | `2e97d962d652ecca5e67e0d57f2f6ff71253c4c7` |
| Validator header blob | `31525023686ae568f28810f57902d0a6b7e7b1eb` |
| Optimizer implementation blob | `0cc46b2c02df28a12c93fb01d768154cc87d8011` |
| Pipeline implementation blob | `af09d3305c3f76c0611eb82d681237ea33ad573e` |
| Validator implementation blob | `86090487391086caf97ce2f9e16c59662d6ae942` |
| Focused-test blob | `336a441f88c427e5f8d01b7613bc11345a5c27d2` |
| Unchanged test CMake blob | `e82e3088e11f215f030b58be7fb6531a5dbaa99a` |

The entering-to-implementation comparison is exactly one commit ahead and modifies only:

- `include/directional/geometry/SurfaceMeshOptimizer.h`;
- `include/directional/validation/SourceAuthoritativeMeshValidator.h`;
- `src/geometry/SurfaceMeshOptimizer.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `src/validation/SourceAuthoritativeMeshValidator.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

Every remote blob reproduces the locally reviewed content exactly. Quotient formation, scalar representative selection, fixtures, manifests, CMake, benchmark acceptance, and the committed torus success test are unchanged.

## Implemented contract

The authoritative phase-front path now projects each completed output vertex's sorted/deduplicated retained source charts and exact `HardRail` equivalence records into optimization constraints and final-validator options. Projection is cardinality-aligned through `PureQuadVertexLineage.outputVertex` and fails closed if lineage is missing, duplicated, empty, or misaligned.

The shared chart resolver:

- preserves scalar `SurfacePoint` barycentric, position, component, sheet, and exact source-entity checks;
- keeps hard-feature edges as transition-graph barriers;
- begins from ordinary exact scalar rebinding;
- admits an alternate retained chart only when exact point support touches the declared hard-rail route and matching explicit rail/route/front ownership is present;
- requires one unique face-wide chart component and a matching peer relation for alternate use;
- rejects malformed, unsupported, disconnected, ambiguous, cardinality-misaligned, or nonreciprocal authority as `LocalSheetMismatch`;
- returns semantic chart identity and exact per-point chart faces without choosing by row, ID, count, order, hash, frequency, or proximity.

Optimizer label selection, centroid/reference projection, projection-cache labels, final surface sampling, and the source-authoritative validator consume the same resolved authority.

## Focused compile coverage

`tests/SurfaceMeshOptimizerPhase22Tests.cpp` adds seven named contracts:

1. positive opposite-side hard-rail quads with shared scalar representatives;
2. missing equivalence and authority-cardinality failure;
3. wrong rail, wrong route, nonreciprocal ownership, and unsupported chart;
4. genuinely ambiguous face-side rejection;
5. disconnected close-sheet rejection;
6. source face-row invariance of semantic side;
7. scalar barycentric, position, component, and sheet failure preservation.

Before the remote build, all four changed translation units and both public headers passed local C++20 syntax compilation against the exact Eigen and GoogleTest revisions. `git diff --check` passed. Those checks compiled only; no executable was linked or run locally.

## Compile authority

| Evidence | Value |
|---|---|
| Workflow run/job | [`31288505364 / 93181547076`](https://github.com/akashskypatel/Directional/actions/runs/31288505364) |
| Result artifact | [`9030700527`](https://github.com/akashskypatel/Directional/actions/runs/31288505364/artifacts/9030700527), `g4-torus-hard-rail-face-chart-authority-code-build` |
| Result artifact SHA-256 | `6eb42943aa8b27c88fa2afa45e22c5fbc9aa16da2d5cc52748de6e3e45474adf` |
| Log artifact | `9030700699`, `g4-torus-hard-rail-face-chart-authority-code-build-logs` |
| Log artifact SHA-256 | `a3d327bd6d98091e4f4394970aab1823a53324f0106c380cde37a31e99d61263` |
| Recursive manifest | **49/49**, digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97` |
| Implementation patch SHA-256 | `99f82a2faf6ae16c713936db5e77a1b2fc85ba6adc48fd76b4321c55051d48e5` |
| Source archive SHA-256 | `df412a3883560c26d45f268cddd9935a7db1221e66bef8a3af88459fe685fbfa` |
| Compile database SHA-256 | `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508` |
| Retention | through **2026-08-23 UTC** |

Configuration and dependencies:

- Release, `BUILD_SHARED_LIBS=OFF`, Ninja, GoogleTest `PRE_TEST`;
- CMake `3.31.6`, GCC `13.3.0`, Ninja `1.13.2`;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope `59da72df6517cab8379865899bdffdbc96171301`.

Compiled targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Ninja completed **113/113**. The compile step used **6:21.24** wall time, exited zero, and peaked at **1,836,364 KiB** resident memory.

## Artifact verification

Independent post-download verification established:

- both outer ZIP digests match GitHub and both ZIPs pass integrity checks;
- all **49/49** recursive checksum entries pass;
- the package contains 50 files, five valid ELF executables, two valid static libraries, and all 27 exact fixture files;
- the source archive reproduces all seven recorded source/CMake Git blobs;
- the archived patch names exactly the six allowlisted implementation/test paths and reverses cleanly against the archived implementation;
- packaged fixtures are byte-identical to the archived committed fixtures;
- the archived implementation tree contains only `.github/workflows/agent-source-snapshot.yml` and no connector trigger or payload;
- the build log ends at `113/113`, has zero compiler/build failure markers, and every logged shell step exits zero;
- command-boundary inspection finds zero generated project-runtime invocations and records `runtimeExecution=false`.

Compile success establishes only that the bounded source and tests compile and link.

## Cleanup and next authority

The bounded workflow was deleted before its trigger. Final cleanup reproduces the implementation tree exactly and retains only `.github/workflows/agent-source-snapshot.yml`.

The authoritative next turn is artifact-only Test + Benchmark under:

`.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Plan.md`

It must consume artifact `9030700527` exactly without rebuilding or editing implementation, tests, fixtures, validators, manifests, CMake, workflows, or benchmark acceptance. PR #8 remains open, draft, and unmerged.
