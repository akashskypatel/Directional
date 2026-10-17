# `M6-CP1-TB9-A7-EXEC` — Artifact-Only Test + Benchmark Report

## Disposition

**COMPLETE / MECHANICALLY VALID / SEMANTIC RED / REVIEW REQUIRED / CANDIDATE UNPROMOTED.**

- Candidate package/source: `11287202960 / b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
- Runtime run/job: `37165108302 / 111326336924` — workflow/job success; artifact-only harness completed without orchestration failure.
- Result artifact: `11288673996`, provider/downloaded ZIP digest `sha256:5ebe700d35159c1cd6448314470daa1701ce44f69edd59ada71d7d5a1695fffa`.
- Log artifact: `11288504403`, provider/downloaded ZIP digest `sha256:60e19895d2c46bad3fb16ef76200f9fbc7cd5024c6e4d37e7f73991f23156f07`.
- Result self-manifest: **970/970** non-manifest files verified; manifest SHA-256 `7133432a54b5b288a0f2e0328097bb3da8b2aebc21aa8a95f3346dcff1f21f56`.
- Outcome: focused **19/20 PASS**, selector449 **449/449 PASS**, aggregate **468/469 PASS**.
- Sole RED: focused ordinal 20, `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`, first failure `CompletionOwnershipInvalidSelectedRelationDestination`.
- Exact-one selection: **true**. Zero skips: **true**. Benchmark execution: **0**.
- Stable accounting remains **60 events / 16 categories / 44 recurrences**, project debt **1**. EXEC creates one Review-owned candidate and does not reprice stable history.
- Reviewed runtime authority remains TB8 `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`; CB9 candidate remains unpromoted.

No repair, retry, test/fixture/selector mutation, package mutation, configure, compile, relink, generated discovery, benchmark execution, executable-mode repair, or same-turn diagnostic rerun occurred after runtime began. Exact successor is mandatory runtime-free `M6-CP1-TB9-A7-REV`.

## 1. Immutable candidate and preflight authority

The gate consumed the CB9 candidate immutably:

- candidate artifact `11287202960`, provider/downloaded ZIP digest `sha256:9bd87689c0155c3544de83159bd00169a4c8f932be4e878dbdd3dc7e7b5a179c`;
- packaged source `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`;
- root package manifest **28/28** before and after runtime;
- focused-20 source list: **20 rows**, SHA-256 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`, with focused-12 as its exact first 12 lines;
- selector449: **449 rows**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: **449 rows**, SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owner census **32 / 301 / 75 / 41**;
- frozen TB9 harness Git blob `4199dbff4df46dc3bd89178e9593ba7c48a6fd45`, runtime SHA-256 `61ba0ef73f33a16f88cb9ff93ee1efc7a3e777d99a8f08e1fa9fa5bd9ee731dd`;
- no executable-mode or package repair.

Pre-runtime source snapshot run/job `37164807750 / 111325464828` completed runtime-free at control SHA `f5f2422127ff559446941d03674b441ed78b3f2d`; snapshot artifact `11289106845` has provider digest `sha256:dab50411f275c758af4d4522088b34e2b737dbc50c46f595537b54f68f81676c` and embedded source-archive SHA-256 `75450843d08ded838ab78f874bc471a3e0ded63b03ad8458b2317fa5f8f43748`.

## 2. Exact runtime result

All **469** required processes ran in the frozen order: focused identities 1-20, then selector449 in file order with routing449.

- focused 19/20 PASS;
- selector 449/449 PASS;
- total 468/469 PASS;
- zero skips;
- exact-one selection for every process;
- zero benchmark processes.

Focused 13-19 all PASS. The RA-18 support diagnostics are absent from every raw log: `SourceSupportKindMismatch=0`, `SourceSupportIdentityMismatch=0`, and `SourceSupportPointMismatch=0`. Existing carry controls also remain green, including focused6/10/11/12 and selectors139/140/142/232/444/446/448/449.

Focused ordinal 20 alone is RED. Production materialization succeeds, then the real `validate_materialized_completion_domain_ownership` call returns false with `CompletionOwnershipInvalidSelectedRelationDestination`. The test selected exactly one identity and produced no skip.

## 3. Candidate root-cause record

### `M6-CP1-TB9-A7-EXEC-CAND-01` — class-wide A7 relation authority meets a representative-anchored completion destination check

**Status:** ACTIVE / NON-STABLE / REVIEW-OWNED. **Candidate category:** existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`.

The immutable runtime localizes the failure to `close_completion_lineage_source_authority` in `PureQuadCompletion.cpp`. The function first anchors `selectedRegion`, `selectedSheet`, and `selectedComponent` to `lineage.sourcePoint.face`, i.e. the materialized representative point. It later validates each A7 `selectedRelationPath` end chart and rejects when the destination region/sheet/component does not satisfy that representative-anchored predicate, yielding `CompletionOwnershipInvalidSelectedRelationDestination`.

A7, however, deliberately publishes class-wide `sourceTopologyRegions`, `sourceIsolationSheets`, `sourceCharts`, and A6-selected relation paths. CB9's producer verifies one common source component, complete occurrence bindings, and certified cross-sheet binding where required. The source therefore exposes a boundary mismatch between **class-wide relation/binding authority** and a **single representative source-point destination anchor**. This is the strongest source-localized cause supported by the immutable evidence.

The exact disjunct inside the compound destination predicate is not separately instrumented by the frozen artifact. Review must independently determine whether the failing torus endpoint differs by isolation sheet, retained region, or another destination field before authorizing a fix; EXEC must not add instrumentation, relax the predicate, or mutate the test.

Because the sole RED is a newly introduced focused positive identity rather than a previously accepted selector row, EXEC does **not** price a stable accepted-green loss. Stable accounting remains **60 / 16 / 44**, debt 1. Mandatory Review owns final event/category classification, candidate disposition, and any corrective authorization.

## 4. Ledger and immutability evidence

Key SHA-256 values:

- focused vector: `a6a3f23619769522804f3de5e2f4475b952a96eb744c589d229677fdcefb85de`;
- focused ledger: `ccc4c78ef3ae654f95f71c3407dbffe66008e47f8328f73aee1ef35733db273b`;
- selector ledger: `17b27fd323339454130c5c71c90c44fa14e241f80acdb8d948212cfcb6ba742e`;
- combined execution ledger: `4d9dfc02fcaefebe97419da2da5f3df209065f3ae3f0edc0c77b1ddc2f33541a`;
- RED ledger: `b4a7126ff1fc94a71e01e0fd1ca0015820c3adabae0ce4950533577cd1421426`;
- ordinal-20 raw log: `1025975974c8c7104a6254aae3c415e042b39fdb123ea8a5c1780581df5fbb31`.

Execution boundary records `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, `focused_executed=20`, `selector_executed=449`, `total_executed=469`; configure/compile/relink/discovery/benchmark/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start are all false.

Postflight records package/source/execution-view/fixture censuses equal, selector/routing unchanged, and candidate root manifest still **28/28**.

## 5. Turn boundary and successor

`M6-CP1-TB9-A7-EXEC` is mechanically complete and semantically RED. Candidate `11287202960 / b8d27b63...` stays rejected from promotion pending Review. No corrective Code + Build is authorized by EXEC itself.

Exact successor: **`M6-CP1-TB9-A7-REV`**. Review must independently re-open result `11288673996`, verify the 970/970 self-manifest, 469-process coverage/order, ordinal-20 raw failure, all-green selector449 and immutable postflight, then adjudicate `M6-CP1-TB9-A7-EXEC-CAND-01`. CB10 remains held until that Review.
