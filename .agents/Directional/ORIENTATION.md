# Directional — Project Orientation

>This rewrite was expressly requested on 2026-10-16.

**Currency:** 2026-10-31 · M6-DEFN-DIAG-RETAIN-CLI-GUI — [RA-185](Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md) adds a polyscope-free display adapter and text dump for the A5–A7 snapshots in `directional_pipeline` (CB59 frozen; API binary 25/25, membership 945); CLI/GUI wiring follows. The local baseline is TB57 860/861. RP-01, O15, row 935, O2 and the A5–A7 snapshots are done. TB52 853/0 is the latest reviewed Linux candidate; CP2 491/491 last accepted; stable 66/17/49 debt 1. Next `M6-CB59-DIAG-RETAIN-MATERIALIZATION-DISPLAY`.
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
| **M6-CP3 — active** | Local gate TB57 **860/861** on CB58 (861 gated, 82 deferred, membership 943); row 283 (O16) is the only red. RP-01 is closed (RA-179), O15 discharged (RA-181), row 935 gated (RA-182), the O2 entry gate landed (RA-183) and the A5–A7 diagnostic snapshots landed (RA-184). Linux reviewed candidate TB52 853/0. CP3 closure and the direct-production matrix are **not accepted**. selector497 frozen. |
| **M7–M8 — planned** | Verifier-assigned disposition/degradation, then production hardening. |

**Prior Review authority:** [RA-185](Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md) (DIAG-RETAIN display; DR2 → M8-CP2), [RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md) (DIAG-RETAIN), [RA-183](Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md) (O2 gate; O2b, O16), [RA-181](Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md) (O15 discharged; O15c) and [RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md) (RP-01 closed; local-mode rules). Implementers get only exact patches and manifests.

**Test authority:** Local macOS: [TB57](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md) **860/861** on CB58 (membership 943), a pre-registered outcome. Linux: TB52 **853/0** (run 41100261157, RA-177). A Linux CI confirmation of rows 854–859 is carried. Not D0 production, CP3 closure or selector497 promotion.

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

**Immediate:** CB59 → TB58 (863, membership 945) → `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING`. Then the P13 probe DEFN (Cylinder; O6, O9, O15c checks).


| Priority | Missing outcome | Owner |
|---|---|---|
| **1** | DIAG-RETAIN (user-directed A5–A7 snapshots), then the P13 design-acceptance matrix. RP-01, O15, row 935 and O2 are done; their Linux CI confirmation is carried. | `M6-DEFN-DIAG-RETAIN-A5-A7` (R) |
| **2** | Restore accepted-prefix execution and the direct-production positive and tamper paths. Fixture debt follows TB19-REV: 242 → 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R test assumptions. Preserve the accepted 491/491 and the frozen 497 identities. | M6-CP3; [tracker](Regression_Root_Cause_Tracker.md) |
| **3** | Discharge the final **`G4-B002`** closed-complex candidate-extraction witness on real produced authority. | M6-CP3 exit |
| **4** | Implement verified D0–D4 degradation/disposition and representative production quality/resource acceptance. | M7 → M8; [roadmap](ROADMAP.md) |

## 8. Recurring defect patterns

- **Platform split:** a result that differs between builds is a determinism defect; compute the exact answer before classifying, and change per-file flags only through the build system (RA-176, RA-179).
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
