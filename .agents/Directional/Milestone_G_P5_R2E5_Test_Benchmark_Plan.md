# Milestone G P5-R2E5 Test/Benchmark Plan

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Artifact-only Test + Benchmark

## Purpose

Validate that the explicit degree-two exterior/interior sector construction restores all P5-TB32 regressions while preserving the canonical higher-valence rotational system and every prior R0/R1/R2 authority boundary.

Use artifact `8934315316` directly. Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, benchmarks, fixtures, or build logic.

## Package authority gate

Before executing any packaged binary, require:

- artifact `8934315316`, `surface-cell-p5-r2e5-github-source-linux-release`;
- archive SHA-256 `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`;
- exact compiled source `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`;
- workflow event commit `15704d30fc478858284df89d372fa713f2d88576`;
- reviewed and applied source diff SHA-256 `b7648b0bf870d7a65a7715a11e58cc2e8258af0118826c843d013384d485cc29`;
- empty source status;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes match the Code + Build report;
- cleaned validation source contains only `agent-source-snapshot.yml` and zero temporary payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e5.yml`.

Reject the artifact if any authority check fails.

## Execution boundary

Run only the packaged binaries and packaged fixtures. Preserve raw stdout/stderr, GoogleTest XML, benchmark JSON, commands, wall time, process exit status, and memory evidence.

Do not configure or compile. Do not modify source or validation inputs. Do not use fallback, source-grid recovery, legacy output, fixture substitution, validator weakening, or earlier failure as evidence of progress.

## First gate: restore P5-TB32 regressions

The degree-two fix is not accepted unless it restores every regression introduced by R2E4. Require at minimum:

- source-chart R1 **11/11**;
- source validator **6/6**;
- recovery authority **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**, with only bunny allowed;
- R2 focused at least **13/16**, with only the pre-existing planar, hard-rail, and bunny producers allowed;
- Milestone D at least **5/7**;
- Phase 14–18 at least the P5-TB31 passing set plus both new rotational contracts;
- Phase 16 at least **45/47**;
- Phase 17 at least **20/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite at least **597/625**, with no failure absent from the P5-TB31 failure set.

If any P5-TB32 regression remains, stop advancement and identify the earliest degree-two producer.

## Degree-two contracts

Require:

1. every valid two-ray boundary node has exactly two incoming and two outgoing halfedges;
2. `exteriorIncoming -> exteriorOutgoing` follows exact ordered source-loop continuation;
3. `twin(exteriorOutgoing) -> exteriorTwin` owns the complementary source-interior sector;
4. the two incoming halfedges are distinct;
5. each outgoing target is used exactly once;
6. endpoint continuity holds for both assignments;
7. the exterior successor carries authoritative loop identity while the interior successor carries canonical source-entity rotation identity;
8. `boundaryDegreeTwoRotationalNodeCount` is derived from successful audited nodes;
9. boundary-only triangle/curved-disk topology publishes one exterior disk and one bounded disk;
10. malformed two-ray inventory or twin evidence fails closed as `BoundaryRotationalSystemConflict` with no partial publication.

## Higher-valence preservation

Require the existing multiple-interior-rays contract to pass through the `rayCount >= 3` canonical adjacency branch. Source-row permutation and whole-orientation reversal must preserve directed incidence hashes. Do not accept a result that routes higher-valence nodes through degree-two logic.

## Structural topology

After regression restoration, evaluate:

- planar disk: complete permutation, one exterior cell, full bounded area, Euler one, valid topology;
- interior hard rail: one exterior cell, intended bounded partition, complete ownership, valid topology;
- open cylinder: two exterior cells, nonzero bounded disks, Euler zero, no `cell == -1`;
- nested annular bounded cell retains Euler zero and `NonDisk` classification;
- bridge, support-only, disconnected, pinched-fan, and close-sheet cases preserve their exact authority and component separation.

Any genuine remaining producer must be classified separately from the repaired degree-two degeneracy.

## Direct analytic cases

Execute packaged direct cases with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

- plane;
- multi-face seam;
- close sheets;
- disconnected close sheets when available;
- cylinder.

For each case record success/failure, earliest failure, arrangement/simplified/completed inventories, quad count, topology/embedding/area diagnostics, fallback/recovery/legacy flags, wall time, and peak memory.

At minimum, plane must preserve its P5-TB32 9 arrangement cells, 9 simplified cells, and 12 candidate quads. Seam, close sheets, and cylinder must not regress relative to P5-TB31. Nonzero valid inventories remain required for R2 closure.

## Complete suite and performance

Run the complete GoogleTest suite exactly once after focused scopes. Record discovered/passed/failed counts, exact failure list versus P5-TB31 and P5-TB32, normal termination, wall time, exact maximum RSS when available, otherwise sampled RSS with the limitation stated, and dominant long-running cases.

Do not characterize a shorter runtime as improvement when invalid incidence causes earlier termination.

## Decision rules

- If any of the 21 P5-TB32 regressions remains, prepare the smallest coherent P5-R2E5 remediation turn.
- If all regressions close but planar/hard-rail/cylinder remain, identify the earliest post-degree-two producer and prepare one bounded next Code + Build plan.
- Advance to R2F only when all boundary rotational, exterior, repeated-edge/node, disk, owner, Euler, planar, hard-rail, and cylinder gates close and bunny is the sole remaining R2 producer.
- Advance to R3 only after every R2 incidence, ownership, topology, and embedding gate closes.

## Required outputs

Produce and commit:

- `.agents/Directional/Milestone_G_P5_TB33_Artifact_Only_R2E5_Test_Benchmark_Report.md`;
- `benchmark-results/p5-tb33-summary.json`;
- bounded raw evidence sufficient to reproduce every command and result;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- one authoritative next Code + Build plan when R2 remains open.

After all documentation commits, post the required final handoff comment on PR #8. It must be the final repository write of the turn.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
