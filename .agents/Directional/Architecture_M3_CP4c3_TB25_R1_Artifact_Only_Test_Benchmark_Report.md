# M3-CP4c-3-TB25-R1 Artifact-Only Test + Benchmark Report

## Status

**COMPLETE / VALID IMMUTABLE SEMANTIC RUNTIME / SEMANTIC RED / ACCEPTED PREFIX SAFE / REVIEW REQUIRED.**

`M3-CP4c-3-TB25-R1` is the fresh re-execution required after CB29 corrected the pre-runtime control defect in
the first TB25 attempt. It executed all **403** selector identities from immutable CB28 artifact `9950303110`,
one identity per fresh process, and completed **393 PASS / 10 RED** with accepted ordinals **1–365 = 365/365
PASS**. Because gating identities remain RED, CP4c-3 stays **OPEN**. Per the unchanged frozen TB25 plan,
interpretation belongs to **`M3-CP4c-3-TB25-REV`**. This EXEC report records runtime facts only.

## Immutable authority

- semantic product source: `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`
- immutable CB28 package artifact: `9950303110`, SHA-256
  `84c9cd0bdf5d8bef2288e1ca57d52bcec8d1503f368d82101ae10cfa14c49189`
- package producer run/job: `33907875533 / 101137084443`
- formal TB25-R1 run/job: `33919389753 / 101173990222`, **SUCCESS**
- formal workflow event SHA: `375f887847268ed4560f6f6e577f0be0f202c430`
- TB25-R1 result artifact: `9954531868`, SHA-256
  `e3b2ac7a9df5afabfd844450059b33f26fff040d0f1632e523bc7aa085e06cd0`
- TB25-R1 diagnostic-log artifact: `9954532357`, SHA-256
  `412c86f35906482bd9b36f646306a1267f5e13dad16d11986a3993d93a762fc4`
- accepted selector 365: SHA-256
  `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- selector 401: 401 identities, SHA-256
  `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`
- selector 403: 403 identities, SHA-256
  `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`
- selector 365 is the exact first 365 lines of selector 403.
- selector 401 is the exact first 401 lines of selector 403.
- ledger SHA-256: `bdcfbb9d2ea5e7c45535a0b95e2d1914f5245bab498a62dd99cb7b0348936cc0`
- identity-map SHA-256: `7ec8d68589bd6f8d18df7e3386a584203914e5462703adf578ae1325d4e90d8f`

The downloaded result ZIP SHA-256 matched the GitHub artifact-provider digest.

## Pre-runtime correction provenance

The first TB25 attempt remains invalid provenance only: run/job `33910913448 / 101146905061` stopped before
Directional runtime with `selector injection point missing`, executed **0/403**, and produced no semantic ledger.

CB29 then proved the corrected control without runtime. Its result artifact `9953038617` has SHA-256
`f1216938b3d543d4d3fcb498279b1ce432feac008ec240afbf9ae18b1fbe31cf`; the directly verified standalone
harness has SHA-256 `13ec524fa0fe609949b147ab36bf710392244b8202684ece2eea10eb5c83e0e9`.

TB25-R1 re-verified that exact proof artifact and harness before runtime, `bash -n` passed, the immutable product
artifact digest matched, the recursive package manifest passed, source authority matched, GMP remained the exact
backend, and selector 365/401 exact-prefix relations to selector 403 both passed. The corrected gate then started
at ordinal 1 and completed through ordinal 403. This runtime fact closes the pre-runtime orchestration candidate;
it gives the invalid first attempt no semantic credit.

## Execution boundary

Final execution boundary:

- `script_exit=0`
- `runtime_started=true`
- `runtime_completed=true`
- `preflight_completed=true`
- `execution_view_verified=true`
- `orchestration_failure=false`
- `benchmark_execution=false`
- `configure_execution=false`
- `compile_execution=false`
- `relink_execution=false`
- `generated_discovery=false`
- `package_repair=false`
- `mode_repair=false`
- `source_test_fixture_selector_mutation=false`

The consumer used immutable package hardlinks in the staged execution view and resolved fixtures through
`executableDirectory.parent_path()/test-data`.

## Authoritative 403-row ledger

- total: **403**
- PASS: **393**
- RED: **10**
- accepted prefix 1–365: **365/365 PASS**
- accepted RED ordinals: **none**
- RED ordinals: **366, 367, 368, 369, 370, 374, 389, 390, 393, 398**

Relative to TB24's selector-401 authority:

- **384 changes RED → PASS**;
- **385 changes RED → PASS**;
- **366, 367, 368, 369, 370, 374, 389, 390, 393 and 398 remain RED**;
- 371, 372, 391, 392, 397, 399, 400 and 401 remain PASS;
- new 402 and 403 are both PASS.

No accepted-prefix regression is observed. EXEC assigns no root-cause or stable-regression classification to
these transitions.

## Frozen TB25 discriminator evidence

### Accepted boundary

**365/365 PASS.** There is no accepted-green loss.

### Mechanical ownership publication

Ordinal **385 PASS** and publishes:

`sourceFaceCount=300; established=74; unavailable=226; conflicting=0; conflictCensusPublished=true; conflictRowCount=0`

Ordinal **402 PASS** independently records the production conflict census as published with **rowCount=0**.
Ordinal **403 PASS** proves the census contract can name a non-barrier edge separating certified faces on its
bounded witness.

These are factual runtime observations only. The frozen plan assigns interpretation of the production zero-row
census together with incomplete ownership to TB25-REV.

### Component-0 evidence

Ordinals **366 and 367 remain RED**. Their production failure now reports:

- `detailCode=UncutFaceComponentOrbitSeedNotUnique`
- `sourceFace=0,1,2`
- `embeddedGraphEulerCensusComplete=true`
- `V=22`, `E=26`, `F=6`, `componentCount=1`, Euler residual `0`
- `uncutFaceComponent=0`
- `uncutFaceComponentFaceCount=191`
- `uncutFaceComponentSeedCount=0`
- `uncutFaceComponentSeedState=None`
- `uncutFaceComponentCertifiedFaceObservationCount=0`
- `uncutFaceComponentCertifiedFaceUnavailableCount=191`
- `uncutFaceComponentCertifiedFaceDistinctCount=0`
- the certified-face multiset is not truncated.

EXEC does not convert those observations into a branch decision.

### Previously lost evidence surfaces

- **384 PASS**: `FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath`.
- **385 PASS**: production decision evidence and the ownership publication census above are now reached.
- **389 RED**: embedded Euler census is published (`V=22;E=26;F=6;componentCount=1;sourceChi=2;residual=0`), but
  `certificate.proves_cellularity()` is false.
- **390 RED**: `certificate.proves_cellularity()` is false and the observed
  `uncutFaceComponentCertifiedFaceDistinctCount` is `0`, where the identity expects more than one.
- **393 RED**: `certificate.proves_cellularity()` is false before its later projection assertions can establish
  the expected condition.
- **398 RED**: the mechanical production certificate has `proves_cellularity()==false`.

### Other carried RED surfaces

- **368 RED**: prescribed sphere remains at
  `CellularityNotEstablished/origin=RotationSystemInconsistent`, `TraceEventPositionInvalid`, trace 2/event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`.
- **369 RED**: `certificate.saturationUsed` is true where the identity expects false.
- **370 RED**: typed error-code expectation still mismatches and the required source-face locus remains absent.
- **374 RED**: `atlasBuild` is false.

These are carried observations; no corrective measure is authored in EXEC.

## Postflight immutability

All three pre/post censuses are byte-identical:

- package:
  `10dd3e008a2dcfb3c41e1e8b2ec897c11e397804bd303410ece42008ac9704a8`
- packaged source:
  `64cea8d26cd0cebcf7f1330deaa4b44de3ca51042da83c378bb241d7744cc02d`
- execution view:
  `2290af4f58a5918a35d6c8f51d62db98ae96801974198d784ef820ed6373d194`

No package/source/execution-view mutation occurred.

## Runtime environment and resource evidence

Formal runner: Ubuntu 24.04 / Linux x86_64, glibc 2.39, 4 logical CPUs, AMD EPYC 9V74. Per-test
`/usr/bin/time -v` evidence is retained for all 403 fresh processes. Peak recorded test RSS is **18,400 kB**
(ordinal 147). Longest recorded elapsed time is **29.29 s** (ordinal 137).

## Regression-tracker disposition at EXEC

`M3-CP4c3-TB25-ORCH-01` is factually **CLOSED / CONTROL FIX RUNTIME PROVED / NON-STABLE** because corrected
preflight passed and the unchanged gate completed all 403 processes. The invalid attempt remains provenance and
adds no stable event.

The 10 semantic REDs are recorded as **REVIEW PENDING** against their existing owners. This EXEC turn does not
change stable regression accounting: **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains
**5** and semantic M3 package count remains **90**.

## Outcome routing

TB25-R1 is a **valid semantic RED** gate. CP4c-3 remains **OPEN**. Per the unchanged frozen TB25 plan, the exact
successor is:

**`M3-CP4c-3-TB25-REV` — independent REVIEW + PLAN only.**

Review owns diagnosis/classification of the 10-RED ledger, the factual 384/385 recoveries, the zero production
conflict-row census with 226 unavailable source faces, all inherited candidates, stable accounting adjudication,
mandatory `ORIENTATION.md` update, and REVIEW document consolidation. Do not rerun Directional, rebuild/relink/
repair the package, or patch product/tests before that review.
