# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build**.
- Next turn: **P5-TB36 artifact-only R2E8 Test + Benchmark**.
- R2 remains open. Do not advance to R2F or R3.

## P5-R2E8 compile authority

- Exact source: `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`.
- `SurfaceArrangement.cpp` blob: `76e57fef36f9322598387b6b5e968a14b885b755`.
- Workflow run: `31041383154`.
- Artifact: `8944910920`, SHA-256 `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`.
- Compile/link actions: **132/132**.
- Built exactly four approved targets; no project binary was executed.

## R2E8 implementation status

- [x] direct cyclic R1 corner-sector inventory for affected higher-valence boundary nodes;
- [x] independently proven exterior continuation exclusion;
- [x] complete one-to-one local incoming/target audit before publication;
- [x] exact hard-rail incident face/chart roots;
- [x] distinct roots for opposite hard-rail sides;
- [x] predicted bounded rail-side orbit common-root audit;
- [x] generic intrinsic successors demoted from complete-cover authority;
- [x] downstream topology validators unchanged;
- [x] degree-two and genuine four-disk code paths preserved;
- [x] compile-only gate passed;
- [ ] runtime acceptance pending P5-TB36.

## Last runtime baseline

- source chart **11/11**;
- validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**, bunny only;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 14–18 **235/244**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite **597/625**.

The runtime baseline predates R2E8. Planar previously failed `BoundaryFanSectorCoverConflict` before publication. Hard rail previously passed incidence, directed side pairs, disk, loop, Euler, one-exterior/two-bounded cell count, full ownership, and distinct bounded rail-twin owners, but failed embedding and aggregate topology.

## Required P5-TB36 work

- [ ] verify artifact archive and internal manifest exactly;
- [ ] execute packaged binaries only, without configure, rebuild, relink, patch, or fixture modification;
- [ ] run source-chart and validator prerequisites;
- [ ] run R2 focused, Milestone D, Phase 16, Phase 17, Phase 18, Phase 14–18, Phase 20, graph-dependent, and complete-suite scopes;
- [ ] verify planar direct sector count, exterior exclusion, local bijection, publication, and unchanged topology validators;
- [ ] verify hard-rail incident chart roots, side-pair audits, bounded orbit roots, embedding, and aggregate topology;
- [ ] preserve degree-two, genuine four-disk, row-order, whole-orientation, pinched-fan, close-sheet, bridge/support, nested, and nonmanifold authority;
- [ ] run deterministic bunny processes only after focused regressions, with fallback `Fail` and source-grid recovery disabled;
- [ ] classify every changed result against the prior runtime baseline;
- [ ] produce the next plan from the earliest remaining authoritative producer.

## Current authority

- `.agents/Directional/Milestone_G_P5_R2E8_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r2e8-summary.json`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`

Every completed turn ends with a new final PR #8 handoff comment after all documentation and PR metadata writes.

P5 remains open.
