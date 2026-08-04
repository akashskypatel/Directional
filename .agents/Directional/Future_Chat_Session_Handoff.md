# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB108 through P5-CB116 source changes and the compile-only build are
complete. P5 remains open because runtime acceptance has not been run for this
checkpoint.

Exact compiled checkpoint:

- source: `9bff7d352f2751228d10ce72e2860c899f90de80`;
- compile-only run: `30871579432` — **success**;
- artifact: `8878170954`,
  `surface-cell-p5-cb116-github-source-linux-release`;
- artifact SHA-256:
  `c82a27122aaa3f3cc96f6cb3621248ed8eed4bdaf92df503b0f8deb06ec8f5d6`;
- mandatory workflow-log artifact: `8878171276`;
- log SHA-256:
  `9f1531b930be97ceb674eb4f0f788cd5271673fbc77fc600df1f0768d36d28e6`;
- reviewed patch SHA-256:
  `e35e2afc376e2cc34fe552f0e76bd7a7628f67255da4f5c44ab369830e0181cd`;
- source status empty;
- checksums **40/40**;
- fixture files **26**.

The turn compiled exactly `directional_core`, `directional_pipeline`,
`directional_phase1_tests`, and `directional_benchmarks`. It executed no test,
benchmark, custom mesh, help/list/discovery command, or compiled project binary.

The next turn is **P5-TB19 artifact-only test and benchmark**. Execute the
packaged binaries directly from artifact `8878170954`. Do not configure, build,
relink, patch, regenerate, or modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_CB108_CB116_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_TB18_Canonical_Ownership_Output_Memory_Test_Benchmark_Report.md`
5. `benchmark-results/p5-tb18-summary.json`
6. `.agents/Directional/Milestone_G_P5_Post_TB18_Ownership_Compaction_Topology_Output_Code_Build_Plan.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Implemented model

### Compact exact ownership

`SurfaceCellComplex` now owns one sorted exact ownership registry. A cell stores
only a fixed-size `{source component, registry ordinal}` key and its own exact
incident `(component, source face, local sheet)` chart records. Canonical class
membership is stored once, remains exact and collision-free, and is independent
of source-face row and insertion order.

The registry participates once in structural hashes, rollback identities,
transactional copies/restoration, logical payload accounting, and retained
capacity accounting. This removes the P5-TB18 `O(cells × component faces)`
ownership duplication from the source model.

### Unlabeled topology

When complete explicit labels are absent, intrinsic face adjacency derives
source components and deterministic default charts. Complete explicit labels
remain authoritative. Interior cells without valid registry ownership now fail
closed instead of passing through an empty registry.

### Simplification and prepared-domain validation

Arrangement, simplification, feasibility repair, descriptors, and rollback use
the same registry-backed ownership utility. Ad-hoc `{component, sheet}` merge
fallbacks were removed.

Prepared-domain auditing now reports typed failures for repeated boundary node,
repeated halfedge, non-simple boundary, missing source chart, and ownership
registry mismatch. Descriptor early returns retain typed evidence.

### Midpoint, cylinder, and output changes

- The malformed-midpoint fixture replaces only its target occurrence/chart and
  preserves unrelated shared-node chart data.
- The cylinder closure fixture supplies explicit consistent ownership labels so
  classifier ambiguity does not preempt topology validation.
- The pipeline validates completed output before optimization, retains a valid
  completed checkpoint, identifies invalid completion at
  `completion/output-validation`, and rolls back from invalid optimizer output
  to the last valid checkpoint.

## Runtime acceptance is not established

Do not assume that compilation closes:

- the P5-TB18 Phase 14–18, Milestone D/E, Phase 20, or full-suite failures;
- same-corner route repair or positive exact completion reuse;
- malformed midpoint after valid common-chart setup and exact rollback;
- canonical cylinder incidence/stitching/orientation/disk/Euler/boundary loops;
- production output for any fixture;
- random-bunny face-edge or smooth completion, determinism, wall time, or RSS;
- the 75% same-sample memory reconciliation gate.

P5-CB112, full P5-CB114/P5-CB115 runtime closure, and quantitative memory
closure remain open until P5-TB19 evidence exists.

## P5-TB19 execution order

1. Validate artifact SHA, exact source, empty source status, recursive submodules,
   26 fixtures, and 40 packaged checksums.
2. Run new compact-registry, unlabeled ownership, face-row invariance,
   prepared-domain, midpoint, cylinder, route/reuse, output, and memory focused
   regressions.
3. Run the 20 P5-TB18 complete-suite failures and the three formerly blocked
   heavy cases individually.
4. Run Phase 14–18, Milestone D, Milestone E, Phase 20, and the complete suite;
   compare with P5-TB18's 573/593 completed aggregate.
5. Run both guaranteed reuse scenarios and require real `reused > 0` and
   `recomputed > 0`; synthetic counters are forbidden.
6. Run missing-common-chart and malformed-midpoint separately. The malformed
   case must mutate temporarily, reach `InvalidMidpointEmbedding`, and roll back
   bit-exactly.
7. Validate cylinder incidence, embedding, orientation, disk cells, Euler 0,
   one component, two boundary loops, and protected strand/rail preservation
   before simplification.
8. Run the full direct production matrix with fallback `Fail` and source-grid
   recovery disabled. Require the returned mesh itself to be nonempty,
   source-valid, manifold, and pure quad for supported cases.
9. Run one random-bunny face-edge and one smooth process first. Repeat four
   independent processes only after a path completes within the established
   wall/RSS limits. Compare complete structural/result digests.
10. Reconcile categorized simultaneous ownership against the same peak-RSS
    sample and require at least 75% coverage.
11. For every unmet gate, preserve the earliest typed stage/entity and write the
    next focused code/build plan. Do not patch source in the runtime turn.

## Expected decision points

- If Phase 16 no-label topology remains invalid, inspect the derived registry,
  component canonicalization, and exact incident charts before changing a
  validator.
- If Phase 17 still fails, inspect transaction-boundary canonicalization and
  registry key preservation through merges and rollback.
- If prepared cells fail, use the new typed domain failure and exact entity; do
  not accept a non-simple disk.
- If reuse stays zero, inspect same-corner route ownership, affected-patch
  discovery, dependency mismatch vectors, cache lookup order, and rebind
  validation before changing counters.
- If a completed mesh is invalid before optimization, repair the completion
  producer. If optimization invalidates a valid checkpoint, verify rollback and
  accepted-step validation.
- If memory remains excessive, distinguish registry membership, per-cell
  incident charts, rollback/prepared copies, descriptor/cache lifetime, and
  allocator/RSS remainder against the same sample.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Workflow policy

Every GitHub workflow must initialize detailed logging before fallible work,
always upload a separate log artifact under `if: always()`, avoid exposing
secrets, and preserve the current turn boundary.

## Key lessons

- Exact class membership belongs once per complex; cell-local keys and incident
  charts must not duplicate component-wide payloads.
- A compact ordinal is safe only when its registry is deterministic, exact, and
  included in rollback and structural identity.
- Missing labels require intrinsic derivation, not skipped validation or a
  partial implicit/explicit ownership mixture.
- Typed evidence must survive every descriptor early return.
- A valid completed mesh is a transactional checkpoint; optimizer failure must
  not discard it.
- Compile success proves source/build validity only. Runtime topology, reuse,
  output, determinism, and resource gates remain separate acceptance criteria.
