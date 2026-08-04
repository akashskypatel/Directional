# Milestone G P5 R0–R1 Reoriented Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Authority

This is the focused execution slice for the next turn. It is derived from:

1. `.agents/Directional/DESIGN.md`;
2. `.agents/Directional/REORIENTATION_PLAN.md`;
3. `.agents/Directional/Milestone_G_P5_TB22_Artifact_Only_Test_Benchmark_Report.md`;
4. `benchmark-results/p5-tb22-summary.json`.

The earlier `.agents/Directional/Milestone_G_P5_Post_TB22_Producer_Correction_Code_Build_Plan.md` remains useful as a diagnosis of individual failures, but its broad CB143–CB150 execution order is superseded by the reorientation sequence.

P5-TB22 remains the runtime baseline:

- exact tested source `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- artifact `8894034755`;
- complete suite terminates at **585/600** in **103.441 s**;
- direct production remains **0/8**;
- plane, multi-face seam, and close sheets produce partial output and then fail `LocalSheetMismatch`;
- cylinder remains non-disk;
- existing completion rotations/reversals remain geometrically invalid;
- bounded repeated-node alternatives exhaust without a valid commit.

## Reorientation decision

Do not attempt CB143 through CB150 as one implementation turn.

The immediate critical path is:

1. **R0 — freeze the repair surface and make recovery non-authoritative.**
2. **R1 — construct canonical source-entity chart transitions.**
3. Validate R1 independently before starting directed-incidence reconstruction.

Cache reuse, injected-stage lineage, memory coverage, general FlowRep simplification, and additional ownership diagnostics are deferred until the direct constructive path succeeds on a substantial analytic subset.

## R0 — Freeze the repair surface

### Goals

Preserve the useful deterministic diagnostics while stopping further downstream hardening from obscuring producer work.

### Required changes

- Preserve all current typed failure codes, structural hashes, exact rollback, and fail-closed behavior.
- Add no new ownership/failure classification unless an existing typed category cannot represent the earliest producer.
- Make direct `SurfaceCells` production use:
  - `fallbackPolicy=Fail`;
  - source-grid recovery disabled;
  - no legacy execution.
- Change `allowSourceGridRecovery` to default `false`, or expose recovery through a distinct backend/output origin that cannot satisfy direct surface-paving acceptance.
- Keep the P5-TB22 deterministic failure signatures as regression fixtures.
- Do not modify cache reuse, memory telemetry, or injected-stage lineage in this turn.

### Required compile-time/test contracts

Add or update tests so they compile and express:

- default direct requests cannot execute source-grid recovery;
- explicit recovery, when enabled, reports a distinct non-authoritative origin;
- fallback `Fail` never runs legacy output;
- existing P5-TB22 failure diagnostics remain representable without new categories.

Do not execute the tests during this code/build turn.

## R1 — Canonical source-entity transition graph

### Problem

The current stitch resolver intersects literal source-face support. One intrinsic source vertex or edge can be represented in different adjacent source-face charts, causing valid shared output to fail with `LocalSheetMismatch`.

Authoritative P5-TB22 producers:

- plane: 12 quads, cell 4 / face 7;
- multi-face seam: 24 quads, cell 2 / face 15;
- close sheets: 34 quads, cell 3 / face 13.

### Required data model

Introduce a source-chart transition layer with concepts equivalent to:

```cpp
struct SourceChartId {
    int component;
    int localSheet;
    int sourceFace;
};

struct SourceEntityId {
    enum class Kind { Vertex, Edge, FaceInterior } kind;
    int sourceIndex;
    int intrinsicFan;
};

struct SourceChartTransition {
    SourceChartId from;
    SourceChartId to;
    SourceEntityId sharedEntity;
    int orientation;
    BarycentricTransition map;
};
```

Names may differ, but the semantics must remain explicit and source-authoritative.

### Construction algorithm

```text
BUILD_SOURCE_ENTITY_TRANSITIONS(mesh, labels, hardRails):
    create one chart node for each
        (component, localSheet, sourceFace)

    for each manifold source edge:
        if component/sheet labels agree and no hard barrier separates it:
            create orientation-aware transitions
            record exact endpoint permutation
            record barycentric edge map

    for each source vertex:
        partition incident face charts into intrinsic fans
        split fans at:
            source boundaries
            component boundaries
            local-sheet boundaries
            nonmanifold sectors
            hard feature rails

    for every connected chart/entity class:
        choose a deterministic canonical representative
        validate transition composition around every cycle

    reject inconsistent transition cycles
    return graph
```

### Integration requirements

Use the graph when resolving:

- arrangement-node identity;
- completion generated-vertex provenance;
- shared completed vertices and edges;
- stitch keys and global output assembly;
- validation diagnostics for source-chart disagreement.

World-space proximity and source-triangle pairing must not participate in identity.

When several provenance records resolve to the same intrinsic source vertex or source edge:

1. map each record through exact chart transitions;
2. choose a canonical representative chart deterministically;
3. rebind barycentric coordinates through the transition map;
4. retain the complete provenance set for validation.

Disconnected or opposite close sheets must remain in different transition components even when positions are nearly coincident.

### Failure semantics

When reconciliation fails, report the complete conflicting set:

- component and sheet;
- source face;
- canonical source entity candidate;
- transition path/hash;
- orientation;
- barycentric coordinates;
- owning patch/cell/output vertex or edge.

Reuse an existing typed source-chart failure category unless it cannot represent this evidence.

## Required source tests to add or correct

Tests must compile and test their intended topology rather than pass synthetically.

1. Adjacent source faces sharing a source edge reconcile to one intrinsic edge identity.
2. Adjacent source faces sharing only a source vertex reconcile through the correct intrinsic fan.
3. A hard rail splits otherwise adjacent chart transitions.
4. A nonmanifold or disconnected vertex fan remains separated.
5. Close parallel sheets with near-identical positions remain distinct.
6. Face-row permutation preserves canonical transition and output hashes.
7. Source orientation reversal produces the canonical inverse transition.
8. Conflicting transition composition fails before global quad commit and preserves exact rollback.
9. Plane, seam, and close-sheet reduced fixtures no longer depend on literal common-face intersection.

The following are runtime gates for P5-TB23, not compile-turn claims:

- plane completes directly;
- multi-face seam completes directly;
- close sheets complete directly without leakage;
- disconnected close sheets remain separate;
- no `LocalSheetMismatch` remains in those fixtures;
- permutation hashes remain deterministic.

## Explicit non-goals for this turn

Do not implement or modify:

- R2 directed wedge/incidence reconstruction;
- R3 topology-distinct completion catalog;
- R4 repeated-node wedge splicing;
- R5 explicit lattice phase/front events;
- torus descriptor/decomposition;
- adaptive 2:1 transitions;
- completion-cache reuse;
- injected optimization/validation lineage fixtures;
- same-sample memory coverage;
- general FlowRep simplification;
- bunny-specific behavior.

Do not add more completion rotations/reversals or more single-interface exclusions.

## Compile/package boundary

Use a clean Ninja Release build with shallow recursive submodules.

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary, test, benchmark, custom mesh, help/list, discovery, or generated executable.

The workflow must initialize detailed activity logging before fallible work and upload the complete log artifact regardless of success or failure.

Package:

- exact implementation/source commit;
- empty source status;
- recursive checksum manifest;
- 26 fixtures;
- nine recursive submodule records;
- built-target hashes;
- complete configure/build/activity logs.

## Next runtime turn

P5-TB23 must execute the packaged artifact directly without configure, rebuild, relink, patch, regeneration, or source modification.

Run focused R0/R1 contracts first. Then run only the analytic scopes needed to detect regressions and confirm normal termination. Do not run the full bunny matrix merely because R1 changed; bunny remains deferred until the causal analytic producers are valid.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
