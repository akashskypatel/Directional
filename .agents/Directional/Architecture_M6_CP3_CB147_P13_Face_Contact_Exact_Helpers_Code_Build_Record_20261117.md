# CB147 — exact face-contact helpers (Code + Build; 2026-11-17 UTC)

## Situation
- Turn: `M6-CP3-CB147-P13-FACE-CONTACT-EXACT-HELPERS`. [RA-248 §4](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md#4-cb147-frozen-pure-exact-face-chart-helpers-not-wired-in) authorizes the frozen change. Exact implementation source `43294bde49e1f24aa09d10ca7e5ff632a7c28d6b`.
- Compile-only [run 44039082778](https://github.com/akashskypatel/Directional/actions/runs/44039082778) SUCCESS; package `14309111230` (ZIP SHA-256 `63fdbd1a3039d63a7d934407276ef4831b3914be27fd162da8b95067d83dafd1`), log `14309240475` (ZIP SHA-256 `5bf6f2ad9643169d8fbd8470f8d1355d8ddefe8d3eb6689a1a3eeb2558a171f4`); 28/28 package checksums verified. All eight targets, exact source, three changed-file postimages, unchanged gate/census manifests, clean source and GMP/GMPXX linkage verified. Build exit 0; `runtimeExecution=false`.

## Background
- Snapshot `008481473332610746d994874b0b1b913e1599ec`, [run 44038020619](https://github.com/akashskypatel/Directional/actions/runs/44038020619), artifact `14307961777`; ZIP SHA-256 `55b12a602027be146cbf4c01620fb8b3d3dd039ea7f57985982776a884daf109`; 5,516/5,516 file checksums verified. Comparison against CB146 source `48e6f97d278b2226036f658ce9060a38b8a374b5` shows no changes under `src`, `include` or `tests` before CB147.

## Assessment
- Applied the exact [257-line diff](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff), SHA-256 `5c3def45e8bdd713ca321b7cfca0f9f3a5935bdf54900afd5548efc55e5df7d1`, adding 92/35/100 lines to `src/geometry/EmbeddedGraphTopology.cpp`, `src/geometry/EmbeddedGraphTopology.h`, `tests/FieldAlignedCurveNetworkTests.cpp`. Local apply and whitespace checks pass; remote postimage Git blobs `70af0a1ec3817cbc3a1a29df47b313513722bd3d`, `27e8114e3e11ffd99891a5473ebf3e8867239d75`, `98bec9b3e73b014423f633b0160f0726130c6099` match. The three helpers remain unwired. No other product, test, fixture, manifest or selector edit.
- Test `FaceChartExactGeometry.OrdersRaysAndContactsExactlyAroundAFaceInteriorPoint` is future TB128 row 952, not executed. Gate manifest SHA-256 `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`, census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; unchanged.
- [Apply run 44038513541](https://github.com/akashskypatel/Directional/actions/runs/44038513541) SUCCESS; result/log artifacts `14308840738`/`14307783709` (outer hashes verified), preservation patch SHA-256 `b17fb3b28d10c77528d747fafb9774e87973c31928a652a45cf9df549f428220`; Drive staging deleted after verified application.
- Initial compile request [run 44038887899](https://github.com/akashskypatel/Directional/actions/runs/44038887899) rejected unsupported `retention_days` before compilation. Corrected the request only; no source change. Retry event `f5bd842765675cfaf7cb008aeb78e1487468bd72`.
- [Cleanup run 44038987033](https://github.com/akashskypatel/Directional/actions/runs/44038987033) SUCCESS; result `14308397592`, SHA-256 `443d08977f11103a46ae4b9e7c2affb290ab063583237017b217a002ef171c3a`, commit `1107eb8303271bee5b48596cdc5d1a9b494adc92` removes the snapshot marker and manifest only. No durable control files removed.

## Recommendation
- Exactly next, separately: `M6-CP3-DEFN-P13-FACE-CONTACT-NODE-FREEZE` Review per RA-248 §5. Freeze CB148 (FC-1–FC-5) and TB128 manifest rows 952 and 953; no work on that Review has begun. Test row 952 is compiled, not run.
- Stable 66/17/49, debt1, deferred81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`; C5/O42/O43/O45/O46 open, narrow C3/O44/C1 closed. D11=A, D12=A, D10 deferred, D6 pending. PR #8 remains draft and unmerged.
