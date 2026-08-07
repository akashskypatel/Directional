# Gate 3 Periodic Ring Correspondence — Artifact-Only Test + Benchmark Report

## Decision

**G3 remains active. This turn is classified as regression / no-progress by the gate acceptance hierarchy.**

The field-authoritative correspondence source is compile-valid, and its explicit ambiguous-candidate fail-closed contract passes, but exact runtime does not preserve periodic `Produced` authority. The cylinder now deterministically rejects in `tracing/phase-front` with `InvalidPeriodicChart` at phase-front cell 29 before trace generation. Periodic holonomy is not exposed in the terminal diagnostics, so G3 cannot close and this artifact cannot be treated as material runtime progress under the current acceptance rules.

G0-G2 remain green. No fallback or source-grid recovery is used.

This is the first consecutive Code + Build result since the prior source-strip material-progress turn that fails to advance G3 at runtime, so the mandatory two-Code+Build no-progress review rule is **not yet triggered**. The next turn may remain bounded Code + Build.

## Exact artifact authority

Artifact-only execution used exactly:

- artifact `9008118764`, `g3-periodic-ring-correspondence-code-build`;
- outer SHA-256 `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- initial implementation commit `18f2c880f1714d8c41c9e11dadd53169756629fe`;
- initial implementation patch SHA-256 `49cd71bc5aafc33ccdfd5e5104e5a23c7452e72074aac3c7775794f55737d6de`;
- compile-correction patch SHA-256 `8c96fa983990ab6c3f3ace5b24b8af59678aa7d6a0b7ed4f57b06f1397d1cd56`;
- build run/job `31214404170 / 92984429773`;
- build log artifact `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`.

Pre-execution integrity passed:

- recursive checksums **44/44**;
- final blobs:
  - `include/directional/geometry/SurfaceCellTracing.h` `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
  - `src/geometry/SurfaceCellTracing.cpp` `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`;
  - `tests/SurfaceCellsPhase10Tests.cpp` `c4671ef674228d74b96e80499abbb6846bcdf3e3`;
- five executables, two project libraries, 27 fixture/input files;
- exact plane, seam, close-sheet, cylinder, bunny and vase fixtures are checksummed;
- build log reaches `111/111` and the successful workflow packaged the artifact;
- Release / Ninja / static / seven approved targets / `PRE_TEST`;
- packaged command boundary records `runtimeExecution=false` before this Test + Benchmark turn.

No configure, compile, relink, discovery regeneration, source/test/fixture/manifest/validator/build edit, or replacement build occurred. A runtime-only `bin/test-data -> ../test-data` symlink exposed immutable packaged fixtures.

## Focused producer contracts

Focused/retained set: **9/15 passed, 6 failed**.

Passed:

- `PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`;
- `ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`;
- all seven retained G1/G2 producer contracts.

Failed, all because the nominal valid periodic chart now becomes `Rejected/InvalidPeriodicChart`:

1. `PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
2. `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
3. `PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
4. `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`;
5. `PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
6. `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` — its valid precondition chart rejects before malformed-holonomy mutation is exercised.

The ambiguity contract proves genuinely field-equivalent topology candidates still fail closed with the new typed authority. The exact-cylinder boundary test intentionally accepts typed periodic rejection as a producer-boundary condition, so it does not override the failed `Produced` contracts or direct acceptance.

## Direct mandatory fixtures

All active cases were run in fresh processes with `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, warmup 0, runs 1.

| Fixture | Result | Producer | Traces | Arrangement | Direct quads | Output | Determinism |
|---|---|---:|---:|---:|---:|---|---|
| plane | pass | `Produced` | 352 | 65 | 64 | 81 V / 64 Q, hash `730caeae49ec872c` | 3/3 |
| multi-face seam | pass | `Produced` | 256 | 65 | 64 | 81 V / 64 Q, hash `5bdf34d7802e9fb0` | 3/3 |
| close sheets | pass | `Produced` | 1,104 | 202 | 200 | 242 V / 200 Q, 2 components, hash `89b052762f52a5af` | 3/3 |
| cylinder | **fail** | **`Rejected/InvalidPeriodicChart`** | 0 | 0 | 0 | none; terminal `NotProductionReady:tracing` | 3/3 |
| bunny | later-gate fail | `NotApplicable` | 80,862 | 0 | 0 | none; `NotProductionReady:completion` | 1 bounded |
| vase | later-gate timeout | no completed record | — | — | — | 45 s bounded timeout; failure only | 1 bounded |

Passing G0-G2 output hashes and cardinalities are unchanged from the preceding G3 runtime authority. Plane/seam/close sheets have zero non-quads. Close sheets retain two output components and 80 boundary edges. No active case attempts fallback or uses source-grid recovery.

Cylinder is stable 3/3 at:

- producer `Rejected`;
- `surfaceCellFirstInvalidProducerStage = tracing/phase-front`;
- `surfaceCellFirstInvalidProducerReason = InvalidPeriodicChart`;
- `surfaceCellFirstInvalidProducerCell = 29`;
- periodic holonomy unavailable in terminal diagnostics;
- zero trace segments, arrangement cells, completed quads, provenance vertices or output;
- terminal `NotProductionReady:tracing`;
- no fallback/recovery;
- approximately 0.0116-0.0120 s per process and about 8.3-8.4 MB benchmark-reported peak working set.

This is a regression from artifact `9004509871`, where cylinder was periodic `Produced`, `r=0`, `t=(32,0)`, route 32, cut 4, 2,237 traces, 320 direct quads / 352 provenance vertices, and reached completed output validation with three scalar quality failures.

## Exact structural diagnosis

The regression is not evidence that the prior diagonal correspondence should be restored.

Independent reconstruction using only the immutable packaged cylinder fixture and packaged source reproduces the new chart failure at **exactly cell 29**. The field-aligned adjacent-ring mapping has zero angular shift and axial source edges; the competing diagonal mapping has 22.5-degree angular shift and `37.9670987281°` axial-field deviation, matching the prior field-P95 defect.

The new failure occurs later inside periodic chart boundary-path construction. `periodic_chart_segment()` clips triangle occupancy using a `1e-10` tolerance, but emits barycentric interval endpoints at the tolerance-expanded limits without canonicalizing them back onto the source simplex boundary. At cell 29, two sides that geometrically share the same source vertex acquire microscopic tails on source face 30:

- side 0 segment 1 ends at barycentric 2D `(0, 0)` after starting near `(-9.9999e-11, 0)`;
- side 1 segment 0 starts at `(0, 0)` and extends toward approximately `(-1e-10, 1e-10)`.

`validate_closed_boundary_paths()` then calls the unchanged `segments_intersect_beyond_shared_endpoint_2d()` and consistently sees the emitted segments as overlapping beyond an exact shared endpoint. The caller reports this as `InvalidPeriodicChart` for cell 29.

This was reproduced independently by rebuilding the immutable source chart numerically, including the 16 source columns, five rings, 32 periodic subdivisions, 10 axial subdivisions, periodic triangle unwrap, interval clipping and shared-face self-intersection predicate. The first reproduced rejection is cell 29, matching runtime diagnostics.

Therefore the next correction must canonicalize **producer-emitted chart segment endpoints**, not relax the self-intersection validator. Increasing validator tolerances or ignoring small intersections would be validator weakening and is prohibited.

## Later observations and default suites

Bunny completed one bounded process in `41.60769 s`, peak working set `247,566,336` bytes, `NotApplicable`, 80,862 traces, zero arrangement/completion, no fallback/recovery. Vase did not complete within the 45-second bounded observation; timeout is failure only.

Bounded producer coverage excluding the two long BunnyRandom/Vase direct design-acceptance parameter cases: **91/99**. Failures are the six periodic chart regressions above, scheduler-sensitive `StrictValidatorOverheadStaysBelowFivePercent`, and cylinder direct design acceptance.

Other suites:

- completion/simplification: **154/164**, same historical ten failures;
- validation: **60/60**;
- compiled API: **8/8**.

Bounded aggregate across those executed suites: **313/331**. Direct gate status outranks aggregate totals.

## Next turn

Execute `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Plan.md` as **Code + Build only**.

Preserve the field-authoritative ring correspondence and typed ambiguity behavior. Fix the general periodic chart segment endpoint representation upstream so tolerance-expanded clipping cannot create microscopic non-source tails or false self-intersections at exact source vertices/edges. Keep `validate_closed_boundary_paths()` and `segments_intersect_beyond_shared_endpoint_2d()` authoritative and unchanged unless a separate design proof demonstrates an actual validator defect.
