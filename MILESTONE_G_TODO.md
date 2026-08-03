# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — global ownership-frontier remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Tested source: `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`.
- Artifact: `8852049639` (`surface-cell-p5-cb58-memory-frontier-linux-release`).
- Digest: `sha256:aeab9fc7d38dc65a29fec04a5635d8d63cbef46d7c872dbc17e46b26f3aaa34e`.
- Artifact integrity: source status empty; checksums **36/36**; no rebuild.
- Completed turn: P5-TB12 artifact-only test and benchmark.
- Next turn: P5-CB59 through P5-CB66 code changes + compile-only build.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation.
- [x] P5-TB11 — complete inventory diagnosis; closure gates failed.
- [x] P5-CB51–P5-CB58 — budget batching, memory lifetime, fixture closure, compile-only artifact.
- [x] P5-TB12 — artifact validation completed; correctness/reliability gates failed.
- [ ] P5-CB59 — exact canonical side-repair rollback ownership.
- [ ] P5-CB60 — restore descriptors and typed fail-closed completion contracts.
- [ ] P5-CB61 — complete exact reusable-product semantics.
- [ ] P5-CB62 — isolate and eliminate GP26/GP27 matrix SIGSEGVs.
- [ ] P5-CB63 — restore Phase 20 provenance and Milestone D topology contracts.
- [ ] P5-CB64 — preserve memory reduction on successful completion path.
- [ ] P5-CB65 — add deterministic successful-path integration coverage.
- [ ] P5-CB66 — compile/package next checkpoint without executing binaries.
- [ ] P5-TB13 — artifact-only successful-path validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB12 evidence

Tests:

- focused memory/frontier/fixture: **8/11 passed**;
- `PatchDescriptorMilestoneE.*`: **15/21 passed**;
- Phase 14–18: **230/230 passed**;
- P23 + Phase 20: **51/54 passed**;
- authoritative non-overlapping P5 total: **296/305 passed**;
- Milestone D: **4/7 passed**;
- full packaged binary: **566/580 passed**, 12 assertions failed, 2 tests terminated with signal 11.

Crashing tests:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`;
- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`.

Four random-bunny processes were deterministic and remained below both formal resource caps:

- wall range: **32.390061–33.018193 s**;
- maximum peak working set: **158,949,376 B**;
- P5-TB11 maximum: **936,484,864 B**;
- measured reduction: **83.03%**.

Every process failed closed before descriptor completion:

```text
InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1
```

Descriptors/completed patches/output quads were `0/0/0`; no fallback or recovery occurred. The resource improvement is therefore early-failure evidence, not successful production-path evidence.

## Primary diagnosis

P5-CB58 moved the canonical parity-repaired complex into side repair. When side repair is allowed to fail and hand off to the general backend, the failure path now uses `sideRepair.complex` as rollback state instead of the previously retained authoritative `parityRepair.complex`.

The deterministic invalid domain identity and descriptor-empty regressions strongly indicate that a partially mutated side-repair candidate is escaping as the prepared complex. This must be corrected through an explicit transactional rollback contract without reintroducing two simultaneously retained full complexes.

Exact completion-product reuse remains zero in fixtures with unaffected products. Production result/context ownership also remains unsafe, as shown by the two matrix segmentation faults.

## P5-CB59–P5-CB66 gates

- Restore exact pre-transaction canonical topology on every rejected side-repair transaction.
- Preserve the memory discipline through undo logging, copy-on-write touched regions, or equivalent transactional ownership.
- Restore descriptors, typed semantic overlap, authoritative rails, paired-boundary proof, and Milestone D interface/topology behavior.
- Make exact unaffected completion products reusable and bounded.
- Make every production manifest case independently testable and remove all dangling result/context references.
- Preserve intermediate release and compact ownership state.
- Add successful-path owned-byte diagnostics and lifetime regressions.
- Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Execute no binary in the code/build turn.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB12_Memory_Frontier_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Plan.md`
- `benchmark-results/p5-tb12-summary.json`

P5 remains open. PR #8 remains draft and unmerged.
