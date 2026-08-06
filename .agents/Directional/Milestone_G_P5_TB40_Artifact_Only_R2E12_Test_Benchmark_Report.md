# Milestone G P5-TB40 Artifact-Only R2E12 Test + Benchmark Report

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E12 is **not accepted**. The first-class exterior-pair implementation is compile-valid, but packaged runtime behavior does not improve the P5-TB39 baseline.

Both target fixtures still fail before successor publication with aggregate `BoundaryFanSectorCoverConflict`:

- `SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture`;
- `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`.

Each target was executed three times independently and produced byte-identical failure logs. Planar wrap/Euler/topology assertions and hard-rail embedding/orbit/topology assertions are not reached. Phase 17 remains **20/26**. The complete non-overlapping inventory remains **597/625** with the exact same 28 failures as P5-TB39: no failure closed and no new failure appeared.

R2 remains open. Do not advance to R2F or R3.

## Exact artifact authority

- exact tested source: `556efab8c26e012a6019e0b0a10fb847fc8e2ace`;
- workflow event commit: `50d5db4280a5008764f73e5ba0a1827ce63eab1e`;
- workflow run/job: `31060329035` / `92486695630`;
- artifact ID/name: `8951981127` / `surface-cell-p5-r2e12-github-source-linux-release`;
- artifact SHA-256: `7472441fb8b4f82d7e7bc5a62066a8a3db2022851f72c809bb45244bb1b996f0`;
- internal manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- executable-relative fixtures staged byte-identically: **26**;
- source status: empty;
- source/test blobs match package metadata.

No configure, rebuild, relink, patch, regeneration, implementation/test/fixture/validator/workflow change, or binary replacement occurred. Only packaged binaries were executed.

## Focused target evidence

### Planar higher-valence boundary

- aggregate incidence failure: `BoundaryFanSectorCoverConflict`;
- repetitions: **3**;
- byte-identical log SHA-256: `f36b6d762047152019b28c6898fd51995530c2337c28cf7aface952f8c4ca33a`;
- first failing assertion: `incidenceValid == true`;
- no successor-bijection, exterior-exclusion, wrap, Euler, area, cell, or aggregate-topology assertion is reached.

### Interior hard rail

- aggregate incidence failure: `BoundaryFanSectorCoverConflict`;
- repetitions: **3**;
- byte-identical log SHA-256: `8a4beb40039ae1840df95178648ab46f0c8ef6a338ca230070dc50f23e512e65`;
- first failing assertion: `incidenceValid == true`;
- no separator-count, side-root, complete-orbit, embedding, disk, loop, Euler, ownership, or aggregate-topology assertion is reached.

### Runtime observability limitation

The unchanged target assertions print only the aggregate incidence failure name. They do not print `boundaryFanConflict`, its node/incoming/source-ray/target tuple, canonical-pair count, or exterior-exclusion count. Therefore this artifact-only turn does **not** claim an exact derived subtype or tuple for R2E12. P5-TB39's `ExteriorPairMismatch` tuples remain the prior baseline, not newly observed R2E12 facts.

This limitation does not affect the product disposition: both fixtures still reject before publication and the complete failure set is unchanged.

## Source-supported diagnosis

R2E12 inserts an explicit exterior record only after these checks:

1. exact source-boundary loop and `+1/-1` side witnesses;
2. `collect_ray_entity_root_evidence(exteriorTwin)` and the same for `exteriorOutgoing`;
3. each complete evidence map has exactly one `(normalized entity key, transition root)` entry;
4. the two maps have the same entry;
5. combined provenance is non-empty.

The helper collects **all** source-vertex/source-edge fan memberships containing each ray. Requiring the complete raw maps to have cardinality one can reject a legitimate boundary ray that participates in more than one fan identity, even when the authoritative boundary witness already fixes the exterior source entity, chart, root, loop, and side.

This is a source-supported inference, not a newly emitted runtime subtype. The next turn must make exterior authority a projection from the exact boundary witnesses and reconcile fan provenance against that authority. It must not choose by count, order, frequency, score, or arbitrary subset search.

## Focused and aggregate results

| Group | P5-TB40 | P5-TB39 |
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

The exact 28-failure set is unchanged from P5-TB39.

## Complete-suite and nontermination evidence

- one single-process attempt produced complete XML: **597/625**, 28 failures, XML **71.675 s**; its outer wrapper exit/time files were lost, so it is corroborative rather than process-state authority;
- a second bounded single-process attempt again stopped at `[P5_P27_BEFORE_PIPELINE] bunny_1k_random__surface_cells` and was terminated after **180 s**;
- complete suite excluding the two isolated P27 cases: **596/623**, 27 failures, XML **27.081 s**, wall **27.10 s**, max RSS **271,396 KiB**;
- isolated P27 production matrix: **0/1**, XML **23.427 s**, wall **23.43 s**, max RSS **268,772 KiB**;
- isolated P27 bunny parameter: **1/1**, XML **24.081 s**, wall **24.08 s**, max RSS **267,820 KiB**;
- combined non-overlapping correctness inventory: **597/625**, 28 failures, 0 errors, 0 disabled.

Timeout is not correctness evidence. The split inventory is the authoritative correctness/failure-set result; the repeated single-process bunny stop remains a separate nontermination/performance regression.

## Direct production processes

All direct runs used backend `SurfaceCells`, fallback policy `Fail`, source-grid recovery disabled, and no legacy execution. Every case reports `success=false`.

| Case | Runs | Median wall | CV | Arrangement / simplified / quads | First invalid producer |
|---|---:|---:|---:|---:|---|
| Plane | 5 | 0.012850 s | 0.01873 | 9 / 9 / 12 | `completion/output-validation: AggregateCompletionValidationFailure` |
| Multi-face seam | 5 | 0.014025 s | 0.11264 | 0 / 0 / 0 | `completion: SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | 5 | 0.020214 s | 0.03371 | 0 / 0 / 0 | same |
| Cylinder | 5 | 0.138396 s | 0.03908 | 0 / 0 / 0 | same |

All five measured runs of each analytic case have identical selected structural lineage.

Two independent bunny processes completed:

- run 1: **21.602792 s**, **271,355,904 B** peak working set;
- run 2: **22.128905 s**, **271,142,912 B** peak working set.

Both produce `0 / 0 / 0`, fail `completion: SideSubdivisionRepair:InvalidInputIncidence`, and have identical selected structural lineage. No fallback, legacy execution, or source-grid recovery occurred.

## Acceptance audit

- [x] artifact and source authority verified;
- [x] prerequisite source-chart/validator, recovery, and feature/barrier groups preserved;
- [ ] planar passes prior boundary-fan incidence gate;
- [ ] hard rail passes prior boundary-fan incidence gate;
- [ ] one explicit exterior pair/exclusion is runtime-proven per target node;
- [ ] planar reaches genuine wrap and Euler-one topology;
- [ ] hard rail reaches distinct complete-orbit roots and valid embedding/topology;
- [ ] Phase 17 returns to 26/26;
- [x] no validator weakening, fallback substitution, synthetic correction, fixture special case, or timeout-as-correctness;
- [ ] R2E12 accepted — **not accepted**.

## Evidence

- archive: `directional-p5-tb40-8951981127-evidence.zip`;
- archive SHA-256: `aa148bb4a7182ff01f7f41c5123e7d67f41b6b96e6a138826e5c89a9b96b1c28`;
- archive entries: **145**;
- archive size: **394,571 bytes**.

The archive contains integrity records, source/test blob verification, machine context, fixture inventory, raw logs, XML, timing/RSS, exit states, direct benchmark JSON, deterministic-lineage records, source excerpts, orchestration notes, and the machine-readable summary.

## Next turn

Execute **P5-R2E13 authoritative boundary-witness projected exterior-ray evidence Code + Build**.

The next implementation must derive the exterior entity/root authority directly from the exact source-boundary witnesses, reconcile matching fan provenance against that authority, preserve unrelated fan memberships for their own interior authority, and fail closed on any contradictory boundary claim. It must also expose deterministic derived evidence in the existing target assertions without weakening them.
