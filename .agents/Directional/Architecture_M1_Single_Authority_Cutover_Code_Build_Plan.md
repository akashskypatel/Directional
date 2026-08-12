# M1 Single-Authority Cutover — Code + Build Plan

**Turn type:** Code + Build only  
**Current status:** independent closure review rejects overall R-A at branch boundary `356a0bc2733af41e15fad056161e526865c147c5`; the bounded REV-17/REV-20 remediation is retained as compile-valid progress, REV-18/REV-19 remain unimplemented, and R-A-REV-21 is open before the complete R-A inventory, R-B through R-G, and one fresh full package
**Reviewed source authority:** M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Latest independent-review branch boundary:** `356a0bc2733af41e15fad056161e526865c147c5`  
**Latest review-remediation implementation/compile source:** `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`
**Product gate after acceptance:** resume G4 topology-distinct completion and singularities  
**Review policy after the following Test + Benchmark turn:** `never`

## 0B. 2026-08-12 independent R-A closure review after REV-17/REV-20 partial remediation — rejected

Exact implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` was reviewed at branch authority `356a0bc2733af41e15fad056161e526865c147c5`. The six commits after the implementation source change only durable documents. Comparison from the prior review head to the implementation source shows substantive completion/optimizer work but only two deletions in `RemeshPipeline.cpp`; no aggregate-authority or aggregate-oracle implementation/test path changed.

| Checkpoint | Review decision |
|---|---|
| overall R-A | **rejected / open** |
| R-A-REV-17 | bounded owner-certificate/canonical-cache remediation retained; **not independently accepted** |
| R-A-REV-18 | **open / not implemented** |
| R-A-REV-19 | **open / not implemented** |
| R-A-REV-20 | bounded compatibility-path removal retained; **not independently accepted** |
| R-A-REV-21 | **open / new complete-inventory finding** |

REV-17 now validates incoming/intersected certificate relations and REV-20 removes the named raw/legacy optimizer branches. Those changes compiled successfully, but no packaged semantic contract executed. They also still accept a different same-face-count `SourceTopologyRegions` as “complete” because the affected boundaries validate only extent, not exact source-topology ownership.

The partial result/log artifacts `9149834162 / 9149834634` remain authentic compile-only history. The planned focused runtime turn for that partial package is superseded: its packaged contracts cannot close the new same-extent/wrong-topology authority counterexample, and REV-18/REV-19 are absent. Do not execute or relabel it as R-A or M1 acceptance evidence.

## 0A. Retained 2026-08-12 review of overall R-A and REV-14-through-REV-16 — rejected

Exact implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` was reviewed at branch authority `fd96852d19defe70effd0dc6fbbaf07db8378e55`. Later commits are durable-document and temporary-workflow cleanup only for the affected paths.

The prior compile-only package remains authentic partial build evidence: run/job `31602025466 / 94131563590`, Release/static/Ninja/PRE_TEST **118/118**, artifacts `9143819164 / 9143819888`, self-excluding manifest **21/21**, clean recorded source status, and no generated runtime. Compile authenticity does not close the semantic review.

| Checkpoint | Review decision |
|---|---|
| overall R-A | **rejected / open** |
| R-A-REV-14 | **implementation checkpoint retained; independent closure rejected** |
| R-A-REV-15 | **implementation checkpoint retained; independent closure rejected** |
| R-A-REV-16 | **pre-consumer seam retained; full audit/oracle closure rejected** |

Exact evidence is retained in `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`. This prior checkpoint produced the bounded corrections below; Section 0B owns their current review status:

### R-A-REV-17 — source-owned collision certificates

**Current review status:** bounded remediation is complete / compile-valid at `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` and retained as progress; independent closure is deferred because R-A-REV-21 still admits a foreign same-extent authority product.

- Require complete source topology/chart/support authority for semantic stitch publication.
- Validate each incoming and intersected certificate against region-sheet, chart-face, and support-incidence ownership.
- Remove acceptance of exact-only or partial-typed cached identities; derive an absent value or require exact canonical equality.
- Replace fabricated ID fixtures with authority-owned overlap and add wrong-owner, unowned/sparse, wrong-face, exact-only, and stale-identity zero-publication negatives.

### R-A-REV-18 — global aggregate authority and derived identity closure

**Status:** open; intentionally not implemented in the REV-17/REV-20 partial Code + Build turn.

- Publish one checked global source-authority product for the original source mesh.
- Remap all component lineage through that owner and validate the final global lineage.
- Recompute or remove `stitchIdentity`/`authoritativeIdentity` caches after remap and regenerate face-cycle hashes from final global identities.
- Add a two-component colliding-local-domain contract plus stale-cache rejection.

### R-A-REV-19 — transactional aggregate publication and real post-merge oracle

**Status:** open; intentionally not implemented in the REV-17/REV-20 partial Code + Build turn.

- Stage labels, rails, lineages, patches, debug products, optimization, and validation state; commit only after all components and final validation succeed.
- On rejection expose no consumable semantic context, including after a valid first component and malformed later component.
- Validate the final merged/remapped product against the global authority rather than accumulating cached per-component reports.
- Expand REV-16 snapshots/audit to include the global owner, canonical identities, face cycles, all remap domains, complete context rollback, and actual post-merge validation.

### R-A-REV-20 — remove or isolate remaining R-A compatibility paths

**Current review status:** bounded compatibility-path removal is complete / compile-valid at `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` and retained as progress; independent closure is deferred because the strict completeness predicate remains extent-only under R-A-REV-21.

- Remove raw optimizer component/sheet mirrors and legacy point-cloud/feature-interval/basic-validator branches from the affected SurfaceCells path.
- If generic non-SurfaceCells behavior must remain, move it behind a separately typed implementation that strict SurfaceCells wrappers cannot enter.
- Add missing-authority and alternate-validator-path contracts and make the audit fail on the named legacy branches or bypass calls.

### R-A-REV-21 — bind source authority to the exact supplied source topology

**Status:** open; discovered by the complete R-A inventory of source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`.

- Replace face-count-only “complete authority” checks at every affected `(sourceFaces, SourceTopologyRegions)` boundary with an exact row-topology binding check.
- For every source row, construct the checked `SourceFaceTopologyKey` from the supplied source matrix and require equality with `sourceAuthority.topology_for_row(row)`; reject malformed/repeated/out-of-extent vertices before semantic use.
- Apply the binding transitively to completion/stitching, `SourceChartTransitionGraph`, optimizer helpers/wrappers, source-authoritative validation, and pipeline ingress. A pointer plus matching row count is not source ownership.
- Add same-face-count/wrong-topology and authority-only-row-permutation negatives with zero publication. Add a consistently permuted source-matrix-plus-authority positive.

### Required execution sequence

1. Implement REV-18, REV-19, and REV-21 without restoring a raw mirror, compatibility identity, fixture exception, proxy oracle, or extent-only authority bypass.
2. Rerun the complete R-A closure inventory. R-A may close only if every retained REV-01-through-REV-21 gate is statically clean and all required semantic contract sources compile.
3. Complete R-B through R-G in the same vertical cutover.
4. Produce one fresh full R-A-through-R-G Release/static/Ninja/PRE_TEST package with clean provenance and a verified self-excluding manifest.
5. Execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input in the Code + Build turn.
6. Activate immutable Test + Benchmark only for that fresh full package; no historical or partial package is an acceptance candidate.

## 0. Retained M1 cutover requirements

The corrected authority model and the R-A-through-R-G requirements below remain normative where current Section 0B does not refine them. Historical review findings, rejected artifacts, and superseded task selection are retained in `CHANGELOG.md` and the retained independent-review report rather than repeated in this live plan.

### 0.1 Corrected authority model

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

### 0.2 Mandatory remediation packages — one Code + Build turn

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
