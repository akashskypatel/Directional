# CB-211R — sphere route and plan witness (2026-11-27 UTC)

## Situation

`M6-CP3-CB-211R-P13-SPHERE-ROUTE-PLAN-WITNESS` meets the compile-only gate. The exact test receipt is committed and compiled. Runtime acceptance is not established. The only next turn is `M6-CP3-CB-212-P13-SPHERE-COMPLETION-INPUT-CENSUS` after the root STATUS beacon records completion.

## Background

The [exact manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md) and [TB-REV-188 adversarial review BB1–BB4](Architecture_M6_CP3_TB_REV_188_Adversarial_Review_20261127.md) govern this turn. The exact CB-210 compiled source is `0409304d6f9f423685ccddc26b19baf4e41ea61e`, package `15162357312`. Comparison to that source confirms only document/control changes and this test receipt. The new output reports `SphereRoute`, `SpherePlan` and one `SpherePlanRegion` per retained plan region after `SphereCompletionFailure` in row858. No assertion is added or changed. The phase-front outcome, producer disposition, decline flags, seed/trace counts, and plan-region boundaries/certificates remain unmeasured.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | 5,170 B, SHA-256 `288e99bf99a72a5ebf370b36ec001f12c0f17db96735a115bbfe537242ab0486`; `tests/SurfaceCellTracingDisplayTests.cpp` only, +87/−0. Preimage `0089c18ef38298c207a52574fb98ed995c2d65db6bceadea6ea1b5de219bc7a9`; postimage `ae573fe424753dec91ea7f691e9f38efbcb2b69cf5304acb367114acbdf7bdbd`. Local `git apply --check`, exact replay and `git diff --check` passed. Full-index transport body differs from reviewed diff only in expanded blob IDs. Remote blob `c4f3bfbe0eefaa139463935078a56a80f826f5c8`; direct commit comparison confirms exactly one path and +87/−0. |
| Snapshot | [Run 45931826341](https://github.com/akashskypatel/Directional/actions/runs/45931826341), job `140286053407`, source `c9fc1c14ae9521f85e0cd798c5a9016b2609daf4`, artifact `15169150012`, ZIP SHA-256 `9b7a561db215128f965d7e31c3cc7f1f69872fb44d0d85cf2ee97bae45b06dc6`, archive SHA-256 `d918484a1a62f349202d0a6ee4d0d08b1ec729151cdc74b44e85c35a9d857f15`, 5873/5873 checks. |
| Apply | [Run 45932143003](https://github.com/akashskypatel/Directional/actions/runs/45932143003), job `140287106662`, request `c82f0b255a2eec0bae5a52f621b665a927e51f70`, source `9412fee8bcac4cb023cde42f07e0cf62027f726c`. Full patch SHA-256 `199dc44f3f75e93a1f66d5cd0f60f00deb49e52d80ce648700406b15dc9d2b20`, diff body SHA-256 `67206a87d9a8e62b0fcaaf7b334f11549b1f6663064f6ebfd13be594b218686b`; result `15168839034`, ZIP SHA-256 `726402d69b2ca6f443ce56a1f8a1c61564e217e73f01056f2b5e64415093c2f5`; log `15168724193`, ZIP SHA-256 `d74d23651d0dfaaa420cb9f58a0a8c237bedf278dc294e2436aeff67b6640951`. Download verification and apply/push exit 0. Workflow identity lacked trash capability; owner connector retired the consumed Drive file. |
| Compile | [Run 45932351805](https://github.com/akashskypatel/Directional/actions/runs/45932351805), job `140287730742`, request `7732d290b67c289688857907fd6faed4b101faa3`, source `9412fee8bcac4cb023cde42f07e0cf62027f726c`. Configure, preflight and build passed. |
| Candidate | [15169033799](https://github.com/akashskypatel/Directional/actions/runs/45932351805/artifacts/15169033799), ZIP SHA-256 `da7bb71d6d4a47e314aa0d800e8b8306074ffeadb0e15d7215d53fdc1eb52bc6`, root manifest SHA-256 `80a5c1d21cc846774ecc0cb12ab9d319b7d24ffd5a3eefffa4894b2b6c47c5d4`, source archive SHA-256 `9d80097c440c5dc608e0081f6d874297fc0088f23b9dde22913d3b8c6624adcf`. 28/28 checks. Expires 2026-12-04T03:09:18Z. |
| Compile log | [15168774628](https://github.com/akashskypatel/Directional/actions/runs/45932351805/artifacts/15168774628), ZIP SHA-256 `72c9de08cfc999a65f9ce1eeb1d818efe4a98c2e2aa18f3336029a945d38d14c`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, five source-status files empty, preflight/build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`, link evidence includes `libgmpxx.so` and `libgmp.so`. Eight exact targets, two libraries and six executables; archived executable modes verified. |

All 1191 archived regular files were compared with the verified snapshot. Only the exact test change and dispatcher request differ. No product, other test, fixture, selector, harness or workflow change. No local compilation, discovery, runtime tests or benchmarks.

TB-REV-188 accepts the activated 1006/1006 gate, not production. CP2 491/491; stable 67/17/50, debt1/deferred81, membership1087. V5 remains unaccepted; BunnyRandom cost cause and fine-resolution close_sheets remain unmeasured. No CP3/497/D0/H4 promotion. The new diagnostics are not proof of the predicted route or region count.

### Closeout checks

- [Cleanup run 45932364993](https://github.com/akashskypatel/Directional/actions/runs/45932364993), job `140287710451`, result `15169260150` ZIP SHA-256 `6d3fe824a7de0022ad6880c717d008db5c90272a93f79f4ed68bd2da41f2ec14`, cleanup commit `46c251855bd4f11c322831bbd99158442dff5bf4`. Snapshot trigger and cleanup manifest removed; ten durable workflow files and dispatcher preserved.
- Document drift audit: zero errors; existing ORIENTATION size warning. All explicitly durable headings retained. Corrected two ORIENTATION references to the withdrawn CB-211 prose plan; no policy or normative edit.
- Process limitations: initial repository policy/handoff inspection preceded verified snapshot acquisition. Full mandatory pre-work policy/LESSONS and external turn-based-coding-agent skill review are not established. Initial local snapshot Git initialization hit ownership restrictions; a separate scratch replay repository verified the exact patch. Early mailbox reads were stale/absent; workflow-specific run lookup was unavailable and exact request-SHA run discovery succeeded. No duplicate workflow trigger. Cleanup took place while compile used the pinned immutable source. Exact multi-attempt tool ledger not retained. These limitations do not establish runtime or product acceptance.

## Recommendation — CB-212 only, after CB-211R STATUS COMPLETE

Use the [frozen manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md) and CB-211R source `9412fee8bcac4cb023cde42f07e0cf62027f726c`. Verify the exact CB-212 reviewed diff SHA-256 `2483d16a2d5f563681b59267ca7d84cb302e6af84aa77da94ead52a27779545b`, one test path, +122/−0. Require preimage `ae573fe424753dec91ea7f691e9f38efbcb2b69cf5304acb367114acbdf7bdbd`, postimage `6149b26dc7564342261920c1b669e25dfd61cb3ba323cf844ecff07aa65f16cc`. Compile the same eight GMP/GMPXX targets only; no runtime. STOP on any mismatch. Do not combine the two CB turns or advance to TB-EXEC-189 until CB-212 completes. No V5, B1 repair, fallback repair, CB-207D, activation change or product promotion.
