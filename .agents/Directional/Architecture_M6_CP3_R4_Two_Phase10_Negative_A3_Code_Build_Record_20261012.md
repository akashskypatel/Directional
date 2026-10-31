# M6-CP3-CB1-ENTRY-R4 — two Phase10 independently source-bound A3 negative fixtures (2026-10-12)

**Authority:** same `M6-CP3-CB1-ENTRY-R4` Code + Build turn, IN_PROGRESS; successor UNKNOWN. Immutable Test + Benchmark gate TB497 is not authorized. No tests, benchmarks, discovery, or other Directional generated executables were run. No frozen selector, test name, expected failure, production code, fallback, ABI, workflow YAML/permission or PR metadata changed.

## Exact source and patch

Source snapshot workflow `38203335598`, exact source/event `ba6c3ef6becb31531d1a113c04ae89bfe00ea813`, artifact `11726104714`, ZIP SHA-256 `c0d0d6935743cd13e2f562bac600518e0c0d9f8ac6270230404a1fa8f1a5d849`, source tar SHA-256 `19064a9a478aa80f0c8e34ead1dafdc08c83d7cf69959b77e8c5a64a3053602e`; 6347/6347 verified, snapshot `runtimeExecution=false`.

Only `tests/SurfaceCellsPhase10Tests.cpp` changed (+21/-0); original selectors and rejection oracles retained:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed` now makes independent source-owned A2/A3 from the original synthetic bisector cross field before requesting the unchanged `AmbiguousPeriodicRingCorrespondence` rejection. No traced-field matching data was changed.
2. `SurfaceCellsPhase10.PolygonalCurvedDiskInvalidCyclicFieldTurnFailsClosed` uses the existing `bind_curved_disk_atlas` helper for its original two-triangle source, so an absent A3 cannot masquerade as its intended `InvalidBoundedDiskBoundaryTurn` rejection.

The patch `Directional_M6_CP3_R4_Phase10_Two_Negative_A3_WIP.patch` has full SHA-256 `5c7d5fd7c8952899727a182707b66599f627e75a3d592d806ddb3faaacd6d0f3`, diff-body SHA-256 `9b2cc7593cdf6007473dba5e6e586dc1a55b5a7d72cccd42ac19f08ca71f47dd`, and exact base `ba6c3ef6becb31531d1a113c04ae89bfe00ea813`. Reverse/forward `git apply --check` and `git diff --check` passed; exact preserved chat backup exists. Drive apply workflow `38203661294`, job `114662369887`, result `11725129965`, ZIP SHA-256 `0740ad540473bf9be37e680211803adc09f1991282e76b7ebc5f2163f1c63d4e`; semantic commit `2be8da1198f9861efb7231c9468760df787b22f5`. Original staging Drive file `1TwxmQibUz1P-o15ohXt3JDZBadr43ZP0` was owner-permanently deleted after verified commit.

## Exact-source GMP/GMPXX compile-only verification

`agent-operation-dispatcher.yml` request event `db13477f5a14ebad0ca1bd2df071f7db7b72c1c8`, compile workflow `38203770454`, job `114662687581`, exact compiled source `2be8da1198f9861efb7231c9468760df787b22f5`. All eight approved targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`. Preflight/build exits `0/0`; source status clean; CMake `DIRECTIONAL_ENABLE_GMP=ON`, authoritative linker contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`; `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Result artifact `11726506719`, ZIP SHA-256 `a5399cd78e5a38e8f2969c00dc453fa66079f0cf2f31bc8b603658cc5078a972`, full package manifest **28/28**. Diagnostic artifact `11726501750`, ZIP SHA-256 `96e83b13740c2ce04655d80032213ed988cb317d3b3a6ad789578312bede3aa1`.

No runtime first-rejection or PASS/FAIL is known for these two tests: compile does not demonstrate their expected errors. Accepted CP2 **491/491**, rejected R3 **403/497** (94 RED, 88 accepted-prefix losses), ledger **66/17/49**, debt **1** remain frozen. Open R4: independent overfull-A3 source feasibility Review, producer-owned RA-43.4 legacy untyped rail retirement, 39 carried endpoints, 34 Phase10 positives, seven DCEL negatives, 88 CP2 restorations, six CP3 positive gates, genuine odd-τ multi-carrier and other original R4 producer duties. Do not start successor or TB497.
