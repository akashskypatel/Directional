# Surface-cell backend remediation plan

**Revision:** 2026-08-06  
**Disposition:** `SurfaceCells` remains experimental and default-off.  
**Design authority:** `DESIGN.md`  
**Execution authority:** `REORIENTATION_PLAN.md`

Historical milestone detail is preserved in Git history and prior reports. This document is the current remediation authority and intentionally removes stale checked milestone narratives that could pull implementation work away from the earliest failing design gate.

## 1. Objective

Produce a genuine direct `SurfaceCells` backend that:

1. constructs a phase-labelled, cross-field-aligned cell complex directly on the source triangulation;
2. preserves source component, local sheet, boundary, hard-feature, and singularity authority through every stage;
3. uses explicit front, phase, periodic, scale, and topology events rather than post-hoc inference;
4. emits only manifold, conforming, source-authoritative pure-quad output;
5. fails closed with truthful diagnostics when any required contract is unresolved;
6. never substitutes legacy integration, input return, source-grid recovery, or paired source triangles for direct producer success.

## 2. Current evidence

Authoritative runtime baseline from artifact `8974081923`:

| Fixture | Result | Earliest authoritative failure |
|---|---:|---|
| Plane | failed | completion validation after 9 cells / 12 quads |
| Multi-face seam | failed | `SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | failed | `SideSubdivisionRepair:InvalidInputIncidence` |
| Cylinder | failed | `SideSubdivisionRepair:InvalidInputIncidence` |

- direct acceptance: **0/4**;
- remaining producer tests: **79/79**;
- completion tests: **154/164**;
- validation tests: **60/60**;
- compiled API tests: **8/8**;
- complete non-overlapping default inventory: **301/315**.

The unit-test total does not establish production progress while the direct gate is 0/4.

## 3. Non-negotiable success contract

A run may report direct `SurfaceCells` success only when:

- requested and executed backend are `SurfaceCells`;
- fallback policy is `Fail`;
- no fallback is attempted;
- source-grid recovery is not used;
- output origin is `CompletedSurfaceCells`;
- output is non-empty and 100% quadrilateral;
- every output vertex and edge has complete source provenance;
- component, local-sheet, topology, boundary, and hard-feature contracts pass;
- no T-junction, hanging node, duplicate face, nonmanifold incidence, or self-intersection remains;
- strict source-authoritative validation passes;
- repeated runs are structurally deterministic.

Partial cells, diagnostic progress, recovery output, legacy output, and input-mesh output remain failures.

## 4. Evidence rule

A remediation item is complete only when it contains:

- general implementation of the named design contract;
- a focused test or direct fixture that reaches that contract;
- proof that the next constructive stage consumes the result;
- deterministic failure or success evidence;
- updated TODO, milestone, plan, handoff, runtime summary, and PR status.

A type declaration, stage call, counter, diagnostic string, or hash without live consumption is not completion evidence.

## 5. Gate execution order

```text
G0 Truthful authority
  → G1 Uniform phase-front plane
  → G2 Cross-chart and close-sheet propagation
  → G3 Periodic closure and holonomy
  → G4 Topology-distinct completion and singularities
  → G5 Adaptive 2:1 transitions and hard features
  → G6 General production geometry
  → G7 Operational hardening and production decision
```

Only one gate is active at a time. No downstream gate may become the principal work objective until the current gate exits.

## 6. Gate work packages

### G0 — Truthful authority

Status: passed and continuously enforced.

Required contracts:

- typed pipeline context and stage lineage;
- explicit output origin;
- fail-closed direct semantics;
- no legacy continuation after direct failure;
- no recovery or paired-source-triangle success substitution;
- source-authoritative final validation.

Regression work is allowed only to preserve these contracts.

### G1 — Uniform phase-front plane

Status: **active**.

Implementation:

- authoritative `LocalLatticeState`;
- authoritative directed `SurfaceFrontEdge` ownership;
- intrinsic boundary seeding and one-cell front advancement;
- phase-compatible front merge and explicit exterior classification;
- already-decided cells passed to arrangement;
- arrangement prohibited from inventing connectivity on the new path.

Required bounded events:

```text
CompatibleFrontMerge
BoundaryTermination
HardRailCapture
PhaseMismatch
PeriodicHolonomyConflict
```

Exit gate:

- plane direct acceptance passes with non-empty pure-quad `CompletedSurfaceCells` output;
- strict final validation passes;
- no fallback, recovery, fan-sector inference, positional merge, or post-hoc cycle decomposition.

### G2 — Cross-chart and close-sheet propagation

Status: blocked by G1.

Implementation:

- orientation-aware source-chart transition graph consumed by phase transport;
- quarter-turn branch rotation and integer lattice offset across source edges;
- canonical source-edge and source-vertex chart identity;
- component and local-sheet barriers carried through every front event.

Exit gate:

- multi-face seam direct acceptance passes under source-row/orientation permutations;
- close sheets direct acceptance passes with zero cross-sheet capture or merge.

### G3 — Periodic closure and holonomy

Status: blocked by G2.

Implementation:

- explicit cycle holonomy records;
- bounded periodic front reconciliation;
- complete predecessor/successor incidence before arrangement cell assignment;
- typed conflict for irreconcilable periodic phase.

Exit gate:

- cylinder direct acceptance passes;
- no seam break, invalid incidence, repeated-node cycle, or non-disk cell;
- deterministic event sequence and structural hash.

### G4 — Topology-distinct completion and singularities

Status: blocked by G3.

Implementation:

- finite topology graph catalog;
- canonical symmetry quotienting;
- strip and boundary-to-interior routing alternatives;
- intentional valence-3/5 pole structures;
- source-supported embedding and strict completion validation.

Exit gate:

- supported 3–6-sided patch cases pass;
- prescribed sphere and torus/reduced topology cases pass;
- rotations/reversals do not masquerade as separate topologies;
- no center-fan production fallback.

### G5 — Adaptive 2:1 transitions and hard features

Status: blocked by G4.

Implementation:

- shared feature map;
- thickness-, curvature-, feature-, and field-variation-aware size field;
- dyadic levels with adjacent difference at most one;
- named pure-quad 2:1 transition templates;
- feature rails seeded before regular fronts.

Exit gate:

- thin bent tube and mechanical fixtures pass;
- no T-junctions, hanging nodes, feature loss, or opposite-sheet jumps;
- index budget and topology remain correct.

### G6 — General production geometry

Status: blocked by G5.

Implementation and evidence:

- run the direct backend on `bunny_1k_random.obj`;
- validate generated and supplied cross-field modes as defined by the production matrix;
- retain complete provenance, topology, feature, quality, and deterministic evidence.

Exit gate:

- repeated direct bunny runs pass without fallback or recovery;
- all mandatory correctness gates pass.

### G7 — Operational hardening and production decision

Status: blocked by G6.

Allowed work:

- cache and incremental recomputation;
- component scheduling and parallelism;
- spatial indices;
- memory compaction and telemetry;
- exact-predicate hardening;
- broad performance optimization;
- complete benchmark and qualitative matrix;
- default-on decision.

Exit gate:

- design-aligned suite and production fixture matrix green;
- deterministic repeated results;
- benchmark CV and memory budgets pass;
- no validator or fallback rule weakened;
- production disposition supported by archived evidence.

## 7. Current active backlog

Only these items are critical-path work for the next Code + Build turn:

- [ ] define authoritative local phase, lattice coordinate, branch rotation, and scale level;
- [ ] define authoritative directed front-edge ownership;
- [ ] make phase/front state serializable and deterministically hashable;
- [ ] seed the uniform plane boundary;
- [ ] advance one target-size cell intrinsically;
- [ ] implement the bounded G1 front events;
- [ ] emit already-decided source-attached cells;
- [ ] add an arrangement entry that materializes those cells without fan-sector inference;
- [ ] preserve all source, component, sheet, rail, and matching authority;
- [ ] compile and package the approved targets without executing binaries.

Test-hygiene cleanup is deferred unless it is required for the G1 targets to compile. It must not consume the constructive turn.

## 8. Work explicitly deferred

Until G3 passes, defer:

- more pair-local fan interval projections, rankings, or exclusions;
- post-hoc cycle splitting or cell merging;
- additional ownership classifications for already represented failures;
- general FlowRep expansion;
- broad patch catalog work;
- adaptive or feature-complete implementation;
- torus, sphere, tube, mechanical, or bunny acceptance work;
- cache, memory, scheduler, and performance optimization;
- broad historical milestone restoration.

Permanent prohibitions:

- validator weakening;
- fallback/recovery substitution;
- fixture, ID, geometry, or expected-count special cases;
- arbitrary subset search;
- count/order/frequency ownership selection;
- positional merging across unrelated sheets;
- synthetic counters or Euler correction;
- timeout-as-correctness.

## 9. Turn control and no-progress policy

Every turn must declare the active gate and the material-progress condition before work begins.

A Test + Benchmark turn must report the active direct fixture before aggregate totals.

If two consecutive Code + Build turns do not materially advance the active gate, the next turn must:

1. stop the current micro-repair sequence;
2. compare implementation behavior to `DESIGN.md`;
3. identify the missing first-class construction value or ownership decision;
4. produce a bounded replacement proof rather than another equivalent repair.

## 10. Mandatory final quality gates

| Gate | Threshold |
|---|---|
| Face degree | 100% quads on supported fixtures |
| Manifoldness | zero nonmanifold output edges/vertices |
| Conformity | zero T-junctions and hanging nodes |
| Self-intersection | zero detected intersections |
| Provenance | 100% output entities source-authoritative |
| Source sheet | zero opposite-sheet jumps |
| Topology | components, Euler characteristic, and ordered boundaries preserved |
| Hard features | all required rails represented by ordered output edges |
| Determinism | identical structural hashes for repeated equivalent inputs |
| Output origin | `CompletedSurfaceCells` only |
| Periodicity | cylinder closes with explicit reconciled holonomy |
| Completion | supported 3–6-sided topology-distinct cases pass |
| Adaptivity | all scale changes use validated pure-quad transition templates |
| Diagnostics | no unavailable or synthetic value presented as measured |
| Performance | evaluated only after constructive gates pass |

## 11. Production disposition

The backend remains **default-off experimental**. It cannot move toward default-on until G1–G6 pass in order and G7 evidence is complete.
