# M1 Single-Authority Cutover — Code + Build Plan

**Turn type:** Code + Build only  
**Review decision:** rejected and replaced  
**Reviewed source authority:** M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Review/planning baseline:** `fcba2fd9b8905802ca373e0cc88aeccbf38d608a`  
**Product gate after acceptance:** resume G4 topology-distinct completion and singularities  
**Review policy after the following Test + Benchmark turn:** `never`

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
- Keep `SemanticId::value()`/`index()` as a representation accessor only. Calls are permitted at direct Eigen/vector access and derived export encoding, not in semantic equality, map keys, ownership, routing, hashing, or validation decisions.
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
  SourceFaceId face;
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
6. Replace the duplicate chart structs with one typed `SourceProjectionChart {FieldChartId, SourceFaceId}` value object. Component and sheet are queried from the owning source/region products, never copied into the chart. Update `SourceChartTransitionGraph`, arrangement ownership, patch descriptors, lineage, validators, benchmarks, and tests to use that type.
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
