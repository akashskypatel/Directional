# M6-CP3-CB1-ENTRY-R4 — closed-rail source-component first-consumer guard

This is an unfinished **Code + Build** checkpoint, not runtime validation or permission to start TB497. R4 remains authoritative.

## Authority and source-evidence

- Exact frozen source `d78d0c7bcc7486fe2c5497e911e65ca1b8f16b91`; snapshot run 38487953141, artifact 11860840520, outer ZIP SHA-256 `9df8b7e548ecc033ebe9816ce568bb064d371aed45e2e1890c02bca02128cb1b`; inner source manifest **5782/5782** valid.
- Only two semantic changed paths: `src/geometry/SurfaceCellTracing.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`. Git binary patch full SHA-256 `5afc476876a1517b797af1627cee7bbbebd8b618fb3ceb59339446d49665519c`, diff-body SHA-256 `3907568baf7972d85773b630160196d12f60de11de3777ee48155f66a0e3ba84`; forward/reverse apply and whitespace checks verified locally.
- `drive_apply` dispatcher request `22db426efc532e27443b0e55aaa7e801aa399744`, successful run [38488410002](https://github.com/akashskypatel/Directional/actions/runs/38488410002), immutable result artifact 11860269353, outer ZIP SHA-256 `857d09c67575847015f966c09bac3bb1aad3382631a830d9473d542b65837119`; receipt exactly records base, patch hash, semantic commit `62fec4a7f4ccf05a6fe8bc14f81d4b8ff774d809`, and `runtimeExecution=false`. GitHub commit diff confirms precisely those two paths. Owner permanently deleted consumed Drive staging file `1JAQbtaRs5ZW1YFGGA4JRxiY2UxDclMMe`.

## Guard and differential fixture

The first A4 `endpoint_certificate` source consumer previously checked closed-chain existence, vertex simplicity, endpoint-carrier ownership, and all cyclic hard edges but not the claimed `component`. The checked factory would later verify component; relying on that later check allows the earlier consumer to grant a spoofed component's cyclic substitute. The new first consumer checks `hardRailClosedChains[rail].component` against both attachment faces' actual `SourceTopologyRegions::component_for_row`. It returns `closed-rail-component-mismatch` before considering closed-chain geometry or A3 bypass.

The paired Phase10 regression reuses the endpoint-owning forged closed chain from `MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback`. Its real component reaches the *later* `closed-rail-chain-non-hard-edge` rejection; changing only the component to the other real source component must cause `EndpointAttachment`, `InvalidHardRailRouteCertificate`, and `a2bProbeFailure=closed-rail-component-mismatch`, not the later non-hard-edge reason. This is a first-rejection differential, **not a successful closed-rail production fixture**. Neither producer/factory guards nor tolerance/ABI/selector changed.

## Superseding compile-only verification (2026-10-14 UTC)

The original pinned request at dispatcher `608c5338f4a04a3ba3194a7e11ec7956e482c793` has no independently verified mailbox result and must not be called green. A replacement request at dispatcher `463f39802154c518a55a0b23e019f9a910473f62` pinned the later exact source `13df05220f84cba35923855ec50d8aa6c7a6d088` (the same closed-rail implementation/test bytes) and completed **GREEN** in workflow [38492719549](https://github.com/akashskypatel/Directional/actions/runs/38492719549), compile job `115621564151`, package artifact `11862361115`, outer SHA-256 `cf966f536d22b6b88afb11684fe04f11e5a53336ba33b660a67d32d323f9d003`. Independently verified `28/28` internal SHA256SUMS, all eight required targets, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, generated link containing both `libgmpxx.so` and `libgmp.so`, five empty source-status snapshots, `exactArithmeticBackend=GMP`, and `runtimeExecution=false`. The source snapshot [38492441978](https://github.com/akashskypatel/Directional/actions/runs/38492441978) matches that source and verifies 5789/5789 hashes.

**This is compile evidence, not test execution or acceptance.** R4 remains incomplete; no TB497, selector mutation, successor or runtime PASS. Static RA-43.4 ingress census is recorded in `Architecture_M6_CP3_R4_RA434_Static_Ingress_Census_20261014.md`.

## Compile-only evidence

Pinned eight-target GMP/GMPXX compile request at dispatcher commit `608c5338f4a04a3ba3194a7e11ec7956e482c793`, exact semantic source `62fec4a7f4ccf05a6fe8bc14f81d4b8ff774d809`, mailbox `m6-cp3-r4-closedrail-component-compile`: **PENDING**; do not claim GREEN/RED until the immutable compile artifact and source/link evidence are verified.

No tests, benchmarks, binaries, or TB497 were executed in Code + Build; compiling source tests does not establish a PASS. Frozen 497 and CP2/R3 historical baselines unchanged. Still open: RA-43.1/.4 and other reachable RA-46.5 first-rejection/diagnostic cases, RA-47.12 executed liveness in separate TB, the 39 endpoint / 34 Phase10 / 7 DCEL / 88 accepted CP2 / six CP3 runtime gates, organic D1/D2/D3/D5 and A6/A7, and genuine multi-carrier odd-τ. Do not start successor.
