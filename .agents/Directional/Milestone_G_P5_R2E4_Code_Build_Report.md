# Milestone G P5-R2E4 Code/Build Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E4 authoritative boundary-node rotational-system construction is implemented and compiles successfully.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or produced binary was executed. Runtime acceptance remains open. The next turn is **P5-TB32 artifact-only R2E4 validation** using artifact `8929111021`.

Do not advance to intrinsic-fan R2F or R3 from compilation alone.

## Source and build authority

- starting documentation head: `fbec81c04d8134da81482e347389a5fde085feaf`;
- workflow event commit: `d81351aeb6bb7b728ceaf5bf468f924383167eb9`;
- exact compiled source: `ec44ab7570f258f800a27086fca053c573878a13`;
- workflow cleanup commit: `d59ddc2c72459287e4c3af5f6a6939443aae6f12`;
- reviewed patch SHA-256: `33ee4e40c7e5146abd732796b771d74ed28b7808bae6b0ed14bd327fd902aa01`;
- applied source diff SHA-256: `33ee4e40c7e5146abd732796b771d74ed28b7808bae6b0ed14bd327fd902aa01`;
- successful run/job: `31002566593` / `92294705089`;
- job interval: `2026-08-05T11:42:59Z`–`2026-08-05T11:50:41Z`;
- compiled artifact: `8929111021`, `surface-cell-p5-r2e4-github-source-linux-release`;
- artifact SHA-256: `dcb3dcca095a62efde3bc534a8eafca1a5a3976f3e98b649845c6ca47c682450`;
- workflow-log artifact: `8929111261`, `surface-cell-p5-r2e4-workflow-logs-31002566593`;
- workflow-log SHA-256: `a83b4533e6847976a1e942aff8a47b725a8ff468bc586477cc39fb3f45c206ba`;
- source status empty;
- recursive checksums **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

Target hashes:

- `directional_phase1_tests`: `6297dc779d4756b9a4e435781482dc9acb7f4f2e17d056704f95210e8302b579`;
- `directional_benchmarks`: `8026839c74129fe85feb6727d2989a9363eadeb075b611c7cb895941d8e6eed6`;
- `libdirectional_core.a`: `21fc43200b2e18b0344685aa8f5452dca7e423cf5de15d2da13c71c8b57c8ffc`;
- `libdirectional_pipeline.a`: `2fd1418986423d9f96d4c764bc922640f2901f9cb91fa67b6ee90080d9ebeb2b`.

## Implemented R2E4 behavior

1. Replaces the R2E3 two-target transposition with direct reconstruction of every affected node-local successor mapping.
2. Finds the one canonical SourceVertex or SourceEdge wedge shared by every outgoing ray in the authoritative boundary fan.
3. Requires the selected wedge to contain the complete local outgoing-ray inventory; missing, duplicate, contradictory, or partial evidence fails closed.
4. Uses the authoritative exterior incoming/outgoing pair to choose the semantic direction of the canonical cyclic ray order, preserving source-face-row and whole-orientation invariance.
5. Maps each incoming twin to the adjacent outgoing ray in that canonical rotation, assigning every local incoming and every local target exactly once.
6. The single wrap adjacency is the authoritative exterior sector; all other adjacencies are interior sectors, with hard rails and traces naturally acting as separators.
7. Adds typed `BoundaryRotationalSystemConflict` evidence and a derived `boundaryRotationalNodeCount` diagnostic.
8. Audits each local rotational bijection before writing successors.
9. Audits every authoritative source-boundary exterior cycle against the exact ordered-loop continuation before the global predecessor and orbit audits.
10. Preserves R2E3's orientation-invariant paired boundary-subsegment incidence identity.
11. Leaves `RepeatedEdgeCycle`, `RepeatedNodeCycle`, `NonDiskCell`, predecessor multiplicity, owner cardinality, and structural Euler validators unchanged.
12. Adds a generalized multiple-interior-rays-at-one-boundary-vertex contract and strengthens planar, hard-rail, and cylinder rotational evidence.

This is a direct producer-level rotational-system construction. It is not a missing-target repair, sequence of swaps, post-hoc cycle decomposition, or cell merge.

## Files changed

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

The coherent source/test patch contains **254 insertions and 87 deletions**. No FlowRep, tracing semantics, simplification, completion, optimizer, cache, lineage, fallback/recovery, memory accounting, or bunny intrinsic-fan subsystem was changed.

## Compile-only boundary

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No executable was invoked. Configure and compilation completed successfully with Ninja on Ubuntu 24.04 and GCC 13.3.

The authoritative workflow initialized and verified all nine recursive submodules before compiling the four required targets.

## Artifact source authority

The artifact contains two source snapshots:

- `source/exact-source.tar.gz` is the exact compiled commit and includes the bounded active workflow plus the base workflow;
- `source/source.tar.gz` excludes only `.github/workflows/agent-build-p5-r2e4.yml`, contains only `agent-source-snapshot.yml`, and contains zero temporary payloads.

`source-exclusions.txt` records that single transparent exclusion. After artifact upload, the bounded workflow was removed from the branch. The implementation commit had already removed both patch transport files.

The recursive manifest was generated outside the package, excludes itself from its input set, and passed all **48/48** entries before upload and after download.

## Next turn

Run **P5-TB32 artifact-only R2E4 validation** against artifact `8929111021`. Follow `.agents/Directional/Milestone_G_P5_R2E4_Test_Benchmark_Plan.md`.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
