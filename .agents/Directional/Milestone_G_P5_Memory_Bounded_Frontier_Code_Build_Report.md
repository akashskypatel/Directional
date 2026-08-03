# Milestone G P5 — Memory-Bounded Global Frontier Code + Build Report

**Turn:** P5-CB51 through P5-CB58 code changes + compile-only build  
**Review policy:** `never`  
**Runtime status:** unverified; P5 remains open

## Exact checkpoint

- Main implementation commit: `9ed03260df430eb856bd9a3edf1587402ddfc16a`.
- Portable regression manifest commit: `cdf842bcb03d70fecf047bfa848ef9444a9446ba`.
- Random-bunny regression correction commit: `145aaf1d2d6148819501fa6a52bfeb76612428f6`.
- Exact compiled source: `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`.
- Compile-only run / job: `30803697079` / `91654036551` — **success**.
- Artifact: `8852049639` (`surface-cell-p5-cb58-memory-frontier-linux-release`).
- Artifact digest: `sha256:aeab9fc7d38dc65a29fec04a5635d8d63cbef46d7c872dbc17e46b26f3aaa34e`.
- Build: **131/131 steps completed**.
- Source status: empty.
- Packaged checksums: **36/36 verified** after normalizing the archive-time `artifact/` prefix.
- Packaged benchmark fixture files: **26**.
- Tests, benchmarks, custom meshes, help/list commands, and test discovery executed: **none**.

The first compile attempt, run `30802753565`, compiled all 131 steps but failed its packaging gate because the historical `repo_regressions.json` fixture was not tracked. The corrected source adds a portable manifest for the authoritative `bunny_1k_random.obj` input and recompiles from a clean checkpoint.

## Why a 49 KB input previously used about 936 MB

The source asset size is not representative of the working topology. The P5-TB11 production process expanded the 1,000-face OBJ into approximately 80,862 trace segments, 21,298 arrangement cells, 21,297 attempted completion patches, and 2,729 parity splits. The prior path simultaneously retained and copied several of those expanded representations while repeatedly assembling variants.

This turn therefore targets retained expanded state and transaction copying rather than the input file bytes. Actual process RSS reduction is not claimed until P5-TB12 measures the packaged artifact.

## Implemented scope

### Memory and lifetime discipline

- Added production-default `retainIntermediateGeometry = false`; test/debug/injection paths opt in explicitly.
- Released trace, FlowRep, arrangement, simplification, and completion intermediates as soon as downstream stages consumed them.
- Moved complexes, arcs, retained IDs, completion products, and the final mesh through stage boundaries instead of preserving duplicate full payloads.
- Preserved one canonical rollback complex and at most one mutable candidate rather than eagerly cloning complete results.
- Deferred assembled output mesh, provenance, and lineage construction until exact ownership conflicts reach zero.
- Replaced heavyweight per-face ownership storage with a compact registry and materialized exact cycles/owner detail only for actual conflicts.
- Added estimated ownership-registry, deferred-output, and workspace-owned byte diagnostics for P5-TB12 attribution.

### Global ownership progress and wall-time path

- Partitioned the exact frontier before work-budget charging; one atomic independent batch counts as one transaction rather than one charge per exact claim.
- Built deterministic completion-template conflict components and applied compatible independent patch changes in a single assembly transaction.
- Committed only successful or strict-reduction transactions with zero introduced exact claims.
- Corrected exact completion-product reuse to ignore allocation-local numbering while preserving semantic support dependencies.
- Recomputed rollback variants when needed instead of retaining duplicate full meshes.
- Propagated template-component, changed-patch, transaction, reuse, and assembly-pass counters through diagnostics and benchmark JSON.

### Fail-closed and regression contracts

- Kept conflict outputs empty rather than retaining partial meshes.
- Preserved exact typed ownership and first-conflict details while bounding verbose payloads.
- Restored required result/diagnostic contracts and added compile-only regression sources for batching, budgets, reuse, ownership memory accounting, intermediate release, and fixture portability.
- Added a portable `repo_regressions.json` case for `bunny_1k_random.obj` using the supported generated `face_edges` cross field.
- Updated the stale regression that still expected the replaced 2,090-face `bunny1k.obj`; it now verifies the authoritative 1,000-face random triangulation and a real generated degree-four field.
- Packaged the complete tracked benchmark fixture directory relative to the executables.

No fallback, source-grid recovery, final-face deduplication, positional merge, source-triangle pairing, arbitrary subset search, validator weakening, or production ID special case was introduced.

## Compile and artifact evidence

The clean optimized static build linked only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

The artifact contains both ELF executables, both static libraries, the complete tracked benchmark fixture closure, exact source archive, empty source-status record, recursive submodule revisions, configure/build logs, and checksum manifest. The source archive contains the final compile-only workflow and contains no source-materializer workflow or transfer payload.

Artifact inspection did not execute either binary. File-type inspection identified the two expected x86-64 ELF executables and two `ar` archives. The packaged random bunny contains exactly 1,000 faces.

## Disposition

Compilation establishes source validity and package completeness only. It does not establish runtime correctness, zero-conflict completion, output quality, wall-time compliance, or actual RSS reduction.

The next authoritative turn is **P5-TB12 artifact-only test and benchmark** using artifact `8852049639` without rebuilding. It must measure peak RSS directly, compare it with the P5-TB11 maximum of `936,484,864 B`, and apply the existing correctness, determinism, wall-time, and memory gates.

PR #8 remains open, draft, and unmerged.
