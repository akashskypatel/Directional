# Milestone G P5-TB36 Artifact-Only R2E8 Test + Benchmark Plan

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`

## Purpose

Validate the P5-R2E8 canonical boundary corner-sector and hard-rail chart-root implementation directly from the packaged compile artifact.

Determine whether R2E8:

1. closes the planar `BoundaryFanSectorCoverConflict` producer;
2. makes the interior hard-rail fixture embedding- and topology-valid;
3. preserves all accepted R2E5, R2E6, and R2E7 incidence authority;
4. naturally restores any Phase 17 cases that previously received invalid upstream arrangements;
5. leaves the independent cylinder and bunny producers correctly classified.

## Exact artifact authority

- source commit: `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`;
- `SurfaceArrangement.cpp` blob: `76e57fef36f9322598387b6b5e968a14b885b755`;
- workflow run: `31041383154`;
- workflow event commit: `89423d0a49d7e1c2020cda87ee2333f35a3abe98`;
- artifact ID: `8944910920`;
- artifact SHA-256: `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`;
- configuration: Release, `-O2 -DNDEBUG`.

## Hard prohibitions

- no configure, rebuild, relink, regeneration, or binary replacement;
- no implementation, test, fixture, build-system, workflow, or validator modification;
- no fallback/recovery substitution for direct `SurfaceCells` acceptance;
- no timeout-as-correctness;
- no synthetic pass, result editing, or omission of failures;
- no merge or ready-for-review transition.

## Artifact preparation

1. Download artifact `8944910920` through the GitHub connector.
2. Verify the downloaded archive SHA-256.
3. Extract into a clean temporary directory.
4. Verify every packaged file using the internal `SHA256SUMS` manifest.
5. Confirm `SOURCE_COMMIT` and `WORKFLOW_EVENT_COMMIT` match the authority above.
6. Stage the packaged source archive exactly as required by packaged executable-relative fixtures.
7. Record machine, OS, CPU, memory, and timing context.
8. Execute only the packaged binaries.

## Required focused runtime order

### 1. Canonical source-chart and validator authority

Run the existing source-chart transition and source-authoritative validator groups first. These are prerequisite evidence for interpreting chart-root and close-sheet behavior.

### 2. R2 focused arrangement set

Execute the focused R2 set containing:

- planar boundary cyclic-wrap fixture;
- degree-two source-boundary fixture;
- genuine higher-valence four-disk fixture;
- interior hard-rail fixture;
- source-row permutation identity;
- whole-orientation reversal identity;
- pinched and cyclic boundary-node fixtures;
- disconnected close sheets;
- bridge/support constraints;
- nested non-disk and nonmanifold rejection fixtures.

Record for each affected case:

- typed incidence failure;
- direct corner-sector count;
- exterior exclusion count;
- cyclic-wrap interior-sector count;
- hard-rail chart-root count;
- hard-rail side-pair count;
- predecessor multiplicity;
- cell, bounded-cell, and exterior-cell counts;
- disk, embedding, ownership, Euler, boundary-loop, orientation, area, and aggregate topology status;
- structural hash.

### 3. Milestone and phase aggregates

Run, in this order:

1. Milestone D;
2. Phase 16;
3. Phase 17;
4. Phase 18;
5. Phase 14–18 aggregate;
6. Phase 20;
7. graph-dependent group;
8. complete suite, provided the execution window remains sufficient.

Also retain the established recovery and feature/barrier groups as regression authority, while keeping direct surface-paving acceptance separate from recovery behavior.

### 4. Production bunny processes

Only after focused and aggregate regressions are captured, run deterministic `bunny_1k_random.obj` production processes using:

- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- no legacy backend execution.

Use independent processes. Record wall time, peak resident memory, terminal stage, typed failure, output counts, structural hashes, and determinism. Do not reinterpret a timeout or failed-closed result as success.

## Required comparisons

Compare all results against P5-TB35 authority:

- complete suite: `597/625`;
- R2 focused: `13/16`;
- Phase 16: `45/47`;
- Phase 17: `20/26`;
- Phase 18: `57/57`;
- hard rail previously passed incidence, ownership, disk, loop, Euler, and cell-count checks but failed embedding/topology;
- planar previously failed `BoundaryFanSectorCoverConflict` before publication.

Classify every changed result as:

- intended producer closure;
- natural downstream restoration;
- preserved independent failure;
- regression;
- invalid fixture, only when the fixture is demonstrably incapable of exercising its stated purpose.

## Success criteria

P5-TB36 may accept R2E8 only if:

1. the planar fixture publishes a complete direct corner-sector relation without arbitrary selection and reaches the unchanged topology validators;
2. the hard-rail fixture has two distinct incident chart roots, valid bounded side orbits, valid embedding, and valid aggregate topology;
3. degree-two and genuine four-disk fixtures remain valid;
4. source-row and orientation permutations retain identical canonical structural results;
5. no close-sheet, bridge/support, nested, or nonmanifold regression is introduced;
6. no validator, fallback, or recovery mechanism masks an invalid direct result;
7. all observed counters are derived from actual accepted records.

## Outputs

Produce:

- P5-TB36 Test + Benchmark report;
- machine-readable runtime summary;
- complete evidence archive;
- updated TODO, milestone tracker, handoff, and PR description;
- the next Code + Build plan targeting the earliest remaining authoritative producer;
- a new final top-level PR #8 comment after all other repository writes.

PR #8 remains open, draft, and unmerged.
