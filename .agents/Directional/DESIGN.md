# Direct Surface-Cell Quadrangulation Architecture

**Status:** normative architecture  
**Scope:** the direct, source-authoritative, pure-quad surface-cell backend  
**Decision:** this experimental branch stores one authority contract per semantic fact. Existing behavior is evidence only; each replacement is an in-place producer-to-consumer cutover and the displaced contract is deleted in the same change.

## 1. Document authority

This file defines architecture and invariants only. It intentionally contains no artifact IDs, run counts, current failure totals, or “next turn” instructions.

| Concern | Authoritative record |
|---|---|
| Normative product and architecture | this `DESIGN.md` |
| Current gate and next accepted action | `TODO.md` |
| Exact next-session instructions | `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Runtime, build, and benchmark evidence | dated plan/report documents |
| Regression history and repeated patterns | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Point-in-time PR-wide audit evidence | `.agents/Directional/PR_8_Regression_Audit_Inventory.md` |
| Normative testing policy | `tests/TESTING_STRATEGY.md` |
| Test-suite audit findings and redesign order | `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` |

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
9. work is bounded by a global, auditable budget with a monotone progress measure;
10. field alignment, feature preservation, source-surface approximation, and
    element quality satisfy independently verified, explicitly calibrated
    acceptance criteria.

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

File size is not itself an invariant, but a module that combines producer selection, topology planning, canonicalization, materialization, validation, diagnostics, and fallback violates single ownership. New behavior belongs in the target modules. When an existing monolith must change, the affected ownership contract moves completely in that change; a retained bridge is not an architectural destination.

## 12. Verification matrix

Every stage requires positive, negative/tamper, metamorphic, independent
semantic, and representative evidence. Every mandatory test names its intent,
proves its semantic precondition, enters the public production API or named
stage, uses an independently written input/output oracle, rejects a deliberate
counterexample, and records its executable/fixture/seed/artifact identity.

| Contract | Positive | Negative/tamper | Metamorphic/property | Independent/representative |
|---|---|---|---|---|
| typed transition route | boundary and interior routes | domain substitution, missing paired topology | face-row, branch-label, and route-orientation permutation | seam and cylinder through the production entry |
| producer outcome | each of three alternatives | inconsistent payload cannot be constructed | dispatch and call-sequence order do not change rejection | plane plus typed unsupported/invalid inputs |
| rail schedule | two regions consume one schedule | independent breakpoint insertion | region order, uniform scale, and target-size perturbation | torus, thin tube, mechanical feature |
| chart certificate | chained multi-rail path | missing/duplicate/conflicting relation | source-face/cyclic-start permutation | torus completion with unused and off-face relations |
| periodic/singularity transport | zero/nonzero rotation algebra and declared indices | wrong inverse/index/owner/unconsumed relation | canonical reversal and quarter-turn branch relabeling | cylinder, torus, prescribed sphere |
| quotient/materialization | explicit occurrence relations | proximity-only/equal-coordinate merge | emission/component/thread-order permutation | close sheets and torus |
| product mesh | strict direct output | corrupted incidence, lineage, field, feature, and geometry | row, rigid-transform, scale, and triangulation-equivalence families | all ten committed triangle-mesh fixtures |
| work/resource ledger | bounded completion | cumulative/retry exhaustion | queue order and repeated success/failure sequences | sphere plus structured adversarial corpus |

Focused fixtures isolate contracts. Direct gate acceptance enters production
preprocessing and `remesh_from_raw_cross_field` with committed fixtures. A
focused proxy cannot close a representative gate.

## 13. Test architecture

Testing is a first-class architectural boundary. The normative policy is
`tests/TESTING_STRATEGY.md`; `TA-01` through `TA-12` and staged redesign
`T0` through `T6` are tracked in the independent test-suite audit.

Required evidence layers are:

1. type/schema and stage-contract tests;
2. deterministic generated properties with seed replay and shrinking;
3. metamorphic tests over representation, topology cycles, transforms,
   equivalent field branch labels, scheduling, and repeated-call sequences;
4. a test-only independent semantic verifier for topology, source support,
   certificates, direct disposition, geometry, and quality;
5. the complete committed ten-fixture direct production matrix;
6. structured invalid/robustness corpora and sanitizer fuzzing with minimized
   reproducers;
7. calibrated field, feature, approximation, element-quality, work, memory,
   and time gates.

The independent test oracle may share primitive math and typed schemas but may
not call the producer's acceptance decision or reuse its decision procedure.
`result.success`, a production-validator pass, an exact count, a raw ID/order,
an intermediate-retention state, or a hash is not sufficient product evidence.
Oracle-mutation tests must prove sensitivity to corrupted topology, lineage,
field/feature correspondence, geometry, quality, and backend disposition.

All portable mandatory tests and minimized replay cases are compiled and
discovered in the default immutable artifact. Toolchain-specific sanitizer
fuzz targets are mandatory in their declared Clang sanitizer artifact.
Labels may separate accepted required-green contracts from explicit known-red
product intent, nightly corpus/fuzz, and quality tiers; build options may not
hide mandatory authority. A known-red intent test is reported, not disabled or
counted as green.

## 14. Implementation transition

This branch is experimental and has no released surface-cell ABI or serialized schema to preserve. A semantic contract is replaced vertically from producer through verifier/materializer, and the displaced fields, helpers, and tests are removed in the same Code + Build turn. Immutable artifacts remain comparison evidence, but their internal numbering, hashes, row order, and incomplete product behavior are not design requirements.

### M0 — preserve evidence

M0 and T1 are complete historical prerequisites. Their artifacts remain evidence for regression classification and independent-oracle adequacy; they do not certify the pre-cutover architecture.

### M1 — single-authority contract cutover

Finish the authority transition in one Code + Build turn:

- checked strong-ID construction at mesh/container ingress;
- one source-chart value type and one exact `SourceSupport` identity;
- `TransitionStep`, `CanonicalRoute`, and `GridAutomorphism` as the only stored transport contract;
- one typed `SourceTopologyRegions` product referenced by cells, front edges, periodic/bounded-disk records, certificates, and occurrences;
- one fully typed isolation-seam certificate;
- one exhaustive producer outcome with no consumable partial payload;
- numeric projection only at direct container/Eigen access or derived export encoding;
- deletion of every displaced field, conversion helper, alias, and representation-only test.

Acceptance:

- compile-only Code + Build followed by separate immutable Test + Benchmark;
- `T1` package/oracle authority remains accepted;
- compile-time non-convertibility and checked-ingress boundary tests;
- positive, tamper, and permutation tests for region, chart, support, route, periodic, and certificate contracts;
- no duplicated semantic field or numeric bridge remains in the affected production/test surface;
- G0–G3 semantic invariants, truthful typed failures, deterministic identity, and strict no-fallback disposition remain valid;
- differences from the entering artifact are classified by product/design invariants rather than forced back to prior internal representation.

After M1 immutable acceptance, the primary queue returns to G4. M2–M5 are not a separate multi-turn representation campaign: when a G4/G5 blocker requires one of those contracts, the production change implements that complete vertical contract and its evidence together.

### M2 — closed stage products and single writers

Any remaining producer with overlapping state is replaced by one exhaustive outcome and one immutable stage product. Consumers reference the product and may validate it; they do not rewrite or reconstruct its semantics.

Acceptance:

- inconsistent outcomes are unrepresentable;
- exhaustive dispatch covers every alternative;
- `Rejected` is terminal and cannot trigger substitution;
- the affected direct product gate passes its independent oracle.

### M3 — global conformity plan

Move hard-rail breakpoint and side-count selection before regional production. Producers consume one verified schedule.

Acceptance:

- exact shared-rail schedule positive/tamper tests;
- target-size variation cannot create different side breakpoints;
- the exact-torus `InvalidHardRailPairing` blocker is removed without post-hoc pairing;
- work and solver bounds are reported.

### M4 — certificate-carrying chart and quotient relations

Replace verifier-side reachability reconstruction, boolean witness compression, front-edge equality, and relation-vector coupling with canonical relation IDs and explicit path certificates in one producer-to-consumer change.

Acceptance:

- exact selected relation paths are retained and independently verified;
- unused valid relations do not alter the selected certificate;
- missing, duplicate, conflicting, nonreciprocal, and representation-renumbered relations fail typed;
- torus lineage and quotient acceptance are direct production evidence.

### M5 — occurrence, embedding, and independent verification

Separate occurrence creation, quotient construction, geometry embedding, and validation as complete stage products. The verifier consumes certificates and independently recomputes elementary incidence; it never repairs producer state.

Acceptance:

- equal coordinates without a relation remain distinct;
- every owned relation is consumed exactly once;
- exact source support is shared without consumer-specific quantized identity;
- source-row, output-row, and scheduler permutation invariance passes.

### M6 — module boundaries and operational hardening

Move responsibilities to the target module layout and harden diagnostics, resource accounting, packaging, and CI after the owning product contracts are correct.

Acceptance:

- forbidden producer/verifier dependencies are unavailable;
- no semantic equality includes execution handles or backend choice;
- diagnostics cannot feed semantic decisions;
- no architecture-debt item in the regression tracker remains open.

## 15. Stop conditions

Implementation stops for architectural review if any proposed change:

- adds another numeric ID domain without a strong type and checked conversion;
- adds a second copy of region, sheet, chart, route, or ownership authority;
- makes a consumer reconstruct producer semantics;
- uses a hash, container position, output row, or front-edge index as semantic identity;
- schedules a shared rail independently on two sides;
- weakens validation or fixture assertions to accommodate behavior;
- bounds an inner operation while leaving aggregate work multiplicative;
- encodes a representative-only or zero-rotation special case as the general model;
- passes a focused proxy while the representative production path remains unexecuted;
- uses the producer's success decision or validator decision procedure as the
  independent test oracle;
- hides a mandatory direct/property/fuzz replay behind a default-off build
  option or loses its seed/corpus/package identity.

## 16. References

1. Amir Vaxman et al. “Directional Field Synthesis, Design, and Processing.” *Computer Graphics Forum* 35(2), 2016. See the [Directional project](https://avaxman.github.io/Directional/) and course materials.
2. David Bommes, Henrik Zimmer, and Leif Kobbelt. “Mixed-Integer Quadrangulation.” *ACM TOG* 28(3), 2009. [Project page](https://www.graphics.rwth-aachen.de/publication/0344/).
3. Hans-Christian Ebke et al. “QEx: Robust Quad Mesh Extraction.” *ACM TOG* 32(6), 2013. [Paper](https://graphics.rwth-aachen.de/media/papers/ebck2013_1.pdf) and [libQEx](https://github.com/hcebke/libQEx).
4. Nico Pietroni et al. “Reliable Feature-Line Driven Quad-Remeshing.” *ACM TOG* 40(4), 2021. [Project and paper](https://www.quadmesh.cloud/) and [QuadWild implementation](https://github.com/nicopietroni/quadwild).
5. Wenzel Jakob et al. “Instant Field-Aligned Meshes.” *ACM TOG* 34(6), 2015. [Project page](https://rgl.epfl.ch/publications/Jakob2015Instant).
6. Giorgio Gori et al. “FlowRep: Descriptive Curve Networks for Free-Form Design Shapes.” *ACM TOG* 36(4), 2017. [Project page](https://www.cs.ubc.ca/labs/imager/tr/2017/FlowRep/).
7. Qingnan Zhou and Alec Jacobson. “Thingi10K: A Dataset of 10,000 3D-Printing Models.” 2016. [Paper](https://arxiv.org/abs/1605.04797) and [dataset](https://github.com/Thingi10K/Thingi10K).
8. LLVM Project. [libFuzzer documentation](https://llvm.org/docs/LibFuzzer.html).
9. [RapidCheck](https://github.com/emil-e/rapidcheck), [libQEx reference tests](https://github.com/hcebke/libQEx/blob/517dcaa0cc87646baa89e52cfc8e23766776f6d5/tests/reference_meshes.cc), [Geometry Central intrinsic properties](https://github.com/nmwsharp/geometry-central/blob/019669ddabda05e0f71fa3587cfb3c1dadf19cb8/test/src/intrinsic_triangulation_test.cpp), and [CGAL remeshing tests](https://github.com/CGAL/cgal/blob/548fc90ea5d38402df679426283475ec78db0537/PMP_Remeshing/test/PMP_Remeshing/remeshing_test.cpp).
