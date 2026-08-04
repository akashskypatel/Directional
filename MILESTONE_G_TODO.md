# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `a1fec970297739cfe23ade339b6a7b57071b7300`.
- Artifact: `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`.
- Artifact SHA-256: `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`.
- Completed turn: **P5-TB25 artifact-only R1D validation**.
- Next turn: **P5-R2 directed wedge/incidence reconstruction + compile-only build**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery default-off, distinct `SourceGridRecovery`, authority **9/9**.
- [x] R1 orientation — opposite traversal accepted; equal-direction rejected.
- [x] R1 adjacent local sheets — exact topology may cross chart labels while provenance and true barriers remain authoritative.
- [x] R1 runtime — source charts **11/11**, validator **6/6**, graph-dependent **6/6**, feature/barriers **8/8**, Phase 14–18 **247/247**.
- [ ] R2 — directed wedge/incidence reconstruction before cell assignment. **Next**
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

## P5-TB25 evidence

Package authority:

- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodule records **9**;
- no configure, build, relink, patch, regeneration, or source modification.

Runtime:

- source-chart R1 **11/11**;
- Phase 22 validator **6/6**;
- recovery authority **9/9**;
- graph-dependent focused **6/6**;
- feature-rail/barrier focused **8/8**;
- Phase 14–18 **247/247**;
- Phase 16 **39/39**;
- Phase 20 **46/48**;
- direct plane/seam/close sheets **0/3**;
- complete suite **598/617** in **333.444 seconds**;
- observed `VmHWM` at least **582,904 KiB**.

Compared with P5-TB24, failures improve **23 → 19**, but suite duration regresses **4.43×** and observed memory is at least **2.27×**. Three bunny executions each require about 108–113 seconds. Termination is demonstrated; production performance is not.

## Earliest remaining producer: R2

Current arrangement construction uses one global outgoing order per node, sets the radial predecessor of each incoming twin as successor, then splits repeated-node cycles after the successor relation exists.

Evidence:

- `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` — topology invalid;
- `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` — `non-disk-cell cell=0 halfedge=43 twin=42 next=29`;
- plane/seam/close-sheet outputs retain manifold and valence failures with zero rail, provenance, or sheet failures;
- cylinder reaches `InvalidCompletionQuadEmbedding`, pattern variant 51, bow-tie intersection.

## R2 requirements

Follow `.agents/Directional/Milestone_G_P5_R2_Directed_Wedge_Incidence_Code_Build_Plan.md`:

- [ ] inventory directed source-chart wedges before successor assignment;
- [ ] consume R1 transition/fan identity;
- [ ] preserve local-sheet provenance without using raw sheet equality as a standalone split;
- [ ] preserve component, hard-rail, boundary, nonmanifold, and disconnected-fan barriers;
- [ ] assign exactly one successor and predecessor per halfedge within one admissible wedge;
- [ ] audit twin symmetry, continuity, multiplicity, and full permutation coverage;
- [ ] remove post-hoc repeated-node cycle splitting;
- [ ] reject repeated-node/repeated-edge cycles with typed evidence;
- [ ] classify exterior cycles before cell IDs;
- [ ] retain meaningful cylinder, hard-rail, close-sheet, permutation, and nonmanifold tests;
- [ ] keep R3–R11 deferred.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. Execute no project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB25_Artifact_Only_R1D_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb25-summary.json`
- `.agents/Directional/Milestone_G_P5_R2_Directed_Wedge_Incidence_Code_Build_Plan.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/DESIGN.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
