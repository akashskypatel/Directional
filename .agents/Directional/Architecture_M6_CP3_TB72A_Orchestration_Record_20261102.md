# M6-CP3 TB72A — corrected full-gate dispatch (2026-11-02)

Canonical turn: `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH`; working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft. **This documents a dispatch, not a verified test result.**

Prior TB72 run `41533361438` failed preflight before execution (0/0): executor `90c0f28abc174627639f36553934b45d1f4f56ca` predates the frozen 883-case manifest. It is orchestration failure, not semantic RED. Separately, census run `41533460744` already verified 3/3 registered outcomes (Cylinder PASS; BunnyRandom P13-e RED; Vase P13-j RED).

Exact executor snapshot commit `df5862858b5e2ef0d167856f0f0f8aecf3fc6a57`, snapshot run `41539714172`, artifact `13185581639`, provider ZIP SHA-256 `3e620add761acefa4e5bf7b0c2732c933f83918ecaf2d48d18854a12dbd009b0`; metadata and **6115/6115 source hashes verified**. Frozen TB72 case manifest SHA-256 `e9eabb064fba1aa625b20931f1b85cf3f441c0c877a81cccd49b73bb5ebd3031` (883 rows), deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81), harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. No source/code/test/fixture/selector/build/package changes.

Corrected dispatcher `test_benchmark` request `m6-cp3-tb72a-gate-20261102-v2` committed at **`d03e350f5b0413a8e8702b833907dc98990525d5`**, `executor_sha=df5862858b5e2ef0d167856f0f0f8aecf3fc6a57`; CB78 semantic source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`, immutable package `13181887585`, package ZIP SHA-256 `076a19de16db5b0d7be3fb7d133c0324383dde319467afb22b3edc99922658e4`, package root manifest `71492e14a774a4f012f84835ba0d746a0e72d724372436f066cedc15ef8ba9b5`, source archive `c8a13798d857c1bb7427d09a63cb5707d89ef6b792f6e08d06fd67bd14e1d357`. Registered expectation **883/883 PASS**, membership **964**, with 81 deferred. The corrected run is **pending immutable evidence** as of this report; do not claim gate acceptance.

Temporary snapshot marker and cleanup manifest were retired by standard cleanup trigger `9b7cd3bc6938cc1e4b4ea6f00857b7f8ea78c719`; both absent on readback, durable request slot retained.

**Same-turn continuation:** read `.workflow-mailbox/m6-cp3-tb72a-gate-20261102-v2/latest.json` on ref `workflow-mailbox` after publication (last fetch: NOT_FOUND/pending); verify event SHA `d03e350f5b0413a8e8702b833907dc98990525d5`, jobs, result/log artifact IDs and digests, source identity, selected/executed/passed all 883, no skipped/abnormal, 81 deferred, 964 membership, `postflight=true` and no configure/compile/relink/benchmark. Do not replay an unchanged failure. On verified result update handoff/TODO/CHANGELOG/tracker as required and close root STATUS last; route semantic mismatch to RA-199.5 Review rather than fix in this turn.

Accepted CP2 491/491; stable 66/17/49 and debt 1; selector497 unpromoted; no CP3 promotion.
