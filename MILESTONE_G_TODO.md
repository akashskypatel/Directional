# Milestone G Production Readiness TODO

Last updated: 2026-08-10 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d architecture slices are immutable accepted. **M1e segment route transport is Code + Build complete and awaits immutable runtime.** Architecture migration remains separate from G4 product acceptance.

## M1e segment route transport — Code + Build complete

Selected consumer:
`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

| Evidence | Value |
|---|---|
| Final implementation | `bb9cb63a36b64fe2f7c462ad864492c8352b65e8` |
| Build/event | `106e408065e5bda1eb680bc54aef007a1a2d68d6` |
| Build run/job | `31345475101 / 93326482946` |
| Result artifact / SHA-256 | `9047295489` / `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f` |
| Log artifact / SHA-256 | `9047295703` / `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52` |
| Recursive manifest | **61/61**, `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e` |
| Package | 62 regular files; 7 executables; 2 static libs; 27 fixtures |
| Compile | **120/120**, Release/static/Ninja |
| Build wall / peak RSS | **8:08.51 / 1,848,636 KiB** |
| Runtime | **false** |

M1e compiles the bounded authority migration from raw cumulative signed matching to checked source-vertex/interior-transition step identity, canonical `SourceEdgeTopologyKey`, typed `QuarterTurn`/zero-shift `GridAutomorphism`, `TransitionStep`, `CanonicalRoute`, `oriented_steps()` recovery of observed direction, and typed algebraic route composition. Existing raw matching/provenance remains compatibility output/storage only.

No periodic-holonomy loop, `FieldChartId`, public route/segment schema, topology-region planning, shared rail schedule, quotient/certificate ownership, validator, fixture, fallback/recovery expansion, optimization, or G4 behavior was migrated.

Exactly six M1e semantic/counterexample contracts are statically packaged. No generated binary was executed.

Report: `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`.

### Compile correction

The first implementation `9edbef1fe34d60d2a507160aa4a27883cea36903` failed compilation before runtime because it used `Eigen::Vector2i` instead of authority `LatticeTranslation` and qualified the hidden-friend grid `compose`. The final correction `bb9cb63...` uses `LatticeTranslation{0,0}`, `GridAutomorphism::identity()`, and unqualified ADL `compose`.

Two v2 temporary workflow events (`31345414148`, `31345419666`) were invalid YAML and produced no jobs. They are infrastructure-only and not runtime regression evidence.

## Authoritative next turn

Run **M1e Segment Route Transport Consumer — immutable Test + Benchmark only** under `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only artifacts `9047295489 / 9047295703`; no rebuild, relink, regeneration, source/test/fixture edit, substitution, or repair is permitted.

Acceptance requires exact artifact/source/executable preflight/postflight with **61/61** checksums; producer discovery **184**; M1e **6/6**; ordered vertex-fan witnesses **2/2**; M1d **6/6 + 3/3**; M1c **6/6 + 3/3**; required-green producer **169/169**; nine historical/deferred reds explicitly classified; M1b **6/6 + validation 77/77**; M1a **14/14**; T1 **29/29**; four direct product cases oracle-clean; Bunny/Vase evidence-based known-red/safety comparison; exact postflight.

## Regression disposition

- `RP-01`: M1e typed step domains **compile-complete; immutable runtime pending**.
- `RP-05`: M1e canonical step identity and observed/canonical route orientation **compile-complete; runtime pending**.
- `RP-07`: M1e typed cumulative ordered-route transport **compile-complete; runtime pending**.
- `RP-02 / TA-05`: immutable M1e turn must independently preserve prior authority.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current G4 authority is unchanged: direct torus remains **0/3** after 192 quads with 241 `LocalSheetMismatch` issues; historical exact torus remains `InvalidHardRailPairing`.

## Standing Bunny/Vase and cleanup rules

Bunny/Vase may use an ephemeral artifact-only Actions runner for immutable Test + Benchmark. Verify exact artifact/package/executable content first, mutate no regular content, retain raw evidence, and remove/disable temporary workflows **before** deleting trigger markers.

The mandatory durable `.agents/Directional` cleanup policy remains in `Future_Chat_Session_Handoff.md`: every TB turn begins with stale-evidence cleanup and ends with the new current TB report plus exactly one next Code + Build plan alongside durable documents.

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