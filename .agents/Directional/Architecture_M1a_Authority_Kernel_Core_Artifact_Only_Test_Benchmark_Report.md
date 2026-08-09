# M1a Authority Kernel Core — Artifact-Only Test + Benchmark Report

**Status:** accepted  
**Turn type:** Test + Benchmark only  
**Architecture milestone:** M1a — authority kernel core  
**Implementation under test:** `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7`  
**Production behavior delta:** none  
**Review policy:** `never`  
**Date:** 2026-08-09 UTC

## 1. Decision

M1a is **accepted** under immutable artifact `9041930767`.

The authority kernel passed exact package/source/dependency preflight, exact test discovery, all 14 semantic/counterexample contracts, and the accepted T1 preservation boundary. The four required-green direct cases remained green, BunnyRandom retained its accepted known-red independent-oracle-before-product-failure path, and Vase remained bounded/nonreturning at 60 seconds. No packaged regular file changed.

M1b may proceed only as one bounded production-consumer migration. The approved next Code + Build plan is `.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Plan.md`.

## 2. Immutable authority

| Evidence | Value |
|---|---|
| Entering pre-M1a branch head | `9f1d3ebd91403252e990f785c3521588197b4fd4` |
| M1a implementation | `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7` |
| Build/event commit | `a29c1f673ea93e1614751f42a0c1fef94d23e1fe` |
| Workflow run/job | `31327073928 / 93279043100` |
| Result artifact | `9041930767` |
| Result ZIP SHA-256 | `1c1325c038ffe26b80e00dbb69fb15de8b0d0a42673d9720f28bcd9de8549ec5` |
| Log artifact | `9041930871` |
| Log ZIP SHA-256 | `e99e053ea4503b720dbe9b6c9ed4762a4eedcbf67c15261e8ea4317824c427cb` |
| Recursive package manifest | **53/53**, `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6` |
| Package regular files | **54** including `SHA256SUMS` |
| Code + Build closure | Release/static/Ninja **120/120**, `PRE_TEST` |
| Code + Build boundary | `runtimeExecution=false` |
| Accepted T1 comparison artifact | `9041289209` |

Preflight and postflight re-hashed both original ZIPs to the exact values above.

## 3. Package/source/dependency preflight

Preflight passed before any packaged binary ran:

- both ZIP outer hashes exact;
- no absolute, `..`, or escaping ZIP member paths;
- exactly 54 result-package regular files;
- exactly 53 `SHA256SUMS` entries and **53/53** verified;
- `SHA256SUMS` digest exact: `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6`;
- seven ELF executables;
- two static libraries;
- 27 fixture files;
- source patch/archive/compile database present;
- `runtimeExecution=false` in build-authority and command-boundary records;
- exact implementation/build/entering commits present;
- exact toolchain and submodule authority present.

Static manifest hashes were exact:

- authority-kernel 14-name manifest: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- T1 oracle 29-name manifest: `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

Source archive path inspection found 552 members and no unsafe path. Recomputed Git blob IDs matched package metadata for all eight M1a implementation paths and the three retained T1 source-authority paths.

Additional exact source/package hashes:

- M1a patch: `51d0f6e79681d8e02fea58781a9aaf35609ebd6e40230ecee538d7e4d02922b2`;
- source archive: `1c0290da02148d0798f668d2d9ddbd91d6262ca875f3fb1b2d38cd162da7e2c3`;
- compile database: `5288ccccdc7814dcda9b96dcf2e7bb5018ccb5d482b0b2d0cdab021895558088`.

## 4. Byte-identity preservation against accepted T1

Accepted T1 artifact `9041289209` was re-opened and all eight pre-existing M1a members were compared by SHA-256. Every pair was byte-identical:

| Member | SHA-256 |
|---|---|
| `lib/libdirectional_core.a` | `d047dd9e9433a050480068b7d0fac1517026a7741bf11c86da376610c1fadd25` |
| `lib/libdirectional_pipeline.a` | `4f0f9079034f1d61fc3fb5a44d0ae0667e5814fec158fce8418d775c99587495` |
| compiled API tests | `41bcf7db93b9d062545f9f0d6fbed8de1253e0ab1a4e471e8d7622ed27af3b9a` |
| producer tests | `a7cfc1637906d106992f9d391359d46549bb70b28f9bdbabe3c4c5289c6050a6` |
| oracle tests | `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90` |
| completion tests | `ba8052942454e2691bedb6fe237aa5cd751e993cca045ebd0b6fc291f4127261` |
| validation tests | `b4be6cd64ef84bc857ba5156d6c108c3d9ec9248dba968315a633690b4350bcd` |
| benchmarks | `af85f102974449bd4561ded0aec9b00c8168e3c8cc5ddc68843842c1b6fcb6e8` |

Only the new authority-kernel test executable is additional.

## 5. Authority-kernel discovery and semantic contracts

`directional_surface_cell_authority_kernel_tests --gtest_list_tests` was executed exactly once.

Discovery result: **14/14 exact names and order**, no missing or extra test.

Parsed discovery digest: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`.

All 14 contracts then ran individually in fresh processes: **14/14 passed**.

Source inspection confirmed the contracts exercise the intended M1a semantics rather than count/no-crash proxies:

1. compile-time non-convertibility covers face/chart, transition/face, region/sheet, sheet/chart, and raw integer construction/conversion;
2. checked conversion proves valid exact conversion plus typed negative and out-of-range rejection;
3. equal raw numerals remain distinct source-face and field-chart domains;
4. source-edge endpoint reversal canonicalizes while explicit orientation stays separate; degenerate edge is typed-rejected;
5. tagged source-vertex and source-face-interior supports remain distinct;
6. quarter turns normalize modulo four, including negative input, and four unit turns close exactly;
7. grid automorphism proves left/right identity, left/right inverse, and representative associativity;
8. nonzero rotation plus integer translation round-trips exactly;
9. a genuine boundary transition with no interior transition is valid;
10. an interior transition missing its named `InteriorTransitionId` is typed-rejected and a valid nonzero-rotation transition is retained exactly;
11. canonical route reversal is involutive and preserves oriented steps;
12. unrelated representation-handle perturbation does not alter canonical semantic route;
13. named legacy adapter round-trip preserves semantic region identity;
14. deliberate source-face-to-field-chart adapter misuse is rejected with typed domain mismatch.

The static-only contract uses compile-time assertions as its semantic oracle; its runtime `SUCCEED()` merely packages that compile-time proof and was not treated as independent runtime behavior by itself.

## 6. T1 oracle preservation

`directional_surface_cell_oracle_tests --gtest_list_tests` was executed exactly once.

Discovery result: **29/29 exact names and order**, no missing or extra test.

Parsed discovery digest: `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

All 29 independent-oracle positive/mutation/metamorphic contracts ran individually in fresh processes: **29/29 passed**.

This preserves accepted `RP-02 / TA-05` test authority.

## 7. Direct production comparison

All authoritative direct runs used fresh processes and the exact packaged producer executable.

| Case | Exit | Wall | Peak RSS | Result |
|---|---:|---:|---:|---|
| Plane | 0 | 1.00 s | 11,076 KiB | green; oracle-clean |
| MultiFaceSeam | 0 | 1.53 s | 11,048 KiB | green; oracle-clean |
| CloseSheets | 0 | 12.16 s | 13,512 KiB | green; oracle-clean |
| Cylinder | 0 | 6.82 s | 14,960 KiB | green; oracle-clean |
| BunnyRandom | 1 | 56.93 s | 338,356 KiB | known-red; same accepted T1 failure path |
| Vase | 124 | 60.00 s | 89,780 KiB | bounded nonreturn; safety evidence only |

BunnyRandom reproduced the accepted T1 semantics exactly: independent oracle failure appears first at source line 197 with `EmptyOutput`, `NonQuadOutput`, component/Euler mismatch, output-origin mismatch, and `TerminalFailureObserved:NotProductionReady:completion`; only afterward does the unchanged fatal product-success assertion fail at line 199 with `traceSegments=170831 arrangementCells=0 completedQuads=0`.

Vase produced no returned result before the 60-second guard. No correctness, success, or nontermination claim is made from the timeout.

The four required-green cases, Bunny failure signature, and Vase timeout disposition match accepted T1 comparison authority. Runtime differences are timing/environment observations only; the executable bytes are identical.

### Orchestration note

A first combined local harness completed the four green direct cases but the surrounding execution tool terminated while BunnyRandom was still running. A second foreground Bunny invocation was similarly interrupted by the tool's own command-duration limit. Neither interrupted invocation is runtime authority and neither produced a completed test result. The same immutable binary/filter was then run under the planned 90-second process guard through a detached bounded wrapper and completed with the authoritative 56.93-second result above. No package regular file was altered.

## 8. Postflight integrity

After all runtime execution:

- both original ZIP SHA-256 values remained exact;
- all **53/53** manifest entries re-verified;
- before/after hashes for all 54 packaged regular files were byte-identical;
- the only runtime locator added was the non-regular symlink `bin/test-data -> ../test-data`;
- no source, test, fixture, CMake, validator, benchmark, manifest, or packaged regular file was edited or regenerated.

## 9. Regression-pattern disposition

| Pattern | M1a immutable result |
|---|---|
| `RP-01` | **M1a kernel accepted**: strong domains and checked typed conversion counterexamples pass. Production adoption remains staged. |
| `RP-02` | **preserved**: exact 29-name discovery, 29/29, four green direct cases, Bunny/Vase visibility. |
| `RP-05` | **M1a kernel accepted**: source-edge canonicalization, explicit orientation, representation-handle metamorphism, route reversal pass. Production adoption remains staged. |
| `RP-07` | **M1a kernel accepted**: exact modulo-4, automorphism identity/inverse/associativity, nonzero rotation, and reversal pass. Production adoption remains staged. |
| `RP-03`, `RP-04`, `RP-06`, `RP-08`, `RP-09` | untouched; byte-identical pre-existing artifacts and unchanged direct behavior. |

M1a acceptance creates or resolves no production regression event. Historical totals remain **34 events / 14 categories / 20 recurrences**.

`PR8-R034 / G4-R007` remains **active** on production artifact `9031804178`; M1a does not change or reclassify the direct torus failure.

## 10. Acceptance gate

All M1a acceptance conditions passed:

- package/source/dependency authority exact;
- authority discovery exact 14;
- authority semantics **14/14**;
- T1 oracle discovery exact 29;
- T1 oracle **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder preserved green;
- Bunny/Vase remain explicit known-red/deferred without synthetic promotion;
- no production-result drift;
- no package mutation or source repair.

**M1a is accepted.**
