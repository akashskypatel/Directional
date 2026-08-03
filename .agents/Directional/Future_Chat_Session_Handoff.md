# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB16 tested artifact `8870351914` directly without rebuilding. P5 remains open.

- Source implementation commit: `57be334c7a5d41538dcfd7011f429da525d2d2ca`.
- Exact tested source: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Digest: `sha256:ce6ca28d8eb41562c3486077934302643100fab575f34ea8a341e3212964a7e4`.
- Source status empty; packaged checksums **36/36**; fixture closure valid.
- Complete suite: **583/593 passed**, 10 assertion failures, **0 signal-11 terminations**.
- Four face-edge and four smooth-field bunny processes terminate deterministically within wall and memory limits.
- Both bunny paths still fail closed at `BoundaryParityRepair:MixedCellSourceScope` before descriptor acceptance.
- Next turn: **P5-CB91 through P5-CB98 code changes + compile-only build**.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb16-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB16_Parity_Reuse_Fixture_Output_Memory_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_Parity_Scope_FlowRep_Reuse_Rail_Code_Build_Report.md`

## P5-TB16 findings

### Closed by runtime evidence

- High-cardinality generated-smooth-field FlowRep no longer crashes.
- The forced-reallocation endpoint-completion regression passes.
- All three previously signal-11 tests terminate normally; two pass and the matrix test fails only its production-success assertions.
- The complete 593-test suite terminates normally.
- Final arrangement halfedges retain authoritative rail/curve identity and complete provenance in the focused stage-six regression.
- Stage-owned tracing, FlowRep, arrangement, and simplification telemetry is populated and deterministic.

### Still open

- Face edges: `1,860 -> 0` odd cells only inside a parity transaction rejected for mixed source scope.
- Smooth field: `959 -> 0` odd cells only inside the same rejected parity transaction.
- Both field paths produce zero descriptors, zero completed patches, zero reuse, and no output.
- Both positive exact-reuse regressions remain at zero reused completions.
- The invalid-midpoint fixture still reaches `MissingCommonSourceChart` because node-level fields do not create compatible occurrence charts.
- The cylinder simplification fixture still fails initial incidence validation.
- Plane, cylinder, seam, torus, mechanical-feature, Phase 20 cylinder, and production-matrix output contracts remain open.
- Current stage-owned sums explain only 32.65% of face-edge peak RSS and 42.70% of smooth-field peak RSS.

## Required next turn

Implement P5-CB91 through P5-CB98 from the post-TB16 code/build plan.

Priorities:

1. Carry one exact pre-transaction component/sheet scope through every replacement cell, oriented halfedge, twin, node occurrence, and provenance record; add typed first-invalid diagnostics.
2. Add reusable-product field mismatch diagnostics, remove remaining allocation-local dependencies, and produce positive exact reuse.
3. Populate explicit compatible node occurrences for the invalid-midpoint rollback fixture.
4. Rebuild the cylinder fixture from one canonical intrinsic edge representation and prove DCEL incidence before simplification.
5. Repair the earliest invalid producer for each remaining production-output case without weakening validation.
6. Reconcile Eigen, associative-container, retained-capacity, diagnostic, and overlapping-lifetime memory ownership with process RSS.
7. Add regression sources for every corrected contract while preserving the passing FlowRep and rail gates.
8. Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no binary.

## Preserved constraints and lessons

- Do not weaken topology, source-lineage, manifold, orientation, or pure-quad validation.
- Do not convert direct `SurfaceCells` failure into fallback or recovery success.
- Do not deduplicate final faces, merge positionally, pair source triangles, add production-ID special cases, use arbitrary subset search, or treat timeout as correctness.
- Tests must exercise their named contract. Fix invalid fixture construction rather than weakening production code.
- Exact reuse counters and memory telemetry must be derived from real state, never incremented synthetically.
- Workflow files must be valid YAML and changed directly through the GitHub connector. Do not use workflows for tests or repository mutations.
