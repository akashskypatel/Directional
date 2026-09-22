# M5-CP3-CB14 Periodic-Seam Lattice-Gauge Authority Correction Plan

**Turn:** `M5-CP3-CB14`  
**Type:** **Code + Build / product-authority correction / runtime-free**  
**Owner:** `M5-CP3-TB1-R11-R1-CAND-01`  
**Entering candidate:** `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`  
**Required next after green compile/package:** fresh artifact-only `M5-CP3-TB1-R12-EXEC` -> mandatory Review

## 1. Goal

Correct the exact R11-R1 root proved by Review: same-region periodic relation construction uses the cut-open rectangular
cell-grid `LocalLatticeState::latticeCoordinate` directly as quotient-seam endpoint authority. On the accepted nonzero-Z4
row408 torus, reciprocal seam copies lie on opposite rectangle sides, so raw deltas satisfy `d2=-d1`; a nonzero quarter-turn
can never satisfy both raw endpoint mappings.

CB14 separates cell-grid placement from periodic relation endpoint-gauge authority without weakening any frozen M5
correspondence rule.

## 2. Pre-mutation derivation gate

Before semantic mutation, derive and record the exact relation-endpoint representation from existing authority.

The derivation must show that each same-region periodic endpoint state can be computed from **its own**:

- exact A3 `SurfaceSharedBoundaryInterval` and `boundaryOccurrence`;
- semantic Forward/Reverse occurrence role;
- source-chart identity and branch state;
- cut-domain integer lattice state;
- one exact directed generator transport `R`.

The derived state must be canonical under face-row, edge-storage, cell-storage and pair-insertion permutation. It must not use the
partner's desired endpoint, search an inverse, fit a translation, change A3 ordinals, rewrite an endpoint after a mismatch, or
inspect product output to choose a gauge.

If no such independently derived state can be expressed with current authority, **STOP BEFORE MUTATION** and route back to Review
with the missing authority named. Do not invent a new gauge convention.

## 3. Authorized implementation boundary

After the pre-mutation gate succeeds:

1. preserve ordinary cell `latticeCoordinate` values and all ordinary/interior edge ownership exactly;
2. introduce or expose the smallest typed **periodic relation endpoint lattice state** needed for same-region `PeriodicCut`
   correspondence;
3. derive that state before pair/action construction from the pre-mutation authority above;
4. make `periodic_action_for_pair` (or its replacement) use only those relation-owned endpoint states for exact action
   construction;
5. make the checked `SurfacePhaseFrontProduct` validator use the same explicit endpoint authority;
6. retain exact semantic Forward -> Reverse generator direction from CB12;
7. leave relation identity based on topology region + canonical generator route + cut route; do not introduce storage ordinals into
   identity.

Do not modify the field, torus fixture, A3 schedule, source topology, routing artifact, selector430, materializer debt
discriminators, or cross-region HardRail semantics.

## 4. Frozen correspondence contract

For relation-owned directed endpoint states, retain:

```text
d1 = first.to - first.from
d2 = second.to - second.from
R  = generatorRoute.composed_transport().rotation

rotate(R, d1) == -d2
R * first.from.branch == second.to.branch
R * first.to.branch   == second.from.branch
A(first.from) == second.to
A(first.to)   == second.from
```

where `A` is one exact integer `GridAutomorphism{R,t}`.

The endpoint-state derivation is authority; the action is a consumer. Therefore the implementation must not derive endpoint
coordinates by solving these equations against the partner. The equations validate the independently derived states.

For the accepted R11-R1 row4/5 subject, the pre-product authority must prove `R != 0`, `t != 0`, and both exact mappings before
relation publication. The existing row4/5 source/A3 oracle remains the independent direction/value oracle.

## 5. Preservation requirements

CB14 must preserve:

- all nine reviewed mechanism identities;
- focused atlas identity;
- all six produced identity names and discriminators;
- selector430 bytes and first427 prefix;
- rows1/2/3/6 behavior;
- protected selector ordinals 191/192/247/408;
- CP2 typed failure matrix;
- zero-rotation same-region behavior;
- cross-region HardRail local family/sign behavior;
- exact A3 Forward -> Reverse direction;
- source/package immutability contracts for the following TB.

If relation-endpoint gauge normalization changes a zero-rotation serialized transform merely by a representation conjugation, do
not normalize that away silently. Either prove the stored action is already in the newly frozen canonical gauge and update the
independent oracle in the same semantic domain, or stop for Review. Existing accepted semantics may not drift incidentally.

## 6. Tests and compile verification

Implementation tests must include bounded non-runtime checks that make the corrected authority falsifiable:

- a pure correspondence test where independently authored endpoint states satisfy a genuine nonzero `R` and nonzero translation;
- changing only one endpoint/gauge input must fail exact correspondence;
- swapping pair storage order must not change the semantic Forward -> Reverse relation;
- an inverse-direction or partner-fitted construction must not be accepted as an alternative;
- zero-rotation behavior remains semantically identical;
- checked-product validation and producer construction agree on the same relation-endpoint authority.

Use existing identities where they already cover these facts; add only the smallest focused helper/authority tests needed to expose
the new representation. Do not weaken rows4/5 or selector430.

Compile/package the exact semantic source through the repository GitHub workflow with mandatory GMP/GMPXX linkage. Require all
eight established targets green, clean source receipts, root manifest completeness and `runtimeExecution=false`.
Do not run Directional tests or benchmarks in CB14.

## 7. Fresh runtime freeze after green CB14

After green compile/package, freeze `M5-CP3-TB1-R12-EXEC` against that exact candidate:

- **446 existing fresh exact-filter processes** in the same order:
  9 mechanism + 1 focused + 6 produced + selector430 430;
- exact-one selection, zero skips;
- benchmark **0**;
- immutable package/source/execution-view postflight;
- complete post-copy result self-manifest;
- no configure/compile/relink/discovery/repair/mutation in TB.

Primary falsifier: produced row4 must progress beyond `PeriodicActionCorrespondenceMismatch` and prove genuine nonzero
rotation+translation through selected-certificate/materialization consumption. Row5 must reach its transform-only tamper and reject
typed `NonReciprocalPeriodicRelation`. Rows1/2/3/6 and selector430 must remain green.

Any mechanically complete R12 routes to mandatory Review. No candidate promotion, debt discharge or selector publication occurs
in CB14 or R12 EXEC.
