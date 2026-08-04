# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB23 artifact-only validation is complete. R0 and R1 remain open. Do not advance to R2.

Tested checkpoint:

- exact source `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- R0/R1 implementation `ae0c09ed1290df75d1d2cc1d5af039fc1feb83a3`;
- artifact `8902050372`, `surface-cell-p5-r1-github-source-linux-release`;
- artifact SHA-256 `5d1e5ca4fa8bc74e0a30615725c79a8b491830ab1f4407152cf79bfe56f8880f`;
- source status empty;
- recursive checksums **41/41**;
- package files **43**;
- fixtures **26**;
- recursive submodules **9**.

P5-TB23 configured, rebuilt, relinked, patched, regenerated, and modified no source.

The next turn is **P5-R1C source-chart orientation correction plus compile-only build**. Execute no project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB23_Artifact_Only_R0_R1_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb23-summary.json`
5. `.agents/Directional/Milestone_G_P5_R1C_Source_Chart_Orientation_Correction_Code_Build_Plan.md`
6. `.agents/Directional/REORIENTATION_PLAN.md`
7. `.agents/Directional/DESIGN.md`
8. `.agents/Directional/Milestone_G_P5_R0_R1_Code_Build_Report.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB23 result

- focused R0/R1 **8/12**;
- focused recovery **8/9**;
- Phase 14–18 **233/242**;
- Phase20 **35/48**;
- bounded diagnostic suite **553/603**;
- complete suite discovered 606 tests but did not terminate within 1200 seconds;
- full-suite stall: GP26 production matrix, `bunny_1k_random__surface_cells`;
- direct analytic plane/seam/close sheets **0/3**.

Analytic failures with backend `SurfaceCells`, fallback `Fail`, recovery disabled:

- plane: 12 quads, 27 validation failures, `LocalSheetMismatch` at cell/face 0/0;
- seam: 24 quads, 46 failures, same earliest reason/location;
- close sheets: 34 quads, 61 failures, same earliest reason/location.

No analytic case used recovery, fallback, or legacy output.

## Earliest authoritative root cause

`SourceChartTransitionGraph::edge_orientation` has the valid and invalid cases reversed.

For a consistently oriented manifold source, the two incident triangles traverse their shared edge in opposite directions. The current function returns the rejected orientation for that valid case and the accepted orientation for equal-direction winding.

Observed proof:

- valid opposite-winding transition test reports `graph.available() == false`;
- invalid same-direction winding test reports `graph.available() == true`;
- hard-rail source-vertex fan resolution becomes unavailable because the graph is globally rejected;
- arrangement ownership, completion alias, explicit recovery, and direct validation failures follow.

Fix the predicate. Do not weaken the tests or validator.

## P5-R1C required work

1. Correct shared-edge orientation classification:
   - opposite traversal is valid;
   - equal traversal is invalid;
   - whole-mesh orientation reversal remains valid;
   - reversing one face fails;
   - row permutations preserve hashes.
2. Confirm intrinsic vertex-fan adjacency is restored and still split by:
   - source boundaries;
   - components and local sheets;
   - hard rails;
   - nonmanifold sectors.
3. Re-evaluate only graph-dependent failures:
   - arrangement ownership registry;
   - curved multi-face and singularity-fan topology;
   - boundary vertex/edge completion aliases;
   - explicit planar recovery validation.
4. Add `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` to the existing `directional_phase1_tests` target. The P5-TB23 artifact did not expose these requested tests because only the dedicated Milestone F validator executable contained them.
5. Keep R2–R11 deferred.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not run tests, benchmarks, custom meshes, help/list/discovery commands, or generated project executables. Initialize detailed logging before fallible work and always upload the log artifact.

## Next runtime gate

P5-TB24 must execute the packaged artifact directly and require:

- all `SourceChartTransitionsR1.*` tests pass;
- packaged Phase22 validator tests are available and pass intended valid/invalid cases;
- Phase 14–18 returns to at least the TB22 baseline with new tests included;
- explicit planar recovery reports `SourceGridRecovery`;
- analytic plane/seam/close sheets are no longer rejected due to valid winding;
- the complete suite terminates.

Only then consider R2.

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

- A transition-orientation sign error can invalidate the entire source-chart graph and make downstream failures appear unrelated.
- Fix the earliest exact topology predicate before changing ownership, completion, stage lineage, or performance systems.
- Artifact plans must ensure requested test sources are linked into the packaged test executable.
