# M5 Frozen Definitions — Certificate-Carrying Chart and Quotient Relations

**Status:** FROZEN / `M5-DEFN` COMPLETE / CP1 + CP2 CLOSED / EXACT NEXT = `M5-CP3-CB1` / RUNTIME-FREE REVIEW AMENDMENT 2026-09-20
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

### 8.2 Four M5 debts remain unchanged

1. `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`: **M5-CP1 mechanism / M5-CP3 direct-production re-proof**, retaining the original **`>=2` distinct produced relations and `>=2` owned periodic edges** discriminator.
2. `MissingPeriodicRelationOwnerIsRejected`: **M5-CP2 mechanism / M5-CP3 direct-production re-proof** on produced periodic authority.
3. `FullPeriodicRotationAndTranslationMaterialize`: **M5-CP3** direct production with a genuinely nonzero Z4 rotation and nonzero translation, carried through materialization/lineage/quotient acceptance.
4. `TamperedFullPeriodicTransformIsRejected`: **M5-CP3** same direct-production subject with a discriminating nonzero-Z4 transform tamper.

M6 retains the separate closed candidate-bearing-complex `G4-B002` debt. M5 may not pull A5 occurrence ownership backward to obtain evidence.

## 9. Checkpoint split

### `M5-CP1` — canonical identities and selected certificates — **CLOSED / ACCEPTED**

Implement the non-ordinal `PeriodicRelationId`, preserve it through aggregation, permit multiple distinct same-region relations when their canonical path identities differ, publish producer-selected path certificates, and convert the known downstream reachability consumer to certificate validation. Author/compile focused mechanism coverage for relation-order invariance, exact path retention, certificate composition, and semantic discrimination. Do not claim the production debt yet.

### `M5-CP2` — typed relation failures — **CLOSED / ACCEPTED at `M5-CP2-TB1-REV`**

Complete the five-class relation failure matrix with independent negative oracles. Missing/duplicate/conflicting/nonreciprocal/representation-renumbered failures must reject at the named authority boundary without repair. This checkpoint supplies the mechanism credit for `MissingPeriodicRelationOwnerIsRejected` but not its production debt.

### `M5-CP3` — direct-production exit

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

## 11. Current exact successor

**`M5-CP3-CB12`** under `Architecture_M5_CP3_CB12_A3_Directed_Periodic_Pair_Ordering_Correction_Plan.md`.

`M5-CP3-TB1-R10-REV` independently upholds the R10 **444 PASS / 2 RED** diagnosis and exact immutable postflight, but rejects the result artifact for acceptance because its self-manifest covers only **911/912** required non-manifest evidence files. Review closes CB11's specific raw same-region family/sign pre-veto defect and discharges the §16 `R=0` preservation observation. Exact executed source nevertheless chooses same-region generator/action direction from reciprocal-pair insertion order. That is an implementation violation of existing §14.3's explicit no-vector/insertion-order authority rule and §16's exact directed A3/source-path requirement; **no semantic amendment to §§14–16 is made**. CB12 changes only that product direction-selection locus so exact A3 interval orientation binds Forward -> Reverse before the one generator/action construction. Compile-green routes to the unchanged 446-process R11 plus mandatory Review, with complete post-copy result self-manifest finalization required.

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

### V5 — RECORDED RISK: M5's exit conditions are stated in two places and nowhere in full

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

**Required before M5 closes, not now:** the turn that adjudicates M5 closure must state M5's exit once,
explicitly, reconciling `DESIGN.md` §14 M5 with §§8-9 of this document, and must confirm against **both** that
all four debts are discharged on produced authority with no mechanism-only credit. Recorded as
`M5-DEFN-REV-OBS-01`, owned by `M5-CP3`.

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
