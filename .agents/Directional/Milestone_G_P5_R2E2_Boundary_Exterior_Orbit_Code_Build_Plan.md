# Milestone G P5-R2E2 Authoritative Boundary-Exterior Successor Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code changes + compile-only build

## Purpose

Close the remaining source-boundary publication producer by constructing exterior successor cycles directly from ordered authoritative source-boundary topology before generic orbit audit. Preserve R2E exact side evidence and structural Euler accounting. Do not begin intrinsic singularity-fan work or R3 completion work.

## Runtime authority

Use P5-TB29 evidence from exact source `de0aa1a58a5861954dc9e14e731e681b5e5feb87`, artifact `8914900872`.

Confirmed unchanged failures:

- planar fixture has no exterior cell, Euler `-1`, and area error `1`;
- interior hard rail fails closed with `BoundaryLoopOwnerCount`;
- open cylinder publication is cleared, leaving `cell == -1` in independent incidence audit;
- seam, close sheets, and cylinder publish zero arrangement cells to completion;
- bunny singularity-fan embedding remains invalid;
- complete suite remains **595/623** with the same 28 failures.

## Earliest producer

R2E classifies already-formed generic successor orbits and then counts raw negative-side records. This is too late. Boundary-ending traces and hard rails can split exterior-side continuation at source-boundary vertices, so one source loop can correspond to zero or multiple raw orbits.

The correction must make source-boundary topology authoritative over the exterior `next` relation before cycle extraction. Do not post-process, merge, or decompose published cells.

## Scope

### 1. Retain ordered canonical source-boundary loops

Extend `SourceBoundaryTopology` to retain, for every loop:

- ordered source vertices;
- ordered source edges;
- deterministic loop identity;
- the incident source face for each boundary edge;
- operational face-oriented direction with source interior on the left;
- canonical orientation-insensitive identity used for hashes and row/reversal invariance.

Requirements:

- every boundary vertex has exactly two incident boundary edges;
- every edge appears in exactly one loop;
- loop ordering is complete and closed;
- source-face row permutation does not change loop identity;
- whole-mesh orientation reversal does not change canonical identity;
- closed source components retain zero loops.

Do not store only unordered edge membership.

### 2. Inventory exact boundary subsegments

For each arrangement halfedge supported by an authoritative source boundary edge, derive:

- source boundary loop ID;
- source edge ID;
- exact edge parameter interval;
- incident source face/chart;
- exterior or interior side;
- start and end canonical boundary nodes.

Use exact source entities, provenance, and barycentric edge coordinates. Do not choose a chart by vote, frequency, or row order.

Fail closed on:

- duplicate coverage of the same directed subinterval;
- gaps in one source-edge interval;
- overlapping nonidentical subintervals;
- inconsistent endpoint nodes;
- contradictory interior/exterior side evidence.

Add typed failures where necessary, for example `BoundaryCoverageGap`, `BoundaryCoverageOverlap`, and `BoundaryContinuationDiscontinuity`.

### 3. Construct the exterior successor relation before orbit audit

For each canonical source boundary loop:

1. collect all exterior-side boundary subsegments;
2. order them by loop edge order and exact edge parameter;
3. require complete one-to-one coverage of the loop;
4. set each exterior halfedge's `next` to the next exterior halfedge in this authoritative sequence;
5. connect across source-boundary vertices using the ordered source loop, independent of interior hard rails or trace wedges;
6. close exactly one exterior successor cycle per source loop.

Interior-side halfedges and all non-boundary halfedges retain the intrinsic directed-wedge successor relation.

This is a pre-audit successor correction, not a post-hoc cell merge. No exterior halfedge may remain in a generic bounded orbit after the authoritative relation is installed.

### 4. Audit and publish transactionally

After the complete successor relation is established:

- audit the full permutation once;
- require every halfedge to appear in exactly one orbit;
- publish exactly one exterior cell per source boundary loop;
- retain exact `sourceBoundarySide == -1` and one authoritative loop ID on each exterior cell;
- publish bounded and support-only cells from the remaining intrinsic orbits;
- ensure every valid halfedge receives exactly one committed cell ID;
- on any failure, clear all cell IDs and report the earliest typed boundary-continuation evidence.

Do not enforce owner count against unaudited raw orbit fragments.

### 5. Preserve structural Euler accounting

Keep the R2E global formula based on:

- arrangement vertices;
- undirected arrangement edges;
- explicit Euler contribution of every bounded area-bearing cell;
- zero contribution from exterior and support-only cells.

Re-evaluate it only after authoritative exterior and bounded inventories publish successfully.

Require:

- planar disk Euler one;
- open cylinder Euler zero;
- nested annular bounded cell contribution zero;
- disconnected components equal source Euler and component counts.

Do not compensate for missing cells with synthetic Euler adjustments.

### 6. Preserve all prior closures

The implementation must retain:

- source-chart R1 authority;
- typed nonmanifold source-edge rejection;
- nested two-boundary `NonDisk` representation;
- dangling bridge ownership;
- isolated support-only ownership;
- deterministic source ownership registry;
- orientation-reversal invariance;
- complete transactional halfedge ownership.

### 7. Keep bunny fan work deferred

Do not change intrinsic singularity-fan ordering unless static dependency analysis proves that the same boundary-exterior successor override is directly involved. The bunny fixture disables inserted boundary rails and currently has no evidence of this dependency.

Prepare a later intrinsic-fan turn only after the boundary producer closes independently.

## Required generalized contracts

Add or strengthen focused tests that construct real topology:

1. a triangle with multiple boundary-ending traces forms one authoritative exterior cycle and complete bounded area;
2. an interior hard rail ending at two boundary vertices does not split the exterior successor cycle;
3. multiple subsegments on one source boundary edge are ordered by exact parameter and close without gaps;
4. an open cylinder forms exactly two exterior cycles and all halfedges receive cells;
5. two disconnected disks form one exterior owner per source loop without cross-component merging;
6. close sheets retain distinct loop identities and ownership classes;
7. a closed source publishes no exterior cycles;
8. boundary coverage gaps, overlaps, duplicate subintervals, and endpoint discontinuities fail closed with typed evidence;
9. source-face row permutation and whole orientation reversal preserve canonical loop identity, successor hashes, exterior ownership, Euler, and topology;
10. all R2C/R2D/R2E passing contracts remain passing.

Do not assert fixture-specific IDs. Tests may assert canonical counts and structural identities derived from their constructed topology.

## Expected files

Prefer the smallest coherent set centered on:

- `include/directional/geometry/SurfaceArrangement.h` for ordered loop records and typed failures;
- `src/geometry/SurfaceArrangement.cpp`;
- deterministic hash consumers only for new authoritative fields;
- focused `SurfaceArrangementPhase16Tests.cpp` and `MilestoneDClosureTests.cpp` contracts;
- turn documentation and handoff.

Do not refactor FlowRep, simplification, completion, cache, lineage, optimizer, or memory subsystems.

## Mandatory working-branch hygiene

At the start and end of this Code + Build turn:

- compare temporary agent resources against `surface_cell_quad` and the current turn;
- remove all superseded workflows, trigger files, patch fragments, patch READMEs, transfer files, and generated build artifacts;
- retain only the base workflow plus the one active bounded workflow/payload while the build runs;
- self-remove the active workflow and payload from the exact compiled source, or remove them immediately in the documentation handoff commit;
- verify the final branch and packaged source contain only base workflows and zero temporary payloads;
- verify the recursive checksum manifest itself before artifact upload and never include the manifest in its own input list.

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
- source validator **6/6**;
- recovery authority **9/9**;
- feature/barrier authority **8/8**;
- graph-dependent remains at least **5/6**, with only the independent bunny fan allowed to remain;
- all boundary-exterior, incidence, bridge, multi-boundary, and ownership contracts pass;
- planar fixture has one exterior cell, Euler one, full area coverage, and valid topology;
- interior hard rail has one exterior cell, two bounded cells, and valid topology;
- cylinder has two exterior cells, nonzero bounded cells, Euler zero, and valid topology;
- no runtime-valid halfedge has `cell == -1`;
- Milestone D closes to **7/7** except only if an independently proven non-boundary producer remains;
- Phase 16 retains only the bunny fan failure at most;
- Phase 17 failures close naturally only when their arrangement inputs become valid;
- Phase 18 remains **57/57**;
- seam, close sheets, and cylinder retain nonzero arrangement inventories;
- Phase 20 does not regress;
- complete suite terminates with measured runtime and memory evidence.

Advance to intrinsic fan work only after all boundary-exterior and Euler gates close. Advance to R3 only after all R2 incidence, topology, ownership, and embedding gates close.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
