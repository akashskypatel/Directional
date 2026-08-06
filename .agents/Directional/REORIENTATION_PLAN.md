# Surface-cell implementation reorientation plan

[Authoritative design](DESIGN.md)

## 1. Current disposition

The implementation has strong provenance, deterministic diagnostics, fail-closed semantics, source-chart infrastructure, arrangement machinery, completion infrastructure, optimization, and validation. It does not yet have a coherent phase-labelled advancing-front producer.

The design-aligned runtime baseline is:

- plane: partial arrangement and 12 candidate quads, then completion validation failure;
- multi-face seam: zero arrangement cells, `SideSubdivisionRepair:InvalidInputIncidence`;
- close sheets: zero arrangement cells, `SideSubdivisionRepair:InvalidInputIncidence`;
- cylinder: zero arrangement cells, `SideSubdivisionRepair:InvalidInputIncidence`;
- direct acceptance: **0/4**;
- default non-overlapping suite: **301/315**.

The aggregate unit-test result is secondary. The direct analytic producer gate is authoritative.

## 2. Reorientation decision

Do not rewrite the entire backend. Preserve:

- typed pipeline context;
- source-face, component, and local-sheet provenance;
- cross-field matching and singularity data;
- source-chart transitions;
- boundary and hard-rail authority;
- canonical embedded identities;
- arrangement materialization and validation;
- transactional mutation framework;
- strict source-authoritative validator;
- fail-closed backend and fallback semantics.

Replace or isolate the constructive core that currently asks arrangement and completion to infer missing connectivity from an overlaid trace network.

The active objective is not another repair of pair-local angular intervals. It is a bounded uniform phase-front proof.

## 3. Mandatory operating rule

Every future agent must work from the earliest incomplete gate in `DESIGN.md`.

Before modifying code, the agent must record:

```text
Active gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

A change that primarily improves diagnostics, caches, counters, memory accounting, scheduler behavior, historical test coverage, or downstream repair is not permitted as the main turn objective while the active gate remains red.

If two consecutive Code + Build turns do not produce material progress at the active gate, stop the micro-fix sequence and perform a design review or bounded replacement proof.

## 4. Gate-oriented execution plan

### R0 — Preserve truthful authority

Status: continuously enforced.

Requirements:

- `SurfaceCells` direct acceptance uses fallback `Fail`;
- source-grid recovery is disabled;
- only `CompletedSurfaceCells` can satisfy success;
- partial output and fallback output remain failures;
- source provenance and strict validation remain authoritative.

No implementation turn may weaken R0 to obtain progress.

### R1 — Uniform phase-front plane proof

Status: **active**.

Implement first-class values:

```cpp
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
```

Required behavior:

1. Seed the authoritative plane boundary.
2. Advance front edges intrinsically by one uniform target size.
3. Construct four source-attached corners and ordered sides.
4. Create a cell only when phase, family, orientation, ownership, and provenance agree.
5. Classify each directed front edge as one filled side or explicit exterior.
6. Pass already-decided cells to arrangement.
7. Prohibit fan-sector inference on the new producer path.

Exit gate:

- plane direct acceptance passes through strict validation;
- output origin is `CompletedSurfaceCells`;
- output is non-empty and pure quad;
- no fallback, recovery, post-hoc cycle decomposition, or positional merge is used.

### R2 — Source-chart and close-sheet propagation

Blocked by R1.

Required behavior:

- transport branch rotation, phase, integer lattice coordinate, component, sheet, and route through authoritative source-chart transitions;
- canonicalize equivalent edge and vertex chart representations;
- reject missing or inconsistent transitions;
- preserve deterministic results under source-face row and orientation permutations.

Exit gate:

- multi-face seam direct acceptance passes;
- close sheets direct acceptance passes;
- no cross-sheet capture, merge, or projection occurs.

### R3 — Periodic closure and holonomy

Blocked by R2.

Required behavior:

- record phase holonomy around periodic cycles;
- reconcile compatible periodic fronts explicitly;
- produce valid directed incidence before arrangement assigns cells;
- classify incompatible periodic closure as a typed phase event.

Exit gate:

- cylinder direct acceptance passes;
- no seam break, invalid input incidence, repeated-node cycle, or non-disk cell remains;
- repeated runs produce identical event and structural hashes.

### R4 — Topology-distinct completion

Blocked by R3.

Separate:

```text
PatchTopologySolver
PatchTopologyEmbedding
CompletedPatchValidator
CompletedPatchAssembler
```

Candidate identity must include adjacency, strip routing, boundary-to-interior incidence, pole valences, and generated source support. Rotations and reflections canonicalize to one candidate.

Exit gate:

- supported 3–6-sided patches complete through genuinely distinct topology;
- required valence-3/5 structures are intentional;
- no generic center fan or rotation-only candidate budget is used;
- prescribed sphere and torus/reduced topology cases pass.

### R5 — Adaptive scale and feature structure

Blocked by R4.

Required behavior:

- dyadic target-size levels;
- adjacent levels differ by at most one;
- named 2:1 pure-quad transition events;
- hard features are structural rails from seeding onward;
- transition edits preserve index and provenance.

Exit gate:

- thin bent tube and mechanical fixtures pass;
- no T-junctions, hanging nodes, feature loss, or opposite-sheet jumps.

### R6 — General production geometry

Blocked by R5.

Required behavior:

- run the complete direct path on `bunny_1k_random.obj`;
- support supplied and generated cross fields as defined by the production matrix;
- preserve topology, provenance, feature rails, and deterministic output.

Exit gate:

- bunny direct acceptance passes repeatedly without fallback or recovery.

### R7 — Production hardening

Blocked by R6.

Only now resume:

- cache reuse and incremental recomputation;
- component parallelism;
- spatial indices;
- memory compaction and telemetry;
- exact-predicate hardening;
- general performance optimization;
- full production benchmark and default-on decision.

## 5. Active-turn scope

The next Code + Build turn implements R1 only.

Allowed:

- first-class phase/lattice/front types;
- deterministic serialization and hashing required to make them authoritative;
- source-chart transport used by the R1 proof;
- uniform front seeding and advancement;
- bounded R1 event handling;
- arrangement entry that consumes already-decided cells;
- minimal test-target movement required to compile the design-aligned suite.

Deferred:

- general test-hygiene cleanup that does not block R1 compilation;
- fan-interval micro-repair;
- additional ownership diagnostics;
- general completion variants;
- FlowRep expansion;
- adaptivity and features beyond plane boundaries;
- cylinder, torus, sphere, thin tube, mechanical, or bunny implementation;
- cache, memory, scheduler, and performance work.

## 6. Material-progress review

At the end of every Test + Benchmark turn, answer in order:

1. Did the active direct fixture pass?
2. Did the first invalid stage move later because a missing design contract was implemented?
3. Is the new state first-class and consumed by the next constructive stage?
4. Did the change eliminate a general ambiguity rather than rename it?
5. Does the next turn remain on the same gate, or has the exit gate been achieved?

A “no” to all first four questions means the turn did not materially advance the design.

## 7. Prohibited detours

Until plane, seam, close sheets, and cylinder pass, do not make these the active objective:

- pair-local fan identity ranking, interval projection, or exclusion variants;
- post-hoc cycle splitting, cell merging, or ownership selection;
- new diagnostic taxonomies for already represented failures;
- cache and recomputation accounting;
- memory and scheduler optimization;
- broad historical milestone restoration;
- complex-fixture benchmarking;
- fallback or recovery enhancement.

Permanent prohibitions:

- validator weakening;
- fallback/recovery substitution;
- fixture, ID, count, or geometry special cases;
- arbitrary subset search;
- count/order/frequency ownership selection;
- positional merging across unrelated sheets;
- synthetic counters or Euler correction;
- timeout-as-correctness.

## 8. Final disposition

The implementation has a valuable validated shell but an underdeveloped constructive heart. The project must now prove the design in causal order:

```text
uniform phase-front
→ cross-chart and sheet-safe propagation
→ periodic holonomy
→ topology-distinct completion
→ adaptive features and transitions
→ general production geometry
→ operational hardening
```

No later concern may displace the earliest red gate.
