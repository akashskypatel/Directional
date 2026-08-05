# Milestone G P5-R2E7 Cyclic Fan-Sector Cover and Hard-Rail Side Closure Code/Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Starting documentation head:** `5075bc2129987169186d59464253d5d7fffa7ead`

## Objective

Preserve the passing degree-two and genuine higher-valence partition contracts while replacing R2E6's linear/non-wrapping sector criterion with a cyclic authoritative sector cover. Prove hard-rail side assignment from ordered source-fan adjacency, not merely from unequal fan identities.

This is the smallest coherent producer correction because the planar regression, six Phase 17 regressions, and hard-rail topology failure all arise from incomplete cyclic sector semantics at boundary nodes.

## Scope

Modify only the surface-arrangement producer and directly relevant topology tests:

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp` when necessary.

Do not modify FlowRep, Phase 17 simplification, completion, fallback/recovery, optimizer, cache, lineage, memory accounting, or bunny singularity-fan embedding.

## Required implementation

### 1. Preserve accepted branches

- Keep the exact R2E5 degree-two mapping unchanged.
- Preserve the passing R2E6 genuine four-disk higher-valence fixture and diagnostics.
- Preserve ordered source-boundary exterior continuation and paired orientation-invariant boundary identity.

### 2. Construct cyclic fan adjacencies

For each authoritative R1 fan identity at a boundary node:

1. Read its ordered outgoing ray cycle.
2. Enumerate every adjacent pair modulo the ray count, including the vector wrap.
3. Convert each adjacent pair into the corresponding incoming-to-outgoing sector relation.
4. Retain only pairs whose two rays are present in the local node inventory and whose witnesses belong to that exact R1 fan scope.
5. Deduplicate by canonical `(incoming, target, fanIdentity)` identity.

Do not infer interior/exterior status from whether an adjacency wraps the stored vector.

### 3. Exclude exactly one proven exterior sector

- Identify the authoritative exterior pair only from ordered source-boundary loop evidence.
- Remove that exact pair from the cyclic fan-sector candidates.
- All other valid adjacent pairs are source-interior sectors, including a cyclic-wrap pair when it is not the exterior pair.
- Require exactly one exterior sector for each manifold boundary fan.

### 4. Prove hard-rail side assignment

For every authoritative source hard-rail ray at a boundary node:

- identify the two cyclicly adjacent source-interior sectors incident to the rail;
- require distinct R1 fan identities on the two sides;
- require each identity to contain the rail ray and its adjacent non-rail ray in the correct directed order;
- require the two directed twins of the rail to enter the two different bounded orbits;
- reject any sector that crosses from one fan identity to the other without using the rail as their common separator.

A mere inequality of fan IDs is insufficient.

### 5. Transactional complete-cover audit

Before publishing any successor:

- every incoming halfedge appears exactly once;
- every outgoing target appears exactly once;
- every sector has endpoint continuity and reciprocal twin validity;
- the exterior pair appears exactly once;
- each hard rail has exactly two correctly oriented incident interior sectors;
- no duplicate, missing, contradictory, or cross-fan sector exists.

Publish the complete local cover only after all audits pass. Use a typed failure such as `BoundaryFanSectorCoverConflict`; add a narrower typed reason only if it materially improves diagnosis without weakening fail-closed behavior.

### 6. Diagnostics

Keep existing R2E6 diagnostics and add only derived counters that are useful for validating:

- accepted cyclic-wrap interior sectors;
- hard-rail side-pair audits;
- rejected exterior-pair duplicates.

Counters must be derived from successfully audited producer state, never synthesized.

## Required tests

1. **Degree-two preservation:** existing boundary-only triangle remains fully passing.
2. **Single-spoke cyclic-wrap boundary node:** add or strengthen a minimal unit-triangle fixture proving the legitimate interior wrap sector is accepted while the independently identified exterior pair is excluded.
3. **Planar fixture:** restore incidence validity and the P5-TB33 topology/Euler diagnostic position without synthetic Euler correction. Prefer full topology closure if the cyclic cover naturally supplies the missing bounded orbit.
4. **Genuine higher-valence partition:** retain one exterior and four bounded disks.
5. **Interior hard rail:** require one exterior and two bounded disks, complete ownership, disk validity, Euler/area validity, and correctly oriented distinct rail-side fan identities.
6. **Malformed cyclic cover:** missing, duplicate, exterior-duplicate, invalid-twin, and cross-fan rail cases fail transactionally with no partial publication.
7. **Regression authority:** source-row/orientation hashes, pinched fans, close sheets, bridge/core ownership, nested annular classification, nonmanifold preflight, and global predecessor audits remain unchanged.
8. **Phase 17 source fixtures:** do not edit Phase 17 tests; their six contracts must become valid naturally through corrected arrangement inputs.

Do not weaken an assertion or replace a fixture unless the existing fixture is proven not to represent its stated topology.

## Code + Build boundary

- Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Execute no project test, benchmark, custom mesh, help/list, or discovery command.
- Use the established bounded GitHub Actions transport with exact patch hash and expected blobs.
- Remove patch payloads in the exact source commit.
- Remove the bounded workflow immediately after artifact upload.
- Package exact and cleaned source authority, target hashes, fixtures, submodules, logs, and recursive manifest.

## Acceptance for handoff to P5-TB35

Compilation must succeed with no source drift. Runtime claims remain prohibited until artifact-only validation.

The P5-TB35 plan must require:

- restoration of Phase 17 **26/26**;
- R2 focused at least **14/16**, with only cylinder and bunny or a separately diagnosed planar Euler failure allowed;
- Milestone D at least **6/7**, cylinder only;
- Phase 16 at least **46/47** if planar closes, otherwise **45/47** with explicit planar diagnosis;
- preserved Phase 18 **57/57**;
- no failure absent from the P5-TB33 set after accounting for the closed higher-valence contract;
- complete suite exactly once.

## Prohibitions

No validator weakening, arbitrary target permutation, subset search, post-hoc cycle decomposition, cell merging, synthetic Euler correction, positional sheet merging, fallback/recovery substitution, fixture/ID special cases, or timeout-as-correctness.
