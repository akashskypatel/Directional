# `M6-CP1-CB12-CLOSE-REV` — Review of the CB12 C5 Stop

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

## 1. The CB12 stop was correct procedure on a wrong pointer

CB12 followed its plan. The plan's C5 table, which I wrote, named the optimizer consumer as "source-point rebinding `:2576`, `:3020`". Those line anchors were wrong:
- `:3020` sits inside `make_surface_optimization_overlay` (`SurfaceMeshOptimizer.cpp:2900`), in a loop over **source** vertices.
- The actual source-point rebinding is `project_vertices` (`:759-:924`).

The audit was defined as a closed list of line anchors, not a searchable predicate. That let the real consumers fall outside it. **Review-agent error, owned** (lesson 198).

## 2. The flagged site (`SurfaceMeshOptimizer.cpp:3015-3031`)

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

## 3. Complete audit of production provenance-face reads (optimizer and final validation)

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

## 4. Why rows 4, 5 and 7 do not block CP1

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

## 5. Routing

| Turn | Scope |
|---|---|
| **`M6-CP1-CB12-CLOSE-R1`** (exact next, new turn) | CB12 plan C1–C4 and identities 29/30, unchanged. C5 is discharged by RA-26 §3 (the report cites it). **No optimizer or validator change.** Focused-30; compile/package; successor TB12 at **479**. |
| `M6-CP1-TB12-CLOSE-EXEC` → `M6-CP1-TB12-CLOSE-REV` → `M6-CP1-CLOSE-REV` | Unchanged. CLOSE-REV also re-verifies RA-26 §3 at its HEAD: there is no authority-deciding provenance-face consumer. |
| `M6-DEFN-R5` (CP3 entry) | Gains RA-26 §5 items (i)–(iv). |

## 6. Closeout

| Duty | Result |
|---|---|
| Source authority | HEAD source == `8dd95821` (fetched by SHA and diffed); CB12 made no source change. |
| Flagged site | Not a provenance consumer; test-only; OBS-01 → M8-CP2. |
| Full audit | 12 sites classified; no authority-deciding consumer; rows 4, 5, 7 reference-selecting → RA-26 / DEFN-R5 / CP3. |
| Owned errors | Wrong C5 line anchors in the plan; RA-22b §5 class conflation. |
| Accounting | +0 → **60 / 16 / 44**, debt 1. |
| Lesson | 198 — define an audit by a searchable predicate, not by line anchors; separate authority-deciding from reference-selecting consumers. |
| Successor | `M6-CP1-CB12-CLOSE-R1`. |
