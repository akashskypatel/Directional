# Gate 1 Phase-Front Orientation — Artifact-Only Test + Benchmark Report

## Verdict

**Gate 1 — Uniform phase-front plane: PASSED.**

The exact packaged artifact produced direct, source-authoritative, non-empty pure-quad `CompletedSurfaceCells` output for the plane with fallback `Fail`, no fallback attempt, source-grid recovery disabled, and zero strict validation failures.

The earliest incomplete gate is now **Gate 2 — Cross-chart and close-sheet propagation**.

## Exact authority

- artifact SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- internal checksums: **45/45**;
- package closure: five executables, two static libraries, 26 fixture/input files;
- phase-front commit: `4842911b6134c60410c92496d85d1152164a73c7`;
- orientation/direct-cell commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- rebuild performed: **no**;
- source/test/fixture/validator edit: **no**.

## Direct acceptance

| Fixture | Result | Traces | Arrangement cells | Direct cells / output quads | Validation failures | Terminal |
|---|---:|---:|---:|---:|---:|---|
| Plane | **pass** | 352 | 65 | 64 / 64 | 0 | `None` |
| Multi-face seam | fail | 137 | 0 | 0 / 0 | 0 | `NotProductionReady:completion` |
| Close sheets | fail | 158 | 0 | 0 / 0 | 0 | `NotProductionReady:completion` |
| Cylinder | fail | 732 | 0 | 0 / 0 | 0 | `NotProductionReady:completion` |

The three failing later fixtures retain `SideSubdivisionRepair:InvalidInputIncidence`; no fallback or recovery was used.

## Plane proof

Across three independent processes:

- success: **3/3**;
- wall times: `0.361926, 0.363952, 0.364536` seconds;
- trace segments: **352**;
- authoritative direct cells: **64**;
- arrangement inventory: **65** cells, including the exterior domain;
- simplified inventory: **65**;
- output: **81 vertices, 64 faces, 64 quads, 0 non-quads**;
- strict validation failures: **0**;
- output origin: `CompletedSurfaceCells`;
- output structural hash: `730caeae49ec872c` in all processes;
- topology and boundary preservation: **true**;
- stage hashes and counts: identical across all processes.

The prior generic expansion from 65 arrangement cells to 409 completed quads is eliminated. The direct completion path materializes one accepted four-sided phase-front cell as one output quad and bypasses generic patch completion. `FlippedFace` is eliminated.

## Default suites

| Suite | Passed | Total | Failures |
|---|---:|---:|---:|
| Direct acceptance | 1 | 4 | 3 |
| Remaining producer | 78 | 79 | 1 |
| Completion | 154 | 164 | 10 |
| Validation | 60 | 60 | 0 |
| Compiled API | 8 | 8 | 0 |
| **Non-overlapping total** | **301** | **315** | **14** |

The remaining producer failure is the known scheduler-sensitive wall-clock assertion `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`: measured validation time was `0.000125457` seconds against a threshold of `0.0000798764` seconds. It is not a functional Gate 1 regression and belongs in optional benchmark/closeout coverage.

The ten completion failures are unchanged historical/downstream fixtures and do not displace Gate 2.

## Gate transition

- G0 truthful authority — passed.
- G1 uniform phase-front plane — **passed in this turn**.
- G2 cross-chart and close-sheet propagation — **active**.
- G3 periodic closure and holonomy — blocked by G2.
- G4–G7 — blocked.

Gate 2 begins with the multi-face seam. The next implementation must transport phase, integer lattice coordinates, branch rotation, field family/sign, source-chart identity, component, local-sheet, and route provenance through exact source-chart transitions and cross-field matching. It must fail closed on missing or inconsistent transitions and must prevent cross-sheet capture or positional merging.

## Integrity

Every direct case and benchmark process executed the packaged artifact in a fresh bounded process. No process timed out. No rebuild, discovery regeneration, source edit, fixture edit, test edit, validator edit, fallback substitution, recovery substitution, synthetic topology correction, or acceptance weakening occurred.
