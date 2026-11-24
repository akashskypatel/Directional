# CB-200 exact manifest — cross-partition arc census oracle (2026-11-24 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- **Authority:** [TB-REV-179 adversarial continuation](../Architecture_M6_CP3_TB_REV_179_Adversarial_Review_20261124.md), M1–M4.
  - It replaces the prose plan `Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Test_Plan.md`, which is withdrawn (M2).
- **Patch:** `Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Oracle_Exact.diff`.
  - SHA-256 `d4cba179cec0d1971fac3c775b64cf8bb6ffcd913a8c464bb53b9bc0df2ebb26`.
  - 9,209 B, +155/−19, one file.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `ef6a0b1a31ea283fde076333cb0c00ae0f48f166`, SHA-256 `2b32275e…650a` (the CB-199B postimage);
  - postimage SHA-256 `6e83fc338d7632c4540691cb12403d7b495ecd0ddea52f31d792c29c267e0b7b`.
- **Scope:**
  - Replaces `region_frontier_interior_arc_census_is_valid` with `region_frontier_interior_arc_census_failure`. The new helper returns the name of the first failed invariant.
  - Changes the body of row 786 to six corruption checks, each tied to the invariant it must trip, plus one receipt line, `m3Cp4c3PlanInteriorArcCensusCorruptions`.
  - Changes no production, selector, manifest or CMake file, and adds no test.
- **Verified in this review:**
  - `git apply --check` and `git diff --check` are clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`, local `-include iterator` workaround) on the test TU gives 0 errors and the same 9 warnings as before.
- **TB manifest:** reuse the TB179 manifest unchanged.
  - `Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`, 1,003 rows, 81 deferred, membership 1,084.
- **Line moves (J1 rule):**
  - Test lines after 5585 move by +65.
  - Lines after the row-786 assertion block (old 20108) move by +136.
  - All rows are expected to PASS, so no failure-location line should appear. Any changed raw record that contains `FieldAlignedCurveNetworkTests.cpp:` means STOP.
- **Strict stop:** a preimage mismatch, compile failure, or any diff outside this one path means BLOCKED; return to Review.
