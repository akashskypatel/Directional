# M5-CP3-CB9 Produced-Witness Authority Correction Plan

**Turn:** `M5-CP3-CB9`
**Boundary:** **Code + Build only / runtime-free / test-authority-only**
**Owner:** `M5-CP3-TB1-R7-REV`
**Exact successor if compile/package green:** `M5-CP3-TB1-R8-EXEC`

## 1. Goal

Repair only the three invalid/unproved CP3 produced-witness prerequisites exposed by R7 so the next immutable
runtime can distinguish a test-authority problem from a real production-direction defect.

The production implementation is **not** authorized to change in CB9. The one permitted semantic source path is:

- `tests/SurfaceCellTransitionQuotientTests.cpp`

Do not modify `src/**`, public headers, committed `.obj/.rawfield` fixtures, selector files, CMake target
membership, frozen definitions, routing authority, accepted tests outside the exact CP3 witness helpers/bodies, or
benchmark semantics.

## 2. Entering evidence

R7 candidate `10651055588` / source `baae6307d189639fdf7d8a0011f5ba5f30de1631` executes the full 446-process
gate at **9/9 mechanism, 1/1 focused atlas, 3/6 produced, selector430 430/430**. The generator-route failure is
gone and accepted ordinal408 is green.

Review proves:

- the committed torus/rawfield has matching/Z4 **0 on all 216 source edges**, including all 18 row408 hard edges;
- rows4/5 therefore cannot prove the frozen genuine-nonzero-Z4 precondition;
- row6's “unused” swapped relation ID is already present in the produced table;
- `M5-CP3-TB1-R6-REV-OBS-01` remains open because the current zero-Z4 subject cannot distinguish forward from
  inverse directed transition value.

Two M5 debts are already discharged (produced relation owner/reorder and missing owner). The two nonzero-Z4 M5
debts remain open. Project debt is **3** including the separate M6 debt.

## 3. Goal A — author a deterministic nonzero-Z4 torus source witness

Add a test-local raw-cross-field builder over the **existing committed torus geometry**. Do not edit or replace
`torus.rawfield`.

Required construction properties:

1. Build each face's tangent frame from committed geometry, using the face centroid's torus major angle and the
   actual oriented face normal. The base directions must be tangent, normalized, consistently handed and
   deterministic.
2. Apply a known quarter-winding to that base frame (the cylindrical `windingField` helper is an implementation
   precedent, not authority). The winding must be authored from source geometry, not from any product relation or
   failure result.
3. Finalize the raw field through the normal cross-field finalizer. Before building the phase-front product,
   independently inspect the finalized **source transition authority** and prove at least one exact hard-edge
   generator carrier used by the row408-class cut graph has nonzero quarter-turn matching.
4. Require the chosen carrier/occurrence pair to be selected by source/A3 identity before product relation-table
   inspection. A search over `product.periodicHolonomies()` for “whatever nonzero action exists” is prohibited as
   the witness oracle.
5. Retain the same committed torus topology and exact row408 18-edge hard-feature authority. The helper must fail
   closed if the source field is not `Produced` or if no independently selected hard-edge transition is nonzero.

### Verification before leaving Goal A

Static/test-source assertions must make all preconditions observable: source edge identity, the two exact source
faces, directed quarter-turn value, nonzero value, and the A3 boundary occurrences that own those faces. The
Code+Build turn may compile these assertions but must not execute them.

**Stop rule:** if a genuine nonzero transition cannot be authored and proved from source authority without
consulting product relation output, stop CB9. Do not mutate production to manufacture one and do not weaken the
frozen `G4-B003` requirement.

## 4. Goal B — turn the R6 direction observation into a runtime falsifier

For the preselected nonzero carrier, derive the expected **directed** transition independently from:

- canonical A3 source-path parameter orientation;
- exact accepted `SurfaceBoundaryOccurrenceId` ownership;
- accepted occurrence `sourceFace` on each side;
- finalized source transition value for that exact directed face pair.

Do not infer direction from `sourceEdgeFaces` storage order, product relation action, or which reciprocal edge is
stored first. Carrier incidence is only a membership check.

The produced witness must expose enough exact identity to compare the resulting periodic relation's generator
rotation with this pre-product expected direction. The inverse direction must be distinguishable because the
source value is nonzero.

**R8 falsifier:** if product publication uses the inverse directed transition, the exact CP3 produced test must be
RED. Do not compensate in the test by accepting either direction.

**Stop rule:** CB9 is not authorized to edit `SurfaceCellTracing.cpp` if static inspection suggests an inversion.
Compile the discriminating test and let R8 determine whether production is actually wrong; mandatory R8 Review
owns any later product correction.

## 5. Goal C — repair rows 4 and 5 without weakening their frozen debts

### Row 4 — `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`

Use the Goal-A witness and Goal-B source oracle. The row must prove all of the following before it earns credit:

- source/A3 authority selected a genuine nonzero directed Z4 transition;
- production publishes the corresponding stable semantic relation (not merely any nonzero relation);
- the published action agrees with the independently derived direction;
- rotation is nonzero and translation is nonzero;
- materialization succeeds;
- a selected relation-path certificate actually consumes that exact relation/action (or its semantically required
  reciprocal representation where the certificate contract explicitly permits it);
- `consumedPeriodicHolonomies > 0`.

No product-table search may define the expected relation.

### Row 5 — `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`

Reuse the exact same independently selected produced relation. Change **only** its action value while preserving
its stable semantic relation ID and carrier paths. Prove the action actually changed and the ID did not. Checked
phase-front construction must reject with exact typed `NonReciprocalPeriodicRelation`.

The row must reach the tamper. A missing relation before tamper is RED, not a skip or acceptable alternate.

## 6. Goal D — construct a genuinely unused valid relation for row 6

Replace the assumption that swapping the first owner is unused.

Construct one deterministic valid relation from source/product-domain facts that are **not referenced by any
periodic edge or selected certificate**. Prefer a canonical route pair built from an independently chosen interior
source transition/carrier outside the produced periodic-owner carrier set. Before insertion, assert all of:

1. factory construction succeeds and yields a stable semantic ID;
2. that ID is absent from the produced relation table;
3. no phase-front edge owns that ID;
4. no baseline selected certificate references that ID.

Only then append the relation, permute relation storage, and prove:

- phase-front product construction remains valid;
- materialization succeeds for baseline and extended drafts;
- selected relation certificate signatures are identical;
- completion hashes are identical;
- consumed periodic-holonomy counts are identical;
- the added ID remains unselected/unconsumed.

**Stop rule:** if no valid independently unused relation can be constructed without changing frozen relation
semantics, stop. Do not weaken §7, remove the absence precondition, or redefine “unused” as “duplicate already in
the table.”

## 7. Scope guard and surgical-change rules

Permitted changes are limited to the smallest test-local helper/assertion edits needed for Goals A–D. Reuse the
existing torus fixture loading, row408 hard-edge cycles, field finalizer and independent relation/carrier helpers
where they are semantically correct. Do not refactor unrelated tests.

Explicitly prohibited in CB9:

- product/source implementation edits;
- public API/header edits;
- committed fixture-byte edits;
- selector430 or any selector-manifest edit;
- CMake/test-owner changes;
- changing existing accepted identity expectations;
- changing `PeriodicRelationId`, relation factory, atlas barrier semantics or §14/§15 authority;
- runtime execution, `ctest`, test discovery/listing, benchmark execution, or any generated Directional binary.

If implementation requires any prohibited change, stop and return to Review rather than widening scope.

## 8. Code + Build verification

After the test-only patch is statically complete:

1. run normal source/static checks and `git diff --check`;
2. compile/package, with mandatory GMP/GMPXX, all eight standard targets through the durable compile workflow:
   `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`,
   `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`,
   `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`;
3. require the package's source archive, build logs, GMP evidence, clean source status and recursive manifest;
4. require `runtimeExecution=false` and zero generated test/benchmark execution.

A compile failure may be corrected in the same CB9 turn only when the change stays inside the exact test-only
scope above. No runtime-derived semantic adjustment is available in Code + Build.

## 9. Frozen next runtime gate — `M5-CP3-TB1-R8-EXEC`

If CB9 packages green, R8 must consume the exact candidate artifact immutably and execute the same **446**
processes:

- nine reviewed mechanism identities;
- one focused retained-value atlas control;
- the same six produced identities;
- selector430.

Mandatory success/falsifier conditions:

1. exact-one selection and zero skips for all 446 rows;
2. mechanism **9/9 PASS**;
3. focused atlas **1/1 PASS**;
4. produced **6/6 PASS**;
5. selector430 **430/430 PASS**;
6. rows4/5 demonstrate source-authoritative genuine nonzero-Z4 production and row5 reaches exact typed tamper
   rejection;
7. the independent directed-orientation oracle agrees with published product rotation; inverse direction is not
   accepted as equivalent;
8. row6 proves an actually absent/unowned/unselected valid relation and output/certificate invariance;
9. package/source/execution-view byte+mode censuses unchanged, candidate manifest unchanged, selector/routing
   hashes unchanged;
10. configure/compile/relink/generated-discovery/package-repair/mode-repair/input-mutation counters all zero and
    benchmark execution zero.

Any semantic RED goes directly to mandatory **`M5-CP3-TB1-R8-REV`**. R8 EXEC may not repair tests or production.
Only an independently all-green R8 Review may discharge the two remaining M5 nonzero-Z4 debts and pre-commit the
successor selector publication required by frozen §13.3.
