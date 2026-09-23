# M5-CP3-TB1-R15-R1 Independent Review Record

**Turn:** `M5-CP3-TB1-R15-R1-REV`
**Date:** 2026-09-23 UTC
**Boundary:** runtime-free independent Review
**Reviewed execution:** `M5-CP3-TB1-R15-R1-EXEC`
**Verdict:** **APPROVED WITH AMENDMENTS / MECHANICS UPHELD / TEST-AUTHORITY ROOT CAUSE PROVED / NON-STABLE +0**

## 1. Independent evidence re-opened

Review re-opened the authoritative R15-R1 evidence rather than relying on the EXEC summary.

- run/job: `35869756879 / 107210502570`, event SHA `f6a740a38bff6abee6c42973551f747addd41692`;
- candidate/source: `10742798135 / 1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- result artifact `10755930241`, independently re-hashed ZIP SHA-256 `949920d13a6b256ceaad3934c9667df17098243c59075a914156ae5c635cf3e5`;
- log artifact `10755397122`, independently re-hashed ZIP SHA-256 `ad04fa61f4fc9e4d81da632a40f730785d3ace11b4f3e6645f130d1b14423f00`;
- candidate ZIP SHA-256 `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- candidate root manifest `28/28`, SHA-256 `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`;
- packaged source archive SHA-256 `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- selector430 / first427 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

The result self-manifest is independently complete: **921 rows for 921 non-manifest files**, all rows verify, and `SHA256SUMS` itself hashes to `05b6ae8befc542937485679310f47a57f6fa400a71638807525d730563779d79`.

The execution boundary independently records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, exactly **18 + 430 = 448** executed processes, and all benchmark/configure/compile/relink/discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start flags false. Package/source/execution-view censuses are unchanged and the candidate manifest remains **28/28** after runtime.

The fresh semantic vector is therefore upheld exactly:

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| mechanism / semantic | 11 | 0 | 11 |
| focused atlas | 1 | 0 | 1 |
| produced CP3 | 4 | 2 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **446** | **2** | **448** |

Protected selector ordinals **191, 192, 247 and 408 all PASS**. Every ledger row selected exactly one GTest with zero skips. Benchmark count is **0**.

The later accidental duplicate run `35878323220` is explicitly **non-authoritative / zero-credit** and is excluded from this Review regardless of its outcome. The authoritative ledger is only `35869756879`.

## 2. RED frontier independently re-derived

Only produced processes 16 and 17 are RED.

### 2.1 Row 16 — materialization witness

`M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` reaches a published periodic relation. Before its fatal stop, raw evidence records:

1. the independent semantic generator route differs from `relation->route()`;
2. expected semantic source/relation turn is quarter-turn **3**, while the stored relation action carries quarter-turn **1**;
3. fatal `relation->cutRoute() == forwardEdge->route` fails.

The fatal third assertion prevents the test from reaching its endpoint-state checks, independent Forward -> Reverse comparator, materialization, certificate selection or consumed-holonomy checks.

### 2.2 Row 17 — tamper witness

`M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` finds the published relation but fatally fails `witness.generatorRoute == published->route()` before it reaches the source-rotation check, transform-only tamper, or exact typed `NonReciprocalPeriodicRelation` rejection.

Thus neither nonzero-Z4 produced debt is discharged by R15-R1.

## 3. Root cause — storage representation is being compared as semantic direction

The RED is a **test-authority defect**, not a proved product semantic defect.

Frozen §16.3 distinguishes semantic Forward -> Reverse relation authority from canonical storage representation. It requires the semantic action `T` to be derived first; canonical storage may retain `T` or store `T^-1` while reversing both routes. Deterministic semantic resolution must recover `T` from A3 Forward/Reverse roles. For the committed torus witness the independently frozen semantic relation turn is **`Q=3`**.

The CB17 candidate implements that representation rule directly:

- `canonicalize_periodic_holonomy(...)` compares an action with its inverse and, when the inverse is canonical, stores the inverse action with both routes reversed;
- `insert_periodic_holonomy(...)` always canonicalizes before storage;
- `resolve_periodic_relation_semantic_action(...)` returns the stored action when stored cut-route orientation agrees with semantic Forward, and returns the inverse stored action when the stored cut route is reversed relative to semantic Forward.

The valid R15-R1 ledger independently exercises `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` and it **PASSes**. That focused identity deliberately finds a storage-canonical relation whose stored cut route aligns with semantic Reverse, verifies `stored.action().inverse()` is the semantic action, and proves recanonicalizing the semantic representative returns the same stored relation.

Rows16/17 do not use that semantic-resolution rule. They compare `relation->route()`, `relation->action().rotation`, and `relation->cutRoute()` directly against semantic Forward -> Reverse witness facts. Their observed values are the exact signature of canonical inversion: semantic `Q=3`, stored turn `1 = 3^-1 mod 4`, and stored cut-route orientation opposite the semantic Forward edge. Their preconditions therefore reject a valid canonical representation before reaching the product falsifiers those tests are supposed to own.

### Classification

`M5-CP3-TB1-R15-R1-CAND-01` is **CAUSE PROVED / TEST-AUTHORITY STORAGE-REPRESENTATION CONFLATION / NON-STABLE / +0 / OWNER M5-CP3-CB19**.

This is another instance of the existing `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` and existing ORIENTATION rule that canonical storage orientation is not semantic directed authority. It creates **no new stable event/category/recurrence** and requires no new LESSONS number.

## 4. Required correction and non-vacuity

Exactly one bounded correction is authorized: **test-only `M5-CP3-CB19`**. Product, fixture, field, A3, selector, frozen-definition and benchmark semantics are fixed.

For rows16/17, CB19 must bind the exact semantic Forward/Reverse edge pair first, then resolve the stored relation into semantic direction deterministically:

- use `resolve_periodic_relation_semantic_action(stored, forward, reverse)` and require success;
- determine semantic generator-route orientation from the same exact cut-route/Forward alignment: stored route when stored cut route equals Forward route, reversed stored route when reversed stored cut route equals Forward route; any other case fails closed;
- compare the **semantic** route and action against independent witness authority;
- compute relation endpoint expectations and Forward -> Reverse equations from the semantic action, not directly from the storage representative;
- preserve row16's materialization/certificate/consumed-holonomy discriminator unchanged after representation normalization;
- preserve row17's one-transform tamper and exact `NonReciprocalPeriodicRelation` discriminator unchanged after representation normalization.

No best-of-two search, inverse chosen by downstream success, fixture retuning, weaker assertion, alternate relation selection, or product correction is authorized.

Non-vacuity is mandatory: CB19 must prove the corrected tests actually encounter the inverted-storage case (`stored action != resolved semantic action` and the corresponding route orientation differs) before their final product discriminators. Otherwise a green rerun would not prove the stale representation assumption was removed.

## 5. Prior obligations

| Obligation | Disposition |
|---|---|
| `M5-CP3-DEFN-R1-REV-OBS-01` | **DISCHARGED.** The CB17 `Q != A` mechanism identity is present and passes inside a mechanically valid complete ledger; it also falsifies omission of either accepted occurrence gauge. Mechanism-only: no produced-debt credit. |
| `M5-CP3-TB1-R15-REV-OBS-01` | **DISCHARGED / RUNTIME-PROVED.** CB18 statically replayed the corrected parser against literal protocol bytes; R15-R1 then exercised that frozen parser over all 448 exact-one/zero-skip processes with a complete ledger. The evidence-parser replay rule remains durable process guidance. |
| `M5-CP3-TB1-R6-REV-OBS-01` | **OPEN / CARRIED TO R16 REVIEW.** Row16 still dies before the independent Forward -> Reverse comparator and inverted-pair rejection. |
| `M5-CP2-TB1-REV-OBS-01` | **OPEN / CARRIED.** Frozen §13.3 still requires one complete corrected green CP3 pre-publication gate plus independent Review before selector publication precommitment. |
| `M5-DEFN-REV-OBS-01` | **OPEN / CARRIED TO M5 CLOSURE/PUBLICATION OWNER.** R15-R1 does not alter its closure condition. |
| nonzero-Z4 produced debt: genuine rotation+translation materializes | **OPEN.** Row16 does not reach materialization. |
| nonzero-Z4 produced debt: transform-only tamper rejects typed | **OPEN.** Row17 does not reach tamper/rejection. |
| `M5-CP3-TB1-R13-REV-OBS-01` | **REMAINS DISCHARGED AS TRIGGERED.** |
| `M5-CP3-TB1-R14-REV-OBS-01` | **REMAINS DISCHARGED AT DEFN-R1.** |

## 6. Acceptance and successor

R15-R1 is accepted as the latest mechanically valid CP3 runtime evidence, **not** as a green CP3 gate. CB17 candidate `10742798135 / 1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3` remains unpromoted. Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

Stable accounting remains **51 events / 14 categories / 37 recurrences**, produced-witness debt **3**. No selector publication or precommitment is authorized.

Exactly one successor is frozen: **`M5-CP3-CB19`**, test-only and runtime-free. If CB19 compiles/packages green, fresh artifact-only `M5-CP3-TB1-R16-EXEC` must rerun the same 448 identities with benchmark 0, followed by mandatory `M5-CP3-TB1-R16-REV`. No R15-R1 PASS/row/selector credit may be stitched into R16.

## 7. Process deviations recorded

Two process/tool deviations occurred in this Review and are recorded rather than hidden:

1. Several repository documents were fetched directly before the mandatory `READ_MODE` choice was explicitly established. Once recognized, piecemeal inspection stopped and the turn switched to `READ_MODE=snapshot`; substantive cross-file review used verified source snapshot run/artifact `35880135798 / 10761020219` at event/snapshot SHA `5c745f486d32434986b70440d538d3f5125616e8`.
2. During local snapshot verification, `SHA256SUMS` was initially checked before `source.tar.gz` had been extracted, producing expected missing-file messages. The archive was then extracted and the complete 5301-file manifest verified successfully. No repository or runtime evidence was mutated.

These are control-plane/process deviations only and contribute no product evidence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 rows retained exactly. |
| Decisive claims independently re-derived | Re-hashed authoritative result/log ZIPs and candidate ZIP/source archive; verified 921/921 result manifest, 28/28 candidate manifest, 448-process vector, protected selector rows, immutable boundary; inspected raw rows16/17 and exact candidate canonicalization/semantic-resolution code plus frozen §16.3. |
| Non-vacuity checked | R15-R1 executes every row exactly once; row16/17 stop before their final product discriminators because stale tests compare a storage representative as semantic direction. CB19 is precommitted to demonstrate the inverted-storage case before the final discriminator. |
| Prior obligations discharged/carried | DEFN-R1 mechanism observation and R15 parser observation discharged; R6 direction, CP2 publication, M5-DEFN closure and both nonzero-Z4 produced debts carried. |
| Stable accounting | **51 events / 14 categories / 37 recurrences**, debt **3**; accepted package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; selector430 unchanged. |
| New candidates/obligations recorded | `M5-CP3-TB1-R15-R1-CAND-01` cause-proved as non-stable test-authority storage-representation conflation, owner `M5-CP3-CB19`, +0. No new stable event. |
| ORIENTATION currency line | `M5-CP3-TB1-R15-R1-REV`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated to Review authority, CB19 priority, R15-R1 witness disposition, and existing canonical-storage-not-semantic-direction pattern; no new pattern category. |
| CHANGELOG | Current Review adjudication + CB19 successor recorded in both live changelogs. |
| ROADMAP | M5-CP3 updated to Review-complete test-authority diagnosis / CB19 next. |
| Selector manifest | n/a — no selector byte added, changed, accepted or precommitted. |
| LESSONS | No new number; existing canonical-representation/semantic-authority and test-authority/non-vacuity guidance applies. |
| Consolidation under CLEAN_UP_POLICY | Superseded R14 runtime report, superseded R15 Review, consumed CB18 plan/report, and consumed R15-R1 execution plan folded/indexed into `M5_Consolidated_Record.md`; current R15-R1 runtime report + this Review + one CB19 plan retained. |
| Successor frozen | Exactly one successor: `M5-CP3-CB19`; correction scope, falsifiers, prohibitions and R16 requirement are frozen in `Architecture_M5_CP3_CB19_Storage_Canonical_Produced_Test_Correction_Plan.md`. |
| Turn boundary held | Yes — runtime-free Review; no Directional binary executed; no product/test/fixture/selector/benchmark semantic byte mutated. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** on the complete 15-document Review/consolidation diff; no product/test/fixture/build/selector mutation. |
| `STATUS` lifecycle maintained | Entry beacon published for `M5-CP3-TB1-R15-R1-REV`; terminal COMPLETE -> `M5-CP3-CB19` reserved for final repository mutation. |
| Pushed to origin, branch in sync | **PENDING patch publication/cleanup/final authority check.** |
