# RA-107 — CB19A accepted; TB19 specified exactly (2026-10-20)

**Turn:** `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE-REV`. **Inputs:**
- CB19A source `d2c7483cd`;
- compile run `39446712217` at `513f944c5`, whose src/include/tests/CMake are identical to `d2c7483cd`;
- package `12275794192`;
- record `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`.

**Base:** `3bd24682c`. **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`. **Amends:** RA-105.6 and RA-106.5, which this record replaces as the TB19 specification.

## RA-107.1 CB19A accepted

- **Package.** The provider digest `sha256:e4a39cdb…d723a` matches the record. The run concluded `success`. The package expires **2026-10-27T15:24Z**.
- **Diff against `3bd24682c`:**
  - header +2/−0;
  - S +73/−0, so `make` is insertions only;
  - TQ +60/−1. The one removed line is the authorized TQ:4980 assertion.
- **Labels.**
  - All 47 labels match CB19's, one by one, in both clause name and suffix kind: 19 plain, 2 pin, 9 certificate, 9 endpoint and 8 junction.
  - Every `InvalidSourceAuthority` return is still labelled.
  - The three lambdas are as RA-106.3 gives them.
  - No line of `make` is longer than 100 columns.
- **Test.** The new test now requires both edge vertices to be corners of face 0, as RA-106.4 requires.
- **Not re-derived here.** The 28/28 packaged hashes are the agent's claim. The TB19 harness re-verifies them before it executes anything.

## RA-107.2 Defects in the TB19 specification, corrected before it runs

1. **Line drift.** Several M1 first failures cite TQ line numbers, and CB19/CB19A shifted TQ. RA-105.6's "byte-identical to TB18" would therefore fire on every one of them.
   - Mapping from a base line L to its CB19A line:

     | Base TQ line L | CB19A line |
     |---|---|
     | ≤ 441 | L |
     | 442–1880 | L + 11 |
     | 1881–4979 | L + 53 |
     | 4980 | the rewritten assertion |
     | ≥ 4981 | L + 59 |

   - First failures that are exception text stay byte-identical.
2. **Duplicate identity.** `selector:217` is the same gtest as TB18 Part A #12. It runs once.
3. **Harness.** The TB18 Part A harness hard-codes its package, source and 14 tests. TB19 authors one new harness derived from it (RA-86 precedent); see RA-107.3.
4. **M1 is a no-regression check, not a site measurement.** The M1 assertions do not stream the site. M1 rests on the RA-105.3 static proof.
5. **`focused30:12` made exact.** `hard_rail_fixture()` has rail carriers (1,4) and (4,7), and these are its only cross-region interior edges. Its relabelled region can fail the pin only there.
6. **Expiry.** TB19 must run before the package expires. If it has expired, STOP; there is no rebuild inside TB19.

## RA-107.3 TB19 — `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (artifact-only)

### Harness

> **Amended by RA-108.2 and RA-108.5:** the template stages fixtures one level too high, so the six torus rows were not measured. TB19A reruns them with the staging fixed.

- **File:** new `.agents/Directional/tools/m6_cp3_tb19_factory_rejection_site_harness.sh`, a copy of `open_rail_interior_vertex_harness.sh` changed only as follows:
  - **pinned inputs:**
    - source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`;
    - artifact `12275794192`;
    - digest `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`;
  - **test list:** the 22 rows below, with group and identity labels;
  - **extraction:** pull `product=`, `detail=` and `site=` from each raw log into the ledger, alongside the RA-90.4 first failure.
- **Unchanged from the Part A harness:**
  - the package and manifest checks (28);
  - the frozen-selector hashes;
  - the GMP and `runtimeExecution=false` checks;
  - the one-test-per-filter `GTEST_FAIL_IF_NO_TEST_SELECTED=1` execution;
  - the postflight immutability check.
- **Executable:** all 22 run in `directional_surface_cell_producer_tests`, per the selector-449 routing receipt and the TQ/P10 target.

### Identities

| # | Group | Identity | gtest | TB18 | Prediction |
|---|---|---|---|---|---|
| 1 | M2 | `cp3entry:1` | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | RED | RED; `product=0 detail=none site=gauge-pin-consistency;edge=…` |
| 2 | M2 | `cp3entry:2` | `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` | RED | RED; record product, detail and site (no prediction) |
| 3 | M2 | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | RED | RED; record (no prediction) |
| 4 | M2 | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RED | RED; as #1 |
| 5 | M2 | `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | RED | RED; `product=0 site=gauge-pin-consistency;edge=1,4` or `edge=4,7` |
| 6 | M2 | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | RED | RED; as #1 |
| 7 | M2 | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | RED | RED; as #1 |
| 8 | M2 | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | RED | RED; as #1 |
| 9 | M2 | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | RED | RED; as #1 |
| 10 | M1 | `focused30:3` | `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints` | RED | RED; TB18 exception text, identical |
| 11 | M1 | `focused30:22` | `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` | RED | RED; TQ:5769 → 5828 |
| 12 | M1 | `focused30:23` | `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` | RED | RED; TQ:5810 → 5869 |
| 13 | M1 | `selector:139` | `SurfaceCellAuthorityContractCutover.HardRailPairChangedRouteContentRejectsStrictTransport` | RED | RED; identical exception |
| 14 | M1 | `selector:140` | `SurfaceCellAuthorityContractCutover.HardRailPairExplicitRailIdMismatchRejectsStrictTransport` | RED | RED; identical exception |
| 15 | M1 | `selector:142` | `SurfaceCellAuthorityContractCutover.HardRailPairSameOrientationRejectsStrictTransport` | RED | RED; identical exception |
| 16 | M1 | `selector:211` | `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected` | RED | RED; TQ:8541 → 8600 |
| 17 | M1 | `selector:219` | `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected` | RED | RED; TQ:8520 → 8579 |
| 18 | M1 | `selector:227` | `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed` | RED | RED; TQ:9663 → 9722 |
| 19 | M1 | `selector:230` | `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed` | RED | RED; TQ:9643 → 9702 |
| 20 | control | `selector:217` (= TB18 A#12) | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | PASS | PASS |
| 21 | control | TB18 A#14 | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` | PASS | PASS |
| 22 | control | new | `SurfaceCellFactoryRejectionSite.OneFaceGaugePinNamesSourceEdge` | — | PASS |

TB18 first failures come from `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`.

### Falsifiers, and what is not one

**Falsifiers.** Report each as held or fired:
- **F1** — any status that differs from the table.
- **F2** — `PublishedProductRejected` with `product=0` and an empty site.
- **F3** — a torus site (#1, #4, #6–#9) that is not `gauge-pin-consistency`. Or `focused30:12` whose site is not that label, or whose edge is not (1,4)/(4,7).
- **F4** — an M1 first failure that differs from TB18 after the RA-107.2 mapping.

**RA-103.5 R-route falsifier.** It fires if `cp3entry:2` or `cp3entry:6` reports an `endpoint-*` site with `kind=R`. Record the site verbatim.

**Not falsifiers:**
- a non-zero `product=` on `cp3entry:2/6`. Record it; TB19-REV decides any follow-up under RA-106.5;
- differences in pointer addresses.

### Boundary and output

- **Allowed:** the new harness file and its dispatch only.
- **Forbidden:**
  - compiling or relinking;
  - changing source, tests, selectors or fixtures;
  - benchmarks;
  - test discovery beyond the per-filter selection;
  - any repair.
- **Output:** a report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_<date>.md` containing:
  - the run, the artifact and the ZIP SHA-256;
  - manifest counts;
  - a 22-row ledger with TB18 status, TB19 status, mapped first failure, product, detail, site and raw-log SHA;
  - a held/fired line for each falsifier.
- **No adjudication.** The report draws no conclusions on H-pin or on the R-route; TB19-REV decides those.
- **STOP:** any harness verification failure, an expired package, or fewer than 22 identities selected. Preserve the evidence and return to Review.

## RA-107.4 Sequence and accounting

- **Sequence:** TB19 → TB19-REV (mandatory; rules on H-pin, on the `cp3entry:2/6` clause and on the RA-103.5 R-route falsifier, and orders the DEFN) → [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
