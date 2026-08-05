# Milestone G P5-R2E3 Boundary-Node Permutation Splice Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code changes + compile-only build

## Purpose

Replace R2E2's isolated exterior-`next` overwrite with a complete node-local exterior/interior permutation splice, establish authoritative boundary-vertex identity across hard-rail endpoints, and restore whole-mesh orientation-invariant incidence hashing. Do not begin singularity-fan R2F or R3.

## Runtime authority

Use P5-TB30 evidence from exact source `f5305ade5bf5360df36b681d135e5299322f5fdb`, artifact `8916209271`.

Confirmed results:

- planar disk fails `IncompletePermutation`;
- interior hard rail fails `BoundaryContinuationDiscontinuity`;
- cylinder publication clears and leaves `cell == -1`;
- orientation reversal produces unequal directed-incidence hashes;
- complete suite regresses to **594/623**;
- no previous failure closes;
- bunny fan remains independent and deferred.

## Earliest producer

R2E2 first constructs the generic successor permutation and then overwrites only exterior halfedge outgoing successors. This can duplicate predecessors at new targets and orphan superseded targets. At hard-rail endpoints, adjacent source-boundary subsegments can also use different arrangement node scopes even though they represent one authoritative manifold boundary vertex.

The correction must construct the complete boundary-node successor partition before global orbit audit. Do not patch missing predecessors after the fact and do not merge cells after extraction.

## Scope

### 1. Retain a transactional candidate successor map

- Preserve the intrinsic generic successor map as input evidence.
- Build a separate complete `candidateNext` array.
- Never mutate `complex.halfedges[*].next` incrementally while boundary validation is incomplete.
- Commit all successors only after every node-local and global audit passes.
- On failure, retain typed evidence and publish no partial cells.

### 2. Establish authoritative boundary-vertex classes

For each manifold source-boundary vertex, derive a canonical class from:

- source component;
- canonical source vertex identity;
- authoritative source-boundary loop membership;
- local source sheet/ownership class where needed to keep pinched or disconnected sheets separate.

Use that class to make adjacent boundary-rail endpoints share one arrangement node across source-face and hard-rail fan scopes. A hard rail may partition the interior wedge but must not duplicate the exterior boundary vertex.

Requirements:

- do not merge geometrically coincident close sheets;
- do not merge distinct source components;
- preserve pinched source-vertex fan separation;
- fail closed on incompatible boundary-loop or ownership-class aliases;
- keep raw halfedge endpoint continuity (`current.to == next.from`).

### 3. Rebuild the complete node-local permutation

At every boundary node:

1. inventory all incoming halfedges and outgoing rays;
2. identify the two authoritative source-boundary directions and the exterior sector;
3. assign exterior incoming boundary halfedge to the next exterior outgoing boundary halfedge from ordered source-loop topology;
4. construct the complementary source-interior successor cycle from the remaining incoming/outgoing rays in intrinsic wedge order;
5. ensure hard-rail rays split bounded interior regions without splitting the exterior continuation;
6. require each incoming domain and each outgoing target exactly once.

This must produce one node-local bijection. Do not use an arbitrary global target swap or count-based repair.

### 4. Use canonical edge parameters, not directed provenance sign, as identity

- Derive subsegment intervals from canonical source-edge parameterization already used by cross-face splitting.
- Determine operational loop direction by comparing canonical endpoints with the ordered loop edge record.
- Treat `sourceT0/sourceT1` as provenance, not orientation-independent identity.
- Preserve exact gap/overlap auditing using canonical low/high intervals.
- Verify whole-mesh orientation reversal and source-face row permutation do not change segment identity.

### 5. Audit globally once

After all node-local maps are complete:

- require every halfedge has one valid successor;
- require every halfedge has exactly one predecessor;
- require endpoint continuity for every successor;
- require every exterior successor remains in its authoritative loop;
- require all halfedges enter exactly one audited orbit;
- commit cell IDs transactionally only after these checks pass.

Add typed failures for boundary alias conflict or local permutation failure when existing categories are insufficient. Preserve the earliest actionable witness.

### 6. Restore orientation-invariant incidence hashing

Boundary-edge twins must be encoded as one canonical boundary-incidence object or as a paired record whose exterior/interior roles remain invariant under whole-mesh orientation reversal.

Do not independently hash one direction through the authoritative path and its twin through an operational generic path. Do not remove boundary incidence from the hash merely to satisfy the test.

### 7. Preserve structural Euler and prior closures

Do not change structural Euler formulas, simplification, completion, FlowRep, optimizer, cache, lineage, or fallback behavior.

Preserve:

- source-chart R1 authority;
- nonmanifold source-edge rejection;
- nested explicit multi-boundary representation;
- dangling bridge and support-only ownership;
- disconnected close-sheet ownership;
- source-face row-order invariance;
- complete transactional ownership;
- Phase 18 **57/57**.

Keep the existing Phase 15 and Phase 17 failures out of scope unless static dependency analysis proves the boundary permutation directly supplies their invalid input.

## Required generalized contracts

Add or strengthen real-topology tests for:

1. planar disk with multiple boundary-ending traces: complete permutation, one exterior, full area, Euler one;
2. interior hard rail ending at boundary vertices: one raw boundary node per authoritative vertex, one exterior, intended bounded partition;
3. open cylinder: two exterior cycles, nonzero bounded cells, Euler zero, no `cell == -1`;
4. a boundary node with multiple interior rays: exterior and interior local successor partitions are independently bijective;
5. canonical boundary subsegments remain identical under face-row permutation and whole orientation reversal;
6. whole orientation reversal restores equal directed-incidence hashes without weakening topology assertions;
7. close sheets and pinched fans retain distinct canonical node classes;
8. coverage gaps, overlaps, duplicates, alias conflicts, and local permutation conflicts fail closed with typed evidence;
9. all R2C/R2D/R2E passing contracts remain passing.

Tests must assert structural counts and canonical identities, not fixture-specific cell or halfedge IDs.

## Expected files

Prefer the smallest coherent set centered on:

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`;
- turn documentation and handoff.

Do not refactor unrelated subsystems.

## Mandatory Code + Build boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no test, benchmark, custom mesh, project binary, help/list/discovery command, or generated executable.

Remove stale workflows, markers, patch payloads, transfer files, and build artifacts at turn start and end. Verify the recursive manifest excludes itself. Always upload separate detailed logs.

## Next validation acceptance

The artifact-only Test + Benchmark turn must require:

- source-chart **11/11**;
- source validator **6/6**;
- recovery authority **9/9**;
- feature/barrier **8/8**;
- R2 focused restores at least **13/14**, with only bunny allowed to remain;
- Milestone D **7/7**;
- Phase 16 at least **44/45**, with only bunny allowed to remain;
- planar disk, hard rail, and cylinder structural contracts all pass;
- no valid halfedge has `cell == -1`;
- whole-orientation hash equality restored;
- Phase 18 remains **57/57**;
- seam, close sheets, and cylinder retain nonzero valid arrangement inventories;
- complete suite has no R2E3 regression.

Advance to R2F only after every boundary/permutation/Euler gate closes. Advance to R3 only after all R2 gates close.

## End-of-turn PR comment requirement

After all documentation commits, post a new final comment on PR #8 containing the exact evidence commit, turn result, remaining gates, authoritative next plan, and documentation head.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no fallback or recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cell merging or cycle decomposition;
- no timeout-as-correctness.
