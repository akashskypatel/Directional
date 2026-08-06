# Milestone G P5-TB41 Artifact-Only R2E13 Test + Benchmark Report

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E13 is **not accepted**.

The boundary-witness projection change improves observability and advances the planar fixture past exterior-pair insertion, but it does not close any test failure:

- planar now inserts **3** canonical pairs, excludes the explicit exterior pair exactly once, and then fails `InvalidOrientedInterval` for tuple `3/5/4/9` before any cyclic-wrap sector is published;
- interior hard rail still fails `ExteriorPairMismatch` for tuple `1/7/6/1` before any canonical pair or exterior exclusion is recorded.

Both target logs are byte-identical across three independent processes. Phase 17 remains **20/26**. The complete non-overlapping inventory remains **597/625**, with the exact same 28 failures as P5-TB40. No failure closed and no new failure appeared.

R2 remains open. Do not advance to R2F or R3.

## Exact artifact authority

- exact tested source: `39b60e66d72f412c1d648ffef213beca93bd19dc`;
- workflow event commit: `45a4c1031cccd3e814b2cf8e24209662dbfdae87`;
- workflow run/job: `31064914809` / `92500525659`;
- artifact ID/name: `8953600942` / `surface-cell-p5-r2e13-github-source-linux-release`;
- artifact SHA-256: `9144cde751377199a8df135ac0871e75e65c44b5d8efce07ea42a0732ae6f7d1`;
- artifact size: **12,295,987 bytes**;
- internal manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- executable-relative fixtures staged byte-identically: **26**;
- source status: empty;
- production/header/test blobs match package metadata.

No configure, rebuild, relink, patch, regeneration, implementation/test/fixture/validator/workflow/build change, or binary replacement occurred. Only packaged binaries were executed.

## Focused projected-authority diagnostics

### Planar higher-valence boundary

- aggregate: `BoundaryFanSectorCoverConflict`;
- derived conflict: `InvalidOrientedInterval(8)`;
- tuple: node/incoming/source/target = `3/5/4/9`;
- canonical pairs: **3**;
- exterior exclusions: **1**;
- fan-sector nodes: **1**;
- cyclic-wrap interior sectors: **0**;
- hard-rail separators / side pairs: **0 / 0**;
- repetitions: **3**;
- byte-identical log SHA-256: `3498659bc601e18794fc90fe2d3b87349f66e4c172d9f57a9312b9d049887ade`.

This proves that R2E13 no longer fails planar exterior authority. The explicit exterior record exists and is excluded once. The first observable rejection is the oriented chart interval for one non-exterior pair. Successor publication, positive wrap evidence, Euler, cell, area, ownership, and aggregate topology checks are not reached.

### Interior hard rail

- aggregate: `BoundaryFanSectorCoverConflict`;
- derived conflict: `ExteriorPairMismatch(2)`;
- tuple: node/incoming/source/target = `1/7/6/1`;
- canonical pairs: **0**;
- exterior exclusions: **0**;
- fan-sector nodes: **0**;
- cyclic-wrap interior sectors: **0**;
- hard-rail separators / side pairs: **0 / 0**;
- repetitions: **3**;
- byte-identical log SHA-256: `f47d8b154e9cf224fc942cfd703d0a185c48201cf4eaaff29494f959f4bb0fb9`.

The hard-rail fixture still rejects before exterior record insertion. No separator, side-root, orbit, embedding, disk, loop, Euler, ownership, or aggregate-topology check is reached.

## Focused and aggregate results

| Group | P5-TB41 | P5-TB40 |
|---|---:|---:|
| Source chart + validator | **17/17** | **17/17** |
| Recovery authority | **9/9** | **9/9** |
| Feature/barrier | **8/8** | **8/8** |
| Graph-dependent | **5/6** | **5/6** |
| R2 focused | **13/16** | **13/16** |
| Milestone D | **5/7** | **5/7** |
| Phase 16 | **45/47** | **45/47** |
| Phase 17 | **20/26** | **20/26** |
| Phase 18 | **57/57** | **57/57** |
| Phase 14–18 | **235/244** | **235/244** |
| Phase 20 | **46/48** | **46/48** |

The exact complete failure set is unchanged.

## Complete-suite and cumulative-state evidence

- complete suite excluding the two isolated P27 long cases: **596/623**, 27 failures, XML **26.379 s**, wall **26.39 s**, max RSS **272,164 KiB**;
- isolated P27 production matrix: **0/1**, XML **22.941 s**, wall **22.95 s**, max RSS **269,260 KiB**;
- isolated P27 bunny parameter: **1/1**, XML **22.064 s**, wall **22.07 s**, max RSS **269,152 KiB**;
- combined non-overlapping correctness inventory: **597/625**, 28 failures, 0 errors, 0 disabled.

A single-process cumulative-state attempt again reached the P27 bunny `BEFORE_PIPELINE` marker after prior suite state and was externally terminated. This is performance/nontermination evidence only. The complete split inventory is correctness authority; timeout or termination is not used as a pass or failure substitute.

## Direct production processes

All direct runs used backend `SurfaceCells`, fallback policy `Fail`, source-grid recovery disabled, and no legacy execution. Every case reports `success=false`.

| Case | Runs | Median wall | CV | Arrangement / simplified / quads | First invalid producer |
|---|---:|---:|---:|---:|---|
| Plane | 5 | 0.012994 s | 0.03469 | 9 / 9 / 12 | `completion: NotProductionReady`; output validation remains invalid |
| Multi-face seam | 5 | 0.013283 s | 0.10433 | 0 / 0 / 0 | `completion: SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | 5 | 0.020511 s | 0.02116 | 0 / 0 / 0 | same |
| Cylinder | 5 | 0.133303 s | 0.01460 | 0 / 0 / 0 | same |

All measured analytic runs have identical selected structural lineage.

Two independent bunny processes completed:

- run 1: **21.659158 s**, **272,052,224 B** peak working set;
- run 2: **21.925100 s**, **272,048,128 B** peak working set.

Both produce `0 / 0 / 0`, fail `completion: SideSubdivisionRepair:InvalidInputIncidence`, and have identical selected structural lineage. No fallback, legacy execution, or source-grid recovery occurred.

## Source-supported diagnosis

The following is a source-supported inference from the deterministic runtime diagnostics and exact packaged source; it is not an additional runtime field.

### Hard-rail exterior authority is over-collapsed

R2E13 projects source and target boundary rays independently, but then requires their transition roots to be equal before inserting the excluded exterior pair. At a boundary vertex split by an authoritative interior hard rail, the two boundary-side charts are expected to belong to distinct transition components. The exterior continuation is source-boundary topology and does not need one shared interior chart root.

The zero pair/exclusion counts and `ExteriorPairMismatch` tuple are consistent with this pre-insertion equality gate. The exterior record should retain endpoint-specific projected roots and reconcile each ray against its own side, while preserving a common authoritative boundary vertex/entity and loop identity. Non-exterior pairs must continue to require one exact common root.

### Planar wrap authority is attached to raw fan-vector indexing

The node-level canonical pair exists and exterior handling succeeds. Generic pair inventory currently marks `cyclicWrap` from `sourceIndex == 0` in a fan vector, then chart resolution refuses to unwrap `sourceAngle <= targetAngle` unless that stored flag is true.

The deterministic planar result—valid pair inventory, one exterior exclusion, `InvalidOrientedInterval`, and zero wrap count—is consistent with a valid chart-seam interval whose wrap flag was not carried by that raw fan index. Pair existence must remain node-level and normalized. After a pair is already authoritative, its chart witness should normalize the circular interval from exact chart-corner adjacency and the pair's provenance, not from arbitrary container index or by creating a chart-local pair.

## Acceptance audit

- [x] artifact and source authority verified;
- [x] target diagnostics expose deterministic derived context;
- [x] planar explicit exterior pair/exclusion is runtime-proven;
- [ ] planar non-exterior oriented interval and positive wrap are valid;
- [ ] hard-rail exterior pair is inserted with side-specific authority;
- [ ] hard-rail separators, roots, complete orbits, and topology are reached;
- [ ] Phase 17 returns to 26/26;
- [x] prerequisite, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold baselines do not regress;
- [x] no validator weakening, fallback substitution, arbitrary selection, synthetic correction, fixture special case, or timeout-as-correctness;
- [ ] R2E13 accepted — **not accepted**.

## Evidence

- archive: `directional-p5-tb41-8953600942-evidence.zip`;
- archive SHA-256: `20d4f87c21c3789a1ade6eb8da84fca69b5cff6dc83bc2808bee6848bf89d825`;
- archive entries: **140**;
- archive size: **358,161 bytes**.

The archive contains integrity records, source/test blob verification, machine context, fixture inventory, raw focused/group/full logs, XML, timing/RSS, process exits, direct benchmark JSON, structural lineage, source excerpts, and the machine-readable summary.

## Next turn

Execute **P5-R2E14 two-sided exterior-root authority and chart-seam interval normalization Code + Build**.

The implementation must preserve node-level canonical pair ownership and every fail-closed publication/topology gate. It must not use chart-local lists to define whether a pair exists, select roots by count/order/frequency, search subsets, or compensate downstream.
