# Milestone G P5-R2E6 Code/Build Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E6 authoritative boundary fan-sector cover is implemented and compiles successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or produced binary was executed. Runtime acceptance remains open. The next turn is **P5-TB34 artifact-only R2E6 validation** using artifact `8936470245`.

Do not advance to R2F or R3 from compilation alone.

## Source and build authority

- starting documentation head: `2d21e3996d8872b2732892b0f5077643b06e87f2`;
- workflow event commit: `6cd5a5c10aa0f15eb5e1312145425395b8a8372d`;
- exact compiled source: `2444c38b8216656b636f4dad9f8acfa70b86bd41`;
- workflow cleanup commit: `3c4e5bf4a2a40b4f34c39a53e789884383217a5e`;
- reviewed patch SHA-256: `e4196fd4ed1a68d31ba6310af8e8a4822533fac3c1f0248f75721521785f8d3d`;
- applied source diff SHA-256: `e4196fd4ed1a68d31ba6310af8e8a4822533fac3c1f0248f75721521785f8d3d`;
- successful run/job: `31020098349` / `92354282522`;
- job interval: `2026-08-05T15:24:14Z`–`2026-08-05T15:31:55Z`;
- compiled artifact: `8936470245`, `surface-cell-p5-r2e6-github-source-linux-release`;
- artifact SHA-256: `bcc2c0d81e4382368a7fcafe7818c79a2e5bdb23d9a044232a4f3294f4554bf5`;
- workflow-log artifact: `8936470828`, `surface-cell-p5-r2e6-workflow-logs-31020098349`;
- workflow-log SHA-256: `ea700280dc89f4a0e8ed4189aa8db9f760f1cd3210d6f5ce7918e10736ae7e07`;
- source status empty;
- recursive checksums **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

Target hashes:

- `directional_phase1_tests`: `19c0b99b7aa7a1fbe82c378687b72558feb0d79dce21e4edeac6d53f66e50461`;
- `directional_benchmarks`: `4bbab765f3157c68528366517ca8e88f4e4c6e9782754e961c4ec9fae4de2ae0`;
- `libdirectional_core.a`: `287ed77d7ae9a7fe0883b84cc7286a5f0efb2a5c238e4bb5741b4d123af9eb93`;
- `libdirectional_pipeline.a`: `3c58e32d777517df1f06a5b0e2f0e71b554b6a903d5f000bcbaadcc3b16b852e`.

## Implemented R2E6 behavior

1. Preserves the complete R2E5 degree-two construction unchanged:
   - `exteriorIncoming -> exteriorOutgoing`;
   - `twin(exteriorOutgoing) -> exteriorTwin`.
2. Preserves the R1-selected intrinsic successor relation before source-boundary exterior authority is installed.
3. Removes the `rayCount >= 3` requirement that one common canonical wedge contain every local ray.
4. Builds the higher-valence local relation from one authoritative exterior sector plus the complete set of R1-selected source-interior sectors.
5. Accepts an interior sector only when its selected `SourceVertex` or `SourceEdge` fan identity contains the source ray and target as direct, non-wrapping adjacent rays.
6. Requires every local incoming halfedge exactly once and every local outgoing target exactly once before publishing any local successor.
7. Verifies authoritative source hard-rail rays are bounded by two distinct interior fan identities; hard rails therefore separate fan sectors and are never crossed.
8. Adds typed `BoundaryFanSectorCoverConflict` rejection for incomplete, duplicate, contradictory, discontinuous, or hard-rail-crossing cover evidence.
9. Adds derived diagnostics only after a complete local cover succeeds:
   - `boundaryFanSectorNodeCount`;
   - `boundaryInteriorSectorCount`;
   - `boundaryHardRailSeparatorCount`.
10. Leaves ordered exterior-loop closure, global predecessor multiplicity, repeated-edge/node analysis, disk classification, ownership, Euler, orientation hash, and area validation unchanged.
11. Corrects the higher-valence test input: three spokes now terminate at distinct points on the opposite source-boundary edge, genuinely partitioning the source disk into four bounded disks instead of creating dangling interior slits.
12. Strengthens the interior-hard-rail contract with successful fan-cover and separator diagnostics.

This is a producer-level sector cover. It is not an arbitrary target permutation, subset search, validator exception, post-hoc cycle decomposition, or cell merge.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

The coherent source/test patch contains **338 insertions and 149 deletions**. No FlowRep, tracing semantics, simplification, completion, fallback/recovery, optimizer, cache, lineage, memory accounting, or bunny intrinsic-fan subsystem was changed.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Configure and compilation completed successfully with Ninja on Ubuntu 24.04 and GCC 13.3.

## Artifact source authority

The artifact contains:

- `source/exact-source.tar.gz`: exact compiled source with the bounded workflow and base workflow;
- `source/source.tar.gz`: validation source excluding only `.github/workflows/agent-build-p5-r2e6.yml`, containing only `agent-source-snapshot.yml` and zero payloads.

`source-exclusions.txt` records the single exclusion. The implementation commit removed both patch transport files, and the bounded workflow was removed immediately after artifact upload.

The recursive checksum manifest excludes itself and verifies all **48/48** entries after download.

## Next turn

Run **P5-TB34 artifact-only R2E6 validation** against artifact `8936470245`. Follow `.agents/Directional/Milestone_G_P5_R2E6_Test_Benchmark_Plan.md`.

First preserve every P5-TB33 passing authority, including degree-two, Phase 17 **26/26**, and Phase 18 **57/57**. Then determine whether the corrected genuine higher-valence partition and interior hard rail close naturally. Do not advance to R2F or R3 until runtime evidence closes the required gates.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
