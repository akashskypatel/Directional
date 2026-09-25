# M6-CP1-CB4 — Complete Seam-Incident Occurrence/Lineage Authority Code + Build Report

**Status:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE UNPROMOTED
**Turn:** `M6-CP1-CB4`
**Semantic source:** `20f60bb1412424a6f1093fc8076884d1ea23f1c5`
**Required successor:** `M6-CP1-TB4-EXEC`, then `M6-CP1-TB4-REV`

## 1. Scope completed

CB4 implements the accepted `M6-DEFN-R2` contract as amended by RA-1 – RA-11 without widening A4, changing semantic occurrence/relation identity, or changing relation-only quotient equality.

The implementation:

- adds complete `CornerWedgeFaceBinding=(face,sheet,chart)` authority and RA-11 `CornerPlacementProvenance` carrying the A4 corner `LocalLatticeState` plus its selected-face label;
- derives source-edge-collinear interior-face authority from accepted cell orientation/source winding instead of tracer face-row tie breaks;
- carries ordered `CornerWedgeIsolationTransition(region,seam,fromSheet,toSheet)` evidence through A5, A6 lineage equivalences, hashing/benchmark evidence and component remap;
- adds `PureQuadEquivalenceKind::CornerWedgeIsolation` as evidence-only authority, never an A5 owned relation and never a selected HardRail/Periodic path;
- splits A5 HardRail/Periodic/kind/isolation failures while preserving frozen M5 external names through one compatibility adapter;
- uses complete binding signatures plus coordinate/scale/labelled placement provenance in the transitional class key while preserving semantic `QuotientClassId` and using support + bindings + semantic `OccurrenceId` for representative choice;
- derives selected relation path charts/components from relation-side bindings and selected relation steps, not quotient representatives;
- remaps complete binding/isolation tuples before deriving legacy region/sheet/chart projections;
- validates reciprocal ordinary and seam-collinear sides with exact span/certificate/transition evidence and reports `QuotientReciprocalSideAuthorityMismatch` on disagreement; and
- strengthens `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` with the split-square v0/center/v2 multi-sheet/evidence assertions and row-invariant semantic comparison required by RA-4.

Changed semantic/test files are exactly:

- `include/directional/geometry/PureQuadCompletion.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `src/bench/BenchmarkQuality.cpp`
- `src/geometry/PureQuadCompletion.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

The verified work-preservation patch SHA-256 is `1be2b2b3785d46bdde23cd3d24af4346a649591a430595960e44a557b279235b`; its diff-body SHA-256 is `6796adff7179e2407e52e076f0dc4d52b1bb590176be83d7e5f3d72b858ef27b`.

## 2. Frozen static regression audit

No generated Directional binary was executed. The required audit was source-only against the exact compiled source.

- **Focused rows 1–4:** existing assertions are unchanged. Row3 still expects `RelationEndpointMissing` for foreign/self endpoints, `UnownedRelation` for relation identity/owner-encoding mismatch, and `DuplicateRelationDeclaration` for duplicate declarations. The new A5 error split does not rename those enum cases.
- **Selector row140 — `HardRailPairExplicitRailIdMismatchRejectsStrictTransport`:** A5 now classifies explicit owner disagreement as `HardRailOwnerMismatch`; the single legacy adapter maps it to the frozen external `InvalidHardRailTransport`. The later duplicate owner-mismatch check is not needed.
- **Focused row5 — `MultiIsolationMaterializationRetainsAllLocalSheets`:** occurrence wedge bindings publish every admissible sheet and exact seam transition evidence; A6 unions member wedge sheets and emits evidence-only `CornerWedgeIsolation` lineage, so the accepted multi-isolation authority is no longer reconstructed from relation ownership.
- **Focused row6 — periodic pair-storage semantic direction:** Periodic ownership/action remains the selected typed relation. Binding changes only supply the endpoint chart/component attached to the selected relation-side interior face; storage order does not define semantic direction.
- **Selector row186:** exact isolation seam certificates are indexed by `(region,seam)` and transition evidence must match their directed face/sheet pair. Existing certificate owner/value semantics are unchanged.
- **Selector row214:** component remap now validates and remaps exact `(region,sheet,chart)` bindings first, then derives the legacy projections, preserving complete typed domain authority rather than independently remapping scalar projections.
- **Selector row239:** seam-collinear reciprocal sides require the same exact seam/span certificate with opposite incident faces/sheets and reverse-compatible transition evidence; exact reciprocal source-adjacent transport remains the accepted path.
- **Selector rows444/448:** selected relation paths are still built only from selected quotient joins. Start/end charts are taken from the selected relation steps; the implementation does not search an alternative Periodic relation because of a binding.
- **Selector row446:** nonzero-Z4 action/translation continues to come from the accepted Periodic relation action. Added chart evidence does not alter or normalize that action.
- **Accepted Phase10 HardRail single-sheet assertions:** `sourceIsolationSheets` is the union of member corner-wedge bindings only (RA-6). HardRail paths do not inject isolation sheets or `CornerWedgeIsolation` transitions.

Frozen selector/routing bytes remain exact:

- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` (449 LF rows);
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` (449 rows).

## 3. Patch application evidence

The exact patch was applied through the approved Google Drive transport.

- run/job: `36150018237 / 108120755401` — SUCCESS;
- result artifact: `10871236458`, SHA-256 `6a2ee82b45437baeab0d987086f5182de35b3545e0bae65cf21f502a805efafd`;
- log artifact: `10871126599`, SHA-256 `2d068749836283c439d2b60d6b1857c0c264c003fc4f984cf8f67e5f9a1c0ff3`;
- base source: `05127e48cc424aad8c9406be860b3178701c723e`;
- applied semantic commit: `20f60bb1412424a6f1093fc8076884d1ea23f1c5`;
- workflow evidence: `runtimeExecution=false`.

The apply identity could not trash the staged Drive file and reported `drive_file_retirement_required=true`. At closeout, the owner-authorized Drive connector returned 404 for the exact File ID, so the staging object is no longer addressable from the owner control plane; no successful deletion is claimed by this report.

## 4. Compile/package evidence

Mandatory compile run/job `36150253128 / 108121497728` completed successfully through `.github/workflows/agent-compile-reusable.yml` from exact source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`.

Candidate package:

- result artifact: `10871935178`;
- provider/downloaded ZIP SHA-256: `dc6e979ac62b4599c2c8b15528524513f3bc5b45eb9068ed508fd3d08ccf7998`;
- compile log artifact: `10871960013`;
- compile log SHA-256: `bbdfe584c0aefa433f614f699c28686ab83c9bc8194b3f868c1db96589c2eabf`;
- packaged source archive SHA-256: `db894f3e27d880b4d27a593816df6e521dff01583e320ec198b4fd8401e50065`;
- root manifest: **28/28 verified**;
- source status before/after configure/build/final: clean;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only`;
- exact arithmetic backend: GMP, with generated link evidence containing both `gmpxx` and `gmp`;
- fixed compiler-cache key: `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`;
- compile cache: 101/129 hits (78.29%).

The standard eight targets compiled/linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated test, benchmark, discovery/list/help/version command, CLI, fuzzer, `ctest`, or custom Directional input executed.

## 5. Exit disposition

Every CB4 exit-gate item is compile/static-evidence green. This turn grants **no runtime credit, candidate promotion, debt discharge, or checkpoint closure**. Stable accounting remains **54 events / 16 categories / 38 recurrences**, project debt **1** (M6-owned). Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**.

The exact next turn is immutable artifact-only **`M6-CP1-TB4-EXEC`** over **7 focused + selector449 = 456 fresh exact-filter processes**, followed by mandatory **`M6-CP1-TB4-REV`**.
