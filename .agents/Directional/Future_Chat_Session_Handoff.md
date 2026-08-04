# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB22 artifact-only runtime validation is complete. P5 remains open.

Tested checkpoint:

- exact source `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- artifact `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`;
- SHA-256 `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`;
- reviewed patch SHA-256 `890dd621cf549f32c55d44f52b85050bfdfa5ce15df5f2bda2f8ba3e33c8ed70`;
- empty source status;
- checksums **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodules **9**.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB22.

The next turn is **P5-CB143 through P5-CB150 code changes + compile-only build**. Execute no test, benchmark, custom mesh, help/list/discovery command, or compiled project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB22_Artifact_Only_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb22-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB22_Producer_Correction_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_CB135_CB142_Code_Build_Report.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB22 runtime result

Closed or improved:

- package authority;
- complete 600-test suite now terminates in **103.441 s**;
- full suite result **585/600**;
- Phase 14–18 **236/236**;
- Phase 16 **39/39**;
- Phase 17 **26/26**;
- four face-edge runs terminate with one signature, 14/14 alternatives, and sequence hash `12658256849805696865`;
- four smooth runs terminate within the established wall and peak limits;
- torus reason is typed as `side-count-unsupported`.

Open:

- Milestone D **6/7**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase20 **46/48**;
- production **0/8**;
- positive completion reuse/recompute `0/0`;
- same-sample categorized ownership 0 bytes / 0% coverage despite availability true.

## Earliest authoritative producers

### Repeated-node alternatives

The bounded frontier works, but single-interface exclusion cannot create a valid replacement cycle.

- face-edge bunny: 14/14 exhausted in all four runs;
- prescribed sphere: 68/68 exhausted;
- mechanical feature: 104/104 exhausted.

The next implementation must create topology-distinct local pairings at the typed repeated node using canonical DCEL wedges. Do not broaden into arbitrary interface subsets or lose deterministic termination.

### Cylinder

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` remains:

`non-disk-cell cell=0 halfedge=43 twin=42 next=29`

The repeated-occurrence split heuristic did not repair periodic incidence. Reconstruct bounded cells from the complete directed successor/twin inventory before assigning cell IDs.

Cylinder completion separately fails patch 10, pattern variant 51, local quad 3, `bow-tie-intersection`.

### Local completion templates

Rotations/reversals double the catalog but do not change topology:

- focused general completion: bounded-combinatorial variant 47, `degenerate-normal`;
- cylinder: pattern variant 51, `bow-tie-intersection`;
- thin tube: bounded-combinatorial variant 43, `degenerate-normal`;
- smooth bunny: patch 9181, closed-form variant 0, `degenerate-normal`.

The next implementation must produce topology-distinct connectivity and distinct source-supported generated positions, not more cyclic reorderings.

### Parallel route and cache reuse

The semantic duplicate negative remains correct, but the valid whole-complex parallel route still fails `same-corner-distinct-boundary`. The one-candidate contract still reports no incremental recomputation and reuse/recompute `0/0`.

Retain stitch-separation identity in global vertex keys and invalidate/retarget only exact changed dependencies.

### Source-chart agreement

The P5-CB140 resolver does not change the production failures:

- plane: 12 quads, `LocalSheetMismatch`, cell 4, face 7;
- multi-face seam: 24 quads, cell 2, face 15;
- close sheets: 34 quads, cell 3, face 13.

Literal common-face intersection is insufficient. Build orientation-aware transitions across source vertex/edge incidences and select a canonical intrinsic entity chart. Keep disconnected sheets in separate transition components.

### Pipeline lineage

GP23 optimization injections and GP24/Phase20 validation injections still terminate at completion. Correct invalid preceding fixtures/producers; do not bypass completion or reorder stages.

### Torus

Torus remains:

`IncompleteSurfaceCellComplex;descriptor=22;cell=23;reason=side-count-unsupported;reasonCode=3;attempted=41;failed=2;total=43`

The typed reason is closed. The unsupported descriptor/decomposition producer is not.

### Memory

Every production and bunny result reports a nonzero sample sequence and availability true, but categorized owned bytes are zero and coverage is 0%. The sampler is observing a post-release or uncategorized point.

Sample working set and current category ownership together at each ownership acquire/release transition. Availability must be false for zero categorized bytes.

## Bunny evidence

Face-edge four-run ranges:

- wall **20.727–22.865 s**;
- peak **165,543,936–165,769,216 B**;
- one deterministic failure and one alternative-state sequence hash.

Smooth four-run ranges:

- wall **31.052–35.588 s**, below 39.228299 s;
- peak **452,571,136–452,689,920 B**, below 1,115,394,560 B;
- one deterministic failure at patch 9181.

Termination and resource stability improve. Valid output does not.

## Required next work

Follow P5-CB143–P5-CB150 in the post-TB22 plan, in order:

1. topology-distinct repeated-node wedge/splice pairings;
2. cylinder reconstruction from directed incidence;
3. topology-distinct local completion templates;
4. valid parallel-route stitch separation and real cache reuse;
5. source-entity chart transitions across adjacent faces;
6. production-valid stage-lineage fixtures/producers;
7. torus descriptor support or valid decomposition;
8. synchronized live-category memory sampling and exact compile/package gate.

## Compile-only boundary

Shallow-initialize recursive submodules and compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not run them. Initialize detailed workflow logging before fallible work and always upload a separate log artifact.

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

- Bounded deterministic failure is a real improvement, but it does not replace a valid producer.
- Rotating or reversing invalid geometry does not create a topology-distinct completion.
- Common source entities may require exact chart transitions even when owning patches have no literal common source face.
- Memory availability must be conditioned on nonzero synchronized categorized ownership.
- Full-suite termination is now stable enough to expose the remaining 15 correctness failures directly.
