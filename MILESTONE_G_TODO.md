# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-R2E9 canonical boundary wrap-sector and bounded rail-orbit chart publication Code + Build**.
- Next turn: **P5-TB37 artifact-only R2E9 Test + Benchmark**.
- R2 remains open. Do not advance to R2F or R3 from compile evidence.

## P5-R2E9 compile authority

- Exact source: `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c`.
- Workflow event: `29e71770a3c2ff001fa6daa687a2bdf957dd79c4`.
- Run/job: `31046039110` / `92441663510`.
- Artifact: `8946700183`, SHA-256 `bae182ef1e3e5fbbc9fff25ea60a56821e31e4e6fe81787137cdac58f30c6a3a`.
- Log artifact: `8946700685`, SHA-256 `03e137c8af8c41a24595ba1176a3e575fe8da34c44c4605d352a2c9629117e37`.
- Manifest **19/19**; package files **20**; recursive submodules **9**; compile/link actions **132/132**.
- Built exactly four approved targets; no project binary was executed.

## R2E9 implementation status

- [x] canonical cyclic R1 fan-pair inventory precedes chart filtering;
- [x] vector-wrap pair is explicitly represented;
- [x] every non-exterior pair requires one exact supporting chart corner;
- [x] the independently proven exterior pair is excluded once and only once;
- [x] local incoming/target publication remains transactional and bijective;
- [x] canonical-pair, exterior-exclusion, and wrap diagnostics are derived from accepted records;
- [x] each accepted hard-rail root is propagated over its complete bounded successor orbit;
- [x] opposite hard-rail bounded sides retain distinct roots;
- [x] one authoritative chart root is published per bounded orbit and materialized cell;
- [x] full provenance remains separate from directed embedding authority;
- [x] Phase 17 and downstream validators remain unchanged;
- [x] compile-only gate passed;
- [ ] runtime acceptance pending P5-TB37.

## Last runtime baseline

- source chart + validator **17/17**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **26/26**;
- Phase 18 **57/57**;
- Phase 14–18 **241/244**;
- Phase 20 **46/48**;
- complete suite **603/625**, 22 failures.

Planar previously published incidence but omitted the cyclic-wrap interior sector and produced Euler `0`. Hard rail previously had valid incidence, cell inventory, disk, loop, Euler, and ownership but invalid embedding/topology. Cylinder and bunny remain independently open.

## Required P5-TB37 work

- [ ] verify artifact archive and all 19 internal manifest entries exactly;
- [ ] execute packaged binaries only, without configure, rebuild, relink, patch, or source modification;
- [ ] run source-chart and validator prerequisites;
- [ ] run the focused R2 set and require planar positive canonical-pair inventory, one exterior exclusion, positive wrap count, Euler `1`, and valid aggregate topology;
- [ ] require one complete authoritative root per hard-rail bounded orbit, distinct opposite roots, valid embedding, and valid aggregate topology;
- [ ] preserve degree-two, genuine four-disk, source-row, orientation, pinched-fan, close-sheet, bridge/support, nested, and nonmanifold authority;
- [ ] preserve Phase 17 **26/26**;
- [ ] run milestone/phase aggregates and the complete suite;
- [ ] run deterministic direct production processes only after focused regressions, with fallback `Fail` and source-grid recovery disabled;
- [ ] classify every changed result and produce the next plan from the earliest remaining producer.

## Current authority

- `.agents/Directional/Milestone_G_P5_R2E9_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r2e9-summary.json`
- `benchmark-results/p5-tb36-summary.json`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- durable design, reorientation, remediation, and workflow-policy documents
- `TODO`

Every completed turn ends with a new final PR #8 handoff comment after all documentation and PR metadata writes.

P5 remains open.
