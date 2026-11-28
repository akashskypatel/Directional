# TB-REV-185T adversarial continuation (2026-11-25 UTC)

This continues `M6-CP3-TB-REV-185T-REACH-TERMINATION-DIAGNOSTIC`, after the [independent review](Architecture_M6_CP3_TB_REV_185T_Reach_Termination_Diagnostic_Independent_Review_20261125.md).

- **Method:** runtime-free. Haiku read-only work on:
  - the five `quotient_forest_path` call sites and the other whole-forest loops;
  - the row 1006 receipts in TB185T artifact `15035995368` (ZIP and raw hashes verified, nothing executed, deleted afterwards);
  - fixture sizes and options;
  - syntax-only checks of three exact diffs authored in this review.
- **Product and test bytes:** unchanged.

## Verdict

- **Upheld:** TB185T as a bounded observation, and the static finding QF1 (whole-forest reconstruction for every query).
- **Withdrawn:** CB-205U as the next turn. It was a prose algorithm, which breaks the exact-diff rule. It was incomplete, because it deferred a second K×F loop of the same order. And it was on the wrong path: it made a product cost fix the gate for activation.
- **Realigned:**
  - Activation continues with a test-only rescope, CB-205V.
  - QF1 becomes its own product track (CB-207A/B/C), using exact diffs frozen here.

## Findings

**W1 — The stall is outside what any reader needs, and the needed data is already measured.**
- TB185T's 11 raw receipts show the following:
  - **Sphere:** the only fixture that changes under staging. That holds in all four recipes: digest `9084693800288509401` becomes `12659562395504099178`, and `slideStops` goes 0→4.
  - **Unchanged digests (production equals staged):**
    - torus (observe, pipeline and census);
    - mechanical_feature;
    - two-ring;
    - four-triangle-fan;
    - genus_two.
  - **Polyline-defaults sphere:** `polylineEligible=1` in both the production and staged columns.
- `produced_network()` returns at the first eligible fixture, so rows 843/844 read only the sphere, before and after staging.
- The stall happens in close_sheets (32 vertices, 36 faces, two components). That is the third polyline fixture: row 1006 measured it (my TB-REV-184 U1 flagged this exposure but kept it), while no reader ever reaches it.
- The receipts also expose a formatting defect, which my U1 missed: `productionStagedDigestEqual=1not-applicable`.

**W2 — CB-205V (exact, test-only) is the critical-path successor.**
- The polyline loop stops once both firsts are found. Census rows print ` published=not-applicable`. The receipt count becomes `9 + visited`.
- Every assertion stays. Row 1006 was never accepted, so this is a scope correction to what readers read, not a weakening.
- QF1 is not hidden by this: it gets its own falsifier row (W4).
- [Manifest](gates/Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Exact_Manifest.md). It also states TB185V's exact receipt prediction.

**W3 — QF1 is incomplete as frozen.**
- `verify_records` rescans the whole forest once per class, with two map lookups per edge (`RemeshPipeline.cpp:8506–8532`). That is K×F·log N, the same order as the path rebuild.
- TB-REV-185T saw this and deferred it with "measure if the gate still cannot finish". That plan guarantees a second full-gate cycle.
- The producer's per-class certificate scan (`:6079`) is K×R binary searches with no allocation. It is lower cost, so it is left for measurement.

**W4 — Exact QF1 diffs ([manifest](gates/Architecture_M6_CP3_CB207_QF1_Quotient_Forest_Cost_Exact_Manifest.md)).**
- **CB-207A:** builds a `QuotientForestAdjacency` once for each owner. The producer updates its index incrementally, while publication and the verifier each build a separate read-only index.
  - It uses a sorted vector with `upper_bound` insertion, not the multiset TB-REV-185T proposed. Forest degrees are small, and the vector keeps the traversal type and the reverse iteration unchanged.
- **CB-207B:** buckets the verifier's edges by class.
- **CB-207C (to be frozen later):** a test-only termination and size receipt for close_sheets at production defaults. It prints N, K, R, F and the largest class size.
- **Sufficiency is not claimed.** The sampled phases fit either of two explanations:
  - many small classes with a large F, which these diffs fix;
  - one oversized class, which they would not fix, and which would itself be a semantic question.
- CB-207C distinguishes the two.

**W5 — Syntax-only checks** (llvm clang++, `-fsyntax-only -Wall -Wextra -include iterator`, in a throwaway worktree, since removed).
- All three diffs pass `git apply --check` in sequence, and every postimage hash matches.
- `RemeshPipeline.cpp`: HEAD, 207A and 207B each have 0 errors and 31 warnings.
- `FieldAlignedCurveNetworkTests.cpp`: HEAD and 205V each have 0 errors and 45 warnings.
- No new warnings. These are not compile evidence.

**W6 — Carried.**
- TB-REV-184 U1–U4 are carried.
- Reach classification can now proceed from TB185V. TB185T is diagnostic and gives no acceptance credit.
- V5, V10 and V11 are carried. R1–R6 and S2/S3 are carried.
- J6, E5, CB-190 and CP3/497/D0/H4 stay held.
- QF1 is still a non-stable candidate.

## Turn sequence (supersedes TB-REV-185T's CB-205U → TB185U)

**Critical path:**
1. **`M6-CP3-CB-205V-P13-REACH-RECEIPT-READER-SELECTION-SCOPE`:** exact test-only diff; compile only.
2. **`M6-CP3-TB-EXEC-185V`:** 1006/1006 under the exact receipt prediction.
3. **`M6-CP3-TB-REV-185`:**
   - Classify readers from the receipts.
   - Freeze CB-206: the signature flip at `SurfaceCellTracing.cpp:5336`, rows 648/978/979, the row 979 label, and the row 1006 transcript.
4. **CB-206 → TB-EXEC-186:** V5, full compare, STOP-on-RED. Then **TB-REV-186**.

**QF1 track, after step 4:**
5. **CB-207A → CB-207B:** exact, compile only, one turn each.
6. **CB-207C:** test-only close_sheets termination and size receipt. Then **TB-EXEC-187 → TB-REV-187**.

**Then:** parameter deletion, V3b, R1, O48. CB-190 stays off the critical path.

## Lessons

- When a diagnostic row stalls, check first whether the stalled part is something any reader actually needs. Scope the receipt to the reader before fixing the product on the critical path.
- A cost fix frozen in Review must cover every loop of the same order that it already found. Deferring one guarantees another gate cycle.
- A cost hypothesis needs a size receipt that can tell "many small" apart from "one huge". Without it, sufficiency cannot be falsified.
