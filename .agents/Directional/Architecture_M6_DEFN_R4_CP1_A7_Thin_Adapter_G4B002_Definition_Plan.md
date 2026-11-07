# M6-DEFN-R4 — A7 Product, Thin Adapter, and the `G4-B002` A6 Boundary — Definition Plan

**Turn:** `M6-DEFN-R4`
**Type:** Definition only. Runtime-free: no source, test, fixture, selector or build edits; no generated Directional executable.
**Authorized by:** `M6-CP1-TB8-A6-REV` and its review-agent addendum (§H3).
**Mandatory successor:** `M6-DEFN-R4-REV`. No A7, adapter or `G4-B002` Code + Build is authorized until that Review.

**Entering authority.**
- Reviewed runtime: `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`, focused 1-12 + selector449 = **461/461**.
- Accounting: **60 / 16 / 44**, debt 1.

## 1. Why this turn exists

Status of the CP1 exit checklist (frozen definitions, "CP1 exit scope — restated"):

| Item | Requirement | Status |
|---|---|---|
| 1 | A5 product conformant | **Met.** Legacy `SurfaceOccurrence` fields `isolationSheet/chart/lattice` are retired. |
| 2 | Complete immutable A6 product | **Met.** `QuotientCertificate` / `MaterializationCertificate` exist. |
| 3 | A7 product | **Missing.** |
| 4 | Thin adapter | **Missing.** |
| 5 | `G4-B002` A6 stage boundary | **Missing.** |
| 6 | No weld; focused multi-isolation green | Met in practice, but item 6 must be re-proved after A7 extraction. |

R3 deferred the representation of items 3 and 5 to this turn.

## 2. Bounded scope (decide exactly these; nothing else)

### D1. A7 representation and certificates (frozen definitions §5)

Decide:

1. **Product shape.** `SourceAttachedGeometryProduct` type(s) and their immutable API. There is one embedded vertex per A6 `SurfaceQuotientClassId`. A6 topology is copied unchanged and certified unchanged.
2. **Exact support rule.** A `SourceSupportCertificate` predicate over A5 `SourceSupport` that proves every member occurrence is incident to the published support. Define exact compatibility for vertex / edge / face-interior supports.
   - Today the adapter compares member positions under a `1e-9` relative tolerance (`QuotientGeometryConsistencyFailure`, `RemeshPipeline.cpp:6118-6127`). That is a floating predicate in a semantic stage.
   - R4 must replace it as authority with the exact incidence predicate. Any float comparison may remain only as a non-authoritative diagnostic.
3. **Representative rule.** It is representation-only and deterministic, and it lives in A7, not the adapter.
   - Today: min over `(support, cornerWedgeBindings, id)`, at `:6103-6113`.
   - State whether this key is retained, and prove from the D4 census that every frozen assertion over `sourcePoint` / `vertexProvenance` / `vertexPositions` stays satisfiable.
4. **Lineage projection** into `PureQuadVertexLineage`:
   - wedge-union `sourceIsolationSheets` (RA-6) and the binding-chart union `sourceCharts`;
   - `sourceTopologyRegions`, `equivalences`, `quotientClass` ordinal (RA-10);
   - `selectedRelationPaths`, projected from the A6 forest. `SelectedRelationStep.appliedTransport` carries **`canonicalRelationValue`** (RA-16 §3).
5. **The transport guard (normative).** A7 and the adapter must not consume A6 `canonicalTransport` / `relationTransport` for geometry, lineage, chart re-anchoring or completion input.
   - That transport's only consumer is the A6 strict cycle rule.
   - This guard is what lets the carried gauge obligations (§4) wait for `M6-DEFN-R5`.
   - If D4 finds any consumer that needs placement transport, stop for Review.
6. **Failure vocabulary.**
   - A7 `GeometryEmbeddingFailure` codes per §5.3.
   - A legacy-name mapping only where a frozen test pins a string (D4 lists them).
   - RA-12-style site suffixes where several sites share one legacy name (lesson 181).

### D2. Thin adapter

1. **Classify all 55 failure-emission sites** of `build_authoritative_phase_front_mesh` (`RemeshPipeline.cpp:5548-6503`, 955 lines). For each site give its line, its failure string, and exactly one owner:
   - **(a) A4-product validation → A5.** Topology-region map, isolation-seam certificates, transition source edges, phase-front ownership/side authority/cell, source-boundary, relief-cut.
   - **(b) A6 error projection.** The `Quotient*` mappings.
   - **(c) Materialized-mesh validity → A7 `GeometryEmbeddingCertificate`, or A8** if it is an independent recomputation. Covers non-manifold edge/vertex/fan, open or unjustified boundary, degenerate/inverted/duplicate quad, collapsed edge, unreferenced vertex, boundary loops, mesh-edge relation mismatch.
   - **(d) Pure projection / serialization.**
2. **Checkable "thin" predicate.** The adapter performs only (b) and (d): no semantic predicate, no selection, no floating tolerance, no topology decision.
3. **Failure-precedence rule.** Moving (a) into A5 and (c) into A7 changes which check fires first. For every site, state:
   - the accepted precedence that frozen tests pin (from the D4 census);
   - how the move preserves it.

   Do not repeat RA-15's shadowing (lessons 177/181).

### D3. `G4-B002` A6 stage boundary (frozen definitions §8.1)

1. **Boundary representation.** Define the closed-complex view derivable from the A6 product — classed quads, quotient vertices, HardRail/Periodic relation boundaries. Candidate extraction (`extract_surface_simplification_candidates(const SurfaceCellComplex&, ...)`, `SurfaceComplexSimplification.h:425-432`) must be able to consume it without `SurfaceCellPipelineContext::hasArrangement`.
2. **CP1 demonstration.** A boundary adapter proved equivalent on an existing closed fixture. Name:
   - the fixture;
   - the equivalence relation (combinatorial isomorphism plus rail/periodic edge labels plus vertex lineage);
   - the independent oracle.

   **CP3 keeps** the eligibility oracle and the hard-feature tamper re-proof on direct production; CP1 mechanism evidence cannot close the debt.

### D4. Consumer and frozen-assertion census (lessons 180, 187) — do this FIRST; D1-D3 decisions must cite it

For each output A7 or the boundary will produce or change, list every reader with `file:line`, and mark it as production or test; for tests also give the selector row or focused ordinal. The outputs:
- `vertexPositions`, `vertexProvenance`;
- lineage `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `selectedRelationPaths`;
- `hash_completion` and the lineage hashes (`RemeshPipeline.cpp:2700-2760`);
- `BenchmarkQuality` path hashes.

There are about 400 references across src and tests at `8e0818b1`. For each decision in D1-D3, state which frozen assertions bound it and why they stay satisfiable.

### D5. CB sequencing and gate

Freeze the bounded Code + Build sequence. Recommended:
- **`M6-CP1-CB9-A7`:** A7 extraction plus adapter (c)/(d) thinning.
- **`M6-CP1-CB10-A5V`:** adapter (a) moves into A5, if D2 shows they are separable.
- **`M6-CP1-CB11-G4`:** the boundary adapter.
- **CP1 closure Review.**

For each CB, pre-register:
- its new focused identities (appended after focused 12);
- its gate: **`Architecture_M6_CP1_Required_Green_Focused_12.txt` (SHA-256 `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`) + new identities + selector449**, all required green.

The first A7 CB must include
**`M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`**:
- the nonzero-Z4 witness materialization passes `validate_materialized_completion_domain_ownership` with an empty failure string;
- this is the executed evidence the TB8 Review addendum §H2 found missing.

## 3. Must not change

- A5/A6 semantics: RA-1 – RA-16 as annotated, `OccurrenceId`, `SurfaceQuotientClassId`, exact-once, and the strict cycle rule.
- selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...c5707`; the focused-12 list.
- All fixtures and tests. No source edits in this turn.

## 4. Explicitly out of scope → `M6-DEFN-R5` (a CP3-entry gate, not CP1)

These are carried from RA-16 §4 and the TB7 addendum §G5. They must close before any CP3 direct-production TB. R4 only records their owner and confirms the D1.5 guard isolates them.

1. An exact-A3 periodic witness with unequal corresponding-corner `faceBranchRotation`, and replacement of the face-gauged final check with coordinate plus relation-gauge checks.
2. HardRail cross-region branch certification, which needs published per-endpoint face-gauge authority.
3. OrdinaryFront coordinate identity, or isolation-seam transition, across isolation seams.

## 5. Durability

- Write the definition record incrementally, as `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`, completing D4 first.
- After each completed D-item, land it on the branch or emit a `RETENTION_POLICY.md` Drive work-preservation patch.
- Keep STATUS canonical: `Successor: UNKNOWN` until complete; never `NONE`.
- If the turn cannot finish D1-D5 in one session, close **IN_PROGRESS with the D-items completed listed in the record**. Do not compress the remainder into unreviewed assertions.

## 6. Exit criteria (checked by `M6-DEFN-R4-REV`)

- The D4 census is complete, with `file:line` for every reader. Every D1-D3 decision cites the frozen assertions that bound it.
- D1, D2 and D3 are decided with reasons, written normatively into `Architecture_M6_Frozen_Definitions.md` (as an R4 amendment), and consistent with §§5, 7, 8.1, 10 and RA-16.
- D2's 55-site classification is complete, and the "thin" predicate is checkable.
- D5's CB plan(s) are written, with focused identities and gate size stated, including the witness production-completion identity.
- §4's obligations are recorded with owner `M6-DEFN-R5` and the D1.5 guard.
- Accounting stays 60 / 16 / 44, debt 1. No implementation is authorized by R4 itself.
