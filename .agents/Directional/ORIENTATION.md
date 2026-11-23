# Directional — Project Orientation

> This rewrite was expressly requested on 2026-10-16.

**Current currency (2026-11-23 UTC; TB-REV-168 independent review COMPLETE; CB-188 region visit reader NEXT):** TB168 993/993 PASS, accepted CP2 491/491, membership 1074. TB167 prior 989 rows match under N1–N3. Four pure adapter tests pass, but adapter is not yet wired. Independent Review froze exact, separate CB-188 and CB-189 diffs without applying them; see [review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md). CB-188 region reader goes first; only then separate TB169 and CB-189. Production sphere still fails cut-search; staged sphere stops at multi-cut face 6-8-9. Stable 66/17/49, debt1, deferred81; CP3/497/D0/H4 held.

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

**Currency (2026-11-23 UTC; TB-REV-168 COMPLETE, CB-188 NEXT):** TB168 993/993 PASS, CP2 491/491, 1074 membership (993 gated + 81 deferred). Prior TB167 989/989 match under N1–N3. CB-187 adapter is unwired; separate exact deferred CB-188 region and CB-189 corner diffs are frozen in [review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md). No production recovery or CP3/497/D0/H4 promotion. Stable 66/17/49, debt1, deferred81.


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
| **M6-CP3 — active; multi-cut plan remains open** | TB166 immutable 984/984 PASS, CP2 491/491, 179 new exact multi-cut/singularity receipts. The prior nearest-chord seed switch is accepted (192/192 owners, source-face cellularity 1). The staged plan still rejects face 6-8-9 with multiple cuts; production sphere cut-search, Y7, V3b and χ+4 remain open. TB-REV-166 discharged the edge-supported K5 witness; CB-186 pure helper and then separately CB-187 reader switch must be proved before activation. No CP3/497/D0/H4 promotion. |
| **M7–M8 — planned** | Verifier-assigned disposition/degradation, then production hardening. |

Stable accounting remains **66 events / 17 categories / 49 recurrences** with **one** produced-witness debt. Accepted M6 CP2 is **491/491**; CP3's 497 identities are frozen, not accepted. See the [handoff](Future_Chat_Session_Handoff.md), [RA-124 Review](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_iso_a_seam_node_representative_census_review_decision_20261021md "moved: Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md") and [regression tracker](Regression_Root_Cause_Tracker.md).

## 4. Fixtures and witnesses

**TB168 adapter witness:** Four isolated `ArcFaceVisits` tests PASS under 993-row gate; existing 989 TB167 raw logs match N1–N3. The helper remains unwired and does not establish sphere output. [Independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md).

**TB166 singularity-port witness (independent TB-REV-166):** Row979 contains 24 departing port records on eight singular nodes. Every `outgoing` carrier is opposite the source vertex, so `SurfaceCellTracing` creates no radial `edgePortCarrier` for any of them; each also prints `slide=-`. The ten incoming singular arrivals all report `terminalSingularity=1` and have slide carriers distinct from the outgoing first carriers at their nodes. K5's particular edge-supported co-trace is absent in this witness; other crossings or reader errors are not excluded. Face `6-8-9` still has five recorded visits (FE/E/F/F/FE); its staged plan is not yet constructible. [TB-REV-166](Architecture_M6_CP3_TB_REV_166_Staged_Multi_Cut_Face_Receipt_Independent_Review_20261122.md).

**Historical TB143 witnesses (geometry unchanged relative to TB142):** Cylinder PASS 288 quads. Sphere RED: traces 4/6 at one exact edge (0,2) endpoint, noncollinear in both faces, no shared events; 66 crossing diagnostics in 19 rows, each row with a matching exact entry-coincidence receipt; this is not graph publication. BunnyRandom RED: nodes 220/222 claim trace82 at one position; terminating traces43/15 share [X43, v94] on (94,210) and three identical oriented terminal segments; 43 earlier by prior bounded arrival proof. On (94,210), t43=0.26324148596788688 and t15=0.93470265131543506; ratio 0.088627884769471184 (relative error 1.31e-15 to the frozen prediction). TB140 confirms 48 seed, 3 vertex, 15 grazing proposals in BunnyRandom (three repeated 22-receipt blocks); the three predicted grazing identities are present. Proposal counts are not committed path counts. Vase RED unchanged. [TB135 independent Review](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md).

**TB148 sphere witness (independently reviewed):** Row963 observes four distinct committed source-edge slide-interior contacts (17:8/0:6, 20:8/1:6, 5:8/21:6, 8:8/22:6), exact parameter and strict open-interval support, all `sharedEvents=0`. Row686 remains V18/E30/F18, χ6 vs sourceχ2. This is not a verified topology repair and the existing face-chord cut-position type cannot encode slide interiors. [TB148 Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md). TB147 previous two reciprocal end nodes and its three-case census are unchanged; row858 is unpromoted.

**Historical TB146 sphere witness:** 66→0 duplicate crossing diagnostics; two exact pending/pending pairs 4/6 on (0,2), 15/19 on (25,27), same parameter `574181338608147/4503599627370496`, unchanged pre-switch receipts. Four anonymous strict index failures and no final trace census. Row648 still verifies no plan. Row858 now passes its face-locus display assertion; exact face and code are not printed there. Rows669/698 show `CutSearchExhaustedBeforeCellularity`, not graph publication. No new Cylinder, BunnyRandom or Vase measurements. [TB146 Review](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md).

**TB163 independent owner witness:** [TB-REV-163 independent review](Architecture_M6_CP3_TB_REV_163_Staged_Uncut_Owner_Census_Receipt_Independent_Review_20261122.md) verifies 2 eight-face uncut components, 16 boundaries with `barrier=0 oppositeTraceCut=1 sideOwner=1`, zero interior arcs, transits and seeds. All 30 arc records present; uniqueness remains unproved. No R-a/H5 selection.

**TB162 independently reviewed owner witness:** Row979 shows 192 source faces, 176 established and 16 unavailable owners; two eight-face uncut components have zero seeds and no conflicts. [Review](Architecture_M6_CP3_TB_REV_162_Staged_Plan_Owner_Evidence_Receipt_Independent_Review_20261122.md). No direct sphere result is accepted.

**TB161 independently reviewed witness:** Row979 has 41 receipts: staged graph V18/E30/F14 χ2, 24 trace ends, 14 slide pieces; plan fails `UncutFaceComponentOrbitSeedNotUnique` on face 2-5-12. This does not prove two owners or a valid production plan; [Review](Architecture_M6_CP3_TB_REV_161_Staged_Slide_Entry_Stop_Downstream_Receipt_Independent_Review_20261122.md).

**TB160 reviewed witness:** Row978 reports four exact Later moving stops, 24 traces, 56 events, eight carrier-end IDs, ten slide segments and `cutGraph=built`. `SurfaceCutGraph::make` success requires `proves_embedded_cellularity` (χ, components, disc faces), so the staged cut graph is certified; source-face cellularity, plan and output are unmeasured. [Independent review](Architecture_M6_CP3_TB_REV_160_Staged_Slide_Entry_Stop_Full_Gate_Independent_Review_20261122.md); [adversarial](Architecture_M6_CP3_TB_REV_160_Adversarial_Review_20261122.md).

**TB159 independently reviewed witness:** The 564 gate slide-entry receipts show strict interior, Later, and stop-record constructibility on four sphere contact pairs. BunnyRandom adds three swapped-role receipts and has six total records against pending walls (three each for `26:1->99:0` and `142:2->87:0`). No producer stop event was published; pending-wall survival and V3b full reach remain unproved. [TB-REV-159](Architecture_M6_CP3_TB159_P13_Slide_Entry_Stop_Predicate_Full_Gate_Independent_Review_20261122.md).

**TB156 reviewed witness:** Row858 original source-face assertion is PASS; row972 confirms ten slide carriers, all classified and none selected, but ends in cut-search exhaustion. Row686 χ6 versus sourceχ2 and four unowned contacts remain unresolved. This does not prove direct sphere production.

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

**Current priority:** Apply only the frozen CB-188 region reader patch (R1–R4), then execute the independent TB169 gate; CB-189 corner reader follows in a separate turn (C1–C4). [Current review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md). The prior prose CB-187 plan and S5 STOP were withdrawn by TB-REV-167 adversarial P2–P7; they are not live tasks. Staged multi-cut and production sphere failures remain open; no CP3 promotion.

- **Other open product work:** Vase completion remains RED (P13); A4 must consume the correct A3 plan per A2b disc. O42/O43 remain open; O44/C1 closed. The C4/CB145 branch is parked. D11=A, D12=A, D10 deferred, D6 pending. The production rail schedule remains per-arc (`chainRimSchedules=false`); do not activate the chain switch without its frozen preconditions and independent evidence.
- **Other obligations and parked work:** source topology/fixture limitations (including genus>0), platform portability, witness debt, deferred identities, chain/fan/rim ownership, diagnostics, verification and production-quality gates remain governed by their precise dispositions in [regression tracker](Regression_Root_Cause_Tracker.md), [TODO](../../TODO.md), [DESIGN.md](DESIGN.md) and the retained normative definitions. Do not treat a historical next-turn label as current authorization or infer that a condensed entry is closed.
- **M6-CP3 and later:** achieve the required representative direct matrix and independently verify all acceptance criteria before promotion. The D0 ladder and production hardening remain later milestones. See [ROADMAP.md](ROADMAP.md).

TB-REV-167 S6 (carried to CB-190): terminal-vertex edge-side diagnostics require a direct two-orientation witness. Diagnostic-only; no new stable regression.

## 8. Recurring defect patterns

TB-REV-167 S7 (carried to CB-190): exact clipped-arc diagnostics must not replay whole original segments. This is diagnostic conformity, not current stage ownership.



TB-REV-167 S5 (withdrawn, not a live STOP): face-interior split nodes do not invalidate the sound k+1 upper bound; the proposed equality/deficit rejection was withdrawn in adversarial P4.

TB-REV-167 follow-up: repair all semantic readers of a clipped arc together. Correcting the corner reader alone leaves `build_regions` to count full segments and give face fragments inconsistent ownership. Its local chord diagnostics also use original segment endpoints, which may not match the published clipped arc. An error field must identify a causal arc, not the first arc stored for that face. A partial source review patch removes those unsupported error-arc fields, but it does not repair the two-reader count contract and has not been compiled. These findings apply existing source-authority and non-vacuity lessons; neither is a measured stable regression.

TB-REV-167 continuation: a reader that assumes every source-piece segment begins in a face rejects a valid edge-only slide piece. Inspect exact per-segment canonical carriers before assigning a face cut; do not infer source binding from topology. This is a candidate review finding, not a new stable regression.

TB-REV-167: synthetic helper PASS results do not exercise the production reader. Require independent source-path and downstream certificate checks before connecting the helper. This is an application of existing non-vacuity and single-writer lessons, not a new stable regression.

TB-REV-166: an opposite-edge face departure must not be confused with an edge-supported singular port. `FieldTransportAtlas` attaches edge ports to radial edges containing the source vertex and `SurfaceCellTracing` sets `edgePortCarrier` only for these attachments. All 24 TB166 departures exclude the source vertex, so the K5 edge-port co-trace does not occur; a later matching radial-edge arrival must still cause A2a STOP. This applies existing source-authority/identity and non-vacuity lessons, not a new generalized rule.

TB163: an owner-map presence flag is not a uniqueness certificate. For every boundary, `sideOwner=1` records a nonempty map, not exactly one admissible orbit. Demand oriented source-entity incidence and explicit owner cardinality before deriving missing face ownership. This is an instance of the existing source-authority / non-vacuity rule; no new generalized lesson.

TB161: an error called `OrbitSeedNotUnique` is not evidence of multiple owners. The same consistency guard rejects absent, unestablished, trace-crossed or multi-orbit face evidence. Embedded graph χ2 and the first reported face key do not identify the failing owner; require exact component evidence before a repair. This is an instance of the existing single-writer and evidence/causality rules, not a new generalized lesson.

The full reusable rules are in [LESSONS.md](LESSONS.md). Key patterns: one semantic owner per fact; exact certified source identity rather than coordinate equality; preserve frozen byte identities; distinguish invalid stimulus from product failure; negative controls must reach the rejecting predicate; no inherited PASS claim implies production acceptance. RA-245 typed-ID extent; RA-102.1 assertion relocation; RA-250 actual GMP conversion and guard producer proof. TB129 repeats RA-250: trace diagnostic replay and shared fixture callers before freezing receipt scope/count; count distinct semantic identities, not log lines. TB131/TB143: compare full diagnostic records and pointer-object presentation only under prospective explicit rules; a joined-record presentation difference cannot be normalized retroactively; do not treat a forensic explanation as a frozen gate pass. TB133 distinguishes transverse edge endpoints from co-directional overlaps. The latter cannot be cured by merging two contact IDs. Establish producer incidence before changing the consumer. TB134: first equal face entry is not necessarily first overlap; include earlier edge-slide pieces and compare source-authoritative arrival bounds. TB135 confirms RA-256: retain the slide start and verify a predicted scaling ratio before defining ownership. TB140-REV: changing the path representation without its piece-sensitive certifiers violates existing ownership and mandatory validation; list all semantic consumers before freezing a switch (existing LESSONS rules). Prior evidence and detailed causes remain in their owning records and the [historical navigation preimage](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#orientationmd). TB159 initially exposed the T5 pending-wall lifetime question; TB-REV-159 U2 closed it by ordered-arrival reasoning plus fail-closed consumer segment checks, and TB160 supplies the staged committed-wall witness. Do not treat the superseded warning as an open stop. TB148: an edge-slide interior cannot be substituted into a face-chord cut position; keep the piece-aware position and producer switch separate. TB147: avoid inferring unique missing graph nodes from Euler excess alone, and do not transfer BunnyRandom different-face contacts to the sphere; canonicalize source chart aliases before counting contacts ([TB147 Review](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Independent_Review_20261120.md)). TB146: a representation change can invalidate an unconditional test premise even when its accepted identity remains frozen. Preserve every unrelated assertion, require a falsifiable independent oracle for the exact new case, and keep a RED until runtime proves it ([TB146 Review](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md)).

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
