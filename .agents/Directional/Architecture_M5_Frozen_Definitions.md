# M5 Frozen Definitions — Certificate-Carrying Chart and Quotient Relations

**Status:** FROZEN / `M5-DEFN` COMPLETE / EXACT NEXT = `M5-CP1-CB1` / RUNTIME-FREE
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

### `M5-CP1` — canonical identities and selected certificates

Implement the non-ordinal `PeriodicRelationId`, preserve it through aggregation, permit multiple distinct same-region relations when their canonical path identities differ, publish producer-selected path certificates, and convert the known downstream reachability consumer to certificate validation. Author/compile focused mechanism coverage for relation-order invariance, exact path retention, certificate composition, and semantic discrimination. Do not claim the production debt yet.

### `M5-CP2` — typed relation failures

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

## 11. Exact successor

**`M5-CP1-CB1`** under `Architecture_M5_CP1_Code_Build_Plan.md`.

It is a Code + Build turn: implementation/test-definition changes and compile-only verification are authorized exactly as that plan states. Directional runtime tests and benchmarks remain forbidden until the successor Test + Benchmark turn.

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
| exact next implementation | `Architecture_M5_CP1_Code_Build_Plan.md` |
