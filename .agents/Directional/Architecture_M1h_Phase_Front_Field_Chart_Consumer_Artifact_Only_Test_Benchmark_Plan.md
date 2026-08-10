# M1h Phase-Front Field-Chart Consumer — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Prerequisite:** M1h Code + Build compile/package complete  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Immutable inputs

Consume only the exact M1h Code + Build artifacts:

| Evidence | Required value |
|---|---|
| implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| build run/job | `31398571348 / 93487537918` |
| result artifact / ZIP SHA-256 | `9066967620` / `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03` |
| log artifact / ZIP SHA-256 | `9066968049` / `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816` |
| recursive manifest | **69/69**, `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9` |
| package | **70** regular files; 7 executables; 2 static libraries; 27 fixtures |
| build boundary | Release/static/Ninja/PRE_TEST; every runtime flag `false` |

Rebuild, relink, configure, regeneration, source/test/build/fixture edits, artifact repair, and artifact substitution are prohibited. If immutable authority fails, stop as infrastructure failure.

## 2. Mandatory preflight

Before any packaged binary executes:

1. verify both outer artifact SHA-256 values and GitHub artifact metadata;
2. reject unsafe archive members and extract into a fresh arbitrary directory;
3. verify the exact `SHA256SUMS` digest and all **69/69** content entries;
4. verify 70 regular files, seven executables, two static libraries, and 27 fixtures;
5. verify `metadata/build-authority.json` records implementation `de4e2ba7...`, run `31398571348`, Release/static/Ninja/PRE_TEST, and every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input flag `false`;
6. verify the producer executable SHA-256 `c9af71b0d32cb2af6f3ab6f466f54c9b30b8517f9413a047d9ae3b24827ca33a` and the other packaged executable hashes recorded by the Code + Build report;
7. verify packaged M1h/M1g/M1f/M1e/M1d/M1c/M1b/M1a/T1 test-name metadata and direct-product metadata;
8. verify packaged source/test blob IDs match the Code + Build report.

Do **not** create the historical runtime-only `benchmarks/fixtures` symlink used during M1g. M1h specifically changes fixture resolution so packaged binaries must find sibling `../test-data` themselves from arbitrary extraction/runtime locations.

## 3. Native discovery authority

Use package-native GoogleTest listing only after immutable preflight. Expected counts:

- producer: exactly **202** tests;
- validation: exactly **77** tests;
- M1a authority kernel: exactly **14** tests;
- T1 independent oracle: exactly **29** tests.

Producer discovery must equal accepted M1g 196 plus exactly six M1h contracts. Unexpected discovery count is a blocking authority failure.

## 4. M1h focused semantic contracts — six individually

Run each packaged M1h contract in a fresh process by exact semantic name:

1. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.PlanarMultiFaceFrontPublishesCheckedSingleChart`;
2. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering`;
3. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.NumericCoincidenceCannotCrossAuthorityDomains`;
4. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MissingOrInvalidChartAuthorityCannotMasqueradeAsValid`;
5. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.FaceRowPermutationPreservesTypedPlanarChartAuthority`;
6. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero`.

All six must pass without retry-based acceptance.

Semantic acceptance requires:

- every accepted planar/front lattice occurrence carries a valid `FieldChartId`;
- the established single-chart compatibility value remains zero;
- the deterministic three-chart fixture preserves legacy numbering `{0,1,2}` while carrying typed identity;
- equal numeric values from another authority domain cannot be accepted as `FieldChartId`;
- missing, negative, or out-of-range chart authority is not silently coerced;
- face-row permutation does not create chart identity;
- periodic and bounded-disk single-chart producers obtain checked chart zero;
- packaged fixture discovery succeeds through the new sibling layout without an external symlink.

A failing M1h semantic contract blocks acceptance. Diagnose test versus implementation intent; do not weaken the contract or substitute synthetic state.

## 5. Preservation gates

Re-run exact packaged preservation authority:

- M1g focused **6/6** individually;
- M1f focused **6/6** individually;
- M1e focused **6/6** individually;
- M1d focused **6/6** individually plus the accepted three route counterexamples;
- M1c focused **6/6** individually plus the accepted three transition counterexamples;
- M1b focused **6/6** individually;
- validation **77/77**;
- M1a **14/14**;
- T1 independent oracle **29/29**.

Preserve `RP-07` route/periodic transport behavior exactly. M1h must not reinterpret nonzero periodic rotation or close `G4-B003`.

## 6. Complete producer accounting

After exact discovery, construct the required-green producer partition explicitly. Expected required-green count is **187/187**: accepted M1g **181** plus the six new M1h contracts.

Continue excluding only the established non-required-green categories:

- the four direct product cases, which execute separately with independent product-oracle assertions;
- the eight stable historical/deferred producer reds with unchanged entering classifications;
- the nondeterministic strict-validator 5% microbenchmark characterization;
- Bunny known-red;
- Vase bounded safety-only.

No newly failing test may be silently added to the exclusion set.

## 7. Direct product authority

Run the exact four names from `metadata/direct-product-test-names.txt` separately:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

All four must pass their packaged independent product-oracle assertions and must run successfully from the extracted package **without a runtime fixture symlink**. This is both product preservation and the direct acceptance proof for the M1g-discovered packaging portability defect.

## 8. Historical/deferred reds

Execute the same eight stable historical/deferred producer reds individually and compare their failure class against M1g accepted authority. They must remain explicit; do not turn them into expected passes, skip them, or weaken assertions.

In particular, preserve:

- nonzero periodic whole-cycle rotation rejection as `PeriodicHolonomyMismatch`;
- exact-torus/hard-rail classifications;
- existing multi-isolation/quotient assertion reds.

Any class change attributable to M1h is a regression and blocks acceptance.

## 9. Strict-validator timing characterization

Characterize `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` in ten fresh processes only to maintain continuity with M1e/M1f/M1g evidence.

This sub-millisecond ratio gate is already classified as a deferred nondeterministic performance-test defect. Record pass/fail distribution and representative timings, but do not weaken the 5% threshold, retry until green, or use it as M1h semantic acceptance authority.

## 10. Bunny and Vase bounded comparison

Use the standing artifact-only heavy-case rule from `MILESTONE_G_TODO.md` / `GitHub_Workflow_Policy.md` if local execution is unsuitable:

- download exact result artifact `9066967620` directly;
- verify full immutable preflight before runtime;
- perform no checkout/configure/build/relink/regeneration/package mutation;
- do not create fixture symlinks;
- Bunny remains expected to demonstrate its entering known completion red unless product behavior actually changed;
- Vase remains bounded safety-only unless it completes within the existing bound;
- perform exact immutable postflight afterward;
- remove temporary runtime workflow before its trigger marker.

Do not synthesize pass/failure status from a timeout.

## 11. Immutable postflight

After all runtime execution, reverify:

- both outer ZIP SHA-256 values;
- the exact `SHA256SUMS` digest;
- all **69/69** package checksums;
- 70 regular files, seven executables, two libraries, 27 fixtures;
- producer and independent-oracle executable hashes;
- build-authority metadata.

No packaged regular file may change during validation.

## 12. Regression and closeout rules

Acceptance criteria:

1. M1h focused **6/6**;
2. producer discovery exactly **202**;
3. required-green producer **187/187**;
4. all M1g through M1b preservation gates green;
5. validation **77/77**, M1a **14/14**, T1 **29/29**;
6. Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink;
7. historical/deferred red classifications preserved;
8. Bunny/Vase dispositions compared without synthetic reinterpretation;
9. immutable postflight exact;
10. no new stable regression or recurrence.

If accepted, fold stable M1h facts into the durable handoff and regression tracker. Select the next bounded M1 consumer only from fresh source inspection. Do not advance to M2 or G4 repair merely because M1h passes.

Every completed turn must remove temporary workflow/trigger/helper state, keep PR #8 open/draft/unmerged, and make exactly one new top-level PR #8 conversation comment as the final repository write.
