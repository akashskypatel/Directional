# Gate 4 Closed-Genus-One Sheet Coverage — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The G4 complete-source-sheet aggregation slice is **compile-valid, packaged, and subsequently runtime-validated**. This report records only the Code + Build authority; runtime conclusions are in `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`.

The implementation removed the prior partial-authority escape hatch in `build_uniform_phase_front()`: every deterministic authoritative source sheet is evaluated before whole-surface authority is exposed. Supported bounded/periodic sheets may compose; produced-then-unsupported coverage fails closed as typed `UnsupportedSourceSheetTopology`; aggregate ownership/coverage mismatch fails as `IncompleteSourceSheetCoverage`.

## Exact source authority

Primary implementation:

- `856554ce648e5df09ac50f5c94e3e8f098181524` — `fix(surface-cells): fail closed on incomplete sheet coverage`

Surgical test compile correction:

- `a647215b4993338b054f04d4c8e54e7ef5370001` — `fix(tests): parenthesize sheet map keys`

Payload cleanup used by the successful build:

- `e46a6d99a45f22f31672c8e5a3367735427d827e` — `chore(agent): remove G4 sheet-coverage compile-fix payload`

Implementation payload Git blob `5980a71a0d38068fb2bb2dc86d16b4448e95b561`, runtime-recorded SHA-256 `00aadd3db37cb6db4e61309a56ae8cd7d68559e65938056994f908bb600df384`.

Compile-fix payload Git blob `fa0e9bc4ad751cfab5448bfae65c225137fd4a19`, runtime-recorded SHA-256 `8fe261a08be1106991f7f6640e77da26ca759defd5f342480d08900bfad1b50f`.

Final packaged source blobs:

| File | Blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `6ebe8f3324be580fc4838b97e5fb449572709236` |
| `src/geometry/SurfaceCellTracing.cpp` | `6b32b48141c16e2d51f1932462566083a7bc3355` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `c038567898f0da7efd6519392c37cbace02b8c1c` |

## Implementation contract

`build_uniform_phase_front()` now retains one local result per canonical `(source component, source sheet)` and evaluates every sheet before final aggregation.

Per sheet it preserves the existing dispatch:

1. bounded uniform phase-front;
2. periodic-annulus phase-front when bounded is `NotApplicable`;
3. immediate propagation of typed local rejection.

If no sheet is applicable, whole-surface `NotApplicable` is preserved. If one or more sheets produced but a later sheet is unsupported, the aggregate is `Rejected / UnsupportedSourceSheetTopology`; partial cells/edges/events are not published as whole-surface authority.

When all local sheets produce, aggregation verifies exact source component/sheet ownership for cells and front edges, nonempty exact-once coverage for every authoritative sheet, and covered-sheet cardinality equal to source-sheet cardinality. Violations reject as `IncompleteSourceSheetCoverage`.

Canonical periodic-relation insertion remains active and preserves prior same-sheet ambiguity/conflict fail-closed semantics.

## Compile-only regressions added

The build includes semantic coverage for:

- mixed bounded + periodic authoritative-sheet composition;
- produced-then-unsupported typed fail-closed behavior under face-row reversal;
- the exact torus producer boundary no longer accepting prior partial `NotApplicable` behavior;
- all prior G4 periodic-relation tests and G0-G3 focused tests unchanged.

No test was executed during this Code + Build turn.

## Successful compile-only build

Workflow run/job: `31237248211 / 93051938159`  
Event commit: `6ee323c1dcc54181c7997cd33bba7585d51e3493`

Configuration:

- Ubuntu 24.04;
- CMake 3.31.6;
- GCC 13.3.0;
- Ninja 1.13.2;
- Release/static;
- GMP enabled;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- CLI/GUI disabled;
- PARDISO/cuDSS/SuiteSparse disabled.

Seven approved targets compiled and linked **111/111**:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

`compile_only_gate=passed`. No generated Directional executable/test/benchmark, `ctest` discovery, CLI, GUI, help/list, or custom input executed. Artifact metadata records `runtimeExecution=false`.

## Immutable artifacts

Main artifact:

- ID **`9015931928`**;
- name `g4-sheet-coverage-code-build`;
- workflow/downloaded ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- size `16,125,763` bytes;
- internal `SHA256SUMS` SHA-256 `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`;
- recursive checksums **47/47**;
- **48** package files / **27** fixture files;
- five executables / two project static libraries.

Log artifact:

- ID `9015932044`;
- name `g4-sheet-coverage-code-build-logs`;
- ZIP SHA-256 `b05c1ef0bf7c5a52ff5dc8158d02c00d11d9cb7637c0a93b0c385a202ad46c50`.

## Bounded failed attempts

No failed attempt executed generated project runtime binaries.

- Initial workflow definition failed before job execution because of an invalid workflow-scope runner-context path expression.
- A setup-only attempt exposed that connector-committed text SHA-256 cannot be predicted safely from a locally constructed text representation; exact Git blob became the commit authority while runtime SHA-256 remained separately recorded.
- Run `31236913982` committed the production implementation and compiled production source successfully but stopped compiling the new test because GoogleTest parsed commas in `std::pair<int,int>{...}` as macro separators. Log artifact `9015800914`, SHA-256 `71b2d1edf2c418abbea2f1de468958f238f8f20d13d73e05ef8c30a62e96155d`.
- `a647215...` only parenthesized the two map lookup expressions; the next bounded build completed 111/111.

## Repository hygiene

After artifact/source/log authority was verified, the bounded workflow, trigger, and both payloads were removed. `.github/workflows` returned to the durable `agent-source-snapshot.yml` only; temporary trigger/payload directories are absent.

## Runtime transition

Artifact `9015931928` has now been executed artifact-only. The authoritative runtime report is:

`.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`

It proves the new sheet-coverage semantics while exposing the next G4 producer class: non-planar χ=1 single-boundary **curved bounded disk sheets**. The authoritative next turn is defined by:

`.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Plan.md`
