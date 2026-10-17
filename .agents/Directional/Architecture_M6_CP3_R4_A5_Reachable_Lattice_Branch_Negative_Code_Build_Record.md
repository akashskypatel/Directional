# M6-CP3-CB1-ENTRY-R4 — A5-reachable lattice-only hard-rail negative (Code + Build)

## Authority and disposition

- Turn: `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS**, successor **UNKNOWN**. PR #8 draft/unmerged. No Test + Benchmark execution or successor authorization.
- Verified source-snapshot SHA `3fb376186dbf2199a4cc591d12e0b5a13b005048`; workflow `38090740179`, artifact `11683443339`, outer ZIP SHA-256 `aa2ce47797c703625dae989c1cceb7cf74b45456c0871cfa5260b9634755e2e3`, 6008/6008 source `SHA256SUMS` valid.
- Single-test-file exact patch from that snapshot: `7ac899b2d91e9d8c0925bbb4cc1ccd367872dcc4`, applied by workflow `38091134482` (job `114327681552`), result artifact `11684136256` ZIP SHA-256 `87c91479a4cd5162ebd42335943fdb80b9071204f0e366b0a3f0f6848aa8cd91`, log artifact `11684720132` ZIP SHA-256 `eef73aadd687e60b506960a7ceffa6ef853dcd1586c43d8e95905e6f69a54a59`. Drive patch owner-deleted after push. Patch backup in `/Directional/Evidence/Directional_M6_CP3_R4_A5_Reachable_HardRail_Lattice_Forgery.patch` (SHA-256 `0b2b39cbbe9cda8509fe26491e2a3f015dfcd0217c8fd66abeaf8aab1eec3b00`).
- Exact GMP/GMPXX compile GREEN: run `38091230910` (job `114327961939`), semantic source `7ac899b2d91e9d8c0925bbb4cc1ccd367872dcc4`, eight requested targets built, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx` and `libgmp` linked, clean source, 28/28 checksums, `runtimeExecution=false`; result artifact `11684470998` (ZIP SHA-256 `98434eea000957664acee32c57cba233642142da0ef40afcc4fb9d663f9e9fc2`) and log artifact `11684296178` (ZIP SHA-256 `5b6abc8f86fd852a002ee48709089a4d0628fe710f487c07ac17395fe9554d89`).

## Bounded implementation

Added compile-only regression `M6CP3.A5RejectsA4AcceptedHardRailEndpointBranchForgery` to `tests/SurfaceCellTransitionQuotientTests.cpp`. It uses the producer-owned `hard_rail_fixture()`, requires a valid original A5 product, clones the *complete* checked-factory A4 input (including conformity receipt and terminal/closed rail authority), selects a genuine HardRail front edge with a filled cell and corner, changes only one cell-local lattice `branchRotation` by +1 in Z4, and requires the complete checked A4 reconstruction to succeed. It then calls the real A5 producer with the forged cell branch and expects `HardRailTransportMismatch`. It does not change source A3, hard carrier χ, A2b terminal side paths, source face gauges, frozen selectors, production code, or test registration.

This is an **unexecuted regression hypothesis**. Compilation does not prove which producer branch rejects at runtime. If later artifact-only TB shows a different A5 rejection, trace the *first observed* typed failure and correct the test/implementation in a separately authorized Code + Build turn; never label the selector passed or weaken a required source gate to force green.

## Still open; no successor

R4 still requires 39 endpoint effects, 34 Phase10 positives, seven DCEL negatives, recovery of 88 CP2 accepted regressions, authentic multi-carrier/odd-τ witnesses, and independent review of the dual-source-admissible-path expectation. Frozen 497-case TB must not run during Code + Build. Last accepted historic CP2 491/491 and R3 403/497 remain unchanged by this compile.
