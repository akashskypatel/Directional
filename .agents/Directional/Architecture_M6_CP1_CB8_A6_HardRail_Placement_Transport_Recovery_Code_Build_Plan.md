# M6-CP1-CB8-A6 HardRail Placement-Transport Recovery — Code + Build Plan

**Owner:** `M6-CP1-CB8-A6`
**Authorized by:** `M6-CP1-TB7-A6-REV`
**Turn type:** Code + Build only
**Runtime:** forbidden
**Successor if compile/package green:** `M6-CP1-TB8-A6-EXEC` -> mandatory `M6-CP1-TB8-A6-REV`

> **Review-agent amendment (2026-10-03, `M6-CP1-TB7-A6-REV` addendum §G2-§G7; normative RA-16). This block OVERRIDES §§1-7 below wherever they conflict.**
>
> **Revoked.**
> - §2.1's branch-derived helper.
> - §2.2's publication of the placement map in `equivalence.action` and in the selected step.
> - §2.3 entirely: `PureQuadCompletion.cpp` is **not** edited.
> - §4 entirely: selector446's body is **not** edited; it must PASS unchanged as the falsifier of the lineage regression.
> - §3's adapter-wide preflight.
> - §5's "focused count 11" and §7's "460".
>
> **Goal A — coordinate-rigid HardRail placement transport (RA-16 §1-2).** In the A5 HardRail branch, after the RA-15 route-validity check and the existing owner, region and reversed-route predicates:
> 1. Look up the endpoint occurrences' `placement.lattice` for the two pairs `first.from → second.to` and `first.to → second.from`. Use the `endpointPairs` occurrence ids, not `SurfaceFrontEdge::fromLattice`/`toLattice`.
> 2. Require all four `scaleLevel`s equal.
> 3. Compute `e = c(first.to) − c(first.from)` (must be nonzero) and `e' = c(second.from) − c(second.to)`.
> 4. Let `R` be the unique `QuarterTurn` with `rotate(R, e) == e'`. If none exists, fail `HardRailTransportMismatch`.
> 5. Set `t = c(second.to) − rotate(R, c(first.from))` and `T = {R, t}`. Assert that `T` maps both coordinate pairs.
> 6. Set `storageTransport = T`. The existing canonical inversion then produces `canonicalTransport`.
>
> Never compare `branchRotation` across the rail. Delete CB7's HardRail `action_matches` pair (`RemeshPipeline.cpp:4218-4225`). Keep `sharedEquivalence.action = first.route.composed_transport()` and `sharedEquivalence.route = first.route` unchanged.
>
> **Goal A2 — decouple the lineage relation value (RA-16 §3).**
> - Add `std::optional<authority::GridAutomorphism> canonicalRelationValue` to `SurfaceOccurrenceRelationEvidence`, in canonical direction, with the same `storageIsCanonical` inversion as `canonicalTransport`:
>   - OrdinaryFront: identity;
>   - HardRail: `first.route.composed_transport()`;
>   - exact-A3 Periodic: `firstIsForward ? g : g⁻¹`, i.e. the pre-CB7 `a532f803` expression;
>   - non-A3 Periodic: the existing selected action.
> - Set `step.appliedTransport = canonicalRelationValue` (replacing `:4357`).
> - In `SurfaceQuotientProducer::produce`, the HardRail and Periodic certificate checks (`:4723-4724`, `:4749-4750`) compare `appliedTransport` against `relation->evidence.canonicalRelationValue`. `certificate.relationTransport = canonicalTransport` is unchanged.
> - The `publish_records_for_validation` checks stay as they are.
> - Static proof obligation for the CB8 report: for every relation kind, cite the `a532f803` storage-transport line that `canonicalRelationValue` reproduces.
>
> **Goal B — A5-owned route validity (RA-15 as located by RA-16 §5).**
> - Extract the adapter's `exact_interior_route_valid` (`:5752-5773`) into one free function taking the route plus the incidence and transition maps.
> - A5 builds the maps from `sourceFaces`, exactly as the adapter does at `:5529-5546`.
> - At the top of the A5 HardRail branch, before owner, region and reversed-route checks, validate `first.route` and `second.route`. Failure code: new `SurfaceOccurrenceComplexErrorCode::HardRailRouteAuthorityInvalid`, legacy name `InvalidHardRailAuthority`, diagnostic name `OccurrenceHardRailRouteAuthorityInvalid`.
> - The adapter's HardRail and Periodic checks (`:5884-5899`) call the same function; no second copy.
>
> **Tests (TB8 gate = 12 focused + selector449 = 461).**
> - **Focused 3** (`M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`), strengthened at the A5 API level:
>   - a row-230-style HardRail route transition swap returns `HardRailRouteAuthorityInvalid`;
>   - a row-142-style same-orientation route returns `HardRailRouteMismatch`.
> - **New focused 12**, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`, appended after focused 11:
>   - **(a) Baseline.** On `hard_rail_fixture()`, A5 succeeds. Every HardRail relation's `canonicalTransport` maps both endpoint-placement coordinate pairs at equal scale. `equivalence.action == equivalence.route.composed_transport()`. `canonicalSelectedStep->appliedTransport == canonicalRelationValue ==` canonical-direction `route.composed_transport()`.
>   - **(b) Relabelled draft.** Let `R` be the `sourceTopologyRegion` of the first HardRail edge's `oppositeEdge`. Add 1 (mod 4) to `branchRotation` of every `LocalLatticeState` of every cell and edge in region `R`; change nothing else, and assert there are no periodic endpoint states. `construct_phase_front_product` must produce. A5 then succeeds with identical HardRail relation ids and identical `canonicalTransport` per relation, and A6 succeeds with identical class member sets. The RA-14 branch-derived rule fails this clause.
>   - **(c) Nonzero-Z4 witness.** The periodic relation's A5 `canonicalTransport` is in `{T, T⁻¹}` with `T = compose({g.rotation.inverse(), 0}, g)`, and it maps `placement(first).coord → placement(second).coord` for both endpoint pairs. `canonicalSelectedStep->appliedTransport` is in `{g, g⁻¹}` and equals `canonicalRelationValue`.
> - No other test is edited.
>
> **File scope.**
> - `src/pipeline/RemeshPipeline.cpp`;
> - `include/directional/pipeline/RemeshPipeline.h` (new error code and evidence field);
> - `tests/SurfaceCellTransitionQuotientTests.cpp` (focused 3 and new focused 12 only);
> - `cmake/DirectionalTests.cmake` only if registration requires it.
>
> **Static checks.** Add to §5:
> - `git diff` must not touch `src/geometry/PureQuadCompletion.cpp` or the `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` body;
> - selector449, selector448 prefix and routing449 bytes unchanged;
> - `git diff --check` passes;
> - no A7, R4 or G4 code.
>
> **Stop rules.** RA-16 §7, plus: stop for Review if the coordinate-rigid derivation would change the acceptance or transport of any constant-field fixture pair relative to RA-14. Statically that should be impossible.
>
> **TB8 (`M6-CP1-TB8-A6-EXEC`).** Focused 1-12 in order, then selector449 in file order with routing449 — 461 fresh exact-filter processes, benchmark 0. Recovery-green is **461/461**, and the report must state explicitly:
> - the TB7 RED set `115,116,122,130,132,134,137,141,143,150,176,201,217,227,230,231,446`;
> - 446 PASS with an unchanged body;
> - controls 139/140/142 (`InvalidHardRailTransport`), 227/230 (`InvalidHardRailAuthority`), 232/444/448/449, focused 6/10/11/12.
>
> Pre-registered classification for TB8-REV: a `QuotientHolonomyConflict:residual=...` on a HardRail fixture means the rigid cross-rail maps disagree at a rail vertex (consecutive pairs or a rail junction). Classify it by the residual; never relax the strict rule for it.

## 1. Goal and frozen boundary

Recover TB7's two stable regressions and one stale selector446 assertion without changing the reviewed RA-13 periodic/cycle result:

1. separate HardRail carrier-route authority from HardRail placement-gauge relation transport (RA-14);
2. restore individual route-authority validation before A5 reciprocal-pair validation (RA-15);
3. migrate selector446's stale post-materialization transport assertion to the reviewed RA-13 placement-gauge oracle.

Hold fixed:

- A5 relation identity, owner selection, endpoint pairing and canonical direction;
- A6 quotient member-set identity, exact-once certificate/consumption semantics and selected-forest determinism;
- OrdinaryFront identity and exact-A3 Periodic `Γ_to⁻¹ ∘ g ∘ Γ_from` semantics;
- strict cycle equality: `relationTransport == pathTransport`, else `QuotientHolonomyConflict`;
- selector449/routing449 bytes and order, all fixtures, focused identity count **11**;
- A7, `M6-DEFN-R4`, `G4-B002` and unrelated cleanup/refactors.

Do not run generated Directional binaries in this turn.

## 2. Goal A — derive HardRail transport from endpoint placement states

### 2.1 One exact helper

Add/reuse one narrowly scoped helper in the existing A5 implementation surface for a direct `LocalLatticeState a -> b` map:

1. require `a.scaleLevel == b.scaleLevel`;
2. `fromBranch = QuarterTurn::from_integer(a.branchRotation)`;
3. `toBranch = QuarterTurn::from_integer(b.branchRotation)`;
4. `rotation = compose(toBranch, fromBranch.inverse())`;
5. `shift = b.latticeCoordinate - rotate(rotation, a.latticeCoordinate)`;
6. construct `GridAutomorphism{rotation, shift}`;
7. verify with existing `action_matches(a,b,T)` before returning it.

Do not infer this map from `CanonicalRoute::composed_transport()`.

### 2.2 HardRail pair publication

After the already-restored owner/region/reversed-route predicates pass:

- derive `T0` from `first.fromLattice -> second.toLattice`;
- derive `T1` from `first.toLattice -> second.fromLattice`;
- require both values and exact `T0 == T1`;
- otherwise return `SurfaceOccurrenceComplexErrorCode::HardRailTransportMismatch` -> accepted `InvalidHardRailTransport` adapter code;
- publish `sharedEquivalence.action = T0`;
- keep `sharedEquivalence.route = first.route` unchanged as carrier/topology evidence;
- publish `storageTransport = T0` so A5 canonical evidence, selected step and A6 certificate all use placement gauge.

No alternate fallback to route-composed transport is allowed.

### 2.3 HardRail selected-relation consumer

In `PureQuadCompletion.cpp`, keep `completion_certified_hard_rail_components(...)` and its exact route/source-hard-feature checks. Change only the transport comparison:

- forward HardRail relation value = `equivalence.action`;
- reverse = `equivalence.action.inverse()`;
- compare that orientation-adjusted value to `step.appliedTransport` after the independently certified component pair matches.

Do not remove route validation. Do not use action to infer source hard-feature components.

### Goal-A falsifiers

- selectors115/116/141/143/150/217/231 recover from false `InvalidHardRailTransport`;
- downstream selectors122/130/132/134/137/176/201 again reach their established later seams;
- selector139 changed route content still rejects `InvalidHardRailTransport`;
- selector142 same orientation still rejects `InvalidHardRailTransport`;
- selector140 explicit owner mismatch stays green;
- focused10/11 and selector232/444/448/449 remain green.

**Stop:** if the two exact endpoint pairs do not produce one identical placement transform, or another live consumer requires carrier-route composition as quotient placement authority, stop for Review.

## 3. Goal B — restore individual route-authority validation order

Current materialization calls `SurfaceOccurrenceComplexProducer::produce(...)` before the adapter's `exact_interior_route_valid` check, allowing pair reciprocity to shadow malformed individual route authority.

### Required implementation

Extract/move the existing exact route validator so one shared predicate is available before occurrence/A5 relation publication. Before calling `SurfaceOccurrenceComplexProducer::produce(...)`, preflight every relevant phase-front edge:

- HardRail route must satisfy the existing exact interior-route/source-transition predicate; failure preserves `InvalidHardRailAuthority`;
- Periodic route/cut authority preserves its existing `InvalidPeriodicCutAuthority` semantics;
- do not add a weaker duplicate predicate;
- remove or mechanically reuse the later duplicate check so the validation contract has one semantic owner.

This is an ordering correction, not new route semantics.

### Goal-B falsifiers

- selector227 -> `InvalidHardRailAuthority`;
- selector230 -> `InvalidHardRailAuthority`;
- selector139/142 remain `InvalidHardRailTransport` because their individual routes are valid but pair reciprocity is invalid;
- selector140 remains green under its existing owner mismatch contract.

**Stop:** if restoring the ordering requires changing the accepted route-validity predicate, phase-front identity, relation identity, or public failure vocabulary, return to Review.

## 4. Goal C — migrate selector446 without weakening it

Do not rename `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`; selector449 must remain byte-identical.

Keep its existing independent checks for:

- produced nonzero-Z4 periodic relation and nonzero translation;
- endpoint-state publication through `make_periodic_relation_endpoint_state`;
- semantic action `g` mapping published relation-endpoint states and branches;
- successful materialization and non-empty selected relation certificates.

Replace only the stale selected-step predicate that compares `step.appliedTransport` directly with `relation->action()` or inverse.

### New oracle

For the Forward/Reverse periodic edge pair:

1. derive direct cut-domain placement transport `T_direct` from the matching `LocalLatticeState` endpoints using the exact state-to-state formula in §2.1;
2. derive endpoint gauges Γ from `make_periodic_relation_endpoint_state` / the published endpoint states, not from product output;
3. compute `T_gauge = Γ_to⁻¹ ∘ g ∘ Γ_from` independently;
4. require `T_direct == T_gauge` for both paired side endpoints;
5. find the selected step for the relation and require its `appliedTransport` to equal the orientation-correct `T_direct` (forward or inverse).

Do not make the oracle `step.appliedTransport == A5.canonicalTransport` alone. That is not independent enough.

## 5. Tests and static checks authored in CB8

The frozen runtime gate remains **11 focused identities + selector449**. Do not add a twelfth focused identity.

Code + Build may make bounded source-level test edits needed to directly exercise the new helper/ordering, but accepted selector identity/order and fixtures are frozen. Prefer strengthening existing focused10/11 or existing unit-level source assertions rather than adding gate identities.

Before compile verify:

- changed implementation paths are limited to `RemeshPipeline.cpp`/necessary declaration surface and `PureQuadCompletion.cpp` plus narrowly related tests;
- no fixture or selector/routing file changes;
- selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- selector448 prefix SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` and byte-identical rows1-448;
- routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owner census 32/301/75/41;
- no weakening/removal of `action_matches`, reciprocal route checks, exact route structural checks, exact-once relation consumption, or strict A6 cycle equality;
- `git diff --check` passes;
- no A7/R4/G4 implementation appears in the diff.

## 6. Compile/package boundary

Use only the durable GitHub reusable compile workflow with mandatory GMP/GMPXX. Compile/package the standard eight M6 targets. No generated Directional runtime may execute: no test, benchmark, discovery/list, help/version, CLI/GUI or `ctest` command.

Require the standard source/evidence receipts, clean source-status snapshots, root self-excluding manifest and `runtimeExecution=false`.

A compile failure may receive only the smallest same-turn compile repair consistent with §§2-4. Any semantic redesign, fixture/selector change, new relation authority or relaxed validation returns to Review.

## 7. TB8 immutable successor gate

If and only if CB8 compile/package is green, exact successor is `M6-CP1-TB8-A6-EXEC`:

- same 11 focused identities, same order;
- selector449, 449 identities in exact file order with routing449;
- total **460** fresh exact-filter processes;
- exact-one selection, zero skips, benchmark 0, immutable pre/postflight;
- no repair/retry after a mechanically valid semantic RED;
- mandatory `M6-CP1-TB8-A6-REV` afterwards.

Recovery-green is **460/460 PASS**. At minimum explicitly report the prior TB7 RED set `115,116,122,130,132,134,137,141,143,150,176,201,217,227,230,231,446`, controls 139/140/142/232/444/448/449 and focused6/10/11.
