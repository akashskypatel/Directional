# Milestone G P5-R1D Adjacent Local-Sheet Exact-Adjacency Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Turn type:** code changes plus compile-only build

## Objective

Close the remaining R1 defect without beginning R2.

A local-sheet label is authoritative provenance and a barrier for non-topological proximity/capture operations. It is not, by itself, a barrier to a genuine manifold source-edge transition or an intrinsic source-vertex fan within one source component.

## Required implementation

### 1. Correct transition-graph admissibility

In `SourceChartTransitionGraph::build()`:

- require exactly two incident faces for a transition;
- reject hard-feature edges;
- require equal source-component identity;
- require valid opposite shared-edge winding;
- do **not** require equal local-sheet labels for exact manifold adjacency.

Continue to preserve each face's declared local-sheet label in `SourceChartId`, transition records, canonical membership identities, provenance, and diagnostics.

### 2. Preserve true barriers

Exact adjacency must remain split by:

- different source components;
- hard-feature rails;
- source boundaries;
- nonmanifold edge incidence;
- disconnected topology.

No world-space distance, source-triangle pairing, ownership frequency, or insertion order may establish connectivity.

### 3. Restore intrinsic source-vertex fans

Build vertex fans from the corrected admissible manifold adjacency. A fan may contain adjacent charts with different local-sheet labels, while hard rails, component boundaries, nonmanifold sectors, and disconnected sheets still split the fan.

### 4. Preserve canonical identities and determinism

- Preserve local-sheet values in component/fan membership identities.
- Preserve exact forward/reverse barycentric maps.
- Preserve face-row permutation and whole-mesh orientation-reversal invariance.
- Preserve deterministic component/fan ordinals and transition hashes.

### 5. Correct documentation contradictions

Update comments that currently state that local-sheet inequality always blocks intrinsic connectivity. Clarify:

```text
local sheet blocks proximity-based reconciliation;
exact manifold adjacency within one component may cross local-sheet labels;
hard rails, boundaries, nonmanifold incidence, and components remain barriers.
```

Do not weaken the same-sheet safety invariant for geometric capture or projection.

## Required tests

Add or strengthen focused tests for:

1. exact shared-edge transition across different local-sheet labels;
2. exact source-vertex rebind across adjacent local-sheet charts;
3. hard rail still splitting different local-sheet charts;
4. component mismatch still blocking transition;
5. disconnected close sheets remaining distinct;
6. nonmanifold sectors remaining distinct;
7. face-row permutation invariance;
8. whole-mesh orientation-reversal invariance;
9. `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets` behavior;
10. completion boundary vertex/edge alias acceptance;
11. adjacent Phase 16 ownership class construction;
12. bunny singularity-fan embedding and topology.

Do not alter expected results merely to match current implementation.

## Re-evaluation boundary

The code turn may inspect and correct only immediate consumers whose assumptions still contradict the corrected transition graph:

- `SurfaceArrangement` ownership-class construction;
- completion ownership validation and canonical provenance rebinding;
- source-authoritative local-sheet compatibility;
- explicit recovery validation.

Do not begin directed wedge/incidence reconstruction, topology-distinct completion templates, repeated-node splicing, phase/front state, torus decomposition, cache work, lineage hardening, or memory optimization.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable during the code/build turn.

## Next runtime gate

The following artifact-only turn must require:

- all `SourceChartTransitionsR1.*` tests pass;
- all packaged Phase 22 validator tests pass;
- focused recovery remains 9/9;
- the three remaining graph-dependent tests pass;
- `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets` passes;
- Phase 14–18 is clean;
- analytic plane, seam, and close sheets are no longer rejected by local-sheet chart incompatibility;
- the complete suite still terminates.

Advance to R2 only after these R1 conditions are satisfied.
