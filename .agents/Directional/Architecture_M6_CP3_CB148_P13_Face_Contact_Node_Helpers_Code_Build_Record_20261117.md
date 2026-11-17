# CB148 — face-contact node helpers (Code + Build, in progress; 2026-11-17 UTC)

## Situation
- Frozen RA-249 additive implementation applied and verified at `e05d44b850c378b6e77965f0f314b561a8207435`; compile verification pending. This is not a compile-success record.
- Compile-only dispatcher event `43e6302d50e6293d335a34da2ee0fcd22603bf8b`, request `m6-cp3-cb148-compile-v1`, exact source above, eight RA-245 targets. Read `.workflow-mailbox/m6-cp3-cb148-compile-v1/latest.json` on `workflow-mailbox`. No result was visible at closeout preparation. Do not submit an identical request merely because the mailbox is absent.

## Background
- Snapshot `ce3bcb21dbd77041a4edaf3d57c6c502c5905d3e`, [run 44043983914](https://github.com/akashskypatel/Directional/actions/runs/44043983914), artifact `14310657004`; ZIP SHA-256 `a6c123e6d8058d125c718f1932cfee77f5a1fac6710ab7fc7f635769d48cd16b`; 5,521/5,521 checksums verified. Comparison to CB147 `43294bde49e1f24aa09d10ca7e5ff632a7c28d6b` confirms no prior source/test changes.
- [Apply run 44044553058](https://github.com/akashskypatel/Directional/actions/runs/44044553058) SUCCESS, result/log artifacts `14310592783`/`14310338197`, ZIP SHA-256 `1ffbea9f5d28f4b3633368a45c7ddaebdc15ad118f45663c01178e05b6a729d8`/`3dc4e611401a49ff2b67da16f13c32de9812f0533db273dc50ef088f352ebe84`. Patch SHA-256 `afdb4a3e7c7a455664049af0a44221c368efd7fe4069f36dc9b8665b8566c9fb`. Drive staging retired after verified application. Recovery patch in File Library.
- [Cleanup run 44044997569](https://github.com/akashskypatel/Directional/actions/runs/44044997569) SUCCESS, result `14310883076`, SHA-256 `bfb70faac3f9f840f803f41cac6c2bea56f78af38155c78a25b1465780d42bcb`; commit `e991f2d5aec1198a30b1d13e44a8fd77418e9f16`. Removed only the CB148 snapshot marker and manifest; no PR comments deleted.

## Assessment
- Exact [diff](Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff) SHA-256 `b4b8248715e04996bcdc22f2146497d9957bb0923f5602dabbac3c4b44dced6e`, 475 lines, +416/-0. Local apply, reverse apply, whitespace and byte comparison pass. Remote postimages match:
  - `include/directional/geometry/GlobalTopologyPlan.h`, 6, `f33816d1af5abfb2ded60e15b153e1a569061a2f`;
  - `src/geometry/EmbeddedGraphTopology.cpp`, 216, `dfedf9beee23134b63357d05bdff2f2c399e792a`;
  - `src/geometry/EmbeddedGraphTopology.h`, 73, `f071bc8593d6b674a6d373000b2dcdb8d313c90b`;
  - `src/geometry/GlobalTopologyPlan.cpp`, 6, `63d3bbc7cbd2305abef8f5f60fe48a7766b66ad7`;
  - `tests/FieldAlignedCurveNetworkTests.cpp`, 115, `72705a82bd02d2589303fd189c82a650dda2c21f`.
- Helpers not wired in. Test `FaceContactNode.SplitsAStruckSegmentAtAnExactInteriorContactPoint` not run. No runtime, no other implementation/test/fixture/manifests/selectors change, no promotion. Frozen gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.

## Recommendation
- Resume **the same CB148 turn**. Verify the compile run, exact source, eight compiled targets, GMP/GMPXX linkage, clean source, package/log SHA-256 and internal package manifest. Update this record in place with verified results. Only after successful verification and durable closeout may STATUS record COMPLETE and CB149 become next.
- Stable 66/17/49; debt1; deferred81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`; C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. D11=A, D12=A, D10 deferred, D6 pending. PR #8 draft/unmerged.
