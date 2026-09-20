# M5-CP3-CB1 Static Stop Record

**Turn:** `M5-CP3-CB1`
**Mode:** Code + Build / runtime-free
**Disposition:** **COMPLETE AT FROZEN STOP CONDITION / NO IMPLEMENTATION PATCH / REVIEW REQUIRED**
**Entering accepted runtime authority:** package `10601978228` / semantic source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Inspection snapshot:** source snapshot run `35509222128`, artifact `10604648917`, event SHA `331d9052f70cd60171d5179927bd730ba90fd7ad`, provider ZIP SHA-256 `884e043f4f711d03c531c00ab9ca39e6d115df0ced59d88654ae6c91d8b9f499`
**Exact successor:** `M5-CP3-CB1-REV`

## 1. Outcome

CB1 reached a frozen architectural stop condition before any product/test implementation or compile was authorized. The accepted row408 test and the current product/materializer contracts impose mutually incompatible boundary-kind requirements on the same one-region torus cut copies.

No production, test, benchmark, selector, fixture, build, or reusable-workflow logic was changed. No Directional binary was compiled or executed in this turn. The accepted package `10601978228` and selector430 therefore remain the runtime authority.

## 2. Independently established conflict

The frozen positive subject is the accepted selector430 row408 test `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`. That test preserves the exact 18-edge torus cut graph and requires the produced phase front to contain at least one edge whose `boundaryKind` is exactly `HardRail`; every such counted edge must carry `sharedBoundaryInterval`.

The current A4 production seam groups every retained `HardRail` edge by exact A3 shared-boundary interval and canonical route. For a same-source-region pair it permits pairing only when both sides carry distinct exact cut-boundary occurrences, then publishes the two edges as paired, non-exterior `HardRail` edges. On the frozen one-region torus subject, those same-region paired cut copies are precisely the authority CP3 is asked to convert into periodic relation ownership.

The checked `SurfacePhaseFrontProduct::make(...)` contract currently permits `sharedBoundaryInterval` only when `boundaryKind == HardRail`. A `PeriodicCut` carrying that accepted A3 shared-boundary provenance is rejected as `InvalidSharedBoundaryInterval` before CP2 periodic-owner checks.

The materializer independently rejects any paired `HardRail` whose two sides have the same `sourceTopologyRegion` as `InvalidHardRailTransport`. Conversely, its periodic path requires `boundaryKind == PeriodicCut`, a resolvable periodic relation owner, exact cut-route ownership, and a relation action/inverse that maps both endpoint lattice states.

Therefore, on the frozen one-region row408 subject:

1. converting all same-region A3 cut copies to `PeriodicCut` is required for the intended periodic materialization semantics but makes accepted row408's exact `HardRail` count zero;
2. retaining any such pair as `HardRail` keeps row408's current assertion satisfiable but makes the required positive CP3 materialization fail on `InvalidHardRailTransport`;
3. retaining `sharedBoundaryInterval` on converted `PeriodicCut` edges additionally fails the current CP2 checked factory unless that cross-cut provenance contract is explicitly extended;
4. changing row408 to count periodic cut copies, or changing same-region `HardRail` materializer semantics merely to retain the old row, is outside CB1's frozen authority.

This directly triggers the CP3 plan stop rule: the row408 subject cannot reach the required `>=2` canonical periodic relations / owned periodic edges and materialized periodic semantics while preserving the accepted test's current hard-rail target without changing an explicitly frozen accepted-selector contract.

## 3. Why CB1 does not choose a workaround

A superficially small implementation could hide the conflict by duplicating edges, leaving semantically stale `HardRail` pairs, allowing same-region hard rails through materialization, or relaxing the checked `sharedBoundaryInterval`/boundary-kind invariant. Each would alter an accepted semantic boundary rather than implement the frozen CP3 plan. The plan expressly forbids weakening CP2 typing, retargeting an accepted selector430 test body, or widening into a second unrelated architecture change.

The narrow architecture choice that now requires independent review is whether A3 shared-boundary provenance is intended to remain orthogonal metadata when a same-region cut copy is promoted from `HardRail` to `PeriodicCut`, with row408 correspondingly re-specified to verify the same typed A3 provenance across the promoted boundary kind. That is a contract decision; CB1 does not pre-authorize it.

## 4. Preserved evidence and unchanged authority

- Source inspection authority: `331d9052f70cd60171d5179927bd730ba90fd7ad` from snapshot run `35509222128` / artifact `10604648917`.
- Accepted runtime package: `10601978228` / semantic source `0798547dedd8be05f9cd7a096b07e6bd94755316`.
- Selector430 remains 430 LF rows at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
- Stable regression accounting remains **49 events / 14 categories / 35 recurrences**.
- Produced-witness debt remains **5**; all four M5 production debts remain open.
- No compile/package artifact was produced because the frozen stop condition was reached before an implementation patch existed. `runtimeExecution=false` by turn boundary; no runtime command was executed.

## 5. Mandatory independent Review question

`M5-CP3-CB1-REV` is runtime-free and must decide the architecture before another Code + Build turn. It must explicitly adjudicate all of the following together:

1. whether `SurfaceSharedBoundaryInterval` is provenance that remains valid on a same-region `PeriodicCut` after A4 promotes an A3 hard-rail cut copy into periodic quotient authority;
2. whether accepted row408 may be surgically strengthened/re-specified to require the same exact 18-edge A3 provenance while accepting the promoted periodic boundary kind, rather than requiring a residual `HardRail` edge;
3. whether `SurfacePhaseFrontProduct::make(...)` may extend its shared-interval validation to `PeriodicCut` without weakening any CP2 periodic owner/reciprocity/value checks;
4. whether the materializer must continue to reject same-region `HardRail` and require all same-region quotient cut copies to be typed `PeriodicCut`;
5. only if those points are approved, freeze a replacement CB plan that still requires the six existing `M5CP3.Produced...` identities, the exact row408 18-edge production subject, canonical content IDs, authoritative full `GridAutomorphism`, selector430 byte freeze, and mandatory GMP compile-only evidence.

No M5 debt, selector publication credit, or milestone closure is earned by this static stop record.
