# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Exact implementation and compiled source:
  `9bff7d352f2751228d10ce72e2860c899f90de80`.
- Compile-only run: `30871579432` — **success**.
- Compiled artifact: `8878170954`.
- Completed turn: **P5-CB108 through P5-CB116 code + compile-only build**.
- Next turn: **P5-TB19 artifact-only test and benchmark**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB107 — earlier implementation and compile/package turns.
- [x] P5-TB11–P5-TB18 — runtime diagnosis through the canonical-ownership
      resource regression.
- [x] P5-CB108 — compact exact ownership registry and one-per-complex storage.
- [x] P5-CB109 — unlabeled intrinsic ownership derivation.
- [x] P5-CB110 — registry-backed ownership through simplification and rollback.
- [x] P5-CB111 — typed prepared-domain validation/audit groundwork.
- [ ] P5-CB112 — completion dependency compaction implemented; route validation
      and exact positive reuse require runtime closure.
- [x] P5-CB113 — invalid-midpoint fixture precondition correction.
- [ ] P5-CB114 — cylinder ownership preconditions implemented; canonical DCEL
      runtime closure remains open.
- [ ] P5-CB115 — valid completed-checkpoint/optimizer rollback implemented;
      production-output runtime closure remains open.
- [x] P5-CB116 — regression source and exact compile/package gate.
- [ ] P5-TB19 — artifact-only runtime verification of the CB116 checkpoint.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-CB116 artifact integrity

- Artifact ID: `8878170954`.
- Name: `surface-cell-p5-cb116-github-source-linux-release`.
- Exact source: `9bff7d352f2751228d10ce72e2860c899f90de80`.
- Artifact SHA-256:
  `c82a27122aaa3f3cc96f6cb3621248ed8eed4bdaf92df503b0f8deb06ec8f5d6`.
- Mandatory workflow-log artifact: `8878171276`.
- Log SHA-256:
  `9f1531b930be97ceb674eb4f0f788cd5271673fbc77fc600df1f0768d36d28e6`.
- Reviewed patch SHA-256:
  `e35e2afc376e2cc34fe552f0e76bd7a7628f67255da4f5c44ab369830e0181cd`.
- Packaged source status: empty.
- Recursive checksums: **40/40**.
- Fixture files: **26**.
- Compiled targets:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.
- No test, benchmark, custom mesh, help/list/discovery command, or compiled
  project binary executed.

## Implemented correction model

The exact physical ownership-class membership is now stored once in a sorted
registry owned by `SurfaceCellComplex`. A cell carries only a compact
`{component, ordinal}` key and its exact incident source charts. Registry
membership remains collision-free and face-row independent; exact equality is
not replaced by a hash.

When explicit complete labels are absent, source connected components and
default charts are derived from intrinsic source topology. Explicit labels
remain authoritative. Simplification, parity/subdivision repair, descriptor
audits, structural/rollback hashes, and memory accounting share the same
registry-backed model.

Prepared-domain failures now distinguish repeated nodes, repeated halfedges,
non-simple boundaries, missing charts, and registry mismatches. The pipeline
also validates and retains a completed output checkpoint before optimization so
an invalid optimizer result can roll back to the last valid completed mesh.

## P5-TB19 runtime requirements

Use artifact `8878170954` directly. Do not configure, rebuild, relink, patch,
regenerate, or modify source.

- [ ] Verify package authority, all checksums, submodules, and fixture closure.
- [ ] Run focused compact-registry, unlabeled topology, row-order, prepared-domain,
      route/reuse, midpoint, cylinder, output, and memory regressions.
- [ ] Run Phase 14–18, Milestone D, Milestone E, Phase 20, and the complete
      suite; compare with P5-TB18's 573/593 completed aggregate and three heavy
      blockers.
- [ ] Require genuine positive reused and recomputed completion counts in both
      guaranteed reuse scenarios.
- [ ] Require malformed midpoint to reach `InvalidMidpointEmbedding` after
      temporary mutation and prove exact rollback.
- [ ] Validate the cylinder before simplification: incidence, embedding,
      orientation, disk cells, Euler characteristic 0, one connected component,
      two boundary loops, and protected strand/rail preservation.
- [ ] Run plane, cylinder, multi-face seam, torus, mechanical feature, close
      sheets, prescribed sphere, thin bent tube, and bunny direct production
      cases with fallback and source-grid recovery disabled.
- [ ] Require returned output itself to be nonempty, source-valid, manifold, and
      pure quad for supported cases.
- [ ] Run one face-edge and one smooth random-bunny process first; only perform
      four-run determinism after each path completes within established wall and
      RSS limits.
- [ ] Reconcile categorized simultaneous ownership against the same peak-RSS
      sample and require at least 75% coverage.
- [ ] Preserve the first typed invalid producer and define the next focused
      code/build turn for every unmet gate.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Current authority

- `.agents/Directional/Milestone_G_P5_CB108_CB116_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_TB18_Canonical_Ownership_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb18-summary.json`
- `.agents/Directional/Milestone_G_P5_Post_TB18_Ownership_Compaction_Topology_Output_Code_Build_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
