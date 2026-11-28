# CB-218 — Claimed co-trace deletion (2026-11-28 UTC)

## Situation

`M6-CP3-CB-218-P13-CLAIMED-COTRACE-DELETION` passed the compile-only gate. Root `STATUS` governs formal closeout. Successor: `M6-CP3-TB-EXEC-193`. The deletion option defaults off; no test or benchmark was run.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Exact_Manifest.md). Diff [`Architecture_M6_CP3_CB218_P13_Claimed_CoTrace_Deletion_Exact.diff`](Architecture_M6_CP3_CB218_P13_Claimed_CoTrace_Deletion_Exact.diff), SHA-256 `b0be915a4fd5f967a96e354fb6fa2fb78eaba6849028b12014eb50bae98cfab5` (32,417 bytes, +498/−12), applied on the CB-217 postimages.

Preimage (= CB-217 postimage) and postimage SHA-256, all verified before and after apply:

| Path | Preimage | Postimage |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `57097999e067402204bef603b40ca24f966fdaf562596a425da125c6e4ebc22a` | `522cfebbf90dcb806cd9f4f9caf9add379777145689cc75ed73c4aff2beae387` |
| `src/geometry/SurfaceCellTracing.cpp` | `aed2930648277451c90b94a386d2c00c4d09de6aa385eed118ade7fd2de7bf80` | `3a67db446800efe1378c04a1471d64926e2aad88214cfa635c28ce1a3de7c09c` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `c220a00af5ad8d6da07adb604d9165e275d6cff837e29f9401877fbb29751994` | `d02c8507f56f5d7bb55fb909bd74cd614bf60203abcc8a1d6ea91d0d99360bc8` |

Content: `surface_cell_tracing_detail::field_aligned_delete_claimed_co_traces` runs after `field_aligned_select_retraced_traces`, only when `deleteClaimedCoTraces` is true. The option defaults to false and is threaded through the canonical functions, `validate_field_aligned_candidate`, `make_from_candidate` and `diagnose_with_arrival_priority`. `make` is unchanged. Five new `InvalidNetworkTerminalOwnership` conditions (values 13–17) are added, each with a name. New test rows 1012 and 1013 are compiled only and not run.

## Assessment

| Evidence | Exact authority |
|---|---|
| Source | Commit `abe40f6a16e353b25a44a1eafce8f7e46aaee0cb` (CB-218 diff applied on CB-217 source `3e5a26b477e0de0cdde998a8c0c787447b34bd7b`), pushed to the working branch. Patch byte-identical to the frozen diff. |
| Compile request | Commit `5299951f3fae19e0011bf61c2a07744aa2932934` ("Dispatch CB-218 compile-only eight-target build"), `agent-dispatch-request.json` with operation `compile`, request_id and mailbox `m6-cp3-cb218-compile`, artifact prefix `m6-cp3-cb218`, request sha256 `42d0451da7aa6929b217c6efb98744e879fb9fbe510142b0e87a4de6e4859fd5`. |
| Compile | [Run 46109710449](https://github.com/akashskypatel/Directional/actions/runs/46109710449), attempt 1, run number 2261; compile job `140870402115`, mailbox publish job green. All executed jobs success; test_benchmark, noop and drive_apply skipped. Mailbox record `.workflow-mailbox/m6-cp3-cb218-compile/runs/46109710449-attempt-1.json` on `workflow-mailbox`: event sha `5299951f…`, source sha `abe40f6a…`, result success. |
| Candidate | Artifact `m6-cp3-cb218-result-46109710449`, id `15249606947`, 46,632,236 bytes, expiry `2026-12-05T05:05:43Z`; ZIP SHA-256 `3d89344569f498cf2ad21afa0d3e61d25e256abe3d9dbbdf15b0cff172665a6f` (equal to the mailbox digest). SHA256SUMS 28/28 entries verified, no uncovered or extra files. |

Candidate checks: two static libraries (`libdirectional_core.a`, `libdirectional_pipeline.a`), six executables, eight targets listed in `compiled-targets.txt`, `build-exit-code` 0, `preflight-exit-code` 0, five empty source-status records, source commit `abe40f6a…`. GMP receipts: `GMP_ROOT=/usr`, GMP and GMPXX found, one authoritative link command (`directional_surface_cell_authority_kernel_tests`) with `libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`. Command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

No runtime, test, benchmark or local compile was run. Rows 1012 and 1013 compiled only, not run. No promotion. Accepted gate TB-REV-192 1010/1010, CP2 491/491, membership 1091 (1010 gated + 81 deferred), stable 67/17/50, debt1/deferred81. V5 unaccepted. B1 held, B2 carried. O51 remains open.

## Recommendation

Next: `M6-CP3-TB-EXEC-193`, test and benchmark execution only, on the immutable CB-218 candidate `15249606947` and source `abe40f6a1`, against the 1013-row manifest. Then TB-REV-193.
