# Gate 4 Canonical Transition Index and Failure Retention — Code + Build Report

Status: **completed**  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Date: **2026-08-08**  
Review policy: `never`

## Outcome

The bounded canonical transition-index and public failure-retention patch compiled successfully in Release/static/Ninja configuration. Exactly the seven approved targets were compiled. No generated Directional binary, test, benchmark, `ctest`, discovery/list/help/version command, CLI/GUI command, or custom input was executed.

This report is compile authority only. It makes no runtime correctness or benchmark claim.

## Source authority

| Authority | Value |
|---|---|
| Entering implementation | `6210522950a7167bd24c4e8ae11eb68f4f32ecca` |
| Patched implementation | `edc14d38f862b94941b249f564050e2e1f8f5287` |
| Build/event commit | `b0f8f039856aa1d0c7ff6be017cd5d3121a8efe0` |
| Header blob | `b87e37676a980162e7ef3ac1fa9d954ce2199ad2` |
| Tracing implementation blob | `4809e66bb6e797001ffc22b3f2da6d3613cfdef0` |
| Pipeline implementation blob | `0a55429fc83d429ae2176ce3bbaac573682c48eb` |
| Transition quotient test blob | `7644327ffbe30c2a6e5bda3ec977f12a3a47c922` |
| Unchanged Phase10 test blob | `d34b5f097cf39ac72f060616a37d360e382af168` |
| Unchanged test CMake blob | `e82e3088e11f215f030b58be7fb6531a5dbaa99a` |

The entering-to-implementation comparison is four commits ahead, zero behind, and modifies exactly:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

No fixture, manifest, validator, benchmark acceptance, completion/simplification implementation, cross-field extraction, CMake, or unrelated test changed.

## Implemented contract

The patch establishes one materializer-facing transition-index domain: the source-wide compact `edge_matching_indices(edge_faces(full source faces))` table. Regional incidence remains traversal authority only. Every serialized two-face transition route now carries the source-wide compact numeric index and its canonical topology in parallel.

Cross-field authority remains fail-closed: supplied transition topology, full-`EF` identity, and reciprocal incident faces are validated before serialization. Genuine one-face boundaries remain topology-only.

Materialization now requires equal numeric/topology route lengths and exact per-position agreement between canonical topology and the source-wide compact index. Full-`EF` rows and region-local compact indices are rejected as `InvalidAuthoritativeTransitionSourceEdge`.

Pipeline retention now distinguishes:

- `retainRequested`: the public `retainIntermediateGeometry` contract;
- `retainForExecution`: temporary internal ownership needed to complete execution or deterministic failure injection.

All terminal paths clear public intermediate trace/flow/arrangement authority when retention was not requested while preserving the terminal failure code and stage.

The focused regression source contains a general disconnected-overlapping topology witness whose source-wide compact index, region-local compact index, and full-`EF` row are pairwise distinct. It covers the valid source-wide route, both invalid substitutions, and topology-only genuine boundaries. Existing retain true/false integration assertions remain unchanged.

## Static verification

Before the remote build:

- the local entering snapshot matched the exact remote blobs;
- the implementation diff was inspected against the allowlist;
- all `transitionSourceTopology` reads and writes were audited;
- braces were balanced;
- whitespace checks were clean;
- the unchanged Phase10 integration source and test CMake authority were confirmed.

Static inspection is not substituted for the deferred runtime turn.

## Remote compile authority

| Evidence | Value |
|---|---|
| Workflow run | [31279574458](https://github.com/akashskypatel/Directional/actions/runs/31279574458) |
| Job | `93158612245` |
| Configuration | Release / static / Ninja / `PRE_TEST` |
| Compile progress | `113/113` |
| Runtime execution | `false` |
| CMake | `3.31.6` |
| Compiler | Ubuntu GCC `13.3.0` |
| Ninja | `1.13.2` |

Exactly these seven targets compiled:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

`directional_compiled_api_tests` and `directional_surface_cell_validation_tests` are the repository’s actual target names for the conceptual API-compile and validation targets named in the plan. The compile log contains no `FAILED`, compiler `error:`, or `ninja: build stopped` marker.

Submodule authority:

- Eigen: `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest: `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope: `59da72df6517cab8379865899bdffdbc96171301`.

## Immutable artifacts

| Artifact | ID | GitHub SHA-256 |
|---|---:|---|
| [Compile package](https://github.com/akashskypatel/Directional/actions/runs/31279574458/artifacts/9028103772) | `9028103772` | `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a` |
| Compile logs | `9028103932` | `1ff42b2176db5c4f9194957d744dc5f31ff3096b06526f723db0c659636544c6` |

The package’s recursive `SHA256SUMS` file has digest `06123ea4c2507ed673e1a4885c4e463a6c05ed43b7a27146b3dc2722a7631a1f`. Independent download verification established:

- outer ZIP digest equals GitHub’s digest;
- all **48/48** recursive manifest entries pass;
- the package contains 49 files including `SHA256SUMS`;
- five executables, two static libraries, and 27 committed fixtures are present;
- source closure, implementation patch, compile database, configure/build logs, metadata, and toolchain/submodule records are present;
- the source closure reproduces all six expected source/CMake blobs;
- the implementation patch names exactly the four changed allowlisted paths;
- the archived workflow tree contains only `.github/workflows/agent-source-snapshot.yml`;
- metadata records implementation `edc14d38f862b94941b249f564050e2e1f8f5287`, build/event `b0f8f039856aa1d0c7ff6be017cd5d3121a8efe0`, entering artifact `9026181778`, entering head `6210522950a7167bd24c4e8ae11eb68f4f32ecca`, and `runtimeExecution=false`.

No packaged executable was invoked during verification.

## Workflow cleanup

The bounded workflow was removed before its trigger:

1. workflow deletion commit `d2a90538dbf495e1794beda98364da8c6fc70571`;
2. verified workflow path absent while the inert trigger remained;
3. trigger deletion commit `3ceb72c2aa7460264c49f4dbe470cc78060154e4`.

Only `.github/workflows/agent-source-snapshot.yml` is retained.

## Runtime work intentionally deferred

The authoritative next turn is the artifact-only Test + Benchmark plan:

`.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Plan.md`

It must consume artifact `9028103772` without rebuilding or editing source/tests/fixtures/validators. Required acceptance includes the new canonical-index counterfactuals, exact failure-retention behavior, prior green suites, direct fixture classification, and same-artifact semantic evidence. Nonzero periodic rotation, shared hard-rail scheduling, and the multi-isolation lineage witness remain separate blockers unless the immutable artifact proves otherwise.

G4 remains active. PR #8 remains open, draft, and unmerged.
