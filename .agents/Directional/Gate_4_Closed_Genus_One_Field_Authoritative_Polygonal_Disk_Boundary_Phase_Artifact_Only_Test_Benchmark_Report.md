# Gate 4 Field-Authoritative Polygonal Disk Boundary Phase — Artifact-Only Test + Benchmark Report

Date: 2026-08-08 UTC  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

Exact artifact **`9021175280`** (`g4-polygonal-boundary-phase-code-build`) is runtime-valid, but the planned exact-torus material-progress condition is **not satisfied**. G4 remains active.

The generalized polygonal boundary-phase implementation is genuine and works on its structural focused witnesses: the five new boundary-phase cases pass **5/5**, including the natural six-run reflex-corner disk, invalid-turn rejection, row-order invariance, rectangular fast-path retention, and mixed periodic composition without partial cells.

However, exact torus does **not** retain or consume a first-class bounded-disk phase. Three independent direct processes stop deterministically at **`InvalidBoundedDiskBoundaryTurn`** with boundary-phase count, run count, polygonal-phase count, constructed-chart count, and phase hashes all zero. A changed failure reason without retained phase/chart authority is not material progress under the controlling plan.

Read-only structural reconstruction identifies the higher-level domain-partition mistake: the current `sourceFaceSheets` classifier labels are local close/opposing-sheet **isolation labels**, but producer topology currently treats every non-hard cross-sheet classifier edge as an exterior bounded-disk rail. On the torus, two classifier-local disk labels reconstruct one exact source-adjacent annular hard-feature region when their non-hard classifier cuts are restored. The new turn validator is therefore correctly rejecting an artificial disk corner; relaxing quarter-turn/index checks would be the wrong correction.

The next Code + Build target is to decouple **source-topological producer regions** from **local isolation sheets** while preserving both authorities.

No production/test/fixture/validator/benchmark/build-system edit, configure, compile, link, rebuild, discovery regeneration, or replacement artifact occurred in this turn.

## Exact artifact authority

- artifact ID **`9021175280`**;
- name `g4-polygonal-boundary-phase-code-build`;
- workflow run/job **`31254896323 / 93096734152`**;
- workflow event commit `c24af6c83ab25397df1c2bfc4692b91689502f85`;
- implementation **`085db9ec23ffaa509b1f5a29e72968229efa103d`**;
- payload cleanup **`c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`**;
- outer ZIP SHA-256 **`16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`**;
- internal `SHA256SUMS` SHA-256 **`a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`**;
- recursive checksums **48/48**;
- package **49 files / 27 fixtures / five executables / two project static libraries**;
- log artifact `9021175444`, SHA-256 `170c8d869af4ec737250a1a5ce7dfb532ca76fbef972a696cea85a53c61b0f67`;
- metadata records `runtimeExecution=false`, review policy `never`.

Final packaged source blobs match exactly:

| File | Git blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `9597c49693a1146e5dac2ac90270348b55a0c91d` |
| `include/directional/geometry/SurfaceCellTracing.h` | `0c1daa94300121df40c923716314ae6b242c7e8c` |
| `src/bench/DirectionalBenchmark.cpp` | `fd74cd39fff73bee7b4db578eb08382bd6ef50cf` |
| `src/geometry/SurfaceCellTracing.cpp` | `c834e8c81db04c39af9ecf1f45044ea107de3291` |
| `src/pipeline/RemeshPipeline.cpp` | `945bbc58bc56cb9838532889c616520cb234aaa3` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `981b0f6e6fc935c1bfe3d1f6871736035d6bdfcb` |

Submodule authority remains Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, and polyscope `59da72df6517cab8379865899bdffdbc96171301`.

The packaged tests retain an Actions absolute fixture path. Artifact bytes were unchanged; validation used the recorded runtime-only symlink:

`/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_polygonal_runtime_9021175280/test-data/benchmarks/fixtures`

Local evidence archive: `directional-g4-polygonal-boundary-phase-artifact-only-evidence.tar.gz`, SHA-256 **`3da110e6b8f4a0ef4759cacbcb5da109b65b85cb62607dcde4955e8203346f9b`**.

## New polygonal boundary-phase semantics — 5/5

All five newly added focused cases pass:

1. `ExistingRectangularCurvedDiskRetainsExactBoundaryPhaseFastPath`;
2. `PolygonalCurvedDiskBuildsFieldAuthoritativeSixRunPhaseAndChart`;
3. `PolygonalCurvedDiskInvalidCyclicFieldTurnFailsClosed`;
4. `PolygonalCurvedDiskBoundaryPhaseIsInvariantToFaceRowEnumeration`;
5. `PolygonalCurvedDiskRetainsPeriodicAuthorityWithoutPartialSheetCells`.

This proves the implementation is not merely relabeling the former four-run rejection: a natural non-rectangular orthogonal disk develops a first-class six-run phase and chart, an invalid reciprocal turn remains typed and fail-closed, row re-enumeration preserves structural authority, and mixed periodic authority is retained without promoting partial cells.

## Retained focused authority

Source-sheet-boundary semantics remain **3/3**. The five non-torus retained curved-disk cases remain **5/5**. The strengthened exact-torus advancement contract fails because production stops at `InvalidBoundedDiskBoundaryTurn` before any first-class phase record is retained. The combined retained source-sheet/curved group is therefore **8/9** for this artifact.

Other retained groups remain exact:

- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**.

## Direct G0-G3 regression matrix — deterministic 3/3

All direct cases use `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, strict validation, and three independent processes.

| Fixture | Direct result | Structural output | Exact hash | Wall seconds |
|---|---|---|---|---|
| plane | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `730caeae49ec872c` | `0.367643 / 0.361801 / 0.348645` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `5bdf34d7802e9fb0` | `0.529079 / 0.523516 / 0.517678` |
| close sheets | `Produced / CompletedSurfaceCells` | 200 quads / 242 V / 2 components | `89b052762f52a5af` | `2.999163 / 2.972470 / 2.976543` |
| cylinder | `Produced / CompletedSurfaceCells` | 288 pure quads / 320 V | `32135be51d7a0a26` | `2.728804 / 2.688510 / 2.714259` |

Peak RSS ranges are 9.70–9.85 MB for plane, 9.46–9.65 MB for seam, 11.87–12.15 MB for close sheets, and 13.32–13.46 MB for cylinder.

Structural counts remain unchanged: plane 352 traces / 65 arrangement/simplified / 64 completed; seam 256 / 65 / 64; close sheets 1,104 / 202 / 200; cylinder 1,728 / 290 / 288. Every direct process has zero validation failures and no fallback/recovery.

Cylinder retains one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4. Independent output-topology inspection finds 64 exterior boundary edges forming exactly two degree-2 32-vertex loops; the artificial periodic cut remains non-exterior.

## Exact torus — deterministic typed turn failure, 3/3

All three independent processes report:

- success `false`;
- authoritative producer `Rejected`;
- first invalid stage `tracing/phase-front`;
- reason **`InvalidBoundedDiskBoundaryTurn`**;
- first invalid face `-1`;
- diagnostic source vertex `32`;
- bounded-disk phase count **0**;
- bounded-disk run count **0**;
- polygonal phase count **0**;
- constructed-chart count **0**;
- phase hashes **empty**;
- periodic relation count 2 before rejection; compatibility serialization remains `r=0`, `t=(24,0)`, route 24, cut 2;
- traces / arrangement / simplified / completed output all 0;
- output origin `None`;
- fallback attempted false, legacy fallback false, returned-input fallback false, source-grid recovery false.

Wall times are `0.008934 / 0.009836 / 0.008955 s`; peak RSS is `8,749,056 / 8,814,592 / 8,671,232 B`.

Stable stage identities:

- feature `f15e4f3be07d3c7f`, count 216;
- metric `34cb872327c9b0c6`, count 72;
- relief `8ccb10d25b69edb9`, count 58;
- source labels `e48c84177faf6e2c`, count 144;
- tracing `3425d60a62a47da5`, count 0.

Feature diagnostics remain 48 hard edges and four closed feature curves. The observed source vertex, sheet counts, edge counts, relation count, and analytical fixture parameterization below are diagnosis only and must never become production/test ownership or acceptance keys.

## Structural diagnosis — topology region is not isolation sheet

Read-only reconstruction used the immutable packaged torus source, field, classifier policy, and feature-map rules. It did not modify artifact bytes or production logic.

The source classifier uses local geometric isolation policy (`traverseUnmarkedSharpBends=true`, normal compatibility `0.25`, close-sheet radius `2.5` mean edges, geodesic exclusion depth `2`). Reconstructed authority matches runtime feature diagnostics: 48 hard edges in four closed feature rings.

The classifier yields five local isolation sheets. Three are annuli. Two labels are individual disks, but their exact source-adjacent union has Euler characteristic 0 and two genuine boundary loops: together they reconstruct **one annular hard-feature band**. Their separation consists entirely of non-hard exact source edges introduced by close/opposing-sheet isolation, not by a true source boundary or hard feature.

At the runtime-reported diagnostic vertex, the artificial local-disk boundary meets a true hard-feature ring at a geometric angle of approximately `138.42°`. Treating that classifier seam as an exterior field-aligned polygon side produces the typed invalid transported boundary turn. The turn validator is therefore exposing an upstream producer-domain partition error; allowing a 180-degree branch change, relaxing alignment, or fabricating boundary closure would be incorrect.

The corrected architectural distinction is:

- **topology region**: exact source-adjacent producer domain, split only by true topological/barrier authority such as hard features and genuine source boundaries;
- **local isolation sheet**: geometric/proximity partition used to prevent nearby unrelated surface capture/projection;
- an exact shared non-hard edge crossing local sheet labels is an **internal isolation seam** within a topology region when exact source adjacency and reciprocal transport prove continuity;
- local sheet identity remains mandatory for proximity/capture/projection isolation and provenance;
- hard-feature/source-boundary authority remains unchanged;
- unrelated close sheets/components remain disconnected; no Euclidean or positional merge is permitted.

## Bounded suites

Producer suite excluding only the documented deliberately long BunnyRandom/Vase design-acceptance parameter cases: **119/121**.

Failures:

1. existing `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`: validation `0.000116814 s` vs threshold `0.000078967100000000012 s`, the same sub-millisecond performance-threshold class;
2. strengthened `SurfaceCellsPhase10.ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`: correctly exposes this artifact's `InvalidBoundedDiskBoundaryTurn` and zero phase evidence.

Completion/simplification remains **154/164** with the exact same ten historical failures. Validation remains **60/60**. Compiled API remains **8/8**. Aggregate is **341/353**.

## G4 decision and next turn

**G4 remains active. Planned material progress for artifact `9021175280` is not achieved.** The synthetic generalized boundary representation is real and validated, but exact torus fails before it retains/consumes that representation. The no-progress Code + Build count since the last runtime-proven material advancement is therefore **1**.

Prescribed sphere remains deferred. G5 adaptivity/features, G6 bunny/vase production, historical completion/simplification repair, validator-threshold changes, fallback/recovery, and unrelated optimization remain deferred.

Next authoritative turn: **Code + Build — source-topology-region / isolation-sheet decoupling**, using `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md`.

If the next Code + Build also fails to produce material runtime progress in its following Test + Benchmark turn, the process rule requires mandatory design review or a bounded producer-replacement proof before another ordinary Code + Build iteration.