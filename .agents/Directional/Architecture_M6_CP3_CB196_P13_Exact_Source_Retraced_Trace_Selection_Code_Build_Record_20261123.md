# CB-196 exact-source retraced trace selection — Code + Build record (2026-11-23 UTC)

## Situation
Canonical turn: `M6-CP3-CB-196-P13-EXACT-SOURCE-RETRACED-TRACE-SELECTION`. This is a compile-only Code + Build turn. The successor is `M6-CP3-TB-EXEC-175-P13-RETRACED-TRACE-SELECTION-FULL-GATE`, which must not execute in this turn.

## Background
Authority: `Architecture_M6_CP3_TB_REV_174_Adversarial_Review_20261123.md` (F1–F5) and the approved exact patch `Architecture_M6_CP3_CB196_P13_Exact_Source_Retraced_Trace_Selection_Exact.diff` (4,910 bytes, +82/−0; SHA-256 `d95f414457af1ff45dda04611b02ff53271cd55d325c7eb266dba514203e1499`). Only `include/directional/authority/ExactSourcePath.h` and `tests/FieldAlignedCurveNetworkTests.cpp` change. The helper is not connected to production.

## Assessment
Verified patch application: GitHub Actions run `45224696674` (success), result artifact `14841509359`, source commit `f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5`, `runtimeExecution=false`.
Exact postimage hashes:
- header SHA-256 `0285981f850ca852ee2c172847381a1524b74bb1cd1a42d66e81e51fa443b19e`;
- test SHA-256 `2b9cde9a37f89fa0ff8866938b9d7ff50845f47a4125fc304488840017d60d29`.

The first apply run `45224041104` failed before a source change: the raw diff lacked required transport metadata. Retry used a wrapper with the original diff body intact, a verified base SHA, body SHA-256, and semicolon-separated intended paths. Successful wrapper SHA-256 `26afa5e54dc59ce0b6c5117074819d908ee0a7cec8080aaabb84565ae7ca7cb2`. Both staged temporary Google Drive files were moved to Trash after successful application.

Compile-only dispatcher request commit: `2e2c3b3d19e10e7039b7042aaa796df8304ae84c`. Mailbox: `.workflow-mailbox/m6-cp3-cb196-compile/latest.json` on `workflow-mailbox`. Source pinned to `f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5`; eight targets include `directional_surface_cell_producer_tests`. Require GMP and GMPXX, clean packaged source, and `runtimeExecution=false`. Compile verified through run `45225040406` (successful); package `14845101702` ZIP SHA-256 `9afbf9c90c96697c49e97669ba108d68e61f57d0182cff3f42807d133be6034f`, log `14844220690` ZIP SHA-256 `c9fe20e317b2cb8ab3d985af6171d38ce691df23ba15cc7ab239e425f15b945b`. The archive has 28/28 valid internal SHA-256 entries. Preflight and build exit codes are zero. All eight requested targets compiled, including `directional_surface_cell_producer_tests` and the two static libraries. The GMPXX and GMP libraries occur in the generated link command. All final source-status records are empty. The command boundary records `runtimeExecution=false` and `exactArithmeticBackend=GMP`. No Directional executable, test, or benchmark ran during this Code + Build turn.

## Recommendation
CB-196 is compile-complete. Preserve the immutable package. In the next turn, execute TB-EXEC-175 without a rebuild, using its frozen 1000-row manifest. Expected 993/1000 passes and the same seven mechanical failures. TB-REV-175 must review the result before CB-197a begins.
