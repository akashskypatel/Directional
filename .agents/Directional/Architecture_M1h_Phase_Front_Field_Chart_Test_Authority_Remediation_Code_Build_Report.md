# M1h Phase-Front Field-Chart Test-Authority Remediation — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Result

The M1h focused-test authority defect exposed by the blocked immutable runtime turn is repaired at test scope only.

Production behavior remains the M1h implementation:

`de4e2ba7c19d2e49931655dc22d758f50656d054`

at the bounded seam:

`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

The remediation implementation is:

`32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`

and changes exactly one path:

`tests/SurfaceCellsPhase10Tests.cpp`

No production source, fixture data, validator threshold, product expectation, periodic behavior, fallback/recovery, topology/completion, optimization, or package-layout behavior changed.

M1h is **not semantically accepted** by this compile-only turn. Runtime acceptance remains mandatory.

## 2. Test-authority correction

The blocked test was:

`SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering`.

The prior witness incorrectly required the complete producer chart domain `{0,1,2}` to equal the set of chart identities sampled by accepted lattice-corner occurrences. Immutable runtime showed that the fixture's actual lattice occurrences cover only a subset while producer chart `1` still exists on face `3` and chart `2` on face `10`.

The corrected witness keeps the existing `SegmentRouteFixture` and separates three authorities:

1. **Producer numbering / compatibility authority.** A hard-authored source-face map derived from the fixture construction expects chart `0` generally, chart `1` on face `3`, and chart `2` on face `10`. Every emitted boundary segment is checked against that source-face expectation, and the producer compatibility domain must remain exactly `{0,1,2}`.
2. **Constructive-front occurrence authority.** Every actual `LocalLatticeState` must have a typed `FieldChartId`, and its value must equal the independently hard-authored producer chart for the paired `cell.corners[corner].face`.
3. **Coverage sanity.** Actual constructive-front occurrences must exercise more than the default chart, but the test no longer equates occurrence sampling cardinality with producer-domain cardinality.

The correction does **not** encode `{0,2}` as an expected chart domain or otherwise weaken `{0,1,2}` producer numbering semantics.

## 3. Source authority

| Evidence | Value |
|---|---|
| remediation implementation | `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` |
| source/event parent | `e7d8bda3db652b1765ebabd1e4a0e0766cb7865f` |
| base M1h production implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| accepted M1g implementation | `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` |
| changed path | `tests/SurfaceCellsPhase10Tests.cpp` only |
| changed-path diff | **+40 / -10** |
| remediated test blob | `71b991896846a486f29a550ddde4260748b03cd7` |
| tracing header blob | `102b2bbd3f57ec6b994cbe99b39c6d283eb0bf66` |
| tracing implementation blob | `0a8d85c20893ef65f2a2ba572096f2f38e2f652e` |
| pipeline blob | `db87264809b35e325ad6c8f44fabef6ddca3883a` |
| fixture-path helper blob | `4a981f772ee70780d0011696010a0e1b8bef6972` |

The four non-test M1h paths above are byte-identical to the prior M1h production package.

## 4. Build authority

GitHub Actions run/job:

`31404102605 / 93506073062`

Build configuration:

- Ubuntu 24.04;
- Release;
- static libraries (`BUILD_SHARED_LIBS=OFF`);
- Ninja;
- GMP enabled;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- tests and benchmarks compiled;
- CLI, GUI, Python, and tutorials disabled.

Approved targets compiled and linked **120/120**.

Build resource record:

- wall time **8:20.53**;
- peak RSS **1,850,456 KiB**;
- exit status `0`.

No generated Directional binary executed. No GoogleTest discovery/listing, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input executed.

## 5. Immutable package authority

| Evidence | Value |
|---|---|
| result artifact | `9069186973` |
| result ZIP SHA-256 | `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8` |
| log artifact | `9069187317` |
| log ZIP SHA-256 | `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a` |
| recursive `SHA256SUMS` | **72/72**, digest `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8` |
| package | **73** regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures |

The downloaded result artifact was independently checked for unsafe archive members, exact outer digest, exact recursive manifest digest, all **72/72** content checksums, package cardinalities, source/test blob authority, and build-authority metadata. The log artifact outer digest was independently verified as well.

Build authority records `productionSourceDelta=false` and every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input flag `false`.

## 6. Executable and library hashes

Executables:

- producer `937adceea641f372ee42eeb9a3b91c3bba2088847755cc234eaf0b3754f208ac`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `4cab6a23edd96029cddd804c49048b90163c432dc2e832ab9c8c6a597dff17f8`;
- compiled API `e43b293b1a85b5e49343683c5a427a7981eb9d4fd32ff88e69017b883c98c037`;
- benchmark `fe9da9533c60c2f5b5881ffb7dbaa8f5a5001623e3854bb943e0cc98d63c2c83`.

Libraries:

- `libdirectional_core.a` `1e1a4b7e01ba496e796dc8167e85644039399b0a6233f2c45910ff92dce31b46`;
- `libdirectional_pipeline.a` `ad23ed61a75a7167433de358cf90e299652a7be6d9ee4a8903a40b14a3ac0769`.

Only the producer executable hash changed relative to the previous M1h package, as expected from the test-source-only delta; production libraries and unrelated executables retain their previous hashes.

## 7. Static test inventory

Package metadata confirms:

- M1h focused: **6**;
- M1g: **6**;
- M1f: **6**;
- M1e: **6**;
- M1d: **6**;
- M1c: **6**;
- M1b: **6**;
- M1a: **14**;
- T1: **29**.

The static Code + Build gate also verified that the obsolete `typedCharts == {0,1,2}` occurrence assertion is gone, exact producer compatibility domain `{0,1,2}` remains asserted, source-face chart expectations remain hard-authored, no `{0,2}` expected set was introduced, and sibling `../test-data` lookup remains intact.

## 8. Regression disposition

This turn repairs a test-authority witness defect already identified by immutable runtime. It does not establish new runtime product behavior.

No new stable product regression event or recurrence is assigned from compile-only evidence. Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unchanged. M1h `RP-01 / RP-05` semantic acceptance remains pending until immutable runtime succeeds.

## 9. Mandatory next turn

Run **M1h Phase-Front Field-Chart Test-Authority Remediation — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`

Consume only exact artifacts `9069186973 / 9069187317` from remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`. Rebuild, relink, configure, regeneration, source/test/build/fixture edits, repair, substitution, and runtime fixture symlinks are prohibited.

Expected runtime authority remains producer discovery **202**, M1h focused **6/6**, and required-green producer **187/187**, followed by all entering preservation/product/historical-red/heavy-case/postflight gates.
