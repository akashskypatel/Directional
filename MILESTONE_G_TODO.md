# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **Design-Aligned Artifact-Only Test + Benchmark**.
- Next turn: **Design-Aligned Uniform Phase-Front Code + Build**.
- P5 remains open. Do not advance to adaptive, feature-complete, or bunny work.

## Artifact-only test authority

- artifact: `8974081923`;
- artifact SHA-256: `4166325a2f38fa17d05d0d7e71cb147760a1e5208a6e971f60c35665bf3671de`;
- exact source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- workflow event: `b412c8f78a7b597b204b52efbb64afc9899d6517`;
- workflow run/job: `31118705108` / `92674426941`;
- internal checksums: **49/49**;
- recursive submodules: **9/9**;
- fixture/input closure: **26/26**;
- tracked source status: empty;
- no configure, compile, relink, patch, regeneration, source edit, test edit, fixture edit, or validator edit occurred.

## Direct producer acceptance

- [ ] plane — failed `NotProductionReady/completion`; 106 traces, 9 arrangement cells, 12 quads; `completion/output-validation:AggregateCompletionValidationFailure`; 15 validation failures;
- [ ] multi-face seam — failed `NotProductionReady/completion`; 137 traces, zero arrangement cells and quads; `SideSubdivisionRepair:InvalidInputIncidence`;
- [ ] close sheets — failed `NotProductionReady/completion`; 158 traces, zero arrangement cells and quads; `SideSubdivisionRepair:InvalidInputIncidence`;
- [ ] cylinder — failed `NotProductionReady/completion`; 732 traces, zero arrangement cells and quads; `SideSubdivisionRepair:InvalidInputIncidence`.

All four used requested and executed backend `SurfaceCells`, fallback `Fail`, no fallback attempt, source-grid recovery disabled, no remesh output, and output origin `None`. Three independent benchmark processes per fixture produced identical stage hashes, terminal state, and structural counts.

## Default-suite result

- direct producer acceptance: **0/4**;
- remaining producer tests: **79/79**;
- completion tests: **154/164**;
- validation tests: **60/60**;
- compiled API tests: **8/8**;
- non-overlapping total: **301/315**, 14 failures.

## Test validity corrections still required

- [ ] move `StrictValidatorOverheadStaysBelowFivePercent` to optional benchmark/closeout coverage; it failed once and passed in the full run plus five isolated repeats;
- [ ] demote `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` to historical coverage;
- [ ] demote `OneCandidateBudgetIsExactAndDoesNotRecurse` to historical coverage;
- [ ] correct `PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` so invalid degenerate embedding is not expected to succeed;
- [ ] reconstruct Phase 17 fixtures whose `beforeDefect` precondition is currently zero;
- [ ] reconstruct candidate/mutation fixtures from valid oversampled embedded complexes instead of obsolete topology-invalid synthetic inputs.

No direct acceptance assertion may be weakened while correcting these tests.

## Uniform phase-front proof

- [ ] add authoritative local phase, integer lattice coordinate, branch rotation, and scale level;
- [ ] add directed front-edge ownership with one unfilled side or explicit exterior side;
- [ ] transport phase and lattice identity through source-chart transitions;
- [ ] implement compatible merge, boundary termination, hard-rail capture, phase mismatch, and periodic holonomy conflict events;
- [ ] construct plane cells directly from phase-compatible fronts;
- [ ] feed already-decided cells to arrangement;
- [ ] prohibit arrangement from inventing connectivity through pair-local fan-sector inference on the new path;
- [ ] preserve exact source provenance, fail-closed validation, and close-sheet barriers;
- [ ] compile only the approved seven targets and package a self-contained artifact;
- [ ] execute no tests or benchmarks during the Code + Build turn.

## Current authority

- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`

Every completed turn ends with a new top-level PR #8 handoff comment after all documentation and PR metadata writes. That comment is the final repository write.
