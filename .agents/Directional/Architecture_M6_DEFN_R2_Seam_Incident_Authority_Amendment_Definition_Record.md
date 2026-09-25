# M6-DEFN-R2 — Seam-Incident Authority Amendment Definition Record

**Turn:** `M6-DEFN-R2`
**Type:** Definition amendment / runtime-free
**Predecessor:** `M6-DEFN-R1-REV`
**Mandatory successor:** `M6-DEFN-R2-REV`
**Implementation successor if and only if Review accepts:** re-scoped `M6-CP1-CB4`
**Status:** COMPLETE / RUNTIME-FREE / B1-B4 and P1-P4 frozen for independent Review / CB4 HELD
**Date:** 2026-09-25

## 1. Scope and unchanged authority

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

## 2. Independently re-derived source facts

The exact snapshot used for this Definition is GitHub Actions run/artifact `36095854118 / 10847467936`, event/source SHA `342a306ebd3ba68cb6e1135cf9e25726bd8ad461`, provider SHA-256 `a19261e06e11293b9240b8a44c24f95042190df1d7154ba330c5e677fb9875c2`, embedded archive SHA-256 `c0ca5581851b76b1a169cdffb4c3b7243070d54225f176e6510ce909b152ab1c`, 5,312 files / 97,885,751 bytes, `runtimeExecution=false`. All decisive static conclusions below were re-derived from those bytes.

The source establishes all of the following:

1. `PureQuadVertexLineage::equivalences` is the frozen focused-row carrier that row5 already requires to be non-empty for every multi-sheet lineage. Existing equivalence consumers branch only on HardRail or Periodic where they need owner/path semantics; a third isolation-evidence kind can therefore be decision-neutral to those consumers when it does not impersonate either owner.
2. Transitional A6 currently collapses each occurrence to one `isolationSheet` and one `chart`, uses them in `QuotientDomainState` and `representative_key`, and selects path chart components from those occurrence-wide values. That is incompatible with the now-frozen multi-face `CornerWedgeFaceBindings` model.
3. All three side builders can tie-break a segment that lies on a source edge: `segment_on_source`, `periodic_chart_segment`, and `bounded_disk_chart_segment`. All three accepted cell paths normalize their canonical cell cycle orientation against source orientation before `orientationValidated=true`; source-chart adjacency also requires reciprocal source-edge winding. Therefore the cell-interior incident face can be selected topologically after A4 acceptance without relying on the builder's chosen representative face.
4. Current A5 `UnownedRelation` is many-to-one: it covers missing HardRail ownership, Periodic ownership problems, kind incompatibility, and genuinely owner-less structural cases. That conflicts with the frozen M5 typed failure surface.

## 3. A1/B1 — wedge evidence is a first-class lineage equivalence

### 3.1 New equivalence kind

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

### 3.2 Construction and deduplication

For each quotient class A7/materialization projects the union of every member occurrence's `CornerWedgeIsolationEvidence` and every member directed-side isolation evidence that the accepted quotient relation certificate actually verified. Equal semantic evidence is deduplicated by the full ordered transition sequence, not by source-face row, front-edge index, or hash.

This equivalence is lineage evidence only. It must not be inserted into `selectedRelationPaths`, must not alter relation selection, and must not cause a previously unused HardRail/Periodic relation to become selected.

### 3.3 Split-square consequence

For the accepted two-triangle split-square analytic witness:

- v0: one occurrence class, `sourceIsolationSheets={0,1}`, and at least one non-empty `CornerWedgeIsolation` equivalence carrying the exact seam transition `1 -> 0` in that corner-wedge traversal;
- center: four occurrence members collectively span `{0,1}` and materialize non-empty corner/side isolation lineage evidence from the same checked seam authority;
- v2: one occurrence class, `sourceIsolationSheets={0,1}`, and at least one non-empty `CornerWedgeIsolation` equivalence carrying `0 -> 1` in its corner-wedge traversal;
- every other materialized lattice vertex remains single-sheet unless independent typed evidence says otherwise.

This makes focused row5 satisfiable without inventing a relation between the relation-free v0/v2 occurrences.

## 4. A2/B2 — per-consumer face binding

### 4.1 Canonical occurrence binding signature

Every occurrence publishes the complete canonical ordered binding signature derived from its wedge:

```text
(sourceFaceTopology,
 IsolationSheetId,
 SourceProjectionChart,
 branchRotation)
```

plus its face-independent lattice coordinate/phase/scale provenance. No A6/A7 consumer may select one representative sheet/chart and use it as semantic authority for the whole occurrence.

All bindings within one admissible corner wedge must resolve to one `SourceChartTransitionGraph` component. A wedge never crosses a hard-rail or topology-region boundary. If this invariant cannot be established, A5 fails closed; it is not repaired by choosing a different binding.

### 4.2 Transitional class/domain key

The semantic `QuotientClassId` remains the canonical sorted non-empty member-`OccurrenceId` set. Any transitional integer class row is adapter-local only.

A transitional `QuotientDomainState`/class key used to detect duplicate or incompatible occurrence authority must include the member's **complete canonical binding signature** rather than one scalar sheet/chart. It may also include the already-frozen face-independent lattice/scale provenance and exact source support. Two different complete binding signatures must never compare equal merely because one selected binding matches.

### 4.3 Representative key

Geometric representative selection is representation-only. Its deterministic key must include exact source support/geometry and the complete binding signature, with `OccurrenceId` as a semantic final discriminator. `point.face` may be used only as a final lookup/storage tie-break after semantic support and binding equality are already established. Representative selection does not define quotient membership, sheet authority, or chart authority.

### 4.4 Relation-local chart selection

For every selected HardRail or Periodic relation step, the endpoint chart is the binding attached to the **relation-side interior source face at that endpoint**. `SelectedRelationStep.fromChartComponent` and `.toChartComponent` are derived from those relation-local bindings.

`SelectedRelationPathCertificate.startChart/endChart` likewise come from the first/last selected relation step, not from a quotient representative's arbitrary face. Multi-step path continuity is checked in chart-component authority; each exact step retains its own relation-local source chart.

OrdinaryFront requires no selected relation-path certificate merely because a wedge carries `CornerWedgeIsolation` evidence.

### 4.5 A7 lineage projections and component remap

`PureQuadVertexLineage::sourceCharts` is the sorted unique union of **all** member `CornerWedgeFaceBinding.chart` values. `sourceIsolationSheets` and `sourceTopologyRegions` are projections of the same exact binding tuples plus already-verified side/wedge transitions; they are not independently chosen sets.

Component remapping must remap the full binding tuples and `PureQuadIsolationTransition` tuples first and only then derive legacy region/sheet/chart vectors. Validation against independent set membership or a region×sheet cross-product is insufficient because it loses the exact binding association.

## 5. A3/B3 — exact collinearity and cell-interior incident face

### 5.1 Exact support-span rule

A directed side is partitioned, in side traversal order, into maximal positive-length spans of exact `SourceSupport`. A span is source-edge-collinear if and only if its open interior support is exactly that `SourceEdgeSupport`. No tolerance, angle test, builder-selected representative face, source-face row, or lexicographic triangle order participates.

A partly collinear side is classified locally per span. In particular, the near-endpoint positive-length span determines whether that endpoint pair uses the ordinary non-collinear rule or the seam-collinear rule.

### 5.2 Interior-face rule

For an accepted A4 `orientationValidated` cell and an internal manifold source edge:

1. require exactly two incident source faces and reciprocal source-edge winding;
2. inspect the directed source-edge orientation induced by the canonical accepted cell side;
3. select the unique incident source face whose source-triangle winding places that face on the cell-interior side of the directed edge;
4. derive the side's sheet/chart/branch binding from that face;
5. fail closed if the incident faces, winding, owning region, or unique selection is inconsistent.

This is a topological exact decision after A4 acceptance. It does not require a new A4 product field.

### 5.3 Why the premise holds for all three builders

The source audit proves the premise independently for all active builders:

- uniform cells: `orient_and_validate_phase_front_cell` reverses the corner order when needed and requires the resulting loop normal to agree with the source frame normal before setting `orientationValidated`;
- periodic chart cells: the builder computes an expected source normal from the corner source faces, reverses on negative agreement, requires positive agreement, and only then validates region ownership and publishes `orientationValidated`;
- bounded-disk chart cells: the same canonical-loop/source-normal rule is applied, and every source-chart triangle is independently required to have positive signed chart area in source face vertex order;
- source-chart transitions require the two source faces incident on a manifold edge to have opposite winding along that edge.

Therefore one exact A5 interior-face rule can replace all three builder-local tie-break faces for seam-collinear authority.

## 6. A4/B4 — one-to-one A5 failure vocabulary and adapter map

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

## 7. Precision rules P1-P4

### P1 — ordered evidence for multi-edge and partial-collinear sides

`DirectedSideIsolationEvidence` is an ordered list in directed-side traversal order. Each maximal positive-length seam-edge span contributes the exact checked `(region,seam,fromSheet,toSheet)` transition for that span. Repeated geometry does not collapse distinct ordered spans. Reciprocal side evidence must be the reverse-compatible list with every transition direction inverted.

### P2 — reciprocal near-endpoint agreement

For reciprocal OrdinaryFront sides:

- if the near-endpoint positive-length span is not seam-collinear, the two records must agree on the mapped interior sheet authority and that sheet must be a member of both endpoint wedge sets;
- if it is seam-collinear, both records must name the same exact seam certificate/span, the two selected interior faces must be the two incident source faces, and their sheets must be the certificate's opposite incident sheets;
- ordered side-evidence lists must be reciprocal reverses.

Violation is typed A6 failure `QuotientReciprocalSideAuthorityMismatch`.

### P3 — excluded singular/nonmanifold corner classes

CP1 does not invent a corner wedge when the source fan is nonmanifold, singular/excluded such that no unique contiguous cell-interior wedge exists, or the relation corner is a `SingularityPort`. A5 fails closed with:

- `OccurrenceUnsupportedSingularWedge`; or
- `OccurrenceUnsupportedSingularityPort`.

No representative-face or global-search fallback is allowed.

### P4 — region/hard-rail boundary law

A `CornerWedgeFaceBinding` sequence is confined to one `TopologyRegionId` and stops at source boundary, topology-region boundary, or hard rail. A hard-rail-adjacent corner with no internal isolation seam inside its admissible wedge remains **single-sheet**. If satisfying the requested wedge would require crossing a hard rail, or if CP1 encounters an unresolved seam-at-hard-rail corner whose authority is not uniquely inside one admissible wedge, A5 fails `OccurrenceUnsupportedHardRailSeamWedge` rather than broadening the sheet set.

This explicitly preserves the accepted HardRail single-sheet assertions in Phase10.

## 8. Frozen-test compatibility audit

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

## 9. CB4/TB4 authorization shape

`M6-CP1-CB4` is re-scoped by `Architecture_M6_CP1_CB4_Relation_Owned_Isolation_Equivalence_Code_Build_Plan.md` and remains **HELD** until independent `M6-DEFN-R2-REV` accepts this Definition.

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

## 10. Process observation

`M6-DEFN-OBS-01` recurred: several small repository documents were opened before the turn explicitly froze `READ_MODE=snapshot`. The turn stopped piecemeal inspection, acquired the exact snapshot above, and re-derived every decisive semantic conclusion from that verified snapshot. This is the already-known process recurrence; it adds no stable event, category, lesson, or debt.

## 11. Closeout

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
