# Milestone G P5 — TB12 Memory-Frontier Test and Benchmark Report

**Turn:** P5-TB12 artifact-only test and benchmark  
**Artifact:** `8852049639` (`surface-cell-p5-cb58-memory-frontier-linux-release`)  
**Exact source:** `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`  
**Review policy:** `never`  
**Rebuild performed:** no

## Disposition

P5-TB12 does **not** close P5.

The memory-focused checkpoint reduced the observed random-bunny peak working set from `936,484,864 B` to a maximum of `158,949,376 B`, an `83.03%` reduction. All four processes also completed under the `39.228299 s` wall cap. However, those measurements are not successful production-path results: every process failed closed before descriptor completion with the same invalid arrangement-domain identity. The artifact also contains twelve assertion regressions and two deterministic production-matrix segmentation faults.

P5 remains open and PR #8 remains draft and unmerged.

## Artifact verification

The artifact was extracted and executed from an arbitrary path and working directory without rebuilding.

- `source-commit.txt`: `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`.
- Source status: empty.
- Packaged checksums: **36/36 passed** after normalizing the archive-time `artifact/` prefix.
- Expected ELF test and benchmark executables: present.
- Expected static libraries: present.
- Configure/build logs, recursive submodule status, and exact source archive: present.
- Executable-relative `manifest.example.json`, `milestone_g_manifest.json`, `repo_regressions.json`, and `milestone-g/bunny_1k_random.obj`: present.
- The packaged random bunny has exactly 1,000 triangle faces.
- No absolute CI-path fixture failure was observed.

## Focused validation

### New memory/frontier/fixture subset

Filter scope:

- five `PatchDescriptorMilestoneE` budget, route, overlap, and order tests;
- two `PureQuadCompletionPhase18` ownership-inventory tests;
- three `SurfaceCellPipelinePhase20` lifetime and fixture-portability tests;
- the random-bunny regression-manifest test.

Result: **8/11 passed**.

Failures:

1. `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` — expected at least one exact reused completion product; actual reuse count was zero.
2. `SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion` — the expected typed `SameCornerDistinctBoundaryOverlap:` failure was not preserved.
3. `OneCandidateBudgetIsExactAndDoesNotRecurse` — expected at least one exact reused completion product; actual reuse count was zero.

The production-default intermediate-release test, executable-relative fixture-closure test, benchmark-manifest dispatch test, random-bunny generated-field test, canonical ownership test, and complete-inventory test all passed.

### Authoritative suites

| Scope | Passed | Failed |
|---|---:|---:|
| `PatchDescriptorMilestoneE.*` | 15 | 6 |
| Phase 14–18 aggregate | 230 | 0 |
| Milestone G P23 + Phase 20 | 51 | 3 |
| Authoritative non-overlapping total | **296** | **9** |
| Milestone D closure | 4 | 3 |

The six PatchDescriptor failures are:

- `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`;
- `CompletesAuthoritativeComplexThroughMilestoneEEntryPoint`;
- `ExteriorArrangementCyclesAreNotAuthoritativeCompletionPatches`;
- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
- `SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`;
- `OneCandidateBudgetIsExactAndDoesNotRecurse`.

The three Phase 20 failures are:

- `LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails`;
- `PairedBoundaryProofGateIsExplicit`;
- `PairedBoundaryOutputFailsClosedWhenRecoveryIsDisabled`.

The three Milestone D failures are:

- `PartialMultiEdgeInterfaceFailsClosed`;
- `CompleteInterfaceCommitsAndPreservesProtectedRails`;
- `CylindricalOpenStrandCommitsWithTopologyPreserved`.

## Full packaged binary

A direct full run deterministically terminated with signal 11 in:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`.

A rerun excluding that test deterministically terminated with signal 11 in:

- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`.

Each crashing test also exits `139` when run alone, after approximately 12.6 seconds. Excluding both crashing tests, the binary reports **566/578 passed** and the twelve assertion failures listed above. Accounting for the two deterministic crashes, the packaged binary disposition is:

- **566/580 passed**;
- **12 assertion failures**;
- **2 segmentation faults**.

The full binary therefore does not satisfy the production reliability gate even though executable-relative fixture resolution is corrected.

## Random-bunny production processes

All four independent processes used:

- case `bunny_1k_random_medium`;
- `SurfaceCells` backend;
- fallback policy `Fail`;
- source-grid recovery disabled;
- generated `face_edges` degree-four field;
- zero warmups and one measured run per fresh process;
- an arbitrary extraction path and working directory.

| Run | Role | JSON wall | Peak working set | Terminal result |
|---|---|---:|---:|---|
| 1 | Formal | 32.432452 s | 156,839,936 B | Failed closed |
| 2 | Formal | 32.793018 s | 158,949,376 B | Failed closed |
| 3 | Supplementary | 32.390061 s | 156,999,680 B | Failed closed |
| 4 | Supplementary | 33.018193 s | 150,765,568 B | Failed closed |

Aggregates:

- formal wall mean: **32.612735 s**;
- all-process wall mean: **32.658431 s**;
- all-process peak-memory mean: **155,888,640 B**;
- maximum peak memory: **158,949,376 B**;
- memory margin under `1,115,394,560 B`: **956,445,184 B**;
- reduction from P5-TB11 maximum `936,484,864 B`: **777,535,488 B**, or **83.03%**;
- maximum wall margin under `39.228299 s`: **6.210106 s**.

Every record is deterministic in its structural counts and terminal failure:

```text
InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1
```

Common state:

- terminal code/stage: `NotProductionReady` / `completion`;
- output origin: `None`;
- descriptors/completed patches/output quads: `0 / 0 / 0`;
- trace segments: `12,130`;
- arrangement cells: `7,405`;
- simplified cells: `7,405`;
- parity splits: `2,213`;
- side-repair inserted vertices: `8,074`;
- structural candidates/attempts consumed: `0 / 0`;
- full recomputation passes: `1`;
- fallback/recovery: neither used.

Reported completion-owned state is bounded:

- rollback complex estimate: `21,593,612 B`;
- descriptor estimate: `17,119,880 B`;
- assembly estimate: `360 B`;
- peak structural-owned estimate: `38,713,852 B`;
- frontier and product-cache estimates: `0 B`.

Simplification consumes approximately 24.16–24.80 seconds and completion only 0.71–0.87 seconds because completion fails before deriving descriptors. Consequently, the wall and RSS improvements cannot be accepted as successful completion-path performance evidence.

## Root-cause evidence for the next code turn

The exact P5-TB11 to P5-TB12 source diff changed `complete_surface_cell_complex_pass` from retaining the authoritative parity-repaired complex to moving it into side repair. On a permitted side-repair failure, the old implementation restored `parityRepair.complex`; the new implementation moves `sideRepair.complex` while describing it as the unmodified rollback complex.

The relevant semantic change is:

```cpp
// Previous fail-closed rollback
result.preparedComplex = parityRepair.complex;

// P5-CB58 failure path
result.preparedComplex = std::move(sideRepair.complex);
```

This is a strong, test-supported diagnosis rather than a completed proof: the failed side-repair transaction appears to expose a partially mutated complex, which then fails arrangement-domain identity validation before any descriptor is accepted. The three descriptor-empty regressions and the deterministic production failure are consistent with this change.

Exact completion-product reuse also remains zero in fixtures specifically designed to contain unaffected products. The dependency/reuse correction is therefore incomplete.

The two production-matrix segmentation faults require per-case isolation. They must not be suppressed, skipped permanently, or converted to exception handling without correcting the invalid lifetime or topology state.

## Closure-gate result

| Gate | Result |
|---|---|
| Exact artifact/source/status/checksums | Pass |
| Executable-relative fixture closure | Pass |
| Focused memory/frontier tests | Fail |
| Authoritative P5 tests | Fail |
| Full packaged binary | Fail — two SIGSEGVs |
| Four deterministic processes | Pass for determinism only |
| Nonempty pure-quad output | Fail |
| Exact conflict inventory reaches zero | Not reached |
| No fallback/recovery | Pass |
| Wall cap | Pass only on early failure path |
| Memory cap | Pass only on early failure path |
| Improvement versus 936 MB | Measured, but not success-path validated |

## Next authority

Proceed with `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Plan.md` in a code changes + compile-only build turn. Execute no tests, benchmarks, custom meshes, help/list commands, or test discovery in that turn.
