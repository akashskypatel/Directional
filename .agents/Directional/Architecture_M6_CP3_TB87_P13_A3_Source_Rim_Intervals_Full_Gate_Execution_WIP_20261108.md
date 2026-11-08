# TB87 — immutable full-gate/census execution continuation (2026-11-08 UTC)

**Canonical turn:** `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-EXEC` (step 63). This is an artifact-only Test + Benchmark turn; do not rebuild, repair, edit semantic source/tests/fixtures/selectors, or promote acceptance.

## Verified exact input authority

- CB104 semantic source `b41fbf72a4d4d2255b4b0e94e0148de8378e2364`, GMP eight-target compile [42484665857](https://github.com/akashskypatel/Directional/actions/runs/42484665857).
- Immutable CB104 package **artifact `13619640763`**, outer ZIP SHA-256 `0273b89a9a72ccebd4b5b18e1b60b489e615909bf748600eb924bff0a0c2fd98`, 28/28 internal checksums. Root SHA256SUMS SHA-256 `8d236199882f09a48aacec8495d137e2d024b377344780dad03ceb00734822b8`; source TAR SHA-256 `ce347cfea8f47e9a8569346b843a49aadbf65b5b3c93d9e0488a4f2116b6db4a`.
- Source-snapshot trigger commit `d398f94052fca28f755ecdecf04c31546a16262f`, [workflow 42487775179](https://github.com/akashskypatel/Directional/actions/runs/42487775179), artifact `13620151862`, outer SHA-256 `18cd18bf91709c9b0aee281ebb5ed25cd64bdd87c7b617b64d1e0f5772df78b0`; nested source TAR and 6255/6255 checksums verified. It is execution-control/document authority, not the semantic CB104 source.
- Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Both dispatcher requests select executor SHA = semantic source SHA `b41fbf72…` with this harness, no build operations.
- Full gate manifest `Architecture_M6_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Case_Manifest.tsv` SHA-256 `c435519f6304fdcedb794e45187c8c4645e0bb36d32ec567e7979d292fb245bf`: 910 rows including GUARD 909 and 910. Deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 rows; expected membership 991. Census manifest `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, 3 rows.

## Operations dispatched (no result claims until artifact verification)

1. 910-case gate request commit `66604de091a16e08076861cbf90c1e9e149411c2`, request `m6-cp3-tb87-gate-20261108-1405`, mailbox key `m6-cp3-tb87-gate`.
2. Three-case census request commit `e02483196176d69010b5d89c9f39532960711368`, request `m6-cp3-tb87-census-20261108-1405`, mailbox key `m6-cp3-tb87-census`.

These are sequential overwrites of the **durable** `.agents/Directional/agent-dispatch-request.json` slot. The dispatcher pins each request to its own event SHA; do not redispatch merely because no final mailbox is published. Discover terminal runs from `.workflow-mailbox/<mailbox key>/latest.json` on orphan ref `workflow-mailbox`, verify exact request and event SHA, fetch jobs/artifacts once, download each result once.

## Required verification / routing

- Full gate 910/910 PASS, membership 991, package checksums and postflight true; GUARD 909/910 PASS. Compare raw `platform-digest` **and** `a3-coverage` lines of gate rows 795/796/797/864 byte-for-byte against TB86 gate artifact `13613643740`.
- Census 3/3: Cylinder PASS, BunnyRandom P13-e expected RED, Vase legacy expected RED; compare each raw `platform-digest` and `a3-coverage` line byte-for-byte against TB86 census artifact `13613991005`. Check no abnormal/missing/skipped/control errors, package postflight true, no build.
- TB86 baseline result artifacts locally verified: gate 1826/1826 internal checksums, 909/909, 990 membership; census 9/9 checksums, 1 PASS/2 registered RED. Historical stable accounting remains CP2 491/491, 66/17/49, debt 1, 81 deferred; CP3/selector497 unpromoted.
- If matching, complete the owning TB87 report, tracker, TODO, handoff, changelog and proceed only on a **new turn** to step 64 `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC`.
- If semantic mismatch, next turn `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-REV`; if infrastructure-specific, `M6-CP3-TB87A-P13-A3-RECORDED-BOUNDARY-INTERVALS-ORCH`.
- For a bounded time-window yield, retain this same TB87 turn as `IN_PROGRESS` (not `BLOCKED`), preserve its initial `STATUS.Started at` `2026-11-08T14:01:25Z`, and set `Resumed at` on the next attempt. No test or build outcome is currently claimed here.

## Cleanup

One temporary source-snapshot trigger was created: `.agents/connector-triggers/source-snapshot/tb87-20261108-1402.txt`. Remove it with the authorized turn-cleanup workflow after preserving evidence. Never delete `.agents/Directional/agent-dispatch-request.json` or orphan-branch mailbox history.
