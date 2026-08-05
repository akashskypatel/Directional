# Milestone G P5-R2E5 Code/Build Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E5 explicit degree-two boundary rotational-sector construction is implemented and compiles successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or produced binary was executed. Runtime acceptance remains open. The next turn is **P5-TB33 artifact-only R2E5 validation** using artifact `8934315316`.

Do not advance to intrinsic-fan R2F or R3 from compilation alone.

## Source and build authority

- starting documentation head: `e8f6c3f1641db916c53fc9dc938d0bc5d648a019`;
- workflow event commit: `15704d30fc478858284df89d372fa713f2d88576`;
- exact compiled source: `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`;
- workflow cleanup commit: `790714bbe8dffd1efbe7860093027daf3e0e8d54`;
- reviewed patch SHA-256: `b7648b0bf870d7a65a7715a11e58cc2e8258af0118826c843d013384d485cc29`;
- applied source diff SHA-256: `b7648b0bf870d7a65a7715a11e58cc2e8258af0118826c843d013384d485cc29`;
- successful run/job: `31014985061` / `92336594420`;
- job interval: `2026-08-05T14:23:58Z`–`2026-08-05T14:31:22Z`;
- compiled artifact: `8934315316`, `surface-cell-p5-r2e5-github-source-linux-release`;
- artifact SHA-256: `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`;
- workflow-log artifact: `8934315771`, `surface-cell-p5-r2e5-workflow-logs-31014985061`;
- workflow-log SHA-256: `3681d6b81d1251f3de17a5e004ddce42d3b204d636481ded4a390754ae4ebf34`;
- source status empty;
- recursive checksums **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

Target hashes:

- `directional_phase1_tests`: `1bb95bed355ce1b18e0fa69f68af5e3096ffba5bd64cb2e8f87bc3143f30da2b`;
- `directional_benchmarks`: `39999e0e3f9d630618989719be85def412213f5fa12103ab5979d4b5571eee1a`;
- `libdirectional_core.a`: `168286fca64a16426507f2e382e779e2980ead39adc9080c13eddb75772d3a02`;
- `libdirectional_pipeline.a`: `5bd64435747b7861262ec5c91217484eb6759bc1b3b022a6efb7637c3c630362`.

## Implemented R2E5 behavior

1. Detects the genuine rotational degeneracy only when the canonical boundary-node ray inventory has exactly two outgoing rays.
2. Requires that inventory to be exactly the authoritative exterior outgoing and the outgoing twin of the authoritative exterior incoming.
3. Derives the complementary incoming as the twin of the authoritative exterior outgoing.
4. Requires distinct incoming halfedges, endpoint continuity, valid twins, and exactly one use of each local outgoing target.
5. Constructs the complete two-sector permutation directly:
   - `exteriorIncoming -> exteriorOutgoing` for the authoritative exterior sector;
   - `twin(exteriorOutgoing) -> exteriorTwin` for the complementary source-interior sector.
6. Assigns the canonical source-entity rotation identity to the complementary interior successor and preserves the authoritative loop identity override only for the exterior successor.
7. Retains the R2E4 canonical adjacent-ray rotational branch unchanged for three or more rays.
8. Retains typed `BoundaryRotationalSystemConflict` rejection for incomplete, contradictory, invalid-twin, endpoint-discontinuous, or non-bijective evidence.
9. Adds the derived `boundaryDegreeTwoRotationalNodeCount` diagnostic only after the complete local two-sector cardinality audit succeeds.
10. Leaves canonical aliases, ordered source-boundary loops, paired boundary identity, repeated-edge/node, disk, ownership, and Euler validators unchanged.
11. Adds a boundary-only triangle contract that requires one exterior disk, one bounded disk, and the exact complementary two-sector mapping.
12. Strengthens planar, hard-rail, cylinder, and higher-valence contracts without weakening their topology requirements.

This is direct producer-level sector construction. It is not a target repair, validator exception, post-hoc cycle decomposition, or cell merge.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

The coherent source/test patch contains **192 insertions and 53 deletions**. No FlowRep, tracing semantics, simplification, completion, optimizer, cache, lineage, fallback/recovery, memory accounting, or bunny intrinsic-fan subsystem was changed.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Configure and compilation completed successfully with Ninja on Ubuntu 24.04 and GCC 13.3. The authoritative workflow initialized and verified all nine recursive submodules before compiling the four required targets.

## Artifact source authority

The artifact contains two source snapshots:

- `source/exact-source.tar.gz` is the exact compiled commit and includes the bounded active workflow plus the base workflow;
- `source/source.tar.gz` excludes only `.github/workflows/agent-build-p5-r2e5.yml`, contains only `agent-source-snapshot.yml`, and contains zero temporary payloads.

`source-exclusions.txt` records that single transparent exclusion. After artifact upload, the bounded workflow was removed from the branch. The implementation commit had already removed both patch transport files.

The recursive manifest was generated outside the package, excludes itself from its input set, and passed all **48/48** entries before upload and after download.

## Next turn

Run **P5-TB33 artifact-only R2E5 validation** against artifact `8934315316`. Follow `.agents/Directional/Milestone_G_P5_R2E5_Test_Benchmark_Plan.md`.

First require restoration of every P5-TB32 regression. Then evaluate whether planar, hard-rail, cylinder, high-valence rotation, ownership, and direct analytic inventories improve naturally. Do not advance to R2F or R3 until runtime evidence closes the required gates.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
