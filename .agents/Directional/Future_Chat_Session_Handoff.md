# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB22 artifact-only runtime validation is complete. The recently added `.agents/Directional/REORIENTATION_PLAN.md` has been reviewed and adopted as the authoritative remediation order.

The implementation should not proceed with CB143–CB150 as one broad turn. The next turn is **P5-R0/R1 code changes plus compile-only build**:

- **R0:** freeze downstream repair expansion and make source-grid recovery non-authoritative/default-off.
- **R1:** implement canonical source-entity chart transitions.

P5 remains open.

## Tested authority

- exact source `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- artifact `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`;
- artifact SHA-256 `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`;
- reviewed patch SHA-256 `890dd621cf549f32c55d44f52b85050bfdfa5ce15df5f2bda2f8ba3e33c8ed70`;
- empty source status;
- checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**.

P5-TB22 performed no configure, rebuild, relink, patch, regeneration, or source modification.

Runtime baseline:

- complete suite **585/600**, terminating in **103.441 s**;
- Phase 14–18 **236/236**;
- Milestone D **6/7**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase20 **46/48**;
- direct production **0/8**.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/DESIGN.md`
4. `.agents/Directional/REORIENTATION_PLAN.md`
5. `.agents/Directional/Milestone_G_P5_R0_R1_Reoriented_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_TB22_Artifact_Only_Test_Benchmark_Report.md`
7. `benchmark-results/p5-tb22-summary.json`
8. `.agents/Directional/GitHub_Workflow_Policy.md`

The earlier `.agents/Directional/Milestone_G_P5_Post_TB22_Producer_Correction_Code_Build_Plan.md` remains historical diagnosis only. Its CB143–CB150 execution order is superseded.

## Reorientation review

The plan’s central verdict is correct:

- do not rewrite the backend;
- preserve source provenance, typed pipeline state, rollback, deterministic diagnostics, and strict validation;
- stop expanding repair/observability infrastructure before the constructive producers work;
- move source-chart identity, directed incidence, topology-distinct completion, and phase/front state ahead of cache, lineage, and memory work.

One editorial inconsistency exists: some detailed section headings use R6/R7/R8 differently from the final revised task list. The authoritative execution sequence is:

1. R0 — freeze repair expansion and recovery authority;
2. R1 — source-entity chart transitions;
3. R2 — directed wedge/incidence reconstruction;
4. R3 — topology-distinct patch completion;
5. R4 — repeated-node wedge/splice producer;
6. R5 — explicit local lattice phase and advancing-front events;
7. R6 — torus decomposition/descriptor support;
8. R7 — adaptive dyadic 2:1 transitions;
9. R8 — direct production validation;
10. R9 — real cache reuse;
11. R10 — later-stage lineage fixtures;
12. R11 — synchronized memory telemetry.

Do not combine these into one turn. Validate each foundational producer before advancing.

## Why R1 is first

The simplest supported cases already generate substantial output and then fail source-chart ownership:

- plane: 12 quads, `LocalSheetMismatch`, cell 4 / face 7;
- multi-face seam: 24 quads, cell 2 / face 15;
- close sheets: 34 quads, cell 3 / face 13.

The current resolver requires literal common source-face support. That is invalid for one intrinsic source vertex or edge represented in adjacent source-face charts.

R1 must construct orientation-aware chart transitions and canonical source entities while preserving separate components, local sheets, hard-rail sectors, and nonmanifold vertex fans.

## P5-R0/R1 implementation requirements

Follow `.agents/Directional/Milestone_G_P5_R0_R1_Reoriented_Code_Build_Plan.md` exactly.

### R0

- Preserve existing typed failures, structural hashes, exact rollback, and fail-closed behavior.
- Add no new ownership classification unless existing categories cannot represent the earliest producer.
- Keep direct production at fallback `Fail`, no legacy execution, and recovery disabled.
- Make `allowSourceGridRecovery` default `false`, or expose recovery through a distinct non-authoritative backend/output origin.
- Do not touch cache reuse, injected-stage lineage, memory telemetry, or general FlowRep simplification.

### R1

Construct a graph whose chart nodes are `(component, localSheet, sourceFace)` and whose transitions are exact shared source-vertex/source-edge incidences with orientation-aware barycentric maps.

At source vertices, partition incident charts into intrinsic fans. Split fans at:

- source boundaries;
- component boundaries;
- local-sheet boundaries;
- hard rails;
- nonmanifold sectors.

Use the graph for:

- arrangement-node identity;
- completion generated-vertex provenance;
- shared completed vertices and edges;
- global stitch/output assembly;
- source-authoritative validation.

World-space position and source-triangle pairing are forbidden as identity.

Add compile-valid tests for:

- shared source edge;
- shared source vertex within one intrinsic fan;
- hard-rail separation;
- nonmanifold/disconnected fan separation;
- close-sheet separation;
- face-row permutation;
- orientation inverse;
- inconsistent transition-cycle rollback.

Do not execute the tests in this turn.

## Explicit non-goals

Do not implement R2–R11 during P5-R0/R1.

In particular, do not add:

- more completion rotations/reversals;
- more single-interface exclusions;
- cylinder occurrence-splitting repair;
- topology-distinct completion templates yet;
- phase/front events yet;
- torus or adaptive transition work;
- cache, lineage, or memory changes;
- bunny-specific conditions.

## Compile-only boundary

Shallow-initialize recursive submodules and compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable.

Initialize detailed workflow logging before fallible work and upload the full log artifact regardless of success or failure.

## Next runtime turn

P5-TB23 must execute the packaged artifact directly with no rebuild or source modification.

Run focused R0/R1 tests and analytic fixtures first:

1. plane;
2. multi-face seam;
3. close sheets;
4. disconnected close sheets;
5. source orientation reversal;
6. face-row/insertion-order permutations;
7. transition-cycle inconsistency and rollback.

Do not run the full bunny matrix solely for an R1 change. Proceed to R2 only after the R1 analytic gate is understood.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- Deterministic failure is useful evidence, not a valid producer.
- Adjacent source-face charts may describe one intrinsic source entity without sharing a literal face ID.
- Directed incidence and patch topology must be constructed correctly rather than inferred through downstream repair.
- Explicit phase/front state is a required architectural stage, but it should follow independent closure of the immediate source-chart producer.
- Cache, lineage, and memory work should resume only after direct geometry succeeds on a meaningful analytic subset.
