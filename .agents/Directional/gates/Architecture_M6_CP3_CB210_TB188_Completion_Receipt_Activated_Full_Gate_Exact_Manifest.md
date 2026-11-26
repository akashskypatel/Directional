# CB-210 exact manifest and TB-EXEC-188 contract (2026-11-26 UTC)

**Review artifact only.** Frozen by the [TB-REV-186 adversarial continuation](../Architecture_M6_CP3_TB_REV_186_Adversarial_Review_20261126.md), AA2. Nothing here has been applied, built or run.

## `M6-CP3-CB-210-P13-SPHERE-COMPLETION-FAILURE-RECEIPT` — Code + Build, compile only

- **Order:** runs after a successful CB-209 compile, on the CB-209 source.
- **Separate paths:** CB-209 touches `tests/FieldAlignedCurveNetworkTests.cpp`; CB-210 touches `tests/SurfaceCellTracingDisplayTests.cpp`.
- **Diff:** [the diff file](../Architecture_M6_CP3_CB210_P13_Sphere_Completion_Failure_Receipt_Exact.diff), 861 B, SHA-256 `696efc1e2a0c3be15047f407f5f9beaedd7c4710a3919251377751b38baac488`. One path, +2/−0.
- **Preimage:** `1957d13f6aa2c86d84a337cef192e090ac6a9695bd45b79fcf8629cffc2c8712` (the CB-208R postimage, which equals HEAD).
- **Postimage:** `0089c18ef38298c207a52574fb98ed995c2d65db6bceadea6ea1b5de219bc7a9`.
- **Change:** prints `SphereCompletionFailure detail=<result.surfaceCellContext.completionFailure>` right after the `SphereDisplayStopDetail` line.
  - The field is assigned unconditionally at `RemeshPipeline.cpp:14157`, inside the surface-cell backend block; row 858 runs that backend.
  - No assertion is added or changed.
- **Checks done in Review:**
  - Throwaway `CLAUDE_` worktree: apply, replay and `git diff --check`.
  - clang++ `-fsyntax-only`: 0 errors and 27 warnings, the same set as HEAD.
  - This is not compile evidence.
- **CB steps:**
  1. Verify the hashes and that only the one path is touched.
  2. Apply the diff.
  3. Compile the eight CB-208R targets with GMP/GMPXX, `runtimeExecution=false`.
  4. STOP on any mismatch.
  - No other change. No runtime.

## `M6-CP3-TB-EXEC-188` — full gate, then V5, on the CB-210 package

- **Inputs:** CB-210 package; harness `423f385b…572c`; manifest `a9b80832…0587` (1006 cases); deferred v5 `fd433f54…64ce`; 1087 members. No rerun, no rebuild, no timeout substitution.
- **Comparisons** under frozen N1–N3, against TB186 result `15155787349`:
  - **Row 971:** must PASS. Its new rays, coverage and receipts are reported in full; the review adjudicates them.
  - **Row 858:** the PASS envelope is unchanged. The 69,196-byte prefix `32d6de52…42d9` and the `SphereDisplayStopDetail detail=PreparationRejected firstInvalidStage= firstInvalidReason=` line must match byte for byte. Exactly one new line, `SphereCompletionFailure detail=…`, is recorded verbatim.
  - **Every other row:** N1–N3-equal to TB186.
- **Comparisons against TB185V `15066180913` and TB187Q `15130286146`:** reproduce the 26 adjudicated activation rows.
- **Receipts and controls to preserve exactly:**
  - Rows 648, 979 and 1006: the exact CB-206 receipts.
  - Rows 393, 669, 843, 844, 963, 968, 972, 978 and 1005.
  - The explicit unstaged negative controls.
- **STOP** on any RED, any unpredicted material difference, or an invalid boundary.
- **V5**, only after a valid gate, as the CB-208 manifest prescribes:
  - census `3af1dc0d…e793`, three cases: Cylinder, BunnyRandom `offgate:360`, Vase;
  - both pending wall contacts, `142:2→87:0` and `26:1→99:0`;
  - `InvalidNetworkBinding` or a carrier-contact struck-index rejection is STOP.
- **Not allowed:** gate credit before `M6-CP3-TB-REV-188`, CB-207D, or CP3/497/D0/H4 promotion.
