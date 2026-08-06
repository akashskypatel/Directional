# Milestone G P5-R2E13 Code + Build Report

**Date:** 2026-08-05
**Turn type:** Code + Build
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Disposition

P5-R2E13 authoritative boundary-witness projected exterior-ray evidence is implemented and compile-valid.

The independently proven boundary witness now defines the exterior ray's chart, normalized source entity, transition root, source-boundary loop, and directed side before fan provenance is reconciled. Fan memberships agree with that authority only when their exact directed witness occupies the projected chart and resolves to the same normalized entity/root. Unrelated fan memberships remain available for independent interior-pair ownership. Contradictory claims to the same projected boundary chart fail closed.

The two unchanged target acceptance assertions now append deterministic diagnostic context on failure. Their pass criteria and all production validators remain unchanged.

Runtime acceptance is not claimed. P5-TB41 must execute artifact `8953600942` and determine whether the planar and interior-hard-rail boundary-fan failures close or advance to a new observable first producer.

R2 remains open. Do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `45a4c1031cccd3e814b2cf8e24209662dbfdae87`;
- exact compiled source: `39b60e66d72f412c1d648ffef213beca93bd19dc`;
- workflow run/job: `31064914809` / `92500525659`;
- build artifact: `8953600942`;
- build artifact name: `surface-cell-p5-r2e13-github-source-linux-release`;
- build artifact SHA-256: `9144cde751377199a8df135ac0871e75e65c44b5d8efce07ea42a0732ae6f7d1`;
- build artifact size: **12,295,987 bytes**;
- log artifact: `8953601264`;
- log artifact SHA-256: `6fd241cb97616e7a349e427f1130373d5b7e1e212eb63f56b3eea0e196e836ba`;
- log artifact size: **5,806 bytes**;
- `SurfaceArrangement.cpp` blob: `afeb0f1931ee80fdb0d617be9e5bece02fa179b6`;
- public header blob: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- Phase 16 test blob: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- Milestone D test blob: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`;
- patch SHA-256: `b2a068ba41b0a170d227c2320921ccc3cf6a94883803fba6b06b3a7e87947094`;
- recursive manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- compile/link actions: **132/132**;
- packaged source status: empty.

The downloaded archive and log digests match GitHub's recorded digests. Every internal manifest entry verifies from the package parent using the recorded `artifact/` prefix. The source archive reproduces the four recorded production/header/test blobs.

## Implementation

### 1. Boundary-witness chart authority

`BoundarySubsegmentWitness` now retains the resolved source component and source sheet in addition to source face, source edge, loop, side, and exact interval parameters.

When a witness is constructed, its stored component/sheet must agree with any existing source provenance. A disagreement remains fail-closed as `ContradictoryBoundarySide`; it is not repaired, selected, or merged.

The canonical witness key includes component and sheet so distinct source charts cannot collapse into one boundary witness merely because face/edge parameters agree.

### 2. Exterior ray projection

For each exact exterior source and target boundary witness, R2E13 projects:

- exact `SurfaceCellSourceChart`;
- normalized canonical source-entity key;
- transition-component root;
- source-boundary loop identity;
- directed side.

The source and target projections must both be valid, belong to the authoritative exterior loop, carry sides `+1` and `-1`, and agree exactly on normalized entity and transition root.

### 3. Provenance reconciliation without heuristic selection

Fan provenance is reconciled after projection. A fan identity contributes exterior provenance only when the exact ray's `DirectedWedgeWitness` chart equals the projected boundary chart and its normalized entity/root agrees with the projection.

- agreeing identities are retained and canonicalized as provenance;
- memberships on unrelated charts are preserved for interior-pair processing and do not veto the exterior authority;
- a claim on the projected chart with a different entity or root is a deterministic contradiction and fails closed;
- no count, order, frequency, score, subset search, or fallback selects ownership.

The explicit exterior `CanonicalFanPairRecord` is populated from the projected authority rather than raw whole-fan evidence-map cardinality.

### 4. Existing publication gates preserved

R2E13 does not weaken or bypass:

- exact generic contribution reconciliation;
- explicit exterior exclusion exactly once;
- canonical pair completeness;
- one-to-one incoming/target cover;
- predecessor multiplicity;
- hard-rail separator side-pair checks;
- complete bounded-orbit transition-root audit;
- embedding, disk, Euler, orientation, area, ownership, or aggregate topology validation.

### 5. Non-weakening target diagnostics

Only diagnostic text was added to the existing `ASSERT_TRUE(incidenceValid)` assertions for:

- `SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture`;
- `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`.

On failure they now report the derived boundary-fan conflict name/value, node/incoming/source-ray/target tuple, canonical-pair count, exterior-exclusion count, fan-sector-node count, cyclic-wrap count, and hard-rail separator/side-pair counts. Assertions, fixtures, expected values, and test semantics are unchanged.

## Scope audit

Production change:

- `src/geometry/SurfaceArrangement.cpp`.

Focused non-weakening diagnostic changes:

- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

Unchanged:

- `include/directional/geometry/SurfaceArrangement.h`;
- all Phase 17 implementation and tests;
- P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery, fixtures, source-authoritative validators, thresholds, and unrelated diagnostics.

The exact source commit also removes the eight temporary patch-transfer chunks. The bounded workflow was removed after artifact verification.

## Compile gate

Configuration:

- Ubuntu 24.04;
- GNU C++ 13.3.0;
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

- The first bounded run `31064513226` stopped before patch application because a staged transfer chunk failed the declared base64 digest. It produced no source or compile authority.
- The transfer bytes were corrected without changing the intended patch or postimage blobs.
- The authoritative retry verified base64 and decoded patch digests, exact preimages/postimages, permitted paths, and a clean tree.
- The exact source commit was pushed before configuration or compilation.
- The successful run uploaded the build package and detailed logs separately.
- Temporary patch chunks were removed in the exact source commit.
- The bounded workflow was removed after local archive verification.
- Only the durable source-snapshot workflow remains at turn completion.

## Next turn

Execute **P5-TB41 artifact-only R2E13 Test + Benchmark** using artifact `8953600942`.

Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, fixtures, validators, workflows, or build logic. The runtime turn must determine whether:

1. the target diagnostics now expose the exact earliest derived producer whenever incidence remains invalid;
2. planar and hard rail pass boundary-witness projection and provenance reconciliation;
3. exactly one explicit exterior pair is inserted and excluded per boundary-fan node;
4. all non-exterior pairs receive exactly one authoritative chart witness;
5. planar reaches genuine wrap publication and Euler-one valid disk topology;
6. hard rail reaches distinct complete-orbit roots and valid embedding/topology;
7. Phase 17 returns to **26/26** without Phase 17 changes;
8. accepted R2, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold baselines remain intact;
9. the P27/bunny cumulative-state stall is assessed separately from correctness.

Any remaining rejection must be classified by its first aggregate and newly observable derived diagnostic. Compile evidence alone does not close R2.
