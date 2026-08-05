# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E6 authoritative boundary fan-sector cover is implemented and compiles successfully.

- exact compiled source: `2444c38b8216656b636f4dad9f8acfa70b86bd41`;
- artifact: `8936470245`;
- workflow run/job: `31020098349` / `92354282522`;
- post-build workflow cleanup: `3c4e5bf4a2a40b4f34c39a53e789884383217a5e`.

Runtime acceptance has not been executed for this source. The next turn is **P5-TB34 artifact-only R2E6 validation**. Do not configure, rebuild, relink, patch, regenerate, or modify source. Do not advance to R2F or R3 from compilation.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R2E6_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E6_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r2e6-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB33_Artifact_Only_R2E5_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E6_Boundary_Fan_Sector_Cover_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E6 package authority

- starting documentation head: `2d21e3996d8872b2732892b0f5077643b06e87f2`;
- workflow event commit: `6cd5a5c10aa0f15eb5e1312145425395b8a8372d`;
- exact compiled source: `2444c38b8216656b636f4dad9f8acfa70b86bd41`;
- reviewed/applied source diff SHA-256: `e4196fd4ed1a68d31ba6310af8e8a4822533fac3c1f0248f75721521785f8d3d`;
- artifact: `8936470245`, `surface-cell-p5-r2e6-github-source-linux-release`;
- artifact SHA-256: `bcc2c0d81e4382368a7fcafe7818c79a2e5bdb23d9a044232a4f3294f4554bf5`;
- workflow-log artifact: `8936470828`, SHA-256 `ea700280dc89f4a0e8ed4189aa8db9f760f1cd3210d6f5ce7918e10736ae7e07`;
- source status empty;
- recursive checksums **48/48**;
- package files **49**;
- fixtures **26**;
- recursive submodules **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed;
- no project binary executed.

The cleaned validation source contains only `agent-source-snapshot.yml` and zero payloads. The exact-source archive retains the bounded compile workflow; `source-exclusions.txt` records its sole removal. The final branch contains only the base workflow and no patch payloads.

Evidence bundle: `directional-p5-r2e6-8936470245-evidence.zip`, SHA-256 `c2487786ca7984896cb0d202aac1e3093700b37f01e129713731ca6475938bbc`.

## P5-R2E6 implementation

1. Preserves the exact R2E5 degree-two exterior/interior sector construction.
2. Preserves R1-selected intrinsic successors and canonical fan identities before exterior-loop authority is installed.
3. Removes the higher-valence requirement that one common wedge contain the full ray inventory.
4. Builds each `rayCount >= 3` node from one ordered exterior sector plus the complete set of R1-selected source-interior sectors.
5. Accepts interior sectors only when source and target are direct, non-wrapping adjacent rays in the same SourceVertex or SourceEdge fan identity.
6. Requires every local incoming and outgoing ray exactly once before publishing any successor.
7. Requires each authoritative hard-rail ray to have distinct interior fan identities on its two sides; rails separate sectors and never become crossings.
8. Adds typed `BoundaryFanSectorCoverConflict` and derived fan-sector/interior-sector/hard-rail-separator diagnostics.
9. Leaves global predecessor, repeated-edge/node, disk, ownership, Euler, orientation, and area validators unchanged.
10. Replaces the invalid dangling-spoke higher-valence test with three non-crossing boundary-to-boundary spokes that genuinely partition a disk into four bounded disks.

This is direct producer-level fan-sector assembly, not target swapping, arbitrary subset search, post-hoc cycle decomposition, or cell merging.

## P5-TB34 execution order

1. Verify artifact SHA, source commit, source status, **48/48** checksums, 49 files, 26 fixtures, nine submodules, target hashes, one cleaned base workflow, and zero payloads.
2. Preserve source-chart **11/11**, validator **6/6**, recovery **9/9**, feature/barrier **8/8**, and graph-dependent **5/6** with bunny only.
3. Run all R2 through R2E6 contracts and preserve the exact degree-two branch.
4. Require the corrected higher-valence fixture to publish one exterior and four bounded disks with complete ownership and valid topology.
5. Require the interior hard rail to publish one exterior and two bounded disks with at least two audited hard-rail separators.
6. Preserve source-face-row and whole-orientation incidence-hash invariance.
7. Require R2 focused at least **14/16**, Milestone D at least **6/7**, Phase 16 at least **45/47**, Phase 17 **26/26**, Phase 18 **57/57**, and complete suite at least **604/625**.
8. Run direct plane, seam, close sheets, disconnected close sheets when packaged, and cylinder with fallback `Fail`, recovery disabled, and no legacy execution.
9. Run Phase 20 and the complete suite exactly once with raw runtime and RSS evidence.
10. If fan-sector and hard-rail gates close, diagnose planar Euler and cylinder independently and prepare the smallest coherent next Code + Build plan.
11. Do not advance to R2F until planar, hard rail, cylinder, and all boundary/orbit/disk/owner/Euler gates close and bunny is the sole remaining R2 producer.

## End-of-turn PR comment requirement

At the end of every Code + Build, Test + Benchmark, and optional Review turn, post a **new final comment on PR #8** after all documentation commits. It must identify exact source/evidence, result, remaining gates, next-turn plan, and final documentation head. It must be the final repository write.

## Known procedural lessons

- A complete local bijection is not proof of a valid fan-sector cover.
- Higher-valence test inputs must create actual bounded partitions; dangling interior slits are not valid evidence for multiple disk cells.
- Hard rails divide authoritative R1 fan scopes and must be represented as shared sector boundaries, not crossed by a single common wedge.
- Preserve intrinsic sector evidence before installing exterior-loop successors.
- Git source archives do not include initialized submodule worktrees; validate from the verified artifact.
- Never include a checksum manifest in its own input set.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
