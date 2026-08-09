# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 is accepted. M1a authority-kernel semantics are accepted. M1b has compiled/packaged the first production consumer and awaits immutable runtime acceptance.

## M1b first production consumer — compile/package complete

Selected boundary:
`RemeshPipeline -> fill_surface_optimization_rail_constraints -> provenance_supports_interval_sheet`.

Exact authority:

| Evidence | Value |
|---|---|
| M1b base | `9a4131f9655567ffc60c2c513db1c73826165bb2` |
| Implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| Build/event commit | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| Workflow run/job | `31330737703 / 93288453677` |
| Result artifact | `9042940168` |
| Result SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| Log artifact | `9042940336` |
| Log SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Recursive manifest | **53/53**, `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| Compile closure | Release/static/Ninja **120/120**, `PRE_TEST`, `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

M1b attaches `AuthorityKernel.cpp` once to `directional_core`, removes duplicate direct test-target compilation, and converts the validated rail-consumer source-face/source-vertex identity seam to `SourceFaceId` / `SourceVertexId` behind named checked adapters. Public storage and current sentinel/component/sheet/barycentric/rail/optimizer/product semantics are intentionally unchanged.

Six focused migration contracts are packaged in the default validation target, which now statically contains **77** tests total. M1a's exact 14-name and T1's exact 29-name manifests remain unchanged.

No generated project binary ran in Code + Build. Report:
`.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Report.md`.

## Authoritative next turn

**M1b First Production Consumer — immutable Test + Benchmark** under:

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only artifacts `9042940168 / 9042940336`. Acceptance requires:

- exact package/source/dependency verification and **53/53** checksums;
- validation discovery exactly **77** with the six named M1b contracts;
- M1b focused **6/6** individually;
- full validation **77/77**;
- M1a authority **14/14** with exact discovery;
- T1 oracle **29/29** with exact discovery;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green/oracle-clean;
- BunnyRandom/Vase explicit known-red visibility without synthetic green status;
- unchanged postflight package hashes.

Only after this immutable turn accepts M1b may another M1 production consumer be selected.

## Regression disposition

- `RP-01`: first strong-ID production seam is **compile-complete / runtime pending**.
- `RP-05`: semantic identity/representation separation at the rail seam is **compile-complete / runtime pending**.
- `RP-02 / TA-05`: accepted independent authority must be re-executed from the M1b artifact.
- No previously accepted runtime result is currently known lost, so no new stable regression event/recurrence is created.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains active under production artifact `9031804178`.

Current G4 authority remains:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## M1b build correction record

The first source migration compile failed solely because a reopened `surface_optimization_rail_detail` namespace lacked its closing brace. Corrective implementation `0340addf...` added only the missing namespace close and passed 120/120. This was unaccepted migration work, not a production regression event.

## Architecture and test authority

- M1b report: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Report.md`;
- next runtime plan: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- M1a accepted report: `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`;
- normative architecture: `.agents/Directional/DESIGN.md`;
- migration roadmap: `.agents/Directional/REORIENTATION_PLAN.md`;
- testing policy: `tests/TESTING_STRATEGY.md`;
- regression tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`.

## Deferred blockers

1. active representative torus `G4-R007`;
2. shared hard-rail schedule / exact-torus `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic Z4 production capability (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. historical transition-quotient/completion failures;
6. strict-validator timing;
7. prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization;
8. later M1 consumers, M2–M6 and T2–T6.

PR #8 remains open, draft, and unmerged. Every completed turn ends with one new top-level PR #8 conversation comment after all branch-file and PR-body writes.
