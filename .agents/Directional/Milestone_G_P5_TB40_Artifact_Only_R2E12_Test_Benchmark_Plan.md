# Milestone G P5-TB40 Artifact-Only R2E12 Test + Benchmark Plan

**Date:** 2026-08-05
**Turn type:** Test + Benchmark, artifact-only
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`
**Review policy:** `never`

## Purpose

Validate P5-R2E12's first-class normalized authoritative exterior-pair inventory directly from the compiled artifact. Determine whether it removes the deterministic P5-TB39 `ExteriorPairMismatch` failures and allows the unchanged planar and hard-rail topology gates to execute.

## Exact artifact authority

- source commit: `556efab8c26e012a6019e0b0a10fb847fc8e2ace`;
- workflow event commit: `50d5db4280a5008764f73e5ba0a1827ce63eab1e`;
- workflow run/job: `31060329035` / `92486695630`;
- artifact ID: `8951981127`;
- artifact name: `surface-cell-p5-r2e12-github-source-linux-release`;
- artifact SHA-256: `7472441fb8b4f82d7e7bc5a62066a8a3db2022851f72c809bb45244bb1b996f0`;
- configuration: Release, `-O2 -DNDEBUG`;
- internal manifest entries: **20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**.

## Hard prohibitions

- no configure, rebuild, relink, regeneration, patch, or binary replacement;
- no implementation, test, benchmark, fixture, validator, workflow, or build-system modification;
- no fallback or source-grid recovery substitution for direct `SurfaceCells` acceptance;
- no legacy backend execution in direct production runs;
- no timeout-as-correctness;
- no synthetic pass, result editing, failure omission, or downstream compensation;
- no merge or ready-for-review transition.

## Artifact integrity gate

1. Download artifact `8951981127` through the GitHub connector.
2. Verify the exact outer SHA-256.
3. Extract into a clean arbitrary directory.
4. Verify all manifest entries from the package parent so the recorded `artifact/` prefix remains authoritative.
5. Verify `SOURCE_COMMIT`, `WORKFLOW_EVENT_COMMIT`, all four recorded source/test blobs, clean source status, nine recursive submodules, required binaries/libraries, and executable-relative fixture closure.
6. Record machine, OS, CPU, memory, and timing context.
7. Execute only packaged binaries.

If integrity fails, classify infrastructure separately and do not claim product pass or fail.

## Runtime order

### 1. Source-chart and validator prerequisites

Run the established source-chart transition and source-authoritative validator groups first. Require the P5-TB39 **17/17** baseline.

### 2. Focused exterior-pair diagnostics

Run the planar higher-valence and interior-hard-rail tests at least three independent times. Record:

- aggregate incidence failure;
- derived `boundaryFanConflict`;
- node/incoming/source-ray/target tuple;
- normalized canonical pair count;
- exterior exclusion count;
- structural diagnostic hash.

Acceptance at this stage requires neither target to reproduce P5-TB39 `ExteriorPairMismatch`:

- planar prior tuple: `3 / 11 / 10 / 9`;
- hard-rail prior tuple: `1 / 7 / 6 / 1`.

If either still fails, require deterministic non-`None` derived evidence and stop diagnosis at the earliest producer. Do not patch downstream behavior.

### 3. Focused R2 arrangement set

Run the established R2 focused inventory containing:

- planar higher-valence source-boundary fixture;
- degree-two source-boundary fixture;
- genuine four-bounded-disk fixture;
- interior hard-rail fixture;
- source-row and whole-orientation permutations;
- pinched and cyclic boundary-node fixtures;
- disconnected close sheets;
- bridge/support constraints;
- nested non-disk and nonmanifold rejection fixtures.

For planar require and record:

- positive normalized pair inventory;
- exactly one explicit authoritative exterior record;
- exact exterior exclusion count `1`;
- no interior chart witness required for the exterior pair;
- one-to-one incoming and target cover;
- positive genuine cyclic-wrap interior-sector count;
- one exterior plus expected bounded disks;
- Euler characteristic `1`;
- valid embedding, disk, loop, orientation, area, ownership, and aggregate topology.

For hard rail require and record:

- exactly one explicit authoritative exterior record and exclusion;
- both rail-side interior pairs published from exact chart witnesses;
- two incident chart roots and distinct opposite-side selected roots;
- every halfedge of each complete bounded orbit carrying its selected root;
- no root loss, root change, exterior entry, barrier crossing, or ownership conflict;
- one exterior plus two bounded disks;
- valid embedding, disk, loop, Euler, orientation, area, ownership, and aggregate topology.

Assess first failure stage and diagnostics, not only counts.

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
10. complete suite with XML, exit-state, wall-time, and RSS evidence.

Baselines:

- P5-TB36/R2E8: Phase 17 **26/26**, complete **603/625**;
- P5-TB39/R2E11 split inventory: Phase 17 **20/26**, complete **597/625**;
- P5-TB39 R2 focused: **13/16**.

The six Phase 17 tests must recover naturally through valid upstream arrangements. Do not modify or reinterpret Phase 17.

### 5. Single-process nontermination check

P5-TB39 observed two single-process complete-suite stalls when the P27 matrix reached the bunny case after prior suite state. Repeat one bounded single-process full-suite attempt with progress and process-state evidence.

- A normal completion supplies authoritative full-suite timing/RSS.
- A stall is a separate performance/nontermination regression, not correctness evidence.
- Regardless of a stall, execute a complete non-overlapping split inventory to preserve the 625-test correctness/failure-set authority.
- Do not alter P27 or bunny behavior in this turn.

### 6. Direct production processes

After focused and aggregate evidence, run independent packaged processes for the established analytic cases and `bunny_1k_random.obj` using:

- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- no legacy backend execution.

Record terminal stage, aggregate and derived failures, output counts, arrangement/simplified/quad counts, wall time, peak memory, structural hashes, and determinism. A clean process exit with `success=false` remains a production failure.

## Acceptance criteria

R2E12 may be accepted only if:

1. artifact integrity and exact source authority pass;
2. planar and hard rail no longer reject with `ExteriorPairMismatch` before publication;
3. each boundary-fan node owns exactly one explicit authoritative exterior pair and exclusion;
4. all non-exterior pairs have exactly one reconciled chart witness and complete incoming/target coverage;
5. planar naturally reaches positive wrap evidence and Euler-one valid disk topology through unchanged validators;
6. hard rail naturally reaches distinct complete-orbit roots and valid embedding/topology;
7. degree-two, four-disk, permutation, pinched-fan, close-sheet, bridge/support, nested, nonmanifold, recovery, and feature/barrier authority does not regress;
8. Phase 17 returns to **26/26** without Phase 17 changes;
9. no fallback, recovery, arbitrary selection, synthetic counter, validator weakening, fixture special-case, or timeout masks a defect.

Compile evidence alone does not satisfy these criteria.

## Required outputs

- P5-TB40 Test + Benchmark report;
- machine-readable runtime summary;
- complete evidence archive;
- updated TODO, milestone tracker, live handoff, and PR body;
- next Code + Build plan from the earliest remaining authoritative producer;
- final top-level PR #8 handoff comment after all other repository and PR metadata writes.

PR #8 remains open, draft, and unmerged. R2 remains open until runtime evidence proves closure.
