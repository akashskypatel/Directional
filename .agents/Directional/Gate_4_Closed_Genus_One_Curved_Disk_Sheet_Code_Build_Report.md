# Gate 4 Closed-Genus-One Curved Disk Sheet — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The generalized curved bounded disk-sheet producer slice is **compile-valid and packaged**. It is **not runtime-validated in this turn**.

The implementation adds an intrinsic bounded-chart producer for connected χ=1 source sheets with one genuine source/hard-feature boundary. It preserves the existing planar bounded producer, periodic-annulus producer, exact source-sheet aggregation, canonical periodic-relation authority, and hard-feature boundary ownership. No generated Directional binary/test/benchmark was executed.

Exact artifact **`9016834575`** is the only candidate for the following artifact-only Test + Benchmark turn.

## Entering runtime authority

Runtime-proven authority remains artifact `9015931928` / source `a647215b4993338b054f04d4c8e54e7ef5370001` until the new artifact executes.

That authority proves sheet-coverage semantics **3/3**, G4 periodic relations **5/5**, retained G0-G3 focused contracts **17/17**, exact deterministic plane/seam/close-sheets/cylinder baselines, and torus `Rejected / UnsupportedSourceSheetTopology` with three retained periodic relations and no fallback/recovery.

The source-derived missing class entering this turn was the non-planar χ=1 single-boundary disk produced by the torus's authoritative hard-feature/source-sheet partition. Face IDs, sheet counts, relation counts, and observed loop lengths remain diagnostic evidence only.

## Exact source authority

Primary implementation commit:

- **`90046be649a0fd051e6c44eceec07198dc542c29`** — `feat(surface-cells): add intrinsic curved disk phase front`

Payload cleanup commit:

- **`508211936b790dfb40cdbece7900bb0522368b76`** — `chore(agent): remove G4 curved-disk payload`

Patch transfer authority:

- committed payload Git blob `2436d0fe3c1f8bad2e8614f118af70ecda2ac12d`;
- decoded unified-patch SHA-256 `ae0b6efe3db697b22c36e2a348cb7be6a058f9e29bde5ac36231db8439f3eb91`;
- `git apply --check` and `git diff --check` passed before commit.

Final packaged source blobs:

| File | Git blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `998d8bc46faf6d590cb1674c4f5b2e290f94c48e` |
| `src/geometry/SurfaceCellTracing.cpp` | `3363e20c33a6850c192249877e7cb4488fc36597` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `fe7ce43466cc3bc852b36c0ea8b8de6aac0c5b64` |

## Production implementation

### Structural applicability and typed failures

`SurfacePhaseFrontFailureReason` now includes `InvalidBoundedDiskTopology`, `InvalidBoundedDiskTransport`, `InvalidBoundedDiskBoundaryPhase`, `InvalidBoundedDiskChart`, and `InvalidBoundedDiskFrontPairing`.

The new producer applies from source topology rather than fixture identity: a connected χ=1 manifold source sheet with one genuine local boundary. A local boundary edge must be a true source-mesh boundary or an authoritative hard-feature rail when the sheet is created by feature partitioning.

### Reciprocal field authority

The producer propagates a global 4-RoSy gauge over the simply connected sheet using the existing reciprocal source-edge transition machinery. Both lattice families are checked across interior source edges. Inconsistent reciprocal or cycle transport fails closed as `InvalidBoundedDiskTransport` rather than choosing a branch by source ID, discovery order, majority, or arbitrary subset.

### Intrinsic bounded chart

The single source boundary is ordered from source topology and winding. Transported field alignment partitions it into the required cyclic U+/V+/U-/V- side families. Invalid boundary phase/index structure fails as `InvalidBoundedDiskBoundaryPhase`.

Boundary arc length supplies intrinsic side coordinates. Interior chart vertices are solved by a uniform-weight harmonic/Tutte parameterization using Eigen sparse Cholesky. Chart triangle orientation/injectivity is checked before production; invalid parameterizations fail as `InvalidBoundedDiskChart`.

This is not a relaxed global plane fit. Strongly non-planar geometry remains supported through the intrinsic chart while emitted geometry stays on exact source triangles.

### Front/cell provenance

Regular target-size crossings are sampled in the intrinsic chart and mapped piecewise linearly to source triangles. Segment family/sign authority comes from the propagated reciprocal field gauge. Cells retain exact source component/sheet ownership and validate closed source paths and orientation.

Internal front edges are paired structurally. Exterior front termination is accepted only on the authoritative local source/hard-feature boundary; invalid pairing/termination fails as `InvalidBoundedDiskFrontPairing`.

No periodic relation is invented for a disk. Existing annulus relations remain the only periodic authority.

### Sheet-local composition

Sheet-local dispatch now tries the existing planar bounded producer, then the existing periodic-annulus producer, then the curved bounded-disk producer when the earlier producers are `NotApplicable`.

Existing exact-once aggregate source-sheet coverage remains authoritative. The change does not mark partial coverage `Produced`, demote hard features, reinterpret a disk as an annulus, weld seams geometrically, or modify generic arrangement/completion.

## Compile-only semantic regressions

`tests/SurfaceCellsPhase10Tests.cpp` now compiles focused coverage for:

- `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`;
- `CurvedBoundedDiskIsInvariantToFaceRowEnumeration`;
- `CurvedBoundedDiskPreservesAuthoritativeHardBoundary`;
- `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`;
- strengthened `ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`, which also forbids `UnsupportedSourceSheetTopology` as the terminal curved-disk result.

The prior sheet-coverage, periodic-relation, and G0-G3 contracts remain compiled. **No test was executed in this turn.**

## Successful compile-only build

Workflow run/job `31240168780 / 93059691196`, event commit `add5709d0a9bd8a22d10e47a6c4b72d7af51ce48`.

Configuration: Ubuntu 24.04, Release/static, Ninja, GMP enabled, `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`, tests/benchmarks compiled, CLI/GUI/PARDISO/cuDSS/SuiteSparse disabled.

Seven approved targets compiled/linked successfully, **111/111** build actions: `directional_core`, `directional_pipeline`, `directional_compiled_api_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, and `directional_benchmarks`.

No generated Directional executable, test, benchmark, `ctest`/discovery command, CLI/GUI command, help/list command, or custom input executed. Artifact metadata records `runtimeExecution=false`.

## Immutable artifact authority

Main compile artifact:

- artifact ID **`9016834575`**;
- name `g4-curved-disk-code-build`;
- ZIP SHA-256 **`6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`**;
- internal `SHA256SUMS` SHA-256 **`e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`**;
- recursive packaged checksum verification **48/48**;
- total package files **49** including the checksum manifest;
- fixture files **27**;
- five executables;
- two project static libraries.

The artifact contains the exact binaries/libraries, source patch/no-dependency source archive, compile database, fixture tree, source/build/command-boundary metadata, toolchain/configure/build logs, submodule authority, and recursive checksums.

Detailed log artifact:

- artifact ID **`9016834752`**;
- name `g4-curved-disk-code-build-logs`;
- ZIP SHA-256 **`6e0ed0906bc9f935ac80b6d8fd40f0654f203020a7b7c6cde6d9a4e49b067db1`**.

## Repository hygiene

After exact source/artifact/log authority was established, bounded workflow `.github/workflows/g4-curved-disk-code-build.yml` was removed first (`8d7bfa669ceedbb4d6f1ef99071feabb3a69c338`), then trigger `.github/agent-triggers/g4-curved-disk-code-build` was removed (`18a3010cdac0b29ec474ded0c2c9356320786cce`); the patch payload had already been removed by `508211...`.

Final verification showed `.github/workflows` contains only durable `agent-source-snapshot.yml`, and `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent.

The completed executable Code + Build plan was removed. A minimal compatibility pointer remains at its historical path solely because the current runtime-authority report records that path as its then-next step; the pointer explicitly redirects to the current artifact-only plan and is not executable authority.

## Runtime authority remains unchanged

This turn proves compilation and packaging only. Until artifact `9016834575` executes artifact-only, current runtime authority remains artifact `9015931928` and its torus `UnsupportedSourceSheetTopology` result.

Do not claim that the curved-disk focused tests pass, either exact torus disk is successfully charted, torus reaches `Produced`, torus materialization/output succeeds, prescribed sphere improves, or G4 closes.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact **`9016834575`**.

First prove the new curved-disk semantics, retain sheet-coverage 3/3, G4 relation 5/5, G0-G3 17/17, and exact direct plane/seam/close-sheets/cylinder baselines. Exact torus must then no longer terminate as `UnsupportedSourceSheetTopology`. Direct strict-valid torus output is preferred; a deeper deterministic typed transport/boundary-phase/chart/front-pairing/materialization invariant is acceptable material progress if curved-disk applicability is live and no generic/fallback path substitutes for authoritative failure.
