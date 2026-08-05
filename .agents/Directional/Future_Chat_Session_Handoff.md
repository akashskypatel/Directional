# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB32 artifact-only R2E4 validation is complete against exact source `ec44ab7570f258f800a27086fca053c573878a13` and artifact `8929111021`.

R2E4 introduces a broad fail-closed regression at ordinary degree-two boundary nodes. The complete suite is **575/624** with 49 failures. Relative to P5-TB31, one new test was added, no failure closed, and 21 failures regressed.

The next turn is **P5-R2E5 degree-two boundary rotational degeneracy Code + Build**. Do not advance to R2F or R3.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E5_Degree_Two_Boundary_Rotation_Code_Build_Plan.md`
5. `benchmark-results/p5-tb32-summary.json`
6. `.agents/Directional/Milestone_G_P5_R2E4_Code_Build_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E4_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB32 authority

- exact tested source: `ec44ab7570f258f800a27086fca053c573878a13`;
- workflow event commit: `d81351aeb6bb7b728ceaf5bf468f924383167eb9`;
- artifact: `8929111021`, SHA-256 `dcb3dcca095a62efde3bc534a8eafca1a5a3976f3e98b649845c6ca47c682450`;
- reviewed/applied diff SHA-256: `33ee4e40c7e5146abd732796b771d74ed28b7808bae6b0ed14bd327fd902aa01`;
- source status empty; checksums **48/48**; files **49**; fixtures **26**; submodules **9**; target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- no configure, build, relink, patch, regeneration, fixture modification, or source modification during validation;
- evidence bundle: `directional-p5-tb32-8929111021-evidence.zip`, SHA-256 `b31a0259b313332b6234dc3aacd85593b5703f42d2707fbbd5b0ade2f0355aca`.

## Runtime summary

- source-chart R1 **11/11**;
- source validator **6/6**;
- recovery **9/9**;
- feature/barrier **6/8**;
- graph-dependent **2/6**;
- R2 focused **2/15**;
- Milestone D **3/7**;
- Phase 14–18 **215/243**;
- Phase 16 **27/46**;
- Phase 17 **18/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite **575/624**, 49 failures, **157.156 s**.

A reliable complete-suite RSS measurement is unavailable because the outer wrapper detached while the single allowed run continued to normal XML completion. Focused and direct runs retain individual memory evidence.

## Earliest producer

R2E4 chooses cyclic direction by testing whether the authoritative exterior outgoing is the predecessor or successor of the exterior twin in the canonical ray order.

For exactly two rays, predecessor and successor are the same opposite ray. The implementation therefore sees both checks succeed and classifies the equivalent degree-two cyclic directions as contradictory `BoundaryRotationalSystemConflict` evidence.

This rejects ordinary source-boundary vertices before successor publication. It causes the 21 regressions in planar, curved, bridge, support, ownership, disconnected, close-sheet, source-row, orientation, Milestone D, and downstream Phase 17 contracts.

The correct degree-two rotation contains two distinct sectors bounded by the same ray pair:

- authoritative exterior: `exteriorIncoming -> exteriorOutgoing`;
- complementary interior: `twin(exteriorOutgoing) -> exteriorTwin`.

Sector identity comes from authoritative source-boundary side, not from uniqueness of the neighboring ray ID.

## First actions for P5-R2E5

1. Confirm the branch descends from this handoff and contains only the base workflow with no payload directory.
2. Inspect the R2E4 `rayCount`, predecessor/successor, `rotationStep`, and local target-cardinality logic.
3. Add an explicit `rayCount == 2` complete two-sector branch.
4. Retain the existing canonical adjacency branch only for `rayCount >= 3`.
5. Restore all 21 P5-TB32 regressions without weakening any test or validator.
6. Preserve canonical aliases, ordered boundary loops, and paired boundary incidence hashing.
7. Keep FlowRep, tracing, simplification, completion, fallback, recovery, optimizer, cache, lineage, and memory out of scope.
8. Compile exactly the four approved targets and execute no project binary.
9. Remove the bounded workflow and payloads after artifact upload.

## End-of-turn PR comment requirement

At the end of every Code + Build, Test + Benchmark, and optional Review turn, post a **new final comment on PR #8** after all documentation commits. The comment must identify the exact evidence/source commit, turn result, remaining gates, authoritative next-turn plan, and final branch/documentation head. It must be the final repository write of the turn.

## Known procedural lessons

- A two-ray cyclic order has two semantic sectors even though predecessor and successor ray IDs coincide.
- Do not infer sector identity solely from neighboring ray uniqueness at valence two.
- Transactional fail-closed behavior is correct, but a typed failure does not make an incorrect producer acceptable.
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
