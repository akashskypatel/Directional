# Gate 2 Close-Sheet Authoritative Producer — Artifact-Only Test + Benchmark Report

## Result

**G2 cross-chart / close-sheet isolation is closed.**

Artifact `8994541137` directly produces the exact production close-sheet fixture as two deterministic, source-isolated pure-quad components while preserving the already-passed plane and multi-face seam regressions. No configure, compile, relink, discovery regeneration, or source/test/fixture/validator/benchmark/build edit occurred during this Test + Benchmark turn.

## Exact tested authority

- source commit: `218dd3ec3f6399dc82183390720a4ba4d3a70b42`
- artifact: `8994541137` (`g2-close-sheet-code-build`)
- artifact SHA-256: `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`
- build run/job: `31179899458` / `92870408341`
- internal checksums: **45/45 passed**
- packaged closure: five executables, two project libraries, 27 fixture/input files
- changed blobs verified from packaged source:
  - `src/geometry/SurfaceCellTracing.cpp`: `c9570ecb4a9557eebaf0e30b751e2ccca90b2973`
  - `src/pipeline/RemeshPipeline.cpp`: `55af3205fd7cdb8f21357ac69516ffa29cf8a6d3`
  - `tests/SurfaceCellsPhase10Tests.cpp`: `7151077d7d4e0a10dad388dd008479f96fc1aae8`
- packaged Code + Build command boundary: `runtimeExecution=false`

A runtime-only `bin/test-data -> ../test-data` symlink exposed the immutable packaged fixtures at the path expected by the compiled tests. No packaged byte changed.

## Focused producer contracts

All seven focused prerequisites passed:

1. `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`
2. `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`
3. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
4. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`
5. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`
6. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`
7. `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`

Result: **7/7 passed**.

The close-sheet isolation contract directly verified both source keys `{(0,0), (1,1)}` in the authoritative phase front and verified that every twinned front edge has the same source component and local-sheet identity on both sides. The row-order contract reproduced the same phase-front cell/edge/event cardinalities after reversing source-face enumeration.

## Direct acceptance

All direct cases used `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled.

| Fixture | Result | Disposition | Traces | Arrangement | Quads | Vertices | Components | Validation | Output hash |
|---|---:|---|---:|---:|---:|---:|---:|---:|---|
| Plane | **pass** | `Produced` | 352 | 65 | 64 | 81 | 1 | 0 failures | `730caeae49ec872c` |
| Multi-face seam | **pass** | `Produced` | 256 | 65 | 64 | 81 | 1 | 0 failures | `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | 1,104 | 202 | 200 | 242 | 2 | 0 failures | `89b052762f52a5af` |
| Cylinder | fail / later gate | `NotApplicable` | 732 | 0 | 0 | 0 | — | no output validation | — |
| Random bunny | fail / later gate | `NotApplicable` | 80,862 | 0 | 0 | 0 | — | no output validation | — |
| Vase | fail / later gate | `NotApplicable` | 116,922 | 0 | 0 | 0 | — | no output validation | — |

Direct acceptance therefore advances from the prior **2/6** to **3/6**; the newly passing fixture is the active G2 case.

### Close-sheet acceptance details

The exact production close-sheet run satisfies the Gate 2 acceptance contract:

- authoritative producer disposition `Produced`
- terminal failure `None`
- output origin `CompletedSurfaceCells`
- 200 pure quads / zero non-quads
- 242 provenance/output vertices
- two connected output components
- zero strict source-authoritative validation failures
- no non-manifold edges, T-junctions, duplicate faces, or self-intersections
- topology and boundary preservation both true
- no fallback attempt/use
- source-grid recovery disabled/unused
- deterministic output hash `89b052762f52a5af`

The output has exactly two disconnected 121-vertex components. Their bounding layers are `z=-0.035` and `z=+0.035`, respectively; there is no cross-sheet connectivity despite the sheets occupying the same XY footprint.

Combined with the focused front-ownership contract, this provides direct evidence that unrelated spatially close sheets do not share front twins or output connectivity.

### Plane regression

Plane remains exactly stable across three independent processes:

- `Produced`
- 352 traces
- 65 arrangement cells
- 64 pure quads
- 81 vertices
- zero validation failures
- output hash `730caeae49ec872c`

### Multi-face seam regression

The seam remains direct, strict-valid, and deterministic across three independent processes:

- `Produced`
- 256 traces
- 65 arrangement cells
- 64 pure quads
- 81 vertices
- zero validation failures
- output hash `5bdf34d7802e9fb0`

The prior Gate 1 artifact reported hash `a8972efd7c4900a4`. A direct baseline comparison shows the current seam vertex set is geometrically equivalent within a symmetric Hausdorff distance of approximately `2.065e-9`; topology/face counts and all strict quality checks remain valid. The current hash is stable 3/3 and is the new tested authority.

## Determinism

- plane: **3/3** identical disposition/counts/hash
- seam: **3/3** identical disposition/counts/hash
- close sheets: **3/3** identical disposition/counts/hash
- cylinder: **3/3** identical `NotApplicable`, 732 traces, zero arrangement/completion

Measured wall times:

- plane: 0.343–0.357 s
- seam: 0.533–0.546 s
- close sheets: 3.005–3.152 s
- cylinder: 0.146–0.148 s

Later production observations:

- random bunny: failure observation, 23.409 s, 247,545,856 B peak RSS, 80,862 traces, `NotApplicable`, zero arrangement/completion
- vase: failure observation, 52.096 s, 141,316,096 B peak RSS, 116,922 traces, `NotApplicable`, zero arrangement/completion

Neither later failure affects G2 closure.

## Default suites

The producer executable was run with the seven focused tests excluded:

- remaining producer tests: **82/86 passed**
  - expected later-gate failures: cylinder, random bunny, vase design-acceptance cases
  - scheduler-sensitive `StrictValidatorOverheadStaysBelowFivePercent` also failed
- completion/simplification: **154/164 passed**; same ten deferred downstream failures
- validation: **60/60 passed**
- compiled API: **8/8 passed**

Including the seven focused contracts, the non-overlapping test total is **311/325 passed**. Aggregate totals do not supersede ordered direct gates.

## Gate decision

**G2 is closed.**

The next authoritative implementation turn is **Code + Build for G3 periodic cylinder / holonomy**. It must extend the authoritative phase/front producer to a bounded singularity-free annulus/cylinder domain using intrinsic source-topology transport, a deterministic cut/unwrapped chart, explicit periodic lattice holonomy, and source-authoritative periodic front identification. It must not broaden into torus/singularity/adaptivity work and must execute no generated project binary during the Code + Build turn.
