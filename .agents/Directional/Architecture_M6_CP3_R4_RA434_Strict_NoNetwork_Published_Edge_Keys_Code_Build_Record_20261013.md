# M6 CP3 R4 — RA-43.4 strict no-network source edge-key obligation (2026-10-13 UTC)

Canonical turn **M6-CP3-CB1-ENTRY-R4**, still IN_PROGRESS. This is Code + Build only, not Test + Benchmark; **no generated Directional executable, test, benchmark, discovery or TB497 may run**. The independent RA-50 review discharged RA-43.2 and prohibited fabricating a source-owned filled-cell/side receipt; this work does not reopen that issue.

## Exact inspection authority and existing accepted work

- Snapshot branch `agent/surface_cell_quad/p5-recover-bridge-healing`, event/source SHA `d14a3fc025e686a6abee13d8a933932d3014bf29`, GitHub Actions `38354520497`, artifact `11791794737`, archive SHA-256 `192a9c7f1aa0b3ab0ea81c047139f084c5c83bee50ae1371479c87d840b9a02f`; verified inner tar SHA-256 `c9afb5bd8293e9af320fb19e13087e07e28f13953457eda0f8bc4f555f5c96f5`, source-file manifest **5,594/5,594**, `runtimeExecution=false`.
- The prior *network-bound* missing-edge-key and foreign-key corrections already compile GREEN at `c11eb6f4...` and `91e5c2a...` and are preserved. Their runtime expectations have NOT been executed or credited.

## Previously open no-network ingress seam and prescribed bounded change

- `src/geometry/SurfaceCellTracing.cpp::rail_interval_refs`: `RequireTypedSource` previously required a producer vertex chain but, in the absence of `fieldAlignedNetwork`, accepted an **empty** `rail.sourceEdges` sidecar and rebuilt edge keys from the sample's face geometry and typed vertex pair. The network-bound cardinality check alone did not close this no-network strict consumer boundary.
- Require exact `sourceEdges.size() == intervalCount` whenever the mode is strict **or** a network is attached. Preserve `LegacyStandaloneDiagnostic` only when **no** network is provided. Keep all existing duplicate-ID, empty/odd-sample, malformed-sample and interval first-rejection guards and typed edge-key comparisons.
- `tests/SurfaceCellTracingPhase14Tests.cpp`: publish explicit test-owned typed edge lists for synthetic positive rails and for fixture variants that exercise other typed rejection predicates. Preserve the intentionally malformed sample-pair fixture by supplying nonauthoritative cardinality-complete placeholder edge keys only *inside that negative fixture*, so `InvalidSamplePair` remains the first guard. An independently checkable no-network positive plus missing-key negative now pins `TypedAuthorityMismatch` and the failing typed rail ID; the named no-network diagnostic remains Valid for the same missing-key rail.
- `tests/SurfaceCellREPackageTests.cpp`: publish the one synthetic hard-feature rail's typed edge key rather than implicitly relying on geometry inference.
- The fixture migration is authored test source, **not** a statement that the synthetic rails were emitted by the production rail producer. No frozen test name/selector, native ABI or workflow permissions change.

## Verification and limits

Verify exact-base `git apply --check`, reverse application, changed paths and `git diff --check`, then use the established Google Drive staging File ID and durable dispatcher (`drive_apply`). The mandatory follow-on compile must pin the applied semantic commit and call the durable GMP/GMPXX eight-target reusable; verify actual generated link, exit codes, 28/28 package hashes, clean source, and `runtimeExecution=false`. Record receipts once available; do not claim compile-green before inspection. No local build/test. Static inspection and compilation cannot prove the frozen runtime oracles.

Still open: global RA-43.1/43.4 disposition beyond this seam; remaining RA-46.5 first-rejection cases; RA-47.12 executed liveness; 39 carried endpoints, 34 Phase10, seven DCEL, 88 CP2 accepted-loss, six CP3 positive gates; authentic odd-τ multi-carrier; full Test + Benchmark acceptance. No TB497 or successor until independent authorized boundary.

## Verified compile receipt and continuation boundary (2026-10-13 UTC)

- Applied semantic commit `52389f6749e90e9fdc9c9f2b711ea0c339e323ca` by authenticated Drive dispatcher workflow `38355365948` (GREEN); immutable apply receipt `11792422998`, ZIP SHA-256 `cbdc41bfaaae81e25668110e51044d083cbbe3bd7e9e3cc2fddaf1cd723ab971`, complete patch digest `11dd1dda1ca2b3e610c6ad46378c7ed425cc90e0e4e5797090b1d4bf3106d233`. All six intended changed paths verified against GitHub. Owner-side Drive staged file `1YqMF_iUUqR4g7M15nSUUQSUyFssB9HFe` permanently deleted. Temporary snapshot trigger consumed and deleted (commit `58d2a56e354883ac05f834ed0092df25fd55a9e2`).
- Mandatory GMP/GMPXX compile dispatcher event `a8938b2b2f5e4ab412f185c38e2efb40f565c8a2` reached **GREEN** in workflow `38355543522`. Compiled source pin `52389f6749e90e9fdc9c9f2b711ea0c339e323ca`; result artifact ID `11792443636`, exact outer ZIP SHA-256 `be9678338ab324cc490d8ed5cfd46757d2427568e97e0caa6ecf5d6e83fc0ec1`, diagnostic log artifact `11792578162` ZIP SHA-256 `cc656871e22adf02b1b2c78a5d92b8a10477b90e2f87f8894b25ec1646fa9300`.
- Independently checked package: 28/28 SHA256SUMS (package `./` paths normalized only for lookup), 8/8 requested targets, preflight/build exit codes `0/0`, generated `gmpxx` **and** `gmp` link, `exactArithmeticBackend=GMP`, all five source-status records empty/clean, `runtimeExecution=false`. No Directional test or benchmark executed; all new and historical runtime assertions unverified.
- Retain `M6-CP3-CB1-ENTRY-R4` IN_PROGRESS. No successor or TB497. The remaining RA-43.1/.4 global, RA-46.5, RA-47.12 executed, 39/34/7/88/six, and odd-τ multi-carrier gates remain open.
