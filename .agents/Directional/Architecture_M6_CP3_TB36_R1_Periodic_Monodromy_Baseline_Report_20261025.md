# M6-CP3 TB36-R1 — periodic monodromy immutable baseline (2026-10-25)

**Turn:** `M6-CP3-TB36-R1-RP01-PERIODIC-MONODROMY-BASELINE`. **Verdict:** VALID artifact-only Test + Benchmark execution; **0 PASS / 5 RED**, all five distinct frozen identities executed once in fresh processes. Workflow succeeded because RED is expected evidence, not because the semantic gate passed. Independent Review required; CP3 not promoted.

## Immutable authority and execution

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft. Frozen snapshot/event commit `0053f6a779793c274bad3fcd8a2f58dbd8dba032`; snapshot run `40159647266`, source archive artifact `12585970880`, nested tar SHA-256 `75db0d65c30da45fea218723cce1074dc3b555d3d0695646a2d6120d0c66d950` and complete snapshot file checksums verified. The control-plane request commit is `65eeb12ed24dcf33802ec44a1fd3e29c1ecf92b4`.
- Executor harness `.agents/Directional/tools/m6_cp3_tb36_periodic_monodromy_baseline_harness.sh`, exact SHA-256 `343cdc6e53daf33da7d2893086751e0f762e6a3ed2111e69bf077555a4e3f439`. The frozen five-case manifest is `Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv`, SHA-256 `ab2711b2efc64103a9106b9a63f03064c63dc6e93a16c0602f3c6b3f866c1d0c`.
- Immutable semantic source `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`; existing compile package `12580989509`, ZIP SHA-256 `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`, **28/28** embedded package checksums. GMP runtime dependency resolved. No rebuild, relink, source/test/fixture/selector change, or benchmark. Exact postflight passed.
- [Workflow run `40159803899`](https://github.com/akashskypatel/Directional/actions/runs/40159803899); runtime job `121068843414` SUCCESS. Result artifact `12586275698`, outer SHA-256 `dceb186b64ac7bef4d10fb657fd02808b38b1de282e0049e8eadcf14d1f43033`; runner log artifact `12586150906`, SHA-256 `5055b704244486f62b6b8a339aa63f5822db310dc7b7bd562e124ab8a30611f8`. All **9/9** SHA256SUMS entries of the result checked. Exact ledger/result states `planned=5, executed=5, red=5, pass=0, missing=0, postflight=true, stop_reason=null, exit=0`.
- Prior attempt `40155549123` remains an invalid **0/5 orchestration attempt**, not semantic evidence.

## Five independent results

| Row | Identity | Actual | First C++ failure | Evidence |
|---|---|---|---|---|
| 1 | quarter-monodromy | RED | `SurfaceCellsPhase10Tests.cpp:4624` | Expected `PeriodicHolonomyMismatch(29)`; observed `PublishedProductRejected(68)`; phase front rejected, but not by expected periodic guard. |
| 2 | half-monodromy | RED | `:4624` | Same expected `29`, observed `PublishedProductRejected(68)`; A3 setup assertions passed. |
| 3 | directed-published-route | RED | `:4707` | Distinguished route step rotation was not `1` or `3`; the test had passed directed 32-step identity and inverse-orientation checks preceding this assertion. |
| 4 | selector:191 (frozen) | RED | `:5015` | Expected `Rejected`, actually `Produced`; expected reason `29`, actually `None(0)`; ensuing reject accessor threw as expected from incorrect disposition. |
| 5 | selector:192 (frozen) | RED | `:4856` | Expected `Rejected`, actually `Produced`; reason `None(0)`, produced product nonnull. |

Each log selected exactly one test, zero skipped. No unexpected new-oracle GREEN, missing test or harness stop. **Interpretation limit:** the source-location-only harness stop classifier did not stop on the distinct `PublishedProductRejected` reason; its first two lines equal the expected test assertion line. The independently measured phase-front reason is more specific than a presumed failing-stage classification. Review must determine whether this `PublishedProductRejected` path is caused by A4 periodic construction or a separate post-producer validation, and must not label it definitive periodic-guard ownership without proof. Source has `PublishedProductRejected=68` in `SurfaceCellTracing.h` and sets it at `SurfaceCellTracing.cpp:13195`.

## Disposition and review boundary

This evidence is **candidate/non-stable**; no known accepted-green PASS→RED is newly measured and no new stable event/category/recurrence is justified. Keep stable **66 / 17 / 49**, produced witness debt **1**, CP2 **491/491 accepted**, TB32 **481/500 candidate** (19 inherited RED), TB35 **11 PASS / 2 RED**, selector497 byte-frozen, RP-01 open/RP-02 unreached. RA-152 F1 remains a candidate owner pending Review. **Next:** `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE-REV`, independently re-open raw case logs, review the published-product path and whether the new witnesses discriminate A4 transport before authorizing any CB36 production correction. Do not edit source/tests, rerun as a semantic retry, alter selectors or advance to CB36 from this TB turn.
