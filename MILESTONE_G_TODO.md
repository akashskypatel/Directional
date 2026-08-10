# Milestone G Production Readiness TODO

Last updated: 2026-08-10 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d/M1e/M1f architecture slices are immutable accepted. M1g Periodic Holonomy Route Transport Consumer is compile/package complete and immutable runtime validation is next. Architecture migration remains separate from G4 product acceptance.

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

M1d accepted facts are retained in `.agents/Directional/Regression_Root_Cause_Tracker.md` and the current immutable M1e report.

## M1e segment route transport — immutable accepted

Selected boundary:
`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

Implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` replaces only raw cumulative signed matching across the ordered step route with checked step identity, `QuarterTurn` / zero-shift `GridAutomorphism`, `TransitionStep`, `CanonicalRoute`, and typed algebraic composition while preserving observed route direction through `oriented_steps()` and retaining the existing raw output/provenance representation.

M1e does not migrate the separate periodic-holonomy loop, `FieldChartId`, public route/segment schemas, topology-region planning, shared rail scheduling, quotient/certificate ownership, validators, fixtures, fallback/recovery expansion, optimization, or G4 behavior.

| Evidence | Value |
|---|---|
| Build run/job | `31351113129 / 93341993183`, **120/120** |
| Result artifact / SHA-256 | `9049125645` / `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7` |
| Log artifact / SHA-256 | `9049125905` / `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be` |
| Recursive manifest | **61/61**, `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5` |
| Producer discovery | exactly **184** |
| M1e focused | **6/6** |
| required-green producer | **169/169** |
| M1d / M1c / M1b | **6/6 + 3/3**, **6/6 + 3/3**, **6/6** |
| validation / M1a / T1 | **77/77**, **14/14**, **29/29** |
| direct products | Plane / MultiFaceSeam / CloseSheets / Cylinder green and independent-oracle clean |

M1e accepted facts remain retained in the durable handoff and regression tracker.

## Authoritative next turn

Run **M1g Periodic Holonomy Route Transport Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Consume only exact M1g artifacts `9053047653 / 9053048092`. Rebuild, relink, regeneration, source/test/build/fixture edits, repair, and artifact substitution are prohibited. Expected producer discovery is **196**, M1g focused is **6/6** individually, and required-green producer is **181/181**. Existing nonzero periodic rotation rejection remains mandatory and `G4-B003` stays unresolved.

## M1f vertex-continuation transport — immutable accepted

Selected boundary:
`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Final implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` is immutable accepted from artifacts `9050850344 / 9050850513`: producer discovery **190**, M1f **6/6**, required-green **175/175**, M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle gates passed. Bunny preserved `NotProductionReady:completion`, Vase was bounded safety-only at 60 seconds, and local/remote postflight preserved exact **59/59** package authority. Accepted facts remain in the durable handoff and regression tracker. M1g corrects the checksum-valid direct-product metadata names without behavior changes.

## M1g periodic-holonomy route transport — compile/package complete

Selected boundary:
`periodic canonical face cycle -> ordered source-edge crossings -> whole-cycle holonomy decision`.

Implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` replaces only the whole-cycle raw matching accumulator with checked crossing domains, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition. It preserves canonical cycle discovery/order, legacy matching, public periodic holonomy, lattice/cut route, `PeriodicHolonomyMismatch`, current G4 outcomes, and unresolved `G4-B003`.

| Evidence | Value |
|---|---|
| Build run/job | `31362470744 / 93373936472`, **120/120** |
| Result artifact / SHA-256 | `9053047653` / `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c` |
| Log artifact / SHA-256 | `9053048092` / `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9` |
| Recursive manifest | **64/64**, `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae` |
| Package | **65** regular files; 7 executables; 2 static libraries; 27 fixtures |
| Build boundary | Release/static/Ninja/PRE_TEST; runtime **false** |

Exactly six M1g production-path contracts are compiled and unexecuted. The package contains the corrected four parameterized direct-product test names. Current report: `.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Code_Build_Report.md`.

## Regression disposition

- `RP-01`: M1e checked step domains **accepted**; M1f continuation-step domains **accepted**.
- `RP-05`: M1e semantic step identity and observed/canonical route order **accepted**; M1f continuation route identity/orientation **accepted**.
- `RP-07`: M1e cumulative ordered-route transport **accepted**; M1f continuation transport **accepted**.
- `RP-02 / TA-05`: exact producer/M1d/M1c/M1b/M1a/T1/direct authority preserved through immutable M1e validation; M1f preservation accepted under exact artifact-only validation.
- M1g `RP-01 / RP-05 / RP-07` is compile/package complete and runtime pending; no M1g preservation claim is accepted before exact artifact execution.
- No new stable regression event or recurrence. Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.
- Strict-validator timing remains nondeterministic: M1e **6/10 pass, 4/10 fail**; M1f **9/10 pass, 1/10 fail**. It remains a deferred performance-test defect; no threshold/retry workaround is authorized.

Current G4 authority remains unchanged:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## Standing Bunny/Vase execution rule

For immutable Test + Benchmark turns, Bunny and Vase may use an ephemeral artifact-only GitHub Actions runner. Exact build artifact/package/executable authority must be verified before execution; no configure/build/relink/content mutation is allowed; exact runtime evidence must be retained; temporary workflow/trigger/helper files must be removed before closeout.

## Cleanup rule

The mandatory durable cleanup policy is in `.agents/Directional/Future_Chat_Session_Handoff.md`. Every Test + Benchmark turn begins by cleaning stale previous evidence after its facts are folded into durable authority and ends with only the new current report plus exactly one next Code + Build plan in addition to durable `.agents/Directional` documents.

## Core references

- `.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
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
