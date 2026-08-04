# Milestone G P5-R2 Directed Wedge/Incidence Code-Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Objective

Replace post-hoc repeated-cycle splitting with authoritative directed source-chart wedge incidence before any cell is assigned.

P5-TB25 closes R1 source-chart authority but leaves:

- `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` failing with `non-disk-cell cell=0 halfedge=43 twin=42 next=29`;
- invalid hard-rail exterior classification;
- plane/seam/close-sheet manifold and valence failures;
- cylinder variant 51 bow-tie completion after invalid periodic incidence reaches completion.

The earliest remaining producer is the radial successor construction in `src/geometry/SurfaceArrangement.cpp`.

## Corrected R2 semantics

The older reorientation pseudocode listed raw sheet boundaries as unconditional wedge splits. R1D established the precise rule:

- local-sheet labels remain authoritative provenance;
- local-sheet inequality alone does not split exact manifold adjacency when the R1 transition graph admits the charts;
- wedge barriers are different source components, hard rails, source boundaries, nonmanifold sectors, disconnected intrinsic fans, and missing or inconsistent R1 transitions.

R2 must consume the R1 transition graph and must not reintroduce raw local-sheet equality as an adjacency gate.

## P5-R2 implementation checklist

### R2-CB1 — Explicit directed wedge inventory

In `src/geometry/SurfaceArrangement.cpp` and corresponding structures:

1. Build canonical intrinsic node identities before radial ordering.
2. Group each node's outgoing halfedges into directed wedges using:
   - source component;
   - canonical source entity/fan from `SourceChartTransitionGraph`;
   - source-face transition reachability;
   - hard-rail and boundary sectors;
   - nonmanifold/disconnected fan barriers.
3. Preserve each halfedge's local-sheet provenance without using raw sheet equality as the grouping owner.
4. Give every wedge a deterministic structural identity independent of face-row order, insertion order, world position, and fixture IDs.

### R2-CB2 — Intrinsic ordering inside each wedge

1. Sort only within one admissible wedge.
2. Use exact source-face/source-vertex intrinsic parameters and transition maps.
3. Do not use world-space angular order to connect halfedges across source charts.
4. Fail closed when an authoritative source-vertex halfedge cannot be placed uniquely.
5. Retain geometric angular ordering only for genuinely face-interior nodes where no cross-chart topology decision occurs.

### R2-CB3 — Successor/predecessor permutation

For every directed halfedge:

1. locate its incoming twin at the destination node;
2. identify the unique admissible destination wedge through the R1 graph;
3. assign exactly one successor in that wedge;
4. record exactly one predecessor for the successor;
5. reject missing, duplicate, or cross-wedge assignments transactionally.

Audit before cycle enumeration:

- every halfedge has one valid twin;
- twin symmetry holds;
- every halfedge has one successor;
- every halfedge has one predecessor;
- `successor.from == current.to`;
- no successor crosses a barrier;
- the permutation covers all halfedges exactly once.

### R2-CB4 — Remove post-hoc cycle splitting

Delete the block that splits a radial successor walk at repeated boundary nodes after successor construction.

A repeated-node or repeated-edge cycle is invalid wedge pairing. Return a typed incidence failure containing:

- node;
- halfedge;
- twin;
- successor;
- predecessor multiplicity;
- wedge identity;
- component, local-sheet provenance, and source-face evidence.

Do not repair it by selecting a split occurrence, shortest subcycle, count, order, or positional heuristic.

### R2-CB5 — Enumerate and classify before assigning cells

1. Enumerate successor cycles only after the global audit passes.
2. Require every directed halfedge to belong to exactly one cycle.
3. Require each cycle to be closed, edge-simple, and node-simple.
4. Classify exterior cycles from authoritative source boundary/hard-rail sectors before assigning cell IDs.
5. Interior hard rails must not vote as exterior source boundaries.
6. Assign bounded cell IDs only after the complete cycle inventory passes.
7. Compute disk/Euler invariants from audited incidence, not a repaired cycle.

### R2-CB6 — Immediate consumers only

Correct only consumers whose assumptions contradict the new incidence:

- arrangement diagnostics and hashes;
- simplification incidence validator;
- patch descriptor input ordering;
- completion entry conditions currently receiving a pinched/non-disk cell.

Do not implement R3 topology catalogs, R4 splice alternatives, R5 lattice state, R6 torus decomposition, R7 adaptivity, R9 cache reuse, R10 lineage fixtures, or R11 memory telemetry.

## Required compile-valid contracts

Add or strengthen tests that compile now and execute in P5-TB26:

1. periodic cylinder produces node-simple disk cycles before simplification;
2. cylinder seam-start permutation preserves successor and cell hashes;
3. source-face row and whole-orientation permutations preserve incidence;
4. every halfedge has predecessor/successor multiplicity one;
5. every halfedge belongs to exactly one cycle;
6. interior hard rails split wedges but are not exterior boundaries;
7. source boundary sectors classify the exterior cycle correctly;
8. two hard-rail barriers split a source-vertex fan into intended sectors;
9. adjacent local-sheet charts connected by R1 remain one admissible intrinsic fan;
10. disconnected close sheets and different components never share a wedge;
11. nonmanifold source-edge sectors fail closed;
12. an invalid repeated-node successor cycle is rejected, not decomposed;
13. `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` remains a meaningful valid scenario;
14. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` remains a meaningful periodic scenario.

Do not weaken expected topology or replace invalid test inputs with trivial fixtures. Correct a fixture only when it cannot instantiate its stated contract.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list, or discovery command. Initialize detailed logs before fallible work and package exact source, target hashes, fixtures, submodule records, and clean source status.

## P5-TB26 runtime gate

The following turn must execute the artifact without rebuilding and require:

- all R1 gates remain clean;
- all new directed-incidence contracts pass;
- both Milestone D failures close;
- cylinder arrangement incidence is valid before completion;
- plane/seam/close-sheet manifold and valence failures decrease or move to a later typed R3 producer;
- Phase 14–18 remains clean;
- Phase 20 does not regress;
- the complete suite terminates;
- bunny duration and memory are compared against P5-TB24 and P5-TB25.

R2 does not close from compilation or merely moving a failure to completion. Runtime evidence must prove a globally valid directed halfedge permutation and simple cell inventory.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
