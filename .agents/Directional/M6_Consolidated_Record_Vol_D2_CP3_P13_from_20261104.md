# M6 consolidated record, volume D2: CP3 P13 definitions and Reviews from 2026-11-04 (RA-204 to RA-217)

This volume holds **30** former standalone `Architecture_M6*` records, moved here on 2026-11-09 by user instruction ("consolidate these records and prune if the content from each is already documented elsewhere"). No record's content was already documented elsewhere: verbatim-line coverage in the permanent documents was at most 27%. So each record is kept **verbatim** as one section below, and nothing is summarized. Only two things changed: heading levels are demoted by two, and links to other moved records point to their sections. Each original file existed standalone at commit `7a460a5e41c4a77a51b69db672e69f910532718c` (`git show 7a460a5e41c4a77a51b69db672e69f910532718c:.agents/Directional/<name>`). Anchors inside a record (`#…`) may resolve to an earlier record in this volume that has the same heading text. The [moved-record map](M6_Consolidated_Record.md#m6-moved-record-map-2026-11-09) lists every record and its volume.

| Original file | Title |
|---|---|
| [`Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md`](#architecture_m6_cp3_tb76_rev_p13_census_path_cost_probe_adjudication_20261104md) | RA-202 — TB76 Linux Vase timeout: census-path cost probe adjudication (2026-11-04) |
| [`Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md`](#architecture_m6_cp3_tb78_rev_p13_platform_split_adjudication_20261104md) | RA-203 — TB78 Review: the review-boundary block, and the Vase completed-quad platform split (2026-11-04) |
| [`Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md`](#architecture_m6_cp3_cb92_p13_source_vertex_fan_seed_identity_plan_20261105md) | CB92 — Canonical source-vertex fan seed identity (frozen implementation plan, 2026-11-05) |
| [`Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Probe_Adjudication_20261105.md`](#architecture_m6_cp3_defn_p13_completed_mesh_orientation_probe_adjudication_20261105md) | RA-208 — P13-l resolved: the block, the measured owners, and exact CB93/CB94 (2026-11-05) |
| [`Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md`](#architecture_m6_cp3_defn_p13_completed_mesh_orientation_review_single_writer_own_plane_20261105md) | RA-209 — Review of RA-208: the orientation pass must go, and both embedding predicates must project onto the q |
| [`Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md`](#architecture_m6_cp3_defn_p13_o32a_vase_producer_scratch_result_20261105md) | O32a actual Vase producer scratch result — WIP (2026-11-05) |
| [`Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md`](#architecture_m6_cp3_defn_p13_platform_split_review_arrangement_cell_order_20261105md) | RA-204 — O30 Review: the platform split is an arrangement cell-order defect, not the field (2026-11-05) |
| [`Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md`](#architecture_m6_cp3_defn_p13_row_permutation_seeds_review_fan_seeding_20261105md) | RA-207 — Review of the O32a seed Review: the mechanism holds; CB92 becomes an exact, capability-preserving pat |
| [`Architecture_M6_CP3_DEFN_P13_Seed_Capture_Analyzer_Correction_WIP_20261105.md`](#architecture_m6_cp3_defn_p13_seed_capture_analyzer_correction_wip_20261105md) | O32a scratch capture analyzer correction — WIP evidence |
| [`Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md`](#architecture_m6_cp3_defn_p13_smooth_field_portability_review_row_permutation_20261105md) | RA-205 — Review of M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY (RA-204): cross-library fix confirmed, DESIGN §10. |
| [`Architecture_M6_CP3_TB80_REV_Review_Final_Validation_Binding_Per_Vertex_20261105.md`](#architecture_m6_cp3_tb80_rev_review_final_validation_binding_per_vertex_20261105md) | RA-206 — Review of the TB80 Review: row 899 exposed a real O(F×V) binding check, and its wall clock was calibr |
| [`Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md`](#architecture_m6_cp3_tb81_p13_final_validation_binding_full_gate_execution_report_20261105md) | TB81 — Final-validation binding-once immutable full gate and production census (2026-11-05) |
| [`Architecture_M6_CP3_DEFN_P13_Source_Microedge_Provenance_Review_WIP_20261106.md`](#architecture_m6_cp3_defn_p13_source_microedge_provenance_review_wip_20261106md) | P13-l2 source microedge classification — supplemental WIP Review |
| [`Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Provenance_Probe_Adjudication_20261106.md`](#architecture_m6_cp3_defn_p13_stitch_overlap_provenance_probe_adjudication_20261106md) | RA-210 — P13-l2 block resolved: the Vase residue is three contact predicates; exact CB97 → CB98 → CB99 → TB84  |
| [`Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Scratch_Recovery_20261106.md`](#architecture_m6_cp3_defn_p13_stitch_overlap_scratch_recovery_20261106md) | P13-l2 independent Review scratch recovery — 2026-11-06 |
| [`Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Adversarial_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a3_metric_breakpoint_placement_adversarial_review_20261108md) | RA-217 — Step 64.5 (D7b) re-entered: one run decomposition, no zero-weight failure, exact CB108 and CB109 |
| [`Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a3_metric_breakpoint_placement_review_20261108md) | D7b — Exact A3 metric-breakpoint placement (runtime-free Review) |
| [`Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_adversarial_review_20261108md) | RA-216 — Step 64 (D7) re-entered: an implementable exact count, placement split out, exact CB106 and CB107 |
| [`Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_review_20261108md) | D7 — Partition-stable A3 preferred metric and exact breakpoint contract |
| [`Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Adversarial_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a3_recorded_boundary_intervals_adversarial_review_20261108md) | RA-215 — Step 61 (D9 recorded boundary intervals) re-entered: exact CB104, falsifiers re-bound, D4 owned |
| [`Architecture_M6_CP3_DEFN_P13_A4_A2b_Chain_Segmentation_Falsifier_20261108.md`](#architecture_m6_cp3_defn_p13_a4_a2b_chain_segmentation_falsifier_20261108md) | M6-CP3 P13 A4/A2b Review: A3 virtual-chain metric and breakpoint falsifier (2026-11-08) |
| [`Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md`](#architecture_m6_cp3_defn_p13_a4_a2b_disc_producer_runtime_free_resolution_20261108md) | RA-214 — M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER resolved runtime-free; first A4→A3 slice frozen (2026-11-08) |
| [`Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md`](#architecture_m6_cp3_defn_p13_a4_a2b_production_contract_audit_20261108md) | Directional A4 per-A2b-disc producer — production-contract audit (continued Review) |
| [`Architecture_M6_CP3_DEFN_P13_A4_A2b_Readonly_Authority_Extraction_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a4_a2b_readonly_authority_extraction_review_20261108md) | M6-CP3 P13 A4/A2b producer — read-only A2a′/A2b/A3 extraction seam (same-turn continuation, 2026-11-08) |
| [`Architecture_M6_CP3_DEFN_P13_A4_A2b_Three_Side_Feasibility_Continuation_20261108.md`](#architecture_m6_cp3_defn_p13_a4_a2b_three_side_feasibility_continuation_20261108md) | A4/A2b same-turn independent feasibility addendum |
| [`Architecture_M6_CP3_DEFN_P13_A4_A2b_Topology_Only_Scratch_Review_20261108.md`](#architecture_m6_cp3_defn_p13_a4_a2b_topology_only_scratch_review_20261108md) | M6-CP3 A4/A2b — independent topology-only scratch, 2026-11-08 |
| [`Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Census_Adjudication_20261108.md`](#architecture_m6_cp3_defn_p13_side_subdivision_quality_census_adjudication_20261108md) | RA-211 — P13-n side-subdivision quality: per-patch census and owner adjudication (2026-11-08) |
| [`Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md`](#architecture_m6_cp3_defn_p13_side_subdivision_quality_review_legacy_fallback_density_20261108md) | RA-212 — Adversarial review of RA-211: Vase runs on the legacy fallback, its layout is relief-seeded and 20× t |
| [`Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md`](#architecture_m6_cp3_defn_p13_vase_producer_path_adversarial_review_a2b_disc_construction_20261108md) | RA-213 — Adversarial re-entry of M6-CP3-DEFN-P13-VASE-PRODUCER-PATH (2026-11-08) |
| [`Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Orientation_Adjudication_20261108.md`](#architecture_m6_cp3_tb87_rev_p13_a3_observed_route_orientation_adjudication_20261108md) | TB87 Review — canonical route orientation versus observed A3 interval |

## `Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md`; moved verbatim.

### RA-202 — TB76 Linux Vase timeout: census-path cost probe adjudication (2026-11-04)

**Turn:** `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`, re-adjudicated by Review (Claude, scratch build) — **COMPLETE**.

It supersedes the [TB76 independent Review](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB76_P13_Linux_Vase_Independent_Review_Decision_20261104.md")'s successor. It also withdraws the turn that successor started, `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING`. That turn is IN_PROGRESS, but its patch was never applied or compiled ([preservation record](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB84_P13_Linux_Vase_Diagnostic_Timing_Work_Preservation_20261104.md")). **Do not apply that preserved patch.** The CB84 number stays with the withdrawn turn.

**Base:** HEAD `299be8bd7`. Its product source equals CB83 `2278b8b649b4262fb70a522371ed282655383af5` (`git diff --quiet` over `src include tests benchmarks CMakeLists.txt cmake`).

#### RA-202.1 Review of the TB76 Review

**What stands:**
- The TB76 execution evidence is valid: 893/893, membership 974, 1794 + 9 hashes.
- That Review was right to refuse RA-201.10's inference that "a timeout means CB82 did not take".
- No promotion follows.

**What does not stand:**
1. **Its successor is the wrong shape.**
   - The successor is an open-ended instrumentation turn written by the implementation agent. The implementation agent receives exact patches only (RA-167, RA-172).
   - It adds permanent stage logging on stderr to product code. That answers a question that needs no product change.
   - It takes at least three turns (CB, TB, then "stack sampling in a later step") to name a *stage*, and still not a cost owner.
2. **It overlooked decisive evidence already in its own artifacts.**
   - **Linux is not uniformly slower.** TB76's 119 gate rows that take at least 1 s on macOS ran at a median Linux/macOS ratio of **0.96** (p10 0.66, p90 1.13). Cylinder took 6.33 s against 6.22 s, and BunnyRandom 0.59 s against 0.60 s.
   - **Vase alone has been slower on Linux, in every TB:**

     | TB | Linux | macOS | Ratio |
     |---|---|---|---|
     | TB68 | 213.6 s | 138 s | 1.55× |
     | TB70 | 259 s | 143 s | 1.81× |
     | TB71 | 288.7 s | 143 s | 2.02× |

     A cost confined to one large fixture fits both facts, and so does one bound by memory bandwidth.
   - **Its falsifiers named no cost owner.**

**RA-201's own errors, owned here:**
1. **RA-201.10 mis-registered the census.** It registered "Vase RED within 600 s" from a 250 s macOS run without applying Vase's 1.55–2.0× platform ratio; that ratio predicts 390–500 s. It also wrote that a timeout would mean CB82 did not take.
2. **RA-201 profiled only the post-assembly stage.**
3. **Its P13-k census was incomplete.** Two per-query `source_face_scope` calls remained inside `validate_final_surface_mesh` itself, against Amendment 33.

#### RA-202.2 Findings (macOS scratch, one census process per run)

1. **FMA is not the cause.** An FMA-off build (`-ffp-contract=off`, 9 FMA instructions against 1,885) produced Vase logs and a verdict byte-identical to the default build. Both reached `SelfIntersectingFace` with 192,482 segments, 26,817 cells and 67,829 quads. Their stack samples showed the same phases at the same times. Peak RSS was 0.89 GB.
2. **The HEAD cost profile of the census path** (env-switched timers; 256 s with three Vase runs side by side; about 250 s alone):

   | Section | HEAD | Corrected |
   |---|---|---|
   | Tracing (`build_surface_cell_network`) | ≈60 s | unchanged |
   | Selection (`select_sparse_flow_rep_network`) | 24.1 s | 1.6 s |
   | Arrangement total (`build_surface_cell_complex`) | 105.3 s | ≈10 s |
   | — of which the geometric T-junction scan | 94.5 s | <1 s |
   | Completion | ≈25 s | unchanged |
   | Final validation (pre-optimization) | 31.9 s | ≈9 s |
   | — of which the bow-tie check | 19.7 s | 0.05 s |
   | **Vase run alone** | ≈250 s | **108.5 s** |

3. **Three memory-bound scans and two Amendment 33 sites** make up most of this (DESIGN Amendment 34):
   - **T-junction scan.** For each node occurrence (57,636 nodes) it reads every halfedge (168,902 halfedges, a 216-byte stride), and builds the occurrence's scoped node key for each candidate. Each key recomputes `source_vertex_extent` in O(F). The disassembly of the hot loop matches the fields `sourceFace` at offset 0x24 and `from`/`to` at 0x0c/0x10.
   - **Selection.** For each of 4,047 transactions it recounted the endpoint degrees of the whole active network into a `std::map`.
   - **Bow-tie check.** For each of 68,038 output vertices it walked the whole `edgeIncidence` map.
   - **Amendment 33 sites.** `validate_final_surface_mesh` calls `source_face_scope` once per source face (line 2627) and once per quad corner (line 2730), after already checking the binding on entry. These cost about 2 s.
4. **The fixes are exact.** Each was compared with the original by an env-switched cross-check computing both:
   - over the 893-row gate, 16,543 cross-check lines with **0 mismatches** (T-junction 110 rows, selection 117, bow-tie 158, scope 118);
   - on Vase: 4,047 selection checks, 273,720 scope checks, 68,038 bow-tie vertices and the T-junction count, all matching.
   The verdict and every count are unchanged.
5. **Linux attribution is a hypothesis, tested by TB77/TB78.** The removed scans stream about 10¹¹ bytes or chase 10⁹ map nodes. A CI runner core has several times less memory bandwidth than Apple Silicon, which explains why only Vase was slower. That runner's own timings are the test.
6. **Remaining costs, carried and not blocking.** Of the 108.5 s:
   - tracing ≈60 s, most of it inline in `make_intersection_surface_cell_proposal`;
   - completion ≈25 s;
   - validation ≈9 s, in `SourceProjectionCache::allowed_faces`.

#### RA-202.3 Rulings

1. **Withdraw `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING`.** No product stage logging; a scratch stack sample answers "where is the time" (LESSONS §5).
2. **DESIGN Amendment 34.** A pass over a mesh-sized collection reads, for each element, only what that element concerns. A transaction check on an invariant state reads only the net change. Results, visit order within an element, and failure codes are unchanged. The class is **P13-m**.
3. **Exact patches CB85–CB88, one site each; a TB after each pair:**
   - pre-assembly: CB85, CB86, then TB77;
   - validation: CB87, CB88, then TB78.
4. **Linux registration.**
   - TB77 registers both Vase outcomes, because two validation scans remain until CB87/CB88.
   - TB78 registers RED within 600 s: macOS takes 108.5 s, and even 2.4× is 260 s.
   - A timeout at TB78 goes to Review with this probe recipe. It is not an inference about which CB "did not take".
5. **New obligations:**
   - **O27:** `MeshValidator::validate_face_to_face_intersections` tests every pair of faces (O(Q²); 2.3×10⁹ pairs on Vase) with no spatial culling. Vase stops at its first intersection today. Once P13-l is fixed, the full scan runs; the P13-l DEFN must time it.
   - **O28:** nine per-query `source_face_scope` sites remain in the optimizer stage and overlay: `SurfaceMeshOptimizer.cpp` 712, 814, 848, 877, 896, 2054, 2177, 3026 and 3083. They are not on today's Vase path. Measure them when Vase reaches optimization.
   - **O29:** `source_vertex_extent` is recomputed in O(F) per edge key at about 45 call sites in tracing and the arrangement. Together with the tracing proposal cost, this is the next cost candidate.

#### RA-202.4 CB85 — `M6-CP3-CB85-P13-ARRANGEMENT-TJUNCTION-FACE-SCAN`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 2278b8b649b4262fb70a522371ed282655383af5 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan.diff"), byte for byte.
  - SHA-256 `5b6d35a4808393d7274d8f574fa4f68eb343946bc3b065f2c1e8992babcac2f7`.
  - 178 lines; keep its 2 single-space context lines.
  - Run `git apply --check`, then `git apply`.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SurfaceArrangement.h` | `3 0` | `3e13e5cb2dde969417cee460370b36ac24369769a7b9fffecf8eeb67ecba97b4` |
  | `src/geometry/SurfaceArrangement.cpp` | `25 11` | `6fa5c6c6f2a09219d0bc2d116a76e6d22152d60de76decbfff790065abd16d65` |
  | `tests/SurfaceArrangementRowIdentityTests.cpp` | `96 0` | `d3290d04c9525e48a34cb2b7fe9636346cc9d223a52b4455ed6d72a7583e8173` |

- **Content:**
  - Halfedges are indexed once by source face. Each occurrence reads its own face's list in halfedge order.
  - The occurrence's authority scope (`make_node_key` + `canonical_node_authority_scope`) is made once, at the first candidate. The halfedge contributes only `sourceTopologyRegion.value()`.
  - `SurfaceArrangementDiagnostics::geometricTJunctionHalfedgeVisits` counts the visits.
- **Test** (gate row 894, `directional_surface_cell_completion_tests`): `GeometricTJunctionScanVisitsOnlyHalfedgesOfTheOccurrenceFace`.
  - The fixture is a 30×30 grid crossed by 60 lines.
  - The visit count must equal an independent per-face recount, which is deterministic and involves no timing.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`; run no binary.
- **Outcomes:**
  - success → CB86;
  - precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TJUNCTION-STOP`;
  - infrastructure → `M6-CP3-CB85A-P13-ARRANGEMENT-TJUNCTION-ORCH` (one retry).

#### RA-202.5 CB86 — `M6-CP3-CB86-P13-SELECTION-ENDPOINT-NET-CHANGE`

Code + Build, compile only, applied on CB85.

- **Precheck:** the three CB85 result hashes above.
- **Patch:** [`Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change.diff").
  - SHA-256 `c2a0c3083df29f99b43dd953ca871f02abf7961f731b52d5de5650c0b621ae81`.
  - 167 lines; keep its 7 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/FlowRepStrands.h` | `7 3` | `034a306a4de08783b858cac1bf83c10c0298c96d48806c19abb5057a881a8c53` |
  | `src/geometry/FlowRepStrands.cpp` | `23 14` | `0e3997c89339a179f64223cd0c267b203805f3f70d0f554cf636668f5ef2b179` |
  | `tests/FlowRepStrandsPhase15Tests.cpp` | `61 0` | `6810b11d9d7a8e71062ab7b3018a126574d631bb542b1f11590f2a0e3bc70b26` |

- **Content:** `preserves_protected_endpoint_degrees(arcs, active, required)` is replaced by `transaction_keeps_protected_endpoint_degrees(arcs, removed, added, protected)`. It returns true when the net endpoint change is zero at every protected endpoint. A comment at the call site states the invariant.
- **Tests** (gate rows 895–896, `directional_surface_cell_completion_tests`):
  - `TransactionKeepsProtectedEndpointDegreesByNetChange`: removal, substitution and addition at a degree-3 junction.
  - `SelectionChecksEndpointDegreesOfTheTransactionOnly`: 8,000 transactions finish in under 2 s, with 6,000 rejected.
- **Build and outcomes:** as CB85 → TB77. The stop turn is `M6-CP3-PLAN-P13-SELECTION-ENDPOINT-STOP` and the orchestration retry is `M6-CP3-CB86A-P13-SELECTION-ENDPOINT-ORCH`.

#### RA-202.6 TB77 — `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB86's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB77_P13_Pre_Assembly_Cost_Full_Gate_Case_Manifest.tsv"), 896 rows, SHA-256 `48ef4743b18683e78d9f740c4eb0e7f249abcab78a4aeac849620e251d9fface`.
  - It is TB76's 893 rows byte for byte, plus GUARD rows 894–896.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=896 deferred=81`.
  - Pre-registered **896/896**, membership **977**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder PASS; BunnyRandom P13-e unchanged.
  - **Vase:** either RED `terminal=NotProductionReady:completion detail=SelfIntersectingFace … completedQuads=67829`, or ABNORMAL at 600 s. Both are registered, because the validation scans remain; macOS takes about 150 s, estimated from components.
  - Record the Linux Vase wall time if it completes.
  - Any other verdict, or a RED with other counts, is a mismatch.
- **Outcomes:**
  - match → CB87;
  - mismatch → `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-REV` (Review);
  - infrastructure → `M6-CP3-TB77A-P13-PRE-ASSEMBLY-COST-ORCH` (one retry).

#### RA-202.7 CB87 — `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES`

Code + Build, compile only, applied on CB86.

- **Precheck:** the CB86 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges.diff").
  - SHA-256 `eeef1a515995e032e2a35342a4b92a678c309933845c03102915c1e071f53237`.
  - 134 lines; keep its 1 single-space context line.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/MeshValidator.h` | `15 7` | `0b4025fe47f0e7208490e687fab1884f9c2139b072cec6d88391a0cb83c3c015` |
  | `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` | `81 0` | `14ac6f37155613e4377df0b3a19d80d2f5aa9a80a6fb5c5f30b09c7227ddc57c` |

- **Content:** `validate_bow_tie_vertices` lists each vertex's edge face lists once, whichever end of the edge it is. The adjacency is a set, so the result is unchanged.
- **Tests** (gate rows 897–898, `directional_surface_cell_validation_tests`):
  - `BowTieVertexReadsEdgesNamingItFirstOrSecond`: a closed fan whose centre is the first end of two edges and the second end of two reports no bow-tie; a true bow-tie is reported.
  - `BowTieCheckReadsOnlyTheEdgesOfEachVertex`: a 150×150 quad grid validates, topology only, in under 2 s.
- **Build and outcomes:** as CB85 → CB88. The stop turn is `M6-CP3-PLAN-P13-BOW-TIE-STOP` and the orchestration retry is `M6-CP3-CB87A-P13-BOW-TIE-ORCH`.

#### RA-202.8 CB88 — `M6-CP3-CB88-P13-FINAL-VALIDATION-ROW-LABELS`

Code + Build, compile only, applied on CB87.

- **Precheck:** the CB87 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB88_P13_Final_Validation_Row_Labels.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB88_P13_Final_Validation_Row_Labels.diff").
  - SHA-256 `ee12a33fedc24047a960f38a7ba04b905d54716d80ff8c40b5723614b5636640`.
  - 72 lines; 0 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/SurfaceMeshOptimizer.cpp` | `5 2` | `89d52dddb449b6f999aa32ce09e1a2d584c54838e716de0da063dac30449eb6e` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `40 0` | `acb41d05d2a6d2b1c296e65b94ef7025236b95fcf76769b72de17b742da1ced2` |

- **Content:** the two `source_face_scope` calls in `validate_final_surface_mesh` become `bound_source_face_scope`. The binding is already checked on entry, as Amendment 33 requires.
- **Test** (gate row 899, `directional_surface_cell_validation_tests`): `FinalValidationReadsSourceRowLabelsAfterOneBindingCheck`. With 28,800 source faces and 400 output quads, the timed section takes 0.7 s, against a 2 s limit; with M4 it takes 4.7 s.
- **Build and outcomes:** as CB85 → TB78. The stop turn is `M6-CP3-PLAN-P13-FINAL-VALIDATION-LABELS-STOP` and the orchestration retry is `M6-CP3-CB88A-P13-FINAL-VALIDATION-LABELS-ORCH`.

#### RA-202.9 TB78 — `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB88's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv"), 899 rows, SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`.
  - It is TB77's 896 rows byte for byte, plus GUARD rows 897–899.
  - `SELF_CHECK_PASS cases=899 deferred=81`.
  - Pre-registered **899/899**, membership **980**.
- **Census:**
  - Cylinder PASS; BunnyRandom P13-e unchanged.
  - **Vase RED within 600 s:** `terminal=NotProductionReady:completion detail=SelfIntersectingFace traceSegments=192482 arrangementCells=26817 completedQuads=67829 completion=`. macOS takes 108.5 s.
  - Record the wall time and peak RSS (macOS: 1.18 GB).
  - ABNORMAL, or any other verdict, is a mismatch.
- **Outcomes:**
  - match → the Review track continues with P13-l;
  - mismatch → `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV` (Review, which re-runs the RA-202 probe recipe);
  - infrastructure → `M6-CP3-TB78A-P13-CENSUS-PATH-COST-ORCH`.

#### RA-202.10 Turn sequence

| Step | Turn | Track |
|---|---|---|
| — WITHDRAWN | `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING` | Never applied or compiled; do not apply its preserved patch |
| 1 — NEXT | `M6-CP3-CB85-P13-ARRANGEMENT-TJUNCTION-FACE-SCAN` | Implementation agent, Linux; compile only |
| 2 | `M6-CP3-CB86-P13-SELECTION-ENDPOINT-NET-CHANGE` | Implementation agent; compile only |
| 3 | `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-EXEC` | Implementation agent; 896/896, membership 977; Vase RED or ABNORMAL (both registered) |
| 4 | `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES` | Implementation agent; compile only |
| 5 | `M6-CP3-CB88-P13-FINAL-VALIDATION-ROW-LABELS` | Implementation agent; compile only |
| 6 | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-EXEC` | Implementation agent; 899/899, membership 980; Vase RED within 600 s |
| 7 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Probe DEFN on the RA-202 scratch state; time O27 once orientation passes |
| 8 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Probe DEFN |
| 9 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–6 in order, one turn each, and starts a step only after the previous one is verified.

#### RA-202.11 Scratch verification (final state = HEAD + CB85–CB88)

| Check | Result |
|---|---|
| Gate, 899-row TB78 manifest | 898/899; only O16 row 283 (macOS) |
| GUARD rows 894–899 | PASS. Timed or counted sections: 894 0.6 s (count equal); 896 0.07 s; 898 0.05 s; 899 0.7 s |
| Ledger v5 (81 deferred rows) | 0/81, unchanged from RA-201's final state; row 365 (Vase) RED in 98.2 s |
| Census | Cylinder PASS 5.8 s; BunnyRandom P13-e unchanged (vertex 49); Vase RED `SelfIntersectingFace`, 192,482 / 26,817 / 67,829, in 108.5 s alone |
| Cross-check gate (probe, all fixes and both computations) | 892/893 (O16), 16,543 lines, 0 mismatches |

Mutants: each fails only its own CB's rows.

| Mutant | Change | Rows that fail |
|---|---|---|
| M1 | full halfedge scan | 894 |
| M2 | whole-network recount | 896 (8.8 s) |
| M2b | added arcs ignored | 895 |
| M3 | every edge per vertex | 898 (8.0 s) |
| M3b | first end only | 897 and 898 |
| M4 | per-query binding | 899 (9.1 s; timed section ≈4.7 s) |

#### RA-202.12 Probe scripts (scratch, not committed)

The scripts are in `scratchpad/tb76r/`:
- `make_m.py` writes state0 → A1–A4;
- `make_patch_m.py`, `make_manifests_m.py`, `mutate_m.py` (M1–M4), `gate_x.py` (gate with cross-check counts);
- `vase.sh BLD TAG TIMEOUT INTERVAL [fixture]` runs a census case with `sample` stacks;
- `ratio.py` computes Linux/macOS per-row time ratios;
- `children.py` breaks down a sample tree.

The probe used env switches `PROBE_M_FIX` (bits 1/2/4/8 for the fixes; 16/64/128/256 for the cross-checks) and `PROBE_M_TIME`. It has been removed from the scratch tree.

#### Review closeout

| Check | Result |
|---|---|
| Scope | Review only. No product, test, fixture, selector, benchmark or build file changed in the repository; scratch probes only. The four `.diff` files and two manifests are documents for later turns |
| Exact patches | Four files re-hash to the stated SHA-256. They apply as a chain on a clean HEAD worktree, and every result hash matches |
| Manifests | TB76 prefix byte-identical; `SELF_CHECK_PASS` for 896 and 899 cases with ledger v5 (deferred 81), harness P8 |
| Decisive claims re-derived | TB76 artifacts re-downloaded and their ZIP SHA-256 matched; Linux/macOS row ratios computed; Vase log prefixes identical on both platforms |
| Accepted selector prefix | n/a: no selector change |
| Standing state | CP2 491/491; stable 66/17/49, debt 1; ledger v5 81 deferred; selector497 and CP3 unpromoted |
| New obligations | P13-m (Amendment 34, CB85–CB88); O27, O28, O29 |
| Scratch state left | `wt61`/`bld61` = HEAD + CB85–CB88 (final state, all gate binaries built); `bld55n` = FMA-off build of the same source (producer tests only) |

## `Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md`; moved verbatim.

### RA-203 — TB78 Review: the review-boundary block, and the Vase completed-quad platform split (2026-11-04)

**Turn:** `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`. The Claude Review resumes it from the ChatGPT Review's BLOCKED checkpoint ([WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB78_REV_P13_Census_Count_Review_WIP_20261104.md")).

**Source:** HEAD `4614f6858`. `git diff --quiet 6cc50f878ef829711e16262759afb3367bec2aff HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes, so the product and test source is CB88's.

**Scratch probes** used a macOS arm64 build of exactly that tree. The tree was compared with `diff -rq` against `git archive 6cc50f878` and no file differed.

#### RA-203.1 The block

The ChatGPT Review stopped with `REVIEW_BLOCKER`. RA-202.9 requires the mismatch Review to re-run the RA-202 probe recipe, but `REVIEW_TURN_POLICY.md` §4.3 says a Review is runtime-free, and the RA-202.12 scripts are not in the repository.

1. **There is no policy conflict, and no amendment is made.**
   - §4.3 limits what a Review mutates (no product, test, fixture, selector, benchmark or build source) and what it may record as runtime evidence.
   - The standing rulings RA-166.6 F6 and RA-188.1, recorded in `LESSONS.md` ("Re-observe a deferred row…"), hold that Review scratch probes are a Review duty, not a breach. Such probes run on an uncommitted build outside the repository, and nothing they produce is reported as Test + Benchmark evidence.
   - Every P13 DEFN since RA-193 has used such probes.
   - No policy file is changed.
2. **The ChatGPT Review was right to stop.** The defect is in RA-202.9's route, not in the policy. The route has three faults:
   - **It does not name a track.** "Review, which re-runs the RA-202 probe recipe" omits "Claude, scratch build". That same omission produced the BLOCKED Review records at handoff rows 17, 20, 23, 26 and 29.
   - **The recipe cannot answer the question.** The RA-202.12 scripts are environment-switched cost probes of the P13-m sites. Nothing needs them in order to be reproduced. Re-running them on macOS gives 67,829, which is the number in question. A Linux/macOS split cannot be explained from one platform.
   - **Linux runtime belongs to the implementation agent,** as a TB with an exact command and a frozen comparator. This RA authorizes that execution: CB89 (a test-only exact patch), then TB79.
3. **Rule from now on.** A mismatch route that needs a probe names `Review (Claude, scratch build)`. A route that needs Linux runtime names the TB that collects it. A Review that cannot run a scratch probe records BLOCKED immediately and does not start the probe work.

#### RA-203.2 RA-202.9's registration error (owned)

- 67,829 has been observed only on macOS: RA-200 onward, every run, FMA on and off.
- No Linux run had reached a completed Vase count at the P13 state:
  - TB72A ended at assembly with 0 quads;
  - TB73–TB77 timed out after assembly.
- RA-202.9 nevertheless froze 67,829 as the Linux expectation.
  - That repeats the error RA-202 itself turned into a lesson ("predict the other platform from its own history"): Linux had no history for this value.
  - ORIENTATION §8 "Platform split" (RA-176, RA-179) treats any difference between builds as a determinism defect to be computed. It cannot be a registration constant.
- **What a cross-platform registration may pin:**
  - typed verdicts;
  - topological counts;
  - values already observed on the executing platform.
  
  A value seen on only one platform is recorded, not pinned.

#### RA-203.3 TB78 adjudication

Re-derived independently:
- the TB78 report;
- the WIP's independent rehash (1,806/1,806 gate entries, 9/9 census entries);
- the manifest hash `9d2c1ec5…` with its byte-identical 896-row prefix;
- the source.

| Registered (RA-202.9) | Observed (Linux, CB88 package `13358062295`) | Disposition |
|---|---|---|
| Gate 899/899, membership 980, GUARD 897–899 | 899/899, 980, 897–899 PASS | MATCH |
| Cylinder PASS | PASS, 11.69 s | MATCH |
| BunnyRandom P13-e, source vertex 49 | same | MATCH |
| Vase RED `NotProductionReady:completion detail=SelfIntersectingFace` | same | MATCH |
| `traceSegments=192482 arrangementCells=26817` | same | MATCH |
| Within 600 s | 268.93 s (TB76/TB77: ABNORMAL at 600 s) | MATCH: P13-m's Linux objective is met |
| `completedQuads=67829` | 67,784 | Registration error (RA-203.2); the split is **O30** |

**Attribution.** The 45-quad difference is not a defect of CB85–CB88:

1. **Their product hunks cannot round or reorder.** They add 78 lines with no floating-point arithmetic, hashing, sorting or unordered container, checked on the committed `.diff` files:
   - CB85 groups halfedges in a `std::map` by source face and compares integer scopes.
   - CB86 sums integer endpoint deltas.
   - CB87 builds per-vertex edge lists.
   - CB88 reuses labels.
   
   CB87 and CB88 run after the count is taken: `RemeshPipeline.cpp` 14407–14482 records `surfaceCellCompletedQuadCount` before output validation.
2. **On macOS, each fix ran beside its old computation on every call:** 16,543 cross-check lines, 0 mismatches, Vase included (RA-202.11).
3. **Linux and macOS have agreed on Vase topology through the arrangement wherever both were observed:**

   | Pair | Agreement |
   |---|---|
   | TB71 / RA-198 | 26,827 cells |
   | TB72 / RA-199 | 26,817 cells |
   | TB78 / RA-202 | 192,482 traces, 26,817 cells |

   Completion is the first stage whose count differs, and TB78 is the first Linux run that reached a completed count.

**Classification:**
- TB78 is COMPLETE.
- The count line is a Review registration error, not an executor failure.
- O30 is opened.
- No stable event: no accepted green was lost.
- Unchanged: 66/17/49, debt 1, accepted CP2 491/491. Selector497 and CP3 stay unpromoted.

#### RA-203.4 O30 — the Vase completion platform split

**Statement.** The configurations differ in platform only:
- same product source (CB88), same fixture bytes, same options;
- macOS arm64 (clang, libc++, Apple libm) completes **67,829** quads;
- Linux x86-64 (GCC, libstdc++, glibc) completes **67,784**.

Upstream topological counts are equal. Neither count is "right" until it is computed. The fix must make the platforms agree (ORIENTATION §8).

**Known on macOS:** the result repeats. Two digest runs are byte-identical (RA-203.7), and an FMA-off build is identical too (RA-202).

**Candidate mechanisms (none asserted):**
- (a) ULP differences between glibc and Apple libm in field generation or geometry, flipping a discrete decision in completion (for example a rounded segment count).
- (b) Implementation-defined order: `std::sort` ties, or unordered iteration. `PureQuadCompletion.cpp` declares seven unordered containers in assembly; `TriFlowSimplification.cpp` has more.
- (c) The x86-64 80-bit `long double` (`FieldTransportAtlas.h:522`; `NFunctionMesher.h` 7708–7797). On arm64 macOS `long double` is binary64.
- (d) Compiler codegen other than FMA.

**First discriminator: TB79's digest lines against the macOS reference.** The decision table is frozen before TB79:

| Linux vs macOS reference | Meaning | Next |
|---|---|---|
| `vertexBits` or `faceBits` differ | The fixture is read differently | Stop; fixture DEFN |
| `fieldBits` differ | The generated smooth field is not platform-invariant | DEFN inside `extract_cross_field`. Design fork: make the generator invariant, or freeze Vase's field as fixture bytes |
| Inputs equal; first differing product is S | The divergence becomes macroscopic at S | DEFN probes stage S |
| All products through `simplification` equal; `completion` differs | Completion or assembly | DEFN probes `PureQuadCompletion` (unordered containers, libm in patch sizing) |

Stage hashes quantize coordinates to 1e-9 (`hash_combine_double`). Equal hashes therefore bound where the divergence becomes visible, not where it begins.

**Second discriminator** (Review track, only if the first leaves (a) against (b) open): a GCC + libstdc++ build of the same tree with `-ffp-contract=off` on macOS arm64. It keeps Apple libm, so it separates library order and codegen from libm and `long double`.

#### RA-203.5 CB89 — `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST`

Code + Build, test-only, compile only.

- **Precheck:** `git diff --quiet 6cc50f878ef829711e16262759afb3367bec2aff HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB89_P13_Census_Platform_Digest.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB89_P13_Census_Platform_Digest.diff").
  - 68 lines, SHA-256 `64af5c71ad57a662724b077761f71c1c38893be6ed32516fc568166e85c23f71`.
  - Keep its 3 single-space context lines.
  - Numstat `45 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`.
  - Result SHA-256 `ba60c6905db983b53c35a2b5e909a04152eaa557cac8382c84457c5d0f5b1941`.
- **Content:** after the remesh call, `ProducesDirectSourceAuthoritativePureQuadOutput` prints one line, then runs unchanged:

  ```text
  platform-digest case=<name> vertexBits=… faceBits=… fieldBits=… <product>=<structural hash>/<count> …
  ```

  - The three `…Bits` values are FNV-1a over the exact IEEE-754 bit patterns, row-major, low byte first.
  - The products are `RemeshResult::surfaceCellContext.debugProducts`, which the pipeline records for every stage even with `preserveDebugArtifacts=false`.
- **What it does not change:**
  - no product source;
  - no new test, so the test listing and gate membership are unchanged;
  - no changed assertion or failure message, so the registered terminal lines stay byte-identical.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.
- **Outcomes:**
  - success → TB79;
  - precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-CENSUS-PLATFORM-DIGEST-STOP`;
  - infrastructure → `M6-CP3-CB89A-P13-CENSUS-PLATFORM-DIGEST-ORCH`.

#### RA-203.6 TB79 — `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, on CB89's immutable package.

- **Gate:** [TB78 manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv"), reused unchanged.
  - 899 rows, SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`; ledger v5 `fd433f54…`.
  - Registered **899/899**, membership **980**.
  - The raw logs of rows 795 (CloseSheets), 796 (MultiFaceSeam), 797 (Plane) and 864 (Cylinder) each contain exactly one `platform-digest` line.
- **Census:** three-case manifest `3af1dc0d…`, 600 s ceiling.
  - Cylinder PASS.
  - BunnyRandom RED `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`.
  - **Vase RED within 600 s:** `terminal=NotProductionReady:completion detail=SelfIntersectingFace traceSegments=192482 arrangementCells=26817 completedQuads=67784 completion=`. This is TB78's Linux value, so the run also tests repeatability on Linux.
  - Each census log contains exactly one `platform-digest` line.
- **Record:** the seven digest lines, verbatim. They are the measurement, not a criterion. TB79 makes no comparison claim.
- **Outcomes:**
  - match → Review `M6-CP3-DEFN-P13-PLATFORM-SPLIT` (O30; Claude, scratch build; decision table RA-203.4).
  - mismatch → `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-REV` (Review, Claude, scratch build). A mismatch is any of:
    - Vase `completedQuads` other than 67,784 (Linux nondeterminism, a separate class);
    - any other verdict change;
    - a missing or duplicate digest line.
  - infrastructure → `M6-CP3-TB79A-P13-PLATFORM-DIGEST-ORCH`.

#### RA-203.7 macOS reference (scratch: CB88 source + CB89)

[`Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv"): 129 rows (case, item, value, count) for Plane, MultiFaceSeam, CloseSheets, Cylinder, BunnyRandom and Vase. SHA-256 `7e2796fe4991553becf1006d400f288368fe9c9781a6bc0d154faaaa821a167e`; checked against the raw logs.

| Vase item | macOS value / count |
|---|---|
| `vertexBits` / `faceBits` / `fieldBits` | `eef00a8706c009f5` / `e43da6cccb821779` / `afdad15a6d246ed2` |
| `cross-field` | `8e16b454468fe056` / 2404 |
| `field-transport-atlas` | `2e362a754c773930` / 4668 |
| `tracing` | `bbb3c00341039362` / 192482 |
| `strands` / `embedding` | `239f4ed9d48125e3` / 30989; `909330af789bee4c` / 30989 |
| `arrangement` = `simplification` | `611e5aa5aabed428` / 26817 |
| `completion` | `d711fde270eada71` / 67829 |

- Two Vase processes produced byte-identical digest lines and the same terminal: 98.8 s, 1.22 GB peak RSS.
- BunnyRandom's line ends at `source-labels`, because it fails at the field-transport atlas.

#### RA-203.8 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 42A — Review COMPLETE | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV` | ChatGPT WIP (BLOCKED on the review boundary), then RA-203 |
| 42B — NEXT | `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST` | Implementation agent, Linux; compile only |
| 42C | `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC` | Implementation agent; 899/899, membership 980; Vase 67,784; seven digest lines |
| 42D (Review, after TB79) | `M6-CP3-DEFN-P13-PLATFORM-SPLIT` (O30) | Claude, scratch build; RA-203.4 table → exact fix or the second discriminator |
| 43 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build. Its later TB pins only typed verdicts and counts already observed on Linux |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Claude, scratch build |
| 45 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes rows 42B and 42C, one turn each. It starts 42C only after 42B is verified. Rows 42D, 43 and 44 are Review-track probe turns (Claude, scratch build).

#### RA-203.9 Scratch verification

| Check | Result |
|---|---|
| Scratch tree = CB88 source | `diff -rq` against `git archive 6cc50f878` (`src include tests benchmarks cmake`, `CMakeLists.txt`): no differences |
| CB89 on a clean worktree at HEAD `4614f6858` | Precheck passes; `git apply --check` and `git apply` succeed; numstat `45 0`; result hash as above, byte-identical to the scratch file |
| Test listing | Same 614 producer-test names as the CB88 binary (sorted full names identical) |
| Compilers | clang (Apple, `-O3`) compiles and runs it. GCC 16 `-std=gnu++20 -Wall -Wextra -fsyntax-only` with the CI defines accepts it, with no diagnostic on the added lines |
| macOS census with CB89 | Plane, MultiFaceSeam, CloseSheets and Cylinder PASS; BunnyRandom P13-e RED; Vase RED, 192,482 / 26,817 / 67,829; one digest line per case; Vase repeat byte-identical |

The scratch build relinked only the producer test binary against CB88's static libraries. The macOS periodic `/tmp` cleaner had removed `build.ninja` and most objects from the scratch build.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB78 manifest `9d2c1ec5…` re-hashed by the WIP and re-checked here; its 896-row prefix is byte-identical to TB77 `48ef4743…`. Accepted CP2 selector unchanged |
| Decisive claims independently re-derived | Source equality with CB88 (`git diff --quiet`, `diff -rq`); CB85–CB88 product hunks scanned for floating-point, hash, sort and unordered constructs (none); the history of Linux and macOS topological counts (TB71/RA-198, TB72/RA-199, TB78/RA-202); the macOS Vase count and digests from two fresh processes |
| Non-vacuity checked | The digests are bit-exact for inputs and per-stage for products. Two runs agree on macOS, so a Linux difference cannot be noise from the printer. Missing or duplicate digest lines are a TB79 mismatch, so a binary without CB89 cannot pass silently |
| Prior obligations discharged/carried | P13-m: Linux objective met (268.93 s), discharged for cost. O27, O28, O29 carried (Review P13-l). P13-l and P13-e carried. O16, O19, O6, O9, O25, O26, DR1/DR3 carried. DR2/DR4 stay with M8-CP2 |
| Stable accounting | 66 / 17 / 49, debt 1; accepted CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O30 (Vase completion platform split): tracker, ORIENTATION §7, TODO |
| ORIENTATION currency line | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`, 2026-11-04 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 M6-CP3 row updated; §4 n/a (no fixture change); §7 Immediate, P13-m, O30 and priority row updated; §8 "Platform split" extended to registrations |
| CHANGELOG | RA-203 entry added |
| ROADMAP | n/a: no milestone or checkpoint state changes |
| Selector manifest | n/a: TB79 reuses the TB78 manifest unchanged; no new rows |
| LESSONS | Amended the RA-202 lesson ("Time the whole run…") with registrations from one platform |
| Consolidation under CLEAN_UP_POLICY | The handoff's older "Earlier" sections are folded to links (their facts are in TODO, CHANGELOG and the records). The ChatGPT WIP is retained as evidence, with a closure line |
| Successor frozen | `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST` (RA-203.5); TB79 falsifiers in RA-203.6; O30 decision table in RA-203.4 |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; the patch is a committed `.diff`. Scratch probes only (RA-203.1) |
| review_check.py boundary | `boundary`: ALL CHECKS PASSED; `ledgers --base d8c24645b`: ALL CHECKS PASSED (CHANGELOG and LESSONS did not shrink) |
| `STATUS` lifecycle maintained | Turn `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`, COMPLETE, Successor `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST`, Started at 2026-11-04T21:08:48Z (preserved), Resumed at 2026-11-04T22:20:08Z, Ended at the final write; the canonical block only |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the final push |

## `Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md`; moved verbatim.

### CB92 — Canonical source-vertex fan seed identity (frozen implementation plan, 2026-11-05)

> **Superseded by [RA-207](#architecture_m6_cp3_defn_p13_row_permutation_seeds_review_fan_seeding_20261105md "moved: Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md") §3.** The implementation applies the exact patch `Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity.diff`: per-fan seeding (the both-sides rail rule), not fail-closed. The mechanism and evidence below stand. The multi-fan fail-closed policy and the four-Vase product test are withdrawn (RA-207.2).

**Predecessor:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a Review). **Only authorized implementation successor once the Review is formally closed:** `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY`. This plan is metadata, not a code naming rule. Do not begin this work while predecessor STATUS remains IN_PROGRESS.

#### Independent evidence and mechanism

- Actual Vase, four consistent source-face-row permutations, unmodified producer: first divergent phase is relief-critical/root vertex seeding, count **1,456/1,460/1,458/1,455** under this run's exact recipe. `vertex_point` picks the first face row and `initialize_seed` deduplicates on (face row, quantized barycentrics), silently suppressing vertex-seed requests when they collide with earlier hard-rail samples. Source-row order changes the collision.
- Independently compiled scratch candidate based on `SourceChartTransitionGraph` resolves `SourceVertexEntityIdentity(component, vertex, fan)`; all four Vase traces of corrected seed capture emit **1,416** semantic-equal coverage seeds, sorted `origin|sourceId|printed position` SHA-256 `7f299f1f1a1b2c99a5f170e316a828357545cb9da96154c3c5e9e46b4725042c`. This is scratch evidence, NOT a product test.
- Protected-edge split/coalescence with exact typed fan IDs and two source-face orders PASS in isolated `O32aScratchFanSafety` on compiled artifact `13415119500`.
- Valid adjacent rails sharing a source vertex have **both distinct typed rail intervals and owners** (2/2 focused controls PASS), compiled scratch `12f926bf56f0996d6351b2cf68705dde02f0935b`, run `42034591362`, artifact `13418271529`, SHA-256 `05436c29810164e8aaf8c43a098965a91bc84314dc855630eb2690ee8693e145`. Tampering typed source-edge list yields `TypedAuthorityMismatch`; duplicate rail ID yields `DuplicateRailId`. An earlier one-sample-per-rail test was **invalid** for strict rail intervals and its missing coincident seed annotation is NOT evidence of rail-edge loss.
- Full corrected scratch Vase base+perm1+perm2+perm3 remains `SelfIntersectingFace` RED, with 189,462 traces, 30,989 strands, 26,817 arrangement cells, but 67,750/67,782/67,766/67,778 completed quads. O32b–e remain **separate**; do not attempt to fix their order sensitivity in CB92.

#### Frozen source-fan admission contract (O32a Review, 2026-11-05)

**Positive source authority proved:** independent static audit of the immutable `benchmarks/fixtures/milestone-g/vase.off` bytes (SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`) reads 1,274 vertices, 2,404 oriented faces, 142 source-boundary edges, 0 nonmanifold edges, 0 inconsistent paired orientations. With the capture's zero explicit hard-feature edges, all 1,274 vertex incident-face stars have exactly **one connected intrinsic fan**. The accepted scratch 1,416-seed equality consequently exercises the unambiguous one-fan path. It does **not** validate fan duplication.

**Source-derived information limit:** `SourceChartTransitionGraph` publishes distinct typed `SourceVertexEntityIdentity(component,vertex,fan)` at hard-barrier wedges, but `ReliefCriticalPoint`, `reliefRootVertices`, `reliefCriticalVertices`, `separatrixVertices` and `anchors` supply only vertex indices. `FieldAlignedSingularityPort` supplies component and topology region but not fan or source-face attachment; two fans separated by a hard feature can share both. The earlier green `O32aScratchFanSafety` synthetic test with `reliefCriticalVertices={0}` and two hard-barrier fans demonstrates typed graph connectivity and row-invariant fan identities, **not independently authorized two-fan seed ownership**. Do not convert its synthetic expected count to a production acceptance oracle.

**Exact safe admission decision:** When source authority is present, resolve each vertex-origin request to incident typed fan identities, respecting any independently owned component/region scope present in the producer. If the admissible set contains **one** fan, select the minimum canonical `SourceProjectionChart` *inside that fan* and deduplicate against previous semantically equivalent seeds there, preserving provenance priority and existing rail ownership. If the request has **multiple** admissible fans but does not carry a typed fan/face/owner-side selection, do not choose a face by row, choose an arbitrary fan, or emit one seed per fan. **Fail closed with an explicit typed source-seed-scope rejection and no consumable partial network.** CB92 must wire this rejection through the existing `SurfaceCellNetwork`/pipeline outcome; an uncaught `invalid_argument` is not an acceptable substitute. If no truthful existing failure reason supports it, STOP for a narrowly scoped Review amendment of the failure contract; do not mislabel valid topology as invalid or add a silent fallback. For truly independently producer-owned scoped obligations, exact source support may narrow to one fan; until documented by source authority, the vertex index does not.

This rule is a bounded conservative admission policy, **not a claim that valid multi-fan source vertices can never be seeded**. Fan-scoped seeding beyond it is deferred to independently published source-owner authority and its own non-vacuous tests. The unqualified multi-fan input is an **unresolved semantic scope**, not a reason to invent a second copy of the field/relief authority.

#### Bounded product edit

In the existing source seed-generator flow (`src/geometry/SurfaceCellTracing.cpp`) when a valid `SourceTopologyRegions` source authority exists, reuse the existing `SourceChartTransitionGraph` with the existing combined hard-barrier set; index occupied mandatory rail endpoint **typed vertex fans**, not raw row/barycentric coincidences. For each vertex-origin class (singularity, relief critical/root, uncovered relief-region representative, separatrix, anchor), enumerate valid incident source charts and resolve exact `SourceVertexEntityIdentity`. Admit only when the producer-owned request unambiguously resolves to **one authorized fan**: use the minimum canonical `SourceProjectionChart` within that fan, match semantically equivalent previous seeds, preserve existing provenance priority and the original vertex ID. A request that has several admissible fans without independently scoped ownership must **fail closed via a typed terminal outcome** without fabricated fan-wide duplicates; never silently select an arbitrary fan or throw an uncaught exception. Single-fan source authority on Vase is independently established; ambiguity under hard-feature split is not authorization. Reuse the current `append_seed` and typed products; do not invent parallel canonical-ID types. Keep authoritative rail sampling, paired side charts, rail intervals, and their typed `HardRailId` ownership unchanged. Legacy no-source-authority diagnostics must retain their existing documented contract, and cannot be used to claim source-authoritative permutation invariance. Remove all scratch dumps, environment knobs, intentional exceptions, and row-dependent capture code from product.

A mechanically smaller patch limited to relief-root vertices is **not** sufficient unless independently proved that singularity/separatrix/anchor and relief-region representative paths have no corresponding source-row collision. Do not add duplicate coincident seeds solely to satisfy the invalid scratch test.

#### Required predeclared falsifiers (independent tests, no weakened assertions)

1. On four consistent Vase face/field permutations (same vertex, face semantic and field records), compare the full sorted canonical seed inventory, count, provenance and exact typed source-fan membership. Different positions, identities, counts or an unowned fan is RED. Include a mutation/negative control that restores face-row `vertex_point(...).front()` so the test proves non-vacuity.
2. On a valid two-face interior hard barrier: graph split vertex fan identities must be two and stable in both face row orders; without that barrier the graph coalesces to one. For a raw unscoped `reliefCriticalVertices={0}` request, assert **typed fail-closed seed-scope rejection** in the split case, **one admissible fan seed** without the barrier. A synthetic two-seed success assertion is not a semantic permission oracle. Explicitly assert `SourceVertexEntityIdentity` sets, terminal typed failure, and no partial consumable network. If an existing typed source-owner binding uniquely selects one side, assert precisely that one fan; mutate the binding and demand rejection.
3. For **two strictly valid adjacent rails** sharing a source vertex, independently call typed rail-interval ingress: both `HardRailId`+source-edge interval pairs must be retained; remove one typed source edge or duplicate an ID and require the expected typed rejection. Do not assert two distinct coincident trace seeds where the contract does not require them.
4. Exercise the field-aligned singularity path, relief-critical/root/region representative paths, separatrix and anchor paths, provenance priority and source IDs; test no-authority diagnostic behavior separately, without treating it as source-authoritative proof.
5. Compile with GMP/GMPXX through the existing remote compile workflow; preserve exact source SHA, artifacts, 23+/23+ package checksums and source status. Do not locally build. **Stop** if exact semantic fan admissibility cannot be established, mandatory rail intervals disappear, the protected-edge test fails, formerly accepted tests regress, or source authority is invalid; return to Review rather than paper over a red.
6. A later separately authorized TB turn runs immutable full required gate, census, row-permutation checks and stable-regression accounting. **No selector497/CP3 promotion here.** O32b/c/d/e remain independently owned downstream.

**Scope:** one producer source unit plus directly necessary existing test source; no new dependency, fixture, selector, unrelated fallback, tracing/strand/arrangement/completion repair or workflow permission change. Maintain accepted CP2 491/491 and stable 66 events/17 categories/49 recurrences, debt1.

## `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Probe_Adjudication_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Probe_Adjudication_20261105.md`; moved verbatim.

### RA-208 — P13-l resolved: the block, the measured owners, and exact CB93/CB94 (2026-11-05)

> **Reviewed by [RA-209](#architecture_m6_cp3_defn_p13_completed_mesh_orientation_review_single_writer_own_plane_20261105md "moved: Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md").** The census and CB93 stand; CB93 is applied at `e96e98806`. The rest is superseded:
> - the orientation pass must be removed (single writer; 0 flips in production);
> - both embedding predicates must project orthogonally onto the quad's own plane, because the axis projection accepts 17 genuinely twisted Vase quads;
> - "35,416 → 4" relied on that blind spot.
>
> CB94 to CB96 and TB83 are replaced, and the RA-208 CB94 diff and TB83 manifest are removed (never applied).

**Turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`, resumed from the ChatGPT Review's BLOCKED checkpoint. See its [WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_WIP_20261105.md").

**Source:** HEAD at CB92's semantic source `d9921cdd5`. `git diff --quiet d9921cdd5 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes.

**Scratch build:** `bld55n`, FMA-off clang/libc++ static, synced to HEAD and checked with `diff -rq`. Its census test was given a scratch-only dump (`PROBE_DUMP_ORIENT`) that writes the existing rejected-result snapshots: `surfaceCellContext.completedQuads` (pre-orientation), `productSnapshots.optimizationResult.quads` (post-orientation), vertices, quad lineage, vertex provenance and `strictValidationIssues`. The dump is not part of any patch. The census tools are `scratchpad/p13l/tools/*.py` (numpy, exact edge census).

#### RA-208.1 The block

The ChatGPT Review stopped with `REVIEW_BLOCKER`: the snapshots need a new Directional runtime, and it held that a Review cannot run one without a diagnostic CB/TB.

- **There is no policy conflict, as RA-203.1 already ruled.** Review scratch probes are a Review duty (RA-166.6 F6, RA-188.1). This turn was assigned to "Review (Claude, scratch build)" (handoff row 43B). A Review that cannot run a scratch probe records BLOCKED; it does not route evidence collection through the implementation agent.
- **A diagnostic CB/TB is the wrong tool.** It would spend two implementation turns and add test-only export code to the gate just to obtain data that one scratch run produces in 98 s.
- **The WIP's static work was right, and it is used here.** In particular:
  - the existing rejected-result return channel holds both matrices;
  - the first-triangle orientation and projection defects, with their integer witnesses;
  - the A–F decision table.
- No policy changes.

#### RA-208.2 Measured on CB92 Vase (macOS, one run; 67,961 vertices, 67,750 quads)

| | Pre-orientation (stitched completion) | Post-orientation (`orient_quads_to_source_normals`) |
|---|---|---|
| Undirected edges / boundary / non-manifold | 135,710 / 420 / 0 | identical set |
| **Same-direction interior edges** | **0** | **27,597** (all introduced; 19,086 cross-patch, 8,511 intra-patch) |
| Quads inverted against the source (whole-polygon Newell vs source normals) | **0** | 7,630 |
| Quads whose first-triangle normal disagrees with their whole polygon | 7,904 | — |
| Quads reversed by the helper | — | **7,630, every one already agreeing with the source** |
| Validator first-triangle local crossing | 447 | 248 |
| Completion's predicate (Newell dominant axis, eps 1e-13 or tol 1e-9) | **0** | **0** |
| Validation issues | — | FlippedFace 35,164; SelfIntersectingFace 249 (248 local, 1 global); GeometricVertexOnUnsplitEdge 3 |

**Classification against the WIP's A–F table:**
- **B is confirmed and dominant.** Completion's output is consistently oriented and agrees with the source. The helper's first-triangle test then reverses 7,630 correct quads.
- **E/F are confirmed.**
  - The validator's local crossing projects along the first triangle's normal. That axis depends on which corner starts the cycle and on its direction, so the verdict does too: 447 quads before the helper and 248 after, against 0 under completion's whole-polygon definition.
  - In a projection-free check, few of the 248 cross: 11 in the quad's own Newell plane, 17 in the source-normal plane.
- **D is present and small.**
  - The global intersection is between faces 55 (patch 118) and 15372 (patch 54), which overlap over source face 1263. Neither face was flipped.
  - There are 3 T-junctions:
    - vertices 35161 (t = 0.0007) and 53049 (t = 0.0000) lie on edges (4618, 35159) and (28576, 53051) at about 5e-8 distance: unmerged near-coincident vertices;
    - vertex 35160 lies at t = 0.5003 of edge (4618, 35159), between patches 4955 and 4957: a side-subdivision mismatch.
- **A is excluded** on Vase: there were 0 conflicts before the helper.

**With both fixes (scratch):**
- 0 flips, 0 same-direction edges and 0 FlippedFace;
- 0 local self-intersections;
- the issues fall from 35,416 to **4**: 1 global `SelfIntersectingFace` and 3 `GeometricVertexOnUnsplitEdge`;
- the terminal is still RED `SelfIntersectingFace`, now meaning the genuine overlap.

#### RA-208.3 CB93 — `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` (exact)

- **Precheck:** `git diff --quiet d9921cdd5a174bbb00b68387082cf08df80f97c5 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB93_P13_Orientation_Whole_Quad_Normal.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB93_P13_Orientation_Whole_Quad_Normal.diff").
  - SHA-256 `2510e2ddefa717eb71cf50174c29b461713caa5588e61382aab926ef48deebfe`.
  - 94 lines; **keep its 2 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/pipeline/RemeshPipeline.cpp` | `13 4` | `5bb0277ca708e5a34f3ed5416c5d69039526b06806c8dd73de0f40f1dd7a3a31` |
  | `tests/SurfaceCellDesignAcceptanceTests.cpp` | `15 0` | `48bd985008a3803b6cdcadaa90ecf244f980ad4c5e20d76c56da2e0419935a1e` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `31 0` | `3e8604cd3c0d0229bcb7ceac2331d6888094d987bf1220253a7d8434f5ac0fe8` |

- **Content:**
  1. `orient_quads_to_source_normals` compares the source normal with the **whole-polygon Newell vector area** instead of the first triangle's normal. This is the predicate completion's `quad_embedding_failure` already enforces.
  2. The census digest line gains ` validationIssues=<n>` plus counts per failure name, so a census shows every check a RED output fails.
  3. New test `SurfaceCellsPhase10.SourceOrientationKeepsAWholeQuadThatAgreesWithTheSource` uses the WIP's two-quad witness:
     - Q0 (signed double area +19, first triangle −1) and its neighbour stay unchanged;
     - a clockwise quad is still reversed.

     It **fails on the legacy helper**, which flips Q0.

#### RA-208.4 CB94 — `M6-CP3-CB94-P13-QUAD-SELF-INTERSECTION-CORNER-ORDER` (exact, applied on CB93)

- **Precheck:** the three CB93 result SHA-256 values above, and the CB93 source commit.
- **Patch:** [`Architecture_M6_CP3_CB94_P13_Quad_Self_Intersection_Corner_Order.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB94_P13_Quad_Self_Intersection_Corner_Order.diff").
  - SHA-256 `a15632d1ba9149c7fbb47bba6fae71db56c34de999debd2977cc797d51a7ef91`.
  - 88 lines; **keep its 2 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/MeshValidator.h` | `19 1` | `892f00196bc57aa6fb739a9c5e8049693d20d580ff5490c954578c830c4b715f` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `41 0` | `dc7a6f1169413201d0a2047a787ec76e15b74ea80d1af99d700d845c1c8a9116` |

- **Content.** `MeshValidator::quad_self_intersects` projects along the **Newell normal**, which is invariant to the starting corner and the direction. A quad whose vector area is at most `tolerance · longestEdge²` is reported as self-intersecting: a symmetric bow-tie has no embedding, and completion rejects it as `DegenerateNormal`.
  - Without that rule, gate row 734 (`MeshValidatorDetectsDuplicateAndInvalidFaces`) went RED in scratch.
  - The validator keeps its own implementation (DESIGN §9 independence). Only the definition is shared with completion.
- **New test:** `SurfaceCellsPhase10.QuadSelfIntersectionDoesNotDependOnCornerOrder` checks the WIP's non-planar witness and a symmetric planar bow-tie in all 8 corner orders:
  - the non-planar witness gets the same verdict in every order;
  - the bow-tie is flagged in every order.

  It **fails on the legacy validator**: the forward cycle is false and the reversed one true.

**Verified in scratch (both CBs, applied in sequence on a clean `f8a0c1b35` worktree; byte-identical to the scratch tree):**

| Check | Result |
|---|---|
| 903-row local gate | **902/903** (only row 283, O16); rows 734, 902 and 903 PASS |
| Census digest lines, all six fixtures | **identical** to the post-CB92 build apart from the new suffix |
| Suffix, Plane / MultiFaceSeam / CloseSheets / Cylinder | `validationIssues=0` |
| Suffix, Vase | `validationIssues=4 GeometricVertexOnUnsplitEdge=3 SelfIntersectingFace=1` |
| Both new tests on the legacy files | FAIL |
| GCC 16 `-Wall -Wextra -fsyntax-only` on every changed unit | clean |

**Build (each CB):** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.

**Routes:**

| CB | Mismatch | Infrastructure |
|---|---|---|
| CB93 | `M6-CP3-PLAN-P13-ORIENTATION-WHOLE-QUAD-STOP` | `M6-CP3-CB93A-P13-ORIENTATION-WHOLE-QUAD-ORCH` |
| CB94 | `M6-CP3-PLAN-P13-QUAD-SELF-INTERSECTION-STOP` | `M6-CP3-CB94A-P13-QUAD-SELF-INTERSECTION-ORCH` |

#### RA-208.5 TB83 — `M6-CP3-TB83-P13-ORIENTATION-PREDICATE-FULL-GATE-EXEC` (after CB94)

- **Package:** the immutable CB94 package, which contains CB93.
- **Gate:** [`Architecture_M6_TB83_P13_Orientation_Predicate_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB83_P13_Orientation_Predicate_Full_Gate_Case_Manifest.tsv").
  - 903 rows, SHA-256 `20dc101d78889dc98adf4a048fb253ec66c4fda640e76247a0d5d9f4a92d57fb`.
  - TB82's 901 rows byte for byte, plus GUARD rows 902–903.
  - `SELF_CHECK_PASS cases=903 deferred=81`.
  - **903/903**, membership **984**.
- **Census:** manifest `3af1dc0d…`.
  - Cylinder PASS.
  - BunnyRandom P13-e at vertex 49.
  - Vase RED within 600 s, `detail=SelfIntersectingFace`.
- **Pinned digests:**
  - gate rows 795, 796, 797 and 864, and census Cylinder: byte-identical to TB82, followed by ` validationIssues=0`, which a PASS entails;
  - census BunnyRandom: byte-identical to TB82, with no suffix;
  - census Vase: byte-identical to TB82 through its last product item, followed by a ` validationIssues=` suffix that **contains no `FlippedFace`**. Its counts are recorded; macOS gives 4.
- **Routes:**
  - match → the Review track (RA-208.6);
  - mismatch → `M6-CP3-TB83-P13-ORIENTATION-PREDICATE-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB83A-P13-ORIENTATION-PREDICATE-ORCH`.

#### RA-208.6 Trajectory and turn sequence

P13-l splits into two parts:
- **P13-l1 (orientation and predicate)** is owned by CB93/CB94.
- **P13-l2, the genuine residue:** 1 overlap and 3 T-junctions. It goes to the Review DEFN `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP`, which starts from RA-208.2's witnesses:
  - near-coincident unmerged vertices → stitch identity;
  - midpoint side mismatch → side subdivision across patches 4955 and 4957;
  - the patch 118 / 54 overlap → arrangement or completion.

The pre-optimization quality question the WIP raised is moot for Vase: every remaining issue is a safety class. It is carried to the Vase PASS re-census.

| Step | Turn | Track |
|---|---|---|
| 43A — COMPLETE | `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY` | `d9921cdd5` |
| 43C — COMPLETE (MATCH) | `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC` | 901/901 |
| 43B — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | ChatGPT WIP (BLOCKED), then RA-208 |
| 43D — NEXT | `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` | Implementation agent; RA-208.3 |
| 43E | `M6-CP3-CB94-P13-QUAD-SELF-INTERSECTION-CORNER-ORDER` | Implementation agent; RA-208.4 |
| 43F | `M6-CP3-TB83-P13-ORIENTATION-PREDICATE-FULL-GATE-EXEC` | Implementation agent; RA-208.5 |
| 43G (Review, after TB83) | `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2) | Claude, scratch build |
| 44 / 44A / 44B / 44C | P13-e; O31; O32e → d → b/c; O33 | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The 903-row manifest's 901-row prefix is byte-identical to TB82's (`9fbf3291…`); self-check PASS |
| Decisive claims independently re-derived | The return channel confirmed on a real run. An exact directed-edge census before and after. The predicate comparison over all 67,750 quads. Issue origin split. Both fixes measured end to end |
| Non-vacuity checked | Both new tests fail on the legacy code. Row 734 caught the degenerate bow-tie gap in the first CB94 draft |
| Prior obligations discharged/carried | P13-l → P13-l1 (CB93/CB94, TB83) and P13-l2 (DEFN). P13-e, O30b, O31, O32b–e, O33, O27–O29, DR1/DR3 carried |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | P13-l2 (overlap and T-junction witnesses) |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`, RA-208 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 and §8 updated; §3 and §4 unchanged |
| CHANGELOG | RA-208 entry |
| ROADMAP | n/a |
| Selector manifest | New 903-row TB83 manifest, self-checked |
| LESSONS | A geometric predicate must not depend on corner order; pipeline and validator must share one definition |
| Consolidation under CLEAN_UP_POLICY | The WIP is retained with a resolution line |
| Successor frozen | CB93, CB94, TB83 (exact) |
| Turn boundary held | No product, test, fixture or build source changed in the repository; the patches are committed `.diff`s; the manifest is new. Scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Re-entry beacon pushed in canonical form. The non-canonical `Blocker` lines are dropped. COMPLETE with Successor CB93 is the final write. This Review's work began at 2026-11-05T18:42:39Z. A ChatGPT session resumed the same turn at 19:09:27Z and produced no record |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md`; moved verbatim.

### RA-209 — Review of RA-208: the orientation pass must go, and both embedding predicates must project onto the quad's own plane (2026-11-05)

**Reviewed turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` ([RA-208](#architecture_m6_cp3_defn_p13_completed_mesh_orientation_probe_adjudication_20261105md "moved: Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Probe_Adjudication_20261105.md")), in an adversarial re-entry.

**State:**
- The implementation agent applied RA-208's CB93 at `e96e98806` (result hashes verified) and is compiling it under STATUS `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` IN_PROGRESS.
- RA-209 does not touch that turn. CB93 completes as frozen, and RA-209 replaces everything after it.

**Scratch build:** `bld55n` (FMA-off, static), synced to the trees named below and checked with `diff -rq` or `cmp`. The scratch census test adds the env-gated `PROBE_DUMP_ORIENT` snapshot dump; it is not in any patch.

#### RA-209.1 What RA-208 got right

- The block resolution.
- The pre/post census:
  - completion's stitched output has 0 same-direction edges and 0 source-inverted quads;
  - the first-triangle orientation pass reverses 7,630 correct quads;
  - the first-triangle validator projection depends on corner order.
- The residue's location: 1 overlap and 3 T-junctions.
- CB93's whole-quad normal is a correct predicate. Its two-quad test is sound.

#### RA-209.2 Defects in RA-208 (my own)

1. **It repaired a component the architecture forbids instead of removing it.**
   - DESIGN §3 says downstream stages "validate or consume authority; they never recreate it".
   - DESIGN item 4 says no stage "may … edit, repair, re-solve, or re-derive an earlier stage's immutable product".
   - M2 says consumers "may validate it; they do not rewrite".
   - `orient_quads_to_source_normals` rewrites completion's orientation after completion. Completion already rejects every quad whose whole-polygon normal is more than 60° from its source normal; this is gated by rows 874 and 875.
   - **Measured:** with CB93's predicate, the pass flips **0** pipeline quads across the full 903-row gate and the five-fixture census, Vase included. The only flip it ever makes is the deliberately inverted quad in CB93's own unit test.
   - It is a dead second writer. It also projects centroids onto the unrestricted source, so on close sheets it could pick the wrong sheet and invert a correct quad. **Remove it.**
2. **CB94 adopted completion's axis projection, which accepts genuinely self-intersecting quads.**
   - RA-208 measured crossings in the quad's own Newell plane and in the source plane, and still chose a predicate that projects along the coordinate axis nearest the normal. That axis can be up to 55° off.
   - Over all 67,750 Vase quads: **17 cross in their own plane** and 31 in the source-normal plane (36 together).
   - **12 of them are bow-ties in both planes:** two reflex corners against each normal, and diagonal dihedrals up to 178.7°.
   - Completion's axis predicate accepts all 17, and so did RA-208's CB94. The order-invariant and faithful definition is **orthogonal projection onto the Newell plane**, in both producer and validator, each with its own implementation (DESIGN §9).
3. **The success claim was inflated.** RA-208 reported "Vase 35,416 → 4 issues". The 4 held only because the validator shared completion's blind spot. Under the faithful definition the validator alone reports 21 (17 twisted quads, 1 overlap, 3 T-junctions). Only with the producer also fixed (CB96) does Vase return to **4 validator-reported issues**. Their physical causes were not yet independently adjudicated at RA-209; the later [P13-l2 Review](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_PreStitch_Vector_ABI_Probe_Review_20261106.md") proves a false-positive overlap and identifies separate completion and source-support defects. Do not interpret the four reports as four independently certified physical intersections.
4. **Minor:** CB94's degenerate rule compares the vector area with `tolerance · longestEdge²`. That makes the geometric tolerance act as a dimensionless ratio, inconsistent with its absolute use in `ZeroAreaFace`. The criterion is scale-invariant (area/L² ≤ 1e-9) and has no false positive on any fixture; it is kept, and the comment states it.

#### RA-209.3 Realigned turns (exact; each applies on the previous one's result)

**CB93 (in progress, unchanged):** RA-208.3, applied at `e96e98806`. Finish its compile.

**CB94 — `M6-CP3-CB94-P13-ORIENTATION-SINGLE-WRITER`**
- **Precheck:** `git diff --quiet e96e98806cf5fd055df3dd45c629f124c77c5dd5 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB94_P13_Orientation_Single_Writer.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB94_P13_Orientation_Single_Writer.diff").
  - SHA-256 `a19dd0cde27d1a95f24f4c40ec89d9264fdb44f5aae59da75af5abb1465e52b7`.
  - 183 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/pipeline/RemeshPipeline.h` | `0 7` | `112a024ca7d01f81a24aa4f9b98b13480052da190452f2c9b531a567c106d980` |
  | `src/pipeline/RemeshPipeline.cpp` | `3 104` | `18043141fe7720915f46d7d400ff86146c8a39a8346222ea80a4986df8040629` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `0 31` | `913b97e7a3731aff9899f108cb81d9499517f55071a87376355ddd8e6da27bac` (the pre-CB93 file) |

- **Content:** removes the call, the function, its declaration and CB93's unit test. A 3-line comment states the single-writer rule.
- **No new test.** The guarantee is completion's, already gated by rows 874–875. The removed function has no behaviour left to test. TB83's Vase pin (no `FlippedFace`, against 35,164 under the legacy pass) is the integration falsifier.

**CB95 — `M6-CP3-CB95-P13-QUAD-SELF-INTERSECTION-OWN-PLANE`**
- **Precheck:** the three CB94 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB95_P13_Quad_Self_Intersection_Own_Plane.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB95_P13_Quad_Self_Intersection_Own_Plane.diff").
  - SHA-256 `8207716b9993a9d1e290ff4fe9eb4794ff505dfb601708bcd965c68cf4d0c014`.
  - 158 lines; **keep its 4 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/MeshValidator.h` | `40 35` | `15b813d3b1d312d2a7f6c742c951c002b7b633f3cee00ae317f1872d83a08f3e` |
  | `tests/SurfaceCellsPhase10Tests.cpp` | `49 0` | `4cd349c3b7b6bdfa61032d38042018e013cad722c9f01d17b005907d43ae1e3a` |

- **Content:**
  - `quad_self_intersects` builds the Newell normal and treats a vanishing vector area as self-intersecting;
  - it projects **orthogonally onto the quad's own plane** (`unitOrthogonal` basis);
  - it removes the class's orphaned `dominant_axis` and `project2`.
- **New test:** `SurfaceCellsPhase10.QuadSelfIntersectionDoesNotDependOnCornerOrder`, covering in all 8 corner orders:
  - the skew witness (equal verdicts);
  - **Vase twisted quad 65858** (flagged; margin 0.019·L²);
  - a symmetric bow-tie (flagged).
- **Non-vacuity:** it FAILS on the legacy validator. RA-208's axis variant misses the twisted witness, which was selected for exactly that.

**CB96 — `M6-CP3-CB96-P13-COMPLETION-EMBEDDING-OWN-PLANE`**
- **Precheck:** the two CB95 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB96_P13_Completion_Embedding_Own_Plane.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB96_P13_Completion_Embedding_Own_Plane.diff").
  - SHA-256 `a7e81da57d5d1bf37847ccf0b5ee3abeca5230c0605d35056e6a12d40b54f469`.
  - 74 lines; 0 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PureQuadCompletion.cpp` | `9 12` | `b756c3f29481112f10d382f479caad17861927e56e97ab4f574b6c6c87c200b8` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `31 0` | `6ca86f6e721589fae1dcf150cd88e88d152ec559b9fb4cf18a91a0874e88355d` |

- **Content:** `quad_embedding_failure` projects orthogonally onto the quad's own plane. This is the same definition as CB95, implemented separately.
- **New test:** `PureQuadCompletionPhase18.QuadEmbeddingFindsTheCrossingOfATwistedQuadInItsOwnPlane` expects the twisted witness to be `BowTieIntersection` in all 8 orders. It **FAILS on legacy**, which returns `None`.

**Build (each CB):** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.

**Routes:**

| CB | Mismatch | Infrastructure |
|---|---|---|
| CB94 | `M6-CP3-PLAN-P13-ORIENTATION-SINGLE-WRITER-STOP` | `M6-CP3-CB94A-P13-ORIENTATION-SINGLE-WRITER-ORCH` |
| CB95 | `M6-CP3-PLAN-P13-QUAD-SELF-INTERSECTION-OWN-PLANE-STOP` | `M6-CP3-CB95A-…-ORCH` |
| CB96 | `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-OWN-PLANE-STOP` | `M6-CP3-CB96A-…-ORCH` |

**Verified in scratch:**
- The chain CB94 → CB95 → CB96 applies cleanly on a clean `e96e98806` worktree and reproduces the scratch tree **byte for byte**.
- Results on the final tree:

  | Check | Result |
  |---|---|
  | 903-row gate | **902/903** (only row 283, O16) |
  | Census digests, Plane / MultiFaceSeam / CloseSheets / Cylinder / BunnyRandom | **identical** to post-CB92, apart from the suffix |
  | Census digest, Vase | changes only `completion` (`7f9763a9…/67750`; count unchanged) |
  | Vase validation | `validationIssues=4 GeometricVertexOnUnsplitEdge=3 SelfIntersectingFace=1`; 0 FlippedFace; 0 local self-intersections; 0 flips |
  | Effect of CB96 | the patches that produced the 17 twisted quads take other variants; completion still succeeds |
  | Validator-only state (CB94+CB95) | 21 reported issues: 17 twisted quads are independently proved; the 1 overlap and 3 vertex-on-edge complaints were not yet physically adjudicated, and later P13-l2 Review demonstrates validator false positives |
  | Both new tests on legacy | FAIL |
  | GCC 16 `-Wall -Wextra -fsyntax-only`, all six changed units | clean |

#### RA-209.4 TB83 — `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-EXEC` (after CB96)

- **Package:** the immutable CB96 package.
- **Gate:** [`Architecture_M6_TB83_P13_Embedding_Predicate_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB83_P13_Embedding_Predicate_Full_Gate_Case_Manifest.tsv").
  - 903 rows, SHA-256 `61e9edbedee3731b04d7b6279b79a0fd0e0b651686638e9b832773f7aa0a36aa`.
  - TB82's 901 rows byte for byte, plus row 902 (the CB95 test, producer binary) and row 903 (the CB96 test, completion binary).
  - `SELF_CHECK_PASS cases=903 deferred=81`.
  - **903/903**, membership **984**.
- **Census:** Cylinder PASS; BunnyRandom P13-e at vertex 49; Vase RED within 600 s.
- **Pinned digests:**
  - gate rows 795, 796, 797 and 864, and census Cylinder: byte-identical to TB82, followed by ` validationIssues=0`;
  - census BunnyRandom: byte-identical to TB82;
  - census Vase: byte-identical to TB82 through `simplification`, then `completion` (recorded), then a ` validationIssues=` suffix **with no `FlippedFace`**. Its counts are recorded; macOS gives 4.
- **Routes:**
  - mismatch → `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB83A-P13-EMBEDDING-PREDICATE-ORCH`.

**Superseded and removed** (never applied):
- RA-208's CB94 diff (`…CB94_P13_Quad_Self_Intersection_Corner_Order.diff`);
- RA-208's TB83 manifest (`…TB83_P13_Orientation_Predicate_…`), which gates CB93's test that CB94 removes.

#### RA-209.5 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 43D — IN PROGRESS | `M6-CP3-CB93-P13-ORIENTATION-WHOLE-QUAD-NORMAL` | Implementation agent; finish as frozen (RA-208.3) |
| 43E — NEXT after 43D | `M6-CP3-CB94-P13-ORIENTATION-SINGLE-WRITER` | Implementation agent; RA-209.3 |
| 43H | `M6-CP3-CB95-P13-QUAD-SELF-INTERSECTION-OWN-PLANE` | Implementation agent; RA-209.3 |
| 43I | `M6-CP3-CB96-P13-COMPLETION-EMBEDDING-OWN-PLANE` | Implementation agent; RA-209.3 |
| 43F | `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-EXEC` | Implementation agent; RA-209.4 |
| 43G (Review, after TB83) | `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2) | Claude, scratch build. 1 overlap and 3 T-junctions; re-locate the overlap's faces after CB96 |
| 44 / 44A / 44B / 44C | P13-e; O31; O32e → d → b/c; O33 | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The 903-row manifest's 901-row prefix is TB82's; self-check PASS |
| Decisive claims independently re-derived | Helper flip census over the gate and census. Crossing census in the Newell plane and the source plane, with corner signs and dihedrals. The CB96 effect on Vase. Byte-identity of the patch chain |
| Non-vacuity checked | Both new tests FAIL on legacy. The twisted witness was chosen because the axis predicate misses it |
| Prior obligations discharged/carried | RA-208 CB94/TB83 superseded. P13-l2, P13-e, O30b, O31, O32b–e, O33 carried |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| ORIENTATION / TODO / handoff / CHANGELOG / tracker / LESSONS | Updated |
| Turn boundary held | No product, test, fixture or build source changed in the repository; the patches are committed `.diff`s. Scratch probes only |
| `STATUS` lifecycle maintained | Not written: CB93 is IN_PROGRESS (`b734d1cd3`). RA-209 replaces only its successors |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md`; moved verbatim.

### O32a actual Vase producer scratch result — WIP (2026-11-05)

> **Reviewed by [RA-207](#architecture_m6_cp3_defn_p13_row_permutation_seeds_review_fan_seeding_20261105md "moved: Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md").** The mechanism and four-order invariance were re-derived: 1,416 seeds, 189,462 traces and 30,989 strands in every order. The CB92 plan is replaced by an exact per-fan patch.

**Canonical turn:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS`. This is a Review scratch experiment, not product acceptance or a successor freeze. It supplements the existing O32a WIP documents; formally consolidate them before closeout.

**Verified execution:** isolated GMP compile [42007963779](https://github.com/akashskypatel/Directional/actions/runs/42007963779), source SHA `59f605752369908cdc0fb0388485892742caf462`, compile ZIP artifact `13405864387` SHA256 `f4bea9a30dc50184c3d4c8105c871f810b58d0d4932eca546eb04af2c2d5c2dd`. Its original capture attempt failed before producer execution due to missing adjacent `test-data/benchmarks/fixtures`. Follow-up scratch-only [42010784348](https://github.com/akashskypatel/Directional/actions/runs/42010784348) reused the *same* binary and source archive, verified package `SHA256SUMS`, extracted packaged fixture data, ran base + three consistent face/field permutations, and preserved all four `coverage` inventories. Capture artifact `13405669805` SHA256 `a8841ded5d453e2d2bde2002d24904b5ef7d665c5f4d03c2c9331996ad2f9b7e`; capture log artifact `13405624699` SHA256 `f423fecd66ffc33f46c9f297fed62c4cf1d0257dcd0cf47c6e955dd4b165f572`. All internal capture hashes verified. GTest exits 1 intentionally from `O32A_SCRATCH_CAPTURE_COMPLETE`; this is not a passing product test.

| Source-face order | Rail seeds | Coverage / final seeds | Admitted ReliefCritical seeds | Suppressed from observed candidate union |
|---|---:|---:|---:|---:|
| Original | 284 | 1456 | 1171 | 65 |
| Permutation 1 | 284 | 1460 | 1175 | 61 |
| Permutation 2 | 284 | 1458 | 1173 | 63 |
| Permutation 3 | 284 | 1455 | 1170 | 66 |

**Measured first divergence:** `relief_roots`, before adaptive coverage; zero extra adaptive seeds here. The logged canonical face multiset (2404 triangles), rail semantic digest and rail seed digest, 369 relief roots, 1274 target values, 1274 relief labels and admitted singularity (source vertex 357) are identical. The record does not independently inventory all input `reliefCriticalVertices` or all field-network authority.

**Independent causal reconstruction:** `vertex_point` chooses `incident[vertex].front()`, where the incident list is sorted by *face row*. `initialize_seed` deduplicates on (face row, rounded barycentric triple). Parse the complete emitted ordered `O32A_FACE` records and existing rail seed (face, endpoint vertex) keys; then predict admission of each relief-critical source vertex iff its first incident face/vertex is not already in the rail chart set. This correctly predicts **every actual admitted vertex** among the union of 1236 observed candidates in **all four** logs; suppressed totals are exactly 65/61/63/66, every suppressed candidate is a boundary rail endpoint, and non-rail candidate admission is invariant. This demonstrates the observed source-row collision mechanism, rather than an adaptive seed tie. A canonical-minimum semantic-face surrogate predicts the same 1132 admitted source vertices under all four permutations, but it is *not* compiled, fan-/sheet-safe, or necessarily a correct production policy.

**Correction of previous WIP:** prior Continuation 3 incorrectly claimed the production path does not fill `reliefCriticalVertices`. In fact `src/pipeline/RemeshPipeline.cpp` pushes each retained `reliefTopology.criticalPoints` vertex into `tracingOptions.reliefCriticalVertices`; `SurfaceCellTracing.cpp` admits both `reliefCriticalVertices` and `reliefRootVertices` as `ReliefCritical`. The earlier root-only synthetic experiment cannot represent the complete producer path. This correction supersedes that claim.

**Evidence backup:** `Directional_O32a_Vase_Four_Captures_20261105.zip` SHA256 `c7c7bc293b80f610dcc69a8414ae0355735c8d2a656a5cf109c60f3a3a8b19c2` (four raw Vase logs, independent collision checker and JSON proof, corrected general analyzer output, SHA256SUMS). The proof program executed with `STATUS=COMPLETE`.

**Still pending:** source-fan/hard-rail-side-safe correction and C++ scratch falsification; downstream trace/strand changes, formal Review closeout, documentation reconciliation, and exactly one bounded Code + Build successor. The main working branch has no source/test/fixture/selector/workflow changes. The temporary scratch branch and Drive staging patch must be retired after the evidence is secured. **Keep this canonical Review IN_PROGRESS.**


#### Independent compiled-artifact safety audit — resumed review, 2026-11-05

- Independently verified the exact scratch compile ZIP artifact `13410127667`: outer SHA-256 `90c009efa5882b6276f1bcd9b88053a6fb7cfdc115e004c2b89fa345d139c43c`; internal packaged `SHA256SUMS` all passed; embedded source commit `53c381db960eb2fa632f46719528374e2c9eb926`. The authoritative current working-branch source snapshot from run `42020417757`, artifact `13411890620`, matches commit `86e75845f6545cf1fb2535bc9d8ac5cbf2a6bd9e` and its source archive checksum.
- Inspected the **actual compiled scratch correction** in `src/geometry/SurfaceCellTracing.cpp`: `sourceCharts` is built only when `options.sourceAuthority != nullptr`; source-vertex admissions enumerate all `SourceVertexEntityIdentity` fans and insert a seed for each unoccupied fan. This fixes the captured Vase collision, but a raw vertex-scoped singularity/relief input is not by itself a fan-scoped authorization to duplicate semantic obligations. Source-owned rail seeds still use the previous face-local `seen` map; distinct mandatory `HardRailId` occurrences at identical face/barycentric keys can still collide. Neither issue is proved safe by equal Vase seed digests.
- Reused the immutable Linux scratch test binary **without rebuilding** for two independent existing focused cases. `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` and `SurfaceCellTracingPhase14.SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet` both passed (2/2, 0 ms reported). This is **limited evidence**: the former sets only raw face component/sheet labels and never `sourceAuthority`, so it bypasses the new fan-aware branch; the latter tests source-label classification, not seed insertion. Their green result does **not** satisfy the Review's typed-source-authority, mandatory-rail, or cross-sheet falsifiers.
- Required scratch-only negative/positive C++ controls remain: (a) with a valid `SourceTopologyRegions` binding and a protected edge separating two fans at one vertex, verify each optional seed is admitted only in its **authorized** fan and remains distinct on the other independently authorized fan; (b) remove that barrier and require the two fans to coalesce; (c) vary local-sheet/component labels and verify no cross-sheet dedup; (d) place distinct mandatory rail IDs/sides at the same embedded vertex and prove every required occurrence survives; (e) reorder source-face rows in each control while holding semantic source identity fixed. Verify by typed fan and rail IDs, not by world position alone. A mutant removing the barrier and a mutant dropping a required rail ID must each fail the check.
- After those controls, permit the scratch run to continue beyond the deliberate `O32A_SCRATCH_CAPTURE_COMPLETE` exception, capture tracing, strands, and quad outcomes on original plus three permutations, and distinguish newly revealed downstream ordering defects from the corrected seed producer. Do not infer such downstream equality from four equal seed digests.
- **Disposition:** O32a remains unfinished, this is not a product fix, not a TB gate, and no successor was authorized. The corrected 1,416-seed Vase result remains an unpromoted candidate; accepted CP2 and selector/CP3 boundaries are unchanged. No product, test, fixture, or workflow source was changed on the working branch in this continuation.


##### Independent raw capture re-derivation (same resumed Review)

Downloaded artifact `13409544451` and verified its outer ZIP SHA-256 `ea939e9519059493a028077cac52a9af0d1b13c9eef1e67b881fb54a149efe91` plus all five internal `SHA256SUMS`. Reparsed **each** of the four original logs, not the previous analyzer's summary, using a sorted `origin|sourceId|exact printed 3D position` record per phase (this is a newly defined comparison digest, **not** the older analyzer's digest).

- All four: `rails=284`, semantic digest `102dbb5e42e32d8e44cce699489c653c79f072d7bb1738841f031c69e2510a7f`.
- All four: `relief_roots=relief_regions=separatrices=coverage=1416`, semantic digest `7f299f1f1a1b2c99a5f170e316a828357545cb9da96154c3c5e9e46b4725042c`.
- Sorted upstream source-face (2,404), rail (284), relief-root (369), target-size (1,274) and relief-label (1,274) records are each exactly equal under all four row orders. **Zero** explicit `O32A_HARD_EDGE` records were emitted; Vase cannot prove a protected-edge case.
- Each run intentionally exits 1 following `O32A_SCRATCH_CAPTURE_COMPLETE`, so this is a completed **scratch capture**, not a passing product test. No tracing/strand evidence can follow from these early-exit logs.


#### Continuation 4 — independent downstream attempt and scratch controls (2026-11-05)

The unchanged GMP-linked compiled scratch package `13410127667` (source `53c381db960eb2fa632f46719528374e2c9eb926`) was executed locally, without rebuilding. With `DIRECTIONAL_O32A_PERMUTATION=1` and the deliberate seed-capture abort disabled, Vase completed in 246,365 ms with typed RED `NotProductionReady:completion / SelfIntersectingFace`: 189,462 trace segments, 30,989 strands, 26,817 arrangement cells, 67,782 completed quads. This is a single scratch observation, not acceptance. A simultaneously running unpermuted control was killed with exit -9 by container memory limits before its digest: **no valid downstream baseline or cross-permutation comparison exists**. Plane and BunnyRandom failed to exercise the seed generator (phase-front path and earlier field-transport failure respectively).

On isolated scratch branch `scratch/p13-o32a-seed-review-20261105`, commit `91aff2b78c2454b5f72452ca685d05f8194c5f01` added two C++ review-only falsifiers: typed source-authority split/coalesced vertex fans under two source-row orders; and two distinct mandatory rail IDs sharing a source vertex. Commit `ae9c92881692a6b417bccfc82bea48cb94c0ac09` added temporary compile workflow `o32a-review-scratch-compile.yml`. **Compile and test results are unverified**; do not claim green. Validate fixture admissibility, compile remotely and execute controls/mutants, then collect sequential full Vase base plus ≥3 permutations and measure downstream traces/strands. Remove the temporary scratch workflow after securing evidence.

This canonical O32a Review is still unfinished. No working-branch product, test, fixture, selector, or workflow source was modified; no successor or CP3 promotion is authorized by this evidence.


##### Scratch control compile outcome (same continuation)

Temporary workflow `42024977211`, input scratch commit `ae9c92881692a6b417bccfc82bea48cb94c0ac09`, finished **FAILURE**, with compile log artifact `13412724315` (SHA256 `96f6516da3e369d3f6adc42c095323541bef5fff053996e50a7fea558ddd38ba`). Actual error: `tests/SurfaceCellREPackageTests.cpp:1610,1613,1620` dereferences `DomainResult<SourceEdgeTopologyKey>` with `*featureEdge` or `*boundaryEdge`, which has no `operator*`. The checked `.value()` accessor is used in existing fixtures and should replace those three dereferences **on the isolated scratch branch only**, after which a fresh remote compile must establish the next result. The secondary initializer-list diagnostics are downstream consequences of these type errors; no evidence of another error after correction exists. **No scratch controls executed**. This is a scratch-test authoring failure, not a product or TB regression. The failed attempt and its log must remain traceable. No platform/safety-blocking of connector mutations occurred.


#### Continuation 5 — compiled controls and sequential downstream baseline (2026-11-05)

All tests below were **isolated Review scratch execution**, not a production TB gate. The current working branch was unchanged except for the Review WIP and lifecycle beacon. The exact source snapshot remains the previously verified `86e75845f6545cf1fb2535bc9d8ac5cbf2a6bd9e`.

**Remote scratch compile and identity.** The first test-only correction replaced invalid `DomainResult<SourceEdgeTopologyKey>` dereferences with checked `.value()` on scratch branch commit `883f921b134c981cac33722add8e8f01f572c1b4`. GitHub Actions run `42027161975` compiled `directional_surface_cell_producer_tests` successfully. Result artifact `13413982932`, outer ZIP SHA-256 `28dd875c43c58b253514e0134986456b88d1353841af9448440f12b95f13f046`, internal **23/23** hashes verified, GMP/GMPXX linked, source status clean. The product libraries `libdirectional_core.a` and `libdirectional_pipeline.a` are byte-for-byte identical by SHA-256 to the earlier compiled producer source `53c381db960eb2fa632f46719528374e2c9eb926`; only isolated tests differ.

**Actual focused execution of that compiled binary:** `O32aScratchFanSafety.SplitAndCoalescedVertexFansSurviveRowOrder` **RED** for both source-row orders when the two adjacent faces have different raw isolation-sheet labels but no hard barrier: expected two `ReliefCritical` seeds, received one. This trial is not sufficient to assert a product bug, because `SourceChartTransitionGraph::build` joins same-component adjacent charts without splitting on different sheet labels, and this synthetic labeling may not create a valid source-chart barrier. `O32aScratchRailSafety.DistinctMandatoryRailsAtSharedSourceVertexRetainIds` **RED**: only one of two distinct `HardRailId` values survives at the shared endpoint (feature retained, boundary lost). The test uses valid source edges `(0,3)` and `(0,1)` at vertex 0, on face `(0,1,3)`. Source cause: `initialize_seed` deduplicates on raw face and rounded barycentrics before `append_hard_rail_seed` assigns the semantic rail owner. This is a potentially real mandatory-ownership defect; require independent rail-contract adjudication before product changes.

**Isolated hard-barrier falsifier:** scratch commit `63af8e9bd31435531825dca6658f1cef384d9c18` corrected the fan control to keep identical sheet labels and toggle only the protected interior source edge `(0,3)`. Run `42028082868` succeeded compiling the same test target; result artifact `13414318778`, ZIP SHA-256 `477d67b168942eb8c2f0c646572ddbda97f6a0992a352235708b645030f3448b`, 23/23 packaged hashes verified, source clean. Focused runtime **1 PASS / 1 RED**: the barrier-on/off fan control passes in both row orders; mandatory two-ID rail control still fails, retaining one ID. The fan control currently checks seed multiplicity, not the exact typed fan-ID set; strengthen before claiming complete non-vacuity. A mutant that removes the hard barrier should fail the split=1 assertion, but this mutant was not separately compiled/executed.

**Sequential full Vase observations:** From packaged scratch test source `883f921...`, unpermuted `Vase` completed with typed RED `NotProductionReady:completion / SelfIntersectingFace` in **243.344 s** (wall 243.38 s); `traceSegments=189462`, `strands=30989`, `arrangementCells=26817`, `completedQuads=67750`. Earlier independent permutation-1 run used package `53c381...` with identical compiled product-library SHA-256, exited with the **same typed RED** in **246.365 s**, and yielded `189462` traces, `30989` strands, `26817` cells, but `67782` completed quads. Exact input `vertexBits`, `faceBits`, `fieldBits`, relief and source-label digests agree; source/container order and downstream structural digests differ. Both runs executed with recovery disabled. This is an observable **32-quad completion-count difference** after equal trace/strand/cell counts. Do not infer identical topology from equal counts, or a semantic defect from hash differences alone. Neither run produced accepted quads because both failed closed.

**Outstanding same-turn work:** (1) improve the protected-edge test to assert distinct exact typed `SourceVertexEntityIdentity` values and separately adjudicate sheet-only semantics; (2) determine whether mandatory intersecting rail ownership requires separate seeds or a multi-owner representation and record the root-cause/falsifier; (3) collect **sequential** source-row permutation 2 and 3 full Vase results with exact packaged inputs and no simultaneous memory-heavy runs; (4) classify whether remaining completion-count difference is independent of the seed producer and assign O32b/c; (5) only then close O32a with a bounded, independently justified Code + Build successor and full Review closeout block. The temporary scratch workflow is still required while controls remain and must eventually be retired. **No successor turn, P13-l, selector promotion, or CP3 acceptance is authorized yet.**


#### Continuation 6 — four-order full production-trace comparison and typed-fan proof (2026-11-05)

**Status: same canonical O32a Review, still IN_PROGRESS; not an acceptance or successor execution.** All runs below use scratch-only code compiled in a remote GMP/GMPXX workflow. No source, test, fixture, selector, benchmark or build logic was changed on the working branch. The exact working source snapshot is `86e75845f6545cf1fb2535bc9d8ac5cbf2a6bd9e`, run `42020417757`, artifact `13411890620`. Scratch product-library hashes are byte-identical between source `53c381db960eb2fa632f46719528374e2c9eb926` and `883f921b134c981cac33722add8e8f01f572c1b4`: `libdirectional_core.a=92fe324bda8590310baa20b6ca25b3e0c85de5e119c4ad979a5e85bf69031d99`; `libdirectional_pipeline.a=2c39cde34e62dc96c4261326fed50dc36f2f8d61f4e8d88babd9c56f45724c4a`. The latter source was used by original/perm2/perm3 full runs, the former by perm1, all with equivalent product-library bytes.

**Typed source-fan positive and rail negative.** Isolated scratch branch commit `701f16eafb49a41976b5861e0846f9cb772a2ad7` strengthened the source-fan control to resolve each ReliefCritical seed via `SourceChartTransitionGraph::resolve_entity` and compare exact `SourceVertexEntityIdentity` sets across both row orders with and without an explicit interior hard barrier. Remote compile run `42030842612` passed; package artifact `13415119500` ZIP SHA-256 `1b861015defc2f284ece4c1e44ebad8bb63bd37601ff0f49442222417927bed5`, **23/23** checksums, GMP/GMPXX linked, product libraries unchanged. Re-executed both focused tests: `O32aScratchFanSafety.SplitAndCoalescedVertexFansSurviveRowOrder` PASS; `O32aScratchRailSafety.DistinctMandatoryRailsAtSharedSourceVertexRetainIds` RED, retaining one of two coincident annotated `HardRailId` values. Source audit finds the single-ID `SurfaceTraceSeed::hardRailId` set by `append_hard_rail_seed` but never read in the tracing or strand-selection production source. Thus the negative proves **seed-annotation loss**, not a loss of an authoritative rail edge or an independently established mesh-acceptance contract violation. Do not declare the negative discharged before checking the actual mandatory rail-edge/network invariant, and do not blindly insert coincident duplicate seeds. The earlier sheet-only synthetic test is not authoritative fan separation; the explicit hard-barrier test is.

**Corrected seed invariance independently rederived:** from the original and three permuted raw `O32A_SEED coverage` logs, each contains exactly **1,416** records and has sorted `origin|sourceId|exact printed position` SHA-256 `7f299f1f1a1b2c99a5f170e316a828357545cb9da96154c3c5e9e46b4725042c`. The earlier uncorrected producer gave 1,456/1,460/1,458/1,455 with the first phase divergence at `relief_roots` due to source-face-row `vertex_point` choice and face-local `seen` collision. The scratch remedy reuses exact typed vertex-fan ownership; it is not an accepted production fix.

**Independent, sequential four-order full Vase observations, same typed RED:**

| Face-row order | Trace segments | Strands | Arrangement cells | Completed quads before rejection | Wall time |
|---|---:|---:|---:|---:|---|
| original | 189,462 | 30,989 | 26,817 | **67,750** | 243.38 s |
| permutation 1 | 189,462 | 30,989 | 26,817 | **67,782** | 246.365 s (prior process) |
| permutation 2 | 189,462 | 30,989 | 26,817 | **67,766** | 247.56 s |
| permutation 3 | 189,462 | 30,989 | 26,817 | **67,778** | 258.57 s |

Every process reached `NotProductionReady:completion / SelfIntersectingFace`, produced no accepted quad mesh, and did not use source-grid recovery. All four logs have matching `vertexBits=eef00a8706c009f5`, `faceBits=e43da6cccb821779`, `fieldBits=5c9a34a47d717fdc`, plus matching relief, relief-consumption and source-label diagnostic fields. Tracing, strand, embedding, arrangement, completion **content hashes differ** among orders, even though count fields through arrangement are equal. Because some hashes encode source-row representation, hash differences alone do **not** prove semantic disagreement; the 32-quad completion-count range is a concrete count-level order effect, while the first changed semantic downstream topology is not localized.

**O32 ownership allocation from this Review:** O32a earliest seed row-collision mechanism and candidate correction are measured; O32b is the independent tracing-proper row-invariant semantic content gate (count alone green, hash difference inconclusive); O32c is independent strand-selection row-invariant semantic gate (count green, hash difference inconclusive); O32d remains canonical injective arrangement cell identity; O32e remains completion ownership/candidate schedule because completed-quads counts vary, but a direct O32e root-cause proof needs controlled input-order perturbation that holds upstream topology fixed. Treat O32b–e as pending separate Reviews in RA-205.5 order, not as fixed by O32a. No CP3 promotion.

**User-facing independently verified evidence:** `Directional_O32a_Continuation6_Evidence_20261105.zip` SHA-256 `91d166affb962e6e9111178a48ca454379702fd27e503e5f9f0999ecddf17a0e`. It contains four raw full Vase process logs, four raw corrected seed captures, test log, a verifiable SHA256SUMS and a standalone stdlib re-derivation script and outputs; no tests were rewritten to obtain green. This zip is supplied directly in the chat, not stored in the repository; the remote compiled package remains artifact `13415119500`.

**Remaining same-turn actions:** adjudicate the exact mandatory-rail-edge preservation contract versus coincident seed-annotation ownership; establish the smallest production-source change without scratch logging and specify direct typed fan/rail invariants, deterministic source-row/seed census acceptance, compile-only target suite and separate immutable TB with falsifiers. Perform Review-policy mandatory closeout/checker and durable document reconciliation/consolidation, freeze exactly one CB successor only after independent evidence supports it, retire scratch workflow and Drive staging after evidence is secure. Keep this canonical turn IN_PROGRESS while these obligations are unfinished. The scratch product, selectors, accepted CP2 491/491, stable 66/17/49, debt1, TB81 899/899, selector497 and CP3 remain unchanged.


#### Continuation 7 — invalid rail control adjudicated; valid authority proved (2026-11-05)

**Independent correction to the previous interpretation:** `O32aScratchRailSafety.DistinctMandatoryRailsAtSharedSourceVertexRetainIds` was constructed with a **single sample per rail**. The actual strict `surface_cell_tracing_detail::rail_interval_refs` contract requires two endpoint samples per interval, producer-published typed source vertices/edges, and validates rail IDs and per-edge interval ownership. That former scratch assertion compares two coincident seed *annotations* under invalid rail-ingress input; its RED is **not evidence that a valid mandatory source rail was discarded**. This corrects Continuations 4–6 wherever their prose described the RED as an unresolved production mandatory-ownership defect. Do not silently delete the failed check or misrepresent it as now green; preserve its exact synthetic limitation.

**New separate valid control:** scratch branch commit `12f926bf56f0996d6351b2cf68705dde02f0935b` added `O32aScratchRailAuthority.ValidSharedVertexRailsPreserveDistinctTypedIntervals` without modifying the old check. It uses a valid two-sample interior hard-feature rail on source edge (0,3) and a valid two-sample source-boundary rail on edge (0,1), both sharing vertex 0. Both have independently typed `HardRailId`, `sourceVertices`, `sourceEdges`, and geometrically exact sample endpoints. The test calls strict `rail_interval_refs` and asserts both distinct `(HardRailId, SourceEdgeTopologyKey)` pairs survive. Two tamper cases require `TypedAuthorityMismatch` for missing typed `sourceEdges` and `DuplicateRailId` for duplicate owner IDs. It also checks that both IDs remain represented among generated seed annotations, without incorrectly requiring a separate coincident seed at every shared endpoint. Source audit confirms tracing uses authoritative intervals and does not consume `SurfaceTraceSeed::hardRailId` as mandatory rail preservation authority (that optional field also appears in diagnostic hashing).

**Remote compiled evidence:** GitHub Actions run `42034591362` **SUCCESS**, input source `12f926bf56f0996d6351b2cf68705dde02f0935b`, result artifact `13418271529`, outer SHA-256 `05436c29810164e8aaf8c43a098965a91bc84314dc855630eb2690ee8693e145`. Independently verified package `SHA256SUMS` **23/23 OK**, exact `metadata/source-commit.txt`, GMP/GMPXX linkage, source status. Executed the *already compiled* producer test binary, not a local build: `--gtest_filter='O32aScratchRailAuthority.*:O32aScratchFanSafety.*'` **2 PASS / 0 FAIL**, exit 0; the protected-edge fan test separately compares exact typed `SourceVertexEntityIdentity` sets across source-face row orders and barrier-on/off states. Evidence archive `Directional_O32a_Continuation7_Rail_Authority_Evidence_20261105.zip`, SHA-256 `03835f57c21e97ab1b39083e4038292c237f4d7c4b408d3214b044949adfee1d`, includes the focused raw output, exact 23 package checks and previous failing synthetic check for transparent comparison. These are valid scratch controls, not accepted production tests.

**Adjudication:** O32a's true first source-row collision owner is `vertex_point` + `initialize_seed` using row-local identity; the scratch remedy using existing typed `SourceChartTransitionGraph` yields identical 1,416 semantic seeds under base and three independent face/field row permutations. Exact typed protected-edge fan control passes. The rail constraint is the independent, strict **per-edge interval authority**, not a requirement to emit one trace seed per coincident `HardRailId` at every shared vertex. The remedy must preserve rail interval edges and IDs without introducing duplicate coincident seeds solely to green the invalid negative. O32b–e source-order sensitivity remains independently open: full Vase runs still produce 67,750/67,782/67,766/67,778 completed quads before the same terminal `SelfIntersectingFace` RED, with matching tracing/strand/arrangement counts.

**One bounded successor plan, not executed:** [CB92](#architecture_m6_cp3_cb92_p13_source_vertex_fan_seed_identity_plan_20261105md "moved: Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md") prescribes the smallest source-authoritative vertex-fan correction, existing typed-identity reuse, fail-closed admissibility, hard-rail invariants, metamorphic source-row controls and stop rules. A separate immutable TB is required. Final Review closeout/document consolidation and `review_check.py boundary` remain required before setting the canonical turn COMPLETE. Until that checklist passes, keep STATUS on O32a IN_PROGRESS; do **not** start CB92 or a downstream O32b/c/d/e turn.


##### Folded O32a scratch-run continuation index (Review consolidation, 2026-11-05)

| Exact folded filename | Role and verdict |
|---|---|
| `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Scratch_Run_WIP_20261105.md` | Temporary 20-line scratch-workflow setup/initial compile state, now superseded by independently verified completed captures, focused tests, typed fan proof, complete four-order Vase results and valid rail control in this record. Historical file text remains recoverable from Git history. |

Specific facts retained before consolidation: baseline snapshot `4e151e5c139d09ecabca663ea1125d0544c32abb`; isolated scratch branch `scratch/p13-o32a-seed-review-20261105`; temporary caller `.github/workflows/o32a-scratch-workflow.yml` installed at `b6676bb9ff94d6e6860755dac85676b780d80b65`. Initial Drive apply run `42007688756` trigger `903993d35f5e53893b20085be5ee1b50d06786e0` passed schema/patch/mailbox; result artifact `13404903831` hash `41f479145f37633a2add2a7a7fa9d33cf515b8301c5b5659b221b2b6440aaf68`. Applied scratch source `4499643bc5535d95abd962070dfd58b3f7022895` via patch hash `9a19f8386d3acb6a904e264f86fff4496f3dc4662bbd0da82e676a9e411427fe`, two scratch-only paths. Initial GMP compile run `42007963779` triggered at source `59f605752369908cdc0fb0388485892742caf462`; its formerly pending status is superseded by the verified completed run documented above. Old runner's missing fixture adjacent to binary and intentional `O32A_SCRATCH_CAPTURE_COMPLETE` exception were scratch handling facts, not product failures. Temporary Drive patch ID `1kucBxUvhEqvOVJUg4Ia04jDa1XKCU8Uo` had `drive_file_trashed=false` and `drive_file_retirement_required=true`; retire via owner Drive connector only after confirming no remaining recovery use, and record outcome. Remove scratch workflows and branch after all evidence is durable. No accepted product/test/selector surface was changed by scratch work.


#### Continuation 8 — single-fan authority and conservative multi-fan contract (2026-11-05)

**Independent source and fixture audit (no new C++ build):** Parsed immutable `benchmarks/fixtures/milestone-g/vase.off` (SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`) from verified source snapshot `86e75845f6545cf1fb2535bc9d8ac5cbf2a6bd9e`. It has 1,274 vertices, 2,404 faces, 142 boundary edges, zero nonmanifold edges and zero inconsistent paired orientations. Independent edge-adjacency and vertex-star traversal, with no feature barrier (previous raw `O32A_HARD_EDGE` count zero), finds **one connected intrinsic fan at each of the 1,274 vertices**; no multi-fan vertex in Vase. The scratch candidate's four identical 1,416-seed inventories therefore exercise the unambiguous one-fan source domain, not multi-fan semantics. Reproducibility/audit report: `fan_admissibility_audit.md` SHA-256 `a8eb822d71c1706793c8225489c09806ef0c45b4f2b7d32b8c2b88db75ac18ad` (provided as an exact chat attachment).

**Previously overclaimed synthetic control:** `O32aScratchFanSafety.SplitAndCoalescedVertexFansSurviveRowOrder` PASS establishes source-chart connectivity and row-independent typed `SourceVertexEntityIdentity` under hard-feature split, **not** that `reliefCriticalVertices={0}` authorizes relief seeds in both disconnected fans. No independent owner fact for that cardinality was provided by the test. This corrects the prior description "exact typed fan proof" to distinguish topology identity from permissible seed ownership. The graph test remains valid for its actual graph claim; it is not an accepting multi-fan seed admission oracle.

**Independent contract inspection:** `ReliefCriticalPoint` has raw `vertex` only; `reliefCriticalVertices`, `reliefRootVertices`, `separatrixVertices`, and `anchors` are vertex-index collections. Field-aligned singularity ports have typed source component and topology region, but no vertex-fan/attachment; a protected edge can split two fans within one topology region. Existing source-chart identity and region binding can enumerate and check eligible chart fans, but do not manufacture a producer-owned per-fan scope for a vertex-only obligation. Mere source incidence does not prove permission to duplicate that obligation. The safe decision is **single unambiguous typed fan → one canonical chart**; if several admissible fans remain without an independently bound scope, **typed fail-closed terminal rejection**, not row-first/geometry-first picking, all-fan duplication, or uncaught exceptions. Do not add an additional owner table or hard-coded two-fan policy.

The bounded [CB92 plan](#architecture_m6_cp3_cb92_p13_source_vertex_fan_seed_identity_plan_20261105md "moved: Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md") was revised accordingly: the earlier all-fan positive becomes a **multi-fan typed negative**, while split/coalesce identity remains a separate positive graph invariant. Implement the unique-fan source-row fix in `SurfaceCellTracing.cpp` with existing types, preserving mandatory rails; if no truthful typed network failure path can represent absent fan scope, the **Code + Build must STOP and return for an explicit failure-contract Review**, not mislabel a valid region or crash. The future positive per-fan obligation contract is separately owned and requires real producer evidence. O32b–e remain open independent downstream ordering stages. No working-branch production, test, fixture, build or selector code changed in this Review.


#### Review closeout

Final O32a Review adjudication: the frozen CB92 successor is authorized **only in the next turn**, after this Review's final STATUS beacon. The implementation must honor conservative fan authorization and stop on any unsupported typed rejection; no CB92 work was done here.

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No new selector added or accepted, so no successor-prefix comparison applies. Remote `review_check.py boundary` at run `42035921813` verified every present required-green selector hash against HEAD, including 449; CP2 491/491 and frozen selector497 authority unchanged. |
| Decisive claims independently re-derived | Parsed four original and four corrected raw Vase seed captures, 1,456/1,460/1,458/1,455 → 1,416 in all four; independently compared sorted semantic capture hash `7f299f1f1a1b2c99a5f170e316a828357545cb9da96154c3c5e9e46b4725042c`; four full Vase logs with 67,750/67,782/67,766/67,778 completed quads and equal trace/strand/cell counts. Inspected actual typed source paths and rail interval source. |
| Non-vacuity checked | Source hard-barrier split/coalesce and exact typed vertex-fan identities PASS under both row orders. Structurally valid adjacent two-rail owner/edge control PASS with missing typed source-edge and duplicate rail-ID tamper rejection. Former single-sample-per-rail negative is invalid as strict rail-ingress proof; preserve its RED and correction, do not treat it as repaired code. Future CB/TB must include first-face-row reintroduction mutant that fails row-invariance test. |
| Prior obligations discharged/carried | RA-205.4 O32a earliest-owner localization and >=3 permutations discharged in scratch; RA-205.5 O32b (trace semantic oracle), O32c (strands), O32d (injective arrangement identity), O32e (completion ownership) carried separately. RA-206.7 P13-l waits for accepted O32a CB/TB. O30b, O31, O33, P13-e, O27–O29 remain as previously owned. **Adjudicated conservative admission:** actual Vase is single-fan at all 1,274 vertices; unscoped multi-fan requests have no producer-owned fan selection and must fail closed with a truthful typed outcome, not duplicate. The revised CB92 plan requires this negative and a stop if no suitable typed network rejection can be established. True per-fan positive authority remains future design work, not part of O32a/CB92. |
| Stable accounting | No accepted green lost; accepted CP2 **491/491**; **66 events / 17 categories / 49 recurrences**, debt **1**; TB81 899/899 matched on CB91; selector497/CP3 unpromoted. |
| New candidates/obligations recorded | O32a source-face-row seed-key collision, O32b–e semantic downstream row-order probes, typed fan authorization gap, and correction to invalid rail test entered in `Regression_Root_Cause_Tracker.md`. |
| ORIENTATION currency line | Updated 2026-11-05 for O32a Review, source-fan remedy bounded and CB92 next, not started. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 CP3 row reports current O32a Review without acceptance; §4 witness table n/a, no accepted witness changed; §7 revised O32a evidence, rail correction and pending duties; §8 records row-local seed collision as another representation-order defect. |
| CHANGELOG | New O32a Review WIP entry added at head, preserves remote artifact, scratch success/RED and unchanged acceptance. |
| ROADMAP | n/a: no milestone/checkpoint status transition; CP3 still active. Checked roadmap. |
| Selector manifest | n/a: no selector created, changed or promoted; remote checker verified all present files. |
| LESSONS | Existing RA-205/O30a representation-row order pattern cited; no independently new general policy requiring a new lesson number. |
| Consolidation under CLEAN_UP_POLICY | Folded `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Scratch_Run_WIP_20261105.md` into this retained current record with exact filename/verdict, initial source/run/patch/artifact and Drive file ID. Original text recoverable in Git history; former temporary WIP deleted within Review-authorized scope. Consumed Drive scratch-only patch `1kucBxUvhEqvOVJUg4Ia04jDa1XKCU8Uo` was permanently deleted after metadata confirmed exact filename; verified Drive metadata 404 afterward. Isolated scratch branch/workflows remain retained only for recoverable committed source and remote compile logs to be retired by CB92 once consumed; no workflow remains on the working branch. |
| Successor frozen | One **prepared, bounded** CB92 document: `Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md`, with positive/negative falsifiers and return-to-Review stop rules. **Exact next turn after terminal STATUS:** `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY`, Code + Build compile-only, frozen in the CB92 plan with semantic-single-fan positive, unscoped multi-fan typed negative, rail-tamper, four Vase permutations and return-to-Review stop rules. No implementation or TB started here. |
| Turn boundary held | All working-branch changes are documentation or lifecycle beacon, not product/test/fixture/selector/benchmark/build changes. Isolated scratch changes compile/run separately, do not count as production acceptance. |
| review_check.py boundary | **PASS** again, read-only GitHub Actions run `42039734526` on repository SHA `3f0f28c314e8fbb7c30ae08db234dd8ce31c7e98` with `boundary_exit=0`, no product/test/fixture/build/selector mutation, all selector hashes and protected durable sections preserved, source diff empty, remote branch tracking origin clean. Prior pass: run `42035921813`, source branch working SHA printed by workflow; checks product/test/fixture/build and selector mutation, all present selector hashes, protected rewrite sections and clean repo status. Job `127273924124`, artifact `13417748664`. Product diff vs source snapshot `86e75845f6545cf1fb2535bc9d8ac5cbf2a6bd9e` empty. |
| `STATUS` lifecycle maintained | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS`, final `COMPLETE` beacon to be written as last working-branch mutation for `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS`, preserving `Started at 2026-11-05T07:54:25Z` and latest `Resumed at 2026-11-05T13:40:02Z`, naming successor CB92; `Ended at` is populated only in that final beacon. |
| Pushed to origin, branch in sync | At remote boundary run `42039734526`, checkout of `agent/surface_cell_quad/p5-recover-bridge-healing` reported `git status -sb` tracking `origin/agent/surface_cell_quad/p5-recover-bridge-healing` with no ahead/behind, and checker PASS. Final GitHub connector documentation commits are direct remote mutations; latest ref is to be re-read before final STATUS compare-and-swap write. |

## `Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md`; moved verbatim.

### RA-204 — O30 Review: the platform split is an arrangement cell-order defect, not the field (2026-11-05)

> **Reviewed by [RA-205](#architecture_m6_cp3_defn_p13_smooth_field_portability_review_row_permutation_20261105md "moved: Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md").** The cross-library mechanism and CB90 stand. Corrections:
> - RA-204.4 item 5 is wrong: under DESIGN §10.1, a completed count that depends on the cell schedule *is* a determinism defect;
> - CB90's halfedge tie-break is a source-row-derived order, so it is interim with respect to §10.1;
> - "two draws" overclaims while O30b is open.
>
> A source-face row permutation changes Vase's seed set, traces, strands and quads (O32).

**Turn:** `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, the successor frozen by the ChatGPT O30 Review ([digest adjudication](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Platform_Split_Digest_Adjudication_20261105.md"), `92e2e9ce8`). The user asked for an adversarial review of `M6-CP3-DEFN-P13-PLATFORM-SPLIT`. This turn reviews it, withdraws its generated-field branch and closes the turn with an exact fix.

**Source:** HEAD `6be82f33c`. `git diff --quiet 9c9616695 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes, so the source is CB89's, and its product source is CB88's.

**Scratch builds** (macOS arm64, uncommitted, outside the repository):
- **A:** default arithmetic. This is the RA-203.7 reference build.
- **B:** clang/libc++ with `-ffp-contract=off` (`bld55n`). Its tree was re-synced with `rsync --checksum` until `diff -rq` against `git archive HEAD` showed no difference. 0 scalar and 0 vector FMA instructions in its libraries.
- **C:** a standalone GCC 16/libstdc++ build of `extract_cross_field` with `-ffp-contract=off`, using libgcc's `__divdc3` algorithm compiled without contraction.
- **D:** B plus `-D_LIBCPP_DEBUG_RANDOMIZE_UNSPECIFIED_STABILITY`, a full rebuild. libc++ then shuffles every `std::sort`, `nth_element` and `partial_sort` range before sorting, with an ASLR-dependent seed. Equal elements therefore land in a different order in each process.

#### RA-204.1 Verdict on the ChatGPT O30 Review

**What holds.**
- Its parse of the seven Linux lines against the 129-row reference is correct. I re-derived it independently.
- So are its first differences per case:
  - MultiFaceSeam has none;
  - Plane, CloseSheets and Cylinder first differ at `relief`;
  - BunnyRandom and Vase first differ at `fieldBits`;
  - Vase's quantized `cross-field` hash is equal, and so are its counts through `arrangement`.
- It refused to infer causation, and it refused to replace generated-field coverage.

**Accuracy defects.**
1. *"Product hashes quantize doubles to 1e-9."* This is false for the atlas.
   - `atlas_fact_digest` (`FieldTransportAtlas.cpp` 1840, 1866) hashes `std::bit_cast` of every transition and adjacency `effort`.
   - The network, cut-graph and topology-plan bindings and the tracing candidates embed that digest.
   - "First differing downstream product is the field-transport atlas" therefore carries no semantic information (RA-204.2).
   - The CB89 test comment I wrote, "(coordinates quantized to 1e-9)", states the same falsehood. I own it; CB90 corrects it.
2. *"O30 root-owner narrowed to generated smooth field and subsequent atlas."* This is refuted (RA-204.3, RA-204.4).

**Completeness defects.**
3. **CloseSheets' relief has a different element count:** 40 branches on Linux and 38 on macOS. That is a topological divergence on bit-identical mesh and field input. The Review recorded it as a "distinct observed portability issue" and gave it no owner. It is now O31 (RA-204.6).
4. **The cleanest witness was missed.**
   - CloseSheets' `embedding` is equal on Linux and macOS (`67442dd8…`), but its `arrangement` differs (`ea29f9db…` against `d433210f…`), and macOS FMA on and off agree.
   - A 36-face fixture whose arrangement differs on identical embedded input points at the arrangement, not at the field.
5. **The successor would not have found the cause.** The successor was a 2,404×12 binary64 field fixture replayed on both platforms.
   - The mechanism is library sort order (RA-204.4), so the replay would have reproduced 67,784 on Linux.
   - It would then have sent the next Review back to noise-carrying hashes ("earliest remaining stage").
   - Neither RA-203.4's second discriminator nor the TODO's GCC/libstdc++ step was run or routed.
6. **Wording.** "Six later product hashes" (Plane, Cylinder) and "ten later products" (CloseSheets) are totals that include `relief`.

#### RA-204.2 Noise carriers (measured), and RA-203.4's under-specified row (owned)

On build B, Vase was run with four distinct fields:
- the build's own field;
- +1 ULP on all 28,848 coefficients;
- ±1 ULP on 100 random coefficients;
- ±1 ULP on all 28,848 coefficients.

`strands`, `embedding`, `arrangement`, `completion` and the 67,829 count are bit-identical in all four runs. Even so, these hashes change:

| Hash | Changes under |
|---|---|
| `field-transport-atlas`, `field-aligned-network`, `surface-cut-graph`, `global-topology-plan`, `global-conformity-baseline` | every perturbation |
| `tracing` | two of three perturbations |
| `strands` | FMA on/off (its cycle-quality doubles) |

These are **noise carriers**. A difference in one of them does not localize anything.

RA-203.4's row "first differing stage S → probe S" omitted that qualification. That is my error: the rule now reads "the first differing stage that is **not** a noise carrier". For Vase that stage is `embedding` (Linux `f2fc0cca…` against macOS `909330af…`). For CloseSheets it is `arrangement`.

#### RA-204.3 The generated-field branch is withdrawn

- **macOS output does not depend on the field noise.**
  - Five distinct Vase fields give the same `embedding`, `arrangement` and 67,829:
    - default arithmetic, `afdad15a…`;
    - FMA off, `976eabe6…`;
    - the three ±1-ULP variants, `46dae79c…`, `475786be…` and `4c5c0593…`.
  - FMA on/off also changes every downstream floating-point operation, with the same result.
- **Linux's field differs from macOS's only below 1e-9:** the quantized `cross-field` hashes are equal.
- **Field generation is not portable, but this is recorded, not owned.** BunnyRandom's field digest takes four values on four builds:

  | Build | `fieldBits` |
  |---|---|
  | Linux | `03ee413e…` |
  | macOS default | `76b1646b…` |
  | FMA off | `134a0152…` |
  | GCC/libstdc++ with FMA off | `fa5eaf2b…` |

  The contributors are FMA contraction and the library complex algorithms:
  - `std::pow(z, 4)` is repeated squaring in libstdc++ and `exp(4·log z)` in libc++;
  - complex division is Smith's algorithm (`__divdc3`) in libstdc++ and `logb`/`scalbn` scaling in libc++.

  libm (glibc against Apple) also contributes, because C still differs from Linux.
- **Disposition:** making the generator bit-portable would need a libm-free generator. No requirement asks for that, and output is robust to this noise. The fixed-field replay is withdrawn.

#### RA-204.4 O30 root cause: arrangement cell ids follow `std::sort`'s unspecified order

1. **Randomized tie order changes the result on one platform** (build D, four processes each):

   | Case | What stays the same | What changes |
   |---|---|---|
   | Vase | field, tracing, strands and `embedding` (`909330af…`) | `arrangement` takes four values; completed quads are **67,753 / 67,806 / 67,827 / 67,809**, all RED `SelfIntersectingFace` |
   | CloseSheets | `embedding` | `arrangement` takes four values; completion is unchanged |
   | Plane, MultiFaceSeam, Cylinder | every hash | nothing |

   Linux's 67,784 and macOS's 67,829 are two draws from this distribution.
2. **Site.** The sort probe instrumented all 44 `std::sort` calls in `SurfaceArrangement.cpp` and counted adjacent pairs that compare equal.
   - **The defect is at line 6762.** `pendingCells` is sorted by `cell_cycle_key`, and `cell.id` is then assigned in sorted order. Distinct cells share a key: 18 pairs among CloseSheets' 202 cells, and 10,891 pairs among Vase's 26,817. The key is a sorted set of undirected canonical edges plus source faces, so it is not injective.
   - **The other flagged sites are harmless.**
     - 2049, 2274 and 5881 sort plain values;
     - 5762 and 6744 sort keys whose equivalent elements are equal and are then de-duplicated.
3. **Fix, verified.** CB90 breaks ties by `lhs.halfedges < rhs.halfedges`. Every halfedge belongs to exactly one cell, so the order becomes total. Halfedge ids do not depend on tie order: build D's arrangement is invariant once the fix is in.

   | Build | Case | Result with the fix |
   |---|---|---|
   | D, four processes | CloseSheets | `arrangement` `5612032b…` every time |
   | D, four processes | Vase | `arrangement` `e7575660…`, `completion` `7ef76208…`, **67,746**, RED `SelfIntersectingFace`, every time |
   | B, deterministic | Vase and CloseSheets | the same values |
   | B, deterministic | Plane, MultiFaceSeam, Cylinder, BunnyRandom | unchanged |
4. **Why nothing caught it.**
   - Each library is deterministic, and two macOS runs agree byte for byte (RA-203.7).
   - Only a second sort implementation exposes the defect: Linux, or libc++'s randomization.
   - A single-platform unit test cannot observe it, so CB90 adds no test. Build D is the oracle, and TB80's comparison (RA-204.9) is the cross-platform falsifier.
5. **The completion count is still sensitive to cell order.** The spread is 67,746 to 67,829 over five orders, and RA-204.4 does not fix that sensitivity.
   - Once the order is total it is deterministic, so this is no longer a determinism defect.
   - That a valid layout depends on processing order belongs to P13-l. The completed mesh is RED in every order.

#### RA-204.5 O30b: Linux-only Vase embedding difference (open, discriminated by TB80)

Linux's Vase `embedding` differs from macOS's (`f2fc0cca…` against `909330af…`), with equal counts. The embedding is upstream of CB90, and randomization does not move it on macOS. Only one candidate remains open; the others are excluded or tie-broken:

| Candidate | Status |
|---|---|
| Sort ties | excluded by build D |
| FMA | excluded: on and off agree |
| ±1-ULP field noise | excluded |
| Unordered containers | none in tracing, FlowRep or the arrangement |
| Priority queues in tracing (lines 3807, 10173, 10491) | tie-broken |
| libm differences, the x86 80-bit `long double` in the tracing grid key (`SurfaceCellTracing.cpp` 7768) and a single 1e-9 quantization flip in the embedding hash | open |

The embedding hash quantizes about 186,000 barycentric doubles, so one flip from last-bit noise is plausible. That would be a hash difference with no semantic difference. TB80's Vase count decides (RA-204.9).

#### RA-204.6 O31 (new): relief critical points are decided by rounding noise

| Fixture | Linux | macOS default | macOS FMA off |
|---|---|---|---|
| CloseSheets relief branches | 40 | 38 | 40 |
| Cylinder relief branches | 44 | 44 | 48 |
| Plane relief hash | `b41394be…` | `0f8d74ab…` | `b41394be…` |

The inputs are bit-identical. FMA off reproduces Linux on Plane and CloseSheets, but not on Cylinder.

- **Mechanism.** `compute_salience_relief` forms a five-term weighted sum, which the compiler can contract into FMA. `analyze_relief_topology` then classifies critical points by exact `!=` comparison with an index tie-break (`symbolic_less`). On near-constant relief (flat or cylindrical regions), rounding noise picks the critical points.
- **Effect today.** None on completed topology: completion hashes are equal across the three builds for all four gate fixtures. It is still a determinism defect under the RA-176 rule.
- **Owner.** `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (Review, Claude, scratch build), after P13-l. It is not CP3-blocking unless a fixture's completed topology changes across FMA on and off. That is its falsifier.

**Recorded, no new obligation:**
- The cell sort rebuilds `cell_cycle_key` on every comparison: 962,136 key builds and 8.2 s per Vase run on macOS, which is 7.5 %. A decorate-sort would cut it to 26,817 builds. This is an addendum to O20, owned by the performance slice.

#### RA-204.7 CB90 — exact patch (`M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK`)

- **Precheck:** `git diff --quiet 9c9616695ecdc8c6ec219eb7486cbe85f3915c95 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB90_P13_Arrangement_Cell_Order_Tiebreak.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB90_P13_Arrangement_Cell_Order_Tiebreak.diff"), applied byte for byte.
  - SHA-256 `0931939d461ad2d19a6e45e9d39fb5ba130c9846a0bd286b7a9dda0d0228ab24`.
  - 36 lines. Keep its 1 single-space context line.
- **Content:**
  - the `pendingCells` comparator in `build_surface_cell_complex` gains the halfedge tie-break and a 3-line comment;
  - the CB89 digest comment in the test is corrected.
- **Numstat and resulting SHA-256:**

  | Numstat | File | Result SHA-256 |
  |---|---|---|
  | `9 1` | `src/geometry/SurfaceArrangement.cpp` | `94d4b4e9ba3372f87f9c5854f9735efa0ecf06853a9a4a0f6cd6bcc3f6179ad9` |
  | `3 1` | `tests/SurfaceCellDesignAcceptanceTests.cpp` | `2216e82e8d2da2e20c60f5063d7aec184daaece5900573866b58005c31945c35` |

- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`. No test is added, so membership stays 980.
- **Routes:**
  - success → TB80;
  - precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-CELL-ORDER-STOP`;
  - infrastructure → `M6-CP3-CB90A-P13-ARRANGEMENT-CELL-ORDER-ORCH` (one retry).

#### RA-204.8 TB80 — full gate and census (`M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC`)

- **Package:** the immutable CB90 package only, with no rebuild.
- **Gate:**
  - the TB78 manifest, 899 rows (`9d2c1ec5…`), reused unchanged, with ledger v5 (81);
  - **899/899**, membership 980;
  - rows 795, 796, 797 and 864 each log exactly one `platform-digest` line.
- **Census:** the three-case manifest `3af1dc0d…`, 600 s ceiling.
  - Cylinder PASS.
  - BunnyRandom RED P13-e at `sourceVertex=49`.
  - **Vase RED `SelfIntersectingFace` within 600 s, with trace segments 192,482 and arrangement cells 26,817.** Both counts are Linux-observed and upstream of CB90.
  - **Record `completedQuads` without pinning it** (RA-203.2).
  - Each census log has exactly one digest line.
- **Record:**
  - the seven digest lines, verbatim;
  - the comparison table in RA-204.9, as observations, not criteria.
- **Routes:**
  - match → the Review track's P13-l DEFN, which adjudicates O30 from the table first;
  - mismatch (any verdict change, a gate RED, or a missing or duplicate digest line) → `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB80A-P13-ARRANGEMENT-CELL-ORDER-ORCH`.

#### RA-204.9 macOS post-CB90 reference and the frozen O30 decision table

[`Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv") holds 129 rows from build B with CB90 (SHA-256 `955223c86c78c4ffd30dbc20fdb39a44f14cefbea271acf036d1cad59299a7d6`). FMA off was chosen because it matches Linux arithmetic for contraction.

**What TB80 records** (each Linux value next to its reference value):

| Item | Reference | Prediction if CB90 is the whole cell-order defect |
|---|---|---|
| CloseSheets `embedding` | `67442dd8c6025d7f/1128` | equal (TB79 Linux already equal) |
| CloseSheets `arrangement` and `simplification` | `5612032bbe02f5df/202` | **equal** |
| Plane, MultiFaceSeam, Cylinder `arrangement` | as TB79 Linux | equal |
| Vase `embedding` | `909330af789bee4c/30989` | O30b: equal or not |
| Vase `arrangement` and `completion` | `e7575660c00edebe/26817`, `7ef762088d515416/67746` | equal only if O30b is a hash-only difference |

**How the Review decides, at the start of the P13-l DEFN:**
- **CloseSheets equal and Vase 67,746:** O30 is closed, and future Vase registrations may pin 67,746 because Linux has then produced it.
- **CloseSheets equal, Vase different:**
  - O30a (cell order) is closed;
  - O30b stays open, and its first measurement is a semantic embedding digest on Linux. That needs an exact test-only CB, defined then.
  - P13-l continues on macOS, and its TB pins only Linux-observed counts.
- **CloseSheets different:** another library-dependent order exists in the arrangement, one that libc++ randomization does not reach (heap or iteration order). This routes to `…-FULL-GATE-REV` (Review, Claude, scratch build).

#### RA-204.10 Trajectory and turn sequence

**Trajectory.** O30 has cost two implementation turns (CB89 and TB79) and two Review turns. Its root cause now has a 9-line fix.
- P13's critical path is P13-l. Vase is RED `SelfIntersectingFace` in every cell order, so the completed mesh is not consistently oriented whatever the order.
- O30 must not take more implementation turns unless a single turn decides it. TB80 does: it is the gate any product change needs anyway.
- P13-l starts from the post-CB90 state, which is deterministic across libraries, so its macOS probes predict Linux better.
- The Review track's P13-l DEFN may start now, on build B with CB90 and macOS 67,746. Its TB must pin only Linux-observed counts.

| Step | Turn | Track |
|---|---|---|
| 42D — Review COMPLETE | `M6-CP3-DEFN-P13-PLATFORM-SPLIT` | ChatGPT; reviewed and partly withdrawn by RA-204 |
| 42E — Review COMPLETE | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` | RA-204: field branch withdrawn; O30a root cause; exact CB90 |
| 42F — NEXT | `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK` | Implementation agent, Linux; compile only |
| 42G | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC` | Implementation agent; 899/899; census; seven digest lines; RA-204.9 table recorded |
| 43 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, post-CB90. After TB80 it opens with the RA-204.9 O30 decision |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Claude, scratch build |
| 44A (Review, after P13-l) | `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (O31) | Claude, scratch build |
| 45 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes 42F and 42G, one turn each, and starts 42G only after 42F is verified.

#### RA-204.11 Scratch verification

| Check | Result |
|---|---|
| Scratch tree = HEAD source | `diff -rq` against `git archive HEAD` (`src include tests benchmarks cmake`, `CMakeLists.txt`): no differences before the probes |
| Build B is FMA-free | 0 `fmadd`/`fmsub`/`fnmadd`/`fnmsub` and 0 `fmla`/`fmls` in `libdirectional_core.a` and `libdirectional_pipeline.a` |
| CB90 on a clean worktree at HEAD `6be82f33c` | Precheck passes; `git apply --check` and `git apply` succeed; numstats and result hashes as in RA-204.7; code identical to the tested tie-break (comments aside) |
| Randomized build D | Full rebuild; four processes per case; results in RA-204.4 |
| Local gate, build B + CB90 (TB78 manifest, 899 rows, one process per row) | **898/899** in 1 min 42 s. The only RED is row 283, `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`: O16, the pre-registered macOS legacy NFunctionMesher failure, which is not SurfaceArrangement. No new RED |
| Census on build B + CB90 | Cylinder PASS; BunnyRandom P13-e RED; Vase RED `SelfIntersectingFace`, 192,482 / 26,817 / 67,746 in 108.8 s; one digest line per case |

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The TB78 manifest was re-hashed here (`9d2c1ec598fea2b9…`, 899 rows) and is reused unchanged by TB80. Accepted CP2 selector unchanged |
| Decisive claims independently re-derived | Seven Linux lines re-parsed against both references. Atlas digest semantics read at source (`FieldTransportAtlas.cpp` 1840/1866). Noise carriers measured, not inferred. The cause localized by randomized ties, then a sort-site probe, then a fix verified under randomization |
| Non-vacuity checked | Build D does change outcomes: four distinct Vase counts and four CloseSheets arrangements without the fix. The fix makes them constant. Unaffected fixtures (Plane, MultiFaceSeam, Cylinder) stay constant in both, so the probe separates the two cases |
| Prior obligations discharged/carried | O30 is split. O30a has its root cause and exact fix CB90, discharged when TB80's CloseSheets row matches. O30b is open (RA-204.5). Carried: P13-l, P13-e, O27–O29, O16, O19, O6, O9, O25, O26, DR1/DR3 |
| Stable accounting | 66 / 17 / 49, debt 1; accepted CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O31 (relief noise), O30a/O30b, an O20 addendum (cell-sort key cost) |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, RA-204 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 M6-CP3 row; §4 n/a; §7 O30/O31 and Next; §8 "Platform split" gains the noise-carrier and randomized-tie rules |
| CHANGELOG | RA-204 entry added |
| ROADMAP | n/a: no milestone or checkpoint state changes |
| Selector manifest | n/a: TB80 reuses the TB78 manifest; CB90 adds no test |
| LESSONS | New lesson on randomizing unspecified order before attributing a platform split |
| Consolidation under CLEAN_UP_POLICY | The ChatGPT O30 Review is retained as evidence with a closure line. The handoff's "Earlier: TB78" section is folded to a link |
| Successor frozen | CB90 (RA-204.7), TB80 (RA-204.8), O30 decision table (RA-204.9) |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; the patch is a committed `.diff`. Scratch probes only |
| review_check.py boundary | See the commit record: `boundary` and `ledgers` are run before the push |
| `STATUS` lifecycle maintained | Turn `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, COMPLETE, Successor `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK`, Ended at the final write; the canonical block only. Started at 2026-11-05T02:18:42Z is preserved from the turn's first repository entry, which a concurrent ChatGPT session wrote (`96aca2a7c`, with source-snapshot trigger `962882503`). This Review began at 01:34:01Z without publishing an entry beacon; that lapse is owned, and it let the second session start. RA-204 supersedes that session's work on this turn |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md`; moved verbatim.

### RA-207 — Review of the O32a seed Review: the mechanism holds; CB92 becomes an exact, capability-preserving patch (2026-11-05)

**Reviewed turn:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (ChatGPT, closed `cb2c68539`). Its records:
- [WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_WIP_20261105.md");
- [producer scratch result](#architecture_m6_cp3_defn_p13_o32a_vase_producer_scratch_result_20261105md "moved: Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md");
- [CB92 plan](#architecture_m6_cp3_cb92_p13_source_vertex_fan_seed_identity_plan_20261105md "moved: Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md");
- scratch branch `origin/scratch/p13-o32a-seed-review-20261105`.

This re-entry reviews them. It keeps the successor ID `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY` and replaces the plan with an exact patch.

**Source:** HEAD `cb2c68539` (CB91 product source; TB81 899/899 MATCH).

**Scratch build:** `bld55n`, FMA-off clang/libc++ static. `diff -rq` against `git archive HEAD` showed no difference before the patch. The census probe TU has `PROBE_PERMUTE_FACES` (RA-205). Scratch-only `PROBE_SEED_DIGEST` and `PROBE_MULTIFAN_LOG` instrumentation was in the scratch copy and is not in the patch.

#### RA-207.1 What the O32a Review got right (independently re-derived)

- **The mechanism.**
  - `vertex_point` places a vertex seed in `incident[vertex].front()`, the lowest source-face row.
  - `initialize_seed` de-duplicates on (face row, barycentrics).
  - So whether a vertex seed collides with a rail seed at the same vertex depends on row order. Vase gives 1,456 / 1,460 / 1,458 / 1,455 seeds. RA-205 measured 1,456 / 1,461.
- **The scratch remedy works.** Placing vertex-origin seeds by typed `SourceVertexEntityIdentity` fan, at the fan's minimum `SourceProjectionChart`, makes the seed set row-invariant.
  - Re-derived here on a fresh build: **1,416 seeds** in four orders, with an identical sorted digest over position, provenance and source id (`8b4ef97c…`).
  - Trace counts are **189,462** and strand counts **30,989** in all four orders.
  - Completed quads still vary (67,750 / 67,771 / 67,773 / 67,786). That is O32e (completion ownership repair), as RA-205 named.
- **The Vase fan audit is correct.** Every Vase vertex has one intrinsic fan.
- **The invalid one-sample rail control was correctly retracted.**

#### RA-207.2 Defects

1. **The CB92 plan is not an exact patch** — the third Review in a row to give the implementation agent a design instead (TB80-REV's CB91 was the second).
   - It describes a redesign across five seed classes and a new fail-closed terminal outcome "through the existing `SurfaceCellNetwork`/pipeline outcome".
   - It then says: "if no truthful existing failure reason supports it, STOP for a … Review amendment".
   - A turn whose own spec says it may be unimplementable is monolithic by construction.
2. **Fail-closed on multi-fan vertices is a capability regression, and the case it targets is not measured.**
   - Today a seed request on a vertex split by a hard barrier produces one seed, in a row-chosen fan. The plan turns that input into a terminal failure.
   - The code's own precedent goes the other way: a hard-rail sample is seeded in **both** incident face charts "instead of depending on the arbitrary provenance face" (`SurfaceCellTracing.cpp`, rail seeding).
   - A barrier blocks traces, so a seed in one fan cannot cover the other. Seeding each unseeded fan is the coverage-complete, row-invariant choice: a typed canonical rule, as DESIGN §10.1 asks.
   - The plan calls that "unauthorized duplication". It is the same both-sides rule already applied to rails.
3. **The gate impact was never measured.** No scratch gate ran with the remedy. Measured here (RA-207.4):
   - **no vertex-origin request in all 899 gate rows lands on a multi-fan vertex** (positive control: the new split test logs 2 events);
   - the chart graph is never unavailable.

   So the fail-closed path would have shipped untested by the gate. A capability loss would have stayed invisible until a feature-bearing input arrived.
4. **The falsifier design is not gateable.** "Four consistent Vase face/field permutations" as a product test means four full Vase pipelines (about 100–270 s each). The mechanism needs a millisecond synthetic test whose legacy outcome depends on row order (RA-207.3).
5. **Residual, not owned by the plan.** `AdaptiveSeedCandidate::operator<` still breaks distance ties by face row. RA-205.4 showed it does not fire on Vase. It is still a §10.1 non-conformance; it is recorded under O32a, to fix when that code is next touched.

#### RA-207.3 CB92 — exact patch (`M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY`, ID kept)

- **Precheck:** `git diff --quiet 96ee281a40920f21eb911880a3b2c458ef4f0563 HEAD -- src include tests benchmarks CMakeLists.txt cmake` (the CB91 source).
- **Patch:** [`Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity.diff").
  - SHA-256 `c377b206c195613b045b0f5a431df5dc31e553035343b567cdeb2ba0751834fa`.
  - 285 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/SurfaceCellTracing.cpp` | `77 15` | `9e9b979f0976f3c1714e1dbcddd4d973b21f3268e443cff7518bbd4a987a4c7b` |
  | `tests/SurfaceCellREPackageTests.cpp` | `141 0` | `a169667c6c6705be547b257295e6d9eb5ea2d1f933f6958370c7e806cbb28e90` |

- **Product content.** Changes are confined to `generate_deterministic_surface_seeds`.
  - **Where it applies:** with source authority and an available `SourceChartTransitionGraph`, built on the existing combined barrier set.
  - **Which seeds:** every seed named by a source vertex — field-aligned or legacy singularities, relief critical points and roots, relief-region representatives, separatrices and anchors.
  - **The rule:** each such seed resolves the vertex's incident faces to typed fans. **Each fan not already holding a seed gets one, at its minimum canonical chart.**
  - **What counts as held:** fans already holding a rail or earlier vertex seed, known by typed identity.
  - **Unchanged:** rail seeding; provenance and source ids; adaptive coverage. Without authority, the legacy `vertex_point` path keeps its documented contract.
  - **What the patch adds:** no exception, no new type, no new terminal outcome.
- **Tests** (producer binary; new gate rows 900–901):

  | Row | Test | What it checks |
  |---|---|---|
  | 900 | `SurfaceCellTracingPhase14.VertexSeedsFollowSourceVertexFansNotFaceRows` | A boundary-rail sample on vertex 1 in face (1, 5, 4), with relief requests on vertices 1 and 4, in two row orders. The rail's face is first for vertex 1 in one order only. Asserts no relief seed on vertex 1 (its fan holds the rail seed), exactly one on vertex 4, and identical seed multisets (position, provenance, source id) in both orders. **Legacy fails:** one relief seed on vertex 1 in one order, and different multisets |
  | 901 | `SurfaceCellTracingPhase14.VertexSeedsCoverEachHardBarrierFanInBothRowOrders` | Vertex 0 of the two-triangle grid, coalesced or split by hard barrier (0, 3). Asserts 1 or 2 relief seeds, one per distinct typed fan, with the same fan sets in both orders. **Legacy fails:** 1 seed when split |

- **Verified in scratch:**

  | Check | Result |
  |---|---|
  | Local 901-row gate | **900/901** (only row 283, O16); rows 900–901 PASS |
  | Census, Plane / MultiFaceSeam / CloseSheets / Cylinder | **unchanged**, every digest item |
  | Census, BunnyRandom | unchanged (stops before tracing) |
  | Census, Vase | changes from `tracing` on: 189,462 traces, 30,989 strands, 26,817 cells, 67,750 quads; still RED `SelfIntersectingFace` |
  | Four-order Vase | seed digest identical; trace and strand counts identical |
  | GCC 16 `-Wall -Wextra -fsyntax-only` | clean |
  | Patch on a clean worktree at `cb2c68539` | applies and reproduces the tree |

- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.
- **Routes:**
  - mismatch → `M6-CP3-PLAN-P13-SOURCE-VERTEX-FAN-SEED-STOP`;
  - infrastructure → `M6-CP3-CB92A-P13-SOURCE-VERTEX-FAN-SEED-ORCH`.

#### RA-207.4 Measurements

| Measurement | Result |
|---|---|
| Multi-fan census (`PROBE_MULTIFAN_LOG`, full 899-row gate) | 0 vertex-origin requests on multi-fan vertices; 0 graph-unavailable events. The positive control (row 901, split case) logs 2 |
| Vase, four orders (original + `PROBE_PERMUTE_FACES` = 1, 2, 4) | seeds 1,416 / 1,416 / 1,416 / 1,416 (digest `8b4ef97c…` all); traces 189,462 ×4; strands 30,989 ×4; cells 26,817 ×4; quads 67,750 / 67,771 / 67,773 / 67,786 |
| Vase stage digest vs post-CB90 reference | identical through `global-conformity-baseline` (`895d709f…/299`); differs from `tracing` (`2317b75c…/189462`) onward |

#### RA-207.5 TB82 — `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC`

- **Package:** the immutable CB92 package, artifact-only.
- **Gate:** [`Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv").
  - 901 rows, SHA-256 `9fbf329167cbe84698d5a08eda6e5374200c7729a5f0f1e4292836227902f878`.
  - TB78's 899 rows byte for byte, plus GUARD rows 900–901.
  - `SELF_CHECK_PASS cases=901 deferred=81` with ledger v5.
  - **901/901**, membership **982**.
- **Census:** manifest `3af1dc0d…`.
  - Cylinder PASS.
  - BunnyRandom P13-e at vertex 49.
  - Vase RED `SelfIntersectingFace` within 600 s.
  - Trace segments, arrangement cells and `completedQuads` are **recorded, not pinned**: CB92 changes Vase tracing, and Linux has not observed the new values.
- **Pinned digest falsifiers,** all Linux-observed:
  - gate rows 795, 796, 797 and 864, and census rows 1 (Cylinder) and 2 (BunnyRandom), byte-identical to TB81;
  - census row 3 (Vase) byte-identical to TB81 **through `global-conformity-baseline`**. The items from `tracing` on are recorded.
- **Routes:**
  - match → the Review track (RA-207.6);
  - mismatch → `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB82A-P13-SOURCE-VERTEX-FAN-SEED-ORCH`.

#### RA-207.6 Trajectory and turn sequence

- **O32a closes when TB82 matches.** Seeds are row-invariant and so are trace and strand counts.
- **O32 continues downstream.**
  - O32b/c, the content of traces and strands, need a row-invariant semantic digest. Counts are already equal.
  - O32d, the canonical cell key.
  - O32e, completion's ownership-repair tie and budget, is the remaining count-level dependence (67,750–67,786).
- **P13-l (Vase orientation) starts on the post-CB92 state.** Its verdict is the same in every order.

| Step | Turn | Track |
|---|---|---|
| 42J — COMPLETE | `M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE` | Implementation agent (`96ee281a4`) |
| 42K — COMPLETE (MATCH) | `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC` | 899/899, seven digests pinned |
| 43 — Review COMPLETE (re-entered) | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a) | ChatGPT, reviewed by RA-207 |
| 43A — NEXT | `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY` | Implementation agent; RA-207.3, exact |
| 43C | `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC` | Implementation agent; RA-207.5 |
| 43B (Review) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, post-CB92 |
| 44 / 44A (Review) | P13-e; O31 | Claude, scratch build |
| 44B (Review) | O32e first (the count-level dependence), then O32d, O32b/c | Claude, scratch build |
| 44C (Review) | O33 chart-face per-quad cost | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB78 899-row prefix of the new 901-row manifest is byte-identical (`9d2c1ec5…`); harness self-check PASS |
| Decisive claims independently re-derived | Mechanism read at source. Four-order seed, trace and strand invariance on a fresh build. Multi-fan census of the whole gate with a positive control. Census digests. Full gate |
| Non-vacuity checked | Both new tests FAIL on the legacy `SurfaceCellTracing.cpp` and PASS on CB92. The multi-fan logger fires on the split control |
| Prior obligations discharged/carried | O32a → CB92/TB82. O32b–e, O33, O30b, O31, P13-l, P13-e, O27–O29, DR1/DR3 carried. AdaptiveSeedCandidate tie recorded |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O32a residual (adaptive tie); none new otherwise |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` re-entered, RA-207 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 updated; §8 adds the both-sides rule; §3 and §4 unchanged |
| CHANGELOG | RA-207 entry |
| ROADMAP | n/a |
| Selector manifest | New 901-row TB82 manifest (two GUARD rows), self-checked |
| LESSONS | Measure the gate impact of a policy before freezing it, and prefer the codebase's existing symmetric rule over a new failure mode |
| Consolidation under CLEAN_UP_POLICY | The O32a records are retained, each with a review line; the CB92 plan is marked superseded |
| Successor frozen | CB92 exact (RA-207.3), TB82 (RA-207.5) |
| Turn boundary held | No product, test, fixture or build source changed in the repository; the patch is a committed `.diff`; the manifest is new. Scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Re-entry beacon pushed (Resumed at 2026-11-05T14:03:47Z); COMPLETE with Successor CB92 as the final write |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_DEFN_P13_Seed_Capture_Analyzer_Correction_WIP_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Seed_Capture_Analyzer_Correction_WIP_20261105.md`; moved verbatim.

### O32a scratch capture analyzer correction — WIP evidence

**Canonical review:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS`. This note supplements, but does not supersede, `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_WIP_20261105.md`. It must be consolidated into the primary review before formal closeout.

#### Finding and correction

The previous scratch analyzer hashed sorted source-triangle corner/barycentric entries together with 3D position/provenance. A source vertex represented from a different incident triangle therefore changed its allegedly semantic digest even when its semantic position and provenance were identical. This is a **diagnostic false-positive risk**, not independent proof that production seeds differ.

Prepared `analyze_o32a_captures_v2.py` separates `semantic` candidate identity (position/provenance/source) from `representation` identity (semantic values plus full triangle support). It rejects missing phases, mismatched per-phase seed counts, empty coverage, missing explicit termination, invalid seed-face markers, and different source-face-triple multisets. Two non-vacuity checks ran locally: chart-representation changes were detected without a semantic-digest difference; incomplete phase inventory caused a nonzero exit. **No C++ producer was built or executed.** Position/provenance identity is not itself sheet/fan/hard-rail identity, so further instrumentation remains mandatory.

#### Remote scratch preparation

Previous two-file scratch-only instrumentation patch was wrapped with standard exact transport metadata and verified by `git apply --check` on source `4e151e5c139d09ecabca663ea1125d0544c32abb`. Raw Drive staging object in `My Drive/Directional-CI`: ID `1kucBxUvhEqvOVJUg4Ia04jDa1XKCU8Uo`, title `Directional__O32a__review_scratch_only.patch`, 6,791 bytes, MIME `text/x-diff`, SHA-256 `9a19f8386d3acb6a904e264f86fff4496f3dc4662bbd0da82e676a9e411427fe`. Metadata was read back. It has **not been applied or consumed**; retain until deliberately executed/retired. The source snapshot's 6,184 per-file hashes passed from the correct snapshot root.

The permanent dispatcher cannot insert a scratch patch into its immutable `compile` workload; a disposable scratch branch/caller would need a validated, strictly bounded policy exception and cleanup. None was created. Do not modify production source/tests/selector on the working branch or misreport scratch evidence as a TB gate.

#### Status and required next evidence

**Review remains IN_PROGRESS**. Actual producer logs across base plus >=3 face-row permutations, exact upstream-input comparison, earliest seed-phase classification, fan/rail-safe candidate falsification, downstream trace/strand remeasurement, and the mandatory Review closeout/checklist are pending. No Code + Build successor has been frozen. This note and its companion chat evidence archive are preservation only.

## `Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md`; moved verbatim.

### RA-205 — Review of `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` (RA-204): cross-library fix confirmed, DESIGN §10.1 row-permutation invariance fails (2026-11-05)

**Turn:** a re-entry of `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` for an adversarial review of its only record, [RA-204](#architecture_m6_cp3_defn_p13_platform_split_review_arrangement_cell_order_20261105md "moved: Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md"), and the exact CB90. A concurrent ChatGPT session opened this turn (`96aca2a7c`) and only removed its snapshot trigger (`617f5c2e4`). It produced no record.

**Source:** HEAD `617f5c2e4`. `git diff --quiet 9c9616695 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes. CB90 is not applied on origin.

**Scratch build:** RA-204's build B, with CB90's tie-break, is an FMA-off clang/libc++ static build of the HEAD source. The census probe TU gains `PROBE_PERMUTE_FACES=SEED`. It applies a consistent row permutation to `mesh.faces` and `field.raw` after the field is generated, so mesh, field and corner order are identical and only row order changes. The tracing probes in RA-205.4 were reverted afterwards.

#### RA-205.1 What RA-204 got right (re-verified)

- **The cross-library mechanism.** Arrangement cell ids follow `std::sort`'s unspecified order for equal `cell_cycle_key`s, and that order differs between libc++ and libstdc++. Randomized ties vary Vase between 67,753 and 67,827 quads. With CB90 applied, the count is 67,746 in every order.
- **CB90 is correct for its stated purpose,** which is that one input gives one output whichever standard library builds it.
- **No other unspecified order in the stages RA-204 relied on:**
  - **Completion's hash containers** (7 in `PureQuadCompletion.cpp`) were not checked by RA-204. They are order-safe: the loops over `canonicalQuadDuplicateOwners` (3371, 3586) only sum bytes or fill `ownershipConflicts`, which is then sorted and de-duplicated. The other maps are only looked up.
  - **The simplification queue** (`QueueEntry`) is tie-broken by `stableId`.
  - **The arrangement** has no heap or `std::partition`.

#### RA-205.2 Accuracy and completeness defects in RA-204

1. **"This is no longer a determinism defect" (RA-204.4 item 5) is wrong.** DESIGN §10.1 is normative:
   - *"Canonical ordering uses semantic tuples of typed source identities. Hashes, object addresses, thread completion order, source-face row order, and output row order do not participate."*
   - *"region and producer scheduling permutation preserves [the semantic output digest]"*.

   RA-204's own randomized runs show the completed-quad count changing with the cell schedule alone (embedding fixed). That violates §10.1, so it is not only a P13-l quality matter. The owner is completion's ownership repair (`PatchDescriptor.cpp` 3120–3150). It greedily covers the conflict graph, breaks equal degree by **patch id** (that is, cell id), and spends a bounded repair budget, `maxCompletionOwnershipRepairs`.
2. **CB90's tie-break is a representation order.**
   - Halfedge ids follow segment construction, which sorts by `sourceFace` row index (`SurfaceArrangement.cpp` 1904).
   - CB90 therefore replaces a library-dependent order with a source-face-row-dependent one.
   - It makes Linux and macOS agree, but it is not §10.1-conformant.
   - The canonical key `cell_cycle_key` is far from injective: 10,891 tied pairs among 26,817 cells. Its nodes are identified only by the source entity that holds them, and most cells lie inside one source face.
3. **"Linux's 67,784 and macOS's 67,829 are two draws from this distribution" overclaims.** O30b, Linux's different Vase embedding, is still open. Only CloseSheets, whose embedding is equal on both platforms, can attribute a Linux difference to cell order alone.
4. **RA-204 measured no metamorphic invariant.** DESIGN §10.1 lists them as mandatory. M3 requires "tracing-order and start-port permutation invariance passes" and M6 requires "source-row, output-row, and scheduler permutation invariance passes" (DESIGN §14). A platform-determinism review should have run the cheapest one, a source-face row permutation. RA-205.3 does.

#### RA-205.3 Source-face row permutation (measured)

| Stage element count | Unpermuted | Seed 1 | Seed 2 | Seed 3 | Seed 4 |
|---|---|---|---|---|---|
| source … `global-conformity-baseline` (13 stages) | as unpermuted | same | same | same | same |
| `tracing` (segments) | 192,482 | 192,979 | 192,770 | 193,624 | 193,432 |
| `strands` = `embedding` | 30,989 | 30,998 | 30,998 | 31,008 | 31,008 |
| `arrangement` = `simplification` | 26,817 | 26,817 | 26,817 | 26,817 | 26,817 |
| `completion` (quads) | 67,746 | 67,771 | 67,777 | 67,777 | 67,784 |
| verdict | RED `SelfIntersectingFace` | same | same | same | same |

- **CloseSheets:** 200 quads and PASS under three permutations. Its hashes differ, as expected: they embed row indices and are same-artifact diagnostics only (§10.1).
- **Reading.** The first stage whose count depends on source-face row order is **tracing**. Every later count inherits that dependence, and completion adds its own (RA-205.2 item 1).
- **This is new obligation O32:** production violates the §10.1 source-face-row metamorphic invariant on Vase. It is an M6 exit (CP3-exit) blocker, and it is not platform-specific.

#### RA-205.4 Localizing O32's first owner (scratch probes)

1. **Refuted lead: the adaptive seed candidate tie.** `AdaptiveSeedCandidate::operator<` (`SurfaceCellTracing.h` 2770) breaks distance ties by face row.
   - I replaced it with the face's sorted vertex triple, which is row-invariant.
   - Unpermuted and permuted Vase results were then bit-identical to the earlier runs (tracing `6c19b74c…` / `086e21f9…`, quads 67,746 / 67,771). This tie is not the owner.
2. **First owner: the seed set.** A row-invariant digest of the seeds compared the base run with permutation seed 1. It sorts the seeds' 3D positions, rounded to 1e-7, together with their provenance. The canonical candidate tie was still in place.

   | Run | Seeds | Sorted-position digest |
   |---|---|---|
   | unpermuted | **1,456** | `192d254c…` |
   | permutation seed 1 | **1,461** | `43b925de…` |

   So `generate_deterministic_surface_seeds` (`SurfaceCellTracing.cpp` 10297) is row-order dependent. That is upstream of every trace.
3. **Remaining candidates, for the DEFN to discriminate.** Leads, not conclusions:
   - rail-sample seeding and its `seen` de-duplication key (a sample on a shared edge belongs to two faces);
   - the face-corner node layout of `intrinsicGraph` and its `nearest` distances;
   - seed placement toward the chosen face's centroid.

#### RA-205.5 Realignment

- **CB90 → TB80 stand unchanged** (RA-204.7–.9).
  - CB90 is narrow and verified (local gate 898/899, only O16). It is what makes macOS Review probes predict Linux.
  - It is interim with respect to §10.1, not wrong. A canonical, injective cell key (O32, item d below) would leave its tie-break unreachable but harmless. No rework is planned.
- **O32 is now a CP3-exit condition,** added beside "matrix 6/6" in TODO. It is owned by a Review program, one stage at a time and upstream first:

  | Item | Stage | Owner |
  |---|---|---|
  | a | seed set | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (next Review turn) |
  | b | tracing proper | named once (a) is invariant |
  | c | strand selection | named once (a) is invariant |
  | d | arrangement cell identity | an injective canonical key: node identity plus exact barycentrics on the canonical source entity |
  | e | completion ownership repair | a canonical tie and a budget independent of order |

  Each item gets one probe DEFN and one exact CB/TB pair. Its falsifier is the stage count, plus a row-invariant content digest, under three or more permutations.
- **Upstream first, then P13-l.**
  - The seed fix will change every Vase trace, so registrations taken before it would churn. The P13-l DEFN therefore runs on the post-seed-fix state.
  - The P13-l verdict (`SelfIntersectingFace`) is invariant under permutation, so its diagnosis is not blocked: only its registrations wait.
  - P13-e (BunnyRandom, stops at the atlas, upstream of tracing) is unaffected and may run in parallel.
- **Pin only permutation-invariant values.** P13 registrations should pin typed verdicts and the counts shown invariant in RA-205.3 (through `global-conformity-baseline`, and `arrangement`). Trace, strand and completed-quad counts are recorded, not pinned, until O32a–e close. TB80 already records `completedQuads` without pinning it. Its pinned 192,482 trace segments is valid only for the fixed row order, and TB80 uses exactly that.
- **Gate coverage gap.** No gate row runs the production pipeline on a census fixture under a source-face row permutation. Row 2 (`SourceFaceRowPermutationPreservesOccurrenceIdentity`) covers occurrence identity on a small fixture. O32's final CB adds the metamorphic census rows once the counts are invariant.

#### RA-205.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 42E — Review COMPLETE (re-entered) | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` | RA-204, reviewed by RA-205 |
| 42F — NEXT | `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK` | Implementation agent; unchanged (RA-204.7) |
| 42G | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC` | Implementation agent; unchanged (RA-204.8) |
| 43 (Review, next) | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a) | Claude, scratch build. Make the seed set row-invariant (count and sorted-position digest equal under ≥3 permutations) → exact CB → TB; then re-measure tracing and strands and name O32b/c |
| 43B (Review, after 43) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, on the post-O32a state. After TB80 it opens with the RA-204.9 O30 decision |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Claude, scratch build |
| 44A | `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (O31) | Claude, scratch build |
| 44B | O32b–e DEFNs, one stage each, upstream first | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes 42F and 42G, one turn each. Later implementation turns come only from the exact patches those DEFNs freeze.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change; TB80 reuses the TB78 manifest `9d2c1ec5…` (RA-204) |
| Decisive claims independently re-derived | DESIGN §10.1 and §14 (M3, M6) read verbatim. Completion's hash-container loops and the repair tie-break read at source. Four Vase and three CloseSheets permutations run. Seed-set digests measured |
| Non-vacuity checked | The permutation changes row order only, so stage counts through `global-conformity-baseline` stay equal, which is a control. The seed-tie probe changed code on the seeding path, and identical output refutes that lead rather than passing vacuously |
| Prior obligations discharged/carried | RA-204's O30a, O30b and O31 carried as stated. RA-204.4 item 5 corrected. New O32a–e |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O32 (§10.1 source-row permutation), with the CP3-exit condition added |
| ORIENTATION currency line | Re-entry of `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, RA-205 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 O32 and Next; §8 "Platform split" extended with metamorphic invariance; §3 and §4 unchanged |
| CHANGELOG | RA-205 entry |
| ROADMAP | n/a |
| Selector manifest | n/a |
| LESSONS | One lesson: test the design's metamorphic invariants before calling an order-dependent result deterministic |
| Consolidation under CLEAN_UP_POLICY | RA-204 retained with a review line; nothing superseded |
| Successor frozen | CB90 (unchanged); the Review track's next turn is O32a |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Re-entry beacon pushed (`IN_PROGRESS`, Resumed at 2026-11-05T02:42:38Z); COMPLETE with Successor CB90 as the final write |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_TB80_REV_Review_Final_Validation_Binding_Per_Vertex_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB80_REV_Review_Final_Validation_Binding_Per_Vertex_20261105.md`; moved verbatim.

### RA-206 — Review of the TB80 Review: row 899 exposed a real O(F×V) binding check, and its wall clock was calibrated on macOS (2026-11-05)

**Reviewed turn:** `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` (ChatGPT, [adjudication](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB80_REV_Final_Validation_Cost_Gate_Adjudication_20261105.md"), `1b3e790aa`). It froze `M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE` as an open-ended evidence turn.

**State:**
- The implementation agent opened that CB91 at 2026-11-05T05:56:03Z (`c714b4f8c`).
- RA-206 keeps the turn ID and **replaces its content with one exact patch** (RA-206.3).
- STATUS is left to the open CB91 turn.

**Source:** HEAD `a75c9f6ff`. `git diff --quiet e00ef91a8 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes, so the source is CB90's.

**Scratch build:** `bld55n`, a macOS arm64 FMA-off static build synced byte for byte to the HEAD tree, then to HEAD + CB91 (`diff -rq`: no difference). TB80's raw gate log and result artifacts were downloaded into isolated directories and read with `python3 -I`.

#### RA-206.1 Verdict on the TB80 Review

**What holds:**
- Artifact verification;
- the census MATCH;
- the RA-204.9 comparison: CloseSheets' arrangement equals macOS, so O30a holds across platforms in fixed order, while O30b stays open;
- the refusal to retry, soften the guard or promote;
- separating stopwatch from process time.

**Defects:**

1. **No attribution of CB90.** CB90 changes one comparator in `build_surface_cell_complex` and a census-test comment. Row 899 validates a synthetic grid and never builds an arrangement, so CB90 is excluded statically. The Review instead left an "unproven performance root cause".
2. **Wrong hypothesis.** It asked whether binding is re-checked "per output quad … at the shared final validator/optimizer boundary".
   - The check is **per output vertex, inside the independent validator**: `SourceAuthoritativeMeshValidator.cpp:1186`, `matches_source_faces` inside the provenance loop.
   - The cost is dominated by per-sample chart-mask keying (RA-206.2).
   - A witness placed at "the shared owning call boundary" would not have seen either.
3. **The turn shape breaks the standing rule.** Its CB91 was conditional and investigative: "inspect … if … implement … else instrument". The implementation agent gets exact patches only; probes stay on the Review track.
4. **"Keep the existing 2.0 s gate."** On Linux the timed section runs 3.5× macOS (RA-206.2). Even with every per-quad cost removed, Linux would sit near 1.5 s, so the guard would keep flaking.
5. **"LESSONS: n/a, no proven pattern."** There is one: a wall-clock guard calibrated on one platform (RA-206.6).

**My errors, owned:**
- **RA-202.8 set the 2 s bound** from macOS's 0.7 s, without the Linux ratio that RA-202 itself had just documented.
- **CB88's test claims "after one binding check" but never counts checks.** The validation it times makes 450 full binding checks: one per output vertex, plus 9.

#### RA-206.2 Measurements (scratch, CB90 source)

**Stopwatch per gated wall-clock guard**, macOS, 5 runs:

| Row | macOS timed section | Linux/macOS whole test (TB80) |
|---|---|---|
| 888 | 0.003 s | 1.28 |
| 890 | 0.004 s | 1.26 |
| 892 | 0.29 s + 0.15 s | 1.60 |
| 893 | 0.007 s | 1.28 |
| **899** | **0.67–0.69 s** | 1.58 (but its timed section is 2.37 s on Linux, **3.5×**) |

Rows 896 and 898 run in under 0.25 s in total on Linux. Only row 899 is at risk.

**Row 899 is O(F×Q):**

| Source faces F | 100 quads | 400 quads | 1,600 quads | Per quad |
|---|---|---|---|---|
| 28,800 | 0.32 s | 0.68 s | 2.05 s | 1.14 ms |
| 7,200 | — | 0.185 s | 0.546 s | 0.30 ms |

The per-quad cost scales with F (ratio 3.8 for 4× faces). The test exists to exclude exactly this.

**Full binding checks**, counted by a thread-local probe in `matches_source_faces`:

| Output vertices | Checks |
|---|---|
| 121 | 130 |
| 441 | 450 |
| 1,681 | 1,690 |

That is **one O(F) binding check per output vertex, plus 9**, at `SourceAuthoritativeMeshValidator.cpp:1186`.

**Chart-face keying.**
- Every quad's `chartFaces` is all 28,800 faces, one distinct key.
- For each of the 3,600 samples, `SourceProjectionCache::allowed_faces(const std::vector<int>&)` copies, sorts, de-duplicates and map-compares those 28,800 ints.
- A scratch prototype keyed by chart component instead removed 28% (0.68 → 0.49 s), bit-identically.

**Remaining per-quad O(F) work**, after both prototypes (profile at 1,600 quads):

| Site | Share |
|---|---|
| `OutputProjectionCache` constructor (scans every chart face into a scope set, per quad) | 32% |
| `validate_source_authoritative_surface_mesh` | 28% |
| `consistent_source_scope` | 16% |
| `resolve_compatible_chart` (copies the chart face list) | 7% |
| `quad_reference_surface_point` | 7% |

The slope is still 0.56 ms per quad at F = 28,800 (0.16 ms at 7,200).

#### RA-206.3 CB91 — exact patch (`M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE`, ID kept)

- **Precheck:** `git diff --quiet e00ef91a8a5dff8b125c9abfe388952cec20cbe1 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Once.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Once.diff").
  - SHA-256 `c323ae01e44a96998c07c2e0e0fd30b70d3d867201e49d97480003198d1c4a43`.
  - 177 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SourceTopologyRegions.h` | `10 0` | `fe154e30cda51b11530caee121a3e45602d8e99489f08d769d56f768c08027e5` |
  | `src/validation/SourceAuthoritativeMeshValidator.cpp` | `8 9` | `3ea9ff27940d6bfb7c8914066a4905c0a4dbaae9cbd1002019070fa15024e766` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `55 31` | `ec5c94e6adff1253bdb806c85de20a32f3b5011b2444978a28256b037eb121b8` |

- **Content:**
  1. **`source_binding_check_count()`,** a thread-local diagnostic counter incremented by `SourceTopologyRegions::matches_source_faces`. It is diagnostic only, like `SourceProjectionCache::queryCount`, and has no semantic effect.
  2. **The validator checks the loop-invariant binding once,** before the provenance loop, instead of once per output vertex. The local-sheet check reuses that result. Semantics are identical: `matches_source_faces` is `const noexcept` on unchanged inputs.
  3. **Row 899 (test name unchanged, so the selector bytes are unchanged)** validates a 100-quad and a 400-quad grid on the same 28,800-face source. It asserts:
     - source-authoritative validation was used in both runs;
     - binding checks are in (0, 16] (measured: 9);
     - the two counts are equal;
     - a coarse `< 5.0 s` backstop. The comment records the 3.5× Linux ratio.
- **Verified in scratch:**

  | Check | Result |
  |---|---|
  | Local gate, 899 rows | **898/899** (only row 283, O16) |
  | Census digests (Plane, MultiFaceSeam, CloseSheets, Cylinder, BunnyRandom, Vase) | **129/129 items byte-identical** to the [post-CB90 reference](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv"), including every `validation` hash |
  | Row 899 | PASS in 3/3 runs |
  | M1 (per-vertex check restored) | **FAILS**: 450 > 16, 130 ≠ 450 |
  | M4 (RA-202's CB88 revert) | **FAILS**: 30,409 > 16 |
  | Equality alone | **does not** kill M4, because its checks scale with source faces; hence the absolute bound |
  | GCC 16 `-Wall -Wextra -fsyntax-only`, CI defines | clean on the changed lines |

- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.
- **Routes:**
  - mismatch → `M6-CP3-PLAN-P13-FINAL-VALIDATION-BINDING-STOP`;
  - infrastructure → `M6-CP3-CB91A-P13-FINAL-VALIDATION-BINDING-ORCH`.
- **Not in CB91:** the chart-keyed projection mask. It is a correct 28% cut, but one of five per-quad chart-face sites, and those belong in one design (O33, RA-206.5).

#### RA-206.4 TB81 — `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC`

- **Package:** the immutable CB91 package, artifact-only.
- **Gate:**
  - the TB78 manifest, 899 rows (`9d2c1ec5…`), reused unchanged, with ledger v5;
  - **899/899**, membership 980;
  - row 899 PASS.
- **Census:** manifest `3af1dc0d…`.
  - Cylinder PASS.
  - BunnyRandom P13-e at vertex 49.
  - Vase RED `SelfIntersectingFace` within 600 s, with 192,482 / 26,817.
  - Record `completedQuads` without pinning it (RA-205).
- **Pinned behaviour-neutrality falsifier.** All seven `platform-digest` lines must be **byte-identical to TB80's** (the TB80 report's verbatim block). They are Linux-observed values, so pinning them is allowed (RA-203.2). CB91 changes no validation outcome.
- **Routes:**
  - match → the Review track (RA-206.7);
  - mismatch → `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-REV` (Review, Claude, scratch build). A mismatch is any RED, any digest-line difference, or a missing or duplicate line;
  - infrastructure → `M6-CP3-TB81A-P13-FINAL-VALIDATION-BINDING-ORCH`.

#### RA-206.5 New obligation O33: per-quad O(F) chart-face work

Final validation and the optimizer still materialize or scan a whole chart's face list for every quad or sample, at five sites (RA-206.2).

- **Today's cost:** about 0.56 ms per quad at F = 28,800.
- **Projected for Vase:** about 2,400 faces and about 68,000 quads once it reaches validation, which is several seconds on macOS and about 3× that on Linux.
- **Not blocking yet:** Vase stops at completion.
- **Owner:** `M6-CP3-DEFN-P13-CHART-FACE-PER-QUAD-COST` (Review, Claude, scratch build). It designs one chart-level cache:
  - chart handles instead of copies;
  - per-chart projection masks (the RA-206.2 prototype);
  - per-chart scope sets.

  Its deterministic witness is a count of chart-face-list materializations, constant in quad count. It runs before Vase reaches optimization.

#### RA-206.6 Wall-clock guards

A wall-clock bound in a gated test is a cross-platform measurement. Two rules follow:
- set it from the Linux runner's ratio for that code (memory-bound sections reach 3.5×), not from a macOS run;
- prefer a deterministic counter that kills the regression's mutant, with a coarse time bound only as a backstop.

The other six gated wall-clock rows have at least 4× Linux margin (RA-206.2) and stay. Convert each to a counter when its code is next touched.

#### RA-206.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 42F — COMPLETE | `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK` | Implementation agent |
| 42G — COMPLETE (MISMATCH) | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC` | 898/899; row 899 only; census MATCH |
| 42I — Review COMPLETE | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` | ChatGPT, reviewed by RA-206 |
| 42J — NEXT (already opened) | `M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE` | Implementation agent; **apply RA-206.3 exactly** |
| 42K | `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC` | Implementation agent; RA-206.4 |
| 43 (Review) | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a) | Claude, scratch build |
| 43B (Review) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, after O32a |
| 44 / 44A / 44B (Review) | P13-e; O31; O32b–e | Claude, scratch build |
| 44C (Review) | `M6-CP3-DEFN-P13-CHART-FACE-PER-QUAD-COST` (O33) | Claude, scratch build; before Vase reaches optimization |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB78 manifest `9d2c1ec5…` re-hashed. CB91 keeps every test name, so TB81 reuses it unchanged |
| Decisive claims independently re-derived | CB90 diff scope. TB80 raw log and resources downloaded and read. Stopwatches measured. F×Q scaling measured. Binding checks counted. Profile taken. Every CB91 claim verified on a byte-identical scratch tree |
| Non-vacuity checked | M1 and M4 both fail the new assertions. The digest check is a 129-item equality |
| Prior obligations discharged/carried | Row 899 candidate → owned by CB91 → TB81. O30b, O31, O32a–e, P13-l, P13-e, O27–O29, DR1/DR3 carried. New O33 |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O33; the wall-clock rule |
| ORIENTATION currency line | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` reviewed by RA-206 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 and §8 updated; §3 and §4 unchanged |
| CHANGELOG | RA-206 entry |
| ROADMAP | n/a |
| Selector manifest | n/a: unchanged |
| LESSONS | Wall-clock guards and counting the claimed invariant |
| Consolidation under CLEAN_UP_POLICY | The TB80 Review is retained with a review line |
| Successor frozen | CB91 exact (RA-206.3), TB81 (RA-206.4) |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; the patch is a committed `.diff`. Scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Not written: `M6-CP3-CB91-…` is IN_PROGRESS (`c714b4f8c`), and overwriting its beacon would break the implementation agent's lifecycle. Its content is replaced by this record |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md`; moved verbatim.

### TB81 — Final-validation binding-once immutable full gate and production census (2026-11-05)

**Canonical turn:** `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC` (artifact-only Test + Benchmark, RA-206 §4). **COMPLETE / MATCH**: the registered gate, production census, and seven fixed-Linux platform digests all matched. This is not CP3 or selector497 promotion. Next *separate* turn: `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (Review, RA-206.7 / RA-205.4); no successor work was performed here.

#### Exact immutable authority and checks

- CB91 semantic source `96ee281a40920f21eb911880a3b2c458ef4f0563`, existing Linux GMP/GMPXX package artifact `13394321724` from [compile 41980448558](https://github.com/akashskypatel/Directional/actions/runs/41980448558); immutable package outer SHA-256 `777935dccac64fefaf80a0e78f387e0ee9a0c9caf94ae0b66aff099271a4cfd2`, packaged root `SHA256SUMS` SHA-256 `ebfe3e173d47b7e4f283bbba120767d74d1b6cb71df01fd55fe683fcaa8ffa1c`, source tar SHA-256 `df295cbef3c15bbdeca9ef2b52fbcf65db377c2fe2c9abe53edc93c607ec622d`; CB91 compile/package previously verified 28/28 hashes and `runtimeExecution=false`.
- Verified executor/source snapshot SHA `4bb2496cc26965702d9e8dbbd1c01fa24c1264d6`, [snapshot 41985261931](https://github.com/akashskypatel/Directional/actions/runs/41985261931), artifact `13396100353`, ZIP SHA-256 `fbc47b5ccad5d2ed69cb7b102f8b7394f7778ffaf68e7062adbfe4d94d1df854`; 6,183/6,183 source-file hashes and source tar digest verified.
- Frozen 899-row gate manifest `.agents/Directional/Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv` SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`; deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; three-case census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Existing harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Neither test, benchmark, source, manifest, fixture, nor selector was changed; each identity ran in its own fresh process. Both result `execution-boundary.json` records identify the immutable CB91 package, with `configure=false`, `compile=false`, `relink=false`, `benchmark=false` and `postflight=true`.

#### Full gate

- [Dispatcher run 41985957797](https://github.com/akashskypatel/Directional/actions/runs/41985957797), request event `eb5f32b6f6619262a3b05996b5a09e4357d24fb1`, result artifact **13397015651**, outer ZIP SHA-256 `b682e2005569ed7f6f8c740865d9a9cafaef2fe398a42bbe0b92e7d6f3b3dba1`; **1,806/1,806 internal SHA256SUMS verified**.
- **899/899 PASS**, 0 RED, 0 abnormal, 0 skipped, 0 missing, 0 duplicate, 0 control-bad, 0 unexpected-pass, exit 0; membership **980**, deferred 81. All ledger identities have exactly one run, one passed, and zero skipped.
- **Row 899** `SurfaceMeshOptimizerPhase22.FinalValidationReadsSourceRowLabelsAfterOneBindingCheck` PASS. Source assertion checks both 100-quad and 400-quad source-authoritative validations; the full binding-check counter is positive, ≤16, and equal at both output sizes, with internal timed-section backstop `<5.0s`. GTest's **8,744 ms whole-test duration is not the timed-section bound**; it includes setup and both validations. No counter number was emitted; the asserted bounds are evidenced by test PASS, not a measured count claim. The prior TB80 row-899 failure is not reproduced on CB91.

#### Production census

- [Dispatcher run 41985991943](https://github.com/akashskypatel/Directional/actions/runs/41985991943), request event `3a47c9cad722c91d553024080c6f5d666bc0caaf`, result artifact **13397310703**, outer ZIP SHA-256 `ff4a82c31abe97c8ab214182b847652c3c663ee77f9a708ae0c2e63fe2b412c6`; **9/9 internal SHA256SUMS verified**.
- Exact three identities: 1 expected PASS / 2 expected RED, 0 abnormal, 0 skipped, 0 missing, 0 duplicate, 0 control-bad; exit 0, postflight true.

| Fixture | Raw evidence | Registered disposition |
|---|---|---|
| Cylinder | PASS, exit 0; 11.96 s wall, 48,480 KiB peak RSS | MATCH |
| BunnyRandom | RED, exit 1; 0.96 s wall, 24,300 KiB peak RSS; `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` | Existing P13-e — MATCH |
| Vase | RED, exit 1; 257.08 s wall, 2,080,412 KiB peak RSS; `NotProductionReady:completion detail=SelfIntersectingFace`; 192,482 trace segments / 26,817 arrangement cells / **67,746 completedQuads** | Existing P13-l/P13 completion issue, under 600 s — MATCH. Quads informational, not pinned |

#### Seven pinned Linux platform-digest lines (TB80 → TB81)

All seven lines were independently extracted from gate rows 795, 796, 797, 864 and census rows 1, 2, 3, in that order. Exactly one digest line was present in each raw process log. The following is byte-identical to the seven lines recorded in [TB80](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB80_P13_Arrangement_Cell_Order_Full_Gate_Execution_Report_20261105.md"), including the two intentionally identical Cylinder lines:

```text
platform-digest case=CloseSheets vertexBits=610a515ac548d9e5 faceBits=2aac7a4034a53084 fieldBits=67f14e9a0da8cc25 source=5e6048ce544f359c/36 cross-field=2b0d354a26601973/36 feature=ec6eee995a69d42d/66 rails=71402b8cd6b33439/2 metric=fab649a3b38bf0fb/32 relief=14e153b4b075e5d5/40 relief-consumption=b65993849fc47e82/78 source-labels=b526355d3dfb71ca/36 field-transport-atlas=cab4682b73f5bce1/52 field-aligned-network=d723620693f6f1c5/48 surface-cut-graph=d35fc38600a73aa2/2 global-topology-plan=e896b18cb73c56e2/50 global-conformity-baseline=d96525d83266060b/48 tracing=589edaf2eb87bbb5/1104 strands=d68abf6c7e47a0a3/1128 embedding=67442dd8c6025d7f/1128 arrangement=5612032bbe02f5df/202 simplification=5612032bbe02f5df/202 completion=89ced6d01559f38f/200 optimization=42308fa2adadb7fb/200 validation=aefefcede85f098a/200
platform-digest case=MultiFaceSeam vertexBits=d9bdfcc0a3925655 faceBits=41696de4685917ab fieldBits=05bfd9b9dd3ecb25 source=7a8c005d839eace8/32 cross-field=871c9a976d8cbb50/32 feature=8b611bf652405bf2/56 rails=3786416b45502da0/1 metric=da3ce1897060b72f/25 relief=1908fbf2bf880d8e/19 relief-consumption=14625a19e9ce7588/57 source-labels=8a6a6560dcb5c8d3/32 field-transport-atlas=e2c732ede2f158c4/50 field-aligned-network=fc93e24d9a4d1dd0/32 surface-cut-graph=b998dd302510bbf6/1 global-topology-plan=160571701e6dd0a9/33 global-conformity-baseline=c9809142d83085e0/32 tracing=c3996b86d41d70fd/256 strands=4fd4b6f6b9f72e34/272 embedding=040136465efa8eab/272 arrangement=cb3826c8d7773023/65 simplification=cb3826c8d7773023/65 completion=c399607d09eb2683/64 optimization=a64dac0edaddbdf8/64 validation=12db7cff9b1d0517/64
platform-digest case=Plane vertexBits=a6dd696d19d50a18 faceBits=8363b4abcc93efd5 fieldBits=5f4eba6ca6046f25 source=710e15a4220d8ee6/24 cross-field=ae54f37ee5d26302/24 feature=dbcb95cbdb24d00d/43 rails=f1b1bb761198fcc6/1 metric=aad884a80b65bf5d/20 relief=b41394be2321cadb/24 relief-consumption=03c611f59a22c352/49 source-labels=3990f1f0538c4e1c/24 field-transport-atlas=65bec7a9ba3d4eb3/36 field-aligned-network=882f8b00cc981707/28 surface-cut-graph=6d79d3c14247d71d/1 global-topology-plan=1b47db4c3e092091/29 global-conformity-baseline=f5c3f877fce4e8ef/28 tracing=77deb7d5c253f883/352 strands=a4fe21aeb7a7dd73/366 embedding=4f4c21f3dda4a166/366 arrangement=bf49c52b429b8a6d/65 simplification=bf49c52b429b8a6d/65 completion=17e781c735a1b531/64 optimization=f94b7d773cc7c9f1/64 validation=e7e5ad577e046893/64
platform-digest case=Cylinder vertexBits=275ec93baa764a47 faceBits=5cbe02acf3a8b550 fieldBits=9cf2ceb792da2ec5 source=72815904cc9359c2/128 cross-field=048282ce2f33efc7/128 feature=4720dae9adc48841/208 rails=e13580329f22ee39/28 metric=8b544a23d1cff9e3/80 relief=c66182ca3b9667b4/44 relief-consumption=1a618682fbfff038/180 source-labels=a00ad649e820c7fd/128 field-transport-atlas=e12d7d76e66148f6/226 field-aligned-network=4ab72b48e4600ee3/64 surface-cut-graph=ef9a4e56f7901be5/50 global-topology-plan=5e1ff8c1a605f265/162 global-conformity-baseline=12db9fbca63979ca/211 tracing=e0a85269f80c1190/1728 strands=70f1c35bb0c5f759/1760 embedding=b3fb03c2631853a6/1760 arrangement=663e2b4524a30d5b/290 simplification=663e2b4524a30d5b/290 completion=ad7b4ed251f77e3e/288 optimization=6f09047d714f4a98/288 validation=5d261446433662f0/288
platform-digest case=Cylinder vertexBits=275ec93baa764a47 faceBits=5cbe02acf3a8b550 fieldBits=9cf2ceb792da2ec5 source=72815904cc9359c2/128 cross-field=048282ce2f33efc7/128 feature=4720dae9adc48841/208 rails=e13580329f22ee39/28 metric=8b544a23d1cff9e3/80 relief=c66182ca3b9667b4/44 relief-consumption=1a618682fbfff038/180 source-labels=a00ad649e820c7fd/128 field-transport-atlas=e12d7d76e66148f6/226 field-aligned-network=4ab72b48e4600ee3/64 surface-cut-graph=ef9a4e56f7901be5/50 global-topology-plan=5e1ff8c1a605f265/162 global-conformity-baseline=12db9fbca63979ca/211 tracing=e0a85269f80c1190/1728 strands=70f1c35bb0c5f759/1760 embedding=b3fb03c2631853a6/1760 arrangement=663e2b4524a30d5b/290 simplification=663e2b4524a30d5b/290 completion=ad7b4ed251f77e3e/288 optimization=6f09047d714f4a98/288 validation=5d261446433662f0/288
platform-digest case=BunnyRandom vertexBits=afeef971d97f3e77 faceBits=a493d538d4f12dff fieldBits=03ee413ed128cbdd source=f1def128f3fd2d31/1000 cross-field=32eb9c1b3674ab2e/1000 feature=b91068287ee13189/1500 rails=dc5225500a257ab7/7 metric=e993a5a41ddc17d4/502 relief=d483e8239dd4d9af/493 relief-consumption=9b6e882062ada641/1142 source-labels=5076a6e22fae513a/1000
platform-digest case=Vase vertexBits=eef00a8706c009f5 faceBits=e43da6cccb821779 fieldBits=5c9a34a47d717fdc source=bda54d4fd948e6c0/2404 cross-field=8e16b454468fe056/2404 feature=116dae2abefd55cb/3677 rails=0e65f0d581f8c717/1 metric=46e5eb6de00adb8b/1274 relief=88c04e58d9413be9/453 relief-consumption=1a74a99cdb61ff3e/1569 source-labels=2f58b6b0a0d9c652/2404 field-transport-atlas=9634dbd00b8015b2/4668 field-aligned-network=e4787cde9c9c8c8e/291 surface-cut-graph=c8cf0e9fdad8b6df/3 global-topology-plan=817296327ba75c64/297 global-conformity-baseline=018723ddd3522976/299 tracing=d35129b974e6df7d/192482 strands=66c38d23d7421c2d/30989 embedding=f2fc0cca0e258de4/30989 arrangement=26e811501b72fd6b/26817 simplification=26e811501b72fd6b/26817 completion=1925fdbe6354006d/67746
```

#### Classification and next turn

**MATCH** under RA-206.4, no infrastructure issue and no new candidate/stable regression. Gate restored after CB91; no successful full production matrix or CP3 acceptance is implied. The existing BunnyRandom transport-port defect, Vase completion failure, O30b, O31, O32a–e, O33, P13-e, P13-l and O27–O29 remain owned. Accepted **CP2 491/491**, stable **66 events / 17 categories / 49 recurrences**, witness debt **1**, selector497/CP3 **unpromoted**. Frozen gate membership 980 and deferred ledger v5 81 unchanged.

The approved next separate Review is **`M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS`** (RA-206.7 / RA-205.4); inspect seed-generation source-row permutation sensitivity in scratch, not in this TB. The immutable output and test contracts are unchanged. Existing source-snapshot and turn-cleanup markers were removed by [cleanup 41986198930](https://github.com/akashskypatel/Directional/actions/runs/41986198930); durable dispatcher/request and mailbox branch retained.

## `Architecture_M6_CP3_DEFN_P13_Source_Microedge_Provenance_Review_WIP_20261106.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Source_Microedge_Provenance_Review_WIP_20261106.md`; moved verbatim.

### P13-l2 source microedge classification — supplemental WIP Review

**Owning turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP`, currently BLOCKED on the run-specific provenance observation gate. This file is supplemental evidence, **not** a second Review authority or a Code + Build authorization. Consolidate it into the owning completed-mesh-stitch Review before formal closure.

#### Frozen evidence / runtime boundary

- CB96 semantic product `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, immutable package `13460725846`; source snapshot `a1e3d84821a03f33ee9a870d101d802b38337573` (run `42164386607`, artifact `13478417321`, archived source SHA-256 `3c51942ee03535a5b669f6d5057fe711535de1ca1e67306b468bc7a7fb5b305e`, 6212/6212 file hashes previously verified).
- Rejected diagnostic CB96 mesh from earlier artifact `13469796788`, with 67,961 vertices and 67,750 quads; no success or new TB evidence.
- Resumed branch comparison from snapshot to `129c5431bf881f60cfdcaefa18e5b6c2f8cb408d`: review documentation, handoff, cleanup marker and STATUS changed; no semantic implementation source changed.
- This attempt did **static analysis only** on frozen input and output bytes. No generated Directional executable, compile, test or benchmark was run.

#### Independent source-edge finding

Vase input `benchmarks/fixtures/milestone-g/vase.off`: 1274 vertices, 2404 source triangles. Source edge `(773,775)` belongs to precisely two triangles: source rows `285=(773,519,775)`, `1199=(773,775,1169)`. Its length is `0.03007428152092757`, with unsigned oriented-face normal deviation `3.2898067185157487°`.

The benchmark `make_remesh_options` supplies the default `AdaptiveFeatureMapOptions` (no user hard tags). The classifier computes strength `sqrt(relativeScore * smoothstep(dihedral, absoluteLow, absoluteHigh))`; its default absolute low is 8° on organic and 15° on CAD-like regions. Because 3.2898° lies below **both** thresholds, the feature strength for this edge is zero independently of the adaptive percentile score. It is neither boundary nor nonmanifold; under those configured defaults its input classification is **Smooth**, not HardFeature. The source edge is **not itself an authoritative hard-feature rail**.

That does **not** authorize deleting any traced curve, network edge, periodic/cut relation, or arrangement node. The exact `SurfaceArrangementNodeOccurrence.sourceArc` and adjacent `SurfaceArrangementHalfedge.{curveId,railId,hardFeature}` were not retained in the available diagnostic artifacts. Their upstream ownership remains unresolved.

#### Source-local geometry of the three-vertex cluster

Frozen output position projected onto source edge `773→775`:

| Global output vertex | Previously retained typed source support | Edge parameter | Distance to infinite source edge |
|---|---|---:|---:|
| 53049 | source edge (773,775) | 0.3736864579042779 | ~1.7e-18 |
| 28576 | face interior (773,775,1169) | 0.3736857521583742 | 8.703525872478638e-08 |
| 53052 | typed support not independently decoded; geometry only | 0.3736738848683131 | ~4.2e-17 |

Measured distances: `|53049−28576|=8.958587186761864e-08`, only `2.978820019533274e-06` of the source edge length; `|53049−53052|=3.7812502317558406e-07`; `|28576−53052|=3.6735936745952676e-07`. **Previously verified authoritative arrangement-node IDs differ**: do not infer a weld from proximity.

The original patch 23301 six-vertex boundary is simple in its Newell plane, polygon area `3.076601640467252e-05`, minimum projected clearance `8.944653152366212e-08`. Its three boundary-only two-quad decompositions all retain the inherited microedge; the alternative diagonals trade the current near-corner issue for severely thin quads (minimum areas ~1.4e-10 or ~1.85e-09). All alternative quad normals remain within ~3.3° of the two local source face normals, so the existing 60° source-orientation predicate alone does not reject them. **No alternative is yet certified as valid**; a calibrated quality/clearance criterion is still absent. `DESIGN.md` §2.1 item 10 and §2.2 separate structural validity from quality disposition; D1 is not current CP3 acceptance.

Distinct from this cluster, completed quad `21286` on patches 4955/4957 consumes all four consecutive nodes of a *single three-edge logical side* as one face. That is a **completion topology** defect, independent of numerical quality thresholds.

#### Remaining Review requirements

1. Recover the actual source-arc, rail, junction/cut, and incident-halfedge ownership of the 23301/23302 microcluster from already-authoritative evidence or through a separately authorized diagnostic boundary. Prove whether each node is an indispensable route or a redundant optional support trace; no position weld or narrowed identity classes.
2. If a redundant trace is proven, correction belongs to its **earliest producer**, with transactional, globally conforming side updates across all incident patches. Otherwise preserve exact nodes and report any impossibility/quality failure by its truthful typed cause.
3. The eventual bounded Code+Build plan must give a negative-on-legacy *one-logical-side-as-quad* witness (4955/4957) and valid thin-feature positive controls; geometry validator must also distinguish 55/15372 disjoint, 4304/4308 concave-fan false hit, true distinct-face convex overlap and noncoplanar contacts without dropping real positives.
4. Continue this **same Review** until source-route authority and one owner-specific successor's falsifiers are frozen; do **not** start that successor here or promote CP3.

Unchanged: accepted CP2 `491/491`, TB83 candidate `903/903` (membership 984), stable `66/17/49`, debt `1`, selector497 and CP3 unpromoted.


#### Independent source-classification and trace-authority audit (2026-11-06, same Review)

**Re-verification:** The prior frozen exact source snapshot `a1e3d84821a03f33ee9a870d101d802b38337573` was re-extracted from `13478417321`; outer ZIP SHA-256 `c23d9ceb2bdca545b3bb95fbd98a3fa362cd62c7aa767ae456994e5ecc22ae17`, inner source archive SHA-256 `3c51942ee03535a5b669f6d5057fe711535de1ca1e67306b468bc7a7fb5b305e`, and all **6,212/6,212** source-file SHA256SUMS matched. `compare_commits` from that source commit to attempt-entry head `a3dd9cf6b071fdf6a818addbfdbadd9a13585587` found no product/fixture/test/selector/build-source changes: only review notes, handoff, cleanup marker, STATUS. The prior frozen mesh evidence artifact `13469796788` was independently rehashed, **5/5** nested files PASS; output-vertex matrix SHA-256 `b4e16e1f68c33e023d274cf1c086179f0654c962040d1ff0b74723a6c28cfb45`; Vase source input file SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`. The offline audit script and JSON are backed up in `Directional_P13L2_Microcluster_Identity_Review_20261106.zip`. No binary execution.

**Classification is robust, not float-key aliasing.** Independently solve the 3×3 affine barycentric system on source face 1199 `(773,775,1169)` against retained CB96 output positions. Vertex `53049`: barycentric `[0.6263135420957225,0.3736864579042807,-2.92127e-15]` (edge point). Vertex `28576`: `[0.6263133716968747,0.3736841090829517,2.51922017383476e-06]` (strict face interior). Vertex `53052`: third component `-4.87506e-16` (edge point; *its typed identity has not been decoded*). All three affine-reconstruction residuals are below `5e-16`. `SurfaceArrangement.cpp::make_node_key` and `canonicalize_barycentric` use `1e-10` source-edge classification tolerance: the interior point is **25,192 quantization units** away from the edge classification, not a borderline snap. Raw Vase bounding-box diagonal is `2.0119413889380575`; if passed as validator source scale, the `32*1e-9*sourceScale` position tolerance is `6.438212444601785e-08`, versus the inherited microedge `8.958587186761864e-08`. Treat this tolerance as a *raw-input reference*, not a separately observed runtime option; the terminal vertex-on-other-edge distance was previously `2.61e-08` and therefore is a distinct check.

**Exact static provenance producer chain (newly localized, still not the actual run-specific arc IDs):** `src/pipeline/RemeshPipeline.cpp::surface_arrangement_arcs_from_flow_rep` constructs arrangement input arcs only from retained `FlowRepArc` IDs; it transfers `mandatoryRail`, `hardFeatureRail`, `railId`, `curveId`, proposal identifiers, and original `arc.id` into `SurfaceArrangementArc.provenance`. `src/geometry/SurfaceArrangement.cpp::build_surface_cell_complex` constructs 2D segments only from (i) source **boundary or hard-feature** edges and (ii) those retained arrangement input arcs. Source edge `(773,775)` is interior manifold and below the hard-feature angle gate, hence **no direct synthetic boundary/feature segment on that edge is inserted** for the current source/options. Its two close original arrangement nodes must therefore be reached through retained FlowRep segments (including their intersections/splits), not directly from an authoritative hard-source-edge segment. `SurfaceArrangementNodeOccurrence` retains `sourceArc,provenance,railId,curveId`; `SurfaceArrangementHalfedge` retains `sourceArc,railId,curveId,hardFeature,layoutSupport,singularitySupport,proposal*` plus all full provenance records.

**Critical qualification:** `FlowRepStrands.cpp::build_flow_rep_arcs_from_network` can set `mandatoryRail=true` on network authoritative rail segments or segments with `railId`; `RemeshPipeline.cpp` sets `SurfaceArrangementArc.hardFeature = arc.hardFeatureRail || arc.mandatoryRail` and `layoutSupport = !arc.mandatoryRail`. Consequently, a *smooth source edge does not prove that a trace crossing it is optional*. Do not replace arc provenance with proximity or infer optionality from input dihedral. In the default low-memory path, `RemeshPipeline.cpp` releases the FlowRep arcs and arrangement complex prior to completion/terminal validation. The existing frozen output V/Q data and retained quad-lineage diagnostics cannot reconstruct those missing typed arc identifiers. `retainIntermediateGeometry` enables diagnostic-only product snapshots of FlowRep arcs, embedded arrangement arcs and the arrangement complex, but replaying with altered options is runtime work, **not done or authorized by this Review**.

**Next non-vacuous ownership decision (still required):** map original arrangement nodes `9679` (output 53049) and `36055` (output 28576), and all incident boundary halfedges, to actual `SurfaceArrangementNodeOccurrence` and full `SurfaceArrangementHalfedge.provenance`; join the recorded `SurfaceArrangementArc.provenance` back to the exact retained `FlowRepArc.id`. Record *all* distinct sourceArc/curve/rail/proposal/support/mandatory/singularity tags, twin and patch memberships, not only a representative. Prove each candidate event dispensable **or** required under topology, coverage, cycle and rail gates. A mere near-coincidence, source smoothness or one output key match cannot discharge this decision. Any need to run a diagnostic under the Review's runtime-free policy must first be resolved at the owning boundary; no Code + Build successor has been authorized by this incomplete evidence.

#### Exact runtime-observation prerequisite and bounded diagnostic contract (2026-11-06)

**Authority conflict, not a connector outage:** `REVIEW_TURN_POLICY.md §4.3` defines a Review as runtime-free. RA-209.5's Review-track description mentions a scratch build and prior P13 Review attempts executed immutable Vase in scratch GitHub Actions. That history does **not**, by itself, repeal the explicit runtime-free Review boundary for this attempt. A run-specific FlowRep/arrangement provenance witness is absent from the already verified CB96 outputs. **Before a new replay is commissioned**, an authorized independent design/review decision must clarify the permissible diagnostic boundary, or supply a previously produced immutable typed provenance artifact. General GitHub and Google Drive mutation authorization is not equivalent to permission to cross the repository's Review runtime boundary. No new run was started in this attempt.

**Lowest-change candidate after the boundary is resolved:** Frozen CB96 already defines `SurfaceCellOptions.retainIntermediateGeometry=false` by default in `include/directional/pipeline/RemeshPipeline.h`; `RemeshPipeline.cpp` snapshots complete `productSnapshots.flowRepArcs` and `flowRepNetwork` (~13547), `embeddedArrangementArcs` (~13601), and `arrangement` (~13675) when `retainForExecution` is set. The full authority types already exist in `FlowRepStrands.h::FlowRepArc` and `SurfaceArrangement.h::{SurfaceArrangementArc,SurfaceArrangementNodeOccurrence,SurfaceArrangementProvenance,SurfaceArrangementHalfedge}`. Reuse these existing diagnostic snapshots rather than modifying production structs, adding an independent copy of lineage, or enabling a global epsilon merge. An offline witness extractor is a possible **future** observation-only consumer, not work authorized here.

**Snapshot linkage must respect simplification:** The original pre-stitch node ids `9679`/`36055` and cell/patch associations are for the **complex consumed by completion**. `src/geometry/SurfaceComplexSimplification.cpp` can compact nodes and reassign `node.id` in `compactNodes` (around line 1210); a direct array lookup into the *pre-simplification* arrangement with those IDs is **not justified** without an explicit unchanged-ID witness. The frozen Vase stage digests happen to match (`arrangement=9f942f594f94445c/26817`, `simplification=9f942f594f94445c/26817`), but two equal digests do not establish a node-identity bijection. Capture the actual post-simplification completion input or a proved stable mapping to pre-simplification nodes before joining `NodeOccurrence`/halfedges.

**Exact join, if authorized:** Match the two problem nodes and **all** incident halfedges via their typed canonical source support and patch-boundary side identities. For each occurrence and each full halfedge provenance entry, join `SurfaceArrangementProvenance.sourceArc` → `SurfaceArrangementArc.id` → `SurfaceArrangementArc.provenance` → `FlowRepArc.id` (do **not** confuse arrangementArc.id with FlowRepArc.id). Record `sourceFace`, exact barycentrics, `family`, `strand`, `curveId`, `railId`, proposal identifiers and segment, `hardFeature`, `layoutSupport`, `singularitySupport`, `mandatoryRail`, `boundaryRail`, `sourceTopologyRegion`, `sourceIsolationSheet`, endpoint anchor identities, and all incident cell/halfedge owners. `sourceArc=-1` is legitimate for synthetic boundary/feature segments: distinguish it rather than fabricating an arc. Review **all** provenance entries, not only the primary halfedge.

**Non-vacuity / observational parity:** If enabled, the existing `retainIntermediateGeometry` option changes storage lifetime and copy/move paths and is **not presumed to be semantics-neutral without comparison**. Pin frozen package source, exact Vase bytes/options, stage digests and case identity; independently compare retained diagnostic run to the registered CB96 baseline through tracing/strands/embedding/arrangement/simplification/completion and four typed issue rows. If a stage digest, relevant canonical node/patch mapping, or terminal witness diverges, STOP attribution; do not transfer alternative-run node IDs to the baseline by proximity. Budget memory/time and record scratch result and failure even if it cannot provide the proof. The evidence must distinguish required rail/cycle/coverage support from optional layout bridges, including positive retained-feature and negative redundant-support controls, before any proposed upstream deletion.

#### Supplemental static test-coverage and snapshot-boundary audit (2026-11-06)

**Independently rechecked against verified source snapshot** `d3d632afb4b97574f52569d289ff781584271dbc` (6,213/6,213 source file hashes verified locally; compare to current resume head `c41eb3ffc3394c0e700ebc2b7e45d8b4160026dc` changes only `STATUS` and removal of a temporary snapshot trigger). The immutable semantic CB96 source remains unchanged. This is static inspection, not a new runtime witness or authorization.

- **The retained arrangement is not necessarily the completion input.** `RemeshPipeline.cpp:13675-13679` places a copy of **pre-simplification** `arrangementComplex` in `productSnapshots.arrangement`. At lines `13861-13866`, completion consumes `simplifiedComplexForHash`, which may be `simplified.complex`; `SurfaceComplexSimplification.cpp:1204-1218` can compact and reassign node IDs. Therefore `retainIntermediateGeometry=true` cannot, by itself, justify joining the completion-side node IDs 9679/36055 to array indices of the retained arrangement snapshot. Any authorized diagnostic must either capture the **actual post-simplification completion input** (with its complete occurrences/halfedges) or independently prove an exact bijection to the retained pre-simplification arrangement. Identical stage digests are not an ID-bijection proof.
- **Existing intersection test is not the needed non-vacuity matrix.** `SourceAuthoritativeMeshValidatorPhase22Tests.cpp:78-99` exercises triangle shared-edge legal adjacency versus a coplanar foldover. That valuable test does **not** distinguish a disjoint pair of separately owned concave quads from a false intersection introduced by a first-corner fan; neither does it exercise two distinct convex overlapping faces with no shared vertex. `SourceAuthoritativeMeshValidator.cpp:410-420` still triangulates every polygon from its first corner. The eventual correction must independently test true intersecting **distinct** faces, near-separated disjoint faces, the concave-fan negative, and noncoplanar contact, preserving existing shared-edge behavior.
- **Predicate units remain a directly verified source defect.** `SourceAuthoritativeMeshValidator.cpp:162-171,179-191,198-214` compares signed 2D orientation determinants (length squared) against a positional `tolerance` (length). A correction must use dimensionally consistent filtered/orientation predicates and independent positive/negative controls, not a larger catch-all tolerance.
- **An existing concave completion positive is not a thin-feature calibration.** `PureQuadCompletionPhase18Tests.cpp:2719-2729` has a bounded embedded quadrangulation of a concave boundary; it is valuable to retain. However its success alone does not establish admissible source-aware minimum clearance or size-normalized quality for the 23301 microedge. The eventual owner-targeted test set still needs an independently sourced valid thin-feature control and a failing legacy degenerate case.

**Disposition:** This confirms what a **future separately authorized observation** would need to preserve. It does not recover run-specific FlowRep arc/halfedge lineage and does not discharge the Review authorization prerequisite. No executable, build, test, benchmark, fixture, selector or product source was changed.

**Current disposition:** This is an **unresolved independent Review authorization/diagnostic gate**, not merely delayed work or an Action safety-check failure. No owner-specific Code + Build change can be frozen for the 23301 microedge without this evidence. The already proven completion-one-logical-side defect and dimensionally invalid validator contact predicates remain separate, recorded defects. Accepted CP2 491/491, TB83 903/903 candidate, stable 66/17/49 debt 1, selector497/CP3 unpromoted.

## `Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Provenance_Probe_Adjudication_20261106.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Provenance_Probe_Adjudication_20261106.md`; moved verbatim.

### RA-210 — P13-l2 block resolved: the Vase residue is three contact predicates; exact CB97 → CB98 → CB99 → TB84 (2026-11-06)

**Turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP` (P13-l2). This resolves the ChatGPT Review's REVIEW_BLOCKER on the Claude scratch track.

**Source:**
- semantic CB96 `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, unchanged through `89cc1d18e`;
- scratch build `bld55n` (macOS, FMA-off, static), synced to the tree named in each section.

**Owning WIP:** [P13-l2 Review WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Stitch_Overlap_Review_WIP_20261106.md") and its supplements. Their exact issue tuples, patch owners and side schedules are accepted as recorded.

#### RA-210.1 The block

- **Rule:** a Review scratch probe is a Review duty on the Claude track (RA-166.6 F6, RA-188.1, RA-203.1). It is not a new runtime boundary that needs separate authorization.
- **The probe:** the existing `retainIntermediateGeometry` snapshots, read by an env-gated dump in the scratch census test. That dump is in no patch.
- **Observational parity:** the retained run's `platform-digest` line is **byte-identical** to the non-retained run's, every stage hash included.
- **Node ids:**
  - `simplifiedComplex`, completion's input, has 57,636 nodes with `node.id == index` (0 mismatches);
  - the ids 9679 and 36055 index it directly;
  - the compaction concern in the WIP does not arise.

#### RA-210.2 Provenance of the patch 23301 and 4955 clusters (measured)

| Node | Role | Incident arcs (all `hard=0 rail=0 sing=0`, layout support; FlowRep `mandatory=0`) |
|---|---|---|
| 9679 | **degree-2** crossing of source edge 773–775 (`sedgeT=0.3736864579`) | strand 966 only, FlowRep 21618/21619 |
| 36055 | crossing of strands 966 (family 0) and 459 (family 1), 2.5e-6 bary inside face 1199 | 21574 (966), 7746 (459) |
| 9687 | **degree-2** crossing of the same edge by strand 459 (`sedgeT=0.3736738849`) | strand 459 only |
| 35319 (patch 4955) | **degree-2** crossing of source edge 426 by strand 1331 | strand 1331 only |
| 57362 (patch 4955) | crossing of strands 1331 and 464, 2.3e-5 bary off that edge | 30463, 7902 |

- **Cell 23301:** cycle `9677 9678 9680 9679 36055 9687`. It has four real corners. Its two longer sides are split only by the degree-2 nodes 9679 and 9687, which is why its sides read `[1,1,2,2]`.
- **The microedge 9679–36055 (9.0e-8):** a trace crossing that lands 9e-8 past the point where one of its two traces crossed a source edge.
- **Not the cause:**
  - neither trace is redundant;
  - no identity is wrong;
  - nothing calls for a weld.
- **What it does:** it makes completion's boundary-only split produce quads whose corner sits on their own diagonal. Patch 4955 is the same pattern at 2.6e-6.

#### RA-210.3 Owners of the four strict issues (measured; corrects RA-208/209)

All-pairs census of the strict validator's global contact test on the CB96 Vase mesh:

| Validator variant | Contacts | Strict issues |
|---|---|---|
| legacy | **342** triangle pairs (only the first is reported) | 4 |
| determinants measured in length units | 49 (all concave fan spill, e.g. 4304/4308) | 52 |
| plus a fan from the reflex corner of concave quads | **0** | 3 |

1. **Validator, length units (CB97).**
   - `collinear_segment_overlap2`, `proper_segment_intersection2` and `point_in_triangle2_strict` compared `orient2`, which is twice an area, with a length tolerance.
   - Faces 55/15372 are 5.7e-5 apart with a determinant of 1.6e-8, so they were reported as overlapping.
   - **RA-208/209's "1 global overlap" was a validator false positive.** The ChatGPT Review was right; I own the error.
2. **Validator, concave quads (CB98).** `triangulate_faces` fanned every quad from corner 0. For a concave quad whose reflex corner is 1 or 3, that fan covers the notch.
3. **Completion, pinched quads (CB99).**
   - Quads 21286 (patch 4955) and 41746 (patch 23301) each have a corner within the validator's position tolerance (6.44e-8 for Vase) of a non-incident edge of the same quad. These are the 3 `GeometricVertexOnUnsplitEdge` issues.
   - `quad_embedding_failure` had no contact test.
   - With one, defined by the validator's own tolerance, the boundary search rejects 401 candidates and finds an embedded alternative for every patch. Vase still completes with 67,750 quads.

**After CB97–CB99, Vase has `validationIssues=0`** (no T-junctions, self-intersections, degenerate or inverted faces). Its terminal becomes `NotProductionReady:completion detail=AggregateCompletionValidationFailure`, which is the calibrated quality gates (§2.1 item 10), now reported truthfully.

#### RA-210.4 Trajectory finding: side subdivision by source-edge crossings (P13-n, Review next)

- **The completed Vase mesh fails quality by a wide margin:**
  - nonConvex 16,812;
  - angle P5/P95 6.5°/180°;
  - warpage P95 156°;
  - scaled Jacobian min −1;
  - boundary valence mismatches 248.
- **Census of the output:** **26,323 of 67,750 quads (39%) have a corner above 170°**, and there are **4,543 valence-2 vertices**.
- **The proxy reading:** those corners sit where degree-2 arrangement nodes, which are source-edge crossings of a single trace, become patch-side subdivisions. Completion then has to place flat corners on them.
- **Why this conflicts with DESIGN:**
  - DESIGN §4/§5 A3 makes side subdivision counts a property of the **conformity plan** ("edge labels are subdivision counts along those arcs").
  - Here they are a property of how the source triangulation cuts each trace, which is a representation artifact.
- **This is a hypothesis, not a fix.** The degree-2 attribution is by output-valence proxy.
- **The Review must:**
  - count degree-2 nodes and flat corners exactly per patch;
  - check that the quality metrics (warpage, normal, Jacobian) evaluate concave quads faithfully, as CB98 does for contact;
  - name the owner: the A3 plan versus completion's interior-vertex patterns.

  No CB until then.

#### RA-210.5 Exact turns (each applies on the previous one's result)

**CB97 — `M6-CP3-CB97-P13-VALIDATOR-CONTACT-LENGTH-UNITS`**
- **Precheck:** `git diff --quiet 11c8172ad467c6dc865f2f3352e75b78f5469a2b HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB97_P13_Validator_Contact_Length_Units.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB97_P13_Validator_Contact_Length_Units.diff").
  - SHA-256 `84b8414fb58df6dfb90b5e425d15c26aac0ccaa73b4ffbf31dbf9dbc38737071`.
  - 114 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/SourceAuthoritativeMeshValidator.h` | `3 0` | `7f3ae0db…` |
  | `src/validation/SourceAuthoritativeMeshValidator.cpp` | `18 9` | `c71a2054…` |
  | `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` | `30 0` | `627eb086…` |

- **Content:** `line_offset2` is the signed distance from a line, and all three 2D predicates compare it with the tolerance.
- **New test:** `SourceAuthoritativeMeshValidatorPhase22.CoplanarContactIsMeasuredInLengthUnits`. It FAILS on legacy.

**CB98 — `M6-CP3-CB98-P13-VALIDATOR-CONCAVE-QUAD-TRIANGLES`**
- **Precheck:** the CB97 results.
- **Patch:** [`…CB98_P13_Validator_Concave_Quad_Triangles.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB98_P13_Validator_Concave_Quad_Triangles.diff").
  - SHA-256 `14986e38261eb46796262b262801bcf9c5dd255344c918f10867224510b7ce6a`.
  - 113 lines; **keep its 4 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `SourceAuthoritativeMeshValidator.h` | `3 0` | `3b31cb35…` |
  | `SourceAuthoritativeMeshValidator.cpp` | `35 2` | `55360202…` |
  | `SourceAuthoritativeMeshValidatorPhase22Tests.cpp` | `32 0` | `a02f6a79…` |

- **Content:** `quad_fan_corner` fans a concave quad from its reflex corner, judged against the Newell normal.
- **New test:** `…Phase22.ConcaveQuadContactUsesTrianglesInsideTheQuad`. It FAILS on legacy.

**CB99 — `M6-CP3-CB99-P13-COMPLETION-CORNER-ON-OPPOSITE-EDGE`**
- **Precheck:** the CB98 results.
- **Patch:** [`…CB99_P13_Completion_Corner_On_Opposite_Edge.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB99_P13_Completion_Corner_On_Opposite_Edge.diff").
  - SHA-256 `92c67e63bbbeabb7504e349c8f48637c3b26aee39e36423fbeee0a1e2d45dcbe`.
  - 344 lines; **keep its 14 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/PureQuadCompletion.h` | `11 4` | `c9a8d90d…` |
  | `SourceAuthoritativeMeshValidator.h` | `7 0` | `ab0e2f01…` |
  | `src/geometry/PatchDescriptor.cpp` | `4 0` | `30cd7da3…` |
  | `src/geometry/PureQuadCompletion.cpp` | `42 15` | `4da63b68…` |
  | `SourceAuthoritativeMeshValidator.cpp` | `14 10` | `abb10499…` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `41 0` | `f728585d…` |

- **Content:**
  - `source_position_tolerance` is the one shared definition. The validator calls it, and so does completion, once per pass.
  - New kind `CornerOnOppositeEdge`.
  - `PureQuadCompletionOptions::positionTolerance`, which defaults to off for direct callers.
- **New test:** `PureQuadCompletionPhase18.QuadEmbeddingRejectsACornerOnTheOppositeEdgeAtThePositionTolerance`, using the Vase quad 41746 witness in all 8 orders, with a square as the positive control. It cannot compile on legacy; behaviourally, legacy accepted the witness.

**Build (each CB):** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.

**Routes:**

| CB | Mismatch | Infrastructure |
|---|---|---|
| CB97 | `M6-CP3-PLAN-P13-VALIDATOR-CONTACT-LENGTH-UNITS-STOP` | `M6-CP3-CB97A-…-ORCH` |
| CB98 | `…-VALIDATOR-CONCAVE-QUAD-TRIANGLES-STOP` | `CB98A-…-ORCH` |
| CB99 | `…-COMPLETION-CORNER-ON-OPPOSITE-EDGE-STOP` | `CB99A-…-ORCH` |

**Verified in scratch:**
- The chain applies cleanly on a fresh `11c8172ad` worktree and reproduces the tested tree byte for byte.
- The local gate passes **905/906** (only row 283, O16).
- Census digests for Plane, MultiFaceSeam, CloseSheets, Cylinder and BunnyRandom are **identical**.
- Vase is identical through `simplification`; completion is `e63758b9…/67750`, with `validationIssues=0`.
- GCC 16 `-Wall -Wextra`: no new warnings in any changed unit.

#### RA-210.6 TB84 — `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-EXEC` (after CB99)

- **Gate:** [`Architecture_M6_TB84_P13_Contact_Predicates_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB84_P13_Contact_Predicates_Full_Gate_Case_Manifest.tsv").
  - 906 rows, SHA-256 `09eff7ed146ef39836706f4d87ae8e9309e35ab16787b6d1e8c3f39314a0b7ff`.
  - TB83's 903 rows byte for byte, plus GUARD rows 904–906 (the three new tests).
  - `SELF_CHECK_PASS cases=906 deferred=81`.
  - **906/906**, membership **987**.
- **Census:** Cylinder PASS; BunnyRandom P13-e at vertex 49; Vase RED.
- **Pinned digests:**
  - gate rows 795/796/797/864, census Cylinder and census BunnyRandom: byte-identical to TB83;
  - Vase: byte-identical through `simplification`.
- **Registered expectations,** observed on macOS and recorded, not pinned:
  - Vase `completion` hash;
  - Vase suffix ` validationIssues=0`;
  - Vase terminal `NotProductionReady:completion detail=AggregateCompletionValidationFailure`.

  A Linux difference in any of these routes to REV.
- **Routes:**
  - mismatch → `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB84A-P13-CONTACT-PREDICATES-ORCH`.

#### RA-210.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 49 — NEXT | `M6-CP3-CB97-P13-VALIDATOR-CONTACT-LENGTH-UNITS` | Implementation agent |
| 50 | `M6-CP3-CB98-P13-VALIDATOR-CONCAVE-QUAD-TRIANGLES` | Implementation agent |
| 51 | `M6-CP3-CB99-P13-COMPLETION-CORNER-ON-OPPOSITE-EDGE` | Implementation agent |
| 52 | `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-EXEC` | Implementation agent |
| 53 (Review, after TB84) | `M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY` (P13-n) | Claude, scratch build (RA-210.4) |
| then | P13-e, O31, O32e → d → b/c, O33 | Claude, scratch build |
| then | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | — |

#### Review closeout

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Retained-run parity. Node and arc provenance. All-pairs contact census under each variant. Pinch census and Vase outcome. Output flat-corner census |
| Non-vacuity checked | All three new tests fail on legacy; CB99's witness was accepted in production |
| Accepted selector prefix re-hashed | The 906-row manifest's 903-row prefix is TB83's |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| Turn boundary held | No product or test source changed in the repository; patches are committed `.diff`s |
| `STATUS` lifecycle maintained | Started-at preserved; IN_PROGRESS beacon pushed; COMPLETE is the final write, with Successor CB97 |

## `Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Scratch_Recovery_20261106.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Scratch_Recovery_20261106.md`; moved verbatim.

### P13-l2 independent Review scratch recovery — 2026-11-06

**Canonical turn:** `M6-CP3-DEFN-P13-COMPLETED-MESH-STITCH-OVERLAP`, still **IN_PROGRESS**. The owning review record is `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Stitch_Overlap_Review_WIP_20261106.md`. This record concerns scratch execution only; it does not approve a producer patch, alter the accepted gate, or supersede source authority.

#### Verified attempted probes

1. Prior scratch run [42139508263](https://github.com/akashskypatel/Directional/actions/runs/42139508263): schema and 125 compilation steps passed; workflow `cancelled` at 13-minute bound during Vase, before the proposed lineage TSV existed. Result archive `13466872938` SHA-256 `746a488a42eb7a80c20807a59ee0822d26950af1ad79559da687808d4a51b9f5`; log archive `13466768140` SHA-256 `8073766b73f729164f7410e125fc93fa7a512d207f2e72f610f5fd65cd5a7fab`. Its inline compilation deviated from the mandatory reusable-compile policy; do not repeat.
2. New no-build GDB attempt [42142183217](https://github.com/akashskypatel/Directional/actions/runs/42142183217): schema validated; immutable CB96 package `13460725846` matched source `11c8172ad467c6dc865f2f3352e75b78f5469a2b` and all **28/28** SHA-256 entries passed. GDB breakpoint was installed (`0xdfce58`), but the filtered Vase case failed at fixture discovery: the packaged binary runs from `$RUNNER_TEMP/compiled/bin` and expects sibling `$RUNNER_TEMP/test-data/benchmarks/fixtures`. There was **zero actual Vase geometry execution** and no witness matrices. This was infrastructure, not semantic RED. Result archive `13468795251` SHA-256 `b9beda9fb95ace2a3bc47ec800c0c10f2d0dd571af23ad7f0fd54a9d2ebf1fa8`; log archive `13468690396` SHA-256 `8c301410bbf254e6194f3de757efb1542fb3183aca000d101597f35e0393b048`.
3. **Diagnosed retry:** workflow `.github/workflows/p13l2-immutable-gdb-20261106.yml` corrected at commit `a764e5931b68b6323a7e32f95933439b1ac9b175` by providing the **original immutable CB96 checkout's** `benchmarks` fixture path as a sibling test-data symlink. The old `chmod` command was removed. Separate marker retry 2 committed `4975cc24558d0e8b21f3fcc0377585f3fac47f19`; mailbox key `p13l2-immutable-gdb`, ref `workflow-mailbox`. **This trigger is not a success claim.** Do not launch a duplicate while matching retry is running.

#### Pending classification

If the retry produces `V_colmajor_f64.bin`, `Q_colmajor_i32.bin` and `shape.txt`, verify the artifact manifest and analyze them only as **geometric candidates**: the debugger snapshot contains no source-chart, local-sheet, source-entity, or patch lineage. The diagnostic script `analyze_immutable_geometry.py` is saved as a chat attachment. It cannot certify source-identity equality, authorize proximity welding, or provide the requested patch-ownership classification. If the retry fails, diagnose its log once and preserve WIP. Independently capture authoritative lineage before freezing P13-l2 corrective patches.

Do not count scratch runtime as the 903-case TB83 gate. Preserved accepted CP2 491/491; TB83 903/903, membership 984; Vase 4 validation issues (1 intersection + 3 T-junctions), intermediate 67,750 quads; stable regression 66 / 17 / 49, debt 1; CP3/selector497 unpromoted. Source/test/build/benchmark files on the working branch were not changed. Cleanup of both temporary scratch callers/markers must occur only after evidence of the currently running retry is preserved, via workflow-first `agent-turn-cleanup.yml`; do not remove `workflow-mailbox` history.

#### 2026-11-06 01:30Z resumption — verified CB96 output

- Corrected workflow retry 2 (actual run `42142847864`, marker `4975cc24558d0e8b21f3fcc0377585f3fac47f19`) failed before mesh processing because the test-data symlink was mistakenly placed at `$RUNNER_TEMP/test-data`. Source `tests/TestFixturePaths.h` requires `test_executable_directory().parent_path()/test-data`. Its result artifact `13467734367` sha256 `143979d672835bf6569d4c17df47aada4a42178451723f5caa31356458b87447` and log `13466834928` sha256 `bf30270175c5024ea812a4871dc24583123545e1daee33a29ae9fc945b980c34` passed ZIP digests and the 2/2 nested manifest. No geometry from this attempt.
- Workflow fixture-path correction commit `41ab0815f2d02ddd0bc12d83a869c5071079c778` put all three `test-data` references under `$RUNNER_TEMP/compiled/test-data`, leaving the immutable executable and original fixtures intact. Retry 3 trigger `df32302f948e57924163a943210bd8dc8451eafd`; terminal [run 42144458838](https://github.com/akashskypatel/Directional/actions/runs/42144458838) **succeeded** as scratch capture, with validator and capture jobs both GREEN. Result artifact **13469796788**, ZIP sha256 `27e77959b11c284f9f77a1e42b456431af27ceb76aae805c506cb18f68e1a664`, internal 5/5 SHA256SUMS valid. Dedicated log artifact **13469901520**, ZIP sha256 `ef11e69734ac6657da9b8ba55952963d7c22563825573c38ed13ea68308be786`. Immutable CB96 source `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, package artifact `13460725846`, 28/28 SHA256SUMS PASS, no rebuild/relink.
- The debugged Vase process took **213.419s**, selected exactly one test, and failed as expected with `NotProductionReady:completion detail=SelfIntersectingFace`; this is not a formal TB gate. GDB captured **67,961 vertices / 67,750 quads**, Eigen column-major binary matrices, at strict validator entry. Completion digest matches TB83: `5a2aff2aff729ab8`; validation issues remain `4 GeometricVertexOnUnsplitEdge=3 SelfIntersectingFace=1`.
- Read-only geometric nearest-edge scan (threshold `1e-7`) yielded **7 geometric candidates**; it does **not** incorporate source-chart compatibility. Two historical witnesses persist geometrically: vertex **35160** on output edge **(4618,35159)** at t=**0.500337309907436**, distance `3.131196163343484e-08`; vertex **35161** on the same edge at t=**0.0006746198148661404**, distance `6.262392326013387e-08`. Five additional raw geometric candidates: (45955, 15608-23275); (51942, 51941-66437); (53052, 28576-53053); (53261, 53259-53262); (57044, 45240-57039). **Do not classify any of these as the three source-authoritative T-junctions without original validation issue IDs and lineage**. The seven candidates do not contradict the strict three-issue count.
- Historical overlap faces **55** and **15372** retain almost-coplanar coordinates in CB96. However, independent projected-polygon intersection over their actual CB96 coordinates yielded **zero positive-area intersection**, as did a local coplanar neighbour search around each. Thus the old RA-208 patch owners **118/54** cannot be promoted as current overlap owners without new evidence. The currently reported global crossing is not yet localized.

**Current assessment:** P13-l2 remains open. Capture establishes the current mesh geometry and two stable geometric witnesses, but does *not* contain `PureQuadVertexLineage`, exact stitch keys or chart/region/sheet source support, nor the validator's exact four issue ID records. Corrective ownership at A3/A4/A5/A6/A7 is therefore not independently adjudicated; do not merge by proximity, skip collision checks, change acceptance, or authorize source patch yet. Retain accepted CP2 491/491, TB83 903/903 + membership 984, 66/17/49 stable, debt 1, CP3/selector497 unpromoted. Clean two temporary callers then the two markers only after these scratch artifacts are preserved. The same Review turn continues.

##### Final scratch hygiene

Both temporary workflow callers were deleted before cleanup. The existing durable `agent-turn-cleanup.yml` completed [run 42145487638](https://github.com/akashskypatel/Directional/actions/runs/42145487638) with schema, cleanup and mailbox jobs SUCCESS. Result artifact `13469099732` ZIP SHA-256 `7e868c4774981cae72440b41144efb7173b9c53f6a15da51e822f5b8d8d4`; its `cleanup-result.json` confirms removal of the two exact P13-l2 trigger paths and manifest, and cleanup commit `13e43432bd583d313f0aebc27577a09a67385e2c`. Mailbox history remains on orphan branch. The Review remains unfinished due to missing authoritative post-CB96 lineage and actual global crossing owner identity.

## `Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Adversarial_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Adversarial_Review_20261108.md`; moved verbatim.

### RA-217 — Step 64.5 (D7b) re-entered: one run decomposition, no zero-weight failure, exact CB108 and CB109

**Turn:** `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT`, re-entered · 2026-11-08 · Claude Review, runtime-free (`REVIEW_TURN_POLICY.md` §4.3). Nothing was built or run. Both patches were checked with `-fsyntax-only` only, on every changed unit plus `SurfaceCellTracing.cpp` and `RemeshPipeline.cpp`. Every expected test value was recomputed with an exact-fraction model of the new algorithm. Product source = CB107 `34967c89817a…`, unchanged at HEAD.

Reviewed: the [D7b decision](#architecture_m6_cp3_defn_p13_a3_metric_breakpoint_placement_review_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Review_20261108.md"), against [RA-216 §8](#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_adversarial_review_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md") and the source. Evidence read: TB90 gate result artifact `13633654777`, raw log `434.log` (test 392: `entryCount=4`).

#### 1. Verdict

The placement formula, the reversal analysis and the single-piece rule are right. The decision still does not deliver what RA-216 §8 asked of it: an exact CB108 and TB91. Instead it gives the implementation agent a prose scope with open design choices, and that scope is monolithic, covering profile, placement, canonicalization, both width receipts, validator recomputation and tests at once. It also contradicts the count it must agree with, and adds a production failure mode. Finally, it leaves the receipt encoding and width bound to the implementation agent, and misses that the switch rewrites an accepted selector test.

RA-217 makes four changes:
- it fixes the contract (§4);
- it splits the work into an unwired CB108 and a switch CB109, each followed by its own TB;
- it freezes both patches and both manifests;
- it amends DESIGN §7.4.

#### 2. What stands

- **Placement formula (rule 2):** `T = jW/n`; take the run with `C_r ≤ T < C_r + W_r`; set `t = (jW − nC_r)/(nW_r)`; the point is `a_r + t(b_r − a_r)`; within the run, the piece is chosen by its length fraction. This is RA-216 §8.
- **Reversal analysis (rule 3):** a zero-weight run makes the reversed join ambiguous. It is proved in §3 G3 below, and it is right.
- **Single-piece rule (rule 4):** keep the unreduced `(j, n)` on piece 0, including where h varies, so curved-disk output and single-piece receipt widths are unchanged.
- **Ownership (rule 5):** a baseline-only per-span profile. `ConformityScheduleEntry`, `ConformityBreakpointLocation` and `GlobalConformityPlan.cpp:49` stay unchanged, and the framed CP1/CP2 copies stay frozen.
- **Validator:** the `denominator == n` check at `GlobalConformityBaselineValidator.cpp:855-864` holds only for single-piece spans.

#### 3. Findings

- **G1 (high): no exact patch, and CB108 is monolithic.**
  - RA-216 §8 required the step-64.5 DEFN to freeze an exact CB108 and TB91, and it froze neither.
  - Its CB108 scope bundles five changes:
    - a run profile;
    - the placement switch;
    - "source-entity canonicalization";
    - producer and validator width receipts;
    - validator recomputation, plus tests.
  - It also leaves design choices open: "reduced or explicitly unreduced, chosen once", and "a provably conservative declared upper bound or a bounded exact algorithm".
  - The implementation agent receives only exact patches (RA-172, RA-215).
  - **Correction:**
    - CB108 adds the shared run profile and an unwired placement function, with tests; it is digest-neutral.
    - TB91 expects byte-identical digests.
    - CB109 is the smallest atomic switch.
    - TB92 gets a pre-registered rule.
- **G2 (high): rule 1 contradicts the count's runs.**
  - Rule 1 splits runs at "sheets, components, barriers, discontinuities or uncertified source-carrier transitions".
  - The D7 count (`derive_partition_stable_preferred_count_exact`) splits only where the 3D direction changes, using Cauchy–Schwarz equality with `d·u > 0`.
  - Two run decompositions would mean that placement weights no longer sum to what the count measured.
  - Within one span, pieces are chained by exact source-point equality (`previous != piece.first` fails closed), so a span cannot jump sheets or components. `ConformitySpanInput` has no barrier field.
  - **Correction:** one function, `derive_partition_stable_metric_runs`. The count is refactored onto it in CB108 and must stay byte-identical (TB91), and placement reads the same runs.
- **G3 (high): fail-closed zero weights add a production failure mode.**
  - With floor weights `F_r = ⌊2⁶⁴·metric_r⌋`, any run whose metric is below 2⁻⁶⁴ has `F_r = 0`.
  - DESIGN requires A3 to place every span, so the decision's typed rejection becomes a baseline-build failure. That would be a regression, and it would come from code that no consumer reads for multi-piece spans.
  - The ambiguity is real. With `F_r = 0` between runs r−1 and r+1, forward ordinal j lands on `a_{r+1} = b_r`, while reversed ordinal n−j lands on `a_r`, which is a different point when run r has positive length.
  - **Correction:** placement weights `W_r = ⌈2⁶⁴·metric_r⌉ = isqrt(⌈2¹²⁸·q_r⌉ − 1) + 1`, from the same exact squared metric `q_r`. This gives:
    - `W_r ≥ 1` for every positive-length run, so no run is erased and the half-open rule reverses exactly (`t' = 1 − t`; a join resolves to the same physical point from either side);
    - invariance to partition and reversal, as for `q_r`;
    - the count keeps its floor.
  - Falsifier (CB108 GUARD 917): a run of length 2⁻⁷⁰ contributes 0 to the count but is placed with weight 1. Every breakpoint exists, breakpoint 1 sits at `y = 1 − 3·2⁻⁶⁶`, and reversal is exact.
- **G4 (medium): "canonical physical source-entity point" and "typed provenance" are undefined.**
  - A location is `(supportPieceIndex, local fraction)`, and rule 5 itself forbids widening the shared struct.
  - The half-open rule already decides a join: the later piece, at local 0.
  - A reversed span is a different input, so it reaches the same physical point through a different `(piece, local)`. That is correct, because the invariant is the point, not the representation.
  - The source entity follows from the piece's carrier and the local fraction, so storing it would add a second source of truth.
  - **Correction:** drop both phrases. Tests pin both the stored location and the exact point.
- **G5 (medium): the width receipt is over-specified.**
  - M4 closure §5.5 defines the breakpoint widths as those of values "encountered by validation". They are report-only and gate only on deterministic recomputation and equality.
  - The decision instead requires an all-ordinal maximum of reduced forms without enumeration, while admitting that the bound may not be provable.
  - The legacy receipt already samples ordinals {0, 1, n−1, n}, the same ones the validator checks.
  - **Correction:** keep that definition. Producer and validator call the same placement function at ordinals 1 and n−1. Single-piece values are bit-identical to today (`(1, n)` and `(n−1, n)`), and multi-piece widths become those of the stored reduced fractions.
- **G6 (medium): "independent recomputation" is ambiguous.**
  - The count's established pattern is that the validator re-derives from the authoritative input through the shared support function and compares the results.
  - A second, duplicated implementation adds no trust. The oracle for the function itself is exact-fraction unit tests.
  - **Correction:**
    - The plan stores the runs privately; prefixes and weights are derived on use.
    - The candidate validator recomputes runs from the input for the width twin.
    - `validate_global_conformity_baseline` compares the plan's interior locations with a placement re-derived from the input.
- **G7 (medium): the switch rewrites an accepted selector test.**
  - `CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant` (selector:392, gate row 434, part of CP2 491) asserts `localDenominator == count` on a two-piece span.
  - After the switch, that span stores 0:1/2 and 1:1/2 instead of 0:2/4 and 1:2/4. The physical points are the same.
  - The decision's closeout says "no selector/source contract rebaseline", which is wrong.
  - **Correction:** CB109 amends that test's assertions to the exact new locations, adding `count == 4`, which is observed in TB90's raw log. The test identity, its PASS expectation and its permutation and digest invariants are unchanged, and its assertions become stronger, not weaker. This is registered here as a Review-authorized assertion amendment.
- **G8 (low): some falsifiers have no representation in the unit's scope.**
  - "Source-face row order", "close distinct sheets" and "foreign chart alias" cannot be expressed in a span input.
  - Contiguity and malformed-span rejection are already pinned by GUARD 913.
  - Mesh-level sheet controls belong to D5's TB, where multi-piece spans reach a consumer.
- **G9 (low): the production effect was not stated.**
  - No production consumer reads multi-piece placement: curved-disk accepts only single-piece Mandatory edge arcs (`SurfaceCellTracing.cpp:17449-17473`, `:17641`).
  - The switch therefore changes only multi-piece width receipts, which feed the baseline digest and, through `baselinePlanDigest`, the tracing hash. This is TB92's rule.

#### 4. Corrected D7b contract (replaces decision rules 1–5 and the width section)

1. **Runs.** These are exactly the D7 count's runs: maximal consecutive pieces with the same direction. Each run is stored as `BaselineConformityMetricRun{firstPiece, pieceStarts, squaredMetric}`, where:
   - `pieceStarts[k]` is the fraction of the run's length (by `d·u`) at which piece k starts;
   - `squaredMetric` is the exact `S²/|u|²`.

   The count is `round(Σ ⌊2⁶⁴√q_r⌋ / 2⁶⁴)`, halves down, minimum 1, and is unchanged.
2. **Placement of ordinal j of n.**
   - Ordinals 0 and n are the endpoints, stored as `0:0/1 first` and `last:1/1 last`.
   - A single-piece span stores `0:j/n`, unreduced.
   - Otherwise, use the weights `W_r = ⌈2⁶⁴√q_r⌉ ≥ 1`. Take the run with `C_r ≤ jW/n < C_r + W_r`, and set `t = (jW − nC_r)/(nW_r)`. The piece is the last k with `pieceStarts[k] ≤ t`, and the stored local fraction is `(t − τ_k)/(τ_{k+1} − τ_k)` in reduced form, with `τ_K = 1`.
3. **Profile validity.** The runs must tile the pieces in order. Each run's starts must begin at 0, rise strictly and stay below 1, and `squaredMetric > 0`. Otherwise, or for an ordinal outside `[0, n]` or `n < 1`, placement returns nothing.
4. **Ownership.** The plan holds `metricRuns_` in schedule order. Build derives the runs from the input alongside the preferred count. The width producer, the validator twin and the wrapper's interior check each re-derive placement through the same function.
5. **Width receipt.** Ordinals {0, 1, n−1, n}, using the actual stored numerators and denominators, per M4 §5.5.

Within a run, placement stays linear in length; that deviation is documented in RA-216 §8. A single-run span is placed at `t = j/n`.

#### 5. Exact CB108 — the run profile and placement, not yet wired

- [Patch](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB108_P13_A3_Metric_Breakpoint_Placement_Exact.diff"): SHA-256 `c56559ae0d2abced96151cb6ad113fc53c7a70b47200eec04499b847ae08f202`, 532 lines, 11 single-space context lines. Numstat: `15 0` `GlobalConformityBaseline.h`; `124 13` `GlobalConformityBaselineSupport.cpp`; `18 0` `GlobalConformityBaselineSupport.h`; `266 0` `GlobalConformityBaselineTests.cpp`. It applies cleanly to HEAD (product = CB107 `34967c89…`).
- **Product changes:**
  - `BaselineConformityMetricRun` is added to the baseline header, with nothing reading it yet.
  - `derive_partition_stable_metric_runs` is added, and the count now sums floors over it. This is a refactor with identical arithmetic.
  - `derive_metric_breakpoint_location` is added, with `scaled_metric_floor` and `scaled_metric_ceiling`.
- **Tests (GUARD 915–917):**

| Test | Asserts | Fails on |
|---|---|---|
| `D7bBreakpointsFollowTheRunNotThePieceIndex` | λ=(0.1, 3.9) at n=4: `1:3/13`, `1:19/39`, `1:29/39` (x = 1, 2, 3); single piece `0:2/4`; 5 splits × forward/reversed all at x = j | piece-index placement (0:2/4, 1:0/4, 1:2/4 = x 0.05, 0.1, 2.05); a reduced single-piece fraction |
| `D7bBreakpointsShareOrdinalsAcrossRunsByMetric` | Legs of metric 1 and 3 (h rising to ½): runs `{0,[0],1}` and `{1,[0,½],9}`; points (1,0), (1,⅔), (1,4/3), whole and with leg 2 cut, forward and reversed; the corner is `1:0/1` (reversed `2:0/1`) | allocation by total length ((0.75, 0)), piece-index allocation ((0.5, 0)), a second run decomposition |
| `D7bBreakpointsGiveEveryRunWeightAndRejectBrokenProfiles` | rising h on one piece keeps `0:j/6`; a 2⁻⁷⁰ run: count 4, `1:73786976294838206461/295147905179352825856`, exact reversal; 10 broken profiles or ordinals, and an empty span, give nothing | floor weights (fail closed), unchecked profiles |

#### 6. TB91 — CB108 full gate

- [Manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB91_P13_A3_Metric_Breakpoint_Placement_Full_Gate_Case_Manifest.tsv"): 917 rows, `0b16a30e332e42888339c6bdd8bcb66127281fca2c6430e22ef7e98065fb1752`. It is TB90's 914 rows plus GUARD 915–917. `SELF_CHECK_PASS cases=917 deferred=81`; membership 998; ledger v5 `fd433f54…`; census `3af1dc0d…`; harness `78b8002c…`.
- **Expect:**
  - 917/917;
  - all 7 `platform-digest` and 7 `a3-coverage` lines byte-identical to TB90;
  - census Cylinder PASS, BunnyRandom and Vase registered RED.
- **Any digest change means the refactor changed the count.** Route: `M6-CP3-TB91-P13-A3-METRIC-BREAKPOINT-PLACEMENT-FULL-GATE-REV`; infrastructure → `M6-CP3-TB91A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-ORCH`.

#### 7. Exact CB109 — make the D7b placement the plan's, and TB92

- [Patch](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB109_P13_A3_Metric_Breakpoint_Placement_Switch_Exact.diff"): SHA-256 `be4cac4ea85651d0d327f28ba6c9df0a625c4e0e22d518bdedb31d401116e302`, 377 lines, 15 single-space context lines. Numstat: `6 2` `GlobalConformityBaseline.h`; `29 37` `GlobalConformityBaseline.cpp`; `0 15` `GlobalConformityBaselineSupport.cpp`; `0 1` `GlobalConformityBaselineSupport.h`; `44 20` `GlobalConformityBaselineValidator.cpp`; `51 2` `GlobalConformityBaselineTests.cpp`. It applies only on top of CB108.
- **Why these five files are one turn:** the producer receipt and its validator twin are compared for equality, and the wrapper's interior check reads the plan. Changing any one of them without the others fails every multi-piece build.
- **Product changes:**
  - The plan stores `metricRuns_`, and `breakpoint_location` delegates to the placement function.
  - Both width receipts observe the stored locations.
  - The wrapper compares interior locations with a placement re-derived from the input.
  - `exact_to_size_checked` is removed, since the switch left it unused.
- **Tests:**
  - selector:392's denominator assertions are replaced by `count == 4`, `0:1/2` and `1:1/2` (G7).
  - New GUARD 918, `D7bPlanBreakpointsAreTheMetricPlacementForEverySplit`: on the square fixture at h = ¼, the whole, {⅛} and halves splits each give a plan location equal to the D7b location at x = j/4. The stored interior locations are `0:1/4 0:2/4 0:3/4 | 1:1/7 1:3/7 1:5/7 | 0:1/2 1:0/1 1:1/2`. This test fails on CB108, where the uneven split's plan locations are still piece-index.
- **TB92:** [manifest](Architecture_M6_TB92_P13_A3_Metric_Breakpoint_Placement_Switch_Full_Gate_Case_Manifest.tsv) of 918 rows, `d714a52e4f3c7716dd08ea40258ad04fea0c93ecc998b77aa0eab60a77846d13`, membership 999, `SELF_CHECK_PASS cases=918 deferred=81`. Pre-registered outcome:

| Record | Rule |
|---|---|
| Gate | 918/918, including selector:392 (row 434) and GUARD 918 |
| `a3-coverage` (7) | byte-identical to TB91: curved-disk reads only single-piece spans, which are unchanged |
| `platform-digest` through `global-topology-plan` | byte-identical |
| `global-conformity-baseline` | the hash may change (multi-piece width receipts); its `/count` must be identical |
| Later tokens | if the baseline hash is unchanged, everything is identical. Otherwise they may change, but every `/count` and `validationIssues` stays identical for the 4 gate cases and census Cylinder; Vase's later tokens are recorded |
| Census | Cylinder PASS; BunnyRandom RED `SingularityPortClassCountMismatch`; Vase RED `AggregateCompletionValidationFailure` |
| Any baseline build failure, verdict change or `/count` change | MISMATCH → `M6-CP3-TB92-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-FULL-GATE-REV` |

#### 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64.5 | `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT`: COMPLETE, re-entered by RA-217 | Review |
| 64.6 | `M6-CP3-CB108-P13-A3-METRIC-BREAKPOINT-PLACEMENT`: compile only. Mismatch → `M6-CP3-PLAN-P13-A3-METRIC-BREAKPOINT-PLACEMENT-STOP`; infrastructure → `M6-CP3-CB108A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-ORCH` | implementation agent |
| 64.7 | `M6-CP3-TB91-P13-A3-METRIC-BREAKPOINT-PLACEMENT-FULL-GATE-EXEC` (§6) | implementation agent |
| 64.8 | `M6-CP3-CB109-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH`: only after TB91 MATCH. Mismatch → `M6-CP3-PLAN-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-STOP`; infrastructure → `M6-CP3-CB109A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-ORCH` | implementation agent |
| 64.9 | `M6-CP3-TB92-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-FULL-GATE-EXEC` (§7). Infrastructure → `M6-CP3-TB92A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-ORCH` | implementation agent |
| 64B → 65D → 66+ | D5 chains → D4 uniform → D4 annulus → D9c → A2b trace → A4 disc → D8 → per-disc corners (D6 user decision) | Review DEFN, then CB, then TB each |

No Review turn sits between a green TB91 and CB109.

#### 9. Corrections to the D7b decision

- Rule 1's extra split conditions are withdrawn (G2).
- Rule 3's fail-closed is replaced by ceiling weights (G3).
- The "canonical source entity" and "typed provenance" phrases are dropped (G4).
- The width-receipt section is replaced by §4 item 5 (G5).
- Its selector claim is corrected (G7).
- Its CB108 scope is replaced by §5 and §7.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Not re-hashed. selector:392's assertions are amended in CB109 (G7); its identity and PASS expectation are unchanged, and TB92 executes it |
| Decisive claims re-derived | Read the count, placement, both width receipts, the wrapper check, curved-disk and the M4 §5.5 receipt definition. Checked every expected value with an exact-fraction model, and test 392's count against the TB90 raw log |
| Non-vacuity | CB108 tests assert values that piece-index placement, total-length allocation and floor weights each violate. GUARD 918 fails on CB108 |
| Obligations carried | D5 64B; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB90 914/914, membership 995; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 | Updated |
| Turn boundary | No product or test source changed in the repository; syntax checks and an exact-fraction model only |

## `Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Review_20261108.md`; moved verbatim.

### D7b — Exact A3 metric-breakpoint placement (runtime-free Review)

> **Partly superseded by [RA-217](#architecture_m6_cp3_defn_p13_a3_metric_breakpoint_placement_adversarial_review_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Adversarial_Review_20261108.md") (2026-11-08).** The placement formula, reversal analysis, single-piece `(j,n)` rule and baseline-only ownership stand. Rule 1's extra run splits, rule 3's zero-weight fail-closed (replaced by ceiling weights), the "canonical source entity"/"typed provenance" wording, the width-receipt section and the prose CB108 scope are replaced by RA-217 §4–§7: exact CB108 (unwired) → TB91 → exact CB109 (switch) → TB92. The closeout's "no selector rebaseline" is corrected: CB109 amends selector:392's assertions.

**Turn:** `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT`, step 64.5, 2026-11-08. **Disposition:** bounded design definition, not a compile, test, or production-success claim. **Next separate turn:** `M6-CP3-CB108-P13-A3-METRIC-BREAKPOINT-PLACEMENT` (Code + Build, compile-only), then `M6-CP3-TB91-P13-A3-METRIC-BREAKPOINT-PLACEMENT-FULL-GATE-EXEC` (immutable artifact-only Test + Benchmark). These new IDs are turn metadata, never code symbol names.

#### Evidence and authority

TB90 (CB107 source `34967c89817a9d43a7c99eaf337032f9e9a927fb`) verified 914/914 required cases, membership 995, GUARD 914 PASS, and Cylinder PASS/BunnyRandom and Vase expected RED. The accepted D7 *count* now uses per-run integer metrics, but current `GlobalConformityBaseline.cpp` placement uses the legacy **piece-index** rule. RA-216 §8 prescribes physical-run metric allocation and length-within-run placement; this definition freezes its remaining representation, edge-case, validation and width obligations without changing D5/D4. Reviewed against the exact source snapshot `e8c56a30c2bbb64c5ec384321c37663c4f49ec72`. No product binary was run in this Review.

#### Normative placement and authoritative profiles

1. Use the exact oriented `ConformitySpan` source route and RA-216 §4's canonical maximal admissible straight run decomposition (no crossing physical kinks, sheets, components, barriers, discontinuities or uncertified source-carrier transitions). Its canonical geometric segments have exact rational source-attached endpoints and local monotonically increasing geometric coordinates. A different partition of one straight run is **not** a different physical path. The D7 count produces each nonnegative integer `F_r = floor(2^64 S_r / |u_r|), where S_r is RA-216 §4’s exact rational projected density integral` with the exact one-root decision already defined, and prefix `C_r=Σ_{k<r}F_k`, total `F=ΣF_r` in unbounded integer arithmetic. The final scheduled `n`, not just preferred count, controls placement. Don't recompute a different density or independently round each breakpoint.
2. For `j=0` and `j=n`, return exact source-attached span endpoints, with their original endpoint and orientation identity. For `0<j<n` and `F>0`, let `T=j F/n`. Select the unique nonzero-weight run whose half-open interval `[C_r,C_r+F_r)` contains `T` and set `t=(jF-n C_r)/(nF_r)`. Interpolate `P=a_r+t(b_r-a_r)` using exact rational arithmetic. For the chosen representational segment with exact geometric run-coordinate bounds `τ_i≤t<τ_{i+1}`, set its local fraction to `(t-τ_i)/(τ_{i+1}-τ_i)`; at a shared segment edge select the canonical physical source-entity point. Source-carrier, component, sheet, endpoint sign and hard-rail authority survive this translation. A run join is an owned physical point, not a merge inferred from floating-world proximity.
3. To make reversal well-defined, **reject** a multi-run path containing a positive-length run with `F_r=0`: integer-flooring has erased its metric and cannot distinguish its two physical endpoints. This is a typed fail-closed placement condition, not a zero-weight run to traverse, omit or divide by. When an admissible one-run path has `F=0`, its physical length parameter `t=j/n` remains defined. For `F>0` and all `F_r>0`, the half-open convention is unambiguous and exact run joints resolve to one physical source entity. Zero-length segments, nonmonotone projections, disconnected carriers and inconsistent source charts are already invalid input, not placement shortcuts.
4. **Single-piece preservation:** explicitly keep the existing unreduced `(j,n)` numerator/denominator and the same original piece index for all `0≤j≤n`; this includes varying positive source target size on the single piece, and avoids gratuitous width/digest rebaselines. A one-run multi-piece path uses `j/n` as run length *only if* `F=0`; if `F>0`, the run formula algebraically reduces to `j/n` regardless of its representational partition. Reversal must map ordinal `j` to `n-j` at the same exact physical point; a reversal-induced representation difference is canonicalized by source entity, not silently accepted as different geometry.
5. **Location ownership:** retain the shared/framed `ConformityScheduleEntry` shape and `GlobalConformityPlan.cpp:49` unchanged. Store canonical run boundaries, positive metrics, prefixes and segment source carrier breakpoints in a baseline-only per-span profile, derived from the existing source authority and bound immutably to the authoritative baseline. Preserve or extend the baseline-specific breakpoint-location representation with an exact rational local fraction plus its authoritative source entity; do not add a lossy float offset or change framed CP1/CP2 validators. The independent baseline validator must recompute the run profile from source/target/chart authority and compare both exact rational points and typed provenance; trusting the producer profile as the sole oracle is invalid.

#### Compact exact width receipts

`observe_compact_breakpoint_widths` and its independent validator counterpart must use the **same new exact representable location domain**, not the obsolete piece-index surrogate. Count both endpoint identities, local rational numerator/denominator bit widths, and the source-entity/index fields the receipt actually commits to. Preserve unreduced `(j,n)` for single-piece spans, including their historical receipt widths. For multi-piece spans, define a deterministic canonical rational encoding (reduced or explicitly unreduced, chosen once and enforced in both serializers); compute receipt maxima compactly, never enumerate `n` ordinals or allocate proportional to `n`. On each monotone run/segment interval, derive integer ordinal bounds by exact rational ceiling/floor; the affine local numerator achieves its magnitude extremes at those bounds. If reduced-form widths cannot be established using this bound, use a provably conservative declared upper bound or a bounded exact algorithm—not an unproved first/last-ordinal heuristic. The validator independently derives the receipt and rejects a mutated profile, wrong source carrier, wrong segment, wrong rational denominator, missing extrema or overlong width. Adjust `GlobalConformityBaselineValidator.cpp:845–875` endpoint/denominator checks so `denominator==n` is enforced only for the preserved single-piece contract; multi-piece rational denominators may differ. All arithmetic and counts are checked; overflow, uncertifiable width or unsupported encoding fails closed.

#### Frozen CB108 scope (no work in this Review)

- Reuse the existing D7 run constructor and integer metrics at the shared source of truth; expose immutable per-span run profiles without rederiving an inconsistent second metric in the placement function.
- Replace only the *baseline* breakpoint-position derivation and corresponding source-entity canonicalization. No global integer parameterization, no D5 chain aggregation, no D4 consumer wiring, no source-grid recovery, no framed CP1/CP2 changes.
- Update compact width producer and independent validator; ensure memory/time complexity depends on profile size, not scheduled count. Maintain deterministic digests, strict failure classifications and source-sheet safety.
- Add meaningful guard coverage for positive and malformed profiles and numerical boundaries; a test must fail on a reintroduction of piece-index placement. Compile/package exact source through mandatory GMP/GMPXX GitHub Actions; **do not execute tests or benchmarks in CB108**. Separate immutable TB91 executes the registered gates, checks hashes and execution boundary, compares stored digests and classifies any rebaseline before promotion.

#### Required independent falsifiers for CB108/TB91

| Case | Expected discriminator |
|---|---|
| Straight length 4 split into 0.1 and 3.9, scheduled n=4, uniform positive density | Exact x=1,2,3; old piece-index positions 0.05,0.1,2.05 are rejected |
| Multiple source-chart subdivisions of one straight physical run | Same `F`, scheduled count, exact physical points, canonical identities and receipt independent of subdivisions and source-face row order |
| Two noncollinear positive-weight runs, unequal densities | Across-run allocation by integer `F_r`; within each run linear physical distance; distinguish from global Euclidean length and sum of square-root metric |
| Reversed physical route and ordinal `n-j` | Identical physical source-attached point and reciprocal path orientation at both interiors and joins |
| Exact join/segment endpoint and close distinct sheets | One canonical same-sheet source entity; reject foreign chart/sheet alias and interval ownership mismatch |
| Single representational piece, including nonuniform reciprocal target density | Exact legacy `(j,n)` fields and same compact receipt; endpoints unchanged |
| One-run zero `F` versus multi-run zero `F_r` | One-run length fallback is exact; multi-run quantization ambiguity fails closed without division by zero |
| Huge scheduled count and target field extremes | Compact receipt without `O(n)` work, checked big-int arithmetic, positive/negative mutation rejection |
| Mutated produced profile, incorrect prefix/denominator/endpoint/source carrier | Independent validator RED; unchanged semantic source rejected when tampered |
| TB91 complete immutable gate and census | Preserve 914 accepted TB90 rows + scoped new GUARD rows, 81 deferred unless separately reviewed, all source hashes/manifest assertions, no build/relink; compare all 7 platform and A3 records under explicitly pre-registered changed/unchanged rules; expected existing Bunny/Vase RED remains registered |

#### Review disposition and boundaries

The *definition* is complete only when its source-backed contract is durably published; implementation, tests, throughput, direct A3 consumer success and CP3 closure are **not** claimed. Remain at accepted CP2 **491/491**, stable **66 events / 17 categories / 49 recurrences**, debt **1**, 81 deferred, selector497 unpromoted. Preserve existing D5 (64B), D4 (64C/64D), D9c/A2b/A4/D8 and D6 user decision as separate turns. A narrow source-arithmetic implementation impossibility, unexpected representation collision, or failure to prove exact reversal must route back to a runtime-free independent Review rather than weakening the oracle or substituting tolerance. No new stable regression is evidenced by a runtime-free definition.

## `Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md`; moved verbatim.

### RA-216 — Step 64 (D7) re-entered: an implementable exact count, placement split out, exact CB106 and CB107

**Turn:** `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC`, re-entered · 2026-11-08 · Claude Review, runtime-free (`REVIEW_TURN_POLICY.md` §4.3). Nothing was built or run. The two patches were checked with `-fsyntax-only` only, and every expected count was recomputed by hand in exact fractions. Product source = CB105 `d96df38e5…`, unchanged at HEAD.

Reviewed: the [D7 decision](#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_review_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Review_20261108.md") and its DESIGN §7.4 amendment.

#### 1. Verdict

The diagnosis is right, and so is the density model. The decision then freezes a count rule and a breakpoint rule that the exact kernel cannot decide. It bundles a production-affecting change with a production-inert one, and it hands CB106 a design job instead of a patch. CB106's stop rule would therefore have been its likely exit.

RA-216 makes four changes:
- it replaces the unimplementable parts with exact integer rules;
- it splits D7 into a count (now) and placement (D7b, before D5);
- it freezes exact CB106 and CB107, with TB89 and TB90;
- it corrects DESIGN §7.4.

#### 2. What stands

- **Root cause.** `GlobalConformityBaselineSupport.cpp:192-239` computes `round(√(m·Σλ²))`. `GlobalConformityBaseline.cpp:739-767` places ordinal j in piece `⌊m·j/n⌋`, and `GlobalConformityBaselineValidator.cpp:845-875` mirrors that.
  - With λ=(0.1, 3.9) the count is 6 against 4.
  - At count 4, the interior ordinals land at x = 0.05, 0.1 and 2.05 instead of 1, 2 and 3.
- **Density model.** ρ = interpolated 1/h is the right choice. Because ρ is affine on each simplex, the trapezoid rule `L·(ρ₀+ρ₁)/2` is exact and additive under collinear subdivision. The alternative, 1/(interpolated h), integrates to a logarithm.
- **Other rules that stand:** canonicalizing contiguous collinear pieces while keeping genuine vertices; halves round down; the minimum count is one; positivity, parity, the T-join, lex-prefix refinement and the single writer are unchanged; D5, D4 and D8 stay separate.

#### 3. Findings

- **F1 (high): the count rule cannot be decided as frozen.**
  - A bent path's metric is `Σ_k r_k·√q_k`, and rounding it exactly is the sum-of-square-roots decision.
  - The rational kernel decides one root. The legacy code takes a single root of a squared energy for exactly that reason.
  - The only multi-radical machinery, `vertex_star_algebraic_sign_at_precision` (`SurfaceCellTracing.cpp:944`), enumerates 2^k monomials of its radical basis. A face-crossing trace with k bends would need 2^k.
  - The decision's stop rule ("stop if exact algebraic comparison cannot be implemented within existing limits") was therefore CB106's predictable exit: a DEFN with no reachable success exit (RA-172).
  - **Correction:** each maximal same-direction run has a rational squared metric `S²/|u|²`. Each run contributes ⌊2⁶⁴·metric⌋ by integer square root (`FieldExactRational::sqrt_bounds` already provides this), and the count rounds the sum once, halves down.
    - This is an exact integer function. It is deterministic and invariant to collinear re-splits, reversal and face rows.
    - It lies at most `runs·2⁻⁶⁴` below the exact integral, and always below it, which is consistent with rounding halves down.
  - "Do not approximate, quantize" is withdrawn. DESIGN §7.4 makes target size an *objective with permitted deviation*. A defined exact integer function is neither floating optimization nor tolerance matching.
- **F2 (high): exact metric-inverse breakpoints conflict with the architecture.**
  - Within a straight segment ρ is affine, so the cumulative metric is quadratic, and its inverse is a square root nested over a total that is itself a sum of roots.
  - DESIGN §7.4 requires "a canonical ordered breakpoint sequence in exact source-rail coordinates". Every downstream identity is rational: `boundary_trace_point` takes a `FieldExactRational` edge parameter, and both `exactEdgePoint` and the `SurfaceSharedBoundaryInterval` ordinals are rational.
  - Item 5 handed CB106 an unreviewed representation replacement (a "certified algebraic/implicit witness").
  - **Correction (D7b, §8):** across runs, place ordinals by metric. Within a run, place them linearly in length. The existing (piece, local rational) representation then encodes every location exactly, and for a single-run span the location is today's j/n.
- **F3 (high): a production-affecting change was bundled with an inert one.**
  - The only caller of `breakpoint_location` is curved-disk (`SurfaceCellTracing.cpp:17641`). It accepts only Mandatory arcs with `sourcePath.size()==1` on one source edge (`:17448-17473`), and it rejects `supportPieceIndex != 0`.
  - Counts reach production through parity on every span. Multi-piece placement reaches no output until a multi-piece consumer exists (D5 chains or 65C traces).
  - **Correction:** the count lands now (CB106 → CB107), and placement (D7b) lands before 64B.
- **F4 (medium): three frozen copies were left out of scope.**
  - The same count formula also sits in `GlobalConformityPlan.cpp:36`, `GlobalConformityValidator.cpp:188` and `GlobalConformityCP2Validator.cpp:42`, and piece-index placement sits in `GlobalConformityPlan.cpp:49`. These are framed CP1/CP2 evidence.
  - Production calls only `build_global_conformity_baseline` (`RemeshPipeline.cpp:13018`).
  - D7 changes the baseline only. Changing the framed copies would perturb the accepted CP2 491/491 evidence.
- **F5 (medium): the single-piece effect was not stated, and the digest outcome was left open.**
  - Production target sizes are adaptive per vertex (`RemeshPipeline.cpp:12598-12612`).
  - On one piece the metric moves from `L·2/(h₀+h₁)` to `L·(1/h₀+1/h₁)/2`, which is never smaller (AM–HM). Counts therefore change wherever h varies, even on single-edge spans; with uniform h the two agree.
  - The pipeline's `global-conformity-baseline` debug product hash can therefore change. Because the `tracing` hash embeds `receipt.baselinePlanDigest` (`RemeshPipeline.cpp:2095`), the change carries into later product hashes too.
  - "Preserve pinned digests unless independently justified by the later TB" is not an outcome table. TB89 and TB90 below are.
- **F6 (medium): CB106 was monolithic and not exact.** It bundled the metric, a new breakpoint representation, a validator rewrite and "prescribed focused tests", with no patch. That is the RA-215 F2 defect again.
- **F7 (low): `breakpoint_location` sees no geometry.**
  - `GlobalConformityBaselinePlan::breakpoint_location(span, j)` reads only the schedule entry, so it cannot compute a metric placement.
  - `ConformityScheduleEntry` is shared with the framed plan (`GlobalConformityPlan.h:67`), so widening it would touch frozen types.
  - Owner: the D7b DEFN.
- **F8 (low): two falsifiers were unbound.**
  - "A genuine kink is not equivalent" cannot be tested on a count, because a bent path and a straight path of equal metric rightly share one. It is bound as follows: a direction change starts a new run, so counts add across runs, and a fold-back is not a cancellation. In D7b, a bend vertex bounds a run for placement.
  - "The validator derives independently" is already true: the baseline validator recomputes counts from the input through the shared function (`GlobalConformityBaselineValidator.cpp:360`). The independent oracle is the hand-computed tests. No second implementation is needed.

#### 4. Corrected D7 contract (replaces decision items 3–5; DESIGN §7.4 amended)

1. **Runs.** A run is a maximal sequence of consecutive valid support pieces along one direction `u`: same direction means `(d·u)² = |d|²|u|²` and `d·u > 0`. A direction change, including a reversal, starts a new run. Continuity, carrier membership, distinct endpoints and positive finite h are checked exactly as today; any failure gives `DegenerateConformityPath`.
2. **Run metric.** `S = Σ (d·u)(ρ(a)+ρ(b))/2`, where ρ is the barycentric interpolation of exact vertex reciprocals. The run's metric is `S/|u|`, and its square `S²/|u|²` is rational.
3. **Count.** `F = Σ_runs ⌊2⁶⁴·√(S²/|u|²)⌋` by integer square root, and `n_preferred = max(1, ⌊F/2⁶⁴⌋ + [2·(F mod 2⁶⁴) > 2⁶⁴])`. The count is an objective; the existing exact scheduling decides final counts.
4. **Placement (D7b, §8).** Ordinals are spaced by metric across runs and linearly in length within a run, as exact rational source points in the existing representation.
5. **Scope.** The production baseline only.

#### 5. Exact CB106 — the D7 count, not yet wired, plus its falsifiers

[Diff](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB106_P13_A3_Partition_Stable_Count_Exact.diff"):
- SHA-256 `2ee8401442bed8e1df7f5f92de199acc18477df3e7e10ed36e56b4d715afb777`, 382 lines; keep its 7 single-space context lines.
- Numstat `86 0` `GlobalConformityBaselineSupport.cpp`, `7 0` `.h`, `238 0` `GlobalConformityBaselineTests.cpp`. It applies cleanly to HEAD.
- `-fsyntax-only` passes for both `.cpp` files. That is a syntax check, not a build.

It adds `derive_partition_stable_preferred_count_exact` (§4.1–4.3) and the helper `exact_reciprocal_target`. The scheduler still uses `derive_preferred_count_exact`, so production output is unchanged.

Three GUARD tests, each value hand-computed:

| Test | Binds | Discriminates |
|---|---|---|
| `D7PreferredCountIsInvariantToSupportSplitsAndReversal` | A length-4 edge as 1, 2, 2, 4 and 7 pieces, each also reversed, gives 4; an irrational face-interior run, whole, cut or reversed, gives 11 | Legacy gives 6 for λ=(0.1, 3.9), 5 for (0.5, 3.5), and 13 for the uneven face cut |
| `D7PreferredCountIntegratesInterpolatedReciprocalTargetAdditively` | With ρ from 1 to 2 over length 4, the count is 6 for cuts {}, {½}, {⅓} and {⅛, ⅝}, and reversed | Legacy midpoint-h gives 5 whole and 6 halved |
| `D7PreferredCountRoundsOnceKeepsDirectionChangesAndFailsClosed` | Metric 4.5 gives 4, whole or cut; 4.5+2⁻³⁹ gives 5; 0.25 gives 1; a 1+4 bend gives 5; the fold-back 0→3→1 gives 5; six malformed spans give no count | Legacy gives 6 on the bend; a sign-blind run merge would give 1 on the fold-back |

Without the product half the tests do not compile. With a wrong metric they fail on the listed values.

Routes:
- mismatch → `M6-CP3-PLAN-P13-A3-PARTITION-STABLE-METRIC-STOP`;
- infrastructure → `M6-CP3-CB106A-P13-A3-PARTITION-STABLE-METRIC-ORCH`.

#### 6. TB89 — CB106 full gate

- [Manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB89_P13_A3_Partition_Stable_Count_Full_Gate_Case_Manifest.tsv"): 913 rows, `8a4a6fef2a8b8b6e3c81ef1aa11de8f71dab883ee2d1d43b653f0ab129811ef8`. It is TB87/TB88's 910 rows plus GUARD 911–913. `SELF_CHECK_PASS cases=913 deferred=81`; membership 994; ledger v5 `fd433f54…`; census `3af1dc0d…`.
- **Expected:** 913/913. All 7 `platform-digest` and all 7 `a3-coverage` lines are byte-identical to TB88, because the new function has no production caller.
- Routes: mismatch → `M6-CP3-TB89-P13-A3-PARTITION-STABLE-METRIC-FULL-GATE-REV` (Review, runtime-free); infrastructure → `M6-CP3-TB89A-P13-A3-PARTITION-STABLE-METRIC-ORCH`.

#### 7. Exact CB107 — make the D7 count the scheduler's objective — and TB90

[Diff](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB107_P13_A3_Partition_Stable_Count_Switch_Exact.diff"):
- SHA-256 `c1caefb973f8157823018dbd6fcb2d4ff2f47bcf79f41d3ef77d0b216ab9aa5f`, 217 lines; keep its 10 single-space context lines.
- Numstat `2 56` / `1 1` / `52 22`. It applies **only on top of CB106**. Precondition: TB89 MATCH.
- `-fsyntax-only` passes.

The change:
- `derive_preferred_count_exact` delegates to the D7 count, so the producer and the validator both use it.
- The legacy body and its orphaned `exact_target` are removed.
- The CB106 assertions on the former formula now expect D7 values (6→4, 5→4, 13→11, 5→6, 6→5).
- New GUARD 914, `D7PreferredCountIsTheSchedulerObjectiveForEverySplit`: a built and validated plan prefers 4 for one unit edge at h=¼, whole, cut at ⅛ (formerly 5) and halved. All three schedule identical counts.

Routes:
- mismatch → `M6-CP3-PLAN-P13-A3-PARTITION-STABLE-COUNT-SWITCH-STOP`;
- infrastructure → `M6-CP3-CB107A-P13-A3-PARTITION-STABLE-COUNT-SWITCH-ORCH`.

**TB90** `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-EXEC`:
- [Manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB90_P13_A3_Partition_Stable_Count_Switch_Full_Gate_Case_Manifest.tsv"): 914 rows, `45dfbb533ed3668f48a0146a3ce6800f57a2221368380c31c8e60a7974c64607`. `SELF_CHECK_PASS cases=914 deferred=81`; membership 995.
- Expected outcomes:
  - 914/914;
  - all 7 `a3-coverage` lines byte-identical to TB88;
  - census verdicts unchanged: Cylinder PASS, BunnyRandom RED `SingularityPortClassCountMismatch`, Vase RED `AggregateCompletionValidationFailure`.
- `platform-digest`, per line:
  - every token through `global-topology-plan=` is byte-identical;
  - the `/count` suffix of `global-conformity-baseline` is identical;
  - if its hash is unchanged, the whole line is byte-identical;
  - if its hash changed, later product hashes may change (the tracing hash embeds the baseline digest). For the four gate cases and census Cylinder, which uniform or annulus produce (`covered=0`), every later `/count` and `validationIssues` must stay identical. Vase's later tokens are recorded.
- Record every changed baseline hash as the registered D7 rebaseline.
- Routes: mismatch → `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-REV`; infrastructure → `M6-CP3-TB90A-P13-A3-PARTITION-STABLE-COUNT-SWITCH-ORCH`.

#### 8. D7b placement — semantics for step 64.5

The step-64.5 DEFN `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT` freezes exact CB108 and TB91.

**Placement rule.** Use the runs and run values `F_r` of §4, the total `F`, and prefix sums `C_r`.
- Ordinals 0 and n stay at the endpoints.
- For 0<j<n:
  - let `T = j·F/n`, and take the run with `C_r ≤ T < C_r+F_r`;
  - set `t = (T−C_r)/F_r`; the point is `a_r + t·(b_r−a_r)`;
  - its piece is the one with `τ_i ≤ t < τ_{i+1}`, where `τ_i = ((a_i−a_r)·u)/((b_r−a_r)·u)`;
  - its local fraction is `(t−τ_i)/(τ_{i+1}−τ_i)`.
- For a single-piece span this is j/n, so curved-disk output is unchanged.

**Questions the DEFN must decide:**
- where the run profile lives. The recommendation is a baseline-only per-span profile that the validator recomputes. Do not widen the shared `ConformityScheduleEntry`.
- whether the single-piece local fraction keeps today's unreduced `(j, n)`, which leaves the width receipts unchanged.
- the matching changes to `observe_compact_breakpoint_widths`, to its validator twin, and to the endpoint and denominator checks at `GlobalConformityBaselineValidator.cpp:845-875`.
- `GlobalConformityPlan.cpp:49` stays frozen.

**Falsifiers:**
- the λ=(0.1, 3.9) edge at count 4 puts its breakpoints at x = 1, 2, 3 (legacy: 0.05, 0.1, 2.05);
- two runs of different density are spaced by metric, and a single run by length (a documented deviation);
- a reversed span maps j→n−j to the same point;
- a collinear re-split gives identical points;
- the single-piece spans that curved-disk consumes are unchanged.

#### 9. Sequence

| Step | Turn | Owner | Depends on |
|---|---|---|---|
| 64 | this Review (RA-216) | Claude, runtime-free | COMPLETE |
| **64.1** | **`M6-CP3-CB106-P13-A3-PARTITION-STABLE-METRIC`** | implementation agent, compile only | §5 |
| 64.2 | `M6-CP3-TB89-P13-A3-PARTITION-STABLE-METRIC-FULL-GATE-EXEC` | implementation agent | CB106 |
| 64.3 | `M6-CP3-CB107-P13-A3-PARTITION-STABLE-COUNT-SWITCH` | implementation agent, compile only | TB89 MATCH |
| 64.4 | `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-EXEC` | implementation agent | CB107 |
| 64.5 | `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT` (D7b) → CB108 → TB91 | Review, runtime-free | TB90 |
| 64B | `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING` (D5); its consumer must accept multi-piece spans | Review | D7b |
| 64C / 64D | uniform / annulus A3 consumption (D4) | Review | 64B |
| 65A–65D | D9c carrier binding, reciprocal trace, A4 disc domain, D8 receipt | Review each | in order |
| 66+ | per-disc corners (D6, user), fill, dispatch | DEFN → CB → TB each | 65D |

#### 10. Corrections to the D7 decision

- Items 3 and 5: the exact sum-of-roots rounding and the algebraic inverse are superseded by §4.
- The successor paragraph is superseded by §5–§7, and the stop rule is withdrawn.
- The falsifier rows "genuine kink" and "independent verifier" are rebound by F8. The "two sides share one span" row moves to D7b and D5.
- The decision's closeout claimed handoff currency. Its `load_next` still named TB88; it is corrected here.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change |
| Decisive claims re-derived | Read the count, placement, validator, consumer and framed-copy sites; computed every expected test value in exact fractions (legacy and D7) |
| Non-vacuity | Each test asserts a legacy value that differs from D7; CB107 turns those into D7 values plus a wiring test that fails on CB106 |
| Obligations carried | D7b → 64.5; D5 64B; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB88 910/910, membership 991; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 | Updated |
| Turn boundary | No product or test source changed in the repository; syntax checks only |

## `Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Review_20261108.md`; moved verbatim.

### D7 — Partition-stable A3 preferred metric and exact breakpoint contract

> **Partly superseded by [RA-216](#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_adversarial_review_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md") (2026-11-08).** The diagnosis and density model stand. Items 3 and 5 (exact rounding of a sum of square roots, algebraic inverse breakpoints) and the CB106 successor paragraph and stop rule are replaced by RA-216 §4–§8: run-wise exact integer count, placement as D7b, exact CB106 and CB107.

**Turn:** `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` · 2026-11-08 · independent source Review/definition; no product implementation, test execution, build, or accepted-prefix promotion.

#### Authority and scope

TB88's immutable 910/910 MATCH (membership 991) establishes its specific observed-route oracle, **not** A3 producer consumption or correctness of a re-partitioned A3 metric. Accepted CP2 remains 491/491, stable regression accounting 66/17/49, debt 1, deferred ledger v5 81, selector497/CP3 unpromoted. This decision defines D7 only. D5 maximal-chain construction, D4 uniform/annulus consumers, D9c source-rim binding, D8 receipt and A4 construction are later independent work.

#### Independent source finding

`src/geometry/GlobalConformityBaselineSupport.cpp:192–239` accumulates per-piece `squaredLength / midpointTarget²`, multiplies by the number of `supportPieces`, and rounds the square root (ties toward the smaller integer). Thus a uniform-size geometric route with normalized piece lengths (0.1, 3.9) yields `round(sqrt(2*(0.01+15.21)))=6`, whereas the same unsplit route yields 4. Subdivision is not geometric progress. Independently, `src/geometry/GlobalConformityBaseline.cpp:739–767` maps ordinal j to piece index using `m*j/count`: it assigns equal ordinal capacity to unequal-length pieces. The validator at `GlobalConformityBaselineValidator.cpp:845–875` mirrors that broken piece-index contract. Exact source-chart binding and positive counts remain valuable but do not fix either defect. These are confirmed source defects, not newly executed runtime regressions.

#### Frozen D7 semantic contract (DESIGN §7.4)

1. **Authoritative geometric domain.** Each A3 `ConformitySpan` owns a consistently oriented, source-attached physical polyline with typed source component/sheet and its original source-entity carrier. `supportPieces` are only a representation partition of that path. A real bend, surface discontinuity, barrier, changed carrier or changed source sheet is not a representational split and must not be silently merged. Canonicalize admissible contiguous collinear splits and source-chart transitions, preserve every genuine physical vertex, and reject disconnected, zero-length, or ambiguous support fail closed.
2. **Physical-size density.** For a positive finite source target size h at each source vertex, define `rho_v = 1/h_v` exactly from the published target-size bits. On each source triangle interpolate `rho(p)` with its exact barycentric weights. This is a continuous piecewise-affine scalar over shared, consistent source edges, rather than taking `1/(interpolated h)` or taking midpoint h per arbitrary piece. A source-polyline segment must be split at actual triangle/physical-kink transitions before evaluation; any additional representational split must not affect the result.
3. **Additive metric.** Define the nonnegative integrated metric length `M(P) = integral_P rho(p) ds`. On one straight segment `(a,b)` inside an affine source chart, `M(a,b) = ||b-a|| * (rho(a)+rho(b))/2` (orientation invariant, additive under collinear subdivision). Sum across canonical source-supported segments with exact decisions: rational source coordinates and density with square-root/algebraic length as needed. Do not approximate, quantize, sample by piece index, or replace total length with a root-mean-square weighted by piece count. A mere representational re-split must produce the **identical** metric value.
4. **Preferred integer count.** Let `n_preferred = max(1, nearest_integer(M(P)))`, using the established tie-to-lower convention at exact half integers. This is an *objective* only; the existing positivity, parity, T-join and canonical lex-prefix optimization retain final scheduling authority. Counts must be the same for identical physical paths regardless of the number or ordering of representational support pieces.
5. **Exact physical breakpoints.** For the final scheduled count `n >= 1`, ordinal `j = 0..n` denotes the unique path point with cumulative metric length `j*M(P)/n` from the span's **oriented** start. `j=0,n` are exact physical endpoints. For interior ordinals, select the first canonical geometric segment reaching the measure, invert its strictly monotone integral, and return an exact/certified source-attached point. At an exact segment join, canonicalize by physical source entity rather than choosing an arbitrary preceding/following piece index. Reversal must map ordinal `j` to `n-j` at identical positions. The current rational `ConformityBreakpointLocation` (piece index plus local rational) cannot in general encode this inversion exactly; the CB must extend or replace that representation with a certified algebraic/implicit witness, or prove a logically equivalent exact implementation. An inexact approximation is **not** valid equivalence.
6. **Validation and identity.** The verifier must derive the cumulative measure and breakpoint membership independently of the producer, including the intermediate-ordinal source support, monotonic order, exact tiling, shared identical breakpoint identity, and endpoint ownership. Representation-only re-partitioning must not alter semantic hashes, scheduled count, canonical physical breakpoint identities or A3-supplied downstream authority. Physical path changes may change results. Reject any undecidable/exceeded exact bound with a typed failure; never claim synthetic success.
7. **Boundaries.** Keep all existing A3 single-writer and global parity/positive/T-join obligations. Do not introduce D5 chain grouping, D4 consumption, A4 fill, a new source-grid fallback, selector changes, or runtime execution in this definition.

#### Scoped successor and falsifier matrix

**Exactly one authorized successor:** `M6-CP3-CB106-P13-A3-PARTITION-STABLE-METRIC` — implement only the D7 metric, exact breakpoint carrier, independent validator/oracles, and prescribed focused tests; compile/package only under the existing GMP/GMPXX workflow. A separate, not-yet-authorized Test + Benchmark turn must consume the immutable binary before any D7 acceptance. If exact algebraic comparison/representation cannot be implemented within existing exact-arithmetic limits without an unreviewed architectural change, **stop** and return to a Review; do not substitute floating/epsilon or coordinate rounding.

| Falsifier / oracle | Required discriminating outcome |
|---|---|
| Same straight route represented as 1, 2, 4 or 7 pieces | Identical exact M, preferred n, final n and canonical breakpoint source identities |
| Unit-target route λ=(0.1,3.9) and its single-piece representation | Preferred 4 in both; mutant old RMS-with-m formula yields 6 and must be rejected |
| Count 4 on short+long pieces | All three interior breakpoints at physical metric positions 1, 2, 3; mutant piece-index spacing detected |
| Varying per-vertex target on an affine source edge; re-split at arbitrary points | Exact integrated rho invariant; midpoint-h or nonadditive `1/interpolated-h` approximations rejected |
| Source-face crossing, different valid triangle row/order and carrier subdivisions | Same metric/canonical physical breakpoints, subject to fixed geometric path and sheet |
| Reversed oriented route and reversed piece order | Identical undirected breakpoint set; ordinal j maps to n-j; correct recorded orientation |
| Genuine kink, different physical route, barrier or source sheet | Not treated as equivalent; cross-sheet points never merged |
| Exact half-integer metric, very short positive span, invalid/nonpositive h, zero-length fragment | Tie down, positive min-one; malformed input typed fail-closed without injecting new interval |
| Two sides sharing one A3 span, odd/even parity-repaired schedules | Identical final scheduled IDs, count and breakpoints; T-join and lex-prefix never bypassed |
| Independent verifier mutant controls | Perturb one exact interior point, ordinal, carrier, density and measure independently; verifier fails for intended reason and is reached |

**Witness priority:** small synthetic exact rational-coordinate straight rail (both uniform and varying rho) first; then multi-face seam / close sheets; only then wider producer gates in a separate TB. Preserve existing frozen selector identities and scope/pinned digests unless independently justified by the later TB.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a for semantic rebaseline: selector not altered; historical accepted CP2 491/491 and current TB88 910/910 membership 991 are retained, not independently rerun in this Review. |
| Decisive claims independently re-derived | Read exact code: m-weighted squared metric, exact tie rule and `m*j/count`; computed (0.1,3.9) case 6 versus 4; identified validator's corresponding broken oracle. |
| Non-vacuity checked | Old formula differs on a concrete two-piece witness and old index breakpoint differs on the same input; independent negative mutation cases frozen for the next CB/TB. No tests executed here. |
| Prior obligations discharged/carried | D7 definition specified, runtime remediation pending CB106/TB; D5 to 64B; D4 uniform/annulus to 64C/64D; D9c 65A; trace 65B; A4 disc 65C; receipt D8 65D; D6 user approval pending; P13-e and other M6 debts carried. |
| Stable accounting | No accepted-green loss or promotion; CP2 491/491, 66/17/49, debt 1, ledger v5 81; selector497/CP3 unpromoted. |
| New candidates/obligations recorded | Existing D7 root cause narrowed to additive physical metric, exact inverse and independent verifier; no new stable defect. |
| ORIENTATION currency line | D7 review-current wording prepared in same patch. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a because no witness changed runtime state; §8 adds existing piece-index representation pattern instance, no new stable category. |
| CHANGELOG | D7 runtime-free Review entry prepared in same patch. |
| ROADMAP | n/a: M6-CP3 remains active, no milestone promotion. |
| Selector manifest | n/a: no selector/source contract rebaseline. |
| LESSONS | Existing representation-not-breakpoint and producer/validator-oracle rules applied, no new lesson number. |
| Consolidation under CLEAN_UP_POLICY | No historical evidence deleted; one review decision and in-place durable current-state changes only. |
| Successor frozen | CB106 only, D7 metric and exact breakpoint implementation; falsifiers and stop rule above. |
| Turn boundary held | Static source inspection only; no generated Directional runtime/build/test, no implementation/test/selector mutation. |
| review_check.py boundary | PASS on full authentic Git history, with durable-section and selector checks; append-only ledger scan PASS. Independent [run 42506579219](https://github.com/akashskypatel/Directional/actions/runs/42506579219), `D7_REVIEW_GATE_PASSED`. |
| `STATUS` lifecycle maintained | Initial in-progress beacon committed; final beacon follows actual durable publication status. |
| Pushed to origin, branch in sync | Drive apply commit `aa55054543e8a5d1b309cc9d46f0ff543117b05c` confirmed by remote PR HEAD/readback and authentic-history workflow; runner reported clean detached HEAD. A tracking-branch `git status -sb` was not available in ChatGPT Web, so no such claim is made. |

## `Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Adversarial_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Adversarial_Review_20261108.md`; moved verbatim.

### RA-215 — Step 61 (D9 recorded boundary intervals) re-entered: exact CB104, falsifiers re-bound, D4 owned

**Turn:** `M6-CP3-DEFN-P13-A3-RECORDED-BOUNDARY-INTERVALS` (adversarial re-entry of the [step-61 decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Review_20261108.md")). Runtime-free (`REVIEW_TURN_POLICY.md` §4.3). Product and test sources are CB103 `000752d8…`, unchanged at HEAD. I read the TB86 gate-result artifact `13613643740` as evidence, in an isolated scratch directory; nothing was built or run. Patch authoring used `-fsyntax-only`, which produced no object file and is not evidence.

#### 1. Verdict

The core contract of the step-61 decision stands. The producer and factory change is correct, and the consumer census is accurate. But the decision does not deliver a CB104 the implementation agent can execute:

- It rejects, on a false premise, the one existing fixture that witnesses the change.
- It then hands test design to CB104, with a "stop if no fixture exists" clause.
- Three of its TB87 falsifiers name outcomes that no predicate produces, or that no rim fixture can construct.
- Its digest expectations amount to rebaselining after the fact.

RA-215 freezes an exact CB104 (core plus test) and an exact TB87. It also gives the open D4 gap (uniform and annulus producers ignore A3) an owner.

#### 2. What stands

- **Producer** (`SurfaceCellTracing.cpp:17628`, `:18186`). Curved-disk already subdivides every rim edge by A3 ordinals. Recording `hardFeature || sourceBoundary` and requiring presence on `HardRail || GenuineSourceBoundary` is consistent:
  - `edgeAuthority.sourceBoundary` (`:16877`) and the `GenuineSourceBoundary` classification (`:13124-13126`) use the same full incidence map (`:15540`).
  - An interior non-hard edge never reaches the check: it is rejected at `:13148`.
- **Factory** (`:9386`). It admits a present interval on a `GenuineSourceBoundary` edge only when the edge is exterior and has no twin. An absent rim interval stays legal, because the receipt is minted for every producer (D8), and the uniform and annulus producers publish rims without intervals. The requirement that HardRail intervals be present is unchanged.
- **Consumers.** Every product reader is kind-gated or needs both sides:
  - `RemeshPipeline.cpp:4832` and `:5109`;
  - `SurfaceCellTracing.cpp:8252`, `:9464`, `:19064-19141` and `:19950`;
  - `RemeshPipeline.cpp:2285` hashes the interval, and `:9674` is the CB103 report.

  A single-sided rim interval is therefore inert everywhere except in the digest and the coverage report. Test readers are also safe:
  - `FieldAlignedCurveNetworkTests.cpp:17320` (any interval ⇒ PeriodicCut) runs on the closed torus, which has no `GenuineSourceBoundary` edges.
  - The quotient-test readers are kind- or span-gated.
  - GUARD 909's assertions are relative (`≥`, `−1`).
- **Upheld.** The withdrawn draft test was wrong to expect the generic factory to reject an absent rim interval.

#### 3. Findings

| # | Severity | Finding | Evidence | Disposition |
|---|---|---|---|---|
| F1 | high | **The witness was rejected on a false premise.** The decision says `build_rectangular_hard_rail_phase_front` "does not establish a curved-disk A3-consuming non-hard rim". It does. With an A3 plan, the uniform and annulus producers return NotApplicable for any region that touches a hard edge (`:13432-13435`, `:14243-14246`). Every region of that fixture touches the rail, so curved-disk produces all of them in cut-domain mode (`:15549-15553`). Their outer rims are physical, non-hard and A3-scheduled: every run edge needs a mandatory schedule, or the run is rejected (`:17421-17491`). The fixture is a single global run (`parallelizeComponents=false`, `RemeshPipeline.h:246`), and GUARD 909 already shows it is Produced. | static | Test frozen on this fixture (§4) |
| F2 | high | **CB104 was not exact.** The implementation agent was asked to author "the smallest non-vacuous" test and to stop if no fixture could be found. That is test design inside a compile-only turn: it breaks the exact-patch rule, and its success could not be checked before TB87. | step-61 §"Required CB104 test repair" | Replaced by an exact patch (§4) |
| F3 | medium | **Claimed validation does not exist.** The decision says the factory validates "source attachment" of present rim intervals. Nothing checks it: the factory holds only the receipt digests, never the A3 plan. TB87 falsifier 2 ("corrupt … source attachment", "foreign span") therefore names no rejecting predicate. | `:9383-9425`; receipt `SurfaceCellTracing.h:1505` | Attachment becomes a test oracle in CB104 (carrier = route step = physical edge). A foreign or cross-span tamper is visible only to the CB103 report. The factory-side gap is registered as **D9c**, owned by step 65 (reciprocal trace intervals need span-to-carrier authority) |
| F4 | medium | **One falsifier cannot be built.** Falsifier 3 asks for "same-source cross-region rim occurrences sharing a NetworkArcId". A physical edge has exactly one incident face, so one region and one A3 incidence. No rim can satisfy it. | `:16871-16877` | Moved to step 65 (trace seams) |
| F5 | medium | **Digest expectations were left open.** "Register any changed curved-disk digests as expected candidate differences" rebaselines after the fact. Statically, all seven pinned lines run on producers CB104 does not touch: the four gate cases record no interval at all (TB86 covered=0), so none runs curved-disk with a rail; Cylinder is annulus; BunnyRandom fails before A4; Vase has observed=0. | TB86 report | **Prediction:** all 7 `platform-digest` and 7 `a3-coverage` lines byte-identical to TB86; any change → REV |
| F6 | low | **Unlisted behaviour change.** A physical edge listed in `hardFeatureEdges` is now accepted. Before, it recorded an interval and was classified GSB, and the presence check rejected it. The pipeline derives hard edges from HardFeature-kind rails only (`RemeshPipeline.cpp:10023-10046`), so production is unlikely to reach this. | static | Intended (GSB precedes HardRail at `:13124`). TB87 guards against row flips |
| F7 | low | **Comment lost facts.** The core patch's header comment dropped "required for production HardRail pairing" and "periodicRelation remains the quotient owner". | core diff | Restored in the exact patch |
| F8 | trajectory | **D4 has no owner.** The uniform and annulus producers ignore A3 entirely (`:13410-13413`), yet they produce every observed gate case under a receipt. That is DESIGN §2.1 item 7 ("every region's construction consumed the certified global plan unmodified") failing on all produced fixtures. CB104 changes none of them. | TB86: 4/4 covered=0; RA-213 boundary counts (non-accepted) | New step **64A** DEFN, after D7 |

#### 4. CB104, frozen exact

[`Architecture_M6_CP3_CB104_P13_A3_Source_Rim_Intervals_Exact.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB104_P13_A3_Source_Rim_Intervals_Exact.diff"):

| Property | Value |
|---|---|
| SHA-256 | `dfacc5cbc535b16b8b387431a4078c3db3120acbee2ab7e2eac71b044364bb0c` |
| Size | 227 lines |
| Single-space context lines to keep | 2 |
| Numstat | `3 1` `SurfaceCellTracing.h` / `10 5` `SurfaceCellTracing.cpp` / `147 0` `SurfaceCellsPhase10Tests.cpp` |
| Base | product = CB103 `000752d8…` (HEAD) |
| `git apply --check` | clean |
| `-fsyntax-only` | 0 errors in both translation units; the only warnings are 5 pre-existing ones in `PCFaceTangentBundle.h` |

It contains the step-61 core unchanged except for the F7 comment. The superseded `…_Core.diff` (`916c591a…`) must not be applied on its own.

**New test** `SurfaceCellAuthorityContractCutover.A3SourceRimIntervalsAreRecordedSingleSidedAndValidated` (GUARD 910). It runs the rectangular hard-rail fixture in both face-row orders. For every `GenuineSourceBoundary` edge it checks:
- the edge is exterior, has no twin, and has an interval;
- the span's single support carrier is a physical edge (one incident face);
- the route has exactly one Boundary step on that carrier, with the interval's orientation.

Plan-side completeness, independent of the product:
- every A3 span on a physical edge is recorded;
- coverage shows `partial=0` and `foreign=0`;
- every rim span is covered.

Factory checks, forward order only:
- the unchanged product is re-accepted;
- a dropped rim interval is accepted by the factory, while coverage loses exactly one span;
- a stretched interval, an orientation against the ordinal sign, and an interior (`exterior=false`) rim are each rejected with `InvalidSharedBoundaryInterval` at that edge.

**Non-vacuity.**
- On the pre-change source, the first rim edge has no interval, so the test fails.
- With factory admission only, the same assertion fails.
- With producer recording but no factory admission, the fixture is not Produced.
- If the `exterior`/twin clause is omitted, the "interior rim" tamper is accepted, so the test fails.

**CB104 routes:** apply exactly, run the eight-target GMP compile, package, and run nothing.
- mismatch → `M6-CP3-PLAN-P13-A3-RECORDED-BOUNDARY-INTERVALS-STOP`;
- infrastructure → `M6-CP3-CB104A-P13-A3-RECORDED-BOUNDARY-INTERVALS-ORCH`.

#### 5. TB87, frozen

`M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-EXEC` runs on the CB104 package.

| Property | Value |
|---|---|
| Manifest | [`Architecture_M6_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Case_Manifest.tsv"): TB86's 909 rows plus GUARD 910 |
| SHA-256 | `c435519f6304fdcedb794e45187c8c4645e0bb36d32ec567e7979d292fb245bf` |
| Harness self-check | `SELF_CHECK_PASS cases=910 deferred=81` |
| Ledger | v5 `fd433f54…` |
| Membership | 991 |
| Census | unchanged, 3 rows `3af1dc0d…` |

**Expected results:**
- The gate is 910/910, and GUARD 909 and 910 both PASS.
- For rows 795, 796, 797 and 864, both the `platform-digest` and the `a3-coverage` lines are byte-identical to TB86: `observed=1 covered=0 partial=0 foreign=0`, scheduled 24/16/14/81.
- For the census, the Cylinder, BunnyRandom and Vase `platform-digest` and `a3-coverage` lines are byte-identical to TB86. The outcomes are Cylinder PASS, BunnyRandom P13-e RED, and Vase legacy RED.

**Routes:**
- mismatch → `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-REV` (Review, runtime-free);
- infrastructure → `M6-CP3-TB87A-P13-A3-RECORDED-BOUNDARY-INTERVALS-ORCH`.

No test repair happens inside the TB.

#### 6. Realigned sequence

| Step | Turn | Owner |
|---|---|---|
| 61 | this re-entry (RA-215) | Review, runtime-free — COMPLETE |
| **62** | **`M6-CP3-CB104-P13-A3-RECORDED-BOUNDARY-INTERVALS`** (exact §4) | implementation agent, compile only |
| 63 | `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64 | `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` (D7, then D5; DESIGN §7.4) | Review, runtime-free |
| 64A | `M6-CP3-DEFN-P13-A3-UNIFORM-ANNULUS-CONSUMPTION` (D4). The uniform and annulus producers must adopt A3 rim and cut breakpoints and record them, or else decline honestly under an A3 plan. After 64, because D7 changes counts. Independent of 65; required before CP3 promotion. | Review, runtime-free |
| 65 | `M6-CP3-DEFN-P13-A4-A2B-DISC-DOMAIN`: plan-trace edge kind with reciprocal intervals, D9c span-to-carrier authority, and the old falsifier 3 | Review, runtime-free |
| 66+ | per-disc boundary and corners (D6) → fill → dispatch | one DEFN → CB → TB each |

#### 7. Corrections to the step-61 decision

- Its §"Required CB104 test repair", its "Frozen CB104 scope", and its TB87 falsifiers 2–4 are superseded by §4 and §5.
- Its "source attachment" validation claim is withdrawn (F3).
- Its tracker sentence saying the rectangular fixture is not a natural-rim witness is withdrawn (F1).

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edited or accepted |
| Decisive claims independently re-derived | Producer dispatch, rim classification, factory order and every interval reader were read in source. The TB86 artifact confirmed GUARD 909 PASS; its RecordProperty values are not in the raw log, so the test pins relations, not counts |
| Non-vacuity checked | §4: pre-change, partial-implementation and missing-clause variants each fail the new test |
| Prior obligations discharged/carried | D9 rim → CB104/TB87; D9 seam and D9c → 65; D7/D5 → 64; D4 → 64A; D8 caveat stands; D6 user decision pending; P13-e, O30b, O31 (legacy), O32b–e, O33, O27–O29 carried |
| Stable accounting | CP2 491/491; stable 66/17/49; debt 1; 81 deferred; TB86 candidate 909/909, membership 990; selector497/CP3 unpromoted |
| New candidates/obligations recorded | D9c and the D4 owner in the tracker; no stable ID |
| ORIENTATION currency line | updated |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a; §8 dispatch-before-witness pattern added |
| CHANGELOG | entry added |
| ROADMAP | n/a |
| Selector manifest | n/a |
| LESSONS | one lesson added |
| Consolidation under CLEAN_UP_POLICY | `…_Core.diff` retained as provenance; superseded banner on the step-61 decision |
| Successor frozen | CB104 exact (§4), then TB87 (§5) |
| Turn boundary held | no product, test, selector or build mutation; nothing executed |
| `review_check.py boundary` | **ALL CHECKS PASSED** (51 PASS, 10 documents) |
| STATUS lifecycle maintained | IN_PROGRESS beacon pushed at entry (`Resumed at 2026-11-08T12:57:36Z`); COMPLETE is the final write |
| Pushed to origin, branch in sync | yes: the docs commit and the final STATUS commit were pushed; `git status -sb` shows the branch tracking origin with nothing ahead or behind |

## `Architecture_M6_CP3_DEFN_P13_A4_A2b_Chain_Segmentation_Falsifier_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A4_A2b_Chain_Segmentation_Falsifier_20261108.md`; moved verbatim.

### M6-CP3 P13 A4/A2b Review: A3 virtual-chain metric and breakpoint falsifier (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (unfinished Review). **Source:** immutable snapshot `c54184c3caab9dfd37eab6653ae923e0a5c733e9`, GitHub Actions `42452191280`, `source.tar.gz` SHA-256 `b3746075d3ee05776a960023a3fa5c74290dfa6810756452bb42f3c1f88ced6a`. All calculations below are independently authored Python scratch, **not production C++ executions**, **not an A3 re-solve**, and **not a Vase A4 output**. Retain the prior [production contract audit](#architecture_m6_cp3_defn_p13_a4_a2b_production_contract_audit_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md").

#### F1 — The current exact preferred-count formula depends on support-piece partition

In `src/geometry/GlobalConformityBaselineSupport.cpp:192-239`, production A3 calculates exact `E = m × Σ_i(||Δx_i||² / h_i²)`, `m` being the number of support pieces and `h_i` the average target at the two endpoints. It rounds `sqrt(E)` to the nearest positive integer via exact integer arithmetic. In `src/geometry/GlobalConformityBaseline.cpp:739-767`, internal breakpoint `j` for count `N` uses `q=floor(mj/N)`, `r=mj-qN`, giving piece `q` with interpolation fraction `r/N`, *without using physical/metric arc length*. These are the actual production algorithms, not the historical `GlobalConformityPlan` solver.

For one straight source-supported path of geometric length 3, with target size 1 everywhere, the independent exact rational mirror yields:

| Same exact path, support-piece boundary positions | E | Preferred edges | Geometric breakpoint positions |
|---|---:|---:|---|
| 0, 1, 3 | 10 | 3 | 0, 2/3, 5/3, 3 |
| 0, 1/2, 1, 3 | 27/2 | 4 | 0, 3/8, 3/4, 3/2, 3 |
| 0, 1, 2, 3 | 9 | 3 | 0, 1, 2, 3 |

All three are source-supported partitions of **the same line path**, and all are piece-continuous and positive. The count *and/or* its geometric distribution changes solely because the path is partitioned differently. This is a **counterexample to reusing these formulas unchanged in a proposed geometrically invariant maximal-Mandatory-chain scheduler**. It is not a demonstration of a defect against current §7.4, which explicitly schedules separate positive A2b arcs.

A stronger exact control splits only the length-1 portion of the same length-3 path into `k` equal support pieces, while retaining the adjacent length-2 portion as one piece. Then `E=(k+1)(4+1/k)` and the same rounding/interpolation gives:

| k | Preferred count | Internal breakpoints at x≤1 | Internal breakpoints at x>1 |
|---:|---:|---:|---:|
| 1 | 3 | 1 | 1 |
| 2 | 4 | 2 | 1 |
| 4 | 5 | 4 | 0 |
| 8 | 6 | 5 | 0 |
| 16 | 8 | 7 | 0 |
| 64 | 16 | 15 | 0 |
| 256 | 32 | 31 | 0 |

The preferred count grows without bound as `k` increases, despite the fixed path length and target size; eventually all internal breakpoints occupy the short length-1 portion, leaving the remaining length-2 edge without a breakpoint. This is a *mathematical* property of the old formulas on a coalesced chain, not evidence from Vase's actual A3 schedule. The Python scratch asserts path length, positive ordered endpoints, rounding, and the divergence pattern. Files: `Directional_A3_Chain_Invariance_Falsifier_20261108.py` (SHA-256 `2eff14161d30180bb150722907b9652c98adb6234020b9752e204a9fcf2d251b`), `Directional_A3_Chain_Refinement_Falsifier_20261108.py` (SHA-256 `be15bf1b2a34f63009d81871b9e88299f71b1857ecc89bd7d6f9aa1c1fd61e33`).

#### F2 — Geometric scale of the phenomenon on the committed Vase boundary

A second source-only Python audit parsed `benchmarks/fixtures/milestone-g/vase.off` directly (1,274 vertices, 2,404 triangles), reconstructed the one 142-edge boundary cycle, and measured exact-input double geometry: perimeter **5.496458697412124**, edge lengths **0.0237357459 to 0.0555964973**, mean **0.0387074556**, coefficient of variation **0.23556**. At the **RA-213 mean target approximation** `h=0.0883`, treating the *entire rim as a hypothetical single open chain* gives geometric length/h **62.24755**, while the production support-piece RMS formula gives **63.95125**, nearest **64**.

A counterfactual split at three **arbitrary**, not A2b-certified, boundary positions (cyclic indices 0, 47, 95) gives candidate counts **20,22,22** under uniform `h`. These geometry checks reproduce the previously reported 142-edge rim and 5.4965 perimeter, but they **cannot** determine the true three A2b trace contact positions, the actual nonuniform target metric, or a true A3 chain solve. Never claim 64 or 20/22/22 as measured production A3 output.

#### D5 decision required before any production change

The current §7.4 producer and independent verifier intentionally bind one positive scheduled span to **each original A2b arc**. Changing only the number of spans is not a safe implementation. A candidate chain contract must explicitly specify:

1. Which canonical A2b topological nodes delimit a *maximal Mandatory chain* and how every original directed source-support fragment maps to an ordered chain offset and to region boundary occurrences.
2. Whether per-original-arc positivity is replaced by **per-chain positivity**, with DESIGN §7.4 and the production independent validator revised together; never silently assign zero to original required spans.
3. A geometrically meaningful and representation-stable preferred-count metric, breakpoint coordinates, source-support carriers, and deterministic exact comparison/rounding policy. **Do not reuse** `m×Σl_i²/h_i²` or ordinal piece-index interpolation without first proving the intended invariance; the scratch above falsifies the naive combination.
4. The unchanged T-join parity constraint and canonical lexical tie-breaking on the *new* chain-to-region incidence graph, with a separate exact certificate verifier.
5. A4 consumption of shared Trace arcs with two opposite A2b occurrence owners, and source-boundary arcs with one exterior owner. Neither a digest-only A3 receipt nor a count-only check is adequate.

**Smallest independent next proof:** export the exact produced Vase oriented A2b disc boundary walks, A2a′ face-fragment orbit ownership, A3 original spans with support pieces and target metric, and actual breakpoint locations into a read-only Review scratch archive. Use that input to compare the actual baseline against one explicitly selected chain candidate and independently audit parity, exact source support and region-incidence reciprocity. Only after an admissible chain metric is chosen should an implementation slice be frozen. The retained abstract quad topology is not a source-attached A4 witness and does not validate D1.

**No changes** to product/tests/fixtures/selector/workflow/build logic or to the accepted CP2 491/491, stable 66/17/49, debt 1, or TB85 908/908 candidate. CB102 remains withdrawn. A D1 expected tier remains a recommendation pending user approval; no change to quality gates or boundary targets is authorized by this review.

#### D4 — independent synthetic typed-incidence coverage scratch (not a production witness)

A separate minimal Python oracle independently checks a declared 3-region/6-arc schedule: trace counts 10/4/9, illustrative rim counts 56/33/75, resulting boundary sums 70/46/94. For every `(arc, ordinal)`, the verifier requires exactly its authoritative set of A2b `(region,boundaryOccurrence)` owners, with one exterior use for rim arcs or two opposite uses for shared traces, exact ordinal endpoints and no extras. The abstract producer and checker are separate functions. **Positive 1/1** and independent negative controls for wrong ordinal, reversed orientation, changed exact endpoint, omitted complete shared trace, and duplicate incidence **5/5 rejected**. Script SHA-256 `1c912725cf0a2e7d15809a1b4acbda1e2a98d01567383b298d56a387f9ded404`, file `Directional_A4_A2b_Conformance_Oracle_Scratch_20261108.py`.

These `[0,1]` per-arc points are **synthetic**, not real Vase support pieces; the chosen rim pairing is not proven to be the source A2b orientation. This checks only the structural shape of a future D4 independent oracle. For today's Plane, MultiFaceSeam, CloseSheets and Cylinder producers (which do not consume A3), record conformance as **not exercised** rather than PASS. No claim is made that the current C++ validator implements this check.

## `Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md`; moved verbatim.

### RA-214 — `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` resolved runtime-free; first A4→A3 slice frozen (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (step 58), resumed from `BLOCKED` (Review/DEFN, Claude). **Subject:** the blocker raised by the same turn's earlier attempt ([WIP index](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Review_WIP_20261108.md"), [execution-authority record](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A4_A2b_Exact_Support_Export_Execution_Authority_Review_20261108.md")) and the scope [RA-213](#architecture_m6_cp3_defn_p13_vase_producer_path_adversarial_review_a2b_disc_construction_20261108md "moved: Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md") §4 gave this turn. **Verdict:** the blocker is valid, and the fault is RA-213 §4 (mine). This turn completes **runtime-free**. Runtime facts move to the TBs of narrow product slices. The first slice, **CB103**, is frozen as an exact patch, and **TB86** is frozen as a 909-row manifest.

**Evidence base:** HEAD `07d1a2207`. Product sources are unchanged since compiled CB101 `23e35798…` (`git diff --stat 23e35798..HEAD -- src include tests` is empty). Static source reading only. No Directional binary was built or executed. The one compile-tool use is a `-fsyntax-only` check of the frozen patch, which emits no object file (§6).

#### 1. The execution-authority block

1. **The conflict is real, not procedural.** Three documents say a Review or DEFN is runtime-free: `REVIEW_TURN_POLICY.md` §4.3 ("A REVIEW is runtime-free"), `AGENT_POLICY.md` ("A same-agent DEFN remains planning/runtime-free") and `Turn_Cadence.md` item 1 (only CB compiles, only TB executes).
   - `ORIENTATION.md` and the handoff have nonetheless carried a "Review track (Claude, scratch build)" convention, which no policy authorizes.
   - RA-200 and RA-201 called the same ChatGPT blocker "procedural". Under the written policy that was wrong, and RA-213 §4 repeated the error.
2. **RA-213 §4 was also mis-scoped.** It asked a Review for three things:
   - a per-disc A4 prototype on Vase;
   - every gate measured on that prototype;
   - an A3 re-solve.

   That is producer implementation plus TB work inside a Review, so it is a monolithic implementation turn in disguise. The 38 WIP commits show the result: the turn could not converge without becoming a CB and a TB.
3. **Resolution, needing no policy edit and no exception:**
   - Step 58 closes runtime-free.
   - Every fact that needs execution becomes the TB evidence of the smallest *product* slice that needs it. Each such slice adds code the architecture keeps: an oracle, a representation or a producer stage. It is never a diagnostic-only CB.
   - The Review authors exact patches from source. It may syntax-check them off-branch, which is neither a build nor runtime, and that check is not evidence.
4. **Suspended:** the "Claude, scratch build" track label on steps 44, 44A, 44B and 44C. Each is re-scoped runtime-free when it is next opened, or waits for the user.
   - Earlier probe results (RA-165 to RA-213) stay as non-accepted information. None was ever promoted, so no accepted state changes.
   - **User decision, optional:** an explicit amendment to `REVIEW_TURN_POLICY.md` §4.3 permitting off-branch, non-accepting Review probes would make probes faster. Policy files are not edited here, and the sequence below does not depend on that decision.

#### 2. Adjudication of the earlier attempt's findings

| Claim | Disposition |
|---|---|
| A3 preferred count and breakpoints depend on how the arc is split into support pieces (F1) | **Confirmed** (`GlobalConformityBaselineSupport.cpp:192-239`; `GlobalConformityBaseline.cpp:739-767`). The scope is wider than stated; see D7 |
| Production A3 is `GlobalConformityBaselinePlan` (`SurfaceCellTracing.h:2350`) | **Confirmed** |
| Ordinary A2b Trace seams cannot use the HardRail/PeriodicCut path; front cells carry no A2b owner | **Confirmed**; made precise as D9 |
| The receipt cannot establish A4 consumption | **Confirmed**; the receipt actually overclaims (D8) |
| Topology-only witness puts the +3 irregularity on the three trace arms | **Rejected as a target.** Trace-arm vertices are interior surface vertices. Valence 3 there means unprescribed singularities (§2.1 item 3). See §4 |
| Source-attached 7,212-quad surrogate and synthetic three-disc cuts | Not compliant witnesses. No further use |
| Read-only A2b/A3 exporter and Python oracle | **Withdrawn.** CB103's census and the disc-domain slice publish these facts as product output |
| `GitHub_Workflow_Policy.md` compile route | Applies to workflow compiles, not to a runtime-free Review. Moot |
| The `BLOCKED` beacon | It carried two non-schema fields (`Durable_Handoff_Policy.md` item 15 allows exactly six). Repaired at resume |

#### 3. New static findings

- **D7: the A3 metric depends on how the arc is split.**
  - **Count.** `count = round(√(m·Σλᵢ²))` with λᵢ = lᵢ/h̄ᵢ. By Cauchy–Schwarz this is ≥ L = Σλᵢ, with equality only for equal pieces. Example: pieces λ = (0.1, 3.9) give L = 4 but a count of 6.
  - **Breakpoints.** They are placed uniformly in piece *index*. In the example, 3 of the 6 edges land in the 0.1-long piece.
  - **Scope.** This already affects every A2b arc that crosses face interiors, Vase's three trace arcs included (counts 10/4/9, unverified). It is not only a hazard of future chain aggregation. DESIGN §7.4 names a "target-size objective" without fixing the formula, so the fix is a §7.4 amendment.
- **D8: the conformity receipt overclaims.**
  - The comment at `SurfaceCellTracing.h:1500` says it proves "which accepted A2b/A3 plans A4 consumed".
  - In fact it is minted at `SurfaceCellTracing.cpp:18375`, after only digest and support-identity checks and before any regional producer runs. It is hashed (`RemeshPipeline.cpp:2091-2096`).
  - Plane, MultiFaceSeam, CloseSheets and Cylinder carry it without consuming A3, which is a §2.1 item 7 exposure.
- **D9: A3 consumption is unrecordable off rails and cuts.**
  - The product validator admits `sharedBoundaryInterval` only on `HardRail` and `PeriodicCut` edges (`:9386-9387`).
  - Curved-disk *does* subdivide every A2b arc by A3 ordinals (`:17577-17616`), but records an interval only when `shared = hardFeature` (`:17557`). Its rim consumption is therefore real but invisible.
  - No edge kind exists for an A2b Trace seam between two discs of one source region.

#### 4. Decisions

- **D6, Vase success criterion. Recommendation: (ii), expected tier D1 `QualityRelaxed`. Not registered until the user approves.**
  - Each of the three discs gets four corners: the port corner, the two trace–rim junctions, and one rim corner placed at an existing A3 breakpoint where the rim has turned 90° against the field.
  - Items 1–9 of §2.1 then hold, disc interiors stay singularity-free, and A3 is unmodified. The only miss is three boundary-valence mismatches under item 10, which DESIGN §2.2 defines as D1.
  - (i), field-derived boundary-valence targets, is an item-10 calibration change. Open it only if the user wants Vase Certified.
  - (iii), a boundary-aligned field, changes the A1 input. Not recommended.
- **D5 waits for D7.** Merging the per-source-edge Mandatory arcs under today's metric would inflate counts (the falsifier in the earlier attempt). The order is therefore: D7 metric first, then maximal Mandatory chains in A2b. Both go in one DEFN with a DESIGN §7.4 amendment, and both change A3 plans and digests on several fixtures.

#### 5. Realigned sequence

| Step | Turn | Owner | Depends on |
|---|---|---|---|
| 58 | this turn (RA-214) | Claude, runtime-free | COMPLETE |
| **59** | **`M6-CP3-CB103-P13-A3-SPAN-COVERAGE-RECEIPT`** | implementation agent, compile only | §6 |
| 60 | `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-EXEC` | implementation agent | CB103 |
| 61 | `M6-CP3-DEFN-P13-A3-RECORDED-BOUNDARY-INTERVALS` | Review, runtime-free | CB103 source |
| 62–63 | CB104 → TB87 | implementation agent | step 61 |
| 64 | `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` (D7, then D5) | Review, runtime-free | — |
| 65 | `M6-CP3-DEFN-P13-A4-A2B-DISC-DOMAIN` | Review, runtime-free | steps 61 and 64 |
| 66+ | per-disc boundary and corners (needs D6) → fill (§4.9) → aggregator dispatch with honest `Declined` flags (D3) | one DEFN → CB → TB each | — |

What each later Review freezes:
- **Step 61** audits every consumer of `sharedBoundaryInterval`, then freezes CB104:
  - the validator accepts a single-sided unit interval on `GenuineSourceBoundary` edges;
  - curved-disk records intervals on every A3-subdivided boundary arc.

  The consumers to audit include `RemeshPipeline.cpp:2285`, `:4832` and `:5109`, and `SurfaceCellTracing.cpp:19882`. **Prediction:** only the curved-disk fixtures change digest, and their boundary spans go from unrecorded to covered.
- **Step 64** freezes the partition-stable A3 metric (D7) and then maximal Mandatory chains (D5), with the DESIGN §7.4 amendment.
- **Step 65** freezes the A2b plan-trace edge kind (reciprocal intervals) and a disc-domain builder that publishes, per disc, the A2a′ fragments, the oriented walk and the A3 breakpoints. Its TB measures Vase's 3 discs and is the first place the D7 trace-count prediction is tested.

The singularity veto stays until the per-disc producer exists. Not scheduled: legacy tuning (O31, P13-n1/2/3), CB102.

#### 6. CB103 and TB86, frozen

**CB103 is behaviour-neutral.** It adds a pure, report-only `summarize_a3_span_coverage(edges, baseline)`: for each A3 span, do the recorded unit intervals tile [0, count] once per A3 incidence?

Its outputs:
- Six `RemeshDiagnostics` counters, filled where the product and the A3 plan coexist (`RemeshPipeline.cpp`), summed across components.
- A separate `a3-coverage case=…` census line, so the pinned `platform-digest` lines stay byte-identical.
- The D8 comment correction.
- One test using the rectangular hard-rail fixture: rail spans are covered, the partition is complete, and two mutations (a dropped interval, a stretched interval) each turn exactly one span partial.

No disposition reads the counters, and nothing is hashed.

**Patch:** [`Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff"), base `07d1a2207`.

| Property | Value |
|---|---|
| Size | 292 lines |
| SHA-256 | `0982bd4ae02d98c876ee42c53b19b7f9452cc90708db991d9ee415609db531ec` |
| Numstat | `8 0` RemeshDiagnostics.h / `36 1` SurfaceCellTracing.h / `71 0` SurfaceCellTracing.cpp / `22 0` RemeshPipeline.cpp / `11 0` SurfaceCellDesignAcceptanceTests.cpp / `63 0` SurfaceCellsPhase10Tests.cpp |
| Context lines to keep | 8 single-space context lines |
| Pre-freeze checks | `git apply --check` clean. Four touched translation units pass `-fsyntax-only` under the `bld55n` configuration, with no new warnings. GCC/GMP compile authority remains with the CB |

**CB103 stop rule:** apply exactly. If the patch hash, numstat or compile does not match, stop with `M6-CP3-PLAN-P13-A3-SPAN-COVERAGE-RECEIPT-STOP`. Infrastructure failure routes to `M6-CP3-CB103A-P13-A3-SPAN-COVERAGE-RECEIPT-ORCH`.

**TB86** runs on the CB103 package.

- **Manifest:** [`Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv"). It has 909 rows: TB85's 908 plus GUARD 909, `SurfaceCellAuthorityContractCutover.A3SpanCoverageObservesRecordedHardRailIntervalsAndTheirLoss`.
  - SHA-256 `3573ffbf6cba47592489c34f2177988c1b66871db4cd983577694dbb9dcabe76`
  - `SELF_CHECK_PASS cases=909 deferred=81`
  - membership 990
  - ledger v5 `fd433f54…`
  - census manifest unchanged, 3 rows `3af1dc0d…`
- **Falsifiers, stated before the build:**
  - The gate is 909/909.
  - Rows 795, 796, 797 and 864 and the Cylinder, BunnyRandom and Vase census `platform-digest` lines are byte-identical to TB85.
  - Every `a3-coverage` line shows `partial=0` and `foreign=0`, and covered + unrecorded = scheduled.
  - Plane, MultiFaceSeam, CloseSheets and Cylinder show `observed=1`, with covered spans only where `HardRail` intervals exist.
  - Vase shows `observed=0`, because it reaches no A4 product.

  This records D4 on Linux as TB evidence.
- **Routes:**
  - mismatch → `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-REV` (Review, runtime-free);
  - infrastructure → `M6-CP3-TB86A-P13-A3-SPAN-COVERAGE-ORCH`.

#### 7. Corrections to RA-213 (mine)

- §4 is withdrawn: it put runtime and prototype work in a Review (§1).
- Its "Claude scratch" labels are suspended.
- Its closeout table omitted most of the `REVIEW_TURN_POLICY.md` §5 rows. This record carries the full block.
- D5 treated per-source-edge arcs as the only cause of over-refinement. D7 adds a second cause on face-crossing arcs.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB85 manifest re-hashed `ec088eb1…` (908). TB86 = those 908 rows byte-identical + row 909. Selector497/CP3 unpromoted, so no accepted-selector change |
| Decisive claims independently re-derived | Policy clauses; receipt mint site and hash; validator interval kinds; curved-disk `shared` flag; A3 count and breakpoint formulas, with the D7 worked example; product source unchanged since CB101 |
| Non-vacuity checked | CB103's test has two mutations, each of which must flip exactly one span. TB86 pins byte-identical digest lines, so any behaviour change in CB103 is caught |
| Prior obligations discharged/carried | RA-213 D1–D3 stand. D4: CB103/TB86. D5: step 64 after D7. D6: user decision pending. RA-213 §4 withdrawn. Earlier-attempt obligations 1–4 superseded by §5. Carried: P13-e, O30b, O31 (legacy only), O32b–e, O33, O27–O29 |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; 81 deferred; TB85 908/908 latest; selector497/CP3 unpromoted |
| New candidates/obligations recorded | D7, D8, D9 and the review-runtime governance item; tracker updated |
| ORIENTATION currency line | RA-214, 2026-11-08 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 next turn updated; §4 n/a (no witness state changed); §7 Vase bullet replaced and the governance item added; §8 pattern updated |
| CHANGELOG | Entry added |
| ROADMAP | n/a: checkpoint status unchanged (CP3 open, nothing promoted) |
| Selector manifest | n/a: no selector added or accepted. TB86 gate manifest committed |
| LESSONS | New lesson (runtime-needing Review → product-slice TB) |
| Consolidation under CLEAN_UP_POLICY | The earlier attempt's 8 WIP records are kept as provenance. The index carries a superseded banner |
| Successor frozen | Exactly one: CB103 (§6), falsifiers in §6 |
| Turn boundary held | Runtime-free. No product, test, selector or workflow mutation in the repository. Patch and manifest committed as artifacts only |
| review_check.py boundary | Recorded in the CHANGELOG entry |
| `STATUS` lifecycle maintained | `IN_PROGRESS` at resume (`Started at` 05:47:31Z preserved, `Resumed at` 09:15:13Z); `COMPLETE` with successor CB103 as the final write |
| Pushed to origin, branch in sync | Confirmed by `git status -sb` after the final push |

## `Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md`; moved verbatim.

### Directional A4 per-A2b-disc producer — production-contract audit (continued Review)

**Canonical turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER`, same unfinished Review. **Frozen semantic source:** `c54184c3caab9dfd37eab6653ae923e0a5c733e9` (source snapshot Actions run `42452191280`; retained `source.tar.gz.sha256` passes). **Do not apply CB102:** withdrawn by RA-213. Independent static inspection and prior topology-only scratch execution; **not** Vase A4, A3 re-solve, compile, or production validation.

#### 1. Correction: production A3 identity and arithmetic

Earlier WIP incorrectly suggested the historical `GlobalConformityPlan.cpp` solver was production A3 authority. The production pipeline calls `remesh_pipeline_detail::make_global_conformity_baseline_input(...)` followed by `build_global_conformity_baseline(...)` (`src/pipeline/RemeshPipeline.cpp:13016-13034`), and passes `GlobalConformityBaselinePlan` to A4 (`:13035-13055`). `GlobalConformityBaselineInput` contains source vertices, target metric and `ConformitySpanInput` but **does not accept caller-supplied incidences**; baseline derives incidences from each `GlobalTopologyRegion::boundary` (`include/directional/geometry/GlobalConformityBaseline.h:165-175`; `src/geometry/GlobalConformityBaseline.cpp:313-347`). `normalize_baseline` rejects a span count different from `topology.arcs().size()` (`GlobalConformityBaseline.cpp:279-286`). Production chooses exact preferred counts and parity flips via minimum T-join plus canonical lex-prefix refinement (`:535-665`), with exact baseline validation in `GlobalConformityBaselineValidator.cpp`.

Per-original-arc positivity **still holds** (§7.4 DESIGN). A virtual-chain experiment must change **production baseline and verifier**, not historical CP1 or silently zero per-arc counts. The true Vase A3 input and complete oriented A2b boundary paths were not preserved in our scratch: the RA-213 totals `145 Mandatory / 3 Trace`, boundary `164`, traces `10/4/9`, region sums `70/94/46` do not determine per-arc geometry or a unique new schedule. Illustrative `20/21/21` counts are not measured A3 output.

#### 2. A2b identity is missing at the A4 materialized-cell boundary

`SurfacePhaseFrontCell` and `SurfaceFrontEdge` each own only `authority::TopologyRegionId sourceTopologyRegion` (`include/directional/geometry/SurfaceCellTracing.h:1621-1652,1787-1797`); for Vase all three A2b discs lie in one source region. `SurfaceBoundedDiskBoundaryPhase` is also A1/source-region-scoped (`:1772-1783`). A3 already owns the finer `(NetworkRegionId, canonicalBoundaryOccurrenceOrdinal)` `ConformityBoundaryIncidenceId` and A4 already defines `SurfaceBoundaryOccurrenceId` of that shape (`GlobalConformityPlan.h:41-47`; `SurfaceCellTracing.h:1439-1454`), but only as an optional per-edge interval label, not a certified owner of **each constructed cell**. A per-disc producer needs verified A2b ownership through construction, assembly and verification; A1 IDs or positional inference cannot establish it.

#### 3. Existing A3 seam and shared-trace semantics are not interchangeable

`SurfaceSharedBoundaryInterval` stores exact `(NetworkArcId, firstOrdinal, secondOrdinal, orientation, optional boundaryOccurrence)` (`SurfaceCellTracing.h:1446-1456`). However `SurfacePhaseFrontProduct::make` rejects any edge that supplies this interval unless its boundary kind is `HardRail` or `PeriodicCut` (`SurfaceCellTracing.cpp:9388-9400`); it only requires the interval for HardRail when a plan receipt exists (`:9422-9428`). `SurfaceConformityPlanReceipt` itself stores only three numbers — A2b digest, A3 digest, schedule size (`SurfaceCellTracing.h:1501-1508`). This receipt can be published without consuming non-hard-feature intervals (RA-213 census).

The existing global hard-rail pairer matches hard-rail edges and treats opposite chart copies in the **same** A1 source region as `PeriodicCut` with an explicit periodic relation (`SurfaceCellTracing.cpp:18997-19307`). Vase's A2b Trace arcs are *ordinary separating boundaries of two A2b discs in the same A1 source region*, not periodic cuts. The route generator for those current hard-rail pairs explicitly accepts only one-piece `Mandatory` arcs on `SourceEdgeSupport` (`:18828-18863`), whereas A2b Trace paths are multiple exact `SourceFaceInteriorSupport` pieces (`GlobalTopologyPlan.cpp:2683-2706`). Relabeling Vase traces as HardRail would be a **false equivalence**.

A minimal general conformance proof must independently enumerate each A3 `(arc, intervalOrdinal)` and its accepted A2b boundary occurrences, materialize the exact ordered endpoints from immutable support pieces and `GlobalConformityBaselinePlan::breakpoint_location`, and compare every produced front side. Source boundary arcs need one exterior use; genuine A2b shared Trace/Cut arcs require exactly two opposite, source-support-equal uses with distinct A2b incidence owners; no extras, missing spans, or orientation flips are allowed. These checks should be keyed on exact typed identities, not floating geometry or matching counts. New A2b internal-arc ownership semantics must remain distinct from source HardRail and periodic quotient relations.

#### 4. A2a′ face fragment construction remains a separate proof

The A2a′ cellularity certificate contains `SurfaceCutGraphSourceFaceOwnership{sourceFace,certifiedFaceOrbits,traceFragmentSides,status}` and each trace-fragment side stores `(TraceId,segmentIndex,orientation,orbit)` (`include/directional/geometry/SurfaceCutGraph.h:78-114`; certificate `:268-284`). A2b's disc certificate identifies `actualEmbeddedFace.orbit`; `GlobalTopologyRegion::sourceFaces` stores only source face keys (which can legitimately appear in several regions). Therefore A4 must join the exact A2a′ orbit and trace-fragment-side ownership to each A2b disc and reconstruct its face-interior fragment geometry from source-attached trace paths. A unique source-face list or A1 region face-set equality cannot prove such a fragment domain. No previous Python scratch contains these source-face fragments.

#### 5. Retained abstract Y-sector scratch — additional localization result

Re-ran `Directional_A4_A2b_Combinatorial_Scratch_20261108.py` in both modes: measured-count model `V/E/Q=185/286/102`, rim=164, trace=23; illustrative model `83/133/51`, rim=62, trace=23. Incidence audits, Euler sum, reciprocal shared traces, and flipped/missing/duplicate-face negative controls pass in each mode. **New precise localization:** the three extra overall-interior valence-3 vertices are exactly `('arm-A',1)`, `('arm-B',1)`, `('arm-C',1)` — one subdivision outward from the central prescribed port along each of three trace arms. They lie on **A2b disc boundaries**, not in any disc's interior, though they are interior vertices of the final whole-surface mesh. They are *not* prescribed cross-field singularities and must be explicitly evaluated against source field/quality gates. In particular, this construction cannot be mistaken for geometrically valid Vase embedding, and the 102-quads model is much coarser than the roughly 224-quads area/target-size heuristic before boundary and quality checks.

#### 6. Narrowest justified next experimental obligations

1. **A2b/A3 export-only scratch authority:** obtain the true ordered `(region, oriented arc)` walks; per-arc support pieces and baseline schedule/count; source-face orbit and trace-fragment-side records; and exact `breakpoint_location` for all ordinals, with the immutable source/metric/plan digests. A single raw evidence archive would permit independent Python analysis without re-deriving topology. Missing source data is not permission to invent rim contact positions.
2. **D5 chain experiment:** propose a certified maximal Mandatory-chain schedule and its exact chain→original A2b arc occurrence map. Run the actual production-baseline parity objective on the new normalized input, including its independent exact certificate check. Preserve the original A2b region graph or explicitly revise A2b topology authority; do not combine both changes implicitly. Before implementing a chain design, decide whether every old span remains an identified *covered portion* of a chain and where positivity is now defined.
3. **Per-disc source attachment:** build ONE Vase disc directly from its certified A2a′ face fragment orbit with exact A3 endpoints and the prescribed port at its corner, rejecting overlaps/edge crossings and recording exact shared-arc incidence. Only then attempt topology-distinct fill, exact embedding, materialization and A5–A8 validation.
4. **Universal non-vacuous conformance:** independently compare *all* source-boundary, hard-feature, trace and cut occurrences for Plane/MultiFaceSeam/CloseSheets/Cylinder/Vase. Negative controls must mutate a trace ordinal, reverse an incidence, and omit a whole scheduled arc; all must produce typed failures even when A2b and A3 digest receipts remain unchanged.
5. **D6 policy:** no change to Vase expected tier, supplied field, boundary-valence targets or strict gates absent the user's explicit approval. `D1 QualityRelaxed` is a candidate design choice, **not** achieved merely because an abstract quad topology exists. D1 requires a complete independently verified source-attached mesh satisfying DESIGN §2.1 items 1–9. Preserve RA-213's withdrawn CB102 and the singularity veto until the per-disc producer is proven.

**Turn remains unfinished:** no real maximal-chain A3 re-solve; no Vase face-fragment A4 geometry; no compile/runtime gate evidence; no frozen successor. No product, test, selector, benchmark or build source was changed in this Review. Stable accepted CP2 491/491 and TB85 candidate 908/908 are unchanged by this static/scratch evidence.

## `Architecture_M6_CP3_DEFN_P13_A4_A2b_Readonly_Authority_Extraction_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A4_A2b_Readonly_Authority_Extraction_Review_20261108.md`; moved verbatim.

### M6-CP3 P13 A4/A2b producer — read-only A2a′/A2b/A3 extraction seam (same-turn continuation, 2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER`, Review, **IN_PROGRESS**. **Source authority:** previously verified frozen source `c54184c3caab9dfd37eab6653ae923e0a5c733e9`, snapshot workflow `42452191280`, 6,234-file hash inventory. No new source snapshot or C++ runtime was produced in this continuation. This record **does not freeze any successor**, grant a D1 tier change, accept Vase output, or supersede RA-213.

#### New finding: use the already published diagnostic products and injected stage-3 stop

`src/pipeline/RemeshPipeline.cpp:12912–13039` constructs and retains `SurfaceCutGraph` (A2a′), `GlobalTopologyPlan` (A2b) and `GlobalConformityBaselinePlan` (A3) **before tracing**. They are copied to `RemeshResult.surfaceCellContext.productSnapshots`. `:13383–13393` permits a typed **`injectFailureAfterStage=3`** return after tracing. With `surfaceCells.retainIntermediateGeometry=true` and `fallbackPolicy=Fail`, the `fail_surface_cells` lambda (`:12342–12429`) does **not** discard those retained A2a′/A2b/A3 snapshots. Thus an independent Review scratch can read all three authoritative products from the rejected `RemeshResult` without changing the production pipeline or waiting for the legacy completed-mesh path. `src/cli/RemeshCommand.cpp:410–417` currently exports only retained A5–A7 materialization data, so `--diagnostics-prefix` alone is **not** sufficient to recover A2b/A3.

**Important precondition:** the injected return is reached only if tracing is **not itself rejected** first (`RemeshPipeline.cpp:13374–13389`). RA-213's measured Vase phase-front outcome was `NotApplicable`, making this a plausible, **unexecuted** extraction route. It must be run and verified; no claim of result availability is made.

#### Concrete scratch overlay (downloadable, not committed into production/test source)

Provided `review_vase_a2b_a3_export.py` constructs a modified **copy** of `tests/SurfaceCellDesignAcceptanceTests.cpp` from the immutable source and adds one diagnostic-only GTest `A4A2bReviewScratch.ExportCertifiedVaseA2bA3`. It reuses exactly the production-acceptance fixture loader (`vase__surface_cells`), generated raw cross field and benchmark options; sets `injectFailureAfterStage=3`; and writes a line-oriented TSV with these record families:

- `REGION`, `WALK`, `REGIONFACE`, `ARC`, `ARCPIECE`: typed A2b region IDs, exact source-face orbit, ordered oriented arc occurrence, endpoint nodes, source-support path;
- `SPAN`, `SPANPIECE`, `BREAK`: production **baseline** A3 preferred/final counts, source-support carrier and exact breakpoint location as piece index plus exact numerator/denominator;
- `FACEOWNER`, `ORBIT`, `FRAGSIDE`: A2a′ certified per-source-face orbit and trace-segment side ownership;
- `METRIC`: per-source-vertex target size from the actual pipeline metric, not a global uniform proxy.

The injected test expects `InjectedStageFailure/tracing`, validates product presence, three certified singularity-free discs, and metric-vector extent; it deliberately does not claim a quadrangulation result. It appends source code to an **off-branch copy** and prints its source/postimage hashes. The test source file in the working branch remains unchanged. Scratch overlay **not compiled**: no C++ type check, GMP build, runner execution, or actual per-region measurements are claimed. Before using it as runtime evidence, compile via an authorized remote GMP scratch workflow and execute with GTest filter `A4A2bReviewScratch.ExportCertifiedVaseA2bA3`, preserving the log and source SHA. Do not silently install an ad hoc workflow or modify the durable dispatcher/reusable workflows: the existing dispatcher has no custom scratch-overlay operation, and GitHub workflow policy requires a diagnosed fallback, reusable compile ownership, and validated workflow authority.

#### Independent verifier and non-vacuity

`verify_vase_a2b_a3_export.py` consumes a complete marked TSV segment and checks ordered walk closure, opposite orientation and complete ownership of shared Trace arcs, one exterior owner of Mandatory arcs, source-support piece equality between A2b/A3, exactly covered consecutive A3 breakpoint ordinals with increasing exact piece-index positions and **actual terminal positions** (0 and `pieceCount`), positive exact counts and positive metric, region-even parity, target-size sample coverage, and A2b disc source-face orbit membership in certified A2a′ owners. It pins RA-213's **historical measurements as expected values only**: 3 regions; 145 Mandatory + 3 Trace; 187 scheduled / 188 preferred; exterior 164 and trace subdivisions 23; region boundary counts 46/70/94. Any discrepancy must be **reported**, not fudged to green.

Scratch non-vacuity test `test_export_oracle_nonvacuity.py`: synthetic positive **1/1 PASS**; six deliberately corrupted streams **6/6 rejected** (wrong owner orbit, wrong exact endpoint, reversed arc orientation, duplicate/incorrect incidence, nonpositive metric, missing finish marker). **Correction recorded:** the initial version did **not** reject a modified final endpoint (`1/2` in place of `1`); a failing negative exposed the gap and the verifier now enforces first/last piece-coordinate values. Neither the synthetic result nor the checker constitutes a production A4→A3 conformant output.

#### Future actual producer proof, still outstanding

1. Execute the read-only exporter in a remote **GMP-enabled scratch** without changing checked-in test/product sources; preserve exact source/runtimes/hashes. Validate the real typed A2a′/A2b/A3 walks, metric and breakpoints using the independent checker.
2. Use the true three A2b disc boundary occurrences and certified source-face fragments to compare a well-defined maximal Mandatory-chain candidate, not a hypothetical 20/21/21 split. Its metric/breakpoint and positivity contract requires an authorized D5 change; earlier falsifier disproves naive piece-index reuse.
3. Construct A4 source-face-attached quads honoring real trace and Mandatory breakpoints, port corners, interior fill; verify reciprocal side ownership, geometry, prescribed valence and all A5–A8/field/size/quality gates. Prior 7,212-quad global and three surrogate-disc meshes are not this output.
4. D6: recommend evaluating D1 `QualityRelaxed` with named quality exceptions and all strict topology/geometry invariants retained, **but user approval is required before changing an expected gate**. CB102 stays withdrawn and successor `UNKNOWN`.

**Boundary:** only a Review scratch exporter and oracle were authored. Production source, tests, fixtures, selectors, CI workflows, build policy, accepted CP2 491/491, TB85 908/908, stable 66/17/49, debt 1, and 81 deferred were not modified or re-executed. No evidence supports marking this canonical Review COMPLETE.

## `Architecture_M6_CP3_DEFN_P13_A4_A2b_Three_Side_Feasibility_Continuation_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A4_A2b_Three_Side_Feasibility_Continuation_20261108.md`; moved verbatim.

### A4/A2b same-turn independent feasibility addendum

#### Same-turn continuation — 2026-11-08, exact feasibility and contract proof

**New independent mathematical falsifier (not a meshing runtime).** RA-213 reports three Vase A2b disc boundary counts `B=(70,94,46)` and three shared trace-arm counts `t=(10,4,9)` (23 total), with the exterior count 164. Under the explicit **three-logical-side** model of each Y-sector disc—one maximal outer boundary chain, two trace arms—a maximally regular three-sided patch requires the side inequality `outer_i <= trace_a + trace_b` (QuadWild/patch feasibility). For every possible pairing of the three trace-arm pairs with the three region counts, `outer_i = B_i - (trace_a + trace_b)`. Because `B_i >=46` and `trace_a+trace_b <=19`, `outer_i >=27 >19 >= trace_a+trace_b`. **Every one of the three measured discs fails** the necessary inequality, regardless of the six pair-to-disc assignments. This is a conditional falsifier of a *simple 3-sided maximally regular topology template*, **not** a proof that general pure-quad filling is impossible. Extra logical boundary corners, interior irregular vertices/strips, altered trace subdivision or a different topology are required. The actual A2b walk must still certify whether the three-logical-side reduction is valid; its raw side records were not packaged in the checked-in review evidence.

There is a stronger summed necessary bound for this specific three-side model. Summing the three `outer_i <= trace_a+trace_b` inequalities yields `outer_total <= 2*trace_total`. The measured A3 schedule has `outer_total=164` and `trace_total=23`, i.e. `164 > 46` by 118. Even an illustrative chain-coarsened outer target of 62 violates `62 > 46`; it would require at least 31 total trace subdivisions (8 more than now) **or** a topology-distinct fill. At the measured 164 boundary count, the same model needs at least 82 total trace subdivisions (59 more than now). These are necessary, not sufficient, and are conditional on no extra logical corners/irregular topology.

**New independently measured boundary statistics.** Parsing the checked-in `benchmarks/fixtures/milestone-g/vase.off` gives 142 exterior source edges, total 5.496458697412124, edge-length min 0.02373574593, median 0.03978711381, max 0.05559649732. With a **hypothetical constant** target 0.0883 and a single chain consisting of all 142 source boundary edges, current `GlobalConformityPlan.cpp:36` evaluates the preferred count as the integer nearest `sqrt(142 * sum(edgeLength^2)) / 0.0883 = 63.95125`, about 64. The geometric length quotient is `5.4964586974/0.0883=62.24755`; source segmentation creates ~2.74% RMS-vs-length bias, much smaller than the measured 164-vs-62 ~2.63x positivity floor. **This is not an A3 re-solve**: the actual target metric varies and three A2b chains would replace the single illustrative loop; the actual breakpoints and scheduler inputs were not reproduced.

**Source-API obstacle at D5:** `GlobalTopologyPlan.h:44-55` gives each Mandatory `GlobalTopologyArc` one optional `mandatoryEdge`, not an ordered list of many `NetworkEdgeId`s. `GlobalTopologyPlan.cpp:440-454,1120-1150,2910ff` uses the single edge relation to derive incidence/validate mandatory coverage. `GlobalConformityPlan.h:27-38` defines `ConformitySpanId` as one `NetworkArcId`; `GlobalConformityPlan.cpp:42` requires exactly one span per A2b arc and one region-boundary occurrence. Therefore **neither naive A2b arc concatenation nor silent A3 span coalescing respects current certified identities**. An adopted D5 design must choose (a) canonical upstream A2b arc/node simplification with an explicit many-to-one mandatory-edge lineage and a revalidated face-walk/certificate, or (b) canonical A3 *virtual chain* IDs over unchanged A2b arc runs, with an exact chain→arc occurrence/breakpoint map and a revised positivity invariant. The second option is narrower in A2b topology authority but still changes A3's public typed contract. No such change has been authorized or tested.

**Metric/geometry caveat:** `GlobalConformityPlan.cpp:36` uses `m*sum(length_i^2 / midpointTarget_i^2)` for `m` support pieces, and `:49` (breakpoint_location) places `j/n` in a uniform support-piece index coordinate, not by cumulative arc length. A D5 chain can remove the one-edge-one-count floor without automatically providing length-uniform output edges. A later A4 must compare the exact ordered breakpoint sequence and measured edge sizes; no boundary vertex may be shifted independently of A3.

**Disposition:** the proposed four broad slices remain **unfrozen**. Before freezing a Code+Build successor, independently materialize actual A2b oriented disc walks and exact A3 span/source-support coordinates, resolve D5 chain identity without weakening incidence/positivity, and supply a source-attached topology-distinct A4 scratch witness satisfying all structural gates. The 3-sided one-pole template alone is falsified under the tested reduced topology. No production build/test was executed and no fixture/selector/gate/acceptance authority was changed. User decision on the proposed D1 expected tier remains outstanding; no such gate change is assumed.
**Review-boundary independent ancestry:** the source snapshot lacks `.git`, so `review_check.py boundary` exits 1 although its local selector and no-product-change checks pass; the four reported failures are the baseline-ancestor and three durable-baseline-file checks, all dependent on Git history. An independent GitHub compare of `8b7299b43...c54184c3` returns `ahead_by=4371`, `behind_by=0`, and a merge base equal to full commit `8b7299b43764a6ba3444e5bc774a2f1b65e99731`. Thus the baseline **is** an ancestor of the reviewed source, but the baseline three-file durable-heading comparison remains unverified; do not misrepresent the full boundary checker as PASS.

## `Architecture_M6_CP3_DEFN_P13_A4_A2b_Topology_Only_Scratch_Review_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_A4_A2b_Topology_Only_Scratch_Review_20261108.md`; moved verbatim.

### M6-CP3 A4/A2b — independent topology-only scratch, 2026-11-08

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (Review, still IN_PROGRESS). **Exact frozen source:** `c54184c3caab9dfd37eab6653ae923e0a5c733e9` (snapshot workflow 42452191280, metadata and `source.tar.gz.sha256` verified). Read with the previous [WIP review](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Review_WIP_20261108.md"), [feasibility continuation](#architecture_m6_cp3_defn_p13_a4_a2b_three_side_feasibility_continuation_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A4_A2b_Three_Side_Feasibility_Continuation_20261108.md"), and RA-213.

#### Independent scratch evidence (not production A4 or A3)

Construct an abstract oriented Y-sector disc complex using three radial shared chains from the central port to rim points A/B/C, with exact *combinatorial* chain cardinalities 10, 4, 9 (from RA-213). Three rim chains are AB, BC, CA. Form each disc as outward arm, forward rim, reversed adjacent arm; quadrangulate its simple even-length boundary by alternating left/right four-corner ear removals. The first ear removes the central port, so that port is incident to exactly one quad in each of three discs. Every shared-arm vertex is the *same explicit token* on both regions; there is no tolerance-based welding.

| Abstract input | Rim counts AB/BC/CA | Disc boundary edge counts AB/BC/CA | Disc quads AB/BC/CA | Global V/E/F | Boundary edges | Interior extraordinary valence |
|---|---|---|---|---|---|---|
| A3-measured-count **conditional pairing** | 56/33/75 | 70/46/94 | 34/22/46 | 185/286/102 | 164 | 4 vertices of valence 3 |
| Illustrative target-coarsened counts | 20/21/21 | 34/34/40 | 16/16/19 | 83/133/51 | 62 | 4 vertices of valence 3 |

In both cases every edge has one or two faces, interior edges have opposite directed use, every vertex link is connected and has the correct cycle/path shape, all faces have four distinct tokens, the rim is exactly the prescribed three rim chains, Euler characteristic is one, the center has three incident quads, and `sum_int(4-v)+sum_bd(3-v)=4` with interior sum 4 and boundary sum 0. Three extra interior valence-3 poles supply the net +3 beyond the prescribed central +1. These are **topology-only** claims.

**Non-vacuity:** the same scratch incidence checker rejects a flipped face (orientation), removed face (rim coverage), and duplicated face (edge over-ownership), for both cardinality sets. Scratch code SHA-256: `742119651cf330cc0079d1326965b8fe5c4db0fe973c250e1c0b839fa828d3c0`, 151 lines; preserved as downloadable chat artifact `Directional_A4_A2b_Combinatorial_Scratch_20261108.py`.

The measured-count assignment is only one pairing of RA-213's unordered region counts 70/94/46 with the three arm-pairs; actual oriented A2b walks have **not** been recovered. The illustrative counts 20/21/21 are **not** the result of running the exact A3 scheduler. Neither case uses source-face fragments, barycentric attachment, the supplied cross-field, source-boundary geometric fidelity, injective embedding, A5/A8 certificates, size/warpage/field/quality gates, or a produced A3 output. Mean equal-area size / 0.0883 is approximately 1.48 for 102 quads and 2.09 for 51 quads, demonstrating why a valid topological witness is not a target-size or production witness.

#### D5 and producer contract implications

1. `GlobalTopologyArc::mandatoryEdge` is optional *single* `NetworkEdgeId`; `GlobalTopologyRegion::sourceFaces` is face-orbit fragment coverage, not an ordinary set of disjoint source faces. Source: `include/directional/geometry/GlobalTopologyPlan.h:44-90`.
2. `ConformitySpanId` is a single `NetworkArcId`; `canonicalize_impl` enforces one span per A2b arc, plus one incidence per boundary occurrence. `preferred_count` multiplies per-piece sum of squared metric lengths by piece count; `breakpoint_location` uses *piece-index*, not accumulated physical/metric length. Source: `include/directional/geometry/GlobalConformityPlan.h:27-65`, `src/geometry/GlobalConformityPlan.cpp:36-49`.
3. To coarsen boundary counts below the number of source-edge Mandatory arcs, positivity **cannot remain defined on each original full A2b arc**. A virtual chain must explicitly preserve all source segment lineage and oriented incidence while changing the A3 scheduling unit, positive-count contract and breakpoint ownership, or A2b must safely publish larger merged arcs with a many-source-edge certificate. A silent downstream count merge would break DESIGN §7.4.
4. The existing curved-disk A4 path is gated to hard-feature source regions and requires a candidate A2b face-set equal to the whole A1 region. Vase has zero hard features and three certified *fragments* of one A1 region; this producer cannot be re-used unchanged. Source: `src/geometry/SurfaceCellTracing.cpp:15478-15550`.

**Minimal future source experiments, in order:** (a) independently materialize the true oriented A2b disc walks and their exact A3 span/source-support coordinates; (b) determine one D5 chain identity/positivity design, test it with unchanged A2b authority and an exact A3 re-solve; (c) construct one source-face-fragment A4 disc with exactly those A3 breakpoints and port corner, certify reciprocal shared traces; (d) then test topology-distinct fill/embedding and every A5–A8 and size/quality gate. A4→A3 conformance must compare the exact ordered breakpoint **coordinates/IDs** on both sides, not counts alone. These are requirements for completing this same Review, not authorized implementation turns.

#### Boundary evidence and disposition

The prior `review_check.py boundary` ran on an extracted snapshot without `.git`: local no-product/selector checks passed, four Git-history-dependent checks failed. GitHub compare separately confirmed `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is an ancestor of `c54184c...`. Independent GitHub baseline fetches established the exact protected heading sets: Handoff 4/4 retained, ORIENTATION 1/1 retained, Regression tracker 0/0. This resolves those historical facts *independently* but does not change the command's nonzero exit or constitute a full original gate PASS.

**Unresolved:** no true A3 chain re-solve; no per-disc source-attached A4 output; no geometric/quality/field validation; no selector/runtime promotion. D1 `QualityRelaxed` is a recommendation requiring explicit user approval before changing any expected tier or gate; all structural validation remains mandatory. Preserve RA-213's CB102 withdrawal and the singularity veto. No product/test/fixture/benchmark/build source changes in this review.

#### Source-fragment ownership joins (independent static inspection)

The A2a′ `SurfaceCutGraphCellularityCertificate` retains `sourceFaceOwners`, each with `certifiedFaceOrbits` and `traceFragmentSides` (trace ID, segment index, oriented side, orbit), and exposes `find_source_face_owner` (`include/directional/geometry/SurfaceCutGraph.h:53-109,274-284`). In contrast, A2b populates `GlobalTopologyRegion::sourceFaces` by appending each face to the owning graph-face orbit and then **sorts/deduplicates face keys** (`src/geometry/GlobalTopologyPlan.cpp:1630-1664`); `GlobalTopologyRegionDiscCertificate::actualEmbeddedFace.orbit` preserves the certified regional face-walk orbit. Consequently an A4 disc domain must join the actual A2a′ source-face ownership and trace-fragment sides to that certified A2b region-orbit, then materialize exact oriented trace/source-boundary fragment polygons from source paths. The `sourceFaces` vector alone is not a face-fragment partition, and neither a set equality test nor geometric position matching certifies membership. This is a precise producer-boundary requirement, **not** a new implemented API or an independently executed geometry proof.

## `Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Census_Adjudication_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Census_Adjudication_20261108.md`; moved verbatim.

### RA-211 — P13-n side-subdivision quality: per-patch census and owner adjudication (2026-11-08)

> **Partly superseded by [RA-212](#architecture_m6_cp3_defn_p13_side_subdivision_quality_review_legacy_fallback_density_20261108md "moved: Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md") (same day, adversarial re-entry).** The §2 census stands. Corrections:
> - Vase's layout is about 20× denser than its metric target, because 1,131 of its 1,416 seeds are relief-critical (O31).
> - Vase is the only census fixture on the legacy fallback; the four passing fixtures are produced by the phase front, so the fixture-digest falsifiers in §4/§7 are vacuous for legacy changes.
> - `turns` has no behavioural consumer, so P13-n2's owner is completion's patch model, not the descriptor sign.
> - Parity repair writes 121 rail breakpoints, which §7.4 forbids.
> - CB100 is replaced (own-plane reference, `8c11fb85…`) and CB101 is added (`normalP95` was 121.56° only because of the first-triangle normal).
> - TB85 is now 908 rows.
> - §7's next Review is withdrawn in favour of `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH`.

**Turn:** `M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY` (Review / DEFN, P13-n), Claude scratch track. **Disposition:** the REVIEW_BLOCKER is resolved. The owners are adjudicated. One exact CB (CB100) and one TB (TB85) are frozen. The dominant producer fix is prototyped and **falsified as a standalone landing**, so it goes to a separate Review (`M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY`) with the evidence below.

#### 1. Block and resolution

ChatGPT's [WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_WIP_20261108.md") blocked on "independent per-patch Vase source-edge subdivision and concave-quality scratch census … unavailable; obtain immutable-source lineage evidence". The WIP's static findings S1 and S2 are correct (§3).

Scratch census on the Review track (RA-166.6 F6, RA-188.1, RA-203.1):
- **Source:** HEAD `c9c50f1e9`. Product sources are byte-identical to CB99 `553932b04`; only the env-gated test probe in `SurfaceCellDesignAcceptanceTests.cpp` differs.
- **Run:** retained-geometry Vase run. Its `platform-digest` line is **byte-identical** to the normal run (`completion=e63758b94110a4f7/67750`, macOS; Linux is `946b59dbe8279a65/67750` per TB84).
- **Dumps:** the completion complex (66,715 nodes, 187,060 halfedges, 26,817 cells) and 26,816 patch descriptors (114,913 sides). Also completed-vertex lineage (stitch kind and arrangement node) and quad lineage (backend, `boundaryOnly`), plus pre- and post-optimization meshes.
- **Analysis:** reflex-aware corner angles about the Newell normal, signed corner turns about the source-face normal, node degree, and source-edge, strand and family identity.
- **Reproducibility:** the probe and scripts live in the session scratchpad (`rev211/tools/*.py`). The probe block is reproduced in §7.

#### 2. Census (exact counts)

**Pre-repair vs repair.** The simplified complex has 57,636 nodes. Completion's parity repair finds **5,931 odd cells** and inserts **9,079 nodes** (57,636 → 66,715). Side repair finds 11,424 infeasible cells and inserts 0 (it falls back to `GeneralFallbackPreparation`).

**Side-interior vertices** (71,727 incidences on 114,913 sides):

| Class | Incidences |
|---|---|
| degree-2 on a source edge (D2E) | 46,452 (+40 on rails) |
| degree-2 inside a source face (D2F; arc joints and parity insertions) | 25,008 (+81 on rails) |
| degree-2 at a source vertex | 40 (+51 on rails) |
| junction (degree ≥ 3, T-junction) | **55** |

- **Raw counts:** 64,360 sides have count 1. 50,408 sides carry representation vertices.
- **Semantic counts:** skipping degree-2 plain same-side vertices leaves **114,725 / 114,913 sides at count 1**.

**Corners** (114,913 sides):

| Corner type | Count | Turn |
|---|---|---|
| Junction corners | 107,126 | exactly +90° |
| Degree-2 same-strand L-corners | 7,748 | ±90° |

- The L-corners split exactly in half: 3,874 at +90° (convex) and 3,874 at −90° (reflex). The descriptor hard-codes `turns = 1` for all of them.
- Patches by signed-turn sum: 4-sided 23,324; 6-sided with sum +4 (L) 2,942; 8-sided with sum +4 (U/Z) 371; others 179.
- **Sliver cells** (min/max corner-to-corner side length): 5,760 below 0.1, 677 below 0.01, 51 below 0.001. Examples: cells 8265 and 5604 have sides of 3.3e-5 and 3.9e-5 between nearly coincident traces (1120/1123, 1064/855).

**Output** (67,750 quads; pre- and post-optimization identical):
- **Valence-2 vertices:** 4,463, all degree-2 arrangement nodes (2,081 source-edge, 2,361 in-face, 21 source-vertex); 4,458 of them are also a >170° corner.
- **Quads with a corner > 170°:** 26,373, of which 11,867 are reflex (> 180°). The unsigned metric sees only 24,808.
- **Attribution of the worst corner of each bad quad:**

| Origin of that vertex | Quads | Share |
|---|---|---|
| source-edge crossing (arrangement representation) | 14,025 | 53.2% |
| parity-repair insertion (caused by representation parity) | 6,732 | 25.5% |
| in-face arc joint (arrangement representation) | 3,029 | 11.5% |
| reflex L-corner declared +1 | 2,232 | 8.5% |
| generated 228, feature 93, junction 18, convex corner 16 | 355 | 1.3% |

- **By backend** (bad/total): BoundedCombinatorial boundary-only 21,928/36,744; Pattern boundary-only 3,730/5,229; ClosedForm 415/4,074; ClosedForm boundary-only 200/21,209; TransitionTemplate 100/494.
- **Convex patches without representation side vertices:** only 1,214 of 11,092 quads are bad, counting the representation-free cells that were split by parity insertions.

#### 3. Owner adjudication

| Id | Mechanism | Owner | DESIGN | Status |
|---|---|---|---|---|
| **P13-n1** | Arrangement representation vertices (per-face source-edge crossings, in-face arc joints) become patch breakpoints. Three count writers use one wrong definition: `PatchDescriptor.cpp` `extract_sides` (`++subdivisionCount` per halfedge), completion parity (`cell.halfedges.size() % 2`, two sites), and side repair (`effective_side_counts` over `cell.sideEdgeCounts`). | completion preparation / descriptor (A4 consumer) | §6.2 (semantic vs representation), §7.4 (producers may not insert breakpoints), M4 acceptance ("target-size variation cannot create different side breakpoints"), §10.1 | **Prototype falsified as a standalone landing** (§4); to Review |
| **P13-n2** | Reflex L-corners (a strand turns −90° at a degree-2 node) are declared convex: `patch.turns.push_back(1)` with the comment "the cell orientation determines its sign", but no sign is computed. | descriptor turns; upstream layout strands that turn at degree-2 nodes | §7.4, Amendment 29 (side partition) | to Review, coupled to n1 |
| **P13-n3** | Sliver cells from nearly coincident layout traces (677 below 1% side ratio). | layout strand spacing/selection | §2.2 quality | to Review, coupled to n1 |
| **P13-n4** | Evaluator: unsigned angle extrema (a reflex 233.13° is reported as 126.87°) and warpage over **both** diagonals (a planar concave quad reports 180°). | A8 `evaluate_surface_quad_quality` | §9 independent verification | **exact CB100** (§5) |

**A3 is not the owner.** The arrangement completion path builds the conformity baseline (299 entries) but never consumes it, and the Vase complex contains no A3-typed breakpoint. Only the phase-front path reads the schedule. Binding descriptors to A3 is CP3 promotion work, not P13. Within P13 the correct realignment is to make the existing local count model *semantic*, in line with §7.4.

**Latent defect found.** `side_halfedges(cell)` maps `cell.sideEdgeCounts` to halfedges by offset from `cell.halfedges[0]`. When `canonicalize_logical_sides` merges a side that wraps around index 0, the halfedges are attributed to the wrong sides. Raw counts hide this because their sum always equals `halfedges.size()`; semantic counts expose it (prototype A: counts ≤ 0, `MissingSideSubdivisionEdge`). It belongs to the n1 design.

#### 4. Prototype evidence (scratch only, not for application)

The prototype adds `SurfaceArrangementNode::representationOnly`. It is placed beside `hardBarrierCrossing` so that `sizeof` is unchanged; otherwise `memoryRatioEstimate` changes every `arrangement` digest. A single writer, `mark_representation_only_nodes`, runs once before completion. It marks a node that has degree 2, plain edges (no hard/rail/curve/singularity), no hard barrier, and that **both** incident cells cross on the same logical side. Consumers: parity count, descriptor sides, and the patch boundary. The prototype diff (variant C below, 256 lines, SHA-256 `bcc260b4…`) is kept as Review evidence in [`Architecture_M6_CP3_DEFN_P13_Representation_Breakpoint_Prototype_FALSIFIED.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Representation_Breakpoint_Prototype_FALSIFIED.diff"). **Do not apply it.**

| Variant | Odd cells / parity splits | Vase terminal |
|---|---|---|
| baseline (CB99) | 5,931 / 9,079 | `AggregateCompletionValidationFailure`, 67,750 quads |
| A: all consumers, including side repair | 301 / 490 | `PreparationRejected` `SideSubdivisionRepair:MissingSideSubdivisionEdge` (offset defect) |
| B: parity and descriptor only | 301 / 490 | `PatchCompletionRejected`, patch 5604 (L hexagon, reflex node 28849), transition-template bow-tie |
| C: B, with marks only between two convex cells | 5,865 / 8,717 | `PatchCompletionRejected`, patch 8265 (sliver 0.016 × 3.3e-5), closed-form source-orientation mismatch; asymmetric marks inside one cell plus a misaligned parity insert |

In all variants the Plane/MultiFaceSeam/CloseSheets/Cylinder/BunnyRandom digests stay byte-identical once the flag is in padding. Those fixtures have no representation side vertices: each arrangement cell becomes one quad (65→64, 65→64, 202→200, 290→288).

**Conclusion:** n1 cannot land alone. It turns Vase from a produced, D1-like mesh into no mesh at all. It has to land with n2 (reflex corners) and an n3 decision (slivers), and its side-repair consumer needs wrap-correct side attribution.

#### 5. CB100 — evaluator concave-quad metrics (exact)

- **Patch:** [`Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff"), SHA-256 `d55589c799776ee8449fb4eff6a037a80b228c0d64df6299edc7ab654f9638cb`, 79 lines. Keep its 2 single-space context lines.
- **Numstat and post-image SHA-256:**
  - `15 2` `src/geometry/SurfaceMeshOptimizer.cpp` → `8798fa013a9636d5892109c44ab9e50280881176230caa30c18cf1ba913490ec`
  - `26 0` `tests/SurfaceMeshOptimizerPhase21Tests.cpp` → `6a6d600473fe7300d74b1b414fdac50ee5117a36bc30b6110c526b9e9ece8589`
- **Precheck:** `git diff --quiet 553932b04fb433b560e24c59d23751f70f7f2c3e HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Change:**
  - The interior angle is `360 − unsigned` where the signed corner is negative.
  - Warpage uses only diagonals that lie inside the quad: 0–2 needs corners 1 and 3 positive, 1–3 needs corners 0 and 2 positive. It falls back to both diagonals when neither or both qualify.
  - Convex quads keep identical bits, and `convex` and `signedScaledJacobian` are unchanged.
  - Every decision consumer (optimizer acceptance at `SurfaceMeshOptimizer.cpp:1816`, the pipeline refined pair at `RemeshPipeline.cpp:11519`) requires `convex` first, so only reported metrics change.
- **Test:** `SurfaceMeshOptimizerPhase21.ConcaveQuadReportsItsReflexAngleAndInteriorDiagonalWarpage`:
  - WIP counterexample `[(0,0),(2,0),(0.5,0.5),(0,2)]`: max angle 180+atan2(4,3)°, min 18.4349°, warpage 0, SJ −0.8;
  - lifted convex control.
  - It fails on the legacy body.
- **Scratch verification (macOS, -j2):**
  - the chain applies to a clean HEAD worktree and reproduces the tested tree byte for byte;
  - validation target: 88 PASS, plus the 9 failures that are ledger v5 off-gate rows 373/375/385/390/399/401/406/407/408, identical to baseline;
  - no new warnings;
  - all six acceptance fixtures have byte-identical digests (Vase: `completion` unchanged);
  - Vase report: angle P95 180 → 180.972, max 180 → 359.925, warpage P95/max 156.27/180 → 80.32/179.07; nonConvex 16,812, SJ min −1, aspect and size unchanged.
  - **Local 907-row gate (TB85 manifest):** 906/907. The only red is row 283, the known macOS-only O16 (same as RA-210). Rows 795/796/797/864 and GUARD 907 pass.

#### 6. TB85

- **Manifest:** [`Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv"), 907 rows, SHA-256 `6ee8495981ae5f8fe3475ae6593c9063030c36bd76b6ceed50a5fded6cd0afbd`. It is TB84's 906 rows plus GUARD 907 (`ra211:evaluator-concave-quad-metrics`, validation binary). `SELF_CHECK_PASS cases=907 deferred=81`; membership **988**.
- **Pinned:** gate rows 795/796/797/864 and the Cylinder/BunnyRandom census `platform-digest` lines byte-identical to TB84. The Vase line is byte-identical to TB84 (`completion=946b59dbe8279a65/67750`, `validationIssues=0`), terminal `AggregateCompletionValidationFailure`. The Vase metric values are a macOS Review observation, not a pin.
- **Routes:** mismatch → `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-REV` (Review, Claude, scratch build); infrastructure → `M6-CP3-TB85A-P13-CONCAVE-QUALITY-METRICS-ORCH`.
- **Local scratch gate:** 906/907; only row 283 (O16, macOS) is red.

#### 7. Next Review — `M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY` (P13-n1/n2/n3, Claude, scratch)

The Review must deliver one combined prototype in which Vase completes (no `PatchCompletionRejected`) and the §2 census improves. It then freezes the result as narrow exact CBs, each independently testable:

1. **Representation flag and single writer, no consumers.** Zero behaviour change; the digests prove it.
2. **Wrap-correct side attribution in side repair.** A latent fix; zero change on the fixtures.
3. **Reflex turns.** Signed turns in the descriptor, plus reflex-corner completion (or an upstream strand fix if the census shows that L-corners come from layout outlines).
4. **Semantic counts in all three writers.**

Falsifiers:
- Plane/MultiFaceSeam/CloseSheets/Cylinder/BunnyRandom digests are byte-identical.
- A unit test on `unit_square_two_triangles` with traces at 0.2/0.7 shows the middle cell going from raw counts {1,2,2,1} to semantic {1,1,1,1}, with junctions and a hard trace's crossing protected.
- Vase valence-2 and >170° counts fall, and no new strict issue appears.

Probe block (scratch only):
```
PROBE_SIDES=<dir>: retained run → nodes.tsv, halfedges.tsv, sides.tsv (per descriptor side:
cell, admissible, reason, singularities, side, family, count, hard, rails, curves, boundaryVertices, halfedges),
vlin.tsv (outputVertex, sourcePatch, localVertex, stitchKind, kind), qlin.tsv (outputQuad, sourcePatch,
backend, localQuad, variant, boundaryOnly), provenance.tsv, source/pre/post matrices, plus repair diagnostics.
```

#### 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 54 — NEXT | `M6-CP3-CB100-P13-EVALUATOR-CONCAVE-QUAD-METRICS` | implementation agent, compile only |
| 55 | `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-EXEC` | implementation agent |
| 56 | `M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY` (P13-n1/n2/n3) | Claude Review, scratch |
| then | P13-e, O31, O32e → d → b/c, O33; P13 re-census → matrix → CP3-REV | as before |

CP2 491/491, stable 66/17/49, debt 1, ledger v5 (81 deferred) unchanged; selector497 and CP3 unpromoted.

#### Closeout

**Mine to own:** RA-210.4 asserted that A3 owned side subdivision counts, framing this as "A3 vs completion". The census shows the arrangement path never consumes A3. The P13 owner is the local count model, and A3 binding is CP3 promotion work.

## `Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md`; moved verbatim.

### RA-212 — Adversarial review of RA-211: Vase runs on the legacy fallback, its layout is relief-seeded and 20× too dense, CB100 is revised and CB101 added (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY`, re-entered to review [RA-211](#architecture_m6_cp3_defn_p13_side_subdivision_quality_census_adjudication_20261108md "moved: Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Census_Adjudication_20261108.md") for completeness and accuracy. Claude scratch track, product sources = CB99.

**Disposition:**
- RA-211's census counts stand.
- Its owner model, its falsifiers, its CB100 and its next Review do not.
- **CB100 is superseded** before application by a revised exact patch, and **CB101** is added.
- TB85 grows to 908 rows.
- RA-211's next Review (`M6-CP3-DEFN-P13-SEMANTIC-PATCH-BOUNDARY`) is **withdrawn**. The next Review is `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH`.

#### 1. What stands in RA-211

- **The §2 census**, re-run here with a byte-identical digest:
  - 26,373 quads have a >170° corner;
  - the worst corner sits on a representation vertex for 90.2% of them;
  - all 4,463 valence-2 vertices are representation nodes;
  - parity repair makes 9,079 insertions (5,931 raw-odd cells against 301 semantic);
  - the descriptor turn sign is hard-coded.
- **The latent `side_halfedges` wrap defect.**
- **The fact** that every prototype variant rejects Vase.

#### 2. What RA-211 got wrong (mine to own)

1. **It never compared cell size with the target.**
   - Vase's metric target has mean 0.0883 and range 0.0335–0.1006; the base is 0.05 × bbox diagonal 2.012.
   - Output edges have median **0.00434** and P95 0.0172.
   - The final report's size ratio is **P5 0.0035, P95 0.200**, against the gate's P5 ≥ 0.5. The four passing fixtures sit at 0.53–1.31.
   - About 172–225 target-size quads would cover Vase; it has **67,750**. The layout is about 20× too dense, linearly. RA-211 even noted "~28 quads per source triangle" without asking why.
2. **It missed the cause of that density.**
   - Vase's 1,416 tracing seeds are **1,131 `ReliefCritical`**, 284 `Boundary`, 1 `Singularity` and 0 `AdaptiveFarthest`. Each seed emits four traces whatever the spacing.
   - Relief seeding appears **nowhere in DESIGN**, and its tests are in the optional guidance target.
   - **Scratch probe** (env-gated, withholding the three relief seed inputs; the relief barrier edges are kept):

     | | Current | No relief seeds |
     |---|---|---|
     | seeds | 1,416 | 380 (95 adaptive coverage seeds at target spacing) |
     | traces / strands | 5,664 / 30,989 | 1,520 / 5,327 |
     | **arrangement cells** | 26,817 | **1,184** |
     | odd cells / parity splits | 5,931 / 9,079 | 255 / 0 |
     | Vase run | ~4 min | 51 s |

     The run stops earlier, at `BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node; AlternativeRepairBudgetExhausted (447/447)`.
   - O31 (RA-204.6, "relief critical points decided by rounding noise") was recorded as having "no effect on completed topology", but that was measured only on the four gate fixtures, which have no tracing seeds. On Vase it is the dominant upstream driver of P13-n.
3. **It missed that Vase is the only census fixture on the legacy fallback.** `RemeshPipeline.cpp` calls the arrangement → descriptor → completion path "the legacy tracing fallback", allowed only when every A4 phase-front producer returns NotApplicable.
   - **Phase-front disposition (scratch):** Plane, MultiFaceSeam, CloseSheets and Cylinder are **`Produced` by the phase front** (A3-consuming A4). Vase is **`NotApplicable`, with no reason published.** BunnyRandom stops earlier, at the atlas (P13-e).
   - Consequently **RA-211's falsifier "five fixture digests byte-identical" was vacuous** for every legacy-completion change. Those fixtures never call `complete_surface_cell_complex`. RA-211 §4 also overclaimed it ("in all variants"): after the padding fix only Plane and Cylinder were run, under variant B.
4. **It mis-owned P13-n2.**
   - `PureQuadPatch::turns` has **no behavioural consumer**: only `turns_are_valid` (|t| ≤ 1) and the completion cache key read it. Signing the turns changes nothing.
   - All 2,232 reflex-corner bad quads come from boundary-only backends: BoundedCombinatorial 1,279, Pattern 886, TransitionTemplate 67.
   - The real owner is completion's patch model. It counts a reflex corner as an ordinary side change, picks templates by side count, and accepts a simple concave quad at a 270° boundary corner.
5. **It missed a forbidden second writer.** Completion parity repair inserted **121 breakpoints on hard rails** (`railId` + `hardFeature`) and 35 on singularity-support edges. DESIGN §7.4: producers "may not insert, remove, quantize, or reorder shared breakpoints"; rail breakpoints are A3's. RA-211's plan ("semantic counts in all three writers") would have hardened this writer.
6. **CB100 was incomplete and used the wrong reference.**
   - **Incomplete:** `normalP95` in the final report uses `face_normal`, the **first-triangle** normal of corners 0–2. On the 7,690 Vase quads whose corner 1 is reflex it flips. Report: **121.56°**. Whole-quad (Newell) normal: **P95 5.91°** (scratch analysis), **3.74°** as the patched evaluator reports it. Zero quads are more than 90° off. The `normalP95 ≤ 15°` gate was failing **purely as a measurement artifact**, RA-208's exact defect class.
   - **Wrong reference:** CB100 took reflex corners against the **source** normal. The validator (CB98 `quad_fan_corner`) uses the quad's own Newell normal, so there were two definitions in A8 (§9). On a quad listed clockwise (inverted), CB100 reports 341.6° and 126.9° for the angle extrema and 180° warpage on a planar quad. The revised test fails on the frozen CB100 at lines 188/190/191.
7. **It gave an imprecise reason for not landing n1.** "Turns a produced, D1-like mesh into no mesh at all" is wrong. Vase is already `NotProductionReady` with no product. The regression is an earlier, structural terminal (an invalid quad embedding) in place of a post-completion quality failure: it loses the CB97–CB99 `validationIssues=0` evidence.
8. **It cited DESIGN loosely.** §6.2 is about semantic *identity*, and §10.1 about row permutation; neither forbids a geometric vertex. The applicable clauses are the §5 A4 row ("cells conform exactly to the supplied plan; no shared decision is recomputed") and §7.4. The fallback as a whole is outside DESIGN.
9. **It attributed only the angle gates.** After CB100 (revised) and CB101, Vase fails these gates:

   | Gate | Vase |
   |---|---|
   | field P95 (≤ 15) | 36.4 |
   | size P5 (≥ 0.5) | 0.0035 |
   | angle P5 / P95 | 6.46 / 180.8 |
   | warpage P95 / max | 81.6 / 166.2 |
   | aspect P95 / P99 | 60.7 / 286.6 |
   | SJ min / P5 | −1 / −0.013 |
   | nonConvex | 16,812 |
   | boundary-valence mismatches | 248 |
   | singularity-valence mismatch | 1 |

   Only `normalP95` (3.74) newly passes. Field, size, aspect, boundary valence and singularity valence were never attributed.

#### 3. Realignment

- **DESIGN's production path for Vase is the A4 phase-front producer.** It consumes A3 and already produces four of six census fixtures. The legacy fallback is a transitional contract: DESIGN's branch decision deletes a displaced contract at cutover. Its seeding (relief), its layout density and its local parity T-join (writing on rails) are all outside DESIGN.
- **RA-211's step 56 is withdrawn.** Tuning the fallback's count model on a noise-seeded layout 20× denser than target optimizes a configuration that the seeding fix replaces. The P13-n1/n2/n3 measurements stay on record as properties of that configuration, not as frozen work.
- **Next Review: `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH`** (Claude, scratch), in this order:
  1. **Observability:** why each A4 producer (uniform, periodic annulus, curved bounded disk) returns NotApplicable for each Vase region. Today the run publishes `NotApplicable` with no reason. Freeze a narrow diagnostic CB if the reason is not already retained.
  2. **Decision with evidence:**
     - **(a)** extend A4 phase-front coverage to Vase's regions (DESIGN-conformant; A3 owns every shared breakpoint); or
     - **(b)** keep the fallback for P13. In that case:
       - seeding density comes first: relief seeds outside DESIGN, O31 promoted from a determinism item to the P13-n root;
       - re-census at target density, where parity repair failing (255 odd cells) is the first terminal;
       - then n1/n2/n3 only as they recur there;
       - parity repair may not write rail breakpoints.
  3. **Attribute every failing gate** in §2.9, including the field P95, boundary valence and singularity valence.
- **Falsifiers** for any fallback change must run on Vase's legacy path or on legacy unit fixtures, never only the phase-front fixtures.

#### 4. CB100 (revised) — evaluator interior angles and warpage in the quad's own plane (exact)

- **Patch:** [`Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff"), SHA-256 **`8c11fb8541b5dc799f66a5ac8ea325b1e7045b8b50b93ecc6f8689ec92e947a7`**, 114 lines. Keep its 4 single-space context lines. It **supersedes** `d55589c7…` (RA-211.5), which was never applied.
- **Numstat and post-image SHA-256:**
  - `29 2` `src/geometry/SurfaceMeshOptimizer.cpp` → `a0f816b3bc96050ab2c7a68189001e88d22b2a56335befb4e4893b3d456107c0`
  - `39 0` `tests/SurfaceMeshOptimizerPhase21Tests.cpp` → `6104b59ba09a74045b5b9b4ba3a8c811b8424addc36da338bbab8bb0374537fe`
- **Precheck:** `git diff --quiet 553932b04fb433b560e24c59d23751f70f7f2c3e HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Change:**
  - A local `quad_normal` wraps the validator's `source_authoritative_detail::polygon_normal`, one shared definition (§9).
  - A corner is reflex when its turn is negative about the quad's own normal; its angle is then `360 − unsigned`.
  - A diagonal is inside when both corners off it are convex in that plane; warpage uses only inside diagonals and falls back to both diagonals when neither or both qualify.
  - `convex` and `signedScaledJacobian` stay measured against the source normal.
  - Convex quads, in either orientation, keep identical bits.
- **Test** `ConcaveQuadReportsItsReflexAngleAndInteriorDiagonalWarpage`:
  - the counterexample (233.13° / 18.43° / warpage 0 / SJ −0.8);
  - **the same quad clockwise** (same angles and warpage);
  - a lifted convex control.
  - It fails on the legacy body and on the superseded CB100.

#### 5. CB101 — report normal error in the quad's own plane (exact)

- **Patch:** [`Architecture_M6_CP3_CB101_P13_Evaluator_Quad_Normal_Own_Plane.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB101_P13_Evaluator_Quad_Normal_Own_Plane.diff"), SHA-256 **`9b42498d9e3615488c9007499aea590c195d472b66e519c67d5ff124190155f1`**, 56 lines. Keep its 1 single-space context line.
- **Precheck:** the CB100 post-images above.
- **Numstat and post-image SHA-256:**
  - `2 2` `src/geometry/SurfaceMeshOptimizer.cpp` → `ac441cd36be7bec02903f5c35baa85ba0f171022012457b892f99c3707793384`
  - `23 0` `tests/SurfaceMeshOptimizerPhase21Tests.cpp` → `0362e0bd636e89543d403812c39cc96602e0fb05cb642c8c1f7366f333e0dfba`
- **Change:** `validate_final_surface_mesh` normal errors and the diagnostic overlay use `quad_normal` instead of `face_normal`. The optimizer's normal energy (`face_normal`, line 1519) is deliberately unchanged, because changing it would change optimization.
- **Test** `NormalErrorOfAConcaveQuadDoesNotDependOnItsFirstCorner`: a planar concave quad with reflex corner 1 must report `normalP95Degrees ≈ 0` and `nonConvex == 1`. It fails without CB101.
- **Effect:** `normalP95` feeds a gate. A mesh whose only failing gate was this artifact would now pass it; any such mesh still fails `nonConvex == 0`.

#### 6. Scratch verification of CB100 (revised) + CB101

- The chain applies in sequence to a clean HEAD worktree and reproduces the tested tree byte for byte.
- **Validation target:** 89 PASS, plus the 9 ledger-v5 off-gate failures (rows 373/375/385/390/399/401/406/407/408), the same set as the baseline.
- **Digests:** all six acceptance fixtures are byte-identical to the baseline, Vase's whole line included (`validation=` hashes counts and flags, not angles, warpage or normal). The four fixtures report normal P95 0 under both normals.
- **Vase report:** normal P95 121.56 → **3.74**; angle P95 180 → 180.77; max angle 180 → 332.46; warpage P95/max 156.3/180 → 81.6/166.2. nonConvex, SJ, aspect and size are unchanged.
- **Local 908-row gate (revised TB85 manifest):** 907/908. The only red is row 283, the known macOS-only O16. Rows 795/796/797/864 and GUARD 907/908 pass. No compiler warnings in the changed units.

#### 7. TB85 (revised)

- **Manifest:** [`Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv"), **908 rows**, SHA-256 **`ec088eb1121a5846605a4bb3675657b68477c88513c28795350369c03bb9f999`**. It is TB84's 906 rows plus GUARD 907 (CB100 test) and GUARD 908 (CB101 test). `SELF_CHECK_PASS cases=908 deferred=81`; membership **989**. It supersedes the 907-row `6ee84959…`.
- **Pins:** rows 795/796/797/864 and the Cylinder, BunnyRandom and Vase census digest lines byte-identical to TB84 (Vase `completion=946b59dbe8279a65/67750`, `validationIssues=0`, terminal `AggregateCompletionValidationFailure`).
- **Routes:** mismatch → `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-REV` (Review, Claude, scratch build); infrastructure → `M6-CP3-TB85A-P13-CONCAVE-QUALITY-METRICS-ORCH`.

#### 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 54 — NEXT | `M6-CP3-CB100-P13-EVALUATOR-CONCAVE-QUAD-METRICS` (revised `8c11fb85…`) | implementation agent, compile only |
| 55 | `M6-CP3-CB101-P13-EVALUATOR-QUAD-NORMAL-OWN-PLANE` (`9b42498d…`) | implementation agent, compile only |
| 56 | `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-EXEC` (908 rows) | implementation agent |
| 57 | `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` (§3) | Claude Review, scratch |
| then | P13-e; O32e → d → b/c; O33; P13 re-census → matrix → CP3-REV | as before. O31 is absorbed into step 57 for Vase; its determinism falsifier stays. |

RA-211's step 56 (`SEMANTIC-PATCH-BOUNDARY`) is withdrawn. CP2 491/491, stable 66/17/49, debt 1 and ledger v5 are unchanged; selector497 and CP3 are unpromoted.

#### Closeout

Mine to own: items 1–9 above. The most consequential are not checking density against the metric, and treating the phase-front fixtures as falsifiers for legacy-path changes.

## `Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md`; moved verbatim.

### RA-213 — Adversarial re-entry of `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` (2026-11-08)

> **Partly superseded (2026-11-08):** [RA-214](#architecture_m6_cp3_defn_p13_a4_a2b_disc_producer_runtime_free_resolution_20261108md "moved: Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md") §1 and §7 withdraw §4 of this record (scratch prototype and gate measurement inside a Review) and its "Claude scratch" labels. §1–§3 stand.

**Turn:** `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` re-entered (Review, Claude scratch build). **Subject:** the runtime-free [Vase producer-path Review](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Vase_Phase_Front_Producer_Path_Review_20261108.md") (`a74afce4d`), its decision ("singularity-capable regional phase front") and its successor `M6-CP3-CB102-P13-PHASE-FRONT-APPLICABILITY-RECEIPTS`. **Verdict:** the static veto proof stands. The direction, the successor and the gate attribution do not. **CB102 is withdrawn.** It also corrects two of my own RA-212 claims (§5).

**Evidence base:** product sources byte-identical to HEAD and to compiled CB101 `23e35798…` (`diff -r src include` empty). Scratch build `bld55n` (fallback BigInteger, `ninja -j2`) with env-gated instrumentation only:
- `PROBE_A4`: a per-region producer report in `build_uniform_phase_front_state`, with each `return result;` of the three producers marked by line;
- `PROBE_NOVETO`: bypasses the three singularity guards;
- `PROBE_SIDES`: a census of the network ports, source regions, A2b regions and certificates, A3 schedule per arc, cross-field axes and output meshes.

With the variables unset, the platform-digest lines of Vase, Plane, MultiFaceSeam, CloseSheets and Cylinder are **byte-identical to RA-212's**, so the instrumentation does not perturb. Scratch files are kept as `rev213/SurfaceCellTracing.a4probe.cpp` and `rev213/Acceptance.a4probe.cpp`, with tools in `rev213/tools/`. No repository product or test source is changed.

#### 1. What stands

- **S1 — the veto.** `tracing_has_singularities(options)` (`SurfaceCellTracing.cpp:5529`) has no region parameter and is the first decline of all three producers on Vase (`:13336/13337`, `:14146/14148`, `:15448/15450`). This is measured: the `PROBE_A4` decline marks hit exactly those returns for the one Vase region.
- **S2 — the aggregate.** It returns `NotApplicable` with no reason when nothing was produced and `hardFeatureEdges` is empty (`:18589`). That admits the legacy fallback.
- **S3 — legacy.** The legacy fallback, its relief density (O31) and its parity breakpoint insertion are not a production path. The `normalP95` artifact is discharged (CB101, TB85).

#### 2. Defects in the reviewed decision

**D1 — evidence was routed through a diagnostic CB and a TB.** The turn was assigned to the Claude scratch track. It ran no probe and deferred "region-local port ownership and post-veto eligibility" to CB102 plus a separate TB, two implementation turns (memory rule: never route evidence through a diagnostic CB/TB). One three-minute scratch run settles both:

| Vase fact (measured) | Value |
|---|---|
| Source-topology regions | **1** (2,404 faces, χ = 1, 1 boundary loop) |
| Hard-feature edges / authoritative rails | **0** / 1 (the boundary) |
| Field singularities | **1** (source vertex 357, index +¼), carrying **3 ports**, all in region 0 |
| Port → region ownership | already a typed field, `FieldAlignedSingularityPort::sourceTopologyRegion`; no containment test or receipt is needed |

CB102's per-region receipt would print one row equal to the global count. Its "mixed-region" fixture cannot reach Vase.

**D2 — wrong abstraction: DESIGN never asks A4 to build across a singularity.** DESIGN §7.2 makes ports into traces, and the faces of the certified cellular embedding become `GlobalTopologyPlan` regions. Each region carries `GlobalTopologyRegionDiscCertificate{interiorSingularityFree, boundarySingularities}`. A4 is "`RegionCellComplex` per region" (§5): the region is the **A2b disc**, and singular ports are disc corners. Measured on Vase:

| A2b/A3 (measured) | Value |
|---|---|
| A2b regions | **3**, all `proves_disc_topology`, all `interiorSingularityFree`; the singularity lies on each boundary |
| Arcs | 148 = **145 Mandatory** (boundary) + **3 Trace** (separatrices from port node 60 to rim nodes 143/144/145) |
| A3 schedule | 187 edges (preferred 188); traces 10/4/9; region sums 70/94/46, all even |

The producers' unit is the **source-topology region**:
- uniform and annulus never read A2b;
- curved-disk reads A2b only on a hard-feature region, and only when one A2b region equals the whole source region (`candidateRows != activeFaceSet → continue`, `:15535–15550`).

No producer can build a source region that A2b **partitions**. A cone always partitions its region by traces, so the veto is a symptom. A "singularity-capable phase front" over a source region re-derives what A2b already certifies. Region-scoping the veto changes nothing for Vase (one region). On a multi-region input it turns `NotApplicable` into aggregate `Rejected UnsupportedSourceSheetTopology` (`anyProduced` plus an unsupported region, `:18589–18606`), which the review did not notice.

**D3 — "removing the veto ... may silently violate" is false on Vase.** With `PROBE_NOVETO`:
- uniform declines `NotApplicable` (non-planar frame, `:13384`);
- annulus declines `NotApplicable` (χ ≠ 0, `:14230`);
- curved-disk returns **`Rejected InvalidBoundedDiskTransport`** (`:16469`), because one gauge cannot be propagated around the cone.

The run fails closed in 1.7 s at `NotProductionReady:tracing`. The veto hides no wrong output. Its real effect is to turn a typed `Rejected` into an unreasoned `NotApplicable`, and that is what admits the legacy fallback for every singular input. There is also an Amendment 19 instance: the three `surfaceCell*PhaseFrontProducerDeclined` flags are set only on the hard-feature `Rejected` path (`RemeshPipeline.cpp:13246–13252`), so Vase reports `declined=000` for producers that did decline.

**D4 — no produced census fixture consumes A3.** RA-212 also missed this. A3 counts against the actual output:

| Fixture (producer) | A3 boundary edges | Output boundary edges | Other A3 arcs |
|---|---:|---:|---|
| Plane (uniform) | 42 | **32** | — |
| MultiFaceSeam (uniform) | 48 | **32** | — |
| CloseSheets (uniform ×2) | 96 | **80** | — |
| Cylinder (annulus) | 64 | 64 | 49 cut arcs, 131 counts, **no counterpart** |

- Uniform declines on hard features and otherwise ignores A3.
- Annulus is periodic and ignores the A2a′ cut.
- Curved-disk consumes A3 only on hard-feature regions, which no census fixture exercises.
- Product validation checks shared intervals only on `HardRail` edges (`SurfaceCellTracing.cpp:9422`).

So §5 A4 ("cells conform exactly to the supplied plan") and §2.1.7 are unverified on every census fixture. A per-disc A4 for Vase must consume the shared trace-arc counts, a contract no current non-hard-feature producer honours or checks.

**D5 — A3's Vase schedule is about 2.6× too fine on the boundary.**
- A2b publishes **one Mandatory arc per source boundary edge**: 145 single-piece arcs, 142 source edges plus 3 trace-endpoint splits.
- Positivity gives each arc ≥ 1, for **164** boundary edges. The metric wants about **62** (rim length 5.4965, mean target 0.0883; source boundary edge 0.042 ≈ 0.47 × target).
- Area 1.7437 / target² ≈ **224** quads.

Any A3-conformant A4 inherits this floor. §7.4 accepts positivity's cost as "some coarse configurations ... excluded". Read as a floor at source boundary resolution, that is not "some". The arc granularity (maximal mandatory chains between topological nodes, versus per source edge) is a DESIGN interpretation the next DEFN must settle.

**D6 — Vase's full-gate expectation contradicts its own field.** Every Review, mine included, missed this.
- Vase is a disk (χ = 1) whose supplied field has one interior +¼ singularity.
- By Poincaré–Hopf the field must turn ¾ of a turn against the rim. Measured: **−270.0°**.
- Rim misalignment has median 22.5° and maximum 44°; **76 %** of rim edges are more than 15° off and 31 % more than 30°.
- Quad-mesh counting: Σ_int(4−v) + Σ_bd(3−v) = 4. With the one prescribed valence-3 vertex, every pure-quad Vase mesh needs **net +3 more irregularity**: either ≥ 3 boundary vertices of valence 2, or ≥ 3 interior valence-3 vertices the field does not prescribe.
- The evaluator's target on a smooth rim is valence 3 (angle ≥ 150°, `SurfaceMeshOptimizer.cpp:1313`). So `boundaryValenceMismatch = 0` and A2b's singularity-free disc interiors cannot both hold.
- Rim-aligned boundary quads also put the field-alignment P95 ≤ 15° gate at risk.

This makes Vase's success criterion a **requirements decision**, taken before any producer work:
- (i) calibrate boundary-valence targets from the field's boundary turning, the way `requiredSingularityValenceTargets` already prescribes interior valence;
- (ii) register Vase's expected tier as D1 `QualityRelaxed` (§2.2) with named gates;
- (iii) supply a boundary-aligned field (interior index sum 1).

#### 3. Gate attribution, corrected

| Vase gate (TB85) | Floor for any DESIGN-conformant producer, this field and this A3 | Legacy-specific remainder |
|---|---|---|
| Boundary valence 248 | ≥ 3 (D6), unless (i)/(ii)/(iii) | ≥ 245 |
| Field P95 36.4° | rim band: 76 % of rim edges > 15° from the field (D6) | interior trace and completion geometry |
| Size P5 0.0035 | boundary mean ≈ 0.38 × target while D5 stands | 20× relief-seeded density (O31) |
| Singularity valence 1 | 0: three disc corners give valence 3 by construction | all |
| Angle, warpage, aspect, SJ, nonConvex | none known | all (RA-211/212 census) |

#### 4. Realignment and turn sequence

**Direction:** build A4 per **A2b disc**, consuming A3 on every arc it bounds. Shared trace arcs are consumed identically by both discs, and ports are corners. This is DESIGN §5/§7.2/§7.4, not a new "singularity-capable" front. The source-region producers stay valid for their present domain, and the veto stays until the per-disc producer exists. No legacy tuning (O31, P13-n1/2/3) is scheduled.

| Step | Turn | Owner and exit |
|---|---|---|
| 57 | `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` | COMPLETE, re-entered by RA-213; decision revised; **CB102 WITHDRAWN** |
| **58 NEXT** | **`M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER`** | Review, Claude scratch. In order: (1) the Vase success criterion, D6 (i)/(ii)/(iii), with a recommendation, asking the user if a gate changes; (2) the A2b Mandatory-arc granularity (D5): measure A3 with maximal chains and amend DESIGN if adopted; (3) a scratch prototype of one per-disc A4 on Vase (A2a′ face-fragment domain, A3 breakpoints, port corners, interior fill per §4.9), measuring every gate; (4) the scope of A4→A3 conformance verification (D4) and the typed state of the four produced fixtures; (5) freeze **exact** slices: conformance check, disc domain, boundary breakpoints, fill plus registration. Each is compile-only and goes to a full-gate TB. **Exit:** frozen slices, or STOP `M6-CP3-PLAN-P13-A4-A2B-DISC-PRODUCER-STOP` with Vase registered at its measured tier |
| 44 (parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | unchanged |

**Implementation agent:** no turn is authorized until step 58 freezes exact patches. Do not open CB102, and do not open step 58 (probe-backed, Claude track).

#### 5. Corrections to RA-212 (mine)

- RA-212 §3 called the phase-front producers "A3-consuming". They do not (D4). RA-212's option (a), "extend A4 phase-front coverage to Vase's regions", left "region" ambiguous, and the reviewed decision inherited that ambiguity. The A4 region is the A2b disc.
- RA-212 §2.5's "121 breakpoints on hard rails" are on Vase's **boundary rail**, since Vase has 0 hard-feature edges. They are not shared breakpoints. The governing rule is §5 A4 "conform exactly to the supplied plan" and §2.1.7, not §7.4's shared-breakpoint clause.

#### Closeout

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Veto sites, aggregate, mixed-region rejection, A2b and A3 censuses, post-veto dispositions, A3-versus-output counts, rim turning: all measured on the scratch build |
| Non-vacuity | Instrumentation digest-neutral on 5 fixtures; the post-veto run changes Vase's terminal (fallback → `Rejected`), so the probe discriminates |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; 81 deferred; selector497/CP3 unpromoted; no runtime promotion |
| Carried | P13-e, O30b, O31 (legacy only), O32b–e, O33, O27–O29; P13-n1/2/3 legacy-only, not scheduled |
| Product/test source changed | None |

## `Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Orientation_Adjudication_20261108.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Orientation_Adjudication_20261108.md`; moved verbatim.

### TB87 Review — canonical route orientation versus observed A3 interval

**Turn:** `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-REV` · 2026-11-08 · independent static Review, no runtime or build.

#### Verdict and immutable evidence

**Oracle-frame defect in GUARD 910; no production defect established by the reported mismatch.** The test compares `CanonicalRoute::steps().front().orientation()` (lexicographically canonical storage) to `sharedBoundaryInterval.orientation` (observed physical-rim traversal). Those are different frames. The single-step canonical Boundary route is reversed by canonical minimization when its observed orientation is Forward; the resulting canonical Reverse value is not evidence that the producer emitted a wrong interval.

- Immutable product: CB104 source `b41fbf72a4d4d2255b4b0e94e0148de8378e2364`, eight-target GMP compile run `42484665857`, package `13619640763`.
- Gate [42488019698](https://github.com/akashskypatel/Directional/actions/runs/42488019698), artifact `13620204214`: outer SHA256 `f3fcd27fa87151933f8a41c6487ea6a6cd453f5a91fe7a246eb97fa9983f9925`; verified **1,828/1,828** internal hashes. Gate 909 PASS, 1 RED, 910 executed, membership 991. Raw `910.log` contains 64 failures at 32 edge indices repeated identically for the two face-row orders: `0,4,8,12,128,132,136,140,141,157,173,189,205,221,237,253,256,260,264,268,384,388,392,396,397,413,429,445,461,477,493,509`. Every observed comparison is stored route Reverse (-1) versus interval Forward (+1). Both row orders hit the same mismatch class. No missing/skipped/abnormal control can explain it.
- Census [42488045371](https://github.com/akashskypatel/Directional/actions/runs/42488045371) 1 PASS/2 registered RED, 9/9 hashes. All 7 platform and 7 A3 digest lines remain byte-identical to TB86. It is not evidence for accepting GUARD 910.
- Verified source snapshot artifact `13620151862` (outer `18cd18bf91709c9b0aee281ebb5ed25cd64bdd87c7b617b64d1e0f5772df78b0`; 6,255/6,255 hashes) and current control-plane snapshot artifact `13621539326` (outer `e9665b1fe059a79278a29e70e3d29ac36360d201290527f40fd146e00fa042a9`; 6,257/6,257 hashes); current snapshot event `d8b42b00598f4a39a6419012979c75c053a4a40a`. Neither snapshot alters immutable CB104 semantics.

#### Independent source re-derivation

1. `src/authority/AuthorityKernel.cpp:81–99`: `from_observed_steps` chooses the lexicographically smaller of the observed sequence and its reversal. Reversal calls `TransitionStep::reversed()` and flips its orientation. Therefore `steps()` is a *canonical unordered-route representation*, and it cannot certify observed signed traversal. `oriented_steps()` returns the forward observed sequence (reversing canonical storage when required). `composed_transport()` already uses it.
2. `src/geometry/SurfaceCellTracing.cpp` in `assign_open_front_boundary_authority`: the Boundary step orientation is constructed from traversal on the physical source edge. The curved-disk rim interval records the corresponding A3 ordinal travel direction. Its span, carrier, and source edge are checked separately in GUARD 910.
3. `tests/SurfaceCellsPhase10Tests.cpp:7441–7445`: the guard checks `edge.route.steps().size()==1` and reads `edge.route.steps().front()`, then equates its *canonical* orientation with the *observed* interval orientation. This is the exact incorrect observation. The 64 logged mismatches are consistent with it. They do not isolate any producer error; no counterexample to the producer's own traversal sign was observed.
4. `CanonicalRoute::oriented_steps()` is the type-owned, existing accessor for the correct frame. This is not a direction-agnostic weakening; it compares the recorded interval to the route's observed Boundary orientation while still checking physical carrier identity and one-step shape. The test's independent A3 count, coverage, source boundary/exterior/no-twin, ordinal and tamper assertions remain unchanged.

#### Exact corrective implementation and falsifiers

**Frozen successor:** `M6-CP3-CB105-P13-A3-OBSERVED-ROUTE-ORIENTATION-ORACLE` (one test-only edit, compile/package only, GMP/GMPXX, no execution). Apply [the exact approved patch](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Oracle_Exact.diff") against source authority `b41fbf72a4d4d2255b4b0e94e0148de8378e2364` (source-semantic files unchanged by TB87). Full SHA256 of patch `9e9635aea3245ee298906101f873db6427d9bf08d9842614f4b75ff027e801a8`; test preimage `7f70db2393f4f439b907d26497e5e9366c623a448887960d80556e47c4d74695`, postimage `a43eb329e874cbeb527d13c8dbc5c879bea638e422b08452f4402f236a4c52f4`.

Change only the route observation to:

```cpp
const auto observedSteps = edge.route.oriented_steps();
ASSERT_EQ(1U, observedSteps.size()) << index;
const auto &step = observedSteps.front();
```

**Subsequent immutable Test + Benchmark:** `M6-CP3-TB88-P13-A3-OBSERVED-ROUTE-ORIENTATION-FULL-GATE-EXEC`. Reuse frozen TB87 910-row gate manifest SHA256 `c435519f6304fdcedb794e45187c8c4645e0bb36d32ec567e7979d292fb245bf`, membership 991, ledger v5 81; execute all cases from the new immutable CB105 package (no rebuild). Require 910/910, all rim comparisons in both face-row orders, positive GUARD 909, 910, and all four existing test tamper checks (dropped interval coverage; stretched span; flipped ordinal sign; interior rim invalid), all 7/7 platform and 7/7 A3 lines byte-identical to TB86. Census must remain exactly registered Cylinder PASS, BunnyRandom P13-e RED, Vase legacy-completion RED. Any mismatch → separate independent Review, never relax or silently rebaseline. No compiled/test result is claimed here.

**Limits:** A3 source-rim interval factory does not prove A3 source attachment (D9c → 65A). Uniform and annulus A3 consumption D4 → 64C/64D; metric D7 → 64 before Mandatory-chain D5 → 64B; D8 receipt verification → 65D. The original RA-215 oracle's *frame comparison* is withdrawn; its substantive coverage, conservation, and row-invariance obligations are retained. A compile-successful CB105 is not acceptance. D6 proposed Vase expected D1 remains pending user decision.

#### Requested substantive re-audit — independent static source analysis (2026-11-08)

**Adjudication sustained, but limited.** `Orientation` is `Reverse = -1`, `Forward = +1` (`AuthorityIds.h:324`). `TransitionStep::reversed()` flips sign and inverts transport; `CanonicalRoute::from_observed_steps()` chooses the lexicographically lesser signed route. For a *single Boundary step with identity transport*, the stored canonical sign is **always -1**, whichever direction was observed: a forward observation is stored reversed with `canonical_orientation() == Reverse`, and a reverse observation is stored unchanged. Therefore the 64 `-1 versus +1` comparisons in TB87 guard 910 do **not** identify even one producer sign error or one producer sign success. The old review correctly identifies a test-frame error but must not imply that replacing the accessor proves the producer's geometry. `oriented_steps()` reconstructs the observed path: it is the correct signed route witness for CB105, whose frozen test-only diff remains appropriate. TB88 must still run.

##### Material unclosed source/design obligations

1. **P0 — Factory does not certify interval-to-carrier binding.** `SurfaceCellTracing.cpp:9383–9427` admits a `GenuineSourceBoundary` interval when its kind, exterior/no-opposite, unit ordinal width and orientation-versus-ordinal sign are valid. It does not check `interval.span` against `edge.route.oriented_steps().front().topology()`, A3 baseline carrier or schedule. For example, a unit interval with both ordinal endpoints reversed **and** orientation flipped remains sign-consistent; a foreign physical span with valid unit ordinal also passes this branch when other fields are unchanged. The focused GUARD 910 source-carrier check catches a wrong span on *its fixture*, but is not a factory guarantee for arbitrary product inputs. This is **existing D9c**, not a novel accepted-green regression. It requires a separate authority-design turn and a paired-tamper negative test at the factory boundary, not an unreviewed validator change in CB105.
2. **P0 — Receipt does not prove plan consumption.** `summarize_a3_span_coverage()` only computes a report on supplied edges; the factory retains only receipt digests and does not require full A3 coverage. All-unrecorded spans are counted as `unrecorded`, not `partial`. The rectangular fixture's independent rim-coverage assertion is valuable, but a passing TB88 does not prove DESIGN §2.1.7 globally. Preserve **D8** and a distinct read-only validation/design owner after producer-specific consumption is covered.
3. **P1 — Produced domains still evade A3.** Existing **D4**: uniform and annulus producers publish products under an A3 receipt without consuming scheduled A3 rim/cut breakpoints. The pinned seven `a3-coverage` and platform digests come from other fixtures and cannot replace a positive A3-consumption oracle on each produced domain. Separate uniform from annulus obligations; either consume and record the exact plan or explicitly decline the domain under the A3 contract. No acceptance/promotion until each has its own positive and omission-tamper evidence.
4. **P1 — The next plan conflates independent roots.** Existing **D7** (partition-dependent count/breakpoints) must be defined and verified before **D5** (maximal Mandatory-chain schedule unit, many-source-edge support, revised positivity). Combining both in one implementation obscures whether geometry or scheduling identity changed. Likewise, binding authority **D9c**, reciprocal A2b trace-edge materialization, and per-disc A4 construction require separate changes and independent falsifiers. The previous steps 64/64A/65 are amended below; no normative invariant is silently withdrawn.

##### Exact bounded sequence for implementation

Only the first successor is authorized to run next. Each later **definition**, **Code + Build** and **artifact-only Test + Benchmark** is a separate turn, not a combined implementation package. A passing compile does not count as a runtime gate. Every semantic change requires a distinct exact patch, positive oracle, named negative oracle, row-permutation check where applicable, immutable binary, and a no-accepted-prefix-regression gate. Stop at the first mismatch and request an independent Review; do not rewrite or rebaseline frozen TB87/TB88, 497 selector, accepted CP2, or deferred ledger to obtain green.

| Order | Narrow turn and acceptance obligation | Predecessor |
|---|---|---|
| **Now: CB105** | `M6-CP3-CB105-P13-A3-OBSERVED-ROUTE-ORIENTATION-ORACLE`: exact approved *test-only* three-line accessor patch; compile eight GMP/GMPXX targets, no execution, no code/fixture/selector modifications | This review |
| **Then: TB88** | `M6-CP3-TB88-P13-A3-OBSERVED-ROUTE-ORIENTATION-FULL-GATE-EXEC`: frozen 910 cases, 991 membership, all GUARD 910 row orientations and tamper falsifiers; pinned 7+7 digests and registered census; no rebuild | CB105 PASS |
| **64: D7** | `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC`: define partition-independent count and exact arc-length breakpoint positions *only*; independently test one geometric path subdivided into different source pieces. Then a **separate** exact metric CB and a **separate** metric TB before changing scheduling units | TB88 PASS |
| **64B: D5** | `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING`: specify maximal-chain topology/identity, orientation, positive-count ownership, source-lineage conservation, and count constraints in DESIGN §7.4. Its own CB and TB must prove same source path under split/merged arc representations and the required physical boundary counts | D7 metric TB PASS |
| **64C: D4 uniform** | `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION`: one producer, one independent plan-coverage positive, dropped-breakpoint tamper and row permutation; its own CB then TB | D5 TB PASS |
| **64D: D4 annulus** | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION`: separate periodic/cut boundary coverage and reciprocal orientation tamper, without touching uniform code; own CB then TB | D4 uniform TB PASS |
| **65A: D9c** | `M6-CP3-DEFN-P13-A3-BOUNDARY-SPAN-CARRIER-BINDING`: choose a typed A3 authority reference available to factory/validator; test wrong span, wrong carrier and coupled ordinal/sign reversal while retaining legal absent physical-rim interval under current factory policy; own CB then TB | D4 annulus TB PASS |
| **65B: D9 trace** | `M6-CP3-DEFN-P13-A2B-RECIPROCAL-TRACE-INTERVALS`: introduce a distinct plan-trace edge and paired occurrences; prove exact matching span, opposing ordinals/orientations, region ownership and cross-region negative; own CB then TB | D9c TB PASS |
| **65C: A4 domain** | `M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION`: consume existing A2a′ fragment and oriented A2b walks, produce one bounded domain per disc without recomputing A3 breakpoints; first targeted Vase three-disc positive/rejection gate. The separate CB and TB must not implement downstream fill/dispatch | Trace TB PASS |
| **65D: D8** | `M6-CP3-DEFN-P13-A3-CONSUMPTION-RECEIPT-VALIDATION`: independently certify per-domain consumed schedule/coverage (or truthfully decline); do not allow receipt minting alone to imply consumption; own CB then TB | All relevant producer TBs PASS |
| **66+** | Corners/D6 user decision, fill and dispatch, each separately defined and gated. The proposed Vase D1 change has **no approval** yet | 65D TB PASS and required approval |

**Supersession:** the previous combined step-64 D7+D5 implementation, step-64A uniform+annulus implementation, and step-65 D9c+trace+disc implementation are withdrawn as *bundles only*. Their substantive requirements and RA-214/RA-215 evidence remain retained. This is a sequencing correction, not a test waiver or a claim of newly measured failures. All unreviewed later IDs are planning metadata, not permission to begin them before the immediate successor.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector added or accepted; TB87 membership 991 and accepted CP2 491/491 remain frozen. Historical prefix bytes not freshly re-hashed here. |
| Decisive claims independently re-derived | Gate ZIP+1,828 internal hashes; repeated 32-index tuple across both face-row orders; exact `CanonicalRoute` reversal/observed accessor; test predicate and A3 producer signs. |
| Non-vacuity checked | Canonical single-step sign is -1 irrespective of observed sign; the old 64 failures are non-discriminating for producer correctness. `oriented_steps()` retains an observable sign invariant but actual corrected runtime pending TB88. Factory wrong-span and paired ordinal/sign reversal remain untested D9c negatives. |
| Prior obligations discharged/carried | TB87 test-frame attribution adjudicated, **not** producer sign; D9 rim TB88 pending, D7→64, D5→64B, D4 uniform→64C/annulus→64D, D9c→65A, reciprocal trace→65B, disc→65C, D8→65D, D6 user decision pending, P13-e/O30b/O31/O32b–e/O33/O27–29 carried. |
| Stable accounting | No accepted-green regression: CP2 491/491, 66/17/49, debt 1, ledger v5 81, selector497/CP3 unpromoted. |
| New candidates/obligations recorded | No new accepted-green defect or stable category. Existing D4/D5/D7/D8/D9c refined into independent falsifiable owners; GUARD 910 test oracle CB105/TB88 remains first. |
| ORIENTATION currency line | Updated to TB87-REV and its reviewed result. |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7 updated in place; §4 n/a (fixture state not changed); §8 canonical-versus-observed-frame failure pattern referenced. |
| CHANGELOG | TB87-REV entry prepended. |
| ROADMAP | n/a: M6-CP3 remains active, no milestone exit or status change. |
| Selector manifest | n/a: no selector mutation or promotion. |
| LESSONS | Existing lesson on conflated authority / independent oracle retained; new non-vacuous instance documented here. |
| Consolidation under CLEAN_UP_POLICY | Original TB87 report retained as immutable primary evidence; no safe superseded historical record deleted. |
| Successor frozen | CB105 exact one-test patch above, followed separately by TB88 artifact-only falsifiers above. |
| Turn boundary held | Review-only: no product, test, fixture, selector, benchmark or build source changed; no generated Directional runtime executed. |
| review_check.py boundary | **PASS** on authentic Git history: [static run 42494441417](https://github.com/akashskypatel/Directional/actions/runs/42494441417), 6,257 source snapshot files previously verified; zero product/test/fixture/build/selector mutations, all 39 selector hashes match committed blobs, durable rewrite headings retained; ledgers check also PASS (append-only since `8b7299b43`). Log artifact `13623006637`, ZIP SHA256 `53c2edd7ef243970abd4a6ceb52e7b9f584a2d7a246f2f7a011179521c5a338c`. A fresh [substantive-patch static run 42496774176](https://github.com/akashskypatel/Directional/actions/runs/42496774176) also passed boundary and ledgers; any subsequent documentation harmonization requires the same check. |
| `STATUS` lifecycle maintained | Entry beacon published with original UTC Start; final beacon to be published as final repository mutation only after patch/docs application and closeout. |
| Pushed to origin, branch in sync | [Drive apply run 42494152760](https://github.com/akashskypatel/Directional/actions/runs/42494152760) pushed commit `7c9f4c79d75760dfda8cb0f31cca04c91300d328`; branch head read via GitHub before closing. A local `git status -sb` confirmation is unavailable in ChatGPT Web; no fabricated local result is claimed. |
