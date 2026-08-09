# Gate 4 Canonical Transition Test Authority Remediation — Code + Build Report

Status: **completed**
Turn type: **Code + Build only**
Active design gate: **G4 topology-distinct completion and singularities**
Date: **2026-08-09 UTC**
Review policy: `never`

## Outcome

The five test-authority corrections compiled successfully in the same Release/static/Ninja configuration as the entering implementation. Exactly the seven approved targets compiled. No production source, CMake, fixture, manifest, validator, benchmark, completion/simplification, or unrelated test changed.

No generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI command, help/version command, or custom input was executed. `runtimeExecution=false`; this report makes no runtime correctness or benchmark claim.

## Source authority

| Authority | Value |
|---|---|
| Entering branch head | `2703f2f94e77afa4c7ed397200ddd456413c7125` |
| Test-remediation implementation | `de5261c7185aef71807b0b4140c8f023a44874fd` |
| Workflow commit | `b09426ea25425e4172aaa5572af60f884d202268` |
| Build/event commit | `5bf9b0efc665e0a940aa4e74b168171651685f7d` |
| Workflow cleanup commit | `6857b0635b5ac984d467aec81ea340ce194919d5` |
| Trigger cleanup commit | `d6267089ccafe76c7111064d5a22a74fdd4cef05` |
| Transition quotient test blob | `42111d1de51baa6cca85171aeab339813cae3b50` |
| Phase10 test blob | `552a3d98ec8f9280b960fb9bbff9a1c7596a0778` |
| Unchanged tracing header blob | `b87e37676a980162e7ef3ac1fa9d954ce2199ad2` |
| Unchanged tracing implementation blob | `4809e66bb6e797001ffc22b3f2da6d3613cfdef0` |
| Unchanged pipeline implementation blob | `0a55429fc83d429ae2176ce3bbaac573682c48eb` |
| Unchanged test CMake blob | `e82e3088e11f215f030b58be7fb6531a5dbaa99a` |

The entering-to-implementation comparison is one commit ahead, zero behind, and modifies exactly:

- `tests/SurfaceCellTransitionQuotientTests.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

## Corrected test authority

### Serialized three-domain witness

The old disconnected-overlapping-square helper selected a pairwise-distinct regional topology without proving that topology occurred in a materializer-facing route. The positive test therefore failed at its witness check, and both negative tests failed before materialization.

The replacement test-only fixture contains two disconnected planar topology regions: a unit square followed by a 2-by-1 rectangle, each triangulated by one interior diagonal. The first region shifts the source-wide compact domain. The second region's non-square phase grid naturally crosses its later-region interior diagonal instead of meeting it only at square-grid junctions.

The witness is now selected only while enumerating actual produced cell `boundaryPaths`. It records the exact cell, side, segment, and route position and requires:

- equal numeric/topology sequence lengths;
- the serialized value to equal the source-wide compact map for the parallel topology;
- the owning cell's topology region to contain the regional compact entry;
- exactly one CrossField transition with the same canonical endpoints and reciprocal incident faces;
- the transition's full-`EF` row to resolve to the same canonical endpoints and reciprocal `mesh.EF` faces;
- source-wide compact, region-local compact, and full-`EF` values to be nonnegative and pairwise distinct.

The positive test validates that exact serialized position, every numeric/topology pair in every produced cell route, genuine topology-only source boundaries, and successful materialization. The two tamper helpers mutate the exact recorded route position, prove the replacement occurred, and preserve the exact `InvalidAuthoritativeTransitionSourceEdge` expectation.

### Face-row-invariant periodic authority

`PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` no longer interprets compact route/cut values as `mesh.EV` rows. It compares the ordered canonical route and cut topology sequences across exact face/raw-field row reversal, compares the parallel compact sequences, and independently validates every numeric/topology pair through each mesh's source-wide compact map. Grid dimensions, quarter-turn rotation, lattice translation, and meaningful route order remain unchanged.

### Malformed holonomy tamper

`PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` now selects the intended route through `sourceRouteTopology`. It requires one matching CrossField transition by canonical endpoints plus reciprocal incident faces, verifies that transition's full-`EF` row against both `mesh.EV` and `mesh.EF`, then applies the same matching mutation. The authoritative expectations remain exactly `Rejected / PeriodicHolonomyMismatch` with empty seeds, traces, and proposals.

## Static verification

Before the remote build:

- the local source closure reproduced both entering branch blobs;
- the final diff contained only the two allowlisted test files;
- no compact route/cut index remained as a `mesh.EV` lookup or direct `CrossFieldEdgeTransition.sourceEdge` comparison;
- every new numeric route assertion was paired positionally with topology;
- no semantic or typed-failure assertion was removed or weakened;
- no fixture name, observed output count, source numeric ID, predicted hash, or ordering accident became production authority;
- whitespace checks, YAML parsing, and all eight workflow shell-block syntax checks passed.

The remote commit reproduced the local output blobs exactly.

## Compile authority

| Evidence | Value |
|---|---|
| Workflow run/job | [`31284957305 / 93172020467`](https://github.com/akashskypatel/Directional/actions/runs/31284957305) |
| Result artifact | [`9029584083`](https://github.com/akashskypatel/Directional/actions/runs/31284957305/artifacts/9029584083), `g4-canonical-transition-test-authority-code-build` |
| Result artifact SHA-256 | `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad` |
| Log artifact | `9029584200`, `g4-canonical-transition-test-authority-code-build-logs` |
| Log artifact SHA-256 | `b2c147a691caaafc6591106ebb59f50f2956c17722f88bff1857c94d33f3da9b` |
| Recursive manifest | **49/49**, digest `ee65be615bcf59516f5c0e05f98e56b7d9095d48d41cb1675cb5e3938ad7ce26` |
| Test patch SHA-256 | `96e96f3a2bb4492f208600359aefec59c70a0a138b0ccfcf0dca03e40b5650ef` |
| Source archive SHA-256 | `b3d1848ac9710044104e4be5382f2d1af3adf00314ed7b22a566aead8469d376` |
| Retention | through `2026-08-23 UTC` |

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

Ninja completed **113/113**. The compile step used 7:38.22 wall time, exited zero, and peaked at 1,812,340 KiB resident memory.

## Artifact verification

Independent post-download verification established:

- both outer artifact digests match GitHub;
- all **49/49** recursive checksum entries pass;
- the package contains 50 files, five valid ELF executables, two valid static libraries, and all 27 exact fixture files;
- the source archive reproduces all six expected source/CMake Git blobs;
- the archived patch names exactly the two allowlisted tests;
- the archived workflow tree contains only `.github/workflows/agent-source-snapshot.yml` and no connector trigger;
- the build log ends at `113/113` with no failure marker;
- all logged shell exit codes are zero and the command boundary records `runtimeExecution=false`.

Compile success does not establish that the corrected witness is produced at runtime or that any assertion passes.

## Generalization review and remaining risk

The corrections are domain-based rather than fixture-ID-based: route identity is selected from actual serialized topology, compact maps are reconstructed from exact source incidence, and full-`EF` authority is validated by canonical endpoints and reciprocal faces. The only new geometry is a minimal deterministic test precondition for making the three numeric domains observably distinct on a route.

The principal remaining test risk is runtime-only: the new rectangle must actually produce the intended later-region crossing. If it does not, the test remains a fixture-authority failure and production code must remain unchanged. Torus `LocalSheetMismatch` and every other production blocker are deliberately untouched.

## Cleanup and next authority

The bounded workflow was deleted before its trigger. The next turn is artifact-only Test + Benchmark under:

`.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`

It must consume artifact `9029584083` exactly without rebuilding or editing validation logic. PR #8 remains open, draft, and unmerged.
