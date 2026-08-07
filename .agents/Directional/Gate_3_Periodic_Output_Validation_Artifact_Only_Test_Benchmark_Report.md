# Gate 3 Periodic Output Validation — Artifact-Only Test + Benchmark Report

## Decision

**G3 remains active. The source-strip correction is structurally valid and deterministic, but it does not close the exact cylinder.**

Exact artifact `9004509871` from source `2783ea718ffb15f8fb3868795173472ab8636c1c` preserves G0–G2 and keeps the cylinder on authoritative periodic `Produced`. The new canonical source-strip breakpoint and row-order contracts pass. However, the cylinder still stops at `completion/output-validation:AggregateCompletionValidationFailure`, and the completed-checkpoint failure count increases from 2 to 3.

Non-invasive inspection of the exact in-memory `SurfaceFinalValidationReport` identifies the three failed scalar thresholds precisely:

- `normalP95Degrees = 16.6272734366` > `15.0`;
- `fieldP95Degrees = 37.9670987281` > `15.0`;
- `warpageP95Degrees = 30.6213792811` > `30.0`.

All discrete strict/source-authoritative topology, boundary, feature-rail, provenance, local-sheet, degeneracy, manifold, inversion, self-intersection, convexity, valence, Euler, and component checks represented in the report are green. Validation was not weakened.

## Turn boundary and artifact integrity

This was an artifact-only Test + Benchmark turn. No configure, compile, relink, source/test/fixture/manifest/validator/benchmark/build edit, or replacement build occurred.

Exact authority:

- artifact ID `9004509871` (`g3-periodic-output-validation-code-build`);
- outer SHA-256 `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- source commit `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- source patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- changed blobs:
  - `src/geometry/SurfaceCellTracing.cpp` `9df9a9759c761293fef1278f97b82fbb0aee0600`;
  - `tests/SurfaceCellsPhase10Tests.cpp` `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`;
- recursive checksums **44/44**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- command-boundary metadata: `runtimeExecution=false` before this Test + Benchmark turn.

A runtime-only `bin/test-data -> ../test-data` symlink exposed immutable packaged fixtures to the binaries. Packaged bytes were unchanged.

## Focused and retained producer contracts

All **13/13** focused/retained contracts passed.

### G3 periodic/output-validation contracts — 6/6

1. `PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
2. `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
3. `PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
4. `PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
5. `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

The corrected row-order test passes by **ordered canonical endpoint-key route/cut identity**, not raw DCEL IDs. The source-strip test proves all source-boundary vertices derived from authoritative boundary edges remain exact phase-front corners on the two genuine annulus boundaries without a hard-coded fixture count.

### Retained G1/G2 contracts — 7/7

- exact committed plane producer boundary;
- disconnected close-sheet partition;
- close-sheet face-row invariance;
- ordered authoritative source-vertex-fan traversal;
- source-vertex-fan row-order invariance;
- duplicate transition metadata fail-closed;
- relief guidance blocks only when embedded.

## Direct mandatory fixtures

| Fixture | Result | Producer | Holonomy | Traces | Quads | Provenance V | Validation | Output |
|---|---|---|---|---:|---:|---:|---:|---|
| plane | pass | `Produced` | — | 352 | 64 | 81 | 0 | `CompletedSurfaceCells`, hash `730caeae49ec872c` |
| multi-face seam | pass | `Produced` | — | 256 | 64 | 81 | 0 | `CompletedSurfaceCells`, hash `5bdf34d7802e9fb0` |
| close sheets | pass | `Produced` | — | 1,104 | 200 | 242 | 0 | `CompletedSurfaceCells`, hash `89b052762f52a5af` |
| cylinder | **fail** | `Produced` | `r=0, t=(32,0), route=32, cut=4` | 2,237 | 320 | 352 | **3** | withheld at completion validation |
| bunny | later-gate fail | `NotApplicable` | — | 80,862 | 0 | 0 | 0 | `NotProductionReady:completion` |
| vase | later-gate timeout | no completed record | — | — | — | — | — | exceeded 180 s bounded observation |

No case used fallback or source-grid recovery. Timeout is failure only and is not correctness evidence.

Plane, seam, and close sheets remain pure quad with zero non-quads and preserve the same output structural hashes as the preceding G3 artifact.

## Cylinder comparison with preceding G3 artifact

| Metric | artifact `9001168379` | artifact `9004509871` |
|---|---:|---:|
| producer | `Produced` | `Produced` |
| periodic translation | `(29,0)` | `(32,0)` |
| route / cut edges | `32 / 4` | `32 / 4` |
| traces | 2,163 | 2,237 |
| direct completed quads | 290 | 320 |
| provenance vertices | 319 | 352 |
| validation failures | 2 | **3** |
| terminal | `completion/output-validation` | same |
| fallback / recovery | none | none |

The source-strip correction substantially improves source approximation:

- quad-to-source P95: `0.0683281 -> 0.0312811`;
- quad-to-source max: `0.107841 -> 0.0667845`;
- source-to-output P95: `0.104464 -> 0.00817359`;
- source-to-output max: `0.161024 -> 0.0657374`.

It does not fix field alignment and introduces one marginal new warpage threshold failure:

- field P95: `37.9671 -> 37.9671` degrees, unchanged;
- normal P95: `15.7660 -> 16.6273` degrees;
- warpage P95: `29.3356 -> 30.6214` degrees.

## Exact structural diagnosis

The remaining dominant defect is an **inter-ring correspondence ambiguity** in the periodic chart.

For each adjacent source ring pair, the triangulated cylinder provides two source-topologically valid one-to-one correspondences because each strip contains both vertical and diagonal inter-ring edges. Current production code enumerates all compatible candidates, sorts their source-vertex sequences lexicographically, and selects `valid.front()`.

On the committed cylinder this selects the diagonal/sheared candidate:

- source ring 0 starts at angular column `0°`;
- the selected next ring starts at `22.5°`;
- the alternative correspondence is the vertical same-column mapping;
- the selected diagonal source edge deviates from the axial cross-field family by exactly **37.9670987281°**, matching the failed `fieldP95Degrees` value.

A non-invasive extraction of the completed checkpoint mesh confirms high-error output edges move in both circumferential angle and axial `z`, rather than staying in the axial family. The source-strip count fix therefore solved one real coverage defect but left a more fundamental chart correspondence ambiguity.

This diagnosis does not rely on fixture IDs, expected output counts, validator relaxation, or synthetic success.

## Determinism

Plane, seam, close sheets, and cylinder were each executed in three independent benchmark processes. All recorded semantic states are stable 3/3: disposition, holonomy tuple/counts, stage counts, validation failure identity/count, stage structural hashes, passing output hashes, and no fallback/recovery.

Cylinder is deterministically wrong at the same completed validation checkpoint.

## Default suites

- focused/retained producer contracts: **13/13**;
- producer remaining bounded set excluding the two long mandatory production acceptance cases: **82/84**;
  - failures: `StrictValidatorOverheadStaysBelowFivePercent` and cylinder direct design acceptance;
- full producer remaining attempt reached `BunnyRandom` after the same cylinder/timing failures but exceeded the bounded execution budget before Bunny/Vase completion;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**.

The ten historical completion/simplification failures remain unchanged and later than the active G3 direct blocker. Aggregate totals do not override direct gate status.

## G3 decision

G3 **does not close**. The exact cylinder remains authoritative periodic `Produced`, and the new source-strip and canonical row-order contracts are live and consumed, so the turn establishes material structural progress. Final direct output remains correctly withheld because three existing validation thresholds fail.

The next Code + Build must remove the field-authority ambiguity in adjacent-ring correspondence rather than further tuning strip counts or validator thresholds.
