# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority, M1a kernel semantics, and M1b first production-consumer migration are immutable accepted. **M1c field-transition consumer is compile/package complete but not semantically accepted until its immutable Test + Benchmark turn.** Architecture migration does not close G4.

## M1c field-transition consumer — Code + Build complete

Selected production boundary:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`, authoritative `CrossFieldEdgeTransition` consumption only.

| Evidence | Value |
|---|---|
| Migration base | `512d9523f13158a9f71b406b6db7137a1db3c504` |
| Implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Build/event | `ebda31859a18005844f81274393211991361cbbb` |
| Run/job | `31334345368 / 93297618568` |
| Result artifact | `9043971772` |
| Result SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Recursive manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| Compile | Release/static/Ninja **120/120** |
| Runtime | **false** |

M1c makes authoritative transition semantics typed at consumption:

- checked `SourceFaceId` reciprocity;
- checked `SourceVertexId` endpoints and canonical `SourceEdgeTopologyKey`;
- exact `QuarterTurn` modulo-four transport and inverse for reverse traversal.

It intentionally preserves raw signed `BranchTransitionResult.matching`, public cross-field storage, the separate legacy `edgeMatching` fallback, and all product/topology/certificate/rail/completion/validator policy.

Exactly six focused semantic/counterexample tests are compiled into the existing producer target. No generated Directional binary was executed, so this checkpoint is compile/package authority only.

Report:
`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Report.md`.

## Authoritative next turn

Run **M1c Field-Transition Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only result/log artifacts `9043971772 / 9043971968`. No rebuild, relink, source/test/fixture edit, substitution, regeneration, or repair is permitted.

Acceptance requires:

- exact preflight/postflight artifact and **54/54** package authority;
- exact M1c focused discovery and **6/6** contracts;
- existing transition counterexamples green, including periodic-holonomy tamper rejection;
- complete relevant producer preservation;
- M1b focused **6/6** and validation **77/77**;
- M1a exact 14 and **14/14**;
- T1 exact 29 and **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- explicit evidence-based Bunny known-red and Vase bounded safety-only dispositions.

Only after that turn may M1c be marked immutable accepted or another M1 consumer be planned.

## Accepted M1b authority remains unchanged

Accepted seam:
`RemeshPipeline -> fill_surface_optimization_rail_constraints -> provenance_supports_interval_sheet`.

- implementation `0340addf21473854856266ff00cb68915ce24ef0`;
- result artifact `9042940168`;
- focused **6/6**;
- validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green/oracle-clean.

Bunny remained known-red `NotProductionReady:completion` with independent-oracle-before-fatal evidence. Vase remained bounded nonreturn at 60 seconds. Their long-running checks may continue through the explicitly authorized artifact-only GitHub Actions procedure.

## Regression disposition

- `RP-01`: M1c checked face/vertex consumption **compile-complete; immutable runtime pending**.
- `RP-05`: M1c canonical source-edge semantic identity **compile-complete; runtime pending**.
- `RP-07`: M1c exact cyclic quarter-turn transport **compile-complete; runtime pending**.
- `RP-02 / TA-05`: following immutable turn must preserve independent M1b/M1a/T1/direct authority.
- Historical totals remain **34 events / 14 categories / 20 recurrences**; compile-only M1c creates no accepted new regression event.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current G4 production authority remains unchanged:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## Standing Bunny/Vase execution rule

For immutable Test + Benchmark turns, Bunny and Vase may use an ephemeral artifact-only GitHub Actions runner to avoid local execution-tool timeout limits. Exact artifact/package/executable authority must be verified before execution; no configure/build/relink/content mutation is allowed; executable mode may be restored only after content-hash verification; exact runtime evidence must be retained; temporary workflow/trigger/helper files must be removed before closeout.

## Architecture and test authority

- M1c Code + Build report: `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Report.md`;
- M1c immutable runtime plan: `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- M1b runtime report: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
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
