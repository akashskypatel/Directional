# M5-CP3-TB1-R15-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R15-R1-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on CB17 candidate `10742798135 / 1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`
**Disposition:** **MECHANICALLY COMPLETE / SEMANTIC RED / 446 PASS + 2 RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R15-R1-REV`

## 1. Immutable authority

R15-R1 consumed only the CB17 compile-green candidate, frozen routing/selector authority, and the CB18-frozen executor:

- semantic source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- candidate artifact `10742798135`, ZIP SHA-256 `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- candidate root manifest SHA-256 `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, **28/28**;
- packaged source archive SHA-256 `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` and first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing owner census **31 / 283 / 75 / 41**;
- canonical harness SHA-256 `7867e779ee1d276617cbf7c0e1a9910dbd5b7388a5fe6bde7aac32a47efb81b7`.

The canonical caller was installed byte-for-byte before the marker trigger. Trigger/event SHA is `f6a740a38bff6abee6c42973551f747addd41692`. No process, PASS, ledger row, or semantic observation from either invalid R15 attempt was carried forward.

## 2. Runtime and evidence authority

Workflow run/job `35869756879 / 107210502570` completed successfully as orchestration. Schema validation also passed. Runtime-job success means the frozen executor completed its mechanical contract; it is not a claim of semantic green.

Authoritative artifacts:

- result artifact `10755930241`, ZIP SHA-256 `949920d13a6b256ceaad3934c9667df17098243c59075a914156ae5c635cf3e5`;
- log artifact `10755397122`, ZIP SHA-256 `ad04fa61f4fc9e4d81da632a40f730785d3ace11b4f3e6645f130d1b14423f00`.

The result contains exactly **921 actual non-manifest files** and **921 `SHA256SUMS` rows**; every row verifies. `SHA256SUMS` itself hashes to `05b6ae8befc542937485679310f47a57f6fa400a71638807525d730563779d79`.

The execution boundary records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, **18** nonselector processes, **430** selector processes, and **448** total. Benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start are all false. Candidate package, packaged source and execution-view censuses are unchanged; candidate manifest remains **28/28** after runtime.

## 3. Fresh 448-process semantic ledger

All **448/448** prescribed processes executed freshly. Every process selected exactly one GTest and recorded zero skips.

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| mechanism / semantic | 11 | 0 | 11 |
| focused atlas | 1 | 0 | 1 |
| produced CP3 | 4 | 2 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **446** | **2** | **448** |

Benchmark count is **0**. Protected selector ordinals **191, 192, 247 and 408 all PASS**.

The CB17 discriminating mechanism identity `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` is now PASS inside a complete mechanically valid ledger. This is runtime evidence only; formal disposition of `M5-CP3-DEFN-R1-REV-OBS-01` belongs to Review.

Produced rows 13/14/15/18 PASS. Produced rows 16/17 are the only RED processes:

- process 16, `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`;
- process 17, `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`.

## 4. Exact observed RED frontier

EXEC reports the preserved assertions without choosing a root cause.

### 4.1 Produced row 16

The nonzero-Z4 witness reaches a published relation, then records these mismatches before the fatal stop:

1. independently directed `witness.generatorRoute` differs from `relation->route()`;
2. independently derived `witness.sourceRotation` is quarter-turn **3**, while `relation->action().rotation` is quarter-turn **1**;
3. fatal `ASSERT_EQ(relation->cutRoute(), forwardEdge->route)` fails.

Because the third check is fatal, row 16 does **not** reach the later endpoint-state checks, independent Forward -> Reverse comparator/inverted-pair falsifier, materialization, or selected-certificate checks. Therefore EXEC does not discharge the reopened R6 direction observation or either nonzero-Z4 product debt.

### 4.2 Produced row 17

The produced relation exists, but the first fatal witness check fails: `witnessFixture.witness.generatorRoute != published->route()`. The process therefore does **not** reach its source-rotation assertion, transform-only tamper, or expected typed `NonReciprocalPeriodicRelation` rejection.

Review must determine whether these observed mismatches are product semantics, representation/orientation expectation, or another authority-boundary issue. EXEC does not infer that answer from the assertion names or values.

## 5. Accounting and acceptance disposition

R15-R1 is mechanically valid semantic RED. It supersedes R14 as the latest mechanically valid CP3 runtime evidence, but does **not** promote the CB17 candidate. Accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`.

EXEC makes no stable-regression adjudication, no debt discharge, no observation closure, no selector publication, and no candidate promotion. Stable accounting therefore remains **51 events / 14 categories / 37 recurrences**, produced-witness debt **3**, pending mandatory Review.

The corrected exact-one parser is exercised over all 448 processes with exact-one selection and zero skips, supplying the runtime evidence required by `M5-CP3-TB1-R15-REV-OBS-01`; closure remains Review-owned.

## 6. Operational deviation — accidental duplicate trigger

After the authoritative run above had already completed, been recorded, and had its temporary caller/marker retired, a resumed session failed to reconcile that completed repository state before reinstalling the same frozen caller and triggering a second run, `35878323220` at event SHA `bb994ebecf064c034808823faa00b4f9b9bf866b`. This was an agent orchestration mistake. It is **not** a permitted retry and has **zero semantic, ledger, selector, debt, recovery, or promotion authority regardless of its eventual result**. The authoritative R15-R1 execution remains exclusively run/job `35869756879 / 107210502570` and artifacts `10755930241 / 10755397122`.

Once recognized, the accidental caller and marker were retired workflow-first to prevent any further trigger. No product, test, fixture, selector, candidate, or reusable-workflow semantic bytes were changed by the duplicate trigger.

## 7. Successor

Exact successor is runtime-free **`M5-CP3-TB1-R15-R1-REV`**. Review must independently reopen result/log bytes and manifests, verify the 446/448 vector and immutable boundary, adjudicate the row16/17 route/rotation/cut-route evidence without assuming its cause, dispose the carried R6 / DEFN-R1 / parser / CP2-publication observations and nonzero-Z4 debts, and decide candidate/promotion/publication successor authority.
