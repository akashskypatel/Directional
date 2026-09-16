# M3-CP4c-3-TB48-EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / CB54 PREDICTION MET / SEMANTIC RED / RAW EVIDENCE PRESERVED / REVIEW REQUIRED

**Turn:** `M3-CP4c-3-TB48-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-09

## 1. Authority and immutable input

TB48-EXEC consumed immutable CB54 package113 exactly as frozen. It did not configure, compile, relink, regenerate
discovery, repair package bytes or executable modes, mutate source/tests/fixtures/selectors, or run benchmarks.

- semantic source: `6dae3f6959551f6dcdd81f153aedb5f38411a96b`;
- immutable package113 artifact: `10125000895`, `m3-cp4c3-cb54-package113-result-34404928469`;
- package provider/download SHA-256: `e5fb50f92bbf4c4ffae5afeb203d6738490f6410b3a7e49245607e1b2e7835e9`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, 409 rows;
- accepted-prefix selector count: 365;
- generic artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- package root manifest: **28/28 verified**;
- per-identity control: `timeout -k 5s 180s`;
- outer elapsed cutoff: none.

## 2. Execution evidence and caller boundary

Authoritative workflow run **`34409262512`**, event SHA `5bee00b7f4b4fb59c1716a8d99c3de026beaa602`, completed successfully. The artifact-only execute job is **`102659650326`** and completed successfully.

- result artifact: `10126711178`, `m3-cp4c3-tb48-result-34409262512`, provider/download SHA-256 `07961a2339204b80f83feac8916e93578176363f9bdf0317ea85bdc095de5747`;
- persistent log artifact: `10126711588`, `m3-cp4c3-tb48-log-34409262512`, provider/download SHA-256 `1aab2f5f9b0d23f41ffd04a1467894f572604774ee2ee6ce9e42ee4b8f6dbd7d`;
- all **409** selector identities executed exactly once in ordinal order, one fresh process per identity;
- selection mismatches: **0**;
- timeout count: **0**;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

The caller records `harness_exit=0`; its independent boundary check records `boundary_ok=true`, `boundary_reason=ok`; the harness boundary records `script_exit=0`, `mode=--execute`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, and `timeout_count=0`. Package/source/execution-view pre/post censuses are byte-identical.

## 3. Raw measured result

TB48-EXEC measured:

- **409 total**;
- **405 PASS / 4 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[368,369,374,398]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256: `e450efbcc359ef544ab97c6fb9f0cb23b097e59b9680569390fe7a45a9350566`;
- failure-detail table SHA-256: `511f3c0bc6a4f971849b3c339e848a598905dd4af892cefe1506905ad82f5b4d`;
- resource-summary SHA-256: `1f85af61168f36ca9171b6e43b6f99e9165d26616c0f3f2e290e4c0e9a3cc79c`;
- identity-map SHA-256: `f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`.

This exactly matches CB54's falsifiable aggregate prediction. It is mechanically valid raw EXEC evidence, not review or promotion authority. **TB47/package112 remains the reviewed semantic runtime authority** until independent `M3-CP4c-3-TB48-REV` adjudicates package113.

## 4. Ordinal370 — CB54 product correction recovers the frozen identity at runtime

Ordinal370 `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` is **PASS**, selected exactly once with exit 0. The frozen identity constructs an atlas-accepted closed torus with empty rails/network, requires `SurfaceCutGraph::make` to fail with existing `EmptyNetworkOnClosedSurface`, and requires a non-empty `sourceFace` locus. Its passing runtime therefore exercises both typed code 6 and the locus assertion from immutable package113. Current failure-detail/evidence SHA-256 is `c26de83abdc9496cd1301470918ec39ecca1cf389ef0ae1c6504da1800d1c431`.

Tracker intake: **`M3-CP4c3-TB48-EXEC-CAND-01` — RAW PRODUCT-CORRECTION RECOVERY / REVIEW REQUIRED / NON-STABLE / UNPRICED**. EXEC records the recovery only. Independent review owns final closure of `M3-CP4c2-TB-X2-R8-CAND-02`, package113 promotion, and checkpoint-closure judgment.

Accepted/protected ordinals307 and 367 remain **PASS**. Their prior dispositions are unchanged by EXEC.

## 5. Protected controls and ownership remain non-vacuously green

Protected 390/393/406/407 all remain **PASS** through the successful `PlanFrontier` evidence branch. Their retained receipts continue to record `branch=UncutCensus`, `censusPredicateExecuted=yes`, `sameDomainCorruptionRejected=yes`, `terminalSubjectBranch=PlanFrontier`, and `planFrontierEvidenceBranchExecuted=yes`, with non-empty BW3/owner-map/partition/interior-arc evidence.

Ordinal385 again publishes **300 established / 0 unavailable / 0 conflicting** ownership. Frozen controls 404/408/409 also PASS.

## 6. Every observed RED categorized before closeout

The four RED ordinals reproduce their established separate failure surfaces and remain under their prior owners:

- **368** — prescribed sphere still fails before a cut graph with `NotProductionReady / CellularityNotEstablished / origin=RotationSystemInconsistent`, originating reason `TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable`; carried owner `M3-CP4c2-TB-X2-CAND-04`; current failure-detail SHA-256 `7772f846dd26ce469de28a285182a6d98f90c35fdfbd84757dce229a2312fa21`.
- **369** — `certificate.saturationUsed` remains `true` where the identity requires the ordinary tree-cotree proposal; carried owner `M3-CP4c2-TB-X2-R10-CAND-01`; current failure-detail SHA-256 `cc2ceeff468dea5dda3121548a68ab081518809783b06151eaa726ec183fdcbf`.
- **374** — the pre-classified folded-cone witness still stops at `atlasBuild=false`; carried owner `M3-CP4c3-TB7-CAND-02`; current failure-detail SHA-256 `f43da8d8de7d61b9132be3005bb652c732d1f6dc2f27eb87d8a181d2f2feaffa`.
- **398** — prescribed-sphere cut graph remains absent at `NotProductionReady/CellularityNotEstablished`; this remains downstream of 368; current failure-detail SHA-256 `c06eaa58a852f24fe6df465b2f8a783795294a9c1418a2dac0e391eb799bd2b5`.

No new RED identity or new failure surface appears. EXEC does not merge/reprice owners or prescribe corrections. Stable accounting therefore remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, ownership **300/0/0**, accepted package count **113** pending review.

## 7. Retired-predicate silence and immutability

Across current result/log evidence there are zero occurrences of `TraceArcDoesNotSeparateItsSides`, `UncutFaceComponentOrbitSeedNotUnique`, `RegionEulerCharacteristicNotOne`, `FragmentCountRule`, and `FragmentPartition`.

Package/source/execution-view pre/post censuses are equal. No artifact mutation, source mutation, build, repair, discovery, benchmark, or executable-mode repair path executed.

## 8. Regression-tracker intake and authority boundary

Every observed RED is categorized in `Regression_Root_Cause_Tracker.md` as a carried recurrence under its existing owner. Ordinal370's RED-to-PASS transition is recorded as non-stable product-correction recovery evidence. Accepted remains 365/365 and EXEC establishes no new stable event/category. Stable totals remain **47 / 14 / 33**, debt **5**, ownership **300/0/0**, packages **113**.

**Reviewed semantic runtime authority remains TB47/package112** at 404 PASS / 5 RED until independent review. Raw TB48/package113 is not semantic promotion or checkpoint-closure authority by itself.

## 9. Exact successor

**Exact next: `M3-CP4c-3-TB48-REV` — independent REVIEW + PLAN, runtime-free.**

The review must adjudicate ordinal370's runtime recovery, the four carried RED owners, protected non-vacuity, stable accounting, package113 promotion and whether formal CP4c-3 closure follows from the already-met AU0–AU9 mechanical-witness criterion. It must perform mandatory REVIEW-turn document consolidation and update `ORIENTATION.md`. No retry, product/test patch, compile or new runtime is authorized before that review.
