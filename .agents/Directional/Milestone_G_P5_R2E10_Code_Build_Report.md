# Milestone G P5-R2E10 Code/Build Report

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E10 canonical wrap-pair chart-witness and unique boundary fan-cover reconciliation is implemented and compile-valid.

This turn corrects the earliest P5-TB37 producer regression without weakening the fail-closed incidence gate. The source now builds one normalized node-level canonical directed-pair inventory before chart resolution, reconciles only authoritative equivalent fan identities, resolves wrap witnesses in a continuous chart-corner interval, excludes the exact exterior relation once, and publishes only a complete one-to-one incoming/target cover.

Runtime acceptance is not claimed. P5-TB38 must execute the packaged binaries and determine whether planar and hard-rail incidence, planar wrap/Euler-one topology, hard-rail embedding, and Phase 17 **26/26** are restored.

R2 remains open. Do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `4831349b3d8c996a44bbd804f12ad01be9e3446f`;
- exact compiled source: `bf33049157dfee51a1b6c48dff35a97ce980e49f`;
- workflow run/job: `31051610854` / `92459824013`;
- build artifact: `8948771075`;
- build artifact name: `surface-cell-p5-r2e10-github-source-linux-release`;
- build artifact SHA-256: `d0815a8423cd71758eb4f1033c0d3f19fd34261df4ea5c32efcf80b2069c3210`;
- log artifact: `8948771526`;
- log artifact SHA-256: `e2a8b1ab9399952f3ffd029e747cc09271bb64906b5a8509e2ed6447e9f8bf20`;
- `SurfaceArrangement.cpp` blob: `359ae620448e777731d2d2292eda3d0050c42c61`;
- header blob: `b172625cd82862d16b81b6f3b8d52686b5fda41c`;
- Phase 16 test blob: `e58bceda098f7768b8a7203cca00564f82a7d831`;
- Milestone D test blob: `015a9f02354a91ca07d0e0c6bf6b2632055436ae`;
- recursive manifest: `19/19`;
- packaged files including the manifest: `20`;
- recursive submodules: **9**;
- compile/link actions: **132/132**;
- source status before packaging: empty.

## Implementation

### 1. Node-level canonical directed-pair inventory

The higher-valence boundary producer now creates a single node-level inventory keyed by:

```text
(incoming, sourceRay, target)
```

Canonical cyclic adjacency is still enumerated before chart filtering, including vector wrap. Multiple source-entity fan identities that produce the same directed key are not treated as separate complete covers.

Equivalent records are collapsed only when their normalized canonical source entity and exact transition-component root agree. All agreeing fan identities remain as provenance. Conflicting entities, roots, or incidence reject transactionally with `BoundaryFanSectorCoverConflict`.

This is deterministic equivalence reconciliation, not count-, order-, or frequency-based selection and not subset search.

### 2. Exact exterior relation

The authoritative exterior relation remains derived independently from the source-boundary continuation:

- authoritative exterior incoming halfedge;
- its twin as the source ray;
- authoritative exterior outgoing halfedge as the target.

The normalized node inventory must contain this exact directed key once. It is excluded once and only once before bounded-sector publication.

### 3. Continuous chart-corner witness resolution

Charts validate canonical pair records only after the node inventory exists.

For each non-exterior pair the producer:

1. resolves charts containing both rays;
2. maps source and target directions into one continuous unwrapped chart-corner interval;
3. applies the required `2*pi` source-angle lift for a wrap pair only when needed;
4. requires a positive oriented span contained by the exact chart corner;
5. rejects a candidate when a third ray from the canonical fan lies strictly inside the span;
6. deduplicates identical chart/root witnesses while requiring score agreement;
7. requires exactly one agreeing witness whose chart root equals the canonical transition root.

Chart filtering therefore cannot create or remove canonical adjacency.

### 4. Complete publication and hard-rail authority

Publication remains transactional. The accepted non-exterior sectors plus the exact exterior relation must form one complete incoming/target bijection before modifying `next`.

The R2E9 hard-rail complete bounded-orbit audit is retained:

- each selected root must remain present on every directed halfedge of the predicted bounded orbit;
- root changes, root loss, exterior entry, hard-barrier crossing, or conflicting orbit ownership reject publication;
- opposite bounded sides retain distinct roots;
- one authoritative embedding root is materialized per bounded cell while full provenance remains separate.

### 5. Focused contract

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` now also requires:

- positive canonical fan-pair inventory;
- one exact exterior exclusion per boundary fan-sector node.

No fixture data or identifiers were special-cased.

## Scope audit

Changed:

- `src/geometry/SurfaceArrangement.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

Unchanged:

- `include/directional/geometry/SurfaceArrangement.h`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- all Phase 17 implementation and tests;
- cylinder and bunny producers;
- FlowRep, completion, optimization, fallback/recovery, fixtures, source-authoritative validators, and unrelated tests.

## Compile gate

Configuration:

- Ubuntu 24.04;
- GNU C++ 13.3;
- Ninja;
- Release `-O2 -DNDEBUG`;
- static libraries;
- tests and benchmarks enabled;
- CLI, GUI, GMP, PARDISO, cuDSS, and SuiteSparse disabled.

Built exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_phase1_tests`;
4. `directional_benchmarks`.

No test, benchmark, help/list/discovery command, custom mesh, CLI, GUI, or generated project binary was executed.

## Workflow and repository hygiene

- The source commit was pushed before compilation and the package records that exact commit.
- The detailed activity log was initialized before checkout and uploaded separately.
- The bounded workflow and transfer payload were removed after artifact verification.
- Only the durable `.github/workflows/agent-source-snapshot.yml` remains.
- No temporary patch/payload directory or generated repository build artifact remains.

## Next turn

Execute **P5-TB38 artifact-only R2E10 Test + Benchmark** using build artifact `8948771075`.

Do not configure, rebuild, relink, patch, regenerate, or modify source, tests, fixtures, validators, workflows, or build logic. The runtime gate must determine whether R2E10:

1. restores planar and hard-rail successor publication;
2. restores planar canonical wrap evidence and Euler-one valid disk topology;
3. validates one complete authoritative hard-rail root per bounded orbit and aggregate embedding/topology;
4. restores Phase 17 **26/26** without Phase 17 changes;
5. preserves all accepted R2, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold authority.

R2 remains open until runtime evidence proves closure.
