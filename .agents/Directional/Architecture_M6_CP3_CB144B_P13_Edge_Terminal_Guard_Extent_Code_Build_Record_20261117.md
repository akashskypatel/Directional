# CB144B — mandatory-edge terminal guard extent correction (Code + Build; 2026-11-17 UTC)

## Situation
- Turn: `M6-CP3-CB144B-P13-EDGE-TERMINAL-GUARD-EXTENT-CORRECTION`. [RA-245 and RA-246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md) authorize the test-only correction.
- Source `5d4077303a1aa46f0755421b607509694177c17f`; compile-only [run 44019533988](https://github.com/akashskypatel/Directional/actions/runs/44019533988) `SUCCESS`.

## Background
- TB126 result 950/951; row 951 threw before the two-cut guard because trace ID 38 used extent 16. The frozen 19-line [diff](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff) sets node extent 16 and trace extent 39; all assertions and identities remain unchanged.
- Snapshot `fcfec94620ae89b96c28ad29f9c36381fece50c6`, [run 44018721386](https://github.com/akashskypatel/Directional/actions/runs/44018721386), artifact `14300465544`, outer SHA-256 `f7bac1f40844f3c1bc162a3c70de804956a8059466c1a54fc55d73a36e4dd5f0`, 5,510/5,510 checksums. Compared against CB144 semantic source `7b0668d432ccb187c5a2d856494064f0bcb2fb95`; only docs/control changed before correction.

## Assessment
- Frozen diff SHA-256 `20aeaf0d6e999c12d634f7c505418628add662b4484fdfa6dddaa63c3b1ed4ae`. Only `tests/FieldAlignedCurveNetworkTests.cpp` (+4/-3); preimage SHA-256 `417ef255e893af1cf46a736c99b5af1d593de97bf58559a47aa30088baaf1f89`, postimage `9160790d7e9830aee73bc6ce9094e277a49d5cff84036c74ac18b396db38b67e`. Exact remote blob `64400ccf6ebd5fe845fd7353d8b20da856d8b90d`; apply and whitespace checks passed.
- [Apply run 44019261912](https://github.com/akashskypatel/Directional/actions/runs/44019261912), result/log artifacts `14300526103`/`14299564904`, both ZIP hashes match mailbox. Preservation patch SHA-256 `0f0a7631511cf28e7f9bdb344d6323e010c9f94349fbbbacb27b2545235379a8`. Drive staging retired by owner-authorized connector.
- Gate manifest SHA-256 `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; frozen selector/manifest bytes unchanged.
- Compile package `14299943924`, outer SHA-256 `186f213904be8e1da3d25a649c425c2ea782c006967a6f9025814d7b9801fe3e`; log artifact `14300631663`, SHA-256 `0832122708f0a35e795d1c5142ddfcf66df442465b4b9f3a16b2a9df6fafe691`. All 28 checksums verified, source archive test postimage matches, source status clean; all eight approved targets present and build exit 0. GMP (GNU Multiple Precision Arithmetic Library) exact backend with GMPXX C++ interface linkage verified. `runtimeExecution=false`; row 951 compiled, not executed.

## Recommendation
- Exactly next separate turn: `M6-CP3-CB146-P13-ROTATION-TERMINAL-LOCUS-PRINT`, RA-246 §4. Apply only its frozen test-only diff and compile the eight approved targets; no runtime. TB127 subsequently uses that combined package, not this package alone.
- Preserve stable 66/17/49, debt 1, deferred 81, CP2 491/491 and CP3/selector497 unpromoted; `chainRimSchedules=false`. C3/O42/O43 open; O44/C1 closed; C5 unresolved. No successor work or promotion in this turn. PR #8 remains draft and unmerged.
