# M5-CP3-TB1-R2 Independent Review Record

**Turn:** `M5-CP3-TB1-R2-REV`
**Boundary:** **Review / runtime-free**
**Reviewed candidate:** artifact `10620415471` / semantic source `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5` — **unpromoted**
**Reviewed runtime:** run/job `35557990692 / 106205308600`; result/log artifacts `10621351075 / 10621154456`
**Accepted runtime authority:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Disposition:** **R2 EVIDENCE UPHELD / IMPLEMENTATION AUTHORITY REFINED / EXISTING STABLE RP-01 RECURRENCE CONTINUES / RECOVERY REQUIRED**
**Exact successor:** `M5-CP3-CB4`

## 1. Review question and boundary

R2 is the first fresh runtime on CB3's exact-span correction. This Review must independently determine four things without implementation or rerun: whether the R2 445-process gate is mechanically authoritative; whether the unchanged RED vector still protects test/selector authority; why the exact-span correction did not restore the torus production endpoint; and whether R2 is a new stable event or continuation of the already-open R1 accepted-prefix regression.

The Review is runtime-free. No Directional binary, test, benchmark, discovery command, build, product source, test source, fixture, selector or frozen definition is changed or executed here.

## 2. Independent R2 evidence re-derivation

The result and diagnostic artifacts were reopened independently from immutable local copies of the exact GitHub artifacts. Their outer SHA-256 values are:

- result `10621351075`: `793de57785f058e8a16a9d95c084d6e593b7d0e552586756b3fa0c021b85e66f`;
- log `10621154456`: `65e4ba46c7bd5c6cd45e91cd35a35fc9aaec1e7c0b4bd61a3aac9d171e0daf02`.

The result self-manifest contains **908** rows and verifies **908/908**. Independent ledger parsing gives:

| phase | rows | PASS | RED | selected exactly 1 | skips | nonzero exit |
|---|---:|---:|---:|---:|---:|---:|
| mechanism | 9 | **9** | 0 | 9/9 | 0 | 0 |
| produced | 6 | 0 | **6** | 6/6 | 0 | 6 |
| selector430 | 430 | **429** | **1** | 430/430 | 0 | 1 |

The sole selector RED is ordinal408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`. All six `M5CP3.Produced...` rows throw `torus pipeline producer failed: PeriodicHolonomyMismatch` while establishing the shared production fixture. Ordinal408 still receives `Rejected` instead of required `Produced` (`NotProductionReady / tracing / None`).

`execution-boundary.txt` independently records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`; benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation are all **0**. Package/source/execution-view byte+mode censuses are identical before and after, candidate manifest remains **28/28**, selector and routing-map authority are unchanged.

The accepted selector is independently re-hashed from the review snapshot: **430** LF-terminated rows, no CR bytes, full SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

**Mechanical verdict:** the R2 report is upheld. It is a complete, immutable artifact-only semantic RED with no execution-plane invalidity.

## 3. Test and expectation authority remains upheld

R2 repeats the same discriminating shape as R1 after a product-only correction:

- all nine reviewed CP1/CP2 relation mechanisms remain green;
- all six production-debt identities fail before their relation-specific debt assertions because the real torus pipeline never reaches `Produced`;
- accepted ordinal408 fails at its pre-existing required `Produced` assertion before the §14.4 final-kind evolution can be decisive;
- the accepted selector prefix itself remains byte-identical.

Nothing in R2 supports weakening row408, the six produced tests, the torus fixture, CP2 checked failures, or selector430. The RED remains product-authority evidence.

## 4. Independent static diagnosis of the failed CB3 recovery

### 4.1 CB3 fixed the R1 whole-region substitution but selected the wrong transport domain

Frozen `Architecture_M5_Frozen_Definitions.md` §14.3 requires the exact A3 interval `span` to resolve through accepted `GlobalTopologyPlan::sourcePath`, and that exact path to be converted through **existing transition/atlas authority** into the generator carrier. CB3 correctly removed the R1 whole-region branch-transport reconstruction and now resolves the exact `Mandatory` source-path carrier.

The remaining implementation error is deterministic. Current `generator_route_for_span` resolves the exact `SourceEdgeSupport`, then asks:

`options.fieldTransportAtlas->transport(carrier->edge, typedFromFace, typedToFace)`.

That API is traversal authority. In `FieldTransportAtlas::make`, raw `crossField.edgeTransitions` are first indexed by exact source-edge key, but a `hardFeatureEdges` match is then published as `FieldTransportBarrierKind::HardFeature` and the edge is skipped before any `FieldTransportAdjacency` is built. `FieldTransportAtlas::transport` later searches only `adjacencies_`; a hard-feature edge therefore returns no directed atlas transport by construction.

The promotion seam's exact A3 interval is not an arbitrary traversable edge. The accepted hard-rail boundary authority is created from mandatory hard-feature carriers; exact shared-boundary intervals are retained on `HardRail`, and same-region promotion is exactly the operation converting the paired chart copies to `PeriodicCut`. CB3 therefore asks a **nontraversable hard-feature carrier** for a traversal adjacency that intentionally cannot exist. `generator_route_for_span` returns `nullopt`, and the first same-region promotion guard deterministically emits `PeriodicHolonomyMismatch`.

This is not evidence that the hard feature should become traversable. Changing `FieldTransportAtlas` to publish a hard-feature adjacency would weaken A1 barrier authority and is outside §14. The defect is another authority-domain conflation: **barrier/traversal classification is not the same authority as the edge's exact cross-field transition value**.

### 4.2 Existing exact transition metadata already carries the required value

No new semantic authority is needed. `FieldTransportAtlas::make` indexes `CrossFieldEdgeTransition` by exact source-edge key **before** hard-feature exclusion. The same production file already has `EdgeTransitionLookup` and `resolve_branch_transition` logic for the raw transition path: it validates exact source-edge vertices and the requested face pair, derives `QuarterTurn::from_integer(matching)` for forward traversal, and uses its inverse for reverse traversal.

CB3's frozen plan explicitly allowed “the already-built transition lookup” where the exact path uniquely determines the directed transport. The bounded corrective therefore uses the existing edge-keyed transition metadata for the exact hard-feature support step; it must not create a traversable atlas adjacency, search the region, infer from floating geometry, or invent a new relation authority.

### 4.3 CB3 also over-constrained exact path endpoints

A second static incompleteness is latent in the same helper. `generator_route_for_span` currently requires both exact support-piece endpoints to be `SourceVertexId`. But `GlobalTopologyPlan` can split a `Mandatory` source edge at one exact terminal-barrier parameter and emits two exact mandatory interval paths `[0,t]` and `[t,1]`; one endpoint is then an `ExactSourceEdgePoint`.

The same phase-front function already owns `exact_edge_parameter`, which accepts either a source vertex or an exact edge point and returns the canonical exact parameter. CB4 must derive support orientation from those exact parameters instead of requiring vertex-only endpoints. This is contract completeness, not the dynamic explanation for R2: the hard-feature atlas-domain mismatch already makes the current promoted HardRail step fail deterministically.

## 5. Classification and stable accounting

`M5-CP3-TB1-R2-CAND-01` is classified **IMPLEMENTATION AUTHORITY / HARD-FEATURE TRANSPORT DOMAIN CONFLATION / RECOVERY REQUIRED** and is **merged into the existing `M5-CP3-TB1-R1-CAND-01` stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event**.

R2 does **not** add another stable event. The accepted-prefix transition being tracked is still the same ordinal408 PASS→RED first recorded by R1. R2 is a recovery candidate that leaves that already-open accepted behavior RED; it does not create a second distinct accepted-green→RED transition. The refined static cause is in the same RP-01 category: CB2 sourced carrier and transport from different authority domains; CB3 unified the carrier path but then sourced a hard-feature relation value through an API whose domain explicitly excludes hard features.

Stable accounting therefore remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**. Candidate `10620415471` remains unpromoted. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

All four M5-owned produced debts remain **OPEN** with zero credit. `M5-CP2-TB1-REV-OBS-01` remains carried to the first independently green corrected CP3 pre-publication Review. `M5-CP3-TB1-REV-OBS-01` remains the standing digest/provenance process rule and was satisfied by the R2 frozen plan/materialized driver; it opens no new blocker.

## 6. Exact successor — `M5-CP3-CB4`

The sole successor is runtime-free Code + Build plan `Architecture_M5_CP3_CB4_Hard_Feature_Transition_Transport_Correction_Plan.md`.

CB4 is product-source-only. Its exact correction seam is the generator transport for a `Mandatory` hard-feature support: preserve the exact `GlobalTopologyArc::sourcePath` carrier, obtain the edge's directed quarter-turn from existing exact `CrossFieldEdgeTransition` metadata keyed by the same source edge and validated face pair, and derive support orientation from exact edge parameters. Do **not** make hard features traversable in `FieldTransportAtlas` and do not introduce a fallback/global search.

The plan's falsifiers are frozen before implementation: stop if the exact source edge does not have one unique transition record for the requested face pair; stop if exact source-path orientation cannot be derived from exact parameters; stop if the correction requires changing any test/fixture/selector/frozen definition, weakening CP2 checked relation semantics, changing cross-region HardRail/materializer rejection, or widening A1 hard-feature traversal authority.

A statically faithful, GMP compile/package-green CB4 routes to a **fresh** artifact-only `M5-CP3-TB1-R3-EXEC`; no R1/R2 semantic credit is reused.

## 7. Consolidation

Per `CLEAN_UP_POLICY.md`, this Review folds the superseded CP3 per-turn documents into `M5_Consolidated_Record.md` after preserving their durable facts here, in the tracker, changelog, orientation and handoff. The current runtime report `Architecture_M5_CP3_TB1_R2_Artifact_Only_Test_Benchmark_Report.md`, this Review record, the new CB4 plan, consolidated/frozen records and byte-frozen selectors remain current authority.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` |
| Decisive claims independently re-derived | R2 outer artifact hashes; result self-manifest 908/908; 9/9 + 0/6 + 429/430 ledger vector; exact-one/zero-skip; immutable postflight; zero prohibited counters; exact source-path/atlas hard-feature domain mismatch; raw edge-transition directed matching authority |
| Non-vacuity checked | all six produced rows reach the real torus fixture and fail before debt-specific assertions; row408 fails at its pre-existing `Produced` assertion; nine independent mechanism controls remain green; the exact hard-feature atlas lookup is statically guaranteed absent rather than inferred from a collapsed diagnostic |
| Prior obligations discharged/carried | `M5-CP3-TB1-R2-CAND-01` merged/refined into existing stable `M5-CP3-TB1-R1-CAND-01 / RP-01`; four M5 produced debts remain open; `M5-CP2-TB1-REV-OBS-01` carried; `M5-CP3-TB1-REV-OBS-01` standing process rule satisfied for R2 and retained |
| Stable accounting | **50 / 14 / 36**, debt **5**; accepted package `10601978228`, selector430 **430/430**; R2 adds no second stable event |
| New candidates/obligations recorded | R2 candidate refined as hard-feature transport-domain conflation and merged into existing RP-01 event; CB4 exact-transition correction plus split-interval orientation completeness recorded in tracker/plan |
| ORIENTATION currency line | `M5-CP3-TB1-R2-REV`, 2026-09-21 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated current M5 authority/accounting, torus witness, next priority/publication state, and hard-feature traversal-vs-transition RP-01 instance; stale R1/CB3-next text removed |
| CHANGELOG | R2 independent verdict, refined root cause, accounting disposition and CB4 successor recorded |
| ROADMAP | M5-CP3 moved from R2-review-pending to recovery-required/CB4-next; no checkpoint closed |
| Selector manifest | n/a — no selector bytes, identities, publication or accepted selector authority changed |
| LESSONS | n/a — existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` and exact-carrier/source-of-truth lessons already cover the finding; no new general rule is required |
| Consolidation under CLEAN_UP_POLICY | folded CB3 report/plan, R1 runtime report/review, and consumed R2 execution plan into `M5_Consolidated_Record.md`; retained current R2 runtime report + this Review + one CB4 plan |
| Successor frozen | exactly `M5-CP3-CB4`; falsifiers are in `Architecture_M5_CP3_CB4_Hard_Feature_Transition_Transport_Correction_Plan.md` §6 |
| Turn boundary held | runtime-free; documentation/static inspection only; no product/test/fixture/selector/benchmark/build-source mutation and no Directional execution |
| review_check.py boundary | PASS — `review_check.py boundary` reports ALL CHECKS PASSED; no product/test/fixture/build or selector mutation; all retained selector hashes match baseline; 15 documentation/consolidation paths changed |
| `STATUS` lifecycle maintained | entry beacon published for `M5-CP3-TB1-R2-REV`; terminal COMPLETE beacon with sole successor `M5-CP3-CB4` is the final repository write after documentation and cleanup |
| Pushed to origin, branch in sync | control-plane confirmation is performed after documentation push and temporary-state cleanup; no self-referential commit hash is embedded here |
