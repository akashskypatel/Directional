# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB117 through P5-CB125 source changes and the compile-only package gate are
complete. P5 remains open because runtime acceptance has not been executed for
this checkpoint.

Exact checkpoint:

- implementation commit:
  `a8f8971766f55cf11828a1ae90daad3b98b50664`;
- exact compiled source:
  `bc8ed616adfe59d4a3e0d5dca8ef7503d3c00e83`;
- reviewed patch SHA-256:
  `5657eb0b64aed76a5718d40a5db61e21d0c8fce60bb620e8abcf359062e873b9`;
- compile-only run: `30874916873` — **success**;
- artifact: `8879272440`,
  `surface-cell-p5-cb125-github-source-linux-release`;
- artifact SHA-256:
  `bb9aca3881727093411f7f1012dbae9a65e1d62805a4c5a4900af58bd8f7fc76`;
- mandatory workflow-log artifact: `8879272815`;
- log SHA-256:
  `03c91d91cec65de1682d40af9a20dc9a2900e954de200ce4dbb793b1532fd6b5`;
- empty source status;
- checksums **40/40**;
- fixture files **26**;
- recursive submodule records **9**.

The turn compiled exactly `directional_core`, `directional_pipeline`,
`directional_phase1_tests`, and `directional_benchmarks`. It executed no test,
benchmark, custom mesh, help/list/discovery command, or compiled project binary.

The next turn is **P5-TB20 artifact-only test and benchmark**. Execute packaged
binaries directly from artifact `8879272440`. Do not configure, build, relink,
patch, regenerate, or modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_CB117_CB125_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_TB19_Ownership_Compaction_Topology_Output_Test_Benchmark_Report.md`
5. `benchmark-results/p5-tb19-summary.json`
6. `.agents/Directional/Milestone_G_P5_Post_TB19_Completion_Topology_Reuse_Output_Code_Build_Plan.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Implemented model

### Typed incidence evidence

`audit_complex_incidence` now reports the exact first invalid node, halfedge,
twin, next edge, cell, expected value, actual value, and typed reason. It covers
ID consistency, endpoints, twin symmetry, cell-cycle closure, next/predecessor
symmetry, directed multiplicity, use counts, side metadata, disk cells, and
ownership registry validity.

The cylinder fixture prints this audit when invalid. The cylinder DCEL producer
is not yet claimed repaired.

### Fail-closed subdivision cycles

Subdivision, parity, and side-repair results carry typed domain failures. A
replacement cycle that repeats a node/halfedge or is otherwise non-simple is
rejected and rolled back before mutation is reported successful. This removes
the P5-TB19 false-success contract, but a valid alternative producer path is
still a runtime gate.

### Same-corner routes

Geometric coincidence no longer proves route overlap. Exact canonical boundary
interval overlap remains fail-closed; exact-disjoint routes at the same corner
can enter deterministic repair arbitration. Actual validated cache reuse and
recompute remain runtime gates.

### Local completion embedding

Every completed patch quad is checked for unique vertices, valid rows,
nondegenerate finite normal, nonzero projected area, and opposite-edge crossing.
An invalid local embedding receives
`InvalidCompletionQuadEmbedding;localQuad=<index>`. Only this failure permits
trying another existing bounded deterministic completion variant.

This does not prove global cross-patch output validity or duplicate ownership.

### Canonical fixture baselines

Manual rollback and shared-parity fixtures now enter canonical ownership before
recording structural baselines or recomputing topology diagnostics. Full
structural identity remains required.

## Explicitly open

Do not assume compilation closes:

- P5-TB19 Phase 14–18 **235/235** preservation;
- full-suite improvement from **583/599**;
- the open-cylinder DCEL;
- conforming shared-edge parity success;
- a valid completion after repeated-node proposals are rejected;
- positive exact reuse/recompute;
- pipeline stage injection, fallback, original-failure, and output-origin
  semantics — `RemeshPipeline.cpp` was not changed in this turn;
- global source-valid non-self-intersecting output;
- smooth duplicate completion ownership;
- torus/thin incomplete complexes;
- successful bunny output/determinism;
- 75% same-sample memory reconciliation — telemetry expansion was not
  implemented in this checkpoint.

## P5-TB20 execution order

1. Verify archive SHA, exact source, implementation ancestry, source status,
   recursive checksums, submodules, fixtures, and built-target hashes.
2. Run focused canonical rollback, typed incidence, cylinder, shared parity,
   repeated-node domain, same-corner route/reuse, local completion embedding,
   global output, and pipeline-lineage tests.
3. Run Phase 14–18, Milestone D, Milestone E, GP23/GP24, Phase 20, and the full
   suite; compare with P5-TB19.
4. Require both guaranteed reuse scenarios to show actual `reused > 0` and
   `recomputed > 0`; synthetic counters remain forbidden.
5. Run the eight direct production fixtures with backend `SurfaceCells`, fallback
   `Fail`, and source-grid recovery disabled. Validate the returned mesh itself.
6. Run one face-edge and one smooth random-bunny process first. Repeat only if
   each remains inside the established wall/RSS limits.
7. Preserve the earliest typed failure for every unmet gate and write the next
   focused code/build plan. Do not patch source during the runtime turn.

## Workflow note

The first run, `30874823514`, applied and pushed the source patch but stopped
before compilation because the workflow had not created its build directory
before teeing `configure.log`. It uploaded mandatory failure logs as artifact
`8879148483`. The workflow-only correction produced successful run
`30874916873`. This was not a source compile failure.

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

- Typed incidence evidence must precede topology repair; a boolean invalid flag
  is insufficient.
- A transaction may report success only after both incidence and simple domain
  identity pass.
- Geometric corner coincidence is not authoritative topological route overlap.
- Local patch embedding validation is necessary but does not replace global
  source-authoritative validation.
- Compile success proves source/build validity only; all topology, reuse,
  output, pipeline-lineage, determinism, and telemetry gates remain separate.
