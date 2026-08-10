# M1h Phase-Front Field-Chart Consumer — Artifact-Only Test + Benchmark Report

**Status:** blocked by focused test-authority defect; M1h semantic acceptance not granted  
**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Result

M1h runtime validation consumed only the immutable Code + Build artifacts for implementation `de4e2ba7c19d2e49931655dc22d758f50656d054`.

The package and production-preservation evidence are healthy, but M1h **cannot be accepted** because one of the six new focused contracts fails:

`SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering`.

Observed failure:

```text
expected typedCharts = {0,1,2}
actual   typedCharts = {0,2}
```

The same test's independent compatibility assertions for the producer-owned face-chart values continue to pass: face `3` publishes legacy chart `1`, and face `10` publishes legacy chart `2`. Source inspection of the exact packaged implementation shows why the first assertion is not a valid witness: `typedCharts` is collected only from `LocalLatticeState` at accepted cell corners, while chart `1` in this fixture is traversed by boundary segments but has no accepted lattice-corner occurrence. The producer numbering itself has not collapsed; the test incorrectly equates **producer chart-domain coverage** with **lattice-corner occurrence coverage**.

This is classified as a **new M1h test-authority/fixture assertion defect**, not a product regression and not evidence that the production `FieldChartId` migration changed numbering. The contract remains blocking because changing `{0,1,2}` to `{0,2}` would weaken the intended test rather than correct it.

No source, implementation, test, fixture, validator, benchmark, or build file was edited, rebuilt, relinked, regenerated, repaired, or substituted during this turn.

## 2. Immutable package authority

| Evidence | Value |
|---|---|
| implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| build run/job | `31398571348 / 93487537918` |
| result artifact / ZIP SHA-256 | `9066967620` / `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03` |
| build-log artifact / ZIP SHA-256 | `9066968049` / `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816` |
| recursive manifest | **69/69**, `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9` |
| package | **70** regular files; 7 executables; 2 static libraries; 27 fixtures |
| build boundary | Release/static/Ninja/PRE_TEST; every Code + Build runtime flag `false` |

Preflight rejected unsafe archive paths, verified both outer artifact digests, all **69/69** content checksums, exact package cardinalities, build-authority metadata, source/test blob IDs, focused-test metadata, direct-product metadata, and executable hashes before runtime.

Executable authority reverified:

- producer `c9af71b0d32cb2af6f3ab6f466f54c9b30b8517f9413a047d9ae3b24827ca33a`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

## 3. Native discovery

Package-native GoogleTest discovery from the exact artifact produced the required counts:

- producer: **202**;
- validation: **77**;
- M1a authority kernel: **14**;
- T1 independent oracle: **29**.

The producer count is accepted M1g 196 plus exactly six M1h contracts.

## 4. M1h focused contracts

Fresh-process results:

1. `PlanarMultiFaceFrontPublishesCheckedSingleChart` — **pass**;
2. `MultipleOrientationChartsPreserveEstablishedNumbering` — **fail**;
3. `NumericCoincidenceCannotCrossAuthorityDomains` — **pass**;
4. `MissingOrInvalidChartAuthorityCannotMasqueradeAsValid` — **pass**;
5. `FaceRowPermutationPreservesTypedPlanarChartAuthority` — **pass**;
6. `PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero` — **pass**.

Result: **5/6**. M1h semantic acceptance is blocked.

### Failure diagnosis

The failing test builds the established multi-orientation `SegmentRouteFixture` and collects `typedCharts` only from `cell.lattice[*].sourceChart`. In that fixture:

- the producer-owned typed chart table retains at least charts `0`, `1`, and `2`;
- `segment_on_source` converts the typed producer chart back to the compatibility integer schema for traversed segments;
- the test successfully observes compatibility chart `1` on face `3` and chart `2` on face `10`;
- accepted lattice corners happen to occur on chart `0` and chart `2`, not chart `1`.

Therefore the assertion that all producer charts must appear among lattice-corner occurrences is not supported by the fixture geometry or by the M1h architectural invariant. The intended invariant is that every **actual** lattice occurrence carries the correct typed producer chart identity, while producer numbering is verified independently across the producer's chart domain.

The remediation must not simply change the expected set to `{0,2}`. It must separate those two authorities or provide a fixture that independently guarantees lattice occurrences on every chart.

## 5. Preservation evidence

All previously accepted focused suites executed individually from the same immutable producer package and remained green:

| Gate | Result |
|---|---:|
| M1g focused | **6/6** |
| M1f focused | **6/6** |
| M1e focused | **6/6** |
| M1d focused | **6/6** |
| M1c focused | **6/6** |
| M1b focused | **6/6** |
| validation | **77/77** |
| M1a | **14/14** |
| T1 independent oracle | **29/29** |

The complete required-green producer partition was constructed with exactly the established 15 exclusions: four separately-run direct products, eight historical/deferred reds, strict-validator timing, Bunny, and Vase.

Expected required-green cardinality was **187**. Exact aggregate result:

- **186 passed**;
- **1 failed** — only `MultipleOrientationChartsPreserveEstablishedNumbering`;
- wall approximately **23.17 s**;
- peak RSS approximately **23,140 KiB**.

Thus no entering required-green producer test regressed. The only aggregate failure is the same new M1h contract.

The accepted M1d/M1c counterexample tests are contained in this required-green partition and did not produce any additional failure. Because M1h acceptance was already blocked, no separate claim of new counterexample acceptance is made beyond the unchanged aggregate/focused preservation evidence.

## 6. Packaged fixture portability — corrected behavior proven

No runtime fixture symlink was created.

The direct products executed successfully from an arbitrary extraction directory using the packaged sibling `../test-data` layout:

| Product | Result | Wall | Peak RSS |
|---|---:|---:|---:|
| Plane | pass | **1.20 s** | **11,268 KiB** |
| MultiFaceSeam | pass | **2.01 s** | **11,224 KiB** |
| CloseSheets | pass | **15.35 s** | **13,576 KiB** |
| Cylinder | pass | **8.67 s** | **14,740 KiB** |

This closes the narrow M1g-discovered artifact-portability defect at the package/runtime boundary. It does not grant M1h semantic acceptance.

## 7. Historical/deferred producer reds

All eight stable historical/deferred reds were executed individually and retained their entering classes:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red;
- `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`;
- `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`;
- `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`;
- `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`;
- `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`;
- `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red;
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — unchanged `NotProductionReady:tracing producer=tracing/phase-front/InvalidHardRailPairing` path and downstream assertion reds.

No class drift attributable to M1h was observed. Nonzero periodic rotation remains rejected as `PeriodicHolonomyMismatch`; `G4-B003` remains unresolved.

## 8. Strict-validator timing characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` was executed in ten fresh processes:

- **0 pass**;
- **10 fail**.

Representative observed validation values remained sub-millisecond (`~0.00015 s` in most samples) while the 5% threshold varied with the similarly tiny remesh timing. This is the same already-deferred nondeterministic ratio microbenchmark defect; no threshold weakening or retry-based acceptance was used.

## 9. Bunny and Vase

The heavy Bunny/Vase comparison was **not launched** after the blocking M1h focused failure. The turn already lacked semantic acceptance, and the immutable package had shown no entering product-preservation regression across the complete non-heavy required-green partition, direct products, and historical red classifications. Launching the resource-heavy comparison could not make the blocked M1h contract acceptable.

The entering accepted M1g dispositions remain the comparison authority until a corrected M1h immutable package reaches a new Test + Benchmark turn:

- Bunny: known `NotProductionReady:completion` red;
- Vase: bounded safety-only at 60 seconds.

No new Bunny/Vase claim is made from this blocked turn.

## 10. Harness execution lesson

The first aggregate producer command used an incorrectly constructed GoogleTest negative filter with repeated `-` separators. That command unintentionally admitted excluded long-running product tests and was terminated by the external command bound. It was not used as product or acceptance evidence and did not alter packaged content.

The corrected partition used the required GoogleTest grammar exactly once:

```text
positive-pattern-negative1:negative2:...
```

and produced the authoritative **187 = 186 pass + 1 focused M1h failure** result above.

## 11. Immutable postflight

After all retained runtime evidence, postflight reverified:

- result ZIP SHA-256 `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03`;
- build-log ZIP SHA-256 `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`;
- `SHA256SUMS` digest `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9`;
- all **69/69** content checksums;
- 70 regular files, seven executables, two static libraries, 27 fixtures;
- producer and independent-oracle executable hashes unchanged.

No packaged regular file changed.

## 12. Regression disposition

M1h remains **runtime pending/blocked**, so `RP-01` and `RP-05` at the field-chart consumer are not yet marked immutable accepted.

The failing contract is a newly introduced test-authority defect, not loss of previously accepted product behavior. Under the regression tracker rules it does **not** create a new stable regression event or recurrence. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unchanged.

## 13. Mandatory next turn

Run **M1h Phase-Front Field-Chart Test-Authority Remediation — Code + Build only** under:

`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Plan.md`.

The next turn must correct the invalid focused-test witness without weakening the architectural contract, keep production M1h behavior unchanged unless a compile-time/source inconsistency is independently proven, compile/package only, and execute no generated Directional binary. A following immutable Test + Benchmark turn must re-prove all six M1h contracts and the complete preservation authority before M1h can be accepted.