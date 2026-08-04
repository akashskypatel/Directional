# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Exact compiled source: `306fab5d440199cb090e1aa343fadb6112663edc`.
- Artifact: `8908691591`, `surface-cell-p5-r2-final-github-source-linux-release`.
- Artifact SHA-256: `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`.
- Completed turn: **P5-R2 directed wedge/incidence code + compile-only build**.
- Next turn: **P5-TB26 artifact-only R2 validation**.
- Do not advance to R3 until R2 runtime closes.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority closed.
- [x] R1 orientation and adjacent-chart transitions — runtime closed.
- [x] R1 runtime — source charts **11/11**, validator **6/6**, graph-dependent **6/6**, feature/barriers **8/8**, Phase 14–18 **247/247**.
- [x] R2 compile — explicit directed wedges, one-to-one incidence audit, simple cycles before cell assignment.
- [ ] R2 runtime — P5-TB26 must close focused incidence and Milestone D gates.
- [ ] R3 — topology-distinct patch completion engine.
- [ ] R4 — repeated-node wedge/splice producer.
- [ ] R5 — explicit local lattice phase and advancing-front state.
- [ ] R6 — torus decomposition/descriptor support.
- [ ] R7 — adaptive dyadic 2:1 transitions.
- [ ] R8 — direct analytic production validation.
- [ ] R9 — real completion-cache reuse after geometry succeeds.
- [ ] R10 — production-valid later-stage lineage fixtures.
- [ ] R11 — truthful synchronized memory telemetry.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-R2 package evidence

- P5-TB25 tested source `a1fec970297739cfe23ade339b6a7b57071b7300`;
- implementation commit `9ca13956e8872f5221bcaf51142ef3474232495b`;
- exact compiled source `306fab5d440199cb090e1aa343fadb6112663edc`;
- reviewed patch SHA-256 `e4da79427d33a5fd7bf29b707ec0765974faf0bc67c2dc18e6f2e6e6dd9a8658`;
- formatting-fix SHA-256 `d0696338ecdf5cf9af57b9dca3d56260192c8fe12cf0122a98c45e8b31734522`;
- successful run `30949473754`, job `92127660105`;
- artifact `8908691591`, SHA-256 `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`;
- workflow logs `8908692488`, SHA-256 `1f3cc3630d89f4aacf419d60ece84f9f5c8d5a4e8fa2e59cbb314c79421b97f6`;
- source status empty;
- recursive checksum manifest **41/41**;
- package files **43**;
- fixture files **26**;
- recursive submodule records **9**;
- all **132/132** Ninja actions completed;
- compiled exactly four required targets;
- no project binary executed.

## R2 implementation

- [x] typed directed-incidence failure categories and first-failure evidence;
- [x] canonical source-chart/source-vertex-fan wedge inventory;
- [x] R1 transition reachability consumed before successor assignment;
- [x] local-sheet provenance retained without raw sheet-equality ownership;
- [x] component, hard-rail, source-boundary, nonmanifold, disconnected-fan, and inconsistent-transition barriers retained;
- [x] intrinsic ordering only inside one admissible wedge;
- [x] exactly one successor and predecessor per halfedge;
- [x] global twin, continuity, multiplicity, and permutation audit;
- [x] repeated-node post-processing removed;
- [x] repeated halfedge/node/edge cycles fail closed;
- [x] simple cycles classified before bounded cell IDs;
- [x] canonical `directedIncidenceHash` propagated to immediate consumers and rollback identity;
- [x] focused R2 and Milestone D contracts compiled;
- [x] no R3–R11 work included.

## Last runtime evidence: P5-TB25

- R1 authority clean;
- Phase 14–18 **247/247**;
- Phase 16 **39/39**;
- Phase 20 **46/48**;
- direct plane/seam/close sheets **0/3**;
- complete suite **598/617** in **333.444 seconds**;
- observed `VmHWM` at least **582,904 KiB**.

No runtime improvement is claimed from compile evidence.

## P5-TB26 requirements

Follow `.agents/Directional/Milestone_G_P5_R2_Test_Benchmark_Plan.md`:

- [ ] verify artifact authority and source archive;
- [ ] preserve all R1 gates;
- [ ] pass all new directed-incidence focused contracts;
- [ ] close `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`;
- [ ] close `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved`;
- [ ] prove one-to-one predecessor/successor ownership and simple-cycle coverage;
- [ ] retain hard-rail, source-boundary, component, nonmanifold, and disconnected-sheet barriers;
- [ ] run Phase 14–18 and Phase 16/17/18 scopes;
- [ ] run direct plane, seam, close sheets, cylinder, and any disconnected-close-sheet case;
- [ ] run complete Phase 20;
- [ ] run the complete suite once and compare bunny duration/memory against P5-TB24 and P5-TB25.

Execute artifact `8908691591` directly. No configure, rebuild, relink, patch, regeneration, or source modification.

Advance to R3 only when R2 incidence is independently valid and any remaining analytic failure has later typed completion evidence.

## Current authority

- `.agents/Directional/Milestone_G_P5_R2_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R2_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r2-summary.json`
- `.agents/Directional/Milestone_G_P5_TB25_Artifact_Only_R1D_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2_Directed_Wedge_Incidence_Code_Build_Plan.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/DESIGN.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
