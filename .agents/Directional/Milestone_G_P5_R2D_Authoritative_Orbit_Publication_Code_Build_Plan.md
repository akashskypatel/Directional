# Milestone G P5-R2D Authoritative Orbit Publication Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code changes + compile-only build

## Purpose

Close the remaining R2 defect by separating source-topology admissibility, successor-orbit structural audit, bounded-cell topology, exterior classification, and transactional cell assignment. Preserve the passing R1 and R2C bridge contracts. Do not begin R3 topology-distinct completion.

## Runtime authority

Use P5-TB27 artifact-only evidence from exact source `94b86c50c38a849a744f40b0a21c86ed19551769`, artifact `8912374007`.

Primary failures:

- planar Euler `-1` instead of `1`;
- nested two-boundary cell not represented as `NonDisk`, boundary components `2`, Euler `0`;
- three-face nonmanifold source edge incorrectly reports valid incidence;
- bunny singularity fan embedding invalid;
- interior hard rail and open cylinder pass narrow incidence but fail final topology;
- seam, close sheets, and cylinder produce zero arrangement cells and completion receives `InvalidInputIncidence`;
- six Phase 17 candidates/mutations remain absent;
- Phase 20 remains 46/48.

## Scope

### 1. Restore authoritative source-topology preflight

Before accepting any successor permutation or audited orbit:

- detect source edges with incident-face count other than one or two;
- respect component, local-sheet, and hard-barrier partitions without treating three independent sheet labels as permission to accept one nonmanifold source edge;
- fail closed with the existing typed incidence diagnostics;
- transactionally clear cells and reset all halfedge ownership on failure.

Verify by compilation and preserved test intent only; do not execute tests in this turn.

### 2. Separate orbit audit from cell-topology classification

Keep the current complete successor traversal and Tarjan bridge/core audit, but produce an explicit structural descriptor before creating a `SurfaceArrangementCell`:

- ordered directed core cycles;
- exact twin-pair bridge forest;
- connected core-component graph;
- source-boundary incidence per directed core;
- bounded versus exterior role;
- boundary-component count;
- Euler characteristic;
- support-only versus area-bearing ownership.

Do not hard-code `boundaryComponentCount = 1` or infer all non-simple cells as Euler zero without structural evidence.

### 3. Make exterior classification component-authoritative

For each connected source component:

- classify exterior ownership from exact source-boundary sectors and directed orientation;
- permit exactly the source-topology-required exterior loops;
- never let an interior hard rail manufacture an exterior component;
- preserve two source boundary loops for an open cylinder while keeping bounded periodic cells interior;
- preserve source-row, seam-start, and whole-orientation invariance.

Negative projected area remains non-authoritative.

### 4. Represent nested and bridge-bearing bounded topology exactly

- A simple bounded core remains a disk with one boundary component and Euler one.
- A valid multi-core cut disk joined by an admissible bridge forest remains `cutCellDisk`, disk, Euler one.
- A bounded annular/nested cell is `NonDisk`, has two boundary components, and Euler zero.
- A dangling support excursion remains explicit and non-disk.
- A support-only orbit remains an exact two-halfedge twin pair, owns its support, and contributes neither area nor Euler face count.
- A figure-eight, theta graph, repeated nonbridge node/edge, malformed bridge multiplicity, missing successor, ambiguous successor, or incomplete permutation fails closed.

Do not decompose an invalid successor orbit after construction.

### 5. Publish cells transactionally from the complete structural inventory

- Require every runtime-valid halfedge to occur in exactly one audited structural descriptor.
- Assign every runtime-valid halfedge exactly one bounded/exterior/support cell ID.
- Validate predecessor, successor, twin, orbit, and cell coverage before committing any cell.
- On any failure, clear the entire pending cell inventory and reset `halfedge.cell` to `-1`.
- Include all new structural fields in deterministic hashes, rollback identity, and diagnostics.

### 6. Preserve downstream contracts without synthetic repair

The corrected arrangement must naturally restore inputs needed by FlowRep/simplification and completion. Do not special-case the six failing Phase 17 test names, direct manifest case names, source IDs, or cell counts. Do not modify test expectations or bypass completion/validation stages.

Track `FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation` separately. Modify FlowRep only if static dependency analysis proves the R2D structural representation requires a generalized continuation change; otherwise leave it for a later focused producer turn.

## Required implementation invariants

1. Source nonmanifoldness is rejected before a valid incidence disposition can be published.
2. Successor/predecessor permutation validity does not imply disk topology or exterior classification.
3. Cell topology derives from the audited graph and source-boundary sectors, not world-space position, frequency, order, or fixture identity.
4. Every valid halfedge owns exactly one cell after a successful transaction.
5. Support-only ownership is retained but excluded from area and Euler totals.
6. R1 canonical source-chart transitions remain authoritative.
7. R2C dangling-bridge and isolated-support contracts remain supported.
8. No post-hoc cycle decomposition, arbitrary subset search, recovery substitution, or validator weakening is introduced.

## Files expected to change

Prefer the smallest coherent set, expected to center on:

- `include/directional/geometry/SurfaceArrangement.h` only if the structural descriptor or diagnostics require public fields;
- `src/geometry/SurfaceArrangement.cpp`;
- focused Phase 16 and Milestone D tests only when new generalized contracts are required to express intended behavior;
- deterministic hash/rollback consumers only where a new authoritative structural field must propagate;
- turn documentation and handoff.

Do not refactor unrelated geometry, completion, FlowRep, or pipeline code.

## Compile-only gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable. Build the exact pushed commit. Preserve empty source status, recursive submodule authority, detailed activity logging, and a separate always-uploaded workflow log artifact.

## Next Test + Benchmark acceptance

The following turn must execute the exact artifact and require:

- source-chart R1 **11/11**;
- Phase 22 validator **6/6**;
- recovery authority **9/9**;
- feature/barrier authority **8/8**;
- graph-dependent **6/6**;
- all R2/R2C/R2D focused contracts pass;
- nonmanifold source edge fails with typed incidence evidence;
- planar Euler/boundary/area contract passes;
- nested non-disk contract passes;
- bunny singularity fan passes;
- Milestone D **7/7**;
- Phase 16 and Phase 17 clean, Phase 18 **57/57**, Phase 14–18 clean;
- seam, close sheets, and cylinder retain nonzero valid arrangement inventories;
- direct failures either close or move to a later typed completion producer;
- Phase 20 does not regress;
- complete suite terminates;
- runtime and memory are measured without treating earlier failure as progress.

Advance to R3 only after these R2 gates close.
