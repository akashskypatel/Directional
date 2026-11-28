# CB-203 exact manifest: display stop-locus contract (2026-11-25 UTC)

**This is a Review artifact.** TB-REV-182 authorizes no application, build or runtime.

- **Owner:** `M6-CP3-CB-203-P13-DISPLAY-STOP-LOCUS-CONTRACT`, Code + Build only, test-only.
- **Authority:** the [TB-REV-182 adversarial review](../Architecture_M6_CP3_TB_REV_182_Adversarial_Review_20261125.md), findings R3 and R4.
- **Semantic preimage:** `5698f79a77e08ad1d2f5e80ab351040060c8bf31`.
- **Exact diff:** [the diff file](../Architecture_M6_CP3_CB203_P13_Display_Stop_Locus_Contract_Exact.diff).
  - SHA-256 `063f87fc61202f3a1dc45d2b46eecfbeb8c2a025b534ee7a08f6a304a5b4f3ad`, 6,492 bytes, one path, +91/−16.
- **Checks done in Review:**
  - `git apply --check` passes at the preimage, and `git diff --check` is clean.
  - Syntax-only check of the test TU, HEAD and patched: 0 errors each, and the same 5 warnings in both (pre-existing, from `PCFaceTangentBundle.h`).
  - That check needed a compile-only `-include iterator` shim, because `SourceChartTransitions.h:529` is missing an include before this patch. The shim is not part of the diff.

## Required behavior

Test-only. No change to the product, fixtures, selectors or other tests.

1. **Row 858 (`SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported`)**: the sphere sub-case no longer assumes that the cut graph stops `sphere_prescribed`. It now asserts the display contract for whatever stage does stop it:
   - the terminal code is not `None`;
   - each reported `sourceFace` or `relatedSourceFace` resolves to a mesh face, and that face is displayed;
   - a reported `sourceEdge` is displayed;
   - a reported `sourceVertex` is displayed;
   - the existing `has_stop_location()` and `cellCount == 0` checks are kept.
   - It also prints one receipt line: `SphereDisplayStop stage= code= sourceFace= relatedSourceFace= sourceEdge= sourceVertex=`.
   - The genus-two and half-index-fan sub-cases are unchanged.
2. **New row 1005 (`SurfaceCellTracingDisplay.TerminalFaceLocusIsShownByItsCorners`)**: does not depend on the pipeline. It always exercises the corner-keyed terminal face path:
   - the input is a two-face mesh, with corners `{3,0,2}` given in rotated order;
   - exactly face 1 is displayed, face 0 is not, and there are no edges and no vertices;
   - the note `code: CutSearchExhaustedBeforeCellularity` is present.
   - If `face_corners` is removed, or corner sorting is removed, this test fails.

## Preimage and postimage (SHA-256)

| Path | Before | After |
|---|---|---|
| `tests/SurfaceCellTracingDisplayTests.cpp` | `f32540153871bd6d6c2f453f5e3784f9f392ab4fdafcb274f496f3a3ee199974` | `b054f3b2fabc07553c0efcef293048ff46a18649609997665593cb6827d10a75` |

## Build, then the separate runtime falsifier

1. **CB-203 (build only).**
   - Verify the preimage and the diff SHA-256, apply only this diff, then verify the postimage and the path set.
   - Compile the eight default GMP/GMPXX targets with `runtimeExecution=false`.
   - Any mismatch or compile failure is a STOP: return to Review.
2. **`M6-CP3-TB-EXEC-183-P13-DISPLAY-STOP-LOCUS-CONTRACT-FULL-GATE`, using the immutable CB-203 package.**
   - **Case manifest:** [Architecture_M6_TB183_P13_Display_Stop_Locus_Contract_Full_Gate_Case_Manifest.tsv](Architecture_M6_TB183_P13_Display_Stop_Locus_Contract_Full_Gate_Case_Manifest.tsv), SHA-256 `94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be`.
     - It is the TB182 manifest byte for byte (`d778afbe…8ca5f`), plus row 1005.
   - **Deferred ledger:** v5 (`fd433f54…64ce`), 81 rows, unchanged.
   - **Expected:** 1005 gated + 81 deferred = 1086 members, and all 1005 PASS.
   - **Comparison** against TB182 result `14979452472` (ZIP `bbbc344b…20b7`) under N1–N3:
     - Only row 858's raw receipt (the added `SphereDisplayStop` line) and the new row 1005 may differ.
     - The `SphereDisplayStop` line must report the existing cut-graph stop, with `sourceFace` present.
     - Anything else is a STOP.
