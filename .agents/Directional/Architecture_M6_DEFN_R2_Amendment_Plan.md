# M6-DEFN-R2 Seam-Incident Authority Amendment — Definition Plan

**Turn:** `M6-DEFN-R2`
**Type:** Definition amendment, runtime-free
**Predecessor:** `M6-DEFN-R1-REV` (`Architecture_M6_DEFN_R1_Review_Record.md`)
**Successor:** mandatory `M6-DEFN-R2-REV`, then the re-scoped `M6-CP1-CB4`
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Current definition authority:** `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md` (core model D1-D8 upheld) plus `Architecture_M6_Frozen_Definitions.md`

## 1. Scope

Keep the upheld DEFN-R1 core: corner-wedge sheet sets, wedge/side certificate carriers keyed by `(region, seam edge)`, owner-less `OrdinaryFront` with unchanged `OccurrenceRelationId`, A6 membership validation, A7 union, and no mixed-face records. Amend exactly the four blocking findings and the four precision items below. Record each decision with the rejected alternative and the reason.

### A1 (B1) — Lineage evidence for wedge-certified sheets

1. Freeze the lineage representation of verified wedge evidence and seam-collinear side evidence inside `PureQuadVertexLineage::equivalences`. Recommended: a new `PureQuadEquivalenceKind` (e.g. `CornerWedgeIsolation`) whose provenance carries the crossed seam key(s) and an explicit `fromSheet → toSheet` orientation, with `firstFrontEdge/secondFrontEdge = -1`.
2. Prove, by citing each consumer (`PureQuadCompletion.cpp:801/925/1019/1059`, `RemeshPipeline.cpp:5556/5624`, completion hash), that the new kind does not change their behaviour.
3. Prove frozen focused row5 (`SurfaceCellTransitionQuotientTests.cpp:2626-2642`, unchanged since `e284fea7`) is satisfiable: in the split square every multi-sheet lineage, including the relation-free singleton classes at v0 and v2, has non-empty `equivalences`.
4. Amend D8: the seventh identity also materializes and asserts lineage. v0, centre and v2 each `{0,1}` with non-empty wedge evidence; every other vertex a singleton.

### A2 (B2) — Binding selection for every face-dependent consumer

Freeze one rule per consumer, with no representative choice:

1. **Transitional class key.** `QuotientDomainState`/`QuotientClassKey` (`RemeshPipeline.cpp:4399-4432`) and what "`QuotientClassId` unchanged" means for the transitional ordinal (`:4465-4492`) and the `UnpairedDuplicateAuthoritativeCorner` guard (`:4457-4461`).
2. **`representative_key`** (`:4503-4516`).
3. **Selected relation paths.** `SelectedRelationStep.from/toChartComponent` (`:4377-4380`) and `SelectedRelationPathCertificate.start/endChart` and `start/endChartComponent` (`:4633-4637`); accepted torus rows 444 and 448 pin these.
4. **Lineage `sourceCharts`.** Must stay consistent with the typed remap check (`:11470-11490`).

Recommended:
- relation-local consumers use the binding of the relation side's interior face at that endpoint;
- class-level consumers use the complete sorted binding list or its union;
- `chartComponent` is occurrence-wide, with a fail-closed check that it is constant across the wedge.

### A3 (B3) — One exact rule for collinearity, interior face and wedge fan, across all three side builders

Cover `segment_on_source` (`SurfaceCellTracing.cpp:11161`, source-face-row tie-break `:11239`), `periodic_chart_segment` (`:12456`, lexicographic `:12529`) and `bounded_disk_chart_segment` (`:12581`, lexicographic `:12648`). The split square uses the **uniform** builder (`segment_on_source`), not the bounded-disk one.

1. **Collinearity** is decided by the exact `SourceSupport` of the segment interior (edge support ⇒ collinear with that edge), never by tolerance or the tracer's triangle choice.
2. **Interior-side face** for every collinear segment, seam or not. Recommended: the incident face whose consistent source winding contains the side's directed edge. **Prove** that validated cell cycles agree with source winding in all three builders (`orient_and_validate_phase_front_cell` orients against the builder frame normal), or choose the chart-orientation rule and name the A5 inputs that make it computable without an A4 product change.
3. **Wedge fan** is the winding-order arc around the support between the outgoing and incoming interior faces.
4. **Stop rule:** if interior-face or wedge authority requires an A4 product change, stop and record it.

### A4 (B4) — A5 relation failure vocabulary versus frozen §4.6

Recommended:
1. Split A5 structural relation failures 1:1: `OccurrenceHardRailOwnerMissing`, `OccurrenceHardRailOwnerMismatch`, `OccurrencePeriodicOwnerMismatch`, `OccurrenceRelationKindMismatch`, plus `OccurrenceUnownedRelation` for genuinely ownerless cases.
2. The transitional adapter maps each through one table to its legacy M5 name (`MissingHardRailRelationOwner`, `InvalidHardRailTransport`, `InvalidPeriodicRelationOwner`, `IncompatibleAuthoritativeFrontPair`).
3. Then delete the unreachable downstream duplicates while keeping transport/content checks.

Alternative: amend §4.6 explicitly so the external failure contract is only the accepted test surface. Either way, §4.6 and D7 must no longer contradict each other.

### Precision items

- **P1.** Multi-edge and partly collinear seam sides carry an ordered certificate list. D3 or D4 is chosen per endpoint pair.
- **P2.** Reciprocal sides must agree on the near-endpoint interior face and sheet; disagreement is a typed A6 failure.
- **P3.** Singular or excluded vertices and SingularityPort corners are out of CP1 scope and produce a typed A5 failure.
- **P4.** Wedges never cross a region boundary, so rail-adjacent wedges without seams stay singletons (HardRail single-sheet rows `SurfaceCellsPhase10Tests.cpp:6351/6632`).

### Required frozen-test audit

For every accepted selector449 row and focused identity that materializes a fixture with isolation seams, list each assertion over `vertexLineage`, `equivalences`, `sourceCharts`, `sourceIsolationSheets` and the selected certificates. Show each stays satisfiable under the amended definition.

At minimum:
- focused rows 5 and 6;
- selector rows 186, 214, 239, 444, 446 and 448;
- the HardRail single-sheet rows.

## 2. Must not change

`OccurrenceId`, `CellId`, relation-only quotient equality, HardRail/Periodic owners, the no-geometric-welding rule, selector449 `d4a0d1b7...d6414`, routing449 `9c88a5ed...c5707`, and every existing test and fixture. No source edits, compile, or Directional runtime.

## 3. Exit criteria (checked by `M6-DEFN-R2-REV`)

- A1-A4 and P1-P4 are decided and written into `Architecture_M6_Frozen_Definitions.md` §§3-5 consistently. §4.6 no longer contradicts the A5 failure policy.
- The frozen-test audit shows every listed assertion is satisfiable, with row5 at v0 and v2 explicitly.
- The A3 orientation premise is proved per builder, or replaced.
- The CB4 plan is rewritten with the amended seventh identity and TB4 at 7 + 449 = 456.
- Accounting stays **54 / 16 / 38**, debt 1.
