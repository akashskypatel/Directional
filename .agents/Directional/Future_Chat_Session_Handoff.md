# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E7 cyclic fan-sector cover and directed hard-rail side closure is implemented and compiles successfully.

- exact compiled source: `31c8d9a212f649df7c70fe9291d1fac8c4db7132`;
- artifact: `8938299309`;
- workflow run/job: `31024637616` / `92369812070`;
- workflow cleanup: `a95d2531f87833373bfde92b5d697185f9c71687`.

Runtime acceptance has not been executed for this source. The next turn is **P5-TB35 artifact-only R2E7 validation**. Do not configure, rebuild, relink, patch, regenerate, modify source, or advance to R2F/R3 from compilation.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R2E7_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E7_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r2e7-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB34_Artifact_Only_R2E6_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E7_Cyclic_Fan_Sector_Cover_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E7 package authority

- starting documentation head `7c46b888ff9336a9a83d26097c41b50c3e770a8f`;
- workflow event `7d5450cb6411722818844548de59a09c8f4451d5`;
- exact compiled source `31c8d9a212f649df7c70fe9291d1fac8c4db7132`;
- reviewed/applied source diff `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`;
- artifact `8938299309`, SHA-256 `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`;
- workflow logs `8938299624`, SHA-256 `a4c1dee2951ab2f374b86fca6767ebf17835797fdf4a9a8ac26d9771fc54331c`;
- source status empty; checksums **48/48**; files **49**; fixtures **26**; submodules **9**;
- all four target hashes verified; Ninja **132/132**; compile exit code zero;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- no project binary executed;
- evidence bundle `directional-p5-r2e7-8938299309-evidence.zip`, SHA-256 `d1a81288fb5bf4b9350fb2f90e7423370be567682d0a4a97f7af68d03970c555`.

## P5-R2E7 implementation

1. Preserves the exact R2E5 degree-two mapping and passing R2E6 four-disk partition.
2. Evaluates R1 fan predecessor adjacency modulo fan size, including vector wrap.
3. Excludes only the exact exterior adjacency proven by source-boundary loop authority.
4. Tracks accepted cyclic-wrap interior sectors only after complete local audit.
5. Derives each hard-rail side from separator witness orientation and cyclicly adjacent source fan.
6. Requires opposite rail sides to use distinct fan identities and the expected directed rail/non-rail order.
7. Replaces rail-side sector records transactionally and re-audits every incoming/target exactly once.
8. Leaves global predecessor, repeated-edge/node, disk, ownership, Euler, boundary-loop, orientation, and area validators unchanged.
9. Strengthens planar and hard-rail contracts; Phase 17 remains untouched.

## P5-TB35 execution order

1. Verify artifact SHA, source commit, source status, **48/48** checksums, 49 files, 26 fixtures, nine submodules, target hashes, one cleaned base workflow, and zero payloads.
2. Preserve source-chart **11/11**, validator **6/6**, recovery **9/9**, feature/barrier **8/8**, graph-dependent **5/6**, and Phase 18 **57/57**.
3. Preserve the degree-two and genuine four-disk contracts.
4. Require planar cyclic-wrap sector acceptance and at least the P5-TB33 topology/Euler diagnostic position.
5. Require all six P5-TB34 Phase 17 regressions to close naturally and Phase 17 **26/26**.
6. Require the hard rail to prove directed side pairs, distinct bounded owners, one exterior plus two bounded disks, and all topology subflags.
7. Require R2 focused at least **14/16**, Milestone D at least **6/7**, and Phase 16 **46/47** if planar closes.
8. Run direct analytic cases and the complete suite exactly once.
9. Diagnose any remaining planar, cylinder, and bunny producers independently.
10. Do not advance to R2F until planar, hard rail, cylinder, and all boundary/orbit/disk/owner/Euler gates close and bunny is the sole remaining R2 producer.

## End-of-turn PR comment requirement

At the end of every Code + Build, Test + Benchmark, and optional Review turn, post a **new final comment on PR #8** after all documentation commits. It must identify exact source/evidence, result, remaining gates, next-turn plan, and final documentation head. It must be the final repository write.

## Known procedural lessons

- Stored fan-vector wrap is not a semantic exterior marker; exterior identity must come from source-boundary loop authority.
- A complete hard-rail permutation is insufficient unless both directed sides are proved against the correct adjacent R1 fans.
- Phase 17 regressions caused by invalid arrangement inputs must be repaired upstream, not patched in Phase 17.
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
