# TB-EXEC-174 — retrace oracle 998-case full gate (in-flight record, 2026-11-23 UTC)

## Situation
Canonical turn `M6-CP3-TB-EXEC-174-P13-RETRACE-ORACLE-FULL-GATE` is **IN_PROGRESS**. The immutable artifact-only GitHub Actions runtime started on 2026-11-23 at 15:32:34 UTC. This record **does not claim a test result**. Do not start `TB-REV-174` or a Code + Build turn from this in-flight record.

## Background — exact frozen authority
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8.
- CB-195 semantic/executable source `29415df1ca8d76825a531092f65ff85e4ecd3b9d`; GMP/GMPXX compile workflow `45198338115`; immutable package artifact `14832291155`.
- Downloaded compile-package ZIP was verified locally: SHA-256 `7a06da51b899ba73f7e9b2375275be87dceeab86dba469cae5bad5be6cf6350c`; all **28/28** internal checksums pass. Package metadata: `runtimeExecution=false`, `exactArithmeticBackend=GMP`. Packaged source archive SHA-256 `c7531eb2611d3fd1d16d6476f8c03a974f062fa32b90350e0dea54be598763d8`; root SHA256SUMS SHA-256 `198f52e83ea2251f7435e40f25a149b429096448290fca9b1754a4d618be12e4`.
- Packaged harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`: SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Frozen case manifest `.agents/Directional/gates/Architecture_M6_TB174_P13_Retrace_Oracle_Full_Gate_Case_Manifest.tsv`: **998** rows; SHA-256 `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7`. Deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- TB173 comparison artifact `14821438542`, downloaded and locally SHA-256 verified as `22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`. It contains **989/996 PASS**, the seven prior mechanical RED rows **445/652/653/656/658/660/786**, and 1077 members; source `fae9eb71bb5806d71901cc2ccb8c925201be0c0a`.
- Strict durable dispatcher request pushed at commit `069c2c185af05fecf21cebb1359df1adef076be4`; request ID `m6-cp3-tb174-retrace-oracle-20261123-a`, mailbox key `m6-cp3-tb174-retrace-oracle-full-gate`.
- [Run 45206305297](https://github.com/akashskypatel/Directional/actions/runs/45206305297): dispatcher schema checks and request parse PASS; runtime job `137803112432` started 15:32:34 UTC, last observed in progress. `compile`, `drive_apply`, and `noop` jobs skipped. No source/test/fixture/selector/manifest edits or rebuild in this TB turn.

## Assessment — not yet measured
Frozen expected outcome: **991 PASS / seven known RED**, rows 995–998 PASS, 1079 total membership. These are requirements, **not observed results**. No gate acceptance, CP3/497/D0/H4 promotion, new regression ID, full-prefix comparison, or runtime pass claim is made.

## Same-turn continuation before closeout
1. Read `.workflow-mailbox/m6-cp3-tb174-retrace-oracle-full-gate/latest.json` on **ref `workflow-mailbox` only** after this run reaches terminal publication; match run `45206305297`, request and source identities. If mailbox publication fails, use this known run ID directly.
2. Fetch the run's final job and artifact metadata; download the immutable result ZIP once, verify SHA-256 and all internal checksums, `execution-boundary.json`, full 998-row ledger, 1079 membership, exit and unchanged compile/relink/configure/benchmark flags.
3. Compare every prior row 1–996 with the TB173 result, including full normalized raw logs. Permit only N1 Google Test duration, N2 newline differences, N3 full diagnostic-record reorder when proved, and independently proved assertion-line moves (none expected). Unexpected drift: STOP and route to Review; no production census.
4. Check rows 997–998 and 995–996, seven known mechanical RED rows, required control accounting, CP2 491/491 accepted baseline, staged-only row979, and stable regression accounting.
5. Record the actual result (including failed-closed evidence if red) here and in `Regression_Root_Cause_Tracker.md`, then update `TODO.md`, `Future_Chat_Session_Handoff.md`, and change history under retention/patch-transport rules. Close this same turn only after durable evidence and final STATUS write. The authorized successor is `M6-CP3-TB-REV-174-P13-RETRACE-ORACLE-FULL-GATE`; **do not start it during TB174**.
