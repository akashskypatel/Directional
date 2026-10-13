# M6-CP3-CB1-ENTRY-R4 — RA-43.1 complete admissible transit source oracle (2026-10-13)

Same unfinished Code + Build turn. This record is a continuation, not a Test + Benchmark result or a successor.

## Completed source transport recovery
- Earlier `container_session_unavailable` Google Drive staging blockage resolved by Library-to-Drive transport.
- Verified exact snapshot source `e9c2f250c81193ac7507e130880918829742c155`, run `38393991475`, archive `11810363710`, all 5675/5675 source file hashes.
- Added 39 lines only to `tests/SurfaceCellsPhase10Tests.cpp`, existing `ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit` test, to independently enumerate all source-eligible non-hard interior face-pair transports and compare with A1 producer transport inventory, in addition to its hard-carrier exclusion oracle. Exact patch SHA256 `2276f412c594a3264cd9bd26f0c304dd3792828c0be0764c33fefbaecba41735`, body SHA256 `43cf5e229cdecb04b5eb7c32b8fd055e21f0305343e52f4d44d346d307e771c3`.
- Applied through durable Drive dispatcher run `38404239853`, exact semantic commit `b94f530301135fef5ccedd67b2e26960d67d2410`; result artifact `11817311248` outer SHA256 `deccde546efb6c8190ac4f28dcd16b73405fa261005d2c90a66d583b2bf049f5`. Verified 39 additions, zero deletions. Staged Drive patch owner-deleted.

## Compile failure and surgical correction
- Exact source compile run `38404696195` failed at `SurfaceCellsPhase10Tests.cpp:6708-6711`: four `*first`/`*second` dereferences of `DomainResult<SourceFaceId>` (no operator*). Preflight exit 0; build exit 1. Log artifact `11818420944` outer SHA256 `43b7e6949d8b4f8d1d0c59121c9d1cec4a573e7e957e6c20d676d4385ef529eb`.
- Four test-only replacements use `.value()` following existing `ASSERT_TRUE(has_value())` checks. Exact repair patch SHA256 `038338ea164c098a3d15d1983ee654c531fbaf8b4b5a1003bcf11fae724a938e`, body SHA256 `d07425f2423eea838eabf6948dc17e5a5b5971c2ff87633a7ff7ef40ddd8b003`; local patch checks passed.
- Repair applied via run `38405284517`, semantic commit `32eff2943d4c3c8d2183f5a51439d33dc3c84ae1`, independently verified result artifact `11818681403` ZIP SHA256 `a7adf2e4471065bc6b67734a28daa6bb5a6186a96abb0f541c9d598a645180c5`; staged Drive patch owner-deleted.

## Verified exact-source compile — 2026-10-13 13:34Z
- **COMPILE GREEN**: dispatcher request commit `969c70deb87d5d2eace6ca53c8358488222615d3`; exact source `32eff2943d4c3c8d2183f5a51439d33dc3c84ae1`; workflow `38405627436` with compile job SUCCESS. Immutable result artifact `11818707033`, outer ZIP SHA256 `63e3b884e856ba492b820852cd5fa94583ac08ceeacaa93e1944a4e607e2ca12`. Package `SHA256SUMS` verified **28/28**, all eight named compiled targets present, preflight/build exits `0/0`, generated authority-kernel linker explicitly references `libgmpxx.so` and `libgmp.so`, all five source-status files empty/clean, command-boundary `runtimeExecution=false` and `exactArithmeticBackend=GMP`. Validation/dispatcher/mailbox jobs also succeeded. No generated Directional tests, benchmarks, or TB497 executed and no runtime success credited.
- RA-43.1/.4, RA-46.5, RA-47.12 executed liveness, historical 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 loss / six CP3 recovery and authentic odd-tau multi-carrier remain open. RA-50 discharges RA-43.2. Frozen selector 497 unchanged. Accepted CP2 remains 491/491; rejected R3 403/497, 94 RED; ledger 66/17/49 debt 1. R4 remains unfinished; do not enter successor or TB497.
