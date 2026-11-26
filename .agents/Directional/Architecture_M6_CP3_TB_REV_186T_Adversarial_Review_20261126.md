# TB-REV-186T adversarial continuation (2026-11-26 UTC)

Continues `M6-CP3-TB-REV-186T` after the [independent review](Architecture_M6_CP3_TB_REV_186T_Activated_Sphere_Termination_Independent_Review_20261126.md). Runtime-free. Haiku read-only work covered three things: a census of the completion rejection sites, a census of the gated rows that read the sphere, and syntax-only checks of CB-208 and CB-208R, each in a throwaway `CLAUDE_` worktree that has since been removed. Product and test bytes are unchanged.

## Verdict

- **Upheld:** TB186T census facts: six terminations, 5 PASS / row 858 RED, and the exact row 648/979/1006 predictions. No cap was hit, so CB-207D stays unauthorized.
- **Upheld in principle:** the row 858 classification. The display can't show a location that the producer never reported, so the unconditional geometry assertion is too strong for a completion stop.
- **Rejected: CB-208 as frozen (diff `15dd890d…e4e9`).** It does not compile (Z1). Withdrawn.
- **Realigned:** CB-208R is the same correction with a valid output check, plus a detail receipt that records which completion site fired (Z2). Without that receipt, the full gate would spend its run confirming the sphere stops, yet still not say where.

## Findings

**Z1 — CB-208 does not compile (blocking).**
- Applied at HEAD, `-fsyntax-only` gives 1 error: `tests/SurfaceCellTracingDisplayTests.cpp:250:30: error: no member named 'faces' in 'directional::pipeline::RemeshResult'`.
- `RemeshResult` (`include/directional/pipeline/RemeshPipeline.h:648`) exposes its outcome through `is_produced()`, `is_rejected()` and `product()`, not through `faces`.
- TB-REV-186T checked apply, postimage and whitespace only, so the CB would have stopped at compile.
- **CB-208R** replaces the check with `EXPECT_FALSE(sphere.result.is_produced())`. That check is stronger: it rejects any produced outcome, not only one with zero rows.
- Syntax-only: 0 errors and 27 warnings, the same warning set as HEAD, with none in the test file. This is not compile evidence.

**Z2 — The completion stop is not identified, but it can be at no cost.**
- `fail_surface_cells` (`RemeshPipeline.cpp:12362–12392`) records `terminalFailureDetailCode` (`RemeshDiagnostics.h:519`). The test reads that field for the fan fixture, but the sphere receipt never prints it.
- There are five completion `NotProductionReady` sites, and none of them passes a locus:

| Site | Rejects when | Detail code |
|---|---|---|
| `:13975` | domain-ownership validation fails | `None` |
| `:14363` | the complex completion is rejected | typed completion kind |
| `:14817` | `!completionAccepted` | `None` |
| `:14924` | the materialized hard-feature rails are invalid | `None` |
| `:15051` | completed validation fails | the reason string |

- The three `None` sites still set `surfaceCellFirstInvalidProducerStage/Reason` (`RemeshDiagnostics.h:660–661`).
- TB-REV-186T calls the predicate "not established" and leaves it open, so the next product question after activation, why the sphere fails completion, would need a separate diagnostic turn.
- **CB-208R** adds one receipt line right after the frozen `SphereDisplayStop` line: `SphereDisplayStopDetail detail=… firstInvalidStage=… firstInvalidReason=…`.
- The frozen 69,196-byte, 397-line prefix witness `32d6de52…42d9` ends at the LF after `SphereDisplayStop`, so it is unchanged. The new line is recorded verbatim and is not predicted.
- Residual: the no-location exception is keyed on stage and code, which covers all five sites. It cannot be narrowed until the detail code has been measured; TB-REV-186 narrows it if needed.

**Z3 — Other gated sphere readers.** Haiku examined 56 grep hits. Only one other gated row's assertions depend on the cut outcome:
- **Row 972** (`SurfaceCutGraph.PrescribedSphereSlideCarriersAreNeverCutCandidates`, `FieldAlignedCurveNetworkTests.cpp:15369`) now takes its success branch, `certificate().cutCandidates`. Its assertions hold: candidates are non-empty, every carrier is classified as a slide carrier, and none is selected.
- Row 979 measured the same staged certificate at 288 candidates, 10 carriers, 10 classified and 0 selected, so row 972 is predicted to PASS. The exact edge-by-edge match is unmeasured, but row 979 already uses the same carrier oracle.
- Rows 848/849 reach the sphere only if torus and genus_two fail first.
- Every other row is stage-independent, as are the deferred sphere-success rows, which stay deferred.
- No further pre-gate amendment.

**Z4 — Carried.**
- Completion locus: no site reports source geometry. That is a diagnostics-conformity gap for CB-190 (S4/S6/S7), not for this CB.
- Y1–Y5, X1–X5, V5, close_sheets at 0.02, CB-207C/D, J6/E5 and CP3/497/D0/H4 are held unchanged.
- Stable accounting is unchanged at 67/17/50, debt 1, deferred 81. No new stable event.

## Turn sequence

1. `M6-CP3-CB-208R-P13-DISPLAY-STOP-LOCATION-DETAIL-RECEIPT`: exact diff, compile only.
2. `M6-CP3-TB-EXEC-186`: full 1006 gate, then V5, STOP-on-RED, under the CB-208 runtime plan. The row 858 receipt and prefix predictions are unchanged, and the detail line is reported verbatim. Row 972 is predicted PASS.
3. `M6-CP3-TB-REV-186`: adjudicate. Freeze the next step from the measured detail code:
   - a completion diagnostic or repair at the named site;
   - a narrowed row 858 exception, if needed.
4. Then parameter deletion, V3b, R1 and O48. CB-190 stays off the critical path; it now also owns the completion-locus gap.

## Lessons

- An exact test diff needs a syntax check before it is frozen. Apply plus postimage proves the bytes, not that the code compiles.
- When a test is relaxed for a stop it cannot locate, make the same change record which predicate fired, when that costs nothing. Otherwise the gate pays for an unidentified stop.
