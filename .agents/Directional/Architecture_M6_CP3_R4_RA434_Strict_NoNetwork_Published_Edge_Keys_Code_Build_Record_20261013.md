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
