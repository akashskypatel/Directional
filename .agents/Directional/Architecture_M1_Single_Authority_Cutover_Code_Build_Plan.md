# M1 Single-Authority Cutover — Code + Build Plan

**Turn type:** Code + Build only  
**Current status:** R-A-REV-01 through R-A-REV-10 are compile-closed for their reviewed paths at `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e`; R-A remains open pending the complete closure inventory, R-B through R-G, and one fresh full self-verifying package
**Original planning decision:** prior narrow M1m plan rejected and replaced  
**Reviewed source authority:** M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Review/planning baseline:** `fcba2fd9b8905802ca373e0cc88aeccbf38d608a`  
**Latest closure-review branch head:** `f81f40524f9ee6978e4e298497d4d54580520cf3`
**Exact reviewed implementation source:** `c62c99ffe5b7863820c91f4ff3a93645b22d3591`
**Latest review-remediation source:** `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e`
**Product gate after acceptance:** resume G4 topology-distinct completion and singularities  
**Review policy after the following Test + Benchmark turn:** `never`

## 0AA. 2026-08-12 R-A-REV-07-through-10 review-remediation checkpoint

This partial Code + Build checkpoint closes the four named findings for their reviewed paths without declaring R-A or M1 complete.

### Changes

- **R-A-REV-07:** completion no longer publishes exact-boundary stitch authority from an empty-source compatibility branch. `resolved_stitch_identity` requires valid separately derived typed lineage before considering an exact arrangement-boundary identity, and authoritative resolution no longer falls back to exact-only identity. Exact-only assembly rejects with `MissingTypedStitchIdentity`; typed positive and exact-only negative contracts are compile-visible.
- **R-A-REV-08:** removed the public optional `requireSourceAuthoritativeValidation` bypass. SurfaceCells production uses dedicated source-authoritative optimizer/final-validator entry points that fail closed with `MissingSourceAuthority` on missing/incomplete authority. Generic validation is isolated for non-SurfaceCells use and no longer compares raw `SurfacePoint::component/sheet` as sheet authority.
- **R-A-REV-09:** multi-component isolation-sheet extent/offset is computed from complete typed vertex lineage, not `sourceSurfaceLabels.localSheetByFace` or `SurfacePoint::sheet`. Incomplete typed coverage fails with `MissingTypedComponentIsolationSheetAuthority`; typed sheet remap precedes one-way raw projection/export. A compiled helper contract verifies raw-label tampering cannot change typed extent and missing typed support invalidates it.
- **R-A-REV-10:** replaced the previous focused/name-only evidence with an affected-path audit that inventories public headers/declarations, completion/assembly, optimizer/verifier modes, generic validation boundaries, component aggregation, and raw component/sheet reads. The audit inspects semantic contract bodies and permits raw labels only in classified one-way assignment/export leaves.

### Compile-only evidence

- Exact implementation source: `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e` (`10 files changed, 421 insertions, 102 deletions`).
- Run/job `31565756309 / 94017095695` completed Release/static/Ninja/PRE_TEST **118/118** with build exit `0`.
- Result artifact `9129549875`, outer SHA-256 `34f9d4a576ddfd79c2c35997ac95bdd91a0b549ac1bf519bc38a11d36d0559e5`; log artifact `9129550069`, outer SHA-256 `65fe62a061ab090f4929477997b28527d9511816e8c0518a136dac3604941bb0`.
- Independent artifact inspection verified exact source `d8d648a...`, a self-excluding recursive manifest **20/20**, zero self references, and five empty source-status snapshots.
- The source audit reports `R-A-REV-07 source/contract audit: closed`, `R-A-REV-08 source/contract audit: closed`, `R-A-REV-09 source/contract audit: closed`, and `R-A-REV-10 complete affected-path inventory: clean`.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. Compiled contracts were not run.

### Remaining gate

This artifact is partial and ineligible for M1 acceptance. Before advancing the cutover, rerun the complete R-A closure inventory below over all affected producers/consumers. Only a statically clean complete inventory may mark R-A complete; R-B through R-G and one fresh full R-A-through-R-G package remain mandatory.

## 0A. 2026-08-12 complete R-A closure-gate review — rejected

This section controls wherever it conflicts with older remediation text. Historical checkpoints remain in `CHANGELOG.md`; they are not live tasks here.

### Verified boundary and evidence

- The Review inspected PR #8 through branch head `f81f40524f9ee6978e4e298497d4d54580520cf3`. No implementation or test source changed after `c62c99ffe5b7863820c91f4ff3a93645b22d3591`, so that commit is the exact reviewed source.
- The packaged source snapshot from run/job `31561686903 / 94005144300` is byte-identical to a clean `c62c99f...` worktree. Release/static/Ninja/PRE_TEST compiled **118/118** with build exit `0`.
- Result artifact `9127976318` and log artifact `9127976660` independently match outer SHA-256 values `f7bcf34579664f19cd5a73fd384b5ff020304c7b10a89c81ce35a89a92b38588` and `3f4c5eef39aedbb06666edf3b09e5f2e5071209ba88a3d9ef0f9174083bd536a`.
- The result's self-excluding manifest verifies **22/22** and all five recorded source-status snapshots are empty. R-A-REV-06 is therefore verified for these packaging mechanics. Artifact `9127976318` remains a partial checkpoint, not an M1 acceptance candidate.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. Compiled test source and test-name presence are not semantic acceptance.
- The focused `m1-ra-rev-03-06-audit.py` checks selected blocks and names only. It does not inspect the generic validator header, the public optimizer bypass, exact-only boundary lineage, or top-level component aggregation; its printed REV-03/04/05 closure labels do not establish the complete gate.

### R-A-REV-07 — exact boundary identity bypasses complete typed lineage

Evidence: `validate_completion_domain_ownership` publishes exact boundary identities and continues when `sourceFaces` is empty. `resolved_stitch_identity` returns an exact boundary identity before requiring the separately derived typed identity to be valid, and `resolved_authoritative_identity` can return that resolved identity when typed authority is absent. `PrebuiltBoundaryStitchIdentityMustMatchExactAuthority` positively completes a patch with no source faces or typed source authority.

Corrective measure: require complete typed topology-region, isolation-sheet, chart, and support lineage for every published completion vertex. An exact arrangement identity is a stitch key only after validation against that separate typed owner/lineage. Delete the empty-source compatibility publication, reject exact-only lineage with `MissingTypedStitchIdentity`, and convert standalone fixtures to typed positive or explicit missing-authority negative contracts.

### R-A-REV-08 — optimizer/verifier retains a non-authoritative SurfaceCells path

Evidence: `SurfaceOptimizationConstraints::requireSourceAuthoritativeValidation` defaults false; `source_authoritative_hard_invariants_valid` returns true immediately in that state; and final validation falls back to generic `MeshValidator`. Its `same_source_sheet` helper compares raw `SurfacePoint::component/sheet` to decide geometric T-junction compatibility. The optimizer also retains an explicitly named point-cloud fallback for legacy standalone fixtures.

Corrective measure: make typed source authority mandatory for every SurfaceCells optimization and validation path. Missing authority must fail closed; generic point-cloud behavior, if retained for a non-SurfaceCells API, must be isolated so it cannot produce or validate SurfaceCells output. Remove raw provenance from sheet decisions and replace legacy fixtures with typed contracts or missing-authority negatives.

### R-A-REV-09 — component aggregation derives typed sheet offsets from raw projections

Evidence: `remesh_surface_cell_components_from_cross_field` computes `localMaximumSheet` from `sourceSurfaceLabels.localSheetByFace` and remapped `SurfacePoint::sheet`, then uses the resulting `sheetOffset` to remap typed `IsolationSheetId` lineage. Raw diagnostic/projection labels therefore determine typed sheet identity in the production multi-component merge.

Corrective measure: compute component sheet extent from `SourceTopologyRegions` or complete typed lineage, fail on incomplete typed coverage, remap typed `IsolationSheetId` first, and derive raw projection/export sheet values one way afterward. Add a multi-component raw-label-tamper invariance contract over the merged typed lineage and output semantics.

### R-A-REV-10 — the focused audit and compiled contracts cannot detect REV-07 through REV-09

Evidence: the script scans only selected `.cpp` blocks and test-name strings. It misses `MeshValidator.h`, the public validation flag, the top-level component merge, and exact-only completion semantics. The new raw-tamper test covers one typed patch, while the prebuilt-boundary test depends positively on exact-only completion.

Corrective measure: replace the focused script with a complete affected-path inventory covering declarations, headers, all completion/assembly paths, all optimizer/verifier modes, and component aggregation. Audit every raw component/sheet read and allow only one-way assignment/export leaves. Add semantic contracts for REV-07 through REV-09; name presence is not evidence.

### Updated execution decision

The next Code + Build continuation must:

1. retain the valid R-A-REV-01-through-10 typed-authority work and verified packaging rules;
2. rerun the complete R-A inventory below and call R-A complete only when every item is statically clean;
3. complete R-B through R-G in the same vertical cutover;
4. produce one fresh full R-A-through-R-G self-verifying package without generated runtime execution, then hand only that package to the retained artifact-only plan.

### R-A closure gate

Before work may be called R-A-complete, a complete static inventory and compiled contract review must demonstrate:

- every affected occurrence and completion lineage carries required typed topology region, sheet, chart, and support;
- no affected materializer, completion, patch, lineage, arrangement-ownership, verifier, optimizer, rail, or component-aggregation decision reads `SurfacePoint` component/sheet as authority;
- no fallback canonical/stitch/ownership key stores raw component/sheet;
- every exact boundary identity is validated against separate complete typed lineage; no exact-only or standalone compatibility publication survives;
- every SurfaceCells optimizer/verifier entry point requires typed source authority and fails closed when it is missing;
- multi-component sheet extents and offsets derive only from typed authority; raw labels are one-way diagnostic/export payload;
- raw classifier arrays exist only at source-authority builder ingress, and `build_authoritative_phase_front_mesh` accepts no parallel raw authority;
- the audit covers declarations, headers, implementation modes, and top-level aggregation, and classifies every raw component/sheet read;
- compiled positive, missing-authority, distinct-sheet, exact-only, alternate-validator-path, raw-tamper, and multi-component-tamper contracts would fail if a bypass returned;
- the full package has clean source provenance and a self-excluding checksum manifest that verifies before upload.

## 0. Independent review amendment — remediation required

**Review date:** 2026-08-11 UTC  
**Explicit review authority:** user-requested independent review  
**Reviewed range:** `9192fd04a50e72c20a6e58c1c7e6b71ccfcbb31f` through `facdb346dc2dc417f6b1966c71ac9a048a57d8c5` (inclusive)  
**Reviewed implementation:** `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e`  
**Review verdict:** **rejected as an M1-complete implementation; compile-valid partial cutover only**  
**Next turn:** **M1 Single-Authority Cutover Remediation — Code + Build only**  
**Runtime gate:** artifact `9105462679` is retained as historical compile evidence but is **not** an M1 acceptance candidate

This amendment controls wherever it conflicts with the original plan below. The original requirements remain in force where this amendment does not replace them.

The implementation correctly deleted `LegacyAuthorityAdapters`, installed checked `SemanticId::from_index`, replaced the named route mirrors, introduced typed region/cell/rail/occurrence/quotient references, published a variant outcome, and compiled all 121 approved build steps. Those changes must be retained.

The implementation did not complete the promised vertical cutover. Raw source identity and scope still coexist with the new types and still participate in semantic decisions. The source-only audit was too narrow to detect those duplicates. Do not run the pending artifact-only acceptance plan against `9105462679`; first complete the remediation packages below and produce a new immutable compile artifact.

### 0.1 Blocking review findings

#### M1-R01 — source component, sheet, face, and support authority remains duplicated

Confirmed affected contracts include:

- `SourceChartTransitionGraph`, which still receives raw `vector<int>` component/sheet arrays;
- `SourceEntityId`, which reconstructs raw kind/component/source-index/fan fields and a numeric canonical vector from typed `SourceSupport`;
- `SurfaceCellOwnershipClassRecord` and `SurfaceCellDomainIdentity`, whose raw component/sheet fields participate in equality, ordering, and hashing;
- arrangement arcs, occurrences, provenance, nodes, halfedges, cells, and private segment records, which retain raw source face/component/sheet ownership;
- `PureQuadPatch` and `PureQuadVertexLineage`, which retain raw component/sheet authority beside typed regions, sheets, charts, and support;
- `build_authoritative_phase_front_mesh`, which receives raw `sourceFaceComponents` and `sourceFaceSheets` beside `SourceTopologyRegions` and reads both as authority;
- materializer occurrence/representative selection, which reads `SurfacePoint::{face,component,sheet}` after typed region/chart/support values already exist.

This violates the one-owner rule, AR-03/AR-04/AR-05/AR-09, and Sections 1, 3, 4B, and 4D of this plan.

#### M1-R02 — face-row handles and hashes still define semantic identity/order

- `SourceProjectionChart` stores `SourceFaceId`, which is currently an Eigen face-row handle.
- `SourceFaceInteriorSupport` also uses that row handle as its semantic identity.
- `surface_topology_region_hash_impl` hashes region IDs and face-row IDs, and `build_uniform_phase_front_state` uses that hash to order region work.
- `SourceChartTransition::structuralHash` hashes from/to face rows.
- the new face-row permutation contract compares region hashes instead of a row-independent semantic snapshot.

The current model therefore cannot satisfy the declared source-face-row permutation invariant. A diagnostic hash also participates in production ordering, directly violating Section 2.

#### M1-R03 — published authority values remain mutable and incompletely validated

- `SurfaceTopologyRegion`, `SourceTopologyRegions`, `SurfaceIsolationSeamTransportCertificate`, `SurfacePeriodicHolonomy`, and `SurfacePhaseFrontProduct` expose mutable public fields.
- non-const `SurfacePhaseFrontResult::product()` permits mutation after publication.
- `SourceTopologyRegions::complete_for_face_count` checks only vector length; it does not prove region-ID validity, exact face membership, or map/region bijection.
- `SurfacePhaseFrontResult::produced` checks non-emptiness, not the complete product invariant.
- `SurfaceIsolationSeamTransportCertificate::make` checks only distinct sheets and reciprocal turns. Owner membership, seam incidence, transition identity, face authority, canonical ordering, and sheet membership are deferred to a later consumer.
- `SurfacePeriodicHolonomy` has no stored `PeriodicRelationId`; vector position remains its implicit owner.

Tests mutate these published objects to manufacture malformed states. That proves the stated “malformed value is unrepresentable” and immutable-product requirements are not met.

#### M1-R04 — checked ingress and numeric-leaf rules remain violated

- `SurfaceOptimizationRailConstraints.cpp` constructs `SourceVertexId` with an `INT_MAX + 1` compatibility extent instead of the actual source-vertex container extent.
- phase-chart construction explicitly preserves a raw `legacyFaceChart` BFS partition/numbering before converting it to `FieldChartId`.
- `SemanticId::value()` remains as a compatibility alias, and a kernel test compares coincident raw values across domains.
- numeric projections are stored in `SourceEntityId`/`SurfaceCellCanonicalIdentity`, compared in materializer representative keys, hashed for region/chart identity, and unpacked from `GridAutomorphism` into a second rotation/translation pair for validation.

Private numeric scratch is permitted only while constructing a value and only when it cannot escape, become compatibility authority, or affect semantic equality/order/hash.

#### M1-R05 — required tests are incomplete or proxy-only

The packaged source declares all five required groups, but the required intent is not complete:

- no `SourceFaceTopologyKey` canonicalization/degeneracy test exists;
- compile-time domain separation covers selected pairs, not every semantic-ID domain;
- `RepresentationHandlePerturbationDoesNotChangeCanonicalRoute` mutates an unrelated local vector that is never consumed by the route;
- certificate coverage omits wrong-transition and wrong-face-key cases;
- the topology-region group does not positively and negatively exercise periodic and bounded-disk region ownership;
- `RequiredRegionReferencesCannotPublishMissingAuthority` checks only default constructibility and never attempts incomplete face-map publication;
- typed-transport coverage omits segment-route authority, a positive source-boundary route contract, canonical reversal equivalence, and the declared nonzero-Z4 behavior;
- support/chart coverage does not provide a genuinely close disconnected-sheet fixture, multiple orientation-chart identity, or row-permuted support/chart equality;
- the face-row permutation test uses a structural hash as its oracle, which `TESTING_STRATEGY.md` explicitly disallows;
- numerous accepted M1i–M1l semantic tests were removed; only representation/compatibility assertions may remain deleted. Any lost fail-closed or cross-region intent must be restored under the new contracts.

#### M1-R06 — the static audit and completion report overstate closure

The recorded audit checks a short banned-name list and then prints `static_cutover_audit=clean`. It does not inspect the duplicate fields and read-back paths above. Consequently these Code + Build report claims are not established:

- “numeric projections remain representation leaves”;
- “chart/source-support identity uses one typed contract”;
- “topology-region authority is typed through occurrence consumers”;
- “raw semantic mirror fields covered by the cutover are absent.”

The compile/package identity, checksums, command boundary, and 121/121 build result remain valid evidence. The M1-complete status and next-turn selection do not.

### 0.2 Corrected authority model

The remediation must distinguish a checked row locator from row-independent semantic identity.

```cpp
struct SourceRegionFaceAuthority {
  SourceFaceTopologyKey topology; // semantic face identity
  IsolationSheetId sheet;         // owned once for this region member
};

class SurfaceTopologyRegion {
public:
  static DomainResult<SurfaceTopologyRegion> make(/* complete validated data */);
  TopologyRegionId id() const noexcept;
  SourceComponentId component() const noexcept;
  const std::vector<SourceRegionFaceAuthority>& faces() const noexcept;
  const std::vector<SourceEdgeTopologyKey>& boundary_edges() const noexcept;
  const std::vector<SourceEdgeTopologyKey>& isolation_seams() const noexcept;
private:
  // validated immutable fields
};

class SourceTopologyRegions {
public:
  static DomainResult<SourceTopologyRegions> make(/* source faces + regions */);
  TopologyRegionId region_for_row(SourceFaceId row) const;
  const SourceRegionFaceAuthority& face_authority(SourceFaceId row) const;
  const SurfaceTopologyRegion& region(TopologyRegionId id) const;
private:
  // row-to-region/member data is a derived lookup index only;
  // component, sheet, and face topology are not copied into it.
};

struct SourceProjectionChart {
  FieldChartId chart;
  SourceFaceTopologyKey face;
};

struct SourceFaceInteriorSupport {
  SourceFaceTopologyKey face;
};
```

Equivalent repository-conventional names are allowed. These rules are not:

1. `SourceFaceId` is a checked matrix-row locator. It may be used to access the source matrix or the derived row lookup, but it is not face topology and must not participate in semantic equality, ordering, or hashes.
2. A region owns source component once and each member face’s sheet once. The row lookup points to those facts; it does not copy them.
3. `SourceProjectionChart` and face-interior `SourceSupport` use `SourceFaceTopologyKey`, so their equality survives source-face row permutation.
4. Raw classifier arrays are ingress data only. They are checked once while constructing the typed source-authority product and are not passed beside that product to later semantic consumers.
5. A general geometric `SurfacePoint` may remain a projection payload, but its raw component/sheet fields are not read as authority in the affected producer, verifier, materializer, arrangement-ownership, completion, or lineage paths. Authoritative code carries typed region/chart/support separately and derives any export-only integers after validation.

### 0.3 Mandatory remediation packages — one Code + Build turn

Complete these packages in order. The final pushed source and build artifact must contain all packages; no package may be deferred to another M1 slice.

#### R-A. Build and publish one complete typed source-authority product

1. Extend `SurfaceTopologyRegion` membership to pair row-independent face topology with the face’s typed isolation sheet.
2. Replace public aggregate construction with checked factories and private fields. Validate sorted/unique region IDs, region faces, sheets, boundary edges, and seam edges; exact face coverage; one region per source row; component consistency; and row topology matching the stored face key.
3. Keep any incomplete `optional`/integer build state inside `.cpp` builders only. Publish no object until the complete face-map/region bijection closes.
4. Consume raw classifier component/sheet arrays only in this builder. Replace later raw-array parameters with `const SourceTopologyRegions&` or the owning phase-front product.
5. Change `SourceChartTransitionGraph`, affected arrangement/patch/validator consumers, and the materializer to query component/sheet/region through this product.
6. Remove `SourceEntityId`. Represent resolved entity identity with `authority::SourceSupport`, `SourceProjectionChart`, and a strong typed fan/chart identifier when fan distinction is required. Add a new strong ID domain only if `FieldChartId` cannot correctly own that distinction.
7. Remove or replace raw component/sheet mirrors in semantic records, including `SurfaceCellOwnershipClassRecord`, `SurfaceCellDomainIdentity`, arrangement ownership/provenance records, `PureQuadPatch`, and `PureQuadVertexLineage`. Diagnostic/export records may contain derived integers only when no production path reads them back.
8. Remove raw component/sheet arguments from `build_authoritative_phase_front_mesh`. Materializer occurrences derive region, component, and sheet from the published source-authority product and carry required, not optional, typed region/chart/support after construction.
9. Delete standalone completion/optimizer compatibility branches that synthesize semantic identity or scope without complete typed authority. An exact arrangement boundary identity may be consumed only after validation against its typed owner/lineage.
10. Migrate `SourceAuthoritativeMeshValidator`, `SurfaceMeshOptimizer`, and `SurfaceOptimizationRailConstraints` so raw `SurfacePoint` component/sheet values cannot accept, reject, scope, order, merge, or route production data.
11. Make missing typed completion lineage reject with `MissingTypedStitchIdentity`; do not infer authority from patch-local vertex IDs, positions, source-patch IDs, hashes, or raw projection labels.
12. Replace standalone fixtures that depend on raw labels with typed positive or explicit missing-authority negative fixtures. No legacy-fixture exception survives the cutover.

#### R-B. Make face, support, and chart identity row-independent

1. Change `SourceProjectionChart::face` and `SourceFaceInteriorSupport::face` to `SourceFaceTopologyKey`.
2. Build the face key once from checked source vertices at ingress. Maintain a derived key-to-row/row-to-key lookup for Eigen access; never store its row as semantic identity.
3. Assign `FieldChartId` in canonical topology order. Remove the compatibility-numbering goal and `legacyFaceChart`; private traversal ordinals may exist only until canonical IDs are assigned.
4. Sort topology regions and chart transitions by their canonical typed fields, never by a digest.
5. Make region/chart/support diagnostic digests derive from canonical typed topology and typed ownership. Exclude row locators and do not use the digest for equality, ordering, lookup, validation, or production scheduling.
6. Replace every affected face-row permutation assertion with a semantic snapshot of topology keys, typed ownership, routes, certificates, and output correspondence.

#### R-C. Close and freeze published products and certificates

1. Make `SurfaceTopologyRegion`, `SourceTopologyRegions`, `SurfaceIsolationSeamTransportCertificate`, `SurfacePeriodicHolonomy`, and `SurfacePhaseFrontProduct` factory-constructed values with private state and const accessors.
2. Remove non-const `SurfacePhaseFrontResult::product()`. The `.cpp` build state remains mutable; the published `Produced` payload does not.
3. Make `SurfacePhaseFrontProduct::make` validate all region, cell, edge, periodic, bounded-disk, certificate, and ID-reference bijections before returning `Produced`.
4. Replace certificate `optional` construction with a typed `DomainResult`/certificate error. The factory receives enough typed source authority to validate owner region, seam membership/incidence, transition identity, canonical face order, distinct and correctly owned sheets, and reciprocal quarter turns.
5. No certificate member is publicly mutable. Negative tests call the factory with malformed inputs and assert the precise typed rejection; they do not prove correctness by corrupting an already published value.
6. Give every `SurfacePeriodicHolonomy` its own `PeriodicRelationId`; verify uniqueness and edge ownership at product construction. Consumers resolve relations by typed ID, not vector position.
7. Keep derived diagnostic/export hashes outside semantic value state when practical. If cached for diagnostics, compute only after successful construction and never consume it as authority.

#### R-D. Finish checked ingress and remove compatibility bridges

1. Remove `SemanticId::value()`; retain `index()` as the only numeric projection spelling. `DomainResult::value()` is unrelated and remains.
2. Pass the actual source-vertex extent into rail-constraint conversion. Delete `legacy_source_vertex_extent`; an ID outside the owning mesh/container must reject.
3. Delete the compatibility chart numbering/name and all affected comments or tests whose purpose is preserving the displaced representation.
4. Audit every `.index()`/quarter-turn numeric projection in the affected source. It is allowed only inline at a direct matrix/vector access or one-way diagnostic/export encoding. It must not be assigned to persistent semantic state, inserted into a semantic tuple/map/set key, compared to a second raw authority, or used to order work.
5. Replace materializer periodic validation’s unpacked integer rotation/`Eigen::Vector2i` pair with `GridAutomorphism::apply`, `compose`, and `inverse` on typed lattice values.
6. Preserve unrelated geometry/product behavior. Do not restore an adapter, alias, raw mirror, fallback, or representation-numbering oracle to fix compilation.

#### R-E. Complete typed owner use without expanding into later product algorithms

1. Store and resolve `PeriodicRelationId`, `HardRailId`, `CellId`, `OccurrenceId`, and `QuotientClassId` at every affected semantic owner/reference. A vector offset may remain an explicitly named local storage index only when it is not exported or compared as identity.
2. Replace relation-vector positional ownership with typed-ID maps or checked lookup tables derived from the published product.
3. Make route construction fail closed for structural invalidity already required by M1: missing interior IDs, invented boundary IDs, unsupported mixed step kinds, and duplicate step authority where the current product contract forbids it.
4. Keep topology-to-transition certificate/reconstruction work that is explicitly assigned to M4 out of this remediation. M1 must remove numeric mirrors and invalid public states; it must not implement a new G4 algorithm.

#### R-F. Restore intent-complete compile contracts

Compile, but do not execute, the following added/adapted tests in the new artifact:

1. `SurfaceCellAuthorityKernel`
   - generate compile-time non-convertibility checks for every pair of distinct semantic-ID domains;
   - check lower/upper/negative/out-of-range construction for representative domains and actual-ingress extent use;
   - add `SourceFaceTopologyKey` permutation canonicalization and repeated-vertex rejection;
   - delete the unrelated-vector “representation perturbation” test and replace it with a real route-input/order metamorphic contract.
2. `SurfaceCellAuthorityContractCutover`
   - factory rejection for missing, duplicate, out-of-range, and conflicting face/region membership;
   - positive and tamper contracts for cell, edge, periodic, and bounded-disk typed region ownership;
   - materializer API compile contract proving raw component/sheet arrays are no longer accepted;
   - face-row permutation equality over semantic snapshots, not hashes.
3. `SurfaceCellIsolationSeamCertificateAuthority`
   - positive reciprocal multi-sheet construction/materialization;
   - factory rejection for wrong region, seam, transition, first/second face key, sheet membership/order, duplicate key, and nonreciprocal transport;
   - exact-once consumption observed through the immutable product.
4. `SurfaceCellTypedTransportAuthority`
   - segment entry routes, hard-rail routes, genuine source-boundary routes, and periodic/cut routes;
   - canonical reversal/inversion using actual route inputs;
   - swapped topology/transition and invented boundary-transition rejection;
   - truthful nonzero-Z4 unsupported behavior unless production already supports it.
5. `SurfaceCellSourceSupportAndChartAuthority`
   - distinct vertex/edge/face-interior variants using topology-key face identity;
   - genuinely close disconnected sheets and distinct orientation charts;
   - source-face row permutation preserving support/chart/entity identity;
   - malformed/ambiguous support typed rejection.
6. Restore every removed M1i–M1l fail-closed, cross-region, multi-sheet, and permutation intent not covered by the new tests. Do not restore tests whose sole intent was adapter round-trip, raw numbering, hash identity, or compatibility output.
7. Add the R-A closure contracts: identical typed lineage under different raw projection labels has identical semantics; coincident geometry under distinct typed sheets does not merge; missing typed sheet/region or exact boundary identity returns `MissingTypedStitchIdentity`; and materializer sheet decisions remain unchanged under raw-projection tamper.

Every test must establish its precondition and assert a semantic input/output or construction-rejection contract. Existence, exact count, hash equality, compile success, or an unrelated mutation is not sufficient evidence.

#### R-G. Replace the false-positive static audit

The final pre-build audit must fail, not merely print, when any displaced contract remains. At minimum:

1. retain the original banned-symbol list;
2. add `SourceEntityId`, `legacyFaceChart`, `legacy_source_vertex_extent`, the `SemanticId::value()` compatibility accessor, and affected “legacy representative/compatibility path” branches;
3. enumerate every raw face/component/sheet field in the affected semantic structs and prove it was removed, typed, or moved to a one-way diagnostic/export record;
4. enumerate every affected `.index()` call and classify it as a direct container leaf or one-way export; any unclassified use fails the audit;
5. add compile-time schema assertions that published region/certificate/product fields are private/const-only and malformed construction APIs are unavailable;
6. prove `build_authoritative_phase_front_mesh` and affected validators no longer accept raw component/sheet authority beside the typed product;
7. reject valid-looking patch-local or standalone compatibility identities that lack complete typed lineage, and audit `SourceAuthoritativeMeshValidator`, `SurfaceMeshOptimizer`, and `SurfaceOptimizationRailConstraints` for raw projection read-back;
8. record the checked paths, match counts, and allowed leaf inventory in the package. A heading-only audit followed by `clean` is insufficient.

### 0.4 Corrected Code + Build and acceptance sequence

1. Implement R-A through R-G in one Code + Build turn on the current branch.
2. Configure and compile the established Release/static/Ninja/PRE_TEST targets only. Do not execute generated binaries, discovery, tests, benchmarks, CLI, fuzzers, or custom inputs.
3. Package the exact final implementation, source archive/diff, compile logs, new checked audit, test-source manifest, fixtures, and recursive checksums. Generate the manifest after all payload writes, exclude the manifest itself, verify it before upload, and record clean source provenance independently of the out-of-tree build directory.
4. Activate the current artifact-only plan only after it names the new implementation/artifact and includes the corrected tests above. No historical or partial package may be relabeled as acceptance evidence.
5. Run a separate immutable Artifact-Only Test + Benchmark turn against the new package.
6. Close M1 only if the new source audit, focused semantic groups, entering preservation gates, direct product oracles, known-red classification, bounded characterization, and immutable postflight all close.
7. Resume G4 directly after M1 acceptance. Do not open another M1 letter slice and do not defer any finding above to M2–M6.

### 0.5 Remediation definition of done

The remediation Code + Build turn is complete only when all of the following are true at one pushed implementation commit:

- exactly one source-authority product owns region/component/sheet/face topology for the affected pipeline;
- chart and face-interior support identity are invariant to source-face row permutation;
- no affected semantic record stores a raw component/sheet/face mirror beside typed authority;
- published regions, certificates, periodic relations, and phase-front products cannot be mutated into invalid states;
- every semantic owner named by M1 is stored and resolved by its strong ID rather than vector position;
- numeric projections are confined to reviewed direct storage/export leaves;
- diagnostic hashes do not order work or serve as semantic test oracles;
- all missing test intents in M1-R05 are compiled into the artifact;
- the expanded audit closes with explicit evidence;
- the exact source builds under the Code + Build boundary;
- the next turn is immutable validation of the new artifact, not validation of a historical or partial package.

## 1. Decision and outcome

The prior narrow follow-up plan is superseded. The next Code + Build turn must finish M1 as one source-level cutover from the partially migrated state to one semantic authority model.

This branch is experimental. It has no released surface-cell ABI, serialized schema, or supported internal contract that justifies retaining transitional authority fields. The cutover therefore replaces each affected producer-to-consumer contract in place and deletes the displaced representation in the same turn.

The completed source must have these properties:

1. checked strong IDs are constructed at raw mesh/container ingress;
2. semantic identity remains typed from producer through verification and materialization;
3. a semantic fact has one stored representation and one owner;
4. numeric projection occurs only at the exact Eigen/vector/serialization leaf that requires an index;
5. no numeric projection is stored, compared, hashed, or passed to another semantic consumer;
6. accepted G0–G3 invariants and truthful failure behavior remain protected;
7. output differences are classified against product/design invariants, not rejected merely because they differ from the pre-cutover artifact;
8. after immutable artifact-only validation, M1 closes and work returns to the active G4 product gate.

The turn is intentionally a single broad authority cutover. Do not split it into more M1 letter slices and do not leave a half-converted contract for a later turn.

## 2. Non-negotiable implementation rules

- Delete every transitional raw mirror touched by this plan in the same change that introduces its typed replacement.
- Delete `LegacyAuthorityAdapters.h`, the `LegacyAuthorityAdapters` class, its friend access, implementation methods, includes, and tests. Replace it with checked construction owned by `SemanticId` or a narrowly named free factory in `AuthorityIds.h`.
- Rename `DomainErrorCode::{NegativeLegacyValue,OutOfRangeLegacyValue}` and `DomainError::legacyValue` to representation-neutral index terminology.
- Keep `SemanticId::index()` as the only representation accessor. Calls are permitted at direct Eigen/vector access and derived export encoding, not in semantic equality, map keys, ownership, routing, hashing, or validation decisions.
- Do not add a second raw field, cache, lookup table, hash, or helper to ease the cutover.
- Hashes are derived diagnostics. They do not participate in semantic equality or ordering and cannot be used to reconstruct authority.
- Do not preserve raw output row order, raw ID numbering, structural hashes, or exact intermediate counts unless an independently documented product invariant requires them.
- Do preserve source attachment, topology-region/sheet/chart distinction, transport composition, certificate ownership, exact-once consumption, determinism, direct-backend disposition, and no-fallback behavior.
- Do not change fallback/recovery, optimization policy, target-size policy, or G4 algorithms except where compilation requires them to consume the new types without changing their product logic.
- No generated Directional binary may execute in this turn.

## 3. Target authority model

Use the existing strong-ID and transport primitives. Extend them only where a complete contract requires a missing value object.

```cpp
template<class Tag>
class SemanticId {
public:
  static DomainResult<SemanticId> from_index(std::int64_t index,
                                              std::size_t extent);
  std::size_t index() const noexcept;
};

class SourceFaceTopologyKey {
public:
  static DomainResult<SourceFaceTopologyKey>
  make(std::array<SourceVertexId, 3> vertices);
  const std::array<SourceVertexId, 3>& vertices() const noexcept;
};

struct SourceProjectionChart {
  FieldChartId chart;
  SourceFaceTopologyKey face;
};

struct ResolvedSourceSupport {
  SourceSupport support;
  std::vector<SourceFaceId> incidentFaces; // derived incidence, not identity
};

struct SurfaceTopologyRegion {
  TopologyRegionId id;
  SourceComponentId component;
  std::vector<SourceFaceId> faces;
  std::vector<IsolationSheetId> isolationSheets;
  std::vector<SourceEdgeTopologyKey> boundaryEdges;
  std::vector<SourceEdgeTopologyKey> isolationSeams;
};

struct SourceTopologyRegions {
  std::vector<TopologyRegionId> regionByFace;
  std::vector<SurfaceTopologyRegion> regions;
};

struct IsolationSeamTransportCertificate {
  TopologyRegionId region;
  SourceEdgeTopologyKey seam;
  InteriorTransitionId transition;
  SourceFaceTopologyKey firstFace;
  SourceFaceTopologyKey secondFace;
  IsolationSheetId firstSheet;
  IsolationSheetId secondSheet;
  QuarterTurn forward;
  QuarterTurn reverse;
};
```

Equivalent names matching repository convention are acceptable. The ownership and invalid-state rules are not optional:

- published IDs are required values, not `-1` sentinels;
- builder-only incomplete state stays private to the `.cpp` implementation;
- published `SourceTopologyRegions` contains a complete face map;
- a region owns component and sheet membership once;
- chart/component/sheet queries derive through the source/region products; chart records do not copy those labels;
- cells, front edges, periodic relations, bounded-disk records, certificates, and occurrences reference the region by `TopologyRegionId` instead of copying component/sheet/region mirrors;
- a single-sheet value is derived from `region.isolationSheets`, never stored beside the complete set;
- certificate construction is fail-closed and makes a malformed certificate unrepresentable;
- `forward` and `reverse` must compose to the identity;
- source-face keys are canonical typed source-vertex triples;
- `CanonicalRoute` owns route topology, optional interior-transition identity, transport, and orientation together;
- `GridAutomorphism` owns periodic rotation and translation together.

## 4. Required work packages within this one turn

Complete the packages in order. Checkpoint commits are allowed for recovery, but the authoritative build/package must be produced from the final pushed tip containing every package.

### A. Replace adapter construction with checked ID construction

Primary files:

- `include/directional/authority/AuthorityIds.h`;
- `src/authority/AuthorityKernel.cpp`;
- delete `include/directional/authority/LegacyAuthorityAdapters.h`;
- all production/test files that include or name the deleted class.

Required edits:

1. Move checked range validation into `SemanticId<Tag>::from_index` or `make_semantic_id<Id>`.
2. Keep constructors private so arbitrary numeric construction is impossible.
3. Preserve compile-time non-convertibility between ID domains.
4. Replace adapter calls in `SurfaceCellTracing.cpp`, `RemeshPipeline.cpp`, and `SurfaceOptimizationRailConstraints.cpp` with checked ingress construction.
5. Replace `to_legacy_index` helpers and every `legacy_phase_front_*` helper with direct typed use. At a matrix/vector leaf, use `id.index()` inline and do not retain the numeric value beyond that expression.
6. Remove adapter round-trip tests. Replace them with checked-construction boundary tests and compile-time domain-separation tests.

### B. Publish one topology-region product

Primary symbols:

- `SurfaceTopologyRegion`;
- `SourceTopologyRegions`;
- `build_source_topology_regions`;
- `SurfacePhaseFrontResult`;
- `build_uniform_phase_front` and its regional finalization path;
- `pipeline::build_authoritative_phase_front_mesh`.

Required edits:

1. Type region ID, component, face membership, sheet membership, boundary edges, and isolation seams.
2. Build with private `optional<TopologyRegionId>` scratch slots if necessary, verify every face is assigned exactly once, then publish `vector<TopologyRegionId>` with no missing state.
3. Replace `SurfacePhaseFrontResult::{sourceTopologyRegionByFace,topologyRegions}` with one `SourceTopologyRegions` member.
4. Replace `SurfacePhaseFrontResult::{disposition,attempted,succeeded}` plus partial payload with one exhaustive `ProducerOutcome<SurfacePhaseFrontProduct>`. `Produced` owns the complete topology/relations/cells/edges payload; `Rejected` owns a typed failure and exposes no consumable partial product; `NotApplicable` owns no payload.
5. Replace `normalize_scope` mutation with a finalization step that constructs published cells/edges with required region references. Do not publish partially scoped cells or edges.
6. Remove cell/edge copies of source component, single sheet, and full sheet set. Resolve those facts through the owning region.
7. Type topology-region references in periodic holonomy, bounded-disk phase records, materializer occurrence data, consumed-region sets, isolation-sheet graphs, and certificate indexes.
8. In the materializer, use the producer-published face map directly. A derived map of `TopologyRegionId -> const SurfaceTopologyRegion*` is permitted as a lookup index; rebuilding a second face-to-region authority is not.
9. Keep face row numbers only for indexing source matrices. Semantic comparison uses `SourceFaceId` or `SourceFaceTopologyKey`.

### C. Replace the complete isolation-seam certificate contract

Primary symbols:

- `SurfaceIsolationSeamTransportCertificate`;
- `build_isolation_seam_transport_certificates`;
- `isolation_seam_transport_certificate_hash`;
- certificate verification and exact-once consumption in `build_authoritative_phase_front_mesh`.

Required edits:

1. Replace every certificate identity/transport member together: region, seam topology, transition, both source faces, both sheets, and both quarter turns.
2. Remove `sourceComponent`; it is derived from the owning region.
3. Remove raw seam topology/index pairs and raw face arrays.
4. Remove integer quarter turns; use `QuarterTurn` and require reciprocal composition.
5. Construct certificates through one factory/builder that validates region membership, exact seam incidence, distinct sheets, transition identity, canonical face order, and reciprocal transport before returning a value.
6. Define equality/order from typed semantic fields only.
7. Replace persistent `structuralHash` authority with a derived digest function used only for diagnostics/export. The verifier recomputes it when a diagnostic digest is required.
8. Key duplicate detection, sheet graphs, and exact-once consumption by typed `(TopologyRegionId, SourceEdgeTopologyKey)`.
9. Preserve the existing typed failure categories for missing, duplicate, wrong-owner, wrong-sheet, nonreciprocal, and bijection failures. Do not repair or infer a malformed certificate.

### D. Finish chart, support, route, and periodic transport cutover

This package removes the remaining dual representations introduced during M1a–M1l.

Primary symbols:

- `SurfaceTraceSegment`;
- `LocalLatticeState`;
- `SurfaceFrontEdge`;
- `SurfacePeriodicHolonomy`;
- `SourceChartId` and `SurfaceCellSourceChart`;
- `SurfacePointSourceSupport` and `SurfacePointSourceSupportResolver`;
- source-chart, route, support, lineage, validator, and materializer consumers.

Required edits:

1. Replace `SurfaceTraceSegment::sourceChart` with required/optional `FieldChartId` as dictated by actual segment validity; remove raw chart storage.
2. Replace `transitionSourceEdge`, `transitionSourceEdges`, and `transitionSourceTopology` with one `CanonicalRoute` whose steps carry `SourceEdgeTopologyKey` and optional `InteriorTransitionId`.
3. Replace `SurfaceFrontEdge::{sourceRouteEdges,sourceRouteTopology}` with one route. Boundary steps have topology and no invented transition ID.
4. Replace periodic raw route/cut vector pairs with `CanonicalRoute` values and replace integer rotation/`Eigen::Vector2i` pairing with `GridAutomorphism`.
5. Assign `PeriodicRelationId`, `HardRailId`, `CellId`, `OccurrenceId`, and `QuotientClassId` wherever those values are semantic owners. Keep front-edge/vector offsets as explicitly named representation indices.
6. Replace the duplicate chart structs with one typed `SourceProjectionChart {FieldChartId, SourceFaceTopologyKey}` value object. Component and sheet are queried from the owning source/region products, never copied into the chart. Update `SourceChartTransitionGraph`, arrangement ownership, patch descriptors, lineage, validators, benchmarks, and tests to use that type.
7. Make `authority::SourceSupport` the sole vertex/edge/face-interior identity returned by source-point resolution. Retain resolver failures as typed errors and retain incident faces as derived typed incidence. Delete raw kind/vertex/edge identity mirrors.
8. Update semantic digests to hash typed value-object fields. Do not project to integers before equality/order/hash.
9. If a public diagnostics/serialization record must emit integers, derive them once after verification in the export code. No producer, materializer, or validator may read that export representation back.

### E. Adapt tests to contracts, not deleted representation

Tests may change only to preserve or strengthen their stated semantic intent.

Required test groups:

1. `SurfaceCellAuthorityKernelTests`
   - checked construction accepts the lower/upper valid boundaries;
   - negative and extent values reject with the correct typed error;
   - every ID domain remains non-convertible at compile time;
   - source-edge and source-face topology keys canonicalize and reject degeneracy.
2. `SurfaceCellAuthorityContractCutover`
   - a multi-region production fixture publishes one complete typed face map;
   - cell/edge/periodic/bounded-disk consumers reference the published region and cannot carry conflicting component/sheet mirrors;
   - source-face row permutation preserves semantic region/certificate identity;
   - missing/unassigned face authority fails before publication.
3. `SurfaceCellIsolationSeamCertificateAuthority`
   - reciprocal multi-sheet certificate succeeds through materialization;
   - wrong region, seam transition, face key, sheet owner, duplicate key, and nonreciprocal quarter turn each fail for the intended existing category;
   - exact-once certificate consumption is observable.
4. `SurfaceCellTypedTransportAuthority`
   - segment, hard-rail, source-boundary, and periodic routes carry the right typed step variants;
   - route reversal/inversion preserves canonical identity;
   - swapped topology/transition inputs and invented boundary transitions reject;
   - nonzero Z4 remains truthfully unsupported unless the production algorithm already supports it; do not special-case a pass.
5. `SurfaceCellSourceSupportAndChartAuthority`
   - vertex, edge, and face-interior support are distinct typed variants;
   - close sheets and multiple orientation charts remain distinct;
   - row permutation preserves semantic support/chart identity;
   - ambiguous or malformed support fails typed.

Adapt existing M1a–M1l and certificate/materializer tests in place. Remove assertions whose only purpose was to prove conversion back to a raw number. Replace them with typed equality, semantic output, or fail-closed assertions. Do not predeclare a new discovery total; the following Test + Benchmark turn must independently discover and record it.

### F. Static cutover audit

Before the authoritative build, run source-only searches. The relevant production/test scope must contain no references to:

```text
LegacyAuthorityAdapters
to_legacy_index
legacy_phase_front_
transitionSourceEdge
transitionSourceEdges
transitionSourceTopology
sourceRouteEdges
sourceRouteTopology
sourceTopologyRegionByFace
struct SourceChartId
struct SurfaceCellSourceChart
```

Also audit changed structs for pairs of typed and numeric fields representing the same semantic fact. A nonzero result is unfinished implementation, not a follow-up task.

## 5. Scope control and allowed files

This is a symbol-bounded cutover, not a filename-bounded micro-slice. Changes are authorized only where compilation or semantic ownership requires one of the contracts above.

Expected areas include:

- `include/directional/authority/**` and `src/authority/**`;
- `SurfaceCellTracing`, `SourceChartTransitions`, `SurfacePointSupport`, `SurfaceCellOwnership`, `SurfaceArrangement`, `PatchDescriptor`, and rail-constraint source/header files;
- `PureQuadCompletion` lineage/equivalence records where they consume affected authority;
- `RemeshPipeline.cpp` materialization, verification, semantic digest, and derived export;
- `SourceAuthoritativeMeshValidator` affected authority records;
- benchmark/diagnostic serialization that must emit derived values;
- tests directly broken by deleted fields/types or required by package E;
- build/install manifests only if deleting/adding headers requires it.

Do not refactor unrelated geometry algorithms, rename unrelated public APIs, reformat untouched files, change fixtures, alter thresholds, or redesign CMake.

## 6. Behavior and difference classification

The M1l artifact is evidence, not the target contract. Use it to detect changes, then classify each change:

- **required invariant regression:** source attachment, topology, transport, certificate consumption, determinism, strict disposition, or no-fallback behavior worsened — block acceptance;
- **intentional representation change:** raw ID/order/hash/intermediate layout changed while semantic output is equivalent — accept and document;
- **truthfulness correction:** malformed or ambiguous state now fails earlier through an appropriate typed failure — accept when the design requires it;
- **product progress:** a known-red fixture improves because invalid reconstructed authority was removed — retain as evidence but require the full independent product oracle before changing gate status;
- **unexplained semantic drift:** stop and diagnose; do not automatically force old output.

G0–G3 acceptance means their documented semantic invariants remain true. It does not require byte-for-byte or count-for-count reproduction of the pre-cutover internals.

## 7. Code + Build boundary

The turn may edit source/tests/build manifests, configure, compile/link, and package the exact pushed final commit. Use the established Release/static/Ninja configuration and compile-only-safe GoogleTest mode (`PRE_TEST` or equivalent).

The turn must not execute:

- a generated Directional test or benchmark binary;
- GoogleTest discovery/listing;
- `ctest`;
- CLI/GUI/help/version/smoke commands;
- fuzzers;
- custom mesh or field inputs.

Compile failures caused by the deleted contracts are implementation work for this turn. Fix them by migrating the affected consumer, not by restoring a displaced field or alias.

## 8. Authoritative package requirements

Package enough information for a separate artifact-only Test + Benchmark turn:

- exact final source commit and immediate parent;
- reviewed M1l implementation identity;
- complete source diff/archive and changed-path/blob manifest;
- configure/build/toolchain/submodule logs;
- all established producer, authority-kernel, validation, completion, oracle, compiled-API, and benchmark executables;
- unchanged committed fixture closure;
- manifest of new/renamed cutover test groups without executing discovery;
- command-boundary metadata with every runtime flag false;
- recursive checksums generated after the final package write;
- source-only cutover-audit output.

The result artifact must not be repaired after packaging.

## 9. Following immutable Test + Benchmark gates

The next turn consumes the exact package without rebuilding and must:

1. verify package/source/fixture/command-boundary closure;
2. discover the actual test inventory independently;
3. run each new cutover contract by exact name before aggregates;
4. run the adapted M1a–M1l semantic preservation groups, M1 route/transition counterexamples, validation, T1, and required-green producer set;
5. run Plane, MultiFaceSeam, CloseSheets, and Cylinder through the independent product oracle;
6. execute the eight historical/deferred red cases and classify semantic drift rather than enforcing raw representation equality;
7. characterize strict-validator timing truthfully;
8. run bounded Bunny/Vase comparison;
9. verify immutable postflight;
10. audit that no displaced source symbols or duplicate semantic fields are present in the packaged source.

M1 closes only if all required-green semantic gates pass, no unclassified product regression exists, and the static cutover audit is clean. The following Code + Build plan then returns to G4, selecting the highest-prerequisite active blocker supported by the new runtime evidence; it does not open another authority-migration letter slice.

## 10. Stop conditions

Stop and report the exact blocker if:

- a supposedly external integer contract is proven to be a released/supported ABI or file format requiring a user decision;
- the cutover would require fixture-specific production logic or weaker validation;
- a consumer cannot be migrated without implementing an unrelated new G4 algorithm;
- a raw semantic mirror would remain at the final pushed tip;
- a generated binary would need to run to complete Code + Build;
- branch authority moves and cannot be reconciled without overwriting another actor's changes.

Do not respond to a compile failure by reintroducing the deleted adapter, raw field, alias, or fallback. Preserve the partial work on the branch, document the precise unresolved contract, and request direction only if it is a genuine stop condition above.
