# M5-CP3-TB2 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB2-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on the CB20-published selector448 package
**Disposition:** **MECHANICALLY COMPLETE / 448 PASS + 0 RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB2-REV`

## 1. Immutable authority

TB2 consumes only CB20 result artifact `10771899191` from exact semantic source `cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1`.

- candidate artifact provider/download ZIP SHA-256: `d0f26b1615cbc69d3dd977f726296ad8e76728b682ad3428dc10c07ddb1d2cbe`;
- candidate root manifest SHA-256: `b3afa49083701f466d7a1d6b98aea83d6d5a58078f0336727d29c4184a7dc3f3`, **28/28** before and after runtime;
- packaged source archive SHA-256: `dabed7ea7f37565aec320bc7cfd34a51a840f519c2115015994f459880e580b7`;
- published selector448: **448 rows**, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- static routing receipt: **448 rows**, SHA-256 `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`;
- exact standard-owner census: **32 authority-kernel / 300 producer / 75 completion / 41 validation**;
- TB2 harness SHA-256: `78d4549b0f58c3db3dd81e7e6f3bbcef09e7061d7e8e0853a503cc17cdb34f25`;
- trigger/event SHA: `9d4f8dbb318a9e4250812823d55328cce7f2f0bc`.

The harness used system `unzip` and `tar` so archived executable mode bits were preserved. It performed no permission repair, rebuild, configure, compile, relink, generated discovery, source/test/fixture/selector mutation, or package repair. It routed directly from the CB20 static receipt and did not rediscover ownership at runtime. No R16 process credit was stitched into TB2.

The two CB14 identities governed by `M5-CP3-TB1-R16-REV-OBS-01` are absent from selector448 and were not executed, exactly as required. Their disposition remains Review-owned.

## 2. Runtime and result authority

Authoritative workflow run/job: `35913334490 / 107358491487`.

Runtime began at `2026-09-23T20:03:10Z` and completed at `2026-09-23T20:14:57Z`. Schema validation and the execution job both completed successfully; harness exit is `0`.

Authoritative artifacts:

- result artifact `10775185139`, provider/download ZIP SHA-256 `01142fbc1f4cf0a4fb695cda1ed973d39b3b51e5dc11e05ff34336b84875261b`;
- log artifact `10774217117`, provider ZIP SHA-256 `b58678cbf37d9c7757e8a36e8b590381919f5d1413a6ac02d11038e12e040fc6`.

The result contains exactly **917 actual non-manifest files** and **917 `SHA256SUMS` rows**; every row verifies. `SHA256SUMS` hashes to `9681fda2357103470162e7cd1362713df07078732dc2a1e8a4fff17b75a843c1`.

The execution boundary records:

- `preflight_completed=true`;
- `runtime_started=true`;
- `runtime_completed=true`;
- `orchestration_failure=false`;
- `selection_integrity=true`;
- `selector_executed=448` and `total_executed=448`;
- `benchmark_execution=false`;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start all `false`;
- `script_exit=0`.

Package, packaged-source, and execution-view byte+mode censuses are identical before and after runtime. Selector448 and its routing receipt are unchanged, and the candidate root manifest remains **28/28** after execution.

## 3. Fresh published-selector448 ledger

All **448/448** selector identities executed as fresh one-identity GTest processes in published file order. Every process selected exactly one test and recorded zero skips.

| Gate | PASS | RED | Total |
|---|---:|---:|---:|
| published selector448 | **448** | **0** | **448** |

Owner census is exactly **32 / 300 / 75 / 41**. Benchmark count is **0**. Selector-ledger SHA-256 is `91c861fca2a7627b256ae6f7cb3241c5992689056da57d1622a135519bd600c3`.

Protected historical ordinals **191, 192, 247, and 408 PASS**. All newly published ordinals **431-448 PASS**. In particular:

- ordinal 446 `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` PASS, raw SHA-256 `476fb5cbb909992e1df18ad2f0496da7c532359209da2599ebc7d9ade3e6aa9c`;
- ordinal 447 `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` PASS, raw SHA-256 `864a67220f6cc330e06af712f27373dd4a980b5f1638f9097848ec75c4ff4ad7`;
- ordinal 448 `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` PASS, raw SHA-256 `83f915a109900ffc5460052a33473099773f7bdda574df8236d894b514832a6a`.

## 4. Regression documentation gate

TB2 observed **zero RED processes, zero skips, zero selection mismatches, and zero immutable-boundary violations**. There is therefore **no observed regression to classify** and no evidence basis for a new stable regression event or non-stable regression candidate.

Stable accounting remains **51 events / 14 categories / 37 recurrences**. Project debt remains **1**, M6-owned. The matching no-regression disposition is recorded in `Regression_Root_Cause_Tracker.md` as part of this turn closeout.

## 5. EXEC disposition

TB2 mechanically proves that the **published** selector448 can be executed freshly and completely from the immutable CB20 artifact with exact-one selection, zero skips, zero RED, benchmark 0, exact routing, and exact immutable postflight.

EXEC does **not** accept selector448, promote CB20 as accepted runtime authority, close M5, dispose the two ungated CB14 identities, repair the consolidated-record numbering, or discharge `M5-DEFN-REV-OBS-01`. Those are explicitly owned by mandatory runtime-free `M5-CP3-TB2-REV`.

Until that Review acts, CB19 package/source `10763242885 / a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1` under accepted selector430 remains the accepted M5 runtime authority. Selector448 remains **PUBLISHED / EXECUTED GREEN / NOT YET ACCEPTED**.
