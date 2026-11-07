# TB13 — Immutable open-rail chain-interval harvest (2026-10-18)

**Turn:** `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE`, artifact-only Test + Benchmark. CB13 semantic source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`; compile artifact `12130290543`, ZIP SHA-256 `7aea91a1b689f26ae9a4786c48152fe0a3d9c8e17382b6e155db0465e3445fd3`; 28/28 package checksums, GMP/GMPXX, build/preflight 0/0, compiled boundary `runtimeExecution=false`.

**Harness:** `.agents/Directional/tools/m6_cp3_r10_open_rail_chain_interval_harness.sh` SHA-256 `2cb9ef9e8799ed9fd704f93109c283f082884a4ee4e2489a0434e9021e487ae7`, executor commit `157145f3e2f1cf5a500dfb8d8b2bc2ce3fdd9272`. Changes relative to TB12 harness limited to immutable source/package/digest, truth-table identity, gate ordering, and TB13 output labels.

**Execution:** [GitHub Actions run 39112131501](https://github.com/akashskypatel/Directional/actions/runs/39112131501); result artifact `12130683535`, ZIP SHA-256 `43505af2912b840262307db96865c5e7f9e2af8ca3b9cbe5426f0b18e87f4885`. Result manifest verified. All six exact-filter processes ran: **1 PASS / 5 RED / 0 missing**. Postflight package, source, view, and frozen selector inventories unchanged. `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`. The Actions workflow succeeding does not mean the tests passed.

| # | Identity | Result / evidence |
|---:|---|---|
| 1 | `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` | **RED.** At `SurfaceCellsPhase10Tests.cpp:7182`, `check({{4,7},{1,4}}, nullopt, nullopt, chain)` returned `true`, expected `false`. RA-87.4 searches direction ±1, making this a valid reverse traversal of chain `[1,4,7]`, but separately lists that route as a false row. Contract/test inconsistency requires independent Review. |
| 2 | `SurfaceCellClosedProductContracts.OpenHardRailChainProvenanceIsSourceValidated` | **PASS** focused provenance contract. |
| 3 | `SurfaceCellAuthorityContractCutover.CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor` | **RED diagnostic**; first rejection advanced from TB12 `open-rail-route-anchor` front 29/147 to `endpoint-1` front 61/179 at rail-interior vertex 4 (B2). Still fails before the intentional mutation. |
| 4 | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` | **RED diagnostic**; same new B2 first failure as #3; fixture does not reach `Produced`. |
| 5 | `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` | **RED diagnostic**, B3 `endpoint-1` front 17/203. Complete raw 9,180-character producer-failure line byte-identical to TB12 #5. |
| 6 | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | **RED diagnostic**, B3 `endpoint-1` front 17/203. Complete raw 9,180-character producer-failure line byte-identical to TB12 #6. |

**Disposition:** The harvest is executed and immutable, but its required truth-table gate is RED. This is a candidate/specification-versus-oracle discrepancy, **not a proven new stable regression or a reason to weaken the test**. The two midline cases progressed to the already-known B2; the full-pipeline controls remain at B3. No direct production acceptance, RP-01 closure, or gate promotion. Frozen **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491**, R3 **403/497**, selector 497 unchanged, RP-02 UNREACHED, Gate C suspended.

**Stop gate:** Independent Review must reconcile RA-87.4's bidirectional rule with its contrary false-row expectation before conditional TB13C, U4/U5/U6, or any corrective code/test change. Exact Review successor ID UNKNOWN; do not invent one.
