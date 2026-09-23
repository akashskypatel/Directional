# M5-CP3-TB1-R16 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R16-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on CB19 candidate `10763242885 / a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1`
**Disposition:** **MECHANICALLY COMPLETE / 448 PASS + 0 RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R16-REV`

## 1. Immutable authority

R16 consumes only the CB19 compile-green candidate, the unchanged routing/selector authority, and the CB18-frozen R15-R1 evidence parser/vector:

- candidate artifact `10763242885`, provider/download ZIP SHA-256 `abe4c381511d3b4025f22612978388bb554bd686b86b6f9dc406538998e990aa`;
- semantic source `a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1`;
- candidate root manifest SHA-256 `cda95dd99d7c201fb4fc1f5021f24c6e720e82dc737a89418245e687bf010c25`, **28/28**;
- packaged source archive SHA-256 `54962d495891b35dd800fbede63ddc7d622c28091b42a0faeb8e8b3597726d91`;
- routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` and first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing owner census **31 / 283 / 75 / 41**.

The frozen R15-R1 harness hashes to `7867e779ee1d276617cbf7c0e1a9910dbd5b7388a5fe6bde7aac32a47efb81b7`. R16 materialized it in runner-local temporary storage and changed exactly five candidate-authority constants: artifact ID, semantic source SHA, candidate ZIP digest, root-manifest digest, and source-archive digest. The derived R16 harness hashes to `5d383089aa12f9e78367ec5c673c7fda3b79040da4a42d3234c7dcc5a4ca6cdf`. Evidence parsing, the 18-row nonselector vector, selector430 routing, exact-one/zero-skip checks, postflight, and manifest logic are otherwise byte-preserved from the frozen harness.

Trigger/event SHA is `1052882e56b28f703f60dfa11e0a9493e7e091d9`. No R15 or R15-R1 PASS, ledger row, selector credit, or semantic observation was carried into R16.

## 2. Runtime and evidence authority

Authoritative workflow run/job is `35889831381 / 107279255523`. Schema validation and orchestration both complete successfully. Runtime started at `2026-09-23T16:36:31Z` and completed at `2026-09-23T16:49:51Z`.

Authoritative artifacts:

- result artifact `10765221644`, provider/download ZIP SHA-256 `d2ec2703f2255cdfa7797da3989aab20e6d10d7203e006ba4068892df1909f46`;
- log artifact `10764573644`, provider/download ZIP SHA-256 `3b8d16d1dbed5ee96e7990f6482d7961f454be1410e35097ba08c931d3097103`.

The result contains exactly **921 actual non-manifest files** and **921 `SHA256SUMS` rows**; every row verifies. `SHA256SUMS` itself hashes to `c2f898912e19fb57061b50945a58e79af74e244c145de9c5d6ef367ee3185784`.

The execution boundary records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, **18** nonselector processes, **430** selector processes, and **448** total. Benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start are all false. Candidate package, packaged source, and execution-view censuses are unchanged; the candidate manifest remains **28/28** after runtime.

## 3. Fresh 448-process ledger

All **448/448** prescribed processes executed freshly. Every process selected exactly one GTest and recorded zero skips.

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| mechanism / semantic | 11 | 0 | 11 |
| focused atlas | 1 | 0 | 1 |
| produced CP3 | 6 | 0 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **448** | **0** | **448** |

Benchmark count is **0**. Protected selector ordinals **191, 192, 247, and 408 all PASS**.

Produced row16 `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` is exact-one / zero-skip / exit0 / PASS with raw SHA-256 `c59eea07dfbee79d58ace0031701f7d454fd35b3541608ecd4b7af705b0ece7d`. Produced row17 `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` is exact-one / zero-skip / exit0 / PASS with raw SHA-256 `a22dd174cd788521a3845b3b1697805829e0db394a354fa3093367c975685655`.

The nonselector ledger SHA-256 is `5716a0b6b8512ba07dc575219bf59538c43cb4227fcf6e136629bf7976168987`; selector ledger SHA-256 is `9b2f4e1d2e2578c84ce9e05fa43759fc6a554eeea9e69a65032b2d3cdfc8fd25`.

## 4. EXEC disposition

R16 is mechanically valid and has no RED process. That is runtime evidence only. EXEC does **not** promote the CB19 candidate, discharge either nonzero-Z4 produced debt, close the carried R6-direction or CP2-publication observations, close M5, publish a selector, or alter stable accounting. Those dispositions remain mandatory-Review authority.

The passing row16/17 processes remove the prior R15-R1 execution frontier, but Review must independently reopen the exact source and result/log bytes, verify the inverse-storage non-vacuity and independent source/A3 `Q=3` expectation, confirm row16 actually reaches materialization/certificate/consumption checks and row17 reaches its one-transform typed `NonReciprocalPeriodicRelation` rejection, and adjudicate the carried observations/debts.

The standing DEFN-R1 note remains: the current CP3 witness has cancelling occurrence gauges. Its green produced rows must not be cited as independent validation of the gauge correction. That validation rests on `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges`, which is PASS in this complete ledger.

Stable accounting therefore remains **51 events / 14 categories / 37 recurrences**, produced-witness debt **3**, pending mandatory Review. Accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` until Review decides promotion.

## 5. Successor

Exact successor is runtime-free **`M5-CP3-TB1-R16-REV`**. Review must independently verify the 448/448 ledger, 921/921 evidence manifest, immutable boundary, selector/routing authority, produced-row non-vacuity and final falsifiers, then decide candidate promotion, the two nonzero-Z4 debt dispositions, R6 direction observation, CP2 selector-publication precondition, M5 closure authority, and the next authorized turn.
