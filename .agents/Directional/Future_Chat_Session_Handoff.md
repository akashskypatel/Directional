# Future Chat Session Handoff

## Mandatory next turn

Run **M1c Field-Transition Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1 authority kernel and staged production adoption**;
- M1a authority kernel: **immutable accepted**;
- M1b first production consumer: **immutable accepted**;
- review policy: `never`.

The next turn is mutating **Code + Build only**. It may implement the bounded M1c seam and compile/package, but must execute no generated Directional binary, GoogleTest discovery/test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

## Accepted M1b immutable authority

Authoritative runtime report:
`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Accepted seam:
`RemeshPipeline -> fill_surface_optimization_rail_constraints -> surface_optimization_rail_detail::provenance_supports_interval_sheet`.

Exact authority:

| Evidence | Value |
|---|---|
| M1b base | `9a4131f9655567ffc60c2c513db1c73826165bb2` |
| implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| build/event | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| build run/job | `31330737703 / 93288453677` |
| result artifact | `9042940168` |
| result SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| log artifact | `9042940336` |
| log SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| recursive manifest | **53/53**, `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| package | 54 regular files including manifest; seven ELF; two static libs; 27 fixtures |
| Code + Build | Release/static/Ninja **120/120**, `PRE_TEST`, `runtimeExecution=false` |

Immutable Test + Benchmark acceptance:

- validation native discovery exactly **77**;
- exactly six `SurfaceOptimizationRailAuthorityMigration` members;
- M1b focused contracts **6/6** individually in fresh processes;
- full validation **77/77**;
- M1a authority discovery exact 14 and **14/14** individually;
- T1 oracle discovery exact 29 and **29/29** individually;
- postflight preserved both build ZIP hashes and every **53/53** packaged checksum.

Direct required-green comparison:

| Case | Result |
|---|---|
| Plane | pass, **1.000 s**, independent oracle clean |
| MultiFaceSeam | pass, **1.559 s**, independent oracle clean |
| CloseSheets | pass, **12.169 s**, independent oracle clean |
| Cylinder | pass, **6.525 s**, independent oracle clean |

Four preliminary direct invocations mistakenly targeted the standalone benchmark CLI with GoogleTest filters and exited immediately with `Unknown benchmark option`; no test was selected. They are non-authoritative orchestration attempts only.

## Bunny/Vase standing GitHub Actions procedure

The user explicitly authorizes **GitHub Actions workflows for Bunny and Vase going forward** to avoid local container/execution-tool timeout issues.

M1b authoritative long-running runtime run: `31332383845`.

- Bunny job `93292577409`: exact one-test selection; wrapper rc=1 after about 64 s / GoogleTest 63.865 s. Independent oracle rejects first with empty/non-quad/component/Euler/origin/terminal issues; afterward the unchanged fatal success assertion reports `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`. Known-red preserved. Evidence artifact `9043307980`, SHA-256 `c2e7776a9b68ffeeecc7471a3718a2c1bc90fae4556c7d7c05084b5ae8d8fb2d`.
- Vase job `93292577420`: exact one-test selection reached `[ RUN ]`, bounded rc=124 at 60 s, no returned result. Safety evidence only. Artifact `9043307204`, SHA-256 `1726deb422a3eea238ab3895108a423f6fb6e932cabcc6b215916cc969e87105`.

Required future procedure:

1. use a temporary artifact-only workflow in the **Test + Benchmark** turn only;
2. download the exact immutable build artifact by run/artifact identity;
3. verify GitHub artifact digest, `SHA256SUMS`, every package checksum, implementation metadata, and selected executable content hash before runtime;
4. never configure, compile, relink, regenerate, substitute, or edit product/test/fixture content;
5. `actions/download-artifact` may strip executable mode; restore `+x` only **after** content-hash verification;
6. a non-regular runtime fixture locator may be created if required;
7. run the exact existing Bunny/Vase tests with explicit process guards and retain filter, stdout/stderr, return code, elapsed time, and evidence-artifact digest;
8. workflow job success means orchestration success only—classify the underlying GoogleTest result from logs;
9. delete temporary workflow/trigger files before closeout so the net implementation/test/build diff is zero.

A preliminary M1b workflow run `31332304742` verified package authority but returned rc=126 before generated-binary execution because executable mode had been stripped. It is non-authoritative orchestration evidence, not a regression.

## M1b regression/architecture disposition

- `RP-01`: first production strong-ID source-face/source-vertex seam **accepted**.
- `RP-05`: first semantic-ID versus row-representation boundary **accepted**.
- `RP-02 / TA-05`: accepted independent authority preserved through M1b.
- M1b creates no production regression event or recurrence.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** and separate.

Production G4 authority remains artifact `9031804178`:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, topology `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## M1c exact consumer boundary

Selected call path:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`.

M1c migrates only the **authoritative `fields::CrossFieldEdgeTransition` consumption path**.

Default allowed implementation/test paths:

- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`;
- `include/directional/geometry/SurfaceCellTracing.h` only if a narrowly typed detail-helper signature is genuinely required.

No CMake change is expected.

Mandatory implementation rules:

1. preserve existing adjacency/topology checks;
2. convert source/target and transition face integers through checked `LegacyAuthorityAdapters::source_face(..., faces.rows())` before semantic face reciprocity;
3. convert transition `sourceVertex0/1` through checked `source_vertex(..., vertices.rows())`;
4. canonicalize those typed endpoints through `SourceEdgeTopologyKey::make` and compare to the existing `uint64_t edgeKey` only at an explicit legacy representation boundary;
5. authoritative matching semantics use `QuarterTurn::from_integer`; reverse traversal uses `.inverse()`;
6. preserve the existing raw signed `BranchTransitionResult.matching` compatibility value so downstream behavior does not change in M1c;
7. preserve the separate `edgeTransitions == nullptr` `edgeMatching`/`edgeEffort` fallback path unchanged;
8. malformed authoritative transition metadata remains fail-closed and must never fall through to legacy matching/geometric inference.

Explicit non-goals:

- no `CrossFieldResult`/`CrossFieldEdgeTransition` public schema change;
- no `InteriorTransitionId`, `FieldChartId`, `TransitionStep`, or `CanonicalRoute` production migration yet;
- no topology-region/isolation/periodic certificate changes;
- no rail, arrangement, completion, quotient, optimizer, validator, fixture, benchmark-policy, fallback, or recovery changes;
- no G4-R007/Bunny/Vase behavior change.

## M1c mandatory pattern checks

- `RP-01` touched: source face and vertex domains must be checked and non-interchangeable.
- `RP-05` touched: semantic source-edge identity must not depend on endpoint order or raw hash representation.
- `RP-07` touched: quarter-turn matching must be exact modulo four and reverse traversal must use algebraic inverse.
- `RP-02 / TA-05` preservation: focused transition tests cannot replace M1b/M1a/T1/direct evidence.

Required focused counterexamples are defined in the M1c plan, including forward +1, reverse inverse, `+5 == +1` semantically, reversed source-edge endpoints, malformed authoritative face/edge fail-closed, and unchanged legacy matching fallback.

The following immutable turn must also retain explicit visibility for existing `NonReciprocalSourceAdjacentIsolationSeamFailsClosed`, `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`, and periodic-holonomy tamper rejection.

## Core references

- `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Plan.md`;
- `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.

## Deferred blockers

- active representative torus `G4-R007`;
- shared hard-rail scheduling `G4-B002`;
- nonzero periodic Z4 product capability `G4-B003`;
- positive multi-isolation witness `G4-B004`;
- historical transition-quotient/completion failures;
- strict-validator timing;
- prescribed sphere, G5/G6, Bunny/Vase production success, fallback/recovery, optimization;
- later M1 consumers, M2–M6 and T2–T6.

At the start of the next turn, fetch fresh PR/head state and verify it is a descendant of the accepted M1b implementation. Do not assume the branch head from this handoff if external commits have moved it.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
