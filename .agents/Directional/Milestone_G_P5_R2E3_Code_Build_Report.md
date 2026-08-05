# Milestone G P5-R2E3 Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E3 boundary-node permutation splicing and orientation-invariant boundary incidence identity are implemented and compile successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or produced binary was executed. Runtime acceptance remains open. The next turn is **P5-TB31 artifact-only R2E3 validation** using artifact `8918054686`.

Do not advance to intrinsic-fan R2F or R3 from compilation alone.

## Source and build authority

- starting documentation head: `31b17ff6abb4965e5d506c35b38ca772d7591a5b`;
- workflow event commit: `2d1d616eaf6e5be025e1a190b995172954d3f102`;
- exact compiled source: `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`;
- workflow cleanup commit: `3d805eca6f1dfbc857c023a6f509d9310e9577dc`;
- reviewed patch SHA-256: `f7a26c3b3869a59247532e86f4468e0d17bce7caa72cf31a5c315b620fac1ff3`;
- applied source diff SHA-256: `f7a26c3b3869a59247532e86f4468e0d17bce7caa72cf31a5c315b620fac1ff3`;
- successful run/job: `30975049986` / `92207228399`;
- job interval: `2026-08-05T04:24:38Z`–`2026-08-05T04:32:03Z`;
- compiled artifact: `8918054686`, `surface-cell-p5-r2e3-github-source-linux-release`;
- artifact SHA-256: `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`;
- workflow-log artifact: `8918054984`, `surface-cell-p5-r2e3-workflow-logs-30975049986`;
- workflow-log SHA-256: `01578b07c754dd3eef0fc1aa63272b4fe5934565ddf0e48647ed3bf50aff7007`;
- source status empty;
- recursive checksums **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

Target hashes:

- `directional_phase1_tests`: `c36b29c9e7c40e283d20226ac2af591f6748a8281c0d7d2512058f11bf878813`;
- `directional_benchmarks`: `3f588d924c1cd6780057344d117373836c12c52a71d0ad4d25dc77663942d8f7`;
- `libdirectional_core.a`: `493ae6271e26289f36a0ff1e9466512d641bf5f3c08b9b02595326bc0998fe88`;
- `libdirectional_pipeline.a`: `3afc9b2458a08d85e85fa0bfb8860d38770c7fda6a201545ba32225d9aab7e50`.

## Implemented R2E3 behavior

1. Successor construction now uses a separate transactional `candidateNext` map; committed halfedge successors remain untouched until all local and global audits pass.
2. Manifold source-boundary vertices receive canonical boundary classes keyed by source vertex, authoritative loop, component, and the existing R1 source-vertex fan scope.
3. Hard-rail endpoint chart clones within the same manifold boundary fan collapse to one arrangement node, while pinched fans, close sheets, and distinct components retain separate classes.
4. Incompatible boundary aliases fail closed with typed `BoundaryAliasConflict` evidence.
5. Boundary subsegment orientation and intervals are derived from canonical source-edge parameters rather than directed provenance sign.
6. At each affected boundary node, exterior continuation and its complementary source-interior mapping are spliced together as one local bijection.
7. The displaced intrinsic incoming ray receives the superseded exterior target; this preserves every incoming domain and outgoing target exactly once instead of overwriting one successor in isolation.
8. Node-local endpoint, cardinality, duplicate-target, and predecessor audits fail closed with typed `BoundaryLocalPermutationConflict` evidence.
9. The complete candidate permutation receives one global endpoint/predecessor audit before successors are committed and orbit extraction begins.
10. Both directed twins of an authoritative boundary subsegment are represented by one canonical boundary-incidence identity for orientation-invariant hashing.
11. Non-boundary incidence retains the existing canonical directed hash path.
12. Focused planar, hard-rail, cylinder, orientation-reversal, and node-local bijection contracts were strengthened. They compiled but were not executed.

This is a producer-level node-local permutation construction. It does not merge, split, or decompose cells after orbit extraction.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

The coherent source/test patch contains **518 insertions and 106 deletions**. No FlowRep, simplification, completion, optimizer, cache, lineage, fallback, or memory subsystem was changed.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Configure and compilation completed successfully with Ninja on Ubuntu 24.04 and GCC 13.3.

A local syntax-only preflight compiled the modified production translation unit and focused Phase 16 test translation unit without linking or execution. The authoritative workflow initialized and verified all nine recursive submodules before compiling the four required targets.

## Artifact source authority

The artifact contains two source snapshots:

- `source/exact-source.tar.gz` is the exact compiled commit and includes the bounded active workflow plus the base workflow;
- `source/source.tar.gz` excludes only `.github/workflows/agent-build-p5-r2e3.yml`, contains only `agent-source-snapshot.yml`, and contains zero temporary payloads.

`source-exclusions.txt` records that single transparent exclusion. After artifact upload, the connector removed the active workflow from the branch. The implementation commit had already removed both patch transport files.

The recursive manifest was generated outside the package, excludes itself from its input set, and passed all **48/48** entries both before upload and after download.

## Next turn

Run **P5-TB31 artifact-only R2E3 validation** against artifact `8918054686`. Follow `.agents/Directional/Milestone_G_P5_R2E3_Test_Benchmark_Plan.md`.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
