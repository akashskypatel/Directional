# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Last tested source: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Implementation source: `34edce9e508fd81e28bbd6b68a064a2a57bacf03`.
- Exact GitHub-compiled source: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`.
- Completed turn: P5-CB91 through P5-CB98 code changes + GitHub compile-only closeout.
- Next turn: P5-TB17 artifact-only test and benchmark using artifact `8875627676` without rebuilding.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB82 — earlier global-frontier, rollback, scoped identity,
      liveness, rail, fixture, and memory implementation turns.
- [x] P5-TB11–P5-TB15 — earlier runtime diagnosis turns.
- [x] P5-CB83–P5-CB90 — FlowRep lifetime, parity scope, reuse, rail, fixture,
      output, memory, and compile artifact.
- [x] P5-TB16 — 583/593; all prior signal-11 cases terminate; remaining parity,
      reuse, fixture, output, and memory gates identified.
- [x] P5-CB91 — authoritative pre-transaction parity scope and typed failure.
- [x] P5-CB92 — exact dependency identity, transactional rebind, reuse evidence.
- [x] P5-CB93 — intended invalid-midpoint fixture and exact rollback contract.
- [x] P5-CB94 — canonical open-cylinder DCEL fixture and topology assertions.
- [x] P5-CB95 — producer/output ownership and first-invalid diagnostics.
- [x] P5-CB96 — complete stage-owned memory accounting and timeline.
- [x] P5-CB97 — regression sources.
- [x] P5-CB98 — compile-only build/package gate.
- [x] P5-CB98-SYNC — exact seven-file non-workflow patch and 14/14 implementation blob parity verified.
- [x] P5-CB98-GITHUB-COMPILE — exact pushed GitHub source compiled successfully with mandatory detailed log artifact.
- [ ] P5-TB17 — artifact-only closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-CB98 GitHub compile closeout evidence

- Workflow: `.github/workflows/agent-build-recovered-p5.yml`.
- Run ID: `30864341083`; job ID: `91852874765`; conclusion: **success**.
- Exact pushed source: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`.
- Local checkout SHA equaled remote branch SHA.
- Source status was empty before and after compilation.
- GNU C++ 13.3.0, CMake 3.31.6, Ninja 1.13.2, Release `-O2 -DNDEBUG`.
- Ninja actions: **131/131**.
- Required targets compiled and linked:
  - `directional_core`
  - `directional_pipeline`
  - `directional_phase1_tests` — not executed
  - `directional_benchmarks` — not executed
- Compiled artifact ID: `8875627676`.
- Compiled artifact digest: `sha256:b9560c9438289e90e6acca3a0f4b7f1d46a5ad34663693c1243bf4176056c165`.
- Packaged checksums: **38/38**; packaged fixtures: **26**; source status bytes: **0**.
- Dedicated log artifact ID: `8875628150`.
- Log artifact digest: `sha256:f31e7d57d137399634187edbac5902732e0226172bc80248c1abf41ff61513e8`.
- No test, benchmark, custom mesh, help/list, discovery, or compiled project binary command ran.

## GitHub workflow policy

All future workflows must follow `.agents/Directional/GitHub_Workflow_Policy.md`:

- initialize detailed persistent logging before fallible work;
- retain exact activity and command output on success and failure;
- always upload a dedicated log artifact with `if: always()`;
- diagnose failures from that artifact;
- never expose secrets in command traces;
- preserve compile-only versus test/benchmark turn boundaries.

The malformed workflow-level `runner.temp` references were removed. The successful closeout run proves the corrected policy-compliant workflow is valid.

## P5-TB16 runtime baseline

| Scope | Passed | Failed |
|---|---:|---:|
| Phase 14–18 | **230** | **0** |
| Patch descriptor Milestone E | 22 | 3 |
| P23 + Phase 20 | 53 | 1 |
| Milestone D | 6 | 1 |
| Complete suite | **583** | **10** |

The complete suite had zero signal-11 terminations. The former crash cases all terminated normally; one P27 matrix case still failed assertions.

Both random-bunny field paths failed before descriptor acceptance at:

```text
NotProductionReady/completion
BoundaryParityRepair:MixedCellSourceScope
```

They used neither fallback nor source-grid recovery and emitted no output.

## P5-TB17 closure gates

- Validate artifact `8875627676` directly; do not rebuild.
- All ten prior assertion failures pass for the intended reason.
- Both guaranteed reuse scenarios report `reused > 0`.
- Invalid midpoint is reached after valid common-chart setup and rollback is bit-exact.
- Cylinder topology and production output pass.
- Plane, seam, torus, mechanical-feature, and Phase 20 output pass.
- Four face-edge and four smooth-field runs are deterministic and return valid nonempty pure-quad surface-cell output without fallback/recovery.
- Stage-owned memory telemetry is internally consistent and reconciles dominant peak RSS ownership.
- Complete suite has no unexpected failure or abnormal termination.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb16-summary.json`
- `.agents/Directional/Milestone_G_P5_CB91_CB98_Parity_Reuse_Fixture_Output_Memory_Code_Build_Report.md`
- `benchmark-results/p5-cb98-summary.json`
- `.agents/Directional/Milestone_G_P5_CB98_GitHub_Compile_Closeout_Report.md`
- `benchmark-results/p5-cb98-github-closeout-summary.json`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `.agents/Directional/Milestone_G_P5_Post_CB98_Artifact_Test_Benchmark_Plan.md`

P5 remains open. PR #8 remains draft and unmerged.
