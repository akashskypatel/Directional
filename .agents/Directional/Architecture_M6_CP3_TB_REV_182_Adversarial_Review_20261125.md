# TB-REV-182 adversarial continuation: resolving activation stop A1 (2026-11-25 UTC)

This continues `M6-CP3-TB-REV-182`, after the [independent review](Architecture_M6_CP3_TB_REV_182_Region_Corner_Singularity_Reach_Independent_Review_20261125.md).

- **Method:** runtime-free, using source reading and Haiku read-only work: test and source extraction, a census of the production sphere, and authoring and syntax-checking the CB-203 diff.
- **Product and test bytes:** unchanged at `5698f79a7`.

## Verdict

- **Upheld:** TB182 1004/1004, P1, and D-U carried.
- **A1 is resolved as follows:**
  - **R1:** the owner authorizes adding row 979.
  - **R2/R3:** row 858 is decoupled from the sphere premise by a test-only contract, CB-203, frozen here.
  - **R5:** activation is split into narrow turns.
- **Corrections to earlier review records:**
  - **R2:** TB-REV-160 V7 overclaimed coverage of row 858.
  - **R6:** the activation flag is named exactly.

## Findings

**R1 — Owner authorization (recorded).**
- On 2026-11-25 the user (the owner) directed this turn to resolve "Owner must authorize the Branch A activation premise amendment to include row 979".
- This record takes that direction as the authorization.
- The Branch A premise-change set becomes rows 393/648/858/971/972/978 **plus 979**.
- Row 979 requirements, carried from the independent review:
  - Its old negative is preserved through an explicit unstaged network: `diagnose_with_arrival_priority(..., field_aligned_production_arrival_priority(), false)` must still be rejected with `CutSearchExhaustedBeforeCellularity`.
  - The production network must equal the explicitly staged network (semantic digest), its cut graph must certify embedded cellularity, and its plan must build.
  - No other row is amended by this authorization.

**R2 — Row 858's evidence boundary, and a correction.**
- **What row 858 reads.** Row 858's sphere sub-case (`SurfaceCellTracingDisplayTests.cpp:152–169`) reads the *full pipeline's* terminal stop through `remesh_from_raw_cross_field`. That stop is currently the cut-graph face, so `sourceFace` is present.
- **Correction to TB-REV-160 V7.** V7 claimed that row 979's prints "cover what rows 393, 648, 858 … read". That is false for row 858: row 979 stops at the plan and never runs the pipeline stages after it.
- **No way to measure before activation.**
  - `remesh_from_raw_cross_field_impl_with_stage_products` (`RemeshPipeline.cpp:12210`) builds its own network at :12919, and no entry point accepts a supplied one.
  - `make_from_candidate` (`SurfaceCellTracing.cpp:6396–6431`) re-canonicalizes with the defaults, and validation rejects any mismatch (:5925).
  - A production option seam is rejected: it would create a second source of truth, against V11.
  - So the sphere's stop after activation cannot be measured before activation, and must not be predicted.

**R3 — Resolution of R2: CB-203 contract, frozen ([manifest](gates/Architecture_M6_CP3_CB203_P13_Display_Stop_Locus_Contract_Exact_Manifest.md)).**
- **The sphere is only a witness.** In row 858 it stands in for the corner-keyed terminal-locus display path (`SurfaceCellTracingDisplay.cpp:188`), not for a cut-graph outcome.
- **Row 858 becomes stage-agnostic.** The terminal code is not `None`, and every reported face, related face, edge or vertex is displayed. The `has_stop_location` and `cellCount == 0` checks are kept, and a `SphereDisplayStop` receipt line is printed.
- **New row 1005 keeps the corner-keyed path covered**, independent of the pipeline. Corners given in rotated order must display exactly one face.
- **Before activation it is behavior-identical,** because the sphere still reports `sourceFace`. It is strictly more specific for edges and vertices.
- **After activation**, row 858's outcome is backed by assertions whichever stage stops the sphere. The receipt then measures that stage, so nothing is predicted.
- **If the sphere instead produces a complete result**, `has_stop_location` fails. That would be a genuine STOP, not a hidden pass.

**R4 — Review of CB-203.**
- Hashes, `apply --check` and `diff --check` all pass.
- Syntax: 0 errors, and warnings identical to HEAD.
- Pre-existing defect: `SourceChartTransitions.h:529` uses `std::inserter` without `<iterator>`, so the syntax check needed a compile-only shim. This is outside scope; it is recorded for CB-190.
- No assertion is weakened at the current premise. Coverage of the face-by-corners path moves to row 1005, which does not depend on whether the sphere is staged.

**R5 — Census: the premise set is still not closed at seven rows.**
A census of production sphere paths across the gate found the following.

- **Certain flips under activation:**
  - **979:** the production cut negative.
  - **978:** `semantic_digest` of production compared with the explicit unstaged network, at `:17916`.
  - **648:** the sphere half un-skips at `:14392`, then `ASSERT_FALSE(sphere.plan)` at `:14405` fails.
  - **858:** handled by CB-203.
  - **393:** the carrier ends `{4,6,15,19}` at `:17762` describe the unstaged network.
- **Static-unknown production readers.** These are not edited, and run under STOP-on-RED. Each becomes a separately frozen correction only on measured evidence:
  - 394, 396, 397, 644, 645, 693, 694, 843/844, 963, 968, 971 (V10) and 972.
- **Expected neutral:** 669.
  - The census entry (`SurfaceCellTracing.cpp:6262`) and `make` both take the canonical default flag, so a single-source flip moves them together, as V11 requires.
- **Deferred ledger rows 192 and 344** (open sphere cut/plan REDs) may change. Record their outcome; there is no promotion.
- **Historical binary:** MilestoneGP26/27 lie outside the gate and are noted only.

**R6 — Naming the activation flag precisely.**
- The activation is the default of `stopAtLaterSlideEntry` in `canonical_field_aligned_candidate` (`SurfaceCellTracing.cpp:5328–5336`).
- It is not the arrival priority: `field_aligned_production_arrival_priority()` stays `ArcLengthFiltered`.
- V11's line reference `:5241` is stale.

## Turn sequence (supersedes the TB-REV-181 step 4A wording)

1. **`M6-CP3-CB-203-P13-DISPLAY-STOP-LOCUS-CONTRACT`:** exact test-only diff, compile only.
2. **`M6-CP3-TB-EXEC-183-P13-DISPLAY-STOP-LOCUS-CONTRACT-FULL-GATE`:**
   - 1005 + 81 = 1086 members, and all 1005 PASS.
   - Only row 858's receipt and the new row 1005 may differ from TB182.
3. **`M6-CP3-TB-REV-183`:** accept, then freeze CB-204 as an exact diff.
4. **CB-204, test-only pre-staging, green before activation:**
   - Row 979's production negative is rewritten onto the explicit unstaged network, plus an assertion that production equals unstaged.
   - Row 978's equality is rewritten with an explicit flag.
   - After this, activation only flips "production ≡ unstaged" to "production ≡ staged".
   - Then TB-EXEC-184, then TB-REV-184, which freezes CB-205 from the TB182/TB184 receipts. This includes row 393's eight exact carrier ends and the certificate values for row 648's built plan.
5. **CB-205, activation:**
   - The single-source default flip (V11), plus exact replacements for the certain-flip rows only.
   - Then TB-EXEC-185, with the BunnyRandom census (V5) and STOP-on-RED for the static-unknown readers.
   - Then TB-REV-185.
6. **After that**, each in its own turn: parameter deletion, V3b, R1, O48. CB-190 stays off the critical path.

## Carried

D-U, J6, E5, CB-190, and CP3/497/D0/H4 stay held. There is no promotion.

## Lessons

- Before freezing any premise set for a default flip, census every production reader of the affected fixture. A list inherited from an earlier review is not a census.
- When a later stage cannot be measured before a behavior change, replace a premise-bound assertion with the contract it witnesses. Move the specific path to an independent witness, so the change's own gate does the measuring.
