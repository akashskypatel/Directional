# Surface-Cell Architecture Independent Design Review

**Review type:** independent, documentation-only architecture review  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Reviewed branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Decision:** **changes required before architecture expansion**  
**Runtime decision:** preserve and execute the already compiled artifact-only checkpoint; a pass can resolve `G4-R007` behaviorally but cannot close the architectural findings below.

> **2026-08-11 historical-status note:** This report remains authoritative evidence for AR-01 through AR-12 against reviewed source `6af23d9...`. Its former normative roadmap and immediate runtime instruction are superseded by the supplied replacement `DESIGN.md`, `REORIENTATION_PLAN.md`, and `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`. The redesign makes Pipeline B normative, leaves Pipeline A optional, adds M3 curve-network and M7 disposition contracts, and maps former M3-M6 to M4/M5/M6/M8. Do not execute the historical artifact instruction in this report.

## Executive assessment

The implementation has accumulated substantial correct domain knowledge—source-attached points, typed failure reasons, topology regions, local sheets, explicit holonomy data, seam certificates, direct cell materialization, and strong validation goals. The repeated regressions are not evidence that the underlying surface-cell idea is unsound.

They are evidence that authority is represented and owned incorrectly.

The implementation currently has multiple partially overlapping “truths” for producer state, source identity, routes, chart equivalence, region scope, and output ownership. Consumers repair gaps by reconstructing semantics from those representations. Focused tests then tend to validate a particular reconstruction. A different enumeration, additional relation, or representative fixture invalidates the proxy and produces the next regression.

The design is therefore unsafe to extend with nonzero holonomy, new adaptive transitions, or prescribed-singularity completion until a staged authority migration begins. The migration must be incremental and retain the existing immutable evidence chain.

## Scope and method

This review inspected:

- the normative design, remediation, TODO, milestone, handoff, regression tracker, and PR-wide audit documents;
- production headers and implementations at the reviewed commit;
- focused and representative surface-cell test architecture;
- prior build/runtime reports and immutable artifact boundaries;
- the supplied MIQ, QEx, QuadWild, Instant Meshes, Directional Fields STAR, and FlowRep papers;
- the supplied AutoRemesher implementation;
- official paper project pages and open-source implementations for Directional, libQEx, QuadWild, and Instant Meshes.

No production code, tests, fixtures, workflows, build configuration, generated executable, benchmark, or runtime artifact was changed or executed in this review.

## Severity model

- **Critical:** permits contradictory semantic authority or makes a representative topology class structurally unreliable.
- **High:** repeatedly converts representation details into semantic behavior and is likely to regress under new fixtures.
- **Moderate:** materially increases change coupling, evidence ambiguity, or verification cost.

## Findings

### AR-01 — producer state has contradictory authorities

**Severity:** Critical  
**Patterns:** `RP-03`, `RP-08`

`SurfacePhaseFrontResult` contains an enum disposition plus independently mutable `attempted` and `succeeded` booleans. At the reviewed commit, `SurfaceCellTracing.cpp` contains 106 disposition assignments, 99 explicit `Rejected` values, five `attempted` assignments, and five `succeeded` assignments. Pipeline consumers use both `succeeded` and `disposition`.

Evidence:

- `include/directional/geometry/SurfaceCellTracing.h:465-490`;
- `src/geometry/SurfaceCellTracing.cpp:5455-5492`, `5727-5736`, and analogous producers;
- `src/pipeline/RemeshPipeline.cpp:1838-1842` versus `6051-6056`.

There are representable states such as `Rejected + succeeded`, `Produced + !succeeded`, and `NotApplicable + attempted`. Convention, not the type system, prevents them. Adding another consumer can choose the wrong field without a compile error.

**Correction:** replace the triple with a closed `ProducerOutcome<T>` sum type, named constructors, and exhaustive dispatch. Debug partial state is separate and cannot be consumed as a product.

### AR-02 — semantic domains are encoded as interchangeable integers and parallel arrays

**Severity:** Critical  
**Patterns:** `RP-01`, `RP-03`, `RP-06`, `RP-07`

Routes store a compact transition index and canonical source-edge topology in parallel vectors. Singular “last transition” values duplicate route state. Other records repeat the same structure for periodic routes and cuts.

Evidence:

- `SurfaceTraceSegment::transitionSourceEdge`, `transitionSourceEdges`, and `transitionSourceTopology` in `SurfaceCellTracing.h:119-126`;
- `SurfaceFrontEdge::sourceRouteEdges` and `sourceRouteTopology` at `297-300`;
- `SurfacePeriodicHolonomy` route/cut pairs at `316-323`.

The current tracker already records full-`EF`, source-wide compact, and region-local compact index confusion. The architecture still permits recurrence because all values are `int`, positional correspondence is external, and a consumer can accept either vector independently.

**Correction:** strong ID types plus `TransitionStep { topology, optional interior ID, transport, orientation }` inside one `CanonicalRoute`. Derive the last step. Conversion between index domains is named, checked, and fallible.

### AR-03 — a generic integer-vector identity erases domain schemas

**Severity:** High  
**Patterns:** `RP-01`, `RP-03`, `RP-05`

`SurfaceCellCanonicalIdentity` is `bool valid + vector<int64_t> values`. It is reused for ownership, chart membership, source entity, support, and boundary semantics without a domain tag or schema. `make_surface_cell_ownership_key` stores `{sourceComponent, classOrdinal}`, where the ordinal is an enumeration handle rather than a source-invariant identity.

Evidence:

- `include/directional/geometry/SurfaceCellOwnership.h:23-57`;
- ownership key construction at `124-133`.

Two domains with the same vector shape can compare equal. Changing membership enumeration can change ownership identity while source semantics remain fixed.

**Correction:** domain-specific canonical key types with explicit constructors. Ownership keys contain canonical member identities, not ordinals.

### AR-04 — duplicate chart and authority records invite divergence

**Severity:** High  
**Patterns:** `RP-06`, `RP-09`

`SourceChartId` and `SurfaceCellSourceChart` represent the same facts with different names and field orders. Validation manually converts between them. `SurfaceCellNetwork` contains `phaseFront`, then copies source face/topology-region arrays and topology-region records already held by `phaseFront`.

Evidence:

- `SourceChartId` in `SourceChartTransitions.h:36-53`;
- `SurfaceCellSourceChart` in `SurfaceCellOwnership.h:61-86`;
- manual validator conversion around `SourceAuthoritativeMeshValidator.cpp:812-819`;
- duplicate phase-front/network authority in `SurfaceCellTracing.h:474-490` and `622-634`.

The validator or pipeline can read a different copy from the producer. No single writer is structurally enforced.

**Correction:** one chart type and immutable `SourceAuthoritySnapshot`/`GlobalTopologyPlan` referenced by typed IDs. Aggregates never copy mutable authority tables.

### AR-05 — canonical equality includes representation and execution details

**Severity:** High  
**Patterns:** `RP-05`

`SourceHardRailChartEquivalence` equality and ordering include `firstFrontEdge` and `secondFrontEdge`. Those are emitted-container positions. `SurfaceCellCompletedFaceOwnerIdentity` equality includes `sourcePatch`, `localQuad`, `completionBackend`, and `completionVariant`. `SourceEntityId` compares raw indices and a canonical identity simultaneously. Region processing sorts first by `structuralHash`, then by canonical vertices.

Evidence:

- `SourceAuthoritativeMeshValidator.h:49-69`;
- `SurfaceCellOwnership.h:454-504`;
- `SourceChartTransitions.h:62-82`;
- `SurfaceCellTracing.cpp:8812-8828`.

Equivalent source semantics can become unequal after emission, patch partition, completion backend, or hash changes. A collision can also select a nonsemantic order.

**Correction:** split semantic identities from representation handles. Define semantic equality first; use hashes only after equality and never as canonical order. Canonicalize route orientation instead of rejecting one direction.

### AR-06 — validator reconstructs producer semantics and compresses away the proof

**Severity:** Critical  
**Patterns:** `RP-01`, `RP-05`, `RP-09`

`resolve_compatible_chart` rebuilds hard-rail relation endpoints from route topology, source-edge incidence, hard-feature membership, and chart-component lookup. It builds per-output-vertex graphs, computes reachability, and records only `scalar`/`witnessed` booleans and reachable sets. The returned compatibility contains selected component and faces, not the ordered relation path that proved selection.

Evidence:

- local graph and `witnessed` state at `SourceAuthoritativeMeshValidator.cpp:631-646`;
- consumer reconstruction of relation components at `676-716`;
- graph assembly and relation ownership at `778-891`;
- selected result compression at `927-953`;
- result schema at `SourceAuthoritativeMeshValidator.h:305-315`.

The validator is acting as a second topology producer. A fix to the reconstruction can pass focused tests without proving that the originating quotient relation was correct. The exact witness is no longer auditable after selection.

**Correction:** producer-owned canonical relation registry and `ChartSelectionCertificate` containing exact endpoints and ordered relation paths. The validator verifies certificates against elementary source incidence; it does not discover them.

### AR-07 — independently produced rail breakpoints are paired post hoc

**Severity:** Critical  
**Patterns:** `RP-06`, `RP-09`

Regions are produced independently and the aggregate phase later groups and pairs hard-rail sides using point-support keys. The persistent exact-torus blocker changes with target size because independently generated sides do not share one breakpoint schedule.

Evidence:

- region producer loop after `SurfaceCellTracing.cpp:8875`;
- post-production hard-rail support grouping around `9085-9147`;
- blocker `G4-B002` in the regression tracker.

This is an ordering defect. No pairing algorithm can guarantee equality of two sequences that were independently chosen under different local discretizations.

**Correction:** introduce a global conformity-planning stage before region production. It owns exact ordered rail breakpoints, shared side counts, parity, and incident region/side assignments. Region producers consume the immutable schedule.

### AR-08 — aggregation overwrites producer semantics

**Severity:** High  
**Patterns:** `RP-03`, `RP-06`, `RP-09`

`normalize_scope` overwrites component, topology-region, sheet, and isolation-sheet values on periodic relations, boundary phases, cells, and edges after a local producer returns.

Evidence: `SurfaceCellTracing.cpp:8835-8881`.

This can make an incompletely scoped producer look valid, mask a wrong producer output, and create two writers for the same facts.

**Correction:** pass an immutable `RegionAuthorityView` into producers and require fully scoped output construction. Aggregation verifies and remaps representation handles only; any semantic mismatch is a typed producer rejection.

### AR-09 — exact source support is implemented multiple times with tolerance-derived identity

**Severity:** High  
**Patterns:** `RP-01`, `RP-05`, `RP-06`

Hard-rail pairing constructs a local `support_key` and quantizes barycentric values with tolerance `1e-9` and scale `1e12`. Arrangement code has additional quantized parameter/angle keys. Other components use `SurfacePointSourceSupportResolver` and generic canonical integer vectors.

Evidence:

- `SurfaceCellTracing.cpp:9085-9143`;
- `SurfaceArrangement.cpp:3232-3238` and `5295-5303`;
- `SurfacePointSupport.h` and chart-transition support logic.

Multiple classifiers can disagree at vertices/edges, particularly on thin sheets or nearly degenerate barycentric coordinates. A numerical rounding choice becomes topology identity.

**Correction:** one sanitized source-support kernel with a tagged exact simplex identity. Tolerances decide sanitization success only; topology identity after sanitization is exact.

### AR-10 — monolithic files collapse stage ownership

**Severity:** Moderate  
**Patterns:** amplifies all repeated patterns

At the reviewed commit:

- `SurfaceCellTracing.cpp`: 9,961 lines;
- `SurfaceArrangement.cpp`: 7,858 lines;
- `RemeshPipeline.cpp`: 10,531 lines;
- `SourceAuthoritativeMeshValidator.cpp`: 1,397 lines.

The largest files combine producer selection, topology construction, canonicalization, aggregation, materialization, diagnostics, retention policy, and validation plumbing. This makes semantic state easily accessible outside its owning stage and makes surgical tests difficult.

**Correction:** responsibility modules introduced by migration, not a one-shot file split. New behavior lands behind stage APIs; legacy monolith code becomes adapters and is deleted only after representative parity evidence.

### AR-11 — the design document mixed normative architecture with status history

**Severity:** High for process architecture  
**Patterns:** `RP-02`, `RP-03`

The prior `DESIGN.md` contained “previous runtime authority,” several “current runtime/compile authority” sections, historical next actions, and normative invariants in one file. At least four different authority epochs remained readable as current design.

This creates the documentation equivalent of one state carrying two meanings: architecture and mutable status. An implementer can follow a superseded “current” section while remaining internally consistent.

**Correction:** the rewritten design is normative only. TODO/milestone/handoff own status; dated reports own evidence; the tracker owns history.

### AR-12 — focused test authority can outpace representative production proof

**Severity:** High  
**Patterns:** `RP-02`

The project has strong focused counterfactual coverage, but prior regressions show tests can construct exact relation objects or numeric domains directly while the production producer emits a different artifact. The current multi-rail tests exercise graph semantics; the immutable torus run remains necessary to establish production-path authority.

**Correction:** every stage contract has four evidence classes: positive, tamper/negative, metamorphic, and representative production entry. A focused proxy cannot close a gate. Test packaging/discovery is part of the certificate.

## Cross-finding root cause map

| Root architectural failure | Direct findings | Repeated patterns | Typical observed symptom |
|---|---|---|---|
| no single semantic owner | AR-04, AR-08 | RP-06, RP-09 | consumer reads or overwrites a different authority copy |
| type-erased domains | AR-02, AR-03, AR-09 | RP-01, RP-03 | full-`EF`, compact, topology, support, or ownership values are interchanged |
| representation-dependent identity | AR-05 | RP-05, RP-07 | enumeration or route direction changes behavior |
| proof reconstructed downstream | AR-06 | RP-01, RP-09 | focused resolver fix moves failure to the representative fixture |
| local decisions precede global constraints | AR-07 | RP-06, RP-09 | target-size-dependent rail mismatch |
| lossy lifecycle state | AR-01 | RP-03, RP-08 | consumers disagree on NotApplicable/Rejected/Produced |
| incomplete evidence boundary | AR-11, AR-12 | RP-02, RP-03 | stale design status or focused proxy is treated as gate authority |

## Reference architecture comparison

| System | Architectural strength | Surface-cell adoption | Explicit non-adoption |
|---|---|---|---|
| Directional Fields STAR / Directional | explicit connection, matching, period jump, singularity, and holonomy domains | typed field-transport atlas and cycle certificates | implicit principal matching as general topology authority |
| MIQ | seamless grid automorphism across cuts; global compatibility | typed `Z4` rotation and `Z2` translation algebra | global mixed-integer coordinate integration |
| QEx / libQEx | preprocessing → geometry extraction → connectivity extraction; sanitized data and exact predicates; occurrence-like entities | exactness boundary, explicit occurrences/ports/relations, certificate verification | inference from imperfect numeric coincidence |
| QuadWild | layout → global side tessellation/parity → independent patch quadrangulation | global rail conformity plan before local producers | post-hoc pairing of independently discretized sides |
| Instant Meshes | scalable local orientation/position fields | geometric proposal and quality optimization | proximity merge as source-topology authority; quad-dominant acceptance |
| FlowRep | global strand/cycle context improves reliability over local alignment | global rail/cycle planning and quality objectives | perceptual score as a validity condition |
| supplied AutoRemesher | clear parameterization/extraction staging | implementation cautionary comparison | hole repair, largest-island selection, and mixed polygon output in strict direct mode |

## Corrective decision

The rewritten `DESIGN.md` is approved as the normative target. The current implementation is approved only as a behavioral baseline and migration source. It is not approved as the architecture for further feature growth.

The already compiled artifact should still be tested exactly once under its existing artifact-only plan because it provides valuable, immutable evidence about `G4-R007`. Regardless of pass/fail:

1. do not add nonzero periodic rotation, adaptivity, or singularity completion to the legacy authority representation;
2. begin the staged architecture migration at M1 after the artifact closeout;
3. keep every migration slice compile/runtime separated and representative-fixture verified;
4. do not combine M1–M6 into a broad refactor;
5. close architectural findings only when forbidden representations are removed, not when one fixture passes.

## Required next evidence

The immediate evidence-only checkpoint remains the immutable multi-rail artifact plan. Its result must be classified as:

- behavioral resolution of `G4-R007` if all required torus evidence passes;
- persistence of `G4-R007` if the same failure remains;
- recurrence/new stable event only if direct evidence satisfies tracker rules.

After that checkpoint, the first mutating turn is M1 authority-kernel Code + Build. It must not change runtime behavior and must not execute generated binaries.

## Sources

- Vaxman et al., [Directional Field Synthesis, Design, and Processing / Directional](https://avaxman.github.io/Directional/).
- Bommes et al., [Mixed-Integer Quadrangulation](https://www.graphics.rwth-aachen.de/publication/0344/).
- Ebke et al., [QEx paper](https://graphics.rwth-aachen.de/media/papers/ebck2013_1.pdf) and [libQEx](https://github.com/hcebke/libQEx).
- Pietroni et al., [Reliable Feature-Line Driven Quad-Remeshing](https://www.quadmesh.cloud/) and [QuadWild](https://github.com/nicopietroni/quadwild).
- Jakob et al., [Instant Field-Aligned Meshes](https://rgl.epfl.ch/publications/Jakob2015Instant).
- Gori et al., [FlowRep](https://www.cs.ubc.ca/labs/imager/tr/2017/FlowRep/).
