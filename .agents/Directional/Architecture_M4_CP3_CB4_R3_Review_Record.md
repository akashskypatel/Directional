# M4-CP3-CB4-R3-REV Independent Review Record — semantic correction upheld; derivative packaged-test contract drift isolated

- **Phase:** M4-CP3
- **Validated semantic source commit:** `7fdc3c001de9193f8f94591d3e74d1c94c260195`
- **Review snapshot/control head:** `1dad640454306e3ed642640a1409168ed26c5920`
- **Snapshot run / artifact:** `34664102792 / 10287759503`
- **Reviewed plan:** `Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md`
- **Reviewed compile guard:** `Architecture_M4_CP3_CB4_R3_Compile_Guard_Record.md`
- **Reviewer independence:** same-agent review is user-authorized; decisive claims below were re-opened from primary source/evidence and re-derived rather than inherited from the prior turn.
- **Turn boundary:** runtime-free Review. No production, test, benchmark, selector or build configuration source may change in this turn.

## 1. Evidence reviewed

### Source and selector authority

The review re-opened the exact semantic diff from pre-R3 authority `463bcb9ab35f7b9941e03199c8ca0818b20db84c` to semantic commit `7fdc3c001de9193f8f94591d3e74d1c94c260195`, then compared the semantic commit to the review snapshot/control head. The latter drift is documentation/control-plane only; no `src/`, `include/`, `tests/`, `cmake/`, benchmark or selector semantic bytes changed after the preserved R3 semantic commit.

The R3 selector was re-hashed and statically re-owned from test definitions:

```text
rows                         = 403
selector403 SHA-256          = c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
first394 SHA-256             = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
first394 == selector394      = true
missing identities           = 0
duplicate identities         = 0
owner partition              = 30 / 257 / 75 / 41
row400 owner                 = directional_surface_cell_producer_tests
row400 source                = tests/FieldAlignedCurveNetworkTests.cpp
```

### Primary compile evidence

Failed preflight log artifact `10287418994` was independently downloaded and re-hashed at
`sha256:53488144ddedfea1d1e7eb98b57cc403ef93a22bd9260af1ea85747fc9b10fe3`.
The log proves:

- requested exact source `7fdc3c001de9193f8f94591d3e74d1c94c260195`;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only`;
- GMP and GMPXX found before configure failure;
- CMake configure stopped at `cmake/DirectionalTests.cmake:115`, called from line 266;
- the mandatory packaged-test contract still required `FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder` and found **0** source definitions;
- no target compilation or Directional runtime followed.

## 2. Independent semantic re-derivation

`build_source_index` preserves each source face's raw oriented `SourceFaceRecord::vertices` row while `SourceFaceTopologyKey::make` canonicalizes topology identity. `field_boundary_point_barycentric` and `source_vertex_barycentric` therefore publish tuples in the raw oriented row basis used by `vertex_locus_secondary_parameter`.

The terminal-contact branch is different: its authoritative contact tuple is stored in canonical `SourceFaceTopologyKey` order. R3 now maps each canonical component back by source-vertex identity into the raw oriented `SourceFaceRecord::vertices` basis before returning the second point. The mapping is local to the terminal-contact branch and preserves the other branches' already-correct basis.

The replacement row400 is independently discriminating. On `make_four_triangle_fan()` row 3:

```text
raw source row        = [3,0,4]
canonical key         = [0,3,4]
canonical weights     = [1/6,1/3,1/2]
locus                  = 4
correct raw-basis rank = 1/3
wrong positional rank  = 2/3
```

The values are exact and unequal. Removing the remap makes the replacement identity fail for the intended semantic reason; the test does not derive its oracle from production output.

## 3. Packaged-test contract finding

The R3 semantic/test replacement changed the required row400 identity but did not update the build-time packaged-test contract in `cmake/DirectionalTests.cmake`. That contract is not a second semantic test oracle: it is a packaging ownership guard that requires a named identity to exist exactly once in the expected default packaged source.

Current static facts are:

- retired identity source definitions: **0**;
- replacement identity source definitions: **1**;
- replacement identity source: `tests/FieldAlignedCurveNetworkTests.cpp`;
- that file remains in `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES`;
- replacement row400 remains producer-owned in the 403-row selector;
- owner totals remain **30 / 257 / 75 / 41**.

Therefore replacing only the stale CMake identity string with the replacement identity preserves and strengthens the same required-green ownership check. It does not weaken selector authority, change test semantics, or broaden the production correction.

**New non-stable finding:** `M4-CP3-CB4-R3-REV-CAND-01` — **BUILD-CONTRACT / MANDATORY PACKAGED-TEST IDENTITY DRIFT / NON-STABLE / SOURCE-PROVED**.

**Falsifier:** before correction, configure finds zero definitions for the retired required identity; after the one-name correction, configure must find exactly one definition for the replacement identity in `tests/FieldAlignedCurveNetworkTests.cpp`. Any need to change another packaged identity, target ownership, selector row, test source or product source invalidates the bounded correction and returns to Review.

This is an existing defect pattern, not a new lesson class: `LESSONS.md` 49 already requires literal build-contract markers and typed consumers to migrate in the same cutover.

## 4. Challenge to the prior diagnosis

The prior STOP-GUARD classification is upheld. The configure failure does **not** falsify the R3 product correction; it exposes one derivative dependency omitted from the frozen scope. Reverting the replacement test name or restoring the old decorative row400 would be the wrong repair because it would recover configure by weakening the actual non-vacuous regression.

A broader CMake refactor is also unnecessary. The smallest sufficient correction is one exact identity replacement in the existing `directional_require_default_packaged_test_contract(...)` call.

## 5. Decision

**`approved_with_amendments`**.

- R3's terminal-contact basis correction is approved as the preserved source-proved semantic correction.
- The replacement row400 regression and R3 selector403 lineage are approved as static candidate authority only; no runtime acceptance is inferred.
- R3 remains non-green because it produced no package.
- The successor is amended to include exactly one derivative build-contract identity replacement and then repeat compile/package under the normal Code + Build boundary.

Package119/selector394 remains accepted **394/394**. Package120/historical old selector403 remains mechanically **403/403** but unpromoted. The R3 selector403 remains unpromoted. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt remains **5**, CP3 remains open and A3->A4 cutover remains unauthorized.

## 6. Prior obligations

- `M4-CP3-CB4-R2-REV-CAND-01`: **implemented in source, compile-blocked, runtime-unproved**; carried through R4 until a green package and later artifact-only proof.
- `M4-CP3-TB2-REV-CAND-01`: **carried**; replacement row400 is now independently discriminating, but runtime acceptance remains outstanding.
- `M4-CP3-TB1-R1-REV-OBS-01`: **carried unchanged**; multiplicity weighting remains outside this correction.
- `M4-CP3-CB4-REV-OBS-02`: **carried unchanged**; row399 path/`sourceFaces` consistency tamper remains outside this correction.
- `M4-CP3-CB4-R3-REV-CAND-01`: **new non-stable build-contract finding**, corrective owner `M4-CP3-CB4-R4`.

No obligation is silently discharged.

## 7. Authoritative next Code + Build plan

Exactly one successor is frozen: **`M4-CP3-CB4-R4`**, governed by
`Architecture_M4_CP3_CB4_R4_Code_Build_Plan.md`.

Its semantic mutation is restricted to one build-configuration identity replacement in
`cmake/DirectionalTests.cmake`. Product source, test source, selector files and accepted authority are frozen.
It must compile changed-owner preflight and then the full selector-owner package through the mandatory reusable GitHub workflow with GMP/GMPXX and `runtimeExecution=false`. Any second semantic/build dependency is a STOP-GUARD back to Review.

If R4 packages green, future artifact-only `M4-CP3-TB2-R2-EXEC` remains exactly **799 fresh processes**: replacement row400 twice, accepted selector394 **394/394**, and successor selector403 **403/403**, followed by review before promotion.

## 8. Risks and merge implications

This review authorizes no promotion and no A3->A4 cutover. The CMake correction is derivative ownership metadata for packaging, but it is still build configuration and therefore belongs in a fresh Code + Build turn rather than being smuggled into this Review. PR #8 remains draft and unmerged.

## 9. Integrity confirmation

- Production code changed: **no**
- Test/fixture/benchmark logic changed: **no**
- Selector authority changed: **no**
- Build configuration changed: **no**
- Tests/benchmarks/Directional runtime executed: **no**
- Compile executed: **no**

## 11. Independent verification addendum (reviewing agent)

Runtime-free. The review is **upheld**. The semantic correction is right, the replacement identity is
genuinely discriminating, and the successor is correctly bounded. Accepted authority remains
package119 / selector394 **394/394**; accounting stays **47 / 14 / 33**, debt **5**. Two additions: one
reclassification and one operational fact the record does not state.

### V1 — the correction is right, and in the right direction

`vertex_trace_ray_second_point`'s other branches all return arrays in **raw oriented** `face.vertices`
order, so the terminal-contact branch returning a canonical-key-ordered tuple was the outlier. The patch
remaps by source-vertex identity into oriented order, rejects duplicate or unmatched corners, and returns
`std::nullopt` rather than a partially filled array — failing closed, consistent with the project's typed
failure commitment. It corrects the outlier rather than changing the contract its consumers rely on.

### V2 — the replacement identity discharges the surviving `TB2-REV` constraint

Re-derived independently. `make_four_triangle_fan()` raw row 3 is `[3,0,4]`; its key sorts to `[0,3,4]`.
With canonical weights `[1/6, 1/3, 1/2]`, the vertex-4 ray's opposite-edge parameter is
`w(v0) / (w(v3) + w(v0)) = (1/6)/(1/2) = 1/3`. Treating the canonical tuple as raw-row ordered exchanges
the `v3` and `v0` components, giving `(1/3)/(1/2) = 2/3`.

The identity asserts `EXPECT_EQ(1/3, *parameter)` and `EXPECT_NE(2/3, *parameter)`, pins **both** orderings
as fixture preconditions (`mesh.F(3,·)` is `3,0,4`; `face.vertices()` is `0,3,4`), and never touches
`exact_source_point_is_canonical`. It therefore goes RED if the remap is replaced by the identity function,
which is exactly the surviving constraint from the `M4-CP3-TB2-REV` addendum after its second constraint
was withdrawn. Pinning the fixture orderings also prevents the silent re-aiming that made the original
row400 vacuous.

### V3 — the compile stop is an unsatisfiable plan, not an omitted dependency

§4 describes the configure failure as "one derivative dependency omitted from the R3 plan". The stronger
and more useful classification is that **the plan could not be satisfied as written**. Per the guard
record, R3 §2 *explicitly excluded build configuration* while §5 *mandated replacing row400* — and
`cmake/DirectionalTests.cmake:268` hard-codes that identity name in
`directional_require_default_packaged_test_contract`, whose check at `:114` raises `FATAL_ERROR` unless
exactly one source definition exists. An active prohibition collided with an active mandate.

The distinction changes what prevents recurrence. "Omission" implies a planner should have listed one more
file; unsatisfiability implies a structural rule: **replacing a registered identity is atomically coupled
to updating its registry**, and a plan that mandates the replacement while forbidding the registry edit is
contradictory no matter how carefully it is written. This is the same class as the `M4-CP1-CB4` block —
two mutually exclusive requirements in one frozen scope — and naming it that way lets future plans
authorize the coupled edit up front instead of spending a turn discovering it.

### V4 — the working branch is currently unconfigurable, which §8 does not say

Verified at HEAD: the old identity has **0** definitions under `tests/`, while
`cmake/DirectionalTests.cmake` still lists it **once**. The mandatory contract therefore fails
`FATAL_ERROR` at configure, so the branch as it stands cannot configure at all.

Two consequences worth recording alongside §8's risk note:

1. `M4-CP3-CB4-R4` is **unblocking, not merely next**. No turn that needs to configure — any Code + Build,
   any packaging step — can run until it lands.
2. This also confirms V3 from the other direction: the identity replacement and the registry update could
   never have been split across turns even in principle, because the intermediate state is un-buildable.
   That intermediate state is the one the branch currently occupies.

Neither point changes the decision or the successor's scope, which is already correctly limited to one
identity name in one build file.

### V5 — obligations

§6 names all five outstanding items by id with a disposition and states that none is silently discharged.
That is full `REVIEW_TURN_POLICY.md` §2.5 compliance and the strongest obligation ledger in this sequence
so far.

## 10. Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | R3 selector403 first394 = accepted selector394 = `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`; full R3 selector403 = `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` |
| Decisive claims independently re-derived | terminal-contact canonical->raw basis conversion, replacement `1/3` vs `2/3` falsifier, compile failure locus, and one-name CMake ownership correction all re-derived from primary source/evidence |
| Non-vacuity checked | all three weights are distinct; raw `[3,0,4]` differs from canonical `[0,3,4]`; replacement test is the sole row400 identity and is producer-owned |
| Prior obligations discharged/carried | R2 product candidate + TB2 test-authority candidate carried to runtime proof; `OBS-01` and `OBS-02` carried unchanged; new build-contract candidate assigned to R4 |
| Stable accounting | `47 / 14 / 33`, debt `5`; package119/selector394 remains accepted `394/394` |
| New candidates/obligations recorded | `M4-CP3-CB4-R3-REV-CAND-01`; tracker updated |
| ORIENTATION currency line | `M4-CP3-CB4-R3-REV`, 2026-09-12 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged because no witness runtime state changed; §8 records the stale packaged-test identity as another instance of existing lesson 49 |
| CHANGELOG | review entry added |
| ROADMAP | CP3 state and R4 successor updated |
| Selector manifest | unchanged by design: Review added/accepted no selector; existing R3 candidate receipt remains authoritative |
| LESSONS | no new numbered lesson; existing lesson 49 exactly covers literal build-contract marker drift |
| Consolidation under CLEAN_UP_POLICY | M4 consolidated record updated with R2/R3/Review disposition; no evidence-bearing document deleted because current review still cites the R3 guard/plan and predecessor diagnosis |
| Successor frozen | `M4-CP3-CB4-R4`; one-name build-contract correction only |
| Turn boundary held | runtime-free planning/docs only; no product/test/fixture/selector/build mutation |
| review_check.py boundary | **ALL CHECKS PASSED** on the verified snapshot-local working tree; no product/test/fixture/build or selector mutation; durable markers preserved |
| Pushed to origin, branch in sync | publication/cleanup confirmation action required after patch apply; final PR summary records the verified remote head |
