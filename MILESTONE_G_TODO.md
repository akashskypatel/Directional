# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Source implementation commit: `57be334c7a5d41538dcfd7011f429da525d2d2ca`.
- Exact clean compiled source: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Compile-only run: `30849904147` — **success**.
- Artifact: `8870351914` (`surface-cell-p5-cb90-parity-flowrep-reuse-rail-linux-release`).
- Digest: `sha256:ce6ca28d8eb41562c3486077934302643100fab575f34ea8a341e3212964a7e4`.
- Completed turn: P5-CB83 through P5-CB90 code changes + compile-only build.
- Next turn: P5-TB16 artifact-only test and benchmark without rebuilding.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB82 and P5-TB11–P5-TB15 — earlier implementation and artifact diagnosis.
- [x] P5-CB83 — eliminate stale FlowRep references and high-cardinality ownership hazards; add forced-reallocation regression source.
- [x] P5-CB84 — inherit one authoritative pre-transaction cell scope through parity replacement pieces and twins.
- [x] P5-CB85 — canonical authoritative source-domain dependency identity for exact completion reuse.
- [x] P5-CB86 — preserve final rail/curve identity and complete provenance independently of selected cell scope.
- [x] P5-CB87 — correct invalid-midpoint, missing-chart, and cylinder simplification fixtures without weakening preconditions.
- [x] P5-CB88 — apply source-supported producer ownership, scope, rail, and lifetime corrections; runtime output closure remains for TB16.
- [x] P5-CB89 — trace, FlowRep, arrangement, and simplification stage-owned memory telemetry and release bounds.
- [x] P5-CB90 — regression sources and clean compile/package gate.
- [ ] P5-TB16 — artifact-only closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## Compile-only evidence

The clean Ninja Release workflow compiled only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

It verified clean source status, shallow recursive submodules, fixture closure, packaging, and checksums. No executable was run.

## P5-TB16 gates

Run artifact `8870351914` directly without rebuilding.

- [ ] Generated-smooth-field production and matrix cases return normally instead of signal 11.
- [ ] Face-edge random bunny parity repair commits with exact inherited source scope.
- [ ] Positive exact reuse is observed in both intended regressions, with no dependency mismatch reuse.
- [ ] Final arrangement halfedges retain authoritative `railId`, `curveId`, feature class, rail parameters, and provenance.
- [ ] Missing-chart and invalid-midpoint tests reach distinct typed failures; cylinder fixture is topology-valid before simplification.
- [ ] Plane, cylinder, seam, torus, mechanical-feature, Phase 20 cylinder, and production-matrix output contracts pass or yield newly localized producer failures.
- [ ] Deterministic structural hashes and diagnostics match across independent processes.
- [ ] Wall time, peak working set, stage-owned bytes, release flags, and maximum simultaneous live structures satisfy the production gates.

## Current authority

- `.agents/Directional/Milestone_G_P5_Parity_Scope_FlowRep_Reuse_Rail_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Parity_Scope_FlowRep_Reuse_Rail_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_TB15_Parity_Scope_Reuse_Rail_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb15-summary.json`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
