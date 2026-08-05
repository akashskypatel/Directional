# Milestone G P5-R2E2 Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E2 authoritative boundary-exterior successor construction is implemented and compiles successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or produced binary was executed. Runtime acceptance remains open. The next turn is **P5-TB30 artifact-only R2E2 validation** using artifact `8916209271`.

Do not advance to intrinsic-fan R2F or R3 from compilation alone.

## Source and build authority

- starting documentation head: `eab14c9a26d2ebaedf16e359a03b983c90180275`;
- workflow event commit: `517735a53e4554d74cab14845cb8e26edb90de37`;
- exact compiled source: `f5305ade5bf5360df36b681d135e5299322f5fdb`;
- workflow cleanup commit: `2d2a04d34e077a910db36af1409c3114108918f1`;
- reviewed patch SHA-256: `526c01714d6d11ca8c4e60458b176f0057d386a6d163e406bb89fb04c86a83ec`;
- applied source diff SHA-256: `526c01714d6d11ca8c4e60458b176f0057d386a6d163e406bb89fb04c86a83ec`;
- successful run/job: `30969860018` / `92191640303`;
- job interval: `2026-08-05T02:36:57Z`–`2026-08-05T02:44:13Z`;
- compiled artifact: `8916209271`, `surface-cell-p5-r2e2-github-source-linux-release`;
- artifact SHA-256: `2117cc2b99bc82a197bb7ee94f3e21a9c8f71b48f735c15c878515dabd4915df`;
- workflow-log artifact: `8916209511`, `surface-cell-p5-r2e2-workflow-logs-30969860018`;
- workflow-log SHA-256: `45606d385ffacdfc621c85d21316dca31bfd84cdc0421d16b6f990b817b47007`;
- source status empty;
- recursive checksums **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

Target hashes:

- `directional_phase1_tests`: `2df7eb12d05b74d06c9d7f2a7ac64146379870e8191daf4c90ccf57fe4c8f856`;
- `directional_benchmarks`: `f6641fdcb1688bd722365acfdb46fdf550b1be28078003f446449bc82d3c7593`;
- `libdirectional_core.a`: `b5fccd454f40ee85a906798d973e13052dba2b1eb66b800ea88878b136194440`;
- `libdirectional_pipeline.a`: `3afc9b2458a08d85e85fa0bfb8860d38770c7fda6a201545ba32225d9aab7e50`.

## Implemented R2E2 behavior

1. `SourceBoundaryTopology` now retains deterministic ordered source-boundary loops instead of unordered edge membership only.
2. Every loop records ordered source vertices and edges, operational face-oriented direction, incident source faces/edges, and a canonical orientation-insensitive identity.
3. Boundary arrangement subsegments are inventoried from exact source provenance and edge parameters.
4. Exterior and interior directed coverage are independently audited for complete gap-free, overlap-free source-edge intervals.
5. New typed fail-closed evidence covers `BoundaryCoverageGap`, `BoundaryCoverageOverlap`, and `BoundaryContinuationDiscontinuity`.
6. Exterior boundary-halfedge `next` pointers are installed from authoritative source-loop order before full orbit extraction.
7. Exterior continuation crosses source-boundary vertices independently of interior hard-rail wedges.
8. Interior-side and non-boundary halfedges retain intrinsic directed-wedge successors.
9. Predecessor multiplicity is recomputed from the final mixed authoritative/intrinsic successor relation before the single complete permutation audit.
10. Authoritative exterior adjacency participates in deterministic incidence hashing using canonical loop and subsegment identities.
11. Existing R2E owner-count and structural Euler logic remains downstream of valid orbit publication.
12. Focused planar, interior-hard-rail, and open-cylinder contracts were strengthened to require endpoint-continuous exterior cycles, successor/cell consistency, and complete halfedge ownership. They compiled but were not executed.

This is a pre-audit successor construction. It does not merge, split, or decompose cells after orbit extraction.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

The implementation contains **598 insertions and 63 deletions** across these four source/test files. No FlowRep, simplification, completion, optimizer, cache, lineage, or memory subsystem was changed.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Configure and compilation completed successfully with Ninja on Ubuntu 24.04 and GCC 13.3.

A local artifact-source preflight could not configure because Git archives do not contain initialized submodule worktrees. The authoritative workflow initialized and verified all nine recursive submodules before compiling. This was an environment limitation, not a source compile failure.

## Artifact source authority

The artifact contains two source snapshots:

- `source/exact-source.tar.gz` is the exact compiled commit and includes the bounded active workflow plus the base workflow;
- `source/source.tar.gz` excludes only `.github/workflows/agent-build-p5-r2e2.yml`, contains only `agent-source-snapshot.yml`, and contains zero temporary payloads.

`source-exclusions.txt` records that single transparent exclusion. After the build completed, the connector removed the active workflow from the branch. The final branch contains only the base workflow and no patch payload directory.

The recursive manifest was generated outside the package, excludes itself from its input set, and passed all **48/48** entries both before upload and after download.

## Next turn

Run **P5-TB30 artifact-only R2E2 validation** against artifact `8916209271`. Follow `.agents/Directional/Milestone_G_P5_R2E2_Test_Benchmark_Plan.md`.

Preserve all prohibitions: no validator weakening, frequency/count/order ownership selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
