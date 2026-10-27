# CB47A — harness manifest pin migration, tool-only Code + Build (2026-10-27)

**Turn:** `M6-CP3-CB47A-HARNESS-MANIFEST-PINS`. Source inspection base: `04cf34ffd012c1d391bb3e6e643d456c867f99a1` (verified snapshot, 5,945 file hashes). This is tool-only; no compilation, product test binary execution, benchmarking, or fixture/selector/product mutation was authorized or performed.

## Changed mechanism

`tools/m6_cp3_targeted_artifact_harness.sh` now consumes the frozen `asserted_site` manifest field directly for registered expected-RED and later-positive-RED cases, with strict `CppFile.cpp:positiveLine|nonemptyDecisiveWitness` parsing. It removes the hardcoded `PINNED_RED_SITES` and `PROVEN_LATER_POSITIVE_SITES` lists. The parser rejects malformed/missing RED pins, unexpected pins on guards, malformed later-positive pins, row/identity duplication, and malformed manifest rows. `selector:174` is the exact frozen informational POSITIVE note, explicitly **not** a failure-site pin; it remains a mandatory positive PASS. First failure location and decisive witness must both appear inside the same failing GTest block. Unexpected RED->PASS remains a reported improvement rather than silently promoted acceptance. Full manifest identity is bound by `CASE_MANIFEST_SHA256` before execution.

## Exact offline verification

- Frozen TB47 manifest: SHA-256 `6f9b3582900951eef5f94309b7f7053412148faca4935a619e504bad9b73a09b`, 504 exact rows. First six columns remain byte-equivalent row-for-row to TB46. No manifest bytes edited.
- Immutable TB46 result: Actions run `40468913755`, artifact `12719412600`, original source `8f0d4329695de1c7542ea240e30e55761acc3a38`; result ZIP SHA-256 `2a33427b5bc1af6629259469514a30158e07478ca21b3c68df3be7d3e1f5fd37`. Verified complete result `SHA256SUMS` and 504 raw logs.
- Executed harness `--self-check` (504) and `--self-test` (12 synthetic parser/verdict cases) only. An **independent offline replay**, loading the modified parser but not executing any product binary, compared all 504 case identities/verdicts, selected-test process outcomes, first-failure strings, typed reasons, raw log SHA-256s, and 13 ledger fields per row against the saved TB46 ledger. Exact match **504/504**, **498 PASS / 6 registered RED**, 497 guards PASS, zero unexpected-pass, missing/skipped/duplicate/control/red-site violations, later-positive-RED=1, postflight=true. This is comparison of preexisting runtime logs, not a new TB run.
- Six registered pins each underwent two falsifying mutations (first-site and witness): **12/12 correctly rejected** by control logic. Missing/malformed/quoted manifest site rows rejected by `read_cases`; one-row frozen identity mutation fails digest equality. No accepted selector, line location, or test assertions changed.

**Disposition:** CB47A tool-only pin migration meets its bounded offline proof. Next authorized turn is `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES`; CB47 is a separate Code + Build turn. CP2 491/491 accepted, CP3 and selector497 unpromoted, stable 66/17/49 and debt1 unchanged. No runtime acceptance is claimed here.
