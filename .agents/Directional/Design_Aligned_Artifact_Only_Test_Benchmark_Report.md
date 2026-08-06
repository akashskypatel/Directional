# Design-Aligned Artifact-Only Test + Benchmark Report

**Date:** 2026-08-06  
**Artifact:** `8974081923`  
**Artifact digest:** `4166325a2f38fa17d05d0d7e71cb147760a1e5208a6e971f60c35665bf3671de`  
**Exact source:** `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`  
**Workflow event:** `b412c8f78a7b597b204b52efbb64afc9899d6517`  
**Workflow run/job:** `31118705108` / `92674426941`

## Package authority

The downloaded archive digest matched GitHub's artifact digest. All **49/49** internal `SHA256SUMS` entries passed. The package recorded an empty tracked source status, **9/9** recursive submodules, five executables, two static libraries, and the complete **26/26** benchmark fixture/input closure.

The event-to-source comparison contains only the bounded compile workflow. The packaged source archive and all test binaries are from exact source `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`.

Only packaged binaries were executed. No configure, compile, relink, patch, regeneration, source edit, test edit, fixture edit, validator edit, CLI, or GUI operation occurred.

## Direct producer acceptance

All four acceptance cases failed direct `SurfaceCells` production with fallback `Fail`, source-grid recovery disabled, no fallback attempt, no remesh output, and output origin `None`.

| Fixture | Result | Terminal | Traces | Arrangement cells | Completed quads |
|---|---:|---|---:|---:|---:|
| Plane | **failed** | `NotProductionReady/completion` | 106 | 9 | 12 |
| Multi-face seam | **failed** | `NotProductionReady/completion` | 137 | 0 | 0 |
| Close sheets | **failed** | `NotProductionReady/completion` | 158 | 0 | 0 |
| Cylinder | **failed** | `NotProductionReady/completion` | 732 | 0 | 0 |

### First authoritative producer failure: plane

The plane progressed through tracing, embedding, arrangement, and completion:

- arrangement cells: **9**;
- completed quads: **12**;
- completion descriptors attempted: **8**;
- completion output was available but rejected before optimization;
- validation failure count: **15**;
- first invalid producer stage: `completion/output-validation`;
- first invalid producer reason: `AggregateCompletionValidationFailure`.

The packaged acceptance test therefore correctly rejects the output rather than counting partial quads as success.

### Remaining analytic failures

Multi-face seam, close sheets, and cylinder reached completion with zero arrangement cells and failed as:

```text
SideSubdivisionRepair:InvalidInputIncidence
```

The failure is fail-closed and does not use fallback or source-grid recovery.

### Determinism

Each bounded benchmark was executed in three independent processes. For every fixture, all stage structural hashes, terminal code/stage, trace count, arrangement count, and completed-quad count matched across all three runs.

Measured pipeline times were:

| Fixture | Run 1 | Run 2 | Run 3 |
|---|---:|---:|---:|
| Plane | 0.045617 s | 0.037224 s | 0.037022 s |
| Multi-face seam | 0.040049 s | 0.039861 s | 0.036478 s |
| Close sheets | 0.073110 s | 0.058266 s | 0.059616 s |
| Cylinder | 0.426269 s | 0.412653 s | 0.450793 s |

No broader benchmark matrix was run because the four analytic producer gates failed.

## Default-suite inventory

| Target | Passed | Failed | Total |
|---|---:|---:|---:|
| Direct producer acceptance | 0 | 4 | 4 |
| Remaining producer tests | 79 | 0 | 79 |
| Completion | 154 | 10 | 164 |
| Validation | 60 | 0 | 60 |
| Compiled API | 8 | 0 | 8 |
| **Non-overlapping total** | **301** | **14** | **315** |

The full producer executable passed **79/83**; its only failures were the four direct acceptance cases.

## Residual test-suite validity findings

The realigned default suite is substantially better than the former milestone inventory, but it still contains tests that should not block the current producer proof.

### Demote from the default gate

1. `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`
   - This wall-clock microbenchmark failed once in the isolated remaining-producer run (`0.000777290 s` versus a `0.000610908 s` limit), then passed in the full producer run and five additional isolated executions.
   - It is scheduler-sensitive and belongs in benchmark/closeout coverage, not a correctness executable.

2. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`
   - It protects the superseded post-hoc same-corner route-repair ledger rather than the intended phase-labelled producer.

3. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse`
   - It asserts exact incremental-recomputation counters, reuse counts, and route-interval inventory. These are implementation details, not a production topology contract.

### Correct invalid or obsolete fixtures

1. `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion`
   - Rollback succeeds, but the fixture then expects successful completion from a `degenerate-normal` bounded-combinatorial embedding. The current fail-closed rejection is safer than the test expectation. The fixture must either provide valid source-supported geometry or assert exact rollback and rejection.

2. `SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`
3. `SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`
   - Their setup no longer creates the claimed precondition (`beforeDefect` is zero), so they do not reach the behavior they claim to test.

Four additional Phase 17 failures expect a candidate or committed mutation from obsolete or topology-invalid synthetic complexes. Their fixtures must be reconstructed from a valid oversampled embedded complex before they remain authoritative default tests.

`FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation` remains a potentially valid directed-incidence regression, but it is downstream of the failed direct producer proof and is not the next implementation target.

## Disposition

The direct producer gate is valid and gives an unambiguous result: **0/4 direct acceptance**. Aggregate unit-test totals must not obscure that result.

The branch must not return to pair-local fan-interval micro-repair. The next Code + Build turn should implement the bounded uniform phase-labelled front proof, beginning with the plane and transporting phase through source-chart transitions. Arrangement should materialize already-decided front cells rather than infer missing connectivity from an overlaid network.
