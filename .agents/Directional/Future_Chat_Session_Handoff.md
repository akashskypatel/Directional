# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB34 artifact-only validation is complete against exact source `2444c38b8216656b636f4dad9f8acfa70b86bd41` and artifact `8936470245`.

R2E6 closes the corrected genuine higher-valence four-disk partition and preserves degree-two authority. It regresses ordinary cyclic single-spoke boundary nodes and six Phase 17 contracts, while the interior hard rail remains topology-invalid. Complete suite: **597/625**, 28 failures. R2 remains open.

The next turn is **P5-R2E7 cyclic fan-sector cover and hard-rail side closure Code + Build**. Do not advance to R2F or R3.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB34_Artifact_Only_R2E6_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E7_Cyclic_Fan_Sector_Cover_Code_Build_Plan.md`
5. `benchmark-results/p5-tb34-summary.json`
6. `.agents/Directional/Milestone_G_P5_R2E6_Code_Build_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E6_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB34 authority

- artifact SHA-256 `bcc2c0d81e4382368a7fcafe7818c79a2e5bdb23d9a044232a4f3294f4554bf5`;
- exact source `2444c38b8216656b636f4dad9f8acfa70b86bd41`;
- workflow event `6cd5a5c10aa0f15eb5e1312145425395b8a8372d`;
- reviewed/applied diff `e4196fd4ed1a68d31ba6310af8e8a4822533fac3c1f0248f75721521785f8d3d`;
- manifest **48/48**; files **49**; fixtures **26**; submodules **9**;
- clean source has one base workflow and zero payloads;
- no source, test, build, or fixture modification;
- evidence `directional-p5-tb34-8936470245-evidence.zip`, SHA-256 `dc662e8d207585ceec9482f64fb859a6e64d38d39892af2f323a84b8d3c0e8c8`.

## Results

- source chart **11/11**;
- source validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 14–18 **235/244**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite **597/625**, XML **73.085 s**.

The complete suite was started once. The outer wrapper detached; the test process continued to normal XML completion and was not rerun. Exact max RSS and wrapper exit code are unavailable.

## Earliest producer diagnosis

R2E6 accepts only intrinsic fan adjacencies with `targetPosition == sourcePosition - 1` and rejects the stored-vector wrap. The fan order is cyclic, so a legitimate source-interior sector may occupy that wrap. Only the independently proven exterior boundary pair should be excluded.

The hard-rail test now passes incidence, predecessor, repeated-cycle, fan-sector, and separator audits, then fails topology. Its current separator audit proves only that the two sector fan identities differ; it does not prove that each directed rail side is paired with the correct adjacent fan in cyclic order.

These two defects explain the planar incidence regression, six Phase 17 regressions, and unresolved hard-rail topology.

## First actions for P5-R2E7

1. Preserve the exact R2E5 degree-two path and passing R2E6 four-disk test.
2. Enumerate adjacent pairs modulo each authoritative R1 fan ray cycle.
3. Remove exactly the independently identified exterior pair; allow all other valid cyclic pairs, including wrap.
4. Prove each hard-rail directed side against its correct adjacent R1 fan identity and non-rail ray.
5. Audit a complete one-to-one local sector cover transactionally.
6. Restore planar incidence and Phase 17 **26/26** without modifying Phase 17.
7. Keep FlowRep, completion, recovery, fallback, optimizer, memory, and bunny out of scope.
8. Compile exactly the four approved targets and execute no project binary.
9. Remove bounded workflow and payloads after artifact upload.

## End-of-turn requirement

After all documentation commits, post a new top-level PR #8 handoff comment identifying exact source/artifact authority, result, remaining gates, next-turn plan, and final documentation head. It must be the final repository write.

## Preserved prohibitions

- no validator weakening;
- no arbitrary target permutation or subset search;
- no synthetic Euler correction;
- no fallback/recovery substitution;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
