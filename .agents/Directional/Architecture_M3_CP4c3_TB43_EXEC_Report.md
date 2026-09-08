# M3-CP4c-3-TB43 EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / RAW EVIDENCE PRESERVED / SEMANTICALLY UNADJUDICATED

**Turn:** `M3-CP4c-3-TB43-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-08 UTC

## 1. Authority and immutable input

TB43 executed immutable CB48 package108 without rebuilding, configuring, relinking, regenerating, repairing, or mutating
package/source/test/fixture/selector state.

- semantic source: `531b517fb129425f113b5f811215f1d2b1939ee2`;
- immutable package108 artifact: `10076272909`, `m3-cp4c3-cb48-package108-result-34276935866`;
- provider/download SHA-256: `a2578a82e82c3e1bdc5798e0bf96028e3e854ccbeb65c7a111a6489fa1593612`;
- packaged source archive SHA-256: `2bce00134c172973225bbe44e87a2708477bde5fed2d531b8d0b9636945fb7c3`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- accepted-prefix selector count: 365;
- package root checksum verification: 28/28 PASS;
- exact arithmetic backend: GMP/GMPXX linked in the immutable package evidence.

Executable modes were preserved by ordinary archive extraction. No package permission/content repair was performed.

## 2. Execution evidence

Authoritative workflow run `34280642422`, event SHA `51387f933304d157ef392cd2d492fd379ccaffb3`, completed successfully.
The artifact-only execute job is `102244347209` and completed successfully.

- result artifact: `10077594302`, `m3-cp4c3-tb43-result-34280642422`, digest
  `sha256:486a411479bec2249e6c3b33f2612625651e80e4f26b9b6fbf5e7addd63e4110`;
- diagnostic log artifact: `10077595162`, `m3-cp4c3-tb43-log-34280642422`, digest
  `sha256:7ad742562eb48d0c8f6160176d73ab3baec3d6506262d022cc37580ff4e8bed2`;
- runtime started and completed organically with no repository elapsed-time cutoff on the full 409-identity gate;
- every selector identity ran exactly once in ordinal order in a fresh process;
- selection mismatch count: 0;
- timeout count: 0;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

The generic frozen artifact-only harness was verified at SHA-256
`aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`. The workflow materialized only a
runner-temporary TB43 execution view that removed the per-identity timeout and added exact source-archive and accepted-prefix
preflight checks; it did not patch the immutable package or repository source.

## 3. Raw semantic result

TB43 measured the frozen Part XII falsifier exactly:

- **409 total**;
- **402 PASS / 7 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[366,367,368,369,370,374,398]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256: `058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`.

This is **raw EXEC evidence only**. TB43-EXEC does not promote itself over TB42, close/reprice candidates, or authorize a
corrective implementation. Independent `M3-CP4c-3-TB43-REV` owns semantic adjudication.

## 4. Part XII protected receipts

Ordinals **390, 393, 406 and 407 all PASS** and each publishes the required non-vacuity receipt:

`branch=UncutCensus; censusPredicateExecuted=yes; terminalSubjectRelation=Outside; sameDomainCorruptionRejected=yes; regionCertificationEvidenceBranchExecuted=yes`

Receipt table SHA-256:
`72fd412043f6ed23eb57af2339c4e18c3d014af1683810f89587d07833600b3a`.

This proves mechanically that the producer-owned `P_U` census predicate executed, the deliberately corrupted same-domain copy
was rejected, and the terminal failing subject was classified separately as `Outside`. EXEC records the recovery but does not
semantically close the owning candidate.

## 5. Preserved controls and ownership

The protected controls **311/312/314/315/356/357/404/408/409 PASS**. Ordinal 385 publishes:

`sourceFaceCount=300; established=300; unavailable=0; conflicting=0; conflictRowCount=0`.

Retired-code silence holds across the retained raw logs:

- `TraceArcDoesNotSeparateItsSides`: 0 occurrences;
- `UncutFaceComponentOrbitSeedNotUnique`: 0 occurrences;
- `RegionEulerCharacteristicNotOne`: 0 occurrences.

## 6. Raw RED intake

The seven RED identities remain separately owned carried surfaces. TB43-EXEC records their current failure loci without
adjudicating or merging them.

### 366 / 367 — carried missing fragment/orbit relation

Both remain at `NotProductionReady/global-topology-plan/RegionSourceFaceOwningFragmentMissing` and publish the Part XII exact
observation contract. The failing locus includes source face `10,11,79`, topology region 1, expected
`regionOwningFragmentOrbit=1`, present owner-orbit IDs `[2,3]`, exact count 2, and
`regionOwningFragmentOrbitPresent=false`. The terminal subject relation is `Outside`; the independent uncut census remains
non-empty at 226 unlabelled faces / 9 components / 9 owner-consistency rows.

Both failure-detail digests are identical:
`073c4e44dbc8c88f2b0b37a0063b70bf74cfcb930a95a9afbfead3575b36c460`.

This is current raw evidence under the existing 366/367 owner. Part XII adds observation; it does not correct product behavior.

### 368 — prescribed sphere / cellularity surface

Still RED because `sphere.cutGraph.has_value()` is false; failure remains
`NotProductionReady/CellularityNotEstablished/origin=RotationSystemInconsistent`. Detail digest:
`225f721e4665efee5b21c6ad22153b0b01b449925bf79af342328c70fe1ef571`.

### 369 — saturation / quality surface

Still RED because `certificate.saturationUsed` is true where the identity expects false. Detail digest:
`3977b8c39be9ac2b1b7283b1877d7df9890a7a24e74853ac90e3662fd8badeb1`.

### 370 — empty closed-surface network typed rejection surface

Still RED: the expected `EmptyNetworkOnClosedSurface` contract is not observed and the expected source-face locus remains
absent. Detail digest: `2186769ec148ad26af8b455c7aa471e00314443ce1918c78c5dc4ef67f80b7b`.

### 374 — folded-cone atlas surface

Still RED because `atlasBuild` is false. Detail digest:
`0a11506dd4a52f8e145722d3d1e63bc3d7ede68c0039834589a2e711430c1463`.

### 398 — prescribed sphere production cellularity surface

Still RED because `fixture.cutGraph.has_value()` is false with
`NotProductionReady/CellularityNotEstablished`. Detail digest:
`a1cb27f1d7df1fcf0ea853fedf0194aeb219df18e7b9bd658b96279726ddecb6`.

Failure-detail table SHA-256:
`a9c69f4e9f703c9d38e8acb1149fd5ee0a28d9eda20f48dbda934a35795d71ed`.

## 7. Immutability and resource evidence

All three pre/post censuses are byte+mode identical:

- package census before/after: `ca20ef1b001e36c4320210107d0c664621a37429ab73af36a9cf8fc79117459e`;
- packaged source census before/after: `643d50f8cfd5cff3bc5d49118324ed4f8f29390201e742e76eb50dafb679180f`;
- execution-view census before/after: `5dcbbc43c7319f0c6703bf8b8d1becdc6bae7507c693604b7e0415cf6f10983e`.

Resource-summary table SHA-256:
`1d588ec397e426ca1d92a8cba146bb61ce52fe5f26004013b37787cb9fb52f4b`.
The maximum recorded RSS row was ordinal 147 at 18,488 KiB with elapsed 0:15.02.

## 8. Regression-tracker disposition and accounting

TB43 introduces **no new RED ordinal and no accepted-prefix loss**. The four protected Part XII identities recover mechanically,
while the seven REDs are recurrences of already owned surfaces. Because this EXEC turn is not the independent semantic review,
it does **not** create, merge, close, or reprice stable regression events.

Stable accounting therefore remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, package count
**108**. Promoted semantic runtime authority remains **TB42 / package107** pending independent TB43 review.

## 9. Exact successor

**Exact next: `M3-CP4c-3-TB43-REV` — independent evidence-only review.**

The review must adjudicate the raw Part XII recovery of 390/393/406/407, the exact `Outside` / owner-orbit evidence on 366/367,
and the seven carried RED surfaces. It must not compile, run new runtime, or mutate product/test/fixture/selector semantics before
that adjudication decides the next edge.
