# Directional — Project Orientation

>This rewrite was expressly requested on 2026-10-16.

**Currency:** 2026-11-05 · [TB81](Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md) **COMPLETE / MATCH** after CB91: Linux artifact-only 899/899 PASS, membership 980, 1,806/1,806 hashes, registered census and seven identical TB80 Linux digests. **O32a Review COMPLETE:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` localized source-row seed suppression, proved actual Vase has one fan per vertex, and froze [CB92](Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md) as the next compile-only Code + Build turn (not started; RA-206.7 / RA-205.4). CP2 491/491 accepted; 66/17/49, debt1; selector497/CP3 unpromoted. O30b/O31/O32/O33/P13-l/e remain open.
- **Before it:** P13-m, fixed by [RA-202](Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md). The fix is Amendment 34 and exact CB85–CB88, removing three memory-bound census-path scans plus two Amendment 33 sites.
- **The block.** The ChatGPT Review saw a conflict between "runtime-free" and a probe re-run. The fault is RA-202.9's route: it named no track and asked one platform to explain a split between two. Review scratch probes are a duty (RA-166.6 F6, RA-188.1), Linux runtime is a TB, and no policy changes.
- **TB78** (CB85–CB88) matches on gate 899/899 and on every census line except the count. Vase reaches RED `SelfIntersectingFace` in 268.93 s on Linux, so P13-m's Linux objective is met.
- **The count is O30.** Vase completes 67,784 quads on Linux and 67,829 on macOS. RA-202.9 had pinned the macOS-only value. Upstream topology agrees on both platforms, and CB85–CB88 cannot round or reorder.

**Next:**
- `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST` is complete: exact test-only patch, [compile run 41932156223](https://github.com/akashskypatel/Directional/actions/runs/41932156223) eight targets PASS, artifact `13370954424` (28/28 hashes), GMP/GMPXX, runtime not executed; [CB89 record](Architecture_M6_CP3_CB89_P13_Census_Platform_Digest_Code_Build_Record_20261104.md).
- **TB79 complete:** [gate 41938188019](https://github.com/akashskypatel/Directional/actions/runs/41938188019) **899/899 PASS**, membership 980; census MATCH; seven Linux digests in the [report](Architecture_M6_CP3_TB79_P13_Platform_Digest_Full_Gate_Execution_Report_20261105.md).
- **RA-204 (O30):**
  - **Noise carriers:** the atlas digest hashes exact `effort` bits, and five later hashes embed it, so they change with any last-bit field change.
  - **The field is not the cause:** five distinct Vase fields give the same macOS output.
  - **The cause:** `SurfaceArrangement.cpp:6762` assigns cell ids in a non-injective key order. With randomized `std::sort` ties, one build gives Vase 67,753 to 67,827 quads.
  - **The fix:** CB90 adds a halfedge tie-break. After it, Vase gives 67,746 under every order, and the local gate is 898/899 (only O16).
- **RA-205:** RA-204's mechanism and CB90 stand. Completed counts that change with the cell schedule violate DESIGN §10.1. A Vase source-face row permutation changes seeds (1,456 → 1,461), traces, strands and quads (67,746 → 67,771–67,784). That is O32.
- **CB91 and TB81:** [CB91 record](Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Code_Build_Record_20261105.md) on source `96ee281a…`; [TB81](Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md) 899/899 and seven TB80 digest lines identical. Predecessor TB80 remains a reviewed historical 898/899 timing-control RED; O32a is next, not another TB81 replay.
- Review track (Claude, scratch build):
  - `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a, next);
  - `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l, after O32a; opens with the RA-204.9 O30 decision after TB80);
  - `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e);
  - `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (O31, after P13-l).
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing` (experimental, PR #8).
**Purpose:** Help a fresh contributor understand the product, architecture, fixtures, project records, cadence, current status and outlook **in minutes**—without reading a turn-by-turn journal.

**Start here →** this page → [ROADMAP.md](ROADMAP.md) (milestones) → [DESIGN.md](DESIGN.md) §§2, 5, 14 (normative architecture) → [Future_Chat_Session_Handoff.md](Future_Chat_Session_Handoff.md) (exact current authority/next turn). Read the relevant frozen definitions and policies before touching implementation.

## 1. What the project is

Directional is a C++ directional-field library with a Python interface ([README](../../README.md)). This branch develops a **direct surface-cell quadrangulation backend**: given a source triangle mesh, tangent cross field, source features and target size, produce a deterministic, source-attached, manifold **pure-quad mesh** with independently verifiable guarantees.

The chosen architecture is **Pipeline B**: field-aligned combinatorial tracing **without global coordinate integration**. Its central ideas are:

- **Single-writer authority:** one producer owns each semantic fact; downstream stages consume immutable, typed products and never repair earlier results.
- **Exact source and topology:** field transport, incidence, region ownership and quotient identity are certified—not inferred from position, container order, a hash or an epsilon.
- **Global-before-local conformity:** choose shared-rail counts/breakpoints once, before independently constructing regional quads.
- **Typed outcomes and real evidence:** fail with an owning reason; prove the intended stage was reached using independent oracles, positive cases, mutations and invariance tests.
- **Verified disposition:** `D0 Certified` through `D4 DiagnosticOnly` describe the *eventual* independently assigned guarantees. M7 has not yet implemented the full ladder.

The objective is **production-ready Pipeline B at M8-CP3**, not merely passing internal contract tests. An optional coordinate-integration **Pipeline A** is documented but unscheduled.

## 2. Pipeline at a glance

| Stage | Owns |
|---|---|
| **Conditioning → A0** | Certified raw→conditioned correspondence; `SourceAuthoritySnapshot` with exact source support, barriers, components, sheets and typed identities. |
| **A1** | `FieldTransportAtlas`: field frames, transport, singularities and holonomy. |
| **A2a → A2a′ → A2b** | `FieldAlignedCurveNetwork` traces; `SurfaceCutGraph` cellularity; `GlobalTopologyPlan` regions with disc proofs. |
| **A3 → A4** | One `GlobalConformityPlan` for shared rails; conforming `RegionCellComplex` products per region. |
| **A5 → A6 → A7** | Explicit corner/side occurrences; only certified quotient merges; source-attached vertex geometry. |
| **A8 → A9** | Independent verification; eventual M7 verifier-assigned disposition; derived diagnostics and export. |

Each arrow denotes a checked, immutable producer-to-consumer boundary. Details and stop conditions belong to [DESIGN.md](DESIGN.md#5-normative-pipeline--pipeline-b), not this map.

## 3. Where we are

**M0–M5 are complete/closed; M6 is active at CP3.** Closure means the checkpoint's frozen criteria passed, **not** that representative output is production-ready.

| Milestone | Achievement / status |
|---|---|
| **M0–M2 — complete** | Preserved baseline; M1 typed single-authority cutover (**234/234**); M2 closed stage products (**275/275**). |
| **M3 — closed** | Field-aligned tracing, typed network events, cellular cut graph and disc-region authority; required-green **365/365**. |
| **M4 — closed** | Exact global rail schedules, production cutover, conditioning and scale contracts; **430/430**. |
| **M5 — closed** | Canonical periodic/quotient identities, certificates and direct producer evidence; **449/449**. |
| **M6-CP1 — closed** | Occurrence, quotient and embedding separation; **479/479** (mechanism-only). |
| **M6-CP2 — closed** | Independent `SurfaceProductVerifier`; accepted cumulative **491/491**. |
| **M6-CP3 — active** | [TB81](Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md) **899/899 MATCH** on CB91 immutable Linux artifact; membership 980, 81 deferred; expected census Cylinder PASS/BunnyRandom P13-e RED/Vase completion RED; seven digests preserved. Current O32a Review located seed first-owner and prepared CB92 plan (not started; Review closeout pending); CP2 491/491, stable 66/17/49, debt1, selector497/CP3 not promoted. |
| **M7–M8 — planned** | Verifier-assigned disposition/degradation, then production hardening. |

**Prior Review authority:** [RA-187](Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md) (GUI layers; full-gate TB rule), [RA-186](Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md) (CLI sidecar; DR4), [RA-185](Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md) (DIAG-RETAIN display; DR2 → M8-CP2), [RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md) (DIAG-RETAIN), [RA-183](Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md) (O2 gate; O2b, O16), [RA-181](Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md) (O15 discharged; O15c) and [RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md) (RP-01 closed; local-mode rules). Implementers get only exact patches and manifests.

**Test authority:** Local macOS: [TB60](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md) **862/863** on CB61 (membership 945), a pre-registered outcome. Linux: TB62 **863/863** independently verified on ten targets (run 41205693716); CLI/GUI GMP compilation/linkage verified; on-screen GUI not tested. Not D0 production, CP3 closure or selector497 promotion.

Stable accounting remains **66 events / 17 categories / 49 recurrences** with **one** produced-witness debt. Accepted M6 CP2 is **491/491**; CP3's 497 identities are frozen, not accepted. See the [handoff](Future_Chat_Session_Handoff.md), [RA-124 Review](Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md) and [regression tracker](Regression_Root_Cause_Tracker.md).

## 4. Fixtures and witnesses

**A3 exactness and the API display witness:** A3 branch topology (face gauge, barycentric derivatives, port order) is exact on the stored doubles (RA-180/RA-181); FMA and FMA-free builds agree byte for byte. Row 935 (`apicensus:19`) is gated with a +½-singularity vertex stop (RA-182). Exact directions widen A4 trace parameters (O15c; for example sphere_prescribed 1,531 of 4,096 bits, fail-closed), and P13 measures them.

The **ten-case representative direct matrix** is defined by [tests/TESTING_STRATEGY.md §4](../../tests/TESTING_STRATEGY.md#4-mandatory-committed-direct-matrix), using [benchmarks/fixtures/milestone-g/](../../benchmarks/fixtures/milestone-g/) and the [fixture matrix manifest](../../benchmarks/fixtures/milestone_g_manifest.json).

| Representative fixture | Intended coverage |
|---|---|
| `plane`, `cylinder` | Basic open/bounded surfaces and boundary topology. |
| `multi_face_seam` | Cross-face seam and field-transport behavior. |
| `close_sheets` | Near-coincident but distinct source sheets. |
| `torus` | Closed, periodic and noncontractible topology. |
| `thin_bent_tube` | Curvature, thinness and approximation stress. |
| `sphere_prescribed` | Prescribed field, singularities and closed-surface tracing. |
| `mechanical_feature` | Hard-feature and trace/rail preservation. |
| `bunny_1k_random` (Bunny) | Representative mesh with generated smooth field. |
| `vase` | Representative mesh with generated smooth field. |

**Other focused witness:** `genus_two` tests higher-genus behavior but is **not an eleventh case** in the mandatory ten-case direct matrix. Synthetic test-local witnesses prove narrow contracts; they cannot substitute for pipeline-produced representative evidence.

Fixture generation, provenance, licenses and checksums are recorded in [generate_milestone_g_fixtures.py](../../benchmarks/fixtures/generate_milestone_g_fixtures.py) and [asset-manifest.json](../../benchmarks/fixtures/milestone-g/asset-manifest.json). The matrix also contains legacy-backend comparisons; **strict direct** testing selects `SurfaceCells`, `SurfaceCellFallbackPolicy::Fail`, with source-grid recovery disabled. **A present fixture or focused green gate does not establish D0 acceptance across the full matrix.**

## 5. Document layout — choose by question

| Need | Read |
|---|---|
| Product/algorithm/contract | [DESIGN.md](DESIGN.md) (normative); [README.md](../../README.md) for build/public API. |
| Achievements and future milestone/checkpoint scope | [ROADMAP.md](ROADMAP.md); [M1](M1_Closure_Record.md), [M2](M2_Closure_Record.md), [M3](M3_Closure_Record.md), [M4](M4_Closure_Record.md), [M5](M5_Closure_Record.md) milestone closure records for accepted evidence and preserved historical definitions. |
| Current work, evidence and authorization | [Future_Chat_Session_Handoff.md](Future_Chat_Session_Handoff.md); [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md) and current review/turn plan. Root [STATUS](../../STATUS) is only a lifecycle beacon. |
| Tasks, blocked issues, regression classification | Root [TODO.md](../../TODO.md), [Regression_Root_Cause_Tracker.md](Regression_Root_Cause_Tracker.md). |
| Change history and reusable lessons | [CHANGELOG.md](../../CHANGELOG.md), [LESSONS.md](LESSONS.md). |
| Tests and execution rules | [TESTING_STRATEGY.md](../../tests/TESTING_STRATEGY.md), [REVIEW_TURN_POLICY.md](REVIEW_TURN_POLICY.md), [GMP_COMPILE_POLICY.md](GMP_COMPILE_POLICY.md), [GitHub_Workflow_Policy.md](GitHub_Workflow_Policy.md) (ChatGPT Web), [RETENTION_POLICY.md](RETENTION_POLICY.md), [CLEAN_UP_POLICY.md](CLEAN_UP_POLICY.md). |

**Repository map:** `include/directional/` contracts/types; `src/geometry/` geometry and topology; `src/pipeline/` producer wiring; `tests/` tests and independent oracles; `benchmarks/fixtures/` datasets; `.agents/Directional/` architecture/policies/status/evidence; `.github/workflows/` remote execution.

## 6. Development and evidence cadence

| Turn | Responsibility and boundary |
|---|---|
| **DEFN / Plan** | Freeze scoped semantics, admissible witnesses, acceptance and owner; **no** compile/runtime. |
| **CB — Code + Build** | Implement authorized changes and compile/package exact source; mandatory **GMP and GMPXX** linkage. Compile success is not runtime acceptance. |
| **TB — Test + Benchmark** | Fresh tests against immutable package with exact selector; **no** rebuild, repair, semantic mutation or invented discovery. Publish PASS **and RED** evidence. |
| **REV — independent Review** | Re-open primary evidence, re-derive decisive facts, test non-vacuity, accept/reject promotion and assign unresolved obligations. Same agent is permitted; independence is of **evidence**, not personnel. |

The separation is deliberate: accepted selector continuity and frozen invariants are not negotiable fixes for a RED; diagnostics are not acceptance; representative production claims require production-path witnesses. See the [review policy](REVIEW_TURN_POLICY.md), [testing strategy](../../tests/TESTING_STRATEGY.md) and [workflow policy](GitHub_Workflow_Policy.md) for actual requirements, repository operation, artifact transport and mailbox behavior.

## 7. Open problems — priority, not a task ledger

**Immediate:**
- CB90 and TB80 are complete (898/899; row 899 RED).
  - RA-206: the independent validator re-checks the full source binding once per output vertex (`SourceAuthoritativeMeshValidator.cpp:1186`), so row 899's validation is O(F×Q). Its 2 s bound came from a macOS run, and Linux runs this section 3.5× slower.
  - **Completed:** CB91 hoisted the binding check and TB81 verified the count assertion, 899/899 gate and seven TB80 digest lines. Next O32a Review. [TB81 report](Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md).
- **O33, per-quad chart-face cost (RA-206.5):** final validation and the optimizer materialize or scan the whole chart face list per quad or sample, at five sites. That is about 0.56 ms per quad at F = 28,800 after CB91. Review DEFN `M6-CP3-DEFN-P13-CHART-FACE-PER-QUAD-COST`, before Vase reaches optimization.
- On the Review track, in parallel: the P13-l completed-mesh orientation DEFN (Vase, post-CB90; also time O27) and the P13-e BunnyRandom DEFN. O31 follows P13-l.
- **O30, Vase** ([RA-204](Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md)):
  - **O30a.** Arrangement cell ids follow `std::sort`'s unspecified order for equal `cell_cycle_key`s. There are 10,891 tied pairs among 26,817 cells. Linux (libstdc++) gives 67,784 and macOS (libc++) 67,829; randomized ties on one build give 67,753 to 67,827.
    - Exact fix CB90 (halfedge tie-break) gives 67,746 deterministically.
    - TB80's CloseSheets arrangement (`5612032b…`, equal embedding on both platforms) is the cross-platform falsifier.
  - **O30b.** Linux's Vase embedding differs (`f2fc0cca…` against `909330af…`). Sort ties, FMA and ±1-ULP field noise are excluded. Open: libm, the x86 `long double` grid key, or a single 1e-9 hash flip. TB80's Vase count decides (RA-204.9).
- **O32, source-row permutation (DESIGN §10.1; M3/M6 exit; CP3-exit condition):** with mesh and field unchanged and only face rows reordered, Vase gives:
  - seeds 1,456 / 1,461;
  - trace segments 192,482 / 192,770–193,624;
  - strands 30,989 / 30,998–31,008;
  - quads 67,746 / 67,771–67,784.

  Counts through `global-conformity-baseline`, the arrangement cells and the verdict are invariant.
  - Owners, upstream first: a, `generate_deterministic_surface_seeds`; b, tracing; c, strand selection; d, the canonical cell key (CB90 is interim); e, completion ownership repair (patch-id tie, budget).
  - Refuted lead: the seed candidate face-row tie.
  - **O32a WIP 2026-11-05:** actual corrected scratch producer yields 1,416 identical semantic seeds under base + 3 permutations; typed hard-barrier vertex-fan control passes; full Vase still fails closed with 189,462 traces/30,989 strands/26,817 arrangement cells in all runs but 67,750/67,782/67,766/67,778 completed-quads before rejection. O32b/c need semantic digest probes; O32e completion remains order-sensitive. Earlier one-sample-per-rail two-ID assertion is invalid as strict interval authority; corrected paired-endpoint rail test proves both distinct typed source-edge intervals survive, with missing-edge and duplicate-ID tamper rejection (remote run 42034591362). Independent Vase OFF fan audit proves 1,274/1,274 vertices have exactly one incident topological fan (no explicit hard-feature edges). The synthetic split-fan seed-count PASS proves typed fan-graph invariance, **not** fan-scoped relief authorization. Revised bounded [CB92 plan](Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md) admits only a uniquely authorized fan; unscoped multi-fan requests must fail closed with a truthful typed outcome, never duplicate, guess or crash. O32a Review boundary checked PASS, CB92 next and not started. [WIP evidence](Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md).
  - [RA-205](Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md).
- **O31, relief noise:** with bit-identical input, relief branches differ by build (CloseSheets 40/38/40, Cylinder 44/44/48). Exact critical-point comparisons on a contractible weighted sum decide near-constant relief by rounding. Completed topology is unaffected today. Review after P13-l.
- **P13-f, Vase:** one source-chart graph per mesh (CB71) and per completion pass (CB72), lent only to callees whose inputs it borrows exactly (Amendment 27). macOS probe: Vase reaches a typed RED at `completion` in 138 s. [RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md).
- **P13-g, Vase:** patch 1200 (bounded-combinatorial, variant 15, bow-tie) is a simple concave octagon whose only embedded quadrangulations are fans that the fixed split never reaches. The validator projects each quad on its own plane and accepts folds. Fix: Amendment 28 (source-orientation predicate, exhaustive forward search, typed `NoEmbeddedQuadrangulation`, typed terminal detail), exact CB73/CB74/CB75 → TB69 ([RA-196](Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md)).
- **P13-h, Vase:** the closed-form grid reads corners by index from `boundaryVertices[0]`, but the descriptor starts the boundary at the smallest halfedge id, often mid-side. 220 strips fail as twisted ladders (patch 4 first) and 2,055 more are accepted twisted. Fix: Amendment 29, the descriptor rotates to side 0 (exact CB76 → TB70). **P13-h2:** 4 needle 2D grids still fail after CB76, and no interpolant embeds them all. **P13-i:** 5 rail-grazing lenses (two sides, tips 0.2°–27°), correctly rejected `side-count-unsupported`. Both → `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` ([RA-197](Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md)).
- **P13-h2, Vase:** the closed-form dispatch never offers a folded grid to the Amendment 28 pattern search, which embeds all 4 needles. Fix: Amendment 30, scoped to grids with generated vertices (exact CB77 → TB71). **P13-i:** the lenses are optional rim support traces; FlowRep selection cannot remove any optional trace (same-face coverage, exact junction degrees), and removing the 5 named traces exposes 3 more ([RA-198](Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md)). RA-199: all 8 are unmet support chords (10 on Vase); selection cannot see meeting because seed traces never end on another trace. Fix: Amendment 31 (exact CB78 → TB72). Coverage across faces and the degree rule → O25 (quality).
- **P13-j, Vase:** with CB78, assembly rejects at node 5355 (three two-quad fans). RA-200: the stitcher's typed certificates match on both sides of every split node; `derive_patch_descriptor` keys a corner by the source scope of the halfedge leaving it, so 23,221 of 66,783 Vase nodes get two keys and the HEAD assembly has Euler −19,442. Fix: Amendment 32, a node key over all occurrences (exact CB79 → TB73). Row 97 passed on a two-component assembly → O26.
- **P13-k, Vase:** with CB79, Vase assembles (Euler 1, one boundary loop) and then spends its time rebuilding immutable source structures per query: `source_face_scope` revalidates the authority over all faces per (vertex × rail interval), `nearest_source_point` builds a source BVH per call, and final validation builds a chart graph per quad (RA-200.1 item 7, RA-200.2a). Same class as Amendment 27 / O20 RA-201 measured five instances (the binding check also ran per chart face and per label-support query) → Amendment 33, exact CB80–CB83.
- **P13-l, Vase:** with CB80–CB83 (scratch), the completed mesh fails its pre-optimization validation. Topology passes, but 27,966 interior edges are traversed the same way by both quads, 7,681 quads oppose the source normal, 250 self-intersect and 3 are T-junctions. Leads: the per-quad `orient_quads_to_source_normals`, or mixed patch winding → Review DEFN `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (RA-201.3 item 5).
- **P13-m, Vase (Linux timeout):** RA-202. Three passes rescanned a whole mesh-sized collection per element, outside the optimizer stage RA-201 fixed:
  - the arrangement's geometric T-junction scan (57,636 nodes × 168,902 halfedges);
  - FlowRep selection, which recounted the endpoint degrees of the whole network for each of 4,047 transactions;
  - `MeshValidator`'s bow-tie check (68,038 vertices × all edges).

  They are memory-bound, which explains why only Vase is slower on Linux. Two Amendment 33 sites remained in `validate_final_surface_mesh`. Fix: Amendment 34, exact CB85–CB88 → TB77/TB78, cross-checked exact. **Verified on Linux by TB78:** Vase RED in 268.93 s, against ABNORMAL at 600 s in TB76/TB77 (RA-203). Carried: O27 (the O(Q²) face-intersection scan, which runs in full once P13-l passes), O28 (nine optimizer-stage `source_face_scope` sites), O29 (`source_vertex_extent` per edge key; tracing ≈60 s).
- **P13-e, BunnyRandom:** index −1 vertex 49 still has 4/5 expected port incidences; separate DEFN → CB → TB, do not combine.
- **P13-d/O18:** CB69 typed arrangement termination and CB70 wedge guards proved in TB67; post-CB70 Vase completion output remains unproved.
- **P13-a/P13-b:** Cylinder PASS and dyadic A2a width issue discharged; earlier evidence retained.

macOS O16 stays separate.

| Priority | Missing outcome | Owner |
|---|---|---|
| **1** | P13 direct matrix 6/6 unresolved. TB81 gate 899/899 MATCH, membership 980; no CP3 promotion. P13-m is fixed on Linux (TB78). The Vase completion count splits by platform (O30, RA-203); its cause is arrangement cell order (O30a, RA-204; CB90). Vase next: P13-l completed-mesh orientation. BunnyRandom P13-e remains an independent Review; O6/O9 only where reached, O19 genus >0 nonblocking; O27–O29 carried. | M6-CP3; next `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` Review; P13-l remains after O32a |
| **2** | Restore accepted-prefix execution and the direct-production positive and tamper paths. Fixture debt follows TB19-REV: 242 → 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R test assumptions. Preserve the accepted 491/491 and the frozen 497 identities. | M6-CP3; [tracker](Regression_Root_Cause_Tracker.md) |
| **3** | Discharge the final **`G4-B002`** closed-complex candidate-extraction witness on real produced authority. | M6-CP3 exit |
| **4** | Implement verified D0–D4 degradation/disposition and representative production quality/resource acceptance. | M7 → M8; [roadmap](ROADMAP.md) |

## 8. Recurring defect patterns

- **A per-query check that moves down a level (P13-k):** lending the label support removed the per-quad chart graph, but the same O(F) source binding check then ran once per chart face and once per label query. Re-profile after each cost fix, and remove the check at every call depth: check once per stage, then lend structures that carry their build-time check (RA-201).
- **A whole-collection rescan per element (P13-m):** a check about one node, vertex or transaction walked the whole halfedge list, edge map or active network. The cost hid outside the stage being fixed, and it was memory-bound, so it hit one platform hardest. Profile the whole run, index by the filter key, and check a transaction by its net change (Amendment 34, RA-202).

- **A key built from one consumer's view of a shared object (P13-j):** the completed-patch corner key was the arrangement node seen through the halfedge leaving it in one cell, so the cells around one node published different keys. A validator caught it only where three cracks met; 23,221 other split nodes passed, and a completion test passed on a two-component assembly. Key a shared object by its own identity, assert the assembled topology, and count how widespread a defect is before studying its first witness (RA-200).

- **A selection stage that selects nothing (P13-i):** two conservative predicates (same-face coverage and exact degrees at every junction) made every optional flowline unremovable, so the unsimplified candidate network reached the arrangement as slivers and lenses. Count a selector's accepted removals before routing a sliver to the tracer or the arrangement (RA-198). Then check which relation its guards can see: Vase's lenses are traces that meet nothing, which neither a node-degree rule nor a distance bound can express, because no trace ends on another (RA-199).
- **An index contract between producer and consumer, broken silently (P13-h):** the descriptor started each patch boundary at its smallest halfedge id, while the closed-form grid read corners by index from position 0. 1×1 cells, which no rotation can change, never failed; that was the tell. When a rotation-invariant subclass is always clean, check the ordering contract before the geometry (RA-197).
- **A validator trusted as the oracle can be blind to the defect (P13-g):** the completion embedding check projected each quad onto its own plane, so it accepted folds, and the stage reported only its first failure in semantic order. Check a validator against the source (here the source normal) and count every failure of the pass before naming the owner (RA-196).
- **Immutable authority reconstructed inside a hot validation loop (P13-f):** source-chart graph constructors perform source-wide checks and topological construction; calling them per vertex or per completed patch transforms a shared proof into O((P+V)F) repeated work. Borrow one source-bound immutable graph at an explicit lifetime boundary without weakening authority predicates; do not mistake a 600-second timeout for a completed terminal failure. The binding proof is that the graph borrows exactly the callee's inputs (Amendment 27), not a per-use `matches_source_faces`. Profile a cost defect, and remove it in a probe, before writing the plan (RA-195).

- **Rejection location is not producer identity:** side repair rejected an arrangement that had already failed. Read the producer's own published audit first (`SurfaceArrangementDiagnostics::incidenceFailure`), then probe incidence at each boundary before attributing or repairing (RA-193, 2026-11-01).
- **Identity keys that carry a witness's chart split shared entities:** a wedge, fan or edge key must use the canonical `SourceEntityIdentity`, not `ResolvedSourceEntity`'s per-face chart; and an angle measured from a canonical edge direction is counter-clockwise on only one of its two faces (RA-193).

- **Simple-edge identity loses a slit:** a vertex-indexed face array cannot hold two edges with the same endpoints, so an interior barrier edge with two interior tips stays glued. That is the only configuration that does (RA-192.1 D2). A1 applies it in the cycle basis instead of building a new incidence product, because transport adjacency is already keyed by source edge (RA-191, RA-192).

- **Exact local arithmetic versus unbounded carried rational width:** a finite bit cap cannot bound growth with face count. Amendment 24 rounds each interior exit inside the one producer that every consumer replays, so the trace is its published geometry (RA-190). A representation change made outside that producer would split one trace into two geometries.

- **Platform split:** a result that differs between builds is a determinism defect. Compute the exact answer before classifying, and change per-file flags only through the build system (RA-176, RA-179).
  - A count seen on one platform is not a prediction for another: RA-202.9 pinned macOS's 67,829 and Linux gave 67,784 (O30). A cross-platform registration pins typed verdicts, topological counts and values the executing platform has already produced. Anything else is recorded, not pinned.
  - To localize a split, print bit-exact input digests and per-stage hashes on both platforms rather than reasoning from one (RA-203).
  - **Noise carriers.** A stage hash that includes exact double bits, or an upstream digest, changes with any last-bit noise. The atlas, network, cut graph, topology plan, conformity baseline and tracing hashes are noise carriers. Localize at the first differing stage that is **not** one (RA-204.2).
  - **Wall-clock guards.** A gated time bound is a cross-platform measurement. Set it from the Linux runner's ratio for that code, or better, count the invariant the test claims (`source_binding_check_count`), and keep time only as a coarse backstop (RA-206.6).
  - **Representation order.** Cross-library agreement is not determinism. DESIGN §10.1 also requires source-face row, output row and scheduling permutations to preserve the semantic output. A tie-break on row-derived ids (CB90) fixes the first and not the second. Run a row permutation before calling an order-dependent result deterministic (RA-205).
  - **Unspecified order.** Different standard libraries break `std::sort`, heap and hash-table ties differently. Run the census once under libc++ `-D_LIBCPP_DEBUG_RANDOMIZE_UNSPECIFIED_STABILITY`: if outcomes vary between processes, the split is an order defect, and a total comparator fixes it (O30a, RA-204.4).
- **Representation-row seed collision:** selecting the first incident face row as source-vertex seed position, then deduplicating after earlier rail seeds by face-local barycentrics, suppresses different optional requests depending on face order. Resolve existing typed source-fan identity and canonical source chart instead; require row permutations and a split/coalesce barrier falsifier (O32a Review 2026-11-05). Do not equate lost optional seed annotation with missing producer-owned rail interval.
- **Masked or unconsumed stimulus:** a stronger earlier guard, or a mutation of data that the checked path never reads, makes a negative vacuous; confirm that the intended guard actually fires (RA-169, RA-178, TB35-REV).
- **Oracle copies the producer:** an oracle that re-implements the producer's formula proves nothing; derive it independently (RA-168).
- **Vacuous witness:** RA-146/148 and CB31-REV (corrected statically in CB32-REV): equal-gauge row permutations cannot distinguish stale mapping; unpaired front records do not reach reciprocal periodic action guards. A path that is never reached, or a relation whose operands share an object (RA-124), cannot independently prove its advertised contract. Require separately sourced positive/negative oracles and actual prerequisite reachability.
- **Conflated authority:** row number, gauge, semantic ID, terminal incidence, certificate provenance or a per-node representative face (RA-72.4, RA-123) used as interchangeable identities. Find the unique writer and exact typed correspondence.
- **Premature credit:** compile-green, diagnostic data or focused PASS/RED presented as cumulative acceptance. Separate candidate evidence from reviewed promotion.
- **Predicted cause substituted for measured cause:** inspect the **actual first rejecting predicate** and discriminate its subconditions before proposing a repair.
- **Incomplete case analysis:** a contract excludes a case from one branch without assigning it to another. When a specification says "X cannot enter branch B", ask which branch admits X.
- **Incomplete execution mistaken for expected RED (RA-138):** one test-start marker without a terminal GoogleTest failure is not evidence of a completed negative outcome. Preserve the log but fail the harness.
- **Documentation drift:** a second “CURRENT” section appended rather than revising the existing one. Move incident history into its owning tracker, changelog, report or closure record.

Reusable rules and examples belong in [LESSONS.md](LESSONS.md), not here.

## 9. Code entry points

| Subject | Source |
|---|---|
| Pipeline and product wiring | [`src/pipeline/RemeshPipeline.cpp`](../../src/pipeline/RemeshPipeline.cpp) |
| Field tracing, rails, contacts and transport | [`src/geometry/SurfaceCellTracing.cpp`](../../src/geometry/SurfaceCellTracing.cpp) |
| Cut graph and region topology | [`SurfaceCutGraph.cpp`](../../src/geometry/SurfaceCutGraph.cpp), [`GlobalTopologyPlan.cpp`](../../src/geometry/GlobalTopologyPlan.cpp) |
| Geometry/network and pipeline tests | [`FieldAlignedCurveNetworkTests.cpp`](../../tests/FieldAlignedCurveNetworkTests.cpp), [`SurfaceCellsPhase10Tests.cpp`](../../tests/SurfaceCellsPhase10Tests.cpp), [`SurfaceCellPipelinePhase20Tests.cpp`](../../tests/SurfaceCellPipelinePhase20Tests.cpp) |
| Field-aligned network and SurfaceCells diagnostics display (GUI sections 6–7) | [`SourceRegionDisplay.cpp`](../../src/visualization/SourceRegionDisplay.cpp), [`FieldAlignedNetworkPolylines.cpp`](../../src/visualization/FieldAlignedNetworkPolylines.cpp), [`src/gui/Main.cpp`](../../src/gui/Main.cpp) |
| Field streamlines (GUI section 8) | [`FieldStreamlines.cpp`](../../src/visualization/FieldStreamlines.cpp), [`Streamlines.cpp`](../../src/geometry/Streamlines.cpp) |
| Cut graph and disc regions (GUI section 9) | [`CutGraphDisplay.cpp`](../../src/visualization/CutGraphDisplay.cpp) |
| Target size and feature heatmaps (GUI section 10) | [`TargetSizeDisplay.cpp`](../../src/visualization/TargetSizeDisplay.cpp) |
| Review helper conventions | [`.agents/Directional/tools/README.md`](tools/README.md) |

## 10. Outlook and upkeep

**Path forward:** finish M6-CP3 direct-production acceptance → **M7** verifier-owned disposition and strictly labeled degradation → **M8** module boundaries, scale/quality/resource calibration, packaging and production-ready D0 matrix. Future schedules and selector counts remain **unfrozen**; [ROADMAP.md](ROADMAP.md) owns future checkpoint descriptions.

### DURABLE — DO NOT DELETE, AND UPDATE AT EVERY REVIEW TURN

This landing page must remain easy to scan. Per [REVIEW_TURN_POLICY.md §3.1](REVIEW_TURN_POLICY.md#31-orientationmd--update-before-closing-without-exception), every Review updates the **currency line**, **§3** accepted state/selector/accounting, **§4** when witnesses change, **§7** prioritized open problems (remove resolved/stale claims), and **§8** for genuinely new patterns. Review also performs the required consolidation under [CLEAN_UP_POLICY.md](CLEAN_UP_POLICY.md).

**Never append** per-turn headers, repeated status copies, artifact IDs, detailed diagnostics, regression histories, full test ledgers, or frozen definitions. Update summaries **in place**, linking to the correct owner document. Only substantive changes in the project, fixture matrix or document navigation merit more material here.
