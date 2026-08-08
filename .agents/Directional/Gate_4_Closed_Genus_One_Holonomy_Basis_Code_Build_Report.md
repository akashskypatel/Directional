# Gate 4 Closed-Genus-One Holonomy Basis — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The first G4 closed-genus periodic-authority implementation slice is **compile-valid and packaged**. It is **not runtime-validated** in this turn.

The previous result-level scalar `SurfacePeriodicHolonomy` authority was replaced by a canonical relation collection. The collection is now consumed by structural hashing, diagnostics, benchmark reporting, and periodic materialization. Equivalent/reversed relation descriptions canonicalize, incompatible authority fails closed, and unresolved distinct same-sheet basis authority fails closed instead of selecting by discovery order.

The exact torus material-progress condition remains a **runtime question for the next artifact-only Test + Benchmark turn**. No claim is made here that torus production, G4, or the prescribed-sphere singularity slice passes.

## Exact source authority

Primary implementation commit:

- `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba` — `feat(surface-cells): retain periodic holonomy relations`

Surgical compile-fix source commit:

- `6e754bdd64482582d39e71184805fbb053c99f86` — `fix(surface-cells): hash periodic topology signatures`

Payload cleanup commit used by the successful build:

- `8304ba30b0f85bc69deebbf55922f05846d2d5b2` — `chore(agent): remove G4 compile-fix payload`

The compile fix adds only the required `std::vector<std::uint64_t>` structural-hash overload after the first compile attempt exposed the type mismatch. It does not alter the G4 relation semantics.

Final packaged source blobs:

| File | Blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `51f80393ecd60e32a9cddc1d60ff0d3a7e6de386` |
| `include/directional/geometry/SurfaceCellTracing.h` | `00d849c21a5af9b871b4ad56bf31c4c74bd705b5` |
| `src/bench/DirectionalBenchmark.cpp` | `87e152f25bc2028c6f5293667712c61f21bc6a8f` |
| `src/geometry/SurfaceCellTracing.cpp` | `cf1d17d5966b3d6904c823046c7dbded017e35ad` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `99976a4481bfa9daaf197e15a3b53b70336e8218` |

## Implementation completed

### First-class periodic relation collection

`SurfacePhaseFrontResult` now owns `std::vector<SurfacePeriodicHolonomy> periodicHolonomies` rather than a competing scalar mutable authority.

Each relation carries:

- source component and local sheet;
- `Z4` quarter-turn transport;
- integral lattice translation;
- ordered source route and cut route;
- canonical source-topology signatures for those routes.

The old relation-local `enabled` flag was removed; collection membership is the authority.

### Canonicalization and typed fail-closed behavior

The tracing layer now:

- canonicalizes source-route topology under cyclic orientation reversal;
- canonicalizes cut-route topology under path reversal;
- canonicalizes inverse periodic action without source-ID/discovery-order ownership;
- deduplicates exact canonical equivalents;
- retains compatible relations on distinct authoritative source component/sheet identities;
- rejects conflicting action on the same authoritative route/cut as `IncompatiblePeriodicRelation`;
- rejects unresolved distinct same-sheet basis authority as `AmbiguousPeriodicRelationBasis` rather than choosing one arbitrarily.

The current producer constructs at most one local annulus relation per authoritative `SheetWork`; therefore this first G4 slice does not invent a generic two-generator same-sheet torus basis. If that becomes naturally required by runtime source topology, a later bounded basis solver must derive it explicitly rather than use subset search or ordering.

### Downstream consumption

The relation collection is live in:

- phase-front structural hashing using canonical topology signatures;
- machine-readable diagnostics (`SurfaceCellPeriodicHolonomyDiagnostics`);
- benchmark JSON relation cardinality;
- diagnostics copy/merge paths;
- periodic materialization lookup by source component/sheet;
- existing single-annulus quotient behavior.

Legacy scalar diagnostic fields are retained only as a derived view of the first canonical relation for compatibility; they are not independent mutable production authority.

### Compile-only semantic regressions added

`SurfaceCellsPhase10Tests.cpp` now compiles coverage for:

- reverse-description canonicalization without duplicate generator;
- deterministic retention of multiple distinct authoritative sheet relations;
- same-sheet unresolved/dependent basis fail-closed behavior without order selection;
- conflicting periodic transport fail-closed behavior;
- exact committed torus producer-boundary coverage proving the old scalar `InvalidPeriodicTopology` rejection is not the acceptable terminal reason;
- all retained G3 annulus, field-authority, cut pairing, cylinder, and plane contracts migrated to collection authority.

These tests were **compiled only**. They were not executed in this turn.

## Successful compile-only build

Workflow run: `31233594490`  
Job: `93042009574`  
Event commit: `7e9a721e98b6433ea2c10b3c58b2b1d6c603b535`

Configuration:

- Ubuntu 24.04;
- CMake 3.31.6;
- GCC 13.3.0;
- Ninja 1.13.2;
- Release;
- static libraries;
- GMP enabled;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- CLI/GUI disabled;
- no PARDISO/cuDSS/SuiteSparse.

Approved targets compiled and linked **111/111**:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

`compile_only_gate=passed`.

No generated Directional binary, test, benchmark, `ctest`, CLI, GUI, help/list, or discovery command was executed. Artifact metadata records `runtimeExecution=false`.

## Immutable artifacts

Main compile artifact:

- artifact ID: **`9014730437`**
- name: `g4-holonomy-basis-code-build`
- workflow ZIP digest: `sha256:14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`
- uploaded size: `16,104,440` bytes
- internal `SHA256SUMS` digest: `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`
- recursive packaged checksums independently verified after download: **46/46**
- package file count: **47**
- fixture count: **27**

Packaged runtime files:

- `directional_benchmarks`
- `directional_compiled_api_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `libdirectional_core.a`
- `libdirectional_pipeline.a`

The artifact also includes exact fixture data, build/activity/toolchain logs, `compile_commands.json`, the source archive, the combined G4 patch, source/blob authority metadata, and checksum manifests.

Detailed log artifact:

- artifact ID: **`9014730651`**
- name: `g4-holonomy-basis-code-build-logs`
- workflow ZIP digest: `sha256:cadc92c03d18d905ca362943a4a28ecb2a4b56450f3e8659064e6d68f2ff24de`

## Failed bounded attempts retained as evidence

The turn had three bounded failures before the successful compile artifact. None executed project runtime binaries.

1. Run `31233177777`: setup-only transform guard defect; no production source commit. Log artifact `9014513436`.
2. Run `31233235342`: setup-only incomplete scalar-to-collection test-reference migration; no production source commit. Log artifact `9014530231`.
3. Run `31233330498`: source implementation committed successfully, but compile stopped at 83/111 because `RemeshPipeline.cpp` lacked a `hash_vector` overload for `std::vector<std::uint64_t>`. Log artifact `9014631674`.

The fourth bounded run fixed only that compile defect and completed 111/111.

## Repository hygiene

After artifact/source/log authority was verified:

- bounded workflow `.github/workflows/g4-holonomy-basis-code-build.yml` was removed;
- bounded trigger `.github/agent-triggers/g4-holonomy-basis-code-build` was removed;
- transform/compile-fix payloads were removed;
- `.github/workflows` again contains only the durable `agent-source-snapshot.yml` workflow.

## Runtime authority remains unchanged

Until artifact `9014730437` is executed artifact-only, the formal runtime authority remains G3 artifact `9013161456` / runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

Do not claim:

- G4 passed;
- torus direct production succeeds;
- relation count/translation values for the torus;
- prescribed-sphere completion is fixed;
- aggregate suite improvements.

Those are next-turn runtime questions.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact **`9014730437`**.

The first runtime decision is whether the exact committed torus has stopped failing solely because a second compatible periodic relation exists, while all G0-G3 focused contracts and direct plane/seam/close-sheets/cylinder authority remain unchanged. Direct strict-valid torus production is preferred; a deeper truthful failure is material progress only when the collection is demonstrably retained and consumed.
