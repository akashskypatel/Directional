# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Active gate: **G1 — Uniform phase-front plane**.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **Design-Aligned Artifact-Only Test + Benchmark**.
- Next turn: **Design-Aligned Uniform Phase-Front Code + Build**.

Milestone G is now governed by the gate order in `.agents/Directional/DESIGN.md`. Later fixture, performance, memory, cache, scheduling, or production-disposition work is blocked until the earlier constructive gates pass.

## Artifact-only runtime authority

- artifact: `8974081923`;
- exact source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- artifact SHA-256: `4166325a2f38fa17d05d0d7e71cb147760a1e5208a6e971f60c35665bf3671de`;
- internal checksums: **49/49**;
- recursive submodules: **9/9**;
- fixture/input closure: **26/26**;
- tracked source status: empty;
- no rebuild or source/test/fixture/validator modification occurred.

## Direct producer baseline

- [ ] plane — completion validation failure after 106 traces, 9 arrangement cells, and 12 candidate quads;
- [ ] multi-face seam — `SideSubdivisionRepair:InvalidInputIncidence`, zero cells/quads;
- [ ] close sheets — `SideSubdivisionRepair:InvalidInputIncidence`, zero cells/quads;
- [ ] cylinder — `SideSubdivisionRepair:InvalidInputIncidence`, zero cells/quads.

All four used requested and executed backend `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, and output origin `None`.

Default-suite result:

- direct acceptance: **0/4**;
- remaining producer: **79/79**;
- completion: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total: **301/315**.

## High-level production gates

### G0 — Truthful authority

- [x] direct `SurfaceCells` requests fail closed;
- [x] fallback `Fail` is used for acceptance;
- [x] source-grid recovery is disabled for acceptance;
- [x] only `CompletedSurfaceCells` can satisfy success;
- [x] strict source-authoritative validation remains mandatory.

### G1 — Uniform phase-front plane

Status: **active**.

- [ ] authoritative local phase and integer lattice coordinates;
- [ ] authoritative directed front-edge ownership;
- [ ] deterministic phase/front serialization and hashing;
- [ ] intrinsic uniform boundary seeding and front advancement;
- [ ] bounded merge, boundary, hard-rail, phase-mismatch, and holonomy events;
- [ ] four source-attached phase-compatible corners and ordered sides per accepted cell;
- [ ] already-decided cells consumed by arrangement;
- [ ] no fan-sector inference on the new producer path;
- [ ] plane direct acceptance passes strict validation.

### G2 — Cross-chart and close-sheet propagation

Blocked by G1.

- [ ] phase and lattice transport through authoritative source-chart transitions;
- [ ] multi-face seam direct acceptance;
- [ ] deterministic source-row/orientation permutations;
- [ ] close sheets direct acceptance;
- [ ] zero cross-sheet captures, merges, or projections.

### G3 — Periodic closure and holonomy

Blocked by G2.

- [ ] explicit periodic phase holonomy;
- [ ] complete directed incidence before cell assignment;
- [ ] deterministic periodic event sequence;
- [ ] cylinder direct acceptance with no seam break or invalid incidence.

### G4 — Topology-distinct completion and singularities

Blocked by G3.

- [ ] finite topology graph catalog;
- [ ] rotations/reflections canonicalized rather than counted as alternatives;
- [ ] intentional valence-3/5 structures;
- [ ] supported 3–6-sided patch completion;
- [ ] prescribed sphere and torus/reduced cases pass;
- [ ] no generic center-fan production fallback.

### G5 — Adaptive scale and hard features

Blocked by G4.

- [ ] dyadic target levels and 2:1 grading;
- [ ] validated pure-quad transition templates;
- [ ] hard features seeded as structural rails;
- [ ] thin bent tube and mechanical fixtures pass;
- [ ] no T-junctions, feature loss, or opposite-sheet jumps.

### G6 — General production geometry

Blocked by G5.

- [ ] `bunny_1k_random.obj` passes direct validated surface paving;
- [ ] supplied/generated field modes are deterministic;
- [ ] no fallback or recovery substitution;
- [ ] topology, provenance, features, and quality gates pass.

### G7 — Operational hardening and default-on decision

Blocked by G6.

- [ ] cache and incremental recomputation;
- [ ] component parallelism and scheduling;
- [ ] spatial indices and exact predicates;
- [ ] memory compaction and telemetry;
- [ ] production benchmark and qualitative matrix;
- [ ] complete suite and fixture matrix green;
- [ ] explicit default-on decision supported by evidence.

## Next Code + Build checklist

Only G1 work is authorized:

- [ ] add phase/lattice/front types;
- [ ] consume source-chart matching in phase transport;
- [ ] seed and advance the uniform plane front;
- [ ] emit already-decided cells;
- [ ] isolate arrangement materialization from fan-sector inference;
- [ ] preserve provenance, rails, sheet barriers, and fail-closed behavior;
- [ ] compile and package the seven approved targets;
- [ ] run no generated binary.

## Deferred test-suite cleanup

The following remains valid cleanup work, but it is not the main G1 objective and should be done only when required to compile or package the design-aligned targets:

- move the scheduler-sensitive validator wall-time test to benchmark/closeout coverage;
- demote exact route-ledger and recomputation-counter tests to historical coverage;
- reconstruct invalid completion and Phase 17 fixtures without weakening assertions.

## Progress-control rules

- Every turn must name the active gate and material-progress condition.
- Direct gate results are reported before aggregate totals.
- A new diagnostic subtype, counter, hash, or ownership class is not progress by itself.
- Two consecutive Code + Build turns without material gate progress trigger a design review or bounded replacement proof.
- Do not work on a blocked gate.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md`
- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `tests/TESTING_STRATEGY.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `TODO`

Every completed turn ends with a new top-level PR #8 handoff comment after all documentation and PR metadata writes. That comment is the final repository write.

P5 remains open.
