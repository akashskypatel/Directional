# Milestone G P5 — TB15 Parity-Scope, Reuse, Rail, and Liveness Test + Benchmark Report

**Turn:** P5-TB15 artifact-only test and benchmark  
**Artifact:** `8866222973` (`surface-cell-p5-cb82-mixed-sheet-liveness-linux-release`)  
**Exact source:** `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`  
**Digest:** `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`  
**Review policy:** `never`  
**Rebuild performed:** no

## Disposition

P5-TB15 does **not** close P5.

The compile checkpoint materially improves rollback correctness, Milestone D interface fixtures, face-edge random-bunny liveness, wall time, and memory. It does not yet produce valid production output, exact reusable-product hits, final rail identity, a valid cylinder simplification fixture, or a safe generated-smooth-field production path.

PR #8 remains open, draft, and unmerged.

## Artifact integrity

The artifact was extracted to an arbitrary path and executed directly.

- `source-commit.txt`: `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.
- Source status: empty.
- Artifact ZIP digest: exact match.
- Packaged checksums: **36/36 passed** after normalizing the archive-time `artifact/` prefix.
- x86-64 ELF test and benchmark executables: present.
- Static core and pipeline libraries: present.
- Configure/build logs, source archive, and recursive submodule status: present.
- Packaged fixture files: **26**.
- Packaged random bunny: **502 vertices / 1,000 triangle faces**.

## Test results

### Focused P5-TB14 failure set

The 13 previously assertion-failing tests now pass **3/13** and fail **10/13**.

Newly passing:

- `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion`;
- `MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed`;
- `MilestoneDClosure.CompleteInterfaceCommitsAndPreservesProtectedRails`.

Still failing:

1. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` — exact reused completions remain zero.
2. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse` — exact reused completions remain zero.
3. `PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex` — fixture still reaches `MissingCommonSourceChart`, not `InvalidMidpointEmbedding`.
4. `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` — no final arrangement halfedge has authoritative rail identity.
5. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` — fixture complex is topology-invalid before simplification.
6. `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput` — `NotProductionReady/validation`.
7. `MilestoneGP26.PlaneAndMechanicalFixturesCompleteEndToEnd`.
8. `MilestoneGP26.CylinderCompletesEndToEnd`.
9. `MilestoneGP26.MultiFaceSeamCompletesEndToEnd`.
10. `MilestoneGP26.TorusCompletesEndToEnd`.

The additional successful-subdivision and simplification subset passes **3/3**.

### Authoritative suites

| Scope | Passed | Failed |
|---|---:|---:|
| Phase 14–18 aggregate | **230** | **0** |
| `PatchDescriptorMilestoneE.*` | 21 | 3 |
| Milestone G P23 + Phase 20 | 52 | 2 |
| Milestone D closure | 6 | 1 |
| Full binary excluding three crash tests | 579 | 10 |

The packaged binary contains **592 tests**. Complete disposition:

- **579/592 passed**;
- **10 assertion failures**;
- **3 signal-11 tests**.

The same three production-matrix tests still exit `139` before the pipeline returns:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`;
- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`;
- `ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/7`.

## Face-edge random-bunny processes

Four fresh independent processes used:

- case `bunny_1k_random_medium`;
- generated `face_edges` degree-four field;
- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled;
- zero warmups and one measured run;
- arbitrary extraction and working directories.

| Run | Role | Wall | Peak working set | Result |
|---|---|---:|---:|---|
| 1 | Formal | `19.939944 s` | `137,048,064 B` | deterministic fail-closed |
| 2 | Formal | `17.594136 s` | `137,109,504 B` | deterministic fail-closed |
| 3 | Supplementary | `19.356339 s` | `137,162,752 B` | deterministic fail-closed |
| 4 | Supplementary | `19.420800 s` | `137,039,872 B` | deterministic fail-closed |

All four processes terminate. All non-timing diagnostics and every stage structural hash are identical.

Common state:

```text
NotProductionReady/completion
completionFailure=BoundaryParityRepair:MixedCellSourceScope
```

- trace segments: `12,130`;
- arrangement/simplified cells: `7,405 / 7,405`;
- odd cells before/after parity repair: `1,860 / 0`;
- descriptors/completed patches/completed quads: `0 / 0 / 0`;
- exact reused/recomputed completions: `0 / 0`;
- output origin: `None`;
- fallback/recovery: neither used.

The parity repair reaches zero odd-cell count only inside the rejected transaction. It cannot commit because at least one rebuilt cell boundary has no single exact component/sheet scope shared by every oriented replacement halfedge.

### Simplification convergence

All four runs report:

- generated candidates: `3,725`;
- invalidated candidates: `2,978`;
- deduplicated candidates: `0`;
- stale-generation candidates: `0`;
- frontier generations: `5`;
- peak live candidates: `747`;
- evaluated candidates: `762`;
- committed/rejected transactions: `4 / 758`.

The generation-bounded frontier is deterministic and terminates on this path.

### Resource gates

- maximum wall: **19.939944 s** versus `39.228299 s` limit — pass;
- maximum peak working set: **137,162,752 B** versus `1,115,394,560 B` limit — pass;
- maximum simplification time: **9.721273 s**.

Versus the completed P5-TB14 process:

- maximum wall: **51.28% lower**;
- maximum peak working set: **25.54% lower**;
- maximum simplification time: **68.27% lower**.

Completion-owned telemetry reports only `2,200 B` current structural state, including `1,640 B` descriptor storage, `360 B` assembly storage, and `200 B` rollback storage. Side-repair undo storage is zero because failure occurs during boundary parity repair. These fields do not explain the approximately 137 MB process RSS; trace, FlowRep, arrangement, and simplification container ownership still needs explicit stage-level accounting.

## Generated-smooth-field signal-11 isolation

The production manifest's bunny case differs from the portable regression case:

- it uses the default generated `smooth` field rather than `face_edges`;
- it retains debug artifacts.

Isolation results:

- exact `bunny_1k_random__surface_cells`: exit `139`, no JSON, `8.71 s`, approximately `40,804 KiB` RSS;
- generated `smooth` with debug retention disabled: exit `139`;
- generated `face_edges` with debug retention enabled: returns normally;
- generated `smooth`, injected failure after tracing stage 3: returns normally with `80,862` trace segments and trace hash `f2fe5aaec178f507`;
- generated `smooth`, injected failure after strands stage 4: exit `139`.

Therefore the crash is not caused by debug-result retention. It is isolated to the **strands stage** after a deterministic high-cardinality `80,862`-segment smooth-field trace network and before the stage-4 marker. The likely fault domain is FlowRep selection/input construction or endpoint completion under high-cardinality graph state.

## Root-cause findings

### 1. Boundary parity repair still selects scope by frequency

The parity subdivision rebuild currently chooses a dominant `(component, sheet)` pair from boundary provenance, then rejects if an edge cannot supply that scope. This is not an authoritative source-sheet construction. The required scope must be derived from the pre-transaction cell and carried through every replacement piece. A mixed input cell must be partitioned earlier or rejected with a typed producer failure before parity mutation.

### 2. Smooth-field crash is inside FlowRep strands

Stage injection proves tracing completes and strands does not. The next code turn must instrument and audit:

- `build_flow_rep_selection_input`;
- `select_sparse_flow_rep_network`;
- open-endpoint completion;
- vector/map references across insertions and moves;
- recursion or stack depth on the 80,862-segment graph;
- ownership when `retainIntermediateGeometry` is enabled or disabled.

### 3. Exact completion reuse remains semantically over-keyed

The reusable-product key still includes bit-exact derived positions, squared distances, ordered source-face lists, and other regenerated representation details. Unaffected patches can therefore miss even when their authoritative source-domain, side subdivision, rail/curve support, singularity requirements, and boundary source coordinates are unchanged. Add field-level mismatch diagnostics and key only authoritative completion dependencies.

### 4. Rail propagation is still incomplete

Authoritative rail identity exists upstream but final arrangement halfedges still contain no rail ID in the focused production test. The complete provenance vector must survive every split, stitch, orientation reversal, and post-cell rebind. Do not infer rails from geometry.

### 5. Two remaining tests are invalid before their intended scenarios

- `FailedSubdivisionReturnsBitExactCommittedComplex` intentionally removes common chart support, so `MissingCommonSourceChart` is correct. To test `InvalidMidpointEmbedding`, both endpoints must declare one compatible common chart with malformed barycentric data.
- The cylinder fixture duplicates coincident source-edge arcs in every incident triangle chart and is topology-invalid before simplification. Rebuild it from nonoverlapping cross-face segments or a canonical source-edge representation with complete incident provenance.

### 6. Production output validation remains open

Plane, cylinder, and multi-face seam reach validation with substantial sheet, geometry, orientation, and manifold violations. Torus and mechanical-feature fail earlier in completion. These are production implementation failures, not reasons to weaken validation.

## Gate summary

| Gate | Result |
|---|---|
| Exact artifact/source/status/checksums | Pass |
| Phase 14–18 | Pass |
| Real side-repair exact rollback | Pass |
| Milestone D multi-edge interface fixtures | Pass |
| Face-edge random-bunny liveness | Pass |
| Face-edge structural determinism | Pass |
| Face-edge wall and memory caps | Pass |
| Boundary parity exact source scope | Fail |
| Positive exact completion reuse | Fail |
| Final authoritative rail identity | Fail |
| Cylinder simplification fixture validity | Fail |
| Generated-smooth-field strands safety | Fail — signal 11 |
| Full packaged binary | Fail |
| Nonempty pure-quad production output | Fail |
| Successful-path memory | Not measured |

## Next authority

Proceed with `.agents/Directional/Milestone_G_P5_Parity_Scope_FlowRep_Reuse_Rail_Code_Build_Plan.md` in a code changes + compile-only build turn. Execute no tests, benchmarks, custom meshes, compiled binaries, help/list commands, or discovery commands in that turn.
