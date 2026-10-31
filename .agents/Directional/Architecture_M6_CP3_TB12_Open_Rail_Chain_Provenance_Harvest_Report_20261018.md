# TB12 — Immutable open-rail chain provenance harvest (2026-10-18)

Canonical turn: `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` (artifact-only Test + Benchmark).
Semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9`; immutable CB12 package `12125223513`, ZIP SHA-256 `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6`.
Harness `.agents/Directional/tools/m6_cp3_r10_open_rail_chain_provenance_harness.sh`, SHA-256 `37fe7152bde8e25c366115189487a629a3439a432fd98d7d33ac0b0ac643fde5`, executor commit `2bb45fa6084bcfce4b1287f65e4f88ead2678557`; dispatcher `bae8440c711c2fca72bfeb14e6ecf1cecce0c234`.
[Run 39103358061](https://github.com/akashskypatel/Directional/actions/runs/39103358061), result artifact `12127706461`, ZIP SHA-256 `1b6c3babd942cfc7fc7bbeff94774bf719297fdb9bc7ca3c0088e40110f2dfee`.
Artifact `SHA256SUMS` verified; package 28/28, frozen selector checks, source, view, and package postflight passed; GMP runtime resolved. Six independent exact-filter processes: **6 selected, 0 missing, 2 PASS, 4 RED**.

| # | Role | Identity (test case) | Verdict | First failure / prediction |
|---|---|---|---|---|
| 1 | gate | `SurfaceCellClosedProductContracts.OpenHardRailChainProvenanceIsSourceValidated` | PASS | PASS as RA-86.4 predicted |
| 2 | gate | `SurfaceCellAuthorityContractCutover.OpenRailRouteAnchorTruthTable` | PASS | PASS as predicted |
| 3 | diagnostic | `SurfaceCellAuthorityContractCutover.CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor` | RED | `firstPredicate=predicate=open-rail-route-anchor` (full predicate below), predicted |
| 4 | diagnostic | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` | RED | Same first predicate as #3, predicted |
| 5 | diagnostic | `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` | RED | `producer failed: InvalidHardRailRouteCertificate firstPredicate=predicate=endpoint-1`, predicted consumer rejection |
| 6 | diagnostic | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | RED | Same initial `endpoint-1` rejection as #5, predicted |

For #3/#4, removing the ledger's `firstPredicate=` wrapper leaves this **byte-identical** TB11 predicate:
`predicate=open-rail-route-anchor;locus=9;rail=2;front=29,147;faceEnds=0,3|0,3;vertex=-1;step=-1;currentFace=0;expectedFace=3;routeLength=1;edge[0]=1,4:faces=0,3:chi=0`.
For #5/#6, `first_failure` contains `firstPredicate=`; neither is a `PublishedProductRejected` without a predicate. The CB12 publication validator is **not reached** by these real pipeline diagnostics, so they cannot establish production coverage of that validator; the valid-chain gate proves a focused contract only.
All four RED cases remain within existing `RP-01`. No independently demonstrated new stable regression, acceptance promotion, ledger change, or RP-02 reachability: **66/17/49**, debt **1**, M6 CP2 **491/491**, R3 **403/497** rejected, selector **497** frozen; Gate C suspended.
No source/test/fixture changes; no compile, relink, benchmark, selector run, or package repair. Exact product outcomes and predictions require independent Review.
**Authorized successor:** `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV` (RA-86.4). Do not start CB13 from this harvest alone.
