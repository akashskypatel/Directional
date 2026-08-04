# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB91 through P5-CB98 are implemented. The implementation authority is commit
`34edce9e508fd81e28bbd6b68a064a2a57bacf03`; the exact GitHub source compiled
for closeout is descendant commit
`680d81c6946f45b1daed9dd477cfde565f8ac7a2`.

GitHub Actions run `30864341083` completed successfully and compiled exactly:

- `directional_core`
- `directional_pipeline`
- `directional_phase1_tests`
- `directional_benchmarks`

No test, benchmark, custom mesh, help/list, discovery, or compiled project binary
was executed.

Compiled artifact:

- ID `8875627676`
- `surface-cell-p5-cb98-github-source-linux-release`
- SHA-256 `b9560c9438289e90e6acca3a0f4b7f1d46a5ad34663693c1243bf4176056c165`
- checksums **38/38**
- fixture files **26**
- empty source status

Dedicated detailed workflow log artifact:

- ID `8875628150`
- `surface-cell-p5-cb98-workflow-logs-30864341083`
- SHA-256 `f31e7d57d137399634187edbac5902732e0226172bc80248c1abf41ff61513e8`

The next turn is **P5-TB17 artifact-only test and benchmark** using artifact
`8875627676`. Do not rebuild.

P5 remains open because the new runtime contracts have not been executed.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/GitHub_Workflow_Policy.md`
4. `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`
5. `benchmark-results/p5-tb16-summary.json`
6. `.agents/Directional/Milestone_G_P5_CB91_CB98_Parity_Reuse_Fixture_Output_Memory_Code_Build_Report.md`
7. `benchmark-results/p5-cb98-summary.json`
8. `.agents/Directional/Milestone_G_P5_CB98_GitHub_Compile_Closeout_Report.md`
9. `benchmark-results/p5-cb98-github-closeout-summary.json`
10. `.agents/Directional/Milestone_G_P5_Post_CB98_Artifact_Test_Benchmark_Plan.md`

## Last runtime evidence

P5-TB16 tested exact source `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`:

- complete suite **583/593**;
- ten assertion failures;
- zero signal-11 terminations;
- all three prior crash cases terminate normally;
- four face-edge and four smooth-field random-bunny runs are deterministic and
  within wall/memory limits;
- both field paths fail closed at
  `BoundaryParityRepair:MixedCellSourceScope` and emit no output;
- exact reuse, intended invalid midpoint, cylinder topology/output, remaining
  production outputs, and RSS reconciliation remained open.

## Implemented in P5-CB91–P5-CB98

- Exact authoritative cell component/sheet scope is captured before parity
  subdivision.
- Mixed/missing scope fails before mutation with typed entity and mutation-phase
  evidence.
- Replacement halfedges, twins, node occurrences, provenance, and cells inherit
  authoritative scope before validation.
- Completion reuse identity covers authoritative source dependencies rather than
  allocation-local IDs.
- Cache mismatch vectors, transactional rebind validation, and actual reuse/
  recompute accounting are present.
- Missing-chart and invalid-midpoint fixtures are distinct and require exact
  rollback.
- Cylinder fixture uses canonical crossing entities and validates strict DCEL
  topology before simplification.
- Output source ownership derives from provenance; first-invalid producer
  diagnostics identify the responsible stage/entity.
- Memory evidence separates logical payload, retained capacity, peak,
  simultaneous ownership, and acquire/release events.

## Workflow policy and lessons

All future workflows must follow
`.agents/Directional/GitHub_Workflow_Policy.md`:

- initialize detailed logging before fallible work;
- preserve activity and command output for success and failure;
- always upload a dedicated log artifact under `if: always()`;
- use that artifact for failed-workflow diagnosis;
- do not expose tokens or credentials in traced output;
- preserve compile-only versus test/benchmark boundaries.

The closeout workflow initially failed validation because workflow-level `env`
used the step-only `${{ runner.temp }}` context. Fixed paths under `/tmp` were
used instead. The corrected workflow parsed and completed successfully.

Patch synchronization lesson: a normal patch failure can mean the output is
already present. Verify output blobs before treating it as missing work.

## Required next turn

Follow the post-CB98 artifact plan exactly:

1. Download artifact `8875627676`; verify digest, checksums, exact source,
   dependencies, binaries/libraries, and fixture closure without rebuilding.
2. Run the ten P5-TB16 failures plus focused parity/reuse/midpoint/cylinder/
   output/memory regressions.
3. Run Phase 14–18, Milestone E, Milestone D, P23/P26/P27/Phase 20, the three
   former crash cases, and the complete suite.
4. Run four face-edge and four smooth-field random-bunny processes with zero
   warmups, one measured run, fallback `Fail`, and source-grid recovery off.
5. Require deterministic valid nonempty pure-quad output, positive exact reuse,
   intended invalid-midpoint rollback, valid cylinder and production outputs,
   and meaningful peak-RSS reconciliation.

Preserve all prohibitions: no validator weakening, fallback/recovery
substitution, synthetic counters, positional merging, source-triangle pairing,
arbitrary subset search, fixture/ID special case, or timeout-as-correctness.

If a gate remains open, record the first invalid producer/entity and create one
bounded next code/build plan. Otherwise advance to final P5 closeout.
