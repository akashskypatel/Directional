# Milestone G P5-TB39 Artifact-Only R2E11 Test + Benchmark Plan

**Date:** 2026-08-05
**Turn type:** Test + Benchmark, artifact-only
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`

## Purpose

Validate the P5-R2E11 normalized chart-entity ownership, pair-first witness reconciliation, and derived boundary-cover diagnostics directly from the compiled artifact.

The turn must determine whether R2E11 restores the R2E8 incidence baseline and advances planar/hard-rail validation beyond the pre-publication `BoundaryFanSectorCoverConflict` observed in P5-TB37 and P5-TB38.

## Exact artifact authority

- source commit: `b3010a36f762bb7317f2201d94733226b418c2c0`;
- workflow event commit: `5e96846a55acc8fd085836db886fcddbb5cd1dac`;
- workflow run/job: `31056835353` / `92476050630`;
- artifact ID: `8950709981`;
- artifact name: `surface-cell-p5-r2e11-github-source-linux-release`;
- artifact SHA-256: `012a7782726b849ece1aa72286ae2ae9eb98b6a803106813b87caf348939a31c`;
- configuration: Release, `-O2 -DNDEBUG`;
- internal manifest entries: **20**;
- packaged files including manifest: **21**;
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

1. Download artifact `8950709981` through the GitHub connector.
2. Verify the archive SHA-256 exactly.
3. Extract into a clean arbitrary directory.
4. Verify every internal checksum-manifest entry.
5. Confirm `SOURCE_COMMIT`, `WORKFLOW_EVENT_COMMIT`, all four recorded source/test blobs, empty source status, nine recursive submodules, required binaries/libraries, and executable-relative fixture closure.
6. Stage fixture files byte-identically only as needed by packaged executable-relative tests.
7. Record machine, OS, CPU, memory, and timing context.
8. Execute only packaged binaries.

If integrity fails, classify infrastructure separately and do not claim product pass or fail.

## Required runtime order

### 1. Source-chart and validator prerequisites

Run the established source-chart transition and source-authoritative validator groups first. Require the P5-TB38 **17/17** baseline.

### 2. Derived diagnostic authority

Run focused invalid boundary-cover cases that naturally reach `BoundaryFanSectorCoverConflict`. Require:

- aggregate incidence failure remains `BoundaryFanSectorCoverConflict`;
- `boundaryFanConflict` is a non-`None` derived subreason;
- node/incoming/source-ray/target evidence corresponds to the rejected record;
- row-order and whole-orientation permutations produce structurally equivalent diagnostics;
- no derived counter or subreason is synthesized after publication.

Record the exact derived subreason for planar and hard rail if either still fails. A generic aggregate failure with `boundaryFanConflict == None` is an R2E11 diagnostic failure.

### 3. Focused R2 arrangement set

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
- `boundaryFanConflict == None` on accepted publication;
- positive accepted cyclic-wrap interior-sector count;
- complete incoming/target bijection and predecessor multiplicity one;
- one exterior cell plus expected bounded disk inventory;
- no repeated node or edge cycle;
- Euler characteristic `1`;
- valid embedding, disk, loop, orientation, area, ownership, and aggregate topology.

For hard rail, record and require:

- positive normalized canonical-pair inventory;
- one exterior exclusion per boundary fan-sector node;
- `boundaryFanConflict == None` on accepted publication;
- two exact incident chart roots;
- one authoritative root per complete bounded orbit;
- distinct roots for opposite rail sides;
- every halfedge of each bounded orbit carrying its selected root;
- no root loss, root change, exterior entry, barrier crossing, or conflicting orbit ownership;
- one exterior plus two bounded disks;
- valid embedding, disk, loop, Euler, ownership, orientation, area, and aggregate topology.

Record the first aggregate failure, derived subreason, diagnostics, and structural hash for every focused case. Do not rely on pass totals alone.

### 4. Regression and phase aggregates

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

Comparison baselines:

- P5-TB36/R2E8: Phase 17 **26/26**, complete **603/625**;
- P5-TB38/R2E10: Phase 17 **20/26**, complete **597/625**;
- R2 focused **13/16** at both checkpoints, with different failure stages.

Assess failure stage and derived diagnostics, not only counts.

### 5. Direct production processes

After focused and aggregate evidence, run independent packaged processes for the established direct analytic cases and `bunny_1k_random.obj` using:

- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- no legacy backend execution.

Record wall time, peak resident memory, terminal stage, aggregate and derived failures, output counts, arrangement counts, structural hashes, and determinism. A clean process exit with `success=false` is a production failure.

## Acceptance criteria

R2E11 may be accepted only if:

1. artifact integrity and exact source authority pass;
2. every boundary-cover rejection supplies an accurate derived subreason while preserving the aggregate fail-closed failure;
3. planar and hard rail no longer fail before publication;
4. planar publishes the required wrap sector and naturally reaches Euler-one valid disk topology through unchanged validators;
5. hard rail publishes one exact root per complete bounded orbit, distinct opposite roots, and passes unchanged embedding/topology validators;
6. degree-two and genuine four-disk fixtures remain valid;
7. row and orientation permutations remain structurally identical;
8. pinched-fan, close-sheet, bridge/support, nested, nonmanifold, recovery, and feature/barrier authority does not regress;
9. Phase 17 returns to **26/26** without Phase 17 changes;
10. no fallback, recovery, arbitrary selection, synthetic counter, validator weakening, fixture special-case, or timeout masks failure.

Compile evidence alone does not satisfy these criteria.

## Required outputs

- P5-TB39 Test + Benchmark report;
- machine-readable runtime summary;
- complete evidence archive;
- updated TODO, milestone tracker, live handoff, and PR body;
- next Code + Build plan from the earliest remaining authoritative producer;
- final top-level PR #8 handoff comment after all other repository and PR metadata writes.

PR #8 remains open, draft, and unmerged. R2 remains open until runtime evidence proves closure.
