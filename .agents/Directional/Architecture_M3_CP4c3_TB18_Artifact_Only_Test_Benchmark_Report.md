# M3 CP4c-3 TB18 — Artifact-Only Test + Benchmark Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB18`
Status: **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / DIAGNOSTIC MECHANISM MEASURED / ONE REQUIRED LOG RECORD ABSENT / NON-STABLE**

## Authority and immutable envelope

TB18 consumed the immutable CB20 compile result directly. No configure, compile, relink, package repair, mode repair,
generated discovery, source/test/fixture/selector mutation, or benchmark execution occurred.

- semantic/evidence source: **`57635e87306a416daabb8321e1f36fa9c788d208`**;
- compile run/job: **`33780005014 / 100731152066`**;
- compile result artifact: **`9903305256`**, Actions digest **`sha256:06def1b690bf63391520392da9381088c2bf6529138b6e9f44816bf06996563a`**;
- packaged source archive SHA-256: **`ffa1a919077183a91f4d8d4cf903bb901eea0a00eb9d333495916f018df5d079`**;
- selector 383 SHA-256: **`a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`**;
- selector 382 prefix SHA-256: **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`**;
- accepted selector-365 prefix SHA-256: **`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`**;
- final TB18 run/execute job: **`33785382790 / 100748821924`**;
- result artifact: **`9905330011`**, Actions digest **`sha256:c060eea3b1469c2ddc368bcf1d1d3a61c4ce35ad1de7bda249e11bdb566c5faa`**;
- diagnostic-log artifact: **`9905330748`**, Actions digest **`sha256:2bb5e0504d80b9f9d1f905d802a90980caedc47c42531664df7eb063a3c181c3`**;
- exact 383-entry result-ledger SHA-256: **`a99c31d84200cb97e78bb399fa32c76bea1f3767092f29fc339c4cc9130604ed`**;
- package pre/post byte+mode census SHA-256: **`5fb1dcf55b2850f5655e76a58b3a77e3b49c29b137c3773ebd416bbedb350eb8`**; pre/post are byte-identical.

The package preflight also re-proved `runtimeExecution=false` at compile time and `exactArithmeticBackend=GMP`, with
both GMPXX and GMP present in the packaged link evidence. Runtime execution in TB18 was limited to the frozen test
identities and is recorded separately as `runtimeExecution=true`.

## Orchestration revision — attempt 1 preserved, not rerun

Attempt 1, run/job **`33784755615 / 100746771952`**, executed ordinals **1–39**, all PASS, then stopped before
ordinal 40 because the temporary owner-map shell case omitted ordinal 40. That is an orchestration defect, not a
semantic RED. Attempt-1 result/log artifacts are **`9904975159 / 9904975611`** with digests
`sha256:51dc8cdfafcb7de0f50abcbf51ebbc0e89863d6b3fa6929fccd5f88472391dce` and
`sha256:c5191547f20949a9d51d5b66aa48585932f551daceaf3922382952926c5b4a99`.

The corrected runner verified that artifact, verified every completed ordinal 1–39 against selector 383 and its log
hash, copied those immutable results forward, and resumed at **ordinal 40**. It explicitly records
`rerun_completed_ordinals=false`. No completed semantic identity was rerun to seek a different result.

## Gate result

Selector **383** completed all 383 exact identities, one identity per fresh process for each newly executed ordinal:

- **375 PASS / 8 RED**;
- accepted ordinals **1–365: 365/365 PASS**;
- RED ordinals: **366, 367, 368, 369, 370, 371, 372, 374**;
- first semantic red: **366**;
- ordinal 373 and ordinals 375–383: **PASS**;
- new CB20 projection witness at ordinal **383**: **PASS**.

The red set is the same eight-ordinal semantic set as TB17; selector 383 adds one passing diagnostic-contract
identity. CP4c-3 therefore remains OPEN and routes to independent review.

## Fragment-count measurement at the first red

Ordinal 366 remains
`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` and still fails
`TraceCutFaceFragmentCountMismatch` at source face **`(0,1,102)`**. CB20's no-semantic-change boundary is therefore
preserved.

The retained production failure now reports the deciding values:

- `fragmentOrbitCount = 1`;
- `tracePieceCount = 1`;
- `expectedFragmentCount = 2`;
- direction: **`actual < expected`**, by exactly 1;
- `fragmentIncidenceCount = 1`;
- `fragmentIncidencesTruncated = false`.

The complete retained incidence is:

`trace=1, arc=15, segment=4, orientation=Forward, incomingCarrier=none, outgoingCarrier=0-102, forwardOrbit=0, reverseOrbit=0, forwardExteriorDropped=false, reverseExteriorDropped=false`.

All three failing-face edge-evidence rows are present and untruncated:

- edge `1-102`: `totalOrbitCount=1`, `orbits=[0]`;
- edge `0-1`: `totalOrbitCount=1`, `orbits=[0]`;
- edge `0-102`: `totalOrbitCount=1`, `orbits=[0]`.

For this witness, the measured low-side mechanism is therefore **shared global orbit ownership**: both oriented sides
of the one real chord retain the same global face-walk orbit id `0`, while neither side is dropped by the exterior
filter. TB18 records that mechanism only; it does not prescribe the replacement invariant or product correction.

Ordinals **367, 371, and 372** co-reach the same fragment mismatch at `(0,1,102)` with the same retained counts and
incidence.

## BS9 discriminator disposition

1. **PASS — accepted boundary.** Ordinals 1–365 are **365/365 PASS**.
2. **PASS — no frontier movement.** Ordinal 366 remains `TraceCutFaceFragmentCountMismatch` at `(0,1,102)`.
3. **PASS — mismatch direction visible.** Actual/trace/expected are **1 / 1 / 2**, so **actual < expected**.
4. **PASS — contributing incidence visible.** The one retained real-chord incidence is untruncated and includes both
   carriers, both orbit ids, and both exterior-drop flags; both orbit ids are `0`, both drop flags are `false`.
5. **FAIL / DIAGNOSTIC INSUFFICIENCY — named `fragment_reconciliation` log record absent.** The production failure
   envelope does retain the accumulated three-edge orbit evidence, but no
   `M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation` line for `(0,1,102)` appears in the retained selector logs.
   The frozen TB18 plan explicitly prohibits an ad-hoc runtime probe when required BS9 evidence is absent, so TB18
   does not rerun with a changed environment or invent the missing record.
6. **PASS — carried surfaces unchanged.** 367/371/372 co-reach the same downstream fragment mismatch; 368 remains
   prescribed-sphere `RotationSystemInconsistent -> TraceEventPositionInvalid`, trace 2/event 30,
   `NoCarrierMatch / SourceEdgeUnavailable`; 369 remains `saturationUsed=true` where ordinary proposal is expected;
   370 remains actual `CellularityNotEstablished` with no source-face locus instead of the expected
   `EmptyNetworkOnClosedSurface`; 374 remains the pre-classified folded-cone `atlasBuild=false` fixture surface.

BS9-5's missing text record is evidence insufficiency, not permission to rerun or to reinterpret the measured typed
failure envelope. The following independent review owns whether the retained typed counts/incidence/edge evidence are
already sufficient to freeze a corrective representation contract.

## Immutability and process boundary

- pre/post package byte+mode census: **IDENTICAL**, SHA-256
  `5fb1dcf55b2850f5655e76a58b3a77e3b49c29b137c3773ebd416bbedb350eb8`;
- `benchmarkExecution=false`;
- `configureExecution=false`;
- `compileExecution=false`;
- `relinkExecution=false`;
- `packageRepair=false`;
- `modeRepair=false`;
- `generatedDiscovery=false`;
- `sourceMutation=false`;
- `testMutation=false`;
- `fixtureMutation=false`;
- `selectorMutation=false`.

## Regression accounting and ownership

`M3-CP4c3-TB17-CAND-01` remains **ACTIVE / GATING / MECHANISM RUNTIME-MEASURED / CONTRACT UNADJUDICATED**.
TB18 removes the deciding incidence ambiguity for this witness: the observed mismatch is low because the forward and
reverse sides of one real chord collapse to the same global orbit owner, not because either side was exterior-filtered.
The replacement representation/invariant is still an architectural decision and remains owned by independent
`M3-CP4c-3-TB18-REV`.

No accepted-green identity regressed and no new stable product regression is established. Stable accounting remains
**44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3 package count remains
**84**.

## Status and exact successor

`M3-CP4c-3-TB18` is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / NON-STABLE**. CP4c-3 remains
**OPEN**. Accepted authority remains **365/365**. Current runtime selector authority is now selector **383**, with
**375 PASS / 8 RED** and ledger
`a99c31d84200cb97e78bb399fa32c76bea1f3767092f29fc339c4cc9130604ed`.

Exact successor: **`M3-CP4c-3-TB18-REV` — independent REVIEW + PLAN only**. That review owns the representation
decision and the disposition of BS9-5's missing reconciliation log. No semantic Code + Build is pre-authorized by
TB18.
