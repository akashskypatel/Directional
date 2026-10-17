# M6-CP3-TB1-R4-WITNESS-EXEC — supplemental immutable-artifact Test + Benchmark

**Result: 1/1 executed RED; 6/7 planned identities NOT EXECUTED under the mandatory first-RED stop.** This is a supplemental measurement outside the frozen 497. Mandatory independent successor: `M6-CP3-TB1-R4-WITNESS-REV`. The 497 gate has not run, and no stable acceptance accounting changed.

## Immutable source, package, and execution evidence

- Compiled semantic SHA: `953f812ff1f431e3ad3af3b68a92284a7831c94a`; immutable GMP eight-target compile [run 38664036225](https://github.com/akashskypatel/Directional/actions/runs/38664036225), package artifact `11939982141`, ZIP SHA-256 `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a`.
- Verified source snapshot [run 38667447821](https://github.com/akashskypatel/Directional/actions/runs/38667447821), source SHA `ecdbcb4c725e9149736c089dd73fdc63ba5c68aa`, 5,607 file hashes verified. The snapshot is inspection authority; the packaged semantic commit above is runtime authority.
- Artifact-only execution [run 38668126299](https://github.com/akashskypatel/Directional/actions/runs/38668126299), result `11942382424` SHA-256 `738959c08bb543cbdf38848b45199e351644685b350dc9e6f7b5a5f44d765861`; diagnostic log `11942512458` SHA-256 `ef2e2c11bcc0e88e6979a8847cda789cbd79a9a4d8600b1d6d1cb582a322ec52`. Mailbox `m6-cp3-r4-witness-supplemental` on `workflow-mailbox` reports `source_sha=953f812...` and exact dispatch event `f2bd4e7f2467f7d6068f687509b492531f2db4cc`.
- Executor commit `22abb93bce79ef843f4c047bb4f2a173eaff611a`, harness `.agents/Directional/tools/m6_cp3_r4_supplemental_witness_harness.sh`, SHA-256 `f61374f14dbe384687735369739df4a84e1c8f679675ee249cd71ce1220d301c`.
- Root package `SHA256SUMS`: 28/28 both before and after. Packaged source archive hash, exact source SHA and GMP package boundary verified. Package/source/execution-view byte hashes identical across test execution; frozen focused30/focused12/selector449/routing449 SHA-256 matched the published four selectors. No local or remote recompilation, relink, source/test/fixture change, selector edit, or benchmark execution.

## Runtime evidence — first and only executed test

`SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer`: **RED** (exit 1; selected exactly 1, passed 0; 8 ms per gtest).

Exact first assertion: `tests/SurfaceCellsPhase10Tests.cpp:6665` expected `SurfaceCellProducerDisposition::Produced` (enum `1`) but `fixture.network.phaseFront.disposition()` was enum `2`; first predicate detail:

```text
predicate=endpoint-1;locus=3;rail=2;front=13,131;faceEnds=0,2|0,3;vertex=-1;step=0;currentFace=0;expectedFace=2;routeLength=1;edge[0]=1,4:faces=0,3:chi=0;a2bProbeFrom=0:0x0p+0,0x1.8p-1,0x1p-2;a2bProbeTo=3:0x1.8p-1,0x0p+0,0x1p-2;a2bProbeFailure=no-exact-terminal-corner;a2bProbeCarrierPresent=1;a2bProbeA3Present=1;a2bProbeContactPresent=1;a2bProbeClosedChainPresent=0;corner[1]=0,0;railEnd[1]=1;corner[7]=0,0;railEnd[7]=0
```

The fixture rejects before the proposed network-bound A4 consumer receipt. Therefore this RED **does not disprove the consumer guard**, and it does not discharge `RP-02 TEST_AUTHORITY_COVERAGE_GAP`. The supported immediate root-cause location is the earlier A2b terminal-corner/closed-chain source route or the fixture's preconditions; whether production logic or the witness fixture is wrong remains **unresolved**. Do not weaken the assertion or manufacture a pass. Review must localize the first producer failure at this exact route and authorize any subsequent Code + Build change.

## Remaining witnesses

Six identities were not executed because the authoritative instruction says stop at the first RED: `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement`; `SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate`; `SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress`; `SurfaceCellTracingPhase14.ProducedRailEndpointsRequireExactSourceVertexIncidence`; `SurfaceCellTracingPhase14.RailValidationRejectsDisconnectedGeometryParametersAndSharedEdges`; `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm`.

Independently, the current compiled package does not contain `directional_surface_cell_historical_tests`, which owns both Phase14 tests (see `cmake/DirectionalTests.cmake`, conditional `DIRECTIONAL_BUILD_HISTORICAL_TESTS`). It is a **future coverage prerequisite** for executing those two; do not compile them inside this artifact-only turn. This absence did not cause the present RED.

## Accounting and disposition

Candidate `R4-TB-A-RP02-01` — **new first-executed supplemental witness failure, provisional, not stable regression accounting**. No comparable accepted runtime baseline exists for this identity and no independent root-cause adjudication has occurred. Preserve ledger **66/17/49**, debt **1**, CP2 **491/491**, prior R3 **403/497** with 94 RED and 88 carried losses, frozen selector **497**, PR #8 draft/open. Mandatory next turn is independent **Review** `M6-CP3-TB1-R4-WITNESS-REV`; only after its disposition can any source repair or a later 497 execution be authorized.
