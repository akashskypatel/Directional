# Milestone G P5 — Completion Ownership Test + Benchmark Report

**Turn type:** Test and benchmark only  
**Artifact:** `8840866875`, `surface-cell-p5-branch-linux-release`  
**Exact compiled source:** `dcef9fbf65930b20db93128deb193f10702dc9c7`  
**Artifact digest:** `sha256:d67a464b2f2c2f6d58bbb9fa15a0e87009176698f14d19a9054facfbcb97cd90`  
**Rebuild performed:** No

## Artifact validation

- All ten packaged checksums passed.
- `source-commit.txt` matches `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- `source-status.txt` is empty.
- Packaged test and benchmark executables are Linux x86-64 ELF binaries.
- The exact source archive and recursive submodule revisions are present.

## Test results

| Scope | Passed | Failed | Result |
|---|---:|---:|---|
| New ownership discriminator subset | 3 | 1 | Failed |
| Corrected `PatchDescriptorMilestoneE.*` | 14 | 1 | Failed |
| Phase 14–18 aggregate | 218 | 4 | Failed |
| Milestone G P23 + Phase 20 | 52 | 0 | Passed |

The required suites contain **289 test executions**, with **284 passes and 5 unique failures**.

### Ownership diagnostic failure

`PureQuadCompletionPhase18.CompletedFaceOwnershipCanonicalizesRotationAndReversal`

The conflict is correctly classified as `CompletionTemplateOwnership`, but the serialized corner arrays are not canonical under reversal. The first face reports:

```text
8669075232843032540,15588106157561556657,
4060388610524016314,10979419535242540431
```

The reversed equivalent face reports:

```text
8669075232843032540,10979419535242540431,
4060388610524016314,15588106157561556657
```

The same mismatch occurs for authoritative hashes. The implementation compares forward and reversed cycles correctly for classification, but `copy_conflict_corner_diagnostics()` always serializes `stitchForward.sourceIndices`. The diagnostic contract therefore remains orientation-dependent.

### Valid shared-boundary regressions

These tests all receive an empty patch vector because `complete_pure_quad_patch()` rejects at least one valid cylinder patch before assembly:

- `PureQuadCompletionPhase18.MilestoneECylinderStitchesPeriodicPatchBoundaries`
- `PureQuadCompletionPhase18.StitchingRejectsInconsistentSharedBoundaryGeometry`
- `PureQuadCompletionPhase18.StitchingIsPatchOrderInvariant`

The shared helper projects boundary vertices onto the complete source cylinder. A source vertex or source-edge point can legitimately be represented by any incident source-face chart. `validate_completion_domain_ownership()` currently requires every stored provenance face—including boundary vertices—to be a literal member of `patch.sourceFaces`. That rule rejects valid chart aliases and prevents the tests from reaching their intended stitching contracts.

This is an implementation regression, not a reason to weaken those test contracts.

### Remaining Milestone E fixture failure

`PatchDescriptorMilestoneE.SharedEdgeParityRepairConforminglyCompletesTwoOddCells`

The revised fixture still fails its first precondition:

```text
complex.diagnostics.topologyValid == false
```

It therefore still does not construct the topology-valid two-cell odd arrangement required to test parity repair. The other two corrected Milestone E fixtures now pass.

## Direct random-bunny results

Two independent runs used:

- case `bunny_1k_random__surface_cells`;
- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled;
- no warmup and one measured run per process.

Both runs failed deterministically before global assembly:

```text
CompletionOwnershipSourceSupportEscape
```

| Metric | Run 1 | Run 2 |
|---|---:|---:|
| Wall time | 25.018685 s | 24.651439 s |
| Peak working set | 872,894,464 B | 872,677,376 B |
| Arrangement cells | 21,298 | 21,298 |
| Descriptors attempted | 21,297 | 21,297 |
| Descriptors completed | 21,193 | 21,193 |
| Descriptors failed | 104 | 104 |
| Required unresolved endpoints | 0 | 0 |
| Accepted output quads | 0 | 0 |
| Completion stage | 5.183686 s | 5.169346 s |

The fixture hash, terminal failure, counts, and every input/output stage structural hash matched across both runs. The completion output hash was also identical.

The new proof gate prevents assembly, so the previous patches `378/394` are not reclassified in this artifact. No conclusion can be made that the earlier duplicate conflict is resolved; it is masked by the earlier source-support rejection.

## Root-cause classification

The production failure and the valid cylinder regressions point to the same invalid ownership predicate:

```cpp
sourceFaces.count(provenance.face) != 0
```

A `SurfacePoint` on a source vertex or source edge is supported by all incident source faces. Its stored `face` is one valid chart, not its complete source support. Existing source-authoritative validation already computes incident supported faces from barycentric support. Completion ownership must use equivalent intrinsic source-entity semantics:

- face-interior point: stored face must belong to the patch support;
- source-edge point: at least one incident face of that edge must belong to patch support;
- source-vertex point: at least one incident face of that vertex must belong to patch support;
- generated patch-interior point: remain strictly confined to the allowed patch faces and patch-local identity.

Boundary identity validation remains authoritative and must not be replaced with positional tolerance.

## Performance comparison

Current two-run means:

- wall time: **24.835062 s**;
- peak working set: **872,785,920 B**;
- completion stage: **5.176516 s**.

Compared with baseline artifact `8838467442`:

| Metric | Baseline | Current mean | Change |
|---|---:|---:|---:|
| Wall time | 22.981569 s | 24.835062 s | +8.07% |
| Peak working set | 749,375,488 B | 872,785,920 B | +16.47% |
| Completion stage | 4.168940 s | 5.176516 s | +24.17% |

Compared with previous artifact `8840174777`:

| Metric | Previous mean | Current mean | Change |
|---|---:|---:|---:|
| Wall time | 26.775241 s | 24.835062 s | -7.25% |
| Peak working set | 1,696,000,000 B | 872,785,920 B | -48.54% |
| Completion stage | 6.318718 s | 5.176516 s | -18.08% |

The ownership compaction substantially corrected the prior memory regression, but completion remains slower and more memory-intensive than the baseline.

## Diagnostics gap

`SurfaceCellComplexCompletionResult::completionOwnershipRepairAttempts` is not propagated through `SurfaceCellContextProducts`, `RemeshDiagnostics`, or benchmark JSON. The current run did not reach assembly repair, but the next artifact must expose this count so a validation turn can distinguish zero attempts, exhausted alternatives, and successful variant advancement.

## Disposition

P5 remains incomplete. PR #8 must stay draft and unmerged.

The next authoritative turn is **code changes + compile-only build**. It must repair intrinsic source-support containment, canonicalize serialized conflict corners under reversal, construct a genuinely topology-valid parity fixture, propagate ownership-repair diagnostics, and compile without executing tests or benchmarks.
