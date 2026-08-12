# M1 Single-Authority Cutover — Code + Build Report

**Status:** historical compile/package evidence; independently rejected as M1-complete and not eligible for runtime acceptance  
**Turn:** M1 Single-Authority Cutover — Code + Build  
**Repository:** `akashskypatel/Directional`  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Entering accepted implementation:** `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Final implementation:** `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e`

## 2026-08-12 status amendment

This report remains an immutable factual record of source `5b1c9b...`, compile `121/121`, artifact `9105462679`, and the recorded command boundary. Its original claims that the complete cutover closed and that artifact-only validation was next were rejected by the independent source review recorded in the live Code + Build plan.

The later R-A checkpoint `bebac907de814b07a55a770add4c897ab6d22ffd` compiled `118/118` in run/job `31550744314 / 93972723960`, but independent review also found two blocking raw-payload read-back paths. Current authority is `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md` plus the amended Code + Build plan. Do not execute or relabel artifact `9105462679` or R-A artifact `9124167871` as M1 acceptance candidates.

## Result

The final M1 authority cutover is compile-valid and packaged for separate immutable artifact-only validation. This turn executed configuration, compilation/linking, source-only audits, and packaging only. It executed no generated Directional binary, GoogleTest discovery/listing, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

The implementation completes the selected one-turn replacement boundary without restoring displaced numeric authority. Runtime and semantic acceptance are deliberately unclaimed until the following artifact-only Test + Benchmark turn.

## Contract changes

- Strong semantic IDs are constructed through checked ingress; numeric projections remain representation leaves.
- The phase-front topology-region product is typed through producer, verification, materialization, and occurrence consumers.
- Isolation-seam certificates, chart/source-support identity, canonical routes, and periodic transport use one typed contract each.
- Producer publication is a closed `ProducerOutcome<SurfacePhaseFrontProduct>`; rejected/not-applicable states expose no consumable partial product.
- Hard-rail ownership is `HardRailId` across tracing, FlowRep, arrangement, completion, optimization, and affected tests.
- Materialized vertex lineage owns checked `OccurrenceId` and `QuotientClassId` rather than raw semantic indices.
- Transitional adapters, duplicated chart structs, route mirrors, and raw semantic mirror fields covered by the cutover audit are absent.

## Authoritative build/package evidence

| Evidence | Authority |
|---|---|
| Final source | `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e` |
| Immediate source parent | `1cb115500c629610d5ad7b2d73c58029beb94a7c` |
| Final package run/job | `31501276992 / 93811595735` |
| Result artifact | `9105462679` — `m1-single-authority-cutover-code-build-result-31501276992` — `sha256:f73f6e02ff7cb3254dce46694af460d3703c7869985bcb69648eb528db9c6ad2` |
| Log artifact | `9105463175` — `m1-single-authority-cutover-code-build-log-31501276992` — `sha256:b7da5a801aa5a6c0d6a8cd1919c6ba98e1bf0aca9f837e8fff9243ffaf9b2343` |
| Retention | `7 days (through 2026-08-18 UTC)` |
| Recursive manifest | `57/57`, SHA-256 `ebd5f1587feec0120260eacd127f45fcf66784f5effaf1a60703e7471f9454b4` |
| Fixture files | `27` |
| Compile | **121/121** approved compile/link steps; **8:36.47**, peak RSS **2,014,140 KiB** |

The package contains the seven established test/benchmark executables, `libdirectional_core.a`, `libdirectional_pipeline.a`, committed benchmark fixtures, exact source archive, M1l→cutover source patch, changed-path/blob manifest, compile database, configure/build/toolchain/submodule logs, source-only cutover audit, test-group source manifest, command-boundary metadata, and recursive checksums.

## Static cutover audit

The authoritative pre-build source audit returned zero matches for every displaced symbol required by the plan:

`LegacyAuthorityAdapters`, `to_legacy_index`, `legacy_phase_front_`, `transitionSourceEdge`, `transitionSourceEdges`, `transitionSourceTopology`, `sourceRouteEdges`, `sourceRouteTopology`, `sourceTopologyRegionByFace`, `struct SourceChartId`, and `struct SurfaceCellSourceChart`.

Legacy domain-error terminology (`NegativeLegacyValue`, `OutOfRangeLegacyValue`, `legacyValue`) was absent. The affected authority headers also contained no typed+numeric duplicate fields for rail, periodic relation, filled cell, topology region, or raw boundary/feature rail vectors under the audit patterns.

## Compile-remediation evidence

Compile-only retries remained inside the Code + Build boundary and did not execute generated runtime:

- `31497014917 / 93797170471`: typed rail migration exposed a heterogeneous integer/`int64_t` initializer list in `SurfaceCellFeasibilityRepair.cpp`; fixed with explicit `std::array<std::int64_t, ...>` authority-neutral serialization storage.
- `31497611526 / 93799175926`: orchestration-only failure; the trigger parent still referenced the prior staged patch. No source semantic failure was inferred.
- `31497817179 / 93799852718`: compile reached `47/121`; `SurfaceMeshOptimizer.h` retained a stale `int` declaration for a definition returning `SurfaceFeatureSequenceKey`.
- `31498586644 / 93802425794`: orchestration-only failure from a corrupted staged payload; corrected before retry.
- `31498810384 / 93803158105`: compile reached `103/121`; three Milestone-E fixtures used the new test `HardRailId` helper without its namespace qualification.
- Initial final-package trigger `31501039998` had no runnable job because `${{ runner.temp }}` was used in job-level `env`; the workflow was corrected to shell-time `$RUNNER_TEMP` before the authoritative package run. No source or generated runtime executed in that failed orchestration attempt.

Each source correction migrated the affected consumer/test to the typed contract; no removed adapter, raw authority field, fallback, fixture workaround, threshold change, or validator weakening was restored.

## Execution boundary

Authoritative package metadata records all of the following as false:

- `runtimeExecution`
- `gtestListExecution`
- `testExecution`
- `benchmarkExecution`
- `ctestExecution`
- `cliExecution`
- `fuzzerExecution`
- `customInputExecution`

No test total is claimed in this report. The next artifact-only turn must discover the packaged inventory independently.

## Historical next-turn instruction — superseded

Run **M1 Single-Authority Cutover — Artifact-Only Test + Benchmark** using:

`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`.

The instruction below was the next step at report creation and is retained only as history. It must not be executed.

Consume exact result artifact `9105462679` from source `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e` without rebuilding or modifying the package. If every required semantic gate and the static cutover audit pass with no unclassified product regression, M1 closes and the primary queue returns directly to G4. No further M1 letter slice is selected.
