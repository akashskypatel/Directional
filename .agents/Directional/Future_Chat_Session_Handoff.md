# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R1D code changes and the exact four-target compile/package gate are complete. Runtime acceptance has not been executed for this source. Remain on R1 until P5-TB25 is authoritative.

Compiled checkpoint:

- P5-TB24 tested source `f4cce52006d21a248473e327ada1d66183af54e6`;
- workflow event commit `6fc57831afc7f77e0cda9bd1f409aaaaece15bda`;
- P5-R1D implementation and exact compiled source `a1fec970297739cfe23ade339b6a7b57071b7300`;
- applied source-diff SHA-256 `4488988dc877f1a0a001e27286b68f2752314bade361d59a11c1e7eae8a6cd89`;
- successful run `30942950398`, job `92105699139`;
- artifact `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`;
- artifact SHA-256 `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`;
- workflow-log artifact `8906116758`, SHA-256 `c8ceb09ca4ea9f72148125466a9958366b51a52f8e02c229aa71d1852b2d1ec2`;
- empty source status;
- recursive checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**;
- all **132/132** Ninja actions complete.

The build compiled exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. No project binary executed.

The next turn is **P5-TB25 artifact-only R1D validation**. Execute artifact `8906115786` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R1D_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R1D_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r1d-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB24_Artifact_Only_R1C_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R1D_Adjacent_Local_Sheet_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB24 runtime authority

- `SourceChartTransitionsR1.*`: **7/7**;
- `SourceAuthoritativeMeshValidatorPhase22.*`: **6/6**;
- recovery authority: **9/9**;
- graph-dependent focused: **3/6**;
- Phase 14–18: **240/243**;
- Phase 16: **37/39**;
- Phase 20: **46/48**;
- analytic plane/seam/close sheets: **0/3**;
- complete suite: **590/613**, terminating in **75.260 seconds**;
- maximum resident set: **256,544 KiB**.

R0 recovery authority and the R1 shared-edge orientation predicate are closed. The remaining R1 issue was exact adjacency being split solely by unequal local-sheet labels.

## P5-R1D implementation

1. Removed local-sheet equality from exact manifold transition admission.
2. Preserved equal source-component identity, valid opposite winding, exactly-two-face incidence, and hard-rail exclusion.
3. Preserved each face's local-sheet label in chart IDs, transition records, rebound provenance, hashes, and diagnostics.
4. Intrinsic source-vertex fans may cross adjacent local-sheet charts only through genuine source topology.
5. Hard rails, source boundaries, nonmanifold sectors, different components, and disconnected topology remain barriers.
6. Same-sheet safety remains for non-topological proximity capture and projection.
7. Added four focused contracts:
   - exact cross-local-sheet manifold adjacency;
   - source-vertex fan cross-local-sheet rebinding;
   - source-component mismatch rejection;
   - nonmanifold shared-edge rejection.
8. Strengthened face-row and whole-mesh orientation invariance tests with unequal incident local-sheet labels.
9. Added no R2 work, completion template search, recovery behavior, cache, stage-lineage, or memory changes.

The first workflow attempt failed before source modification because of an exact-text transport mismatch. The successful workflow used a single-occurrence regex-bounded source transformation. Do not infer runtime success from the compile result.

## P5-TB25 execution order

1. Verify artifact SHA, exact source, empty status, **40/40** checksums, 42 files, 26 fixtures, nine submodules, source contents, and target hashes.
2. Run all eleven `SourceChartTransitionsR1.*` tests.
3. Run all packaged `SourceAuthoritativeMeshValidatorPhase22.*` tests.
4. Run focused recovery authority and preserve **9/9** behavior.
5. Run the three P5-TB24 graph-dependent failures explicitly.
6. Run `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets` and relevant barrier regressions.
7. Run Phase 14–18 aggregate and Phase 16 independently.
8. Run plane, multi-face seam, close sheets, and any packaged disconnected-close-sheet direct case with fallback `Fail` and recovery disabled.
9. Run complete Phase 20.
10. Run the complete suite once with a watchdog used only as a safety mechanism.
11. Do not run the full direct bunny benchmark matrix solely for R1D.

## Decision rule

Advance to R2 only when:

- all eleven source-chart contracts pass;
- Phase 22 validator and recovery authority remain clean;
- the three graph-dependent failures close;
- feature-rail incident-sheet support passes;
- Phase 14–18 is clean;
- analytic cases are no longer blocked by local-sheet incompatibility;
- the complete suite still terminates.

A later analytic failure may justify R2 only after evidence shows source-chart orientation and local-sheet exact adjacency are no longer causal. Otherwise remain on R1 and make the smallest producer correction.

## Subsequent authoritative order

1. R2 — directed wedge/incidence reconstruction;
2. R3 — topology-distinct patch completion;
3. R4 — repeated-node wedge/splice producer;
4. R5 — explicit local lattice phase and advancing-front events;
5. R6 — torus decomposition/descriptor support;
6. R7 — adaptive dyadic 2:1 transitions;
7. R8 — direct production validation;
8. R9 — cache reuse;
9. R10 — stage-lineage fixtures;
10. R11 — synchronized memory telemetry.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- Local-sheet provenance and exact topological adjacency are distinct: keep sheet labels while allowing exact source topology to establish connectivity.
- Preserve sheet barriers for proximity capture and projection; only exact manifold adjacency crosses chart labels.
- Compile success proves integration and packaging only. P5-TB25 determines whether R1D closes the remaining R1 runtime failures.
