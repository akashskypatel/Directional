# `M6-CP1-CB12-CLOSE-R2` — Identity29 Witness Recovery Code + Build Plan

**Owner:** `M6-CP1-CB12-CLOSE-R2`
**Type:** Code + Build only; compile/package; runtime forbidden.
**Authority:** `Architecture_M6_CP1_TB12_Close_Review_Record.md` and RA-27.

## Goal

Recover only `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`. The defect is test-authority witness construction, not established production behavior. **Do not change production C1/A5/A6/A7 semantics.**

## Required implementation

1. Replace identity29's assumption that `split_isolation_fixture()` must contain a selected cross-sheet forest edge.
2. Construct a deterministic valid A5 witness whose normal `SurfaceQuotientProducer::produce` result contains at least one selected-forest relation with disjoint endpoint `cornerWedgeSheets`. Prefer deriving records from existing typed fixture authority and the A5 validation publication seam rather than introducing geometric tolerance or row-order dependence.
3. The A6 witness must be production-derived; do not fabricate a `SurfaceQuotientProduct`, bypass relation validation, or mutate private product state.
4. Require the selected cross-sheet edge before tampering, then prove baseline A7 acceptance.
5. Rewrite the relevant relation-side/equivalence and endpoint `cornerWedgeIsolation` transitions for that exact edge to unrelated sheet IDs. Republish the A5 records through the existing validation seam.
6. Require exact A7 failure `UncertifiedCrossSheetBinding` and site `cross-sheet`.
7. Keep the identity name and focused-30 ordering unchanged. Identity30 and identities1-28 remain byte/behavior untouched.

## Forbidden scope

- no production source change;
- no change to quotient membership, selected-forest algorithm, C1 predicate, transition semantics, diagnostics or tolerances;
- no selector449/routing449 change;
- no test that passes without reaching the tamper discriminator;
- no generated Directional runtime in this turn.

If a valid production-derived selected-cross-sheet A6 witness cannot be constructed without changing production semantics, **STOP for Review**.

## Static and compile gate

- `git diff --check`;
- changed production source count = 0;
- focused-30 identity list/order unchanged; focused-28 remains exact first-28 prefix;
- selector449/routing449 bytes unchanged;
- compile/package with mandatory reusable GMP/GMPXX workflow, standard eight targets, `runtimeExecution=false`.

Compile-green successor: `M6-CP1-TB12-CLOSE-R1-EXEC`, exact **30 + 449 = 479** fresh exact-filter processes, then mandatory `M6-CP1-TB12-CLOSE-R1-REV`. Candidate promotion remains forbidden until that Review.
