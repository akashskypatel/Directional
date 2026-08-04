# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB19 artifact-only runtime validation is complete. P5 remains open.

Tested checkpoint:

- source `9bff7d352f2751228d10ce72e2860c899f90de80`;
- artifact `8878170954`,
  `surface-cell-p5-cb116-github-source-linux-release`;
- SHA-256
  `c82a27122aaa3f3cc96f6cb3621248ed8eed4bdaf92df503b0f8deb06ec8f5d6`;
- empty source status;
- checksums **40/40**;
- fixture files **26**;
- recursive submodule records **9**.

No configure, build, relink, patch, regeneration, or source modification
occurred during P5-TB19.

The next turn is **P5-CB117 through P5-CB125 code changes + compile-only
build**. Execute no test, benchmark, custom mesh, help/list/discovery command, or
compiled project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB19_Ownership_Compaction_Topology_Output_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb19-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB19_Completion_Topology_Reuse_Output_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_CB108_CB116_Code_Build_Report.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Runtime result

Closed:

- Phase 14–18 **235/235**;
- Phase 16 **39/39**;
- Phase 17 **26/26**;
- typed prepared-domain evidence;
- invalid-midpoint mutation and bit-exact rollback;
- full-suite termination: **583/599** in 100.312 s, maximum RSS 530,259,968 B;
- all formerly blocked heavy cases terminate;
- both bunny paths complete inside established wall/RSS limits;
- four independent processes per bunny path produce deterministic failed-result
  signatures;
- no fallback or source-grid recovery.

Open:

- 16 full-suite assertions;
- positive exact completion reuse (`0/0`);
- cylinder incidence/DCEL;
- shared-edge parity topology;
- pipeline stage/injection/fallback lineage;
- valid nonempty production output;
- smooth duplicate completion and torus/thin incomplete complexes;
- at least 75% same-sample memory reconciliation.

## Earliest typed producers

### Successful side subdivision

Mechanical feature, prescribed sphere, and face-edge bunny fail after a reported
successful subdivision with `repeated-boundary-node`:

- mechanical: cell 24, halfedge 304, node 67;
- sphere: cell 2, halfedge 59, node 13;
- face-edge bunny: cell 2, halfedge 69, node 20.

Repair replacement-path orientation/splicing and prove a simple boundary before
commit. Do not special-case these IDs.

### Open-cylinder incidence

`CylindricalOpenStrandCommitsWithTopologyPreserved` fails boolean incidence
validation before candidate extraction. Add a typed first-entity incidence audit
and repair periodic seam/cell/boundary cycles from topology.

### Route and reuse

The positive whole-complex route still stops at
`same-corner-distinct-boundary`; cache lookup is not reached and counters remain
zero. Define route ownership from canonical boundary occurrences and exact
source charts, then count only validated actual reuse/recompute.

### Completion and pipeline

Plane, cylinder, seam, and close-sheets completed buffers are already
self-intersecting at `completion/output-validation`; optimizer rollback is not
the producer fix. Separately, completion validation preempts injected
optimization/validation tests and changes GP23/GP24/Phase20 lineage. Preserve
validation and restore explicit stage semantics.

Smooth bunny deterministically reports a completion-template duplicate stitched
quad. Torus and thin tube remain `IncompleteSurfaceCellComplex`.

### Memory

Ownership compaction is effective: face-edge falls from 2.513 GB to about
204 MB and smooth from a 3.801 GB SIGKILL to about 451 MB. Categorized same-sample
coverage is still only about 18.7% and 43.4%; extend telemetry rather than
assuming the remainder.

## Required next work

Follow P5-CB117–P5-CB125 in the post-TB19 plan, in order:

1. canonical transaction rollback baseline;
2. typed incidence audit and cylinder DCEL;
3. shared-edge parity topology;
4. repeated-node subdivision producer;
5. same-corner route and genuine reuse;
6. pipeline stage/injection/fallback lineage;
7. valid completion output;
8. smooth duplicate plus torus/thin incomplete complexes;
9. memory telemetry, regression sources, and four-target compile/package gate.

## Compile-only boundary

The next turn must shallow-initialize recursive submodules and compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not run them. Initialize detailed workflow logging before fallible work and
always upload a separate log artifact under `if: always()`.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- Exact ownership compaction fixed the resource catastrophe and restored broad
  topology coverage; preserve it.
- A successful transaction must not be declared until incidence and simple
  domain identity pass on the committed candidate.
- A valid rollback baseline is the canonical transaction-entry state, not a
  pre-canonical manual fixture representation.
- Completion validation revealed that several buffers are invalid before
  optimization; repair the completion producer.
- Deterministic failure and resource compliance are progress, not successful
  quadrangulation.
