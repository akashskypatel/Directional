# Gate 3 Periodic Cylinder / Holonomy — Artifact-Only Test + Benchmark Report

## Decision

**G3 remains active, with material progress.**

The exact production cylinder no longer falls through `NotApplicable` to the generic producer. The G3 artifact reaches authoritative `Produced`, carries first-class periodic holonomy, materializes 290 direct quads with 319 provenance vertices, and is deterministic across three independent processes. It then fails the pre-optimization completed-mesh validation checkpoint with two aggregate validation failures. Therefore G3 does not close yet.

A separate focused row-enumeration test fails because it compares raw DCEL `sourceEdge` integer IDs across a face-row reversal. Those IDs are row-enumeration-dependent; mapping them through each mesh's EV table yields identical ordered canonical endpoint routes and cuts. This failure is an **incorrect test expectation**, not production nondeterminism.

No source, test, fixture, manifest, validator, benchmark, or build logic was edited in this Test + Benchmark turn.

## Artifact integrity

Exact authority:

- build artifact ID: `9001168379` (`g3-periodic-cylinder-code-build`)
- outer SHA-256: `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`
- source commit: `56f823273cad041a01ebb4d0772c3265ff248f4a`
- build run/job: `31196268841` / `92925122791`
- detailed log artifact ID: `9001167184`
- log artifact SHA-256: `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`
- source patch SHA-256: `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`
- recursive checksums: **44/44 passed**
- packaged closure: five executables, two project libraries, 27 fixture/input files
- packaged command boundary: `runtimeExecution=false`

Verified changed Git blobs:

- `include/directional/geometry/SurfaceCellTracing.h` → `931669018a986096cf78d66a2aed9de5aa8e0fe1`
- `include/directional/diagnostics/RemeshDiagnostics.h` → `a51215982318e77581efa4fa7887d0406a9d4bf0`
- `src/geometry/SurfaceCellTracing.cpp` → `b1a2c6d4051cc17b79e342170285d69552cad16d`
- `src/pipeline/RemeshPipeline.cpp` → `7674ed3fe40c5f43c668c931c01b59f6c7829df8`
- `src/bench/DirectionalBenchmark.cpp` → `18955ca8ef72812c9c70ed522bb578409e6a176f`
- `tests/SurfaceCellsPhase10Tests.cpp` → `bccd6abf3e31b8096c471c515b1949d08dcfde59`

Exact cylinder fixture hashes:

- `cylinder.obj` → `59ed6d736410dbef6bc751136ba0eb1d557a43c9df63fb2a570daf85c79419ae`
- `cylinder.rawfield` → `6e861e06fa5d3dd6ed84c48bf7d459df701acd7f6ab241cc2adbde66d829084d`

A runtime-only fixture symlink was used to expose immutable packaged fixture paths expected by the compiled tests. No packaged file bytes changed.

## Focused G3 and retained producer contracts

Twelve focused/retained contracts were executed first.

**11/12 passed.**

Passed:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`
2. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`
3. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`
4. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`
5. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
6. `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`
7. `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`
8. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`
9. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`
10. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`
11. `SurfaceCellsPhase10.UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded`

Failed:

- `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`

### Row-enumeration failure classification

The failed assertions compare raw `periodicHolonomy.sourceRouteEdges` and `cutSourceEdges` integer IDs.

`populate_cross_field_edge_transitions()` assigns `transition.sourceEdge = edge`, where `edge` is the `TriMesh` DCEL edge index. `DCEL::init()` assigns those edge indices by first halfedge encounter while walking face rows. Reversing face rows therefore legitimately renumbers edge IDs.

The observed raw values differ, but converting each edge ID to its canonical unordered source-vertex endpoints proves semantic invariance:

- both 32-edge holonomy routes map to the same ordered endpoint sequence;
- both four-edge cuts map to exactly `(0,2) → (2,32) → (32,48) → (48,64)`;
- grid dimensions and holonomy rotation/translation already compare equal in the test.

Classification: **incorrect expectation**. The intended G3 contract explicitly permits canonical renumbering. The next Code + Build turn should replace raw ID equality with canonical endpoint-route equality; this strengthens the semantic test rather than weakening it.

## Direct acceptance matrix

All cases used the packaged manifest, requested `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled.

| Fixture | Result | Producer | Holonomy | Traces | Arrangement | Completed quads | Provenance vertices | Validation failures | Output |
|---|---:|---|---|---:|---:|---:|---:|---:|---|
| plane | **pass** | `Produced` | none | 352 | 65 | 64 | 81 | 0 | `CompletedSurfaceCells`, hash `730caeae49ec872c` |
| multi-face seam | **pass** | `Produced` | none | 256 | 65 | 64 | 81 | 0 | `CompletedSurfaceCells`, hash `5bdf34d7802e9fb0` |
| close sheets | **pass** | `Produced` | none | 1,104 | 202 | 200 | 242 | 0 | `CompletedSurfaceCells`, hash `89b052762f52a5af` |
| cylinder | **fail** | `Produced` | `r=0, t=(29,0), route=32, cut=4` | 2,163 | 0 | 290 | 319 | 2 | `NotProductionReady:completion` |
| bunny | fail/later gate | `NotApplicable` | none | 80,862 | 0 | 0 | — | — | `NotProductionReady:completion` |
| vase | fail/later gate | `NotApplicable` | none | 116,922 | 0 | 0 | — | — | `NotProductionReady:completion` |

No direct case used fallback or source-grid recovery.

### Cylinder material progress

This artifact materially advances G3 relative to the previous tested authority:

- previous cylinder: `NotApplicable`, 732 generic traces, zero arrangement/completion;
- current cylinder: authoritative `Produced`;
- periodic holonomy available;
- quarter-turn rotation `0`;
- integral periodic translation `(29,0)`;
- non-empty ordered source route: 32 edges;
- non-empty source cut: four edges;
- 2,163 source-attached trace segments;
- 290 completed direct quads;
- 319 provenance vertices;
- no fallback/recovery.

The current terminal failure is deterministic:

- terminal `NotProductionReady:completion`;
- first invalid producer stage `completion/output-validation`;
- reason `AggregateCompletionValidationFailure`;
- exactly **2** validation failures;
- output origin remains `None` because the completed checkpoint is rejected before optimization/final output.

The benchmark serialization does not expose the two individual `SurfaceFinalValidationReport` threshold fields. `strictValidationIssues` are not surfaced through the benchmark record, and the first-invalid reason is aggregate. Do not infer a specific validator threshold as proven evidence.

### Bounded source-level diagnosis for next implementation

The current periodic chart chooses `gridU = round(period / target)` globally. On the committed cylinder this yields 29 periodic columns while the canonical source ring has 16 source edges. `build_authoritative_phase_front_mesh()` then materializes every accepted cell as one straight quad from its corner positions and quotients only the periodic duplicate lattice column. Thus the periodic lattice is not required to retain canonical source-strip breakpoints before direct materialization.

This is a concrete general risk on curved annular source topology: a straight output side may span a source topological corner even though the phase-front side carries a source route. The next Code + Build turn should make periodic lattice/materialization source-strip-conforming rather than relax validation. The exact two failed validation thresholds remain to be confirmed from the in-memory validation report during implementation; diagnostics must not become the principal objective.

## Determinism

Current artifact, three independent processes each:

- plane: deterministic 3/3; output hash `730caeae49ec872c`;
- seam: deterministic 3/3; output hash `5bdf34d7802e9fb0`;
- close sheets: deterministic 3/3; output hash `89b052762f52a5af`;
- cylinder: deterministic 3/3 failure signature.

Cylinder is stable across all three runs for:

- `Produced` disposition;
- holonomy `(rotation=0, translation=(29,0), routeEdgeCount=32, cutEdgeCount=4)`;
- 2,163 traces;
- zero generic arrangement cells;
- 290 completed quads;
- 319 provenance vertices;
- two validation failures;
- `completion/output-validation:AggregateCompletionValidationFailure`;
- every recorded stage structural hash through completion.

Cylinder wall times were approximately 0.92–1.06 s.

Bunny completed one required bounded observation in 28.61 s. Vase completed one required bounded observation in 51.93 s. No second later-gate repetition was necessary for the G3 decision.

## Default suites

Full packaged producer executable:

- **93/98 passed**;
- five failures:
  - scheduler-sensitive `StrictValidatorOverheadStaysBelowFivePercent`;
  - the incorrect raw-edge-ID row-order expectation described above;
  - cylinder direct design acceptance;
  - bunny direct design acceptance;
  - vase direct design acceptance.

Excluding the 12 explicitly executed focused/retained contracts gives the non-overlapping remaining producer result:

- **82/86 passed**;
- failures are the known timing closeout check plus cylinder/bunny/vase design acceptance.

Other suites:

- completion/simplification: **154/164 passed** — same ten deferred historical failures;
- validation: **60/60 passed**;
- compiled API: **8/8 passed**.

The non-overlapping total including the 12 focused/retained contracts is **315/330 passed**.

The scheduler timing ratio remains performance/closeout evidence and cannot override direct functional results. Bunny/vase remain later production gates. The ten completion/simplification failures remain deferred until the ordered design gate reaches them.

## G3 decision

**G3 is incomplete but materially advanced.**

The missing periodic authority is now live and consumed by the exact production cylinder. The remaining active failure is no longer applicability, generic tracing, or periodic holonomy construction; it is the direct periodic completed mesh failing the source-authoritative completed-checkpoint validation.

Passed G0–G2 gates remain green.

## Authoritative next Code + Build declaration

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: a Produced periodic phase-front must materialize its cut-quotiented annular cells into a source-authoritative completed quad mesh that passes the existing pre-optimization validation without shortcutting canonical source-strip structure; row-order invariance must be compared in canonical source identity rather than DCEL edge numbering
Smallest general implementation change: preserve canonical annulus source-strip breakpoints in periodic lattice/materialization, choosing deterministic per-strip subdivisions nearest the target size so output sides do not bridge source topological corners, while retaining exact periodic holonomy quotient and one accepted cell -> one quad; separately correct the row-order contract test to compare ordered canonical source-edge endpoint keys instead of raw sourceEdge IDs
Observable material-progress condition: exact cylinder remains Produced with the same valid periodic authority and reaches zero completed-checkpoint validation failures/direct CompletedSurfaceCells output, while plane, seam, and close sheets remain strict-valid deterministic regressions; the row-order test passes by canonical endpoint identity without weakening its holonomy invariants
Explicitly deferred work: torus/general genus, singularity topology and G4 completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, scheduler timing, and unrelated historical completion/simplification failures
```

### Next-turn constraints

- Do not relax the validator or any quality threshold.
- Do not fall back from `Produced`/`Rejected` to generic tracing.
- Do not use Euclidean seam welding or nearest-point periodic pairing.
- Do not special-case `cylinder.obj`, 16 segments, 29 columns, fixture names, or expected counts.
- Derive source-strip breakpoints and subdivision compatibility from the canonical annulus topology and target-size field.
- Preserve exact periodic holonomy and artificial-cut ownership.
- Keep one accepted phase-front cell → one quad.
- Correct only the structurally invalid raw-ID row-order assertion; preserve the semantic endpoint-route, cut, grid, and holonomy checks.
- Code + Build only: compile the required targets and tests, execute no generated project binary.
- Package the exact next artifact for another artifact-only G3 Test + Benchmark turn.

Optional review is not requested (`review_policy=never`); this next Code + Build plan is authoritative.
