# CB-220 — Region corner sides (2026-11-28 UTC)

## Situation

`M6-CP3-CB-220-P13-REGION-CORNER-SIDES` passes the compile-only gate. Root `STATUS` governs formal closeout. The successor is `M6-CP3-TB-EXEC-195`. No production caller was added. No test or benchmark ran.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB220_TB195_Region_Corner_Sides_Exact_Manifest.md); [corners DEFN](Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_20261128.md), CR1–CR4. Frozen diff [exact diff](Architecture_M6_CP3_CB220_P13_Region_Corner_Sides_Exact.diff), SHA-256 `35a164a8b4490ae1e6ab29f480745d49f8bbd0f79db84c0334d94f87bb7141fa`, 22405 bytes, +434/−0. All three existing preimages, the absent new source preimage, and all four postimages match the manifest. Apply, reverse-apply and whitespace checks pass. Remote Git blob identities match all four local postimages. `build_region_corner_sides` derives per-region corners and corner-delimited side counts, or returns one of six typed failures. Row858 diagnostic receipt and two guard tests are compiled, not run.

## Assessment

| Evidence | Exact authority |
|---|---|
| Snapshot | Run `46131080596`, job `140936189498`, artifact `15257606310`, source `1922d81724c8a8a7e75fc97031cdaca800fd1f1b`, ZIP SHA-256 `6f01dbfe2c33610ab7209136793bfecf488c679907f539db2f798bcc0d504406`, 5911/5911 checks. |
| Application | [Run 46131286374](https://github.com/akashskypatel/Directional/actions/runs/46131286374), job `140936874450`, event `1aefac1e531e8e05e683f821d05215ac8d279470`, result `15257955978` ZIP `78c794d687de64aafcaf77f9525e7672d7628fac40df52b036157f4543d062cb`, log `15257661372` ZIP `80e07457a0420b5c6881a3f0c9f6a6050901e37e411c9de158cc955417b6d519`. Full transport patch SHA-256 `59d5ef1033fa1a508a744bae2db36a1e0e8b7f93375aec56c61c72f55772350b`, apply and push exit 0. Owner-authorized Drive retirement confirmed. |
| Source | `e55f01b9ac86e2dc0159771a45521cb6f35049be`. Exactly four paths; +434/−0. |
| Compile request | Commit `763e2576950212f966556605686108b5d2baeab0`; request/mailbox `m6-cp3-cb220-compile`. |
| Compile | [Run 46131427922](https://github.com/akashskypatel/Directional/actions/runs/46131427922), job `140937296936`, mailbox success, compile log `15258282782` ZIP `bc2e1595c35d5d4c3b714b187613995878baf5997b5b5c1415ec955fbe8a1380`. |
| Candidate | Artifact `m6-cp3-cb220-result-46131427922`, ID `15257943465`, 46729671 bytes, expiry `2026-12-05T09:48:32Z`; ZIP SHA-256 `eb7e5ea11cb129c9d0ff33931967cf9bcf7227a831ff9af59014f44f9faa4f71`; SHA256SUMS 28/28, root manifest `eac14312b4efc6686fffc5b90bd888a55237e723d3a7f0a160af7a6496888bf5`, source archive `d268be90335fd0cc30fa32d99950b835405da7a55c09dec9ab395443acfa2e6c`; all four postimages match. |
| Cleanup | Run `46131439515`, receipt `15258016877`, ZIP SHA-256 `01fed2138885f9c69805acda2c3015ac33d544ba5cd25d83192db2295d04dafe`, commit `b59ecef20b12bd041924e5bd6c27b173c9ac11af`; exact snapshot marker and cleanup manifest removed. |

Two static libraries, six executable files, eight targets; build and preflight exit 0; clean source status; GMP and GMPXX linkage verified; `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`. No local compile, test, benchmark, or unapproved source change. The candidate contains the frozen harness, full gate case manifest and deferred ledger. CP2 remains 491/491; TB-REV-194 remains the last accepted test gate (1013/1013). Stable 67/17/50, debt1/deferred81; pinned O51 accepted, O52/O50 open, B1 held, B2 unmeasured; V5 not rerun. No production or checkpoint promotion.

Documentation audit: zero errors. The orientation size warning predates CB-220. The three protected-file warnings concern the handoff, orientation and roadmap updates that closeout requires and the user authorizes. No policy, design, selector, fixture, harness or workflow changed.

## Recommendation

Next `M6-CP3-TB-EXEC-195`, immutable candidate `15257943465`, exact source `e55f01b9ac86e2dc0159771a45521cb6f35049be`. Use the frozen 1015-row manifest and TB194 comparator. Verify the full gate, row858 insertion and CR2 predictions, and two guards; stop for review on any mismatch. Do not activate corners or adapt any rule during execution. Then TB-REV-195. No successor work in CB-220.
