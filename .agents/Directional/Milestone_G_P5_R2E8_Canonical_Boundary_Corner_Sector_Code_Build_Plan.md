# Milestone G P5-R2E8 Canonical Boundary Corner-Sector and Rail-Chart Embedding Code/Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build, compile-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`

## Purpose

Close the two coherent boundary-node producers left by P5-TB35:

1. planar single-spoke boundary nodes still fail `BoundaryFanSectorCoverConflict` because R2E7 validates a generic preselected intrinsic successor instead of directly owning every authoritative R1 corner sector;
2. interior hard-rail topology now has correct cell counts, disk/loop/Euler authority, and distinct rail-twin owners, but `embeddingValid` fails because directed rail sides are not proven to remain inside one compatible incident source chart.

Do not address cylinder, bunny, completion, or Phase 17 in this turn.

## Required reading

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB35_Artifact_Only_R2E7_Test_Benchmark_Report.md`
5. `benchmark-results/p5-tb35-summary.json`
6. `.agents/Directional/REORIENTATION_PLAN.md`
7. `.agents/Directional/DESIGN.md`
8. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`

## Allowed scope

Modify only:

- `include/directional/geometry/SurfaceArrangement.h` when typed diagnostics are required;
- `src/geometry/SurfaceArrangement.cpp`;
- focused Phase 16 and Milestone D arrangement tests;
- turn reports, TODOs, and handoff documentation.

Do not modify FlowRep, tracing, Phase 17 simplification, completion, optimizer, cache, lineage, fallback/recovery, memory accounting, or bunny intrinsic-fan logic.

## Required implementation

### 1. Preserve accepted branches exactly

Retain without semantic change:

- R2E5 degree-two exterior/interior mapping;
- R2E6 genuine four-disk higher-valence partition;
- exact ordered exterior-loop continuation;
- source-row and whole-orientation canonical incidence identity;
- existing predecessor, repeated-cycle, disk, ownership, Euler, boundary-loop, orientation, and area validators.

### 2. Build direct canonical R1 corner-sector records

At each affected boundary node with three or more outgoing rays:

1. inventory every R1 `orderedWedges` fan independently;
2. enumerate every cyclic adjacent pair in that fan, including vector wrap;
3. convert each adjacent pair into a directed sector record:
   - incoming twin of the source ray;
   - source outgoing ray;
   - target outgoing ray;
   - canonical fan identity;
   - source component, sheet, face, and source entity;
   - exact witness/corner identity;
4. canonicalize and deduplicate only records that are semantically identical;
5. remove exactly the one authoritative exterior `(incoming,target)` pair proven by the source-boundary loop;
6. require every remaining local incoming and outgoing target exactly once.

Do **not** seed the cover from `intrinsicCandidateNext` or `intrinsicSuccessorWedge`. Those arrays may remain evidence for unaffected nodes or consistency checks, but they are not authority for the complete boundary corner-sector inventory.

If two non-identical authoritative sectors claim the same incoming or target, fail transactionally with typed `BoundaryFanSectorCoverConflict` and record the competing fan/corner identities. Do not choose by count, order, frequency, halfedge ID, or subset search.

### 3. Prove the exterior exclusion independently

The exterior sector must remain the exact ordered source-boundary continuation:

- `exteriorIncoming -> exteriorOutgoing`;
- exact source loop and side;
- exact canonical boundary segment identity;
- removed once and only once from the cyclic R1 sector inventory;
- no other vector-wrap sector classified as exterior.

Add a derived count for direct corner sectors and exterior exclusions only if needed for runtime proof. Counters must be derived after complete local audit.

### 4. Derive hard-rail sides from exact incident source-face corners

For every authoritative source hard rail at a boundary node:

1. identify its two incident source faces/charts from R1 transition and rail provenance;
2. in each incident face, identify the exact directed corner adjacent to the rail ray;
3. construct the two rail-side sectors from those face-local corners, not from global `leftScore` sign alone;
4. require each side sector's rail ray and non-rail ray to share the same source component, sheet, face/chart root, and canonical fan identity;
5. require opposite rail sides to use the two distinct incident chart roots;
6. require the two rail twins to enter distinct bounded cells after orbit extraction;
7. before publication, audit that every predicted bounded rail-side orbit has a nonempty common ownership/chart root across all of its halfedge provenance.

A `leftScore` sign may be used only as a consistency check after exact source-face corner authority is established. It must not select the rail side.

If the incident chart/corner evidence is missing, duplicated, cross-sheet, endpoint-discontinuous, or incompatible, fail as `BoundaryFanSectorCoverConflict` without partial publication.

### 5. Transactional local and global audits

Before writing `halfedge.next`:

- one sector per local incoming;
- one use per local outgoing target;
- endpoint continuity;
- exact exterior continuation;
- direct R1 corner identity for every interior sector;
- two exact source-face/chart sides for each hard rail;
- complete common ownership root for predicted bounded rail-side orbits;
- global predecessor multiplicity one.

Publish the full candidate relation only after all audits pass. Run all existing orbit, disk, embedding, ownership, Euler, boundary-loop, orientation, and area validators unchanged.

## Required tests

Strengthen semantic tests without adding fixture-specific IDs:

1. **Planar single-spoke/two-spoke boundary fixture**
   - incidence valid;
   - direct canonical corner-sector count positive;
   - at least one accepted cyclic-wrap interior sector;
   - exact exterior exclusion once;
   - complete local bijection;
   - no repeated cycles;
   - reach topology/Euler validation and preferably close Euler one naturally.

2. **Degree-two boundary fixture**
   - exact existing mapping unchanged;
   - one exterior plus one bounded disk.

3. **Genuine three-spoke fixture**
   - one exterior plus four bounded disks;
   - complete ownership and topology validity.

4. **Interior hard rail**
   - two incident face-local rail-side corner records;
   - two distinct chart roots;
   - at least two side-pair audits across endpoints;
   - one exterior plus two bounded disks;
   - distinct bounded owners for rail twins;
   - embedding, orientation, disk, loop, Euler, ownership, area, and topology valid.

5. **Malformed corner authority**
   - duplicate/missing/cross-fan/wrong-chart rail-side evidence fails typed and transactionally.

6. Preserve source-row permutation, whole-orientation reversal, pinched fans, disconnected close sheets, bridge/support, nested non-disk, and nonmanifold tests.

Do not modify Phase 17 tests. Their restoration must occur naturally in P5-TB36.

## Compile-only gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no test, benchmark, custom mesh, CLI, GUI, help/list/discovery command, or generated binary.

## Artifact requirements

Package:

- exact source snapshot;
- `directional_phase1_tests` and `directional_benchmarks`;
- `libdirectional_core.a` and `libdirectional_pipeline.a`;
- all packaged fixtures;
- configure/build/activity logs;
- target hashes;
- recursive checksum manifest excluding itself;
- source/workflow/diff authority and recursive submodule records.

## Hygiene

At start and end:

- remove stale bounded workflows, triggers, payloads, transfer files, and build artifacts;
- retain only base workflows plus one bounded active workflow/payload during remote compilation;
- remove the bounded workflow and payload immediately after artifact upload;
- final branch and cleaned source must contain only base workflows and zero payloads.

## End-of-turn outputs

- P5-R2E8 Code + Build report;
- P5-TB36 artifact-only validation plan;
- machine-readable summary;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- updated PR body;
- a new top-level PR #8 handoff comment as the final repository write;
- PR remains open, draft, and unmerged.

## Prohibitions

- no validator weakening;
- no generic successor choice as boundary-sector authority;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
