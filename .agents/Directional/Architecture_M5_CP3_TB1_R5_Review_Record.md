# M5-CP3-TB1-R5 Independent Review Record

**Turn:** `M5-CP3-TB1-R5-REV`
**Boundary:** **Review / runtime-free**
**Reviewed candidate:** artifact `10633891886` / semantic source `20f9bf11dc5a986dafd52c5556671fb9f7d429f4` — **unpromoted**
**Reviewed runtime:** run/job `35591203189 / 106305794544`; result/log artifacts `10634649162 / 10635142112`
**Accepted runtime authority:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Disposition:** **R5 EVIDENCE UPHELD / R4 ORACLE RECOVERY PROVED / EXISTING RP-01 RECOVERY STILL OPEN / FAILURE-BRANCH OBSERVABILITY REQUIRED**
**Exact successor:** `M5-CP3-CB7`

## 1. Review question and boundary

R5 tests CB6's two falsifiable corrections: the independent atlas oracle must recover without weakening its discriminators, and removing the unfrozen generator-versus-cut carrier inequality must either recover the production torus endpoint or be falsified as the complete cause. This Review independently re-derives those results, adjudicates the two candidates, and freezes only the next bounded diagnostic step supported by the evidence.

The Review is runtime-free. No Directional binary, test, benchmark, discovery command, configure, compile, relink, product source, test source, fixture, selector or build source is executed or changed here. Review-owned durable records and the next Code + Build plan may change.

## 2. Independent R5 evidence re-derivation

The R5 result bytes were reopened independently. Result artifact `10634649162` has provider/local SHA-256 `b93903eafdd028140759526635312efa7e6896442d5260a871a85402371cc4ab`; diagnostic log artifact `10635142112` has provider/local SHA-256 `eded6a14c358fb4f8a24ae07585142cc9d97042912fd100857ff078430f9509c`. The result self-manifest hashes to `680ec03ace5f839e802fc256b7a335b11279cedc9248d641e9156e266d6b4fc9`, contains **911** entries, and independently verifies **911/911**.

Independent parsing of all four ledgers gives:

| phase | rows | PASS | RED | selected exactly 1 | skips |
|---|---:|---:|---:|---:|---:|
| mechanism | 9 | **9** | 0 | 9/9 | 0 |
| focused atlas | 1 | **1** | 0 | 1/1 | 0 |
| produced | 6 | 0 | **6** | 6/6 | 0 |
| selector430 | 430 | **429** | **1** | 430/430 | 0 |
| **total** | **446** | **439** | **7** | **446/446** | **0** |

Every ledger raw-log SHA-256 was independently recomputed and matches its receipt. All six produced rows report `torus pipeline producer failed: PeriodicHolonomyMismatch`. The only selector RED is ordinal **408**, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, which still requires `Produced` but observes `Rejected` with `NotProductionReady/tracing/None`.

`execution-boundary.txt` independently records preflight/runtime start/runtime completion true, orchestration failure false, benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation all **0**. Package/source/execution-view byte+mode censuses are unchanged, candidate manifest remains **28/28**, selector authority is unchanged, and routing authority is unchanged.

Selector430 independently re-hashes from the exact Review snapshot to **430 LF-terminated rows**, no CR bytes, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

The CB6 compile candidate was also re-opened independently: artifact `10633891886` hashes to `4359271b96f9cf5351782056ee030757a3d02956b8cb901264d4a46b4d1836f7`; its 28-row root manifest hashes to `5e36a32b3c07c1c4f533c8f896517e33239475a6175d012b66bdd6da358dbd73` and verifies **28/28**; packaged source is `20f9bf11dc5a986dafd52c5556671fb9f7d429f4`; source archive hashes to `c939872ab9e8648d2009e7ca9781ea62a6938ffeb21f342344924dcaf171b8b7`; command boundary remains Code + Build only with `runtimeExecution=false` and explicit GMP/GMPXX linkage.

**Mechanical verdict:** R5 is mechanically complete semantic RED evidence, not orchestration failure.

## 3. `R4-CAND-02` — recovery is proved and the non-stable issue closes

R4 pre-committed a clean recovery falsifier: CB6 had to extend the independent atlas oracle from independent source/raw transition authority, preserve the six accepted tests' original discriminators, add one hard-feature transition-value-without-adjacency identity, and return the six R4 atlas REDs to green without selector changes.

R5 satisfies that falsifier exactly. The new focused identity `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency` passes. Accepted selector ordinals **18, 20, 21, 22, 23, 25** all pass. Static source inspection confirms the independent snapshot now derives retained transition values from `CrossFieldResult::edgeTransitions` plus typed source authority, hashes those facts independently, while the existing tests still contain their original relabel/tamper assertions. Hard-feature traversal remains absent; the focused identity requires transition value in both directions while `transport(...)` and adjacency lookup remain absent and barrier kind remains `HardFeature`.

`M5-CP3-TB1-R4-CAND-02` is therefore **CLOSED / RECOVERY PROVED / TEST-AUTHORITY ORACLE DRIFT / NON-STABLE / +0 accounting**. No stable regression event was created and no accepted selector expectation was weakened.

## 4. `R5-CAND-01` — existing RP-01 continuation remains open; CB6's production falsifier is refuted

CB6 removed only the unfrozen generator-versus-cut carrier inequality. R5 still produces the same six torus `PeriodicHolonomyMismatch` failures and accepted ordinal408 `Produced`→`Rejected` endpoint. The carrier inequality was therefore **not the complete active cause**.

This is still the same accepted ordinal408 PASS→RED event first priced at R1. It has never returned to accepted green on a promoted candidate, so another failed repair attempt does not create another event or recurrence. `M5-CP3-TB1-R5-CAND-01` is **UPHELD AS EXISTING `RP-01 / AUTHORITY_DOMAIN_CONFLATION` CONTINUATION / RECOVERY OPEN / +0 events / +0 categories / +0 recurrences**. Stable accounting remains **50 / 14 / 36**, debt **5**.

The important Review result is what cannot yet be claimed. The current same-region promotion collapses three materially different boundaries into `PeriodicHolonomyMismatch`:

1. `generator_route_for_span(...)` returns no exact generator route;
2. `periodic_action_for_pair(...)` rejects lattice/branch endpoint correspondence;
3. `SurfacePeriodicHolonomy::make(...)` rejects relation construction (with exact subcodes `ZeroTranslation`, `MissingRoute`, `MissingCutRoute`, or `InvalidRelationIdentity`).

The extra rotation comparison in branch 2 is not an independent fourth cause: `periodic_action_for_pair` constructs the action using the exact rotation passed by the generator route, so when the action exists its rotation is that same value.

R5 does not expose which branch fires. After R4's statically plausible carrier-distinctness falsifier failed dynamically, another semantic edit chosen from static plausibility alone would violate the project's fail-closed and single-authority discipline.

## 5. Static next-candidate observation — exact A3 carrier incidence is not proved equal to A4 front endpoint faces

One source-level authority mismatch is concrete enough to retain as a **candidate**, not to implement yet. `generator_route_for_span(span, fromFace, toFace)` correctly resolves the A3 `Mandatory` arc and exact `SourceEdgeSupport` carrier, but queries `FieldTransportAtlas::transition_value(...)` using `first.from.face` and `second.to.face` supplied by the paired A4 front representation. `SurfaceTracePoint::face` is an untyped integer provenance field, and `SurfaceFrontEdge` contains no contract proving those two endpoint face labels are exactly the two source faces incident to the A3 carrier edge.

The same producer already computes authoritative `sourceEdgeFaces = edge_faces(faces)`, which maps each interior `SourceEdgeTopologyKey` to its exact two source face rows. Frozen §14.3 says generator authority comes from the exact A3 interval `span` / source path. Reusing A4 front endpoint-face labels as A3 transition-incidence authority is therefore a plausible `RP-01` domain leak.

It is **not yet classified as the root cause**. If R6 identifies `generator_route_for_span` as the active failing branch, this observation becomes the next bounded semantic falsifier. If R6 identifies action correspondence or relation construction instead, the observation remains non-operative and must not be used to steer the fix.

Record this as `M5-CP3-TB1-R5-REV-OBS-01`: **STATIC AUTHORITY-MISMATCH CANDIDATE / DYNAMIC BRANCH PROOF REQUIRED BEFORE SEMANTIC CHANGE**.

## 6. Prior obligations

- `M5-CP2-TB1-REV-OBS-01` — **CARRIED** to the first independently green corrected CP3 pre-publication Review. R5 remains RED.
- `M5-CP3-TB1-REV-OBS-01` — **STANDING RULE / SATISFIED BY R5** for exact digest/provenance; remains a standing process rule.
- `M5-CP3-TB1-R2-REV-OBS-01` — **CARRIED / REFINED TO R6 REVIEW**. R5 proves the independent atlas transition-value contract and hard-feature nontraversal, but no successful produced relation exists from which to prove reached generator-route consumption.
- `M5-CP3-TB1-R3-REV-OBS-01` — **DISCHARGED** by frozen §15; unchanged.
- `M5-CP3-TB1-R4-REV-OBS-01` — **DISCHARGED BY R5**. The independent-oracle extension returns all six named accepted rows to PASS while the added hard-feature value-without-adjacency control also passes.
- M5 produced-witness debts 1-4 — **OPEN**. No product witness is produced in R5.
- M6 closed-complex debt — **OPEN / M6-owned**.

No frozen-definition amendment is required. Frozen §§14-15 already require exact A3 carrier authority, distinguish transition value from traversal adjacency, permit generator/cut carrier equality, and preserve checked relation semantics. Review found no frozen claim false.

## 7. Exact successor — `M5-CP3-CB7`

Exactly one bounded runtime-free Code + Build turn is authorized under `Architecture_M5_CP3_CB7_Periodic_Holonomy_Failure_Disambiguation_Plan.md`.

CB7 changes diagnostics only. It appends typed same-region periodic-promotion failure reasons without renumbering existing reasons, so the three collapsed boundaries are distinguishable and the relation-construction branch reports its exact existing `SurfacePeriodicHolonomyErrorCode`. It must not change generator-route selection, face authority, action mathematics, relation identity/factory behavior, fixtures, selector430, frozen definitions, or any acceptance expectation. Mandatory GMP/GMPXX compile/package of all eight standard targets is required; generated Directional runtime remains prohibited.

If compile/package is green, exact successor is a fresh artifact-only `M5-CP3-TB1-R6-EXEC` replaying the same **9 mechanism + 1 focused atlas + 6 produced + 430 selector = 446** exact-filter processes. R6's discriminator is diagnostic: all six produced rows must reach one of the newly typed periodic-promotion reasons, while mechanism/focused/selector authority remains otherwise unchanged. R6 then routes to mandatory runtime-free `M5-CP3-TB1-R6-REV` before any semantic repair.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 LF rows, no CR |
| Decisive claims independently re-derived | result self-manifest 911/911; ledger vector 9/9 + 1/1 + 0/6 + 429/430 = 439/446; exact-one/zero-skip 446/446; raw-log hashes; immutable postflight; zero prohibited counters; CB6 package 28/28 + GMP boundary |
| Non-vacuity checked | focused hard-feature value-without-adjacency row passes; all six R4 atlas REDs return green with their source discriminators retained; six produced rows still enter the real torus fixture and fail before debt assertions; ordinal408 still requires `Produced`; carrier-distinctness falsifier is therefore actually refuted |
| Prior obligations discharged/carried | CP2 OBS-01 carried; CP3 TB1 OBS-01 standing/satisfied; R2 OBS-01 carried/refined to R6 Review; R3 OBS-01 discharged; R4 REV OBS-01 discharged by R5; four M5 debts open |
| Stable accounting | **50 events / 14 categories / 36 recurrences**, debt **5**; accepted package `10601978228` / selector430 **430/430**; R5 candidate unpromoted |
| New candidates/obligations recorded | `M5-CP3-TB1-R5-CAND-01` upheld as existing RP-01 continuation; `M5-CP3-TB1-R4-CAND-02` closed recovered non-stably; new `M5-CP3-TB1-R5-REV-OBS-01` requires branch proof before semantic use of the source-face-incidence candidate; tracker updated |
| ORIENTATION currency line | `M5-CP3-TB1-R5-REV`, 2026-09-21 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated current R5 Review authority, torus witness, CB7 priority, carried obligations, recovered oracle issue and new diagnostic-collapse/RP-01 instance; superseded CB6-next text removed |
| CHANGELOG | one R5 Review entry added |
| ROADMAP | M5-CP3 advanced to R5 reviewed / CB7 diagnostic disambiguation next; no checkpoint closed |
| Selector manifest | n/a — selector430 bytes and accepted authority are unchanged; no selector is added or accepted |
| LESSONS | no new lesson number; existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`, non-vacuity/reachability discipline and typed-failure principles apply |
| Consolidation under CLEAN_UP_POLICY | n/a — R5 runtime report remains current evidence and this Review/CB7 plan are current authority; no superseded durable document needed deletion |
| Successor frozen | exactly `M5-CP3-CB7`; falsifiers/stop rules are in `Architecture_M5_CP3_CB7_Periodic_Holonomy_Failure_Disambiguation_Plan.md` |
| Turn boundary held | runtime-free; no product/test/fixture/selector/build source mutated; only Review-owned durable documentation/plan changed |
| review_check.py boundary | **PASS** on the final local review document set |
| `STATUS` lifecycle maintained | entry beacon `M5-CP3-TB1-R5-REV / IN_PROGRESS` published; terminal COMPLETE beacon with sole successor `M5-CP3-CB7` is reserved as the final repository write after durable docs and cleanup |
| Pushed to origin, branch in sync | confirmed after durable-doc push and temporary-state cleanup; final authority re-read before terminal `STATUS` write |
