# M6-DEFN-R3 — A6 quotient-product separation definition record

**Turn:** `M6-DEFN-R3`
**Type:** runtime-free Definition amendment
**Predecessor:** `M6-CP1-TB5-REV` review-agent addendum
**Exact successor:** mandatory independent `M6-DEFN-R3-REV`
**First implementation if Review accepts:** `M6-CP1-CB6-A6`
**Reviewed runtime entering the turn:** package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 `449/449`
**Stable accounting:** `55 / 16 / 39`, produced-witness debt `1`

## 1. Scope and evidence boundary

This record decides only the bounded recovery scope in `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md` §5: the CP1 exit checklist, A6 class identity, exact-once relation ledger including cycle-closing relations, selected-path ownership, A6 failure vocabulary, the first A6 Code + Build plan, and its frozen-test audit. A7 representation and the `G4-B002` stage-boundary representation are intentionally deferred to `M6-DEFN-R4`; §8 records intent only.

No Directional executable, test, benchmark, configure, compile, relink, fixture, selector, or routing mutation is part of this Definition turn. The exact source snapshot used for cross-file inspection is workflow run/artifact `36199074014 / 10890838063`; snapshot commit `fbbb4cac835887b60aa5fc22083cc6d068ee886c` differs from the semantic entry head `c4d046289276f6b4ecc496ae41c697e0a7852d16` only by the source-snapshot trigger marker. The snapshot manifest verifies 5,317/5,317 files; embedded archive SHA-256 is `b850d7a3166c78d4cc9813685af2ce8901b3cb391d46da4e647aa8d2be7b6ca3` and records `runtimeExecution=false`.

## 2. CP1 exit checklist — normative confirmation

CP1 closes only after exact source plus a fresh accepted gate prove all of the following together:

1. **A5:** conformant immutable `SurfaceOccurrenceComplex`; unread representative fields `SurfaceOccurrence::{chart,lattice,isolationSheet}` are retired while live `point`, `chartComponent`, complete wedge bindings, placement provenance and isolation evidence remain.
2. **A6:** immutable `SurfaceQuotientProduct` exists with member-set semantic class identity, one relation certificate and one consumption row for every A5-owned relation, deterministic selected-path evidence, `QuotientCertificate`, and `MaterializationCertificate`.
3. **A7:** immutable `SourceAttachedGeometryProduct` and its source-support/embedding certificates exist. Representation details are deferred to `M6-DEFN-R4`.
4. **Thin adapter:** `build_authoritative_phase_front_mesh(...)` makes no semantic occurrence, quotient, relation-selection, or embedding decision; it only projects immutable stage products into compatibility/output surfaces.
5. **No weld:** coordinate, lattice, point, output-row, scheduler, representative-sheet, hash, or cache equality never creates occurrence/class equality.
6. **`G4-B002` boundary:** a closed-complex view is derived from A6 without `SurfaceCellPipelineContext::hasArrangement`; its exact representation is deferred to `M6-DEFN-R4` and CP3 still owns direct-production re-proof.
7. **Preservation:** focused multi-isolation remains green and selector449 is re-executed fresh at 449/449 after the A6/A7 cutovers.

The previous statement that CP1 was one standalone legacy-field cleanup away from closure is superseded.

## 3. A6 semantic class identity

### 3.1 New semantic ID type

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

### 3.2 Transitional ordinal remains adapter-only

`authority::QuotientClassId` remains a compatibility/output ordinal only. It is not stored as A6 semantic identity. During the transitional adapter, A6 classes are sorted by `SurfaceQuotientClassId`; ordinal rows `0..N-1` are assigned in that order and projected to `PureQuadVertexLineage::quotientClass`.

This satisfies RA-10 without preserving the old class-key-derived ordinal as authority. Existing frozen tests do not pin a numeric quotient ordinal. The storage-permutation test compares `(ordinal, sourceOccurrences)` only between equivalent executions, and hash assertions compare invariance rather than a hard-coded hash; lexicographic member-set ordering remains satisfiable under those tests.

## 4. Exact-once relation certificates and ledger

### 4.1 Canonical relation processing

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

### 4.2 Deterministic selected forest and cycle rule

Joining rows form the A6 **selected relation forest**. Every forest edge stores its relation-certificate identity and orientation; ordinary identity edges are retained even when they have no downstream legacy selected-path projection.

For a cycle-closing relation `(a -> b)` there is one unique forest path from `a` to `b`. A6 composes the path transport in traversal order, using the exact inverse of a certificate transport whenever the path traverses that certificate opposite its stored orientation.

The frozen acceptance rule is exact:

```text
relationTransport == compose(selectedForestPath(a -> b))
```

If not, A6 fails `QuotientHolonomyConflict`. Equivalently, the closed loop formed by the new relation and the existing path has identity residual. The direct relation/path transports may themselves be non-identity; the rule is consistency, not "all periodic actions must be identity".

### 4.3 Exact-once invariants

`QuotientCertificate` must prove:

- certificate count == A5-owned relation count;
- consumption-row count == A5-owned relation count;
- relation IDs are a bijection across A5 ownership, relation certificates, and consumption rows;
- no unowned relation participates in partition, forest, path, classed topology, or lineage projection;
- every joining row appears once in the selected forest;
- every cycle-closing row has an exact path-consistency result;
- the class partition is exactly the transitive closure of the certified owned relations.

A validation/publication seam exists only for focused negative tests; production construction never fabricates missing/duplicate/conflicting ledger state.

## 5. Analytical holonomy proof and produced-fixture falsifier

This Definition turn runs no producer. The rule in §4.2 is therefore proved only where it follows from frozen fixture geometry/field construction without executing Directional.

### 5.1 Split square

The split-square fixture is two coplanar triangles of the unit square with the same constant XY 4-RoSy field and constant target size; only the source-sheet labels differ across the diagonal. Ordinary non-seam relations have identity transport. The isolation-seam relation uses the reciprocal seam quarter-turn; because the two triangles are coplanar and the constant field has the same tangent orientation on both sides, its exact quarter-turn is zero, so its lifted `GridAutomorphism` is identity. Therefore every possible forest path and every cycle-closing direct relation in this fixture compose to identity, satisfying §4.2.

### 5.2 Uniform hard-rail rectangle

The hard-rail fixture is a planar 3x3 vertex grid under the same constant XY field and uniform metric, with the interior vertical midline marked as a hard rail. Ordinary relations are identity. The reciprocal HardRail relation compares the same planar lattice frame on the two rail sides, so its exact relation action has zero quarter-turn and zero translation. Consequently every relation in any quotient-class cycle is identity and direct/path transports agree.

This is an analytical property of the authored fixture; it is not a claim that the production fixture was executed in this turn.

### 5.3 Ordinary-only classes

For a class whose relations are all ordinary, and none crosses a nonzero seam transport, every certificate transport is identity by definition. Any forest-path composition and any direct cycle-closing transport are therefore identity. Such a class cannot produce `QuotientHolonomyConflict` unless certificate construction itself is inconsistent.

### 5.4 Produced torus/cylinder falsifier

The produced torus and cylinder/annulus classes cannot be enumerated runtime-free. The A6 TB therefore pre-registers the cycle rule as a falsifier:

- selector row **232** `SurfaceCellTypedTransportAuthority.ValidPeriodicCutRouteUsesTypedIdentity` exercises the produced cylinder through materialization;
- torus selector rows **444 / 446 / 448 / 449** exercise produced periodic/multi-isolation authority and materialization surfaces.

If any accepted row first fails with `QuotientHolonomyConflict`, TB must not weaken the rule. Mandatory TB Review determines whether the evidence proves (a) a real inconsistent quotient cycle or (b) a legitimate class with nontrivial residual holonomy that invalidates the strict rule.

Fallback, **not authorized unless that Review changes the Definition:** keep exact-once certificate/ledger semantics, record both `relationTransport` and `selectedPathTransport` plus the nonidentity residual on a cycle-closing row, and treat the row as evidence-only rather than rejection. This fallback exists to avoid hiding evidence if legitimate deck-transform holonomy is demonstrated; CB/TB may not select it on their own.

## 6. Selected relation paths are A6 authority

A6, not A7, owns relation-path selection.

For each semantic class:

1. choose the first (smallest) member of its sorted `SurfaceQuotientClassId` as the **path root**; this is evidence rooting only, never geometric representative selection;
2. use the unique selected-relation-forest path from that root to every other member;
3. store exact ordered relation-certificate IDs, traversal orientation, relation-local source chart/component bindings where the current HardRail/Periodic certificate requires them, and the exact composed transport;
4. keep ordinary identity joins in A6 path authority even when they produce no legacy selected-relation step.

A7 may project this evidence into `PureQuadVertexLineage::selectedRelationPaths`; it does not select/recompute paths. To preserve the accepted compatibility contract, the transitional lineage projection emits legacy `SelectedRelationPathCertificate` entries only for A6 paths containing at least one HardRail or Periodic selected relation step. Ordinary-only and isolation-wedge evidence therefore do not make split-square `selectedRelationPaths` non-empty. Existing completion-stage re-anchoring in `PureQuadCompletion.cpp` remains representation-only and unchanged.

An unrelated valid M5 relation that A5 does not publish as an owned occurrence relation is decision-neutral and cannot enter the forest or path set.

## 7. A6 typed failure vocabulary

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

## 8. Deferred R4 intent only

**A7 intent.** `M6-DEFN-R4` will freeze `SourceAttachedGeometryProduct` as a source-attached representation of already-decided A6 classes: one embedded output vertex per semantic class, exact source-support/embedding certificates, complete wedge-union sheet/chart/equivalence lineage, and no topology mutation. Geometry/representative selection is representation-only and may not alter the A6 partition, selected relation forest, or ledger.

**`G4-B002` stage-boundary intent.** `M6-DEFN-R4` will freeze the A6-derived closed-complex view needed by candidate extraction so that the consumer no longer relies on `SurfaceCellPipelineContext::hasArrangement`. CP1 proves the mechanism/equivalence on an existing closed fixture; CP3 still owns the direct-production candidate-eligibility and hard-feature-tamper re-proof required for `G4-B002` credit.

## 9. First A6 implementation sequence

If and only if `M6-DEFN-R3-REV` accepts this record, the first implementation turn is `M6-CP1-CB6-A6` under `Architecture_M6_CP1_CB6_A6_Quotient_Product_Extraction_Code_Build_Plan.md`.

That CB absorbs the previously standalone legacy-field retirement. It adds exactly four new focused identities:

1. `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant`
2. `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord`
3. `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption`
4. `M6CP1.CycleClosingRelationTransportConflictRejected`

The next artifact-only gate, if Code + Build is compile-green, is **11 focused + selector449 = 460 fresh exact-filter processes**. The unchanged seven entering focused identities run first, then the four new A6 identities, then selector449 in exact frozen order. No selector file is changed or appended.

## 10. Frozen-test audit for the A6 CB

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

## 11. Turn disposition

`M6-DEFN-R3` is definition-complete for its bounded scope only. It grants no implementation, runtime, regression closure, G4 credit, or CP1 acceptance. Stable accounting remains **55 / 16 / 39** and debt **1**. Exact successor is mandatory independent `M6-DEFN-R3-REV`; `M6-CP1-CB6-A6` remains held until that Review accepts or amends this definition.
