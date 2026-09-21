# M5-CP3-TB1-R1 Review Record

**Turn:** `M5-CP3-TB1-R1-REV`
**Boundary:** **Independent Review / runtime-free**
**Reviewed execution:** `M5-CP3-TB1-R1-EXEC`
**Verdict:** **R1 EVIDENCE UPHELD / IMPLEMENTATION-AUTHORITY DEFECT / CANDIDATE UNPROMOTED / CORRECTION REQUIRED**
**Exact successor:** `M5-CP3-CB3`

## 1. Entering authority and review question

Accepted runtime authority entering this Review is unchanged:

- package `10601978228`;
- semantic source `0798547dedd8be05f9cd7a096b07e6bd94755316`;
- selector430 **430/430 PASS** at SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- owner census **31 / 283 / 75 / 41**;
- stable accounting **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

The reviewed candidate is artifact `10615252806` / semantic source `fc2aa5fa68cac890051614c2104979aef4a60d21`. It is compile/package green but unpromoted.

The Review question is not whether corrected R1 was mechanically valid; its report already claims that. The question is whether independent evidence supports the **9/9 mechanism, 0/6 produced, 429/430 selector** vector, and whether the shared torus production failure belongs to implementation authority, test/expectation authority, or a contract defect.

## 2. Independent evidence re-opened

### 2.1 Fresh R1 artifacts

Review independently re-opened run `35548642817` and re-downloaded both authoritative artifacts:

- result artifact `10617583137`, provider/download SHA-256 `264f1cc1428e4b91c388aa3281df471730dd84dc621b4e87a0b3c0bad5ef3f37`;
- diagnostic-log artifact `10616998978`, provider/download SHA-256 `1970c9f24c1f00a2f165b85dc28daaec831d6b8d92f707e7a5aa69bca5163790`.

The result `SHA256SUMS` verifies **908/908** files. Independent parsing of the three ledgers re-derives:

| Gate | Rows | PASS | RED | selected | skipped |
|---|---:|---:|---:|---|---|
| mechanism | 9 | **9** | 0 | exactly 1 on every row | 0 on every row |
| produced | 6 | 0 | **6** | exactly 1 on every row | 0 on every row |
| selector430 | 430 | **429** | **1** | exactly 1 on every row | 0 on every row |
| **total** | **445** | **438** | **7** | exact-one | zero-skip |

The sole selector RED is ordinal408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`.

The six produced logs independently contain the same producer stop:

```text
PeriodicHolonomyMismatch
```

Ordinal408 independently fails at its production-disposition assertion: expected `SurfaceCellProducerDisposition::Produced`, received `Rejected`, with `NotProductionReady/tracing/None`. It therefore fails **before** the CB2-evolved final-kind assertions.

The execution boundary independently reads:

- `preflight_completed=true`;
- `runtime_started=true`;
- `runtime_completed=true`;
- `orchestration_failure=false`;
- benchmark/configure/compile/relink/discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all **0**.

The immutable postflight independently states package/source/execution-view census equality, root manifest **28/28**, selector unchanged and routing map unchanged.

Review also recomputed the decisive evidence hashes; they match the execution report exactly: mechanism ledger `4c1825481f4711eba54c94318a27cc497ee4a2465ed505b46d82f8f313c6f440`, produced ledger `4d93fb6c21461ee4cae7df92240f407b58f4c24452e61e0f641ae47e24c52067`, selector ledger `59a5e84c4f430588111b1e06985226ce270ba9999c3fb28a6ef59ddfdf713074`, semantic summary `1ba52250e80700b680d44b46dfce26201808473d132ac86f2f92f074de1d9d86`, execution boundary `fd9f6be2d29eacfbb67e71f542166d088defd0a8dd0f0902c868818cccba7438`, and immutability receipt `41aece7634f1d0667902a6080573e1fd7624b8e2bd4e79d74e2e8f660fe70f85`.

### 2.2 Fresh exact source snapshot

Review selected snapshot inspection and materialized source-snapshot run/job `35551565555 / 106187165350` at event/source snapshot SHA `36ac4859193b6fb217f9f50aae21f28cb5da54fa`. Artifact `10618532494` has provider SHA-256 `b7ffe7ff1e4c78d97f81311989beb4fa2dc573d415daf05df420bdc9b0c5a7a3`; its inner `source.tar.gz` hashes to `9832cc57e030c57d5257d7524b8e633a626cecfa78ac006ad63b4618f3d0daf0` and its 5300-file manifest verifies.

A commit comparison from candidate semantic source `fc2aa5fa68cac890051614c2104979aef4a60d21` to the snapshot SHA contains documentation/control-plane changes only. No `src/`, `include/`, `tests/`, `benchmarks/`, CMake, or selector semantic bytes changed after the candidate source. Static inspection of the snapshot is therefore evidence about the tested candidate semantics.

### 2.3 Accepted package re-opened

Review also re-downloaded accepted runtime package `10601978228`, verifies its **28/28** package manifest, and independently reads semantic source `0798547dedd8be05f9cd7a096b07e6bd94755316` from package metadata.

Comparing accepted semantic source to candidate source shows only four semantic files changed for CP3:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/FieldAlignedCurveNetworkTests.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

That bounded diff is sufficient to adjudicate implementation versus test authority without attributing a failure to an unrelated subsystem.

## 3. Accepted selector prefix independently re-hashed

From the exact source snapshot:

- selector430 LF SHA-256 = `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- exact first427 prefix LF SHA-256 = `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

These are unchanged accepted authority. No selector beyond 430 is authorized or published by this Review.

## 4. Test authority is upheld and non-vacuous

The semantic RED is **not** a test-expectation defect.

### 4.1 Accepted row408 fails before its reviewed evolution

Frozen §14.4 preserves row408's committed torus subject, exact 18-source-edge hard-feature equality, A0-A3 path, conformity evidence and production reachability. The only approved test evolution is its final representation check: exact A3 intervals must now appear on a complete reciprocal `PeriodicCut` pair rather than final `HardRail` edges.

The candidate row408 body still proves the exact 18-edge torus authority and reaches the producer-disposition assertion first. R1 receives `Rejected` there. None of the evolved `PeriodicCut` assertions executes. Changing those assertions cannot make this RED green and would weaken the frozen production-reachability contract.

### 4.2 All six produced identities share the real production subject

`torus_fixture()` is backed by `make_torus_pipeline_fixture()`, which executes the committed torus through `remesh_from_raw_cross_field`, retains the produced trace-network snapshot and calls `require_produced(...)` before any relation-specific test assertion. The fixture uses the same 18-edge row408 hard-feature authority.

Therefore the six `M5CP3.Produced...` rows are not direct/helper substitutions. Their common `PeriodicHolonomyMismatch` occurs while establishing the production subject, before their separate relation-order, missing-owner, nonzero-Z4, transform-tamper and unused-valid-relation discriminators. A test-only adjustment would make the production debts vacuous instead of repairing the product.

### 4.3 Mechanism evidence remains independently green

All nine frozen CP1/CP2 mechanism rows PASS on the same candidate. This excludes a broad loss of canonical-ID, certificate-container, or checked factory mechanics and localizes the semantic loss to the CP3 production construction added after accepted package `10601978228`.

## 5. Root cause: implementation violates frozen §14.3 authority

The frozen contract is explicit. `Architecture_M5_Frozen_Definitions.md` §14.3 requires promotion to:

1. resolve the A3 interval `span` through accepted `GlobalTopologyPlan` arc/source-path authority;
2. convert **that exact path** through existing transition/atlas authority into the generator carrier;
3. use the produced paired-edge canonical route as cut carrier;
4. derive one complete `GridAutomorphism` from authoritative route rotation plus exact chart-lattice correspondence, satisfying both reciprocal endpoint-state pairs.

The candidate implementation does something materially different.

### 5.1 Unauthorized whole-region rotation reconstruction

`atlas_rotation_between_faces` builds a graph from **all** `FieldBranchTopology::transports()` inside the topology region and breadth-first assigns accumulated face rotations. If an already-seen face is reached with a different accumulated rotation, it returns no value.

That is a whole-region path-independence requirement. It is not the selected A3 `span` path and is not authorized by §14.3. For a periodic subject, the nontrivial cycle transport is precisely information the relation is meant to represent; requiring one globally path-independent regional rotation can reject that information before the selected carrier is constructed.

### 5.2 Carrier and transport are then sourced from different authorities

`generator_route_for_span` does read `GlobalTopologyArc::sourcePath` for carrier/orientation identity, but it assigns identity transport to every transition step except the first and injects the separately reconstructed aggregate rotation into that first step. The route therefore does **not** carry the step-by-step transport published by transition/atlas authority along the exact source path.

The candidate has an existing directed branch-transport API (`FieldBranchTopology::transport(...)`) and other established transition lookup paths. Whether those current products contain sufficient directed information for every exact A3 support step is an implementation question for the correction turn; if they do not, the correction must stop rather than inventing another search.

### 5.3 Classification boundary

The R1 logs collapse several relation-construction stops into `PeriodicHolonomyMismatch`. This Review **does not claim which individual `if` branch dynamically fired**. The implementation-authority classification does not require that guess: the candidate's relation-construction algorithm is statically inconsistent with the frozen exact-path authority, it is the only new product seam common to the seven torus production REDs, accepted row408 proves the old production path was green, and all nine downstream relation mechanisms remain green.

**Disposition:** `M5-CP3-TB1-R1-CAND-01` is **CLASSIFIED / IMPLEMENTATION AUTHORITY / EXACT-SPAN TRANSPORT CONTRACT VIOLATION / NON-STABLE / RECOVERY REQUIRED**.

## 6. Candidate, debt and publication decisions

Candidate `10615252806` is **not promoted**. Accepted runtime authority remains package `10601978228` under selector430 **430/430**.

All four M5 produced-witness debts remain **OPEN**. R1 earns no produced-witness credit because the production subject does not reach `Produced`.

`M5-CP2-TB1-REV-OBS-01` is **carried**, not discharged. Its own falsifier requires every publication identity to have been independently reviewed green on the exact candidate. R1 has six produced REDs and selector row408 RED, so pre-committing a successor selector now would violate the frozen governance sequence. Ownership moves to the first independently green corrected CP3 pre-publication Review, expected `M5-CP3-TB1-R2-REV` after the bounded correction and fresh full pre-publication runtime.

`M5-CP3-TB1-REV-OBS-01` remains the standing process rule for frozen literal length/provenance checks. The new CB3 plan contains no newly invented artifact digest authority; future execution plans must continue applying the rule.

No stable accepted-green behavior was lost. Stable accounting remains **49 / 14 / 35**, debt **5**.

## 7. Exact successor — `M5-CP3-CB3`

The sole successor is runtime-free Code + Build plan `Architecture_M5_CP3_CB3_Exact_Span_Transport_Correction_Plan.md`.

Its bounded correction is product-only: replace the whole-region rotation reconstruction / synthesized aggregate route transport with exact `span`-path conversion through existing transition/atlas authority while preserving §14.2 promotion preconditions, CP2 validation, cross-region HardRail behavior, row408, all six produced test bodies, fixtures and selector430.

Its principal falsifier is explicit: **if the exact A3 source path does not contain enough authority to resolve one unique directed transition/transport sequence without global search or guessing, CB3 stops and returns to Review.** It may not solve that absence by changing tests, selector, frozen definitions, or by inventing relation transport.

A green compile-only CB3 routes to a fresh full artifact-only `M5-CP3-TB1-R2-EXEC`; no R1 semantic credit is reused.

## 8. Process and boundary note

At turn entry the required `STATUS` bootstrap was performed first. The turn then violated the tool-conservation pre-read gate by reading several repository documents before explicitly fixing `READ_MODE=snapshot`, even though the review obviously exceeded the three-file threshold. The turn stopped further piecemeal source inspection, recorded the miss here, switched to the durable source-snapshot workflow, verified that snapshot, and based the static adjudication above on the materialized exact snapshot. This is a control-plane efficiency/process miss, not semantic evidence, and no product/test/fixture/selector byte was mutated by it.

No Directional runtime, build, compile, benchmark or generated discovery was executed by this Review.

## 9. Consolidation

Per `CLEAN_UP_POLICY.md`, durable facts from superseded CP3 per-turn records are preserved here, in `M5_Consolidated_Record.md`, the root-cause tracker, ORIENTATION, changelog and git history before folding. The folded-document index records the exact retired filenames and line counts. Current retained roles after consolidation are:

- current runtime report: `Architecture_M5_CP3_TB1_R1_Artifact_Only_Test_Benchmark_Report.md`;
- current Review: this record;
- sole next-turn plan: `Architecture_M5_CP3_CB3_Exact_Span_Transport_Correction_Plan.md`;
- family history: `M5_Consolidated_Record.md`;
- normative semantics: `Architecture_M5_Frozen_Definitions.md`;
- all byte-frozen selectors unchanged.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` |
| Decisive claims independently re-derived | Fresh R1 result/log downloads; 908/908 self-manifest; 9/9, 0/6, 429/430 ledger vector; exact-one/zero-skip; immutable postflight; candidate-vs-accepted semantic diff; frozen §14.3 authority mismatch |
| Non-vacuity checked | row408 fails at required `Produced` assertion before evolved final-kind checks; six produced rows use the real pipeline fixture and fail before relation-specific assertions; nine mechanism controls remain green |
| Prior obligations discharged/carried | `M5-CP3-TB1-R1-CAND-01` classified implementation-authority/recovery-required; `M5-CP2-TB1-REV-OBS-01` carried to first corrected green pre-publication Review (expected R2 Review); four M5 produced debts remain open; `M5-CP3-TB1-REV-OBS-01` remains standing process rule |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10601978228`, selector430 **430/430** |
| New candidates/obligations recorded | No new stable candidate; existing `M5-CP3-TB1-R1-CAND-01` reclassified with owner `M5-CP3-CB3`; tracker updated |
| ORIENTATION currency line | `M5-CP3-TB1-R1-REV`, 2026-09-21 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | Updated current M5 boundary, torus witness state, next priority, and exact-carrier-vs-global-transport recurring instance; superseded R1-review-pending text removed |
| CHANGELOG | Review verdict, classification and successor recorded |
| ROADMAP | M5-CP3 updated from review-pending to implementation-correction-required; no checkpoint closed |
| Selector manifest | n/a — no selector added, changed, published or accepted |
| LESSONS | No new lesson; this is an instance of existing single-authority/exact-transport guidance, including Lesson 58 (`Never publish a guessed value as authority`) |
| Consolidation under CLEAN_UP_POLICY | Folded superseded CB2 report, blocked TB1 report, corrected R1 execution plan and predecessor TB1 Review into `M5_Consolidated_Record.md` index after durable preservation |
| Successor frozen | exactly `M5-CP3-CB3`; falsifiers and stop rules are in `Architecture_M5_CP3_CB3_Exact_Span_Transport_Correction_Plan.md` §6 |
| Turn boundary held | runtime-free; documentation/control-plane only; no product/test/fixture/selector/benchmark/build-source mutation |
| review_check.py boundary | **PASS** on the prepared Review documentation/consolidation diff with selector430 expected hash; recorded before remote application |
| `STATUS` lifecycle maintained | entry beacon written before other repository mutation; final COMPLETE beacon is reserved as the final repository write after documentation and cleanup |
| Pushed to origin, branch in sync | Closeout control requires final branch-authority confirmation after documentation/cleanup and the final `STATUS` write; no commit hash is embedded in this record |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld on every technical finding; one accounting classification is corrected.** The root-cause
analysis, the defence of test authority, the produced-subject proof and the candidate/debt decisions all stand.
Stable accounting is corrected to **50 events / 14 categories / 36 recurrences**; produced-witness debt remains
**5**.

### V1 — the technical adjudication is right, and right for the right reasons

This Review does the hard thing: it declines the easy verdict. A semantic RED on a candidate that also evolved a
test body invites a test-authority classification, and §4 refuses it on evidence.

- **§4.1** — the candidate row408 body still proves the exact 18-edge torus authority and fails at the
  **producer-disposition assertion**, which is pre-existing; none of the evolved `PeriodicCut` assertions ever
  execute. The R1 report confirms it: ordinal **408** expected `SurfaceCellProducerDisposition::Produced`.
- **§4.2** — the six `M5CP3.Produced…` rows run on `torus_fixture()` backed by `make_torus_pipeline_fixture()`
  through `remesh_from_raw_cross_field`, so they are genuine production subjects, not `direct_*` helper
  substitutions. That is the §13.4 boundary holding under pressure.
- **§4.3** — all nine CP1/CP2 mechanism rows PASS on the same candidate, which localises the defect instead of
  permitting a vague "something broke" story.
- **§5.3** — the Review explicitly declines to claim which `if` branch fired. Refusing to over-specify a root
  cause the logs cannot resolve is the correct discipline.

The §5 diagnosis — carrier identity read from `GlobalTopologyArc::sourcePath` while transport is synthesised by
whole-region rotation reconstruction — is `RP-01 AUTHORITY_DOMAIN_CONFLATION` in its textbook form: two halves of
one semantic object sourced from different authorities.

### V2 — CORRECTION: this is a stable event; accounting moves to 50 / 14 / 36

§6 states "No stable accepted-green behavior was lost. Stable accounting remains **49 / 14 / 35**." That is
incorrect, and the evidence defeating it is this Review's own §4.1.

The durable criterion, recorded in `Regression_Root_Cause_Tracker.md`, is mechanical:

> A stable event is recorded when an ordinal inside the **accepted selector prefix** transitions PASS → RED,
> regardless of whether the failing package is promoted. New unaccepted rows cannot produce one, and "the failing
> bytes are on an unpromoted package" is not a valid reason for non-stable — it would make the rule unfirable.

Every element is satisfied:

1. **Inside the accepted prefix.** Ordinal 408 of selector430,
   `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, verified at line 408 of
   the byte-frozen accepted selector.
2. **Was PASS.** selector430 ran **430/430** at `M4-CP4-TB3`, again at `M5-CP1-TB1-R3` and again at `M5-CP2-TB1`.
3. **Is now RED.** R1 records selector430 at **429 PASS / 1 RED**, ordinal 408 the sole selector RED.
4. **Lost behaviour, not a raised bar.** This is the one that could have excused it, and §4.1 closes it: the
   failure occurs at the **pre-existing** producer-disposition assertion, *before* any evolved assertion runs. The
   candidate lost behaviour that accepted authority had already proved — it did not merely fail a new one.

The §14.4 body evolution therefore does not exempt this row. Had row408 failed on an evolved `PeriodicCut`
assertion, non-stable would have been right; it failed on the assertion it has always made and always passed.

**Corrected accounting: 50 events / 14 categories / 36 recurrences**, debt **5**. The category is the existing
`RP-01 AUTHORITY_DOMAIN_CONFLATION`, so no new category opens and the count stays at 14. `M5-CP3-TB1-R1-CAND-01`
keeps its classification — implementation authority / exact-span transport contract violation — and its
disposition changes only from NON-STABLE to **STABLE / RP-01 recurrence**.

Nothing else moves: the candidate stays unpromoted, accepted authority remains package `10601978228` under
selector430 **430/430**, all four M5 produced debts stay OPEN with no credit, and `M5-CP2-TB1-REV-OBS-01`
remains correctly carried because no publication identity is green on this candidate.

Recording the event is not a criticism of the work. A stable event marks that a candidate lost accepted
behaviour, so the pattern stays visible across turns; that the cause is authorised in-progress CP3 work, already
localised, and already has a bounded correction plan does not exempt it. The rule was made durable at
`M4-CP-SCALE-TB6-REV` precisely so it could not be argued away by circumstance.

### V3 — successor scope and verification limits

`M5-CP3-CB3` is product-only, replacing whole-region rotation reconstruction with exact `span`-path conversion
through existing transition authority, and carries an explicit stop: if the exact A3 source path cannot resolve
one unique directed transition/transport sequence without global search or guessing, CB3 stops. That is the right
falsifier, and it is the second time in this checkpoint a plan has pre-committed the condition for abandoning
itself. No R1 semantic credit may be reused; a fresh full `M5-CP3-TB1-R2-EXEC` is required.

Re-derived from repository bytes: row408's identity at selector line 408, selector430's 430 rows and SHA-256, its
427-row prefix, and the R1 gate tallies as reported in the retained runtime report. Accepted as reported: R1
artifact hashes, run/job identifiers and package receipts.
