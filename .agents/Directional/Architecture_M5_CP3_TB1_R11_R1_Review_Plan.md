# M5-CP3-TB1-R11-R1 Review Plan

**Turn:** `M5-CP3-TB1-R11-R1-REV`
**Type:** **REVIEW + PLAN / runtime-free / no implementation**
**Subject:** mechanically complete R11-R1 semantic RED on immutable CB12 candidate `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`
**Entering runtime:** `35778555375 / 106917917282`, result/log `10717297354 / 10717921412`

## 1. Review goal

Independently re-open the complete R11-R1 evidence, re-derive the exact `444 PASS / 2 RED` ledger and immutable postflight, then
adjudicate why produced rows4/5 still stop at `PeriodicActionCorrespondenceMismatch` after CB12 replaced insertion-order authority
with the frozen A3 Forward -> Reverse direction. Review must distinguish an insufficient correction of
`M5-CP3-TB1-R10-REV-CAND-01` from a distinct product or test-authority defect before authorizing any next Code + Build.

No Directional runtime, source/test mutation, compile, package repair, selector publication or debt discharge occurs in Review.

## 2. Independent evidence re-derivation

Review must independently verify, not inherit from EXEC prose:

1. candidate artifact/source, root **28/28** manifest, source archive, GMP/GMPXX build evidence and `runtimeExecution=false`;
2. routing artifact/identity-map and selector430/first427 exact hashes;
3. R11-R1 result/log outer digests and complete self-manifest **912/912**;
4. all **446** ledger rows, exact-one selection, zero skips and benchmark **0**;
5. mechanism **9/9**, focused atlas **1/1**, produced **4/6**, selector430 **430/430**;
6. protected selector ordinals **191/192/247/408** PASS;
7. exact package/source/execution-view postflight equality and every prohibited-operation counter zero;
8. row4/5 raw failures at exact `PeriodicActionCorrespondenceMismatch`, with row4 not reaching materialization/certificate checks and row5 not reaching tamper/typed-rejection checks.

Invalid R11 may be used only as diagnostic provenance. No row from it can substitute for R11-R1 evidence.

## 3. Re-derive CB12 directed authority

From exact candidate source and independent test/source authority, prove or falsify each link rather than assuming the CB12 intent:

1. identify the exact reciprocal same-region A3 interval pair selected for the nonzero-Z4 subject;
2. prove one member is semantically `Forward` and the other `Reverse`, including boundary-occurrence identity and exact interval direction;
3. prove production passes those exact pointers to `generator_route_for_span(ForwardOccurrence, ReverseOccurrence)` and
   `periodic_action_for_pair(ForwardEdge, ReverseEdge, generatorRotation)` without falling back to vector/insertion order;
4. independently derive the generator carrier/source transition direction and its exact quarter-turn from A3/source/atlas authority;
5. compare that directed rotation to the independent witness's `sourceRotation` and `atlasRotation` without using production's answer as the oracle.

If the semantic meaning of interval `Forward` is not the same direction required by source transition/action correspondence, state
that mismatch explicitly rather than trying the inverse direction until one works. Frozen §16 forbids best-of-two direction search.

## 4. Split the collapsed action-correspondence guard

The current product reason merges `!action.has_value()` with `generatorRoute.rotation != action.rotation`. Review must independently
reconstruct the operands and identify the first false predicate among:

- both endpoint `sourceChart` values present;
- reciprocal scale levels match;
- `R * first.from.branchRotation == second.to.branchRotation`;
- `R * first.to.branchRotation == second.from.branchRotation`;
- one exact lattice translation maps `first.from -> second.to`;
- the same translation maps `first.to -> second.from`;
- resulting `action.rotation == generatorRoute.rotation`.

Use exact integer/quarter-turn/lattice authority. Do not fit translation, rewrite endpoints, search rotations, invert direction as a
fallback, or use floating correspondence.

## 5. Adjudicate test authority and debt reachability

For rows4/5, independently audit the nonzero-Z4 witness construction through its pre-product chart oracle and source/A3-selected
relation witness. Determine whether the product rejects valid independently certified authority or whether the test asks incompatible
endpoint/branch correspondence of the produced charts.

Row5 cannot earn tamper/debt credit while baseline production fails before relation publication. Row4 cannot discharge the genuine
nonzero-Z4 materialization debt until the selected relation has nonzero rotation and translation, materializes, appears in a selected
certificate and increments consumed periodic holonomies. Preserve the original discriminators exactly.

## 6. Regression/accounting decision

Adjudicate `M5-CP3-TB1-R11-R1-CAND-01` and the inherited `M5-CP3-TB1-R10-REV-CAND-01` together:

- if CB12 correctly removed insertion-order authority but a distinct latent defect remains, close the old candidate as
  recovery-proved and open/classify the new root separately;
- if the Forward -> Reverse correction does not implement the frozen semantic direction, keep the prior candidate open as a failed
  recovery and freeze the smallest authority correction;
- if the independent witness is invalid, classify test authority and freeze only the witness correction;
- update stable event/category/recurrence accounting only from established historical transition rules, never from candidate naming.

Accepted runtime authority remains unchanged unless Review independently proves promotion conditions. Selector publication may be
pre-committed only if every proposed publication identity is independently green on one mechanically valid corrected candidate.
R11-R1 is semantic RED, so publication remains prohibited entering Review.

## 7. Required Review closeout

Because this is a REVIEW turn, update `.agents/Directional/ORIENTATION.md` and perform mandatory document consolidation under
`CLEAN_UP_POLICY.md`: index per-turn files retired by intervening CB/TB turns, preserve durable facts first, retain current review
record plus exactly one successor plan, and repair live citations. The Review record must state its exact corrective measure and
successor; do not implement that measure in the Review turn.
