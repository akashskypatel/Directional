# Milestone G P5 — TB14 Successful-Subdivision Identity Test and Benchmark Report

**Turn:** P5-TB14 artifact-only test and benchmark  
**Artifact:** `8864496877` (`surface-cell-p5-cb74-successful-identity-linux-release`)  
**Exact source:** `188baf35a13c02b20424cd72fb9c6d8fe81ec9fc`  
**Digest:** `sha256:5629045697a3819f3caeb9416d0d4bbe941d6981d6e226420c5899062378a088`  
**Review policy:** `never`  
**Rebuild performed:** no

## Disposition

P5-TB14 does **not** close P5.

The artifact restored the Phase 14–18 simplification suite and added a truthful typed audit for the successful-subdivision failure, but the production path remains invalid and unstable:

- the only completed random-bunny benchmark fails before descriptor acceptance with a `mixed-source-sheet` domain identity;
- three additional benchmark processes do not terminate within their observation windows;
- all three former bunny matrix tests still terminate with signal 11 before the pipeline returns;
- exact reusable-product reuse remains zero;
- the production side-repair rollback regression reports a structural hash mismatch;
- rail identity still does not reach final arrangement halfedges;
- all three reconstructed Milestone D fixtures still fail their own topology preconditions;
- four production end-to-end fixtures and the Phase 20 cylinder regression fail;
- no process produces nonempty pure-quad output.

PR #8 remains open, draft, and unmerged.

## Artifact integrity

The artifact was extracted to an arbitrary path and executed without rebuilding.

- `source-commit.txt`: `188baf35a13c02b20424cd72fb9c6d8fe81ec9fc`.
- Source status: empty.
- Artifact ZIP digest: exact match.
- Packaged checksums: **36/36 passed** after normalizing the archive-time `artifact/` prefix.
- x86-64 ELF test and benchmark executables: present.
- Static core and pipeline libraries: present.
- Configure/build logs, recursive submodule status, and source archive: present.
- Executable-relative fixture closure: present.
- Packaged fixture files: **26**.
- Packaged random bunny: **502 vertices / 1,000 triangle faces**.

## Focused validation

The focused successful-subdivision, rollback, reuse, simplification, rail, and Milestone D subset passed **3/10**.

Passed:

- `PatchDescriptorMilestoneE.SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity`;
- `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate`.

Failed:

1. `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` — `rollbackEquivalent` is reported, but the returned complex hash is `1699136895805365811` instead of the committed pre-transaction hash `15567413043167398147`.
2. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` — exact reused completions remain zero.
3. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse` — exact reused completions remain zero.
4. `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` — no final arrangement halfedge has `railId >= 0`.
5. `MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed` — reconstructed fixture still has zero shared interface halfedges.
6. `MilestoneDClosure.CompleteInterfaceCommitsAndPreservesProtectedRails` — reconstructed fixture still has zero shared interface halfedges.
7. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` — reconstructed cylinder remains topology-invalid before simplification.

## Authoritative suites

| Scope | Passed | Failed |
|---|---:|---:|
| Focused TB14 subset | 3 | 7 |
| `PatchDescriptorMilestoneE.*` | 20 | 4 |
| Phase 14–18 aggregate | **230** | **0** |
| Milestone G P23 + Phase 20 | 52 | 2 |
| Milestone D closure | 4 | 3 |

The Phase 14–18 fixed-point regressions are restored. This is the only major gate closed by this artifact.

New or remaining failures include:

- `PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex` now reaches `MissingCommonSourceChart` instead of its intended `InvalidMidpointEmbedding` scenario. The fixture must supply a valid common chart before testing invalid midpoint embedding, or the two failure contracts must be split into separate tests.
- `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput` fails `NotProductionReady/validation`.

## Full packaged disposition

The packaged binary contains **592 tests**.

A direct full run terminates with signal 11 inside:

```text
MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback
case=bunny_1k_random__surface_cells
last marker=[P5_P26_BEFORE_PIPELINE]
```

Running all tests except the three known crash tests completes:

- **576/589 passed**;
- **13 assertion failures**.

Adding the three independently confirmed signal-11 tests gives the complete disposition:

- **576/592 passed**;
- **13 assertion-failing tests**;
- **3 signal-11 tests**.

Additional end-to-end failures are:

- `MilestoneGP26.PlaneAndMechanicalFixturesCompleteEndToEnd`;
- `MilestoneGP26.CylinderCompletesEndToEnd`;
- `MilestoneGP26.MultiFaceSeamCompletesEndToEnd`;
- `MilestoneGP26.TorusCompletesEndToEnd`.

Plane, cylinder, and multi-face seam reach output validation and fail with substantial topology, geometry, sheet, and orientation violations. Torus and mechanical-feature fail earlier in completion.

## Bunny signal-11 isolation

All three formerly crashing tests still terminate with exit code `139`:

| Test | Last marker |
|---|---|
| `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` | `[P5_P26_BEFORE_PIPELINE] bunny_1k_random__surface_cells` |
| `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` | `[P5_P27_BEFORE_PIPELINE] bunny_1k_random__surface_cells` |
| `ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/7` | `[P5_P27_PARAM_BEFORE_PIPELINE] bunny_1k_random__surface_cells` |

No `AFTER_PIPELINE` marker is reached. The crash therefore occurs inside the pipeline, not during returned-result reads or destruction. The previous lifetime diagnosis was too late in the call boundary.

The benchmark executable can sometimes return a fail-closed JSON result for the same fixture, which makes undefined behavior, stale candidate state, or nondeterministic topology traversal more likely than a deterministic input-only failure.

## Random-bunny processes

All processes used:

- case `bunny_1k_random_medium`;
- generated `face_edges` degree-four field;
- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- zero warmups and one measured run;
- arbitrary extraction and working directories.

| Run | Role | Observation | Result |
|---|---|---:|---|
| 1 | Formal | `>300 s` | Did not terminate; no JSON |
| 2 | Formal | `40.925049 s` | Failed closed |
| 3 | Supplementary | `>120 s` | Did not terminate; no JSON |
| 4 | Supplementary | `>120 s` | Did not terminate; no JSON |

The four-process determinism and liveness gate fails decisively. Three processes exceeded their observation windows by large margins; only one completed.

### Completed process

The completed process reports:

```text
SuccessfulSubdivisionDomainIdentity;
identityFailure=mixed-source-sheet;
cell=19;
halfedge=52893;
node=-1;
sourceFace=794;
component=0;
sheet=9
```

Common state:

- terminal code/stage: `NotProductionReady` / `completion`;
- trace segments: `12,130`;
- arrangement/simplified cells: `7,405 / 7,405`;
- odd cells before/after parity repair: `1,860 / 0`;
- parity split edges: `2,213`;
- side infeasible cells before/after: `918 / 0`;
- side inserted vertices: `8,074`;
- patch descriptors/completed patches: `0 / 0`;
- exact reused/recomputed completions: `0 / 0`;
- product-cache hash misses/exact mismatches: `0 / 0`, because descriptor acceptance is never reached;
- fallback/recovery: neither used;
- output origin: `None`.

The typed audit is functioning, but the producer correction is incomplete. A committed subdivision creates or exposes mixed source-sheet ownership on cell `19` and halfedge `52893`.

### Resource result for the completed process

- wall: **40.925049 s**;
- wall gate: `<= 39.228299 s` — failed by **1.696750 s**;
- peak working set: **184,205,312 B**;
- memory cap: `1,115,394,560 B` — passed with **931,189,248 B** margin;
- versus P5-TB13 failed-path maximum `185,614,336 B`: **1,409,024 B lower** (`-0.76%`);
- versus P5-TB12 early-failure maximum `158,949,376 B`: **25,255,936 B higher** (`+15.89%`);
- versus P5-TB11 maximum `936,484,864 B`: **752,279,552 B lower** (`-80.33%`).

Stage timings:

- tracing: **7.038130 s**;
- arrangement: **1.324948 s**;
- simplification: **30.632781 s**;
- completion: **0.680215 s**.

Simplification still dominates the completed process. The nonterminating processes began after default fixed-point refresh was restored, so deterministic queue convergence and stale-candidate invalidation are now production blockers.

Tracked completion ownership includes about **21.60 MB** current structural state and **21.59 MB** rollback state. The next turn must verify that rollback storage is a compact undo representation rather than a second full complex.

## Root-cause findings for the next code turn

### 1. Successful subdivision mixes source sheets

The audit correctly identifies `mixed-source-sheet`, but the producer still combines source occurrences or source support across local sheets. Inserted nodes may retain multiple valid occurrences, while each oriented replacement halfedge and owning cell must select and preserve the exact incident sheet. Do not resolve this by dropping sheet identity, choosing geometry-nearest charts, or weakening the audit.

### 2. Simplification fixed-point refresh is not live or deterministic

Local Phase 17 behavior passes, but production runs range from about 41 seconds to nontermination beyond 300 seconds. The candidate frontier needs deterministic generations, dependency-scoped invalidation, duplicate suppression, and a proof of monotone convergence. A hard iteration timeout is not a correctness fix.

### 3. The crash occurs inside the pipeline

All bunny test markers stop before pipeline return. Add stage-boundary and transaction-boundary ownership markers around simplification candidate extraction/commit, successful side subdivision, descriptor derivation, and completion cleanup. Audit invalid references and moved storage inside the pipeline rather than only `RemeshResult` lifetime.

### 4. Rollback proof is false

The real side-repair regression reports rollback equivalence while the structural hash differs. Every mutated node, halfedge, cell field, source occurrence, provenance vector, support set, and diagnostic state must be restored before claiming equivalence.

### 5. Semantic reuse indexing is present but never reached successfully

The two targeted completion tests still report zero reuse. Instrument candidate product count, semantic hash buckets, exact mismatch fields, consumption state, and affected/unaffected classification. Ensure mutable allocation IDs and rebuilt local ordering are excluded from exact dependency identity.

### 6. Rail propagation remains incomplete

Embedded arcs carry rail identity, but final arrangement halfedges do not. Audit every arc split, stitch, halfedge creation, orientation reversal, and compaction path. Preserve the complete provenance vector and a deterministic primary interval.

### 7. Test fixtures remain invalid

The three Milestone D fixtures still fail before their intended production scenarios. Rebuild them from explicitly validated DCEL primitives and assert twin symmetry, incidence, interface length, Euler characteristic, component count, boundary-loop count, and removable-strand preconditions before invoking simplification.

## Gate summary

| Gate | Result |
|---|---|
| Exact artifact/source/status/checksums | Pass |
| Executable-relative fixture closure | Pass |
| Successful-subdivision typed audit | Pass |
| Successful-subdivision producer validity | Fail — mixed source sheet |
| Real side-repair exact rollback | Fail |
| Positive exact reuse | Fail |
| Phase 14–18 | Pass |
| P23 + Phase 20 | Fail |
| Milestone D | Fail — fixtures still invalid |
| Full packaged binary | Fail — 3 SIGSEGV tests |
| Four-process liveness/determinism | Fail — 3 nonterminating processes |
| Nonempty pure-quad output | Fail |
| Zero ownership conflicts | Not reached |
| No fallback/recovery | Pass |
| Wall cap | Fail on completed process; other processes nonterminating |
| Memory cap | Pass only on one early-failure process |

## Next authority

Proceed with `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Plan.md` in a code changes + compile-only build turn. Execute no tests, benchmarks, custom meshes, compiled binaries, help/list commands, or test discovery in that turn.
