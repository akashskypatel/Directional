# M5-CP3-CB18 — R15-R1 Orchestration Correction Report

## 1. Verdict

**COMPLETE / CONTROL-PLANE GREEN / RUNTIME-FREE / NO DIRECTIONAL COMPILE / NO REPACKAGE.**

CB18 corrected only the R15 exact-one GTest evidence parser, froze one canonical R15-R1 harness and caller payload, and proved the correction with a non-Directional static falsifier. No product, test, fixture, A3, selector, benchmark, CMake, candidate-package, or reusable-workflow semantic bytes were changed.

Exact successor is **`M5-CP3-TB1-R15-R1-EXEC`**, which must restart the unchanged 448-process R15 vector from process 1 with benchmark count 0. No runtime credit from either invalid R15 attempt carries forward.

## 2. Frozen semantic/runtime authority

CB18 preserved the entire CB17/R15 authority unchanged:

- semantic source: `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- candidate artifact: `10742798135`;
- candidate ZIP SHA-256: `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- root manifest SHA-256: `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, 28/28;
- packaged source archive SHA-256: `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- routing artifact: `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing owner census: `31 / 283 / 75 / 41`;
- gate cardinality: `11 + 1 + 6 + 430 = 448`, benchmarks `0`.

Stable accounting remains **51 events / 14 categories / 37 recurrences**. Produced-witness debt remains **3**. Accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`. R14 remains the latest mechanically valid CP3 runtime at **446/448 PASS** with complete **916/916** evidence and selector430 **430/430**. Candidate `10742798135` remains unpromoted.

## 3. Canonical control payload

CB18 publishes the canonical successor control bytes under durable repository paths:

- `.agents/Directional/tools/m5_cp3_tb1_r15_r1_artifact_only_harness.sh`
  - SHA-256: `7867e779ee1d276617cbf7c0e1a9910dbd5b7388a5fe6bde7aac32a47efb81b7`;
- `.agents/Directional/tools/m5_cp3_tb1_r15_r1_executor.yml`
  - SHA-256: `0f0a12f9b1b4ef43cde9f42726a60d91ea3ab4606cd3765c04ba6eaae076a15c`.

The harness preserves exact-one selection, zero-skip rejection, exact PASS accounting, immutable package/source/execution-view censuses, exact selector/routing authority, self-excluding result manifest generation, no-retry-after-runtime-start state, mode-preserving binary copying, and the exact 448-process vector.

The only evidence-parser correction is literal GTest protocol matching:

```bash
selected="$(grep -Ec '^\[ RUN      \] ' "$raw" || true)"
skipped="$(grep -Ec '^\[  SKIPPED \] ' "$raw" || true)"
passed="$(grep -Ec '^\[       OK \] ' "$raw" || true)"
```

The historical retry had doubled bracket escapes and therefore matched a backslash-bearing pattern GTest does not emit.

## 4. Static falsifier and schema validation

Control-validation run `35864475136` at event SHA `fe7565f2ddf113f048bb4230eb6b92354b9a89de` completed successfully.

Jobs:

- successor caller SchemaStore validation: **PASS**;
- temporary validation caller SchemaStore validation: **PASS**;
- static control proof: job `107192544449`, **PASS**.

Authoritative validation artifact:

- artifact `10751925972`;
- ZIP SHA-256 `bbd5ef8070d004c146781c443a548cf309a032f3604084d4ea932ccebd0362b4`.

Its recorded proof is:

```text
harness_sha256=7867e779ee1d276617cbf7c0e1a9910dbd5b7388a5fe6bde7aac32a47efb81b7
syntax_check=PASS
literal_probe_selected=1
literal_probe_passed=1
literal_probe_skipped=0
historical_selected=0
historical_passed=0
skip_probe_selected=1
skip_probe_passed=0
skip_probe_skipped=1
exact_process_count=448
benchmark_count=0
runtimeExecution=false
configureExecution=false
compileExecution=false
repackageExecution=false
timeout_watchdog=false
mode_repair=false
semantic_input_mutation=false
```

This satisfies the precommitted discriminator: corrected and historical parsers produce different counts on the same literal protocol bytes, and the skip parser detects a skipped exact row.

## 5. Transport and immutability evidence

The canonical two-file control payload was transported through the durable Google Drive patch workflow, not by direct semantic file mutation. Patch apply run `35863954067` completed successfully and committed the canonical files as `43fdb97c146190ed637eb47cd1c23413ab328ffa`.

Patch authority:

- patch SHA-256: `5d372e55d0c9f1ec8cdf22267addb11bc8c8848a70eebd0bfa687736820989ca`;
- patch body SHA-256: `c1a88256f33c555c1bdd904d7e742987d06293f731b94cc55a044e66d9f98ad8`;
- exact base: `4e7a81bef2460b356d0ce4d5f2aa6265e42e8973`;
- apply result artifact: `10751309101`, provider ZIP digest `sha256:c121c55c27c2c7e8ed9f58ed42f415e95317a0b16ec0c9c72bb1da43fc2b7255`.

The temporary Drive staging objects were permanently deleted after successful landing. Temporary caller workflows were removed workflow-first.

## 6. Scope audit

The turn executed no Directional binary, GTest identity, benchmark, help/list/version/discovery command, CMake configure, compile, link, or package command. It introduced no gate timeout/watchdog and no permission change to reusable workflows.

The successor caller has one narrow marker trigger, exact harness hash binding, the existing observer/validator reuse, and no broad branch trigger.

## 7. Operational deviations recorded

The following tool-use/process deviations occurred and are recorded rather than hidden:

1. A few repository policy/handoff files were fetched piecemeal before formal `READ_MODE=snapshot` selection. The turn then switched to one source snapshot for repository inspection; no semantic mutation occurred before the snapshot authority was established.
2. The source-snapshot observer comment was not yet available when first checked, so the run ID was recovered from the repository Actions list.
3. The first Drive-apply run was polled more often than the conservation policy's ideal one-intermediate/one-final status pattern. The run itself remained single-shot and produced one authoritative artifact set.
4. Library work-preservation upload failed with `container_session_unavailable`; the exact preservation patch was instead placed in Google Drive before further orchestration and was retired only after the canonical GitHub commit existed.

None changed semantic inputs, runtime evidence, candidate bytes, or the acceptance result.

## 8. Acceptance disposition

All CB18 acceptance conditions are GREEN. Therefore:

- `M5-CP3-TB1-R15-EXEC-CAND-01` remains non-stable and zero-credit, but its orchestration owner correction is now statically proved;
- no stable event or recurrence is added;
- no produced debt is discharged;
- no selector publication or candidate promotion occurs;
- `M5-CP3-DEFN-R1-REV-OBS-01` remains pending a complete valid R15-R1 ledger and Review;
- exact successor is `M5-CP3-TB1-R15-R1-EXEC`, followed by mandatory `M5-CP3-TB1-R15-R1-REV`.
