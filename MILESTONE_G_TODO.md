# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c architecture slices are immutable accepted. Architecture migration remains a separate progress axis and does not close G4.

## M1c field-transition consumer — immutable accepted

Accepted production boundary:
`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`, authoritative `CrossFieldEdgeTransition` consumption only.

| Evidence | Value |
|---|---|
| Implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Build/event | `ebda31859a18005844f81274393211991361cbbb` |
| Build run/job | `31334345368 / 93297618568` |
| Result artifact | `9043971772` |
| Result SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Recursive manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| M1c focused | **6/6** |
| transition counterexamples | **3/3** |
| M1b / validation | **6/6**, **77/77** |
| M1a / T1 | **14/14**, **29/29** |
| required-green producer segment | **157/157** |

Producer discovery is exactly **172** and fully accounted for. Four direct required-green product cases remain green/oracle-clean. Nine historical/deferred producer tests remain explicitly red and map to already-known quotient/completion, strict-validator timing, and exact-torus blockers; they are not new M1c regressions.

Long-running comparison used artifact-only Actions run `31341209985`:

- Bunny job `93315178447`: exact one-test rc=1 after 63.09 s, independent oracle rejects first, then unchanged `NotProductionReady:completion`; known-red preserved. Evidence `9045884237`, SHA-256 `7b7ea790d386ed82667d4827bf8cb39910a08d9a8d9c075c24ac7ffa61dd7633`.
- Vase job `93315178308`: exact one-test selection reached `[ RUN ]`, bounded rc=124 at 60.00 s; safety-only known-red preserved. Evidence `9045884496`, SHA-256 `9f231de99277d19e1ab8a3c7ec7c937ba86df14d675bc77f384c7eb1c3c6c04c`.

Postflight preserved both immutable build ZIP hashes and all **54/54** package checksums. Temporary runtime workflow/trigger files were removed.

Report:
`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## Authoritative next turn

Run **M1d Phase-Front Route Identity Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Plan.md`.

Selected boundary:
`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`.

M1d is intentionally narrow. It may make existing authoritative HardRail/PeriodicCut route identity typed at consumption using checked `InteriorTransitionId`, checked `SourceVertexId`, and canonical `SourceEdgeTopologyKey` while preserving public `sourceRouteEdges/sourceRouteTopology` vectors and all existing product policy.

M1d must not migrate route producers, public route storage, per-step transport, `TransitionStep`, `CanonicalRoute`, `FieldChartId`, periodic certificates, topology planning, shared rails, quotient materialization, validators, fixtures, fallback/recovery, or known-red dispositions. Code + Build executes no generated Directional binary.

## Regression disposition

- `RP-01`: M1c checked face/vertex authority **accepted**; M1d next touches compact transition/source-vertex route domains.
- `RP-05`: M1c canonical source-edge identity **accepted**; M1d next migrates packed route topology/index representation at one consumer.
- `RP-07`: M1c exact modulo-four/inverse transport **accepted** and is a preservation boundary for M1d.
- `RP-02 / TA-05`: preserved by exact M1c/M1b/M1a/T1/direct evidence.
- No new stable regression event or recurrence. Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current G4 production authority remains unchanged:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## Standing Bunny/Vase execution rule

For immutable Test + Benchmark turns, Bunny and Vase may use an ephemeral artifact-only GitHub Actions runner. Exact artifact/package/executable authority must be verified before execution; no configure/build/relink/content mutation is allowed; executable mode may be restored only after content-hash verification; exact runtime evidence must be retained; temporary workflow/trigger/helper files must be removed before closeout.

## Architecture and test authority

- M1c runtime report: `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- M1d next plan: `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Plan.md`;
- normative architecture: `.agents/Directional/DESIGN.md`;
- migration roadmap: `.agents/Directional/REORIENTATION_PLAN.md`;
- testing policy: `tests/TESTING_STRATEGY.md`;
- regression tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`.

## Deferred blockers

1. active direct-torus `G4-R007`;
2. shared hard-rail schedule / exact-torus `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic Z4 production capability (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. historical transition-quotient/completion failures;
6. strict-validator timing;
7. prescribed sphere, G5/G6, Bunny/Vase production success, fallback/recovery, optimization;
8. later M1 consumers, M2–M6 and T2–T6.

PR #8 remains open, draft, and unmerged. Every completed turn ends with one new top-level PR #8 conversation comment after all branch-file and PR-body writes.
