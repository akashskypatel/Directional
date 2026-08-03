# Milestone G P5 — TB13 Rollback Integrity Test and Benchmark Report

**Turn:** P5-TB13 artifact-only test and benchmark  
**Artifact:** `8860409984` (`surface-cell-p5-cb66-rollback-integrity-linux-release`)  
**Exact source:** `074ec5d125b531db03fcfbda9d6d3654bfc696b7`  
**Review policy:** `never`  
**Rebuild performed:** no

## Disposition

P5-TB13 does **not** close P5.

The compile-only checkpoint restored several local contracts, including the synthetic bit-exact subdivision rollback regression, successful-result finalization, typed semantic-overlap reporting, paired-boundary behavior, and multiple previously failing Milestone E fixtures. It did not restore the production path.

Four fresh random-bunny processes still fail deterministically before descriptor acceptance with:

```text
InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1
```

The production side-repair solve reports success (`918 -> 0` infeasible cells and `8,074` inserted vertices), so this is not the rejected-transaction rollback path that P5-CB59 targeted. The invalid domain is created or exposed on the **successful subdivision output**. All four processes produce zero accepted descriptors, zero completed patches, and zero output quads.

Three bunny matrix tests still terminate with signal 11, exact product reuse remains zero, one authoritative rail-propagation test fails, the explicit simplification API no longer performs its documented fixed-point candidate refresh, and all four production runs exceed the wall-time gate.

PR #8 remains draft and unmerged.

## Artifact verification

The artifact was extracted and executed from an arbitrary working directory without rebuilding.

- `source-commit.txt`: `074ec5d125b531db03fcfbda9d6d3654bfc696b7`.
- Source status: empty.
- Packaged checksums: **36/36 passed** after normalizing the archive-time `artifact/` prefix.
- Expected x86-64 ELF test and benchmark executables: present.
- Expected static libraries: present.
- Configure/build logs, recursive submodule status, and exact source archive: present.
- Executable-relative fixture closure: present.
- Packaged fixture files: **26**.
- Packaged random bunny: exactly **1,000 triangle faces**.
- Temporary source-transfer workflow/payload entries in the source archive: **0**.
- Compile-only workflow entries in the source archive: **1**.

## Focused validation

The focused rollback, successful-result, reuse, semantic-overlap, rail, paired-boundary, fixture, ownership, and Milestone D subset passed **9/15**.

Passed:

- `PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex`;
- `PatchDescriptorMilestoneE.AlreadySuccessfulComplexPerformsNoStructuralRepair`;
- `PatchDescriptorMilestoneE.SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`;
- both focused Phase 18 ownership-inventory tests;
- production intermediate release;
- packaged fixture closure;
- both paired-boundary Phase 20 tests.

Failed:

1. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` — expected reused patch completions greater than zero; actual zero.
2. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse` — expected reused patch completions greater than zero; actual zero.
3. `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` — authoritative arcs exist, but no arrangement halfedge retained `railId >= 0`.
4. `MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed` — fixture precondition failed: internal interface size was zero.
5. `MilestoneDClosure.CompleteInterfaceCommitsAndPreservesProtectedRails` — fixture precondition failed: internal interface size was zero.
6. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` — fixture precondition failed: the constructed input complex was already topology-invalid.

The three Milestone D failures are invalid test scenarios, not evidence to weaken production validation. Their fixtures must be corrected to construct the topology they claim to test.

## Authoritative suites

| Scope | Passed | Failed |
|---|---:|---:|
| `PatchDescriptorMilestoneE.*` | 20 | 2 |
| Phase 14–18 aggregate | 228 | 2 |
| Milestone G P23 + Phase 20 | 53 | 1 |
| Authoritative non-overlapping total | **301** | **5** |
| Milestone D closure | 4 | 3 |

The two Phase 17 failures are:

- `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate`.

Both fail because P5-CB63 disabled post-commit candidate refresh for the explicit candidate API. These tests establish the existing fixed-point contract and remain valid. The next implementation must restore dependency-bounded recomputation rather than changing the expectations.

## Full packaged binary and matrix isolation

The packaged binary contains **590 tests**.

A direct full run terminates with signal 11 in:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`.

The per-case markers identify the active case as:

```text
bunny_1k_random__surface_cells
```

Independent runs also terminate with signal 11 in:

- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`;
- `ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/7`.

Parameterized surface-cell cases `0–6` and `8` pass. Case `7` is the random bunny. This proves that the new isolation structure works and narrows the unresolved lifetime/topology crash to the random-bunny result path.

Excluding the three deterministic crash tests, the binary reports **579/587 passed** with the eight assertion failures listed above. The complete disposition is therefore:

- **579/590 passed**;
- **8 assertion failures**;
- **3 signal-11 tests**.

## Random-bunny production processes

All four independent processes used:

- case `bunny_1k_random_medium`;
- generated `face_edges` degree-four field;
- `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- zero warmups and one measured run;
- arbitrary extraction and working directories.

| Run | Role | Wall | Peak working set | Result |
|---|---|---:|---:|---|
| 1 | Formal | 44.680662 s | 185,577,472 B | Failed closed |
| 2 | Formal | 40.231057 s | 185,614,336 B | Failed closed |
| 3 | Supplementary | 43.471956 s | 185,479,168 B | Failed closed |
| 4 | Supplementary | 40.819858 s | 185,352,192 B | Failed closed |

Aggregates:

- formal wall mean: **42.455860 s**;
- all-process wall mean: **42.300883 s**;
- wall range: **40.231057–44.680662 s**;
- all-process peak-memory mean: **185,505,792 B**;
- maximum peak memory: **185,614,336 B**;
- peak memory margin under `1,115,394,560 B`: **929,780,224 B**;
- increase from P5-TB12 early-failure maximum `158,949,376 B`: **26,664,960 B**, or **16.78%**;
- reduction from P5-TB11 maximum `936,484,864 B`: **750,870,528 B**, or **80.18%**.

Every run fails the wall gate `<= 39.228299 s`; overruns are **1.002758–5.452363 s**. Every run passes the formal memory cap.

Common deterministic state:

- terminal code/stage: `NotProductionReady` / `completion`;
- completion failure: `InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1`;
- descriptors/completed patches/output quads: `0 / 0 / 0`;
- trace segments: `12,130`;
- arrangement cells: `7,405`;
- simplified cells: `7,405`;
- odd cells before/after parity repair: `1,860 / 0`;
- parity splits: `2,213`;
- side infeasible cells before/after: `918 / 0`;
- side inserted vertices: `8,074`;
- exact reused patch completions: `0`;
- fallback/recovery: neither used.

The successful side-repair output has different before/after identity hashes:

- before: `16943071503504169972`;
- after: `7392717407632751531`.

That difference is expected for a committed subdivision and is not a rollback failure. The key failure is that descriptor derivation reports the first resulting arrangement domain as invalid. The next turn must validate every newly inserted node and replacement halfedge against canonical domain identity immediately after successful subdivision, before the result reaches descriptor compaction.

Stage timing averages:

- tracing: **6.900454 s**;
- arrangement: **1.292477 s**;
- simplification: **31.880934 s**;
- completion: **1.035549 s**.

The wall regression is dominated by simplification, but performance changes must be addressed only after the successful topology path is restored.

## Root-cause findings for the next code turn

### 1. Successful subdivision identity is still invalid

The production process does not take the rejected side-repair rollback branch. Side repair succeeds and mutates the complex. `derive_patch_descriptors` then rejects cell `2` because its `SurfaceCellDomainIdentity.valid` is false.

The current identity is invalid only when a boundary is empty, a boundary halfedge/node reference is invalid, a boundary node has no valid source occurrence, or the cell source support is invalid. Add typed diagnostics identifying the exact cell, halfedge, endpoint node, occurrence, component, sheet, and source face that fails. Do not continue from an invalid successful transaction.

### 2. Reuse lookup is still keyed by allocation-local `cellId`

P5-CB61 removed compact allocation IDs from `exact_patch_dependency_equal`, but the cache lookup still performs:

```text
reusableProducts->products.find(descriptor.cellId)
```

If cell IDs change after a local rebuild, exact equality is never reached. The cache must be keyed or indexed by the canonical semantic dependency identity, with exact collision-safe comparison, not by `cellId`.

### 3. Explicit simplification fixed-point behavior was removed

P5-CB63 only refreshes candidates when `topologyHealingOnly` is true. Existing Phase 17 tests require candidate recomputation after committed explicit candidates. Restore the established fixed-point behavior with dependency-bounded refresh. If an isolated one-transaction mode is needed, expose it explicitly rather than silently changing the default API contract.

### 4. Milestone D fixtures remain invalid

The two-interface fixture produces no shared multi-edge interface, and the cylinder fixture is topology-invalid before simplification. Correct the input construction and retain fail-fast preconditions. Do not alter production behavior to satisfy invalid fixtures.

### 5. Rail metadata does not reach arrangement halfedges

Authoritative rails, trace seeds, FlowRep rails, and embedded arrangement arcs are present. Only the final arrangement halfedges lack rail identity. Fix arc-to-halfedge metadata/provenance propagation and retain compact rail proof through result transfer.

### 6. Random-bunny returned-result lifetime remains unsafe

The benchmark process returns a fail-closed JSON result, but the GP26/GP27 tests segfault on the random-bunny case, including the new test that destroys temporary inputs before reading the returned result. Audit all pointers, spans, references, and views retained by `RemeshResult`, `SurfaceCellPipelineContext`, descriptors, completion products, lineage, and debug artifacts.

## Closure-gate result

| Gate | Result |
|---|---|
| Exact artifact/source/status/checksums | Pass |
| Executable-relative fixture closure | Pass |
| Synthetic failed-subdivision rollback | Pass |
| Successful subdivision domain identity | Fail |
| Exact unaffected-product reuse | Fail |
| Phase 14–18 | Fail |
| P23 + Phase 20 | Fail |
| Milestone D | Fail — invalid fixtures |
| Full packaged binary | Fail — 3 SIGSEGVs |
| Four deterministic processes | Pass for determinism only |
| Nonempty pure-quad output | Fail |
| Zero ownership conflicts | Not reached |
| No fallback/recovery | Pass |
| Wall cap | Fail in all four runs |
| Memory cap | Pass on early failure path only |

## Next authority

Proceed with `.agents/Directional/Milestone_G_P5_Successful_Subdivision_Identity_Code_Build_Plan.md` in a code changes + compile-only build turn. Execute no tests, benchmarks, custom meshes, compiled binaries, help/list commands, or test discovery in that turn.
