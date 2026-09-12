# M4-CP3-TB3 Test + Benchmark EXEC Report — exact A3→A4 shared-boundary acceptance

**Turn:** `M4-CP3-TB3-EXEC`
**Status:** COMPLETE / VALID ARTIFACT-ONLY EXECUTION / FOCUSED-A RED AT ROW408 / REVIEW REQUIRED
**Runtime package:** CB5 artifact `10290933668`
**Semantic source:** `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`
**Accepted predecessor:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`
**Candidate selector:** selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`

## 1. Execution authority

The authoritative TB3 execution is GitHub Actions run/job:

```text
run                  = 34671972132
execute job          = 103494923768
result artifact      = 10291076362
result artifact SHA  = 56158d759bf7827e33a51ce04fcd67bba960f68fea7486893fdf14936d96f388
log artifact         = 10291146242
log artifact SHA     = 93d56c5c8fc76f4d9ab1210183ce6aa57ecab25479f01b3e31b5ec78c33de5b1
```

The workflow schema validator passed before execution. The package was downloaded by immutable artifact ID and its provider size/digest, outer ZIP digest, 28-entry manifest, source commit/archive, GMP evidence, owner binaries, executable modes, selector hashes/prefix, static unique owner mapping, and execution-view staging were verified before runtime.

A prior orchestration-only attempt `34671851965 / 103494592879` executed **0 Directional tests**. Its preflight rejected an over-specific static row408 source-string check (`globalTopologyPlan` / `globalConformityBaseline`) that was not part of the frozen semantic predicate. The temporary executor was corrected without package/source/test/selector mutation. That attempt has no semantic authority.

## 2. Frozen process matrix result

The frozen plan authorized exactly 821 fresh exact-filter processes, fail-fast on the first RED. The authoritative run reached focused pass A and stopped at row408:

| Phase | Planned | Executed | PASS | RED | SKIP | Timeout |
|---|---:|---:|---:|---:|---:|---:|
| rows404-408 focused A | 5 | 5 | 4 | 1 | 0 | 0 |
| rows404-408 focused B | 5 | 0 | 0 | 0 | 0 | 0 |
| accepted selector403 | 403 | 0 | 0 | 0 | 0 | 0 |
| candidate selector408 | 408 | 0 | 0 | 0 | 0 | 0 |
| **total** | **821** | **5** | **4** | **1** | **0** | **0** |

Each executed process selected exactly one named test. Rows404-407 each emitted exactly one `[ RUN ]`, one matching `[ OK ]`, exit `0`, and zero skips. Row408 emitted exactly one `[ RUN ]`, exit `1`, zero matching `[ OK ]`, and zero skips.

## 3. Focused outcomes

### 3.1 Rows404-407 — PASS

The following new candidate identities are green in fresh exact-filter processes:

1. `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt`
2. `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals`
3. `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback`
4. `SurfaceCellAuthorityContractCutover.A3SharedBoundaryCutoverPreservesA4LocalFamilyAndAdvanceSign`

TB3-EXEC records those raw outcomes only; it does not promote their semantics independently of Review.

### 3.2 Row408 — RED

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity` failed at its first production-phase-front assertion:

```text
expected phaseFront disposition = Produced
actual phaseFront disposition   = NotApplicable
terminal diagnostic             = NotProductionReady/tracing/None
```

The test therefore did not reach its subsequent `conformityPlanReceipt`, exact shared-interval, or `InvalidHardRailPairing` assertions. EXEC makes no causal classification; that belongs to Review.

## 4. Immutable postflight

Postflight passed after the RED:

```text
package_immutable        = PASS
source_immutable         = PASS
execution_view_immutable = PASS
manifest_post             = 28/28
selector403_immutable     = PASS
selector408_immutable     = PASS
configure                 = false
compile                   = false
relink                    = false
generated_discovery       = false
package_repair            = false
```

No source, fixture, selector, package, executable, or execution-view bytes were changed by TB3.

## 5. EXEC disposition

`M4-CP3-TB3-EXEC` is complete as a valid fail-fast raw execution turn. It is **RED** because row408 failed, and the remaining 816 planned processes were correctly not executed after the frozen fail-fast stop.

The candidate CB5 package/selector408 are **not promoted**. Corrected R4 artifact `10289601000` / selector403 remains accepted runtime authority until Review adjudicates the row408 RED and the unexecuted predecessor/cumulative gates.

**Mandatory successor:** `M4-CP3-TB3-REV`.
