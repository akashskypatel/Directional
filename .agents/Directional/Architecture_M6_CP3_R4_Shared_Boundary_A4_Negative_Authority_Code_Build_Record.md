# M6-CP3 R4 — Phase10 shared-boundary negative retains complete A4 source authority

## Exact source and status

- Canonical turn: `M6-CP3-CB1-ENTRY-R4`, continuing. No successor authorized.
- Frozen source snapshot: workflow `38096516783`, event SHA `0764c60a08dd88e933da058035221358097f0e1e`, verified 6026/6026 source-file checksums, `runtimeExecution=false`.
- Test-only semantic commit: `f7be55e01c525ef4ae7c8db0039956246d8f04cc`, applied by dispatcher workflow `38096715429`, result artifact `11685874765` (outer ZIP SHA-256 `13155f1e530041a95888ebef24d11cb3600dbc48c59a2f6ef652fc83011e7fdb`). Source patch complete SHA-256 `5b8582f505266cdd8a772a621a08a99a18bbf773993434b9b35efbba472d39bc`.
- Source patch backed up in ChatGPT Library `/Directional/Evidence/Directional_R4_Phase10_Interval_Negatives_Full_Authority.patch` and consumed Google Drive stage owner-deleted.
- Exact GMP/GMPXX compile GREEN: workflow `38096829899`, job `114344387141`, semantic source `f7be55e01c525ef4ae7c8db0039956246d8f04cc`, eight required targets, preflight/build exit `0/0`, CMake GMP discovery and both `libgmpxx` / `libgmp` link verified, 28/28 recursive package checksums, clean source and `runtimeExecution=false`; result artifact `11686391124` ZIP SHA-256 `cbfbe488bda31b5542bb19ceefc80628181d65e1c0bf36ad8f91cec533c3efaa`, log artifact `11686760574` ZIP SHA-256 `7d0ef296ef8d9074c83604fa9ad845e3d38cfffac8f22151d18c385c9e4190d1`.

## Test-source correction and semantic guard

File: `tests/SurfaceCellsPhase10Tests.cpp`. Identity `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback` is unchanged.

The source-produced rectangular hard-rail fixture already provides `hardFeatureEdges()`, `sourceFaceBranchRotations()`, `hardRailFieldTransitions()`, `hardRailRouteCertificates()`, `hardRailTerminalContacts()` and `hardRailClosedChains()`. Before this correction, both mutated calls to `SurfacePhaseFrontProduct::make` carried only `conformityPlanReceipt()`, causing the checked source authority verifier to inspect an incomplete A2b/A3 proof before the intended missing/tampered shared-boundary interval. This can mask the targeted `InvalidSharedBoundaryInterval` oracle with an earlier, unrelated rejection.

Both negative reconstructions now pass the same complete authority from the genuinely produced product. An unchanged product is first independently reconstructed through the existing full-argument `rebuild_phase_front_with_edges` helper, failing if the checked A4 baseline is invalid. The two mutations remain limited to removing a shared-boundary interval and substituting a distinct interval span. Their expected `InvalidSharedBoundaryInterval` errors remain unchanged. No production geometry, immutable selector, or workflow permission was modified.

## Evidence boundary and continuing obligations

This is compile-only Code + Build. No Directional binary was executed, so the new first-rejection outcomes are expectations and **not verified runtime PASS**. The 39 carried endpoint cases, 34 Phase10 cases, seven DCEL negatives, 88 formerly accepted CP2 identities, source-valid multi-carrier/odd-tau witnesses and dual-path independent design review all remain open; the immutable 497-case Test + Benchmark remains unauthorized in this turn.

## Follow-up

Observe actual first rejection of this unchanged selector only in a separately authorized Test + Benchmark gate. Do not run tests, `--list`, binaries, or benchmarks during this Code + Build turn. Preserve current source and all immutable workflow evidence.
