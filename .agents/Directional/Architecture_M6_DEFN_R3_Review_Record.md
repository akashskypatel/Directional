# M6-DEFN-R3-REV — independent A6 quotient-product definition review

**Turn:** `M6-DEFN-R3-REV`
**Type:** independent runtime-free Review
**Predecessor:** `M6-DEFN-R3`
**Disposition:** **ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-4**
**Exact successor:** `M6-CP1-CB6-A6`
**Reviewed runtime authority remains:** package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 `449/449`
**Stable accounting:** unchanged `55 / 16 / 39`, produced-witness debt `1`

## 1. Evidence boundary

This Review is static and runtime-free. It executed no Directional binary, test, benchmark, configure, compile, or relink operation and grants no runtime or checkpoint credit.

Review source was frozen by source-snapshot run/job `36207017645 / 108305601337`, artifact `10894735898`, event/snapshot SHA `dba4fbba516f3b309103c4b6529ad6194b9caa52`. The artifact provider digest is `1241268d4e0e55cbf273e1820b02a54f630dda1563b9593e96678b87600a2bfa`; embedded source archive SHA-256 is `cf5bb84898a5179824749feb9d9279cad1193e0a8c18429600d60252480f41c7`; metadata records 5,319 files, 98,165,063 bytes, recursive submodules and `runtimeExecution=false`.

A commit comparison from reviewed runtime semantic source `82b86a28...` through the Review snapshot is 66 commits ahead and contains documentation/control-plane changes only; no `src/`, `include/`, or `tests/` file changed. Selector449 and routing449 remain 449 lines at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` / `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

The Review independently inspected the R3 definition/plan, frozen M6 contract, held A6 CB plan, DESIGN quotient contract, exact accepted transitional source, and frozen focused storage-permutation witness.

## 2. Upheld R3 decisions

The following R3 decisions are accepted without semantic weakening:

1. A6 semantic class identity is the exact sorted unique non-empty member-`OccurrenceId` set; `authority::QuotientClassId` remains adapter-only ordinal lineage.
2. Every A5-owned relation receives exactly one immutable relation certificate and one consumption row, including cycle-closing relations.
3. Joining rows form one deterministic selected forest; cycle-closing rows are not skipped.
4. The strict cycle rule remains direct canonical relation transport == exact canonical selected-forest path transport; mismatch is `QuotientHolonomyConflict`. Non-identity direct/path actions remain valid when equal.
5. A6 owns selected relation paths; A7 only projects them. Legacy `selectedRelationPaths` remains HardRail/Periodic-only.
6. R3's A6 error vocabulary, A7/R4 deferral, `G4-B002` R4 deferral, and the produced cylinder/torus TB falsifier remain binding.
7. The first A6 implementation still absorbs retirement of unread `SurfaceOccurrence::{chart,lattice,isolationSheet}` and remains compile/package-only.

R3 is therefore architecturally sound, but four precision defects must be corrected before implementation.

## 3. Review amendments

### RA-1 — certificate direction is canonical semantic relation direction

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

### RA-2 — every accepted OrdinaryFront quotient transport is identity

For A6 quotient semantics, every accepted `OrdinaryFront` relation publishes:

```text
relationTransport = GridAutomorphism::identity()
```

A checked isolation-seam transition remains source-chart/sheet evidence used to establish admissible reciprocal authority. Its quarter-turn is **not** the quotient relation transport.

Evidence: the accepted transitional OrdinaryFront path first requires exact `lattice_equal(first.fromLattice, second.toLattice)` and the reciprocal endpoint equality. `lattice_equal` includes lattice coordinate, branch rotation, scale level, source chart and phase. Thus the accepted quotient endpoint identification itself is identity in the already-transported local-lattice state. Lifting the source isolation-seam quarter-turn into an additional quotient transform would double-count evidence and can synthesize holonomy that the accepted equality relation does not contain.

This amendment supersedes R3 §4.1's separate “ordinary relation crossing a checked isolation seam” transport rule. It does not weaken any seam certificate check.

### RA-3 — A5 relation evidence must be sufficient for A6; representation handles cannot reconstruct transport

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

### RA-4 — path transport composition order is frozen explicitly

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

## 4. Focused-gate amendment

The four planned new identities are retained; no fifth identity and no selector mutation is authorized. The later gate remains **11 focused + selector449 = 460 fresh exact-filter processes**.

Amend their required coverage as follows:

1. `M6CP1.QuotientClassIdIsSortedMemberSetAndStorageInvariant` also compares the canonical relation-certificate orientation/transport signature under reciprocal front-edge storage swap and relation/cell/source-face storage permutations. This directly protects RA-1 and the existing row6 contract.
2. `M6CP1.EveryOwnedRelationHasExactlyOneConsumptionRecord` is unchanged except that certificate transport is checked in RA-1 canonical direction.
3. `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption` is unchanged.
4. `M6CP1.CycleClosingRelationTransportConflictRejected` must start from an individually valid certified cycle and alter exactly one otherwise admissible direct cycle-closing certificate through the A6 validation-publication seam. It must not fabricate an invalid OrdinaryFront transform to obtain the rejection. The untampered cycle must publish.

Existing focused row6 remains an independent storage-direction falsifier. Cylinder selector row232 and torus rows444/446/448/449 remain the runtime falsifiers for the strict holonomy rule.

## 5. Review of the held Code + Build plan

With RA-1 – RA-4 folded into `Architecture_M6_CP1_CB6_A6_Quotient_Product_Extraction_Code_Build_Plan.md`, the plan is sufficiently bounded for implementation:

- one new immutable A6 product/producer;
- one evidence-complete A5 relation projection required to honor the already-frozen A5→A6 product boundary;
- retirement of only the three proven-unread A5 representative fields;
- transitional adapter consumes A6 and may not recompute quotient semantics;
- exactly four new focused identities;
- compile/package only, no generated runtime.

Stop conditions remain mandatory: if enriching A5 relation evidence requires changing relation identity/equality/owner selection, if a supposedly dead field has a live semantic consumer, or if A6 cannot validate HardRail/Periodic transport without reaching back into representation-owned global arrays, stop and return to Review rather than widening the CB.

## 6. Regression/accounting disposition

This Review finds definition defects before implementation/runtime. It creates **no stable regression event**, no category/recurrence change, no recovery claim, and no produced-witness credit. Stable accounting remains **55 / 16 / 39** and debt **1**. Reviewed runtime authority remains package/source `10879581622 / 82b86a28...` under selector449 449/449.

The strict holonomy rule remains provisional only in the already-defined sense: the produced cylinder/torus rows are required runtime falsifiers, and only mandatory TB Review may invoke the documented evidence-only fallback if those rows prove legitimate nontrivial residual holonomy.

## 7. Final disposition

`M6-DEFN-R3-REV` is **ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-4**.

Exact next is `M6-CP1-CB6-A6`. Do not start `M6-DEFN-R4`, A7 extraction, `G4-B002` boundary implementation, or runtime TB before that Code + Build turn completes. Compile-green `M6-CP1-CB6-A6` advances only to immutable `M6-CP1-TB6-A6-EXEC`, then mandatory `M6-CP1-TB6-A6-REV`.
