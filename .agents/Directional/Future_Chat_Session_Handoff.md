# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E5 explicit degree-two boundary rotational-sector construction is implemented and compiles successfully.

- exact compiled source: `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`;
- artifact: `8934315316`;
- workflow run/job: `31014985061` / `92336594420`;
- post-build workflow cleanup: `790714bbe8dffd1efbe7860093027daf3e0e8d54`.

Runtime acceptance has not been executed for this source. The next turn is **P5-TB33 artifact-only R2E5 validation**. Do not configure, rebuild, relink, patch, regenerate, or modify source. Do not advance to R2F or R3 from compilation.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R2E5_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E5_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r2e5-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E5_Degree_Two_Boundary_Rotation_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E5 package authority

- starting documentation head: `e8f6c3f1641db916c53fc9dc938d0bc5d648a019`;
- workflow event commit: `15704d30fc478858284df89d372fa713f2d88576`;
- exact compiled source: `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`;
- reviewed/applied source diff SHA-256: `b7648b0bf870d7a65a7715a11e58cc2e8258af0118826c843d013384d485cc29`;
- artifact: `8934315316`, `surface-cell-p5-r2e5-github-source-linux-release`;
- artifact SHA-256: `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`;
- workflow-log artifact: `8934315771`, SHA-256 `3681d6b81d1251f3de17a5e004ddce42d3b204d636481ded4a390754ae4ebf34`;
- source status empty;
- recursive checksums **48/48**;
- package files **49**;
- fixtures **26**;
- recursive submodules **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed;
- no project binary executed.

The cleaned validation source contains only `agent-source-snapshot.yml` and zero payloads. The exact-source archive retains the bounded compile workflow; `source-exclusions.txt` records its sole removal from the validation source. The final branch also contains only the base workflow and no patch payloads.

## P5-R2E5 implementation

1. Detects the degree-two rotational degeneracy only for an exact two-ray boundary-node inventory.
2. Requires the local outgoing rays to be exactly the authoritative exterior outgoing and exterior twin.
3. Constructs the complete authoritative exterior sector as `exteriorIncoming -> exteriorOutgoing`.
4. Constructs the complete complementary interior sector as `twin(exteriorOutgoing) -> exteriorTwin`.
5. Requires valid reciprocal twins, distinct incoming halfedges, endpoint continuity, and exactly one use of each outgoing target.
6. Preserves authoritative loop identity only on the exterior successor and canonical source-entity rotation identity on the interior successor.
7. Adds derived `boundaryDegreeTwoRotationalNodeCount` only after the complete local audit succeeds.
8. Retains the R2E4 canonical adjacent-ray rotational construction unchanged for three or more rays.
9. Retains typed `BoundaryRotationalSystemConflict` for genuinely incomplete, contradictory, invalid-twin, or non-bijective evidence.
10. Leaves canonical aliases, ordered loops, paired boundary identity, repeated-edge/node, disk, owner, and Euler validators unchanged.
11. Adds a boundary-only triangle contract and strengthens planar, hard-rail, cylinder, orientation, and higher-valence contracts; compiled but not executed.

This is direct producer-level sector construction, not a target repair, validator exception, post-hoc cycle decomposition, or cell merge.

## P5-TB33 execution order

1. Verify artifact SHA, source commit, source status, **48/48** checksums, 49 files, 26 fixtures, nine submodules, target hashes, one cleaned base workflow, and zero payloads.
2. First run the P5-TB32 regression scopes and require restoration of all 21 regressions.
3. Require source-chart **11/11**, source validator **6/6**, recovery **9/9**, feature/barrier **8/8**, graph-dependent **5/6**, and Phase 18 **57/57**.
4. Run the new boundary-only triangle and all exact degree-two sector mapping/rejection contracts.
5. Run the existing higher-valence rotational contract separately and prove it remains on the `rayCount >= 3` branch.
6. Preserve source-face-row and whole-orientation incidence-hash invariance.
7. Require Phase 16 at least **45/47**, Phase 17 at least **20/26**, Phase 20 **46/48**, and complete suite at least **597/625** with no failure absent from the P5-TB31 failure set.
8. Run direct plane, seam, close sheets, disconnected close sheets when available, and cylinder with fallback `Fail` and recovery disabled.
9. Preserve plane's 9 arrangement cells, 9 simplified cells, and 12 candidate quads; do not regress the other direct cases.
10. After all P5-TB32 regressions close, classify remaining planar, hard-rail, cylinder, and bunny producers independently.
11. Run the complete suite exactly once with runtime and memory evidence.
12. Advance to R2F only after every boundary rotational, exterior, repeated-edge/node, disk, owner, Euler, planar, hard-rail, and cylinder gate closes and bunny is the sole remaining R2 producer.

## End-of-turn PR comment requirement

At the end of every Code + Build, Test + Benchmark, and optional Review turn, post a **new final comment on PR #8** after all documentation commits. The comment must identify the exact evidence/source commit, turn result, remaining gates, authoritative next-turn plan, and final branch/documentation head. It must be the final repository write of the turn.

## Known procedural lessons

- A two-ray cyclic order has two semantic sectors even though predecessor and successor ray IDs coincide.
- Sector identity at valence two must come from authoritative source-boundary side, not neighboring-ray uniqueness.
- A derived degree-two diagnostic must increment only after the complete local sector cardinality audit succeeds.
- Git source archives do not include initialized submodule worktrees; validate from the verified artifact.
- Never include a checksum manifest in its own input set.

## Mandatory working-branch hygiene

At Code + Build turn start and end, remove superseded workflows, markers, patch fragments, patch READMEs, transfer files, and generated build artifacts. Retain only the base workflow plus one bounded active workflow/payload while remote work runs. Remove the bounded workflow and payloads immediately after artifact upload.

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
