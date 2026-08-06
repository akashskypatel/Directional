# Adaptive cross-field-aligned surface-cell quadrangulation

## 1. Authoritative design thesis

The backend is **adaptive cross-field-aligned surface paving**.

It constructs a conforming pure-quad cell complex directly on the source triangle mesh. Every generated point, arc, front edge, cell, patch, and topology edit remains intrinsically attached to authoritative source triangles, components, and local sheets.

The architectural claim is:

> Replace global mixed-integer coordinate integration with local source-surface construction plus explicit, bounded topology reconciliation.

This is not an integer-free method. The required discrete decisions move into:

- 4-RoSy branch matching;
- local lattice phase and integer lattice offsets;
- advancing-front ownership;
- periodic phase holonomy;
- adaptive 2:1 transitions;
- patch side subdivisions and parity;
- extraordinary-vertex placement;
- bounded hole and non-disk closure.

A cross field supplies orientation and singularity information. It does **not** supply authoritative grid position, phase, or connectivity. The implementation must therefore construct those values explicitly before arrangement and completion.

## 2. Development direction is part of the design

The implementation must always advance the earliest incomplete constructive gate in this document. Local diagnostics, repair classifications, caches, memory accounting, benchmark infrastructure, and historical milestone coverage are supporting work only. They must not become the active implementation objective while an earlier constructive gate is red.

Every implementation task must state:

1. the active design gate;
2. the design contract being implemented;
3. the earliest currently failing fixture;
4. the observable result that would constitute material progress;
5. why the change cannot be deferred to a later gate.

A task that cannot answer all five items is not on the critical path and must be deferred.

### Material progress

Material progress requires at least one of:

- the active gate passes its direct acceptance fixture;
- the earliest invalid producer advances to a later named design stage because a general invariant was implemented;
- a missing first-class design value becomes authoritative and is consumed by the next constructive stage;
- a general structural defect is removed without replacing it with an equivalent downstream ambiguity.

The following are not material progress by themselves:

- a new diagnostic subtype, string, counter, hash, or ownership class;
- movement between equivalent repair failures;
- a higher aggregate unit-test count while the direct gate remains red;
- faster execution of a failing producer;
- a cache, memory, or scheduling improvement that does not change constructive validity;
- fixture-specific success or fallback/recovery output.

### No-progress stop rule

If two consecutive Code + Build turns fail to advance the earliest active gate materially, the next turn must be a design review or bounded replacement proof. It must not continue the same micro-repair sequence without explicit evidence that the design contract is now better represented.

## 3. Required production pipeline

```text
Source triangle mesh
  ↓
Input validation and bounded preconditioning
  ↓
Cross-field normalization, matching, and singularity analysis
  ↓
Shared feature map and uniform/adaptive target metric
  ↓
Locally compatible tangent-lattice phase field
  ↓
Boundary, feature, singularity, and regular front seeds
  ↓
Intrinsic phase-labelled advancing-front construction
  ↓
Collision, phase, periodic, scale, and singularity reconciliation
  ↓
Materialization of already-decided cells into a global arrangement
  ↓
FlowRep-style whole-strand and cycle simplification
  ↓
Topology-distinct patch completion
  ↓
Pole, strip, and loop topology optimization
  ↓
Source-constrained geometric optimization
  ↓
Strict source-authoritative validation
```

The order is mandatory. A downstream stage may validate or reject upstream topology, but it must not invent missing upstream phase, front ownership, or cell connectivity.

## 4. Core authoritative data contracts

```cpp
struct SurfacePoint {
    int sourceFace;
    Eigen::Vector3d barycentric;
    int componentId;
    int localSheetId;
};

struct LocalLatticeState {
    Eigen::Vector2d phase;
    Eigen::Vector2i latticeCoordinate;
    int branchRotation;
    int scaleLevel;
};

struct SurfaceFrontEdge {
    SurfacePoint from;
    SurfacePoint to;
    int fieldFamily;
    int advanceSign;
    LocalLatticeState lattice;
    int unfilledSide;
    SourceRouteIdentity route;
};

struct SurfaceCell {
    std::array<SurfacePoint, 4> corners;
    std::array<EmbeddedArc, 4> orderedBoundaryArcs;
    LocalLatticeState lattice;
    int scaleLevel;
    Provenance provenance;
};
```

Equivalent project-specific types are acceptable, but the information must be first-class, serializable, deterministic, and consumed by the constructive pipeline.

World-space position is never authoritative identity. Nearby points may lie on opposing sheets; one intrinsic source point may have multiple adjacent triangle-chart representations.

## 5. Stage responsibilities

### 5.1 Cross-field preparation

- Represent the cross modulo quarter turns.
- Apply authoritative matching at every source-edge transition.
- Track singularity index as a topology budget.
- Do not average one arbitrarily selected cross arm as an ordinary vector field.

### 5.2 Local phase field

For adjacent charts, transport a state of the form:

```text
phase_j = rotate90(phase_i, branchRotation) + integerOffset
```

The transition must preserve component, local sheet, source entity, orientation, field family, and route provenance. Missing or inconsistent transport fails closed.

Noncontractible cycles must record explicit phase holonomy. Residual phase must not emerge later as duplicate ownership or ambiguous fan-sector pairing.

### 5.3 Intrinsic front construction

The front is the constructive authority. It must:

- seed source boundaries and hard rails first;
- advance by intrinsic surface walking;
- construct four source-attached corners and four ordered sides;
- create a quad only after phase, family, scale, ownership, and provenance are compatible;
- give each directed front edge one filled side or an explicit exterior classification;
- resolve collisions through typed events.

Initial uniform event types:

```text
CompatibleFrontMerge
BoundaryTermination
HardRailCapture
PhaseMismatch
PeriodicHolonomyConflict
```

Later adaptive event types:

```text
TwoToOneScaleTransition
SingularityTermination
BoundedClosurePatch
```

### 5.4 Arrangement

Arrangement may:

- canonicalize source identities;
- split exact geometric crossings;
- stitch adjacent source-chart representations;
- materialize twins, next links, cycles, and cells;
- classify exterior and non-disk regions;
- validate topology and provenance.

Arrangement must not infer intended cell connectivity from unrelated fan identities, angular interval ranking, count/frequency rules, positional proximity, or post-hoc cycle decomposition.

### 5.5 FlowRep simplification

FlowRep-inspired work acts on a valid embedded network. It removes or substitutes complete logical strands transactionally while preserving:

- hard rails;
- intrinsic coverage;
- cycle and patch feasibility;
- source provenance;
- topology and singularity budgets.

It is downstream of a coherent producer and must not be used to manufacture missing initial incidence.

### 5.6 Patch completion

Completion candidates must be topology-distinct. Candidate identity includes:

- quad adjacency graph;
- strip routing;
- boundary-to-interior incidence;
- pole valences and placement;
- generated source-supported vertices and arcs.

Rotations and reversals of one topology canonicalize to one candidate. A generic center fan is not a production solution.

### 5.7 Optimization and validation

Optimization moves vertices only through source-constrained intrinsic or provenance-aware operations. Final validation requires:

- pure quads with four distinct vertices;
- manifold incidence;
- no T-junctions, hanging nodes, duplicate faces, or self-intersections;
- correct components, Euler characteristic, and ordered boundary loops;
- complete source provenance and same-sheet safety;
- hard-feature preservation;
- correct singularity-index budget;
- deterministic structural output.

The backend fails closed on incomplete or invalid output.

## 6. High-level implementation gates

Only one gate is active at a time. A later gate may not become the implementation focus until the earlier gate exits.

### Gate 0 — Truthful authority and direct acceptance

Exit criteria:

- direct tests use `SurfaceCells`, fallback `Fail`, and recovery disabled;
- only `CompletedSurfaceCells` can satisfy success;
- source provenance and fail-closed validation remain authoritative;
- the active gate is named in TODO, milestone, handoff, plan, and PR status.

Status: **passed and continuously enforced**.

### Gate 1 — Uniform phase-front plane

Required implementation:

- first-class local phase and lattice coordinates;
- directed front ownership;
- intrinsic uniform front advancement;
- already-decided cells passed to arrangement.

Exit criteria:

- plane produces non-empty pure-quad `CompletedSurfaceCells` output;
- no fallback or source-grid recovery;
- strict source-authoritative validation passes;
- arrangement does not invent connectivity through fan-sector inference.

Status: **active**.

### Gate 2 — Cross-chart and close-sheet propagation

Fixtures: multi-face seam, then close sheets.

Exit criteria:

- phase and lattice identity transport through source-chart transitions;
- source-face row and orientation permutations are deterministic;
- close sheets produce zero cross-sheet merges or captures;
- both fixtures pass direct acceptance.

Status: blocked by Gate 1.

### Gate 3 — Periodic closure and holonomy

Fixture: cylinder.

Exit criteria:

- periodic phase holonomy is recorded and reconciled explicitly;
- every directed front edge has one filled or exterior side;
- no `InvalidInputIncidence`, seam break, or non-disk cell remains;
- cylinder passes direct acceptance.

Status: blocked by Gate 2.

### Gate 4 — Topology-distinct completion and singularities

Fixtures: prescribed sphere and torus/reduced patch cases.

Exit criteria:

- topology-distinct completion graphs exist;
- required valence-3/5 structures are represented intentionally;
- 3–6-sided supported patches complete without center fans;
- rotations/reversals do not consume separate candidate budget;
- strict topology and source validation pass.

Status: blocked by Gate 3.

### Gate 5 — Adaptive scale and feature structure

Fixtures: thin bent tube and mechanical feature fixture.

Exit criteria:

- dyadic target levels with adjacent 2:1 grading;
- explicit pure-quad transition templates;
- hard features are structural rails from construction;
- no final T-junctions or opposite-sheet jumps;
- both fixtures pass direct acceptance.

Status: blocked by Gate 4.

### Gate 6 — General production geometry

Fixture: `bunny_1k_random.obj` with generated and supplied fields as applicable.

Exit criteria:

- deterministic direct pure-quad success;
- complete topology, feature, provenance, and quality validation;
- no fallback or recovery substitution;
- repeated structural hashes agree.

Status: blocked by Gate 5.

### Gate 7 — Production hardening and default-on decision

Allowed only after Gates 1–6 pass.

Work includes:

- cache and incremental recomputation;
- component parallelism;
- spatial indices;
- memory compaction and telemetry;
- exact-predicate hardening;
- full benchmark and qualitative matrix;
- default-on production decision.

Exit criteria:

- complete design-aligned suite green;
- production fixture matrix green;
- deterministic repeated results;
- performance and memory within documented budgets;
- no validator or fallback gate weakened.

## 7. Critical invariants

1. Every generated entity has authoritative source provenance.
2. No operation crosses source components or local sheets without an explicit valid transition.
3. Every source-edge crossing applies authoritative cross-field matching.
4. Boundary and hard-feature rails are never silently dropped.
5. Every accepted cell has a complete ordered boundary and authoritative front ownership.
6. No topology mutation commits before complete local validation.
7. Every topology event records its singularity-index effect.
8. Temporary T-junctions are resolved before final output.
9. Stable identities, traversal order, event order, and stopping rules are deterministic.
10. Missing evidence or unresolved topology produces typed failure, never synthetic success.

## 8. Prohibited implementation detours

Until Gate 3 passes, do not make the following the active implementation work:

- additional fan-interval projection or ranking schemes;
- additional ownership classifications not required by the phase-front producer;
- post-hoc repeated-cycle splitting or cell merging;
- cache, recomputation, memory, or scheduler optimization;
- general FlowRep simplification expansion;
- general patch catalog expansion beyond what the active gate consumes;
- torus, sphere, adaptive, mechanical, or bunny acceptance work;
- broad benchmark tuning.

At all gates, prohibit:

- validator weakening;
- fallback or recovery substitution;
- fixture, face, vertex, ID, or expected-count special cases;
- arbitrary subset search;
- count/order/frequency ownership selection;
- positional merging across unrelated sheets;
- synthetic counters or Euler correction;
- timeout-as-correctness.

## 9. Fixture progression

```text
plane
→ multi-face seam
→ close sheets
→ cylinder
→ prescribed sphere and torus
→ thin bent tube and mechanical feature
→ bunny_1k_random
```

The fixture order is causal. Do not skip a red analytic gate to work on a more complex fixture.

## 10. Distilled contribution

> A source-attached adaptive tangent lattice that creates a phase-labelled advancing-front cell complex, reconciles local phase, periodicity, scale, and singularities through bounded topology events, simplifies coherent strands transactionally, and completes valid disk patches into a strictly validated pure-quad mesh without constructing a global MIQ parameterization.
