# Milestone G P5 — Global Ownership Frontier P5-TB11 Test + Benchmark Report

**Turn:** artifact-only test and benchmark without rebuilding  
**Artifact:** `8848599037` (`surface-cell-p5-global-frontier-linux-release`)  
**Exact compiled source:** `643cc483e430d2cd161dde94a983aedac4be57dd`  
**Implementation commit:** `413660dba15fe1376adc13aa80aea0e1ba99194e`  
**Review policy:** `never`

## Artifact verification

- Extracted to an arbitrary path: `/mnt/data/p5-tb11`.
- `source-commit.txt` matches the exact compiled source.
- `source-status.txt` is empty.
- All **11/11** checksums pass after normalizing the archive-time `artifact/` prefix.
- Both executables are Linux x86-64 ELF binaries; both libraries are valid static archives.
- `bin/test-data/benchmarks/fixtures/manifest.example.json` is present.
- No rebuild or implementation, test, benchmark-source, build-system, or workflow edit occurred.

## Test results

| Scope | Passed | Failed |
|---|---:|---:|
| Focused global-frontier subset | 5 | 2 |
| `PatchDescriptorMilestoneE.*` | 15 | 6 |
| Phase 16 + Phase 18 | 89 | 1 |
| Phase 14–18 aggregate | 229 | 1 |
| Milestone G P23 + Phase 20 | 50 | 2 |
| Full packaged binary | 549 | 29 |

The authoritative non-overlapping P5 total is **294/303 passed**: 15/21 PatchDescriptor, 229/230 Phase 14–18, and 50/52 P23/Phase20.

### Focused failures

- `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`
  - completion succeeds, but `completionOwnershipReusedPatchCompletions` is `0`.
- `PureQuadCompletionPhase18.CompletedFaceOwnershipCanonicalizesRotationAndReversal`
  - exact ownership classification is present, but the bounded failure string no longer includes required backend and corner-kind diagnostics.

### Additional authoritative regressions

- PatchDescriptor:
  - `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`;
  - `CompletesAuthoritativeComplexThroughMilestoneEEntryPoint`;
  - `ExteriorArrangementCyclesAreNotAuthoritativeCompletionPatches`;
  - `SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`;
  - `OneCandidateBudgetIsExactAndDoesNotRecurse`.
- Phase 20:
  - `PairedBoundaryProofGateIsExplicit`;
  - `PairedBoundaryOutputFailsClosedWhenRecoveryIsDisabled`.

Three Milestone D closure tests also fail in the full binary: `PartialMultiEdgeInterfaceFailsClosed`, `CompleteInterfaceCommitsAndPreservesProtectedRails`, and `CylindricalOpenStrandCommitsWithTopologyPreserved`.

Do not synthetically change these expectations. The next code turn must first prove each fixture reaches the scenario it claims to test, then fix production behavior or correct an invalid fixture.

## Artifact portability finding

`SurfaceCellPipelinePhase20.BenchmarkManifestDispatchesBackends` passes from the arbitrary extraction path, so the new executable-relative `manifest.example.json` fix works.

The complete packaged test binary is still not self-contained. Seventeen full-suite failures attempt to open absolute compile-runner paths:

- `/home/runner/work/Directional/Directional/benchmarks/fixtures/milestone_g_manifest.json`;
- `/home/runner/work/Directional/Directional/benchmarks/fixtures/repo_regressions.json`.

These failures affect Milestone G P26/P27 and `RemeshRegressionPhase00`. No source-path staging workaround was used.

## Direct random-bunny results

Four authoritative fresh processes used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, zero warmups, one measured run, and the packaged benchmark binary with the mesh and manifest from the packaged source archive.

| Run | Role | Pipeline | Wall | Peak working set | `/usr/bin/time` max RSS | Completion |
|---|---|---|---:|---:|---:|---:|
| 1 | Formal | failed closed | 61.437552 s | 936,361,984 B | 936,361,984 B | 30.921753 s |
| 2 | Formal | failed closed | 62.645585 s | 936,419,328 B | 936,419,328 B | 28.611349 s |
| 3 | Supplementary | failed closed | 61.252152 s | 936,484,864 B | 936,484,864 B | 28.666135 s |
| 4 | Supplementary | failed closed | 59.776277 s | 936,386,560 B | 936,386,560 B | 29.249247 s |

Formal means:

- wall: **62.041569 s**;
- peak working set: **936,390,656 B**;
- completion: **29.766551 s**.

All-four means:

- wall: **61.277891 s**;
- peak working set: **936,413,184 B**;
- completion: **29.362121 s**.

Every process exits cleanly and remains below the `1,115,394,560 B` memory cap. The maximum measured resident set is **936,484,864 B**, leaving **178,909,696 B** of margin.

Every process exceeds the `39.228299 s` wall cap, fails closed at completion, reports output origin `None`, and emits no quad mesh. No fallback or source-grid recovery occurs.

## Deterministic production failure

All four records match on fixture hash, terminal failure, repair log, conflict counts, and budget evidence.

The complete assembly inventory begins with **143** completion-template ownership conflicts. The completion-variant loop performs **41** sequential committed variant repairs and reduces the inventory to **92** exact same-corner claims. The terminal record is:

`SameCornerStructuralRepairExhausted:candidate-budget:DuplicateStitchedQuad:firstPatch=916;firstLocalQuad=1;secondPatch=907;secondLocalQuad=0;classification=same-corner-distinct-boundary;inventoryCount=92`

The controller reports:

- route candidates: **92**;
- structural candidate budget: **2**;
- candidates consumed: **0**;
- structural attempts: **0**;
- full completion passes: **1**;
- incremental passes: **0**;
- exhaustion: `candidate-budget`;
- pre/post inventory counts and hashes: zero because no frontier transaction executes.

## Root cause

The global frontier is constructed, but the budget gate runs before component partitioning and batching:

`candidatesConsumed + frontier.size() > candidateBudget`

This treats every exact conflict candidate as a separately budgeted evaluation. With 92 candidates and a default budget of 2, production fails before the component graph, atomic batched subdivision, or exact completion-product reuse path can execute.

This contradicts the intended contract. The budget must bound transactions/evaluations, not reject a topology-derived independent batch merely because it contains many exact claims.

A second performance blocker precedes structural repair: the completion-template loop performs 41 sequential full assembly cycles. Completion alone averages **29.362121 s**, and total wall averages **61.277891 s**. Correcting only the structural budget gate is unlikely to satisfy the wall cap unless completion-template ownership is also handled globally or incrementally.

## Disposition

P5-TB11 **fails**.

- Packaged manifest dispatch: fixed for the one targeted fixture.
- Complete artifact portability: failed.
- Focused/global regression suites: failed.
- Global ownership frontier reaches zero: failed.
- Direct random-bunny output: failed.
- Wall gate: failed.
- Memory gate: passed.
- Determinism: passed.
- Fallback/recovery prohibition: passed.

P5 remains open. PR #8 must remain draft and unmerged.

The next authoritative turn is **code changes + compile-only build** using `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Candidate_Budget_Code_Build_Plan.md`.
