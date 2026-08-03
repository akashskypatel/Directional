# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — global ownership-frontier remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Tested artifact: `8848599037` (`surface-cell-p5-global-frontier-linux-release`).
- Exact source: `643cc483e430d2cd161dde94a983aedac4be57dd`.
- Completed turn: P5-TB11 artifact-only test and benchmark.
- Next turn: code changes + compile-only build.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation and artifact.
- [x] P5-TB11 — artifact validation completed; closure gates failed.
- [ ] P5-CB51 — correct atomic transaction budget semantics.
- [ ] P5-CB52 — global completion-template ownership assignment.
- [ ] P5-CB53 — correct and prove exact product reuse.
- [ ] P5-CB54 — restore fail-closed result and diagnostic invariants.
- [ ] P5-CB55 — remediate authoritative test regressions.
- [ ] P5-CB56 — package complete runtime fixture closure.
- [ ] P5-CB57 — recover wall time.
- [ ] P5-CB58 — compile/package corrected checkpoint.
- [ ] P5-TB12 — artifact-only validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB11 evidence

- Authoritative tests: **294/303 passed**.
- Full binary: **549/578 passed**.
- 17 full-suite failures are absolute-path fixture dependencies.
- Four random-bunny processes failed closed deterministically.
- Wall mean: **61.277891 s**; maximum memory: **936,484,864 B**.
- Initial completion-template inventory: **143**.
- Sequential variant commits: **41**.
- Remaining same-corner inventory / route candidates: **92 / 92**.
- Candidate budget / consumed / structural attempts: **2 / 0 / 0**.
- Terminal reason: `candidate-budget`.

The budget gate rejects `frontier.size()` before component partitioning and batching. Completion-template ownership also performs repeated full assembly cycles and remains a wall-time blocker.

## Next authority

- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_P5_TB11_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Candidate_Budget_Code_Build_Plan.md`
- `benchmark-results/p5-tb11-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
