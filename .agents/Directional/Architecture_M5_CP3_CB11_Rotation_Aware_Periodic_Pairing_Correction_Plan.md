# M5-CP3-CB11 Rotation-Aware Same-Region Periodic Pairing Correction Plan

**Turn:** `M5-CP3-CB11`
**Boundary:** **Code + Build only / runtime-free / product-only**
**Owner:** `M5-CP3-TB1-R9-REV`
**Exact successor if compile/package green:** `M5-CP3-TB1-R10-EXEC`

## 1. Goal

Repair the exact same-region periodic-pairing contract inconsistency proved by R9 Review without changing the authoritative generator route, exact action correspondence, tests, fixtures, selector, routing authority, or cross-region HardRail semantics.

Current code compares chart-local `family` / `advanceSign` directly across same-region cut copies before the periodic generator rotation is known. Combined with exact reciprocal endpoint mapping, that raw comparison mathematically permits only Z4 rotation zero. M5 debts 3/4 require genuine nonzero Z4, so the current path is structurally unreachable.

CB11 makes one bounded product correction: **same-region periodic seam compatibility is judged in transported lattice coordinates under the exact directed generator rotation, not by comparing untransported local family/sign labels.**

## 2. Authorized semantic scope

Only this production source path may change semantically:

```text
src/geometry/SurfaceCellTracing.cpp
```

No semantic change is authorized to:

- public headers or API;
- `tests/**` or committed fixtures;
- `FieldTransportAtlas` semantics or hard-feature traversability;
- `GlobalTopologyPlan`, A3 interval/source-face authority or generator carrier selection;
- `SurfacePeriodicHolonomy`, `PeriodicRelationId`, materialization or verifier semantics;
- selector430, routing identity map or any selector manifest;
- CMake/build ownership;
- benchmark semantics;
- any M6 authority.

`Architecture_M5_Frozen_Definitions.md` §16 is already frozen by R9 Review and is not a CB11 edit target except a purely mechanical citation correction if absolutely necessary; semantic redefinition in CB11 is prohibited.

## 3. Exact correction

### 3.1 Preserve common hard-rail pairing authority

Keep all existing pair identity and provenance checks:

- exactly two edges per `HardRailPairKey`;
- valid exact reciprocal `SurfaceSharedBoundaryInterval` values;
- same span and opposite interval orientation;
- distinct exact `boundaryOccurrence` values for same-region promotion;
- canonical reverse routes;
- compatible optional `railId`;
- exact `oppositeEdge` publication only after structural pairing succeeds.

Do not broaden grouping keys, use floating support, invent an ordinal fallback, or reconstruct source authority.

### 3.2 Cross-region HardRail remains unchanged

For `first.sourceTopologyRegion != second.sourceTopologyRegion`, retain the current local-chart reciprocity requirement exactly:

```text
first.family == second.family
first.advanceSign == -second.advanceSign
```

Cross-region pairs remain `HardRail`; they do not publish a periodic relation. Any existing cross-region failure remains `InvalidHardRailPairing`.

### 3.3 Same-region periodic promotion becomes rotation-aware

For a same-region pair, do **not** reject solely because the two untransported local `family` values differ or their raw `advanceSign` values fail the zero-rotation pattern.

Instead:

1. resolve the exact directed generator route from the A3 span and the two exact boundary occurrences using the existing `generator_route_for_span(...)` path unchanged;
2. take exactly `generatorRotation = generatorRoute.composed_transport().rotation` in that directed orientation;
3. retain the existing `periodic_action_for_pair(first, second, generatorRotation)` as the authoritative endpoint/branch-state correspondence gate;
4. equivalently, the exact directed lattice deltas must satisfy

   ```text
   rotate(generatorRotation,
          first.toLattice.latticeCoordinate - first.fromLattice.latticeCoordinate)
     == second.fromLattice.latticeCoordinate - second.toLattice.latticeCoordinate
   ```

   before one action can satisfy both endpoint mappings;
5. do not try the inverse generator rotation, swap occurrence direction, search rotations, alter endpoints, or fit a translation. One directed route produces one rotation and one exact action candidate.

The existing exact branch-rotation conditions and both `GridAutomorphism::apply(...)` endpoint checks remain mandatory. `PeriodicActionCorrespondenceMismatch` continues to own a true same-region action/correspondence failure.

### 3.4 Preserve checked relation creation

After correspondence succeeds, preserve the existing `SurfacePeriodicHolonomy::make(...)` call and exact mappings from its error codes. Preserve relation identity derived from exact generator/cut carrier content. Do not weaken zero-translation, missing-route, missing-cut-route, invalid-ID, duplicate/conflict, reciprocity, representation-renumbering or selected-certificate validation.

## 4. Static falsifiers before compile

Before any build workflow is triggered, source review must establish all of the following:

1. the early hard-rail validation still applies raw family/sign reciprocity to cross-region pairs;
2. the same-region path no longer applies raw family/sign equality/opposition as a pre-rotation veto;
3. same-region promotion still requires exact distinct boundary occurrences, reciprocal intervals and reverse routes;
4. `generator_route_for_span(...)` is byte/semantically unchanged except unavoidable mechanical refactoring;
5. the directed `generatorRotation` is passed unchanged into `periodic_action_for_pair(...)`;
6. no inverse-direction retry or best-of-two rotation appears;
7. `periodic_action_for_pair(...)` still checks both branch rotations, computes one integer shift and checks both endpoint applications exactly;
8. checked `SurfacePeriodicHolonomy::make(...)` and its typed failures are unchanged;
9. no test, fixture, selector, routing, header, build or benchmark semantic byte changes occur.

If satisfying the correction requires a second semantic product domain, a test rewrite, a new relation representation, a selector edit or any weakening of exact action correspondence, stop and route back to Review instead of expanding CB11.

## 5. Mandatory compile/package

Use the standard GitHub Actions compile/package path. Do not compile locally and do not execute a Directional runtime in CB11.

The exact semantic source must receive:

1. preflight compile of the directly affected production/test-owner target under the standing workflow policy;
2. mandatory all-eight GMP/GMPXX compile/package:
   - `directional_core`
   - `directional_pipeline`
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
   - `directional_compiled_api_tests`
   - `directional_benchmarks`
3. explicit `runtimeExecution=false` and exact semantic source SHA receipts;
4. clean source status before/after configure/build;
5. mode-preserving candidate package and complete self-manifest;
6. explicit GMPXX + GMP linkage evidence.

No `ctest`, gtest execution, benchmark, generated discovery/listing, CLI, help/version command or other Directional binary execution is allowed in CB11.

## 6. Exact R10 immutable runtime gate if compile green

If and only if compile/package is green, freeze a fresh `M5-CP3-TB1-R10-EXEC` against that exact artifact. Reuse the same accepted routing/selector authority and the same **446** fresh exact-filter processes as R9:

- 9 reviewed mechanism identities;
- 1 focused atlas identity;
- 6 produced torus identities;
- all 430 selector430 identities in exact accepted order;
- benchmark executions exactly 0.

No generated discovery chooses the identities. Require exact-one selection, zero skips and exact immutable pre/postflight.

### 6.1 Load-bearing rows4/5 outcomes

A full recovery requires produced row4 `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` to advance through:

- the already-reviewed CB10 source/chart oracle;
- successful real pipeline production;
- `select_torus_source_witness(...)`;
- exact directed source transition == exact directed atlas value in the chosen A3 occurrence orientation, with inverse direction **not** accepted as equivalent;
- produced relation retaining the independently derived generator route;
- genuinely nonzero Z4 rotation **and** nonzero translation;
- authoritative materialization success;
- selected relation-path certificate consuming that relation/action;
- `consumedPeriodicHolonomies > 0`.

Produced row5 `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` must select the same independently derived relation, change only its action while preserving semantic ID/carriers, prove the action changed, and reach exact checked `NonReciprocalPeriodicRelation`. Failure before the tamper is RED.

Row6 must remain PASS with its already recovery-proved absent/unowned/unselected preconditions and unchanged selected-certificate/completion/consumption invariants.

### 6.2 Complete required vector

A green candidate requires:

- mechanism **9/9 PASS**;
- focused atlas **1/1 PASS**;
- produced **6/6 PASS**;
- selector430 **430/430 PASS**;
- all **446/446** exact-one / zero skipped;
- protected selector ordinals 191/192/247/408 PASS;
- exact byte+mode postflight and root manifest;
- prohibited operation counters all zero;
- benchmark **0**.

Any mechanically complete R10, green or RED, routes to mandatory `M5-CP3-TB1-R10-REV`. EXEC may not repair, promote, discharge debt or precommit selector publication.

## 7. Authority and accounting entering CB11

Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Candidate `10668437359` is rejected for promotion and remains historical R9 evidence only.

Stable accounting remains **50 events / 14 categories / 36 recurrences**. Project produced-witness debt remains **3**: two M5 nonzero-Z4 debts and one M6 closed-complex debt.

- `M5-CP3-TB1-R7-CAND-02` is **CLOSED / RECOVERY PROVED / NON-STABLE** by R9 Review.
- `M5-CP3-TB1-R9-REV-CAND-01` is **OPEN / RP-01 AUTHORITY_DOMAIN_CONFLATION / owner CB11 -> R10 Review**.
- `M5-CP3-TB1-R8-REV-OBS-01` is **CLOSED / no-tuning + chart admissibility upheld**.
- `M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN / directed relation discriminator not reached**.
- `M5-CP2-TB1-REV-OBS-01` remains **OPEN / no selector-publication precommitment before independently green corrected Review**.

Selector publication remains prohibited throughout CB11 and R10 EXEC.
