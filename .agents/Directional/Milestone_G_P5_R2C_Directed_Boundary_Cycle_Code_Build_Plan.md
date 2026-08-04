# Milestone G P5-R2C Directed Boundary-Sector and Cycle-Inventory Code-Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Objective

Correct the R2 valid-cycle inventory regression without restoring post-hoc repeated-node decomposition or weakening typed incidence rejection.

P5-TB26 proves that narrow directed-wedge permutation contracts pass, but valid source-boundary, hard-rail, disconnected-component, singularity-fan, and periodic-cylinder sectors can be omitted from `auditedCycles`. The resulting halfedges retain `cell == -1`, valid cells disappear, and downstream simplification/completion receives invalid or empty incidence.

Remain on R2. Do not implement R3.

## Required semantics

1. Every valid directed halfedge must receive exactly one successor, one predecessor, one audited cycle, and one cell assignment.
2. Exterior source-boundary cycles are valid cycles, not incomplete permutations.
3. Interior hard rails split intrinsic wedges but do not create independent exterior source-boundary cycles.
4. Adjacent local-sheet charts connected by R1 remain one intrinsic fan; raw sheet inequality is not a barrier.
5. Different components, disconnected close sheets, hard-rail sectors, source boundaries, nonmanifold incidence, disconnected vertex fans, and missing/inconsistent R1 transitions remain authoritative barriers.
6. Valid periodic seams may close a node-simple, edge-simple cycle across canonical chart transitions.
7. Genuine repeated-node, repeated-edge, short, ambiguous, missing-successor, duplicate-predecessor, or incomplete permutations fail closed with typed evidence.
8. No cycle may be repaired by occurrence selection, shortest-cycle choice, positional ordering, count/frequency voting, or post-hoc decomposition.

## P5-R2C implementation checklist

### R2C-CB1 — Separate wedge validity from cycle class

Audit the current `DirectedWedgeMap`, `successorWedge`, and `auditedCycles` construction.

- Identify why valid boundary and periodic sectors are dropped after successor assignment.
- Preserve one-to-one successor/predecessor audit independently of whether the resulting cycle is interior or exterior.
- Do not clear all audited cycles merely because a distinct invalid sector exists; build transactionally and return typed failure without leaving apparently valid halfedges partially assigned.
- Ensure first-failure evidence identifies the actual missing/ambiguous wedge or invalid cycle rather than surfacing later as `invalid-cell cell=-1`.

### R2C-CB2 — Authoritative source-boundary sector closure

- Represent source-boundary sectors explicitly in wedge identity and ordering.
- Close the exterior successor relation using the exact boundary orientation and R1 chart transition/fan identity.
- Classify exterior cycles only after the cycle is complete and audited.
- Require exactly the intended exterior cycle per connected planar source component.
- An interior hard rail may partition interior wedges but must not vote as a source boundary or create another exterior cycle.

### R2C-CB3 — Complete cell assignment transaction

Before publishing `SurfaceCellComplex`:

- every halfedge must belong to one audited cycle;
- every audited cycle must receive a bounded cell ID;
- every cycle halfedge must receive that cell ID;
- no halfedge may retain `cell == -1` in an otherwise valid arrangement;
- the cell inventory must cover all directed halfedges exactly once;
- failure must leave a coherent fail-closed diagnostic state, not a partially populated valid-looking complex.

Add a dedicated typed failure for unassigned cycle/cell ownership only if existing `IncompletePermutation` cannot represent the producer precisely. Do not use a synthetic counter to conceal the missing assignment.

### R2C-CB4 — Restore valid sector classes

Restore without fixture special cases:

- planar exterior plus interior cell inventory and Euler/area accounting;
- disconnected components each producing intended interior/exterior cycles;
- explicit non-disk/patch-candidate exposure;
- intrinsic singularity-fan sectors and singularity-touch propagation;
- valid periodic cylinder cycles;
- seam and close-sheet arrangements retaining nonzero valid cell inventories.

### R2C-CB5 — Preserve R2 and R1 authority

Retain:

- `SurfaceArrangementIncidenceFailure` typed failures;
- deterministic `directedIncidenceHash`;
- source-row and whole-orientation invariance;
- R1 cross-local-sheet exact adjacency;
- component, hard-rail, boundary, nonmanifold, disconnected-fan, and transition barriers;
- nonmanifold fail-closed contract;
- complete successor/predecessor multiplicity audit;
- no post-hoc repeated-node splitting.

### R2C-CB6 — Immediate consumers only

Correct only immediate consumers invalidated by missing cycle/cell inventory:

- arrangement topology/area diagnostics;
- singularity-touch and candidate classification derived from valid cells;
- simplification entry validation and rollback identity;
- completion input-incidence guard.

Do not implement topology-distinct completion variants, repeated-node splice alternatives, advancing-front state, torus decomposition, adaptivity, cache reuse, stage-lineage fixtures, or memory telemetry.

## Required compile-valid contracts

Add or strengthen contracts that execute in P5-TB27:

1. every valid directed halfedge has one cell after cycle audit;
2. planar fixture has one intended exterior cycle, valid interior cells, Euler `1`, and bounded area error;
3. disconnected source components each retain complete cycle/cell inventories;
4. interior hard rail splits wedges but does not increase exterior-cycle count;
5. source-boundary rail does classify the exterior cycle;
6. valid periodic cylinder has no unassigned halfedges and no `invalid-cell cell=-1` evidence;
7. cylinder seam-start, source-row, and whole-orientation permutations preserve successor/cell hashes;
8. singularity fan yields the intended three center sectors and preserves singularity-touch evidence;
9. non-disk/patch-candidate fixture remains represented rather than being omitted;
10. adjacent local-sheet charts remain connected through R1 exact adjacency;
11. disconnected close sheets and different components never share a wedge or cycle;
12. nonmanifold source-edge sectors still fail with the intended typed incidence evidence;
13. intentionally repeated-node/repeated-edge cycles are rejected and never decomposed;
14. an invalid sector cannot leave a partially assigned valid arrangement.

Do not weaken expected topology. Correct a test fixture only when it cannot instantiate its stated scenario.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list, or discovery command. Initialize detailed logging before fallible work and always package exact source, target hashes, fixtures, submodule records, source status, and reviewed patch hash.

## P5-TB27 runtime gate

The next artifact-only turn must require:

- source-chart **11/11**, Phase 22 **6/6**, recovery **9/9**, and feature/barrier **8/8** remain clean;
- all directed-incidence and new cell-inventory contracts pass;
- Milestone D **7/7**;
- Phase 16 and Phase 17 return to a clean pre-R2 baseline plus new tests;
- Phase 14–18 is clean;
- seam, close sheets, and cylinder retain nonzero valid arrangement cell inventories;
- no valid halfedge has `cell == -1`;
- analytic failures either improve or move to a later typed R3 completion producer;
- Phase 20 does not regress;
- complete suite terminates;
- bunny time and memory are measured without treating faster failure as success.

Advance to R3 only after runtime proves complete valid wedge/cycle/cell ownership and the earliest remaining failures are genuinely completion-topology failures.

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
