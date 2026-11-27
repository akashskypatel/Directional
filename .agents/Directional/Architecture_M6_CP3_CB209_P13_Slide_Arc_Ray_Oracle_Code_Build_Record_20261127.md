# CB-209 — slide arc ray oracle (2026-11-27 UTC)

## Situation

`M6-CP3-CB-209-P13-SLIDE-ARC-RAY-ORACLE` meets the compile-only gate. The exact reviewed test change is committed and compiled. Runtime acceptance is not established. The only next turn is `M6-CP3-CB-210-P13-SPHERE-COMPLETION-FAILURE-RECEIPT`.

## Background

The [exact CB-209 manifest](gates/Architecture_M6_CP3_CB209_P13_Slide_Arc_Ray_Oracle_Exact_Manifest.md), [TB-REV-186](Architecture_M6_CP3_TB_REV_186_P13_Activated_Sphere_Full_Gate_Independent_Review_20261126.md) and [adversarial review AA1](Architecture_M6_CP3_TB_REV_186_Adversarial_Review_20261126.md) control the change. The test separates ten original slide segments from fourteen clipped arc occurrences (six whole, four prefixes, four suffixes), and checks exact source support, split fractions, both interior-wall ray orientations and ten vertex-end rays. The exact parameters are pinned cross-representation witnesses, not an independent geometric derivation. No new test expectation was designed in this turn.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | 14,643 B, SHA-256 `6f17d7c84672dc3780ca15e6556f2ffbc40bbd5565c881242f14573afe38fcc4`; `tests/FieldAlignedCurveNetworkTests.cpp` only, +186/−19. Preimage `073d5254b055a74ac32e6509418375c3ad31058c20f263139f5f5481e81017da`, postimage `a371dffbb30576dfe492631ecd68f2006b1cef01b721f2518a8472362e617584`. Local `git apply --check`, exact replay, `git diff --check` passed; remote Git blob `4beb89bec56b1800f905e864c1c30dfaf78344ce`. |
| Snapshot | [Run 45911116148](https://github.com/akashskypatel/Directional/actions/runs/45911116148), job `140219523281`, source `c28dca740453ec18d22adc01aeec2e6570239e31`, artifact `15159623992`, ZIP SHA-256 `0ce6bb8a2faad1b54113908ccb0315f1a987e265e2405e5f25eecb5503b4a342`, archive SHA-256 `865d7603c6b1d5f318014accf7e04c76594ce70e7528e02cf1d52e265178b097`, 5865/5865 checks. |
| Apply | [Run 45913793578](https://github.com/akashskypatel/Directional/actions/runs/45913793578), job `140228229506`, request `fffaa7b929358d114a15d056977b76656327d07b`, applied source `62e888727803fcc2640dd5fba4a9369229d8df2b`. Patch SHA-256 `c09d34d5c581f5311aef5dec00ba39d20add3287af1c7aa37d7f7828456713b6`; result `15161620877`, ZIP SHA-256 `8bbbdb36561bf72f2bdbac8a5c38870e6800ce79b995cdb48fb46e8895fc3f30`; log `15161099230`, ZIP SHA-256 `8cad2b3c3e4ced3b260958f6c4c706b674bee8284fd42f1e229a06818fa6e811`. Download and apply/push exit 0; owner connector deleted the consumed Drive file. |
| Compile | [Run 45913923121](https://github.com/akashskypatel/Directional/actions/runs/45913923121), job `140228617825`, request `750a671418041dc164d748dc10a2e938cd720fda`, exact source `62e888727803fcc2640dd5fba4a9369229d8df2b`. Configure, preflight and build passed. |
| Candidate | [15161541555](https://github.com/akashskypatel/Directional/actions/runs/45913923121/artifacts/15161541555), ZIP SHA-256 `5131c44209e0a74eab7f42c90f68b772a2cd1e73492769280caec702b2252630`, root manifest SHA-256 `ee8a111d605c41a8d02adc966014655c65d2f379b99439192abfd26521f82eeb`, source archive SHA-256 `01cd5d55c0ebb7a0d5089dd994c819a23fc4542fc393c75f96f4179a0d611830`. 28/28 checks. Expires 2026-12-03T23:59:53Z. |
| Compile log | [15161711178](https://github.com/akashskypatel/Directional/actions/runs/45913923121/artifacts/15161711178), ZIP SHA-256 `6e95dc3ce199f5f7f751da7c557d3e61373d851e7887596a7fb378e3cfb3cc3f`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, five source-status files empty, preflight/build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`, link evidence includes `libgmpxx.so` and `libgmp.so`. Eight exact targets, two libraries and six executables; archived executable modes present. |

All 1183 archived regular files were compared with the verified snapshot. Only the exact test change, `STATUS` and the dispatcher request differ. No product, other test, fixture, selector, harness or workflow change. No local compilation, discovery, runtime tests or benchmarks.

TB186 remains a valid semantic RED at 1005/1006. No stable product regression proved from row971. The accepted preactivation comparators TB185V/TB187Q remain 1006/1006, CP2 491/491, stable 67/17/50, debt1/deferred81, membership1087. No CP3/497/D0/H4 promotion. V5, fine-resolution close_sheets and the exact completion rejection remain unmeasured.

### Closeout checks

- [Cleanup run 45914248684](https://github.com/akashskypatel/Directional/actions/runs/45914248684), job `140229592911`, result `15161631524` ZIP SHA-256 `d9df14733d3ea34cc03fbc8cdbc7029ef1571c5a3d682ad947f8adb06d58bb82`, cleanup commit `169e9648c10c2679e06f1b93d7710746472ef2ce`. Snapshot trigger and cleanup manifest removed; durable workflows and dispatcher preserved.
- Document drift audit on the final local document set: zero errors, with the existing ORIENTATION size warning. All explicitly durable headings in the changed documents retained.
- Process limitations: the first attempt inspected repository documents before snapshot verification, did not complete the external turn-based skill review (404), and did not retain an exact multi-attempt tool ledger. Repeated early mailbox reads returned stale/absent records. Local replay first encountered a Git ownership check; replay in a separate scratch repository succeeded. A regenerated diff differed by a blank context-line marker; the original frozen body and exact postimage were used unchanged. Full mandatory pre-work policy/LESSONS review is not established. No successor work performed.

## Recommendation — CB-210 only

Use compile source `62e888727803fcc2640dd5fba4a9369229d8df2b` and package `15161541555`. Apply the single separate exact test-only receipt under the [CB-210/TB188 contract](gates/Architecture_M6_CP3_CB210_TB188_Completion_Receipt_Activated_Full_Gate_Exact_Manifest.md) after CB-209 STATUS COMPLETE. Verify the exact CB-210 pre/postimages; compile the same eight targets with GMP/GMPXX. No runtime in CB-210. TB-EXEC-188 uses the eventual CB-210 package, not the present CB-209 package. Require unchanged 1006-case membership plus 81 deferred, compare to TB186 under frozen N1–N3 and both accepted preactivation comparators; only row971 PASS and one row858 `SphereCompletionFailure` receipt may change vs TB186. Run V5 only after the valid full gate; STOP on RED, unexpected material change or invalid boundary. No acceptance or promotion until independent Review.
