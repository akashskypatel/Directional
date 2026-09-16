# M4-CP-SCALE-TB9-REV — Independent Review Record

**Date:** 2026-09-16 UTC
**Verdict:** **ACCEPT / PROMOTE CB10 PACKAGE UNDER UNCHANGED SELECTOR425 / DISCHARGE S4 PREREQUISITE OBSERVATION / PRODUCT S4 STILL UNIMPLEMENTED**
**Authorized successor:** `M4-CP-SCALE-CB11`

## 1. Scope and boundary

This is a runtime-free Review + Plan turn. It does not modify product, test, fixture, selector, benchmark or build source and does not execute Directional runtime. Review independently reopens the immutable CB10 package `10455353524`, TB9 run/result/log/nested evidence, semantic source `bebb14e32a0ac53dd420acf46bfa34410cf759a1`, selector425, and the corrected prerequisite source rather than treating the TB9 report as self-proving.

The question is narrow: whether the corrected S4 prerequisite establishes an independent production-reachable necessary-condition oracle with the required positive/adversarial/enumeration/decision-neutral controls, while the complete accepted selector remains green and the immutable package remains unchanged. This Review does **not** implement S4, publish selector426, claim S4 cumulative gate credit, or close CP-SCALE.

## 2. Immutable evidence independently reopened

Review reverified the following bytes and identities:

- CB10 candidate artifact `10455353524`, provider SHA-256 `b891318511ef6db2f6317abac99a4b7e1511fe6d4ebc58bdd048cdc49a757de9`;
- semantic source `bebb14e32a0ac53dd420acf46bfa34410cf759a1`; GitHub commit metadata changes exactly `tests/FieldAlignedCurveNetworkTests.cpp` and no product/CMake/fixture/selector source;
- packaged source archive SHA-256 `884ff6703f290df8b3479e35945cb3dc29b0732e3810eb66528759721d8366ae`;
- package `SHA256SUMS` SHA-256 `1219fbe0550d260be929e5dc4b7d3a4afa21fc1d1e15a992114e982c9a74d1d4`, 28/28 entries verified; compile and preflight exit receipts are zero, source-status receipts are empty, `runtimeExecution=false`, and GMP/GMPXX linkage evidence is present;
- TB9 run/job `35121594986 / 104880514495`, result artifact `10458072304` / provider SHA-256 `c2a11b62de22b520e972239a21d815ba69dede50c117e3cc294b22a3848ae250`, and log artifact `10458461955` / provider SHA-256 `2082bbbadd0d3b869967d9227a2e77148760244c62409796e551f0e4acbd4f6b`;
- nested evidence ZIP SHA-256 `01040836e8138ec92cd624cfc7bf571d69657c2c7f7dbb288f7afe92cc4cc933`; its 1304-entry self-manifest hashes to `e9e879efbe7fc78bc0448e3f3847e705e88a78b00d766e2f98705afa389a9b93` and independently verifies entry-by-entry;
- selector425 exactly 425 unique LF rows, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; its first424 rows hash exactly to accepted selector424 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.

No selector426 exists in the reviewed candidate.

## 3. Focused prerequisite mechanics are complete and non-vacuous

The focused identity `M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral` ran in one fresh producer-test process with exactly **1 selected / 1 executed / 1 passed / 0 skipped**, exit `0`. Its structured receipt count is exactly one and `requiredFieldsValid=true`.

The corrected test no longer lets a failure in the negative subject hide the positive/adversarial/enumeration controls: subject-level availability and assertions are non-fatal where required and the terminal receipt is emitted only after every control executes. The receipt proves all three raw/invariant/final-certificate views were available for negative, positive and adversarial states, plus `enumerationInvariant=true` and `decisionNeutral=true`.

This is non-vacuous in both directions: the empty-cut state rejects early, the accepted-cut state does not, the adversarial state exercises the one-way safety implication, reversing accepted-cut enumeration leaves the independent state invariant, and a fresh production rerun reproduces accepted cuts/certificate/semantic/provenance digests.

## 4. S4 arithmetic independently re-derived

For the production-reachable empty-cut torus state, the independent raw oracle publishes `V=48`, `E=48`, graph components `c=4`, source components `s=1`, source Euler `chi=0`, and four connected complement components. Each complement component has valid boundary cycles, two boundary walks, Euler zero and therefore is annular/non-disc.

The necessary-condition arithmetic is:

`b1 = E - V + c = 48 - 48 + 4 = 4`

`F_required = chi - s + b1 = 0 - 1 + 4 = 3`

while the independently observed complement count is `F_observed=4`. The mismatch is decisive for the covered `BettiFaceCountMismatch` class: a cellular decomposition cannot have both values. The corrected test therefore rejects this state without importing the final product certificate's face-walk-orbit count.

For the production-accepted cut set, the independent state is `V=72`, `E=76`, `c=1`, `s=1`, `chi=0`, with four disc complement components. Hence `b1=76-72+1=5` and `F_required=0-1+5=4=F_observed`; the early oracle does not reject and the unchanged final certificate proves embedded cellularity.

The one-edge adversarial state is independently distinct (`V=49,E=49,F=4,c=4,s=1,chi=0`). It early-rejects and the unchanged final certificate is non-cellular. Review does not infer the converse: S4 remains a partial necessary-condition accelerator, not replacement topology authority.

## 5. Final authority remains single and unchanged

The corrected prerequisite respects the frozen authority split. `SurfaceCutGraphCellularityCertificate::proves_embedded_cellularity()` plus per-face disc topology remains final product authority. The independent oracle is a test-side falsifier for a future accelerator. The negative pairing is only `earlyReject => finalReject`; it does not equate connected complement components with product face-walk orbits off the cellular domain and does not revive the retired source-support Euler proxy.

`SurfaceCutGraph::canonical_candidate` still initializes the candidate cut set empty before proposal mutation, so the negative is production-reachable. The future production accelerator is permitted only after that fixed candidate state exists. It may skip an expensive final-certification attempt when the necessary condition proves failure, then continue the same existing proposal path; it may not return a new semantic failure, add/remove/reorder cuts, backtrack, repair topology, or make its own acceptance decision.

## 6. Complete selector425 independently re-derived

Review parsed all 425 TB9 selector process ledger rows and joins them to the static owner map. Ordinals are contiguous 1–425; every row is exit `0`, selected/executed/passed/skipped `1/1/1/0`, result `PASS`. Outcome census is exactly **425 PASS / 0 RED / 0 SKIP / 0 crash / 0 timeout / 0 selection mismatch / 0 unexecuted**.

Owner census independently sums to **30 authority-kernel / 279 producer / 75 completion / 41 validation** and exactly matches the frozen source/CMake ownership map. The focused S4 prerequisite is outside selector425, so TB9 used **426/426 total fresh runtime processes**: one focus plus 425 selector processes. No focused PASS is imported as cumulative selector credit.

## 7. Immutable postflight independently rechecked

TB9's postflight reports package/source/execution-view/fixture census equality, and Review independently verifies the evidence manifest carrying those receipts. The execution prohibition receipt keeps configure, compile, relink, code generation, chmod, package repair, selector mutation, benchmark execution and discovery/list/help/version operations false.

The package manifest, source archive, selector425 and first424-prefix hashes remained exact. There is no evidence of runtime-side repair or candidate mutation.

## 8. Adjudication

Review **PROMOTES package `10455353524` / source `bebb14e32a0ac53dd420acf46bfa34410cf759a1` as current M4 runtime authority under unchanged selector425 425/425**. This promotion replaces TB7 package authority but does not alter selector authority or identity count.

`M4-CP-SCALE-DEFN-OBS-03` is **DISCHARGED / INDEPENDENT S4 PREREQUISITE ORACLE + REACHABLE NEGATIVE + FRESH RUNTIME + REVIEW PROVED / NON-STABLE**. The prior CB9/TB8 test-authority defect remains historical and non-stable; the corrected CB10/TB9 path supplies the missing proof.

No accepted PASS-to-RED transition, regression candidate or new category is observed. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

This is prerequisite acceptance only. S4 product semantics are still absent, selector426 is not authorized, and CP-SCALE remains open.

## 9. Exact successor — `M4-CP-SCALE-CB11`

The next bounded turn is production S4 activation under `Architecture_M4_CP_SCALE_CB11_S4_Product_Activation_Code_Build_Plan.md`.

CB11 may add only the minimum production-side exact necessary-condition accelerator and its focused product test. The fixed-candidate invariant must be evaluated before the final actual-embedded certificate can accept/reject that same state; an early reject may only bypass that final certification attempt and fall through to the **unchanged existing cut-proposal path**. The independent prerequisite oracle remains test authority and must not be replaced by the product implementation under test.

The decisive pre-runtime falsifiers are frozen in the CB11 plan: if the proposed observed-complement count is merely `proposal_components`, face-walk-orbit count, or any representation not independently proved equal to the accepted raw complement authority on the covered states; if deleting the accelerator would not remove a demonstrated final-certification attempt; if accepted cuts or pre-existing final certificate fields change; or if the implementation needs cut reordering/backtracking/repair/final-certificate weakening, CB11 stops for Review instead of broadening.

CB11 is Code + Build only. Selector425 stays byte-frozen; no selector426 is created; no Directional runtime executes. A successful CB11 package advances to a fresh artifact-only `M4-CP-SCALE-TB10-EXEC`, then mandatory Review, before any publication row can be considered.

## 10. Prior obligations

- `M4-CP-SCALE-DEFN-OBS-03` — **DISCHARGED here** by corrected test authority + fresh focused runtime + selector425 + independent Review.
- `M4-CP-SCALE-TB1-REV-OBS-01` — **CARRIED**; S1 representative/stress calibration before any numeric gate.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **CARRIED**; dedicated audit of remaining zero-transport helper callers.
- `M4-CP-SCALE-DEFN-OBS-01` — **CARRIED**; S2 arrival ordering still lacks same-seam exact fallback authority.
- `M4-CP-SCALE-DEFN-OBS-02` — **already discharged by TB6 Review**.
- `M4-CP-SCALE-DEFN-OBS-04` — **CARRIED**; genus>=2 construction/reachability owed, torus genus1 receives zero S5 credit.
- `M4-CP-SCALE-TB4-REV-OBS-01` — **already discharged by TB5 Review**.
- `M4-CP-SCALE-TB6-REV-OBS-01` — **already discharged by TB7 Review**.
- `M4-CP3-TB1-R1-REV-OBS-01` — **CARRIED** to cumulative M4-CP4; same-region multiplicity-2 independent oracle.
- `M4-CP3-CB4-REV-OBS-02` — **CARRIED** to next legitimate row399 touch; path/`sourceFaces` divergence tamper.
- `G4-B002` — **CARRIED**, three produced-witness debts at M4-CP4. `G4-B003` remains two debts at M5.

## 11. Document consolidation

Per `CLEAN_UP_POLICY.md`, this Review preserves durable CB10/TB9 facts in this record and `M4_Consolidated_Record.md`, then retires superseded per-turn role documents. The folded index records exact filename/line-count/role for the CB10 plan/report and TB9 execution plan already retired by TB9 stale-evidence cleanup, plus the now-superseded TB7 runtime report and TB8 Review. The retained CP-SCALE role set is the frozen definitions, current TB9 runtime-authority report, this TB9 Review, exactly one CB11 plan, consolidated history, selector425/history, and durable trackers/changelogs.

No selector, policy, frozen-definition document, closure record or durable project authority is consolidated.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; first424 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` |
| Decisive claims independently re-derived | package/evidence manifests; S4 `b1`/required-face arithmetic; one-way safety; all 425 ledger outcomes/owners; postflight prohibitions |
| Non-vacuity checked | negative rejects, positive does not, adversarial implication executes, reversed enumeration and production rerun both execute; focus receipt is terminal |
| Prior obligations discharged/carried | `DEFN-OBS-03` discharged; remaining CP-SCALE/CP3/debt obligations explicitly carried in §10 |
| Stable accounting | 49 events / 14 categories / 35 recurrences; debt 5; accepted package `10455353524` under selector425 |
| New candidates/obligations recorded | no regression candidate; successor product-activation proof obligations frozen in CB11 plan |
| ORIENTATION currency line | `M4-CP-SCALE-TB9-REV`, 2026-09-16 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated current authority/S4 state; torus row updated; open problems reordered with `DEFN-OBS-03` discharged; TB8 test-authority pattern marked closed by TB9 |
| CHANGELOG | TB9 Review promotion/discharge entry added |
| ROADMAP | CP-SCALE current package and CB11 successor updated |
| Selector manifest | selector425 package authority updated; selector bytes/count unchanged |
| LESSONS | no new pattern; existing lessons on witness-specific numbers, representation domains, and passed-vs-not-run are sufficient |
| Consolidation under CLEAN_UP_POLICY | CB10 plan/report + TB9 plan indexed as prior retirements; TB7 runtime report + TB8 Review folded now; references repaired |
| Successor frozen | `M4-CP-SCALE-CB11`; falsifiers and stop rules in the CB11 plan and §9 |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build mutation |
| review_check.py boundary | **ALL CHECKS PASSED** on the snapshot-derived worktree; no product/test/fixture/build mutation, no selector mutation, selector425 matches the declared hash, and durable markers are preserved |
| `STATUS` block rewritten | direct root-beacon write is performed as the final control-plane write before the response footer |
| Pushed to origin, branch in sync | ChatGPT Web closeout uses the branch-safe Drive patch reusable plus post-apply branch fetch in lieu of a persistent local clone; completion requires the fetched working branch to contain this review patch, followed by mandatory temporary-state cleanup |
