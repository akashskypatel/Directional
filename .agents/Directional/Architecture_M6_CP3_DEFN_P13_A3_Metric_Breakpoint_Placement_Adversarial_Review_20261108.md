# RA-217 — Step 64.5 (D7b) re-entered: one run decomposition, no zero-weight failure, exact CB108 and CB109

**Turn:** `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT`, re-entered · 2026-11-08 · Claude Review, runtime-free (`REVIEW_TURN_POLICY.md` §4.3). Nothing was built or run. Both patches were checked with `-fsyntax-only` only, on every changed unit plus `SurfaceCellTracing.cpp` and `RemeshPipeline.cpp`. Every expected test value was recomputed with an exact-fraction model of the new algorithm. Product source = CB107 `34967c89817a…`, unchanged at HEAD.

Reviewed: the [D7b decision](Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Review_20261108.md), against [RA-216 §8](Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md) and the source. Evidence read: TB90 gate result artifact `13633654777`, raw log `434.log` (test 392: `entryCount=4`).

## 1. Verdict

The placement formula, the reversal analysis and the single-piece rule are right. The decision still does not deliver what RA-216 §8 asked of it: an exact CB108 and TB91. Instead it gives the implementation agent a prose scope with open design choices, and that scope is monolithic, covering profile, placement, canonicalization, both width receipts, validator recomputation and tests at once. It also contradicts the count it must agree with, and adds a production failure mode. Finally, it leaves the receipt encoding and width bound to the implementation agent, and misses that the switch rewrites an accepted selector test.

RA-217 makes four changes:
- it fixes the contract (§4);
- it splits the work into an unwired CB108 and a switch CB109, each followed by its own TB;
- it freezes both patches and both manifests;
- it amends DESIGN §7.4.

## 2. What stands

- **Placement formula (rule 2):** `T = jW/n`; take the run with `C_r ≤ T < C_r + W_r`; set `t = (jW − nC_r)/(nW_r)`; the point is `a_r + t(b_r − a_r)`; within the run, the piece is chosen by its length fraction. This is RA-216 §8.
- **Reversal analysis (rule 3):** a zero-weight run makes the reversed join ambiguous. It is proved in §3 G3 below, and it is right.
- **Single-piece rule (rule 4):** keep the unreduced `(j, n)` on piece 0, including where h varies, so curved-disk output and single-piece receipt widths are unchanged.
- **Ownership (rule 5):** a baseline-only per-span profile. `ConformityScheduleEntry`, `ConformityBreakpointLocation` and `GlobalConformityPlan.cpp:49` stay unchanged, and the framed CP1/CP2 copies stay frozen.
- **Validator:** the `denominator == n` check at `GlobalConformityBaselineValidator.cpp:855-864` holds only for single-piece spans.

## 3. Findings

- **G1 (high): no exact patch, and CB108 is monolithic.**
  - RA-216 §8 required the step-64.5 DEFN to freeze an exact CB108 and TB91, and it froze neither.
  - Its CB108 scope bundles five changes:
    - a run profile;
    - the placement switch;
    - "source-entity canonicalization";
    - producer and validator width receipts;
    - validator recomputation, plus tests.
  - It also leaves design choices open: "reduced or explicitly unreduced, chosen once", and "a provably conservative declared upper bound or a bounded exact algorithm".
  - The implementation agent receives only exact patches (RA-172, RA-215).
  - **Correction:**
    - CB108 adds the shared run profile and an unwired placement function, with tests; it is digest-neutral.
    - TB91 expects byte-identical digests.
    - CB109 is the smallest atomic switch.
    - TB92 gets a pre-registered rule.
- **G2 (high): rule 1 contradicts the count's runs.**
  - Rule 1 splits runs at "sheets, components, barriers, discontinuities or uncertified source-carrier transitions".
  - The D7 count (`derive_partition_stable_preferred_count_exact`) splits only where the 3D direction changes, using Cauchy–Schwarz equality with `d·u > 0`.
  - Two run decompositions would mean that placement weights no longer sum to what the count measured.
  - Within one span, pieces are chained by exact source-point equality (`previous != piece.first` fails closed), so a span cannot jump sheets or components. `ConformitySpanInput` has no barrier field.
  - **Correction:** one function, `derive_partition_stable_metric_runs`. The count is refactored onto it in CB108 and must stay byte-identical (TB91), and placement reads the same runs.
- **G3 (high): fail-closed zero weights add a production failure mode.**
  - With floor weights `F_r = ⌊2⁶⁴·metric_r⌋`, any run whose metric is below 2⁻⁶⁴ has `F_r = 0`.
  - DESIGN requires A3 to place every span, so the decision's typed rejection becomes a baseline-build failure. That would be a regression, and it would come from code that no consumer reads for multi-piece spans.
  - The ambiguity is real. With `F_r = 0` between runs r−1 and r+1, forward ordinal j lands on `a_{r+1} = b_r`, while reversed ordinal n−j lands on `a_r`, which is a different point when run r has positive length.
  - **Correction:** placement weights `W_r = ⌈2⁶⁴·metric_r⌉ = isqrt(⌈2¹²⁸·q_r⌉ − 1) + 1`, from the same exact squared metric `q_r`. This gives:
    - `W_r ≥ 1` for every positive-length run, so no run is erased and the half-open rule reverses exactly (`t' = 1 − t`; a join resolves to the same physical point from either side);
    - invariance to partition and reversal, as for `q_r`;
    - the count keeps its floor.
  - Falsifier (CB108 GUARD 917): a run of length 2⁻⁷⁰ contributes 0 to the count but is placed with weight 1. Every breakpoint exists, breakpoint 1 sits at `y = 1 − 3·2⁻⁶⁶`, and reversal is exact.
- **G4 (medium): "canonical physical source-entity point" and "typed provenance" are undefined.**
  - A location is `(supportPieceIndex, local fraction)`, and rule 5 itself forbids widening the shared struct.
  - The half-open rule already decides a join: the later piece, at local 0.
  - A reversed span is a different input, so it reaches the same physical point through a different `(piece, local)`. That is correct, because the invariant is the point, not the representation.
  - The source entity follows from the piece's carrier and the local fraction, so storing it would add a second source of truth.
  - **Correction:** drop both phrases. Tests pin both the stored location and the exact point.
- **G5 (medium): the width receipt is over-specified.**
  - M4 closure §5.5 defines the breakpoint widths as those of values "encountered by validation". They are report-only and gate only on deterministic recomputation and equality.
  - The decision instead requires an all-ordinal maximum of reduced forms without enumeration, while admitting that the bound may not be provable.
  - The legacy receipt already samples ordinals {0, 1, n−1, n}, the same ones the validator checks.
  - **Correction:** keep that definition. Producer and validator call the same placement function at ordinals 1 and n−1. Single-piece values are bit-identical to today (`(1, n)` and `(n−1, n)`), and multi-piece widths become those of the stored reduced fractions.
- **G6 (medium): "independent recomputation" is ambiguous.**
  - The count's established pattern is that the validator re-derives from the authoritative input through the shared support function and compares the results.
  - A second, duplicated implementation adds no trust. The oracle for the function itself is exact-fraction unit tests.
  - **Correction:**
    - The plan stores the runs privately; prefixes and weights are derived on use.
    - The candidate validator recomputes runs from the input for the width twin.
    - `validate_global_conformity_baseline` compares the plan's interior locations with a placement re-derived from the input.
- **G7 (medium): the switch rewrites an accepted selector test.**
  - `CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant` (selector:392, gate row 434, part of CP2 491) asserts `localDenominator == count` on a two-piece span.
  - After the switch, that span stores 0:1/2 and 1:1/2 instead of 0:2/4 and 1:2/4. The physical points are the same.
  - The decision's closeout says "no selector/source contract rebaseline", which is wrong.
  - **Correction:** CB109 amends that test's assertions to the exact new locations, adding `count == 4`, which is observed in TB90's raw log. The test identity, its PASS expectation and its permutation and digest invariants are unchanged, and its assertions become stronger, not weaker. This is registered here as a Review-authorized assertion amendment.
- **G8 (low): some falsifiers have no representation in the unit's scope.**
  - "Source-face row order", "close distinct sheets" and "foreign chart alias" cannot be expressed in a span input.
  - Contiguity and malformed-span rejection are already pinned by GUARD 913.
  - Mesh-level sheet controls belong to D5's TB, where multi-piece spans reach a consumer.
- **G9 (low): the production effect was not stated.**
  - No production consumer reads multi-piece placement: curved-disk accepts only single-piece Mandatory edge arcs (`SurfaceCellTracing.cpp:17449-17473`, `:17641`).
  - The switch therefore changes only multi-piece width receipts, which feed the baseline digest and, through `baselinePlanDigest`, the tracing hash. This is TB92's rule.

## 4. Corrected D7b contract (replaces decision rules 1–5 and the width section)

1. **Runs.** These are exactly the D7 count's runs: maximal consecutive pieces with the same direction. Each run is stored as `BaselineConformityMetricRun{firstPiece, pieceStarts, squaredMetric}`, where:
   - `pieceStarts[k]` is the fraction of the run's length (by `d·u`) at which piece k starts;
   - `squaredMetric` is the exact `S²/|u|²`.

   The count is `round(Σ ⌊2⁶⁴√q_r⌋ / 2⁶⁴)`, halves down, minimum 1, and is unchanged.
2. **Placement of ordinal j of n.**
   - Ordinals 0 and n are the endpoints, stored as `0:0/1 first` and `last:1/1 last`.
   - A single-piece span stores `0:j/n`, unreduced.
   - Otherwise, use the weights `W_r = ⌈2⁶⁴√q_r⌉ ≥ 1`. Take the run with `C_r ≤ jW/n < C_r + W_r`, and set `t = (jW − nC_r)/(nW_r)`. The piece is the last k with `pieceStarts[k] ≤ t`, and the stored local fraction is `(t − τ_k)/(τ_{k+1} − τ_k)` in reduced form, with `τ_K = 1`.
3. **Profile validity.** The runs must tile the pieces in order. Each run's starts must begin at 0, rise strictly and stay below 1, and `squaredMetric > 0`. Otherwise, or for an ordinal outside `[0, n]` or `n < 1`, placement returns nothing.
4. **Ownership.** The plan holds `metricRuns_` in schedule order. Build derives the runs from the input alongside the preferred count. The width producer, the validator twin and the wrapper's interior check each re-derive placement through the same function.
5. **Width receipt.** Ordinals {0, 1, n−1, n}, using the actual stored numerators and denominators, per M4 §5.5.

Within a run, placement stays linear in length; that deviation is documented in RA-216 §8. A single-run span is placed at `t = j/n`.

## 5. Exact CB108 — the run profile and placement, not yet wired

- [Patch](Architecture_M6_CP3_CB108_P13_A3_Metric_Breakpoint_Placement_Exact.diff): SHA-256 `c56559ae0d2abced96151cb6ad113fc53c7a70b47200eec04499b847ae08f202`, 532 lines, 11 single-space context lines. Numstat: `15 0` `GlobalConformityBaseline.h`; `124 13` `GlobalConformityBaselineSupport.cpp`; `18 0` `GlobalConformityBaselineSupport.h`; `266 0` `GlobalConformityBaselineTests.cpp`. It applies cleanly to HEAD (product = CB107 `34967c89…`).
- **Product changes:**
  - `BaselineConformityMetricRun` is added to the baseline header, with nothing reading it yet.
  - `derive_partition_stable_metric_runs` is added, and the count now sums floors over it. This is a refactor with identical arithmetic.
  - `derive_metric_breakpoint_location` is added, with `scaled_metric_floor` and `scaled_metric_ceiling`.
- **Tests (GUARD 915–917):**

| Test | Asserts | Fails on |
|---|---|---|
| `D7bBreakpointsFollowTheRunNotThePieceIndex` | λ=(0.1, 3.9) at n=4: `1:3/13`, `1:19/39`, `1:29/39` (x = 1, 2, 3); single piece `0:2/4`; 5 splits × forward/reversed all at x = j | piece-index placement (0:2/4, 1:0/4, 1:2/4 = x 0.05, 0.1, 2.05); a reduced single-piece fraction |
| `D7bBreakpointsShareOrdinalsAcrossRunsByMetric` | Legs of metric 1 and 3 (h rising to ½): runs `{0,[0],1}` and `{1,[0,½],9}`; points (1,0), (1,⅔), (1,4/3), whole and with leg 2 cut, forward and reversed; the corner is `1:0/1` (reversed `2:0/1`) | allocation by total length ((0.75, 0)), piece-index allocation ((0.5, 0)), a second run decomposition |
| `D7bBreakpointsGiveEveryRunWeightAndRejectBrokenProfiles` | rising h on one piece keeps `0:j/6`; a 2⁻⁷⁰ run: count 4, `1:73786976294838206461/295147905179352825856`, exact reversal; 10 broken profiles or ordinals, and an empty span, give nothing | floor weights (fail closed), unchecked profiles |

## 6. TB91 — CB108 full gate

- [Manifest](Architecture_M6_TB91_P13_A3_Metric_Breakpoint_Placement_Full_Gate_Case_Manifest.tsv): 917 rows, `0b16a30e332e42888339c6bdd8bcb66127281fca2c6430e22ef7e98065fb1752`. It is TB90's 914 rows plus GUARD 915–917. `SELF_CHECK_PASS cases=917 deferred=81`; membership 998; ledger v5 `fd433f54…`; census `3af1dc0d…`; harness `78b8002c…`.
- **Expect:**
  - 917/917;
  - all 7 `platform-digest` and 7 `a3-coverage` lines byte-identical to TB90;
  - census Cylinder PASS, BunnyRandom and Vase registered RED.
- **Any digest change means the refactor changed the count.** Route: `M6-CP3-TB91-P13-A3-METRIC-BREAKPOINT-PLACEMENT-FULL-GATE-REV`; infrastructure → `M6-CP3-TB91A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-ORCH`.

## 7. Exact CB109 — make the D7b placement the plan's, and TB92

- [Patch](Architecture_M6_CP3_CB109_P13_A3_Metric_Breakpoint_Placement_Switch_Exact.diff): SHA-256 `be4cac4ea85651d0d327f28ba6c9df0a625c4e0e22d518bdedb31d401116e302`, 377 lines, 15 single-space context lines. Numstat: `6 2` `GlobalConformityBaseline.h`; `29 37` `GlobalConformityBaseline.cpp`; `0 15` `GlobalConformityBaselineSupport.cpp`; `0 1` `GlobalConformityBaselineSupport.h`; `44 20` `GlobalConformityBaselineValidator.cpp`; `51 2` `GlobalConformityBaselineTests.cpp`. It applies only on top of CB108.
- **Why these five files are one turn:** the producer receipt and its validator twin are compared for equality, and the wrapper's interior check reads the plan. Changing any one of them without the others fails every multi-piece build.
- **Product changes:**
  - The plan stores `metricRuns_`, and `breakpoint_location` delegates to the placement function.
  - Both width receipts observe the stored locations.
  - The wrapper compares interior locations with a placement re-derived from the input.
  - `exact_to_size_checked` is removed, since the switch left it unused.
- **Tests:**
  - selector:392's denominator assertions are replaced by `count == 4`, `0:1/2` and `1:1/2` (G7).
  - New GUARD 918, `D7bPlanBreakpointsAreTheMetricPlacementForEverySplit`: on the square fixture at h = ¼, the whole, {⅛} and halves splits each give a plan location equal to the D7b location at x = j/4. The stored interior locations are `0:1/4 0:2/4 0:3/4 | 1:1/7 1:3/7 1:5/7 | 0:1/2 1:0/1 1:1/2`. This test fails on CB108, where the uneven split's plan locations are still piece-index.
- **TB92:** [manifest](Architecture_M6_TB92_P13_A3_Metric_Breakpoint_Placement_Switch_Full_Gate_Case_Manifest.tsv) of 918 rows, `d714a52e4f3c7716dd08ea40258ad04fea0c93ecc998b77aa0eab60a77846d13`, membership 999, `SELF_CHECK_PASS cases=918 deferred=81`. Pre-registered outcome:

| Record | Rule |
|---|---|
| Gate | 918/918, including selector:392 (row 434) and GUARD 918 |
| `a3-coverage` (7) | byte-identical to TB91: curved-disk reads only single-piece spans, which are unchanged |
| `platform-digest` through `global-topology-plan` | byte-identical |
| `global-conformity-baseline` | the hash may change (multi-piece width receipts); its `/count` must be identical |
| Later tokens | if the baseline hash is unchanged, everything is identical. Otherwise they may change, but every `/count` and `validationIssues` stays identical for the 4 gate cases and census Cylinder; Vase's later tokens are recorded |
| Census | Cylinder PASS; BunnyRandom RED `SingularityPortClassCountMismatch`; Vase RED `AggregateCompletionValidationFailure` |
| Any baseline build failure, verdict change or `/count` change | MISMATCH → `M6-CP3-TB92-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-FULL-GATE-REV` |

## 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64.5 | `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT`: COMPLETE, re-entered by RA-217 | Review |
| 64.6 | `M6-CP3-CB108-P13-A3-METRIC-BREAKPOINT-PLACEMENT`: compile only. Mismatch → `M6-CP3-PLAN-P13-A3-METRIC-BREAKPOINT-PLACEMENT-STOP`; infrastructure → `M6-CP3-CB108A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-ORCH` | implementation agent |
| 64.7 | `M6-CP3-TB91-P13-A3-METRIC-BREAKPOINT-PLACEMENT-FULL-GATE-EXEC` (§6) | implementation agent |
| 64.8 | `M6-CP3-CB109-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH`: only after TB91 MATCH. Mismatch → `M6-CP3-PLAN-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-STOP`; infrastructure → `M6-CP3-CB109A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-ORCH` | implementation agent |
| 64.9 | `M6-CP3-TB92-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-FULL-GATE-EXEC` (§7). Infrastructure → `M6-CP3-TB92A-P13-A3-METRIC-BREAKPOINT-PLACEMENT-SWITCH-ORCH` | implementation agent |
| 64B → 65D → 66+ | D5 chains → D4 uniform → D4 annulus → D9c → A2b trace → A4 disc → D8 → per-disc corners (D6 user decision) | Review DEFN, then CB, then TB each |

No Review turn sits between a green TB91 and CB109.

## 9. Corrections to the D7b decision

- Rule 1's extra split conditions are withdrawn (G2).
- Rule 3's fail-closed is replaced by ceiling weights (G3).
- The "canonical source entity" and "typed provenance" phrases are dropped (G4).
- The width-receipt section is replaced by §4 item 5 (G5).
- Its selector claim is corrected (G7).
- Its CB108 scope is replaced by §5 and §7.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Not re-hashed. selector:392's assertions are amended in CB109 (G7); its identity and PASS expectation are unchanged, and TB92 executes it |
| Decisive claims re-derived | Read the count, placement, both width receipts, the wrapper check, curved-disk and the M4 §5.5 receipt definition. Checked every expected value with an exact-fraction model, and test 392's count against the TB90 raw log |
| Non-vacuity | CB108 tests assert values that piece-index placement, total-length allocation and floor weights each violate. GUARD 918 fails on CB108 |
| Obligations carried | D5 64B; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB90 914/914, membership 995; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 | Updated |
| Turn boundary | No product or test source changed in the repository; syntax checks and an exact-fraction model only |
