# Milestone G P5-R1C Source-Chart Orientation Correction Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Turn type:** code changes plus compile-only build

## Objective

Correct the earliest R1 producer exposed by P5-TB23 without advancing to R2 or broadening the repair surface.

P5-TB23 authority:

- exact tested source `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- artifact `8902050372`;
- focused R0/R1 **8/12**;
- Phase 14–18 **233/242**;
- Phase 20 **35/48**;
- analytic plane/seam/close-sheets **0/3**;
- complete suite fails to terminate within 1200 seconds at the GP26 bunny case;
- bounded suite **553/603**.

## R1C-1 — Correct shared-edge orientation classification

In `SourceChartTransitionGraph::edge_orientation`:

1. Compute the directed traversal of each incident triangle along canonical `(lowVertex, highVertex)`.
2. Treat a manifold shared edge as consistently oriented only when the directions are opposite.
3. Return the transition orientation value expected by `build()` for opposite traversal.
4. Reject equal-direction traversal.
5. Keep exact endpoint and barycentric maps independent of source-face row ordering.

The current implementation has the valid and invalid cases reversed. Fix the predicate, not the tests.

Required contracts:

- valid opposite traversal creates two inverse transitions;
- same-direction traversal fails closed;
- reversed whole-mesh orientation remains valid;
- reversing only one face remains invalid;
- transition hashes are stable under face-row permutation.

## R1C-2 — Restore intrinsic vertex-fan construction

After the orientation correction:

- ensure admissible face adjacency is populated before fan traversal;
- preserve fan splits at hard rails, source boundaries, component/sheet barriers, and nonmanifold sectors;
- verify deterministic fan ordinals from canonical fan membership, not insertion order;
- do not merge disconnected or opposite sheets through position.

Do not add post-hoc fan repair or positional fallback.

## R1C-3 — Restore arrangement and completion aliases

Re-evaluate only the failures that depend on a valid graph:

- adjacent per-face ownership classes;
- unlabelled ownership registry construction;
- repeated-cell class membership;
- curved multi-face and singularity-fan arrangement topology;
- boundary source-vertex/source-edge completion aliases;
- explicit planar recovery validation.

Only correct call-site behavior that remains demonstrably wrong after the orientation predicate is fixed. Do not weaken component, sheet, hard-rail, or source-authoritative validation.

## R1C-4 — Package validator contracts in the existing test target

Add `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` to `directional_phase1_tests` in `CMakeLists.txt`.

This does not add a fifth build target. It makes the validator contracts requested by the artifact-only plan available through the already packaged test executable.

Do not remove the dedicated Milestone F validator targets.

## Explicit non-goals

Do not implement:

- R2 directed wedge/incidence reconstruction;
- R3 topology-distinct completion;
- R4 repeated-node splicing;
- R5 phase/front state;
- torus or adaptive transitions;
- cache reuse, injected lineage, or memory telemetry;
- bunny-specific behavior;
- new fallback/recovery behavior;
- new ownership classifications unless the current typed evidence cannot represent a real failure.

## Compile/package boundary

Use a clean Ninja Release build with shallow recursive submodules. Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable.

Package exact source authority, empty source status, recursive checksums, all fixtures, recursive submodule records, four target hashes, and complete configure/build/activity logs.

## Next runtime turn

P5-TB24 must execute the resulting artifact directly and first require:

1. all `SourceChartTransitionsR1.*` contracts pass;
2. newly packaged validator contracts run and pass their intended valid/invalid cases;
3. Phase 14–18 returns to at least the P5-TB22 baseline with the new contracts included;
4. explicit planar recovery reports `SourceGridRecovery`;
5. plane, seam, and close sheets no longer fail because the transition graph rejects valid winding;
6. the complete suite terminates before any decision to advance to R2.

Advance to R2 only if R1 closes independently.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
