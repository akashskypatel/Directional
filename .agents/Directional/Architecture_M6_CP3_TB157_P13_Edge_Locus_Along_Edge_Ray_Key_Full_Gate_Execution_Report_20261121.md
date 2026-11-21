# TB157 — immutable full-gate execution record (in progress, 2026-11-21 UTC)

## Turn authority
- Canonical turn: `M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft.
- Entry `STATUS` commit: `a772e4d6aad12008895b120fdadc526642869c2f`, `Started at: 2026-11-21T18:15:13Z`.
- Source-snapshot trigger: `3fb03720991b79f16371543f1b835a0bb2c0b7a1`; snapshot workflow [44934533315](https://github.com/akashskypatel/Directional/actions/runs/44934533315), artifact `14718564682`, ZIP SHA-256 `38438349589eecadebb6c11aeb44e4cfa3a523e80e9a0feac1d6b349f8903181`; 5683/5683 source checksums verified.
- Source-snapshot temporary trigger to clean after remote evidence capture: `.agents/connector-triggers/source-snapshot/m6-cp3-tb157-20261121-1016.txt`.

## Frozen package and baselines — verified locally
- Immutable CB173 semantic source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, compile artifact `14718074764`, outer ZIP SHA-256 `cad613506dbadff3179f17a8492a57062d31cf27cfff6d1378417f351ab5ad09`, 28/28 packaged checksums verified. No rebuild, relink, test-source, fixture, or selector mutation.
- Previous full-gate artifact `14715014772`, ZIP SHA-256 `0bfac9c0eaf626408d666a5bd298b681236e7f54c69bfd25340b6064aa8d1e9b`, 972 rows; downloaded and checksum-verified.
- Previous census artifact `14716036015`, ZIP SHA-256 `847b88f3e95881ed2044c6ed9cd49bce9eba1e89a567a95bb202d3fbe8bd1680`, three rows; downloaded and checksum-verified.

## Remote TB157 work submitted — results not yet accepted
- Full gate dispatcher request commit: `c3d7a59111e7d4e2fecde5ec332ba5c72c316fd3`, request `m6-cp3-tb157-gate-20261121-v1`, mailbox key `m6-cp3-tb157-gate-v1`; manifest SHA-256 `92eb18e8aaf2881d933c88dfde1a86b957334fe6785fd88f404459812cdc50c7`, 975 cases.
- Production census dispatcher request commit: `023d516b7ce12fb9960ee83732b1302279e8cfaf`, request `m6-cp3-tb157-census-20261121-v1`, mailbox key `m6-cp3-tb157-census-v1`; manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, three cases.
- Both requests use source-snapshot executor `3fb03720991b79f16371543f1b835a0bb2c0b7a1`, the immutable CB173 artifact, and the verified generic artifact-only harness with SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Dispatcher requests are separate event commits; `.agents/Directional/agent-dispatch-request.json` is a retained mutable slot. Do not replay either request solely because its mailbox has not yet published.
- As of the initial mailbox checks, neither `.workflow-mailbox/m6-cp3-tb157-gate-v1/latest.json` nor `.workflow-mailbox/m6-cp3-tb157-census-v1/latest.json` had published on the orphan `workflow-mailbox` branch. This is pending remote execution, not a test failure. No TB157 PASS/RED result is claimed.

## Complete this same TB157 turn only
1. Fetch each exact mailbox record on `workflow-mailbox`, verify its event SHA matches the recorded request commit and source/executor authority; fetch the exact run's jobs and artifacts once; download each result only once.
2. Verify outer ZIP digest, internal `SHA256SUMS`, manifest, package/source identity, postflight, and immutable execution boundary (no configure/compile/relink/benchmark).
3. Check 975/975 PASS and CP2 491/491; compare gate rows 1–972 to TB156 using N1–N3 with **empty allowance**; compare census 3/3 to TB156 using N1–N4. Record actual row differences and every forbidden `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge`, or `FirstPieceNotLeavingLocusIntoFace` hit.
4. Update this owning report, the Regression Root Cause Tracker (all observed regressions or explicitly no new stable regression), TODO, handoff, and CHANGELOG; run required drift and temporary-file cleanup gates. Stop on any genuine regression; do not promote CP3, selector 497, D0, or the unwired stop switch.
5. Direct-write root `STATUS` as the **final repository action**: COMPLETE only after durable green evidence, otherwise IN_PROGRESS with original Started at and empty Ended at. If green, successor for a future turn only: `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`.

Status: **IN_PROGRESS; remote results pending.** No build or direct runtime acceptance claim.
