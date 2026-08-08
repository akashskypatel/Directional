# Gate 4 Closed-Genus-One Sheet Coverage — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The G4 torus source-sheet coverage slice is **compile-valid and packaged**. It is **not runtime-validated in this turn**.

The implementation removes the previous partial-authority escape hatch in `build_uniform_phase_front()`: deterministic sheet-local producers are evaluated across the complete authoritative sheet set before aggregation is exposed. Supported bounded/periodic sheets may compose into one aggregate; when at least one sheet is authoritative but a later sheet remains structurally unsupported, the whole-surface producer now fails closed with typed `UnsupportedSourceSheetTopology` instead of returning a partially accumulated `NotApplicable` result that sends the pipeline into zero-cell generic arrangement/completion.

This is intentionally not a claim that the exact torus now produces quads. Artifact-only runtime validation of exact artifact **`9015931928`** is the next turn.

## Exact source authority

Primary implementation:

- `856554ce648e5df09ac50f5c94e3e8f098181524` — `fix(surface-cells): fail closed on incomplete sheet coverage`

Surgical compile-only test correction:

- `a647215b4993338b054f04d4c8e54e7ef5370001` — `fix(tests): parenthesize sheet map keys`

Payload cleanup used by the successful build:

- `e46a6d99a45f22f31672c8e5a3367735427d827e` — `chore(agent): remove G4 sheet-coverage compile-fix payload`

Implementation payload authority:

- Git blob `5980a71a0d38068fb2bb2dc86d16b4448e95b561`;
- SHA-256 `00aadd3db37cb6db4e61309a56ae8cd7d68559e65938056994f908bb600df384`.

Compile-fix payload authority:

- Git blob `fa0e9bc4ad751cfab5448bfae65c225137fd4a19`;
- SHA-256 `8fe261a08be1106991f7f6640e77da26ca759defd5f342480d08900bfad1b50f`.

Final packaged source blobs:

| File | Blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `6ebe8f3324be580fc4838b97e5fb449572709236` |
| `src/geometry/SurfaceCellTracing.cpp` | `6b32b48141c16e2d51f1932462566083a7bc3355` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `c038567898f0da7efd6519392c37cbace02b8c1c` |

## Implementation completed

### Deterministic complete-sheet aggregation boundary

`build_uniform_phase_front()` now keeps a deterministic `SheetBuild` result for every canonical `(source component, source sheet)` work item rather than appending authority and returning immediately on the first later `NotApplicable` sheet.

Each sheet still uses the existing producer order:

1. bounded uniform phase-front;
2. if `NotApplicable`, periodic-annulus phase-front;
3. typed local rejection propagates unchanged.

No hard-feature/source-sheet barriers are removed or reclassified.

### Partial authority now fails closed

If **no** sheet producer is applicable, the overall producer remains `NotApplicable`, preserving the generic applicability contract.

If at least one sheet has produced valid cells and a later sheet remains unsupported, the aggregate becomes `Rejected` with typed `UnsupportedSourceSheetTopology` and a canonical failing source face. It does not expose partially accumulated cells/edges/events as whole-surface `Produced` authority.

This is the intended bounded result when the current producer family cannot cover one topology class. It prevents the previous torus path from silently discarding the whole-surface authority decision and reaching the downstream zero-cell generic arrangement/`SideSubdivisionRepair` symptom.

### Complete aggregate invariants

When all sheet-local producers succeed, aggregation now verifies:

- every emitted cell belongs to the expected `(component, sheet)`;
- every emitted front edge belongs to the expected `(component, sheet)`;
- every authoritative sheet contributes nonempty cell coverage exactly once;
- the final covered-sheet cardinality equals the authoritative sheet-work cardinality.

Violations reject with typed `IncompleteSourceSheetCoverage`.

Canonical periodic-relation insertion remains active during the all-sheet evaluation pass, preserving the previous G4 multi-relation authority and its fail-closed ambiguous/incompatible behavior.

### Compile-only semantic regressions

New tests compile coverage for:

- `PhaseFrontComposesBoundedAndPeriodicAuthoritativeSheets` — a committed plane and translated committed cylinder as distinct authoritative sheets must compose under one produced aggregate while retaining cylinder periodic authority;
- `PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority` — a produced bounded sheet followed by an unsupported tetrahedral sheet must reject as `UnsupportedSourceSheetTopology`, expose no partial cells/edges/events, and retain the failing source-sheet identity under face-order reversal;
- strengthened exact torus producer boundary — exact torus must not remain the prior partial `NotApplicable`; if runtime rejects at this slice, the expected bounded reason is the new typed unsupported-sheet contract rather than the old scalar periodic rejection.

The prior G4 relation tests and G0-G3 tests remain compiled unchanged. **No test was executed in this turn.**

## Successful compile-only build

Workflow run/job:

- run `31237248211`;
- job `93051938159`;
- event commit `6ee323c1dcc54181c7997cd33bba7585d51e3493`.

Configuration:

- Ubuntu 24.04;
- CMake 3.31.6;
- GCC 13.3.0;
- Ninja 1.13.2;
- Release/static;
- GMP enabled;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- tests and benchmarks compiled;
- CLI/GUI disabled;
- PARDISO/cuDSS/SuiteSparse disabled.

The seven approved targets compiled/linked **111/111**:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

`compile_only_gate=passed`.

No generated Directional executable/test/benchmark, `ctest` discovery, CLI, GUI, help/list, or custom input was executed. Artifact metadata records `runtimeExecution=false`.

## Immutable artifact authority

Main artifact:

- ID **`9015931928`**;
- name `g4-sheet-coverage-code-build`;
- workflow/downloaded ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- uploaded size `16,125,763` bytes;
- internal `SHA256SUMS` SHA-256 `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`;
- recursive packaged checksum verification **47/47**;
- total package files **48**;
- fixture files **27**;
- five executables;
- two project static libraries.

Packaged binaries/libraries:

- `directional_benchmarks`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `libdirectional_core.a`;
- `libdirectional_pipeline.a`.

The package also contains the exact combined patch, source archive without external dependencies, `compile_commands.json`, fixture tree, source/build authority metadata, submodule authority, build/activity/toolchain logs, and recursive checksum manifest.

Log artifact:

- ID `9015932044`;
- name `g4-sheet-coverage-code-build-logs`;
- ZIP SHA-256 `b05c1ef0bf7c5a52ff5dc8158d02c00d11d9cb7637c0a93b0c385a202ad46c50`.

## Bounded failed attempts

Several bounded control-plane/build attempts preceded the successful artifact. None executed a generated project binary.

- The first workflow definition was rejected before job execution because a runner-context path expression was invalid at workflow scope.
- A subsequent setup-only attempt failed because a locally predicted SHA-256 did not match the connector-committed text representation; authority was corrected to the exact committed Git blob while still recording the runtime SHA-256.
- Run `31236913982` successfully committed the production implementation and compiled `SurfaceCellTracing.cpp`; it stopped only while compiling the new producer test because GoogleTest interpreted commas inside `std::pair<int,int>{...}` as macro argument separators. Log artifact `9015800914`, SHA-256 `71b2d1edf2c418abbea2f1de468958f238f8f20d13d73e05ef8c30a62e96155d`.
- Commit `a647215...` only parenthesizes those two lookup expressions. It changes no production semantics. The next bounded run completed 111/111.

## Repository hygiene

After exact artifact/source/build/log authority was verified:

- bounded `.github/workflows/g4-sheet-coverage-code-build.yml` was removed;
- bounded `.github/agent-triggers/g4-sheet-coverage-code-build` was removed after the workflow;
- both temporary turn payloads were removed;
- `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent;
- `.github/workflows` contains only durable `agent-source-snapshot.yml`.

## Runtime authority remains the prior artifact

Until artifact `9015931928` is executed artifact-only, current runtime-proven G4 authority remains artifact `9014730437` / final source `6e754bdd64482582d39e71184805fbb053c99f86`:

- G4 periodic relations 5/5;
- retained G0-G3 17/17;
- direct plane/seam/close-sheets/cylinder exact deterministic hashes retained;
- torus retains two periodic relations but still follows partial `NotApplicable -> 670 traces -> 0 arrangement cells -> SideSubdivisionRepair:InvalidInputIncidence`.

Do not claim from this compile-only turn that the new torus path is runtime-proven, that the torus produces output, or that G4 is closed.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact **`9015931928`**.

The next runtime gate must first prove the new sheet-coverage tests, retain all five G4 relation semantics and all 17 G0-G3 contracts, and preserve direct plane/seam/close-sheets/cylinder hashes. Exact torus must then stop following the previous partial `NotApplicable` downstream path.

Preferred result is complete produced/materialized strict-valid torus output. An earlier deterministic typed `UnsupportedSourceSheetTopology`/materialization failure with retained relation authority is acceptable material progress because it makes the unsupported producer topology explicit and prevents the opaque downstream zero-cell completion failure.
