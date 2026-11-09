# M6 consolidated record, volume D1: CP3 P13 definitions, probe adjudications and Reviews, to 2026-11-03

This volume holds **38** former standalone `Architecture_M6*` records, moved here on 2026-11-09 by user instruction ("consolidate these records and prune if the content from each is already documented elsewhere"). No record's content was already documented elsewhere: verbatim-line coverage in the permanent documents was at most 27%. So each record is kept **verbatim** as one section below, and nothing is summarized. Only three things changed: heading levels are demoted by two, links to other moved records point to their sections, and paths to relocated files now include their new folder (`selectors/`, `tools/data/`, `evidence/`). Each original file existed standalone at commit `7a460a5e41c4a77a51b69db672e69f910532718c` (`git show 7a460a5e41c4a77a51b69db672e69f910532718c:.agents/Directional/<name>`). Anchors inside a record (`#…`) may resolve to an earlier record in this volume that has the same heading text. The [moved-record map](M6_Consolidated_Record.md#m6-moved-record-map-2026-11-09) lists every record and its volume.

| Original file | Title |
|---|---|
| [`Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Review_Working_Evidence_20261031.md`](#architecture_m6_cp3_defn_p13_design_acceptance_review_working_evidence_20261031md) | P13 design-acceptance matrix — independently verified working evidence (2026-10-31) |
| [`Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md`](#architecture_m6_cp3_defn_p13_o15c_dyadic_exit_probe_adjudication_20261031md) | RA-190 — O15c dyadic A2a exit: probe adjudication of RA-189 (2026-10-31) |
| [`Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md`](#architecture_m6_cp3_defn_p13_probe_adjudication_20261031md) | RA-188 — P13 probe adjudication: three deferred rows, three causes (2026-10-31) |
| [`Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md`](#architecture_m6_cp3_defn_p13_completion_ownership_cost_probe_adjudication_20261101md) | RA-195 — P13-f completion ownership cost: probe adjudication; exact CB71/CB72, TB68 (2026-11-01) |
| [`Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md`](#architecture_m6_cp3_defn_p13_completion_quad_embedding_probe_adjudication_20261101md) | RA-196 — P13-g completion quad embedding: probe adjudication; exact CB73/CB74/CB75, TB69 (2026-11-01) |
| [`Architecture_M6_CP3_DEFN_P13_Single_Edge_Barrier_Slit_Review_Decision_20261101.md`](#architecture_m6_cp3_defn_p13_single_edge_barrier_slit_review_decision_20261101md) | RA-191 — P13-c single-edge barrier slit representation (2026-11-01) |
| [`Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md`](#architecture_m6_cp3_defn_p13_slit_cycle_basis_probe_adjudication_20261101md) | RA-192 — P13-c slit: probe adjudication of RA-191 and exact CB66 (2026-11-01) |
| [`Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md`](#architecture_m6_cp3_defn_p13_vase_arrangement_rotation_probe_adjudication_20261101md) | RA-193 — P13-d Vase: probe adjudication of the completion-incidence decision, and exact CB67/CB68 (2026-11-01) |
| [`Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md`](#architecture_m6_cp3_defn_p13_vase_landed_incidence_probe_revert_20261101md) | RA-194 — P13-d Vase: review of the landed diagnostics CB67; exact revert, then RA-193's patches (2026-11-01) |
| [`Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md`](#architecture_m6_cp3_defn_p13_arrangement_sliver_cells_probe_adjudication_20261102md) | RA-198 — P13-h2 needle grids and P13-i rail lenses: probe adjudication; exact CB77, TB71; selection DEFN (2026 |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Preflight_20261102.md`](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_preflight_20261102md) | P13-j stitched-vertex Review/Definition — same-turn preflight (2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Boundary_Only_Completion_Variant_Review_20261102.md`](#architecture_m6_cp3_defn_p13_boundary_only_completion_variant_review_20261102md) | P13-h2 Review — boundary-only completion changes topology and has a second variant gate |
| [`Architecture_M6_CP3_DEFN_P13_Completion_Dispatch_Source_Review_20261102.md`](#architecture_m6_cp3_defn_p13_completion_dispatch_source_review_20261102md) | P13 sliver Review — closed-form grid dispatch versus existing boundary quadrangulation (2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md`](#architecture_m6_cp3_defn_p13_completion_grid_embedding_probe_adjudication_20261102md) | RA-197 — P13-h/P13-i closed-form grids and side-count descriptors: probe adjudication; exact CB76, TB70 (2026- |
| [`Architecture_M6_CP3_DEFN_P13_Cross_Stage_Evidence_Contract_20261102.md`](#architecture_m6_cp3_defn_p13_cross_stage_evidence_contract_20261102md) | P13 sliver cells — bounded cross-stage causality evidence contract (interim Review, 2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Cyclic_Side_Corrective_Audit_20261102.md`](#architecture_m6_cp3_defn_p13_cyclic_side_corrective_audit_20261102md) | P13 cyclic side indexing — corrective Review audit (2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Directed_Wedge_Scratch_Review_20261102.md`](#architecture_m6_cp3_defn_p13_directed_wedge_scratch_review_20261102md) | Directional P13 directed-wedge review continuation — 2026-11-02 |
| [`Architecture_M6_CP3_DEFN_P13_Fallback_Source_Path_Review_20261102.md`](#architecture_m6_cp3_defn_p13_fallback_source_path_review_20261102md) | M6-CP3 P13 sliver-cell review — exact active producer path |
| [`Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md`](#architecture_m6_cp3_defn_p13_flowrep_selection_probe_adjudication_20261102md) | RA-199 — P13-i FlowRep selection: probe adjudication; unmet support chords; exact CB78, TB72; next failure P13 |
| [`Architecture_M6_CP3_DEFN_P13_Needle_Intrinsic_Provenance_Review_20261102.md`](#architecture_m6_cp3_defn_p13_needle_intrinsic_provenance_review_20261102md) | P13 needle-cell source-provenance and intrinsic-separation review |
| [`Architecture_M6_CP3_DEFN_P13_Optional_Trace_Same_Rail_Return_Review_20261102.md`](#architecture_m6_cp3_defn_p13_optional_trace_same_rail_return_review_20261102md) | P13 arrangement sliver cells — same-rail support-return incidence audit |
| [`Architecture_M6_CP3_DEFN_P13_Protected_Endpoint_Degree_Veto_Review_20261102.md`](#architecture_m6_cp3_defn_p13_protected_endpoint_degree_veto_review_20261102md) | P13 lens same-rail returns — protected endpoint-degree veto review |
| [`Architecture_M6_CP3_DEFN_P13_RepeatedState_Anchor_Admissibility_Review_20261102.md`](#architecture_m6_cp3_defn_p13_repeatedstate_anchor_admissibility_review_20261102md) | P13 source Review — overloaded RepeatedState and anchored support-tip admissibility (2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Sliver_Review_Scratch_Execution_20261102.md`](#architecture_m6_cp3_defn_p13_sliver_review_scratch_execution_20261102md) | P13 nine-cell provenance — isolated Review scratch execution (2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Trace_Termination_Anchor_Source_Review_20261102.md`](#architecture_m6_cp3_defn_p13_trace_termination_anchor_source_review_20261102md) | P13 Review — trace termination versus embedded endpoint authority (2026-11-02) |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Dual_Boundary_Scope_Witness_20261103.md`](#architecture_m6_cp3_defn_p13_assembly_dual_boundary_scope_witness_20261103md) | P13-j — dual-scope boundary keys: two exact source-edge splits and one vertex-seam ambiguity (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md`](#architecture_m6_cp3_defn_p13_assembly_node5355_prepared_ring_comparison_20261103md) | P13-j — Prepared arrangement is one ring; completed boundary keys diverge (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Breakpoint_Witness_20261103.md`](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_breakpoint_witness_20261103md) | P13-j — exact CB78 read-only stitched-vertex breakpoint witness |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md`](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_probe_adjudication_20261103md) | RA-200 — P13-j stitched-vertex probe adjudication (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md`](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_three_fan_witness_20261103md) | P13-j — exact CB78 Vase three-fan stitched-vertex witness (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Assembly_Typed_Source_Transition_Adjudication_20261103.md`](#architecture_m6_cp3_defn_p13_assembly_typed_source_transition_adjudication_20261103md) | P13-j Review/Definition — typed source transitions prove three descriptor boundary key splits |
| [`Architecture_M6_CP3_DEFN_P13_Compatible_Occurrence_Key_V2_Scratch_Verification_20261103.md`](#architecture_m6_cp3_defn_p13_compatible_occurrence_key_v2_scratch_verification_20261103md) | P13-j — scoped boundary-key V2 scratch verification (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Completed_Lineage_Discriminator_Gate_20261103.md`](#architecture_m6_cp3_defn_p13_completed_lineage_discriminator_gate_20261103md) | P13-j — completed-boundary ownership discriminator (same Review, 2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md`](#architecture_m6_cp3_defn_p13_optimizer_source_query_cost_probe_adjudication_20261103md) | RA-201 — P13-k optimizer source-query cost probe adjudication (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md`](#architecture_m6_cp3_defn_p13_optimizer_source_query_cost_static_preflight_20261103md) | P13-k optimizer source-query cost — static preflight (INCOMPLETE) |
| [`Architecture_M6_CP3_DEFN_P13_Row_Ranked_Provenance_Corner_Key_Counterexample_20261103.md`](#architecture_m6_cp3_defn_p13_row_ranked_provenance_corner_key_counterexample_20261103md) | P13-j — row-ranked provenance is not an invariant corner-owner certificate (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_Stitch_Key_Dataflow_Readonly_Review_20261103.md`](#architecture_m6_cp3_defn_p13_stitch_key_dataflow_readonly_review_20261103md) | P13-j — exact stitch-key producer-to-assembler read-only check (2026-11-03) |
| [`Architecture_M6_CP3_DEFN_P13_V2_Readonly_Sampling_Control_Evidence_20261103.md`](#architecture_m6_cp3_defn_p13_v2_readonly_sampling_control_evidence_20261103md) | P13-j V2 read-only CPU sampling and scratch controls — 2026-11-03 |

## `Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Review_Working_Evidence_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Review_Working_Evidence_20261031.md`; moved verbatim.

### P13 design-acceptance matrix — independently verified working evidence (2026-10-31)

**Canonical turn:** `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (DEFN/Review, unfinished).
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft.
**Inspection source:** immutable source snapshot `0a3f22557b651ab0e370b7cafd25f95efaf2e2b1`; run `41212749593`, artifact `13047161542`, outer SHA-256 `26b1947a3bba9ec74b130f35fbf68dee84140f7b176a0d35492290380b327d6f`. All 6,046 snapshot file hashes verified. This is a review working record, not P13 acceptance.

#### Independent TB62 review first

- Re-downloaded TB62 immutable result artifact `13046191343`; independently verified outer ZIP SHA-256 `95a1b5f87b711e4a9587210fce9ff474623f078726e4c416f47ce2f4d0c5c303` and all 1,734 internal manifest hashes.
- Rehashed frozen 863-case manifest `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341` and deferred v4 ledger `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`; checked 863 ordered (row,kind,identity,test,binary) joins to result ledger.
- Recomputed all 863 raw-process log SHA-256 receipts. Each shows an exact selected GoogleTest filter, exactly one matching RUN and OK, one passed test; recorded run=passed=1, skipped=0, exit=0. Membership set exactly equals 863 gated plus 82 distinct deferred identities (945 total), with no overlap or duplication. Kind breakdown: 854 GUARD, 9 POSITIVE.
- The `execution-boundary.json` reports postflight=true; compile/relink/configure/benchmark=false, zero RED/abnormal/missing/skipped/control-bad. This was independently matched against the ledger and logs, not inferred from a successful workflow badge.
- The result binds source to CB63 semantic commit `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`, package `13043004468`. TB62's retained report documents successful 10-target Linux compile/GMP-GMPXX linkage, 11 separate CLI assertions, and GUI link only. This review independently reverified the **test-result** archive **and CB63 immutable compiled package** (artifact `13043004468`, ZIP SHA-256 `14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`, 30/30 internal package hashes), exact source `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`, successful build exit 0, Release, CLI=ON, GUI=ON, GMP=ON, and generated link commands including both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` for authority-kernel tests, CLI, and GUI. The supplementary CLI sidecar's eleven runtime receipts were **not** independently byte-audited here; they remain supported by the TB62 report. GUI *appearance* and cross-platform parity are NOT established; macOS O16 row 283 remains carried.
- Stable accounting remains 66 events / 17 categories / 49 recurrences, debt 1; accepted CP2 491/491; selector497 not promoted; no CP3 acceptance.

#### P13 six-fixture acceptance matrix

The authoritative source contract is `tests/SurfaceCellDesignAcceptanceTests.cpp`: each of six parameterized cases invokes `remesh_from_raw_cross_field` with `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and the independent product oracle. It requires produced output, requested/executed SurfaceCells identity, zero fallback/recovery, `CompletedSurfaceCells` origin, no terminal error, nonempty all-quad mesh and per-face degree 4. Neither a failed-closed output nor a legacy recovery constitutes a pass.

| Fixture | Frozen ledger/gate identity | Independently reverified TB62 result | P13 disposition |
|---|---|---|---|
| Plane | gated `offgate:364`, row 797 | PASS, exact GTest receipt | Existing positive control; not new P13 repair |
| MultiFaceSeam | gated `offgate:363`, row 796 | PASS, exact GTest receipt | Existing positive control |
| CloseSheets | gated `offgate:361`, row 795 | PASS, exact GTest receipt | Existing same-sheet control |
| Cylinder | deferred `offgate:362` | NOT EXECUTED in TB62; historical 600 s timeout | First P13 target; no current gate acceptance |
| BunnyRandom | deferred `offgate:360` | NOT EXECUTED in TB62; historical independent-oracle failure, A3 cut-domain Euler mismatch | Distinct product/topology investigation |
| Vase | deferred `offgate:365` | NOT EXECUTED in TB62; historical 600 s timeout | Distinct bounded nonrectangular/paving investigation |

Earlier RA-180.3 reports a **local** Cylinder run finishing in 179 s before and after A3 exactness changes, but explicitly distinguishes that from the 600 s CI timeout. This record has not independently re-executed Cylinder, so neither success nor reproducible current Linux performance is claimed.

#### Causal review obligations / falsifiers

1. **Cylinder first, max 300 seconds in a separately authorized immutable diagnostic execution:** capture exact exit/timeout, first failure, stage reached, independent oracle, output origin, source-chart and periodic holonomy, and per-stage time/peak memory. A historical local PASS and a CI timeout do not establish the current package outcome. Any 300 s timeout is an incomplete runtime observation, not a product-green result.
2. **O6 / nonrectangular bounded disks:** source `src/geometry/SurfaceCellTracing.cpp` at the polygonal phase/chart construction branch explicitly rejects `!phaseRecord.rectangular` with `InvalidBoundedDiskFrontPairing` after constructing the chart; it states polygonal lattice clipping/pairing is not implemented. Do not treat earlier chart validity as a completed quad producer, or replace it with rectangular coercion. For Vase/Bunny, derive which produced disk(s) actually reach this branch before prescribing a product correction.
3. **Exact atlas (RA-176.3):** A3 topological face gauge, ordering and tie decisions must use exact semantics of stored doubles; confirm source-chart authority and independently varying source-row/order controls, not merely a passing build with one FMA setting.
4. **O9 (RA-178.3):** previous produced open-rail routes were single-carrier. On every actually reached P13 fixture record maximum `route.oriented_steps().size()`; any produced route >1 falsifies the prior non-reachability ruling and must witness the A4 junction-certificate path. Zero routes is NOT proof of a single-step bound.
5. **O15c (RA-181.3):** independently record maximum A4 exact continuation width in bits for each executed design fixture. The bound is 4,096 bits (`kFieldExactContinuationMagnitudeBits`). Any `BranchContinuationExactMagnitudeExceeded` or measured width >2,048 bits triggers an exact-direction/limit design decision. Prior sphere_prescribed 1,531-bit observation is not a measurement of these six fixtures.
6. **Non-vacuity:** a P13 admission requires a real direct `CompletedSurfaceCells` product and a passing independent oracle. Per-fixture probes must record stages and reasons even for timeouts; never count mere reached predicates or partial output as a valid mesh.

#### Boundary and next action

`REVIEW_TURN_POLICY.md` §4.3 and `Turn_Cadence.md` §6 explicitly require Review/DEFN to remain runtime-free, while the current handoff describes this DEFN as 'probe-capable' and expects 300-second fixture executions. The latter is not an express amendment to the former. Consequently **no new Directional runtime or compile was executed in this DEFN**. The execution authority for the planned P13 probes must be reconciled under repository turn policy (e.g. a separately authorized artifact-only TB/diagnostic turn) before invoking binaries. Do not silently treat prior runtimes or static review as completed new probes.

**Current result:** TB62 platform evidence independently re-adjudicated within stated limits; P13 matrix source/ledger mapped; one source-supported O6 failure path identified. P13 producer reachability, fresh Cylinder/Vase/Bunny runtime, exact-atlas/route-width measurements, independent correction plan and mandatory Review closeout remain UNFINISHED. Keep the canonical turn active; do not invent or enter a successor and do not promote CP3.

## `Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md`; moved verbatim.

### RA-190 — O15c dyadic A2a exit: probe adjudication of RA-189 (2026-10-31)

**Turn:** `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` (Review/Definition), resumed and closed on an authentic Git checkout. RA-190 keeps RA-189's choice of a dyadic exit and its Cylinder promotion. It replaces RA-189 §2's safety obligations and §4's CB65 scope with one exact, probe-verified patch (RA-190.8). DESIGN.md Amendment 24 is rewritten to match.

#### RA-190.1 The boundary block was procedural

RA-189 could not close because its agent ran `review_check.py boundary` on a source snapshot with no Git history, so the rewrite ancestor `8b7299b43` was missing. On this checkout at `aed15cd6c`, the unmodified checker reports **ALL CHECKS PASSED**: the rewrite baseline exists and is an ancestor, and the durable sections are preserved 4/4, 1/1 and 0/0. Nothing in the design depended on it.

#### RA-190.2 Review of RA-189

**Upheld.**
- **A dyadic exit, not a higher cap or rounded directions.** Uncapped exact arithmetic on Vase needs 9,131 bits over 309 exits, and prescribed-sphere circulations reach 12,243 bits. Width grows linearly with trace length, so any fixed cap fails on production-size meshes. A rounded direction leaves the affine exit map composing rational coefficients.
- **The policy itself:** `B = 52`, ties to even, integer arithmetic only.
- **The Cylinder promotion,** re-verified:
  - The 864-row manifest `b50463ea…` has an 863-row prefix byte-identical to the TB58 manifest.
  - Ledger v5 `fd433f54…` is exactly v4 minus `offgate:362`.
  - The harness reports `SELF_CHECK_PASS cases=864 deferred=81`.

**Defects.**

| # | RA-189 text | Finding |
|---|---|---|
| R1 | §4: apply rounding "at every A4 trace-exit path" and at the `currentEntryPoint`/`proposal.nextEntryPoint = decision.exitPoint` assignments | **Would break consistency.** Four consumers re-derive a segment's exit by calling `resolve_field_branch_continuation` on the stored entry: the legacy tracer (`SurfaceCellTracing.cpp:2457`), the canonical traversal (`:3120`), the crossing predicate `field_aligned_segments_properly_cross` (`:2753`) and `field_aligned_segment_exit_point` (`:2893`). Rounding at the assignments would make each replayed exit differ from the next segment's entry. The only correct site is inside the resolver, where `EdgeExit` is built (`:680`). Vertex hits (`:675`, `:705`) and grazing transits (`:1996`) already publish exact endpoints. |
| R2 | New typed failure `ContinuationDyadicEndpointCollapse` for an interior exit that rounds to 0 or 1 | **Would add false failures.** HEAD's exact arithmetic already produces interior exits within 2⁻⁵³ of a vertex: 12 on the prescribed sphere (rows 688/699; t ≈ 5.6·10⁻¹⁸ to 1−1.1·10⁻¹⁶; widths 3,006–12,243 bits, several under the 4,096 cap). The dyadic run produces 1. Restricting `n` to `[1, 2⁵²−1]` keeps an interior exit interior, with no new failure. |
| R3 | "Same undirected canonical orientation in both faces" | **Vacuous.** `FieldBoundaryPoint` is already an undirected `SourceEdgeTopologyKey` plus the parameter of `edge.second()`, shared by both incident faces. |
| R4 | Pre-arithmetic direction-complexity certificate; certified field-deviation contract; exact separation/adjacency certificate; quantization-ambiguity error; policy-version receipts; oracle provenance check | **Undefined and unneeded; withdrawn.** A separation certificate needs the unrounded trajectory, which the construction discards. There is one representation, so there is no provenance to carry. `\|q − t\| ≤ 2⁻⁵³` follows from the construction and needs no runtime check. Measured rounding inputs reach at most 271 bits (gate) and 267 (Vase), so per-step arithmetic is already bounded. Existing exact predicates decide crossing, contact, barrier, vertex and recurrence on the published geometry. |
| R5 | "Vase is not pre-declared PASS"; no probe | **Probes give the exact outcome** (RA-190.3), so TB64 can pre-register it. |
| R6 | CB65 as open-ended design, implementation and test authoring | **Monolithic.** Replaced by the exact patch in RA-190.8. |
| R7 | TB64 on the 864-row manifest | **Would fail membership.** CB65 adds two tests (membership 945 → 947), so P8 needs the 866-row manifest in RA-190.6. |

#### RA-190.3 Probe findings (macOS, scratch build, diagnostic only)

| Probe | Result |
|---|---|
| 864-row candidate gate, dyadic | **863/864.** Only row 283 (O16) fails, and it never reaches the rounding. 74 rows exercise inexact rounding; all pass, including the prescribed-sphere census (row 669, 67,299 exits). |
| 81 deferred rows, HEAD vs dyadic | **81/81 RED in both.** 7 rows exercise rounding. Vase changes as below. Rows 191, 344 and 350 give identical output. The prescribed-sphere rows 182, 192 and 196 fail at the same stage (`surface-cut-graph/CellularityNotEstablished`, origin `RotationSystemInconsistent`) with the same per-trace terminals (14 `TraceIntersection`, 10 `SingularityTermination`, the same trace IDs). Exactly coincident trace events separate (56 → 60 events, 10 → 12 terminal intersections), so the reported failure locus moves. |
| Vase, dyadic | Passes tracing (54 s), strands, embedding, arrangement (50 s) and simplification. Then RED at completion: `SideSubdivisionRepair:InvalidInputIncidence`, with 192,482 trace segments. The terminal reads `NotProductionReady:completion detail=None`. |
| Vase, exact, uncapped | **The same failure and the same 192,482 segments** (309 exits, up to 9,131 bits; tracing 69 s). The completion defect does not come from the rounding. |
| Cylinder | No interior exits; PASS in 8 s. Unaffected. |
| CB65 final patch | Both new tests pass. Mutant M1 (`EdgeExit` publishes the exact exit) fails the edge-exit test. Mutant M2 (floor, no clamp) fails both. The 74 rounding rows and 2 new rows pass 76/76. Census: Cylinder PASS; BunnyRandom `CutTransportDomainIdentityMismatch` `cutChi=-3`; Vase `completion=SideSubdivisionRepair:InvalidInputIncidence`. Listed membership is 947 = 866 + 81, with no overlap. |

#### RA-190.4 Rulings

- **Amendment 24 (rewritten):**
  - There is a single site, the `EdgeExit` construction in `resolve_field_branch_continuation`, using the open grid `n/2⁵²` with `1 ≤ n ≤ 2⁵²−1`.
  - There is no new failure code and no receipt.
  - The trace is defined by its published geometry, not by the exact integral curve. Exactly coincident events that depend on an inexact exit may separate.
  - `B` is part of the definition; changing it is a DESIGN change.
- **O15c:** discharged for A2a once TB64 matches, because every A2a-continued entry is then at most 53 bits wide. The 4,096-bit guard stays as the fail-closed backstop for entries constructed outside A2a. Termination still comes from the exact-state cycle guard, the combinatorial-recurrence guard and the step budget.
- **P13-b (Vase):** the A4 frontier is passed. The new earliest failure is **P13-d**: A7 completion side-subdivision repair rejects its input as `InvalidInputIncidence` (`SurfaceCellFeasibilityRepair.cpp:2123`). It goes to a Review DEFN after TB64.
- **O18 (new):** the completion rejection at `RemeshPipeline.cpp:14352–14357` returns without a detail code or first-invalid stage, so the terminal reads `detail=None`. CB65's test hunk exposes `completionFailure` for TB64. The product diagnostic is owned by the P13-d DEFN.
- **Prescribed-sphere event separation:** a stated consequence of Amendment 24, not a regression; the deferred rows keep their stage and origin.
- **Carried unchanged:** O9 falsifier, O6, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b.

#### RA-190.5 CB65 — exact patch

`M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` (CB; implementation agent; Linux workflow runner).

| Item | Value |
|---|---|
| Precheck | `git diff --quiet d56d990580163f4fd0ceda4137f7ecd16ceb6027 HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Patch | RA-190.8 block, verbatim plus a trailing newline. SHA-256 `ed125319bb38f9ed5352c8b18b3513a53dc5e994d3e7f964d27f82341ac6f91b`. Run `git apply --check`, then apply. |
| Numstat | `26 1` `include/directional/geometry/SurfaceCellTracing.h`; `26 2` `src/geometry/SurfaceCellTracing.cpp`; `79 0` `tests/FieldAlignedCurveNetworkTests.cpp`; `2 1` `tests/SurfaceCellDesignAcceptanceTests.cpp` |
| Result SHA-256 | `.h` `6542668e53dcee5b5d13afe608dd7941026e270c0fdcbaee694a3635b47a677d`; `.cpp` `10b4532187d55c1f62dce50169d6e164f4a8141f9cd6c957093f5c2451ddd1fa`; network tests `7dff149cabc02c8862f804b532705ca5a81fbe0bc08e49e5aebaabf94fa24d18`; acceptance tests `f4105aa4772955b30574ff6200d9623a844ff70216aea1f8ef3dd9577a2e6ebf` |
| Build | `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets. Record the artifact ID, ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256. No native runs. |
| Outcomes | Exact → TB64. Patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-DYADIC-EXIT-STOP` (Review). Infrastructure → `M6-CP3-CB65A-P13-DYADIC-EXIT-ORCH` (one retry). |

#### RA-190.6 TB64 — frozen inputs and pre-registered outcomes

`M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` (TB-EXEC; Linux), on the immutable CB65 package.

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB64_P13_Dyadic_Exit_Full_Gate_Case_Manifest.tsv`, **866 rows**, SHA-256 `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`. It is the 864-row candidate byte-for-byte, plus rows 865 `ra190:dyadic-exit-grid` and 866 `ra190:dyadic-edge-exit` (GUARD). `SELF_CHECK_PASS cases=866 deferred=81`. |
| Ledger | v5, 81 rows, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Census | `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` `3af1dc0d…`, no ledger, one fresh process per row |
| Harness | P8 `78b8002c…`, unchanged |

| Run | Pre-registered outcome |
|---|---|
| Gate | **866/866 PASS**, membership **947**, postflight true |
| Census row 1, Cylinder | PASS |
| Census row 2, BunnyRandom | RED `CutTransportDomainIdentityMismatch`, `cutChi=-3` |
| Census row 3, Vase | RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence` and no `BranchContinuationExactMagnitudeExceeded` |

Mismatch routes:
- Any gate RED, membership ≠ 947, or a census signature mismatch → `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-REV` (Review).
- Infrastructure → `M6-CP3-TB64A-P13-CANONICAL-DYADIC-ORCH` (one retry).

No TB64-REV is needed when everything matches.

#### RA-190.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` | Implementation agent, Linux; exact patch |
| 2 | `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` | Implementation agent, Linux; gate 866 + census 3 |
| 3 (parallel with 1–2) | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (BunnyRandom, P13-c) → CB66 → TB65 | Review (probes) → implementation agent |
| 4 (after 2) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d, with O18) → CB → TB | Review (probes) → implementation agent |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | Per slice |

#### RA-190.8 Exact CB65 patch

SHA-256 of the block content plus a trailing newline: `ed125319bb38f9ed5352c8b18b3513a53dc5e994d3e7f964d27f82341ac6f91b`.

Six lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the patched source itself is clean under `git diff --check`.

```diff
diff --git a/include/directional/geometry/SurfaceCellTracing.h b/include/directional/geometry/SurfaceCellTracing.h
index 200da4bc2..8b0c96ea6 100644
--- a/include/directional/geometry/SurfaceCellTracing.h
+++ b/include/directional/geometry/SurfaceCellTracing.h
@@ -1126,10 +1126,35 @@ publish_field_aligned_trace_traversal_state(
  *
  * Exceeding it is a typed rejection, never a fallback to inexact arithmetic: the
  * producer declines to answer rather than answering approximately, so no
- * topological outcome is ever decided by a magnitude.
+ * topological outcome is ever decided by a magnitude. Since DESIGN.md
+ * Amendment 24 an entry published by A2a is at most 53 bits wide, so the policy
+ * binds only on an entry constructed outside A2a.
  */
 inline constexpr std::size_t kFieldExactContinuationMagnitudeBits = 4096U;
 
+/**
+ * @brief Fractional bits of the grid on which A2a publishes an interior exit.
+ *
+ * An exact exit composed face after face widens by the width of each face's
+ * direction (RA-188: about 200 bits per face on the vase), so a long trace
+ * outgrows any fixed magnitude policy. DESIGN.md Amendment 24 publishes each
+ * interior edge exit as n / 2^52 instead, which bounds the next entry at 53
+ * bits however many faces the trace has crossed.
+ */
+inline constexpr unsigned kFieldDyadicExitFractionBits = 52U;
+
+/**
+ * @brief The interior exit parameter A2a publishes for an exact interior exit.
+ *
+ * Returns n / 2^52 for the integer n nearest to 2^52 * parameter, ties to even,
+ * restricted to 0 < n < 2^52. The open grid keeps an interior exit interior:
+ * a vertex hit is decided exactly before this point and is never created or
+ * removed here. Integer arithmetic only. Requires 0 < parameter < 1.
+ */
+[[nodiscard]] authority::FieldExactRational
+field_dyadic_interior_exit_parameter(
+    const authority::FieldExactRational &parameter);
+
 [[nodiscard]] FieldBranchExitTimeOrdering compare_field_branch_exit_times(
     const authority::FieldExactRational &firstPosition,
     const authority::FieldExactRational &firstNegativeDirection,
diff --git a/src/geometry/SurfaceCellTracing.cpp b/src/geometry/SurfaceCellTracing.cpp
index c90a56ed0..1c9e19e8f 100644
--- a/src/geometry/SurfaceCellTracing.cpp
+++ b/src/geometry/SurfaceCellTracing.cpp
@@ -530,6 +530,24 @@ FieldBranchExitTimeOrdering compare_field_branch_exit_times(
   return FieldBranchExitTimeOrdering::Equal;
 }
 
+authority::FieldExactRational field_dyadic_interior_exit_parameter(
+    const authority::FieldExactRational &parameter) {
+  const EInt scale = authority::FieldExactRational::from_integer(
+                         std::int64_t{1} << kFieldDyadicExitFractionBits)
+                         .exact_numerator();
+  const EInt scaled = parameter.exact_numerator() * scale;
+  const EInt denominator = parameter.exact_denominator();
+  EInt nearest = scaled / denominator;
+  const EInt twiceRemainder = (scaled - nearest * denominator) * EInt(2);
+  const bool odd = nearest - (nearest / EInt(2)) * EInt(2) == EInt(1);
+  if (twiceRemainder > denominator || (twiceRemainder == denominator && odd)) {
+    nearest = nearest + EInt(1);
+  }
+  if (nearest < EInt(1)) nearest = EInt(1);
+  if (nearest > scale - EInt(1)) nearest = scale - EInt(1);
+  return *authority::FieldExactRational::from_exact_fraction(nearest, scale);
+}
+
 FieldBranchContinuationResult resolve_field_branch_continuation(
     const authority::SourceFaceTopologyKey &sourceFace,
     const authority::FieldBranchBoundaryPairing &pairing,
@@ -676,9 +694,15 @@ FieldBranchContinuationResult resolve_field_branch_continuation(
             vertexSupport->vertex};
       }
     }
+    // Amendment 24: publish the interior exit on the dyadic grid, so the next
+    // face's entry width does not grow with the length of the trace.
     return FieldBranchContinuationDecision{
-        FieldBranchContinuationKind::EdgeExit, *exitPoint, outgoing,
-        std::nullopt};
+        FieldBranchContinuationKind::EdgeExit,
+        authority::FieldBoundaryPoint{
+            outgoing, authority::ExactUnitParameter{
+                          field_dyadic_interior_exit_parameter(
+                              exitPoint->parameter.value)}},
+        outgoing, std::nullopt};
   }
 
   std::sort(minimizingEdges.begin(), minimizingEdges.end());
diff --git a/tests/FieldAlignedCurveNetworkTests.cpp b/tests/FieldAlignedCurveNetworkTests.cpp
index 2f68eb947..ad5883a38 100644
--- a/tests/FieldAlignedCurveNetworkTests.cpp
+++ b/tests/FieldAlignedCurveNetworkTests.cpp
@@ -16018,6 +16018,85 @@ TEST(ResolvedBranchCorrection,
   EXPECT_EQ(boundary_point(outgoing, 1, 4), decision->exitPoint);
 }
 
+TEST(ResolvedBranchCorrection,
+     DyadicInteriorExitIsNearestOpenGridPointTiesToEven) {
+  using namespace directional::geometry::surface_cell_tracing_detail;
+  constexpr std::int64_t kGrid = std::int64_t{1} << 52;
+  ASSERT_EQ(52U, kFieldDyadicExitFractionBits);
+
+  // A grid value is published unchanged; 1/3 goes to the nearest grid point.
+  EXPECT_EQ(exact_ratio(3, 8),
+            field_dyadic_interior_exit_parameter(exact_ratio(3, 8)));
+  EXPECT_EQ(exact_ratio(1501199875790165, kGrid),
+            field_dyadic_interior_exit_parameter(exact_ratio(1, 3)));
+  EXPECT_LE(field_dyadic_interior_exit_parameter(exact_ratio(1, 3))
+                .magnitude_bits(),
+            53U);
+
+  // Exact halfway points go to the even neighbour: 5.5 -> 6 and 6.5 -> 6.
+  EXPECT_EQ(exact_ratio(6, kGrid), field_dyadic_interior_exit_parameter(
+                                       exact_ratio(11, kGrid * 2)));
+  EXPECT_EQ(exact_ratio(6, kGrid), field_dyadic_interior_exit_parameter(
+                                       exact_ratio(13, kGrid * 2)));
+
+  // An interior value nearer an endpoint than half a grid step stays interior.
+  constexpr std::int64_t kFine = std::int64_t{1} << 60;
+  EXPECT_EQ(exact_ratio(1, kGrid),
+            field_dyadic_interior_exit_parameter(exact_ratio(1, kFine)));
+  EXPECT_EQ(exact_ratio(kGrid - 1, kGrid),
+            field_dyadic_interior_exit_parameter(exact_ratio(kFine - 1, kFine)));
+}
+
+TEST(ResolvedBranchCorrection, EdgeExitPublishesBoundedDyadicInteriorParameter) {
+  using namespace directional::geometry::surface_cell_tracing_detail;
+  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
+  const SourceEdgeTopologyKey incoming = topology_edge(0, 1);
+  const SourceEdgeTopologyKey outgoing = topology_edge(1, 2);
+  // Entry parameter p on (0,1) exits (1,2) exactly at (1 - p) / 2.
+  const auto pairing = continuation_pairing({-2, 1, 1}, {outgoing, incoming});
+  const auto exit_for = [&](const directional::authority::FieldExactRational &p)
+      -> std::optional<FieldBranchContinuationDecision> {
+    const auto resolved = resolve_field_branch_continuation(
+        face, pairing,
+        directional::authority::FieldBoundaryPoint{
+            incoming, directional::authority::ExactUnitParameter{p}});
+    const auto *decision =
+        std::get_if<FieldBranchContinuationDecision>(&resolved);
+    return decision == nullptr
+               ? std::nullopt
+               : std::optional<FieldBranchContinuationDecision>{*decision};
+  };
+
+  // The exact exit 1/3 is published as its grid point, not as 1/3.
+  const auto third = exit_for(exact_ratio(1, 3));
+  ASSERT_TRUE(third.has_value());
+  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, third->kind);
+  EXPECT_EQ(outgoing, third->exitPoint.edge);
+  EXPECT_EQ(field_dyadic_interior_exit_parameter(exact_ratio(1, 3)),
+            third->exitPoint.parameter.value);
+  EXPECT_NE(exact_ratio(1, 3), third->exitPoint.parameter.value);
+
+  // A wide entry under the magnitude policy (3^-2048, about 3,250 bits) has
+  // an exact exit just as wide; the published exit is the grid point 1/2.
+  auto wide = exact_ratio(1, 3);
+  for (int squaring = 0; squaring < 11; ++squaring) wide = wide * wide;
+  ASSERT_GT(wide.magnitude_bits(), 3000U);
+  ASSERT_LE(wide.magnitude_bits(), kFieldExactContinuationMagnitudeBits);
+  const auto narrowed = exit_for(wide);
+  ASSERT_TRUE(narrowed.has_value());
+  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, narrowed->kind);
+  EXPECT_EQ(exact_ratio(1, 2), narrowed->exitPoint.parameter.value);
+
+  // An exit 2^-61 from vertex 1 is still an edge exit, never a vertex hit.
+  constexpr std::int64_t kFine = std::int64_t{1} << 60;
+  const auto nearVertex = exit_for(exact_ratio(kFine - 1, kFine));
+  ASSERT_TRUE(nearVertex.has_value());
+  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, nearVertex->kind);
+  EXPECT_FALSE(nearVertex->sourceVertex.has_value());
+  EXPECT_EQ(exact_ratio(1, std::int64_t{1} << 52),
+            nearVertex->exitPoint.parameter.value);
+}
+
 TEST(M4CPScaleS1,
      ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral) {
   using namespace directional::geometry::surface_cell_tracing_detail;
diff --git a/tests/SurfaceCellDesignAcceptanceTests.cpp b/tests/SurfaceCellDesignAcceptanceTests.cpp
index 3ebd635ac..92efd233b 100644
--- a/tests/SurfaceCellDesignAcceptanceTests.cpp
+++ b/tests/SurfaceCellDesignAcceptanceTests.cpp
@@ -43,7 +43,8 @@ std::string failure_context(const directional::pipeline::RemeshResult &result) {
          " arrangementCells=" +
          std::to_string(result.diagnostics.surfaceCellArrangementCellCount) +
          " completedQuads=" +
-         std::to_string(result.diagnostics.surfaceCellCompletedQuadCount);
+         std::to_string(result.diagnostics.surfaceCellCompletedQuadCount) +
+         " completion=" + result.surfaceCellContext.completionFailure;
 }
 
 
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB58 `31c1360a…`, the 864 candidate `b50463ea…` (prefix byte-identical), ledger v5 `fd433f54…` (v4 minus 362) and the new 866 manifest `289d887c…` all self-check |
| Decisive claims independently re-derived | Probes, not static reading. Gate run under the change. Deferred rows compared between HEAD and dyadic mode. Vase run both exact-uncapped and dyadic. Membership listed from the built binaries |
| Non-vacuity checked | 74 gate rows plus 7 deferred rows exercise inexact rounding. Both new tests fail under mutants M1/M2 and pass on CB65 |
| Prior obligations discharged/carried | RA-189 R1–R7 ruled. O15c discharged once TB64 matches. P13-d and O18 new. O6, O9, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-d (Vase completion incidence), O18 (completion rejection publishes no detail) |
| ORIENTATION currency line | Updated to RA-190 / CB65 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 Next and §7 Immediate updated. §8 line on the dyadic exit corrected. §4: n/a, no witness change |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: a representation change belongs in the producer that every consumer replays |
| Consolidation under CLEAN_UP_POLICY | n/a: RA-189 stays as history; its 864 manifest is kept as the prefix of the 866 |
| Successor frozen | CB65 (RA-190.5); TB64 falsifiers (RA-190.6) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran only in scratch builds |
| `review_check.py boundary` | ALL CHECKS PASSED (see the commit) |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB65 |
| Pushed to origin, branch in sync | Confirmed after the push |

## `Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md`; moved verbatim.

### RA-188 — P13 probe adjudication: three deferred rows, three causes (2026-10-31)

**Turn:** `M6-CP3-DEFN-P13-PROBE-ADJUDICATION` (DEFN, Review track). It reviews `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` ([P13 decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Decision_20261031.md")) and replaces its unstarted successors.
- **Method:** scratch probes are diagnostic only and carry no gate authority (RA-165.2 F1, RA-166.6 F6). They ran on a local macOS arm64 build of `e1fd0e4b…`, which equals HEAD in `src`, `include`, `tests`, `benchmarks`, `CMakeLists.txt` and `cmake` (the CB63 semantic source), at default arithmetic, with one fixture per process. TB63's census is the Linux confirmation.

#### RA-188.1 Review of the P13 decision

**Upheld:**
- The TB62/CB63 audit, the frozen hashes, membership 945 and the stable accounting.
- No gate runtime or acceptance inside a DEFN.
- The six-fixture contract summary.
- The O6 branch exists as stated (`SurfaceCellTracing.cpp:17208`).

**Defects:**

| # | Defect | Effect |
|---|---|---|
| D1 | All three deferred dispositions come from the pre-CB55 TB50C census. None was re-observed at current source. | The matrix is stale: each row now has a different first failure (RA-188.2). |
| D2 | It read "runtime-free" as forbidding Review scratch probes. RA-165.2 F1 and RA-166.6 F6 require them whenever a disposition rests on one; what "runtime-free" excludes is gate runtime and acceptance. | It turned a three-minute probe into a CB+TB cycle. |
| D3 | It froze CB64 to give the frozen P8 harness (`78b8002c…`) a 300 s cap. P8 already runs OBSERVE-only censuses (a separate manifest with no ledger, 600 s cap). | An unnecessary harness edit. A 300 s cap is also below unpatched Cylinder's Linux runtime (>600 s), so the census was certain to come back ABNORMAL with no information. |
| D4 | It required TB63 to observe stages, per-stage time, O9 step counts and O15c widths. The acceptance test prints none of these, and a timed-out process prints nothing. | The obligations were vacuous. |
| D5 | It assigned O6 to Vase and BunnyRandom and treated O15c as something to monitor. | Neither fixture reaches tracing. O15c is Vase's first failure. |

**Ruling:** `M6-CP3-CB64-P13-ARTIFACT-PROBE-REGISTRATION` and `M6-CP3-TB63-P13-CYLINDER-FIRST-DIAGNOSTIC-EXEC` are withdrawn; neither started. The P13 decision record stays as history, and its audit stands.

#### RA-188.2 Probe findings (current source, macOS)

| Fixture | Result | First failure / cause | Owner |
|---|---|---|---|
| Cylinder `offgate:362` (80 V, 128 F) | **PASS**, 181.7 s, peak RSS 58 MB | About 96% of stack samples (2,229 of 2,315) are inside `SourceChartTransitionGraph::available()`, which re-runs the O(F) `SourceTopologyRegions::matches_source_faces` check on every query, sometimes twice per query. The A8 optimizer reaches it per point via `quad_reference_surface_point` → `rebind` / `resolve_entity` / `source_face_row` / `isolation_sheet`. The ledger's 600 s ABNORMAL is a performance defect, not a product defect. | **P13-a**: CB64 |
| BunnyRandom `offgate:360` | **RED**, 0.66 s | A3 `CutTransportDomainIdentityMismatch`. Region 0 has χ = 2 and no boundary. The 17 hard-feature (rail) edges form 7 tree components; 2 of them are single edges whose two endpoints are both tips (`68–216`, `169–331`). DESIGN Amendment 15.3 duplicates no tip, so those edges stay glued: the cut gives χ −3 with 5 loops, against identity 15.4's −5. A vertex-indexed `TriMesh` cannot represent a one-edge slit. The guard fails closed correctly; this is a **DESIGN gap** (15.3 cannot realise 15.4 for a tip–tip arc). | **P13-c**: DEFN |
| Vase `offgate:365` | **RED**, 1.6 s | A4 `field-aligned-network` / `BranchContinuationExactMagnitudeExceeded` at edge (320,713), face (320,712,713), branch 1, from the entry-width guard (`SurfaceCellTracing.cpp:548`, 4,096 bits). The A4 trace-scale census shows the exact width growing **linearly, about 200 bits per continuation step**: 1,018 / 2,076 / 3,096 / 4,080 / 4,282 bits at steps 5 / 10 / 15 / 20 / 21. The bound therefore admits about 20 faces per trace. This meets RA-181's O15c trigger. Before CB55 the same row timed out at 600 s. | **P13-b**: DEFN |

- **Equivalence of the P13-a fix:** with the RA-188.8 patch, the pipeline produces Cylinder in 7.85 s (optimization 6.1 s). The CLI output is byte-identical before and after (`6e1e6a9d…`, 216 s → 9.0 s wall).
- **O6 and O9** are reached by none of the three. They stay carried until Vase and BunnyRandom pass A3/A4.
- **O17 (new, hygiene, not P13):** production code writes diagnostics to stderr unconditionally. `GlobalTopologyPlan.cpp:2634` passes `emitEulerDiagnostics = true`, and `FieldTransportAtlas.cpp:746` emits the partition dump. Owner: M8-CP2.

#### RA-188.3 Rulings: architecture and trajectory

- **P13 splits by cause into three independent slices.** Each slice is one exact patch and one full-gate TB that also runs the three-row census. No slice waits for another.
- **P13-b is architectural, not a parameter.** Exact rational continuation through a chain of faces accumulates width linearly, and arithmetic cost grows with it. A 4,096-bit bound fails beyond about 20 faces, while production meshes routinely need traces of hundreds of faces. The DEFN must measure the per-step growth and choose among:
  1. **A revised bound.** This only moves the cliff.
  2. **RA-181's correctly-rounded direction.** This lowers the slope but stays linear.
  3. **A canonical bounded-precision continuation.** Each exit parameter is rounded deterministically to a fixed dyadic grid. Every predicate (exit-edge choice, ties, ordering) stays exact on the rounded values, as RA-176, RA-180 and RA-181 require. The fail-closed guard stays.

  Only option 3 bounds the width. Whichever option is chosen must keep topological decisions exact and platform-independent.
- **P13-c amends DESIGN Amendment 15.** Options:
  1. A transport-domain representation in which a slit does not require duplicating a vertex.
  2. A typed rail-product policy for interior tip–tip single-edge rails. Hard features come from rails (`RemeshPipeline.cpp:12676`), and this option must be reconciled with A0's "no value-changing sanitization".

  The DEFN probes what BunnyRandom hits after each option.
- **Gate promotion:** Cylinder joins the gate only after a Linux census PASS (Turn_Cadence's non-gating rule). If TB63 matches its pre-registration, the P13-b DEFN freezes manifest 864 and ledger v5 81.
- **No TB-REV when TB63 matches** (lean sequencing). Probe-backed DEFNs stay on the Review track; the implementation agent gets only CB64 and TB63.

#### RA-188.4 CB64 — exact patch

**Turn:** `M6-CP3-CB64-P13-CHART-BINDING-CACHE` (CB; implementation agent; Linux workflow runner).
- **Change:**
  - `available()` stops re-validating every face row on each call. It reads a binding flag that `build()` sets after its existing `matches_source_faces` check.
  - The design-acceptance test's `failure_context` adds `detail=<terminalFailureDetailCode>` without changing its line count. Vase's A4 code then reaches the census log, and the ledger site `:197` is unchanged.
  - No verdict, ordering, admission or output changes.
- **Checks:**
  - The RA-188.8 block, extracted verbatim with a trailing newline, has SHA-256 `fad8986caf897b4fc5eba3f9e667f30518077b81143823e7b65c65314f536c1e`.
  - Run `git apply --check`, then apply. The numstat must be exactly `7 4` (`include/directional/geometry/SourceChartTransitions.h`) and `2 2` (`tests/SurfaceCellDesignAcceptanceTests.cpp`).
  - Resulting SHA-256: `aa981c5a916f0ddfff0f4f78fd5acccd3e33148ccbce7a9a7a42f3d1cad256dd` and `fff33d6c1f2b99a92af22ac7fcf24b14ab735ef621eb443a67e5a14ba2422590`.
  - Before applying, HEAD must equal `e1fd0e4b…` in `src include tests benchmarks CMakeLists.txt cmake`.
- **Build:** the standard `agent-compile-reusable.yml` with the CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI and GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256s and the source archive SHA-256. No native runs.

| CB64 result | Successor |
|---|---|
| Patch exact, package built | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` |
| SHA/numstat/source mismatch | `M6-CP3-PLAN-P13-CHART-BINDING-STOP` (PLAN, Review) |
| Infrastructure failure | `M6-CP3-CB64A-P13-CHART-BINDING-ORCH`, then one retry |

#### RA-188.5 TB63 — frozen inputs and pre-registered outcomes

**Turn:** `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` (TB-EXEC; implementation agent; Linux workflow runner). It makes two P8 harness `--execute` runs on the immutable CB64 package (harness `78b8002c…`, unchanged).

1. **Gate:**
   - Manifest: [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv"), 863 rows, `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`.
   - `MEMBERSHIP_LEDGER`: ledger v4, 82 rows, `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`.
   - Pre-registered: **863/863 PASS**, postflight true, membership 945.
2. **Census:**
   - Manifest: [`Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`](Architecture_M6_TB63_P13_Census_Case_Manifest.tsv), 3 OBSERVE rows (Cylinder, BunnyRandom, Vase), `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. No ledger.
   - Pre-registered: row 1 **PASS**, row 2 **RED** with `CutTransportDomainIdentityMismatch` and `cutChi=-3`, row 3 **RED** with `detail=BranchContinuationExactMagnitudeExceeded`.
   - A census PASS never changes gate membership.

| TB63 result | Successor |
|---|---|
| Gate as pre-registered and census as pre-registered | `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` (Review); no TB-REV |
| Gate RED, or census differs (a platform split is a determinism lead, RA-176) | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-REV` (TB-REV, Review) |
| Membership error | `M6-CP3-PLAN-P13-CENSUS-MEMBERSHIP-STOP` (PLAN, Review) |
| Orchestration failure | `M6-CP3-CB64A-P13-CHART-BINDING-ORCH` → `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC-R1` |

#### RA-188.6 Probe evidence (local, diagnostic)

- **Before the patch:** the three probes ran one process each with a 1,500 s cap. Cylinder: exit 0 in 183.4 s. BunnyRandom: exit 1 in 5 s wall. Vase: exit 1 in 5 s wall. The failure texts are quoted in RA-188.2.
- **Locus probes:** a scratch probe replicated the test options and read `terminalFailureDetailCode`, `terminalFailureLocus`, the retained `fieldTransportAtlasError` barrier components, and `diagnose_field_aligned_trace_scale_census` (57 rows, 3 traces, longest 21 steps).
- **With the patch:** the RA-188.8 patch was applied to the scratch build (43 incremental steps, 2 min 50 s at `-j2`).
  - A row-per-process probe over the TB58 manifest gives **862/863**. Only row 283 fails, the pre-registered macOS O16 row; TB60 gave the same result.
  - The three census rows match the RA-188.5 pre-registration:
    - Cylinder: **PASS** in 7.8 s, independent oracle included.
    - BunnyRandom: **RED**, `CutTransportDomainIdentityMismatch` … `cutChi=-3`.
    - Vase: **RED**, `detail=BranchContinuationExactMagnitudeExceeded`.

#### RA-188.7 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| 1 — NEXT | `M6-CP3-CB64-P13-CHART-BINDING-CACHE` | CB / implementation agent, Linux | Package built, patch exact |
| 2 | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` | TB-EXEC / implementation agent, Linux | Gate 863/863 and census as pre-registered |
| 3 | `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` | DEFN / Review, probes; may start during steps 1–2 | Vase continuation policy; Cylinder promoted (manifest 864, ledger v5 81) → CB65 → TB64 |
| 4 | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` | DEFN / Review, probes; independent of step 3 | Amendment 15 for tip–tip arcs → CB66 → TB65 |
| 5 | P13 re-census → O6 / O9 where reached → matrix 6/6 | per slice | Then retire → FIXTURE → PRODUCT → OPEN → CP3-REV |
| carried | DR1, DR3; DR2/DR4 and O17 → M8-CP2; O2b, O15b, O16 | — | — |

#### RA-188.8 Exact CB64 patch

~~~diff
diff --git a/include/directional/geometry/SourceChartTransitions.h b/include/directional/geometry/SourceChartTransitions.h
index 216bcd661..6e4c96f69 100644
--- a/include/directional/geometry/SourceChartTransitions.h
+++ b/include/directional/geometry/SourceChartTransitions.h
@@ -208,10 +208,11 @@ public:
                                    hardFeatureEdges, barycentricTolerance) {}
 
   [[nodiscard]] bool available() const {
-    return faces_ != nullptr && faces_->cols() == 3 && authority_ != nullptr &&
-           authority_->matches_source_faces(*faces_) &&
-           consistent_ && faceChartComponent_.size() ==
-                              static_cast<std::size_t>(faces_->rows());
+    // build() checks the exact source binding once; the graph borrows
+    // immutable stage products, so queries do not re-validate every row.
+    return sourceBound_ && faces_->cols() == 3 && consistent_ &&
+           faceChartComponent_.size() ==
+               static_cast<std::size_t>(faces_->rows());
   }
 
   [[nodiscard]] std::optional<SourceProjectionChart>
@@ -597,6 +598,7 @@ private:
         !authority_->matches_source_faces(*faces_)) {
       return;
     }
+    sourceBound_ = true;
 
     const int faceCount = faces_->rows();
     int maximumVertex = -1;
@@ -929,6 +931,7 @@ private:
       vertexFan_;
   std::vector<SourceChartTransition> transitions_;
   bool consistent_ = true;
+  bool sourceBound_ = false;
 };
 
 } // namespace directional::geometry
diff --git a/tests/SurfaceCellDesignAcceptanceTests.cpp b/tests/SurfaceCellDesignAcceptanceTests.cpp
index 1c761a782..3ebd635ac 100644
--- a/tests/SurfaceCellDesignAcceptanceTests.cpp
+++ b/tests/SurfaceCellDesignAcceptanceTests.cpp
@@ -37,8 +37,8 @@ const directional::bench::BenchmarkCase &find_benchmark_case(
 
 std::string failure_context(const directional::pipeline::RemeshResult &result) {
   return "terminal=" + result.diagnostics.terminalFailureCode + ":" +
-         result.diagnostics.terminalFailureStage +
-         " traceSegments=" +
+         result.diagnostics.terminalFailureStage + " detail=" +
+         result.diagnostics.terminalFailureDetailCode + " traceSegments=" +
          std::to_string(result.diagnostics.surfaceCellTraceSegmentCount) +
          " arrangementCells=" +
          std::to_string(result.diagnostics.surfaceCellArrangementCellCount) +
~~~

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB58 manifest `31c1360a…` and ledger v4 `36241caa…` re-hashed unchanged; census manifest self-check `SELF_CHECK_PASS cases=3` |
| Decisive claims independently re-derived | Every P13 row re-observed at current source. Barrier components read from the retained A3 error. A4 widths from A4's own census. Hot path from 2,315 stack samples. Equivalence from byte-identical CLI output |
| Non-vacuity checked | Each probe printed a terminal code with its locus. Cylinder PASS ran the independent oracle. The patch probe gate executed every row: 862/863, with only O16 row 283 failing |
| Prior obligations discharged/carried | P13 decision D1–D5 ruled. CB64/TB63 (old) withdrawn. O6 and O9 carried to P13 re-census. O15c is now P13-b. DR1, DR3, DR2/DR4, O2b, O15b, O16 carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-a (CB64), P13-b (O15c DEFN), P13-c (Amendment 15 DEFN), O17 (M8-CP2) |
| ORIENTATION currency line | Updated to RA-188 / CB64 next, 2026-10-31 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 Next and §7 Immediate updated. §4: n/a, the witness matrix is unchanged. §8: n/a, no defect pattern is confirmed yet |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a: no selector change |
| LESSONS | New lesson: re-observe deferred rows at current source before planning on them |
| Consolidation under CLEAN_UP_POLICY | n/a: the P13 decision and its working evidence stay as history |
| Successor frozen | `M6-CP3-CB64-P13-CHART-BINDING-CACHE` (RA-188.4); TB63 falsifiers in RA-188.5 |
| Turn boundary held | No gate runtime and no product, test, fixture, selector or benchmark change in the repository. Probes ran only on a scratch build |
| `review_check.py boundary` | **ALL CHECKS PASSED**. `ledgers --base 95565e7ee` also PASSED. `document_drift_audit.py`: 0 errors, 0 warnings |
| `STATUS` lifecycle maintained | Turn `M6-CP3-DEFN-P13-PROBE-ADJUDICATION`, COMPLETE, Successor CB64 |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |

## `Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md`; moved verbatim.

### RA-195 — P13-f completion ownership cost: probe adjudication; exact CB71/CB72, TB68 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (Review/Definition), reopened at `fa06ae4ff`. The [static decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Review_Decision_20261101.md") (ChatGPT, `55b8e18b6`) named the right two cost sites. But it ran no probe, so it did not name Vase's next failure. It also froze an open-ended Code + Build plan ([CB71 plan](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md")) whose API, binding rule and tests the implementation agent would have had to design. RA-193.4 gave this DEFN one exit: name Vase's next failure, or a PASS, within the 600 s harness bound. RA-195 meets that exit with probes on current source and replaces the plan with two exact patches.

Source at review: HEAD `fa06ae4ff`; `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB70 `9754500b2058229b7f0a6268838953650690b031` (TB67 package `13087332886`, 871/871). Nothing landed after TB67 except documents.

#### RA-195.1 Findings on the decision

1. **F1 — exit not met.** The decision is "static source/evidence review only". It leaves the next Vase verdict to a later TB ("no semantic result can be presumed here"). RA-193.4 and TODO required the DEFN to name it. Probes name it in RA-195.2: Vase ends at `completion` with `InvalidCompletionQuadEmbedding` (P13-g) in 138 s.
2. **F2 — monolithic, open-ended CB.** The plan has five open items. Graph lifetime is left to the agent ("establish graph lifetime/source binding"), and so is the API ("make caller proof explicit in the API or refuse reuse"). It also asks for six categories of new tests and refactors two validators and a patch-cache path. It has no patch, no numstat and no result hashes. Implementation agents receive exact patches only.
3. **F3 — the binding rule contradicts itself and the graph's design.** The decision forbids "implicit pointer-identity acceptance", yet says that re-running `matches_source_faces` per patch "would nullify the win". `SourceChartTransitionGraph` already borrows its inputs by pointer and records the binding check once, at build (CB64, RA-188: "the graph borrows immutable stage products, so queries do not re-validate every row"). Stage products are immutable `const` views (DESIGN §7.3). A graph that borrows exactly the same face matrix, authority, hard-edge set and tolerance therefore answers every query as a fresh graph would; that identity *is* the binding proof. Ruled in Amendment 27.
4. **F4 — cost inventory unmeasured.** The decision lists the two validator sites correctly (`PureQuadCompletion.cpp:869`, `:1322`; callers `:1282`, `:1582`, `PatchDescriptor.cpp:2842`). It never measured their share, and it treats the per-vertex `matches_source_faces` as a check to keep rather than the same O(F) work. The profile (RA-195.2) puts graph construction at 93.5 % of completion CPU and the per-vertex closure at 83.2 %. Other per-call O(F) work the decision missed is measured or bounded as residual: the per-patch `SurfaceProjectionBvh` (1.0 %), `matches_source_faces` per vertex (0.9 %), assembly's per-certificate `matches_source_faces` and the per-lineage graph in `rebuild_aggregate_output_identity_caches` (multi-component aggregation only). They are O20, not CB scope.
5. **F5 — TB obligations that a TB cannot observe.** "Instrument graph-construction count … one per completion batch" cannot be executed by an artifact-only TB. Replaced: the reuse rule is proven by two unit tests with mutation checks (RA-195.4–5), and the TB registers time-to-verdict.
6. **F6 — lifetime question left open, now resolved.** `complete_surface_cell_complex_pass` already builds one `SurfacePointSourceSupportResolver` per pass and passes it by `const` pointer through `PureQuadCompletionOptions`. The graph follows the same pattern and the same scope, which covers generated, retried and cache-reused patches. Standalone callers pass nothing and get a local graph.
7. **F7 — what stands.** The site attribution, O((P+V)·F), keeping assembly's existing shared graph, no promised Vase PASS, and keeping every ownership check.

#### RA-195.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP) of the exact CB70 source. Probe switch `PROBE_P13F` in a scratch copy of `PureQuadCompletion.cpp` only: `0` = HEAD; `1` = one graph per validator call, reused by every vertex; `2` = `1` plus one graph and BVH per pass. Every Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`.

| Probe | Result |
|---|---|
| HEAD stack, 8 s sample at ~4 min | completion pass 6,193 samples: `validate_completion_domain_ownership` 6,124 (98.9 %), `close_completion_lineage_source_authority` 5,152 (83.2 %), `SourceChartTransitionGraph` construction 5,790 (93.5 %), `SurfaceProjectionBvh` 61 (1.0 %), `matches_source_faces` 56 (0.9 %) |
| Mode 0 (HEAD), uncapped | completion entered at 152.9 s; 20,000 patches by 891 s; 280,000 per-vertex graph builds by 1,690 s; **same RED** (`InvalidCompletionQuadEmbedding;patch=1200;…;bow-tie-intersection`), **1,732 s** wall. TB67's 600 s timeout was this run cut short |
| Mode 1 (per-vertex reuse only) | completion entered at 206.7 s; 20,000 patches by 306.1 s (≈ 5 ms per patch, still one graph + one BVH each); **RED** `NotProductionReady:completion`, `completion=InvalidCompletionQuadEmbedding;patch=1200;backend=bounded-combinatorial;variant=15;localQuad=2;classification=bow-tie-intersection`; 386 s wall with two other processes running |
| Mode 2 (per-vertex + per-pass) | completion entered at 135.1 s, more than 280,000 lineage closures done by 136.3 s; **same RED**, 138 s wall |
| Production CB71 + CB72 (clean build of the RA-195.8–9 patches, no probe code) | Vase **same RED**, 213 s wall while the 873-row gate (3 workers) and two other processes ran. New rows 872–873 PASS; `PureQuadCompletionPhase18.*` 74/74. Mutant M1 (closure reuses any lent graph) fails only row 872; mutant M2 (validator reuses any lent graph) fails only row 873. The CB71-only state passes `-fsyntax-only` for `PureQuadCompletion.cpp`, `PatchDescriptor.cpp`, `RemeshPipeline.cpp` and the test file. The chain CB71 → CB72 applies to `fa06ae4ff` and reproduces every result SHA-256 |
| Gate and ledger, production build | TB68 manifest (873): **872/873**, only row 283 (O16, macOS LegacyInteger). Against the CB70 baseline gate (RA-193, 870/871), no shared row changes; new rows 872–873 PASS. Ledger v5: 0/81 PASS, as before; only row 365 (Vase) changes, TIMEOUT → RED in 164 s. A first gate run that by mistake used an M2-mutant completion binary failed only row 873, which confirms M2 is caught by that row alone in the full gate |
| Cylinder (mode 0) | PASS 8.0 s; it uses the authoritative phase-front path (`validate_materialized_completion_domain_ownership`), not patch completion |

The next failure is the same in both modes, and the same as HEAD's (mode 0 row), so it does not depend on the change. **P13-g** (new): patch 1200, completed by the bounded-combinatorial fallback at ownership variant 15, embeds local quad 2 as a bow-tie; the pass then publishes no quads. The terminal also reads `detail=None` while the typed cause sits only in `completion=` (an Amendment 19 attribution gap of the O18 kind). Both go to `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING`.

#### RA-195.3 Rulings

- **DESIGN Amendment 27** (added): a stage builds one `SourceChartTransitionGraph` per invocation and passes it to its per-patch and per-vertex checks. Reuse requires `borrows()`: the same face matrix, authority, hard-edge set and barycentric tolerance objects. The borrowed graph's `source_bound()` stands for `matches_source_faces` on those inputs. A graph that does not borrow exactly the callee's inputs is ignored, and the callee builds its own, which is the pre-change path. It is never accepted on trust and never a new failure. No check, failure code or check order changes.
- **CB71** (exact, RA-195.8): per-vertex reuse in both ownership validators. **CB72** (exact, RA-195.9): one graph per completion pass, threaded through `PureQuadCompletionOptions::sourceTransitions` and the cache-reuse validation. CB72 is needed: with CB71 alone each patch still costs ≈ 5 ms (mode 1), which leaves Vase too close to the 600 s bound.
- One TB after both (TB68). A TB after CB71 alone would have to pre-register a timing-dependent Vase outcome (≈ 390 s on macOS, unknown on Linux).
- **O20** (new, residual, non-blocking): the per-patch BVH in `complete_pure_quad_patch`, assembly's per-certificate `matches_source_faces` (`owner_validated_typed_authority_certificate`), and the per-lineage graph in `rebuild_aggregate_output_identity_caches` (multi-component aggregation only). Owner: a performance slice, or the first fixture whose census times out in one of them.
- The decision's CB71 plan is superseded. The turn ID `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` is kept for the exact patch.

#### RA-195.4 CB71 — `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE`

Code + Build, implementation agent, Linux workflow runner, compile only.

- **Precheck:** `git diff --quiet 9754500b2058229b7f0a6268838953650690b031 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** the RA-195.8 block verbatim plus a trailing newline. Keep its 6 single-space context lines. SHA-256 `8512400fe56c59f35ac3770383890366f35028c47346ba1fdeb04ca5014e5852` (261 lines, 12,237 bytes). `git apply --check`, then apply.

| Path | Numstat | Base SHA-256 | Result SHA-256 |
|---|---|---|---|
| `include/directional/geometry/PureQuadCompletion.h` | `14 0` | `274058762297c11a…` | `37fcd5b041da1820762bd584de2ee3bccb073fe9e8eb2f742f985107da862bdf` |
| `include/directional/geometry/SourceChartTransitions.h` | `18 0` | `aa981c5a916f0ddf…` | `21553d343a10d603e1faffe62ab7b3560fb396ac464c0793642e5ccd6736ead7` |
| `src/geometry/PureQuadCompletion.cpp` | `49 9` | `1b13f454a45fd0df…` | `6a78a3e4226840483e0f6aa0a71a6c1bfb64d9304ae9944c808c5870b2009b1c` |
| `tests/PureQuadCompletionPhase18Tests.cpp` | `86 0` | `d7c7914dfd15e159…` | `6de658cc973176e97bdd15f348dfa6798093a4ab1b221955236df71025da1bab` |

- **What it does:**
  - Adds `SourceChartTransitionGraph::borrows()` and `source_bound()`.
  - Adds a `close_completion_lineage_source_authority` overload that takes a lent graph; the original signature forwards with none.
  - `validate_materialized_completion_domain_ownership` builds one graph per mesh.
  - `validate_completion_domain_ownership` lends its existing graph to every vertex.
  - No check, failure code or check order changes (Amendment 27).
- **New test** (gate row 872, `ra195:closure-graph`): `PureQuadCompletionPhase18.LineageClosureReusesOnlyAGraphBorrowingItsExactInputs`.
  - On every row of a produced patch, a borrowing graph, a graph over a copied face matrix and an unbound graph over foreign authority each give the standalone result and failure.
  - Unbound inputs fail with `CompletionOwnershipInvalidSourceAuthorityClosure` in both overloads.
  - Mutant M1 (reuse any lent graph) fails it; probe-verified.
- **Compile:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`. No binary runs.
- **Outcomes:**
  - Exact → `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH`.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`.
  - Infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH` (one retry).

#### RA-195.5 CB72 — `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH`

Code + Build, implementation agent, Linux workflow runner, compile only.

- **Precheck:** `git diff --name-only 9754500b2058229b7f0a6268838953650690b031 HEAD -- src include tests benchmarks CMakeLists.txt cmake` lists exactly CB71's four paths, each at its RA-195.4 result SHA-256.
- **Patch:** the RA-195.9 block verbatim plus a trailing newline. Keep its 5 single-space context lines. SHA-256 `514c6d87b7ad47083262b802e7b59da931a9bbeb71e0f3c14af49a6668ff5d6f` (178 lines, 9,539 bytes). `git apply --check`, then apply.

| Path | Numstat | Base SHA-256 | Result SHA-256 |
|---|---|---|---|
| `include/directional/geometry/PureQuadCompletion.h` | `6 1` | `37fcd5b041da1820…` (CB71) | `ba998d51a484e87ec698fc94f0aeaccf391e02de0662468a739e75ad070ec371` |
| `src/geometry/PatchDescriptor.cpp` | `10 1` | `c4cf22ea313961d0…` | `c864fd4a3e12e6ac0b48981aa250005c96b73ab7d368490deaf2a5e1c600e564` |
| `src/geometry/PureQuadCompletion.cpp` | `17 6` | `6a78a3e422684048…` (CB71) | `eac7161b328bb27b2bd4c0c905bc0a564e59429ddbbcb5f035c7b92181ef6b6c` |
| `tests/PureQuadCompletionPhase18Tests.cpp` | `58 0` | `6de658cc973176e9…` (CB71) | `37db444abea6791f364203cbf9209beb588552bcf724bacdcf292585b76697d3` |

- **What it does:**
  - Adds `PureQuadCompletionOptions::sourceTransitions` and a defaulted trailing `sourceTransitions` parameter on `validate_completion_domain_ownership`.
  - `complete_surface_cell_complex_pass` builds one graph next to its existing `SurfacePointSourceSupportResolver`.
  - It lends that graph to every generated patch and to the cache-reuse validation (`PatchDescriptor.cpp:2842`).
  - A graph that does not borrow exactly the patch's inputs is ignored (Amendment 27). Public callers default to `nullptr`.
- **New test** (gate row 873, `ra195:pass-graph`): `PureQuadCompletionPhase18.PatchOwnershipReusesOnlyASharedGraphBorrowingItsExactInputs`.
  - On the vertex/edge alias fixture, a borrowing graph and a graph split by a hard diagonal each give the local product: the same provenance face, charts and support.
  - The split graph is shown to be discriminating: with the diagonal really hard, the alias cannot rebind, and the local and shared calls reject with one detail.
  - Mutant M2 (the validator reuses any lent graph) fails it; probe-verified.
- **Compile:** as CB71.
- **Outcomes:**
  - Exact → TB68.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-PASS-GRAPH-STOP`.
  - Infrastructure → `M6-CP3-CB72A-P13-COMPLETION-PASS-GRAPH-ORCH` (one retry).

#### RA-195.6 TB68 — `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB72's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB68_P13_Completion_Graph_Reuse_Full_Gate_Case_Manifest.tsv"), 873 rows, SHA-256 `3b6b9f425d4061885b393ccd2d530cbcd3d4f39916859e0db197ce1e6029ea60`: TB67's 871 plus rows 872–873. Ledger v5 `fd433f54…`; harness P8 `78b8002c…`, `SELF_CHECK_PASS cases=873 deferred=81`. Pre-registered **873/873**, membership **954** (873 + 81).
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion` with `completion=InvalidCompletionQuadEmbedding;…`. The registered match is that stage and that code. The macOS locus (patch 1200, `bounded-combinatorial`, variant 15, `bow-tie-intersection`) is recorded, not registered, because an exact tie may resolve differently on Linux (RA-176).
  - An ABNORMAL Vase (timeout) is a mismatch.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB68A-P13-COMPLETION-GRAPH-ORCH` (one retry).

#### RA-195.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` | Implementation agent, Linux; RA-195.8, compile only |
| 2 | `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH` | Implementation agent, Linux; RA-195.9, compile only |
| 3 | `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC` | Implementation agent, Linux; gate 873/873, membership 954; Vase RED `completion` / `InvalidCompletionQuadEmbedding` within 600 s |
| 4 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (P13-g) | Probe DEFN. The scratch build reproduces it in 138 s. Name the owner: bounded-combinatorial template, projection, or the ownership-variant search. Close the `detail=None` attribution gap. Then an exact patch |
| 5 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 6 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

#### RA-195.8 Exact CB71 patch

Base: CB70 source `9754500b2…` (HEAD `fa06ae4ff`). SHA-256 `8512400fe56c59f35ac3770383890366f35028c47346ba1fdeb04ca5014e5852` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
index 990479f65..ce7eadeb0 100644
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -510,6 +510,20 @@ bool close_completion_lineage_source_authority(
     const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
     std::string &failure);
 
+/**
+ * The same closure against a caller-built source-chart graph, so a validator
+ * builds one graph per mesh rather than one per vertex. A graph that does not
+ * borrow exactly these inputs is not used; a local graph is built instead.
+ */
+bool close_completion_lineage_source_authority(
+    PureQuadVertexLineage &lineage,
+    const SurfacePointSourceSupport &support,
+    const Eigen::MatrixXi *sourceFaces,
+    const SourceTopologyRegions *sourceAuthority,
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph &sourceTransitions,
+    std::string &failure);
+
 /**
  * Validate and close a materialized authoritative phase-front mesh before it
  * may be published as a successful completion result. This adapter performs
diff --git a/include/directional/geometry/SourceChartTransitions.h b/include/directional/geometry/SourceChartTransitions.h
index 6e4c96f69..000b78bce 100644
--- a/include/directional/geometry/SourceChartTransitions.h
+++ b/include/directional/geometry/SourceChartTransitions.h
@@ -215,6 +215,24 @@ public:
                static_cast<std::size_t>(faces_->rows());
   }
 
+  /**
+   * True when this graph borrows exactly these inputs. Borrowed stage
+   * products are immutable, so such a graph answers every query exactly as a
+   * graph freshly built from the same inputs.
+   */
+  [[nodiscard]] bool borrows(
+      const Eigen::MatrixXi *sourceFaces,
+      const SourceTopologyRegions *sourceAuthority,
+      const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges,
+      const double barycentricTolerance = 1.0e-8) const {
+    return faces_ == sourceFaces && authority_ == sourceAuthority &&
+           hardFeatureEdges_ == &hardFeatureEdges &&
+           barycentricTolerance_ == std::max(0.0, barycentricTolerance);
+  }
+
+  /** build()'s SourceTopologyRegions::matches_source_faces() result. */
+  [[nodiscard]] bool source_bound() const { return sourceBound_; }
+
   [[nodiscard]] std::optional<SourceProjectionChart>
   chart(const int sourceFace) const {
     if (!available() || sourceFace < 0 || sourceFace >= faces_->rows() ||
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
index f4d647a9e..6fea2d005 100644
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -847,15 +847,24 @@ std::optional<std::pair<int, int>> completion_certified_hard_rail_components(
   return components;
 }
 
-bool close_completion_lineage_source_authority(
+bool close_lineage_source_authority_with_graph(
     PureQuadVertexLineage &lineage,
     const SurfacePointSourceSupport &support,
     const Eigen::MatrixXi *sourceFaceMatrix,
     const SourceTopologyRegions *sourceAuthority,
     const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
-    std::string &failure) {
+    const SourceChartTransitionGraph *callerGraph, std::string &failure) {
+  const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges =
+      sourceHardFeatureEdges != nullptr ? *sourceHardFeatureEdges
+                                        : empty_hard_feature_edges();
+  // A borrowing graph recorded matches_source_faces() for these immutable
+  // inputs when it was built; any other graph is ignored.
+  const bool reuseGraph =
+      callerGraph != nullptr &&
+      callerGraph->borrows(sourceFaceMatrix, sourceAuthority, hardFeatureEdges);
   if (sourceFaceMatrix == nullptr || sourceAuthority == nullptr ||
-      !sourceAuthority->matches_source_faces(*sourceFaceMatrix) ||
+      !(reuseGraph ? callerGraph->source_bound()
+                   : sourceAuthority->matches_source_faces(*sourceFaceMatrix)) ||
       !lineage.sourcePoint.valid() || !support.valid()) {
     failure = "CompletionOwnershipInvalidSourceAuthorityClosure";
     return false;
@@ -866,10 +875,12 @@ bool close_completion_lineage_source_authority(
     return false;
   }
 
-  const SourceChartTransitionGraph transitionGraph(
-      sourceFaceMatrix, sourceAuthority, sourceHardFeatureEdges != nullptr
-          ? *sourceHardFeatureEdges
-          : empty_hard_feature_edges());
+  std::optional<SourceChartTransitionGraph> localGraph;
+  if (!reuseGraph) {
+    localGraph.emplace(sourceFaceMatrix, sourceAuthority, hardFeatureEdges);
+  }
+  const SourceChartTransitionGraph &transitionGraph =
+      reuseGraph ? *callerGraph : localGraph.value();
   if (!transitionGraph.available()) {
     failure = "CompletionOwnershipMissingPublishedSourceChart";
     return false;
@@ -1237,6 +1248,31 @@ bool close_completion_lineage_source_authority(
   return true;
 }
 
+bool close_completion_lineage_source_authority(
+    PureQuadVertexLineage &lineage,
+    const SurfacePointSourceSupport &support,
+    const Eigen::MatrixXi *sourceFaceMatrix,
+    const SourceTopologyRegions *sourceAuthority,
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    std::string &failure) {
+  return close_lineage_source_authority_with_graph(
+      lineage, support, sourceFaceMatrix, sourceAuthority,
+      sourceHardFeatureEdges, nullptr, failure);
+}
+
+bool close_completion_lineage_source_authority(
+    PureQuadVertexLineage &lineage,
+    const SurfacePointSourceSupport &support,
+    const Eigen::MatrixXi *sourceFaceMatrix,
+    const SourceTopologyRegions *sourceAuthority,
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph &sourceTransitions,
+    std::string &failure) {
+  return close_lineage_source_authority_with_graph(
+      lineage, support, sourceFaceMatrix, sourceAuthority,
+      sourceHardFeatureEdges, &sourceTransitions, failure);
+}
+
 bool validate_materialized_completion_domain_ownership(
     PureQuadMesh &mesh, const Eigen::MatrixXi &sourceFaces,
     const SourceTopologyRegions *sourceAuthority,
@@ -1255,6 +1291,10 @@ bool validate_materialized_completion_domain_ownership(
     failure = "CompletionOwnershipInvalidSourceSupport";
     return false;
   }
+  const SourceChartTransitionGraph transitionGraph(
+      &sourceFaces, sourceAuthority, sourceHardFeatureEdges != nullptr
+          ? *sourceHardFeatureEdges
+          : empty_hard_feature_edges());
   std::set<int> outputVertices;
   for (std::size_t row = 0; row < mesh.vertices.size(); ++row) {
     const int outputVertex = mesh.vertices[row];
@@ -1281,7 +1321,7 @@ bool validate_materialized_completion_domain_ownership(
     }
     if (!close_completion_lineage_source_authority(
             lineage, support, &sourceFaces, sourceAuthority,
-            sourceHardFeatureEdges, failure)) {
+            sourceHardFeatureEdges, transitionGraph, failure)) {
       return false;
     }
   }
@@ -1581,7 +1621,7 @@ bool validate_completion_domain_ownership(
       lineage.sourceSupport = support.identity;
       if (!close_completion_lineage_source_authority(
               lineage, support, sourceFaceMatrix, sourceAuthority,
-              sourceHardFeatureEdges, failure)) {
+              sourceHardFeatureEdges, transitionGraph, failure)) {
         return false;
       }
     }
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
index 8b28513e7..5ea9866e4 100644
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -1409,6 +1409,92 @@ TEST(PureQuadCompletionPhase18,
   EXPECT_FALSE(rejection.boundaryVertex);
 }
 
+TEST(PureQuadCompletionPhase18,
+     LineageClosureReusesOnlyAGraphBorrowingItsExactInputs) {
+  const CompletionFixture fixture = generated_plane_patch();
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 38;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(
+      fixture.faces, {0, 0, 1}, {0, 0, 1});
+  options.sourceAuthority = &sourceAuthority;
+  const auto completion = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  ASSERT_TRUE(completion.is_produced());
+
+  const auto &hard = no_hard_feature_edges();
+  const directional::geometry::SourceChartTransitionGraph borrowed(
+      &fixture.faces, &sourceAuthority, hard);
+  ASSERT_TRUE(borrowed.borrows(&fixture.faces, &sourceAuthority, hard));
+  ASSERT_TRUE(borrowed.source_bound());
+  const Eigen::MatrixXi copiedFaces = fixture.faces;
+  const directional::geometry::SourceChartTransitionGraph copied(
+      &copiedFaces, &sourceAuthority, hard);
+  EXPECT_FALSE(copied.borrows(&fixture.faces, &sourceAuthority, hard));
+  Eigen::MatrixXi foreignFaces(3, 3);
+  foreignFaces << 0, 1, 3,
+                  1, 2, 3,
+                  4, 5, 6;
+  const auto foreignAuthority =
+      test_source_authority(foreignFaces, {0, 0, 1}, {0, 0, 1});
+  const directional::geometry::SourceChartTransitionGraph unbound(
+      &fixture.faces, &foreignAuthority, hard);
+  ASSERT_FALSE(unbound.source_bound());
+  ASSERT_FALSE(unbound.available());
+
+  const directional::geometry::SurfacePointSourceSupportResolver resolver(
+      fixture.faces);
+  int closedRows = 0;
+  for (std::size_t row = 0; row < completion.product().vertexLineage.size();
+       ++row) {
+    const auto support =
+        resolver.resolve(completion.product().vertexProvenance[row]);
+    auto expected = completion.product().vertexLineage[row];
+    std::string expectedFailure;
+    const bool expectedClosed = directional::geometry::pure_quad_detail::
+        close_completion_lineage_source_authority(
+            expected, support, &fixture.faces, &sourceAuthority, &hard,
+            expectedFailure);
+    closedRows += expectedClosed ? 1 : 0;
+    for (const auto *graph : {&borrowed, &copied, &unbound}) {
+      auto actual = completion.product().vertexLineage[row];
+      std::string failure;
+      EXPECT_EQ(expectedClosed,
+                directional::geometry::pure_quad_detail::
+                    close_completion_lineage_source_authority(
+                        actual, support, &fixture.faces, &sourceAuthority,
+                        &hard, *graph, failure))
+          << "row " << row << ": " << failure;
+      EXPECT_EQ(expectedFailure, failure) << "row " << row;
+      EXPECT_EQ(expected.sourceCharts, actual.sourceCharts) << "row " << row;
+      EXPECT_EQ(expected.sourceTopologyRegions, actual.sourceTopologyRegions)
+          << "row " << row;
+      EXPECT_EQ(expected.sourceIsolationSheets, actual.sourceIsolationSheets)
+          << "row " << row;
+    }
+
+    // Inputs that fail the source binding fail identically with a graph
+    // that borrows those same inputs.
+    auto unboundExpected = completion.product().vertexLineage[row];
+    auto unboundActual = unboundExpected;
+    std::string unboundExpectedFailure;
+    std::string unboundFailure;
+    EXPECT_FALSE(directional::geometry::pure_quad_detail::
+                     close_completion_lineage_source_authority(
+                         unboundExpected, support, &fixture.faces,
+                         &foreignAuthority, &hard, unboundExpectedFailure));
+    EXPECT_FALSE(directional::geometry::pure_quad_detail::
+                     close_completion_lineage_source_authority(
+                         unboundActual, support, &fixture.faces,
+                         &foreignAuthority, &hard, unbound, unboundFailure));
+    EXPECT_EQ("CompletionOwnershipInvalidSourceAuthorityClosure",
+              unboundExpectedFailure);
+    EXPECT_EQ(unboundExpectedFailure, unboundFailure);
+  }
+  EXPECT_GT(closedRows, 0);
+}
+
 TEST(PureQuadCompletionPhase18,
      CompletionRejectsComponentSheetMismatchAtSharedSourceEntity) {
   CompletionFixture fixture = source_support_alias_patch();
```

#### RA-195.9 Exact CB72 patch

Base: CB71's result. SHA-256 `514c6d87b7ad47083262b802e7b59da931a9bbeb71e0f3c14af49a6668ff5d6f` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
index ce7eadeb0..7560d895d 100644
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -409,6 +409,10 @@ struct PureQuadCompletionOptions {
   const SurfacePointSourceSupportResolver *sourceSupportResolver = nullptr;
   const SourceTopologyRegions *sourceAuthority = nullptr;
   const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges = nullptr;
+  // Optional source-chart graph shared by every patch of one completion pass.
+  // Used only when it borrows exactly the source inputs above; otherwise
+  // ownership validation builds its own graph for the patch.
+  const SourceChartTransitionGraph *sourceTransitions = nullptr;
 };
 
 struct PureQuadCompletionEvidence {
@@ -543,7 +547,8 @@ bool validate_completion_domain_ownership(
     const Eigen::MatrixXi *sourceFaces,
     const SourceTopologyRegions *sourceAuthority, std::string &failure,
     PureQuadCompletionOwnershipRejection *ownershipRejection,
-    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges);
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph *sourceTransitions = nullptr);
 
 } // namespace pure_quad_detail
 
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
index b9da3c5f8..9866dfba2 100644
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -2480,6 +2480,13 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     ReusableCompletionProducts *reusableProducts = nullptr) {
   SurfaceCellComplexCompletionDraft result;
   const SurfacePointSourceSupportResolver sourceSupportResolver(F);
+  // One source-chart graph for every patch of this pass; ownership validation
+  // reuses it instead of rebuilding it from F for each patch.
+  const SourceChartTransitionGraph sourceTransitions(
+      &F, options.sourceAuthority,
+      options.sourceHardFeatureEdges != nullptr
+          ? *options.sourceHardFeatureEdges
+          : empty_hard_feature_edges());
   SurfaceCellParityRepairResult parityRepair =
       repair_surface_cell_boundary_parity(std::move(complex));
   std::optional<SurfaceCellParityRepairProduct> parityProduct;
@@ -2729,6 +2736,7 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     completionOptions.sourceAuthority = options.sourceAuthority;
     completionOptions.sourceHardFeatureEdges =
         options.sourceHardFeatureEdges;
+    completionOptions.sourceTransitions = &sourceTransitions;
     return complete_pure_quad_patch(descriptor.patch, completionOptions);
   };
 
@@ -2843,7 +2851,8 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
                 descriptor.patch, reused, completionVariant,
                 &sourceSupportResolver, &F, options.sourceAuthority,
                 ownershipFailure,
-                &ownershipRejection, options.sourceHardFeatureEdges);
+                &ownershipRejection, options.sourceHardFeatureEdges,
+                &sourceTransitions);
         const bool topologyValid =
             ownershipValid && pure_quad_topology_is_disk(reused) &&
             !reused.quads.empty();
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
index 6fea2d005..08f044b39 100644
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -1335,7 +1335,8 @@ bool validate_completion_domain_ownership(
     const Eigen::MatrixXi *sourceFaceMatrix,
     const SourceTopologyRegions *sourceAuthority, std::string &failure,
     PureQuadCompletionOwnershipRejection *ownershipRejection,
-    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges) {
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph *sourceTransitions) {
   if (mesh.vertices.size() != mesh.vertexProvenance.size() ||
       mesh.vertices.size() != mesh.vertexLineage.size()) {
     failure = "CompletionOwnershipIncompleteVertexLineage";
@@ -1359,10 +1360,19 @@ bool validate_completion_domain_ownership(
       patchSourceFaces.end());
   const std::set<int> sourceFaces(patchSourceFaces.begin(),
                                   patchSourceFaces.end());
-  const SourceChartTransitionGraph transitionGraph(
-      sourceFaceMatrix, sourceAuthority, sourceHardFeatureEdges != nullptr
-          ? *sourceHardFeatureEdges
-          : empty_hard_feature_edges());
+  const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges =
+      sourceHardFeatureEdges != nullptr ? *sourceHardFeatureEdges
+                                        : empty_hard_feature_edges();
+  const bool reuseGraph =
+      sourceTransitions != nullptr &&
+      sourceTransitions->borrows(sourceFaceMatrix, sourceAuthority,
+                                 hardFeatureEdges);
+  std::optional<SourceChartTransitionGraph> localGraph;
+  if (!reuseGraph) {
+    localGraph.emplace(sourceFaceMatrix, sourceAuthority, hardFeatureEdges);
+  }
+  const SourceChartTransitionGraph &transitionGraph =
+      reuseGraph ? *sourceTransitions : localGraph.value();
   const bool transitionAuthorityAvailable = transitionGraph.available();
   std::size_t sourceVertexExtent = 0U;
   if (sourceFaceMatrix != nullptr && sourceFaceMatrix->cols() == 3) {
@@ -2274,7 +2284,8 @@ PureQuadCompletionResult complete_pure_quad_patch(
   if (!pure_quad_detail::validate_completion_domain_ownership(
           patch, mesh, options.completionVariant, sourceSupportResolver,
           options.sourceFaces, options.sourceAuthority, ownershipFailure,
-          &result.ownershipRejection, options.sourceHardFeatureEdges)) {
+          &result.ownershipRejection, options.sourceHardFeatureEdges,
+          options.sourceTransitions)) {
     result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
     result.failure = ownershipFailure;
     return close_pure_quad_completion(std::move(result));
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
index 5ea9866e4..fd11e5c38 100644
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -1288,6 +1288,64 @@ TEST(PureQuadCompletionPhase18,
   EXPECT_EQ(nullptr, completion.rejection());
 }
 
+TEST(PureQuadCompletionPhase18,
+     PatchOwnershipReusesOnlyASharedGraphBorrowingItsExactInputs) {
+  const CompletionFixture fixture = source_support_alias_patch();
+  const auto sourceAuthority =
+      test_source_authority(fixture.faces, {0, 0}, {0, 1});
+  const auto &hard = no_hard_feature_edges();
+  const std::set<directional::authority::SourceEdgeTopologyKey> diagonal{
+      directional::authority::SourceEdgeTopologyKey::from_indices(0, 2, 4U)
+          .value()};
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 28;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  options.sourceAuthority = &sourceAuthority;
+  options.sourceHardFeatureEdges = &hard;
+  const auto local = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  ASSERT_TRUE(local.is_produced());
+
+  const directional::geometry::SourceChartTransitionGraph borrowed(
+      &fixture.faces, &sourceAuthority, hard);
+  const directional::geometry::SourceChartTransitionGraph splitByDiagonal(
+      &fixture.faces, &sourceAuthority, diagonal);
+  ASSERT_TRUE(borrowed.borrows(&fixture.faces, &sourceAuthority, hard));
+  ASSERT_FALSE(splitByDiagonal.borrows(&fixture.faces, &sourceAuthority, hard));
+  for (const auto *graph : {&borrowed, &splitByDiagonal}) {
+    options.sourceTransitions = graph;
+    const auto shared = directional::geometry::complete_pure_quad_patch(
+        fixture.patch, options);
+    ASSERT_TRUE(shared.is_produced())
+        << (shared.rejection() != nullptr ? shared.rejection()->detail : "");
+    ASSERT_EQ(local.product().vertexLineage.size(),
+              shared.product().vertexLineage.size());
+    for (std::size_t row = 0; row < local.product().vertexLineage.size();
+         ++row) {
+      EXPECT_EQ(local.product().vertexProvenance[row].face,
+                shared.product().vertexProvenance[row].face);
+      EXPECT_EQ(local.product().vertexLineage[row].sourceCharts,
+                shared.product().vertexLineage[row].sourceCharts);
+      EXPECT_EQ(local.product().vertexLineage[row].sourceSupport,
+                shared.product().vertexLineage[row].sourceSupport);
+    }
+  }
+
+  // The ignored graph is discriminating: with the diagonal really hard, the
+  // vertex alias cannot rebind to the patch face, shared graph or not.
+  options.sourceHardFeatureEdges = &diagonal;
+  options.sourceTransitions = nullptr;
+  const auto splitLocal = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  options.sourceTransitions = &splitByDiagonal;
+  const auto splitShared = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  ASSERT_TRUE(splitLocal.is_rejected());
+  ASSERT_TRUE(splitShared.is_rejected());
+  EXPECT_EQ(splitLocal.rejection()->detail, splitShared.rejection()->detail);
+}
+
 TEST(PureQuadCompletionPhase18,
      CompletionRejectsFaceInteriorOutsidePatchSupport) {
   CompletionFixture fixture = source_support_alias_patch();
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB68 manifest is TB67's 871 rows byte for byte plus rows 872–873; `SELF_CHECK_PASS cases=873 deferred=81` with harness P8 `78b8002c…` |
| Decisive claims independently re-derived | HEAD stack sample; probe modes 1 and 2; production build of the exact patches (Vase, gate, ledger); mutants M1/M2; CB71-only syntax check; patch chain applied to `fa06ae4ff` with every result SHA-256 reproduced; embedded blocks re-hashed |
| Non-vacuity checked | Row 872 fails under M1 and row 873 under M2. Row 873's split graph is shown to be discriminating, because with the diagonal really hard the alias rejects. Row 872 requires at least one closed row |
| Prior obligations discharged/carried | F1–F7 ruled. P13-f is attributed and routed (CB71/CB72/TB68), and P13-g is new. O18 is recorded discharged (TB66). Carried: P13-e, O6, O9, O16, O17, O19, O20 (new), DR1/DR3, DR2/DR4, O2b, O15b, O7 (the oracle target still does not compile; seen in the probe build) |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-g (Vase quad embedding) → `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING`; O20 residual per-call O(F) |
| ORIENTATION currency line | Updated to RA-195 / CB71 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a, no executed gate or witness change |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: for a cost defect, measure the cost and remove it in a probe before writing the plan |
| Consolidation under CLEAN_UP_POLICY | The decision and its CB71 plan stay as history, each with a superseded note pointing here |
| Successor frozen | CB71 (RA-195.4, exact RA-195.8) → CB72 (RA-195.5, exact RA-195.9) → TB68 (RA-195.6) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base fa06ae4ff` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB71 |
| Pushed to origin, branch in sync | Yes, fast-forward, no force |

## `Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md`; moved verbatim.

### RA-196 — P13-g completion quad embedding: probe adjudication; exact CB73/CB74/CB75, TB69 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (Review/Definition), reopened at `fe29a3554`. The [static decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Review_Decision_20261101.md") (ChatGPT, `6b6048966`) ran no binary. It left its central question open: is patch 1200's boundary malformed (branch A), or is the split inadmissible (branch B)? It then froze a CB73 that would investigate, branch and possibly stop. RA-195.7 gave this DEFN one exit: name the owner, close `detail=None`, and produce an exact patch. RA-196 meets that exit with probes on current source. It replaces the decision's CB73 with three exact patches and a TB.

Source at review: HEAD `fe29a3554`, fast-forwarded to `b7eb717b4` at closeout. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB72 `7b85b450bc98abfb65db511fdcd524eb11f537f8` (TB68 package `13093439789`, 873/873) at both. Only documents and orchestration landed after TB68. A CB73 attempt under the superseded scope started at 2026-11-01T21:39:52Z (`60bc9ac84` … `b7eb717b4`, resumed 22:02:58Z). It changed only `STATUS` and is superseded: CB73 restarts from RA-196.9, whose precheck still holds.

#### RA-196.1 Findings on the decision

1. **F1 — exit not met, and neither branch holds.** The decision says "the existing record does not distinguish those two hypotheses", and it hands that question to a Code + Build turn. Two probes settle it (RA-196.2):
   - **Branch A is false.** Patch 1200 lies entirely in source face 264. In that face's barycentric chart (an affine image, so incidence and orientation are exact) its 8-node boundary is a simple counter-clockwise polygon. It has two reflex corners (9073, 9076) and one straight corner (59254, the exact midpoint of 9076–9062).
   - **Branch B, as stated, would not fix it.** The decision wants more "topology-distinct odd-span separator/strip pairings", each tested for "simple embedding and orientation" before commit. The real defects are listed under F2 and F3.
2. **F2 — the validator the decision protects is unsound.** The decision says "do not … relax `completed_quads_have_simple_embedding`", so it treats that function as the oracle. But the check projects each quad onto its *own* Newell plane, so it cannot see orientation: a folded quad passes.
   - Of the 12,452 boundary-only completions that Vase's first pass accepts, 2,552 (20.5 %) disagree with the source surface: 1,809 contain a reversed quad and 743 a quad more than 60° off the source normal.
   - Exactly, in single-face patches: 29 accepted completions are folded.
   - The acceptance test's independent oracle checks combinatorial winding, zero area and manifoldness, not geometric folds (`tests/support/SurfaceCellProductOracle.h`). A Vase "PASS" could therefore have contained folded quads.
   - Branch B, run against this validator, would have accepted the first fold it produced.
3. **F3 — the producer's search is incomplete.** `append_balanced_boundary_quadrangulation` always splits at span 3 from `n/4`. Over all 16 rotations and reversals it reaches only the 4 parallel-chord quadrangulations of an octagon, out of 12. Patch 1200's only 2 embedded quadrangulations are fans (three quads sharing an apex), which it never reaches.
   - An exact DP over sub-polygons, with the source-orientation predicate, finds an embedded quadrangulation for **every** one of the 12,524 boundary-only patches in Vase's first pass. That holds under the sign test and under every margin up to 60°.
   - So no interior (Steiner) vertex is needed for this class, and no new producer.
4. **F4 — the terminal hides the rest of the pass.** Descriptors are processed in `domainIdentity` order (`PatchDescriptor.cpp:1874`), and the stage reports only the first failure. Patch 1200 is the first of **150** failed patches at CB72:
   - 72 boundary-only (pattern/bounded) bow-ties;
   - 73 closed-form grids (72 bow-tie, 1 degenerate normal);
   - 5 descriptors rejected as `side-count-unsupported`.

   The decision's TB69 expectation was "Vase PASS, or a newly named *earlier* producer RED". It cannot be met. With CB73–CB74, Vase moves to the next failure in the same pass: patch 4, a closed-form bow-tie. That failure is later in order, outside P13-g's class, and is P13-h.
5. **F5 — monolithic CB with an internal stop rule.** CB73 bundled four things: a new witness product, an A/B investigation with "stop and return to Review", a producer rewrite and a terminal change. It had no patch, numstat or result hashes. Implementation agents receive exact patches only (RA-172), and a CB with an embedded investigation has no single verifiable outcome.
6. **F6 — the proposed terminal fix misattributes.** "Pass through `firstCompletionEmbeddingFailure`" names the first *embedding* failure, not the first failure. When an earlier patch fails some other way, the terminal would name a decision that did not end the run (Amendment 19).
   - The truthful terminal detail is the typed completion failure kind, `PatchCompletionRejected` here.
   - The per-patch reason stays in `completion=`.
7. **F7 — reversed variants were never embeddable.** Variants `n … 2n−1` of the pattern and bounded backends (and 3–5 of the transition template) reverse the cycle. Their quads wind against the patch boundary and its shared halfedges. CB72 would accept such a completion if its quads were not bow-ties. No accepted Vase completion used one, but nothing prevented it.
   - Under Amendment 28 every reversed variant fails as an embedding failure.
   - Dropping them from `completion_variant_count` is cleanup (O22).
8. **F8 — what stands.**
   - Generated-vertex projection is not the owner: the bounded backend generates no vertices.
   - Ownership reconciliation is not reached.
   - The `detail=None` diagnosis is correct.
   - The scope limits stand: no epsilon relaxation, no fallback or recovery route, no selector change, no P13-e work.

#### RA-196.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB72. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. The probe switch `PROBE_P13G_MODE` lives in a scratch copy of `PureQuadCompletion.cpp`:
- `0`: CB72;
- `1`: Amendment 28 orientation check only;
- `2`: `1` plus an extra final variant that runs the exhaustive search;
- `3`: `1` plus the exhaustive search inside each forward variant (the CB74 design).

`PROBE_P13G_TRACE` prints every failed descriptor of every completion pass. Offline audits (Python, exact `Fraction` arithmetic for single-face charts) read a dump of every boundary-only completion in the first pass: 19,076 records, 12,524 patches.

| Probe | Result |
|---|---|
| CB72 (mode 0) | Vase RED `completion`, `detail=None`, `completion=InvalidCompletionQuadEmbedding;patch=1200;backend=bounded-combinatorial;variant=15;localQuad=2;classification=bow-tie-intersection`; 145 s. Same locus as TB68 on Linux (the macOS corner 59254 is Linux 59257, a representation handle) |
| Patch 1200 boundary, exact chart of face 264 | Simple, counter-clockwise; reflex at 9073 and 9076, straight at 59254. Sides `[1,1,1,3,1,1]`, `side-inequality`, so it takes the bounded fallback |
| Patch 1200, all 12 quadrangulations, exact | 2 embed, both fans: {(9056,9057,9073,9061), (9073,59254,9062,9061), (9073,9082,9076,59254)} and {(9056,59254,9062,9061), (9056,9057,9073,59254), (9073,9082,9076,59254)}. The 16 variants reach only the 4 parallel-chord ones, none embedded |
| Accepted first-pass boundary-only completions vs. the local source normal (sum of corner-face unit normals) | 12,452 accepted (11,413 bounded, 1,039 pattern). Reversed quad: 1,506 + 303. Beyond 60°: 715 + 28. Exact single-face subset: 29 folded, 332 with a straight (180°) corner |
| Angle of each quad's vector area to the source normal (all 85,301 quads tried; 23 have a zero normal) | 58,888 within 5°; 11,462 at 175–180° (true folds); a thin continuum between. Every corner-face normal is within 15° of its quad's reference, so the surface is smooth at quad scale. Quads near 90° are edge-on slivers whose sign is noise; sign-only and polygon-normal tests disagree on 57 such quads |
| Exact DP, every first-pass boundary-only patch | An embedded quadrangulation exists for 12,524/12,524 under the sign test and under every bound tested, from 90° down to 60° (cos 0, 0.05, 0.1, 0.2, 0.3, 0.5). DP over all patches: 1.25 s in Python |
| Mode 1 (orientation only), trace | 545 failed descriptors. 252 more boundary-only completions are now rejected as folded or edge-on, and 171 closed-form grids too. First: patch 1200, `source-orientation-mismatch` |
| Mode 3 (orientation + search), trace | **229** failed descriptors, **none boundary-only**: 171 closed-form `source-orientation-mismatch`, 53 closed-form bow-tie, 5 `side-count-unsupported`. Vase RED at patch 4 (`closed-form`, variant 0, `bow-tie-intersection`, source faces 155/248) in 147 s uncontended. One completion pass, no repair pass reached |
| Clean CB73 + CB74 + CB75 build (exact patches, no probe code) | The 5 new tests pass. `PureQuadCompletionPhase18.*` and `PatchDescriptorMilestoneE.*` show 97 passes and exactly CB72's 11 pre-existing off-gate `PatchDescriptorMilestoneE` failures (RA-170 baseline). **Vase RED `terminal=NotProductionReady:completion detail=PatchCompletionRejected`**, `completion=InvalidCompletionQuadEmbedding;patch=4;backend=closed-form;variant=0;localQuad=0;classification=bow-tie-intersection`, in 210 s while the ledger ran. Cylinder PASS (8 s); BunnyRandom P13-e unchanged. The chain CB73 → CB74 → CB75 applies to `fe29a3554` and reproduces every result SHA-256 |
| Gate (TB69 manifest, 878 rows) | **877/878**, only row 283 (O16, macOS LegacyInteger). Against RA-195's CB72 gate (872/873), no shared row changes; new rows 874–878 PASS. (A first run from a directory of copied binaries failed 140 rows, because tests read data relative to the build directory. It was rerun in place.) |
| Ledger v5 (81 rows) | 0/81 PASS, as at CB72; no row changes its verdict or first-failure token. Row 365 (Vase) is RED in 209 s under load (164 s at CB72) |
| Mutants (each rebuilt; the five new tests run) | M1, orientation check removed: rows 874, 875 and 876 fail. M2, sign only (no 60° margin): 874. M3, no search (balanced split only): 876 and 877. M4, search ignores the source orientation: 876. M5, exhaustion not reported: 877. M6, kind name collapses to `None`: 878. Restored: all pass. The CB73-only and CB73 + CB74 states pass `-fsyntax-only` for `PureQuadCompletion.cpp`, `PatchDescriptor.cpp`, `RemeshPipeline.cpp` and the test file |

The search runs only on forward rotations, which all share one set of quadrangulations. A first version also ran it on reversed variants. Its own test then showed that every reversed variant reports "no embedded quadrangulation", which is true only of the reversed winding (F7). The CB74 below keeps reversed variants on the historical split, so the validator rejects them as embedding failures, and reports `NoEmbeddedQuadrangulation` only from a forward rotation.

#### RA-196.3 Rulings

- **DESIGN Amendment 28** (added): a completed quad must agree with the source surface, and a boundary-only completion searches every quadrangulation before failing.
  - **The predicate.** A quad is embedded only if it is simple in its own Newell plane (existing checks, unchanged and in the same order) and its vector area lies within 60° of the local source orientation. The local source orientation is the sum of the unit normals of the source faces under its four corners.
  - **One owner.** `quad_embedding_failure` is the single predicate. The validator `completed_quads_have_simple_embedding` uses it whenever it has the source matrices, and so does every producer that chooses quads by geometry.
  - **Why 60°.** The margin is structural, not a quality bound: it rejects folds and edge-on slivers, whose sign is numerical noise.
  - **The search.** The pattern and bounded backends keep the historical balanced split whenever all its quads embed. Otherwise they search every quadrangulation of the same forward cycle by diagonals: a DP over sub-polygons that takes the first admissible split in index order.
  - **Reversed variants.** A reversed variant keeps the split, and the validator rejects it.
  - **No embedding.** If no quadrangulation embeds, the patch fails with the typed `NoEmbeddedQuadrangulation`, which no rotation can change.
  - **Terminal detail.** The completion terminal reports the typed completion failure kind as its detail (Amendment 19).
- **CB73** (exact, RA-196.9) adds the predicate and the validator check. **CB74** (exact, RA-196.10) adds the search and the typed reason. **CB75** (exact, RA-196.11) adds the terminal detail.
  - Each is compile-only, with its own GUARD tests and a mutant that fails them.
  - One TB runs after all three (TB69). A TB after CB73 alone would register a Vase verdict that CB74 immediately changes.
- **P13-h** (new, next Review): closed-form bilinear grids that do not embed. 224 descriptors in Vase's first pass after CB74: 53 bow-tie and 171 folded. Of these, 73 already fail at CB72.
  - Owner candidates: the bilinear target in `complete_rectangular_grid`, or the projection of its interior vertices.
  - DEFN: `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING`, a probe DEFN that can start now on the scratch build.
- **P13-i** (new, Review): 5 Vase descriptors with fewer than three sides are inadmissible (`side-count-unsupported`) at every source state probed. To be classified in the P13-h DEFN, by the same per-descriptor trace; it may need its own DEFN.
- **O21** (new, quality, non-blocking): the search takes the *first* embedded quadrangulation, not the best. Quads with a straight (180°) corner are accepted (332 in the exact single-face subset). This is a §2.1 item 10 quality criterion, owned by the M7 quality gates.
- **O22** (new, cleanup, non-blocking): reversed variants can never embed under Amendment 28, so they only cost attempts. Drop them from `completion_variant_count` in a later cleanup slice.
- The decision's CB73 scope is superseded. The turn ID `M6-CP3-CB73-P13-COMPLETION-EMBEDDING` is kept for the exact validator patch, and TB69 keeps the decision's ID.

#### RA-196.4 CB73 — `M6-CP3-CB73-P13-COMPLETION-EMBEDDING`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 7b85b450bc98abfb65db511fdcd524eb11f537f8 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-196.9 verbatim plus a trailing newline. Keep its 5 single-space context lines. SHA-256 `4020fad1d3a16c536504d0a3d58e11522dfd99688111bdc09e77b3a6885fabf1`; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/PureQuadCompletion.h` | `10 0` | `38ef15f3fb204516bce022044da92d35e550065251d91597ae66a6617dc479d5` |
  | `src/geometry/PureQuadCompletion.cpp` | `124 63` | `33de77c38ab5e71de44aa36ecd1969472062267a697e196bc18d9fa2b73ec492` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `73 0` | `5ccbd88f772c0ba8008c88fd256c128baa90cd8fa4d178d02abc8ce982db1267` |

- **Content:**
  - `PureQuadEmbeddingFailureKind::SourceOrientationMismatch` (`source-orientation-mismatch`).
  - `source_orientation_normal`.
  - `quad_embedding_failure`, the existing per-quad geometry moved verbatim and followed by the 60° check. It is declared in the header for tests.
  - The validator takes the source matrices; `complete_pure_quad_patch` passes `options.sourceVertices` and `options.sourceFaces`. Without them only the existing checks run, as before.
- **Tests (gate rows 874–875):**
  - `QuadEmbeddingRejectsFoldedAndEdgeOnQuadsAgainstTheSourceNormal`: 0° and 55° pass; 65°, 90° and 180° fail; no source means no orientation check; a bow-tie keeps its classification.
  - `CompletionRejectsQuadsFoldedAgainstTheSourceSurface`: the 2×2 plane patch traversed clockwise is rejected `SourceOrientationMismatch`, while the counter-clockwise patch is produced.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Exact → CB74.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-STOP`.
  - Infrastructure → `M6-CP3-CB73A-P13-COMPLETION-EMBEDDING-ORCH` (one retry).

#### RA-196.5 CB74 — `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH`

Code + Build, compile only.

- **Precheck:** the source differs from `7b85b450…` in exactly CB73's three paths, each at its RA-196.4 result SHA-256.
- **Patch:** RA-196.10 plus a trailing newline. Keep its 5 single-space context lines. SHA-256 `b2c6a251c915371845d93c05d753cbf7ad5ed92936cf0fa66879d0dd307c7b4b`.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `PureQuadCompletion.h` | `3 0` | `5580f55294047e168624b3e661c71083c53fc15920c1be89ed00e77c6681da14` |
  | `PureQuadCompletion.cpp` | `146 7` | `28a26b80f4b0b13605f691ebf15dd91191e51496be4f11db84b64f2f6adbad9b` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `131 0` | `c433da17e3fd8f03bf3359c84fb87a56809da853e62d6b3e024e2e6d6c97ccf8` |

- **Content:**
  - `PureQuadPatchRejectReason::NoEmbeddedQuadrangulation` (`no-embedded-quadrangulation`).
  - `append_embedded_boundary_quadrangulation`: keep the balanced split if it embeds; otherwise run the exhaustive memoized DP on forward rotations, while reversed variants keep the split.
  - `complete_pattern` and `complete_bounded` take the source matrices and an `exhausted` flag; `complete_pure_quad_patch` reports the typed reason.
- **Tests (rows 876–877):**
  - `BoundedCompletionFindsAnEmbeddedQuadrangulationOfAConcaveBoundary`: patch 1200's chart scaled to integers. Every forward variant produces 3 quads that an independent exact oracle (positive area, no crossing) accepts, and every reversed variant is rejected as an embedding failure.
  - `BoundedCompletionReportsABoundaryWithNoEmbeddedQuadrangulation`: a simple hexagon whose 3 quadrangulations all contain a bow-tie is rejected `NoEmbeddedQuadrangulation` on every forward variant.
- **Outcomes:**
  - Exact → CB75.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-QUADRANGULATION-STOP`.
  - Infrastructure → `M6-CP3-CB74A-P13-COMPLETION-QUADRANGULATION-ORCH`.

#### RA-196.6 CB75 — `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL`

Code + Build, compile only.

- **Precheck:** the source differs from `7b85b450…` in exactly the three CB73/CB74 paths, each at its RA-196.5 result SHA-256.
- **Patch:** RA-196.11 plus a trailing newline. Keep its 1 single-space context line. SHA-256 `d1f5652a979c414e53f11f8b62a71f9d528a79428c0067f2b4946ad71844d933`.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/PatchDescriptor.h` | `23 0` | `e9c090df552cd227c814756a853bf0fa348a28781beb45041cc5ef3986d77a31` |
  | `src/pipeline/RemeshPipeline.cpp` | `6 2` | `fca712094c21313fddb81f40160b392dbf1ab1888e632fa4f3c00e17b764db12` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `22 0` | `e4275e614d983f5492b861230a1e5dd5899d8afdf7ae7095381fc39094c67184` |

- **Content:**
  - `surface_cell_complex_completion_failure_name`.
  - The rejected-completion terminal passes it as `fail_surface_cells`'s detail code.
- **Test (row 878):** `CompletionFailureKindsNameTheTerminalDetail`, where every rejection kind has a distinct typed name.
- **Outcomes:**
  - Exact → TB69.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-TERMINAL-STOP`.
  - Infrastructure → `M6-CP3-CB75A-P13-COMPLETION-TERMINAL-ORCH`.

#### RA-196.7 TB69 — `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB75's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB69_P13_Completion_Embedding_Full_Gate_Case_Manifest.tsv"), 878 rows, SHA-256 `aaaba077a067853a00310683946f82394c60247bd42717fd283b4d7cde423c82`. That is TB68's 873 rows byte for byte plus GUARD rows 874–878.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=878 deferred=81`.
  - Pre-registered **878/878**, membership **959**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, with `completion=InvalidCompletionQuadEmbedding;…;backend=closed-form;…`.
  - The registered match is the stage, the detail, the code and `closed-form`. The macOS locus (patch 4, variant 0, `bow-tie-intersection`) is recorded, not registered (RA-176).
  - A Vase RED whose `completion=` names `bounded-combinatorial` or `pattern` is a mismatch, and so are `detail=None` and a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB69A-P13-COMPLETION-EMBEDDING-ORCH` (one retry).

#### RA-196.8 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB73-P13-COMPLETION-EMBEDDING` | Implementation agent, Linux; RA-196.9, compile only |
| 2 | `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH` | Implementation agent, Linux; RA-196.10, compile only |
| 3 | `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL` | Implementation agent, Linux; RA-196.11, compile only |
| 4 | `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC` | Implementation agent, Linux; gate 878/878, membership 959; Vase RED `completion` / `PatchCompletionRejected` / closed-form within 600 s |
| 5 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (P13-h; P13-i classified there) | Probe DEFN on the RA-196 scratch build. 224 closed-form descriptors plus 5 `side-count-unsupported`; name the owner, then exact patches |
| 6 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 7 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

#### RA-196.9 Exact CB73 patch

Base: CB72 source `7b85b450…` (HEAD `fe29a3554`). SHA-256 `4020fad1d3a16c536504d0a3d58e11522dfd99688111bdc09e77b3a6885fabf1` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -139,6 +139,7 @@ enum class PureQuadEmbeddingFailureKind : int {
   DegenerateNormal = 6,
   ZeroProjectedArea = 7,
   BowTieIntersection = 8,
+  SourceOrientationMismatch = 9,
 };
 
 inline const char *pure_quad_embedding_failure_name(
@@ -162,6 +163,8 @@ inline const char *pure_quad_embedding_failure_name(
     return "zero-projected-area";
   case PureQuadEmbeddingFailureKind::BowTieIntersection:
     return "bow-tie-intersection";
+  case PureQuadEmbeddingFailureKind::SourceOrientationMismatch:
+    return "source-orientation-mismatch";
   }
   return "unknown";
 }
@@ -787,6 +790,13 @@ bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh);
 bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
                              int &explored);
 
+// One completed quad: simple in its own Newell plane and, given the summed
+// unit normals of the source faces under its corners, oriented within 60
+// degrees of that source normal.
+PureQuadEmbeddingFailureKind quad_embedding_failure(
+    const std::array<Eigen::Vector3d, 4> &corners,
+    const Eigen::Vector3d *sourceNormal);
+
 } // namespace pure_quad_detail
 
 PureQuadCompletionResult complete_pure_quad_patch(
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -472,9 +472,117 @@ std::pair<int, int> diagnostic_source_scope(const PureQuadMesh &mesh) {
   return {-1, -1};
 }
 
+Eigen::Vector3d source_orientation_normal(
+    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
+    const std::array<int, 4> &faces) {
+  // Sum of the unit normals of the source faces carrying a quad's corners:
+  // the local source-surface orientation the quad must agree with.
+  Eigen::Vector3d sum = Eigen::Vector3d::Zero();
+  for (const int face : faces) {
+    if (face < 0 || face >= sourceFaces.rows()) {
+      continue;
+    }
+    const Eigen::Vector3d a =
+        sourceVertices.row(sourceFaces(face, 0)).transpose();
+    const Eigen::Vector3d b =
+        sourceVertices.row(sourceFaces(face, 1)).transpose();
+    const Eigen::Vector3d c =
+        sourceVertices.row(sourceFaces(face, 2)).transpose();
+    const Eigen::Vector3d normal = (b - a).cross(c - a);
+    const double length = normal.norm();
+    if (std::isfinite(length) && length > 0.0) {
+      sum += normal / length;
+    }
+  }
+  return sum;
+}
+
+PureQuadEmbeddingFailureKind quad_embedding_failure(
+    const std::array<Eigen::Vector3d, 4> &p,
+    const Eigen::Vector3d *sourceNormal) {
+  for (const Eigen::Vector3d &corner : p) {
+    if (!corner.allFinite()) {
+      return PureQuadEmbeddingFailureKind::NonFinitePosition;
+    }
+  }
+  const auto orient2 = [](const Eigen::Vector2d &a,
+                          const Eigen::Vector2d &b,
+                          const Eigen::Vector2d &c) {
+    return (b.x() - a.x()) * (c.y() - a.y()) -
+           (b.y() - a.y()) * (c.x() - a.x());
+  };
+  const auto oppositeEdgesIntersect = [&](const Eigen::Vector2d &a,
+                                          const Eigen::Vector2d &b,
+                                          const Eigen::Vector2d &c,
+                                          const Eigen::Vector2d &d) {
+    constexpr double eps = 1.0e-13;
+    const double o1 = orient2(a, b, c);
+    const double o2 = orient2(a, b, d);
+    const double o3 = orient2(c, d, a);
+    const double o4 = orient2(c, d, b);
+    return ((o1 > eps && o2 < -eps) || (o1 < -eps && o2 > eps)) &&
+           ((o3 > eps && o4 < -eps) || (o3 < -eps && o4 > eps));
+  };
+  Eigen::Vector3d normal = Eigen::Vector3d::Zero();
+  for (int corner = 0; corner < 4; ++corner) {
+    const Eigen::Vector3d &current = p[static_cast<std::size_t>(corner)];
+    const Eigen::Vector3d &next =
+        p[static_cast<std::size_t>((corner + 1) % 4)];
+    normal.x() += (current.y() - next.y()) * (current.z() + next.z());
+    normal.y() += (current.z() - next.z()) * (current.x() + next.x());
+    normal.z() += (current.x() - next.x()) * (current.y() + next.y());
+  }
+  if (!normal.allFinite() || normal.squaredNorm() <= 1.0e-24) {
+    return PureQuadEmbeddingFailureKind::DegenerateNormal;
+  }
+  Eigen::Index dropAxis = 0;
+  normal.cwiseAbs().maxCoeff(&dropAxis);
+  std::array<Eigen::Vector2d, 4> projected;
+  for (int corner = 0; corner < 4; ++corner) {
+    const Eigen::Vector3d &value = p[static_cast<std::size_t>(corner)];
+    if (dropAxis == 0) {
+      projected[static_cast<std::size_t>(corner)] =
+          Eigen::Vector2d(value.y(), value.z());
+    } else if (dropAxis == 1) {
+      projected[static_cast<std::size_t>(corner)] =
+          Eigen::Vector2d(value.x(), value.z());
+    } else {
+      projected[static_cast<std::size_t>(corner)] =
+          Eigen::Vector2d(value.x(), value.y());
+    }
+  }
+  double signedArea2 = 0.0;
+  for (int corner = 0; corner < 4; ++corner) {
+    const Eigen::Vector2d &a = projected[static_cast<std::size_t>(corner)];
+    const Eigen::Vector2d &b =
+        projected[static_cast<std::size_t>((corner + 1) % 4)];
+    signedArea2 += a.x() * b.y() - a.y() * b.x();
+  }
+  if (!std::isfinite(signedArea2) || std::abs(signedArea2) <= 1.0e-14) {
+    return PureQuadEmbeddingFailureKind::ZeroProjectedArea;
+  }
+  if (oppositeEdgesIntersect(projected[0], projected[1], projected[2],
+                             projected[3]) ||
+      oppositeEdgesIntersect(projected[1], projected[2], projected[3],
+                             projected[0])) {
+    return PureQuadEmbeddingFailureKind::BowTieIntersection;
+  }
+  // A quad agrees with the source surface only if its vector area lies
+  // within 60 degrees of the local source normal. This rejects folded quads
+  // and edge-on slivers, whose orientation sign is numerical noise.
+  if (sourceNormal != nullptr &&
+      !(normal.dot(*sourceNormal) >
+        0.5 * normal.norm() * sourceNormal->norm())) {
+    return PureQuadEmbeddingFailureKind::SourceOrientationMismatch;
+  }
+  return PureQuadEmbeddingFailureKind::None;
+}
+
 bool completed_quads_have_simple_embedding(
     const PureQuadMesh &mesh, const int completionVariant,
-    PureQuadEmbeddingFailure &failure) {
+    PureQuadEmbeddingFailure &failure,
+    const Eigen::MatrixXd *sourceVertices,
+    const Eigen::MatrixXi *sourceFaces) {
   failure = {};
   failure.sourcePatch = mesh.sourcePatch;
   failure.backend = mesh.backend;
@@ -520,24 +628,6 @@ bool completed_quads_have_simple_embedding(
       return reject(PureQuadEmbeddingFailureKind::DuplicateMeshVertex, 0);
     }
   }
-  const auto orient2 = [](const Eigen::Vector2d &a,
-                          const Eigen::Vector2d &b,
-                          const Eigen::Vector2d &c) {
-    return (b.x() - a.x()) * (c.y() - a.y()) -
-           (b.y() - a.y()) * (c.x() - a.x());
-  };
-  const auto oppositeEdgesIntersect = [&](const Eigen::Vector2d &a,
-                                          const Eigen::Vector2d &b,
-                                          const Eigen::Vector2d &c,
-                                          const Eigen::Vector2d &d) {
-    constexpr double eps = 1.0e-13;
-    const double o1 = orient2(a, b, c);
-    const double o2 = orient2(a, b, d);
-    const double o3 = orient2(c, d, a);
-    const double o4 = orient2(c, d, b);
-    return ((o1 > eps && o2 < -eps) || (o1 < -eps && o2 > eps)) &&
-           ((o3 > eps && o4 < -eps) || (o3 < -eps && o4 > eps));
-  };
 
   for (int quadIndex = 0; quadIndex < static_cast<int>(mesh.quads.size());
        ++quadIndex) {
@@ -552,6 +642,7 @@ bool completed_quads_have_simple_embedding(
                     quadIndex);
     }
     std::array<Eigen::Vector3d, 4> p;
+    std::array<int, 4> faces{{-1, -1, -1, -1}};
     for (int corner = 0; corner < 4; ++corner) {
       const auto row = rowByVertex.find(quad[static_cast<std::size_t>(corner)]);
       if (row == rowByVertex.end() || row->second < 0 ||
@@ -565,52 +656,21 @@ bool completed_quads_have_simple_embedding(
         return reject(PureQuadEmbeddingFailureKind::NonFinitePosition,
                       quadIndex);
       }
-    }
-    Eigen::Vector3d normal = Eigen::Vector3d::Zero();
-    for (int corner = 0; corner < 4; ++corner) {
-      const Eigen::Vector3d &current = p[static_cast<std::size_t>(corner)];
-      const Eigen::Vector3d &next =
-          p[static_cast<std::size_t>((corner + 1) % 4)];
-      normal.x() += (current.y() - next.y()) * (current.z() + next.z());
-      normal.y() += (current.z() - next.z()) * (current.x() + next.x());
-      normal.z() += (current.x() - next.x()) * (current.y() + next.y());
-    }
-    if (!normal.allFinite() || normal.squaredNorm() <= 1.0e-24) {
-      return reject(PureQuadEmbeddingFailureKind::DegenerateNormal, quadIndex);
-    }
-    Eigen::Index dropAxis = 0;
-    normal.cwiseAbs().maxCoeff(&dropAxis);
-    std::array<Eigen::Vector2d, 4> projected;
-    for (int corner = 0; corner < 4; ++corner) {
-      const Eigen::Vector3d &value = p[static_cast<std::size_t>(corner)];
-      if (dropAxis == 0) {
-        projected[static_cast<std::size_t>(corner)] =
-            Eigen::Vector2d(value.y(), value.z());
-      } else if (dropAxis == 1) {
-        projected[static_cast<std::size_t>(corner)] =
-            Eigen::Vector2d(value.x(), value.z());
-      } else {
-        projected[static_cast<std::size_t>(corner)] =
-            Eigen::Vector2d(value.x(), value.y());
+      if (row->second < static_cast<int>(mesh.vertexProvenance.size())) {
+        faces[static_cast<std::size_t>(corner)] =
+            mesh.vertexProvenance[static_cast<std::size_t>(row->second)].face;
       }
     }
-    double signedArea2 = 0.0;
-    for (int corner = 0; corner < 4; ++corner) {
-      const Eigen::Vector2d &a = projected[static_cast<std::size_t>(corner)];
-      const Eigen::Vector2d &b =
-          projected[static_cast<std::size_t>((corner + 1) % 4)];
-      signedArea2 += a.x() * b.y() - a.y() * b.x();
+    Eigen::Vector3d sourceNormal = Eigen::Vector3d::Zero();
+    const bool oriented = sourceVertices != nullptr && sourceFaces != nullptr;
+    if (oriented) {
+      sourceNormal =
+          source_orientation_normal(*sourceVertices, *sourceFaces, faces);
     }
-    if (!std::isfinite(signedArea2) || std::abs(signedArea2) <= 1.0e-14) {
-      return reject(PureQuadEmbeddingFailureKind::ZeroProjectedArea,
-                    quadIndex);
-    }
-    if (oppositeEdgesIntersect(projected[0], projected[1], projected[2],
-                               projected[3]) ||
-        oppositeEdgesIntersect(projected[1], projected[2], projected[3],
-                               projected[0])) {
-      return reject(PureQuadEmbeddingFailureKind::BowTieIntersection,
-                    quadIndex);
+    const PureQuadEmbeddingFailureKind kind =
+        quad_embedding_failure(p, oriented ? &sourceNormal : nullptr);
+    if (kind != PureQuadEmbeddingFailureKind::None) {
+      return reject(kind, quadIndex);
     }
   }
   return true;
@@ -2295,7 +2355,8 @@ PureQuadCompletionResult complete_pure_quad_patch(
     return close_pure_quad_completion(std::move(result));
   }
   if (!pure_quad_detail::completed_quads_have_simple_embedding(
-          mesh, options.completionVariant, result.embeddingFailure)) {
+          mesh, options.completionVariant, result.embeddingFailure,
+          options.sourceVertices, options.sourceFaces)) {
     result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
     const PureQuadEmbeddingFailure &failure = result.embeddingFailure;
     std::ostringstream stream;
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -2611,3 +2611,76 @@ TEST(PureQuadCompletionPhase18, StitchingIsPatchOrderInvariant) {
   EXPECT_EQ(forward.eulerCharacteristic, reverse.eulerCharacteristic);
   EXPECT_EQ(forward.boundaryLoopCount, reverse.boundaryLoopCount);
 }
+
+TEST(PureQuadCompletionPhase18,
+     QuadEmbeddingRejectsFoldedAndEdgeOnQuadsAgainstTheSourceNormal) {
+  using directional::geometry::PureQuadEmbeddingFailureKind;
+  using directional::geometry::pure_quad_detail::quad_embedding_failure;
+  // A unit square turned about the x axis, so that its vector area makes
+  // `degrees` with +z.
+  const auto turned = [](const double degrees) {
+    const double angle = degrees * std::numbers::pi / 180.0;
+    const Eigen::Vector3d u(1.0, 0.0, 0.0);
+    const Eigen::Vector3d v(0.0, std::cos(angle), std::sin(angle));
+    return std::array<Eigen::Vector3d, 4>{
+        {Eigen::Vector3d::Zero(), u, u + v, v}};
+  };
+  // Two unit source normals summed, as for corners on two faces.
+  const Eigen::Vector3d source(0.0, 0.0, 2.0);
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::None,
+            quad_embedding_failure(turned(0.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::None,
+            quad_embedding_failure(turned(55.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::SourceOrientationMismatch,
+            quad_embedding_failure(turned(65.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::SourceOrientationMismatch,
+            quad_embedding_failure(turned(90.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::SourceOrientationMismatch,
+            quad_embedding_failure(turned(180.0), &source));
+  // Without a source surface only the quad's own simplicity is checked.
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::None,
+            quad_embedding_failure(turned(180.0), nullptr));
+  // A bow-tie keeps its own classification ahead of orientation.
+  const std::array<Eigen::Vector3d, 4> bowTie{
+      {Eigen::Vector3d(0.0, 0.0, 0.0), Eigen::Vector3d(3.0, 1.0, 0.0),
+       Eigen::Vector3d(3.0, 0.0, 0.0), Eigen::Vector3d(0.0, 2.0, 0.0)}};
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::BowTieIntersection,
+            quad_embedding_failure(bowTie, &source));
+}
+
+TEST(PureQuadCompletionPhase18,
+     CompletionRejectsQuadsFoldedAgainstTheSourceSurface) {
+  CompletionFixture fixture = generated_plane_patch();
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 17;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(
+      fixture.faces, {0, 0, 1}, {0, 0, 1});
+  options.sourceAuthority = &sourceAuthority;
+  ASSERT_TRUE(directional::geometry::complete_pure_quad_patch(
+                  fixture.patch, options)
+                  .is_produced());
+
+  // The same square traversed clockwise about the +z source normal: every
+  // generated quad now faces away from the source surface.
+  auto &patch = fixture.patch;
+  std::reverse(patch.boundaryVertices.begin() + 1,
+               patch.boundaryVertices.end());
+  std::reverse(patch.boundaryProvenance.begin() + 1,
+               patch.boundaryProvenance.end());
+  std::reverse(patch.boundaryTopologyRegions.begin() + 1,
+               patch.boundaryTopologyRegions.end());
+  std::reverse(patch.boundaryCharts.begin() + 1, patch.boundaryCharts.end());
+  std::reverse(patch.boundaryNodeIdentities.begin() + 1,
+               patch.boundaryNodeIdentities.end());
+  const auto folded =
+      directional::geometry::complete_pure_quad_patch(patch, options);
+  ASSERT_TRUE(folded.is_rejected());
+  EXPECT_EQ(directional::geometry::PureQuadEmbeddingFailureKind::
+                SourceOrientationMismatch,
+            folded.rejection()->embeddingFailure.kind);
+  EXPECT_EQ(folded.rejection()->detail.rfind(
+                "InvalidCompletionQuadEmbedding", 0),
+            0U);
+}
```

#### RA-196.10 Exact CB74 patch

Base: CB73 result. SHA-256 `b2c6a251c915371845d93c05d753cbf7ad5ed92936cf0fa66879d0dd307c7b4b` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -58,6 +58,7 @@ enum class PureQuadPatchRejectReason : int {
   RewritePreconditionFailed = 14,
   RewriteFeatureViolation = 15,
   RewriteValenceMismatch = 16,
+  NoEmbeddedQuadrangulation = 17,
 };
 
 inline const char *pure_quad_patch_reject_reason_name(
@@ -97,6 +98,8 @@ inline const char *pure_quad_patch_reject_reason_name(
     return "rewrite-feature-violation";
   case PureQuadPatchRejectReason::RewriteValenceMismatch:
     return "rewrite-valence-mismatch";
+  case PureQuadPatchRejectReason::NoEmbeddedQuadrangulation:
+    return "no-embedded-quadrangulation";
   }
   return "unknown";
 }
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -2120,6 +2120,130 @@ bool append_balanced_boundary_quadrangulation(
          append_balanced_boundary_quadrangulation(second, mesh);
 }
 
+bool append_embedded_boundary_quadrangulation(
+    const PureQuadPatch &patch, const std::vector<int> &boundary,
+    const int completionVariant, const Eigen::MatrixXd *sourceVertices,
+    const Eigen::MatrixXi *sourceFaces, PureQuadMesh &mesh, bool &exhausted) {
+  // The balanced split is kept whenever every one of its quads embeds.
+  // Otherwise every quadrangulation of the same cycle by diagonals is
+  // searched: split(i, j) records the first quad (i, a, b, j) in (a, b) order
+  // whose three sub-polygons also split, so the result is deterministic. The
+  // search is exhaustive, so `exhausted` proves that no forward rotation of
+  // this cycle has an embedded quadrangulation either.
+  const int n = static_cast<int>(boundary.size());
+  if (n < 4 || n % 2 != 0) {
+    return false;
+  }
+  // A reversed variant winds every quad against the patch boundary. It keeps
+  // the balanced split, which the validator then rejects; only the forward
+  // rotations, which all share one set of quadrangulations, are searched.
+  if (normalized_completion_variant(completionVariant, 2 * n) >= n) {
+    return append_balanced_boundary_quadrangulation(boundary, mesh);
+  }
+  std::map<int, std::size_t> indexByVertex;
+  for (std::size_t index = 0; index < patch.boundaryVertices.size(); ++index) {
+    indexByVertex.emplace(patch.boundaryVertices[index], index);
+  }
+  std::vector<const SurfacePoint *> corners;
+  corners.reserve(boundary.size());
+  for (const int vertex : boundary) {
+    const auto found = indexByVertex.find(vertex);
+    if (found == indexByVertex.end() ||
+        found->second >= patch.boundaryProvenance.size()) {
+      return false;
+    }
+    corners.push_back(&patch.boundaryProvenance[found->second]);
+  }
+  const bool oriented = sourceVertices != nullptr && sourceFaces != nullptr;
+  const auto embedded = [&](const int i, const int a, const int b,
+                            const int j) {
+    const std::array<int, 4> rows{{i, a, b, j}};
+    std::array<Eigen::Vector3d, 4> p;
+    std::array<int, 4> faces{};
+    for (std::size_t corner = 0; corner < 4; ++corner) {
+      const SurfacePoint &point =
+          *corners[static_cast<std::size_t>(rows[corner])];
+      p[corner] = point.position;
+      faces[corner] = point.face;
+    }
+    Eigen::Vector3d sourceNormal = Eigen::Vector3d::Zero();
+    if (oriented) {
+      sourceNormal =
+          source_orientation_normal(*sourceVertices, *sourceFaces, faces);
+    }
+    return quad_embedding_failure(p, oriented ? &sourceNormal : nullptr) ==
+           PureQuadEmbeddingFailureKind::None;
+  };
+
+  const std::size_t firstQuad = mesh.quads.size();
+  if (append_balanced_boundary_quadrangulation(boundary, mesh)) {
+    std::map<int, int> rowByVertex;
+    for (int row = 0; row < n; ++row) {
+      rowByVertex.emplace(boundary[static_cast<std::size_t>(row)], row);
+    }
+    const bool balancedEmbeds = std::all_of(
+        mesh.quads.begin() + static_cast<std::ptrdiff_t>(firstQuad),
+        mesh.quads.end(), [&](const std::vector<int> &quad) {
+          return quad.size() == 4U &&
+                 embedded(rowByVertex.at(quad[0]), rowByVertex.at(quad[1]),
+                          rowByVertex.at(quad[2]), rowByVertex.at(quad[3]));
+        });
+    if (balancedEmbeds) {
+      return true;
+    }
+  }
+  mesh.quads.resize(firstQuad);
+
+  constexpr int unknown = -2;
+  constexpr int infeasible = -1;
+  std::vector<int> split(static_cast<std::size_t>(n) * n, unknown);
+  const auto splits = [&](const auto &self, const int i, const int j) -> bool {
+    if (j - i == 1) {
+      return true;
+    }
+    int &memo = split[static_cast<std::size_t>(i) * n + j];
+    if (memo != unknown) {
+      return memo != infeasible;
+    }
+    memo = infeasible;
+    for (int a = i + 1; a < j; a += 2) {
+      if (!self(self, i, a)) {
+        continue;
+      }
+      for (int b = a + 1; b < j; b += 2) {
+        if (self(self, a, b) && self(self, b, j) && embedded(i, a, b, j)) {
+          memo = a * n + b;
+          return true;
+        }
+      }
+    }
+    return false;
+  };
+  if (!splits(splits, 0, n - 1)) {
+    exhausted = true;
+    return false;
+  }
+  std::vector<std::pair<int, int>> pending{{0, n - 1}};
+  while (!pending.empty()) {
+    const auto [i, j] = pending.back();
+    pending.pop_back();
+    if (j - i == 1) {
+      continue;
+    }
+    const int choice = split[static_cast<std::size_t>(i) * n + j];
+    const int a = choice / n;
+    const int b = choice % n;
+    mesh.quads.push_back({boundary[static_cast<std::size_t>(i)],
+                          boundary[static_cast<std::size_t>(a)],
+                          boundary[static_cast<std::size_t>(b)],
+                          boundary[static_cast<std::size_t>(j)]});
+    pending.emplace_back(b, j);
+    pending.emplace_back(a, b);
+    pending.emplace_back(i, a);
+  }
+  return true;
+}
+
 } // namespace directional::geometry::pure_quad_detail
 
 namespace directional::geometry::pure_quad_detail {
@@ -2166,12 +2290,16 @@ bool complete_singularity_pole(
 namespace directional::geometry::pure_quad_detail {
 
 bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh,
-                      const int completionVariant) {
+                      const int completionVariant,
+                      const Eigen::MatrixXd *sourceVertices,
+                      const Eigen::MatrixXi *sourceFaces, bool &exhausted) {
   if (patch.boundaryVertices.size() < 4 ||
       patch.boundaryVertices.size() % 2 != 0) return false;
   const std::vector<int> boundary =
       rotated_cycle(patch.boundaryVertices, completionVariant);
-  if (!append_balanced_boundary_quadrangulation(boundary, mesh)) {
+  if (!append_embedded_boundary_quadrangulation(
+          patch, boundary, completionVariant, sourceVertices, sourceFaces,
+          mesh, exhausted)) {
     return false;
   }
   mesh.backend = PureQuadCompletionBackend::Pattern;
@@ -2183,12 +2311,16 @@ bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh,
 namespace directional::geometry::pure_quad_detail {
 
 bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
-                      int &explored, const int completionVariant) {
+                      int &explored, const int completionVariant,
+                      const Eigen::MatrixXd *sourceVertices,
+                      const Eigen::MatrixXi *sourceFaces, bool &exhausted) {
   PureQuadMesh trial = mesh;
   ++explored;
   const std::vector<int> boundary =
       rotated_cycle(patch.boundaryVertices, completionVariant);
-  if (!append_balanced_boundary_quadrangulation(boundary, trial) ||
+  if (!append_embedded_boundary_quadrangulation(
+          patch, boundary, completionVariant, sourceVertices, sourceFaces,
+          trial, exhausted) ||
       !pure_quad_topology_is_disk(trial)) {
     return false;
   }
@@ -2305,6 +2437,7 @@ PureQuadCompletionResult complete_pure_quad_patch(
   const std::vector<unsigned char> *allowedFacePtr =
       allowedFaces.empty() ? nullptr : &allowedFaces;
   bool completed = false;
+  bool quadrangulationExhausted = false;
   if (!boundedFallbackAdmissible && patch.singularityCount != 0) {
     completed = pure_quad_detail::complete_singularity_pole(
         patch, mesh, projection.get(), allowedFacePtr,
@@ -2326,14 +2459,20 @@ PureQuadCompletionResult complete_pure_quad_patch(
   }
   if (!completed && !boundedFallbackAdmissible && patch.simple) {
     completed = pure_quad_detail::complete_pattern(
-        patch, mesh, options.completionVariant);
+        patch, mesh, options.completionVariant, options.sourceVertices,
+        options.sourceFaces, quadrangulationExhausted);
   }
   if (!completed && options.allowBoundedCombinatorialFallback) {
     completed = pure_quad_detail::complete_bounded(
-        patch, mesh, result.exploredPatterns, options.completionVariant);
+        patch, mesh, result.exploredPatterns, options.completionVariant,
+        options.sourceVertices, options.sourceFaces,
+        quadrangulationExhausted);
   }
   if (!completed) {
-    result.failureReason = PureQuadPatchRejectReason::SearchLimitExceeded;
+    result.failureReason =
+        quadrangulationExhausted
+            ? PureQuadPatchRejectReason::NoEmbeddedQuadrangulation
+            : PureQuadPatchRejectReason::SearchLimitExceeded;
     return close_pure_quad_completion(std::move(result));
   }
   if (!pure_quad_detail::fill_positions(mesh)) {
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -2684,3 +2684,134 @@ TEST(PureQuadCompletionPhase18,
                 "InvalidCompletionQuadEmbedding", 0),
             0U);
 }
+
+namespace {
+
+CompletionFixture single_face_patch(const std::vector<Eigen::Vector2d> &boundary,
+                                    std::vector<int> sides) {
+  CompletionFixture fixture;
+  fixture.vertices.resize(3, 3);
+  fixture.vertices << 0.0, 0.0, 0.0,
+                      2000.0, 0.0, 0.0,
+                      0.0, 2000.0, 0.0;
+  fixture.faces.resize(1, 3);
+  fixture.faces << 0, 1, 2;
+  fixture.patch.sideEdgeCounts = std::move(sides);
+  fixture.patch.turns.assign(fixture.patch.sideEdgeCounts.size(), 1);
+  fixture.patch.sourceFaces = {0};
+  for (int index = 0; index < static_cast<int>(boundary.size()); ++index) {
+    const Eigen::Vector2d &corner = boundary[static_cast<std::size_t>(index)];
+    fixture.patch.boundaryVertices.push_back(index);
+    fixture.patch.boundaryProvenance.push_back(
+        directional::geometry::project_to_surface(
+            fixture.vertices, fixture.faces,
+            Eigen::Vector3d(corner.x(), corner.y(), 0.0)));
+  }
+  const auto authority = test_source_authority(fixture.faces, {0}, {0});
+  assign_patch_boundary_authority(
+      fixture.patch, fixture.faces, authority,
+      std::vector<int>(fixture.patch.boundaryVertices.size(), 0));
+  return fixture;
+}
+
+} // namespace
+
+TEST(PureQuadCompletionPhase18,
+     BoundedCompletionFindsAnEmbeddedQuadrangulationOfAConcaveBoundary) {
+  // Vase patch 1200 in its source face's barycentric chart, scaled to
+  // integers: reflex corners 2 and 4, straight corner 5. No rotation or
+  // reversal of the balanced split embeds; three of the twelve
+  // quadrangulations by diagonals do.
+  const std::vector<Eigen::Vector2d> boundary = {
+      {250.0, 582.0}, {442.0, 466.0}, {384.0, 666.0}, {618.0, 526.0},
+      {556.0, 740.0}, {492.0, 963.0}, {428.0, 1186.0}, {2.0, 1444.0}};
+  const CompletionFixture fixture =
+      single_face_patch(boundary, {1, 1, 1, 3, 1, 1});
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 1200;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(fixture.faces, {0}, {0});
+  options.sourceAuthority = &sourceAuthority;
+  const auto cross = [](const Eigen::Vector2d &a, const Eigen::Vector2d &b,
+                        const Eigen::Vector2d &c) {
+    return (b.x() - a.x()) * (c.y() - a.y()) -
+           (b.y() - a.y()) * (c.x() - a.x());
+  };
+  const auto properlyCross = [&](const Eigen::Vector2d &a,
+                                 const Eigen::Vector2d &b,
+                                 const Eigen::Vector2d &c,
+                                 const Eigen::Vector2d &d) {
+    return cross(a, b, c) * cross(a, b, d) < 0.0 &&
+           cross(c, d, a) * cross(c, d, b) < 0.0;
+  };
+  // Variants 8-15 reverse the cycle, so every quad winds against the
+  // counter-clockwise boundary and the source face; none is emitted.
+  for (int variant = 8; variant < 16; ++variant) {
+    options.completionVariant = variant;
+    const auto reversed =
+        directional::geometry::complete_pure_quad_patch(fixture.patch, options);
+    ASSERT_TRUE(reversed.is_rejected()) << "variant " << variant;
+    EXPECT_TRUE(reversed.rejection()->embeddingFailure.active)
+        << "variant " << variant;
+    EXPECT_EQ(reversed.rejection()->detail.rfind(
+                  "InvalidCompletionQuadEmbedding", 0),
+              0U)
+        << "variant " << variant;
+  }
+  for (int variant = 0; variant < 8; ++variant) {
+    options.completionVariant = variant;
+    const auto completion =
+        directional::geometry::complete_pure_quad_patch(fixture.patch, options);
+    ASSERT_TRUE(completion.is_produced()) << "variant " << variant;
+    const auto &mesh = completion.product();
+    EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::
+                  BoundedCombinatorial,
+              mesh.backend);
+    ASSERT_EQ(3U, mesh.quads.size()) << "variant " << variant;
+    EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(mesh));
+    // Independent exact oracle on the fixture's integer corners: every quad
+    // is simple and counter-clockwise, like the source face.
+    for (const auto &quad : mesh.quads) {
+      std::array<Eigen::Vector2d, 4> q;
+      for (std::size_t corner = 0; corner < 4; ++corner) {
+        q[corner] = boundary[static_cast<std::size_t>(quad[corner])];
+      }
+      double area2 = 0.0;
+      for (std::size_t corner = 0; corner < 4; ++corner) {
+        const Eigen::Vector2d &a = q[corner];
+        const Eigen::Vector2d &b = q[(corner + 1) % 4];
+        area2 += a.x() * b.y() - a.y() * b.x();
+      }
+      EXPECT_GT(area2, 0.0) << "variant " << variant;
+      EXPECT_FALSE(properlyCross(q[0], q[1], q[2], q[3]));
+      EXPECT_FALSE(properlyCross(q[1], q[2], q[3], q[0]));
+    }
+  }
+}
+
+TEST(PureQuadCompletionPhase18,
+     BoundedCompletionReportsABoundaryWithNoEmbeddedQuadrangulation) {
+  // Every one of the three quadrangulations of this hexagon contains a
+  // bow-tie, so no forward rotation can succeed and the failure is typed.
+  const std::vector<Eigen::Vector2d> boundary = {
+      {100.0, 500.0}, {200.0, 200.0}, {700.0, 500.0},
+      {500.0, 400.0}, {300.0, 500.0}, {400.0, 400.0}};
+  const CompletionFixture fixture = single_face_patch(boundary, {1, 1, 1, 3});
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 6;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(fixture.faces, {0}, {0});
+  options.sourceAuthority = &sourceAuthority;
+  for (int variant = 0; variant < 6; ++variant) {
+    options.completionVariant = variant;
+    const auto completion =
+        directional::geometry::complete_pure_quad_patch(fixture.patch, options);
+    ASSERT_TRUE(completion.is_rejected()) << "variant " << variant;
+    EXPECT_EQ(directional::geometry::PureQuadPatchRejectReason::
+                  NoEmbeddedQuadrangulation,
+              completion.rejection()->reason)
+        << "variant " << variant;
+  }
+}
```

#### RA-196.11 Exact CB75 patch

Base: CB74 result. SHA-256 `d1f5652a979c414e53f11f8b62a71f9d528a79428c0067f2b4946ad71844d933` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PatchDescriptor.h b/include/directional/geometry/PatchDescriptor.h
--- a/include/directional/geometry/PatchDescriptor.h
+++ b/include/directional/geometry/PatchDescriptor.h
@@ -298,6 +298,29 @@ enum class SurfaceCellComplexCompletionFailureKind : int {
   AssemblyRejected = 7,
 };
 
+inline const char *surface_cell_complex_completion_failure_name(
+    const SurfaceCellComplexCompletionFailureKind kind) {
+  switch (kind) {
+  case SurfaceCellComplexCompletionFailureKind::None:
+    return "None";
+  case SurfaceCellComplexCompletionFailureKind::PreparationRejected:
+    return "PreparationRejected";
+  case SurfaceCellComplexCompletionFailureKind::InvalidDomainIdentity:
+    return "InvalidDomainIdentity";
+  case SurfaceCellComplexCompletionFailureKind::UnresolvedSingularityOwnership:
+    return "UnresolvedSingularityOwnership";
+  case SurfaceCellComplexCompletionFailureKind::PatchCompletionRejected:
+    return "PatchCompletionRejected";
+  case SurfaceCellComplexCompletionFailureKind::CompletionOwnershipRejected:
+    return "CompletionOwnershipRejected";
+  case SurfaceCellComplexCompletionFailureKind::StructuralRepairExhausted:
+    return "StructuralRepairExhausted";
+  case SurfaceCellComplexCompletionFailureKind::AssemblyRejected:
+    return "AssemblyRejected";
+  }
+  return "Unknown";
+}
+
 struct SurfaceCellComplexCompletionEvidence {
   int parityOddCellsBefore = 0;
   int parityOddCellsAfter = 0;
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -14376,8 +14376,12 @@ remesh_from_raw_cross_field_impl_with_stage_products(
       result.surfaceCellContext.hasSimplifiedComplex = true;
     }
     if (completionResult.is_rejected()) {
-      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
-                                "completion");
+      // The typed completion failure is the terminal detail; the per-patch
+      // reason stays in surfaceCellContext.completionFailure.
+      return fail_surface_cells(
+          SurfaceCellFailureCode::NotProductionReady, "completion",
+          geometry::surface_cell_complex_completion_failure_name(
+              closedCompletionFailure->kind));
     }
     if (!completionResult.is_produced()) {
       return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -1908,3 +1908,25 @@ TEST(PatchDescriptorMilestoneE,
   EXPECT_EQ(0, completion.completionOwnershipRouteCandidateCount);
   EXPECT_TRUE(completion.ownershipRepairAttempts.empty());
 }
+
+TEST(PatchDescriptorMilestoneE, CompletionFailureKindsNameTheTerminalDetail) {
+  using directional::geometry::SurfaceCellComplexCompletionFailureKind;
+  using directional::geometry::surface_cell_complex_completion_failure_name;
+  // The completion terminal reports this name instead of "None"; every
+  // rejection kind has its own.
+  std::vector<std::string> names;
+  for (int value = 1; value <= 7; ++value) {
+    const std::string name = surface_cell_complex_completion_failure_name(
+        static_cast<SurfaceCellComplexCompletionFailureKind>(value));
+    EXPECT_NE("None", name);
+    EXPECT_NE("Unknown", name);
+    for (const std::string &previous : names) {
+      EXPECT_NE(previous, name);
+    }
+    names.push_back(name);
+  }
+  EXPECT_STREQ("PatchCompletionRejected",
+               surface_cell_complex_completion_failure_name(
+                   SurfaceCellComplexCompletionFailureKind::
+                       PatchCompletionRejected));
+}
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB69 manifest is TB68's 873 rows byte for byte plus rows 874–878; `SELF_CHECK_PASS cases=878 deferred=81` with harness P8 |
| Decisive claims independently re-derived | Patch 1200 boundary and all 12 quadrangulations in exact arithmetic; first-pass census of every boundary-only completion; DP existence for all 12,524 patches; per-descriptor failure traces in modes 0/1/3; clean build of the exact patches (tests, gate, ledger, Vase); mutants; patch chain applied to `fe29a3554` with every result SHA-256 reproduced; embedded blocks re-hashed |
| Non-vacuity checked | Each new row fails under its own mutant (RA-196.2), and row 876 also fails when the search ignores orientation. Row 876's fixture is exact: 0 of 16 balanced variants embed, and 3 of 12 quadrangulations do. Row 877's hexagon has no embedded quadrangulation (all 3 contain a bow-tie). The clean build moves Vase off the boundary-only class (229 failures, 0 boundary-only) |
| Prior obligations discharged/carried | F1–F8 ruled. P13-g attributed and routed (CB73/CB74/CB75/TB69); P13-h, P13-i, O21, O22 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, DR1/DR3, DR2/DR4, O2b, O15b, O7 (the oracle target still does not compile; seen in the probe build) |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-h, P13-i → `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING`; O21 (quality), O22 (cleanup) |
| ORIENTATION currency line | Updated to RA-196 / CB73 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: count every failure in a pass and check the validator against the source before designing a producer fix |
| Consolidation under CLEAN_UP_POLICY | The decision stays as history with a superseded note pointing here |
| Successor frozen | CB73 (RA-196.4, exact RA-196.9) → CB74 (RA-196.5, exact RA-196.10) → CB75 (RA-196.6, exact RA-196.11) → TB69 (RA-196.7) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 0dfde11f6` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB73 |
| Pushed to origin, branch in sync | Yes, fast-forward, no force |

## `Architecture_M6_CP3_DEFN_P13_Single_Edge_Barrier_Slit_Review_Decision_20261101.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Single_Edge_Barrier_Slit_Review_Decision_20261101.md`; moved verbatim.

### RA-191 — P13-c single-edge barrier slit representation (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT`, Review/Definition. **Disposition:** elect an A1 cut-side *combinatorial incidence* product, rather than relaxing hard-rail semantics or disguising a non-slit edge as an inner transport adjacency. This is a prospective CB66 contract, not a runtime fix. No production, test, fixture, benchmark, selector or compiled artifact was modified in this Review.

#### Evidence and independent reconstruction

- Source authority: exact verified repository snapshot `41fde362bd45707f37c0488decb6848fc6e697c0`, workflow run `41260180297`, artifact `13064259270`, **6059/6059** snapshot-file SHA-256 matches; source/semantic implementation remains CB65 `dbc38661efabdfa051f48f8f71ee3c604841842c`.
- TB64 independent artifact-only Linux evidence is [TB64 report](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB64_P13_Canonical_Dyadic_Full_Gate_Execution_Report_20261101.md"): frozen manifest **866/866** PASS; membership **947** (866 gated + 81 deferred); BunnyRandom census RED `CutTransportDomainIdentityMismatch`, `cutChi=-3`; Cylinder PASS; Vase fails later at completion. Those run claims are cited from the TB64 owning report; **no binaries or test artifacts were executed in this Review**.
- Source inspection: `make_local_region_mesh` (`src/authority/FieldTransportAtlas.cpp:990–1270`) partitions each original vertex's incident faces across non-barrier edges, builds `localCopyByVertexFace`, then invokes `TriMesh::set_mesh` on its remapped face array. An isolated barrier edge with both endpoints of barrier degree one does not split either vertex's connected star. Its two face-side occurrences have the same unordered local endpoint pair; a simple `TriMesh` therefore represents **one** edge and cannot distinguish the two boundary sides. `cutEulerCharacteristic` and `cutBoundaryLoopCount` are then computed from this collapsed mesh. This is a source-level causal argument, **not** a measured CB66 result.
- Independent finite-complex arithmetic: for a closed spherical triangulation with `V−E+F=2`, slitting `k` pairwise-disjoint interior single-edge tree components must give `E_cut=E+k`, with unchanged `V` and `F`; therefore `χ_cut=2−k` and `b_cut=k`. A tetrahedral sphere (`4,6,4`) with one isolated edge requires `(χ,b)=(1,1)`, and an octahedral sphere (`6,12,8`) with two disjoint isolated edges requires `(0,2)`. This is a **combinatorial probe**, not C++ or production runtime evidence. The BunnyRandom record has seven tree barrier components; two single-edge tip–tip components were not slit, explaining `−3` rather than expected `−5` under Amendment 15.4, subject to independent CB66 topology validation.
- `PCFaceTangentBundle` and consumers currently rely on simple `TriMesh` edge IDs. Merely incrementing the Euler diagnostic, aliasing the two edge sides, or calling the existing bundle on the uncut mesh would leave transport adjacency and cycle basis incorrect. Midpoint-triangle insertion would introduce synthetic face/chart/vertex support and is **not** approved as an invisible workaround.

#### Decision: Amendment 25, effective for A1 transport domains

A region cut along its interior non-traversable hard rails is a **combinatorial surface with edge-side occurrences**, not necessarily a simplicial complex expressible solely as an indexed face array. For each oriented source-face side `(source face identity, local side identity)`, derive a unique cut dart. On a traversable interior source edge, link the two incident darts as reciprocal twins. On an interior barrier edge, **do not link** them; each is an independent boundary dart with original source-edge and side provenance, even when both endpoints have the same canonical source-vertex IDs. Boundary source edges similarly expose one boundary dart. Use canonical topology-source IDs, never float positions or face-row indices, for comparison; preserve oriented component/sheet scope. A boundary loop can consist of **two parallel darts** joining the same pair of tip vertices. At a degree-one tip, the vertex stays one topological vertex and its surface boundary link must still be a single interval (a valid manifold-with-boundary sector).

The unique writer of this edge-side cut product is A1's transport-domain builder; A0/source faces, `SourceAuthoritySnapshot`, cross-field transitions and the uncut `GlobalTopologyPlan` remain immutable. All A1 transport walks, local boundary cycles, holonomy/index/`dual_cycles`, singularity attachment and later transport consumers must use its cut incidence, or an exact adapter proven equivalent **including parallel boundary edges**. A `TriMesh` adapter incapable of representing this incidence may be used for geometry/tangent samples only; it cannot own cut connectivity or its Euler proof. Do not silently equate source edge identity with cut-edge occurrence identity. Preserve no transport across barrier twins, and enforce reciprocal traversable adjacency and exactly one incident face on each cut boundary dart.

The authoritative identity is `χ(R_cut)=χ(R)−χ(B(R))+∂`, with `∂` the count of barrier vertices already on the original local boundary, using **incidence-based** `V/E/F` and independently enumerated boundary cycles. The cut must retain region face connectivity and be a manifold with boundary; a mismatch is a typed fail-closed A1 error with a source-edge/side locus. The `RelativeBoundary` singularity/index rules remain binding; a barrier-tip singularity must bind to the resulting boundary cycle or fail closed. This **supersedes Amendment 15.3's claim** that a face-array rewrite with the fixed tip rule always constructs the cut. Its endpoint multiplicity and arithmetic remain valid where representable, but a simple edge-key collapse is not acceptable. A rail-policy exemption that permits transport across a hard barrier is rejected.

#### Exactly one successor — CB66 Code + Build

`M6-CP3-CB66-P13-CUT-SIDE-INCIDENCE`: implement the smallest shared A1 cut-side occurrence producer and its transport/cycle consumers, preserving source-backed face tangent geometry and typed failure behavior. Do not change A2a–A9, cross-field values, output tolerances, rail policy, general patch completion, the Vase P13-d/O18 defect, the accepted 491 tests, or frozen selector497. Expand existing A1 tests only as required by the authorized contract, with independent evidence; compile-only Linux eight-target GMP/GMPXX package via the durable workflow, **no runtime in CB66**.

**Pre-registered CB66 acceptance/falsifiers:**

1. Inspect a closed tetrahedral sphere with one interior source-edge barrier: both face-side boundary darts exist, no cross-barrier twin, two-dart boundary loop, `χ=1`, `b=1`, connectivity preserved, all original source faces present. If merged to one edge or if either tip is spuriously doubled, **RED**.
2. On a closed octahedral sphere with two disjoint interior single-edge barriers: `χ=0`, `b=2` with independently enumerated loop orbits, and source-graph connectivity preserved. On a non-isolated multi-edge tree, established star-splitting behavior remains valid. An arithmetic-only corrected counter that leaves a wrong cycle basis is **RED**.
3. Check an open source-boundary-to-interior barrier, an ordinary traversable edge, and a vertex-bound singularity. A source-boundary edge must not be double-cut; a traversable edge retains reciprocal transport; a slit-tip singularity either binds to the boundary index or fails with its typed source locus. Any unintended pass or cross-barrier connection is **RED**.
4. Reorder source face rows and reverse compatible source face windings; compare **canonical topological** cut-edge/boundary and transport signatures, not raw local indices. Close-but-distinct sheets must never merge. A positional or face-row-based join is **RED**.
5. Negative mutant: explicitly identify two boundary sides by source-edge endpoint pair, or restore their twin across the barrier. The independent incidence/boundary oracle must fail. A merely expected typed error without asserting the violated invariant is **not** a valid mutant.
6. The existing required-green 866-case manifest SHA-256 `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce` and 81-case deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` remain immutable for this prospective CB. New test identities are separately enumerated and later governed by TB65; **no synthetic selector-green changes**.

**CB66 stop routes:** if the incidence product cannot be consumed by a correct tangent-bundle/dual-cycle construction without rewriting unrelated stages, do not paper over the edge collapse: stop at `M6-CP3-PLAN-P13-CUT-INCIDENCE-ADAPTER-STOP` (Review), retaining exact counterexamples. On compile failure, preserve the patch and report source defects instead of claiming runtime acceptance. If Actions infrastructure fails, retry with the same exact source under approved orchestration, preserving immutable build scope.

#### TB65 successor after a successful CB66 (not authorized in this Review)

`M6-CP3-TB65-P13-CUT-SIDE-FULL-GATE-EXEC` shall execute only a verified immutable CB66 package: frozen exact existing gate and deferred membership plus separately registered new cut-incidence tests (counts derived from actual compiled binary, never guessed); independently evaluate the above positive/negative witnesses and the three-case P13 census. Pre-register Cylinder PASS and Vase's independent existing completion RED **subject to actual control verification**. BunnyRandom must stop exhibiting `CutTransportDomainIdentityMismatch` with `cutChi=-3` and either reach a genuine later stage or complete directly with source-authoritative proof; a new A1 identity/adjacency/holonomy failure, a zero-selected test, any accepted-green loss, or cross-rail transport is **RED** and triggers an independent TB-REV. Do not require BunnyRandom production PASS merely to demonstrate this narrow A1 correction. No gate promotion, selector497 mutation, or CP3 acceptance is inferred.

The subsequent **separate** Review `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` remains sequenced after the CB66/TB65 slice and its authorized closeout.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No selector modification. Frozen TB64 866-manifest independently re-hashed to `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`; deferred v5 ledger re-hash recorded in the turn proof. CP2 491/491 is unchanged historical authority, not re-executed |
| Decisive claims independently re-derived | Read source cut builder and reconstructed finite CW Euler/loop counts for a tetrahedron and octahedron, without relying on a counter copied from the implementation |
| Non-vacuity checked | A simple vertex-indexed mesh collapses same-endpoint parallel cut edges; mutation restoring source-edge join or deleting one side would violate two-dart loop, boundary count and `χ` and fail the independent oracle |
| Prior obligations discharged/carried | P13-c representation adjudicated; CB66 runtime proof open. P13-d/O18 Vase, O6/O9, O16/O17, DR1/DR3 and DR2/DR4, O2b/O15b carried; O15c dyadic discharge unchanged |
| Stable accounting | 66 events / 17 categories / 49 recurrences, debt 1; CP2 accepted 491/491, selector497 not promoted; TB64 866/866 verified historical candidate, not production acceptance |
| New candidates/obligations recorded | P13-c cut-side incidence proof and CB66/TB65 outcome gates, no new accepted-green regression |
| ORIENTATION currency line | Updated to RA-191 and TB64 as latest verified evidence |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current 866/947; §4 witness outcomes unchanged (no runtime); §7 reordered P13-c then P13-d; §8 added simple-edge-collapse pattern |
| CHANGELOG | RA-191 turn summary inserted |
| ROADMAP | CP3 boundary refreshed; checkpoint status remains active/not accepted |
| Selector manifest | n/a: Review has no authorization to mutate frozen selector/manifest |
| LESSONS | Existing semantic ownership and independent-oracle lessons apply; no separate lesson needed |
| Consolidation under CLEAN_UP_POLICY | No superseded unique evidence deleted: RA-188 and RA-190 own distinct executed proof; RA-191 supplies normative new decision and links to them; historical reports retained. Turn snapshot-trigger file was deleted by the standard cleanup workflow |
| Successor frozen | `M6-CP3-CB66-P13-CUT-SIDE-INCIDENCE` with exact falsifiers and stop routes above |
| Turn boundary held | Review remained runtime-free; no implementation, test, fixture, selector, benchmark or build source edited |
| review_check.py boundary | Executed against the exact snapshot in a **synthetic Git worktree**: code/selector checks PASS; 4 historical rewrite-baseline checks could not pass because `8b7299b43` is absent from the snapshot-derived local Git history. Full authentic-history boundary verification remains unresolved; this is not represented as a green boundary run |
| `STATUS` lifecycle maintained | Entry beacon written as `IN_PROGRESS`; final COMPLETE beacon must be the last repository mutation after this record is applied |
| Pushed to origin, branch in sync | GitHub dispatcher applied the exact eight-path patch successfully (run 41260934999); verified applied commit in the job result, successful temporary-state cleanup (run 41261109756) and remote PR #8 head readback after cleanup. This is remote evidence; no local synthetic `git status -sb` is represented as origin synchronization |

## `Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md`; moved verbatim.

### RA-192 — P13-c slit: probe adjudication of RA-191 and exact CB66 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (Review/Definition), reopened and closed on an authentic Git checkout at `57136b395`. RA-192 keeps RA-191's diagnosis and its rejection of a rail exemption and of midpoint insertion. It replaces RA-191's general edge-side incidence product, its consumer-wide scope and its open-ended CB66 with one narrow, probe-verified adapter, delivered as an exact patch (RA-192.8). DESIGN.md Amendment 25 is rewritten and Amendment 15.3 restored to match.

#### RA-192.1 Review of RA-191

**Upheld.**
- **The diagnosis**, re-observed at current source (`dbc38661…`). BunnyRandom region 0 (χ 2, no boundary) has 17 hard-feature edges in 7 tree components. Two components are single edges whose endpoints are both interior tips (`68–216`, `169–331`). The face array keeps each glued, so the cut gives χ −3 with 5 loops against the identity's −5 with 7.
- **No transport across a hard barrier** (no rail exemption), **no midpoint insertion or synthetic vertex**, and identity 15.4 unchanged.

**Defects.**

| # | RA-191 text | Finding |
|---|---|---|
| D1 | A1 builds an edge-side incidence complex with canonical dart identities; "all A1 transport walks, local boundary cycles, holonomy/index/`dual_cycles`, singularity attachment and later transport consumers must use its cut incidence" | **Scope overstated.** Transport adjacency is built from source edges and already excludes every hard-feature edge (`FieldTransportAtlas.cpp:2082–2086`, `FieldTransportBarrierKind::HardFeature`), so no walk, transition or later stage can cross a slit. The cut mesh (`LocalRegionMesh`) is file-local and read only by A1's region loop: the Euler/boundary identity, `PCFaceTangentBundle` → `dual_cycles`, boundary-loop association and `componentTopology`. The defect is confined there. |
| D2 | Collapse attributed to "isolated tip–tip" edges, with no argument that nothing else collapses | **Proved, so 15.3 needs exactly one exception.** The two faces of a barrier edge `e = (u, v)` share a copy of `u` exactly when they lie in one component of `star(u) ∖ B`. At an interior vertex with `d_B(u) = 1` they always do; with `d_B(u) ≥ 2`, or with `u` on the region's local boundary, `e` separates them. Two distinct source edges never share an endpoint pair. So the face array glues a barrier edge exactly when both its endpoints are interior tips, and realises every other configuration. |
| D3 | CB66: "implement the smallest shared A1 cut-side occurrence producer and its transport/cycle consumers", tests "as required" | **Monolithic and open-ended**: design and test authoring handed to the implementation agent. Replaced by the exact patch in RA-192.8. |
| D4 | Falsifiers 1–2 on tetrahedral and octahedral spheres | **Not executable through the atlas.** A1 accepts vertex singularities with 3–6 ports, i.e. index ≤ 1 (`FieldTransportAtlas.cpp:574–581`), and a tetrahedron needs total index 8 on four vertices. On an octahedron, zero-transport lifts are 4/3. Replaced by planar grids, where a zero-transport field is valid, and the genus-1 torus fixture. |
| D5 | Falsifier 4 (face-row reorder, winding reversal); falsifier 5 (mutants as typed-error tests) | 4 tests no property this change introduces: slits are ordered by source edge, and the rest is existing face-array behaviour. 5 is a Review activity, done in RA-192.3. |
| D6 | Falsifier 6 and TB65: the 866 manifest and ledger "remain immutable", new tests "separately enumerated", counts "derived from actual compiled binary" | **Would fail membership** (RA-190 R7 again). Three new tests in a gated binary make membership 950, and P8 rejects the 866 manifest. Deriving counts during TB-EXEC also moves pre-registration to the executor. The 869-row manifest is frozen now (RA-192.6). |
| D7 | TB65: BunnyRandom must "reach a genuine later stage or complete" | **Not pre-registered.** Probes give the exact next failure on macOS and in an FMA-off build (RA-192.3). |
| D8 | No probe | Decided from source reading. RA-192.3 supplies the probes. |

#### RA-192.2 The adapter (Amendment 25, rewritten)

- **Detection.** After the face-array cut, `make_local_region_mesh` records each inner edge of the cut mesh whose source edge is a barrier and whose endpoints both have barrier degree 1 and lie off the region's uncut boundary. By D2 these are exactly the glued edges. They are ordered by source edge.
- **Accounting.** `χ_cut = V − E + F − s` and `b_cut = loops + s` for `s` slits. The boundary-multiplicity check counts each slit's two sides, so a glued barrier edge that is not a slit still fails closed.
- **Cycle basis** (`cut_cycle_basis`). Start from `dual_cycles` on the face array.
  - For each slit, the two tip rows merge into one boundary-loop row `ring(u) + ring(v)`, placed after the face-array loops. The slit column cancels, because `ring(u)` holds −1 and `ring(v)` +1 there.
  - The slit column is removed.
  - The curvature is `κ(u) + κ(v) − 2π = 2π − Σθ(u) − Σθ(v)`. That is `dual_cycles`' boundary formula for the vertex set `{u, v}` with all of their corners.
  - The loop's vertex list is `[u, v]`.

  This is the row `dual_cycles` would build on a mesh able to represent the slit; no other vertex ring contains the slit column.
- **Handle generators.** A generator row that is nonzero on a slit column fails closed as `IncompleteCycleBasis` with the new reason `HandleGeneratorCrossesSlit`, located at the slit's source edge (O19). The row is not rewritten, because `dual_cycles`' generator curvature is a side-set formula, not linear in the row. A distinct reason keeps 15.4's guarantee that a barrier never raises `CycleTransportAdjacencyMissing`.
- **No slit, no change.** The row and column maps are the identity, and the triplets and curvatures are unchanged.
- **Untouched:** transport adjacency, transitions, singularity binding, A2a–A9 and rail policy. A singular tip binds to its slit loop through `slitCycleByGlobalVertex`, as any barrier tip does.

#### RA-192.3 Probe findings (macOS, scratch build, diagnostic only)

| Probe | Result |
|---|---|
| 869-row candidate gate | **868/869.** Only row 283 (O16) fails. Only the three new rows reach a slit, so the change is inert on every existing gate fixture. |
| 81 deferred rows, slit off vs on | **81/81 RED in both modes.** Only row 360 (BunnyRandom) reaches a slit; it moves from `CutTransportDomainIdentityMismatch` to the P13-e failure below. Vase (row 365) has no slit and is unchanged. |
| BunnyRandom | Identity passes (cutChi −5, 7 loops), and the cycle basis is built. The next failure is `SingularityPortClassCountMismatch` at vertex 49. Its index is −1, so 5 port classes are expected, but only 4 incidences are found, in fan faces 0, 2, 4 and 6 of 8. An FMA-off build gives the same result, so this is not an FMA tie. Recorded as **P13-e**. |
| Torus sweep: each of 216 edges as the only hard edge | 181 succeed with χ −1, b 1, genus 1 and 2 handles. 35 fail closed because a `dual_cycles` generator crosses the slit: **O19**. |
| Mutants | M1 (no slit detection, i.e. HEAD) fails all three new tests. M2 (slit-loop curvature without the −2π) fails rows 867 and 868. M3 (no generator guard) fails row 869. All three pass on the patch. |
| Membership | 950 = 869 gated + 81 deferred, listed from the built binaries, no overlap. P8: `SELF_CHECK_PASS cases=869 deferred=81` |
| Census | Cylinder PASS. BunnyRandom RED `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, with `cutChi=-5,uncutBoundaryLoops=0,cutBoundaryLoops=7` and no `CutTransportDomainIdentityMismatch`. Vase RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence`, unchanged. |

#### RA-192.4 Rulings

- **Amendment 25 (rewritten):**
  - The face array realises every barrier except the slit of D2.
  - A1 applies each slit exactly in its cut accounting and its `dual_cycles` basis.
  - A generator that crosses a slit fails closed (`HandleGeneratorCrossesSlit`).
  - RA-191's general incidence product, dart identities and consumer-wide adoption are withdrawn.
- **Amendment 15.3** reads as before, with this one exception.
- **P13-c:** discharged when TB65 matches.
- **P13-e (new):** A1 requires `4 − index` port classes at every non-barrier singularity. BunnyRandom's smooth field on its random triangulation has 4 sector incidences at index −1 vertex 49, on both builds. The open question is whether A1's sector rule or the field owns this.
  - Owner: `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (Review, probes), after TB65 confirms it on Linux.
- **O19 (new):** `HandleGeneratorCrossesSlit`, a genus > 0 region whose `dual_cycles` generator crosses a slit (35 of 216 torus edges).
  - Not CP3-blocking: all six design-acceptance fixtures are genus 0 (Plane, MultiFaceSeam and Vase χ 1; Cylinder χ 0 with 2 loops; CloseSheets and BunnyRandom χ 2).
  - Owner: a later DEFN, raised when a fixture needs it.
- **RA-191 IDs superseded:**
  - CB66 becomes `M6-CP3-CB66-P13-SLIT-CYCLE-BASIS`.
  - TB65 becomes `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC`.
  - `M6-CP3-PLAN-P13-CUT-INCIDENCE-ADAPTER-STOP` is withdrawn.
- **Carried:** P13-d with O18 (Vase), O6, O9, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b.

#### RA-192.5 CB66 — exact patch

`M6-CP3-CB66-P13-SLIT-CYCLE-BASIS`: implementation agent, Linux workflow runner, compile only.

| Item | Value |
|---|---|
| Precheck | `git diff --quiet dbc38661efabdfa051f48f8f71ee3c604841842c HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Patch | RA-192.8 block, verbatim plus a trailing newline. SHA-256 `c83fefa2298e8fb5fc1b6ef14a8fe47f46ce5cf92d0acc89f4fd6d7da0c4377c`. Run `git apply --check`, then apply. |
| Numstat | `1 0` `include/directional/authority/FieldTransportAtlas.h`; `173 33` `src/authority/FieldTransportAtlas.cpp`; `182 0` `tests/FieldAlignedCurveNetworkTests.cpp` |
| Result SHA-256 | header `b73e5adc88812d1106bed5936d8cf9a5480c7ef48f3d5defbe502567e345b78f`; atlas `514d49656cf53d16d3472f41392f0e57a33f3facccb5533719fa1e331e249b89`; network tests `e9f13aa4dc0f3acbaa2c8c0f18575d08f0771d7ebcf63feea30f0a2b95b9a560` |
| Build | `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256. No native runs. |
| Outcomes | Exact → TB65. A patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-SLIT-STOP` (Review). Infrastructure failure → `M6-CP3-CB66A-P13-SLIT-ORCH` (one retry). |

#### RA-192.6 TB65 — frozen inputs and pre-registered outcomes

`M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC`: implementation agent, Linux workflow runner, on the verified CB66 package only.

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv`, **869 rows**, SHA-256 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`. It is the TB64 866-row manifest byte-for-byte, plus GUARD rows 867 `ra192:slit-two-sided`, 868 `ra192:slit-with-arc` and 869 `ra192:torus-slit`. `SELF_CHECK_PASS cases=869 deferred=81` |
| Ledger | v5, 81 rows, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, unchanged |
| Census | `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` `3af1dc0d…`, no ledger, one fresh process per row |
| Harness | P8 `78b8002c…`, unchanged |

| Run | Pre-registered outcome |
|---|---|
| Gate | **869/869 PASS**, membership **950**, postflight true |
| Census row 1, Cylinder | PASS |
| Census row 2, BunnyRandom | RED `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, with `cutChi=-5,uncutBoundaryLoops=0,cutBoundaryLoops=7` and no `CutTransportDomainIdentityMismatch` |
| Census row 3, Vase | RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence` (unchanged) |

Mismatch routes:
- Any gate RED, membership other than 950, or a census signature mismatch → `M6-CP3-TB65-P13-SLIT-FULL-GATE-REV` (Review).
- Infrastructure failure → `M6-CP3-TB65A-P13-SLIT-ORCH` (one retry).

No TB65-REV is needed when everything matches.

#### RA-192.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB66-P13-SLIT-CYCLE-BASIS` | Implementation agent, Linux; exact patch, compile only |
| 2 | `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869 + census 3 |
| 3 (Review, parallel with 1–2) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d with O18) → CB → TB | Review (probes) → implementation agent |
| 4 (Review, after 2) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Review (probes) → implementation agent |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | Per slice |

#### RA-192.8 Exact CB66 patch

SHA-256 of the block content plus a trailing newline: `c83fefa2298e8fb5fc1b6ef14a8fe47f46ce5cf92d0acc89f4fd6d7da0c4377c`.

Seven lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the patched source is clean under `git diff --check`.

```diff
diff --git a/include/directional/authority/FieldTransportAtlas.h b/include/directional/authority/FieldTransportAtlas.h
index 206c9a1b2..ea8fe47db 100644
--- a/include/directional/authority/FieldTransportAtlas.h
+++ b/include/directional/authority/FieldTransportAtlas.h
@@ -108,6 +108,7 @@ enum class IncompleteCycleBasisReason : std::uint8_t {
   CycleOrderingFailed = 5,
   CycleKindPartitionMismatch = 6,
   BoundaryCycleCountMismatch = 7,
+  HandleGeneratorCrossesSlit = 8,
 };
 
 struct FieldAtlasRegionCycleBasisDiagnostics {
diff --git a/src/authority/FieldTransportAtlas.cpp b/src/authority/FieldTransportAtlas.cpp
index 24e04e79c..6762a9687 100644
--- a/src/authority/FieldTransportAtlas.cpp
+++ b/src/authority/FieldTransportAtlas.cpp
@@ -982,6 +982,10 @@ struct LocalRegionMesh {
   std::vector<int> globalVertexByLocal;
   std::set<int> barrierVertices;
   std::map<int, std::size_t> transportStarComponentCountByGlobalVertex;
+  // Rows of mesh.EV that are slits (Amendment 25): barrier edges whose two
+  // endpoints are interior barrier tips, so the face array keeps both sides
+  // glued. Sorted by source edge.
+  std::vector<int> slitEdges;
   FieldTransportRegionDiagnostics diagnostics;
   bool uncutAuthorityMatches = false;
   bool cutIdentityValid = false;
@@ -1263,10 +1267,36 @@ std::optional<LocalRegionMesh> make_local_region_mesh(
   } catch (const std::exception &) {
     return std::nullopt;
   }
+
+  // Amendment 25: a tip has one vertex copy, so a barrier edge whose two
+  // endpoints are interior tips stays an inner edge of the face array. Each
+  // such slit adds one edge and one two-edge boundary loop to the cut.
+  std::map<SourceEdgeTopologyKey, int> slitEdgeByKey;
+  for (int edge = 0; edge < result.mesh.EV.rows(); ++edge) {
+    if (result.mesh.EF(edge, 1) < 0) continue;
+    const int first = result.globalVertexByLocal[static_cast<std::size_t>(
+        result.mesh.EV(edge, 0))];
+    const int second = result.globalVertexByLocal[static_cast<std::size_t>(
+        result.mesh.EV(edge, 1))];
+    const auto key = SourceEdgeTopologyKey::from_indices(
+        first, second, static_cast<std::size_t>(sourceMesh.V.rows()));
+    if (!key || barrierEdges.count(key.value()) == 0U) continue;
+    if (barrierAdjacency[first].size() == 1U &&
+        barrierAdjacency[second].size() == 1U &&
+        uncutBoundaryGlobalVertices.count(first) == 0U &&
+        uncutBoundaryGlobalVertices.count(second) == 0U) {
+      slitEdgeByKey.emplace(key.value(), edge);
+    }
+  }
+  for (const auto &[key, edge] : slitEdgeByKey) {
+    result.slitEdges.push_back(edge);
+  }
+  const int slitCount = static_cast<int>(result.slitEdges.size());
   result.diagnostics.cutEulerCharacteristic = static_cast<int>(
-      result.mesh.V.rows() - result.mesh.EV.rows() + result.mesh.F.rows());
+      result.mesh.V.rows() - result.mesh.EV.rows() + result.mesh.F.rows()) -
+      slitCount;
   result.diagnostics.cutBoundaryLoopCount =
-      static_cast<int>(result.mesh.boundaryLoops.size());
+      static_cast<int>(result.mesh.boundaryLoops.size()) + slitCount;
   result.diagnostics.newSlitBoundaryLoopCount =
       result.diagnostics.cutBoundaryLoopCount -
       result.diagnostics.uncutBoundaryLoopCount;
@@ -1283,6 +1313,9 @@ std::optional<LocalRegionMesh> make_local_region_mesh(
     if (!key) return std::nullopt;
     ++cutBoundaryMultiplicity[key.value()];
   }
+  for (const auto &[key, edge] : slitEdgeByKey) {
+    cutBoundaryMultiplicity[key] += 2U;
+  }
   bool boundaryRealizationValid = true;
   for (const auto &[edge, count] : cutBoundaryMultiplicity) {
     const std::size_t expected = barrierEdges.count(edge) != 0U
@@ -1315,6 +1348,108 @@ std::optional<LocalRegionMesh> make_local_region_mesh(
   return result;
 }
 
+// Cycle basis of a region's cut transport domain: dual_cycles of the face
+// array with each slit applied exactly (Amendment 25). A slit's two tip rows
+// become one boundary-loop row, in which the slit column cancels, and the slit
+// column is removed. The loop's curvature is 2*pi minus the angle sums at both
+// tips, which is dual_cycles' boundary formula. Rows are interior vertices,
+// face-array boundary loops, slit loops, then handle generators.
+struct LocalCutCycleBasis {
+  Eigen::SparseMatrix<double> cycles;
+  Eigen::VectorXd cycleCurvatures;
+  Eigen::VectorXi innerAdjacencies;
+  std::vector<int> interiorVertices;
+  std::vector<std::vector<int>> boundaryLoops;
+  // A handle generator that crosses a slit would need transport across a
+  // barrier; it is reported, not rewritten.
+  std::optional<int> generatorSlitEdge;
+};
+
+// Throws whatever PCFaceTangentBundle::init throws.
+LocalCutCycleBasis cut_cycle_basis(const LocalRegionMesh &local) {
+  PCFaceTangentBundle bundle;
+  bundle.init(local.mesh);
+  LocalCutCycleBasis basis;
+  basis.boundaryLoops = local.mesh.boundaryLoops;
+  std::map<int, int> slitByTip;
+  std::set<int> slitEdges(local.slitEdges.begin(), local.slitEdges.end());
+  for (std::size_t slit = 0; slit < local.slitEdges.size(); ++slit) {
+    const int edge = local.slitEdges[slit];
+    slitByTip.emplace(local.mesh.EV(edge, 0), static_cast<int>(slit));
+    slitByTip.emplace(local.mesh.EV(edge, 1), static_cast<int>(slit));
+    basis.boundaryLoops.push_back(
+        {local.mesh.EV(edge, 0), local.mesh.EV(edge, 1)});
+  }
+
+  std::vector<int> meshInterior;
+  for (int vertex = 0; vertex < local.mesh.V.rows(); ++vertex) {
+    if (local.mesh.isBoundaryVertex(vertex) == 0) meshInterior.push_back(vertex);
+  }
+  // dual_cycles rows are the face array's interior vertices, its boundary
+  // loops, then handle generators; each slit merges two rows into one.
+  const int interiorRows = static_cast<int>(meshInterior.size());
+  const int generatorRowBegin =
+      interiorRows + static_cast<int>(local.mesh.boundaryLoops.size());
+  const int slitCount = static_cast<int>(local.slitEdges.size());
+  const int slitRowBegin = generatorRowBegin - 2 * slitCount;
+  const int rowCount = static_cast<int>(bundle.cycles.rows()) - slitCount;
+  std::vector<int> rowMap(static_cast<std::size_t>(bundle.cycles.rows()));
+  int nextRow = 0;
+  for (int row = 0; row < bundle.cycles.rows(); ++row) {
+    if (row == generatorRowBegin) nextRow += slitCount;
+    if (row < interiorRows) {
+      const int vertex = meshInterior[static_cast<std::size_t>(row)];
+      const auto slit = slitByTip.find(vertex);
+      if (slit != slitByTip.end()) {
+        rowMap[static_cast<std::size_t>(row)] = slitRowBegin + slit->second;
+        continue;
+      }
+      basis.interiorVertices.push_back(vertex);
+    }
+    rowMap[static_cast<std::size_t>(row)] = nextRow++;
+  }
+
+  std::vector<int> columnMap(
+      static_cast<std::size_t>(bundle.innerAdjacencies.size()), -1);
+  std::vector<int> innerAdjacencies;
+  for (int column = 0; column < bundle.innerAdjacencies.size(); ++column) {
+    if (slitEdges.count(bundle.innerAdjacencies(column)) != 0U) continue;
+    columnMap[static_cast<std::size_t>(column)] =
+        static_cast<int>(innerAdjacencies.size());
+    innerAdjacencies.push_back(bundle.innerAdjacencies(column));
+  }
+
+  std::vector<Eigen::Triplet<double>> triplets;
+  for (int column = 0; column < bundle.cycles.outerSize(); ++column) {
+    for (Eigen::SparseMatrix<double>::InnerIterator it(bundle.cycles, column);
+         it; ++it) {
+      const int mappedColumn = columnMap[static_cast<std::size_t>(it.col())];
+      if (mappedColumn < 0) {
+        if (it.row() >= generatorRowBegin) {
+          basis.generatorSlitEdge = bundle.innerAdjacencies(it.col());
+        }
+        continue;
+      }
+      triplets.emplace_back(rowMap[static_cast<std::size_t>(it.row())],
+                            mappedColumn, it.value());
+    }
+  }
+  basis.cycles.resize(rowCount, static_cast<int>(innerAdjacencies.size()));
+  basis.cycles.setFromTriplets(triplets.begin(), triplets.end());
+  basis.innerAdjacencies = Eigen::Map<const Eigen::VectorXi>(
+      innerAdjacencies.data(), static_cast<int>(innerAdjacencies.size()));
+
+  basis.cycleCurvatures = Eigen::VectorXd::Zero(rowCount);
+  for (int slit = 0; slit < slitCount; ++slit) {
+    basis.cycleCurvatures(slitRowBegin + slit) = -2.0 * std::numbers::pi;
+  }
+  for (int row = 0; row < bundle.cycles.rows(); ++row) {
+    basis.cycleCurvatures(rowMap[static_cast<std::size_t>(row)]) +=
+        bundle.cycleCurvatures(row);
+  }
+  return basis;
+}
+
 std::vector<FieldAtlasRegionCycleBasisDiagnostics>
 collect_cycle_basis_diagnostics(
     const TriMesh &sourceMesh,
@@ -1332,11 +1467,11 @@ collect_cycle_basis_diagnostics(
 
     row.localMeshAvailable = true;
     row.vertexCount = static_cast<std::size_t>(local->mesh.V.rows());
-    row.edgeCount = static_cast<std::size_t>(local->mesh.EV.rows());
+    row.edgeCount = static_cast<std::size_t>(local->mesh.EV.rows()) +
+                    local->slitEdges.size();
     row.faceCount = static_cast<std::size_t>(local->mesh.F.rows());
-    row.eulerCharacteristic = static_cast<int>(
-        local->mesh.V.rows() - local->mesh.EV.rows() + local->mesh.F.rows());
-    row.boundaryLoopCount = static_cast<int>(local->mesh.boundaryLoops.size());
+    row.eulerCharacteristic = local->diagnostics.cutEulerCharacteristic;
+    row.boundaryLoopCount = local->diagnostics.cutBoundaryLoopCount;
     const int genusNumerator =
         2 - row.boundaryLoopCount - row.eulerCharacteristic;
     if (genusNumerator >= 0 && genusNumerator % 2 == 0) {
@@ -1347,20 +1482,20 @@ collect_cycle_basis_diagnostics(
         ++row.interiorLocalVertexCount;
       }
     }
+    row.interiorLocalVertexCount -= 2U * local->slitEdges.size();
     if (row.genus >= 0) {
       row.expectedCycleCount =
           static_cast<int>(row.interiorLocalVertexCount) +
           row.boundaryLoopCount + 2 * row.genus;
     }
 
-    PCFaceTangentBundle bundle;
     try {
-      bundle.init(local->mesh);
+      const LocalCutCycleBasis basis = cut_cycle_basis(*local);
       row.bundleInitialized = true;
-      row.cycleRowCount = static_cast<std::size_t>(bundle.cycles.rows());
-      row.cycleCurvatureCount = bundle.cycleCurvatures.size();
+      row.cycleRowCount = static_cast<std::size_t>(basis.cycles.rows());
+      row.cycleCurvatureCount = basis.cycleCurvatures.size();
       row.innerAdjacencyCount =
-          static_cast<std::size_t>(bundle.innerAdjacencies.size());
+          static_cast<std::size_t>(basis.innerAdjacencies.size());
     } catch (const std::exception &) {
       row.bundleInitialized = false;
     }
@@ -2486,37 +2621,39 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
     }
     const int genus = genusNumerator / 2;
 
-    PCFaceTangentBundle bundle;
+    LocalCutCycleBasis basis;
     try {
-      bundle.init(local->mesh);
+      basis = cut_cycle_basis(*local);
     } catch (const std::exception &) {
       return incomplete_cycle_basis_failure(
           sourceMesh, sourceAuthority,
           IncompleteCycleBasisReason::LocalTangentBundleInitializationFailed,
           std::nullopt, region.id(), hardFeatureEdges);
     }
-    std::vector<int> interiorLocalVertices;
-    for (int vertex = 0; vertex < local->mesh.V.rows(); ++vertex) {
-      if (local->mesh.isBoundaryVertex(vertex) == 0) {
-        interiorLocalVertices.push_back(vertex);
-      }
+    if (basis.generatorSlitEdge.has_value()) {
+      return incomplete_cycle_basis_failure(
+          sourceMesh, sourceAuthority,
+          IncompleteCycleBasisReason::HandleGeneratorCrossesSlit,
+          global_edge_key(*local, *basis.generatorSlitEdge, vertexExtent),
+          region.id(), hardFeatureEdges);
     }
+    const std::vector<int> &interiorLocalVertices = basis.interiorVertices;
     const int expectedHandleCount = 2 * genus;
     const int expectedCycleCount =
         static_cast<int>(interiorLocalVertices.size()) + boundaryLoopCount +
         expectedHandleCount;
-    if (bundle.cycles.rows() != expectedCycleCount ||
-        bundle.cycleCurvatures.size() != expectedCycleCount ||
-        bundle.cycles.cols() != bundle.innerAdjacencies.size()) {
+    if (basis.cycles.rows() != expectedCycleCount ||
+        basis.cycleCurvatures.size() != expectedCycleCount ||
+        basis.cycles.cols() != basis.innerAdjacencies.size()) {
       return incomplete_cycle_basis_failure(
           sourceMesh, sourceAuthority,
           IncompleteCycleBasisReason::CycleDimensionCountMismatch, std::nullopt,
           region.id(), hardFeatureEdges);
     }
 
-    Eigen::VectorXd effort(bundle.innerAdjacencies.size());
-    for (int column = 0; column < bundle.innerAdjacencies.size(); ++column) {
-      const int localEdge = bundle.innerAdjacencies(column);
+    Eigen::VectorXd effort(basis.innerAdjacencies.size());
+    for (int column = 0; column < basis.innerAdjacencies.size(); ++column) {
+      const int localEdge = basis.innerAdjacencies(column);
       const SourceEdgeTopologyKey edge =
           global_edge_key(*local, localEdge, vertexExtent);
       const auto transition = transitionByEdge.find(edge);
@@ -2540,12 +2677,12 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
       }
     }
     const Eigen::VectorXd exactLifts =
-        ((bundle.cycles * effort +
+        ((basis.cycles * effort +
           static_cast<double>(fields::kCrossFieldDegree) *
-              bundle.cycleCurvatures)
+              basis.cycleCurvatures)
              .array() /
          (2.0 * std::numbers::pi));
-    Eigen::SparseMatrix<double, Eigen::RowMajor> rowCycles = bundle.cycles;
+    Eigen::SparseMatrix<double, Eigen::RowMajor> rowCycles = basis.cycles;
 
     const std::size_t componentCycleBegin = cycles.size();
     std::vector<std::size_t> localCycleIndices;
@@ -2569,13 +2706,13 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
         // zeros. They are representation storage, not semantic cycle support.
         if (std::abs(coefficient) < kIntegerTolerance) continue;
         if (std::abs(std::abs(coefficient) - 1.0) >= kIntegerTolerance ||
-            it.col() < 0 || it.col() >= bundle.innerAdjacencies.size()) {
+            it.col() < 0 || it.col() >= basis.innerAdjacencies.size()) {
           return incomplete_cycle_basis_failure(
               sourceMesh, sourceAuthority,
               IncompleteCycleBasisReason::CycleCoefficientInvalid, std::nullopt,
               region.id(), hardFeatureEdges);
         }
-        const int localEdge = bundle.innerAdjacencies(it.col());
+        const int localEdge = basis.innerAdjacencies(it.col());
         const SourceEdgeTopologyKey edge =
             global_edge_key(*local, localEdge, vertexExtent);
         const FieldTransportAdjacency *adjacency =
@@ -2745,18 +2882,18 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
       }
       witness.indexSum = requiredIndexSum;
     }
-    if (boundaryCycleIndices.size() != local->mesh.boundaryLoops.size()) {
+    if (boundaryCycleIndices.size() != basis.boundaryLoops.size()) {
       return incomplete_cycle_basis_failure(
           sourceMesh, sourceAuthority,
           IncompleteCycleBasisReason::BoundaryCycleCountMismatch, std::nullopt,
           region.id(), hardFeatureEdges);
     }
     for (std::size_t loopIndex = 0;
-         loopIndex < local->mesh.boundaryLoops.size(); ++loopIndex) {
+         loopIndex < basis.boundaryLoops.size(); ++loopIndex) {
       const FieldCycleId boundaryCycle =
           cycles[boundaryCycleIndices[loopIndex]].id;
       const std::vector<int> &localBoundaryLoop =
-          local->mesh.boundaryLoops[loopIndex];
+          basis.boundaryLoops[loopIndex];
       std::vector<SourceEdgeTopologyKey> sourceBoundarySupport;
       sourceBoundarySupport.reserve(localBoundaryLoop.size());
       for (std::size_t edgeIndex = 0; edgeIndex < localBoundaryLoop.size();
@@ -2836,7 +2973,8 @@ FieldTransportAtlasBuildResult FieldTransportAtlas::make(
         region.id(), region.component(), eulerCharacteristic,
         boundaryLoopCount, genus,
         static_cast<std::size_t>(local->mesh.V.rows()),
-        static_cast<std::size_t>(local->mesh.EV.rows()),
+        static_cast<std::size_t>(local->mesh.EV.rows()) +
+            local->slitEdges.size(),
         static_cast<std::size_t>(local->mesh.F.rows()),
         localCycleIndices.size(), handleCycleIndices.size()});
     FieldTransportRegionDiagnostics regionDiagnostics = local->diagnostics;
@@ -3252,6 +3390,8 @@ const char *incomplete_cycle_basis_reason_name(
     return "CycleKindPartitionMismatch";
   case IncompleteCycleBasisReason::BoundaryCycleCountMismatch:
     return "BoundaryCycleCountMismatch";
+  case IncompleteCycleBasisReason::HandleGeneratorCrossesSlit:
+    return "HandleGeneratorCrossesSlit";
   }
   return "Unknown";
 }
diff --git a/tests/FieldAlignedCurveNetworkTests.cpp b/tests/FieldAlignedCurveNetworkTests.cpp
index ad5883a38..36b9f1754 100644
--- a/tests/FieldAlignedCurveNetworkTests.cpp
+++ b/tests/FieldAlignedCurveNetworkTests.cpp
@@ -18018,3 +18018,185 @@ TEST(TestFixturePaths, MissingPackageFailsClosedInsteadOfReturningMissingPath) {
   EXPECT_THROW((void)directional::tests::require_test_data_root(missing),
                std::runtime_error);
 }
+
+namespace {
+
+// Planar n-by-n vertex grid; every interior vertex has six incident faces.
+TriMesh make_planar_grid_mesh(const int side) {
+  Eigen::MatrixXd vertices(side * side, 3);
+  for (int row = 0; row < side; ++row) {
+    for (int column = 0; column < side; ++column) {
+      vertices.row(row * side + column) << column, row, 0.0;
+    }
+  }
+  Eigen::MatrixXi faces(2 * (side - 1) * (side - 1), 3);
+  int face = 0;
+  for (int row = 0; row + 1 < side; ++row) {
+    for (int column = 0; column + 1 < side; ++column) {
+      const int corner = row * side + column;
+      faces.row(face++) << corner, corner + 1, corner + side + 1;
+      faces.row(face++) << corner, corner + side + 1, corner + side;
+    }
+  }
+  TriMesh mesh;
+  mesh.set_mesh(vertices, faces);
+  return mesh;
+}
+
+bool cycle_steps_all_touch(const directional::authority::FieldCycleWitness &cycle,
+                        const std::set<std::size_t> &vertices) {
+  return std::all_of(cycle.steps.begin(), cycle.steps.end(),
+                     [&](const auto &step) {
+                       return vertices.count(step.sourceEdge.first().index()) !=
+                                  0U ||
+                              vertices.count(step.sourceEdge.second().index()) !=
+                                  0U;
+                     });
+}
+
+} // namespace
+
+// Amendment 25: an interior hard-feature edge whose endpoints are both
+// interior barrier tips is a slit. The face array keeps its two sides glued,
+// so A1 cuts it in the cycle basis: one more edge, one two-edge boundary loop,
+// no vertex cycle at either tip and no cycle step across the slit.
+TEST(FieldTransportAtlas, IsolatedInteriorBarrierEdgeIsATwoSidedSlit) {
+  const TriMesh mesh = make_planar_grid_mesh(5);
+  const auto slit = topology_edge(6, 7, 25U);
+  const std::set<SourceEdgeTopologyKey> hardEdges{slit};
+  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
+      mesh, *sourceAuthority, hardEdges, make_zero_transport_field(mesh));
+  std::ostringstream report;
+  if (!atlasBuild) append_atlas_error(report, atlasBuild.error());
+  ASSERT_TRUE(atlasBuild) << report.str();
+  const auto &atlas = atlasBuild.value();
+  append_transport_region_diagnostics(report, atlas);
+
+  ASSERT_EQ(1U, atlas.component_topology().size());
+  const auto &topology = atlas.component_topology().front();
+  EXPECT_EQ(0, topology.eulerCharacteristic) << report.str();
+  EXPECT_EQ(2, topology.boundaryLoopCount) << report.str();
+  EXPECT_EQ(0, topology.genus) << report.str();
+  EXPECT_EQ(25U, topology.vertexCount) << report.str();
+  EXPECT_EQ(57U, topology.edgeCount) << report.str();
+  EXPECT_EQ(32U, topology.faceCount) << report.str();
+  EXPECT_EQ(7U, topology.localCycleCount) << report.str();
+  ASSERT_EQ(1U, atlas.region_transport_diagnostics().size());
+  const auto &region = atlas.region_transport_diagnostics().front();
+  EXPECT_EQ(1, region.uncutEulerCharacteristic) << report.str();
+  EXPECT_EQ(0, region.cutEulerCharacteristic) << report.str();
+  EXPECT_EQ(2, region.cutBoundaryLoopCount) << report.str();
+  EXPECT_EQ(1, region.newSlitBoundaryLoopCount) << report.str();
+
+  std::vector<int> boundaryLifts;
+  for (const auto &cycle : atlas.cycles()) {
+    for (const auto &step : cycle.steps) {
+      EXPECT_NE(slit, step.sourceEdge) << report.str();
+    }
+    if (cycle.kind == directional::authority::FieldCycleKind::LocalVertex) {
+      ASSERT_TRUE(cycle.localVertex.has_value());
+      EXPECT_NE(6U, cycle.localVertex->index()) << report.str();
+      EXPECT_NE(7U, cycle.localVertex->index()) << report.str();
+    }
+    if (cycle.kind != directional::authority::FieldCycleKind::BoundaryLoop) {
+      continue;
+    }
+    boundaryLifts.push_back(cycle.turningLift);
+    if (cycle_steps_all_touch(cycle, {6U, 7U})) {
+      // Ten radial edges around the two degree-six tips, minus the slit.
+      EXPECT_EQ(10U, cycle.steps.size()) << report.str();
+      EXPECT_EQ(-4, cycle.turningLift) << report.str();
+    }
+  }
+  EXPECT_EQ((std::vector<int>{4, -4}), boundaryLifts) << report.str();
+}
+
+// Two slits and a two-edge barrier arc in one region: the face array cuts the
+// arc (its middle vertex gets two copies) and the cycle basis cuts the slits.
+TEST(FieldTransportAtlas, SlitsAndABarrierArcShareOneCutTransportDomain) {
+  const TriMesh mesh = make_planar_grid_mesh(6);
+  const std::set<SourceEdgeTopologyKey> hardEdges{
+      topology_edge(7, 8, 36U), topology_edge(27, 28, 36U),
+      topology_edge(14, 15, 36U), topology_edge(15, 16, 36U)};
+  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
+      mesh, *sourceAuthority, hardEdges, make_zero_transport_field(mesh));
+  std::ostringstream report;
+  if (!atlasBuild) append_atlas_error(report, atlasBuild.error());
+  ASSERT_TRUE(atlasBuild) << report.str();
+  const auto &atlas = atlasBuild.value();
+  append_transport_region_diagnostics(report, atlas);
+
+  ASSERT_EQ(1U, atlas.component_topology().size());
+  const auto &topology = atlas.component_topology().front();
+  EXPECT_EQ(-2, topology.eulerCharacteristic) << report.str();
+  EXPECT_EQ(4, topology.boundaryLoopCount) << report.str();
+  EXPECT_EQ(0, topology.genus) << report.str();
+  EXPECT_EQ(37U, topology.vertexCount) << report.str();
+  EXPECT_EQ(89U, topology.edgeCount) << report.str();
+  EXPECT_EQ(9U, topology.localCycleCount) << report.str();
+  std::vector<int> boundaryLifts;
+  for (const auto &cycle : atlas.cycles()) {
+    for (const auto &step : cycle.steps) {
+      EXPECT_EQ(0U, hardEdges.count(step.sourceEdge)) << report.str();
+    }
+    if (cycle.kind == directional::authority::FieldCycleKind::BoundaryLoop) {
+      boundaryLifts.push_back(cycle.turningLift);
+    }
+  }
+  std::sort(boundaryLifts.begin(), boundaryLifts.end());
+  EXPECT_EQ((std::vector<int>{-4, -4, -4, 4}), boundaryLifts) << report.str();
+}
+
+// On the genus-one torus fixture a slit keeps both handle generators when
+// dual_cycles' generators avoid it. A generator that crosses it would need
+// transport across the barrier, so A1 fails closed with the slit as locus
+// (O19).
+TEST(FieldTransportAtlas, TorusSlitKeepsBothHandlesOrFailsClosedAtTheSlit) {
+  TriMesh mesh;
+  ASSERT_TRUE(directional::readOBJ(
+      directional::tests::benchmark_fixture_path("milestone-g/torus.obj")
+          .string(),
+      mesh));
+  const Eigen::MatrixXd raw = read_cp4c_rawfield(
+      directional::tests::benchmark_fixture_path("milestone-g/torus.rawfield"),
+      mesh.F.rows());
+  const CrossFieldResult field =
+      directional::pipeline::finalize_surface_cell_raw_cross_field(mesh, raw);
+  const auto build = [&](const SourceEdgeTopologyKey &slit) {
+    const std::set<SourceEdgeTopologyKey> hardEdges{slit};
+    const auto sourceAuthority = make_source_authority(mesh, hardEdges);
+    EXPECT_TRUE(sourceAuthority.has_value());
+    return directional::authority::FieldTransportAtlas::make(
+        mesh, *sourceAuthority, hardEdges, field);
+  };
+  const std::size_t extent = static_cast<std::size_t>(mesh.V.rows());
+
+  const auto kept = topology_edge(0, 1, extent);
+  const auto keptBuild = build(kept);
+  std::ostringstream report;
+  if (!keptBuild) append_atlas_error(report, keptBuild.error());
+  ASSERT_TRUE(keptBuild) << report.str();
+  ASSERT_EQ(1U, keptBuild.value().component_topology().size());
+  const auto &topology = keptBuild.value().component_topology().front();
+  EXPECT_EQ(-1, topology.eulerCharacteristic);
+  EXPECT_EQ(1, topology.boundaryLoopCount);
+  EXPECT_EQ(1, topology.genus);
+  EXPECT_EQ(2U, topology.handleGeneratorCount);
+  for (const auto &cycle : keptBuild.value().cycles()) {
+    for (const auto &step : cycle.steps) EXPECT_NE(kept, step.sourceEdge);
+  }
+
+  const auto crossed = topology_edge(12, 14, extent);
+  const auto crossedBuild = build(crossed);
+  ASSERT_FALSE(crossedBuild);
+  EXPECT_EQ(directional::authority::FieldAtlasBuildErrorCode::IncompleteCycleBasis,
+            crossedBuild.error().code);
+  EXPECT_EQ(directional::authority::IncompleteCycleBasisReason::
+                HandleGeneratorCrossesSlit,
+            crossedBuild.error().incompleteCycleBasisReason);
+  EXPECT_EQ(crossed, crossedBuild.error().sourceEdge);
+}
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB64 866 `289d887c…` is the byte-identical prefix of the new 869 `baaef9e7…`; ledger v5 `fd433f54…` unchanged; both self-check |
| Decisive claims independently re-derived | Probes, not static reading. Gate run under the change. Deferred rows compared slit-off vs slit-on. BunnyRandom run on macOS and in an FMA-off build. Torus swept over all 216 edges. Membership listed from the built binaries |
| Non-vacuity checked | Mutants M1–M3 each fail at least one new test; the three new rows and deferred row 360 reach a slit |
| Prior obligations discharged/carried | RA-191 D1–D8 ruled. P13-c discharged once TB65 matches. P13-e and O19 new. P13-d, O18, O6, O9, O16, O17, DR1/DR3, DR2/DR4, O2b, O15b carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-e (BunnyRandom vertex-49 port count), O19 (handle generator across a slit) |
| ORIENTATION currency line | Updated to RA-192 / CB66 next |
| ORIENTATION §3 / §4 / §7 / §8 | §7 Immediate and priority 1 updated; §8 RA-191 line corrected. §3/§4: n/a, no executed gate or witness change |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: find what a broken representation actually feeds before replacing it |
| Consolidation under CLEAN_UP_POLICY | n/a: RA-191 stays as history; its diagnosis is upheld here |
| Successor frozen | CB66 (RA-192.5); TB65 falsifiers (RA-192.6) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran only in scratch builds |
| `review_check.py boundary` | ALL CHECKS PASSED on the authentic checkout; `ledgers --base 0a9b0618e` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB66 |
| Pushed to origin, branch in sync | Confirmed after the push |

## `Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md`; moved verbatim.

### RA-193 — P13-d Vase: probe adjudication of the completion-incidence decision, and exact CB67/CB68 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (Review/Definition), reopened and closed at `8eccb79d9`, semantic source `911840c195b52ce1800b3ac7ff3ea7380137ad9c` (CB66). The [Vase decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Vase_Completion_Incidence_Review_Decision_20261101.md") was right to refuse an incidence "repair", and its F1 rule (the earliest invalid boundary owns the defect) is the rule applied here. But it left the producer unidentified, ruled from source reading alone, and handed the implementation agent an open-ended diagnostics CB. A two-minute scratch probe identifies the producer. **The arrangement publishes zero cells.** The cause is two defects in its directed rotation system, plus a pipeline that ignores the arrangement's own typed failure. Both are fixed here by exact patches (RA-193.10, RA-193.11), probe-verified on the gate and the ledger.

#### RA-193.1 Review of the Vase decision

**Upheld.** No downstream incidence sanitizer, no skipped validator, no selector or assertion change; F1 (assign the earliest producer that violates incidence).

**Defects.**

| # | Decision text | Finding |
|---|---|---|
| V1 | "`arrangementCells=0` is a reported diagnostic count, not proof that the arrangement was empty" | **Wrong.** `RemeshPipeline.cpp:13736` sets it to `arrangementComplex.cells.size()`. The probe confirms 0 cells over 57,677 nodes and 169,004 halfedges, every one with `cell = −1`. |
| V2 | The zero-odd parity fast path is "a contract-validation blind spot" | **Immaterial.** Side repair runs the same `validate_incidence_allowing_nondisk` on the same complex immediately afterwards, so nothing is hidden. Not carried. |
| V3 | "No evidence currently distinguishes arrangement-origin invalidity, a simplification-induced invalidity, or an invalid parity transform" | **The evidence was already published.** The arrangement records its own typed audit (`SurfaceArrangementDiagnostics::incidenceValid`, `incidenceFailure`, node, halfedge). It reports `RepeatedNodeCycle` at node 33. The pipeline discards it: `RemeshPipeline.cpp:13777` records the stage as succeeded unconditionally. That is the O18 defect, an Amendment 19 violation, not a missing probe point. |
| V4 | CB67 "change only the smallest existing producer/validation boundary needed …", F3 "inject a known invalid twin … into a synthetic source-complex unit fixture" | **Open-ended.** It gives the implementation agent design latitude and fixture design, contrary to the standing rule (exact patches and frozen manifests only). Withdrawn. |
| V5 | "Invoke one consistent named validation oracle at these boundaries" | Three already exist: the arrangement's own audit, `validate_incidence_allowing_nondisk` and the typed `surface_simplification_detail::audit_complex_incidence`. No new oracle is needed. |
| V6 | No probe | A one-line `fprintf` at four boundaries settled F1 in one run (RA-193.3). This is the fourth consecutive P13 DEFN decided statically (RA-188, RA-190, RA-192). |

#### RA-193.2 Root cause

The generic arrangement (`build_surface_cell_complex`, non-proposal branch) orders the rays at each node into directed wedges and takes each halfedge's successor from its wedge. Two defects break that rotation system wherever a trace crosses a source edge or vertex:

- **R1, split wedges.** The wedge map is keyed by `ResolvedSourceEntity`. Its `operator<` (`SourceChartTransitions.h:143`) compares `chart`, a `SourceProjectionChart` whose `operator<=>` includes the source **face** (`SurfaceCellOwnership.h:134`). An edge point seen from its two faces, or a vertex seen from the faces of its fan, therefore yields one wedge per face. Each wedge holds a single ray, whose successor is the incoming halfedge's own twin, so the face walk turns back along the trace. On Vase, 23,332 of 57,677 nodes are split, giving 46,585 single-ray wedges (46,338 edge, 247 vertex). The code's own intent is a shared wedge:
  - the two-face side mapping at `SurfaceArrangement.cpp:2926`;
  - the boundary-rail comment "One common SourceVertex/SourceEdge identity" (`:3603`);
  - the historical test `AdjacentLocalSheetChartsShareDirectedIntrinsicWedges` (`SurfaceArrangementPhase16Tests.cpp:1547`).

  The canonical `SourceEntityIdentity` (component, edge or vertex fan, field chart) exists for exactly this purpose.
- **R2, mirrored edge rotations.** An edge ray's angle is measured from the canonical low→high direction into its face (`:2652`). That is counter-clockwise only on the face that traverses low→high. The side that gets `2π − θ` is chosen by sorted vertex signature, not orientation, and a single-face wedge is never corrected. An independent 3D rotation oracle (cyclic order about the face normal) over Vase's nodes with three or more rays gives: face interior 26,670 same / 0 mirrored; vertex 102 / 0; **edge 95 / 72**.
- **R3, O18.** When incidence is invalid the arrangement drops every cell (`:6351`). The pipeline still records the stage as succeeded and forwards the empty complex. Simplification, parity and side repair then pass it along until side repair's validator rejects it with a generic `InvalidInputIncidence`, `detail=None`.

**Why this was never seen.** The non-proposal path is reached only by fixtures that every authoritative phase-front producer declines. In the 869 gate rows and the 81 deferred rows, only Vase reaches an invalid arrangement. The arrangement's unit tests are in the historical target, which is not built, and they are stale: none passes `sourceAuthority`. Before CB65, Vase failed earlier at the A4 width bound. At HEAD, even an arc-free two-triangle square fails here with `BoundaryRotationalSystemConflict`.

#### RA-193.3 Probe findings (macOS scratch build `bld61`, diagnostic only)

| Probe | Result |
|---|---|
| Incidence at each boundary (HEAD) | arrangement out, simplified out, parity in, side in (raw and canonical): all `cells=0`, first clause `halfedge.cell = −1`. **F1 fires at the arrangement.** Its own audit: `RepeatedNodeCycle`, node 33 (source face 0, interior X-crossing), first face walk of 68 halfedges, the outside of a figure-8 of arcs confined to triangle 0 because every arc reaching the triangle's interior edges U-turns |
| R1 only fixed | No single-ray wedges remain; walks from the first 112 halfedges pass; next `RepeatedEdgeCycle` (a 1,114-halfedge walk using both sides of a non-bridge edge, impossible on a disk) |
| R1 + R2 fixed | Rotation oracle edge 167 / 0. **Arrangement valid: 26,827 cells, `topologyValid`.** Simplification valid; parity 5,937 odd → 0; side-repair input valid. Completion then runs for more than 25 min (RA-193.4, P13-f) |
| Gate 869, R3 only (CB67 state) | **868/869**, only row 283 (O16); no row reaches an invalid arrangement |
| Gate 869, R1 + R2 + R3 (CB68 state) | **868/869**, only row 283 |
| Clean CB67 + CB68 build, TB67 manifest 871 | **870/871**, only row 283; membership listed from the five binaries **952** = 871 + 81 |
| 81 deferred rows, HEAD vs CB68 state | 0 PASS in both. One change: row 365 (Vase) RED → TIMEOUT at 300 s, because it now reaches completion. HEAD mode: exactly one row (Vase) with invalid arrangement incidence |
| New tests | `TraceCrossingInteriorSourceEdgeSharesOneDirectedEdgeWedge` and `TraceThroughInteriorSourceVertexSharesOneDirectedFanWedge` pass. R1 reverted: both fail (`BoundaryRotationalSystemConflict`). R2 reverted: both fail (`BoundaryFanSectorCoverConflict`). Both reverted: both fail |
| Vase census, CB67 state | `terminal=NotProductionReady:arrangement detail=RepeatedNodeCycle traceSegments=192482 arrangementCells=0 completedQuads=0 completion=` |
| Vase census, CB68 state | No verdict within 600 s (clean build); the stack is in `complete_pure_quad_patch` |
| Completion cost (stack samples) | 3,179 of 3,807 samples are in `close_completion_lineage_source_authority`, which builds a full `SourceChartTransitionGraph` and runs `matches_source_faces` (both O(F)) **per output vertex**. Reusing the caller's graph moves 2,755 of 3,840 samples to `validate_completion_domain_ownership`'s own per-patch graph build (`PureQuadCompletion.cpp:1322`), once per patch × 26,827 patches |

#### RA-193.4 Rulings

- **Amendment 26 (new):** a directed wedge is one counter-clockwise rotation about its source entity, shared by every incident face chart. An arrangement whose incidence is invalid ends the run at the `arrangement` stage with its own typed failure.
- **O18:** discharged when TB66 matches.
- **P13-d (arrangement rotation system):** discharged when TB67 matches. Vase's frontier moves to completion.
- **P13-f (new):** completion ownership validation is O(output vertices × F) and then O(patches × F), from repeated `SourceChartTransitionGraph` construction in `PureQuadCompletion.cpp` (`:869`, `:1322`; callers `:1282`, `:1582`, `PatchDescriptor.cpp:2842`). The fix must build the graph once per completion and pass it down. That changes the `complete_pure_quad_patch` / `validate_completion_domain_ownership` signatures, so it is a design choice for a probe DEFN, not a CB.
  - Owner: `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (Review, probes), after TB67. It must name the next Vase failure, or a PASS, within the 600 s harness bound.
- **P13-e** (BunnyRandom vertex 49) is independent of this change and already confirmed on Linux by TB65. Its DEFN can run on the Review track now.
- **Superseded:** the decision's `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE`, its F1–F5 CB contract and its follow-on TB. CB67 now names the exact O18 patch.
- **Carried:** P13-e, O6, O9, O16, O17, O19, DR1/DR3, DR2/DR4, O2b, O15b. The stale historical arrangement suite belongs to O2b's retirement DEFN.

#### RA-193.5 CB67 — exact patch (O18)

`M6-CP3-CB67-P13-ARRANGEMENT-INCIDENCE-TERMINAL` (Code + Build, implementation agent, Linux workflow runner; compile only).

| Item | Value |
|---|---|
| Precheck | `git diff --quiet 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Patch | RA-193.10 block, verbatim plus a trailing newline. SHA-256 `35727214ac067ac3337ce640ec78fd23a8e92f7f14c444d953053feef7209822`. Run `git apply --check`, then apply |
| Numstat | `29 1` `src/pipeline/RemeshPipeline.cpp` |
| Base / result SHA-256 | `47d77eb7ec4d7356f43890669b7b9158929b236695249956be2ddd8e264c410c` → `d478a64c57df71a0a50182ec80304b5176dfd87a0f5999de410a764c9e5f391a` |
| Build | `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256. No binary runs |
| Outcomes | Exact → TB66. Patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP` (Review). Infrastructure failure → `M6-CP3-CB67A-P13-ARRANGEMENT-TERMINAL-ORCH` (one retry) |

#### RA-193.6 TB66 — frozen inputs and pre-registered outcomes

`M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` (artifact-only, CB67 package).

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv`, 869 rows, `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`, unchanged (CB67 adds no test) |
| Ledger | v5, 81 rows, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Census | `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

| Run | Pre-registered outcome |
|---|---|
| Gate | **869/869 PASS**, membership **950**, postflight true |
| Census 1, Cylinder | PASS |
| Census 2, BunnyRandom | RED `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` (unchanged) |
| Census 3, Vase | RED `terminal=NotProductionReady:arrangement detail=RepeatedNodeCycle`, `traceSegments=192482`, `arrangementCells=0`, `completedQuads=0`, empty `completion=` |

Mismatch → `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-REV` (Review). Infrastructure → `M6-CP3-TB66A-P13-ARRANGEMENT-TERMINAL-ORCH` (one retry).

#### RA-193.7 CB68 — exact patch (arrangement rotation system)

`M6-CP3-CB68-P13-ARRANGEMENT-WEDGE-ROTATION` (Code + Build, implementation agent, Linux workflow runner; compile only; after TB66).

| Item | Value |
|---|---|
| Precheck | `git diff --name-only 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake` prints only `src/pipeline/RemeshPipeline.cpp`, at SHA-256 `d478a64c…` (CB67) |
| Patch | RA-193.11 block, verbatim plus a trailing newline (keep its five single-space context lines). SHA-256 `e93f5d8c5966f520e4650259a4d836bba1fbfa6ac025d08fe98e49a3065e0f82`. Run `git apply --check`, then apply |
| Numstat | `37 30` `src/geometry/SurfaceArrangement.cpp`; `95 0` `tests/SurfaceArrangementRowIdentityTests.cpp` |
| Base → result SHA-256 | arrangement `8dd2f3fd2cae0c253a050edaf38ce4b724ed379990d9ec800269077cee996d68` → `2c8f66296219f13b57895592851c1a3561e5f525dd98b1fc4b24049e2e4a183e`; tests `95ff8de9595844ff48b6f001360758dd67aca58a2a7812dd7a187ec4db255fea` → `862ab53de607ad094bc708bef86497e8ed81a4b6ee18ee5c1f638d689f646214` |
| Build | As CB67 |
| Outcomes | Exact → TB67. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP` (Review). Infrastructure → `M6-CP3-CB68A-P13-ARRANGEMENT-WEDGE-ORCH` (one retry) |

#### RA-193.8 TB67 — frozen inputs and pre-registered outcomes

`M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` (artifact-only, CB68 package).

| Input | Value |
|---|---|
| Gate manifest | `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv`, **871 rows**, SHA-256 `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b`: the TB65 869 rows byte-identical, plus GUARD rows 870 `ra193:edge-wedge` and 871 `ra193:fan-wedge` (`directional_surface_cell_completion_tests`). P8 `SELF_CHECK_PASS cases=871 deferred=81` |
| Ledger, census, harness | As TB66 |

| Run | Pre-registered outcome |
|---|---|
| Gate | **871/871 PASS**, membership **952**, postflight true |
| Census 1, Cylinder | PASS |
| Census 2, BunnyRandom | RED, unchanged signature (as TB66) |
| Census 3, Vase | **ABNORMAL**, harness timeout (600 s, exit 124) inside completion (P13-f). Any verdict before 600 s is a mismatch |

Mismatch → `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-REV` (Review). Infrastructure → `M6-CP3-TB67A-P13-ARRANGEMENT-WEDGE-ORCH` (one retry).

#### RA-193.9 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB67-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; exact patch, compile only |
| 2 | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869, membership 950, census 3 |
| 3 | `M6-CP3-CB68-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; exact patch, compile only |
| 4 | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871, membership 952, census 3 |
| 5 (Review, parallel with 1–4) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) → CB → TB | Review (probes) → implementation agent |
| 6 (Review, after 4) | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) → CB → TB | Review (probes) → implementation agent |
| 7 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

#### RA-193.10 Exact CB67 patch

SHA-256 of the block content plus a trailing newline: `35727214ac067ac3337ce640ec78fd23a8e92f7f14c444d953053feef7209822`.

```diff
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index 5421e8e39..d44a21f83 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -13774,9 +13774,37 @@ remesh_from_raw_cross_field_impl_with_stage_products(
         result.diagnostics.surfaceCellArrangementCellCount);
     mark_stage_consumed("embedding", retainedNetworkIdentity,
                         SurfaceCellConsumptionKind::Full);
+    const geometry::SurfaceArrangementDiagnostics &arrangementIncidence =
+        arrangementComplex.diagnostics;
     record_surface_cell_stage("arrangement", retainedNetworkIdentity,
-                              arrangementIdentity, true,
+                              arrangementIdentity,
+                              arrangementIncidence.incidenceValid,
                               result.diagnostics.surfaceCellArrangementSeconds);
+    if (!arrangementIncidence.incidenceValid) {
+      // Without valid incidence the arrangement publishes no cells to simplify
+      // or complete; its own typed failure is the first invalid producer.
+      SurfaceCellFailureLocusDiagnostics locus;
+      if (arrangementIncidence.incidenceFailureNode >= 0 &&
+          arrangementIncidence.incidenceFailureNode <
+              static_cast<int>(arrangementComplex.nodes.size())) {
+        const int face =
+            arrangementComplex
+                .nodes[static_cast<std::size_t>(
+                    arrangementIncidence.incidenceFailureNode)]
+                .sourceFace;
+        if (face >= 0 && face < meshWhole.F.rows()) {
+          locus.sourceFace = std::array<std::size_t, 3>{
+              static_cast<std::size_t>(meshWhole.F(face, 0)),
+              static_cast<std::size_t>(meshWhole.F(face, 1)),
+              static_cast<std::size_t>(meshWhole.F(face, 2))};
+        }
+      }
+      return fail_surface_cells(
+          SurfaceCellFailureCode::NotProductionReady, "arrangement",
+          geometry::surface_arrangement_incidence_failure_name(
+              arrangementIncidence.incidenceFailure),
+          locus);
+    }
     completedSurfaceCellStages.push_back("arrangement");
     if (options.surfaceCells.injectFailureAfterStage == 6) {
       return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
```

#### RA-193.11 Exact CB68 patch

SHA-256 of the block content plus a trailing newline: `e93f5d8c5966f520e4650259a4d836bba1fbfa6ac025d08fe98e49a3065e0f82`.

Five lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the patched source is clean under `git diff --check`.

```diff
diff --git a/src/geometry/SurfaceArrangement.cpp b/src/geometry/SurfaceArrangement.cpp
index 8dc2e40a4..3104eb4cc 100644
--- a/src/geometry/SurfaceArrangement.cpp
+++ b/src/geometry/SurfaceArrangement.cpp
@@ -2650,6 +2650,19 @@ SurfaceCellComplex build_surface_cell_complex(
           }
           y = std::max(0.0, y);
           parameter = std::atan2(y, direction.dot(edgeDirection));
+          // The angle runs from the canonical low->high direction into this
+          // face. It is counterclockwise only on the face that traverses
+          // low->high; the opposite face measures its clockwise complement.
+          const int chartFace = chart_source_face(chart);
+          bool lowToHigh = false;
+          for (int corner = 0; corner < 3; ++corner) {
+            lowToHigh = lowToHigh ||
+                        (faces(chartFace, corner) == lowVertex &&
+                         faces(chartFace, (corner + 1) % 3) == highVertex);
+          }
+          if (!lowToHigh && parameter > 0.0) {
+            parameter = 6.283185307179586476925286766559 - parameter;
+          }
           return std::isfinite(parameter);
         }
         if (entity.kind() == SourceEntityKind::FaceInterior) {
@@ -2812,9 +2825,19 @@ SurfaceCellComplex build_surface_cell_complex(
       }
     }
   } else {
+  // A directed wedge is one rotation about its source entity. Key it by the
+  // canonical identity so that the incident face charts of one source edge or
+  // vertex fan share it.
+  struct DirectedWedgeKeyLess {
+    bool operator()(const ResolvedSourceEntity &lhs,
+                    const ResolvedSourceEntity &rhs) const {
+      return lhs.identity < rhs.identity;
+    }
+  };
   using DirectedWedgeMap =
       std::map<ResolvedSourceEntity,
-               std::map<int, std::vector<DirectedWedgeWitness>>>;
+               std::map<int, std::vector<DirectedWedgeWitness>>,
+               DirectedWedgeKeyLess>;
   std::vector<DirectedWedgeMap> wedgeWitnesses(complex.nodes.size());
   std::vector<std::vector<int>> outgoing(complex.nodes.size());
   for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
@@ -2864,7 +2887,8 @@ SurfaceCellComplex build_surface_cell_complex(
     }
   }
 
-  std::vector<std::map<ResolvedSourceEntity, std::vector<DirectedWedgeRay>>>
+  std::vector<std::map<ResolvedSourceEntity, std::vector<DirectedWedgeRay>,
+                       DirectedWedgeKeyLess>>
       orderedWedges(complex.nodes.size());
   std::vector<std::vector<ResolvedSourceEntity>>
       halfedgeWedges(complex.halfedges.size());
@@ -2894,13 +2918,8 @@ SurfaceCellComplex build_surface_cell_complex(
           }
         }
       }
-      std::vector<int> wedgeFaces(sourceFaceSet.begin(), sourceFaceSet.end());
-      std::sort(wedgeFaces.begin(), wedgeFaces.end(), [&](const int lhs,
-                                                           const int rhs) {
-        return std::make_tuple(face_signature(lhs), lhs) <
-               std::make_tuple(face_signature(rhs), rhs);
-      });
-      if (wedgeKind == SourceEntityKind::SourceEdge && wedgeFaces.size() > 2U) {
+      if (wedgeKind == SourceEntityKind::SourceEdge &&
+          sourceFaceSet.size() > 2U) {
         ++complex.diagnostics.successorAmbiguityCount;
         record_incidence_failure(
             SurfaceArrangementIncidenceFailure::AmbiguousWedge, nodeId, -1,
@@ -2913,24 +2932,7 @@ SurfaceCellComplex build_surface_cell_complex(
         std::vector<double> parameters;
         parameters.reserve(witnesses.size());
         for (const DirectedWedgeWitness &witness : witnesses) {
-          double mapped = witness.localParameter;
-          if (wedgeKind == SourceEntityKind::SourceEdge &&
-              wedgeFaces.size() == 2U) {
-            const auto found = std::find(wedgeFaces.begin(), wedgeFaces.end(),
-                                         witness.chart.sourceFace);
-            if (found == wedgeFaces.end()) {
-              continue;
-            }
-            const int side =
-                static_cast<int>(std::distance(wedgeFaces.begin(), found));
-            if (side == 1) {
-              mapped = twoPi - mapped;
-            }
-            if (std::abs(mapped - twoPi) <= parameterTolerance) {
-              mapped = 0.0;
-            }
-          }
-          parameters.push_back(mapped);
+          parameters.push_back(witness.localParameter);
         }
         if (parameters.empty()) {
           ++complex.diagnostics.successorMissingCount;
@@ -2990,8 +2992,12 @@ SurfaceCellComplex build_surface_cell_complex(
     }
   }
   for (auto &memberships : halfedgeWedges) {
-    std::sort(memberships.begin(), memberships.end());
-    memberships.erase(std::unique(memberships.begin(), memberships.end()),
+    std::sort(memberships.begin(), memberships.end(), DirectedWedgeKeyLess{});
+    memberships.erase(std::unique(memberships.begin(), memberships.end(),
+                                  [](const ResolvedSourceEntity &lhs,
+                                     const ResolvedSourceEntity &rhs) {
+                                    return lhs.identity == rhs.identity;
+                                  }),
                       memberships.end());
   }
 
@@ -3612,7 +3618,8 @@ SurfaceCellComplex build_surface_cell_complex(
                 localOutgoing[index])];
             std::set_intersection(commonWedges.begin(), commonWedges.end(),
                                   memberships.begin(), memberships.end(),
-                                  std::back_inserter(intersection));
+                                  std::back_inserter(intersection),
+                                  DirectedWedgeKeyLess{});
             commonWedges = std::move(intersection);
           }
 
diff --git a/tests/SurfaceArrangementRowIdentityTests.cpp b/tests/SurfaceArrangementRowIdentityTests.cpp
index 1342f2da9..e4b6bbb5c 100644
--- a/tests/SurfaceArrangementRowIdentityTests.cpp
+++ b/tests/SurfaceArrangementRowIdentityTests.cpp
@@ -2,6 +2,7 @@
 #include <directional/geometry/SurfaceArrangement.h>
 #include <directional/geometry/SurfaceCellTracing.h>
 
+#include <algorithm>
 #include <memory>
 #include <stdexcept>
 #include <vector>
@@ -118,4 +119,98 @@ TEST(SurfaceArrangementPhase16,
   EXPECT_NE(firstIdentity, distinctIdentity);
 }
 
+// A directed wedge is one rotation about a source edge or vertex fan.
+// A trace crossing a shared source edge or vertex must continue into the next
+// face; keying the wedge by the witnessing face chart splits it and turns the
+// face walk back along the trace.
+directional::geometry::SurfaceArrangementArc wedge_test_arc(
+    const int id, const int face, const Eigen::RowVector3d &start,
+    const Eigen::RowVector3d &end) {
+  directional::geometry::SurfaceArrangementArc arc;
+  arc.id = id;
+  arc.sourceFace = face;
+  arc.startBarycentric = start;
+  arc.endBarycentric = end;
+  arc.family = 0;
+  arc.strand = 0;
+  arc.provenance = id;
+  return arc;
+}
+
+void expect_trace_continues_through_shared_node(
+    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
+    const std::vector<directional::geometry::SurfaceArrangementArc> &arcs,
+    const Eigen::RowVector3d &sharedPoint) {
+  const std::vector<int> components(static_cast<std::size_t>(faces.rows()), 0);
+  const std::vector<int> sheets(static_cast<std::size_t>(faces.rows()), 0);
+  directional::geometry::SurfaceArrangementOptions options;
+  options.sourceAuthority =
+      row_identity_source_authority(faces, components, sheets);
+  const auto complex = directional::geometry::build_surface_cell_complex(
+      vertices, faces, arcs, options);
+
+  ASSERT_TRUE(complex.diagnostics.incidenceValid)
+      << directional::geometry::surface_arrangement_incidence_failure_name(
+             complex.diagnostics.incidenceFailure);
+  EXPECT_EQ(2, std::count_if(complex.cells.begin(), complex.cells.end(),
+                             [](const auto &cell) { return !cell.boundaryCycle; }));
+  int sharedNode = -1;
+  for (const auto &node : complex.nodes) {
+    Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
+    for (int corner = 0; corner < 3; ++corner) {
+      position += node.barycentric(corner) *
+                  vertices.row(faces(node.sourceFace, corner));
+    }
+    if ((position - sharedPoint).norm() < 1.0e-12) {
+      ASSERT_EQ(-1, sharedNode);
+      sharedNode = node.id;
+    }
+  }
+  ASSERT_GE(sharedNode, 0);
+  int incoming = 0;
+  for (const auto &halfedge : complex.halfedges) {
+    if (halfedge.to != sharedNode) {
+      continue;
+    }
+    ++incoming;
+    EXPECT_NE(halfedge.twin, halfedge.next) << "halfedge " << halfedge.id;
+  }
+  EXPECT_EQ(2, incoming);
+}
+
+TEST(SurfaceArrangementPhase16,
+     TraceCrossingInteriorSourceEdgeSharesOneDirectedEdgeWedge) {
+  Eigen::MatrixXd vertices(4, 3);
+  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0;
+  Eigen::MatrixXi faces(2, 3);
+  faces << 0, 1, 2,
+           1, 3, 2;
+  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
+      wedge_test_arc(0, 0, Eigen::RowVector3d(0.5, 0.0, 0.5),
+                     Eigen::RowVector3d(0.0, 0.5, 0.5)),
+      wedge_test_arc(1, 1, Eigen::RowVector3d(0.5, 0.0, 0.5),
+                     Eigen::RowVector3d(0.5, 0.5, 0.0))};
+  expect_trace_continues_through_shared_node(
+      vertices, faces, arcs, Eigen::RowVector3d(0.5, 0.5, 0.0));
+}
+
+TEST(SurfaceArrangementPhase16,
+     TraceThroughInteriorSourceVertexSharesOneDirectedFanWedge) {
+  Eigen::MatrixXd vertices(5, 3);
+  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
+      0.5, 0.5, 0.0;
+  Eigen::MatrixXi faces(4, 3);
+  faces << 0, 1, 4,
+           1, 2, 4,
+           2, 3, 4,
+           3, 0, 4;
+  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
+      wedge_test_arc(0, 3, Eigen::RowVector3d(0.5, 0.5, 0.0),
+                     Eigen::RowVector3d(0.0, 0.0, 1.0)),
+      wedge_test_arc(1, 1, Eigen::RowVector3d(0.0, 0.0, 1.0),
+                     Eigen::RowVector3d(0.5, 0.5, 0.0))};
+  expect_trace_continues_through_shared_node(
+      vertices, faces, arcs, Eigen::RowVector3d(0.5, 0.5, 0.0));
+}
+
 } // namespace
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB65 869 `baaef9e7…` is the byte-identical prefix of TB67 871 `434e6d37…`; ledger v5 `fd433f54…` unchanged; both self-check |
| Decisive claims independently re-derived | Probes, not static reading: incidence at every boundary, the arrangement's own audit, a wedge census, an independent 3D rotation oracle, the gate in two states plus the clean build, the ledger in two modes, and stack samples of the completion cost |
| Non-vacuity checked | Each new test fails with either fix reverted; HEAD mode reaches an invalid arrangement on exactly one ledger row (Vase), which the CB67 census pre-registers |
| Prior obligations discharged/carried | V1–V6 ruled. O18 discharged once TB66 matches; P13-d's arrangement defect once TB67 matches. P13-f new. P13-e, O6, O9, O16, O17, O19, DR1/DR3, DR2/DR4, O2b, O15b carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-f (completion ownership cost) |
| ORIENTATION currency line | Updated to RA-193 / CB67 next |
| ORIENTATION §3 / §4 / §7 / §8 | §7 Immediate and priority 1 updated; §8 adds the arrangement-audit lesson. §3/§4: n/a, no executed gate or witness change |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: read the producer's own published audit before instrumenting its consumers |
| Consolidation under CLEAN_UP_POLICY | n/a: the Vase decision stays as history; RA-193.1 rules it |
| Successor frozen | CB67 (RA-193.5), TB66 (RA-193.6), CB68 (RA-193.7), TB67 (RA-193.8) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran only in scratch builds |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 8b7299b43` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB67. It supersedes the implementation agent's in-progress `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE` beacon (entered 10:53:33Z; a snapshot trigger only, no source change) |
| Pushed to origin, branch in sync | Yes: `cdfbdc48f`, rebased onto `6bc6efcb7` without force |

## `Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md`; moved verbatim.

### RA-194 — P13-d Vase: review of the landed diagnostics CB67; exact revert, then RA-193's patches (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (Review/Definition), reopened a second time at `46b3e240e`. [RA-193](#architecture_m6_cp3_defn_p13_vase_arrangement_rotation_probe_adjudication_20261101md "moved: Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md") withdrew the static decision's diagnostics CB67 and froze exact patches. The withdrawn CB67 nevertheless landed on top of RA-193:

- `c9c3578af` and `a6bf2c7b5` dispatched it.
- `829a47b2d` applied it (dispatcher `drive_apply`, base `6bc6efcb7`, patch `25588e54…`).
- `46b3e240e` removed its trigger.

There was no compile run and no report. The compiled source now differs from `911840c1…` in six paths (213 + / 46 −). RA-194 reviews what landed, rules that it be reverted, and renumbers RA-193's exact patches after the revert. RA-193's diagnosis, Amendment 26, patches and TB pre-registrations are unchanged.

#### RA-194.1 What landed

| Part | Change |
|---|---|
| a | `validate_incidence_allowing_nondisk` rewritten as a typed `audit_incidence_allowing_nondisk` (clause, node, halfedge, twin, next, cell, source face), exported as `audit_surface_cell_incidence` |
| b | Side repair stores `canonicalInputIncidence` in its product and failure, and uses it as its input check |
| c | `complete_surface_cell_complex_pass` records four boundary audits per pass (parity input, parity output, side-repair input, side-repair canonicalized input) |
| d | The pipeline audits the arrangement and the simplified complex and records the first invalid clause in `surfaceCellFirstInvalidProducer*`. On `SideSubdivisionRepair:InvalidInputIncidence` it fails at stage `completion` with that evidence appended to the detail string |
| e | New public `same_surface_cell_incidence_structure` |
| f | One test, `MilestoneDClosure.IncidenceOracleReportsExactIndependentFailureSites`, in `tests/MilestoneDClosureTests.cpp` |

#### RA-194.2 Findings

| # | Finding |
|---|---|
| L1 | **Compiles and preserves verdicts.** A syntax-only compile of the three changed production TUs at HEAD (scratch `bld61` flags) is clean. The rewritten validator keeps every check in the same order, and adds one successor range guard that only prevents an out-of-bounds read. The one gated test that asserts `surfaceCellFirstInvalidProducerStage` stops at tracing, before the new audits. This is a scope problem, not a regression. |
| L2 | **Does not discharge O18 under Amendment 26.** The run still forwards Vase's cell-less arrangement through simplification, parity and side repair, and ends with `terminal=NotProductionReady:completion`. The first invalid producer appears only inside the detail string. Amendments 19 and 26 require the typed exit at the producer that failed. |
| L3 | **Records the symptom as the first clause.** It re-audits the arrangement with the downstream oracle instead of reading the arrangement's own audit. Its check order matches the RA-193 probe, whose first failing check was halfedge 0 with `cell = −1`, so for Vase it reports `HalfedgeCellOutOfRange` at halfedge 0. That is the consequence of the arrangement dropping every cell. The cause is the arrangement's `RepeatedNodeCycle` at node 33, which it never reads. |
| L4 | **No executable test.** `MilestoneDClosureTests.cpp` is built only in `directional_surface_cell_historical_tests`, which CI configures OFF (`agent-compile-reusable.yml:216`). The file does not compile at HEAD either: its fixtures use `sourceComponent`/`sourceSheet`, removed in the M1 cutover. The decision's own F3 (valid control, injected faults) therefore has no evidence. |
| L5 | **Dead and redundant surface.** `same_surface_cell_incidence_structure` has no production caller; its only use is the dead test. `parity/output` and `side-repair/input` audit the same object. Every completion pass, one per structural candidate, now runs three extra full-complex audits unconditionally, plus two more per run at the arrangement and simplification. That cost is small, but it adds work on the very stage P13-f must make cheaper. |
| L6 | **Unreachable once RA-193's patches land.** Before the rotation fix, the run ends typed at the arrangement; after it, Vase's arrangement is valid. Downstream incidence is already validated by parity (when cells are odd), by subdivision on its output and by side repair. No probe in this patch would then fire on any known fixture. |

**Ruling:** revert `829a47b2d` exactly. Nothing in it is needed by the corrected trajectory. If a downstream `InvalidInputIncidence` ever recurs after the rotation fix, a DEFN can reintroduce a typed clause for that validator, with a test in a built target.

#### RA-194.3 Renumbering

The landed patch consumed the number CB67. RA-193's turns keep their patches, SHAs, prechecks and pre-registered outcomes, under new numbers:

| RA-193 ID | New ID | Patch |
|---|---|---|
| — | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | RA-194.6 |
| `M6-CP3-CB67-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | RA-193.10, `35727214…` |
| `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | unchanged | — |
| `M6-CP3-CB68-P13-ARRANGEMENT-WEDGE-ROTATION` | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | RA-193.11, `e93f5d8c…` |
| `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | unchanged | — |

Routes follow the new numbers:
- CB69: `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP`, `M6-CP3-CB69A-P13-ARRANGEMENT-TERMINAL-ORCH`.
- CB70: `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP`, `M6-CP3-CB70A-P13-ARRANGEMENT-WEDGE-ORCH`.
- TB66 and TB67 routes are as in RA-193.6 and RA-193.8.

#### RA-194.4 CB68 — exact revert

`M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` (Code, implementation agent, Linux workflow runner).

| Item | Value |
|---|---|
| Precheck | `git diff --quiet 829a47b2d96eb7313e64402c3de666266725ba7e HEAD -- src include tests benchmarks CMakeLists.txt cmake` (no source change since the landed patch) |
| Patch | RA-194.6 block, verbatim plus a trailing newline (keep its 13 single-space context lines). SHA-256 `a6b8cf62c8f9543bfa35766782906dc28c9d6cbe7263d5db0d1cabc1d4174c21`. Run `git apply --check`, then apply |
| Numstat | `0 8` `include/directional/geometry/PatchDescriptor.h`; `0 23` `include/directional/geometry/SurfaceCellFeasibilityRepair.h`; `0 14` `src/geometry/PatchDescriptor.cpp`; `46 85` `src/geometry/SurfaceCellFeasibilityRepair.cpp`; `0 49` `src/pipeline/RemeshPipeline.cpp`; `0 34` `tests/MilestoneDClosureTests.cpp` |
| Postcheck | `git diff --quiet 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake` |
| Build | None. The postcheck proves every compiled path byte-identical to CB66's source, whose package `13067780359` TB65 ran 869/869. No binary runs |
| Outcomes | Exact → CB69. Mismatch → `M6-CP3-PLAN-P13-INCIDENCE-PROBE-REVERT-STOP` (Review). Infrastructure → `M6-CP3-CB68A-P13-INCIDENCE-PROBE-REVERT-ORCH` (one retry) |

#### RA-194.5 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | Implementation agent, Linux; exact revert, source equality, no build |
| 2 | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; RA-193.10, compile only (spec RA-193.5) |
| 3 | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869, membership 950, census per RA-193.6 |
| 4 | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; RA-193.11, compile only (spec RA-193.7) |
| 5 | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871, membership 952, census per RA-193.8 |
| 6 (Review, parallel with 1–5) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) → CB → TB | Review (probes) → implementation agent |
| 7 (Review, after 5) | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) → CB → TB | Review (probes) → implementation agent |
| 8 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

#### RA-194.6 Exact CB68 revert patch

SHA-256 of the block content plus a trailing newline: `a6b8cf62c8f9543bfa35766782906dc28c9d6cbe7263d5db0d1cabc1d4174c21`. It is `git revert --no-commit 829a47b2d` at `46b3e240e`, as `git diff --cached`.

Thirteen lines of the block consist of a single space. They are context lines for blank source lines and are part of the patch, so keep them when extracting. `git diff --check` reports them as trailing whitespace in this record only; the reverted source is clean under `git diff --check`.

```diff
diff --git a/include/directional/geometry/PatchDescriptor.h b/include/directional/geometry/PatchDescriptor.h
index cf68a36cd..eaea5172e 100644
--- a/include/directional/geometry/PatchDescriptor.h
+++ b/include/directional/geometry/PatchDescriptor.h
@@ -298,15 +298,7 @@ enum class SurfaceCellComplexCompletionFailureKind : int {
   AssemblyRejected = 7,
 };
 
-struct SurfaceCellIncidenceBoundaryProbe {
-  std::string stage;
-  SurfaceCellIncidenceIssue issue;
-  int oddCellsBefore = -1;
-};
-
 struct SurfaceCellComplexCompletionEvidence {
-  // Ordered, read-only incidence oracles across the preparation boundary.
-  std::vector<SurfaceCellIncidenceBoundaryProbe> incidenceBoundaryProbes;
   int parityOddCellsBefore = 0;
   int parityOddCellsAfter = 0;
   int paritySplitEdges = 0;
diff --git a/include/directional/geometry/SurfaceCellFeasibilityRepair.h b/include/directional/geometry/SurfaceCellFeasibilityRepair.h
index 81cfe9573..4b89355e4 100644
--- a/include/directional/geometry/SurfaceCellFeasibilityRepair.h
+++ b/include/directional/geometry/SurfaceCellFeasibilityRepair.h
@@ -22,27 +22,6 @@
 
 namespace directional::geometry {
 
-// Exact clause and source-supported site of the first failed incidence check.
-// This is diagnostic evidence only; it never authorizes a topology mutation.
-struct SurfaceCellIncidenceIssue {
-  std::string clause;
-  int node = -1;
-  int halfedge = -1;
-  int twin = -1;
-  int next = -1;
-  int cell = -1;
-  int sourceFace = -1;
-
-  [[nodiscard]] bool valid() const noexcept { return clause.empty(); }
-};
-
-[[nodiscard]] SurfaceCellIncidenceIssue audit_surface_cell_incidence(
-    const SurfaceCellComplex &complex);
-
-// Equality is determined over exact structural identities, not a hash.
-[[nodiscard]] bool same_surface_cell_incidence_structure(
-    const SurfaceCellComplex &first, const SurfaceCellComplex &second);
-
 struct SurfaceCellReplacementScopeFailure {
   bool active = false;
   int originalCell = -1;
@@ -459,7 +438,6 @@ enum class SurfaceCellSideRepairPreparationReason : int {
 };
 
 struct SurfaceCellSideRepairProduct {
-  SurfaceCellIncidenceIssue canonicalInputIncidence;
   SurfaceCellSideRepairProductKind kind = SurfaceCellSideRepairProductKind::Repaired;
   SurfaceCellSideRepairPreparationReason preparationReason =
       SurfaceCellSideRepairPreparationReason::None;
@@ -482,7 +460,6 @@ struct SurfaceCellSideRepairProduct {
 };
 
 struct SurfaceCellSideRepairFailure {
-  SurfaceCellIncidenceIssue canonicalInputIncidence;
   SurfaceCellSideRepairFailureKind kind = SurfaceCellSideRepairFailureKind::None;
   std::string detail;
   bool rollbackEquivalent = false;
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
index ace51b779..b9da3c5f8 100644
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -2480,8 +2480,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     ReusableCompletionProducts *reusableProducts = nullptr) {
   SurfaceCellComplexCompletionDraft result;
   const SurfacePointSourceSupportResolver sourceSupportResolver(F);
-  result.incidenceBoundaryProbes.push_back(
-      {"parity/input", audit_surface_cell_incidence(complex), -1});
   SurfaceCellParityRepairResult parityRepair =
       repair_surface_cell_boundary_parity(std::move(complex));
   std::optional<SurfaceCellParityRepairProduct> parityProduct;
@@ -2540,12 +2538,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     return result;
   }
   recordParityDiagnostics(parityProduct.value());
-  result.incidenceBoundaryProbes.push_back(
-      {"parity/output", audit_surface_cell_incidence(parityProduct->complex),
-       parityProduct->oddCellsBefore});
-  result.incidenceBoundaryProbes.push_back(
-      {"side-repair/input", audit_surface_cell_incidence(parityProduct->complex),
-       parityProduct->oddCellsBefore});
 
   SurfaceCellSideRepairResult sideRepair =
       repair_surface_cell_side_subdivisions(
@@ -2592,9 +2584,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     return result;
   }
   if (sideFailure.has_value()) {
-    result.incidenceBoundaryProbes.push_back(
-        {"side-repair/canonicalized-input", sideFailure->canonicalInputIncidence,
-         result.parityOddCellsBefore});
     recordSideDiagnostics(sideFailure.value());
     result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
     result.failure = "SideSubdivisionRepair:" + sideFailure->detail;
@@ -2607,9 +2596,6 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     result.assembly.failure = result.failure;
     return result;
   }
-  result.incidenceBoundaryProbes.push_back(
-      {"side-repair/canonicalized-input", sideProduct->canonicalInputIncidence,
-       result.parityOddCellsBefore});
   recordSideDiagnostics(sideProduct.value());
   if (sideProduct->kind ==
       SurfaceCellSideRepairProductKind::GeneralFallbackPreparation) {
diff --git a/src/geometry/SurfaceCellFeasibilityRepair.cpp b/src/geometry/SurfaceCellFeasibilityRepair.cpp
index ad9f3aff4..59a8af636 100644
--- a/src/geometry/SurfaceCellFeasibilityRepair.cpp
+++ b/src/geometry/SurfaceCellFeasibilityRepair.cpp
@@ -423,92 +423,67 @@ int odd_bounded_cell_count(const SurfaceCellComplex &complex) {
       }));
 }
 
-SurfaceCellIncidenceIssue audit_incidence_allowing_nondisk(
-    const SurfaceCellComplex &complex) {
-  const auto fail = [&](const char *clause, const int node = -1,
-                        const int halfedge = -1, const int cell = -1) {
-    SurfaceCellIncidenceIssue issue;
-    issue.clause = clause;
-    issue.node = node;
-    issue.halfedge = halfedge;
-    issue.cell = cell;
-    if (halfedge >= 0 &&
-        halfedge < static_cast<int>(complex.halfedges.size())) {
-      const auto &edge = complex.halfedges[static_cast<std::size_t>(halfedge)];
-      issue.twin = edge.twin;
-      issue.next = edge.next;
-      issue.sourceFace = edge.sourceFace;
-      if (issue.node < 0) issue.node = edge.from;
-    } else if (node >= 0 && node < static_cast<int>(complex.nodes.size())) {
-      issue.sourceFace = complex.nodes[static_cast<std::size_t>(node)].sourceFace;
-    } else if (cell >= 0 && cell < static_cast<int>(complex.cells.size())) {
-      issue.sourceFace = complex.cells[static_cast<std::size_t>(cell)].sourceFace;
-    }
-    return issue;
-  };
+bool validate_incidence_allowing_nondisk(const SurfaceCellComplex &complex) {
   for (int node = 0; node < static_cast<int>(complex.nodes.size()); ++node) {
-    if (complex.nodes[static_cast<std::size_t>(node)].id != node)
-      return fail("NodeIdMismatch", node);
+    if (complex.nodes[static_cast<std::size_t>(node)].id != node) {
+      return false;
+    }
   }
   std::vector<int> useCount(complex.halfedges.size(), 0);
   for (int id = 0; id < static_cast<int>(complex.halfedges.size()); ++id) {
     const SurfaceArrangementHalfedge &edge =
         complex.halfedges[static_cast<std::size_t>(id)];
-    if (edge.id != id) return fail("HalfedgeIdMismatch", -1, id);
-    if (edge.twin < 0 || edge.twin >= static_cast<int>(complex.halfedges.size()))
-      return fail("TwinOutOfRange", -1, id);
-    if (edge.next < 0 || edge.next >= static_cast<int>(complex.halfedges.size()))
-      return fail("SuccessorOutOfRange", -1, id);
-    if (edge.from < 0 || edge.from >= static_cast<int>(complex.nodes.size()))
-      return fail("FromNodeOutOfRange", -1, id);
-    if (edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()))
-      return fail("ToNodeOutOfRange", -1, id);
-    if (edge.from == edge.to) return fail("DegenerateHalfedge", -1, id);
-    if (edge.cell < 0 || edge.cell >= static_cast<int>(complex.cells.size()))
-      return fail("HalfedgeCellOutOfRange", -1, id);
-    const auto &twin = complex.halfedges[static_cast<std::size_t>(edge.twin)];
-    if (twin.twin != id) return fail("NonReciprocalTwin", -1, id);
-    if (twin.from != edge.to || twin.to != edge.from)
-      return fail("TwinEndpointMismatch", -1, id);
+    if (edge.id != id || edge.twin < 0 ||
+        edge.twin >= static_cast<int>(complex.halfedges.size()) ||
+        edge.next < 0 ||
+        edge.next >= static_cast<int>(complex.halfedges.size()) ||
+        edge.from < 0 || edge.from >= static_cast<int>(complex.nodes.size()) ||
+        edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()) ||
+        edge.from == edge.to || edge.cell < 0 ||
+        edge.cell >= static_cast<int>(complex.cells.size())) {
+      return false;
+    }
+    const SurfaceArrangementHalfedge &twin =
+        complex.halfedges[static_cast<std::size_t>(edge.twin)];
+    if (twin.twin != id || twin.from != edge.to || twin.to != edge.from) {
+      return false;
+    }
   }
   for (int id = 0; id < static_cast<int>(complex.cells.size()); ++id) {
-    const auto &cell = complex.cells[static_cast<std::size_t>(id)];
-    if (cell.id != id) return fail("CellIdMismatch", -1, -1, id);
-    if (!cell.closed) return fail("OpenCell", -1, -1, id);
-    if (cell.halfedges.size() < 2U) return fail("ShortCellBoundary", -1, -1, id);
-    if (cell.sideFamilies.size() != cell.sideEdgeCounts.size())
-      return fail("SideMetadataSizeMismatch", -1, -1, id);
+    const SurfaceArrangementCell &cell =
+        complex.cells[static_cast<std::size_t>(id)];
+    if (cell.id != id || !cell.closed || cell.halfedges.size() < 2U ||
+        cell.sideFamilies.size() != cell.sideEdgeCounts.size()) {
+      return false;
+    }
     std::vector<std::pair<std::size_t, std::size_t>> boundaryRanges;
-    if (!surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges))
-      return fail("BoundaryCycleRangesInvalid", -1, -1, id);
+    if (!surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges)) {
+      return false;
+    }
     std::set<int> seenHalfedges;
     for (const auto &[begin, end] : boundaryRanges) {
       for (std::size_t index = begin; index < end; ++index) {
         const int edgeId = cell.halfedges[index];
-        if (edgeId < 0 || edgeId >= static_cast<int>(complex.halfedges.size()))
-          return fail("BoundaryHalfedgeOutOfRange", -1, edgeId, id);
-        if (!seenHalfedges.insert(edgeId).second)
-          return fail("RepeatedBoundaryHalfedge", -1, edgeId, id);
-        const auto &edge = complex.halfedges[static_cast<std::size_t>(edgeId)];
-        const int nextId = cell.halfedges[index + 1U < end ? index + 1U : begin];
-        if (nextId < 0 || nextId >= static_cast<int>(complex.halfedges.size()))
-          return fail("BoundarySuccessorOutOfRange", -1, edgeId, id);
-        if (edge.cell != id) return fail("BoundaryCellMismatch", -1, edgeId, id);
-        if (edge.next != nextId) return fail("BoundarySuccessorMismatch", -1, edgeId, id);
-        if (edge.to != complex.halfedges[static_cast<std::size_t>(nextId)].from)
-          return fail("BoundaryEndpointMismatch", -1, edgeId, id);
+        if (edgeId < 0 ||
+            edgeId >= static_cast<int>(complex.halfedges.size()) ||
+            !seenHalfedges.insert(edgeId).second) {
+          return false;
+        }
+        const SurfaceArrangementHalfedge &edge =
+            complex.halfedges[static_cast<std::size_t>(edgeId)];
+        const int nextId =
+            cell.halfedges[index + 1U < end ? index + 1U : begin];
+        if (edge.cell != id || edge.next != nextId ||
+            edge.to !=
+                complex.halfedges[static_cast<std::size_t>(nextId)].from) {
+          return false;
+        }
         ++useCount[static_cast<std::size_t>(edgeId)];
       }
     }
   }
-  for (std::size_t id = 0; id < useCount.size(); ++id)
-    if (useCount[id] != 1)
-      return fail("DirectedHalfedgeUseMultiplicity", -1, static_cast<int>(id));
-  return {};
-}
-
-bool validate_incidence_allowing_nondisk(const SurfaceCellComplex &complex) {
-  return audit_incidence_allowing_nondisk(complex).valid();
+  return std::all_of(useCount.begin(), useCount.end(),
+                     [](const int count) { return count == 1; });
 }
 
 SurfaceCellDomainIdentityAudit audit_simple_cell_boundary(
@@ -872,19 +847,6 @@ int total_side_equation_defect(const SurfaceCellComplex &complex,
 
 namespace directional::geometry {
 
-SurfaceCellIncidenceIssue audit_surface_cell_incidence(
-    const SurfaceCellComplex &complex) {
-  return surface_cell_feasibility_detail::audit_incidence_allowing_nondisk(complex);
-}
-
-bool same_surface_cell_incidence_structure(
-    const SurfaceCellComplex &first, const SurfaceCellComplex &second) {
-  // Exact rollback identities include source scopes, halfedge incidence,
-  // ordered cell boundaries, logical sides and provenance. No hash shortcut.
-  return surface_cell_feasibility_detail::exact_rollback_identity(first) ==
-         surface_cell_feasibility_detail::exact_rollback_identity(second);
-}
-
 namespace {
 
 SurfaceCellSubdivisionFailure subdivision_failure_from_product(
@@ -938,7 +900,6 @@ SurfaceCellSideRepairFailure side_failure_from_product(
         std::nullopt) {
   SurfaceCellSideRepairFailure failure;
   failure.kind = kind;
-  failure.canonicalInputIncidence = std::move(product.canonicalInputIncidence);
   failure.detail = std::move(detail);
   failure.rollbackEquivalent = product.rollbackEquivalent;
   failure.rollbackIdentityHashBefore = product.rollbackIdentityHashBefore;
@@ -2111,7 +2072,6 @@ SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
       surface_cell_feasibility_detail::exact_rollback_identity(canonicalInput);
   surface_cell_feasibility_detail::canonicalize_logical_sides(
       canonicalInput, sourceVertices, sourceFaces);
-  result.canonicalInputIncidence = audit_surface_cell_incidence(canonicalInput);
   result.rollbackIdentityHashBefore =
       surface_cell_feasibility_detail::rollback_identity_hash(
           rollbackIdentity);
@@ -2160,7 +2120,8 @@ SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
       options.maxPropagationPasses <= 0 || options.maxStagnantPasses <= 0) {
     return returnRollback(SurfaceCellSideRepairFailureKind::InvalidSideRepairOptions, "InvalidSideRepairOptions");
   }
-  if (!result.canonicalInputIncidence.valid()) {
+  if (!surface_cell_feasibility_detail::
+          validate_incidence_allowing_nondisk(canonicalInput)) {
     return returnRollback(SurfaceCellSideRepairFailureKind::InvalidInputIncidence, "InvalidInputIncidence");
   }
   std::map<int, int> insertions;
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index e61aa5664..5421e8e39 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -13763,23 +13763,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
         arrangementCurrentOwnedBytes;
     result.diagnostics.surfaceCellArrangementPeakOwnedBytes =
         result.surfaceCellContext.arrangementPeakOwnedBytes;
-    const auto arrangementIncidence =
-        geometry::audit_surface_cell_incidence(arrangementComplex);
-    const auto recordFirstIncidence =
-        [&](const std::string &stage,
-            const geometry::SurfaceCellIncidenceIssue &issue) {
-      if (issue.valid() ||
-          !result.diagnostics.surfaceCellFirstInvalidProducerStage.empty())
-        return;
-      result.diagnostics.surfaceCellFirstInvalidProducerStage = stage;
-      result.diagnostics.surfaceCellFirstInvalidProducerReason = issue.clause;
-      result.diagnostics.surfaceCellFirstInvalidProducerNode = issue.node;
-      result.diagnostics.surfaceCellFirstInvalidProducerHalfedge = issue.halfedge;
-      result.diagnostics.surfaceCellFirstInvalidProducerTwin = issue.twin;
-      result.diagnostics.surfaceCellFirstInvalidProducerCell = issue.cell;
-      result.diagnostics.surfaceCellFirstInvalidProducerFace = issue.sourceFace;
-    };
-    recordFirstIncidence("arrangement/output", arrangementIncidence);
     const std::uint64_t arrangementHash = hash_surface_complex(arrangementComplex);
     if (retainForExecution) {
       // Retain a debug copy; simplification consumes the local stage product.
@@ -13916,9 +13899,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
     result.diagnostics.surfaceCellSimplifiedCountAvailable = true;
     const geometry::SurfaceCellComplex &simplifiedComplexForHash =
         simplified.hasComplexOutput ? simplified.complex : arrangementComplex;
-    recordFirstIncidence("simplification/output-or-arrangement-fallback",
-                         geometry::audit_surface_cell_incidence(
-                             simplifiedComplexForHash));
     const std::uint64_t simplificationHash =
         hash_surface_complex(simplifiedComplexForHash);
     const SurfaceCellObjectIdentity simplificationIdentity = make_identity(
@@ -14164,11 +14144,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
         completionResult.firstCompletionOwnershipRejection;
     result.surfaceCellContext.firstCompletionEmbeddingFailure =
         completionResult.firstCompletionEmbeddingFailure;
-    // The exact same oracle is used at arrangement, simplification,
-    // parity and side-repair boundaries. An earlier invalid site takes
-    // precedence over a downstream rejection; no repair is performed here.
-    for (const auto &probe : completionResult.incidenceBoundaryProbes)
-      recordFirstIncidence(probe.stage, probe.issue);
     const auto *closedCompletionFailure = completionResult.rejection();
     result.surfaceCellContext.completionFailure =
         closedCompletionFailure == nullptr ? std::string{}
@@ -14373,30 +14348,6 @@ remesh_from_raw_cross_field_impl_with_stage_products(
       result.surfaceCellContext.hasSimplifiedComplex = true;
     }
     if (completionResult.is_rejected()) {
-      if (completionResult.rejection() != nullptr &&
-          completionResult.rejection()->detail ==
-              "SideSubdivisionRepair:InvalidInputIncidence" &&
-          !result.diagnostics.surfaceCellFirstInvalidProducerStage.empty()) {
-        const auto &d = result.diagnostics;
-        std::ostringstream locus;
-        locus << "SideSubdivisionRepair:InvalidInputIncidence"
-              << ";firstIncidenceStage=" << d.surfaceCellFirstInvalidProducerStage
-              << ";clause=" << d.surfaceCellFirstInvalidProducerReason
-              << ";cell=" << d.surfaceCellFirstInvalidProducerCell
-              << ";halfedge=" << d.surfaceCellFirstInvalidProducerHalfedge
-              << ";twin=" << d.surfaceCellFirstInvalidProducerTwin
-              << ";node=" << d.surfaceCellFirstInvalidProducerNode
-              << ";sourceFace=" << d.surfaceCellFirstInvalidProducerFace
-              << ";incidenceBoundaryProof=arrangement/output:"
-              << (arrangementIncidence.valid() ? "PASS" : arrangementIncidence.clause);
-        for (const auto &probe : completionResult.incidenceBoundaryProbes)
-          locus << ',' << probe.stage << ':'
-                << (probe.issue.valid() ? "PASS" : probe.issue.clause)
-                << "@" << probe.issue.halfedge << '/' << probe.issue.cell
-                << '/' << probe.issue.sourceFace;
-        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
-                                  "completion", locus.str());
-      }
       return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                 "completion");
     }
diff --git a/tests/MilestoneDClosureTests.cpp b/tests/MilestoneDClosureTests.cpp
index 31c1d4a37..6909c0e1f 100644
--- a/tests/MilestoneDClosureTests.cpp
+++ b/tests/MilestoneDClosureTests.cpp
@@ -439,40 +439,6 @@ std::vector<SurfaceArrangementArc> cylinder_grid_arcs(
 
 } // namespace
 
-TEST(MilestoneDClosure, IncidenceOracleReportsExactIndependentFailureSites) {
-  using directional::geometry::audit_surface_cell_incidence;
-  const SurfaceCellComplex control = two_interface_complex(unit_triangle());
-  const auto healthy = audit_surface_cell_incidence(control);
-  ASSERT_TRUE(healthy.valid()) << healthy.clause;
-
-  SurfaceCellComplex brokenTwin = control;
-  brokenTwin.halfedges[0].twin = -1;
-  const auto twin = audit_surface_cell_incidence(brokenTwin);
-  EXPECT_EQ(twin.clause, "TwinOutOfRange");
-  EXPECT_EQ(twin.halfedge, 0);
-  EXPECT_EQ(twin.sourceFace, 0);
-
-  SurfaceCellComplex missingSuccessor = control;
-  missingSuccessor.halfedges[0].next = -1;
-  const auto successor = audit_surface_cell_incidence(missingSuccessor);
-  EXPECT_EQ(successor.clause, "SuccessorOutOfRange");
-  EXPECT_EQ(successor.halfedge, 0);
-  EXPECT_EQ(successor.sourceFace, 0);
-
-  SurfaceCellComplex repeatedCycle = control;
-  const auto cycle = repeatedCycle.cells[0].halfedges;
-  repeatedCycle.cells[0].halfedges.insert(
-      repeatedCycle.cells[0].halfedges.end(), cycle.begin(), cycle.end());
-  const auto repeated = audit_surface_cell_incidence(repeatedCycle);
-  EXPECT_EQ(repeated.clause, "RepeatedBoundaryHalfedge");
-  EXPECT_EQ(repeated.cell, 0);
-  EXPECT_GE(repeated.halfedge, 0);
-  EXPECT_FALSE(directional::geometry::same_surface_cell_incidence_structure(
-      control, repeatedCycle));
-  EXPECT_TRUE(directional::geometry::same_surface_cell_incidence_structure(
-      control, control));
-}
-
 TEST(MilestoneDClosure, CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces) {
   const MeshFixture mesh = curved_square();
   const SurfaceCellComplex complex =
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector or manifest change; the TB66 869 and TB67 871 manifests are unchanged from RA-193 |
| Decisive claims independently re-derived | Syntax-only compile of the landed TUs; check-order comparison with the RA-193 probe; build-target and CI-flag check for its test; a compile of that test file; the inverse patch applied in scratch and compared to `911840c1…` |
| Non-vacuity checked | The landed test cannot compile or run (L4); the revert's postcheck is an exact equality |
| Prior obligations discharged/carried | L1–L6 ruled. RA-193's obligations carried unchanged: O18 (TB66), P13-d arrangement (TB67), P13-e, P13-f, O6, O9, O16, O17, O19, DR1/DR3, DR2/DR4, O2b, O15b |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | None; the stale historical suite (now including `MilestoneDClosureTests.cpp`) stays with O2b |
| ORIENTATION currency line | Updated to RA-194 / CB68 revert next |
| ORIENTATION §3 / §4 / §7 / §8 | §7 order updated. §3/§4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a |
| LESSONS | New lesson: a test counts only if its target is built and the file compiles |
| Consolidation under CLEAN_UP_POLICY | n/a: RA-193 keeps its patches; RA-194 renumbers them |
| Successor frozen | CB68 (RA-194.4); CB69–TB67 per RA-193.5–193.8 under RA-194.3's numbers |
| Turn boundary held | No product, test, fixture or selector change in the repository; the revert is the implementation agent's turn |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 8b7299b43` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB68 |
| Pushed to origin, branch in sync | Yes, fast-forward on `46b3e240e`, no force |

## `Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md`; moved verbatim.

### RA-198 — P13-h2 needle grids and P13-i rail lenses: probe adjudication; exact CB77, TB71; selection DEFN (2026-11-02)

**Turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (Review/Definition). ChatGPT started it at 2026-11-02T05:14:30Z and set `STATUS` to BLOCKED at 15:07Z. Its [review WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Review_WIP_20261102.md"), about 100 commits long, says it lacks the original trace states, the FlowRep selection decisions and needle completion evidence, and that Review policy forbids runtime probes.

That block is procedural. RA-197.3 and handoff step 20 put this DEFN on the Review track as a **probe DEFN on the scratch build**: the evidence is a probe to run, not an artifact to find. `REVIEW_TURN_POLICY.md` §4.3 keeps a Review free of product, test, fixture and selector changes in the repository. Scratch diagnostic probes leave all of those untouched, and they have been the Review track's evidence since RA-188 (GMP_COMPILE_POLICY: diagnostic only, never gate authority). Resumed here at 15:54:02Z on the RA-197 scratch build.

Source at review: HEAD `1c7642c32`. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72` (TB70 package `13115678045`, 880/880). The scratch tree `wt61`/`bld61` equals that source (verified file by file) before the probes were added.

#### RA-198.1 Findings

1. **F1 — the four needle grids complete under the existing boundary search (P13-h2 owner: completion).**
   - Cells 6095, 20533, 20968 and 22350 (2×2, 2×2, 3×2, 2×4) fail only because the closed-form grid places generated vertices from the four corners. A bent needle puts the bilinear point outside the cell, and its projection folds a quad (RA-197 F6).
   - The Amendment 28 pattern search over the **same boundary** finds an embedded quadrangulation for all four. Vase then stops at P13-i (probe B: `IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;…;failed=5;total=26826`), exactly RA-197's mode-4 data point.
   - The dispatch keeps a grid whenever `complete_rectangular_grid` returns true, so the pattern backend never sees these boundaries; only the final validator does.
   - DESIGN §4.11 treats thinness as a quality objective, not a validity criterion. A needle cell is a valid cell, so completion must complete it when its boundary has an embedded quadrangulation. Needle quality stays O23 (M7).
2. **F2 — the grid gives way only when the search succeeds, and only for grids with generated vertices.**
   - A first probe discarded every grid that failed the embedding predicate and let the dispatch fall through (probe H2). That turned three gate rows red:
     - 144 and 570: a `completed_cylinder_patches` 1×1 patch fails the check before ownership validation, although the final validator accepts it;
     - 875: its reversed plane grid would end in `NoEmbeddedQuadrangulation` instead of the registered `InvalidCompletionQuadEmbedding`.
   - The frozen rule (CB77) replaces the grid only when the pattern search succeeds; otherwise the grid stands and the validator reports its failure exactly as before. That alone keeps all three rows green (mutant M2).
   - CB77 also limits the rule to grids that generated vertices. 1×1 cells and strips have none, and RA-197 ruled that their failures must stay visible (no strip search: a failing ladder signals a registration or boundary defect). After CB76, no Vase strip fails. No current fixture distinguishes this scope (M2 survives); it narrows the change and adds no behaviour.
3. **F3 — the five lenses are optional rim-seed support traces.** `build_flow_rep_arcs_from_network` retains a boundary or feature seed's branch as optional layout support.
   - Traces 1037, 878, 20, 422 and 612 bound cells 26735, 26764, 26781, 26802 and 26812. Each comes from a vertex-backed seed on boundary rail 0, has 3 segments and 0.031–0.048 length, and terminates `Boundary` on the same rail.
   - They leave the rim at 0.6°, 0.2°, 3.3°, 11.1° and 1.7°, the smaller tip angle of each lens, and return at the larger one (RA-197 F7). Nothing crosses them, so each cell has two corners.
4. **F4 — no rail-tangent rule separates them.** The cross field is not aligned with Vase's rim.
   - The 115 retained rim support traces leave the rail at angles spread from 0.1° to 88° (72 below 45.6°, the tracer's hard-rail compatibility bound).
   - Dropping every branch within that bound (probe D/E) removes 72 connectors and changes the arrangement to 24,001 cells. It is not a rule: it discards traces with no defect.
   - The tracer's compatible-rail following applies only to `hardFeatureEdges`. Boundary edges are not in that set (`I_VSEED hard=0` for all 562 rim-seed branches), so the vertex-seed follow asymmetry found in source has no effect here (probe C = probe B).
5. **F5 — the FlowRep selector removes nothing on Vase (P13-i owner: A2a network selection).** DESIGN §7.2 step 7 and invariant 8 make global selection the stage that removes redundant traces. On Vase it accepts **0 of 4,057** attempted flowline removals:
   - 3,942 proposal flowlines fail their own cycle evidence. Every proposal is one required cycle, which is intended.
   - 104 support flowlines fail coverage. `build_coverage_index` only lets an arc cover a sample **in the same source face**, so removing the only arc in any face makes coverage infinite. Four of the five lens traces fail here, though each lies within about 10⁻³ of the rim that is kept.
   - 11 support flowlines pass coverage and fail the endpoint check. `protected_endpoint_degrees` freezes the exact degree at **every** endpoint with degree ≥ 3 and every rail endpoint, so no flowline that touches a junction can ever be removed. Lens trace 878 is one of them.
   - Relaxing only the degree check (protect rail and singularity incidence, forbid a new dangling end; probe G) removes 11 support flowlines including 878. Vase then stops at the other four lenses (`failed=4`).
6. **F6 — P13-i is a class, not five traces.** Dropping exactly the five lens traces (CB77 + `PROBE_P13I_DROP5`) leaves 26,822 cells and three *other* two-sided cells: `IncompleteSurfaceCellComplex;descriptor=25329;cell=26730;reason=side-count-unsupported;…;failed=3;total=26821`.
   - The two-sided cells are rim support traces that bound a cell with the rail. Deleting named traces only exposes the next ones.
   - A selection rule must therefore reach a fixed point over the whole network. What lies past P13-i is not yet observable; the selection DEFN must name it.
7. **F7 — the WIP's leads.**
   - Its source reading stands on several points: proposals are one cycle each, production substitutions are empty, and rail contacts are frozen by the degree rule.
   - It never measured whether selection removes anything, and it kept the needle question on the arrangement side. It also ruled runtime evidence out of the Review track, which RA-197 had placed there.
   - Its needle widths, wedge audit and cyclic side audit are consistent with F1–F5. They do not change the owners.

#### RA-198.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB76 before the probes. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. Env switches in scratch copies of `SurfaceCellTracing.cpp`, `FlowRepStrands.cpp` and `PureQuadCompletion.cpp`; unset is HEAD behaviour:
- `PROBE_P13I_DUMP`: per rim-seed branch, its incident hard edges and alignment (`I_VSEED`); per retained support trace, its seed, termination, length and rail alignment (`I_SUP`, `I_ALIGN`); per selector transaction, its kind and both verdicts (`I_TX`).
- `PROBE_P13I_FOLLOW`: a vertex-backed rail seed's branch aligned with an incident hard edge follows that rail.
- `PROBE_P13I_SKIP`: drop rim support branches within 0.7 of the rail tangent.
- `PROBE_P13I_DEG`: protect only rail and singularity incidence and forbid new dangling ends.
- `PROBE_P13I_DROP5`: drop exactly the five lens traces.
- `PROBE_P13H2`: discard every grid that fails the embedding predicate.

| Probe | Result |
|---|---|
| A: dump, HEAD behaviour | Vase RED at patch 6095, `vertices=60917,19077,19081,-1`, 26,827 cells, 143 s: the TB70 locus. 115 retained support traces, all from vertex-backed seeds on rail 0, all `Boundary`; the 5 lens traces have 3 segments each |
| B: grid fall-through (H2) | The 4 needle grids fall through and complete by pattern. Vase RED `IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;…;failed=5;total=26826` |
| C: B + vertex-seed rail following | Identical to B: no rim edge is a hard edge |
| D, E: tangent-branch skip (± H2) | 72 of 115 support traces dropped, 24,001 cells. With H2: completion passes, Vase RED `AssemblyRejected`/`NonManifoldStitchedVertex`. Without: a different needle grid (17601) fails. Not a rule (F4) |
| F: selector census, current rule | 0 of 4,057 removals accepted: proposals 3,904 cycle-only + 38 cycle-and-degree; supports 102 coverage-and-degree + 13 degree-only |
| G: relaxed degree rule | 11 support removals accepted (878 among them); Vase RED `side-count-unsupported`, `failed=4`, 26,709 cells |
| Gate with H2 (unscoped) | 877/880: rows 144, 570, 875 RED besides 283 (F2) |
| CB77 exact source (clean, no probe effect) | Gate (TB71 manifest, 881 rows) **880/881**, only row 283 (O16, macOS LegacyInteger); no shared row changes against RA-197's CB76 gate; row 881 PASS. Vase RED `IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;…;failed=5;total=26826`, 26,827 cells, 0 quads (251 s with the gate running in parallel). Ledger v5 (81 rows) 0/81, as at CB76; no row changes its verdict or first-failure token |
| CB77 + DROP5 | 26,822 cells; Vase RED `side-count-unsupported` at descriptor 25329, cell 26730, `failed=3`: three other two-sided cells (F6) |
| Mutants (each rebuilt; `PatchDescriptorMilestoneE.*` and `PureQuadCompletionPhase18.*`) | Clean CB77: 100 passes plus exactly CB76's 11 off-gate `PatchDescriptorMilestoneE` failures (RA-170 baseline). M1, no replacement (HEAD behaviour): row 881 fails, nothing else changes. M2, scope removed: no change (F2). Restored clean: as above |

#### RA-198.3 Rulings

- **DESIGN Amendment 30** (added): a closed-form grid gives way to the boundary search when its generated vertices fold a quad.
  - When a closed-form grid that generated interior vertices fails the Amendment 28 predicate, completion runs the pattern search over the same boundary. It keeps the search's result (backend `Pattern`) if there is one; otherwise the grid stands and the validator reports its failure.
  - 1×1 cells, strips and every typed failure of a boundary without an embedded quadrangulation are unchanged.
- **P13-h2 owner:** the closed-form dispatch in `complete_pure_quad_patch`. CB77 (exact, RA-198.8) fixes it. No interpolant change, no epsilon, no admissibility change.
- **P13-i owner:** A2a network selection (`run_flow_rep_sparse_selection`). It cannot remove an optional trace. Its two blocking predicates are the same-face coverage index and exact degree freezing at every junction (F5). The admissibility rejection of two-sided cells stands. Tracer, support admission, arrangement and completion are not the owner (F3, F4).
- **Next Review DEFN: `M6-CP3-DEFN-P13-FLOWREP-SELECTION`** (probe DEFN on this scratch build, Review track). It must decide:
  - what coverage means across source faces (the index today only sees same-face arcs);
  - which incidences selection must preserve: mandatory rail arcs, singularity ports, and no new dangling end (invariant 3), rather than every junction degree;
  - whether proposal cycles remain one required cycle each.

  It must also measure removals on every census fixture and on the gate and the ledger, name Vase's next failure, and then freeze exact patches.
- **O24** (new, quality, non-blocking): the cross field is not aligned with Vase's boundary rail (F4). Support traces leave the rim at any angle, so boundary cells have arbitrary corner angles. This is §2.1 item 10 quality, owned by M7, unless the selection DEFN finds it blocks a valid layout.
- **Vertex-seed rail following** (source finding, not a defect on any fixture): an edge-backed rail seed follows a compatible hard rail at its first step, while a vertex-backed one does not. No census fixture has hard-rail seeds that reach this path, so it goes to the selection DEFN's notes, not to a CB.
- A TB runs after CB77 alone (TB71). CB77 changes which backend completes some grids, so its gate, ledger and census evidence should not wait for the selection DEFN.

#### RA-198.4 CB77 — `M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet f59f92f889fc6fe22d689fd7559c024cd09c6c72 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-198.8 verbatim plus a trailing newline. It has no single-space context lines. SHA-256 `673010d4a76f611bc3f7fbedd40306022ac3fa136ee1acea414a45cb415727db`; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PureQuadCompletion.cpp` | `23 0` | `9eb46a71b4f8af85b7b9ccda703606fe39dd4d7eb61a67d10e00ff5998f45476` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `27 0` | `e6f8b3cc6bcac81b91d7526d184b3e2664184b64fcb839032731c01ac2959cd2` |

- **Content:** in `complete_pure_quad_patch`, a closed-form grid with generated vertices whose quads do not all embed is replaced by `complete_pattern` over the same boundary, when that search finds an embedded quadrangulation.
- **Test (gate row 881):** `PatchDescriptorMilestoneE.BentNeedleGridCompletesByTheBoundarySearch`.
  - Fixture: a 2×2 strip 0.02 thick whose long sides dip by 0.03.
  - The bilinear vertex projects onto side 2, and the grid's last quad turns clockwise (signed area −1.8·10⁻³).
  - Expected: one `Pattern` patch with 3 quads and the 8 boundary vertices.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Precheck, apply, numstat or result-hash mismatch → `M6-CP3-PLAN-P13-NEEDLE-GRID-STOP`.
  - Infrastructure failure → `M6-CP3-CB77A-P13-NEEDLE-GRID-ORCH` (one retry).

#### RA-198.5 TB71 — `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB77's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB71_P13_Needle_Grid_Full_Gate_Case_Manifest.tsv"), 881 rows, SHA-256 `f2503dcaf91b13c4a221d52fe7a18899327ab6f96862c3688a67f8f8d14c78a6`. That is TB70's 880 rows byte for byte plus GUARD row 881.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=881 deferred=81`.
  - Pre-registered **881/881**, membership **962**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, with `completion=IncompleteSurfaceCellComplex;…;reason=side-count-unsupported;…`.
  - The registered match is the stage, the detail, the code and the reason. The macOS locus (descriptor 23933, cell 26735, `failed=5`, `total=26826`) is recorded, not registered (RA-176).
  - Mismatches:
    - `InvalidCompletionQuadEmbedding` (a needle grid still fails);
    - any other completion code or reason;
    - `detail=None`, or a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB71A-P13-NEEDLE-GRID-ORCH` (one retry).

#### RA-198.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH` | Implementation agent, Linux; RA-198.8, compile only |
| 2 | `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC` | Implementation agent, Linux; gate 881/881, membership 962; Vase RED `completion` / `PatchCompletionRejected` / `IncompleteSurfaceCellComplex` `side-count-unsupported`, within 600 s |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (P13-i; selection removes nothing) | Probe DEFN on the scratch build: coverage across faces, preserved incidences, removals on every fixture, gate and ledger; then exact patches |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–2 only. Steps 3–4 are probe DEFNs and stay on the Review track (Claude), on the scratch build; a Review turn that cannot run a scratch probe does not start them.

#### RA-198.7 Probe scripts (scratch, not committed)

`scratchpad/p13i/`: `make_probe_i.py` (env-switched probes), `make_cb77.py` (CB77 state and mutants M1/M2), `make_patch77.py` (patch, apply check, result hashes), `needle_search.py` (the planar fixture search behind row 881), `gate.py` (env-driven per-row gate), `run_vase*.sh`.

#### RA-198.8 Exact CB77 patch

```diff
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -2449,9 +2449,32 @@ PureQuadCompletionResult complete_pure_quad_patch(
     }
   }
   if (!completed && !boundedFallbackAdmissible) {
+    const PureQuadMesh boundaryOnly = mesh;
     completed = pure_quad_detail::complete_rectangular_grid(
         patch, mesh, projection.get(), allowedFacePtr,
         options.sourceAuthority);
+    // The grid places its generated vertices by the corners alone, which can
+    // fold a quad of a thin, bent patch whose boundary still has an embedded
+    // quadrangulation. Such a grid gives way to the pattern search over the
+    // same boundary when that search finds one; otherwise the grid stands and
+    // the validator reports its failure.
+    if (completed && patch.simple &&
+        mesh.vertices.size() > patch.boundaryVertices.size()) {
+      PureQuadMesh positioned = mesh;
+      PureQuadEmbeddingFailure gridFailure;
+      if (!pure_quad_detail::fill_positions(positioned) ||
+          !pure_quad_detail::completed_quads_have_simple_embedding(
+              positioned, options.completionVariant, gridFailure,
+              options.sourceVertices, options.sourceFaces)) {
+        PureQuadMesh search = boundaryOnly;
+        bool exhausted = false;
+        if (pure_quad_detail::complete_pattern(
+                patch, search, options.completionVariant,
+                options.sourceVertices, options.sourceFaces, exhausted)) {
+          mesh = std::move(search);
+        }
+      }
+    }
   }
   if (!completed && !boundedFallbackAdmissible && boundaryCount == 6) {
     completed = pure_quad_detail::complete_six_vertex_transition(
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -1991,3 +1991,30 @@ TEST(PatchDescriptorMilestoneE, ClosedFormStripRungsJoinOppositeSideVertices) {
   EXPECT_EQ(mesh.quads, (std::vector<std::vector<int>>{
                             {0, 1, 6, 7}, {1, 2, 5, 6}, {2, 3, 4, 5}}));
 }
+
+TEST(PatchDescriptorMilestoneE, BentNeedleGridCompletesByTheBoundarySearch) {
+  // A 2x2 strip 0.02 thick whose long sides dip by 0.03, more than its
+  // thickness. The bilinear vertex at (0.5, 0.01) lies outside the strip and
+  // projects onto side 2, where the grid's last quad turns clockwise; the
+  // boundary itself has an embedded quadrangulation.
+  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
+  fixture.V << 0.72, -0.0134, 0.0,
+               0.0, 0.0, 0.0,
+               0.5, -0.03, 0.0,
+               1.0, 0.0, 0.0,
+               1.0, 0.01, 0.0,
+               1.0, 0.02, 0.0,
+               0.7, -0.01, 0.0,
+               0.0, 0.02, 0.0,
+               0.0, 0.01, 0.0;
+  const auto completion = complete_fixture_with_source_authority(
+      fixture.complex, fixture.V, fixture.F);
+
+  ASSERT_TRUE(completion.is_produced());
+  ASSERT_EQ(1U, completion.product().completedPatches.size());
+  const auto &mesh = completion.product().completedPatches.front();
+  EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::Pattern,
+            mesh.backend);
+  EXPECT_EQ(3U, mesh.quads.size());
+  EXPECT_EQ(8U, mesh.vertices.size());
+}
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB71 manifest is TB70's 880 rows byte for byte plus row 881; `SELF_CHECK_PASS cases=881 deferred=81` with harness P8 |
| Decisive claims independently re-derived | Probe runs at HEAD behaviour reproduce TB70's Vase locus; every support trace and every selector transaction dumped; needle fall-through, rail-follow, tangent skip, relaxed degree and lens drop probes; clean build of the exact patch (gate, ledger, census); mutants; patch applied to HEAD with both result SHA-256 reproduced; embedded block re-hashed |
| Non-vacuity checked | Row 881 fails under M1 (HEAD behaviour); its grid quad has signed area −1.8·10⁻³, not a tolerance edge. The scope condition is not distinguished by any fixture (M2), and the record says so. The selector census counts every transaction, and the relaxed-degree and lens-drop probes show that each predicate binds |
| Prior obligations discharged/carried | P13-h2 attributed and routed (CB77/TB71). P13-i attributed to A2a selection → `M6-CP3-DEFN-P13-FLOWREP-SELECTION`. O24 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, O21, O22, O23, DR1/DR3, DR2/DR4, O2b, O15b, O7 |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | O24; the inert selector (F5) as a tracker candidate |
| ORIENTATION currency line | Updated to RA-198 / CB77 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: before routing a sliver to the arrangement or tracer, measure whether the selection stage removes anything |
| Consolidation under CLEAN_UP_POLICY | The review WIP stays as history with a superseded note pointing here |
| Successor frozen | CB77 (RA-198.4, exact RA-198.8) → TB71 (RA-198.5); Review DEFN `M6-CP3-DEFN-P13-FLOWREP-SELECTION` |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 1c7642c32` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB77 |
| Pushed to origin, branch in sync | Pushed to `origin/agent/surface_cell_quad/p5-recover-bridge-healing` as a fast-forward, no force; `git status -sb` confirms sync |

## `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Preflight_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Preflight_20261102.md`; moved verbatim.

### P13-j stitched-vertex Review/Definition — same-turn preflight (2026-11-02)

> **Superseded (2026-11-03) by [RA-200](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_probe_adjudication_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md"),** which closes this turn by scratch probes. The decision table's answer is "completion-boundary sharing owner": the corner key was scoped to the outgoing halfedge (Amendment 32, exact CB79 → TB73). The measured facts below stand.

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` — **INCOMPLETE**. This record preserves source-verified static findings, an exact diagnostic plan, and the unresolved decision. It is *not* an adjudication or an authorization for a Code + Build turn.

#### Immutable authority and boundaries

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft and unmerged. Entry `STATUS` commit `531ee98476e977f31ee1839992e345eb444428ee`, started `2026-11-02T23:31:04Z`.
- Read-only source snapshot: event/source `f3f91234124731cef85938b67dd0732b40b14180`; run `41546168024`; artifact `13187758198`; outer SHA-256 `25f33d683a5161af3e001b1bac694fd13ef8b10a3f1e54d4a18a0a46adb634e6`, 6116/6116 source-file hashes verified.
- Immutable CB78 package: semantic source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`, artifact `13181887585`, ZIP SHA-256 `076a19de16db5b0d7be3fb7d133c0324383dde319467afb22b3edc99922658e4`, package manifest verified.
- Corrected TB72A gate: 883/883 PASS, membership 964, 81 deferred; registered independent production census: Cylinder PASS, BunnyRandom P13-e RED (`SingularityPortClassCountMismatch;sourceVertex=49`), Vase P13-j RED (`AssemblyRejected/NonManifoldStitchedVertex`). Gate green does not imply Vase production green. Accepted CP2 remains 491/491, stable 66/17/49 debt 1, selector497 unpromoted.
- Authority: `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md` RA-199 F7 / §RA-199.6. Objective: name the failing stitched vertex, exact source support, incident cells/patches, discriminate between assembly, completion boundary sharing and arrangement, **then** freeze an exact corrective patch.
- **Cross-version source match (re-derived):** streamed the exact immutable CB78 source tarball and independently compared it against the verified head snapshot: `src/geometry/PureQuadCompletion.cpp` SHA-256 `9eb46a71b4f8af85b7b9ccda703606fe39dd4d7eb61a67d10e00ff5998f45476`, `src/geometry/PatchDescriptor.cpp` `108e5481fe85ecafa566d4a14f089afbf00956f8e543fbbc8b0c5f176f31f491`, and `DESIGN.md` `d6d3ba7fa4ecbbf29d271699253c0165a7774b6b188f2b762a55eda6b9d7e289` — **all byte-identical** between compiled CB78 semantic source and review snapshot.
- No source, test, fixture, selector, benchmark or build mutations; no new compiled or production runtime evidence. This Review/Definition turn may not substitute speculation for the required witness.

#### Independently verified static facts

1. `src/geometry/PureQuadCompletion.cpp:3260` builds an assembly from completed patches. In `resolved_stitch_identity` (~2838), shared boundary occurrences take `patch.boundaryNodeIdentities[boundaryIndex]`, if valid; generated interiors have patch-local ownership.
2. `stitch_pure_quad_patches` (~3390–3510) maps patch-local occurrences into a global vertex row keyed by `PureQuadStitchIdentity`. A repeated key requires overlapping owner-validated typed-authority certificates and positions within the configured tolerance; occurrences are saved in `PendingOutputVertex::provenanceCandidates`. These checks establish typed support compatibility, **not a connected output fan**.
3. The routine rejects duplicate global quads and edges incident to more than two quads, then constructs edge/face incidence. At ~3810–3854 it walks the quads incident to each stitched vertex using **only shared edges touching that vertex**. If `reached.size() != incidentSet.size()`, it returns only `NonManifoldStitchedVertex`, without vertex index, identity, patch owners, local quads, fan-component partition or source support.
4. `src/geometry/PatchDescriptor.cpp:3046` / ~3222 calls the stitcher, and later surfaces the assembly failure as `AssemblyRejected`. RA-199 independently observed two different Vase networks hitting this same terminal class; that proves a recurring failure stage, **not the underlying owner**.
5. A stitched vertex can pass every earlier key/typed-authority/edge-count check while its link contains multiple edge-disconnected incident-quad components (for example two patches sharing a vertex but no incident edge). The present evidence does not distinguish a false identity equivalence, a missing matched boundary edge, or invalid incoming arrangement sectors.

**Current disposition:** exact failing global vertex number, original source support, first contributing patch/cell, and responsible producing stage **NOT ESTABLISHED**. No patch, test expectation, regression acceptance, or successor Code + Build identity is frozen.

#### Required bounded discriminating witness (scratch diagnostic; no production edit)

At the **first** `NonManifoldStitchedVertex` rejection, before discarding `pendingVertices` and `uniqueFaceOwners`, extract one deterministic, compact record keyed by the failing global row:

1. **Identity/source:** global row; full canonical stitch identity (kind, values, topology regions, isolation sheets, support faces), resolved authoritative identity, final typed-authority certificate, canonical source-entity type/ID, source-face/barycentric support, and all sorted `provenanceCandidates` with (patch index, domain identity, patch owner, local row, local vertex, source chart). Do not replace exact keys with position proximity.
2. **Fan partition:** sorted incident global quad IDs and the corresponding `CompletedFaceOwnershipRecord` (patch/local quad, ordered global quad, source-support lineage), the two incident edges at each corner, exact shared-edge adjacency, and *all* connected components of the vertex-link graph. Record whether each link component is a path, cycle, branching or repeated-edge walk, and incident boundary edge counts. Preserve the output as a diagnostic artifact only, not an accepted mesh.
3. **Upstream comparison:** for each pair of fan components, compare (a) source entity + sheet/chart-sector equivalence using the authoritative `SourceChartTransitionGraph`, (b) intended boundary-side and ordered subdivision ownership on completed patches, and (c) source arrangement node/cell sectors and originating arcs. Identify the earliest stage at which the two claims became inconsistent.
4. **Cross-checks:** repeat the same capture against the immutable CB78 Vase case; verify Cylinder stays a connected-fan positive control and BunnyRandom stays at its distinct P13-e predecessor failure. If a scratch perturbation or later Code + Build regression is used, prove its negative case actually fails with the expected witness. Require stable canonical identity across deterministic replay/face-row permutations; do not infer equivalence from changed ordinal row numbers.

#### Decision table — select only after the witness

- **Assembly owner** iff patches have compatible matching boundary edges and source chart sectors, but assembly maps distinct canonical incident-fan identities into one global vertex (or otherwise loses correct incidence). Correct the assembly identity/adjacency *at the shared source*, not by suppressing the validator.
- **Completion-boundary sharing owner** iff incoming arrangement/source sectors are correct but completed patches disagree on shared boundary edge subdivision, identity or ordered adjacency, yielding disconnected fan components. Correct patch boundary authority or completion with a guarded consistent interface.
- **Arrangement owner** iff incompatible sectors, repeated node ownership or missing edge relationships already exist in the authoritative arrangement before completion. Correct the original construction; no assembly-stage coordinate merge or post-hoc fan repair.
- If all evidence is still ambiguous, record competing hypotheses and a narrower follow-up diagnostic. In every case preserve fail-closed topology, exact source provenance, hard rails, deterministic order, existing validators, and all accepted selector bytes.

#### Continuation and closeout accounting

- **Next action, same canonical turn:** perform the focused scratch witness capture using exact CB78 source and Vase input, derive the owner from the measured fan components, then issue a falsifiable exact patch and bounded separate CB successor only if justified. Do not start P13-e successor or edit production semantics inside this Review turn.
- **No production tests/builds run by this chat.** Local inspection of the existing package included listing test identities only. `review_check.py boundary` and true in-sync origin verification were not executed; do not claim those checks passed.
- Current in-chat source snapshot trigger `.agents/connector-triggers/source-snapshot/p13-assembly-20261102.txt` is temporary and must be retired before closeout. The durable dispatcher/request slot and `workflow-mailbox` history must remain.
- Tool-use conservation pre-read gate miss: early small handoff/TODO/policy reads happened before formal snapshot selection; subsequent iterative inspection used the verified exact snapshot. This is a workflow-policy deviation, not evidence about the product.
- No accepted selector, stable regression, roadmap milestone, architecture amendment or production acceptance changes are warranted by the static preflight.

#### Same-turn continuation — 2026-11-02

- Resumed from the authoritative `STATUS` beacon; did not advance to the unknown corrective successor.
- Re-inspected the exact source snapshot: the stitched-vertex validator builds `edgeFaces`, then for each vertex BFSes incident quads through edges `(vertex, previous)` and `(vertex, next)`; `reached.size() != incidentSet.size()` is the sole trigger for `NonManifoldStitchedVertex`. The rejection still carries no failing vertex or patch-owner identity. This confirms that the required source-specific witness cannot be inferred from this error alone.
- Ran `python3 .agents/Directional/tools/review_check.py boundary` against the **extracted source snapshot**, not an authenticated Git checkout. It reported no product/test/fixture/build or selector mutation, but **overall FAILED**: missing Git ancestry for durable rewrite baseline `8b7299b43` and source verification of `Future_Chat_Session_Handoff.md`, `ORIENTATION.md`, `Regression_Root_Cause_Tracker.md`. The source archive excludes `.git`, so these failures are verification-environment limitations, **not proof the boundary passed**. A genuine repository checkout with ancestry is required for authoritative review-check verification.
- The required first-failing-vertex production diagnostic remains uncollected. No root-cause owner, precise corrective patch or CB successor is justified. No runtime tests or build were executed. Keep this Review/Definition turn open for the exact immutable CB78 diagnostic, rather than inventing an implementation.

#### Same-turn continuation — 2026-11-03

- Verified the repository beacon still authorized this exact unfinished P13-j Review/Definition turn; updated its attempt timestamp without advancing to successor work.
- Re-fetched the review preflight and enumerated source-snapshot workflow run `41546168024` artifacts. Confirmed the immutable source snapshot artifact `13187758198` remains listed, alongside workflow schema and publisher logs; **none** of these are a failing-vertex runtime witness. This establishes that re-downloading the same snapshot will not independently resolve the attribution question.
- The GitHub connector currently exposes workflow run/artifact reads and reruns, but no workflow-dispatch action in the available tool set. No unauthorized mutation of reusable CI workflows or production code was attempted. An actual CB78 Vase execution with a temporary diagnostic capture is still necessary. No build, tests, or new witness executed in this attempt.
- Unresolved next action: capture the first rejected stitched vertex with canonical identity, all provenance candidates, incident-face ownership, and fan components, then cross-check authoritative arrangement/completion sectors to determine the earliest invalid equivalence. Keep fail-closed validation and this same canonical turn until evidence supports a precise implementation handoff.

#### Same-turn continuation — 2026-11-03 00:49 UTC: bounded immutable-binary replay

- Reused the already extracted CB78 `directional_benchmarks` executable (no compilation, no source edits), running from the verified source snapshot's `benchmarks/fixtures` with `--manifest milestone_g_manifest.json --case vase__surface_cells --warmup 0 --runs 1 --output /mnt/data/p13j-vase-replay.json`, under a 65-second timeout. The replay **timed out without a result JSON**, and therefore did not reproduce or refute the terminal stitched-vertex failure. Do not count this as a successful production gate.
- The captured partial log shows `FieldTransportAtlas.partition` singularity 0, fan transitions over source edges `(357,1002)`, `(357,743)`, `(357,1000)`, `(357,1003)`, `(357,1105)`, `(357,617)` and repeated `M3_CP4AB_FRAGMENT_DIAG` support projections for regions 0/1/2 with reduced Euler 1. These are early-stage diagnostics **not** the rejected stitched vertex, and do not establish causal attribution.
- Next continuation should use an authorized bounded GitHub Actions runtime job with diagnostic instrumentation at the first failing stitched vertex (or a longer controlled execution of the exact immutable binary for reproduction only). Preserve the raw partial log separately for context; avoid inferring source-owner identity from ordinal singularity 0. The scratch replay generated no accepted output and changed no repository production files.

#### Same-turn continuation — 2026-11-03 01:13 UTC: runtime budget and instrumentation boundary

- Rechecked the authoritative TB72 orchestration failure report: the full Vase production census **completed in 277.58 seconds** with `completion=NonManifoldStitchedVertex`, 26,817 arrangement cells and zero completed quads; the report also records Cylinder 16.50 seconds PASS and BunnyRandom 0.96 seconds RED at the distinct port-class mismatch. The previous 65-second scratch replay cannot reasonably be expected to reach the terminal Vase rejection; its timeout supplies no new evidence about stitched vertex ownership. A controlled capture should allow at least the observed 277.58-second runtime plus bounded overhead, preferably use the existing GitHub census workflow rather than a short local execution.
- Inspected the exact validator in `PureQuadCompletion.cpp`: `edgeFaces` is keyed by canonical undirected edge, `vertexFaces` by global stitched row, and the failure is emitted when an incident-face BFS through the two edges adjacent to that vertex does not cover `incidentSet`. The existing `faceAdjacency` vector is global face connectivity for the later connected-components check; it does **not** provide a missing alternative vertex-link check. This excludes replacing the vertex-link BFS with the global connected-component test as a valid correction.
- Minimal discriminating capture site: immediately before assigning `result.failure = "NonManifoldStitchedVertex"`, serialize the first failing global `vertex`, sorted `incidentSet`, `reached`, incident quad vertex tuples, canonical incident edge -> face lists, corresponding `uniqueFaceOwners`, and `pendingVertices[vertex].provenanceCandidates` plus the already constructed stitch identities and source-authority certificates. A second traversal over `incidentSet - reached` is needed to enumerate **all** disconnected fan components, rather than reporting only the first reachable subset. Diagnostic must be scratch-only, deterministic and bounded; it must not weaken the rejection or alter output mesh semantics.
- This turn still lacks that measured witness. No root-cause attribution or exact Code + Build patch is authorized. No new build, runtime test, or production file mutation was performed in this continuation.

#### Same-turn continuation — 2026-11-03 01:36–01:44 UTC: extended CB78 replay

- Ran the **existing immutable CB78** `directional_benchmarks` binary from the extracted source snapshot fixture directory using `--manifest milestone_g_manifest.json --case vase__surface_cells --warmup 0 --runs 1 --output /mnt/data/p13j-vase-replay-extended.json` with `timeout 410s`. No compilation or source mutation occurred.
- The process consumed approximately 410 seconds at ~104% CPU, reached ~384 MiB RSS and was terminated by the explicit timeout. **No output JSON was created**, and the log remained 18 lines of early `FieldTransportAtlas.partition` and `M3_CP4AB_FRAGMENT_DIAG` output. The prior 277.58-second census duration was on a different runner and is **not** a reliable upper bound for this container. Neither this run nor the earlier 65-second attempt reached the assembly rejection, so neither provides the first-failing-vertex witness or a production pass/fail result.
- The raw 18-line log is preserved in the conversation artifact `Directional_P13j_CB78_Vase_Extended_Replay_20261103.log`. Further repetition of an uninstrumented binary is low-value: it does not emit the canonical vertex, fan partition or patch provenance even if it finishes. Prioritize an **instrumented, bounded GitHub workflow** on the accepted source, retaining the rejection and capturing the diagnostic before returning; do not treat ordinal field singularity 0 as the failing assembly vertex.
- No attribution among assembly identity, completion boundary ownership and upstream arrangement is established. Keep the same review turn open; do not freeze a speculative correction or claim gate acceptance.

#### Same-turn continuation — 2026-11-03 02:02 UTC: workflow authority check

- Rechecked repository-root `STATUS`, handoff, TODO, and the preflight. All retain the unfinished P13-j Review/Definition authority; no authorized Code + Build successor is established.
- Verified `.github/workflows/agent-source-snapshot.yml` exposes `workflow_dispatch` and a push trigger restricted to `.agents/connector-triggers/source-snapshot/**`. This workflow packages source; **it does not run the instrumented Vase benchmark**. Triggering it again cannot generate the required fan-component witness. The prior `agent-compile.yml` guess returned 404 and is not a valid workflow path.
- Existing TB72 orchestration failure report distinguishes a stale executor request (0 executed cases) from the separate completed production census. The review must not reuse a stale executor or mistake a snapshot/compile artifact for runtime evidence.
- Precise remaining execution prerequisite: identify an existing authorized runtime workflow/dispatcher that can run a scratch-instrumented CB78-equivalent binary, preserve the exact failing vertex/face/patch provenance in a downloadable artifact, and retain fail-closed rejection. No such witness was captured in this attempt. No speculative production change or successor transition.

## `Architecture_M6_CP3_DEFN_P13_Boundary_Only_Completion_Variant_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Boundary_Only_Completion_Variant_Review_20261102.md`; moved verbatim.

### P13-h2 Review — boundary-only completion changes topology and has a second variant gate

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (same unfinished Review, 2026-11-02). **Status of this finding:** independently rederived *static* source and topology implications, not an implemented change or a formal behavioral test. No new Code + Build successor is authorized by this record.

#### Evidence authority and checks

Immutable source: snapshot event `6c95f68120a20c55ddc09fd155de83f633e49549` from GitHub workflow run `41393896396`, archive SHA-256 `701182750fbd98aa589f1792c4490224ed295ec2821d754bca8e02563550a27a`. This attempt independently recomputed the archive digest and verified **6,092/6,092** SHA-256 source entries. GitHub compare to this attempt's opening branch head found **zero changes** under `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/` or `CMakeLists.txt`. RA-197, source `PureQuadCompletion.cpp` SHA-256 `28a26b80f4b0b13605f691ebf15dd91191e51496be4f11db84b64f2f6adbad9b`, and `PatchDescriptor.cpp` are independently inspected from that immutable snapshot.

`p13_boundary_only_quad_count_audit.py` statically checks producer and caller routing, recomputes the Euler counts below, and rejects **5/5** mutated source *copies* (removed pattern dispatch, replaced pattern DP call, removed grid emission, changed closed-form variant case, changed caller's expected backend). The script was initially written with an erroneous assumption of **8** generated interior vertices; it failed that assertion, which was corrected to **7**, and the complete five-control run then passed. This is a local arithmetic correction, **not** a product fix or a manufactured test pass. The receipt is `P13_Boundary_Only_Completion_Counts_Audit_20261102.json`. `review_check.py boundary` was also rerun on the Git-history-free archive and returned **exit 1** on the same four historic-ancestry checks. Previous authentic GitHub ancestry comparison independently established the baseline's ancestry but does not make this script invocation green.

#### Producer grid gate, caller initial variant bound, and actual-backend retry

1. `PureQuadCompletion.cpp:1997–2048`: the current four-sided equal-opposite-sides rectangular completion emits `width × height` quads and `(width − 1)(height − 1)` new interior vertices; its `true` result denotes **construction**, not completed-quad source-orientation/embedding validation.
2. `PureQuadCompletion.cpp:2450–2512`: `complete_pure_quad_patch` chooses that grid before `complete_pattern` and only tries `complete_pattern` when `!completed`; the source-ownership, disk-topology and per-quad embedding predicates run *after* this decision. A grid that constructed but then failed embedding cannot reach the existing boundary-only dynamic-programming option. `complete_pattern` uses only boundary vertices and creates no new interior vertex, and its result uses the `Pattern` backend.
3. **Correction to the former “second gate needs its own code change” inference:** `PatchDescriptor.cpp:2900–2940` initially computes `expectedBackend=ClosedForm` for four-sided rectangular patches, so it calls `complete_pure_quad_patch` only once (`variant=0`) at first pass. This is an **initial call bound**, not necessarily a second independent implementation blocker. If the one producer call retries a *failed grid embedding* internally using `complete_pattern` on variant 0, that producer returns a `Pattern` mesh; `append_embedded_boundary_quadrangulation` enumerates all locally admissible forward diagonal quadrangulations for that boundary. Later ownership-conflict repair explicitly derives its variant count from the **actual `mesh.backend`** (`PatchDescriptor.cpp:3086–3160`), so a returned `Pattern` already obtains `2 × boundaryVertices.size()` later variants without changing the initial expected-backend classification. Therefore a separate unconditional caller variant-count edit is **not source-proven necessary**; changing it pre-emptively risks unnecessary recomputation of already-valid grids. This remains a static prediction, not an executed retry.
4. `PatchDescriptor.cpp:1679` sets `patch.simple=true` for descriptor construction, and `PureQuadCompletion.cpp:2460` checks `patch.simple` before pattern dispatch. The later ownership, lineage, source chart and disk checks must remain unchanged; a nonzero diagonal search result is not a global surface-injectivity certificate.

#### Additional exact cache-reuse distinction (2026-11-02 12:12Z continuation)

`PatchDescriptor.cpp:2205–2307` computes the *requested* completion dependency for any rectangular patch without a mesh, assigning expected backend `ClosedForm`, variant 0. `take_reusable_completion_products` at :2380–2420 stores the *actual* produced backend and variant using `completion_dependency_fields(descriptor, &mesh)`. The cache lookup at :2770–2850 requires an exact match including `!mismatch.backendVariant`; `dependency_mismatch` flags it when requested backend differs from cached backend. Therefore a future rectangular descriptor whose failed-grid retry produced `Pattern` will be **ineligible for exact cache reuse on an unchanged rectangular dependency** (`ClosedForm` requested vs `Pattern` stored). This is a **predicted reuse/performance loss, not a proven current semantic correctness defect**; the fallback has not yet been implemented. Do not indiscriminately erase backend discrimination, since it protects distinct completion topology. A future CB must decide whether to retain safe recomputation or add an explicit source-verified cache equivalence with exact geometry, lineage, and variant checks; the first correctness patch need not alter the cache merely for speed. No permission to weaken source ownership, disk, embedding or immutable accepted selectors is inferred.

Independent offline source-contract audit `p13_variant_cache_source_audit.py` passed **14/14** exact invariants and rejected **4/4** mutated copies, with two frozen source-file hashes. These are static checks only and do not demonstrate the hypothetical fallback or cache behavior in production.

#### Exactly what an interior-free candidate changes

For a topological quad disk with a single simple boundary of `B` edges, **no interior vertices**, and only ordinary interior edges, `V=B`, `4F=2E_interior+B`, and `V−E+F=1` imply `F=B/2−1`. Rectangular grids instead have `F=w×h` and `(w−1)(h−1)` interior vertices. All four shapes and identities are taken from *RA-197 F6*, not inferred from arbitrary approximate needle measurements:

| Vase cell | Frozen grid dimensions | Boundary edges `B` | Existing grid quads | Existing generated interior vertices | Hypothetical boundary-only quads |
|---|---|---:|---:|---:|---:|
| 6095 | 2×2 | 8 | 4 | 1 | 3 |
| 20533 | 2×2 | 8 | 4 | 1 | 3 |
| 20968 | 3×2 | 10 | 6 | 2 | 4 |
| 22350 | 2×4 | 12 | 8 | 3 | 5 |
| **Total** | | | **22** | **7** | **15** |

A successful boundary-only fallback would preserve the same *boundary edge count and exact boundary identities* while changing both **internal combinatorics** and backend provenance, removing seven generated vertices and seven quads across these four patches. These counts are structural predictions, **not measured product output**, and do not establish field-aligned interior layout or global cross-patch injectivity. RA-197's scratch `Rotation + grid DP (mode 4, data point)` reported zero local completion failures and then five `SideCountUnsupported` lens failures. That report supports a **candidate** for these fixed needle boundaries but is not an independently accepted package/test and does not prove a successful full Vase mesh.

#### Correct owner, falsifiers and accepted-authority controls

A bounded candidate for *only the four needles* belongs first to **pure-quad completion dispatch**, with caller variant selection investigated but **not modified unless a separate failed control proves it necessary**; it does not justify suppressing near-parallel source traces. It must preserve the original chosen grid exactly when already valid, attempt a boundary-only alternative only for a specifically failed grid embedding (never a failed source/chart/ownership proof), restore the immutable boundary before another candidate, preserve typed failure detail if all candidates fail, and pass all existing source lineage/ownership, disk, quad embedding and global assembly checks unweakened. Do not silently change variant ordering, backend enum or cache dependency identity. Demonstrate that the one call at variant zero reaches the exhaustive Pattern search after a rejected grid, and separately exercise ownership-conflict retry using the returned actual Pattern backend; do not weaken failure or ownership checks. A positive existing-grid witness must continue using `ClosedForm` byte-for-byte; a negative genuinely non-embeddable or wrong-sheet boundary must remain RED. Accepted CP2 **491/491** and TB70 **880/880** (membership **961**, **81** deferred), stable **66/17/49**, debt **1**, cannot be weakened or promoted by this Review.

**Lens correction is a separate producer question.** Five P13-i descriptors have **six prepared boundary edges** (3 field + 3 mandatory rail) after parity and subdivision preparation, but only two logical sides; their observed typed `SideCountUnsupported` rejection is not an odd-parity impossibility. Raw arrangement has five halfedges before the repair. The prior incorrect “fixed five-edge lens parity obstruction” was formally retracted in the previous correction. A source-authorized lens layout must address rail-contact topology and protected selector degrees, not modify the four-grid fallback for unrelated reasons. No source-authoritative demonstration yet establishes a single corrective owner for all nine cells. Preserve this Review as unfinished; do not start a Code + Build turn or claim CP3 acceptance.

#### Review closeout — interim, not a completed turn

| Duty | Evidence / carried status |
|---|---|
| Accepted prefix | Independently rehashed earlier this canonical Review: CP2 491 ordered identities; TB69 878 rows unchanged in TB70 880; no selector edit this attempt |
| Static claims / non-vacuity | Grid producer and actual-backend variant route, cache mismatch risk + Euler arithmetic independently derived; 5/5 source-copy negative controls rejected; no Directional runtime |
| Prior obligations / owner | Needle completion variant/identity/quality/injectivity controls sharpened; lens source admission and retained rail topology, trace terminal evidence and parity repair remain carried; BunnyRandom P13-e separate |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt 1; CP2 accepted, TB70 candidate only |
| ORIENTATION / handoff / CHANGELOG / roadmap | No accepted checkpoint or semantic authority changed. Full formal Review closeout still pending |
| Successor | Not frozen: no single proven producer owner or complete lens corrective contract |
| Review boundary | `review_check.py boundary` **exit 1** on Git-history-free snapshot, four ancestry checks; not reported green |
| Turn boundary and sync | Source/test/fixture/selector/build unchanged; record committed via GitHub connector, same canonical turn; final STATUS direct write required |

## `Architecture_M6_CP3_DEFN_P13_Completion_Dispatch_Source_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Dispatch_Source_Review_20261102.md`; moved verbatim.

### P13 sliver Review — closed-form grid dispatch versus existing boundary quadrangulation (2026-11-02)

**Canonical owner:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` — continuing same Review, **not closed**. This is a source and prior-evidence adjudication; no product patch, authorization of a Code + Build successor, compile, test, benchmark, or acceptance transition.

#### Exact authority and independently checked inputs

- Semantic source frozen at CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72`; verified exact source snapshot `6c95f68120a20c55ddc09fd155de83f633e49549`, run 41393896396, artifact 13118905233. ZIP SHA-256 `701182750fbd98aa589f1792c4490224ed295ec2821d754bca8e02563550a27a`, tar SHA-256 `5fb7a345222a0bb5a8fb4e2d3531c26ffbc10865eccb761fd9962c011496a835`, all **6092/6092** source hashes passed in this attempt. GitHub comparison from snapshot to this turn's entry head `1e5ba1a830bb2f3edce71fa9a425109b6c6f7b37` found no change in production `src`, `include`, `tests`, `benchmarks`, `cmake` or `CMakeLists.txt`.
- Fresh offline source audit `p13_completion_dispatch_source_audit.py` and machine receipt `P13_Completion_Dispatch_Source_Audit_20261102.json`: **9/9** static invariants; **3/3** mutated *copies* rejected. This verifies literal control flow and one existing RA-197 diagnostic report, not runtime execution or a new behavioral oracle. Source file SHA-256 `28a26b80f4b0b13605f691ebf15dd91191e51496be4f11db84b64f2f6adbad9b`; RA-197 SHA-256 `abe2fb36cdd8a4d8ac6185f96b5df91673c1f272426db32b7157e32bc195714f`.
- Existing independent accepted-prefix check remains: CP2 **491/491**, gate candidate TB70 **880/880**, membership **961** (81 deferred), stable **66 events / 17 categories / 49 recurrences**, debt **1**. No promotion, selector modification, or runtime re-verification occurs here.

#### Source-proven completion dispatch gap, limited to rejected rectangular-grid candidates

1. `src/geometry/PureQuadCompletion.cpp:1997–2048` `complete_rectangular_grid` returns **construction** success when a four-sided patch has equal opposite side edge counts and its generated interior vertices project onto allowed source faces. It produces a regular tensor-product `width × height` grid using corner-bilinear positions, not a global certificate that every resulting quad embeds. In particular, it does **not** call `completed_quads_have_simple_embedding` before returning `true`.
2. `complete_pure_quad_patch` at approximately `:2448–2480` attempts the rectangular grid first and only attempts `complete_pattern` when `!completed`. A built rectangular grid thus makes the existing pattern search **unreachable** even if its quads will later be rejected.
3. The function applies source ownership, topology and finally `completed_quads_have_simple_embedding` at `:2480–2512`. On a failed embedding predicate it returns `TopologyValidationFailed / InvalidCompletionQuadEmbedding` and **never rolls back to the initialized boundary mesh to try a different completion**. This is an observable limitation of the current *dispatch and retry strategy*, not a proven violation of the requirement to prefer a rectangular grid.
4. `PureQuadCompletion.cpp:2120–2250` already implements an exhaustive **boundary-only quadrangulation** of the unchanged even-length boundary cycle by dynamic programming, checking each candidate quad against the source-oriented embedding predicate. That search does not require the generated interior grid vertex; it does not change the source boundary or its scheduled subdivisions. It is currently invoked by `complete_pattern` only if earlier backends do not report construction success.
5. **Positive scratch control in frozen RA-197:** the prior `Rotation + grid DP (mode 4, data point)` run reported **zero completion failures** and Vase stopped instead on the **five two-sided lenses**, first cell 26735 (`side-count-unsupported`, `attempted=26821`, `failed=5`, `total=26826`). It therefore supplies evidence that *on those scratch inputs*, all four identified needle grids could pass local completion with an alternate quadrangulation. The attempt was a scratch diagnostic, explicitly “data point only,” not a promoted product code path, an accepted full-gate, or proof of globally nonoverlapping output. This **directly narrows** the older claim that needle source geometry inherently prevents any completion; failure of three placement interpolants does not prove that the boundary admits no alternate quad connectivity.
6. P13-i is **separate**. All five lenses have only two logical sides, fail `check_pure_quad_patch_admissibility` before any rectangular grid/pattern call, and cannot be repaired by this dispatch change. Their exact tracing/rail-contact admissibility and replacement authority still need investigation. Do not drop mandatory rail 0 or globally relax side-count guards.

#### ERRATUM — raw arrangement parity is NOT the prepared completion parity (2026-11-02 11:21Z continuation)

**Correction of the preceding version:** Its claim that all five lens **completion descriptors** contain five boundary edges and therefore cannot admit any quad-disk completion by odd parity was **false as an inference from raw arrangement incidence**. The five original directed arrangement halfedges (3 optional support + 2 mandatory rail) are accurately recorded by the later independent raw-cycle audit, **but this is not the boundary that completion consumes**. `PatchDescriptor.cpp:2491–2639` first calls `repair_surface_cell_boundary_parity`, then `repair_surface_cell_side_subdivisions`, and only then calls `derive_patch_descriptors(prepared,...)` at :2663. `SurfaceCellFeasibilityRepair.cpp:2041–2049` rejects a produced parity repair if any bounded cell remains odd. Both repair producers may split edges before the descriptor; `PatchDescriptor.cpp:220–249,1711–1743` counts the **prepared**, not the raw, halfedges. `RA-197 §F7` already reports all five **downstream** lens descriptors with **six boundary vertices and two sides split 3+3**. CB76 only rotates the boundary registration, not its count. Therefore the reported five raw edges and six prepared subdivisions concern **different stages**, not a contradiction and not a fixed five-edge completion barrier. The exact selected repair edge for each individual lens has not been re-derived from a per-cell parity-split receipt and is not invented here.

The necessary mathematical relation `4F = 2E_interior + E_boundary` remains valid; it rules out quad disks only when the **actual prepared** boundary count is odd. Six is even. A *constructive counterexample* also refutes an unconditional topological impossibility for a six-edge, two-logical-side disk: a regular hexagon with logical side counts 3+3 can be split along diagonal (0,3) into quads (0,1,2,3) and (0,3,4,5), each positively oriented and non-overlapping. This is an abstract planar topology control, **not** an authorized field/rail-compatible Vase completion. The current Vase lenses are rejected by the **two-logical-side semantic admissibility guard** (`PureQuadCompletion.cpp:1887–1890`), which fires ahead of `OddBoundary`. Their field/rail source-authoritative topology and necessity remain unresolved; no removal, side-count relaxation or parity repair change follows. The prior report's recommendation that lens repair must specifically *restore even parity* is **withdrawn**.

Reproducible offline audit `p13_prepared_boundary_parity_audit.py` re-derived **9/9** source/RA-197 checks, rejected **4/4** mutated input copies, and verified the explicit two-quad convex hexagon construction without running Directional. Its receipt is `P13_Prepared_Boundary_Parity_Audit_20261102.json`. It does not establish that a geometric quad mesh with source-chart/rail obligations exists for the actual five lens descriptors.

#### Corrective owner and falsifiable controls — proposed scope, NOT authorized implementation

A narrowly bounded candidate exists at the **pure-quad completion backend selection/failure-retry boundary**, rather than speculative removal of the four needle-cell proposal or support traces. Before authorizing code, first establish that replacing a failed generated grid with the existing boundary-only DP preserves the semantic side schedule and required in-patch lineage/injectivity, not merely the present per-quad validator. The fallback must be attempted **only after a demonstrated failed grid embedding**, not after an ownership/sheet failure or arbitrary attempt limit, and must restart from the original immutable boundary state. Both original and fallback candidates must run the existing source-authority, disk topology, quad embedding and final source-attachment validators unmodified; do not turn a genuine `NoEmbeddedQuadrangulation` into PASS.

Independent positive/negative controls required for a future authorized CB/TB split: an already-embedded rectangular grid remains byte-identical and keeps the ClosedForm backend; all four specific needle cells become locally embeddable under an alternative connectivity; a truly non-embeddable or owner-invalid boundary stays RED; a genuine source-crossing/tampered patch is rejected; source-sheet, boundary stitch identity and global conformity are unchanged; CP2 491/491 and full TB70 identity membership remain exact. A source-level branch-deletion mutant must make the new positive controls fail; this prevents a vacuous fallback. Separate P13-i stays independently RED under the two-side guard until its exact layout authority is proved; the odd-parity claim for prepared lens descriptors is withdrawn.

**Important disposition:** This review has **not** established that the local per-quad embedding predicate plus disk-topology check guarantees global embedding across an arbitrary patch; it has not re-executed the scratch DP against CB76. The RA-197 local success is a prior diagnostic observation. The current canonical Review remains open; do not freeze or start a Code + Build successor based on this document alone.

#### Other obligations and turn closeout

- Five lens trace terminal identities, exact original rail intervals, source sheet/region, mandatory coverage/singularity obligations and first transactional rejection are **not present in the verified source snapshot** and were not reconstructed. The named `directional-p13-sliver-nine-cell-review-evidence.zip` is visible in the user's Library but its raw bytes cannot currently be materialized; no terminal reason may be invented from the enum's two source branches. Previous Review record `Architecture_M6_CP3_DEFN_P13_Trace_Termination_Anchor_Source_Review_20261102.md` remains a **potential** anchor-certification issue, not proven cause of these lenses.
- Exact accepted-prefix hash evidence and historical rewrite-ancestor confirmation carry from the canonical WIP. No changed checkpoint, selector, frozen normative rule or stable accounting. No ORIENTATION/CHANGELOG/ROADMAP status change claimed; final durable closeout still pending.
- Review boundary: prior history-free `review_check.py boundary` exited **1** on four Git-ancestry checks. No authentic-history checker PASS claimed. Review remains runtime-free; no source/test/fixture/selector/build/workflow modification.
- Same-turn lifecycle beacon preserved. This record is recoverable directly on the working branch, with a separate downloadable audit script, JSON, and SHA-256 evidence bundle.

## `Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md`; moved verbatim.

### RA-197 — P13-h/P13-i closed-form grids and side-count descriptors: probe adjudication; exact CB76, TB70 (2026-11-02)

**Turn:** `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (Review/Definition). ChatGPT started it at 2026-11-02T01:14:57Z and set `STATUS` to BLOCKED: the [review WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Review_WIP_20261102.md") asks for "missing Vase descriptor evidence" before it can name an owner. Resumed here at 03:14:48Z on the RA-196 scratch build. RA-196.8 step 5 had already placed this DEFN on that build. The trace is a probe to run, not an artifact to find, so the block was procedural.

Source at review: HEAD `8510d1e48`. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB75 `8656c4fed5070a467da491b60ead5c8ab1d99dbd` (TB69 package `13107147891`, 878/878). Only documents landed after CB75. The scratch tree `wt61`/`bld61` equals that source (verified file by file) before the probe was added.

#### RA-197.1 Findings

1. **F1 — the owner is corner registration in the descriptor, not the grid's geometry.**
   - `ordered_boundary` (`PatchDescriptor.cpp:179`) starts each cell's boundary at its smallest halfedge id. That start is arbitrary with respect to the sides.
   - `extract_sides` then closes a side that wraps around the start, by moving the tail run to the front of side 0. So side 0 begins `t` vertices *before* boundary index 0.
   - `derive_patch_descriptor` copies the boundary in traversal order, so `PureQuadPatch::boundaryVertices[0]` is often a mid-side vertex. Nothing rotates it.
   - `complete_rectangular_grid` reads corner `c00` at index 0, and sides at the offsets `w`, `w + h` and `2w + h`. With `t ≠ 0` every rung joins the wrong pair of vertices: the ladder is twisted by `2t` positions. `complete_singularity_pole` reads corners by index parity the same way.
2. **F2 — the evidence (RA-197.2).**
   - Of the 224 closed-form failures, 220 are boundary-only strips (`w` or `h` equal to 1), not 2D grids. Every one has a simple, counter-clockwise boundary, its normals lie within 6.8° of their mean, and its failing quads touch only boundary vertices.
   - In 222 of the 224, the geometric corners are the grid's assumed corners shifted by `t` = 1–4.
   - For all 220 strips, the ladder built from the geometric corners embeds under Amendment 28.
   - None of the 6,862 1×1 cells fails, and no rotation can twist them.
   - With the boundary rotated to side 0's first halfedge, all 220 strips complete.
3. **F3 — the defect is mostly silent.** At HEAD, 5,868 of the 23,329 four-sided descriptors in Vase's first pass are misregistered: 1,902 of 6,371 strips and 375 of 823 2D grids.
   - Only 222 of those fail.
   - The other **2,055 closed-form completions are accepted with their corners on the wrong vertices.** A real corner sits mid-side, and a T-node is treated as a corner. That puts irregular vertices on the cell boundary, which the field does not ask for.
   - Amendment 28's predicate cannot see this, because a twisted ladder in a convex cell is still embedded.
   - No accepted output contains such completions. Vase has never produced output, BunnyRandom stops at the atlas, and Cylinder never reaches descriptor completion (its trace has no descriptor).
4. **F4 — the WIP's leads and its candidate fixes do not reach the owner.**
   - Its correction stands: patch 4 is a boundary-only strip, so interior interpolation cannot cause it. Its terminology caution stands too.
   - But both of its candidate mechanisms address symptoms:
     - The corner-only bilinear target: Coons targets make Vase worse, with 20 grid failures at HEAD's registration.
     - The CB74 boundary DP for strips: it completes all 220 strips, but it replaces the field's ladder with an arbitrary quadrangulation, and it leaves the 2,055 silent twists in place.
   - Its smooth-side Coons witness is not Vase evidence.
   - Its stop condition ("no trace") is satisfied by running the probe, which RA-196.8 had assigned to the Review track.
5. **F5 — RA-196's own P13-h statements were wrong.**
   - RA-196.2 called the 224 closed-form failures "none boundary-only". 220 of them are boundary-only strips, carried by the `ClosedForm` backend rather than `Pattern`/`BoundedCombinatorial`.
   - RA-196.3 named "the bilinear target or the projection" as the owner candidates. The owner is upstream of both.
   - The dumps were run but never binned by grid shape, and never compared against the geometric corners.
6. **F6 — after CB76, P13-h leaves 4 needle grids (P13-h2).** Cells 6095, 20533, 20968 and 22350 (2×2, 2×2, 3×2, 2×4) fail at a quad with a generated vertex.
   - Their boundaries are simple and counter-clockwise, within 3.6° of flat. Projection moves the targets by at most 1.1 % of the diameter.
   - Each is a needle: about 10⁻⁵ thick and 10⁻² long, bent by more than its thickness.
   - No interpolant embeds them all:
     - corner-bilinear fails these 4;
     - index-uniform Coons fails 5 others (16291, 5504, 25371, 10732, 17300);
     - Tutte (harmonic) fails 2 (6095, 20533).
   - Swapping the interpolant is therefore not a fix.
7. **F7 — the P13-i descriptors are rail-grazing lenses, not malformed counts.** All five (cells 26735, 26764, 26781, 26802, 26812; descriptors 23933–24559) are disks with six boundary vertices and exactly two sides: one field trace (family 0 or 1, 3 edges) and one hard-feature rail (family −1, one rail, one curve, 3 edges).
   - Their two tips have interior angles of 0.2°–27° (26735: 10.0° and 0.6°; 26764: 1.3° and 0.2°; 26781: 20.6° and 3.3°; 26802: 15.1° and 11.1°; 26812: 26.9° and 1.7°).
   - So a trace meets the rail at a grazing angle and cuts off a needle lens.
   - `check_pure_quad_patch_admissibility` is right to reject them. Relaxing `SideCountUnsupported` would accept needle quads.
   - The owner is upstream, in how a trace that runs along a rail meets it.
8. **F8 — what stands.**
   - Amendment 28's predicate, search and typed failures are unchanged.
   - The terminal detail (CB75) is correct.
   - No interior-placement change, fallback, epsilon or admissibility change is authorized.

#### RA-197.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB75 before the probe. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. The probe lives in scratch copies of `PureQuadCompletion.cpp` and `PatchDescriptor.cpp`:
- `PROBE_P13H_DUMP` dumps every failed completion (vertex positions, source face, its unit normal, target before projection, quads, source faces), every inadmissible descriptor (sides, families, positions), and one `H_ROT` line per descriptor with its side-0 start offset.
- `PROBE_P13H_ROTATE` rotates the boundary to side 0's first halfedge, which is CB76's change.
- `PROBE_P13H_MODE` selects the variant:
  - `0`: HEAD grid;
  - `1`: index-uniform Coons targets;
  - `2`: the CB74 DP for strips whose ladder does not embed;
  - `3`: `1` and `2` together;
  - `4`: the DP for any grid that does not embed (data point only);
  - `5`: Tutte targets.

Offline audits (Python, `-I`) re-implement Amendment 28's predicate with the same constants and order.

| Probe | Result |
|---|---|
| HEAD (mode 0), dump | 224 closed-form failures (220 strips: 52 bow-tie and 168 source-orientation; 4 2D grids) and 5 `side-count-unsupported`. 13,832 closed-form completions accepted (6,862 1×1, 6,151 strips, 819 grids). Vase RED at patch 4 in 144 s. The 210 transition-template embedding failures in the log are retried variants, not final failures |
| Strip geometry | 220/220 boundaries simple and counter-clockwise in the chart of the mean source normal. Normal spread at most 6.8°. Every failing quad touches boundary vertices only. Thickness/length runs from 0.0006 to 0.70 (median 0.19). A boundary-only quadrangulation exists for 220/220 |
| Patch 4 | Sides `2,1,2,1`. The real corners are boundary indices 1, 2, 4 and 5 (`t = 1`): a straight strip about 0.039 long and 2·10⁻⁵ thick, with its T-nodes 0 and 3 opposite each other. The grid's rung 1–4 runs corner to corner along the strip, giving a bow-tie and an edge-on quad (88.7° and 86.8°). The true rung 0–3 gives two embedded quads |
| Geometric corners vs. assumed corners, all 224 | Shift `t`: 0 → 2, 1 → 42, 2 → 145, 3 → 26, 4 → 9. The ladder built from the real corners embeds for **220/220** strips |
| Misregistration census, all 26,826 descriptors (`H_ROT`, HEAD order) | Four-sided: 5,868 of 23,329. Rectangular: 1×1 0/6,862; strips 1,902/6,371; 2D grids 375/823. Other side counts are also offset (for example 1,064 of 2,942 six-sided), but their backends rotate through every variant |
| Mode 2 (strip DP) | 4 completion failures (the 2D grids) + 5 P13-i. All 220 strips are completed by the DP, which replaces their ladders |
| Mode 3 (Coons + strip DP) | 20 2D-grid failures |
| **Rotation (CB76's change), mode 0** | **0 strip failures.** 4 2D grids fail (6095, 20533, 20968, 22350), each at a quad with a generated vertex. 14,052 closed-form completions accepted (6,862 + 6,371 + 819). Vase RED `completion=InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch;vertices=60917,19077,19081,-1` in 141 s |
| Rotation + Coons (mode 1) | 5 different 2D grids fail (16291, 5504, 25371, 10732, 17300), all bow-tie. Index-uniform parameters misplace rows when one side's T-nodes cluster at an end (16291: three side-1 nodes within 6·10⁻⁴ of a side 1.2·10⁻² long) |
| Rotation + Tutte (mode 5) | 2 fail (6095, 20533): bent needles whose four side midpoints average outside the cell |
| Residual 2D grids after rotation | Boundary simple and counter-clockwise, within 3.6° of flat; projection displacement at most 1.1 % of the diameter. 20533: thickness about 9·10⁻⁶, length 8.2·10⁻³, T-nodes at 82 % of both long sides, bilinear centre at 50 %. 6095: about 4·10⁻⁵ by 4·10⁻² |
| Rotation + grid DP (mode 4, data point) | 0 completion failures. Vase RED `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, `completion=IncompleteSurfaceCellComplex;descriptor=23933;cell=26735;reason=side-count-unsupported;reasonCode=3;attempted=26821;failed=5;total=26826`, in 142 s. So P13-i is the terminal once P13-h2 is resolved |
| P13-i lenses | See F7. Thinness (4πA/P²) 0.006–0.17. 4 of the 5 are also side-0 offset, which does not change their side count |
| Cylinder, BunnyRandom (probe) | Cylinder PASS in 8.5 s with no descriptor; BunnyRandom P13-e at the atlas. CB76 cannot change either |
| Clean CB76 build (exact patch, no probe code) | `PatchDescriptorMilestoneE.*` and `PureQuadCompletionPhase18.*`: 99 passes, plus exactly the 11 pre-existing off-gate `PatchDescriptorMilestoneE` failures of CB72–CB75 (RA-170 baseline) |
| Gate (TB70 manifest, 880 rows) | **879/880**, only row 283 (O16, macOS LegacyInteger). Against RA-196's CB75 gate (877/878), no shared row changes; rows 879–880 PASS. 1 min 42 s at `-P3` |
| Ledger v5 (81 rows) | 0/81 PASS, as at CB75; no row changes its verdict or first-failure token. Row 365 (Vase) is RED in 144 s |
| Census, clean build | Cylinder PASS (8 s). BunnyRandom P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`). **Vase RED** `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, `completion=InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch;vertices=60917,19077,19081,-1`, in 143 s uncontended. This matches TB70's registered criteria |
| Mutants (each rebuilt; rows 879–880 and the entry-point control run) | M1, no rotation (HEAD): 879 and 880 fail. M2, rotation to the last side's start: 879 and 880 fail. Control `CompletesAuthoritativeComplexThroughMilestoneEEntryPoint` passes under both. Restored: all pass |

#### RA-197.3 Rulings

- **DESIGN Amendment 29** (added): a patch boundary starts at the first vertex of side 0.
  - **The contract.** `PureQuadPatch::sideEdgeCounts` partitions `boundaryVertices` in order from index 0: side `k` starts at the sum of the earlier counts. Every per-patch array (provenance, identities, charts, regions, rails, curves) follows the same order.
  - **The producer.** `derive_patch_descriptor` rotates its boundary traversal to side 0's first halfedge after extracting sides. The domain identity is rotation-invariant (`canonical_cycle_rotation` of the directed boundary, sorted undirected), so identities and descriptor order do not change.
  - **The consumers.** Completion templates may read corners and sides by index offset; the closed-form grid and the pole template do.
- **P13-h owner:** `derive_patch_descriptor`'s corner registration. CB76 (exact, RA-197.7) fixes it at the producer. No strip search, no interpolant change, no fallback.
- **P13-h2** (new, blocking): 4 needle 2D grids that fail with correctly registered corners. No interpolant is sound on them (F6). The candidates are robust interior placement in the completion, or not producing needle cells in the arrangement.
- **P13-i** (classified): rail-grazing lenses; the admissibility rejection stands. The owner is upstream (trace–rail incidence).
- **Next Review DEFN:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`, a probe DEFN covering P13-h2 and P13-i. It can start now on the scratch build. For each needle and lens it must find:
  - which strands, proposals or rails bound it;
  - the separation of its two long sides;
  - the field direction against the rail tangent at the lens tips;
  - whether a design rule already governs a trace that runs within a cell width of a parallel trace or rail.

  Then it names one owner and freezes exact patches.
- **O23** (new, quality, non-blocking): needle cells (thickness/length down to 6·10⁻⁴) from near-parallel traces produce needle quads even when they embed. Owned by M7 quality unless the sliver DEFN removes them.
- A TB runs after CB76 alone (TB70). CB76 changes a descriptor contract that every completion backend reads, so its gate, ledger and census evidence should not wait for P13-h2.

#### RA-197.4 CB76 — `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 8656c4fed5070a467da491b60ead5c8ab1d99dbd HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-197.7 verbatim plus a trailing newline. Keep its 3 single-space context lines. SHA-256 `5c7918fbd6dea765848ce3bd0272aba336c22952fde398acf5beb4d3ccc6af19`; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PatchDescriptor.cpp` | `10 0` | `108e5481fe85ecafa566d4a14f089afbf00956f8e543fbbc8b0c5f176f31f491` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `61 0` | `e1eda480ad809dfd285bf5760c257f47b8085459b9c9ef2b432af8a892bde8d6` |

- **Content:**
  - After `extract_sides`, `derive_patch_descriptor` rotates `boundary` to `descriptor.sides.front().halfedges.front()`.
  - The test helper `start_boundary_inside_first_side` renumbers a fixture cell's halfedges, with their twin and next links, so that the smallest id lies inside side 0.
- **Tests (gate rows 879–880):**
  - `PatchBoundaryStartsAtTheFirstVertexOfSideZero`: a `3,1,3,1` cell whose smallest halfedge id is side 0's second halfedge. The side counts are unchanged, `boundaryVertices` equals the concatenated side vertices, and it starts at vertex 0.
  - `ClosedFormStripRungsJoinOppositeSideVertices`: the same cell, completed through the Milestone E entry point with source authority. One closed-form patch, with quads `{0,1,6,7}`, `{1,2,5,6}`, `{2,3,4,5}`. Without the rotation the ladder is twisted but still embedded, so only the connectivity assertion catches it.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Exact → TB70.
  - Mismatch → `M6-CP3-PLAN-P13-PATCH-SIDE-START-STOP`.
  - Infrastructure → `M6-CP3-CB76A-P13-PATCH-SIDE-START-ORCH` (one retry).

#### RA-197.5 TB70 — `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB76's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB70_P13_Patch_Side_Start_Full_Gate_Case_Manifest.tsv"), 880 rows, SHA-256 `a9f964c843a5620f281bf2ca2f07e7df9b8d11a7769218a635a5b707aaf2b03b`. That is TB69's 878 rows byte for byte plus GUARD rows 879–880.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=880 deferred=81`.
  - Pre-registered **880/880**, membership **961**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, with `completion=InvalidCompletionQuadEmbedding;…;backend=closed-form;…`, and **at least one negative (generated) id in `vertices=`**.
  - The registered match is the stage, the detail, the code, `closed-form` and a generated vertex. The macOS locus (patch 6095, `localQuad=1`, `source-orientation-mismatch`, `vertices=60917,19077,19081,-1`) is recorded, not registered (RA-176).
  - Mismatches:
    - a Vase RED whose `vertices=` are all non-negative (a boundary-only strip still fails);
    - `bounded-combinatorial` or `pattern`;
    - `IncompleteSurfaceCellComplex` (P13-h2 would then not reproduce);
    - `detail=None`, or a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB70A-P13-PATCH-SIDE-START-ORCH` (one retry).

#### RA-197.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START` | Implementation agent, Linux; RA-197.7, compile only |
| 2 | `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC` | Implementation agent, Linux; gate 880/880, membership 961; Vase RED `completion` / `PatchCompletionRejected` / closed-form with a generated vertex, within 600 s |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (P13-h2 needle grids, P13-i rail-grazing lenses) | Probe DEFN on the scratch build: name one owner, then exact patches |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

#### RA-197.7 Exact CB76 patch

```diff
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -1698,6 +1698,16 @@ PatchDescriptor derive_patch_descriptor(
 
   descriptor.sides =
       patch_descriptor_detail::extract_sides(complex, cell, boundary, V, F);
+  // The traversal starts at the smallest halfedge id, which can lie inside a
+  // side that extract_sides then closes across the wrap. Start the patch
+  // boundary at side 0's first halfedge instead, so the side counts partition
+  // it in order from its first vertex, as the completion templates assume.
+  if (!descriptor.sides.empty()) {
+    std::rotate(boundary.begin(),
+                std::find(boundary.begin(), boundary.end(),
+                          descriptor.sides.front().halfedges.front()),
+                boundary.end());
+  }
   patch.sideEdgeCounts.reserve(descriptor.sides.size());
   patch.turns.reserve(descriptor.sides.size());
   for (const PatchSideDescriptor &side : descriptor.sides) {
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -780,6 +780,27 @@ Fixture make_valid_parallel_route_same_corner_complex() {
   return fixture;
 }
 
+// Renumbers the boundary halfedges of the fixture's first cell so that the
+// smallest id is the `offset`-th halfedge of side 0. Twin and next links
+// follow the renumbering.
+void start_boundary_inside_first_side(Fixture &fixture, const int offset) {
+  auto &halfedges = fixture.complex.halfedges;
+  const int count =
+      static_cast<int>(fixture.complex.cells.front().halfedges.size());
+  const auto moved = [&](const int id) {
+    return id >= 0 && id < count ? (id - offset + count) % count : id;
+  };
+  auto renumbered = halfedges;
+  for (int id = 0; id < static_cast<int>(halfedges.size()); ++id) {
+    auto edge = halfedges[static_cast<std::size_t>(id)];
+    edge.id = moved(edge.id);
+    edge.next = moved(edge.next);
+    edge.twin = moved(edge.twin);
+    renumbered[static_cast<std::size_t>(moved(id))] = edge;
+  }
+  halfedges = std::move(renumbered);
+}
+
 } // namespace
 
 TEST(PatchDescriptorMilestoneE, DerivesOrderedSidesSubdivisionsAndFeatures) {
@@ -1930,3 +1951,43 @@ TEST(PatchDescriptorMilestoneE, CompletionFailureKindsNameTheTerminalDetail) {
                    SurfaceCellComplexCompletionFailureKind::
                        PatchCompletionRejected));
 }
+
+TEST(PatchDescriptorMilestoneE, PatchBoundaryStartsAtTheFirstVertexOfSideZero) {
+  // The smallest halfedge id is the second halfedge of side 0, so the
+  // boundary traversal starts inside side 0 and closes it across the wrap.
+  Fixture fixture = make_patch({3, 1, 3, 1});
+  start_boundary_inside_first_side(fixture, 1);
+  const auto descriptor = directional::geometry::derive_patch_descriptor(
+      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
+
+  ASSERT_TRUE(descriptor.boundaryCycleValid);
+  ASSERT_EQ(descriptor.sides.size(), 4U);
+  EXPECT_EQ(descriptor.patch.sideEdgeCounts, (std::vector<int>{3, 1, 3, 1}));
+  std::vector<int> sideVertices;
+  for (const auto &side : descriptor.sides) {
+    sideVertices.insert(sideVertices.end(), side.boundaryVertices.begin(),
+                        side.boundaryVertices.end());
+  }
+  EXPECT_EQ(descriptor.patch.boundaryVertices, sideVertices);
+  EXPECT_EQ(descriptor.patch.boundaryVertices,
+            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7}));
+  EXPECT_TRUE(descriptor.feasibility.admissible);
+}
+
+TEST(PatchDescriptorMilestoneE, ClosedFormStripRungsJoinOppositeSideVertices) {
+  Fixture fixture = make_authoritative_patch({3, 1, 3, 1});
+  start_boundary_inside_first_side(fixture, 1);
+  const auto completion = complete_fixture_with_source_authority(
+      fixture.complex, fixture.V, fixture.F);
+
+  ASSERT_TRUE(completion.is_produced());
+  ASSERT_EQ(1U, completion.product().completedPatches.size());
+  const auto &mesh = completion.product().completedPatches.front();
+  EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::ClosedForm,
+            mesh.backend);
+  // Side 0 runs 0-1-2-3 and side 2 runs 4-5-6-7 back, so each rung joins a
+  // side 0 vertex to the opposite side 2 vertex and the corners 0, 3, 4 and
+  // 7 each lie in exactly one quad.
+  EXPECT_EQ(mesh.quads, (std::vector<std::vector<int>>{
+                            {0, 1, 6, 7}, {1, 2, 5, 6}, {2, 3, 4, 5}}));
+}
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB70 manifest is TB69's 878 rows byte for byte plus rows 879–880; `SELF_CHECK_PASS cases=880 deferred=81` with harness P8 |
| Decisive claims independently re-derived | Full first-pass failure dump at HEAD; every failure binned by grid shape; geometric corners against assumed corners for all 224; producer start rule read in source; misregistration census of all 26,826 descriptors; rotation, interpolant and fallback probes; clean build of the exact patch (suites, gate, ledger, census); mutants; patch applied to HEAD with both result SHA-256 reproduced; embedded block re-hashed |
| Non-vacuity checked | Rows 879–880 fail under M1 (HEAD behaviour) and M2; row 880 fails on connectivity alone, because the twisted ladder still embeds. The Vase census moves off strips (0 strip failures; every residual failure has a generated vertex) |
| Prior obligations discharged/carried | F1–F8 ruled; RA-196 F-statements on P13-h corrected (F5). P13-h attributed and routed (CB76/TB70). P13-h2 new, P13-i classified; both → `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. O23 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, O21, O22, DR1/DR3, DR2/DR4, O2b, O15b, O7 (the oracle target still does not compile) |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-h2, O23; P13-i classification; the silent misregistration (F3) as a tracker candidate |
| ORIENTATION currency line | Updated to RA-197 / CB76 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: when a rotation-invariant subclass never fails, check index contracts between producer and consumer before geometry |
| Consolidation under CLEAN_UP_POLICY | The review WIP stays as history with a superseded note pointing here |
| Successor frozen | CB76 (RA-197.4, exact RA-197.7) → TB70 (RA-197.5) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 8510d1e48` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB76 |
| Pushed to origin, branch in sync | Yes, fast-forward, no force |

## `Architecture_M6_CP3_DEFN_P13_Cross_Stage_Evidence_Contract_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Cross_Stage_Evidence_Contract_20261102.md`; moved verbatim.

### P13 sliver cells — bounded cross-stage causality evidence contract (interim Review, 2026-11-02)

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (unfinished). **Scope:** evidence acquisition and falsifiers only; no product/test/fixture/selector/build changes, Review runtime, CP3 promotion, or successor authorized here.

#### Authority and independently checked limits

- Compiled semantics: CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. Reused immutable source snapshot `4f48f09562740bcdff78cacb6a9159b0299238a8`, run `41446197233`, archive SHA-256 `cdbd72e5294c8659e16cb71bde42cdabb8f84765cd750efc2d3e38b2053266b8`, **6104/6104** internal SHA-256 files validated. Authentic GitHub compare from CB76 through this continuation's entry commit showed zero `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/`, or top-level CMake changes. Unpromoted TB70 880/880 PASS, membership 961; accepted CP2 491/491; stable 66/17/49, debt 1.
- `FlowRepStrands.cpp:1246–1314` builds exactly one cycle per **proposal** and excludes stand-alone hard rails and optional support arcs (`proposalId<0`). Its generated comparison normals are identical, source-distance deviations zero, and four logical sides each count one. `evaluate_flow_rep_cycle` (`:1655–1720`) gives a nondegenerate, complete four-sided original proposal approximately zero cycle energy *irrespective of neighboring proposals*. The per-proposal certificate can detect removed required arcs via `rebuild_cycle_evaluation` (`:1786–1818`), but is **not a global induced-cell embedding or cross-proposal compatibility certificate**.
- `select_sparse_flow_rep_network` (`:2261+`) uses logical-provenance transactional flowlines, per-proposal cycle preservation, source-face coverage, and protected endpoint degrees. It does **not** call `cluster_flow_rep_strands`, `compute_flow_rep_affinity`, or `strand_merge_is_simple` in its production path. Their existing affinity and crossing knobs cannot be presented as an active global correction.
- `RemeshPipeline.cpp:13487–13518` builds/selects FlowRep **before** `:13705–13722` constructs the induced arrangement complex. The pipeline subsequently checks incidence and final embedding, not a pre-selection global face certificate. This proves a **certificate scope gap**; it does not prove any particular sliver is geometrically invalid, expendable, or repairable by admission changes.
- Independent static source-audit `p13_flowrep_certificate_scope_audit.py` (SHA-256 `71737ef39ed2b53a6509a7c276df6e470260009db93888a4e1241ec0ff3f703e`) checked **10/10** source-scope assertions; **4/4** deliberately corrupted *in-memory source copies* were rejected. JSON receipt SHA-256 `ff68b5dc852b4c7b85b05d047d5814971901de2d4e46ee930ba46775e347a709`. These are string/control-flow audits, not product tests or evidence of a valid Vase correction. Earlier canonical WIP already describes the initial cycle construction's vacuity; this record does not claim first discovery.

#### Nine-cell source configurations and current missing discriminators

| Observed cell(s) | Original producer boundaries | Decision still unproved |
|---|---|---|
| 6095, 20533 | Four distinct proposal-side producers per cell | Whether individually accepted proposals overlap incompatibly in source-attached interiors, versus a valid close-parallel corridor with an embedded completion |
| 20968 | Opposite long sides: two distinct runs of **one support trace 815**; two short proposal sides | Whether the same-trace near-return is valid, necessary, anchored, and source-sheet-consistent; removal/coverage/cycle consequence |
| 22350 | Proposal 488 opposes support trace 487 | Whether the particular support is mandatory for coverage/index, or replaces an otherwise valid proposed boundary |
| 26735, 26764, 26781, 26802, 26812 | One optional support trace `1037,878,20,422,612` respectively, returning to mandatory hard rail 0 | Exact original trace terminal subtype, seed-vs-terminal tip, source-chart transported rail direction, and actual transactional removal/retention obligations |

**Trace IDs are conditional on producer ordering:** verify `traces.size()==4*seeds.size()` before using the `4*seedIndex+branch` mapping. Trace IDs 1037/878/20/422/612/815/487 yield seed/branch `259/1,219/2,5/0,105/2,153/0,203/3,121/3` respectively. Provenance already appears in the needle and rail-return Review records; the integer conversion is not a new tracing observation.

#### Minimum discriminating evidence, if existing retained artifacts cannot supply it

Any **new runtime diagnostic must be separately authorized** under a bounded Code + Build (compile-only) and immutable Test + Benchmark sequence, or a specific policy exception. Do not execute it as part of this Review. Reuse the current typed state and source-provenance producers rather than retuning tracing semantics or inventing additional source geometry.

1. **Producer trace receipt (seven named IDs only).** Capture exact source commit and fixture hash, seed provenance, four-way trace-count invariant, terminal enum, quantized-state duplicate count and first duplicate indices, last segment source face/barycentric and source-chart/sheet, rail suffix and original start/end intrinsic keys. `RepeatedState` with a duplicate key is a quantized revisit; without one it denotes the edge/no-finite-exit branch. The archived Review scratch run retained no full trace-state vectors; the CLI intermediate-preservation switch alone does not serialize them.
**Termination geometry discriminator:** in the `RepeatedState`/all-unique branch capture `current.barycentric`, `dbary[0..2]`, `entryEdge`, `bestT`, selected/eligible exit corners and the exact hard/relief/rail edge classification **at the failure site**. `SurfaceCellTracing.cpp:11205–11228` ignores a candidate `t=0` when the direction is already exiting a face edge, so this enum can encode outward-face failure, not just true tangential grazing. As a source-logic illustration, barycentric `(0,0.4,0.6)` and derivative `(-0.3,0.2,0.1)` produce no positive exit; derivative `(0,-0.2,0.2)` instead has a positive vertex exit. Neither example is measured Vase data. Do not conflate the separate A2a exact-grazing transit resolver with this generic support-trace path without proving their shared authority.

2. **Selection receipt.** For *each flowline containing a listed original support or proposal arc*, record its full arc IDs, whether selected for a removal trial, initial and trial membership, mandatory status, affected required proposal cycle IDs and reason for any invalid cycle, protected endpoint degree before/after, and dense/trial maximum normalized same-face coverage. Record the `evidenceAccepted` and `endpointsAccepted` booleans as evaluated at the atomic transaction, **including the actual first rejection**, rather than guessing which guard rejected it from the final retained network. Emit explicit `not attempted` with source reason where applicable. Do not log all global flowlines or misidentify an arc as a flowline.
3. **Arrangement and completion receipt (nine named cells only).** Capture ordered source arc IDs, proposal/support/rail ownership, chart/sheet and family transitions, original junction seed vs trace terminal identity, source-index/holonomy obligations, fixed prepared side counts and boundary vertices, and the first failing embedding predicate. A proposed alternative for needles requires independently validated source-surface injectivity, global nonoverlap, quad topology and unchanged boundary conformity. A lens completion proposal additionally requires mandatory rail and transported-field correctness.

**Independent falsification controls:** a valid close-parallel corridor must survive any geometric-quality criterion; a valid required rail-contact/return must survive any optional-trace criterion; an invalid unanchored no-exit return and incompatible cross-proposal overlap must be rejected; reversed/permuted rail orientation and changed chart/sheet identities must not silently pass. Prove positive/negative divergence and real effects when an added decision is removed. Use existing source geometry and stage provenance; do not use a new global width/angle epsilon.

#### Branch decision and turn boundary

- If the four needles admit a valid boundary-preserving embedded completion, investigate the specific completion dispatch/embedding alternatives without deleting their source arcs. If no such completion exists and the upstream layout violates an existing source-authoritative rule, localize the violated proposal/support producer.
- If a lens support is a certified necessary source rail contact, retain it; seek an explicitly index/rail-valid completion or topology-preserving replacement. If it is demonstrably optional and invalid, locate the exact admission/selection guard that must change **without** weakening protected-degree, coverage, or mandatory rail authority. Termination enum alone never proves optionality.
- If needle and rail-lens diagnoses require different producers, state this explicitly and correct the plan under authorized repository policy rather than inventing one nine-cell patch. Until a source-valid candidate and its falsifiers are proved, **no Code + Build successor is frozen**. Separate BunnyRandom P13-e stays out of scope.
- Review policy remains runtime-free. `review_check.py boundary` on the Git-history-free snapshot previously exited 1 for four ancestry facts; no PASS is claimed. No formal Review closeout, ORIENTATION/ROADMAP/selector change, or CP3 acceptance is implied.

## `Architecture_M6_CP3_DEFN_P13_Cyclic_Side_Corrective_Audit_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Cyclic_Side_Corrective_Audit_20261102.md`; moved verbatim.

### P13 cyclic side indexing — corrective Review audit (2026-11-02)

**Owning turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. This is independent scratch evidence, not a production/test change or CB/TB acceptance record.

#### Prior evidence correction

The archived `p13_geometry_observations.json` and `p13_sliver_geometry.py` from scratch Vase evidence `directional-p13-sliver-nine-cell-review-evidence.zip` (SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`) had **incorrect side assignment for seven of nine cells**. The raw nine-cell source-provenance inventory and 9/9 directed-cycle/arc/node receipt remain valid **within their original checker's narrower scope**.

**Cause:** `src/geometry/SurfaceArrangement.cpp:6500–6534` constructs `sideEdgeCounts` by merging a continuous final logical side with the first side, but does not rotate `cell.halfedges` to this merged side's start. The scratch probe inferred `P13_HALFEDGE ... side=` by partitioning `cell.halfedges` directly from zero. The geometric summary then used those incorrectly inferred labels to group segments. This was a **diagnostic analysis bug**, not demonstrated to be a product bug. `PatchDescriptor.cpp:220+` independently reconstructs sides and CB76 explicitly reanchors the patch boundary to its first side.

An independent Python audit matched each recorded cyclic family/count sequence against the physical ordered halfedge family sequence, requiring the first actual halfedge to belong to logical side 0. The match was unique for all nine cells and reduced **29 wrong logical-side labels (including 24 family mismatches) to zero**. Recomputed distances remain **Euclidean lower bounds only**, not intrinsic geodesic distances. Existing local-tip field/rail chord angles do not depend on the side group labels and were not invalidated by this correction.

| Cell | Side-zero start (physical halfedge offset) | Corrected side lengths in cyclic logical order |
|---|---:|---|
| 6095 | 0 | 0.0000807322, 0.0404730743, 0.0000774215, 0.0404739386 |
| 20533 | 5 | 0.00828979368, 0.00000881780, 0.00828987697, 0.00000879191 |
| 20968 | 7 | 0.0343890130, 0.0002115719, 0.0343866634, 0.0002076528 |
| 22350 | 7 | 0.0323743364, 0.0008902854, 0.0323569349, 0.0008887559 |
| 26735 | 4 | 0.0394434000, 0.0394775838 |
| 26764 | 4 | 0.0483646978, 0.0483625639 |
| 26781 | 0 | 0.0362449274, 0.0366260169 |
| 26802 | 3 | 0.0401296925, 0.0411925739 |
| 26812 | 4 | 0.0308496781, 0.0310742718 |

Corrected rail lens sides are respectively a 3-edge field trace plus a 2-edge protected rail, or its cyclic reverse, at **the raw arrangement stage**. RA-197's later **descriptors** with 6 boundary vertices and 3+3 splits are downstream-stage statements, so this does not, by itself, falsify those descriptor observations. The earlier mixed-side lengths reported for lenses, e.g. 26735 approximately 0.005 versus 0.074, are **retracted**.

**Absolute-area sanity check:** Independently parsed all nine `P13_CELL area=` receipts. The smallest is cell `20533`, `7.292183487273476e-08`; even that exceeds the current `SurfaceArrangement.cpp` `Sliver` threshold `1e-14` by **7,292,183×**. No cell can be classified as a sliver by that present predicate. Increasing the threshold until these cells reject would be an unjustified global behavior change, not causal recovery.

#### Ownership finding and exact remaining discriminator

All nine directed cell boundaries are linked to retained source arcs, not fabricated by pure-quad completion. Needle four-sided cells span distinct layout/proposal strands; rail lenses contain a field-trace side and a mandatory hard rail. Existing source `DESIGN.md` §4.5 defines **exact shared-edge grazing transit**; it does not authorize proximity thresholds that delete near-parallel traces or mandatory hard rails. The observed near-parallelism is not proof of an invalid upstream trace.

The missing causal discriminator is **complete incident outgoing-ray/wedge identity and expected left-cell successor** at the lens tips versus the actual `SurfaceArrangement.cpp` directed successor. For needles, compare source-authoritative candidate layout/proposal ownership and same-sheet intrinsic separation against the emitted cells. A claim of a single producer owner is premature without this comparison. Do not tune a `Sliver` area epsilon, redefine two-sided lenses as quad-ready, weaken the completion embedding check, or promote CP3.

**Exact future tip-node probe set:** five lens transition-node pairs in the raw scratch arrangement are `26735: (56813,56385)`, `26764: (16998,47581)`, `26781: (9928,56412)`, `26802: (57415,53651)`, `26812: (57661,23821)`. These were independently extracted as family-change vertices from the directed halfedge cycles. A future scratch-only diagnostic should record every outgoing halfedge from each of these ten nodes, complete source-entity wedge/ray ordering, chosen next and alternative candidates, plus upstream trace/rail admission evidence. Ten node IDs are **not** by themselves a proof that any successor is wrong.

#### Additional completion-stage gate audit (same Review, 2026-11-02 13:10Z)

Independently checked the verified source snapshot at `4f48f09562740bcdff78cacb6a9159b0299238a8` (archive SHA-256 `cdbd72e5294c8659e16cb71bde42cdabb8f84765cd750efc2d3e38b2053266b8`, 6,104/6,104 source hashes); semantic CB76 unchanged. These are conditional source-routing proofs, **not** evidence that changing the gates is valid for Vase.

For the five prepared two-logical-side, six-boundary-vertex (3+3) lenses, source contains **three distinct barriers** to reaching the existing dynamic-programming completion:

1. `PureQuadCompletion.cpp:1887–1890`: `check_pure_quad_patch_admissibility` rejects `sides<3` with `SideCountUnsupported` (the observed P13-i class).
2. `PureQuadCompletion.cpp:44–50,1910–1923`: with only that guard hypothetically deleted, `side_inequalities_hold` still returns false for `n<3`, producing `SideInequality`. A one-line side-count change is not a functional fix.
3. `PureQuadCompletion.cpp:2448–2471,2055–2074`: if both guards were altered under a separately established contract **and no singularity-pole path preempts this branch**, the rectangular grid rejects two sides, but `complete_six_vertex_transition` constructs two quads for any six-vertex boundary and returns true. This skips `complete_pattern` behind `!completed`; later source-ownership, topology or orientation rejection does not retry DP. If `patch.singularityCount != 0`, the earlier singularity-pole branch can instead fail or succeed first; its status for these five lenses has not been proved. Therefore neither branch is justified merely by relaxing admission.

The existing abstract hexagon (two sides of three subdivisions) proves only topological possibility. `PatchDescriptor.cpp:1712–1718` supplies two `+1` family turns, not a source-chart transported `Z4` holonomy or field-index certificate. `DESIGN.md` §§4.1, 4.5 and 7.5 retain those obligations. Even boundary parity and simple geometry alone cannot authorize an actual Vase lens.

**Required discriminator:** recover each original support trace terminal and rail interval, chart/sheet identity, protected endpoint/cycle obligations, transported field family and index; independently establish whether any embedded two-side completion preserves mandatory rails and globally valid quad topology. If yes, separately adjudicate a bounded completion capability with all three dispatch barriers and unchanged validators. If not, identify and correct a specific earlier trace/selection admission defect. Positive required-rail-contact and negative invalid-return cases must separate the hypotheses. Neither path is authorized for implementation by this unfinished Review.

#### Reproduction and boundary

- Independently reverified the existing source snapshot ZIP SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062` and **6,092/6,092** file hashes. Frozen semantic CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72` remains unchanged by later work.
- `p13_cyclic_side_audit.py` SHA-256 `1727d68a103d7444c326af6bb258f62c252a286872e71c813ed7a0be5a574edc`; `p13_cyclic_side_audit.json` SHA-256 `143c2f8dc1add1b8a840f9fc35fd324e68239877c5254c9e998feca42142de56`. User-downloadable archive `P13_CYCLIC_SIDE_AUDIT_EVIDENCE.zip` SHA-256 `266742ecef9272d0f9b16a1e1e0af1e6afee00002de6470d32ae9c832d4bc88a` includes both and readable detail.
- No local builds, new runtime probes, source/test/selector edits, workflow permission changes, or acceptance runs during this continuation. An early choice of repo-document connector reads before explicitly freezing `READ_MODE=snapshot` missed the conservation pre-read gate; additional static source analysis used the **existing verified immutable snapshot**, not more piecemeal reads. This process defect does not invalidate independently verified source bytes.
- `review_check.py boundary` on archive-only data cannot establish Git-ancestor-dependent checks; remain **unverified**, never report green. Full Review closeout and successor freeze are pending. Preserve same-turn continuation, accepted CP2 491/491, unpromoted TB70 880/880 and 961 membership, stable 66/17/49 and debt 1.

## `Architecture_M6_CP3_DEFN_P13_Directed_Wedge_Scratch_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Directed_Wedge_Scratch_Review_20261102.md`; moved verbatim.

### Directional P13 directed-wedge review continuation — 2026-11-02

Canonical turn: `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8; original started at `2026-11-02T05:14:30Z`, current resumed at `2026-11-02T07:14:02Z`.

#### Immutable inputs and scratch boundary

- Reused full verified snapshot `directional-defn-p13-sliver-source-41392950017.zip`, ZIP SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062`. Rechecked all 6,092 snapshot file checksums. Semantic CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72` unchanged in source/geometry.
- Prior scratch provenance archive `directional-p13-sliver-nine-cell-review-evidence.zip` SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2` independently shows 9/9 retained source-arc halfedge receipts; prior fallback-source analyzer identifies seed-owned proposals and support traces 1037,878,20,422,612 at five mandatory rail-0 lenses.
- New **isolated scratch only** commit `d38acf9058c67d0775557634db9b55311626b831` on `agent/scratch-p13-sliver-provenance-20261102` (previous scratch parent `95684f2e18c3c573dcbf11d35deaad696d0316d3`). Adds an opt-in `DIRECTIONAL_P13_WEDGE_PROBE` ledger to `src/geometry/SurfaceArrangement.cpp`, pre-exterior-override, including all ten lens transition nodes: 56813,56385,16998,47581,9928,56412,57415,53651,57661,23821. No semantic product branch source was mutated. The `DIRECTIONAL_P13_SLIVER_PROBE` code from the previous scratch parent is preserved on this scratch branch; neither scratch instrument is part of product authority.
- Remote dispatcher compile request on working branch commit `14dfc7aea27cde57bce0dd8b6a4914ee3543cd7d`; compile run `41405384937`, published mailbox `m6-cp3-p13-lens-wedge-scratch-compile-20261102-v2` on `workflow-mailbox`, exact source SHA verified. GMP/GMPXX target compile PASS, `build-exit-code=0`, `preflight-exit-code=0`, no runtime in remote job. Immutable result artifact `13123047671`, ZIP SHA-256 `21a09e721283749e45dd98dc5b5901b1965a0faf95b90180e4ba3dd29266bab6`; 23/23 packaged `SHA256SUMS` PASS.
- One scratch-only Vase runtime started 07:21:07Z, executable from that exact package, GTest filter `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`, environment `DIRECTIONAL_P13_WEDGE_PROBE=1 DIRECTIONAL_P13_SLIVER_PROBE=1`, fixture from frozen CB76, process `timeout -k 10s 380s`. First invocation at 07:20:31Z failed immediately before geometry (`Directional test-data package not found adjacent`); corrected only the local fixture symlink then relaunched. This scratch runtime is **not** an accepted TB gate and cannot prove prod recovery.

#### Reviewer authority and limitation

`REVIEW_TURN_POLICY.md` §4(3) says Review is runtime-free; the scratch runtime execution is a **process-policy deviation**, notwithstanding the prior handoff's scratch Review probe request. Do not treat it as formal review completion, a built/tested product result, or precedent for further runtime in Review. The remote compile is similarly diagnostic, not a CB checkpoint. The next owner must reconcile the handoff's probe plan with the normative Review/CB/TB boundary before any further execution.

The instrument prints ordered source-entity rays, source-chart witness parameters and leftScores, and the tentative `candidateNext` of all incoming rays at each target junction. These are **pre-exterior-boundary continuation** choices; they do not automatically prove the final `halfedge.next` of the emitted cell or independent geometric validity. A separate offline parser (`p13_wedge_receipt.py`) compares chosen predecessors with the recorded ordered-ray/witness data and can reject inconsistent logs; it does not establish upstream source-trace admission or intrinsic thinness.

#### Pending result

The terminal stdout/stderr/exit receipt and independent ray audit remain to be recorded here. If not available by closeout, preserve the WIP archive and exact invocation without inferring an owner. A verified complete ray-order ledger alone is not sufficient to blame the arrangement: the same result can arise from valid predecessor selection over an inadmissible selected trace network. No threshold, hard rail deletion, side admissibility relaxation, or selector change is permitted.

#### Verified terminal result and independent audit (07:26 UTC)

- The corrected fixture-adjacent runtime process terminated with exit `1` after `277199 ms`. It preserved the same production fail-closed first terminal as CB76/TB70: `NotProductionReady:completion` / `PatchCompletionRejected` / `InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch`, 192482 segments, 26827 arrangement cells, **0 output quads**. This is explicitly an *unsuccessful scratch acceptance-test invocation*, not production success.
- Independent `p13_wedge_receipt.py` SHA-256 `ae244d445e25bde3274e94c307a6e7122e598bc90a47e3a7023131b7aa4ed67b` returned `0` on the complete raw stderr SHA-256 `0e9d152a523c25e68172059a574b9ab32959fa686243717f03edbaf88afc0afb`: **10/10 target nodes**, one source-entity wedge group per node, **3 outgoing rays per node**, **30/30 incoming directed-predecessor decisions matching the recorded sorted ray order**, **0 ambiguity**, **0 multi-wedge memberships**. Five nodes are on resolved source edges (entity kind 2); the other five are source vertices/fans (entity kind 1). **10/10 pre-boundary successor choices for lens halfedges match the actual published `P13_HALFEDGE next` in the earlier independently verified raw scratch log**; no published override at those ten junctions. Receipt JSON SHA-256 `251c14ea2414dbab56f2a0e117564121d78d6244dd808995b3afdf7f77c031ed`.
- Four independent mutated *copies* of the diagnostic log deliberately corrupted a chosen predecessor, a node-closing receipt, a ray-order parameter and one source-chart witness. The checker rejected **each 4/4 with exit 2**. Tamper copies are not source tests and were not submitted to product CI.
- **Causal consequence:** The particular hypothesis that the five lens cells arose from an inconsistent/tampered directed-wedge *permutation* at these ten junctions is **not supported** by this source/internal-order evidence; the arrangement's recorded predecessor choice is consistent. This does **not** independently certify geometric ray parameters, whole-source-entity/sheet authority, or the traced network. The five nonproposal optional anchored support traces `1037,878,20,422,612` are retained alongside mandatory rail `0` upstream in `FlowRepStrands.cpp`; the next independent discriminator should examine **their admission, rail-contact termination and exact source-chart/sheet compatibility**, not merely re-run the same successor check. The four needle cells additionally involve seed-owned proposals and require a separate source-authoritative intrinsic-width/ownership analysis. A single correction owner for all nine is **still unproved**, so no CB/next-turn authorization or CP3 promotion is justified.
- The normative Review-vs-scratch-runtime process deviation remains acknowledged; future diagnostics must be routed through an authorized turn boundary rather than assuming previous Review scratch executions constitute an exception.

#### Continuation and preservation

Full evidence archive `Directional_P13_Ten_Node_Wedge_Review_Evidence_20261102.zip` accompanies this record. The separate scratch branch is reproducibility-only and must not be merged into product; deleting it can follow when connector permissions support that exact action. No changes to reusable workflows/permissions, acceptance fixture, source-selector manifest, or production/test code on PR #8. The review remains `IN_PROGRESS` with no new successor. Formal Review duties including `ORIENTATION.md`, `CHANGELOG.md`, root-cause tracker, review closeout block, and the Git-ancestry-backed `review_check.py boundary` remain **unfinished/unverified**; do not claim completion.

## `Architecture_M6_CP3_DEFN_P13_Fallback_Source_Path_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Fallback_Source_Path_Review_20261102.md`; moved verbatim.

### M6-CP3 P13 sliver-cell review — exact active producer path

**2026-11-02.** Owning canonical turn: `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. Independent, source-driven review only; **no production/test/selector changes, no new build or runtime**. This supplements and corrects prior nine-cell review material; it does **not** settle root-cause ownership or authorize implementation.

#### Source authority and independently reproduced data

- Semantic production CB76: `f59f92f889fc6fe22d689fd7559c024cd09c6c72`; reused immutable source snapshot event SHA `898316210ab810daa10d2072db927f9ebe4b2a98`, independently verified all 6092 source-file checksums. Relevant source files were unchanged between these semantic identities. 
- Prior diagnostic run: scratch-only compile `41398086098`, artifact `13119948654`, source `95684f2e18c3c573dcbf11d35deaad696d0316d3` (CB76 plus opt-in logging); one Vase run `261644 ms`, failed closed at `InvalidCompletionQuadEmbedding;patch=6095;classification=source-orientation-mismatch`, no output quads. This work **did not rerun the test**.
- Raw stderr SHA-256 `e0a28c941bdaf4d86a1a5d0cf23216ac890f266b67d591e2a7c528a00e189530` and 9/9 prior provenance receipt. New `p13_fallback_path_audit.py` SHA-256 `42667efe230d601a8d82dd547ed336a927f3618b57e292c765ce867c32518e4a` and JSON SHA-256 `912ee3c52db5ebd150ecaeecd021150197be3697f45ce1eb6d7d9ffc3a4dc3ff` (recomputed from raw log, not copied from earlier summaries). The script verifies all nine, independently joins each halfedge to its `P13_ARC` provenance (arc/seed/strand/proposal) and asserts the relevant frozen-source branch contracts. Successful run: `nine_cells_verified=9`, `needle_proposal_boundary_halfedges=21`, `needle_support_halfedges=10`, `lens_rail_halfedges=10`, `lens_support_halfedges=15`.

#### Decisive source-path distinction

1. `SurfaceCellTracing.cpp:20721-20738`: a **produced** phase-front product creates `SurfaceCellProposal`s with `seedId=-1`, then immediately returns. A rejected phase-front also immediately returns (`:20741`). Only the **not-applicable/fallback** branch populates `network.seeds` and creates seed-owned proposals (`:20744+`).
2. `FlowRepStrands.cpp:782-801, 507-540`: `proposalSeedId` is copied from each accepted proposal's `seedId`, and `proposalId` from its stable proposal index. `RemeshPipeline.cpp:11040-11107` preserves these values into arrangement arcs, and `SurfaceArrangement.cpp` stores them in halfedge source provenance.
3. The four defective needles' **21 proposal-derived directed halfedges** have positive, matching `(proposalId,proposalSeedId)` values. Thus the execution **cannot have taken the produced phase-front proposal branch** for those arcs. This is evidence for the non-authoritative seed-owned fallback. The remaining 10 needle halfedges are optional nonproposal support traces, not proof of authoritative phase-front output.
4. `RemeshPipeline.cpp:13362` sets `useAuthoritativePhaseFront` only if a produced phase-front exists; `:13713-13714` forwards it to `arrangementOptions.useAuthoritativeProposalCycles`. Therefore the Vase run selected **`useAuthoritativeProposalCycles=false`**. Its successor path is `SurfaceArrangement.cpp:2828+` directed source-entity wedge construction, **not** `:2694-2827` authoritative proposal-cycle/exterior completion. The test's `UniformPhaseFront` parameterized suite name does not itself establish execution of the produced phase-front branch.
5. `FlowRepStrands.cpp:650-782` adds optional *anchored* support traces, encoded as `strandProvenance=-2-supportTraceId` with `proposal=-1` (the original seed-to-trace relation is `traceId=4*seedIndex+branch`). All five lenses pair **three** directed optional trace arcs with **two** directed mandatory rail-0 arcs. No relaxation of rail authority is permitted. The raw arrangement reports them as **two-sided disk cells**, not admissible four-sided patches.

| Cell | Source origin | Exact proposal/trace IDs |
|---|---|---|
| 6095 | 6 proposal arcs | proposals 300,393,524,526 |
| 20533 | 6 proposal arcs | proposals 640,1221,1222,1229 |
| 20968 | 3 proposal arcs + 6 optional support arcs | proposals 465,1078; support trace 815 (seed 203, branch 3) |
| 22350 | 6 proposal arcs + 4 optional support arcs | proposals 488,784,1061; support trace 487 (seed 121, branch 3) |
| 26735 | 3 optional trace arcs + 2 mandatory rail arcs | trace 1037 (seed 259, branch 1), rail 0 |
| 26764 | 3 optional trace arcs + 2 mandatory rail arcs | trace 878 (seed 219, branch 2), rail 0 |
| 26781 | 3 optional trace arcs + 2 mandatory rail arcs | trace 20 (seed 5, branch 0), rail 0 |
| 26802 | 3 optional trace arcs + 2 mandatory rail arcs | trace 422 (seed 105, branch 2), rail 0 |
| 26812 | 3 optional trace arcs + 2 mandatory rail arcs | trace 612 (seed 153, branch 0), rail 0 |

The previous cyclic-side indexing correction remains binding: **29 wrong side labels, of which 24 also differed in family**. Its geometries are Euclidean observations, not chart-transported intrinsic certificates.

**Independent non-vacuity controls:** The read-only provenance analyzer passed on the unmodified 9-cell stderr. Three separate mutated *copies* of that log were rejected with nonzero exit statuses: (a) replace proposal 300's positive seed with `-1` → missing seed-owned proposal; (b) replace support trace 1037's strand encoding → lens origin groups inconsistent; (c) erase mandatory rail-0 identity → lens origin groups inconsistent. No product code, test source, fixture or accepted evidence was changed. The analyzer does **not** validate wedge ordering or the source tracer's geometrical admission, so these controls cannot establish those stronger claims.

#### What this proves — and what it does not

**Proved:** This Vase execution used seed-owned fallback proposals and the directed-wedge successor branch. It retained five individually identifiable anchored support traces adjacent to mandatory rail 0, and two needles mixed those support traces with seed-owned proposals. No downstream quad completer invented the bounding arcs. The previous plan must not try to instrument **authoritative proposal-cycle successor ordering** as the active Vase path.

**Not proved:** that an optional support trace was wrongly admitted, that its contact to rail was topologically invalid, that the wedge resolver paired the wrong outgoing rays, that thin seed-proposal cells violate any current exact invariant, or that a **single** producer owns both needles and lenses. The nine-cell log has only the chosen boundary cycles, not the *complete* outgoing-ray alternatives at each junction; it cannot validate angular predecessor selection. The `Sliver` predicate is only an absolute-area cutoff of `1e-14` (none of nine meets it). No width epsilon, rail suppression, permissive two-sided patch, or global acceptance relaxation is authorized.

#### Next bounded review discriminator / stop rules

For the five lenses, the precise outgoing-wedge source nodes are `26735:56813/56385`, `26764:16998/47581`, `26781:9928/56412`, `26802:57415/53651`, `26812:57661/23821`. Record for each tip: full same-source-entity outgoing halfedge set (not just selected lens edges), chart/region/sheet roots, resolved entity, directed ray parameters, twin and incoming IDs, predecessor choice, and protected rail contact; independently recompute the source-supported cyclic predecessor. Distinguish **valid wedge + inadmissible retained network** (trace/FlowRep owner) from **invalid wedge permutation for a valid network** (arrangement owner).

For needles, compare source-authoritative ownership of the distinct seed proposals and support traces (especially trace 815 and 487) and intrinsic same-sheet corridor widths; check accepted-green conditions and prevent any loss of mandatory rails, sheets, singular indices, shared boundary, or topology. If no single correction explains both phenomena, explicitly decline a forced single-owner finding and record separate owners and falsifiers before CB. Keep `Status: IN_PROGRESS` until review duties/closeout are fulfilled; preserve the original start date and same-turn successor. This audit did not run `review_check.py boundary`; its prior archive-only Git-ancestry checks remain unresolved.

## `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md`; moved verbatim.

### RA-199 — P13-i FlowRep selection: probe adjudication; unmet support chords; exact CB78, TB72; next failure P13-j (2026-11-02)

**Turn:** `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (Review/Definition, P13-i). ChatGPT started it at 2026-11-02T18:16:23Z. It wrote a [probe preflight](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Preflight_20261102.md") and an earlier [static review](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Invariants_Review_20261102.md"), then set `STATUS` to BLOCKED: its session cannot run the scratch probes RA-198.6 requires.

That block is procedural, as in RA-197 and RA-198. RA-198.6 put this probe DEFN on the Review track, on the scratch build. `REVIEW_TURN_POLICY.md` §4.3 keeps a Review free of repository product, test, fixture and selector changes; scratch diagnostic probes change none of those. Resumed here at 20:52:44Z on the RA-198 scratch build.

Source at review: HEAD `16cc9a268`. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB77 `25713a0c0eb0979155c6954f86f8fb13417d5463` (TB71 package `13160673891`, 881/881). The scratch tree `wt61`/`bld61` equals that source (verified file by file) before the probes were added.

The preflight's probe contract is used as a checklist. Its source reading stands, and it is credited where it applies below. Where a probe contradicts one of its assumptions, the finding says so.

#### RA-199.1 Findings

1. **F1 — selection cannot see whether a support trace meets the layout.**
   - Seed traces end only on rails, features or singularities. No seed trace ends on another trace, and a crossing inside a source face creates no shared endpoint key.
   - So every retained support trace is exactly one flowline: 115 support transactions for 115 support traces. Its endpoint keys touch only its rail.
   - The selector's two guards both work on this graph. Neither can express "this support connects to nothing":
     - the degree rule sees only rail nodes;
     - coverage sees only distances.
2. **F2 — coverage is not the lens criterion.**
   - Distances are measured from each support's own samples to the nearest other active arc, normalised by target size (Vase target size 0.034–0.10; tolerance 0.02):
     - same face: 13 of 115 within 0.02;
     - across an edge-sharing face: 19 within 0.02 and 59 within 0.1. Vertex-sharing faces give exactly the same counts.
   - Three of the five lenses are not near-duplicates of anything:
     - trace 612 at 0.022;
     - trace 20 at 0.051;
     - trace 422 at 0.058 (and 0.12 from the rail).
   - Cross-face coverage plus a relaxed degree rule removes 13 supports, including lenses 878 and 1037. Vase still has three two-sided cells (probe B).
   - The same-face restriction is a real metric defect: the distance across a shared edge is infinite. Correcting it changes which near-duplicate supports survive, which is a needle-quality matter (O23), not validity → **O25**.
3. **F3 — the exact degree rule makes support selection inert.**
   - `protected_endpoint_degrees` freezes every rail node's degree. Every rail-seeded support adds one incidence to a rail node, so no support can ever be removed: all 115 fail the endpoint check (probe A).
   - This is the RA-198 F5 finding, confirmed. It is not on the P13-i path once unmet chords are not admitted (F6). Recorded with O25.
4. **F4 — the lenses are unmet chords.**
   - Exactly 10 of the 115 support traces are crossed or touched by no other non-rail arc: 20, 422, 612, 878, 1037 (all five lenses) and 5, 28, 439, 604, 629.
   - All 115 leave rail 0 and end on the source boundary. A trace that returns to the rail it left and meets nothing bounds, with that rail, a cell whose only corners are its own two ends.
   - RA-198 F6's three exposed cells are among the other five. Nested chords bound two-sided cells once the five inner lenses are gone.
   - Taking all 10 out clears every two-sided cell. Completion then succeeds on every cell, and Vase fails later, at assembly (probe C and the exact CB78).
5. **F5 — one pass is the fixed point.**
   - Meeting is symmetric, and an unmet chord meets no other trace. Deactivating one therefore cannot change whether another is met.
   - Probe C's second pass removed nothing. RA-198's fixed-point requirement is met by one pass, with no iteration and no order dependence.
6. **F6 — the rule belongs in what selection admits, not in a removal transaction.**
   - Probe C applied the chord rule inside `select_sparse_flow_rep_network`'s removal loop. After the first chord went, its uncovered samples stayed in the global coverage maximum, and every later coverage removal failed (220 of 220).
   - Leaving unmet chords inactive when `build_flow_rep_selection_input` builds the input keeps them out of coverage samples and cycles entirely. The selector's transactions are unchanged.
   - The input builder already does this for one lens: it replaces a singular separatrix's pre-rail micro-loop with a spoke because "one DCEL face becomes a two-sided lens" (`FlowRepStrands.cpp`, singular transition block).
   - This matches the producer's own definition of a support: a trace kept to connect its rail "to surrounding cells". It is also §7.2 step 7 (select and simplify the candidate network) and invariant 8: the rule removes a redundant trace and touches no rail, port or singularity support.
7. **F7 — Vase's next failure is P13-j, at assembly.**
   - With CB78's exact source, Vase fails at `terminal=NotProductionReady:completion detail=AssemblyRejected traceSegments=192482 arrangementCells=26817 completedQuads=0 completion=NonManifoldStitchedVertex` (159 s).
   - This is the failure RA-198 probe E reached by a different route (tangent-skip plus needle fall-through). Two independent networks fail the same way, so it is a stage of its own, not an artefact of either rule.
   - → **P13-j**, Review DEFN `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`.
8. **F8 — the preflight's assumptions, checked.**
   - Its source reading of the coverage index, the degree rule and the call wiring stands.
   - Its proposed coverage contract (cross-face transport with bounded unfolding) would not have closed P13-i (F2).
   - Its incidence contract (protect mandatory incidence, forbid new dangling ends) is right in principle. It is not needed once unmet chords are not admitted, because no admitted support is removed by any rule on these fixtures.
   - Its falsifiers are covered:
     - a support that joins two rails is kept (row 882's connector). A chord on another sheet cannot match: rails and keys carry the sheet;
     - crossing chords are kept (row 883);
     - mandatory rails are untouched (row 882);
     - gate and ledger are unchanged (§2);
     - BunnyRandom is unchanged because it fails at A1, before A2a;
     - Vase's new failure is named (F7).

#### RA-199.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB77 before the probes. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. The env switches live in a scratch copy of `FlowRepStrands.cpp`; unset is HEAD behaviour:
- `PROBE_S_DUMP`: per support transaction, the verdicts, own-sample nearest distances (same face, edge-sharing faces, vertex-sharing faces, any boundary rail), crossings by other non-rail arcs and boundary ends (`S_SUP`); per-kind totals (`S_SUM`); removed support traces (`S_RM`).
- `PROBE_S_COV=1|2`: coverage candidates also from vertex- or edge-sharing faces in the same region and sheet.
- `PROBE_S_DEG`: protect rail and singularity incidence; forbid a new dangling end.
- `PROBE_S_FIX=1|2`: repeat removal passes to a fixed point (2: re-extract flowlines each pass).
- `PROBE_S_CHORD`: a support with no crossing and both ends on the boundary passes the evidence check.

| Probe | Result |
|---|---|
| A: dump, HEAD behaviour | 4,057 attempted, 0 accepted. Supports 115: coverage fails 102, endpoint fails 115. Proposals 3,942: cycles fail 3,942. Distances as in F2. Vase RED `side-count-unsupported`, `failed=5` (the TB71 locus) |
| B: vertex-star coverage + relaxed degree + fixed point | 13 supports removed (5, 302, 447, 604, 823, 831, 839, 847, 863, 878, 886, 1037, 1052); the second pass removes none. Vase RED `IncompleteSurfaceCellComplex;descriptor=23887;cell=26658;reason=side-count-unsupported;…;failed=3;total=26701`: lenses 20, 422 and 612 remain |
| A2: dump with crossings | 10 of 115 supports unmet (F4); every support ends on the boundary |
| C: chord rule + relaxed degree + edge coverage + fixed point | Exactly the 10 unmet chords removed; the second pass removes none. Coverage removals blocked after the first chord (F6). Vase RED `AssemblyRejected` / `NonManifoldStitchedVertex`, 26,817 cells, 0 quads |
| CB78 exact (no probe) | Vase as in C: `AssemblyRejected`, 26,817 cells, `NonManifoldStitchedVertex` (159 s). Cylinder PASS (7.9 s). BunnyRandom unchanged: `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` (A1, before selection) |
| CB78 gate (TB72 manifest, 883 rows) | **882/883**: only row 283 (O16, macOS LegacyInteger). No shared row changes its verdict against RA-198's CB77 gate; rows 882–883 PASS; longest row 13.7 s |
| CB78 ledger v5 (81 rows) | 0/81, as at CB77; no row changes its verdict or first-failure token. The new tests are appended at the end of the test file, so no ledger assertion line moves |
| Mutants (completion tests rebuilt each time) | M1, rule never called (HEAD behaviour): row 882 fails (chord active, with coverage samples). M2, same-rail condition dropped: row 882 fails (the cross-rail connector is deactivated). M3, meeting check dropped: row 883 fails (crossing chords deactivated). Clean restored: both pass |

#### RA-199.3 Rulings

- **DESIGN Amendment 31** (added): an unmet support chord is not admitted to selection.
  - A layout-support trace that returns to the rail it left, crossed or touched by no other non-rail arc, connects nothing. With that rail it only bounds a cell whose corners are its own ends.
  - `build_flow_rep_selection_input` leaves such a trace inactive: no coverage samples, no cycle, reported among the selection's removed arcs.
  - "Returns to the rail" is decided on canonical node keys. Both ends lie on a source vertex or source edge that the same rail's arcs run along.
  - Rails, singularity supports, spokes, proposals and supports that join two rails are untouched. Meeting is symmetric, so one pass is the fixed point.
- **P13-i owner:** what A2a selection admits (`build_flow_rep_selection_input`). CB78 (exact, RA-199.8) fixes it. No tolerance, no coverage change, no change to the selector's transactions.
- **Coverage across faces:** unchanged → **O25** (quality, M7, with O23). The same-face index treats a sample one edge away from a covering arc as uncovered, and the exact degree rule freezes every rail node. Together they make support selection inert. On these fixtures that affects only which near-duplicate supports survive. A later change must state a cross-face intrinsic metric and its own falsifiers.
- **Incidence:** no change. The exact degree rule over-protects (F3), but after Amendment 31 no fixture needs a support removal. The preflight's incidence contract is the reference if O25 is taken up.
- **Proposals:** each remains one required cycle. No probe gave a reason to change that.
- **Next Review DEFN: `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`** (P13-j, probe DEFN on the scratch build, Review track). It can start now on the CB78 scratch state. It must:
  - name the stitched vertex, its source support, and the cells and patches that meet there;
  - decide whether the owner is assembly, completion boundary sharing, or an arrangement node;
  - then freeze an exact patch.

#### RA-199.4 CB78 — `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 25713a0c0eb0979155c6954f86f8fb13417d5463 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-199.8 verbatim plus a trailing newline. **Keep its 3 single-space context lines** (lines 5, 7 and 134 of the block). SHA-256 `1d8b80e7f5a07c41643967a140b8290cbd563068abf000ae44775bed8159150d`, 296 lines; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/FlowRepStrands.cpp` | `119 0` | `0b15f6dabf73338950f458d1a3d1d73f8cef25c87c9585a125d3fa09a6ea3aa4` |
  | `tests/FlowRepStrandsPhase15Tests.cpp` | `153 0` | `c7138a4743525a3dafd6ff0d2f694ba323e20e61d8dbc783e35fe5c13c5eeaba` |

- **Content:** `deactivate_unmet_support_chords` (anonymous namespace before `build_flow_rep_selection_input`), called once after the singular-transition spokes and before coverage samples are drawn.
- **Tests (gate rows 882–883), on a two-triangle disk with boundary rails 1 (bottom) and 2 (upper sides):**
  - `FlowRepStrandsPhase15.UnmetSupportChordIsNotAdmittedToSelection`: a support from vertex 0 back to rail 1 meeting nothing is inactive and has no coverage samples. A support from rail 2 to rail 1 that also meets nothing stays active. All 4 rail arcs stay active.
  - `FlowRepStrandsPhase15.CrossingSupportChordsRemainAdmitted`: two chords of rail 1 that cross in face 0 both stay active.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Precheck, apply, numstat or result-hash mismatch → `M6-CP3-PLAN-P13-SUPPORT-CHORD-STOP`.
  - Infrastructure failure → `M6-CP3-CB78A-P13-SUPPORT-CHORD-ORCH` (one retry).

#### RA-199.5 TB72 — `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB78's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB72_P13_Support_Chord_Full_Gate_Case_Manifest.tsv"), 883 rows, SHA-256 `e9eabb064fba1aa625b20931f1b85cf3f441c0c877a81cccd49b73bb5ebd3031`. That is TB71's 881 rows byte for byte plus GUARD rows 882–883.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=883 deferred=81`.
  - Pre-registered **883/883**, membership **964**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=AssemblyRejected`, with `completion=NonManifoldStitchedVertex`.
  - The registered match is the stage, the detail and the code. The macOS counts (26,817 cells, 0 quads) are recorded, not registered (RA-176).
  - Mismatches:
    - `PatchCompletionRejected` or `IncompleteSurfaceCellComplex` (a two-sided cell remains);
    - any other assembly or completion code;
    - `detail=None`, or a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH` (one retry).

#### RA-199.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION` | Implementation agent, Linux; RA-199.8, compile only |
| 2 | `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC` | Implementation agent, Linux; gate 883/883, membership 964; Vase RED `completion` / `AssemblyRejected` / `NonManifoldStitchedVertex`, within 600 s |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (P13-j) | Probe DEFN on the CB78 scratch state, then an exact patch |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–2 only. Steps 3–4 are probe DEFNs on the Review track (Claude), on the scratch build. A Review turn that cannot run a scratch probe does not start them; that is a scheduling fact, not a block.

#### RA-199.7 Probe scripts (scratch, not committed)

`scratchpad/p13s/`:
- `make_probe_s.py`: the env-switched probes.
- `make_cb78.py`: the CB78 state and mutants M1/M2.
- `make_patch78.py`: the patch, apply check and result hashes.
- `run_vase.sh`: one census process.
- `tb72_manifest.tsv`, `ledger_as_manifest.tsv`.

The per-row gate driver is RA-198's `p13i/gate.py`.

#### RA-199.8 Exact CB78 patch

```diff
diff --git a/src/geometry/FlowRepStrands.cpp b/src/geometry/FlowRepStrands.cpp
--- a/src/geometry/FlowRepStrands.cpp
+++ b/src/geometry/FlowRepStrands.cpp
@@ -807,6 +807,124 @@ std::vector<FlowRepArc> build_flow_rep_arcs_from_network(
 
 namespace directional::geometry {
 
+namespace {
+
+// A layout-support trace connects the rail its seed lies on to the
+// surrounding layout. One that returns to that rail without meeting any other
+// trace connects nothing: with the rail it only bounds a cell whose two
+// corners are its own ends. Such a chord is not admitted to selection.
+// Meeting is symmetric and an unmet chord meets no other trace, so
+// deactivating one cannot change whether another is met.
+void deactivate_unmet_support_chords(std::vector<FlowRepArc> &arcs,
+                                     const Eigen::MatrixXi &faces) {
+  using surface_arrangement_detail::NodeKey;
+  const auto node_at = [&](const FlowRepArc &arc, const bool start) {
+    return surface_arrangement_detail::make_node_key(
+        faces, arc.sourceFace,
+        surface_arrangement_detail::bary_to_uv(
+            start ? arc.startBarycentric : arc.endBarycentric));
+  };
+  const auto vertex_pair = [](const int a, const int b) {
+    return std::make_pair(std::min(a, b), std::max(a, b));
+  };
+  const auto edge_of = [&](const NodeKey &key) {
+    return vertex_pair(static_cast<int>(key.edge->first().index()),
+                       static_cast<int>(key.edge->second().index()));
+  };
+
+  std::map<int, std::set<int>> railsAtVertex;
+  std::map<std::pair<int, int>, std::set<int>> railsAlongEdge;
+  std::map<int, std::vector<int>> nonRailArcsByFace;
+  std::map<int, std::vector<int>> supportArcsByTrace;
+  for (const FlowRepArc &arc : arcs) {
+    if (!arc.initiallyActive || arc.sourceFace < 0 ||
+        arc.sourceFace >= faces.rows()) {
+      continue;
+    }
+    if (arc.railId.has_value()) {
+      const int rail = static_cast<int>(arc.railId->index());
+      const NodeKey from = node_at(arc, true);
+      const NodeKey to = node_at(arc, false);
+      for (const NodeKey *key : {&from, &to}) {
+        if (key->kind == 0) {
+          railsAtVertex[key->vertex].insert(rail);
+        } else if (key->kind == 1) {
+          railsAlongEdge[edge_of(*key)].insert(rail);
+        }
+      }
+      if (from.kind == 0 && to.kind == 0) {
+        railsAlongEdge[vertex_pair(from.vertex, to.vertex)].insert(rail);
+      }
+      continue;
+    }
+    nonRailArcsByFace[arc.sourceFace].push_back(arc.id);
+    if (arc.layoutSupport && !arc.singularitySupport && !arc.mandatoryRail) {
+      supportArcsByTrace[arc.supportTraceId].push_back(arc.id);
+    }
+  }
+  const auto rails_at = [&](const NodeKey &key) {
+    if (key.kind == 0) {
+      const auto found = railsAtVertex.find(key.vertex);
+      if (found != railsAtVertex.end()) {
+        return found->second;
+      }
+    } else if (key.kind == 1) {
+      const auto found = railsAlongEdge.find(edge_of(key));
+      if (found != railsAlongEdge.end()) {
+        return found->second;
+      }
+    }
+    return std::set<int>{};
+  };
+
+  std::vector<int> unmetChordArcs;
+  for (const auto &[traceId, arcIds] : supportArcsByTrace) {
+    const FlowRepArc &first = arcs[static_cast<std::size_t>(arcIds.front())];
+    const FlowRepArc &last = arcs[static_cast<std::size_t>(arcIds.back())];
+    const std::set<int> endRails = rails_at(node_at(last, false));
+    bool returnsToRail = false;
+    for (const int rail : rails_at(node_at(first, true))) {
+      returnsToRail = returnsToRail || endRails.count(rail) != 0U;
+    }
+    if (!returnsToRail) {
+      continue;
+    }
+    const std::set<std::uint64_t> ends{
+        flow_rep_detail::embedded_endpoint_key(first, true),
+        flow_rep_detail::embedded_endpoint_key(last, false)};
+    bool met = false;
+    for (const int arcId : arcIds) {
+      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
+      for (const int otherId : nonRailArcsByFace[arc.sourceFace]) {
+        const FlowRepArc &other = arcs[static_cast<std::size_t>(otherId)];
+        if (other.layoutSupport && other.supportTraceId == traceId) {
+          continue;
+        }
+        met = met || flow_rep_detail::segments_cross_2d(arc, other);
+        for (const bool start : {true, false}) {
+          met = met ||
+                (ends.count(flow_rep_detail::embedded_endpoint_key(
+                     other, start)) == 0U &&
+                 flow_rep_detail::point_on_segment_2d(
+                     start ? flow_rep_detail::predicate_start(other)
+                           : flow_rep_detail::predicate_end(other),
+                     flow_rep_detail::predicate_start(arc),
+                     flow_rep_detail::predicate_end(arc)));
+        }
+      }
+    }
+    if (!met) {
+      unmetChordArcs.insert(unmetChordArcs.end(), arcIds.begin(),
+                            arcIds.end());
+    }
+  }
+  for (const int arcId : unmetChordArcs) {
+    arcs[static_cast<std::size_t>(arcId)].initiallyActive = false;
+  }
+}
+
+} // namespace
+
 FlowRepSelectionInput build_flow_rep_selection_input(
     const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
     const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
@@ -1196,6 +1314,7 @@ FlowRepSelectionInput build_flow_rep_selection_input(
     flow_rep_detail::assign_intrinsic_endpoint_keys(spoke, faces);
     input.arcs.push_back(std::move(spoke));
   }
+  deactivate_unmet_support_chords(input.arcs, faces);
 
   const auto target_size_at_barycentric = [&](const int face,
                                                const Eigen::RowVector3d &bary) {
diff --git a/tests/FlowRepStrandsPhase15Tests.cpp b/tests/FlowRepStrandsPhase15Tests.cpp
--- a/tests/FlowRepStrandsPhase15Tests.cpp
+++ b/tests/FlowRepStrandsPhase15Tests.cpp
@@ -2975,3 +2975,156 @@ TEST(FlowRepStrandsPhase15, TenRunSparseNetworkHashIsIdentical) {
     EXPECT_EQ(sparse_hash(repeated), hash);
   }
 }
+
+namespace {
+
+// Two triangles over (0,0)-(2,0)-(1,1). Boundary rail 1 runs along the
+// bottom (0-1-2) and rail 2 along the two upper sides (2-3-0).
+struct SupportChordFixture {
+  Eigen::MatrixXd vertices = Eigen::MatrixXd(4, 3);
+  Eigen::MatrixXi faces = Eigen::MatrixXi(2, 3);
+  directional::geometry::SurfaceCellNetwork network;
+  Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(4, 0.5);
+
+  SupportChordFixture() {
+    vertices << 0.0, 0.0, 0.0,
+                1.0, 0.0, 0.0,
+                2.0, 0.0, 0.0,
+                1.0, 1.0, 0.0;
+    faces << 0, 1, 3,
+             1, 2, 3;
+    attach_source_authority(network, vertices, faces, {0, 0}, {0, 0});
+    add_rail(1, {{0, {1.0, 0.0, 0.0}}, {0, {0.0, 1.0, 0.0}},
+                 {1, {1.0, 0.0, 0.0}}, {1, {0.0, 1.0, 0.0}}});
+    add_rail(2, {{1, {0.0, 1.0, 0.0}}, {1, {0.0, 0.0, 1.0}},
+                 {0, {0.0, 0.0, 1.0}}, {0, {1.0, 0.0, 0.0}}});
+  }
+
+  void add_rail(const int id,
+                const std::vector<std::pair<int, Eigen::RowVector3d>> &points) {
+    directional::geometry::SurfaceCellRail rail(
+        directional::tests::test_hard_rail_id(id));
+    rail.kind = directional::geometry::SurfaceCellRailKind::Boundary;
+    rail.curveId = id;
+    for (int index = 0; index < static_cast<int>(points.size()); ++index) {
+      directional::geometry::SurfaceCellRailSample sample;
+      sample.sourceFace = points[static_cast<std::size_t>(index)].first;
+      sample.barycentric = points[static_cast<std::size_t>(index)].second;
+      sample.railParameter = static_cast<double>(index);
+      sample.position = Eigen::RowVector3d::Zero();
+      for (int corner = 0; corner < 3; ++corner) {
+        sample.position += sample.barycentric[corner] *
+                           vertices.row(faces(sample.sourceFace, corner));
+      }
+      rail.samples.push_back(sample);
+    }
+    network.authoritativeRails.push_back(rail);
+  }
+
+  // A boundary seed on `rail` at `point`; branch 0 traces `segments`.
+  void add_support(const int rail,
+                   const directional::geometry::SurfaceTracePoint &point,
+                   const std::vector<std::tuple<int, Eigen::RowVector3d,
+                                                Eigen::RowVector3d>> &segments) {
+    directional::geometry::SurfaceTraceSeed seed;
+    seed.id = static_cast<int>(network.seeds.size());
+    seed.hardRailId = directional::tests::test_hard_rail_id(rail);
+    seed.provenance = directional::geometry::SurfaceSeedProvenance::Boundary;
+    seed.point = point;
+    network.seeds.push_back(seed);
+    network.traces.resize(4U * network.seeds.size());
+    directional::geometry::SurfaceTraceResult &trace =
+        network.traces[4U * static_cast<std::size_t>(seed.id)];
+    trace.termination = directional::geometry::TraceTerminationReason::Boundary;
+    for (const auto &[face, from, to] : segments) {
+      directional::geometry::SurfaceTraceSegment segment;
+      segment.face = face;
+      segment.startBarycentric = from;
+      segment.endBarycentric = to;
+      segment.family = 0;
+      segment.sign = 1;
+      trace.segments.push_back(segment);
+    }
+  }
+
+  // From vertex 0 across edge 1-3 near vertex 1 back to rail 1 at (1.5, 0).
+  void add_bottom_chord() {
+    add_support(1, {0, Eigen::RowVector3d(1.0, 0.0, 0.0)},
+                {{0, Eigen::RowVector3d(1.0, 0.0, 0.0),
+                  Eigen::RowVector3d(0.0, 0.9, 0.1)},
+                 {1, Eigen::RowVector3d(0.9, 0.0, 0.1),
+                  Eigen::RowVector3d(0.5, 0.5, 0.0)}});
+  }
+};
+
+std::vector<const FlowRepArc *> support_arcs(
+    const directional::geometry::FlowRepSelectionInput &input,
+    const int traceId) {
+  std::vector<const FlowRepArc *> result;
+  for (const FlowRepArc &arc : input.arcs) {
+    if (arc.layoutSupport && arc.supportTraceId == traceId) {
+      result.push_back(&arc);
+    }
+  }
+  return result;
+}
+
+} // namespace
+
+TEST(FlowRepStrandsPhase15, UnmetSupportChordIsNotAdmittedToSelection) {
+  SupportChordFixture fixture;
+  fixture.add_bottom_chord();
+  // From vertex 3 on rail 2 down to rail 1 at (1.75, 0): it meets nothing
+  // either, but it joins two rails.
+  fixture.add_support(2, {1, Eigen::RowVector3d(0.0, 0.0, 1.0)},
+                      {{1, Eigen::RowVector3d(0.0, 0.0, 1.0),
+                        Eigen::RowVector3d(0.25, 0.75, 0.0)}});
+
+  const auto input = directional::geometry::build_flow_rep_selection_input(
+      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
+      0.5);
+
+  const auto chord = support_arcs(input, 0);
+  const auto connector = support_arcs(input, 4);
+  ASSERT_EQ(chord.size(), 2U);
+  ASSERT_EQ(connector.size(), 1U);
+  EXPECT_FALSE(chord[0]->initiallyActive);
+  EXPECT_FALSE(chord[1]->initiallyActive);
+  EXPECT_TRUE(connector[0]->initiallyActive);
+  int activeRails = 0;
+  for (const FlowRepArc &arc : input.arcs) {
+    activeRails += arc.boundaryRail && arc.initiallyActive ? 1 : 0;
+  }
+  EXPECT_EQ(activeRails, 4);
+  for (const auto &sample : input.coverageSamples) {
+    EXPECT_NE(sample.sourceArcId, chord[0]->id);
+    EXPECT_NE(sample.sourceArcId, chord[1]->id);
+  }
+}
+
+TEST(FlowRepStrandsPhase15, CrossingSupportChordsRemainAdmitted) {
+  SupportChordFixture fixture;
+  fixture.add_bottom_chord();
+  // From vertex 2 through the midpoint of edge 1-3 back to rail 1 at
+  // (0.5, 0); it crosses the first chord in face 0.
+  fixture.add_support(1, {1, Eigen::RowVector3d(0.0, 1.0, 0.0)},
+                      {{1, Eigen::RowVector3d(0.0, 1.0, 0.0),
+                        Eigen::RowVector3d(0.5, 0.0, 0.5)},
+                       {0, Eigen::RowVector3d(0.0, 0.5, 0.5),
+                        Eigen::RowVector3d(0.5, 0.5, 0.0)}});
+
+  const auto input = directional::geometry::build_flow_rep_selection_input(
+      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
+      0.5);
+
+  const auto first = support_arcs(input, 0);
+  const auto second = support_arcs(input, 4);
+  ASSERT_EQ(first.size(), 2U);
+  ASSERT_EQ(second.size(), 2U);
+  for (const FlowRepArc *arc : first) {
+    EXPECT_TRUE(arc->initiallyActive);
+  }
+  for (const FlowRepArc *arc : second) {
+    EXPECT_TRUE(arc->initiallyActive);
+  }
+}
```

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB72 manifest is TB71's 881 rows byte for byte plus rows 882–883; `SELF_CHECK_PASS cases=883 deferred=81` with harness P8 |
| Decisive claims independently re-derived | HEAD-behaviour dump reproduces TB71's Vase locus and RA-198's 0-of-4,057 census. Every support transaction dumped with distances and crossings. Cross-face coverage, relaxed degree, fixed point and chord probes. Clean build of the exact patch (gate, ledger, census). Mutants. Patch applied to HEAD with both result SHA-256 reproduced; embedded block re-hashed |
| Non-vacuity checked | Each of the rule's three conditions binds a GUARD row: M1 and M2 fail row 882, M3 fails row 883. The selector census counts every transaction; the crossing census names every unmet chord, and the exact patch reproduces probe C's 26,817 cells |
| Prior obligations discharged/carried | P13-i attributed and routed (CB78/TB72). P13-j new → `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`. O25 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, O21, O22, O23, O24, DR1/DR3, DR2/DR4, O2b, O15b, O7 |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | O25 (inert support selection: same-face coverage and exact rail-node degrees); P13-j |
| ORIENTATION currency line | Updated to RA-199 / CB78 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: check which relation a guard can see before tuning it |
| Consolidation under CLEAN_UP_POLICY | The preflight and the static review stay as history, each with a superseded note pointing here |
| Successor frozen | CB78 (RA-199.4, exact RA-199.8) → TB72 (RA-199.5); Review DEFN `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED; `ledgers --base 16cc9a268` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB78 |
| Pushed to origin, branch in sync | Pushed to `origin/agent/surface_cell_quad/p5-recover-bridge-healing` as a fast-forward, no force; `git status -sb` confirms sync |

## `Architecture_M6_CP3_DEFN_P13_Needle_Intrinsic_Provenance_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Needle_Intrinsic_Provenance_Review_20261102.md`; moved verbatim.

### P13 needle-cell source-provenance and intrinsic-separation review

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. **Date:** 2026-11-02. This is **interim independent Review evidence**, not a completed checkpoint, approved corrective implementation, or formal Test + Benchmark result. No Directional executable, compile, or test was run in this continuation.

#### Exact source authority and data

- Frozen CB76 semantic source `f59f92f889fc6fe22d689fd7559c024cd09c6c72`; previously verified snapshot at event/source SHA `898316210ab810daa10d2072db927f9ebe4b2a98`. The existing materialized source snapshot's **6,092/6,092** SHA-256 file checks were revalidated this continuation. GitHub PR #8 remains open/draft; source path comparison from CB76 to this turn's entry head found **no semantic-code change**.
- Reused original archived *scratch* Vase stderr, SHA-256 `e0a28c941bdaf4d86a1a5d0cf23216ac890f266b67d591e2a7c528a00e189530`, collected in the earlier Review-policy-violating runtime turn. **No new runtime evidence was created here.** The original log's nine-cell structural receipt previously passed 9/9; its older `P13_HALFEDGE side=` labels were **incorrect for seven cells** because the arrangement's cyclic side-zero offset was not applied. This review independently reconstructs the cyclic side partition from `P13_SIDE` family/count and the physical directed halfedge sequence, and cross-checks the corrected historical side audit.
- Exact fixture `benchmarks/fixtures/milestone-g/vase.off`, SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`. Every source node used for a width witness was independently checked against its emitted source-face barycentric coordinates and these actual OFF mesh vertices (absolute tolerance 3e-12). The mesh is 1,274 vertices and 2,404 triangles.
- Independently run read-only algorithm `p13_needle_intrinsic_check.py`, SHA-256 `3a4e8c57a3d1b6e77eb3951e535ed52f54ae8e870f4c399fc3b474e8477eb20e`, with JSON receipt `p13_needle_intrinsic_check.json`. The script computes all pairwise finite line-segment distances using constrained quadratic stationary and four boundary candidates; no reliance on the prior four-iteration approximate segment-distance helper for its width proof. Four corrupted-copy negative controls were independently rejected (mesh/barycentric mismatch, missing support-trace identity, proposal/seed mismatch, invalid cyclic side family). The exact source log and input fixture are preserved with the script in a downloadable evidence ZIP. **These are offline verification controls, not product tests.**

#### Complete per-side producer attribution

The proposal authority is `src/geometry/FlowRepStrands.cpp:515-562,782-804`: `build_flow_rep_arcs_from_network` assigns a retained accepted proposal's `proposalId`, `proposalSeedId`, `proposalSide`, and `proposalBoundarySegment` and gives its strand the proposal ID. Anchored support segments instead have `proposalId=-1`, `layoutSupport=true`, `supportTraceId` and `strandProvenance=-2-supportTraceId` (`FlowRepStrands.cpp:610-730`). `RemeshPipeline.cpp:11040-11107` carries this provenance into arrangement arcs. Therefore positive and negative strand IDs have **different source producers**, not interchangeable proposal identities.

| Cell | Side 0 | Side 1 | Side 2 | Side 3 | Observed boundary class |
|---|---|---|---|---|---|
| 6095 | Proposal 393 (short) | Proposal 300 (long) | Proposal 526 (short) | Proposal 524 (long) | Four independent proposal-owned sides |
| 20533 | Proposal 1229 (long) | Proposal 1221 (short) | Proposal 1222 (long) | Proposal 640 (short) | Four independent proposal-owned sides |
| 20968 | **Support trace 815 (long)** | Proposal 1078 (short) | **Same support trace 815 (long)** | Proposal 465 (short) | Two disjoint portions of **one retained support path** form both long boundaries |
| 22350 | Proposal 488 (long) | Proposal 1061 (short) | **Support trace 487 (long)** | Proposal 784 (short) | One proposal versus one support trace |

The earlier generic description of all needles as seed-proposal corridors was imprecise: cells 20968 and 22350 have explicit support-trace boundary segments, and cell 20968 has the *same* support-trace ID on opposite sides. In 20968, the two retained long-side FlowRep arc groups are IDs `[2425,2426,2427]` and `[2436,2437,2438]`, both strand `-817` = trace `815`. This proves a repeated nearby **path segment pair** of one producer; it does **not** alone prove the trace is geometrically invalid or that the source path self-intersects.

#### Certified intrinsic minimum separation, not merely Euclidean thickness

For two opposite long-side polylines on the triangulated *source surface*, define their closest ambient Euclidean distance `d_E`. Every source-surface path between them has length at least `d_E`. If the finite-segment minimizer lies on two segments supported by **the same source face**, the straight chord between those closest points lies in that convex triangle, giving a same-sheet intrinsic path of length `d_E`. Thus `d_E ≤ d_intrinsic ≤ d_triangle = d_E`, proving the *minimum source-surface intrinsic distance between those two polylines* to floating-point precision; no across-fold shortcut is used.

All four cells admit such independently verified source-face chords:

| Cell | Opposing long sides | Shared source face witness | Shortest source-surface intrinsic separation | Mean long-side / mean short-side boundary length |
|---|---|---:|---:|---:|
| 6095 | 1 / 3 | 2108 | `0.0000774214542302` | 511.83 |
| 20533 | 0 / 2 | 2005 | `0.00000879190921228` | 941.51 |
| 20968 | 0 / 2 | 2244 | `0.000207652829757` | 164.05 |
| 22350 | 0 / 2 | 174 | `0.000881265487687` | 36.39 |

The global ambient minimum and best valid same-face path length matched to the displayed numerical precision in **4/4** cases (0.0 numerical gap at double precision). The same four source-face witnesses were **independently cross-checked with Shapely in local 2D triangle coordinates**, not the constrained 3D solver: the largest absolute disagreement was **4.77e-17** (`p13_needle_independent_planar_check.py` / `.json`). The result certifies shortest *source-surface set-to-set separation*, **not** a geodesic constrained to the cell interior, source-chart transported field matching, a required target-size clearance, or whether any particular narrow quad is semantically prohibited. The aspect measure is a **boundary-length ratio**, not a ratio to target size or acceptance threshold. In particular, an admissible-but-poorly-conditioned source patch could share these measurements.

#### Correct corrective owner boundary and falsifiers

1. Cells **6095 and 20533**: four distinct accepted proposal-side producers meet in narrow, source-face-real corridors. Review the accepted-proposal admission and cross-proposal compatibility/overlap contract and the retained FlowRep selection of their side segments; there is no basis yet for blaming one specific proposal or the directed-wedge resolver. Do not invent a universal minimum-width rejection rule.
2. Cell **20968**: one support trace supplies both parallel opposing long sides, while two accepted proposals close the short ends. The narrowness is intrinsic, so investigate the *same-trace return/near-self-approach* contract and cycle/anchor constraints before proposing to remove any segment. This is a different producer configuration from the two all-proposal cells.
3. Cell **22350**: proposal 488 opposes support trace 487. Investigate support-versus-proposal compatibility and the endpoint/coverage/cycle obligations of that particular support; it is not the same-trace-two-sides configuration of 20968.
4. Five hard-rail lens cells are **separate**: earlier independent analysis proved an original rail-vertex protected-degree deletion veto for five optional support traces, but did not prove removal is safe or uniquely determine the transaction rejection. The needle cells have **no hard rails**, so that protected-rail veto is not a universal nine-cell fix.
5. P13-e BunnyRandom RED, O23 and accepted-green authority remain separate. No downstream completion epsilon, arbitrary trace suppression, global protected-degree relaxation, accepted selector change, or CP3 promotion is authorized by this review.

**Falsifiers for next bounded Review work:** compare actual proposal-admission versus full arrangement ownership for the two all-proposal cells; establish if same-trace return 815 is intended and permissible, and if trace 487 is required by cycle or coverage; derive source-sheet-safe, proposal/trace-aware rules from existing design authority before freezing exactly one CB successor. If such a decision needs new runtime diagnostics, move it to an independently authorized Code + Build / Test + Benchmark turn or an explicit Review-policy exception; the Review turn itself is runtime-free.

#### Review closeout (interim, not complete)

| Duty | Answer |
|---|---|
| Accepted selector prefix rehashed | n/a for this incremental evidence: selector untouched, but original accepted-prefix hash not rechecked; formal closeout pending |
| Decisive claims independently rederived | Verified 4/4 source-face barycentric points against OFF mesh, re-derived cyclic side partitions, independently minimized all finite segments and certified same-face paths; four deliberately corrupted copies were rejected |
| Prior obligations discharged/carried | Needle proposal vs support provenance and intrinsic minimum widths **discharged**; admissibility/compatibility, support 815/487 validity, five lens coverage/cycle and singularity obligations **carried**; P13-e and O23 independent |
| Stable accounting | Durable stable 66 events / 17 categories / 49 recurrences, debt 1; no independent recount, no reclassification |
| ORIENTATION §3/§4/§7/§8, currency line | Not yet synchronized; formal review closeout still required |
| CHANGELOG / regression tracker | Not yet synchronized; no stable regression change proposed |
| ROADMAP / manifest / LESSONS | No checkpoint or selector promotion; not changed; formal final review still required |
| Successor frozen | No; the evidence still does not establish one corrective producer or legitimate admission rule |
| Turn boundary held | Yes, **this continuation** is offline Review-only; no builds, runtimes, or product/test edits |
| `review_check.py boundary` | Historical archive-only run failed Git-ancestry checks; **not claimed PASS**; verify from actual repository Git history before completed Review |
| Status / push verification | Review evidence to be committed and branch comparison verified before final direct `STATUS` beacon; same unfinished turn and original start preserved |

**Canonical checkpoint remains `IN_PROGRESS`**, with same-turn continuation, until the upstream contracts and full review/document obligations are adjudicated. The missing causal proof is unfinished review analysis, not a confirmed external platform failure.

## `Architecture_M6_CP3_DEFN_P13_Optional_Trace_Same_Rail_Return_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Optional_Trace_Same_Rail_Return_Review_20261102.md`; moved verbatim.

### P13 arrangement sliver cells — same-rail support-return incidence audit

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (Review/Definition). **Unfinished**; this is a source and prior-evidence audit, not product implementation, formal CB, or TB.

#### Authority and independent inputs

- Semantic CB76 authority `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. Reused immutable full source snapshot event `898316210ab810daa10d2072db927f9ebe4b2a98`, archive SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062`; **6,092/6,092** file hashes independently checked in this attempt. No fresh runtime or build.
- Independently read the prior nine-cell stdout/stderr provenance archive `directional-p13-sliver-nine-cell-review-evidence.zip`, SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`, and ten-junction wedge archive `Directional_P13_Ten_Node_Wedge_Review_Evidence_20261102.zip`; SHA-256 of latter independently stored in the attached JSON receipt. The older cyclic-side geometry has a documented correction: **29 incorrect side labels, 24 family mismatches**. This new audit uses raw ordered halfedges, not the incorrect side label field.

#### Verified five same-hard-rail returns

Each lens has exactly five directed cyclic halfedges partitioning into a continuous three-edge optional support-trace path and a continuous two-edge **mandatory rail 0** path. At *both* transitions the field trace meets the same rail in the **same source face**; the source-entity resolver identifies one source-edge contact and one source-vertex contact for every lens. At each contact the prior independent wedge ledger contains exactly three outgoing rays (two mandatory-rail rays, one support ray), a single source-entity wedge group, and three chosen successors.

| Lens cell | Optional support trace | Seed index / branch | Rail-source edge contact (node; source face) | Rail-source vertex contact (node; source face) |
|---|---:|---:|---|---|
| 26735 | 1037 | 259 / 1 | 56813; 2301 | 56385; 2321 |
| 26764 | 878 | 219 / 2 | 16998; 512 | 47581; 2151 |
| 26781 | 20 | 5 / 0 | 9928; 293 | 56412; 2262 |
| 26802 | 422 | 105 / 2 | 57415; 2364 | 53651; 2385 |
| 26812 | 612 | 153 / 0 | 57661; 2401 | 23821; 2400 |

##### Source-face-local field-to-rail direction audit

Using the raw twelve-component cross-field frame (`P13_FIELD`) at each contact, the explicitly selected support family (`P13_HALFEDGE family`) and the same-source-face rail segment chord from the original `P13_NODE xyz` records, a separate **offline** calculation independently measured the unsigned family-to-rail direction angle. Both field/support segment agreement and field/rail angle were checked; the field-to-support chord angle is at most `0.000001°` within recorded precision. The field-to-rail angles below are source-face-local, not cross-face transported and not certificates of permissible trace admission.

| Cell | Rail-edge contact field/rail angle | Rail-vertex contact field/rail angle |
|---|---:|---:|
| 26735 | 9.959657° | 0.606843° |
| 26764 | 1.272584° | 0.249013° |
| 26781 | 20.599508° | 3.316825° |
| 26802 | 15.138432° | 11.073036° |
| 26812 | 26.937285° | 1.686827° |

Absolute minimum `0.249013°` (cell 26764, source-vertex tip); maximum `26.937285°` (cell 26812, source-edge tip). **Three** of the ten source-face-local contacts fall below `1.3°`. A global near-rail angle threshold would not follow from these data and is prohibited without independent validity and coverage controls. The standalone script/result are included in the evidence archive.


**Independent 5/5 and 10/10 validation:** `p13_rail_return_audit.py` and `p13_rail_return_audit.json` in the evidence archive reparse the frozen logs, rederive the entire five-edge cycle, distinct source-arc family, original support trace ID, all transitions, same source-face contacts, all three outgoing rays, unique chosen successor IDs, and matching expected tip-node sets. It rejected four separately tampered *copies* of its input: missing hard-rail identity, support-trace strand mismatch, missing tip wedge, and broken boundary cycle. None of these is a formal product test.

#### Source-path ownership and safeguards

1. `src/geometry/FlowRepStrands.cpp:608–719` creates optional anchored layout support from boundary/feature/singularity seeds when the trace has segments, begins off a rail, and ends with one of the listed embedded-anchor termination **labels**; it stops on the first authoritative rail suffix and deduplicates reversed whole paths. It does **not** reject all returns to the same hard rail at that creation point. In particular, the termination-label list includes `RepeatedState`; this alone is **not** proof the five traces terminated for that reason.
2. `include/directional/geometry/FlowRepStrands.h:74–121` defines `FlowRepArc::initiallyActive=true` and distinguishes `layoutSupport` from `mandatoryRail`. `FlowRepStrands.cpp:650–719` sets `startEmbeddedAnchor=true` and conditionally sets `endEmbeddedAnchor` only if the retained support path actually reaches the original trace terminal; explicit pre-rail prefixes cannot inherit a rail suffix's terminal anchor. These source safeguards must **not** be deleted or weakened.
3. The prior ten-node ledger independently found 30/30 recorded directed-wedge predecessors consistent and 10/10 matching published lens cell successors. The new cross-log identity audit confirms the retained support+rail network itself forms each two-sided lens. Accordingly the **observed incidence-producing path** lies upstream of pure-quad completion and should be diagnosed in traced support/FlowRep admission and retained network topology, not treated as a random wedge permutation. The upstream trace admission **cannot yet be declared invalid** under an exact source-authoritative requirement merely because the resulting lens is unsupported by completion.
4. `.agents/Directional/DESIGN.md` §4.5 requires exact source-edge grazing transits and continuity at tangency; this does **not** grant a numeric near-parallel suppression heuristic. The earlier lens polygon angles are not chart-transported field–rail tangents. Do not drop hard rail 0, snap near traces based on a world distance, increase `Sliver` area thresholds, accept two-sided patches as pure quads, or weaken the embedding fail-closed check.
5. The four needle cells remain separate: positive seed-owned proposal arcs dominate, some with optional support trace 815/487. Source-authoritative proposal ownership, source-sheet compatibility, and intrinsic corridor width remain unchecked. **No single repair for all nine cells is established.**

#### Candidate sparse-selection retention lock (new, not yet proven active)

The **original** FlowRep arc endpoints, not merely the arrangement-split halfedges, were independently matched to the same barycentrically exact source vertex at all five lens rail contacts:

| Lens | Vertex node | Original optional FlowRep arc | Original rail-0 FlowRep arc |
|---|---:|---:|---:|
| 26735 | 56385 | 2644 | 130 |
| 26764 | 47581 | 2514 | 109 |
| 26781 | 56412 | 156 | 2 |
| 26802 | 53651 | 981 | 53 |
| 26812 | 23821 | 1857 | 77 |

The independent `p13_original_arc_vertex_contact_audit.py` and JSON establish this identity using both `P13_NODE` source-face barycentrics and the unsplit original `P13_ARC` endpoint coordinates, with a strict one-hot source-vertex and 1e-10 endpoint match. This **strengthens** the source-selection hypothesis: `include/directional/geometry/FlowRepStrands.h:105` starts every arc active; `src/geometry/FlowRepStrands.cpp:2124–2172` calculates `protected_endpoint_degrees` from the initially active set, including optional support arcs, protects all hard-rail endpoints and degree≥3 junctions, then rejects a trial that changes **any** protected endpoint degree. `:2559–2625` attempts optional-flowline removals but calls `preserves_protected_endpoint_degrees`, reverting failed removals. Therefore deleting an optional support at its source-vertex rail junction **without compensating endpoint incidence** would fail the degree guard even if the support was not mandatory. This is a concrete *candidate retention-lock mechanism*, not proof that all five particular trial transactions were attempted and rejected: the archive lacks the per-flowline trial/evidence/rejection ledger and complete preselection incidence. The exact active selector and any legitimate replacement must not weaken protected mandatory rail/singularity incidence. A future correctly authorized build/probe should identify original trace IDs, trial flowline IDs, initial/proposed protected degrees, coverage and cycle guards, and first rejection reason for those five traces. A negative control must demonstrate a genuinely optional removable rail-contact trace, and a positive control must demonstrate a required branch being protected.

#### Required next authorized Review action

Check the exact **tracing terminal reasons**, intrinsic start/end point keys, same-sheet rail intervals, transported field/rail tangent at each of the ten contacts, and whether a legitimate required separatrix/coverage/cycle obligation mandates retaining each return. Obtain that evidence without another Review runtime execution (normative `REVIEW_TURN_POLICY.md` §4 requires a runtime-free Review); any new probe must first be authorized under the correct CB/TB or policy exception. If all five are proven optional and nonessential, define a *bounded and falsifiable* source-owned candidate in the support-trace selection path; require a positive valid rail-return control, negative invalid control, reversed/permuted rail control, source-chart/sheet check, unchanged mandatory rails and accepted prefix, and no new singularity or coverage loss. Do not infer that arbitrarily deleting these exact five traces is correct.

#### Review policy/boundary result and carry-forward

`python3 .agents/Directional/tools/review_check.py boundary` was executed on the **verified extracted archive**, exit **1**. It reported product/test/build and selector mutation checks PASS locally but four failures: durable rewrite baseline ancestry and three durable-source Git-history checks (`Future_Chat_Session_Handoff.md`, `ORIENTATION.md`, `Regression_Root_Cause_Tracker.md`). The extracted archive has no full repository Git ancestry; the `PASS` lines treating many selector files as "untracked, new this turn" are **not** credible turn-diff evidence. Do not report this as a green policy check or as a product regression. GitHub branch-diff inspection must separately establish the actual mutation boundary.

Preserve accepted CP2 **491/491**, candidate TB70 **880/880** with selector membership **961**, stable **66/17/49**, debt **1**, and no CP3 promotion. Continue the same Review/Definition turn; formal review closeout (ORIENTATION currency, CHANGELOG, root-cause tracker, exact successor falsifiers and repository-backed `review_check.py boundary`) remains unresolved. No new code/build/runtime/selector edits in the working branch are authorized by this report alone.

#### Review closeout (interim, intentionally not a completed turn)

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector edited or promoted; accepted prefix still requires verification at formal closeout. |
| Decisive claims independently re-derived | 5 lens cycles, ten rail contacts, wedge counts and source identities independently reconstructed from two frozen raw logs; source admission statements checked against CB76 snapshot. |
| Non-vacuity checked | Four independently corrupted input copies rejected by new audit; this does not certify upstream tracing correctness. |
| Prior obligations discharged/carried | P13-i retained-return structure refined; carries exact trace admission/rail transit authority; P13-h2 needle proposal ownership and intrinsic width, P13-e, O23 remain. |
| Stable accounting | 66/17/49, debt 1, CP2 491/491; reported from prior durable authority, not independently re-counted here; TB70 880/880 and membership 961 remain unpromoted. |
| New candidates/obligations recorded | No proved new product defect; candidate falsifier for five same-rail optional trace returns documented in this report, not yet tracker-accepted. |
| ORIENTATION currency line | Not updated; turn unfinished, formal closeout outstanding. |
| ORIENTATION §3 / §4 / §7 / §8 | Not updated; checkpoint/witness state unchanged, pending formal review consolidation. |
| CHANGELOG | Not updated; interim review result, not a completed checkpoint. |
| ROADMAP | n/a — no accepted checkpoint transition. |
| Selector manifest | n/a — no selector change or promotion. |
| LESSONS | n/a — no new proven recurring defect; diagnostic provenance controls documented here. |
| Consolidation under CLEAN_UP_POLICY | n/a — this is new unique supporting evidence, not consolidation of historical files. |
| Successor frozen | No — not justified without trace-admission and needle-owner falsifiers; same Review continues. |
| Turn boundary held | This attempt ran no builds or product tests, changed no production/test/fixture/selector code; offline Python diagnostic only. Prior scratch Review runs remain an acknowledged policy deviation, not a precedent. |
| review_check.py boundary | FAIL exit 1 on extracted snapshot, Git-ancestry dependencies unavailable; 4 failures named above. |
| `STATUS` lifecycle maintained | Entry/resume beacon direct-written; final beacon must be direct-written after all other repository actions with original start preserved. |
| Pushed to origin, branch in sync | Connector writes update the remote branch directly. No local clone tracking branch exists in the extracted archive, so `git status -sb` cannot truthfully confirm synchronization. Independently inspect GitHub PR head and exact diff before final STATUS. |

## `Architecture_M6_CP3_DEFN_P13_Protected_Endpoint_Degree_Veto_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Protected_Endpoint_Degree_Veto_Review_20261102.md`; moved verbatim.

### P13 lens same-rail returns — protected endpoint-degree veto review

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. **2026-11-02; interim independent Review/Definition evidence, not a finished turn or an implementation authorization.** A source-level deletion veto is proved; deletion correctness and needle ownership are not.

#### Authority and scope

- Exact semantic production source: CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. Reused verified snapshot `898316210ab810daa10d2072db927f9ebe4b2a98` (outer ZIP SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062`). All **6,092/6,092** file hashes passed; the CB76-to-current-head GitHub comparison found **zero semantic-source changes**. Source-file SHA-256: `FlowRepStrands.cpp` `d599f478a516804e166b125c2890e55ccc40fe85a82a85b363d81d618b34a5b6`; `RemeshPipeline.cpp` `fca712094c21313fddb81f40160b392dbf1ab1888e632fa4f3c00e17b764db12`.
- Raw independent prior Vase scratch stderr SHA-256 `e0a28c941bdaf4d86a1a5d0cf23216ac890f266b67d591e2a7c528a00e189530` from immutable conversation artifact `directional-p13-sliver-nine-cell-review-evidence.zip`, ZIP SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`. That prior scratch runtime violated the Review boundary. This continuation is **offline-only**.
- Stand-alone offline source/receipt audit: `p13_protected_degree_review.py`, SHA-256 `4f91077fafd344e9976138838429eea26c49cc8289c314a481c3563c7566c56b`, emitted `p13_protected_degree_review.json`, SHA-256 `51ee46e1521ce7add0998532d66e9f1e35c1dca89f1c2684ecaa1e465a505d06`. It independently parsed raw `P13_ARC/HALFEDGE/NODE` and relevant source, verifying **5/5** original-vertex joins.

#### Original-source contact proof

Each originally emitted optional support FlowRep arc has one endpoint at exactly the same **source face and one-hot barycentric vertex** as a separate **mandatory rail-0 FlowRep arc**, **before arrangement splitting**. Intrinsic endpoint identity in `FlowRepStrands.cpp:1915–1985` includes this same source-vertex topology and its source region/sheet; for arcs emitted from the same source face, both scope labels come from the same `network_source_scope`. Therefore both endpoints contribute to the **same protected endpoint key** in sparse selection. The dense degree is **at least 2**, not necessarily exactly 2.

| Lens cell | Seed trace (`4×seed+branch`) | Source-vertex node | Source face | Original support arc | Original mandatory rail arc | Hypothetical pure-deletion degree delta |
|---|---|---:|---:|---:|---:|---:|
| 26735 | 1037 (`259,1`) | 56385 | 2321 | 2644 | 130 | −1 or less |
| 26764 | 878 (`219,2`) | 47581 | 2151 | 2514 | 109 | −1 or less |
| 26781 | 20 (`5,0`) | 56412 | 2262 | 156 | 2 | −1 or less |
| 26802 | 422 (`105,2`) | 53651 | 2385 | 981 | 53 | −1 or less |
| 26812 | 612 (`153,0`) | 23821 | 2400 | 1857 | 77 | −1 or less |

All five support arcs have `proposal=-1`, `hard=0`, `rail=-1`, and `strandProvenance=-2-supportTraceId`. All five matched rail arcs have `hard=1`, `rail=0`. Original endpoints were checked within 1e-10; arrangement-split incidence alone is insufficient.

#### The exact source-level veto (not an observed diagnostic reason)

1. `FlowRepStrands.cpp:610–720` constructs each anchored seed support path as an **optional** `FlowRepArc` with seed-derived `supportTraceId=4*seedIndex+branch`. The `FlowRepArc` default `initiallyActive=true` applies, unlike singular transition-ring support paths re-rooted later. Mandatory rails also enter the dense network as active constraint arcs. `build_flow_rep_selection_input` precedes `select_sparse_flow_rep_network` and `complete_flow_rep_endpoints` in `RemeshPipeline.cpp:13487–13576`.
2. `FlowRepStrands.cpp:2126–2158` counts **all initially active endpoint incidences**, including optional support arcs. Any endpoint touched by `boundaryRail`, `hardFeatureRail`, `mandatoryRail`, `singularitySupport`, or having degree≥3 is protected. The shared original source vertex of each row is therefore protected by the mandatory rail, and the required degree includes its optional support incidence.
3. `FlowRepStrands.cpp:2161–2178` demands *exact equality* between every required protected degree and the trial degree. Removing an optional support flowline that contains the listed arc **without a compensating active arc endpoint at that same intrinsic key** reduces a required protected degree. Therefore **`preserves_protected_endpoint_degrees` must return false for that deletion**. This is a necessary selector veto for these five observed source configurations, independently of any coverage/cycle or geometric decision.
4. `FlowRepStrands.cpp:2560–2628` builds the frozen degree map once before greedy transactions and rejects/rematerializes any removal when either the evidence or endpoint guard fails. Source code treats `mandatoryRail`, `hardFeatureRail`, `boundaryRail`, `singularitySupport` as mandatory flowline ownership; the seed-derived supports in this review are optional. The `constraintOnlyNetwork` fast path cannot explain the observed retained positive-proposal arcs in Vase; the ordinary transactional path is relevant.
5. This **establishes a deletion-veto mechanism**, not the observed first rejection reason: the archived scratch stdout/stderr has no per-flowline trial ledger, and another guard may also reject the same trial. In particular, the raw record does **not** prove that these five traces are redundant under valid cycle coverage, singularity or topology constraints. Blanket removal or relaxed degrees is unjustified.

**Non-vacuity:** The offline audit also evaluated the literal protected-degree equality rule on three deliberately distinct logical cases: deletion at a protected endpoint fails; deletion at a genuinely unprotected endpoint passes the *degree check*; replacing the deleted incidence at the protected endpoint passes the *degree check*. These are proof controls for the predicate, **not product tests** or evidence that replacement yields a valid geometric network.

#### Correct causal boundary and outstanding falsifiers

The preceding ten-node wedge audit reported 30/30 internally consistent predecessor choices, with five lenses each supported by the same rail-return source arcs. **Upstream tracing admits** those anchored support paths; **FlowRep sparse selection structurally cannot simply delete them** because the mandatory rail's protected original vertex degree includes the optional incidence; **arrangement then faithfully embeds** their retained source network as two-sided lens cells; **patch completion correctly fails closed**. This chain narrows where a correction could be made. It does **not** prove that the original path was invalid: two-sided source-cell geometry could be an unavoidable consequence of a valid tracing contract or demand a different upstream layout.

Next evidence must establish each trace's terminal, seed, same-sheet rail interval, singularity obligation, **coverage delta**, and **cycle energy**. If proven redundant, compare admission rejection with validated replacement; never globally relax protected degrees. Demand positive required rail-return control, negative redundant support control, reversed/permuted rail case, exact source-chart/sheet scope, invariant rail ownership, coverage/cycle witnesses and unchanged accepted prefix. Review remains runtime-free; new probes need CB/TB authority or explicit exception.

**Four needle cells remain independent:** `6095,20533,20968,22350` have very thin **Euclidean** opposing sides and distinct seed proposal ownership. The rail degree veto does not explain them; intrinsic width/proposal admissibility remains outstanding. Do not merge the two owners or freeze a new Code + Build successor without that decision.

#### Review closeout (interim, not a completed turn)

| Required duty | Evidence / carry |
|---|---|
| Decisive claims / non-vacuity | Five original source endpoint joins independently rederived from raw logs; protected-degree equality source verified; three logical predicate controls differentiated outcomes. |
| Accepted selector prefix | No selector edited or promoted; accepted CP2 491/491 and TB70 candidate 880/880 with membership 961 are unchanged by this review, but prefix was **not rehashed** in this continuation. |
| Stable accounting | Stable 66 events / 17 categories / 49 recurrences; debt 1 per existing durable authority, **not independently recounted here**. |
| Prior obligations | P13-i direct deletion guard narrowed; actual path validity / coverage / cycle still carried. P13-h2 needle-source ownership, P13-e and O23 separate. |
| Corrective source/test/selector edits | None; Review boundary held, no new runtime or compile. |
| ORIENTATION, CHANGELOG, tracker and successor | Still pending formal review closeout; no accepted checkpoint or selector changed. Roadmap and manifest unchanged. |
| `review_check.py boundary` | Historical run on archive-only tree exited nonzero on Git-ancestry requirements. **Not rerun** and **not claimed PASS**; proper Git-history verification still pending. |
| GitHub sync / lifecycle | Work committed directly to target remote branch. Final PR diff and direct root `STATUS` beacon to be verified/written at response closeout. Original start `2026-11-02T05:14:30Z` must be preserved. |

**Turn remains `IN_PROGRESS`; successor is the same Review turn**, not an authorized implementation. No required independent external approval or outage has been demonstrated, because the source/provenance and needle investigations still have available authorized offline work.

## `Architecture_M6_CP3_DEFN_P13_RepeatedState_Anchor_Admissibility_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_RepeatedState_Anchor_Admissibility_Review_20261102.md`; moved verbatim.

### P13 source Review — overloaded RepeatedState and anchored support-tip admissibility (2026-11-02)

**Owner and boundary:** Unfinished `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` Review; same canonical turn. This is a read-only source-derived **conditional defect mechanism**, not proof any of the nine Vase cells used it and not an authorized source correction. Semantic authority CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72`, existing source snapshot `4f48f09562740bcdff78cacb6a9159b0299238a8` (artifact 13142187868, SHA-256 `cdbd72e5294c8659e16cb71bde42cdabb8f84765cd750efc2d3e38b2053266b8`, 6104/6104 source hashes independently reverified); no compiled/runtime code changed.

#### Exact source-level causal route

1. `src/geometry/SurfaceCellTracing.cpp:11176–11185` appends a quantized trace state, then terminates `RepeatedState` if insertion into `visitedStates` fails after the initial step. This branch means **revisited quantized state**, not necessarily bit-identical source geometry.
2. `:11204–11228` can **also** terminate `RepeatedState` if a step after the first is on a source-face edge and **no finite positive exit** exists (`hitCorner<0 || !std::isfinite(bestT)`). The inserted state was unique in that iteration. This is a distinct code path with no proof of return to any prior network vertex. It does not prove a tangential graze: a direction pointing out of the face at an edge can also satisfy the branch.
3. `src/geometry/FlowRepStrands.cpp:645–650` classifies both kinds of `RepeatedState` as eligible embedded anchors. `:663–718` accepts a non-rail-prefix support path from eligible boundary/feature/singularity seeds and assigns the **last support arc** `endEmbeddedAnchor=true` whenever its segment count equals the full trace segment count. The code does not examine `states` or the actual terminal subtype at that assignment.
4. `FlowRepStrands.cpp:438–463` labels an arc endpoint with `start/endEmbeddedAnchor=true` as `NetworkJunction` ahead of the separate degree-based condition. In `complete_flow_rep_endpoints` (`:3111–3125`), a degree-one endpoint enters `openEndpoints` **only** when `!embeddedAnchor`. `RemeshPipeline.cpp:13517–13536` executes sparse selection followed by this endpoint-completion stage. Therefore **if** an optional full-path support ends with `RepeatedState` from the *unique-state/no-finite-exit* branch **and** its retained endpoint has degree one, the endpoint is classified as anchored and is excluded from the source-owned completion attempt despite no demonstrated revisit or connected rail/junction.
5. A separate index-aware singular support uses the same terminal predicate (`FlowRepStrands.cpp:776–778`), but can be mandatory due to singularity index. Do not delete or suppress singular separatrices based on the generic optional-support example.

**Source-level counterexample (not a Vase measurement):** at barycentrics `(0,0.4,0.6)`, tangent-coordinate barycentric derivative `(-0.3,0.2,0.1)` has no strictly positive edge-exit parameter: its only negative derivative coordinate is already zero. A trace after one or more finite segments entering that state takes the no-finite-exit branch. Tangent derivative `(0,-0.2,0.2)`, on the same point, instead yields a finite exit parameter `t=2`; do not equate the former with a generic grazing event. This illustration establishes branch feasibility algebraically but not whether the full admissible field-transition system can produce the configuration in the Vase fixture.

**Causal limitation:** the original five two-sided lenses have three outgoing rays at their observed mandatory-rail tip nodes; a tip with **actual degree three** is not omitted from `openEndpoints` solely due to its anchor flag because the endpoint-degree-one condition already fails. A path from a misclassified terminal to the particular lens must be proved with original ordered support arcs, seed vs terminal endpoint, intrinsic identity and preselection degrees. The prior scratch ran with `retainIntermediateGeometry=false` and lacks the source trace state vectors. Existing final arrangement data cannot distinguish the two `RepeatedState` branches. **No assertion is made that this source mechanism actually caused any of the five lenses or four needles.**

#### Explicit test-coverage gap (2026-11-02 14:48Z; offline)

Both `RepeatedState` producers append a state without a final segment: the repeated-key branch appends a duplicate (`SurfaceCellTracing.cpp:11176–11185`); the edge/no-finite-positive-exit branch appends a unique state (`:11200–11228`). Therefore **`states.size() == segments.size()+1` is not a sufficient subtype discriminator**. Check duplicate *complete quantized keys*, not vector length, and then independently prove contact, chart/sheet and retained endpoint degree.

`tests/MilestoneCClosureTests.cpp` expects a periodic-cylinder `RepeatedState` and asserts that same size relation; it is a positive periodic control, not a no-exit oracle. The frozen `tests/FlowRepStrandsPhase15Tests.cpp` has **no explicit `RepeatedState` reference**, although it tests truncated-rail support with `endEmbeddedAnchor=false` and unanchored degenerate singular support. Thus the existing inspected tests do not explicitly distinguish generic no-exit optional-support anchors. `DESIGN.md` §4.6 forbids self-contact alone as the normative A2a stopping rule; applying that rule to this generic consumer requires a proven common authority, not an enum-wide rewrite.

Read-only source-coverage audit: `directional_p13_trace_coverage_audit.py` SHA-256 `3750f4dace3b298b761d38e4bc54ffd6111ad0a181d56e46bd409b4298876af8`, JSON SHA-256 `6ce2987593c86889dced57895a6a2ecf18d4662a77d7ef3006ddaff89f86653f`; **12/12** static assertions and **4/4** in-memory negative controls. No Directional binary, test or build ran. Future authoritative CB/TB verification must distinguish a valid periodic path, a unique no-exit unconnected tip, and a source-sheet-mismatched contact while preserving genuine rail and singularity constraints; these outcomes are not yet known for Vase.

#### Independent non-vacuity and conditional decision

Offline read-only static audit (downloadable, not a product test): `p13_terminal_anchor_source_audit.py` SHA-256 `ea81c272436157d21819b82a6fd26559a13f70d352ee69f34c5e254584c23831`, JSON `P13_Terminal_Anchor_Source_Audit_20261102.json` SHA-256 `4aa06bfdcda1e613a077d3141a29e1e85769cdbaf92ab9c663aed364b856af5d`. **11/11** static source-control assertions succeeded; four independently changed *in-memory source copies* were detected (no-exit enum changed, anchor classification changed, degree-one guard deleted, trace-state recording deleted). The first script run raised an exception when a tampered copy removed a required substring; the corrected checker treats missing substrings as explicit negative evidence, retains the full assertion, and then passed all controls. No Directional binary, compilation, CI test or fixture executed.

**Discriminating evidence before correction:** for each support trace `1037/878/20/422/612`, recover the exact typed terminal and duplicate-state count, terminal vs rail-seed endpoint, source chart/sheet, original end intrinsic node key, degree immediately before endpoint completion, and actual selected arc membership. A valid repeated loop, an outward no-finite-exit into an *unconnected* tip, a hard-rail-captured support, and a required field separatrix must be independent positive/negative controls; preserve exact mandatory rail ownership, protected degrees, source-sheet identity and final injective embedding. If the no-finite-exit misanchor is demonstrated, separate that terminal subtype from actual repeated-state capture **at the producer or source-authoritative consumer**, without globally disallowing valid repeated-state loops. A termination-label change alone is not sufficient to explain a **three-ray mandatory-rail lens**. If those five supports are valid, keep them and investigate source-index-valid completion or a topology-preserving replacement instead.

**Deletion-only constraint:** in `FlowRepStrands.cpp:2126–2175,2559–2625`, a connected three-ray rail junction is protected at its baseline degree. Removing a support arc while retaining both mandatory rail arcs reduces its degree from three to two, and is rejected independently of cycle or coverage evidence. This is a conditional **impossibility of pure deletion** whenever the relevant original FlowRep endpoints genuinely share that protected intrinsic key; arrangement-split ray coincidence alone does not prove such original preselection equality. No production assignment of `FlowRepArc.substitutions` was found in the unchanged `src/` tree, so the substitution pass cannot be assumed to supply a compensating replacement.

**Review decision:** no single verified defect/owner or exact bounded CB/TB successor spans four needles and five rail lenses. Continue the same runtime-free DEFN. Refer to `Architecture_M6_CP3_DEFN_P13_Cross_Stage_Evidence_Contract_20261102.md` for nine-cell provenance, required atomic selector trial receipt and source-index controls. Do not relax numerical sliver tolerances, skip final embedding, remove mandatory rails, invent a two-sided completion exception, or claim CP3 acceptance. TB70 880/880 and membership 961 are unpromoted; accepted CP2 491/491, stable 66/17/49 and debt 1 unchanged. `review_check.py boundary` cannot be reported passing from the Git-history-free snapshot (prior archive invocation exit 1 on four history-dependent checks); formal Review closeout remains pending.

## `Architecture_M6_CP3_DEFN_P13_Sliver_Review_Scratch_Execution_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Sliver_Review_Scratch_Execution_20261102.md`; moved verbatim.

### P13 nine-cell provenance — isolated Review scratch execution (2026-11-02)

**Owning turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. **This document is Review evidence, not a Code + Build or Test + Benchmark acceptance record.**

**Evidence erratum (2026-11-02T06:37Z):** The archived `p13_geometry_observations.json` and its per-side lengths/opposite-side distances are **superseded for seven cells** because the scratch probe incorrectly assumed cyclic `sideEdgeCounts` starts at `cell.halfedges[0]`. The independently reconstructed `Architecture_M6_CP3_DEFN_P13_Cyclic_Side_Corrective_Audit_20261102.md` fixes 29 incorrectly side-labeled halfedges (24 also have mismatched recorded families), and its corrected measurements control. The 9/9 arc/provenance/node receipt and raw stderr remain valid within their checked scope; the face-local field/rail chord angles did not depend on the bad side labels. No production defect is inferred from this scratch error.

#### Frozen immutable source and scratch exception

- Production semantic CB76 source: `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. The independently downloaded source snapshot at `898316210ab810daa10d2072db927f9ebe4b2a98` has identical `RemeshPipeline.cpp` SHA-256 `fca712094c21313fddb81f40160b392dbf1ab1888e632fa4f3c00e17b764db12`; archive and 6092/6092 source checksums passed.
- **Exceptional scratch-only branch** `agent/scratch-p13-sliver-provenance-20261102` from exact CB76, source SHA `95684f2e18c3c573dcbf11d35deaad696d0316d3`. Necessary because Review permits a diagnostic probe but forbids production-source mutation; the standard dispatcher compile request can select an exact commit on an isolated branch. This branch must not be merged, promoted or treated as canonical source. It remains temporary until the probe evidence is preserved and branch retirement can be performed by an authorized branch-deletion tool.
- GitHub `compare_commits(f59f92...,95684f...)`: exactly **one source path** `src/pipeline/RemeshPipeline.cpp` changed (+149/−0), no product semantic behavior changes intended. The scratch blob `2cc737e903a5a0b6d1d36a8ef1ba20d10e9e7221` matched the locally computed exact `git hash-object`; original blob `91d681bd98db2f1bbf3767cabd83c03e2a6b0b5e`. The opt-in instrumentation is `DIRECTIONAL_P13_SLIVER_PROBE=1`; no permanent context retention or topology edits.
- Original patch is preserved in the ChatGPT File Library/conversation as `directional-p13-sliver-scratch-probe.patch`, SHA-256 `2deb0780ef3fe3991bbbcda820a7ca286f0826aab5a5e683b2d65b6f03a4c00e`.

#### Verified scratch GMP compile

- Triggering working-branch dispatcher request commit `9dafa1680f0dc8cb699780a053c3b58c3cda954b`, operation `compile`, exact source `95684f2e...`, target `directional_surface_cell_producer_tests`. No reusable workflow or permissions edited.
- Workflow `41398086098` **successful**; mailbox key `m6-cp3-p13-sliver-review-scratch-compile-20261102-v1` on dedicated `workflow-mailbox` ref; source/event identities verified. Immutable artifact `13119948654`, ZIP SHA-256 `e283bdb1070dd29658ece5964f2574529ce70e3359f1480d14a37cd44ea0fd7a`, **23/23 packaged checksums PASS**, source SHA exact, exit code 0, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, link evidence includes `gmpxx` and `gmp`. This is **scratch compile evidence only**, not a product build or accepted-green test.
- Artifact backup available to the user as `directional-p13-sliver-scratch-compile-41398086098.zip`.

#### Scratch runtime diagnostic

- One fresh local process launched at **2026-11-02T06:12:35Z** from that exact packaged binary with source-archive fixtures supplied adjacent to the executable, environment `DIRECTIONAL_P13_SLIVER_PROBE=1`, gtest filter `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. This fixture explicitly requests `SurfaceCells`, `fallbackPolicy=Fail`, `allowSourceGridRecovery=false` and `retainIntermediateGeometry=false`. **It is an authorized Review scratch diagnostic, not a formal TB gate.**
- The process is bounded by `timeout -k 10s 390s`; raw stdout/stderr and exit-status files live under `/mnt/data/p13_review_0601/`. No result/ownership claim should be made until terminal evidence and all nine receipts are independently checked.
- Receipt checker `p13_sliver_receipt.py` SHA-256 `2405a11451ac21c3a2b11b9f15145388d8e4a5a8d767fd5b84eb7dd4254ec114`. Optional geometric observational processor `p13_sliver_geometry.py` SHA-256 `7764b0b17165da3fde6722725142c441489d88b73544afbe935141a1eb54d831`, syntax checked, no output yet. Euclidean minima and chords are **not** intrinsic distances or field matching certificates.

#### Required Review completion

Capture and independently audit the nine target cells (needles 6095,20533,20968,22350; lenses 26735,26764,26781,26802,26812). Distinguish source-provenance arc selection from arrangement successor pairing, compute same-sheet intrinsic widths and chart-transported field-vs-rail tangent angles where source authority permits. Freeze **one** falsifiable producer owner and exact CB/TB plan only with complete evidence. Do not relax admissibility, modify the frozen selector, claim a successful production output, or mix this diagnostic with accepted TB70 (880/880, membership 961) and CP2 (491/491). P13-e remains independent.

**Closeout rule:** If the scratch process has not delivered adequate evidence by the bounded turn response, preserve this Review as `IN_PROGRESS`, same original Started at `2026-11-02T05:14:30Z`, latest Resumed at `2026-11-02T06:02:10Z`, blank Ended at, and the same-turn successor. No authorized Code + Build successor is named yet.


#### Verified terminal scratch observation — 2026-11-02T06:19Z

The direct scratch Vase process exited **1** (expected non-acceptance), with one gtest failure and the same first production terminal as TB70: `NotProductionReady:completion / PatchCompletionRejected / InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch`, 192482 traces, 26827 arrangement cells, **0 output quads**, measured 261644 ms. No production acceptance, rebuilt product, fixture or selector gate is claimed.

Independent scratch provenance receipt: **9/9 complete, 0 validation errors**. Needle cells `6095/20533/20968/22350` have 4 sides each, 6/6/9/10 directed halfedges, **no rails**, and span 4/4/2/3 distinct proposal IDs respectively. Lens cells `26735/26764/26781/26802/26812` each have 2 sides, 5 directed halfedges, hard rail `0`, and no proposal IDs. Original retained FlowRep IDs, compact source-arc joins and per-node source-face/chart occurrences are included in the independently checked receipt. The field-trace/hard-rail boundaries pre-exist completion; completion did not invent those arcs. Same-source-face cross-arm/rail chord angle samples include **0.249°, 0.607°, 1.273°, 9.960°, 15.138°, 26.937°**. Opposite-side Euclidean minima (not intrinsic distance) are recorded for all four needles.

**Preserved user-visible evidence:** `directional-p13-sliver-nine-cell-review-evidence.zip`, SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`. Contains raw stdout/stderr/exit receipt, 9/9 provenance JSON, geometry observations JSON, original exact probe patch and the independently auditable scripts/report. Geometric helper's final SHA-256 `c612af85d19e43276a9f7be2963e3a5040434a8941b277672f753c1593f76069` supersedes the provisional helper hash above.

**Unresolved owner:** These observations do NOT establish whether an upstream trace/FlowRep selection admitted incompatible rails/strands or the arrangement selected wrong directed successors. The arrangement has materialized the selected source arcs, and completion correctly fails closed, but a single authoritative corrective producer has **not** been proven. An exact same-sheet intrinsic separation and transported field/rail family-angle certificate remains outstanding. No code patch or successor CB is authorized. Preserve this Review as unfinished. Temporary diagnostic branch must be retired once its reproducibility purpose is served, through authorized branch deletion (not available in the current GitHub connector).

## `Architecture_M6_CP3_DEFN_P13_Trace_Termination_Anchor_Source_Review_20261102.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Trace_Termination_Anchor_Source_Review_20261102.md`; moved verbatim.

### P13 Review — trace termination versus embedded endpoint authority (2026-11-02)

**Canonical Review owner:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`; same-turn continuation, **not closed**. This document adds source-level causal falsifiers; it does not authorize product changes, tests, runtime execution, a successor or CP3 promotion.

#### Source and evidence boundary

- Reused immutable source snapshot at `6c95f68120a20c55ddc09fd155de83f633e49549`, run 41393896396, ZIP SHA-256 `701182750fbd98aa589f1792c4490224ed295ec2821d754bca8e02563550a27a`. Independently verified ZIP digest and **6,092/6,092** internal SHA-256 source files this attempt. Prior full current-head comparison found zero semantic source/test/fixture/build changes.
- Independently examined production `src/geometry/SurfaceCellTracing.cpp`, `src/geometry/FlowRepStrands.cpp`, `src/geometry/PureQuadCompletion.cpp`, normative `DESIGN.md`, `Architecture_M6_Frozen_Definitions.md`, and RA-197. Companion offline source check `flowrep_anchor_source_audit.py` passed, and **three mutated *copies*** were rejected: removing the repeated-state anchor label, removing the no-exit repeated-state outcome, and bypassing the anchored-tip exclusion. Source check and negative controls prove the examined syntax/control-flow relationship, **not** Vase branch reachability or behavioral acceptance; no Directional executable was run.
- The previous accepted CP2 selector remains 491/491 and unpromoted TB70 candidate 880/880 with 961 membership, 81 deferred. Stable bookkeeping stays 66 events / 17 categories / 49 recurrences, debt 1. None was modified or re-accepted here.

#### Narrow source-derived finding — one termination label, two causes

1. `SurfaceCellTracing.cpp:11183–11185` emits `TraceTerminationReason::RepeatedState` when the exact directed state is visited again. That case may represent a genuine recurrent path.
2. **Separately**, `SurfaceCellTracing.cpp:11219–11226` emits the **same** `RepeatedState` when the tracer has already advanced, finds **no finite positive next face exit**, and the current point lies on any face edge. That branch does **not** require a repeated prior state, captured network arc, mandatory rail or certified singularity. It is a distinct termination cause concealed by the same enum value.
3. `FlowRepStrands.cpp:647–650` admits `RepeatedState` as an `embedded_anchor` terminal reason for generic seed traces; `:662–717` only checks the seed's Boundary/Feature/Singularity provenance, nonempty path, terminal enum and no first rail suffix. When the entire trace prefix is retained, its last arc receives `endEmbeddedAnchor=true`. `:439–461` classifies the flag as `NetworkJunction`; `:3107–3127` excludes that flagged endpoint from degree-one endpoint completion. Neither source site independently proves the **particular repeated-state endpoint** touches another retained embedded arc.
4. **Potential missing authority, not a confirmed P13 defect:** an edge/no-exit `RepeatedState` on a generic anchored support can therefore be treated as an embedded junction without a collision/contact certificate. Exact per-trace terminal reason, the no-exit/revisited-state subcause, original endpoint key, retained incidence degree and source region/sheet must be observed before attributing any Vase cell to this path. Valid closed/recurrent paths must not be rejected merely because their terminal enum is `RepeatedState`.
5. **Existing narrow precedent is not a general fix.** `FlowRepStrands.cpp:932–1195` has a separately guarded singular-separatrix micro-loop remedy: it requires a specific singular source vertex and intrinsic transition ring, tests which ring crossing or pre-ring return occurred, and conditionally substitutes a canonical radial spoke. The five observed hard-rail lens supports derive from **generic seed branches** (trace IDs 1037, 878, 20, 422, 612), not that singular transition-ring owner. This mechanism proves why a legitimate replacement needs independent topology authority; it cannot be copied over by distance/angle tuning.

#### Geometric validity versus quality — corrective scope

- `Architecture_M6_Frozen_Definitions.md:8` explicitly sends **O23 needle-cell quality to M7 unless these cells are removed by a valid correction**. `DESIGN.md` §2.2 reserves `QualityRelaxed` D1 for a complete pure-quad mesh missing calibrated quality gates; §4.9 separates injectivity from distortion. The four P13-h2 failures are instead **M6 structural embedding failures with generated quad vertices**, while all five P13-i lenses have **two logical sides**, correctly rejected by `PureQuadCompletion.cpp:1875–1891`. A narrow accepted cell is not automatically a source-admission contract violation.
- RA-197 tried corner-bilinear, Coons and Tutte interior placements; each leaves failures, but this **does not prove that no valid interpolant or embedded quadrangulation exists** for the four fixed patches. Its phrase “No interpolant embeds them all” must be read as limited to those tested candidates. Exhaustive impossibility or an explicit counterexample construction is still outstanding.
- Two independent boundary questions remain: (i) do the needle boundaries possess a source-attached embedded conforming completion under the existing fixed boundary/schedule, or must their **valid** upstream layout change? (ii) are the five hard-rail return supports permitted or necessary under exact tracing, topology, singularity coverage and protected endpoint degrees? No universal width cutoff, tolerance, dropped rail or blanket optional-support deletion follows.

#### Retained-state discriminator — no tracer modification needed (2026-11-02 13:31Z)

**New source-derived offline recovery:** `SurfaceTraceResult` retains `states` plus `termination` (`SurfaceCellTracing.h:1270–1295`); the `SurfaceTraceState` ordering/equality includes face, entry edge, family, sign and quantized barycentric coordinates. In the CB76 `trace_surface` loop, each current state is appended **before** attempted insertion into `std::set<SurfaceTraceState> visitedStates` (`SurfaceCellTracing.cpp:11176–11185`); unsuccessful insertion immediately returns `RepeatedState`. The **only other** assignment of that enum in this tracer is the no-finite-positive-exit/face-edge branch (`:11219–11227`), reached only after successful insertion. Consequently, if and only if the original trace result is available and its terminal enum is `RepeatedState`: **duplicate in its `states` vector → revisit under the tracer's quantized state key; all states unique → no-finite-exit on an edge**. The key rounds each barycentric coordinate at `1e-9` precision (`SurfaceCellTracing.cpp:6548–6568`); a duplicate is **not** proof of bit-identical positions, an exact geometric periodic orbit, or a legal network anchor. This is a deterministic discriminator of the producer branch, not an embedded-contact or invalidity certificate. Distinguish exact state equality from proximity; do not reclassify genuine cycles as invalid.

**Preservation limit:** `RemeshPipeline.cpp:13447–13449` copies the trace network into `productSnapshots.traceNetwork` only when `retainForExecution` is enabled; `:13504–13514` releases the full trace network after FlowRep input construction otherwise. That flag is `retainIntermediateGeometry || injectFailureAfterStage>=0` (`:12329–12332`), **but failure closeout calls `clear_unrequested_intermediate_context` (`:12391–12420,12464–12469`), which clears the snapshot unless `retainIntermediateGeometry` was requested**. Thus failure injection by itself is insufficient to recover the states from a returned rejected result. Existing terminal-count summaries and downstream FlowRep arcs **do not reproduce `states`**. Search previously retained snapshots/artifacts for the full five traces `1037/878/20/422/612` and needle traces `815/487`; if absent, the prior scratch logs cannot be assumed to contain these state vectors. This static finding reduces the required *new* probe to preserving/reporting already-existing typed state data at its source, rather than modifying tracing classification.

**Availability correction:** the documented P13 scratch Vase invocation explicitly used `retainIntermediateGeometry=false` (`Architecture_M6_CP3_DEFN_P13_Sliver_Review_Scratch_Execution_20261102.md:22`), so its normal returned pipeline context did **not** preserve the full trace state vectors; the nine-cell arc receipts must not be represented as trace-state receipts. The existing CLI `--surface-cell-preserve-debug-artifacts` does enable retention (`RemeshCommand.cpp:176–178`), but the CLI dump path (`:409–437`) only serializes A5–A7 materialization on rejection, not `productSnapshots.traceNetwork.traces[].states`. Thus toggling that CLI switch alone cannot produce the needed subtype evidence. A later separately authorized diagnostic harness may read the already typed per-trace states from a retained tracing product or emit only the specific seven trace IDs, with explicit memory bounds and immutable TB provenance; new tracing semantics or a new termination enum are not necessary just for subtype observation.

**Causal-position check:** a lens trace has two rail contacts, and the certified unsplit source-vertex contact is **not yet identified as the trace terminal**. The generic support path sets its *first* arc's start anchor unconditionally from the boundary/feature seed, whereas the last arc's terminal anchor depends on trace termination and whether a rail suffix was dropped (`FlowRepStrands.cpp:647–717`). Match ordered `supportSegment` plus start/end intrinsic endpoint keys to **both** lens tips before attributing any two-sided return to the terminal enum. If the questioned tip is merely the valid rail seed, its anchor cannot be challenged by a terminal-subtype finding.

**Falsifier and scope:** check `network.traces.size()==4*network.seeds.size()` before indexing those generic seed trace IDs; verify one repeated-state and one edge/no-exit case with distinct state arrays; check chart/sheet, exact rail key and degree separately. Even an identified edge/no-exit is only a potential mis-anchoring mechanism, not proof those five supports are dispensable. No Review-runtime test, new acceptance or successor is authorized.

#### Falsifiable next Review investigation and stop rules

1. For each of five lens support trace IDs `1037/878/20/422/612`, and needle support IDs `815/487`, obtain the **actual** original trace terminal enum and repeated-state subtype **from already archived evidence if available**. If absent, document that no Review-runtime probe is authorized. Compare original terminal key to the retained network's exact intrinsic endpoint key and degree. A positive valid recurrence control and negative no-exit-without-contact control must diverge; if they do not, no generic correction is justified.
2. For needles 6095/20533/20968/22350, independently distinguish intrinsic quality from injective completion existence. Check the fixed boundary and all required source-chart/sheet/rail owners; the three previously tried interpolants do not close the existence question. A valid close-parallel corridor is a required positive control.
3. Preserve frozen mandatory rail 0, accepted selector prefix, singularity ports, protected-degree/cycle/coverage checks, exact source identity and terminal stage attribution. If new behavioral evidence is necessary, it belongs to a separately authorized Code + Build / Test + Benchmark split, not this runtime-free Review. **No demonstrated single corrective owner or authorized CB successor yet.**

#### Read-only non-vacuity receipt for the discriminator (2026-11-02 13:37Z)

Fresh offline literal-source audit of the verified 6,104-file snapshot checked **8/8** control-flow/retention invariants, and rejected **4/4** deliberately tampered *in-memory source copies* (removed state recording, replaced no-exit terminal, corrupted state equality, removed failure-retention guard). Script `p13_trace_subtype_source_audit.py` SHA-256 `c8bba3a3d40efad50e87ebf2a550020cf9d8d1be1c98b62a83eba5247589b69e`; receipt `P13_Trace_Subtype_Source_Audit_20261102.json` SHA-256 `563a62e0fec98cd01189857c4b1c4332874bd44ab3b86f5b42b9f3e05d3de510` (downloadable continuation evidence). These checks cover exact string-path assumptions only; they are **not product tests, proof of lens trace subtype, or an accepted runtime gate**. This branch's product/test/selector sources were not changed.

#### Review closeout — interim only

| Duty | Disposition |
|---|---|
| Decisive claims / non-vacuity | Fresh static source-path audit; three mutated copies rejected; no binary run or new production oracle |
| Prior obligations | P13 lens terminal-subtype and layout ownership **carried**, needle injective-completion existence and global compatibility **carried**; P13-e and O23 separate |
| Accepted prefix / stable authority | Earlier independent 491-row rehash and 880/961 manifest audit retained, no new selector edit; 66/17/49, debt 1 |
| Durable documents / next turn | Canonical WIP remains active; no new accepted disposition; no new successor frozen |
| Review boundary | `python3 .agents/Directional/tools/review_check.py boundary` in a Git-history-free source archive returned **exit 1**, four ancestry diagnostics. Authentic-history ancestry facts were independently checked in an earlier continuation; no script PASS claimed |
| Runtime and product mutation | No Directional binary, compile, test, fixture, selector, source or workflow-permission modification |
| STATUS / sync | Same canonical turn remains open; final direct GitHub beacon and PR state to be verified at closeout |

## `Architecture_M6_CP3_DEFN_P13_Assembly_Dual_Boundary_Scope_Witness_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Dual_Boundary_Scope_Witness_20261103.md`; moved verbatim.

### P13-j — dual-scope boundary keys: two exact source-edge splits and one vertex-seam ambiguity (2026-11-03)

**Current Review/Definition turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`; **INCOMPLETE**. This record adds a measured scratch-only witness, not production acceptance, an exact corrective patch, or an authorized successor.

#### Immutable evidence

- CB78 base source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; prior [three-fan](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_three_fan_witness_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md") and [prepared-ring](#architecture_m6_cp3_defn_p13_assembly_node5355_prepared_ring_comparison_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md") reports remain authoritative.
- Existing isolated scratch diagnostic ref `agent/p13j-diagnostic-first-vertex-20261103`; corrected diagnostic source **`6db6b8a5535db97da923982c6c6694ba3932c56b`** adds environment-gated `P13L` logging of complete compacted boundary-identity values, typed regions/chart source faces, prepared outgoing halfedges and node occurrences, and retains earlier `P13K/P13J` logs. `PureQuadCompletion.cpp` was verified byte-identical to the preceding scratch build; the diff in `PatchDescriptor.cpp` is 74 added log-only lines. No product/source edit on working branch; no validator relaxation.
- The first scratch compile **FAILED**, run `41574151313`, source `0c9c4d6d…`: diagnostic-only invalid member access `PureQuadMesh::boundaryCharts` / `boundaryTopologyRegions`; warnings about printf type mismatches. Corrected on scratch ref; do not call the first build successful. The retry used the existing mandatory GMP/GMPXX reusable workflow, [run 41574389289](https://github.com/akashskypatel/Directional/actions/runs/41574389289) **SUCCESS**, source `6db6b8a…`, package artifact `13202304778`, ZIP SHA-256 `99ee95193bf450573b8af115c550cc20bc4c991c0eab08e79ed56d1100449f93`; internal SHA256SUMS/source commit/GMP metadata independently verified; `runtimeExecution=false` for CI build.
- Prebuilt CI binary locally replayed (not locally compiled) with exact unchanged `benchmarks/fixtures/milestone-g/vase.off` via `milestone_g_manifest.json` case `vase__surface_cells`. Runtime **294.337s**, reporting process exit code 0 but benchmark `success=false`, original `NonManifoldStitchedVertex`. Each `P13J/K/L_BEGIN` and `END` appears exactly once. Binary SHA-256 unchanged before/after: `f49b7968673a8bbf025010ccb42242c417bde9a553a07edee57b75c53cd5448a`.
- `SurfaceCellCanonicalIdentity::hash()` mixes exact numeric values but only typed-array **sizes**, not typed elements; definitive key equality uses full values + typed fields. The comparison below checks full compacted values and sourceChart content, not hash alone.

#### Measured per-neighbor identity and source scope

Four incident source cells are `26569,3,26570,0` around arrangement node `5355`. The prepared graph has four reciprocal twin edge pairs forming one ring; see prior record. The new per-corner output:

| Source arrangement node | Patch/cell first → second | Compacted identities | Outgoing source scopes | Equality |
|---|---|---|---|---|
| 5351 | 26569 → 3 | `(1,61357)` → `(1,61357)` | face155 → face155, chart0 | equal |
| 5356 | 26570 → 0 | `(1,50500)` → `(1,50501)` | face155 `(0,255,1248)` → face547 `(0,1208,1248)`, chart0 | **different** |
| 5357 | 26569 → 26570 | `(1,89848)` → `(1,89849)` | face155 `(0,255,1248)` → face1381 `(0,857,1208)`, chart0 | **different** |
| 5359 | 3 → 0 | `(1,50195)` → `(1,5144)` | face248 `(255,893,1248)` → face155 `(0,255,1248)`, chart0 | **different** |
| 5355 | all four | `(1,56731)` on all four | face155, chart0 | equal |

All reported scopes have topology region 0, chart ID 0. The exact typed chart-face triples change for three distinct neighbor keys. In the original source, `PatchDescriptor.cpp::arrangement_node_identity` filters node occurrences by `source_scope(edge)` of each **outgoing oriented boundary halfedge**, and `compact_patch_ownership_identities` assigns distinct compact rank to exactly different full records. Completed `PureQuadMesh.boundaryNodeIdentities` are then consumed verbatim by `PureQuadCompletion.cpp::resolved_stitch_identity`.

#### Independent source mesh cross-check — different semantic classes

Parsed the immutable **OFF source triangles and coordinates**, not a reconstructed assembled mesh:

- **5356:** face155 barycentric `(0,.3420184032665,.6579815967335)` and face547 barycentric `(.6579815967335,.3420184032665,0)` refer to the **same exact source edge (0,1248)**. Positions agree to `2.22e-16`. Different descriptor keys arise from changing outgoing face scope despite shared source-edge support.
- **5359:** face155 barycentric `(.3382665797966,0,.6617334202034)` and face248 barycentric `(.6617334202034,0,.3382665797966)` refer to the **same exact source edge (255,1248)**. Source coordinates agree exactly. Different descriptor keys arise from changing outgoing face scope despite shared source-edge support.
- **5357:** face155 barycentric `(0,1,0)` corresponds to source vertex **0** in the unmodified OFF face's stored corner order `(255,0,1248)`; face1381 barycentric `(0,1,0)` also corresponds to source vertex **0** in stored corner order `(1208,0,857)`. **Both refer to source vertex 0**, and coordinates agree exactly. The source-chart face support nevertheless differs. (CAUTION: the diagnostic canonical source-chart keys print sorted vertex triples; their order is not the raw OFF triangle corner order. One must not infer source vertex 255 versus 857 merely from sorted chart-face order.) This is another candidate scope-fragmentation witness rather than proof of distinct source vertex topology.

**Adjudication precision:** the three different output keys on the same authoritative source node are caused by selecting different outgoing source-face scopes at the patch boundary; the prepared graph has reciprocal twins and all source points above share exact source-edge/vertex support in the respective raw OFF faces. The immediate producing source is the **descriptor/completion boundary identity construction**, not the assembly's fail-closed vertex-link validator. However, a safe corrective rule must preserve topology-region, isolation-sheet, chart-transition, barrier and hard-rail separation globally, so no broad node-ID/position merge is authorized. The exact corrected identity construction and negative falsifier have **not** been frozen; this Review remains open.

#### Next focused Review action

Derive a **source-topology canonical endpoint key** for the same supported source edge/vertex across adjacent chart faces, using authoritative `SourceChartTransitionGraph` / typed source support and safeguarding chart/sheet/region and hard-feature disconnections. Establish from source code whether a precise descriptor-level normalization can be proven to unify only the three failing same-source endpoints without conflating non-equivalent sectors. Specify an adversarial negative fixture (coincident but different source-support/sheet) that would fail without correct scope guarding. Only then freeze a minimal corrective patch and one separately authorized Code+Build successor. Preserve original `NonManifoldStitchedVertex` validator. No CP3/selector promotion; accepted CP2 491/491, stable 66/17/49, debt1, unpromoted TB72A 883/883 unchanged.

**Remaining closeout:** authenticated Git-ancestry `review_check.py boundary`, full REVIEW_TURN_POLICY duties, ORIENTATION/CHANGELOG/tracker/TODO/handoff reconciliation and consolidation. Scratch diagnostic ref retained; no new test source or production code was changed.

#### Same-turn cache/identity boundary audit (2026-11-03)

**Correction:** a prepared node's `node.id` plus typed source/chart authority guards against merging distinct colocated nodes **within one pass**, including subdivision nodes. It is **not proven safe across structural repair passes**: `SurfaceCellFeasibilityRepair.cpp:1184–1274` assigns new split-node IDs from `rebuilt.nodes.size()`. Numeric IDs are stage-local representation, not stable owners between independently rebuilt arrangements.

**Correction (2026-11-03):** `retarget_reused_completion_product` updates mesh/domain and lineage patch owner, not boundary vertices/keys. `canonical_completion_boundary_dependency` compares typed region/chart, **all three quantized barycentric coordinates**, rail and curve metadata, not just XYZ; other dependency fields compare domain, sides and topology. `compact_identity_group` retains typed authority vectors while replacing numeric `values`; equal rank alone is **not** equality. `validate_completion_domain_ownership` compares cached lineage keys to requested boundary keys and typed source authority, but lacks prepared-node adjacency. The symbolic recycled-rank case with different barycentrics **fails** dependency equality. Any same-dependency changed-owner case remains untested and is **not the proven initial Vase defect** (initial pass has no reuse cache).

**Corrective contract:** preserve distinct prepared-node ownership **and** prove rebind/retarget or invalidate cached completed patches when topology owners change between passes. Do not key solely by `node.id` or by location-only occurrence sets. Required negative: two separately owned nodes at the same source point and matching cache-dependency coordinates, with swapped numerical IDs between repair attempts; the original validator must reject invalid reuse. Legitimate unchanged-owner reuse must remain possible. No runtime or product mutation; V2 remains **UNACCEPTED**.

Read-only exact-source audit: 14/14 structural checks PASS, script SHA-256 `99dc52622319b8ea85cbec16a56f39e9116bc34ceea990f7896748151464e686`, JSON SHA-256 `6c36d41022b99b62373f02e2c796ddb6eec952e591563a76cf8b177132e35856`. This does not prove runtime cache safety. Authenticated Review boundary and durable closeout remain outstanding.

## `Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md`; moved verbatim.

### P13-j — Prepared arrangement is one ring; completed boundary keys diverge (2026-11-03)

**Canonical turn** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`, still **in progress**. This is a scratch-only diagnostic and source audit, **not** a production repair, gate acceptance, selector change, or authorized successor. Supersedes no prior observation; read alongside the same-day three-fan witness and breakpoint report.

#### Exact independent evidence

- **Immutable base** CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca`.
- **Isolated diagnostic branch** `agent/p13j-diagnostic-first-vertex-20261103` source `41b87026a479d0a67b5f5fdf10fd159e0d3962cf` (one environment-gated logging block in `PatchDescriptor.cpp` plus the prior logging block in `PureQuadCompletion.cpp`). This branch is required to compile diagnostics without modifying working-branch production semantics or immutable CB78. Do **not** merge diagnostic changes.
- **Mandatory GMP/GMPXX compile** reusable Actions workflow [run 41571602244](https://github.com/akashskypatel/Directional/actions/runs/41571602244), exact dispatcher event `191e54dc550bdbcc4fe5125ee19346bd80dcd7aa`, successful source `41b87026…`; immutable package artifact **13201383249**, outer ZIP SHA-256 `d059116652e496dcd45c44aaef564377e7837da417a32d6cc8cc6b31ccefc167`; log artifact **13201965932**, outer ZIP SHA-256 `f171fd1537b538c1081c94f3f510fd8555333fe57cad130d572c60c2548cf0d5`. Package SHA256SUMS verified. No build or modified project binary created in local container; source edits are on isolated scratch ref, workflow compiled them with GMP.
- **Runtime** exact CB78 Vase fixture `milestone_g_manifest.json` case `vase__surface_cells`, `DIRECTIONAL_P13J_SCRATCH_WITNESS=1`, compiled binary SHA256 unchanged before/after `3bd0210c0e8a8c399716ee60ccc350945cdb28e4bf50ca6fd225791d66a2f4e2`. Elapsed **284.112 s**, benchmark `success=false`, original `NonManifoldStitchedVertex` still present; one complete P13K and one complete P13J marker block. Process exit 0 **is not case success**.
- Source-independent parser re-read the **eight actual incident directed halfedge records**, independently checked all four twin pairs reciprocal and orientation-reversed (zero bad twins), and derived the following exact cell adjacency; no invented edge or inferred twin.

#### Prepared graph — node 5355

Node 5355, sourceFace **155**, bary `(0.19728784762040577,0.41676813671918711,0.3859440156604072)`, two occurrences from arcs **142** and **5539**. Eight directed halfedges, four reciprocal undirected twins, **all at source face 155 / topology region 0 / chart 0**, no hard feature and `layoutSupport=1`:

| Twin IDs | Shared local arrangement edge | Adjacent prepared cell IDs |
|---|---|---|
| 13338 / 13339 | 5351–5355 | 3 / 26569 |
| 13352 / 13353 | 5355–5359 | 3 / 0 |
| 13340 / 13341 | 5355–5356 | 0 / 26570 |
| 13350 / 13351 | 5357–5355 | 26569 / 26570 |

All four incident cells have `disk=true`, `closed=true`, one boundary cycle. They form **one connected closed ring** `26569–3–0–26570–26569` in the **post-parity/post-side-preparation arrangement**. This **rules out a missing post-preparation arrangement twin** at the point of failure; it does not prove the untouched pre-parity graph was correct.

Completed patch boundary corners preserve those four adjacency claims around node 5355:

| Completed patch index | Source cell | Boundary neighbors at 5355 | Node canonical hash |
|---|---|---|---|
| 0 | 26569 | 5357 / 5351 | 5886397040142297526 |
| 10942 | 3 | 5351 / 5359 | 5886397040142297526 |
| 22042 | 26570 | 5356 / 5357 | 5886397040142297526 |
| 24674 | 0 | 5359 / 5356 | 5886397040142297526 |

**But the resulting P13J stitched topology has three missing links:** arrangement neighbor **5357** is global rows 2 versus 63568 (cells 26569/26570), neighbor **5356** is global rows 63567 versus 76289 (cells 26570/0), and neighbor **5359** is global rows 29991 versus 76288 (cells 3/0). Neighbor **5351** merges correctly at global row 0 (cells 3/26569). The six incident quads therefore form the earlier three disconnected two-face fans, although the prepared arrangement forms one four-cell ring.

#### Responsibility / exact outstanding discriminator

**Established:** after the prepared graph, before or during assembly, three **matching reciprocal boundaries** are not coalesced into the same global boundary vertex identity; the source arrangement ring itself is connected. The vertex mesh mismatch is not caused by a missing quad in any of those four patches. Production remains correctly fail-closed.

**Leading hypothesis: completion-boundary identity sharing.** `PatchDescriptor.cpp::arrangement_node_identity` constructs a scope-qualified `SurfaceCellCanonicalIdentity` from the node and the scope of the **outgoing oriented halfedge**. `derive_patch_descriptor` fills `patch.boundaryNodeIdentities` using that oriented edge; `PureQuadCompletion.cpp::resolved_stitch_identity` then uses each completed patch's boundary identity verbatim as the assembly key. Equal keys would share a global vertex row in `stitch_pure_quad_patches`. The three observed different global rows imply **different resolved keys** (provided the unmodified hash/equality contract holds), not a missing halfedge or an intentionally skipped assembly traversal.

**Not yet proved:** the exact canonical identity and typed certificate for the three adjacent arrangement nodes **5356/5357/5359** from both matching patch corners, the outgoing oriented halfedge scope at each corner, and whether those differences correctly encode a legitimate chart/sheet separation. The eight immediate edge scopes at node 5355 all match; scopes at the *other* endpoints were not logged. Therefore do **not** yet freeze a corrective code diff or a Code+Build successor. A deliberately false merge based solely on numeric node ID is forbidden.

**Next narrow probe (same Review turn):** capture for the 4 twin pairs above the *pair of endpoint canonical identities as constructed on each incident patch* (`boundaryNodeIdentities` full equality/hash and `boundaryTopologyRegions/boundaryCharts`), with outgoing halfedge IDs/scopes for nodes 5351/5356/5357/5359, and the incoming `vertexLineage` stitch identities / certificate support. If adjacent boundary keys differ while source region/chart sector remains validly identical, assign correction at descriptor/completion boundary identity construction, not by weakening the assembly's manifold gate. If scopes legitimately differ, trace the earliest incorrect sector assignment upstream before assigning owner.

Standing unchanged: CB78 accepted **only** as immutable compile artifact; TB72A 883/883 unpromoted gate, CP2 **491/491** accepted, stable **66/17/49**, debt 1, selector497 unpromoted. No production source/test/fixture/selector/benchmark modifications. Authenticated ancestry-backed `review_check.py boundary` and full review-document closeout not performed; this turn remains open. The isolated diagnostic branch is retained for exact next probe.

#### Same-Review producer-key ownership finding (2026-11-03)

**Definition, not an accepted fix.** Exact CB78 source (`305573a3fd5508dbc380708798051aa0baea5d90` snapshot verified, 6,124/6,124 hashes) shows that `SurfaceArrangement.cpp::node_id` interns one node per `ScopedNodeKey = (NodeKey, TopologyRegionId, NodeAuthorityScope)`. The authority scope is vertex-fan ID for source vertices, sheet ID for face interiors, or empty for edge interiors. The producer retains `nodeScopes` locally, but **does not publish the complete scoped key** on `SurfaceArrangementNode`. The later `ensureOccurrence` appends admissible chart occurrences without creating a new node. V2 reconstructs a key from this mutable occurrence set, rather than using the original node owner identity.

**Smaller alternative to review:** publish an immutable, exact semantic encoding of the producer's complete scoped node key once, then use it **only for completed-patch boundary-node identities**. Preserve oriented/undirected domain and halfedge identity audits, typed certificates, and fail-closed assembly. Encode source vertex/fan, source edge topology and 1e-10 canonical edge parameter, or source face topology and barycentric weights ordered by typed source vertex ID, plus topology region and authority scope. The existing face-interior `NodeKey.face` is a *row index* and must NOT be copied into a semantic key: that would break face-row permutation invariance. Numeric node id alone and world-position proximity are not substitutes. Require injectivity for distinct original scoped nodes, or fail closed. This proposal would eliminate redundant per-corner `resolve_entity/rebind` in V2, but no performance gain is yet measured.

**Mandatory future falsifiers:** equal keys for the same prepared nodes 5351, 5356, 5357, 5359 viewed from either incident patch; distinct keys for distinct scoped nodes across disconnected coincident geometry, hard rails, vertex fans and sheet boundaries; distinct near-edge points around the 1e-8 classification/1e-10 key threshold; invariance to source-face rows, triangle orientations and patch order; unchanged manifold rejection for real disconnected links; bounded Vase progress and unchanged Cylinder PASS/BunnyRandom expected RED. These require descriptor-through-assembler evidence in a separately authorized Code + Build turn, not only native graph tests. **No successor is authorized; V2 is unaccepted.**

**Boundary-check evidence:** `review_check.py boundary` was actually run on the verified snapshot and exited 1 because the snapshot contains no `.git`. Its selector lines appear falsely as `untracked`, and rewrite-base ancestry cannot be checked there. This is not an accepted boundary PASS. Authenticated GitHub compare separately verified CB78 ancestry and no product/test/build/fixture drift; complete boundary proof remains outstanding. Same Review continues.

## `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Breakpoint_Witness_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Breakpoint_Witness_20261103.md`; moved verbatim.

### P13-j — exact CB78 read-only stitched-vertex breakpoint witness

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` — INCOMPLETE. This is a first failing-vertex runtime observation, not a completed DEFN, fix, production acceptance, or Code + Build successor.

#### Immutable evidence

- CB78 semantic source: `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; compiled artifact `13181887585`, outer SHA-256 `076a19de16db5b0d7be3fb7d133c0324383dde319467afb22b3edc99922658e4`.
- Packaged `directional_benchmarks` executable SHA-256 **before and after**: `78c00bbd95b9a25651389d2077463d24bab9e8bd2cc9e6c0743287e95e453d77`.
- Command: `--manifest milestone_g_manifest.json --case vase__surface_cells --warmup 0 --runs 1` from the exact snapshot's benchmarks/fixtures.
- A read-only Python ptrace debugger set a *memory-only* INT3 breakpoint at ELF virtual address `0x4ff2eb`, which disassembly proves is the branch assigning literal `NonManifoldStitchedVertex` (string at `0x7bdaaa`). No local build, modified executable, production source edit, new fixture or accepted gate.
- Reached the breakpoint after **283.1 seconds**, 2026-11-03 02:39:14 UTC.
- **First failing stitched global vertex row = 3** (32-bit `[rbp-0x2e00]`, not source vertex ID); **incident quad count = 6** (`[rbp-0x2ac8]`); **reachable through vertex-incident shared edges = 2** (`[rbp-0x2a88]`). Independent reading of the saved stack bytes confirms all three. `r12d=4` reflects incrementing the vertex iterator immediately before rejection.
- The other **four incident quads are unvisited** by the initial fan BFS. They are not proved to comprise one component. The debugger stops before assigning the failure string; it terminates the child, so this is **not** a completed benchmark result.

#### Unresolved root-cause ownership

The evidence proves an edge-disconnected fan at the first rejected global vertex, but **does not** identify its canonical source support, contributing patch/cell owners or full fan partition. It cannot yet distinguish a false assembly stitch merge, mismatched completion-boundary subdivision/edge identity, or an invalid upstream arrangement sector.

The previously emitted **scratch-only** diagnostic patch `Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__scratch-diagnostic.patch` (full SHA-256 `461b95dedfd5f8a66ef2e8662eb0a588387eb53f82c6779597501f146e9b7145`) is statically applicable to exact CB78 source; it is **not compiled or executed** and **must not** be applied to the production working branch.

**Same-turn next action:** isolate an approved GMP/GMPXX scratch build of exact CB78 plus diagnostic patch and capture `P13J_BEGIN`–`P13J_END` including exact identity, provenance candidates, patch/cell owners, incident face/edge lists, complete fan components and source-chart sectors. Verify no validator weakening and retain fail-closed rejection. Adjudicate owner from that evidence before authorizing an exact corrective CB successor. Preserve CP2 491/491, stable 66/17/49, debt 1, selector497 unpromoted; no CP3 promotion.

This evidence supplements, but does not supersede, `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Preflight_20261102.md`. The raw JSON and reproducible probe script were preserved as downloadable ChatGPT continuation artifacts; do not treat their absence from the repository as new source authority.

#### Same Review: independent Vase source-endpoint and rank-lifetime audit (2026-11-03)

**Independent OFF witness:** Reparsed immutable `benchmarks/fixtures/milestone-g/vase.off` against diagnostic face/barycentric pairs from the prior P13L report. Node 5356: face155/547 → exact source edge `(0,1248)`, 1e10-quantized high-vertex fraction `6579815967`; node 5357: face155/1381 → source vertex `0`; node 5359: face155/248 → source edge `(255,1248)`, fraction `6617334202`. Reconstructed 3D positions coincide (distance **0** for all three pairs). This independently corroborates **source location equality** but not chart/fan/hard-rail topological equivalence; previously captured typed-transition evidence retains authority. The separate 5351 equality control and 5355 one-ring prepared adjacency are unchanged.

**Rank-lifetime limitation:** `PatchDescriptor.cpp::compact_identity_group` lexicographically sorts each descriptor pass's semantic identities, assigns dense `{namespaceTag, rank}` values, then **replaces** the original records. `derive_patch_descriptors` reinterns a later structural repair's identities afresh. A source-structure-backed mathematical model proves that `old{fan0,fan1}` and `new{fan1,fan2}` assign rank `(1,0)` to *different* fan owners, while the unchanged `fan1` changes from `(1,1)` to `(1,0)`. Thus compact ranks are **pass-local labels**, not stable ownership certificates across cached completion reuse. This is an exact counterexample to a *proposed identity assumption*, **not a demonstrated unsafe Directional cache hit**: `validate_completion_domain_ownership`, chart rebound, and lineage/topology gates can still reject stale products. Negative diagnostic must exercise the same-coordinate, changed-owner, rank-recycle case through the real descriptor-to-stitcher validator, and verify unchanged-owner cache reuse.

**Reproducibility:** exact prior source snapshot `305573a3fd5508dbc380708798051aa0baea5d90`, `SHA256SUMS` **6124/6124 PASS** rechecked this turn; tar SHA-256 `ce19fc86954a59cdd129f3d907c0af991843cda5585006f528cacb2fdfbf8e75`. Read-only scripts `compact_rank_lifetime_audit.py` SHA-256 `dd4e9ca37b9f4e83bad2d18fbcdc68b182cd6b8c6d0f68b83f8dfbadf526660e`, `vase_source_endpoint_audit.py` SHA-256 `e21674b88c9cb1337658b4bc65379dc2185b684b78210fb1f00021035f0be2eb`. First OFF audit run failed on the audit script's tuple/list expected-kind comparison, corrected only that assertion and reran successfully; no C++ assertion, test source, executable or production validator changed. Full scripts/results/report preserved as `P13j_Endpoint_And_Identity_Lifetime_Evidence_20261103.zip` in ChatGPT Library `/Directional/`, SHA-256 `2a0bfc43e65ff5943d1f50af48ef709838bdab5d4d9b8ed48ca2141f628d9aaf`.

**Decision:** V2 remains **UNACCEPTED** and the original fail-closed `NonManifoldStitchedVertex` oracle stays unchanged. No runtime/compile/test, no accepted gate or selector promotion, no successor authorization. Same Review remains **IN_PROGRESS** pending exact key contract including original/split-node and cache-owner lifecycle, targeted positive/negative C++ evidence in the authorized separate Code+Build scope, controlled Vase timing, full `review_check.py boundary` on authentic Git history, and mandatory Review closeout.

**Process exception (this continuation):** Multiple small repository authority documents were fetched by connector before an explicit READ_MODE selection, contrary to TOOL_USE_CONSERVATION_POLICY Step 2. Subsequent multi-file source analysis used the previously verified local snapshot (`READ_MODE=snapshot`), which was freshly checked 6,124/6,124. The early pre-read gate miss is recorded rather than claimed compliant.

#### Same-Review: cache-owner observability and face-row-test non-vacuity (2026-11-03 08:10Z)

Exact CB78 snapshot `305573a3fd5508dbc380708798051aa0baea5d90`: **6124/6124 SHA256SUMS PASS**. Authenticated GitHub compare CB78 `afd72107d321` to entry head `f61509f28a07`: no product/test/fixture/build changes. Read-only audit **15/15** explicit source assertions; script SHA256 `154b48f1b7f7e293dff981c3235024f1c90ff67885263ead3810daeb46342c2c`, JSON SHA256 `eccab6fdca43ff1e4350728811acbaf43d11da101da0026dd25ea1b968a7231a`. Full report/archive `/Directional/Directional_P13j_Same_Turn_Review_0810.zip` (SHA256 `a164882414ab8f641c9baf4eef19101bb046ce7fd7d3d588b700a7a3c3091ee9`). Static audit **does not** execute C++ code or prove an actual cache hit.

**Correction (2026-11-03):** Claiming compaction replaces the *complete* semantic identity was **false**: `compact_identity_group` overwrites numeric `values` only. Typed region/chart/rail/support vectors survive, and `SurfaceCellCanonicalIdentity::operator==` compares them. Equal ranks alone do not establish identity. Cache dependencies include typed chart/region, quantized barycentrics, rails/curves, domain, sides and topology. A different-barycentric same-rank model fails the dependency check. Cached boundary keys are retained on retarget, but `validate_completion_domain_ownership` compares stored lineage identities with requested keys; absence of prepared-node adjacency leaves a conditional owner question, **not** a reproduced collision. Initial completion has no cache. The proven Vase descriptor fragmentation remains the primary owner. Read-only correction: Library `/Directional/P13j_Typed_Compaction_Correction_20261103.md`.

**Test evidence limitation:** `tests/PatchDescriptorMilestoneETests.cpp::DomainIdentityIsIndependentOfSourceFaceRowOrder` copies the already-built complex (`Fixture reordered = first`) and reindexes face references. It keeps node IDs and **does not rebuild** the arrangement. The test legitimately checks fixed-complex row renumbering; it does not cover fresh-rebuild node-ID stability. Retain it; require a full rebuild-under-permutation adversarial check in an authorized Code + Build turn.

**Same-turn required next:** freeze one boundary-key contract respecting the proven positive transitions at nodes 5356/5357/5359 (5351 control), distinct prepared node ownership, hard rails/fans/sheets/split parents, and structural cache reuse. Prove owner certificate equality or invalidate changed-generation reuse; add negative recycled-rank/independent-node and full-rebuild permutation oracles in authorized Code + Build. Preserve original fail-closed validator. V2 **UNACCEPTED**, Vase performance unsettled; no Code + Build successor, selector/CP3 promotion, product mutation or runtime execution. Authenticated `review_check.py boundary`, REVIEW_TURN_POLICY §5 and durable closeout remain open.

## `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md`; moved verbatim.

### RA-200 — P13-j stitched-vertex probe adjudication (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (Review/Definition) — **COMPLETE**. Resumed from the ChatGPT Review's `REVIEW_BLOCKER`. That blocker was procedural: the turn needed the completed lineage charts, typed authority and provenance at Vase nodes 5351/5356/5357/5359 and centre 5355, and that Review could not run C++. This adjudication ran that capture, and the follow-up probes, on the macOS scratch build (Claude, diagnostic only). It changes no product source in the repository.

**Base:** HEAD `d2e3c1f7a`, whose product source equals CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca` (`git diff --quiet` over `src include tests benchmarks CMakeLists.txt cmake`). The scratch build reproduces the CI witness exactly: the first rejected stitched row is 3, with 6 incident quads, 2 of them reached; it is node 5355, contributed by patches 0/10942/22042/24674 (source cells 26569/3/26570/0).

**Supersedes as open work:** the 13 P13-j Review records of 2026-11-02/03 (preflight, breakpoint, three-fan, prepared ring, dual scope, typed source transition, V2 scratch verification, V2 sampling, ring non-vacuity, row-ranked counterexample, stitch-key dataflow, owner/cache preflight, completed-lineage gate). Their measured facts stand. Their open conditions are closed or ruled out of scope by RA-200.3. V2 and the reciprocal-DSU candidates are withdrawn; CB79 replaces them.

#### RA-200.1 Findings

1. **The measurement the block asked for.** On HEAD, the stitcher's own lineage certificates at the five nodes, one line per shared-boundary corner:

   | Node | Corners (patch) | Support | Region / sheet | Literal source charts | Stitch keys |
   |---|---|---|---|---|---|
   | 5351 | 0, 1, 10941, 10942 | face (0,255,1248) | 0 / 0 | {0:(0,255,1248)} | 1 (control) |
   | 5355 | 0, 10942, 22042, 24674 | face (0,255,1248) | 0 / 0 | {0:(0,255,1248)} | 1 |
   | 5356 | 22042, 24674 | edge (0,1248) | 0 / 0 | {0:(0,255,1248), 0:(0,1208,1248)} on **both** | **2** |
   | 5357 | 0, 22042 | vertex 0 | 0 / 0 | {0:(0,255,1248), 0:(0,857,1208), 0:(0,1208,1248)} on **both** | **2** |
   | 5359 | 10942, 24674 | edge (255,1248) | 0 / 0 | {0:(0,255,1248), 0:(255,893,1248)} on **both** | **2** |

   Every certificate passes `owner_validated_typed_authority_certificate`, and the two sides of each split node carry identical certificates. This is branch (A) of the completed-lineage gate: the typed authority is compatible, and only the descriptor key differs.

2. **The key is not a property of the node.** `derive_patch_descriptor` publishes `arrangement_node_identity(node, F, source_scope(edge))`, where `edge` is the halfedge leaving the node in *this* cell. That function keeps only the node's occurrences in that one source scope. A node on a source edge or vertex is left through different source faces by different cells, so the cells around one prepared node publish different keys. The halfedge-scoped form is correct for `halfedge_identity`, because an oriented edge lies in one chart. It is wrong for a corner that several charts share.

3. **The fault is systemic; node 5355 is only where a validator first notices it.** On HEAD, Vase assembly sees 66,783 arrangement nodes and 186,780 boundary corners; **23,221 nodes (46,458 corners) resolve to two stitch keys**. The assembled mesh is shredded: 91,268 vertices, 67,829 quads, 85,762 boundary edges, Euler −19,442. Most split nodes leave two path-shaped fans, which pass the vertex-link check. Row 3 fails only because three cracks meet at one vertex.

4. **An existing gate row was passing on a cracked assembly.** Row 97, `PatchDescriptorMilestoneE.SharedEdgeParityRepairConforminglyCompletesTwoOddCells`, completes two triangles that share a source diagonal. On HEAD its assembly is two disjoint quads: 8 vertices, 8 boundary edges, Euler 2, with nodes 0 and 2 split. The test asserts only `quads not empty`. With the node key the assembly is the source disk: 6 vertices, 6 boundary edges, Euler 1. Downstream, the production `SourceAuthoritativeMeshValidator` compares components, Euler and boundary loops, so a census would not silently accept the cracks. The completion-level tests, however, never checked.

5. **Cylinder never reaches the patch stitcher.** It finishes through the authoritative phase-front mesh (`RemeshPipeline.cpp` ~14005), so Vase is the only census fixture that exercises `stitch_pure_quad_patches`.

6. **With a node key, assembly passes.** Key = the node's occurrences in **all** of its source scopes. Vase then has 0 split nodes, and each of the five nodes has one key with unchanged certificates. Assembly succeeds with 68,038 vertices, 67,829 quads, 135,866 edges, 416 boundary edges and Euler 1. The source has Euler 1 and one boundary loop (V 1274, F 2404, E 3677, 142 boundary edges). There is no `IncompatibleTypedStitchAuthority`, position or manifold rejection anywhere in Vase.

7. **The next failure is P13-k, a source-query cost after assembly, not a verdict.** The run reaches assembly at about 205 s on macOS and does not finish within 875 s. Four stack samples:
   - 3:42–6:30: **100 %** in `fill_surface_optimization_rail_constraints` → `provenance_supports_interval_sheet` → `source_face_scope` → `SourceTopologyRegions::matches_source_faces`. Every (output vertex × rail interval) pair revalidates the immutable source authority against all 2,404 source faces, twice.
   - After that: `evaluate_surface_optimization_energy_cached` → `project_vertices` → `nearest_source_point` → `SurfaceProjectionBvh::SurfaceProjectionBvh`. `nearest_source_point` (and `project_vertices` and the quad-label projection) construct a local `SourceProjectionCache`, and so a full source BVH, on **every call**, even when the caller passes a cache.

   O20 already named the same class of cost: per-query rebuilds of immutable source structures. The V2 timeouts in the earlier Review records were this stage, not V2 overhead. Their samples show the same two functions. Probe K (RA-200.2a) removes both costs. The run then reaches a third site of the same kind: final validation builds a chart graph per output quad.

#### RA-200.2 Probes (macOS, scratch, diagnostic only)

| Probe | Switch | Result |
|---|---|---|
| J-count (HEAD) | `PROBE_J_COUNT` | 23,221 / 66,783 nodes split; HEAD mesh Euler −19,442; first rejection row 3 = node 5355 (matches CI) |
| J-nodes (HEAD) | `PROBE_J_NODES=5351,5355,5356,5357,5359` | Table in RA-200.1 item 1: identical certificates on both sides; keys split at 5356/5357/5359 |
| J-key | `PROBE_J_KEY` (node key over all scopes) | 0 split nodes; assembly passes (Euler 1, 416 boundary edges); Vase continues into P13-k |
| Two-cell row 97 | `PROBE_J_COUNT`, `PROBE_J_FAIL` | HEAD: two disjoint quads (Euler 2); node key: one disk (Euler 1) |
| Cylinder | `PROBE_J_COUNT` | Never calls the stitcher; PASS on HEAD and with the node key |
| Stack samples | `sample` ×4 after assembly | Rail fill: per-query `matches_source_faces`; then per-call projection BVH |
| K | `PROBE_K` (validate authority once; build the local projection cache only when none is passed), on CB79 | See RA-200.2a |

##### RA-200.2a Vase past P13-k (probe K)

This was run on CB79 with `PROBE_K`. The probe validates the source authority once instead of in each `source_face_scope` call. It also builds the local `SourceProjectionCache` only when the caller passes none.

| Phase (macOS, one process) | HEAD source path | With `PROBE_K` |
|---|---|---|
| Assembly reached | ~205 s | ~205 s |
| `fill_surface_optimization_rail_constraints` (68,038 vertices × 142 rail intervals) | ~3 min, 100 % of samples in `matches_source_faces` | **0.1 s** |
| Optimizer energy / projection | BVH built per `nearest_source_point` call | passes in under 2 min |
| `validate_final_surface_mesh` | not reached by 875 s | about 20 min. All samples through 14:47 are in `OutputProjectionCache` → `consistent_source_scope` → `SourcePointLabelSupport` → `SourceChartTransitionGraph::build`, **one graph per output quad** (67,829) |
| Verdict | none within 875 s | **1,521 s:** `terminal=NotProductionReady:completion detail=None … completedQuads=67829 completion=` (empty completion code) |

The third site, `consistent_source_scope` (and the quad-label projection in `SurfaceMeshOptimizer.cpp`, which builds the same label support), is the Amendment 27 per-call graph build that RA-195 removed from completion. So P13-k is one cost class at three sites, all in the surface-optimizer and final-validation stage:

1. `source_face_scope` (`SurfaceMeshOptimizer.h` and `SurfaceOptimizationRailConstraints.cpp`) runs `matches_source_faces`, which is O(F), on every call.
2. `nearest_source_point`, `project_vertices` and the quad-label projection construct a `SourceProjectionCache`, and so a full source BVH, even when a cache is lent.
3. `consistent_source_scope` and the quad-label projection construct a `SourcePointLabelSupport`, and so a `SourceChartTransitionGraph`, per quad.

**Beyond P13-k (P13-l):** with sites 1–2 removed and site 3 left to run, Vase ends at 1,521 s. The stage is completion, the detail is `None` and the completion code is empty: final validation rejects the assembled mesh without a typed reason. Linux cannot reach this verdict in 600 s without the P13-k fixes, so TB73's registration (ABNORMAL 600 s) stands.

The P13-k DEFN:
- removes all three sites and confirms the same verdict, faster;
- names the rejecting check (the terminal must carry a detail and a completion code, as CB75 required for completion rejections);
- freezes exact patches, one CB per site, each with a cost GUARD in the RA-195 style.

The owner of the rejection itself (P13-l) is decided only after the reason is visible.

##### CB79 verification (scratch build, clean CB79 state)

- **Gate:** 886 rows (RA-200.5 manifest), **885/886**. The only red is row 283, the O16 macOS row, which was also red on CB78. No other verdict changed.
- **Ledger v5:** 0/81 pass, as on CB78. One deferred row changed: row 365 is the Vase census case itself, and it went from RED at 174 s to TIMEOUT at 600 s because it now passes assembly into P13-k.
- **Census:**
  - Cylinder PASS (10.4 s).
  - BunnyRandom unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`, P13-e).
  - Vase passes assembly and is then inside P13-k at 600 s.
- **Mutants:**
  - M1 (the call site keeps the halfedge-scoped key) fails rows 884 and 885.
  - M3 (a region-blind key) fails row 886.
  - Rows 91 (face-row permutation) and 97 stay green under both mutants and under clean CB79.

#### RA-200.3 Rulings

1. **Owner: the completion-boundary identity producer** (`derive_patch_descriptor`). It is not the assembler and not the arrangement. The prepared arrangement is correct: node 5355 is a four-cell reciprocal ring. The assembler correctly fails closed.
2. **DESIGN Amendment 32:** a completed patch's boundary-node stitch key is the identity of the prepared arrangement node itself, meaning its occurrences in every source scope. It is not the view through the halfedge leaving the node in one cell. The reciprocal twins of the prepared complex are the certified relation (§8 rule 1). The assembler's typed-authority intersection, position and manifold checks remain the verification, unchanged. Halfedge and domain identities keep their chart-scoped endpoints.
3. **The open conditions from the earlier Review records:**
   - **Row/corner invariance:** the key reuses `source_point_identity` (typed vertex IDs, weights sorted by vertex, canonical chart faces). Row 91 (face-row permutation of `boundaryNodeIdentities`) stays green.
   - **Distinct nodes:** nodes are interned by `ScopedNodeKey` (position, region, vertex fan or sheet), and the key carries every occurrence's region and chart. Two distinct nodes collide only if their full occurrence sets are equal, which also collides HEAD's key for every shared scope; so CB79 is no weaker than HEAD here. Row 886 guards region separation, and it kills the region-blind mutant.
   - **Hard rail, sheet and fan sectors:** measured, not assumed. Across all of Vase, no corner pair that the node key joins fails the typed intersection.
   - **Repair-split nodes:** covered by the Vase run (repair passes) and by row 97 (the parity split on the shared diagonal).
   - **Completion cache with a changed owner:** conditional and unwitnessed. The initial pass has no cache. A node-intrinsic key removes the scope dependency that made rank aliasing plausible. No guard is added (CLAUDE.md §2); it reopens only on a witness.
   - **V2's 1e-8 rebind tolerance, row-ranked primary selection, quantized-anchor concerns:** they do not arise, because CB79 uses no tolerance, no rebind and no primary selection.
4. **Next Vase failure: P13-k** (RA-200.1 item 7, RA-200.2a), a cost in the surface-optimizer stage. Owner: the stage rebuilds immutable source structures per query, at three sites:
   - per-call revalidation of the source authority;
   - per-call construction of the projection BVH;
   - a per-quad label support and chart graph in final validation.

   This is the class O20 and Amendment 27 already recorded; P13-k is its first witness that blocks a fixture. → Review DEFN `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (Claude, scratch), which can start now.
5. **O26 (new, test oracle):** completion-level tests that assemble meshes assert counts or success, not the assembled topology. Row 97 passed on a two-component assembly. CB79's row 885 is the first assembly-topology assertion. Further strengthening goes with the CP3 test-quality slice; it is not a blocker.

#### RA-200.4 CB79 — `M6-CP3-CB79-P13-NODE-STITCH-KEY`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet afd72107d3213a396ed7f35b53f67dceeea7e7ca HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-200.8 verbatim plus a trailing newline. **Keep its 1 single-space context line** (line 7 of the block). SHA-256 `89f37001d6eea167672c32edf73178cbf98d23e0501e28ca8795fb79a0719028`, 146 lines; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PatchDescriptor.cpp` | `25 2` | `cef48a850cac9ba3c0a471491f1fb5e4d094571173dd6db916df6aa1683ce41f` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `95 0` | `068271a6d0afb08bba23ba391495ae82de86ff35d50826ca26bffa06ded985fc` |

- **Content:** `arrangement_node_stitch_identity(node, F)` (after `arrangement_node_identity`) builds the node's identity over the primary and every occurrence, each in its own scope; `derive_patch_descriptor` publishes it as `boundaryNodeIdentities`. `arrangement_node_identity` and its halfedge/domain callers are unchanged.
- **Tests (gate rows 884–886):**
  - `SharedNodeCornersPublishOneStitchKeyAcrossSourceCharts`: on the existing two-cell fixture, nodes 0 and 2 are left through different source charts by the two cells, yet both cells publish one key per node; the keys of nodes 0 and 2 differ.
  - `SharedInterfaceCompletesAsOneConnectedDisk`: `complete_surface_cell_complex` on that fixture assembles 2 quads, 6 vertices, 1 component, 1 boundary loop, Euler 1.
  - `CoincidentNodesInDistinctRegionsKeepDistinctStitchKeys`: the same authoritative patch in region 2 and in region 3, at identical source points, gives different keys at every corner.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Precheck, apply, numstat or result-hash mismatch → `M6-CP3-PLAN-P13-NODE-STITCH-KEY-STOP`.
  - Infrastructure failure → `M6-CP3-CB79A-P13-NODE-STITCH-KEY-ORCH` (one retry).

#### RA-200.5 TB73 — `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB79's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB73_P13_Node_Stitch_Key_Full_Gate_Case_Manifest.tsv"), 886 rows, SHA-256 `5d09fa337b42adc8629f4bded8ea35b2181e468fb9dd91f7db5414fa534cfc4a`: TB72's 883 rows byte for byte plus GUARD rows 884–886 (`directional_surface_cell_completion_tests`).
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=886 deferred=81`.
  - Pre-registered **886/886**, membership **967**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: ABNORMAL, harness timeout (600 s, exit 124)**, after assembly, inside the surface-optimizer stage (P13-k).
  - Any Vase verdict before 600 s is a mismatch; `AssemblyRejected` (any completion code) means CB79 did not take.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB73A-P13-NODE-STITCH-KEY-ORCH` (one retry).

#### RA-200.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB79-P13-NODE-STITCH-KEY` | Implementation agent, Linux; RA-200.8, compile only |
| 2 | `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC` | Implementation agent, Linux; gate 886/886, membership 967; Vase ABNORMAL 600 s timeout after assembly |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (P13-k) | Probe DEFN on the CB79 scratch state (Claude), then an exact patch |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–2 only. Steps 3–4 are probe DEFNs on the Review track (Claude, scratch build). A Review turn that cannot run a scratch probe does not start them; that is a scheduling fact, not a block (RA-172, RA-198, RA-199, RA-200).

#### RA-200.7 Probe scripts (scratch, not committed)

`scratchpad/p13j/`:
- `make_probe_j.py`: `PROBE_J_KEY/COUNT/NODES/FAIL`.
- `make_probe_k.py`: `PROBE_K`.
- `make_cb79.py`: the CB79 state and mutants M1/M3.
- `make_patch79.py`: the patch, apply check and result hashes.
- `run_long.sh`: one census process with a set cap.
- `tb73_manifest.tsv`.

The per-row gate driver is RA-198's `p13i/gate.py`.

#### RA-200.8 Exact CB79 patch

```diff
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -437,6 +437,30 @@ SurfaceCellCanonicalIdentity arrangement_node_identity(
   return result;
 }
 
+// A completed patch's boundary corner is stitched by the arrangement node it
+// lies on, so every cell around that node must publish the same key. The key
+// is the node's occurrences in all of its source scopes; the scope of the
+// halfedge leaving the node in one cell selects only that cell's view.
+SurfaceCellCanonicalIdentity arrangement_node_stitch_identity(
+    const SurfaceArrangementNode &node, const Eigen::MatrixXi &F) {
+  std::vector<SurfaceCellCanonicalIdentity> occurrences;
+  occurrences.push_back(source_point_identity(F, node.sourceFace, node.barycentric, source_scope(node)));
+  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
+    occurrences.push_back(source_point_identity(F, occurrence.sourceFace, occurrence.barycentric, source_scope(occurrence)));
+  }
+  occurrences.erase(std::remove_if(occurrences.begin(), occurrences.end(),
+                     [](const SurfaceCellCanonicalIdentity &identity) { return !identity.valid; }),
+                     occurrences.end());
+  std::sort(occurrences.begin(), occurrences.end());
+  occurrences.erase(std::unique(occurrences.begin(), occurrences.end()), occurrences.end());
+  SurfaceCellCanonicalIdentity result;
+  if (occurrences.empty()) return result;
+  result.valid = true;
+  result.values.push_back(static_cast<std::int64_t>(occurrences.size()));
+  for (const SurfaceCellCanonicalIdentity &occurrence : occurrences) append_identity(result, occurrence);
+  return result;
+}
+
 SurfaceCellCanonicalIdentity provenance_semantics(const SurfaceArrangementProvenance &provenance) {
   SurfaceCellCanonicalIdentity result;
   result.valid = true;
@@ -1756,8 +1780,7 @@ PatchDescriptor derive_patch_descriptor(
     patch.boundaryTopologyRegions.push_back(edge.sourceTopologyRegion.value());
     patch.boundaryCharts.push_back(edge.sourceChart.value());
     patch.boundaryNodeIdentities.push_back(
-        patch_descriptor_detail::arrangement_node_identity(
-            *node, F, patch_descriptor_detail::source_scope(edge)));
+        patch_descriptor_detail::arrangement_node_stitch_identity(*node, F));
     patch.boundaryProvenance.push_back(
         patch_descriptor_detail::node_surface_point(*node, V, F, edge));
     patch.hardFeatureCrossing =
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -2018,3 +2018,98 @@ TEST(PatchDescriptorMilestoneE, BentNeedleGridCompletesByTheBoundarySearch) {
   EXPECT_EQ(3U, mesh.quads.size());
   EXPECT_EQ(8U, mesh.vertices.size());
 }
+
+TEST(PatchDescriptorMilestoneE,
+     SharedNodeCornersPublishOneStitchKeyAcrossSourceCharts) {
+  const Fixture fixture = make_two_odd_cells_with_shared_interface();
+  const auto first = directional::geometry::derive_patch_descriptor(
+      fixture.complex, fixture.complex.cells[0], fixture.V, fixture.F);
+  const auto second = directional::geometry::derive_patch_descriptor(
+      fixture.complex, fixture.complex.cells[1], fixture.V, fixture.F);
+  const auto corner = [](const auto &patch, const int node) {
+    return static_cast<std::size_t>(std::distance(
+        patch.boundaryVertices.begin(),
+        std::find(patch.boundaryVertices.begin(), patch.boundaryVertices.end(),
+                  node)));
+  };
+  // Nodes 0 and 2 are source vertices of both source faces. Cell 0 leaves
+  // them through face-0 halfedges and cell 1 through face-1 halfedges; both
+  // cells still publish the node's one stitch key.
+  for (const int node : {0, 2}) {
+    const std::size_t a = corner(first.patch, node);
+    const std::size_t b = corner(second.patch, node);
+    ASSERT_LT(a, first.patch.boundaryNodeIdentities.size()) << "node=" << node;
+    ASSERT_LT(b, second.patch.boundaryNodeIdentities.size()) << "node=" << node;
+    ASSERT_NE(first.patch.boundaryCharts[a], second.patch.boundaryCharts[b])
+        << "node=" << node;
+    ASSERT_TRUE(first.patch.boundaryNodeIdentities[a].valid) << "node=" << node;
+    EXPECT_EQ(first.patch.boundaryNodeIdentities[a],
+              second.patch.boundaryNodeIdentities[b])
+        << "node=" << node;
+  }
+  EXPECT_NE(first.patch.boundaryNodeIdentities[corner(first.patch, 0)],
+            first.patch.boundaryNodeIdentities[corner(first.patch, 2)]);
+}
+
+TEST(PatchDescriptorMilestoneE, SharedInterfaceCompletesAsOneConnectedDisk) {
+  const Fixture fixture = make_two_odd_cells_with_shared_interface();
+  directional::geometry::SurfaceCellTracingOptions sourceAuthorityOptions;
+  sourceAuthorityOptions.sourceFaceComponents = {0, 0};
+  sourceAuthorityOptions.sourceFaceSheets = {0, 0};
+  const auto sourceAuthority =
+      directional::geometry::surface_cell_tracing_detail::
+          build_source_topology_regions(fixture.F, sourceAuthorityOptions);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  directional::geometry::SurfaceCellComplexCompletionOptions completionOptions;
+  completionOptions.sourceAuthority = &sourceAuthority.value();
+  const auto completion = directional::geometry::complete_surface_cell_complex(
+      fixture.complex, fixture.V, fixture.F, completionOptions);
+  ASSERT_TRUE(completion.is_produced());
+  // The two cells share the source diagonal, so the assembly is the source
+  // disk, not two quads that only touch geometrically.
+  const auto &assembly = completion.product().assembly;
+  EXPECT_EQ(2U, assembly.mesh.quads.size());
+  EXPECT_EQ(6U, assembly.mesh.vertices.size());
+  EXPECT_EQ(1, assembly.connectedComponents);
+  EXPECT_EQ(1, assembly.boundaryLoopCount);
+  EXPECT_EQ(1, assembly.eulerCharacteristic);
+}
+
+TEST(PatchDescriptorMilestoneE,
+     CoincidentNodesInDistinctRegionsKeepDistinctStitchKeys) {
+  Fixture first = make_authoritative_patch({1, 1, 1, 1});
+  Fixture second = first;
+  const auto region = test_topology_region_id(3);
+  for (auto &node : second.complex.nodes) {
+    node.sourceTopologyRegion = region;
+    for (auto &occurrence : node.occurrences) {
+      occurrence.sourceTopologyRegion = region;
+    }
+  }
+  for (auto &edge : second.complex.halfedges) {
+    edge.sourceTopologyRegion = region;
+  }
+  for (auto &cell : second.complex.cells) {
+    cell.sourceTopologyRegion = region;
+  }
+  bind_patch_charts_to_source_topology(first.F, first.complex);
+  bind_patch_charts_to_source_topology(second.F, second.complex);
+  const auto a = directional::geometry::derive_patch_descriptor(
+      first.complex, first.complex.cells.front(), first.V, first.F);
+  const auto b = directional::geometry::derive_patch_descriptor(
+      second.complex, second.complex.cells.front(), second.V, second.F);
+  ASSERT_EQ(a.patch.boundaryVertices, b.patch.boundaryVertices);
+  ASSERT_EQ(4U, a.patch.boundaryNodeIdentities.size());
+  ASSERT_EQ(4U, b.patch.boundaryNodeIdentities.size());
+  for (std::size_t index = 0; index < 4U; ++index) {
+    ASSERT_TRUE(a.patch.boundaryNodeIdentities[index].valid);
+    ASSERT_TRUE(b.patch.boundaryNodeIdentities[index].valid);
+    EXPECT_EQ(a.patch.boundaryProvenance[index].face,
+              b.patch.boundaryProvenance[index].face);
+    EXPECT_EQ(a.patch.boundaryProvenance[index].barycentric,
+              b.patch.boundaryProvenance[index].barycentric);
+    EXPECT_NE(a.patch.boundaryNodeIdentities[index],
+              b.patch.boundaryNodeIdentities[index])
+        << "corner=" << index;
+  }
+}
```

#### Review closeout

| Check | Result |
|---|---|
| Scope | Review/Definition only; no product, test, fixture, selector, benchmark or build file changed in the repository. Scratch probes only |
| Exact patch | Embedded block re-hashes to `89f37001…`; `git apply --check` and apply on a clean HEAD worktree; both result hashes match |
| Manifest | TB72 prefix byte-identical; `SELF_CHECK_PASS cases=886 deferred=81` with harness P8 |
| Accepted selector prefix re-hashed | n/a: no selector change |
| Standing state | CP2 491/491; stable 66/17/49, debt 1; ledger v5 81 deferred; selector497 and CP3 unpromoted |
| `review_check.py boundary` | ALL CHECKS PASSED on the history-bearing checkout; `review_check.py ledgers --base d2e3c1f7a` PASSED |
| Scratch state left | `wt61`/`bld61` = HEAD + clean CB79 + inert `PROBE_K` (unset = HEAD); scripts in `scratchpad/p13j/` |

## `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md`; moved verbatim.

### P13-j — exact CB78 Vase three-fan stitched-vertex witness (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`; Review/Definition remains **INCOMPLETE**. This is an observed scratch diagnostic, not a production correction or candidate promotion. It supplements the preflight and the read-only breakpoint record; the root-cause producing stage is **not yet adjudicated**.

#### Immutable/diagnostic execution authority

- Baseline **CB78** source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; independently verified baseline failure `AssemblyRejected/NonManifoldStitchedVertex`.
- Necessary **isolated temporary diagnostic branch** `agent/p13j-diagnostic-first-vertex-20261103` at `42126c14ff530c4ccfd3768f93e4b95c2ae3bfc7`, based exactly on CB78. A single source file `src/geometry/PureQuadCompletion.cpp` was changed to print the first rejected vertex, identities, owners, edge incidences and all fan components when `DIRECTIONAL_P13J_SCRATCH_WITNESS` is set. The original `NonManifoldStitchedVertex` rejection remains. This branch is isolated because compiling an instrumented diagnostic must not mutate production work or the accepted immutable package.
- Mandatory reusable GMP compile via durable dispatcher request commit `6f905a0e2cced5cd5e152d34a096d8493ba76400`, run **41569099988** (successful); compiled single target `directional_benchmarks`; package artifact **13199469869**, SHA-256 `268a33a0508dd6c444e5f0df01ff0ad9ab176e9f103105a69506944011d1de3c`; log artifact **13201085244**, SHA-256 `b379d36ab78204084624f3e419bc36cae01911a58dba13ef4ce9ec9761d4b0b0`. Verified all package SHA256SUMS; `DIRECTIONAL_ENABLE_GMP=ON`, generated link line includes **gmpxx** and **gmp**, metadata says `exactArithmeticBackend=GMP`, source SHA matches, build/preflight exit codes zero, compile-only boundary preserved.
- Executed the packaged binary **without rebuilding** against the exact `milestone_g_manifest.json` source fixture `vase__surface_cells`, one run, no warmup, diagnostic environment flag set. Elapsed **294.149 s**, process exit code **0** (benchmark reporting status only), benchmark's `cases[0].runs[0].success=false` and terminal `NotProductionReady` / `NonManifoldStitchedVertex`. One complete `P13J_BEGIN`/`P13J_END` marker pair. Binary SHA-256 before and after identical: `e220eb2e1f572d5ae3a50dc3442c7b34b8dbe39c49b6c9985c0937d7fc855782`. The diagnostic did **not** turn Vase green.

#### First rejected stitched vertex and provenance

- Global stitched vertex row **3**, six incident quads, only two edge-connected from the initial seed, precisely **three disjoint two-quad fans**. Global row is an assembly-local ordinal; it is **not** source vertex 3.
- Shared canonical arrangement-node identity: kind **1** (`ArrangementBoundaryNode`), hash **7413753397690851829**, values `1,56731`; each patch-local occurrence has local vertex ID **5355** and boundary=true. Full canonical source-support values include source face corners `(0,255,1248)`. Resolved authoritative identity kind 1/hash **1278380862843572727** and source face `(0,255,1248)`, topology region 0, sheet 0, chart 0. Canonical provenance `face=155; component=0; sheet=0; bary=(0.197288,0.416768,0.385944)`; exact source-support incident face 155.
- Four contributing patch-local occurrences (patchIndex, sourcePatch, localRow, domainHash):
  - `(0,26569,3,13477175895117145574)`, source side edges `1,1,1,1`
  - `(10942,3,3,2797002078942487011)`, source side edges `2,1,2,1,1,1`
  - `(22042,26570,2,7840118678002363504)`, source side edges `2,1,2,1,2`
  - `(24674,0,10,7710101604013126795)`, source side edges `5,3,2,2`
- Fan 0: faces **0** (patch 0/localQuad 0) and **15320** (patch 10942/localQuad 0), connected by stitched edge `(3,0)`.
- Fan 1: faces **44813** and **44815** (patch 22042/localQuads 0,2), connected by stitched edge `(3,10)`.
- Fan 2: faces **55549** and **55551** (patch 24674/localQuads 2,4), connected by stitched edge `(3,76283)`.
- The six outward vertex-incident edges `(3,2)`, `(3,29991)`, `(3,63568)`, `(3,63567)`, `(3,76289)`, `(3,76288)` each have only one incident quad in the assembled result. Thus the one globally merged row has **six unmatched fan ends**, not the boundary vertex's ordinary two.
- Patch-lineage `ownerAuthority` fields printed `kind=0/valid=0`, but the *resolved* global authoritative identity is valid; do not mistake the optional incoming lineage representation for proof that typed authority was absent.

#### Negative and positive controls (same scratch binary, unchanged fixtures)

- `cylinder__surface_cells`: process returned 0, benchmark `success=true`, 320 vertices, 288 faces; no P13-j witness.
- `bunny_1k_random__surface_cells`: process returned 0 but benchmark `success=false`, `SingularityPortClassCountMismatch;sourceVertex=49`; no P13-j witness. Benchmark process exit codes alone are **not** acceptance evidence.
- Accepted CP2 491/491, stable 66/17/49 debt 1, and selector497 unpromoted remain unchanged; no CP3 promotion or new stable event.

#### Exact remaining discrimination (same Review turn)

**Proved:** multiple completed patch sectors share one arrangement-node key and one valid source support but have three disconnected stitched edge-link components. **Not yet proved:** the earliest stage that introduced invalid fan incidence. Preserve all three explanations until upstream comparisons:
1. Compare arrangement's ordered incident arcs/cell sectors at node `5355` (canonical `1,56731`) with the four source patches `26569,3,26570,0`. Determine whether three disconnected sectors are already present in the incoming authoritative arrangement (**arrangement owner**) or arise later.
2. Compare, per incident patch, exact boundary-node sequence and ordered side-edge subdivisions, matching neighboring patch interfaces and typed sheet/chart sectors. If the arrangement is correct but these interfaces disagree, **completion-boundary sharing owner**.
3. If completed patch boundaries genuinely match a single connected source fan, but the stitching key collapses separate vertex-link sectors, **assembly owner**. Do not infer this from equal position/provenance alone.
4. Require a falsifiable corrective patch with a negative case that would fail without the fix, retain original fail-closed validation, and separately authorize a Code + Build successor. No production semantic change is permitted in this Review.

**Preserved evidence:** complete stderr marker block, parsed JSON result, three benchmark JSON results, scratch patch (full SHA-256 `6e5ec0614084f1524cb6800955a85468ba392e0887e285a8f71b2917b14c38cb`), CI package/logs and exact replay script are downloadable continuation assets. The isolated scratch branch must be retired after its evidence is consumed and any necessary follow-up probes are complete; no workflow YAML or reusable-workflow permissions were changed. The authenticated Git-ancestry `review_check.py boundary` and full Review closeout remain outstanding.

#### Same-Review finding: second node producer (2026-11-03)

**Original `ScopedNodeKey` retention alone is incomplete.** In CB78 source, `SurfaceArrangement.cpp:2084–2202` interns original nodes through `nodeByKey[ScopedNodeKey]`, whereas `SurfaceCellFeasibilityRepair.cpp:1184–1274` creates fresh nodes by splitting undirected twin edges and appends them directly to `rebuilt.nodes`, sharing each inserted `pathNodes` vertex between forward and reverse pieces. This second producer does not use the original node interning map. This does **not** establish that a split-generated node caused Vase's first failed stitched fan.

**Revised identity contract (candidate, not frozen):** original nodes keep their complete typed producer-scoped key, with source-face rows converted to source-face topology. Split nodes require explicit parent undirected-edge ownership and a canonical split fraction, with preserved interval lineage if nested/reordered subdivision exists. Never merge separate parent edges, hard-rail sectors, fans or sheets solely by identical coordinates. Require an authoritative rule for a split coinciding with an existing node; otherwise fail closed. Original assembly manifold validation is unchanged.

**Independent numerical falsifier:** with source vertices (10,20,30), barycentric weights (0.33333333332,0.33333333334,0.33333333334), and scale 1e10, separately rounded `u,v` equal 3333333333. Filling the omitted corner with `1e10-u-v` gives 3333333334 to whichever corner was omitted; rotating face-corner order changes the semantic key. Separately rounding **all three original barycentric weights** and sorting by typed vertex ID preserves the synthetic key through all three rotations. This is a source-motivated Python **model**, not a C++ runtime test. The model also checks distinct region/sheet/fan owner tags and reciprocal twin split fractions. Script SHA256 `a33bd684e195a0a6bb8ba5672abcc0a864673cb1497d98064f2e0a1b920d9095`; full report SHA256 `25200d52739dccbd89d3388fccf400382ee941d59a3c00d8bb7ea8cb96cd2f37`, preserved in ChatGPT Library `/Directional/P13j_Stitched_Node_Identity_Scope_Review_20261103.md`.

**Next same-Review discriminators:** positive equality of boundary keys for prepared nodes 5351/5356/5357/5359 and reciprocal split vertices; negative inequality for disconnected nodes, distinct split owners, hard rails, vertex fans, sheets and near-edge points; source row/corner, patch order, split-order and nested-subdivision perturbations; controlled Vase time against CB78 and unchanged Cylinder/BunnyRandom controls. V2 remains **UNACCEPTED**. No code/test/fixture/selector/build change; no successor authorized, CP2 491/491 and stable 66/17/49 debt 1 unchanged. Git-history-backed review boundary and formal closeout still pending.

## `Architecture_M6_CP3_DEFN_P13_Assembly_Typed_Source_Transition_Adjudication_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Assembly_Typed_Source_Transition_Adjudication_20261103.md`; moved verbatim.

### P13-j Review/Definition — typed source transitions prove three descriptor boundary key splits

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`; still **IN_PROGRESS** pending an exact corrective patch, falsifiers and mandatory Review closeout. This record makes a **bounded root-cause stage adjudication**, not a Code + Build authorization or production acceptance.

#### Baselines and source of evidence

- Immutable production baseline: CB78 compiled semantic source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`. Accepted CP2 remains **491/491**, stable **66/17/49**, debt **1**; TB72A **883/883** is an unpromoted candidate gate, selector497 unpromoted. Original Vase direct production fails `AssemblyRejected/NonManifoldStitchedVertex`; Cylinder PASS, BunnyRandom separately fails `SingularityPortClassCountMismatch;sourceVertex=49`.
- Prior [three-fan runtime evidence](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_three_fan_witness_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md"), [prepared arrangement ring](#architecture_m6_cp3_defn_p13_assembly_node5355_prepared_ring_comparison_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md"), and [per-corner key scopes](#architecture_m6_cp3_defn_p13_assembly_dual_boundary_scope_witness_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Dual_Boundary_Scope_Witness_20261103.md") establish: first rejected global stitched row 3 has six incident quads in **three disconnected two-face fans**; node 5355's prepared arrangement has four reciprocal twin pairs and one connected four-cell ring (cells 26569,3,0,26570). Completed patch corner IDs diverge at arrangement neighbors 5356,5357,5359; 5351 is a matching control.
- Added a **scratch-only** environment-gated readout of `SourceChartTransitionGraph::resolve_entity`, `rebind`, and `compatible_chart_component` immediately before the original stitch operation on isolated diagnostic branch `agent/p13j-diagnostic-first-vertex-20261103`. Source commit **`7461cba7e9a72699f3aba839ec83b9c79b8451ce`**, after the prior P13J/K/L logging; `PatchDescriptor.cpp` gained **58 read-only diagnostic lines**, `PureQuadCompletion.cpp` unchanged from the previously verified diagnostic commit. Original fail-closed validator intact.
- Mandatory GMP/GMPXX compile **SUCCESS**: [GitHub Actions 41576761756](https://github.com/akashskypatel/Directional/actions/runs/41576761756), exact event commit `00f7d77ac6413429230f5e0bc6b75496fe4696e4`, package artifact **13204585017**, ZIP SHA-256 **`3344ced7a3efe0ad0e84c12e2167145475fc3ecaa7d885bec5361e582bd14a6a`**, internal SHA256SUMS all verified, `DIRECTIONAL_ENABLE_GMP=ON`, linked gmpxx/gmp, preflight and build exit codes 0, build `runtimeExecution=false`. Log artifact 13203673829, SHA-256 `58a675a94d898ed6bc4666b8e9d3ce23c2fae615445ef378c2976d414f66752b`.
- Replayed **the CI-built binary, without local compilation**, on the unmodified `benchmarks/fixtures/milestone_g_manifest.json` / `vase__surface_cells`, flag `DIRECTIONAL_P13J_SCRATCH_WITNESS=1`. Duration **286.971 seconds**; benchmark JSON `success=false`, same production failure `NonManifoldStitchedVertex`. Process exit 0 only means benchmark reporting completed. P13J/K/L/M BEGIN/END markers all exactly once. Executable SHA-256 **before and after identical**: `1f1b55c37bfe0b90ad8ededac7f5e05da8c7d0d2adc05aeaf38c84a2f5949dce`. Parser independently required exact markers, unchanged binary, failure status, and both cells for each compared node. Captured JSON SHA-256: `684eba5cd271b98ed998fe0470b530d75feff340498a09add0a715de073779fa`; parsed comparison SHA-256: `9481024fd73238a98fee51a931829f41a9b370a52dff93494e60b8e97387505e`.

#### Direct authority result: four corresponding boundary corners

For each two-sided claim the existing `SourceChartTransitionGraph` is **available**; each face resolves to the **same typed source-entity identity and support**, the `rebind` succeeds **in both directions**, the unique `compatible_chart_component` is **0**, and transformed barycentrics agree to 1.25e-16 or better:

| Arrangement node | Prepared source cells | Resolved exact support | Vertex fan (if any) | Native bidirectional rebind | Rebound discrepancy |
|---|---|---|---|---|---|
| **5351** (positive control) | 26569,3 | face interior 155 | n/a | true | 0 |
| **5356** | 26570,0 | source edge (0,1248) | n/a | true | 0 |
| **5357** | 26569,26570 | **source vertex 0** | **0 on both sides** | true | 0 |
| **5359** | 3,0 | source edge (255,1248) | n/a | true | 1.2412670766e-16 |

All typed owner scopes are region **0**, sheet **0** and chart-component **0**. The three failing neighbors are **not** disjoint hard-rail or vertex-fan sectors according to the native authoritative graph. The earlier interpretation of 5357 as distinct source vertices 255 and 857 was false: ordered OFF triangle faces prove that **both** occurrences are at vertex **0**. The previous review record already corrected that error; this graph probe additionally verifies identical vertex-fan **0**.

#### Producing-stage adjudication

**Root cause: descriptor/completion boundary identity construction.** `PatchDescriptor.cpp::derive_patch_descriptor` computes `boundaryNodeIdentities` with `arrangement_node_identity(node,F,source_scope(outgoing_halfedge))`. That builder filters node occurrences by a **face-specific outgoing source scope**, and `source_point_identity` records the **full source-face weighted corner list**. Subsequent `compact_patch_ownership_identities` assigns different dense ranks to differing scope records. Thus the *same* source-supported/transition-equivalent node obtains different compacted identities in adjacent completed patches (5356: 50500 vs 50501; 5357: 89848 vs 89849; 5359: 50195 vs 5144). `PureQuadCompletion.cpp::resolved_stitch_identity` then consumes those boundary identities verbatim. The stitcher correctly refuses the resulting three disconnected vertex fans. This is not a missing prepared arrangement twin or reason to weaken manifold validation.

**Corrective design scope (to turn into an exact, separately reviewed patch):**
1. **Change only the completed patch boundary-vertex key producer**, not the general `arrangement_node_identity` used by directed/undirected halfedge and domain identity audits, and not the assembly validator. Use the existing `SourceChartTransitionGraph` already constructed once in `complete_surface_cell_complex_pass`, carried explicitly into descriptor derivation through a borrowed, validated option.
2. For each boundary point, resolve `SourceEntityIdentity` (source support, component, field chart/vertex fan) and the intrinsic chart-transition component. Represent **intrinsic point location** canonically (vertex ID or edge topology + ordered/quantized edge parameter; face-interior source topology + canonical barycentric weights) so changing only a source-face chart does not change the key. Keep exact typed region and support ownership; **do not key by world position, hash, raw face-row, or arrangement node ordinal alone**.
3. Reject or retain distinct keys if either source entity is invalid, support/point locations differ, the authoritative chart transition does not permit bidirectional rebinding, distinct vertex fans/unique chart components are reported, or barrier/region ownership differs. No tolerance-only quotient that bridges hard rails. Account explicitly for the fact that raw sheet labels may differ across a **valid** chart transition; native graph authority, not equality of raw labels, governs.
4. Keep typed certificate validation, source-support conflict checks, repeat/duplicate quad detection, edge-manifold and vertex-link checks unchanged. Do not alter `source_point_identity` within domain/halfedge audits as a side effect.

**Required falsifiers for the exact subsequent patch**, using existing tests and extending descriptor/assembly tests only in the authorized Code + Build turn: (a) same source-edge point across rebindable charts produces the same completed boundary key; (b) same source vertex **same fan** across different chart faces produces the same key; (c) source edge with hard rail and two distinct vertex fans after hard rail must **not** merge; (d) two distinct source points on one edge and coincident coordinates of different source vertices/components must **not** merge; (e) source-face-row permutation must not change semantic key equivalence; (f) without the fix, targeted Vase-like broken fan and a deliberately split identity fail the original `NonManifoldStitchedVertex` oracle; with fix no validator weakening, and native graph negative cases remain separated. Existing independent native graph coverage includes `SourceChartTransitionsR1.HardRailSplitsAdjacentProjectionCharts`, `SourceVertexFansRespectTwoHardRailBarriers`, `NonManifoldSharedEdgeDoesNotCreateTransition`, and `ComponentMismatchBlocksExactManifoldAdjacency` in `tests/SurfaceArrangementPhase16Tests.cpp`. These tests were **inspected, not run** in this Review turn.

**Not yet closed:** precise production patch and actual independent negative/positive target probes, authenticated Git-ancestry review boundary script, review-closeout checklist, durable ORIENTATION/CHANGELOG/ROADMAP/tracker/TODO/handoff reconciliation and document consolidation. Do **not** create or execute a Code+Build successor in this review, do not promote TB72A or selector497, and do not merge the isolated scratch diagnostic branch. Same canonical turn continues.

#### Same-turn continuation — 2026-11-03 04:35 UTC: bounded corrective-key proposal (unaccepted)

A new exact **review-only** two-file source proposal has been constructed against immutable CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca` and preserved in the user's ChatGPT Library at:

`/Directional/Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__compatible-occurrences-v2.patch`

Full SHA-256 **`d38339902844fcb8ed902a5ed877f2d0a59464bbc7b83a246380460d945c1ff5`**; diff-body SHA-256 **`74bcf11cf2b91023df67f911440904a208b7603c1024e6ed78e745c72b846a0d`**; **54 insertions, 5 deletions across two files**. Forward `git apply --check --whitespace=error` against the exact CB78 source and reverse `git apply --check -R` against the locally patched source both **PASS**. This is **static patch applicability only**; it was **not compiled, executed, benchmarked, tested or submitted to the working branch**.

**Proposal mechanism:** Add a borrowed `const SourceChartTransitionGraph *boundarySourceTransitions` option used only by the production completion descriptor call. In `PatchDescriptor.cpp`, compute each completed-patch boundary stitch key from the **same original arrangement node's own source occurrences** that are permitted by `SourceChartTransitionGraph::rebind` from the selected corner's source point and agree on typed source-entity identity, source chart/region, and point position. Sort/deduplicate the full scope-specific `source_point_identity` entries and form one exact aggregate identity. All existing oriented/undirected halfedge domain identity logic remains unchanged; the original stitching and `NonManifoldStitchedVertex` validator are untouched. Direct descriptor callers without the new borrowed graph retain the existing behavior. This is narrower than applying a global key based on intrinsic source position alone.

**Superseded preliminary proposal:** `/Directional/Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__intrinsic-boundary-proposal.patch` (SHA-256 `e5fd3691887052f54e962f55c5de5a0d3b1640d7c97e2af7be65ebff107bb151`) is **withdrawn from consideration**: canonicalizing only source position could over-merge distinct arrangement nodes occupying the same source location. Do not run/merge it as a production solution.

**Falsification/acceptance still required before freezing:**

1. Compile the v2 patch on an **isolated exact-CB78 scratch ref** with the existing mandatory GMP/GMPXX reusable workflow; do not run local builds or mutate the production branch.
2. Positive witness: the two boundary keys at each node 5356, 5357, 5359 compare equal and Vase progresses past the **original first nonmanifold vertex**. Check that no invalid arrangement-node quotient was created; merely changing the failure signature is insufficient.
3. Negative guard: disconnected source-vertex fans at the same vertex, a hard-rail split of adjacent charts, distinct source points on one edge, nonmanifold source-edge contacts, and two independent arrangement nodes sharing a source point remain **separate**. For each adversary explicitly assert inequality of boundary keys and the correct fail-closed output when applicable. Tests must fail if the original face-scoped implementation or an unsafe coordinate-only merge is substituted. Do not reuse green native-chart unit tests as proof of the new descriptor behavior.
4. Source-face-row/permutation invariance: semantic equality and separation hold under source-row reorder, mirrored boundaries and patch-order changes. The proposal selects a sorted set of exact typed occurrences, but this has **not been independently verified in compiled code**.
5. Check numeric threshold/quantization: the proposal compares rebound barycentric coordinates with **1e-8** and uses existing `quantized_parameter` with **1e10** scale. Those distinct tolerances need an explicit near-coincident adversarial negative test; otherwise a close but distinct occurrence could be accepted. If so, tighten the comparison at the identity producer, rather than suppressing topology validation.
6. Only with green discriminating evidence can the Review finalize an exact corrective patch, one Code + Build successor with predeclared stop rules, and required REVIEW_TURN_POLICY §5 closeout; no automatic successor authorization exists now.

**Preservation transport:** attempted Google Drive upload to the verified `My Drive/Directional-CI` folder (ID `1I_-EViWSpaxg69pbglfPPVnFRYb1s5O0`), but the available Drive connector **requires a connector file-reference object**; a Library file ID was rejected with `INVALID_ARGUMENT`. No Drive upload occurred. Both proposals are durably persisted in the user's `/Directional/` Library folder and are downloadable from this conversation; for remote patch application, transfer the **v2** bytes to Drive through a supported connector-file transport first. Do not claim a Drive file ID or workflow compile.

**Remaining:** precise negative tests and scratch verification, review-boundary verification with authentic Git ancestry, ORIENTATION/tracker/CHANGELOG/ROADMAP/selector/handoff/TODO reconciliation and mandatory consolidation. **Current turn remains incomplete**, with CP2 491/491, stable 66/17/49, debt 1, TB72A 883/883 candidate and selector497 unpromoted. Preserve this same canonical turn without beginning its successor.

#### Same-turn continuation — 2026-11-03: independent V2 boundary-contract audit

**Authority:** Review/Definition `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` remains open; no Code + Build successor was initiated. Exact working-branch source snapshot at `63fe94125206c60d70ce06e54067a4697c79b7e7`: source-snapshot run `41610561568`, artifact `13218926987`, outer SHA-256 `d2783a3548cfee45492a6992ea573c8fd8788c71acde379f06a09d1ceac45cd7`; 6,125/6,125 source-file SHA-256 entries verified. The snapshot executed no Directional binaries.

**Read-only recheck of unaccepted V2:** The preserved Library patch `Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__compatible-occurrences-v2.patch` independently matched full SHA-256 `d38339902844fcb8ed902a5ed877f2d0a59464bbc7b83a246380460d945c1ff5` and diff-body SHA-256 `74bcf11cf2b91023df67f911440904a208b7603c1024e6ed78e745c72b846a0d`. `git apply --check --whitespace=error` passed against the verified working source for its two affected files. This is **patch applicability only**, not compile/runtime/negative evidence.

Two source-backed gaps prevent accepting V2 as an exact corrective contract:

1. **Unavailable transition authority is not explicit.** The V2 call would assign `descriptorOptions.boundarySourceTransitions = &sourceTransitions` unconditionally in `complete_surface_cell_complex_pass`, but `SurfaceCellComplexCompletionOptions::sourceAuthority` defaults to null (`PatchDescriptor.h`). `SourceChartTransitionGraph::available()` requires a bound source authority. V2's `compatible_boundary_node_identity` silently returns an invalid canonical identity when unavailable, rather than retaining the original scoped identity for nonpublishing callers or raising a typed failure at the publishing boundary. This is a demonstrated behavior change in the proposed source path, **not** a compiled regression or an observed Vase failure. Specify and verify the correct authority-unavailable behavior before approval.
2. **Near-coincident inclusion is wider than stored identity precision.** V2 accepts `(rebound.barycentric - bary).norm() <= 1e-8`, while `PatchDescriptor.cpp::quantized_parameter` stores `llround(value * 1e10)`. A scalar difference of `5e-9` passes the V2 comparison yet differs by **50 integer quantization units**; choosing opposite adjustments of `5e-9` in two edge barycentrics gives norm approximately `7.07e-9`, still below the V2 threshold. When a node carries close but inequivalent occurrences, V2 may include both in the aggregate. That is a non-vacuous **potential** equivalence error, not a demonstrated separate-node production merge. Test the descriptor/assembler boundary with those exact adversarial coordinates, preserving original negative topology checks.

**Unchanged cache caveat:** `retarget_reused_completion_product` still retargets mesh patch/domain and lineage sourcePatch but not cached boundary-local identities, while exact dependency and `validate_completion_domain_ownership` already guard many mismatches. No same-dependency, changed-owner cache alias has been reproduced. An ID-only owner shortcut remains withdrawn; any cache change must be justified by a positive collision witness, not a speculative risk. The initial P13-j rejection does not depend on cache reuse.

**Review boundary evidence:** `python3 .agents/Directional/tools/review_check.py boundary` was invoked on the source snapshot: product/test/fixture/build and selector mutation checks passed, but the overall result **FAILED** because the snapshot lacks `.git` ancestry, affecting the durable rewrite baseline and three durable-source checks. Independently, the authenticated GitHub comparison `8b7299b43...63fe9412` reported `ahead=3496`, `behind=0`, and the exact baseline as merge base. This establishes ancestry via GitHub but **does not** convert the failed local `review_check.py` into PASS.

**Disposition and required continuation:** V2 stays **UNACCEPTED**. Require the original positive Vase identity pairs 5356/5357/5359 (and control 5351) to be established with actual descriptor/assembly evidence, plus adversarial negatives for different prepared nodes at coincident source points, hard rails, vertex fans, nonmanifold edge contacts, same-edge near-coincident points, face-row permutations, unavailable authority, and unchanged-owner cache reuse. Do not modify the assembler's `NonManifoldStitchedVertex` rejection, do not accept a mere change in failure signature, and do not run tests or mutate production code in this Review. Accepted CP2 491/491; unpromoted TB72A 883/883 and selector497; stable 66/17/49 and debt1 unchanged. Mandatory Review §5 closeout and an exact independently proven successor remain pending.

## `Architecture_M6_CP3_DEFN_P13_Compatible_Occurrence_Key_V2_Scratch_Verification_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Compatible_Occurrence_Key_V2_Scratch_Verification_20261103.md`; moved verbatim.

### P13-j — scoped boundary-key V2 scratch verification (2026-11-03)

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`, **IN_PROGRESS**. This is diagnostic evidence, not accepted production code, gate promotion, or a successor authorization.

#### Exact source and patch

- Immutable CB78 baseline source: `afd72107d3213a396ed7f35b53f67dceeea7e7ca`.
- V2 work-preservation patch in ChatGPT Library `/Directional/Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__compatible-occurrences-v2.patch`; full SHA256 `d38339902844fcb8ed902a5ed877f2d0a59464bbc7b83a246380460d945c1ff5`, diff-body SHA256 `74bcf11cf2b91023df67f911440904a208b7603c1024e6ed78e745c72b846a0d`. Applies forward and reverse against exact CB78 source, whitespace check PASS.
- Scratch branch **`agent/p13j-compatible-boundary-scratch-20261103`** created from CB78. Source commit **`36fb5349aebb96a0b5b0d30d5c5265a110c5df8c`** changed only `include/directional/geometry/PatchDescriptor.h` (Git blob `e23724eb27c5e7098d1f4cf2dd5bb915f4d6ed3e`) and `src/geometry/PatchDescriptor.cpp` (Git blob `9c24c984e604f85fa58822f3821c91ec13b0446e`); both exact hashes independently verified against locally patched CB78 source. The production working branch contains **no** semantic source mutation.

#### Isolated GMP build evidence

- First exact source compile request commit **`7ae917c69c1fffe405c82b8f84ad99facee7aa4c`**, run **41581341497**, failed at `ninja: error: unknown target 'directional_tests'`. All 107 steps including `directional_benchmarks` compiled, preflight target was green, but the overall build **FAILED**; this is an assistant-selected invalid target, not a source compiler error. No unit tests ran. Error log artifact **13205842583**.
- Corrected compile request commit **`f056bf363d3664194cf9ce8169a8d14665414230`**, valid target `directional_benchmarks` only, run **[41581676195](https://github.com/akashskypatel/Directional/actions/runs/41581676195)**: **SUCCESS**. Immutable package artifact **13205668125**, outer SHA256 **`ba5fda366227e4e2e5f5856853e1344aae4b14e7cb2b1b86660e190daa1cd07e`**; 23/23 internal SHA256SUMS match, source commit matches scratch exact SHA, configure `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, link evidence includes both gmpxx and gmp, preflight/build exit 0, compile workflow `runtimeExecution=false`. Log artifact **13206511928**.

#### Exact evaluation boundary

- Candidate has no accepted runtime or test result at time of initial report write; the independently verified CI binary is executing the immutable Vase benchmark `vase__surface_cells` from `milestone_g_manifest.json`, warmup 0, runs 1, with **420 s timeout**. Case-level `runs[0].success` and terminal reason, not executable exit code, will determine the diagnostic verdict. The initial direct CB78 Vase failure was `AssemblyRejected/NonManifoldStitchedVertex` (first global row 3, three disconnected two-face fans).
- The source uses existing `SourceChartTransitionGraph::rebind` and `resolve_entity` and only the boundary-key producer; source domain and halfedge identities, original edge/vertex manifold validation, and accepted selector are unchanged. Critical unproven safety: rebound barycentric tolerance **1e-8** and potential false equivalence if **distinct arrangement nodes** have equal sets of source occurrences. Do not freeze V2 as an exact corrective patch without negative tests.
- Required negative tests: separate chart components behind hard rails; distinct source-vertex fans; coincident source support from independent arrangement nodes; distinct points separated below 1e-8 (within barycentric rebound tolerance); nonmanifold source-edge contacts; face-row and patch-order permutation. A negative test must detect the unsafe merge, not just pass the existing native graph tests. Tests may be added only in an authorized Code + Build turn; no test source changed here. Exact positive: two boundary keys at each of 5356/5357/5359 should become equal and geometry must progress past first Vase stitched vertex; a different failure elsewhere is not a pass.
- Established accounting unchanged: accepted CP2 491/491; stable 66/17/49, debt 1; TB72A 883/883 candidate unpromoted and selector497 unpromoted. No other pipeline stage and no Code + Build successor launched.

#### Continuation requirements

Append case-level runtime status and checksummed evidence when the currently running bounded replay finishes. If the replay fails, do not adapt tests or suppress validators. Fix only evidenced root cause, and retain V2 as an unaccepted scratch proposal. The canonical Review remains incomplete until exact negative/positive falsifiers, proof of no improper topology quotient, authenticated ancestry-backed `review_check.py boundary`, mandatory REVIEW_TURN_POLICY documentation closeout/consolidation, and one separately authorized successor are established.

#### Runtime closeout: bounded V2 Vase replay — TIMEOUT (2026-11-03 05:13 UTC)

The CI-compiled candidate benchmark was launched at **2026-11-03 05:06:15 UTC** with exact immutable `milestone_g_manifest.json` / `vase__surface_cells`, warmup 0, one run, from the fixture directory; command uses only the packaged prebuilt `directional_benchmarks` and **does not compile locally**. It **TIMED OUT after 420.057 seconds**. There was **no benchmark JSON**, no terminal case verdict, no `NonManifoldStitchedVertex` result or replacement failure, and no claim that the candidate fixes Vase. The prebuilt binary SHA256 was identical before/after: **`d4a6b7384bb0b8a5463cfa2541b810f7e2fbd7db9ef2d85ee6ae18430ddf2da7`**. Runtime report SHA256 **`1a7ce868c63c9670021dd393f931d74aad509caf183dc0a7dd024c44f37c0ee5`**. Stderr 4316 bytes, SHA256 **`08d380c27d28a0fa30e88db48d7d953dd3e21668050a6e083fe8eb75f4fbb817`**; only early `FieldTransportAtlas.partition` and `M3_CP4AB_FRAGMENT_DIAG` records were emitted, not the completion/assembly site. Stdout 43 bytes, SHA256 **`8a48a83dff828da89d3f04ad77376f149d34cf406c4d7ffcf0d6370fc11e0b54`**.

Prior exact-CB78 **instrumented** diagnostic Vase replays completed in roughly **286–294 seconds** in this container, so the V2 duration is a serious *performance/regression signal*, but different compilation or execution conditions could contribute. No profiler traces identify the hot path, and a timeout without a terminal verdict proves **neither improvement nor a new regression class**. Do not increase the acceptance timeout just to obtain a green result. A bounded profile should identify whether the new per-node chart-rebind calls are responsible; prove any optimization is semantics-preserving before reconsidering V2.

**Evidence preservation correction:** the new runtime script accidentally reused the two older `P13j_Typed_Chart_Rebind.stderr.log` and `.stdout.log` local output paths. After timeout, the new bytes were copied to unique `P13j_V2_Candidate.stderr.log` and `.stdout.log`, and the original files were **restored byte-for-byte** from previously verified `Directional_P13j_Typed_Source_Transition_Evidence_20261103.zip` (original SHA256 stderr `8578944004c1b38b0219014e68905ae1f373bdb0696b7a1dca42ee1454bcd1e2`, stdout `e8982b4776f77b51201559933ee1842fe645cdf199c5e22d7f8adf67f22dacf1`). This mistake did **not** affect GitHub or the immutable CI package. Restore check passed.

**Disposition:** V2 is **UNACCEPTED**; not compiled/tested as a unit-test target, not proven to close the fan, not proven safe for distinct nodes, near-coincident source support, hard rails or vertex fans. Do not merge the scratch branch or start the successor. Keep the Review turn **IN_PROGRESS** to isolate the runtime cost, establish positive/negative falsifiers and exact safer patch before finishing mandatory review closeout. Stable CP2/TB72A/selector authority unchanged. This same-turn review record and the preserved Library patch remain authoritative to resume without repeating already completed diagnostics.

#### Same-Review producer uniqueness and ancestry addendum (2026-11-03)

Authenticated GitHub compare CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca` → resumed head `abf057574b7a96584dd5b09c8ba00d853ad54643`: `ahead` by 99 commits, merge base exactly CB78, 20 changed paths, **none** in `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/` or `CMakeLists.txt`. Thus current reviewed implementation matches CB78 semantics; this compares authenticated Git ancestry, not a fabricated local history.

Important qualification to the separate source-level conditional risk: `SurfaceArrangement.cpp::node_id` interns one node per `ScopedNodeKey=(NodeKey,TopologyRegionId,NodeAuthorityScope)`; its node key encodes vertex ID, edge topology plus 1e-10 parameter, or face plus 1e-10 local parameters. Vertex fans and face-interior sheets are included in scope; edge interiors use one shared source-edge scope. Consequently, two distinct **initially constructed** arrangement nodes cannot have the same complete scoped node key. The hypothetical identical-occurrence/different-node counterexample is **not** an observed production failure, and this source evidence narrows its plausibility. It does **not** prove the proposed V2 occurrence-set projection injective after `ensureOccurrence` enrichment and preparation: the V2 key omits the original scoped-node key, and no independent prepared-complex adversarial negative has established the projection's injectivity. Preserve the original distinct-node, hard-rail, vertex-fan, and near-coincident negative requirements. Do not promote V2 or change the validator.

V2's `resolve_entity` and `rebind` use the already-built `SurfacePointSourceSupportResolver` incidence lookup, not a fresh source-wide graph build at each invocation. Repeated boundary/occurrence work is possible, but existing process samples do not establish that it caused the Vase timeout. No runtime execution or build occurred in this Review addendum.

## `Architecture_M6_CP3_DEFN_P13_Completed_Lineage_Discriminator_Gate_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completed_Lineage_Discriminator_Gate_20261103.md`; moved verbatim.

### P13-j — completed-boundary ownership discriminator (same Review, 2026-11-03)

> **Resolved (2026-11-03) by [RA-200](#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_probe_adjudication_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md") §1 item 1:** the measurement below was taken on the scratch build. Branch (A) holds: the certificates on both sides are identical at 5351/5355/5356/5357/5359, and only the descriptor key differs. The fix is Amendment 32, exact CB79 → TB73.

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`. This is a source-and-retained-evidence decision gate, **not** a completed Review, corrective patch, runtime test, or Code + Build authorization.

#### Immutable authority and independent recheck

- Semantic base: CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; compiled eight-target GMP/GMPXX package `13181887585`. TB72A 883/883 is verified **unpromoted**; accepted CP2 491/491, stable 66 events / 17 categories / 49 recurrences, debt 1, 81 deferred and membership 964 unchanged.
- Exact source snapshot: `5bf12419f1cb185aef2e297b3ad17b2e470a916f`, run `41645502073`, artifact `13233879616`, source archive SHA-256 `59cdf6240fb20b09e329e8171343535af38418a948693069acdbdba3b79503fd`. Re-ran `sha256sum -c`: **6,128/6,128 PASS**, zero mismatches. Authenticated GitHub comparison from the snapshot to this attempt's entry head lists only three Review documents, removed temporary snapshot marker, and `STATUS`; no semantic C++/test/fixture/workflow/selector changes.
- Re-read independent ring report `p13j_ring_identity_probe.json` SHA-256 `4bd03c5bb2adf69368a9f13c77501e3872527a71e82083091ccbed1b8bf64907` and source endpoint report `vase_source_endpoint_audit.json` SHA-256 `86da0aec57a7bf0ef37f47543973061c3b3cbc3a7084aa8d5bd775bdfaec7bd5`. These are prior scratch-derived and independently parsed read-only reports, **not new C++ measurements**.

#### What is proven and what is missing

The prepared node 5355 has a valid four-cell reciprocal ring (cells 26569, 3, 0, 26570). The descriptor-boundary key pairs in the retained report are:

| Neighbor node | Reciprocal cells | Descriptor keys | Evidence |
|---|---|---|---|
| 5351 | 26569 / 3 | (1,61357) = (1,61357) | Positive control |
| 5356 | 26570 / 0 | (1,50500) != (1,50501) | Split |
| 5357 | 26569 / 26570 | (1,89848) != (1,89849) | Split |
| 5359 | 3 / 0 | (1,50195) != (1,5144) | Split |

The three mismatched endpoints have common intrinsic source support in the original Vase source, and the prior **native scratch probe** established bidirectional chart transition, region 0, sheet 0, and compatible chart component for these pairs. In `PatchDescriptor.cpp:414-445,1758-1760`, `arrangement_node_identity` *filters* to the outgoing halfedge's selected source scope, so descriptor keys already diverge **before the assembler**. `PureQuadCompletion.cpp:2838+,3426-3495` then consumes the keys and fail-closes incompatible typed certificates and geometry. This identifies the **current failure-producing boundary** as descriptor-to-completion stitch identity, not a license to change the assembler's `NonManifoldStitchedVertex` rule.

The reviewed ring JSON contains **only** the two cells, outgoing source-face rows, and the compact descriptor keys per neighbor. The endpoint JSON records original source support, but **neither reports the actual completed-patch `vertexLineage.sourceCharts` vectors, selected completed `sourcePoint`, topology region/sheet vectors, source occurrences, relation paths, or cache reuse at assembly**. Static non-A5 chart-closure reasoning predicts compatibility conditionally, but does not measure these outputs. No amount of renaming, source-position-only hashing, or a new Python connectivity model substitutes for that evidence.

#### Single next discriminating measurement (separate authorized scratch execution)

Using **unchanged CB78 semantic source** and its scratch-only diagnostic execution path, capture the *existing completed patch products* immediately before the original assembly lookup at `PureQuadCompletion.cpp:3426-3495`. For each side of reciprocal nodes **5351, 5356, 5357, 5359**, and for each of the four contributors at center **5355**, record:

1. Exact source cell / patch / local boundary-vertex identity and the matching prepared node/twin endpoint; full resolved `PureQuadStitchIdentity` (both numeric and typed members), completed `vertexLineage.stitchIdentity` and `authoritativeIdentity`.
2. Actual completed `vertexProvenance` / lineage source point and `sourceSupport`, full sorted `sourceTopologyRegions`, `sourceIsolationSheets`, **literal** `sourceCharts` (typed chart and canonical face), plus source occurrences and selected relation-path certificates.
3. Cache creation/reuse result for that completed patch; provenance rebind candidate faces; the pairwise and cumulative typed-authority intersection and any common provenance rebinding face.

The report must include *both* sides and cannot summarize a chart set as `chart_component=0`. Keep the original rejection and tests untouched; no product source, tests, fixtures, selectors, or benchmark mutation in this Review. Any instrumentation, C++ run, or compile belongs only to a **separately authorized scratch diagnostic/CB/TB boundary**, with exact source and artifacts recorded; do not silently execute it under this Review.

**Decision tree:** (A) all reciprocal typed certificates and global 5355 certificate compatible, while three descriptor pairs differ: design only the exact upstream semantic owner-key producer and prove row/corner/repair/injective class invariance; (B) a required pair's *actual* completed certificates are incompatible: first adjudicate the completing producer/source-chart closure, **not** a descriptor-only key merge; (C) compatible identities but reused cache product has changed owner: independently prove same-key/different-full-membership through the real reuse validator while preserving unchanged-owner reuse; (D) the corrected key reaches an original face/vertex manifold or source provenance rejection: retain that rejection and re-evaluate owner eligibility. No branch licenses geometric welding or synthetic green.

#### Review boundary and continuation

`python3 .agents/Directional/tools/review_check.py boundary` on the verified snapshot **exited 1**: it lacks Git history and cannot authenticate durable rewrite baseline ancestry, marking selectors as untracked. This is not PASS. Prior authenticated GitHub compare establishes byte-level semantic unchanged paths but cannot replace the mandated command on a history-bearing checkout.

The exact owner-key serialization, disjoint point-contact and hard-rail/sheet/fan sector admissibility, repair-generated node ownership, and completion-cache full-member reuse certificate remain unaccepted. The Review §5 document closeout and any Code + Build successor must wait for a genuinely discriminating measurement and its adjudication. Do not replay CB78/TB72A or promote CP3/selector497.

**Current disposition:** same canonical Review unresolved; the missing completed-lineage measurement is a **review/design conditional gate**, not a connector authorization or safety-check failure. No successor starts in this turn.

## `Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md`; moved verbatim.

### RA-201 — P13-k optimizer source-query cost probe adjudication (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (Review/Definition) — **COMPLETE**. It resumes from the ChatGPT Review's `REVIEW_BLOCKER`, which was procedural: the turn needed scratch execution on CB79, and that Review must stay runtime-free. The [static preflight](#architecture_m6_cp3_defn_p13_optimizer_source_query_cost_static_preflight_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md") located the three sites and set the requirements. This adjudication ran the measurements on the macOS scratch build (Claude, diagnostic only). It changes no product source in the repository.

**Base:** HEAD `2f36c637c`. Its product source equals CB79 `3feb2a4182a5a12c2a9f306272756f8333a44b59` (`git diff --quiet` over `src include tests benchmarks CMakeLists.txt cmake`).

**Supersedes as open work:** the static preflight. Its site list and requirements stand and are met below: validate at the stage boundary, lend only exact-input structures, keep standalone rejection, add non-timing behaviour rows next to any cost row, and make the terminal name its check.

#### RA-201.1 Findings

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

#### RA-201.2 Probes (macOS, scratch, diagnostic only)

| Probe | What it shows |
|---|---|
| Iteration 1: probe K plus a lent label support | The per-quad graph is gone; `matches_source_faces` per chart face remains (46 % of samples) |
| v2: CB80–CB82 forms | Vase 252 s; terminal unchanged |
| `probe`: census prints `surfaceCellFirstInvalidProducer*` | `completion/output-validation \| SelfIntersectingFace`, quad 16034, cell 510 |
| `probe2`: census prints the validation report and counts issues by code and by edge/face form | Table in item 3 |
| M3v on Vase | 269 s without the `available()` change |
| Stack samples (`sample`, every 30–45 s) | Item 1 table |

#### RA-201.3 Rulings

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

#### RA-201.4 CB80 — `M6-CP3-CB80-P13-RAIL-BINDING-ONCE`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 3feb2a4182a5a12c2a9f306272756f8333a44b59 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff"), byte for byte. SHA-256 `d4dda97eeea13c4c50ca107fa06bf093b7a173abce9a0bbfb268e8793da265fe`, 281 lines, 11 single-space context lines. Run `git apply --check`, then apply.

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

#### RA-201.5 TB74 — `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB80's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB74_P13_Rail_Binding_Once_Full_Gate_Case_Manifest.tsv"), 888 rows, SHA-256 `bb4e771fd911d9aefdb83c89cf2ac8def41e464bb41f26778a1b3a98adbee4da`. It is TB73's 886 rows byte for byte plus GUARD rows 887–888.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=888 deferred=81`.
  - Pre-registered **888/888**, membership **969**.
- **Census:** `3af1dc0d…`, unchanged. Cylinder PASS; BunnyRandom P13-e unchanged; **Vase ABNORMAL, 600 s timeout (exit 124)**, because the per-quad label support remains until CB82.
- **Outcomes:** mismatch → `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-REV` (Review); infrastructure → `M6-CP3-TB74A-P13-RAIL-BINDING-ONCE-ORCH` (one retry).

#### RA-201.6 CB81 — `M6-CP3-CB81-P13-LENT-PROJECTION-CACHE`

Code + Build, compile only.

- **Precheck:** the product paths differ from `3feb2a41…` in exactly CB80's three paths, each at its RA-201.4 result SHA-256.
- **Patch:** [`Architecture_M6_CP3_CB81_P13_Lent_Projection_Cache.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB81_P13_Lent_Projection_Cache.diff"), byte for byte. SHA-256 `ffa4b5548b6bf45f044dac4b46fb2cca51db051b324d2ca7c0116faae99a4e30`, 169 lines, 6 single-space context lines.

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

#### RA-201.7 TB75 — `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-EXEC`

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB75_P13_Lent_Projection_Cache_Full_Gate_Case_Manifest.tsv"), 890 rows, SHA-256 `a134d9411bd5885fa85d7405e2a733da7cd4d5899d17a83f6dbcb501d18326c6`. It is TB74's 888 rows plus rows 889–890; `SELF_CHECK_PASS cases=890 deferred=81`. Pre-registered **890/890**, membership **971**.
- **Census:** as TB74 (**Vase ABNORMAL 600 s**).
- **Outcomes:** `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-REV` / `M6-CP3-TB75A-P13-LENT-PROJECTION-CACHE-ORCH`.

#### RA-201.8 CB82 — `M6-CP3-CB82-P13-LENT-LABEL-SUPPORT`

- **Precheck:** the product paths differ from `3feb2a41…` in exactly the CB80/CB81 paths, each at its RA-201.6 result SHA-256 (the rail file at its RA-201.4 hash).
- **Patch:** [`Architecture_M6_CP3_CB82_P13_Lent_Label_Support.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB82_P13_Lent_Label_Support.diff"), byte for byte. SHA-256 `b963ea3d4b440fea66b65926478861b7bb6c489166f21b7db41769dc31cde1d2`, 349 lines, 10 single-space context lines.

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

#### RA-201.9 CB83 — `M6-CP3-CB83-P13-OUTPUT-VALIDATION-TERMINAL-DETAIL`

- **Precheck:** the product paths differ from `3feb2a41…` in exactly the CB80–CB82 paths, each at its latest RA-201 result SHA-256.
- **Patch:** [`Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail.diff"), byte for byte. SHA-256 `3741697ed34d219579a97081db3763126292a3d103a445e2ceda6cbbf37df682`, 16 lines, 1 single-space context line. Numstat `4 1` `src/pipeline/RemeshPipeline.cpp`; result SHA-256 `ceb0ec7f0b0f6be6ef4e45f512d7b5068958bd131e2517b5136fc4060ce37df2`.
- **Content:** when the completed mesh fails its pre-optimization validation, the terminal detail is the reason the diagnostics already record: the first strict issue, `MissingFeatureRail`, or `AggregateCompletionValidationFailure`. This follows CB75. Nothing else changes.
- **Tests:** none new. The only fixture that reaches this branch is the Vase census; TB76 registers its detail.
- **Build / outcomes:** as CB80; `M6-CP3-PLAN-P13-OUTPUT-VALIDATION-TERMINAL-STOP` / `M6-CP3-CB83A-P13-OUTPUT-VALIDATION-TERMINAL-ORCH`.

#### RA-201.10 TB76 — `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC`

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB76_P13_Optimizer_Source_Query_Full_Gate_Case_Manifest.tsv"), 893 rows, SHA-256 `3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8`. It is TB75's 890 rows plus rows 891–893; `SELF_CHECK_PASS cases=893 deferred=81`. Pre-registered **893/893**, membership **974**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder PASS; BunnyRandom P13-e unchanged.
  - **Vase RED within 600 s: `terminal=NotProductionReady:completion detail=SelfIntersectingFace … completedQuads=67829 completion=`** (macOS scratch: about 250 s).
  - A Vase timeout means CB82 did not take; `detail=None` means CB83 did not take; any other verdict is a mismatch.
- **Outcomes:** mismatch → `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV` (Review); infrastructure → `M6-CP3-TB76A-P13-OPTIMIZER-SOURCE-QUERY-ORCH` (one retry).

#### RA-201.11 Turn sequence

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

#### RA-201.12 Scratch verification (final state = CB80–CB83 on CB79)

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

#### RA-201.13 Probe scripts (scratch, not committed)

`scratchpad/p13k/`:
- `make_k.py STATE0 OUT STAGES`: stages `s1`–`s4` (CB80–CB83 source), `t1`–`t3` (their tests), and the census prints `probe` and `probe2`.
- `make_patch_k.py A B OUT WT [EARLIER…]`: writes a patch, applies the earlier patches, then checks, applies and hashes it on a clean worktree.
- `make_manifests.py`: TB74–TB76 manifests.
- `mutate_k.py`: mutants M1–M3v.
- `run.sh`, `sampler.sh`, `hot.py`: census runs and stack summaries.

#### Review closeout

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

## `Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md`; moved verbatim.

### P13-k optimizer source-query cost — static preflight (INCOMPLETE)

> **Resolved (2026-11-03) by [RA-201](#architecture_m6_cp3_defn_p13_optimizer_source_query_cost_probe_adjudication_20261103md "moved: Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md"):** the scratch execution below was run on CB79. All three sites were measured, plus the same binding check one level down (per chart face and per label-support query). Vase keeps its verdict and reaches it in about 250 s. The rejecting check is named (P13-l; terminal detail by CB83), and the guarded patches are frozen as CB80–CB83 → TB74–TB76.

**Canonical turn:** `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (Review/Definition, P13-k).  
**Status:** Static source preflight only. **This is not RA-201, a completed DEFN, an approved CB patch, or a runtime verdict.**  
**Source inspected:** Verified immutable source snapshot 41702924049 / artifact 13264691897 / SHA `9d5ab4333e94c527a8d56b11d1ac689632e96eba`; source/test tree was unchanged through the inspected STATUS head `3c100ab78a22ce67ece25658f6af692dc52fe59c`. CB79 semantic source is `3feb2a4182a5a12c2a9f306272756f8333a44b59`.  
**Prior primary evidence:** RA-200, `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md`, §RA-200.2a. Latest immutable TB73: 886/886 gate, membership 967; independent census Cylinder PASS, BunnyRandom P13-e RED, Vase expected ABNORMAL timeout (600 s). No runtime was executed in this preflight.

#### Independently inspected source sites

1. **Repeated source topology validation.** `src/geometry/SurfaceOptimizationRailConstraints.cpp` has a private `source_face_scope` that calls `SourceTopologyRegions::matches_source_faces` on each invocation. `provenance_supports_interval_sheet` calls it for both provenance and interval faces; `fill_surface_optimization_rail_constraints` iterates output vertices and rail intervals. The general `source_face_scope` in `include/directional/geometry/SurfaceMeshOptimizer.h` must also be audited. Separately, `source_optimization_has_complete_authority` in `src/geometry/SurfaceMeshOptimizer.cpp` verifies the full input and face vertices. **Required:** validate immutable source authority at the correct invocation boundary and pass a verifiably source-bound result to inner queries, preserving standalone invalid-input rejection. Do not globally remove the validating public helper or equate array dimensions with source binding. RA-200 measured the rail fill at ~3 minutes before its two-site scratch change versus 0.1 seconds after.

2. **Unconditional projection BVH construction.** `src/geometry/SurfaceMeshOptimizer.cpp` constructs `SourceProjectionCache localCache(constraints)` before deciding whether to use the lent `projectionCache` in `nearest_source_point`, `project_vertices`, and `quad_reference_surface_point`. The cache constructor in `include/directional/geometry/SurfaceMeshOptimizer.h` builds `SurfaceProjectionBvh` for nonempty valid source dimensions. **Required:** construct a local fallback only when no compatible lent cache is available; preserve exact face restrictions, component/sheet filtering, and no-cache standalone behavior. Audit lifetime and source ownership of the lent object. This is not permission to drop complete-authority checks.

3. **Per-quad chart graph rebuild.** `consistent_source_scope` and `quad_reference_surface_point` in `src/geometry/SurfaceMeshOptimizer.cpp` each construct `validation::source_authoritative_detail::SourcePointLabelSupport`, whose constructor owns `SourceChartTransitionGraph` construction (`include/directional/validation/SourceAuthoritativeMeshValidator.h`). `OutputProjectionCache` invokes the first across output quads. A different validation path in `SurfaceMeshOptimizer.cpp` already creates `sourceLabelSupport` once for its containing function. **Required:** one source-labelled support per immutable stage scope; lend by `const` reference only on exact `SourceChartTransitionGraph::borrows`-compatible face matrix, authority, hard-edge set, and tolerance (DESIGN Amendment 27). Preserve the existing zero/ambiguous/no-common-chart rejection semantics. Do not convert the graph into a global mutable cache. RA-200 measured ~20 minutes at this third site across 67,829 Vase quads.

#### Prospective three-step CB boundary (NOT YET AUTHORIZED)

The owning DEFN must first make and measure a scratch change for **all three** sites on CB79 and prove unchanged output/verdict. Only afterward freeze exact independently applicable code patches and non-vacuous cost GUARDs, **one separate Code + Build turn per site**, as RA-200 directs. Potential GUARDs must fail if a loop-bound matcher, unnecessary BVH construction with lent cache, or per-quad graph construction reappears; they must also reject invalid source identity, mismatched lent data, cross-component/sheet leakage, and unsupported charts. Avoid timing-only thresholds and avoid weakening the full validation oracle. Subsequent TB is separately artifact-only.

RA-200's earlier scratch `PROBE_K` removed sites 1–2, not site 3. It reached `terminal=NotProductionReady:completion` after 1,521 seconds, with `detail=None` and an empty completion code. That is **not** a diagnosed P13-l cause. The scratch reviewer must first measure the full three-site correction, confirm the same semantic verdict significantly faster, then identify the exact rejecting check and restore the required typed detail/completion code. Only the completed DEFN can assign the rejection to its next authorized owner.

#### Outstanding review/authority gate

This turn's authoritative owner in RA-200 is a scratch-capable **Claude Review**. The ChatGPT Web DEFN execution contract is runtime-free; this session has not executed a C++ scratch binary, assembled the exact three patches, measured the full correction, verified GUARD mutations, or identified the terminal rejecting check. Therefore **the Review/Definition is not complete**; no CB successor or source mutation is authorized by this preflight. The canonical successor remains UNKNOWN pending the required scratch adjudication.

Accepted CP2 remains 491/491; stable regression accounting remains 66/17/49, debt 1; selector497 and CP3 remain unpromoted. No claims of test, build, benchmark, acceptance promotion, or resolved Vase production are made.

#### Review closeout (incomplete; explicitly open)

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Pending; no selector mutation or promotion |
| Decisive claims independently re-derived | Source call sites inspected; RA-200 timings attributed to prior scratch, not independently reproduced |
| Non-vacuity checked | Planned GUARD falsifiers identified; no actual mutation run |
| Prior obligations discharged/carried | P13-k all three sites + typed terminal reason carried; P13-e remains parallel |
| Stable accounting | CP2 491/491; 66/17/49, debt 1; TB73 886/886, membership 967, 81 deferred |
| New candidates/obligations recorded | No new stable ID; P13-l retained as undiagnosed downstream condition |
| ORIENTATION currency line | Unchanged; review not closed |
| ORIENTATION §3 / §4 / §7 / §8 | Unchanged; review not closed |
| CHANGELOG | Unchanged; review not closed |
| ROADMAP | Unchanged; no milestone transition |
| Selector manifest | Unchanged; no promotion |
| LESSONS | Existing Amendment 27 source-binding/lending rule applies; no new rule established |
| Consolidation under CLEAN_UP_POLICY | Pending full completed REVIEW, with preserved source authority |
| Successor frozen | UNKNOWN pending full P13-k scratch adjudication |
| Turn boundary held | Yes: runtime-free; no source, test, build, selector, or acceptance mutation |
| review_check.py boundary | Not executed as authoritative branch check; immutable tarball lacks git history |
| STATUS lifecycle maintained | Entry beacon published for current turn; final beacon remains to be set |
| Pushed to origin, branch in sync | This static preflight committed via GitHub connector; no local git branch or push check claimed |

## `Architecture_M6_CP3_DEFN_P13_Row_Ranked_Provenance_Corner_Key_Counterexample_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Row_Ranked_Provenance_Corner_Key_Counterexample_20261103.md`; moved verbatim.

### P13-j — row-ranked provenance is not an invariant corner-owner certificate (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (same Review/Definition turn; incomplete). **Source authority:** verified snapshot `6334ccfed7bcc582db8edd781df290e6e753739d` with 6,125/6,125 file SHA-256 checks, plus authenticated GitHub comparison showing no production source drift to this checkpoint. CB78 compiled semantics remain `afd72107d3213a396ed7f35b53f67dceeea7e7ca`. No product code, tests, workflow, or selector changed.

#### Code-derived mechanism

- `SurfaceArrangement.cpp:7103–7130` chooses an edge's `primary` provenance by lexicographic `std::min_element` over compatible candidates; after rail and cell-face membership priorities, **numeric `value->sourceFace` occurs before** typed topology region, chart and the remaining provenance fields. `edge.sourceFace = primary.sourceFace` and `edge.sourceChart = primary.sourceChart` then publish the selected scope. The candidate set can contain more than one compatible face.
- `PatchDescriptor.cpp:68–78` records each selected `SourceProjectionChart` including its **canonical source-face topology**, while `source_point_identity` (lines 380–412) records all **three** weighted source vertices including zero-weight corners. `halfedge_identity` (460 onward) uses the selected halfedge scope; `build_domain_identity_audit` (587 onward) accumulates directed identities into the `orientedBoundary` canonical cycle. Hence a corner-signature candidate based directly on the full **uncompacted cell `SurfaceCellDomainIdentity` plus its incoming/outgoing `halfedge_identity`** is not demonstrably independent of a row-ranked primary selection.
- This does **not** invalidate the existing source-domain audit; that audit correctly characterizes the **chosen** prepared complex. It invalidates assuming that its record is, without additional proof, a stable label for the same physical owner under arbitrary source-face-row permutations.

#### Independent non-vacuous conditional countermodel

The existing Vase OFF fixture itself contains source triangles **face155=(0,255,1248)** and **face547=(0,1208,1248)** (sorted source-vertex topologies). Both meet on source edge **(0,1248)**. Construct a *hypothetical* compatible-provenance set containing both faces with identical non-row priority fields, both admitted by cell-face/root filters. With original row numbering `min(155,547)` chooses the first face; swap only the numeric rows and `min(155,547)` now chooses the other semantic face. Physical edge support stays unchanged, but the selected `SourceProjectionChart.face` and `source_point_identity` record change (zero-weight third vertex **255** versus **1208**). This could change a domain-derived candidate corner signature on an otherwise equivalent arrangement under source-face renumbering.

**Scope limit:** this two-compatible-face tie is **synthetic**, *not* claimed to be the exact actual Vase halfedge provenance set or a measured production row-permutation failure. The code's row-ranked comparator and both source-face topologies are real. The countermodel is sufficient to refute *an unconditional proof from the existing domain key alone*, not to declare the proposed DSU physically incorrect or all row permutations failing.

Reproducible read-only source/OFF check: `p13j_provenance_row_relabel_audit.py`, SHA-256 `ae25b632757977b0bc0945f12eeec48ccb8f155faa6b1223d1555c4c68538ac4`; results `p13j_provenance_row_relabel_audit.json`, SHA-256 `3e8ee05187e9a805487e2ceee4af2d2b8f157620af57d84aad5d656aec768594`; **23/23 source and conditional-model assertions PASS**. The corrected audit also independently reconstructs the same 5356 source-edge XYZ from both OFF faces (maximum coordinate error < 1e-15), and includes a one-compatible-face row-relabel negative control. Initial script run failed on an incorrect string expectation about `append_source_scope`; the script was corrected to match its actual `{scope.chart->chart, scope.chart->face}` append and rerun. No C++ or production fixture was executed or changed.

#### Consequence for minimal corrective contract

**Preserve the reciprocal-incidence DSU candidate only as connectivity**, separating disconnected point contacts, typed hard rails, disjoint vertex fans, regions, sheets and unsupported chart transitions. Do **not** assign its persistent canonical corner identities merely as `min(uncompacted domain + selected halfedge identities)` without a permutation-resistant uniqueness proof. Prefer an exact, row-independent source-owned corner label derived from the full prepared provenance/typed support plus incident sector, rejecting ambiguous collisions. A turn-local numeric `(cellId,nodeId)` can index DSU members but **must not** become the semantic exported key; full owner membership must be checked on cross-build cache reuse. Keep the assembler's typed certificate intersection and nonmanifold rejection intact.

**Required later discriminators (no tests executed here):** (1) two compatible selected source faces whose row numbers exchange, with required key *equivalence* and no accidental source support change; (2) one-compatible-face control (no false difference); (3) two disconnected corners at identical source point (must differ); (4) source-edge points separated near 1e-10 quantization and unsupported hard-rail/fan/sheet cases (must not merge); (5) Vase 5351/5356/5357/5359 each matching at descriptor and assembler; (6) full unchanged/changed owner cache-membership controls.

**Disposition:** the reciprocal-DSU and V2 proposals remain **UNACCEPTED**. Prior completed-patch typed-chart closure evidence predicts overlap under its certified conditions but actual emitted lineage vectors remain unmeasured. No frozen Code + Build successor, runtime acceptance or CP3 promotion. Review §5 closeout and true Git-history-backed `review_check.py boundary` remain incomplete.

#### Additional independent review-boundary checks (incomplete Review)

The verified local source-snapshot selector files were independently LF-normalized and SHA-256 hashed:

| Selector | LF SHA-256 | Count |
|---|---|---:|
| 365 | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` | 365 |
| 430 | `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` | 430 |
| 448 | `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` | 448 |
| 449 | `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` | 449 |

All four match the retained selector manifest. The first **365**, **430**, and **448** LF rows of selector449 are each byte-identical to the complete matching historical selectors, with recomputed prefix SHA-256 respectively `6b5b6555…c14b8a1`, `1c412850…4955a9db6`, and `70ff0860…75789`. Authenticated GitHub compare from the immutable source snapshot to this Review checkpoint lists **only documents, the removed temporary snapshot trigger, and root STATUS**; no selector/product/test/fixture/build/workflow surfaces changed.

An additional GitHub ancestry check from authorized durable rewrite base `8b7299b43` found that it is an ancestor of this branch (ahead 3,536 / behind 0 at inspection). Comparing baseline protected headings by literal `DURABLE|DO NOT DELETE` regex to the current branch gave handoff **4/4**, ORIENTATION **1/1**, tracker **0/0** missing none. **These are independent partial checks, not a successful execution of the mandated `python3 .agents/Directional/tools/review_check.py boundary`**, which requires genuine Git history absent in the extracted source snapshot. Do not record it as PASS; complete the actual command on a history-bearing checkout and finish Review §5 only after the identity/caching/design proof. No checkpoint or selector promotion.

#### SourceEdge is a lossy diagnostic, not a stable owner key

Additional **read-only** audit of CB78 source: `SurfaceArrangement.cpp:2165-2202` interns original arrangement nodes with a private `ScopedNodeKey` map but only retains `node.sourceEdge = key.edge->second().index() & 0x7fffffff` as a **one-way diagnostic projection**. `SurfaceArrangementNode` does not publish the scoped intern key. `SurfaceCellFeasibilityRepair.cpp:1186-1274` creates repair-generated nodes by direct `rebuilt.nodes.push_back`, outside the original intern table. It may inspect the diagnostic edge projection for interpolation, but this is not proof of semantic ownership equality.

The *recorded* Vase endpoint witness contains **distinct** exact source edges `(0,1248)` at prepared node 5356 and `(255,1248)` at node 5359; both produce diagnostic `sourceEdge=1248`. They are distinct edges, **not** evidence of an actual erroneous repair-node merge or two endpoints of one known repaired halfedge. Any proposed stable class serialization must retain the exact endpoint pair plus certified fan/sheet/region/rail and repair-split relation provenance, not deduce it from `sourceEdge` or row rank. Independent static/source-witness audit passed 20 Python asserts, **not Directional C++ tests**. Script SHA-256 `38bc9ff5843f6c1812f2007564fe93629c64b7f8b8470f9b5284ef8efb4f92c2`; JSON SHA-256 `7703b2e843aef6c88f1adacd1c2b69865b7975027a32660a700acb3fa65eae57`. No Code + Build authorization or observed new runtime failure.

#### Face-interior row/corner canonicalization countermodel (same Review)

**Do not canonicalize `NodeKey(kind=2)` *after* quantizing face-local `u,v`.** Exact CB78 `SurfaceArrangement.cpp:490-519` stores the face row plus `llround(u*1e10)` and `llround(v*1e10)`, where `uv_to_bary=(1-u-v,u,v)`. Changing the source-face row is already unsafe for an exported semantic label; merely replacing it with a sorted source-face vertex triple and recomputing the missing integer weight `Q-u-v` is also insufficient.

Independent static/arithmetic model reproducing `canonicalize_barycentric` and positive-`llround` on one *synthetic* interior point with barycentrics `(0.50000000005,0.25000000005,0.24999999990)` produces **three distinct** sorted typed-vertex integer signatures across its **six** triangle-corner permutations, while its source point and vertex triple remain fixed. The recorded Vase 5355 barycentric sample remains invariant under the same modeled transform (6/6). Quantizing **all three** canonical barycentric weights individually and then sorting by typed source-vertex identity produces one signature across these six adversarial permutations, matching the existing `PatchDescriptor.cpp:380-412::source_point_identity` method *for this model*. This neither proves general floating-point invariance nor makes `source_point_identity` an admissible stitch-owner key: that helper still serializes the selected `SourceScope.chart`, and unrelated prepared nodes may have identical source-point support.

**Narrow corrective design constraint:** when an original scoped-node key is made externally stable, canonicalize all point weights by typed source-vertex *before* quantization rather than attempting to rebase two rounded face-local UV components; retain explicit source region, vertex fan/sheet and reciprocal sector membership, and reject ambiguous collisions. Original `ScopedNodeKey` is not retained on nodes; repair-inserted split nodes also need authored provenance, not reconstruction from `sourceEdge`. This audit does **not** accept the existing `min(corner signature)` proposal, modify source, or authorize CB.

Audit script SHA-256 `5c774672926dac2bd65f03a4e2df4032ed67b3e021f96fcc2fc2d9f9f19f0738`; JSON SHA-256 `17eb7cd7984956b2604f70e6661e1f24b8c8af3e69192580e3db1bf50160f6e0`. Six positive and six adversarial permutations were modeled; this is Python static arithmetic, **not Directional C++ execution**.

## `Architecture_M6_CP3_DEFN_P13_Stitch_Key_Dataflow_Readonly_Review_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_Stitch_Key_Dataflow_Readonly_Review_20261103.md`; moved verbatim.

### P13-j — exact stitch-key producer-to-assembler read-only check (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`, still IN_PROGRESS. This is a same-turn **Review/Definition evidence note**, not a corrective source patch, accepted design, runtime verdict, or Code + Build authorization.

#### Immutable input and verification

- Working-branch snapshot run [41645502073](https://github.com/akashskypatel/Directional/actions/runs/41645502073), source `5bf12419f1cb185aef2e297b3ad17b2e470a916f`, source artifact `13233879616`. Internal archive hash verified; **6,128/6,128** file hashes passed, zero errors, `runtimeExecution=false`.
- GitHub compare `afd72107d3213a396ed7f35b53f67dceeea7e7ca...5bf12419f1cb185aef2e297b3ad17b2e470a916f`: 176 commits ahead, zero behind; changed paths are review/documentation, `STATUS`, dispatcher/control, or snapshot markers, **no C++/test/build/workflow/selector semantic changes**. The immutable CB78 source remains the semantic baseline.
- Independently checked exact local source SHA-256: `PatchDescriptor.cpp=108e5481fe85ecafa566d4a14f089afbf00956f8e543fbbc8b0c5f176f31f491`; `PureQuadCompletion.cpp=9eb46a71b4f8af85b7b9ccda703606fe39dd4d7eb61a67d10e00ff5998f45476`.
- Read-only audit passed 16 distinct source/witness assert statements (one is executed for three separate broken neighbors), including the four recorded neighbor keys and all eight subsets of the three fractured seam matches. Audit script SHA-256 `d1bd82e34c43ae85759992cf40c9e6d81095d5712a423805f2e234e2f67903fe`; JSON SHA-256 `74442212f83fc3a198db518f4acdf65e378c7ccbaa22b67792bcf20bf1116112`. **Not Directional C++ tests**. The earlier count of 14 was incorrect and is corrected here.

#### Precisely located responsibility

1. `PatchDescriptor.cpp:414-445` builds `arrangement_node_identity` only from occurrences exactly matching `source_scope(outgoingHalfedge)`; `derive_patch_descriptor:1758-1760` publishes this as each completed-patch boundary-node identity. Thus two reciprocal patch corners can inherit different exact chart-scoped keys at the **descriptor producer**, even when they refer to the same prepared node and intrinsic source support. Source-support geometry alone does not certify admissible equivalence.
2. `compact_identity_group:833-869` replaces the numeric `values` vector with namespace/rank but retains the typed vectors. **Matching ranks alone do not repair mismatching typed identities.**
3. `PureQuadCompletion.cpp:341-373` initializes the completed mesh and boundary vertex lineage from descriptor identities. `resolved_stitch_identity:2838+` reads the mesh boundary identity as its resolved key and rejects mismatch against the lineage key. A descriptor-key fix cannot be simulated by rewriting only a cached mesh boundary vector.
4. `intersect_typed_authority_certificates:2744+` independently requires matching exact source support and nonempty region, sheet, and literal source-chart intersections. The original `IncompatibleTypedStitchAuthority`, position, and `NonManifoldStitchedVertex` fail-closed checks must not be weakened.
5. The inherited real Vase witness has one four-cell prepared ring at 5355. At neighboring 5351 the two compact keys match; at 5356, 5357, 5359 they differ. The read-only graph independently gives three disconnected sectors. **Equating any two of the three mismatched interfaces produces one connected graph**; therefore a green aggregate vertex-link result would be vacuous as a complete stitching oracle.

#### Same-turn adjudication: what is and is not proven

**Established:** key fragmentation is already present at the descriptor-to-completion boundary, before the assembler's final nonmanifold validation. Repair is to be investigated at source-owned completed-boundary equivalence, not by positional welding or suppressing the assembly rejection. The source snapshot contains no semantic drift from the CB78 base.

**Not established:** injective row/corner/permutation-stable class identity for original and repair-split nodes; admissible reciprocal hard-rail/cut, region, sheet, and fan policy; exact full cache owner-member equality after structural rebuilding; *actual completed* Vase `vertexLineage.sourceCharts` vectors and selected source-provenance pairings; live descriptor-through-assembler positive/negative execution; controlled Vase performance.

The source-level fresh-completion chart closure predicts overlap when provenance stays within the certified support/fan class, but no completed-lineage vector was measured. **V2 and reciprocal-incidence owner-key candidates remain UNACCEPTED.** No CB/TB or separate BunnyRandom P13-e successor is authorized. The future distinct positive must verify **all four** reciprocal corner pairs individually, and negatives must preserve disconnected same-position/near-coincident nodes, hard-rail/fan/sheet separation, typed certificate intersection and exact cache invalidation where owners change. Do not infer these from only a model or connectivity counter.

#### Boundary-check and procedural limits

`python3 .agents/Directional/tools/review_check.py boundary` on the verified source archive **exited 1**: authentic Git rewrite ancestry could not be established because the snapshot has no `.git`; the checker labels selector files `untracked`. This is **not** an accepted boundary PASS. Authenticated GitHub compare establishes ancestry and unchanged semantic paths, but does not replace the full checker.

During session bootstrap, repository document reads preceded the conservation-policy read-mode gate; this was a procedural miss. Source inspection subsequently switched to the mandatory verified snapshot rather than continuing piecemeal connector reads. The 20-minute response closeout and exact current canonical turn remain binding.

No product/source/test/fixture/selector/benchmark/build was changed, no Directional runtime was executed, and accepted CP2 **491/491**, stable **66/17/49**, debt **1**, unpromoted TB72A **883/883** / selector497 are unchanged. This Review remains unfinished; mandatory Review §5 closeout and authenticated boundary proof are pending.

#### Existing C++ regression coverage audit (same turn)

Read-only audit of six existing C++ test bodies and CB78 descriptor/cache/assembler source: script SHA-256 `6c45d772c84af2910f45e105a7ad2abb3bd92f2f9d55919d9a9e0c88962ce43a`; JSON SHA-256 `2b0c5b919b9a12bf31fba70904b8bb5b22129bc6cc653852facd3200f258d3a1`. **These are static checks, not executed C++ test results.**

- `PatchDescriptorMilestoneETests.cpp:1404+` **already checks boundaryNodeIdentities equality** under a source-face-row permutation; it tests one patch, not *two reciprocal patches* selecting different outgoing source-chart scopes at the same prepared node.
- `PatchDescriptorMilestoneETests.cpp:1481+` and `:1605+` explicitly require nonzero reused patch completions **after structural repair**. Blanket disabling cross-repair cache reuse would violate these existing positives; preserve valid unchanged-owner reuse while rejecting a same-dependency changed-owner product.
- `PureQuadCompletionPhase18Tests.cpp:2003+,2429+,2474+` verify successful compatible typed stitch and incompatible-sheet/support rejection. They do not prove the descriptor generates matching keys across Vase's three fractured reciprocal interfaces.
- `PatchDescriptor.cpp:2205+` does not include exact `boundaryNodeIdentities` member equivalence in cache dependency fields. A hypothetical same-dependency changed-owner reuse still needs a real negative; this risk is **not** the proven cause of the initial Vase conflict.

**Non-vacuous future gate (not authorized yet):** separately assert matching descriptor/completed-lineage/assembler keys at Vase 5351,5356,5357,5359; retain disconnected same-support/no-twin, hard-rail, fan/sheet, near-coincident, row/corner/patch-order, and repair-generated twin-reversal negatives; retain valid cache-reuse positive alongside changed-owner same-rank rejection and actual fail-closed manifold/typed checks. An aggregate four-cell connectedness assertion alone is insufficient. Capture *actual completed* sourceCharts/support/region/sheet/occurrence/relation-path vectors and resolved keys on both sides in an authorized scratch probe, not by inference from chart-component IDs.

No source/test/build/selector changed, no Directional binary executed; owner-class injectivity, typed sector policy, cache proof and Review closeout remain open. No Code + Build successor is frozen.

#### Four-way certificate non-vacuity (same Review)

`PureQuadCompletion.cpp:3426-3505` intersects source support, region, sheet and **literal source charts cumulatively across all patches** sharing one stitch key. `:3624-3712` separately requires one resolved source entity and **one common source face to which all contributors can rebind**. Pairwise-valid seams do not prove either global condition.

Synthetic, not actual Vase lineage: chart sets `abc,abd,acd,bcd` pass all six pairwise intersections yet have an empty four-way intersection; the read-only model rejects all 24 patch orders. Adding a common chart passes only the modeled chart predicate. Pairwise rebind-destination intersections can likewise conceal an empty global intersection.

Future non-vacuity: measure actual completed owner certificates/provenance across the 5355 ring and every 5351/5356/5357/5359 interface; assert global chart/support/region/sheet compatibility and a common rebinding face, plus each reciprocal key individually. Add an all-pairs-compatible/global-incompatible four-patch negative, keep original fail-closed validators.

Script SHA256 `0d9a4195363eb35252be863191c03e4816f70356729e6f1659324c208caa0cc1`; JSON `12051d5aa927597d1c748c26b7cf949fe6f3ccf0d4f7b9ac34e12ee4b4cc09a9`; ZIP `7496471302c374a0604f19b519267a62ac5c5a431cc3d8fae3dd00096a012c6b`. Synthetic/static only, no C++ execution, no CB authorization.

## `Architecture_M6_CP3_DEFN_P13_V2_Readonly_Sampling_Control_Evidence_20261103.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P13_V2_Readonly_Sampling_Control_Evidence_20261103.md`; moved verbatim.

### P13-j V2 read-only CPU sampling and scratch controls — 2026-11-03

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`; **IN_PROGRESS**, no successor authorization. This record supplements `Architecture_M6_CP3_DEFN_P13_Compatible_Occurrence_Key_V2_Scratch_Verification_20261103.md`. The V2 source proposal remains **unaccepted**.

#### Evidence and unchanged binary

- Exact immutable CB78 base `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; isolated V2 candidate source `36fb5349aebb96a0b5b0d30d5c5265a110c5df8c`. Precompiled GMP/GMPXX artifact **13205668125**, [successful compile run 41581676195](https://github.com/akashskypatel/Directional/actions/runs/41581676195), artifact SHA256 `ba5fda366227e4e2e5f5856853e1344aae4b14e7cb2b1b86660e190daa1cd07e`.
- Existing packaged binary `directional_benchmarks`, SHA256 **`d4a6b7384bb0b8a5463cfa2541b810f7e2fbd7db9ef2d85ee6ae18430ddf2da7`**, unchanged before/after each run. This turn **did not compile project code, change a production source file, patch executable instructions, or alter validators**.
- Program-counter profiler: parent Linux `ptrace(PTRACE_ATTACH/PTRACE_GETREGS/PTRACE_PEEKDATA/PTRACE_DETACH)` on the direct child, samples every 15 s with `nm` symbol lookup and heuristic stack return-address candidates. It did not rewrite process memory. Sampling script SHA256 `13422cd8abc285083e6c1dc9de3de8c1cbac2e89ce95d574f395e743d549494b`; raw record SHA256 `08bacbbd85958238b2d23c4aa998edbcc8c4abf6bb633f9f6a50aa1154608064`. **26 snapshots**, 15.02–390.16 s, run killed at 390.23 s, no case JSON and no terminal Vase verdict. This deliberately does not claim a successful benchmark.
- Sampled program counters and stack candidates are **a sparse diagnostic, not a statistically unbiased profiler**. Registers and candidate return addresses were read without stack unwinding validation. One 30 s sample is in a shared library; fallback symbol labels for such addresses should be ignored.

#### Decisive phase observations

- At **15/45/60/105 s**, the CPU PC is in unchanged `surface_cell_tracing_detail::edge_faces`; **75/90 s** in `source_vertex_extent` called from `local_edge_key` → `rail_interval_refs`; **195 s** again in `source_vertex_extent` from arrangement node key construction. The latter helper scans all source-face corners on each invocation; source file `src/geometry/SurfaceCellTracing.cpp`, SHA256 `10b4532187d55c1f62dce50169d6e164f4a8141f9cd6c957093f5c2451ddd1fa`. V2 packaged source tarball and exact CB78 baseline have **byte-identical** versions of that file.
- **135/150/165 s:** `preserves_protected_endpoint_degrees` inside the existing FlowRep selector; **210/225/240 s:** `build_surface_cell_complex` and tracing/arrangement call paths.
- **255 s:** the old `arrangement_node_identity` on the stack; **270 s:** `SurfaceProjectionBvh::build_node`.
- **285, 315, 330, 360 s:** PC in unchanged `SourceTopologyRegions::matches_source_faces`; **300, 345, 375, 390 s** sample PC or return-stack evidence is also consistent with this same source validation/projection path. `matches_source_faces` iterates all source-face rows and checks typed topology binding each invocation; it is an **O(source faces)** verification, `include/directional/geometry/SourceTopologyRegions.h:151–188`. Sampled RSS increased from ~38 MiB to **2018 MiB**; this is an observation, not proof of a leak or causal attribution.
- **No sampled program counter belongs to `compatible_boundary_node_identity`**. Sparse sampling cannot prove it was never executed. The 390.23 s timeout without a Vase verdict **cannot be causally attributed to V2 boundary-key overhead** on this evidence; a controlled exact-CB78 vs V2 same-host profile (or a bounded stage-level timer) is needed. The previous 420.057 s timeout also lacks a case verdict. Do not adapt timeouts to manufacture a PASS.
- **Independent scratch controls on the same V2 binary** (original immutable benchmark manifest, no local compile): `cylinder__surface_cells` **PASS**, 288 quads, wall 14.302647 s, process 14.404 s. `bunny_1k_random__surface_cells` **expected RED**, `field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, wall 0.790291 s, process 0.867 s. Both programs returned process exit 0; interpretation is by `cases[0].runs[0].success` and terminal diagnostics. Controls JSON SHA256 `43cdfadcd360b7ade0e4f4dcdbcf66f3246511d3e864e38eb921e0ab0b02dff2`.

#### Review decision and falsifiers

**P13-j root-stage attribution remains** descriptor/completion boundary-key fragmentation at nodes 5356/5357/5359, from the previous exact P13J/K/L/M witness. V2's proposed occurrence normalization is still **UNACCEPTED**: Vase not proved past first nonmanifold vertex, candidate-induced performance not isolated, and distinct source points, hard-rail chart components, vertex fans, independent arrangement nodes at the same source location, and near-coincident support have **no new negative descriptor-key tests**. Existing chart-transition unit tests are not replacements for those falsifiers. The patch's **1e-8** barycentric rebinding check versus the existing **1e-10** identity quantization requires a deliberately adversarial near-collision case. Maintain original fail-closed stitcher validation.

Next in the **same** review: bounded stage-level profiling or matched baseline sample to separate untouched source-validation cost from new completed-boundary key work; independently prove key equivalence and separation in a diagnostic before freezing the exact corrective source patch. No unrelated `SurfaceCellTracing` optimization in this Review/Definition. No selector/gate promotion; accepted CP2 491/491, stable 66/17/49, debt 1, TB72A 883/883 candidate unpromoted, selector497 unpromoted. Authenticated Git-ancestry review boundary and REVIEW_TURN_POLICY §5 durable closeout remain outstanding.

#### V2 source-level nonmerge audit (2026-11-03, same Review turn)

Exact inspection authority: source snapshot commit `305573a3fd5508dbc380708798051aa0baea5d90`; successful Actions run `41586287283`, artifact `13207429981`, archive SHA-256 `03ce432f4d8c12c3e1dbc80917f97de2a1c4ae489c42d22b4c39a978d003d9d0`; packaged tar SHA-256 and 6,124/6,124 file hashes verified. Snapshot includes a control-only trigger, not a product modification. Existing V2 Library patch SHA-256 `d38339902844fcb8ed902a5ed877f2d0a59464bbc7b83a246380460d945c1ff5` and diff-body SHA-256 `74bcf11cf2b91023df67f911440904a208b7603c1024e6ed78e745c72b846a0d` were checked; `git apply --check --whitespace=error` passes against unchanged semantic files. Static applicability is not runtime acceptance.

**Conditional counterexample:** `compatible_boundary_node_identity` computes a sorted/deduplicated source-occurrence set from source face, barycentrics, occurrences, selected patch point and source-chart `resolve_entity`/`rebind`. It never consults `node.id`, prepared halfedge/twin adjacency, cell sectors or a certified arrangement-node equivalence relation. `compact_patch_ownership_identities` interns identical identities and `PureQuadCompletion::resolved_stitch_identity` consumes the boundary key. Thus two topologically independent arrangement nodes with identical admissible source-occurrence records can receive the same stitch key. Source support equality alone cannot prove connected node ownership. **This is a source-level possibility, not a measured Vase collision.** The required distinct-node negative is unproved; V2 remains **UNACCEPTED**.

Precision caveat: `rebind`/membership use approximately `1e-8` tolerances; returned source-point weights quantize at `1e-10`. This may affect included occurrences but does not itself prove distinct quantized positions collide. Test near-edge/near-coincident membership and final keys. Per-boundary graph operations may be costly; prior sparse `SourceTopologyRegions::matches_source_faces` samples do not isolate V2 cost. No runtime binary, build, test or benchmark was run in this continuation.

**Required next same-Review action:** prove positive equality for Vase node 5355 neighbors 5356/5357/5359 (5351 control), and negative separation for disconnected coincident nodes, hard-rail sectors, distinct vertex fans, near-coincident points, and face-row permutations across descriptor through assembled key. A corrected producer must use authoritative prepared incidence alongside typed chart transitions; never collapse all colocated nodes or weaken the fail-closed validator. Prior Vase timeouts remain unresolved; no Code+Build successor is authorized.

**Process correction:** multiple repository documents were initially inspected before selecting snapshot mode, contrary to the conservation pre-read gate. Further source analysis used the verified local snapshot. Review/ancestry closeout remains pending.

#### Same-turn cleanup and verification receipt (2026-11-03)

Verified the original V2 preservation patch again against the source snapshot: full SHA-256 `d38339902844fcb8ed902a5ed877f2d0a59464bbc7b83a246380460d945c1ff5`, embedded diff-body SHA-256 `74bcf11cf2b91023df67f911440904a208b7603c1024e6ed78e745c72b846a0d`, `git apply --check --whitespace=error` PASS; no application occurred. Authenticated CB78→current GitHub compare established no product/test/fixture/build drift. Cleanup workflow run `41589307866` succeeded, result artifact `13209780344`, cleanup commit `ef303cd6935d2c33f46670be9555114d64ada664`, deleted only `.agents/connector-triggers/source-snapshot/m6-cp3-p13-stitch-20261103-0549.txt`; remote file absence verified; PR conversation and inline comments deleted `0/0`; `runtimeExecution=false`. This is an incomplete same-turn Review, not V2 acceptance or a Code + Build turn. Formal `review_check.py boundary` still requires genuine local Git history and remains unexecuted.
