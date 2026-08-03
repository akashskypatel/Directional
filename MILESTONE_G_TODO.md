# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Tested source: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Artifact: `8870351914` (`surface-cell-p5-cb90-parity-flowrep-reuse-rail-linux-release`).
- Digest: `sha256:ce6ca28d8eb41562c3486077934302643100fab575f34ea8a341e3212964a7e4`.
- Source status empty; checksums **36/36**; no rebuild.
- Completed turn: P5-TB16 artifact-only test and benchmark.
- Next turn: P5-CB91 through P5-CB98 code changes + compile-only build.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB82 and P5-TB11–P5-TB15 — earlier implementation and artifact diagnosis.
- [x] P5-CB83 — high-cardinality FlowRep ownership and signal-11 liveness closed.
- [ ] P5-CB84 — parity scope implementation failed runtime gate; reopen under P5-CB91.
- [ ] P5-CB85 — exact reuse implementation failed runtime gate; reopen under P5-CB92.
- [x] P5-CB86 — focused final rail/curve and complete provenance propagation passes.
- [ ] P5-CB87 — both intended fixture gates remain open; reopen under P5-CB93 and P5-CB94.
- [ ] P5-CB88 — production output contracts remain open; continue under P5-CB95.
- [ ] P5-CB89 — memory telemetry populated but RSS reconciliation remains open; continue under P5-CB96.
- [x] P5-CB90 — clean compile and package gate.
- [x] P5-TB16 — artifact-only runtime disposition completed.
- [ ] P5-CB91–P5-CB98 — post-TB16 remediation and compile-only build.
- [ ] P5-TB17 — artifact-only closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB16 test disposition

| Scope | Passed | Failed |
|---|---:|---:|
| Phase 14–18 | **230** | **0** |
| Patch descriptor Milestone E | 22 | 3 |
| P23 + Phase 20 | 53 | 1 |
| Milestone D | 6 | 1 |
| Complete packaged binary | **583** | **10** |

Complete packaged disposition: **583/593 passed**, with 10 assertion failures and **0 signal-11 terminations**.

Newly closed:

- forced-reallocation FlowRep endpoint completion;
- generated-smooth-field production and matrix liveness;
- complete full-suite liveness;
- focused final arrangement rail identity and memory telemetry;
- distinct missing-common-chart fixture.

## Bunny field-path disposition

Four face-edge and four smooth-field processes terminate with identical non-timing diagnostics within each field path.

### Face edges

- wall: `17.475780–19.086715 s`;
- peak working set: `130,035,712–138,072,064 B`;
- trace/strands: `12,130 / 8,913`;
- arrangement/simplified cells: `7,405 / 7,405`;
- odd cells: `1,860 -> 0` inside rejected parity repair.

### Smooth field

- wall: `23.280920–24.560557 s`;
- peak working set: `283,176,960–283,557,888 B`;
- trace/strands: `80,862 / 16,958`;
- arrangement/simplified cells: `21,298 / 21,298`;
- odd cells: `959 -> 0` inside rejected parity repair;
- unresolved required endpoints: `0`.

Both paths report:

```text
BoundaryParityRepair:MixedCellSourceScope
```

Both produce zero descriptors, zero completed patches, zero reuse, and no output. Neither fallback nor source-grid recovery is used.

## Remaining source gates

- Carry one exact pre-transaction scope through every replacement cell, oriented halfedge, twin, node occurrence, and provenance record.
- Add typed parity diagnostics naming the first invalid replacement record and available scopes.
- Add field-level reusable-product mismatch diagnostics and produce positive exact reuse.
- Populate explicit compatible occurrences for the invalid-midpoint transaction fixture.
- Build a topology-valid canonical cylinder DCEL before simplification.
- Repair the earliest invalid producer for every remaining production-output case without weakening validation.
- Reconcile Eigen, associative-container, retained-capacity, diagnostic, and overlapping-lifetime ownership with RSS.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb16-summary.json`
- `.agents/Directional/Milestone_G_P5_Post_TB16_Parity_Reuse_Fixture_Output_Memory_Code_Build_Plan.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
