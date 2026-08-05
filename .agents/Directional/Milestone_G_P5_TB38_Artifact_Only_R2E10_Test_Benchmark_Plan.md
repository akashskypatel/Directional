# Milestone G P5-TB38 Artifact-Only R2E10 Test + Benchmark Plan

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`

## Purpose

Validate the P5-R2E10 normalized canonical boundary fan-cover and continuous wrap-witness implementation directly from its compiled artifact.

The turn must determine whether R2E10 restores the valid R2E8 incidence baseline while retaining R2E9 canonical-pair and hard-rail complete-orbit authority.

## Exact artifact authority

- source commit: `bf33049157dfee51a1b6c48dff35a97ce980e49f`;
- workflow event commit: `4831349b3d8c996a44bbd804f12ad01be9e3446f`;
- workflow run/job: `31051610854` / `92459824013`;
- artifact ID: `8948771075`;
- artifact name: `surface-cell-p5-r2e10-github-source-linux-release`;
- artifact SHA-256: `d0815a8423cd71758eb4f1033c0d3f19fd34261df4ea5c32efcf80b2069c3210`;
- configuration: Release, `-O2 -DNDEBUG`;
- internal manifest entries: `19`;
- recursive submodules: **9**.

## Hard prohibitions

- no configure, rebuild, relink, regeneration, patch, or binary replacement;
- no implementation, test, fixture, validator, workflow, or build-system modification;
- no fallback or source-grid recovery substitution for direct `SurfaceCells` acceptance;
- no legacy backend execution in direct production runs;
- no timeout-as-correctness;
- no synthetic pass, result editing, or omission of failures;
- no merge or ready-for-review transition.

## Artifact preparation

1. Download artifact `8948771075` through the GitHub connector.
2. Verify the archive SHA-256 exactly.
3. Extract into a clean arbitrary directory.
4. Verify every internal checksum-manifest entry.
5. Confirm `SOURCE_COMMIT`, `WORKFLOW_EVENT_COMMIT`, all four changed-file blob records, empty source status, nine recursive submodules, required binaries/libraries, and executable-relative fixture closure.
6. Stage fixture files byte-identically only as needed by packaged executable-relative tests.
7. Record machine, OS, CPU, memory, and timing context.
8. Execute only packaged binaries.

If artifact integrity fails, classify infrastructure separately and do not claim product pass or fail.

## Required runtime order

### 1. Source-chart and validator prerequisites

Run the established source-chart transition and source-authoritative validator groups first. Require the P5-TB37 **17/17** baseline.

### 2. Focused R2 arrangement set

Run the established focused set containing:

- planar higher-valence source-boundary fixture;
- degree-two source-boundary fixture;
- genuine four-bounded-disk fixture;
- interior hard-rail fixture;
- source-row and whole-orientation permutations;
- pinched and cyclic boundary-node fixtures;
- disconnected close sheets;
- bridge/support constraints;
- nested non-disk and nonmanifold rejection fixtures.

For planar, record and require:

- positive normalized canonical directed-pair inventory;
- exact exterior relation present and excluded once;
- positive accepted cyclic-wrap interior-sector count;
- complete incoming/target bijection and predecessor multiplicity one;
- one exterior cell plus the expected bounded disk inventory;
- no repeated node or edge cycle;
- Euler characteristic `1`;
- valid embedding, disk, loop, orientation, area, ownership, and aggregate topology.

For hard rail, record and require:

- positive normalized canonical-pair inventory;
- one exterior exclusion per boundary fan-sector node;
- two exact incident chart roots;
- one authoritative root per complete bounded orbit;
- distinct roots for opposite rail sides;
- every halfedge of each bounded orbit carrying its selected root;
- no root loss, root change, exterior entry, barrier crossing, or conflicting orbit ownership;
- one exterior plus two bounded disks;
- valid embedding, disk, loop, Euler, ownership, orientation, area, and aggregate topology.

Record the first typed failure, diagnostics, and structural hash for every focused case. Do not rely on pass totals alone.

### 3. Regression and phase aggregates

Run in this order:

1. recovery authority;
2. feature/barrier authority;
3. graph-dependent focused group;
4. Milestone D;
5. Phase 16;
6. Phase 17;
7. Phase 18;
8. Phase 14–18 aggregate;
9. Phase 20;
10. complete suite with XML and RSS evidence.

Required comparison baselines:

- P5-TB36: Phase 17 **26/26**, complete **603/625**;
- P5-TB37: Phase 17 **20/26**, complete **597/625**;
- R2 focused count **13/16** at both checkpoints, but P5-TB37 moved planar and hard rail to an earlier incidence failure.

R2E10 must be assessed by failure stage and diagnostics, not only counts.

### 4. Direct production processes

After focused and aggregate evidence, run independent packaged processes for the established direct analytic cases and `bunny_1k_random.obj` using:

- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- no legacy backend execution.

Record wall time, peak resident memory, terminal stage, typed failure, output counts, arrangement counts, structural hashes, and determinism. A clean process exit with `success=false` is a production failure.

## Acceptance criteria

R2E10 may be accepted only if:

1. planar and hard rail no longer fail `BoundaryFanSectorCoverConflict` before publication;
2. planar publishes the required wrap sector and naturally reaches Euler-one valid disk topology through unchanged validators;
3. hard rail publishes one exact root per complete bounded orbit, distinct opposite roots, and passes unchanged embedding/topology validators;
4. degree-two and genuine four-disk fixtures remain valid;
5. row and orientation permutations remain structurally identical;
6. pinched-fan, close-sheet, bridge/support, nested, nonmanifold, recovery, and feature/barrier authority does not regress;
7. Phase 17 returns to **26/26** without Phase 17 changes;
8. no fallback, recovery, arbitrary selection, synthetic counter, validator weakening, fixture special-case, or timeout masks failure;
9. all diagnostics are derived from accepted records.

Compile evidence alone does not satisfy these criteria.

## Required outputs

- P5-TB38 Test + Benchmark report;
- machine-readable runtime summary;
- complete evidence archive;
- updated TODO, milestone tracker, live handoff, and PR body;
- next Code + Build plan from the earliest remaining authoritative producer;
- final top-level PR #8 handoff comment after all other repository and PR metadata writes.

PR #8 remains open, draft, and unmerged. R2 remains open until runtime evidence proves closure.
