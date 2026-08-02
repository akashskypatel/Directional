# Surface-Cell Backend Remediation Plan

**Revision:** 2026-07-25
**Historical baseline snapshot:** `Directional_snapshot.zip`
**Historical baseline SHA-256:** `d6ccf97add8749f4896d878a4e4255fc5496d96bc1dd9aa268b4ce0b2a5db29f`
**Milestone A closure snapshot:** `Milestone_A_r4_snapshot.zip`
**Disposition:** `SurfaceCells` remains experimental and default-off until every production gate in this document passes.
**Supersedes:** the current-state verdict and checked completion claims in `Surface_Cell_Backend_Correction_Plan.md`. It does not supersede the research rationale in `NOTES.md` or the accepted Phase 00-09 results.

## 1. Remediation objective

Produce a genuine end-to-end `SurfaceCells` backend in which:

1. the complete cross-field result, feature rails, adaptive metric, relief topology, trace network, sparse embedded network, surface arrangement, simplified complex, completed patches, optimized mesh, and validation report form one typed dataflow;
2. every live stage consumes the authoritative output of the preceding stage;
3. output topology is constructed by the surface-cell path rather than by pairing source triangles or returning the input mesh;
4. failure and fallback behavior is explicit and accurately reported; and
5. supported inputs produce deterministic, manifold, conforming, pure-quad meshes that preserve topology, boundaries, source sheets, and hard features.

A cross field provides orientation but does not by itself provide globally compatible grid phase or connectivity. This plan therefore preserves explicit topology reconciliation, singularity handling, patch feasibility, parity repair, and global validation. It does not introduce a global MIQ-style integer parameterization.

## 2. Baseline history and current state

### 2.1 Historical pre-Milestone-A baseline

Before Milestone A remediation, the live path had several truthfulness defects:

- complete cross-field metadata was validated but not preserved through construction;
- hard feature and boundary rails were not propagated through all downstream stages;
- FlowRep sparse selection lacked authoritative coverage/cycle evidence;
- simplification was called with an empty candidate list;
- completion handled only a narrow simple four-sided case;
- source-triangle pairing could be reported as successful `SurfaceCells` output;
- several diagnostics did not identify the actual stage objects or output origin.

The archived planar benchmark from that baseline demonstrated source-triangle pairing rather than newly constructed surface-cell topology.

### 2.2 Milestone A closure state

Milestone A corrected the observable execution contract:

- source-triangle pairing was removed from the successful `SurfaceCells` path;
- success is reported only as `CompletedSurfaceCells` after completion, optimization, and accepted validation;
- input-mesh and legacy fallbacks report explicit fallback origins and set `surfaceCellRemeshOccurred=false`;
- canonical structural identities and explicit consumption kinds describe the live stage flow;
- sparse FlowRep output is materialized through an explicit `embedding` stage before arrangement;
- arrangement consumes the exact retained embedded-network identity;
- failure lineage terminates at the actual failed stage;
- focused and full local test suites passed as recorded in `.agents/Milestone_A.md`.

Milestone A does not close the remaining algorithmic work. The backend remains experimental and default-off. Milestone B remediation is now implemented for authoritative edge-transition indexing, real local-sheet classification and enforcement, authoritative compatible rail traversal, and fail-closed raw-field finalization. Full production topology, completion, optimization, and strict final validator enforcement remain assigned to later milestones.

## 3. Non-negotiable acceptance rules

### 3.1 Genuine SurfaceCells success

A run may report `executedBackend == SurfaceCells` and `surfaceCellRemeshOccurred == true` only when all of the following hold:

- [ ] Output faces were emitted from completed `SurfaceCellComplex` patches or from an explicitly diagnosed, fail-closed source-cell recovery that constructs new vertices and quad edges rather than returning source-triangle-pair boundaries.
- [ ] Every output vertex and edge has stage lineage and source-surface provenance.
- [ ] No input-mesh, source-triangle-pair-boundary, legacy, or quad-dominant fallback supplied the result.
- [ ] All required stage outputs were available and consumed.
- [ ] Strict final validation passed.
- [ ] On the nontrivial proof fixture, output contains newly constructed surface vertices or edges and cannot be represented solely as boundaries of paired source triangles.

### 3.2 Evidence rule

A goal is complete only when its change contains all applicable evidence:

- implementation;
- focused tests that fail before the change and pass afterward;
- integration test proving the live backend consumes the result;
- benchmark or scalability evidence where required;
- debug artifact or qualitative review where required; and
- updated phase/status records with exact evidence paths.

A similarly named type, test, stage call, timer, or count is not completion evidence.

### 3.3 Benchmark protocol

For every quantitative gate:

- Release build only.
- One warm-up plus at least five measured runs.
- Report median, minimum, maximum, mean, standard deviation, and coefficient of variation.
- Require CV <= 10%, or record the gate as unstable/failed.
- Archive raw JSON, command line, snapshot/commit identity, compiler, build mode, CPU, OS, timestamp, options, fixture hash, and output structural hash.
- Preserve failed outcomes; do not tune thresholds after seeing results without recording a new experiment ID.

**Important**: Use `data\bunny1k.obj` for every medium-scale end-to-end, performance, memory, and qualitative production benchmark. Focused unit and regression tests may use minimal analytic fixtures when they isolate a specific invariant or failure mode. Such fixtures must not be used as substitutes for the required bunny1k production benchmark. Do not fallback to a simpler mesh for medium-scale production benchmarks simply because bunny1k benchmarks or tests are failing; increase timeout if needed and record the bunny1k baseline in the benchmark manifest.

## 4. Execution order

```text
R0 Records and truthfulness
  -> R1 Typed pipeline context and full cross-field contract
  -> R2 Authoritative feature/boundary rails
  -> R3 Matching-aware tracing and closed cells
  -> R4 Embedded FlowRep network
  -> R5 Global surface arrangement
  -> R6 Real complex simplification
  -> R7 General pure-quad patch completion
  -> R8 Optimizer and authoritative validator
  -> R9 End-to-end pipeline and fallback semantics
  -> R10 Benchmark matrix and production decision
```

Do not begin a downstream work package until the preceding package's exit gate passes. Keep `LegacyInteger` callable and unchanged except for shared bug fixes covered by tests.

# 5. Concrete pursuable-goal checklist

This is the assignable execution backlog. Items start unchecked when introduced;
completed remediation items are checked with evidence, and explicitly deferred
items remain assigned to later milestones.

## Milestone A — Establish a truthful failing baseline

- [x] **P0. Reconcile project records with the current snapshot.**
  - Update `.agents/Phase_10.md` through `.agents/Phase_20.md` with separate fields for API, prototype tests, live integration, quantitative gate, qualitative gate, disposition, and evidence.
  - Replace stale statements that Phases 13-19 are not called.
  - Mark called-but-ineffective paths explicitly.
  - Reopen any checked goal whose completion evidence depended on source-triangle pairing, empty candidate lists, fabricated semantics, or smoke-only benchmarks.

- [x] **P1. Add stage-lineage diagnostics.**
  - Record for every stage: input object ID/hash, output object ID/hash, object count, availability, consumed-by-next-stage flag, duration, and terminal failure.
  - Add typed output-origin and consumption enums.
  - Use canonical structural hashes over feature, relief, trace, sparse-network, explicit retained embedded arrangement arcs, arrangement, and completion/provenance content instead of count summaries.
  - Mark consumption explicitly from consumer-side pipeline transitions.
  - Fail tests when `SurfaceCells` success has any origin other than `CompletedSurfaceCells`.
  - Cover same-count structural mutations, canonical ordering, failure lineage, embedding materialization continuity, validation-rejection origin safety, and actual multi-component aggregation in focused tests.

- [x] **P2. Disable false SurfaceCells success.**
  - Remove `build_quads_from_paired_source_triangles()` from the successful SurfaceCells path.
  - Retain it only behind an explicitly named fallback policy if it remains useful.
  - Such a fallback must set `surfaceCellRemeshOccurred=false` and must not satisfy any SurfaceCells gate.

**Milestone A exit gate**

- [x] Existing planar smoke output either fails honestly at the correct stage or succeeds through completed surface cells; it cannot silently succeed through source-triangle pairing.
- [x] Phase records and diagnostics agree with the observed execution path.


**Milestone A evidence (2026-07-25):**

- `include/directional/diagnostics/RemeshDiagnostics.h` adds typed `SurfaceCellOutputOrigin`, `SurfaceCellObjectIdentity`, `surfaceCellOutputOrigin`, and `surfaceCellStageLineage`.
- `include/directional/pipeline/RemeshPipeline.h` records structural stage identities and explicit consumption kind, reports typed `CompletedSurfaceCells`, `LegacyFallback`, `InputMeshFallback`, `Mixed`, or `None` origins, sets fallback `surfaceCellRemeshOccurred=false`, and removes `build_quads_from_paired_source_triangles()` entirely.
- `src/bench/DirectionalBenchmark.cpp` serializes output origin and stage-lineage diagnostics.
- `tests/SurfaceCellPipelinePhase20Tests.cpp` asserts completed-cell successes report `CompletedSurfaceCells`, completion failures report origin `None`, fallbacks do not satisfy SurfaceCells remesh success, lineage hashes are continuous, no-op simplification is labeled, failure lineage stops at the failed stage, and mixed component origins aggregate to `Mixed`.
- `tests/DiagnosticsTests.cpp` pins the new diagnostics JSON fields.
- Verification: `build\codex-verify\directional_phase1_tests.exe --gtest_filter=SurfaceCellPipelinePhase20.*:Diagnostics* --gtest_brief=1` passed 32 tests; `build\codex-verify\directional_phase1_tests.exe --gtest_brief=1` passed 282 tests; `.agents\validate_phase_records.ps1` passed; `git diff --check -- include src tests .agents` passed.
## Milestone B — Preserve authoritative inputs through tracing (implementation complete; local verification pending)

**Goal:** carry authoritative cross-field, rail, relief, component, and
local-sheet data into every supported tracing execution path and preserve
truthful structural identities.

### Supported execution matrix

Sequential SurfaceCells with a finalized `CrossFieldResult` is supported.

Parallel SurfaceCells is explicitly unsupported and must fail before execution.
Full component remapping and aggregate typed context are future functionality.

### Completed implementation

- [x] **P3. Sequential execution returns typed `SurfaceCellPipelineContext`.**
- [x] **P3. Unsupported parallel execution does not claim context or lineage.**
- [x] **P4. Matching and effort are keyed by canonical source-edge identity.**
- [x] **P4. Missing, duplicate, malformed, and nonfinite field metadata fails closed.**
- [x] **P5. Boundary and hard-feature rails are explicit ordered inputs.**
- [x] **P5. Rail entry is incident-face independent.**
- [x] **P5. Canonical rail-side identity is preserved through continuation.**
- [x] **P5. Component/local-sheet labels constrain edge transitions, vertex continuation, and proposals.**
- [x] **P5. Endpoint, missing interval, side discontinuity, and source-sheet blocking are distinct.**
- [x] **P5. Rail validation proves geometric, source-vertex, and global-parameter continuity.**
- [x] **P5. Duplicate source edges across rails fail closed.**
- [x] **P5. Mixed feature curves split into contiguous same-kind rail runs.**
- [x] **P5. Invalid production rail construction returns no partial rail set.**
- [x] **P5. Closed rails use canonical cyclic source-vertex loops without synthetic self-edges.**
- [x] **P6. Relief roots, regions, and barriers affect tracing.**
- [x] **Lineage. Trace hashes include rail semantics, rejection semantics, and nested container boundaries.**

### Review-environment verification

- [x] `SurfaceCellTracingPhase14.*`: 34 passed.
- [x] `MilestoneBClosure.*`: 4 passed.
- [x] Modified production headers compiled in focused targets.

### Local closeout gate

Run `.agents/RUN_MILESTONE_B_VERIFICATION.md`.

- [x] Clean configure and build succeeds.
- [x] Focused Milestone B filter passes.
- [x] Affected suites pass.
- [x] Full `directional_phase1_tests` passes.
- [x] Relocated phase-record validation passes.
- [x] `git diff --check -- CMakeLists.txt include src tests .agents` passes.

### Deferred production hardening — not a Milestone B gate

- [ ] Finalize classifier semantics for sharp bends.
- [ ] Expose classifier thresholds through `SurfaceCellOptions`.
- [ ] Add broad curved, scale, and nonmanifold classifier coverage.
- [ ] Replace all-face conflict scanning with a spatial index.
- [ ] Define inconsistent-normal behavior.

### Closeout disposition

The Milestone B code implementation is complete for supported modes. Mark the
milestone formally closed and begin Milestone C when every local closeout
command passes. Do not reopen deferred classifier-hardening work unless it
causes a concrete closeout failure.

## Milestone C — Construct a valid embedded network

- [x] **P7. Implement branch-consistent intrinsic trace state.**
  - Track `(sourceFace, entryEdge, family, sign, quantizedBarycentric)`.
  - Apply principal matching at every source-edge crossing.
  - Resolve vertex continuation using transported turn angle, matching effort, then stable face ID.
  - Use intrinsic same-sheet distance for capture and farthest sampling.
  - Implementation evidence:
    - `SurfaceTraceState` records the current source face, destination-local entry edge, matched branch family/sign, and 64-bit quantized barycentric coordinates.
    - Edge and source-vertex crossings use the same principal-matching transition routine; a vertex path applies every crossed transition before ranking continuations.
    - Vertex continuations are ranked by transported turn angle, accumulated matching effort, stable face ID, and finally stable path order.
    - Capture and deterministic farthest sampling use a barrier-aware face-corner intrinsic graph. This is a deterministic edge-graph geodesic approximation, not an exact continuous geodesic solver.
    - Focused regression coverage is in `tests/SurfaceCellTracingPhase14Tests.cpp`.
    - Review-environment verification: `SurfaceCellTracingPhase14.*` passed 40/40, including AddressSanitizer/UndefinedBehaviorSanitizer execution, and `SurfaceCellPipelinePhase20.*` passed 42/42; the Phase 14 test translation unit also compiled with GCC 14.2 in Release mode.
  - Disposition: code-complete and focused-test verified. Milestone C remains open because P8-P10 and the milestone-level gates are not complete.

- [x] **P8. Replace half-trace proposals with closed cell boundaries.**
  - Construct four corners and four ordered boundary arcs.
  - Reject non-closing, self-intersecting, inverted, duplicate-corner, out-of-size, or hard-rail-crossing proposals before FlowRep.
  - Emit explicit rejection reasons and counts.
  - Implementation evidence:
    - `SurfaceCellProposal` now carries four ordered `boundaryPaths`; accepted paths are endpoint-canonicalized when the final segment and destination corner share a source face.
    - Cell-loop validation reports distinct `Closure`, `SelfIntersection`, `Inverted`, `DuplicateCorner`, `OutOfSize`, `Barrier`, and `HardRailCrossing` rejection reasons rather than collapsing structural failures into `Degenerate`.
    - `SurfaceCellProposalStats` records a separate count for every P8 rejection category, and the accounting test proves every proposal attempt is represented exactly once.
    - Authoritative-rail intersection is tested in source-triangle barycentric coordinates and allows a path to follow the same rail while rejecting a proper crossing of a different rail. Rail samples are consumed as explicit endpoint pairs, so disjoint intervals are never joined by a fabricated crossing segment.
    - Accepted proposals undergo a final authoritative boundary audit: all four paths must be nonempty, ordered, endpoint-closed, segment-contiguous, and free of proper crossings, T-intersections, or positive-length overlaps in every source-triangle chart.
    - `build_flow_rep_arcs_from_network()` no longer exports diagnostic half traces or rejected proposals. FlowRep receives authoritative rails and accepted closed proposal boundaries only.
    - Focused regression coverage is in `tests/SurfaceCellTracingPhase14Tests.cpp` and `tests/FlowRepStrandsPhase15Tests.cpp`.
    - Review-environment verification: the modified Phase 14 and Phase 15 test translation units compiled with GCC 14.2; `SurfaceCellTracingPhase14.*` plus `FlowRepStrandsPhase15.*` passed 61/61 in a focused executable. A targeted Phase 20 translation-unit compile exceeded the review time window, so no Phase 20 compile result is claimed.
  - Disposition: code-complete and focused-test verified. Milestone C remains open because P9-P10 and the milestone-level gates are not complete.

- [x] **P9. Make FlowRep selection fail closed without evidence.**
  - Reject sparse selection when coverage samples or cycle/patch evidence are required but absent.
  - Build intrinsic coverage samples normalized by local target size.
  - Build and rebuild affected cycles after every removal or substitution.
  - Preserve mandatory rails and complete embedded provenance.
  - Implementation evidence:
    - `FlowRepSelectionInput` now carries typed embedded arcs, intrinsic coverage samples, and proposal-cycle evidence. Selection requires coverage, cycle, and complete-provenance evidence by default.
    - Evidence-free, malformed, incomplete, or identity-invalid inputs return a precise `FlowRepSelectionFailureCode` while retaining the initially active dense network for diagnostics; the live pipeline maps each failure to a precise `SurfaceCellFailureCode` and stops at `strands`.
    - Coverage samples are generated deterministically along each source-triangle arc at a density derived from local target size. Coverage distance is accepted only within the same source face, component, and local sheet, and is normalized by each sample's interpolated local `h`.
    - Accepted closed P8 proposals produce ordered four-side cycle records; the selector also validates explicit 3-6-side cycle inputs. Source-triangle splits remain segments of one logical proposal side, and proposal segments that follow mandatory rails remain part of their cycle evidence.
    - Every attempted removal or substitution rebuilds only its affected cycles before commit. Transactions must preserve finite normalized coverage, complete cycle boundaries, descriptive/patch feasibility, and every mandatory rail.
    - Arc, proposal, rail, component, sheet, barycentric, cycle, and evidence metadata are included in stage structural hashes and preserved into retained arrangement-arc inputs.
    - Focused regressions are in `tests/FlowRepStrandsPhase15Tests.cpp`; pipeline failure mapping and live evidence assertions are in `tests/SurfaceCellPipelinePhase20Tests.cpp`.
    - Review-environment verification: the Phase 15 focused executable passed 24/24 tests with Clang 17; the Phase 15 translation unit also passed GCC 14.2 syntax checking. The Phase 20 translation unit passed Clang 17 syntax checking with five pre-existing missing-`override` warnings. No full suite or benchmark was run.
  - Disposition: code-complete and focused-test verified. Milestone C remains open because P10 and the milestone-level geometry/benchmark gates are not complete.

- [x] **P10. Simplify whole embedded strands transactionally.**
  - Extract maximal nonbranching logical flowlines from embedded arcs, joining compatible segments across source-face boundaries while preserving component and local-sheet identity.
  - Split flowlines at global network junctions and logical-strand branch points before simplification.
  - Remove or substitute every arc in a flowline as one transaction; partial multi-segment edits are not committed.
  - Continue evaluating crossing and boundary predicates in source-triangle barycentric coordinates.
  - Roll back transactions that violate intrinsic coverage, cycle descriptiveness/quadrangulability, disk/turn/side-count evidence, mandatory feature rails, or protected endpoint/junction degrees.
  - Record attempted, rejected, retained, and removed flowline counts in `FlowRepSparseNetwork` and include them in the pipeline structural hash.
  - Focused regressions cover multi-arc rollback, all-segment substitution, cross-face continuation, junction splitting, and deterministic hashes in `tests/FlowRepStrandsPhase15Tests.cpp`.
  - Final sparse-network diagnostics now count flowlines extracted from the committed retained arc set, so transactionally activated substitutes are included in `retainedFlowlines`; `removedFlowlines` remains an explicit count of original dense flowlines removed or replaced.
  - Review-environment verification: `FlowRepStrandsPhase15.*` passed 27/27 with Clang 17, including explicit retained/removed flowline accounting after multi-segment substitution. CMake configure succeeded. The monolithic header-heavy test target still requires local closeout.
  - Disposition: code-complete and focused-test verified. Formal Milestone C closure is contingent on `.agents/closeout-milestone-c.ps1` passing locally.

**Milestone C tests**

- [x] Cylinder traces reconcile around the periodic seam.
  - Evidence: `MilestoneCClosure.CylinderPeriodicTraceProducesClosedEmbeddedFlowline` traces through the periodic source seam, isolates the repeated-state loop, and proves it extracts as one closed embedded logical flowline.
- [x] Torus traces collide and merge without cross-sheet capture.
  - Evidence: `MilestoneCClosure.TorusTraceCapturesCompatibleNodeAndIgnoresCloseOtherSheet` places a geometrically close capture candidate on another local sheet before the valid target and proves the trace captures the same-sheet target.
  - Supporting regression: `SurfaceCellTracingPhase14.IntrinsicCaptureDoesNotJumpToEuclideanCloseOppositeSheet`.
- [x] Feature-compatible traces follow rails; incompatible traces stop or redirect deterministically.
  - Evidence: `SurfaceCellTracingPhase14.CompatibleHardFeatureRailIsFollowed`, `CompatibleHardFeatureRailTerminatesWhenFollowDisabled`, and the hard-feature barrier/rail identity regressions.
- [x] Empty FlowRep evidence produces a precise failure instead of deleting the network.
- [x] Accepted FlowRep edits rebuild cycles and preserve structural validity.
- [x] Sequential and repeated runs produce identical network hashes.

**Milestone C benchmark**

- [x] Measure tracing and FlowRep scaling on increasing planar grids and one medium curved fixture.
  - Evidence generator: `directional_milestone_c_benchmark` measures planar grids 4, 8, and 12 plus a 64x8 cylinder.
- [x] Record accepted/rejected cells, retained/removed strands, intrinsic coverage error, cycle rebuild count, and peak memory.
  - The benchmark emits all algorithmic counters as JSON.
  - `.agents/closeout-milestone-c.ps1` performs one warm-up and five measured Release runs, samples process peak working set, and writes `.agents/milestone_c_closeout/raw_results.json` plus `summary.md`.

**Milestone C exit gate**

- [x] A cylinder produces a nonempty closed embedded network whose periodic seam is not visible as a topology break.
  - Evidence: `MilestoneCClosure.CylinderPeriodicTraceProducesClosedEmbeddedFlowline`.
- [x] FlowRep retains enough cycles to define downstream cells.
  - Evidence: `MilestoneCClosure.FlowRepRetainsClosedCycleForDownstreamCells` requires coverage and cycle evidence, retains the complete four-sided cycle, and verifies descriptive/quadrangulable evaluation.

### Milestone C closeout disposition

The implementation and focused geometry/FlowRep gates are complete in this
snapshot. The milestone is **ready for formal local closeout**, not yet claimed
closed by this review environment, because the monolithic Phase 20 handoff and
full suite were not completed here. Run:

```powershell
powershell -ExecutionPolicy Bypass -File .\.agents\closeout-milestone-c.ps1
```

Formal closure requires that script to finish successfully and preserve its
generated `.agents/milestone_c_closeout` evidence.

## Milestone D — Build and simplify a global surface-cell complex

- [x] **P11. Canonically stitch the arrangement across source triangles.**
  - Use global source-vertex keys, orientation-corrected source-edge keys, and robust face-interior keys.
  - Merge both adjacent-face representations of shared source edges.
  - Insert only actual boundaries and classified hard features as hard rails.
  - Preserve all coincident arc, strand, feature, and source provenance.
  - Evidence: `SurfaceArrangementPhase16.SharedSourceEdgeUsesOrientationCorrectedCanonicalParameters`, `CoincidentSharedEdgeSegmentsMergeAndPreserveAllProvenance`, `SharedSourceVertexUsesOneGlobalNodeWithAllFaceOccurrences`, and `FaceInteriorKeysSanitizeSubToleranceBarycentricNoise`.
  - Implementation: canonical global source-vertex identities, orientation-corrected canonical source-edge parameters, sanitized face-interior keys, multi-face node occurrences, per-halfedge contributor provenance, embedded-position merge verification, and 3D tangent-frame halfedge ordering.
  - Corrected closeout evidence: `MilestoneDClosure.CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces` and the complete Phase 16 focused suite.

- [x] **P12. Make arrangement topology and measurements authoritative.**
  - Detect disk/non-disk cells rather than defaulting to disk.
  - Compute unique transverse hard-barrier crossings without counting collinear overlap.
  - Validate twin/next/cell incidence, cycle orientation, connected components, boundary loops, and Euler characteristic against the source mesh.
  - Measure deterministic peak owned storage from actual container capacities, including retained complex storage and major temporary arrangement buffers; retain the legacy ratio field only as an alias of the measured ratio.
  - Evidence: `SurfaceArrangementPhase16.AuthoritativeTopologyDiagnosticsMatchSingleDiskSource`, `AuthoritativeTopologyDiagnosticsHandleDisconnectedSourceComponents`, `NestedCyclesAreClassifiedAsNonDiskInsteadOfDefaultDisk`, `HardBarrierCrossingsAreUniqueTransverseAndLocalizedToIncidentCells`, `PeakMemoryMeasurementUsesOwnedCapacityAndBoundsRetainedStorage`, and `CurvedMultiFaceFixturePreservesStitchedTopologyAndEulerCharacteristic`.
  - Implementation: explicit closed-cycle, boundary-component, and cell Euler metadata; authoritative topology diagnostics and aggregate validity; per-node hard-barrier crossing evidence; source/arrangement topology comparison; deterministic owned-memory peak accounting; embedded 3D polygon measurement; and source-boundary-oriented exterior classification for curved open surfaces.
  - Corrected closeout evidence: `MilestoneDClosure.CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces`, `CylindricalOpenStrandCommitsWithTopologyPreserved`, and the complete Phase 16 focused suite.

- [x] **P13. Generate real simplification candidates.**
  - Deterministically extract connected open-strip and closed-loop candidates from canonical undirected arrangement edges grouped by field family and strand.
  - Emit redundant-strand candidates when one logical strand is split into multiple arrangement segments.
  - Attach canonical halfedges, affected nodes, cells, strands, source-sheet boundaries, protection flags, removed length, objective terms, feasibility metadata, and stable IDs.
  - Preserve protected candidates for diagnostics while assigning explicit feature/topology penalties so P14 can reject them transactionally rather than silently omitting evidence.
  - Wire the live SurfaceCells path to pass the extracted candidate set into simplification instead of an empty vector.
  - Evidence: `SurfaceComplexSimplificationPhase17.CandidateExtractionIsDeterministicAndCarriesAuthoritativeSupport`, `OversampledArrangementGeneratesRealNonemptyCandidateSet`, and `CandidateExtractionMarksProtectedSupportInsteadOfSilentlyDroppingIt`.
  - Corrected closeout evidence: `MilestoneDClosure.DisconnectedSameStrandProducesConnectedCandidates`, `BranchedStrandIsTopologyChangingRegionCandidate`, and the planar/cylinder benchmark smoke run.
  - Disposition: P13 code-complete for Milestone D scope; complete local focused-target evidence remains part of `.agents/test-d.ps1`.

- [x] **P14. Apply simplification as transactional complex mutation.**
  - Trial each candidate on a copied complex and commit only after authoritative incidence, disk-cell, Euler-delta, and protected-support validation.
  - Remove the selected undirected arrangement edges, merge the incident cells through their ordered exterior boundary, rebuild halfedge IDs/twins/next/cell ownership, and compact orphaned nodes.
  - Reject malformed boundary unions, topology-changing Euler deltas, non-disk results, stale supports, objective regressions, and protected feature/boundary edits without mutating the live complex.
  - Invalidate the pre-commit queue after every successful mutation and deterministically re-extract/requeue candidates from the committed complex.
  - Preserve exact before/after structural hashes and rejection reasons for every transaction; rejected transactions retain identical hashes.
  - Evidence: `SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex`, `ComplexRollbackPreservesHashOnRejectedTrial`, `ComplexCandidateRecomputationCreatesRealQueuedCandidates`, `TransactionalMutationCommitsExtractedOversampledCandidate`, and `TransactionalMutationPreservesHardRailSupport`.
  - Corrected closeout evidence: `MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed`, `CompleteInterfaceCommitsAndPreservesProtectedRails`, `CylindricalOpenStrandCommitsWithTopologyPreserved`, and the planar/cylinder benchmark smoke run.
  - Disposition: P14 code-complete for Milestone D scope; formal closeout remains pending the full local `.agents/test-d.ps1` evidence archive.

**Milestone D tests**

- [x] Two-triangle stitching produces one shared arrangement edge, not two face-local copies.
- [x] Curved multi-face and source-vertex-junction fixtures preserve provenance and Euler characteristic.
- [x] Open-cylinder exterior classification remains valid without requiring one global tangent-plane projection.
- [x] Oversampled planar and cylindrical fixtures generate nonzero connected candidates.
- [x] Partial multi-edge interfaces fail closed; complete interfaces commit transactionally.
- [x] Oversampled planar and cylindrical fixtures commit valid edits while preserving Euler characteristic and boundary loops.
- [x] Rejected edits leave an identical structural hash.
- [x] Hard rails, boundaries, singularities, and local-sheet identity are protected transactionally.

**Milestone D benchmark**

- [x] Dedicated benchmark reports arrangement time, candidate-generation time, queue work, commits, rejection histogram, cell/halfedge reduction, and validator passes.
- [x] Dense and simplified complexes are compared on the same planar and open-cylinder fixtures.
- [x] Archive one warm-up plus five Release measurements, peak working set, environment metadata, and summary by running `.agents/test-d.ps1` locally.

**Milestone D exit gate**

- [x] Live simplification receives real candidates and changes the complex on oversampled planar and cylindrical fixtures.
- [x] No empty-candidate call may be reported as completed simplification.
- [x] Committed mutations preserve authoritative topology and exact protected support.
- [x] Formal closeout evidence from `.agents/milestone_d_closeout/` is complete and all local checks pass.

See `.agents/Milestone_D.md` for the corrected verification record and exact disposition.

## Milestone E — Produce genuine pure-quad output

- [x] **P15. Implement patch descriptors and feasibility checks.**
  - Derive ordered patch sides, turns, boundary subdivisions, singularities, feature constraints, and disk status from the complex.
  - Support planned 3-, 4-, 5-, and 6-sided patches.
  - Enforce parity, side-count inequalities, turn constraints, and singularity/valence compatibility.
  - Implementation evidence: `include/directional/geometry/PatchDescriptor.h` derives deterministic boundary cycles, ordered sides, subdivisions, rails/curves, source provenance, disk status, and interior singularity metadata from `SurfaceCellComplex`; `tests/PatchDescriptorMilestoneETests.cpp` covers 3/4/5/6-sided fixtures and rejection cases. The live completion stage now consumes these descriptors.
  - Verification disposition: the direct Clang C++20 focused suite passed all `PatchDescriptorMilestoneE.*` tests, and a syntax-only translation unit including the live pipeline passed. The project Release target remains part of `.agents/test-e.ps1` local closeout evidence.

- [x] **P16. Implement general patch completion.**
  - Use explicit tested templates for regular quads and 2:1 transitions.
  - Implement closed-form/pattern-based completion for supported N-sided patches.
  - Use a bounded local combinatorial solver only as fallback.
  - Prohibit center-fan completion as a production solution.
  - Implementation evidence: `PureQuadCompletion.h` now provides a tensor-product rectangular template, an explicit conforming six-boundary-edge transition template, deterministic N-sided boundary patterns, and a bounded anchor search fallback. Every accepted completion is validated as a connected disk with the complete authoritative boundary, interior edge incidence two, no duplicate quad corners, and Euler characteristic one.
  - Correctness boundary: P16 fails closed for missing provenance, excessive search size, invalid topology, and interior singularities. Required valence-3/5 pole construction remains P17 rather than being fabricated by P16.
  - Verification evidence: `PureQuadCompletionPhase18.*` contains 38 focused tests including regular, transition, general-pattern, bounded-fallback, provenance, topology, global stitching, and fail-closed cases. The direct Clang C++20 focused suite passed 38/38; run `.agents/test-e.ps1` locally for the authoritative project Release build.

- [x] **P17. Make pole and strip rewrites real.**
  - Encode pole relocation, strip reduction, radial transition, and loop redirection as guarded local mutations.
  - Every template must define preconditions, affected topology, feature restrictions, expected valence changes, rollback rules, and post-validation.
  - Implementation evidence: `PureQuadCompletion.h` now provides explicit valence-3/5 singularity pole templates and a transactional `apply_guarded_topology_mutations()` API. Mutations operate on real quad connectivity, validate removal indices and pre-valences, protect feature edges, optionally preserve the local boundary and Euler characteristic, verify requested post-valences, and commit only after all checks pass; rejected mutations leave the prior mesh unchanged. The rewrite catalog can report a commit only after the corresponding guarded connectivity mutation commits; the former caller-supplied validation boolean was removed.
  - Correctness boundary: pole completion is intentionally limited to the canonical two-boundary-edges-per-sector pattern. Other singularity layouts fail closed for a later bounded template expansion rather than fabricating a pole.
  - Verification evidence: `PureQuadCompletionPhase18.*` includes focused valence-3/5 pole, wrong-pattern rejection, real catalog-routed connectivity mutation, invalid-mutation rejection, committed loop-redirection, protected-feature rollback, and valence rollback tests. Run `.agents/test-e.ps1` locally for the authoritative project build and pipeline regressions.

- [x] **P18. Prove output lineage.**
  - Map every output quad to its source patch and completion operation.
  - Map every output vertex to source triangle/barycentric provenance or an ordered feature interval.
  - Add a test that rejects output composed solely of paired source-triangle boundaries on the proof fixture.
  - Implementation evidence: `PureQuadCompletion.h` now records per-quad source patch and completion backend/local operation index, records every vertex as source-triangle/barycentric provenance or an ordered rail/feature interval, validates complete lineage, and detects outputs whose quads are solely boundaries of adjacent source-triangle pairs. The live completion stage remaps and retains lineage through aggregate output, always fails closed when lineage is incomplete, and applies paired-boundary rejection only when the explicit proof-fixture gate is enabled; geometric coincidence alone is not a general failure for minimal valid patches.
  - Verification evidence: `PureQuadCompletionPhase18.P18*` covers patch/operation lineage, ordered feature intervals, generated interior provenance, missing lineage, strict proof rejection, and diagnostic-only paired-boundary detection. `SurfaceCellPipelinePhase20.PairedBoundaryProofGateIsExplicit` verifies the live option boundary.

**Milestone E tests**

- [x] Separate fixtures exercise 3-, 4-, 5-, and 6-sided patches.
- [x] Odd parity is repaired or rejected deterministically.
- [x] 2:1 transitions contain no hanging nodes or T-junctions.
- [x] Required valence-3 and valence-5 singularities are represented correctly.
- [x] No center fan, placeholder unit-circle geometry, or caller-supplied validation boolean can create success.

Verification evidence: `PatchDescriptorMilestoneE.*` and
`PureQuadCompletionPhase18.*` cover all listed cases. Generated interior
vertices are projected onto the patch's authoritative source-triangle set;
missing projection/provenance fails closed. Completed patches are stitched by
global arrangement-node identity, with edge- and vertex-manifold checks,
ordered boundary-loop reconstruction, duplicate-quad rejection, and complete
lineage remapping. Completion fails closed if any authoritative complex cell is
invalid or incomplete, preventing a successful partial-surface result.

**Milestone E exit gate**

- [x] Plane and cylinder produce manifold pure quads through completed patches.
- [x] The proof fixture contains genuine generated topology and no source-triangle-pair fallback.

Gate scope: this milestone begins with the authoritative
`SurfaceCellComplex` produced by Milestone D. The same
`complete_surface_cell_complex()` entry point is used by the live pipeline and
the closeout fixtures. `MilestoneEPlaneProducesGeneratedManifoldPureQuadTopology`
proves generated interior topology and rejects source-triangle-pair-only
lineage. `MilestoneECylinderStitchesPeriodicPatchBoundaries` proves a connected
periodic open-cylinder result with two boundary loops and Euler characteristic
zero. Raw-field-to-complex cylinder failures remain Phase 20/upstream
arrangement integration failures and do not permit Milestone E to fabricate a
replacement complex.

Formal local closeout:

- [x] Run `.agents/test-e.ps1` and archive its focused Release build, Phase 20
  regression, and full-suite artifacts under `.agents/milestone_e_closeout/`.

Milestone E is closed by the archived code-level and local test evidence. The
retired `.agents/validate_phase_records.ps1` script is not part of current or
future closeout requirements.

## Milestone F — Optimize and validate authoritatively

- [x] **P19. Project and optimize on source triangles.**
  - Use BVH source-triangle projection while preserving component, sheet, face, and barycentric provenance.
  - Interpolate source normals, 4-RoSy field values, and local target size from provenance.
  - Keep feature vertices on explicit ordered curve intervals.
  - Completion evidence: `SurfaceProjectionBvh` is cached across an optimization run; constrained projection fails closed when component/sheet authority cannot be satisfied; face and barycentric provenance are refreshed after each accepted projection; per-vertex source normals and target sizes are barycentrically interpolated; per-vertex cross values are interpolated in degree-four power space; and authoritative rail samples are converted into explicit ordered curve segments with stable curve, rail, interval, and rail-parameter identities. Focused tests: `SurfaceMeshOptimizerPhase19.*` (23 tests) and `MilestoneFP19Integration.*` (4 tests).

- [x] **P20. Implement derivatives for every enabled energy.**
  - Surface distance.
  - Feature distance and interval order.
  - Normal agreement.
  - Cross-field alignment with deterministic 4-RoSy branch choice.
  - Local size, including barycentrically varying source-triangle size data.
  - Orthogonality and aspect/shape regularization.
  - Valence/pole regularization where applicable; the fixed-connectivity valence term has an explicit zero positional derivative.
  - Completion evidence: `evaluate_surface_optimization_gradient()` returns per-energy and weighted-total derivatives; the optimizer uses that direct derivative instead of finite-differencing the complete objective; fixed vertices receive zero motion; invalid order/orientation/provenance trials remain transactional and roll back; closed-form geometric derivatives and local source-data pullbacks agree with centered finite differences on constant and barycentrically varying source fixtures. The Armijo sufficient-decrease check now scales with the actual descent-direction norm instead of clamping it to one. Focused tests: `SurfaceMeshOptimizerPhase20.*` (9 tests), plus the retained `SurfaceMeshOptimizerPhase19.*` regression suite.

- [x] **P21. Correct quality and error metrics.**
  - Signed scaled Jacobian is evaluated at every corner against a source normal sampled at the quad centroid, including rotated/non-XY surfaces.
  - Convexity, diagonal-independent warpage, minimum/maximum angle, aspect ratio, and Jacobian distributions are reported and gated.
  - Deterministic 3x3 bilinear quad sampling and seven-point source-triangle sampling provide normalized quad-to-source and source-to-output error; component/sheet-incompatible samples and mixed-authority output faces fail closed instead of projecting onto a nearby sheet.
  - Normal overlays sample the source at each quad centroid; field overlays sample the source cross at each output-edge midpoint; reverse surface coverage and valence target/error channels are exposed.
  - Boundary targets distinguish geometric corners (valence 2) from straight boundary samples (valence 3), allow explicit overrides, and compare required singularity valence `4 - indexNumerator` for interior source singularities and `3 - indexNumerator` for boundary source singularities after deterministic source-to-output mapping; conflicting singularities mapped to one output pole produce an impossible target and fail closed.
  - Completion evidence: `SurfaceFinalValidationReport` carries bidirectional approximation, convexity, warpage, angle, aspect, Jacobian, sample-count, and valence-contract results; `SurfaceOptimizationOverlay` carries output-to-source, source-to-output, normal, field, size, actual-valence, target-valence, and valence-error channels. Focused tests: `SurfaceMeshOptimizerPhase21.*` (9 tests), plus retained P19-P20 regression tests (41 tests total).

- [x] **P22. Make final validation source-authoritative.**
  - Compare source and output connected-component counts, Euler characteristic, and the complete set of ordered boundary cycles.
  - Verify authoritative boundary and hard-feature rail edge sequences using output-vertex identities produced by the rail-constraint builder.
  - Require complete finite source-triangle provenance, normalized barycentric coordinates, source-position reconstruction, source-component labels, and local-sheet labels for every output vertex.
  - Reject output faces whose vertices mix source components or local sheets.
  - Validate output orientation against the authoritative source-triangle normal.
  - Retain duplicate-face, nonmanifold-incidence, bow-tie, self-intersection, and geometric T-junction checks.
  - Use AABB-tree broad-phase acceleration for output-face intersections and output-edge T-junction queries.
  - Run the same source-authoritative hard-invariant validator on every optimizer line-search trial and reject invalid trials transactionally.
  - Completion evidence: `SourceAuthoritativeMeshValidator.h`, output-index authority in `SurfaceOptimizationRailConstraints.h`, live opt-in from `RemeshPipeline.h`, `SurfaceMeshOptimizerPhase22.*` (12 tests), and `SourceAuthoritativeMeshValidatorPhase22.*` (2 focused geometry tests). The optimizer line-search orientation gate now resolves each quad's reference source normal from authoritative vertex provenance instead of indexing provenance by output-face ID. The complete focused inventory is 59 tests: 23 P19, 9 P20, 9 P21, 12 P22, 4 integration, and 2 standalone validator tests.

**Milestone F tests**

- [x] Finite-difference tests cover every enabled optimizer term, feature interval order, 4-RoSy branch selection, and barycentrically varying source normal/field/size data.
- [x] Rotated/non-XY fixtures validate orientation against local normals.
- [x] P21 reverse-sampling fixtures and P22 provenance/component/sheet checks fail closed on opposite-sheet or mixed-sheet authority.
- [x] Coplanar overlap, geometric T-junction, duplicate face, missing provenance, hard-feature rail, multiple-boundary-cycle, Euler-change, and boundary-order fixtures fail correctly.
- [x] Optimization cannot worsen any source-authoritative hard invariant; rejected line-search trials leave the accepted geometry and topology unchanged.

**Milestone F benchmark**

- [x] A reproducible Release benchmark target reports optimization iterations, accepted iterations, line-search trials and rejection causes, per-energy change, projection queries, optimization and validation time, end-to-end time, coefficient of variation, and peak working set.
- [x] Targeted reference run on the deterministic 16x16 planar grid completed one warm-up and five measured runs with all strict source-authoritative checks enabled and all outputs accepted. The median validator-overhead ratio was below 4%, below the 5% target, and timing CV was below 1%. This synthetic result does not replace Milestone G's representative production-asset matrix.

**Milestone F exit gate**

- [x] Code-level P19-P22 correctness, strict validation, transactional rejection, telemetry, and deterministic medium-fixture benchmark gates are implemented and pass targeted review-environment checks.
- [x] Run `.agents/test-f.ps1` locally and archive the focused Release suite, benchmark JSON, Phase 20 pipeline regression suite, and full test-suite artifacts under `.agents/milestone_f_closeout/`.

Milestone F is code-complete through P22 in this snapshot. Formal project closeout remains pending the local Release script because the full pipeline and full suite were intentionally not run in the constrained review environment. The backend remains `default-off experimental`; Milestone G owns representative assets, production dispatch, fallback semantics, and the final default-on decision.

## Milestone G — Integrate, benchmark, and decide production status

- [x] **P23. Correct pipeline and fallback semantics.**
  - `ReturnInputMesh` is the canonical enum, parser, CLI, diagnostic, and benchmark name. `ReturnQuadDominant` remains only as a deprecated enum/parser alias and is never serialized.
  - `Fail` and `ReturnInputMesh` use one failure path for early raw-field validation, authoritative `CrossFieldResult` validation, unsupported component scheduling, and late stage failures.
  - **Production contract amendment (2026-08-01): a failed SurfaceCells request must never enter `setup_integration()`, `integrate()`, or the `LegacyInteger` mesher.** `TryLegacy` is retained only as a deprecated source-compatible alias of `Fail`; the parser and CLI reject it, and no runtime branch invokes the legacy backend.
  - Under `Fail`, the original SurfaceCells terminal code/stage remains authoritative, no output mesh is returned, `executedBackend=SurfaceCells`, `surfaceCellFallbackAttempted=false`, `surfaceCellUsedLegacyFallback=false`, and all legacy integration/mesher timings and factorization counters remain zero.
  - `ReturnInputMesh` remains an explicitly requested non-remeshing disposition and cannot satisfy any SurfaceCells production gate.
  - Requested backend, executed backend, original SurfaceCells failure, fallback cause, terminal failure, output origin, and remesh-occurrence state are preserved independently.
  - Evidence: `tests/MilestoneGP23Tests.cpp`, the updated `SurfaceCellPipelinePhase20` regressions, focused target `directional_milestone_g_p23_tests`, and `.agents/test-p23.ps1`.

- [x] **P24. Correct diagnostics and timing.**
  - Derive every count from the actual stage result.
  - Give every count an availability flag.
  - Measure each interval from its own start time.
  - Set overall pipeline time on every return path.
  - Count provenance from the actual output.
  - Preserve last-valid-stage artifacts on injected and real failures.
  - Availability follows all-components semantics during aggregation; mixed output origins and fallback causes are explicit, and component-local lineage hashes retain component indices.
  - Benchmark and CLI diagnostics serialize the new timing, availability, and component-lineage fields.
  - Evidence: `tests/MilestoneGP24Tests.cpp`, updated diagnostics and Phase 20 regressions, focused target `directional_milestone_g_p24_tests`, and `.agents/test-p24.ps1`.

- [x] **P25. Complete deterministic integration coverage.**
  - Deterministically split disconnected source components and execute both one-worker and bounded-parallel schedules through the same SurfaceCells implementation.
  - Remap authoritative field rows, source-edge transition identities, matching/effort, singular vertices/indices, confidence, source labels, local sheets, rails, provenance, and lineage between global and component-local identities.
  - Merge polygonal output with explicit face degrees, component-indexed stage lineage, diagnostics, final optimization/validation context, and fallback state in deterministic source-component order.
  - Return no partial mesh when a required component fails under `Fail`; retain the exact failed component, original face identity, terminal code, and stage.
  - Compare sequential/parallel structure and stage identities, repeat parallel runs, and inject failures after every live stage.
  - Evidence: `tests/MilestoneGP25Tests.cpp`, updated component and Phase 20 regressions, focused target `directional_milestone_g_p25_tests`, and `.agents/test-p25.ps1`. Formal MSVC Release pass evidence remains a local script output.

- [x] **P26. Add the production fixture matrix and deterministic recovery coverage.**
  - Added deterministic rectangular plane, periodic cylinder, torus, thin bent tube, close-sheet, prescribed-sphere, multi-face seam, and mechanical analytic fixtures with degree-4 raw fields; added the externally supplied canonical bunny1k mesh with a committed field for its exact face order.
  - Added paired SurfaceCells/LegacyInteger manifest entries, licensing notes that distinguish generated analytic assets from the external bunny artifact, and SHA-256 asset records.
  - Corrected open-boundary raw-field finalization so aggregate boundary turning is not misclassified as a point singularity.
  - Added field-aligned source-cell recovery using deterministic minimum-cost perfect matching over degree-at-most-two candidate components; incomplete, higher-degree, or equal-cost ambiguous inputs fail closed.
  - Candidate source-triangle pairs identify source cells only. Every accepted cell is refined into four new quads using source-edge midpoints and a source-surface center, preventing source-triangle-pair-only output from satisfying the gate.
  - Preserved source-surface provenance, vertex lineage, quad lineage, component/sheet labels, validation, and explicit recovery diagnostics.
  - Corrected the production validation path: recovered topology now receives a deterministic target-size field feasible for its actual edge graph, with a public 2x fail-closed relaxation bound and serialized diagnostics; quad orientation uses source geometry plus provenance; source-edge/source-vertex points support every incident local-sheet chart during rail assembly and final validation; pair-boundary-only output is always rejected; component-local recovery targets are deterministically remapped to original source-vertex order only for complete all-recovery results.
  - Added `tests/MilestoneGP26Tests.cpp` with truthful terminal coverage for all nine fixture families, named validated-success gates for plane/cylinder/torus/multi-face-seam/mechanical, bounded recovery-target and incident-sheet rail regressions, explicit atomic-failure semantics for unsupported final-validation cases, updated cylinder/seam/close-sheet Phase 20 regressions, focused target `directional_milestone_g_p26_tests`, and `.agents/test-p26.ps1`.
  - MSVC Release evidence on 2026-07-30: all 61 focused P26/Phase 20 tests passed, the complete `directional_phase1_tests` binary passed all 453 tests, and focused P23 (51), P24 (59), P25 (57), Milestone F optimizer (55), and source-authoritative validator (2) suites passed. The repeated paired benchmark archive remains P27 work.

- [ ] **P27A. Enforce pure SurfaceCells production benchmarking.**
  - Every SurfaceCells correctness, performance, and production-disposition run must set `fallbackPolicy=Fail`.
  - A SurfaceCells run is classified as failed unless `requestedBackend=SurfaceCells`, `executedBackend=SurfaceCells`, `surfaceCellUsedLegacyFallback=false`, `surfaceCellFallbackAttempted=false`, and `surfaceCellOutputOrigin=CompletedSurfaceCells`.
  - Failed SurfaceCells runs must terminate at their real SurfaceCells failure stage with no output mesh; they must not continue into legacy integration to obtain comparison output.
  - Benchmark JSON must record `setupIntegrationSeconds=0`, `integrationTotalSeconds=0`, `setupMesherSeconds=0`, `mesherTotalSeconds=0`, `integration.integerIterations=0`, `integration.directFactorizations=0`, and `integration.numericFactorizationSeconds=0` for every SurfaceCells run. Automatic cross-field synthesis is an upstream field-generation concern and must not be confused with the prohibited MIQ-style integration stage.
  - LegacyInteger remains a separately requested comparison backend only. It must be run as its own manifest case, never as a fallback or continuation of a SurfaceCells case.
  - Tests must use fixtures that would genuinely permit legacy execution, inject or reproduce a real SurfaceCells failure, and prove that the run still terminates before any integration/factorization counters change. Do not satisfy this gate with malformed data that would have prevented both backends from running.

- [x] **P27. Compare against `LegacyInteger`.**
  - [x] Emit diagnostics for every run, including failed runs with precise terminal code/stage.
  - [x] Emit wall/per-stage time, peak working set, and deterministic output structural hash.
  - [x] Archive an output mesh for every successful run and a review image for every run, including source-only failure images with an explicit failure mark.
  - [x] Emit pure-quad rate and nonmanifold, T-junction, duplicate-face, and self-intersection counts.
  - [x] Emit topology and ordered-boundary preservation.
  - [x] Emit hard-feature recall/alignment and cross-field alignment.
  - [x] Emit local-size error and bidirectional surface approximation.
  - [x] Emit irregular vertex count and valence distribution.
  - [x] Align the prescribed-sphere fixture key across the manifest, closeout script, and review-decision schema.
  - [x] Add benchmark-schema tests that reject any successful run missing a required quality field or artifact and prove failed-run review evidence is emitted.
  - [x] Execute one warm-up plus five measured MSVC Release runs for all 18 paired cases and archive raw JSON without discarding failures.
  - [x] Require CV <= 10% for every successful timing result used in the comparison.
  - Evidence: `build/milestone-g-p26-production-fix-verify/p27-release-evidence-r4/benchmark.json`, `comparison.json`, `support-matrix.json`, `raw_results.json`, and `summary.md`.
  - Accepted timing evidence has one structural hash per successful case and CV between 0.41% and 4.05%. Earlier `p27-release-evidence` and integrated `p27-closeout-r1/r2` runs are retained as rejected timing experiments because at least one successful case exceeded the 10% CV gate. `p27-release-evidence-r3` passed its timing gates but was superseded after unenforced optimizer timing was removed from the validation structural hash and covered by a determinism regression.
  - SurfaceCells succeeds in all five measured runs for 8/9 fixtures. `bunny1k__surface_cells` fails all five runs atomically as `NotProductionReady/completion`, with `surfaceCellOutputOrigin=None`, no output mesh, and no fallback.
  - LegacyInteger succeeds in all five measured runs for only plane and multi-face seam. Its remaining seven fixture pairs fail explicitly and retain diagnostics and review images.

- [x] **P28. Make an explicit production decision for the current evidence state.**
  - `default-on` only if every mandatory correctness gate passes and representative performance is acceptable.
  - `default-off experimental` if correctness is limited to a documented support matrix or performance/validator gates fail.
  - `prototype only` if cylinder closure, global arrangement, general patch completion, or authoritative validation remains unproven.
  - Current disposition: **`default-off experimental`**. P26/P27 correctness, benchmark, artifact, and qualitative-review evidence is complete, but SurfaceCells supports only 8/9 mandatory fixtures. The canonical bunny remains an explicit atomic completion-stage rejection, so `default-on` is not justified. The implementation is beyond `prototype only` because cylinder closure, torus/global topology, general fixture completion, source-authoritative validation, deterministic component execution, and the full suite all pass.

### Next concrete pursuable goals before `default-on`

- [ ] **C1. Isolate the bunny completion rejection.**
  - Archive the simplified arrangement, completion input boundaries, rejection reason, and source-grid candidate graph for `bunny1k`.
  - Add a focused regression that reproduces the first unsupported completion invariant without running the complete benchmark.
  - Exit gate: the failure is assigned to one named invariant with deterministic evidence; do not attribute it to classification without a causal test.
- [ ] **C2. Define and expose classifier policy.**
  - Decide whether unmarked sharp manifold bends are traversable sheets or implicit barriers.
  - Move normal compatibility, close-sheet radius, and geodesic depth into `SurfaceCellOptions` with documented units and fail-closed ranges.
  - Exit gate: defaults preserve the current 8/9 support matrix and a policy-specific sharp-bend test distinguishes intended behavior.
- [ ] **C3. Close classifier coverage.**
  - Add cylinder, sphere, elbow, coarse curved strip, scale `1e-3/1/1e3`, nonmanifold, and inconsistent-normal fixtures.
  - Exit gate: label hashes are deterministic and ordinary curvature remains traversable while true close sheets remain distinct.
- [ ] **C4. Bound classifier cost.**
  - Replace all-face conflict scanning with a deterministic spatial index.
  - Exit gate: medium-fixture labels are structurally identical and classifier wall time/working set meet an archived bound.
- [ ] **C5. Repeat the production decision.**
  - Require 9/9 atomic validated SurfaceCells success, five stable structural hashes per case, CV <= 10% for every compared timing, all qualitative reviews `Pass`, and the complete suite green.
  - Exit gate: rerun `.agents/test-g.ps1` with `-ProductionDisposition default-on`; the script must pass without weakening any validator or fallback gate.

**Milestone G exit gate**

- [x] Full test binary passes (484/484, MSVC Release, 2026-07-30).
- [x] Milestone records, closeout artifacts, and production disposition agree with the code and measured results.
- [x] Benchmark archive validation passes.
- [x] Every successful fixture output mesh and every backend/fixture review image, including failed-run evidence, is archived.
- [x] Production disposition is supported by measured evidence rather than stage-call presence.

# 6. Work-package details

## R0 — Records, diagnostics, and false-success removal

**Targets**

- `.agents/Phase_10.md` through `.agents/Phase_20.md`
- `.agents/Directional_Surface_Cell_Quadrangulation_Implementation_Plan.md`
- `.agents/Surface_Cell_Backend_Correction_Plan.md`
- `include/directional/pipeline/RemeshPipeline.h`
- `tests/SurfaceCellPipelinePhase20Tests.cpp`

**Success criteria**

- The current stage wiring is described accurately.
- Source-triangle pairing cannot masquerade as SurfaceCells success.
- Diagnostics expose the true output origin.

## R1 — Typed context and complete field contract

**Targets**

- `include/directional/fields/PointSampledCrossField.h`
- `include/directional/fields/CrossField.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `tests/SurfaceCellsPhase10Tests.cpp`
- `tests/SurfaceCellPipelinePhase20Tests.cpp`

**Success criteria**

- SurfaceCells construction receives matching and singularity metadata.
- Raw field overloads adapt to the complete contract.
- Nominal tests no longer bypass metadata requirements.

## R2 — Shared constraints

**Targets**

- `include/directional/geometry/AdaptiveFeatureMap.h`
- `include/directional/geometry/AdaptiveTargetSize.h`
- `include/directional/geometry/ReliefTopology.h`
- pipeline context and consumers

**Success criteria**

- Ordered boundary/feature rails and local size are authoritative across all stages.
- Unsupported heat and skeleton options fail fast and are excluded from acceptance claims.

## R3 — Tracing and cells

**Targets**

- `include/directional/geometry/SurfaceCellTracing.h`
- `tests/SurfaceCellTracingPhase14Tests.cpp`

**Success criteria**

- Matching-aware branches produce closed intrinsic cell proposals.
- Cylinder periodic closure passes.

## R4 — FlowRep

**Targets**

- `include/directional/geometry/FlowRepStrands.h`
- `tests/FlowRepStrandsPhase15Tests.cpp`

**Success criteria**

- Sparse selection has real coverage/cycle evidence.
- Network simplification is embedded, deterministic, and transactional.

## R5 — Arrangement

**Targets**

- `include/directional/geometry/SurfaceArrangement.h`
- `tests/SurfaceArrangementPhase16Tests.cpp`

**Success criteria**

- Multi-face stitching creates one global complex with preserved topology and provenance.

## R6 — Simplification

**Targets**

- `include/directional/geometry/SurfaceComplexSimplification.h`
- `tests/SurfaceComplexSimplificationPhase17Tests.cpp`

**Success criteria**

- Candidate generation is nonempty on oversampled fixtures.
- At least one real valid complex edit commits.

## R7 — Completion

**Targets**

- `include/directional/geometry/PureQuadCompletion.h`
- patch/template helpers under `include/directional/meshing/`
- `tests/PureQuadCompletionPhase18Tests.cpp`

**Success criteria**

- Supported 3-6 sided patches produce conforming pure quads without center fans.

## R8 — Optimization and validation

**Targets**

- `include/directional/geometry/SurfaceMeshOptimizer.h`
- `include/directional/validation/MeshValidator.h`
- `tests/SurfaceMeshOptimizerPhase19Tests.cpp`
- `tests/SurfaceCellsPhase10Tests.cpp`

**Success criteria**

- All enabled energies have verified derivatives.
- Strict source-authoritative validation passes.

## R9 — Pipeline semantics

**Targets**

- `include/directional/pipeline/RemeshPipeline.h`
- `include/directional/pipeline/ParallelRemeshPipeline.h`
- diagnostics structures and serializers
- Phase 20 tests

**Success criteria**

- Every stage consumes the preceding typed product.
- Failure and fallback reporting is precise.
- Only completed surface cells can produce SurfaceCells success.

## R10 — Benchmarks and disposition

**Targets**

- `src/bench/DirectionalBenchmark.cpp`
- benchmark manifests and archive validator
- fixed qualitative artifact scripts
- Phase 10-20 records

**Success criteria**

- Complete fixture matrix and A/B results are archived.
- Disposition is determined from mandatory gates.

# 7. Mandatory final quality gates

The backend cannot move beyond `default-off experimental` unless all mandatory gates pass.

| Gate | Mandatory threshold |
|---|---|
| Face degree | 100% quads on supported fixtures |
| Manifoldness | zero nonmanifold output edges/vertices |
| Conformity | zero T-junctions and hanging nodes |
| Self-intersection | zero detected intersections |
| Provenance | 100% output vertices and edges valid |
| Source sheet | zero opposite-sheet jumps |
| Topology | components, Euler characteristic, and ordered boundary loops preserved |
| Hard features | 100% required rails represented by ordered output edges |
| Determinism | identical structural hashes for repeated runs; parallel equivalence where supported |
| Output origin | `CompletedSurfaceCells` only |
| Cylinder | periodic closure with no seam break |
| General completion | 3-, 4-, 5-, and 6-sided supported patch tests pass |
| Benchmark stability | CV <= 10% for recorded quantitative comparisons |
| Diagnostics | no unavailable or fabricated value presented as measured |

Quality targets such as field alignment, size error, Jacobian, warpage, irregular-vertex count, and performance must be recorded per fixture. Initial thresholds should be taken from the canonical implementation plan and may be revised only through a documented plan change before evaluating the corresponding experiment.

# 8. Explicit deferrals

Do not expand the remediation scope with these items before R10:

- global heat-method distance support;
- curve-skeleton hints;
- exact or approximate 3D straight skeletons;
- learned topology or feature prediction;
- semantic animation-loop inference;
- unrelated legacy-pipeline refactors;
- automatic default-on enablement.

Dijkstra-based intrinsic distance, existing BVH infrastructure, deterministic local topology templates, and the current legacy backend are sufficient for the remediation path.

# 9. First implementation pass

The first coding pass should contain only P0-P4:

1. correct records;
2. add output-origin and stage-lineage diagnostics;
3. remove source-triangle pairing from SurfaceCells success;
4. introduce the typed pipeline context; and
5. route complete `CrossFieldResult` metadata into the SurfaceCells backend.

**Verification for the first pass**

- Existing legacy tests remain unchanged and pass.
- SurfaceCells planar smoke test no longer succeeds through triangle pairing.
- A complete cross-field fixture reaches feature/metric/relief/tracing with matching and singularity metadata present.
- A missing-metadata fixture fails at input validation with precise diagnostics.
- All modified phase records cite the new test and source evidence.

Do not proceed to feature rails or tracing changes until this first-pass gate is green.
