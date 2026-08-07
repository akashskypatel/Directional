# Gate 1 Regression Restoration — Artifact-Only Test + Benchmark Report

## Turn declaration

```text
Active design gate: Gate 1 — uniform phase-front plane regression restoration
Earliest failing fixture: plane__surface_cells
Missing design contract: complete zero-turn prescribed-field metadata must be consumed by the authoritative planar phase-front route instead of falling through to generic tracing and completion
Smallest completed action: execute and preserve the exact restoration artifact without rebuilding or editing source, tests, fixtures, manifests, or validators
Observable material-progress condition: plane returns direct validated CompletedSurfaceCells output while the multi-face seam retains its deterministic 64-quad result
Explicitly deferred work: source changes, close-sheet isolation, cylinder holonomy, bunny/vase completion, validator timing, fallback/recovery, and historical completion cleanup
```

## Artifact authority

- artifact: `directional-g1-regression-restoration-local-build-artifact.zip`;
- artifact SHA-256: `c516af42f6aa388ef219408ef63e939490176385e976885f1ea9176ec3609e20`;
- internal checksums: **44/44**;
- source commit: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- source blob: `850971a60b75dd84a81ddd4d260998f7ec9c326a`;
- packaged closure: five executables, two project static libraries, 27 fixture/input files.

The archive was extracted into a fresh directory. The only runtime-layout action was creating `bin/test-data -> ../test-data`; no packaged file was modified.

## Direct acceptance

| Fixture | Result | Terminal | Traces | Arrangement | Completed candidates | Validation failures | Output |
|---|---:|---|---:|---:|---:|---:|---|
| Plane | **fail** | `NotProductionReady:completion` | 106 | 9 | 12 | 15 | none |
| Multi-face seam | **pass** | `None` | 256 | 65 | 64 | 0 | 81 vertices, 64 pure quads |
| Close sheets | **fail** | `NotProductionReady:completion` | 158 | 0 | 0 | 0 | none |
| Cylinder | **fail** | `NotProductionReady:completion` | 732 | 0 | 0 | 0 | none |
| `bunny_1k_random` | **fail** | `NotProductionReady:completion` | 80,862 | 0 | 0 | 0 | none |
| Vase | **fail** | `NotProductionReady:completion` | 116,922 | 0 | 0 | 0 | none |

Direct acceptance: **1/6**.

Every case requested and executed `SurfaceCells`, used fallback policy `Fail`, attempted no fallback, and used no recovery. No timeout was treated as correctness evidence.

## Determinism and direct authority

Independent bounded processes:

- plane, seam, close sheets, and cylinder: three each;
- bunny and vase: two each.

All six cases were structurally deterministic across their processes.

The seam retained the required direct result:

- output origin `CompletedSurfaceCells`;
- 64 accepted direct cells and 64 output quads;
- 81 output vertices;
- zero validation failures and zero non-quads;
- structural output hash `a8972efd7c4900a4`;
- no fallback or recovery.

The plane retained the exact pre-restoration generic signature. Its stage hashes and counts did not change:

| Stage | Hash | Count |
|---|---|---:|
| feature | `dbcb95cbdb24d00d` | 43 |
| metric | `aad884a80b65bf5d` | 20 |
| relief | `b41394be2321cadb` | 24 |
| tracing | `9a3bc6f1202818b1` | 106 |
| strands | `6e5a5774bd948e54` | 46 |
| embedding | `3b751ab8dd34e73e` | 46 |
| arrangement | `6e42bc969e9d7fba` | 9 |
| completion | `c538eeec73e84d2d` | 12 |

The restoration therefore made no observable runtime change on the real plane path. Gate 1 remains red.

## Default suites

| Suite | Passed | Total | Failures |
|---|---:|---:|---:|
| Remaining producer suite | 79 | 80 | 1 |
| Completion suite | 154 | 164 | 10 |
| Validation suite | 60 | 60 | 0 |
| Compiled API suite | 8 | 8 | 0 |
| **Aggregate** | **301** | **312** | **11** |

The producer failure is `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`, a scheduler-sensitive timing check and not the active constructive gate.

Completion failures remain:

1. `FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation`
2. `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion`
3. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`
4. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse`
5. `SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex`
6. `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates`
7. `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate`
8. `SurfaceComplexSimplificationPhase17.TransactionalMutationPreservesHardRailSupport`
9. `SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`
10. `SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`

These do not supersede the earlier direct Gate 1 failure.

## Why the restoration branch was unreachable

Static review of the exact archived source established:

1. `finalize_surface_cell_raw_cross_field()` calls `principal_matching(rawField, false)`;
2. it copies `rawField.matching` and `rawField.effort` into `CrossFieldResult`;
3. it calls `populate_cross_field_edge_transitions(rawField, crossField)`;
4. the pipeline passes those populated containers into `build_surface_cell_network()` and then the phase-front producer.

The restoration patch only selected metadata-free transport when the matching, effort, and transition containers were empty. The real prescribed plane path populates all three before tracing, so that branch was never selected. This is consistent with the unchanged plane stage hashes.

## Leading next-failure candidate

The Gate 1 versus Gate 2 source delta introduced a requirement that every consecutive selected segment interval share one source edge before authoritative branch transport is resolved. A lattice line that passes exactly through a triangulation vertex can produce consecutive source-face intervals that meet at the vertex but do not share a single edge.

This is a **source-review inference, not runtime-proven diagnosis**. The current phase-front producer returns only a Boolean failure, so the exact first rejection predicate is not observable in the artifact. The next turn must expose a bounded fail-closed phase-front rejection reason and repair only the confirmed first invariant. If the candidate is confirmed, the general correction is an ordered source-vertex fan transition that applies every crossed authoritative edge transition, not a positional merge or arbitrary face choice.

## Evidence

- evidence archive: `directional-g1-regression-restoration-artifact-only-test-evidence.zip`;
- evidence archive SHA-256: `57e2f247dbf1cb7ad4c2470f30fa8ec7705b888ec891515ce61b76c329cd2591`;
- evidence files covered by recursive checksums: **114**;
- contents: raw command logs, direct-test XML/JSON, 16 benchmark-process JSON outputs, default-suite results, command inventories, review images, and machine-readable runtime summary.

## Conclusion

The restoration is rejected as a Gate 1 fix. The seam remains a proven mandatory regression. The next authorized turn is the bounded Code + Build plan in `.agents/Directional/Gate_1_Live_Transition_Path_Code_Build_Plan.md`.
