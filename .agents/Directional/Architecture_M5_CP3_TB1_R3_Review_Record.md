# M5-CP3-TB1-R3 Independent Review Record

**Turn:** `M5-CP3-TB1-R3-REV`
**Boundary:** **Review / runtime-free**
**Reviewed candidate:** artifact `10624020011` / semantic source `6dd0e5179686a4ea2ca4aacda0577855948864df` — **unpromoted**
**Reviewed runtime:** run/job `35565176454 / 106225476682`; result/log artifacts `10623878370 / 10624252516`
**Accepted runtime authority:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Disposition:** **R3 EVIDENCE UPHELD / PRODUCTION AUTHORITY CUTOVER MISMATCH / EXISTING STABLE RP-01 RECURRENCE CONTINUES / RECOVERY REQUIRED**
**Exact successor:** `M5-CP3-CB5`

## 1. Review question and boundary

R3 is the fresh runtime proof of CB4's exact hard-feature transition-value correction. This Review independently decides whether the 445-process evidence is mechanically authoritative; whether test/selector authority remains protected; why CB4 still cannot restore the torus production endpoint; whether R3 creates a new stable event; and the one bounded recovery that may follow.

The Review is runtime-free. No Directional binary, test, benchmark, discovery command, configure, compile, relink, product source, test source, fixture, selector, or frozen definition is changed or executed here.

## 2. Independent R3 evidence re-derivation

The immutable artifacts were reopened from the exact downloaded bytes. Their independently re-hashed outer SHA-256 values are:

- candidate package `10624020011`: `eeba51295d20082c8f20840b3f3b280d6b6012a1178eef2bd3eb5afbfd1a0ed6`;
- result `10623878370`: `6e3c4dcdfeb379268a6b43480c2b5569f49359bb699466527b1e57ccd8faafaa`;
- diagnostic log `10624252516`: `0589830ae95f800f088e0f7392d9daa9edf3c18ddced319b88a9549369132b65`.

The result self-manifest contains **908** entries and independently verifies **908/908**. Parsing all three ledgers independently gives:

| phase | rows | PASS | RED | selected exactly 1 | skips | nonzero exit |
|---|---:|---:|---:|---:|---:|---:|
| mechanism | 9 | **9** | 0 | 9/9 | 0 | 0 |
| produced | 6 | 0 | **6** | 6/6 | 0 | 6 |
| selector430 | 430 | **429** | **1** | 430/430 | 0 | 1 |

All six produced rows independently show `torus pipeline producer failed: PeriodicHolonomyMismatch`. The sole selector RED is ordinal408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, which still receives `Rejected` instead of required `Produced`, with `NotProductionReady/tracing/None` at the pre-existing disposition assertion.

`execution-boundary.txt` independently records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`; benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation are all **0**. Package/source/execution-view byte+mode censuses are equal before/after, candidate manifest remains **28/28**, selector authority is unchanged and routing authority is unchanged.

The candidate package independently verifies root `SHA256SUMS` **28/28**, root-manifest SHA-256 `a9ccee0d830768e1d91239741bba67f4912fe86efe12cca8ddd3a13cf50f4177`, source archive `643ce57f4b23d2237d8be0d856b6e8b49229f12dc99c49ab0ff514e39bd39253`, exact semantic source `6dd0e5179686a4ea2ca4aacda0577855948864df`, preflight/build exits `0 / 0`, five empty source-status receipts, and the runtime-free GMP command boundary.

The accepted selector is independently re-hashed from exact source authority: **430 LF rows**, no CR bytes, full SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Row408 is the same frozen identity.

**Mechanical verdict:** the R3 report is upheld in full. R3 is mechanically complete semantic RED evidence, not an orchestration failure.

## 3. Test and expectation authority remains upheld

R3 repeats the same discriminating shape after a second product-only recovery:

- all nine reviewed CP1/CP2 mechanisms remain green;
- all six produced-debt identities fail while establishing the real torus production fixture, before their relation-specific debt discriminators;
- accepted ordinal408 still fails at its pre-existing required `Produced` assertion before the approved §14.4 final-kind assertions can decide anything;
- selector430 and first427 remain byte-identical;
- no test, fixture, selector or frozen definition changed between the accepted baseline and CB4's product correction.

Nothing supports weakening row408, the six produced tests, the torus fixture, CP2 checked relation failures, or selector430. The RED remains product-authority evidence.

## 4. Independent static diagnosis of the failed CB4 recovery

### 4.1 CB4's local transition validation is correct but unreachable on production authority

CB4 changed exactly `src/geometry/SurfaceCellTracing.cpp`. Its helper now preserves the exact A3 `Mandatory` carrier, derives orientation from exact source-edge parameters, indexes raw `CrossFieldEdgeTransition` records by exact source edge, checks duplicate authority, reconstructs the edge, validates the requested directed face pair and inverts the quarter-turn for reverse traversal. Those local checks are structurally faithful to the R2 correction.

The production call path, however, deliberately cuts raw cross-field containers out once the validated A1 product exists. `RemeshPipeline.cpp` constructs `FieldTransportAtlas`, installs `tracingOptions.fieldTransportAtlas`, and calls the `CrossFieldResult` overload of `build_surface_cell_network`. That overload states the production cutover explicitly: when `options.fieldTransportAtlas != nullptr`, it calls the lower overload with raw matching, effort and edge-transition pointers all `nullptr`; raw containers are the legacy/test ingress only.

CB4's `generator_route_for_span` begins by requiring `edgeTransitions != nullptr`. On the real production path this condition is therefore **deterministically false by construction**. The helper returns `nullopt` before its new edge/face-pair transition validation can run, and the first same-region promotion guard converts that absence directly to `PeriodicHolonomyMismatch`.

The candidate source file in the R3 package and the independently captured review snapshot hash identically at `c6e9e60005a5687d8d9653f5f2509973d7bb2acaca13b7cb03ffff027a420200`, so this diagnosis is against the exact semantic bytes that R3 executed.

### 4.2 The repair must preserve the A1 single-authority cutover

The correction is **not** to pass raw `edgeTransitions` alongside a production atlas and is **not** to make hard features traversable. Either move would recreate two semantic authorities or weaken barrier semantics.

`FieldTransportAtlas::make` already receives the full `CrossFieldResult`, indexes `crossField.edgeTransitions` by exact source edge, rejects duplicate records, and owns the production validation seam. The current implementation discards the transition value for hard-feature/nontraversable interior edges because barrier classification `continue`s before the adjacency-only validation/publication block. `FieldTransportAtlas::transport` later queries only traversable adjacencies, correctly returning no value for a hard feature.

The bounded repair is therefore to retain an **immutable validated edge-transition value fact** inside `FieldTransportAtlas` for interior edges independently of traversability, with a separately named directed-value query that cannot be confused with `transport()`. Atlas construction must validate exact source edge, exact two-face pair, forward/inverse quarter-turn and lift/effort once at the A1 seam before barrier/traversal classification. Traversable adjacency then reuses that validated fact; a hard feature remains in `nontraversable_edges()` but its exact transition value remains available as semantic metadata. The atlas semantic digest must cover those facts.

`generator_route_for_span` can then consume the exact carrier plus this atlas-owned nontraversal transition value without touching raw containers, searching globally, inferring from floating geometry, or changing barrier classification.

### 4.3 R2 observation is refined, not discharged

`M5-CP3-TB1-R2-REV-OBS-01` asked the next Review to confirm CB4 re-validates unique edge-transition authority, exact edge identity and directed face-pair identity at the promotion seam rather than bypassing atlas validation. The CB4 helper contains those checks, but production never reaches them because the raw pointer is intentionally null after cutover. The observation is therefore **carried/refined**: CB5 must move the validated value into the existing atlas construction seam, and the next corrected Review must independently confirm the production query reads that immutable atlas-owned fact while hard-feature traversal remains prohibited.

## 5. Classification and stable accounting

`M5-CP3-TB1-R3-CAND-01` is classified **IMPLEMENTATION AUTHORITY / PRODUCTION AUTHORITY CUTOVER MISMATCH / RECOVERY REQUIRED** and is **merged into the existing stable `M5-CP3-TB1-R1-CAND-01 / RP-01 AUTHORITY_DOMAIN_CONFLATION` event**.

R3 does not create another stable event. The tracked accepted-prefix behavior is still the same ordinal408 transition from accepted PASS to candidate RED first recorded at R1. Neither R2 nor R3 returned the candidate line to accepted-green in between. The new failure mechanism is again the same category: the correct relation datum is sourced through an authority path incompatible with the production owner boundary.

Stable accounting therefore remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**. Candidate `10624020011` remains unpromoted. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. All four M5 produced debts remain **OPEN** with zero credit; selector publication remains prohibited.

`M5-CP2-TB1-REV-OBS-01` stays carried to the first independently green corrected CP3 pre-publication Review. `M5-CP3-TB1-REV-OBS-01` remains the standing digest/provenance rule and R3 satisfies it. `M5-CP3-TB1-R2-REV-OBS-01` is refined as described above and remains open with the next corrected Review as owner.

## 6. Exact successor — `M5-CP3-CB5`

The sole successor is runtime-free Code + Build plan `Architecture_M5_CP3_CB5_Atlas_Barrier_Transition_Value_Cutover_Correction_Plan.md`.

CB5 may touch only the atlas transition-value publication/query seam and the same-region generator-route consumer: retain one validated transition-value fact per interior edge inside immutable `FieldTransportAtlas`, preserve hard-feature nontraversability, and make `generator_route_for_span` consume that atlas-owned value. The exact CB4 source-path parameter orientation remains unchanged.

The plan freezes fail-closed falsifiers before implementation. Stop if a unique exact raw transition cannot be validated at atlas construction; stop if the directed value cannot be queried without implying traversability; stop if the value cannot participate in the atlas semantic digest; stop if the correction requires raw production ingress, fallback search/inference, test/fixture/selector/frozen-definition changes, CP2 weakening, or any cross-region/materializer behavior change.

A statically faithful, GMP compile/package-green CB5 routes to a **fresh** artifact-only `M5-CP3-TB1-R4-EXEC`, restarting all **9 + 6 + 430 = 445** processes from process 1 with benchmark **0** and no R1/R2/R3 semantic-credit reuse.

## 7. Review process note

This Review initially read several repository documents directly before choosing `READ_MODE`, crossing the mandatory snapshot threshold in `TOOL_USE_CONSERVATION_POLICY.md`. The miss was recorded rather than normalized: piecemeal inspection stopped, exact snapshot run `35568075974` / job `106233819251` was captured, artifact `10625021405` (`7a343af60bb418d19f4602d39266e0f6c082eabc88ffe17c5d228e7ce0418995`) was downloaded once, and its source manifest verified **5301/5301** before all subsequent cross-file inspection. This is control-plane process evidence only and creates no product regression/accounting change; it is another instance of the existing setup-order/snapshot-threshold lesson.

## 8. Consolidation

Per `CLEAN_UP_POLICY.md`, this Review folds the superseded CB4 build report/plan, R2 runtime report/Review and consumed R3 execution plan into `M5_Consolidated_Record.md` after preserving their durable facts here, in the tracker, changelog, orientation and family record. Current authority retained after consolidation is the R3 runtime report, this Review, the CB5 plan, frozen/consolidated records and byte-frozen selectors.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` |
| Decisive claims independently re-derived | R3 outer artifact hashes; result self-manifest 908/908; 9/9 + 0/6 + 429/430 ledger vector; exact-one/zero-skip; immutable postflight; zero prohibited counters; candidate 28/28 GMP package; production atlas cutover and CB4 raw-pointer guard |
| Non-vacuity checked | six produced rows reach the real torus fixture and fail before debt assertions; row408 fails at its pre-existing `Produced` assertion; nine mechanism controls remain green; static call-path proves the CB4 transition checks are unreachable specifically because production publishes the atlas and nulls raw transition ingress |
| Prior obligations discharged/carried | R3 candidate merged into existing R1 stable RP-01 event; four M5 produced debts open; `M5-CP2-TB1-REV-OBS-01` carried; `M5-CP3-TB1-REV-OBS-01` standing rule satisfied; `M5-CP3-TB1-R2-REV-OBS-01` refined/carried to corrected Review |
| Stable accounting | **50 / 14 / 36**, debt **5**; accepted package `10601978228`, selector430 **430/430**; R3 adds no second stable event |
| New candidates/obligations recorded | `M5-CP3-TB1-R3-CAND-01` classified production-authority cutover mismatch and merged into RP-01; CB5 atlas-owned barrier transition-value correction frozen |
| ORIENTATION currency line | `M5-CP3-TB1-R3-REV`, 2026-09-21 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated current M5 authority, torus witness, CB5 priority, carried publication/debt state, production cutover RP-01 instance and snapshot-threshold process instance |
| CHANGELOG | R3 independent verdict, root cause, accounting and CB5 successor recorded |
| ROADMAP | M5-CP3 moved from R3-review-pending to reviewed recovery-required/CB5-next; no checkpoint closed |
| Selector manifest | n/a — no selector bytes, order, owner census, publication or accepted selector authority changed |
| LESSONS | existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` and setup-order/snapshot-threshold lessons cited; no new general rule required |
| Consolidation under CLEAN_UP_POLICY | folded CB4 report/plan, R2 runtime report/Review and consumed R3 execution plan; retained current R3 runtime report + this Review + one CB5 plan |
| Successor frozen | exactly `M5-CP3-CB5`; falsifiers are in `Architecture_M5_CP3_CB5_Atlas_Barrier_Transition_Value_Cutover_Correction_Plan.md` §6 |
| Turn boundary held | runtime-free; static/document review only; no product/test/fixture/selector/benchmark/build-source mutation and no Directional execution |
| review_check.py boundary | PASS — `review_check.py boundary` reports ALL CHECKS PASSED; no product/test/fixture/build or selector mutation |
| `STATUS` lifecycle maintained | entry beacon published for `M5-CP3-TB1-R3-REV`; terminal COMPLETE beacon with sole successor `M5-CP3-CB5` is the final repository write after durable docs and cleanup |
| Pushed to origin, branch in sync | control-plane confirmation is performed after documentation push and temporary-state cleanup; no self-referential commit hash is embedded here |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** The reachability diagnosis is correct and re-derives from bytes, the continuation
accounting is right, and CB5 targets the one remaining location that can hold the value. Accounting holds at
**50 events / 14 categories / 36 recurrences**, debt **5**. One normative-recording finding is raised.

### V1 — the unreachability claim is exact

`RemeshPipeline.cpp:7869` sets `tracingOptions.fieldTransportAtlas = &*fieldTransportAtlasProduct;`, and there is
**no assignment of `tracingOptions.edgeTransitions` anywhere in `RemeshPipeline.cpp`** — the field keeps its
default null on the production path. CB4's helper opens by requiring `edgeTransitions != nullptr`, so on
production that guard is deterministically false by construction, exactly as §4.1 states. The corrected code is
never entered.

R3's tallies are unchanged from R2 — mechanism **9/9**, produced **0/6**, selector430 **429/1** with ordinal 408
the sole selector RED and all six produced rows reporting `PeriodicHolonomyMismatch` — which is precisely what an
unreachable fix predicts: nothing moved.

### V2 — this is "passed vs did not run", and the green rows helped hide it

Worth naming plainly, because it bears on how the next correction is judged. CB4's code was not sloppy: it
implemented the seam re-validation `M5-CP3-TB1-R2-REV-OBS-01` required — unique edge-transition authority, exact
edge identity, directed face-pair identity, failing closed. That work is correct. It has simply never executed.

The nine mechanism rows stayed **9/9 green** throughout, because they construct options directly and do supply
raw containers; only the produced rows and row408 traverse the real pipeline. So the mechanism suite's
continued green was not evidence that the repair worked — it was compatible with the repair never running at all.
`LESSONS.md` 160 applies directly: **passed is not the same as did not run.**

The operative consequence: **a correction's reachability on the production path must be established before its
internal correctness is worth assessing.** For CB5 that means demonstrating the new atlas query is reached by
`generator_route_for_span` on the production configuration — the one where `fieldTransportAtlas` is installed and
raw containers are absent — not merely that it returns the right value when called. §4.3 is therefore right that
`M5-CP3-TB1-R2-REV-OBS-01` is **refined, not discharged**: validation that has never run is not validated.

### V3 — three failures, but this is convergence by elimination, not thrashing

Three consecutive failed recoveries deserve a judgment rather than a shrug, since the alternative reading is that
frozen §14.3's representation is itself wrong. The record supports convergence:

- **R1** eliminated *synthesised* transport (whole-region rotation reconstruction);
- **R2** eliminated the wrong *authority domain* (`FieldTransportAtlas::transport`, traversal-only, which
  excludes hard-feature carriers by design);
- **R3** eliminated the wrong *source container* (raw `crossField.edgeTransitions`, cut out of the production
  path by the A1 single-authority cutover).

Each attempt removed a distinct wrong provider for the same value, and none of the three was refuted by the
representation rule — only by where the value was fetched from. The remaining candidate is the one place that
provably both holds the data and survives the cutover: I verified at `M5-CP3-TB1-R2-REV` that
`FieldTransportAtlas::make` builds `transitionByEdge` at `:1912-1923`, with validation, **before** the
hard-feature exclusion at `:1963`. The value is already computed and already validated inside the atlas; CB5 only
has to retain and publish it as a non-traversal fact. The search space is now small and the target is
evidence-backed.

### V4 — RECORDED: the atlas's published contract is being extended by review record alone

`Architecture_M5_Frozen_Definitions.md` was last amended at `af233057`, the R1 review. §14 has not been touched
since, and it governs CP3 same-region periodic promotion.

CB5 will change what `FieldTransportAtlas` **publishes** — retaining a validated transition-value fact for
interior edges and exposing a separate non-traversal query. That is a change to a product's public contract, and
its sole authority is this Review record. Note also that CB4's own plan forbade exactly this ("no change to
`FieldTransportAtlas` implementation or any public header"); the prohibition is being lifted one turn later by a
different document.

The substance is sound — separating transition **value** from **traversability** is a real distinction, the atlas
already computes and validates the value, and §4.2 is explicit that hard features must not become traversable and
that the A1 single-authority cutover is preserved. I am not disputing the direction. The gap is where it is
written. This is the recurring pattern recorded as `M4-CP4-TB3-REV-OBS-01`: **a turn reliably amends the document
it is working in, and unreliably amends the document that governs it.**

Left as is, a later reader of §14 finds the A1 barrier invariant — hard-feature edges are not traversable —
sitting beside a new atlas query that returns data for hard-feature edges, with no frozen text reconciling the
two. That reads as a weakened barrier to anyone who did not follow this turn sequence.

**Required before CB5's result is accepted, not before CB5 runs:** record in the frozen definitions that
`FieldTransportAtlas` retains a validated non-traversal transition value for interior edges, that this is
distinct from traversability, and that `FieldTransportBarrierKind::HardFeature` and the A1 barrier contract are
unchanged. Recorded as `M5-CP3-TB1-R3-REV-OBS-01`.

### V5 — successor scope and verification limits

CB5's plan is tightly bounded and carries real stop rules: three authorized files; no test, fixture, benchmark,
selector, frozen-definition, CMake or `RemeshPipeline` change; §14.2's same-region promotion preconditions
preserved exactly; and explicit stops if scope must widen beyond the three files or if a declaration-only
adjustment outside them proves necessary. Requiring R4 to restart the complete **9 + 6 + 430 = 445** process
sequence from process 1, with no reuse of R3 credit, is also correct.

Re-derived from repository bytes: the `fieldTransportAtlas` installation at `RemeshPipeline.cpp:7869`, the
absence of any `tracingOptions.edgeTransitions` assignment in that file, the frozen-definitions amendment history,
and CB5's authorized-path and stop-rule text. Accepted as reported: R3 artifact hashes, the 908-row self-manifest,
the 28/28 package manifest, run/job identifiers and execution-boundary receipts.
