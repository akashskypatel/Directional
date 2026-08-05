# Milestone G P5-R2E4 Boundary-Node Rotational-System Code + Build Plan

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code + Build, compile-only

## Purpose

Replace the R2E3 two-target boundary-node transposition with a complete authoritative local rotational-system construction.

P5-TB31 proves that target cardinality alone is insufficient:

- planar passes predecessor bijection but fails `RepeatedEdgeCycle`;
- hard-rail endpoints fail `BoundaryLocalPermutationConflict`;
- open cylinder publishes a `NonDiskCell`;
- orientation-invariant boundary incidence hashing now passes and must be preserved.

The next producer must construct every affected node's successor mapping from canonical cyclic ray order and explicit exterior/interior sectors before any global orbit extraction.

## Scope

Modify only:

- `include/directional/geometry/SurfaceArrangement.h` when typed local-rotation evidence is required;
- `src/geometry/SurfaceArrangement.cpp`;
- focused arrangement and Milestone D tests;
- turn documentation and handoff.

Do not modify FlowRep, tracing semantics, simplification, completion, optimizer, cache, lineage, fallback/recovery, memory accounting, or bunny intrinsic-fan embedding.

## Required implementation

### 1. Canonical node-local ray inventory

For every arrangement node, build one deterministic inventory of all incident directed rays:

- incoming halfedge;
- outgoing twin;
- canonical node/fan class;
- source face, component, sheet, and wedge identity;
- hard-rail/barrier membership;
- authoritative source-boundary loop and side when present;
- canonical tangent/parameter ordering evidence.

Order must be independent of source-face row order and whole-mesh orientation reversal. Do not use halfedge ID as the semantic order; IDs may be a final deterministic tie-break only after canonical evidence is equal.

### 2. Explicit boundary sector identification

At a canonical manifold source-boundary node, identify:

- the authoritative exterior incoming boundary ray;
- the authoritative exterior outgoing boundary ray;
- the complementary interior boundary rays;
- all hard-rail and trace rays that partition the interior fan;
- the exact cyclic sectors between adjacent rays.

There must be exactly one exterior sector per authoritative boundary-loop occurrence. Pinched source-vertex fans, close sheets, and disconnected components remain separate occurrences.

Fail closed on missing, duplicate, or contradictory boundary-sector evidence. Add a typed `BoundaryRotationalSystemConflict` failure when existing typed evidence is insufficient.

### 3. Rebuild the complete local successor map

For every affected node, discard the generic local successor assignments and reconstruct **all** incoming-to-outgoing mappings at that node in one transaction:

- the exterior incoming maps to the authoritative exterior outgoing;
- each interior incoming maps to the outgoing ray immediately preceding it in the canonical interior rotational order for its wedge/sector;
- hard rails remain separators and produce distinct bounded sectors;
- no mapping crosses components, sheets, pinched fans, or barriers;
- every incoming is assigned once;
- every outgoing is targeted once;
- every mapping is endpoint-continuous.

Do not implement this as a sequence of swaps or a missing-target repair. The result must be derived directly from the rotational system.

### 4. Transactional audit and publication

Before writing `halfedge.next`:

1. audit every affected node's complete local bijection;
2. audit every unaffected node's intrinsic mapping;
3. audit global endpoint continuity and predecessor multiplicity;
4. audit that authoritative exterior mappings form exactly one ordered cycle per source boundary loop;
5. audit that interior sector mappings do not contain the exterior boundary cycle;
6. commit the candidate map once;
7. run the existing orbit and disk audits unchanged.

Any failure clears pending publication and leaves no partial cells or successor state.

### 5. Preserve canonical incidence identity

Retain R2E3's orientation-invariant paired boundary-twin identity. The rotational-system correction must preserve:

- whole-orientation directed-incidence hash equality;
- source-face row-order invariance;
- boundary incidence represented in hashes rather than omitted;
- canonical edge low/high interval identity.

### 6. No validator weakening

Do not weaken or bypass:

- `RepeatedEdgeCycle`;
- `RepeatedNodeCycle`;
- `NonDiskCell`;
- predecessor multiplicity;
- boundary-loop owner cardinality;
- structural Euler validation.

The planar and cylinder cases must close naturally under the corrected successor producer.

## Required tests

Add or strengthen generalized tests that prove:

1. planar triangle with two boundary-ending traces has a complete local rotational system, no repeated edge, one exterior cell, full bounded area, and Euler one;
2. an interior hard rail ending at two boundary vertices creates two bounded cells and one exterior cycle without local permutation conflict;
3. multiple interior rays ending at one boundary vertex preserve canonical cyclic order and create one cell per adjacent interior sector;
4. open cylinder creates two exterior cycles, only disk bounded cells, complete ownership, and Euler zero;
5. pinched boundary fans at one source vertex remain separate rotational systems;
6. disconnected close sheets at coincident positions remain separate;
7. source-face row permutation preserves node-local mappings and hashes;
8. whole orientation reversal preserves node-local mappings and hashes;
9. missing/duplicate/contradictory sector evidence fails closed with typed rotational-system evidence;
10. all prior nonmanifold, nested multi-boundary, bridge, support-only, ownership-registry, and orientation tests remain passing.

Tests must inspect semantic topology and local successor mappings, not only counters.

## Compile-only gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no test, benchmark, CLI, GUI, custom mesh, help/list/discovery command, or generated project binary during this Code + Build turn.

## Artifact requirements

Produce:

- exact source snapshot;
- compiled test and benchmark binaries;
- the two required static libraries;
- all packaged fixtures;
- complete configure/build/activity logs;
- target hashes;
- recursive checksum manifest generated outside the package and excluding itself;
- exact workflow/source/diff authority records.

## Mandatory hygiene

At turn start and end:

- remove superseded workflows, triggers, patch payloads, patch READMEs, transfer files, and temporary build artifacts;
- retain only the base workflow plus one bounded active workflow while remote compilation runs;
- remove the bounded workflow and payload immediately after artifact upload;
- verify final branch and cleaned validation source contain only base workflows and zero payloads.

After all documentation commits, post the required new final handoff comment on PR #8. It must be the last repository write of the turn.

## Exit criteria

The turn closes only when:

- the coherent source/test patch is committed and pushed;
- all four approved targets compile successfully;
- no project binary was executed;
- artifact authority and checksums verify;
- the bounded workflow and payloads are removed;
- the handoff points to an artifact-only P5-TB32 validation plan;
- PR #8 remains open, draft, and unmerged;
- the final PR handoff comment is posted last.
