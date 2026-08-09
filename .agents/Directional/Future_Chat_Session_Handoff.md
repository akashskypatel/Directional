# Future Chat Session Handoff

## Mandatory next turn

Run **M1c Field-Transition Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1 authority kernel and staged production adoption**;
- M1a authority kernel: **immutable accepted**;
- M1b first production consumer: **immutable accepted**;
- M1c field-transition consumer: **Code + Build compile/package complete; immutable runtime pending**;
- review policy: `never`.

The next turn is non-mutating with respect to product/test/build/fixture content. Consume the exact packaged M1c artifact only. Do not configure, rebuild, relink, regenerate, substitute, edit, or repair source/tests/fixtures.

## Exact M1c immutable build authority

Selected seam:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`, authoritative `fields::CrossFieldEdgeTransition` consumption only.

| Evidence | Value |
|---|---|
| Migration base | `512d9523f13158a9f71b406b6db7137a1db3c504` |
| Implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Build/event | `ebda31859a18005844f81274393211991361cbbb` |
| Build run/job | `31334345368 / 93297618568` |
| Result artifact | `9043971772` |
| Result SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Recursive package manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| Package | 55 regular files including manifest; seven ELF; two static libs; 27 fixtures |
| Code + Build | Release/static/Ninja **120/120**, `PRE_TEST`, `runtimeExecution=false` |
| Build wall / peak RSS | **8:31.95 / 1,836,460 KiB** |
| Retention | through **2026-08-23 UTC** |

Read-only post-build inspection already verified both outer GitHub artifact digests, zero unsafe archive paths, and every **54/54** packaged checksum. No generated Directional binary was executed in M1c Code + Build.

Report:
`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Report.md`.

## M1c implementation truth table to prove

Only the authoritative transition-consumer path changed:

1. source/target and transition first/second faces cross checked `LegacyAuthorityAdapters::source_face(..., faces.rows())` before semantic reciprocity;
2. transition source-edge endpoints cross checked `source_vertex(..., vertices.rows())`;
3. typed endpoints become canonical `SourceEdgeTopologyKey`; raw `uint64_t edge_key` is used only at the legacy lookup representation boundary;
4. semantic matching uses `QuarterTurn::from_integer` and `.inverse()` for reverse traversal;
5. raw signed `BranchTransitionResult.matching` remains legacy-compatible (`matching` forward, `-matching` reverse);
6. effort and the separate `edgeTransitions == nullptr` `edgeMatching`/`edgeEffort` fallback remain unchanged;
7. missing/malformed authoritative transition metadata fails closed and must never fall through to the legacy fallback or geometric inference;
8. public `CrossFieldResult` / `CrossFieldEdgeTransition` layout is unchanged.

Final M1c product/test diff is exactly:

- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

No header/CMake/schema/fixture/validator/product-policy change was required.

## Exact M1c focused contracts

The packaged producer target statically contains exactly six new contracts:

1. `SurfaceCellFieldTransitionAuthorityMigration.ForwardQuarterTurnUsesTypedModuloTransport`;
2. `SurfaceCellFieldTransitionAuthorityMigration.ReverseTraversalUsesExactQuarterTurnInverse`;
3. `SurfaceCellFieldTransitionAuthorityMigration.EquivalentQuarterTurnsNormalizeSemantically`;
4. `SurfaceCellFieldTransitionAuthorityMigration.ReversedSourceEdgeEndpointsPreserveSemanticIdentity`;
5. `SurfaceCellFieldTransitionAuthorityMigration.MalformedAuthoritativeFaceOrEdgeFailsClosed`;
6. `SurfaceCellFieldTransitionAuthorityMigration.LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent`.

Static manifest SHA-256:
`4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`.

The immutable turn must require exact six-member discovery and **6/6** fresh-process semantic success. Zero-selection success is invalid.

## Existing transition counterexamples that must remain visible

Run and require green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

The periodic tamper must retain `PeriodicHolonomyMismatch`.

## Required preservation matrix

The immutable turn must additionally prove:

1. complete relevant producer preservation with exact nonzero selection accounting;
2. M1b six `SurfaceOptimizationRailAuthorityMigration` contracts **6/6** individually;
3. full validation discovery exactly **77** and **77/77**;
4. M1a authority discovery exactly **14** and **14/14**;
5. T1 independent oracle discovery exactly **29** and **29/29**;
6. Plane, MultiFaceSeam, CloseSheets, Cylinder remain green and independent-oracle clean;
7. package postflight preserves both original ZIP hashes and all **54/54** packaged checksums.

M1c focused tests cannot substitute for independent oracle or direct product evidence.

## Accepted M1b comparison authority

M1b remains immutable accepted under:
`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Accepted M1b direct comparison:

| Case | Result |
|---|---|
| Plane | pass, **1.000 s**, independent oracle clean |
| MultiFaceSeam | pass, **1.559 s**, oracle-clean |
| CloseSheets | pass, **12.169 s**, oracle-clean |
| Cylinder | pass, **6.525 s**, oracle-clean |

## Bunny/Vase standing GitHub Actions procedure

The user explicitly authorizes **GitHub Actions artifact-only runtime workflows for Bunny and Vase going forward** to avoid local container/execution-tool timeout issues.

For M1c the temporary runtime workflow, if used, must:

1. download exact artifact `9043971772` from run `31334345368`;
2. verify GitHub artifact digest, `SHA256SUMS`, every 54 package checksums, implementation metadata, and selected producer executable content hash before runtime;
3. never configure, compile, relink, regenerate, substitute, or edit packaged product/test/fixture content;
4. restore executable permission only after content-hash verification if `actions/download-artifact` strips it;
5. run the exact existing Bunny/Vase tests with explicit process guards and retain filter, selected count, stdout/stderr, return code, elapsed time, and evidence-artifact digest;
6. classify the underlying GoogleTest result from logs; workflow success is orchestration success only;
7. remove temporary workflow/trigger/helper files before closeout.

Accepted M1b comparison:

- Bunny: one real test, known-red after ~64 s; independent oracle rejects first, then unchanged fatal `NotProductionReady:completion`, `traceSegments=170831 arrangementCells=0 completedQuads=0`;
- Vase: one real test reached `[ RUN ]`, bounded rc=124 at 60 s; safety evidence only.

Do not relabel Bunny/Vase green to close M1c. A changed failure mode, lost independent-oracle ordering, crash, or unbounded execution is material evidence.

## Regression/architecture disposition

- `RP-01`: M1c checked source-face/source-vertex adoption **compile-complete; immutable runtime pending**.
- `RP-05`: M1c canonical source-edge semantic identity **compile-complete; runtime pending**.
- `RP-07`: M1c exact modulo-four/inverse transport **compile-complete; runtime pending**.
- `RP-02 / TA-05`: following immutable turn must preserve M1b/M1a/T1/direct authority.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** and separate.

Production G4 authority remains unchanged under artifact `9031804178`:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, topology `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

## Core references

- `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`;
- `TODO`;
- `MILESTONE_G_TODO.md`.

## Deferred blockers

- active representative torus `G4-R007`;
- shared hard-rail scheduling `G4-B002`;
- nonzero periodic Z4 product capability `G4-B003`;
- positive multi-isolation witness `G4-B004`;
- historical transition-quotient/completion failures;
- strict-validator timing;
- prescribed sphere, G5/G6, Bunny/Vase production success, fallback/recovery, optimization;
- later M1 consumers, M2–M6 and T2–T6.

At the start of the next turn, fetch fresh PR/head state and verify the branch still contains implementation `e139fca...`. Do not assume this handoff's final documentation head if external commits move the branch.

If any required-green immutable gate regresses, remain at M1c and return to a corrective Code + Build turn. Do not advance to another consumer.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
