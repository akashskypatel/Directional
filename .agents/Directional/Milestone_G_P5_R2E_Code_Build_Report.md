# Milestone G P5-R2E Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E source-boundary side ownership and structural Euler topology changes are implemented and compile successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or generated binary was executed. Runtime acceptance remains open. The next turn is **P5-TB29 artifact-only R2E validation** using artifact `8914900872`.

Do not advance to R3 from compilation alone.

## Source and build authority

- P5-TB28 tested source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`;
- implementation commit: `f5afd014cced8205d485bea4f1470725e1fd8be1`;
- corrected workflow event commit: `2a40add65b13137d4d7183e0715c6807dbd6a10a`;
- exact compiled/package source: `de0aa1a58a5861954dc9e14e731e681b5e5feb87`;
- reviewed patch SHA-256: `3ca1d3b940989e1fbda9e0f8f4b0b8c5971643575550ff9e34501e219651d628`;
- applied implementation diff SHA-256: `abf671a365ab97ba3075962528bcf76b71901f6dc06a7d0b877499561c89814e`;
- successful authoritative run/job: `30966134727` / `92180382387`;
- job interval: `2026-08-05T01:21:18Z`–`2026-08-05T01:28:33Z`;
- compiled artifact: `8914900872`, `surface-cell-p5-r2e-corrected-github-source-linux-release`;
- artifact SHA-256: `418518d879ec8686296ed3dd30d24e3b9e3b9df4280278996292fa1eba4d1d1c`;
- workflow-log artifact: `8914901042`, `surface-cell-p5-r2e-package-fix-workflow-logs-30966134727`;
- workflow-log SHA-256: `351462cc5e3c72440fd2933bb31e3c2c63ee8560b61af20b9de8361a6713e0a3`;
- source status empty;
- recursive checksums **45/45**;
- package files **46** including the manifest;
- fixtures **26**;
- recursive submodules **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

The source archive contains only `.github/workflows/agent-source-snapshot.yml` and no agent patch payloads.

## Packaging correction

The first compile run `30965657962` built the same implementation successfully, but artifact `8914740347` was rejected as authority because its recursive manifest included `files.sha256` while that file was being written. Verification produced **43 valid entries and one self-check mismatch**.

The corrected workflow generated the manifest outside the package, included `built-targets.sha256`, excluded only `files.sha256`, moved the finished manifest into the package, and verified all **45/45** listed files before upload. No implementation behavior changed during this correction.

## Implemented R2E behavior

1. Builds canonical source boundary loops from exact boundary-edge connectivity.
2. Records exact oriented source-side witnesses on audited successor orbits: `-1` exterior, `+1` interior, `0` no boundary witness.
3. Fails closed with typed `ContradictoryBoundarySide` evidence when one orbit contains incompatible witnesses.
4. Requires exactly one exterior arrangement owner per canonical source boundary loop; zero or multiple owners fail with `BoundaryLoopOwnerCount`.
5. Prevents an interior hard rail from manufacturing an exterior source-boundary owner.
6. Computes global arrangement Euler by summing structural Euler contributions from bounded area-bearing cells, excluding exterior and support-only ownership.
7. Propagates boundary-loop identity and side evidence through arrangement hashes, simplification, feasibility repair, descriptors, rollback identity, memory accounting, and pipeline hashes.
8. Preserves transactional complete halfedge-to-cell ownership or clears the pending publication fail-closed.
9. Strengthens focused planar, orientation-reversal, hard-rail, and open-cylinder contracts. They were compiled but not executed.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/PatchDescriptor.cpp`;
- `src/geometry/SurfaceArrangement.cpp`;
- `src/geometry/SurfaceCellFeasibilityRepair.cpp`;
- `src/geometry/SurfaceComplexSimplification.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/MilestoneDClosureTests.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`.

The implementation patch contains 425 insertions and 81 deletions across these eight files.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Compile success establishes integration and package authority only.

## Mandatory working-branch hygiene

At the start and end of every Code + Build turn:

- compare temporary agent resources against the base branch and current turn;
- remove every superseded workflow, trigger marker, patch fragment, patch README, transfer file, and generated build artifact;
- retain only base workflows plus one active bounded workflow/payload while a remote build is running;
- self-remove the active workflow/payload from the exact compiled source or remove it immediately in the handoff commit;
- verify the final branch and packaged source contain no stale temporary artifacts;
- never leave historical workflow YAML on the working branch.

P5-R2E ends with only `.github/workflows/agent-source-snapshot.yml` and zero patch payloads.

## Next turn

Run **P5-TB29 artifact-only R2E validation** against artifact `8914900872`. Follow `.agents/Directional/Milestone_G_P5_R2E_Test_Benchmark_Plan.md`.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.
