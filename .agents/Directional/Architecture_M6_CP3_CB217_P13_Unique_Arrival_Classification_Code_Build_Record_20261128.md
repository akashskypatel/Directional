# CB-217 — Unique arrival classification (2026-11-28 UTC)

## Situation

`M6-CP3-CB-217-P13-UNIQUE-ARRIVAL-CLASSIFICATION` passed the compile-only gate. Root `STATUS` governs formal closeout. Successor: `M6-CP3-CB-218-P13-CLAIMED-COTRACE-DELETION`.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Exact_Manifest.md). Diff [`Architecture_M6_CP3_CB217_P13_Unique_Arrival_Classification_Exact.diff`](Architecture_M6_CP3_CB217_P13_Unique_Arrival_Classification_Exact.diff), SHA-256 `d3d3102e85a372d5b5cf4e999fef6caf0852efb3581336f4ba922f566626aff8` (15,476 bytes, +190/−31), applied on TB192 source `c76e74b35ffa5ba6aa1f3f8662f592e077c63033`.

Preimage and postimage SHA-256 of the three paths, all verified before and after apply:

| Path | Preimage | Postimage |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `7fcb9fc2f30b4856f11fe8357c2e91fbf4a1c5d927a878cfeda7d0c9d8def49e` | `57097999e067402204bef603b40ca24f966fdaf562596a425da125c6e4ebc22a` |
| `src/geometry/SurfaceCellTracing.cpp` | `d6dbb123c7d86db3f12032c7827dc68c1b4629c328cfcea956bd7fa010bc650a` | `aed2930648277451c90b94a386d2c00c4d09de6aa385eed118ade7fd2de7bf80` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `9b08f17416d2a9468e6a8668793429b02b4cbc4d167b488e35bfb2f762cf338b` | `c220a00af5ad8d6da07adb604d9165e275d6cff837e29f9401877fbb29751994` |

Content: `classify_field_aligned_candidate_arrivals` returns `FieldAlignedArrivalPortMatch::{Unique, NoPortSlot, SeveralPortSlots}` with each arrival. The public `classify_field_aligned_singularity_arrivals` keeps its signature, returns `nullopt` on ambiguity (fail closed), and leaves `port` empty on no match. No production caller is added. New test row 1011: `FieldAlignedCurveNetwork.CandidateArrivalClassificationRequiresExactlyOnePortSlot`, compiled only and not run.

## Assessment

| Evidence | Exact authority |
|---|---|
| Source | Commit `3e5a26b477e0de0cdde998a8c0c787447b34bd7b` (diff applied on `a74655aeb` beacon base), pushed to the working branch. Patch byte-identical to the frozen diff. |
| Compile request | Commit `86a7434387e555b6674c6c3af9059e393c431cf1` ("Dispatch CB-217 compile-only eight-target build"), `agent-dispatch-request.json` with operation `compile`, request_id and mailbox `m6-cp3-cb217-compile`, artifact prefix `m6-cp3-cb217`, request sha256 `cfe08113ab3f9b479679d68a9fb6cbd2ca69db31fa591df8a3d031982cc6f426`. |
| Compile | [Run 46108573400](https://github.com/akashskypatel/Directional/actions/runs/46108573400), attempt 1, run number 2260; compile job `140866878488`, mailbox publish job `140869102205`. All jobs success; test_benchmark, noop and drive_apply skipped. Mailbox record `.workflow-mailbox/m6-cp3-cb217-compile/runs/46108573400-attempt-1.json` on `workflow-mailbox`: event sha `86a74343…`, source sha `3e5a26b4…`, result success. |
| Candidate | Artifact `m6-cp3-cb217-result-46108573400`, id `15248359837`, 46,560,162 bytes, expiry `2026-12-05T04:49:37Z`; ZIP SHA-256 `4a2d85cf22a4419b904efce3b348d9d1162b1f47d3414ac11e78ed6907933abf` (equal to the mailbox digest). SHA256SUMS 28/28 entries verified, no uncovered or extra files. |

Candidate checks: two static libraries (`libdirectional_core.a`, `libdirectional_pipeline.a`), six executables, eight targets listed in `compiled-targets.txt`, `build-exit-code` 0, `preflight-exit-code` 0, five empty source-status records, source commit `3e5a26b4…`. GMP receipts: `GMP_ROOT=/usr`, GMP and GMPXX found, one authoritative link command (`directional_surface_cell_authority_kernel_tests`) with `libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`. Command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.

No runtime, test, benchmark or local compile was run. Rows 1011 compiled only, not run. No promotion. Accepted gate TB-REV-192 1010/1010, CP2 491/491, membership 1091, stable 67/17/50, debt1/deferred81. V5 unaccepted. B1 held, B2 carried. O51 remains open.

## Recommendation

Next: `M6-CP3-CB-218-P13-CLAIMED-COTRACE-DELETION`. Apply diff `Architecture_M6_CP3_CB218_P13_Claimed_CoTrace_Deletion_Exact.diff` (SHA-256 `b0be915a4fd5f967a96e354fb6fa2fb78eaba6849028b12014eb50bae98cfab5`) on the CB-217 postimages, compile the eight GMP/GMPXX targets with `runtimeExecution=false`. Then TB-EXEC-193 on the 1013-row manifest.
