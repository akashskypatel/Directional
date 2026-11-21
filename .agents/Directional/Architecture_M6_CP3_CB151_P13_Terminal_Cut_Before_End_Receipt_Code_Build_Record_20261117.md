# CB151 — terminal cut before end receipt (Code + Build; 2026-11-17 UTC)

## Situation

- Turn: `M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT`. [RA-250 §R5](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#r5-cb151-terminal-cut-before-end-receipt-diagnostic-only-replaces-cb149b) authorizes the exact diagnostic-only diff. Semantic source `c45e9abe5085f39c1f5bcb149ec07f95b719177e`.
- [Compile run 44081373209](https://github.com/akashskypatel/Directional/actions/runs/44081373209), job `134032867220`, SUCCESS; package `14327212608`, ZIP SHA-256 `9ef0f781947748cf2433566f3704259ab362dbf8f042999f87248ca6d645eb69`; log `14327402145`, ZIP SHA-256 `6fffc14fea2d7b9ded5de7437e97bb3de0ff7b35ebb240921d9fec4be690e10f`. Package and log ZIP hashes verified; 28/28 checksums, 371/371 packaged src/include/tests files equal the authorized snapshot+patch; frozen manifests match. Both exit codes 0; five empty source-status files. All eight targets present (six executables and two libraries); Release, DIRECTIONAL_ENABLE_GMP=ON, GMP/GMPXX link evidence, exactArithmeticBackend=GMP, runtimeExecution=false. Source archive SHA-256 434a3817c90395366c572287e205c3d0d9268241817b20c3f106ba6e2a500417.
- Dispatcher event `77b12231e3e791227516c6da2bc805b70e5fc1d6`; mailbox `m6-cp3-cb151-compile-v1`. [Cleanup run 44081829660](https://github.com/akashskypatel/Directional/actions/runs/44081829660), job `134034191689`, SUCCESS; result `14327901413`, ZIP SHA-256 `61162108a55c18ea4ceab3bff37a697bed3c9e210492b99008ddc89ef7b71df2`; cleanup commit `802ac656a0c2de45b48ab37264ad35c04576107f`.

## Background

- [Snapshot run 44080151754](https://github.com/akashskypatel/Directional/actions/runs/44080151754), job `134028440990`; source `bfc133744a434c7b1fb175c7f609ed727060646e`; artifact `14326159467`, ZIP SHA-256 `07f73973bb450355ac675d85f064e8d3ffdd9a21946e16001db9a2a81c60b97a`; source archive SHA-256 `733f75cf2ca806664745aaa4997c82f147a82b1a55ea4367852d9d5af41322af`; 5,521/5,521 checksums pass. CB149 to CB150 comparison contains only the authorized test change in `src/include/tests`; CB150 to the snapshot has no changes in those directories. CB150 reverse applicability passes.

## Assessment

- Applied the [frozen 168-line diff](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff), SHA-256 `044529d63c2f9e82cad38fb95cad00d4fa299918c6bcd02ffb3c56cc1947b516`, +129/-0 in `src/geometry/EmbeddedGraphTopology.cpp` only. Forward/reverse applicability and whitespace checks pass; remote postimage `ab9e746e4a3f7b6bbc05e11e2f7acc93e6340242` matches. The receipt adds evidence for a Terminal incidence resolved before trace end; no accepted/rejected product decision changes. No test, fixture, manifest, selector or workflow edit.
- [Apply run 44080839434](https://github.com/akashskypatel/Directional/actions/runs/44080839434), job `134030953058`, SUCCESS; dispatcher event `0244a80c59558b695796f558f51188bd60145a7f`; result `14328020318`, ZIP SHA-256 `23d3badc1e723a9e9b91b9394136001fb0446dd603065ce490b8b233f66b1feb`; log `14326378557`, declared ZIP SHA-256 `0cfee451f711a42d09c59bc886746197c3978abc66a41cc153550adb6cb181d7`; full patch SHA-256 `1d5b999621f4057b974018cad3f1b97f746c921048b52320c4c303f546be5229`. The result ZIP was verified. Owner connector deleted the consumed Drive file successfully.
- Gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` (953 rows) and census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (three rows) remain frozen. No Directional binary, test suite, discovery command or benchmark ran in this turn. No runtime verdict or H1/H2 classification is claimed.
- Stable 66/17/49, debt 1, deferred 81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`. C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. PR #8 remains draft and unmerged.

## Recommendation

- Exactly next, separately: `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC`; use the verified immutable CB151 package, frozen manifests and RA-250 §R6. No successor work began.
