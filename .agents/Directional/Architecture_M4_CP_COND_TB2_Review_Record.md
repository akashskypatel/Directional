# M4-CP-COND-TB2 Review Record

**Turn:** `M4-CP-COND-TB2-REV`
**Disposition:** COMPLETE / MECHANICAL RECOVERY ACCEPTED / NEGATIVE-INDEX TEST AUTHORITY REJECTED / CP-COND OPEN
**Runtime/build/product mutation:** none
**Exact successor:** `M4-CP-COND-CB3`

## 1. Decision

`M4-CP-COND-TB1-EXEC-CAND-01` is **CLOSED / RECOVERY PROVED / NON-STABLE**. TB2 proves the TB1 stop was package-owner closure: unchanged semantic source `b576d061e23873b7b4193b158138d2097c75a728`, once packaged with all four selector owners, completes the frozen runtime surface with zero RED/crash/selection mismatch.

CB2 artifact `10321878900` is nevertheless **NOT PROMOTED** and CP-COND remains OPEN. Review opens `M4-CP-COND-TB2-REV-CAND-01` as **OPEN / TEST-AUTHORITY / NEGATIVE-INDEX RAW-PRECONDITION ORACLE INADEQUATE / NON-VACUOUSNESS GAP / NON-STABLE**.

The decisive defect is `InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved`. Frozen authority requires an independent exact/discrete cycle oracle to derive a valid negative index and prove field admissibility from raw branch/transport data. The test does not. Its `exactDiscreteNumerator` is authored from constants `5 * (72 - 90) / 90 = -1`; the raw field is separately populated with binary64 `cos/sin` values; the test then checks the authored integer and only verifies the identity conditioner preserved faces/field bytes. No cycle is derived from those bytes, no raw cross-face transport is reconstructed, and no mutation discriminator proves that `-1` depends on the raw transport.

This is a green test-authority defect, not a product-semantic RED. Accepted runtime authority remains CP3 package `10307919492` / selector408 **408/408**.

## 2. Independent mechanical re-derivation

Review re-opened the primary artifacts rather than trusting EXEC prose:

- selector408 = 408 LF rows / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 = `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- focused ledger = 14 PASS, SHA-256 `04e0a63847d29b3d5dc3a1628986711f37de3cace1d61902a30fd1300a9d26d7`;
- report-only ledger = one SKIP, SHA-256 `c3a5b066e949443afe8ba36efb7cd3edf76b6331fc8cc5e17d8c65f369772c2f`;
- selector ledger = 408 PASS, SHA-256 `2954548b7f0c3e517cadb2672608f42a30a4ffe933955421f6b0d1dc6e552773`;
- owner census = 30 / 262 / 75 / 41;
- package and execution-view pre/post censuses are byte-identical; source and selector equality are true;
- root `SHA256SUMS` verifies 27/27, manifest SHA-256 `10f45675750aca16d99fbc69a6affc1a75dd5b112977de5fb32da34e47bf37ad`;
- boundary = 423 processes, 422 PASS + 1 report-only SKIP, all repair/rebuild/mutation flags false.

That closes the package candidate mechanically. It cannot close CP-COND because mechanical green cannot substitute for frozen witness semantics.

## 3. Negative-index non-vacuity re-derivation

`make_negative_index_witness()` has two disconnected evidentiary tracks:

1. actual raw binary64 branches are populated from `cos/sin(2πi/5)`;
2. `exactDiscreteNumerator` is assigned from compile-time integers `sectors=5`, `representativeStepDegrees=72`, `quarterTurnDegrees=90`.

The focused test asserts the second track's `-1`, runs `ConditioningPolicy::production_identity()`, requires `Produced`, and checks byte-preservation. `production_identity()` is the default policy and `canonicalizeFieldBranches=false`; the conditioner's exact Z4 opposite-pair canonicalization/admissibility path runs only when that option is true. Thus this identity does not independently prove that its actual raw field is an admissible negative-index witness.

The non-vacuity falsifier is structural: the expected `-1` calculation reads no raw branch byte. A raw-data mutation can change the subject while leaving the asserted precondition untouched. Existing lessons 157/160 and 64j already cover this family, so no new `LESSONS.md` entry is required.

## 4. Frozen exit adjudication

`Architecture_M4_CP_COND_Frozen_Definitions.md` requires the negative-index witness to derive its discrete cycle/index and admissibility independently from raw authority. That requirement is unsatisfied.

- high-valence, sliver, inadmissible-field, correspondence tamper, idempotence and S6 gates remain usable;
- boundary-truncated separatrix remains correctly **report-only / non-selector / blocked**;
- negative-index gate is not semantically acceptable;
- therefore CP-COND exit is not proved and package `10321878900` cannot be promoted.

No production rollback is inferred. Product source is frozen for the corrective successor.

## 5. Accounting and carried obligations

No accepted runtime authority transitioned PASS→RED. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. `M4-CP-COND-TB2-REV-CAND-01` is non-stable.

Carried unchanged:

- `M4-CP3-TB1-R1-REV-OBS-01` — multiplicity-2 end-to-end oracle before CP4;
- `M4-CP3-CB4-REV-OBS-02` — row399 path/`sourceFaces` divergence tamper at next legitimate row399 touch;
- TB3 provenance warning — historical-claim bound;
- `G4-B002` debt 3 — M4-CP4 gating;
- `G4-B003` debt 2 — M5 gating.

## 6. EXEC closeout gap repaired

The prior EXEC closeout named `Architecture_M4_CP_COND_TB2_EXEC_Report.md`, but the published patch did not create it. Review reconstructed that record from immutable primary evidence and labels it explicitly REVIEW-RECONSTRUCTED. No new runtime claim was introduced.

## 7. Consolidation

Consumed CP-COND DEFN/CB1/TB1/CB2 per-turn plans and records are folded into `M4_Consolidated_Record.md`. Retained current authority is:

- `Architecture_M4_CP_COND_Frozen_Definitions.md`;
- Review-reconstructed `Architecture_M4_CP_COND_TB2_EXEC_Report.md`;
- this Review record;
- exactly one next plan, `Architecture_M4_CP_COND_CB3_Code_Build_Plan.md`;
- selector files/manifest and durable project records/policies.

## 8. Exact successor

`M4-CP-COND-CB3` is **test-authority-only Code + Build**. Only the negative-index witness/helper/oracle in `tests/InputConditionerTests.cpp` may change semantically. The corrected oracle must derive exact/discrete cycle index and field admissibility from actual raw binary64 branch/mesh/transport bytes, independent of production output, and include a raw-data mutation discriminator that changes or invalidates the oracle result. Product/public API/CMake/selector/A3/A4 semantics stay frozen. Compile/package the complete TB-runnable owner set with GMP/GMPXX and no runtime, then freeze artifact-only TB3 over the unchanged complete 14 + report-only + selector408 surface. If a product change is required, STOP and return to Review/DEFN.

## Review closeout

| Required item | Result |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector408 `c689c0cd...484`, first403 `c3f509af...70cb7` |
| Decisive claims independently re-derived | PASS — package, ledgers, owner census, immutability and negative-index source |
| Non-vacuity checked | FAILS CANDIDATE — negative-index expected `-1` is independent of raw branch/transport bytes |
| Prior obligations discharged/carried | PASS — package candidate closed; unrelated obligations retain owners |
| Stable accounting | UNCHANGED — **49 / 14 / 35**, debt **5** |
| New candidate | PASS — `M4-CP-COND-TB2-REV-CAND-01` open / test-authority / non-stable |
| ORIENTATION / ROADMAP / TODO / handoff / tracker / changelog | PASS — advanced to CB3 |
| Selector manifest | N/A — selector unchanged |
| LESSONS | N/A — existing oracle/non-vacuity lessons cover the pattern |
| Consolidation | PASS — consumed CP-COND docs folded; current evidence/Review/one next plan retained |
| Successor frozen | PASS — exactly `M4-CP-COND-CB3`, runtime-free compile-only |
| Turn boundary held | PASS — Review/documentation only; no product/test/fixture/selector/build/runtime mutation |
| `review_check.py boundary` | PASS — ALL CHECKS PASSED; no product/test/fixture/build or selector mutation; durable markers preserved |
| Durable publication / cleanup / final authority re-read | PASS — primary patch `ac15f316...d33856c` published by Drive run `34775495731` as commit `456bf8782cfce8b7fb76e23cfcb0adba9256e0b1`, staged file permanently deleted, and cleanup run/job `34775550382 / 103772892241` completed at `b77560d5889f6ee552062eb578b1d87158a811c8`; follow-up TODO correction patch `f3d01b96...8cca23` published by Drive run/job `34775736249 / 103773386924` as commit `8d56a04d363a3ae0d4a88f535c25a42b9ce679d8`, staged file permanently deleted, and post-correction cleanup run/job `34775830834 / 103773638396` completed at `f67f166f026cc219b2c752b9f90131df955557cd`. Final re-read at `f67f166f...557cd` confirms exactly seven durable workflows, absent turn-payload/workflow-observation state, connector-triggers reduced to `source-snapshot` with only the protected CP3-R4 marker, `TODO.md` naming exactly `M4-CP-COND-CB3`, and PR #8 open / draft / unmerged before metadata closeout. |
