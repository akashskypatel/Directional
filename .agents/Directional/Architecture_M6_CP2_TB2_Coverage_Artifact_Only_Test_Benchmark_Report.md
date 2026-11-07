# M6-CP2-TB2-COVERAGE-EXEC — Artifact-Only Test + Benchmark Report

**Disposition:** COMPLETE / MECHANICALLY GREEN / **491/491** / CANDIDATE UNPROMOTED / MANDATORY CLOSE REVIEW NEXT.

This turn consumed immutable package `11391685901` / semantic source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6` without rebuild, relink, configure, generated discovery, package or mode repair, source/test/fixture/selector mutation, benchmark execution, or retry after runtime start. The frozen gate was exactly focused30 + CP2-focused12 + selector449 = **491 fresh exact-filter processes**. Semantic closure/promotion remains Review-owned.

## Immutable candidate authority

- compile/result artifact: `11391685901`;
- semantic source: `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`;
- candidate ZIP SHA-256: `d2a3ef4f2bf40420fba21155bb264a8271c36ce18c41bc31a5e191af93739980`;
- candidate root `SHA256SUMS` SHA-256: `0a71304d3a77ff99ad6332403927b9cb3cacc9de6647e3d84d1d9dfd3abaa0ce`;
- source archive SHA-256: `c7bbbdfac04ae55db6adaeb4f60bc6fcd757a01a01b3999369a52215b727f5c9`;
- package root manifest: **28/28** before runtime and **28/28** after runtime;
- exact arithmetic: GMP/GMPXX;
- entering Code + Build boundary: `runtimeExecution=false`.

Frozen gate authority remained byte-identical:
- focused30: 30 rows, `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`;
- CP2-focused12: 12 rows, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`;
- selector449: 449 rows, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: 449 rows, `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Runtime authority and immutable evidence

Workflow run `37419256039`, trigger/event SHA `5c136917d09c731515b94cd867a4aecec2f46c43`:
- schema validation job `112124700521`: SUCCESS;
- runtime job `112124748161`: SUCCESS;
- mailbox job `112134190723`: SUCCESS;
- authoritative mailbox: `.workflow-mailbox/m6-cp2-tb2-coverage-exec/latest.json`;
- result artifact `11393198123`, provider/downloaded ZIP SHA-256 `0e4e550a09e4fb38b58bfcef2e57db6dcea865a1c46b384b5a288d5c491606bb`;
- execution-log artifact `11393312986`, provider/downloaded ZIP SHA-256 `fd2a578380dd071967b46b5461d6a7434a14c787a8b3d8a2438a6a9abdde7cf7`;
- result self-manifest: **1005/1005** verified, SHA-256 `25bae369de8a6a46f5b8f273083fe3a18ec0e9374f833c11479c85aa0ac22a2b`.

The harness began runtime at `2026-10-06T05:35:16Z` and completed organically at `2026-10-06T06:10:41Z`. No repository timeout, cancellation, partitioning, or runtime retry was used.

## Mechanical gate

- focused30: **30/30 PASS**;
- CP2-focused12: **12/12 PASS**;
- selector449: **449/449 PASS**;
- aggregate: **491/491 PASS**;
- exact-one selection: **491/491**;
- skips: **0**;
- benchmark executions: **0**;
- RED ledger: header only / **0 RED**.

Ledger SHA-256 values:
- focused30: `2dde1ec0ed7d9651134665a7a54b6968ed16e563f43d3f6756dcf06df417c1e8`;
- focused12: `768178c02ef59f5f2d340399805c4ba4342b26023c8c885e27a38f1eb400fbab`;
- selector449: `a7a9c7651d11ffb48066b6d859da3658f6c91ccdfb681d28dd7d69e27fdfd394`;
- combined 491-row ledger: `cb2039e475783c277df966d312eeec5fb759f63e928d4eac0dbe90104896df01`;
- empty RED ledger: `dc5496d37ad6939dc28d5b6c2b2eb9a670066d4a6cf3268c443fef6ffb27ecf7`.

Execution boundary is fully clean: `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`; configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start are all false.

Postflight proves `package_census_equal=true`, `source_census_equal=true`, `execution_view_census_equal=true`, all four gate files unchanged, and candidate manifest **28/28** again after runtime.

## Regression/accounting classification

No RED row, orchestration defect, or new regression candidate occurred. This Test + Benchmark turn therefore adds **+0** regression events, **+0** categories, and **+0** recurrences. Stable accounting remains **60 events / 16 categories / 44 recurrences**, architecture debt **1**.

Mechanically, the RA-29d CB2 recovery is exercised by the frozen gate: the strengthened CP2-focused identities, exact A7 vertex binding coverage, A6 topology/member checks, A5 ownership/relation checks, and §6.3 forbidden-class coverage all remain green. That observation is evidence for Review, not an EXEC closure decision. RA-29d OBS-01/02/03 and the missing CP2 closure record remain Review-owned until `M6-CP2-CLOSE-REV`.

## Boundary and mandatory successor

Candidate package `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6` remains **unpromoted by this EXEC turn**. Previously reviewed runtime authority remains `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` (491/491) until Review explicitly promotes/accepts the coverage recovery and writes the closure record.

The exact next turn is mandatory independent `M6-CP2-CLOSE-REV`. It must independently re-derive the 491/491 result and immutable evidence, adjudicate RA-29d OBS-01/02/03 and the closure-record obligation, write `M6_CP2_Closure_Record.md` only if CP2 exit is actually satisfied, and then authorize `M6-DEFN-R5` only on accepted closure. EXEC authorizes no source/test repair, no duplicate runtime, and no direct advance to `M6-DEFN-R5`.
