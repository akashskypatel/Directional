# CB-194 exact shared-edge oracle manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- **Authority:** [TB-REV-172 second adversarial continuation](../Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md), C1–C6. It replaces the withdrawn CB-194 interval receipt.
- **Patch:** `Architecture_M6_CP3_CB194_P13_Exact_Source_Path_Shared_Edge_Oracle_Exact.diff`.
  - SHA-256 `7913097b108c6f8b0d74bedbded1048e5e4b45ae41ab892d069f9398957365e5`.
  - 7,432 bytes, +129/−0, two files.
- **`include/directional/authority/ExactSourcePath.h`:**
  - git preimage `c13c13efc3489d6477e5c7a14a06d75068a6ec68`;
  - postimage SHA-256 `9a6456e5686a01a86a768660ad0359268e07e5d13bca5a4ae2e6f157ae5b9d91`.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `dbee0e4ead77689f60e6ba6d137246819926c098`, the CB-193 postimage;
  - postimage SHA-256 `4c22f65e07a042f69b74e63a69d4034173078173cfabb84a0ff77898bbffe672`.
- **Scope:**
  - Adds the pure `ExactSourceEdgeInterval`, `exact_source_piece_edge_interval` and `exact_source_paths_shared_edges`. They are unwired.
  - Appends 2 tests at the end of the file, so no existing assertion line moves.
  - No product behaviour, selector or assertion change.
- **TB manifest:** `Architecture_M6_TB173_P13_Shared_Edge_Oracle_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `b54de0b28dc646b465daae0d40dd7874f550567fb904647c7dff36a4f2e2ff6e`, 996 rows.
  - The header plus 491-row prefix hash `483f1101…038` is unchanged.
- **Verified in this review:**
  - `git apply --check` and `git diff --check` are clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) on the test TU gives 0 errors and the same 9 warnings as before, none on new lines.
- **Strict stop:** a preimage mismatch or compile failure means BLOCKED; return to Review.
