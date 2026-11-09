# M6 consolidated record, volume A: M6 definitions (R1–R5), CP1 and CP2 records, and the DIAG-RETAIN records

This volume holds **38** former standalone `Architecture_M6*` records, moved here on 2026-11-09 by user instruction ("consolidate these records and prune if the content from each is already documented elsewhere"). No record's content was already documented elsewhere: verbatim-line coverage in the permanent documents was at most 27%. So each record is kept **verbatim** as one section below, and nothing is summarized. Only two things changed: heading levels are demoted by two, and links to other moved records point to their sections. Each original file existed standalone at commit `7a460a5e41c4a77a51b69db672e69f910532718c` (`git show 7a460a5e41c4a77a51b69db672e69f910532718c:.agents/Directional/<name>`). Anchors inside a record (`#…`) may resolve to an earlier record in this volume that has the same heading text. The [moved-record map](M6_Consolidated_Record.md#m6-moved-record-map-2026-11-09) lists every record and its volume.

| Original file | Title |
|---|---|
| [`Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`](#architecture_m6_cp1_cb12_close_out_code_build_planmd) | M6-CP1-CB12-CLOSE — CP1 Close-Out Code + Build Plan |
| [`Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md`](#architecture_m6_cp1_cb12_close_stop_review_recordmd) | M6-CP1-CB12-CLOSE-REV — Review of the CB12 C5 Stop |
| [`Architecture_M6_CP1_TB10_A5V_R1_Review_Record.md`](#architecture_m6_cp1_tb10_a5v_r1_review_recordmd) | M6-CP1-TB10-A5V-R1-REV — Independent Recovery Review Record |
| [`Architecture_M6_CP1_TB10_A5V_Review_Record.md`](#architecture_m6_cp1_tb10_a5v_review_recordmd) | M6-CP1-TB10-A5V Review Record |
| [`Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`](#architecture_m6_cp1_tb11_g4_r1_review_recordmd) | M6-CP1-TB11-G4-R1-REV — Independent Recovery Review Record |
| [`Architecture_M6_CP1_TB11_G4_Review_Record.md`](#architecture_m6_cp1_tb11_g4_review_recordmd) | M6-CP1-TB11-G4-REV — Independent Review Record |
| [`Architecture_M6_CP1_TB12_Close_R1_Review_Record.md`](#architecture_m6_cp1_tb12_close_r1_review_recordmd) | M6-CP1-TB12-CLOSE-R1-REV — Recovery Review Record |
| [`Architecture_M6_CP1_TB7_A6_Review_Record.md`](#architecture_m6_cp1_tb7_a6_review_recordmd) | M6-CP1-TB7-A6 Review — HardRail Placement-Gauge Recovery |
| [`Architecture_M6_CP1_TB8_A6_Review_Record.md`](#architecture_m6_cp1_tb8_a6_review_recordmd) | M6-CP1-TB8-A6-REV — Independent Runtime-Free Review Record |
| [`Architecture_M6_CP1_TB9_A7_R1_Review_Record.md`](#architecture_m6_cp1_tb9_a7_r1_review_recordmd) | M6-CP1-TB9-A7-R1-REV — Recovery Review Record |
| [`Architecture_M6_CP1_TB9_A7_Review_Record.md`](#architecture_m6_cp1_tb9_a7_review_recordmd) | M6-CP1-TB9-A7-REV — Independent Runtime-Free Review Record |
| [`Architecture_M6_CP2_CB2_Coverage_Code_Build_Plan.md`](#architecture_m6_cp2_cb2_coverage_code_build_planmd) | M6-CP2-CB2-COVERAGE — CP2 Verifier Binding + Negative-Coverage Code + Build Plan |
| [`Architecture_M6_CP2_Close_Review_Record.md`](#architecture_m6_cp2_close_review_recordmd) | M6-CP2-CLOSE-REV — Independent Close Review Record |
| [`Architecture_M6_CP2_TB1_Verifier_R1_Review_Record.md`](#architecture_m6_cp2_tb1_verifier_r1_review_recordmd) | M6-CP2-TB1-VERIFIER-R1-REV — Independent Review Record |
| [`Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`](#architecture_m6_cp2_tb1_verifier_r2_review_recordmd) | M6-CP2-TB1-VERIFIER-R2-REV — Independent Review Record |
| [`Architecture_M6_CP2_TB1_Verifier_Review_Record.md`](#architecture_m6_cp2_tb1_verifier_review_recordmd) | Architecture M6 CP2 TB1 Verifier Review Record |
| [`Architecture_M6_DEFN_R1_Review_Record.md`](#architecture_m6_defn_r1_review_recordmd) | M6-DEFN-R1 Independent Review Record |
| [`Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`](#architecture_m6_defn_r1_seam_incident_occurrence_sheet_authority_definition_recordmd) | M6-DEFN-R1 Seam-Incident Occurrence Sheet Authority — Definition Record |
| [`Architecture_M6_DEFN_R2_Review_Record.md`](#architecture_m6_defn_r2_review_recordmd) | M6-DEFN-R2 Independent Review Record |
| [`Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`](#architecture_m6_defn_r2_seam_incident_authority_amendment_definition_recordmd) | M6-DEFN-R2 — Seam-Incident Authority Amendment Definition Record |
| [`Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md`](#architecture_m6_defn_r3_a6_product_separation_definition_recordmd) | M6-DEFN-R3 — A6 quotient-product separation definition record |
| [`Architecture_M6_DEFN_R3_Review_Record.md`](#architecture_m6_defn_r3_review_recordmd) | M6-DEFN-R3-REV — independent A6 quotient-product definition review |
| [`Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`](#architecture_m6_defn_r4_a7_boundary_definition_recordmd) | M6-DEFN-R4 — A7 Product, Thin Adapter, and G4-B002 A6 Boundary — Definition Record |
| [`Architecture_M6_DEFN_R4_Review_Record.md`](#architecture_m6_defn_r4_review_recordmd) | M6-DEFN-R4-REV — Independent Review of the A7 / Thin-Adapter / G4-B002 Definition |
| [`Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md`](#architecture_m6_defn_r5_cp3_entry_definition_recordmd) | M6-DEFN-R5 — CP3 Entry Definition Record (WIP) |
| [`Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`](#architecture_m6_defn_r5_r1_cp3_entry_recovery_definition_recordmd) | M6-DEFN-R5-R1 — CP3 Entry Recovery Definition Record |
| [`Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md`](#architecture_m6_defn_r5_r2_cp3_entry_recovery_definition_recordmd) | M6-DEFN-R5-R2 — CP3 Entry Recovery Definition Amendment (RA-34 candidate) |
| [`Architecture_M6_DEFN_R5_R2_Review_Record.md`](#architecture_m6_defn_r5_r2_review_recordmd) | M6-DEFN-R5-R2-REV — Independent Definition Review (RA-34) |
| [`Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md`](#architecture_m6_defn_r5_r3_cp3_entry_recovery_definition_recordmd) | M6-DEFN-R5-R3 — CP3 R2 Recovery Definition, candidate RA-37 |
| [`Architecture_M6_DEFN_R5_R3_Review_Record.md`](#architecture_m6_defn_r5_r3_review_recordmd) | M6-DEFN-R5-R3-REV — Independent RA-37 Definition Review |
| [`Architecture_M6_DEFN_R5_R4_DIAG_Diagnostic_Fidelity_Audit.md`](#architecture_m6_defn_r5_r4_diag_diagnostic_fidelity_auditmd) | M6-DEFN-R5-R4-DIAG — exact carrier-incidence diagnostic-fidelity audit |
| [`Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`](#architecture_m6_defn_r5_r4_independent_review_recordmd) | M6-DEFN-R5-R4-REV — independent definition review (runtime-free) |
| [`Architecture_M6_DEFN_R5_Review_Record.md`](#architecture_m6_defn_r5_review_recordmd) | M6-DEFN-R5-REV — Independent Review of the CP3-Entry Definition |
| [`Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md`](#architecture_m6_defn_diag_retain_a5_a7_snapshots_20261031md) | RA-184 — DIAG-RETAIN: A5–A7 diagnostic snapshots (2026-10-31) |
| [`Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md`](#architecture_m6_defn_diag_retain_cli_materialization_sidecar_20261031md) | RA-186 — DIAG-RETAIN: CLI materialization sidecar (2026-10-31) |
| [`Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md`](#architecture_m6_defn_diag_retain_gui_layers_20261031md) | RA-187 — DIAG-RETAIN: GUI layers; full-gate correction for the CLI slice (2026-10-31) |
| [`Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md`](#architecture_m6_defn_diag_retain_materialization_display_20261031md) | RA-185 — DIAG-RETAIN: materialization display adapter and text dump (2026-10-31) |
| [`Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md`](#architecture_m6_tb60_diag_retain_gui_full_gate_local_test_report_20261031md) | M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC — full gate, CLI cases and GUI link check on the CB61 packages (2026-10 |

## `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`; moved verbatim.

### `M6-CP1-CB12-CLOSE` — CP1 Close-Out Code + Build Plan

> **Review-agent block — `M6-CP1-CB12-CLOSE-REV` (RA-26), 2026-10-05.**
> - The CB12 C5 stop is **discharged**. This plan is now executed by the new turn **`M6-CP1-CB12-CLOSE-R1`**.
> - **C1–C4, identities 29/30, focused-30, compile/package and the 479 successor are unchanged.**
> - **C5 is complete.** The binding classification is `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` §3 (RA-26 §3). The R1 report cites it and does no further C5 work.
> - The C5 table below had wrong optimizer anchors. `:3020` is the test-only overlay; the real source-point rebinding is `project_vertices` (`SurfaceMeshOptimizer.cpp:759-:880`).
> - **Forbidden in R1:** any change to `SurfaceMeshOptimizer` or final validation. Anchor-dependent references are re-homed to `M6-DEFN-R5` / `M6-CP3` (RA-26 §5).
> - The C5 stop rule is replaced by RA-26 §2: only an *authority-deciding* consumer stops a turn.

**Owner:** `M6-CP1-CB12-CLOSE`
**Type:** Code + Build only; compile/package; runtime forbidden.
**Authority:**
- `Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`, review-agent addendum §N2–§N3;
- frozen definitions RA-19a §3, RA-22a §3, RA-22b §5, RA-24 and **RA-25**.

**Entering runtime:** `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`, focused-28 + selector449 = **477/477**.

**Successor:**
1. compile-green → `M6-CP1-TB12-CLOSE-EXEC`, **focused-30 + selector449 = 479**;
2. mandatory `M6-CP1-TB12-CLOSE-REV`;
3. `M6-CP1-CLOSE-REV`, a pure verification of the six CP1 exit items on that fresh gate.

#### Goals (exactly these; nothing else)

##### C1 — exact A7 cross-sheet certification (RA-22a §3)

In `SourceAttachedGeometryProducer::produce`, replace the proxy (`RemeshPipeline.cpp` ~6850-6872).

**Today.** A selected-forest edge whose endpoints share no wedge sheet is accepted if *any* isolation evidence exists on the relation, or any `cornerWedgeIsolation` exists on either occurrence.

**Required.** Let `S1` and `S2` be the endpoints' `cornerWedgeSheets`. The crossing is certified only if there is a `CornerWedgeIsolationTransition t` such that:
- `t` comes from the relation's `firstSideIsolationEvidence`, `secondSideIsolationEvidence` or `equivalence.isolationTransitions`, or from either occurrence's `cornerWedgeIsolation`; and
- either `t.fromSheet ∈ S1` and `t.toSheet ∈ S2`, or `t.fromSheet ∈ S2` and `t.toSheet ∈ S1`.

Otherwise fail `UncertifiedCrossSheetBinding` (`:cross-sheet`). `relationEvidenceSufficient` must now mean exactly this.

**Stop for Review** if this rejects any row that was accepted before.

##### C2 — distinct A5 phase-front source diagnostics (RA-19a §3)

Restore three distinct causes, kept apart through to the legacy names:
- **empty phase front** — `cells().empty()` or `edges().empty()` → legacy `MissingAuthoritativePhaseFront`;
- **source shape or face-count mismatch** → legacy `InvalidAuthoritativePhaseFrontSource`;
- **chart-transition unavailability** → legacy `InvalidAuthoritativeSourceChartTransitions`.

Use new `SurfaceOccurrenceComplexErrorCode` values or site tokens, with predicates and order unchanged.

**Empty edges.** A5 previously failed only on empty *cells*. The pre-CB10 adapter also failed on empty *edges*, so restore that predicate as the first A5 check. It is fail-closed either way; this restores the original name.

##### C3 — counter from A5-validated authority

`AuthoritativePhaseFrontMeshResult::consumedInternalIsolationSeams` must come from A5's **validated** isolation-certificate set, not from `phaseFront.isolationSeamTransportCertificates().size()`. Do this by exposing a count on the published `SurfaceOccurrenceComplex` certificate, set by the moved bijection check.

Update identity 24's expectation to read that A5 value.

##### C4 — RA-24 continuation fails closed (RA-25)

In `build_surface_quotient_closed_complex_view`: at an interior valence-4 quotient vertex, if an incident edge has zero, or more than one, incident edges sharing no classed quad with it, return a new A6 error `ClosedComplexStripContinuationMismatch`. Do not skip silently. Everything else stays unchanged.

##### C5 — provenance-face consumer audit (RA-22b §5; static; recorded in the CB12 report)

Classify each consumer that reads a `sourcePoint` or `vertexProvenance` **face** as **class-wide**, **representation-only** or **anchor-assuming**, with a `file:line` justification:

| Consumer | Location | Status |
|---|---|---|
| `project_surface_cell_vertex_chart_authority` | `RemeshPipeline.cpp:8061-8127` | Pre-audited: class-wide (uses `lineage.sourceCharts`) |
| `SourceAuthoritativeMeshValidator` `resolve_compatible_chart` / face-chart checks | `SourceAuthoritativeMeshValidator.cpp:1190-1262` | To classify |
| `SurfaceMeshOptimizer` source-point rebinding | `:2576`, `:3020` | To classify |
| `BenchmarkQuality` field alignment | `:1490-1503` | To classify |

**Stop for Review** if any consumer is anchor-assuming. Do not fix it inside CB12.

##### Tests (append after focused 1-28; create focused-30 with focused-28 as its exact prefix)

**29 — `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`.**
- Positive: a multi-sheet class on an existing split-isolation fixture is accepted.
- Negative: rewrite the relevant transitions' `fromSheet`/`toSheet` to a sheet pair that does not connect the endpoints. A7 must reject with `UncertifiedCrossSheetBinding` and site `cross-sheet`. The C1 rule rejects this case and the old proxy accepted it.

**30 — `M6CP1.A5PhaseFrontSourceFailuresKeepDistinctDiagnostics`.** Three tampers, each producing the exact distinct A5 code and the adapter legacy name:
- empty edges;
- face-count mismatch;
- unavailable chart transitions — use a source-topology authority mismatch if it is reachable; otherwise document unreachability and assert the other two.

**Identity 24** expectation update (C3) only. No other existing test body changes.

#### Static checks and gate

- `git diff --check`.
- selector449, routing449 and the focused-12/20/24/28 bytes are unchanged.
- No change to A5/A6/A7 semantics beyond C1–C4, and no tolerance change.
- Compile with the mandatory reusable GMP/GMPXX workflow, standard eight targets, `runtimeExecution=false`.
- TB12: **30 + 449 = 479** fresh exact-filter processes.

#### Stop rules

Stop for Review if:
- C1 rejects a previously accepted fixture;
- C5 finds an anchor-assuming consumer;
- C2 cannot keep predicates unchanged;
- any goal requires changing quotient membership, support, relation or transport semantics, or the RA-24 strip rule beyond fail-closed.

## `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md`; moved verbatim.

### `M6-CP1-CB12-CLOSE-REV` — Review of the CB12 C5 Stop

**Turn:** `M6-CP1-CB12-CLOSE-REV` (runtime-free Review of a Code + Build stop)

**Reviewed:**
- `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Report.md` (stop report);
- the CB12 plan (C5);
- RA-22b §5 and RA-25;
- exact source.

**Source authority.** Branch HEAD at review start (`33b03f3e`, after the history squash). `src/`, `include/`, `tests/`, `cmake/` and `CMakeLists.txt` are byte-identical to the reviewed runtime `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`. I checked this by fetching that commit and the CB12 snapshot commit `29085d06` by SHA and diffing them. CB12 made no source change.

**Disposition: STOP DISCHARGED.**
- The flagged site is **not a provenance-face consumer** and has **no production caller**. Its classification as "anchor-assuming" is withdrawn.
- I audited every optimizer and final-validation read of a provenance face. **No consumer makes an authority decision from the representative face**, so CP1 closure is not blocked.
- The audit did find **reference-selecting** anchor dependence in the production optimizer energy and in one final-validation metric fallback. That dependence predates CP1 and CP1 did not change it. It is a permutation-invariance defect, and **RA-26** re-homes it to `M6-DEFN-R5` / `M6-CP3` with a pre-registered falsifier.
- Successor: **`M6-CP1-CB12-CLOSE-R1`**, which runs C1–C4 and identities 29/30 exactly as planned; C5 is discharged by RA-26 §3.
- Accounting **60 / 16 / 44**, debt 1.

#### 1. The CB12 stop was correct procedure on a wrong pointer

CB12 followed its plan. The plan's C5 table, which I wrote, named the optimizer consumer as "source-point rebinding `:2576`, `:3020`". Those line anchors were wrong:
- `:3020` sits inside `make_surface_optimization_overlay` (`SurfaceMeshOptimizer.cpp:2900`), in a loop over **source** vertices.
- The actual source-point rebinding is `project_vertices` (`:759-:924`).

The audit was defined as a closed list of line anchors, not a searchable predicate. That let the real consumers fall outside it. **Review-agent error, owned** (lesson 198).

#### 2. The flagged site (`SurfaceMeshOptimizer.cpp:3015-3031`)

```cpp
for (int source = 0; source < sourceSampleCount; ++source) {     // source-mesh vertex
  for (int face = 0; face < constraints.sourceFaces.rows(); ++face)
    for (int corner = 0; corner < 3; ++corner)
      if (constraints.sourceFaces(face, corner) == source) {
        sourcePoint.face = face; ...                               // local variable
        sourceScope = source_face_scope(constraints, face);
        break; }
  ... outputProjection.project(position, sourceScope) ...          // -> overlay.sourceToOutputError
```

1. **It is not a provenance-face consumer.** It reads source-mesh incidence (`constraints.sourceFaces`) for a source vertex. `sourcePoint` is a local variable. It never reads `vertexProvenance`, `provenance[v]` or a lineage `sourcePoint`, so the A7 representative choice cannot change its output. RA-22b §5's subject is the A7 representative face; this site is outside that subject.
2. **It has no production caller.** `make_surface_optimization_overlay` is called only from `tests/SurfaceMeshOptimizerPhase19Tests.cpp` (2 sites) and `tests/SurfaceMeshOptimizerPhase21Tests.cpp` (1 site). It cannot affect a CP1 product, the pipeline result or the gate.
3. **It does have a real defect, of a different kind.** For a source vertex on an isolation seam, the required scope is the sheet of the *lowest-row* incident face. That makes the test-only diagnostic `sourceToOutputError` depend on source-row order. Recorded as **`M6-CP1-CB12-REV-OBS-01`**, owner **M8-CP2** (diagnostics hardening). The final-validation counterpart at `:2573` iterates source faces with each face's *own* scope, which is exact.

CB12's description of the code is accurate; only the category was wrong. CB12 also cleared two consumers, and I re-checked both:
- `BenchmarkQuality.cpp:1478-1504` projects output edge midpoints with an **unscoped** BVH and never reads a provenance face, so it is not a consumer either.
- The validator's face-chart resolution (`SourceAuthoritativeMeshValidator.cpp:1232-1262`) goes through `resolve_compatible_chart` with `vertexChartAuthority`, so it is **class-wide**. Confirmed.

#### 3. Complete audit of production provenance-face reads (optimizer and final validation)

**Production path.** `RemeshPipeline.cpp:12738-12811` runs the authoritative path with:
- `constrainVerticesToProvenanceEntities = true`;
- `vertexProvenance = completedProvenance` (A7 representatives);
- `vertexChartAuthority` from `project_surface_cell_vertex_chart_authority` (class-wide);
- per-face `sourceNormals` and `sourceFieldX`.

That path then calls `optimize_source_authoritative_surface_mesh` (`:12950`) and `validate_source_authoritative_final_surface_mesh` (`:12896`, `:12961`).

**Classes.**
- **Authority-deciding:** the anchor face decides destination, component, sheet or chart membership, lineage, topology, certificate content, or a membership/consistency verdict.
- **Reference-selecting:** the anchor face selects a continuous reference (normal, field direction, projection scope) for an energy or a quality metric. Positions and certificates are unaffected.

| # | Consumer | Site | Class | Basis |
|---|---|---|---|---|
| 1 | `project_surface_cell_vertex_chart_authority` | `RemeshPipeline.cpp:8061-8127` | class-wide | uses `lineage.sourceCharts` |
| 2 | validator face-chart / local-sheet | `SourceAuthoritativeMeshValidator.cpp:1232-1262` | class-wide | `resolve_compatible_chart` + `vertexChartAuthority` |
| 3 | optimizer source-point rebinding `project_vertices` + `project_to_provenance_entity` | `SurfaceMeshOptimizer.cpp:690-755`, `:759-:880` | representation-only | Projects onto the class-common support simplex. A vertex support stays at the vertex, an edge support moves along the edge, a face-interior support stays in its face (a single face, common to the class). The anchor face is carried through unchanged, so positions are anchor-invariant. **Weakness:** the component/sheet checks (`:820-:880`) compare the anchor with itself, so they are vacuous on this path. |
| 4 | optimizer energy normal + field reference | `:1470-1485` (`faceSource = facePoints.front()`), `:1505` | **reference-selecting** | Per-face `sourceNormals`/`sourceFieldX` are read from the representative face of quad corner 0. The reference depends on the anchor and on output corner order. |
| 5 | optimizer gradient reference | `:1957-1965`, `:2001`, `:2124` | **reference-selecting** | Same as #4, plus a finite-difference projection scope from the anchor. |
| 6 | final-validation normal and quality reference | `:2640` (`quad_reference_surface_point`, `:1087`) | class-wide | `resolve_compatible_chart` + `vertexChartAuthority` |
| 7 | final-validation field metric | `:2675` → `best_source_field_alignment` (`:477`) | class-wide, with a **reference-selecting fallback** | The endpoints' support charts (`compatible_source_field_charts`, `:421`) are intersected, which is class-wide. Only when that intersection is empty does it project the midpoint within the **first endpoint's anchor scope**. The fallback feeds `fieldMedianDegrees <= 7.5` and `fieldP95 <= 15` (`:2848-2866`). |
| 8 | final-validation coverage sampling | `:2534`, `:2573` | class-wide / exact | The `compatible_chart_faces` fallback is `consistent_source_scope` (`:1018`, class-wide). Source faces use their own scope. |
| 9 | rail interval sheet support | `SurfaceOptimizationRailConstraints.cpp:50-95` | class-wide | It explicitly accepts another sheet's interval through the shared support entity. |
| 10 | `OutputProjectionCache` scopes | `SurfaceMeshOptimizer.h:619-679` | class-wide | `compatible_chart_faces` + `vertexChartAuthority` |
| 11 | `make_surface_optimization_overlay` | `:2967`, `:3015-3031` | not production | test-only; OBS-01 |
| 12 | `BenchmarkQuality` | `BenchmarkQuality.cpp:1478-1504` | not a consumer | unscoped projection |

**Result: no authority-deciding consumer exists.** Rows 4, 5 and 7 are reference-selecting.

#### 4. Why rows 4, 5 and 7 do not block CP1

1. **CP1 did not introduce or change the anchors.** A7's representative key `(support, cornerWedgeBindings, OccurrenceId)` is the pre-A7 adapter key, retained verbatim by R4 D1 (`M6-DEFN-R4-REV` §1). Every accepted runtime, before and after A7, gave the optimizer and the validator the same anchors.
2. **No product authority depends on them.**
   - Positions stay on the certified common support (row 3).
   - Topology, lineage and certificates never read the energy.
   - Final validation's chart, normal and coverage references are class-wide (rows 2, 6, 8).
3. **They can still change outcomes, and that is the real defect.**
   - Rows 4 and 5 can change optimized positions within supports. Final validation then decides between the optimized geometry and the already-validated completion checkpoint (`RemeshPipeline.cpp:12961-12975`), so this cannot turn success into failure.
   - Row 7's fallback can move a quality percentile across its threshold, and **can** in principle flip acceptance.
   - The anchor depends on source-row order (support and `OccurrenceId`) and output corner order. That is exactly M6-CP3's exit conjunct "source-row / output-row / scheduler permutation invariance". It is not a CP1 exit item.
4. **Repairing it inside CB12 is unbounded.** It would change optimizer energy and validation metrics for every authoritative fixture across selector449, with no witness showing that the anchor matters today. The fix needs a definition (the class-wide quad reference, its cost under finite differences and line search) and a falsifier first. Those are `M6-DEFN-R5`'s job.

**RA-22b §5 as written ("any anchor-assuming consumer blocks CP1 closure") overreached.** It did not separate authority decisions from reference selection. **Review-agent error, owned.** RA-26 corrects it.

#### 5. Routing

| Turn | Scope |
|---|---|
| **`M6-CP1-CB12-CLOSE-R1`** (exact next, new turn) | CB12 plan C1–C4 and identities 29/30, unchanged. C5 is discharged by RA-26 §3 (the report cites it). **No optimizer or validator change.** Focused-30; compile/package; successor TB12 at **479**. |
| `M6-CP1-TB12-CLOSE-EXEC` → `M6-CP1-TB12-CLOSE-REV` → `M6-CP1-CLOSE-REV` | Unchanged. CLOSE-REV also re-verifies RA-26 §3 at its HEAD: there is no authority-deciding provenance-face consumer. |
| `M6-DEFN-R5` (CP3 entry) | Gains RA-26 §5 items (i)–(iv). |

#### 6. Closeout

| Duty | Result |
|---|---|
| Source authority | HEAD source == `8dd95821` (fetched by SHA and diffed); CB12 made no source change. |
| Flagged site | Not a provenance consumer; test-only; OBS-01 → M8-CP2. |
| Full audit | 12 sites classified; no authority-deciding consumer; rows 4, 5, 7 reference-selecting → RA-26 / DEFN-R5 / CP3. |
| Owned errors | Wrong C5 line anchors in the plan; RA-22b §5 class conflation. |
| Accounting | +0 → **60 / 16 / 44**, debt 1. |
| Lesson | 198 — define an audit by a searchable predicate, not by line anchors; separate authority-deciding from reference-selecting consumers. |
| Successor | `M6-CP1-CB12-CLOSE-R1`. |

## `Architecture_M6_CP1_TB10_A5V_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB10_A5V_R1_Review_Record.md`; moved verbatim.

### `M6-CP1-TB10-A5V-R1-REV` — Independent Recovery Review Record

**Turn:** `M6-CP1-TB10-A5V-R1-REV`
**Reviewed candidate:** `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea`
**Reviewed runtime:** `37194004252 / 111411987330`
**Disposition:** **ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED**
**Exact successor:** `M6-CP1-CB11-G4`

#### 1. Independent evidence re-derivation

The R1 recovery gate is mechanically sound and independently re-derived from immutable artifacts.

- Compile candidate ZIP SHA-256: `142bac1bb485ff1f2b8017a08c8457053659867716c7b44edcceb117dca75afd`; root manifest `39259613897fa30935ecdb82f8616986bdb3ce544e82768a4aeeec46043ab708`, **28/28**; packaged source archive `f4bd8408880c8e661124f3ff01be33326a32259edb2296dd5bfe4932795c0710`; exact source `96b456f925be00e00bad6645e6eb905a804c14ea`; compile boundary `runtimeExecution=false`, GMP/GMPXX.
- Runtime result/log ZIP SHA-256: `b9f2daedc62d40c6768d3c257f3b720a1fee9e040ffce8e56f5022e216e8b589` / `b06b0a1bc81dafbe12811fa4991e01aab3c6c5de61dbdab84d99058dfb73d275`.
- Result self-manifest SHA-256 `21bec441216fdd829abce6eedc154868c53156cadca5a9dfcbf9540922e419b2`, **965/965**.
- Focused ledger: 24 rows, all PASS; selector ledger: 449 rows, all PASS; aggregate **473/473**. Every process selected exactly one test, zero skips, benchmark 0. Raw logs contain exactly 473 RUN / 473 OK / 0 SKIP records. RED ledger is header-only.
- Postflight proves package/source/execution-view census equality and unchanged focused/selector/routing authority; package manifest remains **28/28**.
- Frozen hashes re-derived: focused24 `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`, focused20 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

Review source authority is snapshot run/artifact `37197878231 / 11301865187`, event/source `16b85570debf8d3fab83e42458ffe92b116e68ba`, embedded archive SHA-256 `39bfaa8c2a8cf8a03367f6ccc3f8164b5be08b8db43327575accdf5ddddef763`, **5343/5343** source-file manifest checks, `runtimeExecution=false`. The first snapshot-marker create attempt was blocked by connector safety before any repository mutation; the corrected invocation succeeded. No semantic inspection relied on the failed attempt.

#### 2. F1 / CAND-01 — RA-19 ordering and A5-product binding

**DISCHARGED.** The exact R1 source now publishes A5 records before any moved category-(a) predicate:

1. `publish_records_for_validation(std::move(cells), std::move(occurrences), std::move(relations))` runs first;
2. a publication error returns unchanged;
3. only a valid published `SurfaceOccurrenceComplex` reaches `validate_phase_front_authority_after_a5(...)`;
4. the helper consumes `complex.occurrences()`, checks side cardinality against `complex.certificate().directedSideCount`, and iterates `complex.cells()`.

The pre-R1-to-R1 production diff is confined to this binding/order repair in `src/pipeline/RemeshPipeline.cpp`; no adapter serialization or unrelated production semantic changed. The prior validation-order-shadowing candidate is therefore recovery-proved and closed as non-stable; append-only stable accounting is unchanged.

#### 3. F2 / CAND-02 — identity24 complete pure-projection oracle

**DISCHARGED.** `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` remains the same frozen identity and still exercises the three required fixtures. Its expected values are independently reconstructed from A5/A6/A7 plus fixed/default compatibility rules; it does not call adapter helpers to create the expected result.

Field census against the current type definitions and adapter writes is complete:

- every `AuthoritativePhaseFrontMeshResult` field is asserted: success/failure, invalid loci, three topology summary fields, and all three consumed-authority counters;
- every `PureQuadMesh` field is asserted: fixed/default fields, vertices/positions/provenance, quads, boundary vertices/loops, backend/center-fan state, empty boundary-node/source-side metadata, vertex lineage and face lineage;
- every `PureQuadVertexLineage` field is covered, including all five `PureQuadFeatureIntervalLineage` members, full `SurfacePoint`, both stitch identities, source/local IDs, retained region/chart/sheet/support authority, quotient ID, occurrences, equivalences and selected relation paths;
- every `PureQuadFaceLineage` field is covered, including both cycle hashes;
- quad canonical ordering and boundary-loop rotation/sort are independently reimplemented test-side.

A one-field mutation of any adapter-written result/mesh/lineage field is therefore observable by identity24. Focused identity24 passes in the immutable R1 gate, and the prior test-authority candidate is recovery-proved and closed as non-stable.

#### 4. R3 thin-adapter preservation

The adapter itself is unchanged by R1. Static inspection confirms it remains a compatibility projection: A5/A6/A7 producer invocation, typed legacy failure mapping, deterministic serialization/normalization, and diagnostic counters. R1 adds no tolerance, support/region/sheet selector, relation search, route validity, topology repair, merge/acceptance predicate, or legacy authority reconstruction to the adapter.

Within production `src/`, the R1 delta is only `src/pipeline/RemeshPipeline.cpp`; within tests it is only `tests/SurfaceCellTransitionQuotientTests.cpp`. Frozen gate files are byte-identical.

#### 5. Regression and authority disposition

- `M6-CP1-TB10-A5V-REV-CAND-01`: **CLOSED / RECOVERY PROVED / NON-STABLE**; existing `VALIDATION_ORDER_SHADOWING` pattern, no stable repricing.
- `M6-CP1-TB10-A5V-REV-CAND-02`: **CLOSED / RECOVERY PROVED / NON-STABLE** test-authority defect, no stable repricing.
- R1 EXEC creates no new candidate. Stable accounting remains **60 events / 16 categories / 44 recurrences**, project debt **1**.
- Candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` is promoted as the current reviewed M6 runtime authority under selector449 449/449 and focused24 24/24.
- Shared `tau`, RA-22b, A6/A7 semantics and the previously accepted thin-adapter failure mapping remain unchanged.

#### 6. Successor and carried obligations

`M6-CP1-CB11-G4` is now authorized under `Architecture_M6_CP1_CB11_G4_B002_Boundary_Code_Build_Plan.md`, including RA-20/RA-21. Its compile-green successor is artifact-only TB11, **28+449 = 477**, then mandatory Review.

`M6-CP1-CLOSE-REV` continues to own the A7 cross-sheet certification proxy, provenance-face consumer audit, and the previously recorded merged-diagnostic-name closeout. `M6-DEFN-R5` remains a CP3-entry gate. No CP1 closure or debt discharge occurs in this Review.

#### 7. Review closeout checklist

| Duty | Result |
|---|---|
| Immutable compile/runtime evidence independently re-derived | PASS — 28/28 candidate manifest; 965/965 runtime manifest; 473/473 exact-filter gate |
| F1 ordering/product binding | PASS / discharged |
| F2 complete projection oracle | PASS / discharged |
| Static thin-adapter preservation | PASS |
| Regression candidates | both recovery-proved / non-stable; no new candidate |
| Stable accounting | 60 / 16 / 44, debt 1 |
| Runtime authority | promote `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` |
| ORIENTATION / TODO / CHANGELOG / ROADMAP / tracker | updated for accepted R1 Review |
| Turn boundary | runtime-free Review; no source/test/fixture/selector/build mutation |
| Successor | `M6-CP1-CB11-G4` -> TB11 477 -> mandatory Review |

---

#### Review-agent addendum (2026-10-04, resumed `M6-CP1-TB10-A5V-R1-REV`)

**Disposition:**
- **Acceptance and promotion: CONFIRMED.** Candidate `11299078582 / 96b456f9...` is the reviewed runtime authority.
- **F1/F2 discharges: CONFIRMED** by independent source and field-census checks.
- **RA-21b added.** A static pre-analysis of the CB11 oracle shows that RA-21 as written would hit its own stop rule on the produced torus. RA-21b fixes the oracle *before* CB11 starts.
- Accounting 60 / 16 / 44, debt 1. Successor unchanged: `M6-CP1-CB11-G4`, with its plan amended.

##### K1. Independent re-derivation (confirmed)

- I downloaded result `11300407906` again. Its ZIP SHA-256 is `b9f2daed...b589`, and `SHA256SUMS` verifies **965/965**.
- The focused ledger is 24/24 PASS in the exact order of the focused-24 file (`6bcc8a54...`). The selector ledger is 449/449 PASS in exact selector449 order. No selection or skip anomalies.
- Raw logs: focused 20 `[ OK ]` (72 s), focused 24 `[ OK ]` (87 s).
- HEAD `src/`, `include/`, `tests/` and `cmake/` are byte-identical to `96b456f9`.

##### K2. R1 source and oracle (confirmed)

**F1 / RA-19a.** `SurfaceOccurrenceComplexProducer::produce` now works in this order:
1. call `publish_records_for_validation(...)` and return any of its errors unchanged;
2. run `validate_phase_front_authority_after_a5(..., *complex)` on the **published** complex (`RemeshPipeline.cpp:4937-4951`):
   - the side count is checked against `complex.certificate().directedSideCount`, iterating `complex.cells()`;
   - regions come from `complex.occurrences()` (`:3467`, `:3603-3606`);
3. return the published product.

The diff touches nothing else.

**F2 / §J3.** Identity 24 now asserts, with exact equality, every field of:
- `AuthoritativePhaseFrontMeshResult` (11);
- `PureQuadMesh` (14);
- `PureQuadVertexLineage` (17, including all five `PureQuadFeatureIntervalLineage` members and every `SurfacePoint` member);
- `PureQuadFaceLineage` (8).

I checked these against the current struct definitions; no field is unaccounted for. Quads are compared in the A7 corner order, which is stronger than comparing canonicalized cycles, after test-side canonical sorting. Boundary loops are re-derived test-side.

**Observation (not blocking).** `consumedInternalIsolationSeams` is the A4 input's certificate count, and the oracle expects exactly that. It is "consumed" only because A5's moved bijection check passes. `M6-CP1-CLOSE-REV` should source it from A5's validated certificate set.

##### K3. CB11 pre-analysis: RA-21 needs a subdivision-equivalence oracle (RA-21b)

CB11 is the next turn. RA-21 requires an exact combinatorial isomorphism between the A6 closed-complex view and the retained arrangement on the produced torus, keyed through `(proposalId, proposalSide)`, and stops for Review if the arrangement subdivides proposal cells. Static facts at `96b456f9`:

1. **The proposal key is positional.**
   - In the authoritative phase-front path, A3 builds `network.proposals` one per `phaseFront.cells()` row, in order. It copies `corners` and `boundaryPaths`, and by design carries **no `CellId`** ("never mirror CellId into seed provenance") (`SurfaceCellTracing.cpp:17901-17916`).
   - So `proposalId` is a row index into the same immutable A4 product.
2. **`halfedge.proposalId` is only the primary provenance** (`SurfaceArrangement.cpp:2426`).
   - Each halfedge carries a `provenance` vector of `(proposalId, proposalSide, proposalBoundarySegment, sourceT0, sourceT1)` entries. The authoritative proposal-cycle rebuild groups halfedges by these entries (`:2701-2709`).
   - Coincident sides of adjacent proposals merge into one halfedge pair with two entries.
3. **Every A4 cell side is a polyline across source faces.**
   - `boundaryPaths[s]` is a vector of per-face `SurfaceTraceSegment`s, and each segment becomes an arrangement arc, so each side becomes a *chain* of halfedges with degree-2 nodes at source-edge crossings.
   - A strict isomorphism therefore **fails by construction**, and RA-21's stop rule would fire on the first CB11 attempt.
4. **No other arc sources on the torus (expected).** The produced torus has no singular separatrices, and its authoritative path builds no seed traces before returning proposals (`:17890-17920`). Authoritative rails are not inserted as extra arcs (`insertBoundaryRails = authoritativeRails.empty()`). So the expected subdivision is pure degree-2 chaining. CB11 must verify this rather than assume it (RA-21b item 4).

**RA-21b** (frozen definitions) therefore replaces RA-21 item 1's key and isomorphism notion with:
- a **provenance-chain** key;
- an equivalence **up to degree-2 contraction**;
- explicit positional preconditions;
- RA-21's stop rule kept for every *other* kind of subdivision.

##### K4. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 965/965 manifest, both ledgers in frozen order, focused 20/24 OK, HEAD == `96b456f9`. |
| F1 / F2 discharges | Confirmed in source and by a full struct-field census. |
| CB11 readiness | RA-21b: provenance-chain key, degree-2 contraction, positional preconditions, stop rule kept for other subdivisions. CB11 plan amended. |
| Observation | `consumedInternalIsolationSeams` source → CP1 close. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 195 — check an oracle's preconditions statically before the turn that must satisfy them. |
| Successor | `M6-CP1-CB11-G4` (RA-20, RA-21, RA-21b) → TB11 477 → mandatory Review. |

## `Architecture_M6_CP1_TB10_A5V_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB10_A5V_Review_Record.md`; moved verbatim.

### M6-CP1-TB10-A5V Review Record

**Turn:** `M6-CP1-TB10-A5V-REV`
**Reviewed candidate:** `11295692493 / 7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`
**Reviewed runtime:** `37184301651 / 111382969115`
**Disposition:** **REJECTED / UNPROMOTED / REPAIR REQUIRED**
**Reviewed runtime retained:** `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c`
**Exact successor:** `M6-CP1-CB10-A5V-R1`

#### 1. Independent evidence re-derivation

The TB10 execution itself is mechanically sound.

- Result ZIP SHA-256 independently recomputed as `109e98d6be0dc4106889b45645aec7818de0bca0177480ff783e11df77020cae`; log ZIP SHA-256 is `00e640b72e4be6968e2dadeac3af690e30320cb6a6a2de741946acb9b10eebba`.
- Result self-manifest independently verifies **965/965**; manifest SHA-256 is `7b915d5e3056844bdc2f13248b9d34b22b0b0133544e89249c7761f9c62ce1f1`.
- Candidate ZIP independently hashes to `e65cd6ee6b3f883b526207d83718a028b111f7ecc4de89e70e9365f38ea77065`; its root manifest verifies **28/28**; source archive hashes to `2cd6f8acd11cb635b8db40b29f9d902438c820ba8d360306208545506ccaa3bb`; source receipt is exactly `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`; every source-status receipt is empty.
- Focused24 re-hashes to `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`. Its first 20 lines independently hash to focused20 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`. Focused12 remains `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`.
- Selector449 / routing449 independently re-hash to `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` / `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, each 449 rows.
- Ledgers contain exactly **24 focused + 449 selector = 473** data rows. Raw logs contain exactly 473 `[ RUN ]` and 473 `[ OK ]` lines and no skips. The RED ledger has only its header. Focused 21-24 and the previously sensitive selector rows are PASS.
- Execution boundary records no configure, compile, relink, generated discovery, benchmark, package repair, mode repair, source/test/fixture/selector mutation, orchestration failure, or retry after runtime start. Package/source/execution-view/focused/selector/routing postflight equality is recorded and covered by the self-manifest.

This establishes a mechanically valid 473/473 TB10 run. It does **not** make the candidate acceptable when the implementation/test contract itself is incomplete.

#### 2. Finding F1 — RA-19 validation precedence is not implemented as frozen

**Severity: blocking. Candidate stays unpromoted.** Existing category: `VALIDATION_ORDER_SHADOWING`; this candidate is non-stable because no accepted runtime lost green.

RA-19 states that moved category-(a) checks must run inside A5 **after every check A5 performs today**; earlier placement is allowed only with a per-required-test outcome proof in the CB10 report.

The exact candidate violates that ordering:

- `validate_phase_front_authority_after_a5(...)` is invoked at `RemeshPipeline.cpp:4937-4941`.
- Only afterwards does `produce(...)` call `publish_records_for_validation(...)` at `:4943-4945`.
- `publish_records_for_validation(...)` contains the pre-existing A5 ownership/corner/side/relation checks at `:3620-3757`.

The CB10 report instead states that the moved checks are after the pre-existing A5 checks and supplies no RA-19-authorized per-required-test proof for the earlier placement. Focused23 proves one HardRail-before-A6 path, not the full ordering of the pre-existing A5 validation boundary.

**Required correction.** Preserve all existing A5 record validation before the moved phase-front category-(a) helper. Do not rename or weaken any existing failure. The repair must make the dataflow/order evident in source; do not satisfy this finding by accepting multiple failure outcomes.

**Falsifier.** The repair fails Review if any moved category-(a) predicate can still execute before `publish_records_for_validation` has accepted the constructed A5 records, or if any existing A5 failure name/precedence is widened.

#### 3. Finding F2 — focused identity 24 does not prove the frozen full-projection contract

**Severity: blocking test-authority gap. Candidate stays unpromoted.** Non-stable; no production regression is claimed.

RA-19 changed identity24 to a behavioral contract: on the hard-rail, split-isolation and produced-torus fixtures, the adapter's **mesh, provenance and lineage** must equal an independent test-side serialization of A5/A6/A7 products.

The exact test at `SurfaceCellTransitionQuotientTests.cpp:3769-3867` checks only a subset:

- vertex position/provenance and selected vertex-lineage fields;
- canonicalized quad cycles;
- only `operationLocalQuad` and `operation` from each face-lineage row.

It does not compare adapter mesh fields such as `sourcePatch`, the complete `vertices` vector, `boundaryVertices`, `boundaryLoops`, `backend`, `usesCenterFan`, or the default/empty fields that are part of `PureQuadMesh`; it also omits vertex-lineage fields including output/local IDs, kind and default stitch/cache fields, and face-lineage fields including `outputQuad`, `sourcePatch`, `completionVariant`, `boundaryOnly` and the cycle hashes. It also does not compare the adapter result's A5/A6/A7-derived summary counters.

A mutation in any omitted serialization field can therefore leave identity24 green. The 473/473 run proves the authored test passed, but the authored test is not yet the frozen pure-projection falsifier.

**Required correction.** Keep the identity name and focused24 file unchanged. Strengthen the test body to construct the complete expected adapter serialization from A5/A6/A7 (plus fixed compatibility/default values where the adapter contract intentionally has them) and compare every adapter-written mesh, provenance, lineage and result-summary field. If a field's expected semantics cannot be derived without inventing new authority, stop for Review rather than guessing.

**Falsifier.** Deliberately changing any adapter-written serialized field or summary field away from the independently derived expectation must make identity24 fail.

#### 4. Disposition and bounded recovery

- Shared `tau` single-sourcing is accepted: `SurfacePointSourceSupportResolver::default_barycentric_tolerance() == 1.0e-8` is the canonical owner and both A5 and A7 consume it. No retune is authorized.
- RA-22b is accepted: the A7 representative-face retained region/sheet reject-only guard is restored with exact `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`, and focused20 contains both positive and negative coverage.
- TB10 execution evidence is accepted as mechanically valid, but candidate `11295692493 / 7c56845d...` is **rejected for promotion** because F1 and F2 leave RA-19 incompletely satisfied.
- Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt 1. No stable event is added because the candidate was never reviewed/accepted runtime authority.
- Reviewed runtime remains TB9-R1 `11292072930 / 584f80fe...`.
- The A7 cross-sheet certification proxy and provenance-face consumer audit remain owned by `M6-CP1-CLOSE-REV`.

Exact successor is runtime-free Code + Build `M6-CP1-CB10-A5V-R1`, governed by `Architecture_M6_CP1_CB10_A5V_R1_Code_Build_Plan.md`. Compile-green then routes to immutable `M6-CP1-TB10-A5V-R1-EXEC` using the unchanged focused24 + selector449 = **473** gate, followed by mandatory `M6-CP1-TB10-A5V-R1-REV`. CB11 remains held.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused24 `6bcc8a...067bf`; first20 `15d04a...827d2`; focused12 `59a523...d571c`; selector449 `d4a0d1...d6414`; routing449 `9c88a5...6c5707` |
| Decisive claims independently re-derived | result/log/candidate digests; 965/965 result manifest; 28/28 candidate manifest; 24+449 ledgers/raw logs; exact source; F1 source ordering; F2 field coverage |
| Non-vacuity checked | focused21-23 execute targeted tamper paths; focused24 executes three stage-valid fixtures, but its omitted-field oracle gap is itself blocking F2 |
| Prior obligations discharged/carried | shared `tau` DISCHARGED; RA-22b DISCHARGED; RA-19 ordering/pure-projection NOT DISCHARGED -> R1; A7 cross-sheet proxy + provenance-face audit carried to `M6-CP1-CLOSE-REV` |
| Stable accounting | 60 events / 16 categories / 44 recurrences, debt 1; reviewed runtime remains `11292072930 / 584f80fe...`; selector449 remains accepted |
| New candidates/obligations recorded | `M6-CP1-TB10-A5V-REV-CAND-01` validation-order recurrence; `...-CAND-02` test-authority undercoverage; tracker updated |
| ORIENTATION currency line | `M6-CP1-TB10-A5V-REV`, 2026-10-04 UTC written |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 updated; §4 n/a because no witness authority changed and TB9-R1 remains reviewed runtime |
| CHANGELOG | review rejection / R1 route entry added |
| ROADMAP | CB10/TB10 candidate marked rejected; R1 recovery made exact next |
| Selector manifest | n/a: selector449 and all selector bytes unchanged; no new selector accepted |
| LESSONS | lesson 193 added |
| Consolidation under CLEAN_UP_POLICY | n/a: no historical document became redundant in this bounded review |
| Successor frozen | `M6-CP1-CB10-A5V-R1`; falsifiers stated in the R1 plan and Findings F1/F2 above |
| Turn boundary held | runtime-free Review; no product, test, fixture, selector, benchmark or build source mutated |
| review_check.py boundary | PASS — `python3 .agents/Directional/tools/review_check.py boundary`; no product/test/fixture/build mutation, no selector mutation, all selector hashes match baseline, durable markers preserved |
| `STATUS` lifecycle maintained | entry beacon published; final COMPLETE beacon to name `M6-CP1-CB10-A5V-R1` |
| Pushed to origin, branch in sync | documentation patch push will be verified by exact branch-head read; connector environment has no authoritative local tracking checkout, so no fabricated `git status -sb` claim is made |

---

#### Review-agent addendum (2026-10-04, resumed `M6-CP1-TB10-A5V-REV`)

**Disposition:**
- **Rejection, F1 and F2: CONFIRMED.**
- **Move fidelity verified.** TB10-REV had not checked whether the moved predicates are semantically equivalent; this addendum does (J2).
- **R1 plan amended.** The F2 oracle now has an exact field table derived from the adapter, and the F1 reorder must bind the helper to the published A5 complex (J3).
- Accounting 60 / 16 / 44, debt 1. Successor unchanged: `M6-CP1-CB10-A5V-R1`.

##### J1. Independent re-derivation (confirmed)

- I downloaded result `11296687408` again. Its ZIP SHA-256 is `109e98d6...0cae`, and `SHA256SUMS` verifies **965/965**.
- The focused ledger is 24/24 PASS in the exact order of `Architecture_M6_CP1_Required_Green_Focused_24.txt`; its first 20 lines hash to `15d04a2a...`. The selector ledger is 449/449 PASS in exact selector449 file order. No selection or skip anomalies.
- HEAD `src/`, `include/` and `tests/` are byte-identical to candidate `7c56845d`.

**Code checks.**
- **F1 confirmed.** `validate_phase_front_authority_after_a5(...)` (`RemeshPipeline.cpp:4937-4941`) runs before `publish_records_for_validation(...)` (`:4943-4945`).
- **RA-22b confirmed** (`PureQuadCompletion.cpp:901-912`).
- **Shared `τ` confirmed.** A5 and A7 both read `SurfacePointSourceSupportResolver::default_barycentric_tolerance()`, at `RemeshPipeline.cpp:3790` and `:6046`.
- **The adapter is now 252 lines** (`:6843-7095`). It does typed-error mapping, including the A7 `MaterializedMeshInvalid` site → legacy-name table, plus A7 serialization and counters. It has no semantic predicate, selection or tolerance.

##### J2. Move fidelity — the 31 category-(a) sites (not checked by TB10-REV; now verified)

A move refactor is safe only if the predicates move unchanged. I normalized the old adapter section (`6c3ae223`, adapter start through the A6 call) and the new helper:
- `result.failure="X"; return result;` and `return fail(Code::X …)` both become `FAIL(X)`;
- whitespace is collapsed;
- the statement-level texts are then diffed.

Results:

1. **28 sites move with identical predicates.** The only differences are renames: `topologyRegionById` → `regionById`, `cellIndexById` → `cellById`, and typed-`auto` loops.
2. **The side-count site changed its authority source.** `edgeByCellSide.size() != occurrenceComplex->certificate().directedSideCount` and the loop over `occurrenceComplex->cells()` became `phaseFront.cells().size() * 4U` and `phaseFront.cells()`, because the helper now runs before A5 publishes.
   - It is semantically equivalent for producer-built records: one A5 cell per phase-front cell, four directed sides each.
   - But it re-binds an A5-product check to the A4 input. The F1 reorder must restore the binding (J3).
3. **Three unpinned legacy literals now map onto existing A5 codes:**
   - `MissingAuthoritativePhaseFront` (empty cells; empty edges now fails later as `IncompleteAuthoritativePhaseFrontSides`) and `InvalidAuthoritativePhaseFrontSource` → A5 `SourceAuthorityMismatch`;
   - `InvalidAuthoritativeSourceChartTransitions` → A5 `InvalidChartAuthority`.

   All stay fail-closed, and R4 §3.4 releases the spelling of unpinned sites. But two distinct causes now share `OccurrenceSourceAuthorityMismatch`, which is a lesson-181 diagnosability loss. Recorded for `M6-CP1-CLOSE-REV`; not blocking.

No moved predicate was weakened or widened.

##### J3. R1 plan amendments (binding)

**For R1 (ordering).**
- After `publish_records_for_validation` returns a valid `SurfaceOccurrenceComplex`, the moved helper must take the **published** complex.
- The side-count check uses `complex.certificate().directedSideCount` and `complex.cells()` again, exactly as the pre-CB10 adapter did.
- Validating against the input instead of the A5 product is not permitted after the reorder.

**For R2 (identity 24) — exact oracle, derived from the adapter's own writes at `7c56845d`.** Every expected value is computed test-side from A5/A6/A7 products or the fixed compatibility constant.

| Field | Expected value | Source |
|---|---|---|
| `success` | `true` | — |
| `failure` | empty | — |
| `invalidCell`, `invalidEdge` | `-1` | — |
| `connectedComponents`, `boundaryLoopCount`, `eulerCharacteristic` | A7 `certificate()` | A7 |
| `consumedTopologyRegions` | count of distinct A5 `occurrence.topologyRegion` | A5 |
| `consumedInternalIsolationSeams` | A4 `isolationSeamTransportCertificates().size()` | A4 input |
| `consumedPeriodicHolonomies` | count of distinct `periodicRelation` among A6 `relation_certificates()` | A6 |
| `mesh.sourcePatch` | `0` | fixed |
| `mesh.backend` | `ClosedForm` | fixed |
| `mesh.usesCenterFan` | `false` | fixed |
| `mesh.vertices` | `0..n-1` | — |
| `vertexPositions` row `r` | A7 `vertices()[r].position` | A7 |
| `vertexProvenance[r]` | A7 `sourcePoint` | A7 |
| vertex lineage `outputVertex`, `localVertex` | `r` | — |
| vertex lineage `kind` | `SourceTriangle` | fixed |
| vertex lineage `sourcePatch` | `0` | fixed |
| vertex lineage `sourcePoint`, region/chart/sheet sets, `sourceSupport`, `sourceOccurrences`, `equivalences`, `selectedRelationPaths` | the A7 vertex's fields | A7 |
| vertex lineage `quotientClass` | `QuotientClassId::from_index(r, n)` | — |
| other vertex-lineage fields (`featureInterval`, `stitchIdentity`, `authoritativeIdentity`, …) | value-initialized defaults | — |
| `quads` | A7 `topology()` cells mapped through the class→row map, sorted by lexicographically smallest rotation (canonical cycle) | A7 |
| face lineage `outputQuad` | its index | — |
| face lineage `sourcePatch` | `0` | fixed |
| face lineage `operation` | `ClosedForm` | fixed |
| face lineage `operationLocalQuad` | the source cell's `CellId` index | A7 topology |
| face lineage `completionVariant` | `0` | fixed |
| face lineage `boundaryOnly` | `false` | fixed |
| face lineage cycle hashes | `0` | default |
| `boundaryLoops` | A7 `boundary_loops()` mapped to rows, each rotated to start at its minimum row, then sorted | A7 |
| `boundaryVertices` | concatenation of `boundaryLoops` | — |
| other mesh fields (`domainIdentity`, `boundaryNodeIdentities`, `sourceSideEdgeCounts`, `boundaryProvenance`, `boundaryRailIds`) | defaults | — |

Rules:
- Compare every field with exact equality.
- Use `isApprox` only where the adapter copies a double from A7 by value; these compare equal, so exact equality is preferred.
- A field outside this table found to be adapter-written is a stop for Review.

##### J4. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 965/965 manifest, focused-24 and selector449 ledgers in frozen order, HEAD == `7c56845d`. |
| Findings F1 / F2 | Confirmed in source. |
| Move fidelity | Verified by normalized predicate diff: 28 identical, 1 re-bound to the A4 input (restored in R1), 3 unpinned names consolidated (recorded). |
| R1 plan | Amended: helper bound to the published complex; exact identity-24 field oracle. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 194 — review a move refactor with a normalized predicate diff. |
| Successor | `M6-CP1-CB10-A5V-R1` → TB10-R1 473 → mandatory Review. |

## `Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`; moved verbatim.

### `M6-CP1-TB11-G4-R1-REV` — Independent Recovery Review Record

**Turn:** `M6-CP1-TB11-G4-R1-REV`
**Reviewed candidate:** `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`
**Reviewed runtime:** `37240414090 / 111547976292`
**Disposition:** **ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED**
**Exact successor:** `M6-CP1-CLOSE-REV`

#### 1. Independent evidence re-derivation

The R1 recovery gate is mechanically sound and independently re-derived from immutable artifacts without executing Directional binaries in Review.

- Compile candidate ZIP SHA-256: `35f865b1016a0ec6f0d30b80dd0c33d7a01f9fbfcbb420ee43225398cf75415c`; root manifest SHA-256 `4bf0ca5cd9caae58626b0660eb77466fa88eadf604aaeb657c502e1bbb63598d`, **28/28**; packaged source archive SHA-256 `b0c70a127e1a262761ff0519dd0d0d4d28511f276bfe38f71d2e72249c2b631b`; exact source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; compile boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, GMP/GMPXX and clean source receipts.
- Runtime result/log ZIP SHA-256: `1082edce080e373c062b5c8dc398158d2d4ab92ded669c191b4c6bd9e5668b6e` / `bfaf91db3602fa1535c984afba1378cd47c3090b1658c7cf16b24ce990e19308`.
- Result self-manifest SHA-256 `47d3e333899321da8e8a351849df5abe10407cd1af1864578ac9528c6e6c86d6`, **973/973**.
- Focused ledger: **28/28 PASS** in exact focused-28 order; selector ledger: **449/449 PASS** in exact selector449 order; aggregate **477/477**. Every process selected exactly one test, zero skips, benchmark 0. Raw logs independently contain **477 RUN / 477 OK / 0 SKIP**; RED ledger is header-only.
- Postflight records package/source/execution-view census equality, unchanged focused/selector/routing authority and package manifest **28/28**. Execution boundary records no configure, compile, relink, generated discovery, package/mode repair, source/test/fixture/selector mutation or retry after runtime start.
- Focused ordinals 25 and 28 each select once and pass. Their raw logs show organic completion at 113.979 s and 57.511 s respectively.
- Frozen hashes re-derived: focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

Review source authority is snapshot run/artifact `37244642521 / 11319125271`, event/source `d75dada25389d15ff7caf75e0b99a599a96df486`, provider ZIP SHA-256 `0d7112e0ceb9968f2944fd98f8dbeeab7f63dc26b40d8e7831ebacae4d0b2392`, embedded archive SHA-256 `99772c123df8cab3287265a06ac88143af67cb193ae166b80a749ef94b457f10`, **5353/5353** source-file manifest checks and `runtimeExecution=false`. The first local manifest verification attempt used the wrong extraction root and failed before source inspection; correcting the local extraction layout yielded the authoritative 5353/5353 result without any remote retry or repository mutation.

#### 2. RA-24 / CAND-02 — edge-loop strip definition recovery

**DISCHARGED / RECOVERY PROVED.** The exact R1 production delta replaces only the invalid quad-opposite rung-set relation in `build_surface_quotient_closed_complex_view`.

Static re-derivation confirms:

1. the builder constructs the four incident quotient edges at each quotient class;
2. boundary and valence-!=4 vertices are not joined;
3. at an interior valence-4 vertex, each edge is united only with an incident edge sharing no classed quad, which is the RA-24 edge-loop continuation;
4. strip canonicalization still orders components by their smallest `SurfaceQuotientEdgeId` and assigns deterministic ordinals;
5. candidate extraction, protection labels, A5, A6 class/relation construction and A7 are untouched by R1.

The pre-R1-to-R1 semantic source diff is confined to `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp`; the production file's R1 blob is `ad46e264a60f0cd0218aa305a19caf8aa336c3e1`. No other `src/` or `tests/` path differs from the frozen pre-R1 snapshot.

Identity 28 independently reconstructs the edge-loop partition from edge incidence and classed-quad ownership rather than calling production strip construction. It checks every emitted candidate against independently derived strip membership, edge existence, global valence, boundary, hard-feature, side-cell, periodic-relation and path-degree facts; it requires a produced-torus eligible `ClosedLoop`; and a one-edge `hardFeatureProtected=true` tamper makes that loop independently ineligible and absent. The immutable runtime PASS therefore reaches both the non-vacuity and tamper falsifiers that failed before RA-24.

`M6-CP1-TB11-G4-EXEC-CAND-02` is closed as **RECOVERY PROVED / PRODUCTION-DEFINITION DEFECT / NON-STABLE**. Its earlier RA-23 “definition-witness gap” wording is superseded by the TB11 Review addendum and this recovery evidence.

#### 3. RA-21c/RA-21d / CAND-01 — arrangement/quotient oracle recovery

**DISCHARGED / RECOVERY PROVED.** Identity 25 now preserves arrangement evidence without conflating physical arrangement identity with quotient identity across certified seams.

Static re-derivation confirms the strengthened oracle:

- one provenance chain is built per `(proposalId, proposalSide)` and checked as a degree-2 subdivision with two endpoints and uniform hard-feature state;
- each A4 corner occurrence gets its own arrangement-node witness from the unique intersection of adjacent side-chain node sets; witnesses are not collapsed by quotient class;
- A6 side IDs map to exact phase-front edges by `(filledCell, filledSide)` and reciprocal `oppositeEdge` ownership is required;
- the two A6 relation certificates must encode exactly the reversed endpoint-occurrence pairs and their typed owner must match OrdinaryFront, HardRail or Periodic authority;
- each side chain's endpoints must equal its two occurrence-node witnesses and chain hard-feature state must equal `hardFeatureProtected`;
- exact chain equality and crossed occurrence-node equality are retained only for `Ordinary` relations with no relation-side/span isolation evidence; HardRail, Periodic and isolation seams are the only relaxation cases.

The test uses exact identities and exact source/authority fields; it does not infer quotient equality from geometry, tolerance or hashes. Focused ordinal25 passes organically in the immutable R1 runtime, discharging the RA-21b false rejection while retaining RA-21d's discriminator on non-barrier Ordinary edges.

`M6-CP1-TB11-G4-EXEC-CAND-01` remains a **FALSE REJECTION / TEST-ORACLE DEFECT / NON-STABLE**, now recovery-proved under RA-21c/RA-21d.

#### 4. Scope, regression and authority disposition

The exact R1 patch SHA-256 is `49eb272c5433de5520fadced9615347d93f158f58e6e4ba627b0a549ccddd8ca`; its declared base is `d8b1aff8c12364ed587e61fddb8b3716dd9a57c3`, diff-body SHA-256 `4a13bc081b94335c83e7affcaff1d774a05498677f981247c45f79e53880ad9b`, and intended paths are exactly the two files above. Current file Git blobs match the patch destinations: production `ad46e264...` and tests `4549e1a1...`.

No new runtime RED, orchestration defect, stable event, recurrence, category or debt was observed. Stable accounting remains **60 events / 16 categories / 44 recurrences** and project debt remains **1**.

Candidate `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` is promoted as the current reviewed M6 runtime authority under focused28 **28/28** + selector449 **449/449** = **477/477**.

#### 5. Successor and carried obligations

The accepted R1 Review releases the held CP1-close checkpoint. Exact successor is runtime-free `M6-CP1-CLOSE-REV`.

That close Review still owns the previously carried obligations and must not silently discharge them from this gate:

- A7 cross-sheet certification proxy;
- remaining provenance-face consumer audit against multi-sheet A7 classes;
- merged diagnostic-name closeout;
- `consumedInternalIsolationSeams` counter-source audit.

`M6-DEFN-R5` remains the CP3-entry gate for the deferred gauge obligations and A5 barrier-set census. This Review does not close CP1 or discharge project debt; it only promotes the recovered G4 runtime and authorizes the dedicated close Review.

#### 6. Review closeout checklist

| Duty | Result |
|---|---|
| Immutable compile/runtime evidence independently re-derived | PASS — 28/28 candidate manifest; 973/973 runtime manifest; 477/477 exact-filter gate |
| RA-24 edge-loop production change | PASS / bounded to the strip relation |
| Identity 28 independent non-vacuity + tamper oracle | PASS / reaches both falsifiers |
| RA-21c/RA-21d arrangement oracle | PASS / barrier-only relaxation retained |
| R1 source/test scope | PASS — exactly one production file + one test file |
| Regression candidates | CAND-01 false rejection recovery-proved; CAND-02 production-definition recovery-proved; both non-stable |
| Stable accounting | 60 / 16 / 44, debt 1 |
| Runtime authority | promote `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` |
| Turn boundary | runtime-free Review; no source/test/fixture/selector/build mutation |
| Successor | `M6-CP1-CLOSE-REV` |

---

#### Review-agent addendum (2026-10-05, resumed `M6-CP1-TB11-G4-R1-REV`)

**Disposition:**
- **Acceptance and promotion: CONFIRMED.** Candidate `11316716869 / 8dd95821...` is the reviewed runtime authority (477/477).
- **One fail-closed gap** in the RA-24 implementation (M1).
- **Successor re-routed** from `M6-CP1-CLOSE-REV` to a bounded close-out Code + Build, **`M6-CP1-CB12-CLOSE`**. A runtime-free close Review cannot discharge the carried obligations, because most of them need code (M2).
- Accounting 60 / 16 / 44, debt 1.

##### N1. Independent re-derivation (confirmed)

- I downloaded result `11316968568` again. Its ZIP SHA-256 is `1082edce...8b6e`, and `SHA256SUMS` verifies **973/973**.
- The focused ledger is 28/28 PASS in exact focused-28 order (`9154a986...`). The selector ledger is 449/449 PASS in exact selector449 order. No anomalies.
- Raw logs: ordinal 25 `[ OK ]` (114 s), ordinal 28 `[ OK ]` (57.5 s).
- HEAD `src/`, `include/`, `tests/` and `cmake/` are byte-identical to `8dd95821`.

**RA-24 code (confirmed).**
- R1 replaces the quad-opposite union with vertex-incident continuation (`RemeshPipeline.cpp:6278-6311`).
- It skips vertices that are not interior with valence 4, unites each edge with the unique incident edge that shares no classed quad with it, and keeps the ordinal rule.
- Nothing else in production changed.

**Identity 28.** Its independent reconstruction asserts that the opposite edge is unique at every interior valence-4 vertex. It then requires an eligible produced-torus `ClosedLoop`, checks that the one-edge tamper makes it ineligible and absent, and validates every emitted candidate.

**Identity 25** implements RA-21c with RA-21d. Equality is kept on Ordinary edges without isolation evidence.

##### N2. M1 — RA-24's production continuation does not fail closed (Low–Medium)

RA-24 defines continuation as "the **unique** other incident edge … that shares no classed quad". When more than one candidate exists, the production code drops the continuation silently (`opposite.reset(); break;`), and when none exists it silently does nothing.

In a valid closed manifold quad complex, the opposite edge at an interior valence-4 vertex is always unique, so ambiguity means the complex is malformed. Silently truncating strips there:
- hides the malformation from every view consumer;
- yields misleading open-strip candidates;
- the extractor can be called on an A6 view without A7's vertex-fan checks.

The test's reconstruction asserts uniqueness, so the produced torus is covered, but production must not depend on a test. **Fix:** a typed A6 error, `ClosedComplexStripContinuationMismatch`, emitted when an interior valence-4 vertex lacks a unique opposite. Owner: CB12-CLOSE (C4).

##### N3. M2 — CP1 close needs a close-out Code + Build before the close Review

Successor `M6-CP1-CLOSE-REV` is runtime-free. Its carried obligations:

| Obligation | Needs code? |
|---|---|
| (a) A7 cross-sheet proxy: make it exact, or remove it and state that A6 certifies — RA-22a §3 | yes |
| (b) provenance-face consumer audit — RA-22b §5 | analysis; any defect found → code |
| (c) the three merged A5 diagnostics — RA-19a §3 | yes |
| (d) `consumedInternalIsolationSeams` counter source | yes |
| (e) N2 / M1 | yes |

A runtime-free close Review would therefore immediately authorize a close-out CB. Routing straight to **`M6-CP1-CB12-CLOSE`** saves a turn, and leaves CLOSE-REV as pure verification on a fresh gate.

**Static facts that make CB12 bounded.**
- **(a)** `CornerWedgeIsolationTransition` carries `region`, `seam`, `fromSheet` and `toSheet` (`PureQuadCompletion.h:195-198`). The exact check is feasible: a cross-sheet forest edge needs a transition (relation evidence ∪ either occurrence's `cornerWedgeIsolation`) whose `{fromSheet, toSheet}` maps one endpoint's sheet set onto the other's. Today any transition is accepted (`RemeshPipeline.cpp:~6850-6872`).
- **(b) partial pre-audit.** `project_surface_cell_vertex_chart_authority` (`:8061-8127`) consumes class-wide `lineage.sourceCharts` → **class-wide, safe**. Still to classify:
  - `SourceAuthoritativeMeshValidator::resolve_compatible_chart` (`SourceAuthoritativeMeshValidator.cpp:1210-1262`);
  - the optimizer's source-point rebinding (`SurfaceMeshOptimizer.cpp:2576`, `:3020`);
  - `BenchmarkQuality` (`:1490-1503`).
- **(c)** A5 emits `SourceAuthorityMismatch` for the empty-phase-front and source-shape cases (`:3769`) and `InvalidChartAuthority` for chart transitions (`:3785`). Distinct codes or sites can restore the three legacy names.
- **(d)** The adapter sets the counter from the A4 input count (`:7544`). A5 should publish its validated isolation-certificate count.

##### N4. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 973/973 manifest, both ledgers in frozen order, ordinals 25/28 OK, HEAD == `8dd95821`. |
| RA-24 / RA-21c/d | Confirmed in code and tests. M1: production ambiguity is silent (fix in CB12). |
| Successor | Re-routed: `M6-CP1-CB12-CLOSE` → `M6-CP1-TB12-CLOSE-EXEC` (30+449 = 479) → `M6-CP1-TB12-CLOSE-REV` → `M6-CP1-CLOSE-REV`. |
| Plan | `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md` written. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 197 — route a Review successor to the turn type its obligations need. |

## `Architecture_M6_CP1_TB11_G4_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB11_G4_Review_Record.md`; moved verbatim.

### `M6-CP1-TB11-G4-REV` — Independent Review Record

**Disposition:** **CB11 candidate REJECTED / runtime evidence accepted / two REDs reclassified as test-definition defects / bounded R1 recovery required.**

Candidate `11308472138 / 582da20a925ba920c923bf5aacb9e0e56ef0723d` remains **unpromoted**. The last reviewed runtime remains `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` until a recovery gate and mandatory recovery Review succeed.

Stable accounting remains **60 events / 16 categories / 44 recurrences**, project debt **1**. No stable regression event is added: both REDs are newly authored focused-oracle/definition failures on an unpromoted candidate and selector449 remains **449/449 PASS**.

#### 1. Independent evidence re-derivation

Review re-used the immutable TB11 package/result bytes without executing generated Directional runtime. Candidate ZIP SHA-256 is `a4d178678bcbc9c29fc4003ffc9205ef220873bfb0e5247b21a453fffdc8d04d`; its root `SHA256SUMS` is `c6e691329dfe5599caf658b23e70d51d45ac76c090afc7d9cb86f3901df34468` and verifies **28/28**. Embedded source is `582da20a925ba920c923bf5aacb9e0e56ef0723d`, archive SHA-256 `c41200fefded7e8a60f57eb801c5de2476eebafe6822fe5ce5e4a2113971c768`, with clean source-status receipts.

Result ZIP SHA-256 is `7de4a3203720d170691ff0f1b3d1773736b56f857accd5e51ced5f92c5973add`. Its self-manifest SHA-256 is `31a537f5d420b64e828fe75c8c5125e33ef3c1c3588efc9e531b6cca3ee61317` and independently verifies **973/973**. The ledgers contain exactly **28 focused + 449 selector = 477** processes. Focused is **26 PASS / 2 RED**, selector is **449/449 PASS**, aggregate **475/477**; every row selected exactly one test and skipped zero. RED is exactly focused ordinals **25 and 28**. The execution boundary records no configure, compile, relink, generated discovery, benchmark, package/mode repair, source/test/fixture/selector mutation, or retry after runtime start. Immutable package/source/execution-view postflight is green.

Review source authority was refreshed with source-snapshot run/artifact `37233051478 / 11314264059` at branch SHA `48c4fbeb154fb8deeb26b970a13ad2ea652583b1`; archive SHA-256 `986e3bc1ec98c681af537004def24d4bd165da417437f9c83268729c96d02c05`, **5348/5348** manifest rows verified, `runtimeExecution=false`. Relevant product/test files are byte-identical to the embedded candidate source. A process miss occurred before this snapshot: several repository source/document reads were made before the mandatory `READ_MODE=snapshot` gate was fixed. No decisive conclusion below relies on that pre-snapshot inspection; every finding was re-derived from the verified local snapshot. Existing tool-conservation policy already forbids the pattern, so this adds no stable lesson/event.

#### 2. Finding F1 — ordinal25 is a false rejection: RA-21b conflates quotient identity with arrangement-node identity

**Classification:** TEST-ORACLE / DEFINITION DEFECT. `M6-CP1-TB11-G4-EXEC-CAND-01` is **not** evidence of an A6 production side-pairing defect.

Ordinal25 fails at three linked assumptions: one A6 class must map to one arrangement node, the two incident sides of one A6 edge must have identical arrangement-chain edge sets, and that common chain's endpoints must equal the globally chosen nodes for the A6 classes. Runtime shows 35 class/node disagreements, 30 paired-chain disagreements and 18 endpoint-set disagreements.

The frozen RA-21b assumption is invalid for the exact produced-torus authority:

1. `SurfaceCellTracing.cpp` pairs same-region hard-rail boundaries only when their `sharedBoundaryInterval.boundaryOccurrence` values are **distinct**. It then sets reciprocal `oppositeEdge`, constructs a periodic holonomy, and converts the pair to `PeriodicCut` with one shared `PeriodicRelationId`.
2. A5 consumes that reciprocal phase-front authority and publishes the two endpoint occurrence relations across the paired sides. A6 unions the relation endpoints into quotient classes. This is quotient identification across two distinct cut occurrences; it is not a claim that the two cut sides are the same arrangement arc.
3. `SurfaceArrangement.cpp` builds physical DCEL nodes/halfedges from scoped source-node identity and merges segment provenance only when it lands on the same undirected arrangement edge. It does **not** apply A5/A6 occurrence relations to identify arrangement nodes or halfedges.
4. Therefore a valid PeriodicCut quotient edge may have two distinct arrangement provenance chains and its quotient endpoint class may contain occurrences represented by distinct arrangement nodes. Requiring equality of those chains/nodes is exactly the quotient/arrangement authority conflation that the stage split was intended to avoid.

The correct migration oracle is per-occurrence/per-side, not per-quotient-node physical identity. Each proposal side must still have one valid degree-2 arrangement provenance chain, and each A4 corner occurrence must still be the unique intersection of its adjacent proposal-side chains. But A6 quotient equivalence is then checked through A4 `oppositeEdge` + A5/A6 relation authority; members of one quotient class are not required to share one arrangement node, and the two sides of a quotient edge are not required to share one arrangement edge set.

Focused identities 26 and 27 are independently green, which is consistent with this classification: typed hard-feature/relation labels and quotient member lineage survived. They do not by themselves promote the candidate; they only show the RED is not a label/lineage failure.

#### 3. Finding F2 — ordinal28 exposes an unproved non-vacuity premise, not a demonstrated extractor implementation defect

**Classification:** DEFINITION / FIXTURE-WITNESS GAP. `M6-CP1-TB11-G4-EXEC-CAND-02` is separate from F1 and is **not** established as a production regression.

Ordinal28 fails only at its first non-vacuity assertion. The hard-feature tamper is never reached. Static review proves that any candidate currently emitted with `includeProtectedCandidatesForDiagnostics=false` already satisfies the independent predicate used by ordinal28: the extractor groups one `stripOrdinal`, rejects invalid path degree, marks cell presence as side-feasible, and filters every hard-feature, boundary or quotient-valence singularity candidate. The independent oracle then re-checks those same externally visible facts. Therefore the observed failure means the production call emitted **no eligible candidate at all** on this produced view; it is not an independent-oracle disagreement about an emitted candidate.

The prior M4CP4 non-vacuity result cannot establish the R4 D3 premise. That accepted test extracts candidates from the retained arrangement grouped by `(family, strand)`. R4 §4.3 explicitly removed `family/strand` from A6 authority and replaced that grouping with the transitive closure of opposite edges in quotient quads. The old test proves an arrangement candidate exists; it does not prove the new quotient-topology strip partition contains an unprotected, nonsingular path/loop on the same fixture. R4 §4.4 silently assumed that transfer and ordinal28 is the first executable falsifier of the assumption.

Review does **not** authorize changing production strip closure, valence classification, protection semantics, or side-feasibility merely to manufacture non-vacuity. Those implementations match the frozen §4.3 rules on static inspection. The reason the produced torus has zero eligible quotient-strip candidates (protected strip, quotient singularity, or topology of the opposite-edge closures) was not emitted by the immutable TB11 artifact, so Review does not invent a more specific runtime cause.

#### 4. Binding amendments — RA-21c and RA-23

##### RA-21c — arrangement is a per-side subdivision witness, not quotient identity authority

RA-21b items 2-5 are amended as follows for the CB11 migration oracle:

1. Keep the positional proposal/cell preconditions and provenance-key rule unchanged.
2. Build and validate one degree-2 provenance chain for each `(proposalId, proposalSide)`. Every arrangement halfedge must retain proposal provenance; non-proposal inserted arcs remain a stop.
3. For each A4 corner **occurrence**, independently require the previous/next side-chain node sets to intersect in exactly one arrangement node. Store this as an occurrence-node witness. Do not collapse this map by `SurfaceQuotientClassId`; two occurrences in one quotient class may legitimately have different arrangement nodes.
4. For each A6 two-sided edge, map its `SurfaceQuotientSideId`s back to the exact phase-front edges by `(filledCell, filledSide)` and require reciprocal `oppositeEdge`. Require the A5/A6 endpoint relations to certify the reversed quotient-class pairing and relation owner. This relation authority, not physical chain equality, establishes the quotient edge.
5. For each incident side separately, require its chain endpoints to equal the two occurrence-node witnesses for that side. Do **not** require the two incident sides' chain edge sets or endpoint-node sets to be equal across Ordinary/HardRail/Periodic quotient relations.
6. Keep per-chain `hardFeature` uniformity and equality to `hardFeatureProtected`; keep exact HardRail/Periodic owner checks from phase-front/A5/A6 authority. No position, epsilon or hash may establish identity.
7. Stop for Review on positional failure, missing proposal provenance, non-degree-2 side subdivision, non-unique occurrence corner intersection, non-reciprocal phase-front side pairing, relation/owner disagreement, per-side endpoint disagreement, sliver/extra cell, or any need to infer quotient identity from arrangement geometry.

##### RA-23 — split produced-boundary verification from CP1 mechanism non-vacuity

R4 §4.4's inference from the old arrangement candidate test to produced A6 quotient-strip non-vacuity is withdrawn.

1. The produced torus remains mandatory for identities 25-27 and for identity28's **universal** boundary checks: independently reconstruct the opposite-edge strip partition from `view.quads` + side incidence and require every published `stripOrdinal` to match it; independently validate every emitted candidate. An empty produced candidate set is not, by itself, a CP1 failure.
2. Identity28's **mechanism-only non-vacuity/tamper** must use a test-side canonical closed toroidal A6 view with at least a `4 x 4` periodic quad grid: every edge two-sided, every vertex quotient-valence four, no boundary/protection labels, and independently derived opposite-edge strip ordinals. It must produce at least one independently eligible closed-loop candidate. Marking one edge of that exact candidate `hardFeatureProtected=true` must make the exact candidate independently ineligible and absent from extraction.
3. The test-side toroidal view is an extractor mechanism fixture only. It grants **zero** `G4-B002` debt credit. M6-CP3 retains the direct-production requirement: closed source, recovery/fallback disabled, a directly produced independently eligible candidate, and discriminating hard-feature tamper after A5-A8 are complete.
4. Focused identity names/order and focused28 list bytes remain unchanged.

#### 5. Candidate and regression disposition

- `M6-CP1-TB11-G4-EXEC-CAND-01`: **CLOSED / FALSE REJECTION / TEST-ORACLE DEFECT / NON-STABLE.** Root is RA-21b's invalid quotient==arrangement identity assumption across relation seams.
- `M6-CP1-TB11-G4-EXEC-CAND-02`: **RECLASSIFIED / DEFINITION-WITNESS GAP / NON-STABLE / RECOVERY REQUIRED.** The produced-torus non-vacuity premise was never proved under quotient opposite-edge strips. No product defect is established.
- The two findings are not merged. F1 concerns the migration comparison authority; F2 concerns a non-vacuity premise for a different strip model.
- Stable accounting stays **60 / 16 / 44**, debt **1**.

#### 6. Promotion decision and bounded recovery

The CB11 candidate is **rejected for promotion** because the frozen 477 gate did not pass, even though Review finds no demonstrated production-source defect. Recovery must prove the corrected oracle rather than waive the RED.

Exact successor: **`M6-CP1-CB11-G4-R1`**.

R1 is test-authority recovery only. It may implement RA-21c in focused ordinal25 and RA-23 in focused ordinal28, with helper-only changes needed to express those oracles. **No semantic production change to A5/A6 closed-complex construction, protection, strip closure, or candidate extraction is authorized.** If R1 discovers that such a production change is necessary, it must stop and return to Review instead of broadening scope.

R1 compile/package remains Code + Build only. If compile green, successor gate is the unchanged focused28 + selector449 = **477** fresh exact-filter processes, then mandatory `M6-CP1-TB11-G4-R1-REV`. `M6-CP1-CLOSE-REV` remains held.

---

#### Review-agent addendum (2026-10-04, resumed `M6-CP1-TB11-G4-REV`)

**Disposition:**
- **Rejection: CONFIRMED.**
- **F1 (ordinal 25): CONFIRMED in substance.** RA-21c over-relaxes, and RA-21d sharpens it.
- **F2 (ordinal 28): OVERTURNED.** It is a **production/definition defect**, not a non-vacuity witness gap.
  - R4 D3 §4.3 rule 7 groups strips by quad-opposite edges. That produces *rung sets* (matchings), which the path-degree classifier can never accept.
  - The CB11 extractor therefore emits **zero candidates on every closed quad complex**.
  - RA-23's synthetic 4×4 torus would fail the same way.
- **RA-24** replaces rule 7 with edge-loop (strand) closure.
- **The R1 plan is re-scoped** to one bounded production change plus the oracle fixes.
- Accounting 60 / 16 / 44, debt 1.

##### L1. Independent re-derivation (confirmed)

**Artifact.**
- I downloaded result `11312313559` again. Its ZIP SHA-256 is `7de4a320...3add`, and `SHA256SUMS` verifies **973/973**.
- Focused is RED at exactly ordinals 25 and 28. Selector449 is 449/449 PASS.

**Ordinal 28's raw log.** The failure is `found != extracted.candidates.end()`, where both iterators are null. **`extracted.candidates` is empty.**
- No candidate was emitted at all.
- So this is not "emitted candidates failed the independent oracle". TB11-REV §3 reached the right first step, but drew the wrong conclusion from it.

**Ordinal 25's raw log.** It shows the reported class↔node and chain disagreements (83 failure lines).

##### L2. F2 overturned — the A6 extractor cannot emit a candidate on a closed quad complex

**Code facts at `582da20a`.**
- The A6 view builder unites edges `(0,2)` and `(1,3)` of every classed quad (`RemeshPipeline.cpp:6289-6291`), as R4 D3 §4.3 rule 7 specified ("transitive closure of the opposite-edge relation in quotient quads").
- In a quad, edges 0/2 and 1/3 are **parallel and disjoint**. The closure across a quad strip is that strip's **rung set**, a matching in which every vertex appears in exactly one rung.
- `extract_surface_quotient_simplification_candidates` (`:6343-6436`) then classifies each strip by vertex degree among its edges:
  - all degree 2 → `ClosedLoop`;
  - exactly two degree-1 vertices → `OpenStrip`;
  - otherwise `continue`.
- A rung set of `k ≥ 2` rungs has every vertex at degree 1, so `degreeOne = 2k`, and the strip is silently skipped.

On any closed manifold quad complex, every strip has at least two rungs, so the extractor returns an empty candidate set **regardless of protection**. Two consequences:
- The produced torus's empty result is a consequence of this, not a property of the fixture.
- RA-23's synthetic `4 x 4` periodic torus has four rungs per strip, `degreeOne = 8`, and **would also emit nothing**. R1 as planned (test-only, production frozen) was guaranteed to fail.

**Where the definition went wrong.** The retired arrangement extractor groups edges by `(family, strand)`, splits each group into **node-connected components**, and only then applies the same degree classification (`SurfaceComplexSimplification.cpp:1687-1740`). A strand is a field-aligned curve, i.e. an **edge chain**.

R4 §4.3 says it "replaces the old … `family/strand` grouping … with a topology-derived strip grouping". The topology-derived analogue of a strand is the **edge-loop** relation: at a regular vertex, continue through the opposite edge. Rule 7 used the quad-opposite relation instead.

R4-REV, which was mine, accepted rule 7 without checking it against the classifier it feeds, or against the strand semantics it claimed to replace. The error is shared and owned. TB11-REV's statement that "those implementations match the frozen §4.3 rules on static inspection" is true: the rule itself was wrong.

**Why the produced torus should be non-vacuous under edge loops.**
- The 18 user hard edges form one minor and one major cycle, each itself an edge loop. Those two loops are `hardFeatureProtected`.
- Every other edge loop is parallel to one of them. It crosses the other hard cycle only at a vertex, not along an edge, so it is unprotected.
- The torus has no boundary and no valence-≠-4 vertex.

So independently eligible `ClosedLoop` candidates exist, consistent with M4CP4's accepted non-vacuity on the same fixture under strand semantics.

##### L3. F1 confirmed in substance; RA-21c over-relaxes (RA-21d)

TB11-REV's mechanism is plausible and consistent with the counts: about 30 chain disagreements and 35 node disagreements on a torus with thousands of quotient edges. The arrangement builds scoped node identity, so it splits nodes and edges along barrier-carried seams; A5/A6 identify those seams by relation.

But RA-21c item 5 drops chain equality for **all** quotient edges, including `Ordinary` ones, where no barrier exists. Across an `Ordinary` front with no isolation transition, adjacent proposals share one front polyline, and the arrangement merges it into one edge chain with two opposite provenance entries. The small number of runtime disagreements shows equality holds there.

Dropping it throws away the oracle's discriminating power on the majority of edges. **RA-21d** restores equality:
- for `Ordinary` edges without isolation transitions;
- for the node witness of occurrence pairs joined by such relations.

The relaxation applies only across HardRail, Periodic and isolation-seam edges.

##### L4. Disposition changes

- **`M6-CP1-TB11-G4-EXEC-CAND-02`:** re-classified as a **production/definition defect**. The R4 D3 §4.3 rule-7 strip relation is incompatible with the candidate classifier.
  - Non-stable: the candidate is unpromoted, no accepted-green row was lost, and production does not yet call the A6 extractor.
  - +0 to stable accounting.
- **`...-CAND-01`:** remains a test-oracle defect (RA-21c + RA-21d).
- **R1 is re-scoped** to production + test, bounded:
  - Production: change only the A6 view's strip relation to edge-loop closure (RA-24).
  - Tests: identity 25 per RA-21c/RA-21d; identity 28 back to the produced torus (non-vacuity + tamper), with RA-23 item 1's universal checks against the edge-loop reconstruction.
  - RA-23 item 2's synthetic torus is withdrawn as a requirement; it may be kept as an extra mechanism case.
  - Protection, labels, classification and A5/A6/A7 semantics stay unchanged.

##### L5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 973/973 manifest, both ledgers, ordinal 25/28 raw logs re-derived. Ordinal 28 = empty candidate set. |
| F1 | Confirmed; RA-21d restores equality on non-barrier Ordinary edges. |
| F2 | **Overturned.** Rule 7 (quad-opposite → rung sets) is incompatible with path-degree classification, so zero candidates on any closed quad complex and RA-23 item 2 would also fail. RA-24: edge-loop closure. |
| R1 plan | Re-scoped: one production change (strip relation) + test oracles. |
| Accountability | R4 D3 rule 7 accepted by R4-REV (review agent) without a classifier-invariant check. Owned. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 196 — when replacing a grouping relation, check the invariants of every downstream classifier. |
| Successor | `M6-CP1-CB11-G4-R1` (re-scoped) → TB11-R1 477 → mandatory Review. |

## `Architecture_M6_CP1_TB12_Close_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB12_Close_R1_Review_Record.md`; moved verbatim.

### `M6-CP1-TB12-CLOSE-R1-REV` — Recovery Review Record

#### Verdict

**ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED / +0 STABLE REPRICING.**

Candidate package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` is promoted as the current reviewed M6 runtime authority. The immutable R1 gate is independently upheld at focused30 **30/30** + selector449 **449/449** = **479/479 PASS**, exact-one, zero skips, benchmark 0, with immutable postflight. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

Exact successor: runtime-free **`M6-CP1-CLOSE-REV`**. CP1 is not closed by this turn.

#### 1. Independent evidence re-derivation

- Runtime run/job: `37280517630 / 111667316992`.
- Result/log artifacts: `11333591947 / 11333547162`; provider ZIP SHA-256 `ef5dba1131f25025bc536ba160475191629cc8bffed0465a087dd72fc4d1474b / dd78296134b6e71d2080ab2b1b6623841f75725e6a43deffe6ec2ad50dd46e53`.
- Result self-manifest re-verified **497/497**; manifest SHA-256 `9d7f244f4996d06db10db756c3bf25e1495d9628b9bb3e92af8cfeb089a4bd67`.
- Focused ledger SHA-256 `296bc32f9ed1fc017c1ae7c5e48c67056a962a9c8f376333f1ca400bfde61e0a`; selector ledger SHA-256 `d5298b2aaaf55c1a458b1ec6e79954cbddc17dbf33be7baf0998f397d4a2908f`.
- Recomputed ledger order equals frozen focused30 **30/30** and selector449/routing449 **449/449**. Every row has selected=`1`, skipped=`0`, result=`PASS`; the RED ledger has no data rows.
- Frozen authorities re-hash to focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d` as the exact first-28 prefix, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
- Candidate package remains exact: source `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, packaged manifest **28/28**, exact GMP boundary, `runtimeExecution=false` for compile/package. R1 execution records no configure/compile/relink/discovery/benchmark/repair/mutation/retry.

The review source snapshot is run/artifact `37287216977 / 11335041130`, exact source/event `f6ffca2a1b6492e0685d0d93f82db996576cb7cc`, provider digest `e672793ad3519750789f2962dda351d756f37541a44ead5cb65af16714fe0cb1`, embedded archive SHA-256 `e470ad13d6498bff71409a56a3520348153013afdfde152132bdc8665419f572`, 5406 files, `runtimeExecution=false`.

#### 2. RA-27a implementation review

The R2 implementation is faithful to the frozen rule.

1. **Exact wedge graph.** A7 now accepts a multi-sheet occurrence only when its own `cornerWedgeIsolation` graph connects every member of `cornerWedgeSheets`. Only transitions in `occurrence.topologyRegion` whose two sheet endpoints are in that occurrence's sheet set are edges; traversal is undirected. Failure is `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`. Produced `cornerWedgeSheets` are sorted/unique before publication, matching the membership helper's binary-search precondition.
2. **Selected-forest edge rule unchanged.** The pre-existing disjoint-endpoint-sheet rule remains a separate check at site `cross-sheet`; R2 did not retarget or weaken it.
3. **C4 diagnostic.** `ClosedComplexStripContinuationMismatch` now maps exactly to `QuotientClosedComplexStripContinuationMismatch`.
4. **Identity29 consistent-chain falsifier.** The test proves baseline A5→A6→A7 acceptance, requires a multi-sheet bridge occurrence with non-empty wedge transitions, changes only that occurrence's transition sheet endpoints to unrelated IDs, republishes A5, re-produces A6 and requires A6 success, then requires A7 `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`. The transition vector remains non-empty, so the old non-empty proxy would accept the tamper while the exact graph rejects it.

Runtime focused ordinal29 PASS therefore establishes non-vacuity: the bridge was found, the tamper was reached, A5 publication and fresh A6 production succeeded, and the expected A7 rejection was observed. Ordinal30 also remains PASS. No accepted row regressed.

#### 3. Prior obligations

- `M6-CP1-TB12-CLOSE-EXEC-CAND-01`: **CLOSED / RECOVERY PROVED / NON-STABLE**. The corrected reachable-branch falsifier is green. It never enters stable totals because the original loss was a new unpromoted test-authority row, not accepted-green loss.
- RA-27a §2 / C1 reachable wedge proxy: **DISCHARGED** by the exact graph plus ordinal29 runtime falsifier.
- RA-27a §3 C4 name: **DISCHARGED** by exact source inspection. The earlier fail-closed behavior was already reviewed; this turn verifies the required diagnostic string correction.
- RA-27a §6 edge-rule executed falsifier: **CARRIED** to `M6-DEFN-R5` → `M6-CP3`, awaiting the first produced seam-collinear fixture; no hand-built relation record is authorized.
- `M6-CP1-TB12-REV-OBS-01` A6→A5 certificate binding: **CARRIED** to `M6-CP2` via `M6-DEFN-R5`.
- `M6-CP1-TB12-REV-OBS-02` relation-kind-agnostic selected-edge rule: **CARRIED** to `M6-DEFN-R5`.
- RA-26 §5 reference-selecting representative/permutation obligations: **CARRIED** to `M6-DEFN-R5` / `M6-CP3`; they do not block CP1.

No new regression candidate, category, recurrence, or debt is created.

#### 4. Promotion and successor boundary

Package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` becomes current reviewed M6 runtime authority under focused30 + selector449 = **479/479**. CP1 remains ACTIVE until the dedicated close Review re-derives all six frozen CP1 exit items and the carried close obligations against exact current source.

`M6-CP1-CLOSE-REV` is runtime-free. Its falsifiers are frozen in `Architecture_M6_CP1_Close_Review_Plan.md`: any missing CP1 exit item, any surviving authority-deciding provenance-face consumer, any undisclosed semantic adapter decision, any coordinate/position weld, or any contradiction with the promoted 479/479 evidence prevents CP1 closure and must be routed to the proper Definition/Code + Build owner rather than repaired in Review.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused28 `9154a986...011d` is the exact first 28 rows of focused30 `1e815443...a1d6`; selector449 `d4a0d1b7...d6414` and routing449 `9c88a5ed...c5707` independently re-hashed. |
| Decisive claims independently re-derived | 497/497 result manifest; 30/30 + 449/449 ledgers in frozen order; exact-one/zero-skip; candidate/package/source identity; RA-27a source/test semantics. |
| Non-vacuity checked | Ordinal29 PASS requires the multi-sheet bridge, non-empty tamper, A5 republish, fresh A6 success, and exact A7 wedge rejection; old non-empty proxy would accept the same non-empty tamper. |
| Prior obligations discharged/carried | CAND-01, C1 wedge proxy and C4 name discharged; RA-27a §6, OBS-01/02 and RA-26 §5 carried with owners in §3. |
| Stable accounting | 60 / 16 / 44, debt 1; promoted package/source `11330703256 / 3f40f04a...`; selector449 remains accepted. |
| New candidates/obligations recorded | None; tracker records recovery closure and carried existing obligations. |
| ORIENTATION currency line | `M6-CP1-TB12-CLOSE-R1-REV`, 2026-10-05 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 promoted 479/479 authority; §4 split-square wedge falsifier updated; §7 R2 item discharged and close Review made exact next; §8 cites existing lesson 199, no new pattern. |
| CHANGELOG | Root and agent changelogs updated with accepted R1 Review and promotion. |
| ROADMAP | n/a: CP1 remains ACTIVE; checkpoint status does not move until `M6-CP1-CLOSE-REV`. |
| Selector manifest | n/a: no selector file was added, modified, or newly accepted. |
| LESSONS | Existing lesson 199 applies; no genuinely new pattern. |
| Consolidation under CLEAN_UP_POLICY | Immediate TB12-close predecessor plan/report/review and consumed R2/R1 plans folded into `M6_Consolidated_Record.md` §48/index; current R1 runtime report retained. |
| Successor frozen | `M6-CP1-CLOSE-REV`; falsifiers in `Architecture_M6_CP1_Close_Review_Plan.md`. |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build source mutation and no generated Directional runtime. |
| review_check.py boundary | PASS — review-turn boundary check reports no product/test/fixture/build or selector mutation; all durable-marker checks pass. |
| `STATUS` lifecycle maintained | Entry beacon published; final COMPLETE beacon is the final repository action. |
| Pushed to origin, branch in sync | Connector-applied documentation patch and cleanup are verified on the configured working branch before final beacon. |

---

#### Review-agent addendum (2026-10-05, resumed `M6-CP1-TB12-CLOSE-R1-REV`)

**Disposition:**
- **Acceptance and promotion of `11330703256 / 3f40f04a...` (479/479): CONFIRMED.**
- **Two claims overstate the runtime proof** (Q3).
- **Two defensive branches have no executed falsifier and no owner** (Q4).
- The close plan does not freeze CP1's successor (Q5).
- **RA-27b** records owners and amends the close plan. The successor stays **`M6-CP1-CLOSE-REV`**.
- Accounting **60 / 16 / 44**, debt 1.

##### Q1. Independent re-derivation (confirmed)

- Result `11333591947`: ZIP `ef5dba11...`. Log `11333547162`: ZIP `dd782961...`.
- `SHA256SUMS` (`9d7f244f...`) verifies **497/497**: 479 raw logs plus metadata. This harness writes no per-process resource files.
- Focused ledger `296bc32f...` and selector ledger `d5298b2a...` are in exact focused-30 and selector449 order.
- Every row has selected=1, skipped=0, passed=1, PASS. **All 479 raw-log SHA-256 values match their ledger rows.** The RED ledger has a header only (`dc5496d3...`).
- Ordinals 29 and 30 are `[ OK ]`.
- Candidate `3f40f04a` source == HEAD source. Its diff from `02149f15` touches 2 files: `RemeshPipeline.cpp` (+26/−6) and the test file.

##### Q2. RA-27a code review (confirmed)

- **Wedge rule** (`RemeshPipeline.cpp:6884-6915`):
  - fixed-point reachability from `cornerWedgeSheets.front()`, over transitions with `region == topologyRegion` and both sheets in the set;
  - accepts only if the reachable set equals the sheet set;
  - single-sheet members pass trivially;
  - site `cross-sheet:wedge`.

  It matches RA-27a §2 exactly. The edge rule is unchanged.
- **Membership.** `wedge_contains_sheet` uses `binary_search`. The A5 *producer* sorts and dedupes (`:4446-4453`); `publish_records_for_validation` does not. Unsorted or duplicated input can only cause **false rejection**, never false acceptance, so this is fail-closed.
- **C4 name.** Now `QuotientClosedComplexStripContinuationMismatch`. This was required, not cosmetic: DEFN-R3 freezes "external A6 diagnostics use the `Quotient` prefix".
- **Identity 29.** It runs on a consistent chain:
  - bridge non-vacuity, then baseline acceptance;
  - every bridge transition rewritten to sheets 99→100, still non-empty;
  - republish A5, re-produce A6 and assert success;
  - A7 fails at `cross-sheet:wedge`.

  The old proxy accepts this tamper, so the test discriminates.

##### Q3. Overclaims (Low–Medium)

1. **"RA-27a §2 discharged by the exact graph plus the ordinal-29 runtime falsifier."** The tamper moves **both** endpoints of every transition outside the set, so it falsifies only the "no transition inside the set" case. These conjuncts are verified **statically only**:
   - the **region filter**: a mutant that ignores region passes identity 29;
   - **connectivity versus "touches the set"**: a mutant accepting any transition with one endpoint in the set also passes;
   - **three-sheet partial connectivity**.

   The production code is correct by inspection, but the record should say "static plus one runtime dimension". Owner for the missing tampers: Q6.
2. **"Produced `cornerWedgeSheets` are sorted/unique before publication."** True of the producer, not of the publication seam (Q2). Harmless, but imprecise.

##### Q4. Defensive branches with no executed falsifier and no owner (Medium; not CP1-blocking)

| Branch | Why it is unfalsified | Why it is not CP1-blocking | Owner (RA-27b) |
|---|---|---|---|
| C4 `ClosedComplexStripContinuationMismatch` (`:6310-6333`) | A non-unique opposite needs a pinched interior vertex: two 2-quad fans sharing one vertex. Only a weld produces that, and CP1 item 6 rules welds out. | It fails closed; identity 28 proves it does not fire falsely on the produced torus. | `M6-CP2-DEFN`: a weld-constructed malformed-authority witness, together with the verifier's manifoldness recompute (frozen §6.2). |
| C2 empty-front `MissingAuthoritativePhaseFront` | A4 rejects empty edges and cells first (identity 30 says so honestly). | Unreachable through product authority. | Accepted as defensive; no owner needed. |

TB12-R1-REV §3 lists neither branch. CLOSE-REV must classify each explicitly; RA-27b §3 amends the close plan to require this.

##### Q5. The close plan leaves CP1's successor open (Medium, routing)

`Architecture_M6_CP1_Close_Review_Plan.md` ends with "freeze exactly one next turn under the roadmap". The carried obligations, however, are split across two owners that the roadmap orders CP2 → CP3:
- **CP2 entry:** the verifier contract (frozen §6, §10). OBS-01, the missing A6 → A5 certificate binding, belongs here, because §6.2 lets the verifier check "deterministic equality of immutable certificate payloads". So does RA-26 §5(iii) (retire or replace the vacuous `project_vertices` sheet check), and the Q4 C4 witness.
- **CP3 entry (`M6-DEFN-R5`):** the gauge obligations, the A5 barrier-set census, RA-26 §5(i)(ii)(iv), RA-27a §6 (edge-rule falsifier) and OBS-02.

Letting CLOSE-REV choose freely invites jumping to DEFN-R5, which would skip CP2 and overload one Definition turn (lesson 188). **RA-27b freezes the post-closure successor as `M6-CP2-DEFN`**: a bounded, runtime-free definition of `SurfaceProductVerifier` with the CP2-entry items. `M6-DEFN-R5` follows CP2.

##### Q6. Observations

- **`M6-CP1-TB12-R1-REV-OBS-01`.** Identity 29 lacks region, one-endpoint and three-sheet tampers (Q3.1). Owner: the first `M6-CP2` Code + Build, as **new appended identities**; identity 29 stays unchanged.
- **`M6-CP1-TB12-R1-REV-OBS-02`.** The adapter maps `UncertifiedCrossSheetBinding` without A7's site (`RemeshPipeline.cpp:7462`), so edge and wedge failures share one adapter string. A7 keeps the site, so diagnosability is lost only at the adapter boundary. Owner: M8-CP2 (diagnostics).

##### Q7. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived: 497/497, frozen order, 479/479, all raw hashes match. |
| RA-27a code | Confirmed; fail-closed under malformed membership input. |
| Overclaims | Q3 recorded; runtime proof covers one dimension of the wedge rule. |
| Defensive branches | C4 → `M6-CP2-DEFN`; C2 empty-front accepted as defensive. |
| Close plan | RA-27b block: exit items verbatim from frozen §526; defensive-branch classification; `G4-B002` debt stays open; successor `M6-CP2-DEFN`. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 200. |
| Successor | `M6-CP1-CLOSE-REV`, unchanged. |

## `Architecture_M6_CP1_TB7_A6_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md`; moved verbatim.

### M6-CP1-TB7-A6 Review — HardRail Placement-Gauge Recovery

**Turn:** `M6-CP1-TB7-A6-REV`
**Type:** runtime-free Review + Plan
**Reviewed candidate:** `11257522199 / 40842caa88f8d7a08a38c91273ace77ebd7c0676`
**Authoritative TB7 run/job:** `37090507571 / 111109661723`
**Result/log artifacts:** `11262587435 / 11262387973`
**Disposition:** **CANDIDATE REJECTED / TWO STABLE RECURRENCES / ONE TEST-AUTHORITY DEFECT / CB8-A6 RECOVERY AUTHORIZED**

#### 1. Review conclusion

TB7-A6 is mechanically valid and its semantic RED is authoritative. The immutable gate executed all **11 focused + selector449 = 460** exact-filter processes with exact-one selection, zero skips and no benchmark/configure/compile/relink/repair/retry. Outcome is focused **11/11 PASS**, selector **432/449 PASS**, aggregate **443/460 PASS / 17 RED**.

Independent Review re-opens the primary result evidence and exact source and adjudicates the three EXEC candidates as follows:

1. `M6-CP1-TB7-A6-EXEC-CAND-01` is **STABLE**, one recurrence of existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`. CB7 conflated a HardRail carrier/topology route transport with the relation's cut-domain placement transport. The seven direct HardRail failures and seven downstream reachability losses share that mechanism.
2. `M6-CP1-TB7-A6-EXEC-CAND-02` is **STABLE**, one recurrence of existing `VALIDATION_ORDER_SHADOWING`. Rows227/230 still fail closed, but the new A5 pair-reciprocity gate pre-empts the accepted individual route-authority diagnostic.
3. `M6-CP1-TB7-A6-EXEC-CAND-03` is **CLOSED / NON-STABLE TEST-AUTHORITY DEFECT**. Selector446 now materializes successfully; its sole failure is a stale assertion equating RA-13 placement-gauge selected-step transport with `SurfacePeriodicHolonomy::action()` in the relation-endpoint gauge.

Stable accounting advances from **57 events / 16 categories / 41 recurrences** to **59 events / 16 categories / 43 recurrences**. Produced-witness debt remains **1**. Candidate `11257522199 / 40842caa...` is rejected/unpromoted. Reviewed runtime authority remains TB5 `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 **449/449**.

Exact successor is bounded runtime-free `M6-CP1-CB8-A6`, followed if compile/package green by fresh immutable `M6-CP1-TB8-A6-EXEC` over the same **11+449=460** shape and mandatory `M6-CP1-TB8-A6-REV`. `M6-DEFN-R4`, A7 and `G4-B002` remain held.

#### 2. Evidence authority and independent re-derivation

##### 2.1 TB7 evidence re-opened

Review independently verifies the retained TB7 result artifact ZIP against provider digest `sha256:87cfcda2502f10cfc74e04aecd6e32aaca629928dff966988f52751f59e44575` and its self-manifest **953/953**. The result self-manifest SHA-256 is `5a5abda8a8d51a4b75d2266fb0b34604e3d0d4179e731e48a52be5a18771508a`; execution/focused/selector ledgers are respectively:

- `fd41e71a538bb817cea5da989daf1e52a033d0a51818593ba03c3b8054bfa39f`;
- `f2a8cd85937258df3bd57767ce88b3b53f4faed826dfd68159e0a9544a30f11c`;
- `ac7883b7c652cdaedd21d19d5ed2867d6de6f11198f1fb9abf25d80efc8404e3`.

The 17 selector RED ordinals are exactly:

`115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 227, 230, 231, 446`.

Raw logs contain zero `QuotientHolonomyConflict` and zero `OccurrenceInvalidCornerAuthority`. `InvalidHardRailTransport` appears 10 times across 9 raw selector logs. Focused6/10/11 and selectors139/140/142/232/444/448/449 are green.

##### 2.2 Exact source authority

Review source snapshot run `37094244645` materializes exact branch authority `ea826744832357d7234ebc9d34c3d23cb9865207`; artifact `11263094759` has provider digest `sha256:ef9755771633a0a94e4470ff351e46d42b81a7531e75dfc4daab63e17834e182`, internal source archive SHA-256 `7d1b837ef9a3fc1b781bd37594538859bdf327ed63190d1e094a1428de639b8b`, **5323** verified source files and `runtimeExecution=false`.

The CB7 package embeds semantic source archive `source-40842caa88f8d7a08a38c91273ace77ebd7c0676.tar.gz` with SHA-256 `2c8981c6da6e9e72b4977f2879a687e2ba1c6c042591bd82720936f69888d27f`. Review byte-compares the decisive implementation/test files between that packaged source and the current snapshot; all are identical: `RemeshPipeline.cpp`, `SurfaceCellTracing.cpp`, `PureQuadCompletion.cpp`, their relevant headers, `SurfaceCellTransitionQuotientTests.cpp`, `SurfaceCellsPhase10Tests.cpp`, and `SurfaceCellREPackageTests.cpp`. Static findings therefore apply to the exact runtime candidate rather than only to later documentation state.

#### 3. Finding A — HardRail carrier route was promoted into the wrong transport domain

**Candidate:** `M6-CP1-TB7-A6-EXEC-CAND-01`
**Classification:** **STABLE / existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence**
**Accounting:** **+1 event / +1 recurrence / +0 categories**.

##### 3.1 Direct evidence

The CB7 A5 HardRail branch correctly restores common rail owner, distinct source topology region and exact reversed-route reciprocity. It then publishes:

- `sharedEquivalence.route = first.route`;
- `sharedEquivalence.action = first.route.composed_transport()`;
- `storageTransport = sharedEquivalence.action`;
- two placement-state `action_matches` checks across the paired HardRail endpoints.

That last step crosses authority domains. Exact source in `assign_open_front_boundary_authority` constructs retained HardRail carrier steps with `TransitionStep::interior(..., GridAutomorphism::identity(), runOrientation)`. The route is exact transition/topology/carrier provenance; its composed transport is not thereby a map between the paired endpoint occurrences' cut-domain `LocalLatticeState` placements.

This is not a speculative interpretation. Row141 first establishes a valid reciprocal HardRail pair (common rail and exact reversed routes) and then materialization fails `InvalidHardRailTransport`. The direct accepted-green losses 115/116/141/143/150/217/231 all fail on the new HardRail placement-action condition. CB7's own RA-13 stop rule explicitly required Review if HardRail route transport proved not to be in placement gauge. That stop condition has fired.

##### 3.2 Downstream grouping independently confirmed

The seven downstream REDs do not expose separate first mechanisms:

- 122 cannot find HardRail feature authority to tamper;
- 130/132/134 cannot reach the final oracle with non-empty remapped feature authority;
- 137 cannot reach final validation;
- 176 reaches `NotProductionReady` instead of its injected later-stage failure;
- 201 reaches `NotProductionReady` at `tracing` rather than its injected `arrangement` failure and never observes the expected rail/network state.

These identities previously depended on the same valid HardRail-producing path. Their first failures are loss of downstream reachability after A5 rejects that path, not independent newly-authored semantics. They are therefore grouped with the direct HardRail placement-domain defect as one stable event, not priced separately.

##### 3.3 RA-14 — HardRail carrier route and placement transport are separate authorities

This Review freezes the following normative amendment to RA-13:

1. `PureQuadEquivalenceProvenance.route` remains the exact HardRail **carrier/topology/transition provenance**. It is validated structurally, carries source hard-feature edge/component evidence, and must remain exactly reciprocal across the relation pair.
2. HardRail `canonicalTransport` / selected-step `appliedTransport` is instead the unique **cut-domain placement transform** between the paired endpoint `LocalLatticeState`s in canonical relation direction.
3. For one source placement state `a` and destination state `b`, derive the only candidate grid automorphism directly from their exact state:
   - require equal `scaleLevel`;
   - `R = branch(b) ∘ branch(a)⁻¹`;
   - `t = b.latticeCoordinate - rotate(R, a.latticeCoordinate)`;
   - `T = {R,t}` and verify it with the existing `action_matches` predicate.
4. Derive `T0` independently for `first.fromLattice -> second.toLattice` and `T1` for `first.toLattice -> second.fromLattice`. The HardRail relation is valid only if both exist and `T0 == T1`. Otherwise fail closed with existing `InvalidHardRailTransport` through `HardRailTransportMismatch`.
5. Publish that unique placement map in `sharedEquivalence.action` and as A5 `canonicalTransport`; preserve `sharedEquivalence.route` separately. A6 continues to consume canonical A5 transport and keeps the strict cycle rule unchanged.
6. The completion selected-relation consumer must compare a HardRail selected step against orientation-adjusted `equivalence.action`, not recompute `equivalence.route.composed_transport()`. The route remains mandatory for the independent hard-feature component/topology certification already performed by `completion_certified_hard_rail_components`.
7. No consumer may infer quotient placement transport from carrier-route transport merely because both belong to the same HardRail evidence object.

This derivation is not circular: relation identity/owner, source regions and reciprocal route are independently fixed first, and the second endpoint pair is an independent coherence constraint on the placement map.

**Stop rule:** if the two exact endpoint pairs do not yield one unique transform, or another current consumer demonstrably requires route-composed transport to remain the quotient placement authority, stop for Review rather than weakening the endpoint check.

#### 4. Finding B — malformed route authority is validated after A5 pair reciprocity

**Candidate:** `M6-CP1-TB7-A6-EXEC-CAND-02`
**Classification:** **STABLE / existing `VALIDATION_ORDER_SHADOWING` recurrence**
**Accounting:** **+1 event / +1 recurrence / +0 categories**.

Rows227/230 intentionally corrupt individual HardRail route topology. Accepted behavior is typed `InvalidHardRailAuthority`. They still fail closed under CB7, but now return `InvalidHardRailTransport` because A5's reciprocal route equality runs before the materializer's existing exact route-topology validator.

Exact source proves the ordering: `SurfaceOccurrenceComplexProducer::produce(...)` executes before the adapter defines/applies `exact_interior_route_valid`; malformed individual route content can therefore be compared as a relation pair before its own source transition/topology authority is established.

##### RA-15 — individual route authority precedes relation-pair reciprocity

CB8 must preserve the accepted typed ordering without weakening the recovered row139/142 reciprocity checks:

1. Extract/reuse the existing exact individual interior-route validator rather than maintaining two divergent implementations.
2. Run the individual HardRail/Periodic route source/topology validity preflight **before** `SurfaceOccurrenceComplexProducer::produce(...)` can publish relation-pair evidence.
3. Preserve accepted adapter failures: malformed HardRail route -> `InvalidHardRailAuthority`; malformed Periodic route -> its existing `InvalidPeriodicCutAuthority` path.
4. Once an individual route is valid, A5 still requires HardRail common owner, different source region and exact reversed-route pair; those relation-pair mismatches remain `InvalidHardRailTransport`.
5. Remove/avoid a duplicate later semantic validator after the earlier shared preflight so one predicate owns the route-authority contract.

Rows227/230 are the typed-order falsifiers. Rows139/142 and row140 are non-weakening controls.

#### 5. Finding C — selector446 pins the pre-RA-13 representation

**Candidate:** `M6-CP1-TB7-A6-EXEC-CAND-03`
**Classification:** **CLOSED / NON-STABLE TEST-AUTHORITY DEFECT**
**Accounting:** **+0**.

Selector446 now clears the production behavior that TB6 was intended to recover:

- materialization succeeds;
- focused6 passes the same nonzero-Z4 witness under storage swap;
- no raw log contains `QuotientHolonomyConflict`;
- selectors232/444/448/449 remain green.

Its only failing assertion occurs after successful materialization. The test scans selected relation steps and requires `step.appliedTransport == relation->action()` or inverse. Exact-A3 RA-13 intentionally changed `appliedTransport` to the placement-gauge map `Γ_to⁻¹ ∘ g ∘ Γ_from`; `relation->action()` remains semantic `g` in `SurfacePeriodicRelationEndpointState` relation-endpoint gauge. The test compares two different authorities and is stale.

##### Authorized test-only migration

CB8 may change only selector446's assertion body, not its identity or selector449 bytes. The replacement oracle must remain independent and stronger than a tautological product echo:

1. Preserve the existing checks that published periodic endpoint states match `make_periodic_relation_endpoint_state` and that semantic `g` maps those endpoint states correctly.
2. Independently derive the direct placement map from the paired `LocalLatticeState` endpoints using the same exact state-to-state formula frozen in RA-14.
3. Independently derive the gauge-conjugated map `Γ_to⁻¹ ∘ g ∘ Γ_from` from the published endpoint states and semantic action.
4. Require those independently derived placement maps to agree.
5. Require the selected periodic step for the relation to equal that placement map or its exact inverse according to step direction.

Do not change row446 into “compare selected step with A5 canonicalTransport” alone; that would only restate the product under test.

#### 6. Non-vacuity, controls and carried obligations

- Focused6 PASS proves the nonzero-Z4 periodic strict-cycle recovery itself is no longer broken.
- Focused10/11 PASS preserve exact-once/certificate-conflict and strict cycle-conflict rejection.
- Selector139/142 PASS prove CB7's recovered HardRail pair reciprocity is live; selector140 keeps independent owner mismatch live.
- Selectors232/444/448/449 PASS preserve periodic control populations and the accepted full selector tail.
- The HardRail direct failures plus downstream seam losses make RA-14 falsifiable; CB8 cannot merely delete the placement check.
- Rows227/230 make RA-15 falsifiable; CB8 cannot merely update expected error strings.
- A7, `M6-DEFN-R4`, `G4-B001`, `G4-B002`, `G4-B004` representative-consumption work and CP1 closure remain carried and held.

#### 7. Accounting and promotion

Review prices exactly two stable mechanisms:

1. CAND-01 -> one `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence;
2. CAND-02 -> one `VALIDATION_ORDER_SHADOWING` recurrence.

CAND-03 is a test-authority correction and contributes no stable event. Stable accounting is therefore **59 / 16 / 43**, debt **1**.

Candidate `11257522199 / 40842caa...` is rejected/unpromoted. Reviewed runtime authority remains package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8` with selector449 **449/449**.

#### 8. Exact successor — `M6-CP1-CB8-A6`

CB8 is a bounded Code + Build turn under `Architecture_M6_CP1_CB8_A6_HardRail_Placement_Transport_Recovery_Code_Build_Plan.md`. It may modify only:

- A5 HardRail placement-transport derivation/publication;
- the one HardRail selected-relation completion consumer that currently substitutes route-composed transport for placement transport;
- individual route-validation ordering/shared helper needed for rows227/230;
- selector446 test body and bounded focused/static assertions needed to directly falsify RA-14/RA-15 without increasing the frozen focused count.

It may not change selector449/routing449 bytes, fixtures, relation identity/equality/owner selection, A6 strict cycle semantics, A7/R4/G4 surfaces, or accepted failure strength.

Compile/package green -> fresh `M6-CP1-TB8-A6-EXEC` over **11 focused + selector449 = 460** exact fresh processes -> mandatory `M6-CP1-TB8-A6-REV`.

#### 9. Review closeout

| Duty | Result |
|---|---|
| Primary runtime evidence re-opened | TB7 result ZIP/provider digest, 953/953 self-manifest, ledgers, raw RED logs and controls independently inspected. |
| Exact source independently re-opened | Runtime-free snapshot `37094244645 / 11263094759` verified; decisive source/test files byte-identical to packaged semantic source `40842caa...`. |
| Candidate mechanisms adjudicated | CAND-01 stable RP-01; CAND-02 stable validation-order shadowing; CAND-03 closed non-stable test authority. |
| Stable accounting | **59 / 16 / 43**, debt 1. |
| Normative amendments | RA-14 HardRail carrier/placement separation; RA-15 individual route validation precedes pair reciprocity. |
| Test authority | Selector446 body migration authorized with independent direct-placement + gauge-conjugation oracle; identity/selector bytes frozen. |
| Promotion | TB7 candidate rejected; TB5 reviewed runtime retained. |
| Successor | Exactly one: `M6-CP1-CB8-A6`; then TB8-A6 460-process gate + mandatory Review. |
| Turn boundary | Runtime-free Review; no generated Directional executable executed. |
| Consolidation | Superseded CP1 per-turn docs are folded into `M6_Consolidated_Record.md`; current TB7 report, this Review, one CB8 plan, frozen definitions and selectors remain. |
| Tool-call ledger | **unknown/partial** after context compaction; not reconstructed by extra tool calls, per conservation policy. |

---

#### Review-agent addendum (2026-10-03, resumed `M6-CP1-TB7-A6-REV`)

**This addendum overrides §§3.3, 5, 7 and 8 above where they conflict.**

| Item | Result |
|---|---|
| Evidence re-derivation | Confirmed |
| Finding A diagnosis | Confirmed |
| Finding B diagnosis | Confirmed |
| RA-14 derivation | **Corrected** (RA-16) |
| RA-15 location | **Pinned to A5** |
| Finding C | **Overturned:** production regression, +1 stable |
| CB8 plan | **Amended:** the selector446 migration and the completion-consumer edit are revoked; focused identity 12 is added; TB8 becomes **12 + 449 = 461** |

- Stable accounting: **60 / 16 / 44**, debt **1**.
- Candidate `11257522199 / 40842caa...` stays rejected. Reviewed runtime authority stays TB5 `10879581622 / 82b86a28...`.
- Successor is unchanged: `M6-CP1-CB8-A6`, as amended.

##### G1. Independent re-derivation (confirmed)

**Artifact.**
- I downloaded result artifact `11262587435` again. The ZIP SHA-256 equals the provider digest `87cfcda2...44575`.
- `SHA256SUMS` verifies **953/953**; the manifest is `5a5abda8...`.
- The execution, focused and selector ledgers are `fd41e71a...`, `f2a8cd85...` and `ac7883b7...`.

**Selector ledger.**
- Its identities equal selector449 (`d4a0d1b7...d6414`) in exact file order.
- Outcome is **432 PASS / 17 RED**, at exactly 115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 227, 230, 231 and 446.
- Every row has selected=1 and skipped=0. Focused is 11/11 PASS.
- The boundary file records 460 executed, no orchestration failure, and every repair/mutation/retry flag false.

**Raw first failures.**
- 115/116/141/143/217/231: `materialized.success` is false with `InvalidHardRailTransport`.
- 150: `NotProductionReady:tracing:InvalidHardRailTransport`.
- 227/230: expected `InvalidHardRailAuthority`, actual `InvalidHardRailTransport`.
- 446: materialization succeeds, then only `EXPECT_TRUE(selected)` fails (tests `:4213`).
- All 460 raw logs contain zero `QuotientHolonomyConflict`.

**Downstream grouping, verified in code (the logs alone cannot show it).** Rows 122/130/132/134/137 assert reachability before printing any root code. The grouping holds because:
- component stage products, including `authoritativeRails`, are published only on the success path (`RemeshPipeline.cpp:11912`);
- `captureFinalValidationAuthority` returns early when `!run.result.is_produced()` (`:14302`).

So once a HardRail component fails to materialize:
- row 122's hook still sees `Produced` from the phase-front producer, but finds no HardFeature rail to tamper;
- rows 130/132/134/137 never observe feature authority;
- rows 176/201 stop `NotProductionReady` at `tracing` (row 201's log shows stage `tracing`).

**Source identity.** HEAD `src/`, `include/` and `tests/` are byte-identical to `40842caa` (`git diff 40842caa..HEAD` is empty), so every citation below is the exact runtime candidate.

##### G2. Finding A is confirmed, but RA-14's remedy depends on the face gauge

**Diagnosis confirmed.** Retained HardRail carrier steps are published as `TransitionStep::interior(topology, transitionId, GridAutomorphism::identity(), runOrientation)` (`SurfaceCellTracing.cpp:11670-11672`). `route.composed_transport()` is therefore always identity for HardRail. It records which source edges the rail runs along, not the map across the rail.

**Defect in the remedy.** RA-14 derives `R = branch(b) ∘ branch(a)⁻¹`. But `LocalLatticeState.branchRotation` is face-gauged, not a pure lattice frame:

- Cell corner states take `branchRotation = faceBranchRotation[selected source face]`, plus the region's `chartUBranch` (`SurfaceCellTracing.cpp:12094-12095`, `:16324-16326`).
- `faceBranchRotation` is propagated **per topology region**, starting from that region's own root (value 0), across dual edges by FieldTransportAtlas transport (`:14920-14985`; `resolve_branch_transition` uses `atlas->transport`, `:6409+`).
- A3 strips this face gauge before it compares periodic endpoints (`make_periodic_relation_endpoint_state`, `:7926-7931`).
- A4 certifies exact-A3 periodic correspondence only in that face-free relation-endpoint gauge (`:8262-8291`). A4 certifies no lattice relation across a HardRail at all.

Consequence: take endpoint states `a` (region A, selected face `f_a`) and `b` (region B, face `f_b`). Then

  `branch(b) − branch(a) = R_true + τ(f_a → f_b)`,

where `τ` is the field matching across the rail between the two selected faces. RA-14's `R` is the true lattice rotation only when `τ = 0`.

**Why the gate cannot see it.**
- Every HardRail fixture in the 460 gate uses a constant field: `constant_xy_field` / `constant_xy_raw_field` (e.g. `hard_rail_fixture`, the rectangular builder in `SurfaceCellsPhase10Tests.cpp`). So `τ = 0` everywhere and RA-14 would pass TB8.
- Nonzero matching across hard carriers is real. The repo's own nonzero-Z4 witness has to search for hard carriers whose matching is nonzero (`SurfaceCellTransitionQuotientTests.cpp:1351-1363`).
- On a separating rail with `τ ≠ 0`, RA-14 yields `T0 ≠ T1` for a valid pair, because the edge vector does not rotate by `τ`. It fails closed with `InvalidHardRailTransport`.

That is a production regression selector449 cannot detect.

**The "non-circular" claim.** RA-14 §3.3 says its derivation is not circular. Re-checking a state-derived `T` with `action_matches` is tautological for that same pair. The only real content is `T0 == T1`, i.e. rigidity of the edge correspondence. RA-16 keeps exactly that rigidity check without the face gauge.

**Second defect: wrong source states.** A5 derives transports from the `SurfaceFrontEdge` lattice copies (`first.fromLattice`, ...). The adapter only checks those copies against the cell corners afterwards (`lattice_equal`, `RemeshPipeline.cpp:5798-5806`).
- So tampering an edge lattice on a HardRail or Periodic edge now fails as a transport error instead of `InvalidAuthoritativePhaseFrontSideAuthority`.
- Only the OrdinaryInterior variant is pinned (tests `:3251-3263`).
- RA-16 therefore derives from the endpoint occurrences' `placement.lattice`, which are the objects the relation actually unites.

##### G3. Finding C is overturned: selector446 falsifies a production lineage regression (+1 stable)

**Mechanism (three steps).**
1. A5 builds the lineage selected step with `step.appliedTransport = evidence.canonicalTransport` (`RemeshPipeline.cpp:4357`).
2. A6 requires `selectedRelationStep->appliedTransport == canonicalTransport` for HardRail and Periodic certificates (`:4723-4724`, `:4749-4750`).
3. RA-13 changed `canonicalTransport` to the placement gauge for the A6 certificate. Through steps 1-2, CB7 therefore also changed the representation of the M5 lineage `SelectedRelationStep.appliedTransport`. RA-13 never authorized that.

**Production consumer.**
- `close_completion_lineage_source_authority` validates every selected step against its lineage equivalence:
  - HardRail: orientation-adjusted `equivalence.route.composed_transport()` (`PureQuadCompletion.cpp:1086-1092`);
  - Periodic: orientation-adjusted `equivalence.action` (`:1105-1128`);
  - otherwise it fails `CompletionOwnershipSelectedRelationValueMismatch` (`:1132`).
- The authoritative pipeline runs this check immediately after materialization (`RemeshPipeline.cpp:10705-10719`) and fails `NotProductionReady` at `completion`.
- Periodic `equivalence.action` is `storedRelation.action()`, i.e. `g` (`:4234`). For any exact-A3 relation with `Q ≠ 0`, the placement map is neither `g` nor `g⁻¹`, so production completion rejects it.
- The gate is blind to this: the nonzero-Z4 witness is materialized only, never completed.

**Selector446 mirrors that check.** Its predicate (`SurfaceCellTransitionQuotientTests.cpp:4204-4213`) is the same comparison production completion makes. It is not stale; it is the gate's only falsifier of this defect.

**What the TB7-REV CB8 plan would have done.**
- (a) Migrated selector446, which deletes that falsifier.
- (b) Changed only the HardRail half of the completion check (plan §2.3). The periodic half would still compare against `g`, so the defect ships.
- (c) Written the placement map into HardRail `equivalence.action` (RA-14 item 4). That field is hashed (`RemeshPipeline.cpp:2718`), checked during component aggregation (`:15533-15537`) and benchmark-hashed (`BenchmarkQuality.cpp:1131`). This contradicts lesson 185, which TB7-REV itself recorded.

**Correction (RA-16 §3): decouple the two values.**
- A5 publishes two A5-owned values per relation, both in canonical direction:
  - `canonicalTransport`: placement gauge; feeds the A6 certificate and the strict cycle rule;
  - `canonicalRelationValue`: the M5 lineage relation value. That is identity for OrdinaryFront, `route.composed_transport()` for HardRail, `g` oriented for exact-A3 Periodic, and the existing selected action for non-A3 Periodic.
- The selected step carries `canonicalRelationValue`.
- A6 already keeps `pathCertificate.composedTransport` (placement) separate from `legacyProjection` (`:4912-4924`; validator `:5339-5346`).
- Result: the lineage projection is byte-identical to the pre-RA-13 projection on every accepted row. Completion and selector446 stay unchanged.

**Accounting.** One event and one recurrence of `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: the A6 quotient-certificate transport and the M5 lineage relation value were conflated through one field.
- Root cause: RA-13 (review agent) did not list the consumers of `canonicalTransport`, and CB7 inherited the field coupling.
- Stable accounting becomes **60 / 16 / 44**, debt 1.

##### G4. Finding B is confirmed; RA-15 moves into A5

**Diagnosis confirmed.**
- Row 227 duplicates a route step (tests `:5233-5250`); row 230 replaces a step's interior transition id (`:5190-5230`).
- Both routes are individually invalid under the adapter's `exact_interior_route_valid` (`RemeshPipeline.cpp:5752-5773`). That check only runs after A5: A5 runs at `:5711`, the check at `:5884-5888`.

**Controls survive the reorder.**
- Row 139 swaps in another real edge's route, and row 142 copies `first.route`. Both routes are individually valid (`SurfaceCellsPhase10Tests.cpp:6804-6843`), so they still reach the reciprocity check.
- Row 140 is an owner mismatch and is unaffected.

**Location correction.**
- A5 already receives the needed inputs: `produce(sourceVertices, sourceFaces, phaseFront)` (`:3284`).
- Extract the predicate once as a free function. A5 applies it to both HardRail sides before any pair predicate, with a distinct A5 code `HardRailRouteAuthorityInvalid` that maps to `InvalidHardRailAuthority`.
- The adapter keeps calling the same function for unpaired and exterior edges.
- Do not build an adapter-wide preflight. It would change precedence against every other per-edge adapter check, and it keeps semantic validation in the adapter, against the CP1 thin-adapter exit criterion.
- Periodic is already covered upstream: A4 rejects non-reciprocal and renumbered exact-A3 periodic routes during product construction (`SurfaceCellTracing.cpp:8218-8225`).

##### G5. Exact-A3 Periodic: a latent issue, carried to R4

CB7's `periodic_endpoint_gauge` (`RemeshPipeline.cpp:4034-4060`) builds Γ state-to-state, so Γ includes a rotation by `[Q]−F` about the endpoint. Its final `action_matches` (`:4293-4299`) then compares face-gauged branches.

- A4 constructs relation endpoints with `Q = g.rotation`. Under that convention, `T = Γ_to⁻¹ ∘ g ∘ Γ_from` has linear part `rot(F_rt − F_ff)`.
- `T` equals the coordinate map `rot(Q)⁻¹ ∘ g` exactly when the face gauges at corresponding corners agree (`F_rt = F_ff`).
- Otherwise `T_from ≠ T_to`, and an A4-valid product is rejected with `PeriodicTransportMismatch`.
- The non-constant-field witness has equal gauges (focused6 and 446 materialize), so no gate row reaches the other case.

Disposition: no change in CB8, since the output is provably identical whenever CB7 accepts. `M6-DEFN-R4` carries an obligation to supply a witness with unequal corner gauges and to replace the face-gauged final check with coordinate and relation-gauge checks. Focused 12(c) pins the coordinate rule meanwhile.

##### G6. Review-agent accountability (RA-13)

- **Item 1** mandated `action_matches` on face-gauged placement states for every relation. That is unsound across faces: applied to OrdinaryFront, it would reject valid relations whose two sides select faces with nonzero matching. CB7 happened not to apply it there.
- **Item 4** predicted selector446 would PASS. I did not audit the assertions over `appliedTransport`, nor the consumers of `canonicalTransport` (lesson 180 again).
- **The HardRail clause** handed a statically answerable question to a stop rule that a runtime-free CB could not fire reliably. `SurfaceCellTracing.cpp:11670-11672` already answered it.

Lessons 186 and 187 record these.

##### G7. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Result ZIP digest, 953/953 manifest, three ledgers, 460 raw logs and selector order independently verified. |
| Source authority | HEAD source is byte-identical to `40842caa`; every citation is to the runtime candidate. |
| Finding A | Diagnosis confirmed. Remedy replaced by RA-16 §2: coordinate-rigid derivation from occurrence placements; no cross-region branch comparison. |
| Finding B | Confirmed. RA-15 location pinned to A5 (RA-16 §5). |
| Finding C | **Overturned.** Production lineage-contract regression (`PureQuadCompletion.cpp:1086-1132`, `RemeshPipeline.cpp:10705-10719`). Selector446 retained as falsifier. +1 stable RP-01. |
| Accounting | **60 / 16 / 44**, debt 1. |
| Definitions | RA-16 frozen. RA-14 items 2-5 superseded; RA-13 item 1 withdrawn; RA-15 item 1 located. |
| CB8 plan | Amended: decoupling, coordinate-rigid HardRail, A5-owned route validity, selector446 unchanged, `PureQuadCompletion.cpp` untouched, focused 12 added. |
| TB8 gate | **12 focused + selector449 = 461** fresh exact-filter processes; recovery-green **461/461**. |
| Carried | R4: periodic coordinate-rule replacement with a face-gauge witness, cross-region branch certification, OrdinaryFront coordinate identity across isolation seams. |
| Turn boundary | Runtime-free; no generated Directional executable run. |

## `Architecture_M6_CP1_TB8_A6_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB8_A6_Review_Record.md`; moved verbatim.

### `M6-CP1-TB8-A6-REV` — Independent Runtime-Free Review Record

**Disposition:** ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED / CP1 REMAINS OPEN.

#### 1. Authority independently re-opened

Review re-opened the immutable TB8 result rather than relying on the EXEC summary.

- Candidate package/source: `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`.
- Candidate ZIP SHA-256 independently re-hashed: `022a35378a58463b892f1bf1d5113f726c2cc7cb8939892b24acd1da62259c4b`.
- Candidate root `SHA256SUMS`: 28/28 verified; packaged source archive SHA-256 `7220c197eae6b69957b71d6136eb3fce2b6f875bdc3ed3a298537720fef00296`.
- Candidate metadata still says `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.
- selector449 independently hashes to `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` with 449 rows; routing449 independently hashes to `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with 449 rows.
- Branch comparison from semantic source `8e0818b1...` to review control SHA `c13d157f...` contains only documentation/control-state changes; no `src/`, `include/`, `tests/`, fixtures or selector/routing semantic file changed.

TB8 runtime authority is run/job `37121395619 / 111198068572`. Result/log artifacts are `11273611682 / 11274345428`, provider digests `sha256:55647d752e97cb71062c23475fe76bb870d0329c5f957ca819ccebc809e6ad05` / `sha256:36f674b7dd8eab84b1ad3c9c2486ce94f8a369f81994da3418b1c41fcb34d98e`.

The downloaded result ZIP independently re-hashes to the provider digest and its self-manifest verifies **954/954**.

#### 2. Mechanical gate verification

The result ledgers prove the frozen order and complete coverage:

- focused ledger: 12 rows, ordinals 1-12, **12/12 PASS**;
- selector ledger: 449 rows, ordinals 1-449, **449/449 PASS**;
- aggregate: **461/461 PASS**;
- exact-one selection: true for every process;
- zero skips;
- benchmark execution: 0;
- empty RED ledger.

Independent ledger hashes match the EXEC report: focused vector `534771e30147a0d4791f596c8900b6f41d32633011345f563251c344845c04a7`; focused ledger `d9a3e24a59646d90411fecf99b5bf7617cd2346b2f426acb1df2f054e78019d0`; selector ledger `3baad8ec2a7843551dfa4e1ecf07ea9582a3de13b4d74e9257154012343996b8`; combined ledger `20ea03fa623dd8813a5ccf69ec4d3e26023b4ce2db423dc8e11de48eec177592`; header-only RED ledger `3f685d2b69788508657c64cc1bf398cc9a301dc901974c3bac1fc3f2795a6eae`.

Execution boundary is clean: runtime started/completed, preflight complete, no orchestration failure, selection integrity true, and configure/compile/relink/discovery/benchmark/package-repair/mode-repair/source/test/fixture/selector mutation/retry-after-runtime-start all false. Package/source/execution-view/fixture censuses are equal pre/post; selector/routing remain unchanged; root package manifest remains 28/28.

#### 3. Recovery adjudication

TB8 satisfies every recovery condition registered by the TB7 Review addendum.

- **HardRail placement authority / RP-01:** focused12 passes the coordinate-rigid two-endpoint mapping and branch-relabel invariance contract. Prior direct/downstream RED rows `115,116,122,130,132,134,137,141,143,150,176,201,217,231` all recover.
- **HardRail route-validation precedence / VALIDATION_ORDER_SHADOWING:** rows227/230 recover their accepted typed behavior; valid-route reciprocity controls 139/142 and owner control 140 all pass.
- **Lineage value / RP-01:** selector446 passes unchanged, proving the restored M5 selected-step relation value is compatible with production completion while A6 placement transport remains separate. Focused6 and periodic controls 232/444/448/449 remain green.
- Raw diagnostic census is zero for `QuotientHolonomyConflict`, `OccurrenceInvalidCornerAuthority`, `InvalidHardRailTransport`, and `RelationCertificateConflict`.

The three TB7 stable events are therefore **RECOVERY PROVED**. Historical stable accounting is append-only and remains **60 events / 16 categories / 44 recurrences**. Produced-witness debt remains **1**.

#### 4. Source review and promotion

Review directly re-opened candidate source. A5 applies the shared `exact_interior_route_valid` predicate to both HardRail sides before owner/region/reversed-route pair predicates; malformed routes map to legacy `InvalidHardRailAuthority`. HardRail placement transport is derived only from the four endpoint occurrence `placement.lattice` states, maps both paired coordinates, and does not compare branch rotations. `canonicalRelationValue` is stored separately from `canonicalTransport`; selected lineage steps consume `canonicalRelationValue` while A6 certificates consume placement transport.

Focused12 independently exercises both HardRail endpoint mappings, face-gauge branch relabel invariance, class-member invariance, and the nonzero-Z4 periodic placement-vs-relation-value split. No static contradiction with RA-16 was found.

Candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` is **PROMOTED as current reviewed M6 runtime authority** under unchanged selector449 449/449.

#### 5. CP1 disposition and exact next turn

CP1 does **not** close here. Frozen CP1 exit scope still requires the A7 `SourceAttachedGeometryProduct`, a thin semantic-free adapter, and the `G4-B002` A6-derived stage boundary. Those were deliberately deferred from R3.

Exact next is runtime-free **`M6-DEFN-R4`**. R4 must freeze:

1. A7 representation/certificates: one embedded output vertex per A6 semantic class, exact source-support and geometry-embedding certificates, complete wedge-union sheet/chart/equivalence lineage, representation-only representative selection, and no topology mutation/reselection.
2. The A6-derived closed-complex `G4-B002` stage-boundary representation and the CP1 equivalence proof on an existing closed fixture; CP3 retains direct-production eligibility/hard-feature-tamper debt proof.
3. The carried exact-A3 periodic obligation: an unequal-corresponding-corner face-gauge witness and replacement of the face-gauged final check with coordinate and relation-gauge checks.
4. Cross-region branch certification for HardRail and OrdinaryFront coordinate identity across isolation seams.
5. The bounded A7 + thin-adapter Code + Build sequence and its pre-registered focused/selector preservation gate.

`M6-DEFN-R4` is Definition-only and runtime-free; implementation remains held pending its mandatory Review. A7/G4 implementation must not start in this Review turn.

---

#### Review-agent addendum (2026-10-03, resumed `M6-CP1-TB8-A6-REV`)

**Disposition.**
- **Acceptance and promotion: CONFIRMED.** Candidate `11265967968 / 8e0818b1...` is current reviewed runtime authority.
- **One overclaim corrected:** the §3 selector446 statement (H2).
- **R4 scope: RE-BOUNDED.** The `M6-DEFN-R4` plan now exists: `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md`.
- **Accounting unchanged:** 60 / 16 / 44, debt 1.
- **Successor unchanged:** `M6-DEFN-R4`.

##### H1. Independent re-derivation (confirmed)

**Result artifact.**
- I downloaded result `11273611682` again; the ZIP SHA-256 equals the provider digest `55647d75...e6ad05`.
- `SHA256SUMS` verifies **954/954**.
- The focused vector, focused, selector, execution and RED ledgers hash to `534771e3...`, `d9a3e24a...`, `3baad8ec...`, `20ea03fa...` and `3f685d2b...`, matching the report.

**Ledgers.**
- The selector ledger equals selector449 (`d4a0d1b7...`) in exact file order: 449 PASS, and every row has selected=1 / skipped=0.
- The focused ledger is 1-12 in the pre-registered order, 12/12 PASS. The focused-12 raw log shows `[ OK ]` (20 s).
- The boundary file records 461 executed and no repair, mutation or retry.

**Source identity.** HEAD `src/`, `include/`, `tests/`, `cmake/` and `benchmarks/` are byte-identical to `8e0818b1` (empty diff).

**CB8 source against RA-16.**
- HardRail placement transport is derived from the four `publishedOccurrenceById(...).placement.lattice` states:
  - the endpoint pairing matches A5's `endpointPairs`;
  - all four scales must be equal;
  - the edge vector must be nonzero;
  - the rotation must be unique;
  - both coordinate pairs are verified.
- CB7's HardRail `action_matches` (the cross-rail branch comparison) is gone.
- `canonicalRelationValue` reproduces the `a532f803` value for every kind. Its canonical inversion is independent of `canonicalTransport`. It feeds `step.appliedTransport` and the A6 step checks (`:4833-4843`, `:4859-4870`).
- The route predicate is one free function, called by A5 before the HardRail pair predicates and reused by the adapter.
- Nit: the duplicate-rotation branch in the `R` search cannot fire for a nonzero edge vector. It is harmless.

**Tests.**
- Focused 3 discriminates the route-validity order: a tampered transition id fires `HardRailRouteAuthorityInvalid`, not `HardRailRouteMismatch`.
- Focused 12(b) relabels only the opposite region, in cells and edges alike. That changes the branch difference across the rail by ±1 and leaves coordinates fixed, so the RA-14 rule would have failed it. The clause therefore discriminates.

##### H2. Overclaim: selector446 does not by itself prove production-completion compatibility

§3 says 446 passing "proves the restored M5 selected-step relation value is compatible with production completion".
- 446 re-implements the periodic half of the completion comparator. It does not call `validate_materialized_completion_domain_ownership`.
- The nonzero-Z4 witness, the only Q≠0 fixture, is still never run through the production check that the authoritative pipeline applies at `RemeshPipeline.cpp:10705-10719`.

The claim is a sound inference (the predicates are identical), but it is not executed evidence.

**Resolution.** R4 pre-registers a focused identity for the first A7 CB: the witness materialization must pass `validate_materialized_completion_domain_ownership` with an empty failure. That CB rewrites the lineage projection, so this is exactly when the check is needed. No repricing.

##### H3. Re-bounding R4

The §5 R4 list has five items. Items 3 and 4 are the A5 gauge obligations carried from RA-16 §4 and the TB7 addendum §G5:
- the periodic unequal-face-gauge witness and coordinate rule;
- HardRail cross-region branch certification;
- OrdinaryFront coordinate identity across isolation seams.

None of them is a CP1 exit item:
- they only matter on non-constant fields (CP3, direct production on real data);
- they need witnesses that a runtime-free turn cannot build;
- the first Definition turn that asked for too much (`M6-DEFN-R3`) stalled and needed a recovery amendment (lesson-level evidence in `M6_Consolidated_Record.md`).

So R4 is bounded to CP1 exit plus one architectural guard:

- **Guard.** A7 and the adapter must not consume A6 `canonicalTransport` or `relationTransport` for geometry, lineage or chart re-anchoring. A7 embeds from exact A5 source support only (§5.1-5.3). The lineage projects `canonicalRelationValue` (RA-16 §3).
  - Under this guard, the uncertified gauge components cannot reach geometry. Their only consumer is the A6 strict cycle check, which fails closed.
  - The three gauge obligations therefore move to a new, bounded **`M6-DEFN-R5` (CP3-entry gate)**: they must close before any CP3 direct-production TB, not before CP1 closure.

R4 must also cover three things the §5 list omitted:

- **Census first** (lessons 180, 187): before freezing the A7 representation, enumerate every production and test reader of the outputs A7 extraction will produce:
  - `vertexPositions`, `vertexProvenance`;
  - lineage `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `selectedRelationPaths`;
  - `hash_completion` and the lineage hashes.

  Current count: about 400 references across src and tests. R4 must also state which frozen assertions bound each representation decision.
- **Adapter census.** The adapter is still 955 lines with 55 failure-emission sites (`RemeshPipeline.cpp:5548-6503`). R4 must classify each site:
  - A4-product validation → A5;
  - A6 error projection;
  - materialized-mesh validity (non-manifold, open boundary, degenerate/inverted quad, collapsed edge, unreferenced vertex, boundary loops) → A7 `GeometryEmbeddingCertificate`, or A8 if the check is an independent recomputation;
  - pure projection.

  "Thin" is then a checkable predicate: no semantic predicate, no selection, no floating tolerance.
- **Exact support, not an epsilon.** The adapter's `QuotientGeometryConsistencyFailure` compares member positions under a `1e-9` relative tolerance (`:6118-6127`), and it chooses the representative with a semantic-looking key (`:6103-6113`). §5.3 requires the `SourceSupportCertificate` to prove exact support incidence; nearest-position coincidence is forbidden as recovery.
  - R4 must define the exact incidence predicate over `SourceSupport` (vertex/edge/face support compatibility).
  - It must keep any float comparison as a diagnostic only.
  - It must place the representation-only representative rule in A7.

##### H4. Procedural repairs (folded in here, not findings)

TB8-REV left the following stale, so this addendum updates them:
- the live handoff section (still "exact next CB8") — the recurring cause of loop stalls;
- ORIENTATION (currency, §3, §7);
- the frozen-definitions status line.

##### H5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Result digest, 954/954 manifest, ledgers and selector order re-derived; focused-12 raw log checked. |
| Source authority | HEAD == `8e0818b1` for all semantic paths; CB8 diff reviewed line by line against RA-16. |
| Acceptance / promotion | Confirmed. `11265967968 / 8e0818b1...` is reviewed runtime authority, selector449 449/449, plus required-green focused 1-12. |
| Corrections | §3's selector446 "production compatibility" claim downgraded to an inference; witness production check pre-registered for the A7 CB. |
| R4 scope | Re-bounded to CP1 exit plus the no-placement-transport-for-geometry guard, with consumer census, adapter census and exact-support rule added. Gauge obligations moved to `M6-DEFN-R5` (CP3-entry). |
| Plan | `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md` written. |
| Accounting | 60 / 16 / 44, debt 1 (unchanged). |
| Turn boundary | Runtime-free; no generated Directional executable run. |

## `Architecture_M6_CP1_TB9_A7_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB9_A7_R1_Review_Record.md`; moved verbatim.

### `M6-CP1-TB9-A7-R1-REV` — Recovery Review Record

**Turn:** `M6-CP1-TB9-A7-R1-REV`
**Type:** runtime-free Review
**Reviewed candidate:** `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c`
**Reviewed runtime:** `37174573847 / 111354443006`
**Result / log:** `11293546353 / 11293531459`
**Disposition:** **ACCEPT / RECOVERY PROVED / PROMOTE**
**Exact successor:** `M6-CP1-CB10-A5V`

#### 1. Independent evidence re-derivation

Review did not accept the EXEC narrative as self-proving. The primary result bytes were reopened and independently checked.

- Result artifact ZIP SHA-256 is `a690ca3992022d7e41d6608062825f5dcf948c74cda8b10a3abe91ddc9d1778e`; log artifact ZIP SHA-256 is `6f9365e9430b97e5f22fd2740443c5cb26dafc408c4b6ac43c2a0b1e9b5b43b7`.
- `SHA256SUMS` SHA-256 is `735dca6e58428f2f8c4234afec61c41d023841d9af8f058f7c5895d11813e008`; all **970/970** listed result files verify.
- Focused ledger independently re-parses to **20 rows / 20 PASS / 0 selection mismatches / 0 skips / exact ordinal order**.
- Selector ledger independently re-parses to **449 rows / 449 PASS / 0 selection mismatches / 0 skips / exact ordinal order**.
- Arithmetic is therefore **20 + 449 = 469**, all **469/469 PASS**.
- `red-ledger.tsv` has no data rows. The execution boundary records runtime complete, orchestration failure false, and configure/compile/relink/generated-discovery/benchmark/package-repair/mode-repair/source-test-fixture-selector mutation/retry-after-runtime-start all false.
- Postflight reports package, source, execution-view and fixture censuses unchanged, selector/routing unchanged, and candidate root manifest still 28/28.

The exact review snapshot is run/job `37176878537 / 111361248778` at control SHA `fbaea32325dbb067e154ad6a3ed07e4e448ff049`; snapshot artifact `11293877329` has provider ZIP digest `sha256:afe0b13427f07a78d21727e7bea0613f7231408a0dbf8dec34ad066930882d3a`, embedded `source.tar.gz` SHA-256 `8167218e777d3d13185469394de322dea571d1613c8b9e753ae3200c0e1e4e7f`, and **5334/5334** source-manifest entries verified.

#### 2. Accepted-prefix and authority checks

Review re-hashed the frozen authority bytes:

- focused12: `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`;
- focused20: `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`;
- focused20 first 12 lines are byte-identical to focused12;
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- counts are 12 / 20 / 449 / 449 respectively.

Focused ordinal 20 is non-vacuous. Its source calls the real `build_authoritative_phase_front_mesh`, requires successful materialization, then calls real `validate_materialized_completion_domain_ownership`. Its raw log selects exactly that one test and records a 72.151-second PASS. The same frozen identity was the sole RED before R1, so the recovery distinguishes the repaired completion predicate from merely reaching an unrelated green branch.

#### 3. RA-22 / RA-22a source adjudication

The reviewed source implements the bounded recovery without widening the producer contract:

1. A7 lineage is detected only by existing occurrence-binding authority (`sourceOccurrences` non-empty).
2. Every retained chart is still resolved and checked against exact support plus retained region/sheet authority.
3. `SourceChartTransitionGraph::source_component` is evaluated for every retained chart; unresolved or non-singleton component authority fails with `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`.
4. A7 selected-relation destinations require retained-region membership, retained-sheet membership, and equality to the retained-chart component singleton. They do **not** compare candidate sheet/component against the representation-only `sourcePoint.face` values.
5. Legacy non-A7 closure still initializes and checks `selectedSheet` / `selectedComponent` from the selected face.
6. RA-22a destination diagnostics are split, in order, into `:dest-unresolved`, `:dest-region`, `:dest-sheet`, and `:dest-component`.

This matches RA-22/RA-22a. No A5/A6/A7 producer identity, relation value, placement transport, selected path, source-support rule, fixture, focused list, or selector is changed by Review.

#### 4. Regression and promotion disposition

`M6-CP1-TB9-A7-EXEC-CAND-01` is now **RECOVERY PROVED / CLOSED AS A NON-STABLE INSTANCE OF EXISTING `RP-01 / AUTHORITY_DOMAIN_CONFLATION`**. It never entered stable accounting because no previously accepted selector row was lost. R1 restores the production-completion witness without any accepted-prefix loss.

Candidate `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c` is therefore **PROMOTED as the current reviewed M6 runtime authority under unchanged selector449**. Stable accounting remains **60 events / 16 categories / 44 recurrences**, produced-witness debt **1**.

#### 5. Prior obligations

- **`τ` single-source obligation — CARRIED to `M6-CP1-CB10-A5V`.** A5 and A7 currently each construct a default `SurfacePointSourceSupportResolver`; A7 reads `barycentric_tolerance()` from its own instance. CB10 must make the accepted RA-18 tolerance one shared constant/accessor used by both A5 and A7, with no numeric tolerance change. The CB10 plan is amended in this Review.
- **A7 cross-sheet certification proxy — CARRIED to `M6-CP1-CLOSE-REV`.** This Review neither weakens nor silently discharges it. CP1 close must either make the A7 check exact for the crossed endpoint sheets or remove the proxy and state A6 as the sole certifier.

No other R1 Review obligation is outstanding.

#### 6. Exact successor and stop rules

Review releases exactly one bounded successor: **`M6-CP1-CB10-A5V`** under the amended `Architecture_M6_CP1_CB10_A5_Validation_Code_Build_Plan.md`.

Its pre-build falsifiers remain the four focused identities 21-24 plus the accepted focused1-20 prefix and selector449. CB10 must additionally prove statically that A5 and A7 read one shared `τ` owner while preserving the accepted numeric value. Compile/package only; runtime is forbidden. If implementation requires changing the accepted tolerance value, A7 support semantics, A6/A7 identity/topology, fixtures, selector449, prior focused bytes, or anything outside the bounded A5/thin-adapter plus shared-tolerance plumbing, stop for Review instead of broadening scope. Compile-green successor is `M6-CP1-TB10-A5V-EXEC`, exact gate **24 + 449 = 473**, then mandatory `M6-CP1-TB10-A5V-REV`.

`M6-CP1-CLOSE-REV` remains owner of the A7 cross-sheet proxy. CB11 and CP1 close are not started in this turn.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused12 `59a523ae...3d571c`; focused20 `15d04a2a...827d2`; first 12 byte-identical; selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...6c5707`. |
| Decisive claims independently re-derived | 970/970 manifest; 20/20 focused; 449/449 selector; 469/469 arithmetic/order; exact-one/zero-skip; empty RED ledger; immutable postflight; RA-22 source predicates. |
| Non-vacuity checked | focused20 executes real production materialization + completion ownership; exactly one test ran and passed; the same frozen identity was the prior sole RED. |
| Prior obligations discharged/carried | `τ` single-source carried to CB10 with plan amendment; A7 cross-sheet proxy carried to `M6-CP1-CLOSE-REV`. |
| Stable accounting | 60 / 16 / 44, debt 1; promoted package/source `11292072930 / 584f80fe...` under unchanged selector449. |
| New candidates/obligations recorded | none; prior CAND-01 marked recovery-proved/closed non-stable; existing carried obligations retained. |
| ORIENTATION currency line | updated to this Review and 2026-10-04 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 runtime authority/current gate updated; §4 torus recovery state corrected; §7 R1 removed as open and CB10 made first priority; §8 lesson 191 retained as the governing existing pattern. |
| CHANGELOG | Review acceptance/promotion entry prepended. |
| ROADMAP | CP1 routing advanced to CB10; R1 marked accepted. |
| Selector manifest | updated package/runtime-authority note under unchanged selector449; no selector append. |
| LESSONS | no new lesson; existing lesson 191 governs the recovered anchor/authority-domain defect. |
| Consolidation under CLEAN_UP_POLICY | n/a — no stale standalone review/plan document is eligible for deletion in this recovery chain. |
| Successor frozen | `M6-CP1-CB10-A5V`; falsifiers and stop rules are in §6 and the amended CB10 plan. |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/build-source mutation. |
| review_check.py boundary | PASS after the final review-document edit set; no product/test/fixture/build-source or selector mutation. |
| `STATUS` lifecycle maintained | entry beacon written directly for this Review; final COMPLETE beacon is written directly only after durable patch/cleanup. |
| Pushed to origin, branch in sync | ChatGPT Web has no local clone; durable Drive-patch workflow is the push plane. Final branch authority and temporary-state cleanup are re-read after the push; `git status -sb` is n/a for this execution environment. |

---

#### Review-agent addendum (2026-10-04, resumed `M6-CP1-TB9-A7-R1-REV`)

**Disposition:**
- **Acceptance and promotion: CONFIRMED.** Candidate `11292072930 / 584f80fe...` is the current reviewed runtime authority.
- **One omission found.** R1 deleted a reject-only consistency guard that RA-22 did not authorize removing.
- **RA-22b** restores it, bundled into CB10 as Goal T2. The gate is unchanged (473).
- **One audit obligation added** for `M6-CP1-CLOSE-REV`.
- Accounting 60 / 16 / 44, debt 1. Successor stays `M6-CP1-CB10-A5V`, with its plan amended.

##### I1. Independent re-derivation (confirmed)

- I downloaded result `11293546353` again. Its ZIP SHA-256 equals the provider digest `a690ca39...778e`, and `SHA256SUMS` verifies **970/970**.
- The focused ledger is 20/20 PASS in the exact order of `Architecture_M6_CP1_Required_Green_Focused_20.txt`. The selector ledger is 449/449 PASS in exact selector449 file order. No row has a selection or skip anomaly.
- The focused-20 raw log shows `[ OK ]` in 72 s; this is the prior sole RED.
- HEAD `src/`, `include/`, `tests/` and `cmake/` are byte-identical to `584f80fe`.

The RA-22a destination checks fire in the specified order: `:dest-unresolved` → `:dest-region` → `:dest-sheet` → `:dest-component`. The A7 component singleton comes from the retained charts, and the legacy branch keeps its selected-face equalities.

##### I2. Finding — R1 removed a reject-only consistency guard RA-22 did not authorize removing (Medium)

**What was deleted.** Before R1, the A7 branch of `close_completion_lineage_source_authority` also required that the representative point's face belong to the class's own authority:

```text
binary_search(retainedSourceRegions, region_for_row(sourcePoint.face))
binary_search(retainedSourceSheets,  sheet_for_row(sourcePoint.face))
```

R1 deleted this check together with `selectedRegion` / `selectedSheet` / `selectedComponent` (diff `a3198ffb..584f80fe`, `PureQuadCompletion.cpp:881-900`).

**Why RA-22 does not cover the deletion.** RA-22 item 1 forbids the representative's face from deciding **selected-relation destination** authority. It does not forbid a reject-only check that the representation leaf is consistent with the class authority it represents.

**What is now undetected.** With the check gone, an A7 lineage whose `sourcePoint` lies on a support-incident face in a region or sheet *outside* the class's retained sets passes this function. Nothing else catches it:
- `sourceSupport == support.identity` only ties the point to the support simplex, not to a sheet;
- the retained-chart loop checks the retained charts, not the point's face.

No test pins `CompletionOwnershipInvalidRetainedSourceAuthority`, so the deletion was invisible to the gate. TB9-R1-REV §3 does not mention it.

This is lesson 189's pattern again: a reject-only guard removed without proving it redundant. The R1 plan's G1 wording ("keep selectedRegion/Sheet/Component only for the legacy path") invited the broader reading.

**Restoring it is provably gate-neutral.** In TB9 (pre-R1 source `b8d27b63`), all 469 processes either passed this exact preflight or, in focused 20's case, failed *later*, at the destination predicate. So every accepted row and the witness already satisfy the guard.

##### I3. RA-22b — restore the representative-face guard as reject-only (bundled into CB10, Goal T2)

1. In the A7 branch only (`sourceOccurrences` non-empty), before the retained-chart loop, require:
   - `region_for_row(sourcePoint.face) ∈ sourceTopologyRegions`;
   - `sheet_for_row(sourcePoint.face) ∈ sourceIsolationSheets`.

   Otherwise fail `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`.
2. The guard may only reject. It must not feed destination, component, chart or lineage decisions (RA-22 item 1 still holds).
3. Strengthen focused 20's body with one negative, without renaming the identity or editing the focused-20 file:
   - in the materialized witness lineage, take one A7 vertex whose `sourceIsolationSheets` has at least two entries (the witness has such multi-sheet classes; they are what failed in TB9), so the emptiness check cannot fire first, and remove the representative face's sheet from `sourceIsolationSheets`;
   - expect exactly `...:representative-face`.
4. Placement in CB10 is deliberate. CB10 already touches A5/A7 shared plumbing for `τ`, and its TB10 reruns focused 1-20 + 21-24 + selector449 = 473, which includes focused 20. Scope beyond these four items is out of bounds; stop for Review.

##### I4. Obligation — finish the lesson-191 consumer audit (owner: `M6-CP1-CLOSE-REV`)

R1 fixed one consumer that assumed the representative's face is the class anchor. Other consumers read `sourcePoint` / `vertexProvenance` faces and have not been re-derived against multi-sheet A7 classes:
- the final source-authority validator, through `resolve_compatible_chart` (`SourceAuthoritativeMeshValidator.cpp:1210-1262`);
- `project_surface_cell_vertex_chart_authority`;
- the optimizer's source-point rebinding (`SurfaceMeshOptimizer.cpp:2576`, `:3020`);
- `BenchmarkQuality` field alignment (`:1490-1503`).

The gate exercises completion ownership on the witness, but not the full production chain (completion → optimizer → final oracle) for a multi-sheet class.

`M6-CP1-CLOSE-REV` must classify each such consumer as one of:
- class-wide (safe);
- representation-only (safe);
- anchor-assuming (defect).

Any anchor-assuming consumer blocks CP1 closure. CP3's direct-production torus proof remains the runtime witness for the full chain.

##### I5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 970/970 manifest, both ledgers in frozen order, focused-20 OK log, HEAD == `584f80fe` re-derived. |
| R1 source | RA-22/RA-22a implemented. **One unauthorized guard removal** (I2). |
| Amendment | RA-22b: representative-face reject-only guard restored in CB10 Goal T2, with a focused-20 negative. Provably gate-neutral. |
| Obligation | Lesson-191 consumer audit for `M6-CP1-CLOSE-REV` (I4). |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 192 — plans must name the guards that stay when they narrow a variable's scope. |
| Successor | `M6-CP1-CB10-A5V`: RA-19, shared `τ`, and RA-22b T2; gate 473. |

## `Architecture_M6_CP1_TB9_A7_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP1_TB9_A7_Review_Record.md`; moved verbatim.

### `M6-CP1-TB9-A7-REV` — Independent Runtime-Free Review Record

**Disposition:** REJECTED / A7 PRODUCER UPHELD / COMPLETION-CONSUMER AUTHORITY DEFECT PROVED / CANDIDATE UNPROMOTED / BOUNDED RECOVERY AUTHORIZED.

#### 1. Authority independently re-opened

Review re-opened the immutable TB9 evidence instead of relying on the EXEC summary.

- Candidate package/source: `11287202960 / b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
- Runtime run/job: `37165108302 / 111326336924`.
- Result artifact: `11288673996`, SHA-256 `5ebe700d35159c1cd6448314470daa1701ce44f69edd59ada71d7d5a1695fffa`.
- Log artifact: `11288504403`, SHA-256 `60e19895d2c46bad3fb16ef76200f9fbc7cd5024c6e4d37e7f73991f23156f07`.
- Result `SHA256SUMS`: independently verified **970/970**.
- Mechanical gate: focused **19/20**, selector449 **449/449**, aggregate **468/469**; exact-one selection true, zero skips, benchmark 0, immutable pre/postflight.
- Sole RED: focused20 `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`; production materialization succeeds, then the real `validate_materialized_completion_domain_ownership(...)` returns `CompletionOwnershipInvalidSelectedRelationDestination`.
- Focused13-19 all PASS. Selector449 is fully green. RA-18 diagnostics `SourceSupportKindMismatch`, `SourceSupportIdentityMismatch`, and `SourceSupportPointMismatch` are absent.

Review source authority is exact snapshot event/source `2800d5049150c7499246b74124719761470238bc`, run/job `37168394385 / 111336124857`, artifact `11289673380`. Git history from semantic source `b8d27b63...` to the review snapshot contains documentation/control changes only; `src/`, `include/`, `tests/`, fixtures and selector/routing semantic authority are unchanged.

#### 2. Finding A — completion re-promotes a representation-only point into semantic class authority

**Finding: CONFIRMED / corrective action required.**

Frozen A7 authority is class-wide. `SourceAttachedGeometryProduct` publishes, for each A6 quotient class, the complete sorted unions of member occurrence charts, topology regions and isolation sheets. The deterministic representative supplies compatibility `sourcePoint`/position only and is explicitly forbidden from selecting a representative sheet/chart or changing semantic class authority.

CB9 implements that contract. `SourceAttachedGeometryProducer::produce`:

1. derives one deterministic representative only for compatibility geometry;
2. collects `sourceCharts` from every member `cornerWedgeBinding`;
3. collects `sourceTopologyRegions` from every member occurrence;
4. collects `sourceIsolationSheets` from every member wedge-sheet set;
5. rejects classes whose published chart-component evidence spans more than one source component;
6. retains A6-selected relation paths and never consumes placement transport for A7 geometry/lineage.

`close_completion_lineage_source_authority` then violates that ownership split. It derives `selectedRegion`, `selectedSheet` and `selectedComponent` from `lineage.sourcePoint.face`, i.e. the representation-only representative. For A7 lineage (`sourceOccurrences` nonempty), it correctly preserves `retainedSourceCharts`, `retainedSourceRegions` and `retainedSourceSheets`, and each selected relation path already requires both endpoint charts to be retained. But the final destination predicate additionally requires:

```text
candidateSheet == selectedSheet
candidateSourceComponent == selectedComponent
candidateRegion in retainedSourceRegions
```

The region membership clause is class-wide and is already implied by the earlier retained-chart validation. The sheet equality is not: A7 expressly permits a valid quotient class to retain more than one certified isolation sheet. The source-component equality is also expressed through the representative even though A7's semantic component authority is the singleton component induced by the retained class-wide charts.

This is the authority-domain mismatch exposed by focused20: a class-wide A7 relation destination is judged through singleton values selected from representation-only `sourcePoint`. The failure is therefore downstream of successful A7 production, not an A7 support/embedding failure. The frozen artifact does not instrument which individual boolean in the compound destination predicate evaluates false; Review does not fabricate that subclause. It is sufficient and decisive that the predicate itself consumes the wrong authority domain and that the only RED stops there.

#### 3. RA-22 — class-wide A7 completion destination authority

The following amendment is normative for recovery and is copied into `Architecture_M6_Frozen_Definitions.md`.

For lineage with A7 occurrence-binding authority (`sourceOccurrences` nonempty):

1. `sourcePoint` remains representation/compatibility data only. Its face's region, sheet or component may not decide semantic selected-relation destination authority.
2. The selected relation certificate's `startChart` and `endChart` must remain exact members of `sourceCharts`; no search, rebind, substitution or alternate path is permitted.
3. The destination topology region must be a member of `sourceTopologyRegions`.
4. The destination isolation sheet must be a member of `sourceIsolationSheets`. It must **not** be required to equal the representative face's sheet.
5. Source-component authority is derived from the retained A7 charts through `SourceChartTransitionGraph::source_component`. All retained charts must resolve and their unique component set must have cardinality one; otherwise fail closed. The destination component must equal that class-wide singleton.
6. The existing exact support, path endpoint, path continuity, relation-value, composed-transport and no-placement-transport rules remain unchanged.
7. Lineage without A7 occurrence-binding authority retains the established legacy singleton selected-face closure.

RA-22 changes no A5/A6/A7 producer identity, support, topology, selected path, relation-value or transport semantics. It changes only the completion consumer's interpretation of already-published A7 lineage.

#### 4. Regression adjudication

`M6-CP1-TB9-A7-EXEC-CAND-01` is adjudicated **CAUSE PROVED / NON-STABLE / existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` mechanism**.

- Population: new focused20 only; no selector449 accepted-green loss.
- Root mechanism: representation-only representative authority is conflated with class-wide A7 semantic authority in the completion consumer.
- Attribution: the CB9 producer follows frozen R4/RA-18 A7 class-wide publication; the defect is in the pre-existing completion integration seam exposed for the first time by the new production-completion witness.
- Stable accounting: **+0 events / +0 categories / +0 recurrences**. Totals remain **60 events / 16 categories / 44 recurrences**, project debt **1**.
- Candidate `11287202960 / b8d27b63...` remains rejected/unpromoted. Reviewed runtime authority remains TB8 `11265967968 / 8e0818b1...`.

#### 5. Recovery scope and stop rules

Review authorizes one bounded recovery turn, `M6-CP1-CB9-A7-R1`, under `Architecture_M6_CP1_CB9_A7_R1_Completion_Ownership_Code_Build_Plan.md`.

Allowed semantic source scope is the completion ownership integration seam, expected to be `src/geometry/PureQuadCompletion.cpp`. The recovery must consume existing class-wide A7 lineage exactly as RA-22 states. It must not change A7 producer semantics, A5/A6 identity/certificates, `canonicalRelationValue`, `canonicalTransport`, RA-18 support rules, fixtures, selector449, focused-20 bytes, or CB10/CB11 reserved identities.

Stop for Review rather than broadening scope if implementation requires changing A7 publication, quotient membership, selected path construction, source-support semantics, fixtures/selectors, or any relation/transport rule.

The recovery Code + Build is compile/package only. If compile-green, `M6-CP1-TB9-A7-R1-EXEC` reruns the **same exact focused20 + selector449 = 469** artifact-only gate. Recovery requires 469/469 and is followed by mandatory `M6-CP1-TB9-A7-R1-REV`. CB10 remains held until that Review accepts recovery.

#### 6. Final disposition

TB9 evidence is mechanically authoritative and semantically rejects the CB9 candidate. A7 itself is upheld; completion consumption is amended by RA-22. No runtime, build, source repair or diagnostic rerun occurred in this Review.

Exact successor: **`M6-CP1-CB9-A7-R1`**.

---

#### Review-agent addendum (2026-10-04, resumed `M6-CP1-TB9-A7-REV`)

**Disposition:**
- **Rejection and RA-22 confirmed.** The failing subclause is now identified statically (H2).
- **RA-22a added:** site-qualified completion-destination diagnostics.
- **Two A7 fidelity gaps recorded** for CB10 / CP1 closure (H4).
- Accounting unchanged at 60 / 16 / 44, debt 1.
- Successor unchanged: `M6-CP1-CB9-A7-R1`, with its plan amended.

##### H1. Independent re-derivation (confirmed)

**Result artifact.**
- I downloaded result `11288673996` again. Its ZIP SHA-256 equals the provider digest `5ebe700d...fffa`.
- `SHA256SUMS` verifies **970/970**.
- The focused and selector ledgers hash to `ccc4c78e...` and `17b27fd3...`.

**Ledgers.**
- The focused ledger is ordered exactly as `Architecture_M6_CP1_Required_Green_Focused_20.txt`. That file's first 12 lines hash to `59a523ae...`, identical to the frozen focused-12 file.
- Focused 13-19 PASS; selector449 is 449/449 PASS.
- The only RED is focused 20. Its raw log shows `validate_materialized_completion_domain_ownership` returning `CompletionOwnershipInvalidSelectedRelationDestination`.

**CB9 source against R4 and RA-18 (verified).**
- Support is read from A5 `occurrence.support`, comparing kind and then identity.
- The same-simplex guard is reject-only: edge parameter `β_b/(β_a+β_b)` or canonical face barycentrics, within `τ` = the resolver barycentric tolerance.
- The adapter's `1e-9` check and `QuotientGeometryConsistencyFailure` are gone from `RemeshPipeline.cpp`.
- The A7 producer region reads no `canonicalTransport` or `relationTransport`.
- Focused 15 asserts both the typed code and the site for each negative.

##### H2. The failing subclause, identified statically

TB9-REV §2 declined to name the false disjunct. It can be deduced from invariants that `close_completion_lineage_source_authority` has already enforced before it reaches the destination predicate (`PureQuadCompletion.cpp:1144-1158`):

- **The end chart is resolved and checked.** It is retained (`:997`), it resolves to an exact source row equal to the certificate chart (`:1020-1028`), and that row is in `support.incidentFaces`. So `topology_region`, `isolation_sheet` and `source_component` are all non-null.
- **Region membership is already proved.** The A7 preflight (`:897-920`) requires every retained chart's region and sheet to be in the retained sets. The `candidateRegion ∈ retainedSourceRegions` clause is therefore implied.
- **Component equality is already implied.** Every retained chart's face is incident to the one published support simplex, so all such faces share the representative face's source component on a manifold source. The witness is the closed `milestone-g/torus.obj`, a single connected component.

The only clause left that can be false is **`candidateSheet != selectedSheet`**: the destination member's isolation sheet differs from the representative's sheet. This matches A6 path direction. A6 paths run root (smallest `OccurrenceId`) → target member. The A7 representative is the min of `(support, bindings, id)`, and the destination is a non-representative member whose sheet legitimately differs. A7's `UncertifiedCrossSheetBinding` gate accepted that crossing.

So RA-22 item 4 (sheet membership) is the operative repair. Items 3 and 5 are fail-closed restatements of invariants the preflight already enforces; they are harmless, and kept.

**Production consequence (not a regression; +0).** The promoted runtime `8e0818b1` already publishes the same lineage, and the authoritative pipeline runs this same check (`RemeshPipeline.cpp`, authoritative completion call). The production path therefore rejects, with `NotProductionReady` at `completion`, any authoritative class whose projected HardRail/Periodic selected path ends on a sheet other than the representative's. That includes the nonzero-Z4 torus. Focused 20 is the first gate to run it. This matters for CP3 (direct torus production); R1 removes it within CP1.

##### H3. RA-22a — site-qualified destination diagnostics (lesson 181)

No test or production code compares `CompletionOwnershipInvalidSelectedRelationDestination` exactly; source and tests were searched. R1 must suffix it by subclause:
- `:dest-unresolved`
- `:dest-region`
- `:dest-sheet`
- `:dest-component`

The new RA-22 component-singleton failure gets its own site, `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`.

If TB9-R1 is not green, the next Review must be able to attribute the residual without new instrumentation. This does not change any predicate.

##### H4. A7 fidelity gaps (not R1 scope; recorded for `M6-CP1-CB10-A5V` / `M6-CP1-CLOSE-REV`)

1. **The cross-sheet certification is a proxy.** For a forest edge whose endpoints share no wedge sheet, A7 accepts the crossing if **any** isolation evidence exists on the relation, **or** either occurrence has **any** `cornerWedgeIsolation` (`RemeshPipeline.cpp:5952-5987`). It does not check that the evidence connects the two sheets being crossed. Yet the certificate publishes `relationEvidenceSufficient = true`.

   Frozen §5.2 says only A6's verified wedge/side evidence may establish each cross-sheet step. A6 does validate isolation-seam evidence (RA-12 `:a6-seam-*` sites), so this is redundancy with an overclaiming bit, not an open hole.

   **Required by `M6-CP1-CLOSE-REV`:** either make the A7 check exact — some certified transition maps one endpoint sheet to the other — or delete the proxy and state that A6 is the certifier.
2. **`τ` is not single-sourced.** A7 builds its own default `SurfacePointSourceSupportResolver` to read `τ` (`:5587-5588`), while A5 uses a separate default instance. RA-18 defines `τ` as A5's tolerance. One shared constant or accessor must own both. Fix in CB10, which touches A5.

##### H5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 970/970 manifest, ledgers, focused-20 prefix identity, sole-RED raw log re-derived. |
| A7 producer | Upheld against RA-18. Old check removed; no placement-transport read. |
| Root cause | Sheet-equality subclause deduced statically (H2). RA-22 confirmed; RA-22a diagnostics added. |
| Production note | Promoted runtime is production-latent on multi-sheet selected-path classes; R1 recovers. No repricing. |
| Recorded gaps | A7 cross-sheet proxy (CP1 close); `τ` single-source (CB10). |
| Accounting | 60 / 16 / 44, debt 1. |
| Successor | `M6-CP1-CB9-A7-R1` (RA-22 + RA-22a) → TB9-R1 469 → mandatory Review. |

## `Architecture_M6_CP2_CB2_Coverage_Code_Build_Plan.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP2_CB2_Coverage_Code_Build_Plan.md`; moved verbatim.

### `M6-CP2-CB2-COVERAGE` — CP2 Verifier Binding + Negative-Coverage Code + Build Plan

**Owner:** `M6-CP2-CB2-COVERAGE`
**Type:** Code + Build only; compile/package; runtime forbidden.
**Authority:**
- RA-29d;
- `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`, review-agent addendum §U1–§U4;
- frozen §6.2, §6.3 and §10 (M6-CP2);
- RA-28a §1–§2 and §5.

**Entering runtime authority:** `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` (491/491).
**Accounting:** 60 / 16 / 44, debt 1.

#### Goals (exactly these)

##### G1 — A7 vertex binding (RA-28a §2; production verifier)

In the A7 partition, for every A7 vertex `v` of class `C` with support certificate `s`, require all of:
- `v.representative` ∈ `C.members`;
- `v.sourcePoint` == the published `point` of occurrence `v.representative`, with exact equality of face, barycentric and position;
- `v.position` == `v.sourcePoint.position`;
- `v.support == s.publishedSupport`.

Together with the existing check `member.support == s.publishedSupport`, this binds every vertex to the class-common support. Failure: `SourceSupportIncidenceMismatch`, site `a7:vertex-binding`. Use exact equality only; no tolerance.

**Stop for Review** if any accepted row would fail. A7 copies these fields verbatim (`RemeshPipeline.cpp:6985-6993`), so the check should be gate-neutral.

##### G2 — dead codes (RA-28a §5 in reverse)

- **Remove** `UncertifiedAuthoritySubstitution` from `VerificationFailureCode` and its name table.
- **Give `BoundaryOrEulerMismatch` its predicate.** Split the recomputed connected-components, boundary-loop-count and Euler-characteristic comparisons out of `certificate:a7` into separate findings: `BoundaryOrEulerMismatch` at `a6:components`, `a6:boundary-loops` and `a6:euler`. The remaining certificate-field checks stay under `certificate:a7`.

##### G3 — negative coverage (identities 2–5; names and order unchanged; bodies strengthened)

Each witness:
- starts from a verified produced record view;
- asserts that its tamper changed the record;
- asserts the **exact code and site**.

| Identity | Witnesses (code / site) |
|---|---|
| 2 (A0/A5) | `a0:hard-feature-edge` (an edge not in A0); `a5:exact-corner-ownership` or `a5:corner-owner` (duplicate a corner owner) — `OccurrenceOwnershipMismatch`; `a5:directed-side-cycle` (permute one directed side) — `DirectedSideCycleMismatch`; `a5:wedge-isolation` (a transition seam that is not an A0 isolation seam) |
| 3 (A6) | `a6:exact-once-ledger` (drop one consumption); `a6:duplicate-certificate`; `a6:forest-joining-set` (flip one `Joining` to `CycleClosing` with no forest change); `a6:forest-cardinality` or `a6:forest-spanning` (remove one forest edge); `a6:edge-manifoldness` (a third cell on one edge, if constructible from records; else classify); and from G2, `BoundaryOrEulerMismatch` at `a6:boundary-loops` / `a6:euler` (tamper the A7 certificate counts so they disagree with the recompute) |
| 4 (A7) | **G1** `a7:vertex-binding` — four witnesses: (a) a non-member representative, (b) a moved `sourcePoint` with self-consistent support, (c) a `position` mismatch, (d) `v.support ≠ publishedSupport`. Also `a7:support-cover` (drop one support certificate), `a7:topology-copy` (alter one A7 cell), `certificate:a5`, `certificate:a6`. |
| 5 (§6.3 coverage map) | A table-driven body with one row per frozen §6.3 class (`Architecture_M6_Frozen_Definitions.md` §6.3, 10 rows). Each row is either a runtime record-view witness with exact code and site (it may reuse witness helpers from identities 2–4 and 6–7, but **must execute** the witness here), or an API-shape row pinned by a compile-time trait: no mutating overload; no overload accepting a producer error variant. Keep the existing non-mutation assertion. Required rows: create/renumber IDs; union / replacement representative (G1 a); search or replace a route (path structure); infer missing authority (`MissingPublishedAuthority` at `a6:a5-relation` or `a6:a5-transport` or `a6:selected-path-certificate`); canonicalize (non-mutation); substitute an equivalent or reverse unreferenced relation (a certificate citing the reverse or an unowned relation → its exact resulting code/site); weld (pinched-topology witness and G1 b); repair (directed side / quad / support / certificate tamper); mutate (API trait); upstream failure (API trait). |

##### G4 — CB report coverage table

The CB report must contain a table mapping every §6.2 recompute category and every §6.3 class to:
- its production predicate (`file:line`);
- its executed witness (identity plus code/site), **or** its API-shape classification with a reason.

Any row without either is a **stop for Review**.

#### Forbidden

- Producer (A5/A6/A7) semantic changes.
- Any `SurfaceMeshOptimizer` change.
- Any focused-30, focused-12, selector449 or routing449 byte or order change.
- New identities. The gate stays **491**.
- Tolerances.
- Unchecked product factories.

#### Static and compile gate

- `git diff --check`.
- A diff census separating production from tests.
- Frozen hashes: focused-30 `1e815443…`, focused-12 `2aa57aac…`, selector449 `d4a0d1b7…`, routing449 `9c88a5ed…`.
- Mandatory reusable GMP/GMPXX workflow, standard eight targets, `runtimeExecution=false`.

#### Successor

Compile-green → `M6-CP2-TB2-COVERAGE-EXEC`: focused-30 + focused-12 + selector449 = **491** fresh exact-filter processes, with upload paths derived from the harness `TURN_ID` → mandatory **`M6-CP2-CLOSE-REV`**.

`M6-CP2-CLOSE-REV` adjudicates the frozen CP2 exit (§10) against the G4 coverage table and the fresh 491 gate, and writes `M6_CP2_Closure_Record.md`. If CP2 closes → `M6-DEFN-R5`.

## `Architecture_M6_CP2_Close_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP2_Close_Review_Record.md`; moved verbatim.

### M6-CP2-CLOSE-REV — Independent Close Review Record

**Disposition:** **ACCEPTED / CP2 CLOSED**
**Reviewed candidate:** `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6`
**Runtime:** `37419256039 / 112124748161`, **491/491**
**Result/log artifacts:** `11393198123 / 11393312986`
**Successor:** `M6-DEFN-R5`
**Accounting:** **60 events / 16 categories / 44 recurrences**, debt **1**

#### Independent evidence re-derivation

Review used exact source snapshot `303f9c54c160c38a9b1e288c88bd79a17c329d56` from run/artifact `37425574903 / 11394532173`; snapshot metadata records 5,505 files and `runtimeExecution=false`. The reviewed semantic candidate remains `5ce3132e...`; later branch commits are documentation/control-plane state only.

TB2 result artifact `11393198123` was independently re-read rather than accepted from the EXEC report. Its ZIP SHA-256 is `0e4e550a09e4fb38b58bfcef2e57db6dcea865a1c46b384b5a288d5c491606bb`; `SHA256SUMS` hashes to `25bae369de8a6a46f5b8f273083fe3a18ec0e9374f833c11479c85aa0ac22a2b` and verifies **1005/1005**. The three ledgers contain exactly 30, 12 and 449 data rows. Every row independently matches the frozen identity at the same ordinal, has exit 0 / selected 1 / skipped 0 / passed 1 / PASS, and every raw-log SHA-256 matches the ledger. Aggregate: **491/491**, exact-one **491/491**, zero skips, zero RED, benchmark execution 0.

Package, packaged-source and execution-view before/after censuses compare byte-for-byte equal. Candidate manifest checks are **28/28** before and after runtime. The execution boundary records no configure, compile, relink, generated discovery, package/mode repair, source/test/fixture/selector mutation, or retry after runtime start. Frozen hashes independently match: focused30 `1e815443...a1d6`, focused12 `2aa57aac...74ed`, selector449 `d4a0d1b7...d6414`, routing449 `9c88a5ed...c5707`.

The CB2 semantic compare from `23a4663f...` to `5ce3132e...` changes only the verifier header, verifier implementation and `SurfaceCellTransitionQuotientTests.cpp` beyond temporary workflow/mailbox control files. No A5/A6/A7 producer or optimizer semantic file changed.

#### Frozen §10 adjudication

| CP2 duty | Review result | Evidence |
|---|---|---|
| Consume immutable A0/A5/A6/A7 products and certificates | **PASS** | `SurfaceProductVerifier::verify_records` accepts record views and only emits `VerificationReport`; successful product construction remains verifier-owned. |
| Independently recompute only frozen §6.2 elementary facts | **PASS** | CB2 G4 has one row for each of the eight §6.2 categories; source inspection confirms the A0/A5 incidence, A6 topology/membership/transport, A7 support and certificate predicates. RA-29b remains controlling for A0 component labels: raw connectivity must not be substituted for unavailable ingress-label authority. |
| Fail typed on every frozen §6.3 malformed-authority class | **PASS** | Focused identity 5 is a ten-row table matching all ten §6.3 classes. Eight rows execute exact record-view rejection witnesses; two rows pin API shape at compile time. Identity 5 executed and passed in the fresh TB2 gate. |
| Never repair/canonicalize/search/substitute/weld/mutate producer state | **PASS** | Runtime witnesses reject those classes rather than correcting them; the canonicalization row also asserts input records remain unchanged. Compile-time traits reject mutable verifier and upstream-error overloads. Published-path traversal/composition is verification of named evidence and remains within §6.2 exact algebra. |

The frozen §6.2 phrase “component adjacency from A0” is not reopened into RA-29a’s withdrawn raw-connectivity component-label equality. RA-29b proved that `SourceComponentId` is ingress authority not independently recoverable from raw connectivity with this API. The current verifier checks published A0/source-face incidence and does not infer replacement component labels; this is the accepted amended contract.

#### RA-29d closure

- **OBS-01 / U1 — CLOSED / RECOVERY PROVED.** `a7:vertex-binding` now requires representative membership, exact representative point, embedded-position equality and class-certificate support. Identity 4 carries four distinct tamper witnesses, and the fresh focused12 gate is green.
- **OBS-02 / U2 — CLOSED / RECOVERY PROVED.** Identities 2–4 now exercise the required ledger/forest, A5 ownership/directed-side, A0 hard-edge, A7 cover/topology/binding, certificate and boundary/Euler negatives. Identity 5 executes/classifies all ten §6.3 classes. The fresh 491 gate runs those strengthened frozen identities without changing their names/order.
- **OBS-03 / U3 — CLOSED / RECOVERY PROVED.** `UncertifiedAuthoritySubstitution` is absent from header/source/tests. `BoundaryOrEulerMismatch` has live predicates at `a6:components`, `a6:boundary-loops` and `a6:euler`, with executed identity-3 witnesses.
- **OBS-04 / U4 — CLOSED BY THIS REVIEW.** `M6_CP2_Closure_Record.md` supplies the previously missing dedicated per-criterion closure record.

RA-29d’s two non-blocking notes remain unchanged: shared `reverse_selected_relation_step` is permitted exact algebra; by-value verified-product copying remains owned by M8-CP2. Neither blocks CP2.

#### Verdict and routing

The frozen M6-CP2 exit is satisfied. Review promotes `11391685901 / 5ce3132e...` as the reviewed CP2 verifier/runtime authority and closes M6-CP2. No new stable regression event, category, recurrence or architecture-debt item is created; accounting remains **60 / 16 / 44**, debt **1**. The remaining debt is not CP2 verifier debt and stays later-owned by direct-production work.

Exact successor: **`M6-DEFN-R5`**.

## `Architecture_M6_CP2_TB1_Verifier_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP2_TB1_Verifier_R1_Review_Record.md`; moved verbatim.

### M6-CP2-TB1-VERIFIER-R1-REV — Independent Review Record

**Disposition:** REJECTED FOR BOUNDED RECOVERY / CANDIDATE UNPROMOTED
**Reviewed candidate:** `11382000465 / 9c8478aec40bf07144ca7372c2aa58293cd42f5e`
**Runtime:** `37393554373 / 112044082007`, **462/491**
**Exact successor:** `M6-CP2-CB1-VERIFIER-R3`

#### Review authority and evidence

Review used an exact source snapshot of semantic source `9c8478aec40bf07144ca7372c2aa58293cd42f5e`: workflow run `37395710753`, artifact `11383307041`, provider digest `sha256:ba5d6cc2b9f21d81fd90491586f0126ae0872200bce293f7181016f4868a34ae`, archive digest `c314fb145c5e9426cb02898af8e91216b11514e184eb8648f6f36abdb8b903b3`, 5454 files, `runtimeExecution=false`. The turn selected `READ_MODE=snapshot`; the mode was selected only after a few repository-document reads, which is a tool-policy miss. Static source review after that point used only the verified local snapshot.

Runtime evidence is the GitHub job log for `37393554373 / 112044082007` plus `.workflow-mailbox/m6-cp2-tb1-verifier-r1-exec/latest.json`. The harness completed all 491 exact-filter processes and immutable postflight. Result/log upload failed only afterward because the caller still named predecessor-turn output paths. No duplicate runtime is required or authorized.

Mechanical re-derivation is accepted: focused30 **26/30**, CP2 focused12 **11/12**, selector449 **425/449**, aggregate **462/491**, exact-one **491/491**, zero skips, benchmark 0. RED ordinals match the EXEC report.

#### Finding R1-REV-01 — A7 exact-step verifier requires identity that A7 intentionally does not publish

**Severity:** High / production verifier false rejection.
**Disposition:** CONFIRMED; primary cause of the broad R1 RED cluster.

A6 publishes one `QuotientSelectedPathCertificate` for every non-root class member. Each certificate owns `root`, `target`, exact `orderedRelations`, orientations, and an optional legacy `SelectedRelationPathCertificate`. A7 deliberately projects only the legacy certificate values into each vertex, then sorts and deduplicates them. The legacy type contains support, start/end chart/component, ordered HardRail/Periodic steps and composed transport, but **no A6 target occurrence or path identity**.

R2's verifier reverses that lossy projection by scanning all A6 selected paths and demanding exactly one candidate whose legacy fields match the A7 path. On a second matching candidate it sets the selected candidate back to null and emits `MissingPublishedAuthority:a7:a5-relation-step`. That uniqueness is not published authority. Different A6 root→target paths can collapse to the same legacy path after OrdinaryFront steps are omitted, and A7 explicitly deduplicates those projections.

This is exactly the case RA-29a §3 anticipated: when positional correspondence cannot be established from published records, the verifier must use the same-ID relation-value fallback. R2 did not implement that fallback. It therefore turns representational ambiguity into missing authority and rejects accepted production rows.

The direct runtime signature is consistent with the static defect: focused30 ordinals 6/20/24 and selector ordinals 115/116/141/143/150/217/218/231/232/246/436/437/438/444/446/448 report `VerificationFailed:MissingPublishedAuthority:a7:a5-relation-step`. The other feature/flow/arrangement REDs fail because the pipeline stops earlier at `NotProductionReady`/`tracing` or never reaches their intended mutation/oracle seam. Focused30 ordinal25 similarly never reaches its expected produced arrangement.

##### Required correction

For each A7 legacy path, collect all A6 selected-path certificates in that class whose `legacyProjection` has the same non-value semantic identity. Never require target uniqueness that A7 does not carry.

- **One matching A6 path:** use its exact HardRail/Periodic subsequence of `orderedRelations` and orientations; each A7 step must equal the exact cited A5 `canonicalRelationValue` after orientation.
- **Multiple matching A6 paths:** positional target correspondence is unobservable. Apply RA-29a's fallback: for each A7 step's typed HardRail/Periodic owner ID, collect every A5 relation in the class with that owner; require at least one, require `canonicalRelationValue` on every candidate, require all those values identical, and require the A7 step's `appliedTransport` to equal that common value (inverted when the published step direction is reverse). First-match lookup remains forbidden.
- **No matching A6 legacy path:** `MissingPublishedAuthority:a7:a5-relation-step` remains valid.

Do not add a target field to the legacy A7 type in this recovery; that would expand the frozen product contract. Do not change A5/A6 producers to make the verifier's reverse lookup unique.

#### Finding R1-REV-02 — RA-29a component-partition requirement contradicts accepted A0 ingress semantics

**Severity:** High / review-specification error causing production false rejection.
**Disposition:** RA-29a §4 WITHDRAWN and replaced by RA-29b below.

R2 recomputes raw triangle edge-connected components and requires `SourceTopologyRegions::component_for_row` to induce exactly that partition. This assumes `SourceComponentId` is derivable from raw connectivity alone. The API does not provide that invariant: `build_source_topology_regions` receives `sourceFaceComponents` as ingress labels and may publish multiple disconnected topology regions carrying the same component label.

Accepted selector449 ordinal 144 (`MaterializerConsumesPublishedTopologyRegionsExactlyOnce`) deliberately constructs two disconnected squares, supplies `sourceFaceComponents = 0` for every face, obtains a valid produced phase-front product, and requires materialization to succeed. R2 rejects this accepted authority at `SourceIncidenceMismatch:a0:component-adjacency`. That is the mandatory RA-28 §7 Review stop.

The new identity-2 sub-witness makes the same invalid assumption in the other direction by merging component labels across a disconnected produced fixture and expecting rejection. Because the verifier receives only the already-published `SourceTopologyRegions` and raw mesh, not an independent copy of ingress component labels, there is no independent expected component labeling to reconstruct. Mesh connectivity cannot substitute for that missing authority.

##### Required correction

Withdraw the exact mesh-connected-component equality check and remove the identity-2 component-merge sub-witness. Identity 2 continues to cover the real canonical source-face mismatch, shared `SurfacePointSourceSupportResolver` equality, wedge binding/sheet incidence, seam incidence and other A0/A5 elementary facts.

A future stronger component-label verifier would first need an independently published ingress-label certificate/input. CP2 R3 must not infer component IDs from connectivity and must not change accepted selector144 semantics.

#### Finding R1-REV-03 — focused12 ordinal 6 baseline failure is part of R1-REV-01

The strengthened hard-rail identity now constructs a produced >=2-step A6 path, but its baseline `verify_m6cp2_records(pathRecords).verified()` is false before the intended path-structure tamper. Its source authority is connected and does not trigger the component-label issue. The baseline passes through the same A7 legacy-path reverse-binding code described in R1-REV-01. Treat this as the focused witness for that production false rejection, not as an independent regression class.

R3 must make the baseline green before the tamper, retain the >=2-step path-structure mutation, and add a non-vacuity assertion that the chosen produced fixture actually contains the projection ambiguity (two or more A6 selected paths collapsing to an equal legacy projection). If the existing hard-rail fixture does not expose that ambiguity after the production fix, use another already-produced fixture; do not forge unchecked authority.

#### EXEC-OBS-01 — post-runtime artifact upload path defect

The runtime harness used `TURN_ID=M6-CP2-TB1-VERIFIER-R1-EXEC` and wrote under that turn-local path, but the workflow upload steps still used `M6-CP2-TB1-VERIFIER-EXEC`. Both uploads therefore failed after the harness had completed and postflight had passed. This is orchestration-only and does not invalidate the 491 runtime results.

The next TB caller must derive result/log upload paths from the same `TURN_ID` used by the harness, rather than duplicating a predecessor literal. Schema validation alone cannot catch this semantic path mismatch. No runtime retry is authorized merely to recreate R1 artifacts.

#### Causal clustering and accounting

All 29 RED rows are explained by two bounded causes:

1. **R1-REV-01 A7/A6 reverse-binding false rejection** — the direct `a7:a5-relation-step` rows plus downstream pipeline/reachability rows, including focused12 ordinal6 and focused30 ordinal25;
2. **R1-REV-02 invalid A0 component-partition rule** — selector449 ordinal144.

Neither represents a newly discovered user-visible optimizer regression. Both were introduced by CP2 verifier recovery authority, and the component rule is specifically a review-agent specification error. The candidate remains rejected/unpromoted and the previously reviewed CP1 runtime remains authority.

Stable accounting remains **60 events / 16 categories / 44 recurrences**, architecture debt **1**. No stable repricing is made.

#### Frozen recovery routing

RA-29b freezes one bounded recovery:

`M6-CP2-CB1-VERIFIER-R3` → `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**) → mandatory `M6-CP2-TB1-VERIFIER-R2-REV`.

R3 is Code + Build only. It may change the verifier and existing focused identities 2/6 as specified, but may not change optimizer source, A5/A6/A7 producer semantics, focused30 names/order, CP2 focused12 names/order, selector449/routing449 bytes, or gate size. Any accepted gate authority that still rejects after those two corrections returns to Review.

---

#### Review-agent addendum (2026-10-06, resumed `M6-CP2-TB1-VERIFIER-R1-REV`)

**Disposition:**
- **Rejection, causal clustering and R1-REV-02: CONFIRMED.**
- **R1-REV-01's diagnosis: CONFIRMED. Its prescribed correction (RA-29b §1 and §3): REPLACED by RA-29c.** The ambiguity fallback can itself falsely reject accepted rows. An exact, fallback-free binding is available from published records and needs no ambiguity witness.
- **Owned:** both R1 failure classes trace to my RA-29a §3 (positional binding plus a fragile fallback) and §4 (component partition).
- Gate unchanged at **491**. Accounting **60 / 16 / 44**, debt 1.

##### T1. Independent re-derivation

No result artifact exists (EXEC-OBS-01), so I re-derived the result from the GitHub job log `112044082007` (1,469,035 bytes after stripping escape sequences):
- **491** `[ RUN ]` lines in exact focused-30 + focused-12 + selector449 order; 462 `[ OK ]`; 29 failed.
- REDs:
  - focused-30 ordinals **6, 20, 24, 25**;
  - focused-12 ordinal **6**;
  - selector449 ordinals **115, 116, 122, 130, 132, 134, 137, 141, 143, 144, 150, 176, 201, 217, 218, 231, 232, 246, 436, 437, 438, 444, 446, 448**.
- Signatures:
  - **19** × `VerificationFailed:MissingPublishedAuthority:a7:a5-relation-step`;
  - **1** × `a0:component-adjacency` (selector 144);
  - **9** reachability failures with no verifier string: `NotProductionReady` instead of the injected stage, an unreached final-oracle or mutation seam, and `hasArrangement == false`. All nine are on hard-rail, feature or torus fixtures, consistent with the pipeline stopping at the A7 rejection.
- **R1-REV's clustering is confirmed.**

**R2 RA-29a items checked in source (`9c8478ae`):**
- `a6:relation-class` is present (`:7822`, `:7856`).
- Topology uses single-pass `edgeOwners` / `incidentEdges` (O(n log n)).
- `AuthoritativePhaseFrontMeshResult::verificationReport` is present.
- `VerifiedSurfaceProducts` holds its products by value.

##### T2. R1-REV-02 confirmed; review-agent error owned

`SourceComponentId` is ingress authority. Selector 144 deliberately publishes one component label over two disconnected squares. My RA-29a §4 assumed component labels equal raw edge-connectivity components, without checking that accepted row. Withdrawn (lesson 204).

##### T3. RA-29b's ambiguity fallback can falsely reject — replace it with an exact two-hop binding (High)

**Why the fallback fails.** A5 sets `canonicalSelectedStep.appliedTransport = canonicalRelationValue` per relation (`RemeshPipeline.cpp:4940`). It also **inverts** `canonicalRelationValue` whenever that relation's storage order is not canonical (`:4917-4921`). Canonical order is by `OccurrenceId`, which along a rail or periodic cut depends on cell IDs and varies from pair to pair. So relations sharing a rail or periodic ID can legitimately carry **inverse** values.

RA-29b §1 requires "every A5 relation in the class sharing that step's rail/periodic owner ID must publish the same `canonicalRelationValue`". Whenever the value is not an involution, that **falsely rejects**. The nonzero-Z4 periodic torus rows (focused-30 ordinals 6 and 20; selector 444/446/448) are exactly that case: a 90° rotation's inverse is 270°. RA-29b §3 also adds a feasibility risk: it requires a produced ambiguity witness, and stops if none exists.

**What exactly is published.**
- **A6 → A5, per certificate.** `certificate.selectedRelationStep == r.evidence.canonicalSelectedStep`. This is already verified by the RA-28a §2 table.
- **A6 projection, positional within one certificate.** The A6 producer builds `legacyProjection.orderedSteps` as the oriented `selectedRelationStep` of each certificate along the path's own `orderedRelations` / `traversalOrientations` (`:5500-5548`). It sets `composedTransport` to the composition of those steps' `appliedTransport`, and takes start/end chart and component from the first/last step. A6 publication re-checks this (`:5935-5960`).
- **A7 → A6, by projection equality.** `vertex.selectedRelationPaths` is exactly the sorted, deduplicated multiset of the class's present `legacyProjection`s (`:6962-6970`).

**So the binding is exact in three hops, with no reverse lookup, no uniqueness assumption and no fallback:**

| Hop | Rule | Site |
|---|---|---|
| A5 internal, per relation | If `canonicalSelectedStep` is present: `canonicalRelationValue` is present, `step.appliedTransport == canonicalRelationValue`, and `step.direction == Forward`. | `a5:selected-step-value` |
| A6, per path certificate | `legacyProjection.has_value()` ⇔ the oriented step subsequence is non-empty. `legacyProjection.orderedSteps` equals that subsequence, where inverting a step means: invert `appliedTransport`, swap from/to chart and component, flip `direction`. `composedTransport` is the composition of the steps' `appliedTransport`; the start/end fields come from the first/last steps. | `a6:legacy-projection` |
| A7, per class | `vertex.selectedRelationPaths` == sorted-unique { p.`legacyProjection` : p a class path with a projection }. | `a7:selected-paths` |

- Hop 2 uses only named-certificate inversion and composition (frozen §6.2).
- Group paths by class once; the whole binding is O(P log P). This also **removes R2's O(V·P) all-paths scan per A7 path**, which reintroduced quadratic cost in the production verifier (RA-29a §2's intent).
- By transitivity, every A7 step value equals the exactly cited A5 relation's `canonicalRelationValue` (RA-28a §2), oriented as published.

##### T4. Identity 6 consequences

- **Remove RA-29b §3's ambiguity-witness requirement.** Ambiguity is irrelevant under T3.
- Keep:
  - the clean baseline;
  - the `relationTransport` tamper (`a6:a5-binding`);
  - the ≥2-step forest-path-structure tamper.
- Add three non-vacuous tampers on the same produced fixture:
  - **(a)** change one A7 path step's `appliedTransport` → `a7:selected-paths`;
  - **(b)** change one A6 `legacyProjection` step → `a6:legacy-projection`;
  - **(c)** change one A5 relation's `canonicalRelationValue` only, leaving the step unchanged → `a5:selected-step-value`, which fires in the A5 partition before any A6 check.

  Each must assert that the tamper changed the record before the verifier is called.

##### T5. Low — the ownership "trait" is self-declared

`static_assert(VerifiedSurfaceProducts::owns_products)` (`tests/…:7489`) tests a constant that the class declares about itself. Reverting to pointers while keeping the flag would still pass.

**Replace it with a behavioral check:** after `verify`, `&token.occurrences() != &originalA5` (and likewise for A6/A7), plus record-view equality. A pointer-holding token returns the original addresses, so it fails. Remove the self-declared constant.

##### T6. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived from the job log: 491 RUN in frozen order; 462/491; 29 REDs and signatures as listed; clustering confirmed. |
| R1-REV-01 | Diagnosis confirmed; correction **replaced** (RA-29c): exact three-hop binding; ambiguity witness removed. |
| R1-REV-02 | Confirmed; my RA-29a §4 error, owned. |
| New | T3 (the fallback can falsely reject, on inverted canonical values); R2 O(V·P) scan; T5 vacuous trait. |
| Gate | 491, unchanged; identities unchanged (identity 6 body changes). |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 204. |
| Successor | `M6-CP2-CB1-VERIFIER-R3` under RA-29b (§2, §4, §5) + RA-29c. |

## `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`; moved verbatim.

### M6-CP2-TB1-VERIFIER-R2-REV — Independent Review Record

**Disposition:** ACCEPTED / R3 CANDIDATE PROMOTED / M6-CP2 CLOSED
**Promoted package/source:** `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20`
**Reviewed runtime:** `37403703032 / 112076464024`, **491/491**
**Result/log artifacts:** `11387562709 / 11387233341`
**Exact successor:** `M6-DEFN-R5`

#### Review authority

This Review selected `READ_MODE=snapshot` before repository source/document inspection. Exact current review snapshot authority is source/event SHA `b26f19d934dd67e6eae26166200b923a86879e14`, workflow run `37409151437`, artifact `11388097916`, provider digest `sha256:b0154733104278a8963878292789677134a7567be911ab41ae8083c0786f3d3b`, archive digest `8f2736d20f8d75d0b5665d0a0f54d05826c7bd846b3df32e0b4c18d8e0a79ad0`, 5476 files, `runtimeExecution=false`.

The immutable candidate package was independently rechecked from artifact `11385836615`. Its ZIP SHA-256 is `40ea2966011865090ce49382300885ee132e82655fba4f98575f326b53ca2ea4`; root `SHA256SUMS` verifies 28/28; semantic source is exactly `c64baacd6c767c4ba053b6963651c0aa6eceed20`; its source archive SHA-256 is `fb7f08f193aa335944c5a3ff460ef481ec9f1dec6cefba676a563d374305bce9`; the command boundary records `runtimeExecution=false` and `exactArithmeticBackend=GMP`; the eight standard targets and GMP/GMPXX link evidence are present; captured source-status receipts are empty.

The current review snapshot's `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/`, and root `CMakeLists.txt` are byte-identical to the candidate's packaged source on those code surfaces. Static review therefore applies to the exact tested semantic candidate.

#### Independent runtime re-derivation

The R2 result ZIP matches `dada6a755d4ec6d695ab2b11b13c6d92452d4b1599e9ebda0e6bee751b23fdcf`; the log ZIP matches `5a6950535ec39f20e776759b0c0f1d241ee5228c346ea4d2afc3fe9fcf0b3c39`. The result self-manifest verifies **1005/1005** and hashes to `82943861e169fcdc8589bf13f0e068a663b837997792c454d7a6efb6b5788d7f`.

Independent ledger/raw-log checks establish focused30 **30/30**, CP2-focused12 **12/12**, selector449 **449/449**, aggregate **491/491**, exact-one **491/491**, zero skips and zero REDs. Every ledger `raw_sha256` matches its raw log; frozen identity/order/owner authority matches; `benchmark_execution=false`; configure/compile/relink/discovery/repair/mutation/retry flags are false; package/source/execution-view censuses are unchanged; postflight manifest remains 28/28.

Frozen hashes remain focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

#### Static adjudication of RA-29b/RA-29c recovery

The implementation is faithful to the frozen recovery and introduces no new Review finding.

1. `a0:component-adjacency` and its disconnected-component identity-2 witness are absent; no replacement rule infers ingress component labels from raw connectivity. Accepted selector449 ordinal144 is green.
2. A5 relations carrying `canonicalSelectedStep` require `canonicalRelationValue`, equal step transport, and `Forward` at `a5:selected-step-value`.
3. A6 reconstructs each path's selected-step subsequence from its own ordered relations/orientations and named certificates, using only step inversion and exact composition, and verifies optionality, ordered steps, composed transport and endpoints at `a6:legacy-projection`. The A6→A5 table still exact-binds `selectedRelationStep`.
4. A7 expected paths are grouped once by class from A6 `legacyProjection`s, sorted/deduplicated, and compared exactly at `a7:selected-paths`. The rejected reverse lookup/fallback, target-uniqueness assumption and per-A7 all-path scan are gone; complexity is O(P log P).
5. Relation-class, forest-size/spanning, selected-path reconstruction and map-based topology obligations remain intact.
6. Shared support authority, carried verification report and verified-token downstream reads remain intact.
7. `VerifiedSurfaceProducts` owns A5/A6/A7 values; the self-declared trait is gone. Identity 11 proves address inequality plus record-view equality.
8. Identity 6 retains baseline, relation-transport and >=2-step structure tampers and adds record-changing A7-step, A6-legacy-step and A5-value-only tampers at the three RA-29c sites. All focused12 rows are green.

No A5/A6/A7 producer semantic change was introduced by R3.

#### Prior finding closure

- **R1-REV-01:** CLOSED / RECOVERY PROVED — lossy A7→A6 reverse lookup removed; formerly affected accepted rows are green.
- **R1-REV-02:** CLOSED / RECOVERY PROVED — invalid raw-connectivity component rule removed; selector144 is green.
- **R1-REV-03:** CLOSED / RECOVERY PROVED — focused12 identity 6 baseline/tamper chain is green.
- **EXEC-OBS-01:** CLOSED / ORCHESTRATION RECOVERY PROVED — R2 uses its own `TURN_ID`; both result/log artifacts exist and verify.
- **RA-29c T3/T5:** CLOSED — fallback and O(V·P) scan are absent; ownership is behavioral.

These were non-stable recovery/specification defects. No new regression candidate or architecture-debt item is created. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

#### Promotion and routing

Candidate `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` is **PROMOTED** as reviewed M6-CP2 authority. M6-CP2 is closed. The exact successor is **`M6-DEFN-R5`**; that turn is not begun inside this Review.

---

#### Review-agent addendum (2026-10-06, resumed `M6-CP2-TB1-VERIFIER-R2-REV`)

**Disposition:**
- **Promotion of `11385836615 / c64baacd` as reviewed runtime authority: CONFIRMED.** 491/491, every R1 recovery item is closed, and no false rejection remains.
- **"M6-CP2 CLOSED": REVOKED. CP2 stays ACTIVE.** The frozen CP2 exit (§10: "independently recomputes … §6.2 elementary facts and fails typed on **every** §6.3 malformed-authority class") is not met:
  - one RA-28a §2 A7 binding is unimplemented (U1);
  - most verifier predicates have no executed negative witness, and identity 5 tests one of ten §6.3 classes (U2);
  - two runtime codes are dead (U3).
- **RA-29d** routes a bounded completion: `M6-CP2-CB2-COVERAGE` → TB (491) → `M6-CP2-CLOSE-REV`, with a closure record.
- Accounting **60 / 16 / 44**, debt 1.

##### U0. Independent re-derivation (confirmed)

- Result `11387562709`: ZIP `dada6a75...`. Log `11387233341`: ZIP `5a695053...`.
- `SHA256SUMS` (`82943861...`) verifies **1005/1005**.
- focused-30 (`1e815443`), focused-12 (`2aa57aac`) and selector449 (`d4a0d1b7`) ledgers are each in exact frozen order. Every row has exactly one selection, zero skips and PASS. **All 491 raw-log hashes match.**
- Candidate `c64baacd` source == HEAD. The R3 diff from `9c8478ae` touches the verifier and tests only (−2 header lines).
- **RA-29c is implemented as specified:**
  - `a5:selected-step-value`;
  - `a6:legacy-projection`, reconstructed along each path's own relations;
  - `a7:selected-paths`, grouped by class and sorted-unique.

  The reverse lookup, fallback and O(V·P) scan are gone, and identity 11's ownership check is behavioral.

##### U1 (High) — RA-28a §2's A7 vertex binding is not implemented

RA-28a §2 requires that "each A7 vertex's class equals one published A6 class (ID and member set); **its support equals the common A5 member support (RA-18)**". The A7 partition (`RemeshPipeline.cpp:8157-8222`) checks:
- `sourceOccurrences == members`;
- `vertex.support == resolve(vertex.sourcePoint)` (shared kernel);
- that every member's support equals the **support certificate's** `publishedSupport` (`:8204`).

It **never** checks:
- `vertex.support == publishedSupport` (or == the members' common support);
- `vertex.representative ∈ members`;
- `vertex.sourcePoint ==` the representative occurrence's published `point`;
- `vertex.position == vertex.sourcePoint.position`.

**Witness:** move one class's A7 vertex to an unrelated but self-consistent source point (any other face, with its kernel-resolved support). Every A7 check passes. This is the geometric weld that A7 and CP1 item 6 rule out. The verifier, the only independent certifier, cannot see it.

This is an implementation omission against frozen text. TB1-REV, R1-REV, R2-REV and my own addenda all missed it.

##### U2 (High) — CP2's exit criterion has no executed negative coverage

**Counts.** Of about 56 verifier failure sites, about 14 are referenced by any test. By failure code:

| Production sites | Codes | Test references |
|---|---|---|
| 4 | `OccurrenceOwnershipMismatch` (§6.2 occurrence ownership counts) | **0** |
| 5 | `MissingPublishedAuthority` (the §6.3 "infer missing endpoint/owner/…/relation" class) | **0** |
| 19 | `QuotientMembershipMismatch` | 2 |

**Untested negatives** (sites with no test anywhere):
- the RA-28a §1 core: `a6:exact-once-ledger`, `a6:forest-joining-set`, `a6:forest-cardinality`, `a6:forest-endpoints`, `a6:duplicate-certificate` / `-consumption`;
- A5: `a5:corner-owner`, `a5:exact-corner-ownership`, `a5:directed-side-cycle`;
- A7: `a7:support-cover`, `a7:class-cover`, `a7:topology-copy`;
- certificates: `certificate:a5`, `certificate:a6`.

**Identity 5** (`VerifierRejectsEveryForbiddenRepairClassWithoutMutation`, `tests/…:7647-7663`) applies **one** tamper: a duplicated class member → `SemanticIdentityMismatch`, plus a non-mutation check. The Definition (§1.4) claimed every §6.3 class "has a reachable record-view witness or is classified defensive". That was never demonstrated, and my DEFN-REV accepted the identity on its name (owned).

**Why 491/491 doesn't settle this.** It proves the verifier does not falsely reject valid products. It does **not** prove detection. A wrongly compared set in, for example, the exact-once ledger would still be green on valid data.

##### U3 (Medium) — two runtime codes are dead

`UncertifiedAuthoritySubstitution` (`RemeshPipeline.h:1504`) and `BoundaryOrEulerMismatch` (`:1499`) are **never emitted**. The recomputed boundary loops, components and Euler characteristic (`:8306`) are reported only as `CertificatePayloadMismatch:certificate:a7` (`:8314`), while the Definition matrix (§1.3) maps them to `BoundaryOrEulerMismatch`. RA-28a §5's rule ("no runtime code without a frozen predicate") applies in reverse: a code with no emitting predicate is a dead diagnostic.

##### U4 (Medium) — CP2 was closed without a closure record or exit adjudication

CP1 closed through a dedicated Review against a frozen checklist, with `M6_CP1_Closure_Record.md`, and every M4/M5 checkpoint has a closure record. This Review declared CP2 closed inside a TB Review, with no per-criterion mapping and no closure record. That is how U1–U3 went unnoticed.

##### U5 (Low; no change required) — inversion is shared with the producer

Hop 2 calls the producer helper `reverse_selected_relation_step` (`:7904`). It is pure exact algebra on a value type (flip direction, swap charts and components, invert the transform), which §6.2 permits. But the verifier and A6 share one definition, so an error there is invisible to both. Recorded. An independent five-line inversion is optional.

##### U6 (Low; owner M8-CP2) — the token copies all three products on every run

`VerifiedSurfaceProducts` copies A5/A6/A7 per pipeline run. Moving them in would avoid the copy. Recorded for resource accounting.

##### U7. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived: 1005/1005; frozen order; 491/491; all raw hashes match. |
| RA-29c | Implemented as specified; R1 findings closed. |
| Promotion | **Confirmed** (runtime authority `c64baacd`). |
| CP2 closure | **Revoked**: U1 (High), U2 (High), U3, U4 → RA-29d. |
| Gate | 491. Identity names and order unchanged; bodies of identities 2–5 strengthened; no new identity. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 205. |
| Successor | `M6-CP2-CB2-COVERAGE` → `M6-CP2-TB2-COVERAGE-EXEC` (491) → `M6-CP2-CLOSE-REV`. `M6-DEFN-R5` follows CP2 closure. |

## `Architecture_M6_CP2_TB1_Verifier_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP2_TB1_Verifier_Review_Record.md`; moved verbatim.

### Architecture M6 CP2 TB1 Verifier Review Record

**Turn:** `M6-CP2-TB1-VERIFIER-REV`
**Disposition:** **REJECTED FOR BOUNDED RECOVERY / THREE EXEC REDS ARE FALSE-REJECTION WITNESSES / FOUR STATIC CONTRACT GAPS / NO PROMOTION**
**Reviewed candidate:** artifact `11365308211`, semantic source `265c8fbb19a66c5c3344a525fdbd43932c3ef829`
**Runtime evidence:** run/job `37368784487 / 111962223674`, result `11370598981`, log `11370413984`
**Mechanical gate:** focused30 `30/30`, CP2-focused12 `9/12`, selector449 `449/449`, total `488/491`
**Accounting:** `60 events / 16 categories / 44 recurrences`, debt 1. No accepted-green row regressed.

#### 1. Independent evidence verdict

The artifact-only execution is mechanically valid. All 491 frozen exact-filter processes ran once, selected exactly one test, skipped none, ran zero benchmarks, and left the immutable package/source/execution view unchanged. The run-level failure is mailbox-only: validator and runtime jobs succeeded and the result/log artifacts were uploaded before the mailbox job was cancelled. The candidate is nevertheless **not promotable** because three focused-12 rows are RED and independent static review finds additional RA-28a contract omissions.

#### 2. Adjudication of the three EXEC candidates

##### CAND-01 — FALSE REJECTION / TEST-WITNESS AUTHORITY DEFECT / NON-STABLE

`M6CP2.VerifierRecomputesA0AndA5ElementaryIncidenceIndependently` swaps two corners of one source triangle. `SourceFaceTopologyKey::make` canonicalizes by sorting the three source vertex IDs, so the row still denotes the same source-face topology. The expected `SourceIncidenceMismatch / a0:source-faces` precondition is never created.

**Recovery:** alter one vertex so the canonical topology key actually changes while remaining a valid triangle, and assert `sourceAuthority.matches_source_faces(...) == false` before calling the verifier. Then require the exact A0 finding.

##### CAND-02 — FALSE REJECTION / TEST-WITNESS AUTHORITY DEFECT / NON-STABLE

`M6CP2.CertificateChainRequiresExactA5A6A7PayloadBinding` resets `selectedRelationStep` on the first `OrdinaryFront` certificate. Production already resets that optional field for `OrdinaryFront`, so the tamper is a no-op.

**Recovery:** tamper an always-bound field, preferably `relationTransport`, after asserting the baseline certificate equals the cited A5 `canonicalTransport`; mutate the transport and assert inequality before verifier invocation. Require exact `CertificatePayloadMismatch / a6:a5-binding`.

##### CAND-03 — FALSE REJECTION / TEST-FIXTURE NON-VACUITY DEFECT / NON-STABLE

`M6CP2.WeldPinchedRecordViewFailsIndependentManifoldness` searches the one-square fixture for two classed cells with disjoint quotient-corner sets. No such pair exists, so `tampered` remains false and the verifier is never called on the intended pinched topology.

**Recovery:** use a produced fixture with two disconnected/disjoint classed-cell components (the existing overlap fixture is an accepted candidate), assert the disjoint pair exists, weld one quotient corner across the pair, then require `NonManifoldTopology / a6:vertex-link`.

These three REDs are not stable regressions. They are failed negative witnesses on new CP2 gate authority.

#### 3. Static contract gaps discovered by Review

##### REV-OBS-01 — RA-28a §6 pipeline result does not carry the verified report — RECOVERY REQUIRED

`build_authoritative_phase_front_mesh_with_hard_features` obtains `VerifiedSurfaceProducts`, projects them, and returns `AuthoritativePhaseFrontMeshResult`, but that result type contains no `VerificationReport`. Identity 11 only inspects `VerifiedSurfaceProducts::report()` directly. This does not satisfy RA-28a §6's behavioral requirement that **a pipeline result carries a verified report**.

**Recovery:** successful authoritative pipeline results must retain the exact A8 `VerificationReport` that authorized projection; do not synthesize a new empty/green report after projection. Reorder declarations if needed to carry `std::optional<VerificationReport>` (or semantically equivalent exact report carrier). Identity 11 must call the full pipeline and assert the returned report is present, verified, and is the report produced before projection.

##### REV-OBS-02 — RA-28a §8 wrong-region identity does not prove an A0-valid alternate region — RECOVERY REQUIRED

Identity 8 constructs `TopologyRegionId(current.index()+1)` through a test helper whose extent is synthetic. It proves only type construction and inequality; it does not prove the replacement ID belongs to the fixture's `SourceTopologyRegions`. RA-28a §8 explicitly freezes a **valid** alternate topology region.

**Recovery:** use a produced fixture with at least two A0 regions and a bridge witness, or a dedicated produced fixture. Assert both the original and replacement IDs occur in `sourceAuthority.regions()`, assert they differ, keep both sheets in-set, republish A5, require fresh A6 success, then require exact A7 `UncertifiedCrossSheetBinding / cross-sheet:wedge`.

##### REV-OBS-03 — RA-28a §3 shared source-support kernel is bypassed — RECOVERY REQUIRED

The verifier uses local `verification_support_incident_to_face/edge` helpers. RA-28a §3 requires exact A0 support incidence **through the shared source-support kernel**. A5 already derives support with `geometry::SurfacePointSourceSupportResolver`, and every published occurrence carries the source `point`.

**Recovery:** in the A5-incidence partition instantiate/use the shared `SurfacePointSourceSupportResolver` over A0 source faces, resolve each published occurrence point, and require the resolved identity to equal the published support before wedge/seam incidence checks. Local duplicated support classification must not be the sole authority. Identity 2 must include a non-vacuous support/point mismatch that only passes when the shared kernel agreement is checked. No A5 producer routine may be called.

##### REV-OBS-04 — RA-28a §1.4 selected-path verifier does not prove the path is the published forest path — RECOVERY REQUIRED

The verifier composes the certificate IDs and orientations listed in each `selectedPath`, but it does not independently prove those ordered relations/orientations equal the unique traversal in the published `selectedForest`. Production validation does perform that stronger check via `quotient_forest_path`. A self-consistent but unrelated certificate list can therefore satisfy the verifier's composition check while violating the frozen phrase “along the class's published selected path.”

**Recovery:** independently traverse the **published forest** inside the verifier (no producer routine), derive the unique root→target relation/orientation sequence, and require exact equality with `orderedRelations` and `traversalOrientations` before using it for transport composition. Require one selected path per non-root class member, exact root/target/class membership, and exact path cardinality. Extend identity 6 with a tamper that preserves a plausible composed transport but breaks forest-path relation/orientation identity; require `QuotientMembershipMismatch` for path structure or `NamedTransportMismatch` only for transport disagreement after structure is valid.

#### 4. Review verdict and recovery boundary — RA-29

The candidate is **REJECTED FOR BOUNDED RECOVERY**. No production runtime is promoted. The three EXEC REDs remain non-stable test authority defects, while REV-OBS-01/03/04 are production verifier/API contract omissions and REV-OBS-02 is a latent test-witness defect. None reprices the stable regression ledger because no accepted-green identity regressed.

The only authorized successor is `M6-CP2-CB1-VERIFIER-R2` under `Architecture_M6_CP2_CB1_Verifier_R2_Recovery_Code_Build_Plan.md`, followed by fresh immutable `M6-CP2-TB1-VERIFIER-R1-EXEC` (**491**) and mandatory `M6-CP2-TB1-VERIFIER-R1-REV`. No test-only shortcut, selector reduction, promotion, or runtime retry against the old package is authorized.


#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; CP2-focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. No selector bytes changed. |
| Decisive claims independently re-derived | Re-opened exact source and runtime evidence; re-derived all three false-rejection roots and the four static RA-28a gaps from the bytes rather than from the EXEC narrative. |
| Non-vacuity checked | CAND-01/02 are canonical/no-op tampers; CAND-03 never constructs the malformed topology. RA-29 requires explicit pre-verifier non-vacuity assertions for each recovery witness. |
| Prior obligations discharged/carried | RA-28a/RA-28b verifier obligations adjudicated here. CAND-01..03 and REV-OBS-01..04 carried only to `M6-CP2-CB1-VERIFIER-R2`; `M6-DEFN-R5` remains after CP2. |
| Stable accounting | `60 / 16 / 44`, debt 1. Candidate `11365308211 / 265c8fbb...` remains unpromoted; accepted reviewed runtime remains `11330703256 / 3f40f04a...` until an R1 Review promotes a replacement. |
| New candidates/obligations recorded | CAND-01/02/03 adjudicated false-rejection/non-stable; REV-OBS-01..04 added to `Regression_Root_Cause_Tracker.md`, owned by R2. |
| ORIENTATION currency line | `M6-CP2-TB1-VERIFIER-REV`, 2026-10-05, candidate rejected; R2 exact next. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated to CP2 R2 recovery; §4 has no milestone witness-state change (test-fixture defects only); §8 records a new instance of the existing non-vacuity/canonical-witness pattern. |
| CHANGELOG | Review rejection / RA-29 entry added. |
| ROADMAP | Live M6 routing updated to R2 recovery then fresh 491-process R1 EXEC + Review. |
| Selector manifest | n/a — no selector added, removed, reordered or newly accepted. |
| LESSONS | No new lesson; existing lesson 10 (non-vacuity must prove the witness can satisfy its precondition) governs the three failed negative witnesses. |
| Consolidation under CLEAN_UP_POLICY | CP2 Definition plan/record/Review and superseded CB1 verifier plan/stop-review/build-report folded into `M6_Consolidated_Record.md` §53 + folded-document index; current TB report, current Review, R2 plan, frozen definitions and selectors retained. |
| Successor frozen | Exactly `M6-CP2-CB1-VERIFIER-R2`; falsifiers and stop rules are frozen in `Architecture_M6_CP2_CB1_Verifier_R2_Recovery_Code_Build_Plan.md` and RA-29. |
| Turn boundary held | runtime-free Review; no product, test, fixture, selector, benchmark or build-source mutation. |
| review_check.py boundary | PASS; selector449 declared hash matched and no product/test/fixture/build/selector mutation was detected. |
| `STATUS` lifecycle maintained | Entry and resume beacons maintained; COMPLETE beacon is the final repository mutation after documentation/cleanup. |
| Pushed to origin, branch in sync | Repository patch application and cleanup are verified at remote branch authority before the final COMPLETE beacon; no ahead/behind local branch is used as authority in ChatGPT Web. |

---

#### Review-agent addendum (2026-10-05, resumed `M6-CP2-TB1-VERIFIER-REV`)

**Disposition:**
- **Rejection, non-stable classification and R2 routing: CONFIRMED.**
- CAND-01/02/03 and REV-OBS-01/03/04: **confirmed**.
- **REV-OBS-02: WITHDRAWN as over-strict** (it adds fixture risk and no discriminating power).
- **Five verifier defects TB1-REV missed** (S1–S5), plus two precision items. RA-29a adds them to R2.
- Gate unchanged at **491**: every item folds into an existing identity or is a static requirement.
- Accounting **60 / 16 / 44**, debt 1.

##### S0. Independent re-derivation (confirmed)

- Result `11370598981`: ZIP `e9260e35...`. Log `11370413984`: ZIP `a455e284...`.
- `SHA256SUMS` (`2d7d7984...`) verifies **1005/1005**.
- focused-30, focused-12 (`2aa57aac...`, 12 rows; identity 12 already carries the RA-28b name) and selector449 are each in exact frozen order. Every row has exactly one selection and zero skips. **All 491 raw-log hashes match their ledger rows.**
- REDs are exactly focused-12 ordinals **2** (`:7553`), **6** (`:7615`) and **7** (`:7654`, `tampered == false`). Result **488/491**.
- Candidate `265c8fbb` source == HEAD source. Diff from `3f40f04a`: header +153, `RemeshPipeline.cpp` ±1236, tests +552.

##### S1. Confirmed TB1-REV findings

- **CAND-01.** `matches_source_faces` compares canonical (sorted) face keys, so a corner permutation is a no-op (`:7486-7491`).
- **CAND-02.** The field table is implemented exactly (`:7690-7702`). `OrdinaryFront` certificates carry `selectedRelationStep == nullopt`, which equals A5, so resetting it is a no-op.
- **CAND-03.** In a 2×2 grid every cell shares the centre vertex, so there is no disjoint pair.
- **REV-OBS-01** (result carries no report) and **REV-OBS-04** (paths are composed but never checked against the published forest traversal) are accurate.
- **REV-OBS-03 is accurate and gate-neutral.** The local helper `verification_support_incident_to_face` (`:7390-7408`) only checks that the support touches the point's face; a face-interior point published with a vertex support passes. The frozen §6.2 "shared source-support kernel" is `SurfacePointSourceSupportResolver`, which §6.2 permits as a shared primitive. A5 publishes `resolve(canonicalPoint)` verbatim (`:4265-4268`), so the equality check costs nothing on valid data. **It must also cover A7's class binding**, which uses the same local helper (`:8031-8044`).

##### S2. New findings

**S2.1 (High) — a class split along a `Joining` relation passes the verifier.**
- The per-class spanning check counts only forest edges with both endpoints in the class (`:7842-7877`). `forestRelations == joiningRelations` and the endpoint-equality check do not require a forest edge to be intra-class. Nothing compares |forest| with Σ(|members| − 1).
- **Witness:** split a class C at forest edge `e` into C₁ and C₂. Each half is still spanned by its own edges, and `e` becomes a cross-class `Joining` edge. Every check passes, so a relation is "consumed" as joining while its endpoints are not identified. That is a fail-open on exact-once semantics.
- `CycleClosing` relations are class-checked (`a6:cycle-class`); `Joining` relations are not.
- My RA-28a §1.3 wording ("its published forest edges") was ambiguous here (owned).
- **Fix:** every owned relation, whatever its disposition, must have both endpoints in one class (`a6:relation-class`), and |forest| = Σ(|members| − 1).

**S2.2 (Medium–High) — quadratic topology passes in a verifier that now runs in production.**
- Boundary and cell adjacency rescan every cell for every edge (`:7929-7948`): O(E·C).
- The vertex-link check rescans every edge for every vertex (`:7987-8023`): O(V·E).
- The verifier runs on every authoritative pipeline run (`:8491`), so this adds superlinear cost to production; M4 CP-SCALE made boundedness an explicit requirement. TB1 rows are small, so it passed.
- **Fix:** build a single edge → owning-cells map and per-vertex incident-edge lists in one pass, giving O(n log n). This is a static requirement in R2, with no gate change.

**S2.3 (Medium) — the A7 selected-step binding is not the exact cited relation.**
- `:8101` matches the first A5 relation with the same `railId` or `periodicRelation`. Several A5 relations can share a rail or periodic ID, so this is first-match and not the "cited A5 relation" of RA-28a §2.
- A7 steps carry no relation ID. The exact citation runs through the A6 `QuotientSelectedPathCertificate.orderedRelations` that the A7 path projects.
- **Fix:** bind each A7 HardRail/Periodic step to the relation ID at the same position of the class's A6 path certificate (the HardRail/Periodic subsequence), and compare `canonicalRelationValue` with that exact relation. If the projection correspondence cannot be shown, require every A5 relation sharing that rail or periodic ID to carry an identical `canonicalRelationValue`, and record why.

**S2.4 (Medium) — the A0 partition omits component adjacency.**
- Frozen §6.2 lists "source face/edge/vertex incidence and component adjacency from A0". The A0 partition only checks `matches_source_faces` and that hard-feature edges exist (`:7484-7513`).
- **Fix:** recompute the connected components of A0 face edge-adjacency and require `component_for_row` to induce the same partition (labels up to renaming).

**S2.5 (Medium–Low) — `VerifiedSurfaceProducts` is bound to addresses, not contents.**
- It stores non-owning raw pointers to A5/A6/A7 (`RemeshPipeline.h`, `VerifiedSurfaceProducts`) and is copyable, so a copied or escaped token can outlive or re-point at different storage.
- After projection, the adapter keeps reading the raw `occurrenceComplex` for its counters (`:8508+`).
- **Fix:** the token **owns** the products (moved or `shared_ptr<const>`), **or** it is non-copyable and confined to the stage function's scope. Post-projection counters read through the token.

##### S3. REV-OBS-02 withdrawn; precision items

- **REV-OBS-02 (and my RA-28a §8 word "valid") is withdrawn.** Identity 8 already asserts the exact rejection site `cross-sheet:wedge`, and nothing before the wedge rule checks region validity. So a synthetic region ≠ `topologyRegion` already kills the region-omitting mutant (identity 8 is green).
  - Requiring an A0-valid alternate region needs a produced fixture with two regions **and** a bridge occurrence. None exists, so that would invite another CAND-01-style RED for no extra discrimination.
  - Identity 8 stays as is, plus one added assertion: the replacement region ID ≠ the occurrence's region.
- **CAND-03 precision.** The weld must change **only** `classedCells` corner class IDs, never `classes` or the forest. A class merge trips the A6 ledger partition first, and gating (RA-28a §4) then skips the topology partition, so `a6:vertex-link` would never run. Assert the pre-tamper disjointness and that the ledger partition stays clean.
- **REV-OBS-04 tamper.** Use a produced class with at least a 2-step selected path. Where available, use non-commuting transports so that composition order is also pinned.

##### S4. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived: 1005/1005; frozen order; 488/491; all raw hashes match; REDs 2/6/7. |
| TB1-REV findings | CAND-01/02/03 and REV-OBS-01/03/04 confirmed; REV-OBS-03 extended to A7; REV-OBS-02 withdrawn. |
| New | S2.1 (High), S2.2, S2.3, S2.4, S2.5 → RA-29a. |
| Gate | Unchanged at 491. S2.1 → identity 3; S2.3 → identity 6; S2.4 → identity 2; S2.5 → identity 11; S2.2 is static. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 203. |
| Successor | `M6-CP2-CB1-VERIFIER-R2` under RA-29 + RA-29a. |

## `Architecture_M6_DEFN_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R1_Review_Record.md`; moved verbatim.

### M6-DEFN-R1 Independent Review Record

**Turn:** `M6-DEFN-R1-REV`
**Type:** mandatory runtime-free independent Review (review agent)
**Disposition:** **CORE MODEL UPHELD / NOT ACCEPTED AS FROZEN / FOUR BLOCKING AMENDMENTS / CB4 STAYS HELD / EXACT NEXT `M6-DEFN-R2`**
**Reviewed definition:** `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md` plus the `M6-DEFN-R1` edits to `Architecture_M6_Frozen_Definitions.md` (commit `02143b8e`)
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`

#### 1. Evidence re-opened

- **Definition snapshot:** run/artifact `36091204501 / 10846121134` has provider digest and download SHA-256 `194e16d6...be99`. Its embedded `source.tar.gz` is `591afb01...f077`, and its `src/pipeline/RemeshPipeline.cpp` is `9436ad68...`, byte-identical to `660015f2`. `git diff 660015f2 63330339 -- src include tests` is empty.
- **Selector/routing and focused tests:** selector449 is `d4a0d1b7...d6414` and routing449 is `9c88a5ed...c5707`. The six focused identities are unchanged. The seventh, `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`, does not yet exist in `tests/`.
- **Focused row5 body** (`SurfaceCellTransitionQuotientTests.cpp:2626-2642`) is byte-identical to accepted `e284fea7`.
- **Accounting:** stable accounting stays **54 / 16 / 38**, debt 1. This Review creates no runtime event.

#### 2. What is upheld

The core model is correct and is the right answer to the TB3 findings:

- occurrence authority is the complete `CornerWedgeSheetSet` (D1);
- seam certificates are carried by the wedges and sides that actually cross the seam, keyed by `(region, seam edge)`, so an interior seam vertex is unambiguous (D2);
- `OrdinaryFront` stays owner-less, `OccurrenceRelationId` is unchanged, and A6 checks side-sheet membership in both endpoint wedge sets (D3);
- A7 records the union of member wedge sets (D5);
- no occurrence record mixes faces (D6).

The split-square table (§3), the eight endpoint-pair memberships and the interior seam-vertex chain re-derive independently and are correct. Soundness of D3 also holds: every relation step shares at least one sheet between its endpoints, so every cross-sheet transition inside a class happens within a certified wedge, or on a certified seam-collinear side (D4).

#### 3. Blocking findings

##### B1 — As frozen, the definition makes TB4 RED: D5 conflicts with frozen focused row5

Focused row5 asserts `EXPECT_FALSE(lineage.equivalences.empty())` for **every** lineage with more than one sheet (`SurfaceCellTransitionQuotientTests.cpp:2631-2641`). Lineage `equivalences` are produced only by relation unions: `occurrenceEquivalences[...]` is pushed in the union loop (`RemeshPipeline.cpp:4384-4393`) and aggregated per class (`:4545-4548`).

In the split square, v0 = `{c00.0}` and v2 = `{c11.2}` are single-occurrence classes on the square boundary. Neither has any relation. Under D5 their lineage becomes `{0,1}`, which is exactly what DEFN-R1 §3 requires, while their `equivalences` stay empty. Row5 therefore fails twice, and TB4 cannot be 456/456 as pre-registered.

The D8 identity checks only A5 publication, so it does not cover the A7 completeness that D5 introduces. DEFN-R1 §5 lists only falsifiers over the new definition; none of them asks whether the **existing frozen assertions** stay satisfiable.

**Amendment.** Freeze how verified wedge (and seam-collinear side) evidence appears in `PureQuadVertexLineage::equivalences`, the only evidence field row5 inspects. Recommended: a new `PureQuadEquivalenceKind` value (e.g. `CornerWedgeIsolation`) whose `PureQuadEquivalenceProvenance` carries the crossed seam key(s) and an explicit `fromSheet → toSheet` orientation, with `firstFrontEdge/secondFrontEdge = -1`. Current kind consumers only filter `HardRail`/`PeriodicHolonomy` (`PureQuadCompletion.cpp:801/925/1019/1059`, `RemeshPipeline.cpp:5556/5624`), so a new kind is neutral there. No test pins completion hash constants, and only row5 inspects `equivalences.empty()`. Extend D8's identity to assert materialized lineage too: v0, centre and v2 each `{0,1}` with non-empty wedge evidence, and every other vertex a singleton.

##### B2 — D6 does not say which face binding each existing consumer uses

D6 correctly makes chart, branch and sheet per-binding, but several transitional consumers read exactly one value per occurrence today. Left open, CB4 must invent a selection, which is the representative choice this work removes:

1. **Transitional class key.** `QuotientDomainState = (region, sheet, latticeX, latticeY, branchRotation, scale, chart)` per member (`:4399-4432`) forms `QuotientClassKey`. That key drives the transitional `QuotientClassId` ordinal (`:4465-4492`) and the `UnpairedDuplicateAuthoritativeCorner` guard (`:4457-4461`). DEFN-R1 says "`QuotientClassId` unchanged", but the value CB4 must compute changes type. Also, the transitional ordinal already differs from frozen §4.3 (sorted member set).
2. **`representative_key`** (`:4503-4516`) uses `isolationSheet` and `chart.chart`.
3. **Selected relation paths.** `SelectedRelationPathCertificate.startChart/endChart` and `start/endChartComponent` (`:4633-4637`), plus `SelectedRelationStep.from/toChartComponent` (`:4377-4380`), come from single occurrence values. Accepted torus rows 444 and 448 pin these certificates.
4. **Lineage `sourceCharts`.** D5 defines `sourceIsolationSheets` only. The typed remap check requires each lineage chart's face sheet to be in the lineage sheet set (`:11470-11490`).

**Amendment.** Freeze one selection rule per consumer. Recommended:

- relation-local consumers (items 3 and D3) use the binding of the relation side's interior face at that endpoint;
- class-level consumers (items 1, 2 and 4) use the complete sorted binding list or its union;
- `chartComponent` is declared occurrence-wide, with a fail-closed check that it is constant across the wedge (isolation seams are not chart barriers: `SourceChartTransitions.h` graph uses topology regions and hard edges only);
- state explicitly what "`QuotientClassId` unchanged" means for the transitional ordinal.

##### B3 — Wedge endpoints still rely on tie-broken faces; the definition names one of three side builders

D1's operational rule traverses from "the last positive-length incoming segment" to "the first positive-length outgoing segment". Those are `SurfaceTraceSegment::face` values, which are tie-broken whenever a side runs along **any** source edge, not only a seam. D4 replaces the tie-break only for seam-collinear sides.

There are three side builders, all feeding A4 node-shared corners:

| builder | used by | side segmentation | tie-break |
|---|---|---|---|
| `build_uniform_phase_front_for_faces` | split square (planar/uniform) | `segment_on_source` (`SurfaceCellTracing.cpp:11161`) | smallest **source-face row** (`interval.face < selectedFace`, `:11239`), which depends on row order |
| `build_periodic_annulus_phase_front_for_faces` | periodic annulus | `periodic_chart_segment` (`:12456`) | lexicographic triangle (`:12529`) |
| `build_curved_bounded_disk_phase_front_for_faces` | curved bounded disk | `bounded_disk_chart_segment` (`:12581`) | lexicographic triangle (`:12648`) |

DEFN-R1 §1, and this reviewer's own TB3 addendum and DEFN-R1 plan (which cited `:16222` and the bounded-disk builder for the split square), named only the last. The split-square node layout is the same in the uniform builder (`gridU = round(width/target)`, nodes at `frame.minU + stepU·u`), so the §3 table stands. The citation is corrected here.

**Amendment.** Make D1 and D4 one exact rule:

- *Collinearity* is decided by the exact `SourceSupport` of the segment interior (the same `supportResolver` A5 already uses): an edge support means the segment is collinear with that edge. It is not decided by tolerance bands or by which triangle the tracer chose.
- *Interior-side face* of every collinear segment (seam or not) is recommended to be the incident face whose consistent source winding contains the side's directed edge. This is combinatorial and exact, needs no chart geometry, and is available to A5 from `sourceFaces`. It is valid **iff** validated cell cycles are oriented consistently with source winding. `orient_and_validate_phase_front_cell` orients against the builder frame normal, which is not yet proved equivalent for all three builders. DEFN-R2 must prove it or choose the chart-orientation rule and name its inputs.
- *Wedge fan* is the winding-order arc around the support between the outgoing and incoming interior faces.

##### B4 — D7 contradicts frozen §4.6 and cannot be implemented as an adapter mapping

Frozen §4.6 keeps "M5's accepted typed relation failures remain unweakened". D7 deletes the downstream `MissingHardRailRelationOwner`, the owner half of `InvalidPeriodicRelationOwner`, and the kind half of `IncompatibleAuthoritativeFrontPair`. Only the HardRail mismatch gets an adapter mapping back to its M5 name.

A5's `UnownedRelation` is many-to-one: it covers a missing HardRail owner, a periodic owner that is missing or mismatched, a boundary-kind mismatch, and an out-of-range opposite edge (`RemeshPipeline.cpp:3408-3450`). The adapter therefore cannot restore the specific M5 codes. Those failures become generic `OccurrenceUnownedRelation`. That is the same specific → generic change that was counted as a stable `VALIDATION_ORDER_SHADOWING` event at row140; it escapes counting here only because no test pins those codes yet.

**Amendment.** Recommended:

1. Split A5's structural relation failures 1:1, e.g. `OccurrenceHardRailOwnerMissing`, `OccurrenceHardRailOwnerMismatch`, `OccurrencePeriodicOwnerMismatch`, `OccurrenceRelationKindMismatch`, and keep `OccurrenceUnownedRelation` for genuinely ownerless cases.
2. Have the transitional adapter map each to its legacy M5 name through one table.
3. Then delete the unreachable downstream duplicates.

The alternative is to amend §4.6 explicitly so the external failure contract is only the accepted test surface.

#### 4. Non-blocking precision items (fold into DEFN-R2)

- **P1.** Seam-collinear sides may span several seam edges or be only partly collinear. Evidence is an **ordered certificate list**, not "the same certificate". D3 or D4 is chosen **per endpoint pair** by whether the near-endpoint segment is collinear.
- **P2.** Both reciprocal directed sides must agree on the near-endpoint interior face and sheet for a non-collinear pair; disagreement is a typed A6 failure.
- **P3.** Wedges at singular or excluded source vertices, or at nodes that are SingularityPort corners, are out of CP1 scope. A5 has no SingularityPort producer, so declare them a typed A5 failure rather than leaving them undefined.
- **P4.** HardRail-closure rows assert single-sheet lineage (`SurfaceCellsPhase10Tests.cpp:6351`, `:6632`). Record that wedges never cross a region boundary, so rail-adjacent wedges without seams stay singletons.

#### 5. Why a definition turn rather than reviewer amendments

B2 and B3 each need a design decision with a proof obligation: the per-consumer binding rule, and whether cell orientation agrees with source winding in all three builders. B1 extends a public lineage product schema. Freezing these as unverified reviewer text and sending them straight to Code + Build would repeat the TB3-REV error of freezing an unproved model into a CB turn. A bounded, runtime-free `M6-DEFN-R2` is cheaper than another CB → 456-process TB → Review cycle.

#### 6. Successor

Exact next: runtime-free **`M6-DEFN-R2`**, then mandatory `M6-DEFN-R2-REV`, then the re-scoped `M6-CP1-CB4` (plan stays HELD and must be revised by DEFN-R2). Scope: `Architecture_M6_DEFN_R2_Amendment_Plan.md`.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...c5707` |
| Decisive claims independently re-derived | snapshot `10846121134` digest and source byte-identity to `660015f2`; split-square table and eight memberships; seam-vertex chain; row5 body unchanged since `e284fea7`; equivalence provenance path; the three side builders and their tie-breaks; many-to-one A5 `UnownedRelation` |
| Non-vacuity checked | B1 is decisive by construction: v0 and v2 have no relations, so under D5 their lineage is `{0,1}` with no equivalences, which violates `:2639` |
| Prior obligations discharged/carried | TB3 addendum A7.1-A7.9: core decisions discharged; A7.5 (lineage) and A7.6 (single-face record) carried as B1/B2; A7.8 carried as B4 |
| Stable accounting | **54 / 16 / 38**, debt 1; +0 |
| New candidates/obligations recorded | B1-B4 and P1-P4 → `M6-DEFN-R2`; tracker entry +0 |
| ORIENTATION currency line | `M6-DEFN-R1-REV`, 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 updated; §4 n/a |
| CHANGELOG | root and Directional prepended |
| ROADMAP | status line and M6-CP1 row updated |
| Selector manifest | n/a |
| LESSONS | 180 added (audit every frozen assertion over a widened output) |
| Consolidation under CLEAN_UP_POLICY | consumed `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Plan.md` and `Architecture_M6_DEFN_R1_Review_Plan.md` folded into `M6_Consolidated_Record.md` and removed; DEFN-R1 record retained as current definition authority; CB4 plan retained, HELD |
| Successor frozen | exactly `M6-DEFN-R2`, then `M6-DEFN-R2-REV` |
| Turn boundary held | runtime-free; no source/test/fixture/selector/benchmark/build mutation; no compile or Directional runtime |
| review_check.py boundary / ledgers | recorded in the review commit message |
| `STATUS` lifecycle maintained | entry `M6-DEFN-R1-REV / IN_PROGRESS` (Started/Resumed = operator handoff `2026-09-25T04:29:24Z`) → docs → COMPLETE last |
| Pushed to origin, branch in sync | verified after the final push |

## `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`; moved verbatim.

### M6-DEFN-R1 Seam-Incident Occurrence Sheet Authority — Definition Record

**Turn:** `M6-DEFN-R1`
**Type:** Definition amendment, runtime-free
**Predecessor:** `M6-CP1-TB3-REV` review-agent addendum A2–A7
**Successor:** mandatory `M6-DEFN-R1-REV`; only after Review acceptance may re-scoped `M6-CP1-CB4` begin
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**Static source authority for this Definition:** source-snapshot run/artifact `36091204501 / 10846121134`, exact source/event SHA `63330339b116c8a6a56740de5b1160e8b4195992`, provider artifact digest `194e16d68da52525c35ad70079bf929d69acaf1622ceef7c5aee9728e541be99`, embedded `source.tar.gz` SHA-256 `591afb01d4e02f06e5603f1c52886659866cc1c09ba1a6a44f94d016e341f077`.

This turn changes definitions, plans, and durable records only. It does not change product source, tests, fixtures, selectors, benchmarks, or build logic, and it executes no generated Directional runtime.

#### 1. Static re-derivation

The exact snapshot confirms the TB3 Review addendum rather than the held CB4 repair model.

- `bounded_disk_chart_segment(...)` resolves a segment whose midpoint belongs to more than one source triangle by choosing the lexicographically smallest triangle. That is a representation tie-break, not semantic sheet authority.
- A5 currently obtains occurrence support/component/sheet from the outgoing-side start face, while `LocalLatticeState.sourceChart` and `branchRotation` still originate from the shared node's selected face. One occurrence can therefore mix two source-face authorities.
- `OrdinaryFront` carries no semantic owner in `OccurrenceRelationId`; HardRail and Periodic do. The materializer reconstructs isolation evidence later from front-edge boundary-path routes.
- The split-square fixture is the unit square cut by seam `(v0,v2)`, with face 0 below the diagonal on sheet 0 and face 1 above it on sheet 1, and target size 0.5. Its 2×2 cell lattice therefore contains seam-incident endpoint and center occurrences whose complete cell-interior corner wedges touch both sheets.

**Process observation recurrence, +0:** this ChatGPT Web turn repeated `M6-DEFN-OBS-01` by opening several small repository documents before explicitly freezing `READ_MODE=snapshot`. No semantic conclusion or repository mutation other than the required entry beacon was accepted from those reads; all decisive static conclusions above and below were re-derived from the verified exact snapshot. Existing conservation policy already covers the pattern, so this is not a new lesson or stable regression event.

#### 2. Frozen decisions

##### D1 — Occurrence sheet authority is a corner-wedge sheet set

Each occurrence publishes a canonical **`CornerWedgeSheetSet`**: the sorted, unique, non-empty set of `IsolationSheetId` values of source faces covered by that cell corner's interior wedge around the exact `SourceSupport`.

- At a face-interior support the set is the single incident sheet.
- At a source-edge support it contains the sheet(s) of the one or two source faces covered by the wedge.
- At a source-vertex support it contains the sheet(s) of the contiguous source-face fan arc covered by the wedge on the cell-interior side.
- At a non-seam corner it remains a singleton, preserving current behavior.

A single `IsolationSheetId` is rejected as incomplete authority at a seam-incident corner because choosing the shared-node face or outgoing-side face silently discards another sheet that belongs to the same semantic occurrence.

##### D2 — Isolation certificates live on the geometric/topological object that crosses the seam

A corner occurrence publishes **`CornerWedgeIsolationEvidence`** consisting exactly of the checked `(TopologyRegionId, SourceEdgeTopologyKey)` isolation-seam certificate references crossed by its contiguous wedge fan, in canonical seam-key order. Each reference also records the wedge traversal orientation (`fromSheet -> toSheet`); the referenced M5 certificate remains the semantic certificate and is not copied or re-invented.

A directed side publishes **`DirectedSideIsolationEvidence`** for checked seam crossings that occur in the side interior or along a seam-collinear side. These are side facts, not `OccurrenceRelationId` owner fields.

Consequences:

- `OrdinaryFront` stays owner-less and `OccurrenceRelationId` is unchanged.
- HardRail and Periodic owner semantics are unchanged.
- At a seam vertex where two seam edges separate the same sheet pair, a wedge crossing both carries two distinct certificate references because the seam-edge key is part of identity. No search or arbitrary representative is required.
- Missing/duplicate/nonmatching required seam evidence is a typed A5 construction failure.

The held relation-owned CB4 model is rejected: the relation need not geometrically cross the seam that explains an endpoint wedge's multi-sheet authority, and assigning a seam certificate to such a relation would be convention rather than derivation.

##### D3 — A6 ordinary-relation validation uses endpoint wedge membership plus side evidence

For a non-seam-collinear reciprocal `OrdinaryFront`, A6 validates each endpoint pair with the side-local near-endpoint sheet already fixed by the incident cell's directed side:

```text
sideSheet ∈ firstEndpoint.cornerWedgeSheets
AND
sideSheet ∈ secondEndpoint.cornerWedgeSheets
```

Both endpoint pairs must pass. Equality of one representative endpoint sheet is not authority.

If a directed side crosses one or more isolation seams away from its endpoints, A6 consumes only the ordered `DirectedSideIsolationEvidence` published by A5 and verifies each named checked M5 certificate exactly. It may not rediscover seam authority from raw boundary paths or scan global certificate inventory.

##### D4 — Seam-collinear sides are supported without a representative face

A segment lying exactly on an isolation seam is not rejected and does not use the lexicographic-triangle tie-break as semantic authority.

For each incident cell, the directed side's **interior source-face authority** is the unique incident source face lying on that cell's interior side of the directed segment, determined by exact source-chart orientation and the cell's canonical cycle. Its sheet is the cell-side sheet.

For two reciprocal ordinary sides collinear with an isolation seam:

1. both directed sides name the same checked `(region, seam-edge)` certificate;
2. their interior-side sheets are the certificate's two distinct incident sheets, in the corresponding orientation;
3. each incident-side sheet belongs to its own endpoint corner-wedge sets; and
4. the certificate, carried by the collinear sides, is the explicit authority for quotient equality across the seam.

Thus disjoint singleton wedge sets on opposite sides of a seam are legal only through this side-carried checked certificate. The ordinary relation itself remains owner-less.

##### D5 — A7 lineage is the union of complete occurrence authority

For a quotient class `Q`:

```text
sourceIsolationSheets(Q) = sorted_unique(union(member.cornerWedgeSheets))
```

A7 records the wedge and directed-side certificate evidence that A6 actually verified while establishing the quotient relation closure. A7 must not pick one member, face, or sheet as representative authority. The former wording “relation certificates establish equivalence” is replaced by “A5-published wedge/side certificates verified by A6 establish every cross-sheet step that requires certification.”

##### D6 — Face-dependent provenance is per wedge/side; no mixed-face occurrence record

The exact `SourceSupport`, `CellId`, `canonicalCornerRole`, `TopologyRegionId`, lattice coordinate, phase, and scale level are occurrence-wide values. Face-dependent values are not occurrence-wide representatives.

A seam-incident occurrence publishes ordered **`CornerWedgeFaceBindings`** for the contiguous faces of its wedge. Each binding carries the source-face topology identity, isolation sheet, exact field-chart binding, and branch rotation for that face. If implementation retains a `LocalLatticeState` object, only face-independent values may remain single-valued there; `sourceChart`/`branchRotation` must be moved or repeated per wedge binding. The semantic record may not combine sheet/support from one face with chart/branch from another.

##### D7 — Row140 compatibility belongs at the adapter; duplicate downstream ownership checks are removed

A5 owns occurrence/relation structural failures in the `Occurrence*` vocabulary. `HardRailOwnerMismatch` becomes externally named **`OccurrenceHardRailOwnerMismatch`**. The legacy row140 string `InvalidHardRailTransport` is preserved only at the transitional M5-compatible adapter boundary that maps the new A5 failure to the accepted legacy failure surface.

The following downstream checks are deleted when CB4 moves their structural responsibility into A5, rather than retained as a second semantic authority:

- `MissingHardRailRelationOwner`;
- the owner-presence/equality half of `InvalidPeriodicRelationOwner`;
- the boundary-kind compatibility half of `IncompatibleAuthoritativeFrontPair` already proven by the A5 relation kind/owner contract.

Downstream checks that validate transport content after the owner has been accepted remain. In particular, route reversal, non-zero periodic shift, checked periodic relation content, and exact transport/application checks are not removed.

##### D8 — CB4/TB4 are re-scoped; the acceptance surface grows by one focused identity

`M6-CP1-CB4` implements D1–D7 and no broader semantic change. The exact new pre-registered focused identity is:

`M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`

It asserts the split-square endpoint occurrences at v0 and v2 each publish `{sheet0,sheet1}` and the expected wedge certificate reference/orientation. The existing six focused identities remain byte-unchanged. Selector449 and routing449 remain byte-frozen.

TB4 therefore executes **7 focused + selector449 = 456 fresh exact-filter processes**. Recovery-green is **456/456 PASS** with immutable postflight and no benchmark. A mechanically valid RED goes directly to `M6-CP1-TB4-REV`; no TB repair or rerun is authorized.

#### 3. Independent worked example — split square

Assumptions independently re-derived from the exact fixture and tracer: uv=xy on `[0,1]^2`, target size `0.5`, cell corner order `BL, BR, TR, TL`, directed side `s` from corner `s` to `s+1`, face 0 `(v0,v1,v2)` below diagonal `(v0,v2)` on sheet 0, face 1 `(v0,v2,v3)` above it on sheet 1.

At a corner, the wedge is traversed from the last positive-length incoming side segment to the first positive-length outgoing side segment through the cell interior. This yields:

| cell | corner 0 | corner 1 | corner 2 | corner 3 |
|---|---|---|---|---|
| `c00=[0,½]^2` | `v0: {0,1}`, cert `e` `1→0` | `(½,0): {0}` | `(½,½): {0,1}`, cert `e` `0→1` | `(0,½): {1}` |
| `c10=[½,1]×[0,½]` | `(½,0): {0}` | `v1: {0}` | `(1,½): {0}` | `(½,½): {0}` |
| `c01=[0,½]×[½,1]` | `(0,½): {1}` | `(½,½): {1}` | `(½,1): {1}` | `v3: {1}` |
| `c11=[½,1]^2` | `(½,½): {0,1}`, cert `e` `1→0` | `(1,½): {0}` | `v2: {0,1}`, cert `e` `0→1` | `(½,1): {1}` |

The orientation follows directly from incoming/outgoing cell sides. For example, `c00.0` arrives along the left side in face/sheet 1 and leaves along the bottom side in face/sheet 0, hence `1→0`; `c00.2` arrives through sheet 0 and leaves through sheet 1, hence `0→1`.

Expected lineage authority is therefore:

- v0: `{c00.0}` with union `{0,1}`;
- center `(½,½)`: `{c00.2,c10.3,c11.0,c01.1}` with union `{0,1}`;
- v2: `{c11.2}` with union `{0,1}`;
- every other lattice vertex: singleton sheet authority.

The four interior reciprocal sides yield eight endpoint pairs. Each non-collinear pair has a unique incident side sheet contained in both endpoint wedge sets. Example: the lower horizontal/vertical adjacency endpoint pair `(c00.2,c10.3)` uses side sheet 0 and `0 ∈ {0,1} ∩ {0}`. The other seven follow identically by the exact cell position: left-of-center uses sheet 1, below/right-of-center uses sheet 0, and above-center uses sheet 1.

##### Interior seam-vertex chain

Let seam edges `e_a=(v_a,v)` and `e_b=(v,v_b)` meet at source vertex `v` and separate sheets `s|t`. Because certificate identity includes the canonical seam-edge key:

- a wedge crossing neither edge has singleton `{s}` or `{t}` and no wedge certificate;
- a wedge crossing only `e_a` has `{s,t}` and exactly certificate `(R,e_a)`;
- a wedge crossing only `e_b` has `{s,t}` and exactly certificate `(R,e_b)`;
- a wedge whose contiguous fan crosses both has `{s,t}` and exactly the sorted pair `{(R,e_a),(R,e_b)}`, with each traversal direction derived from the fan order.

Even when both certificates encode the same unordered sheet pair, the set is unambiguous because `e_a != e_b`. This is the decisive counterexample to a relation-owned “one certificate for the sheet pair” model.

#### 4. Frozen invariants and explicit non-goals

Unchanged: `OccurrenceId=(CellId,canonicalCornerRole)`, `CellId`, `QuotientClassId`, relation-only quotient equality, HardRail/Periodic semantic owners, no geometric welding, selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, existing tests/fixtures, accepted M5 runtime authority, stable accounting **54 / 16 / 38**, debt **1**.

No selector is published or accepted by this turn. No candidate is promoted. No runtime, compile, benchmark, fixture edit, or product/test-source edit is authorized.

#### 5. Successor falsifiers

`M6-DEFN-R1-REV` must reject or amend this definition if independent re-derivation shows any of the following:

1. a corner wedge at source-edge or source-vertex support cannot be derived uniquely from the accepted A4 canonical cycle and exact source topology without choosing a representative face;
2. seam-collinear incident-cell side authority cannot be determined exactly from source-chart orientation and canonical cell interior;
3. the split-square v0/v2 sheet/certificate table is incorrect;
4. A6 would need to search global certificate inventory or infer equality from position/lattice coincidence;
5. the row140 adapter policy weakens an accepted M5 transport/content check rather than removing only duplicated structural ownership checks; or
6. any proposed implementation requires changing selector449/routing449, existing six focused identities, `OccurrenceId`, quotient equality, or HardRail/Periodic owner semantics.

#### 6. Required closeout

| Review/Definition duty | M6-DEFN-R1 disposition |
|---|---|
| Accepted selector prefix re-hashed | selector449 LF SHA-256 `d4a0d1b7…d6414`; selector byte unchanged |
| Decisive claims independently re-derived | exact snapshot `63330339…`; split-square 2×2 geometry, mixed-face occurrence, relation owner shape, materializer seam reconstruction, seam-collinear representative tie-break |
| Non-vacuity checked | v0/v2 single-occurrence completeness gap and interior seam-vertex two-edge example |
| Prior obligations discharged/carried | TB3 addendum A7.1–A7.9 frozen here; stable accounting/debt carried unchanged |
| Stable accounting | **54 / 16 / 38**, debt 1 |
| New candidates/obligations recorded | no runtime candidate; CB4/TB4 re-scope and review falsifiers recorded |
| ORIENTATION currency line | updated to `M6-DEFN-R1`, runtime-free, Review next |
| ORIENTATION §3 / §4 / §7 / §8 | current state/open obligations/successor updated; no accepted runtime authority changed |
| CHANGELOG | agent and root changelogs updated |
| ROADMAP | M6 CP1 Definition interlock and successor updated; checkpoint acceptance unchanged |
| Selector manifest | n/a — no selector added/published/accepted |
| LESSONS | existing Lesson 179 applies; no new lesson |
| Consolidation under CLEAN_UP_POLICY | no destructive consolidation in this Definition turn; current plan retained for `M6-DEFN-R1-REV` to fold/index under standing Review authority |
| Successor frozen | `M6-DEFN-R1-REV` only; CB4 remains held until Review acceptance |
| Turn boundary held | runtime-free documentation/planning only |
| `review_check.py boundary` | **PASS** with declared selector449 SHA; no product/test/fixture/build or selector mutation; durable markers preserved |
| STATUS lifecycle maintained | entry beacon published first; final beacon is reserved as final repository write |
| Pushed to origin, branch in sync | **CONFIRMED.** Drive patch run `36092706709` / apply job `107938329647` / result artifact `10845388776` pushed definition commit `02143b8e1375bfdca939989af6a709f8b17c9468`; workflow reported owner cleanup required and owner-side Drive deletion succeeded. Temporary caller retirement commit `b1bc763ea3b45ccfd358c88f6a97429f15a174ee` preceded cleanup run `36092795885` / cleanup job `107938556572` / result artifact `10846695480`, which pushed cleanup commit `b184b202669c83b58bd6a3730a3d639d88d263b9` and removed both inventoried trigger paths. This closeout record write is repository-native on the target branch; final `STATUS` is the only remaining repository write. |

## `Architecture_M6_DEFN_R2_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R2_Review_Record.md`; moved verbatim.

### M6-DEFN-R2 Independent Review Record

**Turn:** `M6-DEFN-R2-REV`
**Type:** mandatory runtime-free independent Review (review agent)
**Disposition:** **ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-10 / CB4 AUTHORIZED UNDER THE AMENDED PLAN / EXACT NEXT `M6-CP1-CB4`**
**Reviewed definition:** `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md` plus the `M6-DEFN-R2` edits to `Architecture_M6_Frozen_Definitions.md` (commit `6ac2b339`)
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`

#### 1. Evidence re-opened

- **Definition snapshot:** run/artifact `36095854118 / 10847467936` has provider digest and download SHA-256 `a19261e0...75c2`. Its embedded `source.tar.gz` is `c0ca5581...ab1c` with **5,312** files. `RemeshPipeline.cpp`, `SurfaceCellTracing.cpp`, `PureQuadCompletion.h` and `SurfaceCellTransitionQuotientTests.cpp` are byte-identical to `660015f2`, and `git diff 660015f2 342a306e -- src include tests` is empty.
- **Selector/routing and focused tests:** selector449 `d4a0d1b7...d6414` and routing449 `9c88a5ed...c5707` are unchanged. The seventh identity is still absent from `tests/`.
- **Accounting:** stable accounting stays **54 / 16 / 38**, debt 1. This Review creates no runtime event.

#### 2. What is upheld (independently re-derived)

- **B1 carrier.** `CornerWedgeIsolation` is evidence-only and carries ordered `(region, seam, fromSheet, toSheet)` transitions. Every existing equivalence consumer is kind-gated to HardRail/Periodic (`PureQuadCompletion.cpp:801/925/1019/1059`, `RemeshPipeline.cpp:5556/5624`, `SourceAuthoritativeMeshValidator.cpp:680`). Component aggregation guards negative front edges (`RemeshPipeline.cpp:14114/14123`). A `firstFrontEdge = secondFrontEdge = -1` entry is therefore safe, and row5 becomes satisfiable at v0 and v2.
- **B2 rules.** Each face-dependent consumer now has one declared rule: complete binding signatures for class keys, the representative key and `sourceCharts`; relation-side interior-face bindings for selected steps; path start/end from the first/last step. `chartComponent` is constant across an admissible wedge because isolation seams are not chart barriers, so `SelectedRelationStep` components are unchanged.
- **B3 orientation premise, proved in all three builders.**
  - Uniform: `SurfaceCellTracing.cpp:11834-11855` orients against `frame.normal`, which is the reference face's own normal (`build_planar_phase_frame`, `face_normal(vertices, faces, referenceFace)`).
  - Periodic (`:13799-13821`) and bounded-disk (`:16367-16392`) orient against the summed `face_normal` of the corner faces.
  - Source winding is globally consistent (`classify_source_surface_labels` rejects inconsistent winding, `:7388-7391`).

  The winding-selected interior face is therefore sound.
- **B4 split.** A5's relation failures become one-to-one and are mapped at the adapter.
- **P1/P2.** Ordered span evidence and reciprocal-agreement checks are sound.

#### 3. Review amendments (normative; frozen into `Architecture_M6_Frozen_Definitions.md`)

Each amendment closes a gap where a literal CB4 implementation would fail a frozen gate, fail the witness fixture, or reintroduce ambiguity. None needs a new design choice or an unproved premise, so they are frozen here rather than routed to another Definition turn.

**RA-1 — boundary and region-boundary edges.** R2 §5.2 is written only for "an internal manifold source edge; require exactly two incident source faces". All eight perimeter sides of the split square are collinear with **source boundary edges** that have one incident face. Taken literally, the rule fails closed on the witness fixture.

*Amendment:* for a collinear span on
- an internal edge, the interior face is the incident face whose source winding contains the side's directed edge;
- a source boundary edge, the interior face is the single incident face, which must satisfy the same winding test;
- a hard-rail or topology-region-boundary edge, the interior face is the winding-selected incident face, which must also lie in the cell's `TopologyRegionId`.

Any failed test is a typed A5 failure.

**RA-2 — P3 must not key on vertex category.** In the codebase's own vocabulary, "excluded source vertices" means barrier vertices. `GlobalTopologyPlan.cpp:2343-2344` computes `total − interior`; on the produced torus that is 72 − 55 = **17** = 6 + 12 − 1 rail vertices, and rail vertices are lattice nodes there. A P3 keyed on "singular/excluded" vertices would fail the torus rows (444, 446, 448 and focused row6).

*Amendment:* `OccurrenceUnsupportedSingularWedge` fires only when the winding-order fan arc (RA-8) cannot be computed. That means a nonmanifold vertex fan, or an arc that is not contained in one `TopologyRegionId` and one chart component. It never fires because a vertex is on a boundary, barrier or hard rail. `OccurrenceUnsupportedSingularityPort` fires only for an A4 corner that participates in a SingularityPort relation; A5 currently produces none.

**RA-3 — P4 predicate.** "Unresolved seam-at-hard-rail corner" is undefined. *Amendment:* `OccurrenceUnsupportedHardRailSeamWedge` is exactly the case where the RA-8 arc would have to cross a hard-rail edge to connect the incoming and outgoing interior faces. For a validated cell this is unreachable, so it is a fail-closed assertion. A seam edge that ends at a rail vertex inside an admissible arc is ordinary wedge evidence.

**RA-4 — "structural hash" in the seventh identity.** `hash_completion` hashes `SurfacePoint::face` (a source-face row; `hash_surface_point`, `RemeshPipeline.cpp:1913-1923`, applied at `:2655/:2683`) and equivalence front-edge indices (`:2711-2712`). It is not invariant to face-row permutation, so asserting that it is invariant fails by construction.

*Amendment:* the permutation clause compares only row-invariant semantic data:
- `OccurrenceId`s;
- per-`OccurrenceId` `CornerWedgeSheetSet` and ordered `CornerWedgeIsolation` transition tuples;
- per class (keyed by sorted member `OccurrenceId`s): lineage `sourceIsolationSheets` and the `CornerWedgeIsolation` transition tuples.

CB4 may add **one test-local split-square fixture helper with reversed face rows**, sheet labels permuted with the rows, used only by the seventh identity. Existing fixtures stay byte-unchanged.

**RA-5 — the `OccurrenceUnownedRelation` name, and frozen focused row3.**
- R2 §6 maps `OccurrenceUnownedRelation → "UnownedRelation"`, but no such M5 string exists (accepted `e284fea7` has none). The current external name is `OccurrenceUnownedRelation` (`RemeshPipeline.cpp:3051`, `:4099`). *Amendment:* keep `OccurrenceUnownedRelation` as its external name; there is no legacy remap.
- Frozen focused row3 (not covered by the R2 audit) pins enum `UnownedRelation` for a malformed relation identity: `id.first` rewritten, detected by `relation.id != expectedId` at `:3190` (test at `SurfaceCellTransitionQuotientTests.cpp:2092-2103`). *Amendment:* the enum member `UnownedRelation` is kept. It continues to cover relation-identity/owner-encoding mismatch in `publish_records_for_validation`. The new owner/kind codes apply only to the producer-side conditions R2 §6 names. The out-of-range opposite edge becomes `RelationEndpointMissing`.

**RA-6 — lineage sheets are the wedge union only.** R2 §4.5 says `sourceIsolationSheets` is derived from binding tuples "plus already-verified side/wedge transitions". Frozen §5 says it is the union of member `CornerWedgeSheetSet`s. The two disagree whenever a side crosses a seam mid-span: that side's `fromSheet`/`toSheet` would widen the lineage of endpoint vertices whose own wedges are single-sheet.

*Amendment:* frozen §5 governs. Side transitions are `equivalences` evidence only and add no sheets.

**RA-7 — retire the M5 endpoint-equality guard explicitly.** The transitional `crossesSheets` guard (`RemeshPipeline.cpp:4180-4191`) compares single occurrence sheets. It must be removed and replaced by the RA/R2 span-membership validation, not adapted to a representative sheet.

Under R2's own B4 principle, the A6 failure that replaces it maps at the adapter to the legacy name it supersedes:
- missing seam evidence for a cross-sheet step → `MissingIsolationSeamEquivalenceAuthority`;
- a named certificate absent or wrong → `InvalidIsolationSeamEquivalenceAuthority`;
- reciprocal disagreement (`QuotientReciprocalSideAuthorityMismatch`) keeps its new name. It has no M5 predecessor.

**RA-8 — wedge fan endpoints and direction.** Frozen §3.2 still says the wedge spans "between the last positive-length incoming side segment and first positive-length outgoing side segment".

*Amendment:* the arc endpoints are the **interior faces** of the incoming side's last support span and the outgoing side's first support span. For a collinear span that face comes from RA-1; otherwise it is the face containing the span's open interior. The arc runs in source-winding (counter-clockwise) order from the outgoing interior face to the incoming interior face around the corner support, which is the side containing the cell interior for a validated cell. The recorded transition orientation stays incoming → outgoing as in the DEFN-R1 table (v0 `1→0`, v2 `0→1`).

**RA-9 — "exact" support is resolver-defined.** Span and occurrence supports are resolved by `SurfacePointSourceSupportResolver`, with default barycentric tolerance `1e-8` (`SurfacePointSupport.h`). R2's "no tolerance participates" is inaccurate. *Amendment:* the support-span rule is defined **by that resolver, applied to each span's open-interior midpoint and both endpoints**. The span is edge-collinear iff all three resolve to the same `SourceEdgeSupport`, or the endpoints resolve to that edge's closure. The builder's own tie-break tolerance is irrelevant.

**RA-10 — the transitional `QuotientClassId` stays as it is in CB4.** The semantic `QuotientClassId` is the sorted member set (frozen §4.3). CB4 keeps today's transitional ordinal in `lineage.quotientClass`, and in its hash, unchanged in representation. Only the class-key tuple feeding the ordinal changes (complete binding signatures). Realizing the member-set identity as a product type belongs to A6 extraction, not CB4.

**Accuracy note (no amendment).** R2 §8 says row444's selected certificate is "unchanged signature/hash". Relation-local `startChart` changes certificate content relative to M5. Rows 444/448 compare within one candidate, so they remain satisfiable, but the certificate is not byte-identical to M5.

#### 4. Frozen-test audit extension

The R2 audit omitted focused rows 1-4.
- Row 1 (four semantic corners, square fixture) and row 4 (coincident unrelated occurrences, overlap fixture) assert only identity, count and distinctness. Wedge sets are singletons on those fixtures, so both stay satisfiable.
- Row 2 compares semantic IDs only, so it stays satisfiable.
- Row 3 stays satisfiable only under RA-5.

With RA-1 – RA-10 the audit covers all seven focused identities and selector rows 140, 186, 214, 239, 444, 446 and 448.

#### 5. Successor

Exact next: runtime-free **`M6-CP1-CB4`**, under the amended CB4 plan authority now folded into `M6_Consolidated_Record.md` §§12-18. Compile-green → immutable `M6-CP1-TB4-EXEC` (7 + 449 = **456**) → mandatory `M6-CP1-TB4-REV`.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...c5707` |
| Decisive claims independently re-derived | snapshot `10847467936` digest/archive/5,312 files and byte-identity to `660015f2`; kind-gated consumers and front-edge guards; orientation premise in all three builders; row3 malformed-ID path; `hash_completion` row dependence; excluded-vertex semantics (72 − 55 = 17 rail vertices); resolver tolerance; absence of an M5 `"UnownedRelation"` string |
| Non-vacuity checked | RA-1 (8 perimeter sides), RA-2 (torus rail nodes), RA-4 (face-row hash) and RA-5 (row3) each name a frozen gate that a literal implementation would fail |
| Prior obligations discharged/carried | DEFN-R1-REV B1-B4 and P1-P4: discharged by R2 as amended by RA-1 – RA-10 |
| Stable accounting | **54 / 16 / 38**, debt 1; +0 |
| New candidates/obligations recorded | RA-1 – RA-10 frozen; CB4 plan amended; tracker +0 entry |
| ORIENTATION currency line | `M6-DEFN-R2-REV`, 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 updated; §4 n/a |
| CHANGELOG | root and Directional prepended |
| ROADMAP | status line and M6-CP1 row updated |
| Selector manifest | n/a |
| LESSONS | existing 179/180 apply; no new lesson |
| Consolidation under CLEAN_UP_POLICY | consumed `Architecture_M6_DEFN_R2_Amendment_Plan.md` folded into `M6_Consolidated_Record.md` and removed; DEFN-R1/R2 records and the DEFN-R1 review retained as the definition chain; CB4 plan is the single live successor plan |
| Successor frozen | exactly `M6-CP1-CB4` (amended) |
| Turn boundary held | runtime-free; no source/test/fixture/selector/benchmark/build mutation; no compile or Directional runtime |
| review_check.py boundary / ledgers | recorded in the review commit message |
| `STATUS` lifecycle maintained | entry `M6-DEFN-R2-REV / IN_PROGRESS` (operator handoff `2026-09-25T05:33:36Z`) → docs → COMPLETE last |
| Pushed to origin, branch in sync | verified after the final push |

## `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`; moved verbatim.

### M6-DEFN-R2 — Seam-Incident Authority Amendment Definition Record

**Turn:** `M6-DEFN-R2`
**Type:** Definition amendment / runtime-free
**Predecessor:** `M6-DEFN-R1-REV`
**Mandatory successor:** `M6-DEFN-R2-REV`
**Implementation successor if and only if Review accepts:** re-scoped `M6-CP1-CB4`
**Status:** COMPLETE / RUNTIME-FREE / B1-B4 and P1-P4 frozen for independent Review / CB4 HELD
**Date:** 2026-09-25

#### 1. Scope and unchanged authority

This turn resolves only the four blockers and four precision items raised by `Architecture_M6_DEFN_R1_Review_Record.md`. It changes no product source, tests, fixtures, selectors, benchmarks, or build source and executes no generated Directional runtime or compile.

The following DEFN-R1 decisions remain unchanged:

- `OccurrenceId=(CellId, canonicalCornerRole)`;
- `CornerWedgeSheetSet` is the complete sheet set of the contiguous cell-interior source-face fan;
- wedge and side isolation evidence is keyed by the checked `(TopologyRegionId, SourceEdgeTopologyKey)` certificate actually crossed or followed;
- `OrdinaryFront` remains owner-less;
- HardRail and Periodic semantic owners remain unchanged;
- A6 quotient equality is relation-only and never follows coordinate or world-space coincidence;
- A7 lineage is the union of complete member authority rather than a representative sheet;
- no mixed-face occurrence record is permitted;
- accepted M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` and selector449 remain immutable.

Stable accounting remains **54 events / 16 categories / 38 recurrences**, produced-witness debt **1**, +0.

#### 2. Independently re-derived source facts

The exact snapshot used for this Definition is GitHub Actions run/artifact `36095854118 / 10847467936`, event/source SHA `342a306ebd3ba68cb6e1135cf9e25726bd8ad461`, provider SHA-256 `a19261e06e11293b9240b8a44c24f95042190df1d7154ba330c5e677fb9875c2`, embedded archive SHA-256 `c0ca5581851b76b1a169cdffb4c3b7243070d54225f176e6510ce909b152ab1c`, 5,312 files / 97,885,751 bytes, `runtimeExecution=false`. All decisive static conclusions below were re-derived from those bytes.

The source establishes all of the following:

1. `PureQuadVertexLineage::equivalences` is the frozen focused-row carrier that row5 already requires to be non-empty for every multi-sheet lineage. Existing equivalence consumers branch only on HardRail or Periodic where they need owner/path semantics; a third isolation-evidence kind can therefore be decision-neutral to those consumers when it does not impersonate either owner.
2. Transitional A6 currently collapses each occurrence to one `isolationSheet` and one `chart`, uses them in `QuotientDomainState` and `representative_key`, and selects path chart components from those occurrence-wide values. That is incompatible with the now-frozen multi-face `CornerWedgeFaceBindings` model.
3. All three side builders can tie-break a segment that lies on a source edge: `segment_on_source`, `periodic_chart_segment`, and `bounded_disk_chart_segment`. All three accepted cell paths normalize their canonical cell cycle orientation against source orientation before `orientationValidated=true`; source-chart adjacency also requires reciprocal source-edge winding. Therefore the cell-interior incident face can be selected topologically after A4 acceptance without relying on the builder's chosen representative face.
4. Current A5 `UnownedRelation` is many-to-one: it covers missing HardRail ownership, Periodic ownership problems, kind incompatibility, and genuinely owner-less structural cases. That conflicts with the frozen M5 typed failure surface.

#### 3. A1/B1 — wedge evidence is a first-class lineage equivalence

##### 3.1 New equivalence kind

M6 freezes a new lineage-equivalence kind:

```text
PureQuadEquivalenceKind::CornerWedgeIsolation
```

It is evidence that one materialized quotient vertex legitimately spans more than one isolation sheet because the accepted A5 wedge/side authority crosses or follows one or more checked isolation seams. It is **not** an A5 `ownedRelation`, does not create quotient equality, and does not acquire a HardRail or Periodic owner.

The authoritative payload is an ordered list of exact transitions:

```text
PureQuadIsolationTransition
  TopologyRegionId region
  SourceEdgeTopologyKey seam
  IsolationSheetId fromSheet
  IsolationSheetId toSheet
```

The implementation may use equivalent field names, but it must preserve this exact semantic tuple and order. For a `CornerWedgeIsolation` equivalence:

- `firstFrontEdge = secondFrontEdge = -1`;
- HardRail and Periodic owner fields are unset;
- transport/action is identity unless a future Definition explicitly gives this evidence transport semantics;
- route/cut-route fields are empty;
- `isolationTransitions` is non-empty;
- each transition names exactly one already-checked `(region,seam)` certificate and its traversal-oriented sheet pair.

The pre-existing `isolationSeams` field may remain as a compatibility projection while CB4 is transitional, but the ordered transition tuple is semantic authority for the new kind. A compatibility projection must be derived from the semantic list and cannot replace it.

##### 3.2 Construction and deduplication

For each quotient class A7/materialization projects the union of every member occurrence's `CornerWedgeIsolationEvidence` and every member directed-side isolation evidence that the accepted quotient relation certificate actually verified. Equal semantic evidence is deduplicated by the full ordered transition sequence, not by source-face row, front-edge index, or hash.

This equivalence is lineage evidence only. It must not be inserted into `selectedRelationPaths`, must not alter relation selection, and must not cause a previously unused HardRail/Periodic relation to become selected.

##### 3.3 Split-square consequence

For the accepted two-triangle split-square analytic witness:

- v0: one occurrence class, `sourceIsolationSheets={0,1}`, and at least one non-empty `CornerWedgeIsolation` equivalence carrying the exact seam transition `1 -> 0` in that corner-wedge traversal;
- center: four occurrence members collectively span `{0,1}` and materialize non-empty corner/side isolation lineage evidence from the same checked seam authority;
- v2: one occurrence class, `sourceIsolationSheets={0,1}`, and at least one non-empty `CornerWedgeIsolation` equivalence carrying `0 -> 1` in its corner-wedge traversal;
- every other materialized lattice vertex remains single-sheet unless independent typed evidence says otherwise.

This makes focused row5 satisfiable without inventing a relation between the relation-free v0/v2 occurrences.

#### 4. A2/B2 — per-consumer face binding

##### 4.1 Canonical occurrence binding signature

Every occurrence publishes the complete canonical ordered binding signature derived from its wedge:

```text
(sourceFaceTopology,
 IsolationSheetId,
 SourceProjectionChart,
 branchRotation)
```

plus its face-independent lattice coordinate/phase/scale provenance. No A6/A7 consumer may select one representative sheet/chart and use it as semantic authority for the whole occurrence.

All bindings within one admissible corner wedge must resolve to one `SourceChartTransitionGraph` component. A wedge never crosses a hard-rail or topology-region boundary. If this invariant cannot be established, A5 fails closed; it is not repaired by choosing a different binding.

##### 4.2 Transitional class/domain key

The semantic `QuotientClassId` remains the canonical sorted non-empty member-`OccurrenceId` set. Any transitional integer class row is adapter-local only.

A transitional `QuotientDomainState`/class key used to detect duplicate or incompatible occurrence authority must include the member's **complete canonical binding signature** rather than one scalar sheet/chart. It may also include the already-frozen face-independent lattice/scale provenance and exact source support. Two different complete binding signatures must never compare equal merely because one selected binding matches.

##### 4.3 Representative key

Geometric representative selection is representation-only. Its deterministic key must include exact source support/geometry and the complete binding signature, with `OccurrenceId` as a semantic final discriminator. `point.face` may be used only as a final lookup/storage tie-break after semantic support and binding equality are already established. Representative selection does not define quotient membership, sheet authority, or chart authority.

##### 4.4 Relation-local chart selection

For every selected HardRail or Periodic relation step, the endpoint chart is the binding attached to the **relation-side interior source face at that endpoint**. `SelectedRelationStep.fromChartComponent` and `.toChartComponent` are derived from those relation-local bindings.

`SelectedRelationPathCertificate.startChart/endChart` likewise come from the first/last selected relation step, not from a quotient representative's arbitrary face. Multi-step path continuity is checked in chart-component authority; each exact step retains its own relation-local source chart.

OrdinaryFront requires no selected relation-path certificate merely because a wedge carries `CornerWedgeIsolation` evidence.

##### 4.5 A7 lineage projections and component remap

`PureQuadVertexLineage::sourceCharts` is the sorted unique union of **all** member `CornerWedgeFaceBinding.chart` values. `sourceIsolationSheets` and `sourceTopologyRegions` are projections of the same exact binding tuples plus already-verified side/wedge transitions; they are not independently chosen sets.

Component remapping must remap the full binding tuples and `PureQuadIsolationTransition` tuples first and only then derive legacy region/sheet/chart vectors. Validation against independent set membership or a region×sheet cross-product is insufficient because it loses the exact binding association.

#### 5. A3/B3 — exact collinearity and cell-interior incident face

##### 5.1 Exact support-span rule

A directed side is partitioned, in side traversal order, into maximal positive-length spans of exact `SourceSupport`. A span is source-edge-collinear if and only if its open interior support is exactly that `SourceEdgeSupport`. No tolerance, angle test, builder-selected representative face, source-face row, or lexicographic triangle order participates.

A partly collinear side is classified locally per span. In particular, the near-endpoint positive-length span determines whether that endpoint pair uses the ordinary non-collinear rule or the seam-collinear rule.

##### 5.2 Interior-face rule

For an accepted A4 `orientationValidated` cell and an internal manifold source edge:

1. require exactly two incident source faces and reciprocal source-edge winding;
2. inspect the directed source-edge orientation induced by the canonical accepted cell side;
3. select the unique incident source face whose source-triangle winding places that face on the cell-interior side of the directed edge;
4. derive the side's sheet/chart/branch binding from that face;
5. fail closed if the incident faces, winding, owning region, or unique selection is inconsistent.

This is a topological exact decision after A4 acceptance. It does not require a new A4 product field.

##### 5.3 Why the premise holds for all three builders

The source audit proves the premise independently for all active builders:

- uniform cells: `orient_and_validate_phase_front_cell` reverses the corner order when needed and requires the resulting loop normal to agree with the source frame normal before setting `orientationValidated`;
- periodic chart cells: the builder computes an expected source normal from the corner source faces, reverses on negative agreement, requires positive agreement, and only then validates region ownership and publishes `orientationValidated`;
- bounded-disk chart cells: the same canonical-loop/source-normal rule is applied, and every source-chart triangle is independently required to have positive signed chart area in source face vertex order;
- source-chart transitions require the two source faces incident on a manifold edge to have opposite winding along that edge.

Therefore one exact A5 interior-face rule can replace all three builder-local tie-break faces for seam-collinear authority.

#### 6. A4/B4 — one-to-one A5 failure vocabulary and adapter map

A5 freezes these distinct relation failures:

| A5 semantic failure | Transitional legacy M5-compatible name | Meaning |
|---|---|---|
| `OccurrenceHardRailOwnerMissing` | `MissingHardRailRelationOwner` | HardRail relation requires an owner but none is present. |
| `OccurrenceHardRailOwnerMismatch` | `InvalidHardRailTransport` | reciprocal HardRail endpoints disagree on the exact accepted owner/transport authority. |
| `OccurrencePeriodicOwnerMismatch` | `InvalidPeriodicRelationOwner` | Periodic endpoints have missing, conflicting, or incompatible periodic owner authority. |
| `OccurrenceRelationKindMismatch` | `IncompatibleAuthoritativeFrontPair` | reciprocal boundary/relation kinds are not the same accepted kind. |
| `OccurrenceUnownedRelation` | `UnownedRelation` | only a genuinely owner-less/structurally unowned relation case not covered above. |

A relation endpoint index/range defect remains a structural endpoint/cycle failure and must not be collapsed into `OccurrenceUnownedRelation`.

The compatibility adapter owns this mapping. It is the only place where the M6 name becomes the frozen legacy diagnostic name.

After A5 certifies the corresponding invariant, the transitional materializer may delete only duplicate structural branches whose entire predicate is already proved by A5:

- HardRail owner presence and exact owner equality;
- Periodic owner presence/equality compatibility;
- reciprocal relation-kind compatibility.

It must retain relation route reversal/content checks, periodic nonzero shift checks, exact relation values, exact transport application, source-support checks, and every other M5 semantic falsifier. Thus §4.6 remains literal: an accepted M5 failure cannot become success or an unrelated generic failure merely because A5 now owns structural validation earlier.

#### 7. Precision rules P1-P4

##### P1 — ordered evidence for multi-edge and partial-collinear sides

`DirectedSideIsolationEvidence` is an ordered list in directed-side traversal order. Each maximal positive-length seam-edge span contributes the exact checked `(region,seam,fromSheet,toSheet)` transition for that span. Repeated geometry does not collapse distinct ordered spans. Reciprocal side evidence must be the reverse-compatible list with every transition direction inverted.

##### P2 — reciprocal near-endpoint agreement

For reciprocal OrdinaryFront sides:

- if the near-endpoint positive-length span is not seam-collinear, the two records must agree on the mapped interior sheet authority and that sheet must be a member of both endpoint wedge sets;
- if it is seam-collinear, both records must name the same exact seam certificate/span, the two selected interior faces must be the two incident source faces, and their sheets must be the certificate's opposite incident sheets;
- ordered side-evidence lists must be reciprocal reverses.

Violation is typed A6 failure `QuotientReciprocalSideAuthorityMismatch`.

##### P3 — excluded singular/nonmanifold corner classes

CP1 does not invent a corner wedge when the source fan is nonmanifold, singular/excluded such that no unique contiguous cell-interior wedge exists, or the relation corner is a `SingularityPort`. A5 fails closed with:

- `OccurrenceUnsupportedSingularWedge`; or
- `OccurrenceUnsupportedSingularityPort`.

No representative-face or global-search fallback is allowed.

##### P4 — region/hard-rail boundary law

A `CornerWedgeFaceBinding` sequence is confined to one `TopologyRegionId` and stops at source boundary, topology-region boundary, or hard rail. A hard-rail-adjacent corner with no internal isolation seam inside its admissible wedge remains **single-sheet**. If satisfying the requested wedge would require crossing a hard rail, or if CP1 encounters an unresolved seam-at-hard-rail corner whose authority is not uniquely inside one admissible wedge, A5 fails `OccurrenceUnsupportedHardRailSeamWedge` rather than broadening the sheet set.

This explicitly preserves the accepted HardRail single-sheet assertions in Phase10.

#### 8. Frozen-test compatibility audit

No test is changed by this Definition. The source audit establishes satisfiability of the relevant frozen assertions under the amended semantics:

| Surface | Result under R2 |
|---|---|
| Focused row5 `MultiIsolationMaterializationRetainsAllLocalSheets` | Satisfiable: v0/v2 are `{0,1}` and now have non-empty `CornerWedgeIsolation` equivalence evidence; center remains multi-sheet with lineage evidence. |
| Focused row6 `ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | Unchanged: the new isolation equivalence is not a selected Periodic path and relation-local bindings preserve semantic Forward/Reverse authority. |
| Selector 186 `ReciprocalIsolationSeamCertificateMaterializes` | Unchanged certificate owner/count; R2 only projects the same checked certificate into lineage. |
| Selector 214 component-typed lineage authority | Satisfiable and stronger: full binding tuples are remapped before legacy region/sheet/chart projections. |
| Selector 239 `ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam` | Unchanged producer certificate, distinct sheets, reciprocal transport and exact consumed-seam count. |
| Selector 444 Periodic relation storage permutation | Unchanged selected-certificate signature/hash: selection is relation-local and may not search alternatives. |
| Selector 446 nonzero periodic materialization | Unchanged Periodic owner/action/transport semantics. |
| Selector 448 unused valid relation | Strengthened: `CornerWedgeIsolation` is lineage-only and cannot select an otherwise unused relation. |
| Phase10 HardRail single-sheet assertions | Preserved by P4; no hard rail becomes an isolation-wedge crossing. |

Selector449 and its routing receipt bytes are untouched.

#### 9. CB4/TB4 authorization shape

`M6-CP1-CB4` was re-scoped by the now-folded CB4 plan authority preserved in `M6_Consolidated_Record.md` §§12-18 and remained **HELD** until independent `M6-DEFN-R2-REV` accepted this Definition.

The seventh focused identity is still:

`M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`

but its acceptance surface is strengthened. It must materialize the split-square fixture and prove:

1. v0 lineage is `{0,1}` with non-empty exact `CornerWedgeIsolation` evidence and expected transition orientation;
2. center lineage is `{0,1}` with non-empty exact isolation evidence;
3. v2 lineage is `{0,1}` with non-empty exact `CornerWedgeIsolation` evidence and reverse transition orientation;
4. all remaining lattice vertices are single-sheet;
5. no `CornerWedgeIsolation` entry appears in `selectedRelationPaths` or alters HardRail/Periodic selection;
6. source-face-row permutation preserves the semantic identities and structural hashes.

TB4 remains exactly **7 focused + selector449 = 456 fresh exact-filter processes** if and only if CB4 compiles and Review has accepted this Definition. No selector row is added or changed.

#### 10. Process observation

`M6-DEFN-OBS-01` recurred: several small repository documents were opened before the turn explicitly froze `READ_MODE=snapshot`. The turn stopped piecemeal inspection, acquired the exact snapshot above, and re-derived every decisive semantic conclusion from that verified snapshot. This is the already-known process recurrence; it adds no stable event, category, lesson, or debt.

#### 11. Closeout

| Check | Result |
|---|---|
| B1 lineage evidence carrier | PASS — `CornerWedgeIsolation` + ordered exact transition tuple frozen |
| B2 binding selection | PASS — complete binding signature and per-consumer relation-local rules frozen |
| B3 exact side rule | PASS — support-span + unique cell-interior incident face frozen; all three orientation premises proved statically |
| B4 failure compatibility | PASS — 1:1 A5 vocabulary and adapter mapping frozen; semantic M5 checks retained |
| P1-P4 | PASS — ordered spans, reciprocal agreement, excluded corner classes, hard-rail/region law frozen |
| Frozen-test audit | PASS statically — rows 5/6, 186/214/239/444/446/448 and HardRail single-sheet assertions remain satisfiable without test changes |
| Selector/routing bytes | UNCHANGED |
| Product/test/fixture/build source | UNCHANGED |
| Runtime / compile | NOT EXECUTED by Definition boundary |
| Stable accounting | UNCHANGED: **54 / 16 / 38**, debt 1 |
| Implementation authorization | HELD pending `M6-DEFN-R2-REV` |

**Exact successor:** mandatory runtime-free **`M6-DEFN-R2-REV`**. Do not start CB4 in this turn.

## `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md`; moved verbatim.

### M6-DEFN-R3 — A6 quotient-product separation definition record

**Turn:** `M6-DEFN-R3`
**Type:** runtime-free Definition amendment
**Predecessor:** `M6-CP1-TB5-REV` review-agent addendum
**Review:** `M6-DEFN-R3-REV` COMPLETE / ACCEPTED WITH RA-1 – RA-4
**Exact next implementation:** `M6-CP1-CB6-A6`
**Reviewed runtime entering the turn:** package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 `449/449`
**Stable accounting:** `55 / 16 / 39`, produced-witness debt `1`

> **Reviewed by `M6-DEFN-R3-REV`: ACCEPTED WITH RA-1 – RA-4.** The historical R3 text below is preserved, but the Review amendments in `Architecture_M6_DEFN_R3_Review_Record.md` and the appended `M6-DEFN-R3-REV` amendment in `Architecture_M6_Frozen_Definitions.md` govern conflicts. In particular: canonical certificate direction is `relation.id.first -> relation.id.second`; every accepted OrdinaryFront quotient transport is identity; A5 relations must carry evidence sufficient for A6 HardRail/Periodic canonical transport without representation lookup; and selected-path `GridAutomorphism` composition order is explicit. Exact next is `M6-CP1-CB6-A6`.

#### 1. Scope and evidence boundary

This record decides only the bounded recovery scope in `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md` §5: the CP1 exit checklist, A6 class identity, exact-once relation ledger including cycle-closing relations, selected-path ownership, A6 failure vocabulary, the first A6 Code + Build plan, and its frozen-test audit. A7 representation and the `G4-B002` stage-boundary representation are intentionally deferred to `M6-DEFN-R4`; §8 records intent only.

No Directional executable, test, benchmark, configure, compile, relink, fixture, selector, or routing mutation is part of this Definition turn. The exact source snapshot used for cross-file inspection is workflow run/artifact `36199074014 / 10890838063`; snapshot commit `fbbb4cac835887b60aa5fc22083cc6d068ee886c` differs from the semantic entry head `c4d046289276f6b4ecc496ae41c697e0a7852d16` only by the source-snapshot trigger marker. The snapshot manifest verifies 5,317/5,317 files; embedded archive SHA-256 is `b850d7a3166c78d4cc9813685af2ce8901b3cb391d46da4e647aa8d2be7b6ca3` and records `runtimeExecution=false`.

#### 2. CP1 exit checklist — normative confirmation

CP1 closes only after exact source plus a fresh accepted gate prove all of the following together:

1. **A5:** conformant immutable `SurfaceOccurrenceComplex`; unread representative fields `SurfaceOccurrence::{chart,lattice,isolationSheet}` are retired while live `point`, `chartComponent`, complete wedge bindings, placement provenance and isolation evidence remain.
2. **A6:** immutable `SurfaceQuotientProduct` exists with member-set semantic class identity, one relation certificate and one consumption row for every A5-owned relation, deterministic selected-path evidence, `QuotientCertificate`, and `MaterializationCertificate`.
3. **A7:** immutable `SourceAttachedGeometryProduct` and its source-support/embedding certificates exist. Representation details are deferred to `M6-DEFN-R4`.
4. **Thin adapter:** `build_authoritative_phase_front_mesh(...)` makes no semantic occurrence, quotient, relation-selection, or embedding decision; it only projects immutable stage products into compatibility/output surfaces.
5. **No weld:** coordinate, lattice, point, output-row, scheduler, representative-sheet, hash, or cache equality never creates occurrence/class equality.
6. **`G4-B002` boundary:** a closed-complex view is derived from A6 without `SurfaceCellPipelineContext::hasArrangement`; its exact representation is deferred to `M6-DEFN-R4` and CP3 still owns direct-production re-proof.
7. **Preservation:** focused multi-isolation remains green and selector449 is re-executed fresh at 449/449 after the A6/A7 cutovers.

The previous statement that CP1 was one standalone legacy-field cleanup away from closure is superseded.

#### 3. A6 semantic class identity

##### 3.1 New semantic ID type

A6 introduces `pipeline::SurfaceQuotientClassId`. Its complete semantic value is:

```text
SurfaceQuotientClassId := sorted_unique_nonempty_vector<authority::OccurrenceId>
```

Rules:

- equality is exact member-set equality;
- ordering is lexicographic over the sorted `OccurrenceId` sequence;
- the producer constructs it only after all accepted A5-owned relations have been verified and consumed;
- a validation/publication seam rejects empty, unsorted, duplicate-member, missing-member, or overlapping-class definitions rather than silently normalizing malformed test input;
- no hash, union-find root, storage ordinal, `SourceSupport`, lattice state, source chart, output row, position, representative occurrence, or transport is part of semantic identity.

This is the concrete realization of frozen §4.3.

##### 3.2 Transitional ordinal remains adapter-only

`authority::QuotientClassId` remains a compatibility/output ordinal only. It is not stored as A6 semantic identity. During the transitional adapter, A6 classes are sorted by `SurfaceQuotientClassId`; ordinal rows `0..N-1` are assigned in that order and projected to `PureQuadVertexLineage::quotientClass`.

This satisfies RA-10 without preserving the old class-key-derived ordinal as authority. Existing frozen tests do not pin a numeric quotient ordinal. The storage-permutation test compares `(ordinal, sourceOccurrences)` only between equivalent executions, and hash assertions compare invariance rather than a hard-coded hash; lexicographic member-set ordering remains satisfiable under those tests.

#### 4. Exact-once relation certificates and ledger

##### 4.1 Canonical relation processing

A6 consumes only `SurfaceOccurrenceComplex::owned_relations()`. Before consumption it sorts by semantic `SurfaceOccurrenceRelationId`; source vector order and `firstFrontEdge` / `secondFrontEdge` are representation handles and cannot determine product semantics.

Every owned relation produces exactly one immutable `QuotientRelationCertificate` and exactly one immutable `QuotientRelationConsumption` row. A relation may never disappear merely because union-find reports that its endpoints are already in the same class.

The certificate is oriented from `relation.firstOccurrence` to `relation.secondOccurrence` and records:

- exact `SurfaceOccurrenceRelationId` and endpoint IDs;
- relation kind;
- the kind-specific authority/evidence that verified it;
- one exact `authority::GridAutomorphism relationTransport` in that orientation.

Transport mapping is frozen as:

- ordinary non-seam relation: identity;
- ordinary relation crossing a checked isolation seam: the checked reciprocal seam quarter-turn lifted to a zero-translation `GridAutomorphism` in the certificate orientation;
- HardRail: the current exact selected HardRail transport in relation orientation;
- Periodic: the current semantic periodic action (or exact inverse) in relation orientation;
- SingularityPort: unsupported by the current accepted A5 contract and typed-fail if it reaches A6 through a validation seam.

The row has exactly one disposition:

```text
Joining
CycleClosing
```

`Joining` means the endpoints were in different quotient components when that canonical relation was consumed. `CycleClosing` means they were already connected by earlier canonical joining relations. Both are complete consumption; both receive a certificate and row.

##### 4.2 Deterministic selected forest and cycle rule

Joining rows form the A6 **selected relation forest**. Every forest edge stores its relation-certificate identity and orientation; ordinary identity edges are retained even when they have no downstream legacy selected-path projection.

For a cycle-closing relation `(a -> b)` there is one unique forest path from `a` to `b`. A6 composes the path transport in traversal order, using the exact inverse of a certificate transport whenever the path traverses that certificate opposite its stored orientation.

The frozen acceptance rule is exact:

```text
relationTransport == compose(selectedForestPath(a -> b))
```

If not, A6 fails `QuotientHolonomyConflict`. Equivalently, the closed loop formed by the new relation and the existing path has identity residual. The direct relation/path transports may themselves be non-identity; the rule is consistency, not "all periodic actions must be identity".

##### 4.3 Exact-once invariants

`QuotientCertificate` must prove:

- certificate count == A5-owned relation count;
- consumption-row count == A5-owned relation count;
- relation IDs are a bijection across A5 ownership, relation certificates, and consumption rows;
- no unowned relation participates in partition, forest, path, classed topology, or lineage projection;
- every joining row appears once in the selected forest;
- every cycle-closing row has an exact path-consistency result;
- the class partition is exactly the transitive closure of the certified owned relations.

A validation/publication seam exists only for focused negative tests; production construction never fabricates missing/duplicate/conflicting ledger state.

#### 5. Analytical holonomy proof and produced-fixture falsifier

This Definition turn runs no producer. The rule in §4.2 is therefore proved only where it follows from frozen fixture geometry/field construction without executing Directional.

##### 5.1 Split square

The split-square fixture is two coplanar triangles of the unit square with the same constant XY 4-RoSy field and constant target size; only the source-sheet labels differ across the diagonal. Ordinary non-seam relations have identity transport. The isolation-seam relation uses the reciprocal seam quarter-turn; because the two triangles are coplanar and the constant field has the same tangent orientation on both sides, its exact quarter-turn is zero, so its lifted `GridAutomorphism` is identity. Therefore every possible forest path and every cycle-closing direct relation in this fixture compose to identity, satisfying §4.2.

##### 5.2 Uniform hard-rail rectangle

The hard-rail fixture is a planar 3x3 vertex grid under the same constant XY field and uniform metric, with the interior vertical midline marked as a hard rail. Ordinary relations are identity. The reciprocal HardRail relation compares the same planar lattice frame on the two rail sides, so its exact relation action has zero quarter-turn and zero translation. Consequently every relation in any quotient-class cycle is identity and direct/path transports agree.

This is an analytical property of the authored fixture; it is not a claim that the production fixture was executed in this turn.

##### 5.3 Ordinary-only classes

For a class whose relations are all ordinary, and none crosses a nonzero seam transport, every certificate transport is identity by definition. Any forest-path composition and any direct cycle-closing transport are therefore identity. Such a class cannot produce `QuotientHolonomyConflict` unless certificate construction itself is inconsistent.

##### 5.4 Produced torus/cylinder falsifier

The produced torus and cylinder/annulus classes cannot be enumerated runtime-free. The A6 TB therefore pre-registers the cycle rule as a falsifier:

- selector row **232** `SurfaceCellTypedTransportAuthority.ValidPeriodicCutRouteUsesTypedIdentity` exercises the produced cylinder through materialization;
- torus selector rows **444 / 446 / 448 / 449** exercise produced periodic/multi-isolation authority and materialization surfaces.

If any accepted row first fails with `QuotientHolonomyConflict`, TB must not weaken the rule. Mandatory TB Review determines whether the evidence proves (a) a real inconsistent quotient cycle or (b) a legitimate class with nontrivial residual holonomy that invalidates the strict rule.

Fallback, **not authorized unless that Review changes the Definition:** keep exact-once certificate/ledger semantics, record both `relationTransport` and `selectedPathTransport` plus the nonidentity residual on a cycle-closing row, and treat the row as evidence-only rather than rejection. This fallback exists to avoid hiding evidence if legitimate deck-transform holonomy is demonstrated; CB/TB may not select it on their own.

#### 6. Selected relation paths are A6 authority

A6, not A7, owns relation-path selection.

For each semantic class:

1. choose the first (smallest) member of its sorted `SurfaceQuotientClassId` as the **path root**; this is evidence rooting only, never geometric representative selection;
2. use the unique selected-relation-forest path from that root to every other member;
3. store exact ordered relation-certificate IDs, traversal orientation, relation-local source chart/component bindings where the current HardRail/Periodic certificate requires them, and the exact composed transport;
4. keep ordinary identity joins in A6 path authority even when they produce no legacy selected-relation step.

A7 may project this evidence into `PureQuadVertexLineage::selectedRelationPaths`; it does not select/recompute paths. To preserve the accepted compatibility contract, the transitional lineage projection emits legacy `SelectedRelationPathCertificate` entries only for A6 paths containing at least one HardRail or Periodic selected relation step. Ordinary-only and isolation-wedge evidence therefore do not make split-square `selectedRelationPaths` non-empty. Existing completion-stage re-anchoring in `PureQuadCompletion.cpp` remains representation-only and unchanged.

An unrelated valid M5 relation that A5 does not publish as an owned occurrence relation is decision-neutral and cannot enter the forest or path set.

#### 7. A6 typed failure vocabulary

A6 introduces `SurfaceQuotientProductErrorCode`. The stable semantic names are:

```text
SourceAuthorityMismatch
RelationEndpointMissing
RelationAuthorityConflict
RelationCertificateMissing
RelationCertificateDuplicate
RelationCertificateConflict
ReciprocalSideAuthorityMismatch
MissingIsolationEvidence
InvalidIsolationEvidence
InvalidHardRailTransport
InvalidPeriodicTransport
UnsupportedSingularityPort
UnownedRelationUse
RelationConsumptionMissing
RelationConsumptionDuplicate
RelationConsumptionConflict
HolonomyConflict
InvalidClassPartition
MissingOccurrenceMember
DegenerateClassedQuad
NonBijectiveMaterialization
```

The external diagnostic prefix is `Quotient` + the semantic name, e.g. `QuotientHolonomyConflict`.

Legacy diagnostic mapping is adapter-only and only where existing frozen behavior requires it:

- `MissingIsolationEvidence` -> RA-12 `MissingIsolationSeamEquivalenceAuthority:<live-site>`;
- `InvalidIsolationEvidence` -> RA-12 `InvalidIsolationSeamEquivalenceAuthority:<live-site>`;
- `ReciprocalSideAuthorityMismatch` -> `QuotientReciprocalSideAuthorityMismatch`;
- `InvalidHardRailTransport` / `InvalidPeriodicTransport` preserve the accepted outer-stage name required by the existing negative when that negative reaches A6.

New A6 product tests assert enum codes, not incidental diagnostic prose. A6 does not reuse A5 enum values merely to keep old strings.

#### 8. Deferred R4 intent only

**A7 intent.** `M6-DEFN-R4` will freeze `SourceAttachedGeometryProduct` as a source-attached representation of already-decided A6 classes: one embedded output vertex per semantic class, exact source-support/embedding certificates, complete wedge-union sheet/chart/equivalence lineage, and no topology mutation. Geometry/representative selection is representation-only and may not alter the A6 partition, selected relation forest, or ledger.

**`G4-B002` stage-boundary intent.** `M6-DEFN-R4` will freeze the A6-derived closed-complex view needed by candidate extraction so that the consumer no longer relies on `SurfaceCellPipelineContext::hasArrangement`. CP1 proves the mechanism/equivalence on an existing closed fixture; CP3 still owns the direct-production candidate-eligibility and hard-feature-tamper re-proof required for `G4-B002` credit.

#### 9. First A6 implementation sequence

If and only if `M6-DEFN-R3-REV` accepts this record, the first implementation turn is `M6-CP1-CB6-A6` under `Architecture_M6_CP1_CB6_A6_Quotient_Product_Extraction_Code_Build_Plan.md`.

That CB absorbs the previously standalone legacy-field retirement. It adds exactly four new focused identities:

1. `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant`
2. `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord`
3. `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption`
4. `M6CP1.CycleClosingRelationTransportConflictRejected`

The next artifact-only gate, if Code + Build is compile-green, is **11 focused + selector449 = 460 fresh exact-filter processes**. The unchanged seven entering focused identities run first, then the four new A6 identities, then selector449 in exact frozen order. No selector file is changed or appended.

#### 10. Frozen-test audit for the A6 CB

| Frozen surface | Why the A6 extraction remains satisfiable |
|---|---|
| Focused rows 1-4 | A5 identity/publication/malformed-relation behavior is unchanged; A6 consumes the product after the A5 publication gate. |
| Focused row5 `MultiIsolationMaterializationRetainsAllLocalSheets` | A6 relation-owned partition is unchanged; wedge isolation remains evidence-only. Transitional A7 projection still unions member wedge sheets/equivalences. Ordinary-only A6 paths are not projected as legacy `selectedRelationPaths`. |
| Focused row6 `ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | A6 sorts owned relations by semantic relation ID and derives direction from relation authority, never edge-storage index. |
| Focused row7 `SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | A5 data is unchanged. Its class signature is keyed by sorted member occurrences/sheets/evidence; the adapter ordinal is representation-only. |
| row140 | Explicit HardRail owner mismatch remains an A5/outer validation-precedence failure before A6. |
| rows186 / 214 / 239 | Existing seam certificate, component-typed domain and reciprocal transport authority remain inputs to A6 verification; one owned relation is consumed exactly once. |
| rows436 / 444 | Relation-container permutation cannot affect the canonical relation sort, selected forest, member-set IDs, or projected selected certificates. |
| rows437 / 448 | An unused valid Periodic relation not owned by A5 cannot enter A6 certificates, ledger, partition or selected paths. |
| row438 | A7/transitional lineage projects the same A6-selected HardRail/Periodic path values; tampering remains detectable by the existing completion-domain validator. |
| row446 | Nonzero periodic rotation/translation is preserved as exact `GridAutomorphism`; §4.2 compares direct and path transport rather than requiring identity action. |
| row449 | Multi-isolation torus authority remains relation/evidence input and is also a pre-registered `QuotientHolonomyConflict` falsifier. |
| row232 cylinder | Existing typed Periodic cut materialization is the produced-cylinder `QuotientHolonomyConflict` falsifier. |
| Phase10 HardRail surfaces, including row240 | HardRail remains a topology/chart barrier, not an isolation-sheet source. The new A6 product neither creates sheets nor weakens the existing single-sheet/hard-feature distinction. |
| lineage `quotientClass` | Numeric values may be re-assigned from lexicographically sorted member sets, but no frozen test pins a numeric ordinal; invariance comparisons remain exact. |
| lineage `equivalences` | Existing sorted/deduplicated projection remains unchanged; A6 does not reinterpret `CornerWedgeIsolation` as relation ownership. |
| lineage `selectedRelationPaths` | A6 owns selection; adapter projection preserves relation-local charts/components and only emits HardRail/Periodic legacy steps. |
| `hash_completion` | The hash surface remains representation-level and is not made semantic. Existing assertions compare equivalent executions, not a hard-coded digest. |

The selector/routing bytes remain frozen at selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

#### 11. Turn disposition

`M6-DEFN-R3` is definition-complete for its bounded scope only. It grants no implementation, runtime, regression closure, G4 credit, or CP1 acceptance. Stable accounting remains **55 / 16 / 39** and debt **1**. Exact successor is mandatory independent `M6-DEFN-R3-REV`; `M6-CP1-CB6-A6` remains held until that Review accepts or amends this definition.

## `Architecture_M6_DEFN_R3_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R3_Review_Record.md`; moved verbatim.

### M6-DEFN-R3-REV — independent A6 quotient-product definition review

**Turn:** `M6-DEFN-R3-REV`
**Type:** independent runtime-free Review
**Predecessor:** `M6-DEFN-R3`
**Disposition:** **ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-4**
**Exact successor:** `M6-CP1-CB6-A6`
**Reviewed runtime authority remains:** package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 `449/449`
**Stable accounting:** unchanged `55 / 16 / 39`, produced-witness debt `1`

#### 1. Evidence boundary

This Review is static and runtime-free. It executed no Directional binary, test, benchmark, configure, compile, or relink operation and grants no runtime or checkpoint credit.

Review source was frozen by source-snapshot run/job `36207017645 / 108305601337`, artifact `10894735898`, event/snapshot SHA `dba4fbba516f3b309103c4b6529ad6194b9caa52`. The artifact provider digest is `1241268d4e0e55cbf273e1820b02a54f630dda1563b9593e96678b87600a2bfa`; embedded source archive SHA-256 is `cf5bb84898a5179824749feb9d9279cad1193e0a8c18429600d60252480f41c7`; metadata records 5,319 files, 98,165,063 bytes, recursive submodules and `runtimeExecution=false`.

A commit comparison from reviewed runtime semantic source `82b86a28...` through the Review snapshot is 66 commits ahead and contains documentation/control-plane changes only; no `src/`, `include/`, or `tests/` file changed. Selector449 and routing449 remain 449 lines at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` / `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

The Review independently inspected the R3 definition/plan, frozen M6 contract, held A6 CB plan, DESIGN quotient contract, exact accepted transitional source, and frozen focused storage-permutation witness.

#### 2. Upheld R3 decisions

The following R3 decisions are accepted without semantic weakening:

1. A6 semantic class identity is the exact sorted unique non-empty member-`OccurrenceId` set; `authority::QuotientClassId` remains adapter-only ordinal lineage.
2. Every A5-owned relation receives exactly one immutable relation certificate and one consumption row, including cycle-closing relations.
3. Joining rows form one deterministic selected forest; cycle-closing rows are not skipped.
4. The strict cycle rule remains direct canonical relation transport == exact canonical selected-forest path transport; mismatch is `QuotientHolonomyConflict`. Non-identity direct/path actions remain valid when equal.
5. A6 owns selected relation paths; A7 only projects them. Legacy `selectedRelationPaths` remains HardRail/Periodic-only.
6. R3's A6 error vocabulary, A7/R4 deferral, `G4-B002` R4 deferral, and the produced cylinder/torus TB falsifier remain binding.
7. The first A6 implementation still absorbs retirement of unread `SurfaceOccurrence::{chart,lattice,isolationSheet}` and remains compile/package-only.

R3 is therefore architecturally sound, but four precision defects must be corrected before implementation.

#### 3. Review amendments

##### RA-1 — certificate direction is canonical semantic relation direction

A `QuotientRelationCertificate` is always oriented:

```text
relation.id.first -> relation.id.second
```

not `relation.firstOccurrence -> relation.secondOccurrence`.

Evidence:

- `make_occurrence_relation_id(...)` sorts the two occurrence endpoints before constructing `SurfaceOccurrenceRelationId` (`RemeshPipeline.cpp`, near 3117).
- `SurfaceOccurrenceRelation` separately stores `firstOccurrence` / `secondOccurrence` plus `firstFrontEdge` / `secondFrontEdge`; the front-edge fields are explicitly marked representation projection only (`RemeshPipeline.h`, near 869).
- the A5 producer constructs those unsorted endpoint fields from reciprocal front-edge storage order (`RemeshPipeline.cpp`, near 4031).
- frozen focused row6 physically swaps the two reciprocal Periodic front-edge records and requires selected semantic relation direction/signature invariance.

Therefore the semantic certificate endpoints and transform direction must derive from `relation.id.first/second`. `relation.firstOccurrence`, `relation.secondOccurrence`, `firstFrontEdge` and `secondFrontEdge` may be validated as representation provenance but may not choose certificate direction. If current evidence is naturally obtained in the opposite direction, invert it exactly before publication.

##### RA-2 — every accepted OrdinaryFront quotient transport is identity

For A6 quotient semantics, every accepted `OrdinaryFront` relation publishes:

```text
relationTransport = GridAutomorphism::identity()
```

A checked isolation-seam transition remains source-chart/sheet evidence used to establish admissible reciprocal authority. Its quarter-turn is **not** the quotient relation transport.

Evidence: the accepted transitional OrdinaryFront path first requires exact `lattice_equal(first.fromLattice, second.toLattice)` and the reciprocal endpoint equality. `lattice_equal` includes lattice coordinate, branch rotation, scale level, source chart and phase. Thus the accepted quotient endpoint identification itself is identity in the already-transported local-lattice state. Lifting the source isolation-seam quarter-turn into an additional quotient transform would double-count evidence and can synthesize holonomy that the accepted equality relation does not contain.

This amendment supersedes R3 §4.1's separate “ordinary relation crossing a checked isolation seam” transport rule. It does not weaken any seam certificate check.

##### RA-3 — A5 relation evidence must be sufficient for A6; representation handles cannot reconstruct transport

Frozen A6 consumes typed A0 source authority plus one complete A5 occurrence complex. That input boundary is retained. To make it implementable without consulting the transitional materializer or global front-edge representation, A5 relation publication must be **evidence-complete**.

Each A5-owned `SurfaceOccurrenceRelation` must carry or reference immutable evidence sufficient to publish the canonical RA-1 A6 certificate, including the exact canonical `relationTransport` and the kind-specific accepted owner evidence. The minimum semantic requirements are:

- `OrdinaryFront`: identity relation transport; reciprocal side/wedge/isolation evidence remains the validating evidence.
- `HardRail`: exact accepted HardRail owner/route/transport, normalized to `relation.id.first -> relation.id.second`.
- `Periodic`: exact semantic Periodic owner action and the route/cut owner evidence required to validate it, normalized to `relation.id.first -> relation.id.second`.
- `SingularityPort`: remains unsupported by current accepted A5 and typed-fails if introduced through the validation seam.

This is an **evidence-completeness projection**, not a change to A5 relation identity, equality, owner selection, accepted relation set, cell topology, or quotient semantics. It may enrich the A5 relation record in `M6-CP1-CB6-A6`, because the A5 producer already has the authoritative phase-front values at relation-publication time. `firstFrontEdge` / `secondFrontEdge` remain optional representation provenance only and A6 must not dereference them to discover semantic transport.

Why this amendment is required:

- current A5 relations contain canonical relation ID, unsorted endpoint representation fields and front-edge handles, but no exact relation action;
- `PeriodicRelationId` explicitly excludes transport/action from identity (`AuthorityIds.h`); an owner ID therefore cannot reconstruct the action;
- DESIGN §8 already requires every certified relation to contain canonical endpoint occurrence IDs, source support, chart transport, orientation and owner-certificate identity.

A6 must not repair this missing evidence by reading global phase-front arrays through stored edge indices.

##### RA-4 — path transport composition order is frozen explicitly

`GridAutomorphism::compose(left, right)` means “apply `right` first, then `left`.” For the selected-forest path traversed from canonical endpoint `a` to `b`:

```text
pathTransport = identity
for certificate edge E in traversal order a -> ... -> b:
    T = E.relationTransport
    if traversal is opposite E's canonical certificate direction:
        T = T.inverse()
    pathTransport = compose(T, pathTransport)
```

The cycle-closing acceptance check is then exact:

```text
cycleClosingCertificate.relationTransport == pathTransport
```

This freezes the noncommutative composition order; “compose in traversal order” alone is insufficient implementation authority.

#### 4. Focused-gate amendment

The four planned new identities are retained; no fifth identity and no selector mutation is authorized. The later gate remains **11 focused + selector449 = 460 fresh exact-filter processes**.

Amend their required coverage as follows:

1. `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant` also compares the canonical relation-certificate orientation/transport signature under reciprocal front-edge storage swap and relation/cell/source-face storage permutations. This directly protects RA-1 and the existing row6 contract.
2. `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord` is unchanged except that certificate transport is checked in RA-1 canonical direction.
3. `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption` is unchanged.
4. `M6CP1.CycleClosingRelationTransportConflictRejected` must start from an individually valid certified cycle and alter exactly one otherwise admissible direct cycle-closing certificate through the A6 validation-publication seam. It must not fabricate an invalid OrdinaryFront transform to obtain the rejection. The untampered cycle must publish.

Existing focused row6 remains an independent storage-direction falsifier. Cylinder selector row232 and torus rows444/446/448/449 remain the runtime falsifiers for the strict holonomy rule.

#### 5. Review of the held Code + Build plan

With RA-1 – RA-4 folded into `Architecture_M6_CP1_CB6_A6_Quotient_Product_Extraction_Code_Build_Plan.md`, the plan is sufficiently bounded for implementation:

- one new immutable A6 product/producer;
- one evidence-complete A5 relation projection required to honor the already-frozen A5→A6 product boundary;
- retirement of only the three proven-unread A5 representative fields;
- transitional adapter consumes A6 and may not recompute quotient semantics;
- exactly four new focused identities;
- compile/package only, no generated runtime.

Stop conditions remain mandatory: if enriching A5 relation evidence requires changing relation identity/equality/owner selection, if a supposedly dead field has a live semantic consumer, or if A6 cannot validate HardRail/Periodic transport without reaching back into representation-owned global arrays, stop and return to Review rather than widening the CB.

#### 6. Regression/accounting disposition

This Review finds definition defects before implementation/runtime. It creates **no stable regression event**, no category/recurrence change, no recovery claim, and no produced-witness credit. Stable accounting remains **55 / 16 / 39** and debt **1**. Reviewed runtime authority remains package/source `10879581622 / 82b86a28...` under selector449 449/449.

The strict holonomy rule remains provisional only in the already-defined sense: the produced cylinder/torus rows are required runtime falsifiers, and only mandatory TB Review may invoke the documented evidence-only fallback if those rows prove legitimate nontrivial residual holonomy.

#### 7. Final disposition

`M6-DEFN-R3-REV` is **ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-4**.

Exact next is `M6-CP1-CB6-A6`. Do not start `M6-DEFN-R4`, A7 extraction, `G4-B002` boundary implementation, or runtime TB before that Code + Build turn completes. Compile-green `M6-CP1-CB6-A6` advances only to immutable `M6-CP1-TB6-A6-EXEC`, then mandatory `M6-CP1-TB6-A6-REV`.

## `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`; moved verbatim.

### M6-DEFN-R4 — A7 Product, Thin Adapter, and `G4-B002` A6 Boundary — Definition Record

> **Review disposition (`M6-DEFN-R4-REV`, 2026-10-03):** ACCEPTED WITH BINDING AMENDMENTS RA-18 – RA-21 (`Architecture_M6_DEFN_R4_Review_Record.md`; normative text at the end of `Architecture_M6_Frozen_Definitions.md`). Where they conflict, the amendments override §2.2 (support guard), §3.4/§5.2 (placement inside A5; identity 24), §4.2–§4.3 (protection from source hard-feature authority) and §4.4 (oracle key path and stop rule). `M6-CP1-CB9-A7` is authorized.

**Turn:** `M6-DEFN-R4`
**Type:** Definition only; runtime-free.
**Entering reviewed runtime:** `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`, focused 1–12 + selector449 = **461/461**.
**Accounting:** **60 / 16 / 44**, debt 1.
**Source inspection authority:** source-snapshot run `37137065911`, artifact `11277809639`, exact snapshot SHA `c7deb092e86f0912a304397e364d47dc94587a5a`, outer artifact SHA-256 `81cce673b5585f799bcee419dda5ab8602bbe3213e855996fd75ad9a4b6f23eb`.
**Mandatory successor if this Definition completes:** `M6-DEFN-R4-REV`.

#### 0. Turn checklist

- [x] D4 consumer and frozen-assertion census first.
- [x] D1 A7 representation and certificates.
- [x] D2 55-site thin-adapter classification and precedence.
- [x] D3 `G4-B002` A6 stage-boundary representation/equivalence demonstration.
- [x] D5 CB sequencing, focused identities and gate sizes.
- [x] R4 amendment appended normatively to `Architecture_M6_Frozen_Definitions.md`.
- [ ] Handoff/TODO/CHANGELOG closeout and mandatory `M6-DEFN-R4-REV` authorization.

This record is intentionally **IN PROGRESS** after D4. No A7, adapter, `G4-B002`, source, test, fixture, selector, or build implementation is authorized by the work recorded here.

**Operational evidence:** the start-of-turn `READ_MODE` gate was initially missed by directly reading the mandatory policy/handoff/TODO bundle before selecting snapshot mode. The miss was recognized immediately after the conservation policy was read; piecemeal repository source/document inspection then stopped. All substantive D4 inspection and this work product use the verified exact snapshot above.

#### 1. D4 — consumer and frozen-assertion census — COMPLETE

##### 1.1 Method and completeness boundary

The exact-snapshot census is stored in
`Architecture_M6_DEFN_R4_D4_Consumer_Census.md`. It conservatively retains every exact textual reference under `src/`, `include/`, `tests/`, and `benchmarks/` to the outputs named by the R4 plan:

- `vertexPositions`, `vertexProvenance`;
- lineage `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `selectedRelationPaths`;
- `hash_completion`;
- `BenchmarkQuality`.

The census deliberately keeps producer/mutation sites as well as apparent reads. This is a strict superset of readers: it prevents a compound mutation/read expression from being dropped by a heuristic. Every row records `file:line`, production/test classification, a role hint, enclosing GTest identity when recoverable, selector449 row and focused-12 ordinal when present, and the exact source line. The snapshot contains **1,189 unique reference sites**: **666 production** and **523 test/benchmark**. Per-output counts are recorded in the census header.

This is the D4 authority for D1–D3. Later R4 decisions may narrow a site from the conservative set only by explaining why it is not a consumer of the A7/boundary value; no later decision may silently omit a listed frozen assertion.

##### 1.2 Frozen assertions that directly constrain A7 geometry and representative publication

The census identifies the following already-frozen gates that directly read the geometry/provenance surface R4 will replace or project:

| Authority | D4 outputs read | R4 consequence |
|---|---|---|
| focused-12 ordinal 7 `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | `sourcePoint`, `sourceTopologyRegions`, `sourceIsolationSheets`, `equivalences`, `selectedRelationPaths` | A7 projection must retain complete occurrence-derived region/sheet/equivalence/path authority. |
| focused-12 ordinal 12 `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | `vertexPositions`, `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `equivalences` | R4 may replace floating geometry authority only if the published geometry remains support-attached and the RA-17 transport guard remains true. |
| selector449 row 73 `PureQuadCompletionPhase18.CompletionVerticesCarrySourceProvenance` | `vertexPositions`, `vertexProvenance` | one A7 vertex per A6 class must still publish complete source provenance. |
| row 87 `PureQuadCompletionPhase18.P18GeneratedInteriorVertexHasSourceTriangleLineage` | `sourcePoint` | representative/source-point publication remains a frozen observable; D1 must define it deterministically. |
| row 97 `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing` | `vertexProvenance`, `sourcePoint`, `sourceSupport`, `sourceIsolationSheets`, `sourceTopologyRegions` | A7 cannot accept stale or reconstructed authority merely because coordinates are close. |
| row 250 `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets` | geometry, provenance, all principal lineage unions, `equivalences`, `hash_completion` | D1 changes must preserve the complete integrated output contract and deterministic completion hash. |
| row 448 `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | `vertexProvenance`, `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `hash_completion` | unused valid relation evidence must remain observationally inert; A7 selection cannot depend on relation-container order or unused relation presence. |

Additional accepted Phase18 lineage authority is explicit at selector449 rows **86, 96, 100, 102, and 103**. These rows pin missing-lineage fail-closed behavior, sparse-owner publication, topology-region ownership, chart correctness, and isolation-sheet correctness respectively. D1 must cite these rows when fixing each projected lineage field.

##### 1.3 Frozen assertions that constrain selected relation paths and hashes

- selector449 row **438**, `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`, reads `selectedRelationPaths` and `sourceTopologyRegions`; selected path evidence therefore remains certificate evidence, not an A7 placement authority.
- rows **436** and **437** read `hash_completion` to freeze selected-certificate invariance under relation container permutation and unused valid relations.
- rows **448** and **449** also read `hash_completion`; any A7 lineage re-expression must define whether it changes the hash and must preserve the accepted invariances.
- row **241**, `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`, and row **250** freeze deterministic completion hashing at the broader pipeline surface.
- all `BenchmarkQuality` references are enumerated in the companion census so D1/D3 can state whether a new A7/boundary hash is projected into the existing quality-path hashes or remains a separate certificate digest.

##### 1.4 Representative-key and transport-guard observations established by the census

The current transitional materializer at `src/pipeline/RemeshPipeline.cpp:6103-6113` chooses the representative by the lexicographic key
`(SourceSupport, cornerWedgeBindings, OccurrenceId)`. The same function currently performs the forbidden semantic floating comparison at `:6118-6127` and emits `QuotientGeometryConsistencyFailure` when representative/member positions differ by more than a relative `1e-9` tolerance.

The D4 census shows that downstream accepted assertions observe the resulting `sourcePoint`, `vertexPositions`, `vertexProvenance`, and lineage authority, but none grants the adapter permission to derive placement from A6 `canonicalTransport` / `relationTransport`. RA-17 therefore remains compatible with the observed consumer surface: the later D1 decision must embed from A5 `SourceSupport`, publish a deterministic representation-only representative, and keep A6 placement transport confined to A6 strict-cycle validation.

##### 1.5 D4 conclusions binding the remaining R4 decisions

1. D1 cannot remove or silently repurpose existing lineage fields. It may change their producer from the transitional adapter to A7, but every accepted reader in the census must remain satisfiable or receive an explicitly reviewed successor contract.
2. The exact `SourceSupport` incidence certificate must become semantic geometry authority before the epsilon check is removed. Coordinate equality may remain diagnostic only.
3. The A7 representative is an observable representation choice because accepted tests read `sourcePoint`/positions/provenance. Its key must therefore be frozen explicitly rather than treated as an implementation detail.
4. `selectedRelationPaths` and equivalence transport are evidence/lineage projections. D1 must project RA-16 `canonicalRelationValue` into `SelectedRelationStep.appliedTransport`; it must not consume A6 placement transport for geometry.
5. Existing completion and quality hashes are frozen observables. D1/D3 must state exactly which new certificate fields participate in existing hashes and preserve container-order / unused-relation invariance.
6. D2 precedence analysis must use the census rather than only the 55 failure strings: several accepted tests assert legacy names and publication emptiness, so moving a predicate to A5/A7 must preserve the earliest accepted owner-visible failure.

#### 2. D1 — A7 representation and certificates — COMPLETE

D1 freezes A7 as a new immutable product. It does **not** make the transitional
`AuthoritativePhaseFrontMeshResult` or `PureQuadVertexLineage` semantic authority.
Those remain compatibility projections of the A7 product until their eventual
retirement.

##### 2.1 Product shape and immutable API

The implementation target is semantically equivalent to:

```cpp
struct SourceSupportCertificate {
  SurfaceQuotientClassId quotientClass;
  authority::SourceSupport publishedSupport;
  authority::OccurrenceId representative;
  std::vector<authority::OccurrenceId> members; // semantic order
  bool exactCommonSupport = false;
  bool everyMemberFaceIncident = false;
  bool relationEvidenceSufficient = false;
};

struct SourceAttachedVertex {
  SurfaceQuotientClassId quotientClass; // semantic vertex identity
  authority::SourceSupport support;
  geometry::SurfacePoint sourcePoint;   // representation leaf only
  Eigen::RowVector3d position;          // projection of sourcePoint only

  std::vector<authority::OccurrenceId> sourceOccurrences;
  std::vector<geometry::SourceProjectionChart> sourceCharts;
  std::vector<authority::IsolationSheetId> sourceIsolationSheets;
  std::vector<authority::TopologyRegionId> sourceTopologyRegions;
  std::vector<geometry::PureQuadEquivalenceProvenance> equivalences;
  std::vector<geometry::SelectedRelationPathCertificate> selectedRelationPaths;
};

struct GeometryEmbeddingCertificate {
  std::size_t quotientClassCount = 0;
  std::size_t embeddedVertexCount = 0;
  std::size_t classedCellCount = 0;
  bool exactClassBijection = false;
  bool exactCellTopologyCopy = false;
  bool completeSourceSupport = false;
  bool noPlacementTransportConsumed = false;
};

class SourceAttachedGeometryProduct {
public:
  const SurfaceQuotientProduct &topology() const; // immutable semantic copy/view
  const std::vector<SourceAttachedVertex> &vertices() const;
  const std::vector<SourceSupportCertificate> &support_certificates() const;
  const GeometryEmbeddingCertificate &certificate() const;
};
```

The concrete implementation may avoid storing an owning duplicate of the complete
A6 object, but the semantic contract is the same: A7 publishes exactly one vertex
for every A6 `SurfaceQuotientClassId`, copies every `SurfaceQuotientCell` corner ID
unchanged, and neither creates, unions, splits, renumbers nor drops an A6 class.
The A7 producer receives immutable A0 + A5 + A6 authority. A7 never obtains
semantic input from the partially materialized compatibility mesh.

This is bounded by D4 focused ordinal 7, selector449 rows 73/87/97/250/448 and
rows 86/96/100/102/103: all of those consumers remain satisfiable because the
legacy projection still exposes one position/provenance row per A6 class and the
same complete occurrence/chart/sheet/region/equivalence/path authority.

##### 2.2 Exact `SourceSupportCertificate` rule

The semantic support predicate is **typed exact identity**, not geometric
proximity. Let `S(q)` be the support published for A6 quotient class `q` and let
`S(o)` be the immutable A5 `SurfaceOccurrence::support` for member occurrence
`o`. A7 requires:

```text
for every q:
    members(q) is non-empty
    choose S(q) from the representation-only representative (§2.3)
    for every o in members(q):
        require support_kind(S(o)) == support_kind(S(q))
        require S(o) == S(q)
        require point.face(o) is topologically incident to S(q)
    require every cross-sheet member connection is already justified by
            A6-selected A5 wedge/side relation evidence
```

The exact incidence rule for the three support variants is:

| Published support | Exact member-support compatibility | Exact face-incidence predicate |
|---|---|---|
| `SourceVertexSupport{v}` | member support is exactly the same typed vertex `v` | member `sourcePoint.face` contains vertex `v` |
| `SourceEdgeSupport{a,b}` | member support is exactly the same canonical unordered edge `(min(a,b),max(a,b))` | member face contains both edge endpoints |
| `SourceFaceInteriorSupport{f}` | member support is exactly the same canonical source-face topology key `f` | member face canonicalizes exactly to `f` |

Cross-kind coercion is forbidden. In particular, `vertex ⊂ edge ⊂ face` incidence
does not make two occurrence points equal. A vertex support may not be promoted to
an edge/face support and an edge support may not be promoted to a face support to
force a quotient class through A7.

This rule is deliberately stronger than mere simplex-set intersection. It is the
only rule that replaces the `1e-9` check at snapshot lines 6121-6127. A7 does not
compare two member `position` vectors, barycentric vectors, lattice coordinates,
or Euclidean distances to establish semantic compatibility. The already-certified
A5/A6 relation path is the authority that permits the class membership; the common
exact `SourceSupport` proves that all class members attach to the same source
simplex. The member `SurfacePoint` is then only a coordinate representation on an
incident source face.

A floating comparison may be retained temporarily only as a diagnostic receipt.
Its value cannot reject, accept, select a representative, choose a support, alter
lineage or change any certificate bit. This directly satisfies RA-17 §2 and D4
§1.5 items 1-2.

##### 2.3 Deterministic representation-only representative

Retain the current key, now explicitly frozen as A7 representation policy:

```text
RepresentativeKey(o) =
  (o.support, o.cornerWedgeBindings, o.id)
representative(q) = min_lex { RepresentativeKey(o) | o in members(q) }
```

All `members(q)` are interpreted in the semantic sorted-member order of
`SurfaceQuotientClassId`; the `min_lex` result therefore cannot depend on source
face row, relation-container order, output row, scheduler order or hash-table
iteration. `support` remains in the key even though §2.2 requires a common support;
that keeps the current representation ordering explicit and avoids an accidental
behavior change during extraction.

The representative supplies only:

- compatibility `sourcePoint` / `vertexProvenance`;
- compatibility `vertexPositions = sourcePoint.position`;
- the representation row from which raw barycentric coordinates are serialized.

It does **not** supply quotient identity, complete chart/sheet/region authority,
relation selection or source support for the class. Those come from the class-wide
A5/A6 projection below. D4 selector449 row 87 therefore remains satisfiable while
row 448's unused-valid-relation invariance is preserved.

##### 2.4 Lineage projection

For each A7 vertex/class, project legacy `PureQuadVertexLineage` as follows:

| Legacy field | Frozen A7 source |
|---|---|
| `sourcePoint` | §2.3 representative A5 occurrence point |
| `sourceSupport` | the class `SourceSupportCertificate::publishedSupport`, not an independently resolved float point |
| `sourceOccurrences` | the exact sorted A6 class member set |
| `sourceCharts` | sorted unique union of every member `cornerWedgeBindings[].chart` |
| `sourceIsolationSheets` | sorted unique union of every member `cornerWedgeSheets` (RA-6) |
| `sourceTopologyRegions` | sorted unique union of every member `topologyRegion` |
| `equivalences` | the A6 `SurfaceQuotientClass::equivalences`, semantic order/deduplicated exactly as A6 publishes them |
| `selectedRelationPaths` | sorted unique legacy projections from A6 `QuotientSelectedPathCertificate` rows for this class |
| legacy `quotientClass` ordinal | compatibility row only: the deterministic A7 output-row ordinal; semantic identity remains `SurfaceQuotientClassId` |

For `selectedRelationPaths`, A7 performs no graph search and no transport
composition. A6 already owns the selected forest/path. Every projected
`SelectedRelationStep.appliedTransport` must therefore be the A6 legacy projection
whose step was validated against A5 `canonicalRelationValue` under RA-16 §3.
A7 must never substitute `QuotientRelationCertificate::relationTransport` or A5
`canonicalTransport`.

The complete binding tuples and ordered isolation transitions remain certificate
evidence. The legacy chart/sheet/region vectors are derived projections after the
complete tuples are validated, not independent sets that can be cross-producted.
This retains focused ordinal 7 and selector449 rows 96/100/102/103.

##### 2.5 Normative transport guard

The RA-17 transport guard is an A7 construction invariant:

```text
consumers(A6 canonicalTransport / relationTransport) == { A6 strict-cycle rule }
```

A7, its compatibility adapter, lineage projection, chart re-anchoring, representative
selection, source-point selection, position publication, completion input and hash
projection are forbidden consumers. A7 reads only A6 membership/cell topology,
relation/equivalence evidence, selected-path legacy projections, and exact A5
source-support/binding authority.

The three gauge questions intentionally carried to `M6-DEFN-R5` therefore cannot
alter CP1 A7 geometry: unequal-face-gauge exact-A3 periodic validation, HardRail
cross-region branch certification, and OrdinaryFront coordinate identity across
isolation seams remain outside this product boundary.

##### 2.6 A7 typed failures and transitional legacy mapping

Freeze the following semantic A7 failure classes. A concrete enum may use these
names or a mechanically equivalent typed spelling, but one semantic cause may not
collapse into an unrelated generic code:

| A7 typed cause | Required locus/site distinction | Transitional compatibility behavior |
|---|---|---|
| `MissingSourceSupport` | quotient class + occurrence | fail closed; no output vertex |
| `SourceSupportKindMismatch` | class + first mismatching occurrence | replaces cross-kind/ambiguous support acceptance |
| `SourceSupportIdentityMismatch` | class + occurrence | authoritative replacement for the old position-consistency predicate |
| `SourceSupportFaceIncidenceMismatch` | class + occurrence + source face | exact A0 incidence failed |
| `SourceSupportRelationEvidenceMismatch` | class + relation/occurrence pair | required wedge/side certification absent or incompatible |
| `CrossComponentBinding` | class + binding | complete binding tuples cross source components |
| `UncertifiedCrossSheetBinding` | class + binding/transition | sheet crossing lacks certified A5/A6 evidence |
| `MissingQuotientVertexEmbedding` | class | no A7 vertex for an A6 class |
| `DuplicateQuotientVertexEmbedding` | class | more than one A7 vertex for an A6 class |
| `NonFiniteEmbeddedGeometry` | class + representative | representation coordinate is non-finite |
| `TopologyMutation` | cell/class locus | A7 topology differs from immutable A6 topology |
| `MaterializedMeshInvalid` | named sub-site from D2(c) | transitional CP1 owner for mesh-level validity until A8 independently recomputes it |

Where one typed code has several checks, the diagnostic suffix is a stable semantic
site token (for example `:support-kind`, `:support-identity`, `:support-face`,
`:class-bijection`, `:cell-topology`, `:quad-orientation`, `:edge-incidence`,
`:boundary-loop`, `:vertex-fan`). It is not a source line number or output row.

No required-green D4 geometry/lineage assertion directly pins the legacy string
`QuotientGeometryConsistencyFailure`. Therefore the A7 typed cause is authority.
During the transitional adapter, that old name may be emitted only as a compatibility
diagnostic if a still-frozen caller requires it; it is not permitted to restore the
old floating predicate. D2 separately records every actually pinned adapter name and
its precedence.

##### 2.7 Hash and `BenchmarkQuality` disposition

R4 adds **no A7 certificate field to the existing `hash_completion` or
`BenchmarkQuality` path hashes**. Those hashes remain compatibility/output hashes
and continue to observe the legacy projected geometry/lineage fields they already
consume. A7 certificate metadata is compared structurally by focused tests; no new
hash is semantic identity.

Consequently:

- the same A7 semantic product under source-row, relation-container or scheduler
  permutation must project the same existing completion hashes;
- unused valid relation evidence that does not enter the selected A6 forest remains
  inert (selector449 rows 436/437/448/449);
- the representative rule is deterministic, so row 241 and row 250 determinism stay
  satisfiable;
- no future implementation may make a digest the equality key for an occurrence,
  quotient class or A7 vertex.

##### 2.8 D1 verification obligations for the first A7 CB

D1 is definition-complete only because the implementation proof is explicitly
pre-registered rather than assumed. `M6-CP1-CB9-A7` must add focused identities that
prove at minimum:

1. exact common vertex-, edge- and face-interior support acceptance;
2. one mismatch case for each support kind plus one cross-kind mismatch, all failing
   the typed support gate before any floating diagnostic;
3. deterministic representative selection under occurrence/source-row permutation;
4. complete chart/sheet/region/equivalence/selected-path projection;
5. a transport-guard test that would fail if A7 reads `canonicalTransport` or
   `relationTransport` for geometry/lineage;
6. topology copy and one-embedding-per-A6-class certificate checks;
7. the mandated `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` identity.

The gate size and exact test identities are frozen in D5; this subsection fixes the
properties D5 must cover, not the final names/count by itself.

#### 3. D2 — thin-adapter 55-site classification and precedence — COMPLETE

##### 3.1 Checkable thin predicate

After CP1 thinning, `build_authoritative_phase_front_mesh` is permitted to do only:

```text
1. invoke A5, A6 and A7 producers in order;
2. map an already-produced typed A5/A6/A7 error to a compatibility diagnostic;
3. serialize/project immutable A7 topology, vertices, lineage and counters into
   AuthoritativePhaseFrontMeshResult / PureQuadMesh;
4. compute representation-only row maps needed for that serialization.
```

It is forbidden to perform any semantic predicate, topology choice, quotient
selection, representative selection, support selection, source-chart decision,
floating equality/tolerance check, relation search, weld, manifold repair or
failure-precedence preflight. In particular the lambdas at snapshot 5584-5599 and
the `1e-9` comparison at 6121-6127 cannot survive as adapter authority.

The only accepted adapter-side conditions after thinning are mechanical bounds or
construction failures intrinsic to serialization itself; such a failure is a
projection failure, not a substitute semantic validator. A semantic condition that
can make a previously valid stage product fail belongs to A5/A6/A7 (or later A8),
not the adapter.

##### 3.2 Complete 55 literal-site census

The table below classifies the exact **55 direct literal assignments** in
`build_authoritative_phase_front_mesh` at the D4 snapshot. Categories are exactly
the R4 plan's `(a)`–`(d)` owners.

| Line | Current literal | Owner | Required move / retained behavior | Frozen precedence |
|---:|---|---|---|---|
| 5554 | `MissingAuthoritativePhaseFront` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5560 | `InvalidAuthoritativePhaseFrontSource` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5580 | `InvalidAuthoritativeSourceChartTransitions` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5611 | `AuthoritativeTopologyRegionMapMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5618 | `InvalidAuthoritativeTopologyRegion` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5625 | `AuthoritativeTopologyRegionMapMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5633 | `AuthoritativeTopologyRegionMapMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5660 | `InvalidAuthoritativeSourceEdgeTransition` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5704 | `InvalidAuthoritativeTopologyRegionIsolationAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5736 | `InvalidAuthoritativeIsolationSeamCertificate` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5745 | `InvalidAuthoritativeIsolationSeamCertificate` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5774 | `IsolationSeamCertificateSourceAuthorityMismatch` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5782 | `IsolationSeamCertificateBijectionMismatch` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5789 | `IsolationSeamCertificateBijectionMismatch` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5826 | `DisconnectedAuthoritativeIsolationSheetGraph` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5857 | `InvalidAuthoritativePhaseFrontCell` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5867 | `IncompleteAuthoritativeTopologyRegionConsumption` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5883 | `InvalidAuthoritativePhaseFrontOwnership` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5905 | `InvalidAuthoritativePhaseFrontSideAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5915 | `InvalidAuthoritativeTransitionSourceEdge` | (a) A5 | Move transition-ID/source-edge authority validation into A5 input certification. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5926 | `InvalidAuthoritativeTransitionSourceEdge` | (a) A5 | Move transition-ID/source-edge authority validation into A5 input certification. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5939 | `IsolationSeamTransitionOwnerMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5950 | `InvalidAuthoritativePhaseFrontOwnership` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5957 | `InvalidOrdinaryFrontRelation` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5964 | `InvalidSourceBoundaryAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5977 | `FalseAuthoritativeSourceBoundary` | (a) A5 | Move exact source-boundary topology predicate to A5; preserve frozen legacy name at adapter. | selector449 row 212 `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected` pins `FalseAuthoritativeSourceBoundary` |
| 5986 | `InvalidHardRailAuthority` | (a) A5 | Move/reuse exact route predicate in A5; adapter maps the A5 typed error only. | selector449 rows 227/230 pin `InvalidHardRailAuthority` and RA-15 route-before-pair precedence |
| 5991 | `UnsupportedEmbeddedReliefCut` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5996 | `InvalidPeriodicCutAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6004 | `IncompleteAuthoritativePhaseFrontSides` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6010 | `IncompleteAuthoritativePhaseFrontSides` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6023 | `QuotientUnknownFailure` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6036 | `QuotientReciprocalSideAuthorityMismatch` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6039 | `InvalidHardRailTransport` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | selector449 rows 139/140/142 pin public `InvalidHardRailTransport`; valid individual routes must reach pair/transport validation before A6 projection |
| 6042 | `InvalidPeriodicFrontTransport` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6100 | `QuotientInvalidClassPartition` | (c) A7 embedding certificate | A7 certifies one-to-one A6 class/cell embedding and topology copy; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6126 | `QuotientGeometryConsistencyFailure` | (c) A7 support certificate | Delete the floating `1e-9` semantic predicate; A7 exact `SourceSupportCertificate` owns compatibility. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6168 | `InvalidAuthoritativeQuotientClassId` | (d) projection | Serialize deterministic compatibility quotient ordinal from the A7 vertex row; no semantic validation. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6215 | `QuotientNonBijectiveMaterialization` | (c) A7 embedding certificate | A7 certifies one-to-one A6 class/cell embedding and topology copy; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6223 | `QuotientMissingOccurrenceMember` | (c) A7 embedding certificate | A7 certifies one-to-one A6 class/cell embedding and topology copy; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6238 | `DegenerateAuthoritativePhaseFrontQuad` | (c) A7 embedding certificate | A7 certifies classed-quad materialization/geometry; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6248 | `InvertedAuthoritativePhaseFrontQuad` | (c) A7 embedding certificate | A7 certifies classed-quad materialization/geometry; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6254 | `DuplicateAuthoritativePhaseFrontQuad` | (c) A7 embedding certificate | A7 certifies classed-quad materialization/geometry; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6296 | `CollapsedAuthoritativeMeshEdge` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6312 | `NonManifoldAuthoritativeMeshEdge` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6321 | `UnjustifiedAuthoritativeMeshBoundary` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6335 | `AuthoritativeMeshEdgeRelationMismatch` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6370 | `NonManifoldAuthoritativeBoundaryVertex` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6375 | `OpenAuthoritativeBoundary` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6386 | `InvalidAuthoritativeBoundaryLoop` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6392 | `InvalidAuthoritativeBoundaryLoop` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6397 | `DegenerateAuthoritativeBoundaryLoop` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6445 | `UnreferencedAuthoritativeVertex` | (c) A7 embedding certificate | A7 certifies vertex reference/fan manifoldness; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6463 | `DisconnectedAuthoritativeVertexFan` | (c) A7 embedding certificate | A7 certifies vertex reference/fan manifoldness; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6490 | `NonManifoldAuthoritativeVertexFan` | (c) A7 embedding certificate | A7 certifies vertex reference/fan manifoldness; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |

Category totals are **31 (a) + 4 (b) + 19 (c) + 1 (d) = 55**. This is a total
partition; no site is left jointly owned by the adapter and a semantic producer.

##### 3.3 Non-literal failure assignments in the same function

The plan's number 55 counts direct literal assignments, but thinning must also
remove ambiguity from the neighboring dynamic assignments:

- `5642-5644`: `MissingAuthoritativeTopologyRegions` / map mismatch is category
  **(a)** and moves to A5 with the other region-map predicates.
- `5838-5841`: `SurfaceOccurrenceComplexError` → legacy name is **(d)** pure A5
  error projection; it remains a mapping only and performs no predicate.
- `6028-6033`: the two A6 isolation-evidence legacy names are category **(b)**.
- `6045-6056`: `HolonomyConflict` / default A6 names are category **(b)**;
  `6048-6052` may append the already-produced residual as diagnostic payload but
  may not recompute it.

Thus the complete adapter failure surface after the cutover is typed producer-error
projection plus serialization failure only.

##### 3.4 Failure precedence

Precedence is frozen by **stage**, not by the old source-line order:

```text
A5 validation / A5 typed error
  before A6 construction
A6 typed error
  before A7 construction
A7 typed error / embedding certificate
  before compatibility serialization
```

This preserves every required-green direct string pin found by D4/source audit:

1. selector449 row **212** keeps `FalseAuthoritativeSourceBoundary`; the predicate
   moves to A5 but the adapter maps that A5 code back to the same string.
2. selector449 rows **227/230** keep `InvalidHardRailAuthority`. RA-15 remains
   stronger than line order: the shared exact individual route validator executes
   in A5 before pair-level owner/region/reversed-route/transport validation.
3. selector449 rows **139/140/142** keep `InvalidHardRailTransport`. Only
   individually valid routes reach the pair/transport checks; an A6 error carrying
   the corresponding typed cause maps to the same public string.

No other one of the 55 literal names is asserted by the accepted selector449 or
focused-12 lists. For those sites, the frozen contract is still fail-closed and
publication-empty behavior, but not the historical spelling. Moving an `(a)` check
earlier into A5 cannot be pre-empted by A6/A7; moving a `(c)` check into A7 cannot
pre-empt an A5/A6 error. This explicitly avoids the RA-15 validation-order
shadowing recurrence.

##### 3.5 A7 versus future A8 ownership

The 19 category-(c) checks become **producer certificates in A7 for CP1** because
A8 does not exist yet. CP2's `SurfaceProductVerifier` must later independently
recompute the §6.2 elementary incidence/manifold/boundary facts from immutable
A0/A5/A6/A7 products. At that point A7's certificate remains producer evidence and
A8's recomputation is verification; the checks are not moved back into the adapter.

The D4 frozen geometry/lineage readers therefore continue to see either a complete
A7 projection or no publication at all. No semantic failure can occur after a
partial legacy mesh has been published.

#### 4. D3 — `G4-B002` A6 stage boundary — COMPLETE

##### 4.1 Boundary product and ownership

Freeze a new immutable **A6-owned projection**, `SurfaceQuotientClosedComplexView`.
It is produced by `SurfaceQuotientProducer` from the same immutable A5 occurrence
complex used to build `SurfaceQuotientProduct`; it is stored in / returned with the
A6 product and is not reconstructed from `SurfaceCellPipelineContext::arrangement`.
It contains only topology/protection/lineage facts needed by closed-complex candidate
extraction:

```cpp
struct SurfaceQuotientSideId {
  authority::CellId cell;
  std::uint8_t side; // canonical corner side 0..3
  auto operator<=>(const SurfaceQuotientSideId &) const = default;
};

struct SurfaceQuotientEdgeId {
  std::vector<SurfaceQuotientSideId> incidentSides; // sorted; 1 boundary, 2 closed
  auto operator<=>(const SurfaceQuotientEdgeId &) const = default;
};

enum class SurfaceQuotientEdgeProtection : std::uint8_t {
  Ordinary = 0,
  HardRail = 1,
  Periodic = 2,
};

struct SurfaceQuotientBoundaryEdge {
  SurfaceQuotientEdgeId id;
  SurfaceQuotientClassId first;
  SurfaceQuotientClassId second;
  SurfaceQuotientEdgeProtection protection;
  std::optional<authority::HardRailId> hardRail;
  std::optional<authority::PeriodicRelationId> periodicRelation;
  std::vector<SurfaceOccurrenceRelationId> evidence; // semantic sorted evidence
  std::uint32_t stripOrdinal; // representation-only, §4.3
};

struct SurfaceQuotientClosedComplexView {
  std::vector<SurfaceQuotientClassId> vertices; // lexicographic class order
  std::vector<SurfaceQuotientCell> quads;       // A6 classed-cell order
  std::vector<SurfaceQuotientBoundaryEdge> edges;
  bool closed = false;
  bool edgeIncidenceBijection = false;
  bool protectionLabelsCertified = false;
};
```

`SurfaceQuotientEdgeId` is side-incidence identity rather than an endpoint pair so
parallel quotient edges cannot collapse. Every `SurfaceQuotientCell` contributes
four `SurfaceQuotientSideId`s. A closed view requires every side to belong to
exactly one two-sided edge and requires the two incident sides to have reversed
quotient-class endpoints. A source-boundary one-sided edge is representable for
future use, but **the `G4-B002` CP1 proof accepts only `closed=true`**.

Vertex lineage at this boundary is exactly `SurfaceQuotientClassId::members`.
No A7 point, coordinate, output-row ordinal, hash or representative participates.
This satisfies the D4 lineage consumers by keeping the boundary semantic identity
on the same A6 member-set authority; A7 remains the later geometry projection.

##### 4.2 Rail / periodic edge-label derivation

Protection labels are derived while A6 still has immutable A5 side/relation
authority; the adapter does not infer them from geometry.

For a quotient edge with incident sides `s0` and `s1`, compare the two directed
corner-occurrence pairs from the corresponding A5 `SurfaceOccurrenceCell`s.
A non-ordinary label is valid only when **both endpoint pairings** are certified by
A6 `QuotientRelationCertificate`s of the same relation kind and the same owner:

- two `HardRail` endpoint relations with one identical `HardRailId` -> `HardRail`;
- two `Periodic` endpoint relations with one identical `PeriodicRelationId` ->
  `Periodic`;
- otherwise, if the sides are reciprocal under A5 ordinary-front authority ->
  `Ordinary`.

A one-endpoint label, mixed kinds, different owners, non-reciprocal side pairing,
or a label that cannot be reconciled with the A5 directed-side authority is an A6
boundary-construction failure. It is never silently downgraded to `Ordinary`.
`HardRail` is protected for candidate extraction. `Periodic` is a quotient seam
label, **not** a geometric boundary and not automatically a hard feature.

The existing A6 relation certificate remains the evidence owner. The boundary view
stores relation IDs only to make the protection proof independently inspectable;
it does not compose or consume `relationTransport`. RA-17 therefore remains intact.

##### 4.3 Candidate-extraction compatibility projection

The new candidate-extraction entry point consumes the A6 boundary view directly (or
a mechanically equivalent read-only adapter), never
`SurfaceCellPipelineContext::hasArrangement`. Its graph quantities are derived only
from the boundary product:

1. nodes are `SurfaceQuotientClassId`s in lexicographic order;
2. faces are the four class IDs of every `SurfaceQuotientCell`;
3. edges are the exact `SurfaceQuotientEdgeId`s from §4.1;
4. `HardRail` maps to `touchesHardFeature=true`; `Periodic` remains an interior
   quotient edge with its periodic owner retained;
5. boundary is determined from side incidence, not `family < 0`;
6. singularity is a combinatorial quotient valence fact, not an arrangement flag;
7. strip identity is the transitive closure of the **opposite-edge relation in
   quotient quads**. Each strip is represented by the lexicographically smallest
   `SurfaceQuotientEdgeId` in the closure, then assigned a deterministic ordinal.

This replaces the old candidate extractor's arrangement `family/strand` grouping at
this stage with a topology-derived strip grouping. `family`/`strand`, source arc,
proposal ID, arrangement node coordinates and `sourceT0/sourceT1` are explicitly not
A6 boundary authority. A compatibility `SurfaceCellComplex` may be synthesized for
migration, but if used it must be a lossless serialization of the seven rules above;
it cannot read the retained arrangement to fill missing fields.

##### 4.4 CP1 equivalence demonstration

The named fixture is the existing **produced closed torus** fixture used by
`M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`:
`milestone-g/torus.obj` + `milestone-g/torus.rawfield`, with the same 18 committed
HardRail edges and fail-closed `SurfaceCells` options.

CB11 must expose the A6 boundary view from that produced run and compare it with the
existing retained closed-complex authority only as a **migration oracle**. The
required equivalence is a deterministic labeled combinatorial isomorphism:

- one bijection between A6 quotient classes and comparison vertices, keyed by the
  sorted occurrence-member set rather than positions;
- one bijection between A6 classed quads and comparison quads preserving cyclic or
  reversed four-corner incidence;
- one bijection between canonical edge-side incidence IDs preserving the two
  incident quads;
- exact equality of `HardRailId` and `PeriodicRelationId` labels on corresponding
  protected / periodic edges;
- exact equality of each vertex's sorted occurrence-member lineage;
- no coordinate/epsilon predicate and no hash equality may establish the bijection.

The comparison-side adapter may read the retained arrangement **only inside this
focused equivalence test**. Production candidate extraction must use the A6 boundary
view without consulting `hasArrangement`.

The independent oracle is the existing
`independently_check_candidate_eligibility(...)` logic from
`SurfaceComplexSimplificationPhase17Tests.cpp`, re-expressed over the labeled
quotient boundary rather than copied from candidate-extractor internals. It checks
canonical twin/edge ownership, absence of protected support, side feasibility,
source-scope/lineage consistency and open-path/closed-loop degree. CB11 must show at
least one boundary candidate is independently eligible and that marking one of its
edges `HardRail` makes that exact candidate ineligible and absent. This CP1 tamper
checks the **mechanism / label propagation only**.

##### 4.5 Debt boundary and frozen assertions

The CP1 result does **not** close `G4-B002`. M6-CP3 retains the unchanged debt:
fail-closed direct production, recovery/fallback disabled, closed source,
independently validated candidate eligibility and discriminating hard-feature
tamper after A5-A8 are complete. CP1 may use the retained arrangement only for the
§4.4 equivalence comparison; CP3 must re-prove the oracle on direct production.

D4 constraints remain satisfiable:

- the boundary uses class member sets, so no A7 representative or legacy output row
  can perturb semantic vertex identity;
- no new boundary field enters `hash_completion` or `BenchmarkQuality` hashes;
- HardRail / Periodic owner labels are copied from already-certified A5/A6 relation
  authority and do not consume placement transport;
- no source-row, relation-container or scheduler order participates in side, edge,
  strip or lineage identity.

#### 5. D5 — bounded Code + Build / TB / Review sequencing — COMPLETE

R4 itself authorizes **no implementation**. If and only if `M6-DEFN-R4-REV`
accepts this definition, the following sequence is frozen. Every Code + Build turn
is compile/package only; every runtime gate is a separate immutable artifact-only
TB followed by mandatory Review. Selector449 and the focused-12 prefix remain
byte-frozen.

##### 5.1 CB9 — `M6-CP1-CB9-A7`

Scope: implement D1 A7 plus category-(c)/(d) adapter thinning. Append these eight
focused identities after the frozen focused 1-12, in this exact order:

13. `M6CP1.A7PublishesOneEmbeddedVertexPerA6Class`
14. `M6CP1.A7ExactSourceSupportAcceptsVertexEdgeAndFaceInteriorClasses`
15. `M6CP1.A7RejectsSupportKindAndIdentityMismatchesBeforeFloatingDiagnostics`
16. `M6CP1.A7RepresentativeIsInvariantToOccurrenceAndSourceRowOrder`
17. `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues`
18. `M6CP1.A7NeverConsumesPlacementTransportForGeometryOrLineage`
19. `M6CP1.A7CopiesA6TopologyWithoutClassMutation`
20. `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`

The eighth identity must execute the real
`validate_materialized_completion_domain_ownership` production-completion owner
check and require an empty failure string; a replica comparator receives no credit.

Gate after compile-green CB9: **focused 1-20 + selector449 = 469 fresh exact-filter
processes**, exact-one selection, zero skips, benchmark 0, immutable postflight.
Turn sequence: `M6-CP1-CB9-A7` -> `M6-CP1-TB9-A7-EXEC` -> mandatory
`M6-CP1-TB9-A7-REV`.

##### 5.2 CB10 — `M6-CP1-CB10-A5V`

Scope: move only D2 category-(a) semantic predicates into A5 and remove their
adapter copies. Category-(b) remains error projection; already-extracted A7 remains
unchanged. Append four identities, preserving focused 1-20 as an exact prefix:

21. `M6CP1.A5OwnsPhaseFrontRegionAndBoundaryValidationBeforeA6`
22. `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames`
23. `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport`
24. `M6CP1.ThinAdapterPerformsNoSemanticValidationOrSelection`

The fourth is a structural/source-level contract test over the adapter call surface;
it must fail if a semantic predicate, representative/support selection, relation
search or tolerance check is reintroduced.

Gate after compile-green CB10: **focused 1-24 + selector449 = 473 fresh processes**
under the same exact-one/zero-skip/benchmark-0/immutable-postflight rules.
Sequence: `M6-CP1-CB10-A5V` -> `M6-CP1-TB10-A5V-EXEC` -> mandatory
`M6-CP1-TB10-A5V-REV`.

##### 5.3 CB11 — `M6-CP1-CB11-G4`

Scope: implement only D3's A6 closed-complex boundary and candidate-extraction
adapter. Append four identities, preserving focused 1-24 as an exact prefix:

25. `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`
26. `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels`
27. `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage`
28. `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle`

Identity 28 includes the mechanism-only HardRail tamper described in §4.4 but must
state explicitly that it does not discharge the CP3 direct-production debt.

Gate after compile-green CB11: **focused 1-28 + selector449 = 477 fresh processes**
with the same immutable rules. Sequence: `M6-CP1-CB11-G4` ->
`M6-CP1-TB11-G4-EXEC` -> mandatory `M6-CP1-TB11-G4-REV`.

After TB11 Review, a separate **`M6-CP1-CLOSE-REV`** checks all six frozen CP1 exit
items against exact source and the fresh 477-process gate. It may close CP1 only if
A5/A6/A7 are behind immutable stage APIs, the adapter satisfies §3.1, there is no
position weld, focused multi-isolation remains green, and candidate extraction no
longer depends on `hasArrangement`. `M6-DEFN-R5` remains a CP3-entry gate and is not
pulled into CP1 closure.

##### 5.4 Gate-file rule

CB9/10/11 create successor focused-list files of 20, 24 and 28 identities
respectively. Each file must preserve
`Architecture_M6_CP1_Required_Green_Focused_12.txt` byte-for-byte as its first 12
lines and preserve the preceding successor list as an exact prefix. A Code + Build
report records each new list's SHA-256 before its TB. Neither selector449 nor the
original focused-12 file is edited.

#### 6. Carried R5 obligations

Unchanged and not decided here: unequal-face-gauge exact-A3 periodic witness/rule,
HardRail cross-region branch certification, and OrdinaryFront coordinate identity
or isolation-seam transition across isolation seams. Owner remains `M6-DEFN-R5`.
The D1 transport guard expressly keeps all three out of CP1 A7 geometry and D3
closed-complex boundary construction.

#### 7. R4 disposition

D1-D5 are definition-complete and runtime-free. Stable accounting remains
**60 / 16 / 44**, debt **1**. No source, test, fixture, selector or build/runtime
implementation is authorized by this record. Exact successor is mandatory
`M6-DEFN-R4-REV`; only that independent Review may accept/reject/amend R4 and
release `M6-CP1-CB9-A7`.

## `Architecture_M6_DEFN_R4_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R4_Review_Record.md`; moved verbatim.

### M6-DEFN-R4-REV — Independent Review of the A7 / Thin-Adapter / `G4-B002` Definition

**Turn:** `M6-DEFN-R4-REV` (runtime-free Review)

**Reviewed:**
- `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`
- `Architecture_M6_DEFN_R4_D4_Consumer_Census.md`
- the CB9/CB10/CB11 plans
- the R4 amendment in `Architecture_M6_Frozen_Definitions.md`

**Source authority:** branch HEAD at review start (`e73ea19a`). Its semantic source is byte-identical to the promoted `8e0818b1`, which is also R4's snapshot basis (`c7deb092`).

**Disposition:** **ACCEPTED WITH FOUR BINDING AMENDMENTS (RA-18 – RA-21).**
- `M6-CP1-CB9-A7` is authorized under RA-18.
- CB10 and CB11 stay sequenced and held behind their predecessor Reviews; RA-19 – RA-21 amend them now.
- Accounting stays **60 / 16 / 44**, debt 1.

#### 1. What R4 got right (verified)

- **D4 census.** 1,189 exact reference sites (666 production, 523 test/benchmark); a conservative superset, built from a grep. §1.2–§1.3 correctly name the frozen readers that bound A7: focused 7/12, and selector rows 73/86/87/96/97/100/102/103/250/436/437/438/448/449/241.
- **D2 literal-pin claim.** I re-derived it by scanning every required test body (focused-12 + selector449) for each of the adapter's 47 distinct failure literals. Exactly three are pinned:
  - `FalseAuthoritativeSourceBoundary` — row 212;
  - `InvalidHardRailAuthority` — rows 227/230;
  - `InvalidHardRailTransport` — rows 139/140/142.

  R4 §3.4 is accurate.
- **D1 projection and transport guard.**
  - A7 publishes one vertex per A6 class, copies A6 topology, and derives lineage fields class-wide from A5/A6.
  - Selected steps carry `canonicalRelationValue`; RA-17 stays an A7 construction invariant.
  - No new hash field.
  - The representative key `(support, cornerWedgeBindings, OccurrenceId)` is frozen explicitly, as D4 required.
- **D2 partition** (31 / 4 / 19 / 1) and the A7-now / A8-later ownership of the (c) checks are sound.
- **D5 sequencing.** CB9 → TB9 → REV → CB10 → TB10 → REV → CB11 → TB11 → REV → `M6-CP1-CLOSE-REV`. Each gate is the prior focused list plus new identities plus selector449, and focused-12 must stay a byte-exact prefix.

#### 2. Findings

##### F1 (High, D1) — R4 deletes the only check that united occurrences are the same source point

Code facts:
- Neither the A4 product validator (`SurfacePhaseFrontProduct::make`, `SurfaceCellTracing.cpp:7965-8395`), A5 relation construction (`RemeshPipeline.cpp:3284-4500`), nor A6 compares the positions of relation-paired occurrences.
- The adapter's `QuotientGeometryConsistencyFailure` (`:6118-6127`) is the **only** cross-relation point-coincidence detector in the chain.

D1 §2.2 replaces it with typed support **identity**. But equal `SourceEdgeSupport{a,b}` or `SourceFaceInteriorSupport{f}` only means "on the same simplex". Two members on the same edge at different parameters, or in the same face at different barycentrics, pass D1 and are published as one vertex. An A4/A5 mis-pairing that the current code rejects would become a silent weld of distinct points: a fail-open regression on CP1 exit item 6.

Two more corrections to D1's wording:
- **The support is not tolerance-free.** A5 resolves each occurrence's `SourceSupport` with `SurfacePointSourceSupportResolver`, which snaps barycentrics within `1e-8` (`SurfacePointSupport.h:110-175`). "Exact typed identity" is therefore exact comparison of A5's tolerance-classified values. That is legitimate as A5-owned authority, but A7 must read `occurrence.support` and never re-resolve support from points.
- **Accountability.** The `M6-CP1-TB8-A6-REV` addendum, the R4 plan and RA-17 §3 (review agent) said the float check could survive "only as a non-authoritative diagnostic". They conflated *authority*, which decides, selects or merges, with *fail-closed validation*, which can only reject. §5.3 forbids proximity as a **recovery** mechanism; it does not forbid a reject-only consistency check. R4 followed the plan. The error is the review agent's.

**RA-18** fixes this (frozen definitions).

##### F2 (High, D3) — protection labels come from relation kind, so hard edges carried by periodic cuts lose protection

D3 §4.2/§4.3 label a quotient edge `HardRail`, and only those become `touchesHardFeature`. `Periodic` is "not automatically a hard feature".

The named CP1 fixture contradicts this:
- The produced torus (`milestone-g/torus.obj` + `.rawfield`) declares 18 user hard edges, a minor and a major cycle (`SurfaceComplexSimplificationPhase17Tests.cpp:520+`, `make_torus_pipeline_fixture`). They cut the torus into **one** topology region (ORIENTATION witness table; DEFN-R1).
- A5 accepts a HardRail relation only across **different** regions (`RemeshPipeline.cpp:4210`).
- The torus materializes green, so its hard edges are carried by **PeriodicCut** relations (`SurfaceCellTracing.cpp:13858-13868`, `route = cutRoute`), not HardRail ones.

Consequences:
- Under D3, all 18 hard-feature edges would be labeled `Periodic` and left **unprotected** for candidate extraction.
- The arrangement marks them `hardFeature` (`arc.hardFeatureRail`, `RemeshPipeline.cpp:7983`).
- So test 26 fails, or candidate extraction may simplify across hard features, which is the very `G4-B002` property being proved.
- R4's "same 18 HardRails" wording conflates user hard-feature edges with the A5 `HardRail` relation kind.

Related observation, for the R5 / CB11 census: A5 builds its chart-barrier hard-feature set only from HardRail front routes (`RemeshPipeline.cpp:3323-3331`). Hard features carried by PeriodicCut carriers are therefore absent from A5's barrier set, but present in completion's (`hardFeatureRailEdges`). CB11 must not reuse A5's set as protection authority.

**RA-20** fixes the labeling.

##### F3 (High, D3) — the CP1 equivalence oracle is not executable as specified

D3 §4.4 keys the vertex bijection "by the sorted occurrence-member set". The comparison side is the retained arrangement `SurfaceCellComplex`, and its nodes carry no A5 `OccurrenceId` members (`SurfaceArrangement.h:319+`). So the key cannot be computed there.

The arrangement is also built from FlowRep arcs: traced arcs plus accepted `network.proposals` boundary paths (`FlowRepStrands.cpp:782+`). Isomorphism with the A6 classed quads is asserted, never shown. Traced arcs can subdivide the proposal cells.

The only available combinatorial key path is:
- halfedge `(proposalId, proposalSide)` → `network.proposals[proposalId]` → A4 `CellId` and side.
- R4 does not establish that this path exists.

**RA-21** fixes the oracle.

##### F4 (Medium, D2) — "precedence frozen by stage" misses the order within A5

Today the effective order is: existing A5 checks → adapter (a) checks, in edge-loop order → A6 → mesh checks. Moving 31 (a) checks "into A5" without saying **where** inside A5 can put them ahead of A5's existing relation checks. Those relation checks own the pinned rows 139/140/142 and 227/230.

**RA-19** fixes the placement.

##### F5 (Medium, D5) — identity 24 is a source-text test

`M6CP1.ThinAdapterPerformsNoSemanticValidationOrSelection` is specified as a "source-structure" test. A gtest that inspects source text is fragile and has no behavioral content.

**RA-19** replaces it with a behavioral projection identity plus a static Code + Build / Review check.

##### F6 (Low) — the census is a grep dump

Declarations are labeled "consumer/read". That is acceptable as a superset, and the decision-bearing analysis lives in record §1.2–§1.5. A future R5 census should separate declarations, producers and readers.

#### 3. Amendments (normative; full text in `Architecture_M6_Frozen_Definitions.md`)

| Amendment | What it fixes | Effect on identities |
|---|---|---|
| **RA-18** (F1) | `SourceSupportCertificate` gets typed exact common support, read from A5 `occurrence.support` (authority), **plus** a fail-closed same-simplex point-coincidence validation in dimensionless simplex coordinates. The validation can only reject; it never accepts, merges, selects or chooses the representative. It replaces the `1e-9` position check. | Identity 15 is renamed and widened. |
| **RA-19** (F4, F5) | Moved (a) checks go inside A5, **after** every existing A5 check, keeping their current relative order. | Identity 24 becomes behavioral; the source rule becomes a static CB/Review check. |
| **RA-20** (F2) | A quotient edge gets a separate `hardFeatureProtected` attribute derived from typed source hard-feature authority. The relation-kind label stays. Candidate protection reads `hardFeatureProtected`. | — |
| **RA-21** (F3) | The oracle key path is defined explicitly, with a stop rule. | — |

Gate sizes are unchanged: 469 / 473 / 477.

#### 4. Closeout

| Duty | Result |
|---|---|
| Record, census, plans, frozen amendment | Read in full; claims checked against exact source. |
| D2 pinned literals | Independently re-derived: exactly rows 212, 227/230, 139/140/142. |
| D1 | Accepted with RA-18. Fail-open weld gap closed; support-tolerance provenance stated. Review-agent plan error owned. |
| D2 | Accepted with RA-19. Intra-A5 placement rule; identity 24 behavioral. |
| D3 | Accepted with RA-20 (protection from source hard-feature authority) and RA-21 (executable oracle key path, stop rule). |
| D5 | Accepted. Identities 15 and 24 renamed; counts unchanged. |
| Lessons | 189 (reject-only guards vs authority); 190 (a source property cannot be inferred from the relation kind that carries it). |
| Accounting | 60 / 16 / 44, debt 1. |
| Successor | `M6-CP1-CB9-A7` under its plan plus RA-18. |
| Turn boundary | Runtime-free; no generated Directional executable run. |

## `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md`; moved verbatim.

### M6-DEFN-R5 — CP3 Entry Definition Record (WIP)

**Turn:** `M6-DEFN-R5`
**State:** DEFINITION COMPLETE — D1-D9 decided; pending mandatory independent `M6-DEFN-R5-REV`.
**Turn type:** runtime-free Definition. No Directional executable was run and no source/test/fixture/selector/build byte was changed.
**Mandatory successor:** `M6-DEFN-R5-REV`. No implementation is authorized until that Review accepts RA-30 and the held CB1 plan.

#### 0. Frozen source authority

This turn used one authoritative source snapshot only: workflow run `37433281173`, source/event SHA `22b636c636bb0fb793410d7fe31ca8e51f363ba0`, source artifact `11398311934`. The downloaded snapshot metadata records `runtimeExecution=false`; `source.tar.gz` SHA-256 is `8511dfaa1e3c33e059fb8a9fe50d942900ba697f33c704fc4895f0d16e4a0856`; all `5513/5513` source-manifest rows verified. The reviewed entering runtime authority remains `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, 491/491, per the frozen R5 plan. Accounting remains 60 / 16 / 44, debt 1.

The decisions below follow the R5 method rule: first establish the real producer branch, then define the predicate, then name a production-reachable falsifier. No hand-built relation record is accepted where the producer can create the product.

#### D1 — exact-A3 Periodic unequal-face-gauge rule — DECIDED

##### Reachable authority

`SurfacePeriodicRelationEndpointState` is explicitly the periodic **relation-gauge** state, distinct from cut-domain `LocalLatticeState`; it publishes relation-gauge lattice coordinate, branch rotation, scale, source chart, branch authority, boundary occurrence, occurrence orientation and relation rotation (`include/directional/geometry/SurfaceCellTracing.h:1437-1453`). `make_periodic_relation_endpoint_state` strips the local face branch gauge and applies the relation turn only on the Reverse side (`src/geometry/SurfaceCellTracing.cpp:7925-7941`). Semantic Periodic action is selected only when Forward/Reverse interval orientation and reversed cut route agree (`src/geometry/SurfaceCellTracing.cpp:7945-7965`).

A5 already computes the exact placement-gauge conjugation from four endpoint gauges: `T = Γ_to^-1 ∘ g ∘ Γ_from`; it requires the two endpoint-derived transports to be equal (`src/pipeline/RemeshPipeline.cpp:4543-4614`). The remaining defect is the final check against `SurfaceFrontEdge::{from,to}Lattice`, which is face-gauged representation state (`src/pipeline/RemeshPipeline.cpp:4869-4874`). RA-16 established that comparing such face-gauged branch values is unsound when endpoint face gauges differ (`.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md:247-269`).

##### Frozen rule

For **exact-A3 Periodic** relations only:

1. Keep the semantic relation value `g` in the Periodic relation-endpoint gauge. Do not redefine `canonicalRelationValue`.
2. Recompute each published `SurfacePeriodicRelationEndpointState` from its local placement state, interval, relation rotation and `branchAuthority`; exact inequality is a typed Periodic authority failure. This keeps `make_periodic_relation_endpoint_state` as the sole gauge bridge.
3. Derive `Γ` for each endpoint exactly as the current `periodic_endpoint_gauge` does, and derive placement transport `T = Γ_to^-1 ∘ g ∘ Γ_from` for both endpoint pairs. The two derived `T` values must be identical.
4. The final placement check is against the **A5 occurrence endpoint placements named by the relation's canonical endpoint pairs**, not against the `SurfaceFrontEdge` lattice copies. `T` must map both occurrence lattice coordinates exactly and preserve equal scale. No branch equality is evaluated directly in two different face gauges.
5. Independently, in the relation gauge, `g` must map the two published Forward endpoint states to the reciprocal Reverse endpoint states in both coordinate and branch. Thus coordinate placement and relation-gauge branch correctness are separately certified instead of one face-gauged predicate standing in for both.
6. Non-A3 Periodic stays on the existing legacy action-or-inverse placement path; this D-item does not widen its semantics.

This is a validation/evidence correction, not a new quotient relation: relation identity, `equivalence.action`, route/cut route, canonical relation value and A6 strict cycle semantics remain unchanged.

##### Required produced witness and falsifiers

Reserve `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`.

The witness must be emitted by the real periodic producer and must prove at least one reciprocal exact-A3 endpoint pair has unequal `branchAuthority.localFaceBranchRotation`. The current hand-constructed endpoint-state test already demonstrates that unequal face gauges are representable (`tests/SurfaceCellTransitionQuotientTests.cpp:5815-5878`), but it is **not** sufficient as the CP3 reachability witness.

Conjunct falsifiers on the produced chain:
- change one occurrence placement coordinate while retaining the published A3 relation endpoint state → placement-coordinate clause rejects;
- change one published local-face gauge/endpoint branch authority and republish the upstream product consistently far enough to reach A5 → endpoint-state recomputation/relation-gauge clause rejects;
- change the semantic Periodic relation value while retaining endpoint states → relation-gauge mapping rejects;
- swap storage orientation only → canonical semantic result stays unchanged (existing storage-canonical periodic coverage at `tests/SurfaceCellTransitionQuotientTests.cpp:5927-6003` remains a control).

A witness whose paired local face gauges are equal is vacuous for D1 and earns no D1 credit.

#### D2 — HardRail cross-region branch certification — DECIDED

##### Reachable authority

HardRail is a real A5 relation only for reciprocal HardRail front edges with the same rail owner, **different topology regions**, and reversed route (`src/pipeline/RemeshPipeline.cpp:4657-4683`). Its placement transport is correctly coordinate-rigid today: A5 derives the unique quarter-turn/translation mapping the two occurrence endpoint-coordinate pairs (`src/pipeline/RemeshPipeline.cpp:4738-4799`). This must remain the placement authority.

The missing fact is an independent branch certificate. `LocalLatticeState.branchRotation` contains the selected source face's propagated face gauge plus the region-local lattice branch; directly subtracting two regions' values is invalid. The review derives the contamination term explicitly (`branch(b)-branch(a)=R_true+τ`) and shows why constant-field HardRail gates cannot expose it (`.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md:251-269`).

##### Frozen rule

A HardRail relation must carry **per-endpoint face-gauge evidence** for the exact occurrence placements used by the relation. The minimum evidence is the selected source-face topology plus its authoritative `localFaceBranchRotation` (or a semantically equivalent immutable A4-published gauge value). It is evidence only; it does not become occurrence identity or quotient identity.

For each canonical HardRail endpoint mapping `a -> b`:

- `B_a`, `B_b` = placement `branchRotation` as quarter-turns;
- `F_a`, `F_b` = published local-face gauges;
- face-free regional lattice branches are `C_a = F_a^-1 ∘ B_a` and `C_b = F_b^-1 ∘ B_b`;
- `R_coord` = the rotation of the already-authoritative coordinate-rigid `canonicalTransport`;
- require exactly `R_coord = C_b ∘ C_a^-1`.

Apply the same equation to both HardRail endpoint pairs; both must agree with the one coordinate-rigid transport. Failure is a typed HardRail branch-certification failure mapped through the existing `InvalidHardRailTransport` external family unless Review authorizes a more specific stable external name.

This rule deliberately **does not derive** placement transport from branch data. Coordinates remain primary for HardRail placement; the stripped branch relation is an independent certificate.

##### Required produced witness and falsifiers

Reserve `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`.

The fixture must be produced by the real tracer, have a cross-region HardRail, and require a non-zero selected-face gauge difference or non-zero field matching on the rail; constant-XY HardRail fixtures are insufficient. The repository already demonstrates that non-zero matching on hard carriers is reachable (`.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md:264-267`).

Falsifiers:
- alter only one endpoint face-gauge evidence value → branch certificate rejects while coordinate-rigid `T` is unchanged;
- alter only one placement branch rotation → branch certificate rejects;
- alter the coordinate correspondence so `R_coord` changes while branch evidence stays fixed → coordinate-rigid or branch certificate rejects;
- storage/canonical endpoint reversal must invert both sides and preserve acceptance.

#### D3 — OrdinaryFront identity across isolation seams — DECIDED

##### Reachable authority

A5 currently assigns `GridAutomorphism::identity()` to every OrdinaryFront relation (`src/pipeline/RemeshPipeline.cpp:4714-4730`). A6 then demands complete local-lattice equality, including face-gauged `branchRotation`, `sourceChart`, and floating `phase`, before accepting the identity relation (`src/pipeline/RemeshPipeline.cpp:5225-5247`). Separately, if reciprocal side spans are collinear on the same source edge but their sheets differ, A6 requires exact reciprocal `CornerWedgeIsolationTransition` evidence (`src/pipeline/RemeshPipeline.cpp:5266-5313`). Frozen RA-2 already says the checked seam quarter-turn is chart/sheet evidence and must **not** be re-applied as quotient transport (`.agents/Directional/Architecture_M6_DEFN_R3_Review_Record.md:56-68`).

##### Frozen rule

Keep `OrdinaryFront.relationTransport = identity` universally. For an OrdinaryFront endpoint pair, quotient-coordinate identity is certified by the face-independent lattice product only:

- exact `latticeCoordinate` equality;
- exact `scaleLevel` equality.

Do **not** require equality of `sourceChart` or face-gauged `branchRotation` across an isolation seam. Those are relation-local chart evidence, not quotient coordinates. Do not convert the isolation-seam transition quarter-turn into quotient transport.

For a collinear span whose reciprocal endpoint sheets differ, acceptance additionally requires the already-frozen reciprocal checked isolation transition (`fromSheet/toSheet` in each direction). For non-seam OrdinaryFront spans, the existing same-sheet/wedge-membership rule remains. `phase` remains placement provenance and may be checked by its own producer contract, but the CP3 OrdinaryFront quotient identity must not rely on the current `1e-10` floating phase comparison as topological authority.

##### Required produced witness and falsifiers

Reserve `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`.

The fixture must be produced by the real tracer and contain a front edge collinear with an isolation seam; hand-built relation records are forbidden. This same produced seam-collinear family may be shared with D7, but D3 and D7 require separate falsifier assertions.

Falsifiers:
- change one endpoint lattice coordinate → reject identity;
- change one endpoint scale → reject identity;
- remove or reverse one required seam transition while keeping coordinates equal → reject reciprocal isolation evidence;
- change only relation-local source-chart/face-gauge representation while keeping valid checked seam evidence and face-independent coordinates → acceptance must not change.

#### D4 — A5 chart-barrier census — DECIDED

##### Reachable authority

A5 currently constructs its `SourceChartTransitionGraph` barrier set by scanning **only HardRail** front-edge routes (`src/pipeline/RemeshPipeline.cpp:3785-3799`). That is not the same authority as source hard-feature protection. RA-20 already requires A6 `hardFeatureProtected` to come from the typed source hard-feature edge set, independent of relation kind, and explicitly records that PeriodicCut carriers can be hard features (`.agents/Directional/Architecture_M6_Frozen_Definitions.md:735-755`). The produced torus gate demonstrates this non-vacuously: its protected hard-feature carriers include Periodic relations and recover exactly the 18 source hard edges (`tests/SurfaceCellTransitionQuotientTests.cpp:4302-4355`).

##### Frozen decision

The HardRail-only A5 barrier census is **not semantic**. It conflates relation kind with source hard-feature authority and must be corrected before CP3 direct-production testing.

A5 must receive the same immutable typed source hard-feature edge authority used by downstream completion/A6 protection and build `SourceChartTransitionGraph` from that set directly. Relation kind is not the barrier selector:

- every typed source hard-feature edge is a chart barrier, including a PeriodicCut carrier;
- every HardRail carrier must be in that typed set; otherwise fail closed as inconsistent authority;
- an unmarked PeriodicCut is not promoted to a hard feature merely because it is Periodic;
- A5 does not reconstruct hard-feature authority from routes.

This preserves the single-writer rule: source hard-feature authority decides barrier membership once; A5 and A6 consume it for different products.

##### Required produced witness and falsifiers

Reserve `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`.

Use the existing produced torus path because it already supplies the required PeriodicCut-carried hard features. The identity must prove that all 18 frozen torus hard edges are present in the A5 chart barrier input/effect even though the relations are PeriodicCut, and that the resulting occurrence binding components do not cross those barriers.

Falsifiers:
- remove one typed hard edge while leaving its Periodic relation intact → that edge must cease being a chart barrier (proves authority comes from the typed hard-feature set, not relation kind);
- keep a HardRail relation but remove its carrier from typed hard-feature authority → fail closed on the HardRail/source-authority consistency rule;
- mark an Ordinary/Periodic carrier as hard in typed source authority → it becomes a chart barrier without changing relation kind.

#### 5. Bounded-turn disposition

D1-D4 are decided above. **D5-D9 are not yet decided** and are intentionally not summarized into normative text without their required source/gate audit. In particular, this WIP does not freeze the class-wide optimizer/validation reference, the D6 permutation equality, D7 relation-kind-aware selected-edge cross-sheet semantics, the full CP3 exit evidence matrix, or final CB/gate arithmetic.

No RA-30 amendment is published from this partial record. RA-30 must be written only after D5-D9 are decided so the normative amendment is internally complete and reviewable as one CP3-entry definition.

Resume `M6-DEFN-R5` at **D5** using this exact snapshot authority unless branch/source semantics have changed; if they have, acquire a new authoritative snapshot before accepting further static conclusions.


---

#### Resume addendum — D5-D9 decided (2026-10-06)

This addendum supersedes only the bounded-turn statement above that D5-D9 were undecided. D1-D4 remain as frozen above. The turn itself remains WIP until RA-30, the held CB plan, exact G4-B001 3/3 test-name resolution, durable navigation updates, and final self-audit are complete.

#### D5 — class-wide optimizer and validation references — DECIDED

RA-26's two representative-sensitive consumers are confirmed in current source: optimizer energy selects `facePoints.front()` (`SurfaceMeshOptimizer.cpp:1470-1509`), gradient selects the first valid face provenance (`1943-1970`) and finite differences narrow to `source_face_scope(faceSource.face)` (`2001,2124`); final edge-field validation begins from the first endpoint scope (`2675-2680`). Existing helpers already expose the correct class/quad-wide ingredients at `986-1153`: all four corner authorities, compatible-chart resolution, and quad reference projection. RA-28b forbids assuming the selected representative face belongs to every chart carried by the quotient class.

Freeze one authoritative reference rule:
1. resolve a compatible chart from all four quad-corner provenance points plus all four `vertexChartAuthority` sets;
2. project the quad centroid in that resolved chart and use the resolved chart-face set for normal/field energy and gradient;
3. freeze that face set across each finite-difference gradient evaluation and each line-search candidate evaluation; no corner/representative face may narrow the scope;
4. final edge-field metrics project the edge midpoint in the same quad-wide compatible chart rather than first-endpoint scope;
5. if no compatible authoritative chart can be resolved, or projection within it fails, fail typed. The current first-valid-provenance fallback in `quad_reference_surface_point` is forbidden on this authoritative path.

Cost bound: four-corner chart resolution is linear in the total published chart memberships of those four corners. Gradient and line-search use a fixed number of projections per quad. No class-pair scan, global search, or asymptotic regression is authorized.

#### D6 — produced permutation falsifier — DECIDED

Use a direct-produced torus with recovery disabled and fail-closed fallback. Compare baseline with a perturbation that simultaneously:
- permutes source-face rows while consistently remapping every source-face-indexed field/provenance input;
- permutes output vertex and face rows before optimizer entry with lineage/indices remapped consistently;
- rotates every quad corner cycle by a deterministic nonzero offset.

Non-vacuity requires at least one quotient-class representative source-face row to change and at least one quad corner-0 vertex to change.

Freeze equality as follows:
- A5/A6/A7/A8 semantic identities, relation values, certificates, failure/accept decisions and canonical structural digests: exact after semantic remapping;
- optimizer accept/reject and iteration/line-search decision sequence: exact;
- optimized positions and continuous validation metrics: componentwise absolute difference <= `1e-12 * max(1, source_bbox_diagonal)` after lineage-based remapping;
- discrete validator outcomes, codes and topological counts: exact.

Reserve `M6CP3.ClassWideOptimizerReferencesAreSourceOutputAndCornerPermutationInvariant`.

#### D7 — relation-kind-aware selected-edge cross-sheet rule — DECIDED

The current A7 selected-edge rule (`RemeshPipeline.cpp:6861-6960`) compares endpoint wedge sheet sets globally and, if disjoint, demands connecting isolation-transition evidence without dispatching on relation kind. RA-27a already establishes that sheet IDs are not semantically comparable across unrelated topology-region partitions.

Freeze:
- **HardRail:** do not compare global sheet IDs across its different topology-region partitions. Require the HardRail relation/route, D2 endpoint gauge+branch certificate, and each endpoint's own wedge-sheet validity. A cross-region isolation transition is neither required nor sufficient.
- **OrdinaryFront:** require one topology region. Shared sheet passes. Disjoint sheets require one exact connecting isolation transition certified both by the source transition graph and the relation evidence.
- **Periodic:** same rule within one topology region. A produced cross-region Periodic witness is a Review stop; do not silently exempt it.
- unsupported relation kinds fail closed.

Produced seam-collinear witness: use the real tracer on split-isolation geometry with an isolation seam deliberately collinear with a traced front side; no hand-built relation records. It must actually produce an OrdinaryFront selected relation whose endpoint sheet sets are disjoint. Baseline A7 accepts only because the exact connecting transition exists. Tampering only that transition's sheet endpoints must trigger the selected-edge cross-sheet rejection.

Reserve:
- `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`
- `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`.

#### D8 — CP3 exit evidence — DECIDED

Mechanism-only CP1/CP2 rows remain prerequisites but cannot replace fresh direct-produced CP3 evidence. Freeze these direct owners:

| Frozen exit obligation | CP3 evidence owner |
|---|---|
| equal coordinates/positions without certified relation remain distinct | `M6CP3.DirectProductionKeepsCoincidentUnrelatedClassesDistinct` |
| every A5 relation consumed exactly once | `M6CP3.DirectProductionConsumesEveryA5RelationExactlyOnce` |
| exact/shared source support independently bound | `M6CP3.DirectProductionPublishesExactSharedSupportAndA8BindsIt` |
| source/output/corner and scheduler permutations | D6 identity + `M6CP3.DirectProductionSchedulerPermutationIsSemanticNoOp` |
| G4-B002 direct candidate eligibility + hard-feature tamper | `M6CP3.DirectProducedTorusCandidateEligibilityAndHardFeatureTamper` |
| G4-B001 strict torus 3/3 | the three historical strict direct-torus product rows; first fresh M6 measurement; no validator weakening |
| G4-B004 representative A5→A6→A7→A8 chain | `M6CP3.DirectProducedTorusBindsA5A6A7A8RepresentativeChain` |

The G4-B004 identity must bind one actual direct-produced representative continuously from source authority through A5 explicit occurrence/relation, A6 exact-once selected relation, A7 materialized class/vertex, and A8 independent verification. Separate per-stage checks are insufficient.

G4-B002 uses the same direct-produced torus authority for baseline and hard-feature tamper. CP1 candidate-eligibility evidence remains prerequisite mechanism evidence, not debt closure.

G4-B001 keeps hard features out of isolation-sheet authority. Any returned `LocalSheetMismatch` is diagnosed against A7/source-support authority; validator weakening is forbidden.

#### D9 — CB sequencing and gate arithmetic — DECIDED, with one exact-name item still open

##### CP3-CB1 entry-authority implementation
Implement only D1-D4 and D7 plus these six entry identities:
1. `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`
2. `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`
3. `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`
4. `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`
5. `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`
6. `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`

Compile/package only. No CP3 direct-production acceptance TB is allowed until these execute green in the following artifact-only entry TB and independent Review accepts the entry gate.

Entry arithmetic: inherited `30 + 12 + 449 = 491` plus six entry identities = **497** fresh exact-filter processes. Preserve all inherited list/selector bytes. A later cumulative list may concatenate the accepted 30 then 12 in frozen order; it must not rewrite either authority.

##### CP3-CB2 class-wide references and direct-exit evidence
Only after entry Review, implement D5-D6 and seven remaining new identities:
7. `M6CP3.ClassWideOptimizerReferencesAreSourceOutputAndCornerPermutationInvariant`
8. `M6CP3.DirectProductionKeepsCoincidentUnrelatedClassesDistinct`
9. `M6CP3.DirectProductionConsumesEveryA5RelationExactlyOnce`
10. `M6CP3.DirectProductionPublishesExactSharedSupportAndA8BindsIt`
11. `M6CP3.DirectProductionSchedulerPermutationIsSemanticNoOp`
12. `M6CP3.DirectProducedTorusCandidateEligibilityAndHardFeatureTamper`
13. `M6CP3.DirectProducedTorusBindsA5A6A7A8RepresentativeChain`

Intended final arithmetic is inherited 491 + all 13 new CP3 identities + the frozen historical G4-B001 strict-torus 3 rows = **507** processes. This final number is not selector-freeze authority until this Definition turn records the exact three historical G4-B001 test names.

**Selector449 optimizer stop rule:** if D5 changes the outcome of any inherited selector449 optimizer/validator row, do not rewrite an expectation, delete a row, or substitute a replacement. Stop before direct-production TB and return to independent Review with the exact changed ordinals and source-level cause.

#### Remaining work before COMPLETE

1. Resolve the exact three historical G4-B001 strict-torus test names and replace the provisional 3-row reference above with exact names.
2. Append normative RA-30 to `Architecture_M6_Frozen_Definitions.md`.
3. Write the first CP3 Code+Build plan, HELD pending `M6-DEFN-R5-REV`.
4. Update ORIENTATION, TODO, ROADMAP and handoff coherently.
5. Self-audit D1-D9 against the R5 plan's lessons 199-205 before final Definition closeout.


---

#### Completion addendum — exact G4-B001 gate, method audit, and Definition closeout

A second verified runtime-free source snapshot was taken after the bounded D5-D9 addendum: workflow `37441143188`, source/event SHA `612d914d37112cbbc32b974ec30e922805c47062`, artifact `11400583983`, provider/download SHA-256 `f4b5211254ba91f6ea022e4f6072a7f3feec54aa7dc16081cd49f8ac75fa2fd0`, inner `source.tar.gz` SHA-256 `6930ae109d49c91c6e09ffe8e6c20a730ce5f0449e133c19e07d54d67c463edf`, manifest **5518/5518**, `runtimeExecution=false`. It contains the D1-D9 WIP record and confirms no production source/test/fixture/selector byte changed during Definition.

##### Exact current G4-B001 strict-direct-torus gate

The durable historical record preserves the old result only as **direct torus 0/3** at artifact `9031804178`; it does not preserve the three old exact-filter names. Do not invent historical names. Current source does expose exactly three strict production identities that independently require the committed torus path to produce rather than merely own diagnostics, and these are frozen as the CP3 G4-B001 3/3 re-proof:

1. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` (`tests/SurfaceCellsPhase10Tests.cpp:4436`; `ASSERT_TRUE(result.is_produced())` and strict final product/source-authority assertions).
2. `MilestoneGP26.TorusCompletesEndToEnd` (`tests/MilestoneGP26Tests.cpp:934`; calls `expect_completed_surface_cells(..., false)`, whose helper asserts `result.is_produced()`, `CompletedSurfaceCells`, pure quads, provenance and accepted validation at `:147-225`).
3. `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` (`tests/MilestoneGP27Tests.cpp:519`; the canonical manifest matrix includes `torus__surface_cells` and requires `EXPECT_TRUE(result.is_produced())` for every SurfaceCells case).

`ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/2` is **not** part of the strict 3/3 because that parameterized ownership test deliberately does not require production success; it only checks payload ownership if a result is produced (`MilestoneGP27Tests.cpp:569-631`). This distinction is why it receives no G4-B001 credit.

Accordingly D9 final arithmetic is now frozen as **507 fresh processes**: inherited 491 + 13 named CP3 identities + the three strict G4-B001 identities above. The P27 matrix identity is one process even though it visits every SurfaceCells manifest case. No duplicate invocation of the parameterized ownership row is added.

##### D1-D9 method self-audit

| Item | Reachable producer established | Per-conjunct falsifier | Accepted-gate edge cases checked | Bound / stop rule |
|---|---|---|---|---|
| D1 | exact-A3 periodic endpoint-state producer + A5 conjugation path | coordinate, face-gauge/branch, relation-value and orientation controls | nonzero-Z4/current storage-canonical periodic coverage | existing exact operations only; no search |
| D2 | real cross-region HardRail relation producer | endpoint gauge, placement branch, coordinate transport, reversal | nonzero matching/hard-carrier reachability required | two endpoint pairs, constant work |
| D3 | real OrdinaryFront relation + A6 collinear seam evidence | coordinate, scale, seam-transition removal/reversal, representation-only change | RA-2 seam quarter-turn semantics retained | no quotient-transport widening |
| D4 | A5 chart graph + typed source hard-feature authority | remove/add typed hard edge; inconsistent HardRail carrier | produced torus already carries PeriodicCut hard features | one immutable barrier set; no route reconstruction |
| D5 | optimizer/validator class-wide chart helpers and all representative-sensitive sites | incompatible representative/corner scope and missing common chart | RA-28b forbids selected-face membership assumption | O(total four-corner chart memberships) per quad; fixed projections under finite differences/line search |
| D6 | direct torus through real pipeline/optimizer/validator | source-row, output-row and corner-cycle permutation with non-vacuity | exact discrete equality + scaled continuous tolerance frozen | Review stop on any unexplained discrete difference |
| D7 | real A7 selected edge plus real-tracer seam-collinear witness | transition removal/tamper; HardRail cross-region labels | relation-kind dispatch prevents global sheet-ID comparison | one exact transition query; cross-region Periodic is Review stop |
| D8 | direct produced torus and direct CP3 products | named negative/tamper owner for each new rule | historical G4-B001 strict gate distinguished from diagnostic-only ownership row | no mechanism-only evidence may close direct debt |
| D9 | accepted 491 gate plus enumerated CP3 identities | exact-one selection and inherited-byte preservation | 497 entry gate; 507 final gate | selector449 optimizer outcome change is mandatory Review stop |

Lessons 199-205 are therefore satisfied without adding a hand-built substitute where a producer witness exists. Accounting remains **60 / 16 / 44**, debt **1**; `G4-B002` stays open until CP3 direct-production evidence is accepted.

#### Definition disposition

`M6-DEFN-R5` is complete as a runtime-free Definition. RA-30 is published in `Architecture_M6_Frozen_Definitions.md`, and the first implementation plan is `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`, explicitly **HELD** pending independent Review. No source, test, fixture, selector, build, package, benchmark or Directional runtime is changed or executed by this Definition.

**Mandatory successor: `M6-DEFN-R5-REV`.** Review must independently re-derive D1-D9, the 497/507 arithmetic, the three strict G4-B001 identities, and the held CB1 boundary before implementation is released.

## `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`; moved verbatim.

### M6-DEFN-R5-R1 — CP3 Entry Recovery Definition Record

**Type:** runtime-free Definition; **status:** candidate for mandatory `M6-DEFN-R5-R1-REV`, not implementation authority until accepted. **Source snapshot:** `46717738454a96ab9a379a995eb903939e7a9413` (`37711596951`, artifact `11521898273`, verified SHA-256 `7eb49a71de37808918309fc79ca810d4c471862a5d9119554f43a3a0d3adb187`). **Predecessor:** RA-32, `M6-CP3-TB1-ENTRY-R1-REV` rejected `482/497`; stable **63 / 17 / 46**, debt **1**. This is source inspection, **not** a new runtime or a claim of a proven organic witness.

#### 0. Evidence and non-negotiable boundary

`Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md:25-45` classifies the five Definition obligations; `:53-63` holds R2/CB2 until Review. All source locations below refer to the **exact** source snapshot above. Do not edit any source, test, fixture, frozen selector, build, reusable workflow, optimizer or final validator in this Definition turn. No recovery, fallback, tolerance relaxation or hand-built relation record may establish a positive witness. Frozen entry gate remains **30 + 12 + 449 + 6 = 497** fresh exact-filter processes, zero skips and zero benchmark runs; identity names/order unchanged.

#### D1 — certified OrdinaryFront isolation-seam discriminator (R1 P2)

**Evidence.** `src/pipeline/RemeshPipeline.cpp:5391-5434` currently chooses `crossSheetSeam` from equal `collinearEdge` and *unequal* `interiorBinding.sheet` **before** seeing certificate authority. This is the RA-32 domain conflation. A5 evidence is assembled at `RemeshPipeline.cpp:4999-5054`; `seam_transport_certificate()` at `:4520-4551` already matches region, carrier, endpoint selected faces and sheets. A6 checks reciprocal isolation evidence, both directed span transitions and face-gauge/transport consistency only later (`:5435-5509`).

**Candidate rule (RA-33.1).** For `SurfaceOccurrenceRelationKind::OrdinaryFront`, take the **certified special path** iff the relation's own two A5-published side spans name one identical source-edge carrier and its relation-owned isolation certificate: (i) is present, (ii) matches that carrier and both endpoint source faces, topology region and ordered endpoint sheets in either forward or reverse orientation, (iii) names distinct endpoint sheets, and (iv) is accompanied by both reciprocal side isolation evidence and directed `CornerWedgeIsolationTransition` in the two spans. Require the exact quarter-turn and coordinate/scale/phase checks already applicable; branch stripping must equal the oriented certificate's `forward()` or `reverse()`. Disjoint endpoint wedge-sheet sets remain independently required by A7. **No global sheet-ID comparison may grant the special case.** Use the product's typed relation+certificate instead of recomputing cross-sheet status from arbitrary global labels. A candidate claiming only *some* special-path evidence (unequal sheets or explicit seam transition, but absent/wrong certificate) must fail closed as missing/invalid authority: never reinterpret it as a non-seam relation to bypass a certificate requirement. A relation with no certified special-path claim takes the ordinary path and must meet the existing *full* `sourceChart`, branch, phase, scale, sheet/wedge equality. Do not change ordinary Periodic/HardRail dispositions.

**Worked positive (conceptual tuple, not a produced fixture).** A4 fronts on seam carrier `(1,4)`, selected faces `fL/fR`, reciprocal span transitions `(sheet0→sheet1)` and `(sheet1→sheet0)`, and certificate `(region r,edge(1,4),fL,fR,sheet0,sheet1,quarterTurn +1)` select the special branch only when the A6 stripped branch delta is `+1 mod 4`, both sides are reciprocal and endpoint coordinates/scale/phase satisfy existing exact requirements. **Near miss:** same collinear edge and unequal global sheets but certificate belongs to a different face pair; reject, not special and not ordinary-success. **Ordinary negative:** equal/unequal global labels without certified seam cannot waive full branch/chart equality.

#### D2 — organic reciprocal exact-A3 non-self-inverse periodic gauge witness

**Evidence.** `tests/SurfaceCellTransitionQuotientTests.cpp:1466-1545` constructs a *real* nonzero-Z4 torus `torus.obj`, finalized raw field, row408 hard rails, A3/region plan and A4; however its `select_torus_source_witness()` selects only one generator. `:1998-2045` finds produced reciprocal forward/reverse A4 edges for that one witness. Identity `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` at `:2121-2136` asserts its selected endpoints differ by odd quarter turn; R1 Review `:31-33` proves this assertion **fails**, not that no such pair exists.

**Candidate search (RA-33.2).** Construct the existing produced torus fixture without hand-edited relation records. Enumerate **all** produced `SurfacePeriodicHolonomy` relations and all their exact A3 source-generator candidates in stable canonical IDs, rather than select only the first. For each candidate, (1) require source CrossField transition matches A3 `FieldTransportAtlas::transition_value` in orientation, carrier and selected face pair; (2) require exactly one real A4 front edge in each reciprocal orientation, sharing the same source interval and reciprocal periodic relation ID, as in `produced_semantic_relation_for_witness`; (3) resolve semantic action and require correct forward/inverse route matching; (4) obtain each selected-face gauge from `SurfacePhaseFrontProduct::sourceFaceBranchRotations` and retain only `(F_b-F_a) mod 4 ∈ {1,3}`. Reject duplicates, synthetic endpoints and non-exact A3. Deterministically pick the smallest full source/occurrence/relation key, **after** all preconditions hold. Enforce non-vacuity before the identity's equality assertion. If the finite produced torus search has no qualifying pair, **stop for Review; do not weaken the 90°/270° premise, modify frozen identity count or synthesize a pair.**

**Worked comparison (illustrative, not yet observed).** Two reciprocal A4 edges with equal canonical interval `S`, source faces `(f7,f12)`, exact A3 transport and face gauges `(F7,F12)=(0,1)` qualify; gauges `(0,2)` do not (180° is self-inverse), even when both are actual periodic relations. **Outstanding proof:** existence of a qualifying organic pair has *not* been established by static inspection. Required R2 preflight checkpoint is this bounded enumeration; if empty return to Review without implementing the identity as if green.

#### D3 — HardRail branch certificate in the field-crossing τ domain

**Evidence.** RA-31a in `Architecture_M6_Frozen_Definitions.md` withdraws `C=F⁻¹◦B` because regional `F_b−F_a` is not generally field crossing `τ`; `src/pipeline/RemeshPipeline.cpp:5514-5537` presently uses rigid `canonicalTransport` for HardRail. `src/authority/FieldTransportAtlas.cpp:2020-2047` reads authoritative `CrossFieldEdgeTransition.matching`, forms forward quarter-turn and inverse, adds `FieldTransportTransitionValue` **before** marking the hard-feature carrier nontraversable. `include/directional/authority/FieldTransportAtlas.h:889-891` exposes `transition_value()` for an oriented face pair, while the A4 `SurfacePhaseFrontProduct::make()` API (`include/directional/geometry/SurfaceCellTracing.h:1783-1800`) currently publishes face gauges and hard-feature edges but not τ. A5 consumes that A4 product, not the raw A1/A3 atlas. Do not pretend A5 can infer τ from its regional gauges.

**Candidate rule (RA-33.3).** Work in the orientation of the stored A5 occurrence relation `a→b` and its `canonicalTransport`. Let `B_a,B_b ∈ Z4` be A4-published endpoint branch rotations in their *selected source faces*, `R_coord ∈ Z4` be the rotation component of A5's coordinate-rigid HardRail `canonicalTransport`, and `τ_ab ∈ Z4` be the **oriented raw cross-field matching between selected faces** along the certified HardRail source carrier or certified source-face route, with inverse `τ_ba=-τ_ab mod4`. Compose transforms right-to-left and use `R_coord ∘ τ_ab` (in `Z4`, addition). Require for **each endpoint pair**:

`B_b ∘ B_a⁻¹ = R_coord ∘ τ_ab`  (equivalently `(B_b - B_a - τ_ab - R_coord) mod 4 = 0`).

Keep existing coordinate, scale, relation-kind, rail ID, source-route and reciprocal requirements. Do **not** substitute region-relative `F` for τ; retain `firstEndpointFaceGauge`/`secondEndpointFaceGauge` as verified provenance only. Reverse relation must invert all three relevant transports; do not mix orientations. A4 is the authoritative publication owner: extend its immutable product contract with oriented `(sourceEdge,fromFace,toFace,matching)` records copied/validated against the exact A3 `FieldTransportAtlas::transition_value` (including the matching values stored even on *nontraversable* hard rails). A5 must consume only this published evidence; missing, contradictory, nonreciprocal or ambiguous matching rejects by typed, relation/site-specific fail-closed error. No unrelated producer or validator edits.

**Rail vertex path-independence.** For face fan at a shared rail vertex, derive every admissible source-chart path from selected `f_a` to `f_b`; compose each oriented τ along the path, reversing sign for reversed edges. Require equality of composed τ across **all** admissible paths, equivalently zero quarter-turn holonomy around each allowed contractible fan cycle. Do not cross source boundaries, source-component/sheet barriers, unrelated hard-feature branches or unsupported topology; if path crosses a field singularity or has nonzero/ambiguous holonomy, **reject the HardRail certificate for that pair**, do not choose the shortest path or take a mean. A certified path of multiple adjacent faces is legitimate; a missing directly adjacent face transition is not grounds for inventing a τ. At a singular rail vertex an ambiguous τ remains typed fail-closed until additional owner-reviewed path authority is defined.

**Algebraic counterexample (not yet produced):** `F_a=0, F_b=1; τ_ab=0; R_coord=1; B_a=0, B_b=1`. The τ rule accepts (`1=1+0`), but withdrawn regional strip `C_b-C_a=(B_b-F_b)-(B_a-F_a)=0` incorrectly rejects against `R_coord=1`. A real discriminating fixture must produce **exactly this structural inequality** (`F_b−F_a != τ`, though numerical values can differ): extend the already real-produced `make_nonconstant_hard_rail_fixture` (3×3 vertices, two midline user hard edges, nonconstant XY/90° field; `tests/SurfaceCellTransitionQuotientTests.cpp:684-749`) with a *finite deterministically ordered* set of rail locations, face-gauge roots, and raw-field rotations. Build through `remesh_from_raw_cross_field` using fail-closed/no recovery, require green real A4 and A5, and select a real cross-region HardRail with unequal published `F` and τ, existing coordinate-rigid relation, and rule satisfied for both endpoints. **Outstanding proof:** the R1 run could not find even an odd F-pair (`R1 Review:35-37`), so the discriminating produced witness is *not yet established*; stop for Review if bounded real production yields none.

#### D4 — tracer-produced seam-collinear OrdinaryFront for D3/D7

**Evidence.** The present `split_isolation_fixture()` (`tests/SurfaceCellTransitionQuotientTests.cpp:393-418`) uses a two-triangle square split on the diagonal `(0,2)` but a constant XY cross; the special OrdinaryFront helper at `:2100-2116` finds none. R1 review `:39-41` records D3 and D7 non-vacuity failures. An isolation certificate alone is not proof of seam-aligned traced cells. D7 test at `:2549-2610` additionally requires disjoint `cornerWedgeSheets` and an A6-selected relation followed by valid A7; it removes certified isolation evidence to verify `UncertifiedCrossSheetBinding`.

**Candidate real-tracer construction (RA-33.4).** Replace the D3/D7 witness search with a bounded family of **axis-aligned internal seam** planar rectangles whose front direction can actually follow the seam. Representative 2×1 strip: vertices `(0,0),(1,0),(2,0),(0,1),(1,1),(2,1)` (IDs 0–5), CCW triangles `(0,1,4),(0,4,3),(1,2,5),(1,5,4)`, left/right face sheets `0/1`, one connected component; seam carrier `(1,4)` vertical; normal XY cross arms, target sizing candidate set `{0.25, 0.5, 1.0}`; vary only documented, deterministic seeding and source-face order if needed. For every **real `build_surface_cell_network` product**, run **real** A5 and enumerate reciprocal `OrdinaryFront` relations. Accept a fixture only if both endpoint source spans name `(1,4)`, an A4-supplied exact isolation-seam certificate matches selected source faces/sheets, both reciprocal side isolation transitions exist, the relation is actually used by A6 and D7's endpoint wedge-sheet sets have empty intersection, and real A7 completes with no uncertified cross-sheet binding. Do not make a synthetic relation, manually change a source span, or declare success merely because a seam was added. Record the exact fixture rows, source face IDs, span, quarter-turn and relation IDs in the later R2 report.

**Distinct falsifiers:** D3 tamper only one direction's seam quarter-turn or reciprocal side transition and require an exact A6 certificate error while original produced positive remains green; D7 leave A6 selection unchanged, remove the A5-owned side isolation evidence, require A7 `UncertifiedCrossSheetBinding` at `cross-sheet`. Additional near miss: same mesh and seam but a front edge not collinear must retain strict ordinary equality. **Outstanding proof:** no such organic seam-collinear produced witness exists in the currently reviewed R1 evidence; an axis-aligned *input* is an explicit search proposal, not a proven positive. If candidate family produces no exact positive, stop for Review.

#### D5 — ordinary hard-feature barrier falsifier on an actual A4 route

**Evidence.** Current identity 4 selects first `OrdinaryInterior` edge and *then* asserts non-empty route (`tests/SurfaceCellTransitionQuotientTests.cpp:2521-2544`), which R1 Review `:43-45` disproves. `SourceChartTransitionGraph` must consume typed protected source carriers rather than global component IDs.

**Candidate oracle (RA-33.5).** In an actually produced A4 `SurfacePhaseFrontProduct`, enumerate `edges()` sorted by stable IDs. Select an edge only when: (i) `boundaryKind==OrdinaryInterior`, (ii) `route` is present and nonempty, (iii) `route.steps().front().topology()` resolves to a genuine interior source carrier with two faces and a legal source-chart transition, (iv) the carrier is not already in `hardFeatureEdges`, and (v) its transition exists in the baseline `SourceChartTransitionGraph` at that exact typed source pair. Then add *only* this carrier to the A4 draft's typed hard-feature set and reconstruct the graph. Require that exact carrier transition absent/nontraversable while an unrelated unmarked carrier remains, without accepting mere component-label coincidence. In a separate source-preserving negative, remove a **real** required HardRail hard-feature carrier and expect `InvalidHardRailAuthority`; retain the genuine PeriodicCut hard-feature barriers and source-chart checks. If no route-bearing ordinary carrier exists, produce a real traced fixture by finite bounded input/seeding variation; **stop for Review** if still none.

**Worked example (illustrative only):** produced edge `OrdinaryInterior` with `route=[(sourceEdge 1–4, forward)]`, chart transition `(fL→fR)` and no hard feature at `1–4` permits baseline traversal; after adding exactly `1–4`, the chart transition must be blocked. A produced `OrdinaryInterior` with `route=[]` is **not** a candidate and cannot satisfy D4. Do not modify A5 hard-feature authority itself to manufacture coverage.

#### Decisions, stop gates and handoff

All five rules are **defined**, but source inspection establishes **none** of the new organic D2/D3/D4 positive witnesses; exact replay of the reviewed 482/497 is not a proof of their existence. Therefore this is a **conditional RA-33 candidate**, not an accepted Definition or authorized R2 launch. The independent `M6-DEFN-R5-R1-REV` must determine whether the explicit bounded fixture/search recipes discharge RA-32's proof requirements or issue a stop/return with additional producer authority. If Review insists on already-produced positive witnesses, **do not release R2**. No source/fixture/test edits or runtime execution were performed in this Definition.

Only after Review explicitly approves all five semantic contracts and the bounded real-producer witness policy may it release **one** held plan: `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md`. Then one compile-only all-eight GMP/GMPXX run, exactly one immutable 497-process artifact-only gate, and mandatory R2 Review; no CB2 or direct-production gates before acceptance. Stable accounting remains **63 / 17 / 46**, produced-witness debt **1**.

---

#### Independent verification addendum (reviewing agent)

Runtime-free architecture review. **Not accepted as written. D2, D4 and D5 are sound; D3 is architecturally
right with one gap in its discriminating structure; D1 has a concrete orientation hole and an unaddressed
inverse conflation.** Three findings, all re-derived from source.

##### A1 — D1: the certificate lookup discards which orientation matched, so the rule's two disjunctions can be satisfied inconsistently

D1 requires (ii) the certificate match carrier, both endpoint source faces, region and ordered endpoint sheets
"**in either forward or reverse orientation**", and separately that "branch stripping must equal the oriented
certificate's `forward()` or `reverse()`". Those are two independent disjunctions, and the code makes the
independence real rather than theoretical.

`seam_transport_certificate(...)` (`src/pipeline/RemeshPipeline.cpp:4520-4551`) computes

```cpp
const bool forward = certificate.firstFace() == firstOccurrence.placement.selectedFace && …;
const bool reverse = certificate.secondFace() == firstOccurrence.placement.selectedFace && …;
if (forward || reverse) return certificate;
```

It returns **only the certificate**, discarding the orientation that satisfied the identity match. A caller
therefore cannot know whether it matched forward or reverse, and D1's branch-strip clause is free to succeed
against the *other* orientation. A relation whose faces and sheets match reversed while its transport matches
`forward()` satisfies both clauses and is granted the certified special path — on an inconsistent orientation
pairing that waives full `sourceChart`/`branchRotation` equality.

This is the same conflation class that cost M5-CP3 fifteen turns, and **D3 already states the guard**: "Reverse
relation must invert all three relevant transports; do not mix orientations." D1 omits it while carrying the same
hazard.

**Required before acceptance:** D1 must bind one orientation. `seam_transport_certificate` returns the matched
orientation alongside the certificate (or two typed accessors), and the branch-strip, quarter-turn, coordinate,
scale and phase checks are evaluated against **that** orientation only. A certificate matching in one orientation
whose transport matches the other is missing/invalid authority and fails closed under D1's own clause.

##### A2 — D1: global sheet labels are forbidden from granting the special case but still gate its discovery

D1's diagnosis is correct and I confirmed it at the decision site (`:5400-5403`):

```cpp
const bool crossSheetSeam =
    firstSpan.collinearEdge.has_value() &&
    firstSpan.collinearEdge == secondSpan.collinearEdge &&
    firstSpan.interiorBinding.sheet != secondSpan.interiorBinding.sheet;
if (!crossSheetSeam) { /* only here is full sourceChart + branchRotation equality required */ }
```

No certificate is consulted; arbitrary global label inequality alone waives full representation equality. That is
RA-32 exactly.

But the same unsound proxy appears a second time, in the helper D1 cites approvingly. `seam_transport_certificate`
opens with `firstSpan.interiorBinding.sheet == secondSpan.interiorBinding.sheet → return std::nullopt` — label
inequality is a **precondition on even looking for a certificate**. D1 forbids global sheet comparison from
*granting* the special case and says nothing about it *denying* one. If global labels are not a sound proxy for
cross-sheet status — which is RA-32's whole premise — then a genuinely certified seam whose two spans happen to
carry equal labels is never discovered, and the relation silently takes the ordinary path. Removing the
conflation in the granting direction while leaving it in the denying direction converts a false positive into a
false negative built on the same error.

Note the asymmetry is also a correctness question for D1's own condition (iii): "names distinct endpoint sheets"
is a property of the **certificate's** `firstSheet()/secondSheet()`, not of the spans' global labels. Those are
different claims and D1 should say which one governs. Recorded as `M6-DEFN-R5-R1-REV-OBS-01`.

##### A3 — D3 is the right architectural call, but its single discriminating structure cannot falsify τ's orientation

The core decision is correct and worth stating plainly: A5 must **not** infer τ from its regional gauges, and A4
becomes the publication owner for oriented `(sourceEdge, fromFace, toFace, matching)` validated against exact A3
`transition_value`. That is sound because the data provably exists before exclusion —
`src/authority/FieldTransportAtlas.cpp:2020-2047` adds the `FieldTransportTransitionValue` *before* marking the
hard-feature carrier nontraversable — the same retain-then-exclude structure established at M5-CP3 §15. Refusing
to let a consumer re-derive a quantity it does not own is the correct reading of RA-31a's withdrawal of
`C = F⁻¹∘B`.

The rail-vertex path-independence requirement is also right, and unusually well specified: compose oriented τ
along every admissible source-chart path, require equality across all of them (zero quarter-turn holonomy around
each contractible fan cycle), reject on singularity or ambiguity, and explicitly **"do not choose the shortest
path or take a mean."** Those are the two shortcuts a holonomy condition invites, and both are closed.

The gap is in the witness. The proposed algebraic structure is `F_a=0, F_b=1; τ_ab=0; R_coord=1; B_a=0, B_b=1`.
It discriminates well on two axes — `F_b−F_a = 1 ≠ 0 = τ` proves τ replaced regional `F`, and `R_coord = 1` is
odd so its **sign** is falsifiable. But **τ_ab = 0 is self-inverse**, so this witness cannot distinguish `τ_ab`
from `τ_ba = −τ_ab`. The rule insists in the same paragraph that "reverse relation must invert all three relevant
transports"; the only proposed discriminating structure cannot test that for τ.

**Required:** the bounded fixture family must include at least one qualifying witness with `τ_ab ∈ {1,3}`, so the
τ orientation the rule mandates is falsifiable rather than assumed. A green result on a τ=0 witness proves the
τ-versus-`F` substitution and `R_coord`'s sign, and nothing about τ's direction.

One related note worth recording so it is not later mistaken for validation: because `Z4` is abelian, the stated
convention "compose transforms right-to-left and use `R_coord ∘ τ_ab`" is **numerically inert** — the equation
`(B_b − B_a − τ_ab − R_coord) mod 4 = 0` is symmetric in the two terms. No `Z4` test can falsify the composition
*order*; only the *signs* are testable. The order must therefore rest on domain semantics, and no passing fixture
should be cited as confirming it. Recorded as `M6-DEFN-R5-R1-REV-OBS-02`.

##### A4 — D2, D4 and D5 are sound, and their premises are derived rather than asserted

**D2.** The `(F_b − F_a) mod 4 ∈ {1,3}` premise is correctly derived, not arbitrary: a 180° transform is its own
inverse, so a gauge difference of 2 cannot discriminate forward from reverse and is useless for the identity's
purpose. Excluding `{0,2}` is therefore required, and the instruction not to weaken it is right. Enumerating
**all** produced relations instead of the first, requiring the four preconditions, picking the smallest key
**after** preconditions hold, and enforcing non-vacuity before the equality assertion together remove the
select-then-assert ordering defect that made the original identity fail. The admission that a qualifying organic
pair is "**not** established by static inspection", with a stop gate rather than synthesis, is the correct
epistemic posture.

**D4.** I checked the proposed geometry rather than assuming it, because a mis-specified fixture costs a turn.
Vertices `0..5 = (0,0),(1,0),(2,0),(0,1),(1,1),(2,1)` with triangles `(0,1,4),(0,4,3),(1,2,5),(1,5,4)`: the seam
carrier `(1,4)` is the vertical edge at `x=1`, shared by exactly two faces — `(0,1,4)` on the left and `(1,5,4)`
on the right — so it is a genuine interior edge with one face per sheet. All four triangles are counter-clockwise
(signed areas all `+1`). The construction is geometrically valid and the seam is real.

**D5.** This correctly inverts a selection-before-precondition defect: the old identity picked the first
`OrdinaryInterior` edge and *then* asserted a non-empty route. Requiring route presence, a genuine two-face
interior carrier, a legal source-chart transition, absence from `hardFeatureEdges` and existence in the baseline
graph *as selection conditions* is the right ordering. Rejecting "mere component-label coincidence" closes the
same global-ID proxy that A2 above flags elsewhere, and the unrelated-unmarked-carrier control distinguishes
"this carrier became nontraversable" from "the graph broke".

##### A5 — verification limits

Re-derived from repository bytes: `seam_transport_certificate`'s forward/reverse computation and its
orientation-discarding return; the `crossSheetSeam` decision site and its label-only waiver; the
`FieldTransportAtlas` retain-before-exclude ordering; D4's fixture coordinates, edge incidence and triangle
winding; and the `Z4` symmetry of D3's equation. Not verified: whether any qualifying organic witness exists for
D2, D3 or D4 — each is an open search by the record's own admission, and all three carry stop gates.

## `Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md`; moved verbatim.

### M6-DEFN-R5-R2 — CP3 Entry Recovery Definition Amendment (RA-34 candidate)

**Turn:** `M6-DEFN-R5-R2`, runtime-free Definition. **Predecessor:** independent `M6-DEFN-R5-R1-REV` rejected RA-33 as written; see its review addendum. **Status:** candidate only, not accepted implementation authority.

**Verified exact-source inspection:** SHA `f3ae67ade2ac37f00d2317d0de007aaf959f8969`, source-snapshot workflow `37717936915`, artifact `11524367318`, ZIP SHA-256 `ea7668b79705f0fa489b7b6f21a05d09b02a43b9b0545bfc900544396de7901d`. No source, test, fixture, selector, build or generated Directional runtime was modified or executed.

#### Scope

Amend only RA-33.1 (D1, certified OrdinaryFront) and RA-33.3 (D3, HardRail cross-rail transport). RA-33.2 (D2 organic periodic odd-gauge), RA-33.4 (D4 real traced seam-collinear relation / D7) and RA-33.5 (D5 genuinely route-bearing ordinary carrier) remain unchanged, with no fabricated produced positives. Accepted routing authority remains RA-32. The sole `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` remains **HELD** pending independent `M6-DEFN-R5-R2-REV`.

#### D1 — bind certificate and all seam checks to one typed orientation (RA-34.1)

**Observed source contradiction.** In `src/pipeline/RemeshPipeline.cpp:4520-4551`, the `seam_transport_certificate` helper rejects lookup when the two spans' global `interiorBinding.sheet` labels compare equal, then evaluates both forward/reverse face-sheet matches but returns only a certificate on `(forward || reverse)`. At `:5400-5403`, a shared collinear source edge plus differing raw sheet labels can grant the special seam branch without the certificate. At `:5445-5505`, branch validation independently selects certificate orientation. Thus raw sheet labels both wrongly grant and deny admission, and different conjuncts can use different certificate orientations. Review finding: `M6-DEFN-R5-R1-REV-OBS-01`.

**Normative candidate:**

1. Recognize a candidate from **real reciprocal collinear side spans** with the same topology region, canonical source edge, and precise A4-published face/side incidence. Look up the A4-owned certified isolation-seam transport without comparing the raw/global endpoint sheet-label IDs. Neither equality nor inequality of those IDs grants, denies, or bypasses lookup.
2. The certificate's `firstSheet()/secondSheet()` must themselves describe **distinct** typed endpoint sheet authorities. Establish their ordered connection to the selected source faces through **independent A4-owned wedge/sheet-incidence or isolation-transition evidence**, not by assuming the raw labels are comparable or by inferring sheet identity from component, proximity, or the relation under examination. If A4 does not actually publish enough evidence, stop fail-closed and seek a producer-owned A4 contract amendment through independent Review. Do not manufacture an A6 mapping.
3. Return one *oriented* matched object `(certificate, Forward|Reverse)` (or a mechanically equivalent type) after checking source edge, endpoint faces, ordered certificate sheets and reciprocal side incidence. Reject missing, ambiguous, contradictory, duplicate or nonreciprocal matches with an owning typed error.
4. Use **that same orientation** for source-face transitions, endpoint/corner wedge sheets, coordinate transition, phase, scale, branch quarter-turn, and both reciprocal isolation-side checks. The reverse orientation must use `certificate.reverse()` consistently. A mismatch of face orientation and branch orientation is never rescued by selecting an independent opposite orientation for another conjunct.
5. Only a fully certified, same-orientation relation may enter the special cross-seam branch and waive the ordinary full representation-equality rule. Partial or contradictory purported seam evidence must fail closed rather than silently degrade to ordinary matching. A genuine non-seam OrdinaryFront preserves full source-chart, branch, phase, scale and sheet equality. A7 separately verifies its own disjoint-wedge-sheet obligations and cannot be presumed green from A6.

**Required falsifiers (later Code+Build / separately authorized immutable TB; not executed here):**

- A true tracer-produced reciprocal seam-collinear OrdinaryFront with an A4 certificate, A4 typed wedge-to-certificate sheet witness, correct bound orientation and independent A7 positive. Without that production, the positive remains unproven and the gate is RED.
- A mixed-orientation negative: certificate forward quarter-turn 1, reverse 3, relation faces/sheets match only Reverse, but branch strip is forward 1. Must reject (expected reverse 3). Tamper one selected face, reciprocal side transition, branch turn, coordinate, phase or scale at a time while preserving the other independent receipts.
- Unequal raw/global sheet labels and no certificate must **not** grant special matching. Equal labels must **not** suppress lookup; positive admission additionally requires A4's typed cross-sheet evidence. Noncollinear relations remain strict ordinary relations despite unequal labels.
- Reverse face order, source row order and scheduler permutations must preserve a deterministic typed orientation and verdict. Non-vacuity must be checked before downstream certificate assertions.

This is a Definition only. If the current immutable A4 product cannot supply the oriented sheet-incidence proof, the implementation must stop for Review rather than introduce an unsupported recovery heuristic.

#### D3 — odd oriented τ discriminator for HardRail (RA-34.3)

**Retained source basis.** `src/authority/FieldTransportAtlas.cpp:2020-2047` stores `FieldTransportTransitionValue` before marking hard rail edges nontraversable. The exact A3 `transition_value` is oriented by source edge and ordered incident face pair. A4 must publish independently verified oriented `(sourceEdge,fromFace,toFace,matching)` entries as immutable product authority; A5 consumes them. Regional face gauges `F_a,F_b` are independent provenance, not a substitute for crossing transport `τ_ab`. For rail-vertex continuation, compose all admissible source-chart routes; disagreement, singularity or nonzero holonomy is a typed failure, not permission to take a mean/shortest route. Review finding: `M6-DEFN-R5-R1-REV-OBS-02`.

**Normative candidate:** For an actually produced reciprocal HardRail relation between oriented endpoint faces `f_a → f_b`, require

```text
(B_b - B_a - R_coord - τ_ab) mod 4 = 0
τ_ba = (-τ_ab) mod 4
```

and independent reversed-relation validation with inverse coordinate, branch and τ orientations. The produced, baseline-green witness must satisfy **both** `(F_b-F_a) mod 4 != τ_ab` and `τ_ab ∈ {1,3}`. `τ=0` or `τ=2` is self-inverse in Z4, so cannot test the orientation/sign of crossing τ.

**Algebraic counterexample, NOT produced evidence:** `F_a=0, F_b=3, τ_ab=1, τ_ba=3, R_coord=1, B_a=0, B_b=2`. Forward: `B_b-B_a = 2 = R_coord+τ_ab (mod 4)`. Substituting regional F yields `(B_b-F_b)-(B_a-F_a)=3 != R_coord=1`, and reversing τ while retaining coordinate orientation yields `R_coord+τ_ba=0 != 2`. The actual inverse relation has `B_a-B_b=2`, inverse coordinate 3, inverse τ 3, and `3+3=2 (mod 4)`. These calculations show discrimination **algebraically only**, not real-producer reachability.

**Produced-witness protocol (implementation/TB, not this Definition):** Extend the existing real nonconstant two-region HardRail fixture in `tests/SurfaceCellTransitionQuotientTests.cpp:684-749`. Deterministically bound a finite family of rail edges, raw-field quarter turns, face-root choices and face-row permutations. Run the real A1/A3→A4→A5 producer chain. Enumerate all actual reciprocal HardRail relations and select by stable source-edge/relation key only **after** verifying published endpoint gauges, exact oriented A3/A4 τ authority, the F/τ inequality, odd τ, baseline A5 coordinate and reciprocal validation and any required real A7 receipt. Record `sourceEdge, fromFace, toFace, relationId, F_a, F_b, τ_ab, τ_ba, R_coord, B_a, B_b`. Tamper only τ orientation/sign with the rest green; separately invert or permute source face order and require canonical results. If the bounded family produces no odd τ plus independent F/τ inequality, stop for independent Review; do not fabricate relation objects, weaken to self-inverse τ, or claim the gate passed.

**Algebraic limit:** Z4 is abelian. An equality cannot prove whether `R_coord` was composed before or after τ. Right-to-left composition order remains a *typed semantic convention*; numeric falsifiers prove signs, inversion and source-oriented domain only. Do not claim that a passing test proved composition order.

#### Carried obligations and release gate

- RA-33.2: organic exact-A3 nonzero-period torus pair with a 90°/270° face-gauge difference; no produced positive yet.
- RA-33.4: actual tracer-produced seam-collinear OrdinaryFront with independent certificate and D7 disjoint endpoint wedge-sheet validation; no produced positive yet.
- RA-33.5: actual source-route-bearing OrdinaryFront carrier and protected-barrier negatives; no produced positive yet.
- Frozen exact entry gate **497 = focused30 30 + focused12 12 + selector449 449 + CP3-entry 6**; latest rejected candidate **482/497**. Stable accounting **63 events / 17 categories / 46 recurrences**; one M6 produced-witness debt. Reviewed CP2 package **11391685901**, source **5ce3132ec01748eff5b15f82be07a1abe2bd1af6**, 491/491.
- Next authorized turn: **independent runtime-free `M6-DEFN-R5-R2-REV`**, to accept/amend/reject RA-34 and independently verify whether A4's typed sheet incidence is sufficient. This Definition never releases R2 Code+Build or CB2. The held plan remains held until explicit Review approval; missing real-producer authority is a stop, not accepted evidence.

## `Architecture_M6_DEFN_R5_R2_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R2_Review_Record.md`; moved verbatim.

### M6-DEFN-R5-R2-REV — Independent Definition Review (RA-34)

**Verdict: ACCEPT RA-34 as a bounded Definition only.** Exactly one authorized successor is `M6-CP3-CB1-ENTRY-R2` Code + Build (compile/package only), conditional on mandatory producer-owned stop gates. This Review made no code/test/fixture/selector/build changes and executed no Directional binary, compile, test or benchmark.

**Verified source authority:** exact SHA `48370d9913b40b3e42299082188ea404af4c7ca1`, source snapshot run `37723060299`, artifact `11526935503`, outer digest `17690c9726e66fc4499bb71bf8146384ca27dbc71a5ff76a190953c53c83572c`, exact source archive/manifest verified. Subsequent branch commits before this Review touch control-plane STATUS/trigger/mailbox only.

#### Independently adjudicated findings and falsifiers

**`M6-DEFN-R5-R1-REV-OBS-01` — Definition discharged, production recovery open.** In `src/pipeline/RemeshPipeline.cpp:4520-4551`, the old helper refuses certificate lookup when raw/global sheet IDs are equal, and returns only a certificate on independent `forward||reverse` disjunction, discarding selected orientation. `:5400-5403` grants `crossSheetSeam` from unequal raw labels and collinear edge without certificate; `:5445-5505` chooses branch transport orientation separately. RA-34.1 corrects *both* proxy directions: raw label equality/inequality may neither grant nor deny lookup. One `(certificate, Forward|Reverse)` must consistently bind selected face, typed endpoint/corner wedge sheets, branch quarter turn, coordinate, phase, scale, source-chart and both reciprocal side transitions. Partial, contradictory and mixed-orientation evidence fails typed, not ordinary fallback; genuine non-seam OrdinaryFront still requires full representation equality. A7 disjoint wedge-sheet proof is independent, never assumed from A6.

**Mandatory independent A4 preflight:** `SurfaceCellTracing.cpp:16670-16820` constructs isolation certificates from typed A4 region source-face/sheet authorities. Certificate construction checks distinct `firstSheet/secondSheet`, carrier/face and reciprocal transition. A6 `RemeshPipeline.cpp:3917-3930` obtains A4-owned face/sheet binding; `:3990-4048` derives oriented source-edge selected face; `:4140-4255` checks side/transition incidence. This is a plausible input evidence chain, NOT an already-published wedge-to-certificate table or proven real-produced seam-collinear positive. Before accepting a special A6 relation, independently prove every selected endpoint/corner wedge maps to precisely one oriented A4 certificate sheet, without using A5 relation self-certification, raw global label, component coincidence or geometric proximity. If A4 evidence is insufficient/ambiguous: **STOP for A4 producer-owned independent Review**; do not invent an A6 mapping. Frozen negatives: certificate forward=1/reverse=3, faces/sheets matching only Reverse but branch=forward1 MUST reject; also equal-label positive lookup without false denial, unequal-label uncertified rejection, noncollinear strict control, each coordinate/phase/scale/side/source-face tamper and deterministic face/scheduler permutations. Require a **true tracer-produced A4 OrdinaryFront and independent A7 positive**, else RED.

**`M6-DEFN-R5-R1-REV-OBS-02` — Definition discharged, produced τ witness open.** `src/authority/FieldTransportAtlas.cpp:2020-2047` stores exact oriented `FieldTransportTransitionValue` before marking HardRail source edges nontraversable. A4 must publish the exact oriented `(sourceEdge,fromFace,toFace,τ_ab)`; A5 must consume this, NOT infer τ from independent regional face gauges F. Require `(B_b−B_a−R_coord−τ_ab) mod4=0`, inverse `τ_ba=(-τ_ab) mod4` and source-path consistency at rail vertices; no averaging, arbitrary route or singular holonomy waiver.

The RA-34 algebraic discriminator `F_a=0,F_b=3,τ_ab=1,τ_ba=3,R_coord=1,B_a=0,B_b=2` was independently recalculated: forward `(2−0−1−1) mod4=0`; `F_b−F_a=3≠1=τ_ab`; wrong inverse τ in forward direction gives `(2−0−1−3) mod4=2` (reject). Actual inverse has branch difference 2, coordinate inverse 3, τ inverse 3, so `(2−3−3) mod4=0`. τ is odd/non-self-inverse, fixing the old τ=0 test hole. This is **only algebra**, no produced witness. Z4 is abelian, so numeric tests can prove orientation signs but not composition order; ordering rests on typed semantic domains.

**HardRail produced stop:** enumerate a finite canonical family of true A1/A3→A4→A5 reciprocal HardRail relations; require independently `(F_b−F_a) mod4 != τ_ab` and `τ_ab ∈ {1,3}`, baseline-green coordinate/reciprocal/source validation, then sign-invert τ while keeping other evidence green and require rejection. Record exact source/face/relation/τ/F/branch receipt. No real witness → STOP for Review; do not synthesize one or use self-inverse τ.

**Other prior obligations carried unchanged:** D2/RA-33.2 searches every real reciprocal source/A3-exact periodic torus relation and selects only after full matching/route checks and ±1 quarter-turn selected-face gauge difference; if absent STOP. D4/D7/RA-33.4 requires a true seam-collinear **tracer-produced** OrdinaryFront and independent A7 disjoint sheet positive, with separate A6 branch and A7 evidence tamper; input seam geometry alone does not count. D5/RA-33.5 selects an actual route-bearing ordinary A4 edge with eligible source-carrier transition, verifies typed hard-feature injection removes it while an unrelated carrier remains and PeriodicCut/HardRail protections remain; if absent STOP. No synthesized record, loosened test precondition, or selector mutation is authorized.

Reviewed CP2 source/package `5ce3132ec01748eff5b15f82be07a1abe2bd1af6 / 11391685901` remains 491/491; R1 entry candidate remains **482/497 rejected**. Frozen next gate `497=30+12+449+6` exact independent processes, zero skips/benchmark zero. Selector449 independently rehashed: 449 lines, SHA256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. Stable accounting **63 events / 17 categories / 46 recurrences**, debt 1; `RP-01` still open. No organic witness is promoted by a runtime-free Definition Review.

#### Exact successor and turn boundary

Release **only** `M6-CP3-CB1-ENTRY-R2`, with prescriptive preflight above and reviewed single R2 Code+Build plan. Compile-only eight GMP/GMPXX targets using durable dispatcher; execute no Directional binaries in CB. If GREEN, separate immutable `M6-CP3-TB1-ENTRY-R2-EXEC` 497-process artifact-only TB, then mandatory `M6-CP3-TB1-ENTRY-R2-REV`. CB2 and CP3 exit remain HELD.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Frozen 449 rows, SHA256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; no new prefix or selector. |
| Decisive claims independently re-derived | D1 helper/branch source; A4 typed sources; D3 A3 τ storage and odd Z4 inverse arithmetic. |
| Non-vacuity checked | Negative discriminators specified; real-produced D2/D3/D4/D5 positives NOT proved and stop-gated. |
| Prior obligations discharged/carried | OBS-01/02 Definition-only discharged; RP-01, A4 mapping, D2/D3/D4/D7/D5 organic witnesses carried to CB1. |
| Stable accounting | 63/17/46, debt 1, reviewed CP2 491/491, rejected entry 482/497; selector449 unchanged. |
| New candidates/obligations recorded | No new stable event; typed A4 and real-positive stops recorded with prior OBS in tracker. |
| ORIENTATION currency line | R2 Review 2026-10-08 added. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 CP2 closure/current candidate, §4 no witness promotion, §7 R2 exact successor, §8 existing lessons 199/200/206/207. |
| CHANGELOG | R2 Review entry published. |
| ROADMAP | Live routing updated. |
| Selector manifest | n/a; no selector addition or acceptance. |
| LESSONS | Existing 199/200/206/207; no new category. |
| Consolidation under CLEAN_UP_POLICY | Status folded into M6 consolidated record; historical durable docs retained (live references). |
| Successor frozen | Exactly M6-CP3-CB1-ENTRY-R2 under RA-34 with prescriptive stop gates here and in released plan. |
| Turn boundary held | Documentation only; no source/test/build/fixture/selector/runtime mutation or execution. |
| review_check.py boundary | PASS on snapshot-derived uncommitted documentation diff; source/test/selector guards all green. |
| STATUS lifecycle maintained | Entry IN_PROGRESS beacon written; final COMPLETE beacon after all review documentation/cleanup. |
| Pushed to origin, branch in sync | Atomic Git-tree CAS publication completed, independently compared changed paths against the frozen snapshot; post-publication GitHub branch authority is checked before final STATUS. No embedded future commit SHA is asserted. |

## `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md`; moved verbatim.

### M6-DEFN-R5-R3 — CP3 R2 Recovery Definition, candidate RA-37

**Boundary:** runtime-free Definition candidate, **not frozen or implementation authorization**. Independent `M6-DEFN-R5-R3-REV` must adjudicate this contract before any Code + Build. Source inspection: verified snapshot SHA `fade2a964355adeb4c94d5fc28f322343e60abae`, workflow `37775140381`, artifact `11549232451` (outer SHA-256 `27944c2fedc41f9d67670ed135a6bd9ee00ed862ff4d7d7d75f06fefc896949c`, source manifest 5658/5658). No Directional binaries/builds/tests executed in this Definition.

#### D0 — immutable evidence perimeter

- Accepted CP2 semantic source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6` **491/491**; rejected R1 **482/497**; rejected R2 semantic source `80fc1688f13e5ed52699177a845f25cc4dbda38b` **444/497** (15/30 focused30, 10/12 focused12, 419/449 selector449, 0/6 CP3 entry). R2 result artifact `11545716507` / run `37767144537` ZIP SHA-256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`; this turn independently checked its outer ZIP and **1019/1019** internal SHA256SUMS plus the 497-row ledger with 53 RED entries. Full CP2/R1/R2 checksum and per-identity comparison remains the independent R2 Review's authority; it is not represented as freshly re-executed here.
- R2 Review's exhaustive, nonoverlapping 53: **25** A4 `InvalidHardRailRouteCertificate` direct; **12** Phase10 downstream provisional; **5** periodic D1 produced-witness absent; **6** inherited A5/A6 torus recovery RED; **2** D3/D7 seam-collinear produced-witness absent; **1** D5 ordinary route baseline absent; **2** RE-package terminal-code downstream provisional. R1→R2 38 new RED, no recoveries. **47 distinct formerly accepted CP2 identities** are now RED and must all recover, independently of any six added CP3 identities. One new stable A4 event is `RP-01/AUTHORITY_DOMAIN_CONFLATION`, *not* 25 events; pre-existing A6 RP-01 remains open. Ledger **64 events / 17 categories / 47 recurrences; produced-witness debt 1**; no new increment in this Definition.
- The 3×3 fixture at `tests/SurfaceCellTransitionQuotientTests.cpp:495-552` has legal user HardRail carriers `(1,4)` and `(4,7)`, incident source faces `{0,3}` and `{4,7}` respectively. They meet at vertex 4 with no common face. This **falsifies RA-36.1's necessary common-face premise for supported inputs**, not existence of an actually produced two-step paired route; R2 logs do not identify which predicate first rejected each route. RA-36.1 remains marked unsound/under review in frozen definitions, not silently rewritten.

#### Source facts and authority gaps

- `include/directional/geometry/SurfaceCellTracing.h:1477-1504`: `SurfaceHardRailFieldTransition` carries `{edge, firstFace, secondFace, firstToSecond}`; route endpoint certificate holds attachments, oriented steps and one composed turn; paired certificate contains two endpoint records. No path-witness fields for the two face-star sides yet.
- `src/geometry/SurfaceCellTracing.cpp:18115-18205`: `railFanPotentials` visits **all** source-edge-connected faces at each rail vertex, including crossing hard edges; it proves a path-independent Z4 potential over the entire raw vertex star when possible. It does **not** publish the ordered topology of each side sector or prohibit crossing an unrelated rail during a side transport. Potentials alone therefore cannot certify a particular same-side path.
- `src/geometry/SurfaceCellTracing.cpp:18260-18372`: `endpoint_certificate` folds `current` across each crossing χ and requires `current == next.firstFace/secondFace` on each subsequent rail carrier; only afterward attempts `phiA/phiB` and checks the commuting square. This wrongly replaces along-side movement with immediate identical-face adjacency, and makes the existing fan check unreachable for valid disjoint-carrier face pairs.
- `include/directional/authority/FieldTransportAtlas.h:886-895` and `src/authority/FieldTransportAtlas.cpp:3080-3090`: A3 `transition_value(sourceEdge, fromFace, toFace)` supplies directed angular matching **without traversal-adjacency authority**. Its reciprocal can be checked; it does **not by itself choose** left/right fan sectors, chart membership or hard-rail owner. A4 must derive and certify those from A2b source topology, oriented face incidence and typed feature ownership before requesting A3 transport. This is a **mandatory producer-owned topology proof**, not a claim that A3 already contains a side-path API.
- `src/pipeline/RemeshPipeline.cpp:4932-4990`: A5 looks up the paired A4 certificate, checks **both** occurrence `placement.selectedFace` attachments, then enforces `to.branchRotation-from.branchRotation = R_coord ∘ published.composedTurn` at each endpoint pair, followed by the existing coordinate transform checks. It must continue consuming A4 publication only.

#### RA-37 candidate — ordered, source-attached two-side transport (not normative until reviewed)

**RA-37.1 — Topological path domains.** For a canonical directed HardRail carrier sequence `e_0 ... e_(n-1)` in an A4 real produced paired route, record the **ordered typed source edge keys** and the shared endpoint vertex `v_i = e_i ∩ e_(i+1)` (for each distinct consecutive carrier). Validate owners, source-component/region membership, hard-feature graph direction and absence of foreign-rail crossings. The route is not an arbitrary source-edge walk: it must be an oriented feature path with compatible `HardRailId` and valid A4 paired front ownership. Treat the directed vertex link as an oriented 1-manifold fan of source-face wedges; use oriented triangle incidence, `SourceFaceTopologyKey`, and `SourceEdgeTopologyKey` to partition it at incoming/outgoing HardRail rays into **left and right open sectors**. A legal straight-through pair has one sector on each side even if the two carrier face sets are disjoint. Side-sector membership is defined from typed combinatorial incidence and route/owner orientation, **never** Euclidean closeness, sorted face-row IDs, sheet-label equality/inequality or the value of a Z4 potential. A3 supplies matching along admissible edges only *after* this partition. If A2b/A4 cannot independently establish exactly one admissible side-sector chain per side, stop for a producer-owned architectural Review, not a fabricated side identity.

**RA-37.2 — Typed paths and square.** At junction `v_i` orient each carrier crossing `χ_i : a_i → b_i`, with `a_i,b_i` the two topological incident faces selected by consistent left/right orientation, and A3's checked `QuarterTurn` for that carrier; the inverse swaps endpoints and negates turn. For the left-sector face sequence `a_i = l_0 ... l_p = a_(i+1)` publish `φ^a_i` with every directed nonrail radial source-edge key, directed source-face topology keys, `SourceFaceId` lookup, A3 `transition_value` and cumulative turn; analogously right-sector `φ^b_i : b_i → b_(i+1)`. Require source and target of **each** transition to match adjacent face topology, pairwise reciprocal values, same A4 owner/sector, no foreign barrier. The A3 semantic commuting square is:

```text
χ_(i+1) ∘ φ^a_i = φ^b_i ∘ χ_i
in Hom(a_i, b_(i+1));
Z4: χ_(i+1) + φ^a_i - φ^b_i - χ_i == 0 (mod 4).
```

The two compositions have a **common typed source and target**; merely adding all carrier `χ` values without the `φ` paths is invalid. The published witnesses are topology paths plus signed A3 transition values, not a bare `QuarterTurn` inferred from global fan potentials. Face-row permutation changes row lookup but not typed canonical keys, paths or composed turns. Reversing the paired route reverses every path and negates its turn, swaps sides/attachments and keeps the square commuting. The transport graph's path-independent potential may cross-check a proved path; it must not select a path or bypass sector membership.

**RA-37.3 — Two endpoint-pair maps, not a blind χ-fold.** Existing paired front `E` and reversed mate `E'` induce independently ordered endpoint pairs `P0=(E.from, E'.to)` and `P1=(E.to, E'.from)` (matching current `src/geometry/SurfaceCellTracing.cpp:18359-18370`). For **each** `Pj`, determine the typed start and terminal `placement.selectedFace` and one consistent oriented lane across the route. Record, as an ordered typed path witness, precisely which `φ^a_i`, `φ^b_i`, and `χ_i` or inverse crosses it, with junction source/target and cumulative `τ_j`. A path that changes side without the recorded `χ` transition, or crosses a carrier more than justified by its topology, is invalid. Independently prove its endpoints exactly match the A4-trace source face attachments; do not let the final A5-selected face choose/repair the path. A4 publishes both complete endpoint records, with inverses for the reverse relation. A5 checks at **both** pairs `published.firstAttachment == from.placement.selectedFace`, `published.secondAttachment == to.placement.selectedFace` and `B_to - B_from - R_coord - τ_j ≡ 0 (mod 4)`, and retains the existing rigid coordinate, scale/phase, reciprocal and chart checks. No independent A5 search or proxy from region `F`/global sheet labels is allowed.

**RA-37.4 — 0, 1, many.** A zero-step/absent route cannot produce a HardRail path certificate; require the existing correct typed missing-authority rejection, not identity τ. For **one carrier**, the two endpoint attachments are its incident faces in the appropriate orientation, `τ = χ_0` (or `χ_0^-1`), no junction path; preserve the accepted singleton semantics and reversed mate. For **multiple** carriers, compose only well-typed side and cross edges. No arbitrary max-step cap. Detect repeated oriented source edges, repeated vertex junctions or closed walks; require explicit closed-cycle identity/holonomy and unambiguous intended ownership before accepting, otherwise report a typed malformed/ambiguous route rather than silent truncation. For any nonzero singular index around a junction, missing reciprocal A3 value, disconnected/nonmanifold fan, multiple admissible sectors, foreign feature rail, inconsistent holonomy or failure of the commuting square, **fail closed with distinguishable cause**. Avoid coding a new failure enum blindly: independent Review decides whether existing typed `InvalidFrontBoundaryAuthority`/`InvalidHardRailRouteCertificate` reason+detail can represent each without weakening stable diagnostics; `HardRailTransportMismatch` may name only a *tested* A5 transport disagreement.

**RA-37.5 — Concrete typed falsifier on the 3×3 rectangle.** With upward rail orientation `(1→4),(4→7)`, choose left incident source faces `a_0=0=(0,1,4)`, `a_1=4=(3,4,7)` and right faces `b_0=3=(1,5,4)`, `b_1=7=(4,8,7)`. `χ_0:0→3` crosses source edge `(1,4)` and `χ_1:4→7` crosses `(4,7)`. Candidate left-sector face chain is `0 --(0,4)→ 1 --(3,4)→ 4`; right-sector is `3 --(4,5)→ 6 --(4,8)→ 7`. The carried edges are **not** radial side edges; all four side steps are. The two paths are geometrically/topologically valid independent of each carrier face pair intersection, and the correct A3 certificate must validate actual values and the commuting square before accepting. Constant planar cross field is a **plausible** zero-turn case, not accepted runtime evidence that A4 produced a reciprocal two-step route. Row-permute all triangles and recompute typed topology keys; reverse rail orientation and invert both χ and φ; compare canonical sequence and Z4 relations. Deleting one side transition, adding a different rail barrier in one sector, introducing disconnected fans, nonzero star holonomy, or tampering one A3 inverse must produce the correct typed rejection (not a generic face-disconnected false positive). **If the face-star topology cannot publish unique side sectors under these cases, architectural STOP; no R3 CB release.**

#### RA-37 companion hold points — independent of the A4 fix

1. **A4 root localization:** Future CB adds nondestructive, deterministic first-failing-predicate evidence for every `InvalidHardRailRouteCertificate` site: paired front IDs, rail and canonical route size/keys, from/to typed attachments, junction vertex, `current` and expected source face, rejected side path, root reason, owner and fingerprint. Do not infer actual two-step A4 route from input two-edge fixture. Preserve 25 direct, 12 Phase10 and 2 RE-package classifications; identify earliest producer error for the provisional cascades before changing status codes. Compare all 47 accepted CP2 regressions.
2. **A6 R2-P1:** One canonical `(typed A4 isolation-seam certificate, Forward|Reverse)` match must be authoritative for both source-face attachment, wedge binding, corner sheet, branch, coordinate, phase/scale, reciprocal and A7 checks. Neither equality nor inequality of raw global sheet IDs may grant or deny *lookup*. If A4 does not publish the needed typed wedge-to-certificate incidence, STOP for A4 producer review. Old A6 RP-01 remains open until independently validated.
3. **Periodic D1:** Bounded real source/field/geometry family must emit a reciprocal tracer-produced `PeriodicCut` pair with matching A3 source edge, endpoint selected-face gauge difference `1 or 3 mod 4`, same periodic relation and cut route, and independent sign/orientation mutation. The R1 source-only `select_torus_source_witness` is insufficient. Pre-register torus strip/phase windings with nonzero Z4 and face-row permutations, exact A3 pairing predicates and maximum deterministic enumeration bounds **before** future TB. If no organic candidate is found, stop for independent Review; do not loosen delta or fabricate A5 pair.
4. **HardRail D2:** Beyond `τ∈{1,3}` demand a real-produced reciprocal HardRail with `(F_b-F_a) mod4 != τ`, exact two endpoint placement charts and lattice positions, and a negative inverse-τ sign mutant. Illustrative *algebra only*: `F_a=0,F_b=3,τ=1,R_coord=1,B_a=0,B_b=2`; no runtime or produced witness claimed. A valid multi-carrier lane must separately pass RA-37.2/3; a two-edge hard-feature *input* is not sufficient.
5. **D3/D7 seam OrdinaryFront:** Axis-aligned 0.25/0.5/1.0 families previously produced **none**. Freeze a new bounded family only after static A3 source-face support/geometry/matching constraints and A4 isolated-seam side publication are written down; require an actually traced collinear reciprocal `OrdinaryFront`, same typed certificate with disjoint endpoint wedge-sheet sets, positive A5→A6→A7 chain and two distinct negative mutations (A6 branch turn, A7 missing isolation evidence). No A5 hand-built front or sheet inequality as substitute.
6. **D5 route-bearing ordinary:** Prove `OrdinaryInterior` from a real A4 product has a **nonempty** `CanonicalRoute`, an eligible source-chart edge in that route, and a live A5 traversable graph transition *before* injecting a typed hard-feature barrier. Insertion must remove only that carrier, retain unrelated transition, and keep PeriodicCut/HardRail negatives. Empty bounded search is STOP, never pick first labeled ordinary edge.

#### Review gate and routing

`M6-DEFN-R5-R3-REV` independently decides whether the A2b→A4 owner/source topology can make each left/right side chain unique, whether both endpoint-pair paths are actually well typed, and whether RA-37 needs narrower domain or producer-owned stop. **No release to CB solely from this Definition text.** Held implementation plan: `Architecture_M6_CP3_CB1_Entry_R3_Recovery_Code_Build_Plan.md`. If Review accepts, one bounded CB implements its amendments and compiles all eight existing GMP/GMPXX targets (no binaries executed), then separate immutable 497=30+12+449+6 TB and independent TB Review. Frozen selectors/names/order unchanged, zero skip/benchmark, exact-one, manifest/pre/postflight. CB2, optimizer and CP3 exit remain held; current runtime promotion stays accepted CP2 491/491. **Definition candidate cannot claim an organic produced witness or runtime recovery.**

Operational evidence: The mandatory snapshot mode was selected after the first parallel `STATUS`/handoff/TODO/policy read rather than before it; no subsequent piecemeal source inspection was used after discovery of the policy. This pre-read gate miss is recorded rather than normalized. The verified frozen snapshot governed all subsequent source inspection.

## `Architecture_M6_DEFN_R5_R3_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R3_Review_Record.md`; moved verbatim.

### M6-DEFN-R5-R3-REV — Independent RA-37 Definition Review

**Verdict: ACCEPT RA-37 WITH BINDING AMENDMENTS (RA-37a); release only one bounded `M6-CP3-CB1-ENTRY-R3` Code + Build turn, subject to producer-owned preflight STOPs.** This is a source-only Definition Review, **not** a production implementation, compile result, organic witness, or runtime recovery. Current accepted M6 runtime is CP2 `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, 491/491; R1 482/497 and R2 444/497 remain rejected. The accepted-green R2 loss is 47 identities. Existing stable ledger **64 events / 17 categories / 47 recurrences, debt 1**, unchanged by this Review.

#### Primary evidence and independent derivation

- Verified full source-snapshot event/source `6b2a167341101c686d5d839aa1e2e4cc3a67aff2`, run `37783521287`, artifact `11553371376`, outer archive SHA-256 `8473f1526aae7d01c02bf7017e67ac81cb1a0095f402c603b86cbf8855e121db`, embedded `source.tar.gz` SHA-256 `a1894d4e0c2f7c64d3b00ab51e3bd6e8f6c1668f5e9865f309c3649c4996572a`, 5,663/5,663 source-file hashes. Workflow jobs validate/snapshot/mailbox succeeded, runtimeExecution=false. No Directional executable, build, or benchmark was run in Review.
- Reconstructed the actual eight oriented triangles generated at `tests/SurfaceCellTransitionQuotientTests.cpp:495-519`. Vertex 4 has incident faces `{0,1,3,4,6,7}`. Carrier `(1,4)` has `{0,3}`; carrier `(4,7)` has `{4,7}`; intersection is empty. Oriented left face chain `0 --(0,4)--> 1 --(3,4)--> 4`, right `3 --(4,5)--> 6 --(4,8)--> 7`. These four radial edges do not coincide with the two hard carriers. Thus RA-36.1 common-carrier-face premise is **mathematically false on supported input**, and the two side fan chains exist **as topological possibilities**. This does **not** show an A4-produced two-carrier paired front or checked A3 transport values.
- `src/geometry/SurfaceCellTracing.cpp:18115-18205` constructs unrestricted fan potentials including hard carriers; `:18260-18372` makes an initial impossible `current` face fold before inspecting `phiA/phiB`. `include/directional/authority/FieldTransportAtlas.h:886-895` yields directed A3 matching, not source wedge/feature ownership. `SurfaceHardRailRouteEndpointCertificate` currently contains attachments, step list and one turn, **not** two independently source-attached local endpoint paths. `src/pipeline/RemeshPipeline.cpp:4932-4990` binds the two A5 occurrence pairs against A4's published certificate; A5 cannot invent the missing A4 lane.
- The R2 Review's immutable 497-gate/53 RED/47 accepted-prefix-loss classifications remain the evidence authority (`Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`, row table). This Review re-derived the source-topology counterexample independently; it did not rerun the R2 binary or claim the prior review's 1019/1019 R2 result hashes as newly checked. Selector449 is unchanged. No selector was added or promoted in this Definition Review.

#### Binding amendment RA-37a — the only frozen replacement for disputed RA-36.1

**A1 — Two-sector construction, not face equality.** For each pair of consecutive, distinct, ordered, *source-edge* HardRail carriers sharing one canonical source vertex, derive the intrinsic oriented radial halfedges from source triangle winding and A2b typed face/edge topology. Require a connected, oriented two-manifold vertex link on the relevant component and well-defined owner HardRail rays. The inbound and outbound rays split that link into two disjoint open face intervals, unique for the fixed orientation. Source-triangle row order, raw global sheets and A3 Z4 values cannot decide the intervals. Reject if the star is disconnected, branched/nonmanifold, has overlapping rays, a foreign hard-feature barrier inside either required interval, or cannot bind both intervals to the actual paired front. A boundary fan is eligible only if both required side intervals and endpoint attachments are present; otherwise reject. **No source-topology proof = STOP before implementing guesses or expanding to nonmanifold stars.** The 3×3 chains above demonstrate existence/uniqueness of the two link arcs for one valid planar input only, not a universal A4-produced route.

**A2 — Exact sector transport and commuting square.** Each side path carries an ordered source-face/topology-key sequence plus each *actual* nonrail radial source-edge key; every adjacent pair is validated by A2b incidence and forward/reverse `FieldTransportAtlas::transition_value` with checked reciprocity. Let `χ_i:a_i→b_i`, `φL_i:a_i→a_(i+1)`, `φR_i:b_i→b_(i+1)`. Require the **typed** equality `χ_(i+1) ∘ φL_i = φR_i ∘ χ_i`, equivalently `χ_(i+1)+φL_i−φR_i−χ_i≡0 (mod 4)`, only after both sides prove the stated common domain and codomain. A3's whole-star potential may cross-check, never choose topology or bypass a hard barrier. Reversal inverts each arrow and turn and exchanges the correctly oriented pair of side paths. A nonzero star index/holonomy or missing reciprocal transport is an explicit typed rejection, not a zero-turn assumption.

**A3 — Endpoint-local cross-rail relation, distinct from along-rail consistency.** This is the required narrowing of the candidate RA-37.3: `P0=(E.from,E'.to)` is one local *spatial* endpoint pair, and `P1=(E.to,E'.from)` is the other. For **each Pj independently**, the A4-selected start/end source face attachments must be connected through **one explicitly recorded, owner-valid local cross-rail path at that endpoint**, consisting of unique admissible same-side fan arcs (possibly zero-length) and exactly one justified owner-rail crossing `χ` or its inverse. Publish that local path, direction, source and target faces and `τ_j` separately. Do not derive `τ_j` by blindly summing `χ_0,...,χ_n`; those arrows have incompatible face domains, and a detour to the *other spatial endpoint* cannot be silently substituted for local attachment. The along-rail `φL/φR` commuting squares certify that the two endpoint-local mappings agree **after explicitly transporting their source/target bases along the route**; they are not themselves either endpoint's cross-rail path. When a front endpoint lies on a source vertex and multiple source-face attachments exist, the actual trace-selected face and its owner-side wedge constrain the unique same-side approach; first-by-row or shortest-in-geometry guesses are prohibited. If either endpoint pair lacks an independently typed valid path, STOP/fail closed. In the singleton non-junction case the local cross is its checked incident-face `χ` (or inverse); do not alter green singleton behavior.

**A4 — Publication/consumer, typed failure, and bounded validation.** A4 retains one canonical route plus both independently proven endpoint records and an ordered sector witness. A5 consumes only these immutable records and checks attachment equality and `(B_to−B_from−R_coord−τ_j) mod 4 == 0` **for each j**, with one coherent reversed relation, coordinate, phase, scale, and existing chart checks. Preserve A5 `HardRailTransportMismatch` exclusively for an evaluated mismatch. A4's missing fan/owner/attachment/transition/holonomy/square reason must remain distinguishable under existing fail-closed typed reason+detail; avoid an unreviewed enum. A malformed route, zero-step route, repeated vertex/edge, foreign barrier, mixed owner or ambiguous fan never becomes an identity τ. Do not limit route length arbitrarily or use F/global-sheet proxies, source-grid recovery, positional merge, exception by fixture, or a broad test relabel.

#### Additional findings and obligations

1. **R3-REV-01 — AMENDED / code-owned preflight.** The candidate did not distinguish local endpoint cross paths from route-length topology consistency. CB must check `P0/P1` local face charts **before** writing code; if topology cannot attach both to source vertex/edge fans and actual route-owner sectors, stop to independent producer Review. This is not permission to invent endpoint face identity in A5.
2. **R3-REV-02 — CARRIED A4 accepted-green first failure.** Inspect first rejecting predicate and actual route sizes/typed faces for all 25 direct `InvalidHardRailRouteCertificate` rows; diagnose 12 downstream Phase10 and two RE-package rows separately before any terminal code change. An input two-edge feature is not proof of a produced two-step A4 path.
3. **R3-REV-03 — CARRIED A6 RP-01.** Match a single certified A4 isolation-seam and direction with typed wedge/source-face incidence before deciding A6 domain. No raw sheet equality/inequality may grant/deny lookup. A4 missing wedge binding is producer STOP. Existing stable A6 event remains open.
4. **R3-REV-04 — CARRIED organic D1/D2/D3/D5.** Require separately tracer-produced periodic odd selected-face gauge (D1), HardRail odd `τ` unequal region F with sign mutant (D2), seam-collinear OrdinaryFront and independent A6/A7 tamper (D3/D7), and route-bearing OrdinaryInterior with real A5 graph edge removed by typed barrier (D5). Freeze bounded static search premises and explicit empty-search STOP. No synthetic A5 front, no selector/order edit, no claim of organic witness production.
5. **R3-REV-05 — CARRIED test authority.** Protect all 47 formerly accepted CP2→R2 RED identities, accepted CP2 491/491, frozen focused30/focused12/selector449/6 entry identity bytes and total 497 process arithmetic. R2 package remains rejected; no promotion before separate immutable TB and TB Review.

#### Authorized successor and stop gates

**Exactly one:** `M6-CP3-CB1-ENTRY-R3` (Code + Build only), under this RA-37a amendment and amended `Architecture_M6_CP3_CB1_Entry_R3_Recovery_Code_Build_Plan.md`. A4 typed manifold star preflight and two endpoint-local path-ownership proofs are mandatory first stops. If that cannot be established, stop within this CB with documented evidence and return to producer Design Review, not a guessed implementation. The remaining carried A6/witness obligations have independent stop gates. If implementable, compile **only** the existing eight GMP/GMPXX targets through the remote reusable compile workflow; run no Directional binary. The **subsequent separate** artifact-only TB runs exactly 497 fresh processes (30+12+449+6) without rebuilding, with exact-one, no skips/benchmarks, unchanged frozen selectors, immutable pre/postflight, and its mandatory independent TB Review. CB2/CP3 exit and optimizer remain held.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — Definition Review changes no selector and accepts/promotes no runtime package; retained selector449 authority remains unchanged, with byte comparison required in the next CB/TB |
| Decisive claims independently re-derived | Source 3×3 eight-face adjacency, both wedge paths and shared-source-vertex/disjoint-face contradiction; inspected A4 certificate and A5 consumer boundaries |
| Non-vacuity checked | Fixture proves input topology only, not an actual produced multi-carrier A4 pair; organic D1/D2/D3/D5 positives and A6 recovery remain absent/unproved |
| Prior obligations discharged/carried | RA-36.1 false premise replaced by RA-37a; R3-REV-01..05 carried as above; existing A6 RP-01 remains open |
| Stable accounting | 64 events / 17 categories / 47 recurrences, debt 1; CP2 491/491 accepted, R2 444/497 rejected |
| New candidates/obligations recorded | RA-37a amendment and R3-REV-01..05 in this record and root-cause tracker; no new stable event |
| ORIENTATION currency line | `M6-DEFN-R5-R3-REV` / 2026-10-08 updated |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for RA-37a and successor; §4 unchanged witness state documented; §8 adds local-endpoint/along-rail conflation to existing pattern |
| CHANGELOG | R3-REV entry added |
| ROADMAP | CP3 entry remains open; bounded CB now conditionally authorized |
| Selector manifest | n/a — no selector added, edited, or accepted |
| LESSONS | Existing lesson 207 (gauge/source authority) cited; new lesson not warranted pending runtime proof |
| Consolidation under CLEAN_UP_POLICY | Audited R3 Definition record/plan and prior R2 Review: retained as still-cited source/load-bearing historical evidence; no safe fold without losing required Library plan routing; no deletions |
| Successor frozen | Exactly `M6-CP3-CB1-ENTRY-R3`; falsifiers and stop conditions above and amended held plan |
| Turn boundary held | Runtime-free Definition Review; no product/test/fixture/selector/build/workflow mutation |
| review_check.py boundary | PASS — 9 review/document-only files; source/product/test/build/selector unchanged, 39 published selectors and durable markers preserved; no Directional binary executed |
| `STATUS` lifecycle maintained | Entry beacon published; final direct-write beacon remains required as final repository action |
| Pushed to origin, branch in sync | Confirmed remote push via successful Drive-apply job and independently verified immutable result artifact (`37784910240` / `11554166074`); working branch advanced past the published documentation commit through mailbox publication; ChatGPT Web snapshot has no remote-tracking branch, so `git status -sb` in-sync verification is not applicable locally |

## `Architecture_M6_DEFN_R5_R4_DIAG_Diagnostic_Fidelity_Audit.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R4_DIAG_Diagnostic_Fidelity_Audit.md`; moved verbatim.

### M6-DEFN-R5-R4-DIAG — exact carrier-incidence diagnostic-fidelity audit

**Disposition: complete, runtime-free static audit.** The alleged `front=13,131;edge[0]=1,2:faces=0,3` cross-contamination is **not substantiated**. Five such records originate in a **component-local vertex numbering** where local edge `(1,2)` corresponds exactly to original hard rail `(1,4)`, genuinely incident to source faces `{0,3}`. There is no demonstrated carrier/index contamination in any of the **38 records containing explicit carrier diagnostics**. The remaining **one** of the frozen 39 family contains no carrier/route receipt, so no assertion about an *observed* carrier can be made for that row. The independent design Review remains mandatory; the RA-41 candidates are **not frozen** by this audit.

#### Authority and boundaries

- Source snapshot: `f1a893fae1a9a551c74046f60ec3f4fbbba4ee3f`, workflow `38038737771`, source artifact `11663934711`, outer ZIP SHA-256 `878cf5cc187e34bc98bedd183b92d3b791835083e78219a69518bc9ab7a038b2`.
- Exact archive `source.tar.gz` and all **5,837** snapshot file checksums verified locally. This is a static source analysis; no Directional runtime, compiler, tests, benchmarks, source, fixtures, producer semantics, or selector changed.
- Immutable R3 first-failure inputs: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv`. The full 39-row extraction and namespace-specific classification are in `Architecture_M6_DEFN_R5_R4_DIAG_Failure_Carrier_Inventory.tsv` (same identities, no fabricated runs).
- Pre-existing accepted evidence unchanged: CP2 `491/491`; R3 `403/497`, `94 RED`, `39` carried A4 endpoint rows, `88` accepted CP2 identities lost; stable ledger `66 / 17 / 49`, debt `1`.

#### 1. Direct fixture: 3×3 grid and original global vertex IDs

`tests/SurfaceCellTransitionQuotientTests.cpp:570–615` creates the eight triangle rows by iterating lower-left/lower-right/upper-right and lower-left/upper-right/upper-left for each square. `make_nonconstant_hard_rail_fixture` at `:761–836` repeats the same eight-row geometry, with only cross-field variation or an explicitly requested face-row reversal. The non-reversed source rows are:

```
0: (0,1,4)   1: (0,4,3)   2: (1,2,5)   3: (1,5,4)
4: (3,4,7)   5: (3,7,6)   6: (4,5,8)   7: (4,8,7)
```

The true source incidences are `(1,4) → {0,3}`, `(4,7) → {4,7}`, and original `(1,2) → {2}` (boundary). Source-geometry incidence was re-derived by enumerating all triangle edges rather than trusting the diagnostic. The 21 frozen `front=17,203` records and 12 frozen **noncompacted** `front=13,131` records print carrier `(1,4):faces=0,3` and agree with that construction. Their `faceEnds=0,2|0,3` values are trace-endpoint source-face rows, **not** independently certified terminal rail-side contacts.

#### 2. Component fixtures: why local `(1,2)` legitimately owns `{0,3}`

`tests/SurfaceCellsPhase10Tests.cpp:223–271` builds *two disconnected copies* of the same eight-triangle grid, at z=0 and z=2, with global hard features `(1,4),(4,7)` and offset copies `(10,13),(13,16)`. Five frozen failures use the component pipeline (`remesh_surface_cell_components_from_cross_field_{counterfactual,final_validation_counterfactual}`); these call `remesh_surface_cell_components_from_cross_field_aggregate_impl` (`src/pipeline/RemeshPipeline.cpp:16928`) and then `compact_face_components`.

`src/geometry/MeshComponents.cpp:72–116` assigns local vertex IDs by **first encounter walking sorted face rows and their three corners**, not by preserving the original vertex numbering. In the first component the exact original→local mapping is:

```
original 0→local 0; 1→1; 4→2; 3→3; 2→4;
         5→5; 7→6; 6→7; 8→8.
```

Thus original hard rail `(1,4)` becomes **local `(1,2)`**, with local face rows `{0,3}`. Conversely original **boundary** `(1,2)` becomes local `(1,4)` with face row `{2}`. The second component uses the same local mapping relative to its nine-vertex offset. The published diagnostic `front=13,131;edge[0]=1,2:faces=0,3` in those five tests is therefore **correct in the component-local mesh**. Reading that local key against the un-compacted 3×3 fixture produced the apparent contradiction. The `front` indices themselves are only indices into a fixture's own `phaseFrontState.edges`; matching the same numbers between test fixtures does not establish a common mesh or globally shared edge identity.

#### 3. Exhaustive 39-family static inventory

| Observed record group | Count | Mesh namespace | Carrier | Source incidence | Finding |
|---|---:|---|---|---|---|
| `front=17,203` | 21 | Direct original 3×3 | `(1,4)` | `{0,3}` | Matches |
| `front=13,131` | 12 | Noncompacted original 3×3 | `(1,4)` | `{0,3}` | Matches |
| `front=13,131` | 5 | Per-component compacted 3×3 | **local** `(1,2)` | `{0,3}` | Matches; original `(1,4)` |
| No carrier printed (`selector:150`) | 1 | Two-component 3×3 pair | N/A | All four configured global midline rails each have two incident faces | No observed carrier to compare |

**All 38 emitted carrier records are exactly two-face internal carriers.** The 39th is the failed `RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent` expectation at `tests/SurfaceCellsPhase10Tests.cpp:6595–6640`: its first diagnostic only reports failed `produced[]` and `regionCounts[]` checks, not a route. Its configured rails have two source-face incidences each, but the omitted producer route cannot be reconstructed from that log. Do not claim 39/39 carrier receipts matched, and do not extrapolate from absence of a logged invalid carrier to an unseen front.

#### 4. Diagnostic provenance and pre/post-validation boundary

`src/geometry/SurfaceCellTracing.cpp:18287–18362` counts actual source-edge incidences from the **current** `faces` argument; rejects an absent edge or edge with more than two incident faces; obtains two distinct incident rows and forward/reverse A3 transport before publishing `phaseFrontState.hardRailFieldTransitions`. Boundary one-face hard features are permitted as *boundary features* and publish no cross-edge transport. The paired crossing loop starts around `:18384`. The error detail at `:18406–18449` prints:

- `front=...` from the current `phaseFrontState.edges` pair;
- `faceEnds` directly from `first.from.face`, `second.to.face`, `first.to.face`, `second.from.face` (trace endpoints);
- `edge[i]` from `first.route.oriented_steps()[i].topology()`;
- `faces` from the matching published hard-rail transition's **source-topology keys**, resolved using the same current `network.sourceTopologyRegions`;
- `chi` from that transition's transported value.

That `edge[i]`/`faces` diagnostic is emitted **after A4's source-edge incidence and A3 carrier-transport checks and after local front construction**, but **on the rejection path before successful route-certificate publication and before the final `SurfacePhaseFrontProduct::make` checked factory**. Its displayed carrier incidence is not an independent proof of all semantic front attachments. Importantly, the print code does not select an arbitrary owner by `front` ordinal: it looks up the record by exact `entry.edge == route[i].topology()` and otherwise emits `owner=missing`. The five local `(1,2)` rows also independently match the component's source triangles. There is no evidence here of the hypothesized record-index cross-contamination.

`SurfacePhaseFrontProduct::make` (`:8037–8085`) permits a hard-feature edge with one source-face incidence **when no two-face transition is published**, and rejects 0 or >2 incidences; a **published hard-rail transition** does require exactly two faces and source/A3 matching. The separately written (not yet executed) `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` test (`tests/SurfaceCellTransitionQuotientTests.cpp:1850–1975`) explicitly expects `EmptyCells` for a one-face boundary hard rail, `InvalidSourceAuthority` for absent/three-face rail, and an empty-cell gate for valid two-face rail. Therefore the earlier claim that *any* one-incident-face edge is forbidden as a hard feature is too broad. It is forbidden as an emitted two-face **cross-rail transition**, not as boundary authority.

#### 5. Determination for mandatory R4 independent Review

1. **Correct the source-namespace premise** in the R4-next handoff and RA-41 D2 candidate: do not compare component-local `(1,2)` to the original fixture's `(1,2)`. The cited five records are valid local renumberings of original `(1,4)`; their printed `{0,3}` is independently confirmed.
2. **Retain the actual R3 failure.** `faceEnds=0,2|0,3` does not satisfy the current endpoint-carrier-face identity requirement for `(1,4):{0,3}` or compact local `(1,2):{0,3}`. The typed first predicate remains `endpoint-0`, and the producer terminates before acceptance. Nothing in this audit proves source-wedge contact, producer-owned terminal side, or the proposed RA-41.2 local-germ semantics. Do not wave the mismatch away merely because diagnostic carrier identity is correct.
3. **RA-41.2 stays candidate/unfrozen.** The Review should independently verify A2b/A3 producer-owned contact witnesses and gauge lineage before accepting/revising RA-41.1/.2 or releasing the held CB. The separately written four RA-40(C) supplemental tests stay unexecuted and outside the 497 gate. A new runtime case is not credited.
4. **No production mutation** (no fabricated face substitution, contact path, fixture change, loosened factory oracle, compilation, or test replay) is authorized by this diagnostic audit. The precise successor is `M6-DEFN-R5-R4-REV` after the final COMPLETE beacon.

**Static pass / scope pass:** source correlation and independently re-derived carrier incidences explain all 38 printed records; the single unprinted row is explicitly distinguished. This closes the bounded diagnostic-fidelity question, not the blocked semantic recovery plan.

## `Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`; moved verbatim.

### M6-DEFN-R5-R4-REV — independent definition review (runtime-free)

#### R5/R4 re-review after RA-42 Design Review — authoritative correction (2026-10-10T11:07Z)

**Disposition remains REVIEW_BLOCKER: RA-42 is acceptable as a prospective *design obligation*, but the assertion that the source-attached producer already supplies independently authenticated terminal incidence is not supported.** This re-review inspects the exact GitHub source snapshot `0bc8080366757a2285a8265599255475ef8525b2` (workflow `38046815459`, source artifact `11666644778`, outer SHA-256 `c2b548b123ee38e0daef5d1299693d9d7b586caf7639bd1347e690abf479c237`, **5851/5851** internal checksums). All snapshot jobs passed. No Directional binaries, compiles, tests, or benchmarks executed. This latest section supersedes older descriptions of which architecture decisions remain undecided, but preserves the historical independent analysis below.

**R4-REV-01A — rail samples are not typed topology credentials.** `include/directional/geometry/SurfaceCellTracing.h:90-116` declares `SurfaceCellRail::sourceVertices` and `SurfaceCellRail::sourceEdges` as `std::vector<int>` and `SurfaceCellRailSample::sourceFace`/`sourceEdge` as raw `int`, with `sourceEdge` a local face-edge index. These can be useful inputs to a checked mapping; they are not `SourceFaceTopologyKey`, `SourceEdgeTopologyKey`, or a typed *front endpoint-to-rail contact*. No contract proves that a particular `SurfaceFrontEdge::from/to` belongs to a particular rail sample, a unique local source-vertex occurrence, or a specific side germ. `src/geometry/SurfaceCellTracing.cpp:18384-18515` still constructs the endpoint certificate from the raw trace-point face rows. A downstream conversion to typed IDs without producer-owned contact and uniqueness proof would only repackage that gap. **Required:** name the exact producer symbol and source-line path, publish a source-authenticated vertex/edge/face occurrence plus rail sample/interval and filled-side mapping, certify both endpoint germs and uniquely ordered nonrail A2b/A3 continuation, reject missing/ambiguous assignments. A route discovered by geometry/barycentric proximity is not authority.

**R4-REV-01B — false reuse-location claim.** Frozen RA-42.4 and the cited Design Review identify `SurfaceCellTracing.cpp:18120-18206` as an already-existing source-vertex-star traversal. That range actually handles an isolation seam certificate call and diagnostic formatting, **not** the purported vertex-star-cut contact producer. Existing other star-related helpers cannot be presumed to implement this mapping. Corrected the normative reference; a real symbol and line-level dataflow proof remain mandatory. The helper `rail_sample_source_vertex` (`SurfaceCellTracing.cpp:5810-5852`) infers vertex membership from barycentric epsilon checks and therefore cannot establish typed incidence under RA-42.2.

**R4-REV-02A — unconditional A3 decision retained; held plan contradicts it.** RA-42.5 explicitly preserves RA-40.1's unconditional `FieldTransportAtlas::matches_source_faces` boundary. `SurfacePhaseFrontProduct::make` (`SurfaceCellTracing.cpp:7989-8020`) enforces the matched atlas but only range-checks `sourceFaceBranchRotations`; there is no independent source-bound equality check for that caller-supplied gauge. This remains work for Code + Build *after* the review gate. Worse, the HELD R4 plan's implementation items 2 and 5 explicitly still allow a null atlas and an “empty-A3 conditional positive”, contradicting the frozen RA-42.5 decision. Corrected those instructions without running or authorizing implementation. Never use a caller's own gauge as an independent gauge oracle.

**Not discharged / review STOP.** RA-42.7's separation of singleton terminal contact from multi-carrier through-junction is logically consistent with the observed 3×3 source star and retained. However, 38 printed rows remain one physical singleton carrier and the 39th has no carrier: **zero genuine produced multi-carrier A3 witnesses**. No RA-41 freeze, R4 Code + Build release, runtime promotion, or new successor is authorized. A further independently reviewed, source-exact producer proof is required *within this same canonical Review turn* before it may close. Prior R3 runtime remains 403/497 with 94 RED; accepted CP2 491/491, 88 accepted-green losses; stable ledger **66/17/49**, debt **1**; selector 497 and four supplemental tests untouched.

---


**Disposition: NOT ACCEPTED FOR IMPLEMENTATION / REVIEW_BLOCKER.** RA-41.2's observed source-star *possibility* is independently verified, but the current material does not demonstrate producer-owned terminal-contact authority. RA-41.1's atlas-null exemption conflicts with binding RA-40.1 and lacks independently checkable gauge provenance. Do **not** freeze RA-41, rewrite the frozen RA-38/RA-39/RA-40 contract, release `M6-CP3-CB1-ENTRY-R4`, run binaries, or change tests/producer. This turn remains blocked on explicit source-domain architecture decisions; it does not invent a successor. Review baseline snapshot SHA `91cd585f2cfd5457bb9fddae8357554a32c898ad` (snapshot run `38042697991`, artifact `11665329905`, ZIP SHA-256 `3915c6739ca3b22df14e86c15347e8700a9ed303f11004415aac636244495f02`, embedded tar SHA-256 `492a59c7c211e0375b480fa12eba509c13ba902378e97d4f32545b2e54d6ece1`). All three snapshot jobs passed; no Directional executable, compile, test or benchmark ran in this review.

#### Independent topology proof — exactly one observed carrier

Reconstructed `tests/SurfaceCellTransitionQuotientTests.cpp:575–602` from the nine grid vertices and eight oriented face rows:

```
face 0=(0,1,4), 1=(0,4,3), 2=(1,2,5), 3=(1,5,4)
face 4=(3,4,7), 5=(3,7,6), 6=(4,5,8), 7=(4,8,7)
rail carriers: (1,4)->{0,3}; (4,7)->{4,7}
nonrail spoke (1,5)->{2,3}
star(1): {0,2,3}, remove rail (1,4) => {0} | {2,3}
star(4): {0,1,3,4,6,7}, remove rails (1,4),(4,7) => {0,1,4} | {3,6,7}
```

For the 38 carrier-bearing first failures in `Architecture_M6_DEFN_R5_R4_DIAG_Failure_Carrier_Inventory.tsv`, the reported endpoint faces `0,2|0,3` **can** represent opposite rail-side germs at both endpoints of original carrier `(1,4)`. At boundary vertex 1, the face-2 trace sample is on `{2,3}` and has a one-step A2b nonrail candidate `2 -> 3` via `(1,5)`; its partner face 0 is already in `{0}`. At interior vertex 4, face 0 and face 3 are directly on opposite sides. The proposed contact pair is therefore `{3,0}` at vertex 1 and `{0,3}` at vertex 4. This disproves the universality of RA-39.1's **trace-sample row equality** but does not prove a producer-owned contact route or a valid A3 φ value. The 39th selector-150 failure has **no printed carrier** and must remain without contact-credit. `MeshComponents.cpp:72–116` maps original (1,4) to component-local (1,2), so the five compacted entries are not false carrier diagnostics. All 38 diagnosed entries are manifestations of one physical carrier configuration, **zero multi-carrier producer witnesses**.

**Boundary-scope ruling.** Frozen RA-38.3's boundary-vertex and singleton STOP is correct for *multi-carrier through-junction sector transport*, the subject of RA-38. It must not be applied indiscriminately to a **terminal one-carrier contact**: boundary vertex 1 supplies two oriented side germs. The pending RA-41 amendment must explicitly separate these domains. This does not authorize allowing a boundary vertex at an invalid through-junction or removing any source/nonmanifold/rail barrier check. RA-39.6's singleton junction φ is identity only for the absence of junctions; a trace-sample-to-contact step may have nonzero separately proven A3 φ.

#### Blocking finding R4-REV-01 — terminal contact source authority has not been constructed

At `include/directional/geometry/SurfaceCellTracing.h:1500–1545`, the front edge holds `from/to` trace points, filled cell/side, opposite edge and route. It does not publish a contact endpoint source occurrence, admissible source-vertex wedge, ordered nonrail transport path or independently established side germ. `src/geometry/SurfaceCellTracing.cpp:18384–18515` still uses the trace-sample `from.face` / `to.face` as the carrier attachment; `SurfacePhaseFrontProduct::make` then checks exact row equality at `:8090–8118`. The topology proof above shows one possible contact route, not that producer direction, barycentric endpoint support, front-side incidence and competing wedges uniquely select it. A checked factory cannot reconstruct that choice from arbitrary face adjacency or merely trust a supplied contact face.

**Required architectural disposition:** specify and statically prove which existing upstream producer entity binds the trace point to source vertex 1 or 4, selects the oriented filled-side germ, and publishes its ordered A2b **nonrail** route with actual source-edge incidence, source-face topology, A3 forward/reverse `transition_value`, and reciprocal front ownership. Require a uniqueness/ambiguity denial independent of source-row order. Prove on the observed singleton and a true **produced** two-carrier route; treat absent route or zero produced instances as a STOP, not as a passing test. Decide whether the existing product can carry this as an immutable, source-authenticated value or needs an explicit schema amendment. No fabricated `2 -> 3` substitution is authorized by this review.

#### Blocking finding R4-REV-02 — conditional null-A3 exception conflicts with frozen trust boundary

RA-40.1, `.agents/Directional/Architecture_M6_Frozen_Definitions.md:1–22`, explicitly requires `FieldTransportAtlas::matches_source_faces` at the checked `SurfacePhaseFrontProduct::make` boundary and states **absent atlas must fail typed, with no unauthenticated accepted mode**. RA-41.1 proposes accepting A3-independent products with a null atlas. That is a normative amendment, not a mere implementation detail; it is currently **not** accepted. `SurfaceCellTracing.cpp:7989–7993` enforces atlas presence unconditionally; `:8015–8020` only checks `sourceFaceBranchRotations` length/range. Independently sourced `faceAxisX/Y` and local branch selection (`:11019–11056`) are upstream producer logic, but the checked factory currently receives no source/cross-field certificate allowing a caller-provided gauge to be re-derived. Further, periodic and isolation relation products may depend indirectly on field gauge/transport even when rail arrays are empty (`:17965–18060` illustrates periodic branch-dependent publication).

**Required architectural disposition:** choose explicitly between (A) preserving RA-40.1 unconditional source-matched independent atlas and migrating the legitimate ordinary/legacy producers and fixtures, or (B) a formally reviewed RA-40.1 amendment with a complete typed A3-dependency census, a separately authenticatable source/cross-field/gauge lineage, nonrail/isolation/periodic dependency classification, fail-closed negative tests, and a proof that data removal cannot bypass authentication. A length/range check, empty rail arrays, default identity atlas, trust-me certificate or user-selected flag is insufficient. Do not derive independent A3/gauge from the A4 values being validated. The 34 Phase10 errors are presently 22 untyped-not-produced plus 12 generic final-state assertions, not 34 demonstrated null-atlas roots; instrument typed first rejection before asserting a full recovery path.

#### Other findings, unchanged obligations and disposition

- **D3:** The proposed consistent two-face disk is a valid way to remove the seven synthetic single-triangle `DCEL::check_consistency` setup errors without weakening DCEL. The original six periodic-owner negative oracles and one FlowRep truncation oracle must still be reached and retained. This proposal does not discharge R4-REV-01/02.
- **A3/χ invariants:** The preexisting one-terminal carrier χ, reciprocal inverse, verified nonrail φ, and nonzero multi-carrier A3 commuting square must be preserved; do not treat geometric reachability as transported field equality.
- **Runtime authority:** CP2 accepted 491/491; R3 rejected 403/497, 94 RED (39/34/7/14), 88 accepted CP2 losses, zero claimed restorations. Stable regression ledger remains 66 events /17 categories/49 recurrences and M6 debt 1; no new runtime regression classified. Frozen 497=30+12+449+6 and separate four RA-40(C) diagnostics untouched.
- **Code/build gate:** `M6-CP3-CB1-ENTRY-R4` remains HELD; no compile/test or source edit authorized by this review. When both architecture blockers are independently discharged, a subsequent formal Review decision must freeze the exact RA-41 amendment and its single next-turn authority before any implementation begins.

#### Review consolidation audit

Examined active R4 Definition plan, candidate record, DIAG audit/39-row inventory, held CB plan, R3 independent Review and normative definitions. **No R4 per-turn document is eligible for safe folding now**: the diagnostic inventory remains unique immutable source evidence; the candidate and held plan remain load-bearing until the architectural STOP is resolved. Historical project authority and selectors were not folded or deleted. Consolidation obligation cannot justify deleting current evidence; the family consolidated record indexes this review decision. No cleanup is necessary to make this review decision source-authoritative.

#### Resume-required exact next actions

1. Obtain a reviewed producer-owned terminal side-germ/contact proof including actual trace-support incidence (R4-REV-01).
2. Choose and freeze the source-matched A3/gauge trust-domain boundary explicitly (R4-REV-02), preserving RA-40 unless a reviewed amendment supersedes it.
3. Only then adjudicate complete RA-41, update the held CB plan, and release the single Code + Build successor in a separate authorized turn. Until then the current `M6-DEFN-R5-R4-REV` is **BLOCKED / REVIEW_BLOCKER**, with no successor authorized.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: frozen 497 selector not changed; no acceptance decision made, historical 491 accepted authority carried |
| Decisive claims independently re-derived | Raw `SurfaceTracePoint`, rail/sample and front types; real source at `18120-18206`; factory atlas/gauge validation; contradictory HELD plan; snapshot 5851/5851 hashes |
| Non-vacuity checked | A carrier sample's raw face/edge does not identify an oriented front contact; one ambiguous or missing incidence must fail, not create a proof; zero produced multi-carrier cases yields zero credit |
| Prior obligations discharged/carried | R4-REV-02 normative *choice* A accepted; R4-REV-01A/01B producer proof and R4-REV-02A gauge authentication open; 39/34/7/14 first-locus, 88 accepted losses, D1/D2/D3/D5/A6/A7, periodic and four supplementals carried |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt 1; CP2 491/491 accepted; R3 403/497 unpromoted |
| New candidates/obligations recorded | R4-REV-01A, R4-REV-01B, R4-REV-02A added to TODO and regression tracker as review obligations, not new stable runtime regressions |
| ORIENTATION currency line | M6-DEFN-R5-R4-REV 2026-10-10 correction prepended |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 superseded priority annotated; §4 witnesses unchanged because no runtime; §8 adds verified authority conflation recurrence |
| CHANGELOG | Re-review correction prepended without rewriting historical RA-42 decision |
| ROADMAP | n/a: M6 checkpoint state unchanged, R4 remains held |
| Selector manifest | n/a: selector unmodified, 497 gate unchanged |
| LESSONS | Existing durable source-authority vs geometry and evidence non-vacuity lessons applied; no new general class |
| Consolidation under CLEAN_UP_POLICY | n/a: active RA-41/RA-42 Decision, prior Review, DIAG inventory, and HELD plan remain load-bearing; no safe deletion |
| Successor frozen | UNKNOWN: architecture producer proof gate blocks lawful successor; no fabricated successor |
| Turn boundary held | Runtime-free Review; no product, test, fixture, selector, benchmark or build source mutation |
| review_check.py boundary | PASS: no product/test/selector/build changes, all checked selector SHA digests and durable marker counts preserved |
| `STATUS` lifecycle maintained | Entry `M6-DEFN-R5-R4-REV`, 2026-10-10T10:58:35Z; final BLOCKED, successor UNKNOWN, no terminal timestamp |
| Pushed to origin, branch in sync | Durable Drive apply 38047581786 GREEN; pushed exact nine-document correction and verified changed paths via GitHub commit. No local `git status -sb` equivalence: Web snapshot is deliberately not a tracking clone; PR #8 remains draft/unmerged |

## `Architecture_M6_DEFN_R5_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_R5_Review_Record.md`; moved verbatim.

### `M6-DEFN-R5-REV` — Independent Review of the CP3-Entry Definition

**Turn:** `M6-DEFN-R5-REV` (runtime-free Review)

**Reviewed:**
- `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md` (D1–D9);
- RA-30;
- the held `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`;
- against the R5 plan, frozen §10, RA-16/17/20/26/27a/28b and exact source.

**Source authority.** Branch HEAD. Its `src/`, `include/`, `tests/` and `cmake/` are unchanged since CP2 closure; reviewed runtime is `11391685901 / 5ce3132e` (491/491).

**Disposition: ACCEPTED WITH BINDING AMENDMENTS (RA-30a).**
- D1–D9 are all addressed, and the structure is sound:
  - entry gates come before direct production;
  - the CB1/CB2 split is right;
  - the 497 entry gate and 507 final gate are correct as counted.
- **Four decisions have defects that would cause another false-rejection or vacuity cycle, or an unrunnable gate:**
  - **V1:** D4 has no authority source or API, and its fail-closed rule would break direct A5 callers;
  - **V2:** D2's reachability claim cites the wrong evidence;
  - **V3:** D3 weakens A6 instead of certifying the branch across seams;
  - **V4:** two of D9's three G4-B001 rows are not in any built target.
- Four more are underspecified for CB2 (V5–V8).
- RA-30a fixes all of these. **`M6-CP3-CB1-ENTRY` is released** under RA-30 + RA-30a.
- Gates unchanged: **497** entry, **507** final.
- Accounting **60 / 16 / 44**, debt 1.

#### 1. Verified

- **D1** (`SurfaceCellTracing.cpp:7925-7965`; `RemeshPipeline.cpp:4543-4614`, `:4869-4874`). Removing only the face-gauged final branch comparison, while keeping the endpoint-state recomputation, both conjugations and an independent relation-gauge check, is correct.
- **D4's diagnosis.** A5 builds its chart-barrier set from HardRail front routes only (`RemeshPipeline.cpp:3785-3795`), and the produced torus carries 18 hard edges on PeriodicCut relations.
- **D7** relation-kind dispatch (HardRail never compares global sheet IDs; OrdinaryFront and Periodic stay within one region; a cross-region Periodic case is a stop).
- **D8**'s conjunct-to-identity table, and the requirement that G4-B004 be bound continuously as one chain.
- **D9 arithmetic.** None of the three named G4-B001 rows is in selector449, so 491 + 13 + 3 = **507** does not double-count. The entry gate is 491 + 6 = **497**.
- **The P27 parameterized ownership row is correctly excluded**, since it does not require production.

#### 2. Findings

##### V1 (High) — D4 names no authority source or API, and its fail-closed rule breaks direct A5 callers

D4 says A5 must "receive the same immutable typed source hard-feature edge authority" and must "fail closed" when a HardRail carrier is not in it. But:
- `SurfacePhaseFrontProduct` publishes no hard-feature authority (`SurfaceCellTracing.h:1749+`);
- A5's signature is `produce(V, F, phaseFront)`, with **38** direct test call sites, many in accepted focused-30 and selector449 rows.

Any extra parameter with an "absent" default either keeps a HardRail-route fallback (the CB1 plan forbids legacy fallbacks) or makes every direct A5 HardRail call fail closed. Either way, accepted gate behavior would change.

The single writer already exists: `SurfaceCellTracingOptions::hardFeatureEdges` (`SurfaceCellTracing.h:2089`) is the typed set the tracer consumed.

**Fix (RA-30a §1):**
- A4 publishes that set immutably;
- A5 reads it from the product;
- the adapter asserts it equals the pipeline's `hardFeatureRailEdges`;
- A5's signature does not change;
- no accepted test body changes.

##### V2 (High) — D2's reachability claim cites the wrong evidence

D2 requires a produced cross-region HardRail with a nonzero selected-face gauge. As evidence it cites TB7 `:264-267`, but that passage concerns the **torus's periodic carriers**, which belong to a single region. The same TB7 analysis says every HardRail fixture uses a constant field (`constant_xy_field`), so F = 0 everywhere.

With F = 0, stripping is the identity. Any stripping formula passes, including the wrong-direction `F ∘ B` in place of `F⁻¹ ∘ B`. RA-16 deferred this item precisely because no such fixture existed. The "alter only F" negative kills an implementation that ignores F, but nothing proves that correct stripping **accepts** valid data whose gauge is nonzero.

**Fix (RA-30a §2):** specify the produced construction and its non-vacuity conditions; detail is in RA-30a.

##### V3 (Medium–High) — D3 weakens A6 instead of certifying the branch across a seam

A6 accepts an OrdinaryFront relation only if `sourceChart`, `branchRotation`, coordinate and scale are all equal and phase is within `1e-10` (`RemeshPipeline.cpp:5229-5236`). D3/RA-30 §3 lets chart and branch "differ only with the exact reciprocal checked isolation transition", and puts no constraint on the branch difference. It also says the phase comparison "must not" be relied on, without saying whether CB1 removes it.

The A4 `SurfaceIsolationSeamTransportCertificate` publishes the seam's exact `forward()` / `reverse()` quarter-turns (`SurfaceCellTracing.h:1341-1365`), and A5 validates those certificates. So the branch across a seam is **certifiable**, exactly as D2 certifies HardRail branches. Dropping it accepts frame-misaligned OrdinaryFront relations across seams. That is a validator weakening, which the CB1 stop rules forbid.

**Fix (RA-30a §3).**

##### V4 (High) — two of D9's three G4-B001 rows are in no built target

`MilestoneGP26Tests.cpp` and `MilestoneGP27Tests.cpp` compile **only** into `directional_surface_cell_historical_tests`, which is built only under `DIRECTIONAL_BUILD_HISTORICAL_TESTS` (`cmake/DirectionalTests.cmake:554-578`). That target is not among the standard eight compile targets (`.github/workflows/agent-compile-reusable.yml:12`). `SurfaceCellsPhase10` is in the producer target. So the frozen 507 gate cannot be executed by the frozen compile-and-TB pipeline.

**Fix (RA-30a §4):** CB2 decides at compile time. It does not affect CB1 or the 497 gate.

##### V5 (Medium; CB2) — D6's exact equality ignores floating-point accumulation order

D6 requires an **exact** optimizer accept/iteration/line-search decision sequence, and positions within `1e-12 · max(1, bbox)`, under source-row, output-row and corner permutations. The optimizer accumulates energy and gradients in row order, and floating-point addition is not associative, so permuted inputs change rounding. Armijo decisions near their threshold can then flip. That would be a RED with no semantic defect behind it.

The output-row permutation also needs a defined injection seam, which D6 does not give.

**Fix (RA-30a §5).**

##### V6 (Medium; CB2) — "scheduler permutation" is undefined

Frozen §10 and D8 require scheduler-permutation invariance (`DirectProductionSchedulerPermutationIsSemanticNoOp`), but never say what is permuted or how.

**Fix (RA-30a §6).**

##### V7 (Medium) — D1 names no produced fixture and doesn't kill the wrong-direction conjugation

D1 requires a produced exact-A3 pair with unequal `localFaceBranchRotation`, but names no fixture. The produced nonzero-Z4 torus already has to search for carriers with nonzero matching (`SurfaceCellTransitionQuotientTests.cpp:1351-1363`), which makes it the natural candidate.

An unequal pair that differs by 180° is self-inverse, so it cannot kill an implementation using `Γ` in place of `Γ⁻¹`.

**Fix (RA-30a §7).**

##### V8 (Low) — D2 failure diagnosability

D2 maps to the existing external `InvalidHardRailTransport`.

**Fix:** add a distinct site suffix such as `:branch-certificate`, so it stays distinguishable from coordinate-rigidity failures (lesson 181).

#### 3. Closeout

| Duty | Result |
|---|---|
| D1–D9 re-derived against source | D1, D7, D8 verified; D4 diagnosis verified. V1–V4 are defects; V5–V8 are underspecified. |
| Gate arithmetic | 497 / 507 verified; the G4-B001 rows are not in selector449. V4: GP26/GP27 are not in any built target. |
| Disposition | ACCEPTED WITH RA-30a; CB1 released. CB2 amendments V4–V6 are binding when CB2 is planned. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 206. |
| Successor | `M6-CP3-CB1-ENTRY` → `M6-CP3-TB1-ENTRY-EXEC` (497) → `M6-CP3-TB1-ENTRY-REV`. |

## `Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md`; moved verbatim.

### RA-184 — DIAG-RETAIN: A5–A7 diagnostic snapshots (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-A5-A7` (DEFN, Review track), run locally. This is the user-directed DIAG-RETAIN item (TODO, 2026-10-21).
- **Method:** probes are diagnostic only. Source is CB57 `fb4f637b…`, unchanged in `src/`, `include/` and `tests/` at HEAD. A Sonnet subagent traced the snapshot contract and the A5–A7 producers (read-only); the Review agent designed the change, probed it and ruled.

#### RA-184.1 Findings

- **A5, A6 and A7 run inside one helper**, `build_authoritative_phase_front_mesh_with_hard_features` (`src/pipeline/RemeshPipeline.cpp:9222–9405`), and the tracing stage calls it once (`:13341`).
  - The products are locals: A5 `SurfaceOccurrenceComplex`, A6 `SurfaceQuotientProduct`, A7 `SourceAttachedGeometryProduct`, then verification.
  - The helper returns only `AuthoritativePhaseFrontMeshResult` (mesh, counts, a failure string). On success it overwrites that result with `project_verified_surface_products(...)`.
  - A rejection at any stage returns early. **Today no A5–A7 product survives the helper.**
- **The snapshot contract** (`include/directional/pipeline/RemeshPipeline.h:300–344`) documents one-way copies that are never read back. It has no A5–A7 fields. No test mutates a snapshot to prove there is no read-back; the existing retention test compares runs with retention on and off (`SurfaceCellTransitionQuotientTests.cpp:9765`).
- **Consumers today:**
  - the GUI reads `sourceTopologyRegions`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, `globalTopologyPlan` and `traceNetwork` (`src/gui/GuiRemesh.cpp:75–101`);
  - the CLI sets retention for `--surface-cell-preserve-debug-artifacts` (`src/cli/RemeshCommand.cpp:176`) but reads no snapshots.
- **No memory cap exists**; only ownership accounting.
- **The public materializer's exact signature is pinned** (`SurfaceCellsPhase10Tests.cpp:10175`: `decltype(&build_authoritative_phase_front_mesh) == Materializer`). It is an authority contract: the materializer consumes only V, F and the published phase front.

#### RA-184.2 Design (CB58)

- **Snapshot fields.** `SurfaceCellDiagnosticProductSnapshots` gains three members, each a `std::shared_ptr<const T>` (immutable, so it cannot be used as a mutable authority; a forward declaration is enough):
  - `occurrenceComplex` (A5: corner occurrences with support, placement and wedge bindings, plus relations with kind, endpoints and evidence);
  - `quotientProduct` (A6: merged quotient classes);
  - `sourceAttachedGeometry` (A7: final vertex geometry).
- **Copy points.**
  - The helper takes an optional `AuthoritativePhaseFrontDiagnostics *`. It copies each product **immediately after that stage succeeds and before the next stage runs**, so a later rejection keeps every product completed before it.
  - `build_authoritative_phase_front_mesh` keeps its pinned signature and passes `nullptr`. A separately named `build_authoritative_phase_front_mesh_with_diagnostics` exposes the copies.
- **Retention.**
  - The tracing stage passes the diagnostics only under `retainForExecution`, and moves the copies into the snapshots on both success and failure.
  - `clear_unrequested_intermediate_context` drops them when retention was not requested, as for `traceNetwork`.
- **No read-back.** Downstream code uses the helper's own locals and result. The snapshots are copies and nothing reads them. The tests require retained and released runs to give the same outcome.
- **Memory bound.**
  - At most one copy of each product per materialization, linear in the output: about 4 occurrences per cell plus relations, about one class per output vertex, and one geometry vertex per class.
  - The copies exist only while retention is on, and are released with the other unrequested intermediates.

#### RA-184.3 Probe evidence

Builds are local CB57 source plus the CB58 patch, default arithmetic.

- **New `SurfaceCellTransitionQuotient.MaterializationProductsAreRetainedIfAndOnlyIfRequested`** passes. On the plane, stopped after tracing, all three snapshots are present when requested and absent otherwise; the failure code and stage are identical; cell and class counts are consistent.
- **New `SurfaceCellAuthorityContractCutover.MaterializationDiagnosticsAreCopiesAndStopAtTheFailingStage`** passes.
  - On success, the mesh is identical with and without diagnostics. Occurrence cells = classed cells = output quads, and classes = geometry vertices.
  - On the strict hard-rail transport negative (rejected **by A5**), the failure is unchanged and nothing is retained.
- **Failing-first evidence is compile-level:** both tests use the new API.
- **No regressions:** the signature pin stays green, and the existing retention test passes. The full gate (861) gives 860/861 (only 283); all 859 TB56 rows are unchanged; the 82 deferred rows have identical verdicts and first-failure sites.

#### RA-184.4 Open items

- **DR1 (witness gap).** No current fixture gives a phase front that A5 accepts and A6, A7 or verification rejects; existing A6 negatives tamper A5 records and call A6 directly. So "products completed before a later in-helper rejection are kept" holds by construction and is witnessed only for a rejection after materialization (the injected failure). **Owner:** add the assertion when such a stimulus exists (for example from P13 fixtures).
- **DR2.** The multi-component aggregation path (`RemeshPipeline.cpp:17866–19365`) does not merge these snapshots. **Owner:** the CLI/GUI DEFN decides whether per-component products are exposed.
- **DR3 (pre-existing, unchanged).** Most existing snapshot fields are written even when retention is off; only four are cleared. Noted, not changed here.

#### RA-184.5 CB58 — exact patch

**Turn:** `M6-CB58-DIAG-RETAIN-A5-A7-SNAPSHOTS` (CB), run locally; Code + Build.
- **Scope:**
  - `include/directional/pipeline/RemeshPipeline.h`: `27 0`.
  - `src/pipeline/RemeshPipeline.cpp`: `39 3`.
  - `tests/SurfaceCellTransitionQuotientTests.cpp`: `47 0`.
  - `tests/SurfaceCellsPhase10Tests.cpp`: `50 0`.
- **Checks:**
  - The RA-184.7 block, extracted verbatim with a trailing newline, has SHA-256 `c72e47cc54c407af5921bf80aaeec043bd3add928b24046dfc879f56e9041b0e`.
  - `git apply --check`, then apply; the numstat must be exactly as above.
  - The resulting SHA-256 must be:
    - header `37f85237555d843ce71934825197cb3e599cb007aba6529e8b1a97ea275b1a4d`;
    - source `47d77eb7ec4d7356f43890669b7b9158929b236695249956be2ddd8e264c410c`;
    - Phase10 `913b97e7a3731aff9899f108cb81d9499517f55071a87376355ddd8e6da27bac`;
    - TQ `358dabaddacf61798c6f6e5cf5d723c2367bca56d9e1e192f2165b61abe4b191`.
  - Build the eight targets at default arithmetic and stage the package. No native tests.

| CB58 result | Successor |
|---|---|
| All exact, package built | `M6-TB57-DIAG-RETAIN-FULL-GATE-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB58A-DIAG-RETAIN-ORCH`, then one retry |

#### RA-184.6 TB57 frozen inputs

- **Gate:** [`Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv"), 861 rows, SHA-256 `f898c9b67c6f6f2c7ffa5bfaf054cb82dc8b691db0f74f0d28e3bee5ceab2b32`.
  - The first 860 lines are TB56 (`c8437d61…`).
  - Rows 860 (`ra184:diag-retain-helper-copies`) and 861 (`ra184:diag-retain-iff-requested`) are GUARD rows in the producer binary.
- **Ledger:** v4 is unchanged (82).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=861 deferred=82`. The real membership check of the patched binaries gives **943**.

| TB57 result (local) | Successor |
|---|---|
| 860/861 PASS, with row 283 (O16) the only RED, postflight true, membership 943 | `M6-DEFN-DIAG-RETAIN-CLI-GUI` (no separate REV) |
| Any other non-PASS | `M6-TB57-DIAG-RETAIN-FULL-GATE-REV` (R) |
| Membership error | `M6-PLAN-DIAG-RETAIN-MEMBERSHIP-STOP` (PLAN, R) |

#### RA-184.7 Exact CB58 patch

~~~diff
diff --git a/include/directional/pipeline/RemeshPipeline.h b/include/directional/pipeline/RemeshPipeline.h
index a42489260..d7852d79e 100644
--- a/include/directional/pipeline/RemeshPipeline.h
+++ b/include/directional/pipeline/RemeshPipeline.h
@@ -22,6 +22,7 @@
 #include <iostream>
 #include <limits>
 #include <map>
+#include <memory>
 #include <numeric>
 #include <optional>
 #include <set>
@@ -289,6 +290,10 @@ struct RemeshOptions {
   std::function<void(const MesherData &)> mesherDataCallback;
 };
 
+class SurfaceOccurrenceComplex;
+class SurfaceQuotientProduct;
+class SourceAttachedGeometryProduct;
+
 struct SurfaceCellContextProductDebug {
   std::string name;
   std::string type;
@@ -341,6 +346,13 @@ struct SurfaceCellDiagnosticProductSnapshots {
   bool hasOptimizationResult = false;
   geometry::SurfaceFinalValidationReport validationResult;
   bool hasValidationResult = false;
+
+  // A5-A7 products of the phase-front materialization, including those
+  // completed before a later stage rejected. Retained only when intermediate
+  // geometry is retained; immutable copies, never read back.
+  std::shared_ptr<const SurfaceOccurrenceComplex> occurrenceComplex;
+  std::shared_ptr<const SurfaceQuotientProduct> quotientProduct;
+  std::shared_ptr<const SourceAttachedGeometryProduct> sourceAttachedGeometry;
 };
 
 /**
@@ -1560,6 +1572,13 @@ struct AuthoritativePhaseFrontMeshResult {
   std::optional<VerificationReport> verificationReport;
 };
 
+/// Diagnostic copies of each A5-A7 product as soon as it is produced.
+struct AuthoritativePhaseFrontDiagnostics {
+  std::shared_ptr<const SurfaceOccurrenceComplex> occurrenceComplex;
+  std::shared_ptr<const SurfaceQuotientProduct> quotientProduct;
+  std::shared_ptr<const SourceAttachedGeometryProduct> sourceAttachedGeometry;
+};
+
 std::string verification_failure_message(const VerificationReport &report);
 
 class SurfaceProductVerifier;
@@ -1634,6 +1653,14 @@ AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(
     const Eigen::MatrixXi &sourceFaces,
     const geometry::SurfacePhaseFrontProduct &phaseFront);
 
+/// The same materialization, also copying each A5-A7 product into
+/// `diagnostics` as soon as it is produced (one-way observation only).
+AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh_with_diagnostics(
+    const Eigen::MatrixXd &sourceVertices,
+    const Eigen::MatrixXi &sourceFaces,
+    const geometry::SurfacePhaseFrontProduct &phaseFront,
+    AuthoritativePhaseFrontDiagnostics &diagnostics);
+
 using RemeshPipelineClock = std::chrono::steady_clock;
 
 double remesh_elapsed_seconds(
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index 1ec7a0474..5421e8e39 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -9224,7 +9224,8 @@ build_authoritative_phase_front_mesh_with_hard_features(
     const Eigen::MatrixXd &sourceVertices,
     const Eigen::MatrixXi &sourceFaces,
     const geometry::SurfacePhaseFrontProduct &phaseFront,
-    const std::set<authority::SourceEdgeTopologyKey> *hardFeatureRailEdges) {
+    const std::set<authority::SourceEdgeTopologyKey> *hardFeatureRailEdges,
+    AuthoritativePhaseFrontDiagnostics *diagnostics) {
   AuthoritativePhaseFrontMeshResult result;
 
   result.mesh.sourcePatch = 0;
@@ -9260,6 +9261,10 @@ build_authoritative_phase_front_mesh_with_hard_features(
     }
     return result;
   }
+  if (diagnostics != nullptr) {
+    diagnostics->occurrenceComplex =
+        std::make_shared<const SurfaceOccurrenceComplex>(*occurrenceComplex);
+  }
 
   auto quotientConstruction =
       hardFeatureRailEdges == nullptr
@@ -9313,6 +9318,10 @@ build_authoritative_phase_front_mesh_with_hard_features(
     }
     return result;
   }
+  if (diagnostics != nullptr) {
+    diagnostics->quotientProduct =
+        std::make_shared<const SurfaceQuotientProduct>(*quotientProduct);
+  }
 
   auto geometryConstruction = SourceAttachedGeometryProducer::produce(
       sourceVertices, sourceFaces, *occurrenceComplex, *quotientProduct);
@@ -9357,6 +9366,10 @@ build_authoritative_phase_front_mesh_with_hard_features(
     }
     return result;
   }
+  if (diagnostics != nullptr) {
+    diagnostics->sourceAttachedGeometry =
+        std::make_shared<const SourceAttachedGeometryProduct>(*geometryProduct);
+  }
 
   static const std::set<authority::SourceEdgeTopologyKey> kNoHardFeatureEdges;
   const auto &verificationHardFeatureEdges =
@@ -9409,7 +9422,16 @@ AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(
     const Eigen::MatrixXi &sourceFaces,
     const geometry::SurfacePhaseFrontProduct &phaseFront) {
   return build_authoritative_phase_front_mesh_with_hard_features(
-      sourceVertices, sourceFaces, phaseFront, nullptr);
+      sourceVertices, sourceFaces, phaseFront, nullptr, nullptr);
+}
+
+AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh_with_diagnostics(
+    const Eigen::MatrixXd &sourceVertices,
+    const Eigen::MatrixXi &sourceFaces,
+    const geometry::SurfacePhaseFrontProduct &phaseFront,
+    AuthoritativePhaseFrontDiagnostics &diagnostics) {
+  return build_authoritative_phase_front_mesh_with_hard_features(
+      sourceVertices, sourceFaces, phaseFront, nullptr, &diagnostics);
 }
 
 } // namespace directional::pipeline
@@ -12380,6 +12402,9 @@ remesh_from_raw_cross_field_impl_with_stage_products(
       result.surfaceCellContext.hasEmbeddedArrangementArcs = false;
       result.surfaceCellContext.productSnapshots.arrangement = geometry::SurfaceCellComplex{};
       result.surfaceCellContext.hasArrangement = false;
+      result.surfaceCellContext.productSnapshots.occurrenceComplex.reset();
+      result.surfaceCellContext.productSnapshots.quotientProduct.reset();
+      result.surfaceCellContext.productSnapshots.sourceAttachedGeometry.reset();
 
       result.surfaceCellContext.tracingCurrentOwnedBytes = 0U;
       result.surfaceCellContext.flowRepCurrentOwnedBytes = 0U;
@@ -13337,10 +13362,21 @@ remesh_from_raw_cross_field_impl_with_stage_products(
     const bool useAuthoritativePhaseFront = phaseFrontProduct != nullptr;
     AuthoritativePhaseFrontMeshResult authoritativePhaseFrontMesh;
     if (useAuthoritativePhaseFront) {
+      AuthoritativePhaseFrontDiagnostics materializationDiagnostics;
       authoritativePhaseFrontMesh =
           build_authoritative_phase_front_mesh_with_hard_features(
               meshWhole.V, meshWhole.F, *phaseFrontProduct,
-              &hardFeatureRailEdges);
+              &hardFeatureRailEdges,
+              retainForExecution ? &materializationDiagnostics : nullptr);
+      if (retainForExecution) {
+        auto &snapshots = result.surfaceCellContext.productSnapshots;
+        snapshots.occurrenceComplex =
+            std::move(materializationDiagnostics.occurrenceComplex);
+        snapshots.quotientProduct =
+            std::move(materializationDiagnostics.quotientProduct);
+        snapshots.sourceAttachedGeometry =
+            std::move(materializationDiagnostics.sourceAttachedGeometry);
+      }
       if (!authoritativePhaseFrontMesh.success) {
         result.diagnostics.surfaceCellFirstInvalidProducerStage =
             "tracing/phase-front-materialization";
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index 219b20eb9..d6518abea 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -9805,6 +9805,53 @@ TEST(SurfaceCellTransitionQuotient,
             released.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.produced_product());
 }
 
+// DIAG-RETAIN (RA-184): the A5-A7 materialization products are retained as
+// one-way snapshots iff intermediate geometry is requested, without changing
+// the outcome.
+TEST(SurfaceCellTransitionQuotient,
+     MaterializationProductsAreRetainedIfAndOnlyIfRequested) {
+  const auto meshPath = directional::tests::benchmark_fixture_path(
+      "milestone-g/plane.obj");
+  const auto fieldPath = directional::tests::benchmark_fixture_path(
+      "milestone-g/plane.rawfield");
+  directional::TriMesh mesh;
+  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
+  const Eigen::MatrixXd raw = read_rawfield(fieldPath, mesh.F.rows());
+  const auto run = [&](const bool retain) {
+    directional::pipeline::RemeshOptions options;
+    options.lengthRatio = 0.2;
+    options.integralSeamless = false;
+    options.roundSeams = false;
+    options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
+    options.surfaceCells.enabled = true;
+    options.surfaceCells.fallbackPolicy =
+        directional::pipeline::SurfaceCellFallbackPolicy::Fail;
+    options.surfaceCells.allowSourceGridRecovery = false;
+    options.surfaceCells.retainIntermediateGeometry = retain;
+    options.surfaceCells.injectFailureAfterStage = 3;
+    return directional::pipeline::remesh_from_raw_cross_field(
+        mesh.V, mesh.F, raw, options);
+  };
+  const auto retained = run(true);
+  const auto released = run(false);
+  EXPECT_EQ(retained.diagnostics.terminalFailureCode,
+            released.diagnostics.terminalFailureCode);
+  EXPECT_EQ(retained.diagnostics.terminalFailureStage,
+            released.diagnostics.terminalFailureStage);
+  const auto &kept = retained.surfaceCellContext.productSnapshots;
+  const auto &dropped = released.surfaceCellContext.productSnapshots;
+  ASSERT_NE(nullptr, kept.occurrenceComplex);
+  ASSERT_NE(nullptr, kept.quotientProduct);
+  ASSERT_NE(nullptr, kept.sourceAttachedGeometry);
+  EXPECT_EQ(kept.occurrenceComplex->cells().size(),
+            kept.quotientProduct->classed_cells().size());
+  EXPECT_EQ(kept.quotientProduct->classes().size(),
+            kept.sourceAttachedGeometry->vertices().size());
+  EXPECT_EQ(nullptr, dropped.occurrenceComplex);
+  EXPECT_EQ(nullptr, dropped.quotientProduct);
+  EXPECT_EQ(nullptr, dropped.sourceAttachedGeometry);
+}
+
 TEST(SurfaceCellTransitionQuotient,
      SemanticDigestIsInvariantToVertexFaceAndComponentRowPermutation) {
   const auto baseline = semantic_two_component_result();
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index e30db35fa..0694b23e7 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -9084,6 +9084,56 @@ TEST(SurfaceCellAuthorityContractCutover,
   EXPECT_EQ("InvalidHardRailTransport", rejected.failure);
 }
 
+// DIAG-RETAIN (RA-184): each A5-A7 product is copied as soon as it is
+// produced, the copies never change the materialization result, and a stage
+// that rejects leaves no copy of its own or any later product.
+TEST(SurfaceCellAuthorityContractCutover,
+     MaterializationDiagnosticsAreCopiesAndStopAtTheFailingStage) {
+  const auto fixture = build_rectangular_hard_rail_phase_front();
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
+            fixture.network.phaseFront.disposition())
+      << hard_rail_first_failure_detail(fixture.network);
+  const auto &product = fixture.network.phaseFront.product();
+
+  directional::pipeline::AuthoritativePhaseFrontDiagnostics accepted;
+  const auto materialized =
+      directional::pipeline::build_authoritative_phase_front_mesh_with_diagnostics(
+          fixture.mesh.V, fixture.mesh.F, product, accepted);
+  const auto plain = directional::pipeline::build_authoritative_phase_front_mesh(
+      fixture.mesh.V, fixture.mesh.F, product);
+  ASSERT_TRUE(materialized.success) << materialized.failure;
+  EXPECT_EQ(plain.mesh.quads, materialized.mesh.quads);
+  EXPECT_TRUE(plain.mesh.vertexPositions == materialized.mesh.vertexPositions);
+  ASSERT_NE(nullptr, accepted.occurrenceComplex);
+  ASSERT_NE(nullptr, accepted.quotientProduct);
+  ASSERT_NE(nullptr, accepted.sourceAttachedGeometry);
+  EXPECT_EQ(materialized.mesh.quads.size(), accepted.occurrenceComplex->cells().size());
+  EXPECT_EQ(materialized.mesh.quads.size(), accepted.quotientProduct->classed_cells().size());
+  EXPECT_EQ(accepted.quotientProduct->classes().size(),
+            accepted.sourceAttachedGeometry->vertices().size());
+
+  // The strict hard-rail transport negative is rejected by A5 itself.
+  const auto pairs = hard_rail_phase_front_pairs(product);
+  ASSERT_FALSE(pairs.empty());
+  auto edges = product.edges();
+  auto &first = edges[static_cast<std::size_t>(pairs.front().first)];
+  auto &second = edges[static_cast<std::size_t>(pairs.front().second)];
+  second.route = first.route;
+  const auto tampered = rebuild_phase_front_with_edges(product, std::move(edges), fixture);
+  directional::pipeline::AuthoritativePhaseFrontDiagnostics rejectedDiagnostics;
+  const auto rejected =
+      directional::pipeline::build_authoritative_phase_front_mesh_with_diagnostics(
+          fixture.mesh.V, fixture.mesh.F, tampered, rejectedDiagnostics);
+  const auto plainRejected = directional::pipeline::build_authoritative_phase_front_mesh(
+      fixture.mesh.V, fixture.mesh.F, tampered);
+  EXPECT_FALSE(rejected.success);
+  EXPECT_EQ("InvalidHardRailTransport", rejected.failure);
+  EXPECT_EQ(plainRejected.failure, rejected.failure);
+  EXPECT_EQ(nullptr, rejectedDiagnostics.occurrenceComplex);
+  EXPECT_EQ(nullptr, rejectedDiagnostics.quotientProduct);
+  EXPECT_EQ(nullptr, rejectedDiagnostics.sourceAttachedGeometry);
+}
+
 TEST(SurfaceCellAuthorityContractCutover,
      HardRailPairChangedRouteContentRejectsStrictTransport) {
   const auto fixture = build_rectangular_hard_rail_phase_front();
~~~

## `Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md`; moved verbatim.

### RA-186 — DIAG-RETAIN: CLI materialization sidecar (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING` (DEFN, Review track), run locally. It wires the CB59 dump ([RA-185](#architecture_m6_defn_diag_retain_materialization_display_20261031md "moved: Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md")) into the CLI and splits the GUI layers into their own DEFN.
- **Method:** probes are diagnostic only. Source is CB59 `39a77d2e…`, unchanged in `src/`, `include/`, `tests/`, `CMakeLists.txt` and `cmake/` at HEAD. The probe is a CLI-ON reconfigure of the probe build tree (CB59 source plus the CB60 patch). The Review agent designed, probed and ruled.

#### RA-186.1 Findings

- **The CLI throws before writing any diagnostics when the result is not produced** (`src/cli/RemeshCommand.cpp`, the `!result.is_produced()` check before `write_remeshed_mesh`). A rejected SurfaceCells run is exactly where the retained A5–A7 products matter.
- **DR4 (pre-existing, new).** `--diagnostics-prefix` fails on every SurfaceCells product: `write_remesh_diagnostics` writes `.degrees.dmat`, then calls `write_triangle_obj`/`write_triangle_off` on the product's cut mesh (`src/cli/RemeshOutput.cpp:388–392`), and a SurfaceCells product has none, so it throws `Triangle OBJ output faces must have shape (#F, 3).` The output mesh is already written. Probe run B below shows it without the CB60 dump.
- **GUI.** A GUI-ON build compiles polyscope, ImGui and GLFW, which no local tree has yet. The GUI layers get their own DEFN with that build as its first probe.

#### RA-186.2 Rulings

- **CB60: the CLI sidecar.** After the remesh call and **before** the produced-result check, when `--diagnostics-prefix <p>` is given and any of the three snapshots is present, the CLI writes `<p>.materialization.txt` with `write_materialization_diagnostics`. The snapshots are present only under `--surface-cell-preserve-debug-artifacts`, which already sets retention. The usage text gains two lines. Nothing else changes; the pipeline and its result are untouched.
- **GUI layers → `M6-DEFN-DIAG-RETAIN-GUI-LAYERS`** (DEFN, R): optional layers over `materialization_diagnostics_display` (occurrence points coloured by class, cell sides, relations, A7 quads), probed in a GUI-ON build.
- **DR4: carried, owner M8-CP2** (CLI hardening): skip or adapt the cut-mesh sidecars for SurfaceCells products. It is independent of DIAG-RETAIN; the materialization sidecar is written before it fails.

#### RA-186.3 Probe evidence

CLI-ON probe binary from CB59 source plus the CB60 patch, default arithmetic. Fixture `benchmarks/fixtures/milestone-g/plane.{obj,rawfield}`; common options `--raw-field <plane.rawfield> --remesh-backend SurfaceCells --surface-cell-fallback Fail --length-ratio 0.2`.

| Run | Extra options | Exit | Files after the run |
|---|---|---|---|
| A | `--surface-cell-preserve-debug-artifacts --diagnostics-prefix <d>/plane` | 1 (DR4 message) | `out.obj`, `plane.degrees.dmat`, **`plane.materialization.txt`** |
| B | `--diagnostics-prefix <d>/plane` | 1 (DR4 message) | `out.obj`, `plane.degrees.dmat`; no materialization file |
| C | `--surface-cell-preserve-debug-artifacts` | 0 | `out.obj` only |

- **Run A's dump** has 645 lines, with headers `A5 occurrence-complex cells=64 occurrences=256 relations=224`, `A6 quotient-product classes=81 classed-cells=64` and `A7 source-attached-geometry vertices=81 cells=64`, followed by 256 `occurrence`, 224 `relation`, 81 `class` and 81 `vertex` lines (a 9×9 vertex grid of 64 quads).
- Run B shows that DR4 predates CB60 and that no dump is written without retention. Run C shows the sidecar needs the prefix.
- The new lines stay within the file's existing line-length profile, and the CB59 gate binaries are untouched (CB60 changes only `src/cli/`, which none of the eight gate targets compile).

#### RA-186.4 CB60 — exact patch

**Turn:** `M6-CB60-DIAG-RETAIN-CLI-SIDECAR` (CB), run locally; Code + Build.
- **Scope:** `src/cli/RemeshCommand.cpp` `12 0`; `src/cli/Usage.cpp` `2 0`.
- **Checks:**
  - The RA-186.7 block, extracted verbatim with a trailing newline, has SHA-256 `d14aaeff98b662c70e49f0a64f3dfad4df355e97320301a6341d4d7ad2e2a784`.
  - `git apply --check`, then apply; the numstat must be exactly as above.
  - The resulting SHA-256 must be `418fbf8b055c1b88c3c6898b4e1921a0628e7f1e3d6a7208e0a44bb2d63a0e47` (`RemeshCommand.cpp`) and `91817875227bfa81f05a1b9bf1549a97ad6ec0f15550f60e4851f8a7df3cd86b` (`Usage.cpp`).
- **Build:** a fresh configure of a clean worktree with the CI flags **plus `-DDIRECTIONAL_BUILD_CLI=ON`**, building only `directional_cli` (executable `directional`). Stage `build/local-evidence/CB60/` with `bin/directional`, the standard metadata (`compiled-targets.txt` = `directional_cli`), `SHA256SUMS` and `pkg.zip`. No native runs.

| CB60 result | Successor |
|---|---|
| All exact, CLI built | `M6-TB59-DIAG-RETAIN-CLI-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-CLI-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB60A-DIAG-RETAIN-CLI-ORCH`, then one retry |

#### RA-186.5 TB59 frozen check run

`M6-TB59-DIAG-RETAIN-CLI-EXEC` (TB-EXEC, local) runs the staged `bin/directional` three times, each in its own new output directory, with the RA-186.3 options.

| TB59 result | Successor |
|---|---|
| A, B and C exactly as in the RA-186.3 table, and run A's dump has exactly those three header lines and 256/224/81/81 element lines | `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` (no separate REV) |
| Anything else | `M6-TB59-DIAG-RETAIN-CLI-REV` (R) |

The five-binary gate is not re-run: no gate binary changes (TB58 862/863 stands).

#### RA-186.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CB60-DIAG-RETAIN-CLI-SIDECAR` → `M6-TB59-DIAG-RETAIN-CLI-EXEC` | CB, TB-EXEC / local | runs A–C as registered |
| then | `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` (GUI-ON build probe first) | DEFN / R | frozen GUI CB |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | DR1, DR3 (RA-184.4); DR2, DR4 → M8-CP2; O2b, O15b, O15c, O16; Linux CI confirmation of rows 854–859 | — | — |

#### RA-186.7 Exact CB60 patch

~~~diff
diff --git a/src/cli/RemeshCommand.cpp b/src/cli/RemeshCommand.cpp
index e87e6760c..b94e17bc6 100644
--- a/src/cli/RemeshCommand.cpp
+++ b/src/cli/RemeshCommand.cpp
@@ -9,6 +9,7 @@
 
 #include <cmath>
 #include <filesystem>
+#include <fstream>
 #include <iostream>
 #include <optional>
 #include <stdexcept>
@@ -16,6 +17,7 @@
 
 #include <directional/fields/RegularizedCurvatureCrossField.h>
 #include <directional/pipeline/RemeshPipeline.h>
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
 
 namespace directional::cli {
 namespace {
@@ -404,6 +406,16 @@ int run_remesh(const int argc, char **argv) {
     result = pipeline::remesh_from_mesh(mesh.vertices, mesh.faces, options);
   }
 
+  // A rejected SurfaceCells run is where the retained A5-A7 products matter
+  // most, so their dump is written before the produced-result check.
+  const auto &snapshots = result.surfaceCellContext.productSnapshots;
+  if (diagnosticsPrefix.has_value() &&
+      (snapshots.occurrenceComplex || snapshots.quotientProduct ||
+       snapshots.sourceAttachedGeometry)) {
+    std::ofstream dump(diagnosticsPrefix->string() + ".materialization.txt");
+    visualization::write_materialization_diagnostics(dump, snapshots);
+  }
+
   if (!result.is_produced()) {
     throw std::runtime_error(
         "Remeshing failed while simplifying or assembling the output mesh"
diff --git a/src/cli/Usage.cpp b/src/cli/Usage.cpp
index 873e80c4b..b3c7e3706 100644
--- a/src/cli/Usage.cpp
+++ b/src/cli/Usage.cpp
@@ -120,6 +120,8 @@ void print_usage(std::ostream &stream) {
       << "  --curvature-sharp-angle <degrees>\n"
       << "  --smooth-curvature-across-features\n"
       << "  --diagnostics-prefix <p>        Write pipeline result arrays as sidecars.\n"
+      << "                                  With --surface-cell-preserve-debug-artifacts, also\n"
+      << "                                  writes retained A5-A7 products to <p>.materialization.txt.\n"
       << "  --verbose                       Print pipeline timing details.\n";
 }
 
~~~

## `Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md`; moved verbatim.

### RA-187 — DIAG-RETAIN: GUI layers; full-gate correction for the CLI slice (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` (DEFN, Review track), run locally. It adds GUI layers over the CB59 adapter ([RA-185](#architecture_m6_defn_diag_retain_materialization_display_20261031md "moved: Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md")) and corrects how the CLI slice ([RA-186](#architecture_m6_defn_diag_retain_cli_materialization_sidecar_20261031md "moved: Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md")) was tested.
- **Method:** probes are diagnostic only. Source is CB60 `a31f2d39…`, unchanged in `src/`, `include/`, `tests/`, `CMakeLists.txt` and `cmake/` at HEAD. The probe is a GUI-ON reconfigure of the probe build tree (CB59 source plus the CB60 and CB61 patches). The Review agent designed, probed and ruled.

#### RA-187.1 Findings

- **GUI data path.** `run_surface_cell_diagnostics` (`src/gui/GuiRemesh.cpp`) already runs with `retainIntermediateGeometry = true` and, for the quick view, `injectFailureAfterStage = 3`, so A5–A7 are retained whenever tracing completes. Each product becomes an optional field of `SurfaceCellDiagnosticsData` (`src/gui/GuiBackend.h`), drawn by `visualize_surface_cell_diagnostics` (`src/gui/Main.cpp`), which also owns layer removal and transform sync.
- **No GUI tests exist**, and polyscope needs a display, so the only automatable GUI check is a clean compile and link. The data the layers draw is already gate-tested through the CB59 adapter (rows 862–863).
- **Cadence correction.** `Turn_Cadence.md` §2 requires every TB to execute the full current gate. TB59 ran only the three CLI cases, because the CB60 package held only the CLI. That was a deviation: the CLI slice has no full-gate TB. CB60 changed only `src/cli/`, which none of the gate binaries compile, so no gate verdict can have changed, but the cadence still requires the run.

#### RA-187.2 Rulings

- **CB61: the GUI layers** (`src/gui/GuiBackend.h` `5 0`, `GuiRemesh.cpp` `5 0`, `Main.cpp` `52 8`).
  - `SurfaceCellDiagnosticsData` gains `std::optional<MaterializationDiagnosticsDisplay> materialization`, filled whenever any of the three snapshots is present.
  - Three layers: `A5 occurrence cell sides` (curve network), `A5 corner occurrences` (point cloud with the categorical `A6 quotient class` quantity when A6 was retained) and `A7 source-attached geometry` (quad surface mesh, off by default). They are removed and transform-synced with the other SurfaceCells layers. Relations are left out of the GUI because related occurrences coincide; the dump keeps them.
  - The layers only read the display arrays. No pipeline option, admission or ordering changes.
- **CB61 builds everything once, and TB60 runs the full gate plus the CLI cases.** One fresh configure with the CI flags plus `-DDIRECTIONAL_BUILD_CLI=ON -DDIRECTIONAL_BUILD_GUI=ON` builds the eight gate targets, `directional_cli` and `directional_gui`. It stages two packages from that tree:
  - `pkg.zip`, the standard eight-target package, for the gate;
  - `tools.zip`, holding `bin/directional` and `bin/directional-ui`, with the same metadata layout.

  TB60 runs the 863-row TB58 gate on `pkg.zip` and the three RA-186.3 CLI cases on `tools.zip`, and checks that `directional-ui` links against the same GMP. This gives both the CLI slice and the GUI slice a full-gate TB.
- **Manual check.** The layers' appearance needs a person at the GUI. It is not an agent gate; the user can open a SurfaceCells diagnostics run and toggle the three layers.

#### RA-187.3 Probe evidence

- GUI-ON reconfigure and `directional_gui` build of the probe tree: configure 0, build 0 (the first GUI-ON build took about a minute); with the CB61 patch, the incremental rebuild compiles and links `directional-ui` with no errors and no new warnings in the three files.
- The CLI-ON probe and the TB59 runs (RA-186.3, TB59) are unchanged by CB61, which touches only `src/gui/`.
- No full-gate probe: CB61 changes no gate binary source. TB60 runs the full gate.

#### RA-187.4 CB61 — exact patch

**Turn:** `M6-CB61-DIAG-RETAIN-GUI-LAYERS` (CB), run locally; Code + Build.
- **Checks:**
  - The RA-187.7 block, extracted verbatim with a trailing newline, has SHA-256 `afab7d5dc08ec1976b0ef36b22c34757b295f6b010753edf2b26fa7565983e4e`.
  - `git apply --check`, then apply; the numstat must be exactly `5 0` (`src/gui/GuiBackend.h`), `5 0` (`src/gui/GuiRemesh.cpp`) and `52 8` (`src/gui/Main.cpp`).
  - The resulting SHA-256 must be `6cc1c79ad345788abf234153e86d5b38bf0926e96dfc1de18bfbfdf462423a48` (`GuiBackend.h`), `8a4ed4a95205b6c30b1d27a882da94e80218e0bf8885b2f2625f806422becbd9` (`GuiRemesh.cpp`) and `c601f6e717f3e36ef46d6c5d3018724788dc7231e0cccb530b0ef9e739b851c5` (`Main.cpp`).
- **Build:** a fresh configure of a clean worktree with the CI flags plus `-DDIRECTIONAL_BUILD_CLI=ON -DDIRECTIONAL_BUILD_GUI=ON`, at default arithmetic. Build the eight gate targets, `directional_cli` and `directional_gui`. Stage `build/local-evidence/CB61/pkg.zip` (the standard eight-target layout) and `build/local-evidence/CB61/tools.zip` (`bin/directional`, `bin/directional-ui`, the same metadata files with `compiled-targets.txt` = `directional_cli` and `directional_gui`). No native runs.

| CB61 result | Successor |
|---|---|
| All exact, both packages built | `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-GUI-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB61A-DIAG-RETAIN-GUI-ORCH`, then one retry |

#### RA-187.5 TB60 frozen inputs

- **Gate:** the TB58 manifest [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv") unchanged (863 rows, `31c1360a…`); ledger v4 (82, `36241caa…`); membership 945.
- **CLI cases:** the three RA-186.3 runs with the TB59 check script (`build/local-evidence/TB59/tb59_check.sh`, `16137c4e…`) against `tools.zip`'s `bin/directional`.
- **GUI link check:** `otool -L bin/directional-ui` lists the same Homebrew GMP libraries as `pkg.zip`'s `gmp-evidence.txt`.

| TB60 result (local) | Successor |
|---|---|
| Gate 862/863 with row 283 (O16) the only RED, postflight true, membership 945; CLI checks 11/11; GUI link check true | P13 probe DEFN (DIAG-RETAIN closed; no separate REV) |
| Any other non-PASS | `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-REV` (R) |
| Membership error | `M6-PLAN-DIAG-RETAIN-GUI-MEMBERSHIP-STOP` (PLAN, R) |

#### RA-187.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CB61-DIAG-RETAIN-GUI-LAYERS` → `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` | CB, TB-EXEC / local | 862/863 (only 283), CLI 11/11, GUI link true |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | DR1, DR3 (RA-184.4); DR2, DR4 → M8-CP2; O2b, O15b, O15c, O16; Linux CI confirmation of rows 854–859 | — | — |

#### RA-187.7 Exact CB61 patch

~~~diff
diff --git a/src/gui/GuiBackend.h b/src/gui/GuiBackend.h
index 18901faec..81a9d48e3 100644
--- a/src/gui/GuiBackend.h
+++ b/src/gui/GuiBackend.h
@@ -12,6 +12,7 @@
 #include <directional/fields/CompareCrossFields.h>
 #include <directional/visualization/CutGraphDisplay.h>
 #include <directional/visualization/FieldAlignedNetworkPolylines.h>
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
 #include <directional/visualization/SourceRegionDisplay.h>
 #include <directional/visualization/SurfaceCellTracingDisplay.h>
 #include <directional/visualization/TargetSizeDisplay.h>
@@ -133,6 +134,10 @@ struct SurfaceCellDiagnosticsData {
   std::optional<visualization::FieldAlignedNetworkPolylines> network;
   /// The A2a' cut graph and A2b disc regions, when either was published.
   std::optional<visualization::CutGraphDisplay> cutGraph;
+  /// The A5-A7 occurrences, quotient classes and source-attached geometry,
+  /// when the run completed them.
+  std::optional<visualization::MaterializationDiagnosticsDisplay>
+      materialization;
   /// Where the run stopped and, when quad tracing produced them, its cells.
   visualization::SurfaceCellTracingDisplay tracing;
   bool pipelineProduced = false;
diff --git a/src/gui/GuiRemesh.cpp b/src/gui/GuiRemesh.cpp
index 1b4c85e8c..a6f7dd3a0 100644
--- a/src/gui/GuiRemesh.cpp
+++ b/src/gui/GuiRemesh.cpp
@@ -89,6 +89,11 @@ SurfaceCellDiagnosticsData run_surface_cell_diagnostics(
         snapshots.surfaceCutGraph ? &*snapshots.surfaceCutGraph : nullptr,
         snapshots.globalTopologyPlan ? &*snapshots.globalTopologyPlan : nullptr);
   }
+  if (snapshots.occurrenceComplex || snapshots.quotientProduct ||
+      snapshots.sourceAttachedGeometry) {
+    result.materialization =
+        visualization::materialization_diagnostics_display(snapshots);
+  }
   const auto &context = remesh.surfaceCellContext;
   result.tracing = visualization::surface_cell_tracing_display(
       mesh.vertices, mesh.faces, remesh.diagnostics,
diff --git a/src/gui/Main.cpp b/src/gui/Main.cpp
index 558069605..f41e138ed 100644
--- a/src/gui/Main.cpp
+++ b/src/gui/Main.cpp
@@ -57,6 +57,10 @@ constexpr const char *kStopEdgesName = "SurfaceCells stop edges";
 constexpr const char *kStopVerticesName = "SurfaceCells stop vertices";
 constexpr const char *kTracedCellsName = "A4 traced cells";
 constexpr const char *kTracedCornersName = "A4 cell corners";
+constexpr const char *kOccurrenceSidesName = "A5 occurrence cell sides";
+constexpr const char *kOccurrencesName = "A5 corner occurrences";
+constexpr const char *kQuotientClassQuantity = "A6 quotient class";
+constexpr const char *kGeometryQuadsName = "A7 source-attached geometry";
 constexpr const char *kCutEdgesName = "A2a' cut edges";
 constexpr const char *kGraphArcsName = "A2b graph arcs";
 constexpr const char *kFaceDiscRegionQuantity = "A2b disc region";
@@ -418,19 +422,22 @@ private:
   void remove_surface_cell_layers() {
     for (const char *name : {kNetworkTracesName, kNetworkMandatoryName,
                              kRegionSeamsName, kRegionBoundariesName,
-                             kStopEdgesName, kTracedCellsName}) {
+                             kStopEdgesName, kTracedCellsName,
+                             kOccurrenceSidesName}) {
       if (polyscope::hasCurveNetwork(name)) {
         polyscope::removeCurveNetwork(name);
       }
     }
     for (const char *name : {kNetworkSingularitiesName, kStopVerticesName,
-                             kTracedCornersName}) {
+                             kTracedCornersName, kOccurrencesName}) {
       if (polyscope::hasPointCloud(name)) {
         polyscope::removePointCloud(name);
       }
     }
-    if (polyscope::hasSurfaceMesh(kStopFacesName)) {
-      polyscope::removeSurfaceMesh(kStopFacesName);
+    for (const char *name : {kStopFacesName, kGeometryQuadsName}) {
+      if (polyscope::hasSurfaceMesh(name)) {
+        polyscope::removeSurfaceMesh(name);
+      }
     }
     if (polyscope::hasSurfaceMesh(kInputMeshName)) {
       auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
@@ -836,19 +843,22 @@ private:
                              kRegionSeamsName, kRegionBoundariesName,
                              kStreamlinesName, kStopEdgesName,
                              kTracedCellsName, kCutEdgesName,
-                             kGraphArcsName, kFeatureEdgesName}) {
+                             kGraphArcsName, kFeatureEdgesName,
+                             kOccurrenceSidesName}) {
       if (polyscope::hasCurveNetwork(name)) {
         sync(polyscope::getCurveNetwork(name));
       }
     }
     for (const char *name : {kNetworkSingularitiesName, kStopVerticesName,
-                             kTracedCornersName}) {
+                             kTracedCornersName, kOccurrencesName}) {
       if (polyscope::hasPointCloud(name)) {
         sync(polyscope::getPointCloud(name));
       }
     }
-    if (polyscope::hasSurfaceMesh(kStopFacesName)) {
-      sync(polyscope::getSurfaceMesh(kStopFacesName));
+    for (const char *name : {kStopFacesName, kGeometryQuadsName}) {
+      if (polyscope::hasSurfaceMesh(name)) {
+        sync(polyscope::getSurfaceMesh(name));
+      }
     }
   }
 
@@ -967,6 +977,37 @@ private:
     }
   }
 
+  void visualize_materialization(
+      const directional::visualization::MaterializationDiagnosticsDisplay
+          &products) {
+    if (products.occurrenceSides.rows() > 0) {
+      auto *sides = polyscope::registerCurveNetwork(
+          kOccurrenceSidesName, products.occurrencePoints,
+          products.occurrenceSides);
+      sides->setColor({0.85F, 0.45F, 0.10F});
+      sides->setRadius(0.0012F);
+    }
+    if (products.occurrencePoints.rows() > 0) {
+      auto *occurrences = polyscope::registerPointCloud(
+          kOccurrencesName, products.occurrencePoints);
+      occurrences->setPointRadius(0.003F);
+      // -1 marks an occurrence that no retained A6 class lists.
+      if (products.hasQuotientProduct) {
+        occurrences
+            ->addScalarQuantity(kQuotientClassQuantity,
+                                products.occurrenceClass,
+                                polyscope::DataType::CATEGORICAL)
+            ->setEnabled(true);
+      }
+    }
+    if (products.geometryQuads.rows() > 0) {
+      auto *geometry = polyscope::registerSurfaceMesh(
+          kGeometryQuadsName, products.geometryPoints, products.geometryQuads);
+      geometry->setEdgeWidth(1.0);
+      geometry->setEnabled(false);
+    }
+  }
+
   void apply_streamline_style() {
     if (!streamlines_.has_value() || !polyscope::hasCurveNetwork(kStreamlinesName)) {
       return;
@@ -1012,6 +1053,9 @@ private:
     if (surfaceCellDiagnostics_->network.has_value()) {
       visualize_field_network(*surfaceCellDiagnostics_->network);
     }
+    if (surfaceCellDiagnostics_->materialization.has_value()) {
+      visualize_materialization(*surfaceCellDiagnostics_->materialization);
+    }
     visualize_quad_tracing(surfaceCellDiagnostics_->tracing);
     sync_overlay_transforms();
   }
~~~

## `Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md`; moved verbatim.

### RA-185 — DIAG-RETAIN: materialization display adapter and text dump (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-CLI-GUI` (DEFN, Review track), run locally. It continues the user-directed DIAG-RETAIN item after CB58/TB57 landed the A5–A7 snapshots ([RA-184](#architecture_m6_defn_diag_retain_a5_a7_snapshots_20261031md "moved: Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md")).
- **Method:** probes are diagnostic only. Source is CB58 `58ddfef0…`, unchanged in `src/`, `include/`, `tests/`, `CMakeLists.txt` and `cmake/` at HEAD. A Sonnet subagent traced the CLI, GUI, CMake and multi-component consumers (read-only); the Review agent designed the change, probed it and ruled.

#### RA-185.1 Findings

- **CLI.** `--surface-cell-preserve-debug-artifacts` sets `preserveDebugArtifacts` and `retainIntermediateGeometry` (`src/cli/RemeshCommand.cpp:174–176`), but the CLI never reads `surfaceCellContext`. Its only file output beyond the mesh is the `--diagnostics-prefix` sidecar writer `write_remesh_diagnostics` (`src/cli/RemeshOutput.cpp:371`), whose inputs are mesh arrays and `RemeshDiagnostics`.
- **GUI.** `run_surface_cell_diagnostics` (`src/gui/GuiRemesh.cpp:~75–95`) converts snapshots through polyscope-free adapters in `src/visualization/` (compiled into `directional_pipeline`, `CMakeLists.txt:255–272`) and stores each result as an optional on `SurfaceCellDiagnosticsData` (`src/gui/GuiBackend.h:131–142`); `src/gui/Main.cpp` draws them. The adapters' tests are in `directional_compiled_api_tests` (`cmake/DirectionalTests.cmake:59–67`), a gate binary.
- **Build.** The CI flag set builds neither the CLI nor the GUI (`DIRECTIONAL_BUILD_CLI=OFF`, `DIRECTIONAL_BUILD_GUI=OFF`). Only adapter code in `directional_pipeline` is compiled and gate-tested.
- **DR2.** The multi-component aggregate (`RemeshPipeline.cpp:~17900–19400`) copies only `sourceTopologyRegions`, `authoritativeRails` and `completedPatches` into its snapshots. `traceNetwork`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, `globalTopologyPlan` and the three CB58 fields are all dropped, and a failed aggregate resets the whole context (`:17838`, `:18007`).

#### RA-185.2 Rulings

- **CB59: one polyscope-free adapter in `directional_pipeline`** (`include/directional/visualization/MaterializationDiagnosticsDisplay.h`, `src/visualization/MaterializationDiagnosticsDisplay.cpp`).
  - `materialization_diagnostics_display(snapshots)` returns Eigen arrays: A5 occurrence points, directed cell sides and owned relations (as occurrence rows), the A6 class ordinal of each occurrence (−1 if none), and A7 vertex positions with quads as vertex rows. A product that was not retained leaves its fields empty and its `has…` flag false.
  - `write_materialization_diagnostics(out, snapshots)` writes a line-oriented text dump: a header line with counts per product (or `absent`), then one line per occurrence and relation, class and geometry vertex. Occurrences are written `cell:corner`.
  - Both take the snapshots by const reference, so they cannot feed back into any stage. No pipeline code calls them.
- **CLI and GUI wiring: deferred to a follow-up DEFN** (`M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING`), because neither target builds under the gate's flags. That DEFN freezes a CLI sidecar (for example `<prefix>.materialization.txt` written by the CB59 dump under `--diagnostics-prefix` when the snapshots are present) and the GUI layers, each with a CLI-ON or GUI-ON compile check.
- **DR2: carried, re-owned to M8-CP2** (diagnostics hardening). The drop is pre-existing and shared by every stage snapshot, so merging per-component products is a snapshot-contract change, not a DIAG-RETAIN slice. The adapter and dump already treat the products as optional, so a multi-component run reports them `absent`.
- **DR1 and DR3 unchanged** (RA-184.4).

#### RA-185.3 Probe evidence

Builds are local CB58 source plus the CB59 patch, default arithmetic, incremental in the CB58 build tree.

- **New `MaterializationDiagnosticsDisplay.RetainedPlaneProductsBecomeConsistentDisplayGeometry` passes.** On the plane stopped after tracing (the CB58 fixture), all three products are present and non-empty. Every occurrence point equals its product's position. Every side joins two corners of its own cell, and every occurrence is in exactly one A6 class. Each A7 quad corner maps to the vertex of the same class. The dump has one header per product and one line per element.
- **New `MaterializationDiagnosticsDisplay.UnretainedProductsLeaveEmptyFieldsAndAreReportedAbsent` passes.** With retention off, all fields are empty, all flags are false and the dump is exactly the three `absent` lines.
- **Failing-first evidence is compile-level:** both tests use the new API.
- **No regressions:** `directional_compiled_api_tests` gives 25/25 (23 existing + 2 new). The change is additive: one new translation unit referenced only by the new test file, plus one list entry each in `CMakeLists.txt` and `cmake/DirectionalTests.cmake`. No existing source line changes, so the other four binaries are unaffected at source level. A full-gate probe was **not** run; TB58 runs the full gate.
- **Membership** of the five probe binaries is **945** = the TB58 manifest (863) plus ledger v4 (82), exactly.

#### RA-185.4 CB59 — exact patch

**Turn:** `M6-CB59-DIAG-RETAIN-MATERIALIZATION-DISPLAY` (CB), run locally; Code + Build.
- **Scope:**
  - `CMakeLists.txt`: `1 0`.
  - `cmake/DirectionalTests.cmake`: `1 0`.
  - `include/directional/visualization/MaterializationDiagnosticsDisplay.h` (new): `65 0`.
  - `src/visualization/MaterializationDiagnosticsDisplay.cpp` (new): `167 0`.
  - `tests/MaterializationDiagnosticsDisplayTests.cpp` (new): `188 0`.
- **Checks:**
  - The RA-185.7 block, extracted verbatim with a trailing newline, has SHA-256 `78108421ae9e3ccff4cd537e0eb882f75d87d3caf3e6c04259e750dd9485023d`.
  - `git apply --check`, then apply; the numstat must be exactly as above.
  - The resulting SHA-256 must be:
    - `CMakeLists.txt` `7b3eadf6b73a30510dff503c45c2f1b46954c70cc0dc0f6eec8bc98b09c311ab`;
    - `cmake/DirectionalTests.cmake` `50c9f93861add728d4617b062d84e42a4188df9d3e787e648583e84afb12dd80`;
    - header `430e8650291b46478b7912b70712d4534804399c39aba40b63ae6c2fe9757da4`;
    - source `6c2a6f784b5a5c8793a64875caee44df74015beb67098d4313214ee9f7821920`;
    - tests `db2a2fa04dce70eeedabed02c416c0981f129dc2abf001830092aea842b0ee2b`.
  - Build the eight targets at default arithmetic and stage the package. No native tests.

| CB59 result | Successor |
|---|---|
| All exact, package built | `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-DISPLAY-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB59A-DIAG-RETAIN-DISPLAY-ORCH`, then one retry |

#### RA-185.5 TB58 frozen inputs

- **Gate:** [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv"), 863 rows, SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`.
  - The first 862 lines are TB57 (`f898c9b6…`).
  - Rows 862 (`ra185:materialization-display-retained`) and 863 (`ra185:materialization-display-absent`) are GUARD rows in `directional_compiled_api_tests`.
- **Ledger:** v4 is unchanged (82, `36241caa…`).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=863 deferred=82`. The real membership check of the patched binaries gives **945**.

| TB58 result (local) | Successor |
|---|---|
| 862/863 PASS, with row 283 (O16) the only RED, postflight true, membership 945 | `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING` (no separate REV) |
| Any other non-PASS | `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-REV` (R) |
| Membership error | `M6-PLAN-DIAG-RETAIN-DISPLAY-MEMBERSHIP-STOP` (PLAN, R) |

#### RA-185.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CB59-DIAG-RETAIN-MATERIALIZATION-DISPLAY` → `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC` | CB, TB-EXEC / local | 862/863, with only 283 red |
| then | `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING` (CLI sidecar and GUI layers over the CB59 adapter, each with a CLI-ON or GUI-ON compile check) | DEFN / R | frozen wiring CBs |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | DR1, DR3 (RA-184.4); DR2 → M8-CP2; O2b, O15b, O15c, O16; Linux CI confirmation of rows 854–859 | — | — |

#### RA-185.7 Exact CB59 patch

~~~diff
diff --git a/CMakeLists.txt b/CMakeLists.txt
index c4f65b42c..3548d7b84 100644
--- a/CMakeLists.txt
+++ b/CMakeLists.txt
@@ -267,6 +267,7 @@ add_library(
   src/visualization/CutGraphDisplay.cpp
   src/visualization/FieldAlignedNetworkPolylines.cpp
   src/visualization/FieldStreamlines.cpp
+  src/visualization/MaterializationDiagnosticsDisplay.cpp
   src/visualization/SourceRegionDisplay.cpp
   src/visualization/SurfaceCellTracingDisplay.cpp
   src/visualization/TargetSizeDisplay.cpp)
diff --git a/cmake/DirectionalTests.cmake b/cmake/DirectionalTests.cmake
index 262e271b0..cdf060880 100644
--- a/cmake/DirectionalTests.cmake
+++ b/cmake/DirectionalTests.cmake
@@ -62,6 +62,7 @@ add_executable(
   tests/CutGraphDisplayTests.cpp
   tests/FieldAlignedNetworkPolylinesTests.cpp
   tests/FieldStreamlinesTests.cpp
+  tests/MaterializationDiagnosticsDisplayTests.cpp
   tests/SourceRegionDisplayTests.cpp
   tests/SurfaceCellTracingDisplayTests.cpp
   tests/TargetSizeDisplayTests.cpp)
diff --git a/include/directional/visualization/MaterializationDiagnosticsDisplay.h b/include/directional/visualization/MaterializationDiagnosticsDisplay.h
new file mode 100644
index 000000000..ccc0bece1
--- /dev/null
+++ b/include/directional/visualization/MaterializationDiagnosticsDisplay.h
@@ -0,0 +1,65 @@
+// This file is part of Directional, a library for directional field processing.
+// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
+//
+// This Source Code Form is subject to the terms of the Mozilla Public License
+// v. 2.0. If a copy of the MPL was not distributed with this file, You can
+// obtain one at http://mozilla.org/MPL/2.0/.
+
+#pragma once
+
+#ifndef DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
+#define DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
+
+#include <directional/pipeline/RemeshPipeline.h>
+
+#include <Eigen/Core>
+
+#include <iosfwd>
+
+namespace directional::visualization {
+
+/**
+ * Display geometry for the retained A5-A7 materialization snapshots.
+ *
+ * Diagnostic only: positions are the products' double approximations. Nothing
+ * here is semantic authority, and no pipeline stage reads it. A product that
+ * was not retained leaves its fields empty.
+ */
+struct MaterializationDiagnosticsDisplay {
+  /// A5 corner occurrences, O x 3, in occurrence-complex order.
+  Eigen::MatrixXd occurrencePoints;
+  /// A5 directed cell sides as rows of occurrencePoints, 4C x 2.
+  Eigen::MatrixXi occurrenceSides;
+  /// A5 owned relations as rows of occurrencePoints, R x 2.
+  Eigen::MatrixXi occurrenceRelations;
+  /// A6 quotient-class ordinal of each occurrence, size O; -1 when the
+  /// occurrence is in no class or no A6 product was retained.
+  Eigen::VectorXi occurrenceClass;
+  /// A7 vertex geometry, Q x 3, in A7 order.
+  Eigen::MatrixXd geometryPoints;
+  /// A7 cells as rows of geometryPoints, C x 4.
+  Eigen::MatrixXi geometryQuads;
+
+  bool hasOccurrenceComplex = false;
+  bool hasQuotientProduct = false;
+  bool hasSourceAttachedGeometry = false;
+};
+
+/// Converts the retained snapshots into display geometry.
+MaterializationDiagnosticsDisplay materialization_diagnostics_display(
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots);
+
+/**
+ * Writes a line-oriented text dump of the retained snapshots.
+ *
+ * Each product gets one header line with its counts, or `absent` when it was
+ * not retained, followed by one line per occurrence and relation (A5), class
+ * (A6) and geometry vertex (A7). Occurrences are written `cell:corner`.
+ */
+void write_materialization_diagnostics(
+    std::ostream &out,
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots);
+
+} // namespace directional::visualization
+
+#endif // DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
diff --git a/src/visualization/MaterializationDiagnosticsDisplay.cpp b/src/visualization/MaterializationDiagnosticsDisplay.cpp
new file mode 100644
index 000000000..9660ee97f
--- /dev/null
+++ b/src/visualization/MaterializationDiagnosticsDisplay.cpp
@@ -0,0 +1,167 @@
+// This file is part of Directional, a library for directional field processing.
+// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
+//
+// This Source Code Form is subject to the terms of the Mozilla Public License
+// v. 2.0. If a copy of the MPL was not distributed with this file, You can
+// obtain one at http://mozilla.org/MPL/2.0/.
+
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
+
+#include <iomanip>
+#include <map>
+#include <ostream>
+
+namespace directional::visualization {
+namespace {
+
+using OccurrenceRows = std::map<authority::OccurrenceId, int>;
+
+OccurrenceRows
+occurrence_rows(const pipeline::SurfaceOccurrenceComplex &complex) {
+  OccurrenceRows rows;
+  for (std::size_t row = 0; row < complex.occurrences().size(); ++row) {
+    rows.emplace(complex.occurrences()[row].id, static_cast<int>(row));
+  }
+  return rows;
+}
+
+std::ostream &write_occurrence(std::ostream &out,
+                               const authority::OccurrenceId &occurrence) {
+  return out << occurrence.cell().index() << ':'
+             << static_cast<int>(occurrence.canonical_corner_role());
+}
+
+std::ostream &write_position(std::ostream &out, const double x, const double y,
+                             const double z) {
+  return out << x << ' ' << y << ' ' << z;
+}
+
+} // namespace
+
+MaterializationDiagnosticsDisplay materialization_diagnostics_display(
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots) {
+  MaterializationDiagnosticsDisplay display;
+  OccurrenceRows rows;
+  if (const auto &complex = snapshots.occurrenceComplex) {
+    display.hasOccurrenceComplex = true;
+    rows = occurrence_rows(*complex);
+    const auto &occurrences = complex->occurrences();
+    display.occurrencePoints.resize(
+        static_cast<Eigen::Index>(occurrences.size()), 3);
+    for (std::size_t row = 0; row < occurrences.size(); ++row) {
+      display.occurrencePoints.row(static_cast<Eigen::Index>(row)) =
+          occurrences[row].point.position.transpose();
+    }
+    const auto &cells = complex->cells();
+    display.occurrenceSides.resize(static_cast<Eigen::Index>(4 * cells.size()),
+                                   2);
+    for (std::size_t cell = 0; cell < cells.size(); ++cell) {
+      for (std::size_t side = 0; side < 4; ++side) {
+        const auto &[from, to] = cells[cell].directedSides[side];
+        const auto edge = static_cast<Eigen::Index>(4 * cell + side);
+        display.occurrenceSides(edge, 0) = rows.at(from);
+        display.occurrenceSides(edge, 1) = rows.at(to);
+      }
+    }
+    const auto &relations = complex->owned_relations();
+    display.occurrenceRelations.resize(
+        static_cast<Eigen::Index>(relations.size()), 2);
+    for (std::size_t relation = 0; relation < relations.size(); ++relation) {
+      const auto row = static_cast<Eigen::Index>(relation);
+      display.occurrenceRelations(row, 0) =
+          rows.at(relations[relation].firstOccurrence);
+      display.occurrenceRelations(row, 1) =
+          rows.at(relations[relation].secondOccurrence);
+    }
+    display.occurrenceClass = Eigen::VectorXi::Constant(
+        static_cast<Eigen::Index>(occurrences.size()), -1);
+  }
+  if (const auto &quotient = snapshots.quotientProduct) {
+    display.hasQuotientProduct = true;
+    if (display.hasOccurrenceComplex) {
+      const auto &classes = quotient->classes();
+      for (std::size_t ordinal = 0; ordinal < classes.size(); ++ordinal) {
+        for (const auto &member : classes[ordinal].members) {
+          display.occurrenceClass(rows.at(member)) = static_cast<int>(ordinal);
+        }
+      }
+    }
+  }
+  if (const auto &geometry = snapshots.sourceAttachedGeometry) {
+    display.hasSourceAttachedGeometry = true;
+    const auto &vertices = geometry->vertices();
+    std::map<pipeline::SurfaceQuotientClassId, int> vertexRows;
+    display.geometryPoints.resize(static_cast<Eigen::Index>(vertices.size()),
+                                  3);
+    for (std::size_t row = 0; row < vertices.size(); ++row) {
+      vertexRows.emplace(vertices[row].quotientClass, static_cast<int>(row));
+      display.geometryPoints.row(static_cast<Eigen::Index>(row)) =
+          vertices[row].position;
+    }
+    const auto &cells = geometry->topology();
+    display.geometryQuads.resize(static_cast<Eigen::Index>(cells.size()), 4);
+    for (std::size_t cell = 0; cell < cells.size(); ++cell) {
+      for (std::size_t corner = 0; corner < 4; ++corner) {
+        display.geometryQuads(static_cast<Eigen::Index>(cell),
+                              static_cast<Eigen::Index>(corner)) =
+            vertexRows.at(cells[cell].corners[corner]);
+      }
+    }
+  }
+  return display;
+}
+
+void write_materialization_diagnostics(
+    std::ostream &out,
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots) {
+  const auto precision = out.precision(17);
+  if (const auto &complex = snapshots.occurrenceComplex) {
+    out << "A5 occurrence-complex cells=" << complex->cells().size()
+        << " occurrences=" << complex->occurrences().size()
+        << " relations=" << complex->owned_relations().size() << '\n';
+    for (const auto &occurrence : complex->occurrences()) {
+      write_occurrence(out << "occurrence ", occurrence.id)
+          << " face=" << occurrence.point.face << " position=";
+      write_position(out, occurrence.point.position.x(),
+                     occurrence.point.position.y(),
+                     occurrence.point.position.z())
+          << '\n';
+    }
+    for (const auto &relation : complex->owned_relations()) {
+      write_occurrence(out << "relation ", relation.firstOccurrence) << ' ';
+      write_occurrence(out, relation.secondOccurrence) << '\n';
+    }
+  } else {
+    out << "A5 occurrence-complex absent\n";
+  }
+  if (const auto &quotient = snapshots.quotientProduct) {
+    out << "A6 quotient-product classes=" << quotient->classes().size()
+        << " classed-cells=" << quotient->classed_cells().size() << '\n';
+    for (std::size_t ordinal = 0; ordinal < quotient->classes().size();
+         ++ordinal) {
+      out << "class " << ordinal << " members";
+      for (const auto &member : quotient->classes()[ordinal].members) {
+        write_occurrence(out << ' ', member);
+      }
+      out << '\n';
+    }
+  } else {
+    out << "A6 quotient-product absent\n";
+  }
+  if (const auto &geometry = snapshots.sourceAttachedGeometry) {
+    out << "A7 source-attached-geometry vertices="
+        << geometry->vertices().size()
+        << " cells=" << geometry->topology().size() << '\n';
+    for (const auto &vertex : geometry->vertices()) {
+      write_occurrence(out << "vertex ", vertex.representative) << " position=";
+      write_position(out, vertex.position.x(), vertex.position.y(),
+                     vertex.position.z())
+          << '\n';
+    }
+  } else {
+    out << "A7 source-attached-geometry absent\n";
+  }
+  out.precision(precision);
+}
+
+} // namespace directional::visualization
diff --git a/tests/MaterializationDiagnosticsDisplayTests.cpp b/tests/MaterializationDiagnosticsDisplayTests.cpp
new file mode 100644
index 000000000..5a6a18654
--- /dev/null
+++ b/tests/MaterializationDiagnosticsDisplayTests.cpp
@@ -0,0 +1,188 @@
+#include <directional/core/TriMesh.h>
+#include <directional/io/ReadOBJ.h>
+#include <directional/pipeline/RemeshPipeline.h>
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
+
+#include "TestFixturePaths.h"
+
+#include <gtest/gtest.h>
+
+#include <filesystem>
+#include <fstream>
+#include <sstream>
+#include <stdexcept>
+#include <string>
+
+namespace {
+
+Eigen::MatrixXd read_rawfield(const std::filesystem::path &path,
+                              const int expectedFaces) {
+  std::ifstream stream(path);
+  int degree = 0;
+  int faceCount = 0;
+  if (!stream || !(stream >> degree >> faceCount) || degree != 4 ||
+      faceCount != expectedFaces) {
+    throw std::runtime_error("Invalid rawfield fixture: " + path.string());
+  }
+  Eigen::MatrixXd raw(faceCount, 3 * degree);
+  for (int face = 0; face < faceCount; ++face) {
+    for (int column = 0; column < 3 * degree; ++column) {
+      stream >> raw(face, column);
+    }
+  }
+  if (!stream) {
+    throw std::runtime_error("Truncated rawfield fixture: " + path.string());
+  }
+  return raw;
+}
+
+// The plane stopped after tracing, as in the CB58 retention test: A5-A7 all
+// complete, and the injected failure keeps the run on the diagnostic path.
+directional::pipeline::RemeshResult plane_materialization(const bool retain) {
+  directional::TriMesh mesh;
+  if (!directional::readOBJ(
+          directional::tests::benchmark_fixture_path("milestone-g/plane.obj")
+              .string(),
+          mesh)) {
+    throw std::runtime_error("Cannot read the plane fixture");
+  }
+  const Eigen::MatrixXd raw = read_rawfield(
+      directional::tests::benchmark_fixture_path("milestone-g/plane.rawfield"),
+      static_cast<int>(mesh.F.rows()));
+  directional::pipeline::RemeshOptions options;
+  options.lengthRatio = 0.2;
+  options.integralSeamless = false;
+  options.roundSeams = false;
+  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
+  options.surfaceCells.enabled = true;
+  options.surfaceCells.fallbackPolicy =
+      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
+  options.surfaceCells.allowSourceGridRecovery = false;
+  options.surfaceCells.retainIntermediateGeometry = retain;
+  options.surfaceCells.injectFailureAfterStage = 3;
+  return directional::pipeline::remesh_from_raw_cross_field(mesh.V, mesh.F, raw,
+                                                            options);
+}
+
+std::size_t count_prefix(const std::string &text, const std::string &prefix) {
+  std::istringstream lines(text);
+  std::size_t count = 0;
+  for (std::string line; std::getline(lines, line);) {
+    if (line.rfind(prefix, 0) == 0) {
+      ++count;
+    }
+  }
+  return count;
+}
+
+} // namespace
+
+TEST(MaterializationDiagnosticsDisplay,
+     RetainedPlaneProductsBecomeConsistentDisplayGeometry) {
+  const auto result = plane_materialization(true);
+  const auto &snapshots = result.surfaceCellContext.productSnapshots;
+  ASSERT_NE(nullptr, snapshots.occurrenceComplex);
+  ASSERT_NE(nullptr, snapshots.quotientProduct);
+  ASSERT_NE(nullptr, snapshots.sourceAttachedGeometry);
+  const auto &complex = *snapshots.occurrenceComplex;
+  const auto &quotient = *snapshots.quotientProduct;
+  const auto &geometry = *snapshots.sourceAttachedGeometry;
+
+  const auto display =
+      directional::visualization::materialization_diagnostics_display(
+          snapshots);
+  EXPECT_TRUE(display.hasOccurrenceComplex);
+  EXPECT_TRUE(display.hasQuotientProduct);
+  EXPECT_TRUE(display.hasSourceAttachedGeometry);
+
+  const auto occurrences =
+      static_cast<Eigen::Index>(complex.occurrences().size());
+  ASSERT_GT(occurrences, 0);
+  ASSERT_EQ(occurrences, display.occurrencePoints.rows());
+  ASSERT_EQ(4 * static_cast<Eigen::Index>(complex.cells().size()),
+            display.occurrenceSides.rows());
+  ASSERT_EQ(static_cast<Eigen::Index>(complex.owned_relations().size()),
+            display.occurrenceRelations.rows());
+  ASSERT_EQ(occurrences, display.occurrenceClass.size());
+  for (Eigen::Index row = 0; row < occurrences; ++row) {
+    EXPECT_EQ(
+        complex.occurrences()[static_cast<std::size_t>(row)].point.position,
+        display.occurrencePoints.row(row).transpose());
+  }
+  // A side joins two corners of its own cell.
+  for (Eigen::Index edge = 0; edge < display.occurrenceSides.rows(); ++edge) {
+    const auto &cell = complex.cells()[static_cast<std::size_t>(edge / 4)];
+    for (int end = 0; end < 2; ++end) {
+      const auto &occurrence = complex.occurrences()[static_cast<std::size_t>(
+          display.occurrenceSides(edge, end))];
+      EXPECT_EQ(cell.id, occurrence.id.cell());
+    }
+  }
+  // Every occurrence is in exactly the class that lists it.
+  std::size_t classedMembers = 0;
+  for (std::size_t ordinal = 0; ordinal < quotient.classes().size();
+       ++ordinal) {
+    classedMembers += quotient.classes()[ordinal].members.size();
+  }
+  EXPECT_EQ(static_cast<std::size_t>(occurrences), classedMembers);
+  EXPECT_GE(display.occurrenceClass.minCoeff(), 0);
+  EXPECT_LT(display.occurrenceClass.maxCoeff(),
+            static_cast<int>(quotient.classes().size()));
+
+  ASSERT_EQ(static_cast<Eigen::Index>(geometry.vertices().size()),
+            display.geometryPoints.rows());
+  ASSERT_EQ(static_cast<Eigen::Index>(geometry.topology().size()),
+            display.geometryQuads.rows());
+  for (Eigen::Index cell = 0; cell < display.geometryQuads.rows(); ++cell) {
+    for (Eigen::Index corner = 0; corner < 4; ++corner) {
+      const auto row = display.geometryQuads(cell, corner);
+      EXPECT_EQ(
+          geometry.topology()[static_cast<std::size_t>(cell)]
+              .corners[static_cast<std::size_t>(corner)],
+          geometry.vertices()[static_cast<std::size_t>(row)].quotientClass);
+    }
+  }
+
+  std::ostringstream dump;
+  directional::visualization::write_materialization_diagnostics(dump,
+                                                                snapshots);
+  const std::string text = dump.str();
+  EXPECT_EQ(1U, count_prefix(text, "A5 occurrence-complex cells="));
+  EXPECT_EQ(complex.occurrences().size(), count_prefix(text, "occurrence "));
+  EXPECT_EQ(complex.owned_relations().size(), count_prefix(text, "relation "));
+  EXPECT_EQ(1U, count_prefix(text, "A6 quotient-product classes="));
+  EXPECT_EQ(quotient.classes().size(), count_prefix(text, "class "));
+  EXPECT_EQ(1U, count_prefix(text, "A7 source-attached-geometry vertices="));
+  EXPECT_EQ(geometry.vertices().size(), count_prefix(text, "vertex "));
+  EXPECT_EQ(0U, count_prefix(text, "A5 occurrence-complex absent"));
+}
+
+TEST(MaterializationDiagnosticsDisplay,
+     UnretainedProductsLeaveEmptyFieldsAndAreReportedAbsent) {
+  const auto result = plane_materialization(false);
+  const auto &snapshots = result.surfaceCellContext.productSnapshots;
+  ASSERT_EQ(nullptr, snapshots.occurrenceComplex);
+  ASSERT_EQ(nullptr, snapshots.quotientProduct);
+  ASSERT_EQ(nullptr, snapshots.sourceAttachedGeometry);
+
+  const auto display =
+      directional::visualization::materialization_diagnostics_display(
+          snapshots);
+  EXPECT_FALSE(display.hasOccurrenceComplex);
+  EXPECT_FALSE(display.hasQuotientProduct);
+  EXPECT_FALSE(display.hasSourceAttachedGeometry);
+  EXPECT_EQ(0, display.occurrencePoints.rows());
+  EXPECT_EQ(0, display.occurrenceSides.rows());
+  EXPECT_EQ(0, display.occurrenceRelations.rows());
+  EXPECT_EQ(0, display.occurrenceClass.size());
+  EXPECT_EQ(0, display.geometryPoints.rows());
+  EXPECT_EQ(0, display.geometryQuads.rows());
+
+  std::ostringstream dump;
+  directional::visualization::write_materialization_diagnostics(dump,
+                                                                snapshots);
+  EXPECT_EQ("A5 occurrence-complex absent\n"
+            "A6 quotient-product absent\n"
+            "A7 source-attached-geometry absent\n",
+            dump.str());
+}
~~~

## `Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md`; moved verbatim.

### M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC — full gate, CLI cases and GUI link check on the CB61 packages (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction, against RA-187.5's pre-registered outcome table. It is the full-gate TB for both CB60 (CLI) and CB61 (GUI), whose source it contains.

#### Frozen inputs

- **Packages:** CB61 `build/local-evidence/CB61/pkg.zip` (`f39152f7…`, root `SHA256SUMS` `1c5cccb9…`) and `tools.zip` (`c324950f…`, 8 entries, re-verified after extraction); source `e1fd0e4b7560c4fa5bde96853b978d336c522e8f`, archive `2caf2ece…`. macOS arm64, default arithmetic. [CB61 record](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CB61_Diag_Retain_GUI_Layers_Code_Build_Record_20261031.md").
- **Gate:** the TB58 manifest [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv") (863 rows, `31c1360a…`); [ledger v4](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv") (82, `36241caa…`).
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, in the form given in the [TB57 report](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md") with the inputs above. CLI cases: `build/local-evidence/TB59/tb59_check.sh` (`16137c4e…`) on `tools.zip`'s `bin/directional`.

#### Result

The gate result is `build/local-evidence/TB60/result.zip` (gitignored), SHA-256 `2b098fb43172f4fde89a147b07d5c2ee9798e86cd0de25ffbafb5d8724c44eb6`, with 1,734 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **863 / 863 / 862** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| Membership (five binaries) | **945** = 863 GATED + 82 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |
| CLI cases (RA-186.3) | **11/11 PASS**; run A's dump byte-identical to the probe and TB59 (`fa55ca63…`) |
| GUI link check | true: `directional-ui` links the same Homebrew `libgmp.10` and `libgmpxx.4` as the gate binaries |

- **The only non-PASS** is row 283 (`selector:241`), `segment_arrangement(): surviving twin has invalid next`, the pre-registered O16 signature. Rows 854–863 pass.

- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,734/1,734 checksum entries verify, with no unlisted files.
  - 863/863 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 862 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 945 = exactly the manifest pairs (863) plus the ledger v4 pairs (82), with no overlap.

#### Outcome

Per RA-187.5, the result matches the pre-registered outcome. **DIAG-RETAIN is closed:** A5–A7 snapshots (CB58), the display adapter and dump (CB59), the CLI sidecar (CB60) and the GUI layers (CB61) are landed, and CB60 now has its full-gate TB. The layers' on-screen appearance is left to a manual check by the user. No separate REV is scheduled. The next turn is **`M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`**. Stable 66/17/49, debt 1, unchanged. TB60 (863, 862/1) is the latest local candidate; TB52 853/0 remains the latest reviewed Linux candidate.
