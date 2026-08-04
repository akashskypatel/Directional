# Milestone G P5-TB25 Artifact-Only R1D Test/Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB25 is complete against artifact `8906115786` and exact source `a1fec970297739cfe23ade339b6a7b57071b7300`.

R1 exact source-chart authority is closed:

- `SourceChartTransitionsR1.*`: **11/11**;
- source-authoritative validator: **6/6**;
- recovery authority: **9/9**;
- graph-dependent focused: **6/6**;
- feature-rail/barrier focused: **8/8**;
- Phase 14–18: **247/247**;
- Phase 16: **39/39**.

The three P5-TB24 graph-dependent failures and `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets` now pass. Local-sheet inequality is no longer the causal source-chart blocker.

Direct production remains open. The earliest remaining correctness producer is directed arrangement incidence before cell assignment. Advance to **P5-R2 directed wedge/incidence reconstruction**.

## Package authority

- artifact: `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`;
- archive SHA-256: `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`;
- exact source: `a1fec970297739cfe23ade339b6a7b57071b7300`;
- workflow event commit: `6fc57831afc7f77e0cda9bd1f409aaaaece15bda`;
- applied source-diff SHA-256: `4488988dc877f1a0a001e27286b68f2752314bade361d59a11c1e7eae8a6cd89`;
- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**;
- source archive contains the R1D rule and four focused contracts.

No configure, build, relink, patch, regeneration, or source modification occurred.

## Focused runtime gates

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Phase 22 source validator | **6/6** |
| Recovery authority | **9/9** |
| Graph-dependent contracts | **6/6** |
| Feature-rail/barrier contracts | **8/8** |
| Phase 14–18 | **247/247** |
| Phase 16 | **39/39** |
| Phase 20 | **46/48** |

Phase 20 failures remain:

1. `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput` — `NotProductionReady/completion`;
2. `SurfaceCellPipelinePhase20.ValidationRejectionCannotReportCompletedSurfaceCells` — real completion failure still preempts the intended validation-stage lineage.

## Direct analytic evidence

All cases used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy output.

| Case | Result | Quads | Validation failures | Wall | Peak working set |
|---|---:|---:|---:|---:|---:|
| plane | failed | 12 | 15 | 0.012962 s | 8,445,952 B |
| multi-face seam | failed | 24 | 22 | 0.022489 s | 8,564,736 B |
| close sheets | failed | 34 | 27 | 0.034163 s | 8,814,592 B |
| cylinder diagnostic | failed | 0 | 0 | 0.256127 s | 10,977,280 B |

The P5-TB24 validation counts are unchanged: **15**, **22**, and **27**. P27 evidence reports zero rail, provenance, and sheet failures. Remaining invalidity is concentrated in manifold/valence and geometric output checks:

- plane: `manifold=0/0/4`, `valence=2/0`;
- seam: `manifold=0/0/6`, `valence=6/0`;
- close sheets: `manifold=0/0/6`, `valence=10/0`.

Cylinder fails before aggregate output validation:

`InvalidCompletionQuadEmbedding;patch=10;backend=pattern;variant=51;localQuad=3;classification=bow-tie-intersection;vertices=32,31,229,230;component=0;sheet=0;sourceFaces=17,112`

## Directed-incidence evidence

The complete suite retains two Milestone D failures:

- `InteriorHardRailIsNotClassifiedAsExteriorBoundary`: arrangement topology is invalid;
- `CylindricalOpenStrandCommitsWithTopologyPreserved`:
  `non-disk-cell cell=0 halfedge=43 twin=42 next=29`.

Current arrangement construction globally sorts all outgoing halfedges at a node, assigns the predecessor of each incoming twin as its successor, then tries to split repeated-node closed walks after the successor relation exists. This can pair halfedges across inadmissible source-chart wedges and create pinched or non-disk cycles before completion.

R2 must construct directed source-chart wedges first, assign one predecessor and successor per halfedge within the admissible intrinsic wedge, audit the entire permutation, enumerate simple cycles, classify exterior cycles, and only then assign cell IDs. Repeated-node cycles must fail the producer audit instead of being split post hoc.

## Complete-suite result

- **617 tests**;
- **598 passed**;
- **19 failed**;
- completed normally in **333.444 seconds**;
- 1200-second watchdog did not fire;
- observed process `VmHWM` was at least **582,904 KiB** before completion.

The exact final maximum RSS is unavailable because the outer interactive execution call detached while the inner watchdog process continued. The packaged process completed and produced final log/XML; the retained `VmHWM` is a trustworthy lower bound.

Compared with P5-TB24:

- tests: **613 → 617**;
- passed: **590 → 598**;
- failures: **23 → 19**;
- duration: **75.260 → 333.444 seconds** (**4.43×**);
- observed VmHWM: **256,544 → at least 582,904 KiB** (**at least 2.27×**).

Three bunny executions dominate the suite:

- GP26 production matrix: **108.079 s**;
- GP27 production matrix: **113.256 s**;
- parameterized bunny ownership case: **108.116 s**.

Termination is demonstrated; acceptable production performance is not.

## Remaining failures

- GP23: 3 fallback/early-failure contracts preempted by completion;
- GP24: 4 diagnostics/lineage contracts preempted by completion;
- GP26: plane/mechanical, cylinder, seam, and torus end-to-end;
- GP27: production surface-cell matrix;
- Milestone D: 2 directed-incidence failures;
- Milestone E: variant 47 embedding, parallel route repair, and one-candidate reuse;
- Phase 20: cylinder completion and validation-lineage preemption.

Do not synthetically advance GP23/GP24/Phase20 to later stages. The Milestone E failures remain later R3/R9 work and do not precede the invalid directed incidence.

## Decision

- R0 recovery authority: **closed**;
- R1 orientation: **closed**;
- R1 adjacent-local-sheet exact adjacency: **closed**;
- R1 focused runtime: **closed**;
- direct production: **open**;
- performance regression: **open**;
- next turn: **P5-R2 directed wedge/incidence reconstruction + compile-only build**.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.
