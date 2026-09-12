# M4-CP3-TB7 Review Record

**Turn:** `M4-CP3-TB7-REV`
**Mode:** Review + Plan only; runtime-free
**Date:** 2026-09-12 UTC
**Verdict:** CB9 recovery is real, but the candidate is **REJECTED / UNPROMOTED** because accepted selector403 ordinal211 is RED. The RED is a **TEST-AUTHORITY fixture-precondition drift introduced by the CB5 A3→A4 cutover**, not a direct CB9 product regression.
**Accepted runtime authority:** corrected R4 package `10289601000`, selector403 **403/403**.
**Exact successor:** `M4-CP3-CB10` under `Architecture_M4_CP3_CB10_Code_Build_Plan.md`.

## 1. Evidence independently reopened

Review re-opened the immutable TB7 result/log evidence and the exact source packages needed to discriminate causality:

- TB7 run/job `34721325716 / 103627645766`, result/log artifacts `10306626902 / 10306557117`, SHA-256 `c9993798e8ce4d30db20beb8b96d219c4d48618cc50b4d8c18838ea76f682165` / `2ecd20e9b2e7eccffb20fd9c52c45b34579de274a57ec89c282ff582700b130e`;
- process ledger SHA-256 `d5116d08e4cc08be1d20877008963d04795d7c7dea23a55d725c6da1f22c690e`;
- accepted R4 package `10289601000`, exact semantic source `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- CB5 package `10290933668`, exact semantic source `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`;
- CB9 package `10305678151`, exact semantic source `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`.

The review source snapshot was materialized by run/job `34723031921 / 103632250643` at control head `871f0b0f1fa72ee7a3fca79c570cdfe0cdc69bfc`; snapshot artifact `10307196099` has provider digest `10647fd6104b1135d82cd9a78dbda32dd2ff90e1f853ac175e83b6b28ee58aca`, archive SHA-256 `7a203dd106cbcab51a1f66ea724eeaf46be45da9f578e11c426bc687dcaa6562`, `5261` files, and `runtimeExecution=false`.

No Directional runtime, compile, relink, benchmark, package repair, fixture mutation or selector mutation occurred in Review.

## 2. TB7 mechanical result is upheld

The TB7 ledger and raw ordinal211 log re-derive exactly:

- ordinal138 A/B: **2/2 PASS**;
- row408 A/B: **2/2 PASS**;
- rows404-407 A/B: **8/8 PASS**;
- selector403 ordinals1-210: **210/210 PASS**;
- ordinal211 `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`: **RED** with exception `internal-midline hard-rail rectangle producer failed: InvalidHardRailPairing`;
- total: **223 = 222 PASS / 1 RED**, zero SKIP/crash/timeout/selection mismatch;
- immutable package/source/execution-view postflight: PASS.

The remaining selector403 identities and selector408 were correctly not executed after the frozen first RED.

## 3. CB9 recovery is accepted as recovery evidence

TB7's focused discriminator is decisive for the prior owner:

- ordinal138 **2/2 PASS** proves the CB9 `<4` applicability correction restored the accepted fail-closed compatibility contract;
- row408 **2/2 PASS** proves the CB8 cut-open occurrence-domain path remains intact;
- rows404-407 **8/8 PASS** preserve the four producer-owned controls.

`M4-CP3-TB6-REV-CAND-01` is therefore **CLOSED / RECOVERY PROVED / STABLE EVENT RETAINED**. The historical event remains counted; recovery does not erase it. CB9's one-line semantic correction remains required and is not rolled back.

This recovery does **not** promote package `10305678151`: cumulative accepted selector403 is RED at ordinal211.

## 4. Ordinal211 was accepted-green and its test authority did not change

The complete `tests/SurfaceCellTransitionQuotientTests.cpp` SHA-256 is identical in accepted R4, CB5 and CB9/current source:

`4372a939fc1bc356e7753fa4c40e4ce269b04fcd59ba037513665add6a982f25`.

Accepted R4 runtime executed selector403 **403/403 PASS**, so ordinal211 was accepted-green. The current selector403 list/hash is still `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`. The RED therefore satisfies the durable stable-event criterion: an accepted selector ordinal transitioned PASS → RED.

The test's intended assertion is downstream of fixture construction. It first obtains `hard_rail_fixture()`, drafts a valid produced phase-front product, corrupts one counterpart's reciprocal `oppositeEdge`, and expects `SurfacePhaseFrontProductErrorCode::InvalidOppositeEdge`. TB7 never reaches that tamper/oracle: `make_hard_rail_fixture()` throws while trying to produce the setup network.

## 5. Exact causal split: CB5 introduced the failing precondition, not CB9

### 5.1 Accepted R4 behavior

R4 hard-rail aggregation paired chart copies by source-support geometry (`support_key`) plus route topology. The legacy focused `hard_rail_fixture()` supplies:

- a 3×3 planar grid / eight triangles;
- hard source edges `(1,4)` and `(4,7)`;
- one manually authored `HardFeature` rail over source vertices `{1,4,7}`;
- no `GlobalTopologyPlan` and no `GlobalConformityBaselinePlan`.

That fixture produced under accepted R4 and all selector403 identities, including ordinal211, passed.

### 5.2 CB5 production cutover

CB5 intentionally retired floating `support_key` as shared-boundary authority. Its exact source introduced `SurfaceSharedBoundaryInterval` and changed global `HardRail` aggregation so every hard-rail edge must carry `edge.sharedBoundaryInterval`; otherwise aggregation rejects `InvalidHardRailPairing`.

The interval is populated only when:

```text
useAcceptedConformity =
  options.globalTopologyPlan != nullptr &&
  options.globalConformityBaselinePlan != nullptr
```

The unchanged `hard_rail_fixture()` provides neither pointer. Its produced local `HardRail` edges therefore carry no A3 interval, and the CB5/current global pairing gate rejects them before ordinal211 can exercise its intended reciprocal-opposite tamper.

The same unconditional missing-interval gate is already present in exact CB5 source `4dfd0d9a...`; later CB8 occurrence work only refines same-region cut-occurrence pairing, and CB9 removes only the premature `<4` rejection inside accepted-cut handling. CB9's edited path requires accepted A2b/A3 authority and is unreachable from this no-plan fixture. Exposure order is therefore not causality.

## 6. Classification: TEST-AUTHORITY, not product-semantic

`M4-CP3-TB7-REV-CAND-01` is **OPEN / TEST-AUTHORITY / FIXTURE-PRECONDITION DRIFT AFTER A3→A4 CUTOVER / STABLE EVENT**.

The frozen M4 architecture requires production order `... A2b -> A3 GlobalConformityPlan -> A4`, states that A4 consumes immutable A3 shared subdivision, and explicitly forbids restoring floating `support_key` or locally re-solving shared breakpoints. CB5's fail-closed rejection of a production `HardRail` missing exact A3 interval identity is therefore the intended product contract.

The stale part is the accepted unit fixture: after the production cutover it continued constructing hard-rail A4 authority through the pre-A3 focused seam while expecting a produced network. Restoring a no-plan product fallback merely to make ordinal211 green would violate the frozen single-writer boundary.

The correction belongs in test authority: migrate the shared hard-rail fixture to a production-valid A2b/A3 authority path, then keep the downstream hard-rail counterpart/tamper assertions intact.

## 7. Detection escape and bounded blast radius

CB5 introduced the precondition drift, but TB3-TB5 each failed at row408 before cumulative selector403 could reach ordinal211. TB6 recovered row408 but stopped earlier at accepted ordinal138. TB7 first recovered ordinal138 and therefore reached ordinal211. The delayed observation is a consequence of the frozen fail-fast order, not a later semantic introduction.

Static selector review shows six accepted identities consume the same `hard_rail_fixture()`:

- ordinal211 `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected` — runtime RED proved by TB7;
- ordinal217 `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- ordinal219 `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected`;
- ordinal227 `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed`;
- ordinal230 `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed`;
- ordinal231 `SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity`.

Only ordinal211 is classified as an observed RED. The other five are **static at-risk consumers**, not claimed runtime failures; TB8 must execute them explicitly after the fixture correction.

## 8. Stable accounting

Ordinal211 is inside accepted selector403 and went accepted R4 PASS → TB7 RED. Per the durable criterion this is **ONE NEW STABLE EVENT**.

Primary pattern: existing `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the test fixture no longer establishes the production precondition required to reach the assertion it claims to test.

Accounting advances:

- events **48 → 49**;
- categories remain **14**;
- recurrences **34 → 35**;
- produced-witness debt remains **5**.

`M4-CP3-TB6-REV-CAND-01` remains counted as the preceding stable event even though CB9 recovered it.

## 9. Candidate and authority disposition

- CB9 semantic correction: **RECOVERY PROVED / RETAIN**.
- CB9 package `10305678151` / selector408 candidate: **REJECTED / UNPROMOTED** because accepted selector403 is RED.
- Corrected R4 package `10289601000` / selector403 **403/403**: remains accepted runtime authority.
- CP3 and `G4-B002`: remain OPEN.
- No selector continuation is authorized on the rejected package.

## 10. Exact successor: `M4-CP3-CB10`

CB10 is **test-authority-only, runtime-free Code + Build**. It must follow `Architecture_M4_CP3_CB10_Code_Build_Plan.md`.

The correction is bounded to migrating `make_hard_rail_fixture()` onto accepted production A2b/A3 authority while preserving its mesh, intended hard-rail support and all downstream test identities/assertions. Product source, A2b/A3 writers, hard-rail missing-interval rejection, CB8 occurrence-domain behavior, CB9 applicability behavior, rows404-408 and selector identity lists are frozen.

A product fallback, `support_key` restoration, or weakening of missing A3 interval rejection is an immediate STOP back to Review.
