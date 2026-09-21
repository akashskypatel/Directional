# M5-CP3-TB1-R4 Independent Review Record

**Turn:** `M5-CP3-TB1-R4-REV`
**Boundary:** **Review / runtime-free**
**Reviewed candidate:** artifact `10627250028` / semantic source `001dfe8f0fec8a8dc2475e534fadc29967cadf84` — **unpromoted**
**Reviewed runtime:** run/job `35575202225 / 106255409380`; result/log artifacts `10627818091 / 10628501968`
**Accepted runtime authority:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Disposition:** **R4 EVIDENCE UPHELD / EXISTING RP-01 RECOVERY STILL OPEN / TEST-AUTHORITY ORACLE DRIFT CONFIRMED / BOUNDED CB6 RECOVERY REQUIRED**
**Exact successor:** `M5-CP3-CB6`

## 1. Review question and boundary

R4 is the first runtime proof of CB5's atlas-owned non-traversal transition-value correction. This Review independently decides whether the 445-process evidence is mechanically authoritative; whether the six newly RED accepted-selector atlas rows are product regressions or stale independent-oracle authority; whether the still-RED torus endpoint creates a new stable event; what contract must be recorded in frozen definitions; and the one bounded recovery allowed next.

The Review is runtime-free. No Directional binary, test, benchmark, discovery command, configure, compile, relink, product source, test source, fixture, selector or build source is executed or changed here. Frozen definitions and durable review documents may be corrected because that is Review-owned authority.

## 2. Independent R4 evidence re-derivation

The R4 result bytes were reopened independently. Result artifact `10627818091` has provider/download SHA-256 `a3a17e04b950abdd8563dc279ae1cb4d119f7acb00fba52f7db882a52b488693`; diagnostic log artifact `10628501968` has SHA-256 `38b92dcccce3b22ece60984b2d390279911e0ce59baf942956ac03c5c3cd9e4b`. The result self-manifest hashes to `a77abc5eafa6420cacd91f712c6853bab81ede91083739d46a7b467f7bbaa812`, contains **908** entries and independently verifies **908/908**.

Parsing the three ledgers independently gives:

| phase | rows | PASS | RED | selected exactly 1 | skips |
|---|---:|---:|---:|---:|---:|
| mechanism | 9 | **9** | 0 | 9/9 | 0 |
| produced | 6 | 0 | **6** | 6/6 | 0 |
| selector430 | 430 | **423** | **7** | 430/430 | 0 |
| **total** | **445** | **432** | **13** | **445/445** | **0** |

All six produced rows independently report `torus pipeline producer failed: PeriodicHolonomyMismatch`. Selector RED ordinals are **18, 20, 21, 22, 23, 25, 408**. Ordinal408 remains `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity` and still receives `Rejected` rather than required `Produced`.

`execution-boundary.txt` independently records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`; benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation are all **0**. Package/source/execution-view byte+mode censuses are equal before/after, candidate manifest remains **28/28**, selector authority is unchanged and routing authority is unchanged.

The accepted selector is independently re-hashed from the exact Review snapshot: **430 LF-terminated rows**, no CR bytes, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

**Mechanical verdict:** R4 is mechanically complete semantic RED evidence, not orchestration failure. No R1/R2/R3 semantic credit was reused.

## 3. `R4-CAND-02` — independent atlas oracle drift is confirmed

The six new selector REDs are all `FieldTransportAtlas` identities whose baseline-valid independent snapshot fails before the intended relabel/tamper discriminator. Independent source tracing proves why.

`tests/FieldTransportAtlasTests.cpp` defines `IndependentAtlasSnapshot` over the pre-CB5 semantic domains: adjacency, branch topology, barriers, cycles, singularities, boundary facts, topology/witnesses and digests. It has no retained transition-value field. `independent_snapshot(atlas)` consequently copies no transition values, and `independent_atlas_digest(...)` hashes no transition-value facts. Its final validator compares this old-domain independent digest to the published `atlasDigest`, so a valid CB5 atlas reaches `CanonicalBindingMismatch` before the tests' intended discriminators.

Production authority changed intentionally and consistently in CB5. `FieldTransportAtlas::make` validates exact interior source-edge and two-face transition identity, derives the forward/reverse quarter-turn plus signed lift/effort, stores the canonical transition value **before** hard-feature/traversability classification, derives traversable adjacency from that retained fact, sorts retained values canonically and includes them in atlas semantic identity. Hard-feature edges remain `FieldTransportBarrierKind::HardFeature` and receive no traversal adjacency. The public `transition_value(sourceEdge, fromFace, toFace)` query returns semantic value without `FieldTransportAdjacencyId`; `transport(...)` remains adjacency-only.

Therefore `M5-CP3-TB1-R4-CAND-02` is **TEST-AUTHORITY ORACLE DRIFT / CONTRACT-COVERAGE GAP / NON-STABLE**. It is not evidence of six product regressions and adds **+0 events / +0 categories / +0 recurrences**. The test authority must be repaired in Code + Build by independently deriving the extended transition-value identity domain from source/raw transition authority; it may not merely call the production digest to get the expected answer.

## 4. `R4-CAND-01` — the remaining production recovery is blocked by an unfrozen distinctness guard

CB5 successfully moves generator transition lookup onto the production atlas seam, but the accepted torus endpoint remains RED. Independent static review finds one bounded implementation restriction that is not present in the frozen relation contract.

For same-region hard-rail promotion, `generator_route_for_span(...)` now resolves the exact A3 `Mandatory` span carrier and queries atlas-owned directed transition value. `periodic_action_for_pair(...)` independently derives the complete action from exact lattice correspondence. Before calling `SurfacePeriodicHolonomy::make(...)`, however, the promotion rejects whenever the generator route's `carrier_identity()` equals either orientation of the paired cut route's carrier identity.

That inequality is not a frozen M5 invariant. Frozen §3.1 defines `PeriodicRelationId` from topology region plus canonical generator-carrier path and cut-carrier path; it excludes transport from identity but does **not** require the two carrier paths to differ. Frozen §14.3 requires the generator carrier to come from the exact A3 interval `span` and the cut carrier to come from the produced paired-edge route; it likewise contains no distinctness predicate. `PeriodicRelationId::from_carriers(...)` and `SurfacePeriodicHolonomy::make(...)` require valid non-empty carrier paths and valid relation/action semantics but do not reject equality of the two carrier identities.

For the accepted one-edge A3 hard-feature span, both authorities may legitimately identify the same source-edge/interior-transition carrier: the generator path is the exact `Mandatory` source-edge path, while the paired cut route is derived from that same accepted hard-feature span. Equality alone is therefore not semantic invalidity.

The runtime failure vocabulary is intentionally collapsed to `PeriodicHolonomyMismatch`, so R4 does not instrument which internal predicate fired. This Review consequently does **not** claim the equality guard was dynamically observed. It classifies the guard as the next bounded, contract-backed falsifier: removing only that extra restriction predicts that the corrected atlas-owned generator authority can proceed to the existing checked relation factory. A fresh R5 gate must decide the prediction.

`M5-CP3-TB1-R4-CAND-01` is refined to **IMPLEMENTATION AUTHORITY / UNFROZEN GENERATOR–CUT CARRIER DISTINCTNESS GUARD / EXISTING STABLE `RP-01` CONTINUATION / RECOVERY REQUIRED**. It is another attempted recovery of the same accepted ordinal408 PASS→RED event, not a new accepted-green loss, so it adds **+0 / +0 / +0**.

## 5. Frozen-contract reconciliation and prior obligations

This Review adds frozen §15 to `Architecture_M5_Frozen_Definitions.md` and thereby discharges `M5-CP3-TB1-R3-REV-OBS-01`:

- every validated interior source edge may carry immutable atlas-owned transition **value** even when nontraversable;
- `transition_value(...)` is a directed semantic-value query and does not imply adjacency;
- `transport(...)` remains traversal-adjacency-only;
- hard-feature edges remain absent from traversable adjacency and remain `HardFeature` barriers;
- retained transition values participate in atlas semantic identity;
- the CP3 generator route may consume the exact `Mandatory` carrier's transition value without making that carrier traversable;
- equality of valid generator/cut carrier paths is not, by itself, relation invalidity.

Prior observations are adjudicated as follows:

- `M5-CP2-TB1-REV-OBS-01` — **CARRIED** to the first independently green corrected CP3 pre-publication Review; R4 is RED.
- `M5-CP3-TB1-REV-OBS-01` — **STANDING RULE / SATISFIED BY R4** for exact digest length/provenance; remains a standing process rule.
- `M5-CP3-TB1-R2-REV-OBS-01` — **CARRIED / REFINED TO R5 REVIEW**. Static source proves atlas construction validates unique exact edge/face-pair transition authority and production consumes `transition_value(...)`, but R4 has no direct reached-consumption receipt on a successful produced relation. R5 Review must prove the emitted generator route's transition agrees with independently derived atlas authority while hard-feature traversal remains absent.
- `M5-CP3-TB1-R3-REV-OBS-01` — **DISCHARGED HERE** by frozen §15.
- all four M5 produced-witness debts — **OPEN**.
- M6 closed-complex debt — **OPEN / M6-owned**.

The M5 exit-theorem reconciliation risk remains closure-owned; this Review does not close M5.

## 6. Stable accounting and accepted authority

Stable accounting remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**. R4-CAND-01 is another failed recovery inside the existing stable RP-01 event; R4-CAND-02 is non-stable test-authority drift on an unpromoted package.

Candidate `10627250028` remains **unpromoted**. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. All four M5 produced debts remain open and selector publication remains prohibited.

## 7. Exact successor — `M5-CP3-CB6`

Exactly one bounded Code + Build turn is authorized: `M5-CP3-CB6`, under `Architecture_M5_CP3_CB6_Carrier_Distinctness_And_Atlas_Oracle_Correction_Plan.md`.

Its semantic/test mutation scope is exactly:

1. `src/geometry/SurfaceCellTracing.cpp` — remove only the unfrozen generator-versus-cut carrier-identity inequality rejection while preserving all authoritative action, reciprocity, span, orientation and checked-factory validation;
2. `tests/FieldTransportAtlasTests.cpp` — extend the independent atlas snapshot/digest to derive CB5 transition-value identity independently, including nontraversal hard-feature values, and restore the six accepted baseline/tamper discriminators.

One focused contract test is added in the already-authorized atlas test file: `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`. Selector430 remains byte-frozen and is not edited.

CB6 is runtime-free and must perform mandatory GMP/GMPXX compile/package of all eight standard targets only. If static/compile green, exact successor is fresh artifact-only `M5-CP3-TB1-R5-EXEC`, restarting **9 mechanism + 1 focused atlas-contract + 6 produced + 430 selector = 446** fresh exact-filter processes, benchmark execution 0 and no semantic-credit reuse. Stop rather than widen scope if the production correction requires identity/factory semantics to change, if the independent oracle cannot derive the new identity domain without using production answers as expected authority, or if selector/test expectations beyond the named atlas oracle must change.

## 8. Consolidation

This Review folds six superseded per-turn documents into `M5_Consolidated_Record.md` and git history: CP2 TB1 runtime report/Review, CB5 plan/report, and R3 runtime report/Review. Retained current authority is the R4 runtime report, this R4 Review, one CB6 plan, M5 frozen definitions, closure records, consolidated record and selectors.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 LF rows, no CR |
| Decisive claims independently re-derived | result self-manifest 908/908; ledger vector 9/9 + 0/6 + 423/430 = 432/445; exact-one/zero-skip 445/445; immutable postflight and zero prohibited counters; atlas production digest includes CB5 transition values while independent test digest omits them; frozen/factory relation authority contains no generator-cut carrier-distinctness rule |
| Non-vacuity checked | six atlas rows fail valid baseline before their intended discriminators, proving stale oracle authority rather than successful tamper coverage; six produced rows reach the real torus fixture and RED before debt assertions; ordinal408 still requires `Produced`; nine mechanism controls remain green; CB6's carrier-guard removal has a falsifiable R5 prediction |
| Prior obligations discharged/carried | `M5-CP2-TB1-REV-OBS-01` carried; `M5-CP3-TB1-REV-OBS-01` standing/satisfied; `M5-CP3-TB1-R2-REV-OBS-01` refined/carried to R5 Review; `M5-CP3-TB1-R3-REV-OBS-01` discharged by frozen §15; four M5 debts open; M6 debt open |
| Stable accounting | **50 / 14 / 36**, debt **5**; accepted package `10601978228`, selector430 **430/430**; R4 adds no stable event |
| New candidates/obligations recorded | `R4-CAND-01` refined as unfrozen carrier-distinctness implementation authority inside existing RP-01; `R4-CAND-02` confirmed non-stable atlas-oracle drift; tracker updated |
| ORIENTATION currency line | `M5-CP3-TB1-R4-REV`, 2026-09-21 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated R4 adjudication, torus/current authority, CB6 priority, carried obligations, and existing RP-01/RP-02 instances; superseded R4-Review-next language removed |
| CHANGELOG | one R4 Review entry records independent vector, both candidate adjudications, frozen §15, accounting and CB6 successor |
| ROADMAP | M5-CP3 advanced to R4 reviewed / CB6 recovery next; no checkpoint closed |
| Selector manifest | n/a — selector430 bytes/order/census and accepted selector authority are unchanged; no selector was added or accepted |
| LESSONS | existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`, independent-oracle/test-authority drift discipline and non-vacuity rules apply; no genuinely new project-wide lesson added |
| Consolidation under CLEAN_UP_POLICY | folded six superseded M5 per-turn documents (768 lines total) into consolidated index/history; retained current R4 report/Review + one CB6 plan |
| Successor frozen | exactly `M5-CP3-CB6`; falsifiers and stop rules are in `Architecture_M5_CP3_CB6_Carrier_Distinctness_And_Atlas_Oracle_Correction_Plan.md` |
| Turn boundary held | runtime-free; no Directional execution and no product/test/fixture/selector/benchmark/build-source mutation in Review; only frozen/durable document authority changes |
| review_check.py boundary | PASS — local `python3 .agents/Directional/tools/review_check.py boundary` reports ALL CHECKS PASSED |
| `STATUS` lifecycle maintained | entry and resume beacons published for `M5-CP3-TB1-R4-REV`; terminal COMPLETE beacon with sole successor `M5-CP3-CB6` is the final repository write after durable docs and cleanup |
| Pushed to origin, branch in sync | control-plane confirmation is performed after documentation push and temporary-state cleanup; no self-referential commit hash is embedded in this record |
