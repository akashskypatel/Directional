# M3-CP4c-3-TB47-EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / SEMANTIC RED / RAW EVIDENCE PRESERVED / REVIEW REQUIRED

**Turn:** `M3-CP4c-3-TB47-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-09

## 1. Authority and immutable input

TB47-EXEC consumed immutable CB53 package112 exactly as frozen. It did not configure, compile, relink, regenerate
discovery, repair package bytes or modes, mutate source/tests/fixtures/selectors, or run benchmarks.

- semantic source: `c772b53f1c42e117a948f14f77a33ab3dd2619a2`;
- immutable package112 artifact: `10119861923`, `m3-cp4c3-cb53-package112-result-34391561462`;
- package provider/download SHA-256:
  `3abab0f9d4248c838dc0009d3264fb68ce338a0f20160f7c4b325e28f2c24320`;
- selector409 SHA-256:
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, 409 rows;
- accepted-prefix selector count: 365;
- generic artifact-only harness SHA-256:
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- package root manifest: **28/28 verified**;
- per-identity control: `timeout -k 5s 180s`;
- outer elapsed cutoff: none.

## 2. Execution evidence and caller boundary

Authoritative workflow run **`34397425632`**, event SHA
`37cec8a3b6b9ae3c3f03b21f3047c8d42d03deb5`, completed successfully. The artifact-only execute job is
**`102620523147`** and completed successfully.

- result artifact: `10122211479`, `m3-cp4c3-tb47-result-34397425632`, provider/download SHA-256
  `e5cc14813173e005a1c14fb6ce9e62d520a9d458de49ee931afe7b6177d56366`;
- persistent log artifact: `10122212347`, `m3-cp4c3-tb47-log-34397425632`, provider/download SHA-256
  `d40b560d85c0d8f203091bdadeead1a3eec8a85822f6851500ddde6efa9dddf0`;
- all **409** selector identities executed exactly once in ordinal order, one fresh process per identity;
- selection mismatches: **0**;
- timeout count: **0**;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

The caller records `harness_exit=0`; its independent boundary check records `boundary_ok=true`,
`boundary_reason=ok`; the harness boundary records `script_exit=0`, `mode=--execute`, `runtime_started=true`,
`runtime_completed=true`, `preflight_completed=true`, `execution_view_verified=true`,
`orchestration_failure=false`, `selection_integrity=true`, and `timeout_count=0`.

## 3. Raw measured result

TB47-EXEC measured:

- **409 total**;
- **404 PASS / 5 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[368,369,370,374,398]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256:
  `093c4f009a800b56fe385e5129a1ee739fc1cb8b6534baa5fcc89896dadd1942`;
- failure-detail table SHA-256:
  `c761660aec3ee209c70299ba9d7d53cbb6dc97e04066c402f8a7b901bbbe830a`;
- resource-summary SHA-256:
  `dc83db754b0c1ff3bd94416ce824c8c0ef8a2ade5b2b1d9fd96b8bbfd731cb26`.

This is mechanically valid raw EXEC evidence. Because the gate remains RED, **TB47-EXEC does not promote itself**.
TB46-R1/package111 remains the reviewed semantic runtime authority until independent `M3-CP4c-3-TB47-REV`
adjudicates this result.

## 4. Ordinal367 — CB53 correction recovers the identity at runtime

Ordinal367 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` is **PASS**, selected exactly once
with exit 0. The earlier `FragmentCountRule` false rejection is absent; `FragmentCountRule` and `FragmentPartition`
each occur zero times in TB47 raw evidence. This is raw runtime confirmation that package112's frozen high-side-only
independent owner-count rule allows the measured produced witness.

Tracker intake: **`M3-CP4c3-TB47-EXEC-CAND-01` — RAW TEST-AUTHORITY CORRECTION RECOVERY / REVIEW REQUIRED /
NON-STABLE / UNPRICED**. EXEC records recovery only. Independent review owns final closure and any promotion.

The accepted/protected ordinal307 stale equality also remains **PASS**. It did not fire and remains byte-frozen;
TB47-EXEC makes no change to its prior out-of-scope review disposition.

## 5. Protected Part XII controls remain non-vacuously green

Protected 390/393/406/407 all remain **PASS** through the successful `PlanFrontier` evidence branch. The retained
receipts continue to record `branch=UncutCensus`, `censusPredicateExecuted=yes`,
`sameDomainCorruptionRejected=yes`, `terminalSubjectRelation=NotApplicable`,
`terminalSubjectBranch=PlanFrontier`, and `planFrontierEvidenceBranchExecuted=yes`.

The supporting evidence is non-empty: 390 publishes `m3Cp4c3BW3`; 393 publishes `m3Cp4c3OwnerMap`; 406 publishes
`m3Cp4c3UncutComponentPartitionCorrespondence`; 407 publishes a non-empty `m3Cp4c3PlanInteriorArcCensus` plus face
rows. Ordinal385 again publishes **300 established / 0 unavailable / 0 conflicting** ownership.

Frozen controls 404/408/409 also PASS.

## 6. Every observed RED categorized before closeout

The five RED ordinals reproduce their established separate failure surfaces and remain under their prior owners:

- **368** — prescribed sphere still fails before a cut graph with
  `NotProductionReady / CellularityNotEstablished / origin=RotationSystemInconsistent`, originating reason
  `TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable`; current failure-detail
  SHA-256 `7772f846dd26ce469de28a285182a6d98f90c35fdfbd84757dce229a2312fa21`.
- **369** — `certificate.saturationUsed` remains `true` where the identity requires the ordinary tree-cotree
  proposal, current failure-detail SHA-256
  `cc2ceeff468dea5dda3121548a68ab081518809783b06151eaa726ec183fdcbf`.
- **370** — the empty-network witness still returns `CellularityNotEstablished` (enum 4) rather than
  `EmptyNetworkOnClosedSurface` (enum 6) and lacks a source-face locus, current failure-detail SHA-256
  `7d3c2c192d07d482f0258a11509794a0f6e42d1ccd6dcf0d27a6e3e74626b4db`.
- **374** — the pre-classified folded-cone witness still stops at `atlasBuild=false`, current failure-detail SHA-256
  `f43da8d8de7d61b9132be3005bb652c732d1f6dc2f27eb87d8a181d2f2feaffa`.
- **398** — prescribed-sphere cut graph remains absent at `NotProductionReady/CellularityNotEstablished`, current
  failure-detail SHA-256 `c06eaa58a852f24fe6df465b2f8a783795294a9c1418a2dac0e391eb799bd2b5`.

These are surface recurrences, not newly discovered RED identities. EXEC neither merges their owners nor prescribes
corrections. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**,
ownership **300/0/0**, accepted package count **112** pending review.

## 7. Retired-predicate silence and immutability

Across the current result/log evidence there are zero occurrences of:

- `TraceArcDoesNotSeparateItsSides`;
- `UncutFaceComponentOrbitSeedNotUnique`;
- `RegionEulerCharacteristicNotOne`;
- `FragmentCountRule`;
- `FragmentPartition`.

The package/source/execution-view pre/post censuses are equal. No artifact mutation, source mutation, build, repair,
discovery, benchmark, or executable-mode repair path executed.

## 8. Regression-tracker intake and authority boundary

Every observed RED is categorized in `Regression_Root_Cause_Tracker.md` as a carried recurrence under its existing
owner. Ordinal367's RED-to-PASS transition is recorded as non-stable correction-recovery evidence. Accepted remains
365/365 and no new stable event/category is established by EXEC. Stable totals therefore remain **47 / 14 / 33**,
debt **5**, ownership **300/0/0**, packages **112**.

**Reviewed semantic runtime authority remains TB46-R1/package111** at 403 PASS / 6 RED until the independent review.
The raw TB47 result is not semantic promotion authority by itself.

## 9. Exact successor

**Exact next: `M3-CP4c-3-TB47-REV` — independent REVIEW + PLAN, runtime-free.**

The review must adjudicate ordinal367's runtime recovery, the five carried RED owners, protected non-vacuity,
stable accounting and whether package112/TB47 becomes promoted semantic runtime authority. It must perform mandatory
REVIEW-turn document consolidation and update `ORIENTATION.md`. No retry, product/test patch, compile or new runtime
is authorized before that review.
