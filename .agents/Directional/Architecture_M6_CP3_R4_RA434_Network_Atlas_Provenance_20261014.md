# M6-CP3-CB1-ENTRY-R4 — A2a/A3 network/atlas provenance first-ingress code+build record (2026-10-14)

**Turn:** same canonical `M6-CP3-CB1-ENTRY-R4` Code + Build. R4 remains incomplete. No successor, TB497, local compile, generated binary, test, benchmark, selector or workflow modification.

## Source-exact defect and existing partial protection

Analyzed verified immutable GMP compile source `f04eda9743e94e42cac9b19f6ada29ae7fde1a07` from [run 38536008896](https://github.com/akashskypatel/Directional/actions/runs/38536008896), result artifact `11879114903` SHA-256 `672efa0e70715eb9fdfd6085efa8e010c0870792dcb674a4c8eb52113bf175a8`, with **28/28** packaged checksums. In `SurfaceCutGraph.cpp:995`, the checked S4 cut graph already proves exact A2a network to A3 atlas binding with `source_digest` and `field_transport_atlas_hash`. But the direct `SurfaceCellTracing.cpp:5663-5671` `source_authority_valid` and `:18761-18784` `build_surface_cell_network` entry checked source/atlas compatibility without this independent **network/atlas pairing**. A caller may otherwise supply separate, individually valid products from the same source; the default full pipeline's S4 gate is already stricter. No current runtime acceptance bypass is claimed.

## Exact change and positive witness reused

The patch adds local `field_aligned_network_binding_valid` as a two-digest check if both A2a network and A3 atlas are present, preserving legacy absent-atlas/network options. `source_authority_valid` enforces it at direct trace entry; `build_surface_cell_network` rejects a mismatched pair with existing `InvalidTopologyRegionTransport` **before phase-front state construction and seed/trace output**. Only one production file changed; no public ABI or enum changes.

An **existing** test identity `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` in `tests/FieldAlignedCurveNetworkTests.cpp` already constructs independently valid gauge-relabelled atlas/network pairs on the same source: equal network semantic digest but different atlas provenance digest. Its extension deliberately combines baseline network with relabelled atlas and requires the first phase-front rejection plus empty seeds/traces. This is a falsifiable cross-product witness; no new test identity or frozen selector modifications.

## Immutable apply receipt — verified

- Exact base: `f04eda9743e94e42cac9b19f6ada29ae7fde1a07`; patch paths: `src/geometry/SurfaceCellTracing.cpp`, `tests/FieldAlignedCurveNetworkTests.cpp` (46 insertions); full patch SHA-256 `5ab02385a1ca63d1da8dcb6f7478b41010934ae29127ea8b04cd3bb65867fa65`, diff body SHA-256 `df2141cb29c597f988eb249a445b860caa293c8fa2d99d5d4fa6d2a56f5295c7`. Exact-base forward/reverse and whitespace checks passed.
- Preserved work-patch in ChatGPT Library `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R4__base-f04eda9743e9__RA434-atlas-binding.patch`; downloadable `Directional_R4_RA434_atlas_binding_preservation.patch`.
- Uploaded via authorized ChatGPT Library Google Drive path to `My Drive/Directional-CI`, file ID `1xRn14LytBt6y_3L60zdYVVoCaHdvMfEa`. Durable request commit `ee6e1cb5c1499f57adba44e29cb714da148c4498`, mailbox key `m6-cp3-r4-ra434-atlas-binding-apply`.
- [GitHub Actions run 38540378531](https://github.com/akashskypatel/Directional/actions/runs/38540378531) succeeded. Apply job `115773504877`, mailbox job `115773742019`; compile and TB skipped. Result artifact `11882690492`, independently verified ZIP SHA-256 `0d85ec61922d0e09da974f0b3d96dd48175e7d2b0779d3607e8e703eee7c9296`, records exact event/base/patch and `runtimeExecution=false`.
- **Applied semantic commit: `bbf2902ab56c6000867e538c16300720f95b14ff`**. Independent GitHub comparison against dispatcher commit lists exactly those two paths, 24 and 22 changed lines. Owner-authorized Google Drive permanent deletion completed successfully after verified application.

## Historical precompile checkpoint (superseded by the verified compile below)

**As of the preceding apply closeout (now superseded):** a compile of `bbf2902ab56c6000867e538c16300720f95b14ff` was not yet requested. The earlier eight-target GMP/GMPXX green at `f04eda9` cannot prove the new change compiles. At next same-turn continuation, dispatch existing `agent-operation-dispatcher.yml` operation `compile`, pinned to `bbf2902...`, with eight standard targets, `DIRECTIONAL_ENABLE_GMP` / actual GMPXX+GMP link, clean source checkpoints, `runtimeExecution=false`, immutable result and logs, 28/28 package hashes. Diagnose compilation failures without invoking any executable. Preserve the newly compiled negative as **not runtime executed**, and require separately authorized artifact-only Test + Benchmark for acceptance.

Other R4 debts unchanged: independently authenticated RA-43.1 A4-selected/A1-admitted branch receipt, broader RA-43.4, RA-47.12 liveness, 39 endpoint, 34 Phase10, seven DCEL, 88 previously accepted CP2 regressions, six CP3 positives, organic D1/D2/D3/D5/A6/A7, true odd-τ multicarrier acceptance. Frozen 497 selector and historical accepted ledger unchanged.

## Exact semantic-source GMP/GMPXX compile verified (2026-10-14)

The pending compile is **COMPLETE** for applied semantic source `bbf2902ab56c6000867e538c16300720f95b14ff`. Durable dispatcher request commit `9fefd12ac60d8ca92a0a056f5cd5c155c85ac5a3` called the unmodified reusable compile workflow and published the matching mailbox `m6-cp3-r4-ra434-atlas-binding-compile`. [GitHub Actions run 38541872128](https://github.com/akashskypatel/Directional/actions/runs/38541872128) succeeded: compile job `115778443635` and mailbox job `115779319542` both succeeded, with Test + Benchmark and Drive apply skipped. Pinned source is the applied `bbf2902` commit (not the later documentation/STATUS head).

- Immutable result artifact **`11883030813`**, independently verified ZIP **SHA-256 `6ba61fd158e7a6390d7255a31957515b0abf832d3e3a53ee0a894a030b8a10fc`**, 28/28 package `SHA256SUMS` digests correct. Artifact expires 2026-10-21. Log artifact `11882966186`, SHA-256 `10a13eedecb48ae2fdc7f6aaaf7a466855fc8896a2937707ff83645305cea181`.
- All eight standard compiled targets are present; preflight/build exit codes `0/0`. Generated linker evidence contains both `libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`; all five source-status records are clean. Explicit command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.
- The immutable result's source archive is named `source-bbf2902ab56c6000867e538c16300720f95b14ff.tar.gz`. Verified code contains `field_aligned_network_binding_valid` in `SurfaceCellTracing.cpp` and the gauge-relabelled negative fixture in `FieldAlignedCurveNetworkTests.cpp`. This **does not** prove a runtime rejection/pass; no generated Directional binary, test, benchmark, CLI, or TB497 executed.

## Remaining same-R4 continuation after compile

Do not rerun unchanged-source compile. Continue independent source-domain RA-43.1 A4-selected/A1-admitted branch-authentication Review, unclosed RA-43.4 consumer paths and organic producer evidence where actually identified; actual liveness and accepted regressions require separately authorized artifact-only TB. Frozen 497 selector, legacy ledger, and successor remain unchanged. No source/test changes after the compiled semantic commit.
