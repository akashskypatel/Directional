# M3-CP4c-0-TB-R5 — Independent Review + Plan Brief

**Status:** EXACT NEXT / NOT YET EXECUTED
**Turn type:** Independent review + planning only.

## Boundary

This successor reviews TB-R5 evidence and freezes one bounded correction plan. It must execute **no Directional runtime, test, benchmark, build, configure, relink, repair, or generated discovery**, and must mutate **no product source, test source, fixture, selector, tolerance, acceptance criterion, or build configuration**. It must not retry Q8 or enter CP4c-1/2/3.

Immutable evidence under review:

- semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e`; package `9601160869`;
- TB-R5 hosted control/run/job `3f9864fddef696dc7d95084fdd41b680a78f5b37 / 32994846466 / 98261255799`;
- result `9616160533` / `1ecfd85f06b40466f0e8193d1603950cd93b120723568024a1b50595e9902ad8`;
- diagnostic `9616161522` / `7cb10caee2f1e861368da3098e320f10bee3b13d51439bc868e1e3c60aa14b0e`;
- gate 338/338, F3 2/2, G5 PASS/non-gating, H1 PASS/non-gating `390/4224`; Q8 creditable RED criterion 2.

## What TB-R5 already decides

Do not reopen these conclusions without contradictory evidence:

1. **H-A is excluded.** H1 disagreements are dominated by `signedLift=0` and also occur at even ±2, so they are not an odd-lift-only sign/direction convention defect.
2. **H-C is excluded.** A1 itself has 390 flow-agreement violations; the live sphere failure is not merely A2a carrying a wrong branch into otherwise-sound A1 authority.
3. **The ~50% uniform-index branch is unsupported.** Witness rates range 2.5%–13.8889%.
4. **H-B is a candidate, not a verdict.** Matching aliasing remains plausible, but H1 did not prove singularity localization. The fan has two lift-0 disagreements even though its matching is manually prescribed rather than computed through the sphere/torus aliasing path.
5. Q8 criterion 2 remains the same binding red; this is not a new accepted regression.

## Required independent review questions

The review must answer all of the following before naming a successor:

1. **Violation topology.** Map the 390 H1 violations to unique undirected carriers and vertices. Measure distance/incidence to field singularities separately for two-ring, prescribed sphere, and torus. Do not call the pattern "singularity-localized" without that count.
2. **Lift-0 mechanism.** Reconstruct representative lift-0 disagreements from each witness, especially fan edge `1-4`, sphere edge `0-1`, and at least one torus locus. Explain how the same branch index can be outflow on both incident faces when `signedLift=0`.
3. **Edge `6-8` relation.** Reconstruct sphere edge `6-8` in the H1 census and G5 trace. Determine whether its `signedLift=2` is one member of the same sparse mechanism as the large lift-0 population or a distinct subcase.
4. **Matching provenance split.** Compare computed matching paths (two-ring/sphere/torus) against the manually prescribed fan. If H-B matching aliasing is proposed, explain why the fan disagrees without that computed path, or prove that a different matching-authority operation is shared.
5. **Gauge versus physical direction.** Re-check the source/target physical directions and face-local gauge only where needed to adjudicate the sparse pattern; do not resurrect the already-refuted canonical-normal parity hypothesis.
6. **Owning invariant.** State one falsifiable invariant at the lowest correct authority boundary. It must explain both a lift-0 representative and the live sphere edge `6-8`, or explicitly split them and justify why only one split owns Q8.
7. **Successor scope.** Freeze exactly one bounded successor **Code + Build** measure series. It must include a falsifier that proves the chosen invariant independently of Q8, preserve the 338 selector and frozen Q8 criteria unless the review proves they are themselves invalid authority, and make no fixture-shaped one-edge correction.

## Review evidence requirements

Use `Architecture_M3_CP4c0_TB_R5_Artifact_Only_Test_Benchmark_Report.md`, the complete H1 raw census in artifact `9616160533`, H4 matching provenance from the R4 review/CB5 record, `DESIGN.md` cross-field/transition authority, and the exact source implementation. Static arithmetic/source inspection is allowed; runtime is not.

If the evidence cannot distinguish H-B from another sparse A1 mechanism, the review must freeze a **diagnostic-only** CB that separates them rather than guess a production fix. A production semantic correction is authorized only if the review proves the owning invariant and mechanism.

## Accounting / stop rule

Stable totals remain **42 / 14 / 28** unless the review proves that an already-accepted authority actually regressed; detecting a pre-existing unasserted defect does not retroactively create a regression event. Produced-witness debt remains 5; packages 44.

The review closes only when it records its adjudication in the regression tracker and names **exactly one successor**. Stop there; do not implement the successor in the same turn.
