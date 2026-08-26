# M3-CP4c-0-TB-R6 — Independent Review + Plan Brief

**Status:** EXACT NEXT / NOT YET EXECUTED
**Turn type:** Independent review + planning only.

## Boundary

This successor reviews TB-R6 evidence and freezes exactly one bounded successor. It must execute **no Directional runtime, test, benchmark, build, configure, relink, repair, or generated discovery**, and must mutate **no product source, test source, fixture, selector, tolerance, acceptance criterion, or build configuration**. It must not retry Q8 or enter CP4c-1/2/3.

Immutable evidence under review:

- semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`; package `9619352525`;
- TB-R6 control/run/job `a9ae307590b0cc23080452c4a5013674efc48fc2 / 33006282429 / 98300813772`;
- result `9620769314` / `fe6a73175399b764f7cbb3ea2963a8deb40d6d0b5afcc3e9a603102ee4936684`;
- diagnostic `9620770049` / `ce87da5a919e31f7e36a8d904dfaad7c7d9c92b9bebf36a494de096e7cb691cb`;
- gate 338/338, F3 2/2, G5 PASS/non-gating, H1/J3 PASS/non-gating; Q8 creditable RED criterion 2.

## What TB-R6 already decides

Do not reopen these conclusions without contradictory evidence:

1. **The fan remains excluded.** H1 reproduces 2 directed / 1 distinct disagreement on edge `1-4`; J3 independently proves its imposed matching disagrees with geometry on exactly that edge.
2. **The legitimate H1 population is 388 directed / 194 distinct.** Per witness: two-ring 4/2, sphere 144/72, torus 240/120. Only 52 directed disagreements are singular-incident.
3. **J3 is clean on all legitimate matching authority.** Two-ring 20/20, sphere 288/288, torus 216/216: **524/524** declared matchings agree with geometry. Current H-B field-matching/edge-aliasing is therefore not supported on the legitimate witnesses.
4. **The live Q8 edge is not a matching-mismatch case.** Edge `6-8`, branch `3 → 1`, has `matching=0`, `rawGaugeSource=1`, `rawGaugeTarget=3`, `signedLift=2`; J3 agrees with its declared matching. Under the frozen decision table this selects **A1 gauge composition in `build_branch_transports`** as the direct owner of the live Q8 rejection.
5. **A second legitimate class remains.** 254 directed / 127 distinct disagreements have `matching=0`, equal raw gauges, and lift 0. Under the frozen table these point at **A1 flow classification / direction publication in `build_boundary_pairing`**. They are not explained by the live edge's unequal-gauge decomposition.
6. Q8 criterion 2 remains the same binding red and is not a new accepted regression. Stable totals remain 42 / 14 / 28.

## Required independent review questions

The review must answer all of the following before authorizing a successor:

1. **Re-derive the A1 composition contract.** From `DESIGN.md`, Amendment 7/8, `FieldTransportAtlas`, and exact source, derive the expected relation among declared matching, source raw gauge, target raw gauge, and published signed lift. Explain why edge `6-8` should map source branch 3 to the physically incoming target branch 3 rather than published target branch 1.
2. **Locate the precise gauge-authority defect.** Determine whether `build_branch_transports` uses a wrong source/target gauge sign, wrong gauge orientation, wrong raw/canonical direction, or a downstream interpretation of an otherwise-correct lift. Do not infer the fix from the numeric `+2` alone.
3. **Adjudicate the 254/127 equal-gauge residual.** Reconstruct at least one two-ring, one sphere, and one torus representative with `matching=0`, equal gauges, lift 0. Determine whether `build_boundary_pairing` publishes the wrong flow class/direction, whether the H1 invariant is comparing the wrong physical side, or whether a lower common convention defect also explains edge `6-8`.
4. **Common invariant versus two defects.** State whether the unequal-gauge live-Q8 class and equal-gauge residual share one lower authority invariant. If not, explicitly split them and justify why the next correction is scoped to the Q8-owning class without hiding the residual.
5. **H-B closure.** State precisely what J3 excludes and what it does not. Do not keep "matching aliasing" as an active explanation for the current legitimate witnesses unless a source-level mechanism survives 524/524 geometry agreement.
6. **Falsifier design.** Freeze one independent test/oracle that would fail before the chosen correction and pass only when the owning invariant is restored. It must not merely assert Q8 output and must preserve the 338 selector and frozen Q8 criteria.
7. **Successor scope.** Freeze exactly one bounded successor **Code + Build** measure series if the owner is proven. If source review cannot distinguish the common-invariant question, freeze a diagnostic-only CB instead. No fixture-shaped one-edge fix and no tolerance retune.

## Review evidence requirements

Use `Architecture_M3_CP4c0_TB_R6_Artifact_Only_Test_Benchmark_Report.md`, the complete H1/J3 raw censuses in artifact `9620769314`, the R5 independent review, `DESIGN.md` cross-field/transition authority, Amendments 7–8, and the exact source implementation. Static source/arithmetic inspection is allowed; runtime is not.

The review must update `Regression_Root_Cause_Tracker.md`, name exactly one successor, and stop. It may not implement that successor in the same turn.

## Accounting / stop rule

Stable totals remain **42 / 14 / 28** unless the review proves that already-accepted authority actually regressed; the accepted 316 prefix remains green and CP4c-0 has never been accepted. Produced-witness debt remains **5**; M3 packages **45**.
