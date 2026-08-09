# Future Chat Session Handoff

## Mandatory next turn

Run **M1d Phase-Front Route Identity Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1 authority kernel and staged production adoption**;
- M1a authority kernel: **immutable accepted**;
- M1b first production consumer: **immutable accepted**;
- M1c field-transition consumer: **immutable accepted**;
- review policy: `never`.

The next turn is mutating **Code + Build only**. It may implement the bounded M1d route-identity consumer and compile/package, but must execute no generated Directional binary, GoogleTest discovery/test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

## Accepted M1c immutable authority

Accepted seam:
`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`, authoritative `CrossFieldEdgeTransition` consumption only.

| Evidence | Value |
|---|---|
| M1c implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| build/event | `ebda31859a18005844f81274393211991361cbbb` |
| build run/job | `31334345368 / 93297618568` |
| result artifact | `9043971772` |
| result SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| log artifact | `9043971968` |
| log SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| recursive manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| M1c focused | exact six, **6/6** individually |
| required transition counterexamples | **3/3** |
| M1b preservation | **6/6**, validation **77/77** |
| M1a preservation | exact 14, **14/14** |
| T1 preservation | exact 29, **29/29** |
| producer required-green segment | **157/157** |

Producer discovery is exactly **172** and fully accounted for:

- 157 required-green aggregate members;
- four direct required-green product cases run separately;
- nine historical/deferred known-red producer tests run individually and still red;
- BunnyRandom known-red;
- Vase bounded safety-only.

Direct required-green comparison from the exact M1c producer executable:

| Case | Result |
|---|---|
| Plane | pass, **1.44 s**, independent-oracle clean |
| MultiFaceSeam | pass, **2.19 s**, oracle-clean |
| CloseSheets | pass, **17.24 s**, oracle-clean |
| Cylinder | pass, **9.70 s**, oracle-clean |

Postflight preserved both outer build ZIP hashes, `SHA256SUMS`, all **54/54** package checksums, and selected executable hashes.

Authoritative report:
`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## M1c accepted semantic boundary

At `resolve_branch_transition`:

- authoritative source/target and transition faces cross checked `SourceFaceId` adapters before reciprocity;
- transition source-edge endpoints cross checked `SourceVertexId` adapters and canonical `SourceEdgeTopologyKey` before raw lookup representation;
- semantic matching uses exact `QuarterTurn::from_integer` and `.inverse()` for reverse traversal;
- raw signed `BranchTransitionResult.matching`, effort, public cross-field storage, and the separate `edgeTransitions == nullptr` fallback remain compatibility representations/behavior;
- malformed or missing authoritative transition metadata fails closed without legacy/geometric fallthrough.

`RP-01`, `RP-05`, and `RP-07` are accepted at this consumer. M1c creates no stable regression event or recurrence.

## Bunny/Vase standing GitHub Actions procedure

Long-running Bunny and Vase may use a temporary artifact-only GitHub Actions workflow.

M1c authoritative comparison run: `31341209985`.

- Bunny job `93315178447`: exact one-test selection, rc=1 after 63.09 s. Independent oracle rejects first with empty/non-quad/component/Euler/origin/terminal issues; afterward the unchanged fatal success assertion reports `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`. Known-red preserved. Evidence artifact `9045884237`, SHA-256 `7b7ea790d386ed82667d4827bf8cb39910a08d9a8d9c075c24ac7ffa61dd7633`. Log artifact `9045884506`, SHA-256 `7a757aa6230f4dfaaf3338c623ddb2488a616facec8950881238f4ad508c6a4f`.
- Vase job `93315178308`: exact one-test selection reached `[ RUN ]`, bounded rc=124 at 60.00 s. Safety evidence only. Evidence artifact `9045884496`, SHA-256 `9f231de99277d19e1ab8a3c7ec7c937ba86df14d675bc77f384c7eb1c3c6c04c`. Log artifact `9045884645`, SHA-256 `f34a034b716903105cd903053910bba8c5af2f7ddba7ebf0f29c281bcd80ee74`.

Standing procedure:

1. download the exact immutable build artifact by run/artifact identity;
2. verify GitHub digest, `SHA256SUMS`, every packaged checksum, implementation metadata, and selected executable content hash before runtime;
3. never configure, compile, relink, regenerate, substitute, or edit packaged product/test/fixture content;
4. restore executable permission only after content-hash verification if required;
5. create only non-regular runtime fixture locators when necessary;
6. run exact existing tests with explicit process guards and retain filter, selected count, stdout/stderr, return code, elapsed time, and evidence digest;
7. workflow success means orchestration success only—classify GoogleTest from logs;
8. delete temporary workflow/trigger/helper files before closeout.

M1c temporary runtime workflow and trigger have been removed.

## M1d exact consumer boundary

Selected seam:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

This consumer validates `SurfaceFrontEdge::sourceRouteEdges` and `sourceRouteTopology` for authoritative **HardRail** and **PeriodicCut** relations.

Default allowed implementation/test paths:

- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

No header or CMake change is expected.

Mandatory implementation rules:

1. preserve existing nonempty/equal-size/interior-incidence checks and relation failure reasons;
2. decode each existing packed route topology key at an explicit compatibility boundary and convert both endpoint values through checked `LegacyAuthorityAdapters::source_vertex(..., sourceVertices.rows())`;
3. construct `SourceEdgeTopologyKey::make` and use the typed key for semantic uniqueness/identity;
4. reserialize typed endpoints to the existing raw packed source-edge key only for the current maps and require representation equality;
5. convert both the supplied route compact index and the index returned by `sourceEdgeIndices` through checked `LegacyAuthorityAdapters::interior_transition(..., sourceEdgeIndices.size())`;
6. compare `InteriorTransitionId`, not raw integers, for semantic transition identity;
7. preserve public `sourceRouteEdges/sourceRouteTopology`, route order, route producers, diagnostics, and storage unchanged;
8. malformed typed metadata remains fail-closed as the existing `InvalidHardRailAuthority` / `InvalidPeriodicCutAuthority` paths.

Do **not** introduce `TransitionStep`/`CanonicalRoute` into this consumer: it does not own per-step transport, and manufacturing identity transport would add false semantics. Their production adoption stays later M1.

## M1d mandatory regression-pattern review

- `RP-01` touched: compact route index is `InteriorTransitionId`; packed endpoints are source vertices. No cross-domain raw integer equality.
- `RP-05` touched: semantic route topology is `SourceEdgeTopologyKey`; packed key and vector index are compatibility representations only.
- `RP-07` preservation: M1c quarter-turn transport is immutable accepted and M1d must not change it.
- `RP-02 / TA-05` preservation: focused M1d route tests cannot replace exact producer/M1c/M1b/M1a/T1/direct evidence.

Required focused contracts are defined in the M1d plan, including valid HardRail and PeriodicCut routes, invalid transition IDs, out-of-domain packed source vertices, topology/transition mismatch, and duplicate semantic topology.

## Product/regression standing state

Historical totals remain **34 events / 14 categories / 20 recurrences**.

`PR8-R034 / G4-R007` remains active under production artifact `9031804178`:

- Plane/seam/close-sheets/cylinder strict-valid **3/3**;
- direct torus **0/3** after 192 completed quads, complete lineage, `4/8/4`, topology `1/0/0`, then 241 `LocalSheetMismatch` issues;
- historical exact torus remains `InvalidHardRailPairing`.

Nine historical/deferred producer tests remain explicit known-red around transition quotient/completion, periodic/torus production, and strict-validator timing. Do not hide, weaken, or convert them to expected success during M1d.

## Core references

- `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Plan.md`;
- `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
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

At the start of the next turn, fetch fresh PR/head state and verify it remains a descendant of M1c implementation `e139fca885538e310dc47ed7ba531517603d92cf`. Do not assume this handoff's documentation head if external commits move the branch.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
