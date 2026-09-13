# M4-CP3-TB7 Artifact-Only Test + Benchmark Plan

**Turn:** `M4-CP3-TB7-EXEC`
**Status:** FROZEN / NOT YET EXECUTED
**Immutable package:** artifact `10305678151` from run `34720182350`
**Artifact SHA-256:** `543fd253bf04bde38f16aac8c33a05447bf515f37027a077f6014ff13957a629`
**Semantic source:** `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`
**Selector403 SHA-256:** `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`
**Selector408 SHA-256:** `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`

## Immutable boundary

Use the packaged binaries and packaged source directly. No configure, rebuild, relink, source repair, fixture mutation, selector mutation, package repair, or replacement artifact is permitted. Verify artifact digest, 28/28 manifest, exact source, executable modes, GMP evidence, empty packaged source status, and a byte+mode preflight census before runtime; repeat the same census after runtime. Any mismatch is an immediate stop.

`TB7-EXEC` is execution/mechanical evidence only. It does not promote the candidate or reclassify semantics. `M4-CP3-TB7-REV` owns adjudication and promotion.

## Fail-fast execution order

Every focused identity runs in a fresh process and execution view, with exact selection count `1`. Any RED, SKIP, crash, timeout, selection mismatch, package/preflight/postflight mismatch, or unexpected mutation stops the turn immediately.

1. Ordinal138 A/B, two fresh exact-filter processes:
   `SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`
   Both must PASS and independently publish the accepted aggregate `UnsupportedSourceSheetTopology` contract with all three phase-front producers declined.
2. Row408 A/B, two fresh exact-filter processes:
   `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`
   Both must PASS `Produced` and preserve exact A2b/A3 occurrence-domain/shared-boundary receipts.
3. Rows404-407 A/B, eight fresh exact-filter processes; all must PASS:
   - `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt`
   - `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals`
   - `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback`
   - `SurfaceCellAuthorityContractCutover.A3SharedBoundaryCutoverPreservesA4LocalFamilyAndAdvanceSign`
4. Only after all 12 focused/control processes are GREEN, execute selector403 in fresh isolated processes and require **403/403 PASS**.
5. Only after selector403 is fully GREEN, execute selector408 in fresh isolated processes and require **408/408 PASS**.
6. Perform immutable postflight census and compare byte-for-byte/mode-for-mode with preflight.

No benchmark is required unless an existing frozen TB harness names one; no new performance gate is introduced by CB9.

## Falsifiers

- Ordinal138 RED: CB9 did not restore valid `<4 => NotApplicable` compatibility.
- Row408 RED: CB9 overcorrected and regressed accepted-cut occurrence-domain authority.
- Rows404-407 RED: A2b/A3 receipt or typed shared-boundary semantics regressed.
- Selector403 RED: candidate remains rejected even if focused witnesses pass.
- Selector408 RED: candidate does not recover the full frozen post-cutover surface.

On any falsifier, stop and route directly to `M4-CP3-TB7-REV`; do not repair inside EXEC.
