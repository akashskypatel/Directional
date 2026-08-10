# Milestone G Production Readiness TODO

Last updated: 2026-08-10 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d architecture slices are immutable accepted. M1e compile/package is complete and immutable runtime is pending. Architecture migration remains separate from G4 product acceptance.

## M1d phase-front route identity — immutable accepted

Selected consumer:
`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`.

| Evidence | Value |
|---|---|
| Implementation | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Build/event | `98a21f3d843533dcc44cb296711268e0ebb26fb6` |
| Build run/job | `31342400614 / 93318225812` |
| Result artifact / SHA-256 | `9046308272` / `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c` |
| Log artifact / SHA-256 | `9046308461` / `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c` |
| Recursive manifest | **59/59**, `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0` |
| Producer discovery | **178** |
| M1d focused / route witnesses | **6/6**, **3/3** |
| M1c / transition counterexamples | **6/6**, **3/3** |
| required-green producer | **163/163** |
| M1b / validation | **6/6**, **77/77** |
| M1a / T1 | **14/14**, **29/29** |

The migration accepts checked `SourceVertexId`, canonical `SourceEdgeTopologyKey`, and checked `InteriorTransitionId` at the authoritative HardRail/PeriodicCut route-identity consumer while preserving public packed route representation, route order/production, per-step transport, relation policy, diagnostics, and existing failure reasons.

Direct Plane/MultiFaceSeam/CloseSheets/Cylinder remain green and independent-oracle clean. Nine historical/deferred producer reds remain explicit and unchanged in class.

M1d Bunny/Vase artifact-only comparison run `31343763822` preserved accepted known-red/safety dispositions and exact package authority. Bunny remained `NotProductionReady:completion` with independent-oracle-before-fatal ordering; Vase reached `[ RUN ]` and was bounded at 60 seconds. Temporary runtime workflow/trigger files were removed.

Current retained report:
`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## M1e compile/package checkpoint and authoritative next turn

Run **M1e Segment Route Transport Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Selected boundary:
`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

M1e is intentionally narrow. Implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` replaces only raw cumulative signed matching across the ordered step route with checked step identity, `QuarterTurn` / zero-shift `GridAutomorphism`, `TransitionStep`, `CanonicalRoute`, and typed algebraic composition while preserving observed route direction through `oriented_steps()` and retaining the existing raw output/provenance representation.

M1e must not migrate the separate periodic-holonomy loop, `FieldChartId`, public route/segment schemas, topology-region planning, shared rail scheduling, quotient/certificate ownership, validators, fixtures, fallback/recovery expansion, optimization, or G4 behavior.

Compile-only run/job `31351113129 / 93341993183` completed **120/120**. Result/log artifacts `9049125645 / 9049125905` have ZIP SHA-256 `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7 / fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`; the recursive manifest is **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`. Code + Build executed no generated Directional binary. M1e is not accepted until immutable runtime passes.

Current Code + Build report:
`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`.

## Regression disposition

- `RP-01`: M1e checked step domains **compile-complete; runtime pending**.
- `RP-05`: M1e semantic step identity and observed/canonical route order **compile-complete; runtime pending**.
- `RP-07`: M1e cumulative ordered-route transport **compile-complete; runtime pending**.
- `RP-02 / TA-05`: exact producer/M1d/M1c/M1b/M1a/T1/direct authority preserved through M1d and pending M1e immutable validation.
- No new stable regression event or recurrence. Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current G4 authority remains unchanged:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## Standing Bunny/Vase execution rule

For immutable Test + Benchmark turns, Bunny and Vase may use an ephemeral artifact-only GitHub Actions runner. Exact build artifact/package/executable authority must be verified before execution; no configure/build/relink/content mutation is allowed; exact runtime evidence must be retained; temporary workflow/trigger/helper files must be removed before closeout.

## Cleanup rule

The mandatory durable cleanup policy is in `.agents/Directional/Future_Chat_Session_Handoff.md`. Every Test + Benchmark turn begins by cleaning stale previous evidence after its facts are folded into durable authority and ends with only the new current report plus exactly one next Code + Build plan in addition to durable `.agents/Directional` documents.

## Core references

- `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Plan.md`;
- `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.

## Deferred blockers

1. active direct-torus `G4-R007`;
2. shared hard-rail schedule / exact-torus `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic Z4 production capability (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. historical transition-quotient/completion failures;
6. strict-validator timing;
7. prescribed sphere, G5/G6, Bunny/Vase production success, fallback/recovery, optimization;
8. later M1 consumers, M2–M6 and T2–T6.

PR #8 remains open, draft, and unmerged. Every completed turn ends with one new top-level PR #8 conversation comment after all branch and PR-body writes.
