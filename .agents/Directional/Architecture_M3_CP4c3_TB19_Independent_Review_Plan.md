# M3-CP4c-3-TB19 Independent Review + Plan

## Turn

**`M3-CP4c-3-TB19-REV` — independent REVIEW + PLAN only.**

TB19 is a valid semantic RED, so this review is mandatory before any successor Code + Build work. This plan
authorizes no Directional runtime, compile, package, product/test/fixture/selector mutation, or acceptance attempt.

## Immutable evidence to review

- semantic source `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`;
- compile artifact `9908695433`;
- selector 384 SHA-256 `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`;
- TB19 run/job `33798040003 / 100790444711`;
- TB19 result/log artifacts `9910078670 / 9910079341`;
- exact ledger SHA-256 `e9ab64a8392aa1e16e30e03f440865914df846567e4b4fd12f3dce241841c04b`;
- package census SHA-256 `c238668140634325a75dbb48ed23ce5659376cb5d2d7b79f3f3f46ab275e133d`;
- result `376 PASS / 8 RED`, accepted `365/365`, reds 366/367/368/369/370/371/372/374.

## Binding review measures

### CR0 — authority and immutability

Re-verify the immutable source/artifact/selector/run identities, exact 384-row arithmetic, accepted 365/365
boundary, and identical pre/post package census. Confirm no code drift between semantic source and any source lines
used for static adjudication.

### CR1 — prove what the new terminal predicate actually means

Trace the sole `UncutFaceComponentOrbitSeedNotUnique` emitter and all state that feeds its `seedOrbits` set. For
the mechanical witness component containing source face `(0,1,2)`, determine from retained evidence plus static
authority whether the failing cardinality is provably **zero**, **greater than one**, or still unobservable.

Do not infer the cardinality from the error name or from the global six-orbit census. If the decisive cardinality,
component membership, or incoming edge→orbit seeds are not derivable, say exactly what bounded evidence is missing.

### CR2 — compare the historical same-code torus stop without assuming recurrence

The code `UncutFaceComponentOrbitSeedNotUnique` appeared historically on the torus before CP4c-2 closed. Compare
the producer state, component/barrier inputs, and emitter path to TB19's mechanical witness. Decide whether this is
the same root mechanism, a distinct instance of the same guard, or evidence-insufficient. Do not merge candidates
by name alone.

### CR3 — adjudicate the local-fragment non-crossing candidate

TB19 retained 70 face rows, all locally evaluated, all `chordsCrossInside=false`, with no truncation. Decide what
this proves:

- witness-local sufficiency only;
- a product invariant derivable from existing tracing/embedding contracts; or
- still no universal theorem.

`M3-CP4c3-TB18-REV-CAND-01` may be closed or promoted to a fatal local invariant only if the review proves the
needed scope. One witness being non-crossing is not by itself a universal proof.

### CR4 — 366/367/371/372 ownership

Record that all four cleared the CB21 fragment mismatch. Separate their ownership after the new frontier:

- 366 is the primary mechanical production witness;
- 367 genuinely consumes `plan`;
- 371/372 read only the atlas but still abort in the shared all-products fixture.

Decide whether `M3-CP4c3-TB10-REV-CAND-01` should now authorize the already-specified test-only atlas-scoped fixture
decoupling, remain deferred behind the product frontier, or be retired for a proved reason. Do not change the
assertions or selector membership in this review.

### CR5 — carried-surface freeze

Confirm 368/369/370/374 are semantically unchanged from TB18 and remain under their existing owners. Do not combine
them into the component-seed correction merely because they are red in the same gate.

### CR6 — regression accounting

Update every affected candidate in `Regression_Root_Cause_Tracker.md`. Stable totals remain unchanged unless the
review proves a stable event/category/recurrence transition under the established accounting rules. Reconcile the
new TB19 candidate with any historical same-code record explicitly.

### CR7 — choose the smallest justified successor

If CR1–CR6 prove a product defect and its bounded correction, freeze exactly one successor Code + Build plan with:
accepted-prefix safety, frozen selector rules, mandatory GMP/GMPXX compile targets, explicit prohibited surfaces,
and the next artifact-only discriminator. If the decisive state remains unobservable, freeze one diagnostic-only
CB instead. If a representation/definition change is required, stop at that boundary rather than patching around
it.

### CR8 — review-turn durable updates

As required for every REVIEW turn:

- update `ORIENTATION.md`;
- perform the review-turn document consolidation in `CLEAN_UP_POLICY.md`;
- update `M3_CP4c_Current_And_Forward.md`, `TODO.md`, handoff, changelog, and regression tracker;
- preserve every byte-frozen selector and durable section;
- leave exactly one next-turn plan.

## Prohibited conclusions

The review may not:

- call the newly exposed error a regression merely because it is red;
- assume zero seeds versus multiple seeds without evidence;
- treat global orbit count 6 as the affected component's seed count;
- promote `localFragmentCount` to a universal fatal oracle from one non-crossing witness;
- modify 368/369/370/374 ownership without evidence of semantic movement;
- start the successor CB inside the review.

## Exact next action

Execute **`M3-CP4c-3-TB19-REV`** under CR0–CR8 and stop at the REVIEW + PLAN turn boundary.
