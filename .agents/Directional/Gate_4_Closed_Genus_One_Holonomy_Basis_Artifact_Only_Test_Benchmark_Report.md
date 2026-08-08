# Gate 4 Closed-Genus-One Holonomy Basis — Artifact-Only Test + Benchmark Report

Date: 2026-08-08 UTC  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

The first G4 multi-relation periodic-authority slice is **material progress but does not close G4**.

Exact artifact `9014730437` removes the previous scalar-holonomy rejection truthfully:

- all five new G4 periodic-relation semantic regressions pass;
- all 17 retained G0-G3 focused contracts pass;
- plane, multi-face seam, close sheets, and cylinder retain their exact G3 direct outputs and hashes in 3/3 independent processes;
- exact torus no longer rejects at `tracing/phase-front / InvalidPeriodicTopology` after the second relation;
- torus retains **two** periodic relations in diagnostics and advances to **670 trace segments**;
- no fallback, legacy substitution, input-mesh return, or source-grid recovery occurs.

The new earliest torus contract is now phase-front **coverage/composition across all authoritative source sheets**. Runtime reports `surfaceCellAuthoritativeProducerDisposition=NotApplicable` after two relations have already been retained. Packaged-source inspection shows `build_uniform_phase_front()` returns the aggregate immediately when any later local sheet is `NotApplicable`, leaving earlier cells/relations partial and never promoting the aggregate to `Produced`. The pipeline therefore disables authoritative phase-front materialization, takes the generic tracing/FlowRep path, builds 113 embedded arrangement arcs but **zero arrangement cells**, and completion terminates with `SideSubdivisionRepair:InvalidInputIncidence`.

The next Code + Build target is therefore **complete deterministic phase-front coverage of mixed bounded/periodic source-sheet charts on the torus**, not completion-side repair. Do not mark a partial phase-front `Produced`; every authoritative source sheet must have valid cell coverage or fail closed with a typed producer reason.

The prescribed singular sphere remains deferred until this earlier torus producer contract is closed.

## Exact artifact authority

Artifact:

- ID `9014730437`;
- name `g4-holonomy-basis-code-build`;
- workflow run/job `31233594490 / 93042009574`;
- workflow ZIP digest and downloaded ZIP SHA-256 `14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec` — exact match;
- internal `SHA256SUMS` digest `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`;
- recursive checksums **46/46**;
- package structure **47 files**, **27 fixtures**, five executables, two static libraries;
- primary implementation `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`;
- final compile source `6e754bdd64482582d39e71184805fbb053c99f86`;
- payload cleanup `8304ba30b0f85bc69deebbf55922f05846d2d5b2`;
- artifact metadata `runtimeExecution=false`, review policy `never`.

Final packaged source blobs were independently verified from the packaged source archive:

| File | Blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `51f80393ecd60e32a9cddc1d60ff0d3a7e6de386` |
| `include/directional/geometry/SurfaceCellTracing.h` | `00d849c21a5af9b871b4ad56bf31c4c74bd705b5` |
| `src/bench/DirectionalBenchmark.cpp` | `87e152f25bc2028c6f5293667712c61f21bc6a8f` |
| `src/geometry/SurfaceCellTracing.cpp` | `cf1d17d5966b3d6904c823046c7dbded017e35ad` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `99976a4481bfa9daaf197e15a3b53b70336e8218` |

No configure, compile, link, rebuild, source edit, test edit, fixture edit, validator edit, benchmark edit, or build-system edit occurred in this turn.

## Runtime-only fixture path exposure

The first focused invocation exposed the expected packaged Actions-path issue only:

`/home/runner/work/Directional/Directional/benchmarks/fixtures/milestone-g/torus.obj` was absent.

The immutable packaged fixture tree was then exposed through the allowed runtime-only symlink:

`/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_holonomy_tb/test-data/benchmarks/fixtures`

No packaged byte was modified. After this symlink, the same exact binary passes the torus semantic witness.

## Focused G4 relation semantics — 5/5

All five new cases pass:

1. `PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`;
2. `PeriodicHolonomyDistinctAuthoritativeSheetsRetainEveryRelation`;
3. `PeriodicHolonomySameSheetDependentBasisFailsClosedWithoutOrderChoice`;
4. `PeriodicHolonomyConflictingTransportFailsClosed`;
5. `ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`.

This proves the intended insertion semantics without selecting by source ID, discovery order, count/frequency, arbitrary subset, or Euclidean proximity.

## Retained G0-G3 focused contracts — 17/17

All previously authoritative focused contracts pass unchanged: ordered source-vertex fan traversal and row-order invariance; duplicate transition typed rejection; embedded-only relief blocking; disconnected close-sheet partition and row-order invariance; annulus topology; periodic cut/holonomy row-order invariance; canonical strip breakpoints; source-simplex endpoint canonicalization with genuine-overlap rejection; field-authoritative and field-ambiguous ring correspondence; exact artificial-cut pairing; malformed-holonomy typed rejection; exact committed cylinder producer boundary; and exact committed plane producer boundary.

## Direct G0-G3 regression matrix — deterministic 3/3

All runs use direct `SurfaceCells`, manifest fallback `Fail`, and `--disable-surface-cell-source-grid-recovery`.

| Fixture | Result | Traces | Arrangement | Quads / vertices | Validation | Field P95 | Hash | External wall |
|---|---|---:|---:|---:|---:|---:|---|---|
| plane | `Produced / CompletedSurfaceCells` | 352 | 65 | 64 / 81 | 0 | `3.109408068e-05°` | `730caeae49ec872c` | `0.38 / 0.38 / 0.37 s` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 256 | 65 | 64 / 81 | 0 | `3.490194651e-05°` | `5bdf34d7802e9fb0` | `0.57 / 0.57 / 0.57 s` |
| close sheets | `Produced / CompletedSurfaceCells` | 1104 | 202 | 200 / 242, 2 components | 0 | `1.651908724°` | `89b052762f52a5af` | `2.98 / 3.01 / 3.03 s` |
| cylinder | `Produced / CompletedSurfaceCells` | 1728 | 290 | 288 / 320 | 0 | `8.537736463e-07°` | `32135be51d7a0a26` | `2.67 / 2.69 / 2.71 s` |

Cylinder retains exactly one periodic relation with rotation `0`, translation `(32,0)`, route 32, cut 4; 290 simplified cells; no fallback/recovery. Independent output-topology inspection records 64 boundary edges in exactly two degree-2 loops of 32 vertices each, at z=-1 and z=+1. The artificial periodic cut is not exterior.

## Exact torus — new earliest G4 behavior

The exact manifest torus is the committed connected closed genus-one source. Three independent processes complete consistently:

| Run | Internal wall | Peak working set | Relations | Traces | Embedded arcs | Arrangement cells | Terminal |
|---|---:|---:|---:|---:|---:|---:|---|
| 1 | `0.205964 s` | `10,350,592 B` | 2 | 670 | 113 | 0 | `NotProductionReady:completion` |
| 2 | `0.198859 s` | `10,665,984 B` | 2 | 670 | 113 | 0 | `NotProductionReady:completion` |
| 3 | `0.200510 s` | `10,268,672 B` | 2 | 670 | 113 | 0 | `NotProductionReady:completion` |

Common diagnostics:

- `surfaceCellAuthoritativeProducerDisposition = NotApplicable`;
- `surfaceCellPeriodicHolonomyRelationCount = 2`;
- compatibility projection of the first retained relation: rotation `0`, translation `(24,0)`, route 24, cut 2;
- the benchmark JSON does not serialize the full per-relation vector, so no unsupported component/sheet/topology-signature inventory is synthesized;
- `surfaceCellTraceSegmentCount = 670`;
- strands stage count 113;
- embedding stage count 113;
- arrangement stage is available and consumed but yields 0 cells;
- completion failure `SideSubdivisionRepair:InvalidInputIncidence`;
- no output mesh and therefore no output structural hash;
- no fallback attempt/use and no source-grid recovery.

Stage identities are deterministic 3/3, including tracing `0539b306563dbe25`, strands `618d7ed18d1f3daa`, embedded network `33d00772feecc2f7`, zero-cell arrangement `1ee6b9f9fd044d71`, and failed completion `b4efe5193b9e5c27`.

This is materially deeper than the old artifact, which rejected at phase-front with one partial relation and zero traces.

### Source-level classification of the new failure

Packaged-source inspection establishes the causal boundary:

1. `build_uniform_phase_front()` groups work by authoritative component/sheet.
2. Each local sheet tries uniform bounded phase-front construction and then periodic-annulus construction.
3. Successful local sheets append cells and canonical periodic relations to the aggregate.
4. If any later local sheet is `NotApplicable`, the function immediately returns the partially accumulated aggregate without setting `succeeded` or `Produced`.
5. The pipeline therefore does not call authoritative phase-front materialization for torus.
6. Generic tracing/FlowRep still advances, but its 113 embedded arcs form zero arrangement cells; the later completion-side incidence error is downstream of the earlier incomplete authoritative producer coverage.

Torus feature diagnostics also report 48 hard feature edges arranged in four closed feature curves. These barriers legitimately affect chart/sheet partitioning and must remain authoritative; the next implementation must not remove or geometrically weld them merely to force a torus result.

## Bounded suites

- producer excluding only long BunnyRandom/Vase design-acceptance cases: **105/106**;
- sole producer failure remains `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`, the same scheduler/environment-sensitive timing check;
- completion/simplification: **154/164**, exactly the same historical ten failures;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded aggregate: **327/338**.

The producer total increases by the five new passing G4 tests; no pre-existing semantic regression was introduced.

## Deferred observations

Per the authoritative plan, the prescribed sphere is not run after torus reveals a deeper producer/topology defect. Bunny/vase later-gate runs are also unnecessary for this G4 decision. Their prior observations retain only historical/later-gate status; no timeout or stale result is promoted to current correctness authority.

## G4 gate decision

**G4 remains active.** The multi-relation representation slice satisfies the material-progress condition because the scalar `InvalidPeriodicTopology` barrier is gone, two relations are retained and visible in deterministic structural diagnostics, 670 traces are produced, all G0-G3 authority is unchanged, and no fallback/recovery is used.

The next earliest design contract is not same-sheet basis selection and not completion repair. It is **complete authoritative phase-front coverage/composition across every source sheet on closed genus-one input**. Partial sheet success must never be silently treated as whole-surface production, but one unsupported local chart must also not discard already-proven authoritative periodic structure and force an opaque zero-cell generic arrangement path.

## Next authoritative turn

**Code + Build — G4 torus complete phase-front sheet coverage.**

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md`, whose contents are updated for the new earliest contract. The next implementation must preserve all current relation semantics and G0-G3 regressions while making the torus phase-front either fully `Produced` with complete sheet coverage/materialization or fail closed at the exact unsupported sheet with a typed producer reason. It must not mark partial coverage as produced, remove hard-feature barriers, choose authority by ID/order/count/frequency/proximity, or repair the downstream completion symptom first.

Local evidence archive: `directional-g4-holonomy-basis-artifact-only-evidence.tar.gz`, SHA-256 `6c8f20252d7a616924b388e5643dba994dd5b26cf610794c21e602029c352cb2`.
