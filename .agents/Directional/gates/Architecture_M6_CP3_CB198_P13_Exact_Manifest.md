# CB-198 exact manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- **Authority:** [TB-REV-176 adversarial continuation](../Architecture_M6_CP3_TB_REV_176_Adversarial_Review_20261123.md), H1–H4. It replaces the prose CB-198.
- **Patch:** `Architecture_M6_CP3_CB198_P13_Mechanical_Retraced_Trace_Selection_Receipt_Exact.diff`.
  - SHA-256 `c30811fca14154427a41d5e90f3fb565bbbbfe0b5601eec8bcec36e845e6391b`.
  - 6,026 B, +108/−0, one file.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `e21c3362d2a049769ad376b1e79bf59fa6db1999`, the CB-197B postimage;
  - postimage SHA-256 `75ae997a94d766bcc9cda56f37abbb3bb9e655758d141003cfbf51c6cb638cc6`.
- **Scope:**
  - Adds the test-only `append_retraced_trace_selection_receipt` and one call to it in the `RegionElectedCutComponentEmpty` failure branch of `build_cp4c_production_fixture`.
  - No production, selector, manifest, CMake or assertion change, and no new test.
- **Verified in this review:**
  - `git apply --check` and `git diff --check` are clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) on the test TU gives 0 errors and the same 9 warnings as before.
- **TB manifest:** reuse the TB176 manifest unchanged.
  - `Architecture_M6_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`, 1001 rows.
- **Strict stop:** a preimage mismatch or compile failure means BLOCKED; return to Review.
