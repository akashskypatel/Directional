# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Tested source: `188baf35a13c02b20424cd72fb9c6d8fe81ec9fc`.
- Artifact: `8864496877` (`surface-cell-p5-cb74-successful-identity-linux-release`).
- Digest: `sha256:5629045697a3819f3caeb9416d0d4bbe941d6981d6e226420c5899062378a088`.
- Artifact integrity: source status empty; checksums **36/36**; no rebuild.
- Completed turn: P5-TB14 artifact-only test and benchmark.
- Next turn: P5-CB75 through P5-CB82 code changes + compile-only build.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation.
- [x] P5-TB11 — complete inventory diagnosis; closure gates failed.
- [x] P5-CB51–P5-CB58 — budget batching, memory lifetime, fixture closure, compile-only artifact.
- [x] P5-TB12 — rollback/result/lifetime diagnosis.
- [x] P5-CB59–P5-CB66 — rollback-integrity implementation and compile-only artifact.
- [x] P5-TB13 — successful-transaction identity, reuse, rail, simplification, lifetime, and wall diagnosis.
- [x] P5-CB67–P5-CB74 — successful-subdivision audit, semantic index, fixed-point API, fixture, rail, and lifetime source changes.
- [x] P5-TB14 — artifact validation; mixed-sheet, rollback, reuse, rail, fixture, liveness, crash, output, and wall gates failed.
- [ ] P5-CB75 — preserve exact sheet identity through successful subdivision.
- [ ] P5-CB76 — make side-repair rollback proof structurally exact.
- [ ] P5-CB77 — produce positive exact semantic reusable-product hits.
- [ ] P5-CB78 — finish authoritative rail propagation to final halfedges.
- [ ] P5-CB79 — rebuild valid Milestone D and failing production fixtures.
- [ ] P5-CB80 — make simplification fixed-point live and deterministic.
- [ ] P5-CB81 — eliminate the in-pipeline bunny signal 11.
- [ ] P5-CB82 — memory discipline and compile/package gate.
- [ ] P5-TB15 — artifact-only closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB14 evidence

Tests:

- focused subset: **3/10 passed**;
- `PatchDescriptorMilestoneE.*`: **20/24 passed**;
- Phase 14–18: **230/230 passed**;
- P23 + Phase 20: **52/54 passed**;
- Milestone D: **4/7 passed**;
- full binary excluding the three known crash tests: **576/589 passed**;
- complete packaged disposition: **576/592 passed**, with 13 assertion failures and 3 signal-11 tests.

The three signal-11 tests still stop before pipeline return on `bunny_1k_random__surface_cells`:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`;
- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`;
- parameterized GP27 lifetime case `/7`.

Four independent random-bunny processes fail liveness and determinism:

| Run | Role | Observation | Result |
|---|---|---:|---|
| 1 | Formal | `>300 s` | no termination / no JSON |
| 2 | Formal | `40.925049 s` | failed closed |
| 3 | Supplementary | `>120 s` | no termination / no JSON |
| 4 | Supplementary | `>120 s` | no termination / no JSON |

The completed process fails with:

```text
SuccessfulSubdivisionDomainIdentity;
identityFailure=mixed-source-sheet;
cell=19;
halfedge=52893;
node=-1;
sourceFace=794;
component=0;
sheet=9
```

State:

- trace segments: `12,130`;
- arrangement/simplified cells: `7,405/7,405`;
- odd cells: `1,860 -> 0`;
- side infeasible cells: `918 -> 0`;
- side inserted vertices: `8,074`;
- descriptors/completed patches: `0/0`;
- exact reused/recomputed completions: `0/0`;
- peak working set: `184,205,312 B`;
- fallback/recovery: neither used.

The completed process exceeds the `39.228299 s` wall gate by `1.696750 s`. Simplification consumes `30.632781 s`. The memory cap is passed only on this early-failure process; successful-path memory remains unmeasured.

## Primary diagnosis

- The typed audit works, but successful subdivision still mixes source-sheet identity on an oriented boundary.
- The restored default simplification refresh passes local Phase 17 tests but is not live or deterministic on production input.
- All crash markers stop before pipeline return; the fault is internal to simplification/completion, not result destruction.
- The production rollback regression claims equivalence despite a different structural hash.
- Semantic product indexing exists but still produces zero exact reuse.
- Rail identity still disappears between embedded arcs and final arrangement halfedges.
- The attempted Milestone D fixtures remain invalid before their intended scenarios.
- Four GP26 end-to-end fixtures and the Phase 20 cylinder now fail production output contracts.

## P5-CB75–P5-CB82 gates

- Every committed subdivision preserves one exact component/sheet identity per oriented halfedge and cell.
- Real side-repair failure returns a bit-exact committed complex before any downstream handoff.
- Unaffected completion products report positive exact reuse; affected products recompute exactly once.
- Final arrangement halfedges retain rail/curve parameters, classification, component/sheet, and complete provenance.
- Milestone D fixtures pass explicit DCEL/topology preconditions before testing production behavior.
- Simplification candidate generations converge deterministically with duplicate suppression and stale invalidation.
- All former bunny signal-11 cases return normally and own all diagnostics.
- Preserve one committed complex, one mutable transaction, compact undo state, bounded candidates/products, and deferred output.
- Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Execute no binary in the code/build turn.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB14_Successful_Subdivision_Identity_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Plan.md`
- `benchmark-results/p5-tb14-summary.json`
- `.agents/Directional/Milestone_G_P5_Successful_Subdivision_Identity_Code_Build_Report.md`

P5 remains open. PR #8 remains draft and unmerged.
