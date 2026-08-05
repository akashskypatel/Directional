# Milestone G P5-R2E9 Canonical Wrap-Sector and Rail-Orbit Chart Publication Code/Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build, compile-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`

## Purpose

Close the two coherent topology producers left by P5-TB36:

1. planar direct incidence now publishes, but the canonical cyclic-wrap interior sector is absent and the published cells have Euler characteristic `0` instead of `1`;
2. interior hard-rail incidence, ownership, disk, loop, and Euler authority pass, but the accepted rail-side chart root is not carried through to authoritative bounded-cell embedding support.

Do not address cylinder, bunny, FlowRep, completion, or Phase 17 implementation in this turn.

## Required reading

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Report.md`
5. `benchmark-results/p5-tb36-summary.json`
6. `.agents/Directional/REORIENTATION_PLAN.md`
7. `.agents/Directional/DESIGN.md`
8. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`

## Allowed scope

Modify only:

- `include/directional/geometry/SurfaceArrangement.h` when derived diagnostics or typed evidence are required;
- `src/geometry/SurfaceArrangement.cpp`;
- focused Phase 16 and Milestone D arrangement tests when semantic proof must be strengthened;
- turn reports, TODOs, and handoff documentation.

Do not modify tracing, FlowRep selection/simplification, Phase 17, patch completion, optimizer, cache, fallback/recovery, memory accounting, production fixtures, or bunny singularity-fan logic.

## Required implementation

### 1. Preserve accepted incidence branches

Retain without semantic weakening:

- R2E5 degree-two exterior/interior mapping;
- R2E6 genuine three-spoke/four-bounded-disk partition;
- source-row and whole-orientation canonical identity;
- exact source-boundary loop continuation;
- predecessor, repeated-cycle, disk, ownership, Euler, boundary-loop, orientation, and area validators;
- all P5-TB36 Phase 17 restoration behavior.

### 2. Enumerate canonical cyclic fan pairs directly

For every affected boundary node with three or more outgoing rays:

1. use each authoritative R1 `orderedWedges` fan's canonical cyclic ray order as the primary inventory;
2. enumerate every adjacent pair `(ray[i], ray[(i+1) mod n])`, including vector wrap, before chart filtering;
3. convert the pair to the directed relation required by the DCEL convention:
   - incoming twin of the source ray;
   - source outgoing ray;
   - target outgoing ray;
   - canonical fan identity;
   - exact corner witness identity;
4. resolve the pair to exactly one source face/chart corner that supports both rays and whose intrinsic orientation agrees with the fan order;
5. canonicalize only semantically identical records;
6. reject non-identical duplicate incoming or target claims transactionally;
7. remove exactly the independently proven exterior `(incoming,target)` relation once;
8. require every remaining local incoming and outgoing target exactly once.

Do not derive completeness by iterating only consecutive entries in a chart-filtered angle list. Chart-local geometry is evidence that a canonical pair belongs to a corner; it must not define or truncate the cyclic pair inventory.

Do not use halfedge ID, insertion order, frequency, count-majority, or subset search to select among competing records.

### 3. Prove exterior exclusion and planar Euler closure

The exact source-boundary loop remains independent exterior authority.

Before publication, require:

- one and only one exterior continuation at the node;
- the exterior relation matches the source loop and canonical boundary segment;
- the corresponding canonical fan pair is excluded once;
- every other cyclic adjacent pair is interior;
- at least one accepted wrap pair where the topology requires it;
- complete predecessor/successor multiplicity one;
- predicted bounded cycle inventory consistent with the source disk.

After publication, unchanged validators must naturally report for the planar fixture:

- incidence valid;
- positive derived direct-sector and wrap-sector evidence;
- no repeated node/edge cycle;
- one exterior cell;
- Euler characteristic `1`;
- valid embedding, disk, boundary loops, orientation, area, and aggregate topology.

Add derived direct-sector/exterior-exclusion counters only when they reflect accepted records after the complete audit.

### 4. Carry hard-rail chart roots through complete bounded orbits

The exact incident source-face corner remains rail-side authority.

For each accepted hard-rail side:

1. assign the selected chart root to the directed sector relation;
2. traverse the complete predicted bounded successor orbit before DCEL publication;
3. require every directed halfedge on that orbit to admit the selected root through the source-chart transition graph;
4. reject any orbit that changes roots, loses root support, enters exterior incidence, crosses a hard barrier, or fails to close at its seed;
5. store the accepted root as authoritative directed-orbit support;
6. when bounded cells are materialized, construct their authoritative `sourceCharts`/ownership embedding support from the accepted orbit root;
7. retain complete original halfedge provenance separately for diagnostics and source coverage;
8. require the two hard-rail twins' bounded cells to use the two distinct incident roots.

Do not weaken the existing embedding validator and do not hide multi-root provenance. The correction is to distinguish complete provenance from the one chart root that authoritatively embeds a directed bounded orbit.

### 5. Transactional publication

Publish `halfedge.next`, successor wedge, and authoritative chart support only after all affected nodes and all predicted hard-rail orbits pass:

- exact cyclic fan-pair inventory;
- exterior exclusion once;
- incoming/target bijection;
- endpoint continuity;
- canonical corner identity;
- one selected root per bounded orbit;
- distinct opposite rail roots;
- global predecessor multiplicity one.

On any failure, publish none of the candidate incidence or chart-support relation and return the existing typed failure with exact competing identities.

## Required tests

Strengthen existing semantic tests without fixture-specific IDs:

1. **Planar fixture**
   - direct canonical pair inventory is complete;
   - exact exterior exclusion count is one;
   - accepted cyclic-wrap interior sector count is positive;
   - one exterior plus the expected bounded disk inventory;
   - Euler `1` and complete unchanged topology validity.

2. **Degree-two boundary fixture**
   - mapping and one-exterior/one-bounded-disk result unchanged.

3. **Genuine higher-valence fixture**
   - one exterior plus four bounded disks unchanged;
   - row order and orientation invariance unchanged.

4. **Interior hard rail**
   - two exact incident corner roots;
   - one authoritative root per bounded orbit;
   - opposite roots distinct;
   - one exterior plus two bounded disks;
   - embedding, orientation, disk, loop, Euler, ownership, area, and aggregate topology valid.

5. **Malformed authority**
   - missing wrap corner, duplicate corner claim, wrong-root halfedge, cross-fan rail side, or orbit root change fails typed and transactionally.

6. Preserve pinched fans, disconnected close sheets, bridge/support constraints, nested non-disk rejection, nonmanifold rejection, cylinder's independent classification, and bunny's independent classification.

Do not modify Phase 17 tests. Their **26/26** result must be preserved naturally in P5-TB37.

## Compile-only gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no test, benchmark, custom mesh, CLI, GUI, help/list/discovery command, or generated project binary.

## Artifact requirements

Package:

- exact pushed source snapshot;
- `directional_phase1_tests` and `directional_benchmarks`;
- `libdirectional_core.a` and `libdirectional_pipeline.a`;
- all executable-relative fixtures;
- configure/build/activity logs;
- target hashes;
- recursive checksum manifest excluding itself;
- source/workflow/diff authority and recursive submodule records.

## Hygiene

At start and end:

- inspect and remove stale bounded workflows, triggers, payloads, transfer files, and generated build artifacts;
- retain only approved base workflows plus at most one active bounded workflow during compilation;
- remove the bounded workflow and all temporary inputs immediately after artifact publication;
- review `.agents` and `benchmark-results`, retaining only durable authority and the minimum current turn chain;
- verify all retained document references exist;
- preserve every mandatory handoff instruction materially unchanged.

## End-of-turn outputs

- P5-R2E9 Code + Build report;
- P5-TB37 artifact-only validation plan;
- machine-readable source/package summary;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- updated PR body;
- a new top-level PR #8 handoff comment as the final repository write;
- PR remains open, draft, and unmerged.

## Prohibitions

- no validator weakening;
- no generic successor choice as complete sector authority;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
