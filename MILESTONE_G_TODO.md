# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Exact compiled source: `a1fec970297739cfe23ade339b6a7b57071b7300`.
- Artifact: `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`.
- Artifact SHA-256: `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`.
- Completed turn: **P5-R1D adjacent local-sheet exact-adjacency code + compile-only build**.
- Next turn: **P5-TB25 artifact-only R1D validation**.
- Do not advance to R2 until R1 runtime closes.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] P5-TB22 — deterministic terminating baseline, **585/600**, production **0/8**.
- [x] P5-TB23 — identified inverted source-edge orientation and GP26 termination regression.
- [x] R0 compile and runtime — recovery defaults off, explicit recovery reports `SourceGridRecovery`, authority **9/9**.
- [x] R1 orientation predicate — opposite traversal accepted; equal-direction traversal rejected; focused orientation **7/7**.
- [x] Packaged Phase 22 validator authority — **6/6**.
- [x] R1D compile — exact manifold adjacency no longer requires equal local-sheet labels; provenance and true barriers preserved.
- [ ] R1D runtime — P5-TB25 must close graph-dependent, feature-rail, phase, analytic, and termination gates.
- [ ] R2 — directed wedge/incidence reconstruction before cell assignment.
- [ ] R3 — topology-distinct patch completion engine.
- [ ] R4 — repeated-node wedge/splice producer.
- [ ] R5 — explicit local lattice phase and advancing-front event state.
- [ ] R6 — torus decomposition/descriptor support.
- [ ] R7 — adaptive dyadic 2:1 transitions.
- [ ] R8 — direct analytic production validation.
- [ ] R9 — real completion-cache reuse after geometry succeeds.
- [ ] R10 — production-valid later-stage lineage fixtures after geometry succeeds.
- [ ] R11 — truthful synchronized memory telemetry after geometry succeeds.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-R1D package evidence

- P5-TB24 tested source `f4cce52006d21a248473e327ada1d66183af54e6`;
- workflow event commit `6fc57831afc7f77e0cda9bd1f409aaaaece15bda`;
- exact compiled source `a1fec970297739cfe23ade339b6a7b57071b7300`;
- applied source-diff SHA-256 `4488988dc877f1a0a001e27286b68f2752314bade361d59a11c1e7eae8a6cd89`;
- successful run `30942950398`, job `92105699139`;
- artifact `8906115786`, SHA-256 `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`;
- workflow logs `8906116758`, SHA-256 `c8ceb09ca4ea9f72148125466a9958366b51a52f8e02c229aa71d1852b2d1ec2`;
- source status empty;
- recursive checksum manifest **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodule records **9**;
- all **132/132** Ninja actions completed;
- compiled exactly four required targets;
- no project binary executed.

## R1D implementation

- [x] exact opposite-winding manifold transitions may cross different local-sheet labels within one component;
- [x] local-sheet labels remain in chart IDs, transition records, rebound provenance, hashes, and diagnostics;
- [x] different source components remain disconnected;
- [x] hard rails remain barriers;
- [x] source boundaries remain barriers;
- [x] nonmanifold incidence creates no transition;
- [x] disconnected topology remains distinct;
- [x] intrinsic source-vertex fans follow corrected exact adjacency;
- [x] same-sheet restrictions remain for proximity/capture/projection;
- [x] four focused R1D contracts added;
- [x] row-permutation and whole-orientation contracts strengthened with unequal local-sheet labels;
- [x] no validator weakening, recovery substitution, positional fallback, R2 work, or bunny-specific behavior.

## Last runtime evidence: P5-TB24

- source-chart orientation **7/7**;
- source-authoritative validator **6/6**;
- focused recovery **9/9**;
- graph-dependent focused **3/6**;
- Phase 14–18 **240/243**;
- Phase 16 **37/39**;
- Phase 20 **46/48**;
- analytic plane/seam/close sheets **0/3**;
- complete suite **590/613**, terminated in **75.260 seconds**.

No runtime improvement is claimed from compile evidence.

## P5-TB25 requirements

Follow `.agents/Directional/Milestone_G_P5_R1D_Test_Benchmark_Plan.md`:

- [ ] verify exact artifact authority and source archive;
- [ ] pass all eleven `SourceChartTransitionsR1.*` contracts;
- [ ] preserve Phase 22 validator **6/6** and recovery **9/9**;
- [ ] pass the three P5-TB24 graph-dependent failures;
- [ ] pass `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets`;
- [ ] retain hard-rail, component, nonmanifold, and disconnected-sheet barriers;
- [ ] run Phase 14–18 and Phase 16 independently;
- [ ] run direct plane, seam, close sheets, and any packaged disconnected-close-sheet case;
- [ ] run complete Phase 20;
- [ ] run the complete suite once and treat timeout as failure;
- [ ] do not run the full direct bunny matrix solely for R1D.

Execute artifact `8906115786` directly. No configure, rebuild, relink, patch, regeneration, or source modification.

Advance to R2 only after source-chart and adjacent-local-sheet R1 authority closes independently. A later analytic failure must be identified by its earliest typed producer.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Milestone_G_P5_TB24_Artifact_Only_R1C_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R1D_Adjacent_Local_Sheet_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_R1D_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R1D_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r1d-summary.json`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
