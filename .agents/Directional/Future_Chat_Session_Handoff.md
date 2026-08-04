# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB99 through P5-CB107 code changes and the compile-only build are complete.
P5 remains open.

Exact compiled checkpoint:

- implementation/source commit:
  `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`;
- compile-only run: `30867891341` — **success**;
- artifact: `8876934846`,
  `surface-cell-p5-cb107-github-source-linux-release`;
- artifact SHA-256:
  `ba06737ab313f30e23c74f402114649ee2c9f9d7c3a7177c7e0ba3328749df47`;
- mandatory workflow-log artifact: `8876935182`;
- log SHA-256:
  `465aad3a957b99fdb8e7bf76b2040facc25b1ea1b2c00bfdca1d58990f1498dd`;
- source status empty;
- recursive checksums **39/39**;
- fixture files **26**.

The turn compiled exactly `directional_core`, `directional_pipeline`,
`directional_phase1_tests`, and `directional_benchmarks`. It executed no test,
benchmark, custom mesh, help/list command, or compiled project binary.

The next turn is **P5-TB18 artifact-only test and benchmark**. Execute the
packaged binaries directly from artifact `8876934846`. Do not configure, build,
relink, patch, regenerate, or modify source during that turn.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_CB99_CB107_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_TB17_Parity_Reuse_Output_Memory_Test_Benchmark_Report.md`
5. `benchmark-results/p5-tb17-summary.json`
6. `.agents/Directional/Milestone_G_P5_Post_TB17_Source_Scope_Topology_Reuse_Output_Memory_Code_Build_Plan.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Implemented source model

The code now separates:

- connected source component;
- canonical physical cell-side ownership class;
- exact per-source-face chart records
  `(source component, source face, local sheet)`.

Canonical classes are derived from intrinsic source/DCEL adjacency. A cell can
span adjacent face-local chart IDs only when the stitched topology proves one
physical side. Same-face labels, disconnected components, and close/opposing
sheets are not combined by frequency, count, order, position, or shared numeric
labels. Rail lineage remains independent from the incident chart.

The canonical ownership contract and exact chart map are propagated through:

- arrangement cells and structural hashes;
- patch/domain identity audits;
- simplification candidate compatibility and transactional merges;
- parity/subdivision preflight, rebuilt records, and rollback identities;
- completion ownership classification and exact reuse dependencies;
- logical payload and retained-capacity accounting.

Regression sources were added for adjacent chart equivalence, disconnected close
sheet separation, and a malformed midpoint with a valid common-chart
precondition.

## Runtime acceptance is not yet established

Compilation does not prove that the P5-TB17 runtime failures are corrected. In
particular, do not assume closure of:

- the 22 P5-TB17 assertions;
- completion reuse and route repair;
- the canonical cylinder DCEL;
- production output for the full fixture matrix;
- random-bunny direct output;
- the 75% peak-RSS ownership-reconciliation gate.

P5-CB104, P5-CB105, and quantitative P5-CB106 remain runtime-gated until P5-TB18
provides evidence.

## P5-TB18 execution order

1. Validate artifact source commit, empty status, submodules, fixture closure,
   and all packaged checksums.
2. Run the new P5-CB99–P5-CB107 focused regressions and all 22 P5-TB17 failing
   cases.
3. Run Phase 14–18 and Milestone D closure; compare against the P5-TB17 baseline
   of 572/594 for the complete suite.
4. Run both guaranteed exact-reuse scenarios. Require genuine positive reused
   and recomputed completion counts; do not accept synthetic telemetry.
5. Run missing-common-chart and malformed-midpoint cases separately. The latter
   must reach `InvalidMidpointEmbedding` after temporary mutation and prove
   bit-exact rollback.
6. Validate the cylinder DCEL before simplification: incidence, embedding,
   orientation, disk cells, Euler 0, one connected component, and two boundary
   loops.
7. Run the production fixture matrix with direct `SurfaceCells`, fallback
   `Fail`, and source-grid recovery disabled.
8. Run four independent random-bunny face-edge processes and four independent
   smooth-field processes. Compare complete structural/result digests.
9. Reconcile categorized simultaneous ownership against the same peak-RSS
   sample and require at least 75% coverage.
10. For every unmet gate, preserve the earliest typed stage/entity evidence and
    write the next focused code/build plan. Do not patch source in the runtime
    turn.

## Expected decision points

- If cells 19 and 45 no longer stop at
  `BoundaryParityRepair:MixedCellSourceScope`, continue to the next earliest
  failure rather than treating that as production closure.
- If Phase 16 or Phase 17 still regresses, inspect the exact canonical class and
  chart map before changing validation.
- If reuse remains zero, inspect affected-patch discovery, dependency mismatch
  vectors, rebind validation, and route ownership before modifying counters.
- If output is invalid, distinguish a completion-produced invalid mesh from an
  optimizer regression and retain the first invalid entity.
- If memory reconciliation stays below 75%, report the categorized remainder;
  do not inflate reported ownership.

## Preserved prohibitions

- no validator weakening;
- no frequency-vote or count/order scope restoration;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Workflow policy

Every GitHub workflow must follow
`.agents/Directional/GitHub_Workflow_Policy.md`:

- initialize detailed logging before fallible work;
- retain complete success/failure activity;
- always upload a separate log artifact under `if: always()`;
- use that artifact for failure diagnosis;
- do not expose secrets in traced output;
- preserve the current turn boundary.

## Key lessons

- A per-face local-sheet integer is a chart label, not a physical cell-side
  identity across the source surface.
- Canonical equivalence must be proved by intrinsic adjacency and preserved with
  the exact chart map; selecting a representative by frequency or order is not
  authoritative.
- Compile success only establishes source/build validity. Runtime topology,
  output, reuse, and resource gates remain independent acceptance criteria.
- Keep fixture preconditions explicit so an intended late failure is not
  preempted by an unrelated earlier validator.
- Memory reconciliation must count retained capacity and concurrent owners
  against the same RSS sample, without synthetic estimates.
