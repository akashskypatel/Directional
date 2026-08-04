# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB26 artifact-only validation is complete against artifact `8908691591` and exact source `306fab5d440199cb090e1aa343fadb6112663edc`.

R2 does **not** close. The new directed-wedge permutation contracts mostly pass, but valid boundary, disconnected-component, singularity-fan, hard-rail, and periodic-cylinder sectors are omitted from the audited cycle/cell inventory. Do not advance to R3.

Package authority:

- artifact `8908691591`, `surface-cell-p5-r2-final-github-source-linux-release`;
- archive SHA-256 `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`;
- workflow event `b332bb3119a133b957b2f573a5bd447d4ca62d4e`;
- reviewed patch SHA `e4da79427d33a5fd7bf29b707ec0765974faf0bc67c2dc18e6f2e6e6dd9a8658`;
- empty source status;
- recursive checksums **41/41**;
- package files **43**;
- fixtures **26**;
- recursive submodules **9**;
- no configure, rebuild, relink, patch, regeneration, or source modification during P5-TB26.

The next turn is **P5-R2C directed boundary-sector and cycle-inventory correction plus compile-only build**. Compile exactly the four required targets and execute no project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB26_Artifact_Only_R2_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb26-summary.json`
5. `.agents/Directional/Milestone_G_P5_R2C_Directed_Boundary_Cycle_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_R2_Code_Build_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB26 runtime results

- source-chart R1: **11/11**;
- Phase 22 source validator: **6/6**;
- recovery authority: **9/9**;
- feature-rail/barrier authority: **8/8**;
- graph-dependent: **5/6**;
- R2 focused: **6/7**;
- Milestone D: **4/7**;
- Phase 14–18: **227/240**;
- Phase 16: **39/43**;
- Phase 17: **18/26**;
- Phase 18: **57/57**;
- Phase 20: **46/48**;
- complete suite: **588/621**, terminated normally in **74.763 seconds**;
- exact maximum RSS: unavailable because the outer timing shell detached before final statistics.

The dominant bunny executions are approximately 23–24 seconds, versus 108–113 seconds in P5-TB25. Failures regress from 19 to 33. Treat this as faster early rejection, not performance success.

## Direct analytic disposition

All cases used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy output.

- plane: 9 arrangement cells, 12 quads, 15 aggregate validation failures;
- multi-face seam: 0 cells, 0 quads, `SideSubdivisionRepair:InvalidInputIncidence`;
- close sheets: 0 cells, 0 quads, `SideSubdivisionRepair:InvalidInputIncidence`;
- cylinder: 0 cells, 0 quads, `SideSubdivisionRepair:InvalidInputIncidence`.

Seam and close sheets regress from later output-validation failures to empty arrangement inventories. Cylinder regresses from a later pattern bow-tie to empty incidence. No fallback, recovery, or legacy execution occurred.

## Earliest R2 root cause

The R2 implementation publishes cells only from `auditedCycles`. Valid sectors are rejected or omitted before cell assignment:

- valid halfedges retain `cell == -1`;
- cylinder reports `invalid-cell cell=-1 halfedge=0 twin=1 next=4`;
- planar Euler is `-1`, area error is `1`, and no boundary cycle exists;
- disconnected components produce zero interior cells;
- an interior hard rail produces two exterior cycles;
- the bunny singularity fan produces zero center cells instead of three;
- eight Phase 17 contracts lose valid arrangement candidates.

Phase 18 remains clean. R2 valid cycle/cell ownership is therefore earlier than R3 completion work.

## P5-R2C required work

1. Separate one-to-one successor/predecessor validity from interior/exterior cycle classification.
2. Represent source-boundary sectors explicitly and close their exterior successor relation from exact source topology.
3. Prevent interior hard rails from voting as source boundaries or producing extra exterior cycles.
4. Require every valid halfedge to belong to exactly one audited cycle and receive exactly one cell ID.
5. Preserve valid periodic seam closure across R1 chart transitions.
6. Restore planar, disconnected-component, non-disk/candidate, singularity-fan, seam, close-sheet, and cylinder cycle inventories.
7. Preserve typed fail-closed rejection for genuinely missing, ambiguous, nonmanifold, repeated-node, repeated-edge, short, or incomplete incidence.
8. Preserve R1 exact adjacency, local-sheet provenance, `directedIncidenceHash`, source-row/orientation invariance, and rollback identity.
9. Do not restore post-hoc repeated-node decomposition.
10. Keep R3–R11 deferred.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Run no tests, benchmarks, custom meshes, help/list/discovery commands, or generated executables. Initialize persistent logs before fallible work and always upload the logs and exact-source artifact.

## P5-TB27 runtime gate

The artifact-only turn after R2C must require:

- all R1 authority remains clean;
- all directed-incidence and new cell-inventory tests pass;
- Milestone D **7/7**;
- Phase 16 and Phase 17 return to the clean pre-R2 baseline plus new tests;
- Phase 14–18 is clean;
- seam, close sheets, and cylinder retain nonzero valid arrangement cell inventories;
- no valid halfedge has `cell == -1`;
- analytic failures improve or move to a later typed completion producer;
- Phase 20 does not regress;
- the complete suite terminates;
- bunny duration and memory are measured without treating faster failure as correctness.

Advance to R3 only after these R2 gates close.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition;
- no timeout-as-correctness.

## Key lessons

- Passing narrow successor/permutation tests is insufficient when valid boundary sectors are absent from the published cycle/cell inventory.
- Exterior classification must follow complete audited cycle construction; interior hard rails cannot substitute for source boundaries.
- Faster rejection reduced bunny time but increased failures. Correctness remains the gate.
