# M3-CP4c-0 TB-R11 — Focused CAND-02 Verification Report

## Status

**COMPLETE / FOCUSED PASS.** The user authorized `M3-CP4c-0-CB-R11` followed by `M3-CP4c-0-TB-R11` to diagnose, correct, and test `M3-CP4c0-TB-R9-CAND-02`. This is corrective evidence for that identity only, not a whole frozen 346-gate acceptance run.

## Diagnosis

The TB-R9 product result was correct. The test enters face `(0,1,2)` through edge `(0,1)` at exact parameter `1/2`, producing barycentric coordinates `[1/2,1/2,0]`. Its old direction `{-1,2,-1}` marks barycentric coordinates 0 and 2 as outflow. Exact minimum-ratio continuation therefore compares `1/2` against `0`; the exact winning time is zero, and `resolve_field_branch_continuation` must return typed `BranchContinuationDegenerateEntry`.

The positive control was thus structurally degenerate before magnitude-policy behavior could be demonstrated. No product or GMP arithmetic defect was found.

## CB-R11 correction and package authority

- Changed path: `tests/FieldAlignedCurveNetworkTests.cpp` only.
- Corrected positive-control direction: `{-2,1,1}`.
- Only barycentric coordinate 0 is now outflow; exact exit time is `(1/2)/2 = 1/4`.
- The test explicitly asserts `FieldBranchContinuationKind::EdgeExit`, outgoing carrier `(1,2)`, and exact exit point `boundary_point(outgoing,1,4)`.
- The oversized exact-magnitude fail-closed case is unchanged. No production source, selector, tolerance, GMP, or exact-arithmetic semantics changed.
- Semantic source: `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`.
- Compile run/job: `33077493539 / 98535503386`.
- Immutable GMP package: `9648550565`, ZIP SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`.
- Compile log: `9648551415`, ZIP SHA-256 `c7e4c83c6727117af6cdfc5874762d70dc4a8633cfe7e241e1e36ec001a83e2b`.
- All eight standard targets compile/link; GMP 6.3.0 with gmpxx/gmp verified; preflight/build exit 0; source-status snapshots clean; `runtimeExecution=false`.

## TB-R11 immutable artifact-only authority

- Run/job: `33077761701 / 98536455697`.
- Consumed only package `9648550565` from source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`.
- Package outer ZIP SHA-256 matched exactly and recursive `SHA256SUMS` verification passed before runtime.
- Focused identity: `ResolvedBranchCorrection.ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance`.
- Selection: exactly `1`.
- Result: **PASS**, exit `0`, failures `0`, errors `0`, harness elapsed `39 ms`, 60-second timeout not reached.
- Package preflight/postflight file-hash inventories matched: **PASS**.
- No configure, compile, relink, repair, generated discovery, or performance benchmark occurred.
- Result artifact: `9648618375`, ZIP SHA-256 `469cab3ee5a541a5faa29fcdac2a6ff213ca202c8ff38522e131b0a9a4ba6113`.
- Diagnostic log: `9648618836`, ZIP SHA-256 `c15831693911134a4ab3eba6fa8060af8b95e85eac679d5374c632fcecdc908d`.

## Disposition and boundary

`M3-CP4c0-TB-R9-CAND-02` is **RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION**. Together with CB-R10/TB-R10, both TB-R9 RED identities are now individually resolved. Stable accounting changes by **+0 events / +0 recurrences** and remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**; CB-R11 is M3 package **50**.

The earlier `M3-CP4c-0-TB-R9-REVIEW-PLAN` remains skipped/not completed. The last whole frozen CP4c-0 selector execution remains TB-R9 at **344/346**. Focused TB-R10 and TB-R11 do not retroactively make that run green, so CP4c-0 remains OPEN pending a whole-gate re-proof. No successor or CP4c-0b implementation turn is authorized automatically by this report.
