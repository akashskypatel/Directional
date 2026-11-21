# CB150 — face-chart witness correction (Code + Build; 2026-11-17 UTC)

## Situation

- Turn: `M6-CP3-CB150-P13-FACE-CHART-WITNESS-CORRECTION`. [RA-250 §R1](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#r1-row-952-the-replacement-witness-is-verified-independently) authorizes this test-only change. Source `b3d7b66e10ed8cfdd94eb0a1f67222efcd2525d9`.
- [Compile run 44077561426](https://github.com/akashskypatel/Directional/actions/runs/44077561426), job `134019593477`, SUCCESS. Package `14325348753`, ZIP SHA-256 `4bfe84808ac5d88dc23c607e8d31bb2e4a9af4406d6523432cce7e5c388f470d`; log `14324952839`, ZIP SHA-256 `368ebd179659a7133c09c4fbaf4c0db064a667a567914853cfcf59779baf4575`; dispatcher event `65ee9fce2202a752b74b6555443891cb0435f157`, mailbox `m6-cp3-cb150-compile-v1`, request SHA-256 `845295217b137b717c4ffb09b20a71f96f5bd26d307e248d845b8820d9019353`. Package 28/28 checksums pass. Source archive SHA-256 `02baf6c9a1f474503527228758be4a1c7349440feb1c568dc2f8585ae0f61a51`. Both compile exit codes 0; five empty source-status files. All eight RA-245 targets, six executables and two libraries present; Release, `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx.so` and `libgmp.so` in link evidence, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. All 371 packaged `src/include/tests` files match the snapshot except the exact authorized test postimage; frozen gate and census bytes match.
- [Cleanup run 44077801959](https://github.com/akashskypatel/Directional/actions/runs/44077801959), job `134020321079`, SUCCESS; result `14326001522`, ZIP SHA-256 `683b04373bf810b71f21f4e1996b4531fa37f362b7c5d7bd6dce8f13218f01b9`; cleanup commit `bdac7c285eb48c5ce4e038db273afb947ee8ff42`. Removed only the CB150 snapshot marker and cleanup manifest; no PR comments deleted. Durable dispatcher and mailbox retained.

## Background

- [Snapshot run 44076559128](https://github.com/akashskypatel/Directional/actions/runs/44076559128), job `134016109394`, source `ffcfc64fc3086f662f8088142cde078d8fa970be`; artifact `14324452525`, ZIP SHA-256 `f86243d4e276b0141b3d7ab6decd697981e213e379aeaa1abca2cec1473c2493`; source archive SHA-256 `df8a1e703144b49dd41b57bbcc0d7b8dfac816ed7b62ebb36a39d73019ca6dd0`, 5,520/5,520 checksums pass. GitHub comparison to CB149 `85f9c703c5de86fb2b401cf83c03499a1ce73a27` shows no `src`, `include` or `tests` changes before application.

## Assessment

- Applied the [frozen 49-line diff](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Exact.diff), SHA-256 `63a6bd0b95099f0be05b22ca5d0adb539569e5f5afa6b2d8950a6b2ab9e905ba`, +10/-7 in `tests/FieldAlignedCurveNetworkTests.cpp` only. Local forward/reverse applicability and whitespace checks pass. Remote postimage Git blob `693782f591d9fbec5227e57bce34ea2717fb465a` matches. Row 952 uses non-dyadic coordinates to avoid the false double-conversion premise under GMP truncation; assertions are unchanged. No product code, other test, fixture, manifest, selector or workflow edit.
- [Apply run 44077127228](https://github.com/akashskypatel/Directional/actions/runs/44077127228), job `134018079921`, SUCCESS; dispatcher event `86ab9c1940bfe23467c5e6f147c8cd25f9570890`; result/log artifacts `14325641604`/`14325771346`, ZIP hashes `356dfbe6b425428339bdabb7c94b25753fc90164815fd4444d35744ebd98faf6`/`362501afeb157766bc005ee01f52f60bc1fe7f9525213dd14c609a45f0bc0746`; full patch SHA-256 `ba500f3f9abf8ed81a5866dd70e8ed62626caea6110baf4ae5256c58874f0ea7`. Owner connector retired the consumed Drive file successfully.
- Gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` (953 rows) and census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (three rows) remain frozen. No Directional binary, test suite, discovery command or benchmark ran in this turn. No runtime verdict is claimed.
- Stable 66/17/49, debt 1, deferred 81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`. C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. PR #8 remains draft and unmerged.

## Recommendation

- Exactly next, separately: `M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT`; use the frozen diagnostic-only diff and RA-250 §R5. Do not execute binaries or modify the gate. No successor work began.
