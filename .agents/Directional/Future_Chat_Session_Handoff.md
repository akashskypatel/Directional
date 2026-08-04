# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB25 artifact-only R1D validation is complete against exact source `a1fec970297739cfe23ade339b6a7b57071b7300` and artifact `8906115786`.

R0 and R1 are closed. The next turn is **P5-R2 directed wedge/incidence reconstruction plus compile-only build**.

Package authority:

- artifact `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`;
- SHA-256 `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`;
- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**.

P5-TB25 configured, rebuilt, relinked, patched, regenerated, and modified no source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB25_Artifact_Only_R1D_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb25-summary.json`
5. `.agents/Directional/Milestone_G_P5_R2_Directed_Wedge_Incidence_Code_Build_Plan.md`
6. `.agents/Directional/REORIENTATION_PLAN.md`
7. `.agents/Directional/DESIGN.md`
8. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB25 runtime authority

- source-chart R1: **11/11**;
- Phase 22 source validator: **6/6**;
- recovery authority: **9/9**;
- graph-dependent focused: **6/6**;
- feature-rail/barrier focused: **8/8**;
- Phase 14–18: **247/247**;
- Phase 16: **39/39**;
- Phase 20: **46/48**;
- direct plane/seam/close sheets: **0/3**;
- complete suite: **598/617**, terminating in **333.444 seconds**;
- observed process `VmHWM`: at least **582,904 KiB**.

Compared with P5-TB24, four prior failures close and all four new R1D tests pass. Failures improve **23 → 19**. Runtime regresses **4.43×** and observed memory is at least **2.27×**. Three bunny executions each take roughly 108–113 seconds. Termination is proven; acceptable production performance is not.

## Closed R1 contracts

1. Opposite manifold source-edge traversal is accepted.
2. Equal-direction traversal is rejected.
3. Exact manifold adjacency may cross different local-sheet labels within one source component.
4. Local-sheet provenance remains attached to charts, transitions, rebound points, hashes, and diagnostics.
5. Components, hard rails, source boundaries, nonmanifold sectors, disconnected fans, and inconsistent transitions remain barriers.
6. Intrinsic source-vertex fans cross adjacent chart labels only through exact topology.
7. Proximity capture and projection retain sheet safety.
8. Completion aliases, adjacent ownership, bunny fan rotation, and feature-rail incident-sheet support pass.

## Earliest remaining producer

`src/geometry/SurfaceArrangement.cpp` currently performs one global radial order per node, assigns the predecessor of each incoming twin as successor, then tries to split repeated-node cycles after the successor relation exists.

Evidence:

- `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` — topology invalid;
- `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` — `non-disk-cell cell=0 halfedge=43 twin=42 next=29`;
- plane/seam/close sheets retain manifold and valence failures with zero rail, provenance, or sheet failures;
- cylinder reaches pattern variant 51 with a bow-tie completion embedding.

This is the R2 directed-incidence defect. Do not attempt R3 completion-template repair first.

## P5-R2 required work

1. Build explicit directed source-chart wedge inventories at every arrangement node.
2. Consume canonical source entity/fan and transition reachability from the R1 graph.
3. Preserve local-sheet labels as provenance; do not split solely on raw sheet inequality when R1 admits adjacency.
4. Split wedges at component, hard-rail, source-boundary, nonmanifold, disconnected-fan, and transition-inconsistency barriers.
5. Sort only inside one admissible wedge using intrinsic source parameters.
6. Assign exactly one successor and predecessor per directed halfedge.
7. Audit twin symmetry, endpoint continuity, predecessor/successor multiplicity, and full permutation coverage before cycle enumeration.
8. Remove post-hoc repeated-node cycle splitting.
9. Reject repeated-node/repeated-edge cycles with typed node/halfedge/twin/successor/wedge evidence.
10. Enumerate simple cycles, classify exterior cycles, and only then assign cell IDs.
11. Ensure interior hard rails do not vote as exterior source boundaries.
12. Correct only immediate arrangement, incidence-validator, patch-ordering, and completion-entry consumers.
13. Keep R3–R11 deferred.

## Required compile-valid contracts

Add or strengthen meaningful contracts for:

- periodic cylinder simple-disk incidence;
- seam-start, face-row, and orientation invariance;
- predecessor/successor multiplicity one;
- every halfedge belongs to exactly one cycle;
- hard-rail sector separation without exterior misclassification;
- R1-connected adjacent local sheets remain one intrinsic fan;
- disconnected close sheets and different components remain separate;
- nonmanifold sectors fail closed;
- repeated-node cycles are rejected, not decomposed;
- both current Milestone D failures express valid intended scenarios.

Do not weaken expected topology or trivialize fixtures.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Run no tests, benchmarks, custom meshes, help/list/discovery commands, or generated executables. Initialize detailed logging before fallible work and always package exact source, target hashes, fixtures, submodule records, and clean source status.

## Subsequent order

1. R2 — directed wedge/incidence reconstruction;
2. R3 — topology-distinct patch completion;
3. R4 — repeated-node splice producer;
4. R5 — explicit local lattice and advancing-front events;
5. R6 — torus decomposition;
6. R7 — adaptive dyadic transitions;
7. R8 — direct production validation;
8. R9 — cache reuse;
9. R10 — stage-lineage fixtures;
10. R11 — memory telemetry.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- Source-chart correctness and directed cell incidence are separate layers. R1 can be fully correct while a global radial successor rule still creates pinched cells.
- Construct admissible directed wedges before assigning successors. Do not repair repeated cycles after cell topology already exists.
- R1D materially increases bunny runtime and memory. P5-TB26 must compare both against P5-TB24 and P5-TB25 after R2.
