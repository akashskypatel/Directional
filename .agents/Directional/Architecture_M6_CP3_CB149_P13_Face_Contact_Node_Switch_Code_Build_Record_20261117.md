# CB149 — face-contact node switch (Code + Build; 2026-11-17 UTC)

## Situation

- Turn: `M6-CP3-CB149-P13-FACE-CONTACT-NODE-SWITCH`. [RA-249 §3](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md) authorizes the exact wiring change. Implementation source `85f9c703c5de86fb2b401cf83c03499a1ce73a27`.
- Compile-only [run 44054969830](https://github.com/akashskypatel/Directional/actions/runs/44054969830), job `133942076395`: SUCCESS. Package `14315237769`, ZIP SHA-256 `39ce6f17ed010d26bf3e65dace9100646fc215a3a8050bb8cae6d621dfb23926`; log `14315861951`, ZIP SHA-256 `0fc1ec0fb7ecf5b028ce7e67ed37e7c999c46a1f2ecc61fb9387d5944259cdca`. Dispatcher event `f4e5632b273dc3cd0163e3905347c4e2ef30ea51`, mailbox `m6-cp3-cb149-switch-compile-v1`, request SHA-256 `438e11decb9dd4453c24e79aa4f6320a207eb7237e1edebc45a814a8593668d7`.
- Package: 28/28 checksums pass. Source archive SHA-256 `b7a13ebccc299a3cb98bde7471c2e678b1a0ddd3e31e5d96e4f3e1d8e506fdf9`. Both compile exit codes are 0. All five source-status files are empty. `DIRECTIONAL_ENABLE_GMP=ON`, Release; both `libgmpxx.so` and `libgmp.so` appear in link evidence. `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Six executables and both libraries are present.
- Targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

## Background

- Verified source snapshot `53102343509b6fe94ce5fb5d99aead0f12f01866`, [run 44050732923](https://github.com/akashskypatel/Directional/actions/runs/44050732923), artifact `14314095686`; ZIP SHA-256 `1ec05ff5c1a156d17c6b7c1cdcb471d543a7e8d8aa60e704b8c8f02c0b36466f`; source archive SHA-256 `54dbb290ccf8a0a895700e9607962f04e3c2be7c038d8a4fb3364adc20fcffd0`; 5,522/5,522 file checksums pass. The CB148 reverse-check and CB149 forward-check pass. All five CB148 postimages match the frozen diff. CB148 source `e05d44b850c378b6e77965f0f314b561a8207435` remains the predecessor.

## Assessment

- Applied the [exact 270-line diff](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Exact.diff), SHA-256 `ddf87b85683e1f34322418ffd5303740822602d845faf3a80ecff9d8d817963c`, +148/-27 in `src/geometry/EmbeddedGraphTopology.cpp` only. Local forward and whitespace checks pass. GitHub and packaged postimage Git blob `bf38170a053d1fa1e5bf7a0ff26f1df8f7453b1d` matches the frozen postimage. All 371 packaged files under `src`, `include` and `tests` match the snapshot except that authorized file. No other product, test, fixture, manifest, selector or workflow edit; no validator relaxation.
- The switch connects the frozen collector, exact interior cuts and partial trace paths to arc construction, node loci and counter-clockwise face rotation. This is compile evidence only. The BunnyRandom witness and downstream ownership boundary remain open.
- Gate manifest `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`: 953 rows, first 951 byte-identical to TB126/TB127. Census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`: three rows. Both hashes and bytes match the frozen snapshot and the packaged source. No Directional binary, test suite, discovery command or benchmark ran.
- [Apply run 44054666908](https://github.com/akashskypatel/Directional/actions/runs/44054666908) SUCCESS; request event `357e8a59d1f4341ed088242d19af6f7a8038a88d`; result/log artifacts `14315052966`/`14314967725`, ZIP hashes `ef99dcfd365d952c6ba08d8468b05677544d103f363abbc8d853422764c0dae0`/`f1ef9b9f850d4bca8035de24e7fbad75e5a99dbba96707704526efbe8207e545`; full patch SHA-256 `3a1dd6f6f68d7a6b5d45364fa25a6e5467ce1e60438ec862d941d59628becf3e`. Owner connector deleted the consumed Drive file after verified application.
- [Cleanup run 44055067828](https://github.com/akashskypatel/Directional/actions/runs/44055067828) SUCCESS; result `14315902043`, ZIP SHA-256 `7c28a9c52d80b7a0d978855408799d3b5afc8906e067e6cc8370a9cc4424aa65`; cleanup commit `28b6c5206660937075151d654eddcf3e9df26ea3` removed the CB149 snapshot marker and cleanup manifest. No PR comments deleted; no durable control files removed. Pre-existing legacy markers are outside this turn's cleanup scope.

## Recommendation

- Exactly next, separately: `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC`. Execute only immutable CB149 package `14315237769` per RA-249 §4. Use the 953-row gate and three-case census. Preserve the 951 inherited ledger records and the exact comparison rules. Record BunnyRandom's new terminal verbatim; do not predict a successful outcome as evidence. No successor work has begun.
- Stable 66/17/49, debt 1, deferred 81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`. C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. D11=A, D12=A, D10 deferred, D6 pending. PR #8 remains draft and unmerged.
