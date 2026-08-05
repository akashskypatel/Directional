# Milestone G P5-R2E Source-Boundary Side Ownership and Euler Topology Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code changes + compile-only build

## Purpose

Close the next remaining R2 producer by making source-boundary side ownership and aggregate arrangement topology derive from exact oriented source topology and the complete structural cell inventory. Preserve the R2D nonmanifold and nested-cell closures. Do not begin R3 completion work.

## Runtime authority

Use P5-TB28 evidence from exact source `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`, artifact `8913777837`.

Confirmed closures:

- typed three-face `NonManifoldSourceEdge` rejection;
- explicit nested two-boundary, Euler-zero `NonDisk` representation;
- no new complete-suite regressions.

Remaining earliest failures:

- planar fixture publishes no exterior cell, Euler `-1`, and area error `1`;
- interior hard rail publishes two exterior cells for one source boundary loop;
- open cylinder has complete incidence and cell ownership but invalid aggregate topology;
- seam, close sheets, and cylinder publish zero arrangement cells to completion;
- bunny singularity-fan embedding remains invalid;
- six Phase 17 contracts remain downstream of invalid arrangement topology.

## Scope

### 1. Replace per-orbit majority voting with exact source-boundary side witnesses

For every directed arrangement halfedge lying on an authoritative source boundary edge:

- derive the interior and exterior side from the oriented incident source triangle and canonical source-edge endpoint order;
- record the exact side witness on the audited successor orbit;
- require all source-boundary witnesses within one orbit to be mutually consistent;
- classify an orbit exterior only when it owns the exterior side of an authoritative source boundary loop;
- classify a bounded orbit touching the same source boundary as interior when it owns the interior side;
- fail closed with typed evidence if one orbit contains contradictory side witnesses.

Do not use vote counts, projected area sign, traversal order, cell count, or fixture identity to choose exterior ownership.

### 2. Enforce source-boundary-loop cardinality

Build canonical source boundary loops from exact source topology before cell publication.

For each connected source component:

- every authoritative source boundary loop must have exactly one exterior-side arrangement orbit;
- no interior hard rail may create an additional source boundary loop or exterior owner;
- a disk component must publish one exterior orbit;
- an open cylinder must publish two authoritative exterior boundary orbits while retaining bounded periodic cells as interior;
- a closed component must publish zero source-boundary exterior orbits;
- row order, seam start, and whole-mesh orientation reversal must preserve the canonical loop-to-orbit mapping and hashes.

If one source loop maps to zero or multiple exterior orbits, fail closed at the arrangement producer with explicit diagnostics rather than allowing completion to report generic invalid incidence.

### 3. Compute aggregate Euler from structural cell Euler contributions

The R2D cell descriptor already stores `boundaryComponentCount` and `eulerCharacteristic`. Use those authoritative values in global topology accounting.

- sum the Euler contribution of every bounded area-bearing cell;
- exclude exterior and support-only ownership;
- preserve a disk contribution of one, an annulus contribution of zero, and generalized `2 - boundaryComponentCount` only when structurally justified;
- do not count every bounded cell as one face unconditionally;
- derive arrangement boundary-loop diagnostics from the exact source-loop/exterior mapping, not from misclassified left/right labels;
- keep source Euler and component comparisons independent and fail closed on disagreement.

### 4. Preserve transactional complete ownership

- every valid halfedge must remain in exactly one audited orbit and exactly one committed cell;
- exterior reclassification must not duplicate, drop, or rewire halfedges;
- all boundary-cycle ranges must remain individually closed and successor-consistent;
- on any source-loop mapping or topology failure, clear the pending cell inventory and reset all halfedge cell IDs;
- include new loop identity and side evidence in deterministic arrangement, rollback, simplification, repair, descriptor, and pipeline hashes.

### 5. Restore valid topology inputs without downstream bypasses

The intended result is that planar, hard-rail, and cylinder arrangement topology becomes valid and seam/close-sheet/cylinder retain nonzero arrangement inventories naturally.

Do not:

- mark topology valid when source-loop cardinality or Euler checks fail;
- let completion accept an invalid arrangement;
- synthesize cells, counts, or validation stages;
- modify Phase 17 expectations or insert candidate special cases;
- enable fallback, source-grid recovery, or legacy output.

### 6. Treat bunny singularity-fan embedding as a bounded conditional subtask

Inspect the failing fan after the source-side/topology correction is implemented.

Modify intrinsic fan ordering or multi-chart boundary geometry only if static dependency analysis shows that the same incorrect source-side witness, boundary-cycle range, or aggregate topology path causes `embeddingValid == false` and zero center cells. Otherwise leave the bunny producer open and prepare a separate R2F plan after the next artifact-only turn.

Do not broaden this turn into a general source-vertex refactor.

## Required generalized contracts

Add or strengthen focused tests only where needed to verify the intended producer behavior:

1. a planar disk with inserted traces has exactly one exterior orbit, full area coverage, and Euler one;
2. an interior hard rail partitions bounded cells but leaves exactly one exterior owner for the source boundary loop;
3. an open cylinder has exactly two source boundary loops/exterior owners, complete cell ownership, Euler zero, and valid topology;
4. a nested annular bounded cell contributes Euler zero to global topology;
5. a closed source component publishes no exterior boundary orbit;
6. contradictory source-side witnesses fail closed with typed diagnostics;
7. source-face row permutation and whole-orientation reversal preserve loop identity, exterior ownership, and topology hashes;
8. R2D nonmanifold and nested contracts remain passing;
9. R2C dangling-bridge and support-only contracts remain passing.

Tests must construct real topology and must not assert synthetic counters or fixture-specific IDs.

## Expected files

Prefer the smallest coherent set centered on:

- `include/directional/geometry/SurfaceArrangement.h` only if new typed diagnostics or canonical loop identity fields are needed;
- `src/geometry/SurfaceArrangement.cpp`;
- deterministic hash consumers only for new authoritative fields;
- focused `SurfaceArrangementPhase16Tests.cpp` and `MilestoneDClosureTests.cpp` contracts;
- turn documentation and handoff.

Do not refactor unrelated FlowRep, simplification, completion, cache, lineage, or memory code.

## Mandatory working-branch hygiene

At the start and end of this Code + Build turn:

- compare temporary agent resources against `surface_cell_quad` and the current turn;
- remove all superseded workflows, trigger files, patch fragments, patch READMEs, transfer files, and generated build artifacts;
- retain only the base workflow plus the one active bounded workflow/payload while the build is active;
- self-remove the active workflow and payload from the exact compiled source, or remove them immediately in the documentation handoff commit;
- verify the final branch and packaged source contain only base workflows and zero temporary payloads.

Never leave historical workflow YAML on the working branch.

## Compile-only gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable. Build the exact pushed commit. Preserve empty source status, recursive submodule authority, detailed activity logging, and a separate always-uploaded workflow-log artifact.

## Next Test + Benchmark acceptance

The next artifact-only turn must require:

- source-chart **11/11**;
- Phase 22 validator **6/6**;
- recovery authority **9/9**;
- feature/barrier authority **8/8**;
- graph-dependent **6/6**;
- all R2/R2C/R2D/R2E focused contracts pass;
- planar Euler, area, and one-exterior-loop contract passes;
- hard rail has one exterior and two bounded cells with valid topology;
- cylinder has two source boundary loops, nonzero valid arrangement cells, and valid topology;
- nested and nonmanifold closures remain clean;
- Phase 16 and Milestone D are clean;
- Phase 17 failures attributable to arrangement inputs close naturally;
- Phase 18 remains **57/57**;
- seam, close sheets, and cylinder retain nonzero arrangement inventories;
- Phase 20 does not regress;
- complete suite terminates;
- runtime and memory are measured without treating earlier failure as progress.

Advance to R3 only after all R2 incidence, source-side region, topology, and embedding gates close independently.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition;
- no timeout-as-correctness.
