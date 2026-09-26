# M4-CP4-TB3 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP4-TB3-EXEC`
**Disposition:** COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED
**Successor:** `M4-CP4-TB3-REV`
**Runtime authority after EXEC:** unchanged pending mandatory Review; accepted M4 authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**.

## 1. Frozen candidate authority

TB3 consumed only the immutable CB8 package:

- exact compiled source: `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431`;
- compile run/job: `35468097574 / 105964043163`;
- candidate artifact: `10591801825` (`m4-cp4-cb8-result-result-35468097574`);
- provider/download ZIP SHA-256: `20d9b07bae631e68f3292ee37ccb80c4724bae6eec0c50cd2274c36443183da6`;
- package root manifest: **26/26**, manifest SHA-256 `30c3f51fa0e43882d1a3c1227f58c069023007e38dbdc9a96c832ce152157b5a`;
- packaged source archive SHA-256: `4d057381ba3f1caed55579f7a9b662753632637eb0aff7b1432326d8e557021a`;
- all four selector-owner executables retained mode `0755`;
- clean source receipts and mandatory GMPXX+GMP linkage were present;
- CB8 boundary remained `runtimeExecution=false`.

Selector430 was verified only from the immutable packaged source: **430 LF rows / 35,001 bytes / SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`**, exact first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, exact frozen final three identities, owner census **31 / 283 / 75 / 41**.

## 2. Execution authority

Authoritative artifact-only execution:

- workflow run: `35470130614`;
- execution job: `105969470184`;
- event/control SHA: `d691a93896516b8f8644098e4c2588d1c0e0b9b1`;
- immutable harness SHA-256: `5848a8d40d9bcf747d0a5cbba5436b0c6af12aa4768416333e7991dc328034a5`;
- result artifact: `10592987234` (`m4-cp4-tb3-exec-result-35470130614`), provider/download ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- log artifact: `10592817804` (`m4-cp4-tb3-exec-log-35470130614`), provider ZIP SHA-256 `8d10ad76c42cdb9a6e6bc14a3a213deab2b3d3917c361c6d92bb95f313647d5b`;
- process ledger SHA-256: `0e1884ec95bf5043662f42ce5c24186aedb83d74cfe1e0395881a886768694a5`;
- identity map SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`.

The workflow had no repository/job elapsed-time watchdog for the full gate. Every selector identity ran as one fresh exact-filter process in file order.

## 3. Frozen execution boundary

The authoritative result records:

```text
script_exit=0
runtime_started=true
runtime_completed=true
preflight_completed=true
postflight_complete=true
orchestration_failure=false
semantic_non_green=false
configure_execution_count=0
compile_execution_count=0
relink_execution_count=0
generated_discovery_count=0
package_repair_count=0
mode_repair_count=0
source_mutation_count=0
test_mutation_count=0
fixture_mutation_count=0
selector_mutation_count=0
benchmark_execution_count=0
```

No configure, compile, relink, generated discovery, package or mode repair, source/test/fixture/selector mutation, or benchmark execution occurred.

## 4. Mechanical runtime result

The complete selector430 gate is mechanically GREEN:

- attempted **430** / unexecuted **0**;
- **430 PASS / 0 RED / 0 SKIP / 0 crash / 0 invalid-selection**;
- exact-one selected and zero skipped for every process;
- owner PASS census **31 / 283 / 75 / 41**;
- final three publication identities all PASS at ordinals 428-430;
- result records `mechanically_green=true`.

The process ledger contains one header plus all 430 process rows. The result artifact root `SHA256SUMS` verifies all **447/447** entries.

## 5. Immutable postflight

Mandatory postflight is complete. Package, packaged source, and execution-view byte+mode censuses are each exactly equal before and after runtime. Package manifest verification remains **26/26** both before and after. Selector430 retains its exact frozen digest.

## 6. Regression/accounting boundary

TB3 observed **no RED, SKIP, crash, selection mismatch, or new failure surface**, so there is no observed regression requiring a new or updated `Regression_Root_Cause_Tracker.md` entry. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**. The M6-owned closed-complex `G4-B002` debt and four M5-owned periodic debts are unchanged.

EXEC does not promote package `10591801825`, grant cumulative selector430 acceptance credit, or close CP4/M4. Those semantic and closure decisions are reserved to mandatory Review.

## 7. Successor boundary

`M4-CP4-TB3-EXEC` is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**. Exact next is runtime-free **`M4-CP4-TB3-REV`**. Review must independently re-derive package/selector/ledger/postflight authority, decide whether package `10591801825` becomes accepted runtime authority, grant or deny cumulative selector430 credit, preserve stable accounting/debt correctly, and decide CP4/M4 closure against all amended exit conjuncts.
