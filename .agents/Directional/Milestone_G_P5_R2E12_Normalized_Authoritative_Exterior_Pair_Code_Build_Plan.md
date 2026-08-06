# Milestone G P5-R2E12 Normalized Authoritative Exterior-Pair Inventory Code + Build Plan

**Date:** 2026-08-05
**Turn type:** Code + Build
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`
**Review policy:** `never`

## Purpose

Correct the earliest P5-TB39 producer failure: the exact independently proven exterior relation is absent or mismatched in the normalized node-level `canonicalPairInventory` for both the planar higher-valence boundary and interior-hard-rail fixtures.

R2E12 must make the exterior pair a first-class normalized canonical pair before chart-corner interior witness resolution. It must not weaken the aggregate `BoundaryFanSectorCoverConflict` gate or select a relation by count, order, frequency, ranking, or arbitrary subset.

## Exact entry evidence

- tested source: `b3010a36f762bb7317f2201d94733226b418c2c0`;
- artifact: `8950709981`;
- planar derived failure: `ExteriorPairMismatch`, tuple `node=3, incoming=11, sourceRay=10, target=9`;
- hard-rail derived failure: `ExteriorPairMismatch`, tuple `node=1, incoming=7, sourceRay=6, target=1`;
- both reject at the exact-one exterior-key gate before chart witness reconciliation and successor publication;
- P5-TB39 split complete inventory: **597/625**; Phase 17 **20/26**.

## Required implementation

1. Derive the exterior directed triple only from existing authoritative source-boundary topology:
   - `exteriorIncoming`;
   - its exact outgoing twin `exteriorTwin`;
   - `desiredExteriorNext[exteriorIncoming] == exteriorOutgoing`;
   - authoritative source-boundary loop identity and side evidence.
2. Before generic chart-corner filtering, resolve the exterior twin/outgoing rays to one normalized source-entity key and one transition-component root using all agreeing exact witnesses.
3. Create or reconcile one `CanonicalFanPairRecord` for the exact exterior triple.
   - A generic fan contribution may merge only when normalized entity key, transition root, directed triple, and source-boundary identity agree exactly.
   - Any disagreement, missing root/entity evidence, duplicate non-identical record, or contradictory source-boundary ownership fails transactionally as `ExteriorPairMismatch` or a more precise derived subreason while retaining aggregate `BoundaryFanSectorCoverConflict`.
4. Mark exterior authority explicitly in the record instead of inferring it from iteration or chart order.
5. Exclude the exact exterior pair once from interior chart-corner witness publication. The unbounded side must not be forced to own an interior face-corner witness.
6. Audit the complete local pair cover before publishing any successor:
   - every incoming occurs exactly once;
   - every outgoing target occurs exactly once;
   - the authoritative exterior triple occurs exactly once;
   - every non-exterior pair has exactly one reconciled interior chart witness;
   - no interior pair duplicates the exterior incoming or target relation.
7. Preserve proven cyclic-wrap metadata on the canonical pair that owns it. Do not synthesize a wrap count after publication.
8. Preserve hard-rail separator evidence and complete bounded-orbit root propagation exactly. R2E12 should only enable the hard-rail fixture to reach that existing audit; do not bypass or pre-approve it.
9. Keep publication transactional: write `candidateNext`, `successorWedge`, `successorChartRoot`, and orbit roots only after the complete node inventory and all exterior/interior audits pass.
10. Keep the existing derived conflict diagnostics deterministic and record the exact earliest rejection tuple.

## Required semantic outcomes for the next runtime turn

### Planar

- no pre-publication `ExteriorPairMismatch`;
- normalized pair inventory is complete and one-to-one;
- exact exterior exclusion count is one;
- positive genuine cyclic-wrap interior-sector count;
- one exterior plus valid bounded disks;
- Euler characteristic `1` through unchanged validators;
- valid embedding, orientation, disk, loops, area, ownership, and aggregate topology.

### Interior hard rail

- no pre-publication `ExteriorPairMismatch`;
- exact exterior relation excluded once;
- both rail-side interior pairs publish from exact chart witnesses;
- opposite sides retain distinct incident roots;
- every complete bounded orbit carries one authoritative root;
- one exterior plus two bounded disks;
- unchanged embedding/topology validators pass.

## Preservation gates

Preserve without weakening or special-casing:

- degree-two boundary rotation;
- genuine four-bounded-disk fixture;
- source-row and whole-orientation invariance;
- pinched/cyclic boundary rejection;
- disconnected close sheets;
- bridge/support constraints;
- nested non-disk and nonmanifold rejection;
- source-chart and source-authoritative validator authority;
- recovery and feature/barrier authority;
- deterministic structural hashes and diagnostics.

## Explicitly out of scope

Do not modify or compensate for:

- Phase 17 implementation or tests;
- bunny singularity producer;
- cylinder simplification/completion;
- FlowRep pre-ring behavior;
- P27 production-matrix expectations or the newly observed cumulative-state stall;
- completion, optimization, fallback/recovery, legacy backend, fixtures, source-authoritative validators, or unrelated diagnostics.

Do not add fixture IDs, mesh-name checks, positional merging, arbitrary subset search, count/frequency ownership selection, synthetic counters/Euler correction, post-hoc cell decomposition, or timeout-based behavior.

## Allowed files

- `include/directional/geometry/SurfaceArrangement.h` only for narrowly derived exterior-pair diagnostic/state evidence;
- `src/geometry/SurfaceArrangement.cpp`;
- focused Phase 16 or Milestone D tests only if a semantic assertion must be strengthened, never to relax acceptance;
- current turn documentation.

## Compile-only gate

Push the exact source commit before building. Configure Release `-O2 -DNDEBUG` and compile exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_phase1_tests`;
4. `directional_benchmarks`.

Do not execute tests, benchmarks, custom inputs, CLI/GUI, help/list/discovery commands, or generated project binaries.

Package source, binaries, libraries, fixtures, source/test blob authority, recursive submodule status, clean source status, checksums, configure/build logs, and execution-policy metadata. Always upload the detailed activity log separately. Remove bounded workflows and temporary payloads after artifact verification.

## Exit requirements

- exact source commit and artifact authority recorded;
- four approved targets compile and link;
- no project binary executed;
- TODO, milestone tracker, live handoff, PR body, and next artifact-only test plan updated;
- stale current-turn report/plan/summary replaced only after new authority exists;
- final top-level PR #8 comment is the final repository write;
- PR remains open, draft, and unmerged;
- R2 remains open pending runtime evidence.
