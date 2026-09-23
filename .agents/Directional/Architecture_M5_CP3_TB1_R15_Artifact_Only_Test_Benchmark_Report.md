# M5-CP3-TB1-R15 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R15-EXEC`
**Candidate:** artifact `10742798135`, semantic source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`
**Disposition:** **COMPLETE EXECUTION / ORCHESTRATION INVALID / NO COMPLETE SEMANTIC LEDGER / ZERO PRODUCT CREDIT**
**Mandatory successor:** `M5-CP3-TB1-R15-REV`

## 1. Candidate authority and immutable preflight

The CB17 candidate authority itself was recovered and verified from the immutable package:

- candidate artifact provider/download SHA-256: `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- root package manifest: **28/28** verified;
- semantic source: `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- packaged source archive SHA-256: `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- routing artifact `10592987234` provider/download SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing identity map SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- routing rows matched selector430 exactly with owner census `31 / 283 / 75 / 41`;
- packaged executable modes were already executable; no permission repair occurred;
- configure/build/relink/generated-discovery/package-repair counters remained zero and benchmark execution remained zero.

No candidate/package/source/test/fixture/selector mutation was authorized or performed.

## 2. Attempt 0 — pre-runtime orchestration failure

Run/job `35850838725 / 107147928250` produced result/log artifacts `10745895043 / 10745825171` with provider digests:

- result: `sha256:0700b240545c182f546e6c2927a792fd00c0b743cead22eb3f7d06bfe210e806`;
- log: `sha256:03d490b60519118dc8dcb2887b644234c81dbb94318511da1afce36425d112d8`.

The candidate root manifest verified **28/28**, but the temporary execution harness stopped while parsing its embedded selector-authority Python preflight. JavaScript string construction had materialized intended Python escape sequences as control/newline characters, causing an unterminated Python bytes/string literal.

The preserved boundary is exact:

```text
runtime_started=false
runtime_completed=false
preflight_completed=false
nonselector_executed=0
selector_executed=0
benchmark_execution=false
script_exit=1
```

Because generated Directional runtime had not begun, a bounded orchestration-only correction was permitted. The correction changed only the temporary harness/caller representation; it did not alter the immutable candidate, source, tests, fixtures, selector, routing map, or expected process vector.

## 3. Attempt 1 — runtime began, selection parser invalid

The diagnosed retry ran as `35851321165 / 107149476143` and produced result/log artifacts `10745985740 / 10745542559` with provider digests:

- result: `sha256:b863d7a5a88cb9fda5b1019ba6a9d9161594455e5ca118bdabeddf563cb1d13c`;
- log: `sha256:4be730a0a3cad33115e66f70616123d5ac427687d172fc462d1dc550d6631622`.

This attempt completed immutable preflight and began generated runtime. The first prescribed process executed exactly the intended binary/filter:

```text
M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges
```

Its raw GTest output records one test run and `[       OK ]`, and `/usr/bin/time` records process exit status `0`. However, the temporary harness stored the exact-one parser regex with **two literal backslashes** before each bracket (`^\\[ RUN      \\] `) instead of one regex escape. The parser therefore reported `selected=0` against the valid `[ RUN      ]` line and failed closed before committing a process-ledger row.

The preserved attempt-1 boundary is:

```text
runtime_started=true
runtime_completed=false
preflight_completed=true
orchestration_failure=true
selection_integrity=false
nonselector_executed=0
selector_executed=0
total_executed=0
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
retry_after_runtime_start=false
script_exit=90
```

The `nonselector-ledger.tsv` contains only its header. The remaining 447 prescribed processes were not executed. No complete result self-manifest was reached.

## 4. Execution disposition

Project policy forbids retrying an artifact-only Test + Benchmark gate after generated runtime has started. Therefore R15-EXEC stops here rather than repairing the doubled-regex harness and rerunning the candidate.

This turn yields **no 448-process PASS/RED vector and no semantic/product recovery claim**. The observed first-process `[ OK ]` is preserved as raw diagnostic provenance only; it is not promoted into R15 semantic credit because the execution harness violated the exact-one evidence contract.

Consequently:

- CB17 candidate `10742798135` remains **unpromoted**;
- accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`;
- latest mechanically valid CP3 runtime remains R14 at **446/448 PASS** with selector430 **430/430**;
- stable regression accounting remains **51 events / 14 categories / 37 recurrences**;
- produced-witness debt remains **3**;
- `M5-CP3-TB1-R6-REV-OBS-01`, both nonzero-Z4 produced debts, and `M5-CP2-TB1-REV-OBS-01` remain open;
- no selector publication or candidate promotion is authorized in EXEC.

## 5. Required Review input

`M5-CP3-TB1-R15-REV` must independently verify both failed orchestration attempts and decide the bounded successor. It must distinguish the **candidate evidence** (preflight authority valid; one raw focused process happened to execute green) from the **gate evidence** (invalid/incomplete because exact-one selection accounting failed after runtime start).

The likely corrective surface is the temporary test harness selection parser, not the candidate. Review owns that conclusion and any authorization for a fresh `R15-R1` execution; EXEC does not silently rerun or promote anything.
