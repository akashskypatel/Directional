# Milestone G P5-R2E12 Code/Build Report

**Date:** 2026-08-05
**Turn type:** Code + Build
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Disposition

P5-R2E12 normalized authoritative exterior-pair inventory is implemented and compile-valid.

This turn makes the independently proven exterior boundary continuation a first-class normalized `CanonicalFanPairRecord` before generic fan-pair collection or chart-corner interior witness resolution. The record is derived only from authoritative source-boundary loop topology, exact directed boundary witnesses, normalized source-entity evidence, and transition-component roots.

Runtime acceptance is not claimed. P5-TB40 must execute artifact `8951981127` and determine whether the P5-TB39 `ExteriorPairMismatch` failures are removed and whether planar and hard-rail validation reaches the existing wrap, embedding, orbit-root, and topology gates.

R2 remains open. Do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `50d5db4280a5008764f73e5ba0a1827ce63eab1e`;
- exact compiled source: `556efab8c26e012a6019e0b0a10fb847fc8e2ace`;
- workflow run/job: `31060329035` / `92486695630`;
- build artifact: `8951981127`;
- build artifact name: `surface-cell-p5-r2e12-github-source-linux-release`;
- build artifact SHA-256: `7472441fb8b4f82d7e7bc5a62066a8a3db2022851f72c809bb45244bb1b996f0`;
- build artifact size: **12,295,549 bytes**;
- log artifact: `8951981453`;
- log artifact SHA-256: `5a8731736441dae7a9a869f8854178071c0588640e2a3f94139c4c917167b3a6`;
- log artifact size: **8,878 bytes**;
- `SurfaceArrangement.cpp` blob: `3c1855ebaa6a67b1be09956a90906fc269056146`;
- header blob: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- Phase 16 test blob: `e58bceda098f7768b8a7203cca00564f82a7d831`;
- Milestone D test blob: `015a9f02354a91ca07d0e0c6bf6b2632055436ae`;
- patch SHA-256: `9df5bfcb8da63a336f30c3c6a2a37f4e1803db6cb3b8f619cd9b1f99044320b8`;
- recursive manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- compile/link actions: **132/132**;
- packaged source status: empty.

The outer artifact digests match GitHub's recorded digests. Every internal manifest entry verifies when evaluated from the package parent because the manifest intentionally records the `artifact/` prefix. The packaged source archive reproduces all four recorded source/test blobs.

## Implementation

### 1. First-class exterior pair

For every higher-valence source-boundary node, R2E12 constructs the exact exterior directed key:

```text
(exteriorIncoming, exteriorTwin, exteriorOutgoing)
```

The key comes only from the authoritative reversed source-boundary loop traversal and `desiredExteriorNext`. It is inserted into `canonicalPairInventory` before generic fan-pair enumeration.

### 2. Exact boundary identity and side authority

The exterior record requires:

- a valid canonical source-boundary loop identity;
- a valid boundary witness for `exteriorTwin` on side `+1`;
- a valid boundary witness for `exteriorOutgoing` on side `-1`;
- both witnesses owned by the same authoritative source-boundary loop.

Any missing or contradictory identity, loop, or side evidence remains fail-closed as `BoundaryFanSectorCoverConflict` with derived `ExteriorPairMismatch`.

### 3. Normalized entity/root reconciliation

R2E12 collects all source-vertex/source-edge fan evidence for each exterior ray and normalizes every contributing fan identity with the same `canonical_entity_key` contract used by interior pair construction.

Each exterior ray must resolve to exactly one normalized `(entity key, transition root)` authority, and the source and target rays must agree exactly. Agreeing exact fan identities are retained as provenance. The implementation does not select by count, iteration order, frequency, score, or subset search.

### 4. Generic contribution reconciliation

If generic cyclic fan enumeration independently contributes the exact exterior key, it must agree with the preinserted record on:

- the directed triple;
- normalized entity key;
- transition root;
- source-boundary loop identity;
- exact source/target boundary sides.

Disagreement fails transactionally. Agreeing identities are merged only as provenance.

### 5. Explicit exclusion and transactional publication

`CanonicalFanPairRecord` now explicitly carries `exterior` and `sourceBoundaryIdentity`. Chart-corner interior witness resolution skips the explicit exterior record rather than inferring exterior ownership from key ordering.

The exclusion audit requires exactly one explicit exterior record with the exact directed key and source-boundary identity. All remaining pair-witness, incoming/target bijection, predecessor, separator, and hard-rail complete-orbit gates remain unchanged and execute before publication.

## Scope audit

Changed in the exact source commit:

- `src/geometry/SurfaceArrangement.cpp`.

Removed as turn infrastructure in the same source commit:

- `.github/workflows/agent-build-p5-r2e12.yml`.

Unchanged:

- `include/directional/geometry/SurfaceArrangement.h`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`;
- all Phase 17 implementation and tests;
- P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery, fixtures, source-authoritative validators, and unrelated diagnostics.

The exact source commit is one commit after the workflow event commit and contains only the approved production-file modification plus self-removal of the bounded workflow.

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

No test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

## Workflow and repository hygiene

- The workflow checked exact preimage and postimage blobs before committing.
- The exact source commit was pushed before compilation.
- The bounded workflow removed itself in the exact source commit.
- The detailed activity log was initialized before checkout and uploaded separately on success.
- No temporary patch/payload file or generated build artifact remains in the repository.
- Only the durable `.github/workflows/agent-source-snapshot.yml` remains after final documentation cleanup.
- Several bounded documentation-finalization attempts failed on payload-transfer integrity checks; none changed the compiled source or package authority. Final documentation and cleanup were committed through direct GitHub connector writes.

## Next turn

Execute **P5-TB40 artifact-only R2E12 Test + Benchmark** using artifact `8951981127`.

Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, fixtures, validators, workflows, or build logic. The runtime turn must determine whether:

1. planar and hard rail pass the prior `ExteriorPairMismatch` gate;
2. exactly one authoritative exterior pair is recorded and excluded per boundary-fan node;
3. every non-exterior pair receives exactly one reconciled chart witness;
4. planar reaches genuine wrap publication and Euler-one valid disk topology;
5. hard rail reaches distinct side roots, complete bounded-orbit authority, and valid embedding/topology;
6. Phase 17 returns to **26/26** without Phase 17 changes;
7. the accepted R2, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold baselines remain intact.

Any remaining failure must be classified by its first aggregate and derived failure, not only pass counts. R2 remains open until runtime evidence proves closure.
