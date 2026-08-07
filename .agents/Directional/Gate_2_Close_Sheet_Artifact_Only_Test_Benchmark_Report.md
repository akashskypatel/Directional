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

Plane, seam and close sheets were direct `CompletedSurfaceCells` pure-quad outputs with zero strict validation failures, no fallback/recovery and deterministic hashes. Close sheets produced two isolated 121-vertex source-authoritative components at the two source layers despite coincident XY footprint, proving spatial proximity does not merge unrelated sheets.

Therefore **G2 is closed**.

## Historical later-gate observation

At the time of this G2 artifact, cylinder/bunny/vase remained later-gate `NotApplicable`. Current G3 authority is intentionally maintained only by the live `TODO`, `MILESTONE_G_TODO.md`, handoff, design/remediation/runtime summary, latest G3 runtime report, latest G3 Code + Build report, and next artifact-only plan. This G2 report is retained solely as passed-gate authority and does not define current G3 state.
