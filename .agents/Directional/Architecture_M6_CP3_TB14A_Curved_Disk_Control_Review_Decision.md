# RA-94 — TB14A reviewed: curved-disk control restored (425/497); 199 is a hidden fixture repair; DEFN-U6 next (2026-10-18)

**Turn:** `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV`. **Input:** TB14A run `39143325285`, result `12141843937`, on CB14A package `12140756646` (source `2ee499a3`). **Amends:** the RA-85.5 turn IDs for U4/U5 (RA-94.5). **S** = `src/geometry/SurfaceCellTracing.cpp`; **P10** = `tests/SurfaceCellsPhase10Tests.cpp`.

## RA-94.1 Closeout and re-verification

- TB14A committed its report, a tracker row and the handoff. It then stopped with STATUS `IN_PROGRESS`: its `TODO.md`/`CHANGELOG.md` edits were routed through a Google Drive patch it could not reach.
- Review closes the turn out from re-derived facts. The Drive patch is not applied, and the handoff's procedural "incomplete closeout" section is removed.
- Re-verified:
  - result ZIP `1b06e43e…d455`, 1019/1019 checksums;
  - run `success` at executor `4797400a`;
  - candidate digest `eee92aeb…` matches CB14A;
  - every immutability flag true; 497/497 executed.

## RA-94.2 Comparison with TB13C (all 497)

- **Exactly five status changes, all RED → PASS: 199, 235, 236, 294, 299.**
- 237/253/254 PASS, and 250 is RED at P10:3597 with `PublishedProductRejected`, both as predicted.
- The 72 REDs are unchanged in substance:
  - 8 raw logs are byte-identical;
  - 60 are identical except for source line numbers and timings;
  - 134/137/150 differ only in the interleaving of `M3_CP4AB_FRAGMENT_DIAG` lines (the same records);
  - 242 differs only in a printed pointer address.

## RA-94.3 Test 199 falsified RA-93.4 (owned prediction error)

- RA-93.4 predicted 199 would fail later, in its cylinder half, because R3 failed there (`InvalidFinalCellState`, R3 P10:5191).
- But `2be228d96` (2026-10-11, after R3) changed only that call to `build_phase10_with_source_atlas`. That supplies the source A3 atlas, which is now mandatory; the chart-zero assertions are unchanged.
- At TB13C that repair was hidden behind the stale disk half. 199 is therefore a valid R3 RED → PASS control, not a weakened test.
- Lesson: a failure hidden behind another one is unmeasured. Check the test's history before predicting it from an old baseline.

## RA-94.4 Adjudication

- **The curved-disk `make` control is restored.** Four tests pass at the checked factory with a producer-built closed hard rail. RA-92.5's precondition for U4 is met.
- **Census:** 425/497 = R3 403 + 26 that went RED → PASS (RA-91's 25 plus 199) − 4 that went PASS → RED (174, 191, 242, 442).
- **No production regression.** Stable accounting is unchanged: 66/17/49, debt 1, CP2 491/491, selector 497 frozen.
- **RP-01 is unchanged:** B2 owns 11 identities and B3 owns 19, with B3 failing first on `cp3entry:2/6` (front 17/203 is before 61/179).

## RA-94.5 Order: DEFN-U6 first, then U4 → U5

- **Why DEFN-U6 first:**
  - B3 owns most of RP-01 and has no design.
  - The remaining U4/U5 work has a frozen rule and order (R10B as amended by RA-84/RA-85).
  - If no exact producer-origin parameter exists, RP-01 cannot close by this route, and U4/U5 must be re-assessed before code is spent on them. A DEFN costs no runtime.
- **U4 → U5 is kept.** The factory admits R before any producer emits it, so the pipeline stays fail-closed throughout. Limit: until U5, U4's factory branch has direct-`make` coverage only (RA-90.2), with the curved disk as its factory regression control.
- **Renamed** to stay monotonic after CB14A: U4 = `M6-CP3-CB15-R10-FACTORY-RAIL-VERTEX-ENDPOINT`, U5 = `M6-CP3-CB16-R10-CONSUMER-RAIL-VERTEX-ENDPOINT`. Their scope is unchanged.

## RA-94.6 DEFN-U6 specification — `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER` (documents only)

**Deliverable:** `Architecture_M6_CP3_DEFN_U6_Exact_I_Endpoint_Parameter_20261018.md`, 120 lines or fewer, citing `file:line` at `2ee499a3`. Production code has not changed since `70217cc2`.

1. **Producer-origin trace.**
   - Template: `cp3entry:2`, front 17/203, endpoint-1, edge 1–4, faces 0 and 3.
   - From TB14A `raw/cp3entry/ordinal-002.log`: face 0 = (0, `0x1.999999999999ap-1`, `0x1.9999999999999p-3`); face 3 = (`0x1.999999999999ap-1`, 0, `0x1.9999999999998p-3`).
   - For each side, cite every site that writes the barycentric reaching `same_interior_carrier_point` (S:91-97; checks at factory S:8773 and consumer S:19480), back to exact inputs.
   - State whether the two sides share one computed scalar, and which double operation yields the one-ULP difference.
2. **Candidate exact parameter.**
   - Give its exact inputs, its type (prefer the existing `ExactSourceEdgePoint`/`FieldExactRational`, `ExactSourcePath.h:22-26`) and its orientation convention.
   - Give the single site that computes it, and how it reaches both checkers.
   - Compare alternatives and recommend one.
3. **Rule.** I-endpoint identity is exact equality of that parameter, and the doubles become geometry only. The rule must not use an epsilon, rounding, or canonicalization from near-equality (R9B:29, RA-60.11), and must not rest on the interval alone (RA-63.5).
4. **Satisfiability (RA-61.7).**
   - Evaluate the rule as exact rationals on all 19 B3 identities: focused30 3/12/14/15/17/18/22/23/24, focused12 5/6, selector 211/217/219/227/230/231 and `cp3entry` 2/6.
   - Use TB14A raw logs (artifact retained 14 days). Mark each identity equal, unequal, or missing data; for missing data, name the field and the probe that would print it.
   - State what the rule does with RA-76's 324 one-ULP pairs.
5. **Negatives the CB must test:**
   - distinct crossings one ULP apart stay distinct;
   - parameter 0/1 (a vertex masquerade) is rejected;
   - a parameter on a different edge is rejected;
   - the reversed edge orientation compares correctly;
   - a tampered parameter is rejected at the factory.
6. **Units.** Narrow CBs (for example, carry the parameter with no admission change, then switch both checkers), each with TB predictions and falsifiers on the 19 identities and named controls.

If no exact origin exists, the DEFN says so with evidence and proposes alternatives. It never proposes a tolerance. **Out of scope:** code, builds and runs; U4/U5; test debt.

## RA-94.7 Sequence

DEFN-U6 → DEFN-U6-REV, which accepts or amends the U6 units and authorizes CB15 (U4). After that: CB15/TB15 → CB16/TB16 (U5) → the U6 CB/TB units → an RP-01 Review.

Fixture debt is scheduled by DEFN-U6-REV as narrow test-only CBs, none of which blocks U4–U6. It covers 174, the 191 family, 242, 442, 250 and the adjacent-sheet helper.
