# TB123 cross-face oracle — focused execution report, 2026-11-16 UTC

## Situation

Canonical turn: `M6-CP3-TB123-P13-CROSS-FACE-ORACLE-FOCUSED-EXEC`. The scoped immutable-package test execution finished **2/2 PASS**. This is a focused test result, not a 949-case full-gate or production-mesh acceptance. Next distinct and independent Review: `M6-CP3-TB123-REV-P13-CROSS-FACE-ORACLE-OUTCOME`. Do not start that Review in this turn.

## Background

- Repository and branch: `akashskypatel/Directional`, `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft/open.
- Code + Build authority: CB142 exact compiled source `57b28b737fd92b083d24d882152dea186211f735`; compile workflow `43864872021`; immutable package artifact `14224898790`.
- Immutable outer ZIP SHA-256: `98f448f9e5b5ebcacbd1884ad4e62415d7c10d5878da0ccf1438654b4aeaf52b` (verified locally).
- Package internal SHA256SUMS checks: **28/28 passed** before and after both runs; eight compiled targets use GMP/GMPXX. No package repair, rebuild, relink or configure action was performed. Binary SHA-256 unchanged.
- The exact repository-source snapshot at `4e3ce84630bc83a3914d0699e4caa81caf49a11f` was verified by full source archive check (5,564 files) and inspected. This source snapshot is not the compiled-source identity.

## Assessment

| Focused test | Executed | Passed | Skipped | Exit |
|---|---:|---:|---:|---:|
| Row 948 `ResolvedBranchCorrection.EdgeTransitArrivalSeedsElectionOnCarrierRay` | 1 | 1 | 0 | 0 |
| Row 949 `ResolvedBranchCorrection.OwnerWithoutOutflowFollowsFieldAcrossRadialEdge` | 1 | 1 | 0 | 0 |

The corrected row 949 contains independent A1 transport, expected destination-field/outward-wedge assertions, and four negative inputs: wrong branch, wrong lift, inward ray and radial grazing. The test passed with these checks compiled and present. The four negative inputs are assertions within row 949; they are **not** four separately executed named tests. `GTEST_FAIL_IF_NO_TEST_SELECTED=1` was set, and the test logs each confirm one real test ran. The `timeout` wrapper did not fire. Both tests ran by direct invocation of the immutable packaged binary on the local Linux container, **not** in a newly triggered GitHub Actions Test + Benchmark workflow. The repository's existing 949-row remote harness is not evidence for this focused 2-row run, and no full-gate result is claimed. Raw logs, time/memory records, exit codes, before/after binary hashes and postflight package hashes are in the companion evidence archive.

No test, implementation, fixture, benchmark, build, selector, production behavior or reusable workflow was modified or recompiled. The earlier TB122 full gate result remains 948/949 and is not overwritten. This run does not establish A2a end-to-end tracing, BunnyRandom resolution, or a valid product mesh. Stable totals remain 66 events, 17 categories and 49 recurrences; witness debt 1 and deferred 81; CP2 accepted 491/491. O42, O43 and O44 stay open. D11=A, D12=A, D10 deferred, D6 pending; `chainRimSchedules=false`; CP3 and selector497 stay unpromoted.

## Recommendation

The next separate owner is the independent TB123 Review: `M6-CP3-TB123-REV-P13-CROSS-FACE-ORACLE-OUTCOME`. Check that the corrected oracle is independent and each negative control fails when used as a positive witness. If the oracle and physical outgoing field disagree, stop and authorize a separate bounded source-correction plan. Do not start TB124, CB143 or any successor in this turn. A later conditional full-gate run remains necessary.

**Process note:** Initial source/document reads happened before the policy-mandated snapshot read-mode gate. This order was incorrect; subsequent static inspection used the verified exact snapshot. Tool-use accounting is partial; no complete call count is claimed.
