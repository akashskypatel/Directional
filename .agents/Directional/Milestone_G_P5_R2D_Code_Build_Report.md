# Milestone G P5-R2D Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2D authoritative orbit publication and structural cell classification changes are implemented and compile successfully at exact source commit `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`.

This was a Code + Build turn. No test, benchmark, custom mesh, project executable, help/list/discovery command, or generated binary was executed. Runtime acceptance remains open. The next turn is **P5-TB28 artifact-only R2D validation** using artifact `8913777837`.

Do not advance to R3 from compilation alone.

## Source and build authority

- P5-TB27 tested source: `94b86c50c38a849a744f40b0a21c86ed19551769`;
- workflow event commit: `6757e6e98aa90e5b5eefce1db9645fbf523f2650`;
- exact compiled source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`;
- reviewed source patch SHA-256: `c7355a7de3998638f596fa927117584fce274920ca00fcd84f08773bf75935e8`;
- applied commit-diff SHA-256: `de9b6e9e30bf182d73082330d1ef2dbaceca07ffb7a2aa1a938d8e71896319a8`;
- successful run: `30963007513`;
- job: `92170817963`;
- job interval: `2026-08-05T00:21:27Z`–`2026-08-05T00:29:08Z`;
- compiled artifact: `8913777837`, `surface-cell-p5-r2d-github-source-linux-release`;
- artifact SHA-256: `bcb9c6962677f2f638cf6a832eb25d88fdcd2a97e506a1435a7f936d4891416a`;
- workflow-log artifact: `8913778202`, `surface-cell-p5-r2d-workflow-logs-30963007513`;
- workflow-log SHA-256: `04ba6f577b4d76519c365b564762b72844fa5b3f17e71c80bd7d292acf760384`;
- source status: empty;
- recursive checksums: **44/44**;
- packaged files: **45** including the checksum manifest;
- fixture files: **26**;
- recursive submodule records: **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed.

The source archive contains only the base `agent-source-snapshot.yml` workflow and contains no agent patch payload files.

## Implemented R2D behavior

### 1. Source-topology preflight

`SurfaceArrangement` now inventories complete source-edge incidence before accepting a directed arrangement. A source edge with more than two incident faces fails closed with the typed `NonManifoldSourceEdge` incidence result. Partial cells and halfedge ownership are not published after this failure.

### 2. Explicit boundary-cycle structure

`SurfaceArrangementCell` now stores `boundaryCycleOffsets`, allowing one cell to retain multiple directed boundary cycles without flattening them into one invalid walk. A shared range helper validates cycle boundaries and preserves the legacy one-cycle form as `{0}`.

### 3. Orbit audit separated from cell topology

Successor orbits are first represented as pending structural records. Core cycles, bridge support, source-boundary evidence, geometry, and support-only state are evaluated before a `SurfaceArrangementCell` is published. Bridge excursions no longer force polygon geometry to consume a repeated bridge walk as though it were one simple polygon.

### 4. Source-authoritative exterior and nested topology

Source-boundary evidence remains authoritative for exterior classification. Internal negative-orientation cycles with no source-boundary vote are resolved from the complete containment inventory:

- a contained cycle is appended as an explicit inner boundary of the smallest compatible bounded owner;
- the owner receives the derived boundary-component count and Euler characteristic;
- an uncontained cycle is classified as unbounded exterior;
- projected sign alone does not convert an interior hard rail into a source exterior boundary.

A two-boundary bounded cell is therefore representable as non-disk with Euler characteristic zero.

### 5. Transactional cycle-aware publication

Final incidence validation audits every stored boundary range independently, verifies exact halfedge coverage and `next` relations, and preserves exact support-only twin ownership. Any invalid range, ownership gap, or malformed support-only orbit invalidates the transaction rather than publishing a partial cell inventory.

### 6. Downstream structural identity

Boundary-cycle offsets now participate in:

- arrangement and pipeline structural hashes;
- simplification incidence checks and reconstructed cells;
- feasibility-repair rollback identity and undo state;
- descriptor and rollback memory accounting.

Focused Phase 16 contracts were strengthened to require exact nested-cycle ownership and the typed nonmanifold source-edge failure. Test logic was compiled but not executed.

## Working-branch hygiene

Before triggering the build, the event commit removed all **18** superseded agent build workflows and all **5** stale CB98 patch/README payload files. It retained only the base workflow, the single active R2D workflow, and the two active patch parts.

The exact source commit then removed the active R2D workflow and both active patch parts before compilation. The compiled source and packaged source archive therefore contain:

- exactly one workflow: `.github/workflows/agent-source-snapshot.yml`;
- zero agent patch payload files;
- no temporary trigger or build artifact files.

This prevents obsolete or malformed workflow YAML from emitting unrelated check failures on later commits.

## Compile-only gate

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No runtime correctness, quality, performance, memory, determinism, or production-readiness claim is made from this build.

## Next turn

Execute `.agents/Directional/Milestone_G_P5_R2D_Test_Benchmark_Plan.md` against artifact `8913777837` without configuring, rebuilding, relinking, patching, regenerating, or modifying source.
