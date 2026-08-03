# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB12 tested artifact `8852049639` directly without rebuilding. P5 remains open.

- Exact source: `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`.
- Digest: `sha256:aeab9fc7d38dc65a29fec04a5635d8d63cbef46d7c872dbc17e46b26f3aaa34e`.
- Source status empty; checksums **36/36**.
- Authoritative P5 tests: **296/305 passed**.
- Full packaged binary: **566/580 passed**, with 12 assertion failures and 2 deterministic SIGSEGVs.
- Four random-bunny processes failed closed before descriptors.
- Wall range: **32.390061–33.018193 s**.
- Maximum peak working set: **158,949,376 B**, an **83.03%** reduction from P5-TB11's `936,484,864 B`.
- Next turn: **P5-CB59 through P5-CB66 code changes + compile-only build**.

The measured memory reduction is not successful-path evidence because every production process terminated at completion with zero descriptors and zero output quads.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB12_Memory_Frontier_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Plan.md`
5. `benchmark-results/p5-tb12-summary.json`
6. `.agents/Directional/Milestone_G_P5_Memory_Bounded_Frontier_Code_Build_Report.md`
7. `benchmark-results/p5-cb58-summary.json`

## Primary production blocker

All four authoritative random-bunny processes fail identically:

```text
InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1
```

P5-CB58 changed completion ownership so the canonical parity-repaired complex is moved into side repair. On a permitted side-repair failure, the path now uses `sideRepair.complex` as rollback state. Previously it retained `parityRepair.complex` and never exposed an uncommitted side-repair trial.

The exact source diff, descriptor-empty regressions, and deterministic domain failure strongly indicate that a partially mutated side-repair candidate is escaping as the prepared complex. Treat this as the leading diagnosis to verify and correct, not as a completed proof.

Two additional blockers remain:

- exact product reuse is still zero in fixtures with unaffected completion products;
- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` and `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` each terminate with signal 11 when run alone.

## Required next turn

Implement P5-CB59 through P5-CB66 from the rollback-integrity plan.

Priorities:

1. Give side repair an explicit exact rollback transaction contract without retaining two simultaneous full complexes.
2. Restore valid arrangement-domain identity and descriptor production.
3. Complete exact dependency-based reuse for genuinely unaffected patches.
4. Isolate every production manifest case and eliminate moved-from/dangling result or context lifetime errors causing the two SIGSEGVs.
5. Restore typed semantic overlap, authoritative rail/paired-boundary proof, and Milestone D interface/topology behavior.
6. Preserve the memory-lifetime improvements and extend owned-byte diagnostics to the successful completion path.

Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. Run no test, benchmark, custom mesh, compiled binary, help/list command, or test discovery.

Preserve all prohibitions: no final-face deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, arbitrary subset search, or production ID special case.

Workflow files under `.github/workflows` must be changed directly through the GitHub connector, never through a patch-applicator workflow.
