# M1g Periodic Holonomy Route Transport Consumer — Artifact-Only Test + Benchmark Report

**Status:** immutable accepted  
**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Result

M1g is **immutable accepted** at the selected production transport owner:

`periodic canonical face cycle -> ordered source-edge crossings -> whole-cycle holonomy decision`.

The exact compiled implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` was validated only from immutable result artifact `9053047653`. No source, implementation, test, fixture, validator, benchmark, or build logic was rebuilt, relinked, regenerated, repaired, patched, or substituted during runtime validation.

All mandatory M1g semantic and preservation gates passed. Nonzero whole-cycle rotation still fails closed as `PeriodicHolonomyMismatch`; M1g does **not** implement `G4-B003`. The eight stable historical/deferred producer reds retained their entering classes. Bunny retained the known completion failure, Vase retained its bounded safety-only disposition, and the strict-validator 5% timing test remained a nondeterministic microbenchmark defect. No new stable regression event or recurrence was created.

## 2. Immutable package authority

| Evidence | Value |
|---|---|
| implementation | `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` |
| accepted M1f ancestor | `baed0f24831c476f45a1b742c12314e3fb03e10e` |
| build run/job | `31362470744 / 93373936472` |
| result artifact / ZIP SHA-256 | `9053047653` / `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c` |
| build-log artifact / ZIP SHA-256 | `9053048092` / `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9` |
| recursive content manifest | **64/64**, `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae` |
| package | **65** regular files; 7 executables; 2 static libraries; 27 fixtures |
| build | **120/120**, Release/static/Ninja/PRE_TEST |
| Code + Build runtime | **false** |

Preflight verified safe archive members, both outer artifact digests, the exact manifest digest and all **64/64** packaged checksums, package cardinalities, build-authority metadata, exact source/test/policy blobs, source archive/patch presence, and executable hashes before any packaged binary ran.

Executable SHA-256 authority:

- producer `ecb53fc658be166d52bc66fb66bb835ff6c8510e1a27b545aeb7378dfaffa5fd`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `08432de31070d878a9839d04efdf83e77dc499045214a71abf6b7555653329c1`;
- compiled API `b76d6511dfcb60dd763d0f4e90f9ca3639c2bcfc7ccc0ff05988c8280de35667`;
- benchmark `9945050030b7822d492207ca6b491a3707a2490c8e8c80c28abc53d21d0ccf37`.

## 3. Native discovery authority

Package-native discovery from the exact artifact produced:

- producer: exactly **196** tests;
- validation: exactly **77** tests;
- M1a authority kernel: exactly **14** tests;
- T1 independent oracle: exactly **29** tests.

The producer count is the accepted M1f 190 plus exactly six M1g periodic-holonomy route contracts.

## 4. M1g focused contracts — 6/6

Each `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration` contract executed in a fresh process and passed:

1. `NonzeroStepsComposeToZeroWholeCycle`;
2. `ReverseObservedCycleUsesExactTransportInverse`;
3. `EquivalentSignedRepresentationsNormalizeSemantically`;
4. `RouteTopologyAndCompactIdentityIgnoreFaceRowOrder`;
5. `MalformedAuthoritativeCrossingProvenanceFailsClosed`;
6. `LegacyMatchingPathUsesSameTypedAlgebra`.

This proves the intended representation-only migration: checked source-step identity, canonical topology, exact inverse/quarter-turn composition, observed-route ordering, legacy-path equivalence, and fail-closed malformed provenance. It does not change periodic cycle discovery or permit nonzero whole-cycle rotation.

## 5. Preservation gates

All entering architecture/test authority passed from the exact M1g package:

| Gate | Result |
|---|---:|
| M1f focused | **6/6** individually |
| M1e focused | **6/6** individually |
| M1d focused | **6/6** individually |
| M1d route counterexamples | **3/3** |
| M1c focused | **6/6** individually |
| M1c transition counterexamples | **3/3** |
| M1b focused | **6/6** individually |
| ordered source-vertex fan witnesses | **2/2** |
| validation | **77/77** |
| M1a | **14/14** |
| T1 independent oracle | **29/29** |

The exact producer executable discovered **196** tests. The required-green partition excluded only the four direct product cases, eight historical/deferred reds, Bunny, Vase, and the deferred strict-validator timing test. Required-green producer result: **181/181 passed**, approximately **22.09 s** aggregate wall time with observed peak RSS **23,492 KiB**.

No failed required-green test was relabeled, skipped, weakened, retried into acceptance, or replaced by fallback/synthetic output.

## 6. Artifact portability characterization

The packaged binaries contain all required fixtures, but `tests/TestFixturePaths.h` currently first searches `test_executable_directory()/test-data`, while the immutable build package places fixtures at the package root beside `bin/` (`../test-data`). On an arbitrary extraction directory this caused initial fixture-open failures in focused tests and the aggregate manifest test.

This was treated as an **environment/setup failure**, not product evidence. Runtime validation used one runtime-only symlink outside packaged regular content from the compile-runner compatibility path to the immutable packaged fixture directory. After that setup, all required tests passed. No packaged file, manifest, source, fixture, executable, or library was modified.

The next Code + Build turn must correct this narrow portability defect by making `test_data_root()` recognize the packaged sibling `../test-data` layout before falling back to `DIRECTIONAL_TEST_SOURCE_DIR`. Test semantics and fixture contents must not change.

## 7. Direct product authority

The four committed direct production cases executed separately from the exact artifact and passed their packaged independent product-oracle assertions:

| Product | Result | Wall | Peak RSS |
|---|---:|---:|---:|
| Plane | pass | **1.20 s** | **10,964 KiB** |
| MultiFaceSeam | pass | **1.90 s** | **11,008 KiB** |
| CloseSheets | pass | **15.72 s** | **13,508 KiB** |
| Cylinder | pass | **8.49 s** | **14,548 KiB** |

The M1g package also corrects the prior checksum-valid stale names in `metadata/direct-product-test-names.txt`; all four entries are the existing parameterized product test names.

## 8. Historical/deferred producer reds

Eight stable historical/deferred producer reds were executed individually and retained their entering classes:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red;
- `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`;
- `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`;
- `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`;
- `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`;
- `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`;
- `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red;
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — unchanged `NotProductionReady:tracing producer=tracing/phase-front/InvalidHardRailPairing` path and downstream expectations.

No M1g failure class drift was observed.

## 9. Strict-validator timing characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` was characterized in ten fresh executions from the exact package:

- **1 pass**;
- **9 fail**.

A representative failing sample compared validation time approximately `0.000157804 s` against a 5% threshold of approximately `0.000123634 s`. Together with M1e **6/10 pass, 4/10 fail** and M1f **9/10 pass, 1/10 fail**, this remains a sub-millisecond ratio-based performance-test defect rather than stable product evidence. No threshold weakening or retry-based acceptance is authorized.

## 10. Bunny and Vase — bounded GitHub Actions artifact-only evidence

Long/resource-heavy cases used the permitted artifact-only GitHub Actions execution plane. Run `31394985769` downloaded artifact `9053047653` directly, verified API digest/ZIP/manifest/build authority/producer authority before runtime, and reverified exact package authority after runtime. No checkout, configure, compile, link, relink, code generation, fixture regeneration, source/test edit, or package repair occurred.

### Bunny

- job `93475574330`;
- exact BunnyRandom product test reached `[ RUN ]`;
- runtime approximately **82.72 s**;
- peak RSS **341,744 KiB**;
- rc `1`;
- independent product oracle rejected first with empty/non-quad/component/Euler/output-origin/terminal-failure evidence;
- unchanged terminal followed: `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`;
- immutable postflight passed;
- evidence artifact `9065273769`, ZIP SHA-256 `127925800f25b896738bea59d2c42ea919513139cab32fd7c5389b012219612b`;
- dedicated log artifact `9065273267`, ZIP SHA-256 `9f30d95a712614c661936e2c8d27f14dfbd93ff8bde86ed56fb10bc00948bbd4`.

Disposition: **known-red preserved**. This is not an M1g regression.

### Vase

- job `93475574119`;
- exact Vase product test reached `[ RUN ]`;
- bounded at **60.00 s**;
- peak RSS **71,356 KiB**;
- rc `124`;
- no synthetic pass/failure classification was imposed after the bound;
- immutable postflight passed;
- evidence artifact `9065263527`, ZIP SHA-256 `72cfccb2d84859a3788098cffd5722be5927c3d394629b714d201f87e918a4b3`;
- dedicated log artifact `9065262959`, ZIP SHA-256 `1b1ec6fcb3ccc5acfd4cb6b2938ea1f89c362ef1ec05b12ad90a72e3f149c6b2`.

Disposition: **bounded safety-only preserved**.

The temporary runtime workflow was removed before its trigger marker. Final workflow inspection again leaves only `.github/workflows/agent-source-snapshot.yml`.

## 11. Immutable postflight

Postflight reverified:

- result ZIP SHA-256 exactly `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c`;
- build-log ZIP SHA-256 exactly `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9`;
- `SHA256SUMS` exactly `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae`;
- every **64/64** content checksum;
- 65 regular files, seven executables, two static libraries, 27 fixtures;
- all seven executable hashes listed above.

Both remote heavy-case jobs independently repeated preflight and postflight authority checks. No packaged regular file changed during runtime.

## 12. Architecture acceptance and regression disposition

M1g accepts the bounded `RP-01`, `RP-05`, and `RP-07` periodic whole-cycle transport boundary while preserving `RP-02 / TA-05` independent authority.

Historical totals remain **34 regression events / 14 categories / 20 recurrences**. No M1g stable regression event or recurrence is added.

`PR8-R034 / G4-R007` remains active and unchanged. `G4-B002`, `G4-B003`, and `G4-B004` remain unresolved. M1g does not repair direct-torus topology, shared hard-rail scheduling, nonzero periodic Z4 capability, multi-isolation materialization, Bunny/Vase production completion, fallback/recovery, optimization, or M2–M6.

## 13. Fresh next-owner inspection

Fresh read-only inspection of accepted M1g source found the next bounded M1 authority seam in phase-front field-chart production:

`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

The producer currently constructs connected equal-orientation field charts as bare integer IDs and carries those integers into constructive-front lattice state. `authority::FieldChartId` already exists, but production has not adopted it. This is a real semantic owner because the phase-frame producer creates the chart partition and the lattice state consumes that chart identity; wrapping unrelated downstream integers would not satisfy M1.

The next Code + Build turn is **M1h Phase-Front Field-Chart Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Plan.md`.

M1h is representation/authority migration only. It must preserve chart partitioning/numbering, phase/lattice values, front topology, public compatibility output, direct products, periodic rejection behavior, and all current G4 outcomes. `SurfaceTraceSegment::sourceChart`, public schema retirement, chart-relation certificates, M2–M6, G4 repair, nonzero periodic Z4 support, and feature expansion remain explicit non-goals unless the plan names a required compatibility touchpoint.
