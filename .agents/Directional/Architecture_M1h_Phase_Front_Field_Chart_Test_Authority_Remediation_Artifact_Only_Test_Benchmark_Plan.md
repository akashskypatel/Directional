# M1h Phase-Front Field-Chart Test-Authority Remediation — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Prerequisite:** remediation Code + Build compile/package complete  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Immutable inputs

Consume only the exact remediation Code + Build artifacts:

| Evidence | Required value |
|---|---|
| remediation implementation | `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` |
| base M1h production implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| build run/job | `31404102605 / 93506073062` |
| result artifact / ZIP SHA-256 | `9069186973` / `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8` |
| log artifact / ZIP SHA-256 | `9069187317` / `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a` |
| recursive manifest | **72/72**, `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8` |
| package | **73** regular files; 7 executables; 2 static libraries; 27 fixtures |
| build boundary | Release/static/Ninja/PRE_TEST; production source delta false; every runtime flag false |

Rebuild, relink, configure, regeneration, source/test/build/fixture edits, artifact repair, and artifact substitution are prohibited. If immutable authority fails, stop as infrastructure failure.

## 2. Mandatory preflight

Before any packaged binary executes:

1. verify both outer artifact SHA-256 values and GitHub artifact metadata;
2. reject unsafe archive members and extract into a fresh arbitrary directory;
3. verify exact `SHA256SUMS` digest and all **72/72** content entries;
4. verify 73 regular files, seven executables, two static libraries, and 27 fixtures;
5. verify `metadata/build-authority.json` records remediation implementation `32b22d3...`, base M1h production `de4e2ba7...`, run `31404102605`, Release/static/Ninja/PRE_TEST, `productionSourceDelta=false`, and every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input flag false;
6. verify producer executable SHA-256 `937adceea641f372ee42eeb9a3b91c3bba2088847755cc234eaf0b3754f208ac` plus the other executable hashes recorded by the Code + Build report;
7. verify packaged M1h/M1g/M1f/M1e/M1d/M1c/M1b/M1a/T1 test-name metadata and direct-product metadata;
8. verify production source blobs remain the accepted M1h values and remediated test blob is `71b991896846a486f29a550ddde4260748b03cd7`.

Do **not** create a runtime fixture symlink. Packaged binaries must continue to resolve sibling `../test-data` naturally.

## 3. Native discovery authority

Use package-native GoogleTest listing only after immutable preflight. Expected counts:

- producer: exactly **202** tests;
- validation: exactly **77** tests;
- M1a authority kernel: exactly **14** tests;
- T1 independent oracle: exactly **29** tests.

Unexpected discovery is a blocking authority failure.

## 4. M1h focused semantic contracts — six individually

Run each packaged M1h contract in a fresh process by exact semantic name:

1. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.PlanarMultiFaceFrontPublishesCheckedSingleChart`;
2. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering`;
3. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.NumericCoincidenceCannotCrossAuthorityDomains`;
4. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MissingOrInvalidChartAuthorityCannotMasqueradeAsValid`;
5. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.FaceRowPermutationPreservesTypedPlanarChartAuthority`;
6. `SurfaceCellPhaseFrontFieldChartAuthorityMigration.PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero`.

All six must pass without retry-based acceptance.

For the corrected second contract, acceptance specifically requires:

- producer/compatibility chart numbering remains exact `{0,1,2}`;
- face `3` remains chart `1` and face `10` remains chart `2` under the hard-authored fixture oracle;
- every actual lattice occurrence carries a present typed `FieldChartId` matching the independently hard-authored chart of its paired source face;
- actual occurrence sampling is not required to equal the full producer-domain set;
- the fixture still exercises more than the default chart in constructive-front occurrences;
- no `{0,2}` chart-domain expectation or other weakened oracle is introduced.

A failing focused contract blocks acceptance. Diagnose test versus implementation intent; do not edit or weaken anything in this turn.

## 5. Preservation gates

Re-run exact packaged preservation authority:

- M1g focused **6/6** individually;
- M1f focused **6/6** individually;
- M1e focused **6/6** individually;
- M1d focused **6/6** individually plus accepted route counterexamples;
- M1c focused **6/6** individually plus accepted transition counterexamples;
- M1b focused **6/6** individually;
- validation **77/77**;
- M1a **14/14**;
- T1 independent oracle **29/29**.

Preserve `RP-07` route/periodic transport behavior exactly. M1h must not reinterpret nonzero periodic rotation or close `G4-B003`.

## 6. Complete producer accounting

Producer discovery must be exactly **202**. Construct the required-green producer partition explicitly.

Expected required-green result is **187/187**. Continue excluding only the established non-required-green categories:

- four direct product cases, executed separately with independent product-oracle assertions;
- eight stable historical/deferred producer reds with unchanged entering classifications;
- the nondeterministic strict-validator 5% timing microbenchmark characterization;
- Bunny known-red;
- Vase bounded safety-only.

No newly failing test may be silently added to the exclusion set.

## 7. Direct product authority

Run the exact four names from `metadata/direct-product-test-names.txt` separately:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

All four must pass their packaged independent product-oracle assertions from arbitrary extraction without a fixture symlink.

## 8. Historical/deferred reds

Execute the same eight stable historical/deferred producer reds individually and compare their failure classes against accepted M1g/M1h entering authority. They must remain explicit and unchanged.

In particular preserve:

- nonzero periodic whole-cycle rotation rejection as `PeriodicHolonomyMismatch`;
- exact-torus/hard-rail classifications;
- existing multi-isolation/quotient assertion reds.

Any class change attributable to the remediation package blocks acceptance.

## 9. Strict-validator timing characterization

Characterize `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` in ten fresh processes.

This remains a deferred nondeterministic sub-millisecond ratio gate. Record pass/fail distribution and representative timings, but do not weaken the threshold, retry until green, or use it as M1h semantic acceptance authority.

## 10. Bunny and Vase bounded comparison

If no earlier semantic blocker remains, execute Bunny and Vase under the standing artifact-only heavy-case rule:

- consume exact result artifact `9069186973`;
- verify full immutable preflight before runtime;
- perform no checkout/configure/build/relink/regeneration/package mutation;
- create no fixture symlink;
- Bunny remains comparison against entering known completion red unless behavior actually changed;
- Vase remains bounded safety-only unless it completes within the existing bound;
- perform exact immutable postflight afterward;
- remove any temporary runtime workflow before its trigger marker.

Do not synthesize product status from a timeout.

## 11. Immutable postflight

After all runtime execution, reverify:

- both outer ZIP SHA-256 values;
- exact `SHA256SUMS` digest;
- all **72/72** package checksums;
- 73 regular files, seven executables, two libraries, 27 fixtures;
- producer and independent-oracle executable hashes;
- build-authority metadata.

No packaged regular file may change during validation.

## 12. Acceptance and closeout

M1h becomes immutable accepted only if:

1. M1h focused **6/6**;
2. producer discovery exactly **202**;
3. required-green producer **187/187**;
4. all M1g through M1b preservation gates green;
5. validation **77/77**, M1a **14/14**, T1 **29/29**;
6. Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink;
7. historical/deferred red classifications preserved;
8. Bunny/Vase dispositions compared without synthetic reinterpretation if no earlier blocker remains;
9. immutable postflight exact;
10. no new stable product regression or recurrence.

If accepted, fold stable M1h facts into durable status documents, then inspect fresh accepted source to select the next bounded M1 consumer. Do not advance to M2 or G4 repair merely because M1h passes.

Every completed turn removes temporary workflow/trigger/helper state, keeps PR #8 open/draft/unmerged, and ends with exactly one new top-level PR #8 conversation comment after all other repository and PR-body writes.
