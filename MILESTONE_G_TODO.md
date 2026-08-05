# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-TB35 artifact-only R2E7 validation**.
- Next turn: **P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build**.
- R2 remains open. Do not advance to R2F or R3.

## P5-TB35 authority

- Exact source: `31c8d9a212f649df7c70fe9291d1fac8c4db7132`.
- Artifact: `8938299309`, SHA-256 `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`.
- Manifest **48/48**; files **49**; fixtures **26**; recursive submodules **9**.
- Clean source: one base workflow and zero payloads.
- No configure, build, relink, patch, regeneration, source/test/build-logic modification, or fixture modification.
- Evidence: `directional-p5-tb35-8938299309-evidence.zip`, SHA-256 `c9e4a77b2b9709921a445fb8295a6eff16e62268325a844c1a886deff08e595b`.

## Results

- [x] source chart **11/11**;
- [x] validator **6/6**;
- [x] recovery **9/9**;
- [x] feature/barrier **8/8**;
- [x] graph-dependent **5/6**, bunny only;
- [ ] R2 focused **13/16**;
- [ ] Milestone D **5/7**;
- [ ] Phase 14–18 **235/244**;
- [ ] Phase 16 **45/47**;
- [ ] Phase 17 **20/26**;
- [x] Phase 18 **57/57**;
- [ ] Phase 20 **46/48**;
- [ ] complete suite **597/625**, 28 failures, XML **206.053 s**; exact RSS unavailable after wrapper detachment.

The complete failure set is identical to P5-TB34.

## Accepted authority

- [x] degree-two and genuine four-disk boundary partitions pass;
- [x] source-row and whole-orientation identity pass;
- [x] hard rail passes incidence, directed side pairs, disk, loop, Euler, one-exterior/two-bounded cell count, full ownership, and distinct bounded rail-twin owners;
- [ ] hard-rail embedding and aggregate topology fail;
- [ ] planar still fails typed `BoundaryFanSectorCoverConflict` before publication;
- [ ] Phase 17 remains **20/26** through invalid upstream arrangement inputs;
- [ ] cylinder and bunny remain independent R2 producers.

## Required P5-R2E8 work

- [ ] enumerate direct canonical cyclic R1 corner sectors at every affected boundary node;
- [ ] do not seed the complete cover from generic intrinsic successor choices;
- [ ] exclude only the exact independently proven exterior adjacency;
- [ ] fail typed on non-identical duplicate incoming/target claims without arbitrary selection;
- [ ] derive hard-rail sides from exact incident source-face/chart corners;
- [ ] require one compatible ownership/chart root for each predicted bounded rail-side orbit;
- [ ] preserve all accepted R2E5/R2E6/R2E7 authority and unchanged validators;
- [ ] leave FlowRep, Phase 17, completion, optimizer, fallback/recovery, memory, and bunny out of scope;
- [ ] compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- [ ] execute no project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB35_Artifact_Only_R2E7_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E8_Canonical_Boundary_Corner_Sector_Code_Build_Plan.md`
- `benchmark-results/p5-tb35-summary.json`
- `.agents/Directional/Milestone_G_P5_R2E7_Code_Build_Report.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `TODO`

Every completed turn ends with a new final PR #8 handoff comment after all documentation commits.

P5 remains open.
