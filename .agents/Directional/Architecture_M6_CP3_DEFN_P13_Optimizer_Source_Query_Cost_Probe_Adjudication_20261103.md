# RA-201 — P13-k optimizer source-query cost probe adjudication (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (Review/Definition) — **COMPLETE**. It resumes from the ChatGPT Review's `REVIEW_BLOCKER`, which was procedural: the turn needed scratch execution on CB79, and that Review must stay runtime-free. The [static preflight](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md) located the three sites and set the requirements. This adjudication ran the measurements on the macOS scratch build (Claude, diagnostic only). It changes no product source in the repository.

**Base:** HEAD `2f36c637c`. Its product source equals CB79 `3feb2a4182a5a12c2a9f306272756f8333a44b59` (`git diff --quiet` over `src include tests benchmarks CMakeLists.txt cmake`).

**Supersedes as open work:** the static preflight. Its site list and requirements stand and are met below: validate at the stage boundary, lend only exact-input structures, keep standalone rejection, add non-timing behaviour rows next to any cost row, and make the terminal name its check.

## RA-201.1 Findings

1. **The three sites are one cost class: a per-query re-check or rebuild of an immutable source structure.** Every Vase run below is one census process on the scratch build.

   | State (CB79 base) | Vase wall | Where the time goes | Verdict |
   |---|---|---|---|
   | HEAD | no verdict by 875 s (RA-200); Linux TB73 timed out at 600 s | Rail fill about 3 min, all of it in `matches_source_faces`; then one BVH per `nearest_source_point` call | — |
   | RA-200 probe K (sites 1–2 only) | 1,521 s | About 20 min with one `SourceChartTransitionGraph` per quad (67,829) | `NotProductionReady:completion detail=None` |
   | Iteration 1: probe K plus a lent label support | stopped at 342 s | Still in `consistent_source_scope`; 46 % of samples in `matches_source_faces` | — |
   | **Final (CB80–CB83)** | **246–252 s** (about 200 s to assembly) | Optimizer-stage checks and validation take about 50 s; no per-query structure remains in the samples | `NotProductionReady:completion`, detail `SelfIntersectingFace` (P13-l) |
   | Final minus the `available()` change (mutant M3v) | 269 s | — | same |

   The verdict and completed counts (192,482 trace segments, 26,817 cells, 67,829 quads) are the same before and after. The corrections change cost only.

2. **The binding check sat one call level below where it was first seen.** Lending the label support removed the per-quad graph. The run then spent its time in `source_face_scope`, called once per chart face inside `consistent_source_scope` and `OutputProjectionCache`; each call is O(F) `matches_source_faces`. `SourcePointLabelSupport::available()` repeats the same check on every point query. RA-195 already removed this check from `SourceChartTransitionGraph::available()`. So the class has five instances:

   | Instance | File | Fix |
   |---|---|---|
   | Rail fill: 2 binding checks per (output vertex × rail interval) | `SurfaceOptimizationRailConstraints.cpp` | One check per fill (CB80) |
   | `source_face_scope` per chart face | `SurfaceMeshOptimizer.{h,cpp}` | `bound_source_face_scope` after one check (CB80 adds it, CB82 uses it) |
   | `nearest_source_point`: complete-authority check and BVH per call; `project_vertices` and `quad_reference_surface_point` build a BVH even when a cache is lent | `SurfaceMeshOptimizer.{h,cpp}` | A lent cache built for these constraints answers; it carries its build-time check (CB81) |
   | A label support (and chart graph) per quad in `consistent_source_scope`, `quad_reference_surface_point`, `local_orientation_valid` and the overlay | `SurfaceMeshOptimizer.{h,cpp}` | One support per stage, lent by exact inputs (CB82) |
   | `SourcePointLabelSupport::available()` re-checks the binding per query | `SourceAuthoritativeMeshValidator.h` | Uses its graph's build-time check (CB82) |

3. **The P13-l rejecting check, named.** The terminal comes from the pre-optimization validation of the completed mesh (`RemeshPipeline.cpp` about line 15017: `validate_source_authoritative_final_surface_mesh` on the completed checkpoint, before the optimizer runs). The diagnostics already carry the typed reason: stage `completion/output-validation`, reason `SelfIntersectingFace`, output quad 16034 from cell 510. Only the terminal detail is dropped: the `fail_surface_cells` call passes its default `None` → CB83. Every issue in that report:

   | Check | Vase completed mesh (67,829 quads) |
   |---|---|
   | Topology: boundary cycles, rails, sheets, topology hash, components | **pass** |
   | `FlippedFace`, edge form (both quads traverse a shared edge in the same direction) | **27,966** |
   | `FlippedFace`, face form (quad normal against the source normal) | 7,681 |
   | `SelfIntersectingFace` | 249 per face, 1 global |
   | `GeometricVertexOnUnsplitEdge` (T-junction) | 3 |
   | Quality at the final thresholds | normal P95 179.9°; scaled Jacobian min −1, P5 −1; angle P5 6.4°; non-convex 16,874; boundary valence 244/416 wrong; size ratio P5 0.003, P95 0.20 |
   | Surface distance | within bounds (quad→source P95 2·10⁻⁴, max 0.08; source→output P95 3·10⁻³) |

   The mesh lies on the source and has the source's topology (CB79), but it is not consistently oriented. The first-listed issue, `SelfIntersectingFace`, is a small part of the failure. The orientation inconsistency is most of it.

4. **Residual per-query work (not blocking; extends O20).** `source_face_scope` is still called per vertex in `project_vertices` and in the gradient loops. `MeshValidator::validate_bow_tie_vertices` and `validate_source_authoritative_surface_mesh` have their own costs. Vase now reaches its verdict in about 250 s, and the optimizer stage itself is not yet reached (P13-l rejects before it), so these costs are unmeasured there. They reopen when a census times out in one of them.

## RA-201.2 Probes (macOS, scratch, diagnostic only)

| Probe | What it shows |
|---|---|
| Iteration 1: probe K plus a lent label support | The per-quad graph is gone; `matches_source_faces` per chart face remains (46 % of samples) |
| v2: CB80–CB82 forms | Vase 252 s; terminal unchanged |
| `probe`: census prints `surfaceCellFirstInvalidProducer*` | `completion/output-validation \| SelfIntersectingFace`, quad 16034, cell 510 |
| `probe2`: census prints the validation report and counts issues by code and by edge/face form | Table in item 3 |
| M3v on Vase | 269 s without the `available()` change |
| Stack samples (`sample`, every 30–45 s) | Item 1 table |

## RA-201.3 Rulings

1. **Owner: the surface-optimizer stage's use of the source structures** (rail fill, projection and label queries, final validation). The source authority product and the chart graph are correct. Every check stays, and every failure code and its order are unchanged.
2. **DESIGN Amendment 33:** Amendment 27's rule extends to the optimizer stage and its validation. One check of the source binding per stage; immutable source structures built once per stage and lent by exact inputs.
3. **One CB per site, each followed by its own TB** (the user's independently testable slices):
   - CB80 → TB74;
   - CB81 → TB75;
   - CB82 + CB83 → TB76. CB83 is one argument. Only the census exercises it, and Vase reaches it only after CB82.

   Every CB compiles alone, and its GUARD rows pass on the scratch build at that state (RA-201.12).
4. **GUARD style.** Each site has a behaviour row with no timing in it: an unbound authority assigns nothing; a cache or support built for other inputs is ignored. Each also has a scale row. The scale rows run on a 20,000-face source grid, sized so that the corrected path takes milliseconds and the reverted path takes many seconds. Each timed section is bounded at 2 s; the measured margins are in RA-201.12. Fixture setup (about 2 s per row) is outside the timed section.
5. **P13-l owner → Review DEFN `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`** (Claude, scratch). The rejecting check is known. The owner is not. Leads, not conclusions:
   - `orient_quads_to_source_normals` (`RemeshPipeline.cpp` 10949) flips each quad on its own, by the normal of triangle (0,1,2) against one source face's normal. It ignores lineage (`(void)quadLineage`), so it can flip neighbouring quads apart.
   - Completed patches may carry mixed winding before that pass.

   First measurement: count same-direction interior edges right after assembly and again after the orientation pass, binned by patch. The DEFN also decides whether the pre-optimization gate should apply the final quality thresholds to an un-optimized mesh. DESIGN §4.9 separates guaranteed injectivity from distortion quality.
6. **O20** gains RA-201.1 item 4.

**How the patches are delivered.** Each exact patch is a committed `.diff` file beside this record, not a block inside it. The implementation agent copies the file, checks its SHA-256 and runs `git apply`. Earlier records embedded the diff in markdown and had to warn about single-space context lines that copying could lose; a file keeps its bytes. (`**/*.patch` is git-ignored repository-wide, so the files use `.diff`.)

## RA-201.4 CB80 — `M6-CP3-CB80-P13-RAIL-BINDING-ONCE`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 3feb2a4182a5a12c2a9f306272756f8333a44b59 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff`](Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff), byte for byte. SHA-256 `d4dda97eeea13c4c50ca107fa06bf093b7a173abce9a0bbfb268e8793da265fe`, 281 lines, 11 single-space context lines. Run `git apply --check`, then apply.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SurfaceMeshOptimizer.h` | `15 8` | `b89f830580f49096dfc6256e2b803faae51d566ac57ab83fc40e43055a2b0267` |
  | `src/geometry/SurfaceOptimizationRailConstraints.cpp` | `31 23` | `046bbf5559b57fdec4ea1ea7897bc20418fc1b5bf323d6738f3ee5d1ec836791` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `128 0` | `13d289eb5baa58db4d5e4c40506588ebbc502395f0f9dd5aecf0e6a9d3c55029` |

- **Content:**
  - `bound_source_face_scope(authority, face)` reads a face's row labels; `source_face_scope` checks the binding and then calls it, so its behaviour is unchanged.
  - The rail file's private copy of `source_face_scope` is replaced by `source_bound()`.
  - `fill_surface_optimization_rail_constraints` checks the binding once and calls `provenance_supports_bound_interval_sheet` per pair.
  - The public `provenance_supports_interval_sheet` still checks the binding itself.
- **Tests (gate rows 887–888, `directional_surface_cell_validation_tests`):**
  - `RailFillAssignsNoVertexWithoutBoundSourceAuthority`: an authority with the same labels, built for another face matrix of the same size, assigns no feature vertex.
  - `RailFillChecksSourceBindingOncePerFill`: a 20,000-face grid with 600 intervals and 600 vertices; the fill takes under 2 s and assigns all 600.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, run no binary.
- **Outcomes:** precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-RAIL-BINDING-STOP`; infrastructure → `M6-CP3-CB80A-P13-RAIL-BINDING-ORCH` (one retry).

## RA-201.5 TB74 — `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB80's immutable package.

- **Gate:** [manifest](Architecture_M6_TB74_P13_Rail_Binding_Once_Full_Gate_Case_Manifest.tsv), 888 rows, SHA-256 `bb4e771fd911d9aefdb83c89cf2ac8def41e464bb41f26778a1b3a98adbee4da`. It is TB73's 886 rows byte for byte plus GUARD rows 887–888.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=888 deferred=81`.
  - Pre-registered **888/888**, membership **969**.
- **Census:** `3af1dc0d…`, unchanged. Cylinder PASS; BunnyRandom P13-e unchanged; **Vase ABNORMAL, 600 s timeout (exit 124)**, because the per-quad label support remains until CB82.
- **Outcomes:** mismatch → `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-REV` (Review); infrastructure → `M6-CP3-TB74A-P13-RAIL-BINDING-ONCE-ORCH` (one retry).

## RA-201.6 CB81 — `M6-CP3-CB81-P13-LENT-PROJECTION-CACHE`

Code + Build, compile only.

- **Precheck:** the product paths differ from `3feb2a41…` in exactly CB80's three paths, each at its RA-201.4 result SHA-256.
- **Patch:** [`Architecture_M6_CP3_CB81_P13_Lent_Projection_Cache.diff`](Architecture_M6_CP3_CB81_P13_Lent_Projection_Cache.diff), byte for byte. SHA-256 `ffa4b5548b6bf45f044dac4b46fb2cca51db051b324d2ca7c0116faae99a4e30`, 169 lines, 6 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SurfaceMeshOptimizer.h` | `7 1` | `66ad961a201d0de255bd24f2d17186988529515598381ffd0a31edfcd76e3283` |
  | `src/geometry/SurfaceMeshOptimizer.cpp` | `29 11` | `85cfd35dc2c51f4364a2d4278388e8a0f7a171ae1ab68f246cf5e777ea630800` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `58 0` | `052065d50a3142d12a76f8870d36722b61472c435352948ba23163db70d4ecec` |

- **Content:**
  - `SourceProjectionCache` records `source_optimization_has_complete_authority` once, at construction (`sourceComplete`).
  - `nearest_source_point` uses a lent cache only when it was built for the same constraints object, trusting its recorded check. Otherwise it checks the authority first and then builds its own cache, as before.
  - `project_vertices` and `quad_reference_surface_point` build their fallback cache, and its BVH, only when no fitting cache is lent.
- **Tests (rows 889–890):**
  - `LentProjectionCacheAnswersOnlyForItsOwnConstraints`: a cache built for other constraints is ignored (its query count stays 0, and the answer is the one for these constraints); a fitting cache answers.
  - `LentProjectionCacheBuildsNoSourceBvhPerQuery`: 10,000 queries against a 20,000-face grid take under 2 s.
- **Build / outcomes:** as CB80; `M6-CP3-PLAN-P13-LENT-PROJECTION-CACHE-STOP` / `M6-CP3-CB81A-P13-LENT-PROJECTION-CACHE-ORCH`.

## RA-201.7 TB75 — `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-EXEC`

- **Gate:** [manifest](Architecture_M6_TB75_P13_Lent_Projection_Cache_Full_Gate_Case_Manifest.tsv), 890 rows, SHA-256 `a134d9411bd5885fa85d7405e2a733da7cd4d5899d17a83f6dbcb501d18326c6`. It is TB74's 888 rows plus rows 889–890; `SELF_CHECK_PASS cases=890 deferred=81`. Pre-registered **890/890**, membership **971**.
- **Census:** as TB74 (**Vase ABNORMAL 600 s**).
- **Outcomes:** `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-REV` / `M6-CP3-TB75A-P13-LENT-PROJECTION-CACHE-ORCH`.

## RA-201.8 CB82 — `M6-CP3-CB82-P13-LENT-LABEL-SUPPORT`

- **Precheck:** the product paths differ from `3feb2a41…` in exactly the CB80/CB81 paths, each at its RA-201.6 result SHA-256 (the rail file at its RA-201.4 hash).
- **Patch:** [`Architecture_M6_CP3_CB82_P13_Lent_Label_Support.diff`](Architecture_M6_CP3_CB82_P13_Lent_Label_Support.diff), byte for byte. SHA-256 `b963ea3d4b440fea66b65926478861b7bb6c489166f21b7db41769dc31cde1d2`, 349 lines, 10 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SurfaceMeshOptimizer.h` | `19 5` | `f405ac7159cb84ae0c3ab741e0bdbdedf037448e3927676c6f953496f97fe17b` |
  | `include/directional/validation/SourceAuthoritativeMeshValidator.h` | `3 2` | `036740ec641f6754950ba3d9c574e9b2c2e6fc9ea11560d0bdaf544b1c531b88` |
  | `src/geometry/SurfaceMeshOptimizer.cpp` | `54 13` | `b88a18f8c0a65750447b7a838a80f857f84dc15aa6368a6fa60a537446bc0926` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `122 0` | `6f35103761011bfdf948d5a2a17412f1539b689b55083a03e7e6e5364f07ab3d` |

- **Content:**
  - `consistent_source_scope` and `quad_reference_surface_point` take an optional lent `SourcePointLabelSupport`. They use it only when it borrows exactly the constraints' face matrix, authority and hard-edge set (`SourceChartTransitionGraph::borrows`). Otherwise they build their own; `consistent_source_scope` first checks the binding with the constraints' vertex extent, so standalone rejection is unchanged.
  - Lenders: `validate_final_surface_mesh` (its existing support), `OutputProjectionCache` (its own support, after one binding check), `local_orientation_valid` and the overlay (one support per call). The chart-face loops use `bound_source_face_scope`.
  - `SourcePointLabelSupport::available()` relies on its graph's build-time binding check.
- **Tests (rows 891–893):**
  - `LentLabelSupportIsUsedOnlyWhenItBorrowsTheConstraintSources`: on the hard-rail fixture, a support built without the rail is ignored, and a borrowing one gives the standalone answer.
  - `OutputProjectionLendsOneLabelSupportToEveryQuad`: 1,600 quads on the 20,000-face grid take under 2 s in `OutputProjectionCache`, and again in `local_orientation_valid` with a lent cache.
  - `LabelSupportQueriesDoNotRecheckTheSourceBinding`: 100,000 `supported_faces` queries take under 2 s.
- **Build / outcomes:** as CB80; `M6-CP3-PLAN-P13-LENT-LABEL-SUPPORT-STOP` / `M6-CP3-CB82A-P13-LENT-LABEL-SUPPORT-ORCH`. No TB follows directly; CB83 is next.

## RA-201.9 CB83 — `M6-CP3-CB83-P13-OUTPUT-VALIDATION-TERMINAL-DETAIL`

- **Precheck:** the product paths differ from `3feb2a41…` in exactly the CB80–CB82 paths, each at its latest RA-201 result SHA-256.
- **Patch:** [`Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail.diff`](Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail.diff), byte for byte. SHA-256 `3741697ed34d219579a97081db3763126292a3d103a445e2ceda6cbbf37df682`, 16 lines, 1 single-space context line. Numstat `4 1` `src/pipeline/RemeshPipeline.cpp`; result SHA-256 `ceb0ec7f0b0f6be6ef4e45f512d7b5068958bd131e2517b5136fc4060ce37df2`.
- **Content:** when the completed mesh fails its pre-optimization validation, the terminal detail is the reason the diagnostics already record: the first strict issue, `MissingFeatureRail`, or `AggregateCompletionValidationFailure`. This follows CB75. Nothing else changes.
- **Tests:** none new. The only fixture that reaches this branch is the Vase census; TB76 registers its detail.
- **Build / outcomes:** as CB80; `M6-CP3-PLAN-P13-OUTPUT-VALIDATION-TERMINAL-STOP` / `M6-CP3-CB83A-P13-OUTPUT-VALIDATION-TERMINAL-ORCH`.

## RA-201.10 TB76 — `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC`

- **Gate:** [manifest](Architecture_M6_TB76_P13_Optimizer_Source_Query_Full_Gate_Case_Manifest.tsv), 893 rows, SHA-256 `3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8`. It is TB75's 890 rows plus rows 891–893; `SELF_CHECK_PASS cases=893 deferred=81`. Pre-registered **893/893**, membership **974**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder PASS; BunnyRandom P13-e unchanged.
  - **Vase RED within 600 s: `terminal=NotProductionReady:completion detail=SelfIntersectingFace … completedQuads=67829 completion=`** (macOS scratch: about 250 s).
  - A Vase timeout means CB82 did not take; `detail=None` means CB83 did not take; any other verdict is a mismatch.
- **Outcomes:** mismatch → `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV` (Review); infrastructure → `M6-CP3-TB76A-P13-OPTIMIZER-SOURCE-QUERY-ORCH` (one retry).

## RA-201.11 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB80-P13-RAIL-BINDING-ONCE` | Implementation agent, Linux; compile only |
| 2 | `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-EXEC` | Implementation agent; 888/888, membership 969; Vase ABNORMAL 600 s |
| 3 | `M6-CP3-CB81-P13-LENT-PROJECTION-CACHE` | Implementation agent; compile only |
| 4 | `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-EXEC` | Implementation agent; 890/890, membership 971; Vase ABNORMAL 600 s |
| 5 | `M6-CP3-CB82-P13-LENT-LABEL-SUPPORT` | Implementation agent; compile only |
| 6 | `M6-CP3-CB83-P13-OUTPUT-VALIDATION-TERMINAL-DETAIL` | Implementation agent; compile only |
| 7 | `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC` | Implementation agent; 893/893, membership 974; Vase RED `detail=SelfIntersectingFace` |
| 8 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Probe DEFN on the RA-201 scratch state (Claude) |
| 9 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Probe DEFN |
| 10 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–7 in order, one turn each. Steps 8–9 are Review probe DEFNs. A Review that cannot run a scratch probe does not start them; that is a scheduling fact, not a block (RA-172, RA-198 to RA-201).

## RA-201.12 Scratch verification (final state = CB80–CB83 on CB79)

- **Patch chain:** each `.diff` file is generated from its state. It applies on a clean HEAD worktree after the earlier ones: `git apply --check`, then apply, then a byte comparison with the state, numstat and result hashes. The CB83 result equals the tested state byte for byte.
- **Gate:** TB76 manifest (893 rows), **892/893**. The only red is row 283, the O16 macOS row, red on every earlier state. No other verdict changed.
- **Ledger v5:** 0/81, as on CB79. One row changed: row 365, the Vase census case itself, went from TIMEOUT at 600 s to RED in 274 s, because Vase now reaches its verdict.
- **Census (final producer binary):**
  - Vase RED, `terminal=NotProductionReady:completion detail=SelfIntersectingFace`, completedQuads 67829. It took 246–252 s uncontended, and 428 s beside the gate and ledger.
  - Cylinder PASS (6 s).
  - BunnyRandom unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
- **Intermediate states:** each was built with every gate target and gated alone. The CB80 state passed the TB74 manifest **887/888**, and the CB80+CB81 state passed TB75 **889/890**; row 283 was the only red in both. Each CB therefore stands on its own.
- **GUARD rows, timed section (patched → reverted mutant):**

  | Row | Patched | Mutant | Mutant result |
  |---|---|---|---|
  | 887 `RailFillAssignsNoVertexWithoutBoundSourceAuthority` | pass | M1b (binding never checked) | **fails** (assigns the vertex) |
  | 888 `RailFillChecksSourceBindingOncePerFill` | 0.0035 s | M1 (binding checked per pair) | **31.5 s > 2 s** |
  | 889 `LentProjectionCacheAnswersOnlyForItsOwnConstraints` | pass | M2b (any lent cache trusted); M2 (lent cache never used) | **both fail** |
  | 890 `LentProjectionCacheBuildsNoSourceBvhPerQuery` | 0.0039 s | M2 (authority check and BVH per query) | **20.9 s > 2 s** |
  | 891 `LentLabelSupportIsUsedOnlyWhenItBorrowsTheConstraintSources` | pass | M3b (any lent support trusted) | **fails** |
  | 892 `OutputProjectionLendsOneLabelSupportToEveryQuad` | 0.29 s; 0.15 s | M3 (support per quad) | **53.0 s; 55.9 s** |
  | 893 `LabelSupportQueriesDoNotRecheckTheSourceBinding` | 0.0067 s | M3v (binding check per query) | **10.7 s > 2 s** |

  Each mutant fails only its own rows; all other new rows stay green under it. Fixture setup, about 2 s per scale row, is outside the timed section.

## RA-201.13 Probe scripts (scratch, not committed)

`scratchpad/p13k/`:
- `make_k.py STATE0 OUT STAGES`: stages `s1`–`s4` (CB80–CB83 source), `t1`–`t3` (their tests), and the census prints `probe` and `probe2`.
- `make_patch_k.py A B OUT WT [EARLIER…]`: writes a patch, applies the earlier patches, then checks, applies and hashes it on a clean worktree.
- `make_manifests.py`: TB74–TB76 manifests.
- `mutate_k.py`: mutants M1–M3v.
- `run.sh`, `sampler.sh`, `hot.py`: census runs and stack summaries.

## Review closeout

| Check | Result |
|---|---|
| Scope | Review/Definition only. No product, test, fixture, selector, benchmark or build file changed in the repository; scratch probes only. The four `.diff` files and three manifests are documents for later turns |
| Exact patches | Four files re-hash to the stated SHA-256. They apply as a chain on a clean HEAD worktree, and every result hash matches |
| Manifests | TB73 prefix byte-identical; `SELF_CHECK_PASS` for 888, 890 and 893 cases with ledger v5 (deferred 81), harness P8 |
| Static preflight requirements | Validate at the stage boundary: yes (once per fill, once per stage, or carried by the lent structure). Lend only on exact inputs: yes (`constraints` identity; `borrows`). Standalone rejection kept: yes (public helpers keep their checks; `consistent_source_scope` checks the binding itself). Behaviour rows beside timing rows: yes. Terminal names its check: yes (CB83) |
| Accepted selector prefix re-hashed | n/a: no selector change |
| Standing state | CP2 491/491; stable 66/17/49, debt 1; ledger v5 81 deferred; selector497 and CP3 unpromoted |
| New obligations | P13-l → `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`; O20 extended |
| `review_check.py boundary` / `ledgers` | Run on the history-bearing checkout before push; results in the commit |
| Scratch state left | `wt61`/`bld61` = HEAD + CB80–CB83 (final state, all gate binaries built); scripts in `scratchpad/p13k/` |
