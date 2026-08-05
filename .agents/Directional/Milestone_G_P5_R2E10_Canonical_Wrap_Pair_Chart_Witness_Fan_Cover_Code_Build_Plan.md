# Milestone G P5-R2E10 Canonical Wrap-Pair Chart-Witness and Unique Boundary Fan-Cover Code/Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`

## Purpose

Correct the earliest regression exposed by P5-TB37: R2E9 rejects both the planar and interior hard-rail fixtures with `BoundaryFanSectorCoverConflict` before successor publication.

R2E10 must retain the R2E9 architectural requirements—canonical fan-pair inventory before chart filtering and complete hard-rail orbit-root authority—while restoring the valid R2E8 incidence cover and the six Phase 17 natural restorations.

R2 remains open. Do not advance to R2F or R3.

## P5-TB37 authority

- exact tested source: `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c`;
- artifact: `8946700183`;
- artifact SHA-256: `bae182ef1e3e5fbbc9fff25ea60a56821e31e4e6fe81787137cdac58f30c6a3a`;
- source chart + validator: **17/17**;
- feature/barrier: **8/8**;
- recovery authority: **9/9**;
- R2 focused: **13/16**;
- planar: `BoundaryFanSectorCoverConflict` at the first incidence assertion;
- hard rail: `BoundaryFanSectorCoverConflict` at the first incidence assertion;
- Phase 17: **20/26**, losing all six R2E8 natural restorations;
- complete suite: **597/625**, 28 failures;
- direct production remains open; bunny remains deterministic and fail-closed.

The failure count for R2 focused, Milestone D, and Phase 16 is numerically unchanged, but the planar and hard-rail failures move earlier than P5-TB36. This is a producer regression, not a preserved status.

## Source diagnosis

The active boundary-node producer now:

1. enumerates every cyclic adjacent pair for every `nodeWedges` fan identity;
2. collects exact chart-corner candidates only when both rays occur in one chart and satisfy the chart-angle order;
3. excludes the exact exterior pair by directed halfedge identity;
4. requires exactly one candidate for every remaining canonical pair;
5. then requires the union of all emitted sectors to be a one-to-one incoming/target cover.

P5-TB37 proves this combined inventory is not currently a valid cover on the two target fixtures. The runtime evidence does not distinguish whether the rejected pair has zero candidates, multiple candidates, an equivalent duplicate fan identity, or a mismatched exterior relation. R2E10 must resolve those cases from authoritative records rather than weakening the fail-closed gate.

## Required implementation

### 1. Construct one node-level canonical pair inventory

Build canonical pair records before chart filtering, but do not treat independent fan-identity vectors as unrelated complete covers.

For each boundary node:

1. derive the exact exterior directed relation:
   - incoming: authoritative exterior incoming halfedge;
   - source ray: its twin;
   - target ray: authoritative exterior outgoing halfedge;
2. enumerate cyclic adjacent R1 pairs for each authoritative source-entity fan;
3. normalize each record by the directed incidence key `(incoming, sourceRay, target)`;
4. when multiple equivalent fan identities produce the same directed key, require their canonical entity and transition-component evidence to agree, retain all agreeing identities as provenance, and publish one pair record;
5. fail closed on conflicting identities, roots, or source entities;
6. prove that the exact exterior relation occurs once in the normalized node inventory.

This is deterministic equivalence collapse, not count-, order-, or frequency-based selection. Do not search subsets of fan records.

### 2. Resolve wrap pairs in one continuous chart-corner interval

For each non-exterior canonical pair:

1. resolve every chart that supports both rays;
2. map the two ray directions into the same unwrapped exact chart-corner interval;
3. for a canonical wrap pair, apply the required `2*pi` lift to the source angle only when needed to represent the same oriented corner interval;
4. require the oriented span to be positive and contained in the exact chart corner;
5. require no third ray from that canonical fan to lie strictly inside the candidate span;
6. deduplicate identical chart/root witnesses;
7. require exactly one agreeing chart/root witness.

Do not define canonical adjacency from chart-filtered ray lists. Charts validate an existing canonical pair; they do not create or remove pairs.

### 3. Publish only the complete normalized cover

Before modifying `candidateNext`, prove:

- exactly one normalized exterior pair;
- exactly one non-exterior pair for every remaining local incoming relation;
- target multiplicity exactly one;
- complete incoming/target bijection;
- no pair duplicates the exterior incoming or exterior target;
- all selected chart roots are valid transition components;
- hard-rail separator sides retain two distinct incident roots.

Only then publish successor relations, chart roots, and derived diagnostics.

### 4. Preserve hard-rail orbit-root authority

Keep the R2E9 complete-orbit audit and authoritative root materialization. Do not publish a root from a partial orbit.

After the node-level cover succeeds, each hard-rail bounded orbit must close, every orbit halfedge must carry the same selected root, opposite rail sides must retain distinct roots, no orbit may enter the exterior or cross a hard barrier, and full provenance remains separate from the authoritative embedding root.

### 5. Focused contracts

Update only the focused arrangement contracts needed to express the producer result.

The planar test must require: valid incidence, positive canonical pair inventory, one exterior exclusion per affected node, positive accepted cyclic-wrap interior count, complete local bijection, no repeated node or edge cycle, one exterior and expected bounded disk inventory, Euler characteristic `1`, and valid embedding, disk, loops, orientation, area, ownership, and aggregate topology.

The hard-rail test must require: valid incidence, two exact incident roots, one complete root per bounded orbit, distinct opposite roots, valid embedding and aggregate topology, and preserved one-exterior/two-bounded cell inventory, disk, loop, Euler, area, orientation, and ownership authority.

Preserve degree-two, genuine four-disk, row-order, whole-orientation, pinched-fan, close-sheet, bridge/support, nested, and nonmanifold contracts.

## Scope constraints

Allowed implementation scope:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` only for strictly derived diagnostics or data already required by the producer;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

Do not modify Phase 17 implementation or tests, cylinder or bunny producers, FlowRep, completion or optimizer, fallback/recovery behavior, source-authoritative validators, fixtures or manifests, or unrelated tests or diagnostics.

Do not restore R2E8 by reverting to chart-local consecutive-list enumeration. Do not weaken `BoundaryFanSectorCoverConflict`, embedding, topology, or ownership validators.

## Verification for the Code + Build turn

1. Apply only the bounded source/test changes above.
3. Verify exact changed-file scope and clean source status before building.
4. Configure Release with `-O2 -DNDEBUGa, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional external solvers disabled.
5. Compile exactly: `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
6. Execute no project binary, test, benchmark, custom mesh, help/list/discovery command, CLI, or GUI.
7. Package the exact pushed source commit, binaries, libraries, logs, checksums, blob authority, and compile-only execution policy.
8. Remove the bounded workflow and temporary payloads after artifact publication.

Runtime acceptance is deferred to the following artifact-only Test + Benchmark turn.

## Acceptance boundary

Compile success does not accept R2E14. The next runtime turn must prove planar valid incidence, positive wrap, Euler `1`, and valid aggregate topology;hard-rail valid incidence, complete distinct orbit roots, valid embedding, and valid aggregate topology; Phase 17 restored to **26/26** without Phase 17 changes; no accepted R2 contract regresses; and no fallback, recovery, arbitrary selection, synthetic counter, or validator weakening masks an invalid result.

PR #8 remains open, draft, and unmerged.
