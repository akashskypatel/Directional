# M6-CP3 R4 — Curved-disk full-authority A4 bounded-disk negatives

## Source and evidence

- Canonical turn `M6-CP3-CB1-ENTRY-R4`: `IN_PROGRESS`; successor `UNKNOWN`.
- Verified snapshot workflow `38099119681`, event SHA `030369acded05c3e5f79a76bc55c63ee78a653b9`, source archive `SHA256SUMS` 6035/6035, `runtimeExecution=false`.
- Test-only semantic commit `10fe9476be39f71171d6df33bc282089c0461944`; source Drive-apply workflow `38099335208` / job `114351865234`, result `11686679791`, ZIP SHA-256 `83c5f792aabe3a3c6473787dae9e2ae7a6e294b0927ddd88e29685340a5c1830`, diagnostic log `11686754820`, ZIP SHA-256 `7a2530887527f0fb49e98d80f42002dd4660db99a0cca71481dc569b34e4acde`.
- Original source patch SHA-256 `02bc925e77219d644fa6cf2ef15c3f489032ec349795c127c29196b62a886f78`, backup `/Directional/Evidence/Directional_M6_CP3_R4_CurvedDisk_A4_Complete_Source_Authority.patch`. Owner-side staged Google Drive patch permanently deleted.
- Exact mandatory GMP/GMPXX compile GREEN: workflow `38099415226` / job `114352107025`, exact semantic source `10fe9476be39f71171d6df33bc282089c0461944`, all eight required targets linked, preflight/build exit `0/0`, CMake `DIRECTIONAL_ENABLE_GMP=ON`, authoritative link command includes both `libgmpxx` and `libgmp`, 28/28 package self-manifest checksums verified, final source clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Result artifact `11686914874` ZIP SHA-256 `decfd995e52efa2f6a3f242bbbdbe7d2279d38e6bf18834a3a4e190fd7c01643`; diagnostic log artifact `11687480020` ZIP SHA-256 `ca6806b77e0d33eb55cf91cc12c2880695e0d8cc8778f3856c5dfd16fc096340`.

## Corrected test path

File: `tests/SurfaceCellsPhase10Tests.cpp`. The immutable negative cases remain `SurfacePhaseFrontProductFactoryAuthority.ForeignBoundedDiskRegionRejectsAtCheckedFactory` and `SurfacePhaseFrontProductFactoryAuthority.DuplicateBoundedDiskRegionRejectsAtCheckedFactory`. The produced `CurvedDiskFixture` contains exterior hard-feature edges, a source-bound A3 `FieldTransportAtlas`, and producer-published A2b/A4 certificates. Previously their checked factory invocations passed only the initial positional arguments, silently defaulting the rest of the immutable authority to null/empty.

The new shared `rebuild_curved_disk_phase_front` helper supplies every produced authority argument to `SurfacePhaseFrontProduct::make`, including conformity receipt, hard features, face rotations, hard-rail transitions, route certificates, A2b terminal contacts, and closed chains. Each negative verifies an independent successful unchanged product reconstruction before forging only the out-of-range bounded-disk source region or duplicate bounded-disk phase. No production geometry, source chart, immutable selector names, expected diagnostic codes, or CI workflow permissions changed.

## Evidence boundary and remaining work

**Code + Build only.** The expected `InvalidBoundedDiskRegion` and `DuplicateBoundedDiskRegion` are **not runtime-verified**. Compilation cannot prove these oracles. No generated tests, benchmarks, discovery, or frozen 497 selectors were run. R4 still owes 39 endpoint effects, 34 Phase10 positives, seven DCEL negatives, 88 CP2 restorations, authentic multi-carrier/odd-τ source witnesses and independent dual-admissible-path design adjudication. No TB successor is authorized.
