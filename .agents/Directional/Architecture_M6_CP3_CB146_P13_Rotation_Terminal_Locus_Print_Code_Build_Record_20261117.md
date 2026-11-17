# CB146 — rotation terminal locus print (Code + Build; 2026-11-17 UTC)

## Situation
- Turn: `M6-CP3-CB146-P13-ROTATION-TERMINAL-LOCUS-PRINT`. [RA-246 §4](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md#4-cb146-frozen) authorizes the exact test-only change.
- Source `48e6f97d278b2226036f658ce9060a38b8a374b5`; compile-only [run 44022151247](https://github.com/akashskypatel/Directional/actions/runs/44022151247) SUCCESS.

## Background
- CB144B source `5d4077303a1aa46f0755421b607509694177c17f`, package `14299943924`; TB126 950/951, guard extent corrected in CB144B. BunnyRandom's face-only rotation terminal (candidate C5) needs the typed reason already present in the locus. No producer repair authorized.
- Snapshot `ec854197b4d1de6f2bf73248dd9194af6fb4f7d8`, [run 44021269683](https://github.com/akashskypatel/Directional/actions/runs/44021269683), artifact `14300508886`; outer SHA-256 `fee4ded64fa4052c6071495784496d3628f9e6cadd35a82dc39b56b30e509df4`, 5,511/5,511 checksums. Comparison against CB144B source shows only documentation and control changes before CB146.

## Assessment
- Exact [72-line diff](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Exact.diff), SHA-256 `4f1fae63d0d3f2626f02c4f27d26a923e0a525173112556fefe50d9e5be56967`, applies only to `tests/SurfaceCellDesignAcceptanceTests.cpp` (+61/-0). Git preimage `302ce62dff54836c6f14cdb92a33aa27e869fdc3`, postimage `c71080341d4f7b09ab3f27925d8d9b9c871c7bc0` verified remotely. Postimage SHA-256 `898d04c1dac0ee609497220b978653acd316c72f39356b45193729757c636477`. Existing terminal text stays as a prefix; append existing typed fields, including reason and ray/fan details. Apply and whitespace checks pass. No assertion, fixture, product, selector, manifest or benchmark edits.
- [Apply run 44021793173](https://github.com/akashskypatel/Directional/actions/runs/44021793173) SUCCESS; result/log `14300838889`/`14301735195`, both outer hashes verified; preservation patch SHA-256 `a28b4d534ceef83c57346366f46e503b2fc1789c8eddb214d2cc2ca8c0795f08`. Drive staging deleted with owner-authorized connector after verified apply.
- Gate manifest SHA-256 `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; both unchanged.
- Compile request event `5a05ab18737401ee8c04bfac1abdc8a2b38b8230`; package `14301616031`, outer SHA-256 `457a9d061cbfe290baa1cad0b3df29b085f81f639dd8ea7e829e38aea6458984`; log `14301033164`, SHA-256 `a81a78362b86118d9e4bc4d47d94ceb6e5859ad25e335ea514b0111feb637138`. 28/28 package checksums verified, source clean, exact test postimage and manifest hashes verified, eight approved targets and GMP (GNU Multiple Precision Arithmetic Library) plus GMPXX C++ interface verified. Build exit 0; `runtimeExecution=false`. No gate, census, or benchmark executed.

## Recommendation
- Exactly next, separately: `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC` per [RA-246 §5](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md#5-tb127-frozen). Use the CB146 package; 951-row gate, 1,032 membership, three-case census. Require all frozen MATCH conditions; record BunnyRandom suffix verbatim without deciding outcome in CB146. No repair or promotion.
- Stable 66/17/49, debt1, deferred81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`; C3/O42/O43 open, O44/C1 closed, C5 exact site unresolved. D11=A, D12=A, D10 deferred, D6 pending. PR #8 remains draft and unmerged.
