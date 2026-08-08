# Gate 4 Closed-Genus-One Sheet Coverage — Artifact-Only Test + Benchmark Report

Date: 2026-08-08 UTC  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

Exact artifact **`9015931928`** is runtime-valid and establishes **material G4 progress, but G4 remains active**.

The candidate closes the previous partial-authority escape hatch truthfully:

- new sheet-coverage semantics pass **3/3**;
- prior G4 periodic-relation semantics remain **5/5**;
- retained G0-G3 focused contracts remain **17/17**;
- direct plane, seam, close-sheets, and cylinder authority remains exact and deterministic **3/3** with unchanged hashes;
- exact torus no longer follows `partial NotApplicable -> 670 generic traces -> 113 embedded arcs -> 0 arrangement cells -> SideSubdivisionRepair:InvalidInputIncidence`;
- torus instead fails immediately and deterministically at `tracing/phase-front` as `Rejected / UnsupportedSourceSheetTopology`;
- three canonical periodic relations are retained before the unsupported sheet is classified;
- no generic downstream arrangement/completion path, fallback, legacy substitution, input return, or source-grid recovery is used.

Immutable packaged-source and source-topology analysis identifies the next missing producer class: the torus hard-feature partition contains three Euler-zero annular sheets already covered by the periodic producer and two **curved topological disk sheets** (`chi=1`, one boundary loop) that are neither planar rectangular bounded sheets nor periodic annuli. The first unsupported disk contains source face 48. The next Code + Build target is therefore a generalized **curved bounded disk-sheet phase-front producer**, not feature demotion, annulus coercion, generic completion repair, or fixture-specific handling.

## Exact artifact authority

Artifact:

- ID **`9015931928`**;
- name `g4-sheet-coverage-code-build`;
- workflow run/job `31237248211 / 93051938159`;
- workflow/downloaded ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- internal `SHA256SUMS` SHA-256 `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`;
- recursive checksums **47/47**;
- package **48 files**, **27 fixtures**, five executables, two project static libraries;
- implementation `856554ce648e5df09ac50f5c94e3e8f098181524`;
- final compile source `a647215b4993338b054f04d4c8e54e7ef5370001`;
- payload cleanup `e46a6d99a45f22f31672c8e5a3367735427d827e`;
- log artifact `9015932044`, SHA-256 `b05c1ef0bf7c5a52ff5dc8158d02c00d11d9cb7637c0a93b0c385a202ad46c50`;
- artifact metadata `runtimeExecution=false`, review policy `never`.

Final packaged source blobs:

| File | Blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `6ebe8f3324be580fc4838b97e5fb449572709236` |
| `src/geometry/SurfaceCellTracing.cpp` | `6b32b48141c16e2d51f1932462566083a7bc3355` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `c038567898f0da7efd6519392c37cbace02b8c1c` |

The validation turn performed **no** configure, compile, link, rebuild, production edit, test edit, fixture edit, validator edit, benchmark edit, or build-system edit.

No runtime-only fixture symlink was required; all packaged executions resolved the immutable fixture tree directly.

## New sheet-coverage semantics — 3/3

All new/strengthened cases pass:

1. `SurfaceCellsPhase10.PhaseFrontComposesBoundedAndPeriodicAuthoritativeSheets`;
2. `SurfaceCellsPhase10.PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority`;
3. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`.

This proves that supported bounded and periodic sheets can compose, produced-then-unsupported authority fails closed with a typed sheet-topology reason rather than partial `NotApplicable`, and the exact torus does not regress to the scalar periodic-holonomy barrier.

## Prior G4 periodic relation authority — 5/5

All five prior semantic regressions remain green:

1. reverse relation descriptions canonicalize without duplicate generator;
2. distinct authoritative sheets retain every relation;
3. unresolved same-sheet basis ambiguity fails closed without order choice;
4. conflicting reciprocal transport fails closed;
5. exact torus does not reject merely because another compatible periodic sheet exists.

No relation ownership is selected by source ID, discovery order, count/frequency, arbitrary subset, or Euclidean proximity.

## Retained G0-G3 focused contracts — 17/17

All previously authoritative focused producer contracts pass unchanged, including source-vertex fan traversal and face-row invariance, duplicate transition typed rejection, source-sheet isolation, annulus topology, periodic cut/holonomy invariance, source-simplex endpoint canonicalization, field-authoritative periodic correspondence, malformed-holonomy typed rejection, and exact committed cylinder/plane producer boundaries.

## Direct G0-G3 regression matrix — deterministic 3/3

All runs use direct `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and strict source-authoritative validation.

| Fixture | Result | Traces | Arrangement | Output | Validation | Field P95 | Hash | Internal wall (s) |
|---|---|---:|---:|---|---:|---:|---|---|
| plane | `Produced / CompletedSurfaceCells` | 352 | 65 | 64 quads / 81 V | 0 | `3.109408068e-05°` | `730caeae49ec872c` | `0.349223 / 0.344934 / 0.345859` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 256 | 65 | 64 quads / 81 V | 0 | `3.490194651e-05°` | `5bdf34d7802e9fb0` | `0.527573 / 0.536590 / 0.522481` |
| close sheets | `Produced / CompletedSurfaceCells` | 1104 | 202 | 200 quads / 242 V / 2 components | 0 | `1.651908724°` | `89b052762f52a5af` | `2.925930 / 2.932440 / 2.975669` |
| cylinder | `Produced / CompletedSurfaceCells` | 1728 | 290 | 288 quads / 320 V | 0 | `8.537736463e-07°` | `32135be51d7a0a26` | `2.703488 / 2.729472 / 2.679084` |

Cylinder retains exactly one periodic relation with rotation `0`, translation `(32,0)`, source route 32, cut 4, 290 simplified cells, zero validation failures, and no fallback/recovery. Independent output-topology inspection finds 64 exterior boundary edges arranged as exactly two degree-2 loops of 32 vertices each, one at z=-1 and one at z=+1. The artificial periodic cut is not exterior.

## Exact torus — typed earliest failure, deterministic 3/3

The committed torus source is still connected, closed, orientable genus one. Three independent direct processes complete with identical structural behavior:

| Run | Internal wall | Peak working set | Relations | Traces | Arrangement | Terminal |
|---|---:|---:|---:|---:|---:|---|
| 1 | `0.008656 s` | `8,597,504 B` | 3 | 0 | 0 | `NotProductionReady:tracing` |
| 2 | `0.008889 s` | `8,720,384 B` | 3 | 0 | 0 | `NotProductionReady:tracing` |
| 3 | `0.008842 s` | `8,880,128 B` | 3 | 0 | 0 | `NotProductionReady:tracing` |

Common diagnostics:

- `surfaceCellAuthoritativeProducerDisposition = Rejected`;
- `surfaceCellFirstInvalidProducerStage = tracing/phase-front`;
- `surfaceCellFirstInvalidProducerReason = UnsupportedSourceSheetTopology`;
- first invalid source face = `48`;
- `surfaceCellPeriodicHolonomyRelationCount = 3`;
- compatibility projection of the first relation remains rotation `0`, translation `(24,0)`, route 24, cut 2;
- trace count = 0;
- arrangement/simplification/completion output counts = 0;
- output origin = `None`;
- no fallback attempt/use, legacy substitution, returned input, or source-grid recovery.

Stable stage identities include:

- feature `f15e4f3be07d3c7f`, count 216;
- metric `34cb872327c9b0c6`, count 72;
- relief `8ccb10d25b69edb9`, count 58;
- tracing `a99e1237a1fe6596`, count 0.

This is the intended material-progress classification: the prior opaque generic zero-cell path is gone and the first unsupported producer topology is now explicit.

## Immutable source/topology diagnosis — curved bounded disk sheets

Read-only analysis of the packaged source and committed torus fixture reproduces the production hard-feature/source-sheet partition without modifying artifact bytes.

Feature authority is unchanged:

- **48 hard feature edges**;
- four hard-edge graph components;
- each component is a closed degree-2 loop with 12 hard edges;
- sharp-angle magnitude is approximately `60.852573736°` on those edges.

This matches the runtime diagnostic of 48 hard edges / four closed feature curves and therefore does not rely on a synthetic sheet partition.

The authoritative classifier yields five source sheets:

| Canonical sheet | Faces | V | E | Euler χ | Boundary edges | Boundary loops | Existing producer class |
|---|---:|---:|---:|---:|---:|---|---|
| 0 | 48 | 36 | 84 | 0 | 24 | 2 × 12 | periodic annulus |
| 1 | 24 | 24 | 48 | 0 | 24 | 2 × 12 | periodic annulus |
| 2 | 26 | 25 | 50 | **1** | 22 | **1 × 22** | unsupported curved disk |
| 3 | 22 | 21 | 42 | **1** | 18 | **1 × 18** | unsupported curved disk |
| 4 | 24 | 24 | 48 | 0 | 24 | 2 × 12 | periodic annulus |

The runtime first-invalid face `48` lies in the first curved disk sheet.

Why current producers cannot cover it:

- `build_uniform_phase_front_for_faces()` is a bounded planar/rectangular producer; the first unsupported disk is strongly non-planar (maximum plane residual approximately `1.936`, versus a source-scale tolerance around `2.816e-9`), so it is structurally outside that producer's contract;
- `build_periodic_annulus_phase_front_for_faces()` requires Euler characteristic 0 and exactly two compatible boundary cycles; the disk has χ=1 and one boundary loop, so it is correctly `NotApplicable` to that producer;
- the second curved disk has the same topology class, χ=1 with one 18-edge boundary loop.

The three annular sheets naturally explain the now-visible relation count of three. No relation count or sheet ID is used as production ownership authority.

## Failure classification

The torus result is a **production implementation incompleteness**, not an invalid fixture or incorrect expectation: the source naturally contains a valid curved bounded disk chart class required by the intended arbitrary-triangle-mesh surface-cell pipeline, while the current producer family supports only planar bounded charts and periodic annuli.

The correct next target is a generalized curved bounded disk-sheet phase-front producer derived from source topology and field transport. It must not special-case face 48, the observed five-sheet partition, relation count three, disk loop sizes, or canonical sheet IDs.

## Bounded suites

Producer suite, excluding the documented long BunnyRandom/Vase design-acceptance cases:

- **107/108** pass;
- the sole failure remains `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`.

The suite now contains two additional passing sheet-coverage cases relative to the prior 105/106 baseline. The failing validator-overhead check remains a sub-millisecond performance threshold, not a G4 semantic regression. Isolated reruns failed 3/3 in this environment:

- `0.000117845 s` vs allowed `0.0001128949 s`;
- `0.000117194 s` vs allowed `0.00010772445 s`;
- `0.000115221 s` vs allowed `0.00009268305 s`.

It remains classified separately as micro-timing/performance evidence; no threshold or assertion was changed.

Completion/simplification remains **154/164** with the exact same ten historical failures:

1. `FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation`;
2. `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion`;
3. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
4. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse`;
5. `SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex`;
6. `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
7. `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate`;
8. `SurfaceComplexSimplificationPhase17.TransactionalMutationPreservesHardRailSupport`;
9. `SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
10. `SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

Validation remains **60/60**. Compiled API remains **8/8**. Bounded aggregate is now **329/340**; the only count increase is from the two added passing sheet-coverage tests, and the prior failure set is unchanged.

## Deferred observations

The prescribed singular sphere remains deferred because torus did not reach direct strict-valid production. Bunny/vase remain later G6 evidence and were not required for this G4 decision. No timeout or stale later-gate result is promoted to current authority.

## G4 gate decision

**G4 remains active.** The sheet-coverage slice satisfies its material-progress condition:

- partial `NotApplicable` whole-surface authority is eliminated;
- three supported annular sheets retain canonical periodic relations;
- the first unsupported source-sheet topology is surfaced directly and deterministically;
- all prior G4/G0-G3 authority is retained;
- no fallback/recovery or hard-feature weakening is used.

The next earliest contract is **authoritative curved bounded disk-sheet phase-front construction** on a non-planar simply connected sheet with a genuine source/hard-feature boundary.

## Next authoritative turn

**Code + Build — G4 curved bounded disk-sheet phase-front producer.**

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Plan.md`.

The next implementation must derive a deterministic intrinsic/transport-consistent bounded chart on non-planar topological disks, preserve source-sheet and hard-feature boundaries, compose with existing planar bounded and periodic-annulus producers, and fail typed at the next genuine invariant if construction is impossible. It must not demote feature rails, treat disks as annuli, weld periodic seams geometrically, special-case torus IDs/counts, or repair generic arrangement/completion first.

Local evidence archive: `directional-g4-sheet-coverage-artifact-only-evidence.tar.gz`, SHA-256 `4bb8e5235adbffc05411c54d378511ae4eea63bf314d7caf0e50f043d5532b47`.
