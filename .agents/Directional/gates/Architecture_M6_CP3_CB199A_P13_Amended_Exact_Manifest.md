# CB-199A amended exact manifest (2026-11-24 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- **Authority:** [TB-REV-177 adversarial continuation](../Architecture_M6_CP3_TB_REV_177_Adversarial_Review_20261124.md), J3–J5. It replaces the original diff `…CB199A…Remap_Exact.diff` (`4f458361…22bf7`), which overloaded `sourcePort` and the junction role.
- **Patch:** `Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Amended_Exact.diff`.
  - SHA-256 `cd43c3f002d890745701eff5f00de4cb8a658585d9ef414614fdbbcc875d4c5a`.
  - 24,726 B, +463/−0, two files.
- **`src/geometry/RetracedTraceReferences.h`:** new file, SHA-256 `bcab2d6292b9f1317471c0659e714b4afd7339e1def7c07d5d409f85b2356944`.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `943187e3a732eca91bd3a824b9c05f9e8ca15bcb`, the CB-198 postimage;
  - postimage SHA-256 `e13d7182355d071e0fe6bd0dc645b8288037af0bf609eb59437711dda7d29b89`;
  - append only.
- **Scope:**
  - Adds the pure `remap_retraced_trace_references` helper. It is unwired: no production caller and no product or digest change.
  - Appends one guard (row 1002).
- **Verified in this review:**
  - `git apply --check` and `git diff --check` are clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) on the test TU gives 0 errors and the same 9 warnings as before.
- **TB manifest:** `Architecture_M6_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed`, 1002 rows.
- **Strict stop:** a preimage mismatch, compile failure, any production caller, or any diff outside the two paths means BLOCKED; return to Review.
