# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Tested source: `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.
- Artifact: `8866222973` (`surface-cell-p5-cb82-mixed-sheet-liveness-linux-release`).
- Digest: `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`.
- Source status empty; checksums **36/36**; no rebuild.
- Completed turn: P5-TB15 artifact-only test and benchmark.
- Next turn: P5-CB83 through P5-CB90 code changes + compile-only build.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation.
- [x] P5-TB11 — complete inventory diagnosis.
- [x] P5-CB51–P5-CB58 — budget batching, memory lifetime, fixture closure.
- [x] P5-TB12 — rollback/result/lifetime diagnosis.
- [x] P5-CB59–P5-CB66 — rollback-integrity implementation.
- [x] P5-TB13 — successful-transaction identity, reuse, rail, simplification, lifetime, and wall diagnosis.
- [x] P5-CB67–P5-CB74 — successful-subdivision audit, semantic index, fixed-point API, fixture, rail, and lifetime changes.
- [x] P5-TB14 — mixed-sheet, rollback, reuse, rail, fixture, liveness, crash, output, and wall diagnosis.
- [x] P5-CB75–P5-CB82 — scoped source identity, rollback, reuse buckets, rail rebinding, fixtures, candidate generations, memory diagnostics, compile artifact.
- [x] P5-TB15 — artifact validation; rollback and interface fixtures pass, face-edge liveness passes, parity/output/reuse/rail/smooth-field crash gates fail.
- [ ] P5-CB83 — eliminate high-cardinality FlowRep strands signal 11.
- [ ] P5-CB84 — authoritative source scope through boundary parity repair.
- [ ] P5-CB85 — authoritative exact completion dependency identity and positive reuse.
- [ ] P5-CB86 — complete final rail/curve and provenance propagation.
- [ ] P5-CB87 — correct invalid midpoint and cylinder simplification fixtures.
- [ ] P5-CB88 — repair remaining production output contracts.
- [ ] P5-CB89 — complete stage-owned memory telemetry and ownership bounds.
- [ ] P5-CB90 — regression sources and compile/package gate.
- [ ] P5-TB16 — artifact-only closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB15 test disposition

| Scope | Passed | Failed |
|---|---:|---:|
| Phase 14–18 | **230** | **0** |
| Patch descriptor Milestone E | 21 | 3 |
| P23 + Phase 20 | 52 | 2 |
| Milestone D | 6 | 1 |
| Full excluding crash tests | 579 | 10 |

Complete packaged disposition: **579/592 passed**, with 10 assertion failures and 3 signal-11 tests.

Newly closed:

- real permitted side-repair failure returns exact rollback;
- partial multi-edge interface fails closed through a valid fixture;
- complete multi-edge interface commits and preserves protected rails.

## Face-edge random-bunny result

Four independent processes terminate with identical structural diagnostics:

- wall: `17.594136–19.939944 s`;
- peak working set: `137,039,872–137,162,752 B`;
- trace segments: `12,130`;
- arrangement/simplified cells: `7,405 / 7,405`;
- simplification generations: `5`;
- peak live candidates: `747`;
- fallback/recovery: neither used.

All four fail before descriptor acceptance with:

```text
BoundaryParityRepair:MixedCellSourceScope
```

The parity transaction reduces odd cells `1,860 -> 0` but cannot commit because a rebuilt cell boundary lacks one exact scope shared by all oriented replacement pieces. Dominant-frequency scope selection is diagnostic, not authoritative.

## Generated-smooth-field crash isolation

The exact production manifest case and all three production-matrix tests still exit `139`.

- `smooth` without debug retention: crashes;
- `face_edges` with debug retention: returns normally;
- injected after tracing stage 3: returns normally with `80,862` trace segments and hash `f2fe5aaec178f507`;
- injected after strands stage 4: crashes.

The fault is inside FlowRep strands input/selection/endpoint completion on the high-cardinality smooth-field trace graph, not debug-result retention.

## Remaining source gates

- Replace parity scope frequency voting with canonical pre-transaction cell scope inheritance.
- Make FlowRep strands stable for high-cardinality trace graphs and both intermediate-retention modes.
- Produce positive exact completion reuse from canonical source dependencies.
- Preserve authoritative rail/curve identity to final arrangement halfedges.
- Split the missing-chart and invalid-midpoint tests into valid scenarios.
- Rebuild the cylinder fixture without duplicate coincident per-face arcs.
- Correct plane, cylinder, seam, torus, mechanical-feature, and Phase 20 cylinder output failures without weakening validation.
- Add stage-owned bytes for trace, FlowRep, arrangement, simplification, and completion.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB15_Parity_Scope_Reuse_Rail_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Parity_Scope_FlowRep_Reuse_Rail_Code_Build_Plan.md`
- `benchmark-results/p5-tb15-summary.json`
- `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Report.md`
- `benchmark-results/p5-cb82-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
