# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Last tested source: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Current implementation source:
  `34edce9e508fd81e28bbd6b68a064a2a57bacf03`.
- Completed turn: P5-CB91 through P5-CB98 code changes + compile-only build.
- Next turn: P5-TB17 artifact-only test and benchmark.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB82 — earlier global-frontier, rollback, scoped identity,
      liveness, rail, fixture, and memory implementation turns.
- [x] P5-TB11–P5-TB15 — earlier runtime diagnosis turns.
- [x] P5-CB83–P5-CB90 — FlowRep lifetime, parity scope, reuse, rail, fixture,
      output, memory, and compile artifact.
- [x] P5-TB16 — 583/593; all prior signal-11 cases terminate; remaining parity,
      reuse, fixture, output, and memory gates identified.
- [x] P5-CB91 — authoritative pre-transaction parity scope and typed failure.
- [x] P5-CB92 — exact dependency identity, transactional rebind, reuse evidence.
- [x] P5-CB93 — intended invalid-midpoint fixture and exact rollback contract.
- [x] P5-CB94 — canonical open-cylinder DCEL fixture and topology assertions.
- [x] P5-CB95 — producer/output ownership and first-invalid diagnostics.
- [x] P5-CB96 — complete stage-owned memory accounting and timeline.
- [x] P5-CB97 — regression sources.
- [x] P5-CB98 — compile-only build/package gate.
- [ ] P5-TB17 — artifact-only closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB16 runtime baseline

| Scope | Passed | Failed |
|---|---:|---:|
| Phase 14–18 | **230** | **0** |
| Patch descriptor Milestone E | 22 | 3 |
| P23 + Phase 20 | 53 | 1 |
| Milestone D | 6 | 1 |
| Complete suite | **583** | **10** |

The complete suite had zero signal-11 terminations. The former crash cases all
terminated normally; one P27 matrix case still failed assertions.

Remaining failures at that checkpoint:

1. GP26 plane/mechanical output;
2. GP26 cylinder output;
3. GP26 multi-face seam output;
4. GP26 torus output;
5. GP27 supported-disposition matrix;
6. Milestone D cylinder simplification;
7. whole-complex parallel route repair;
8. exact one-candidate budget/reuse;
9. intended invalid-midpoint rollback;
10. Phase 20 cylinder output.

## Random-bunny baseline

Eight independent benchmark processes terminate deterministically and remain
inside the wall and memory limits.

Face-edge:

- wall `17.475780–19.086715 s`;
- max working set `138,072,064 B`;
- trace segments `12,130`;
- arrangement/simplified cells `7,405 / 7,405`.

Smooth field:

- wall `23.280920–24.560557 s`;
- max working set `283,557,888 B`;
- trace segments `80,862`;
- arrangement/simplified cells `21,298 / 21,298`.

Both paths fail before descriptor acceptance at:

```text
NotProductionReady/completion
BoundaryParityRepair:MixedCellSourceScope
```

They use neither fallback nor source-grid recovery and emit no output. Memory
telemetry is deterministic and populated, but explains only 32.65–47.28% of
peak RSS depending on logical/current versus summed stage peaks.

## P5-CB91–P5-CB98 implementation disposition

- Exact source scope is persisted on cells and validated before mutation.
- Replacement halfedges, twins, occurrences, and provenance are scope-stamped
  before validation; failure evidence is typed.
- Completion cache identity uses authoritative source dependencies and reports a
  field-level mismatch vector.
- Cached products are rebound and revalidated transactionally; counters are
  based on actual reuse.
- Missing-chart and invalid-midpoint scenarios are separate.
- Cylinder crossing entities are canonical and topology is asserted before
  candidate extraction.
- Output source charts come from vertex provenance; invalid optimized output
  rolls back to completed surface-cell output.
- First-invalid producer diagnostics identify stage/entity.
- Memory telemetry now includes logical bytes, retained capacity, stage peak,
  simultaneous ownership, and acquire/release events.
- Benchmark JSON serializes the new evidence.
- All four required targets compile and link; no runtime binary was executed.

## P5-TB17 closure gates

- All ten prior assertion failures pass for the intended reason.
- Both guaranteed reuse scenarios report `reused > 0`.
- Invalid midpoint is reached after valid common-chart setup and rollback is
  bit-exact.
- Cylinder topology and production output pass.
- Plane, seam, torus, mechanical-feature, and Phase 20 output pass.
- Four face-edge and four smooth-field runs are deterministic and return valid
  nonempty pure-quad surface-cell output without fallback/recovery.
- Stage-owned memory telemetry is internally consistent and reconciles the
  dominant peak RSS ownership.
- Complete suite has no unexpected failure or abnormal termination.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb16-summary.json`
- `.agents/Directional/Milestone_G_P5_CB91_CB98_Parity_Reuse_Fixture_Output_Memory_Code_Build_Report.md`
- `benchmark-results/p5-cb98-summary.json`
- `.agents/Directional/Milestone_G_P5_Post_CB98_Artifact_Test_Benchmark_Plan.md`

P5 remains open. PR #8 remains draft and unmerged.
