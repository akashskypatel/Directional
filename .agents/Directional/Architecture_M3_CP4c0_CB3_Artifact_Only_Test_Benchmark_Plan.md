# M3-CP4c-0-CB3 Artifact-Only Test + Benchmark Plan

## Turn boundary

This plan is for **`M3-CP4c-0-TB-R3`**, artifact-only Test + Benchmark. It must not configure, compile, relink, regenerate, repair, edit implementation/test/benchmark/build logic, mutate fixtures/selectors/package contents, or create a replacement binary. All runtime comes from the immutable CB3 package.

## Immutable authority

- Semantic source SHA: `b135e219ee9269a73eaee32992d80c3921318011`
- CB3 compile workflow event/control SHA: `950d158c333622f59ed9d26c53b2028706954275`
- Authoritative package artifact: `9589508430`
- GitHub artifact ZIP SHA-256: `7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`
- Internal manifest: **27 entries**, all must verify
- Platform: immutable Linux package produced by GitHub Actions
- Required executable for the frozen selector and F3 falsifiers: packaged `directional_surface_cell_producer_tests`

## Frozen selector authority

The required CP4c-0 gate remains exactly **338 unique, non-empty identities in frozen order**:

- selector: `.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt`
- full SHA-256: `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`
- first-316 SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- first-328 SHA-256: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`

Do not reorder, replace, append, regenerate, or normalize the selector.

Two CB3 class falsifiers are mandatory **supplemental** identities and are deliberately outside the frozen 338 selector so F0/F6 do not mutate the frozen gate:

- `ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode`
- `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus`

They do not contribute selector-gate credit. A red supplemental falsifier is still a semantic blocker for checkpoint acceptance and must be preserved for review.

## TB-EXEC — pre-runtime integrity

Before any project executable runs:

1. Verify the downloaded artifact ZIP SHA-256 equals `7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`.
2. Extract once into a fresh immutable working directory.
3. Verify every packaged `SHA256SUMS` entry; expected **27/27 PASS**.
4. Verify `metadata/source-commit.txt` is exactly `b135e219ee9269a73eaee32992d80c3921318011`.
5. Verify `metadata/command-boundary.txt` records `runtimeExecution=false` and `turnBoundary=Code+Build-only` for the build package.
6. Verify all packaged source-status records are clean.
7. Extract/read the packaged source archive only for identity routing/integrity; do not edit it.
8. Verify the frozen selector count, uniqueness, order, and all three hashes above.
9. Verify the two supplemental F3 test names exist in packaged test source and route statically to `directional_surface_cell_producer_tests` without executing discovery/listing commands.
10. Record pre-run inventories/hashes for package, source archive, executable, selector, and relevant fixtures.

Any integrity mismatch is an orchestration/integrity RED. Do not run semantic validation on unverified bytes.

## TB-EXEC — frozen 338 gate

Execute each selector identity **alone in a fresh process**, in exact selector order, through the packaged executable using the static identity-to-executable route. Record for every process:

- ordinal and exact identity;
- exact command/filter;
- process exit code;
- selected/test/failure/disabled/error counts as exposed by the test framework output;
- elapsed time when available;
- deterministic diagnostic text on red.

A zero-selected filter is orchestration failure, never PASS.

### F6 continuation rule

The first semantic red fixes the required gate result to **RED**. Preserve its ordinal, identity, exit state, and complete diagnostic. **Do not stop executing the remaining required identities.** Continue each later required identity in its own fresh process and label every result after the first red as a **non-crediting observation**.

This continuation does not weaken the gate:

- GREEN requires all **338/338 PASS**;
- any required red means the gate remains RED regardless of later observations;
- later green observations after the first red confer no acceptance credit;
- never reorder the selector to move a suspected failure later;
- never repair or semantically rerun a deterministic red inside TB.

If an accepted identity 1–316 is red, classify it as an accepted regression and continue only for the F6 evidence census; checkpoint acceptance is already blocked and the result must route to review.

## TB-EXEC — mandatory supplemental F3 falsifiers

After the 338 census, execute each supplemental F3 identity once in a fresh process regardless of whether the selector gate was green or red. Record them separately from the 338 gate.

Expected result: **2/2 PASS**.

A red supplemental result does not change the arithmetic of the frozen 338 selector, but it is a semantic CB3 corrective failure and blocks checkpoint acceptance.

## Binding Q8 — verbatim frozen prediction

Q8 is only creditable when package integrity is exact, E6 is present in the immutable package, the frozen required gate is **338/338 PASS**, and both CB3 supplemental class falsifiers are green. Identity 338 green by itself is **not** a substitute for Q8.

The frozen Q8 text is:

1. Accepted **316/316** green, zero expectation edits.
2. The prescribed sphere reaches A2a and publishes a network — **24 traces**, from 8 index-1 singularities × 3 ports.
3. At least one sphere trace terminates on a trace/trace contact, producing a terminal `TraceIntersection` — which unblocks CP4c-1's C4/C5.
4. Face `1-2-5` with incoming `1-2` resolves to exactly one of `{1-5, 2-5}`, and the exit edge **flips** when the entry parameter is moved across the crossover.
5. The torus still publishes 0 traces; the mechanical still fails A1. Unchanged — they are not in scope.

Prediction 3 is binding: if the sphere publishes a network but produces no terminal `TraceIntersection`, preserve the result and route to review. Do not adjust the fixture, expectations, branch topology tolerance, or topology semantics.

If the 338 gate or either supplemental F3 falsifier is red, Q8 is **NOT CREDITABLE / NOT RUN**. F6 requires completing the remaining planned selector/F3 observation processes, not executing Q8 after the gate is known red.

## Frozen prohibitions

- Do not weaken T6 or Q8.
- Do not edit any accepted expectation.
- Do not change the prescribed-sphere fixture.
- Do not retune, widen, narrow, or delete `kBranchTopologyTolerance`.
- Do not alter E2–E6 semantics.
- Do not enter CP4c-1/2/3 implementation scope.
- Do not configure, compile, relink, repair, generate tests/discovery, or run performance benchmarks.
- Do not mutate the package, source, tests, fixtures, selector, or benchmark definitions.

Control flags must remain false: `packageMutation`, `sourceMutation`, `testMutation`, `fixtureMutation`, `selectorMutation`, `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`, `performanceBenchmark`.

## Post-runtime integrity and evidence

After the final planned process:

1. Recompute package/executable/source/selector/fixture inventories and prove they match pre-run state.
2. Preserve a machine-readable per-process ledger covering all 338 required identities plus both supplemental F3 identities.
3. Preserve the complete first-red diagnostic and all later non-crediting observation results.
4. Preserve Q8 evidence when and only when Q8 is creditable.
5. Upload result evidence and a separate detailed diagnostic/activity log even on failure.
6. Record TB semantic source SHA **and** TB workflow event/control SHA, run/job IDs, result/log artifact IDs and SHA-256 digests, selector hashes, and all mutation/build flags.

Evidence-upload failure prevents acceptance even if semantic commands passed.

## TB-REV obligations

TB-REV interprets existing evidence only; it launches no new unplanned runtime work. It must:

- distinguish required-gate credit from F6 non-crediting observations;
- separately classify the two supplemental F3 falsifiers;
- classify every observed regression/candidate in `.agents/Directional/Regression_Root_Cause_Tracker.md` before durable TB closeout;
- preserve P4/P5 from the independent review if identity 338 reports `VertexTransitSectorUnresolved` or `BranchTransportFlowDisagreement`; do not answer either with a tolerance;
- explicitly state whether Q8 was creditable and, if so, whether every frozen prediction passed.

If required gate **338/338**, supplemental F3 **2/2**, and Q8 are all green, CP4c-0 closes and becomes the new accepted runtime authority. Otherwise the next boundary is independent review + planning; no Code + Build repair is authorized inside TB.

## Rerun policy

No automatic semantic rerun. Retry only a diagnosed orchestration/infrastructure failure that produced no valid semantic evidence, with immutable package, selector, commands, fixtures, and semantic source unchanged. Do not rerun an unchanged deterministic semantic failure.
