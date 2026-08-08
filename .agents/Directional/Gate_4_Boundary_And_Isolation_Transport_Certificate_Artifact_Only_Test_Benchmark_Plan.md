# Gate 4 Boundary and Isolation-Transport Certificate — Artifact-Only Test + Benchmark Plan

Status: **completed — blocked with material progress**
Turn type: **Test + Benchmark only**
Outcome report: `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`
Successor: `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Immutable input authority

Use exactly:

- build artifact **`9026181778`** (`g4-boundary-isolation-certificate-code-build`);
- log artifact **`9026181889`**;
- workflow run/job **`31272661747 / 93141125742`**;
- event commit `9f0e6de3e4a1f70eb02d2946072305c7b8c9b5ad`;
- implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`;
- cleanup/build `846b23a1175f541d86e880c993784715c995ef20`;
- build ZIP SHA-256 `0682ae9fe6e98eefac8e4ddb2ccc8db8407326d7b872ec6da1d945aa8a59b79d`;
- log ZIP SHA-256 `d53a060c2b3b20205ce71b3cf44f0fe9f14a2a207a176ec74faf9a8d57e9c890`;
- internal manifest SHA-256 `c63931f3cd9c6261710bd9db255a49aa03029a39d062fe21c714529c4b31fdb1`;
- recursive manifest **48/48**;
- source archive SHA-256 `08fa7f4403145216c1316240a4494c7fa069d77f2518ddbc6346812bcb91bdba`;
- packaged patch SHA-256 `b092219704f360e2f013cdeab83a12c870ac8e804f52f325edcfca2d2a17faac`;
- decoded patch SHA-256 `b93f420d7f9c8139663f8ff573613eeb23dd3c30073ff76c8b563c537fd07f10`.

The package must contain exactly the expected five executables, two project static libraries, 27 fixtures, build/configure/toolchain/submodule logs, compile commands, source patch/archive, metadata, and recursive checksum manifest.

## Turn boundary

Allowed:

- download, extract, checksum, inspect, and execute the exact artifact;
- create a runtime-only `bin/test-data -> ../test-data` fixture lookup symlink inside the extracted copy if required, recording it separately from artifact bytes;
- run packaged GoogleTest discovery, focused tests, bounded suites, and the packaged benchmark executable on committed fixture/manifest inputs;
- collect logs, JSON diagnostics, hashes, process-level repeatability evidence, timings, memory, and sanitizer-free validation already present in the artifact.

Forbidden:

- edit source, tests, CMake, fixtures, validators, tolerances, manifests, or packaged binaries/libraries;
- configure, compile, relink, rebuild, regenerate discovery, substitute another artifact, or apply a patch;
- use fallback/recovery, generic-producer substitution, fixture-specific acceptance, predicted output counts, or validator relaxation;
- merge or mark PR #8 ready.

If immutable authority does not match exactly, stop before runtime.

## 1. Verify artifact authority before execution

1. Verify both outer ZIP digests and ZIP integrity.
2. Verify `SHA256SUMS` itself and all 48 recursive entries.
3. Verify the exact six Git blobs from the Code + Build report against both packaged source and implementation authority.
4. Verify Release/static/Ninja, `PRE_TEST`, seven approved targets, dependency revisions, fixture closure, and `runtimeExecution=false` logs.
5. Confirm Code + Build logs contain no generated Directional runtime/test/benchmark/`ctest`/discovery/CLI/GUI/help/list/custom-input command.
6. Record the runtime-only fixture symlink separately, if needed, and preserve all artifact bytes.

## 2. Prove executable counterfactual closure

Use the packaged producer test executable's `--gtest_list_tests` exactly once. Require all **33** independently named `SurfaceCellTransitionQuotient.*` tests plus the strengthened `SurfaceCellsPhase10` certificate/torus/cylinder contracts to be present.

Map the discovered names to every reviewed contract before running them:

- topology-only genuine boundary and invented/missing interior-index rejection;
- certificate positive path and missing/duplicate/wrong-owner/wrong-sheet/nonreciprocal rejection;
- multi-isolation output without representative-sheet substitution;
- disconnected equal-position/equal-lattice authority remaining distinct;
- reciprocal ordinary endpoint orientation and wrong-endpoint rejection;
- full nonidentity periodic rotation/translation and tamper rejection;
- multiple periodic relations under reordering and swapped/missing owner rejection;
- hard-rail positive stitch and missing/ambiguous counterpart rejection;
- complete sorted scalar/source-support/region/sheet/chart/equivalence lineage;
- repeated corner, nonmanifold edge/fan, artificial boundary, and computed incidence topology;
- `retainIntermediateGeometry` true/false on the identical deterministic failure;
- semantic digest permutation invariance and connectivity/winding/support/component/lineage sensitivity.

Missing discovery is a blocker even if related source exists.

## 3. Run focused authority tests first

Run `SurfaceCellTransitionQuotient.*` in one isolated process and require every test to pass. Then run the exact reciprocal-isolation, topology-region row-invariance, source-disconnected sheet, hard-rail, polygonal/curved boundary, periodic relation, torus, and cylinder tests from `SurfaceCellsPhase10`.

Any certificate-bijection failure, representative-sheet behavior, coordinate/position weld, relation-order inference, invented boundary index, incomplete lineage, or retention asymmetry blocks acceptance immediately.

## 4. Re-run retained and bounded suites

Run the retained G0-G3/topology/polygonal/curved/mixed/relief/hard-rail/periodic groups, then the packaged bounded executables:

- producer;
- completion/simplification;
- validation;
- compiled API.

Require validation **60/60** and compiled API **8/8**. Historical completion failures may remain only if the exact prior ten are unchanged and no active contract regresses. Report focused/direct tests separately from aggregate totals and avoid double counting where practical.

## 5. Direct deterministic fixture matrix

Run plane, multi-face seam, close sheets, and cylinder in **three independent processes each** through the packaged benchmark executable and committed manifest authority.

Every process must report:

- direct `SurfaceCells` success and `CompletedSurfaceCells` output;
- strict-valid pure quads and complete lineage;
- no fallback, source-grid recovery, generic substitution, or terminal failure;
- exact semantic output digest stability across the three processes;
- raw structural hash used only as same-artifact serialization evidence.

Do not restore or invent a cross-version raw golden.

## 6. Exact torus acceptance

Run exact torus in **three independent processes**. Every process must require:

- phase-front `Produced`, direct pipeline success, and `CompletedSurfaceCells`;
- strict-valid pure quads and complete vertex/quad lineage;
- one connected component, zero boundary loops, Euler characteristic zero;
- exactly four retained and consumed topology regions;
- exactly eight retained and consumed internal isolation seams;
- exactly four retained and consumed periodic relations;
- stable semantic digest across processes;
- no fallback, recovery, generic substitution, permissive rejection branch, or predicted/golden vertex/quad/cell count.

If torus does not close, skip prescribed sphere and report the earliest truthful invariant with exact diagnostics.

## 7. Benchmark and closeout

Only after focused and direct acceptance, run the bounded committed manifest needed for benchmark/diagnostic closure. Scheduler-sensitive timing or memory cannot override a semantic failure.

Publish an artifact-only report with exact commands, per-test and per-fixture results, process-level hashes/diagnostics, bounded totals, performance observations, artifact/symlink authority, and the next evidence-driven plan. No source/test/build edit or rebuild is permitted. Keep PR #8 open, draft, and unmerged. The final repository write is one new top-level PR #8 conversation comment.
