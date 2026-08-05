# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- P5-TB28 tested source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`.
- Tested artifact: `8913777837`, SHA-256 `bcb9c6962677f2f638cf6a832eb25d88fdcd2a97e506a1435a7f936d4891416a`.
- Completed turn: **P5-TB28 artifact-only R2D validation**.
- Next turn: **P5-R2E source-boundary side ownership and Euler topology accounting + compile-only build**.
- R2 remains open; do not advance to R3.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority closed.
- [x] R1 — source transitions and validator authority closed.
- [x] R2 directed incidence compile/runtime narrow contracts.
- [x] R2C bridge/core ownership compile and focused runtime contracts.
- [x] R2D source nonmanifold preflight and nested multi-boundary representation.
- [ ] R2E source-boundary side ownership and aggregate Euler topology.
- [ ] R2F singularity-fan embedding, only if still independent after R2E.
- [ ] R3 — topology-distinct patch completion engine.
- [ ] R4 — repeated-node wedge/splice producer.
- [ ] R5 — explicit local lattice and advancing-front state.
- [ ] R6 — torus decomposition/descriptor support.
- [ ] R7 — adaptive dyadic 2:1 transitions.
- [ ] R8 — direct analytic production validation.
- [ ] R9 — completion-cache reuse after geometry succeeds.
- [ ] R10 — production-valid later-stage lineage fixtures.
- [ ] R11 — synchronized memory telemetry.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-TB28 results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature/barriers | **8/8** |
| Graph-dependent | **5/6** |
| R2/R2C/R2D focused | **11/14** |
| Milestone D | **5/7** |
| Phase 14–18 | **233/242** |
| Phase 16 | **43/45** |
| Phase 17 | **20/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |
| Direct plane/seam/close sheets/cylinder | **0/4** |
| Complete suite | **595/623**, 192.964 s |

R2D closes:

- typed `NonManifoldSourceEdge` rejection;
- nested two-boundary Euler-zero `NonDisk` representation;
- two complete-suite failures, with no new failures.

R2 remains open because:

- planar topology still has Euler `-1`, area error `1`, and no exterior cell;
- an interior hard rail still creates two exterior cells for one source boundary loop;
- cylinder has valid incidence and ownership but invalid aggregate topology;
- bunny singularity fan has invalid embedding and zero center cells;
- seam, close sheets, and cylinder still publish zero arrangement cells;
- six Phase 17 failures remain downstream;
- Phase 20 remains 46/48;
- full-suite runtime increases 19.27% versus P5-TB27.

## P5-R2E requirements

- [ ] derive exact interior/exterior side witnesses from oriented source boundary edges;
- [ ] map each canonical source boundary loop to exactly one exterior arrangement orbit;
- [ ] reject contradictory or missing loop ownership with typed arrangement evidence;
- [ ] compute global Euler from explicit bounded-cell Euler contributions;
- [ ] derive boundary-loop diagnostics from canonical loop ownership;
- [ ] preserve complete transactional halfedge/cell ownership;
- [ ] preserve nonmanifold, nested, bridge, and support-only closures;
- [ ] restore planar, hard-rail, and cylinder topology;
- [ ] avoid FlowRep/simplification/completion special cases;
- [ ] keep bunny changes conditional on shared-cause proof;
- [ ] remove all stale agent workflows/payloads before and after build;
- [ ] compile only four required targets; execute no project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB28_Artifact_Only_R2D_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E_Source_Boundary_Topology_Code_Build_Plan.md`
- `benchmark-results/p5-tb28-summary.json`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/DESIGN.md`

Preserve all prohibitions and mandatory working-branch hygiene. P5 remains open. PR #8 remains draft and unmerged.
