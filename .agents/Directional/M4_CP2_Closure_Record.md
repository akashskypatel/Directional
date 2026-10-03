# M4-CP2 Closure Record

**Status:** **CLOSED / ACCEPTED**
**Closure turn:** `M4-CP2-TB2-R1-REV`
**Date:** 2026-09-10 UTC

## 1. Accepted authority

`M4-CP2` closes on reviewed immutable package117:

- semantic source: `534c0d41ae05b31e66711f21f4b4280b59f6483f`;
- package117 artifact: `10172820820`;
- package SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`;
- compile run/job: `34529050994 / 103045247639`;
- accepted selector: `Architecture_M4_CP2_Required_Green_Selector_382.txt`, **382 identities**, SHA-256 `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- accepted predecessor prefix: selector373 **373/373**, SHA-256 `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- reviewed runtime run/job: `34539783373 / 103079623871`;
- result/log artifacts: `10176889758 / 10176890045`, SHA-256 `51d16f992fe7784ac8fcc4db64868823108c147e92fa71acfdf97f73c001e5b0 / b4a1e0fa555de319a816fffb6aa84b370a7b18862ad107a08a65b48aa37a56d6`.

Accepted M4 package authority advances from **115 to 117**; accepted M4 selector authority advances from **373 to 382**. Package116/selector380 remains historical unpromoted candidate lineage.

## 2. Closure proof

The runtime gate is **382/382 PASS**, predecessor **373/373**, CP2 **7/7**, correction rows **2/2**, focused 374/381/382 **3/3 twice**, and owners **30/30 authority-kernel / 236/236 producer / 75/75 completion / 41/41 validation**, with zero RED/SKIP/timeout/selection mismatch. The required ordinal374 success receipt occurs exactly once in each focused run.

Independent R1 review re-derived package/source/execution-view immutability from paired censuses, with SHA-256 `c45c423e7365887ccc5ef5974d1c61c32c775e9b064d41e47709500721d6938d / 67726528d5e31765005b1fee3360acfed9d23958a754a71aaa62d5ff7507cee2 / 1a5b1de75f2c9ae27c28ea77509e57b5e8c4565a2dd537b789cef03f98505f02`. Preflight/gate are `0/0`; no configure, compile, relink, repair, generated discovery, mutation, or benchmark occurred in R1.

The frozen CP2 exit is met:

- carried certificate evidence proves positive schedules, exact balance/parity/objective and terminal fixed-`M=2` optimality;
- complete WorkLedger assurance/bounds/history is carried and independently verified, with ordinal381 tamper coverage across every required family;
- a genuinely infeasible constructed component produces a verified subset-scoped `PositivityCut` rather than a replacement schedule or fatal run-wide A3 outcome;
- mixed outcomes prove every incidence belongs exactly once to either a scheduled certificate or an infeasible subset;
- `GlobalConformityOutcome::semanticDigest` binds full support paths plus scheduled/infeasible evidence and is independently re-derived/tamper-tested by ordinal382;
- the four-coordinate magnitude-two oracle is behaviourally load-bearing and emits a success-visible fixture-derived receipt.

**Why "scalable" is satisfied.** The exit's word *scalable* qualifies the certification method, not the
instance size. Optimality is certified by LP duality — `GlobalConformityCP2Validator.cpp:228-230`
independently recomputes `Σ y_i + Σ_B z_B · ⌊|B|/2⌋` and checks `y_a + y_b + Σ_{B ⊇ {a,b}} z_B ≥ scale · w_e`
on every edge, paired with exact primal equality, and derives it separately from the LEMON producer. Such a
certificate is valid at any instance size. That is the scale-independent replacement for CP1's exhaustive
oracle, which is bounded to `E <= 6, x_s <= 8` and cannot certify anything larger — hence CP1's *fixed-small
test oracles* versus CP2's *carried algorithm-native evidence*. Instance-scale evidence is owned by the
separate frozen **CP-SCALE** checkpoint (certified filters, typed/bounded limit-cycle and Betti outcomes,
published S1 measurements); reading CP2's *scalable* as a large-instance demonstration would duplicate it.
No large-instance runtime was required for CP2 and none is owed retroactively.

## 3. Candidate disposition

All CP2 review/orchestration candidates close non-stably:

- `M4-CP2-TB1-REV-CAND-01` — **CLOSED / RECOVERY PROVED / NON-STABLE**: passing receipt now observable and harness-enforced;
- `M4-CP2-TB1-REV-CAND-02` — **CLOSED / RECOVERY PROVED / NON-STABLE**: WorkLedger carriage and independent verification complete;
- `M4-CP2-TB1-REV-CAND-03` — **CLOSED / RECOVERY PROVED / NON-STABLE**: full CP2 semantic outcome digest present and independently re-derived;
- `M4-CP2-TB1-REV-CAND-04` — **CLOSED / RECOVERY PROVED / NON-STABLE**: magnitude-two fixture changes the optimum relative to its magnitude-one twin;
- `M4-CP2-TB2-EXEC-CAND-01` — **CLOSED / RECOVERY PROVED / ORCHESTRATION / NON-STABLE**: corrected R1 postflight completes on unchanged package117.

No new stable regression is created. Stable accounting remains **47 events / 14 categories / 33 recurrences**. Produced-witness debt remains **5**.

## 4. Scope not closed here

This record closes **CP2 only**, not M4. It does not promote production A3->A4 integration. CP3 owns the producer cutover, exact-torus `InvalidHardRailPairing` removal through A3 authority, and fixed-plan shared-boundary invariance. CP4 still owns all three `G4-B002` produced-witness debt re-proofs; no debt is discharged by CP2 closure.

## 5. Folded CP2 document index

Every folded document below had its durable facts preserved before deletion. Full prior text remains recoverable from git history; line counts are the exact retired revisions used by this review.

| Folded filename | Lines | Verdict / retained home |
|---|---:|---|
| `Architecture_M4_CP2_CB1_Code_Build_Plan.md` | 154 | **FOLDED EARLIER AFTER CB1 + TB1 REVIEW.** CP2 initial implementation scope is preserved in `M4_Consolidated_Record.md` §§2.8-2.10 and git history. |
| `Architecture_M4_CP2_CB1_Code_Build_Report.md` | 96 | **FOLDED EARLIER AFTER TB1 REVIEW.** Package116 compile lineage remains in `M4_Consolidated_Record.md` §2.8 and changelog. |
| `Architecture_M4_CP2_TB1_Test_Benchmark_Plan.md` | 116 | **FOLDED EARLIER AFTER TB1 REVIEW.** Package116 gate contract/results remain in §§2.9-2.10 and git history. |
| `Architecture_M4_CP2_TB1_Test_Benchmark_Report.md` | 107 | **FOLDED AFTER SUPERSESSION BY R1.** Package116 measured-green evidence remains in `M4_Consolidated_Record.md` §2.9, tracker and changelog; it was never promoted. |
| `Architecture_M4_CP2_TB1_Review_Record.md` | 238 | **FOLDED AFTER R1 REVIEW.** Four blocking findings and package116 rejection remain in `M4_Consolidated_Record.md` §2.10, tracker, changelog and the current R1 review/closure records. |
| `Architecture_M4_CP2_CB2_Code_Build_Plan.md` | 213 | **FOLDED AFTER PACKAGE117 REVIEW/PROMOTION.** Four corrective obligations are preserved in §§2.10-2.11 and the current review/closure records. |
| `Architecture_M4_CP2_CB2_Code_Build_Report.md` | 98 | **FOLDED AFTER PACKAGE117 REVIEW/PROMOTION.** Exact source/compile/package117 authority is preserved in §2.11, closure, changelog and current runtime report. |
| `Architecture_M4_CP2_TB2_Artifact_Only_Test_Benchmark_Plan.md` | 129 | **FOLDED AFTER INVALID ATTEMPT + RECOVERY.** Frozen gate and invalid-attempt provenance remain in §§2.12-2.14, tracker and current review. |
| `Architecture_M4_CP2_CB3_Orchestration_Correction_Plan.md` | 77 | **FOLDED AFTER R1 RECOVERY.** One-name census correction is preserved in §§2.12-2.14 and tracker. |
| `Architecture_M4_CP2_CB3_Orchestration_Correction_Report.md` | 96 | **FOLDED AFTER R1 RECOVERY.** Exact corrected preflight/executor lineage remains in §2.13, tracker and changelog. |
| `Architecture_M4_CP2_TB2_Test_Benchmark_Report.md` | 104 | **FOLDED AFTER VALID R1 SUPERSESSION.** Invalid no-credit attempt remains separately preserved in §2.12, tracker and changelog. |
| `Architecture_M4_CP2_TB2_R1_Artifact_Only_Test_Benchmark_Plan.md` | 129 | **FOLDED AFTER R1 EXECUTION + REVIEW.** Corrected immutable retry gate is preserved in §2.14, current R1 runtime report and current review. |

Current runtime authority report `Architecture_M4_CP2_TB2_R1_Test_Benchmark_Report.md`, current review record `Architecture_M4_CP2_TB2_R1_Review_Record.md`, frozen selectors/definitions, this closure record and the M4 consolidated record are retained.

## 6. Exact successor

**`M4-CP3-CB1`**, runtime-free canonical Code + Build, under `Architecture_M4_CP3_CB1_Code_Build_Plan.md`.
