# Gate 3 Periodic Output Validation — Artifact-Only Test + Benchmark Report

## Decision

**G3 remains active. The source-strip correction is structurally valid and deterministic, but it does not close the exact cylinder.**

Exact artifact `9004509871` from source `2783ea718ffb15f8fb3868795173472ab8636c1c` preserves G0–G2 and keeps the cylinder on authoritative periodic `Produced`. The canonical source-strip breakpoint and row-order contracts pass. However, the cylinder still stops at `completion/output-validation:AggregateCompletionValidationFailure`, with three failed scalar thresholds.

Non-invasive inspection of the exact in-memory `SurfaceFinalValidationReport` identifies:

- `normalP95Degrees = 16.6272734366` > `15.0`;
- `fieldP95Degrees = 37.9670987281` > `15.0`;
- `warpageP95Degrees = 30.6213792811` > `30.0`.

All represented discrete strict/source-authoritative topology, boundary, feature-rail, provenance, local-sheet, degeneracy, manifold, inversion, self-intersection, convexity, valence, Euler and component checks are green. Validation was not weakened.

## Exact artifact authority

- artifact ID `9004509871` (`g3-periodic-output-validation-code-build`);
- outer SHA-256 `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- source `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- source patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- recursive checksums **44/44**;
- five executables, two project libraries, 27 fixture/input files;
- build metadata recorded `runtimeExecution=false`;
- no configure/compile/relink or source/test/fixture/validator/build edit during this Test + Benchmark turn.

A runtime-only fixture symlink exposed immutable packaged fixture paths. Packaged bytes were unchanged.

## Focused and retained producer contracts

All **13/13** focused/retained contracts passed, including annulus topology, canonical row-order route/cut identity, canonical source-strip breakpoints, artificial-cut pairing, malformed-holonomy fail-closed behavior, exact cylinder producer boundary, and retained G1/G2 source-fan/close-sheet contracts.

## Direct mandatory fixtures

| Fixture | Result | Producer | Holonomy | Traces | Quads | Provenance V | Validation | Output |
|---|---|---|---|---:|---:|---:|---:|---|
| plane | pass | `Produced` | — | 352 | 64 | 81 | 0 | `CompletedSurfaceCells`, `730caeae49ec872c` |
| seam | pass | `Produced` | — | 256 | 64 | 81 | 0 | `CompletedSurfaceCells`, `5bdf34d7802e9fb0` |
| close sheets | pass | `Produced` | — | 1,104 | 200 | 242 | 0 | `CompletedSurfaceCells`, `89b052762f52a5af` |
| cylinder | **fail** | `Produced` | `r=0, t=(32,0), route=32, cut=4` | 2,237 | 320 | 352 | **3** | withheld at completion validation |
| bunny | later-gate fail | `NotApplicable` | — | 80,862 | 0 | 0 | 0 | `NotProductionReady:completion` |
| vase | later-gate timeout | no completed record | — | — | — | — | — | exceeded bounded observation |

No case used fallback or source-grid recovery. Timeout is failure only and is not correctness evidence. Plane, seam and close sheets preserve their strict-valid deterministic passed outputs.

## Source-strip comparison

Compared with preceding G3 artifact `9001168379`:

- periodic translation `29 -> 32`;
- traces `2,163 -> 2,237`;
- direct quads `290 -> 320`;
- provenance vertices `319 -> 352`;
- quad-to-source P95 `0.0683281 -> 0.0312811`;
- source-to-output P95 `0.104464 -> 0.00817359`;
- field P95 `37.9671 -> 37.9671°` unchanged;
- normal P95 `15.7660 -> 16.6273°`;
- warpage P95 `29.3356 -> 30.6214°`.

The source-strip correction substantially improves source coverage but does not solve field alignment.

## Structural diagnosis

The dominant remaining defect is adjacent-ring correspondence ambiguity. Each triangulated annulus strip contains both same-column axial and diagonal inter-ring edges, so two source-topologically valid one-to-one ring correspondences exist. The tested production source enumerates compatible candidates, sorts their source-vertex sequences lexicographically, and consumes `valid.front()`.

On the exact cylinder that selects the diagonal/sheared candidate: the next ring is offset by one angular column (`22.5°`), and the selected diagonal source edge deviates from the axial cross-field family by exactly **37.9670987281°**, matching field P95.

This diagnosis does not rely on fixture IDs, expected output counts, validator relaxation or synthetic success.

## Determinism and suites

Plane, seam, close sheets and the cylinder failure signature are deterministic 3/3.

- focused/retained producer contracts: **13/13**;
- bounded producer remainder excluding long Bunny/Vase acceptance cases: **82/84**; failures were the scheduler-sensitive validator-overhead check and active cylinder design acceptance;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**.

Direct gate status outranks aggregate totals.

## Historical decision and current continuation

This artifact did **not** close G3, but it established material progress by proving source-strip conformity and isolating field-authority ambiguity. The subsequent Code + Build turn has now produced compile-valid field-authoritative adjacent-ring correspondence source at `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` and immutable artifact `9008118764`.

Current continuation is defined by `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Report.md` and `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md`. This report remains the latest **executed runtime** authority until that new artifact is tested.
