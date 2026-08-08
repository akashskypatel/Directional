# Gate 4 Closed-Genus-One Source-Sheet Boundary Authority — Artifact-Only Test + Benchmark Report

Date: 2026-08-08 UTC  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

Exact artifact **`9019024467`** is runtime-valid and establishes **material G4 progress, but G4 remains active**.

The source-sheet boundary correction is runtime-live:

- new non-hard source-sheet-boundary semantics pass **3/3**;
- source-sheet-boundary + curved-disk semantics pass **9/9**;
- prior sheet-coverage semantics remain **3/3**;
- G4 periodic-relation semantics remain **5/5**;
- retained G0-G3 focused contracts remain **17/17**;
- direct plane, seam, close-sheets and cylinder authority remains exact and deterministic **3/3** with unchanged structural hashes and no fallback/recovery;
- exact torus advances beyond the prior `InvalidBoundedDiskTopology` source-sheet-boundary blocker and now deterministically rejects at `tracing/phase-front` as **`InvalidBoundedDiskBoundaryPhase`**;
- canonical periodic authority remains live before rejection;
- no generic tracing/arrangement/completion, fallback, legacy substitution, returned-input fallback, or source-grid recovery executes after the authoritative rejection.

This satisfies the plan's material-progress condition. Prescribed sphere remains deferred because torus does not yet reach authoritative materialization/direct strict-valid production.

## Exact artifact authority

Artifact:

- ID **`9019024467`**;
- name `g4-source-sheet-boundary-code-build`;
- workflow run/job **`31247546780 / 93078496378`**;
- event commit `ccb9aa0db15a575f31b802a354ccf8b0aabe111c`;
- implementation **`b425898fa7367406fa0c07e8f4441a37efc01315`**;
- payload cleanup **`3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`**;
- outer ZIP SHA-256 **`a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`**;
- internal `SHA256SUMS` SHA-256 **`7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`**;
- recursive checksums **48/48**;
- package **49 files / 27 fixtures / five executables / two project static libraries**;
- build log artifact `9019024673`, SHA-256 `243943268324a24e5fd04a42fed706b274a8525f5c2f157bf246b5028e42f03c`;
- metadata records raw transfer patch SHA-256 `c96b3d73f16f4b9391505380bc3f2cf9ec95ff5783fe843b556e95a534a6e75b`, `runtimeExecution=false`, review policy `never`.

Final packaged source blobs independently match:

| File | Git blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `ddb8e211f073d15fcfcc6782f964f88c4dedfc5e` |
| `src/geometry/SurfaceCellTracing.cpp` | `14cf7f3a3301e9e3f10ec48a480d3f6e5efee7ed` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `31322acea5227a8e3692887fad1ec4a9e6d8c101` |

Submodule authority remains Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, and polyscope `59da72df6517cab8379865899bdffdbc96171301`.

Validation ran from the immutable packaged binaries on Linux x86_64 (AMD EPYC 9V74 runner allocation). This turn performed **no configure, compile, link, rebuild, discovery regeneration, production edit, test edit, fixture edit, validator edit, benchmark edit, or build-system edit**.

The packaged tests retain an Actions absolute fixture path. The allowed runtime-only symlink was created without changing artifact bytes:

`/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_boundary_runtime_9019024467/test-data/benchmarks/fixtures`

An initial focused attempt before this symlink produced only missing-fixture-path failures in the two fixture-backed cases. After the symlink, the exact immutable cases pass. This is environment path compatibility, not a product regression or test edit.

Local evidence archive: `directional-g4-source-sheet-boundary-artifact-only-evidence.tar.gz`, SHA-256 **`27b4d62c6bde5f21475ddd31a42a10c02ffbad379931fd1b728c0506a6287030`**.

## Source-sheet boundary semantics — 3/3

All new behavioral cases pass:

1. `SurfaceCellsPhase10.CurvedBoundedDiskAcceptsNonHardAuthoritativeSourceSheetBoundary`;
2. `SurfaceCellsPhase10.CurvedBoundedDiskRejectsHiddenSameSheetBoundaryCut`;
3. `SurfaceCellsPhase10.CurvedBoundedDiskCrossSheetBoundaryIsInvariantToFaceRowEnumeration`.

The positive and negative controls use the same physical internal source edge. Different authoritative source component/sheet labels make the edge a valid local boundary; compatible same-sheet labels keep the same edge an invalid hidden cut. Hard-feature authority is not modified. Row re-enumeration preserves the produced structural geometry.

## Curved-disk and prior focused authority

The six curved-disk/producer cases pass **6/6**:

- `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`;
- `CurvedBoundedDiskIsInvariantToFaceRowEnumeration`;
- `CurvedBoundedDiskPreservesAuthoritativeHardBoundary`;
- `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`;
- `ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`.

Combined with the three new cases, the active source-sheet-boundary + curved-disk group is **9/9**.

Retained authority:

- source-sheet coverage **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**.

No retained authority regressed.

## Direct G0-G3 regression matrix — deterministic 3/3

All runs use direct `SurfaceCells`, manifest fallback `Fail`, source-grid recovery disabled, warmup 0, and one measured run per independent process.

| Fixture | Required output | Hash | Wall seconds, three processes | Peak working set |
|---|---|---|---|---|
| plane | 64 quads / 81 V | `730caeae49ec872c` | `0.343766 / 0.342932 / 0.346420` | 9.47–9.65 MB |
| multi-face seam | 64 quads / 81 V | `5bdf34d7802e9fb0` | `0.535557 / 0.521374 / 0.524785` | 9.44–9.69 MB |
| close sheets | 200 quads / 242 V / two components | `89b052762f52a5af` | `2.967128 / 2.987092 / 2.936499` | 11.85–12.14 MB |
| cylinder | 288 pure quads / 320 V | `32135be51d7a0a26` | `2.728982 / 3.893863 / 9.316281` | 13.18–13.23 MB |

Every process reports `Produced / CompletedSurfaceCells`, zero strict-validation failures, no fallback attempt/use, and no source-grid recovery.

Structural counts remain exact:

- plane: 352 traces, 65 arrangement/simplified cells, 64 completed quads;
- seam: 256 traces, 65 arrangement/simplified cells, 64 completed quads;
- close sheets: 1,104 traces, 202 arrangement/simplified cells, 200 completed quads and two components;
- cylinder: 1,728 traces, 290 arrangement/simplified cells, 288 completed quads.

Cylinder retains one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4. Independent output-topology inspection finds 64 exterior boundary edges forming exactly **two degree-2 loops of 32 vertices each**. The artificial periodic cut remains non-exterior.

The third cylinder wall-time sample is slower than the other two, but output, structural counts, periodic authority, validation and hash are identical. It is recorded as runtime variance, not correctness drift.

## Exact torus — deeper typed boundary-phase failure, deterministic 3/3

Three independent direct processes produce identical structural behavior:

| Run | Internal wall | Peak working set | Producer | First invalid reason |
|---|---:|---:|---|---|
| 1 | `0.028484 s` | `8,740,864 B` | `Rejected` | `InvalidBoundedDiskBoundaryPhase` |
| 2 | `0.017677 s` | `8,663,040 B` | `Rejected` | `InvalidBoundedDiskBoundaryPhase` |
| 3 | `0.017229 s` | `8,675,328 B` | `Rejected` | `InvalidBoundedDiskBoundaryPhase` |

Common diagnostics:

- first invalid stage `tracing/phase-front`;
- first invalid source face `-1`;
- periodic relation count reached before rejection **2**;
- compatibility periodic authority remains available: `r=0`, `t=(24,0)`, route 24, cut 2;
- traces 0;
- arrangement 0;
- simplified cells 0;
- completed quads 0;
- output origin `None`;
- terminal backend state remains `NotProductionReady:tracing`;
- fallback attempted false;
- legacy fallback false;
- returned-input fallback false;
- source-grid recovery false.

Stage identities are stable in all three runs:

- feature `f15e4f3be07d3c7f`, count 216;
- metric `34cb872327c9b0c6`, count 72;
- relief `8ccb10d25b69edb9`, count 58;
- source labels `e48c84177faf6e2c`, count 144;
- tracing `e9b7fe2146bd7895`, count 0.

Feature authority still reports four adaptive feature curves. The previous runtime record's 48 hard-feature edges remain source-derived authority; neither this implementation nor this test turn demotes them.

The benchmark JSON exposes the relation count and one compatibility projection, but does not serialize every retained relation. Per-relation runtime values are therefore **not claimed** beyond what the existing diagnostics expose.

## New blocker diagnosis — field-authoritative disk boundary phase

The non-hard cross-sheet boundary contract is now proven live. Immutable packaged source shows the next curved-disk stage:

1. classifies each ordered local boundary edge against transported 4-RoSy branches;
2. rejects an ambiguous/weak edge classification below the existing alignment requirement;
3. starts a boundary run whenever the selected branch changes;
4. globally requires exactly **four** runs;
5. canonicalizes the first run geometrically;
6. requires the cyclic run sequence to be the rectangular `U+`, `V+`, `U-`, `V-` pattern;
7. maps those four runs to a rectangle before harmonic chart construction.

The exact torus reports `firstInvalidFace=-1`. The per-edge boundary-alignment rejection paths attach a source face, while the global run-count/canonical-order failures do not. Therefore the evidence narrows the failure to a **global rectangular boundary-phase invariant**, but current diagnostics do not expose which global check fired. Do **not** infer an unobserved run count or branch sequence.

The defect is not that a threshold is too strict. The missing design contract is broader: a valid source-authoritative curved disk can have a field-compatible boundary whose ordered branch/corner structure is not representable as one four-sided rectangle. G4 therefore needs first-class ordered field-authoritative disk boundary phase and a generalized intrinsic polygonal/singularity-compatible disk chart.

The next implementation must not:

- simply change `runStarts.size() != 4` into acceptance;
- merge/split runs arbitrarily to manufacture four sides;
- reduce the existing alignment threshold merely to make the torus pass;
- demote hard/source-sheet rails;
- choose corners/runs by raw IDs, frequency, count, discovery order, or proximity;
- relabel the same failure as `InvalidBoundedDiskChart` without consuming a real generalized boundary representation;
- use post-hoc cell merging or geometric welding.

## Bounded suites

Producer suite, excluding only the documented long BunnyRandom and Vase design-acceptance parameter cases:

- **115/116** pass;
- the sole failure remains `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- observed validation time `0.000114581 s` versus threshold `0.00007840425 s`;
- classification remains the existing sub-millisecond performance threshold, not a G4 semantic regression.

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

Validation remains **60/60**. Compiled API remains **8/8**. New bounded aggregate is **337/348**. The three added producer tests account for the net cardinality increase; the semantic failure set is otherwise unchanged.

## G4 decision

**G4 remains active.** Artifact `9019024467` establishes material progress because:

- non-hard authoritative source-sheet boundary semantics are runtime-proven;
- the exact torus advances past the prior `InvalidBoundedDiskTopology` boundary-authority blocker;
- the new failure is a deeper deterministic typed boundary-phase invariant;
- periodic authority remains live;
- all prior focused/direct authority remains intact;
- no generic/fallback/recovery path substitutes for producer authority.

Prescribed sphere remains deferred until torus reaches complete authoritative materialization/direct strict-valid production. Bunny/vase remain later G6 production gates. Timeout is never used as correctness evidence.

## Next authoritative turn

**Code + Build — G4 field-authoritative polygonal disk boundary phase.**

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Plan.md`.

The implementation must make ordered field-authoritative boundary runs/corners first-class, preserve the existing rectangular fast path exactly, and support a generalized field-compatible polygonal/singularity-aware disk boundary/chart without arbitrary run coercion. The following artifact-only turn must prove exact torus advances beyond `InvalidBoundedDiskBoundaryPhase` to `Produced`/materialization or the next genuinely deeper typed chart/front-pairing invariant while retaining all existing focused/direct authority.
