# Direct Surface-Cell Quadrangulation Architecture

**Status:** normative architecture  
**Scope:** the direct, source-authoritative, pure-quad surface-cell backend  
**Decision:** existing behavior may be verified, but new G4/G5 behavior must not extend the legacy authority model. All new work follows the staged migration in this document.

## 1. Document authority

This file defines architecture and invariants only. It intentionally contains no artifact IDs, run counts, current failure totals, or “next turn” instructions.

| Concern | Authoritative record |
|---|---|
| Normative product and architecture | this `DESIGN.md` |
| Current gate and next accepted action | `TODO` and `MILESTONE_G_TODO.md` |
| Exact next-session instructions | `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Runtime, build, and benchmark evidence | dated plan/report documents |
| Regression history and repeated patterns | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Point-in-time PR-wide audit evidence | `.agents/Directional/PR_8_Regression_Audit_Inventory.md` |

If a status record conflicts with this file, status does not redefine an architectural invariant. If two status records conflict, the newest evidence report governs and the status records must be reconciled before implementation resumes.

## 2. Product contract

Given a source triangle mesh, a degree-four directional field, exact source-feature constraints, and a target-size field, the backend produces a deterministic, source-attached, manifold pure-quad mesh.

Acceptance requires all of the following:

1. every output face is a quadrilateral;
2. output topology is derived from explicit source-topology and field-transport authority;
3. source components, boundaries, hard features, local isolation sheets, cuts, singularities, and periodic relations remain distinguishable;
4. every output vertex has auditable source support;
5. all owned topology regions, rail relations, isolation-seam certificates, and periodic relations are consumed exactly once or rejected with a typed failure;
6. output incidence, connected components, boundary loops, orientability, manifoldness, and Euler characteristic are computed from the materialized mesh rather than predicted;
7. fallback, recovery, and generic-producer substitution are absent from strict direct acceptance;
8. deterministic identity is invariant under source-face row enumeration, output emission order, container order, and thread scheduling;
9. work is bounded by a global, auditable budget with a monotone progress measure.

The backend replaces global mixed-integer coordinate integration. It does **not** claim to eliminate global discrete topology decisions. Shared rail subdivision, parity, holonomy, and quotient consistency are global combinatorial constraints and must be solved explicitly.

## 3. Architectural diagnosis

The recurring failures are not independent local bugs. They arise from one repeated architectural cycle:

1. a producer emits several partially overlapping representations of authority;
2. weakly typed integers, parallel vectors, booleans, hashes, and container positions carry semantic meaning;
3. a downstream consumer reconstructs missing topology or chooses among the representations;
4. a focused test validates the reconstructed proxy rather than the production certificate;
5. a more representative fixture changes enumeration, chart overlap, or the number of relations;
6. the previous proxy ceases to be equivalent to the source semantics;
7. a new field or consumer-side exception is added, increasing the next ambiguity.

The correction is a certificate-carrying, single-writer pipeline. Each stage owns one immutable output type, establishes explicit postconditions, and passes sufficient semantic evidence to the next stage. Downstream stages validate or consume authority; they never recreate it.

## 4. Scientific grounding

The architecture adopts the following established ideas without copying a reference pipeline wholesale.

### 4.1 Directional-field topology is explicit data

Vaxman et al., *Directional Field Synthesis, Design, and Processing* (2016), distinguish discretization from representation and show that principal matching alone can alias field topology. Period jumps, matchings, connections, singularity indices, and holonomy are discrete degrees of freedom. Therefore:

- field transport is a first-class algebraic object;
- a face chart, a local isolation sheet, and a source-topology region are separate domains;
- non-principal transport cannot be inferred from local geometry or a selected representative;
- cycle sums and non-contractible-cycle holonomy are verified explicitly.

### 4.2 MIQ supplies the transport algebra, not the backend architecture

Bommes, Zimmer, and Kobbelt, *Mixed-Integer Quadrangulation* (2009), cut the surface and construct a seamless parametrization whose cross-chart transitions are grid automorphisms. The surface-cell backend retains that precise algebra:

\[
T(p) = R_{90}^{r}p + t,\qquad r\in\mathbb Z_4,\quad t\in\mathbb Z^2.
\]

Rotation and translation are different typed values. Composition, inverse, canonicalization, and cycle closure are defined once. The backend does not replace them with an untyped route, a face choice, or a zero-rotation special case.

### 4.3 QEx supplies the exactness boundary

Ebke et al., *QEx: Robust Quad Mesh Extraction* (2013), separate input preprocessing, geometry extraction, and connectivity extraction. QEx sanitizes the numerical parametrization and transition functions before making deterministic local decisions with exact predicates; it also distinguishes triangle corners, extracted vertices, ports, connections, and halfedges.

For surface cells this implies:

- sanitize numeric source positions and barycentric coordinates once at the boundary;
- use exact source-simplex and combinatorial identities thereafter;
- keep corner occurrences separate from quotient vertices;
- extract connectivity from explicit relations, not world-space coincidence;
- give the validator certificates rather than asking it to repeat extraction.

### 4.4 QuadWild supplies the global-before-local conformity rule

Pietroni et al., *Reliable Feature-Line Driven Quad-Remeshing* (2021), construct a patch layout, solve a global integer program for shared patch-side tessellation and parity, and only then quadrangulate patches independently. The key reusable rule is ordering, not the particular ILP:

> all shared boundary subdivisions are decided once, globally, before any local producer commits cells.

The surface-cell backend therefore owns a `GlobalConformityPlan`. Independent region producers may not select hard-rail breakpoints and ask an aggregator to pair them afterward.

### 4.5 Instant Meshes and FlowRep delimit local heuristics

Jakob et al., *Instant Field-Aligned Meshes* (2015), demonstrate scalable local orientation and position fields. Those fields are valuable geometric proposals, but their proximity-based extraction and quad-dominant contract are not semantic topology authority for this backend.

Gori et al., *FlowRep* (2017), show that robust curve selection depends on global strand and cycle context, not only local edge alignment. This supports using global rail/cycle structure to plan cells, while keeping perceptual or curvature scores as quality objectives rather than validity criteria.

### 4.6 Existing implementations

- `libQEx` is the reference for explicit extraction entities and an exact-predicate boundary.
- `QuadWild` is the reference for phase separation and global side-count consistency before local tessellation.
- `Directional` is the reference for field matching, singularities, and transport metadata.
- the supplied AutoRemesher implementation is a useful comparison for field/parameterization/extraction staging, but its hole repair, largest-island selection, and triangle/n-gon emission are incompatible with strict direct pure-quad authority.

## 5. Normative pipeline

Each stage is a pure transformation over immutable inputs. A stage may create diagnostics, but diagnostics never influence semantic identity or acceptance.

| Stage | Input | Owned immutable output | Required postcondition |
|---|---|---|---|
| A0. Source authority | source mesh and feature metadata | `SourceAuthoritySnapshot` | exact support, incidence, components, sheets, barriers, and stable typed IDs are complete |
| A1. Field transport atlas | A0 and cross field | `FieldTransportAtlas` | every traversable adjacency has a typed transport; cycle and singularity facts are explicit |
| A2. Topology plan | A0–A1 | `GlobalTopologyPlan` | regions, cuts, rails, singularity ports, seam certificates, and holonomy ownership are complete |
| A3. Conformity plan | A0–A2 and target size | `GlobalConformityPlan` | every shared rail has one breakpoint sequence; side counts and parity are globally feasible |
| A4. Local construction | A0–A3 | `RegionCellComplex` per region | cells conform exactly to the supplied plan; no shared decision is recomputed |
| A5. Occurrence complex | all A4 outputs | `SurfaceOccurrenceComplex` | every cell corner and directed side is explicit; relations refer to occurrence IDs |
| A6. Quotient plan and materialization | A0–A5 | `QuotientCertificate` and quad mesh | only certified equivalences merge occurrences; one accepted cell maps to one output quad |
| A7. Geometry embedding | A0 and A6 | source-attached vertex geometry | every vertex has exact source support and remains on the intended source sheet |
| A8. Independent verification | A0–A7 | `VerificationReport` | all certificates, mesh invariants, lineage, and expected topology are independently checked |
| A9. Diagnostics/export | verified records | logs and public result | diagnostics are derived, stable, and cannot mutate authority |

No stage may write into an earlier stage's object. Aggregation is a new stage output, not normalization by mutation.

## 6. Canonical domain model

### 6.1 Strong IDs

Every semantic domain has a distinct type. Bare `int`, `uint64_t`, or `vector<int64_t>` is prohibited at public stage boundaries.

Minimum required domains:

```cpp
struct SourceVertexId;
struct SourceFaceId;
struct SourceEdgeTopologyKey;
struct InteriorTransitionId;
struct SourceComponentId;
struct IsolationSheetId;
struct TopologyRegionId;
struct FieldChartId;
struct HardRailId;
struct PeriodicRelationId;
struct CellId;
struct OccurrenceId;
struct QuotientClassId;
```

Conversion between domains requires a named function returning `expected<T, DomainError>`. Numeric coincidence is never a conversion.

### 6.2 Semantic identity versus representation handles

Semantic identity contains only source-invariant facts. Representation handles—vector offsets, emitted face rows, front-edge indices, local patch ordinals, completion backend IDs, hashes, and cache indices—are stored separately.

Rules:

1. equality and ordering of semantic objects never use representation handles;
2. hashes may accelerate lookup after equality is defined, but a hash is never the primary canonical order or identity;
3. reverse orientation is canonicalized with an explicit orientation bit, not rejected because its vector is lexicographically larger;
4. container order and object address never establish ownership;
5. cached “last” or “selected” values are derived from the canonical object and not stored as independent authority.

### 6.3 Exact source support

One shared source-support kernel classifies a point as a tagged value:

```cpp
using SourceSupport = std::variant<
    SourceVertexSupport,
    SourceEdgeSupport,
    SourceFaceInteriorSupport>;
```

It owns canonicalization, rebinding, equality, hashing, and incidence queries. Materialization, hard-rail pairing, chart resolution, ownership, and validation must use this kernel. Consumer-specific `1e-9` tests or `1e12` quantized keys cannot define identity.

Numerical tolerances may decide whether input is sanitizable. Once sanitized, topology keys are exact. A tolerance-derived value may be logged as geometry evidence but cannot be an ownership key.

### 6.4 Charts and transport

There is one `FieldChartId` type. Duplicate chart structs with reordered fields are prohibited.

```cpp
struct GridAutomorphism {
  QuarterTurn rotation;      // Z4
  LatticeTranslation shift;  // Z2
};

struct TransitionStep {
  SourceEdgeTopologyKey topology;
  std::optional<InteriorTransitionId> interior;
  GridAutomorphism transport;
  Orientation orientation;
};

struct CanonicalRoute {
  std::vector<TransitionStep> steps;
  Orientation canonicalOrientation;
};
```

Topology and the optional compact transition ID are one value object, never parallel vectors. A genuine one-face source boundary has topology and no interior transition. A two-face transport requires both. Route construction validates positional correspondence once.

### 6.5 Closed producer outcomes

A producer exposes exactly one state:

```cpp
template<class T>
using ProducerOutcome = std::variant<
    NotApplicable,
    Produced<T>,
    Rejected<ProducerFailure>>;
```

There are no public `attempted` or `succeeded` aliases. Construction uses named factories; consumers use exhaustive visitation. `Produced<T>` guarantees a nonempty, internally valid payload. `Rejected` guarantees a typed failure and no consumable partial product. Debug snapshots are a separate, explicitly non-semantic channel.

The dispatch rule is fixed:

- `NotApplicable`: the dispatcher may try the next declared producer;
- `Produced`: commit exactly this result;
- `Rejected`: stop; generic substitution is forbidden.

### 6.6 Certificates

Every non-local semantic decision is represented by a certificate with a verifier.

Required certificates include:

- `FieldTransportCycleCertificate`;
- `IsolationSeamTransportCertificate`;
- `PeriodicHolonomyCertificate`;
- `HardRailScheduleCertificate`;
- `RegionConformityCertificate`;
- `ChartSelectionCertificate`;
- `QuotientRelationCertificate`;
- `SourceSupportCertificate`;
- `MaterializationCertificate`.

A `ChartSelectionCertificate` records the selected component and the ordered canonical relation path for every participating occurrence. A boolean `witnessed` flag or reachable-set membership is not sufficient evidence.

## 7. Global topology and conformity

### 7.1 Separate region, sheet, and chart authority

- a **source-topology region** is a producer domain bounded by source boundaries, hard rails, or explicit cuts;
- an **isolation sheet** prevents unintended geometric cross-sheet interactions;
- a **field chart** is a local frame/transport domain;
- a **quotient class** is an output equivalence class of occurrences.

These concepts may correlate, but none is a numeric alias or representative for another.

### 7.2 Single-writer authority

`SourceAuthoritySnapshot` and `GlobalTopologyPlan` are referenced, not copied into multiple mutable aggregates. A consumer receives a `const` view or stable typed ID. Network, phase-front, materializer, and validator objects cannot each own divergent copies of face-region or sheet arrays.

Local producers construct fully scoped objects. An aggregator may verify scope and remap representation handles, but it may not overwrite source component, topology region, sheet membership, route, or relation semantics after production.

### 7.3 Hard-rail scheduling

All regions incident to a hard rail contribute requirements to one scheduling problem. The scheduler computes:

- a canonical ordered breakpoint sequence in exact source-rail coordinates;
- incident region/side ownership;
- target-size objective and permitted deviation;
- shared edge count;
- parity and 2:1 adaptivity constraints where enabled;
- singularity/feature endpoints that are fixed;
- a proof that both sides consume the identical sequence.

Only after the schedule verifies may region producers run. They consume breakpoint IDs and may not insert, remove, quantize, or reorder shared breakpoints. This is the architectural correction for target-size-dependent `InvalidHardRailPairing`.

The scheduler may use an ILP, dynamic program, or deterministic constrained graph algorithm. Solver choice is replaceable; the certificate and invariants are not.

### 7.4 Holonomy

Periodic transport is a complete grid automorphism. Zero rotation is an ordinary value, not a different representation. Composition around every owned cycle must match the declared holonomy. Nonzero `Z4` rotation remains unsupported until the canonical algebra, producers, quotient, and counterfactuals consume it end to end.

## 8. Occurrence and quotient architecture

Equal lattice coordinates or equal 3D positions do not imply equal output vertices. Each produced cell owns four distinct corner occurrences. Occurrences merge only through one of these certified relations:

1. reciprocal ordinary-front relation;
2. exact hard-rail relation using the shared schedule;
3. explicit periodic relation with grid automorphism;
4. singularity-port relation owned by the topology plan.

Every relation contains canonical endpoint occurrence IDs, source support, chart transport, orientation, and owner certificate ID. Front-edge positions and emission indices are optional provenance, not equality.

The quotient builder:

1. verifies every relation independently;
2. rejects duplicate, conflicting, unowned, or nonreciprocal relations;
3. computes equivalence classes with deterministic union order over canonical IDs;
4. proves every owned relation was consumed exactly once;
5. emits one vertex per verified class and one quad per accepted cell;
6. records a materialization certificate linking every output incidence to its source occurrences.

No world-space weld, post-hoc cell merge, representative-sheet selection, count/frequency ownership rule, or arbitrary subset search is allowed.

## 9. Validation architecture

Validation is an independent certificate verifier, not a second producer.

It may recompute elementary source incidence and output mesh topology from immutable inputs. It may not infer missing hard-rail endpoints from front-edge indices, reconstruct producer routes from whichever face is selected, or silently canonicalize malformed producer state.

Validation layers:

1. **schema:** typed IDs, closed outcomes, sorted/unique canonical sets, no dangling references;
2. **certificate:** transition, seam, rail, holonomy, chart-path, quotient, and materialization proofs;
3. **source attachment:** exact support and sheet/component constraints;
4. **mesh topology:** twins, orientation, manifoldness, connected components, boundary loops, Euler characteristic;
5. **product:** pure quads, one cell to one quad, complete lineage, no recovery/fallback;
6. **geometry:** inversion, self-intersection, size, alignment, and quality thresholds.

The verifier uses independently written checks at stage boundaries. Shared primitive types are allowed; reusing the producer's decision procedure as the validator is not independent evidence.

## 10. Determinism and complexity

### 10.1 Determinism

Canonical ordering uses semantic tuples of typed source identities. Hashes, object addresses, thread completion order, source-face row order, and output row order do not participate.

Metamorphic invariants are mandatory:

- source-face row permutation preserves semantic output digest;
- region and producer scheduling permutation preserves it;
- route reversal plus orientation inversion preserves relation identity;
- output vertex/face row permutation preserves it;
- changing source support, transport, connectivity, winding, or sheet separation changes it.

Raw hashes remain same-artifact diagnostics only.

### 10.2 Work ledger

Every recursive, retrying, or combinatorial stage owns a global `WorkLedger`:

```cpp
struct WorkLedger {
  std::size_t proposedStates;
  std::size_t committedStates;
  std::size_t rejectedStates;
  std::size_t remainingBudget;
  MonotoneMeasure measure;
};
```

Local limits nested inside outer loops do not bound total work. A stage must prove that each accepted edit decreases a lexicographic monotone measure or consumes a finite global budget. Exhaustion is a typed result with the last valid certificate set; timeout is never correctness evidence.

## 11. Module boundaries

The target source layout is responsibility-based:

```text
surface_cells/
  authority/       SourceAuthoritySnapshot, strong IDs, source support
  transport/       chart atlas, grid automorphisms, routes, cycle proofs
  planning/        topology plan, rail schedule, parity/conformity
  construction/    bounded region producers
  occurrence/      cells, corners, directed sides, relation registry
  quotient/        quotient plan and materialization
  verification/    independent certificate and mesh verifiers
  diagnostics/     derived reports and serialization
```

File size is not itself an invariant, but a module that combines producer selection, topology planning, canonicalization, materialization, validation, diagnostics, and fallback violates single ownership. New behavior is not added to the existing tracing, arrangement, or pipeline monolith unless it is an adapter that moves responsibility toward this layout.

## 12. Verification matrix

Every stage requires positive, negative, metamorphic, and representative evidence.

| Contract | Positive | Negative/tamper | Metamorphic | Representative |
|---|---|---|---|---|
| typed transition route | boundary and interior routes | domain substitution, missing paired topology | face-row and route-orientation permutation | seam and cylinder |
| producer outcome | each of three alternatives | inconsistent payload cannot be constructed | dispatch order does not change rejection | plane plus an unsupported input |
| rail schedule | two regions consume one schedule | independent breakpoint insertion | region order permutation | exact torus blocker fixture |
| chart certificate | chained multi-rail path | missing/duplicate/conflicting relation | source-face row permutation | torus completion |
| periodic relation | zero and nonzero rotation algebra | wrong inverse/owner/unconsumed relation | canonical route reversal | cylinder, then torus |
| quotient | explicit occurrence relations | proximity-only or equal-coordinate merge | emission order permutation | close sheets and torus |
| work ledger | bounded completion | multiplicative budget exhaustion | queue-order permutation | prescribed sphere |

Focused fixtures isolate contracts. Direct gate acceptance enters production preprocessing and remesh APIs with committed fixtures. A focused proxy cannot close a representative gate.

## 13. Migration plan

This is a strangler migration. Each slice is independently reviewable and preserves the last immutable runtime artifact as comparison authority. No big-bang rewrite is approved.

### M0 — preserve evidence

Run the already compiled multi-rail artifact exactly as its artifact-only plan requires. This records whether the current patch fixes `G4-R007`; it does not certify the legacy architecture. No source or test edit is mixed into this checkpoint.

### M1 — authority kernel and adapters

Introduce strong IDs, one chart type, `SourceSupport`, `TransitionStep`, `CanonicalRoute`, and grid-automorphism algebra behind compatibility adapters. Behavior is unchanged.

Acceptance:

- compile-only Code + Build;
- no public integer-domain conversion without a named checked function;
- adapter round-trip properties and compile-time non-convertibility tests;
- old runtime artifact remains the behavioral comparison baseline.

### M2 — seal producer state and single-writer snapshots

Replace `disposition + attempted + succeeded` with `ProducerOutcome<T>`. Replace duplicated region/sheet arrays with immutable authority snapshots and typed references. Aggregators validate rather than overwrite producer scope.

Acceptance:

- inconsistent producer states are unrepresentable;
- exhaustive dispatch tests cover all alternatives;
- no generic producer runs after `Rejected`;
- plane, seam, close sheets, and cylinder remain strict-valid.

### M3 — global conformity plan

Move hard-rail breakpoint and side-count selection before regional production. Producers consume one verified schedule.

Acceptance:

- exact shared-rail schedule positive/tamper tests;
- target-size variation cannot create different side breakpoints;
- the historical exact-torus `InvalidHardRailPairing` blocker is removed without post-hoc pairing;
- work and solver bounds are reported.

### M4 — certificate-carrying chart and quotient relations

Replace validator-side reachability reconstruction, boolean witness compression, front-edge equality, and parallel relation vectors with canonical relation IDs and explicit path certificates.

Acceptance:

- exact selected relation paths are retained and independently verified;
- unused valid relations do not alter the selected certificate;
- missing, duplicate, conflicting, nonreciprocal, and representation-renumbered relations fail typed;
- torus lineage and quotient acceptance are direct production evidence.

### M5 — independent verification and occurrence split

Separate occurrence creation, quotient construction, geometry embedding, and validation. Centralize exact source support and remove consumer-specific quantized identity.

Acceptance:

- validator consumes certificates and independently recomputes elementary incidence only;
- equal coordinates without a relation remain distinct;
- all owned relations are consumed exactly once;
- source-row, output-row, and scheduler permutation invariance passes.

### M6 — decompose monoliths and retire adapters

Move responsibilities to the target module layout, remove legacy duplicate types and caches, and make forbidden APIs unavailable.

Acceptance:

- no semantic identity is a generic integer vector;
- no public parallel topology/index route arrays remain;
- no semantic equality includes execution handles or backend choice;
- no architecture-debt item in the regression tracker remains open.

## 14. Stop conditions

Implementation stops for architectural review if any proposed change:

- adds another numeric ID domain without a strong type and checked conversion;
- adds a second copy of region, sheet, chart, route, or ownership authority;
- makes a consumer reconstruct producer semantics;
- uses a hash, container position, output row, or front-edge index as semantic identity;
- schedules a shared rail independently on two sides;
- weakens validation or fixture assertions to accommodate behavior;
- bounds an inner operation while leaving aggregate work multiplicative;
- encodes a representative-only or zero-rotation special case as the general model;
- passes a focused proxy while the representative production path remains unexecuted.

## 15. References

1. Amir Vaxman et al. “Directional Field Synthesis, Design, and Processing.” *Computer Graphics Forum* 35(2), 2016. See the [Directional project](https://avaxman.github.io/Directional/) and course materials.
2. David Bommes, Henrik Zimmer, and Leif Kobbelt. “Mixed-Integer Quadrangulation.” *ACM TOG* 28(3), 2009. [Project page](https://www.graphics.rwth-aachen.de/publication/0344/).
3. Hans-Christian Ebke et al. “QEx: Robust Quad Mesh Extraction.” *ACM TOG* 32(6), 2013. [Paper](https://graphics.rwth-aachen.de/media/papers/ebck2013_1.pdf) and [libQEx](https://github.com/hcebke/libQEx).
4. Nico Pietroni et al. “Reliable Feature-Line Driven Quad-Remeshing.” *ACM TOG* 40(4), 2021. [Project and paper](https://www.quadmesh.cloud/) and [QuadWild implementation](https://github.com/nicopietroni/quadwild).
5. Wenzel Jakob et al. “Instant Field-Aligned Meshes.” *ACM TOG* 34(6), 2015. [Project page](https://rgl.epfl.ch/publications/Jakob2015Instant).
6. Giorgio Gori et al. “FlowRep: Descriptive Curve Networks for Free-Form Design Shapes.” *ACM TOG* 36(4), 2017. [Project page](https://www.cs.ubc.ca/labs/imager/tr/2017/FlowRep/).

