# M6-CP3-CB1-ENTRY-R4 — supplemental hard-rail incidence contact preflight (2026-10-11)

**Scope:** Code + Build, supplemental RA-40(C) case only. Frozen R3 94-RED and CP2 491/491 acceptance status unchanged. No runtime tests, binaries, `ctest`, selector discovery, or frozen Test + Benchmark run.

## Source problem and bounded correction

The source-exact snapshot from workflow `38152143066`, event `bb9e8a9a183b3c187f91dffaece242ba61719345`, outer ZIP SHA256 `99346769c36e4659d6c3138e8820ad2bc74361922d63376094fce8d6b3cc9bd3`, source manifest **6192/6192** verified. `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` supplied nonempty hard-feature edges to `SurfacePhaseFrontProduct::make` while leaving both terminal contacts and closed-chain witness empty, violating the factory preflight (`src/geometry/SurfaceCellTracing.cpp` around 8190) before the intended `EmptyCells` boundary (~8697). For open hard edges, provide a producer-source-owned terminal receipt with the selected edge's exact two `SourceVertexId`s and a valid typed `HardRailId`.

- Exact single test file `tests/SurfaceCellTransitionQuotientTests.cpp`. Initial patch `Directional_M6_CP3_R4_HardRail_Incidence_Contacts_Repair.patch`, SHA256 `b52025d291736583ba3ae33098815ae56adf493605c3bc0ef46fcb872db877aa`, applied at source `3a5b1d852fb2c91464969612a312679271043ad2` via workflow `38152596179` (result artifact `11707187398`, ZIP SHA256 `0f8b87965334be025eebfe51f21c53cb1ff4b6444d4c3e13231a8689081570ae`).
- First exact-source compile `38152728029` FAILED at `tests/SurfaceCellTransitionQuotientTests.cpp:1977`: `HardRailId::from_index()` is a typed `DomainResult`, not dereferenceable `optional`. No generated runtime execution. Corrected expression `railId.value()` in one-line patch `Directional_M6_CP3_R4_HardRail_Incidence_DomainResult_Compile_Fix.patch`, SHA256 `e95bb2e983e0f949a5607df89ada5301200a7cae8d233680cbdf3a075ffce71e`, applied semantic source `b2b398591e399f2a8aeeea811c0850c45b128283` via workflow `38152951894` (result `11707820632`, ZIP SHA256 `ee6ad48fbc8efc7c000c47ba59bd061e6e58306a81815612e691c2527ebb235a`). Both patch bytes preserved `/Directional/Evidence/`; both Drive staging files owner-deleted.

## Mandatory GMP/GMPXX compile receipt

Exact GMP/GMPXX eight-target compile **GREEN**: workflow `38153070583`, compile job `114510410732`, semantic source `b2b398591e399f2a8aeeea811c0850c45b128283`, eight requested targets, `0/0` preflight/build exits, 28/28 artifact manifest checksums, linked both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`, source tree clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11706799174` ZIP SHA256 `81a9a52a14db4ef03f60e56737be007baedeea6c19ad98e3383d54615f4617ef`, log artifact `11706888808` ZIP SHA256 `0243bffa99b76b8947c6568145b063673375e073db3683f7bc2e5837875d9f18`.

All package metadata objects were verified from the one immutable result ZIP; 28/28 `SHA256SUMS` entries valid and the eight outputs are present. The first compile attempt `38152728029` failed and must not be credited as GREEN; the corrected source commit alone is the compile authority.

## Review/acceptance limitations

This code repair is **not one of the seven frozen R3 DCEL negatives**, nor the 88 accepted CP2 losses; it is the supplemental `HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`, explicitly **outside the frozen 497 selectors**. Correct source construction and compilation are not proof that the intended one-/two-face positive cases reach `EmptyCells` or that the three-face/absent-edge cases reject `InvalidSourceAuthority`. Those assertions remain unexecuted pending a separately authorized artifact-only diagnostic turn. No production code, source/atlas relaxation, selector identity, or PR metadata changed.

Canonical turn `M6-CP3-CB1-ENTRY-R4` remains `IN_PROGRESS` (root `STATUS`), successor `UNKNOWN`. Frozen CP2 `491/491` remains accepted; R3 candidate `403/497` rejected (94 RED, 88 CP2 losses). Outstanding R4: all 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, authentic multi-carrier/odd-τ, six CP3 positives, independently reviewed feasibility of dual terminal simple A3 paths. No permission to execute generated programs or advance to frozen TB497.
