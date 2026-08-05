# Milestone G P5-TB35 Artifact-Only R2E7 Test/Benchmark Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E7 is not accepted as the active R2 checkpoint. It preserves the passing degree-two and genuine four-disk higher-valence contracts, and it advances the interior hard-rail fixture to a much narrower embedding-only failure. However, it does not close the planar `BoundaryFanSectorCoverConflict`, does not restore Phase 17, and does not change the complete-suite failure set relative to P5-TB34.

The next turn is **P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build**. Do not advance to R2F or R3.

This was an artifact-only Test + Benchmark turn. No configure, build, relink, patch, regeneration, source modification, test modification, build-logic modification, or fixture modification occurred.

## Package authority

Validation used artifact `8938299309`, `surface-cell-p5-r2e7-github-source-linux-release`.

- archive SHA-256: `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`;
- exact compiled source: `31c8d9a212f649df7c70fe9291d1fac8c4db7132`;
- workflow event commit: `7d5450cb6411722818844548de59a09c8f4451d5`;
- reviewed/applied diff SHA-256: `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`;
- source status empty;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e7.yml`.

The authority gate passed before any packaged executable ran.

## Focused results

| Scope | Result | P5-TB34 comparison |
|---|---:|---|
| Source-chart R1 | **11/11** | preserved |
| Source validator | **6/6** | preserved |
| Recovery authority | **9/9** | preserved |
| Feature/barrier | **8/8** | preserved |
| Graph-dependent | **5/6** | bunny only; preserved |
| R2 focused | **13/16** | unchanged |
| Milestone D | **5/7** | unchanged test count; hard rail narrowed |
| Phase 14–18 | **235/244** | unchanged |
| Phase 16 | **45/47** | unchanged |
| Phase 17 | **20/26** | six regressions remain |
| Phase 18 | **57/57** | preserved |
| Phase 20 | **46/48** | unchanged |

## Preserved authority

The following contracts remain passing:

- exact R2E5 degree-two exterior/interior mapping;
- genuine R2E6 three-spoke boundary partition with one exterior and four bounded disks;
- no repeated edge/node cycles in the focused R2 contracts;
- source-face-row and whole-orientation directed-incidence hash invariance;
- pinched-fan and disconnected-close-sheet separation;
- Phase 18 **57/57**;
- all source-chart, validator, recovery, and feature/barrier authority scopes.

No validator was weakened and no fallback, recovery, returned-input substitution, or legacy execution was used to satisfy a direct R2 contract.

## Remaining producers

### 1. Planar boundary corner still fails before publication

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` still fails with typed `BoundaryFanSectorCoverConflict` before incidence publication. The new `boundaryCyclicWrapInteriorSectorCount` assertion is therefore never reached.

The R2E7 source treats fan order cyclically, but it still seeds each interior sector from the already selected `intrinsicCandidateNext` and `intrinsicSuccessorWedge`, then validates that selected relation against the cyclic fan. It does not directly enumerate and own every canonical R1 adjacent corner sector. The runtime result shows that merely permitting modulo wrap on the preselected relation is insufficient.

**Inference from source plus runtime:** the next producer must construct the local cover from authoritative R1 corner-sector records themselves, keyed by exact source chart/fan and directed adjacent ray pair, rather than treating the generic intrinsic successor choice as the authoritative sector inventory.

### 2. Hard rail narrows to embedding validity

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` now passes:

- incidence validity and typed failure `None`;
- complete node-local successor bijection;
- predecessor cardinality;
- repeated-node and repeated-edge audits;
- fan-sector, separator, and directed side-pair counters;
- orientation validity;
- bounded-cell disk validity;
- boundary-loop validity;
- Euler validity;
- exactly one exterior and two bounded cells;
- complete halfedge ownership;
- distinct bounded owners for the two hard-rail twins.

Only `embeddingValid` and consequently `topologyValid` fail.

This proves that R2E7 creates the required topological cell count and rail-side ownership, but at least one bounded orbit cannot be embedded into a coherent authoritative source chart. The current rail-side construction uses witness `leftScore` signs and cyclic predecessor/successor order. That is not sufficient evidence that every halfedge in each bounded rail-side orbit belongs to one compatible incident source face/chart.

**Inference from source plus runtime:** derive each rail-side sector from exact source-face corner incidence on the two incident faces of the rail, and audit a common chart/ownership root for every resulting bounded orbit before successor publication. Do not change the later embedding validator.

### 3. Phase 17 remains upstream-invalid

The same six P5-TB34 failures remain:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

No Phase 17 implementation changed. These remain consequences of invalid Phase 16 arrangement inputs and must not be patched in Phase 17.

### 4. Cylinder and bunny remain independent

- Cylinder still fails incidence in `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` and publishes zero direct arrangement cells.
- Bunny remains the separate intrinsic singularity-fan embedding producer.

Neither should be broadened into P5-R2E8 until the planar and hard-rail boundary-corner contract is coherent.

## Direct analytic cases

All direct cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Arrangement | Simplified | Quads | Result | Earliest reported failure | Peak RSS |
|---|---:|---:|---:|---|---|---:|
| plane | 9 | 9 | 12 | fail | `completion/output-validation: AggregateCompletionValidationFailure` | 10,408 KiB |
| multi-face seam | 0 | 0 | 0 | fail | `completion` | 10,156 KiB |
| close sheets | 0 | 0 | 0 | fail | `completion` | 10,208 KiB |
| cylinder | 0 | 0 | 0 | fail | `completion` | 11,416 KiB |

Plane preserves its P5-TB34 inventory. The other three cases remain unacceptable at zero arrangement inventory. No direct case closed.

## Complete suite

The complete suite was started exactly once after all focused and direct scopes. The outer execution wrapper detached while the packaged process continued. The process reached normal Google Test and XML completion and was not rerun.

- tests: **625**;
- passed: **597**;
- failures: **28**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **206.053 s**;
- normal test-process termination: yes;
- exact wrapper exit code: unavailable after detachment;
- exact maximum RSS: unavailable after detachment.

The failure set is exactly identical to P5-TB34: zero closures and zero new failures.

Runtime is substantially higher than P5-TB34's 73.085 s, dominated by the same production-matrix and bunny cases. No performance disposition is made because the outer wrapper detached, exact RSS is unavailable, and runner-level variance affects the dominant cases.

## Decision

Proceed with **P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build**.

P5-R2E8 must replace the remaining generic-successor dependency at affected boundary nodes with a direct canonical corner-sector inventory and must derive hard-rail sides from exact incident source-face/chart authority. Preserve the passing degree-two and four-disk paths and leave Phase 17 and all downstream validators unchanged.

## Evidence

- machine summary: `benchmark-results/p5-tb35-summary.json`;
- raw evidence bundle: `directional-p5-tb35-8938299309-evidence.zip`;
- evidence SHA-256: `c9e4a77b2b9709921a445fb8295a6eff16e62268325a844c1a886deff08e595b`;
- archive entries: **224**.

Preserved prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
