# Gate 4 Closed-Genus-One Curved Disk Sheet — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The generalized curved bounded disk-sheet producer slice compiled and packaged successfully as exact artifact **`9016834575`**. No generated Directional binary/test/benchmark executed during this Code + Build turn.

Artifact `9016834575` has since been runtime-validated artifact-only. Current runtime results are recorded in `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`. This report remains the compile/source authority for that exact artifact.

## Exact source authority

Primary implementation:

- **`90046be649a0fd051e6c44eceec07198dc542c29`** — `feat(surface-cells): add intrinsic curved disk phase front`

Payload cleanup:

- **`508211936b790dfb40cdbece7900bb0522368b76`** — `chore(agent): remove G4 curved-disk payload`

Patch transfer authority:

- payload Git blob `2436d0fe3c1f8bad2e8614f118af70ecda2ac12d`;
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

The implementation adds a structurally dispatched curved bounded-disk producer for connected χ=1 source sheets with one local boundary. It validates reciprocal 4-RoSy transport, derives boundary phase families from transported field alignment, solves an intrinsic harmonic/Tutte chart, maps chart lattice/front geometry back to exact source triangles, preserves source component/sheet ownership, and fails typed as bounded-disk topology/transport/boundary-phase/chart/front-pairing invariants.

Existing planar bounded and periodic-annulus producers remain before the curved-disk producer. No periodic relation is invented for a disk. No hard-feature demotion, annulus coercion, Euclidean seam welding, fallback/recovery, generic completion repair, or validator change was introduced.

Compile-only tests added coverage for curved-disk applicability, face-row invariance, hard-boundary preservation, invalid reciprocal transport, planar+periodic+curved composition, and exact torus producer advancement. These tests were compiled but **not executed during this Code + Build turn**.

## Successful compile-only build

Workflow run/job `31240168780 / 93059691196`, event commit `add5709d0a9bd8a22d10e47a6c4b72d7af51ce48`.

Environment/configuration: Ubuntu 24.04, Release/static, Ninja, GMP enabled, `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`, CLI/GUI/PARDISO/cuDSS/SuiteSparse disabled.

Seven approved targets compiled/linked successfully, **111/111** build actions:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

No generated Directional executable, test, benchmark, `ctest`/discovery command, CLI/GUI command, help/list command, or custom input executed. Artifact metadata records `runtimeExecution=false`.

## Immutable artifact authority

Main artifact:

- ID **`9016834575`**;
- name `g4-curved-disk-code-build`;
- ZIP SHA-256 `6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`;
- internal `SHA256SUMS` SHA-256 `e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`;
- recursive checksums **48/48**;
- 49 package files / 27 fixture files / five executables / two project static libraries.

Log artifact:

- ID `9016834752`;
- SHA-256 `6e0ed0906bc9f935ac80b6d8fd40f0654f203020a7b7c6cde6d9a4e49b067db1`.

## Repository hygiene

After artifact/source authority was established, bounded workflow `.github/workflows/g4-curved-disk-code-build.yml` was removed before trigger `.github/agent-triggers/g4-curved-disk-code-build`; the payload was removed after source authority was committed.

Current expected hygiene remains: `.github/workflows` contains only durable `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent.

## Post-build runtime status

Artifact-only validation now proves curved-disk focused semantics **6/6**, sheet coverage **3/3**, G4 relation semantics **5/5**, retained G0-G3 **17/17**, and unchanged direct G0-G3 hashes. Exact torus advances beyond `UnsupportedSourceSheetTopology` but exposes the next producer defect: a non-hard internal edge can be an authoritative source-sheet boundary, while the curved-disk boundary check currently recognizes only hard-feature internal boundaries.

The authoritative next plan is `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Plan.md`.
