# M3-CP4c-3-TB44 EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / RAW EVIDENCE PRESERVED / SEMANTIC REVIEW PENDING

**Turn:** `M3-CP4c-3-TB44-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-08

## 1. Authority and immutable input

TB44 executed immutable CB49 package109 exactly as frozen. It did not configure, compile, relink, regenerate discovery,
repair package bytes or modes, mutate source/tests/fixtures/selectors, or run benchmarks.

- semantic source: `cf969597bda5c49e734b98db0c0165b421c4ee12`;
- immutable package109 artifact: `10081938891`, `m3-cp4c3-cb49-result-34292599472`;
- provider/download SHA-256: `285ee15784ea29468c367fa9e4778fd835f1e9582370fdcb26a5050a15c4d617`;
- packaged source archive SHA-256: `7dead808562e8faf0a90e242532e2965bc9260f24505958eb5f242c19b1273ca`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- accepted-prefix selector count: 365;
- generic artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- package root manifest: 28/28 verified;
- executable archive modes preserved; no `chmod` or other repair occurred.

The workflow restored the frozen harness's real per-identity control, `timeout -k 5s 180s`, while imposing no outer
elapsed-time cutoff on the complete selector409 gate.

## 2. Execution evidence

Authoritative workflow run `34295565963`, event SHA `07b1600797ea1330d58474ec2dc72df4a55e4530`, completed
successfully. The artifact-only execute job is `102291328376` and completed successfully.

- result artifact: `10083047547`, `m3-cp4c3-tb44-result-34295565963`, digest
  `sha256:7e3229e9f012e7920cb0318eae358768a19b05e863ec12b4484b68d5d067cfab`;
- persistent log artifact: `10083047938`, `m3-cp4c3-tb44-log-34295565963`, digest
  `sha256:c63b6a45c208f704c26939face91f6f961ee5bc04c71f203c059f5109bcfe9cd`;
- observer log artifact: `10082980146`, digest
  `sha256:326cd6afa0e85fb73cc9c549cf74613503447349ea9490c8c43c7700e48a245d`;
- runtime started and completed organically;
- all 409 selector identities executed exactly once in ordinal order, one fresh process per identity;
- selection mismatches: 0;
- timeout count: **0**;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

The downloaded result artifact independently hashes to
`7e3229e9f012e7920cb0318eae358768a19b05e863ec12b4484b68d5d067cfab`.

## 3. Raw measured result

TB44 measured:

- **409 total**;
- **398 PASS / 11 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[366,367,368,369,370,374,390,393,398,406,407]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256: `5b1e663e2855d453cf461847ed463b7539f9d0e945b4c40468eab64ae3e57a99`;
- failure-detail table SHA-256: `37d9916911c1e799397209994b9aa6c96beb9271ebd49811a5f21abd1889ba40`.

This is **raw EXEC evidence only**. TB44-EXEC does not promote this vector over TB43, merge or reprice regression
events, or authorize a corrective implementation. Independent `M3-CP4c-3-TB44-REV` owns semantic adjudication.

## 4. Direct CB49 falsifier — 366 / 367

The exact TB43 `RegionSourceFaceOwningFragmentMissing` locus did **not** reproduce. Both 366 and 367 are still RED,
but their first observed production failure surface is now:

`NotProductionReady/global-topology-plan/RotationSystemInconsistent;detailCode=RotationSystemInconsistent;sourceFace=10,11,79;rotationSystemReason=FragmentCornerSourceCornerMismatch`

Across both raw logs:

- `RegionSourceFaceOwningFragmentMissing`: 0 occurrences;
- `RegionInteriorVertexCornerOwnerMissing`: 0 occurrences;
- `expectedOwnerOrbit=1`: 0 occurrences;
- owner set `[2,3]`: 0 occurrences;
- `regionOwningFragmentOrbitPresent=false`: 0 occurrences.

The new raw detail digests are:

- ordinal 366: `b4b0f3d527387e340b4b69d3792368986a463e640f14cca80920c93f6c4fa5c7`;
- ordinal 367: `f9f1374e76fbcf9117fb51aafb6d9db0e2f1c33e4d3ee463328d6b97cd3e5891`.

Mechanically, the bounded CB49 falsifier is satisfied only in the narrow sense that the old owner-missing locus is absent and
execution advanced to a later/different fail-closed guard. EXEC does **not** decide whether
`FragmentCornerSourceCornerMismatch` is a new defect, a legitimate downstream guard, or a recurrence under an existing owner.
That decision belongs to TB44-REV.

## 5. Protected Part XII identities — 390 / 393 / 406 / 407

All four protected identities are RED in TB44, but each retained raw log proves that the Part XII oracle executed rather than
being skipped. Every identity publishes:

`branch=UncutCensus; censusPredicateExecuted=yes; terminalSubjectRelation=Outside; sameDomainCorruptionRejected=yes; regionCertificationEvidenceBranchExecuted=yes`

Their immediate assertion surface is also common:

- `region_fragment_owner_relation_is_valid(locus)` is false;
- `locus.regionFrontierFailureRegionSourceFaceCount.has_value()` is false.

Failure-detail digests:

- 390: `3f4d3e03918d8fb4001e6efc85734a05f3acfc66f5df6d6accc04a43b6f07eac`;
- 393: `57c2fcddb7150298d937f5a03cd5fcfe123c4a13713a1aa1707c84ea9f4bbc5a`;
- 406: `26601475cf7a04ec2a611ebf8a09c7be4f4a322ee7641538224de7aaa4a867d4`;
- 407: `0f04932d98b6d714ba2b532df94dec1db173e678b9ea838119bec644683acd09`.

This is a raw color regression relative to TB43's PASS state, but the evidence rules out the vacuous skipped-oracle explanation.
EXEC records a review-pending candidate only; it does not assign a stable root cause or reprice accounting.

## 6. Carried REDs and frozen controls

The five previously carried REDs remain at their prior visible surfaces:

- 368: prescribed-sphere `CellularityNotEstablished/origin=RotationSystemInconsistent`, originating reason
  `TraceEventPositionInvalid` / `NoCarrierMatch`;
- 369: `certificate.saturationUsed=true` where the identity expects false;
- 370: the empty-network typed rejection contract remains unmet;
- 374: `atlasBuild=false`;
- 398: prescribed-sphere `NotProductionReady/CellularityNotEstablished`.

Their detail digests are unchanged from TB43 for 368/369/370/374/398:
`225f721e…`, `3977b8c3…`, `2186769e…`, `0a11506d…`, `a1cb27f1…` respectively.

Frozen controls 311/312/314/315/356/357/404/408/409 PASS. Ordinal 385 publishes
`sourceFaceCount=300;established=300;unavailable=0;conflicting=0`.

Retired-code silence holds across all raw logs:

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

TB44-EXEC records two raw, non-stable review candidates:

1. 366/367 advanced from the exact TB43 owner-missing locus to `RotationSystemInconsistent / FragmentCornerSourceCornerMismatch`;
   the immediate mechanical failure locus is identified, but semantic ownership/root cause is not adjudicated in EXEC.
2. 390/393/406/407 changed from TB43 PASS to RED at the common owner-relation / missing-region-source-face-count assertion
   surface while their Part XII non-vacuity receipts remained present; the immediate assertion locus is identified, but semantic
   ownership/root cause is not adjudicated in EXEC.

No accepted-prefix loss occurred. Because this is an EXEC turn and the new/moved surfaces require independent review, stable
accounting is **not changed here**: **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, package count
**109**. TB43/package108 remains the promoted semantic runtime authority pending TB44-REV.

## 9. Control-plane process notes

Two setup-order issues occurred before or outside the semantic execution and are not TB44 product evidence:

- initial repository/handoff reads preceded the explicit `READ_MODE=snapshot` decision; the session corrected to an exact
  source snapshot before semantic execution work;
- the cleanup manifest was created too early and triggered cleanup run `34294735581`; that run failed before semantic runtime
  because the branch advanced from event SHA `548343e41622f48c1cfaf66b34887f20ca0b1ee7` to
  `88140ef3e3ead60fb8eccaeb34b4f0a3a6ba127d` before its compare-and-swap check. No repository cleanup commit or Directional
  runtime resulted from that failed attempt.

Both are orchestration/process observations only. They do not alter package109, selector409, or run `34295565963` evidence.

## 10. Exact successor

**Exact next: `M3-CP4c-3-TB44-REV` — independent evidence-only review.**

The review must adjudicate the 366/367 downstream `FragmentCornerSourceCornerMismatch` surface, the protected
390/393/406/407 raw regression with non-vacuity receipts intact, the five carried REDs, stable accounting and the exact next edge.
It must not compile, execute new runtime, or mutate product/test/fixture/selector semantics before that adjudication.
