# Direct Surface-Cell Quadrangulation Architecture
 
**Status:** normative architecture  
**Scope:** the direct, source-authoritative, pure-quad surface-cell backend  
**Decision:** this experimental branch stores one authority contract per semantic fact. Existing behavior is evidence only; each replacement is an in-place producer-to-consumer cutover and the displaced contract is deleted in the same change.
 
**Pipeline decision:** the backend implements **Pipeline B** (separatrix-derived topology, no global coordinate integration) as the default and only currently normative construction path. **Pipeline A** (single-solve decomposed coordinate integration) is a documented optional future path. Pipeline A is not implemented, not tested, and not a design requirement until Pipeline B is fully functional and producing production-level output against the committed representative matrix.
 
**Disposition decision:** the backend produces a **graded output disposition** rather than a binary accept/reject. Strict direct acceptance remains the highest and only certified tier. Below it, the pipeline emits the best structurally-sound mesh it can, explicitly labeled with its degradation, rather than failing hard. Only a small, enumerated set of catastrophic conditions produces no mesh at all. Degradation is never silent, never repairs upstream authority, and never relabels itself as certified.
 
## 1. Document authority
 
This file defines architecture and invariants only. It intentionally contains no artifact IDs, run counts, current failure totals, or "next turn" instructions.
 
| Concern | Authoritative record |
|---|---|
| Normative product and architecture | this `DESIGN.md` |
| Current gate and next accepted action | `TODO.md` |
| Checkpoint decomposition from the accepted gate to production-ready | `.agents/Directional/ROADMAP.md` |
| Exact next-session instructions | `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Runtime, build, and benchmark evidence | dated plan/report documents |
| Regression history and repeated patterns | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Point-in-time PR-wide audit evidence | `.agents/Directional/PR_8_Regression_Audit_Inventory.md` |
| Normative testing policy | `tests/TESTING_STRATEGY.md` |
| Test-suite audit findings and redesign order | `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` |
| Prior architecture findings this design answers | `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md` |
 
If a status record conflicts with this file, status does not redefine an architectural invariant. If two status records conflict, the newest evidence report governs and the status records must be reconciled before implementation resumes.
 
## 2. Product contract
 
Given a source triangle mesh, a degree-four directional field, exact source-feature constraints, and a target-size field, the backend produces a deterministic, source-attached, manifold pure-quad mesh together with an explicit disposition describing the strength of the guarantees that mesh carries.

### 2.1 Certified acceptance
 
A result is **Certified** only if all of the following hold:
 
1. every output face is a quadrilateral;
2. output topology is derived from explicit source-topology and field-transport authority;
3. source components, boundaries, hard features, local isolation sheets, cuts, singularities, and periodic relations remain distinguishable;
4. every output vertex has auditable source support;
5. all owned topology regions, rail relations, isolation-seam certificates, and periodic relations are consumed exactly once or rejected with a typed failure;
6. output incidence, connected components, boundary loops, orientability, manifoldness, and Euler characteristic are computed from the materialized mesh rather than predicted;
7. no region was constructed from a degraded, substituted, or relaxed plan; every region's construction consumed the certified global plan unmodified;
8. deterministic identity is invariant under source-face row enumeration, output emission order, container order, and thread scheduling;
9. work is bounded by a global, auditable budget with a monotone progress measure;
10. field alignment, feature preservation, source-surface approximation, and element quality satisfy independently verified, explicitly calibrated acceptance criteria.
Requirement 7 replaces the previous absolute prohibition on fallback. The prohibition was correct about its target — silent substitution masking producer defects — and that target is now enforced by disposition typing (§2.2) rather than by refusing to emit anything. Certified output still contains no fallback, recovery, or generic-producer substitution of any kind.
 
### 2.2 Output disposition ladder
 
Every run terminates in exactly one typed disposition. Dispositions are totally ordered; the pipeline emits the **highest tier it can establish by verification**, never a tier it merely hopes holds.
 
| Tier | Name | Mesh emitted | Guarantees |
|---|---|---|---|
| D0 | `Certified` | pure quad, complete | all of §2.1 |
| D1 | `QualityRelaxed` | pure quad, complete | §2.1 items 1–9; one or more calibrated quality gates (item 10) missed, each named with its measured value |
| D2 | `LocallyDegraded` | pure quad, complete | §2.1 items 1–6, 8, 9; one or more regions constructed by a named degraded producer; every such region individually identified |
| D3 | `Partial` | pure quad, incomplete | §2.1 items 1–6, 8, 9 hold **on the emitted subset**; one or more regions omitted, leaving boundary loops where they were; every omitted region identified with its typed failure |
| D4 | `DiagnosticOnly` | none | no mesh; typed failure record and last valid certificate set only |
 
Rules that hold across the ladder:
 
1. **Verification, not intent, assigns the tier.** The disposition is computed by the independent verifier (§9) from the materialized product, never asserted by a producer or by the orchestrator.
2. **Monotone truthfulness.** A run may only ever move *down* the ladder as it proceeds. No stage may raise a disposition. A tier once lowered is never restored within the same run.
3. **Degradation is data.** Every drop from D0 carries a `DegradationCertificate` (§6.7) naming the stage, the owning region or gate, the typed cause, and the substitution actually applied. A disposition without a complete degradation record is itself a verification failure and forces D4.
4. **No upstream mutation.** Degradation may only affect construction *at or below* the stage where it is triggered. It may never edit, repair, re-solve, or re-derive an earlier stage's immutable product. Stage products remain single-writer under all dispositions.
5. **Degraded output is never certified output.** D1–D3 results are structurally usable meshes. They are not evidence that the strict path works, may not close a strict gate, and may not be compared against certified baselines as equivalents.
6. **Determinism applies at every tier.** The metamorphic invariants of §10.1 hold for D1–D3 output exactly as for D0, including which regions degraded and how.
7. **Degradation is bounded.** Each degradation is a single, finite, non-recursive substitution. A degraded producer may not itself degrade further, and degradation may not be retried. This keeps the work ledger (§10.2) valid under all dispositions.
### 2.3 Catastrophic conditions
 
D4 is reserved for conditions under which no emitted mesh could be meaningfully interpreted. The set is closed and enumerated:
 
- `SourceAuthorityUnestablished` — A0 cannot produce exact support, incidence, or component structure for the input after sanitization;
- `FieldTransportUnestablished` — A1 cannot produce a typed transport for the traversable adjacency, or the field fails the quadrangulability precondition (§7.5);
- `NoRegionConstructed` — A4 produced zero accepted regions, so there is no subset to emit;
- `VerifierIntegrityFailure` — the verifier's own invariants fail, so no claim about the output can be trusted at any tier;
- `BudgetExhaustedBeforeFirstRegion` — the global work budget was consumed before any region completed.
Nothing outside this list is catastrophic. In particular, an infeasible conformity plan, a failed region, a violated quality threshold, an unconsumed relation, and an exhausted per-region budget are all *non-catastrophic* and resolve to D1–D3.
 
### 2.4 Scope of the discrete problem
 
The default backend (Pipeline B) replaces global mixed-integer coordinate integration entirely. It does **not** claim to eliminate global discrete topology decisions. Shared rail subdivision, parity, holonomy, and quotient consistency are global combinatorial constraints and must be solved explicitly — but as graph and flow problems over an `O(n)` structure, not as integer variables inside a linear system.
 
Pipeline A (§16) reintroduces coordinate integration in a restructured form and is out of scope until Pipeline B is production-level.
 
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
 
Graded disposition does not weaken this correction. The failure mode the strict rule guarded against was *silent* substitution — a consumer quietly filling a gap and a test then validating the fill. Under §2.2 a substitution is a typed, verified, independently reported product fact that lowers the run's tier, so it cannot be mistaken for correct behavior by a test, a gate, or a reader.
 
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
 
MIQ's *solver* structure is explicitly not adopted by Pipeline B. Iterative rounding re-solves the parametrization system once per integer variable; that cost structure is the motivating reason the default path carries no integer variables in any linear system.
 
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
 
### 4.5 Combinatorial tracing supplies the network primitive
 
Ray and Sokolov, *Robust Polylines Tracing for N-Symmetry Direction Field on Triangulated Surfaces* (2014), trace field-aligned polylines that provably cannot cross or merge. Each triangle boundary is decomposed into inflow and outflow intervals; the pairing is resolved by a guaranteed combinatorial algorithm, and barycentric positions propagate in arbitrary precision rather than by numerical integration.
 
This is the normative tracing primitive for A2a. Its properties are exactly the ones the architecture requires elsewhere: the branch decision is combinatorial rather than a nearest-direction heuristic, positions are exact barycentric values compatible with `SourceSupport`, and the non-crossing guarantee is structural rather than a post-hoc repair.
 
**Grazing edges — the piecewise-constant case Ray and Sokolov's continuum statement does not cover.** Where a triangle's inflow/outflow decomposition is read from a piecewise-constant per-face field, a shared edge may be an outflow interval of **both** incident triangles. The field is then nearly parallel to that edge on both sides, and no crossing occurs. A trace reaching such an edge neither crosses it nor stops on it: it **transits along the edge** to the endpoint that both incident directions drive the edge parameter toward, and re-enters the vertex rule there — terminating if that vertex is a singularity, re-emitting through the vertex sector rule otherwise. A hard rail still wins: if the edge is a mandatory edge the trace terminates on first contact and is never slid along.
 
Four properties are load-bearing and each is checkable rather than assumed:
 
- **the decision is exact and combinatorial.** The three-way relation of a carrier to a face (inflow, tangent, outflow) is the sign of that face's published barycentric direction at the coordinate opposite the carrier, and the transit endpoint is the common sign of the two faces' rates of change of the edge parameter. No tolerance, threshold, or magnitude comparison participates. Disagreement between the two faces is a typed rejection, never a tie-break.
- **the transit is one step.** The direction is constant per face, so the grazing condition and both parameter rates are constant along the whole edge. The slide is monotone and reaches an endpoint in a single step; the tracing model acquires no edge-following state.
- **it is the continuous extension of the exactly-tangent case.** When the entry face's direction is exactly tangent to the entry edge, the trace already travels along that edge and exits at a vertex — the same vertex, selected by the same expression. A model that terminated on grazing would be discontinuous across a measure-zero configuration.
- **non-crossing is preserved; non-merging is a measurement.** A transit lies on an edge and creates no interior crossing. Two traces entering the same grazing edge would overlap along it, so the count of traces per grazing edge is an observation the stage must publish, not an assumption it may make.
 
### 4.6 The motorcycle graph supplies the region-decomposition guarantee
 
Eppstein, Goodrich, Kim, and Tamstorf, *Motorcycle Graphs: Canonical Quad Mesh Partitioning* (2008), define a canonical partition in which each trace terminates on first contact with an existing trace. For fields with at least one singularity port or a source boundary, that traced network supplies the intended cell decomposition. On a closed index-free surface, however, A2a may legitimately publish a non-cellular or even empty curve network; disc-region authority then comes from the separate A2a′ `SurfaceCutGraph`, derived from source topology and the immutable A2a network before any region exists.
 
Three consequences are load-bearing here:
 
- **termination and cleanliness by construction.** Crash-on-contact removes limit cycles and non-terminating traces structurally. The architecture does not contain a "detect and repair limit cycles" step because it does not create them.
- **disc topology by construction when the traced network is cellular.** For closed index-free surfaces, A2a′ completes the immutable A2a network to a cellular embedding before region derivation; region validity (§7.2) is still a property of the decomposition, not a post-region repair.
- **the conformity plan is the same object.** The decomposition is describable as an `O(n)` graph whose nodes are region corners, whose edges are shared boundary arcs between two regions, and whose edge labels are subdivision counts along those arcs. That is precisely `GlobalConformityPlan`.
Minimizing the number of regions is NP-hard but efficiently approximable; the architecture therefore treats region count as a quality objective, never a validity condition.
 
**The termination guarantee is conditional, and its condition is named.** The motorcycle argument above assumes motorcycles walking the edge chains of an *existing quadrilateral mesh*, where every step consumes an edge and non-termination is impossible by counting. A2a is one stage earlier: it traces a piecewise-constant field on a triangle mesh, carrying an exact position in face interiors. That is a one-dimensional dynamical system and it does admit limit cycles — one is exhibited on the prescribed sphere witness, with an exactly affine, provably contracting first-return map around a closed circuit. Crash-on-contact still terminates every such trace there, but for a different reason than the counting argument: the **perpendicular branch family** crosses a circulating trace almost immediately, and branches `b` and `b±1` cross transversally while `b` and `b+2` never can. On a field with a minimal component the perpendicular family does not save it, and the outcome is a field-quadrangulability judgement under §4.10 and §7.5 — a graded disposition, never a silent truncation.
 
Two consequences are load-bearing and must not be softened. **A trace's own self-contact cannot serve as the stopping rule**: the field direction is one constant vector per `(face, branch)`, so two visits to the same face on the same branch lay down parallel segments that can never cross. And **no length budget derived from the mesh may terminate a trace**: measured on the prescribed sphere, the longest correctly terminating trace and one lap of a never-terminating trace have the same arc length to four decimal places, so length carries no information about whether a trace will terminate. A trace stopped by a length budget also ends at a point that is neither a singularity, a rail, nor a contact, leaving an arc that bounds no region and breaking §7.2's disc validity by construction. Trace length is a diagnostic and a disposition input only.
 
### 4.7 Interval assignment is a flow problem, not an ILP
 
Campen, Bommes, and Kobbelt, *Quantized Global Parametrization* (2015), show that the per-cell consistency conditions — opposite sides of a cell must sum to equal parametric length — form an underdetermined homogeneous linear Diophantine system whose coefficients are drawn from `{-1, 0, 1}` with exactly two non-zeros per column, and that navigating its solution space by generating vectors admits a deterministic Dijkstra-type algorithm rather than branch-and-bound. They further note that for a decomposition without T-junctions the generating vectors are orthogonal, coefficients are chosen independently per dual cycle, and *processing order does not matter*.
 
Heistermann, Warnett, and Bommes, *Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization* (2023), reformulate the same assignment as a minimum-deviation-flow problem in bi-directed networks, solvable in polynomial time by a dedicated solver rather than a generic branch-and-cut solver.
 
This is the normative basis for A3. It matters for two independent reasons: the assignment is decided without any linear-algebra factorization, and a polynomial flow or min-weight-cycle formulation supplies the monotone progress measure that §10.2 requires and that a generic ILP cannot.
 
### 4.8 Exact combinatorial coordinates supply the support kernel
 
Gillespie, Sharp, and Crane, *Integer Coordinates for Intrinsic Geometry Processing* (2021), encode curve/edge crossing structure as one integer per edge, avoiding floating-point data entirely and guaranteeing that the structure always encodes a valid subdivision. Intrinsic mollification adds a bounded slack to edge lengths so that all triangles satisfy the triangle inequality, changing geometry only where a triangle is within tolerance of degenerate.
 
This is the normative implementation basis for the `SourceSupport` kernel (§6.3) and for A0 sanitization. Mollification is the sanitization boundary; integer coordinates are the exact identity carried afterward.
 
### 4.9 Injective region interiors are available without optimization
 
Fu et al., *Inversion-free Geometric Mapping Construction: A Survey* (2021), survey the constrained non-convex optimization normally required to guarantee inversion-free maps. For the specific case this architecture produces — a disc region whose boundary has been fixed to a convex integer rectangle by A3 — Tutte's barycentric embedding yields a guaranteed-injective interior with no optimization and no failure branch, as used for the same purpose by Zhou et al., *Combinatorial Construction of Seamless Parameter Domains* (2020).
 
The architecture therefore treats guaranteed injectivity and distortion-minimizing quality as *separate* concerns with separate mechanisms, rather than depending on one optimizer for both.
 
### 4.10 Field quadrangulability is a checkable precondition
 
Campen, Shen, Zhou, and Zorin, *Seamless Parametrization with Arbitrary Cones for Arbitrary Genus* (2019), establish that for topologically admissible cone sets a solution generally exists, and observe that convexified constraints can render solvable instances apparently infeasible. Shen et al., *Which Cross Fields Can Be Quadrangulated?* (2022), relate cross-field topology to parametrization topology directly.
 
Two architectural consequences: infeasibility encountered downstream should be presumed an artifact of over-constraint or discretization rather than of the input, and the admissibility of the field is a **precondition** verified at A1 (§7.5), not a discovery made at A3.
 
### 4.11 Instant Meshes and FlowRep delimit local heuristics
 
Jakob et al., *Instant Field-Aligned Meshes* (2015), demonstrate scalable local orientation and position fields. Those fields are valuable geometric proposals, but their proximity-based extraction and quad-dominant contract are not semantic topology authority for this backend.
 
Gori et al., *FlowRep* (2017), show that robust curve selection depends on global strand and cycle context, not only local edge alignment. This supports using global rail/cycle structure to plan cells, while keeping perceptual or curvature scores as quality objectives rather than validity criteria. FlowRep's published algorithm consumes an existing quad-dominant mesh and is therefore not adoptable as a generator here; only its network-selection principle transfers.
 
### 4.12 Existing implementations
 
- `libQEx` is the reference for explicit extraction entities and an exact-predicate boundary.
- `QuadWild` is the reference for phase separation and global side-count consistency before local tessellation.
- `libSatsuma` is the reference implementation for bi-directed min-deviation-flow assignment.
- `geometry-central` is the reference implementation for integer/normal coordinates and intrinsic mollification.
- `Directional` is the reference for field matching, singularities, and transport metadata.
- the supplied AutoRemesher implementation is a useful comparison for field/parameterization/extraction staging, but its hole repair, largest-island selection, and triangle/n-gon emission are incompatible with pure-quad authority at any disposition tier.
## 5. Normative pipeline — Pipeline B
 
Each stage is a pure transformation over immutable inputs. A stage may create diagnostics, but diagnostics never influence semantic identity or acceptance.
 
| Stage | Input | Owned immutable output | Required postcondition |
|---|---|---|---|
| A0. Source authority | source mesh and feature metadata | `SourceAuthoritySnapshot` | exact support, incidence, components, sheets, barriers, and stable typed IDs are complete; sanitization is recorded |
| A1. Field transport atlas | A0 and cross field | `FieldTransportAtlas` | every traversable adjacency has a typed transport; cycle and singularity facts are explicit; quadrangulability precondition is decided |
| A2a. Field-aligned curve network | A0–A1 | `FieldAlignedCurveNetwork` | every required singularity port is owned once; every trace is branch-consistent, non-crossing, and terminates at a typed network event |
| A2a′. Surface cut graph | A0–A2a | `SurfaceCutGraph` | the immutable field-aligned network plus deterministic source-edge cuts is a certified cellular embedding; already-cellular input publishes an empty cut set |
| A2b. Topology plan | A0–A2a′ | `GlobalTopologyPlan` | regions, cuts, rails, singularity ports, seam certificates, and holonomy ownership are complete; every region is a disc unless explicitly typed otherwise |
| A3. Conformity plan | A0–A2b and target size | `GlobalConformityPlan` | every shared rail has one positive breakpoint sequence; side counts and parity are globally feasible |
| A4. Local construction | A0–A3 | `RegionCellComplex` per region | cells conform exactly to the supplied plan; no shared decision is recomputed |
| A5. Occurrence complex | all A4 outputs | `SurfaceOccurrenceComplex` | every cell corner and directed side is explicit; relations refer to occurrence IDs |
| A6. Quotient plan and materialization | A0–A5 | `QuotientCertificate` and quad mesh | only certified equivalences merge occurrences; one accepted cell maps to one output quad |
| A7. Geometry embedding | A0 and A6 | source-attached vertex geometry | every vertex has exact source support and remains on the intended source sheet |
| A8. Independent verification | A0–A7 | `VerificationReport` and `OutputDisposition` | all certificates, mesh invariants, lineage, and expected topology are independently checked; the disposition tier is computed, not asserted |
| A9. Diagnostics/export | verified records | logs and public result | diagnostics are derived, stable, and cannot mutate authority |
 
No stage may write into an earlier stage's object. Aggregation is a new stage output, not normalization by mutation.
 
### 5.1 Stage cost structure
 
The default path contains **no global linear system and no numeric factorization**. A0 and A1 are linear passes. A2a is combinatorial tracing in exact arithmetic. A2a′, A2b, and A3 are graph and flow problems over an `O(n)` structure. A4 is local and parallel per region. A5–A9 are combinatorial. This property is normative: any proposed change that introduces a global factorization into the default path is a stop condition (§15) and belongs in Pipeline A instead.
 
### 5.2 Degradation points
 
Degradation is permitted at exactly four points, each with one named substitution and one resulting tier:
 
| Trigger | Stage | Permitted substitution | Resulting tier |
|---|---|---|---|
| a quality gate is missed but all structural certificates verify | A8 | none; the mesh is emitted as-is with measured values | D1 |
| a region producer returns `Rejected` | A4 | that region only is built by the declared degraded producer | D2 |
| a region has no degraded producer, or the degraded producer also fails | A4 | that region only is omitted; its rails become boundary loops | D3 |
| the conformity plan is infeasible for a rail subset | A3 | the affected rails' regions are marked non-constructible; construction proceeds for the remainder | D3 |
 
No other stage may degrade. A0, A1, A2a, A2a′, A2b, A5, A6, A7, and A9 have no degraded mode: a failure at those stages is either catastrophic (§2.3) or is a defect to be fixed, never worked around.
 
### 5.3 The degraded region producer
 
Exactly one degraded producer is declared, and its contract is deliberately minimal:
 
- it consumes the same immutable `GlobalConformityPlan` rails as the strict producer, unmodified;
- it emits pure quads only;
- it produces cells conforming exactly to the already-fixed boundary breakpoints, so neighbouring regions are unaffected and the quotient stage sees no difference in relation structure;
- it makes no field-alignment, feature-preservation, or element-quality claim;
- it is bounded, non-recursive, and cannot itself degrade;
- it emits a `DegradationCertificate` naming the region and the strict producer's typed failure.
Its purpose is to keep the output mesh complete and manifold, not to be good. Regions it builds are individually identified in the verification report so their quality is never averaged silently into the whole.
 
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
struct SingularityId;
struct FieldBranch;
struct NetworkNodeId;
struct TraceId;
```
 
Conversion between domains requires a named function returning `expected<T, DomainError>`. Numeric coincidence is never a conversion.
 
### 6.2 Semantic identity versus representation handles
 
Semantic identity contains only source-invariant facts. Representation handles—vector offsets, emitted face rows, front-edge indices, local patch ordinals, completion backend IDs, hashes, and cache indices—are stored separately.
 
Rules:
 
1. equality and ordering of semantic objects never use representation handles;
2. hashes may accelerate lookup after equality is defined, but a hash is never the primary canonical order or identity;
3. reverse orientation is canonicalized with an explicit orientation bit, not rejected because its vector is lexicographically larger;
4. container order and object address never establish ownership;
5. cached "last" or "selected" values are derived from the canonical object and not stored as independent authority.
### 6.3 Exact source support
 
One shared source-support kernel classifies a point as a tagged value:
 
```cpp
using SourceSupport = std::variant<
    SourceVertexSupport,
    SourceEdgeSupport,
    SourceFaceInteriorSupport>;
```
 
It owns canonicalization, rebinding, equality, hashing, and incidence queries. Materialization, hard-rail pairing, chart resolution, ownership, and validation must use this kernel. Consumer-specific `1e-9` tests or `1e12` quantized keys cannot define identity.
 
Numerical tolerances may decide whether input is sanitizable, and A0 mollification is the single place where they do so. Once sanitized, topology keys are exact and are carried as integer combinatorial coordinates. A tolerance-derived value may be logged as geometry evidence but cannot be an ownership key.
 
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
- `Rejected`: stop; **generic substitution is forbidden**.
This is unchanged by graded disposition, and the distinction is the crux of the design. A producer never substitutes for another producer, never emits a partial payload, and never softens its own failure. Degradation is not a producer behavior at all: it is a decision taken one level up, by the disposition stage (§6.7), which observes a terminal `Rejected`, records it, and invokes a *separately declared, explicitly named* degraded producer whose output is labeled as such. `Rejected` remains terminal for the strict producer that emitted it.
 
### 6.6 Certificates
 
Every non-local semantic decision is represented by a certificate with a verifier.
 
Required certificates include:
 
- `FieldTransportCycleCertificate`;
- `FieldQuadrangulabilityCertificate`;
- `CurveNetworkCertificate`;
- `IsolationSeamTransportCertificate`;
- `PeriodicHolonomyCertificate`;
- `HardRailScheduleCertificate`;
- `RegionConformityCertificate`;
- `ChartSelectionCertificate`;
- `QuotientRelationCertificate`;
- `SourceSupportCertificate`;
- `MaterializationCertificate`.
A `ChartSelectionCertificate` records the selected component and the ordered canonical relation path for every participating occurrence. A boolean `witnessed` flag or reachable-set membership is not sufficient evidence.
 
### 6.7 Disposition and degradation
 
Disposition is a first-class stage product, not a status flag.
 
```cpp
enum class DispositionTier { Certified, QualityRelaxed, LocallyDegraded, Partial, DiagnosticOnly };
 
struct DegradationCertificate {
  StageId               stage;
  DegradationScope      scope;        // whole-run gate, or one TopologyRegionId
  ProducerFailure       cause;        // the terminal typed failure observed
  SubstitutionKind      substitution; // None | DegradedRegionProducer | RegionOmitted
  DispositionTier       impliedTier;
};
 
struct OutputDisposition {
  DispositionTier                        tier;
  std::vector<DegradationCertificate>    degradations;
  std::vector<QualityGateResult>         gateResults;   // measured values, not booleans
  std::optional<CatastrophicCause>       catastrophic;  // set iff tier == DiagnosticOnly
};
```
 
Invariants:
 
1. `tier` equals the minimum of `Certified` and every `impliedTier` present in `degradations`; the verifier recomputes this rather than trusting a stored value;
2. `degradations` is empty if and only if `tier` is `Certified` or `QualityRelaxed` with all gates passed;
3. every `DegradationCertificate` whose scope is a region names a region that exists in the topology plan and, for `RegionOmitted`, is absent from the materialized mesh;
4. `catastrophic` is set if and only if the tier is `DiagnosticOnly`, and its value is drawn from the closed set in §2.3;
5. `gateResults` records measured values for every calibrated gate whether or not it passed, so a relaxation is quantified rather than merely flagged;
6. `OutputDisposition` is immutable once emitted and is part of the exported public result.
The disposition stage is the **only** component permitted to observe a `Rejected` outcome and continue. It may not inspect, repair, or reinterpret the rejected payload — `Rejected` carries no consumable product — and may only choose between the two declared substitutions or omission.
 
## 7. Global topology and conformity
 
### 7.1 Separate region, sheet, and chart authority
 
- a **source-topology region** is a producer domain bounded by source boundaries, hard rails, or explicit cuts;
- an **isolation sheet** prevents unintended geometric cross-sheet interactions;
- a **field chart** is a local frame/transport domain;
- a **quotient class** is an output equivalence class of occurrences.
These concepts may correlate, but none is a numeric alias or representative for another.
 
### 7.2 The curve network and region derivation
 
`GlobalTopologyPlan` regions are derived, not assumed. The derivation is normative:
 
1. create ports from every cross-field singularity, with port count derived from the field index;
2. create mandatory graph edges from hard features and source boundaries;
3. trace the designated field branch from every singularity port using the combinatorial tracing primitive (§4.5);
4. transport the branch intrinsically across source triangles, maintaining branch consistency;
5. terminate each trace on first contact with an existing trace, a boundary, a feature, or a singularity — never in a regular face interior;
6. record every trace intersection as an explicit network node;
7. globally select and simplify the candidate network subject to the mandatory topology being preserved;
8. before any region exists, consume the A2a′ `SurfaceCutGraph`, which deterministically adds only certified source-edge cuts needed to make the immutable A2a network a cellular embedding;
9. extract the faces of that certified cellular embedding (field-aligned network plus cut graph);
10. emit those faces as topology regions.
Invariants on `FieldAlignedCurveNetwork`:
 
1. every required singularity port is owned exactly once;
2. every trace maintains branch-consistent transport along its full length;
3. no trace terminates silently in a regular face interior;
4. trace intersections create explicit graph nodes;
5. feature and boundary constraints are first-class graph edges;
6. every selected curve bounds one or two regions as appropriate;
7. every resulting region has disc topology unless explicitly typed otherwise; on closed index-free surfaces this invariant is supplied by the certified A2a′ cut graph rather than by A2a alone;
8. network reduction may remove redundant traces but may not alter required singularity index or port topology.
Because tracing is combinatorial and terminates on contact, invariant 3 holds by construction. Invariant 7 holds directly when A2a is already cellular and otherwise through the certified A2a′ cut graph before region derivation. The architecture contains no limit-cycle detection, tiny-region collapse, post-`GlobalTopologyPlan` re-cut, or non-disc region repair step; adding one is a stop condition because it would repair an immutable upstream product. A2a′ is not such a repair: it is the single pre-region authority that completes a closed index-free embedding without changing A2a.
 
#### 7.2.1 Amendment record — normative

Amendments 12–14 refine §7.2 steps 8–10 and were declared in the CP4c-2 frozen-definition documents; Amendment 15
was declared at `M3-CP4c-3-DEFN-R1` and governs how A1 derives a region's transport domain, and Amendment 16 at
`M3-CP4c-3-TB2-REV` generalizes it to every derivation that walks transport in any stage (scope widened at
`M3-CP4c-3-TB3-R1-REV`); Amendment 17 at `M3-CP4c-3-TB4-REV` governs how an election among candidate cells is
decided, and Amendments 18-19 at `M3-CP4c-3-TB5-REV` govern the provenance of values reaching a topological
decision and the reportability of every producer exit. They are normative and
are recorded here so §7.2 can be read without them being lost. This subsection is additive: nothing above it is
withdrawn except where an amendment says so explicitly.

- **Amendment 12 — precondition, not repair.** Establishing a precondition *before* a product is derived is not
  repairing that product afterward. A2a′ runs before any region exists and may not read a `GlobalTopologyPlan`.
  Source: `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`; restated in `…DEFN_R1…` §3.5.
- **Amendment 13 — the normative complex.** A2a′ certifies cellularity in the **actual embedded graph** of
  `FieldAlignedCurveNetwork ∪ cutEdges`: vertices are network nodes plus nodes created by cuts, edges are network
  arcs plus cut arcs, faces are the **dart orbits** under the node rotation system. Source-edge carrier provenance
  is not graph-edge authority. The whole-source-face / source-edge-barrier partition is **withdrawn as cellularity
  authority** and survives only as a cut-proposal heuristic and diagnostic provenance, and every publication of it
  must say so. Source: `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` §3.
- **Amendment 14 — trace-crossed cut admissibility, and completeness.** A source edge crossed by a trace at an
  interior point **is** an admissible cut; promoting it adds one arc per sub-interval between consecutive crossings
  and one cut-created node per crossing, subdividing the trace **in the derived arrangement only**. The immutable
  network — its traces, segments, events and digests — is unchanged. The admissible cut set is therefore every
  source edge that is not already a graph arc. Consequently `network ∪ (source 1-skeleton)` is a cellular
  embedding, a sufficient cut set always exists, and step 8's "certified source-edge cuts" is a total contract
  rather than a conditional one. Source: `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` §§3, 5.
- **Amendment 15 — a topology region's transport domain is the region cut along its non-separating barriers.**
  A region's face set, its published `euler_characteristic()` and its published `boundary_loop_count()` are facts
  about the **uncut** source complex and are unchanged. A1's tangent bundle, cycle basis and index quantities are
  derived instead from the region's **transport domain**: the region **cut along**
  `B(R) = { e ∈ hardFeatureEdges : both faces incident to e belong to R }`, its non-separating barrier set.
  Four consequences are normative.
  1. **`B(R)` is the whole defect class.** A source-boundary edge and a region- or component-crossing edge each
     have at most one incident face in `R`, so both are already local boundary edges; a traversable edge has an
     adjacency. Only a hard-feature edge can be non-traversable *and* interior to a region. Isolation seams —
     same region, same component, different sheet — are traversable by design and are **not** barriers.
  2. **The cut never disconnects.** A region is a connected component of the face graph built *without* barrier
     edges, so cutting along `B(R)` leaves that graph untouched. It follows that no subset of `B(R)` separates
     `R`, and hence that on a region with `χ = 2, b = 0` every component of `B(R)` is a tree.
  3. **The cut is a face-array rewrite with a fixed endpoint rule.** A vertex `v` incident to `B(R)` is duplicated
     into one copy per connected component of `star(v) ∖ B(R)`: `copies(v) = d_B(v)` for `v` interior,
     `d_B(v) + 1` for `v` on the region's local-mesh boundary. An open arc's **tip** has `d = 1` and is therefore
     **not** duplicated — the cut surface genuinely touches itself there — but it does become a boundary vertex.
     The result is a manifold with boundary; geometry does not move.
  4. **The arithmetic is an identity, not a coincidence:** `χ(R_cut) = χ(R) − χ(B) + ∂`, where `χ(B) = |V(B)| −
     |B|` and `∂` counts `B`'s vertices already on the region's boundary. Barrier edges become boundary edges,
     leave `dual_cycles`' inner-edge columns, and can no longer demand a transport adjacency — so a barrier can
     never again raise `CycleTransportAdjacencyMissing`.

  The amendment is **not free** and its costs are normative too: A1's local-mesh-versus-region cross-check must be
  **replaced** by the identity in 4 rather than deleted; a region that gains a slit moves from the closed
  `ClosedShenSufficient` index equality to the boundary-corrected `RelativeBoundary` branch; and every vertex on a
  barrier loses its inner-vertex cycle, so a prescribed singularity there must be re-bound to the slit's boundary
  cycle and **fail closed** when it binds to nothing. Amendment 12 is not weakened: constructing a derived
  transport domain is not repairing an upstream product, exactly as Amendment 14 established for the derived
  arrangement. Source: `Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md` §§2-7.
- **Amendment 16 — every derivation that walks transport is a transport-domain operation.** Amendment 15
  defined a region's transport domain and applied it to the cycle basis. It applies to **every** derivation
  that traverses transport, in **any** stage, without exception — including singularity port attachment, its
  incident-fan construction, A2a's vertex-transit resolution, and any future consumer. *(Scope widened from "every
  A1 derivation" to every stage at `M3-CP4c-3-TB3-R1-REV`: the reasoning was never A1-specific, A2a's
  `resolve_field_vertex_transit` already complies by consuming the atlas's barrier-free transport set, and stating
  the obligation prevents a later turn from closing a red by widening a traversal across a barrier. A derivation
  whose transport walk is **truncated** by a barrier must report or handle the truncation — terminating at the
  barrier where the stage models that — and may never restore uniqueness by crossing one.)* A barrier edge is **never** traversed, never supplied with a branch
  transport, and never required to have one; supplying one so that a fan closes is the port-derivation form of
  Amendment 15's prohibited option C. Where a derivation assumed a **closed** ring or a fully traversable
  neighbourhood, that assumption is replaced by the corresponding transport-domain object: the fan of one local
  copy — one connected component of `star(v) ∖ B(R)` — which is **open** when the vertex lies on a barrier. A
  degree-1 barrier vertex is not exempt: its star is not split, but its ring walk still straddles the barrier ray.
  One product may not hold two notions of traversability, so a vertex bound to a slit boundary cycle may not also
  be required to present a closed transportable ring.

  The amendment fixes the **frame and the prohibition**; it deliberately leaves open whether an *open* sector fan
  still emits singularity ports (per-sector ports, versus absorbing the index into the slit boundary cycle and
  emitting none), because the two differ in product-visible behaviour — the second means no traces start at such a
  singularity — and the choice requires a measured census of barrier-incident singularities that does not yet
  exist. Source: `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md` §5.

- **Amendment 17 — an election among candidate cells is decided from a single datum, not from one representative
  per cell.** Where a producer chooses among candidate faces, sectors or cells by asking *"is this cell's own
  representative of the datum admissible in this cell?"*, the question is **not a partition test**, and its
  non-uniqueness cannot be removed by refining the cells, tightening a half-open convention, ordering the
  candidates, or introducing a tolerance — the non-uniqueness is not in the cells. A partition disambiguates one
  point among cells; it cannot disambiguate one point per cell. Vertex continuation in particular is a property of
  **one** incoming ray and must be decided from that ray — expressed once and tested against the fan, or
  equivalently from where the ray exits the vertex star. A cross field's per-face branch representatives are
  related by transport, **not equal as vectors**, so testing each face against its own representative tests a
  different point in every cell.

  Three corrections are **prohibited** because they remove the symptom rather than the cause: electing the first
  candidate or ordering faces to force uniqueness; widening or narrowing the sector convention; and introducing any
  tolerance into a predicate that is exact today. Changing an arrival-mode exclusion in order to alter cardinality
  is prohibited for the same reason. The amendment fixes the frame and the prohibitions; **which** single datum is
  used — the incoming direction transported into each candidate, the ray's geometric exit from the star, or a
  continuation owner published upstream — is a single-writer question left to the turn that measures the elected
  directions. Source: `Architecture_M3_CP4c3_TB4_Independent_Review_Record.md` §§AQ2, 5.

- **Amendment 18 — exactness is a property of the derivation chain, not of the final comparison.** A value that
  reaches a topological decision may not have passed through floating point at **any** point in its derivation,
  even when the comparison itself is exact. Converting an exact quantity to `double` and back — for transport, for
  normalization, or for convenience — destroys the guarantee regardless of the comparison's type, and introduces
  silent failure modes (underflow to zero, non-finite intermediates, failed reconstruction) precisely where the
  decision is least observable. Where performance requires it, a **certified filter** is admitted: a
  floating-point or interval evaluation that either returns the provably-correct result or **defers to the exact
  computation** (Shewchuk-style adaptive predicates, or interval arithmetic used as a filter). A filter that can
  return a different answer than the exact path is not a filter and is prohibited; so is snapping an exact
  coordinate onto a bounded lattice, which changes the value rather than the cost. Source:
  `Architecture_M3_CP4c3_TB5_Independent_Review_Record.md` §AT6, §9.1.
- **Amendment 19 — a producer may not have an unreportable exit.** Every control-flow path that can end in a typed
  failure must record a typed reason. An early `continue`, a `nullopt` return on a conversion, or a guard that
  skips a state must leave evidence. A producer that reports a typed name describing a decision it never made is
  **worse** than one that reports nothing, because the name is believed — five consecutive review turns have been
  spent on names that misdescribed their own cause. Where a producer publishes per-state diagnostics, the
  diagnostic must be recorded **before** any conditional that can skip the state, and an empty diagnostic set must
  itself be a distinguishable, named condition. Source:
  `Architecture_M3_CP4c3_TB5_Independent_Review_Record.md` §AT1-AT2, §11.

### 7.3 Single-writer authority
 
`SourceAuthoritySnapshot`, `GlobalTopologyPlan`, and `GlobalConformityPlan` are referenced, not copied into multiple mutable aggregates. A consumer receives a `const` view or stable typed ID. Network, phase-front, materializer, and validator objects cannot each own divergent copies of face-region or sheet arrays.
 
Local producers construct fully scoped objects. An aggregator may verify scope and remap representation handles, but it may not overwrite source component, topology region, sheet membership, route, or relation semantics after production. This holds identically for the degraded producer.
 
### 7.4 Hard-rail scheduling
 
All regions incident to a hard rail contribute requirements to one scheduling problem. The scheduler computes:
 
- a canonical ordered breakpoint sequence in exact source-rail coordinates;
- incident region/side ownership;
- target-size objective and permitted deviation;
- shared edge count;
- parity and 2:1 adaptivity constraints where enabled;
- singularity/feature endpoints that are fixed;
- a proof that both sides consume the identical sequence.
Only after the schedule verifies may region producers run. They consume breakpoint IDs and may not insert, remove, quantize, or reorder shared breakpoints. This is the architectural correction for target-size-dependent `InvalidHardRailPairing`.
 
The assignment is **positive**: every rail receives at least one subdivision. Positivity is the validity criterion, it is locally checkable, and it structurally prevents the degeneracy that zero-length rails would imply. The cost is that some coarse configurations otherwise expressible with zero-length edges are excluded; that is an accepted quality trade for a criterion that can be certified without a parametrization.
 
The scheduler is a deterministic polynomial graph or flow algorithm (§4.7). A generic branch-and-bound integer program is **not** an acceptable implementation, because it supplies neither the monotone progress measure required by §10.2 nor a canonical tie-break among equally-optimal solutions required by §10.1. Solver choice within the polynomial class is replaceable; the certificate and invariants are not.
 
If the assignment is infeasible for a subset of rails, the scheduler emits a typed infeasibility naming exactly that subset. It does not relax constraints, does not retry with altered targets, and does not fail the run: the affected regions become non-constructible and the run proceeds toward D3.
 
### 7.5 Field quadrangulability precondition
 
A1 decides, before any topology is planned, whether the supplied field admits a quadrangulation consistent with its singularity and holonomy structure, and emits a `FieldQuadrangulabilityCertificate`. A field that fails this check is a catastrophic condition (§2.3), because no downstream disposition could produce meaningful output from it.
 
Placing this check at A1 is deliberate. Infeasibility discovered at A3 is expensive, arrives after substantial work, and is easily misattributed to the scheduler; the same fact is cheap and unambiguous at A1.
 
### 7.6 Holonomy
 
Periodic transport is a complete grid automorphism. Zero rotation is an ordinary value, not a different representation. Composition around every owned cycle must match the declared holonomy. The canonical typed transport algebra and materializer can consume nonzero `Z4` authority when that authority is supplied directly. The current producer does not emit nonzero periodic `Z4`; produced nonzero-`Z4` authority remains deferred to `G4-B003` / M5. Direct materializer evidence therefore does not constitute produced end-to-end support.
 
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
4. proves every owned relation was consumed exactly once **within the constructed region set**;
5. emits one vertex per verified class and one quad per accepted cell;
6. records a materialization certificate linking every output incidence to its source occurrences.
No world-space weld, post-hoc cell merge, representative-sheet selection, count/frequency ownership rule, or arbitrary subset search is allowed, at any disposition tier.
 
Under D3, relations owned by omitted regions are not orphaned defects: the disposition stage removes them from the owned set together with their region, and records that removal in the degradation certificate. Rule 4 is then checked against the reduced set. A relation that is unconsumed *without* a corresponding omission certificate remains a hard verification failure.
 
## 9. Validation architecture
 
Validation is an independent certificate verifier, not a second producer.
 
It may recompute elementary source incidence and output mesh topology from immutable inputs. It may not infer missing hard-rail endpoints from front-edge indices, reconstruct producer routes from whichever face is selected, or silently canonicalize malformed producer state.
 
Validation layers:
 
1. **schema:** typed IDs, closed outcomes, sorted/unique canonical sets, no dangling references;
2. **certificate:** transition, network, seam, rail, holonomy, chart-path, quotient, and materialization proofs;
3. **source attachment:** exact support and sheet/component constraints;
4. **mesh topology:** twins, orientation, manifoldness, connected components, boundary loops, Euler characteristic;
5. **product:** pure quads, one cell to one quad, complete lineage;
6. **geometry:** inversion, self-intersection, size, alignment, and quality thresholds;
7. **disposition:** the tier is recomputed from the materialized product and the degradation set; every degradation certificate is matched to an observable product fact; no degradation is unrecorded and no record is unsubstantiated.
Layer 7 is symmetric and both directions are required. An unrecorded degradation is a verification failure because it would misrepresent the product's guarantees. A recorded degradation with no corresponding product fact is equally a failure, because it would mask a defect behind a fictional excuse.
 
Layers 4 and 5 are evaluated against the emitted subset under D3, with the omitted region set supplied as an explicit input to the verifier rather than inferred from what is missing.
 
The verifier uses independently written checks at stage boundaries. Shared primitive types are allowed; reusing the producer's decision procedure as the validator is not independent evidence.
 
## 10. Determinism and complexity
 
### 10.1 Determinism
 
Canonical ordering uses semantic tuples of typed source identities. Hashes, object addresses, thread completion order, source-face row order, and output row order do not participate.
 
Metamorphic invariants are mandatory and apply at every disposition tier:
 
- source-face row permutation preserves semantic output digest;
- region and producer scheduling permutation preserves it;
- route reversal plus orientation inversion preserves relation identity;
- output vertex/face row permutation preserves it;
- changing source support, transport, connectivity, winding, or sheet separation changes it;
- **the disposition tier, the set of degraded regions, and the set of omitted regions are themselves invariant under all of the above permutations.**
The final invariant is what makes graded disposition safe. A degradation whose occurrence depended on scheduling order would be a nondeterminism defect wearing a degradation label, and the metamorphic suite is what distinguishes the two.
 
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
 
Local limits nested inside outer loops do not bound total work. A stage must prove that each accepted edit decreases a lexicographic monotone measure or consumes a finite global budget. Timeout is never correctness evidence.
 
Budget exhaustion is a disposition input, not a hard failure. Exhaustion during region construction marks the remaining regions non-constructible and proceeds to D3 with the last valid certificate set. Exhaustion before any region completes is catastrophic (§2.3). Because degradation is bounded and non-recursive (§2.2 rule 7), the total work under any disposition remains bounded by the same measure as the strict path plus one bounded substitution per region.
 
## 11. Module boundaries
 
The target source layout is responsibility-based:
 
```text
surface_cells/
  authority/       SourceAuthoritySnapshot, strong IDs, source support
  transport/       chart atlas, grid automorphisms, routes, cycle proofs
  network/         combinatorial tracing, curve network, selection
  planning/        topology plan, rail schedule, parity/conformity
  construction/    bounded region producers (strict and declared degraded)
  occurrence/      cells, corners, directed sides, relation registry
  quotient/        quotient plan and materialization
  disposition/     degradation certificates, tier computation, omission bookkeeping
  verification/    independent certificate, mesh, and disposition verifiers
  diagnostics/     derived reports and serialization
```
 
File size is not itself an invariant, but a module that combines producer selection, topology planning, canonicalization, materialization, validation, diagnostics, and disposition violates single ownership. `disposition/` may depend on `construction/` but not the reverse: a producer must not be able to observe or influence its own degradation. New behavior belongs in the target modules. When an existing monolith must change, the affected ownership contract moves completely in that change; a retained bridge is not an architectural destination.
 
## 12. Verification matrix
 
Every stage requires positive, negative/tamper, metamorphic, independent
semantic, and representative evidence. Every mandatory test names its intent,
proves its semantic precondition, enters the public production API or named
stage, uses an independently written input/output oracle, rejects a deliberate
counterexample, and records its executable/fixture/seed/artifact identity.
 
| Contract | Positive | Negative/tamper | Metamorphic/property | Independent/representative |
|---|---|---|---|---|
| typed transition route | boundary and interior routes | domain substitution, missing paired topology | face-row, branch-label, and route-orientation permutation | seam and cylinder through the production entry |
| curve network | ports owned once; traces terminate at typed events | trace crossing, silent interior termination, unowned port | tracing order and start-port permutation | torus, feature-bearing mechanical part |
| producer outcome | each of three alternatives | inconsistent payload cannot be constructed | dispatch and call-sequence order do not change rejection | plane plus typed unsupported/invalid inputs |
| rail schedule | two regions consume one schedule | independent breakpoint insertion; non-positive assignment | region order, uniform scale, and target-size perturbation | torus, thin tube, mechanical feature |
| chart certificate | chained multi-rail path | missing/duplicate/conflicting relation | source-face/cyclic-start permutation | torus completion with unused and off-face relations |
| periodic/singularity transport | zero/nonzero rotation algebra and declared indices | wrong inverse/index/owner/unconsumed relation | canonical reversal and quarter-turn branch relabeling | cylinder, torus, prescribed sphere |
| quotient/materialization | explicit occurrence relations | proximity-only/equal-coordinate merge | emission/component/thread-order permutation | close sheets and torus |
| **disposition** | each tier reachable and correctly labeled | unrecorded degradation; fabricated degradation record; tier raised mid-run; degraded producer mutating upstream state | tier, degraded set, and omitted set invariant under every §10.1 permutation | induced region failure and induced rail infeasibility on committed fixtures |
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
   certificates, disposition, geometry, and quality;
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
 
### 13.1 Disposition and gates
 
Graded disposition changes what a gate means, and the change is strict rather than permissive:
 
1. **Strict gates require D0.** Every committed representative fixture gate is closed only by a `Certified` disposition. A D1–D3 result on a fixture that is expected to reach D0 is a **failure**, reported as such. Degradation is a production safety property, never a way to pass a test.
2. **Degradation paths need their own positive evidence.** Each declared degradation trigger has a test that induces it deliberately — an injected region-producer rejection, an injected rail infeasibility — and asserts the resulting tier, certificate content, mesh manifoldness on the emitted subset, and determinism of the degraded set.
3. **Known-red intent is distinct from degradation.** A fixture whose strict path is not yet expected to pass is reported as known-red at D0, not silently accepted at D2. The two conditions have different causes and different owners.
4. **The degraded producer is tested as a product, not as an escape.** It has positive, tamper, and metamorphic evidence of its own: pure-quad output, exact boundary conformance to the unmodified plan, and non-interference with neighbouring regions.
All portable mandatory tests and minimized replay cases are compiled and
discovered in the default immutable artifact. Toolchain-specific sanitizer
fuzz targets are mandatory in their declared Clang sanitizer artifact.
Labels may separate accepted required-green contracts from explicit known-red
product intent, nightly corpus/fuzz, and quality tiers; build options may not
hide mandatory authority. A known-red intent test is reported, not disabled or
counted as green.
 
## 14. Implementation transition
 
This branch is experimental and has no released surface-cell ABI or serialized schema to preserve. A semantic contract is replaced vertically from producer through verifier/materializer, and the displaced fields, helpers, and tests are removed in the same Code + Build turn. Immutable artifacts remain comparison evidence, but their internal numbering, hashes, row order, and incomplete product behavior are not design requirements.
 
Milestone numbering is revised in this document to accommodate the curve-network and disposition contracts. The mapping from the previous numbering is: prior M1 → M1 (unchanged), prior M2 → M2 (unchanged), prior M3 → M4, prior M4 → M5, prior M5 → M6, prior M6 → M8. M3 (curve network) and M7 (disposition) are new.
 
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
- G0–G3 semantic invariants, truthful typed failures, and deterministic identity remain valid;
- differences from the entering artifact are classified by product/design invariants rather than forced back to prior internal representation.
### M2 — closed stage products and single writers
 
Any remaining producer with overlapping state is replaced by one exhaustive outcome and one immutable stage product. Consumers reference the product and may validate it; they do not rewrite or reconstruct its semantics.
 
Acceptance:
 
- inconsistent outcomes are unrepresentable;
- exhaustive dispatch covers every alternative;
- `Rejected` is terminal for the emitting producer and cannot trigger substitution within `construction/`;
- the affected direct product gate passes its independent oracle.
### M3 — field-aligned curve network
 
Introduce `FieldAlignedCurveNetwork` as a typed authoritative product derived by combinatorial tracing, and make `GlobalTopologyPlan` consume it rather than assume regions.
 
Acceptance:
 
- singularity ports derived from field index and owned exactly once;
- traces are branch-consistent and provably non-crossing;
- every trace terminates at a typed network event; no silent interior termination is representable;
- every emitted region carries a disc-topology proof;
- network selection preserves mandatory topology under tamper;
- tracing-order and start-port permutation invariance passes.
### M4 — global conformity plan
 
Move hard-rail breakpoint and side-count selection before regional production. Producers consume one verified positive schedule computed by a deterministic polynomial algorithm.
 
Acceptance:
 
- exact shared-rail schedule positive/tamper tests;
- target-size variation cannot create different side breakpoints;
- assignment positivity is certified;
- the exact-torus `InvalidHardRailPairing` blocker is removed without post-hoc pairing;
- infeasible rail subsets produce a typed subset-scoped infeasibility, not a run failure;
- work and solver bounds are reported, with an explicit monotone measure.
### M5 — certificate-carrying chart and quotient relations
 
Replace verifier-side reachability reconstruction, boolean witness compression, front-edge equality, and relation-vector coupling with canonical relation IDs and explicit path certificates in one producer-to-consumer change.
 
Acceptance:
 
- exact selected relation paths are retained and independently verified;
- unused valid relations do not alter the selected certificate;
- missing, duplicate, conflicting, nonreciprocal, and representation-renumbered relations fail typed;
- torus lineage and quotient acceptance are direct production evidence.
### M6 — occurrence, embedding, and independent verification
 
Separate occurrence creation, quotient construction, geometry embedding, and validation as complete stage products. The verifier consumes certificates and independently recomputes elementary incidence; it never repairs producer state.
 
Acceptance:
 
- equal coordinates without a relation remain distinct;
- every owned relation is consumed exactly once;
- exact source support is shared without consumer-specific quantized identity;
- source-row, output-row, and scheduler permutation invariance passes.
### M7 — disposition and graded degradation
 
Introduce `OutputDisposition`, `DegradationCertificate`, the declared degraded region producer, and verifier layer 7 as one vertical contract.
 
Acceptance:
 
- every tier is reachable and correctly labeled by the verifier, never by a producer;
- an unrecorded degradation and a fabricated degradation record both fail typed;
- the tier cannot be raised mid-run;
- the degraded producer emits pure quads conforming exactly to the unmodified plan and cannot mutate upstream products;
- omitted-region bookkeeping reconciles with quotient relation consumption;
- tier, degraded set, and omitted set are invariant under every §10.1 permutation;
- every strict fixture gate still requires `Certified`; no gate is closed by a degraded result.
M7 is deliberately sequenced after M6 rather than early. Disposition is a statement *about* the verified product, so it can only be implemented honestly once the verifier and the stage products it describes are themselves correct. Implementing degradation before verification would produce exactly the silent-substitution failure mode §3 identifies.
 
### M8 — module boundaries and operational hardening
 
Move responsibilities to the target module layout and harden diagnostics, resource accounting, packaging, and CI after the owning product contracts are correct.
 
Acceptance:
 
- forbidden producer/verifier dependencies are unavailable;
- `construction/` cannot depend on `disposition/`;
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
- uses the producer's success decision or validator decision procedure as the independent test oracle;
- hides a mandatory direct/property/fuzz replay behind a default-off build option or loses its seed/corpus/package identity;
- **introduces a global linear system or numeric factorization into the Pipeline B default path;**
- **adds a limit-cycle, tiny-region, or non-disc repair step to the curve network, rather than obtaining those properties from the tracing and termination rules;**
- **degrades without emitting a degradation certificate, or emits a certificate not substantiated by a product fact;**
- **allows a producer to observe, choose, or influence its own degradation;**
- **allows a degradation to modify an upstream immutable stage product;**
- **allows a degraded result to close a strict gate, serve as a certified baseline, or raise a disposition tier;**
- **adds a catastrophic cause outside the closed set in §2.3, or makes a non-catastrophic failure terminate the run.**
## 16. Pipeline A — optional future path
 
Pipeline A is **not normative and not scheduled**. It is recorded here so the option is designed rather than improvised, and so that Pipeline B's stage boundaries are chosen to keep it reachable. No work on Pipeline A is accepted until Pipeline B reaches production-level output on the full committed representative matrix at `Certified` disposition.
 
### 16.1 Motivation
 
The reason to hold this option open is that a solved seamless parametrization supplies a distortion-optimal layout, which traced separatrices do not. Pipeline B's regions are field-faithful; Pipeline A's would additionally be distortion-informed. Whether that difference is material is an empirical question about the input class, to be answered with Pipeline B's measured quality results — not assumed in advance.
 
### 16.2 Structure
 
Pipeline A replaces A2a with a solved layout and adds a per-region embedding step. All other stages are shared:
 
| Stage | Change from Pipeline B |
|---|---|
| A0, A1 | unchanged |
| A2p | **new:** one continuous seamless parametrization solve, containing **no integer variables** |
| A2a | field-aligned curve network extracted by tracing A2p isolines instead of field separatrices |
| A2a′ | unchanged in contract; `SurfaceCutGraph` certifies/completes the immutable isoline-traced network before region derivation |
| A2b | unchanged in contract; regions derived from the certified cellular embedding |
| A3 | unchanged in contract; may use the parametric-distance validity test in addition to positivity, permitting zero-length rails |
| A4 | region interiors embedded by guaranteed-injective barycentric mapping with A3-fixed boundaries, optionally refined per region |
| A5–A9 | unchanged |
 
### 16.3 Cost thesis
 
The performance claim that motivates Pipeline A is that the historical cost is refactorization *count*, not a single factorization. Moving all discrete decisions into A3 leaves exactly one integer-free global solve at A2p, and fixing every region boundary at A3 decomposes the remaining work into independent per-region problems that parallelize.
 
This thesis is **unvalidated** and must be measured before any implementation:
 
1. profile the existing solve, separating symbolic factorization, numeric factorization, and refactorization count; the thesis holds only if cost scales with integer-variable count;
2. time one region embedding on a representative region, multiply by expected region count, divide by available parallelism; the decomposition is worthwhile only if that product is small relative to a single global solve.
Neither measurement requires implementing Pipeline A.
 
### 16.4 Conditions for reconsideration
 
Pipeline A becomes eligible for design work only when all of the following hold:
 
- Pipeline B reaches `Certified` on the full committed representative matrix;
- Pipeline B's calibrated quality gates are defined, measured, and stable;
- a measured quality deficit attributable to separatrix-derived layout is documented against those gates;
- both cost measurements in §16.3 support the decomposition thesis.
Absent all four, Pipeline A remains documentation.
 
### 16.5 Non-negotiable constraints if adopted
 
- A2p carries no integer variables; any reintroduction of mixed-integer coordinate solving is rejected outright;
- Pipeline A does not replace Pipeline B; both remain selectable and both remain covered by the full verification matrix;
- disposition, determinism, work-ledger, and single-writer invariants apply to Pipeline A identically and without exception;
- A2p failure is a catastrophic condition **for Pipeline A runs only**, and must fall back to Pipeline B selection at the orchestration level rather than degrade internally.
## 17. References
 
1. Amir Vaxman et al. "Directional Field Synthesis, Design, and Processing." *Computer Graphics Forum* 35(2), 2016. See the [Directional project](https://avaxman.github.io/Directional/) and course materials.
2. David Bommes, Henrik Zimmer, and Leif Kobbelt. "Mixed-Integer Quadrangulation." *ACM TOG* 28(3), 2009. [Project page](https://www.graphics.rwth-aachen.de/publication/0344/).
3. Hans-Christian Ebke et al. "QEx: Robust Quad Mesh Extraction." *ACM TOG* 32(6), 2013. [Paper](https://graphics.rwth-aachen.de/media/papers/ebck2013_1.pdf) and [libQEx](https://github.com/hcebke/libQEx).
4. Nico Pietroni et al. "Reliable Feature-Line Driven Quad-Remeshing." *ACM TOG* 40(4), 2021. [Project and paper](https://www.quadmesh.cloud/) and [QuadWild implementation](https://github.com/nicopietroni/quadwild).
5. Nicolas Ray and Dmitry Sokolov. "Robust Polylines Tracing for N-Symmetry Direction Field on Triangulated Surfaces." *ACM TOG* 33(3), 2014. [HAL record](https://inria.hal.science/hal-01092823).
6. David Eppstein, Michael T. Goodrich, Ethan Kim, and Rasmus Tamstorf. "Motorcycle Graphs: Canonical Quad Mesh Partitioning." *Computer Graphics Forum* 27(5), 2008. [PDF](https://media.disneyanimation.com/uploads/production/publication_asset/36/asset/motorcycle_sgp_2008.pdf).
7. Marcel Campen, David Bommes, and Leif Kobbelt. "Quantized Global Parametrization." *ACM TOG* 34(6), 2015. [Paper](https://www.graphics.rwth-aachen.de/media/papers/campen_sa2015_qgp_medium.pdf).
8. Martin Heistermann, Jethro Warnett, and David Bommes. "Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization." *ACM TOG* 42(4), 2023. [Project page](https://www.algohex.eu/publications/bimdf-quantization/) and [libSatsuma](https://github.com/cgg-bern/libsatsuma).
9. Yoann Coudert-Osmont et al. "Quad Mesh Quantization Without a T-Mesh." *Computer Graphics Forum* 43(1), 2024. [Project page](https://www.algohex.eu/publications/quad-mesh-quantization-without-a-t-mesh/).
10. Mark Gillespie, Nicholas Sharp, and Keenan Crane. "Integer Coordinates for Intrinsic Geometry Processing." *ACM TOG* 40(6), 2021. [Paper](https://arxiv.org/abs/2106.00220) and [geometry-central documentation](https://geometry-central.net/surface/intrinsic_triangulations/integer_coordinates/).
11. Ryan Viertel, Braxton Osting, and Matthew Staten. "Coarse Quad Layouts Through Robust Simplification of Cross Field Separatrix Partitions." 2019. [Paper](https://arxiv.org/abs/1905.09097).
12. Xiao-Ming Fu et al. "Inversion-free Geometric Mapping Construction: A Survey." *Computational Visual Media* 7(3), 2021. [Paper](https://www.sciopen.com/article/10.1007/s41095-021-0233-9).
13. Jiaran Zhou, Changhe Tu, Denis Zorin, and Marcel Campen. "Combinatorial Construction of Seamless Parameter Domains." *Computer Graphics Forum* 39(2), 2020.
14. Marcel Campen, Hanxiao Shen, Jiaran Zhou, and Denis Zorin. "Seamless Parametrization with Arbitrary Cones for Arbitrary Genus." *ACM TOG* 39(1), 2019. [Paper](https://dl.acm.org/doi/10.1145/3360511).
15. Hanxiao Shen et al. "Which Cross Fields Can Be Quadrangulated? Global Parameterization from Prescribed Holonomy Signatures." *ACM TOG*, 2022.
16. Wenzel Jakob et al. "Instant Field-Aligned Meshes." *ACM TOG* 34(6), 2015. [Project page](https://rgl.epfl.ch/publications/Jakob2015Instant).
17. Giorgio Gori et al. "FlowRep: Descriptive Curve Networks for Free-Form Design Shapes." *ACM TOG* 36(4), 2017. [Project page](https://www.cs.ubc.ca/labs/imager/tr/2017/FlowRep/).
18. Qingnan Zhou and Alec Jacobson. "Thingi10K: A Dataset of 10,000 3D-Printing Models." 2016. [Paper](https://arxiv.org/abs/1605.04797) and [dataset](https://github.com/Thingi10K/Thingi10K).
19. LLVM Project. [libFuzzer documentation](https://llvm.org/docs/LibFuzzer.html).
20. [RapidCheck](https://github.com/emil-e/rapidcheck), [libQEx reference tests](https://github.com/hcebke/libQEx/blob/517dcaa0cc87646baa89e52cfc8e23766776f6d5/tests/reference_meshes.cc), [Geometry Central intrinsic properties](https://github.com/nmwsharp/geometry-central/blob/019669ddabda05e0f71fa3587cfb3c1dadf19cb8/test/src/intrinsic_triangulation_test.cpp), and [CGAL remeshing tests](https://github.com/CGAL/cgal/blob/548fc90ea5d38402df679426283475ec78db0537/PMP_Remeshing/test/PMP_Remeshing/remeshing_test.cpp).
