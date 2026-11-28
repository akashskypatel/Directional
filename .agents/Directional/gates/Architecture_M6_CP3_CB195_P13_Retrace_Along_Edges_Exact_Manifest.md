# CB-195 exact retrace-along-edges helper manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- **Authority:** [TB-REV-173 D13 resolution](../Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md), E1–E4. It replaces the independent review's prose CB-195.
- **Patch:** `Architecture_M6_CP3_CB195_P13_Exact_Source_Path_Retrace_Along_Edges_Exact.diff`.
  - SHA-256 `72fa4fa63c38e831fe6b1a03dd21f166a180fb255395c84cacd7e3454ba8d315`.
  - 5,498 bytes, +91/−0, two files.
- **`include/directional/authority/ExactSourcePath.h`:**
  - git preimage `8daf7694716b9050581ba040ee4bfe2133ffc481`;
  - postimage SHA-256 `59b0c21dfe297f8e62721944331e41fbbc6fc84e4c580d4827670f57d35ff92b`.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `00133ec707e9f8e161cb85404688b6debe598d50`, the CB-194 postimage;
  - postimage SHA-256 `d668792653674d537b3509a92a0699d3b566d005acfed62bb8ff1f6590786d0e`.
- **Scope:**
  - Adds the pure function `exact_source_paths_retrace_along_edges`, plus the `<map>` and `<utility>` includes. It is unwired.
  - Appends 2 tests at the end of the file.
  - No product behaviour, selector or assertion change.
- **TB manifest:** `Architecture_M6_TB174_P13_Retrace_Oracle_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7`, 998 rows.
  - The 491-row and 994-row prefix hashes are unchanged.
- **Verified in this review:**
  - `git diff --check` and the reverse apply check are clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) on the test TU gives 0 errors and the same 9 warnings before and after.
- **Strict stop:** a preimage mismatch or compile failure means BLOCKED; return to Review.
