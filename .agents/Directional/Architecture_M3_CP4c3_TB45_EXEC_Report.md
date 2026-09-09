# M3-CP4c-3-TB45 EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / RAW EVIDENCE PRESERVED / SEMANTIC REVIEW PENDING

**Turn:** `M3-CP4c-3-TB45-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-09

## 1. Authority and immutable input

TB45-EXEC consumed immutable CB50 package110 exactly as frozen. It did not configure, compile, relink, regenerate discovery,
repair package bytes or modes, mutate source/tests/fixtures/selectors, or run benchmarks.

- semantic source: `46554ef2bc1b36fff100e4de0a274a0fb6d3f26d`;
- immutable package110 artifact: `10095738820`, `m3-cp4c3-cb50-package110-result-34330825605`;
- provider/download SHA-256: `7edc47632dbd863508c97d5716dd9df5e469671e0b327a133848ff3c37142000`;
- packaged source archive SHA-256: `8ae8fcd115c5b150642ad090272a001de89520d28ba69c2564cd476473374e80`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, 409 rows;
- accepted-prefix selector count: 365;
- generic artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- package root manifest: 28/28 verified;
- per-identity control: `timeout -k 5s 180s`;
- outer elapsed cutoff: none.

## 2. Execution evidence

Authoritative workflow run `34357709483`, event SHA `4faafa8b0739cfbdb244de09c1ccb70b62ca5a58`, completed
successfully. The artifact-only execute job is `102486495110` and completed successfully.

- result artifact: `10106632656`, `m3-cp4c3-tb45-result-34357709483`, digest
  `sha256:15327d9f3211f9b28b358e380b9b19917813362982f0b8cb94422b4518eff18a`;
- persistent log artifact: `10106633518`, `m3-cp4c3-tb45-log-34357709483`, digest
  `sha256:2d4a0b0dd975f8f50a3b7e9161f67a71ccf2de5c46494c8c7715228dd3e23db8`;
- observer log artifact: `10106441406`, digest
  `sha256:6130cc643a10fd15e253e7fbafaca705d1fbb6c64bb3fcec734cc83feb72b0ba`;
- all 409 selector identities executed exactly once in ordinal order, one fresh process per identity;
- selection mismatches: 0;
- timeout count: 0;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

The downloaded result and log artifacts independently hash to their provider digests above.

## 3. Raw measured result

TB45 measured:

- **409 total**;
- **399 PASS / 10 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[367,368,369,370,374,390,393,398,406,407]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256: `8495191680a23573e636cc01fd9052e1992d53f1c3f4d7dca0c77c02ad2ff50d`;
- failure-detail table SHA-256: `1c8635d38c997dca5dc29da3b1aed8a45b17ea4d5a0c75ca30640b3cdb73782f`.

This is raw EXEC evidence only. TB45-EXEC does not promote this vector over TB44, merge or reprice regression events,
or authorize a corrective implementation. Independent `M3-CP4c-3-TB45-REV` owns semantic adjudication.

## 4. CB50 direct falsifier — 366 / 367

Ordinal 366 changed from TB44 RED to **PASS**. Ordinal 367 remains RED, but the TB44 target failure does not reproduce.
Across both 366 and 367 raw logs:

- `FragmentCornerSourceCornerMismatch`: 0 occurrences;
- `FragmentCornerRayOrdinalDuplicate`: 0 occurrences;
- `FragmentCornerOrbitChainMismatch`: 0 occurrences;
- exact failure-detail token `sourceFace=10,11,79`: 0 occurrences.

Ordinal 367's first retained assertion surface is now the independent rotation/face-walk oracle:
`partition.has_value() == false`, reported as `FragmentPartition` at `FieldAlignedCurveNetworkTests.cpp:9282`.
Its failure-detail SHA-256 is `d3ead838dda0238aa51b4efc4eda5e0a0636050b6447ed4938774ee59552c83c`.

Mechanically, the frozen CB50 falsifier is satisfied in the narrow EXEC sense: the whole-face/source-corner mismatch is absent,
366 passes, and 367 advances to a different later oracle surface. EXEC does not decide the semantic meaning or owner of the
ordinal367 `FragmentPartition` failure.

## 5. Protected identities — 390 / 393 / 406 / 407

All four protected identities remain RED, but their raw first assertion surface changed. Each now fails at the fixture precondition
`ASSERT_FALSE(mechanical.plan.has_value())` because `mechanical.plan.has_value()` is **true**. The assertions are at lines
12145, 12340, 15153 and 15206 respectively in the frozen CB50 test source.

Because each identity terminates at that precondition, its raw log contains zero occurrences of the later Part XII receipts
`branch=UncutCensus`, `censusPredicateExecuted=yes`, `sameDomainCorruptionRejected=yes`, `terminalSubjectBranch=...`, and
`regionCertificationEvidenceBranchExecuted=yes`.

Failure-detail SHA-256 values:

- 390: `8e902d51db041e3f2613bf3148bcadc5cb1b11c039bc5beb57cf1bee4a738397`;
- 393: `4c71964fc59440c8d63ed98836dcfd89c4643a939ff3d5fbd95ad400b68f5f88`;
- 406: `6931c106bfeaa0083cfc4aa65641915775c4ac8a38ce55cbed77af308e44cf66`;
- 407: `a353d5585043c1d9a11805bf9e3c315f77bef89c2cff526cb9de9a6234d55fed`.

This is a mechanically observed execution-path change, not an EXEC-time diagnosis. The frozen terminal-subject helper obligation is
therefore not runtime-demonstrated by these four identities in TB45; independent TB45-REV must adjudicate the now-successful
mechanical plan precondition and the oracle's continued authority.

## 6. Carried REDs and frozen controls

The five separately owned carried RED ordinals remain RED at their previously visible behavior classes:

- 368: prescribed-sphere `CellularityNotEstablished/origin=RotationSystemInconsistent`, originating reason
  `TraceEventPositionInvalid` / `NoCarrierMatch`;
- 369: `certificate.saturationUsed=true` where the identity expects false;
- 370: empty-network typed rejection still lacks the required source-face locus;
- 374: `atlasBuild=false`;
- 398: prescribed-sphere `NotProductionReady/CellularityNotEstablished`.

Frozen controls 311/312/314/315/356/357/404/408/409 PASS. Ordinal 385 publishes
`sourceFaceCount=300;established=300;unavailable=0;conflicting=0`.

Retired-code silence holds across all retained raw selector logs:

- `TraceArcDoesNotSeparateItsSides`: 0 occurrences;
- `UncutFaceComponentOrbitSeedNotUnique`: 0 occurrences;
- `RegionEulerCharacteristicNotOne`: 0 occurrences.

## 7. Immutability and execution boundary

The retained result reports all pre/post byte+mode censuses equal:

- `package_census_equal=true`;
- `source_census_equal=true`;
- `execution_view_census_equal=true`.

`execution-boundary.txt` records `script_exit=0`, `runtime_started=true`, `runtime_completed=true`,
`preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`,
`selection_integrity=true`, and `timeout_count=0`.

## 8. Regression-tracker intake and accounting

TB45-EXEC records two raw, non-stable review candidates:

1. 366 is now PASS and 367 advances from the exact TB44 `FragmentCornerSourceCornerMismatch` surface to the independent
   `FragmentPartition` oracle. The immediate raw surface is identified; semantic ownership/root cause remains review-pending.
2. 390/393/406/407 remain RED but now stop because the mechanical fixture has a published plan, before their Part XII receipt
   branches execute. The immediate raw assertion surface is identified; whether the fixture expectation or product progression
   owns the transition is review-pending.

No accepted-prefix loss occurred. Stable accounting is not changed in EXEC: **47 events / 14 categories / 33 recurrences**,
produced-witness debt **5**, package count **110**. TB44/package109 remains promoted semantic runtime authority pending TB45-REV.

## 9. Exact successor

**Exact next: `M3-CP4c-3-TB45-REV` — independent evidence-only review.**

The review must adjudicate ordinal367's `FragmentPartition` surface, the protected identities' now-successful mechanical-plan
precondition and unexecuted Part XII receipt branches, the five carried REDs, stable accounting, promotion, and the exact next
edge. It must not compile, execute new runtime, or mutate product/test/fixture/selector semantics before that adjudication.
