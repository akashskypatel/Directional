# M5-CP3-CB19 — Storage-Canonical Produced-Test Correction Plan

## 1. Turn contract

**Turn:** `M5-CP3-CB19`
**Mode:** **TEST-ONLY CODE + BUILD / RUNTIME-FREE**
**Owner:** `M5-CP3-TB1-R15-R1-CAND-01`
**If compile/package green:** `M5-CP3-TB1-R16-EXEC` -> mandatory `M5-CP3-TB1-R16-REV`.

CB19 corrects only the stale representation assumptions in the two nonzero-Z4 produced test contracts. It must not change product implementation, fixture/field/A3 authority, frozen definitions, selector430, benchmark membership, or accepted relation semantics.

## 2. Cause already proved by Review

Frozen §16.3 defines semantic Forward -> Reverse action before storage canonicalization and permits canonical storage to keep `T` or the inverse `T^-1` with both routes reversed. CB17 implements this rule and provides `resolve_periodic_relation_semantic_action(...)`. The mechanically valid R15-R1 ledger passes the focused storage/semantic-resolution identity.

Produced rows16/17 instead directly compare storage-canonical `route/action/cutRoute` to semantic witness facts. On the committed torus this is observably the inverted representation: expected semantic `Q=3`, stored action rotation `1`, and stored cut route aligns opposite semantic Forward. Both tests therefore stop before their binding product falsifiers.

## 3. Authorized implementation scope

Edit only the directly coupled test/helper surface needed to express semantic Forward -> Reverse authority. Expected primary owner is `tests/SurfaceCellTransitionQuotientTests.cpp`.

For each affected produced test:

1. Bind the exact Forward and Reverse phase-front edges by the accepted A3 interval orientation and relation ID before semantic comparisons.
2. Resolve the semantic action with `resolve_periodic_relation_semantic_action(storedRelation, forwardEdge, reverseEdge)` and require a value.
3. Resolve semantic generator-route orientation from the same cut-route/Forward-edge relation, without search:
   - stored cut route equals Forward edge route -> semantic generator route is stored generator route;
   - reversed stored cut route equals Forward edge route -> semantic generator route is reversed stored generator route;
   - otherwise fail closed.
4. Compare that semantic route and semantic action to the independent witness authority. For the committed torus the expected semantic turn remains `Q=3`; do not retune it to stored `1`.
5. Compute relation endpoint-state expectations and Forward -> Reverse coordinate/branch equations from the resolved semantic action.
6. Preserve canonical stored relation ID and existing certificate/storage invariance checks where they are representation-level facts.

Do not introduce inverse/best-of-two probing, result-dependent orientation selection, alternate relation search, free translation/gauge fitting, or permissive fallback.

## 4. Required row16 falsifier

Identity remains exactly:

`M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`

The corrected test must non-vacuously prove:

- produced relation exists and is owned by the independently selected witness;
- this committed witness encounters the inverted-storage case: stored action/route representation differs from resolved semantic Forward -> Reverse representation;
- resolved semantic generator route equals the independent A3 witness route;
- resolved semantic turn equals independent `Q=3` and remains nonzero;
- exact semantic endpoint action/branch equations hold;
- materialization succeeds;
- selected certificate consumes this periodic relation with the exact relation action in its valid stored/inverse representation;
- `consumedPeriodicHolonomies > 0`.

No assertion may be deleted merely to obtain green output. The final materialization/certificate discriminator is unchanged in strength.

## 5. Required row17 falsifier

Identity remains exactly:

`M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`

Before tampering, establish the same semantic Forward -> Reverse witness non-vacuously, including the inverted-storage case and semantic `Q=3`. Then retain the existing **one-fact transform tamper** on the stored relation and require exact checked-factory rejection:

`SurfacePhaseFrontProductErrorCode::NonReciprocalPeriodicRelation`.

Do not change relation ID, route membership, fixture, A3 ownership or expected error merely to make the test pass.

## 6. Compile-only validation

Use the mandatory GMP/GMPXX Code + Build workflow. Compile/link all eight standard required targets and package evidence exactly as required by project policy. Generated Directional runtime execution is prohibited in CB19: no GTest invocation, discovery/list/help/version command, benchmark, `ctest`, or custom runtime input.

Required compile evidence includes clean source receipts, exact semantic source SHA, root package manifest, GMP/GMPXX linkage, all target exit codes, and `runtimeExecution=false`.

## 7. Fresh R16 precommitment

If CB19 is compile/package green, `M5-CP3-TB1-R16-EXEC` must execute the same **448** identities as R15-R1 from process 1, benchmark **0**, against the immutable CB19 candidate. No R15/R15-R1 row, PASS, selector credit or semantic observation is carried into the R16 ledger.

R16 must retain exact-one selection, zero skips, complete self-excluding evidence manifest, exact selector430/routing authority, immutable postflight, no timeout/watchdog, no mode/package repair and no retry after generated runtime starts. Mandatory successor is `M5-CP3-TB1-R16-REV` regardless PASS/RED.

## 8. Acceptance / stop rules

CB19 is green only if:

- the diff is confined to the authorized test/helper contract;
- no product/fixture/field/A3/selector/frozen-definition semantics change;
- the inverted-storage non-vacuity requirement is explicit in both affected produced contracts;
- row16 still owns materialization/certificate consumption;
- row17 still owns the one-transform typed nonreciprocal rejection;
- all mandatory compile/link targets are green with `runtimeExecution=false`.

If the semantic direction cannot be resolved deterministically from existing A3/cut-route authority, stop and return to Review/design authority. Do not invent a heuristic.
