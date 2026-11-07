# RA-179 — TB53 review: platform attribution of the local reds and RP-01 closure (2026-10-30)

**Turn:** `M6-CP3-TB53-RP01-FULL-GATE-REV` (TB-REV, Review track), run locally at the user's direction.

**Independence is reduced.** The same session wrote RA-178, built CB54 and ran TB53. To compensate, two read-only subagent traces and one subagent result audit were used, and every decisive claim below was recomputed from separately configured builds of the same source. Variant builds are diagnostic (GMP_COMPILE_POLICY), not gate authority.

## RA-179.1 Evidence re-verified

- **TB53 result** `build/local-evidence/TB53/result.zip` (`5722887a…`):
  - The audit verifies 1,718/1,718 checksums and 855/855 manifest↔ledger↔log joins in order.
  - All 836 PASS logs contain `[  PASSED  ] 1 test.` and no FAILED line.
  - Membership is 938 = exactly the 855 manifest pairs plus the 83 ledger v3 pairs; the retired 261 is absent.
  - Rows 854 (223) and 855 (225) PASS.
- **Package** `21b7cf2d…`: built from source `2a49b873…`, the exact RA-178.7 patch (CB54 record).

## RA-179.2 Attribution experiments

Both variants use the same source and the CI configure flags. The FMA instructions in the archived `FieldTransportAtlas.cpp.o` were counted with `otool -tv`: CB54 has 159; A and B have 0.

| Build | What changes | Rows run | Result |
|---|---|---|---|
| CB54 (TB53) | default (`-ffp-contract=on`) | 855 | 836 PASS; 18 vertex-35 reds + 283 |
| **A** | only `FieldTransportAtlas.cpp` built with `-ffp-contract=off` | the 19 reds, 854, 855, 86, 396, 397 | **23 PASS**; 283 RED |
| **B** | the whole build with `-ffp-contract=off` | all 855 | **854 PASS**; 283 RED |

- In all three builds, 283 throws the same `segment_arrangement(): surviving twin has invalid next`.
- **Evidence** (`build/local-evidence/TB53-REV/`, gitignored):
  - variant A verdicts `e3fc392d…`;
  - variant B verdicts `513e6d98…`;
  - logs `variant-logs.zip` `50499075…`;
  - runner `run_rows.py` `3a187e4b…`, which uses the frozen harness classifier.

## RA-179.3 Findings

- **F1 — all 18 vertex-35 reds are O15 and nothing else.** FMA contraction in `FieldTransportAtlas.cpp` alone flips the `mechanical_feature` atlas decision (`SingularityPortClassCountMismatch` at vertex 35). Building that one file without contraction clears all 18. This confirms RA-176 F1 on the static, CI-configured build. These are not regressions: each row passed in TB52 on Linux, and no producer changed.
- **F2 — O15's row list was wrong (RA-176 used a literal grep).** RA-176 listed row 471, which uses `cp4c_torus_fixture()`. It missed:
  - 637 and 638, through `cp4c_mechanical_atlas_fixture()`;
  - 652 and 656, through `cp4c_mechanical_fixture()`.

  **Corrected list (21 gated rows):** 86, 396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788. On the default macOS build, all of them fail except 86, 396 and 397.
- **F3 — row 283 is a pre-existing macOS-only legacy failure, not FMA.**
  - It fails identically in all three builds, and it already failed locally on 2026-10-28 (RA-170).
  - Its path is the default `LegacyInteger` backend → `NFunctionMesher::segment_arrangement` (`src/meshing/GenerateMesh.cpp:1102`), on an in-memory two-triangle square.
  - Its topology depends on double decisions: the angular order from `slope_function_double` (`:865–890`, with an exact fallback only below 1e-7), the outer-face test `signed_face_area < -1e-5` (`:1055`), and double inputs from integration.
  - The cause is unresolved. RA-176's "likely O15 sibling" is withdrawn. **Owner: O2** (legacy no-atlas retirement), which must retire this row along with the legacy path or establish the cause.
- **F4 — RA-178.2's FMA-off re-verification of 223 and 225 did not take effect.** It replaced the object file by hand, and ninja 1.13 rebuilt it with default flags (the same method left 159 FMA instructions here). Rows 854 and 855 are now verified under A and B, so RA-178's dispositions stand. **Method:** change one file's flags in the scratch `build.ninja` `FLAGS` line, and confirm the change in the archived object.

## RA-179.4 Disposition

- **TB53 is accepted as the reviewed local (macOS arm64) candidate for source `2a49b873…`:** 836/19, with all 19 classified as platform failures (18 O15, 1 O2/legacy). There is no new stable event: 66/17/49, debt 1. TB52 853/0 remains the latest reviewed Linux candidate. selector497 is not promoted and CP3 is not accepted.
- **RP-01 is CLOSED.** RA-178.5's 855/855 criterion assumed Linux CI, so it is evaluated here under Linux-like arithmetic (variant B): 854/855, and the one red (283) is a legacy row outside RP-01's contract, owned by O2.
  - Rows 223 and 225 pass under FMA on, atlas-only off and global off.
  - Membership is exactly 938; 261 is retired; O9 is ruled (RA-178.3).
  - **Falsifier:** the first Linux CI gate of this source or later fails row 854 or 855 → RP-01 reopens.
  - **Carried:** a Linux confirmation run of TB53 when CI or the implementation agent is available. It does not block.
- **Local-mode convention, until O15 is discharged:**
  - Local CB packages are built with `CMAKE_CXX_FLAGS=-ffp-contract=off` and `CMAKE_C_FLAGS=-ffp-contract=off`, recorded in `command-boundary.txt` as `platform=…-nofma`, so that local gates match Linux arithmetic.
  - TB outcome tables pre-register row 283 as a known legacy platform failure (O2).
  - The default (FMA) build remains O15's red-first witness.

## RA-179.5 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| done | CB54 → TB53 → TB53-REV (RA-179) | CB, TB-EXEC (local); TB-REV / R | RP-01 closed |
| **NEXT** | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` | DEFN / R | O15 inventory and exact patch (RA-176.3). Red-first evidence: the 18 rows fail on the default macOS build and pass after the patch, plus the vertex 10/35/47/71 exact oracle. The witness for row 935 is then defined. |
| then | CB55 (exact predicates) → CB56 (row 935 witness) → TB54 → TB54-REV | CB, TB / I or local; TB-REV / R | O15 discharged; ledger v4 (82) |
| then | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (now also row 283) → P13 probe DEFN (Cylinder first; exact-atlas and route-step checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit (RA-174.3 + RA-176.3 + RA-178.3) |
| carried | TB53 Linux confirmation (CI) | TB-EXEC / I | RP-01 falsifier |
