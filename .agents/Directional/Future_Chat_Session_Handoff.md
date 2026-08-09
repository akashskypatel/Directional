# Future Chat Session Handoff

## Mandatory next turn

Run **M1b First Production Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1 authority kernel and compatibility boundary**;
- M1a status: **immutable accepted**;
- review policy: `never`;
- production behavior delta authorized for M1b: **none**.

M1b must migrate exactly one real production consumer. Do not broaden the slice to chart/transition graphs, producers, tracing, arrangement, completion, quotient, validators, fixtures, benchmark policy, G4-R007, Bunny, or Vase.

## Accepted M1a immutable authority

Authoritative runtime report:

`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`

Exact authority:

| Evidence | Value |
|---|---|
| Entering pre-M1a head | `9f1d3ebd91403252e990f785c3521588197b4fd4` |
| M1a implementation | `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7` |
| Build/event commit | `a29c1f673ea93e1614751f42a0c1fef94d23e1fe` |
| Workflow run/job | `31327073928 / 93279043100` |
| Result artifact | `9041930767` |
| Result SHA-256 | `1c1325c038ffe26b80e00dbb69fb15de8b0d0a42673d9720f28bcd9de8549ec5` |
| Log artifact | `9041930871` |
| Log SHA-256 | `e99e053ea4503b720dbe9b6c9ed4762a4eedcbf67c15261e8ea4317824c427cb` |
| Recursive manifest | **53/53**, `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6` |
| Package regular files | **54** including manifest |
| Code + Build closure | Release/static/Ninja **120/120**, `PRE_TEST`, `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

Preflight/postflight:

- both original ZIP hashes exact before and after runtime;
- no unsafe archive paths;
- all **53/53** package hashes exact before and after runtime;
- seven ELF executables, two static libraries, 27 fixtures;
- source patch/archive/compile DB/source blobs exact;
- source archive had 552 safe members;
- all eight pre-existing T1 binaries/libraries were byte-identical to accepted T1 artifact `9041289209`;
- only runtime locator added: non-regular `bin/test-data -> ../test-data`.

### M1a authority-kernel acceptance

`directional_surface_cell_authority_kernel_tests` discovery exactly once: **14/14 exact names/order**.

All 14 contracts ran individually in fresh processes and passed **14/14**. Source inspection confirmed intended semantic/counterexample coverage:

- compile-time cross-domain/raw non-convertibility;
- typed valid/negative/out-of-range/domain-mismatch conversion;
- raw numeric coincidence does not conflate domains;
- canonical source-edge identity with explicit orientation;
- tagged source-support alternatives;
- exact modulo-4 quarter turns;
- grid automorphism identity/inverse/associativity;
- nonzero rotation+translation exact round trip;
- valid source-boundary transition without invented interior ID;
- typed rejection of missing interior transition;
- exact/involutive canonical route reversal;
- representation-handle perturbation invariant;
- adapter round trip;
- deliberate cross-domain misuse rejection.

The static non-convertibility test packages compile-time `static_assert` proof; its runtime `SUCCEED()` is not treated as standalone semantic evidence.

### T1 preservation

`directional_surface_cell_oracle_tests` discovery exactly once: **29/29 exact names/order**. All oracle contracts passed individually: **29/29**.

Direct cases:

| Case | Result |
|---|---|
| Plane | pass, 1.00 s, oracle-clean |
| MultiFaceSeam | pass, 1.53 s, oracle-clean |
| CloseSheets | pass, 12.16 s, oracle-clean |
| Cylinder | pass, 6.82 s, oracle-clean |
| BunnyRandom | known-red `NotProductionReady:completion`, 56.93 s; oracle failure still occurs before fatal product-success assertion |
| Vase | bounded nonreturn at 60.00 s; safety evidence only |

Bunny retains the accepted T1 signature: `EmptyOutput`, `NonQuadOutput`, component/Euler mismatch, output-origin mismatch, `TerminalFailureObserved:NotProductionReady:completion`, followed by `traceSegments=170831 arrangementCells=0 completedQuads=0` at the unchanged fatal success assertion.

A surrounding execution tool interrupted two preliminary Bunny invocations before completion; they are explicitly non-authoritative orchestration attempts. The same immutable binary/filter completed under the planned 90-second detached process guard and produced the authoritative result above. No packaged regular file changed.

## M1a regression/architecture disposition

- `RP-01`: **M1a kernel accepted**; production adoption remains incremental.
- `RP-05`: **M1a kernel accepted** for semantic identity/orientation/reversal.
- `RP-07`: **M1a kernel accepted** for exact Z4/automorphism/reversal algebra.
- `RP-02 / TA-05`: accepted T1 independent test boundary preserved.
- M1a creates/resolves no production regression event.
- historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178` and is unaffected.

## M1b exact consumer boundary

Selected call path:

`RemeshPipeline -> fill_surface_optimization_rail_constraints -> surface_optimization_rail_detail::provenance_supports_interval_sheet`.

M1b migrates only the validated **source-face/source-vertex identity seam** in `SurfaceOptimizationRailConstraints`.

Allowed implementation paths are defined in the plan and are bounded to:

- `CMakeLists.txt`;
- `cmake/DirectionalTests.cmake`;
- `include/directional/geometry/SurfaceOptimizationRailConstraints.h` only if the detail helper signature requires it;
- `src/geometry/SurfaceOptimizationRailConstraints.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

Core migration rules:

1. attach `src/authority/AuthorityKernel.cpp` once to `directional_core` and remove any duplicate direct test-target compilation;
2. preserve current negative sentinel and extent checks before typed conversion;
3. convert validated legacy source faces via `LegacyAuthorityAdapters::source_face`;
4. convert validated legacy source vertices via `LegacyAuthorityAdapters::source_vertex`;
5. internal helper logic consumes `SourceFaceId` / `SourceVertexId`, not raw integers;
6. convert back with `to_legacy_index` only at Eigen/vector row access;
7. typed conversion failure follows the existing rejection path—never clamp, wrap, default, or substitute.

### Explicit non-goals

Do not change:

- `SurfacePoint.face` or `SurfaceFeatureCurveInterval.sourceFace` public/legacy storage;
- component/sheet/chart/transition/rail domains outside this seam;
- the existing `1e-8` barycentric support classification/tolerance;
- projection, rail ordering, feature assignment, fixed-vertex policy, optimizer policy;
- producer/validator/tracing/arrangement/completion/quotient behavior;
- fixtures, benchmark acceptance, fallback/recovery, G4-R007, Bunny, or Vase.

The existing tolerance-derived support classification is explicitly **not** endorsed as canonical identity; M5/AR-09 owns exact source-support rebinding. Use exact barycentric boundary values in M1b focused tests.

## M1b required focused authority

The Code + Build turn adds/strengthens only enough default-built tests to prove:

- same-sheet behavior unchanged;
- legal exact cross-sheet source-edge/vertex incidence remains accepted;
- cross-sheet interior provenance remains rejected;
- negative/out-of-range source faces retain old rejection semantics;
- wrong source face lacking the typed source vertex rejects;
- component/sheet mismatch behavior unchanged;
- helper signatures prevent `SourceFaceId` / `SourceVertexId` interchange;
- no expected result is synthesized from the implementation.

Code + Build may compile/package but executes no generated Directional binary, discovery, tests, benchmarks, `ctest`, CLI/GUI/help/version, fuzzers, or custom input.

The following immutable Test + Benchmark must prove the M1b focused contracts plus M1a **14/14**, T1 **29/29**, direct four-green preservation, Bunny independent-oracle-first known-red behavior, and Vase safety-only bounded visibility before another consumer may migrate.

## Production authority remains known-red

Production G4 authority remains artifact `9031804178`, implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49`:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`;
- `PR8-R034 / G4-R007` stays active.

## Core references

- `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Plan.md`;
- `.agents/Directional/DESIGN.md`, especially sections 6.1–6.4;
- `.agents/Directional/REORIENTATION_PLAN.md`, M1;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.

## Deferred blockers

- active representative torus `G4-R007`;
- shared hard-rail scheduling `G4-B002`;
- nonzero periodic Z4 production capability `G4-B003`;
- positive multi-isolation witness `G4-B004`;
- historical transition-quotient/completion failures;
- strict-validator timing;
- prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization;
- later M1 consumers, M2–M6 and T2–T6.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
