# M4-CP4-TB3 Independent Review Record

**Turn:** `M4-CP4-TB3-REV`
**Canonical turn:** Optional independent Review / runtime-free
**Reviewed runtime report:** `Architecture_M4_CP4_TB3_Artifact_Only_Test_Benchmark_Report.md`
**Validated compiled source:** `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431`
**Reviewed candidate package:** `10591801825`
**Decision:** **APPROVED**
**Planning successor:** `M5-DEFN` under `Architecture_M5_DEFN_Definition_Plan.md`

## 1. Evidence reviewed

Primary immutable evidence was re-opened rather than accepted from the EXEC summary alone:

- CB8 package artifact `10591801825`, compile run/job `35468097574 / 105964043163`, provider/download ZIP SHA-256 `20d9b07bae631e68f3292ee37ccb80c4724bae6eec0c50cd2274c36443183da6`;
- TB3 runtime run/job `35470130614 / 105969470184`, result artifact `10592987234` SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, log artifact `10592817804` SHA-256 `8d10ad76c42cdb9a6e6bc14a3a213deab2b3d3917c361c6d92bb95f313647d5b`;
- exact packaged source archive SHA-256 `4d057381ba3f1caed55579f7a9b662753632637eb0aff7b1432326d8e557021a` and package manifest SHA-256 `30c3f51fa0e43882d1a3c1227f58c069023007e38dbdc9a96c832ce152157b5a`;
- `Architecture_M4_CP4_Frozen_Definitions.md`, the accepted selector427 file, published selector430, the three appended test bodies, their owning production/validator paths, and the carried M5/M6 debt assignments.

No test, benchmark, compiled Directional binary, build, configure, relink, generated discovery, or corrective runtime was executed in Review.

## 2. Independent immutable-authority re-derivation

Review independently verifies the package rather than trusting the report:

- package ZIP bytes re-hash exactly to `20d9b07bae631e68f3292ee37ccb80c4724bae6eec0c50cd2274c36443183da6`;
- root `SHA256SUMS` hashes to `30c3f51fa0e43882d1a3c1227f58c069023007e38dbdc9a96c832ce152157b5a` and all **26/26** entries verify;
- source receipt is exactly `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431`; preflight/build receipts are zero; all five source-status receipts are empty;
- command-boundary evidence records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`; CMake/link evidence independently contains `DIRECTIONAL_ENABLE_GMP=ON`, `libgmpxx.so`, and `libgmp.so`;
- all four selector-owner executables are present with archived mode `0755`.

Selector430 independently re-hashes to **430 LF rows / 35,001 bytes / `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`**. Its first 427 rows independently hash to accepted selector427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. The only appended identities, in exact order, are:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated`
2. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder`
3. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection`

Static ownership independently re-derives **31 authority-kernel / 283 producer / 75 completion / 41 validation = 430**.

## 3. Independent runtime-ledger and postflight re-derivation

Review re-parses the TB3 result artifact itself:

- ordinals are exactly **1..430** and identity-map rows equal selector430 line-for-line;
- every ledger row has exactly one selected test, zero skipped tests, `PASS`, and exit `0`;
- each ledger `raw_log_sha256` matches its raw process log; every raw log contains exactly one `[ RUN ]` and one `[ OK ]` and no skipped/failed marker;
- independent totals are **430 attempted / 430 PASS / 0 RED / 0 SKIP / 0 crash / 0 invalid selection / 0 unexecuted**;
- owner PASS totals independently re-derive **31 / 283 / 75 / 41**;
- result `SHA256SUMS` independently verifies **447/447** entries.

Mandatory immutable postflight is exact. Package, packaged-source, and execution-view byte+mode censuses match before/after with respective census SHA-256 values `7e2bff2e702a2cb1e25c0e3b0706dafff050720fde3c61bcaf3199508dd676f7`, `c673ccbbe66c3d84d3050ff6e144adb9941d6ed89283ac34f6151d535e96609a`, and `a2f2db8dd1f03b2cd3200e3b914cef33645671d6056c8c1873bb9ae473dfd114`. The execution boundary reports all configure/compile/relink/discovery/repair/mutation counters and benchmark count as zero.

## 4. Non-vacuity of the three CP4 publication rows

### 4.1 Work/boundedness receipt

`ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` runs the real baseline producer, independently derives span count and per-phase `1 + 2E` work, requires matching producer/validator work counts and the aggregate bound, validates order/prefix progress/matching dimensions/exact width, and then independently corrupts count, order, progress, matching dimensions, and width. `ASSERT_GT(perPhase, 1U)` prevents a vacuous zero-edge tamper path. The validator separately derives parity vertex/edge counts and T-join work, recomputes the minimum-cardinality result, validates dimensions, reset/final progress, and lexicographic optimum.

### 4.2 Same-region multiplicity two

`ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` executes the produced torus path through `remesh_from_raw_cross_field`, finds an actual A2b region boundary arc occurring exactly twice, proves two distinct occurrence ordinals, and requires the baseline binder to preserve exactly two incidences with their ordinals/orientations. Deleting one incidence from a validation candidate must fail. This is direct production evidence, not a synthetic/direct-plan substitute.

### 4.3 Zero-transport helper precondition

`ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` proves the zero-transport helper succeeds on the flat four-triangle fan, independently computes the non-flat fan's apex angle defect and requires it to be nonzero, then requires the zero-transport construction to fail exactly with `NonIntegralCycleLift`. The negative therefore proves the helper's precondition rather than merely checking a hard-coded failure.

## 5. CP4 exit theorem adjudication

Every amended CP4 exit conjunct in `Architecture_M4_CP4_Frozen_Definitions.md` §2 is satisfied:

1. **Exact predecessor:** selector427 is independently re-hashed as the exact first427 prefix of selector430.
2. **No M4-owned produced-witness debt:** DEFN-R1/R2 preserve the two periodic debts at M5 and the closed candidate-bearing-complex debt at M6; no debt is deleted or miscredited to M4.
3. **Production A3 work evidence:** row428 plus independent validator inspection establishes non-vacuous bounded/reproducible work evidence and tamper rejection.
4. **Same-region multiplicity two:** row429 provides direct produced A2b→baseline evidence plus deletion tamper.
5. **Zero-transport audit:** row430 proves flat success and independent non-flat typed rejection.
6. **Pre-publication review:** the three appended identities were independently reviewed before CB8 publication under DEFN-R2 / TB2-R2 Review authority.
7. **Fresh cumulative artifact-only proof:** TB3 executes exact selector430 as 430 fresh processes with exact immutable postflight and no forbidden execution or mutation.

**Decision: APPROVED.** Package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` is promoted as accepted M4 runtime authority under selector430 **430/430**. Selector427 becomes its accepted historical prefix. `M4-CP4` closes and milestone **M4 closes / is accepted**.

This closure does not assert production readiness. M5-M8 remain open, including all five produced-witness debts already assigned to M5/M6.

## 6. Regression and debt accounting

TB3 observed no failure surface and Review found no hidden selection, mutation, postflight, or non-vacuity defect. No new stable regression event/category/recurrence and no new non-stable candidate is justified. Stable accounting remains **49 events / 14 categories / 35 recurrences**.

Produced-witness debt remains **5**:

- M5: periodic relation-owner reorder `G4-B002`, missing-owner `G4-B002`, `FullPeriodicRotationAndTranslationMaterialize`, and `TamperedFullPeriodicTransformIsRejected`;
- M6: `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on authoritative A5 occurrence-complex production.

## 7. Challenge to existing diagnosis and simpler alternatives

The existing CP4 diagnosis is upheld. Review specifically rejects three tempting but invalid simplifications:

- accepting 430/430 mechanically without independently checking selector prefix, one-selected routing, raw-log hashes, postflight, and non-vacuity;
- pulling diagnostic `surfaceCellContext.hasArrangement` backward into M4 merely to discharge the M6-owned occurrence-complex debt;
- weakening M5/M6 carried produced-witness debts because M4's final cumulative gate is green.

No corrective Code + Build plan is warranted. The smallest valid successor is the already-scheduled planning-only `M5-DEFN`, which freezes relation identity/path-certificate semantics before M5 implementation.

## 8. Authoritative next plan

`Architecture_M5_DEFN_Definition_Plan.md` is the sole next-turn plan. `M5-DEFN` is runtime-free and must freeze canonical relation IDs, explicit selected path certificates, the M5 tamper/failure matrix, witness-stage reachability, and exact ownership of the four M5 produced-witness debts before `M5-CP1` implementation begins.

## 9. Integrity confirmation

- Production code changed: **no**
- Test or benchmark logic changed: **no**
- Build configuration changed: **no**
- Selector bytes changed: **no**
- Tests or benchmarks executed in Review: **no**
- Compile/configure/relink executed in Review: **no**

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | **YES** — selector430 `1c412850...9db6`; first427 `f9c88380...e86f` |
| Decisive claims independently re-derived | **YES** — package 26/26, selector/owners, all 430 ledger rows/raw hashes, 447/447 result manifest, postflight, and three row contracts |
| Non-vacuity checked | **YES** — row428 work/tampers, row429 produced multiplicity-two/tamper, row430 flat-success + non-flat exact rejection |
| Prior obligations discharged/carried | **YES** — CP4 conjuncts discharged; four M5 debts + one M6 debt carried unchanged |
| Stable accounting | **49 events / 14 categories / 35 recurrences; debt 5** |
| New candidates/obligations recorded | **NONE** — TB3 is all-green and Review finds no new defect surface |
| ORIENTATION currency line | **UPDATED to `M4-CP4-TB3-REV` / 2026-09-19 UTC** |
| ORIENTATION §3 / §4 / §7 / §8 | **§3, §4 and §7 updated; §8 unchanged because no new recurring pattern was found** |
| CHANGELOG | **UPDATED** — root and agent changelogs record package promotion and M4 closure |
| ROADMAP | **UPDATED** — M4/CP4 closed; exact next `M5-DEFN` |
| Selector manifest | **UPDATED** — selector430 accepted current authority; selector427 historical accepted prefix |
| LESSONS | **UNCHANGED** — no novel recurring engineering/review pattern beyond existing durable rules |
| Consolidation under CLEAN_UP_POLICY | **COMPLETE** — superseded CP4 per-turn documents indexed/folded; current TB3 runtime report, this Review, closures, normative definitions/selectors and one M5 next plan retained |
| Successor frozen | **YES — `M5-DEFN`**; falsifiers and stop rules are frozen in `Architecture_M5_DEFN_Definition_Plan.md` §4 |
| Turn boundary held | **YES — documentation/static evidence only; no implementation or runtime** |
| review_check.py boundary | **PASS — `python3 .agents/Directional/tools/review_check.py boundary --expect-selector 430=1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`** |
| `STATUS` lifecycle maintained | **YES — entry beacon published; final COMPLETE beacon is reserved as the final repository write** |
| Pushed to origin, branch in sync | **YES** — final documentation authority and temporary-state cleanup are verified on the working branch immediately before the final `STATUS` beacon; no ahead/behind state remains |
