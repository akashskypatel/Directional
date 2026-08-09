# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c architecture slices are immutable accepted. **M1d phase-front route identity is Code + Build complete and awaits immutable runtime.** Architecture migration remains separate from G4 product acceptance.

## M1d phase-front route identity — Code + Build complete

Selected consumer:
`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`.

| Evidence | Value |
|---|---|
| Implementation | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Build/event | `98a21f3d843533dcc44cb296711268e0ebb26fb6` |
| Build run/job | `31342400614 / 93318225812` |
| Result artifact | `9046308272` |
| Result SHA-256 | `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c` |
| Log artifact | `9046308461` |
| Log SHA-256 | `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c` |
| Recursive manifest | **59/59**, `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0` |
| Compile | **120/120**, Release/static/Ninja |
| Runtime | **false** |

The package contains 60 regular files including manifest, seven ELF executables, two static libraries, and 27 fixtures; read-only verification matched both outer artifact digests and every manifest entry.

M1d changes only semantic identity validation for existing authoritative HardRail/PeriodicCut route pairs:

- packed route endpoints cross checked `SourceVertexId`;
- semantic source-edge identity/uniqueness uses canonical `SourceEdgeTopologyKey`;
- compact transition values cross checked `InteriorTransitionId`;
- the existing packed topology/index values remain public compatibility representations only;
- existing route cardinality/interior-incidence checks and `InvalidHardRailAuthority` / `InvalidPeriodicCutAuthority` failure paths remain unchanged.

No route transport, `TransitionStep`, `CanonicalRoute`, public schema, producer order, topology policy, periodic certificate, quotient behavior, fixture, validator, fallback, or G4 behavior was migrated.

Exactly six M1d semantic/counterexample contracts are compiled into the existing producer target. No generated binary was executed in this turn.

Report:
`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Report.md`.

## Authoritative next turn

Run **M1d Phase-Front Route Identity Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only artifacts `9046308272 / 9046308461`; no rebuild, relink, regeneration, source/test/fixture edit, substitution, or repair is permitted.

Acceptance requires:

- exact artifact/source/executable preflight and postflight with **59/59** checksums;
- producer discovery exactly **178**;
- exact M1d suite membership of six and **6/6** focused contracts;
- three existing route counterexamples green;
- M1c **6/6** and three M1c transition counterexamples green;
- required-green producer segment **163/163**;
- nine historical/deferred producer reds explicitly retained and classified;
- M1b **6/6**, validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- Bunny/Vase evidence-based known-red/safety comparison.

Only after this immutable turn may M1d be accepted or another M1 consumer be planned.

## Accepted architecture authority retained

M1c remains immutable accepted at the authoritative `CrossFieldEdgeTransition` consumer with artifact `9043971772`: focused **6/6**, transition counterexamples **3/3**, required-green producer **157/157**, M1b **6/6** + validation **77/77**, M1a **14/14**, T1 **29/29**, and four direct required-green products oracle-clean.

M1d does not reinterpret the nine historical/deferred producer reds from that accepted accounting. Bunny remains known-red `NotProductionReady:completion`; Vase remains bounded safety-only.

## Regression disposition

- `RP-01`: M1d typed source-vertex/transition consumer adoption **compile-complete; immutable runtime pending**.
- `RP-05`: M1d canonical route identity versus packed representation **compile-complete; runtime pending**.
- `RP-07`: accepted M1c quarter-turn transport remains untouched.
- `RP-02 / TA-05`: immutable M1d turn must independently preserve prior authority.
- Historical totals remain **34 events / 14 categories / 20 recurrences**; compile evidence alone creates no new event.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current G4 authority is unchanged: Plane/seam/close-sheets/cylinder strict-valid **3/3**; direct torus remains **0/3** after 192 quads with 241 `LocalSheetMismatch` issues; historical exact torus remains `InvalidHardRailPairing`.

## Standing Bunny/Vase execution rule

For immutable Test + Benchmark turns, Bunny and Vase may use an ephemeral artifact-only GitHub Actions runner. Verify exact build artifact/package/executable content first; never rebuild or edit packaged content; retain selected count/filter/stdout/stderr/rc/time/evidence digests; clean temporary workflow/trigger/helper files before closeout.

## Core references

- `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
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

PR #8 remains open, draft, and unmerged. Every completed turn ends with one new top-level PR #8 conversation comment after all branch-file and PR-body writes.