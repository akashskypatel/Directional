# M5-CP1-TB1 Preflight Independent Review Record

**Turn:** `M5-CP1-TB1-PREFLIGHT-REV`
**Canonical turn:** Independent Review + Plan / runtime-free
**Reviewed report:** `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Report.md`
**Reviewed candidate package:** `10595705100` / semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Accepted runtime authority:** M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**
**Decision:** **TB1 blocker upheld; both frozen-plan defects independently proved and corrected in a retry plan; candidate remains unpromoted**
**Planning successor:** `M5-CP1-TB1-R1-EXEC` under `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md`

## 1. Scope and assumptions

This Review adjudicates only the two pre-runtime orchestration defects recorded by `M5-CP1-TB1-EXEC`. It does not infer runtime behavior from compile success, does not repair the immutable package, and does not change product, test, fixture, benchmark, build, or selector bytes.

The smallest valid correction is routing-only: keep the same candidate package, same nine focused obligations, same accepted selector430 predecessor, and the same mechanism-only evidence boundary; correct only the malformed accepted identity-map digest and the nonexistent exact-filter suite qualification.

## 2. Independent immutable-authority re-derivation

### 2.1 Accepted M4 identity-map authority

Review re-opened accepted M4-TB3 result artifact `10592987234` rather than copying the blocked report's value. Its downloaded ZIP re-hashes to:

`352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`

The artifact's `identity-map.tsv` independently re-derives as:

- **431 lines = one header + 430 data rows**;
- **430 unique identities**;
- owner census **31 authority-kernel / 283 producer / 75 completion / 41 validation = 430**;
- SHA-256 **`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`**.

The frozen TB1 plan literal ending in `...cf6` is exactly 63 hexadecimal characters. `M5-CP1-TB1-CAND-01` is therefore proved as a plan-authority defect. The corrected value is independently derived from immutable bytes; it is not obtained by appending a character to the prior literal.

### 2.2 Candidate package and exact ninth identity

Review independently re-opened candidate artifact `10595705100`. Its ZIP re-hashes to **`fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`**, and the package root `SHA256SUMS` verifies **28/28**. The packaged source archive verifies at **`4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`**.

Exact packaged source contains:

`SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`

and does **not** contain the frozen plan identity:

`M4CP4.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`.

The real test body calls `direct_periodic_owner_product()`, asserts two periodic holonomies, two edges, two distinct relation-owner snapshots, and then verifies owner semantics survive relation-container reversal. The helper itself manually constructs exactly two relations and two `PeriodicCut` edges before creating a `SurfacePhaseFrontProduct`. This is deliberately distinct from the adjacent production test `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering`, which starts from `torus_fixture().network.phaseFront.product()`.

`Architecture_M5_Frozen_Definitions.md` §8.1 classifies the direct helper witness as **mechanism-only, no produced-witness credit**. `M5-CP1-TB1-CAND-02` is therefore proved as an exact-filter routing defect, and the corrected identity may earn only CP1 mechanism credit. It cannot discharge the M5-CP3 production debt.

### 2.3 Accepted selector prefix re-check

The immutable candidate packaged source contains selector430 as exactly **430 LF rows** at SHA-256 **`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`**. Its first 427 rows independently hash to accepted selector427 **`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`**. No selector byte changes in this Review.

## 3. Adjudication

The blocked TB1 turn behaved correctly. Its frozen plan demanded literal authority equality and exact-one test selection; silently fixing either literal inside EXEC would have collapsed the authority/execution boundary. Zero semantic credit was therefore the correct outcome.

Both candidate IDs close as **ORCHESTRATION / FROZEN-PLAN AUTHORITY / NON-STABLE / RECOVERY PROVED BY REVIEW**:

- `M5-CP1-TB1-CAND-01` — independently re-derived accepted identity-map SHA-256 is the 64-character value ending `...cf6c`;
- `M5-CP1-TB1-CAND-02` — independently re-derived packaged identity is suite `SurfaceCellTransitionQuotient`, not `M4CP4`.

No accepted-green product behavior regressed, no Directional runtime ran, and the candidate package remains unpromoted. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt remains **5**, and accepted runtime authority remains M4 package `10591801825` under selector430.

`M5-CP1-TB1-EXEC-OBS-01` is also discharged for this instance: the corrected retry plan now freezes only literals independently verified against immutable artifacts/source. The process rule remains durable for future plans.

## 4. Non-vacuity and debt boundary

The corrected ninth focused identity remains discriminating because its direct helper contains two distinct relation owners and two owned periodic edges before reorder; deleting relation discrimination or owner preservation would make its assertions fail. That is sufficient for **CP1 mechanism** evidence.

It is insufficient for the carried produced-witness debt. The frozen M5 contract requires `M5-CP3` to re-prove `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` on **produced** authority with at least two distinct produced relations and at least two owned periodic edges. The retry plan repeats that prohibition explicitly. The other three M5 production debts and the separate M6 debt are unchanged.

## 5. Corrected successor plan

`Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md` is the sole next-turn plan. Relative to the blocked plan it changes only:

1. the accepted M4-TB3 identity-map SHA-256 to the independently re-derived 64-character value `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c` and freezes accepted routing artifact `10592987234` / ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
2. focused row 9 to `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`.

The focused count remains exactly **9** and the accepted predecessor remains selector430 exactly **430** rows. Artifact `10595705100`, source `b98f461b...`, all other focused identities, order, static audit, postflight, stop rules, zero-benchmark boundary, and no-production-debt rule remain unchanged.

## 6. Consolidation and boundary

Under `CLEAN_UP_POLICY.md`, the prior M5 definition review record, consumed CP1 Code + Build plan/report, and defective original TB1 plan are folded into `M5_Consolidated_Record.md`. The current TB1 blocked report is retained as the latest execution report; this Review record and exactly one corrected next plan are retained alongside normative M5 definitions and byte-frozen selectors.

This Review executes no generated Directional binary, test, benchmark, configure, compile, relink, discovery, or semantic runtime. It changes documentation/planning only.

Operational note: this web session began repository document inspection before the mandatory `READ_MODE=snapshot` declaration and before completing the workflow-policy read. The miss was corrected before semantic editing: one exact source snapshot (`79fcc7d75ace06fb431d2271e8f0feb3359b2562`, snapshot run `35483563438`, artifact `10596237455`) became the subsequent repository-content authority. This is another instance of the existing read-mode/control-plane process discipline, not a semantic regression. Context compaction did not preserve the exact tool-call ledger count; per policy the turn reports that ledger as **partial/unknown** rather than spending calls to reconstruct it.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | **YES** — selector430 `1c412850...9db6`; first427 `f9c88380...e86f`, unchanged. |
| Decisive claims independently re-derived | **YES** — M4 result ZIP/map hash + 430-row/owner census; M5 candidate ZIP + 28/28 manifest; exact packaged test identity/body/helper classification. |
| Non-vacuity checked | **YES** — corrected row9 directly asserts 2 relations / 2 edges / 2 distinct owners before reorder; production-debt credit remains prohibited because the subject is a direct helper. |
| Prior obligations discharged/carried | **CAND-01/CAND-02 and EXEC-OBS-01 discharged for routing; four M5 production debts + one M6 production debt carried unchanged.** |
| Stable accounting | **49 events / 14 categories / 35 recurrences; debt 5; accepted package `10591801825`; selector430 430/430.** |
| New candidates/obligations recorded | **NONE semantic.** Current-turn read-mode sequencing miss recorded as an instance of existing process discipline; no new stable/candidate regression class. |
| ORIENTATION currency line | **UPDATED to `M5-CP1-TB1-PREFLIGHT-REV` / 2026-09-20 UTC.** |
| ORIENTATION §3 / §4 / §7 / §8 | **§3, §7 and §8 updated; §4 unchanged because no witness state changed.** |
| CHANGELOG | **UPDATED** — root and agent changelogs record Review adjudication and corrected retry plan. |
| ROADMAP | **UPDATED** — M5 CP1 compile remains green/runtime unadjudicated; corrected R1 is exact next. |
| Selector manifest | **n/a — no selector added, accepted, renamed, or mutated.** |
| LESSONS | **No new lesson — the literal-validation rule is retained as `M5-CP1-TB1-EXEC-OBS-01`; read-mode miss is an existing process pattern.** |
| Consolidation under CLEAN_UP_POLICY | **COMPLETE** — three superseded/consumed M5 per-turn records folded/indexed; current TB1 report, this Review, corrected next plan, normative definitions and selectors retained. |
| Successor frozen | **YES — `M5-CP1-TB1-R1-EXEC`**; falsifiers/stop rules are frozen in `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md` §§2,6,8. |
| Turn boundary held | **YES — runtime-free documentation/static review only; no product/test/fixture/build/selector mutation.** |
| review_check.py boundary | **PASS** — `python3 .agents/Directional/tools/review_check.py boundary --expect-selector 430=1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; all review boundary checks passed. |
| `STATUS` lifecycle maintained | **YES — entry beacon published for this turn; final COMPLETE beacon reserved as final repository write.** |
| Pushed to origin, branch in sync | **PENDING patch publication/control-plane cleanup; must be verified before final STATUS.** |
