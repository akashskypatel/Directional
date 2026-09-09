# M3-CP4c-3-TB46-R1 EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / SEMANTIC RED / RAW EVIDENCE PRESERVED / REVIEW REQUIRED

**Turn:** `M3-CP4c-3-TB46-R1`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-09

## 1. Authority and immutable input

TB46-R1 consumed immutable CB51 package111 exactly as frozen after CB52's runtime-free orchestration correction.
It did not configure, compile, relink, regenerate discovery, repair package bytes or modes, mutate source/tests/
fixtures/selectors, or run benchmarks.

- semantic source: `4f0663ef3468996abce6f59109f1c67f5be5f604`;
- immutable package111 artifact: `10112532452`, `m3-cp4c3-cb51-package111-result-34372482691`;
- package provider/download SHA-256:
  `62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`;
- selector409 SHA-256:
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, 409 rows;
- accepted-prefix selector count: 365;
- generic artifact-only harness SHA-256:
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- package root manifest: **28/28 verified**;
- per-identity control: `timeout -k 5s 180s`;
- outer elapsed cutoff: none.

The prior `M3-CP4c-3-TB46-EXEC` attempt remains orchestration-invalid at 0/409 and contributes no process row to
this execution. TB46-R1 starts selector409 again at ordinal 1 as frozen.

## 2. Execution evidence and caller boundary

Authoritative workflow run **`34382143529`**, event SHA
`a6577d580ea4b15f069e8216aced9669e5d65891`, completed successfully. The artifact-only execute job is
**`102569425154`** and completed successfully.

- result artifact: `10116449887`, `m3-cp4c3-tb46-r1-result-34382143529`, provider/download SHA-256
  `9f850944168660ea62060a2e0e7c4b04bd681a966664e124c6a41c87f141b842`;
- persistent log artifact: `10116450375`, `m3-cp4c3-tb46-r1-log-34382143529`, provider/download SHA-256
  `321da1297d65de858fa6191dc01e581e58587217c6f3b9aa515fc6bfe33a65ef`;
- all **409** selector identities executed exactly once in ordinal order, one fresh process per identity;
- raw per-identity logs: **409**;
- per-identity resource records: **409**;
- selection mismatches: **0**;
- timeout count: **0**;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

CB52's failure-containment correction is proved in the retained caller evidence. The caller records
`harness_exit=0`; its independent boundary check records `boundary_ok=true`, `boundary_reason=ok`; the harness
boundary records `script_exit=0`, `mode=--execute`, `runtime_started=true`, `runtime_completed=true`,
`preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`,
`selection_integrity=true`, and `timeout_count=0`.

## 3. Raw measured result

TB46-R1 measured:

- **409 total**;
- **403 PASS / 6 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[367,368,369,370,374,398]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256:
  `2f93290c92b1ab6a36ba4815f75956ec608042eb9c057caa3b42d17fd10b26ff`;
- failure-detail table SHA-256:
  `b2a4e24755306ae1b0123baf4cfc319b1836969474f4906c5585678c050196af`.

This is mechanically valid raw EXEC evidence. Because the gate is RED, `M3-CP4c-3-TB46-R1-REV` owns semantic
adjudication, stable pricing and promotion. TB46-R1 does not authorize a correction or promote package111 over the
currently reviewed TB45/package110 runtime authority.

## 4. Ordinal367 — corrected terminal rule advances to `FragmentCountRule`, but remains RED

Ordinal367 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` remains RED, but it advances
beyond TB45's `FragmentPartition` surface. The retained failure detail is now:

- `partition.has_value() == false`;
- independent proof clause: **`FragmentCountRule`**;
- failure-detail SHA-256:
  `73e3b627e6704240bc85ef3ca8c4d61f29c2ae53f8545e0c4b83ad983e2354a8`.

The frozen source makes the immediate failure relation precise. `independent_fragment_partition()` now skips a
final no-barrier segment only when its independently derived forward/reverse face-walk orbit IDs are equal. After
that traversal, `FragmentCountRule` is assigned only at the final per-source-face check

`fragmentOrbits[face].size() == tracePieces[face] + 1`.

Therefore CB51's requested terminal-separation branch is reached far enough to move the oracle from the prior
partition-construction clause to the later cardinality clause, but at least one source face violates that independent
count equation. The retained runtime evidence does not identify the face or the two cardinalities, so EXEC does not
guess whether the remaining mismatch is another test-oracle assumption or a product-side partition defect.

Tracker classification: **`M3-CP4c3-TB46-R1-EXEC-CAND-01` — RAW ORACLE CARDINALITY SURFACE / REVIEW REQUIRED /
NON-STABLE / UNPRICED**. Independent review must establish the missing per-face witness before assigning semantic
ownership or prescribing a correction.

## 5. Protected Part XII identities — 390 / 393 / 406 / 407 recover non-vacuously

All four protected identities change TB45 RED → **PASS** on package111. Each reaches the successful-plan
`PlanFrontier` evidence branch, executes its census predicate, and rejects the deliberately corrupted same-domain
copy. Exact retained receipts are:

- 390:
  `m3Cp4c3R8Receipt;ordinal=390;branch=UncutCensus;censusPredicateExecuted=yes;terminalSubjectRelation=NotApplicable;sameDomainCorruptionRejected=yes;terminalSubjectBranch=PlanFrontier;planFrontierEvidenceBranchExecuted=yes`
- 393: same receipt fields with `ordinal=393`;
- 406: same receipt fields with `ordinal=406`;
- 407: same receipt fields with `ordinal=407`.

Additional raw evidence is non-empty: 390 publishes `m3Cp4c3BW3`; 393 publishes `m3Cp4c3OwnerMap`; 406 publishes
`m3Cp4c3UncutComponentPartitionCorrespondence`; and 407 publishes a non-empty
`m3Cp4c3PlanInteriorArcCensus` plus face rows.

Thus TB46-R1 supplies the success-path runtime proof requested by CB51. EXEC records the recovery; the required
review decides semantic closure/promotion.

## 6. Carried REDs and frozen controls

The five separately owned carried REDs reproduce their established surfaces:

- **368** — prescribed sphere still fails before a cut graph with
  `NotProductionReady / CellularityNotEstablished / origin=RotationSystemInconsistent`, originating reason
  `TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable`;
- **369** — `certificate.saturationUsed` is still `true` where the ordinary-proposal identity requires `false`;
- **370** — empty-network fixture still returns `CellularityNotEstablished` (enum value 4) instead of
  `EmptyNetworkOnClosedSurface` (enum value 6), and still carries no source-face locus;
- **374** — folded-cone witness still stops at `atlasBuild=false`, before the intended owner-election predicate;
- **398** — prescribed-sphere cut graph remains absent at `NotProductionReady/CellularityNotEstablished`.

Their failure-detail SHA-256 values are respectively:

- 368: `183f48e2adaddcdcfb06ef1f1680d5d698c28214bc2766da44ac1331d00ef0c4`;
- 369: `ce0d70ea9f184ed9519181090e818e5c046c02e45322cab35a8bcc35bf1d86ce`;
- 370: `a705efb49a5a4bd3495572ff212424cea8ab333e9181c3bfa9153842e859eba4`;
- 374: `59e60a6254ead8a96be987a937973294356c5c90f06c607908822a0185c0a190`;
- 398: `938db0ab7d9766d566d722b900519c501d4e8d47e0cb564e6c646bde891e31c6`.

These are carried under their existing independent owners; EXEC does not merge or reprice them.

Frozen controls **311/312/314/315/356/357/404/408/409 all PASS**. Ordinal385 publishes
`sourceFaceCount=300;established=300;unavailable=0;conflicting=0;conflictCensusPublished=true;conflictRowCount=0`.

Retired-code silence holds across all 409 raw logs:

- `TraceArcDoesNotSeparateItsSides`: 0 occurrences;
- `UncutFaceComponentOrbitSeedNotUnique`: 0 occurrences;
- `RegionEulerCharacteristicNotOne`: 0 occurrences.

## 7. Immutability and evidence integrity

The package authority record re-verifies artifact `10112532452`, exact provider/download digest
`62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`; selector authority records 409 rows at
the frozen selector hash; the identity map contains 409 entries and hashes to
`f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`.

The retained postflight reports:

- `package_census_equal=true`;
- `source_census_equal=true`;
- `execution_view_census_equal=true`.

No artifact mutation, source mutation, build, repair, discovery, or benchmark path executed.

## 8. Regression-tracker intake and accounting

Every observed RED is categorized before TB46-R1 closes:

1. ordinal367 is the new raw `FragmentCountRule` oracle-cardinality surface described in §4 and routes to review;
2. ordinals368/369/370/374/398 retain their existing distinct owners and reproduced behavior classes.

The four protected identities recover, but recovery is not priced or promoted by EXEC. Accepted remains 365/365.
No newly independent stable event or recurrence is established by this execution. Stable accounting therefore
remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, ownership **300/0/0**, accepted
package count **111**.

TB45/package110 remains the promoted semantic runtime authority pending independent review of TB46-R1's raw result.

## 9. Exact successor

**Exact next: `M3-CP4c-3-TB46-R1-REV` — independent REVIEW + PLAN, evidence-only first.**

The review must adjudicate ordinal367's `FragmentCountRule` surface, the runtime recovery of 390/393/406/407, the
five carried RED owners, stable accounting and promotion. It must perform mandatory REVIEW-turn document
consolidation and update `ORIENTATION.md`. No retry, product/test patch, compile or new runtime is authorized before
that review.
