# M4-CP3 Closure Record

**Status:** **CLOSED / ACCEPTED**
**Closure turn:** `M4-CP3-TB8-REV`
**Date:** 2026-09-13 UTC

## 1. Accepted authority

M4-CP3 closes on reviewed immutable CB10/TB8 authority:

- semantic source: `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`;
- accepted package artifact: `10307919492` (`m4-cp3-cb10-result-34727247774`);
- package/provider ZIP SHA-256: `8988a12fa8b2e6476bf3fd91a6a6936eaef8a9ab7c73837b74ea2e980d29b2ec`;
- compile run/job: `34727247774 / 103643462175`;
- accepted selector: `Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt`, **408 identities**, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- accepted predecessor selector403: **403/403**, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- authoritative runtime run/job: `34729562893 / 103649745950`;
- result/log artifacts: `10309365777 / 10309009858`, SHA-256 `a8d91cd62cb2c633ed46ab963a13060e903a5043d3941fdea6aaec9c77091c04 / c7a7cf9e32269b85afde621c18799f49f9ad815ed9b7fb2eedd066f102275772`;
- process-ledger SHA-256: `2700e511a12505dbaf87b87d00bed7f2d2b73e65dd38adb1934682cb72abf63d`.

Accepted M4 runtime authority advances from corrected R4 package `10289601000` / selector403 to package `10307919492` / selector408. The R4 authority remains the accepted predecessor and historical recovery baseline.

## 2. Closure proof

TB8 is **835/835 PASS** in fresh exact-filter processes with zero RED/SKIP/crash/selection mismatch: six repaired shared-fixture identities A/B **12/12**, accepted ordinal138 A/B **2/2**, row408 A/B **2/2**, rows404-407 A/B **8/8**, accepted selector403 complete census **403/403**, and cumulative selector408 **408/408**. The accepted RED census is empty. Pre/post package, source and execution-view byte+mode censuses are exact.

The frozen CP3 exit is satisfied:

- A4 consumes the accepted A2b/A3 topology/conformity authority and publishes a conformity-plan receipt plus exact `sharedBoundaryInterval` identities (row404);
- fixed accepted A3 authority dominates local A4 target/grid variation: target sizes `0.5` and `2.0` preserve the non-empty shared interval set exactly (row405);
- missing/tampered exact interval identity fails typed and unchanged geometry cannot restore pairing, so floating/post-hoc support pairing is not authority (row406);
- A4-local `family`/`advanceSign` remains independent local authority after the A3 cutover (row407);
- the constructed exact torus production path reaches the cutover and completes without `InvalidHardRailPairing`, with typed shared-boundary identity (row408).

Production source still requires exact A3 span + reversed consecutive ordinal/orientation agreement and route/rail/local family-sign compatibility before publishing `oppositeEdge`; absence of `sharedBoundaryInterval` fails closed. No `support_key` or no-plan fallback was reintroduced.

CB10's test-authority repair is independently non-vacuous: `make_hard_rail_fixture()` must first retain production topology/baseline/rail/trace authority and a Produced network, then six distinct positive/tamper identities exercise the result. All six pass twice focused and again inside the complete accepted/cumulative gates.

## 3. Candidate and accounting disposition

`M4-CP3-TB7-REV-CAND-01` closes **RECOVERY PROVED / STABLE EVENT RETAINED**. Its prior ordinal211 accepted PASS->RED event remains historical stable evidence.

No TB8 accepted identity went RED. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**.

The main `G4-B002` exact-torus `InvalidHardRailPairing` blocker is **CLOSED / RECOVERY PROVED** here. The three inherited `G4-B002` produced-witness debts are explicitly **not discharged**; frozen M4 §11.1 leaves them gating at cumulative M4-CP4.

## 4. Carried non-blocking obligations

- `M4-CP3-TB1-R1-REV-OBS-01` — multiplicity-2 end-to-end oracle remains carried to the first later independently falsifiable M4 test-authority turn before M4-CP4.
- `M4-CP3-CB4-REV-OBS-02` — path/`sourceFaces` divergence detector remains carried to the next legitimate row399 touch.
- TB3 provenance warning — row408 is a constructed production torus witness; do not rewrite history as though that exact path had previously emitted `InvalidHardRailPairing`.

These are outside the frozen CP3 exit and do not reopen CP3.

## 5. Folded CP3 document index

Earlier CP3 folds remain indexed in `M4_Consolidated_Record.md`; that durable index and git history resolve all historical filenames. At closure, the following superseded current-head per-turn records are folded after their durable facts were preserved. Full text remains recoverable from git history.

| Folded filename | Lines | Verdict / retained home |
|---|---:|---|
| `Architecture_M4_CP3_TB2_R2_Test_Benchmark_Report.md` | 118 | **FOLDED AFTER SELECTOR408 PROMOTION.** Corrected R4 predecessor acceptance remains in this closure, selector manifest, consolidated record, tracker and changelog. |
| `Architecture_M4_CP3_CB9_Code_Build_Plan.md` | 159 | **FOLDED AFTER TB8 REVIEW.** Bounded applicability correction guard/scope is preserved in `M4_Consolidated_Record.md` §§2.36-2.38 and tracker. |
| `Architecture_M4_CP3_CB9_Code_Build_Report.md` | 38 | **FOLDED AFTER TB8 REVIEW.** CB9 semantic source/package compile lineage and runtime-free boundary are preserved in consolidated history/changelog. |
| `Architecture_M4_CP3_CB9_Derivation_Guard_Record.md` | 41 | **FOLDED AFTER TB8 REVIEW.** G1-G3 derivation proof is preserved in consolidated history. |
| `Architecture_M4_CP3_TB6_Artifact_Only_Test_Benchmark_Report.md` | 92 | **FOLDED AFTER FINAL CP3 ACCEPTANCE.** TB6 row408 recovery + ordinal138 RED lineage remains in tracker/consolidated history/current Review. |
| `Architecture_M4_CP3_TB6_Review_Record.md` | 306 | **FOLDED AFTER FINAL CP3 ACCEPTANCE.** Stable ordinal138 event, criterion correction and CB9 successor reasoning remain in tracker/consolidated history. |
| `Architecture_M4_CP3_TB7_Artifact_Only_Test_Benchmark_Plan.md` | 46 | **FOLDED AFTER TB8 REVIEW.** Focused/cumulative gate lineage is preserved in consolidated history. |
| `Architecture_M4_CP3_TB7_Artifact_Only_Test_Benchmark_Report.md` | 91 | **FOLDED AFTER TB8 REVIEW.** Ordinal211 accepted RED evidence remains in tracker/consolidated history/current Review. |
| `Architecture_M4_CP3_TB7_Review_Record.md` | 208 | **FOLDED AFTER TB8 REVIEW.** Test-authority root cause, stable event and full-prefix no-fail-fast requirement remain in tracker/consolidated history/current Review. |
| `Architecture_M4_CP3_CB10_Code_Build_Plan.md` | 151 | **FOLDED AFTER TB8 REVIEW.** Test-only fixture migration guards and prohibitions are preserved in current Review/closure/consolidated history. |
| `Architecture_M4_CP3_CB10_Code_Build_Report.md` | 96 | **FOLDED AFTER PACKAGE PROMOTION.** Exact CB10 source/compile/package authority remains in current TB8 report, this closure, selector manifest and changelog. |
| `Architecture_M4_CP3_TB8_Artifact_Only_Test_Benchmark_Plan.md` | 103 | **FOLDED AFTER EXECUTION + REVIEW.** Frozen 835-process gate, complete-prefix census rule and promotion criteria remain in current TB8 report/current Review/closure. |

Retained current CP3 authority documents are `Architecture_M4_CP3_TB8_Artifact_Only_Test_Benchmark_Report.md`, `Architecture_M4_CP3_TB8_Review_Record.md`, this closure record, the M4 consolidated record, frozen M4 definitions and every selector file.

## 6. Scope not closed here

This record closes **CP3 only**, not M4. CP-COND and CP-SCALE remain open. M4-CP4 still owns the three `G4-B002` produced-witness re-proofs plus cumulative M4 exit evidence. `G4-B003` remains M5-owned; `G4-B004` remains M5/M6-owned; `G4-B001` remains downstream.

## 7. Exact successor

**`M4-CP-COND-DEFN`**, runtime-free definition/review-plan turn under `Architecture_M4_CP_COND_DEFN_Plan.md`. It freezes Amendment-20 conditioner semantics and witness preconditions without changing accepted A3/A4 authority.
