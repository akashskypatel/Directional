# R4 RA-43.4 — independent network-bound consumer foreign-edge-key regression

**Canonical turn:** `M6-CP3-CB1-ENTRY-R4` Code + Build, still incomplete. This is test-source/authority documentation only. No Directional runtime, test or benchmark may be executed in this turn; do not authorize TB497 or successor work.

## Exact source and evidence boundary

- Verified exact GitHub snapshot `a2e63a6676c90fdcdc56f1b8922d43e4cf4f670c`, workflow `38352281752`, archive artifact `11791247269` SHA-256 `73f85852b84e6b7365f5b1731c8822cc683b32003a93c58868556540da6b415b`. Source tarball SHA-256 `8d2508b6cfdf252a3722f1704cd577894d897137c0ed9c943d20f8ce2c0aa703`. **5,585/5,585** source-file SHA256SUMS verified; `runtimeExecution=false`.
- Previous RA-43.4 exact-source production guard and network-bound absent-key oracle were applied at `c11eb6f4aac75676f864c84aed501dcd38d2aeb6`; eight-target compile already GREEN in workflow `38350909779`. This work must not duplicate or weaken that guard.

## Distinct test-only change

Extend existing `SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` in `tests/SurfaceCellsPhase10Tests.cpp`, preserving its identity and the existing full-network positive / missing-keys negative. On the same real producer-backed fixture, replace one published source-edge key with a **different existing source hard-feature edge key** while retaining the rail's typed source-vertex list, sample geometry, cardinality, and actual field-aligned network. The separate checked network-factory foreign-key regression (`ProducedRailsReachTypedFieldAlignedConsumerOnDefaultPipelinePath`) already exists; it is not a substitute for the `rail_interval_refs` *consumer* first rejection.

Require `RailBuildStatus::TypedAuthorityMismatch`, a populated failing rail ID matching the damaged producer rail, and rejection despite explicitly named `LegacyStandaloneDiagnostic` mode because the real network is supplied. A non-vacuous foreign-key selection uses a distinct `fixture.hardFeatureEdges` entry; fail the oracle if absent. Do not invent an input mesh or bypass the producer to make the negative pass.

## Additional static observation (not silently repaired)

The default `RequireTypedSource` helper with **no** field-aligned network currently rejects a missing `sourceVertices` chain, but it can accept a present typed vertex chain with an *empty* `sourceEdges` list. `rail_interval_refs` condition `fieldAlignedNetwork != nullptr && sourceEdges.size() != intervalCount` intentionally tightened the network-bound path in the previous checkpoint, not every no-network helper diagnostic. Several existing standalone Phase14 fixtures (for example `ProducedRailEndpointsRequireExactSourceVertexIncidence`, `RailSideSelectionIsStableForReverseTraversalAndIncidentOrder`) use typed vertex chains with no edge-key list and expect `Valid`. Globally making edge keys mandatory without migrating and independently rechecking those first-rejection fixtures would invalidate accepted tests. Preserve this as a separately scoped RA-43.4 migration task; do not claim the network-only correction globally retires the diagnostic seam.

## Verification and limitations

Verify one exact-base patch forward/reverse and whitespace, apply via authorized Google Drive file-ID dispatcher, and run the mandatory pinned eight-target GMP/GMPXX *compile only*. Verify package source, 28/28 internal checksums, all 8 targets, `gmpxx`+`gmp` generated link, clean source-status records, and `runtimeExecution=false`. Compilation does not establish runtime PASS for this or prior oracles.

RA-50 has discharged RA-43.2 and prohibits invented producer-filled-side receipts. Remaining R4 RA-43.1/43.4 disposition, RA-46.5 first rejections, RA-47.12 executed liveness, 39 endpoint/34 Phase10/seven DCEL/88 CP2 historical/six CP3 positive gates and odd-τ multi-carrier proof remain unclosed. No TB497.

## Applied source and immutable compile verified (2026-10-13 UTC)

- Exact source patch SHA-256 `97dac10a5d1c18f62c9067bec315d97528f0de2147d7bcf8538905518780bec0`, diff-body SHA-256 `53bd2ee98ba1f03be60aecd1fa400eac19360b072279a6f1c106575bf6694230`, based on `a2e63a6676c90fdcdc56f1b8922d43e4cf4f670c`, was forward/reverse/whitespace verified. Drive dispatcher apply workflow [38352833746](https://github.com/akashskypatel/Directional/actions/runs/38352833746), receipt artifact `11790654673`, archive SHA-256 `1a7f28f98a4b845c4737960afa3d0f1044984ac826e3a80cb291dc28239ce859`, succeeded at semantic source **`91e5c2a498ffc949ec229fd084cf49949ffe3a76`**. GitHub independently confirmed exactly the four intended paths. Owner-side staged patch was permanently deleted.
- Mandatory eight-target GMP/GMPXX compile **GREEN**, workflow [38352976015](https://github.com/akashskypatel/Directional/actions/runs/38352976015), exact source `91e5c2a498ffc949ec229fd084cf49949ffe3a76`, result artifact `11791682503`, outer SHA-256 `c449ccb818e42882106186afdae2066b3c1e7e591e454b4e62906617eaa7d764`, log artifact `11791687445` SHA-256 `3eec4ed1d56b4b66c1cc02a7b7a056b6e74370e853a47bfaac8a8674e91012a3`. Independently verified **28/28** internal SHA256SUMS; **8/8** requested targets; preflight/build exits **0/0**; real generated `gmpxx` and `gmp` link; five clean source-status files, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Test + Benchmark did not run.
- This closes only this **compile** checkpoint. The wrong-key consumer negative and factory positive were not executed. No runtime PASS, TB497, global RA-43.4 retirement, or successor credit. Preserve separate no-network typed-edge migration and all R4 historical/multi-carrier gates.
