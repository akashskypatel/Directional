# M6-CP3-CB1-ENTRY-R4 — Periodic crossing source-A3 negative preflight

Date: 2026-10-11 (UTC). Turn: `M6-CP3-CB1-ENTRY-R4` (IN_PROGRESS).

## Source and defect

A verified source snapshot from workflow `38161153168`, event/source SHA `9a8a3db6b2beb7b6b7919096df20162dca6b1c7e`, outer archive SHA-256 `a66f4f272ef1804aa3e988c9177a31ddc3fcaadb140e7a7233b81246e7e4128a`, source archive SHA-256 `c66ef077631ebe2a1387d88627727a203230ba7483df818e8e94e049922c2ca1`, verified 6221/6221 SHA256SUMS entries; `runtimeExecution=false`.

The existing `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.MalformedAuthoritativeCrossingProvenanceFailsClosed` regression was alone in using a periodic route builder that supplied no source-bound A3 atlas, even though other periodic-route test paths reconstructed original-source A2/A3. Missing A3 is not a valid substitute for the asserted typed `PeriodicHolonomyMismatch` caused by negative `sourceEdge` metadata. This fix removes the now-unused unbound builder and passes an A2/A3 atlas created from the original full balanced field independently of the forged tracing metadata.

## Implementation

Exact semantic source commit: `e0cc0415b447c045443e3d498c6d6f50769b29e8`. One file changed: `tests/SurfaceCellsPhase10Tests.cpp`; 5 insertions and 15 deletions, no frozen selector or test identity changed. The test still sets `transition->sourceEdge = -1`, still requires a `Rejected` product with first reason `PeriodicHolonomyMismatch` and exact source/target faces, and still checks that no partial seeds/traces/proposals were published.

Verified patch SHA-256 `bbfdf836981f67cb6149ba25ad78d646748335df0638ab22c3edc72e25b6e0e1`, body `4be5a1a165a5d874f0f8d41fa918769a590a1e5a3c737cce25a6a43d59c8d6e4`. The patch applied via standard Google Drive dispatcher workflow `38161729069` (job `114535933683`), validated exact source and one-file changed-path set, committed/pushed `e0cc0415b447c045443e3d498c6d6f50769b29e8`; result ZIP `11710831492` SHA-256 `efb9beeaa65927a751651a2009313e5fc9a43782cdcfa4720f52a5ecaebf1a58` and log ZIP `11711011071` SHA-256 `a92c819fde047aff62de9443e24e681f9b6e612dfa46a062af9c3a0148dc16ae`. Consumed Drive stage `1sw2BpJMCYoDWFvClwGkPHJDRUPjs-HFw` was permanently owner-deleted. Source patch is preserved in ChatGPT Library `/Directional/Evidence/`.

## Compile-only receipt

Exact semantic source commit `e0cc0415b447c045443e3d498c6d6f50769b29e8` compiled in GitHub workflow `38161835655` (compile job `114536250404`). Both preflight and build exit codes were 0; all eight requested targets (`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`) compiled. CMake discovered GMP with `DIRECTIONAL_ENABLE_GMP=ON`, and the generated link command shows `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`; source tree clean; artifact `exactArithmeticBackend=GMP` and `runtimeExecution=false`. Independent package checks confirmed `28/28` SHA256SUMS entries. Result artifact ID `11710631873`, provider ZIP SHA-256 `8e672d4720e4ff244dc80a540a0c1989a67b43155a01883fced3c8d9c1a9d9c7`; diagnostic log ID `11710816692`, ZIP SHA-256 `74210d3d205f49f22f38ded7598514edb772689c750bbef84165efaeaa31276e`.

## Evidence boundary and outstanding requirements

This is a checked-A3 test harness improvement only, not a recovery of any of the 94 historical RED or 88 accepted CP2 losses. No generated executable, filtered test, benchmark, discovery, or frozen 497-case acceptance was executed in this Code + Build turn. Preserve frozen selectors, all A4/A2b/A3 guards, the dual-path source-validity independent Review question, 39 endpoint, 34 Phase10, 7 DCEL, 88 CP2 losses, six CP3 positives and real multi-carrier/odd-τ obligations. No TB successor is released; R4 continues IN_PROGRESS with successor UNKNOWN.
