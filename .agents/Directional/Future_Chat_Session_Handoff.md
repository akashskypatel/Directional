# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E4 authoritative boundary-node rotational-system construction is implemented and compiles successfully.

- exact compiled source: `ec44ab7570f258f800a27086fca053c573878a13`;
- artifact: `8929111021`;
- workflow run/job: `31002566593` / `92294705089`;
- post-build workflow cleanup: `d59ddc2c72459287e4c3af5f6a6939443aae6f12`.

Runtime acceptance has not been executed for this source. The next turn is **P5-TB32 artifact-only R2E4 validation**. Do not configure, rebuild, relink, patch, regenerate, or modify source. Do not advance to R2F or R3 from compilation.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R2E4_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E4_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r2e4-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB31_Artifact_Only_R2E3_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E4_Boundary_Node_Rotation_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E4 package authority

- starting documentation head: `fbec81c04d8134da81482e347389a5fde085feaf`;
- workflow event commit: `d81351aeb6bb7b728ceaf5bf468f924383167eb9`;
- exact compiled source: `ec44ab7570f258f800a27086fca053c573878a13`;
- reviewed/applied source diff SHA-256: `33ee4e40c7e5146abd732796b771d74ed28b7808bae6b0ed14bd327fd902aa01`;
- artifact: `8929111021`, `surface-cell-p5-r2e4-github-source-linux-release`;
- artifact SHA-256: `dcb3dcca095a62efde3bc534a8eafca1a5a3976f3e98b649845c6ca47c682450`;
- workflow-log artifact: `8929111261`, SHA-256 `a83b4533e6847976a1e942aff8a47b725a8ff468bc586477cc39fb3f45c206ba`;
- source status empty;
- recursive checksums **48/48**;
- package files **49**;
- fixtures **26**;
- recursive submodules **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed;
- no project binary executed.

The cleaned validation source contains only `agent-source-snapshot.yml` and zero payloads. The exact-source archive retains the bounded compile workflow; `source-exclusions.txt` records its sole removal from the validation source. The final branch also contains only the base workflow and no patch payloads.

## P5-R2E4 implementation

1. Discards the R2E3 two-target transposition and reconstructs every affected node-local mapping directly.
2. Requires one canonical SourceVertex or SourceEdge wedge containing the complete local outgoing-ray inventory.
3. Uses the authoritative exterior incoming/outgoing pair to select semantic cyclic direction.
4. Maps every incoming twin to the adjacent outgoing ray in that canonical order exactly once.
5. Treats the single wrap adjacency as the exterior sector and all other adjacencies as interior sectors, with hard rails and traces acting as separators.
6. Adds typed `BoundaryRotationalSystemConflict` evidence and derived `boundaryRotationalNodeCount` diagnostics.
7. Audits local rotational bijection and exact authoritative exterior-loop continuation before global predecessor and orbit audits.
8. Preserves the passing orientation-invariant paired boundary-subsegment incidence identity.
9. Leaves repeated-edge/node, non-disk, owner, and structural Euler validators unchanged.
10. Adds a generalized multiple-interior-rays-at-one-boundary-vertex contract; compiled but not executed.

This is not target swapping, missing-target repair, post-hoc cycle decomposition, or cell merging.

## P5-TB32 execution order

1. Verify artifact SHA, source commit, source status, **48/48** checksums, 49 files, 26 fixtures, nine submodules, target hashes, one cleaned base workflow, and zero payloads.
2. Run source-chart, source-validator, recovery, and feature/barrier authority.
3. Run graph-dependent and all R2/R2C/R2D/R2E/R2E2/R2E3/R2E4 contracts.
4. Require complete canonical rotational inventories, typed rotational conflicts, and one-to-one local incoming/outgoing mappings.
5. Preserve whole-orientation and source-row incidence-hash invariance.
6. Require planar, hard-rail, and cylinder orbit/disk/Euler/owner closure.
7. Run Milestone D, Phase 14–18, Phase 16, Phase 17, and Phase 18 independently.
8. Run direct plane, seam, close sheets, disconnected close sheets, and cylinder with fallback `Fail` and recovery disabled.
9. Require nonzero valid seam, close-sheet, and cylinder arrangement inventories.
10. Run Phase 20 and the complete suite once with runtime and memory evidence.
11. Advance to R2F only after every boundary rotational, orbit, disk, owner, and Euler gate closes; advance to R3 only after all R2 gates close.

## End-of-turn PR comment requirement

At the end of every Code + Build, Test + Benchmark, and optional Review turn, post a **new final comment on PR #8** after all documentation commits. The comment must identify the exact evidence/source commit, turn result, remaining gates, authoritative next-turn plan, and final branch/documentation head. It must be the final repository write of the turn.

## Known procedural lessons

- A locally bijective target permutation can still encode the wrong cyclic sectors; construct the full rotation from one canonical wedge.
- Exterior direction must be semantic and source-authoritative, not chosen from row order or raw chart direction.
- Git source archives do not include initialized submodule worktrees; use the verified artifact and do not classify missing archived submodules as a source defect.
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
