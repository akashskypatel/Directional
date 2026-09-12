# M4-CP3-TB3 Review Record — row408 reachability adjudication

**Turn:** `M4-CP3-TB3-REV`
**Status:** COMPLETE / CANDIDATE REJECTED / TEST-AUTHORITY FIXTURE-PRECONDITION DEFECT / NON-STABLE
**Reviewed EXEC:** `34671972132 / 103494923768`
**Reviewed package:** `10290933668` at semantic source `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`
**Accepted authority retained:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`

## 1. Decision

**Reject promotion of CB5 package `10290933668` and selector408.** The authoritative TB3 execution is mechanically valid and immutable, but row408 is a false acceptance gate for the intended exact-torus hard-rail cutover because its fixture does not construct any hard-feature rail authority. It therefore cannot reach the A3-owned shared hard-rail boundary seam it claims to test.

This is `M4-CP3-TB3-REV-CAND-01`:

> **TEST-AUTHORITY / FIXTURE-PRECONDITION + REACHABILITY DRIFT / INCORRECT EXPECTATION / NON-STABLE.**

No accepted runtime behavior is shown lost. Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**. `G4-B002` and CP3 remain open.

## 2. Raw evidence independently re-opened

TB3 authoritative artifacts were reopened independently:

```text
run / job             = 34671972132 / 103494923768
result artifact / SHA = 10291076362 / 56158d759bf7827e33a51ce04fcd67bba960f68fea7486893fdf14936d96f388
log artifact / SHA    = 10291146242 / 93d56c5c8fc76f4d9ab1210183ce6aa57ecab25479f01b3e31b5ec78c33de5b1
```

Preflight and immutable postflight are green. Focused-A rows404-407 pass. Row408 alone is RED, with exactly one selected test, zero skips/timeouts, and failure at the first phase-front production assertion. Focused-B, selector403 and selector408 were correctly not executed after fail-fast, so no predecessor/cumulative promotion evidence exists for this candidate package.

The first attempt `34671851965 / 103494592879` is separately classified **ORCHESTRATION-ONLY / PRE-RUNTIME / NON-STABLE**: it ran zero Directional identities and failed only an over-specific temporary executor source-string proof. The retry changed no package/source/test/selector bytes.

## 3. Why row408 does not exercise the frozen subject

### 3.1 Its options do not declare a hard feature

`build_cp4c_pipeline_products_fixture("torus", "torus")` calls `cp4c_remesh_options()`. That helper enables SurfaceCells and retained intermediates but supplies **no** `surfaceCells.featureMap.userHardEdges` and no other explicit hard-feature override.

Production builds `hardFeatureRailEdges` only from `build_authoritative_surface_cell_rails(featureMap)` and then assigns that set directly to `SurfaceCellTracingOptions::hardFeatureEdges`.

### 3.2 The observed `NotApplicable` disposition proves the hard-rail precondition is absent on this run

`SurfaceCellTracingOptions::enableUniformPhaseFront` defaults true and the fixture does not disable it. In `build_uniform_phase_front_state(...)`, after the uniform, periodic-annulus and curved bounded-disk regional producers all return `NotApplicable`, the aggregate producer returns `NotApplicable` only on the ordinary no-hard-feature path:

```text
if (!anyProduced && options.hardFeatureEdges.empty()) return result;
```

If hard-feature authority were present at that same unsupported point, the producer would instead publish a typed rejection (`UnsupportedSourceSheetTopology`) rather than `NotApplicable`.

TB3 row408 observed exactly `phaseFront.disposition() == NotApplicable`. Therefore the row408 execution did **not** carry the hard-feature rail authority required by the frozen A3→A4 shared-boundary cutover.

### 3.3 Its later assertions are unreachable under its own precondition

Row408 immediately requires `phaseFront.disposition() == Produced`, then intends to inspect the conformity receipt, require every `HardRail` edge to carry `sharedBoundaryInterval`, and require at least one such interval. Because the fixture supplies no hard-feature rails and the authoritative phase-front chain returns `NotApplicable`, those exact shared-boundary assertions never execute.

The RED therefore does not discriminate between:

- correct versus incorrect A3 span/ordinal consumption;
- exact typed pairing versus the retired floating `support_key` authority;
- removal versus persistence of `InvalidHardRailPairing` on a hard-rail torus path.

It only proves the current row408 fixture does not reach its claimed subject.

## 4. Frozen reachability statement corrected, semantic objective retained

`Architecture_M4_DEFN_Frozen_Definitions.md` §10 described the exact torus as already reaching regional phase-front aggregation and the historical `InvalidHardRailPairing` seam. That historical reachability premise is stale for the current `cp4c_remesh_options()` fixture path used by row408: the current run carries no hard-feature rail authority and returns authoritative phase-front `NotApplicable`.

This review does **not** weaken or replace the semantic requirement. CP3 still owes a production torus witness that actually carries shared hard-rail authority and proves the A3-owned span/ordinal identity removes the post-hoc pairing blocker. The correction is to the witness precondition/reachability, not to A3/A4 semantics.

## 5. Product adjudication

Rows404-407 provide fresh positive evidence that the CB5 cutover compiles into runnable behavior for its direct/rectangular hard-rail subjects: production receipt publication, fixed-plan target perturbation invariance, exact negative/tamper rejection, and A4-local frame preservation all pass.

However, Review cannot promote CB5 because:

1. row408 does not exercise the required torus hard-rail seam;
2. the frozen focused-B repeat was not reached;
3. accepted selector403 was not re-executed on the candidate package;
4. candidate selector408 was not executed cumulatively.

There is therefore no accepted-green loss to price and no runtime basis to classify a CB5 product regression. The product cutover remains **compile-valid + partially runtime-proved, not accepted**.

## 6. Corrective mechanism

The bounded correction is **test-authority only**. `M4-CP3-CB6` must repair row408's fixture precondition without changing production semantics, accepted selector403, the four green rows404-407, or the candidate identity count.

The committed torus is an explicit 12×6 triangulated genus-1 grid. Two deterministic source-edge fundamental cycles are statically available and intersect at source vertex 0:

```text
minor/meridian cycle, 0-based vertices:
0-3-25-37-49-61-0

major/longitude cycle, 0-based vertices:
0-1-4-6-8-10-12-14-16-18-20-22-0
```

Every listed pair is an actual committed source edge. The cycles are respectively constant major angle and constant minor coordinate, represent independent torus generators, and their union is the canonical cut-graph shape whose complement is a disc. CB6 may use these edges as explicit `userHardEdges` for the row408 production fixture so hard-rail authority is part of the input instead of relying on adaptive organic classification.

This geometric/topological list is a **plan input**, not runtime acceptance. CB6 must independently re-check the edge/cycle precondition statically from the committed OBJ before changing the test. If the existing production feature/rail pipeline cannot carry that explicit hard-feature input to the intended A3→A4 seam without product changes, CB6 must STOP and return to Review rather than widen scope.

## 7. Candidate disposition and accounting

- `M4-CP3-TB3-REV-CAND-01`: **OPEN correction owner `M4-CP3-CB6`; non-stable test-authority candidate.**
- CB5 artifact `10290933668` / selector408: **REJECTED FOR PROMOTION / retained evidence only**.
- Corrected R4 artifact `10289601000` / selector403: **accepted authority remains unchanged**.
- `G4-B002`: **OPEN**.
- CP3: **OPEN**.
- Stable totals: **47 / 14 / 33**.
- Produced-witness debt: **5**.

## 8. Review-policy closeout

- `ORIENTATION.md` is updated in this review: currency, §3 current state, torus witness state, §7 priority list, and §8 recurring pattern.
- `Regression_Root_Cause_Tracker.md`, `M4_Consolidated_Record.md`, `ROADMAP.md`, `TODO.md`, `CHANGELOG.md`, and the live handoff are updated to the same disposition.
- No product/test/fixture/selector/build source was modified in Review.
- No Directional runtime, configure, compile, relink, discovery/listing, benchmark or package repair occurred in Review.
- Temporary TB3 executor/marker are cleanup-only controls and are retired before closeout.

**Exact successor:** runtime-free `M4-CP3-CB6` under `Architecture_M4_CP3_CB6_Code_Build_Plan.md`. Per turn-boundary policy, Review/Plan stops before that Code + Build turn.
