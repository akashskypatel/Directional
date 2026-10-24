# Directional — Project Orientation

>This rewrite was expressly requested on 2026-10-16.

**Currency:** 2026-10-24 · CB32-REV accepts independently source-derived signed odd A3 test oracles **for immutable artifact-only TB**, not runtime or product acceptance. Exact next `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION`; TB32 candidate 481/500 (497: 478 PASS/19 inherited RED); CP2 491/491 accepted, CP3 unaccepted; stable 66/17/49, debt1; RP-01 open, RP-02 unreached.
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
| **M6-CP3 — active** | Direct-production and M6 exit re-proof **not accepted**. Frozen 497-row entry selector; reviewed R3 candidate **403 PASS / 94 RED**. |
| **M7–M8 — planned** | Verifier-assigned disposition/degradation, then production hardening. |

**Current evidence (RA-148 and CB31-REV):** Independent TB32 Review rechecked 1,006/1,006 artifact checksums and 500 distinct raw logs. Its original 497-case selector measured **478 PASS / 19 inherited RED** (six RED→PASS over TB31's 472/497, zero regressions), plus three PASS factory controls for **481/500**. The six recovered cases prove synthetic checked-factory fixture/owner assertions, not real odd atlas transport, periodic topology or produced A6 behavior. The 19 REDs remain at unchanged first sites, including seven A3 unavailable-route fixture exceptions and seven untyped cases. CB31 lacked independent raw signed-inverse and topology-keyed gauge expectations. **CB32-REV** verifies the corrected expected (3/1) from signed raw arms, semantic source-face mapping and guarded false-gauge negatives; eight-target GMP compile source is verified. Static sufficiency only: `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION` must execute the immutable artifact before runtime credit; no M6-CP3 acceptance. Prior TB28/TB30/TB31 reports remain historical comparison baselines.

Stable accounting remains **66 events / 17 categories / 49 recurrences** with **one** produced-witness debt. Accepted M6 CP2 is **491/491**; CP3's 497 identities are frozen, not accepted. See the [handoff](Future_Chat_Session_Handoff.md), [RA-124 Review](Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md) and [regression tracker](Regression_Root_Cause_Tracker.md).

## 4. Fixtures and witnesses

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

**Immediate:** CB32-REV has independently accepted the corrected static oracle but **runtime remains unproved**; execute the immutable CB32 cases only in `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION`. [RA-148](Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Verification_Review_Decision_20261023.md) accepts TB32 runtime evidence only within the checked-factory scope; six owner tests and all three controls are now measured PASS.


| Priority | Missing outcome | Owner |
|---|---|---|
| **1** | Six owner-map tests and three factory controls are **discharged in prior synthetic runtime scope** at RA-148; CB32-REV accepts raw-derived odd atlas signed (3/1) and independent permutation/negative test **only statically**. Next immutable TB must execute it; produced periodic/A6 remain separate. | M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION; [CB32-REV](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Review_Decision_20261024.md), [CB31-REV](Architecture_M6_CP3_CB31_Odd_Atlas_Transport_Permutation_Review_Decision_20261023.md), [RA-148](Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Verification_Review_Decision_20261023.md) and [RA-146](Architecture_M6_CP3_DEFN_FG01_Periodic_Face_Gauge_Factory_Contract_Review_Decision_20261023.md) |
| **2** | Restore accepted-prefix execution and the direct-production positive and tamper paths. Fixture debt follows TB19-REV: 242 → 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R test assumptions. Preserve the accepted 491/491 and the frozen 497 identities. | M6-CP3; [tracker](Regression_Root_Cause_Tracker.md) |
| **3** | Discharge the final **`G4-B002`** closed-complex candidate-extraction witness on real produced authority. | M6-CP3 exit |
| **4** | Implement verified D0–D4 degradation/disposition and representative production quality/resource acceptance. | M7 → M8; [roadmap](ROADMAP.md) |

## 8. Recurring defect patterns

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
