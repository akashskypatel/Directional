# Milestone G P5-R1D Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

P5-R1D adjacent local-sheet exact-adjacency implementation and the exact four-target compile/package gate are complete. Runtime acceptance remains open because no packaged test, benchmark, mesh, help/list/discovery command, or other project binary executed in this turn.

Exact checkpoint:

- P5-TB24 tested source: `f4cce52006d21a248473e327ada1d66183af54e6`;
- successful workflow event commit: `6fc57831afc7f77e0cda9bd1f409aaaaece15bda`;
- P5-R1D implementation and exact compiled source: `a1fec970297739cfe23ade339b6a7b57071b7300`;
- applied source-diff SHA-256: `4488988dc877f1a0a001e27286b68f2752314bade361d59a11c1e7eae8a6cd89`;
- successful compile-only run: `30942950398`;
- job: `92105699139`;
- compiled artifact: `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`;
- artifact SHA-256: `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`;
- workflow-log artifact: `8906116758`, `surface-cell-p5-r1d-fix-workflow-logs-30942950398`;
- workflow-log SHA-256: `c8ceb09ca4ea9f72148125466a9958366b51a52f8e02c229aa71d1852b2d1ec2`.

Package verification:

- source status empty;
- recursive checksum manifest **40/40** verified;
- package contains **42** files total;
- fixture files **26**;
- recursive submodule records **9**;
- source archive contains the exact R1D implementation and focused contracts;
- all **132/132** Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No project binary executed.

## Implementation

### Exact manifold adjacency across local-sheet labels

`SourceChartTransitionGraph::build()` no longer requires equal local-sheet labels before admitting a genuine manifold source-edge transition.

A transition still requires:

- exactly two incident source faces;
- no hard-feature barrier on the shared edge;
- equal source-component identity;
- valid opposite shared-edge winding.

Source boundaries, nonmanifold incidence, hard rails, different source components, and disconnected topology continue to split intrinsic connectivity.

### Provenance remains authoritative

The change does not erase or normalize local-sheet labels. Each chart retains its declared local sheet in:

- `SourceChartId`;
- forward and reverse transition records;
- structural hashes;
- rebound `SurfacePoint` provenance;
- diagnostics and downstream ownership evidence.

Local-sheet compatibility remains required for non-topological proximity capture, projection, and disconnected close-sheet reconciliation. Exact source adjacency is the only newly admitted cross-sheet relation.

### Intrinsic source-vertex fans

Vertex fans continue to be connected components of incident charts through admissible exact manifold edges. Adjacent charts carrying different local-sheet labels may now belong to one intrinsic fan, while hard rails, component boundaries, nonmanifold sectors, source boundaries, and disconnected topology remain barriers.

### Focused compile-valid contracts

Added:

1. `SourceChartTransitionsR1.ExactManifoldAdjacencyCrossesLocalSheetLabels`;
2. `SourceChartTransitionsR1.SourceVertexFanCrossesAdjacentLocalSheetLabels`;
3. `SourceChartTransitionsR1.ComponentMismatchBlocksExactManifoldAdjacency`;
4. `SourceChartTransitionsR1.NonManifoldSharedEdgeDoesNotCreateTransition`.

Strengthened row-permutation and whole-mesh orientation-reversal contracts so they exercise different local-sheet labels across the valid manifold transition.

No expected result was weakened. No position, source-triangle pairing, insertion order, ownership frequency, or fallback establishes connectivity.

## Build history

The first workflow run, `30942749755`, failed before committing source because one whitespace-sensitive transformation did not match the current header. It executed no project binary. The successful workflow used a regex-bounded, single-occurrence transformation and hashed the resulting source diff before commit.

## Built-target hashes

- `directional_phase1_tests`: `452b546cc2202c741fa47701aa69c4b571b3f8836468d8b64a5130298e20a591`;
- `directional_benchmarks`: `a3c15c1c7b05901cb8e2d815fbf43c4189e388f04be283a72a070d2ae40c2762`;
- `libdirectional_core.a`: `c61fa1df41cef65ad46d72df8c013dad4a0932c00b77d4710e84e8a9d811f213`;
- `libdirectional_pipeline.a`: `a25317b1dd713da2add62c7bde904d6c9e54dcd7160cef2767224a0a6d76fef8`.

The clean Ninja Release configuration used Ubuntu 24.04, GNU 13.3, `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional solver backends disabled.

## Runtime acceptance boundary

Compilation does not establish that:

- all eleven `SourceChartTransitionsR1.*` contracts pass;
- the three P5-TB24 graph-dependent failures are closed;
- `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets` passes;
- Phase 14–18 is clean;
- plane, seam, or close sheets complete directly;
- the complete suite terminates without regression.

The next authoritative turn is **P5-TB25 artifact-only R1D validation** using artifact `8906115786` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Remain on R1 until the runtime gate is complete. Do not advance to R2 based on compile evidence.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.
