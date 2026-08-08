# Future Chat Session Handoff — Gate 4 Canonical Transition Index Artifact Validation

Status: **ready for the next turn**  
Next turn type: **Test + Benchmark only**  
Active branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Pull request: [#8](https://github.com/akashskypatel/Directional/pull/8), open, draft, unmerged  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Start here

1. Read and follow the complete `turn-based-coding-agent` skill.
2. Resolve the current PR #8 head and verify the PR is still open, draft, and unmerged.
3. Read:
   - `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Report.md`;
   - `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Plan.md`;
   - this handoff;
   - `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, and `tests/TESTING_STRATEGY.md`.
4. Treat the artifact-only plan as the sole execution authority for the next turn. Do not combine turn types.

## Completed Code + Build authority

The bounded source correction is complete.

| Authority | Value |
|---|---|
| Entering implementation | `6210522950a7167bd24c4e8ae11eb68f4f32ecca` |
| Patched implementation | `edc14d38f862b94941b249f564050e2e1f8f5287` |
| Build/event commit | `b0f8f039856aa1d0c7ff6be017cd5d3121a8efe0` |
| Workflow run/job | [`31279574458 / 93158612245`](https://github.com/akashskypatel/Directional/actions/runs/31279574458) |
| Compile artifact | [`9028103772`](https://github.com/akashskypatel/Directional/actions/runs/31279574458/artifacts/9028103772) |
| Compile artifact SHA-256 | `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a` |
| Recursive manifest digest | `06123ea4c2507ed673e1a4885c4e463a6c05ed43b7a27146b3dc2722a7631a1f` |
| Log artifact | `9028103932` |
| Log artifact SHA-256 | `1ff42b2176db5c4f9194957d744dc5f31ff3096b06526f723db0c659636544c6` |
| Runtime execution during build | `false` |

All 48 recursive manifest entries were independently verified. The package contains five executables, two static libraries, 27 fixtures, the exact source closure and patch, compile database, configure/build logs, toolchain/submodule metadata, and recursive checksums. The source archive contains only `.github/workflows/agent-source-snapshot.yml` under workflows.

Exact source blobs:

- `include/directional/geometry/SurfaceCellTracing.h`: `b87e37676a980162e7ef3ac1fa9d954ce2199ad2`;
- `src/geometry/SurfaceCellTracing.cpp`: `4809e66bb6e797001ffc22b3f2da6d3613cfdef0`;
- `src/pipeline/RemeshPipeline.cpp`: `0a55429fc83d429ae2176ce3bbaac573682c48eb`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`: `7644327ffbe30c2a6e5bda3ec977f12a3a47c922`;
- unchanged `tests/SurfaceCellsPhase10Tests.cpp`: `d34b5f097cf39ac72f060616a37d360e382af168`;
- unchanged `tests/CMakeLists.txt`: `e82e3088e11f215f030b58be7fb6531a5dbaa99a`.

The remote build compiled exactly seven approved targets at `113/113` using Release/static/Ninja and `PRE_TEST`:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Toolchain: CMake `3.31.6`, Ubuntu GCC `13.3.0`, Ninja `1.13.2`. Submodules: Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, polyscope `59da72df6517cab8379865899bdffdbc96171301`.

No generated Directional binary, test, benchmark, `ctest`, discovery/list/help/version command, CLI/GUI command, or custom input ran during Code + Build or artifact verification. Compile success makes no runtime claim.

## Implemented source contract

Four allowlisted files changed between the entering and patched implementations; `tests/SurfaceCellsPhase10Tests.cpp` remained unchanged.

The producer now builds one source-wide compact transition table from `edge_matching_indices(edge_faces(full source faces))` before topology-region production. Regional incidence remains traversal authority only. Every materializer-facing two-face route carries:

- the source-wide compact numeric transition index; and
- its canonical endpoint topology in a parallel sequence.

`SurfaceTraceSegment.transitionSourceTopology` was added for positional numeric/topology authority. Segment reversal reverses both sequences. Front, periodic, cut, boundary, and certificate producers use the same source-wide compact domain. Genuine one-face boundaries remain topology-only.

CrossField validation remains fail-closed: supplied transitions must match canonical endpoints, full-`EF` identity, and reciprocal incident faces. The full-`EF` row is validation identity, not a serialized compact index.

Materialization requires equal numeric/topology lengths and exact per-position topology-to-source-wide-compact agreement. Substitution of a full-`EF` row or region-local compact index is rejected as `InvalidAuthoritativeTransitionSourceEdge`.

Retention now separates:

- `retainRequested = options.surfaceCells.retainIntermediateGeometry`;
- `retainForExecution = retainRequested || injectFailureAfterStage >= 0`.

Internal authority may remain alive long enough to reach deterministic injection, but every success/failure return clears public trace/flow/arrangement context when retention was not requested without changing the terminal code/stage.

The focused test source uses a general disconnected-overlapping topology witness whose source-wide compact index, region-local compact index, and full-`EF` row are pairwise distinct. It adds:

- `SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
- `FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
- `RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`.

These tests have compiled but have not yet run.

## Next turn: immutable artifact-only testing

Follow `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Plan.md` exactly.

Before runtime:

1. download artifact `9028103772`;
2. verify its outer SHA-256;
3. extract into a fresh isolated directory;
4. verify the recursive manifest and all 48 entries;
5. verify metadata, exact source blobs, patch allowlist, toolchain/submodules, five executables, two libraries, and 27 fixtures;
6. stop on any mismatch—do not repair, rebuild, substitute, or mix artifacts.

Only after preflight succeeds may packaged discovery and runtime begin. Preserve exact commands, raw output, working directory, environment, exit status, and artifact identity.

Focused acceptance must run individually:

- the three new canonical-domain tests above;
- `ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
- `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

The retention test must reach identical `InjectedStageFailure / tracing` for retain true/false, with nonempty trace authority iff requested.

Preserve all previously green certificate, boundary, semantic-digest, topology/isolation, polygonal/curved/mixed, validation, compiled-API, and completion/simplification cases. Historical bounded comparison totals from artifact `9026181778` were producer `143/161`, completion/simplification `154/164`, validation `60/60`, compiled API `8/8`, aggregate `365/393`. They are comparison evidence, not predicted new totals.

## Ordered fixture classification

Use only packaged committed fixtures and the existing authoritative harness. Execute three fresh processes per attempted fixture in this order:

1. plane;
2. direct multi-face seam;
3. close sheets;
4. winding cylinder;
5. direct torus;
6. sphere only after torus authority is fully recorded and the plan permits it.

Required movement:

- plane and close sheets no longer report `InvalidAuthoritativeTransitionSourceEdge`;
- cylinder and torus no longer report numeric route/index `InvalidPeriodicCutAuthority`;
- direct multi-face seam remains deterministic with semantic digest `99c8be7159d05c2f`.

The seam digest is same-artifact semantic evidence only, not a cross-version raw-output golden. A new truthful downstream failure may remain. An unchanged route-index failure is not material progress. Torus must precede sphere.

## Entering runtime evidence and unresolved blockers

Artifact `9026181778` is the previous runtime authority. Its direct matrix was:

| Fixture | Previous result | Earliest authority |
|---|---:|---|
| plane | 0/3 | `InvalidAuthoritativeTransitionSourceEdge`, `63/162` |
| multi-face seam | 3/3 | direct 64 pure quads; semantic `99c8be7159d05c2f` |
| close sheets | 0/3 | `InvalidAuthoritativeTransitionSourceEdge`, `199/12` |
| cylinder | 0/3 | `InvalidPeriodicCutAuthority`, `287/3` |
| torus | 0/3 | `InvalidPeriodicCutAuthority`, `191/0` |

Still-explicit blockers unless artifact `9028103772` proves otherwise:

1. winding cylinder rejects nonzero accumulated periodic `Z4` matching and hard-codes rotation zero;
2. exact torus independently schedules hard-rail fronts without one conforming source-authoritative breakpoint schedule;
3. split isolation accepts its certificate but does not yet prove a quotient class spanning multiple local sheets;
4. sphere, G5/G6, bunny/vase, historical completion repair, validator/timing thresholds, fallback/recovery, and optimization remain deferred.

No fallback, recovery, generic substitution, fixture/ID special case, predicted count, validator relaxation, arbitrary subset search, positional sheet merge, synthetic topology correction, Euclidean periodic welding, post-hoc cell merge, or timeout-as-correctness is allowed.

## Repository state and closeout rules

The temporary build workflow was deleted at `d2a90538dbf495e1794beda98364da8c6fc70571`; its inert trigger was then deleted at `3ceb72c2aa7460264c49f4dbe470cc78060154e4`. Re-verify that both are absent and only `.github/workflows/agent-source-snapshot.yml` remains before closeout.

Do not edit source/tests/fixtures/validators or rebuild in the next turn. Write the artifact-only report and update planning/handoff documents only after evidence is complete. Keep PR #8 open, draft, and unmerged.

After all branch files and PR-body updates, the final repository write must be one new top-level PR #8 conversation comment. Perform no GitHub write after that comment.
