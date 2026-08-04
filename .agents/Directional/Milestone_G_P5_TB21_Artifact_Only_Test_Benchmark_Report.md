# Milestone G P5-TB21 Artifact-Only Test and Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** artifact-only test and benchmark

## Disposition

P5-TB21 is complete. The P5-CB126 through P5-CB134 checkpoint improves fixture correctness, typed diagnostics, and focused coverage, but it is not production ready.

Closed or improved:

- package authority passed;
- Phase 14–18 is now **236/236**;
- Phase 16 remains **39/39**;
- Phase 17 remains **26/26**;
- the corrected positive provenance fixture passes;
- the retained zig-zag negative embedding fixture passes;
- the shared-edge parity focused contract passes;
- semantic-only same-corner duplicate rejection passes;
- typed embedding evidence now identifies concrete patch/backend/variant failures.

Open or regressed:

- the unfiltered full suite no longer terminates within 20 minutes;
- a second suite attempt excluding the first hanging matrix still does not terminate within 15 minutes;
- all eight direct production fixtures still fail;
- cylinder DCEL remains `non-disk-cell`;
- repeated-node repair still has no valid bounded alternative on sphere, mechanical, or face-edge bunny;
- the valid annular/parallel route still fails and reuse remains `0/0`;
- plane, seam, and close sheets still fail `LocalSheetMismatch`;
- smooth bunny exceeds the established wall limit;
- face-edge bunny has three stable failed runs followed by a fourth repetition that did not complete within the remaining approximately 257 seconds of a 300-second batch;
- same-sample memory measurement is unavailable, so the 75% reconciliation gate remains open.

P5 remains open.

## Artifact authority

Executed artifact `8890167812`, `surface-cell-p5-cb134-github-source-linux-release`, directly.

- archive SHA-256: `34a4da9a9c9e3374ed861c41b72493beefc90afbc85743fd25979484f3222bf1`;
- exact compiled source: `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- implementation commit: `01788193457e60bb8817a40b2c1551e672c4de5c`;
- reviewed patch SHA-256: `cb6b02838c08f68bb272b14a13b218572fcae88a58c9d3a73badbafd26b5421f`;
- compile-fix SHA-256: `49ee91640fced0bf21a50fd614a40937ff5b261d4adee8e828262ba2d3e2dd29`;
- empty source status;
- recursive checksums **41/41**;
- fixture files **26**;
- recursive submodule records **9**.

Packaged target hashes:

- `directional_phase1_tests`: `144d1f4aa4e53c5b5704137c16bbfd8bc51decb85342bf2845c07f591ee65fce`;
- `directional_benchmarks`: `a2b4ef5f7eff8281a51ec8267f497d8fd9c27305d9bd715dc80f95a5a6dfec28`;
- `libdirectional_core.a`: `8bf7a7c8b41feab4c7bbb70321c0f5117e19a069d1c1e4fe6bc5fde89eb1935e`;
- `libdirectional_pipeline.a`: `ba337cea2a5cbc378bdab7ab69575969d9124d3aa049fe15fdb55359f39a36e4`.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB21.

## Test scopes

| Scope | Result |
|---|---:|
| Focused P5-CB126–P5-CB134 contracts | **20/27** |
| Phase 14–18 | **236/236** |
| Phase 16 | **39/39** |
| Phase 17 | **26/26** |
| Milestone D | **6/7** |
| Milestone E | **23/26** |
| GP23 + GP24 | **10/14** |
| Phase 20 | **46/48** |
| Bounded full-suite subset | **583/597** |

Newly closed focused contracts include valid provenance, explicit negative zig-zag embedding, shared-edge parity, semantic duplicate rejection, exact failed-subdivision rollback, and typed duplicate/same-corner evidence.

## Earliest focused blockers

1. Cylinder incidence remains `non-disk-cell cell=0 halfedge=43 twin=42 next=29`.
2. The focused bounded-combinatorial completion reaches variant 23 but produces `degenerate-normal` on patch 0, local quad 0, vertices 9,10,11,12.
3. The valid parallel route still ends in `SameCornerStructuralRepairExhausted` with a `same-corner-distinct-boundary` duplicate stitched quad.
4. The one-candidate budget contract still records zero incremental recomputation and genuine reuse/recompute `0/0`.
5. GP23 and GP24 still encounter `NotProductionReady/completion` before their intended optimization or validation evidence.
6. Phase 20 still fails cylinder production and validation-stage lineage.

## Full-suite termination

The checkpoint contains **600** tests.

The unfiltered suite did not terminate within **1,200 seconds**. It reached `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` and stopped after `[P5_P26_BEFORE_PIPELINE] bunny_1k_random__surface_cells`.

A second run excluded that aggregate test. It still did not terminate within **900 seconds**, stopping in `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` during the bunny case.

Excluding the two aggregate production matrices and the independently parameterized bunny case produced **583/597** in 3.504 seconds with 14 failures and maximum RSS 24,424,448 bytes. This bounded subset is diagnostic evidence only, not a replacement for a terminating full suite.

## Direct production matrix

All cases used `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled. No fallback or recovery was observed.

| Case | Result | Earliest authoritative blocker |
|---|---|---|
| plane | fail | 12 quads; `LocalSheetMismatch`, cell 4, face 7 |
| cylinder | fail | patch 10, pattern variant 25, local quad 1, `bow-tie-intersection` |
| torus | fail | `IncompleteSurfaceCellComplex;descriptor=22;cell=23;reason=3;attempted=41;failed=2;total=43` |
| thin bent tube | fail | patch 108, bounded-combinatorial variant 21, local quad 0, `degenerate-normal` |
| close sheets | fail | 34 quads; `LocalSheetMismatch`, cell 3, face 13 |
| prescribed sphere | fail | repeated boundary node, cell 2, halfedge 37, node 13, source face 7 |
| multi-face seam | fail | 24 quads; `LocalSheetMismatch`, cell 2, face 15 |
| mechanical feature | fail | repeated boundary node, cell 2, halfedge 719, node 65, source face 109 |

Production remains **0/8**.

## Bunny evidence

Three face-edge runs complete with one matching failed signature:

- 21.213 s, 164,372,480 B, 23.250% owned/peak;
- 20.191 s, 164,392,960 B, 23.247% owned/peak;
- 22.047 s, 164,302,848 B, 23.260% owned/peak.

All fail at `BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node`, cell 2, halfedge 45, node 20, source face 0. Completion never starts and reuse/recompute remains `0/0`.

A fourth repetition did not produce a JSON result within the remaining approximately 257 seconds of a 300-second batch after runs 2 and 3 completed. No further repeats were started.

One smooth/default-field run completes in **40.090 seconds** at **452,788,224 bytes**, exceeding the established 39.228299-second wall limit. Its typed failure is `InvalidCompletionQuadEmbedding;patch=9181;backend=closed-form;variant=0;localQuad=0;classification=degenerate-normal;vertices=15000,15001,15003,15002;component=0;sheet=0;sourceFaces=406`. It attempted 21,297 patches, failed 1,805, and recorded reuse/recompute `0/0`.

## Memory telemetry

The new output correctly reports `sameSampleOwnershipMeasurementAvailable=false` instead of presenting unsupported coverage. The telemetry semantics improve, but the production gate does not close:

- face-edge owned/peak is about 23.25%;
- smooth owned/peak is about 39.03%;
- the required 75% same-sample reconciliation is not established.

## P5-TB20 comparison

Closed since P5-TB20:

- Phase 14–18 improves from **234/235** to **236/236**;
- Milestone E improves from **21/26** to **23/26**;
- valid provenance and explicit negative embedding fixtures;
- shared-edge parity focused contract;
- typed local embedding producer evidence;
- explicit torus incomplete inventory.

Unchanged or regressed:

- production remains **0/8**;
- cylinder DCEL remains non-disk;
- repeated-node alternatives still do not commit;
- valid parallel route and positive reuse remain open;
- pipeline lineage remains **10/14**;
- Phase 20 remains **46/48**;
- `LocalSheetMismatch` remains;
- full-suite termination regresses;
- face-edge fourth-run determinism regresses and memory increases;
- smooth remains above the wall limit;
- 75% memory reconciliation remains open.

## Next turn

Proceed with **P5-CB135 through P5-CB142 code changes plus compile-only build** following `.agents/Directional/Milestone_G_P5_Post_TB21_Production_Termination_Code_Build_Plan.md`.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. Execute no project binary during the code/build turn.

Preserve all prohibitions: no validator weakening, frequency/count/order ownership selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.
