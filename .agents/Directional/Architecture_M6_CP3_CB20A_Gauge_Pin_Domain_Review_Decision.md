# RA-113 — CB20 and CB20A accepted: corrected gauge-pin domain compiled; TB20 authorized (2026-10-21)

**Turn:** `M6-CP3-CB20A-RP01-GAUGE-PIN-DOMAIN-REV`. **Input:** CB20A source `e22c5da5f8ab86a39650c670340a658847a2ac7e` and compile run [39520787768](https://github.com/akashskypatel/Directional/actions/runs/39520787768). The agent left CB20A `IN_PROGRESS` after a green compile and wrote no record. This decision holds the verified package facts, as RA-109 did for TB19. **Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `e22c5da5f`; `src`, `include` and `tests` at HEAD are identical to it.

## RA-113.1 Package verified independently

- **Artifact:** `12310848591`, ZIP SHA-256 `0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`, which equals the provider digest. It expires 2026-10-28T00:23:30Z.
- **Manifest:** `SHA256SUMS` lists 28 entries, all 28 verify, and the package holds exactly 28 other files.
- **Source and boundary:**
  - `source-commit.txt` is `e22c5da5f`;
  - the tarball's S and TQ are byte-identical to git at that commit;
  - all five `source-status-*` files are empty.
- **Build:**
  - `build-exit-code` is 0, and the build log has no warnings;
  - eight targets were compiled, with `directional_core` as the preflight target;
  - `DIRECTIONAL_ENABLE_GMP=ON`, and GMP and GMPXX are linked;
  - `runtimeExecution=false`, `exactArithmeticBackend=GMP`.
- **Content:** `directional_surface_cell_producer_tests` contains the two new test names, and the site string `gauge-pin-span;region=` is linked from `libdirectional_core.a`.

## RA-113.2 CB20A diff matches RA-112.5

- **Items 1–2 only.** `git diff 7dc9b89ec e22c5da5f -- src include` is empty, and TQ changes by +9/−12:
  - the five accessor lines (TQ:1941, 1947, 1972, 1978, 1979);
  - `RegionGaugeShiftPassesPin`, which now asserts a `SurfacePhaseFrontProduct` and prints the error site on failure.
- The widest changed line is 89 columns.
- The S patch from CB20 (RA-112.2) is unchanged, so the count of 48 labels stands.
- **CB20 and CB20A are accepted as one compiled unit.** This acceptance is static and covers compilation only. Runtime acceptance belongs to TB20.

## RA-113.3 TB20 rows (26)

All 26 rows run in `directional_surface_cell_producer_tests`.

**M2 — 9 rows; baseline RED at the pin (TB19/TB19A):**
- `cp3entry:1` `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`
- `cp3entry:2` `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`
- `cp3entry:6` `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`
- `focused30:6` `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`
- `focused30:12` `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`
- `focused30:20` `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`
- `focused30:24` `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`
- `selector:446` `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
- `selector:447` `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`

**M1 — 10 rows; baseline RED, the TB19 first failures:**
- `focused30:3` `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
- `focused30:22` `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames`
- `focused30:23` `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport`
- `selector:139` `SurfaceCellAuthorityContractCutover.HardRailPairChangedRouteContentRejectsStrictTransport`
- `selector:140` `SurfaceCellAuthorityContractCutover.HardRailPairExplicitRailIdMismatchRejectsStrictTransport`
- `selector:142` `SurfaceCellAuthorityContractCutover.HardRailPairSameOrientationRejectsStrictTransport`
- `selector:211` `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`
- `selector:219` `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected`
- `selector:227` `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed`
- `selector:230` `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed`

TQ lines in TB19's first failures map to HEAD by +77. Review checked all seven cited lines: 5036→5113, 5828→5905, 5869→5946, 8579→8656, 8600→8677, 9702→9779, 9722→9799.

**Controls — 3 rows; baseline PASS:**
- `selector:217` `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`
- `TB18 A#14` `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags`
- `selector:443` `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`

**Suite — 3 rows; new:**
- `SurfaceCellFactoryRejectionSite.OneFaceGaugePinNamesSourceEdge`
- `SurfaceCellFactoryRejectionSite.RegionGaugeShiftPassesPin`
- `SurfaceCellFactoryRejectionSite.HardEdgeIsolatingFaceRejectsAtSpan`

**Oracle — 1 row; baseline RED in R4 (2026-10-15), outside selector 497; recorded only:**
- `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome` (TQ:2833 at `d2c7483cd`, the RA-111.4 uniform-rotation oracle).

## RA-113.4 Predictions TB20-REV will adjudicate

- **P1.** All three suite rows PASS (RA-112.4).
- **P2.** No row rejects at `gauge-pin-consistency` on edge `1,4`, `4,7` or `0,3`. Those edges are hard, so they are now outside the domain. Any such site falsifies CB20.
- **P3.** No row's printed site is `gauge-pin-span;…`, because regions are spanned by construction. A span site, or a `gauge-pin-consistency` site on a non-hard edge, would bear on RA-111.5's cut-set question.
- **P4.** The three controls PASS. A control turning RED is a regression.
- **Not predicted:**
  - the new first failure of each M2 row, which determines the RA-103.5 R-route;
  - the M1 rows. Each is compared with its TB19 first failure after the +77 mapping, and any change is recorded for Review to classify;
  - the oracle.

## RA-113.5 Next unit — `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN` (Test + Benchmark, artifact-only)

1. **Harness.** Create `.agents/Directional/tools/m6_cp3_tb20_gauge_pin_domain_harness.sh` from the TB19A harness. Its diff from TB19A is limited to:
   - `sha`, `artifact` and `digest` (RA-113.1);
   - the 26-row table from RA-113.3, whose fourth field is the baseline: TB19 or TB19A status, `R4 RED` for the oracle, `new` for the suite;
   - the count 7→26;
   - the `TB19A` labels and ledger header → `TB20`, and `TB18` → `baseline`.

   Fixture staging, frozen-selector checks, manifest and immutability checks stay as they are.
2. **Run.** Dispatch the harness once against artifact `12310848591` before it expires (2026-10-28T00:23:30Z).
3. **Report.** Write `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Harvest_Report_20261021.md`. It contains:
   - the run, artifact and digest;
   - the 26-row table: status, first failure, product, detail, site and raw SHA-256;
   - for each M1 row, whether its first failure equals TB19's after the +77 mapping;
   - P1–P4 marked observed or not observed. The report does not interpret the M2 outcomes.

**Out of scope:**
- any source, test, selector or workflow change;
- any repair;
- accounting changes;
- the M1 binding.

**STOP and return to Review** on any of:
- a digest or manifest mismatch;
- a missing fixture;
- a selection count other than 26 single-identity runs;
- a harness failure.

There is no second harness repair inside the turn.

**On success:** `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN-REV` (Review). It adjudicates P1–P4, determines the R-route and decides whether a selector-497 regression run must precede the M1 DEFN.

## RA-113.6 Sequence and accounting

> *Closed by RA-114 (2026-10-21): TB20 confirmed P1–P4; the R-route falsifier is not observed; TB21 (selector-497 census) is next.*

- **Sequence:** CB20 → CB20-REV (RA-112) → CB20A → CB20A-REV (RA-113) → **TB20** → TB20-REV → [selector-497 regression run, if TB20-REV requires it] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
