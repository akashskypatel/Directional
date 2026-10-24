# M6-DEFN-R1 Independent Review Record

**Turn:** `M6-DEFN-R1-REV`
**Type:** mandatory runtime-free independent Review (review agent)
**Disposition:** **CORE MODEL UPHELD / NOT ACCEPTED AS FROZEN / FOUR BLOCKING AMENDMENTS / CB4 STAYS HELD / EXACT NEXT `M6-DEFN-R2`**
**Reviewed definition:** `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md` plus the `M6-DEFN-R1` edits to `Architecture_M6_Frozen_Definitions.md` (commit `02143b8e`)
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`

## 1. Evidence re-opened

- **Definition snapshot:** run/artifact `36091204501 / 10846121134` has provider digest and download SHA-256 `194e16d6...be99`. Its embedded `source.tar.gz` is `591afb01...f077`, and its `src/pipeline/RemeshPipeline.cpp` is `9436ad68...`, byte-identical to `660015f2`. `git diff 660015f2 63330339 -- src include tests` is empty.
- **Selector/routing and focused tests:** selector449 is `d4a0d1b7...d6414` and routing449 is `9c88a5ed...c5707`. The six focused identities are unchanged. The seventh, `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`, does not yet exist in `tests/`.
- **Focused row5 body** (`SurfaceCellTransitionQuotientTests.cpp:2626-2642`) is byte-identical to accepted `e284fea7`.
- **Accounting:** stable accounting stays **54 / 16 / 38**, debt 1. This Review creates no runtime event.

## 2. What is upheld

The core model is correct and is the right answer to the TB3 findings:

- occurrence authority is the complete `CornerWedgeSheetSet` (D1);
- seam certificates are carried by the wedges and sides that actually cross the seam, keyed by `(region, seam edge)`, so an interior seam vertex is unambiguous (D2);
- `OrdinaryFront` stays owner-less, `OccurrenceRelationId` is unchanged, and A6 checks side-sheet membership in both endpoint wedge sets (D3);
- A7 records the union of member wedge sets (D5);
- no occurrence record mixes faces (D6).

The split-square table (§3), the eight endpoint-pair memberships and the interior seam-vertex chain re-derive independently and are correct. Soundness of D3 also holds: every relation step shares at least one sheet between its endpoints, so every cross-sheet transition inside a class happens within a certified wedge, or on a certified seam-collinear side (D4).

## 3. Blocking findings

### B1 — As frozen, the definition makes TB4 RED: D5 conflicts with frozen focused row5

Focused row5 asserts `EXPECT_FALSE(lineage.equivalences.empty())` for **every** lineage with more than one sheet (`SurfaceCellTransitionQuotientTests.cpp:2631-2641`). Lineage `equivalences` are produced only by relation unions: `occurrenceEquivalences[...]` is pushed in the union loop (`RemeshPipeline.cpp:4384-4393`) and aggregated per class (`:4545-4548`).

In the split square, v0 = `{c00.0}` and v2 = `{c11.2}` are single-occurrence classes on the square boundary. Neither has any relation. Under D5 their lineage becomes `{0,1}`, which is exactly what DEFN-R1 §3 requires, while their `equivalences` stay empty. Row5 therefore fails twice, and TB4 cannot be 456/456 as pre-registered.

The D8 identity checks only A5 publication, so it does not cover the A7 completeness that D5 introduces. DEFN-R1 §5 lists only falsifiers over the new definition; none of them asks whether the **existing frozen assertions** stay satisfiable.

**Amendment.** Freeze how verified wedge (and seam-collinear side) evidence appears in `PureQuadVertexLineage::equivalences`, the only evidence field row5 inspects. Recommended: a new `PureQuadEquivalenceKind` value (e.g. `CornerWedgeIsolation`) whose `PureQuadEquivalenceProvenance` carries the crossed seam key(s) and an explicit `fromSheet → toSheet` orientation, with `firstFrontEdge/secondFrontEdge = -1`. Current kind consumers only filter `HardRail`/`PeriodicHolonomy` (`PureQuadCompletion.cpp:801/925/1019/1059`, `RemeshPipeline.cpp:5556/5624`), so a new kind is neutral there. No test pins completion hash constants, and only row5 inspects `equivalences.empty()`. Extend D8's identity to assert materialized lineage too: v0, centre and v2 each `{0,1}` with non-empty wedge evidence, and every other vertex a singleton.

### B2 — D6 does not say which face binding each existing consumer uses

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

### B3 — Wedge endpoints still rely on tie-broken faces; the definition names one of three side builders

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

### B4 — D7 contradicts frozen §4.6 and cannot be implemented as an adapter mapping

Frozen §4.6 keeps "M5's accepted typed relation failures remain unweakened". D7 deletes the downstream `MissingHardRailRelationOwner`, the owner half of `InvalidPeriodicRelationOwner`, and the kind half of `IncompatibleAuthoritativeFrontPair`. Only the HardRail mismatch gets an adapter mapping back to its M5 name.

A5's `UnownedRelation` is many-to-one: it covers a missing HardRail owner, a periodic owner that is missing or mismatched, a boundary-kind mismatch, and an out-of-range opposite edge (`RemeshPipeline.cpp:3408-3450`). The adapter therefore cannot restore the specific M5 codes. Those failures become generic `OccurrenceUnownedRelation`. That is the same specific → generic change that was counted as a stable `VALIDATION_ORDER_SHADOWING` event at row140; it escapes counting here only because no test pins those codes yet.

**Amendment.** Recommended:

1. Split A5's structural relation failures 1:1, e.g. `OccurrenceHardRailOwnerMissing`, `OccurrenceHardRailOwnerMismatch`, `OccurrencePeriodicOwnerMismatch`, `OccurrenceRelationKindMismatch`, and keep `OccurrenceUnownedRelation` for genuinely ownerless cases.
2. Have the transitional adapter map each to its legacy M5 name through one table.
3. Then delete the unreachable downstream duplicates.

The alternative is to amend §4.6 explicitly so the external failure contract is only the accepted test surface.

## 4. Non-blocking precision items (fold into DEFN-R2)

- **P1.** Seam-collinear sides may span several seam edges or be only partly collinear. Evidence is an **ordered certificate list**, not "the same certificate". D3 or D4 is chosen **per endpoint pair** by whether the near-endpoint segment is collinear.
- **P2.** Both reciprocal directed sides must agree on the near-endpoint interior face and sheet for a non-collinear pair; disagreement is a typed A6 failure.
- **P3.** Wedges at singular or excluded source vertices, or at nodes that are SingularityPort corners, are out of CP1 scope. A5 has no SingularityPort producer, so declare them a typed A5 failure rather than leaving them undefined.
- **P4.** HardRail-closure rows assert single-sheet lineage (`SurfaceCellsPhase10Tests.cpp:6351`, `:6632`). Record that wedges never cross a region boundary, so rail-adjacent wedges without seams stay singletons.

## 5. Why a definition turn rather than reviewer amendments

B2 and B3 each need a design decision with a proof obligation: the per-consumer binding rule, and whether cell orientation agrees with source winding in all three builders. B1 extends a public lineage product schema. Freezing these as unverified reviewer text and sending them straight to Code + Build would repeat the TB3-REV error of freezing an unproved model into a CB turn. A bounded, runtime-free `M6-DEFN-R2` is cheaper than another CB → 456-process TB → Review cycle.

## 6. Successor

Exact next: runtime-free **`M6-DEFN-R2`**, then mandatory `M6-DEFN-R2-REV`, then the re-scoped `M6-CP1-CB4` (plan stays HELD and must be revised by DEFN-R2). Scope: `Architecture_M6_DEFN_R2_Amendment_Plan.md`.

## Review closeout

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
