# M6-CP3-CB1-ENTRY-R4 — distinguish absent open-rail contact from closed-chain authority (2026-10-11)

**Boundary:** canonical `M6-CP3-CB1-ENTRY-R4` Code + Build remains `IN_PROGRESS`, successor `UNKNOWN`. PR #8 draft/unmerged. No generated Directional binaries, tests, benchmarks, discovery/list, CLI or frozen TB497 may execute here.

## Exact-source review and change

- Independently verified source snapshot GitHub workflow `38166594857`, event `3c4136f79de5c986a210a91de0bc359a74779879`, artifact `11711957825`, provider ZIP SHA-256 `4244dc159746c55339230a9ec9a41294b6aed829b44b6ceec2319e468e5f2896`, inner source.tar.gz SHA-256 `b2c2267906c68b471a3569cf92dbf9ed761eb48e9bbb9ea5222658b7ec046f53`, **6243/6243** source SHA256SUMS verified; `runtimeExecution=false`.
- At `src/geometry/SurfaceCellTracing.cpp` `endpoint_certificate`, a missing `hardRailTerminalContacts` map entry previously entered the *closed-rail* endpoint path without checking that the same `HardRailId` belonged to `hardRailClosedChains`. This means a source-invalid open-rail route could proceed through the contact-free carrier-face branch and reach checked A4, which separately rejects absent provenance, instead of failing at the earliest A2b producer decision.
- The new branch requires `hardRailClosedChains.contains(*first.railId)` before using the contact-free cyclic endpoint certificate, otherwise returns `missing-terminal-or-closed-rail-provenance`. The closed-chain-published path is unchanged; genuine open-rail paths with matching contacts are unchanged.
- Diagnostic after rejection now includes `a2bProbeClosedChainPresent` next to the existing contact/carrier/A3 probes; the diagnostic never chooses an acceptable path or relaxes factory authority.
- Source patch SHA-256 `5812823abb2e99772773cc7ea8392efa738f6d013814be5f467d96fd2574bdc3`, body `dda0ced6da41f6f683952d761ece7aa8a5d563e967a63c36790c65b4e96a634a`, base `3c4136f79de5c986a210a91de0bc359a74779879`, one production source path, Git patch/whitespace checks passed. Applied semantic commit `d8698996f3c3206830bc2aedeae06d7019d523a3` by `38167011887` (job `114551625145`), Drive result `11712078068` provider ZIP SHA-256 `540f89355a89bf22df468524d936174ac55881c6347e40d27adf0bede1aea5a9`; log artifact `11712048181` SHA-256 `c3589cb1c4126c75a946cb616b6b4352d2d1671e7c01edf6d922c007bb6d95f2`. The transient Drive File ID was permanently owner-deleted after exact push verification.

## Compile-only evidence

Exact eight-target GMP/GMPXX compile **GREEN**: workflow `38167114181`, job `114551928729`, source `d8698996f3c3206830bc2aedeae06d7019d523a3`, preflight/build `0/0`, eight targets built, CMake linked `libgmpxx.so` and `libgmp.so`, package checksum manifest `28/28`, source tree clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11712702267` ZIP SHA-256 `7e285a50395217a3d47c5dafd6a851c695eaebceaf6e64cb7c9e3675d0e6e9a6`, diagnostic artifact `11712622481` ZIP SHA-256 `77fdd8868e9aba9e43df1ccab219cd8592c97274678e806f68c46cc19b835f14`. No runtime tests, benchmarks, or selector discovery executed.

## Deferred executable test cases (not run in Code + Build)

1. Produced open hard rail with an authentic contact: ensure checked A4 production and terminal A3 paths remain unchanged, using existing source-valid 3×3 fixture.
2. Same valid rail without its typed contact and with no closed chain for its rail ID: require first A2b producer rejection `InvalidHardRailRouteCertificate`, diagnostic `missing-terminal-or-closed-rail-provenance`, `a2bProbeContactPresent=0`, and `a2bProbeClosedChainPresent=0`.
3. Source-valid closed chain with no terminal contact: retain the closed-rail path and verify no invented source terminal vertex/contact paths are created.
4. Foreign closed chain keyed by a different `HardRailId`: reject, rather than treating any nonempty closed-chain map as sufficient. Distinguish pre-A4 and A4 first rejection.
5. Keep all frozen selector identities and expected source-owned A3 gate intact; zero-selected runtime filters cannot count as pass.

**Acceptance limitation:** No runtime result is available here. Historical accepted CP2 remains `491/491`; independent R3 `403/497`, 94 RED with 88 previously accepted CP2 losses. The 39 endpoint, 34 Phase10, seven DCEL negatives, six CP3 gates, authentic multi-carrier/odd-τ, and dual-path independent Review remain open. Do not launch the frozen 497 Test + Benchmark in R4 Code + Build.
