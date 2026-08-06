# Gate 1 Uniform Phase-Front Artifact-Only Test + Benchmark Report

**Date:** 2026-08-06  
**Execution plane:** local container; no GitHub Actions workflow used  
**Turn boundary:** artifact execution only; no configure, compile, relink, source edit, test edit, fixture edit, or validator edit

## Artifact authority

- Outer artifact SHA-256: `7e520acda5d402300711d1803a666e505ce4a03c0b92d969f5ae2ba3ca2d1f28`
- Internal checksum verification: **47/47**
- Base source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`
- Exact patch Git blob: `aa18d454877ccf40d16f71f173fdaf765f5f1086`
- Uncompressed patch SHA-256: `48a01a37b038c59af18f2fca8904642f23bf8ea54f8ff8c3c784191dc99b8bf7`
- Remote applied-source commit: pending while the GitHub workflow/write path is unavailable
- Package closure: five executables, two static libraries, 26 fixtures

The exact five-file source synchronization remains on `TODO` and `MILESTONE_G_TODO.md`. No workflow may be used for that synchronization while the outage persists.

## Direct acceptance

| Fixture | Result | Traces | Arrangement cells | Completed quads | Earliest authoritative failure |
|---|---:|---:|---:|---:|---|
| Plane | failed | 352 | 65 | 409 | `completion/output-validation:FlippedFace` |
| Multi-face seam | failed | 137 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | failed | 158 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Cylinder | failed | 732 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |

All four requested and executed `SurfaceCells`, attempted no fallback, used no source-grid recovery, and ended with output origin `None`.

### Plane material progress and remaining defect

- Previous baseline: 106 traces, 9 arrangement cells, 12 completed quads, 15 completion-validation failures.
- Gate 1 patch: **352 traces, 65 arrangement cells, 409 completed quads, 100 validation failures**.
- The first invalid producer record is `completion/output-validation:FlippedFace`, cell 38, source face 41.
- The phase-front tracing hash, arrangement hash, completion hash, and structural counts are identical across all three independent benchmark processes.
- This proves the new phase-front state is live and consumed by arrangement and completion, but the emitted cell orientation/incidence is not production-valid.
- The next Code + Build turn must correct orientation and direct-cell materialization; it must not add more diagnostics or route already-decided cells through generic patch expansion that turns 65 cells into 409 quads.

## Default-suite result

| Suite | Passed | Total | Failures |
|---|---:|---:|---:|
| Producer | 77 | 83 | 6 |
| Completion | 154 | 164 | 10 |
| Validation | 60 | 60 | 0 |
| Compiled API | 8 | 8 | 0 |
| **Total** | **299** | **315** | **16** |

Producer failures comprise the four direct gates plus two obsolete expectations:

1. `AdaptiveTargetSizePhase12.SurfaceCellScaffoldPopulatesSizeDiagnostics` assumes the SurfaceCells scaffold must fail; the new path succeeds on its tiny planar input.
2. `SurfaceCellsPhase10.SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture` forces recovery and assumes recovery must be selected even when direct SurfaceCells succeeds. It now receives direct `CompletedSurfaceCells` output. The recovery-specific assertion is no longer valid for that input.

The ten completion failures are unchanged from the previous artifact and remain downstream/historical fixture work; they are not evidence against the new plane phase-front path.

## Bounded benchmark repetitions

| Fixture | Run 1 | Run 2 | Run 3 | Structural result stable |
|---|---:|---:|---:|---:|
| Plane | 0.130857s | 0.124152s | 0.128165s | yes |
| Multi-face seam | 0.013736s | 0.014004s | 0.013375s | yes |
| Close sheets | 0.021108s | 0.020880s | 0.026107s | yes |
| Cylinder | 0.153768s | 0.148326s | 0.131007s | yes |

No torus, sphere, thin-tube, mechanical, or bunny case was executed because the four preceding analytic gates remain red.

## Authoritative next turn

Proceed with **Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build**:

1. Preserve first-class phase, lattice coordinates, front ownership, and deterministic hashes.
2. Orient every accepted cell against the authoritative source normal before arrangement materialization.
3. Validate ordered side continuity, distinct corners, nonzero signed area, and one-filled-side ownership before a cell becomes authoritative.
4. Materialize one already-decided phase-front cell as one quad-domain cell; do not send it through generic patch completion that expands 65 cells into 409 quads.
5. Fail closed on orientation, incidence, route, component, or sheet inconsistency.
6. Correct the two stale producer tests without weakening direct acceptance or recovery validation.
7. Compile only; execute no tests or benchmarks.
8. Keep the exact existing five-file remote source synchronization on the TODO until the GitHub outage is resolved, then layer the orientation/direct-cell changes as a separate coherent commit.

Gate 1 remains open.
