# Milestone G P5-R2E5 Degree-Two Boundary Rotation Code/Build Plan

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code + Build, compile-only

## Objective

Correct the R2E4 fail-closed regression at canonical source-boundary nodes with exactly two outgoing rays while preserving the authoritative cyclic rotational construction for higher-valence nodes.

The implementation must represent the two distinct sectors induced by the same unordered ray pair:

- one authoritative exterior sector;
- one complementary source-interior sector.

Do not infer sector identity from uniqueness of predecessor-versus-successor ray ID when the cyclic order contains only two rays.

## Authority

Start from the P5-TB32 documentation head and read:

1. `.agents/Directional/Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`;
2. `benchmark-results/p5-tb32-summary.json`;
3. `.agents/Directional/Milestone_G_P5_R2E4_Code_Build_Report.md`;
4. `.agents/Directional/Milestone_G_P5_R2E4_Test_Benchmark_Plan.md`;
5. `TODO`;
6. `MILESTONE_G_TODO.md`;
7. `.agents/Directional/Future_Chat_Session_Handoff.md`.

## Confirmed producer

In R2E4, `rayCount == 2` makes both cyclic neighbor positions resolve to the same opposite outgoing ray. The current direction-selection code treats the two equivalent matches as contradictory and emits `BoundaryRotationalSystemConflict` before any successor is published.

This is not evidence that the ray inventory is ambiguous. The ray inventory is complete; only the sector-orientation representation is degenerate when expressed solely through neighboring ray IDs.

## Required implementation

### 1. Explicit two-ray branch

When an authoritative boundary node has exactly two outgoing rays:

1. identify `exteriorIncoming` and authoritative `exteriorOutgoing` from ordered source-boundary continuation;
2. identify `exteriorTwin`, the outgoing twin of `exteriorIncoming`;
3. require the local outgoing inventory to be exactly `{exteriorTwin, exteriorOutgoing}`;
4. assign:
   - `candidateNext[exteriorIncoming] = exteriorOutgoing` for the exterior sector;
   - `candidateNext[twin(exteriorOutgoing)] = exteriorTwin` for the complementary interior sector;
5. require endpoint continuity and distinct incoming ownership;
6. require each outgoing target exactly once;
7. assign the authoritative loop identity only to the exterior successor and the canonical source-entity rotation identity to the interior successor.

This is the complete two-sector rotational permutation, not a repair after generic assignment.

### 2. Higher-valence branch

For `rayCount >= 3`:

- retain direct canonical adjacent-ray reconstruction;
- require the authoritative exterior pair to be adjacent in exactly one cyclic direction;
- map every incoming twin to the next outgoing ray in that direction;
- retain exact local target cardinality, endpoint, exterior-cycle, and global predecessor audits.

Do not use the degree-two special handling for three or more rays.

### 3. Typed evidence

Retain `BoundaryRotationalSystemConflict` for actual incomplete, contradictory, non-adjacent, or non-bijective rotational evidence.

Add derived diagnostics only when needed to distinguish:

- invalid two-ray inventory;
- invalid complementary twin;
- invalid two-sector target cardinality.

Do not convert a genuine conflict into success merely because the node has two rays.

### 4. Preserve authority boundaries

Do not change:

- canonical boundary alias classes;
- source-face-row and whole-orientation identity hashing;
- ordered source-boundary loops;
- boundary coverage and side audits;
- repeated-edge and repeated-node validators;
- disk/non-disk classification;
- ownership cardinality;
- structural Euler accounting;
- FlowRep, tracing, simplification, completion, fallback, recovery, optimizer, cache, lineage, or memory subsystems.

## Required tests to compile

Strengthen or add generalized contracts that validate:

1. a boundary-only triangle or curved disk with degree-two boundary nodes publishes one exterior and one bounded disk;
2. the two-ray exterior successor follows exact source-loop order;
3. the complementary incoming maps to the complementary outgoing;
4. every local incoming and outgoing is used exactly once;
5. source-face row permutation preserves the two-sector map;
6. whole-mesh orientation reversal preserves directed incidence hash;
7. the existing multiple-interior-rays contract remains a separate `rayCount >= 3` path;
8. planar, interior-hard-rail, cylinder, bridge, support-only, disconnected, close-sheet, and ownership contracts are not weakened;
9. malformed two-ray evidence fails closed with `BoundaryRotationalSystemConflict`.

Do not make tests pass synthetically. Inputs must create the topology named by the test.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not execute tests, benchmarks, custom meshes, project binaries, help/list/discovery commands, or produced binaries.

## Artifact requirements

Produce one bounded Linux release artifact containing:

- the four compiled targets;
- all packaged fixtures;
- exact and cleaned source archives;
- source/event/diff authority files;
- empty source status;
- recursive submodule status;
- build/configure logs;
- target hashes;
- a self-excluding recursive checksum manifest.

Require:

- manifest **48/48**;
- files **49** including the manifest;
- fixtures **26**;
- recursive submodules **9**;
- cleaned source with only `agent-source-snapshot.yml` and zero payloads.

Remove the bounded workflow and all patch payloads immediately after artifact upload.

## Acceptance for the Code + Build turn

The turn closes only when:

- the coherent source/test patch is committed and pushed;
- all four approved targets compile;
- no project binary was executed;
- artifact authority passes;
- the branch retains only the base workflow and no payloads;
- the Code + Build report, artifact-only Test + Benchmark plan, machine summary, TODOs, and live handoff are committed;
- a new final PR #8 handoff comment is posted as the final repository write.

Runtime correctness remains open until the following artifact-only turn.

## Next validation

The next turn must be **P5-TB33 artifact-only R2E5 validation**. It must first verify restoration of the 21 P5-TB32 regressions, then evaluate planar, hard-rail, cylinder, high-valence rotational, ownership, orientation-hash, Phase 18, direct analytic cases, and the complete suite once.

Do not advance to R2F until every boundary rotational, exterior, repeated-edge/node, disk, owner, Euler, planar, hard-rail, and cylinder gate closes and bunny is the sole remaining R2 producer.
