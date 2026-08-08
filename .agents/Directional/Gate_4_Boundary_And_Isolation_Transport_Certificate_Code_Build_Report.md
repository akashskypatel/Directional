# Gate 4 Boundary and Isolation-Transport Certificate — Code + Build Report

Status: **compile-valid candidate; immutable runtime validation pending**
Turn type: **Code + Build only**
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Compile record

Implementation **`82151bf51bce9af9859282b2a03e295a0ee5a309`** (`feat(surface-cells): certify boundary and isolation transport`) and payload cleanup/build authority **`846b23a1175f541d86e880c993784715c995ef20`** were pushed from exact entering branch head `63a65cd9ee938212b2e6e9ddb8f1081cbe44e6a3` after the approved six-file patch was verified byte-for-byte.

Exact compile artifact:

- ID **`9026181778`**;
- name `g4-boundary-isolation-certificate-code-build`;
- workflow run/job **`31272661747 / 93141125742`**;
- workflow event commit `9f0e6de3e4a1f70eb02d2946072305c7b8c9b5ad`;
- outer ZIP SHA-256 `0682ae9fe6e98eefac8e4ddb2ccc8db8407326d7b872ec6da1d945aa8a59b79d`;
- internal `SHA256SUMS` SHA-256 `c63931f3cd9c6261710bd9db255a49aa03029a39d062fe21c714529c4b31fdb1`;
- recursive checksums **48/48**;
- package **49 files / 27 fixtures / five executables / two project static libraries**;
- packaged source archive SHA-256 `08fa7f4403145216c1316240a4494c7fa069d77f2518ddbc6346812bcb91bdba`;
- packaged implementation patch SHA-256 `b092219704f360e2f013cdeab83a12c870ac8e804f52f325edcfca2d2a17faac`;
- decoded implementation patch SHA-256 `b93f420d7f9c8139663f8ff573613eeb23dd3c30073ff76c8b563c537fd07f10`;
- dedicated log artifact **`9026181889`**, outer ZIP SHA-256 `d53a060c2b3b20205ce71b3cf44f0fe9f14a2a207a176ec74faf9a8d57e9c890`;
- Release/static/Ninja approved build **113/113**;
- GoogleTest discovery `PRE_TEST`;
- toolchain CMake 3.31.6, GCC 13.3.0, Ninja 1.13.2;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, polyscope `59da72df6517cab8379865899bdffdbc96171301`;
- artifact metadata `runtimeExecution=false`, review policy `never`.

The downloaded outer digests match GitHub artifact authority. Both ZIP archives pass integrity checks, all 48 recursive entries pass, all six source blobs match the packaged implementation tree, and the source archive excludes the bounded workflow, trigger, and patch payloads. The five packaged executables are ELF files and both project libraries are valid static archives.

No generated Directional binary, test, benchmark, `ctest`, GoogleTest discovery/list command, CLI/GUI command, help/list/version command, or custom-input command was executed during this turn.

## Implemented contract

The candidate implements the review-approved boundary and isolation authority:

- genuine one-face source boundaries retain canonical non-empty `sourceRouteTopology` and no invented interior `sourceRouteEdges` index;
- two-face hard-rail, embedded-relief, and periodic routes remain exact-index strict, while `edge_matching_indices()` remains interior-only;
- the producer emits exactly one canonical reciprocal transport certificate per retained internal isolation seam, including component/region owner, canonical edge and incident faces, local sheets, interior edge index, reciprocal quarter turns, and deterministic structural hash;
- malformed, duplicate, owner/sheet-mismatched, same-sheet, boundary, or nonreciprocal certificates fail closed with typed producer/materializer authority;
- materialization validates the region-seam/certificate bijection, builds the local-sheet connectivity graph, and checks cells, fronts, relations, quotient classes, equivalence lineage, diagnostics, and hashes against that authority;
- explicit cell-side seam transitions remain exact crossing evidence but are no longer required to witness every retained source seam;
- the explicit occurrence quotient remains limited to reciprocal ordinary sides, exact hard-rail counterparts, and explicitly owned full periodic `R^r p+t` relations; no lattice/position welding or representative-sheet substitution was introduced;
- failed tracing retains or releases intermediate trace authority exactly according to `retainIntermediateGeometry`.

## Compile-visible counterfactual closure

`tests/SurfaceCellTransitionQuotientTests.cpp` is now part of the default `directional_surface_cell_producer_tests` executable, with `src/bench/BenchmarkQuality.cpp` linked into the same target. It contains **33 independently named tests** spanning boundary/index separation, seam-certificate positive and broken cases, multi-isolation lineage, disconnected coincident components, reciprocal ordinary endpoints, full periodic transforms and relation ownership, hard rails, output incidence, failure retention, and semantic digest invariance/sensitivity. The historical suite remains disabled.

`SurfaceCellsPhase10Tests.cpp` now makes the torus and cylinder integration contracts strict and direct, requires topology-first diagnostics, exact authority consumption, pure-quad lineage, and no fallback/recovery. These tests compiled but were deliberately not discovered or executed in this turn.

## Source authority

| File | Git blob |
|---|---|
| `cmake/DirectionalTests.cmake` | `e82e3088e11f215f030b58be7fb6531a5dbaa99a` |
| `include/directional/geometry/SurfaceCellTracing.h` | `663b3fc4f944c7136ebceffb9bd0b3e7db16d16b` |
| `src/geometry/SurfaceCellTracing.cpp` | `877fcef94eaf60a9dae8a1aa01e69d03c2826431` |
| `src/pipeline/RemeshPipeline.cpp` | `8281bbae78ac723004aefe257eaabac70c5f107d` |
| `tests/SurfaceCellTransitionQuotientTests.cpp` | `c545264e2bb1f012a94c4772bd93c8004aa4fb4b` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `d34b5f097cf39ac72f060616a37d360e382af168` |

## Runtime status and next authority

Compile success is not product acceptance. The exact candidate has not been executed. The only authorized next turn is immutable artifact-only Test + Benchmark under `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Plan.md`.

That turn must prove every reviewed counterfactual is independently discoverable and passing, restore retained G0-G3/direct plane-seam-close-sheets-cylinder authority, and require exact torus direct strict-valid pure quads with complete lineage, one connected component, zero boundary loops, Euler zero, and all four regions/eight seams/four periodic relations consumed. No predicted torus output count is permitted. Sphere, G5/G6, historical completion repair, validator changes, fallback/recovery, and unrelated optimization remain deferred.

## Repository hygiene

The workflow removed all three verified raw payload parts in build/cleanup commit `846b23a1175f541d86e880c993784715c995ef20`. After artifact verification, the bounded workflow was removed in `a4d759c03d0f2fbdf8e641f8c7427c0e712b3ffc` and its trigger in `5bea46d3cca0d6209c71947149dea765a8c5e7cd`. End-state verification must retain only `.github/workflows/agent-source-snapshot.yml` and no bounded trigger/payload state.
