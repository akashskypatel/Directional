# Milestone G P5-R2E7 Code/Build Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E7 cyclic fan-sector cover and directed hard-rail side closure is implemented and compiles successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or produced binary was executed. Runtime acceptance remains open. The next turn is **P5-TB35 artifact-only R2E7 validation** using artifact `8938299309`.

Do not advance to R2F or R3 from compilation alone.

## Source and build authority

- starting documentation head: `7c46b888ff9336a9a83d26097c41b50c3e770a8f`;
- workflow event commit: `7d5450cb6411722818844548de59a09c8f4451d5`;
- exact compiled source: `31c8d9a212f649df7c70fe9291d1fac8c4db7132`;
- workflow cleanup commit: `a95d2531f87833373bfde92b5d697185f9c71687`;
- reviewed patch SHA-256: `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`;
- applied source diff SHA-256: `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`;
- successful run/job: `31024637616` / `92369812070`;
- job interval: `2026-08-05T16:18:28Z`–`2026-08-05T16:26:03Z`;
- compiled artifact: `8938299309`, `surface-cell-p5-r2e7-github-source-linux-release`;
- artifact SHA-256: `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`;
- workflow-log artifact: `8938299624`, `surface-cell-p5-r2e7-workflow-logs-31024637616`;
- workflow-log SHA-256: `a4c1dee2951ab2f374b86fca6767ebf17835797fdf4a9a8ac26d9771fc54331c`;
- source status empty;
- recursive checksums **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed;
- compile step exit code **0**.

Target hashes:

- `directional_phase1_tests`: `60af489513b62a2519a80e04af5bd1922b1e8b0f58eaaf979f58f825d34b8f79`;
- `directional_benchmarks`: `924eed7c6924a22d8f7a7822c5ebd11a4e58a5775fba76fa0639275d13afc0ab`;
- `libdirectional_core.a`: `e221001007176dc59c78db625d530667a4ffc7085c0579ae76e162fb5eb8ab49`;
- `libdirectional_pipeline.a`: `87c615f3bbfe115b499a88fc8f6e1c283143168f521dc8de1f495de2f234d118`.

## Implemented R2E7 behavior

1. Preserves the exact passing R2E5 degree-two exterior/interior mapping.
2. Preserves the passing R2E6 genuine four-disk higher-valence partition and its producer diagnostics.
3. Treats every authoritative R1 fan ray sequence as cyclic instead of linear.
4. Accepts the modulo predecessor sector, including a vector-wrap sector, when its source and target belong to the same authoritative R1 fan.
5. Excludes only the exact exterior adjacency independently proven by ordered source-boundary loop continuation; a vector wrap is not classified as exterior merely because it wraps storage order.
6. Carries a derived `cyclicWrap` property on successfully audited fan-sector records and increments `boundaryCyclicWrapInteriorSectorCount` only after complete local cover validation.
7. Strengthens hard-rail authority by deriving the two directed side sectors from separator witness orientation and cyclic fan adjacency.
8. Requires each directed hard-rail side to use the rail ray and the correct adjacent non-rail ray in the expected order, with distinct source-fan identities on opposite sides.
9. Replaces the local hard-rail sector records transactionally and then re-audits source ownership, target cardinality, fan identity, and directed side signs.
10. Increments `boundaryHardRailSidePairCount` only after both directed sides pass the complete local audit.
11. Keeps typed `BoundaryFanSectorCoverConflict` for missing, duplicate, discontinuous, exterior-duplicate, invalid-twin, cross-fan, or incorrectly oriented rail-side evidence.
12. Leaves global predecessor, repeated-edge/node, disk, ownership, Euler, boundary-loop, orientation-hash, and area validators unchanged.
13. Strengthens the planar contract to require a naturally accepted cyclic-wrap interior sector.
14. Strengthens the interior-hard-rail contract to require directed side-pair evidence and two distinct bounded-cell owners for the rail twins.
15. Does not modify Phase 17; its six P5-TB34 regressions must restore naturally from valid arrangement inputs.

This is producer-level cyclic sector and rail-side assembly. It is not arbitrary target permutation, subset search, validator exception, post-hoc cycle decomposition, synthetic Euler correction, or cell merging.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

The coherent source/test patch contains **233 insertions and 29 deletions**. No FlowRep, Phase 17 simplification, completion, fallback/recovery, optimizer, cache, lineage, memory accounting, or bunny intrinsic-fan subsystem was changed.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Configure and compilation completed successfully with Ninja on Ubuntu 24.04 and GCC 13.3.0.

## Artifact source authority

The artifact contains:

- `source/exact-source.tar.gz`: exact compiled source with the bounded workflow and base workflow;
- `source/source.tar.gz`: validation source excluding only `.github/workflows/agent-build-p5-r2e7.yml`, containing only `agent-source-snapshot.yml` and zero payloads.

`source-exclusions.txt` records the single exclusion. The implementation commit removed both patch transport files, and the bounded workflow was removed immediately after artifact upload.

The recursive checksum manifest excludes itself and verifies all **48/48** entries after download. The package contains **49** physical files including the manifest.

## Next turn

Run **P5-TB35 artifact-only R2E7 validation** against artifact `8938299309`. Follow `.agents/Directional/Milestone_G_P5_R2E7_Test_Benchmark_Plan.md`.

First preserve every P5-TB34 passing authority, including degree-two, genuine four-disk higher valence, source-row/orientation identity, and Phase 18 **57/57**. Then require the planar cyclic-wrap regression and all six Phase 17 regressions to restore naturally. Require directed hard-rail side ownership to close the remaining Milestone D topology gate or produce a narrower independent diagnosis.

Do not advance to R2F or R3 until runtime evidence closes the required gates.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
