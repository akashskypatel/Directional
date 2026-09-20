# M5-CP1-TB1-R2 Independent Review Record

**Turn:** `M5-CP1-TB1-R2-REV`
**Canonical turn:** Independent Review + Plan / runtime-free
**Reviewed report:** `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Report.md`
**Reviewed candidate package:** `10595705100` / semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Accepted runtime authority:** M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**
**Decision:** **R2 runtime upheld; focused ordinal 6 is a test-authority witness-precondition defect, not a demonstrated product semantic defect; candidate remains unpromoted**
**Planning successor:** `M5-CP1-CB3` under `Architecture_M5_CP1_CB3_Test_Authority_Correction_Plan.md`

## 1. Scope and review boundary

This Review re-opens the immutable R2 runtime evidence, candidate packaged source and frozen M5 contract. It does not rerun Directional, does not repair the candidate, and does not mutate product, test, fixture, selector, benchmark or build source.

The only question being adjudicated is the sole R2 RED:

`M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`

The Review must distinguish a bad witness from a semantic implementation defect before any Code + Build correction is authorized.

## 2. Independent immutable-evidence re-derivation

Review independently re-opened the R2 result and diagnostic artifacts rather than relying on the execution report's summary.

- result artifact `10598684066` ZIP SHA-256: `5896fee5600a6f842fcefd08534d2a21a67cedee8a38ed67daaeace755d2a5dd`;
- diagnostic artifact `10599222908` ZIP SHA-256: `cabfa52286f006572181c8a0368562b1ec31591061431be7b6fe2055951ac016`;
- focused ledger SHA-256: `07646ddbb8bb4d7e4900981901a846576a0e943a8388a74060f128e2117ad645`;
- selector ledger SHA-256: `e571138329ce808a9bab9544640548bcb73def54b93475918a24833f3968d6c0`;
- ordinal-6 raw receipt SHA-256: `68ef89b40caab7818f4aedc3ce2078dbde564eae713257ef56fac28666bfb586`.

The ledgers independently reproduce:

- focused **8/9 PASS / 1 RED**;
- selector430 **430/430 PASS**;
- exact-one selection and zero skips on all **439** processes;
- benchmark execution **0**;
- package/source/execution-view immutability exact after runtime;
- candidate manifest **28/28** after runtime;
- configure/compile/relink/discovery/repair/mutation counters all false.

Candidate artifact `10595705100` independently re-hashes to `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`. Its packaged source archive re-hashes to `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9` and identifies source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`.

The sole RED is reproduced exactly: ordinal 6 selects one test, skips zero and fails at `SurfaceCellTransitionQuotientTests.cpp:1449` because `reorderedDraft.periodicHolonomies.size()` is **1**, not at least **2**. The test exits before the relation container is reversed, before either materialization, and before any certificate comparison.

## 3. Source-side adjudication

### 3.1 The one-relation state is authored witness authority

`direct_full_periodic_materializer_draft()` starts from the committed cylinder-backed materializer fixture, scans its current relation table, rewrites the first eligible relation to a nonzero-Z4 action, and then `break`s. It does not add a second relation. R2's observed **1 relation** is therefore the helper's authored state, not evidence that relation canonicalization dropped a second relation.

The failing assertion is a precondition the test itself never establishes.

### 3.2 Existing runtime separates the witness defect from product semantics

Two neighboring R2 rows provide independent discriminators.

1. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate` is **PASS**. Its test constructs a second distinct valid relation from the same materializable authority, appends it, reverses the relation container, materializes, and verifies the selected-certificate signature and materialized hash are unchanged. This proves the materializer tolerates an unrelated second relation at a different storage position without reselecting semantic certificate authority.
2. `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` is **PASS** with the direct helper's explicit **2 relations / 2 owned periodic edges** discriminator. It proves canonical relation-owner binding survives container reversal at the checked phase-front product boundary.

Neither row substitutes for ordinal 6: row7 changes table membership as well as order, while row9 stops before materialization. Together they show that the implementation seams needed by a corrected pure-permutation witness are present and currently green.

### 3.3 Static implementation review finds no relation-vector-order semantic dependency at the owned seam

At the checked phase-front product boundary, `SurfacePhaseFrontProduct::make(...)` rebuilds a `std::map<PeriodicRelationId, ...>` and validates periodic edge ownership by canonical ID. In `build_authoritative_phase_front_mesh(...)`, periodic relation lookup is again rebuilt as a map keyed by canonical `PeriodicRelationId`; periodic front pairs select their relation through the edge's declared ID rather than a vector position.

Selected path certificates are then constructed from the actual selected quotient joins. Their adjacency is canonicalized by occurrence index before path extraction; relation-table vector position does not participate in the semantic lookup or path selection. The remaining `periodicHolonomies().front()` use in the reviewed source is diagnostic publication, not materialization authority.

The Review therefore finds **no product semantic implementation gap demonstrated by the R2 RED**.

## 4. Correct witness and classification

A valid, minimal pure-permutation witness already has a proven construction pattern in row7:

1. start from `direct_full_periodic_materializer_draft()`;
2. derive one distinct valid unused relation from the existing owner by swapping the owner carrier routes exactly as row7 does;
3. append that relation to the **baseline** table;
4. copy that complete table to the reordered draft;
5. prove the table has at least two distinct IDs and that reversing it changes the first stored ID;
6. reverse only the reordered draft's relation storage;
7. materialize both identical-membership drafts;
8. require both to succeed and compare complete selected-certificate signatures, `hash_completion(...)`, and consumed-periodic-relation counts.

This holds membership and product semantics fixed while changing only representation order, which is the row6 invariant frozen by `Architecture_M5_Frozen_Definitions.md` §§3.2, 4, 5.2 and 7.

`M5-CP1-TB1-R2-EXEC-CAND-01` is therefore adjudicated:

**CLOSED / `RP-02 TEST_AUTHORITY_COVERAGE_GAP` / INVALID WITNESS PRECONDITION / NON-STABLE / TEST-ONLY CORRECTION REQUIRED.**

The correction belongs in test source only. It must not change `direct_full_periodic_materializer_draft()`, product code, fixtures, selectors, CMake, or the M5 semantic contract.

No accepted-green product behavior regressed. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. Candidate `10595705100` remains unpromoted and accepted M4 runtime authority remains unchanged.

## 5. Carried obligations and credit boundary

- `M5-CP1-TB1-PREFLIGHT-REV-OBS-01` remains carried to **M5-CP3**: produced re-proof identities must be distinguishable from the already accepted direct/helper rows whose names match the four open M5 debts.
- `M5-DEFN-REV-OBS-01` remains carried to **M5-CP3**: milestone closure must reconcile `DESIGN.md` §14 with the frozen M5 definitions and grant no direct/helper production credit.
- `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` remains M5-CP1 mechanism / M5-CP3 direct-production debt with the original `>=2` produced-relations / `>=2` owned-periodic-edges discriminator.
- `MissingPeriodicRelationOwnerIsRejected` remains M5-CP2 mechanism / M5-CP3 direct-production debt.
- `FullPeriodicRotationAndTranslationMaterialize` and `TamperedFullPeriodicTransformIsRejected` remain M5-CP3 direct-production debts on nonzero-Z4 authority.
- The separate closed-complex produced-witness debt remains M6-owned.

R2 row9 remains mechanism-only. This Review closes no produced-witness debt.

## 6. Exact successor

`M5-CP1-CB3` is the sole authorized successor under `Architecture_M5_CP1_CB3_Test_Authority_Correction_Plan.md`.

CB3 is **test-authority-only Code + Build**. It may edit only the body of ordinal-6's test in `tests/SurfaceCellTransitionQuotientTests.cpp` as bounded by the plan, then must use the mandatory reusable GMP compile/package workflow with no Directional runtime. Product code, shared materializer helpers, fixtures, selectors, CMake and build semantics remain frozen.

If CB3 packages green, its successor is fresh `M5-CP1-TB1-R3-EXEC`, which must execute the full focused **9** plus selector430 **430** gate from ordinal 1 with zero benchmarks and immutable postflight. R3 does not inherit R2's failed ordinal-6 result.

## 7. Consolidation

Under `CLEAN_UP_POLICY.md`, this Review folds three superseded/consumed M5 per-turn records after their durable facts are preserved in this record, the runtime report, `M5_Consolidated_Record.md`, tracker, changelog and handoff:

- `Architecture_M5_CP1_TB1_Preflight_Review_Record.md` — 204 lines;
- `Architecture_M5_CP1_CB2_Orchestration_Correction_Report.md` — 88 lines;
- `Architecture_M5_CP1_TB1_R2_Artifact_Only_Test_Benchmark_Plan.md` — 94 lines.

Their exact filenames and verdicts are indexed in `M5_Consolidated_Record.md`; full text remains recoverable from git history.

The retained current M5 role set is: current R2 runtime report, this Review record, exactly one CB3 next-turn plan, consolidated family record, normative frozen definitions, and all byte-frozen selectors.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | **YES** — R2 artifact authority independently retains selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; accepted first427 prefix remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. No selector changes in Review. |
| Decisive claims independently re-derived | **YES** — result/log ZIP hashes, focused and selector ledger hashes/counts, ordinal-6 raw receipt, package/source hashes, helper control flow, row7/row9 witness behavior and product-side ID-keyed lookup were re-opened from immutable bytes/source. |
| Non-vacuity checked | **YES** — row6 currently cannot reach its claimed invariant; the corrected witness must contain >=2 distinct IDs, prove reversal is nontrivial, materialize both identical-membership tables and compare certificates/output. Row7 and row9 independently show the constituent mechanisms are reachable. |
| Prior obligations discharged/carried | **CAND-01 root cause adjudicated and closed non-stably; `M5-CP1-TB1-PREFLIGHT-REV-OBS-01`, `M5-DEFN-REV-OBS-01`, four M5 production debts and one M6 debt carried to their existing owners.** |
| Stable accounting | **49 events / 14 categories / 35 recurrences; debt 5; accepted package `10591801825`; selector430 430/430.** |
| New candidates/obligations recorded | **No new stable/candidate regression.** Existing CAND-01 is closed with test-only corrective owner `M5-CP1-CB3 -> M5-CP1-TB1-R3-EXEC`; tracker updated. |
| ORIENTATION currency line | **UPDATED to `M5-CP1-TB1-R2-REV` / 2026-09-20 UTC.** |
| ORIENTATION §3 / §4 / §7 / §8 | **§3, §7 and §8 updated; §4 unchanged because no production witness state changed. Superseded R1-next text removed from current-state sections.** |
| CHANGELOG | **UPDATED** — agent and root changelogs record Review adjudication and CB3 successor. |
| ROADMAP | **UPDATED** — M5 CP1 now records R2's trustworthy 8/9 + 430/430 result, Review's test-authority adjudication and CB3 next. |
| Selector manifest | **n/a — no selector added, accepted, renamed or mutated.** |
| LESSONS | **No new lesson.** This is an instance of existing structural-presence/non-vacuity discipline (`LESSONS.md` 171): a test name and precondition do not establish exercised behavior. |
| Consolidation under CLEAN_UP_POLICY | **COMPLETE** — the 204-line preflight Review, 88-line CB2 report and 94-line consumed R2 plan are folded/indexed; current runtime report, this Review, CB3 plan, frozen definitions and selectors remain. |
| Successor frozen | **YES — `M5-CP1-CB3`**, with authorized edit, falsifiers and stop rules in `Architecture_M5_CP1_CB3_Test_Authority_Correction_Plan.md`. |
| Turn boundary held | **YES — runtime-free review/documentation only; no product/test/fixture/selector/benchmark/build-source mutation.** |
| review_check.py boundary | **PASS — durable boundary check and selector430 expectation pass on the prepared Review tree.** |
| `STATUS` lifecycle maintained | **YES — Review entry beacon was published before substantive repository mutation; final COMPLETE beacon is reserved as the last repository write.** |
| Pushed to origin, branch in sync | **YES — the reviewed documentation/consolidation patch is applied on the configured working branch, branch authority is re-read after push, and no unapplied Review document delta remains before final STATUS closeout.** |
