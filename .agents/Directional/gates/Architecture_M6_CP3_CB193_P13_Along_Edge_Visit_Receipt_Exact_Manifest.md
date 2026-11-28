# CB-193 exact test-only receipt manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- Authority: [TB-REV-171 adversarial continuation](../Architecture_M6_CP3_TB_REV_171_Adversarial_Review_20261123.md) B1–B5. It replaces the independent review's prose CB-193.
- Patch: `Architecture_M6_CP3_CB193_P13_Along_Edge_Visit_Region_Receipt_Exact.diff`, SHA-256 `5fdea657d79d6ae2b6e3e02c31c8efb59520309c444d069f22a90bd8cae55edc`, 4,897 bytes, +87/−0, one file.
- `tests/FieldAlignedCurveNetworkTests.cpp`:
  - Git preimage `936e8269b6eeb24a795f40c9b740761aac43f0e9` (the CB-192 postimage; live).
  - Postimage SHA-256 `294a54f64b8a228dda05c17c342dc8da434275122da6582fb45ebdc43d2008f3`.
- Scope:
  - Test-local read-only receipt `append_along_edge_visit_receipt`. It is called only when the CP4c fixture throws with `detailCode=RegionElectedCutComponentEmpty`.
  - No product source, assertion, selector or manifest change. The TB uses the TB171 994-row manifest unchanged.
- Verified in this review:
  - `git diff --check` is clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) gives 0 errors and 9 warnings, the same count as the preimage, none on the new lines.
- Strict stop: a preimage mismatch or compile failure → BLOCKED, return to Review.
