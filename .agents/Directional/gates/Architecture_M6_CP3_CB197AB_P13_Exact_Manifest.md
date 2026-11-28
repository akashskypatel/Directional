# CB-197A / CB-197B exact manifest (2026-11-23 UTC)

**This file is a review artifact. Neither diff is applied to live source.**

**Authority:** [TB-REV-175 adversarial continuation](../Architecture_M6_CP3_TB_REV_175_Adversarial_Review_20261123.md), G1–G4. It replaces the prose CB-197A.

## CB-197A — trace-piece builder extraction (product-neutral)

- **Patch:** `Architecture_M6_CP3_CB197A_P13_Exact_Trace_Piece_Builder_Extraction_Exact.diff`.
  - SHA-256 `bf679210a15d0f1005b540c09972909e9f47c41db11ae0cc977c24d467eb7fc6`.
  - 20,023 B, +197/−176, three files.
- **`src/geometry/EmbeddedGraphTopology.cpp`:**
  - git preimage `8547f53692443e5201547e5cf28dd2db2cf5bc64`;
  - postimage SHA-256 `61a0fbac4ada9b7a5efbb83c725122af78479411a2a1af2d2f02c8f9ebdead30`.
- **`src/geometry/EmbeddedGraphTopology.h`:**
  - git preimage `d46f39d0142d925bafade7286f958ddee5720eb8`;
  - postimage SHA-256 `bb2c298f7e2353a6cc9949228db729b5bb84d5ea266413b849a5ba23b311b2a6`.
- **`src/geometry/ExactTraceSegmentPieces.h`:** new file, SHA-256 `6279c6d6e08a14d2b80dff799231249d2e8a9939c09fa88bf2b52eb314bac9da`.
- **Scope:**
  - Moves four functions verbatim (adding only `[[nodiscard]] inline`), plus the `FaceChartPoint` alias.
  - No caller, test, CMake or behaviour change.

## CB-197B — ordered retrace predicate

- **Patch:** `Architecture_M6_CP3_CB197B_P13_Exact_Source_Retrace_Ordered_Stretches_Exact.diff`.
  - SHA-256 `1fe85e273a1c997fc976f4cbc7779f3a7711d19b511cfc6824a5809a2325be8d`.
  - 5,687 B, +57/−27, two files.
- **`include/directional/authority/ExactSourcePath.h`:**
  - git preimage `fbae34c6472b708a46a2def2320ad7167c577f32`;
  - postimage SHA-256 `8a7a9306b55627fe35bad25bca19b040de0e1b87e1f6630b207847625e761b34`.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `92fe1c3858d3865448fb70343e35baa7a7b0219b`;
  - postimage SHA-256 `e0eb98956f09793c8e9676e6188e8d7163566793f7a92a6355772c2a1bdf259c`.
- **Scope:**
  - Replaces the coverage equality inside `exact_source_paths_retrace_along_edges` with an ordered comparison of directed stretches.
  - Appends 1 test (row 1001). The helper stays unwired.

## Verified in this review

- `git apply --check` passes for each patch alone and for both together. `git diff --check` is clean.
- `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) gives the same counts as before:

  | Translation unit | Errors | Warnings |
  |---|---|---|
  | `EmbeddedGraphTopology.cpp` | 0 | 3 |
  | Test TU | 0 | 9 |
  | New header compiled on its own | 0 | — |

- **A2a include probe:** I compiled `SurfaceCellTracing.cpp` with the new header included. It adds no error. The only error is the existing macOS-only libc++ `std::inserter` error in `SourceChartTransitions.h:529`, which the unmodified file also has.

## Gate

- **TB manifest:** `Architecture_M6_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`, 1001 rows.
- **Strict stop:** any preimage mismatch or compile failure means BLOCKED; return to Review.
