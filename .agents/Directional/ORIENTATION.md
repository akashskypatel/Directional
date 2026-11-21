# Directional — Project Orientation

> This rewrite was expressly requested on 2026-10-16.

**Current currency (2026-11-21 UTC; TB153 PASS, RA-276 authority):** TB153 executed the CB168Q package (`203150dff`, artifact `14692425922`; [run 44867242174](https://github.com/akashskypatel/Directional/actions/runs/44867242174), result `14692372657`): 968/968 PASS, 966/966 MATCH TB152 N1–N3 (row 686 excluded), CP2 491/491. Row 968 shows all 24 sphere traces' real pieces reachable (182 segments, 0 rejected, 0 path or binding failures); the 10 slides are all `terminalBarrier=0` at the last segment. Row 686's sphere record changed under the real-piece oracle (fragments 376→372, χ6 unchanged). [Execution](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Execution_Report_20261121.md). Sphere χ+4, rows 669/698 exhaustion, four unowned slide contacts and H4 remain. Stable 66/17/49, debt1, deferred81.

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

**Currency (2026-11-20; RA-276):** TB152 upheld. Ownership of trace-touched faces has three readers (certifier, plan fragments, plan corners), all reading segments, so the producer switch does not change them. Arc-piece ownership is held until row 968 shows whether the stop switch's tail arcs are terminal slits. The switch itself waits for the row 968 reach receipt.

**Historical M6-CP3 evidence (2026-11-20):** [TB148 independent Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md) re-derived 963/963 PASS, accepted 491/491, prior 962/962 MATCH. Four distinct source-edge interior sliding-wall contacts have no shared graph event. Row686 remains V18/E30/F18, χ6 vs source2, and rows669/698 still exhaust. Earlier TB147 census is 1/3 (Cylinder PASS; BunnyRandom/Vase RED), not rerun by TB148. Stable 66/17/49, debt1, deferred81; CP3/selector497/D0/row858 remain unpromoted.

**M0–M5 are complete/closed; M6 is active at CP3.** Closure means the checkpoint's frozen criteria passed, **not** that representative output is production-ready.

| Milestone | Achievement / status |
|---|---|
| **M0–M2 — complete** | Preserved baseline; M1 typed single-authority cutover (**234/234**); M2 closed stage products (**275/275**). |
| **M3 — closed** | Field-aligned tracing, typed network events, cellular cut graph and disc-region authority; required-green **365/365**. |
| **M4 — closed** | Exact global rail schedules, production cutover, conditioning and scale contracts; **430/430**. |
| **M5 — closed** | Canonical periodic/quotient identities, certificates and direct producer evidence; **449/449**. |
| **M6-CP1 — closed** | Occurrence, quotient and embedding separation; **479/479** (mechanism-only). |
| **M6-CP2 — closed** | Independent `SurfaceProductVerifier`; accepted cumulative **491/491**. |
| **M6-CP3 — active** | TB152 967/967 PASS, accepted CP2 491/491, prior 966/966 MATCH TB151; existing TB151 census 3/3 MATCH (Cylinder PASS; BunnyRandom/Vase expected RED). Four unowned edge-slide contacts and sphere χ+4 remain. [TB151 execution](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Execution_Report_20261120.md); TB152 independent Review upheld the helper scope; CB168R and CB168Q compiled (RA-276; CB168P withdrawn); TB153 gate next. CP3/selector497/D0 not promoted. |
| **M7–M8 — planned** | Verifier-assigned disposition/degradation, then production hardening. |

Stable accounting remains **66 events / 17 categories / 49 recurrences** with **one** produced-witness debt. Accepted M6 CP2 is **491/491**; CP3's 497 identities are frozen, not accepted. See the [handoff](Future_Chat_Session_Handoff.md), [RA-124 Review](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_iso_a_seam_node_representative_census_review_decision_20261021md "moved: Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md") and [regression tracker](Regression_Root_Cause_Tracker.md).

## 4. Fixtures and witnesses

**Historical TB143 witnesses (geometry unchanged relative to TB142):** Cylinder PASS 288 quads. Sphere RED: traces 4/6 at one exact edge (0,2) endpoint, noncollinear in both faces, no shared events; 66 crossing diagnostics in 19 rows, each row with a matching exact entry-coincidence receipt; this is not graph publication. BunnyRandom RED: nodes 220/222 claim trace82 at one position; terminating traces43/15 share [X43, v94] on (94,210) and three identical oriented terminal segments; 43 earlier by prior bounded arrival proof. On (94,210), t43=0.26324148596788688 and t15=0.93470265131543506; ratio 0.088627884769471184 (relative error 1.31e-15 to the frozen prediction). TB140 confirms 48 seed, 3 vertex, 15 grazing proposals in BunnyRandom (three repeated 22-receipt blocks); the three predicted grazing identities are present. Proposal counts are not committed path counts. Vase RED unchanged. [TB135 independent Review](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md).

**TB148 sphere witness (independently reviewed):** Row963 observes four distinct committed source-edge slide-interior contacts (17:8/0:6, 20:8/1:6, 5:8/21:6, 8:8/22:6), exact parameter and strict open-interval support, all `sharedEvents=0`. Row686 remains V18/E30/F18, χ6 vs sourceχ2. This is not a verified topology repair and the existing face-chord cut-position type cannot encode slide interiors. [TB148 Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md). TB147 previous two reciprocal end nodes and its three-case census are unchanged; row858 is unpromoted.

**Historical TB146 sphere witness:** 66→0 duplicate crossing diagnostics; two exact pending/pending pairs 4/6 on (0,2), 15/19 on (25,27), same parameter `574181338608147/4503599627370496`, unchanged pre-switch receipts. Four anonymous strict index failures and no final trace census. Row648 still verifies no plan. Row858 now passes its face-locus display assertion; exact face and code are not printed there. Rows669/698 show `CutSearchExhaustedBeforeCellularity`, not graph publication. No new Cylinder, BunnyRandom or Vase measurements. [TB146 Review](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md).

**A3 exactness and the API display witness:** A3 branch topology (face gauge, barycentric derivatives, port order) is exact on the stored doubles (RA-180/RA-181); FMA and FMA-free builds agree byte for byte. Row 858 (`apicensus:19`) retains the +½-singularity vertex stop (RA-182) but its distinct sphere cut-graph face assertion is a historical RED at :155 in TB131/TB132 through TB145; TB146 passes that assertion without promotion. Row952 PASS with the corrected exact witness and retained assertions. Exact directions widen A4 trace parameters (O15c; e.g. sphere_prescribed 1,531 of 4,096 bits, fail-closed), and P13 measures them.

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
| Folder layout | `RETENTION_POLICY.md` § `.agents/Directional` layout: documents, the current review record and next-turn patches at the top level; current gate inputs (case manifests, census manifest, deferred ledger) in [`gates/`](gates/); selectors in `selectors/`, scripts in `tools/`, fixed-path tool inputs in [`tools/data/`](tools/data/), cited historical evidence data (byte-pinned TSVs) in [`evidence/`](evidence/). |
| Byte-frozen selectors | [`selectors/`](selectors/) holds all 54 selector files (numbered, M1 full, M6 focused, routing receipts). [Required_Green_Selector_Manifest.md](Required_Green_Selector_Manifest.md) indexes them; policy is in `RETENTION_POLICY.md` § Selector files. |
| Tasks, blocked issues, regression classification | Root [TODO.md](../../TODO.md), [Regression_Root_Cause_Tracker.md](Regression_Root_Cause_Tracker.md). |
| Change history and reusable lessons | [CHANGELOG.md](../../CHANGELOG.md), [LESSONS.md](LESSONS.md). |
| A former `Architecture_M6*` record | Folded per-turn files: [M6 folded document index](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete) (role, verdict, retained home, `git show` recovery). Review, definition and audit records: the [M6 moved-record map](M6_Consolidated_Record.md#m6-moved-record-map-2026-11-09). Each record is kept verbatim in one of five volumes: [A](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md) definitions/CP1/CP2, [B](M6_Consolidated_Record_Vol_B_CP3_R_Series.md) CP3 R-series, [C](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md) CP3 gate turns, [D1](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md) and [D2](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md) P13. 23 `Architecture_M*` files remain standalone: frozen definitions, current authority, next-turn patches and data files. |
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

## 7. Open problems

**Current priority:** `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-REV` (Review; [TB153 execution](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Execution_Report_20261121.md)): attribute the row 686 sphere record, freeze an unwired piece-ray helper then the switch CB, and decide arc-piece ownership from the walls' `terminalBarrier=0`. No producer or stop switch is authorized yet. Four slide contacts, χ+4 and rows 669/698 remain unresolved.

- **Historical priority (superseded by RA-273):** [RA-272](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Independent_Review_20261120.md) had authorized a prose CB168M, now withdrawn.

- **Other open product work:** Vase completion remains RED (P13); A4 must consume the correct A3 plan per A2b disc. O42/O43 remain open; O44/C1 closed. The C4/CB145 branch is parked. D11=A, D12=A, D10 deferred, D6 pending. The production rail schedule remains per-arc (`chainRimSchedules=false`); do not activate the chain switch without its frozen preconditions and independent evidence.
- **Other obligations and parked work:** source topology/fixture limitations (including genus>0), platform portability, witness debt, deferred identities, chain/fan/rim ownership, diagnostics, verification and production-quality gates remain governed by their precise dispositions in [regression tracker](Regression_Root_Cause_Tracker.md), [TODO](../../TODO.md), [DESIGN.md](DESIGN.md) and the retained normative definitions. Do not treat a historical next-turn label as current authorization or infer that a condensed entry is closed.
- **M6-CP3 and later:** achieve the required representative direct matrix and independently verify all acceptance criteria before promotion. The D0 ladder and production hardening remain later milestones. See [ROADMAP.md](ROADMAP.md).

## 8. Recurring defect patterns

The full reusable rules are in [LESSONS.md](LESSONS.md). Key patterns: one semantic owner per fact; exact certified source identity rather than coordinate equality; preserve frozen byte identities; distinguish invalid stimulus from product failure; negative controls must reach the rejecting predicate; no inherited PASS claim implies production acceptance. RA-245 typed-ID extent; RA-102.1 assertion relocation; RA-250 actual GMP conversion and guard producer proof. TB129 repeats RA-250: trace diagnostic replay and shared fixture callers before freezing receipt scope/count; count distinct semantic identities, not log lines. TB131/TB143: compare full diagnostic records and pointer-object presentation only under prospective explicit rules; a joined-record presentation difference cannot be normalized retroactively; do not treat a forensic explanation as a frozen gate pass. TB133 distinguishes transverse edge endpoints from co-directional overlaps. The latter cannot be cured by merging two contact IDs. Establish producer incidence before changing the consumer. TB134: first equal face entry is not necessarily first overlap; include earlier edge-slide pieces and compare source-authoritative arrival bounds. TB135 confirms RA-256: retain the slide start and verify a predicted scaling ratio before defining ownership. TB140-REV: changing the path representation without its piece-sensitive certifiers violates existing ownership and mandatory validation; list all semantic consumers before freezing a switch (existing LESSONS rules). Prior evidence and detailed causes remain in their owning records and the [historical navigation preimage](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#orientationmd). TB148: an edge-slide interior cannot be substituted into a face-chord cut position; keep the piece-aware position and producer switch separate. TB147: avoid inferring unique missing graph nodes from Euler excess alone, and do not transfer BunnyRandom different-face contacts to the sphere; canonicalize source chart aliases before counting contacts ([TB147 Review](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Independent_Review_20261120.md)). TB146: a representation change can invalidate an unconditional test premise even when its accepted identity remains frozen. Preserve every unrelated assertion, require a falsifiable independent oracle for the exact new case, and keep a RED until runtime proves it ([TB146 Review](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md)).

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
