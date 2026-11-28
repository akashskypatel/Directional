# CB-208R exact manifest: display stop-location authority with a completion detail receipt (2026-11-26 UTC)

**Review artifact only.** This manifest supersedes the [CB-208 manifest](Architecture_M6_CP3_CB208_P13_Display_Stop_Location_Authority_Exact_Manifest.md) **diff and hashes only**. That diff, `15dd890d…e4e9`, is withdrawn because it does not compile; see [TB-REV-186T adversarial Z1](../M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb_rev_186t_adversarial_review_20261126md). Everything else in the CB-208 manifest still governs: the bounded Code + Build steps, the eight targets, and the runtime plan for TB-EXEC-186 and V5, including the row 858 receipt and the prefix witness. This manifest adds one recorded-only line.

## Exact change

- **Diff:** [the diff file](../Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Exact.diff), 3,806 B, SHA-256 `29ce73c74f4a1ab2dcd6295048002c6f5e882796e076d19021489deb7f44a02c`. One path, `tests/SurfaceCellTracingDisplayTests.cpp`, +39/−4.
- **Preimage:** `b054f3b2fabc07553c0efcef293048ff46a18649609997665593cb6827d10a75`, which equals HEAD.
- **Postimage:** `1957d13f6aa2c86d84a337cef192e090ac6a9695bd45b79fcf8629cffc2c8712`.
- **Differences from CB-208:**
  1. `EXPECT_EQ(0, sphere.result.faces.rows())` becomes `EXPECT_FALSE(sphere.result.is_produced())`, because `RemeshResult` has no `faces`.
  2. A receipt line is added immediately after the unchanged `SphereDisplayStop` line:
     `SphereDisplayStopDetail detail=<terminalFailureDetailCode> firstInvalidStage=<surfaceCellFirstInvalidProducerStage> firstInvalidReason=<surfaceCellFirstInvalidProducerReason>`
- **Checks done in Review:**
  - In a throwaway `CLAUDE_` worktree, since removed: `git apply --check`, exact replay, `git diff --check`, and both hashes.
  - clang++ `-fsyntax-only`: 0 errors and 27 warnings, the same set as HEAD, with none in the test file. This is not compile evidence.

## Runtime predictions (TB-EXEC-186)

- **Row 858 must PASS.**
  - The `SphereDisplayStop` receipt must be exactly the CB-208 prediction.
  - The 69,196-byte, 397-line prefix witness `32d6de52…42d9` still ends at the LF after that receipt and is preserved under N1–N3.
- **`SphereDisplayStopDetail`:** recorded verbatim, not predicted. It is the only permitted new line. Any other new or changed line needs review.
- **Row 972 is predicted PASS:** the success branch, 10 carriers classified, 0 selected (Z3). A RED there is STOP, as for any other row.
- **Falsifiers:**
  - A produced sphere outcome fails `is_produced()`.
  - A location invented for an unlocated completion stop fails the empty-matrix assertions.
  - A dropped reported entity fails its geometry assertion.
  - A missing stage or code note fails the note check.
  - The genus-two, fan and row 1005 controls are unchanged.
