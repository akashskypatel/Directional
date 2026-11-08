# TB88 — artifact-only gate and census execution (WIP; 2026-11-08 UTC)

Canonical turn: `M6-CP3-TB88-P13-A3-OBSERVED-ROUTE-ORIENTATION-FULL-GATE-EXEC`. The turn remains unfinished. Preserve `Started at: 2026-11-08T16:30:56Z`; on a subsequent attempt set `Resumed at` and leave `Ended at` empty until formally COMPLETE.

## Frozen authority and verified preflight
- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft. Entry STATUS commit `51e051ff81fcf386d5cac0321f743c50833f075f`.
- Exact source snapshot trigger commit `4e552e85611f06967e3b3f6ca1ec5e1cca67cc0b`; run [42500336108](https://github.com/akashskypatel/Directional/actions/runs/42500336108), artifact `13625461764`, ZIP SHA-256 `6832d9e21031674568f4b6b4eab6e2b4f27abed828f26df6d86b8c07a6b0c983`; 6260/6260 file hashes verified. This snapshot is executor/control source, not the semantic compile source.
- Immutable CB105 GMP compile package `13624369054`, exact source `d96df38e5ebfe33bbf979f27a82f7a5a332a7738`; package ZIP SHA-256 `3c044ac3ba37a69b9a2e34f140c53412f2628c2a2fe64e2bbd431179d9dd0857`; 28/28 checksums passed, root manifest SHA-256 `17331ebf9c7d9f3de32366f4a2bf5ddf8cbb238afa9397a137fa8382f6407f89`, source archive SHA-256 `58080376ede67c5e51d97a83e01db9f9affd03f98b0650380ae9eeb728a814ae`; runtimeExecution=false, GMP.
- Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; frozen gate manifest SHA-256 `c435519f6304fdcedb794e45187c8c4645e0bb36d32ec567e7979d292fb245bf` (910 cases); deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 rows; required membership 991). Frozen census SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 cases).
- TB86 reference gate artifact `13613643740`, 1826/1826 stored hashes; reference census `13613991005`, 9/9 stored hashes. Both downloaded and verified.

## Dispatched operations — semantic results NOT YET known
1. Full gate: request commit `19e38c220dba8e65d48da7b65c1a544c073ea6e7`, mailbox key `m6-cp3-tb88-gate`, request ID `m6-cp3-tb88-gate-20261108-1636`. Required result 910/910, membership 991, GUARD 909 and 910 PASS.
2. Census: request commit `51b8fa03a942e0136a9a9f26a982140daf67dcab`, mailbox key `m6-cp3-tb88-census`, request ID `m6-cp3-tb88-census-20261108-1636`. Required outcomes: Cylinder PASS; BunnyRandom P13-e RED; Vase legacy-completion RED.
Both requests pin exact compiled CB105 source and reuse the artifact-only harness. No source/tests/fixtures/selector/build or workflow YAML mutated. The second request intentionally overwrote the durable dispatcher slot; each run consumes its own event SHA. Do not retrigger solely because mailbox publication is pending.

## Resume/checks
Read each `.workflow-mailbox/<key>/latest.json` on `workflow-mailbox`, match event SHA against its request commit, fetch jobs/artifacts once, download each result, verify outer/internal hashes, execution-boundary/postflight/source identity and raw logs. Compare all raw `platform-digest` and `a3-coverage` lines byte-for-byte with TB86: gate rows 795/796/797/864, census 1/2/3 (7/7 of each). Any failure must be classified without changing frozen tests. On MATCH, update owning TB report, regression tracker, TODO, handoff and changelog; authorized successor is `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` only after formal TB88 COMPLETE. On mismatch route to independent Review, not in-TB repair. Stable CP2 491/491; stable 66/17/49, debt 1, 81 deferred, selector497/CP3 remain unpromoted. Do not claim success from dispatch alone.

Temporary source-snapshot marker to clean: `.agents/connector-triggers/source-snapshot/m6-cp3-tb88-20261108-1631.txt`. Preserve durable dispatcher request and all `workflow-mailbox` history.
