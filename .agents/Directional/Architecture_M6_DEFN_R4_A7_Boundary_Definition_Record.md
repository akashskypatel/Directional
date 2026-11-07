# M6-DEFN-R4 — A7 Product, Thin Adapter, and `G4-B002` A6 Boundary — Definition Record

> **Review disposition (`M6-DEFN-R4-REV`, 2026-10-03):** ACCEPTED WITH BINDING AMENDMENTS RA-18 – RA-21 (`Architecture_M6_DEFN_R4_Review_Record.md`; normative text at the end of `Architecture_M6_Frozen_Definitions.md`). Where they conflict, the amendments override §2.2 (support guard), §3.4/§5.2 (placement inside A5; identity 24), §4.2–§4.3 (protection from source hard-feature authority) and §4.4 (oracle key path and stop rule). `M6-CP1-CB9-A7` is authorized.

**Turn:** `M6-DEFN-R4`
**Type:** Definition only; runtime-free.
**Entering reviewed runtime:** `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`, focused 1–12 + selector449 = **461/461**.
**Accounting:** **60 / 16 / 44**, debt 1.
**Source inspection authority:** source-snapshot run `37137065911`, artifact `11277809639`, exact snapshot SHA `c7deb092e86f0912a304397e364d47dc94587a5a`, outer artifact SHA-256 `81cce673b5585f799bcee419dda5ab8602bbe3213e855996fd75ad9a4b6f23eb`.
**Mandatory successor if this Definition completes:** `M6-DEFN-R4-REV`.

## 0. Turn checklist

- [x] D4 consumer and frozen-assertion census first.
- [x] D1 A7 representation and certificates.
- [x] D2 55-site thin-adapter classification and precedence.
- [x] D3 `G4-B002` A6 stage-boundary representation/equivalence demonstration.
- [x] D5 CB sequencing, focused identities and gate sizes.
- [x] R4 amendment appended normatively to `Architecture_M6_Frozen_Definitions.md`.
- [ ] Handoff/TODO/CHANGELOG closeout and mandatory `M6-DEFN-R4-REV` authorization.

This record is intentionally **IN PROGRESS** after D4. No A7, adapter, `G4-B002`, source, test, fixture, selector, or build implementation is authorized by the work recorded here.

**Operational evidence:** the start-of-turn `READ_MODE` gate was initially missed by directly reading the mandatory policy/handoff/TODO bundle before selecting snapshot mode. The miss was recognized immediately after the conservation policy was read; piecemeal repository source/document inspection then stopped. All substantive D4 inspection and this work product use the verified exact snapshot above.

## 1. D4 — consumer and frozen-assertion census — COMPLETE

### 1.1 Method and completeness boundary

The exact-snapshot census is stored in
`Architecture_M6_DEFN_R4_D4_Consumer_Census.md`. It conservatively retains every exact textual reference under `src/`, `include/`, `tests/`, and `benchmarks/` to the outputs named by the R4 plan:

- `vertexPositions`, `vertexProvenance`;
- lineage `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `selectedRelationPaths`;
- `hash_completion`;
- `BenchmarkQuality`.

The census deliberately keeps producer/mutation sites as well as apparent reads. This is a strict superset of readers: it prevents a compound mutation/read expression from being dropped by a heuristic. Every row records `file:line`, production/test classification, a role hint, enclosing GTest identity when recoverable, selector449 row and focused-12 ordinal when present, and the exact source line. The snapshot contains **1,189 unique reference sites**: **666 production** and **523 test/benchmark**. Per-output counts are recorded in the census header.

This is the D4 authority for D1–D3. Later R4 decisions may narrow a site from the conservative set only by explaining why it is not a consumer of the A7/boundary value; no later decision may silently omit a listed frozen assertion.

### 1.2 Frozen assertions that directly constrain A7 geometry and representative publication

The census identifies the following already-frozen gates that directly read the geometry/provenance surface R4 will replace or project:

| Authority | D4 outputs read | R4 consequence |
|---|---|---|
| focused-12 ordinal 7 `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | `sourcePoint`, `sourceTopologyRegions`, `sourceIsolationSheets`, `equivalences`, `selectedRelationPaths` | A7 projection must retain complete occurrence-derived region/sheet/equivalence/path authority. |
| focused-12 ordinal 12 `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | `vertexPositions`, `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `equivalences` | R4 may replace floating geometry authority only if the published geometry remains support-attached and the RA-17 transport guard remains true. |
| selector449 row 73 `PureQuadCompletionPhase18.CompletionVerticesCarrySourceProvenance` | `vertexPositions`, `vertexProvenance` | one A7 vertex per A6 class must still publish complete source provenance. |
| row 87 `PureQuadCompletionPhase18.P18GeneratedInteriorVertexHasSourceTriangleLineage` | `sourcePoint` | representative/source-point publication remains a frozen observable; D1 must define it deterministically. |
| row 97 `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing` | `vertexProvenance`, `sourcePoint`, `sourceSupport`, `sourceIsolationSheets`, `sourceTopologyRegions` | A7 cannot accept stale or reconstructed authority merely because coordinates are close. |
| row 250 `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets` | geometry, provenance, all principal lineage unions, `equivalences`, `hash_completion` | D1 changes must preserve the complete integrated output contract and deterministic completion hash. |
| row 448 `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | `vertexProvenance`, `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `hash_completion` | unused valid relation evidence must remain observationally inert; A7 selection cannot depend on relation-container order or unused relation presence. |

Additional accepted Phase18 lineage authority is explicit at selector449 rows **86, 96, 100, 102, and 103**. These rows pin missing-lineage fail-closed behavior, sparse-owner publication, topology-region ownership, chart correctness, and isolation-sheet correctness respectively. D1 must cite these rows when fixing each projected lineage field.

### 1.3 Frozen assertions that constrain selected relation paths and hashes

- selector449 row **438**, `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`, reads `selectedRelationPaths` and `sourceTopologyRegions`; selected path evidence therefore remains certificate evidence, not an A7 placement authority.
- rows **436** and **437** read `hash_completion` to freeze selected-certificate invariance under relation container permutation and unused valid relations.
- rows **448** and **449** also read `hash_completion`; any A7 lineage re-expression must define whether it changes the hash and must preserve the accepted invariances.
- row **241**, `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`, and row **250** freeze deterministic completion hashing at the broader pipeline surface.
- all `BenchmarkQuality` references are enumerated in the companion census so D1/D3 can state whether a new A7/boundary hash is projected into the existing quality-path hashes or remains a separate certificate digest.

### 1.4 Representative-key and transport-guard observations established by the census

The current transitional materializer at `src/pipeline/RemeshPipeline.cpp:6103-6113` chooses the representative by the lexicographic key
`(SourceSupport, cornerWedgeBindings, OccurrenceId)`. The same function currently performs the forbidden semantic floating comparison at `:6118-6127` and emits `QuotientGeometryConsistencyFailure` when representative/member positions differ by more than a relative `1e-9` tolerance.

The D4 census shows that downstream accepted assertions observe the resulting `sourcePoint`, `vertexPositions`, `vertexProvenance`, and lineage authority, but none grants the adapter permission to derive placement from A6 `canonicalTransport` / `relationTransport`. RA-17 therefore remains compatible with the observed consumer surface: the later D1 decision must embed from A5 `SourceSupport`, publish a deterministic representation-only representative, and keep A6 placement transport confined to A6 strict-cycle validation.

### 1.5 D4 conclusions binding the remaining R4 decisions

1. D1 cannot remove or silently repurpose existing lineage fields. It may change their producer from the transitional adapter to A7, but every accepted reader in the census must remain satisfiable or receive an explicitly reviewed successor contract.
2. The exact `SourceSupport` incidence certificate must become semantic geometry authority before the epsilon check is removed. Coordinate equality may remain diagnostic only.
3. The A7 representative is an observable representation choice because accepted tests read `sourcePoint`/positions/provenance. Its key must therefore be frozen explicitly rather than treated as an implementation detail.
4. `selectedRelationPaths` and equivalence transport are evidence/lineage projections. D1 must project RA-16 `canonicalRelationValue` into `SelectedRelationStep.appliedTransport`; it must not consume A6 placement transport for geometry.
5. Existing completion and quality hashes are frozen observables. D1/D3 must state exactly which new certificate fields participate in existing hashes and preserve container-order / unused-relation invariance.
6. D2 precedence analysis must use the census rather than only the 55 failure strings: several accepted tests assert legacy names and publication emptiness, so moving a predicate to A5/A7 must preserve the earliest accepted owner-visible failure.

## 2. D1 — A7 representation and certificates — COMPLETE

D1 freezes A7 as a new immutable product. It does **not** make the transitional
`AuthoritativePhaseFrontMeshResult` or `PureQuadVertexLineage` semantic authority.
Those remain compatibility projections of the A7 product until their eventual
retirement.

### 2.1 Product shape and immutable API

The implementation target is semantically equivalent to:

```cpp
struct SourceSupportCertificate {
  SurfaceQuotientClassId quotientClass;
  authority::SourceSupport publishedSupport;
  authority::OccurrenceId representative;
  std::vector<authority::OccurrenceId> members; // semantic order
  bool exactCommonSupport = false;
  bool everyMemberFaceIncident = false;
  bool relationEvidenceSufficient = false;
};

struct SourceAttachedVertex {
  SurfaceQuotientClassId quotientClass; // semantic vertex identity
  authority::SourceSupport support;
  geometry::SurfacePoint sourcePoint;   // representation leaf only
  Eigen::RowVector3d position;          // projection of sourcePoint only

  std::vector<authority::OccurrenceId> sourceOccurrences;
  std::vector<geometry::SourceProjectionChart> sourceCharts;
  std::vector<authority::IsolationSheetId> sourceIsolationSheets;
  std::vector<authority::TopologyRegionId> sourceTopologyRegions;
  std::vector<geometry::PureQuadEquivalenceProvenance> equivalences;
  std::vector<geometry::SelectedRelationPathCertificate> selectedRelationPaths;
};

struct GeometryEmbeddingCertificate {
  std::size_t quotientClassCount = 0;
  std::size_t embeddedVertexCount = 0;
  std::size_t classedCellCount = 0;
  bool exactClassBijection = false;
  bool exactCellTopologyCopy = false;
  bool completeSourceSupport = false;
  bool noPlacementTransportConsumed = false;
};

class SourceAttachedGeometryProduct {
public:
  const SurfaceQuotientProduct &topology() const; // immutable semantic copy/view
  const std::vector<SourceAttachedVertex> &vertices() const;
  const std::vector<SourceSupportCertificate> &support_certificates() const;
  const GeometryEmbeddingCertificate &certificate() const;
};
```

The concrete implementation may avoid storing an owning duplicate of the complete
A6 object, but the semantic contract is the same: A7 publishes exactly one vertex
for every A6 `SurfaceQuotientClassId`, copies every `SurfaceQuotientCell` corner ID
unchanged, and neither creates, unions, splits, renumbers nor drops an A6 class.
The A7 producer receives immutable A0 + A5 + A6 authority. A7 never obtains
semantic input from the partially materialized compatibility mesh.

This is bounded by D4 focused ordinal 7, selector449 rows 73/87/97/250/448 and
rows 86/96/100/102/103: all of those consumers remain satisfiable because the
legacy projection still exposes one position/provenance row per A6 class and the
same complete occurrence/chart/sheet/region/equivalence/path authority.

### 2.2 Exact `SourceSupportCertificate` rule

The semantic support predicate is **typed exact identity**, not geometric
proximity. Let `S(q)` be the support published for A6 quotient class `q` and let
`S(o)` be the immutable A5 `SurfaceOccurrence::support` for member occurrence
`o`. A7 requires:

```text
for every q:
    members(q) is non-empty
    choose S(q) from the representation-only representative (§2.3)
    for every o in members(q):
        require support_kind(S(o)) == support_kind(S(q))
        require S(o) == S(q)
        require point.face(o) is topologically incident to S(q)
    require every cross-sheet member connection is already justified by
            A6-selected A5 wedge/side relation evidence
```

The exact incidence rule for the three support variants is:

| Published support | Exact member-support compatibility | Exact face-incidence predicate |
|---|---|---|
| `SourceVertexSupport{v}` | member support is exactly the same typed vertex `v` | member `sourcePoint.face` contains vertex `v` |
| `SourceEdgeSupport{a,b}` | member support is exactly the same canonical unordered edge `(min(a,b),max(a,b))` | member face contains both edge endpoints |
| `SourceFaceInteriorSupport{f}` | member support is exactly the same canonical source-face topology key `f` | member face canonicalizes exactly to `f` |

Cross-kind coercion is forbidden. In particular, `vertex ⊂ edge ⊂ face` incidence
does not make two occurrence points equal. A vertex support may not be promoted to
an edge/face support and an edge support may not be promoted to a face support to
force a quotient class through A7.

This rule is deliberately stronger than mere simplex-set intersection. It is the
only rule that replaces the `1e-9` check at snapshot lines 6121-6127. A7 does not
compare two member `position` vectors, barycentric vectors, lattice coordinates,
or Euclidean distances to establish semantic compatibility. The already-certified
A5/A6 relation path is the authority that permits the class membership; the common
exact `SourceSupport` proves that all class members attach to the same source
simplex. The member `SurfacePoint` is then only a coordinate representation on an
incident source face.

A floating comparison may be retained temporarily only as a diagnostic receipt.
Its value cannot reject, accept, select a representative, choose a support, alter
lineage or change any certificate bit. This directly satisfies RA-17 §2 and D4
§1.5 items 1-2.

### 2.3 Deterministic representation-only representative

Retain the current key, now explicitly frozen as A7 representation policy:

```text
RepresentativeKey(o) =
  (o.support, o.cornerWedgeBindings, o.id)
representative(q) = min_lex { RepresentativeKey(o) | o in members(q) }
```

All `members(q)` are interpreted in the semantic sorted-member order of
`SurfaceQuotientClassId`; the `min_lex` result therefore cannot depend on source
face row, relation-container order, output row, scheduler order or hash-table
iteration. `support` remains in the key even though §2.2 requires a common support;
that keeps the current representation ordering explicit and avoids an accidental
behavior change during extraction.

The representative supplies only:

- compatibility `sourcePoint` / `vertexProvenance`;
- compatibility `vertexPositions = sourcePoint.position`;
- the representation row from which raw barycentric coordinates are serialized.

It does **not** supply quotient identity, complete chart/sheet/region authority,
relation selection or source support for the class. Those come from the class-wide
A5/A6 projection below. D4 selector449 row 87 therefore remains satisfiable while
row 448's unused-valid-relation invariance is preserved.

### 2.4 Lineage projection

For each A7 vertex/class, project legacy `PureQuadVertexLineage` as follows:

| Legacy field | Frozen A7 source |
|---|---|
| `sourcePoint` | §2.3 representative A5 occurrence point |
| `sourceSupport` | the class `SourceSupportCertificate::publishedSupport`, not an independently resolved float point |
| `sourceOccurrences` | the exact sorted A6 class member set |
| `sourceCharts` | sorted unique union of every member `cornerWedgeBindings[].chart` |
| `sourceIsolationSheets` | sorted unique union of every member `cornerWedgeSheets` (RA-6) |
| `sourceTopologyRegions` | sorted unique union of every member `topologyRegion` |
| `equivalences` | the A6 `SurfaceQuotientClass::equivalences`, semantic order/deduplicated exactly as A6 publishes them |
| `selectedRelationPaths` | sorted unique legacy projections from A6 `QuotientSelectedPathCertificate` rows for this class |
| legacy `quotientClass` ordinal | compatibility row only: the deterministic A7 output-row ordinal; semantic identity remains `SurfaceQuotientClassId` |

For `selectedRelationPaths`, A7 performs no graph search and no transport
composition. A6 already owns the selected forest/path. Every projected
`SelectedRelationStep.appliedTransport` must therefore be the A6 legacy projection
whose step was validated against A5 `canonicalRelationValue` under RA-16 §3.
A7 must never substitute `QuotientRelationCertificate::relationTransport` or A5
`canonicalTransport`.

The complete binding tuples and ordered isolation transitions remain certificate
evidence. The legacy chart/sheet/region vectors are derived projections after the
complete tuples are validated, not independent sets that can be cross-producted.
This retains focused ordinal 7 and selector449 rows 96/100/102/103.

### 2.5 Normative transport guard

The RA-17 transport guard is an A7 construction invariant:

```text
consumers(A6 canonicalTransport / relationTransport) == { A6 strict-cycle rule }
```

A7, its compatibility adapter, lineage projection, chart re-anchoring, representative
selection, source-point selection, position publication, completion input and hash
projection are forbidden consumers. A7 reads only A6 membership/cell topology,
relation/equivalence evidence, selected-path legacy projections, and exact A5
source-support/binding authority.

The three gauge questions intentionally carried to `M6-DEFN-R5` therefore cannot
alter CP1 A7 geometry: unequal-face-gauge exact-A3 periodic validation, HardRail
cross-region branch certification, and OrdinaryFront coordinate identity across
isolation seams remain outside this product boundary.

### 2.6 A7 typed failures and transitional legacy mapping

Freeze the following semantic A7 failure classes. A concrete enum may use these
names or a mechanically equivalent typed spelling, but one semantic cause may not
collapse into an unrelated generic code:

| A7 typed cause | Required locus/site distinction | Transitional compatibility behavior |
|---|---|---|
| `MissingSourceSupport` | quotient class + occurrence | fail closed; no output vertex |
| `SourceSupportKindMismatch` | class + first mismatching occurrence | replaces cross-kind/ambiguous support acceptance |
| `SourceSupportIdentityMismatch` | class + occurrence | authoritative replacement for the old position-consistency predicate |
| `SourceSupportFaceIncidenceMismatch` | class + occurrence + source face | exact A0 incidence failed |
| `SourceSupportRelationEvidenceMismatch` | class + relation/occurrence pair | required wedge/side certification absent or incompatible |
| `CrossComponentBinding` | class + binding | complete binding tuples cross source components |
| `UncertifiedCrossSheetBinding` | class + binding/transition | sheet crossing lacks certified A5/A6 evidence |
| `MissingQuotientVertexEmbedding` | class | no A7 vertex for an A6 class |
| `DuplicateQuotientVertexEmbedding` | class | more than one A7 vertex for an A6 class |
| `NonFiniteEmbeddedGeometry` | class + representative | representation coordinate is non-finite |
| `TopologyMutation` | cell/class locus | A7 topology differs from immutable A6 topology |
| `MaterializedMeshInvalid` | named sub-site from D2(c) | transitional CP1 owner for mesh-level validity until A8 independently recomputes it |

Where one typed code has several checks, the diagnostic suffix is a stable semantic
site token (for example `:support-kind`, `:support-identity`, `:support-face`,
`:class-bijection`, `:cell-topology`, `:quad-orientation`, `:edge-incidence`,
`:boundary-loop`, `:vertex-fan`). It is not a source line number or output row.

No required-green D4 geometry/lineage assertion directly pins the legacy string
`QuotientGeometryConsistencyFailure`. Therefore the A7 typed cause is authority.
During the transitional adapter, that old name may be emitted only as a compatibility
diagnostic if a still-frozen caller requires it; it is not permitted to restore the
old floating predicate. D2 separately records every actually pinned adapter name and
its precedence.

### 2.7 Hash and `BenchmarkQuality` disposition

R4 adds **no A7 certificate field to the existing `hash_completion` or
`BenchmarkQuality` path hashes**. Those hashes remain compatibility/output hashes
and continue to observe the legacy projected geometry/lineage fields they already
consume. A7 certificate metadata is compared structurally by focused tests; no new
hash is semantic identity.

Consequently:

- the same A7 semantic product under source-row, relation-container or scheduler
  permutation must project the same existing completion hashes;
- unused valid relation evidence that does not enter the selected A6 forest remains
  inert (selector449 rows 436/437/448/449);
- the representative rule is deterministic, so row 241 and row 250 determinism stay
  satisfiable;
- no future implementation may make a digest the equality key for an occurrence,
  quotient class or A7 vertex.

### 2.8 D1 verification obligations for the first A7 CB

D1 is definition-complete only because the implementation proof is explicitly
pre-registered rather than assumed. `M6-CP1-CB9-A7` must add focused identities that
prove at minimum:

1. exact common vertex-, edge- and face-interior support acceptance;
2. one mismatch case for each support kind plus one cross-kind mismatch, all failing
   the typed support gate before any floating diagnostic;
3. deterministic representative selection under occurrence/source-row permutation;
4. complete chart/sheet/region/equivalence/selected-path projection;
5. a transport-guard test that would fail if A7 reads `canonicalTransport` or
   `relationTransport` for geometry/lineage;
6. topology copy and one-embedding-per-A6-class certificate checks;
7. the mandated `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` identity.

The gate size and exact test identities are frozen in D5; this subsection fixes the
properties D5 must cover, not the final names/count by itself.

## 3. D2 — thin-adapter 55-site classification and precedence — COMPLETE

### 3.1 Checkable thin predicate

After CP1 thinning, `build_authoritative_phase_front_mesh` is permitted to do only:

```text
1. invoke A5, A6 and A7 producers in order;
2. map an already-produced typed A5/A6/A7 error to a compatibility diagnostic;
3. serialize/project immutable A7 topology, vertices, lineage and counters into
   AuthoritativePhaseFrontMeshResult / PureQuadMesh;
4. compute representation-only row maps needed for that serialization.
```

It is forbidden to perform any semantic predicate, topology choice, quotient
selection, representative selection, support selection, source-chart decision,
floating equality/tolerance check, relation search, weld, manifold repair or
failure-precedence preflight. In particular the lambdas at snapshot 5584-5599 and
the `1e-9` comparison at 6121-6127 cannot survive as adapter authority.

The only accepted adapter-side conditions after thinning are mechanical bounds or
construction failures intrinsic to serialization itself; such a failure is a
projection failure, not a substitute semantic validator. A semantic condition that
can make a previously valid stage product fail belongs to A5/A6/A7 (or later A8),
not the adapter.

### 3.2 Complete 55 literal-site census

The table below classifies the exact **55 direct literal assignments** in
`build_authoritative_phase_front_mesh` at the D4 snapshot. Categories are exactly
the R4 plan's `(a)`–`(d)` owners.

| Line | Current literal | Owner | Required move / retained behavior | Frozen precedence |
|---:|---|---|---|---|
| 5554 | `MissingAuthoritativePhaseFront` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5560 | `InvalidAuthoritativePhaseFrontSource` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5580 | `InvalidAuthoritativeSourceChartTransitions` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5611 | `AuthoritativeTopologyRegionMapMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5618 | `InvalidAuthoritativeTopologyRegion` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5625 | `AuthoritativeTopologyRegionMapMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5633 | `AuthoritativeTopologyRegionMapMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5660 | `InvalidAuthoritativeSourceEdgeTransition` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5704 | `InvalidAuthoritativeTopologyRegionIsolationAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5736 | `InvalidAuthoritativeIsolationSeamCertificate` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5745 | `InvalidAuthoritativeIsolationSeamCertificate` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5774 | `IsolationSeamCertificateSourceAuthorityMismatch` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5782 | `IsolationSeamCertificateBijectionMismatch` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5789 | `IsolationSeamCertificateBijectionMismatch` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5826 | `DisconnectedAuthoritativeIsolationSheetGraph` | (a) A5 | A5 validates isolation-seam certificate/source/sheet authority before occurrence publication. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5857 | `InvalidAuthoritativePhaseFrontCell` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5867 | `IncompleteAuthoritativeTopologyRegionConsumption` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5883 | `InvalidAuthoritativePhaseFrontOwnership` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5905 | `InvalidAuthoritativePhaseFrontSideAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5915 | `InvalidAuthoritativeTransitionSourceEdge` | (a) A5 | Move transition-ID/source-edge authority validation into A5 input certification. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5926 | `InvalidAuthoritativeTransitionSourceEdge` | (a) A5 | Move transition-ID/source-edge authority validation into A5 input certification. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5939 | `IsolationSeamTransitionOwnerMismatch` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5950 | `InvalidAuthoritativePhaseFrontOwnership` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5957 | `InvalidOrdinaryFrontRelation` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5964 | `InvalidSourceBoundaryAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5977 | `FalseAuthoritativeSourceBoundary` | (a) A5 | Move exact source-boundary topology predicate to A5; preserve frozen legacy name at adapter. | selector449 row 212 `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected` pins `FalseAuthoritativeSourceBoundary` |
| 5986 | `InvalidHardRailAuthority` | (a) A5 | Move/reuse exact route predicate in A5; adapter maps the A5 typed error only. | selector449 rows 227/230 pin `InvalidHardRailAuthority` and RA-15 route-before-pair precedence |
| 5991 | `UnsupportedEmbeddedReliefCut` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 5996 | `InvalidPeriodicCutAuthority` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6004 | `IncompleteAuthoritativePhaseFrontSides` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6010 | `IncompleteAuthoritativePhaseFrontSides` | (a) A5 | A5 owns this A4/phase-front authority predicate before A6 construction. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6023 | `QuotientUnknownFailure` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6036 | `QuotientReciprocalSideAuthorityMismatch` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6039 | `InvalidHardRailTransport` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | selector449 rows 139/140/142 pin public `InvalidHardRailTransport`; valid individual routes must reach pair/transport validation before A6 projection |
| 6042 | `InvalidPeriodicFrontTransport` | (b) A6 projection | No re-evaluation: translate the already-produced A6 typed error to the frozen compatibility diagnostic. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6100 | `QuotientInvalidClassPartition` | (c) A7 embedding certificate | A7 certifies one-to-one A6 class/cell embedding and topology copy; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6126 | `QuotientGeometryConsistencyFailure` | (c) A7 support certificate | Delete the floating `1e-9` semantic predicate; A7 exact `SourceSupportCertificate` owns compatibility. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6168 | `InvalidAuthoritativeQuotientClassId` | (d) projection | Serialize deterministic compatibility quotient ordinal from the A7 vertex row; no semantic validation. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6215 | `QuotientNonBijectiveMaterialization` | (c) A7 embedding certificate | A7 certifies one-to-one A6 class/cell embedding and topology copy; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6223 | `QuotientMissingOccurrenceMember` | (c) A7 embedding certificate | A7 certifies one-to-one A6 class/cell embedding and topology copy; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6238 | `DegenerateAuthoritativePhaseFrontQuad` | (c) A7 embedding certificate | A7 certifies classed-quad materialization/geometry; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6248 | `InvertedAuthoritativePhaseFrontQuad` | (c) A7 embedding certificate | A7 certifies classed-quad materialization/geometry; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6254 | `DuplicateAuthoritativePhaseFrontQuad` | (c) A7 embedding certificate | A7 certifies classed-quad materialization/geometry; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6296 | `CollapsedAuthoritativeMeshEdge` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6312 | `NonManifoldAuthoritativeMeshEdge` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6321 | `UnjustifiedAuthoritativeMeshBoundary` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6335 | `AuthoritativeMeshEdgeRelationMismatch` | (c) A7 embedding certificate | A7 certifies materialized edge incidence/relation/boundary consistency; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6370 | `NonManifoldAuthoritativeBoundaryVertex` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6375 | `OpenAuthoritativeBoundary` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6386 | `InvalidAuthoritativeBoundaryLoop` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6392 | `InvalidAuthoritativeBoundaryLoop` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6397 | `DegenerateAuthoritativeBoundaryLoop` | (c) A7 embedding certificate | A7 certifies boundary incidence/closed-loop materialization; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6445 | `UnreferencedAuthoritativeVertex` | (c) A7 embedding certificate | A7 certifies vertex reference/fan manifoldness; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6463 | `DisconnectedAuthoritativeVertexFan` | (c) A7 embedding certificate | A7 certifies vertex reference/fan manifoldness; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |
| 6490 | `NonManifoldAuthoritativeVertexFan` | (c) A7 embedding certificate | A7 certifies vertex reference/fan manifoldness; A8 later recomputes independently. | no required-green test pins this literal; preserve stage order A5 → A6 → A7 and publication emptiness |

Category totals are **31 (a) + 4 (b) + 19 (c) + 1 (d) = 55**. This is a total
partition; no site is left jointly owned by the adapter and a semantic producer.

### 3.3 Non-literal failure assignments in the same function

The plan's number 55 counts direct literal assignments, but thinning must also
remove ambiguity from the neighboring dynamic assignments:

- `5642-5644`: `MissingAuthoritativeTopologyRegions` / map mismatch is category
  **(a)** and moves to A5 with the other region-map predicates.
- `5838-5841`: `SurfaceOccurrenceComplexError` → legacy name is **(d)** pure A5
  error projection; it remains a mapping only and performs no predicate.
- `6028-6033`: the two A6 isolation-evidence legacy names are category **(b)**.
- `6045-6056`: `HolonomyConflict` / default A6 names are category **(b)**;
  `6048-6052` may append the already-produced residual as diagnostic payload but
  may not recompute it.

Thus the complete adapter failure surface after the cutover is typed producer-error
projection plus serialization failure only.

### 3.4 Failure precedence

Precedence is frozen by **stage**, not by the old source-line order:

```text
A5 validation / A5 typed error
  before A6 construction
A6 typed error
  before A7 construction
A7 typed error / embedding certificate
  before compatibility serialization
```

This preserves every required-green direct string pin found by D4/source audit:

1. selector449 row **212** keeps `FalseAuthoritativeSourceBoundary`; the predicate
   moves to A5 but the adapter maps that A5 code back to the same string.
2. selector449 rows **227/230** keep `InvalidHardRailAuthority`. RA-15 remains
   stronger than line order: the shared exact individual route validator executes
   in A5 before pair-level owner/region/reversed-route/transport validation.
3. selector449 rows **139/140/142** keep `InvalidHardRailTransport`. Only
   individually valid routes reach the pair/transport checks; an A6 error carrying
   the corresponding typed cause maps to the same public string.

No other one of the 55 literal names is asserted by the accepted selector449 or
focused-12 lists. For those sites, the frozen contract is still fail-closed and
publication-empty behavior, but not the historical spelling. Moving an `(a)` check
earlier into A5 cannot be pre-empted by A6/A7; moving a `(c)` check into A7 cannot
pre-empt an A5/A6 error. This explicitly avoids the RA-15 validation-order
shadowing recurrence.

### 3.5 A7 versus future A8 ownership

The 19 category-(c) checks become **producer certificates in A7 for CP1** because
A8 does not exist yet. CP2's `SurfaceProductVerifier` must later independently
recompute the §6.2 elementary incidence/manifold/boundary facts from immutable
A0/A5/A6/A7 products. At that point A7's certificate remains producer evidence and
A8's recomputation is verification; the checks are not moved back into the adapter.

The D4 frozen geometry/lineage readers therefore continue to see either a complete
A7 projection or no publication at all. No semantic failure can occur after a
partial legacy mesh has been published.

## 4. D3 — `G4-B002` A6 stage boundary — COMPLETE

### 4.1 Boundary product and ownership

Freeze a new immutable **A6-owned projection**, `SurfaceQuotientClosedComplexView`.
It is produced by `SurfaceQuotientProducer` from the same immutable A5 occurrence
complex used to build `SurfaceQuotientProduct`; it is stored in / returned with the
A6 product and is not reconstructed from `SurfaceCellPipelineContext::arrangement`.
It contains only topology/protection/lineage facts needed by closed-complex candidate
extraction:

```cpp
struct SurfaceQuotientSideId {
  authority::CellId cell;
  std::uint8_t side; // canonical corner side 0..3
  auto operator<=>(const SurfaceQuotientSideId &) const = default;
};

struct SurfaceQuotientEdgeId {
  std::vector<SurfaceQuotientSideId> incidentSides; // sorted; 1 boundary, 2 closed
  auto operator<=>(const SurfaceQuotientEdgeId &) const = default;
};

enum class SurfaceQuotientEdgeProtection : std::uint8_t {
  Ordinary = 0,
  HardRail = 1,
  Periodic = 2,
};

struct SurfaceQuotientBoundaryEdge {
  SurfaceQuotientEdgeId id;
  SurfaceQuotientClassId first;
  SurfaceQuotientClassId second;
  SurfaceQuotientEdgeProtection protection;
  std::optional<authority::HardRailId> hardRail;
  std::optional<authority::PeriodicRelationId> periodicRelation;
  std::vector<SurfaceOccurrenceRelationId> evidence; // semantic sorted evidence
  std::uint32_t stripOrdinal; // representation-only, §4.3
};

struct SurfaceQuotientClosedComplexView {
  std::vector<SurfaceQuotientClassId> vertices; // lexicographic class order
  std::vector<SurfaceQuotientCell> quads;       // A6 classed-cell order
  std::vector<SurfaceQuotientBoundaryEdge> edges;
  bool closed = false;
  bool edgeIncidenceBijection = false;
  bool protectionLabelsCertified = false;
};
```

`SurfaceQuotientEdgeId` is side-incidence identity rather than an endpoint pair so
parallel quotient edges cannot collapse. Every `SurfaceQuotientCell` contributes
four `SurfaceQuotientSideId`s. A closed view requires every side to belong to
exactly one two-sided edge and requires the two incident sides to have reversed
quotient-class endpoints. A source-boundary one-sided edge is representable for
future use, but **the `G4-B002` CP1 proof accepts only `closed=true`**.

Vertex lineage at this boundary is exactly `SurfaceQuotientClassId::members`.
No A7 point, coordinate, output-row ordinal, hash or representative participates.
This satisfies the D4 lineage consumers by keeping the boundary semantic identity
on the same A6 member-set authority; A7 remains the later geometry projection.

### 4.2 Rail / periodic edge-label derivation

Protection labels are derived while A6 still has immutable A5 side/relation
authority; the adapter does not infer them from geometry.

For a quotient edge with incident sides `s0` and `s1`, compare the two directed
corner-occurrence pairs from the corresponding A5 `SurfaceOccurrenceCell`s.
A non-ordinary label is valid only when **both endpoint pairings** are certified by
A6 `QuotientRelationCertificate`s of the same relation kind and the same owner:

- two `HardRail` endpoint relations with one identical `HardRailId` -> `HardRail`;
- two `Periodic` endpoint relations with one identical `PeriodicRelationId` ->
  `Periodic`;
- otherwise, if the sides are reciprocal under A5 ordinary-front authority ->
  `Ordinary`.

A one-endpoint label, mixed kinds, different owners, non-reciprocal side pairing,
or a label that cannot be reconciled with the A5 directed-side authority is an A6
boundary-construction failure. It is never silently downgraded to `Ordinary`.
`HardRail` is protected for candidate extraction. `Periodic` is a quotient seam
label, **not** a geometric boundary and not automatically a hard feature.

The existing A6 relation certificate remains the evidence owner. The boundary view
stores relation IDs only to make the protection proof independently inspectable;
it does not compose or consume `relationTransport`. RA-17 therefore remains intact.

### 4.3 Candidate-extraction compatibility projection

The new candidate-extraction entry point consumes the A6 boundary view directly (or
a mechanically equivalent read-only adapter), never
`SurfaceCellPipelineContext::hasArrangement`. Its graph quantities are derived only
from the boundary product:

1. nodes are `SurfaceQuotientClassId`s in lexicographic order;
2. faces are the four class IDs of every `SurfaceQuotientCell`;
3. edges are the exact `SurfaceQuotientEdgeId`s from §4.1;
4. `HardRail` maps to `touchesHardFeature=true`; `Periodic` remains an interior
   quotient edge with its periodic owner retained;
5. boundary is determined from side incidence, not `family < 0`;
6. singularity is a combinatorial quotient valence fact, not an arrangement flag;
7. strip identity is the transitive closure of the **opposite-edge relation in
   quotient quads**. Each strip is represented by the lexicographically smallest
   `SurfaceQuotientEdgeId` in the closure, then assigned a deterministic ordinal.

This replaces the old candidate extractor's arrangement `family/strand` grouping at
this stage with a topology-derived strip grouping. `family`/`strand`, source arc,
proposal ID, arrangement node coordinates and `sourceT0/sourceT1` are explicitly not
A6 boundary authority. A compatibility `SurfaceCellComplex` may be synthesized for
migration, but if used it must be a lossless serialization of the seven rules above;
it cannot read the retained arrangement to fill missing fields.

### 4.4 CP1 equivalence demonstration

The named fixture is the existing **produced closed torus** fixture used by
`M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`:
`milestone-g/torus.obj` + `milestone-g/torus.rawfield`, with the same 18 committed
HardRail edges and fail-closed `SurfaceCells` options.

CB11 must expose the A6 boundary view from that produced run and compare it with the
existing retained closed-complex authority only as a **migration oracle**. The
required equivalence is a deterministic labeled combinatorial isomorphism:

- one bijection between A6 quotient classes and comparison vertices, keyed by the
  sorted occurrence-member set rather than positions;
- one bijection between A6 classed quads and comparison quads preserving cyclic or
  reversed four-corner incidence;
- one bijection between canonical edge-side incidence IDs preserving the two
  incident quads;
- exact equality of `HardRailId` and `PeriodicRelationId` labels on corresponding
  protected / periodic edges;
- exact equality of each vertex's sorted occurrence-member lineage;
- no coordinate/epsilon predicate and no hash equality may establish the bijection.

The comparison-side adapter may read the retained arrangement **only inside this
focused equivalence test**. Production candidate extraction must use the A6 boundary
view without consulting `hasArrangement`.

The independent oracle is the existing
`independently_check_candidate_eligibility(...)` logic from
`SurfaceComplexSimplificationPhase17Tests.cpp`, re-expressed over the labeled
quotient boundary rather than copied from candidate-extractor internals. It checks
canonical twin/edge ownership, absence of protected support, side feasibility,
source-scope/lineage consistency and open-path/closed-loop degree. CB11 must show at
least one boundary candidate is independently eligible and that marking one of its
edges `HardRail` makes that exact candidate ineligible and absent. This CP1 tamper
checks the **mechanism / label propagation only**.

### 4.5 Debt boundary and frozen assertions

The CP1 result does **not** close `G4-B002`. M6-CP3 retains the unchanged debt:
fail-closed direct production, recovery/fallback disabled, closed source,
independently validated candidate eligibility and discriminating hard-feature
tamper after A5-A8 are complete. CP1 may use the retained arrangement only for the
§4.4 equivalence comparison; CP3 must re-prove the oracle on direct production.

D4 constraints remain satisfiable:

- the boundary uses class member sets, so no A7 representative or legacy output row
  can perturb semantic vertex identity;
- no new boundary field enters `hash_completion` or `BenchmarkQuality` hashes;
- HardRail / Periodic owner labels are copied from already-certified A5/A6 relation
  authority and do not consume placement transport;
- no source-row, relation-container or scheduler order participates in side, edge,
  strip or lineage identity.

## 5. D5 — bounded Code + Build / TB / Review sequencing — COMPLETE

R4 itself authorizes **no implementation**. If and only if `M6-DEFN-R4-REV`
accepts this definition, the following sequence is frozen. Every Code + Build turn
is compile/package only; every runtime gate is a separate immutable artifact-only
TB followed by mandatory Review. Selector449 and the focused-12 prefix remain
byte-frozen.

### 5.1 CB9 — `M6-CP1-CB9-A7`

Scope: implement D1 A7 plus category-(c)/(d) adapter thinning. Append these eight
focused identities after the frozen focused 1-12, in this exact order:

13. `M6CP1.A7PublishesOneEmbeddedVertexPerA6Class`
14. `M6CP1.A7ExactSourceSupportAcceptsVertexEdgeAndFaceInteriorClasses`
15. `M6CP1.A7RejectsSupportKindAndIdentityMismatchesBeforeFloatingDiagnostics`
16. `M6CP1.A7RepresentativeIsInvariantToOccurrenceAndSourceRowOrder`
17. `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues`
18. `M6CP1.A7NeverConsumesPlacementTransportForGeometryOrLineage`
19. `M6CP1.A7CopiesA6TopologyWithoutClassMutation`
20. `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`

The eighth identity must execute the real
`validate_materialized_completion_domain_ownership` production-completion owner
check and require an empty failure string; a replica comparator receives no credit.

Gate after compile-green CB9: **focused 1-20 + selector449 = 469 fresh exact-filter
processes**, exact-one selection, zero skips, benchmark 0, immutable postflight.
Turn sequence: `M6-CP1-CB9-A7` -> `M6-CP1-TB9-A7-EXEC` -> mandatory
`M6-CP1-TB9-A7-REV`.

### 5.2 CB10 — `M6-CP1-CB10-A5V`

Scope: move only D2 category-(a) semantic predicates into A5 and remove their
adapter copies. Category-(b) remains error projection; already-extracted A7 remains
unchanged. Append four identities, preserving focused 1-20 as an exact prefix:

21. `M6CP1.A5OwnsPhaseFrontRegionAndBoundaryValidationBeforeA6`
22. `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames`
23. `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport`
24. `M6CP1.ThinAdapterPerformsNoSemanticValidationOrSelection`

The fourth is a structural/source-level contract test over the adapter call surface;
it must fail if a semantic predicate, representative/support selection, relation
search or tolerance check is reintroduced.

Gate after compile-green CB10: **focused 1-24 + selector449 = 473 fresh processes**
under the same exact-one/zero-skip/benchmark-0/immutable-postflight rules.
Sequence: `M6-CP1-CB10-A5V` -> `M6-CP1-TB10-A5V-EXEC` -> mandatory
`M6-CP1-TB10-A5V-REV`.

### 5.3 CB11 — `M6-CP1-CB11-G4`

Scope: implement only D3's A6 closed-complex boundary and candidate-extraction
adapter. Append four identities, preserving focused 1-24 as an exact prefix:

25. `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`
26. `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels`
27. `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage`
28. `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle`

Identity 28 includes the mechanism-only HardRail tamper described in §4.4 but must
state explicitly that it does not discharge the CP3 direct-production debt.

Gate after compile-green CB11: **focused 1-28 + selector449 = 477 fresh processes**
with the same immutable rules. Sequence: `M6-CP1-CB11-G4` ->
`M6-CP1-TB11-G4-EXEC` -> mandatory `M6-CP1-TB11-G4-REV`.

After TB11 Review, a separate **`M6-CP1-CLOSE-REV`** checks all six frozen CP1 exit
items against exact source and the fresh 477-process gate. It may close CP1 only if
A5/A6/A7 are behind immutable stage APIs, the adapter satisfies §3.1, there is no
position weld, focused multi-isolation remains green, and candidate extraction no
longer depends on `hasArrangement`. `M6-DEFN-R5` remains a CP3-entry gate and is not
pulled into CP1 closure.

### 5.4 Gate-file rule

CB9/10/11 create successor focused-list files of 20, 24 and 28 identities
respectively. Each file must preserve
`Architecture_M6_CP1_Required_Green_Focused_12.txt` byte-for-byte as its first 12
lines and preserve the preceding successor list as an exact prefix. A Code + Build
report records each new list's SHA-256 before its TB. Neither selector449 nor the
original focused-12 file is edited.

## 6. Carried R5 obligations

Unchanged and not decided here: unequal-face-gauge exact-A3 periodic witness/rule,
HardRail cross-region branch certification, and OrdinaryFront coordinate identity
or isolation-seam transition across isolation seams. Owner remains `M6-DEFN-R5`.
The D1 transport guard expressly keeps all three out of CP1 A7 geometry and D3
closed-complex boundary construction.

## 7. R4 disposition

D1-D5 are definition-complete and runtime-free. Stable accounting remains
**60 / 16 / 44**, debt **1**. No source, test, fixture, selector or build/runtime
implementation is authorized by this record. Exact successor is mandatory
`M6-DEFN-R4-REV`; only that independent Review may accept/reject/amend R4 and
release `M6-CP1-CB9-A7`.
