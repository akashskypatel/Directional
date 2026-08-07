# Gate 2 Close-Sheet Authoritative Producer — Artifact-Only Test + Benchmark Report

## Result

**G2 is closed.** Exact artifact-only validation of the source-sheet producer extension demonstrates direct deterministic `Produced` output for close sheets while retaining plane and multi-face seam as strict-valid direct regressions.

## Exact authority

- source commit: `218dd3ec3f6399dc82183390720a4ba4d3a70b42`
- artifact: `8994541137` (`g2-close-sheet-code-build`)
- artifact SHA-256: `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`
- build run/job: `31179899458` / `92870408341`
- recursive checksums: **45/45 passed**
- packaged closure: five executables, two project libraries, 27 fixture/input files
- rebuild/configure/relink during Test + Benchmark: **none**
- source/test/fixture/validator/build edits during Test + Benchmark: **none**

A runtime-only `bin/test-data -> ../test-data` symlink exposed immutable packaged fixture paths expected by the compiled tests. No packaged byte changed.

## Focused producer contracts

All required focused contracts passed:

1. `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`
2. `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`
3. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
4. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`
5. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`
6. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`
7. `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`

Result: **7/7 passed**.

The close-sheet producer contract observed exact source keys `{(0,0), (1,1)}` and required both sides of every twinned phase-front edge to retain identical component/local-sheet ownership. The face-row-enumeration case retained the same phase-front cell/edge/event cardinalities.

## Direct acceptance

| Fixture | Result | Disposition | Traces | Arrangement | Quads | Vertices | Components | Output hash |
|---|---:|---|---:|---:|---:|---:|---:|---|
| Plane | **pass** | `Produced` | 352 | 65 | 64 | 81 | 1 | `730caeae49ec872c` |
| Multi-face seam | **pass** | `Produced` | 256 | 65 | 64 | 81 | 1 | `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | 1,104 | 202 | 200 | 242 | 2 | `89b052762f52a5af` |
| Cylinder | fail | `NotApplicable` | 732 | 0 | 0 | 0 | — | — |
| Bunny | fail | `NotApplicable` | 80,862 | 0 | 0 | 0 | — | — |
| Vase | fail | `NotApplicable` | 116,922 | 0 | 0 | 0 | — | — |

### Plane

Plane remains direct `CompletedSurfaceCells`:

- 81 output/provenance vertices
- 64 pure quads / zero non-quads
- zero strict validation failures
- no fallback/recovery
- deterministic output hash `730caeae49ec872c` in 3/3 independent processes

### Multi-face seam

Seam remains direct `CompletedSurfaceCells`:

- 81 output vertices
- 64 pure quads / zero non-quads
- zero strict validation failures
- no fallback/recovery
- deterministic current output hash `5bdf34d7802e9fb0` in 3/3 independent processes

The previous tested seam output had hash `a8972efd7c4900a4`; the current output remains geometrically equivalent within approximately `2.065e-9` symmetric Hausdorff distance with unchanged topology/counts and strict validity.

### Close sheets — G2 acceptance

The exact production close-sheet fixture now succeeds directly:

- authoritative producer disposition `Produced`
- output origin `CompletedSurfaceCells`
- 1,104 traces
- 202 arrangement cells
- 200 pure quads / zero non-quads
- 242 provenance/output vertices
- exactly two connected output components
- zero strict validation failures
- no non-manifold edges, T-junctions, duplicate faces, or self-intersections
- topology/boundary preservation true
- fallback policy `Fail`, no fallback attempt/use
- source-grid recovery disabled/unused
- deterministic hash `89b052762f52a5af` in 3/3 processes

The output components contain 121 vertices each and lie independently at `z=-0.035` and `z=+0.035` while sharing the same XY footprint. Combined with the focused authoritative twin-ownership contract, this establishes that spatial proximity does not merge unrelated source sheets.

Therefore **G2 is closed**.

## Later-gate observations

Cylinder remains the earliest later failure:

- `NotApplicable`
- 732 generic traces
- zero arrangement/completion
- terminal `NotProductionReady:completion`
- no fallback/recovery
- deterministic 3/3 prior signature

Bunny remains `NotApplicable` with 80,862 traces and no arrangement/completion. Vase remains `NotApplicable` with 116,922 traces and no arrangement/completion. These are mandatory later observations but cannot supersede the ordered gate decision.

## Default suites

- focused producer contracts: **7/7**
- remaining producer executable: **82/86**
- completion/simplification: **154/164**
- validation: **60/60**
- compiled API: **8/8**
- non-overlapping total including focused contracts: **311/325**

The remaining producer failures are later-gate cylinder/bunny/vase acceptance plus the scheduler-sensitive validator overhead check. The ten completion/simplification failures remain deferred by gate ordering.

## Decision

G2 closes because the exact close-sheet production fixture is direct deterministic strict-valid `Produced` output with two isolated source-sheet components while plane and seam remain valid direct regressions.

The next gate is **G3 periodic cylinder / holonomy**. Current authoritative G3 state is maintained by `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, `.agents/Directional/REORIENTATION_PLAN.md`, `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`, `.agents/Directional/Future_Chat_Session_Handoff.md`, and the current G3 Code + Build/Test + Benchmark records.
