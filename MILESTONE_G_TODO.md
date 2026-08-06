# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Active gate: **G1 — Uniform phase-front plane**.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **Gate 1 Uniform Phase-Front Local Code + Build**.
- Next turn: **Gate 1 Uniform Phase-Front Artifact-Only Test + Benchmark**.

Milestone G is governed by the gate order in `.agents/Directional/DESIGN.md`. Later fixture, performance, memory, cache, scheduling, or production-disposition work remains blocked until the earlier constructive gates pass.

## Current Gate 1 build authority

- base source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- branch payload checkpoint: `5649cbe6b2ee353955a39db6ceb7fc0d67ee72ce`;
- exact patch Git blob: `aa18d454877ccf40d16f71f173fdaf765f5f1086`;
- uncompressed patch SHA-256: `48a01a37b038c59af18f2fca8904642f23bf8ea54f8ff8c3c784191dc99b8bf7`;
- local compile: **112/112**;
- approved targets: **7/7**;
- compile duration: **435 seconds**;
- package closure: 5 executables, 2 static libraries, 26 fixtures, 47 checksums;
- artifact SHA-256: `7e520acda5d402300711d1803a666e505ce4a03c0b92d969f5ae2ba3ca2d1f28`;
- tests/benchmarks during build: none;
- remote implementation commit: pending because the Actions apply job was cancelled during the outage.

Do not call `5649cbe6...` the implementation commit. It contains the exact patch payload and trigger state, not the five applied source files.

## Direct producer baseline before Gate 1 patch

- [ ] plane — completion validation failure after 106 traces, 9 arrangement cells, and 12 candidate quads;
- [ ] multi-face seam — `SideSubdivisionRepair:InvalidInputIncidence`, zero cells/quads;
- [ ] close sheets — `SideSubdivisionRepair:InvalidInputIncidence`, zero cells/quads;
- [ ] cylinder — `SideSubdivisionRepair:InvalidInputIncidence`, zero cells/quads.

All four used direct `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, and output origin `None`.

## High-level production gates

### G0 — Truthful authority

- [x] direct `SurfaceCells` requests fail closed;
- [x] fallback `Fail` is used for acceptance;
- [x] source-grid recovery is disabled;
- [x] only `CompletedSurfaceCells` can satisfy success;
- [x] strict source-authoritative validation remains mandatory.

### G1 — Uniform phase-front plane

Status: **active**.

- [x] authoritative local phase and integer lattice coordinates represented;
- [x] directed front-edge ownership represented;
- [x] deterministic phase/front hashing and pipeline accounting;
- [x] bounded planar uniform grid and source-attached side paths;
- [x] compatible interior-edge merge events;
- [x] explicit boundary termination events;
- [x] authoritative proposal-cycle arrangement path;
- [x] fan-sector connectivity inference bypassed on that path;
- [x] all approved targets compile and link;
- [ ] exact five source blobs committed to the working branch;
- [ ] plane direct acceptance passes strict validation or reaches a materially later first invalid stage;
- [ ] non-empty pure-quad `CompletedSurfaceCells` output with no fallback/recovery.

### G2 — Cross-chart and close-sheet propagation

Blocked by G1.

- [ ] authoritative chart-transition phase transport;
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

## Next Test + Benchmark checklist

Use `.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Plan.md`.

- [ ] verify outer artifact SHA-256;
- [ ] verify all 47 internal checksums;
- [ ] verify source-authority and final-blob manifests;
- [ ] run plane in a fresh process;
- [ ] run seam, close sheets, and cylinder in that order;
- [ ] run remaining default suites;
- [ ] run three independent bounded benchmark processes per analytic fixture;
- [ ] perform no rebuild or source/test/fixture/validator edit.

## Progress-control rules

- Every turn names the active gate and material-progress condition.
- Direct gate results are reported before aggregate totals.
- A diagnostic subtype, counter, hash, or ownership class is not progress by itself.
- Two consecutive Code + Build turns without material progress trigger a design review or bounded replacement proof.
- Do not work on a blocked gate.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `tests/TESTING_STRATEGY.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `TODO`

Every completed turn ends with a new top-level PR #8 handoff comment after all documentation and PR metadata writes. That comment is the final repository write.

P5 remains open.
