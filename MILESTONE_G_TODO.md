# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority **accepted** → G1 uniform phase-front plane **accepted** → G2 cross-chart / close-sheet isolation **accepted** → G3 periodic closure / holonomy **accepted** → **G4 topology-distinct completion and singularities active** → G5 adaptivity/features → G6 Bunny/Vase production success → G7 hardening.

Production remains known-red on direct torus. T1 independent test authority is accepted. Architecture migration has completed **M1a authority-kernel core** and may proceed to one bounded M1b production-consumer migration.

## M1a authority-kernel — immutable accepted

Exact authority:

| Evidence | Value |
|---|---|
| Entering pre-M1a head | `9f1d3ebd91403252e990f785c3521588197b4fd4` |
| Implementation | `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7` |
| Build/event commit | `a29c1f673ea93e1614751f42a0c1fef94d23e1fe` |
| Workflow run/job | `31327073928 / 93279043100` |
| Result artifact | `9041930767` |
| Result SHA-256 | `1c1325c038ffe26b80e00dbb69fb15de8b0d0a42673d9720f28bcd9de8549ec5` |
| Log artifact | `9041930871` |
| Log SHA-256 | `e99e053ea4503b720dbe9b6c9ed4762a4eedcbf67c15261e8ea4317824c427cb` |
| Recursive manifest | **53/53**, `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6` |
| Code + Build closure | Release/static/Ninja **120/120**, `PRE_TEST`, `runtimeExecution=false` |
| Authority kernel | exact discovery **14**, semantic contracts **14/14** |
| T1 oracle preservation | exact discovery **29**, contracts **29/29** |

Package/source/dependency preflight and postflight were exact. Seven ELF executables, two static libraries, 27 fixtures, source patch/archive/compile DB/source blobs, and static 14/29-name manifests were present. All eight pre-existing T1 binaries/libraries were byte-identical to accepted T1 artifact `9041289209`.

Direct comparison remained unchanged in meaning:

| Case | M1a immutable result |
|---|---|
| Plane | pass, 1.00 s, oracle-clean |
| MultiFaceSeam | pass, 1.53 s, oracle-clean |
| CloseSheets | pass, 12.16 s, oracle-clean |
| Cylinder | pass, 6.82 s, oracle-clean |
| BunnyRandom | known-red `NotProductionReady:completion`, 56.93 s; independent oracle before fatal success assertion |
| Vase | bounded nonreturn at 60.00 s; safety evidence only |

No packaged regular file changed. M1a is accepted for strong domain separation, checked legacy conversion, tagged authority representation, exact Z4/lattice automorphism algebra, and canonical/reversible route semantics. Production adoption remains incremental.

Authoritative report:
`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`.

## Regression disposition

- `RP-01`, `RP-05`, `RP-07`: M1a kernel proof accepted; future production consumers must adopt it without reopening raw-domain conflation.
- `RP-02 / TA-05`: accepted T1 independent-oracle boundary remains preserved.
- M1a creates or resolves no product regression event.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.

Current production authority remains:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`, then **241** `LocalSheetMismatch` issues;
- historical exact-torus remains `InvalidHardRailPairing`.

## Authoritative next turn

**M1b First Production Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Plan.md`

Selected consumer boundary:

`RemeshPipeline -> fill_surface_optimization_rail_constraints -> provenance_supports_interval_sheet`.

M1b may migrate only the validated source-face/source-vertex identity seam in `SurfaceOptimizationRailConstraints` to accepted `SourceFaceId` / `SourceVertexId` types behind named legacy adapters. Public structs, sentinel semantics, barycentric support classification/tolerance, rail assignment, optimizer policy, producers, validators, tracing, arrangement, completion, quotient, fixtures, and product decisions remain unchanged.

The compatibility rollback point is local: legacy sentinel/extent validation → typed consumer logic → explicit conversion back only at matrix/vector indexing. `AuthorityKernel.cpp` may be attached once to `directional_core`; the authority test target must not duplicate it.

Code + Build executes no generated Directional binary. The following turn must consume its immutable artifact and prove focused rail-incidence behavior plus M1a **14/14**, T1 **29/29**, direct four-green preservation, and explicit Bunny/Vase visibility.

## Architecture and test authority

- normative architecture: `.agents/Directional/DESIGN.md`;
- migration roadmap: `.agents/Directional/REORIENTATION_PLAN.md`;
- M1a runtime report: `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`;
- M1b plan: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Plan.md`;
- test policy: `tests/TESTING_STRATEGY.md`;
- permanent regression tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`.

## Deferred blockers

1. active representative torus `G4-R007`;
2. shared hard-rail schedule / exact-torus `InvalidHardRailPairing` (`G4-B002`);
3. nonzero periodic Z4 production capability (`G4-B003`);
4. positive multi-isolation quotient witness (`G4-B004`);
5. historical transition-quotient and completion failures;
6. strict-validator timing;
7. prescribed sphere, G5/G6, Bunny/Vase, fallback/recovery, optimization quality;
8. later M1 consumers, M2–M6 and T2–T6.

PR #8 remains open, draft, and unmerged. The final repository write of every completed turn is one new top-level PR #8 conversation comment after all other branch-file and PR-body updates.
