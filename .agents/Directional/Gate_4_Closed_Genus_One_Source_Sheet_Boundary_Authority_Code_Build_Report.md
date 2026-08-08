# Gate 4 Closed-Genus-One Source-Sheet Boundary Authority — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The curved-disk source-sheet-boundary authority correction is **compile-valid and packaged**. It is **not runtime-validated in this turn**.

The implementation closes the exact contract mismatch exposed by runtime artifact `9016834575`: a curved-disk local boundary may be an authoritative source-sheet/component boundary even when the underlying internal source edge is not marked hard. The correction accepts such an edge only when existing authoritative source labels place the opposite incident face in a different component/sheet; genuine source boundaries and hard-feature internal boundaries remain valid, while hidden same-component/same-sheet cuts remain fail-closed.

No generated Directional binary, test, benchmark, `ctest`, discovery command, CLI/GUI command, help/list command, or custom-input command executed.

Exact artifact **`9019024467`** (`g4-source-sheet-boundary-code-build`) is the only candidate for the following artifact-only Test + Benchmark turn.

## Entering runtime authority

Runtime-proven authority remains artifact **`9016834575`** until the new artifact executes.

That authority proves:

- curved-disk semantics **6/6**;
- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- exact deterministic direct plane/seam/close-sheets/cylinder hashes `730caeae49ec872c`, `5bdf34d7802e9fb0`, `89b052762f52a5af`, `32135be51d7a0a26`;
- no passing direct fallback/recovery;
- exact torus deterministically reaches the curved-disk producer and rejects at `tracing/phase-front` as `InvalidBoundedDiskTopology` because a non-hard internal local boundary is authoritative by source-sheet classification.

Detailed entering runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`.

## Exact source authority

Implementation commit:

- **`b425898fa7367406fa0c07e8f4441a37efc01315`** — `fix(surface-cells): honor source-sheet boundary authority`

Payload cleanup commit:

- **`3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`** — `chore(agent): remove G4 source-sheet boundary payloads`

Raw unified-patch authority:

- SHA-256 **`c96b3d73f16f4b9391505380bc3f2cf9ec95ff5783fe843b556e95a534a6e75b`**;
- six raw text part Git blobs: `5740d314c16d253c4e1d3f3c60808b97d76c103f`, `b6c8db4d63b9c8799bd7aff4d60edfcf4ac79c2a`, `74cc12adcd6b864b172c441e496363822aa27f6c`, `221a07748efb846e4012488b5f28884efb58553b`, `59e3060c9b2300e7ea430334350d189ba9262aa0`, `208573561765a7a75542995d574e2da11d273599`;
- each raw part was verified by both Git blob and SHA-256 before concatenation;
- concatenated patch SHA-256 matched before `git apply --check` and application;
- `git diff --check` passed;
- the patch changed exactly the tracing header, tracing implementation, and Phase 10 tests.

Final packaged source blobs:

| File | Git blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `ddb8e211f073d15fcfcc6782f964f88c4dedfc5e` |
| `src/geometry/SurfaceCellTracing.cpp` | `14cf7f3a3301e9e3f10ec48a480d3f6e5efee7ed` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `31322acea5227a8e3692887fad1ec4a9e6d8c101` |

## Production correction

A reusable `source_edge_is_authoritative_local_boundary()` predicate now validates curved-disk local boundaries structurally.

For a local source edge it:

1. rejects malformed source-face incidence and invalid local-face identity;
2. accepts a genuine one-face source boundary;
3. accepts a two-face internal edge when it is a hard-feature edge;
4. otherwise requires complete valid `sourceFaceComponents` / `sourceFaceSheets` authority;
5. accepts the non-hard internal edge only when the opposite incident face is not `source_faces_compatible()` with the local face;
6. rejects a hidden same-component/same-sheet internal cut.

The curved bounded-disk producer uses this predicate for each local boundary edge. No source classifier, hard-feature set, periodic relation, fallback/recovery path, validator, or generic completion behavior was modified.

## Compile-only regression additions

The Phase 10 test source now compiles behavioral coverage for:

- `CurvedBoundedDiskAcceptsNonHardAuthoritativeSourceSheetBoundary` — a real adjacent planar source sheet shares a non-hard internal source edge with the curved disk and is given a distinct authoritative sheet label;
- `CurvedBoundedDiskRejectsHiddenSameSheetBoundaryCut` — the same source topology with compatible same-sheet labels remains invalid as a hidden local cut;
- `CurvedBoundedDiskCrossSheetBoundaryIsInvariantToFaceRowEnumeration` — equivalent disk face-row enumeration must preserve produced structural geometry;
- the prior hard-feature boundary test remains unchanged;
- the exact torus producer-boundary test now also forbids terminal `InvalidBoundedDiskTopology` for this non-hard cross-sheet boundary class.

The witness is structural rather than fixture-recognition logic: the same physical shared source edge distinguishes valid versus invalid local-boundary authority only through the existing component/sheet labels.

**None of these tests executed in this Code + Build turn.**

## Successful compile-only build

Successful workflow run/job:

- **`31247546780 / 93078496378`**;
- event commit `ccb9aa0db15a575f31b802a354ccf8b0aabe111c`;
- Ubuntu 24.04, Release/static, Ninja;
- GMP enabled;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- CLI/GUI/PARDISO/cuDSS/SuiteSparse disabled.

Seven approved targets compiled/linked successfully, **111/111** build actions:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Artifact metadata records `runtimeExecution=false`.

## Immutable artifact authority

Main artifact:

- artifact ID **`9019024467`**;
- name `g4-source-sheet-boundary-code-build`;
- GitHub/downloaded ZIP SHA-256 **`a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`**;
- internal `SHA256SUMS` SHA-256 **`7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`**;
- recursive checksums **48/48**;
- package **49 files**, **27 fixture files**, five executables, two project static libraries.

Dedicated log artifact:

- artifact ID **`9019024673`**;
- name `g4-source-sheet-boundary-code-build-logs`;
- ZIP SHA-256 **`243943268324a24e5fd04a42fed706b274a8525f5c2f157bf246b5028e42f03c`**.

The package contains binaries/libraries, immutable fixture closure, source archive/patch, compile database, toolchain/configure/build/activity logs, source/build/command-boundary metadata, submodule authority, and recursive checksums.

## Transport failures retained as infrastructure evidence

Two earlier attempts in this same Code + Build turn failed **before source modification or compilation**:

1. run/job `31247308268 / 93077919524`: a single manually transferred compressed/base64 payload failed gzip CRC/length validation; log artifact `9018885210`, SHA-256 `12489b675eac2be059360050f233f41c80bc11bd6790b89af4d9ba7427427cb0`;
2. run/job `31247402955 / 93078151447`: four manually transferred encoded parts passed their committed Git-blob checks but concatenated to a different encoded SHA-256 than the local intended payload; log artifact `9018911645`, SHA-256 `5eb478457ab80cd91dfcb252303761a0dafab1cfaec86a2b173c7cdc7725a1f0`.

Neither attempt applied the production patch or executed project runtime. The successful attempt replaced encoded transport with six plain raw unified-patch chunks whose exact Git blobs and SHA-256 values were independently verified before concatenation. Future connector source transfer should prefer verifiable raw text chunks over manually copied compressed/base64 payloads.

## Repository hygiene

After successful artifact/source/log authority was verified:

- bounded workflow removal commit: `398c3ba1b614f78d52807abc3a4c023c47df70a1`;
- trigger removal commit: `aa384b43243f4fcbd0b4e91204ea7e7f6ac3376c`;
- all payload transport files were removed by cleanup commit `3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`.

Final hygiene must be rechecked before the turn-closeout comment.

## Runtime authority remains unchanged until validation

This turn proves source synchronization, compilation and artifact integrity only. Do not claim that the three new boundary-authority tests pass, exact torus advances beyond `InvalidBoundedDiskTopology`, phase-front materialization succeeds, prescribed sphere improves, or G4 closes until artifact `9019024467` executes artifact-only.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact **`9019024467`**.

Run the new boundary-authority semantics first, then retain the prior curved-disk, sheet-coverage, G4-relation, G0-G3 and direct deterministic authority. Exact torus must then advance beyond the non-hard source-sheet-boundary `InvalidBoundedDiskTopology` blocker or expose the next truthful deeper producer/materialization invariant. No build or source/test/validator edit is permitted in that validation turn.
