# CB148 — face-contact node helpers (Code + Build; 2026-11-17 UTC)

## Situation
- Turn: `M6-CP3-CB148-P13-FACE-CONTACT-NODE-HELPERS`. [RA-249 §3](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md) authorizes the frozen additive change. Exact implementation source `e05d44b850c378b6e77965f0f314b561a8207435`.
- Compile-only [run 44044928423](https://github.com/akashskypatel/Directional/actions/runs/44044928423), job `133908372327`: SUCCESS; package `14311412337` (ZIP SHA-256 `e495ecc80c3828ca624483afb4f5062d28cb12da9828e9ec99a073b99284bb37`), log `14311092914` (ZIP SHA-256 `ab5b2b86c773b584d27d29de94b9e26159a61653c5e2b9d740bc50bb567c17bd`); 28/28 package checksums verified. All eight targets, exact source, five changed-file postimages, unchanged frozen gate/census manifests, clean source and GMP/GMPXX linkage verified. Build and preflight exit 0; `runtimeExecution=false`. Source archive SHA-256 `47b44be840f581bacbb956eb0e57c0d3893a94bb1239b98814bc61213cf766ac`; dispatcher event `43e6302d50e6293d335a34da2ee0fcd22603bf8b`. CMake `DIRECTIONAL_ENABLE_GMP=ON`, Release.
- Compiled targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

## Background
- Snapshot `ce3bcb21dbd77041a4edaf3d57c6c502c5905d3e`, [run 44043983914](https://github.com/akashskypatel/Directional/actions/runs/44043983914), artifact `14310657004`; ZIP SHA-256 `a6c123e6d8058d125c718f1932cfee77f5a1fac6710ab7fc7f635769d48cd16b`; 5,521/5,521 file checksums verified. Comparison against CB147 source `43294bde49e1f24aa09d10ca7e5ff632a7c28d6b` confirms no prior changes under `src`, `include` or `tests`.

## Assessment
- Applied the exact [475-line diff](Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff), SHA-256 `b4b8248715e04996bcdc22f2146497d9957bb0923f5602dabbac3c4b44dced6e`, +416/-0. Local apply, whitespace and byte comparison checks pass. Remote postimages (path, added lines, Git blob) match:
  - `include/directional/geometry/GlobalTopologyPlan.h`, 6, `f33816d1af5abfb2ded60e15b153e1a569061a2f`;
  - `src/geometry/EmbeddedGraphTopology.cpp`, 216, `dfedf9beee23134b63357d05bdff2f2c399e792a`;
  - `src/geometry/EmbeddedGraphTopology.h`, 73, `f071bc8593d6b674a6d373000b2dcdb8d313c90b`;
  - `src/geometry/GlobalTopologyPlan.cpp`, 6, `63d3bbc7cbd2305abef8f5f60fe48a7766b66ad7`;
  - `tests/FieldAlignedCurveNetworkTests.cpp`, 115, `72705a82bd02d2589303fd189c82a650dda2c21f`.
- The exact trace cuts, face-contact collector, and three rotation reasons are not wired in. No other product, test, fixture, manifest or selector edit. Test `FaceContactNode.SplitsAStruckSegmentAtAnExactInteriorContactPoint` (future TB128 row 953) is compiled, not run. Gate manifest SHA-256 `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`, census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; unchanged.
- [Apply run 44044553058](https://github.com/akashskypatel/Directional/actions/runs/44044553058) SUCCESS; result/log artifacts `14310592783`/`14310338197` (ZIP hashes `1ffbea9f5d28f4b3633368a45c7ddaebdc15ad118f45663c01178e05b6a729d8`/`3dc4e611401a49ff2b67da16f13c32de9812f0533db273dc50ef088f352ebe84`); preservation patch SHA-256 `afdb4a3e7c7a455664049af0a44221c368efd7fe4069f36dc9b8665b8566c9fb`. Drive staging deleted after verified application.
- [Cleanup run 44044997569](https://github.com/akashskypatel/Directional/actions/runs/44044997569) SUCCESS; result `14310883076`, SHA-256 `bfb70faac3f9f840f803f41cac6c2bea56f78af38155c78a25b1465780d42bcb`, commit `e991f2d5aec1198a30b1d13e44a8fd77418e9f16` removes the snapshot marker and manifest only. No durable control files removed.
- Previous [in-progress record application run 44046042670](https://github.com/akashskypatel/Directional/actions/runs/44046042670) succeeded at `34ad4c53613db139a762f97c202509ef02c60fd8`; result/log artifacts `14311941175`/`14311901218` (ZIP SHA-256 `44c1c801226735de29024fbfa58e13e5ab75d785021d6b1d3109f1aff68ceb77`/`375ac5ae5f880a3358ac7831694bd904cf69e9ff2933c3430cb7b59bd90e116a`); consumed Drive patch deleted after verification.

## Recommendation
- Exactly next, separately: `M6-CP3-CB149-P13-FACE-CONTACT-NODE-SWITCH` per RA-249 §3. Apply only the frozen switch diff, compile only. No successor work has begun.
- Stable 66/17/49, debt1, deferred81; CP2 accepted 491/491, selector497/CP3 unpromoted; `chainRimSchedules=false`; C5/O42/O43/O45/O46 open, narrow C3/O44/C1 closed. D11=A, D12=A, D10 deferred, D6 pending. PR #8 remains draft and unmerged.
