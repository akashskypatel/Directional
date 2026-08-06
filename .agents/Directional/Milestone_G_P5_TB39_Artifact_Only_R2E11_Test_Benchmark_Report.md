# Milestone G P5-TB39 Artifact-Only R2E11 Test + Benchmark Report

**Date:** 2026-08-05
**Turn type:** Test + Benchmark, artifact-only
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Disposition

P5-R2E11 is **not accepted**. It successfully adds accurate derived boundary-cover diagnostics, but it does not restore planar or interior-hard-rail successor publication. Both target fixtures still fail before publication with aggregate `BoundaryFanSectorCoverConflict`; the derived reason is deterministically `ExteriorPairMismatch`.

The complete split test inventory remains **597/625** with the same 28 failures as P5-TB38. Phase 17 remains **20/26**, so the six upstream arrangement-dependent regressions are not restored. R2 remains open; do not advance to R2F or R3.

A separate runtime regression was also observed: two single-process full-suite attempts reproducibly stopped making progress when the P27 production matrix entered the bunny case after prior suite state. The timeout wrappers are classified only as nontermination/performance evidence and are not correctness results. All 625 tests were therefore also executed through a complete non-overlapping split inventory.

## Exact artifact authority

- exact tested source: `b3010a36f762bb7317f2201d94733226b418c2c0`;
- workflow event commit: `5e96846a55acc8fd085836db886fcddbb5cd1dac`;
- workflow run/job: `31056835353` / `92476050630`;
- artifact ID/name: `8950709981` / `surface-cell-p5-r2e11-github-source-linux-release`;
- artifact SHA-256: `012a7782726b849ece1aa72286ae2ae9eb98b6a803106813b87caf348939a31c`;
- internal manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- executable-relative fixtures staged byte-identically: **26**;
- source status: empty;
- source/test blobs matched the recorded package authority.

No configure, rebuild, relink, patch, regeneration, implementation/test/fixture/validator/workflow change, or binary replacement occurred. Only packaged binaries were executed.

## Derived diagnostic authority

The new derived diagnostic is operational and fail-closed. Three independent runtime readings of each target produced identical aggregate and derived evidence.

### Planar higher-valence boundary

- test: `SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture`;
- aggregate: `BoundaryFanSectorCoverConflict`;
- derived: `ExteriorPairMismatch` (`2`);
- node/incoming/source-ray/target: `3 / 11 / 10 / 9`;
- repeated normalized evidence SHA-256: `45b748c5063f85b9b8fc5ca164824d22526bed89c3476daa2b2395bf90448d92`.

### Interior hard rail

- test: `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`;
- aggregate: `BoundaryFanSectorCoverConflict`;
- derived: `ExteriorPairMismatch` (`2`);
- node/incoming/source-ray/target: `1 / 7 / 6 / 1`;
- repeated normalized evidence SHA-256: `cbf39ca2b568a3a2978029ae3fc9f6bce7a63c53f62fe1b745bb8c437c0bdd93`.

The aggregate failure and exact tuple agree with the derived record. `boundaryFanConflict` is not `None`; no post-publication or synthetic diagnostic was used.

## Source-supported diagnosis

`SurfaceArrangement.cpp` independently constructs the authoritative exterior key as:

```text
(exteriorIncoming, exteriorTwin, exteriorOutgoing)
```

Before chart-corner witness reconciliation, it requires that exact key to occur once in `canonicalPairInventory`. Both target fixtures reject at this gate with `ExteriorPairMismatch`. Therefore the earliest remaining authoritative producer is the normalized canonical-pair inventory: it does not yet create or reconcile the independently proven exterior relation as one exact normalized pair.

This is earlier than wrap-sector publication and hard-rail bounded-orbit root validation. Do not patch downstream Euler, embedding, Phase 17, completion, or validation behavior to compensate.

## Focused and aggregate results

| Group | Result |
|---|---:|
| Source chart + validator | **17/17** |
| Recovery authority | **9/9** |
| Feature/barrier authority | **8/8** |
| Graph-dependent | **5/6** |
| R2 focused | **13/16** |
| Milestone D | **5/7** |
| Phase 16 | **45/47** |
| Phase 17 | **20/26** |
| Phase 18 | **57/57** |
| Phase 14–18 | **235/244** |
| Phase 20 | **46/48** |

The focused and phase counts, reached failure stages, and 28-failure split inventory match P5-TB38. R2E11 closes no product failure and introduces no additional split-inventory correctness failure.

### Complete-suite process evidence

- single-process attempt 1: wrapper ended after **300 s** while P27 entered `bunny_1k_random__surface_cells`;
- single-process attempt 2: same point after **180 s**;
- complete suite excluding the two isolated P27 cases: **596/623**, 27 failures, XML **26.720 s**, wall **26.73 s**, max RSS **270,996 KiB**;
- isolated P27 production matrix: **0/1**, XML **23.504 s**, wall **23.51 s**, max RSS **268,468 KiB**;
- isolated P27 bunny parameter: **1/1**, XML **23.234 s**, wall **23.24 s**, max RSS **268,672 KiB**;
- non-overlapping combined inventory: **597/625**, 28 failures, 0 errors, 0 disabled.

The split inventory is correctness/failure-set evidence. It does not erase the independently recorded single-process nontermination regression.

## Direct production processes

All direct runs used backend `SurfaceCells`, fallback policy `Fail`, source-grid recovery disabled, and no legacy execution. Every measured case reports `success=false`.

| Case | Runs | Median wall | CV | Arrangement / simplified / quads | Terminal producer failure |
|---|---:|---:|---:|---:|---|
| Plane | 5 | 0.013171 s | 0.03424 | 9 / 9 / 12 | `completion/output-validation: AggregateCompletionValidationFailure` |
| Multi-face seam | 5 | 0.012886 s | 0.01349 | 0 / 0 / 0 | `completion: SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | 5 | 0.020435 s | 0.01414 | 0 / 0 / 0 | same |
| Cylinder | 5 | 0.131359 s | 0.01459 | 0 / 0 / 0 | same |

Each analytic case has identical selected structural lineage across all five measured runs.

Two independently completed bunny processes report:

- run 1: **21.564972 s**, **271,044,608 B** peak working set;
- run 3: **22.528725 s**, **271,306,752 B** peak working set.

Both produce `0 / 0 / 0` arrangement/simplified/quads, fail `completion: SideSubdivisionRepair:InvalidInputIncidence`, and have identical selected structural lineage SHA-256 `02d98e49afd4f193f84c76765462f33c3d5b1ede61afd4e43f95b25c37289762`. An intervening independent bunny attempt stalled and is retained only as nontermination/performance evidence.

## Failure classification

- Planar and hard-rail exterior-pair mismatch: **production implementation defect** in normalized boundary-pair inventory/reconciliation.
- Existing bunny singularity, cylinder, FlowRep, completion, and Phase 17 failures: **independent existing production failures**, unchanged by R2E11.
- Single-process P27 bunny stall and intermittent standalone bunny stall: **runtime nontermination/performance regression**, exact producer not yet established; do not classify timeout as correctness.
- Artifact integrity, fixtures, packaging, and test execution setup: **valid**.

## Evidence

- archive: `directional-p5-tb39-8950709981-evidence.zip`;
- archive SHA-256: `ff423c6ebd77acfd16c9558f26f3dd08574c92e510fdc0eb815a7d34b8854803`;
- archive entries: **169**;
- archive size: **387229 bytes**;
- evidence manifest files: **161** plus the manifest itself.

The archive includes raw logs, XML, timing/RSS, exit states, direct benchmark JSON, repeated diagnostic reads, source excerpts, artifact/package authority, machine context, and machine-readable summaries.

## Next turn

Execute **P5-R2E12 normalized authoritative exterior-pair inventory Code + Build**.

The implementation must construct and reconcile the independently proven exterior relation in the normalized node-level pair inventory before chart-corner interior witness resolution, require exact agreement with any generic fan contribution, exclude it exactly once, and preserve every existing fail-closed gate. It must not change Phase 17, P27, bunny, cylinder, FlowRep, completion, fallback/recovery, fixtures, or validators.
