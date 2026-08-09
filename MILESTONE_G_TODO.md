# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority, M1a kernel semantics, and **M1b first production-consumer migration are immutable accepted**. Architecture work may proceed to one bounded M1c consumer; this does not close G4.

## M1b first production consumer — immutable accepted

Accepted seam:
`RemeshPipeline -> fill_surface_optimization_rail_constraints -> provenance_supports_interval_sheet`.

| Evidence | Value |
|---|---|
| Implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| Build/event | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| Result artifact | `9042940168` |
| Result SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| Log artifact | `9042940336` |
| Log SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Recursive manifest | **53/53**, `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| focused migration | **6/6** individually |
| full validation | **77/77** |
| M1a preservation | exact 14 discovery, **14/14** |
| T1 preservation | exact 29 discovery, **29/29** |

Direct comparison remained semantically unchanged:

| Case | M1b immutable result |
|---|---|
| Plane | pass, **1.000 s**, oracle-clean |
| MultiFaceSeam | pass, **1.559 s**, oracle-clean |
| CloseSheets | pass, **12.169 s**, oracle-clean |
| Cylinder | pass, **6.525 s**, oracle-clean |
| BunnyRandom | known-red `NotProductionReady:completion`; independent oracle rejects returned invalid product before fatal success assertion |
| Vase | bounded nonreturn at 60 s; safety evidence only |

Long-running Bunny/Vase evidence used an exact artifact-only GitHub Actions runner under explicit user authorization. Authoritative run `31332383845` reverified artifact `9042940168`, all 53 package checksums, implementation metadata, and producer executable hash before execution. Bunny evidence artifact `9043307980` has SHA-256 `c2e7776a9b68ffeeecc7471a3718a2c1bc90fae4556c7d7c05084b5ae8d8fb2d`; Vase artifact `9043307204` has SHA-256 `1726deb422a3eea238ab3895108a423f6fb6e932cabcc6b215916cc969e87105`. The temporary workflow and trigger were removed before closeout.

Postflight preserved both immutable build ZIP hashes and all **53/53** packaged checksums. M1b therefore accepts the first production use of checked source-face/source-vertex authority and semantic-ID/row separation; it creates no product regression event.

Report:
`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## Regression disposition

- `RP-01`: M1b first production source-face/source-vertex adoption **accepted**.
- `RP-05`: M1b semantic identity versus representation row boundary **accepted**.
- `RP-02 / TA-05`: preserved by focused + validation + M1a + T1 + direct independent-oracle evidence.
- M1b creates no new stable regression event/recurrence.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current G4 production authority remains:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## Authoritative next turn

**M1c Field-Transition Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Plan.md`.

Selected boundary:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`, authoritative `CrossFieldEdgeTransition` consumption only.

M1c may migrate only:

- checked source/target face identity to `SourceFaceId`;
- checked transition source-edge endpoints to `SourceVertexId` + canonical `SourceEdgeTopologyKey`;
- semantic branch matching to `QuarterTurn`, using exact inverse for reverse traversal.

M1c must preserve public `CrossFieldResult` storage, raw compatibility `BranchTransitionResult.matching`, the separate `edgeMatching` fallback, effort/geometric orientation, producer/tracing policy, topology/holonomy certificates, rails, completion, validators, fixtures, and product disposition. Code + Build executes no generated Directional binary; the following turn must be immutable Test + Benchmark.

## Standing Bunny/Vase execution rule

For future immutable Test + Benchmark turns, Bunny and Vase may use an ephemeral artifact-only GitHub Actions runner to avoid local container/tool timeout limits. Exact artifact/package/executable authority must be verified before execution; no configure/build/relink/content mutation is allowed; executable mode may be restored only after hash verification; evidence must be retained; temporary workflow/trigger files must be removed before closeout.

## Architecture and test authority

- M1b runtime report: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- M1c plan: `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Plan.md`;
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
7. prescribed sphere, G5/G6, Bunny/Vase production success, fallback/recovery, optimization;
8. later M1 consumers, M2–M6 and T2–T6.

PR #8 remains open, draft, and unmerged. Every completed turn ends with one new top-level PR #8 conversation comment after all branch-file and PR-body writes.
