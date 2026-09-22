# M5-CP3-TB1-R10 Independent Review Record

**Turn:** `M5-CP3-TB1-R10-REV`
**Boundary:** **runtime-free independent Review**
**Decision:** **approved_with_amendments**
**Verdict:** **R10 MECHANICAL/SEMANTIC EVIDENCE UPHELD FOR DIAGNOSIS / RESULT SELF-MANIFEST INVALID FOR ACCEPTANCE OR PROMOTION / CB11 RAW-FAMILY DEFECT CLOSED AS THE SPECIFIC DEFECT / R=0 PRESERVATION PROVED / NEW A3-DIRECTION INSERTION-ORDER AUTHORITY DEFECT PROVED / CB12 PRODUCT CORRECTION FROZEN**
**Exact successor:** `M5-CP3-CB12`

## 1. Authority independently reopened

Review selected `READ_MODE=snapshot` before substantive repository source/document inspection. The Review source snapshot is run/job/artifact `35694159757 / 106637287056 / 10679775872`, event/snapshot SHA `50bc8b90fe54dd36b271d06c89f8c15f13ae508f`, provider artifact digest `sha256:02e8ff1bd29e12b6e54ea758c170adf3f9990e8c9ea2251cf63d64d13c52578a`, internal source archive SHA-256 `562ee66035a46ccca7f46cd5da1db6fc117abe3f8ac4c41836dcd07a83466034`, file count **5299**, `runtimeExecution=false`. Review independently verifies the snapshot manifest **5299/5299**.

R10 consumed CB11 candidate artifact `10678487447` built from exact semantic source `53a21f550cf67e643e8c67a633bb63a20b055c6a`. Candidate ZIP SHA-256 is `60c4a643cd4a56c70c5fd0674a0df110c501deffe32e244795213a33c96afc3`; root `SHA256SUMS` SHA-256 is `5f009791f3d237383a472bd1d5c4b50ca771b5f6e5d66295d99726cdd857e364` and verifies **28/28**; packaged source archive SHA-256 is `fcd122a41bdcf64010e3c732c1fba89624815b304803e31c114c56018c5dd6b8`.

Review independently compares candidate packaged source to the current Review snapshot over `src`, `include`, `tests`, `benchmarks`, `cmake`, and root `CMakeLists.txt`: **393 files vs 393 files, zero missing, zero extra, zero changed**. Current static findings therefore apply to the exact semantic code executed by R10.

R10 runtime authority is run/job `35691705806 / 106629921249`, event SHA `30442127abca653cec25149eaae09b801c40687f`. Original result/log artifacts are `10679167694 / 10678548342` with provider/download SHA-256 `e07be4438185a3deb1548799175d52ac24934649a7846015667fdecf2ecb4251 / 66e742acfec2e23558fb57443154080b295c682ac7fc00de254efe3f3eef77e2`.

Accepted routing/selector authority is unchanged: routing artifact `10592987234`, routing ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`. Review independently re-hashes selector430 as **430 LF-terminated rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, with exact accepted first427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

## 2. R10 mechanical evidence independently re-derived

Review independently parses every ledger row rather than copying R10's summary:

| Gate | PASS | RED | exact-one / zero-skip |
|---|---:|---:|---:|
| reviewed mechanism | **9/9** | 0 | **9/9** |
| focused retained-value atlas | **1/1** | 0 | **1/1** |
| CP3 produced | **4/6** | 2 — rows 4/5 | **6/6** |
| selector430 | **430/430** | 0 | **430/430** |
| **total** | **444/446** | **2** | **446/446** |

Benchmark execution is **0**. Produced rows1/2/3/6 remain PASS. Produced row4 `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` and row5 `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` are the only RED identities. Their raw logs independently reproduce the exact exception:

```text
torus nonzero-Z4 source witness producer failed: PeriodicActionCorrespondenceMismatch
```

Row4 raw SHA-256 is `f2b6b31bcab3d46ece9f3c68f195d4e9424c947f95161a3784346850cbafdf1a`; row5 raw SHA-256 is `28b2a44e00336368457ce82854eedaeea75e44cdfec6b515787e9a215bc170f2`.

The R10 execution boundary records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`; configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation and benchmark counters are all **0**. Candidate/package/source/execution-view postflight is exact. Nothing in Review contradicts the immutable-runtime claim.

## 3. R10 result self-manifest defect — diagnosis upheld, acceptance credit blocked

Review independently enumerates the R10 result artifact:

- **913** total files including `SHA256SUMS`;
- **912** required non-manifest evidence files;
- **911** `SHA256SUMS` rows;
- every listed row verifies;
- the sole missing non-manifest file is `driver-authority.txt`;
- `driver-authority.txt` independently hashes to `37d0dc701fd5a788b892cb1c9b4f77d3a58c428b44b55bf2bdb55751d26cd3c5`;
- `SHA256SUMS` independently hashes to `f9364f0c9945eaf4f71f05db9e02ed08109894261027ea4ae08b28f1a75747bc`.

`M5-CP3-TB1-R10-EXEC-CAND-01` is therefore **UPHELD / ORCHESTRATION-EVIDENCE MANIFEST FINALIZATION OMISSION / NON-STABLE / +0**. The cause is exact: the R10 driver generated the self-manifest before the workflow copied `driver-authority.txt`; the established R9 shape copied authority first and regenerated/verified the manifest afterward.

The artifact's immutable provider digest, the 911 verified rows, the independently hashed missing file, and the raw ledgers remain sufficient to diagnose the semantic RED. They are **not** sufficient to treat R10 as final acceptance/promotion evidence because the frozen all-non-manifest-evidence coverage contract is false. Review does not repair, repackage or rerun the original artifact. The next complete execution must restore post-copy manifest finalization and verify complete coverage before it can earn acceptance credit.

## 4. CB11's specific raw-family correction is present and its R=0 preservation falsifier passes

Exact candidate source proves CB11 implemented the R9-bounded edit: raw local `family` / `advanceSign` reciprocity remains enforced only for cross-region HardRail pairs; same-region promotion is no longer vetoed by those untransported labels before generator-route transport. `generator_route_for_span(...)`, `periodic_action_for_pair(...)`, both branch-state checks, both exact lattice endpoint equations and checked `SurfacePeriodicHolonomy::make(...)` remain intact. No inverse/search/fallback appears.

Produced rows **1, 2, 3 and 6 all remain PASS** in fresh R10. That is the exact empirical falsifier required by `M5-CP3-TB1-R9-REV-OBS-01-A`: the §16 `R=0` reduction did not regress the already-green zero-rotation production behavior. The observation is **DISCHARGED**.

`M5-CP3-TB1-R9-REV-CAND-01` is correspondingly **CLOSED AS THE SPECIFIC RAW LOCAL-GAUGE PRE-VETO DEFECT / RECOVERY PROVED FOR THAT DEFECT / NON-STABLE / +0**. This does **not** mean M5's nonzero-Z4 path is recovered; R10 proves a different source-authority defect remains.

## 5. New decisive finding — same-region directed generator authority is chosen by storage order

R10's unchanged failure string alone does not identify a cause after CB11. Review therefore does **not** infer root-cause identity from string equality. Instead, exact candidate source independently proves a distinct violation of already-frozen §§14.3 and 16.

### 5.1 Group membership is semantic; pair direction is not

`SurfaceCellTracing.cpp` builds `hardRailGroups` by iterating `result.edges` in vector order and appending `edgeIndex` to each group. For a two-edge group it binds:

```text
first  = result.edges[pair[0]]
second = result.edges[pair[1]]
```

The group checks exact reciprocal interval identity, opposite interval orientation and reverse routes, but it never semantically re-orients the two members before relation construction.

For a same-region pair, production then calls:

```text
generator_route_for_span(
    first.sharedBoundaryInterval->span,
    *first.sharedBoundaryInterval->boundaryOccurrence,
    *second.sharedBoundaryInterval->boundaryOccurrence)
```

and feeds that directed route rotation to:

```text
periodic_action_for_pair(first, second, generatorRotation)
```

Therefore the source chooses `fromOccurrence -> toOccurrence` and the action direction from **`pair[0] -> pair[1]` insertion/storage order**.

Frozen §14.3 already forbids exactly this: **“No edge/group/vector ordinal … [or] insertion order … may name or synthesize a relation.”** Frozen §16 further requires `R` in the **exact directed A3/source-path orientation**. No new definition is required; implementation violates existing authority.

### 5.2 Exact A3 direction already exists

The same source already validates each `SurfaceSharedBoundaryInterval::orientation` against exact ordinal direction, and those intervals are materialized from accepted A3 incidences. The interval comment states that `orientation` is the exact direction of the A4 chart copy relative to increasing A3 ordinals. A same-region reciprocal pair has exactly one `Forward` and one `Reverse` interval.

The independent row4/5 witness does not use product storage order. `select_torus_source_witness(...)` enumerates exact `GlobalTopologyRegion::boundary` incidences, requires exactly one `Forward` and one `Reverse` occurrence for the span, sets **Forward as `fromOccurrence` and Reverse as `toOccurrence`**, resolves exact occurrence-owned source faces, and derives the source/atlas transition in that direction. That is the direction comparator `M5-CP3-TB1-R6-REV-OBS-01` was created to protect.

### 5.3 Why zero-rotation rows did not expose it

For `R=0`, forward and inverse rotation are identical, so insertion-order reversal is invisible to the rotation value. R10 therefore can keep produced rows1/2/3/6 green while the genuine nonzero-Z4 subject remains exposed. This is exactly why an unordered membership check is insufficient authority for a directed transform.

Review does **not** claim the R10 raw log proves the first failing torus pair is stored in the wrong orientation; R10 does not emit that subclause. What is proved is stronger for correction authority: candidate source violates a frozen no-insertion-order rule at the only same-region relation direction-selection site, and the existing independent nonzero witness is designed to distinguish that direction once production advances.

### 5.4 Classification

New `M5-CP3-TB1-R10-REV-CAND-01` is **OPEN / PRODUCT + FROZEN-CONTRACT AUTHORITY / `RP-01 AUTHORITY_DOMAIN_CONFLATION` / representation-order mechanism / NON-STABLE / +0 / OWNER CB12 -> R11 REVIEW**.

The wrong authority domain is the vector/group representation used to choose a semantic A3 direction. `RP-05 REPRESENTATION_DEPENDENT_IDENTITY` is related as a mechanism, but the defect does not redefine relation identity; its primary failure is ownership of a directed fact, so `RP-01` is the correct primary class.

## 6. Non-vacuity and prior-obligation disposition

The remaining row4/5 gate is non-vacuous: before product inspection the test independently proves a genuine nonzero source transition and exact A3 Forward->Reverse direction; after production it requires exact route/action agreement, nonzero rotation **and** translation, materialization and selected-certificate consumption. Row5 then changes only action rotation under the same semantic relation ID and requires exact `NonReciprocalPeriodicRelation`. R10 fails before those discriminators, so neither M5 nonzero debt is credited.

Prior obligations are adjudicated as follows:

- `M5-CP3-TB1-R9-REV-CAND-01`: **CLOSED AS THE SPECIFIC RAW FAMILY/SIGN DEFECT / recovery proved by source + R10 R=0 preservation**. Full CP3 recovery is not implied.
- `M5-CP3-TB1-R9-REV-OBS-01-A`: **DISCHARGED** — produced rows1/2/3/6 are PASS under CB11.
- `M5-CP3-TB1-R6-REV-OBS-01`: **OPEN / CARRIED TO R11 REVIEW** — R10 still fails inside `require_produced(...)` before the independent Forward->Reverse comparator executes. CB12 must remove representation-order direction authority without inverse fallback.
- `M5-CP2-TB1-REV-OBS-01`: **OPEN / CARRIED** — no selector-publication precommitment while the corrected CP3 gate is not independently all-green.
- `M5-CP3-TB1-R9-REV-OBS-01`: **REMAINS CORRECTED / standing process rule**; this Review uses no self-attributed “independent verification addendum” section.
- `FullPeriodicRotationAndTranslationMaterialize`: **OPEN / M5**.
- `TamperedFullPeriodicTransformIsRejected`: **OPEN / M5**.
- closed-complex produced witness: **OPEN / M6**.
- `M5-CP3-TB1-R10-EXEC-CAND-01`: **UPHELD / ORCHESTRATION FINALIZATION CORRECTION REQUIRED IN NEXT TB EXECUTION**.
- `M5-CP3-TB1-R10-EXEC-CAND-02`: **ADJUDICATED / SUPERSEDED BY `M5-CP3-TB1-R10-REV-CAND-01`** as the concrete source-authority correction owner; the raw RED remains preserved as evidence.

## 7. Accounting, promotion and publication

No accepted selector identity regresses: selector430 is independently **430/430**. The new source defect is exposed only by candidate-only produced-debt identities, and the result-manifest omission is orchestration evidence rather than an accepted-product regression. Stable accounting therefore remains **50 events / 14 categories / 36 recurrences**.

Project produced-witness debt remains **3**: two M5 nonzero-Z4 debts and one M6 closed-complex debt. Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Candidate `10678487447` remains **unpromoted**. Frozen §13.3 selector publication remains **prohibited**.

No selector bytes or manifest membership change in this Review. `Required_Green_Selector_Manifest.md` therefore requires no edit.

## 8. Authoritative next Code + Build plan

Exact successor is **`M5-CP3-CB12`** under `Architecture_M5_CP3_CB12_A3_Directed_Periodic_Pair_Ordering_Correction_Plan.md`.

CB12 is product-only and runtime-free. Its sole semantic source path is `src/geometry/SurfaceCellTracing.cpp`. For a same-region reciprocal periodic pair it must derive semantic direction from exact interval/A3 orientation — **Forward occurrence/edge -> Reverse occurrence/edge** — before calling `generator_route_for_span(...)` and `periodic_action_for_pair(...)`. Pair-vector index, insertion order, edge ordinal, inverse retry, best-of-two direction search, endpoint rewriting and translation fitting are prohibited. Cross-region HardRail behavior is unchanged.

CB12 must preserve the exact pair/provenance gates, one directed generator route, atlas-owned transition value, exact branch/endpoint action correspondence, checked relation construction, hard-feature nontraversability, relation identity/certificate behavior and every existing test/selector byte. Mandatory all-eight GMP/GMPXX compile/package remains runtime-free.

If compile/package is green, the next Test + Benchmark is fresh `M5-CP3-TB1-R11-EXEC` over the unchanged **446** identities and benchmark **0**, followed by mandatory `M5-CP3-TB1-R11-REV`. R11 must also restore the established result-finalization order: copy driver authority first, regenerate `SHA256SUMS`, verify every non-manifest evidence file is covered, and fail closed on any coverage difference. If the evidence shape remains unchanged, the expected complete count is **912/912** non-manifest files.

R11's decisive semantic falsifiers are unchanged: rows1/2/3/6 remain PASS; row4 reaches the independent source/A3 Forward->Reverse comparator, proves the published generator route/action uses that exact direction rather than inverse equivalence, proves genuine nonzero rotation plus nonzero translation, materializes and consumes the selected certificate; row5 reaches its action-only tamper and exact `NonReciprocalPeriodicRelation`; mechanism 9/9, focused atlas 1/1 and selector430 430/430 remain green.

## 9. Frozen-definition disposition

No M5 semantic definition is amended. The relevant frozen claims are **not false**: §14.3 already prohibits edge/group/vector ordinal and insertion-order relation synthesis, and §16 already requires the exact directed A3/source-path rotation. R10 exposes an implementation violation of those claims, not a missing normative rule.

Only `Architecture_M5_Frozen_Definitions.md` §11's mutable current-successor pointer is advanced to CB12; §§14–16 remain semantically unchanged.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 prefix `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 LF rows. |
| Decisive claims independently re-derived | Reparsed 446 ledgers and raw row4/5 logs; recomputed 444/2 and exact-one/zero-skip; enumerated result manifest 911/912 coverage; compared 393 code-surface files candidate vs Review snapshot with zero drift; traced `hardRailGroups` insertion order through same-region generator/action direction and independently reopened the Forward->Reverse A3 witness. |
| Non-vacuity checked | Rows4/5 have independent nonzero source/A3 direction authority and downstream route/action/materialization/certificate/tamper discriminators; R10 stops before them. Rows1/2/3/6 provide the required R=0 preservation falsifier and all remain PASS. |
| Prior obligations discharged/carried | `R9-REV-CAND-01` closed as the specific raw-label defect; `R9-REV-OBS-01-A` discharged; `R6-REV-OBS-01` carried to R11 Review; `M5-CP2-TB1-REV-OBS-01` carried; R9 review-provenance process observation remains corrected; two M5 debts + one M6 debt remain open. |
| Stable accounting | **50 events / 14 categories / 36 recurrences**, project debt **3**; accepted package/source `10601978228 / 0798547d...`, selector430 **430/430**; candidate `10678487447` unpromoted. |
| New candidates/obligations recorded | `M5-CP3-TB1-R10-REV-CAND-01` = OPEN `RP-01` directed-authority/storage-order violation; R10 manifest finalization obligation carried to R11; tracker updated. |
| ORIENTATION currency line | `M5-CP3-TB1-R10-REV`, 2026-09-22 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated current CP3 state, torus witness, priority/successor and directed-authority recurring pattern; superseded CB11/R10-next bullets replaced rather than duplicated. |
| CHANGELOG | R10 Review entry added with evidence adjudication, new root cause, accounting and CB12 successor. |
| ROADMAP | M5/CP3 advanced to R10 Review complete / CB12 next; debts and publication block retained. |
| Selector manifest | n/a — no selector added, altered or accepted; current selector/prefix were independently re-hashed and remain unchanged. |
| LESSONS | Added lesson **174**: unordered membership/storage order cannot authorize a directed semantic transform; derive direction from semantic orientation before transport. |
| Consolidation under CLEAN_UP_POLICY | R9 runtime report/Review, CB11 plan/report and consumed R10 execution plan folded into `M5_Consolidated_Record.md` with exact filename/role index; R10 runtime report retained as current runtime evidence; this Review and CB12 plan become current role documents. |
| Successor frozen | Exactly `M5-CP3-CB12`; falsifiers and stop rules are in `Architecture_M5_CP3_CB12_A3_Directed_Periodic_Pair_Ordering_Correction_Plan.md`. |
| Turn boundary held | **Yes — runtime-free Review; no product/test/fixture/selector/benchmark/build semantic mutation and no Directional binary execution.** |
| review_check.py boundary | **PASS** on the prepared Review documentation/consolidation diff with selector430 expected hash; no code/selector mutation. |
| `STATUS` lifecycle maintained | `M5-CP3-TB1-R10-REV` entry and resume beacons published with `Started at=2026-09-22T06:16:00Z`; terminal COMPLETE with successor `M5-CP3-CB12` is reserved as the final repository write after durable publication/cleanup. |
| Pushed to origin, branch in sync | ChatGPT-Web connector mode has no persistent local `origin` checkout; equivalent closeout is a post-publication working-branch authority re-read after cleanup, with any unexpected head race stopping the terminal STATUS write. |
