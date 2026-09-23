# M5 Frozen Definitions — Certificate-Carrying Chart and Quotient Relations

**Status:** FROZEN / `M5-DEFN` COMPLETE / CP1 + CP2 CLOSED / CP3 DEFN-R1 GAUGE MODEL FROZEN / EXACT NEXT = `M5-CP3-CB17` / RUNTIME-FREE DEFINITION AMENDMENT 2026-09-23
**Date:** 2026-09-19
**Definition authority:** this record is the normative M5 contract for canonical periodic-relation identity, producer-selected relation-path certificates, consumer validation, failure ownership, and the CP1/CP2/CP3 split. It refines `DESIGN.md` §14 M5 without changing accepted M4 semantics or M6 occurrence-complex ownership.

This turn changed planning/documentation only. It did not change production, tests, fixtures, selectors, build logic, or execute Directional runtime.

## 1. Entering authority

M5 enters from the reviewed M4 exit:

- accepted package `10591801825`;
- exact compiled semantic source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431`;
- selector430 **430/430 PASS**, LF SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- owner census **31 / 283 / 75 / 41**;
- stable regression accounting **49 events / 14 categories / 35 recurrences**;
- produced-witness debt **5**, of which **4 are M5-owned** and **1 is M6-owned**.

The definition audit used source snapshot `1cef1133ecfe59eeeee220b37a907301f9315dc7` from artifact `10594140365`. That snapshot contains the `M5-DEFN` status/trigger control commit but no M5 semantic source change.

## 2. Source diagnosis and boundary

The current implementation already has useful strong types and exact routes, but the periodic-relation seam still violates the M5 model in four concrete ways:

1. `authority::PeriodicRelationId` is a `SemanticId<PeriodicRelationTag>` allocated through `from_index(...)`; insertion selects the first unoccupied integer and aggregation remaps those integers by component offset.
2. `SurfacePeriodicHolonomy` couples that positional ID to its value payload (`GridAutomorphism`, `route`, `cutRoute`), so storage/aggregation mechanics can still affect relation naming.
3. `PureQuadEquivalenceProvenance` retains front-edge indices, and `close_completion_lineage_source_authority(...)` reconstructs hard-rail reachability by building an adjacency graph and running a consumer-side traversal.
4. The accepted row408 torus reaches a produced phase front, but the M4 R3 evidence showed that its produced product publishes **zero periodic holonomies**. The existing relation-order, missing-owner, full-periodic, and tampered-transform tests therefore remain direct/draft mechanism evidence, not M5 production debt credit.

M5 corrects those seams. It does **not** define M6's A5 occurrence-complex decomposition, occurrence creation, embedding split, or independent-verifier stage boundaries.

## 3. Canonical periodic-relation identity

### 3.1 Identity domain

`authority::PeriodicRelationId` is a **content identity**, not a representation ordinal. CP1 must replace the current index-backed alias with a strong composite identity whose semantic value is:

```text
PeriodicRelationId :=
    (TopologyRegionId,
     canonical(generator-carrier-path, cut-carrier-path))
```

The two carrier paths are orientation-neutral semantic path identities. A carrier step contains only the semantic source carrier needed to identify the path:

```text
(step-kind, SourceEdgeTopologyKey, optional checked InteriorTransitionId)
```

The carrier identity explicitly excludes:

- `GridAutomorphism` / composed transport;
- vector position or relation-table row;
- front-edge index;
- output row;
- hash-table or map iteration order;
- component aggregation order/offset;
- execution/workflow handles.

Transport is **relation value**, not relation identity. This separation is required so a transport tamper on the same semantic relation is typed as a conflict instead of silently becoming a different relation.

### 3.2 Orientation and ordering

For one observed `(generator, cut)` pair, form the exact forward carrier tuple and its exact simultaneous reversal. The canonical identity is the lexicographically smaller tuple after the `TopologyRegionId` scope. Equality and strict ordering compare those canonical semantic fields only.

Two representations of the same relation therefore compare equal under path reversal and container permutation. Two genuinely different same-region generators remain distinct because their carrier tuples differ. Canonicalization must not assign ranks after sorting: inserting an unrelated valid relation must not renumber an existing ID.

### 3.3 Checked creation and conversion

The relation producer may not call `PeriodicRelationId::from_index(...)`. A checked factory derives the ID from the authoritative region plus carrier paths. If a boundary/API supplies both a declared ID and relation payload, the checked conversion recomputes the ID and rejects disagreement; numeric coincidence is not a conversion.

`SurfacePeriodicHolonomy` remains the immutable value object. Its value payload is:

```text
sourceTopologyRegion
GridAutomorphism action
authoritative generator route
authoritative cut route
```

Its published ID must equal the identity derived from those routes' carrier identities. `with_id(...)`-style semantic renumbering is not valid production authority after CP1.

## 4. Explicit selected relation-path certificate

M5 replaces reachable-set reconstruction with one producer-owned exact path certificate for every quotient/chart extension that participates in materialized lineage.

The semantic contract is:

```text
SelectedRelationPathCertificate
  sourceSupport
  startChartComponent
  endChartComponent
  startChart              // exact endpoint binding where applicable
  endChart                // exact endpoint binding where applicable
  orderedSteps[]
  composedTransport

SelectedRelationStep
  relationKind            // HardRail or PeriodicHolonomy
  relationId              // typed HardRailId or canonical PeriodicRelationId
  direction               // forward or reverse
  fromChartComponent
  toChartComponent
  appliedTransport
```

`SourceChartComponentIdentity` is the row-order-independent component identity already available to bind endpoints. `SourceProjectionChart` may additionally bind the exact selected endpoint chart. A certificate with only `witnessed=true`, an unordered relation set, or a reachable component set is invalid.

### 4.1 Producer selection rule

The writer records **the exact relation steps actually used to form the quotient/materialized lineage**. It does not ask a later validator to search the full relation graph for some path that works. If the producer has two equivalent encodings of the same actual join sequence, it canonicalizes only that sequence by semantic endpoint/relation ordering; unrelated table members never participate in path selection.

### 4.2 Independent consumer checks

A consumer may independently recompute elementary facts, but it may not search for or substitute a path. For each certificate it must verify:

1. source-support and endpoint binding;
2. start/end chart-component identities from source authority;
3. every named relation exists exactly once and belongs to the required source region/sheet domain;
4. step direction is compatible with the named relation's endpoints/carriers;
5. `appliedTransport` equals the named relation value in forward direction or its exact inverse in reverse direction;
6. adjacent step endpoints compose exactly in the recorded order;
7. recomposing all step transports equals `composedTransport`;
8. the destination chart is an incident chart of the same exact source support and is admissible under retained region/sheet authority.

The local `SourceChartTransitionGraph` may continue to validate source-chart rebinding and component facts. It may not choose a quotient path by BFS/DFS or turn an unordered set of equivalences into semantic reachability.

## 5. Single writer and bounded consumer cutover

### 5.1 Single writer

The M5 writer is the A4 phase-front relation / quotient-lineage publication seam currently implemented across `SurfaceCellTracing` and the phase-front materialization path in `src/pipeline/RemeshPipeline.cpp`. It owns:

- canonical periodic-relation IDs;
- immutable relation values;
- relation references on periodic front edges;
- the exact selected relation-path certificate copied into materialized vertex lineage.

This is still an M5 relation/certificate product. It does not claim M6's future occurrence-complex authority.

### 5.2 Consumers that must cut over

CP1 must remove semantic dependence on representation order at these bounded consumers:

- `SurfacePhaseFrontProduct::make(...)`: validate relation identity/table ownership by canonical IDs, not vector position;
- component aggregation in `src/pipeline/RemeshPipeline.cpp`: preserve canonical relation IDs; no `periodicRelationOffset` or local-to-global ordinal remap may rename them;
- phase-front materialization: look up by canonical ID and publish the selected certificate actually used;
- `close_completion_lineage_source_authority(...)`: validate producer-carried certificates; do not infer hard-rail/periodic reachability from `lineage.equivalences`;
- lineage/source-authority digest and final validation paths that compare semantic relation evidence: compare certificate content and typed IDs, not front-edge indices.

`firstFrontEdge` / `secondFrontEdge` may remain as diagnostics during CP1 if removal would broaden the diff, but they are representation leaves only and may not participate in equality, ordering, ownership, path selection, or validation success.

## 6. Typed failure matrix

The M5 failure vocabulary is fail-closed and relation-specific. Existing names are retained where they already express the frozen contract; CP2 adds the missing classes.

| Failure | Authoritative condition | Typed owner | Independent negative witness |
|---|---|---|---|
| **missing** | a `PeriodicCut` edge has no owner or names an ID absent from the relation table | retain `SurfacePhaseFrontProductErrorCode::MissingPeriodicRelationOwner` | independently derive a valid relation/product, remove exactly the edge owner or referenced relation, require the same locus to reject |
| **duplicate** | the same canonical `PeriodicRelationId` + identical value payload is published more than once | retain `SurfacePhaseFrontProductErrorCode::DuplicatePeriodicRelationId` | duplicate one relation object without changing its canonical payload; container order must not affect rejection |
| **conflicting** | one canonical relation locus is published with a different action/transport/value, or incompatible claims occupy the same semantic carrier slot | add `SurfacePhaseFrontProductErrorCode::ConflictingPeriodicRelation` | derive the ID independently from unchanged carriers, alter only action/transport or one incompatible value field, require conflict rather than a second identity |
| **nonreciprocal** | paired relation/front directions do not bind exact reverse carriers/endpoints or exact inverse transport | add `SurfacePhaseFrontProductErrorCode::NonReciprocalPeriodicRelation` | independently reverse the semantic path and action, then tamper only one reverse-side fact |
| **representation-renumbered** | a declared/reference ID differs from the canonical ID independently derived from the same semantic carrier locus, including component-offset renumbering | add `SurfacePhaseFrontProductErrorCode::RepresentationRenumberedPeriodicRelation` | preserve relation carrier/value content, perturb only the representation ID/reference/order mapping, require typed rejection |

The independent oracle must derive semantic carrier identity from source/path content. It may not call the production identity factory merely to obtain the expected answer, and it may not compare producer/test ordinals.

No negative may be repaired by sorting, reassignment, first-wins/last-wins, relation dropping, or front-edge substitution.

## 7. Unused-valid-relation invariance

For an accepted produced relation table `R` and a producer-selected certificate `C`, let `r_unused` be a valid relation that is not referenced by `C`. Adding `r_unused` and arbitrarily permuting relation storage must preserve:

- every pre-existing `PeriodicRelationId` exactly;
- every relation value bound to those IDs;
- the complete ordered selected certificate `C` exactly;
- its recomputed composed transport;
- the resulting materialized/lineage semantic outcome for the certified subject.

A whole-product table digest may intentionally change because membership changed; that digest is not the invariant. The selected certificate and output semantics are.

This rule forbids downstream “choose the lexicographically smallest path in the whole relation graph” logic: an unrelated alternate relation must be decision-neutral. The certificate is selected at the producer's actual join/materialization decision and only validated downstream.

## 8. Production reachability and debt preservation

### 8.1 Highest stage already proved

| Witness/contract | Highest evidence entering M5 | Credit at M5 entry |
|---|---|---|
| accepted row408 two-generator / 18-hard-edge torus | direct production reaches `SurfacePhaseFrontProduct` with disposition `Produced`; M4 R3 then measured **0 produced periodic holonomies** | proves the production precondition and current architecture gap only |
| `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` | `direct_periodic_owner_product()` direct typed product helper, 2 relations / 2 edges | mechanism-only, **no produced-witness credit** |
| `MissingPeriodicRelationOwnerIsRejected` | direct typed product helper | mechanism-only, **no produced-witness credit** |
| `FullPeriodicRotationAndTranslationMaterialize` | `direct_full_periodic_materializer_draft()` direct materializer draft | mechanism-only, **no produced-witness credit** |
| `TamperedFullPeriodicTransformIsRejected` | same direct materializer draft with action tamper | mechanism-only, **no produced-witness credit** |

Fixture-file presence, direct builders, synthetic products, and successful phase-front reachability without produced periodic relations do not discharge a production debt.

### 8.2 Four M5 debts — requirements unchanged; all four now DISCHARGED

1. `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`: **M5-CP1 mechanism / M5-CP3 direct-production re-proof**, retaining the original **`>=2` distinct produced relations and `>=2` owned periodic edges** discriminator.
2. `MissingPeriodicRelationOwnerIsRejected`: **M5-CP2 mechanism / M5-CP3 direct-production re-proof** on produced periodic authority.
3. `FullPeriodicRotationAndTranslationMaterialize`: **M5-CP3** direct production with a genuinely nonzero Z4 rotation and nonzero translation, carried through materialization/lineage/quotient acceptance.
4. `TamperedFullPeriodicTransformIsRejected`: **M5-CP3** same direct-production subject with a discriminating nonzero-Z4 transform tamper.

**Disposition (added by the `M5-CP3-TB1-R16-REV` reviewing-agent addendum; requirements above are unweakened).** This heading read "remain unchanged", which a cold reader takes as "still open". Debts 1 and 2 were discharged at `M5-CP3-TB1-R7-REV`; debts 3 and 4 at `M5-CP3-TB1-R16-REV` by `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` and `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`. Scope of debt 3's translation proof: the produced translation is shown **nonzero**, consistent with all four Forward/Reverse endpoint lattice states, and accepted by materialization with positive periodic-holonomy consumption. No independently derived translation *value* exists for this witness; only the rotation `Q=3` is independently fixed (DEFN-R1 §7). That meets the text above, which requires a nonzero translation. It must not be described as an independently derived translation.

M6 retains the separate closed candidate-bearing-complex `G4-B002` debt. M5 may not pull A5 occurrence ownership backward to obtain evidence.

## 9. Checkpoint split

### `M5-CP1` — canonical identities and selected certificates — **CLOSED / ACCEPTED**

Implement the non-ordinal `PeriodicRelationId`, preserve it through aggregation, permit multiple distinct same-region relations when their canonical path identities differ, publish producer-selected path certificates, and convert the known downstream reachability consumer to certificate validation. Author/compile focused mechanism coverage for relation-order invariance, exact path retention, certificate composition, and semantic discrimination. Do not claim the production debt yet.

### `M5-CP2` — typed relation failures — **CLOSED / ACCEPTED at `M5-CP2-TB1-REV`**

Complete the five-class relation failure matrix with independent negative oracles. Missing/duplicate/conflicting/nonreciprocal/representation-renumbered failures must reject at the named authority boundary without repair. This checkpoint supplies the mechanism credit for `MissingPeriodicRelationOwnerIsRejected` but not its production debt.

### `M5-CP3` — direct-production exit — **CLOSED / ACCEPTED at `M5-CP3-TB2-REV`; SELECTOR448 ACCEPTED**

Use the accepted row408-class one-region torus precondition to prove production emits at least two canonical same-region relations/owned periodic edges, then carry direct nonzero-Z4 authority through lineage/quotient materialization. Prove unused-valid-relation invariance on that production subject and discharge all four M5 debts without weakening their discriminators.

## 10. Definition falsifiers — disposition

All `M5-DEFN` stop rules are resolved:

- canonical identity is content-based and contains no relation-vector/front-edge/execution handle;
- the selected certificate names one exact ordered relation path and composed transport;
- unused valid relations cannot renumber IDs or trigger downstream path reselection;
- all five relation failure classes have a typed owner and independent negative contract;
- all four debt witnesses retain their original production/discriminating requirements;
- CP1/CP2 require no M6 A5 occurrence-complex work.

**Decision:** `approved_with_amendments`. The milestone split is preserved, but relation identity is explicitly separated from relation transport/value so transform tamper becomes a conflict on one stable semantic relation rather than a new identity.

## 11. Historical exit and current exact successor

Frozen §13.3 is now complete: R16 precommitted selector448, CB20 published those exact bytes, TB2 executed the published selector freshly, and `M5-CP3-TB2-REV` independently accepted closure. **M5 is CLOSED / ACCEPTED.** Current exact successor is runtime-free **`M6-DEFN`**. No M6 implementation semantics are defined by this M5 record.

*Corrected by the `M5-CP3-TB1-R16-REV` reviewing-agent addendum.* This section named `M5-CP3-CB14` (the R11-R1 Review
successor) and was not updated by any of the Review/DEFN turns that followed (R12-REV through R16-REV, including
DEFN-R1), so it was false from `M5-CP3-TB1-R12-EXEC` onward.
The superseded CB14 rationale — R11-R1 at 444/446 with 912/912 evidence, cut-domain cell-grid coordinates reused as
quotient-seam endpoint authority — is retained in `M5_Consolidated_Record.md` §4.11 and git history. §§16.1-17 are the
later normative amendments; this section is a pointer only and carries no semantics of its own.

## 12. Supersession and citation map

This record supersedes the consumed `Architecture_M5_DEFN_Definition_Plan.md` as live M5 definition authority. It does not supersede `DESIGN.md`, `ROADMAP.md`, M4 closure evidence, or M4 CP4 DEFN-R1/R2 debt ownership; it makes those M5 requirements executable.

| Topic | Current authority |
|---|---|
| milestone acceptance | `DESIGN.md` §14 M5 |
| checkpoint/debt ownership | this record §§8-9 + `ROADMAP.md` M5 |
| canonical relation identity | this record §3 |
| selected path certificate | this record §4 |
| producer/consumer cutover | this record §5 |
| typed failure matrix | this record §6 |
| invariance | this record §7 |
| historical CP3 implementation plan | folded after completion; resolver: `M5_Consolidated_Record.md` §5 |


## 13. CP2 Review amendment — M5 exit theorem and selector publication sequence

This section is a runtime-free normative reconciliation recorded by `M5-CP2-TB1-REV`. It does not weaken §§3-9.

### 13.1 Reconciled M5 exit theorem

M5 may close only when **all** of the following are true on one reviewed authority chain:

1. `DESIGN.md` §14 M5: exact producer-selected relation paths are retained and independently verified;
2. adding an independently valid but unused relation does not alter the selected certificate or accepted output semantics;
3. missing, duplicate, conflicting, nonreciprocal and representation-renumbered relation states reject with the frozen typed CP2 outcomes and no repair;
4. torus lineage and quotient acceptance are direct **production** evidence, not direct/draft/helper substitution;
5. all four §8.2 M5 debts are discharged on the accepted row408-class produced torus, retaining the `>=2` distinct produced relations / `>=2` owned periodic edges discriminator and a genuinely nonzero-Z4 rotation+translation subject;
6. CP1/CP2 mechanism evidence remains required-green after CP3 changes; direct/helper rows receive no produced-witness credit;
7. the cumulative selector containing the reviewed M5 mechanism/production identities has been published only after exact pre-commitment, executed completely artifact-only, and independently reviewed green.

The final M5 Review must explicitly check every conjunct. It may not infer one from another.

### 13.2 Nine reviewed M5 mechanism identities outside selector430

Selector430 remains the accepted byte-frozen prefix. The following already-reviewed-green CP1/CP2 mechanism identities are outside it and must be re-proved in the CP3 pre-publication focused gate, then included in the reviewed publication set unless a later independent Review records a concrete supersession:

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
3. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
4. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
5. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
6. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
7. `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory`
8. `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory`
9. `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory`

Existing selector430 rows that already cover related CP1/CP2 behavior remain in-place and are not duplicated.

### 13.3 Publication sequence — frozen before CP3 implementation

1. **`M5-CP3-CB2`** (the reviewed successor after CB1 stopped before implementation) implements direct production and authors the exact CP3 production identities while selector430 remains byte-identical. No runtime.
2. **`M5-CP3-TB1-EXEC`** executes, artifact-only, the nine §13.2 identities + the exact new CP3 produced identities + selector430. This is pre-publication evidence; it does not mutate the selector.
3. **`M5-CP3-TB1-REV`** independently adjudicates the mechanism/produced split and, only if green, pre-commits the exact successor selector bytes/order, LF SHA-256, exact selector430 prefix hash and complete owner census. This pre-commitment is mandatory and must exist **before** publication Code + Build.
4. A separate **publication Code + Build** may write only the pre-committed selector bytes, compile/package the unchanged reviewed semantics with mandatory GMP, and execute no Directional runtime.
5. A subsequent artifact-only **full published-selector Test + Benchmark** executes every published row as a fresh exact-filter process with exact-one selection/zero-skip and immutable postflight.
6. A final independent Review may close M5 only after re-hashing the published selector/prefix, re-deriving its owner census, independently accepting the full runtime evidence, and proving every §13.1 exit conjunct.

The publication CB may not choose or reorder identities after seeing build/runtime outcomes. Exact successor-selector hash/census authority is owned by the preceding Review, not the publication implementation turn.

A semantic-RED pre-publication attempt does not advance this sequence. It routes through an independently reviewed correction and a fresh complete pre-publication gate; selector bytes/hash/census may be pre-committed only by the first subsequent Review that independently accepts all proposed publication identities green on one corrected candidate. `M5-CP3-TB1-R1-REV` applies this rule and therefore carries, rather than discharges, `M5-CP2-TB1-REV-OBS-01`.

### 13.4 Mechanism versus produced naming boundary

CP3 production tests use the `M5CP3.Produced...` namespace frozen by the CP3-CB1 plan. They must not reuse the exact names of accepted direct/helper debt rows 218/220/221/226. A green direct/helper row remains mechanism evidence only; a produced row earns production credit only after independently proving its row408-class production precondition.

## 14. CP3 CB1 Review amendment — A3 provenance across same-region periodic promotion

`M5-CP3-CB1` proved a representation conflict before mutation: the accepted one-region row408 cut copies cannot remain operative `HardRail` pairs and also satisfy M5 periodic materialization, while the checked factory previously allowed exact A3 `sharedBoundaryInterval` provenance only on `HardRail`. `M5-CP3-CB1-REV` resolves that conflict without weakening §§3-9 or the row408 production precondition.

### 14.1 Provenance and operative ownership are orthogonal

`SurfaceSharedBoundaryInterval` is exact A3 provenance: owning network-arc span, exact ordinal interval, orientation and exact cut-boundary occurrence. Its truth survives a later A4 classification of the same paired chart copies. A final edge may therefore carry this provenance while its operative boundary kind is either `HardRail` or `PeriodicCut`.

For `PeriodicCut`, canonical `periodicRelation` remains mandatory and is the sole quotient owner. Shared-boundary provenance and optional source `railId` may not substitute for that owner, create identity, or relax CP2 route/action reciprocity.

### 14.2 Narrow promotion rule

A4 may promote an already-valid paired hard-rail group to a periodic quotient pair only when:

1. both edges have the same `sourceTopologyRegion`;
2. both carry exact reciprocal A3 shared-boundary intervals;
3. both intervals carry exact `boundaryOccurrence` values and those occurrences are distinct;
4. paired routes are canonical reverses, families match and advance signs oppose.

Cross-region pairs remain `HardRail`. The same-region HardRail rejection in the materializer remains binding and must not be weakened. A promoted pair publishes `PeriodicCut` on both edges, one canonical relation owner, reciprocal routes, `PeriodicFrontMerge`, and retains the exact A3 interval provenance.

### 14.3 Canonical relation authority at promotion

For a promoted pair, relation identity is derived only from exact semantic carrier content:

- resolve the A3 interval `span` through accepted `GlobalTopologyPlan` arc/source-path authority and convert that exact path through existing transition/atlas authority into the generator carrier;
- use the produced paired-edge canonical route as the cut carrier;
- derive the complete relation value from authoritative route rotation plus exact chart-lattice correspondence, requiring one `GridAutomorphism` to satisfy both reciprocal endpoint-state pairs before publication.

No edge/group/vector ordinal, `HardRailId`, insertion order, floating path search, direct-helper relation, or M6 occurrence authority may name or synthesize a relation. Exact ID/value duplicates may coalesce; same ID with different value remains the CP2 conflict failure.

### 14.4 Accepted row408 body evolution

Row408 keeps its identity, committed torus subject, exact 18-source-edge hard-feature equality, accepted A0-A3 path, conformity receipt/digests, and fail-closed pairing checks. Its old final assertion that exact A3 intervals must appear on final `HardRail` edges is superseded only at the representation locus.

On the one-region torus, the evolved row requires at least one complete reciprocal promoted pair (at least two edges) carrying the exact A3 interval provenance on `PeriodicCut`, with canonical periodic owner and reverse-route binding. A broad presence count is insufficient. Existing cross-region HardRail tests continue to own HardRail interval semantics.

This accepted-test evolution is not runtime credit by itself. Selector430 remains byte-frozen, and the complete selector430 runtime in the CP3 pre-publication gate must re-prove the evolved row before candidate promotion or M5 publication.


## 15. CP3 R4 Review amendment — transition value is not traversal adjacency

`M5-CP3-TB1-R4-REV` records the public A1 contract extension introduced by CB5 and reconciles it with the unchanged hard-feature barrier invariant. This amendment discharges `M5-CP3-TB1-R3-REV-OBS-01`; it does not weaken §§3-9 or §14.

### 15.1 Retained transition value is semantic metadata

For every validated interior source edge, `FieldTransportAtlas` may retain one canonical exact directed transition-value fact independently of whether that edge is traversable. The retained fact is validated once at atlas construction from exact source-edge identity, exact two-face identity, reciprocal quarter-turn and signed lift/effort authority, and it participates in atlas semantic identity.

A hard-feature interior edge therefore may have a retained transition **value** while remaining nontraversable.

### 15.2 Queries have disjoint meanings

`transition_value(sourceEdge, fromFace, toFace)` is a directed semantic-value query. Its return type carries no `FieldTransportAdjacencyId` and its success does **not** assert that the edge is traversable or that a traversal adjacency exists.

`transport(sourceEdge, fromFace, toFace)` remains traversal-adjacency-only. Hard-feature edges remain absent from traversable adjacency and remain `FieldTransportBarrierKind::HardFeature` barriers. No consumer may use `transition_value(...)` to bypass a barrier or synthesize traversal.

### 15.3 CP3 promotion use

Frozen §14.3's exact A3 `Mandatory` generator carrier may consume the atlas-owned transition value for its exact source edge and directed face pair without making the carrier traversable. This preserves the single A1 production owner and forbids re-enabling raw production transition ingress.

The generator carrier path and cut carrier path remain separate semantic roles in `PeriodicRelationId`, but the frozen relation contract does **not** require their carrier identities to be unequal. Equality of two valid carrier paths is not, by itself, rejection. Validity still requires exact carrier provenance, canonical paths, authoritative action/endpoint correspondence, reciprocal binding and the checked relation factory; zero translation and every existing CP2 failure condition remain binding.


---

## 16. CP3 R9 Review amendment — rotation-aware same-region periodic pairing

`M5-CP3-TB1-R9-REV` proves that §14.2 item 4's raw `family`/`advanceSign` comparison is not valid authority across a same-region periodic seam with nonzero transport. The local family/sign pair is a chart-local representation. It may be compared directly only when the two chart copies are already in the same gauge.

For a same-region promotion, retain §14.2's exact reciprocal A3 interval identity, distinct boundary occurrences and canonical-reverse route requirements. Let

```text
d1 = first.toLattice.latticeCoordinate - first.fromLattice.latticeCoordinate
d2 = second.toLattice.latticeCoordinate - second.fromLattice.latticeCoordinate
R  = generatorRoute.composed_transport().rotation
```

where `R` is taken in the exact directed A3/source-path orientation frozen by §§14.3 and 15.3. The periodic seam compatibility condition is now frozen as

```text
rotate(R, d1) == -d2.
```

The same directed `R` must also satisfy the two reciprocal branch-rotation endpoint states and both exact integer endpoint mappings through one `GridAutomorphism`. No inverse-direction retry, best-of-two orientation search, rotation search, floating correspondence, endpoint rewrite or translation fitting is permitted. §14.3's exact action correspondence remains final authority.

For `R == 0`, the transported-delta condition reduces to the former same-family/opposite-advance-sign relation. For nonzero `R`, raw local family/sign values may rotate or reverse and therefore may not veto promotion before transport. Cross-region pairs remain `HardRail` and retain the existing direct local family-match/opposite-sign requirement; this amendment does not broaden cross-region pairing or weaken the same-region HardRail rejection in materialization.

This amendment is required for consistency with §8.2 debts 3/4 and §13.1's M5 exit theorem, both of which require a genuinely nonzero-Z4 produced relation. It supersedes only the raw same-region family/sign clause of §14.2 item 4; all other §§14–15 authority remains binding.


### 16.1 R11-R1 Review clarification — cell placement is not relation endpoint gauge

The `first` / `second` endpoint lattice states consumed by §16's same-region correspondence are relation-endpoint authority. A raw
cut-domain cell-placement `LocalLatticeState::latticeCoordinate` is **not** automatically that authority when reciprocal copies are
separated by nonzero quotient transport.

For each periodic endpoint, the relation-owned lattice state must be derived independently from that endpoint's own accepted A3
boundary occurrence, semantic Forward/Reverse role, source-chart/branch state, cut-domain integer state and the one directed
generator transport. Ordinary cell placement remains unchanged. The derivation must precede action construction and may not inspect
the partner's desired endpoint, fit a translation, rewrite an endpoint after mismatch, search a rotation, try the inverse direction
or select among multiple gauges based on which one passes.

After both relation endpoint states are independently authored, the frozen §16 equations remain unchanged and are the validation
contract: one directed `R`, exact `rotate(R,d1) == -d2`, both branch correspondences and both exact integer endpoint mappings through
one `GridAutomorphism`. This clarification separates authority domains; it does not weaken §§14–16 or change relation identity.

### 16.2 R14 Review stop amendment — same-region nonzero-Z4 gauge reconciliation required

`M5-CP3-TB1-R14-REV` independently verifies that CB16's focused occurrence-branch helper contract is green while the genuine produced nonzero-Z4 subject still fails at the first branch correspondence. Static source authority proves that the quantities entering that correspondence are authored in two separately valid domains: the accepted cut carrier is omitted from the bounded-disk dual propagation that defines `faceBranchRotation`, while `generatorRotation` is read independently as exact directed A1 `transition_value(...)` across the accepted A3 generator carrier.

Sections 16 and 16.1 remain binding semantic obligations, including one directed action, reciprocal branch/delta/endpoint equations, deterministic semantic direction, the `R == 0` reduction and every no-search/no-fitting prohibition. R14 proves only that those sections are **insufficient implementation authority** for the nonzero seam: they do not yet define the exact change of gauge between the A1 source-face frame, cut-open phase-front frame, relation-endpoint frame and canonical storage representation.

No further same-region nonzero-Z4 semantic Code + Build turn is authorized until runtime-free `M5-CP3-DEFN-R1` freezes that mapping and assigns one producer/reader domain to the generator rotation, endpoint branch component, endpoint lattice coordinates and relation action/translation. The definition may not be chosen by trying an inverse, fitting a partner or translation, inspecting downstream success, using insertion order/minimum-region heuristics, weakening the accepted selector, tuning the fixture/field/A3 authority, or pulling M6 occurrence authority backward. If one unique relation action cannot be derived from existing producer-owned facts, the definition turn must stop with a definition blocker.

### 16.3 DEFN-R1 amendment — semantic Forward-anchored relation gauge

`M5-CP3-DEFN-R1` closes §16.2's definition gap without changing A1 transport, A3 occurrence authority, ordinary A4 cell placement, `PeriodicRelationId`, fixture/field bytes or selector430.

Name four frames explicitly. `S_f` is the A1 source-face frame on source face `f`. `C` is the accepted cut-domain phase-front trivialization. The existing `faceBranchRotation` at `f`, written `G_f`, maps cut-domain branch components into `S_f`. `E_F/E_R` are relation endpoint gauges authored only after exact semantic A3 Forward/Reverse occurrences are known. `K` is canonical storage representation and is not semantic direction.

Let `F` and `R` be the exact A3 Forward and Reverse occurrences of the generator carrier, with source faces `f_F` and `f_R`. Let

```text
A   = FieldTransportAtlas::transition_value(carrier, f_F, f_R).transport.rotation
G_F = faceBranchRotation[f_F]
G_R = faceBranchRotation[f_R]
```

in their existing producer-owned domains. The unique same-region quotient turn is

```text
Q = G_R^-1 o A o G_F.
```

In Z4 integer notation this is `q = -g_R + a + g_F (mod 4)`. `Q`, not raw `A`, is relation rotation authority. Reverse semantic direction is exactly `Q^-1 = G_F^-1 o A^-1 o G_R`; trying both directions and selecting by success remains prohibited.

For a source-face branch label `B_f`, first recover its cut-domain component `c_f = G_f^-1 o B_f`. A4 authors one chart-global +U component (`LocalLatticeState.branchRotation = G_f + chartUBranch`, or the equivalent zero-root form), so reciprocal cut copies recover the same `c_f = chartUBranch` before quotient transport. Relation endpoint branch authority is then

```text
Forward: b_F = c_F
Reverse: b_R = Q o c_R.
```

This yields the one frozen branch correspondence `Q o b_F = b_R`, equivalently `G_R o b_R = A o G_F o b_F`. A relation endpoint may not copy a source-face branch label directly across the seam.

Ordinary A4 cell-placement lattice coordinates remain unchanged. Let `x_F`, `x_R` denote those raw cut-domain integer coordinates at corresponding semantic endpoint copies. Relation-owned endpoint coordinates are authored in the semantic Forward-anchored convention

```text
y_F = x_F
y_R = rotate(Q, x_R).
```

The asymmetry is semantic authority, not a search: A3 Forward fixes the relation anchor, and canonical storage order may not choose another gauge. The accepted cut-open chart authors both reciprocal copies in one common integer basis; before seam transport their matched raw boundary deltas are oppositely oriented. Therefore rotating the Reverse relation-owned coordinates by the same `Q` makes the frozen transported-delta equation a direct consequence rather than an independently fitted condition. For reciprocal boundary edges `(F.from,F.to)` and `(R.from,R.to)`, A3 correspondence is `F.from -> R.to`, `F.to -> R.from`. The semantic action is

```text
T(p) = rotate(Q,p) + t
t = y_R,to - rotate(Q,y_F,from)
  = rotate(Q, x_R,to - x_F,from).
```

The second endpoint equality

```text
y_R,from == rotate(Q,y_F,to) + t
```

is validation only; no alternative translation may be solved from it. The two endpoint maps imply the existing transported-delta obligation `rotate(Q,d_F) == -d_R` in relation endpoint coordinates. Semantic reversal is exactly `T^-1 = (Q^-1, -rotate(Q^-1,t))`.

Canonical storage is representation-only. Derive semantic `T` before storage canonicalization. If canonical storage orientation agrees with A3 Forward -> Reverse, store `T`; if it reverses representation, store `T^-1` and reverse the associated routes exactly. `PeriodicRelationId` remains unchanged, and deterministic semantic resolution must return `T` from A3 roles rather than pair insertion/storage order. Relation endpoint states remain in the Forward-anchored relation gauge and are not regenerated when storage reverses.

The zero-turn reduction is defined by **`Q == identity`**, not by raw `A == identity`. In that case Reverse normalization is identity, relation endpoint coordinates equal ordinary cut-domain coordinates, and the existing ordinary translation/branch behavior is recovered exactly. No ordinary cell-placement producer changes.

The nonzero-Z4 produced witness criterion is also relation-gauge authority: compute `Q` from exact A3 occurrences, directed A1 transport and accepted cut gauges **before relation publication**, and require `Q != identity`. The committed torus row4/5 witness satisfies this independently. Static principal-matching reconstruction over the committed 216-edge torus finds exactly five nonzero source transitions — `(0,3)`, `(3,25)`, `(25,37)`, `(37,49)`, `(0,61)` — and all five belong to the exact 18-edge accepted hard-cut set. Thus every retained dual transition used by A4 gauge propagation is zero and `faceBranchRotation` is identically zero. Mandatory full-edge source paths use canonical edge orientation, so `(0,3)` Forward `0 -> 3` is owned by face `22` and Reverse `3 -> 0` by face `1`; stored source transport is `+1` in direction `1 -> 22`, so semantic `A(22 -> 1)=3`, while `G_F=G_R=0`. Therefore the independently expected quotient turn is **`Q=3 mod 4`**. The current fixture/field/A3 witness is valid and must not be retuned. Its full expected relation action is uniquely `T=(3, rotate(3, x_R,to - x_F,from))`, with the second endpoint map as an independent exact check.

This amendment discharges `M5-CP3-TB1-R14-REV-OBS-01`. It supersedes only §16.2's statement that implementation authority is absent; §§14–16.2 remain binding historical/semantic context, including all no-search/no-fitting rules. Product recovery is not claimed from this runtime-free definition. Exactly one implementation successor is authorized: `M5-CP3-CB17`, bounded to this mapping plus directly coupled focused test-contract correction and compile-only validation.

## 17. CP3 R16 Review amendment — exact cumulative selector448 publication precommit

`M5-CP3-TB1-R16-REV` independently accepts the complete corrected pre-publication gate and freezes the exact cumulative selector that may be published next. This section changes no product/test/fixture/field/A3 semantics; it completes frozen §13.3 step 3 only.

The accepted published prefix remains selector430 at SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, 430 unique LF-terminated rows and 35,001 bytes. The successor selector is exactly that byte prefix followed by the 18 R16 nonselector identities in their pre-execution order. It has **448 rows / 448 unique identities / 36,382 bytes / 448 LF / terminal LF**, SHA-256 **`70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`**, and owner census **32 authority-kernel / 300 producer / 75 completion / 41 validation**.

| ordinal | exact appended identity |
|---:|---|
| 431 | `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` |
| 432 | `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` |
| 433 | `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator` |
| 434 | `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained` |
| 435 | `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap` |
| 436 | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation` |
| 437 | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate` |
| 438 | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation` |
| 439 | `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` |
| 440 | `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory` |
| 441 | `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory` |
| 442 | `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency` |
| 443 | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` |
| 444 | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` |
| 445 | `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped` |
| 446 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` |
| 447 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` |
| 448 | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` |

Publication path is frozen as `.agents/Directional/Architecture_M5_CP3_CB20_Required_Green_Selector_448.txt`. `M5-CP3-CB20` may create only those exact bytes. It may not derive order from discovery, sort or target ownership; owner inspection validates membership only. Any byte/hash/prefix/census discrepancy fails closed.

This precommit is not selector acceptance. Frozen §13.3 remains binding: CB20 publishes and compile/packages without runtime; `M5-CP3-TB2-EXEC` then executes all 448 published identities freshly with exact-one/zero-skip and immutable postflight; only mandatory `M5-CP3-TB2-REV` may accept the published selector and close M5 after re-verifying the full exit theorem.

R16 Review discharges all four M5 produced debts, but project debt remains **1** because the closed-complex `G4-B002` obligation is M6-owned. Stable regression accounting remains **51 / 14 / 37**.

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** M5-DEFN is complete and well-constructed. Entering authority is exact, all four
inherited debts are bound to named checkpoints with discriminators preserved, and the two design decisions that
carry the most weight are both correct. One forward-looking risk is recorded; no amendment is required and none
is made.

### V1 — entering authority re-derived

§1 is exact against the accepted M4 exit: selector430 `430/430` at
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` — the value this reviewer verified before CB8
built it and again on publication — owner census `31 / 283 / 75 / 41` summing to 430, accounting
**49 / 14 / 35**, and produced-witness debt **5** split **4 M5-owned / 1 M6-owned**. The split reconciles
exactly: §8.2's four (two periodic `G4-B002` re-homed at `DEFN-R1`, two `G4-B003` always M5's) plus the
closed candidate-bearing-complex `G4-B002` re-homed to M6 at `DEFN-R2`.

§8.2 states the M6 boundary in the operative direction — "M5 may not pull A5 occurrence ownership backward to
obtain evidence" — which is the form that actually prevents the error, rather than merely naming the owner.

### V2 — §8.1 is the anti-substitution guard, and it is built on real bytes

The "highest stage already proved" table records the strongest existing evidence for each debt and marks all of
it **mechanism-only, no produced-witness credit**. Both helpers it names are real and correctly classified:
`direct_periodic_owner_product()` and `direct_full_periodic_materializer_draft()` both live in
`tests/SurfaceCellTransitionQuotientTests.cpp`, and both are direct/draft constructions rather than pipeline
products.

This is the most valuable section in the document. Four debts already have *almost*-passing direct witnesses
sitting in the tree; without §8.1 the cheapest path to closing M5 would be to quietly promote them. The closing
sentence forecloses it explicitly: fixture presence, direct builders, synthetic products and phase-front
reachability without produced periodic relations do not discharge a production debt.

### V3 — separating identity from transport is what keeps the `G4-B003` tamper non-vacuous

§3.1 makes `PeriodicRelationId` a content identity that explicitly excludes composed transport / `GridAutomorphism`,
vector position or table row, and execution handles, stating: "Transport is **relation value**, not relation
identity."

The consequence deserves to be named because it is load-bearing two checkpoints ahead. If identity included
transport, then tampering a transform would produce a **different** relation id — and
`TamperedFullPeriodicTransformIsRejected` would observe a new relation rather than a rejected one. The test would
pass while proving nothing. Excluding transport from identity is precisely what makes that discriminator
falsifiable, and §10's amendment — "transform tamper becomes a conflict on one stable semantic relation rather
than a new identity" — records the reasoning correctly.

### V4 — the re-homed debt acquired a mechanism, not just an owner

`M4-CP4-DEFN-R1` re-homed the periodic debts to M5 on the ground that same-sheet basis identity requires the
later topology-basis solver that `src/geometry/SurfaceCellTracing.cpp:6322-6325` defers. §9 now supplies exactly
that: CP1 must "permit multiple distinct same-region relations when their **canonical path identities differ**",
and CP3 must prove production emits at least two canonical same-region relations on the accepted row408-class
one-region torus.

That closes the loop opened at `DEFN-R1` and settled at `TB1-R3-REV`. Content-based identity is what makes two
same-region generators distinguishable without guessing a basis by discovery order — the unsound approach the
product comment refused. The re-homing was therefore not debt deferral: the obligation arrived with a concrete
mechanism and a checkpoint that must prove it.

### V5 — DISCHARGED AT `M5-CP3-TB2-REV`: M5 exit conditions reconciled once at closure

At `M4-CP4-TB3-REV` I required M5's exit theorem to appear in the governing M5 document. It does not:
`Architecture_M5_Frozen_Definitions.md` contains no "M5 closes when…" clause, and neither does the DEFN record
nor the CP1 plan.

**This is not the M4 defect, and I am deliberately not repeating last turn's repair.** §12's citation map answers
the question rather than ignoring it, assigning *milestone acceptance* to `DESIGN.md` §14 M5 — which does carry
acceptance criteria (exact selected relation paths retained and independently verified; unused valid relations do
not alter the selected certificate; the five failure classes fail typed; torus lineage and quotient acceptance
are direct production evidence), extended by the DEFN-R1 amendment naming the two inherited periodic debts. There
is no contradiction to reconcile here, and writing an exit theorem would be a definitional act rather than a
reconciliation — outside what a review turn should decide unilaterally.

The residual risk is one of shape, and this project has already been bitten by it once. M5's *general* acceptance
lives in the charter while its *operative, testable* conditions — four debts, preserved `>=2` discriminators, the
mechanism-only prohibition, the CP1/CP2/CP3 bindings — live in §§8-9 of this checkpoint-local document. That is
the same division that produced `M4-CP4-TB3-REV-OBS-01`, where the two halves diverged and the divergence only
became visible at the moment of closure.

**Discharged at `M5-CP3-TB2-REV`.** Final Review states the seven-conjunct M5 exit once, explicitly reconciles `DESIGN.md` §14 M5 with §§8-9/13 of this document, confirms all four debts on produced authority, and preserves the prohibition on mechanism-only production credit. `M5-DEFN-REV-OBS-01` is closed.

### V6 — successor scope and verification limits

`Architecture_M5_CP1_Code_Build_Plan.md` is Code + Build / runtime-free and compile-only, forbids weakening any
accepted selector430 identity, forbids CP2 acceptance claims, and forbids downstream graph search as a semantic
substitute for producer-selected certificates. No selector pre-commitment is due, correctly — CB1 publishes
nothing; the pre-commitment obligation attaches to the first M5 publication CB, on selector430 as byte-frozen
prefix.

Re-derived from repository bytes: selector430's hash and owner-census arithmetic, the existence and direct/draft
character of both helpers named in §8.1, §3.1's identity exclusions, §§8.2/9 debt-to-checkpoint bindings and
their totals, and the absence of any exit clause across all three M5 documents. Accepted as reported: the
definition-audit source snapshot and artifact identifiers.
